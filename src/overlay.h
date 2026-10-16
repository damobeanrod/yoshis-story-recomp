// In-game settings overlay. See docs/OVERLAY_PLAN.md.
// Toggle with ESC (keyboard) or Back/Select (controller). While visible,
// game input is swallowed so the player effectively pauses.

#pragma once

union SDL_Event;
namespace RT64 { struct Application; }

namespace overlay {

// Install our RT64::Inspector on the application's PresentQueue. Must be
// called once after RT64::Application::setup() returns Success.
void attach(RT64::Application& app);

// Remove the Inspector before the application tears down.
void detach(RT64::Application& app);

// Drive the Inspector's ImGui frame. Must be called on the thread that
// owns updateScreen(), immediately after it returns, every frame.
void draw(RT64::Application& app);

// Returns true if the event was consumed and should not reach the game.
// Toggles visibility on ESC / F1 / Controller Back. Routes other events to
// the Inspector's ImGui backend when visible.
bool handle_event(SDL_Event* event);

void toggle();
bool is_visible();

} // namespace overlay
