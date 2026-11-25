	.include "asm_proc.inc"

	.data

	.global ProcScr_SIOCON
ProcScr_SIOCON: @ 085C9940
	.incbin "fe6-base.gba", 0x5C9940, (0x5C9968 - 0x5C9940) @ length: 0028

	.global ProcScr_SIOVSYNC
ProcScr_SIOVSYNC: @ 085C9968
	.incbin "fe6-base.gba", 0x5C9968, (0x5C9990 - 0x5C9968) @ length: 0028

	.global ProcScr_SIOMAIN
ProcScr_SIOMAIN: @ 085C9990
	.incbin "fe6-base.gba", 0x5C9990, (0x5C99B0 - 0x5C9990) @ length: 0020

	.global gUnk_Sio_085C99B0
gUnk_Sio_085C99B0: @ 085C99B0
	.incbin "fe6-base.gba", 0x5C99B0, (0x5C99C8 - 0x5C99B0) @ length: 0018

	.global gUnk_Sio_085C99C8
gUnk_Sio_085C99C8: @ 085C99C8
	.incbin "fe6-base.gba", 0x5C99C8, (0x5C99E0 - 0x5C99C8) @ length: 0018

	.global ProcScr_SioHOLD
ProcScr_SioHOLD: @ 085C99E0
	.incbin "fe6-base.gba", 0x5C99E0, (0x5C99F8 - 0x5C99E0) @ length: 0018

	.global gUnk_Sio_085C99F8
gUnk_Sio_085C99F8: @ 085C99F8
	.incbin "fe6-base.gba", 0x5C99F8, (0x5C9A08 - 0x5C99F8) @ length: 0010

	.global KeyList_SioSecretTeam
KeyList_SioSecretTeam: @ 085C9A08
	.short 0x20, 0x20, 0x10, 0x10, 0x200, 0x200, 0x8, -1

	.global gSioKeyList_PasswordScreenEN
gSioKeyList_PasswordScreenEN: @ 085C9A18
	.incbin "fe6-base.gba", 0x5C9A18, (0x5C9AC8 - 0x5C9A18) @ length: 00B0

	.global gSioTeamListConfigLut
gSioTeamListConfigLut: @ 085C9AC8
	.incbin "fe6-base.gba", 0x5C9AC8, (0x5C9AD4 - 0x5C9AC8) @ length: 000C

	.global gUnk_Sio_085C9AD4
gUnk_Sio_085C9AD4: @ 085C9AD4
	.incbin "fe6-base.gba", 0x5C9AD4, (0x5C9AE0 - 0x5C9AD4) @ length: 000C

	.global ProcScr_SioTeamList
ProcScr_SioTeamList: @ 085C9AE0
	PROC_SLEEP 0
PROC_LABEL 0
	PROC_CALL SioTeamList_Init
PROC_LABEL 1
	PROC_CALL SioTeamList_SetupGfx
	PROC_CALL FadeInBlackSpeed20
	PROC_SLEEP 0
	PROC_CALL func_fe6_0803EFA8
PROC_LABEL 2
	PROC_REPEAT SioTeamList_Loop_MainKeyHandler
PROC_LABEL 3
	PROC_REPEAT SioTeamList_Loop_SubSel
	PROC_GOTO 9
PROC_LABEL 4
	PROC_CALL func_fe6_0803EF9C
	PROC_CALL FadeInBlackWithCallBack_Speed20
	PROC_SLEEP 0
	PROC_CALL SioTeamList_StartUnitList
	PROC_REPEAT SioTeamList_WaitForUnitListScreen
	PROC_CALL SioTeamList_SetupGfx
	PROC_CALL FadeInBlackSpeed20
	PROC_SLEEP 0
	PROC_CALL func_fe6_0803EFA8
	PROC_GOTO 2
PROC_LABEL 5
	PROC_REPEAT SioTeamList_SubSel_Switching
PROC_LABEL 6
	PROC_REPEAT func_fe6_08037E14
PROC_LABEL 7
	PROC_CALL SioTeamList_StartEraseTeamSubMenu
	PROC_REPEAT SioTeamList_EraseTeam_KeyHandler
	PROC_GOTO 3
PROC_LABEL 8
	PROC_CALL func_fe6_0803EF9C
	PROC_CALL FadeInBlackWithCallBack_Speed20
	PROC_SLEEP 0
	PROC_CALL SioTeamList_LoadTeam_Dummy
	PROC_SLEEP 0
	PROC_GOTO 1
