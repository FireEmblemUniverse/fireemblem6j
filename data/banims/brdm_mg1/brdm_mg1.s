.include "macro.inc"
.include "animscr.inc"
.include "gba_sprites.inc"

.section .data.oamr
OAMR:
OAMR_0:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0020, -16, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -6, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -11, -16
    ANIM_SPRITE_END
OAMR_1:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0005, -8, -16
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0007, 8, -16
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0024, -16, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0064, -16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -6, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0004, -11, -15
    ANIM_SPRITE_END
OAMR_2:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -12, -15
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0084, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00C4, -16, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -6, -24
    ANIM_SPRITE_END
OAMR_3:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -12, -15
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -6, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0008, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0048, -16, 0
    ANIM_SPRITE_END
OAMR_4:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -12, -15
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -6, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0068, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00A8, -16, 0
    ANIM_SPRITE_END
OAMR_5:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -12, -15
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -6, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00C8, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00A0, -16, 0
    ANIM_SPRITE_END
OAMR_6:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -12, -15
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x000C, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x004C, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -6, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE_END
OAMR_7:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -11, -15
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x006C, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00AC, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -5, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE_END
OAMR_8:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -11, -15
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00CC, -16, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -5, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00C0, -16, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE_END
OAMR_9:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -5, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -11, -15
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0010, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0050, -16, 0
    ANIM_SPRITE_END
OAMR_10:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -11, -15
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -5, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0070, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00B0, -16, 0
    ANIM_SPRITE_END
OAMR_11:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -11, -15
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -5, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00D0, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00E0, -16, 0
    ANIM_SPRITE_END
OAMR_12:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -11, -15
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -5, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0014, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0054, -16, 0
    ANIM_SPRITE_END
OAMR_13:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -11, -15
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0074, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00B4, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -5, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE_END
OAMR_14:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -11, -15
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00D4, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0018, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -5, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE_END
OAMR_15:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -11, -15
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0038, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0078, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -5, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE_END
OAMR_16:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -11, -15
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -5, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, 2, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0098, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00D8, -16, 0
    ANIM_SPRITE_END
OAMR_17:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0080, -11, -15
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0040, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0081, -5, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0060, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0062, 2, 8
    ANIM_SPRITE_END
OAMR_18:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0082, -14, -14
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0040, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0081, -5, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0060, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0062, 2, 8
    ANIM_SPRITE_END
OAMR_19:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00A0, -15, -14
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0040, -16, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0060, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0062, 2, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0081, -5, -24
    ANIM_SPRITE_END
OAMR_20:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0080, -11, -15
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0004, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0044, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0081, -6, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0060, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0062, 2, 8
    ANIM_SPRITE_END
OAMR_21:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0080, -11, -15
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00C0, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0064, -16, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0081, -6, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0060, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0062, 2, 8
    ANIM_SPRITE_END
OAMR_22:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x003C, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x007C, -16, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x009C, -16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x009E, 0, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x001C, -8, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0004, -10, -17
    ANIM_SPRITE_END
OAMR_23:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, -10, -18
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00BC, -17, -18
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00FC, -17, -2
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00F8, -17, 6
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x001C, -7, -25
    ANIM_SPRITE_END
OAMR_24:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, 0, -8
    ANIM_SPRITE_END
OAMR_25:
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
    ANIM_SPRITE_END

.section .data.oaml
OAML:
OAML_0:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0020, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -2, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 3, -16
    ANIM_SPRITE_END
OAML_1:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0005, -8, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0007, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0024, 8, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0064, 8, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -2, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0004, 3, -15
    ANIM_SPRITE_END
OAML_2:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 4, -15
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0084, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00C4, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -2, -24
    ANIM_SPRITE_END
OAML_3:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 4, -15
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -2, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0008, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0048, -16, 0
    ANIM_SPRITE_END
OAML_4:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 4, -15
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -2, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0068, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00A8, -16, 0
    ANIM_SPRITE_END
OAML_5:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 4, -15
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -2, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00C8, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00A0, -16, 0
    ANIM_SPRITE_END
OAML_6:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 4, -15
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x000C, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x004C, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -2, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_END
OAML_7:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 3, -15
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x006C, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00AC, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -3, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_END
OAML_8:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 3, -15
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00CC, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -3, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00C0, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_END
OAML_9:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -3, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 3, -15
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0010, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0050, -16, 0
    ANIM_SPRITE_END
OAML_10:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 3, -15
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -3, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0070, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00B0, -16, 0
    ANIM_SPRITE_END
OAML_11:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 3, -15
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -3, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00D0, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00E0, -16, 0
    ANIM_SPRITE_END
OAML_12:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 3, -15
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -3, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0014, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0054, -16, 0
    ANIM_SPRITE_END
