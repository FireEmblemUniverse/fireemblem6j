	.include "asm_proc.inc"
	.data

	.global ProcScr_OpAnim6
ProcScr_OpAnim6: @ 08691E48
	PROC_MARK 9
	PROC_CALL OpAnim6_StartBGM
	PROC_CALL OpAnim6_PutThunderStormGfx
	PROC_SLEEP 30
	PROC_REPEAT OpAnim6_StartThunderStorm
	PROC_SLEEP 6
	PROC_CALL OpAnim6_PutIdunnGfx
	PROC_SLEEP 1
	PROC_CALL func_fe6_0809AD3C
	PROC_SLEEP 0
	PROC_CALL func_fe6_0809AD64
	PROC_SLEEP 30
	PROC_CALL RemoveOpAnimText
	PROC_END

	.global ProcScr_OpAnimThunderStorm
ProcScr_OpAnimThunderStorm: @ 08691EB8
	PROC_CALL OpAnimThunderStorm_Init
	PROC_SLEEP 1
	PROC_CALL OpAnimThunderStorm_PutPal1
	PROC_SLEEP 0
	PROC_CALL OpAnimThunderStorm_PutPal2
	PROC_SLEEP 0
	PROC_CALL OpAnimThunderStorm_PutPal3
	PROC_SLEEP 0
	PROC_CALL OpAnimThunderStorm_PutPal4
	PROC_SLEEP 0
	PROC_CALL OpAnimThunderStorm_PutPal5
	PROC_END

	.global ProcScr_OpAnim5
ProcScr_OpAnim5: @ 08691F18
	PROC_MARK 9
	PROC_CALL func_fe6_0809AD88
	PROC_START_CHILD ProcScr_Unk_08692060
	PROC_SLEEP 0
	PROC_CALL func_fe6_0809ADCC
	PROC_START_CHILD 0x08691810
	PROC_SLEEP 1
	PROC_CALL func_fe6_0809AE60
	PROC_CALL FadeInBlackSpeed08Unk
	PROC_SLEEP 0
	PROC_SLEEP 30
	PROC_CALL PutOpAnimSubtitle4
	PROC_SLEEP 80
	PROC_BREAK_EACH ProcScr_Unk_08692060
	PROC_SLEEP 180
	PROC_START_CHILD 0x08691810
	PROC_CALL FadeInBlackWithCallBack_Speed08
	PROC_CALL func_fe6_08099644
	PROC_SLEEP 0
	PROC_CALL RemoveOpAnimText
	PROC_SLEEP 60
	PROC_CALL PutOpAnimSubtitle5
	PROC_SLEEP 290
	PROC_CALL FadeInBlackWithCallBack_Speed04
	PROC_SLEEP 0
	PROC_CALL RemoveOpAnimText
	PROC_SLEEP 30
	PROC_END

	.global ProcScr_Unk_08691FF8
ProcScr_Unk_08691FF8: @ 08691FF8
	PROC_MARK 9
	PROC_START_CHILD ProcScr_Unk_08692090
	PROC_CALL func_fe6_0809AF30
	PROC_CALL FadeInBlackSpeed08
	PROC_SLEEP 0
	PROC_START_CHILD 0x08692078
	PROC_SLEEP 60
	PROC_CALL PutOpAnimSubtitle5
	PROC_SLEEP 300
	PROC_CALL FadeInBlackWithCallBack_Speed08
	PROC_SLEEP 0
	PROC_CALL RemoveOpAnimText
	PROC_END

	.global ProcScr_Unk_08692060
ProcScr_Unk_08692060: @ 08692060
	PROC_CALL func_fe6_0809AF74
	PROC_REPEAT func_fe6_0809AF84
	PROC_REPEAT func_fe6_0809AFE4
	PROC_CALL func_fe6_0809B01C
	PROC_REPEAT func_fe6_0809B024
	PROC_END

	.global ProcScr_Unk_08692090
ProcScr_Unk_08692090: @ 08692090
	PROC_CALL func_fe6_0809B094
	PROC_REPEAT func_fe6_0809B0A4

	.global BgConf_OpAnim_086920A0
BgConf_OpAnim_086920A0: @ 086920A0
	.incbin "fe6-base.gba", 0x6920A0, (0x6920B8 - 0x6920A0) @ length: 0018

	.global BgConf_OpAnim_086920B8
BgConf_OpAnim_086920B8: @ 086920B8
	.incbin "fe6-base.gba", 0x6920B8, (0x6920D0 - 0x6920B8)

	.global ProcScr_OpAnim_Nintendo
ProcScr_OpAnim_Nintendo: @ 086920D0
	PROC_MARK 9
	PROC_CALL func_fe6_0809B280
	PROC_CALL FadeInBlackSpeed10
	PROC_SLEEP 0
	PROC_SLEEP 220
	PROC_CALL FadeInBlackWithCallBack_Speed10
	PROC_SLEEP 0
	PROC_CALL RemoveOpAnimText
	PROC_END

	.global gTitleDuration
gTitleDuration: @ 08692118
	.4byte 0x348

	.global gTitleSwordSlideInDuration
gTitleSwordSlideInDuration: @ 0869211C
	.4byte 0x1E

	.global gTitleLogoFadeInDuration
gTitleLogoFadeInDuration: @ 08692120
	.4byte 0x1E

	.global gTitleLogoShadowDuration
gTitleLogoShadowDuration: @ 08692124
	.4byte 0x20

	.global gTitleLensFlareDuration
gTitleLensFlareDuration: @ 08692128
	.4byte 0x30

	.global gTitleSwordDelay
gTitleSwordDelay: @ 0869212C
	.4byte 0x10

	.global ProcScr_TitleScreenFromOp
ProcScr_TitleScreenFromOp: @ 08692130
	PROC_MARK 9
	PROC_ONEND Title_End
	PROC_CALL Title_EndIfOpAnimSkipped
	PROC_CALL Title_Init
	PROC_CALL StartMidFadeFromBlack
	PROC_REPEAT WhileFadeExists
	PROC_CALL Title_StartLogoFadeIn
	PROC_REPEAT Title_LogoFadeIn
	PROC_START_CHILD ProcScr_TitleLensFlare
	PROC_START_CHILD_LOCKING ProcScr_TitleSwordDelay
	PROC_START_CHILD_LOCKING ProcScr_TitleSwordSlideIn
	PROC_SLEEP 0
	PROC_CALL Title_InitDisp
	PROC_END_EACH ProcScr_TitleLensFlare
	PROC_CALL Title_PlayRevealSe
	PROC_CALL Title_StartBgm
	PROC_CALL func_fe6_08014934
	PROC_SLEEP 0
	PROC_CALL Title_ReinitTimer
	PROC_REPEAT Title_Idle
	PROC_CALL FadeInBlackWithCallBack_Speed20
	PROC_SLEEP 0
	PROC_END
