.include "macro.inc"
.include "animscr.inc"
.include "gba_sprites.inc"

.section .data.oamr
OAMR:
OAMR_0:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0000, -16, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0080, -16, 8
    ANIM_SPRITE_END
OAMR_1:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0004, -19, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0084, -19, 8
    ANIM_SPRITE_END
OAMR_2:
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0008, -24, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x0088, -24, 8
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
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
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0000, -16, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0080, -16, 8
    ANIM_SPRITE_END
OAML_1:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0004, -13, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0084, -13, 8
    ANIM_SPRITE_END
OAML_2:
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0008, -8, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0088, -8, 8
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
    ANIM_SPRITE_END
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
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x08716680, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, 0x08716680, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x08716680, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, 0x08716680, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_NORMAL_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x08716680, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, 0x08716680, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x08716680, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, 0x08716680, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CRIT_ATK_PRIORITY_L:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x08716680, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, 0x08716680, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_ATK:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x08716680, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, 0x08716680, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_CRIT_ATK:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x08716680, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, 0x08716680, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_CLOSE_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x08716680, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, 0x08716680, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_RANGED_DODGE:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x08716680, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x0E
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, 0x08716680, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
    ANIMSCR_BLOCKED

SCR_STANDING:
    ANIMSCR_FRAME 0x01, 0x08716680, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_STANDING2:
    ANIMSCR_FRAME 0x01, 0x08716680, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_RANGED_STANDING:
    ANIMSCR_FRAME 0x01, 0x08716680, 0x00, OAMR_0 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_BLOCKED

SCR_MISSED_ATK:
    ANIMSCR_CMD 0x02
    ANIMSCR_FRAME 0x01, 0x08716680, 0x00, OAMR_0 - OAMR
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_FRAME 0x01, 0x08716680, 0x02, OAMR_2 - OAMR
    ANIMSCR_CMD 0x01
    ANIMSCR_FRAME 0x03, 0x08716680, 0x01, OAMR_1 - OAMR
    ANIMSCR_CMD 0x0D
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
