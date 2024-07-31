	.data
	.include "animscr.inc"
	.include "gba_sprites.inc"

	.global gUnk_08604948
gUnk_08604948: @ 08604948
	.incbin "fe6-base.gba", 0x604948, (0x604968 - 0x604948) @ length: 0020

	.global gUnk_08604968
gUnk_08604968: @ 08604968
	.incbin "fe6-base.gba", 0x604968, (0x604988 - 0x604968) @ length: 0020

	.global gUnk_08604988
gUnk_08604988: @ 08604988
	.incbin "fe6-base.gba", 0x604988, (0x6049A8 - 0x604988) @ length: 0020

	.global gUnk_086049A8
gUnk_086049A8: @ 086049A8
	.incbin "fe6-base.gba", 0x6049A8, (0x6049D0 - 0x6049A8) @ length: 0028

	.global ProcScr_EkrIdunnDeamon
ProcScr_EkrIdunnDeamon: @ 086049D0
	.incbin "fe6-base.gba", 0x6049D0, (0x6049E8 - 0x6049D0) @ length: 0018

	.global gUnk_086049E8
gUnk_086049E8: @ 086049E8
	.incbin "fe6-base.gba", 0x6049E8, (0x604A00 - 0x6049E8) @ length: 0018

	.global ProcScr_EkrIdunnBodyFlashing
ProcScr_EkrIdunnBodyFlashing: @ 08604A00
	.incbin "fe6-base.gba", 0x604A00, (0x604A18 - 0x604A00) @ length: 0018

	.global gUnk_08604A18
gUnk_08604A18: @ 08604A18
	.incbin "fe6-base.gba", 0x604A18, (0x604A3C - 0x604A18) @ length: 0024

	.global gUnk_08604A3C
gUnk_08604A3C: @ 08604A3C
	.incbin "fe6-base.gba", 0x604A3C, (0x604A6C - 0x604A3C) @ length: 0030

	.global gUnk_08604A6C
gUnk_08604A6C: @ 08604A6C
	.incbin "fe6-base.gba", 0x604A6C, (0x604A9C - 0x604A6C) @ length: 0030

	.global gUnk_08604A9C
gUnk_08604A9C: @ 08604A9C
	.incbin "fe6-base.gba", 0x604A9C, (0x604ACC - 0x604A9C) @ length: 0030

	.global gUnk_08604ACC
gUnk_08604ACC: @ 08604ACC
	.incbin "fe6-base.gba", 0x604ACC, (0x604AE4 - 0x604ACC) @ length: 0168

AnimSprite_Manaketefx1_1:  @ 0x604AE4
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0000, -8, -8
    ANIM_SPRITE_END

AnimSprite_Manaketefx1_2:  @ 0x604AFC
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0040, -16, -14
    ANIM_SPRITE_END

AnimSprite_Manaketefx1_3:  @ 0x604B14
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_64, 0x0004, -16, -40
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0068, -24, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0008, -32, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0048, -32, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E1, 0, 24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00E3, -8, 24
    ANIM_SPRITE_END

AnimSprite_Manaketefx1_4:  @ 0x604B68
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0009, -16, -48
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x000D, -32, -48
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0049, -16, -32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x004D, -32, -32
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x006E, -40, -40
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0069, 0, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E9, 0, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x006B, -8, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00AB, -32, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00EB, -32, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x006C, 16, 28
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x000F, -16, 16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x004F, -16, 32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x006F, 0, 40
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0013, -32, 16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0053, -24, 32
    ANIM_SPRITE_END

	.global AnimScr_ManaketeEnter1
AnimScr_ManaketeEnter1: @ 08604C34
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx1_1, 4
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx1_2, 6
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx1_3, 6
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx1_4, 5
    ANIMSCR_BLOCKED

	.global AnimScr_ManaketeExit3
AnimScr_ManaketeExit3: @ 08604C48
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx1_4, 5
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx1_3, 6
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx1_2, 6
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx1_1, 4
    ANIMSCR_BLOCKED

AnimSprite_Manaketefx2_1:  @ 0x604C5C
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_64, 0x0000, -40, -40
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0085, -32, -8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0087, -40, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0008, 16, 32
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x000A, 8, 32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0048, 16, 48
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x004A, 8, 48
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00A3, -8, 32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E3, -8, 48
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0080, -24, 24
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0082, -32, 24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x0083, -40, 24
    ANIM_SPRITE_END

