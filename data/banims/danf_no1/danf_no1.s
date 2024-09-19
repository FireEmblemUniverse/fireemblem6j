.include "macro.inc"
.include "animscr.inc"
.include "gba_sprites.inc"

.section .data.oamr
OAMR:
OAMR_0:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0000, -17, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0001, -9, -32
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0081, -9, 0
    ANIM_SPRITE_END
OAMR_1:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0006, -9, -31
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0008, 7, -31
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0086, -9, 1
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0088, 7, 1
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0005, -17, -22
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0080, 15, -26
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0085, 15, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A5, 15, -10
    ANIM_SPRITE_END
OAMR_2:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0009, -18, -18
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0049, -18, -2
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000D, 14, -18
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0069, -10, 6
    ANIM_SPRITE_END
OAMR_3:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x006B, -22, -18
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AC, -14, -2
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00AE, 2, -2
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0089, -14, 6
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A9, -30, -11
    ANIM_SPRITE_END
OAMR_4:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x000E, -27, -18
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0012, 5, -18
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x004F, -19, -2
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x004D, -11, 6
    ANIM_SPRITE_END
OAMR_5:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x006F, -16, -26
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00CE, 16, -26
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F2, 16, -10
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AA, -15, -34
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00EF, -15, 6
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F1, 1, 6
    ANIM_SPRITE_END
OAMR_6:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0013, -21, -26
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0093, -13, 6
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0095, 11, -9
    ANIM_SPRITE_END
OAMR_7:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00B3, -23, -26
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00F3, -23, -10
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0096, 9, -10
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0017, -8, -2
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0019, 8, -2
    ANIM_SPRITE_END
OAMR_8:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0057, -15, -26
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0039, -23, -9
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00D7, -8, 6
    ANIM_SPRITE_END
OAMR_9:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x001B, -8, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x001D, 8, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x001A, -16, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001E, -24, -2
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00D9, -10, 8
    ANIM_SPRITE_END
OAMR_10:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x009B, -14, -41
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00F7, -14, 7
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x003E, 3, -1
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x005E, 10, -9
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BF, 18, -33
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FF, 18, -17
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x007E, -14, -9
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x009F, -6, -1
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00EC, -11, 8
    ANIM_SPRITE_END
OAMR_11:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, -13, -54
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0004, 19, -54
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0040, -13, -38
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0044, 19, -38
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0062, 11, -30
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0060, -13, -30
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00A0, -5, -14
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C0, -3, -6
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -11, 8
    ANIM_SPRITE_END
OAMR_12:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0005, -5, -61
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0045, -5, -45
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0064, -13, -37
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00A4, -13, -21
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00C4, -13, -53
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0066, 19, -45
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A6, 19, -29
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -11, 8
    ANIM_SPRITE_END
OAMR_13:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0047, -23, -48
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0009, -23, -64
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E5, 9, -64
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C5, -7, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -11, 8
    ANIM_SPRITE_END
OAMR_14:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x004B, -35, -52
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00C6, -16, -52
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00CA, -15, -36
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00CC, 1, -36
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00E0, -32, -20
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -11, 8
    ANIM_SPRITE_END
OAMR_15:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x000D, -17, -49
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x008D, -17, -17
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x008F, -1, -17
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00AD, -33, -25
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00ED, -17, -57
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EF, -1, -57
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -11, 8
    ANIM_SPRITE_END
OAMR_16:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00CF, 10, -18
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B0, 18, -26
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0091, 26, -34
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D1, 26, -18
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00AF, 34, -42
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0014, 10, -58
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0013, 2, -55
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F0, -6, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0090, 2, -18
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -11, 8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0012, -6, -56
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0031, -14, -48
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0071, -14, -32
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0053, -14, -56
    ANIM_SPRITE_END
OAMR_17:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0053, -14, -55
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D2, -6, -23
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00F1, 10, -23
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -11, 8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0078, 26, -47
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B8, 26, -31
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0057, 18, -55
    ANIM_SPRITE_END
OAMR_18:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0019, 10, -44
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x001B, 26, -44
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0059, 10, -28
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x005B, 26, -28
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0018, 19, -20
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0079, 2, -52
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B9, 2, -36
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0053, -14, -52
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D2, -6, -20
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -11, 8
    ANIM_SPRITE_END
