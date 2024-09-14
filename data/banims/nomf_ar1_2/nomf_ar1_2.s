.include "macro.inc"
.include "animscr.inc"
.include "gba_sprites.inc"

.section .data.oamr
.global BANIM_OAMR_nomf_ar1_2
BANIM_OAMR_nomf_ar1_2:
OAMR:
OAMR_0:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00C0, -11, -31
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00C2, 5, -31
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00C3, -11, -15
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0005, -5, 1
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0080, -19, 0
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0044, 13, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0024, 13, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0045, 21, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0020, -19, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0060, -19, -8
    ANIM_SPRITE_END
OAMR_1:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00B1, -12, -17
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D3, -13, -33
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00D5, 3, -33
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0005, -6, -1
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x000E, -19, -24
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0012, 13, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x008E, -19, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0092, 13, 8
    ANIM_SPRITE_END
OAMR_2:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0018, -16, -34
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x001A, 0, -34
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D6, -16, -18
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0005, -9, -2
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0013, -20, -32
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0017, 12, -32
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0093, -20, 0
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x0097, 12, 0
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
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
.global BANIM_OAML_nomf_ar1_2
BANIM_OAML_nomf_ar1_2:
OAML:
OAML_0:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00C0, -5, -31
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00C2, -13, -31
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00C3, -5, -15
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0005, -3, 1
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0080, -13, 0
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0044, -21, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0024, -21, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0045, -29, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0020, -13, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0060, -13, -8
    ANIM_SPRITE_END
OAML_1:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00B1, -4, -17
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D3, -3, -33
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x00D5, -11, -33
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0005, -2, -1
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x000E, -13, -24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0012, -21, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x008E, -13, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0092, -21, 8
    ANIM_SPRITE_END
OAML_2:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0018, 0, -34
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x001A, -8, -34
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D6, 0, -18
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0005, 1, -2
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0013, -12, -32
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0017, -20, -32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0093, -12, 0
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0097, -20, 0
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
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
.global BANIM_SCR_nomf_ar1_2
BANIM_SCR_nomf_ar1_2:
SCR:
SCR_NORMAL_ATK:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_2, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_NORMAL_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_2, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_2, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_2, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_ATK:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_2, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_CRIT_ATK:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_2, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CLOSE_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_2, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_2, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_STANDING:
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_STANDING2:
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_RANGED_STANDING:
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_MISSED_ATK:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_0, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_nomf_ar1_2, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, BANIM_IMG_nomf_ar1_2, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED


.section .data.modes
.global BANIM_MODES_nomf_ar1_2
BANIM_MODES_nomf_ar1_2:
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