AnimSprite_Manaketefx2_2:  @ 0x604CF8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_64, 0x000B, -32, -40
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x0013, -40, -40
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00AB, 0, 32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00AF, -32, 32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00EB, 0, 48
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00EF, -32, 48
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0090, -40, 24
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0088, -40, -8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x008A, -48, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00C8, -40, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00CA, -48, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x00E8, -32, 16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00EA, -40, 16
    ANIM_SPRITE_END

AnimSprite_Manaketefx2_3:  @ 0x604DA0
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_64, 0x0014, -32, -40
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_16, 0x001C, -40, -40
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_32, 0x0099, -40, 16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x003D, -40, -8
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x003F, -48, -8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x007D, -40, 8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x007F, -48, 8
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0094, 0, 32
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0098, -8, 32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00D4, 0, 48
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D8, -8, 48
    ANIM_SPRITE_END

	.global AnimScr_ManaketeEnter2
AnimScr_ManaketeEnter2: @ 08604E30
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx2_1, 5
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx2_2, 4
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx2_3, 5
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx2_1, 4
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx2_2, 5
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx2_3, 4
    ANIMSCR_BLOCKED

	.global AnimScr_ManaketeExit2
AnimScr_ManaketeExit2: @ 08604E4C
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx2_3, 4
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx2_2, 5
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx2_1, 4
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx2_3, 5
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx2_2, 4
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx2_1, 5
    ANIMSCR_BLOCKED

AnimSprite_Manaketefx3_1:  @ 0x604E68
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, 0, -40
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x0004, -32, -40
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0008, -48, -40
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0040, 0, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x0044, -32, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0048, -48, -24
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_8, 0x0060, 16, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0067, -40, -16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0069, -48, -16
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00A8, -48, 0
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x0063, -40, 16
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_8, 0x0065, -48, 16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00A0, -8, 32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00A4, -40, 32
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00E0, -8, 48
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_16, 0x00E4, -40, 48
    ANIM_SPRITE_END

AnimSprite_Manaketefx3_2:  @ 0x604F34
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_64, 0x000A, -32, -40
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0012, -48, -40
    ANIM_SPRITE_XFLIP ATTR0_TALL, ATTR1_SIZE_32, 0x0092, -48, -8
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_8, 0x00F1, -32, 16
    ANIM_SPRITE_XFLIP ATTR0_WIDE, ATTR1_SIZE_32, 0x00CA, -8, 32
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00CE, -24, 32
    ANIM_SPRITE_XFLIP ATTR0_SQUARE, ATTR1_SIZE_16, 0x00B0, -40, 24
    ANIM_SPRITE_END

	.global AnimScr_ManaketeEnter3
AnimScr_ManaketeEnter3: @ 08604F94
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx3_1, 5
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx3_2, 5
    ANIMSCR_BLOCKED

	.global AnimScr_ManaketeExit1
AnimScr_ManaketeExit1: @ 08604FA0
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx3_2, 5
    ANIMSCR_FORCE_SPRITE AnimSprite_Manaketefx3_1, 5
    ANIMSCR_BLOCKED

AnimSprite_Idunnfx_1:  @ 0x604FAC
    ANIM_SPRITE_AFFIN 1, 0x80, 0xdd, -0xdd, 0x80
    ANIM_SPRITE ATTR0_SQUARE + OBJ_ROT_SCALE_ON, ATTR1_SIZE_32, 0x009C, -7, -50
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0017, -8, -26
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009B, 24, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0096, -16, 6
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D4, -32, 14
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00B4, -32, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00D3, -40, 14
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B2, -34, 30
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B1, -10, 38
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D2, 14, 38
    ANIM_SPRITE_END

AnimSprite_Idunnfx_2:  @ 0x60503C
    ANIM_SPRITE_AFFIN 1, 0xa4, 0xc4, -0xc4, 0xa4
    ANIM_SPRITE ATTR0_SQUARE + OBJ_ROT_SCALE_ON, ATTR1_SIZE_32, 0x009C, -8, -50
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0017, -8, -26
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009B, 24, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0096, -16, 6
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D4, -32, 14
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00B4, -32, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00D3, -40, 14
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B2, -34, 30
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B1, -10, 38
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D2, 14, 38
    ANIM_SPRITE_END

