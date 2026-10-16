# Dev shell for building and running the recomp itself on NixOS.
#
# Host toolchain only — no MIPS compiler is needed here (that's
# tools/decomp-shell.nix, for building the decomp ELF).
#
# Usage (from this repo):
#   nix-shell tools/recomp-shell.nix
#   cmake -B build -DCMAKE_BUILD_TYPE=Release && cmake --build build -j$(nproc)
{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    cmake
    ninja
    pkg-config
    python3
    gdb                  # thread backtraces when the game stalls
  ];
  buildInputs = with pkgs; [
    SDL2
    gtk3                 # RT64's nativefiledialog-extended
    vulkan-headers
    vulkan-loader
    xorg.libX11          # SDL_syswm.h pulls in Xlib.h
    xorg.xorgproto
    libxkbcommon
    wayland
  ];
  shellHook = ''
    # RT64 loads Vulkan at runtime via volk (dlopen), so the loader and the
    # system GPU drivers must be on the library path.
    export LD_LIBRARY_PATH=${pkgs.lib.makeLibraryPath [ pkgs.vulkan-loader ]}:/run/opengl-driver/lib''${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
    export CMAKE_GENERATOR=Ninja
  '';
}