OAML_13:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 3, -15
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0074, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00B4, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -3, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_END
OAML_14:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 3, -15
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00D4, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0018, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -3, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_END
OAML_15:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 3, -15
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0038, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0078, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -3, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_END
OAML_16:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 3, -15
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -3, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E4, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E6, -10, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0098, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00D8, -16, 0
    ANIM_SPRITE_END
OAML_17:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0080, 3, -15
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0040, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0081, -3, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0060, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0062, -10, 8
    ANIM_SPRITE_END
OAML_18:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0082, -2, -14
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0040, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0081, -3, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0060, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0062, -10, 8
    ANIM_SPRITE_END
OAML_19:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00A0, -1, -14
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0040, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0060, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0062, -10, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0081, -3, -24
    ANIM_SPRITE_END
OAML_20:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0080, 3, -15
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0004, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0044, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0081, -2, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0060, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0062, -10, 8
    ANIM_SPRITE_END
OAML_21:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0080, 3, -15
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00C0, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0064, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0081, -2, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0060, -2, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0062, -10, 8
    ANIM_SPRITE_END
OAML_22:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x003C, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x007C, -16, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x009C, 0, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x009E, -8, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x001C, -8, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0004, 2, -17
    ANIM_SPRITE_END
OAML_23:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0000, 2, -18
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00BC, -15, -18
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00FC, -15, -2
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00F8, -15, 6
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x001C, -9, -25
    ANIM_SPRITE_END
OAML_24:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, -8, -8
    ANIM_SPRITE_END
OAML_25:
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
    ANIM_SPRITE_END

.section .data.script
SCR:
SCR_NORMAL_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F4620, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x08, OAMR_8 - OAMR
    ANIMSCR_CMD 0x44
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x0A, OAMR_10 - OAMR
    ANIMSCR_FRAME 0x0B, 0x086F4620, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x0C, OAMR_12 - OAMR
    ANIMSCR_FRAME 0x09, 0x086F4620, 0x0D, OAMR_13 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x0E, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x0F, OAMR_15 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x10, OAMR_16 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x11, OAMR_17 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x48
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x10, 0x086F5268, 0x11, OAMR_17 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x14, OAMR_20 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x46, 0x086F5268, 0x15, OAMR_21 - OAMR
    ANIMSCR_BLOCKED

SCR_NORMAL_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_CMD 0x44
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x0B, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x09, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x48
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x10, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x46, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_BLOCKED

SCR_CRIT_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F4620, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x08, OAMR_8 - OAMR
    ANIMSCR_CMD 0x44
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x0A, OAMR_10 - OAMR
    ANIMSCR_FRAME 0x0B, 0x086F4620, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x0C, OAMR_12 - OAMR
    ANIMSCR_FRAME 0x09, 0x086F4620, 0x0D, OAMR_13 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x0E, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x0F, OAMR_15 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x10, OAMR_16 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x11, OAMR_17 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x48
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x10, 0x086F5268, 0x11, OAMR_17 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x14, OAMR_20 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x46, 0x086F5268, 0x15, OAMR_21 - OAMR
    ANIMSCR_BLOCKED

SCR_CRIT_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_CMD 0x44
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x0B, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x09, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x48
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x10, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x46, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_BLOCKED

SCR_RANGED_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_CMD 0x44
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x0B, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x09, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x48
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x10, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x46, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_BLOCKED

SCR_RANGED_CRIT_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_CMD 0x44
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x0B, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x09, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x18, OAMR_24 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x48
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x10, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x46, 0x086F5268, 0x19, OAMR_25 - OAMR
    ANIMSCR_BLOCKED

SCR_CLOSE_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x16, OAMR_22 - OAMR
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x17, OAMR_23 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x16, OAMR_22 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x16, OAMR_22 - OAMR
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x17, OAMR_23 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x16, OAMR_22 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_STANDING:
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_STANDING2:
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_RANGED_STANDING:
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_MISSED_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086F4620, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x04, 0x086F4620, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F4620, 0x08, OAMR_8 - OAMR
    ANIMSCR_CMD 0x44
    ANIMSCR_FRAME 0x03, 0x086F4620, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x0A, OAMR_10 - OAMR
    ANIMSCR_FRAME 0x0B, 0x086F4620, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F4620, 0x0C, OAMR_12 - OAMR
    ANIMSCR_FRAME 0x09, 0x086F4620, 0x0D, OAMR_13 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x0E, OAMR_14 - OAMR
    ANIMSCR_FRAME 0x08, 0x086F4620, 0x0F, OAMR_15 - OAMR
    ANIMSCR_FRAME 0x07, 0x086F4620, 0x10, OAMR_16 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x11, OAMR_17 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x48
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x05, 0x086F5268, 0x12, OAMR_18 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x13, OAMR_19 - OAMR
    ANIMSCR_FRAME 0x10, 0x086F5268, 0x11, OAMR_17 - OAMR
    ANIMSCR_FRAME 0x06, 0x086F5268, 0x14, OAMR_20 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x46, 0x086F5268, 0x15, OAMR_21 - OAMR
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
