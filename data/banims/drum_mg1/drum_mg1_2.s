.include "macro.inc"
.include "animscr.inc"
.include "gba_sprites.inc"

.section .data.oamr
.global BANIM_OAMR_drum_mg1_2
BANIM_OAMR_drum_mg1_2:
OAMR:
OAMR_0:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009F, -19, -21
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0000, -16, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0004, 16, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0080, -16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0084, 16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FE, -19, 11
    ANIM_SPRITE_END
OAMR_1:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009F, -19, -21
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FE, -19, 11
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0005, -16, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0009, 16, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0085, -16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0089, 16, 8
    ANIM_SPRITE_END
OAMR_2:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009F, -19, -21
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x000A, -16, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x000E, 16, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x008A, -16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x008E, 16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FE, -19, 11
    ANIM_SPRITE_END
OAMR_3:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009F, -19, -21
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FE, -19, 11
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x000F, -16, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0013, 16, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x008F, -16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0093, 16, 8
    ANIM_SPRITE_END
OAMR_4:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009F, -19, -23
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0014, -16, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0018, 16, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0094, -16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0098, 16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FD, -19, 11
    ANIM_SPRITE_END
OAMR_5:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009F, -19, -26
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0019, -16, -40
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x001D, 16, -40
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0099, -16, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x009D, 16, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00D9, -16, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00DD, 16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FC, -19, 11
    ANIM_SPRITE_END
OAMR_6:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009F, -19, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FC, -19, 11
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00A0, -16, -16
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00A4, 16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00E0, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E4, 16, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00AC, -8, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0019, -16, -40
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x001D, 16, -40
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0059, -16, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x005D, 16, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E5, 24, 0
    ANIM_SPRITE_END
OAMR_7:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009F, -19, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FC, -19, 11
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00A6, -16, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00AA, 16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00E6, -16, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00EA, 16, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00CC, -8, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0019, -16, -40
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x001D, 16, -40
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0059, -16, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x005D, 16, -24
    ANIM_SPRITE_END
OAMR_8:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009F, -19, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FC, -19, 11
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00B0, -16, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00B4, 16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00F0, -16, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00F4, 16, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00EC, -8, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0019, -16, -40
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x001D, 16, -40
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0059, -16, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x005D, 16, -24
    ANIM_SPRITE_END
OAMR_9:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, -18, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, -18, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0000, -16, -32
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0004, 16, -32
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0080, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0084, 16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BD, -18, 11
    ANIM_SPRITE_END
OAMR_10:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, -15, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, -15, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0006, -16, -32
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x000A, 16, -32
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0086, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x008A, 16, 0
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000C, 32, -32
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x004C, 32, -16
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x006C, 40, -32
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00AC, 40, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BD, -15, 11
    ANIM_SPRITE_END
OAMR_11:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x000D, -8, -32
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0011, 24, -32
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x008D, -8, 0
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0091, 24, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0012, 32, -32
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0052, 32, -16
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0092, -16, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0072, 32, -8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, -18, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, -18, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BD, -18, 11
    ANIM_SPRITE_END
OAMR_12:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0014, -16, -32
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0018, 16, -32
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0094, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0098, 16, 0
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, -25, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, -25, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BD, -25, 11
    ANIM_SPRITE_END
OAMR_13:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, -24, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, -24, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x001A, -24, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x001E, 8, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x009A, -24, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x009E, 8, 8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BF, 24, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BD, -24, 11
    ANIM_SPRITE_END
OAMR_14:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, -22, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, -22, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00C0, -24, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00C4, 8, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E5, 16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00C5, -24, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C9, 8, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00E6, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EA, 16, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00EB, -16, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00EF, 16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BD, -22, 11
    ANIM_SPRITE_END
OAMR_15:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BE, -21, 11
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, -21, -23
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, -21, -7
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00D1, -16, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00D5, 16, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00D6, -16, -8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00DA, 16, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00FB, -16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FF, 16, 8
    ANIM_SPRITE_END
OAMR_16:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0076, -20, -22
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F6, -20, 12
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0000, -16, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0004, 16, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0080, -16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0084, 16, 8
    ANIM_SPRITE_END
OAMR_17:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0076, -18, -21
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F6, -18, 11
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0005, -16, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0009, 16, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0085, -16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0089, 16, 8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x000A, 24, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x008A, 24, 8
    ANIM_SPRITE_END