PROC_LABEL 9
	PROC_CALL func_fe6_0803EF9C
	PROC_CALL FadeInBlackWithCallBack_Speed20
	PROC_SLEEP 0
	PROC_END

	.global ProcScr_Unk_085C9C40
ProcScr_Unk_085C9C40: @ 085C9C40
	PROC_SLEEP 0
	PROC_CALL Tactician_InitScreen
	PROC_CALL FadeInBlackSpeed20
	PROC_SLEEP 0
	PROC_CALL func_fe6_0803EFA8
PROC_LABEL 0
	PROC_REPEAT Tactician_Loop
	PROC_GOTO 2
PROC_LABEL 1
	PROC_CALL Tactician_SetHBlank
	PROC_REPEAT func_fe6_080388A4
	PROC_CALL func_fe6_080388E4
	PROC_REPEAT func_fe6_08038910
	PROC_GOTO 0
PROC_LABEL 3
	PROC_CALL NameSelect_DrawName
	PROC_REPEAT func_fe6_08038990
	PROC_GOTO 0
PROC_LABEL 2
	PROC_CALL func_fe6_0803EF9C
	PROC_CALL FadeInBlackWithCallBack_Speed20
	PROC_SLEEP 0
	PROC_END

	.global SpriteArray_Sio_085C9CF8
SpriteArray_Sio_085C9CF8: @ 085C9CF8
	.incbin "fe6-base.gba", 0x5C9CF8, (0x5C9D08 - 0x5C9CF8) @ length: 0010

	.global SpriteArray_Sio_085C9D08
SpriteArray_Sio_085C9D08: @ 085C9D08
	.incbin "fe6-base.gba", 0x5C9D08, (0x5C9D18 - 0x5C9D08) @ length: 0010

	.global ProcScr_LinkArenaPostBattle_DrawSprites
ProcScr_LinkArenaPostBattle_DrawSprites: @ 085C9D18
	.incbin "fe6-base.gba", 0x5C9D18, (0x5C9D98 - 0x5C9D18) @ length: 0080

	.global ProcScr_SioPostBattle_PlayMusic
ProcScr_SioPostBattle_PlayMusic: @ 085C9D98
	.incbin "fe6-base.gba", 0x5C9D98, (0x5C9DC0 - 0x5C9D98) @ length: 00F0

	.global ProcScr_SIOPRA
ProcScr_SIOPRA:
	.incbin "fe6-base.gba", 0x5C9DC0, (0x5C9E88 - 0x5C9DC0)

	.global gUnk_Sio_085C9E88
gUnk_Sio_085C9E88: @ 085C9E88
	.incbin "fe6-base.gba", 0x5C9E88, (0x5C9EA8 - 0x5C9E88) @ length: 0020

	.global gUnk_Sio_085C9EA8
gUnk_Sio_085C9EA8: @ 085C9EA8
	.incbin "fe6-base.gba", 0x5C9EA8, (0x5C9EAC - 0x5C9EA8) @ length: 04BC

	.global ProcScr_SIOBAT
ProcScr_SIOBAT:
	.incbin "fe6-base.gba", 0x5C9EAC, (0x5CA1A4 - 0x5C9EAC)

	.global ProcScr_SIOTERM
ProcScr_SIOTERM:
	.incbin "fe6-base.gba", 0x5CA1A4, (0x5CA30C - 0x5CA1A4)

	.global ProcScr_SIORESULT
ProcScr_SIORESULT:
	.incbin "fe6-base.gba", 0x5CA30C, (0x5CA364 - 0x5CA30C)

	.global ProcScr_SIORESULT_NewHighScore
ProcScr_SIORESULT_NewHighScore: @ 085CA364
	.incbin "fe6-base.gba", 0x5CA364, (0x5CA3BC - 0x5CA364) @ length: 00A0

	.global ProcScr_SIO_RuleSettings
ProcScr_SIO_RuleSettings:
	.incbin "fe6-base.gba", 0x5CA3BC, (0x5CA404 - 0x5CA3BC)

	.global gUnk_Sio_085CA404
gUnk_Sio_085CA404: @ 085CA404
	.incbin "fe6-base.gba", 0x5CA404, (0x5CA424 - 0x5CA404) @ length: 0020

	.global gUnk_Sio_085CA424
gUnk_Sio_085CA424: @ 085CA424
	.incbin "fe6-base.gba", 0x5CA424, (0x5CA444 - 0x5CA424) @ length: 0020

	.global ProcScr_SIOMENU
