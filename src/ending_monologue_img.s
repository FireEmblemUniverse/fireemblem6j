	.section .rodata

	.global Img_EndingMonologueText_NormalClosing
Img_EndingMonologueText_NormalClosing: @ 08349A98
	.incbin "data/Monologue/Img_EndingMonologueText_a.4bpp.lz"

	.global Img_EndingMonologueText_FinalChapter
Img_EndingMonologueText_FinalChapter: @ 0834B69C
	.incbin "data/Monologue/Img_EndingMonologueText_b.4bpp.lz"

	.global Img_EndingMonologueText_FalseEnding
Img_EndingMonologueText_FalseEnding: @ 0834E1D4
	@ ??
	@ .incbin "data/Monologue/Img_EndingMonologueText_c_.4bpp.lz"
	.incbin "fe6-base.gba", 0x34E1D4, (0x352160 - 0x34E1D4) @ length: 3F8C

	.global Img_EndingMonologueText_FalseEnding2
Img_EndingMonologueText_FalseEnding2: @ 08352160
	.incbin "data/Monologue/Img_EndingMonologueText_d.4bpp.lz"

	.global Pal_EndingMonologueText
Pal_EndingMonologueText: @ 08353308
	.incbin "data/Monologue/Img_EndingMonologueText_a.gbapal", 0, 0x20