OAMR_19:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0019, 10, -30
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x001B, 26, -30
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0059, 10, -14
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x005B, 26, -14
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0018, 19, -6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0079, 2, -38
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B9, 2, -22
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0053, -14, -38
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D2, -6, -6
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -11, 8
    ANIM_SPRITE_END
OAMR_20:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00D3, -19, -25
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00D7, -19, -9
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00F7, -11, -1
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F9, -9, 7
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -11, 8
    ANIM_SPRITE_END
OAMR_21:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x003C, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x001C, -16, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001E, 0, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x007A, -24, -23
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BA, -24, 0
    ANIM_SPRITE_END
OAMR_22:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0000, -22, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0001, -14, -32
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0081, -14, 0
    ANIM_SPRITE_END
OAMR_23:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00C0, -17, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00C4, 15, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00C5, -17, -8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00C9, 15, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00CA, -9, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00EA, -1, -32
    ANIM_SPRITE_END
OAMR_24:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00BD, 0, -8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BF, 16, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00FD, 0, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FF, 16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00BB, -16, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00FB, 8, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FA, 8, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x007B, -16, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0038, -8, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0011, 0, -24
    ANIM_SPRITE_END
OAMR_25:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, 0, -8
    ANIM_SPRITE_END
OAMR_26:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, 0, -8
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END

.section .data.oaml
OAML:
OAML_0:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0000, 9, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0001, -23, -32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0081, -23, 0
    ANIM_SPRITE_END
OAML_1:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0006, -7, -31
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0008, -15, -31
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0086, -7, 1
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0088, -15, 1
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0005, 9, -22
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0080, -23, -26
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0085, -23, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A5, -23, -10
    ANIM_SPRITE_END
OAML_2:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0009, -14, -18
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0049, -14, -2
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x000D, -22, -18
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0069, -6, 6
    ANIM_SPRITE_END
OAML_3:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x006B, -10, -18
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00AC, -2, -2
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00AE, -10, -2
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0089, -2, 6
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A9, 22, -11
    ANIM_SPRITE_END
OAML_4:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x000E, -5, -18
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0012, -13, -18
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x004F, -13, -2
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x004D, -5, 6
    ANIM_SPRITE_END
OAML_5:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x006F, -16, -26
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00CE, -24, -26
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F2, -24, -10
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00AA, -1, -34
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00EF, -1, 6
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F1, -9, 6
    ANIM_SPRITE_END
OAML_6:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0013, -11, -26
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0093, -3, 6
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0095, -19, -9
    ANIM_SPRITE_END
OAML_7:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00B3, -9, -26
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00F3, -9, -10
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0096, -17, -10
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0017, -8, -2
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0019, -16, -2
    ANIM_SPRITE_END
OAML_8:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0057, -17, -26
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0039, 15, -9
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00D7, -8, 6
    ANIM_SPRITE_END
OAML_9:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x001B, -8, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x001D, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x001A, 8, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001E, 16, -2
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00D9, -6, 8
    ANIM_SPRITE_END
OAML_10:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x009B, -18, -41
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00F7, -18, 7
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x003E, -19, -1
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x005E, -26, -9
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BF, -26, -33
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FF, -26, -17
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x007E, -2, -9
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x009F, -2, -1
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00EC, -5, 8
    ANIM_SPRITE_END
OAML_11:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, -19, -54
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0004, -27, -54
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0040, -19, -38
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0044, -27, -38
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0062, -27, -30
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0060, -3, -30
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00A0, -27, -14
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C0, -13, -6
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -5, 8
    ANIM_SPRITE_END
OAML_12:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0005, -27, -61
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0045, -11, -45
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0064, -3, -37
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00A4, -3, -21
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00C4, 5, -53
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0066, -27, -45
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A6, -27, -29
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -5, 8
    ANIM_SPRITE_END
OAML_13:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0047, -9, -48
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0009, -9, -64
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E5, -17, -64
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C5, -1, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -5, 8
    ANIM_SPRITE_END