OAMR_18:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0076, -16, -21
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F6, -16, 11
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x000B, -10, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x000F, 22, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x008B, -10, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x008F, 22, 8
    ANIM_SPRITE_END

.section .data.oaml
.global BANIM_OAML_drum_mg1_2
BANIM_OAML_drum_mg1_2:
OAML:
OAML_0:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x009F, 11, -21
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0000, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0004, -24, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0080, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0084, -24, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FE, 11, 11
    ANIM_SPRITE_END
OAML_1:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x009F, 11, -21
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FE, 11, 11
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0005, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0009, -24, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0085, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0089, -24, 8
    ANIM_SPRITE_END
OAML_2:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x009F, 11, -21
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x000A, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x000E, -24, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x008A, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x008E, -24, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FE, 11, 11
    ANIM_SPRITE_END
OAML_3:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x009F, 11, -21
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FE, 11, 11
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x000F, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0013, -24, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x008F, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0093, -24, 8
    ANIM_SPRITE_END
OAML_4:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x009F, 11, -23
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0014, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0018, -24, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0094, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0098, -24, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FD, 11, 11
    ANIM_SPRITE_END
OAML_5:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x009F, 11, -26
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0019, -16, -40
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x001D, -32, -40
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0099, -16, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x009D, -32, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00D9, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00DD, -32, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FC, 11, 11
    ANIM_SPRITE_END
OAML_6:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x009F, 11, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FC, 11, 11
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00A0, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00A4, -24, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00E0, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E4, -24, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00AC, -24, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0019, -16, -40
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x001D, -32, -40
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0059, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x005D, -32, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E5, -32, 0
    ANIM_SPRITE_END
OAML_7:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x009F, 11, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FC, 11, 11
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00A6, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00AA, -32, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00E6, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00EA, -32, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00CC, -24, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0019, -16, -40
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x001D, -32, -40
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0059, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x005D, -32, -24
    ANIM_SPRITE_END
OAML_8:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x009F, 11, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FC, 11, 11
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00B0, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00B4, -32, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00F0, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00F4, -32, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00EC, -24, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0019, -16, -40
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x001D, -32, -40
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0059, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x005D, -32, -24
    ANIM_SPRITE_END
OAML_9:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, 10, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, 10, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0000, -16, -32
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0004, -32, -32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0080, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0084, -32, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BD, 10, 11
    ANIM_SPRITE_END
OAML_10:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, 7, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, 7, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0006, -16, -32
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x000A, -32, -32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0086, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x008A, -32, 0
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x000C, -40, -32
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x004C, -40, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x006C, -48, -32
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00AC, -48, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BD, 7, 11
    ANIM_SPRITE_END
OAML_11:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x000D, -24, -32
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0011, -32, -32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x008D, -24, 0
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0091, -32, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0012, -48, -32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0052, -48, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0092, 8, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0072, -40, -8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, 10, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, 10, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BD, 10, 11
    ANIM_SPRITE_END
OAML_12:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0014, -16, -32
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0018, -32, -32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0094, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0098, -32, 0
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, 17, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, 17, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BD, 17, 11
    ANIM_SPRITE_END
OAML_13:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, 16, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, 16, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x001A, -8, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x001E, -24, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x009A, -8, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x009E, -24, 8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BF, -32, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BD, 16, 11
    ANIM_SPRITE_END
OAML_14:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, 14, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, 14, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00C0, -8, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00C4, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E5, -24, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00C5, -8, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C9, -24, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00E6, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EA, -24, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00EB, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00EF, -32, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BD, 14, 11
    ANIM_SPRITE_END
OAML_15:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00BE, 13, 11
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BB, 13, -23
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00BC, 13, -7
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00D1, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00D5, -24, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00D6, -16, -8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00DA, -24, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00FB, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00FF, -24, 8
    ANIM_SPRITE_END
OAML_16:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0076, 12, -22
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F6, 12, 12
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0000, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0004, -24, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0080, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0084, -24, 8
    ANIM_SPRITE_END
OAML_17:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0076, 10, -21
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F6, 10, 11
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0005, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0009, -24, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0085, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0089, -24, 8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x000A, -32, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x008A, -32, 8
    ANIM_SPRITE_END
OAML_18:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0076, 8, -21
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F6, 8, 11
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x000B, -22, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x000F, -30, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x008B, -22, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x008F, -30, 8
    ANIM_SPRITE_END

