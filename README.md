# Yoshi's Story Recomp

A native PC port of Yoshi's Story (N64, US) built with static recompilation.
You supply the ROM; this repo supplies everything else.

Uses [N64Recomp](https://github.com/N64Recomp/N64Recomp),
[N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime) and
[RT64](https://github.com/rt64/rt64).

---

> **⚠️ AI-generated project — please read before using or contributing**
>
> This port was created primarily by [Claude](https://claude.ai) (Anthropic's
> AI assistant), directed by a hobbyist with no prior N64 or graphics
> programming experience. Almost all of the C++, Python tooling, CMake, and
> RT64 patches in this repo were written by Claude in an interactive session —
> what the community calls "vibe coding."
>
> The code works and the game is fully playable, but it has not been written or
> reviewed by experienced graphics or systems programmers. There will be rough
> edges, non-idiomatic patterns, and corners that were never examined. If you
> are considering upstreaming any of the RT64 patches or runtime changes,
> please scrutinise them carefully before doing so.
>
> The underlying tools that make this possible — N64Recomp, N64ModernRuntime,
> RT64, and the Yoshi's Story decompilation — are the work of talented,
> experienced humans. See **Credits** below.

---

## Requirements

- A Yoshi's Story (US) ROM: `yoshis_story.z64`
- A Vulkan-capable GPU and driver
- Linux (Ubuntu 24.04+ or equivalent; NixOS also supported)

## Getting started — AppImage (easiest)

Download the AppImage from the [releases page](../../releases), make it
executable, then set up your files next to it:

```
yoshis-story-recomp-x86_64.AppImage   ← the download
data/
  yoshis_story.z64                     ← your ROM goes here
  saves/                               ← created automatically on first run
```

```bash
chmod +x yoshis-story-recomp-x86_64.AppImage
./yoshis-story-recomp-x86_64.AppImage
```

The AppImage is self-contained and portable — move the AppImage and its
`data/` folder together anywhere on your system and it will work. No
installation required. Requires SDL2, GTK3, and a Vulkan driver on the
host system (present by default on Ubuntu 24.04+).

---

## Getting started — build from source (Ubuntu 24.04+)

### 1. Install dependencies

```bash
sudo apt install build-essential cmake ninja-build pkg-config python3 \
    libsdl2-dev libvulkan-dev libgtk-3-dev libx11-dev libxkbcommon-dev \
    libwayland-dev
```

> Ubuntu 22.04 ships SDL 2.0.20 which is too old. Use 24.04 or later.

### 2. Clone

```bash
git clone --recursive https://github.com/damobeanrod/yoshis-story-recomp
cd yoshis-story-recomp
```

N64ModernRuntime must sit **next to** this repo as a sibling folder:

```bash
cd ..
git clone https://github.com/N64Recomp/N64ModernRuntime
git -C N64ModernRuntime checkout cdf5abbd5026fef5c364c676e4667c45e42b6863
git -C N64ModernRuntime submodule update --init --recursive
cd yoshis-story-recomp
```

### 3. Add your ROM

```bash
cp /path/to/yoshis_story.z64 data/
```

### 4. Build and run

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release -G Ninja
cmake --build build -j$(nproc)
./build/yoshis_story_recomp
```

### Optional: app menu entry

```bash
tools/install_desktop.sh
```

Installs `~/.local/share/applications/yoshis-story-recomp.desktop`. On
Wayland the window icon is matched by app id `yoshis-story-recomp`; on
X11 it is set directly.

---

## NixOS

```bash
nix-shell tools/recomp-shell.nix
cmake -B build -DCMAKE_BUILD_TYPE=Release -G Ninja
cmake --build build -j$(nproc)
./build/yoshis_story_recomp
```

The binary links against Nix store paths and runs outside the shell on the
machine it was built on until `nix-collect-garbage` removes those paths;
rebuild if that happens.

---

## Building a release AppImage (Ubuntu 24.04)

AppImages are not committed to the repo. To produce one:

### 1. Build the binary

Inside an Ubuntu 24.04 environment (distrobox works well):

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release -G Ninja
cmake --build build -j$(nproc)
```

### 2. Download the packaging tools

```bash
mkdir -p appimage-tools
wget -O appimage-tools/linuxdeploy \
    https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage
wget -O appimage-tools/appimagetool \
    https://github.com/AppImage/appimagetool/releases/download/continuous/appimagetool-x86_64.AppImage
chmod +x appimage-tools/linuxdeploy appimage-tools/appimagetool
```

### 3. Assemble the AppDir

```bash
mkdir -p AppDir/usr/bin
cp build/yoshis_story_recomp AppDir/usr/bin/
cp assets/icon.png AppDir/yoshis-story-recomp.png

cat > AppDir/yoshis-story-recomp.desktop << 'EOF'
[Desktop Entry]
Type=Application
Name=Yoshi's Story Recomp
Exec=yoshis_story_recomp
Icon=yoshis-story-recomp
Categories=Game;
EOF

cat > AppDir/AppRun << 'EOF'
#!/bin/bash
APPDIR="$(dirname "$(readlink -f "$0")")"
export LD_LIBRARY_PATH="${APPDIR}/usr/lib:${LD_LIBRARY_PATH}"
if [ -z "$YOSHI_DATA_DIR" ] && [ -n "$APPIMAGE" ]; then
    export YOSHI_DATA_DIR="$(dirname "$(readlink -f "$APPIMAGE")")/data"
fi
exec "${APPDIR}/usr/bin/yoshis_story_recomp" "$@"
EOF
chmod +x AppDir/AppRun
```

### 4. Create the AppImage

Run `appimagetool` from the host (it needs the `file` command, which may not be
in a distrobox). On NixOS: `nix-shell -p file --run "..."`.

```bash
APPIMAGE_EXTRACT_AND_RUN=1 appimage-tools/appimagetool \
    AppDir yoshis-story-recomp-x86_64.AppImage
```

The resulting AppImage requires SDL2, GTK3, and a Vulkan driver on the target
system — all present by default on Ubuntu 24.04+. See the file layout in
**Getting started — AppImage** above.

---

## Data folder

The game stores everything in one folder: the ROM (`yoshis_story.z64`),
saves (`saves/`), `settings.ini` and `mods.json`. The folder is located
in this order:

1. `YOSHI_DATA_DIR` environment variable, if set
2. `data/` next to the executable
3. `../data/` relative to the executable (so `build/` inside the repo works)

The executable's real path is used, so symlinks and PATH launches work.
RT64's own config (`rt64.json`) lives in `~/.config/.yoshis_story_recomp/`.

---

## Controls

Any SDL-supported controller works (hot-plug supported) alongside the
keyboard simultaneously. Rumble is forwarded to the controller.

| N64 | Keyboard | Controller (Xbox layout) |
| --- | --- | --- |
| Stick | WASD / arrow keys | Left stick |
| A | Space / X | A |
| B | Left Shift / C | B or X |
| Z | Z | Left trigger |
| Start | Enter | Start |
| L / R | Q / E | LB / RB (RT = R too) |
| C buttons | I J K L | Right stick |
| D-pad | T F G H | D-pad |

Open the in-game overlay with **F1** to remap bindings in the Controls tab.

---

## Display settings

A launcher window opens before the game with options for resolution
(native 320×240, fit window, or 2×–8×), supersampling, MSAA, 2D
upscaling, output filter, CRT scanline filter, overscan crop and
fullscreen. Settings are saved to `data/settings.ini`.

Uncheck "Show this window at startup" to skip it. Use `YOSHI_LAUNCHER=1`
to force it for one run, `YOSHI_LAUNCHER=0` to skip it.

In-game: **F11** or **Alt+Enter** toggles fullscreen; **F10** cycles the
CRT filter (off → 0.25 → 0.5 → 1.0). Both are remembered.

Environment variable overrides (one run only, not saved):

| Variable | Effect |
| --- | --- |
| `YOSHI_RES=native\|window\|N` | 320×240, fit window, or N × 240p (e.g. `4` = 1280×960) |
| `YOSHI_SSAA=N` | Render N× larger and downsample (fixed resolution only) |
| `YOSHI_MSAA=0\|2\|4\|8` | Multisample anti-aliasing |
| `YOSHI_UPSCALE2D=all\|scaled\|original` | Which 2D elements render at the upscaled resolution |
| `YOSHI_FILTER=pixel\|nearest\|linear` | Final image scaling filter |
| `YOSHI_CRT=0..1` | CRT filter strength (needs ≥720 px tall window) |
| `YOSHI_CROP=N` | Framebuffer pixels hidden per edge (default 2; 0 = off) |
| `YOSHI_FULLSCREEN=0\|1` | Start fullscreen or windowed |

---

## Regenerating the recompiled code

`recomp_funcs/` is pre-generated and committed — most users never need to
touch it. If you need to regenerate (e.g. after a config or ELF change):

```bash
# Paths assume sibling layout; adjust if yours differs
ELF=../yoshis-story-matching/build/yoshisstory-us.elf
ROM=../yoshis-story-matching/baseroms/us/baserom.z64

cmake -S ../N64ModernRuntime/N64Recomp -B build-n64recomp -DCMAKE_BUILD_TYPE=Release
cmake --build build-n64recomp --target N64Recomp -j$(nproc)

python3 tools/check_elf_matches.py --elf $ELF --rom $ROM   # must print OK
python3 tools/gen_function_sizes.py --elf $ELF --config config.toml
python3 tools/regen.py --n64recomp build-n64recomp/N64Recomp
```

The decomp ELF comes from [decompals/yoshis-story](https://github.com/decompals/yoshis-story)
built in MATCHING mode (`make` must end with `build/yoshisstory-us.z64: OK`).
Never hand-edit `recomp_funcs/`; regeneration overwrites all changes. Fixes
to generated code go in `tools/fix_*.py` or `src/ignored_funcs.h`.

---

## Credits

### Tools this port is built on

**[Mr-Wiseguy](https://github.com/Mr-Wiseguy)** created
[N64Recomp](https://github.com/N64Recomp/N64Recomp) and
[N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime) — the
static recompilation framework that makes native N64 ports like this one
possible. Without this work, this project could not exist.

**[Dario](https://github.com/DarioSamo)** and the
[RT64 team](https://github.com/rt64/rt64/graphs/contributors) built the
renderer that drives all 3D and 2D output.

**The [decompals/yoshis-story](https://github.com/decompals/yoshis-story)
team** produced the matching decompilation of the game whose ELF was used
to generate `recomp_funcs/`.

### This port

The port was directed by **damobeanrod** (concept, testing, and engineering
decisions) and implemented almost entirely by
**[Claude](https://claude.ai)** (Anthropic's AI assistant), which wrote the
C++ runtime glue, launcher, in-game overlay, audio, input, RT64 patches,
Python tooling, and CMake build system through an extended interactive
session.

The app icon was hand-designed and generated by `tools/gen_icon.py`.

### Third-party libraries

- [N64Recomp / N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime) — Mr-Wiseguy
- [RT64](https://github.com/rt64/rt64) — Dario and contributors
- [SDL2](https://www.libsdl.org/)
- [Dear ImGui](https://github.com/ocornut/imgui)

---

## Licensing and IP disclaimer

Yoshi's Story and all related names, characters, and assets are the property
of Nintendo. This project does not include, distribute, or grant rights to
the game ROM or any Nintendo-owned assets. You must supply your own legally
obtained copy of the game.

This repository contains `recomp_funcs/`, which is machine-generated C code
produced by N64Recomp from a decompilation ELF. It follows the same
precedent as other public N64 recompilation projects.