OAML_14:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x004B, 19, -52
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00C6, -16, -52
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00CA, -1, -36
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00CC, -9, -36
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00E0, 0, -20
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -5, 8
    ANIM_SPRITE_END
OAML_15:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x000D, -15, -49
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x008D, 1, -17
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x008F, -7, -17
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00AD, 17, -25
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00ED, 1, -57
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EF, -7, -57
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -5, 8
    ANIM_SPRITE_END
OAML_16:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00CF, -26, -18
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B0, -26, -26
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0091, -42, -34
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D1, -34, -18
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00AF, -42, -42
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0014, -42, -58
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0013, -10, -55
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F0, -2, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0090, -10, -18
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -5, 8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0012, -2, -56
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0031, 6, -48
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0071, 6, -32
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0053, 6, -56
    ANIM_SPRITE_END
OAML_17:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0053, -18, -55
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D2, -2, -23
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00F1, -26, -23
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -5, 8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0078, -34, -47
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B8, -34, -31
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0057, -26, -55
    ANIM_SPRITE_END
OAML_18:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0019, -26, -44
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x001B, -34, -44
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0059, -26, -28
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x005B, -34, -28
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0018, -27, -20
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0079, -10, -52
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B9, -10, -36
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0053, -2, -52
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D2, -2, -20
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -5, 8
    ANIM_SPRITE_END
OAML_19:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0019, -26, -30
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x001B, -34, -30
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0059, -26, -14
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x005B, -34, -14
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0018, -27, -6
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0079, -10, -38
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B9, -10, -22
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0053, -2, -38
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D2, -2, -6
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -5, 8
    ANIM_SPRITE_END
OAML_20:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00D3, -13, -25
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00D7, -13, -9
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00F7, -5, -1
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F9, 1, 7
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C2, -5, 8
    ANIM_SPRITE_END
OAML_21:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x003C, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x001C, 0, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001E, -8, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x007A, 16, -23
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BA, 16, 0
    ANIM_SPRITE_END
OAML_22:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0000, 14, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0001, -18, -32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0081, -18, 0
    ANIM_SPRITE_END
OAML_23:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00C0, -15, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00C4, -23, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00C5, -15, -8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00C9, -23, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00CA, -23, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00EA, -15, -32
    ANIM_SPRITE_END
OAML_24:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00BD, -16, -8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BF, -24, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00FD, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FF, -24, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00BB, 0, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00FB, -24, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FA, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x007B, 8, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0038, 0, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0011, -8, -24
    ANIM_SPRITE_END
OAML_25:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, -8, -8
    ANIM_SPRITE_END
OAML_26:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, -8, -8
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END

.section .data.script
SCR:
SCR_NORMAL_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086F1AE4, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x0C, 0x086F1AE4, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F1AE4, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x46
    ANIMSCR_FRAME 0x06, 0x086F1AE4, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F1AE4, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F1AE4, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F1AE4, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x08, OAMR_8 - OAMR
    ANIMSCR_FRAME 0x0A, 0x086F1AE4, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F1AE4, 0x0A, OAMR_10 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x0C, OAMR_12 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x0D, OAMR_13 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x0E, OAMR_14 - OAMR
    ANIMSCR_CMD 0x45
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x0F, OAMR_15 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, 0x086F2C28, 0x10, OAMR_16 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x11, OAMR_17 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F2C28, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F2C28, 0x14, OAMR_20 - OAMR
    ANIMSCR_FRAME 0x0A, 0x086F2C28, 0x15, OAMR_21 - OAMR
    ANIMSCR_FRAME 0x28, 0x086F1AE4, 0x16, OAMR_22 - OAMR
    ANIMSCR_BLOCKED

SCR_NORMAL_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x0C, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_CMD 0x46
    ANIMSCR_FRAME 0x06, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x0A, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_CMD 0x45
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x0A, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x28, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_BLOCKED

