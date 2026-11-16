	.include "asm_proc.inc"
	.data

	.global ProcScr_OpInfoEnter
ProcScr_OpInfoEnter: @ 0868FEFC
	PROC_19
	PROC_CALL StartFastFadeFromBlack
	PROC_REPEAT WhileFadeExists
	PROC_SLEEP 1
	PROC_CALL OpInfoEnter_Init
	PROC_REPEAT OpInfoEnter_Loop_In
	PROC_REPEAT OpInfoEnter_Loop_Out
PROC_LABEL 4
	PROC_CALL OpInfoEnter_OnEnd
	PROC_END

	.global ProcScr_OpInfoView
ProcScr_OpInfoView: @ 0868FF4C
	PROC_19
	PROC_SLEEP 1
	PROC_CALL OpInfoView_Init
	PROC_REPEAT OpInfoView_Loop_FadeIn
	PROC_REPEAT OpInfoView_Loop_Display
	PROC_REPEAT OpInfoView_Loop_FadeOut
	PROC_END

	.global ProcScr_OpInfoIcon
ProcScr_OpInfoIcon: @ 0868FF84
	PROC_19
	PROC_SLEEP 1
	PROC_CALL OpInfoIcon_Init
	PROC_REPEAT OpInfoIcon_Loop_FadeIn
	PROC_REPEAT OpInfoIcon_LoopA
	PROC_REPEAT OpInfoIcon_LoopB
PROC_LABEL 4
	PROC_REPEAT OpInfoIcon_Loop_FadeOut
	PROC_END

	.global ProcScr_ClassDemoMain
ProcScr_ClassDemoMain: @ 0868FFCC
	PROC_SLEEP 0
	PROC_CALL ClassDemoMain_ExecEkrMainMini
	PROC_SLEEP 2
	PROC_REPEAT ClassDemoMain_Loop_Intro
	PROC_REPEAT ClassDemoMain_Loop_Main
	PROC_REPEAT ClassDemoMain_Block
PROC_LABEL 4
	PROC_CALL ClassDemoMain_OnEnd
	PROC_END

	.global ProcScr_ClassDemoStatus
ProcScr_ClassDemoStatus: @ 08690014
	PROC_19
	PROC_SLEEP 3
	PROC_CALL ClassDemoStatus_Init
	PROC_REPEAT ClassDemoStatus_Loop
PROC_LABEL 4
	PROC_CALL ClassDemoStatus_OnEnd
	PROC_END

	.global Sprite_ClassDemoGaugePip1
Sprite_ClassDemoGaugePip1:
	.incbin "fe6-base.gba", 0x69004C, (0x690054 - 0x69004C)

	.global Sprite_ClassDemoGaugePip2
Sprite_ClassDemoGaugePip2:
	.incbin "fe6-base.gba", 0x690054, (0x69005C - 0x690054)

	.global Sprite_ClassDemoGaugePip3
Sprite_ClassDemoGaugePip3:
	.incbin "fe6-base.gba", 0x69005C, (0x690064 - 0x69005C)

	.global Sprite_ClassDemoGaugePip4
Sprite_ClassDemoGaugePip4:
	.incbin "fe6-base.gba", 0x690064, (0x69006C - 0x690064)

	.global Sprites_ClassDemoGaugePips
Sprites_ClassDemoGaugePips: @ 0869006C
	.incbin "fe6-base.gba", 0x69006C, 0x10

	.global Sprite_OpInfo_0869007C
Sprite_OpInfo_0869007C:
	.incbin "fe6-base.gba", 0x69007C, (0x6900BC - 0x69007C)

	.global Sprites_OpInfo_086900BC
Sprites_OpInfo_086900BC: @ 086900BC
	.incbin "fe6-base.gba", 0x6900BC, (0x6900DC - 0x6900BC) @ length: 0020

	.global Sprite_OpInfo_086900DC
Sprite_OpInfo_086900DC: @ 086900DC
	.incbin "fe6-base.gba", 0x6900DC, (0x6900F0 - 0x6900DC) @ length: 0014

	.global Sprite_OpInfo_086900F0
Sprite_OpInfo_086900F0: @ 086900F0
	.incbin "fe6-base.gba", 0x6900F0, (0x6900F8 - 0x6900F0) @ length: 0008

	.global Sprite_OpInfo_086900F8
Sprite_OpInfo_086900F8: @ 086900F8
	.incbin "fe6-base.gba", 0x6900F8, (0x690100 - 0x6900F8) @ length: 0008

	.global Sprite_OpInfo_08690100
Sprite_OpInfo_08690100: @ 08690100
	.incbin "fe6-base.gba", 0x690100, (0x690288 - 0x690100) @ length: 0188

	.global Sprites_OpInfo_08690288
Sprites_OpInfo_08690288: @ 08690288
	.incbin "fe6-base.gba", 0x690288, (0x69056C - 0x690288) @ length: 02E4

	.global gUnk_0869056C
gUnk_0869056C: @ 0869056C
	.incbin "fe6-base.gba", 0x69056C, (0x69058C - 0x69056C) @ length: 0020

	.global OpClassDemo_BIDs
OpClassDemo_BIDs: @ 0869058C
	.incbin "fe6-base.gba", 0x69058C, (0x6905B0 - 0x69058C) @ length: 0024

	.global OpClassDemo_IntroMsgs
OpClassDemo_IntroMsgs: @ 086905B0
	.incbin "fe6-base.gba", 0x6905B0, (0x6905F8 - 0x6905B0) @ length: 0048

	.global gOpClassDemoBanimCtrl
gOpClassDemoBanimCtrl: @ 086905F8
	.incbin "fe6-base.gba", 0x6905F8, (0x6909A4 - 0x6905F8) @ length: 03AC
