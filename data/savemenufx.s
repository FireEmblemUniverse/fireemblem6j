	.data

	.global Sprite_SaveMenuLabelResume
Sprite_SaveMenuLabelResume:	@ 0x68A348
	.incbin "fe6-base.gba", 0x68A348, 0x68A362 - 0x68A348

	.global Sprite_SaveMenuLabelContinue
Sprite_SaveMenuLabelContinue:	@ 0x68A362
	.incbin "fe6-base.gba", 0x68A362, 0x68A37C - 0x68A362

	.global Sprite_SaveMenuLabelCopy
Sprite_SaveMenuLabelCopy:	@ 0x68A37C
	.incbin "fe6-base.gba", 0x68A37C, 0x68A390 - 0x68A37C

	.global Sprite_SaveMenuLabelErase
Sprite_SaveMenuLabelErase:	@ 0x68A390
	.incbin "fe6-base.gba", 0x68A390, 0x68A3A4 - 0x68A390

	.global Sprite_SaveMenuLabelNewGame
Sprite_SaveMenuLabelNewGame:	@ 0x68A3A4
	.incbin "fe6-base.gba", 0x68A3A4, 0x68A3BE - 0x68A3A4

	.global Sprite_SaveMenuLabelExtra
Sprite_SaveMenuLabelExtra:	@ 0x68A3BE
	.incbin "fe6-base.gba", 0x68A3BE, 0x68A3D2 - 0x68A3BE

	.global Sprite_SaveMenuLabelSave
Sprite_SaveMenuLabelSave:	@ 0x68A3D2
	.incbin "fe6-base.gba", 0x68A3D2, 0x68A3E0 - 0x68A3D2

	.global Sprite_SaveMenuLabelTrialMap
Sprite_SaveMenuLabelTrialMap:	@ 0x68A3E0
	.incbin "fe6-base.gba", 0x68A3E0, 0x68A3FA - 0x68A3E0

	.global Sprite_SaveMenuLabelLinkArena
Sprite_SaveMenuLabelLinkArena:	@ 0x68A3FA
	.incbin "fe6-base.gba", 0x68A3FA, 0x68A414 - 0x68A3FA

	.global Sprite_SaveMenuLabelTutorial
Sprite_SaveMenuLabelTutorial:	@ 0x68A414
	.incbin "fe6-base.gba", 0x68A414, 0x68A42E - 0x68A414

	.global Sprite_SaveMenuLabelSoundRoom
Sprite_SaveMenuLabelSoundRoom:	@ 0x68A42E
	.incbin "fe6-base.gba", 0x68A42E, 0x68A448 - 0x68A42E

	.global Sprite_SaveMenuSlotTitleBg1
Sprite_SaveMenuSlotTitleBg1:	@ 0x68A448
	.incbin "fe6-base.gba", 0x68A448, 0x68A45C - 0x68A448

	.global Sprite_SaveMenuSlotTitleBg2
Sprite_SaveMenuSlotTitleBg2:	@ 0x68A45C
	.incbin "fe6-base.gba", 0x68A45C, 0x68A470 - 0x68A45C

	.global Sprite_SaveMenuSlotTitleBg3
Sprite_SaveMenuSlotTitleBg3:	@ 0x68A470
	.incbin "fe6-base.gba", 0x68A470, 0x68A484 - 0x68A470

	.global Sprite_SaveMenuSlotTitleText1
Sprite_SaveMenuSlotTitleText1:	@ 0x68A484
	.incbin "fe6-base.gba", 0x68A484, 0x68A4AA - 0x68A484

	.global Sprite_SaveMenuSlotTitleText2
Sprite_SaveMenuSlotTitleText2:	@ 0x68A4AA
	.incbin "fe6-base.gba", 0x68A4AA, 0x68A4D0 - 0x68A4AA

	.global Sprite_SaveMenuSlotTitleText3
Sprite_SaveMenuSlotTitleText3:	@ 0x68A4D0
	.incbin "fe6-base.gba", 0x68A4D0, 0x68A4F8 - 0x68A4D0

	.global Sprites_SaveMenuExtraLabels
Sprites_SaveMenuExtraLabels: @ 0868A4F8
	.4byte Sprite_SaveMenuLabelTrialMap
	.4byte 0x00000000
	.4byte Sprite_SaveMenuLabelLinkArena
	.4byte 0x00000000
	.4byte Sprite_SaveMenuLabelTutorial
	.4byte 0x00000000
	.4byte Sprite_SaveMenuLabelSoundRoom
	.4byte 0x00000000

	.global Sprites_SaveMenuActionLabels
Sprites_SaveMenuActionLabels: @ 0868A518
	.4byte Sprite_SaveMenuLabelResume
	.4byte 0x00000000
	.4byte Sprite_SaveMenuLabelContinue
	.4byte 0x00000000
	.4byte Sprite_SaveMenuLabelCopy
	.4byte 0x00000010
	.4byte Sprite_SaveMenuLabelErase
	.4byte 0x00000010
	.4byte Sprite_SaveMenuLabelNewGame
	.4byte 0x00000000
	.4byte Sprite_SaveMenuLabelExtra
	.4byte 0x00000010
	.4byte Sprite_SaveMenuLabelSave
	.4byte 0x00000018

	.global Sprites_SaveMenuSlotTitleText
Sprites_SaveMenuSlotTitleText: @ 0868A550
	.4byte Sprite_SaveMenuSlotTitleText1
	.4byte Sprite_SaveMenuSlotTitleText2
	.4byte Sprite_SaveMenuSlotTitleText3

	.global Sprites_SaveMenuSlotTitleBg
Sprites_SaveMenuSlotTitleBg: @ 0868A55C
	.4byte Sprite_SaveMenuSlotTitleBg1
	.4byte Sprite_SaveMenuSlotTitleBg2
	.4byte Sprite_SaveMenuSlotTitleBg3
