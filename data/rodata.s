	.section .rodata

	.global Img_MuralBackground
Img_MuralBackground: @ 08336D5C
	.incbin "fe6-base.gba", 0x336D5C, (0x33B958 - 0x336D5C) @ length: 4BFC

	.global Img_0833B958
Img_0833B958: @ 0833B958
	.incbin "fe6-base.gba", 0x33B958, (0x33BB14 - 0x33B958) @ length: 01BC

	.global Img_0833BB14
Img_0833BB14: @ 0833BB14
	.incbin "fe6-base.gba", 0x33BB14, (0x33BB28 - 0x33BB14) @ length: 0014

	.global Img_0833BB28
Img_0833BB28: @ 0833BB28
	.incbin "fe6-base.gba", 0x33BB28, (0x33BE84 - 0x33BB28) @ length: 035C

	.global Tsa_0833BE84
Tsa_0833BE84: @ 0833BE84
	.incbin "fe6-base.gba", 0x33BE84, (0x33BF08 - 0x33BE84) @ length: 0084

	.global Tsa_0833BF08
Tsa_0833BF08: @ 0833BF08
	.incbin "fe6-base.gba", 0x33BF08, (0x33BFDC - 0x33BF08) @ length: 00D4

	.global Pal_MuralBackground
Pal_MuralBackground: @ 0833BFDC
	.incbin "fe6-base.gba", 0x33BFDC, (0x33C01C - 0x33BFDC) @ length: 0040

	.global Pal_0833C01C
Pal_0833C01C: @ 0833C01C
	.incbin "fe6-base.gba", 0x33C01C, (0x33C03C - 0x33C01C) @ length: 0020

	.global Pal_PlayRankTimeOBJ
Pal_PlayRankTimeOBJ: @ 0833C03C
	.incbin "fe6-base.gba", 0x33C03C, (0x33C09C - 0x33C03C) @ length: 0060

	.global Img_0833C09C
Img_0833C09C: @ 0833C09C
	.incbin "fe6-base.gba", 0x33C09C, (0x33C1D8 - 0x33C09C) @ length: 013C

	.global Tsa_0833C1D8
Tsa_0833C1D8: @ 0833C1D8
	.incbin "fe6-base.gba", 0x33C1D8, (0x33C234 - 0x33C1D8) @ length: 005C

	.global Tsa_0833C234
Tsa_0833C234: @ 0833C234
	.incbin "fe6-base.gba", 0x33C234, (0x33C378 - 0x33C234) @ length: 0144

	.global Img_StatusScreen_Bg
Img_StatusScreen_Bg: @ 0833C378
	.incbin "fe6-base.gba", 0x33C378, (0x33C6F4 - 0x33C378) @ length: 037C

	.global Tsa_StatusScreen_FactionInfoBg
Tsa_StatusScreen_FactionInfoBg: @ 0833C6F4
	.incbin "fe6-base.gba", 0x33C6F4, (0x33C8D8 - 0x33C6F4) @ length: 01E4

	.global Tsa_StatusScreen_PlaytimeBg
Tsa_StatusScreen_PlaytimeBg: @ 0833C8D8
	.incbin "fe6-base.gba", 0x33C8D8, (0x33C944 - 0x33C8D8) @ length: 006C

	.global Pal_StatusScreen_Bg
Pal_StatusScreen_Bg: @ 0833C944
	.incbin "fe6-base.gba", 0x33C944, (0x33C984 - 0x33C944) @ length: 0040

	.global Img_WorldMap_PlayRank
Img_WorldMap_PlayRank: @ 0833C984
	.incbin "fe6-base.gba", 0x33C984, (0x340ED8 - 0x33C984) @ length: 4554

	.global Tsa_08340ED8
Tsa_08340ED8: @ 08340ED8
	.incbin "fe6-base.gba", 0x340ED8, (0x34138C - 0x340ED8) @ length: 04B4

	.global Pal_PlayRankWmBG
Pal_PlayRankWmBG: @ 0834138C
	.incbin "fe6-base.gba", 0x34138C, (0x3413CC - 0x34138C) @ length: 0040

	.global Img_PlayRankFogBG
Img_PlayRankFogBG: @ 083413CC
	.incbin "fe6-base.gba", 0x3413CC, (0x341DA0 - 0x3413CC) @ length: 09D4

	.global Pal_PlayRankFogBG
Pal_PlayRankFogBG: @ 08341DA0
	.incbin "fe6-base.gba", 0x341DA0, (0x341DC0 - 0x341DA0) @ length: 0020

	.global Img_PlayRank
Img_PlayRank: @ 08341DC0
	.incbin "fe6-base.gba", 0x341DC0, (0x342438 - 0x341DC0) @ length: 0678

	.global Img_PlayRankCharacters