ProcScr_SIOMENU: @ 085CA444
	.incbin "fe6-base.gba", 0x5CA444, (0x5CA504 - 0x5CA444) @ length: 00C0

	.global EventScr_SioXMapTransfer
EventScr_SioXMapTransfer: @ 085CA504
	.incbin "fe6-base.gba", 0x5CA504, (0x5CA638 - 0x5CA504) @ length: 0134

	.global ProcScr_SioMenuBurstFx
ProcScr_SioMenuBurstFx: @ 085CA638
	.incbin "fe6-base.gba", 0x5CA638, (0x5CA6B8 - 0x5CA638) @ length: 0080

	.global EventScr_SioXmap_085CA6B8
EventScr_SioXmap_085CA6B8: @ 085CA6B8
	.incbin "fe6-base.gba", 0x5CA6B8, (0x5CA6F4 - 0x5CA6B8) @ length: 003C

	.global ProcScr_LinkArenaPointsBox
ProcScr_LinkArenaPointsBox: @ 085CA6F4
	.incbin "fe6-base.gba", 0x5CA6F4, (0x5CA70C - 0x5CA6F4) @ length: 0018

	.global gUnk_Sio_085CA70C
gUnk_Sio_085CA70C: @ 085CA70C
	.incbin "fe6-base.gba", 0x5CA70C, (0x5CA72C - 0x5CA70C) @ length: 0020

	.global gUnk_Sio_085CA72C
gUnk_Sio_085CA72C: @ 085CA72C
	.incbin "fe6-base.gba", 0x5CA72C, (0x5CA752 - 0x5CA72C) @ length: 0026

	.global gUnk_Sio_085CA752
gUnk_Sio_085CA752: @ 085CA752
	.incbin "fe6-base.gba", 0x5CA752, (0x5CA778 - 0x5CA752) @ length: 0026

	.global ProcScr_LinkArena_PointsNumberMover
ProcScr_LinkArena_PointsNumberMover: @ 085CA778
	.incbin "fe6-base.gba", 0x5CA778, (0x5CA7B8 - 0x5CA778) @ length: 0040

	.global ProcScr_LinkArena_PointsSpriteText
ProcScr_LinkArena_PointsSpriteText: @ 085CA7B8
	.incbin "fe6-base.gba", 0x5CA7B8, (0x5CA7E0 - 0x5CA7B8) @ length: 0028

	.global gUnk_Sio_085CA7E0
gUnk_Sio_085CA7E0: @ 085CA7E0
	.incbin "fe6-base.gba", 0x5CA7E0, (0x5CA7E4 - 0x5CA7E0) @ length: 0004

	.global gUnk_Sio_085CA7E4
gUnk_Sio_085CA7E4: @ 085CA7E4
	.incbin "fe6-base.gba", 0x5CA7E4, (0x5CA834 - 0x5CA7E4) @ length: 0050

	.global gUnk_Sio_085CA834
gUnk_Sio_085CA834: @ 085CA834
	.incbin "fe6-base.gba", 0x5CA834, (0x5CA884 - 0x5CA834) @ length: 0050

	.global gUnk_Sio_085CA884
gUnk_Sio_085CA884: @ 085CA884
	.incbin "fe6-base.gba", 0x5CA884, (0x5CA8A4 - 0x5CA884) @ length: 0020

	.global gUnk_Sio_085CA8A4
gUnk_Sio_085CA8A4: @ 085CA8A4
	.incbin "fe6-base.gba", 0x5CA8A4, (0x5CA8B4 - 0x5CA8A4) @ length: 0010

	.global gUnk_Sio_085CA8B4
gUnk_Sio_085CA8B4: @ 085CA8B4
	.incbin "fe6-base.gba", 0x5CA8B4, (0x5CA8D4 - 0x5CA8B4) @ length: 0020

	.global gUnk_Sio_085CA8D4
gUnk_Sio_085CA8D4: @ 085CA8D4
	.incbin "fe6-base.gba", 0x5CA8D4, (0x5CA93C - 0x5CA8D4) @ length: 0068

	.global gUnk_Sio_085CA93C
gUnk_Sio_085CA93C: @ 085CA93C
	.incbin "fe6-base.gba", 0x5CA93C, (0x5CA958 - 0x5CA93C) @ length: 001C

	.global gUnk_Sio_085CA958
gUnk_Sio_085CA958: @ 085CA958
	.incbin "fe6-base.gba", 0x5CA958, (0x5CA974 - 0x5CA958) @ length: 001C

	.global gUnk_Sio_085CA974
