	.include "macro.inc"

	.syntax unified

	thumb_func_start Shop_HandleBuyConfirmPrompt
Shop_HandleBuyConfirmPrompt: @ 0x080964E0
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	bl GetTalkChoiceResult
	cmp r0, #1
	beq .L08096500
	cmp r0, #1
	bgt .L080964FA
	cmp r0, #0
	beq .L08096502
	b .L08096502
.L080964FA:
	cmp r0, #2
	beq .L08096502
	b .L08096502
.L08096500:
	b .L0809650C
.L08096502:
	ldr r0, [r7]
	movs r1, #1
	bl Proc_Goto
	b .L0809650C
.L0809650C:
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start Shop_TryAddItemToInventory
Shop_TryAddItemToInventory: @ 0x08096514
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5b
	ldrb r0, [r1]
	cmp r0, #4
	bls .L08096538
	ldr r1, .L08096534 @ =0x000002E7
	adds r0, r1, #0
	ldr r1, [r7]
	bl StartShopDialogue
	b .L08096562
	.align 2, 0
.L08096534: .4byte 0x000002E7
.L08096538:
	ldr r1, [r7]
	ldr r0, [r1, #0x2c]
	ldr r1, [r7]
	ldr r3, [r7]
	adds r2, r3, #0
	adds r3, #0x5c
	ldrb r2, [r3]
	adds r3, r2, #0
	lsls r2, r3, #1
	adds r1, #0x30
	adds r2, r1, r2
	ldrh r1, [r2]
	bl UnitAddItem
	ldr r0, [r7]
	bl HandleShopBuyAction
	ldr r0, [r7]
	movs r1, #3
	bl Proc_Goto
.L08096562:
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Shop_HandleSendToConvoyPrompt
Shop_HandleSendToConvoyPrompt: @ 0x0809656C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	bl GetTalkChoiceResult
	cmp r0, #1
	beq .L0809658C
	cmp r0, #1
	bgt .L08096586
	cmp r0, #0
	beq .L0809658E
	b .L0809658E
.L08096586:
	cmp r0, #2
	beq .L0809658E
	b .L0809658E
.L0809658C:
	b .L08096598
.L0809658E:
	ldr r0, [r7]
	movs r1, #0xb
	bl Proc_Goto
	b .L08096598
.L08096598:
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start Shop_NoSendToConvoyDialogue
Shop_NoSendToConvoyDialogue: @ 0x080965A0
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r1, .L080965BC @ =0x000002ED
	adds r0, r1, #0
	ldr r1, [r7]
	bl StartShopDialogue
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080965BC: .4byte 0x000002ED

	thumb_func_start Shop_AddItemToConvoy
Shop_AddItemToConvoy: @ 0x080965C0
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x5c
	ldrb r1, [r2]
	adds r2, r1, #0
	lsls r1, r2, #1
	adds r0, #0x30
	adds r1, r0, r1
	ldrh r2, [r1]
	adds r0, r2, #0
	bl AddSupplyItem
	ldr r0, [r7]
	bl HandleShopBuyAction
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start Shop_SendToConvoyDialogue
Shop_SendToConvoyDialogue: @ 0x080965F0
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r1, .L0809660C @ =0x000002EA
	adds r0, r1, #0
	ldr r1, [r7]
	bl StartShopDialogue
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0809660C: .4byte 0x000002EA

	thumb_func_start Shop_CheckIfConvoyFull
Shop_CheckIfConvoyFull: @ 0x08096610
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	bl CountSupplyItems
	cmp r0, #0x63
	bgt .L08096628
	ldr r0, [r7]
	movs r1, #0xa
	bl Proc_Goto
.L08096628:
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start Shop_ConvoyFullDialogue
Shop_ConvoyFullDialogue: @ 0x08096630
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r0, r1, #0
	ldr r1, [r7]
	bl StartShopDialogue
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start Shop_AnythingElseDialogue
Shop_AnythingElseDialogue: @ 0x0809664C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r1, .L08096668 @ =0x000002CF
	adds r0, r1, #0
	ldr r1, [r7]
	bl StartShopDialogue
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08096668: .4byte 0x000002CF

	thumb_func_start Shop_SellDialogue
Shop_SellDialogue: @ 0x0809666C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r1, .L08096688 @ =0x000002D2
	adds r0, r1, #0
	ldr r1, [r7]
	bl StartShopDialogue
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08096688: .4byte 0x000002D2

	thumb_func_start Shop_InitSellState
Shop_InitSellState: @ 0x0809668C
	push {r7, lr}
	sub sp, #0x10
	add r7, sp, #0xc
	str r0, [r7]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5c
	ldrb r0, [r1]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x5b
	ldrb r1, [r2]
	movs r2, #0x48
	str r2, [sp]
	ldr r2, .L080966C0 @ =ShopDrawSellItemLine
	str r2, [sp, #4]
	ldr r2, [r7]
	str r2, [sp, #8]
	movs r2, #5
	movs r3, #0
	bl RegisterShopState
	add sp, #0x10
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080966C0: .4byte ShopDrawSellItemLine

	thumb_func_start Shop_Loop_SellKeyHandler
Shop_Loop_SellKeyHandler: @ 0x080966C4
	push {r4, r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	adds r0, r7, #4
	movs r1, #0
	strb r1, [r0]
	bl Shop_TryMoveHandPage
	bl ShopSt_GetBg2Offset
	adds r1, r0, #0
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	movs r0, #2
	movs r1, #0
	bl SetBgOffset
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5c
	ldrb r0, [r1]
	adds r4, r0, #0
	bl ShopSt_GetHeadLoc
	lsls r2, r4, #0x10
	lsrs r1, r2, #0x10
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x10
	cmp r1, r0
	beq .L08096708
	adds r0, r7, #4
	movs r1, #1
	strb r1, [r0]
.L08096708:
	bl ShopSt_GetHeadLoc
	ldr r1, [r7]
	adds r2, r1, #0
	adds r1, #0x5c
	ldrb r2, [r1]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r0
	adds r0, r2, #0
	strb r0, [r1]
	bl ShopSt_GetHandLoc
	ldr r1, [r7]
	adds r2, r1, #0
	adds r1, #0x5d
	ldrb r2, [r1]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r0
	adds r0, r2, #0
	strb r0, [r1]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5c
	ldrb r0, [r1]
	adds r1, r0, #0
	lsls r0, r1, #4
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x5d
	ldrb r1, [r2]
	adds r2, r1, #0
	lsls r1, r2, #4
	adds r2, r1, #0
	subs r2, #0x48
	subs r1, r0, r2
	movs r0, #0x38
	bl PutUiHand
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x62
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080967B0
	adds r0, r7, #4
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	beq .L080967B0
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5c
	ldrb r0, [r1]
	adds r1, r0, #0
	lsls r0, r1, #4
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x5d
	ldrb r1, [r2]
	adds r2, r1, #0
	lsls r1, r2, #4
	adds r2, r1, #0
	subs r2, #0x48
	subs r1, r0, r2
	ldr r2, [r7]
	ldr r0, [r2, #0x2c]
	ldr r3, [r7]
	adds r2, r3, #0
	adds r3, #0x5c
	ldrb r2, [r3]
	adds r3, r2, #0
	lsls r2, r3, #1
	adds r0, #0x1c
	adds r3, r0, r2
	ldrh r2, [r3]
	movs r0, #0x38
	bl StartItemHelpBox
.L080967B0:
	bl IsShopPageScrolling
	lsls r1, r0, #0x18
	asrs r0, r1, #0x18
	cmp r0, #0
	beq .L080967BE
	b .L0809693C
.L080967BE:
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x62
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080967FE
	ldr r1, .L080967F8 @ =gKeySt
	ldr r0, [r1]
	ldrh r1, [r0, #8]
	movs r2, #0x81
	lsls r2, r2, #1
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L080967F6
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x62
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	bl CloseHelpBox
.L080967F6:
	b .L0809693C
	.align 2, 0
.L080967F8: .4byte gKeySt
.L080967FC:
	.byte 0x38, 0xE0
.L080967FE:
	ldr r1, .L0809686C @ =gKeySt
	ldr r0, [r1]
	ldrh r1, [r0, #8]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L08096870
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x62
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #1
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5c
	ldrb r0, [r1]
	adds r1, r0, #0
	lsls r0, r1, #4
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x5d
	ldrb r1, [r2]
	adds r2, r1, #0
	lsls r1, r2, #4
	adds r2, r1, #0
	subs r2, #0x48
	subs r1, r0, r2
	ldr r2, [r7]
	ldr r0, [r2, #0x2c]
	ldr r3, [r7]
	adds r2, r3, #0
	adds r3, #0x5c
	ldrb r2, [r3]
	adds r3, r2, #0
	lsls r2, r3, #1
	adds r0, #0x1c
	adds r3, r0, r2
	ldrh r2, [r3]
	movs r0, #0x38
	bl StartItemHelpBox
	b .L0809693C
	.align 2, 0
.L0809686C: .4byte gKeySt
.L08096870:
	ldr r1, .L080968C0 @ =gKeySt
	ldr r0, [r1]
	ldrh r1, [r0, #8]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L08096900
	ldr r1, [r7]
	ldr r0, [r1, #0x2c]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x5c
	ldrb r1, [r2]
	adds r2, r1, #0
	lsls r1, r2, #1
	adds r0, #0x1c
	adds r1, r0, r1
	ldrh r2, [r1]
	adds r0, r2, #0
	bl func_fe6_080975C8
	lsls r1, r0, #0x18
	asrs r0, r1, #0x18
	cmp r0, #0
	bne .L080968C4
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r1, #0
	ldr r1, [r7]
	bl StartShopDialogue
	ldr r0, [r7]
	movs r1, #4
	bl Proc_Goto
	b .L080968FA
	.align 2, 0
.L080968C0: .4byte gKeySt
.L080968C4:
	ldr r1, [r7]
	ldr r0, [r1, #0x2c]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x5c
	ldrb r1, [r2]
	adds r2, r1, #0
	lsls r1, r2, #1
	adds r0, #0x1c
	adds r1, r0, r1
	ldrh r2, [r1]
	adds r0, r2, #0
	bl func_fe6_080975A0
	lsls r2, r0, #0x10
	lsrs r1, r2, #0x10
	adds r0, r1, #0
	bl SetTalkNumber
	ldr r1, .L080968FC @ =0x000002DE
	adds r0, r1, #0
	ldr r1, [r7]
	bl StartShopDialogue
	ldr r0, [r7]
	bl Proc_Break
.L080968FA:
	b .L0809693C
	.align 2, 0
.L080968FC: .4byte 0x000002DE
.L08096900:
	ldr r1, .L08096934 @ =gKeySt
	ldr r0, [r1]
	ldrh r1, [r0, #8]
	movs r2, #2
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L0809693C
	ldr r0, .L08096938 @ =gPlaySt
	ldrb r1, [r0, #0x1d]
	lsls r2, r1, #0x1e
	lsrs r0, r2, #0x1f
	cmp r0, #0
	bne .L08096928
	movs r0, #0x6b
	bl m4aSongNumStart
.L08096928:
	ldr r0, [r7]
	movs r1, #8
	bl Proc_Goto
	b .L0809693C
	.align 2, 0
.L08096934: .4byte gKeySt
.L08096938: .4byte gPlaySt
.L0809693C:
	add sp, #8
	pop {r4, r7}
	pop {r0}
	bx r0

	thumb_func_start Shop_HandleSellConfirmPrompt
Shop_HandleSellConfirmPrompt: @ 0x08096944
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	bl GetTalkChoiceResult
	cmp r0, #1
	beq .L08096964
	cmp r0, #1
	bgt .L0809695E
	cmp r0, #0
	beq .L080969FA
	b .L080969FA
.L0809695E:
	cmp r0, #2
	beq .L080969FA
	b .L080969FA
.L08096964:
	movs r0, #0xb9
	movs r1, #8
	bl PlaySeDelayed
	ldr r0, .L080969F0 @ =gAction
	ldrb r1, [r0, #0x11]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x14
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0, #0x11]
	bl GetGold
	str r0, [r7, #4]
	ldr r1, [r7]
	ldr r0, [r1, #0x2c]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x5c
	ldrb r1, [r2]
	adds r2, r1, #0
	lsls r1, r2, #1
	adds r0, #0x1c
	adds r1, r0, r1
	ldrh r2, [r1]
	adds r0, r2, #0
	bl func_fe6_080975A0
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	ldr r1, [r7, #4]
	adds r0, r1, r0
	str r0, [r7, #4]
	ldr r1, [r7, #4]
	adds r0, r1, #0
	bl SetGold
	ldr r1, [r7]
	ldr r0, [r1, #0x2c]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x5c
	ldrb r1, [r2]
	bl UnitRemoveItem
	ldr r0, [r7]
	bl UpdateShopItemCounts
	ldr r0, [r7]
	bl ShopInitTexts_OnSell
	ldr r1, .L080969F4 @ =gBg0Tm+0x1B6
	adds r0, r1, #0
	bl DisplayGoldBoxText
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5b
	ldrb r0, [r1]
	cmp r0, #0
	bne .L080969F8
	ldr r0, [r7]
	movs r1, #7
	bl Proc_Goto
	b .L08096A04
	.align 2, 0
.L080969F0: .4byte gAction
.L080969F4: .4byte gBg0Tm+0x1B6
.L080969F8:
	b .L08096A04
.L080969FA:
	ldr r0, [r7]
	movs r1, #4
	bl Proc_Goto
	b .L08096A04
.L08096A04:
	add sp, #8
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start Shop_SellAnythingElseDialogue
Shop_SellAnythingElseDialogue: @ 0x08096A0C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r1, #0
	ldr r1, [r7]
	bl StartShopDialogue
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start Shop_AnythingElseRestartDialogue
Shop_AnythingElseRestartDialogue: @ 0x08096A28
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x5c
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r1, .L08096A54 @ =0x000002C6
	adds r0, r1, #0
	ldr r1, [r7]
	bl StartShopDialogue
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08096A54: .4byte 0x000002C6

	thumb_func_start Shop_AnythingElseContinueDialogue
Shop_AnythingElseContinueDialogue: @ 0x08096A58
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r1, .L08096A74 @ =0x000002C9
	adds r0, r1, #0
	ldr r1, [r7]
	bl StartShopDialogue
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08096A74: .4byte 0x000002C9

	thumb_func_start Shop_ExitShopDialogue
Shop_ExitShopDialogue: @ 0x08096A78
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r1, .L08096A94 @ =0x000002E1
	adds r0, r1, #0
	ldr r1, [r7]
	bl StartShopDialogue
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08096A94: .4byte 0x000002E1

	thumb_func_start Shop_OnExit
Shop_OnExit: @ 0x08096A98
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r1, .L08096AB8 @ =ProcScr_GoldBox
	adds r0, r1, #0
	bl Proc_EndEach
	ldr r0, .L08096ABC @ =ProcScr_Mu
	ldr r1, .L08096AC0 @ =ShowMu
	bl Proc_ForEach
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08096AB8: .4byte ProcScr_GoldBox
.L08096ABC: .4byte ProcScr_Mu
.L08096AC0: .4byte ShowMu

	thumb_func_start StartShopFadeIn
StartShopFadeIn: @ 0x08096AC4
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08096AF4 @ =gBmSt
	ldrb r1, [r0, #4]
	movs r2, #0x10
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0
	bne .L08096AEA
	ldr r1, .L08096AF8 @ =ProcScr_ShopFadeIn
	adds r0, r1, #0
	ldr r1, [r7]
	bl SpawnProcLocking
.L08096AEA:
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08096AF4: .4byte gBmSt
.L08096AF8: .4byte ProcScr_ShopFadeIn

	thumb_func_start StartShopFadeOut
StartShopFadeOut: @ 0x08096AFC
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08096B24 @ =gBmSt
	ldrb r1, [r0, #4]
	movs r2, #0x10
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0
	bne .L08096B2C
	ldr r1, .L08096B28 @ =ProcScr_ShopFadeOut
	adds r0, r1, #0
	ldr r1, [r7]
	bl SpawnProcLocking
	b .L08096B30
	.align 2, 0
.L08096B24: .4byte gBmSt
.L08096B28: .4byte ProcScr_ShopFadeOut
.L08096B2C:
	bl ClearTalk
.L08096B30:
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08096B38
func_fe6_08096B38: @ 0x08096B38
	push {r4, r7, lr}
	sub sp, #0xc
	add r7, sp, #4
	str r0, [r7]
	movs r0, #0x38
	movs r1, #0
	bl StartBgm
	ldr r0, .L08096C5C @ =ProcScr_Mu
	ldr r1, .L08096C60 @ =HideMu
	bl Proc_ForEach
	bl InitShopScreenConfig
	ldr r0, .L08096C64 @ =gDispIo
	ldrb r1, [r0, #0xc]
	movs r2, #0xfc
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #0xc]
	ldr r0, .L08096C64 @ =gDispIo
	ldrb r1, [r0, #0x10]
	movs r2, #0xfc
	ands r1, r2
	adds r2, r1, #0
	movs r3, #2
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0, #0x10]
	ldr r0, .L08096C64 @ =gDispIo
	ldrb r1, [r0, #0x14]
	movs r2, #0xfc
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #0x14]
	ldr r0, .L08096C64 @ =gDispIo
	ldrb r1, [r0, #0x18]
	movs r2, #3
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r1, #0
	movs r1, #2
	movs r2, #0
	bl InitTalk
	bl InitFaces
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x5c
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x5e
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x5f
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x5d
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x60
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x62
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	movs r1, #0x90
	lsls r1, r1, #2
	adds r0, r1, #0
	movs r1, #3
	bl UnpackUiVArrowGfx
	ldr r0, [r7]
	bl GetShopFace
	movs r1, #1
	str r1, [sp]
	movs r1, #0x20
	movs r2, #8
	movs r3, #3
	bl StartTalkFace
	ldr r0, .L08096C68 @ =Tsa_ShopWindows
	ldr r1, .L08096C6C @ =gBuf
	bl Decompress
	ldr r0, .L08096C70 @ =gBg1Tm
	ldr r1, .L08096C6C @ =gBuf
	movs r2, #0x80
	lsls r2, r2, #5
	bl TmApplyTsa_thm
	movs r0, #0
	str r0, [sp]
	movs r0, #6
	movs r1, #8
	movs r2, #0x14
	movs r3, #0xc
	bl PutUiWindowFrame
	movs r0, #2
	bl EnableBgSync
	ldr r0, [r7]
	bl StartUiGoldBox
	movs r0, #0
	str r0, [r7, #4]
.L08096C52:
	ldr r0, [r7, #4]
	cmp r0, #5
	ble .L08096C74
	b .L08096C94
	.align 2, 0
.L08096C5C: .4byte ProcScr_Mu
.L08096C60: .4byte HideMu
.L08096C64: .4byte gDispIo
.L08096C68: .4byte Tsa_ShopWindows
.L08096C6C: .4byte gBuf
.L08096C70: .4byte gBg1Tm
.L08096C74:
	ldr r0, [r7, #4]
	adds r1, r0, #0
	lsls r0, r1, #3
	ldr r2, .L08096C90 @ =gShopItemTexts
	adds r1, r0, r2
	adds r0, r1, #0
	movs r1, #0x14
	bl InitText
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L08096C52
	.align 2, 0
.L08096C90: .4byte gShopItemTexts
.L08096C94:
	ldr r0, [r7]
	bl DrawShopSoldItems
	ldr r0, .L08096F50 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0x20
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08096F50 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0x40
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08096F50 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0x7f
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #8
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #0x10
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x35
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x35
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x35
	ldrb r1, [r0]
	movs r2, #0xfb
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x35
	ldrb r1, [r0]
	movs r2, #8
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x35
	ldrb r1, [r0]
	movs r2, #0x10
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #0xfb
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #8
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #0x10
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x2d
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x38
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x31
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x48
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0xf0
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x30
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x98
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x2f
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x33
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #8
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x2e
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0xf0
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x32
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x38
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #0xdf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x35
	ldrb r1, [r0]
	movs r2, #0x20
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #0xdf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r2, #0xc0
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x44
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x45
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F50 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x46
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #8
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08096F54 @ =gDispIo+0x3C
	ldr r1, .L08096F54 @ =gDispIo+0x3C
	ldrh r2, [r1]
	ldr r3, .L08096F58 @ =0x0000FFE0
	adds r1, r2, #0
	ands r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L08096F54 @ =gDispIo+0x3C
	ldr r1, .L08096F54 @ =gDispIo+0x3C
	ldrh r2, [r1]
	movs r3, #8
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L08096F54 @ =gDispIo+0x3C
	ldr r1, .L08096F54 @ =gDispIo+0x3C
	ldrh r2, [r1]
	ldr r3, .L08096F5C @ =0x0000E0FF
	adds r1, r2, #0
	ands r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L08096F54 @ =gDispIo+0x3C
	ldr r1, .L08096F54 @ =gDispIo+0x3C
	ldrh r2, [r1]
	strh r2, [r0]
	ldr r4, .L08096F60 @ =Img_MuralBackground
	movs r0, #3
	bl GetBgChrOffset
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r0, r2
	adds r0, r4, #0
	bl Decompress
	ldr r0, .L08096F64 @ =gBg3Tm
	ldr r1, .L08096F68 @ =gUnk_083278EC
	movs r2, #0xc0
	lsls r2, r2, #8
	bl TmApplyTsa_thm
	ldr r0, .L08096F6C @ =gUnk_083278AC
	movs r1, #0xe0
	lsls r1, r1, #1
	movs r2, #0x40
	bl ApplyPaletteExt
	movs r0, #8
	bl EnableBgSync
	add sp, #0xc
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08096F50: .4byte gDispIo
.L08096F54: .4byte gDispIo+0x3C
.L08096F58: .4byte 0x0000FFE0
.L08096F5C: .4byte 0x0000E0FF
.L08096F60: .4byte Img_MuralBackground
.L08096F64: .4byte gBg3Tm
.L08096F68: .4byte gUnk_083278EC
.L08096F6C: .4byte gUnk_083278AC

	thumb_func_start StartUiGoldBox
StartUiGoldBox: @ 0x08096F70
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08096FF8 @ =gUnk_082DCA2C
	ldr r1, .L08096FFC @ =0x06014C00
	bl Decompress
	ldr r1, .L08097000 @ =ProcScr_GoldBox
	adds r0, r1, #0
	ldr r1, [r7]
	bl SpawnProc
	str r0, [r7, #4]
	ldr r0, [r7, #4]
	adds r1, r0, #0
	adds r0, #0x64
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0xac
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, [r7, #4]
	adds r1, r0, #0
	adds r0, #0x66
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x2c
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, [r7, #4]
	adds r1, r0, #0
	adds r0, #0x68
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	ldr r3, .L08097004 @ =0x00004260
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L08097008 @ =Pal_UiWindowFrame_ThemeBlue
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r1, .L0809700C @ =gBg0Tm+0x1B8
	adds r0, r1, #0
	bl InitGoldBoxText
	ldr r1, .L08097010 @ =gBg0Tm+0x1B6
	adds r0, r1, #0
	bl DisplayGoldBoxText
	add sp, #8
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08096FF8: .4byte gUnk_082DCA2C
.L08096FFC: .4byte 0x06014C00
.L08097000: .4byte ProcScr_GoldBox
.L08097004: .4byte 0x00004260
.L08097008: .4byte Pal_UiWindowFrame_ThemeBlue
.L0809700C: .4byte gBg0Tm+0x1B8
.L08097010: .4byte gBg0Tm+0x1B6

	thumb_func_start InitGoldBoxText
InitGoldBoxText: @ 0x08097014
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	movs r0, #0
	bl SetTextFont
	bl InitSystemTextFont
	ldr r1, .L08097044 @ =Text_GoldBox
	adds r0, r1, #0
	movs r1, #1
	bl InitText
	ldr r2, .L08097048 @ =String_ShopGoldG
	ldr r0, [r7]
	movs r1, #3
	bl PutString
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08097044: .4byte Text_GoldBox
.L08097048: .4byte String_ShopGoldG

	thumb_func_start ClearGoldBoxTextTm2Line
ClearGoldBoxTextTm2Line: @ 0x0809704C
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
.L08097056:
	ldr r0, [r7, #4]
	cmp r0, #0
	bgt .L0809705E
	b .L0809707C
.L0809705E:
	ldr r0, [r7]
	movs r1, #0
	strh r1, [r0]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r0, #0x40
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r7]
	subs r1, r0, #2
	str r1, [r7]
	ldr r0, [r7, #4]
	subs r1, r0, #1
	str r1, [r7, #4]
	b .L08097056
.L0809707C:
	add sp, #8
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start DisplayGoldBoxText
DisplayGoldBoxText: @ 0x08097084
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	movs r0, #0
	bl SetTextFont
	bl InitSystemTextFont
	ldr r0, [r7]
	movs r1, #6
	bl ClearGoldBoxTextTm2Line
	bl GetGold
	adds r2, r0, #0
	ldr r0, [r7]
	movs r1, #2
	bl PutNumber
	movs r0, #1
	bl EnableBgSync
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ShopInitTexts_OnBuy
ShopInitTexts_OnBuy: @ 0x080970BC
	push {r7, lr}
	sub sp, #0x10
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x60
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r1, .L0809710C @ =ProcScr_ShopBuyInit
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
	str r0, [r7, #0xc]
	ldr r0, [r7, #0xc]
	ldr r1, [r7]
	str r1, [r0, #0x54]
	movs r0, #0
	bl SetTextFont
	bl InitSystemTextFont
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5f
	ldrb r0, [r1]
	str r0, [r7, #4]
.L080970FA:
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5f
	ldrb r0, [r1]
	adds r1, r0, #5
	ldr r0, [r7, #4]
	cmp r0, r1
	blt .L08097110
	b .L08097150
	.align 2, 0
.L0809710C: .4byte ProcScr_ShopBuyInit
.L08097110:
	ldr r1, [r7, #4]
	adds r0, r1, #0
	movs r1, #6
	bl DivRem
	str r0, [r7, #8]
	ldr r0, [r7, #8]
	adds r1, r0, #0
	lsls r0, r1, #3
	ldr r1, .L08097148 @ =gShopItemTexts
	adds r0, r0, r1
	ldr r1, [r7, #4]
	adds r2, r1, #0
	lsls r1, r2, #1
	movs r2, #0x1f
	ands r1, r2
	lsls r2, r1, #5
	adds r1, r2, #0
	lsls r2, r1, #1
	ldr r3, .L0809714C @ =gBg2Tm+0xE
	adds r1, r2, r3
	bl PutBlankText
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L080970FA
	.align 2, 0
.L08097148: .4byte gShopItemTexts
.L0809714C: .4byte gBg2Tm+0xE
.L08097150:
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5f
	ldrb r0, [r1]
	adds r1, r0, #0
	lsls r0, r1, #4
	adds r1, r0, #0
	adds r0, r1, #0
	subs r0, #0x48
	adds r1, r0, #0
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	movs r0, #2
	movs r1, #0
	bl SetBgOffset
	movs r0, #4
	bl EnableBgSync
	add sp, #0x10
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DrawShopSoldItems
DrawShopSoldItems: @ 0x08097180
	push {r4, r5, r7, lr}
	sub sp, #0x10
	mov r7, sp
	str r0, [r7]
	movs r0, #0
	bl SetTextFont
	bl InitSystemTextFont
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5f
	ldrb r0, [r1]
	str r0, [r7, #4]
.L0809719C:
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5f
	ldrb r0, [r1]
	adds r1, r0, #5
	ldr r0, [r7, #4]
	cmp r0, r1
	blt .L080971AE
	b .L080971D8
.L080971AE:
	ldr r1, [r7, #4]
	adds r0, r1, #0
	movs r1, #6
	bl DivRem
	str r0, [r7, #0xc]
	ldr r0, [r7, #0xc]
	adds r1, r0, #0
	lsls r0, r1, #3
	ldr r2, .L080971D4 @ =gShopItemTexts
	adds r1, r0, r2
	adds r0, r1, #0
	bl ClearText
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L0809719C
	.align 2, 0
.L080971D4: .4byte gShopItemTexts
.L080971D8:
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5f
	ldrb r0, [r1]
	str r0, [r7, #4]
.L080971E2:
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5f
	ldrb r0, [r1]
	adds r1, r0, #5
	ldr r0, [r7, #4]
	cmp r0, r1
	blt .L080971F4
	b .L08097250
.L080971F4:
	ldr r1, [r7, #4]
	adds r0, r1, #0
	movs r1, #6
	bl DivRem
	str r0, [r7, #0xc]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	adds r2, r1, #0
	lsls r1, r2, #1
	adds r0, #0x30
	adds r1, r0, r1
	ldrh r0, [r1]
	str r0, [r7, #8]
	ldr r0, [r7, #8]
	cmp r0, #0
	bne .L08097218
	b .L08097250
.L08097218:
	ldr r0, [r7, #0xc]
	adds r1, r0, #0
	lsls r0, r1, #3
	ldr r1, .L08097248 @ =gShopItemTexts
	adds r0, r0, r1
	ldr r1, [r7, #8]
	ldr r3, [r7]
	ldr r2, [r3, #0x2c]
	ldr r3, [r7, #4]
	adds r4, r3, #0
	lsls r3, r4, #1
	movs r4, #0x1f
	ands r3, r4
	lsls r4, r3, #5
	adds r3, r4, #0
	lsls r4, r3, #1
	ldr r5, .L0809724C @ =gBg2Tm+0xE
	adds r3, r4, r5
	bl DrawShopItemPriceLine
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L080971E2
	.align 2, 0
.L08097248: .4byte gShopItemTexts
.L0809724C: .4byte gBg2Tm+0xE
.L08097250:
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x5f
	ldrb r0, [r1]
	adds r1, r0, #0
	lsls r0, r1, #4
	adds r1, r0, #0
	adds r0, r1, #0
	subs r0, #0x48
	adds r1, r0, #0
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	movs r0, #2
	movs r1, #0
	bl SetBgOffset
	movs r0, #4
	bl EnableBgSync
	add sp, #0x10
	pop {r4, r5, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start InitShopBuyStatus
InitShopBuyStatus: @ 0x08097280
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r0, #0x54]
	adds r0, r1, #0
	bl Shop_InitBuyState
	ldr r0, [r7]
	ldr r1, [r0, #0x54]
	adds r0, r1, #0
	bl DrawShopSoldItems
	ldr r0, [r7]
	bl Proc_Break
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ShopInitTexts_OnSell
ShopInitTexts_OnSell: @ 0x080972AC
	push {r7, lr}
	sub sp, #0x10
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x60
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #1
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r1, .L080972F4 @ =ProcScr_ShopSellInit
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
	str r0, [r7, #0xc]
	ldr r0, [r7, #0xc]
	ldr r1, [r7]
	str r1, [r0, #0x54]
	movs r0, #0
	bl SetTextFont
	bl InitSystemTextFont
	movs r0, #0
	str r0, [r7, #4]
.L080972EC:
	ldr r0, [r7, #4]
	cmp r0, #4
	ble .L080972F8
	b .L08097338
	.align 2, 0
.L080972F4: .4byte ProcScr_ShopSellInit
.L080972F8:
	ldr r1, [r7, #4]
	adds r0, r1, #0
	movs r1, #6
	bl DivRem
	str r0, [r7, #8]
	ldr r0, [r7, #8]
	adds r1, r0, #0
	lsls r0, r1, #3
	ldr r1, .L08097330 @ =gShopItemTexts
	adds r0, r0, r1
	ldr r1, [r7, #4]
	adds r2, r1, #0
	lsls r1, r2, #1
	movs r2, #0x1f
	ands r1, r2
	lsls r2, r1, #5
	adds r1, r2, #0
	lsls r2, r1, #1
	ldr r3, .L08097334 @ =gBg2Tm+0xE
	adds r1, r2, r3
	bl PutBlankText
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L080972EC
	.align 2, 0
.L08097330: .4byte gShopItemTexts
.L08097334: .4byte gBg2Tm+0xE
.L08097338:
	ldr r2, .L08097350 @ =0x0000FFB8
	movs r0, #2
	movs r1, #0
	bl SetBgOffset
	movs r0, #4
	bl EnableBgSync
	add sp, #0x10
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08097350: .4byte 0x0000FFB8

	thumb_func_start func_fe6_08097354
func_fe6_08097354: @ 0x08097354
	push {r4, r5, r7, lr}
	sub sp, #0x10
	mov r7, sp
	str r0, [r7]
	movs r0, #0
	bl SetTextFont
	bl InitSystemTextFont
	movs r0, #0
	str r0, [r7, #4]
.L0809736A:
	ldr r0, [r7, #4]
	cmp r0, #4
	ble .L08097372
	b .L0809739C
.L08097372:
	ldr r1, [r7, #4]
	adds r0, r1, #0
	movs r1, #6
	bl DivRem
	str r0, [r7, #0xc]
	ldr r0, [r7, #0xc]
	adds r1, r0, #0
	lsls r0, r1, #3
	ldr r2, .L08097398 @ =gShopItemTexts
	adds r1, r0, r2
	adds r0, r1, #0
	bl ClearText
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L0809736A
	.align 2, 0
.L08097398: .4byte gShopItemTexts
.L0809739C:
	movs r0, #0
	str r0, [r7, #4]
.L080973A0:
	ldr r0, [r7, #4]
	cmp r0, #4
	ble .L080973A8
	b .L08097408
.L080973A8:
	ldr r1, [r7, #4]
	adds r0, r1, #0
	movs r1, #6
	bl DivRem
	str r0, [r7, #0xc]
	ldr r1, [r7]
	ldr r0, [r1, #0x2c]
	ldr r1, [r7, #4]
	adds r2, r1, #0
	lsls r1, r2, #1
	adds r0, #0x1c
	adds r1, r0, r1
	ldrh r0, [r1]
	str r0, [r7, #8]
	ldr r0, [r7, #8]
	cmp r0, #0
	bne .L080973CE
	b .L08097408
.L080973CE:
	ldr r0, [r7, #0xc]
	adds r1, r0, #0
	lsls r0, r1, #3
	ldr r1, .L08097400 @ =gShopItemTexts
	adds r0, r0, r1
	ldr r1, [r7, #8]
	ldr r3, [r7]
	ldr r2, [r3, #0x2c]
	ldr r3, [r7, #4]
	adds r4, r3, #0
	lsls r3, r4, #1
	movs r4, #0x1f
	ands r3, r4
	lsls r4, r3, #5
	adds r3, r4, #0
	lsls r4, r3, #1
	ldr r5, .L08097404 @ =gBg2Tm+0xE
	adds r3, r4, r5
	bl DrawShopItemLine
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L080973A0
	.align 2, 0
.L08097400: .4byte gShopItemTexts
.L08097404: .4byte gBg2Tm+0xE
.L08097408:
	movs r0, #4
	bl EnableBgSync
	add sp, #0x10
	pop {r4, r5, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start InitShopSellStatus
InitShopSellStatus: @ 0x08097418
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r0, #0x54]
	adds r0, r1, #0
	bl Shop_InitSellState
	ldr r0, [r7]
	ldr r1, [r0, #0x54]
	adds r0, r1, #0
	bl func_fe6_08097354
	ldr r0, [r7]
	bl Proc_Break
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DrawShopItemPriceLine
DrawShopItemPriceLine: @ 0x08097444
	push {r4, r7, lr}
	sub sp, #0x14
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	str r3, [r7, #0xc]
	ldr r0, [r7, #8]
	ldr r1, [r7, #4]
	bl GetItemPrice
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	str r0, [r7, #0x10]
	ldr r4, [r7, #4]
	ldr r0, [r7, #8]
	ldr r1, [r7, #4]
	bl IsItemDisplayUseable
	lsls r1, r0, #0x18
	asrs r2, r1, #0x18
	ldr r3, [r7, #0xc]
	ldr r0, [r7]
	adds r1, r4, #0
	bl func_fe6_08016694
	ldr r0, [r7, #0xc]
	adds r4, r0, #0
	adds r4, #0x22
	bl GetGold
	ldr r1, [r7, #0x10]
	cmp r0, r1
	blt .L0809748C
	movs r1, #2
	b .L0809748E
.L0809748C:
	movs r1, #1
.L0809748E:
	ldr r2, [r7, #0x10]
	adds r0, r4, #0
	bl PutNumber
	add sp, #0x14
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DrawShopItemLine
DrawShopItemLine: @ 0x080974A0
	push {r4, r7, lr}
	sub sp, #0x10
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	str r3, [r7, #0xc]
	ldr r4, [r7, #4]
	ldr r0, [r7, #8]
	ldr r1, [r7, #4]
	bl IsItemDisplayUseable
	lsls r1, r0, #0x18
	asrs r2, r1, #0x18
	ldr r3, [r7, #0xc]
	ldr r0, [r7]
	adds r1, r4, #0
	bl func_fe6_08016694
	ldr r1, [r7, #4]
	adds r0, r1, #0
	bl func_fe6_080975C8
	lsls r1, r0, #0x18
	asrs r0, r1, #0x18
	cmp r0, #0
	beq .L080974F2
	ldr r0, [r7, #0xc]
	adds r4, r0, #0
	adds r4, #0x22
	ldr r1, [r7, #4]
	adds r0, r1, #0
	bl func_fe6_080975A0
	lsls r1, r0, #0x10
	lsrs r2, r1, #0x10
	adds r0, r4, #0
	movs r1, #2
	bl PutNumber
	b .L080974FE
.L080974F2:
	ldr r3, .L08097508 @ =gUnk_0835CA78
	ldr r0, [r7]
	movs r1, #0x5c
	movs r2, #2
	bl Text_InsertDrawString
.L080974FE:
	add sp, #0x10
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08097508: .4byte gUnk_0835CA78

	thumb_func_start GetItemPrice
GetItemPrice: @ 0x0809750C
	push {r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	ldr r1, [r7, #4]
	adds r0, r1, #0
	bl GetItemValue
	str r0, [r7, #8]
	ldr r0, .L0809757C @ =gBmSt
	ldrb r1, [r0, #4]
	movs r2, #0x10
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0
	beq .L08097558
	ldr r0, [r7, #8]
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r3, #0
	adds r0, r2, #0
	ldr r2, .L08097580 @ =0x3FF80000
	ldr r3, .L08097584 @ =0x00000000
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r3, #0
	adds r0, r2, #0
	bl __fixdfsi
	str r0, [r7, #8]
.L08097558:
	ldr r0, [r7]
	movs r1, #0x6e
	bl UnitHasItem
	lsls r1, r0, #0x18
	asrs r0, r1, #0x18
	cmp r0, #0
	beq .L0809758A
	ldr r0, [r7, #8]
	asrs r1, r0, #0x1f
	lsrs r2, r1, #0x1f
	adds r1, r0, r2
	asrs r0, r1, #1
	adds r1, r0, #0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	b .L08097596
	.align 2, 0
.L0809757C: .4byte gBmSt
.L08097580: .4byte 0x3FF80000
.L08097584: .4byte 0x00000000
.L08097588:
	.byte 0x05, 0xE0
.L0809758A:
	ldr r1, [r7, #8]
	adds r0, r1, #0
	lsls r2, r0, #0x10
	lsrs r1, r2, #0x10
	adds r0, r1, #0
	b .L08097596
.L08097596:
	add sp, #0xc
	pop {r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_080975A0
func_fe6_080975A0: @ 0x080975A0
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	bl GetItemValue
	asrs r1, r0, #0x1f
	lsrs r2, r1, #0x1f
	adds r1, r0, r2
	asrs r0, r1, #1
	adds r1, r0, #0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	b .L080975C0
.L080975C0:
	add sp, #4
	pop {r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_080975C8
func_fe6_080975C8: @ 0x080975C8
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	bl GetItemAttributes
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080975E2
	movs r0, #0
	b .L080975F8
.L080975E2:
	ldr r0, [r7]
	bl func_fe6_080975A0
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	bne .L080975F4
	movs r0, #0
	b .L080975F8
.L080975F4:
	movs r0, #1
	b .L080975F8
.L080975F8:
	add sp, #4
	pop {r7}
	pop {r1}
	bx r1

	thumb_func_start GoldBox_OnLoop
GoldBox_OnLoop: @ 0x08097600
	push {r4, r5, r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x64
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x66
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r2, .L08097634 @ =Sprite_ShopGoldBox
	ldr r4, [r7]
	adds r3, r4, #0
	adds r4, #0x68
	movs r5, #0
	ldrsh r3, [r4, r5]
	bl PutOamHiRam
	add sp, #4
	pop {r4, r5, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08097634: .4byte Sprite_ShopGoldBox

	thumb_func_start InitShopScreenConfig
InitShopScreenConfig: @ 0x08097638
	push {r7, lr}
	mov r7, sp
	ldr r0, .L08097714 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #1
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08097714 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #2
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08097714 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #4
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08097714 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #8
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08097714 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0x10
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08097714 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0xdf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08097714 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0xbf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08097714 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0x7f
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r1, .L08097718 @ =gBg0Tm
	adds r0, r1, #0
	movs r1, #0
	bl TmFill
	ldr r1, .L0809771C @ =gBg1Tm
	adds r0, r1, #0
	movs r1, #0
	bl TmFill
	ldr r1, .L08097720 @ =gBg2Tm
	adds r0, r1, #0
	movs r1, #0
	bl TmFill
	ldr r1, .L08097724 @ =gBg3Tm
	adds r0, r1, #0
	movs r1, #0
	bl TmFill
	movs r0, #0xf
	bl EnableBgSync
	bl ResetText
	bl UnpackUiWindowFrameGraphics
	bl InitIcons
	movs r0, #4
	bl ApplyIconPalettes
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl LoadHelpBoxGfx
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08097714: .4byte gDispIo
.L08097718: .4byte gBg0Tm
.L0809771C: .4byte gBg1Tm
.L08097720: .4byte gBg2Tm
.L08097724: .4byte gBg3Tm

	thumb_func_start _DisplayShopUiArrows
_DisplayShopUiArrows: @ 0x08097728
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	bl DisplayShopUiArrows
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start DisplayShopUiArrows
DisplayShopUiArrows: @ 0x0809773C
	push {r7, lr}
	mov r7, sp
	bl ShouldDisplayUpArrow
	lsls r1, r0, #0x18
	asrs r0, r1, #0x18
	cmp r0, #0
	beq .L0809775A
	movs r2, #0xc9
	lsls r2, r2, #6
	movs r0, #0x78
	movs r1, #0x40
	movs r3, #1
	bl DisplayUiVArrow
.L0809775A:
	bl ShouldDisplayDownArrow
	lsls r1, r0, #0x18
	asrs r0, r1, #0x18
	cmp r0, #0
	beq .L08097774
	movs r2, #0xc9
	lsls r2, r2, #6
	movs r0, #0x78
	movs r1, #0x98
	movs r3, #0
	bl DisplayUiVArrow
.L08097774:
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start UnpackUiVArrowGfx
UnpackUiVArrowGfx: @ 0x0809777C
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	ldr r0, .L080977B4 @ =Img_SpinningArrow
	ldr r1, [r7]
	lsls r2, r1, #0x16
	lsrs r1, r2, #0x16
	lsls r2, r1, #5
	ldr r3, .L080977B8 @ =0x06010000
	adds r1, r2, r3
	bl Decompress
	ldr r0, .L080977BC @ =Pal_SpinningArrow
	ldr r2, [r7, #4]
	adds r1, r2, #0
	adds r1, #0x10
	adds r2, r1, #0
	lsls r1, r2, #5
	movs r2, #0x20
	bl ApplyPaletteExt
	add sp, #8
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080977B4: .4byte Img_SpinningArrow
.L080977B8: .4byte 0x06010000
.L080977BC: .4byte Pal_SpinningArrow

	thumb_func_start DisplayUiVArrow
DisplayUiVArrow: @ 0x080977C0
	push {r4, r7, lr}
	sub sp, #0x1c
	add r7, sp, #4
	str r0, [r7]
	str r1, [r7, #4]
	adds r0, r2, #0
	str r3, [r7, #0xc]
	adds r1, r7, #0
	adds r1, #8
	strh r0, [r1]
	bl GetGameTime
	adds r1, r0, #0
	adds r0, r1, #0
	movs r1, #0x28
	bl DivRem
	str r0, [r7, #0x10]
	ldr r1, [r7, #0x10]
	adds r0, r1, #0
	movs r1, #8
	bl Div
	adds r1, r0, #0
	lsls r0, r1, #1
	str r0, [r7, #0x10]
	ldr r0, [r7, #0xc]
	cmp r0, #0
	bne .L08097802
	movs r0, #0x80
	lsls r0, r0, #6
	str r0, [r7, #0x14]
	b .L08097806
.L08097802:
	movs r0, #0
	str r0, [r7, #0x14]
.L08097806:
	ldr r0, [r7]
	ldr r2, [r7, #0x14]
	adds r1, r0, #0
	orrs r1, r2
	ldr r2, [r7, #4]
	ldr r3, .L0809782C @ =Sprite_16x8
	adds r0, r7, #0
	adds r0, #8
	ldrh r4, [r0]
	ldr r0, [r7, #0x10]
	adds r4, r4, r0
	str r4, [sp]
	movs r0, #2
	bl PutSpriteExt
	add sp, #0x1c
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0809782C: .4byte Sprite_16x8

	thumb_func_start HandleShopBuyAction
HandleShopBuyAction: @ 0x08097830
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	movs r0, #0xb9
	movs r1, #8
	bl PlaySeDelayed
	ldr r0, .L080978A4 @ =gAction
	ldrb r1, [r0, #0x11]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x14
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0, #0x11]
	bl GetGold
	str r0, [r7, #4]
	ldr r1, [r7]
	ldr r0, [r1, #0x2c]
	ldr r1, [r7]
	ldr r3, [r7]
	adds r2, r3, #0
	adds r3, #0x5c
	ldrb r2, [r3]
	adds r3, r2, #0
	lsls r2, r3, #1
	adds r1, #0x30
	adds r2, r1, r2
	ldrh r1, [r2]
	bl GetItemPrice
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	ldr r1, [r7, #4]
	subs r0, r1, r0
	str r0, [r7, #4]
	ldr r1, [r7, #4]
	adds r0, r1, #0
	bl SetGold
	ldr r0, [r7]
	bl UpdateShopItemCounts
	ldr r0, [r7]
	bl DrawShopSoldItems
	ldr r1, .L080978A8 @ =gBg0Tm+0x1B6
	adds r0, r1, #0
	bl DisplayGoldBoxText
	add sp, #8
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080978A4: .4byte gAction
.L080978A8: .4byte gBg0Tm+0x1B6

	thumb_func_start ShopTryMoveCursor
ShopTryMoveCursor: @ 0x080978AC
	push {r7, lr}
	sub sp, #0x10
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	adds r0, r2, #0
	adds r1, r7, #0
	adds r1, #8
	strb r0, [r1]
	ldr r0, [r7]
	cmp r0, #0
	bge .L080978C8
	movs r0, #0
	str r0, [r7]
.L080978C8:
	ldr r0, [r7]
	ldr r1, [r7, #4]
	cmp r0, r1
	blt .L080978D6
	ldr r0, [r7, #4]
	subs r1, r0, #1
	str r1, [r7]
.L080978D6:
	ldr r0, [r7]
	str r0, [r7, #0xc]
	ldr r1, .L08097920 @ =gKeySt
	ldr r0, [r1]
	ldrh r1, [r0, #6]
	movs r2, #0x40
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L0809792C
	ldr r0, [r7]
	cmp r0, #0
	bne .L08097924
	adds r0, r7, #0
	adds r0, #8
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	beq .L0809791E
	ldr r1, .L08097920 @ =gKeySt
	ldr r0, [r1]
	ldrh r1, [r0, #8]
	movs r2, #0x40
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L0809791E
	ldr r0, [r7, #4]
	subs r1, r0, #1
	str r1, [r7]
.L0809791E:
	b .L0809792A
	.align 2, 0
.L08097920: .4byte gKeySt
.L08097924:
	ldr r0, [r7]
	subs r1, r0, #1
	str r1, [r7]
.L0809792A:
	b .L0809797E
.L0809792C:
	ldr r1, .L08097974 @ =gKeySt
	ldr r0, [r1]
	ldrh r1, [r0, #6]
	movs r2, #0x80
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L0809797E
	ldr r1, [r7, #4]
	subs r0, r1, #1
	ldr r1, [r7]
	cmp r1, r0
	bne .L08097978
	adds r0, r7, #0
	adds r0, #8
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	beq .L08097972
	ldr r1, .L08097974 @ =gKeySt
	ldr r0, [r1]
	ldrh r1, [r0, #8]
	movs r2, #0x80
	adds r0, r1, #0
	ands r0, r2
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L08097972
	movs r0, #0
	str r0, [r7]
.L08097972:
	b .L0809797E
	.align 2, 0
.L08097974: .4byte gKeySt
.L08097978:
	ldr r0, [r7]
	adds r1, r0, #1
	str r1, [r7]
.L0809797E:
	ldr r0, [r7, #0xc]
	ldr r1, [r7]
	cmp r0, r1
	beq .L08097998
	ldr r0, .L080979A0 @ =gPlaySt
	ldrb r1, [r0, #0x1d]
	lsls r2, r1, #0x1e
	lsrs r0, r2, #0x1f
	cmp r0, #0
	bne .L08097998
	movs r0, #0x66
	bl m4aSongNumStart
.L08097998:
	ldr r1, [r7]
	adds r0, r1, #0
	b .L080979A4
	.align 2, 0
.L080979A0: .4byte gPlaySt
.L080979A4:
	add sp, #0x10
	pop {r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_080979AC
func_fe6_080979AC: @ 0x080979AC
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L080979C4 @ =gShopSt
	ldr r1, [r7]
	str r1, [r0]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080979C4: .4byte gShopSt

	thumb_func_start ShopTryScrollPage
ShopTryScrollPage: @ 0x080979C8
	push {r7, lr}
	sub sp, #0x14
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	str r3, [r7, #0xc]
	ldr r0, .L080979F0 @ =gShopSt
	ldr r1, [r0]
	str r1, [r7, #0x10]
	ldr r0, .L080979F0 @ =gShopSt
	ldr r1, [r7]
	str r1, [r0]
	ldr r0, [r7]
	ldr r1, [r7, #0x10]
	cmp r0, r1
	bne .L080979F4
	movs r0, #0
	b .L08097A4A
	.align 2, 0
.L080979F0: .4byte gShopSt
.L080979F4:
	ldr r0, [r7, #8]
	ldr r1, [r7, #4]
	cmp r0, r1
	ble .L08097A00
	movs r0, #0
	b .L08097A4A
.L08097A00:
	ldr r0, [r7]
	ldr r1, [r7, #0x10]
	cmp r0, r1
	bge .L08097A24
	ldr r0, [r7, #0xc]
	cmp r0, #0
	bne .L08097A12
	movs r0, #0
	b .L08097A4A
.L08097A12:
	ldr r0, [r7]
	ldr r1, [r7, #0xc]
	subs r0, r0, r1
	cmp r0, #0
	bgt .L08097A22
	movs r0, #1
	rsbs r0, r0, #0
	b .L08097A4A
.L08097A22:
	b .L08097A46
.L08097A24:
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	adds r0, r0, r1
	ldr r1, [r7, #4]
	cmp r0, r1
	bne .L08097A34
	movs r0, #0
	b .L08097A4A
.L08097A34:
	ldr r0, [r7]
	ldr r1, [r7, #0xc]
	subs r0, r0, r1
	ldr r2, [r7, #8]
	subs r1, r2, #1
	cmp r0, r1
	blt .L08097A46
	movs r0, #1
	b .L08097A4A
.L08097A46:
	movs r0, #0
	b .L08097A4A
.L08097A4A:
	add sp, #0x14
	pop {r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start ShopUpdateBg2Offset
ShopUpdateBg2Offset: @ 0x08097A54
	push {r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	subs r0, r0, r1
	cmp r0, #0
	blt .L08097A78
	ldr r0, [r7]
	ldr r1, [r7, #4]
	subs r0, r0, r1
	ldr r1, [r7, #8]
	cmp r0, r1
	blt .L08097A86
	b .L08097A8C
.L08097A78:
	ldr r0, [r7, #4]
	ldr r1, [r7]
	subs r0, r0, r1
	ldr r1, [r7, #8]
	cmp r0, r1
	blt .L08097A86
	b .L08097A8C
.L08097A86:
	ldr r1, [r7, #4]
	adds r0, r1, #0
	b .L08097ABA
.L08097A8C:
	ldr r0, [r7, #4]
	ldr r1, [r7]
	subs r0, r0, r1
	cmp r0, #0
	bgt .L08097AAC
	ldr r0, [r7]
	ldr r1, [r7, #4]
	ldr r2, [r7]
	subs r1, r1, r2
	cmp r1, #0
	bge .L08097AAA
	ldr r1, [r7, #8]
	adds r2, r1, #0
	rsbs r1, r2, #0
	adds r0, r0, r1
.L08097AAA:
	b .L08097AB2
.L08097AAC:
	ldr r1, [r7]
	ldr r2, [r7, #8]
	adds r0, r1, r2
.L08097AB2:
	str r0, [r7]
	ldr r1, [r7]
	adds r0, r1, #0
	b .L08097ABA
.L08097ABA:
	add sp, #0xc
	pop {r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start RegisterShopState
RegisterShopState: @ 0x08097AC4
	push {r4, r5, r7, lr}
	sub sp, #8
	mov r7, sp
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r2, #0
	adds r0, r3, #0
	adds r2, r7, #0
	adds r3, r5, #0
	strh r3, [r2]
	adds r2, r7, #2
	adds r3, r4, #0
	strh r3, [r2]
	adds r2, r7, #4
	strh r1, [r2]
	adds r1, r7, #6
	strh r0, [r1]
	adds r0, r7, #0
	ldrh r1, [r0]
	adds r0, r1, #0
	bl func_fe6_080979AC
	ldr r1, .L08097BBC @ =gpShopSt
	ldr r0, [r1]
	adds r1, r7, #0
	ldrh r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrh r1, [r1]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0]
	ldr r1, .L08097BBC @ =gpShopSt
	ldr r0, [r1]
	adds r1, r7, #2
	ldrh r2, [r0, #2]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrh r1, [r1]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #2]
	ldr r1, .L08097BBC @ =gpShopSt
	ldr r0, [r1]
	adds r1, r7, #4
	ldrh r2, [r0, #4]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrh r1, [r1]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #4]
	ldr r1, .L08097BBC @ =gpShopSt
	ldr r0, [r1]
	adds r1, r7, #6
	ldrh r2, [r0, #6]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrh r1, [r1]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #6]
	ldr r1, .L08097BBC @ =gpShopSt
	ldr r0, [r1]
	ldrh r1, [r0, #8]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #8]
	ldr r1, .L08097BBC @ =gpShopSt
	ldr r0, [r1]
	ldrh r1, [r0, #0xa]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #4
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0xa]
	ldr r1, .L08097BBC @ =gpShopSt
	ldr r0, [r1]
	ldr r1, [r7, #0x1c]
	str r1, [r0, #0x14]
	ldr r1, .L08097BBC @ =gpShopSt
	ldr r0, [r1]
	ldr r1, [r7, #0x20]
	str r1, [r0, #0x18]
	ldr r1, .L08097BBC @ =gpShopSt
	ldr r0, [r1]
	ldr r1, [r7, #0x18]
	rsbs r2, r1, #0
	str r2, [r0, #0x10]
	ldr r1, .L08097BBC @ =gpShopSt
	ldr r0, [r1]
	adds r1, r7, #6
	ldrh r2, [r1]
	adds r3, r2, #0
	lsls r1, r3, #4
	ldrh r2, [r0, #0xc]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #0xc]
	add sp, #8
	pop {r4, r5, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08097BBC: .4byte gpShopSt

	thumb_func_start Shop_TryMoveHandPage
Shop_TryMoveHandPage: @ 0x08097BC0
	push {r4, r7, lr}
	mov r7, sp
	ldr r0, .L08097C1C @ =gpShopSt
	ldr r1, [r0]
	ldrh r0, [r1]
	ldr r2, .L08097C1C @ =gpShopSt
	ldr r1, [r2]
	ldrh r2, [r1, #2]
	adds r1, r2, #0
	movs r2, #0
	bl ShopTryMoveCursor
	adds r1, r0, #0
	ldr r2, .L08097C1C @ =gpShopSt
	ldr r0, [r2]
	ldrh r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0]
	ldr r0, .L08097C1C @ =gpShopSt
	ldr r1, [r0]
	ldrh r0, [r1]
	ldr r1, .L08097C1C @ =gpShopSt
	ldr r2, [r1]
	ldrh r1, [r2, #2]
	ldr r2, .L08097C1C @ =gpShopSt
	ldr r3, [r2]
	ldrh r2, [r3, #4]
	ldr r3, .L08097C1C @ =gpShopSt
	ldr r4, [r3]
	ldrh r3, [r4, #6]
	bl ShopTryScrollPage
	cmp r0, #0
	beq .L08097C26
	cmp r0, #0
	bgt .L08097C20
	movs r1, #1
	cmn r0, r1
	beq .L08097C74
	b .L08097C26
	.align 2, 0
.L08097C1C: .4byte gpShopSt
.L08097C20:
	cmp r0, #1
	beq .L08097C28
	b .L08097C26
.L08097C26:
	b .L08097CB4
.L08097C28:
	ldr r1, .L08097C70 @ =gpShopSt
	ldr r0, [r1]
	ldr r1, .L08097C70 @ =gpShopSt
	ldr r0, [r1]
	ldr r2, .L08097C70 @ =gpShopSt
	ldr r1, [r2]
	ldrh r2, [r1, #6]
	adds r1, r2, #1
	ldrh r2, [r0, #6]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #6]
	ldr r1, .L08097C70 @ =gpShopSt
	ldr r0, [r1]
	ldr r1, .L08097C70 @ =gpShopSt
	ldr r2, [r1]
	ldr r1, [r2, #0x18]
	ldr r2, .L08097C70 @ =gpShopSt
	ldr r3, [r2]
	ldrh r2, [r3, #6]
	ldr r4, .L08097C70 @ =gpShopSt
	ldr r3, [r4]
	ldrh r4, [r3, #4]
	adds r3, r2, r4
	subs r2, r3, #1
	ldr r3, [r0, #0x14]
	adds r0, r1, #0
	adds r1, r2, #0
	bl _call_via_r3
	b .L08097CB4
	.align 2, 0
.L08097C70: .4byte gpShopSt
.L08097C74:
	ldr r1, .L08097CB0 @ =gpShopSt
	ldr r0, [r1]
	ldr r1, .L08097CB0 @ =gpShopSt
	ldr r0, [r1]
	ldr r2, .L08097CB0 @ =gpShopSt
	ldr r1, [r2]
	ldrh r2, [r1, #6]
	subs r1, r2, #1
	ldrh r2, [r0, #6]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #6]
	ldr r1, .L08097CB0 @ =gpShopSt
	ldr r0, [r1]
	ldr r1, .L08097CB0 @ =gpShopSt
	ldr r2, [r1]
	ldr r1, [r2, #0x18]
	ldr r2, .L08097CB0 @ =gpShopSt
	ldr r3, [r2]
	ldrh r2, [r3, #6]
	ldr r3, [r0, #0x14]
	adds r0, r1, #0
	adds r1, r2, #0
	bl _call_via_r3
	b .L08097CB4
	.align 2, 0
.L08097CB0: .4byte gpShopSt
.L08097CB4:
	ldr r0, .L08097CF0 @ =gpShopSt
	ldr r1, [r0]
	ldrh r0, [r1, #0xc]
	ldr r1, .L08097CF0 @ =gpShopSt
	ldr r2, [r1]
	ldrh r1, [r2, #6]
	ldr r3, .L08097CF0 @ =gpShopSt
	ldr r2, [r3]
	ldrh r3, [r2, #8]
	muls r1, r3, r1
	ldr r2, .L08097CF0 @ =gpShopSt
	ldr r3, [r2]
	ldrh r2, [r3, #0xa]
	bl ShopUpdateBg2Offset
	adds r1, r0, #0
	ldr r2, .L08097CF0 @ =gpShopSt
	ldr r0, [r2]
	ldrh r2, [r0, #0xc]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #0xc]
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08097CF0: .4byte gpShopSt

	thumb_func_start ShopSt_GetHeadLoc
ShopSt_GetHeadLoc: @ 0x08097CF4
	push {r7, lr}
	mov r7, sp
	ldr r1, .L08097D04 @ =gpShopSt
	ldr r0, [r1]
	ldrh r1, [r0]
	adds r0, r1, #0
	b .L08097D08
	.align 2, 0
.L08097D04: .4byte gpShopSt
.L08097D08:
	pop {r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start ShopSt_GetBg2Offset
ShopSt_GetBg2Offset: @ 0x08097D10
	push {r7, lr}
	mov r7, sp
	ldr r1, .L08097D28 @ =gpShopSt
	ldr r0, [r1]
	ldr r2, .L08097D28 @ =gpShopSt
	ldr r1, [r2]
	ldrh r2, [r1, #0xc]
	ldr r0, [r0, #0x10]
	adds r1, r2, r0
	adds r0, r1, #0
	b .L08097D2C
	.align 2, 0
.L08097D28: .4byte gpShopSt
.L08097D2C:
	pop {r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start ShopSt_GetHandLoc
ShopSt_GetHandLoc: @ 0x08097D34
	push {r7, lr}
	mov r7, sp
	ldr r1, .L08097D44 @ =gpShopSt
	ldr r0, [r1]
	ldrh r1, [r0, #6]
	adds r0, r1, #0
	b .L08097D48
	.align 2, 0
.L08097D44: .4byte gpShopSt
.L08097D48:
	pop {r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08097D50
func_fe6_08097D50: @ 0x08097D50
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r1, .L08097D78 @ =gpShopSt
	ldr r0, [r1]
	ldr r2, [r7]
	adds r1, r2, #0
	ldrh r2, [r0, #8]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #8]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08097D78: .4byte gpShopSt

	thumb_func_start func_fe6_08097D7C
func_fe6_08097D7C: @ 0x08097D7C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r1, .L08097DA4 @ =gpShopSt
	ldr r0, [r1]
	ldr r2, [r7]
	adds r1, r2, #0
	ldrh r2, [r0, #0xa]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0xa]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08097DA4: .4byte gpShopSt

	thumb_func_start IsShopPageScrolling
IsShopPageScrolling: @ 0x08097DA8
	push {r7, lr}
	mov r7, sp
	ldr r0, .L08097DC8 @ =gpShopSt
	ldr r1, [r0]
	ldrh r0, [r1, #0xc]
	ldr r1, .L08097DC8 @ =gpShopSt
	ldr r2, [r1]
	ldrh r1, [r2, #6]
	ldr r3, .L08097DC8 @ =gpShopSt
	ldr r2, [r3]
	ldrh r3, [r2, #8]
	muls r1, r3, r1
	cmp r0, r1
	beq .L08097DCC
	movs r0, #1
	b .L08097DD0
	.align 2, 0
.L08097DC8: .4byte gpShopSt
.L08097DCC:
	movs r0, #0
	b .L08097DD0
.L08097DD0:
	pop {r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start ShouldDisplayUpArrow
ShouldDisplayUpArrow: @ 0x08097DD8
	push {r7, lr}
	mov r7, sp
	ldr r1, .L08097DEC @ =gpShopSt
	ldr r0, [r1]
	ldrh r1, [r0, #6]
	cmp r1, #0
	beq .L08097DF0
	movs r0, #1
	b .L08097DF4
	.align 2, 0
.L08097DEC: .4byte gpShopSt
.L08097DF0:
	movs r0, #0
	b .L08097DF4
.L08097DF4:
	pop {r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start ShouldDisplayDownArrow
ShouldDisplayDownArrow: @ 0x08097DFC
	push {r7, lr}
	mov r7, sp
	ldr r0, .L08097E1C @ =gpShopSt
	ldr r1, [r0]
	ldrh r0, [r1, #6]
	ldr r2, .L08097E1C @ =gpShopSt
	ldr r1, [r2]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	ldr r2, .L08097E1C @ =gpShopSt
	ldr r1, [r2]
	ldrh r2, [r1, #2]
	cmp r0, r2
	bge .L08097E20
	movs r0, #1
	b .L08097E24
	.align 2, 0
.L08097E1C: .4byte gpShopSt
.L08097E20:
	movs r0, #0
	b .L08097E24
.L08097E24:
	pop {r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08097E2C
func_fe6_08097E2C: @ 0x08097E2C
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08097E6C @ =gMusicPlayerTable
	ldr r2, .L08097E70 @ =gSongTable
	adds r1, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r2, r2, r1
	ldrh r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #1
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	str r1, [r7, #4]
	ldr r0, [r7, #4]
	ldr r1, [r0, #4]
	lsls r2, r1, #0x10
	lsrs r0, r2, #0x10
	cmp r0, #0
	bne .L08097E76
	ldr r0, [r7, #4]
	ldr r1, [r0, #4]
	lsrs r2, r1, #0x1f
	lsls r0, r2, #0x1f
	cmp r0, #0
	bne .L08097E76
	movs r0, #0
	b .L08097E7A
	.align 2, 0
.L08097E6C: .4byte gMusicPlayerTable
.L08097E70: .4byte gSongTable
.L08097E74:
	.byte 0x01, 0xE0
.L08097E76:
	movs r0, #1
	b .L08097E7A
.L08097E7A:
	add sp, #8
	pop {r7}
	pop {r1}
	bx r1
	.align 2, 0
