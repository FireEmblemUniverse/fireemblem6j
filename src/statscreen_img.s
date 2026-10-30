	.section .rodata

	.global Tsa_Statscreen_08307CEC
Tsa_Statscreen_08307CEC: @ 08307CEC
	.incbin "fe6-base.gba", 0x307CEC, (0x307D58 - 0x307CEC) @ length: 006C

	.global Tsa_Statscreen_08307D58
Tsa_Statscreen_08307D58: @ 08307D58
	.incbin "fe6-base.gba", 0x307D58, (0x307DD4 - 0x307D58) @ length: 007C

	.global Tsa_Statscreen_08307DD4
Tsa_Statscreen_08307DD4: @ 08307DD4
	.incbin "fe6-base.gba", 0x307DD4, (0x307E50 - 0x307DD4) @ length: 007C

	.global Tsa_Statscreen_08307E50
Tsa_Statscreen_08307E50: @ 08307E50
	.incbin "fe6-base.gba", 0x307E50, (0x307ED4 - 0x307E50) @ length: 0084

	.global Img_Statscreen_08307ED4
Img_Statscreen_08307ED4: @ 08307ED4
	.incbin "fe6-base.gba", 0x307ED4, (0x308050 - 0x307ED4) @ length: 017C

	.global Pal_Statscreen_08308050
Pal_Statscreen_08308050: @ 08308050
	.incbin "fe6-base.gba", 0x308050, (0x308070 - 0x308050) @ length: 0020

	.global Tsa_Statscreen_08308070
Tsa_Statscreen_08308070: @ 08308070
	.incbin "fe6-base.gba", 0x308070, (0x3080AC - 0x308070) @ length: 003C

	.global Tsa_Statscreen_083080AC
Tsa_Statscreen_083080AC: @ 083080AC
	.incbin "fe6-base.gba", 0x3080AC, (0x3080D0 - 0x3080AC) @ length: 0024

	.global Img_Statscreen_MiscSprites
Img_Statscreen_MiscSprites: @ 083080D0
	.incbin "fe6-base.gba", 0x3080D0, (0x3087C8 - 0x3080D0) @ length: 06F8

	.global Pal_StatscreenPageNameFlashing
Pal_StatscreenPageNameFlashing: @ 083087C8
	.incbin "fe6-base.gba", 0x3087C8, (0x308920 - 0x3087C8) @ length: 0158

	.global Img_Statscreen_08308920
Img_Statscreen_08308920: @ 08308920
	.incbin "fe6-base.gba", 0x308920, (0x308A78 - 0x308920) @ length: 0158

	.global Img_Helpbox_08308A78
Img_Helpbox_08308A78: @ 08308A78
	.incbin "fe6-base.gba", 0x308A78, (0x308B98 - 0x308A78) @ length: 0120
