#!/usr/bin/env python3
"""
Post-process N64Recomp output: relocate overlay HI16/LO16 pairs the ELF has no
relocation for.

N64Recomp only emits RELOC_HI16/RELOC_LO16 for instructions that carry an ELF
relocation. Splat sometimes doesn't symbolize an address pair in overlay code
(e.g. two lui/addiu pairs interleaved), so the decomp assembles it from plain
numbers: the bytes still match the ROM, but the recompiled code then uses the
overlay's link-time address instead of where the game loaded it. Example: in
func_8069D5B0 (.ovl_DC3330) `lui $s1, 0x806A` / `addiu $s1, $s1, -0x1D3E`
read a cast-id table from the unloaded address, asked for cast id 0 and hit
Fault_HungUp castManager.c:161 on the second level.

The ROM's own overlay relocation tables are authoritative (the game relocates
itself with them), so this pairs their text HI16/LO16 entries like the game's
relocator does (a LO16 uses the latest HI16 loaded into its base register) and
rewrites any of those instructions N64Recomp left unrelocated.

Run after every N64Recomp invocation (tools/regen.py does this):
  tools/fix_missing_overlay_relocs.py recomp_funcs [--rom data/yoshis_story.z64]
"""

import argparse
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
R_MIPS_HI16, R_MIPS_LO16 = 5, 6

SECTION_ENTRY = re.compile(r"\{ \.rom_addr = 0x([0-9A-F]+), \.ram_addr = 0x([0-9A-F]+), \.size = 0x([0-9A-F]+), "
                           r"\.funcs = section_\d+_ovl_[0-9A-F]+_funcs,.*?\.index = (\d+) \}")


def load_rom(path):
    rom = bytearray(path.read_bytes())
    magic = bytes(rom[:4])
    if magic == b"\x37\x80\x40\x12":            # .v64
        rom[0::2], rom[1::2] = rom[1::2], rom[0::2]
    elif magic == b"\x40\x12\x37\x80":          # .n64
        for i in range(0, len(rom) - 3, 4):
            rom[i:i + 4] = rom[i:i + 4][::-1]
    elif magic != b"\x80\x37\x12\x40":
        sys.exit(f"error: {path} does not look like an N64 ROM")
    return bytes(rom)


def u32(data, off):
    return struct.unpack_from(">I", data, off)[0]


def s16(v):
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def text_pairs(rom, rom_addr, ram_addr, size):
    """Yield (vram, kind, target_offset) for the text HI16/LO16 relocations of one
    overlay, kind being 'hi' or 'lo'. target_offset is relative to ram_addr."""
    end = rom_addr + size
    if end > len(rom) or size < 0x18:
        print(f"warning: overlay 0x{rom_addr:X} is outside the ROM, skipped")
        return
    back = u32(rom, end - 4)
    hdr = end - back
    if back < 0x18 or hdr < rom_addr or hdr & 3:
        print(f"warning: overlay 0x{rom_addr:X} has no valid relocation block, skipped")
        return
    text, data, rodata, bss, nrel = struct.unpack_from(">5I", rom, hdr)
    if text + data + rodata != hdr - rom_addr or hdr + 0x14 + 4 * nrel > end:
        print(f"warning: overlay 0x{rom_addr:X} relocation header doesn't match its size, skipped")
        return
    # Overlay_Load puts .bss after the whole file (including this relocation
    # block), so valid targets span the file plus .bss.
    limit = size + bss
    hi_by_reg = {}   # register -> (vram, hi16 value)
    for i in range(nrel):
        r = u32(rom, hdr + 0x14 + 4 * i)
        section, rtype, offset = r >> 30, (r >> 24) & 0x3F, r & 0xFFFFFF
        if section != 1 or rtype not in (R_MIPS_HI16, R_MIPS_LO16):
            continue
        instr = u32(rom, rom_addr + offset)
        vram = ram_addr + offset
        if rtype == R_MIPS_HI16:
            hi_by_reg[(instr >> 16) & 0x1F] = (vram, instr & 0xFFFF)
            continue
        base = (instr >> 21) & 0x1F
        if base not in hi_by_reg:
            continue
        hi_vram, hi = hi_by_reg[base]
        target = ((hi << 16) + s16(instr)) & 0xFFFFFFFF
        target_off = target - ram_addr
        if 0 <= target_off < limit:
            yield hi_vram, "hi", target_off
            yield vram, "lo", target_off


def fmt_imm(v):
    return f"-0X{-v:X}" if v < 0 else f"0X{v:X}"


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("out_dir", type=Path)
    ap.add_argument("--rom", type=Path, default=ROOT / "data" / "yoshis_story.z64")
    args = ap.parse_args()
    if not args.rom.exists():
        sys.exit(f"error: ROM not found at {args.rom} (needed for overlay relocation tables)")

    rom = load_rom(args.rom)
    inl = (args.out_dir / "recomp_overlays.inl").read_text()
    wanted = {}   # vram -> (kind, section index, target offset)
    for m in SECTION_ENTRY.finditer(inl):
        rom_addr, ram_addr, size, index = int(m[1], 16), int(m[2], 16), int(m[3], 16), int(m[4])
        for vram, kind, target_off in text_pairs(rom, rom_addr, ram_addr, size):
            prev = wanted.get(vram)
            if prev is not None and prev[0] == "hi" and kind == "hi" and \
                    ((prev[2] + 0x8000) >> 16) != ((target_off + 0x8000) >> 16):
                print(f"warning: lui at 0x{vram:08X} pairs with LO16s of different carry; keeping the first")
                continue
            wanted.setdefault(vram, (kind, index, target_off))

    patched = 0
    comment = re.compile(r"^\s*// 0x([0-9A-F]{8}): (\S+)\s+(.*)$")
    for path in sorted(args.out_dir.glob("funcs_*.c")):
        lines = path.read_text().split("\n")
        changed = False
        for i, line in enumerate(lines[:-1]):
            m = comment.match(line)
            if not m:
                continue
            vram = int(m[1], 16)
            if vram not in wanted or "RELOC_" in lines[i + 1]:
                continue
            kind, index, target_off = wanted[vram]
            code = lines[i + 1]
            if kind == "hi" and m[2] == "lui":
                new = re.sub(r"S32\(0X[0-9A-F]+ << 16\)", f"S32(RELOC_HI16({index}, 0X{target_off:X}) << 16)", code, count=1)
            elif kind == "lo":
                imm = s16(int(m[3].split(",")[-1].split("(")[0].strip(), 0))
                lit = fmt_imm(imm)
                new = re.sub(r"(?<![0-9A-FX])" + re.escape(lit) + r"(?![0-9A-F])",
                             f"(int16_t)RELOC_LO16({index}, 0X{target_off:X})", code, count=1)
            else:
                new = code
            if new != code:
                lines[i + 1] = new
                patched += 1
                changed = True
            else:
                print(f"warning: could not relocate {path.name} 0x{vram:08X}: {code.strip()}")
        if changed:
            path.write_text("\n".join(lines))
    print(f"relocated {patched} overlay instruction line(s) missing from the ELF relocations")


if __name__ == "__main__":
    main()
