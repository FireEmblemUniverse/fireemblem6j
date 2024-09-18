.include "macro.inc"
.include "animscr.inc"
.include "gba_sprites.inc"

.section .data.oamr
.global BANIM_OAMR_berm_ax1_3
BANIM_OAMR_berm_ax1_3:
OAMR:
OAMR_0:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0014, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0031, -8, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0033, 8, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0011, -5, -32
    ANIM_SPRITE_END
OAMR_1:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0097, -44, -19
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00D7, -12, -11
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D9, 4, -11
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0058, 12, -19
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0093, -15, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00F7, -15, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0052, -31, -15
    ANIM_SPRITE_END
OAMR_2:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0093, -15, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00F7, -15, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0052, -31, -15
    ANIM_SPRITE_END
OAMR_3:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0018, -24, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x001C, 8, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x005A, -16, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00DA, -24, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x009B, -16, 8
    ANIM_SPRITE_END
OAMR_4:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0071, 3, -27
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0092, 11, -19
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B2, 3, -19
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0073, -5, -19
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x001D, -13, -34
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x003F, 3, -26
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x005E, -16, -18
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x007E, 0, -18
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00BB, -16, -10
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00FB, -16, 6
    ANIM_SPRITE_END
OAMR_5:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0000, -20, -27
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0080, -20, 5
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EA, 12, 5
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EB, -12, -35
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EB, -3, -35
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00AC, 12, -20
    ANIM_SPRITE_END
OAMR_6:
    ANIM_SPRITE ATTR0_SQUARE, 0x6000, 0x0025, 12, -27
    ANIM_SPRITE ATTR0_TALL, 0x2000, 0x0004, 4, -19
    ANIM_SPRITE ATTR0_SQUARE, 0x2000, 0x0044, 4, -27
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00A1, -7, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00C0, -15, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E0, -15, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E2, 1, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E3, 9, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C4, -15, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C6, 1, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00E4, -15, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A0, 17, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A3, 1, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C7, 9, 0
    ANIM_SPRITE_END
OAMR_7:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0066, 5, -27
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0005, 13, -11
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0064, 13, -27
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00A1, -7, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00C0, -15, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E0, -15, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E2, 1, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E3, 9, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C4, -15, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C6, 1, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00E4, -15, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A0, 17, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A3, 1, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C7, 9, 0
    ANIM_SPRITE_END
OAMR_8:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0025, 5, -14
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0004, 21, -22
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0044, 21, -6
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00A1, -7, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00C0, -15, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E0, -15, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E2, 1, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E3, 9, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C4, -15, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C6, 1, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00E4, -15, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A0, 17, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A3, 1, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C7, 9, 0
    ANIM_SPRITE_END
OAMR_9:
    ANIM_SPRITE ATTR0_SQUARE, 0x2000, 0x0066, 16, -6
    ANIM_SPRITE ATTR0_WIDE, 0x2000, 0x0005, 0, -22
    ANIM_SPRITE ATTR0_SQUARE, 0x6000, 0x0064, 0, -14
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00A1, -7, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00C0, -15, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E0, -15, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E2, 1, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E3, 9, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C4, -15, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C6, 1, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00E4, -15, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A0, 17, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A3, 1, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C7, 9, 0
    ANIM_SPRITE_END
OAMR_10:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, 0, -8
    ANIM_SPRITE_END
OAMR_11:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, 0, -8
    ANIM_SPRITE_END
OAMR_12:
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
.global BANIM_OAML_berm_ax1_3
BANIM_OAML_berm_ax1_3:
OAML:
OAML_0:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0014, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0031, -8, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0033, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0011, -11, -32
    ANIM_SPRITE_END
OAML_1:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0097, 12, -19
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00D7, -4, -11
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D9, -12, -11
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0058, -28, -19
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0093, -17, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00F7, -17, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0052, 15, -15
    ANIM_SPRITE_END
OAML_2:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0093, -17, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00F7, -17, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0052, 15, -15
    ANIM_SPRITE_END
OAML_3:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0018, -8, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x001C, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x005A, -16, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00DA, 16, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x009B, -16, 8
    ANIM_SPRITE_END
OAML_4:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0071, -19, -27
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0092, -19, -19
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B2, -11, -19
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0073, -3, -19
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x001D, -3, -34
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x003F, -11, -26
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x005E, 0, -18
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x007E, -16, -18
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00BB, -16, -10
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00FB, -16, 6
    ANIM_SPRITE_END