SCR_CRIT_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086F1AE4, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x0C, 0x086F1AE4, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F1AE4, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x46
    ANIMSCR_FRAME 0x06, 0x086F1AE4, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F1AE4, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F1AE4, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F1AE4, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x08, OAMR_8 - OAMR
    ANIMSCR_FRAME 0x0A, 0x086F1AE4, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F1AE4, 0x0A, OAMR_10 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x0C, OAMR_12 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x0D, OAMR_13 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x0E, OAMR_14 - OAMR
    ANIMSCR_CMD 0x45
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x0F, OAMR_15 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, 0x086F2C28, 0x10, OAMR_16 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x11, OAMR_17 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F2C28, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F2C28, 0x14, OAMR_20 - OAMR
    ANIMSCR_FRAME 0x0A, 0x086F2C28, 0x15, OAMR_21 - OAMR
    ANIMSCR_FRAME 0x28, 0x086F1AE4, 0x16, OAMR_22 - OAMR
    ANIMSCR_BLOCKED

SCR_CRIT_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x0C, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_CMD 0x46
    ANIMSCR_FRAME 0x06, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x0A, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F1AE4, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_CMD 0x45
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x0A, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_FRAME 0x28, 0x086F2C28, 0x1A, OAMR_26 - OAMR
    ANIMSCR_BLOCKED

SCR_RANGED_ATK:
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x00, OAMR_0 - OAMR
    ANIMSCR_BLOCKED

SCR_RANGED_CRIT_ATK:
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x00, OAMR_0 - OAMR
    ANIMSCR_BLOCKED

SCR_CLOSE_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x086F1AE4, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x086F1AE4, 0x17, OAMR_23 - OAMR
    ANIMSCR_FRAME 0x01, 0x086F2C28, 0x18, OAMR_24 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x086F1AE4, 0x17, OAMR_23 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x086F1AE4, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x086F1AE4, 0x17, OAMR_23 - OAMR
    ANIMSCR_FRAME 0x01, 0x086F2C28, 0x18, OAMR_24 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x086F1AE4, 0x17, OAMR_23 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_STANDING:
    ANIMSCR_FRAME 0x01, 0x086F1AE4, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_STANDING2:
    ANIMSCR_FRAME 0x01, 0x086F1AE4, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_RANGED_STANDING:
    ANIMSCR_FRAME 0x01, 0x086F1AE4, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_MISSED_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086F1AE4, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x0C, 0x086F1AE4, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F1AE4, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x46
    ANIMSCR_FRAME 0x06, 0x086F1AE4, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F1AE4, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F1AE4, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F1AE4, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F1AE4, 0x08, OAMR_8 - OAMR
    ANIMSCR_FRAME 0x0A, 0x086F1AE4, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F1AE4, 0x0A, OAMR_10 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x0C, OAMR_12 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x0D, OAMR_13 - OAMR
    ANIMSCR_FRAME 0x02, 0x086F2C28, 0x0E, OAMR_14 - OAMR
    ANIMSCR_CMD 0x45
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x0F, OAMR_15 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, 0x086F2C28, 0x10, OAMR_16 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x11, OAMR_17 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F2C28, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F2C28, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F2C28, 0x14, OAMR_20 - OAMR
    ANIMSCR_FRAME 0x0A, 0x086F2C28, 0x15, OAMR_21 - OAMR
    ANIMSCR_FRAME 0x28, 0x086F1AE4, 0x16, OAMR_22 - OAMR
    ANIMSCR_BLOCKED


.section .data.modes
    .word SCR_NORMAL_ATK - SCR
    .word SCR_NORMAL_ATK_PRIORITY_L - SCR
    .word SCR_CRIT_ATK - SCR
    .word SCR_CRIT_ATK_PRIORITY_L - SCR
    .word SCR_RANGED_ATK - SCR
    .word SCR_RANGED_CRIT_ATK - SCR
    .word SCR_CLOSE_DODGE - SCR
    .word SCR_RANGED_DODGE - SCR
    .word SCR_STANDING - SCR
    .word SCR_STANDING2 - SCR
    .word SCR_RANGED_STANDING - SCR
    .word SCR_MISSED_ATK - SCR
    .word 0x0
    .word 0x0
    .word 0x0
    .word 0x0
    .word 0x0
    .word 0x0
    .word 0x0
    .word 0x0
    .word 0x0
    .word 0x0
    .word 0x0
    .word 0x0