AnimSprite_Idunnfx_3:  @ 0x6050CC
    ANIM_SPRITE_AFFIN 1, 0xc4, 0xa4, -0xa4, 0xc4
    ANIM_SPRITE ATTR0_SQUARE + OBJ_ROT_SCALE_ON, ATTR1_SIZE_32, 0x009C, -9, -49
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0017, -8, -26
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009B, 24, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0096, -16, 6
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D4, -32, 14
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00B4, -32, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00D3, -40, 14
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B2, -34, 30
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B1, -10, 38
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D2, 14, 38
    ANIM_SPRITE_END

AnimSprite_Idunnfx_4:  @ 0x60515C
    ANIM_SPRITE_AFFIN 1, 0xdd, 0x7f, -0x7f, 0xdd
    ANIM_SPRITE ATTR0_SQUARE + OBJ_ROT_SCALE_ON, ATTR1_SIZE_32, 0x009C, -11, -49
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0017, -8, -26
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009B, 24, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0096, -16, 6
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D4, -32, 14
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00B4, -32, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00D3, -40, 14
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B2, -34, 30
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B1, -10, 38
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D2, 14, 38
    ANIM_SPRITE_END

AnimSprite_Idunnfx_5:  @ 0x6051EC
    ANIM_SPRITE_AFFIN 1, 0xf0, 0x57, -0x57, 0xf0
    ANIM_SPRITE ATTR0_SQUARE + OBJ_ROT_SCALE_ON, ATTR1_SIZE_32, 0x009C, -12, -49
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0017, -8, -26
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009B, 24, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0096, -16, 6
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D4, -32, 14
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00B4, -32, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00D3, -40, 14
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B2, -34, 30
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B1, -10, 38
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D2, 14, 38
    ANIM_SPRITE_END

AnimSprite_Idunnfx_6:  @ 0x60527C
    ANIM_SPRITE_AFFIN 1, 0xfc, 0x2c, -0x2c, 0xfc
    ANIM_SPRITE ATTR0_SQUARE + OBJ_ROT_SCALE_ON, ATTR1_SIZE_32, 0x009C, -14, -49
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0017, -8, -26
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009B, 24, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0096, -16, 6
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D4, -32, 14
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00B4, -32, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00D3, -40, 14
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B2, -34, 30
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B1, -10, 38
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D2, 14, 38
    ANIM_SPRITE_END

AnimSprite_Idunnfx_7:  @ 0x60530C
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x009C, -16, -48
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0017, -8, -26
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x009B, 24, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0096, -16, 6
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00D4, -32, 14
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00B4, -32, 6
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x00D3, -40, 14
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B2, -34, 30
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00B1, -10, 38
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_8, 0x00D2, 14, 38
    ANIM_SPRITE_END

AnimSprite_Idunnfx_8:  @ 0x605390
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0004, -26, -81
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0008, 6, -81
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0088, 6, -49
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x004A, 22, -65
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00CA, 22, -33
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000A, 38, -25
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0070, -32, -39
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, 6, -17
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0040, -58, -65
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x006C, -51, -37
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AC, -51, -21
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x000C, -70, -42
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x004C, -70, -26
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0010, -38, -42
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0014, -72, -28
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0016, -56, -28
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0094, -72, 4
    ANIM_SPRITE_END

AnimSprite_Idunnfx_9:  @ 0x605468
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0004, -26, -88
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0008, 6, -88
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0088, 6, -56
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x004A, 22, -72
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00CA, 22, -40
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000A, 38, -32
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0070, -35, -44
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, 6, -24
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0040, -58, -72
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x006C, -53, -40
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AC, -53, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x000C, -70, -46
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x004C, -70, -30
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0010, -38, -46
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0014, -72, -28
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0016, -56, -28
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0094, -72, 4
    ANIM_SPRITE_END

AnimSprite_Idunnfx_10:  @ 0x605540
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0004, -26, -87
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0008, 6, -87
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0088, 6, -55
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x004A, 22, -71
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00CA, 22, -39
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000A, 38, -31
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0070, -35, -44
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, 6, -23
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0040, -58, -71
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x006C, -53, -40
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AC, -53, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x000C, -70, -46
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x004C, -70, -30
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0010, -38, -46
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0014, -72, -28
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0016, -56, -28
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0094, -72, 4
    ANIM_SPRITE_END

