.include "macro.inc"
.include "animscr.inc"
.include "gba_sprites.inc"

.section .data.oamr
@ BANIM_OAMR_bram_sw1_4:
OAMR:
OAMR_0:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x001C, 0, -19
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0032, 0, -18
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0034, -8, -10
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0054, 0, -2
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0080, -16, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0000, -4, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0020, -13, -16
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0022, 3, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0060, -13, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0062, 3, 0
    ANIM_SPRITE_END
OAMR_1:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0017, -13, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0036, -18, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0076, -10, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0096, -18, 8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x009E, 14, -16
    ANIM_SPRITE_END
OAMR_2:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00F6, -6, -20
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00B6, -13, 4
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0096, -18, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00D8, -17, -12
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00DC, 15, -12
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x007B, 19, -4
    ANIM_SPRITE_END
OAMR_3:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00F6, -6, -20
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0096, -18, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D8, -17, -12
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00B6, -13, 4
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D6, 3, 4
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00DD, 3, -5
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, 0x2000, 0x00BB, 19, -1
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x009C, -1, -12
    ANIM_SPRITE_END
OAMR_4:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00F6, -6, -20
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0096, -18, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D8, -17, -12
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00B6, -13, 4
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D6, 3, 4
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x009C, -1, -12
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, 0x6000, 0x00DD, 10, -19
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BB, 2, -14
    ANIM_SPRITE_END
    ANIM_SPRITE_AFFIN 1, 0xFFAD, 0xFF0F, 0x00F1, 0xFFAD
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00F6, -6, -20
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0096, -18, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D8, -17, -12
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00B6, -13, 4
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D6, 3, 4
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FF, 16, -17
    ANIM_SPRITE ATTR0_SQUARE + OBJ_ROT_SCALE_ON, ATTR1_SIZE_16, 0x00DD, 14, -10
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x009C, -1, -12
    ANIM_SPRITE_END
OAMR_5:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00B1, 5, -15
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00F1, 5, 1
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0052, -3, -14
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0051, -5, -25
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0093, -13, -17
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0095, 3, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F6, -21, -9
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0092, 11, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0011, 7, 9
    ANIM_SPRITE_END
OAMR_6:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00B0, 15, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F0, 15, 0
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00CF, 7, -14
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0051, -5, -25
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0095, 3, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0092, 11, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EE, -13, -1
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0094, -5, -17
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F3, -13, 7
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0093, -13, -17
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AE, -21, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0011, 7, 9
    ANIM_SPRITE_END
OAMR_7:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00B0, 14, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F0, 14, 0
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00CF, 6, -14
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0051, -5, -25
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0095, 3, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0092, 11, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EE, -13, -1
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0094, -5, -17
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F3, -13, 7
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0093, -13, -17
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AE, -20, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0011, 7, 9
    ANIM_SPRITE_END
OAMR_8:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00F6, -6, -20
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0096, -18, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D8, -17, -12
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00B6, -13, 4
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D6, 3, 4
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x009D, -1, -12
    ANIM_SPRITE_END
OAMR_9:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00EF, -8, 13
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0070, -12, -19
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0074, 20, -19
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00CF, 28, -2
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00AF, 24, 13
    ANIM_SPRITE_END
OAMR_10:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00F3, -2, 14
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00B5, -1, -2
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0075, -2, -18
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0077, 14, -18
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0098, 22, -10
    ANIM_SPRITE_END
OAMR_11:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, 0, -8
    ANIM_SPRITE_END
OAMR_12:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, 0, -8
    ANIM_SPRITE_END
OAMR_13:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, 0, -8
    ANIM_SPRITE_END
OAMR_14:
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

.section .data.oaml
@ BANIM_OAML_bram_sw1_4:
OAML:
OAML_0:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x001C, -16, -19
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0032, -16, -18
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0034, 0, -10
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0054, -8, -2
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0080, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0000, -12, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0020, -3, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0022, -11, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0060, -3, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0062, -11, 0
    ANIM_SPRITE_END
OAML_1:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0017, -19, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0036, -14, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0076, -22, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0096, -14, 8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x009E, -22, -16
    ANIM_SPRITE_END
OAML_2:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00F6, -10, -20
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00B6, -19, 4
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0096, -14, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00D8, -15, -12
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00DC, -23, -12
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x007B, -27, -4
    ANIM_SPRITE_END
OAML_3:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00F6, -10, -20
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0096, -14, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D8, 1, -12
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00B6, -3, 4
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D6, -11, 4
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00DD, -19, -5
    ANIM_SPRITE ATTR0_SQUARE, 0x2000, 0x00BB, -27, -1
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x009C, -15, -12
    ANIM_SPRITE_END
OAML_4:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00F6, -10, -20
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0096, -14, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D8, 1, -12
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00B6, -3, 4
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D6, -11, 4
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x009C, -15, -12
    ANIM_SPRITE ATTR0_SQUARE, 0x6000, 0x00DD, -26, -19
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BB, -10, -14
    ANIM_SPRITE_END
    ANIM_SPRITE_AFFIN 1, 0x0053, 0xFF0F, 0xFF0F, 0xFFAD
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00F6, -10, -20
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0096, -14, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D8, 1, -12
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00B6, -3, 4
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D6, -11, 4
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FF, -24, -17
    ANIM_SPRITE ATTR0_SQUARE + OBJ_ROT_SCALE_ON, ATTR1_SIZE_16, 0x00DD, -30, -10
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x009C, -15, -12
    ANIM_SPRITE_END
