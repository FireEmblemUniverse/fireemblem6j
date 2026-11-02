#!/usr/bin/env python3
"""Convert between a chapter tileset's TsaConf and editable chip sources.

A TsaConf holds 1024 metatiles ("chips"), each four 8x8 tile references
(tile index, flips, palette), followed by a 1024-byte terrain table.
The chip sources are:
  - a 512x512 8-bit indexed PNG with one chip per 16x16 cell, where each
    pixel's index is palette * 16 + color
  - a terrain text file, 32 rows of 32 hex bytes
  - a hints file: the filler entry used for empty chips, and the tile
    choices for chips where several sheet tiles match the same pixels

Tile sheets are 8-bit indexed PNGs in the same palette * 16 + color
encoding, so each tile can be shown in the palette it is used with.
Only the low four bits of each pixel reach the 4bpp output.

Usage:
  mapchips.py build   CHIPS.png TERRAIN.txt HINTS.txt OUT.tsa SHEET.4bpp [SHEET2.4bpp]
  mapchips.py extract IN.tsa PAL.pal CHIPS.png TERRAIN.txt HINTS.txt SHEET.4bpp [SHEET2.4bpp]
  mapchips.py sheet   SHEET.png OUT.4bpp [NUM_TILES]
  mapchips.py map     MAP.tsa CHIPS.png OUT.png

The map mode renders a decompressed chapter map with a metatile image,
for previewing edits.
"""

import struct
import sys
from collections import defaultdict

from PIL import Image

CHIPS = 1024
GRID = 32
SHEET_W = 32
QUAD_OFF = (0, 1, SHEET_W, SHEET_W + 1)
BLANK = (0,) * 64


def read_sheet(paths):
    slots = []
    for path in paths:
        data = open(path, 'rb').read()
        tiles = []
        for i in range(0, len(data), 32):
            px = []
            for b in data[i:i + 32]:
                px += [b & 15, b >> 4]
            tiles.append(tuple(px))
        slots += tiles + [None] * (512 - len(tiles))
    return slots[:CHIPS]


def flip(tile, h, v):
    rows = [tile[r * 8:r * 8 + 8] for r in range(8)]
    if h:
        rows = [r[::-1] for r in rows]
    if v:
        rows = rows[::-1]
    return tuple(p for r in rows for p in r)


def entry(j, h, v, pal):
    return j | h << 10 | v << 11 | pal << 12


def split_entry(e):
    return e & 0x3ff, e >> 10 & 1, e >> 11 & 1, e >> 12


def read_jasc(path):
    lines = open(path).read().split('\n')
    return [tuple(int(x) for x in line.split()) for line in lines[3:3 + int(lines[2])]]


def read_hints(path):
    filler = None
    picks = {}
    for line in open(path):
        words = line.split()
        if not words:
            continue
        if words[0] == 'filler':
            filler = int(words[1], 16)
        else:
            picks[int(words[0], 16)] = [int(w, 16) for w in words[1:5]]
    return filler, picks


def chip_quads(img):
    """Yield (pal, pattern) for each 8x8 quadrant of each chip, chip-major."""
    px = img.load()
    for m in range(CHIPS):
        cx, cy = m % GRID * 16, m // GRID * 16
        quads = []
        for k in range(4):
            ox, oy = cx + (k & 1) * 8, cy + (k >> 1) * 8
            vals = [px[ox + x, oy + y] for y in range(8) for x in range(8)]
            pals = set(v >> 4 for v in vals)
            if len(pals) != 1:
                sys.exit('chip %03x quadrant %d mixes palettes' % (m, k))
            quads.append((pals.pop(), tuple(v & 15 for v in vals)))
        yield m, quads


def default_pick(cands, k):
    """Prefer a 2x2 sheet block holding the whole chip, else the lowest tile."""
    blocks = set(j for j, h, v in cands[0] if (h, v) == (0, 0))
    for kk in range(1, 4):
        blocks &= set(j - QUAD_OFF[kk] for j, h, v in cands[kk] if (h, v) == (0, 0))
    if blocks:
        return (min(blocks) + QUAD_OFF[k], 0, 0)
    return min(cands[k])


def convert(img, sheet, filler, picks):
    look = defaultdict(set)
    for j, tile in enumerate(sheet):
        if tile is None:
            continue
        for h in (0, 1):
            for v in (0, 1):
                look[flip(tile, h, v)].add((j, h, v))

    def renders(e, pal, pattern):
        j, h, v, p = split_entry(e)
        if p != pal:
            return False
        if j >= len(sheet) or sheet[j] is None:
            return pattern == BLANK
        return flip(sheet[j], h, v) == pattern

    out = []
    for m, quads in chip_quads(img):
        hint = picks.get(m)
        if hint and all(renders(hint[k], *quads[k]) for k in range(4)):
            out += hint
            continue
        if filler is not None and all(renders(filler, *quads[k]) for k in range(4)):
            out += [filler] * 4
            continue
        cands = [look.get(pattern) for pal, pattern in quads]
        for k in range(4):
            if not cands[k]:
                sys.exit('chip %03x quadrant %d: no sheet tile matches' % (m, k))
        for k in range(4):
            j, h, v = default_pick(cands, k)
            out.append(entry(j, h, v, quads[k][0]))
    return out