.section .data.script
.global BANIM_SCR_drum_mg1_2
BANIM_SCR_drum_mg1_2:
SCR:
SCR_NORMAL_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_0_start, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_0_start, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x0C, _data_BANIM_IMG_drum_mg1_0_start, 0x08, OAMR_8 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x07, _data_BANIM_IMG_drum_mg1_1_start, 0x0A, OAMR_10 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0C, OAMR_12 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_1_start, 0x0D, OAMR_13 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_1_start, 0x0E, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_FRAME 0x04, BANIM_IMG_drum_mg1_2, 0x10, OAMR_16 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_NORMAL_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_0_start, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_0_start, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x0C, _data_BANIM_IMG_drum_mg1_0_start, 0x08, OAMR_8 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x07, _data_BANIM_IMG_drum_mg1_1_start, 0x0A, OAMR_10 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0C, OAMR_12 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_1_start, 0x0D, OAMR_13 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_1_start, 0x0E, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_FRAME 0x04, BANIM_IMG_drum_mg1_2, 0x10, OAMR_16 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_0_start, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_0_start, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x0C, _data_BANIM_IMG_drum_mg1_0_start, 0x08, OAMR_8 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x07, _data_BANIM_IMG_drum_mg1_1_start, 0x0A, OAMR_10 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0C, OAMR_12 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_1_start, 0x0D, OAMR_13 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_1_start, 0x0E, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_FRAME 0x04, BANIM_IMG_drum_mg1_2, 0x10, OAMR_16 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_0_start, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_0_start, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x0C, _data_BANIM_IMG_drum_mg1_0_start, 0x08, OAMR_8 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x07, _data_BANIM_IMG_drum_mg1_1_start, 0x0A, OAMR_10 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0C, OAMR_12 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_1_start, 0x0D, OAMR_13 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_1_start, 0x0E, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_FRAME 0x04, BANIM_IMG_drum_mg1_2, 0x10, OAMR_16 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_0_start, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_0_start, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x0C, _data_BANIM_IMG_drum_mg1_0_start, 0x08, OAMR_8 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x07, _data_BANIM_IMG_drum_mg1_1_start, 0x0A, OAMR_10 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0C, OAMR_12 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_1_start, 0x0D, OAMR_13 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_1_start, 0x0E, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_FRAME 0x04, BANIM_IMG_drum_mg1_2, 0x10, OAMR_16 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_CRIT_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_0_start, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_0_start, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x0C, _data_BANIM_IMG_drum_mg1_0_start, 0x08, OAMR_8 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x07, _data_BANIM_IMG_drum_mg1_1_start, 0x0A, OAMR_10 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0C, OAMR_12 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_1_start, 0x0D, OAMR_13 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_1_start, 0x0E, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_FRAME 0x04, BANIM_IMG_drum_mg1_2, 0x10, OAMR_16 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CLOSE_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_0_start, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, BANIM_IMG_drum_mg1_2, 0x11, OAMR_17 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_drum_mg1_2, 0x12, OAMR_18 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, BANIM_IMG_drum_mg1_2, 0x11, OAMR_17 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_0_start, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, BANIM_IMG_drum_mg1_2, 0x11, OAMR_17 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_drum_mg1_2, 0x12, OAMR_18 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, BANIM_IMG_drum_mg1_2, 0x11, OAMR_17 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_STANDING:
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_0_start, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_STANDING2:
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_0_start, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_RANGED_STANDING:
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_0_start, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_MISSED_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_0_start, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_0_start, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_0_start, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x0C, _data_BANIM_IMG_drum_mg1_0_start, 0x08, OAMR_8 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x07, _data_BANIM_IMG_drum_mg1_1_start, 0x0A, OAMR_10 - OAMR
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_drum_mg1_1_start, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0C, OAMR_12 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_drum_mg1_1_start, 0x0D, OAMR_13 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_IMG_drum_mg1_1_start, 0x0E, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x02, _data_BANIM_IMG_drum_mg1_1_start, 0x0F, OAMR_15 - OAMR
    ANIMSCR_FRAME 0x04, BANIM_IMG_drum_mg1_2, 0x10, OAMR_16 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED


.section .data.modes
.global BANIM_MODES_drum_mg1_2
BANIM_MODES_drum_mg1_2:
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
