// In-game settings overlay. See docs/OVERLAY_PLAN.md for the design.
//
// Pattern copied from ThatGuyMcd/DKR-R runtime_ui.cpp attach/detach/draw: we
// construct our own RT64::Inspector, install it in app.presentQueue->inspector,
// and drive its newFrame/endFrame ourselves. RT64 only drives the Inspector
// itself when userConfig->developerMode is true (rt64_state.cpp:1653), which
// we keep off, so we have exclusive ownership of its ImGui frame.

#include "overlay.h"

#include <algorithm>
#include <atomic>
#include <cmath>
#include <mutex>

#include <unistd.h>   // execvp for the Restart button

#include <SDL.h>
#include "imgui.h"
// PushItemFlag(ImGuiItemFlags_NoNav, ...) lives in the internal header in
// ImGui 1.90 (promoted to public later). Used by the sidebar to lock the
// D-pad / stick to the content panel; see draw_sidebar().
#include "imgui_internal.h"

#include "hle/rt64_application.h"
#include "hle/rt64_application_window.h"
#include "hle/rt64_present_queue.h"
#include "gui/rt64_inspector.h"

#include "launcher.h"

// Defined in main.cpp; argv[0] of the process so we can execvp ourselves on
// Restart. Nullable before main() runs.
extern char* yoshi_argv0;

namespace {

std::atomic<bool> g_visible{false};
std::mutex g_attach_mutex;
bool g_attached = false;
RT64::Application* g_app = nullptr;   // only valid while g_attached is true
ImFont* g_overlay_font = nullptr;     // bigger font added to the atlas on attach

// DKR-R-style capture state for button rebinding in the Controls tab.
// When CaptureTarget != None, handle_event() intercepts the next key/button.
enum class CaptureTarget { None, Keyboard, Controller };
CaptureTarget g_capture_target = CaptureTarget::None;
int g_capture_action_idx = -1;
// Window size the user last resized the overlay to, in pixels. 0 = use default.
// Persists for the life of the process; reset at each attach().
ImVec2 g_overlay_size{0, 0};

// MSAA cannot be changed live: app->updateMultisampling() tears down and
// recreates GPU resources and crashes mid-frame. We keep the chosen value
// here, write it to settings.ini, and show a "takes effect next launch"
// note. g_settings.msaa stays at the booted-with value.
int g_pending_msaa = -1;   // -1 = unset / matches boot MSAA

enum class SideItem {
    Display = 0,
    Audio,
    Controls,
    Saves,
    TexturePacks,
    Mods,
    HudLayout,
    About,
    Count
};
// Current page shown in the content panel.
int g_active = int(SideItem::Display);
// Sidebar cursor for gamepad navigation: 0..Count-1 is a page, Count is
// RESTART, Count+1 is EXIT. Shoulder buttons cycle this; A activates
// RESTART/EXIT. Mouse clicks on page buttons also move the cursor so the
// orange highlight follows. Pattern copied from DKR-R runtime_ui.cpp:9701+.
int g_sidebar_cursor = 0;
constexpr int kSlotRestart = int(SideItem::Count);
constexpr int kSlotExit    = int(SideItem::Count) + 1;
constexpr int kSidebarSlots = kSlotExit + 1;
// Request to re-focus the content panel: set on open and after a shoulder
// cycle. Consumed by the next draw via SetKeyboardFocusHere().
std::atomic<bool> g_focus_content{false};
// Deferred action requested by A on RESTART/EXIT: handled on next draw so
// execvp / exit run outside the SDL event callback.
std::atomic<int> g_sidebar_action{0};   // 0 none, 1 restart, 2 exit

constexpr double kMultipliers[] = { 2, 3, 4, 5, 6, 8, 10 };
constexpr int kMultiplierCount = int(sizeof(kMultipliers) / sizeof(kMultipliers[0]));

int resolution_index(const YoshiSettings& s) {
    if (s.resolution == YoshiSettings::Native) return 0;
    if (s.resolution == YoshiSettings::Window) return 1;
    int best = 0;
    for (int i = 1; i < kMultiplierCount; i++) {
        if (std::fabs(kMultipliers[i] - s.multiplier) < std::fabs(kMultipliers[best] - s.multiplier)) best = i;
    }
    return 2 + best;
}

void set_resolution_index(YoshiSettings& s, int index) {
    if (index == 0) s.resolution = YoshiSettings::Native;
    else if (index == 1) s.resolution = YoshiSettings::Window;
    else {
        s.resolution = YoshiSettings::Manual;
        s.multiplier = kMultipliers[index - 2];
    }
}

// Translate a SDL game controller event to ImGui gamepad input. RT64's SDL2
// ImGui backend ignores controllers so the overlay feeds them in itself.
void feed_controller_to_imgui(const SDL_Event& e) {
    ImGuiIO& io = ImGui::GetIO();
    if (e.type == SDL_CONTROLLERBUTTONDOWN || e.type == SDL_CONTROLLERBUTTONUP) {
        const bool down = e.type == SDL_CONTROLLERBUTTONDOWN;
        ImGuiKey key = ImGuiKey_None;
        switch (e.cbutton.button) {
            case SDL_CONTROLLER_BUTTON_DPAD_UP:        key = ImGuiKey_GamepadDpadUp; break;
            case SDL_CONTROLLER_BUTTON_DPAD_DOWN:      key = ImGuiKey_GamepadDpadDown; break;
            case SDL_CONTROLLER_BUTTON_DPAD_LEFT:      key = ImGuiKey_GamepadDpadLeft; break;
            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:     key = ImGuiKey_GamepadDpadRight; break;
            case SDL_CONTROLLER_BUTTON_A:              key = ImGuiKey_GamepadFaceDown; break;
            case SDL_CONTROLLER_BUTTON_B:              key = ImGuiKey_GamepadFaceRight; break;
            case SDL_CONTROLLER_BUTTON_X:              key = ImGuiKey_GamepadFaceLeft; break;
            case SDL_CONTROLLER_BUTTON_Y:              key = ImGuiKey_GamepadFaceUp; break;
            case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:   key = ImGuiKey_GamepadL1; break;
            case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:  key = ImGuiKey_GamepadR1; break;
            default: break;
        }
        if (key != ImGuiKey_None) io.AddKeyEvent(key, down);
    } else if (e.type == SDL_CONTROLLERAXISMOTION) {
        const float v = e.caxis.value / 32767.0f;
        if (e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX) {
            io.AddKeyEvent(ImGuiKey_GamepadLStickLeft,  v < -0.3f);
            io.AddKeyEvent(ImGuiKey_GamepadLStickRight, v > 0.3f);
        } else if (e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY) {
            io.AddKeyEvent(ImGuiKey_GamepadLStickUp,    v < -0.3f);
            io.AddKeyEvent(ImGuiKey_GamepadLStickDown,  v > 0.3f);
        }
    }
}

void help_tip(const char* text) {
    if (ImGui::IsItemHovered(ImGuiHoveredFlags_ForTooltip | ImGuiHoveredFlags_AllowWhenDisabled)) {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 30.0f);
        ImGui::TextUnformatted(text);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

void heading(const char* text) {
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.00f, 0.60f, 0.15f, 1.0f));
    ImGui::TextUnformatted(text);
    ImGui::PopStyleColor();
    ImGui::Separator();
    ImGui::Spacing();
}

