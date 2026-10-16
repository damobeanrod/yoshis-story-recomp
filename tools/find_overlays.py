#!/usr/bin/env python3
"""
Find Yoshi's Story's relocatable overlays (.ovl files) in the ROM and emit the
splat segments that split them out of the decomp's opaque `unkbin` blob.

Background: the decomp's yamls/us/overlays.yaml treats everything after .main
(ROM 0xB58B0..0x1000000) as one binary blob, so the ELF has no overlay code and
N64Recomp cannot recompile it. At runtime the game loads overlays with
Overlay_Load(vromStart, vromEnd, vramStart, vramEnd, ram) and relocates them
(src/main/O2/loadfragment2.c). Actor/cast constructors live there.

Detection (both must agree):
  * a 4-word {romStart, romEnd, vramStart, vramEnd} tuple somewhere in the ROM
    (how the game references an overlay), with a KSEG0 vramStart outside .main
    (Yoshi links overlays inside the 8MB range, e.g. 0x80471040 — not at OoT/MM
    style fake addresses >= 0x80800000), and
  * a valid OverlayRelocationSection at the end of [romStart, romEnd): the last
    word is the offset back to the header {textSize, dataSize, rodataSize,
    bssSize, nRelocations, relocations[]}, and text+data+rodata == header offset.

Usage:
  tools/find_overlays.py --rom data/yoshis_story.z64
  tools/find_overlays.py --rom data/yoshis_story.z64 \
      --yaml overlays.yaml --sections overlay_sections.txt
"""

import argparse
import signal
import struct
import sys
from collections import defaultdict
from pathlib import Path

MAIN_ROM_END = 0xB58B0       # end of .main in ROM (yamls/us/main.yaml)
ROM_END = 0x1000000          # end marker in yamls/us/overlays.yaml
MAIN_VRAM_START = 0x80000400   # entry + .main
MAIN_VRAM_END = 0x80112CA0     # end of .main bss
MAX_OVL_SIZE = 0x200000


def u32(rom, off):
    return struct.unpack_from(">I", rom, off)[0]


def parse_ovl(rom, start, end):
    """Return the relocation header dict for the .ovl at [start, end), or None."""
    if end - start < 0x18 or end > len(rom):
        return None
    back = u32(rom, end - 4)
    hdr = end - back
    if back < 0x18 or not (start <= hdr < end) or hdr & 3:
        return None
    text, data, rodata, bss, nrel = struct.unpack_from(">5I", rom, hdr)
    if text + data + rodata != hdr - start:
        return None
    if hdr + 0x14 + 4 * nrel > end - 4:
        return None
    return dict(text=text, data=data, rodata=rodata, bss=bss, nrel=nrel, hdr=hdr)


def find_overlays(rom):
    found = {}
    refs = defaultdict(list)
    limit = min(len(rom), ROM_END) - 16
    for off in range(0x1000, limit, 4):
        rs, re_, vs, ve = struct.unpack_from(">4I", rom, off)
        if not (MAIN_ROM_END <= rs < re_ <= ROM_END) or rs & 3:
            continue
        if re_ - rs > MAX_OVL_SIZE or ve <= vs or vs & 3:
            continue
        if not (0x80000000 <= vs < ve <= 0xA0000000) or MAIN_VRAM_START <= vs < MAIN_VRAM_END:
            continue
        ovl = parse_ovl(rom, rs, re_)
        if ovl is None:
            continue
        if ve - vs < ovl["text"] + ovl["data"] + ovl["rodata"] + ovl["bss"]:
            continue
        key = (rs, re_, vs, ve)
        found[key] = ovl
        refs[key].append(off)
    return found, refs


def emit_yaml(overlays):
    """overlays.yaml replacement: overlay code segments with bin gaps between."""
    out = []
    cur = MAIN_ROM_END
    first_gap = True

    def gap(start, end):
        nonlocal first_gap
        if end <= start:
            return
        if first_gap:
            out.extend([
                "  - name: unkbin",
                "    type: bin",
                f"    start: 0x{start:X}",
                "    vram: 0x80112CA0",
                "    follows_vram: main",
            ])
            first_gap = False
        else:
            out.extend([
                f"  - name: unkbin_{start:X}",
                "    type: bin",
                f"    start: 0x{start:X}",
            ])

    by_vram = defaultdict(int)
    for (rs, re_, vs, ve), _ in overlays:
        by_vram[vs] += 1

    for (rs, re_, vs, ve), o in overlays:
        if rs < cur:
            print(f"warning: overlay 0x{rs:X} overlaps previous segment, skipped", file=sys.stderr)
            continue
        gap(cur, rs)
        name = f"ovl_{rs:06X}"
        out.extend([
            f"  - name: {name}",
            "    type: code",
            f"    start: 0x{rs:X}",
            f"    vram: 0x{vs:X}",
        ])
        if o["bss"]:
            out.append(f"    bss_size: 0x{o['bss']:X}")
        if by_vram[vs] > 1:
            out.append("    exclusive_ram_id: ovl")
        out.append("    subsegments:")
        out.append(f"      - [0x{rs:X}, asm]")
        p = rs + o["text"]
        if o["data"]:
            out.append(f"      - [0x{p:X}, data]")
        p += o["data"]
        if o["rodata"]:
            out.append(f"      - [0x{p:X}, rodata]")
        # rodatabin, not bin: splat groups a plain bin with .data, which would
        # place the relocation block before .rodata and break matching.
        out.append(f"      - [0x{o['hdr']:X}, rodatabin, {name}_reloc]")
        if o["bss"]:
            # Overlay_Load clears BSS at allocatedRam + (romEnd - romStart):
            # after the relocation block, not straight after rodata.
            bss_vram = vs + (re_ - rs)
            out.append(f"      - {{type: bss, vram: 0x{bss_vram:X}}}")
        cur = re_
    gap(cur, ROM_END)
    out.append(f"  - [0x{ROM_END:X}]")
    return "\n".join(out) + "\n"


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rom", required=True, type=Path, help="retail big-endian .z64")
    ap.add_argument("--yaml", type=Path, help="write an overlays.yaml replacement here")
    ap.add_argument("--sections", type=Path,
                    help="write N64Recomp relocatable section names (one per line) here")
    args = ap.parse_args()

    rom = args.rom.read_bytes()
    if rom[:4] != b"\x80\x37\x12\x40":
        sys.exit("error: ROM is not big-endian .z64")

    found, refs = find_overlays(rom)
    overlays = sorted(found.items())
    if args.yaml:
        args.yaml.write_text(emit_yaml(overlays))
        print(f"wrote {args.yaml}")
    if args.sections:
        args.sections.write_text("".join(f".ovl_{rs:06X}\n" for (rs, _, _, _), _ in overlays))
        print(f"wrote {args.sections}")

    print(f"{len(overlays)} overlays")
    print("  romStart  romEnd    vramStart vramEnd     text    data  rodata     bss nrel  refs")
    for (rs, re_, vs, ve), o in overlays:
        print(f"  {rs:08X}  {re_:08X}  {vs:08X}  {ve:08X}  {o['text']:6X}  {o['data']:6X}"
              f"  {o['rodata']:6X}  {o['bss']:6X} {o['nrel']:4d}  {len(refs[(rs, re_, vs, ve)])}")


if __name__ == "__main__":
    # Exit quietly when piped into head and the reader goes away.
    signal.signal(signal.SIGPIPE, signal.SIG_DFL)
    main()