gUnk_Sio_085CA974: @ 085CA974
	.incbin "fe6-base.gba", 0x5CA974, (0x5CAB24 - 0x5CA974) @ length: 01B0

	.global gUnk_Sio_085CAB24
gUnk_Sio_085CAB24: @ 085CAB24
	.incbin "fe6-base.gba", 0x5CAB24, (0x5CAC14 - 0x5CAB24) @ length: 00F0

	.global gUnk_Sio_085CAC14
gUnk_Sio_085CAC14: @ 085CAC14
	.incbin "fe6-base.gba", 0x5CAC14, (0x5CAD04 - 0x5CAC14) @ length: 00F0

	.global ProcScr_SIOMAIN2
ProcScr_SIOMAIN2: @ 085CAD04
	.incbin "fe6-base.gba", 0x5CAD04, (0x5CADA4 - 0x5CAD04) @ length: 00A0

	.global gUnk_Sio_085CADA4
gUnk_Sio_085CADA4: @ 085CADA4
	.incbin "fe6-base.gba", 0x5CADA4, (0x5CADFC - 0x5CADA4) @ length: 0058

	.global gUnk_Sio_085CADFC
gUnk_Sio_085CADFC: @ 085CADFC
	.incbin "fe6-base.gba", 0x5CADFC, (0x5CAE34 - 0x5CADFC) @ length: 0038

	.global gUnk_Sio_085CAE34
gUnk_Sio_085CAE34: @ 085CAE34
	.incbin "fe6-base.gba", 0x5CAE34, (0x5CAE6C - 0x5CAE34) @ length: 0038

	.global gUnk_Sio_085CAE6C
gUnk_Sio_085CAE6C: @ 085CAE6C
	.incbin "fe6-base.gba", 0x5CAE6C, (0x5CAE84 - 0x5CAE6C) @ length: 0018

	.global gUnk_Sio_085CAE84
gUnk_Sio_085CAE84: @ 085CAE84
	.incbin "fe6-base.gba", 0x5CAE84, (0x5CAE9C - 0x5CAE84) @ length: 0018

	.global gUnk_Sio_085CAE9C
gUnk_Sio_085CAE9C: @ 085CAE9C
	.incbin "fe6-base.gba", 0x5CAE9C, (0x5CAEB4 - 0x5CAE9C) @ length: 0018

	.global ProcScr_SIOWARP
ProcScr_SIOWARP: @ 085CAEB4
	.incbin "fe6-base.gba", 0x5CAEB4, (0x5CAEE4 - 0x5CAEB4) @ length: 0030

	.global ProcScr_SIOWARPFX
ProcScr_SIOWARPFX: @ 085CAEE4
	.incbin "fe6-base.gba", 0x5CAEE4, (0x5CAF5C - 0x5CAEE4) @ length: 0078

	.global ProcScr_SioWarpFxPartial
ProcScr_SioWarpFxPartial: @ 085CAF5C
	.incbin "fe6-base.gba", 0x5CAF5C, (0x5CAF9C - 0x5CAF5C) @ length: 0040

	.global ProcScr_LAButtonSpriteDraw
ProcScr_LAButtonSpriteDraw: @ 085CAF9C
	.incbin "fe6-base.gba", 0x5CAF9C, (0x5CAFB4 - 0x5CAF9C) @ length: 0018

	.global gUnk_Sio_085CAFB4
gUnk_Sio_085CAFB4: @ 085CAFB4
	.incbin "fe6-base.gba", 0x5CAFB4, (0x5CAFC4 - 0x5CAFB4) @ length: 0010

	.global gUnk_Sio_085CAFC4
gUnk_Sio_085CAFC4: @ 085CAFC4
	.incbin "fe6-base.gba", 0x5CAFC4, (0x5CAFE4 - 0x5CAFC4) @ length: 0020

	.global gUnk_Sio_085CAFE4
gUnk_Sio_085CAFE4: @ 085CAFE4
	.incbin "fe6-base.gba", 0x5CAFE4, (0x5CAFEC - 0x5CAFE4) @ length: 0008

	.global gUnk_Sio_085CAFEC
gUnk_Sio_085CAFEC: @ 085CAFEC
	.incbin "fe6-base.gba", 0x5CAFEC, (0x5CB00C - 0x5CAFEC) @ length: 0020

	.global gUnk_Sio_085CB00C
gUnk_Sio_085CB00C: @ 085CB00C
	.incbin "fe6-base.gba", 0x5CB00C, (0x5CB020 - 0x5CB00C) @ length: 0014

	.global gUnk_Sio_085CB020