// Field label (uppercase yellow), full-width widget below it, then an optional
// description line in dim white under the widget. Mimics the DKR-R layout.
void field_label(const char* text) {
    ImGui::Spacing();
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.80f, 0.20f, 1.0f));
    ImGui::TextUnformatted(text);
    ImGui::PopStyleColor();
}

void field_desc(const char* text) {
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.75f, 0.80f, 0.90f, 1.0f));
    ImGui::TextWrapped("%s", text);
    ImGui::PopStyleColor();
}

// Human-readable name for an SDL_GameControllerButton value.
// Mirrors DKR-R runtime_controls_ui.inl FriendlyBinding.
static const char* button_name(int btn) {
    switch (btn) {
        case SDL_CONTROLLER_BUTTON_A:             return "A";
        case SDL_CONTROLLER_BUTTON_B:             return "B";
        case SDL_CONTROLLER_BUTTON_X:             return "X";
        case SDL_CONTROLLER_BUTTON_Y:             return "Y";
        case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:  return "LB";
        case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER: return "RB";
        case SDL_CONTROLLER_BUTTON_LEFTSTICK:     return "L-stick";
        case SDL_CONTROLLER_BUTTON_RIGHTSTICK:    return "R-stick";
        case SDL_CONTROLLER_BUTTON_DPAD_UP:       return "D-pad \xe2\x86\x91";
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:     return "D-pad \xe2\x86\x93";
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:     return "D-pad \xe2\x86\x90";
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:    return "D-pad \xe2\x86\x92";
        case SDL_CONTROLLER_BUTTON_START:         return "Start";
        case SDL_CONTROLLER_BUTTON_BACK:          return "Back";
        case SDL_CONTROLLER_BUTTON_GUIDE:         return "Guide";
        default: return "?";
    }
}

