# Chapter tilesets

This covers the map tileset sources in `data/mapassets/`: what each file is,
which ones to edit, how the build turns them into ROM data, and how to preview
a chapter map.

## How the game draws a map

A chapter map is a grid of 16x16 metatiles. Each metatile is four 8x8 tiles
from a tile sheet loaded into VRAM, each with its own flips and palette. The
game keeps three pieces of data per tileset:

- the tile sheet (`asset_img_a`, and `asset_img_b` for tileset 01), 4bpp tile
  graphics decompressed to VRAM
- the palette (`asset_pal`), ten 16-colour banks
- the TsaConf (`asset_tileset`), 1024 metatiles of four tile references each,
  followed by a 1024-byte terrain table

The chapter's map (`asset_map`) is a width byte, a height byte, then one u16 per
cell. The cell value divided by 4 is the metatile index.

Which assets a chapter uses is in `src/chapterinfo_data.c`, and the asset table
itself is `ChapterAssets[]` in `src/chapterinfo_assets.c`.

Palette banks 0 to 4 are the normal colours. Banks 5 to 9 are used for cells
hidden by fog. A tile reference's palette field selects a bank from 0 to 4.

## Source files

Each tileset `XX` has these sources:

| File | Content | Edit it to |
| --- | --- | --- |
| `MapAssetXX_Metatiles.png` | 512x512 indexed PNG, one metatile per 16x16 cell, 32 cells per row. Cell `n` is at column `n % 32`, row `n / 32`. | Compose metatiles from existing tiles, change which palette a metatile uses |
| `MapAssetXX_Img.png` (or `_Img1`, `_Img2`) | Tile sheet, 256 pixels wide, 32 tiles per row | Draw new tiles |
| `MapAssetXX_Terrain.txt` | 32 rows of 32 hex bytes, the terrain type of each metatile | Change terrain |
| `MapAssetXX_Pal.pal` | JASC palette, 160 colours, bank `b` colour `c` at line `b * 16 + c` | Change colours |
| `MapAssetXX_Hints.txt` | Tile picks needed to rebuild the vanilla ROM byte for byte | Nothing; see below |

Both PNG kinds are 8-bit indexed with the same pixel encoding: pixel index is
`palette * 16 + colour`. So a pixel with index 35 is colour 3 of bank 2. The
build reads only the indices. The RGB values in the PNG are for display, and
where two banks share a colour the PNG's copy is nudged by one so that every
index has its own RGB value.

Colour 0 of every bank is transparent in-game. It appears in the PNGs as
whatever RGB the palette file gives it, usually a solid dark colour.

### Editing in GIMP or Aseprite

The images must stay indexed, with their palette untouched. That gives these
rules for a general-purpose editor:

- Never convert to RGB and back. The editor would rebuild the palette and the
  indices would no longer encode banks.
- Pick colours from the image or its colormap, not from an RGB picker. Since
  every palette entry has a unique RGB value, a colour picked from the image
  maps back to the right index.
- Copy and paste within the same image, or between images of the same tileset,
  is fine. Pasting from another tileset goes through RGB and will be remapped
  to the nearest colours, which is rarely what you want.
- Export as PNG with the default options. GIMP keeps the colormap as is;
  Aseprite's indexed mode paints by index directly.
- Don't let the editor add transparency, drop unused palette entries, or
  reduce the colour count.

Usenti and other GBA-specific editors work on indices natively and need no
special care.

## Editing metatiles

Edit `MapAssetXX_Metatiles.png`. Each 8x8 quarter of a metatile must match some
tile on the sheet exactly, allowing horizontal and vertical flips, and all 64
pixels of the quarter must use the same palette bank. The build looks the tile
up on the sheet and writes the reference. If a quarter matches nothing, the
build stops with the metatile index and quarter that failed.

Terrain for the metatile goes in `MapAssetXX_Terrain.txt` at the same row and
column. Terrain IDs are in `include/constants/terrains.h`.

Metatiles that are solid colour 0 in bank 0 become the tileset's filler entry.

## Adding tiles

Draw the new 8x8 tiles into free space on `MapAssetXX_Img.png`, in any bank you
like for display. Only the low four bits of each pixel reach the ROM, so the
sheet's colouring is cosmetic. The tile's real palette is chosen per use, in the
metatile image.

The sheet has fixed slots the game overwrites at runtime. Tile animations
(`asset_img_anims`) copy frames into the sheet starting at tile 0x100, so don't
put static tiles where an animation writes. Some sheets end on a partial row;
their tile counts are the `NUM_TILES` lines in the Makefile. Adding a tile past
the end means raising that count.

Tiles 0 to 511 come from `_Img1` and 512 upward from `_Img2` on tileset 01.
Other tilesets have one sheet.

## Why the sheets look odd

The sheet PNGs are generated from ROM data and three things in them look wrong
but are correct:

- **Solid blocks** are colour 0, which is transparent in-game. Those slots are
  empty.
- **Jumbled areas** are tiles stored as deduplicated 8x8 fragments in no
  particular order. Only some regions of each sheet were laid out as whole
  16x16 blocks. The metatile image is where the fragments assemble.
- **Noise-like tiles** are ones no metatile references. Nothing draws them, so
  they have no real palette. They are shown in the palette of an identical tile
  elsewhere on the sheet, or failing that the nearest used tile.

## Hints files

The ROM often picks one of several identical sheet tiles, or a flipped copy,
with no visible rule. `MapAssetXX_Hints.txt` records those picks so the vanilla
build matches: a `filler` line with the entry used for empty metatiles, then
one line per metatile that needs a specific set of four references.

A hint is applied only if it still renders to what the metatile image shows.
If you edit a metatile, its hint is ignored automatically. A hack does not need
to maintain these files.

## Previewing a chapter map

```
python3 tools/scripts/tileset.py map data/mapassets/MapTsa_Ch1.tsa data/mapassets/MapAsset01_Metatiles.png ch1.png
```

This writes the chapter map as a PNG using the metatile image, so it shows your
edits before a build. Find the map and tileset for a chapter in
`src/chapterinfo_data.c`: `asset_map` names the map and `asset_tileset` names
the TsaConf, and `MapAssetXX_TsaConf` goes with `MapAssetXX_Metatiles.png`.

Chapters on an alternate palette, such as 21x on `MapAsset04d_Pal`, need the
palette passed as a fourth argument, since the metatile PNG carries only the
tileset's base palette:

```
python3 tools/scripts/tileset.py map data/mapassets/MapTsa_Ch21x.tsa data/mapassets/MapAsset04_Metatiles.png ch21x.png data/mapassets/MapAsset04d_Pal.pal
```

Map changes, such as a village being visited or a door opening, are not in the
map file. They are rectangles of replacement metatiles in
`src/chapterinfo/map_changes.c`, applied by `ApplyMapChange` in `src/trap.c`.

## Build

`tools/scripts/tileset.py` does all conversions:

- `sheet` converts a sheet PNG to 4bpp, masking each pixel to its low four bits
- `build` makes `MapAssetXX_TsaConf.tsa` from the metatile image, terrain,
  hints, and the built sheets
- `extract` goes the other way, from a TsaConf to the three sources, and is
  how the current sources were made
- `map` renders a chapter map for preview

The Makefile rules are under "Map assets". The generated `_TsaConf.tsa` files
and their `.lz` forms are build output and are ignored by git.
