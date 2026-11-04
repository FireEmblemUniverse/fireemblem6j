    .section .rodata

	.global Img_Prep_083198CC
Img_Prep_083198CC: @ 083198CC
	.incbin "fe6-base.gba", 0x3198CC, (0x319E88 - 0x3198CC) @ length: 05BC

	.global Pal_SpinningArrow
Pal_SpinningArrow: @ 08319E88
	.incbin "fe6-base.gba", 0x319E88, (0x319EE8 - 0x319E88) @ length: 0060

	.global Img_Prep_08319EE8
Img_Prep_08319EE8: @ 08319EE8
	.incbin "fe6-base.gba", 0x319EE8, (0x31A088 - 0x319EE8) @ length: 01A0

	.global Img_Prep_0831A088
Img_Prep_0831A088: @ 0831A088
	.incbin "fe6-base.gba", 0x31A088, (0x31A248 - 0x31A088) @ length: 01C0

	.global Pal_Prep_0831A248
Pal_Prep_0831A248: @ 0831A248
	.incbin "fe6-base.gba", 0x31A248, (0x31A268 - 0x31A248) @ length: 0020

	.global Img_Prep_0831A268
Img_Prep_0831A268: @ 0831A268
	.incbin "fe6-base.gba", 0x31A268, (0x31AABC - 0x31A268) @ length: 0854

	.global Pal_Sio_0831AABC
Pal_Sio_0831AABC: @ 0831AABC
	.incbin "fe6-base.gba", 0x31AABC, (0x31AAFC - 0x31AABC) @ length: 0040

	.global Pal_PrepGoldPulse
Pal_PrepGoldPulse: @ 0831AAFC
	.incbin "fe6-base.gba", 0x31AAFC, (0x31AB1C - 0x31AAFC) @ length: 0020

	.global Img_Prep_0831AB1C
Img_Prep_0831AB1C: @ 0831AB1C
	.incbin "fe6-base.gba", 0x31AB1C, (0x31B068 - 0x31AB1C) @ length: 054C

	.global Pal_Prep_0831B068
Pal_Prep_0831B068: @ 0831B068
	.incbin "fe6-base.gba", 0x31B068, (0x31B0A8 - 0x31B068) @ length: 0040

	.global Img_MonologueBG
Img_MonologueBG: @ 0831B0A8
	.incbin "fe6-base.gba", 0x31B0A8, (0x320434 - 0x31B0A8) @ length: 538C

	.global Tsa_MonologueBG
Tsa_MonologueBG: @ 08320434
	.incbin "fe6-base.gba", 0x320434, (0x320436 - 0x320434) @ length: 0002

	.global Tsa_MonologueScrollingBG
Tsa_MonologueScrollingBG: @ 08320436
	.incbin "fe6-base.gba", 0x320436, (0x320D98 - 0x320436) @ length: 0962 (30 * 40 * 2)

	.global Pal_MonologueBG
Pal_MonologueBG: @ 08320D98
	.incbin "fe6-base.gba", 0x320D98, (0x320E18 - 0x320D98) @ length: 0080

	.global Img_VeriticalSpinningArrow
Img_VeriticalSpinningArrow: @ 08320E18
	.incbin "data/prep/Img_VeriticalSpinningArrow.4bpp.lz"

	.global Img_HorizontalSpinningArrow
Img_HorizontalSpinningArrow: @ 08320EEC
	.incbin "data/prep/Img_HorizontalSpinningArrow.4bpp.lz"

.short 0x70C

	.global Tsa_PrepLeftUnitInfo
Tsa_PrepLeftUnitInfo: @ 08320FCE
	.incbin "fe6-base.gba", 0x320FCE, (0x3210A0 - 0x320FCE) @ length: 00D2

	.global Tsa_UnitList_083210A0
Tsa_UnitList_083210A0: @ 083210A0
	.incbin "fe6-base.gba", 0x3210A0, (0x3215B8 - 0x3210A0) @ length: 0518

	.global Img_UnitList_Title
Img_UnitList_Title: @ 083215B8
	.incbin "data/unitlistscreen/Img_UnitList_Title.4bpp.lz"

	.global Pal_UnitList_Title
Pal_UnitList_Title: @ 08321EE4
	.incbin "data/unitlistscreen/Img_UnitList_Title.gbapal", 0, 0x20

	.incbin "fe6-base.gba", 0x321F04, (0x321F24 - 0x321F04)

	.global gUnk_Ui_Pal_08321F24
gUnk_Ui_Pal_08321F24: @ 08321F24
	.incbin "fe6-base.gba", 0x321F24, (0x321FA4 - 0x321F24) @ length: 0080

	.global Img_PrepWorldMap
Img_PrepWorldMap: @ 08321FA4
	.incbin "data/prep/Img_PrepWorldMap.4bpp.lz"

	.global Pal_PrepWorldMap
Pal_PrepWorldMap: @ 08326910
	.incbin "data/prep/Img_PrepWorldMap.gbapal", 0, 0x20

	.global Img_Prep_08326930
Img_Prep_08326930: @ 08326930
	.incbin "fe6-base.gba", 0x326930, (0x326E64 - 0x326930) @ length: 0534

	.global Pal_Prep_08326E64
Pal_Prep_08326E64: @ 08326E64
	.incbin "fe6-base.gba", 0x326E64, (0x326EE4 - 0x326E64) @ length: 0080

.short 0xF10 @ ?

	.global Tsa_Prep_08326EE6
Tsa_Prep_08326EE6: @ 08326EE6
	.incbin "fe6-base.gba", 0x326EE6, (0x327108 - 0x326EE6) @ length: 0222

	.global Pal_Prep_08327108
Pal_Prep_08327108: @ 08327108
	.incbin "fe6-base.gba", 0x327108, (0x327148 - 0x327108) @ length: 0040
