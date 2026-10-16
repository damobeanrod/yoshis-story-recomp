# FHS environment for building the yoshis-story decomp on NixOS.
#
# The decomp's Makefile hard-codes SHELL = /bin/bash, and `make setup`
# downloads prebuilt IDO compiler binaries (ido-static-recomp) linked
# against a standard glibc layout. Neither works on stock NixOS, so wrap
# the build in an FHS env that provides /bin/bash, the glibc loader,
# MIPS binutils and the Python wheels' native deps.
#
# Usage (from the decomp checkout):
#   nix-shell ../yoshis-story-recomp/tools/decomp-shell.nix
#   make venv && make setup && make extract && make
{ pkgs ? import <nixpkgs> {} }:

let
  # pkgsCross.mips-linux-gnu targets mips-unknown-linux-gnu, so the tools
  # are named mips-unknown-linux-gnu-ld etc. CROSS is exported below.
  mipsBinutils = pkgs.pkgsCross.mips-linux-gnu.buildPackages.binutils-unwrapped;
in
(pkgs.buildFHSEnv {
  name = "yoshi-decomp";
  targetPkgs = p: with p; [
    bash
    coreutils
    gnumake
    git
    gcc          # host cc + cpp (CC_CHECK and preprocessing)
    python3
    wget
    gnutar
    gzip
    which
    glibc.bin    # iconv
    zlib
    stdenv.cc.cc.lib  # libstdc++ for manylinux Python wheels
    mipsBinutils
  ];
  profile = ''
    export CROSS=mips-unknown-linux-gnu-
  '';
  runScript = "bash";
}).env
