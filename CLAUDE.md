# Yoshi's Story recomp — agent rules

Read `docs/HANDOVER.md` first: the game is done and playable; it covers how
to build, why things are the way they are, known loose ends, and what to
upstream (RT64 S2DEX/edge-crop/CRT patches, N64Recomp, runtime, decomp).

## Hard rules
- Recompile only from a **matching** decomp ELF (`../yoshis-story-matching`).
  Verify with `tools/check_elf_matches.py` (must print `OK`). The old
  non-matching ELF shifted 549 functions by +0x10 and caused every earlier
  "fix" (delegators, stubs, gameMgr clamps, DL injection) — never bring those back.
- The matching decomp has **local changes** (overlays split out via
  `tools/find_overlays.py`, splat auto-symbol ld files on the link line); see
  "Local changes" in `docs/HANDOVER.md`. Keep its build ending in `OK`.
- RT64 changes live in `patches/rt64/*.patch` (stacked, applied by CMake);
  never commit a modified `rt64` submodule. After a patch changes:
  `git -C rt64 checkout -- .` then `cmake -B build`.
- Never hand-edit `recomp_funcs/`. Generated-code fixes go in post-process
  scripts (`tools/fix_zero_reg_loads.py`, `tools/fix_overlay_relocs.py`,
  `tools/fix_missing_overlay_relocs.py`, run by `tools/regen.py`) or `src/ignored_funcs.h` (prototypes, force-included).
  Diagnostics go in `[[patches.hook]]` entries in `config.toml` calling
  `yoshi_*` helpers in `src/main.cpp`.
- After changing `config.toml` or the ELF: `python3 tools/regen.py` (runs
  N64Recomp, auto-stubs functions it can't recompile, applies the fixers), then
  rebuild, then commit `recomp_funcs/` + `config.toml`. After changing only
  `src/`: just rebuild.
- Work on `main`. Never force-push.

## Environment (NixOS)
- Build/run inside `nix-shell tools/recomp-shell.nix` (cmake, ninja, SDL2,
  Vulkan, gtk3, gdb). Decomp builds use `tools/decomp-shell.nix`.
- Commit signing may need `git config commit.gpgsign false` if no signing key is configured.
- The decomp's `.venv/bin/python3` only works inside the decomp nix shell
  (FHS); run rabbitizer-based tools from there.
- Use separate terminals (or exit) for the two nix shells; commands from one
  repo run in the other fail confusingly.

## Stale notes
Memory notes from before 2026-10-04 (overlay/overlay2/dlinject/gamefb/pipeline)
describe the shifted-ELF era. Their "fixes" are obsolete; trust `docs/HANDOVER.md`.