OAML_5:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00B1, -21, -15
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00F1, -21, 1
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0052, -5, -14
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0051, -3, -25
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0093, -3, -17
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0095, -11, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F6, 13, -9
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0092, -19, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0011, -15, 9
    ANIM_SPRITE_END
OAML_6:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00B0, -23, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F0, -23, 0
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00CF, -15, -14
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0051, -3, -25
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0095, -11, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0092, -19, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EE, 5, -1
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0094, -3, -17
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F3, 5, 7
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0093, 5, -17
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00AE, 5, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0011, -15, 9
    ANIM_SPRITE_END
OAML_7:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00B0, -22, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F0, -22, 0
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00CF, -14, -14
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0051, -3, -25
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0095, -11, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0092, -19, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EE, 5, -1
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0094, -3, -17
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F3, 5, 7
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0093, 5, -17
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00AE, 4, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0011, -15, 9
    ANIM_SPRITE_END
OAML_8:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00F6, -10, -20
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0096, -14, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D8, 1, -12
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00B6, -3, 4
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D6, -11, 4
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x009D, -15, -12
    ANIM_SPRITE_END
OAML_9:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00EF, -24, 13
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0070, -20, -19
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0074, -28, -19
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00CF, -36, -2
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00AF, -32, 13
    ANIM_SPRITE_END
OAML_10:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00F3, -30, 14
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00B5, -31, -2
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0075, -14, -18
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0077, -22, -18
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0098, -30, -10
    ANIM_SPRITE_END
OAML_11:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, -8, -8
    ANIM_SPRITE_END
OAML_12:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, -8, -8
    ANIM_SPRITE_END
OAML_13:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, -8, -8
    ANIM_SPRITE_END
OAML_14:
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

.section .data.script
@ BANIM_SCR_bram_sw1_4:
SCR:
SCR_NORMAL_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_3, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x0D, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x22
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x06, OAMR_5 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x07, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_2, 0x08, OAMR_7 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_2, 0x06, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_NORMAL_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_0, 0x0C, OAMR_11 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_3, 0x0F, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x0D, BANIM_IMG_bram_sw1_3, 0x0F, OAMR_14 - OAMR
    ANIMSCR_CMD 0x22
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x0E, OAMR_13 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x0E, OAMR_13 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_2, 0x0E, OAMR_13 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_2, 0x0E, OAMR_13 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x0F, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x0F, OAMR_14 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_3, 0x0F, OAMR_14 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_3, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x38
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x05, BANIM_IMG_bram_sw1_3, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_3, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x04, BANIM_IMG_bram_sw1_3, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x05, 0x01F8
    ANIMSCR_FRAME 0x0A, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x22
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x06, OAMR_5 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x07, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x1F, BANIM_IMG_bram_sw1_2, 0x08, OAMR_7 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_2, 0x06, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_0, 0x0C, OAMR_11 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_0, 0x1F, 0x0618
    ANIMSCR_CMD 0x38
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_0, 0x1F, 0x0618
    ANIMSCR_FRAME 0x05, BANIM_IMG_bram_sw1_0, 0x1F, 0x0618
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_0, 0x1F, 0x0618
    ANIMSCR_FRAME 0x04, BANIM_IMG_bram_sw1_3, 0x0F, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x0F, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x0F, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x0A, BANIM_IMG_bram_sw1_3, 0x0F, OAMR_14 - OAMR
    ANIMSCR_CMD 0x22
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x0E, OAMR_13 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x0E, OAMR_13 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_2, 0x0E, OAMR_13 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_2, 0x0E, OAMR_13 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x0F, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x0F, OAMR_14 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_3, 0x0F, OAMR_14 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_3, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x0D, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x22
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x06, OAMR_5 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x07, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_2, 0x08, OAMR_7 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_2, 0x06, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_CRIT_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_3, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x38
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x05, BANIM_IMG_bram_sw1_3, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_3, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x04, BANIM_IMG_bram_sw1_3, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x05, 0x01F8
    ANIMSCR_FRAME 0x0A, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x22
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x06, OAMR_5 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x07, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x1F, BANIM_IMG_bram_sw1_2, 0x08, OAMR_7 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_2, 0x06, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CLOSE_DODGE:
    ANIMSCR_CMD 0x18
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_1, 0x0A, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_1, 0x0B, OAMR_10 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_1, 0x0A, OAMR_9 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_DODGE:
    ANIMSCR_CMD 0x18
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_1, 0x0A, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_1, 0x0B, OAMR_10 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_1, 0x0A, OAMR_9 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_STANDING:
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_STANDING2:
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_RANGED_STANDING:
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_MISSED_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_3, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x0D, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x22
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x06, OAMR_5 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x03, BANIM_IMG_bram_sw1_2, 0x07, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_2, 0x08, OAMR_7 - OAMR
    ANIMSCR_CMD 0x23
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_2, 0x06, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_bram_sw1_3, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, BANIM_IMG_bram_sw1_3, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED


.section .data.modes
@ BANIM_MODES_bram_sw1_4:
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