def open_chips(path):
    img = Image.open(path)
    if img.mode != 'P' or img.size != (GRID * 16, GRID * 16):
        sys.exit('%s: expected a 512x512 indexed PNG' % path)
    return img


def build(chips_path, terrain_path, hints_path, out_path, sheet_paths):
    filler, picks = read_hints(hints_path)
    ents = convert(open_chips(chips_path), read_sheet(sheet_paths), filler, picks)
    terrain = bytes(int(w, 16) for line in open(terrain_path) for w in line.split())
    if len(terrain) != CHIPS:
        sys.exit('%s: expected %d terrain bytes' % (terrain_path, CHIPS))
    with open(out_path, 'wb') as f:
        f.write(struct.pack('<%dH' % (CHIPS * 4), *ents))
        f.write(terrain)


def extract(tsa_path, pal_path, chips_path, terrain_path, hints_path, sheet_paths):
    sheet = read_sheet(sheet_paths)
    raw = open(tsa_path, 'rb').read()
    ents = list(struct.unpack('<%dH' % (CHIPS * 4), raw[:CHIPS * 8]))
    terrain = raw[CHIPS * 8:]

    img = Image.new('P', (GRID * 16, GRID * 16))
    img.putpalette([c for col in read_jasc(pal_path)[:80] for c in col])
    px = img.load()
    for m in range(CHIPS):
        cx, cy = m % GRID * 16, m // GRID * 16
        for k in range(4):
            j, h, v, p = split_entry(ents[m * 4 + k])
            tile = sheet[j] if j < len(sheet) and sheet[j] is not None else BLANK
            tile = flip(tile, h, v)
            ox, oy = cx + (k & 1) * 8, cy + (k >> 1) * 8
            for y in range(8):
                for x in range(8):
                    px[ox + x, oy + y] = p * 16 + tile[y * 8 + x]
    img.save(chips_path)

    with open(terrain_path, 'w') as f:
        for r in range(GRID):
            f.write(' '.join('%02x' % b for b in terrain[r * GRID:(r + 1) * GRID]) + '\n')

    uniform = defaultdict(int)
    for m in range(CHIPS):
        e = ents[m * 4:m * 4 + 4]
        if len(set(e)) == 1:
            uniform[e[0]] += 1
    filler = max(uniform, key=uniform.get) if uniform else None
    rebuilt = convert(img, sheet, filler, {})
    with open(hints_path, 'w') as f:
        if filler is not None:
            f.write('filler %04x\n' % filler)
        for m in range(CHIPS):
            if rebuilt[m * 4:m * 4 + 4] != ents[m * 4:m * 4 + 4]:
                f.write('%03x %04x %04x %04x %04x\n' % ((m,) + tuple(ents[m * 4:m * 4 + 4])))


def sheet(png_path, out_path, num_tiles):
    img = Image.open(png_path)
    if img.mode != 'P' or img.size[0] != SHEET_W * 8:
        sys.exit('%s: expected an indexed PNG %d pixels wide' % (png_path, SHEET_W * 8))
    px = img.load()
    rows = img.size[1] // 8
    if num_tiles is None:
        num_tiles = rows * SHEET_W
    out = bytearray()
    for j in range(num_tiles):
        ox, oy = j % SHEET_W * 8, j // SHEET_W * 8
        for y in range(8):
            for x in range(0, 8, 2):
                out.append(px[ox + x, oy + y] & 15 | (px[ox + x + 1, oy + y] & 15) << 4)
    open(out_path, 'wb').write(out)


def render_map(map_path, chips_path, out_path):
    data = open(map_path, 'rb').read()
    w, h = data[0], data[1]
    cells = struct.unpack('<%dH' % (w * h), data[2:2 + w * h * 2])
    chips = open_chips(chips_path).convert('RGB')
    out = Image.new('RGB', (w * 16, h * 16))
    for i, v in enumerate(cells):
        m = v >> 2
        cx, cy = m % GRID * 16, m // GRID * 16
        out.paste(chips.crop((cx, cy, cx + 16, cy + 16)), (i % w * 16, i // w * 16))
    out.save(out_path)


def main(argv):
    if len(argv) == 5 and argv[1] == 'map':
        render_map(argv[2], argv[3], argv[4])
    elif len(argv) in (4, 5) and argv[1] == 'sheet':
        sheet(argv[2], argv[3], int(argv[4]) if len(argv) == 5 else None)
    elif len(argv) >= 7 and argv[1] == 'build':
        build(argv[2], argv[3], argv[4], argv[5], argv[6:])
    elif len(argv) >= 8 and argv[1] == 'extract':
        extract(argv[2], argv[3], argv[4], argv[5], argv[6], argv[7:])
    else:
        sys.exit(__doc__)


if __name__ == '__main__':
    main(sys.argv)
