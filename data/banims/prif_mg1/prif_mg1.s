.include "macro.inc"
.include "animscr.inc"
.include "gba_sprites.inc"

.section .data.oamr
.global BANIM_OAMR_prif_mg1
BANIM_OAMR_prif_mg1:
OAMR:
OAMR_0:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0000, -11, -16
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0002, 5, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0004, -9, -24
    ANIM_SPRITE_END
OAMR_1:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0003, -17, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0005, -1, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0023, -17, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0063, -17, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0084, -9, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0086, 7, 8
    ANIM_SPRITE_END
OAMR_2:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0007, -9, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0029, 7, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0087, -9, 8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0003, -17, -27
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0006, 15, -5
    ANIM_SPRITE_END
OAMR_3:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x000A, -9, -16
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000C, 7, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x004A, -9, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x004C, 7, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0009, 15, -8
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0007, -9, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0003, -17, -27
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0087, -9, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0089, 7, 8
    ANIM_SPRITE_END
OAMR_4:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x000D, -9, -16
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000F, 7, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x004D, -9, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x004F, 7, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0007, -9, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0003, -17, -27
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0087, -9, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0089, 7, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0083, 15, 0
    ANIM_SPRITE_END
OAMR_5:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x006A, -9, -16
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x006C, 7, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AA, -9, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00AC, 7, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0007, -9, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0003, -17, -27
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0087, -9, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0089, 7, 8
    ANIM_SPRITE_END
OAMR_6:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x006D, -9, -16
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x006F, 7, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AD, -9, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00AF, 7, 0
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0004, -9, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0003, -17, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0084, -9, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0086, 7, 8
    ANIM_SPRITE_END
OAMR_7:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00A0, -10, -18
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00A2, 6, -18
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E0, -10, -2
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E2, 6, -2
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00A6, -10, 6
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A8, 6, 6
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0004, -9, -26
    ANIM_SPRITE_END
OAMR_8:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00A3, -11, -19
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00A5, 5, -19
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00E3, -11, -3
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E5, 5, -3
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00C6, -11, 5
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C8, 5, 5
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0004, -8, -27
    ANIM_SPRITE_END
OAMR_9:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, 0, -8
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END

.section .data.oaml
.global BANIM_OAML_prif_mg1
BANIM_OAML_prif_mg1:
OAML:
OAML_0:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0000, -5, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0002, -13, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0004, -7, -24
    ANIM_SPRITE_END
OAML_1:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0003, 1, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0005, -7, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0023, -15, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0063, -15, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0084, -7, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0086, -15, 8
    ANIM_SPRITE_END
OAML_2:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0007, -7, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0029, -15, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0087, -7, 8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0003, 9, -27
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0006, -23, -5
    ANIM_SPRITE_END
OAML_3:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x000A, -7, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x000C, -15, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x004A, -7, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x004C, -15, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0009, -23, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0007, -7, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0003, 9, -27
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0087, -7, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0089, -15, 8
    ANIM_SPRITE_END
OAML_4:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x000D, -7, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x000F, -15, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x004D, -7, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x004F, -15, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0007, -7, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0003, 9, -27
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0087, -7, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0089, -15, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0083, -23, 0
    ANIM_SPRITE_END
OAML_5:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x006A, -7, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x006C, -15, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00AA, -7, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00AC, -15, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0007, -7, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0003, 9, -27
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0087, -7, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0089, -15, 8
    ANIM_SPRITE_END
OAML_6:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x006D, -7, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x006F, -15, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00AD, -7, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00AF, -15, 0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0004, -7, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0003, 9, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0084, -7, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0086, -15, 8
    ANIM_SPRITE_END
OAML_7:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00A0, -6, -18
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00A2, -14, -18
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E0, -6, -2
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E2, -14, -2
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00A6, -6, 6
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00A8, -14, 6
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0004, -7, -26
    ANIM_SPRITE_END
OAML_8:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00A3, -5, -19
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00A5, -13, -19
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E3, -5, -3
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E5, -13, -3
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C6, -5, 5
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00C8, -13, 5
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0004, -8, -27
    ANIM_SPRITE_END
OAML_9:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x001F, -8, -8
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END

.section .data.script
.global BANIM_SCR_prif_mg1
BANIM_SCR_prif_mg1:
SCR:
SCR_NORMAL_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x06, _data_BANIM_MODE_brdm_mg1_end, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x05, _data_BANIM_MODE_brdm_mg1_end, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x04, OAMR_4 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x05, OAMR_5 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x06, OAMR_6 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_NORMAL_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x06, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x05, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x06, _data_BANIM_MODE_brdm_mg1_end, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x05, _data_BANIM_MODE_brdm_mg1_end, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x04, OAMR_4 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x05, OAMR_5 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x06, OAMR_6 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x06, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x05, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x09, OAMR_9 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x06, _data_BANIM_MODE_brdm_mg1_end, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x05, _data_BANIM_MODE_brdm_mg1_end, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x04, OAMR_4 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x05, OAMR_5 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x06, OAMR_6 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_CRIT_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x06, _data_BANIM_MODE_brdm_mg1_end, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x05, _data_BANIM_MODE_brdm_mg1_end, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x04, OAMR_4 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x05, OAMR_5 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x06, OAMR_6 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CLOSE_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, _data_BANIM_MODE_brdm_mg1_end, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x08, OAMR_8 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, _data_BANIM_MODE_brdm_mg1_end, 0x07, OAMR_7 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, _data_BANIM_MODE_brdm_mg1_end, 0x07, OAMR_7 - OAMR
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x08, OAMR_8 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, _data_BANIM_MODE_brdm_mg1_end, 0x07, OAMR_7 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_STANDING:
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_STANDING2:
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_RANGED_STANDING:
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_MISSED_ATK:
    ANIMSCR_CMD 0x03
    ANIMSCR_CMD 0x07
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x06, _data_BANIM_MODE_brdm_mg1_end, 0x02, OAMR_2 - OAMR
    ANIMSCR_FRAME 0x05, _data_BANIM_MODE_brdm_mg1_end, 0x03, OAMR_3 - OAMR
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x04, OAMR_4 - OAMR
    ANIMSCR_CMD 0x05
    ANIMSCR_FRAME 0x01, _data_BANIM_MODE_brdm_mg1_end, 0x05, OAMR_5 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x04, _data_BANIM_MODE_brdm_mg1_end, 0x06, OAMR_6 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED


.section .data.modes
.global BANIM_MODES_prif_mg1
BANIM_MODES_prif_mg1:
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
