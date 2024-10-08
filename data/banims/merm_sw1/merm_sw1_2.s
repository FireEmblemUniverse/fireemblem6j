.include "macro.inc"
.include "animscr.inc"
.include "gba_sprites.inc"

.section .data.oamr
@ BANIM_OAMR_merm_sw1_2:
OAMR:
OAMR_0:
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00BE, -9, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x007F, 7, 8
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00DC, -7, -16
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x009E, -7, 0
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x003F, -2, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x005F, 9, -12
    ANIM_SPRITE_END
OAMR_1:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x003C, -9, -26
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00BC, -9, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x001E, 7, -18
    ANIM_SPRITE_END
OAMR_2:
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0012, -10, -16
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0014, 6, -16
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x0015, -5, -24
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
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
@ BANIM_OAML_merm_sw1_2:
OAML:
OAML_0:
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00BE, -7, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x007F, -15, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00DC, -9, -16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x009E, -9, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x003F, -6, -24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x005F, -17, -12
    ANIM_SPRITE_END
OAML_1:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x003C, -7, -26
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00BC, -7, 6
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x001E, -15, -18
    ANIM_SPRITE_END
OAML_2:
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0012, -6, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0014, -14, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0015, -3, -24
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
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
@ BANIM_SCR_merm_sw1_2:
SCR:
SCR_NORMAL_ATK:
    ANIMSCR_FRAME 0x04, BANIM_IMG_merm_sw1_1, 0x00, OAMR_0 - OAMR
    ANIMSCR_BLOCKED

SCR_NORMAL_ATK_PRIORITY_L:
    ANIMSCR_FRAME 0x04, BANIM_IMG_merm_sw1_1, 0x00, OAMR_0 - OAMR
    ANIMSCR_BLOCKED

SCR_CRIT_ATK:
    ANIMSCR_FRAME 0x04, BANIM_IMG_merm_sw1_1, 0x00, OAMR_0 - OAMR
    ANIMSCR_BLOCKED

SCR_CRIT_ATK_PRIORITY_L:
    ANIMSCR_FRAME 0x04, BANIM_IMG_merm_sw1_1, 0x00, OAMR_0 - OAMR
    ANIMSCR_BLOCKED

SCR_RANGED_ATK:
    ANIMSCR_FRAME 0x04, BANIM_IMG_merm_sw1_1, 0x00, OAMR_0 - OAMR
    ANIMSCR_BLOCKED

SCR_RANGED_CRIT_ATK:
    ANIMSCR_FRAME 0x04, BANIM_IMG_merm_sw1_1, 0x00, OAMR_0 - OAMR
    ANIMSCR_BLOCKED

SCR_CLOSE_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, BANIM_IMG_merm_sw1_1, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_merm_sw1_1, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_merm_sw1_2, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x02, BANIM_IMG_merm_sw1_1, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, BANIM_IMG_merm_sw1_1, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x02, BANIM_IMG_merm_sw1_1, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, BANIM_IMG_merm_sw1_2, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x02, BANIM_IMG_merm_sw1_1, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_STANDING:
    ANIMSCR_FRAME 0x01, BANIM_IMG_merm_sw1_1, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_STANDING2:
    ANIMSCR_FRAME 0x01, BANIM_IMG_merm_sw1_1, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_RANGED_STANDING:
    ANIMSCR_FRAME 0x01, BANIM_IMG_merm_sw1_1, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_MISSED_ATK:
    ANIMSCR_FRAME 0x04, BANIM_IMG_merm_sw1_1, 0x00, OAMR_0 - OAMR
    ANIMSCR_BLOCKED


.section .data.modes
@ BANIM_MODES_merm_sw1_2:
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