void draw_controls_tab() {
    heading("CONTROLS");
    ImGui::PushItemWidth(-1.0f);

    // --- Device ---
    field_label("CONTROLLER");
    const char* cname = input_current_controller_name();
    if (cname) {
        ImGui::TextUnformatted(cname);
    } else {
        ImGui::TextDisabled("No controller connected");
    }
    ImGui::Spacing();

    // --- Stick ---
    field_label("DEADZONE");
    ImGui::SliderFloat("##dz", &g_settings.bindings.deadzone, 0.0f, 0.5f, "%.2f");
    field_desc("Minimum stick deflection registered as movement. Default: 0.15.");

    field_label("STICK AXIS");
    ImGui::Checkbox("Invert horizontal (X)", &g_settings.bindings.invert_x);
    ImGui::SameLine();
    ImGui::Checkbox("Invert vertical (Y)", &g_settings.bindings.invert_y);
    ImGui::Spacing();

    // --- Button mapping table ---
    heading("BUTTON MAPPING");
    field_desc("Click a key or button cell to rebind it. Esc cancels. "
               "Axis inputs (right stick, triggers) always active alongside any button binding.");
    ImGui::Spacing();

    static const char* const kActionLabels[] = {
        "A", "B", "Z", "Start",
        "L (shoulder)", "R (shoulder)",
        "C Up", "C Down", "C Left", "C Right",
        "D-pad Up", "D-pad Down", "D-pad Left", "D-pad Right",
        "Stick Up", "Stick Down", "Stick Left", "Stick Right",
    };
    // Non-null = axis-driven; show label instead of rebind button.
    static const char* const kAxisLabels[] = {
        nullptr,                  // A
        nullptr,                  // B
        "L-trigger (axis)",       // Z
        nullptr,                  // Start
        nullptr,                  // L
        nullptr,                  // R
        "R-stick \xe2\x86\x91",  // CUp
        "R-stick \xe2\x86\x93",  // CDown
        "R-stick \xe2\x86\x90",  // CLeft
        "R-stick \xe2\x86\x92",  // CRight
        nullptr,                  // DUp
        nullptr,                  // DDown
        nullptr,                  // DLeft
        nullptr,                  // DRight
        "L-stick \xe2\x86\x91",  // StickUp
        "L-stick \xe2\x86\x93",  // StickDown
        "L-stick \xe2\x86\x90",  // StickLeft
        "L-stick \xe2\x86\x92",  // StickRight
    };
    static_assert(sizeof(kActionLabels) / sizeof(kActionLabels[0]) ==
                  static_cast<int>(N64Action::Count), "label count mismatch");
    static_assert(sizeof(kAxisLabels) / sizeof(kAxisLabels[0]) ==
                  static_cast<int>(N64Action::Count), "axis label count mismatch");

    if (ImGui::BeginTable("##bindings", 3,
            ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg |
            ImGuiTableFlags_SizingStretchSame)) {
        ImGui::TableSetupColumn("N64 BUTTON", ImGuiTableColumnFlags_WidthStretch, 1.0f);
        ImGui::TableSetupColumn("KEYBOARD",   ImGuiTableColumnFlags_WidthStretch, 1.5f);
        ImGui::TableSetupColumn("CONTROLLER", ImGuiTableColumnFlags_WidthStretch, 1.5f);
        ImGui::TableHeadersRow();

        for (int i = 0; i < int(N64Action::Count); i++) {
            ImGui::TableNextRow();
            const float btnW = ImGui::GetContentRegionAvail().x;

            // Col 0: action name
            ImGui::TableSetColumnIndex(0);
            ImGui::TextUnformatted(kActionLabels[i]);

            // Col 1: keyboard binding
            ImGui::TableSetColumnIndex(1);
            {
                const int sc = g_settings.bindings.actions[i].key;
                char label[80];
                const bool capturing = g_capture_target == CaptureTarget::Keyboard &&
                                       g_capture_action_idx == i;
                if (capturing) {
                    snprintf(label, sizeof(label), "Press a key...##kb%d", i);
                    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.75f, 0.18f, 0.12f, 1.0f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.90f, 0.25f, 0.18f, 1.0f));
                } else if (sc < 0) {
                    snprintf(label, sizeof(label), "Unbound##kb%d", i);
                } else {
                    snprintf(label, sizeof(label), "%s##kb%d",
                             SDL_GetScancodeName(static_cast<SDL_Scancode>(sc)), i);
                }
                if (ImGui::Button(label, ImVec2(btnW, 0))) {
                    g_capture_action_idx = i;
                    g_capture_target = CaptureTarget::Keyboard;
                }
                if (capturing) ImGui::PopStyleColor(2);
            }

            // Col 2: controller binding
            ImGui::TableSetColumnIndex(2);
            {
                const char* axis = kAxisLabels[i];
                if (axis) {
                    // Axis-controlled: informational only.
                    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.65f, 0.70f, 0.78f, 1.0f));
                    ImGui::TextUnformatted(axis);
                    ImGui::PopStyleColor();
                } else {
                    const int ct = g_settings.bindings.actions[i].btn;
                    char label[80];
                    const bool capturing = g_capture_target == CaptureTarget::Controller &&
                                           g_capture_action_idx == i;
                    if (capturing) {
                        snprintf(label, sizeof(label), "Press button...##ct%d", i);
                        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.75f, 0.18f, 0.12f, 1.0f));
                        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.90f, 0.25f, 0.18f, 1.0f));
                    } else if (ct < 0) {
                        snprintf(label, sizeof(label), "Unbound##ct%d", i);
                    } else {
                        snprintf(label, sizeof(label), "%s##ct%d", button_name(ct), i);
                    }
                    if (ImGui::Button(label, ImVec2(btnW, 0))) {
                        g_capture_action_idx = i;
                        g_capture_target = CaptureTarget::Controller;
                    }
                    if (capturing) ImGui::PopStyleColor(2);
                }
            }
        }
        ImGui::EndTable();
    }

    ImGui::Spacing();
    if (ImGui::Button("Reset to defaults")) {
        input_bindings_reset_defaults(g_settings.bindings);
        g_capture_target = CaptureTarget::None;
    }
    help_tip("Restore all keyboard and controller bindings to their factory defaults.");

    ImGui::PopItemWidth();
}

void draw_audio_tab() {
    heading("AUDIO");
    ImGui::PushItemWidth(-1.0f);

    // Work in 0..100 so SliderFloat can use "%.0f%%" as a live printf format.
    // ImGui substitutes the current float value into the format string each
    // frame — passing a pre-formatted string like "75%" freezes the display.
    float volPct = audio_get_volume() * 100.0f;
    bool muted   = audio_get_muted();

    field_label("MASTER VOLUME");
    const float muteW  = ImGui::GetFontSize() * 4.5f;
    const float spacing = ImGui::GetStyle().ItemSpacing.x;
    ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x - muteW - spacing);
    if (ImGui::SliderFloat("##vol", &volPct, 0.0f, 100.0f,
                           muted ? "Muted" : "%.0f%%")) {
        audio_set_volume(volPct / 100.0f);
        if (muted) { audio_set_muted(false); muted = false; }
    }
    ImGui::SameLine();
    if (ImGui::Button(muted ? "Unmute" : "Mute", ImVec2(muteW, 0))) {
        audio_set_muted(!muted);
    }

    ImGui::Spacing();
    field_label("ABOUT AUDIO");
    field_desc("Yoshi's Story mixes music, effects and voice together inside "
               "the N64 audio microcode (aspMain) before the samples reach us. "
               "There is no separate per-channel split to expose, so Master "
               "Volume is the only control available.");

    ImGui::PopItemWidth();
}

