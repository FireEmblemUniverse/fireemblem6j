.include "macro.inc"
.include "animscr.inc"
.include "gba_sprites.inc"

.section .data.oamr
OAMR:
OAMR_0:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00CC, -14, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EC, -14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EA, -12, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EB, -12, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00CD, -6, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0021, -16, -8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0023, 0, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0061, -16, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0063, 0, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0002, -8, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0040, -24, 0
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0000, 8, -8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0060, 8, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -5, -24
    ANIM_SPRITE_END
OAMR_1:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00AF, -18, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00EF, -18, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x008F, -18, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0091, -2, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0092, -6, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00ED, -26, -19
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00CE, -18, -11
    ANIM_SPRITE_END
OAMR_2:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00B3, -20, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00F3, -20, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0093, -18, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0095, -2, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0096, -10, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00ED, -27, -25
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00CE, -19, -17
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B7, 12, 1
    ANIM_SPRITE_END
OAMR_3:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x00AE, -18, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x00EE, -18, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00CC, -16, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00EC, 0, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EB, 0, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x008E, -8, -24
    ANIM_SPRITE_END
OAMR_4:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0069, -18, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x000D, 14, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0048, -6, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0068, 2, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x006A, -10, 8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x000E, -2, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x004D, 1, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x002D, 1, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x002F, 17, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x004F, 9, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x000A, -10, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x004A, -10, 0
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0029, -18, -8
    ANIM_SPRITE_END
OAMR_5:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, -8, -8
    ANIM_SPRITE_END
OAMR_6:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, -8, -8
    ANIM_SPRITE_END
OAMR_7:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, -8, -8
    ANIM_SPRITE_END
OAMR_8:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, -8, -8
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
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
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00CC, 6, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EC, 6, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EA, 4, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EB, 4, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00CD, -2, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0021, 0, -8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0023, -8, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0061, 0, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0063, -8, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0002, -8, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0040, 16, 0
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0000, -16, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0060, -16, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0001, -3, -24
    ANIM_SPRITE_END
OAML_1:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00AF, -14, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00EF, -14, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x008F, 2, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0091, -6, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0092, -2, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00ED, 10, -19
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00CE, 10, -11
    ANIM_SPRITE_END
OAML_2:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00B3, -12, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00F3, -12, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0093, 2, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0095, -6, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0096, -6, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00ED, 11, -25
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00CE, 11, -17
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B7, -20, 1
    ANIM_SPRITE_END
OAML_3:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00AE, -14, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00EE, -14, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00CC, 0, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00EC, -16, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EB, -8, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x008E, 0, -24
    ANIM_SPRITE_END
OAML_4:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0069, 10, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x000D, -22, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0048, -2, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0068, -10, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x006A, 2, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x000E, -14, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x004D, -17, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x002D, -17, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x002F, -25, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x004F, -17, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x000A, -6, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x004A, -6, 0
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0029, 10, -8
    ANIM_SPRITE_END
OAML_5:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, 0, -8
    ANIM_SPRITE_END
OAML_6:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, 0, -8
    ANIM_SPRITE_END
OAML_7:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, 0, -8
    ANIM_SPRITE_END
OAML_8:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, 0, -8
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
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
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_NORMAL_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x05, OAMR_5 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x05, OAMR_5 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x05, OAMR_5 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x05, OAMR_5 - OAMR
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x05, OAMR_5 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x05, OAMR_5 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x05, OAMR_5 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_CRIT_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x06
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CLOSE_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x086E0E2C, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x01, 0x086E0E2C, 0x04, OAMR_4 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x086E0E2C, 0x03, OAMR_3 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x086E0E2C, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x01, 0x086E0E2C, 0x04, OAMR_4 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x086E0E2C, 0x03, OAMR_3 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_STANDING:
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_STANDING2:
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_RANGED_STANDING:
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_MISSED_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x08
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x06
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, 0x086DE248, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x04, 0x086DE248, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0E
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