OAML_5:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0000, -12, -27
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0080, -12, 5
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EA, -20, 5
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EB, 4, -35
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EB, -5, -35
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00AC, -20, -20
    ANIM_SPRITE_END
OAML_6:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, 0x6000, 0x0025, -28, -27
    ANIM_SPRITE_XFLIP ATTR0_TALL, 0x2000, 0x0004, -12, -19
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, 0x2000, 0x0044, -12, -27
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00A1, -9, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00C0, -17, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E0, -1, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E2, -9, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E3, -17, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C4, -1, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C6, -9, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00E4, -17, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A0, -25, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A3, -9, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C7, -17, 0
    ANIM_SPRITE_END
OAML_7:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0066, -13, -27
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0005, -29, -11
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0064, -29, -27
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00A1, -9, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00C0, -17, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E0, -1, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E2, -9, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E3, -17, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C4, -1, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C6, -9, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00E4, -17, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A0, -25, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A3, -9, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C7, -17, 0
    ANIM_SPRITE_END
OAML_8:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0025, -21, -14
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0004, -29, -22
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0044, -29, -6
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00A1, -9, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00C0, -17, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E0, -1, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E2, -9, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E3, -17, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C4, -1, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C6, -9, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00E4, -17, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A0, -25, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A3, -9, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C7, -17, 0
    ANIM_SPRITE_END
OAML_9:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, 0x2000, 0x0066, -24, -6
    ANIM_SPRITE_XFLIP ATTR0_WIDE, 0x2000, 0x0005, -16, -22
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, 0x6000, 0x0064, -16, -14
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00A1, -9, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00C0, -17, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E0, -1, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E2, -9, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E3, -17, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C4, -1, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C6, -9, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00E4, -17, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A0, -25, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A3, -9, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C7, -17, 0
    ANIM_SPRITE_END
OAML_10:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, -8, -8
    ANIM_SPRITE_END
OAML_11:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, -8, -8
    ANIM_SPRITE_END
OAML_12:
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
.global BANIM_SCR_berm_ax1_3
BANIM_SCR_berm_ax1_3:
SCR:
SCR_NORMAL_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_CMD 0x41
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x03, OAMR_3 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_NORMAL_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x0B, OAMR_11 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_CMD 0x41
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x0B, OAMR_11 - OAMR
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x0B, OAMR_11 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x0B, OAMR_11 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x38
    ANIMSCR_FRAME 0x02, BANIM_IMG_berm_ax1_2_0, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_berm_ax1_2_0, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_berm_ax1_2_0, 0x08, OAMR_8 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_berm_ax1_2_0, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x0F, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_CMD 0x41
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x03, OAMR_3 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x0B, OAMR_11 - OAMR
    ANIMSCR_CMD 0x38
    ANIMSCR_FRAME 0x02, BANIM_IMG_berm_ax1_2_0, 0x0C, OAMR_12 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_berm_ax1_2_0, 0x0C, OAMR_12 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_berm_ax1_2_0, 0x0C, OAMR_12 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_berm_ax1_2_0, 0x0C, OAMR_12 - OAMR
    ANIMSCR_FRAME 0x0F, _data_BANIM_IMG_berm_ax1_0_end, 0x0B, OAMR_11 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_CMD 0x41
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x0B, OAMR_11 - OAMR
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x0B, OAMR_11 - OAMR
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x0B, OAMR_11 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x0B, OAMR_11 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_CMD 0x41
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x03, OAMR_3 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_CRIT_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x38
    ANIMSCR_FRAME 0x02, BANIM_IMG_berm_ax1_2_0, 0x06, OAMR_6 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_berm_ax1_2_0, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_berm_ax1_2_0, 0x08, OAMR_8 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_berm_ax1_2_0, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x0F, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_CMD 0x41
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x03, OAMR_3 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CLOSE_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_berm_ax1_2_0, 0x05, OAMR_5 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x04, OAMR_4 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x04, OAMR_4 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_berm_ax1_2_0, 0x05, OAMR_5 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x04, OAMR_4 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_STANDING:
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_STANDING2:
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_RANGED_STANDING:
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_MISSED_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_CMD 0x41
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x13
    ANIMSCR_FRAME 0x03, _data_BANIM_IMG_berm_ax1_0_end, 0x03, OAMR_3 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x01, _data_BANIM_IMG_berm_ax1_0_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED


.section .data.modes
.global BANIM_MODES_berm_ax1_3
BANIM_MODES_berm_ax1_3:
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