void draw_display_tab() {
    heading("DISPLAY");
    YoshiSettings& s = g_settings;
    YoshiSettings before = s;

    ImGui::PushItemWidth(-1.0f);   // full-width widgets like the DKR-R ref

    static const char* const resNames[] = {
        "Native (320x240)", "Fit window", "2x (640x480)", "3x (960x720)",
        "4x (1280x960)", "5x (1600x1200)", "6x (1920x1440)", "8x (2560x1920)",
        "10x (3200x2400)" };
    int resIndex = resolution_index(s);
    field_label("INTERNAL RESOLUTION");
    if (ImGui::Combo("##resolution", &resIndex, resNames, IM_ARRAYSIZE(resNames))) {
        set_resolution_index(s, resIndex);
        // Native has no internal buffer to supersample; reset SSAA to Off.
        if (s.resolution == YoshiSettings::Native) s.ssaa = 1;
    }
    field_desc("Native is the console's own 320x240. Fit window picks the largest "
               "whole multiple of 240 lines. 2x-8x is a fixed size and enables supersampling.");

    const bool manual = s.resolution == YoshiSettings::Manual;
    static const char* const ssaaNames[] = { "Off", "2x", "3x", "4x", "5x" };
    int ssaaIndex = std::clamp(s.ssaa, 1, 5) - 1;
    field_label("SUPERSAMPLING");
    ImGui::BeginDisabled(!manual);
    if (ImGui::Combo("##ssaa", &ssaaIndex, ssaaNames, IM_ARRAYSIZE(ssaaNames))) s.ssaa = ssaaIndex + 1;
    ImGui::EndDisabled();
    field_desc("Draws the game N times larger again, then shrinks it back down. "
               "Smooths edges but costs 4x / 9x / 16x the pixels. Fixed resolution only.");

    static const char* const msaaNames[] = { "Off", "MSAA 2x", "MSAA 4x", "MSAA 8x" };
    int msaaPending = (g_pending_msaa < 0 ? s.msaa : g_pending_msaa);
    int msaaIndex = msaaPending >= 8 ? 3 : msaaPending >= 4 ? 2 : msaaPending >= 2 ? 1 : 0;
    field_label("ANTI-ALIASING");
    if (ImGui::Combo("##msaa", &msaaIndex, msaaNames, IM_ARRAYSIZE(msaaNames))) {
        g_pending_msaa = msaaIndex == 0 ? 0 : (1 << msaaIndex);
    }
    field_desc("Smooths 3D polygon edges. Yoshi is mostly 2D so expect little visible change. "
               "RT64 cannot swap sample counts live, so this takes effect at next launch.");
    if (g_pending_msaa >= 0 && g_pending_msaa != s.msaa) {
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.65f, 0.20f, 1.0f));
        ImGui::TextUnformatted("Restart required to apply the new MSAA setting.");
        ImGui::PopStyleColor();
    }

    static const char* const up2dNames[] = { "Original", "Scaled only", "All" };
    field_label("UPSCALE 2D");
    ImGui::Combo("##up2d", &s.upscale2D, up2dNames, IM_ARRAYSIZE(up2dNames));
    field_desc("Which 2D sprites and backgrounds are drawn at the high resolution. "
               "Original is blocky but never seams; Scaled only is the default.");

    static const char* const filterNames[] = { "Nearest", "Linear", "Pixel scaling" };
    field_label("OUTPUT FILTER");
    ImGui::Combo("##filter", &s.filter, filterNames, IM_ARRAYSIZE(filterNames));
    field_desc("How the final picture is stretched to fit the window. Pixel scaling is recommended.");

    field_label("CRT FILTER");
    ImGui::SliderFloat("##crt", &s.crt, 0.0f, 1.0f, s.crt <= 0.0f ? "Off" : "%.2f");
    field_desc("Dark gaps between scanlines plus an aperture grille. Needs a tall window; "
               "fades out below ~3 window pixels per native line. F10 cycles off / 0.25 / 0.5 / 1.0.");

    field_label("OVERSCAN CROP (PIXELS)");
    ImGui::SliderInt("##crop", &s.crop, 0, 8);
    field_desc("Hides this many framebuffer pixels along each edge, like a TV. 2 is recommended.");

    field_label("WINDOW MODE");
    ImGui::Checkbox("Borderless fullscreen", &s.fullscreen);
    field_desc("F11 or Alt+Enter also toggles fullscreen while playing.");

    ImGui::PopItemWidth();

    // Live-apply only non-MSAA changes.
    const bool displayTouched =
        before.resolution != s.resolution || before.multiplier != s.multiplier ||
        before.ssaa != s.ssaa ||
        before.upscale2D != s.upscale2D || before.filter != s.filter;
    if (displayTouched && g_app != nullptr) {
        apply_display_settings(g_app);
    }
    if (before.crt != s.crt && g_app != nullptr) {
        g_app->enhancementConfig.presentation.crtStrength = s.crt;
        g_app->updateEnhancementConfig();
    }
    if (before.fullscreen != s.fullscreen && g_sdl_window != nullptr) {
        SDL_SetWindowFullscreen(g_sdl_window, s.fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    }
}

