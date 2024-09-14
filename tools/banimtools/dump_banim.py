#!/bin/python3

import os, sys, struct
import array
from PIL import Image
import lzss_lib

import rom_def
import dump_banim_frame
import dump_banim_script
import dump_banim_oam

from rom_def import BANIM_MODES
from dump_banim_oam import BanimOAM
from dump_banim_script import BanimSCR

abbr_count = {}

class Symbol:
    def __init__(self, ptr, prefix, name, is_img=False):
        self.ptr = ptr
        self.prefix = prefix
        self.name = name
        self.is_img = is_img

all_symbols = []

def sort_symbols(symbols):
    seen_ptrs = set()
    unique_symbols = []

    for symbol in symbols:
        if symbol.ptr not in seen_ptrs:
            seen_ptrs.add(symbol.ptr)
            unique_symbols.append(symbol)

    return sorted(unique_symbols, key=lambda x: x.ptr)

def dump_scr_frame(img_addr, pal_addr, out_png):
    img_bytes = lzss_lib.lz77_decomp_data(img_addr)
    pal_bytes = lzss_lib.lz77_decomp_data(pal_addr)
    img_data = array.array('B', img_bytes)
    img = dump_banim_frame.create_image_from_4bpp(img_data, pal_bytes, 256, 64)
    img.save(out_png)

def dump_modes(prefix, addr, scrs):
    offset = addr & 0x00FFFFFF

    print(f".global BANIM_MODES_{prefix}")
    print(f"BANIM_MODES_{prefix}:")

    with open(rom_def.ROM, "rb") as f:
        f.seek(offset)
        data = f.read(12 * 2 * 4)

        for i in range(24):
            scr_offset = int.from_bytes(data[i*4 : i*4+4], 'little')
            mode_str = f"0x{scr_offset:X}"

            # corner case 1?
            if i >= 12 and scr_offset != 0:
                break

            # corner case 2?
            if scr_offset > 0x6000:
                break

            if i == 0 or scr_offset != 0:
                for scr in scrs:
                    if scr.offset == scr_offset:
                        mode_str = f"{scr.name} - SCR"

            print(f"    .word {mode_str}")

def dump_one_banim_data_ent(addr, out_dir):
    global abbr_count, all_symbols
    struct_format = '12s 5I'

    with open(rom_def.ROM, "rb") as f:
        f.seek(addr)
        data = f.read(32)

    abbr, modes, script, oam_r, oam_l, pal = struct.unpack(struct_format, data)

    abbr_str = abbr.decode('utf-8').rstrip(chr(0))
    if abbr_str in abbr_count:
        abbr_count[abbr_str] += 1
        abbr_str = f"{abbr_str}_{abbr_count[abbr_str]}"
    else:
        abbr_count[abbr_str] = 1

    all_symbols.append(Symbol(modes, abbr_str, f"BANIM_MODE_{abbr_str}"))
    all_symbols.append(Symbol(script, abbr_str, f"BANIM_SCR_{abbr_str}"))
    all_symbols.append(Symbol(oam_r, abbr_str, f"BANIM_OAMR_{abbr_str}"))
    all_symbols.append(Symbol(oam_l, abbr_str, f"BANIM_OAML_{abbr_str}"))
    all_symbols.append(Symbol(pal, abbr_str, f"BANIM_PAL_{abbr_str}"))

    out_dir_ext = f"{out_dir}/{abbr_str}"
    os.makedirs(out_dir_ext, exist_ok=True)
    out_sfile = f"{out_dir_ext}/{abbr_str}.s"

    with open(out_sfile, 'w') as file:

        original_stdout = sys.stdout
        sys.stdout = file

        try:
            print(".include \"macro.inc\"")
            print(".include \"animscr.inc\"")
            print(".include \"gba_sprites.inc\"")
            print("")
            print(".section .data.oamr")
            oams_r = dump_banim_oam.dump_banim_oam_r(abbr_str, oam_r)

            print("")
            print(".section .data.oaml")
            oams_l = dump_banim_oam.dump_banim_oam_l(abbr_str, oam_l)

            print("")
            print(".section .data.script")
            scrs, anim_frames = dump_banim_script.dump_banim_script(abbr_str, script, oams_r)

            anim_frames = list(set(anim_frames))
            anim_frames.sort()

            print("")
            print(".section .data.modes")
            dump_modes(abbr_str, modes, scrs)

            # print("")
            # print(".section .data.frames")
            dump_banim_frame.dump_banim_frames(abbr_str, anim_frames, pal, out_dir_ext)

            for i, img_addr in enumerate(anim_frames):
                all_symbols.append(Symbol(img_addr, abbr_str, f"BANIM_IMG_{abbr_str}_{i}", True))

        finally:
            sys.stdout = original_stdout


def main(args):
    global all_symbols

    out_dir = "data/banims" # "out"

    for i in range(122):
        dump_one_banim_data_ent(0x6A0008 + i * 32, out_dir)

    print("    .data")
    sorted_symbols = sort_symbols(all_symbols)
    for i, symbol in enumerate(sorted_symbols):
        print(f"    .global {symbol.name}")
        print(f"{symbol.name}: @ 0x{symbol.ptr:08X}")

        cur = symbol.ptr & 0x00FFFFFF
        end = 0x7E989C # hardcoded lol
        if i < (len(sorted_symbols) - 1):
            end = sorted_symbols[i + 1].ptr & 0x00FFFFFF


        if symbol.name[0:9] == "BANIM_IMG":
            print(f"    .incbin \"data/banims/{symbol.prefix}/{symbol.name}.4bpp.lz\"")
        elif symbol.name[0:10] == "BANIM_OAMR":
            print(f"    .incbin \"data/banims/{symbol.prefix}/{symbol.prefix}.oamr.bin.lz\"")
        elif symbol.name[0:10] == "BANIM_OAML":
            print(f"    .incbin \"data/banims/{symbol.prefix}/{symbol.prefix}.oaml.bin.lz\"")
        elif symbol.name[0:10] == "BANIM_MODE":
            print(f"    .incbin \"data/banims/{symbol.prefix}/{symbol.prefix}.mode.bin\"")

            if (end - cur) > (24 * 4):
                cur += 24 * 4
                print("")
                ptr = f"{(cur + 0x08000000):08X}"
                name = f"gUnk_{ptr}"
                print(f"    .global {name}")
                print(f"{name}: @ {ptr}")
                print(f"    .incbin \"fe6-base.gba\", 0x{cur:06X}, 0x{end:06X} - 0x{cur:06X}")

        else:
            print(f"    .incbin \"fe6-base.gba\", 0x{cur:06X}, 0x{end:06X} - 0x{cur:06X}")

        print("")

if __name__ == '__main__':
    main(sys.argv)