gUnk_Sio_085CB020: @ 085CB020
	.incbin "fe6-base.gba", 0x5CB020, (0x5CB02C - 0x5CB020) @ length: 000C

	.global gUnk_Sio_085CB02C
gUnk_Sio_085CB02C: @ 085CB02C
	.incbin "fe6-base.gba", 0x5CB02C, (0x5CB044 - 0x5CB02C) @ length: 0018

	.global gUnk_Sio_085CB044
gUnk_Sio_085CB044: @ 085CB044
	.incbin "fe6-base.gba", 0x5CB044, (0x5CB07A - 0x5CB044) @ length: 0036

	.global gUnk_Sio_085CB07A
gUnk_Sio_085CB07A: @ 085CB07A
	.incbin "fe6-base.gba", 0x5CB07A, (0x5CB0B4 - 0x5CB07A) @ length: 003A

	.global gUnk_Sio_085CB0B4
gUnk_Sio_085CB0B4: @ 085CB0B4
	.incbin "fe6-base.gba", 0x5CB0B4, (0x5CB0BC - 0x5CB0B4) @ length: 0008

	.global gUnk_Sio_085CB0BC
gUnk_Sio_085CB0BC: @ 085CB0BC
	.incbin "fe6-base.gba", 0x5CB0BC, (0x5CB0D4 - 0x5CB0BC) @ length: 0018

	.global gUnk_Sio_085CB0D4
gUnk_Sio_085CB0D4: @ 085CB0D4
	.incbin "fe6-base.gba", 0x5CB0D4, (0x5CB0EC - 0x5CB0D4) @ length: 0018

	.global gUnk_Sio_085CB0EC
gUnk_Sio_085CB0EC: @ 085CB0EC
	.incbin "fe6-base.gba", 0x5CB0EC, (0x5CB0F4 - 0x5CB0EC) @ length: 0008

	.global gUnk_Sio_085CB0F4
gUnk_Sio_085CB0F4: @ 085CB0F4
	.incbin "fe6-base.gba", 0x5CB0F4, (0x5CB108 - 0x5CB0F4) @ length: 0014

	.global gUnk_Sio_085CB108
gUnk_Sio_085CB108: @ 085CB108
	.incbin "fe6-base.gba", 0x5CB108, (0x5CB120 - 0x5CB108) @ length: 0018

	.global gUnk_Sio_085CB120
gUnk_Sio_085CB120: @ 085CB120
	.incbin "fe6-base.gba", 0x5CB120, (0x5CB12C - 0x5CB120) @ length: 000C

	.global gUnk_Sio_085CB12C
gUnk_Sio_085CB12C: @ 085CB12C
	.incbin "fe6-base.gba", 0x5CB12C, (0x5CB144 - 0x5CB12C) @ length: 0018

	.global gUnk_Sio_085CB144
gUnk_Sio_085CB144: @ 085CB144
	.incbin "fe6-base.gba", 0x5CB144, (0x5CB15C - 0x5CB144) @ length: 0018

	.global gUnk_Sio_085CB15C
gUnk_Sio_085CB15C: @ 085CB15C
	.incbin "fe6-base.gba", 0x5CB15C, (0x5CB164 - 0x5CB15C) @ length: 0008

	.global gUnk_Sio_085CB164
gUnk_Sio_085CB164: @ 085CB164
	.incbin "fe6-base.gba", 0x5CB164, (0x5CB16C - 0x5CB164) @ length: 0008

	.global gUnk_Sio_085CB16C
gUnk_Sio_085CB16C: @ 085CB16C
	.incbin "fe6-base.gba", 0x5CB16C, (0x5CB174 - 0x5CB16C) @ length: 0008

	.global gUnk_Sio_085CB174
gUnk_Sio_085CB174: @ 085CB174
	.incbin "fe6-base.gba", 0x5CB174, (0x5CB1E4 - 0x5CB174) @ length: 0070

	.global SpriteArray_LAVersusPlayerNumbers
SpriteArray_LAVersusPlayerNumbers: @ 085CB1E4
	.incbin "fe6-base.gba", 0x5CB1E4, (0x5CB1F4 - 0x5CB1E4) @ length: 0010

	.global ProcScr_LAVersusSpriteDraw
ProcScr_LAVersusSpriteDraw: @ 085CB1F4
	.incbin "fe6-base.gba", 0x5CB1F4, (0x5CB204 - 0x5CB1F4) @ length: 0010