void draw_placeholder_tab(const char* label, const char* detail) {
    heading(label);
    ImGui::TextDisabled("Coming soon");
    ImGui::Spacing();
    ImGui::TextWrapped("%s", detail);
    ImGui::Spacing();
    ImGui::TextDisabled("Tracked in docs/OVERLAY_PLAN.md.");
}

void draw_about_tab() {
    heading("About");
    ImGui::TextUnformatted("Yoshi's Story Recomp");
    ImGui::TextDisabled("Native static recompilation using N64Recomp + RT64");
    ImGui::Spacing();
    ImGui::BulletText("Repo: github.com/damobeanrod/yoshis-story-recomp");
    ImGui::BulletText("RT64 submodule: github.com/rt64/rt64");
    ImGui::BulletText("N64ModernRuntime: github.com/N64Recomp/N64ModernRuntime");
    ImGui::Spacing();

    heading("RT64 patches applied in this build");
    ImGui::BulletText("0001 - S2DEX GBI1 object sprite commands");
    ImGui::BulletText("0003 - CRT filter in VI shader");
    ImGui::BulletText("0004 - S2DEX upscale strip heuristic (local)");
    ImGui::Spacing();

    heading("In-game shortcuts");
    ImGui::BulletText("Esc / F1 / Controller Back - toggle this overlay");
    ImGui::BulletText("F10 - cycle CRT filter (off / 0.25 / 0.5 / 1.0)");
    ImGui::BulletText("F11 or Alt+Enter - toggle fullscreen");
    ImGui::BulletText("F9 - dump the next display list to stderr");
    ImGui::Spacing();

    heading("Credits");
    ImGui::TextWrapped(
        "This recomp would not exist without the people and projects whose "
        "work it stands on. Thank you.");
    ImGui::Spacing();
    ImGui::TextDisabled("Recomp toolchain and runtime");
    ImGui::BulletText("Mr-Wiseguy - N64Recomp and the original recomp approach");
    ImGui::BulletText("N64Recomp contributors - N64ModernRuntime, librecomp, ultramodern");
    ImGui::BulletText("Zelda64Recomp / Zelda64Recompiled team - input engine, mod system lineage");
    ImGui::Spacing();
    ImGui::TextDisabled("Renderer");
    ImGui::BulletText("rt64 team - RT64 (HLE renderer, Vulkan/D3D12 backends, texture replacement)");
    ImGui::BulletText("olivieryuyu - S2DEX microcode decoding referenced by patch 0001");
    ImGui::BulletText("GLideN64 project - prior art reference for S2DEX (independent impl here)");
    ImGui::Spacing();
    ImGui::TextDisabled("UI inspiration");
    ImGui::BulletText("ThatGuyMcd - DKR-R overlay design informed this one");
    ImGui::BulletText("Omar Cornut and Dear ImGui contributors - the whole UI");
    ImGui::Spacing();
    ImGui::TextDisabled("Libraries");
    ImGui::BulletText("SDL2 - window, audio, input");
    ImGui::BulletText("plume, hlslpp, im3d, implot - vendored in RT64");
    ImGui::Spacing();
    ImGui::TextDisabled("Decompilation");
    ImGui::BulletText("decompals/yoshis-story contributors - decomp this recomp was built against");
    ImGui::Spacing();
    ImGui::TextDisabled("The game itself remains the property of Nintendo. "
                        "This recomp ships no game data; a user-supplied ROM is required.");
}

void restart_game() {
    // Relaunch via execvp. SDL and our threads are torn down by exec.
    // Fallback: _exit(0) so the user can relaunch manually.
    char* argv[2] = { yoshi_argv0, nullptr };
    const char* path = yoshi_argv0 ? yoshi_argv0 : "yoshis_story_recomp";
    execvp(path, argv);
    fprintf(stderr, "[overlay] execvp failed, exiting instead\n");
    _exit(0);
}

