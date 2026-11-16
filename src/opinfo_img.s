	.section .rodata

	.global Pal_OpInfoViewLetters
Pal_OpInfoViewLetters: @ 08354760
	.incbin "fe6-base.gba", 0x354760, (0x354780 - 0x354760) @ length: 0020

	.global Img_OpInfoViewLettersB
Img_OpInfoViewLettersB: @ 08354780
	.incbin "fe6-base.gba", 0x354780, (0x357140 - 0x354780) @ length: 29C0

	.global Img_OpInfoViewLettersA
Img_OpInfoViewLettersA: @ 08357140
	.incbin "fe6-base.gba", 0x357140, (0x3599AC - 0x357140) @ length: 286C

	.global Img_OpInfoViewIcon
Img_OpInfoViewIcon: @ 083599AC
	.incbin "fe6-base.gba", 0x3599AC, (0x35A368 - 0x3599AC) @ length: 09BC

	.global Pal_OpInfoViewIcon
Pal_OpInfoViewIcon: @ 0835A368
	.incbin "fe6-base.gba", 0x35A368, (0x35A3E8 - 0x35A368) @ length: 0080

	.global Img_ClassDemoWindow
Img_ClassDemoWindow: @ 0835A3E8
	.incbin "fe6-base.gba", 0x35A3E8, (0x35A5D0 - 0x35A3E8) @ length: 01E8

	.global Pal_ClassDemoWindow
Pal_ClassDemoWindow: @ 0835A5D0
	.incbin "fe6-base.gba", 0x35A5D0, (0x35A5F0 - 0x35A5D0) @ length: 0020

	.global Tsa_ClassDemoWindow
Tsa_ClassDemoWindow: @ 0835A5F0
	.incbin "fe6-base.gba", 0x35A5F0, (0x35AB08 - 0x35A5F0) @ length: 0518

	.global Pal_ClassDemoBg
Pal_ClassDemoBg: @ 0835AB08
	.incbin "fe6-base.gba", 0x35AB08, (0x35AB28 - 0x35AB08) @ length: 0020

	.global Tsa_ClassDemoBg
Tsa_ClassDemoBg: @ 0835AB28
	.incbin "fe6-base.gba", 0x35AB28, (0x35B040 - 0x35AB28) @ length: 0518

	.global Img_ClassDemoFont
Img_ClassDemoFont: @ 0835B040
	.incbin "data/OpInfo/Img_ClassDemoFont.4bpp.lz"

	.global Pal_ClassDemoFont
Pal_ClassDemoFont: @ 0835C034
	.incbin "data/OpInfo/Img_ClassDemoFont.gbapal", 0, 0x20
	.incbin "data/OpInfo/Img_ClassDemoFont_Shadow.gbapal", 0, 0x20

	@ unused
	.global Img_IntelligentSystem
Img_IntelligentSystem:
	.incbin "data/OpInfo/Img_IntelligentSystem.4bpp.lz"

	@ unused
	.global Pal_IntelligentSystem
Pal_IntelligentSystem:
	.incbin "data/OpInfo/Img_IntelligentSystem.gbapal", 0, 0x20
