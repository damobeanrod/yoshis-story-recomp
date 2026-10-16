#!/usr/bin/env bash
# Install a desktop entry + icon for the current user, so the app shows the
# egg icon (Wayland compositors take window icons from the .desktop file whose
# name matches the app id, "yoshis-story-recomp") and appears in the app menu.
#
#   tools/install_desktop.sh            # launcher runs build/yoshis_story_recomp
#   tools/install_desktop.sh --nix-shell  # launcher runs it inside tools/recomp-shell.nix
#   tools/install_desktop.sh --uninstall
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DATA="${XDG_DATA_HOME:-$HOME/.local/share}"
APP_ID="yoshis-story-recomp"
DESKTOP="$DATA/applications/$APP_ID.desktop"
ICON="$DATA/icons/hicolor/256x256/apps/$APP_ID.png"

if [[ "${1:-}" == "--uninstall" ]]; then
    rm -f "$DESKTOP" "$ICON"
    echo "removed $DESKTOP and $ICON"
    exit 0
fi

EXEC="$ROOT/build/yoshis_story_recomp"
if [[ "${1:-}" == "--nix-shell" ]]; then
    EXEC="nix-shell $ROOT/tools/recomp-shell.nix --run $ROOT/build/yoshis_story_recomp"
fi

mkdir -p "$(dirname "$DESKTOP")" "$(dirname "$ICON")"
cp "$ROOT/assets/icon.png" "$ICON"
cat > "$DESKTOP" <<DESK
[Desktop Entry]
Type=Application
Name=Yoshi's Story Recomp
Comment=Yoshi's Story (N64) static recompilation
Exec=$EXEC
Path=$ROOT/build
Icon=$APP_ID
Terminal=false
Categories=Game;
StartupWMClass=$APP_ID
DESK

command -v update-desktop-database >/dev/null && update-desktop-database "$DATA/applications" 2>/dev/null || true
command -v gtk-update-icon-cache >/dev/null && gtk-update-icon-cache -q "$DATA/icons/hicolor" 2>/dev/null || true
echo "installed $DESKTOP"
echo "installed $ICON"
