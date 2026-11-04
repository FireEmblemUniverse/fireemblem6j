	.section .rodata

	.global Pal_Title_BG
Pal_Title_BG: @ 0835CB90
	.incbin "fe6-base.gba", 0x35CB90, (0x35CC90 - 0x35CB90) @ length: 0100

	.global Img_Title_BG
Img_Title_BG: @ 0835CC90
	.incbin "fe6-base.gba", 0x35CC90, (0x35E6DC - 0x35CC90) @ length: 1A4C

	.global Img_Title_Sprites
Img_Title_Sprites: @ 0835E6DC
	.incbin "fe6-base.gba", 0x35E6DC, (0x35F2C8 - 0x35E6DC) @ length: 0BEC

	.global SpriteAnim_Title
SpriteAnim_Title: @ 0835F2C8
	.incbin "fe6-base.gba", 0x35F2C8, (0x35F388 - 0x35F2C8) @ length: 00C0

	.global Pal_Title_PressStartGlow
Pal_Title_PressStartGlow: @ 0835F388
	.incbin "fe6-base.gba", 0x35F388, (0x35F3A8 - 0x35F388) @ length: 0020

	.global Tsa_Title_BG2
Tsa_Title_BG2: @ 0835F3A8
	.incbin "fe6-base.gba", 0x35F3A8, (0x35F780 - 0x35F3A8) @ length: 03D8

	.global Tsa_Title_BG0
Tsa_Title_BG0: @ 0835F780
	.incbin "fe6-base.gba", 0x35F780, (0x35F9EC - 0x35F780) @ length: 026C

	.global Tsa_Title_BG1
Tsa_Title_BG1: @ 0835F9EC
	.incbin "fe6-base.gba", 0x35F9EC, (0x35FC3C - 0x35F9EC) @ length: 0250

	.global Img_Title_BG3
Img_Title_BG3: @ 0835FC3C
	.incbin "fe6-base.gba", 0x35FC3C, (0x364418 - 0x35FC3C) @ length: 47DC

	.global Pal_Title_BG3
Pal_Title_BG3: @ 08364418
	.incbin "fe6-base.gba", 0x364418, (0x364438 - 0x364418) @ length: 0020

	.global Img_Title_LensFlare
Img_Title_LensFlare: @ 08364438
	.incbin "fe6-base.gba", 0x364438, (0x364A94 - 0x364438) @ length: 065C

	.global Pal_Title_LensFlare
Pal_Title_LensFlare: @ 08364A94
	.incbin "fe6-base.gba", 0x364A94, (0x364AB4 - 0x364A94) @ length: 0020