void draw_sidebar(const ImVec2& area) {
    // Patterned on DKR-R runtime_ui.cpp:9472+: the sidebar child is NavFlattened
    // and its buttons carry ImGuiItemFlags_NoNav, so the D-pad / stick cannot
    // move focus into it. Shoulder buttons own this rail (see handle_event).
    ImGui::BeginChild("##sidebar", area, true,
        ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NavFlattened);
    ImGui::PushItemFlag(ImGuiItemFlags_NoNav, true);

    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.80f, 0.20f, 1.0f));
    ImGui::TextUnformatted("YOSHI'S STORY");
    ImGui::TextUnformatted("RECOMPILED");
    ImGui::PopStyleColor();
    ImGui::Separator();
    ImGui::Spacing();

    static const char* const items[] = {
        "DISPLAY", "AUDIO", "CONTROLS", "SAVE MANAGER",
        "TEXTURE PACKS", "MODS / HACKS", "HUD LAYOUT", "ABOUT",
    };
    const ImVec4 activeBg      = ImVec4(0.95f, 0.35f, 0.10f, 1.00f);
    const ImVec4 activeBgHov   = ImVec4(1.00f, 0.42f, 0.15f, 1.00f);
    const ImVec4 inactiveBg    = ImVec4(0.15f, 0.22f, 0.38f, 1.00f);
    const ImVec4 inactiveBgHov = ImVec4(0.22f, 0.32f, 0.52f, 1.00f);
    const ImVec4 restartBg     = ImVec4(0.95f, 0.52f, 0.10f, 1.00f);
    const ImVec4 restartBgHov  = ImVec4(1.00f, 0.60f, 0.15f, 1.00f);
    const ImVec4 restartBgHot  = ImVec4(1.00f, 0.72f, 0.20f, 1.00f);
    const ImVec4 exitBg        = ImVec4(0.90f, 0.20f, 0.12f, 1.00f);
    const ImVec4 exitBgHov     = ImVec4(1.00f, 0.28f, 0.18f, 1.00f);
    const ImVec4 exitBgHot     = ImVec4(1.00f, 0.42f, 0.28f, 1.00f);

    const float buttonW = ImGui::GetContentRegionAvail().x;
    const float buttonH = ImGui::GetFontSize() * 2.1f;

    for (int i = 0; i < int(SideItem::Count); i++) {
        const bool active = (i == g_active);
        // The cursor and active page are the same for page slots; mouse click
        // sets both so the highlight follows a click as well as a shoulder cycle.
        ImGui::PushStyleColor(ImGuiCol_Button, active ? activeBg : inactiveBg);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, active ? activeBgHov : inactiveBgHov);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, activeBg);
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 1, 1, 1));
        if (ImGui::Button(items[i], ImVec2(buttonW, buttonH))) {
            g_active = i;
            g_sidebar_cursor = i;
            g_focus_content.store(true, std::memory_order_release);
        }
        ImGui::PopStyleColor(4);
        ImGui::Spacing();
    }

    // Spacer, then Restart + Exit at the bottom, DKR-R style.
    const float remaining = ImGui::GetContentRegionAvail().y;
    const float footerH = (buttonH + ImGui::GetStyle().ItemSpacing.y) * 2;
    if (remaining > footerH) ImGui::Dummy(ImVec2(1, remaining - footerH));

    const bool restartHot = (g_sidebar_cursor == kSlotRestart);
    ImGui::PushStyleColor(ImGuiCol_Button,        restartHot ? restartBgHot : restartBg);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, restartBgHov);
    ImGui::PushStyleColor(ImGuiCol_ButtonActive,  restartBg);
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 1, 1, 1));
    if (ImGui::Button("RESTART", ImVec2(buttonW, buttonH))) {
        g_sidebar_action.store(1, std::memory_order_release);
    }
    ImGui::PopStyleColor(4);
    ImGui::Spacing();

    const bool exitHot = (g_sidebar_cursor == kSlotExit);
    ImGui::PushStyleColor(ImGuiCol_Button,        exitHot ? exitBgHot : exitBg);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, exitBgHov);
    ImGui::PushStyleColor(ImGuiCol_ButtonActive,  exitBg);
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 1, 1, 1));
    if (ImGui::Button("EXIT", ImVec2(buttonW, buttonH))) {
        g_sidebar_action.store(2, std::memory_order_release);
    }
    ImGui::PopStyleColor(4);

    ImGui::PopItemFlag();
    ImGui::EndChild();
}

void draw_content(const ImVec2& area) {
    ImGui::BeginChild("##content", area, true, ImGuiWindowFlags_NavFlattened);

    // Top-right hint and close affordance.
    const char* hint = "LB / RB tabs \xC2\xB7 B closes \xC2\xB7 Esc / F1 / Back";
    const float hintW = ImGui::CalcTextSize(hint).x;
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.65f, 0.70f, 0.78f, 1.0f));
    ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x + ImGui::GetCursorPosX() - hintW);
    ImGui::TextUnformatted(hint);
    ImGui::PopStyleColor();
    ImGui::Spacing();

    // When the overlay opens or the user cycles the sidebar, drop focus into
    // the content panel so the D-pad drives the widgets, not the sidebar.
    if (g_focus_content.exchange(false, std::memory_order_acq_rel)) {
        ImGui::SetKeyboardFocusHere();
    }

    switch (SideItem(g_active)) {
        case SideItem::Display: draw_display_tab(); break;
        case SideItem::Audio: draw_audio_tab(); break;
        case SideItem::Controls: draw_controls_tab(); break;
        case SideItem::Saves:
            draw_placeholder_tab("Save Manager",
                "Backup, restore and rename yoshis_story.bin. Portable-mode "
                "toggle. The save file already lives in data/saves/ and this "
                "tab will manage it.");
            break;
        case SideItem::TexturePacks:
            draw_placeholder_tab("Texture Packs",
                "Install and prioritise texture replacement packs. RT64 ships "
                "the replacement engine; this tab will expose a folder picker "
                "and priority list.");
            break;
        case SideItem::Mods:
            draw_placeholder_tab("Mods / Hacks",
                "Enable / disable mods declared in data/mods.json. The file "
                "exists but nothing is authored yet; this tab lands when the "
                "first mod ships.");
            break;
        case SideItem::HudLayout:
            draw_placeholder_tab("HUD Layout",
                "Reposition the HUD elements per aspect ratio. Low-priority "
                "but kept visible so the roadmap is clear.");
            break;
        case SideItem::About: draw_about_tab(); break;
        default: break;
    }
    ImGui::EndChild();
}