AnimSprite_Idunnfx_11:  @ 0x605618
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0004, -26, -86
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0008, 6, -86
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0088, 6, -54
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x004A, 22, -70
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00CA, 22, -38
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000A, 38, -30
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0070, -35, -43
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, 6, -22
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0040, -58, -70
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x006C, -52, -40
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AC, -52, -24
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x000C, -70, -45
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x004C, -70, -29
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0010, -38, -45
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0014, -72, -28
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0016, -56, -28
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0094, -72, 4
    ANIM_SPRITE_END

AnimSprite_Idunnfx_12:  @ 0x6056F0
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0004, -26, -85
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0008, 6, -85
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0088, 6, -53
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x004A, 22, -69
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00CA, 22, -37
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000A, 38, -29
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0070, -34, -42
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, 6, -21
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0040, -58, -69
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x006C, -52, -39
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AC, -52, -23
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x000C, -70, -44
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x004C, -70, -28
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0010, -38, -44
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0014, -72, -28
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0016, -56, -28
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0094, -72, 4
    ANIM_SPRITE_END

AnimSprite_Idunnfx_13:  @ 0x6057C8
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0004, -26, -84
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0008, 6, -84
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0088, 6, -52
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x004A, 22, -68
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00CA, 22, -36
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000A, 38, -28
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0070, -34, -41
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, 6, -20
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0040, -58, -68
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x006C, -51, -39
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AC, -51, -23
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x000C, -70, -44
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x004C, -70, -28
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0010, -38, -44
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0014, -72, -28
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0016, -56, -28
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0094, -72, 4
    ANIM_SPRITE_END

AnimSprite_Idunnfx_14:  @ 0x6058A0
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0004, -26, -83
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0008, 6, -83
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0088, 6, -51
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x004A, 22, -67
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00CA, 22, -35
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000A, 38, -27
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0070, -34, -40
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, 6, -19
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0040, -58, -67
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x006C, -51, -38
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AC, -51, -22
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x000C, -70, -43
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x004C, -70, -27
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0010, -38, -43
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0014, -72, -28
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0016, -56, -28
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0094, -72, 4
    ANIM_SPRITE_END

AnimSprite_Idunnfx_15:  @ 0x605978
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_64, 0x0004, -26, -82
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0008, 6, -82
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0088, 6, -50
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x004A, 22, -66
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x00CA, 22, -34
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_8, 0x000A, 38, -26
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0070, -34, -39
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x0000, 6, -18
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_32, 0x0040, -58, -66
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x006C, -51, -38
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x00AC, -51, -22
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_32, 0x000C, -70, -43
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_16, 0x004C, -70, -27
    ANIM_SPRITE ATTR0_SQUARE, ATTR1_SIZE_16, 0x0010, -38, -43
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_32, 0x0014, -72, -28
    ANIM_SPRITE ATTR0_TALL, ATTR1_SIZE_16, 0x0016, -56, -28
    ANIM_SPRITE ATTR0_WIDE, ATTR1_SIZE_8, 0x0094, -72, 4
    ANIM_SPRITE_END

	.global AnimScr_EkrIdunnDeamon
AnimScr_EkrIdunnDeamon: @ 08605A50
    ANIMSCR_FORCE_SPRITE AnimSprite_Idunnfx_1, 2
    ANIMSCR_FORCE_SPRITE AnimSprite_Idunnfx_2, 2
    ANIMSCR_FORCE_SPRITE AnimSprite_Idunnfx_3, 2
    ANIMSCR_FORCE_SPRITE AnimSprite_Idunnfx_4, 2
    ANIMSCR_FORCE_SPRITE AnimSprite_Idunnfx_5, 2
    ANIMSCR_FORCE_SPRITE AnimSprite_Idunnfx_6, 2
    ANIMSCR_FORCE_SPRITE AnimSprite_Idunnfx_7, 1
    ANIMSCR_BLOCKED

	.global gUnk_08605A70
gUnk_08605A70: @ 08605A70
	.incbin "fe6-base.gba", 0x605A70, (0x605A94 - 0x605A70) @ length: 0024