Img_PlayRankCharacters: @ 08342438
	.incbin "fe6-base.gba", 0x342438, (0x342A98 - 0x342438) @ length: 0660

	.global Pal_08342A98
Pal_08342A98: @ 08342A98
	.incbin "fe6-base.gba", 0x342A98, (0x342AB8 - 0x342A98) @ length: 0020

	.global Pal_08342AB8
Pal_08342AB8: @ 08342AB8
	.incbin "fe6-base.gba", 0x342AB8, (0x342AD8 - 0x342AB8) @ length: 0020

	.global Pal_08342AD8
Pal_08342AD8: @ 08342AD8
	.incbin "fe6-base.gba", 0x342AD8, (0x342AF8 - 0x342AD8) @ length: 0020

	.global Tsa_08342AF8
Tsa_08342AF8: @ 08342AF8
	.incbin "fe6-base.gba", 0x342AF8, (0x342B54 - 0x342AF8) @ length: 005C

	.global Img_PlayRankMissionCompletesOBJ
Img_PlayRankMissionCompletesOBJ: @ 08342B54
	.incbin "fe6-base.gba", 0x342B54, (0x343358 - 0x342B54) @ length: 0804

	.global Pal_PlayRankMissionCompletesOBJ
Pal_PlayRankMissionCompletesOBJ: @ 08343358
	.incbin "fe6-base.gba", 0x343358, (0x343398 - 0x343358) @ length: 0040

	.global Img_CreditGlyph_Cap
Img_CreditGlyph_Cap: @ 08343398
	.incbin "fe6-base.gba", 0x343398, (0x343A80 - 0x343398) @ length: 06E8

	.global Img_CreditGlyph_Low
Img_CreditGlyph_Low: @ 08343A80
	.incbin "fe6-base.gba", 0x343A80, (0x343FAC - 0x343A80) @ length: 052C

	.global Img_CreditGlyph_Narrow
Img_CreditGlyph_Narrow: @ 08343FAC
	.incbin "fe6-base.gba", 0x343FAC, (0x3442C4 - 0x343FAC) @ length: 0318

	.global Pal_CreditCharacterGlyph
Pal_CreditCharacterGlyph: @ 083442C4
	.incbin "fe6-base.gba", 0x3442C4, (0x344304 - 0x3442C4) @ length: 0040

	.global Img_EndingFighterText
Img_EndingFighterText: @ 08344304
	.incbin "fe6-base.gba", 0x344304, (0x3449F8 - 0x344304) @ length: 06F4

	.global Img_Fin
Img_Fin: @ 083449F8
	.incbin "data/GameEnding/Img_Fin_len26.4bpp.lz"

	.global Pal_Fin
Pal_Fin: @ 08344CB0
	.incbin "data/GameEnding/Img_Fin_len26.gbapal", 0, 0x20

	.global Img_Ending_CopyRight
Img_Ending_CopyRight: @ 08344CD0
	.incbin "fe6-base.gba", 0x344CD0, (0x34523C - 0x344CD0) @ length: 056C

	.global Tsa_Ending_CopyRight
Tsa_Ending_CopyRight: @ 0834523C
	.incbin "fe6-base.gba", 0x34523C, (0x345420 - 0x34523C) @ length: 01E4

	.global Pal_Ending_CopyRight
Pal_Ending_CopyRight: @ 08345420
	.incbin "fe6-base.gba", 0x345420, (0x345440 - 0x345420) @ length: 0020

	.global Tsa_EndingPInfoBG
Tsa_EndingPInfoBG: @ 08345440
	.incbin "fe6-base.gba", 0x345440, (0x345934 - 0x345440) @ length: 04F4

	.global Img_EndingPInfoWindow
Img_EndingPInfoWindow: @ 08345934
	.incbin "fe6-base.gba", 0x345934, (0x346184 - 0x345934) @ length: 0850

	.global Pal_EndingPInfoWindow
Pal_EndingPInfoWindow: @ 08346184
	.incbin "fe6-base.gba", 0x346184, (0x3461C4 - 0x346184) @ length: 0040

	.global Tsa_GameRank_083461C4
Tsa_GameRank_083461C4: @ 083461C4
	.incbin "fe6-base.gba", 0x3461C4, (0x346330 - 0x3461C4) @ length: 016C

	.global Tsa_GameRank_08346330
Tsa_GameRank_08346330: @ 08346330
	.incbin "fe6-base.gba", 0x346330, (0x3463B4 - 0x346330) @ length: 0084

	.global Tsa_GameRank_083463B4
Tsa_GameRank_083463B4: @ 083463B4
	.incbin "fe6-base.gba", 0x3463B4, (0x3463F4 - 0x3463B4) @ length: 0040

	.global Tsa_GameRank_083463F4
Tsa_GameRank_083463F4: @ 083463F4
	.incbin "fe6-base.gba", 0x3463F4, (0x346574 - 0x3463F4) @ length: 0180