void draw_overlay_window() {
    ImGuiIO& io = ImGui::GetIO();

    // Use the bigger font we added to the atlas on attach(). PushFont scales
    // the glyphs directly instead of up-sampling the default 13 px bitmap.
    if (g_overlay_font != nullptr) ImGui::PushFont(g_overlay_font);

    const ImVec2 displaySize = io.DisplaySize;
    // First open uses ~65% of the display; after that, the user's resize sticks
    // for the life of the process. Children scroll if the window gets smaller
    // than their content needs.
    float w = g_overlay_size.x > 0 ? g_overlay_size.x : displaySize.x * 0.65f;
    float h = g_overlay_size.y > 0 ? g_overlay_size.y : displaySize.y * 0.65f;
    w = std::min(w, displaySize.x * 0.98f);
    h = std::min(h, displaySize.y * 0.98f);
    ImGui::SetNextWindowPos(ImVec2(displaySize.x * 0.5f, displaySize.y * 0.5f),
                            ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(w, h), ImGuiCond_Appearing);
    ImGui::SetNextWindowSizeConstraints(ImVec2(displaySize.x * 0.3f, displaySize.y * 0.3f),
                                        ImVec2(displaySize.x,       displaySize.y));

    // Deeper window background, visible yellow border like DKR-R uses.
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.08f, 0.09f, 0.14f, 0.98f));
    ImGui::PushStyleColor(ImGuiCol_Border,   ImVec4(0.95f, 0.72f, 0.10f, 0.75f));
    ImGui::PushStyleColor(ImGuiCol_FrameBg,  ImVec4(0.12f, 0.16f, 0.24f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.18f, 0.22f, 0.32f, 1.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 2.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 14.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 12.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 8.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(14.0f, 10.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10.0f, 10.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(16.0f, 16.0f));

    const bool open = ImGui::Begin("##yoshi_overlay", nullptr,
        ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar);
    if (open) {
        // Remember the current size so re-opening uses the same dimensions.
        g_overlay_size = ImGui::GetWindowSize();
        const float sidebarW = std::max(ImGui::GetFontSize() * 13.0f, w * 0.26f);
        const ImVec2 avail = ImGui::GetContentRegionAvail();
        const ImVec2 sideArea(sidebarW, avail.y);
        const ImVec2 contentArea(avail.x - sidebarW - ImGui::GetStyle().ItemSpacing.x, avail.y);
        draw_sidebar(sideArea);
        ImGui::SameLine();
        draw_content(contentArea);
    }
    ImGui::End();

    ImGui::PopStyleVar(7);
    ImGui::PopStyleColor(4);
    if (g_overlay_font != nullptr) ImGui::PopFont();
}

} // namespace

namespace overlay {

void attach(RT64::Application& app) {
    std::scoped_lock guard(g_attach_mutex);
    if (g_attached) return;
    if (app.presentQueue == nullptr || app.device == nullptr ||
        app.swapChain == nullptr || app.appWindow == nullptr) {
        return;
    }
    std::scoped_lock lock(app.presentQueue->inspectorMutex);
    app.presentQueue->inspector = std::make_unique<RT64::Inspector>(
        app.device.get(), app.swapChain.get(), app.chosenGraphicsAPI,
        app.appWindow->sdlWindow);
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard
                    | ImGuiConfigFlags_NavEnableGamepad;
    // RT64's SDL2 ImGui backend strips controller handling, so we feed the
    // gamepad into ImGui ourselves (see feed_controller_to_imgui). Marking
    // HasGamepad is required for Nav to pick up those input events.
    io.BackendFlags |= ImGuiBackendFlags_HasGamepad;

    // Add a bigger font to the atlas while it is still mutable. The Vulkan
    // ImGui backend builds the atlas lazily on the first newFrame() call, so
    // adding here (before our first draw) is in time. FontGlobalScale cannot
    // enlarge the baked default 13 px bitmap convincingly, so we rasterise a
    // dedicated larger font and PushFont around our drawing.
    ImFontConfig cfg;
    cfg.SizePixels = 26.0f;
    cfg.OversampleH = 2;
    cfg.OversampleV = 2;
    g_overlay_font = io.Fonts->AddFontDefault(&cfg);

    g_app = &app;
    g_attached = true;
    g_pending_msaa = -1;
    g_overlay_size = ImVec2(0, 0);   // use default on first open
}

void detach(RT64::Application& app) {
    std::scoped_lock guard(g_attach_mutex);
    if (g_visible.load(std::memory_order_acquire)) {
        // Persist any pending edits on the way out.
        if (g_pending_msaa >= 0) g_settings.msaa = g_pending_msaa;
        settings_save(g_settings_path);
    }
    g_visible.store(false, std::memory_order_release);
    if (app.presentQueue != nullptr) {
        std::scoped_lock lock(app.presentQueue->inspectorMutex);
        app.presentQueue->inspector.reset();
    }
    g_app = nullptr;
    g_attached = false;
}

void draw(RT64::Application& app) {
    if (!g_attached) return;
    if (app.presentQueue == nullptr || app.framebufferGraphicsWorker == nullptr) return;
    std::scoped_lock lock(app.presentQueue->inspectorMutex);
    RT64::Inspector* inspector = app.presentQueue->inspector.get();
    if (inspector == nullptr) return;

    inspector->newFrame(app.framebufferGraphicsWorker.get());
    const bool wasVisible = g_visible.load(std::memory_order_acquire);
    if (wasVisible) {
        draw_overlay_window();
        if (!g_visible.load(std::memory_order_acquire)) {
            // Just closed: write pending MSAA into settings (applies next launch),
            // persist to data/settings.ini.
            if (g_pending_msaa >= 0) g_settings.msaa = g_pending_msaa;
            settings_save(g_settings_path);
        }
    }
    inspector->endFrame();

    // A on RESTART / EXIT fires via the sidebar action latch (set by either a
    // mouse click or a controller A-press from handle_event). Run it after
    // endFrame so neither execvp nor _exit runs with the inspector lock held.
    const int action = g_sidebar_action.exchange(0, std::memory_order_acq_rel);
    if (action == 1) {
        if (g_pending_msaa >= 0) g_settings.msaa = g_pending_msaa;
        settings_save(g_settings_path);
        restart_game();
    } else if (action == 2) {
        if (g_pending_msaa >= 0) g_settings.msaa = g_pending_msaa;
        settings_save(g_settings_path);
        _exit(0);
    }
}

// Move the sidebar cursor by `delta`, wrapping around all slots. Updates the
// active page when the cursor lands on a page slot, and requests content
// focus so the D-pad drives widgets rather than drifting back into the
// sidebar. Mirrors DKR-R runtime_ui.cpp:9701-9728.
void cycle_sidebar(int delta) {
    int next = g_sidebar_cursor + delta;
    while (next < 0) next += kSidebarSlots;
    next %= kSidebarSlots;
    g_sidebar_cursor = next;
    if (next < int(SideItem::Count)) {
        g_active = next;
    }
    g_focus_content.store(true, std::memory_order_release);
}

bool handle_event(SDL_Event* event) {
    if (!g_attached || event == nullptr) return false;

    // Capture mode (DKR-R pattern): intercept the next key/button press to
    // apply as a new binding. Takes priority over all other event handling so
    // that Esc cancels capture rather than closing the overlay.
    if (g_capture_target != CaptureTarget::None) {
        if (event->type == SDL_KEYDOWN && !event->key.repeat) {
            const SDL_Scancode sc = event->key.keysym.scancode;
            if (sc == SDL_SCANCODE_ESCAPE) {
                // Esc cancels without assigning
                g_capture_target = CaptureTarget::None;
                return true;
            }
            if (g_capture_target == CaptureTarget::Keyboard && g_capture_action_idx >= 0) {
                g_settings.bindings.actions[g_capture_action_idx].key = sc;
                g_capture_target = CaptureTarget::None;
            }
            return true;
        }
        if (event->type == SDL_CONTROLLERBUTTONDOWN) {
            const int btn = event->cbutton.button;
            // Don't let the user accidentally bind an overlay control button.
            const bool reserved = btn == SDL_CONTROLLER_BUTTON_BACK ||
                                  btn == SDL_CONTROLLER_BUTTON_LEFTSHOULDER ||
                                  btn == SDL_CONTROLLER_BUTTON_RIGHTSHOULDER;
            if (!reserved && g_capture_target == CaptureTarget::Controller &&
                g_capture_action_idx >= 0) {
                g_settings.bindings.actions[g_capture_action_idx].btn = btn;
            }
            g_capture_target = CaptureTarget::None;
            return true;
        }
        // Swallow all other events while waiting for a binding press.
        return true;
    }

    // ESC / F1 / Controller Back toggle visibility and consume the event.
    if (event->type == SDL_KEYDOWN && !event->key.repeat) {
        const SDL_Scancode code = event->key.keysym.scancode;
        if (code == SDL_SCANCODE_ESCAPE || code == SDL_SCANCODE_F1) {
            toggle();
            return true;
        }
    }
    if (event->type == SDL_CONTROLLERBUTTONDOWN &&
        event->cbutton.button == SDL_CONTROLLER_BUTTON_BACK) {
        toggle();
        return true;
    }

    if (!g_visible.load(std::memory_order_acquire)) return false;

    // While visible: shoulder buttons own the sidebar, B closes, A activates
    // RESTART/EXIT when the cursor is on them. Pattern: DKR-R runtime_ui.cpp:9697+.
    if (event->type == SDL_CONTROLLERBUTTONDOWN) {
        switch (event->cbutton.button) {
            case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
                cycle_sidebar(-1);
                return true;
            case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
                cycle_sidebar(+1);
                return true;
            case SDL_CONTROLLER_BUTTON_B:
                // Yoshi-specific: B closes the overlay. DKR-R uses Back for
                // toggle; we keep Back for toggle and let B double as close.
                g_visible.store(false, std::memory_order_release);
                return true;
            case SDL_CONTROLLER_BUTTON_A:
                if (g_sidebar_cursor == kSlotRestart) {
                    g_sidebar_action.store(1, std::memory_order_release);
                    return true;
                }
                if (g_sidebar_cursor == kSlotExit) {
                    g_sidebar_action.store(2, std::memory_order_release);
                    return true;
                }
                // Otherwise fall through so A is routed to ImGui (activates
                // the focused widget in the content pane).
                break;
            default:
                break;
        }
    }

    // Route to inspector so the panel sees mouse / keyboard input, and feed
    // gamepad to ImGui ourselves (RT64's SDL2 backend ignores controllers).
    // Returning true below swallows the event: the game's input polling is
    // already zeroed via overlay::is_visible() in input_sample().
    if (g_app != nullptr && g_app->presentQueue != nullptr) {
        std::scoped_lock lock(g_app->presentQueue->inspectorMutex);
        if (auto* inspector = g_app->presentQueue->inspector.get()) {
            inspector->handleSdlEvent(event);
        }
    }
    feed_controller_to_imgui(*event);
    return true;
}

void toggle() {
    const bool next = !g_visible.load(std::memory_order_acquire);
    g_visible.store(next, std::memory_order_release);
    if (next) {
        // On open, reset the sidebar cursor to the current page and request
        // focus into the content panel so the D-pad drives widgets directly.
        g_sidebar_cursor = g_active;
        g_focus_content.store(true, std::memory_order_release);
    } else {
        // Cancel any pending rebind capture when the overlay closes.
        g_capture_target = CaptureTarget::None;
    }
}

bool is_visible() {
    return g_visible.load(std::memory_order_acquire);
}

} // namespace overlay
