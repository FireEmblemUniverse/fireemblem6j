	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_0808D0C0
func_fe6_0808D0C0: @ 0x0808D0C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0808D0F0 @ =gBg0Tm+0x58
	movs r1, #6
	movs r2, #0xe
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L0808D0F4 @ =gBg1Tm+0x16
	movs r1, #8
	movs r2, #0x10
	movs r3, #0
	bl TmFillRect_thm
	adds r0, r4, #0
	bl EndMenu
	movs r0, #3
	bl EnableBgSync
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0808D0F0: .4byte gBg0Tm+0x58
.L0808D0F4: .4byte gBg1Tm+0x16

	thumb_func_start func_fe6_0808D0F8
func_fe6_0808D0F8: @ 0x0808D0F8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, .L0808D148 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	ble .L0808D15E
	movs r2, #0
	ldr r7, .L0808D14C @ =gUnk_0868AF74
.L0808D10C:
	ldrb r0, [r7, #1]
	str r2, [sp]
	bl GetUnitByPid
	ldr r2, [sp]
	cmp r0, #0
	beq .L0808D156
	movs r4, #1
	adds r6, r7, #0
	movs r1, #1
	adds r0, r2, #0
	eors r0, r1
	lsls r5, r0, #0x18
.L0808D126:
	adds r0, r4, #0
	str r2, [sp]
	bl GetUnit
	ldr r2, [sp]
	cmp r0, #0
	beq .L0808D150
	ldr r0, [r0]
	cmp r0, #0
	beq .L0808D150
	ldrb r0, [r0, #4]
	ldrb r1, [r6, #1]
	cmp r0, r1
	bne .L0808D150
	lsrs r0, r5, #0x18
	b .L0808D160
	.align 2, 0
.L0808D148: .4byte gPlaySt
.L0808D14C: .4byte gUnk_0868AF74
.L0808D150:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0808D126
.L0808D156:
	adds r7, #0x10
	adds r2, #1
	cmp r2, #1
	ble .L0808D10C
.L0808D15E:
	movs r0, #0xff
.L0808D160:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0808D168
func_fe6_0808D168: @ 0x0808D168
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl SetInitTalkTextFont
	bl ClearTalkText
	bl EndTalk
	adds r0, r4, #0
	bl DecodeMsg
	adds r2, r0, #0
	movs r0, #0xa
	movs r1, #0xe
	adds r3, r5, #0
	bl StartTalkExt
	movs r0, #1
	bl SetTalkPrintColor
	movs r0, #1
	bl SetTalkFlag
	movs r0, #2
	bl SetTalkFlag
	movs r0, #4
	bl SetTalkFlag
	movs r0, #3
	bl SetTalkPrintDelay
	movs r0, #1
	bl SetActiveTalkFace
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0808D1B8
func_fe6_0808D1B8: @ 0x0808D1B8
	push {r4, lr}
	adds r4, r0, #0
	bl SetInitTalkTextFont
	bl ClearTalkText
	bl EndTalk
	adds r0, r4, #0
	bl DecodeMsg
	adds r2, r0, #0
	movs r0, #0xa
	movs r1, #0xe
	bl StartTalk
	movs r0, #1
	bl SetTalkPrintColor
	movs r0, #1
	bl SetTalkFlag
	movs r0, #2
	bl SetTalkFlag
	movs r0, #4
	bl SetTalkFlag
	movs r0, #3
	bl SetTalkPrintDelay
	movs r0, #1
	bl SetActiveTalkFace
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0808D204
func_fe6_0808D204: @ 0x0808D204
	push {lr}
	ldr r0, .L0808D210 @ =gUnk_0868AFBE
	bl InitBgs
	pop {r0}
	bx r0
	.align 2, 0
.L0808D210: .4byte gUnk_0868AFBE

	thumb_func_start func_fe6_0808D214
func_fe6_0808D214: @ 0x0808D214
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	ldr r5, .L0808D2FC @ =gDispIo
	adds r2, r5, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r1, r5, #0
	adds r1, #0x44
	movs r3, #0
	movs r7, #0x10
	mov sb, r7
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #1
	movs r2, #1
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x46
	strb r3, [r0]
	ldr r0, .L0808D300 @ =0x0000FFE0
	ldrh r1, [r5, #0x3c]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	ldr r1, .L0808D304 @ =0x0000E0FF
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r5, #0x3c]
	movs r7, #0x20
	mov r8, r7
	mov r0, r8
	ldrb r1, [r5, #1]
	orrs r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r5, #1]
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0x40
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x68
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x98
	strb r0, [r1]
	adds r6, r5, #0
	adds r6, #0x34
	ldrb r0, [r6]
	orrs r0, r2
	movs r4, #2
	orrs r0, r4
	movs r3, #4
	orrs r0, r3
	movs r1, #8
	orrs r0, r1
	mov r7, sb
	orrs r0, r7
	adds r5, #0x36
	ldrb r7, [r5]
	orrs r2, r7
	orrs r2, r4
	orrs r2, r3
	orrs r2, r1
	mov r1, sb
	orrs r2, r1
	mov r3, r8
	orrs r0, r3
	strb r0, [r6]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r2, r0
	strb r2, [r5]
	movs r0, #9
	movs r1, #0xd
	movs r2, #0x14
	movs r3, #6
	bl PutTalkBubbleTm
	movs r0, #8
	movs r1, #0x10
	movs r2, #2
	bl PutTalkBubbleTail
	movs r0, #2
	bl EnableBgSync
	mov r0, sl
	bl func_fe6_0808D954
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808D2FC: .4byte gDispIo
.L0808D300: .4byte 0x0000FFE0
.L0808D304: .4byte 0x0000E0FF

	thumb_func_start func_fe6_0808D308
func_fe6_0808D308: @ 0x0808D308
	push {lr}
	ldr r1, .L0808D334 @ =gUnk_0868AF58
	ldr r0, .L0808D338 @ =0x020169CC
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r2, [r0]
	lsls r1, r2, #3
	subs r1, #2
	ldrb r0, [r0, #1]
	lsls r2, r0, #3
	ldr r0, .L0808D33C @ =0x020169DC
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L0808D340
	cmp r0, #2
	beq .L0808D34A
	b .L0808D352
	.align 2, 0
.L0808D334: .4byte gUnk_0868AF58
.L0808D338: .4byte 0x020169CC
.L0808D33C: .4byte 0x020169DC
.L0808D340:
	adds r0, r1, #0
	adds r1, r2, #0
	bl PutUiHand
	b .L0808D352
.L0808D34A:
	adds r0, r1, #0
	adds r1, r2, #0
	bl PutFrozenUiHand
.L0808D352:
	ldr r2, .L0808D364 @ =gUnk_0868AFA4
	movs r3, #0x82
	lsls r3, r3, #6
	movs r0, #0x20
	movs r1, #8
	bl PutOamHiRam
	pop {r0}
	bx r0
	.align 2, 0
.L0808D364: .4byte gUnk_0868AFA4

	thumb_func_start func_fe6_0808D368
func_fe6_0808D368: @ 0x0808D368
	ldr r1, .L0808D370 @ =0x020169DC
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
.L0808D370: .4byte 0x020169DC

	thumb_func_start func_fe6_0808D374
func_fe6_0808D374: @ 0x0808D374
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, .L0808D544 @ =0x020169CE
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L0808D548 @ =0x020169DC
	strb r1, [r0]
	bl func_fe6_0808D0F8
	ldr r1, .L0808D54C @ =0x020169DB
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne .L0808D396
	movs r0, #2
	strb r0, [r1]
.L0808D396:
	bl ResetText
	bl UnpackUiWindowFrameGraphics
	ldr r2, .L0808D550 @ =gDispIo
	movs r0, #1
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r0, .L0808D554 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r5, .L0808D558 @ =gBg1Tm
	adds r0, r5, #0
	movs r1, #0
	bl TmFill
	ldr r6, .L0808D55C @ =gBg3Tm
	adds r0, r6, #0
	movs r1, #0
	bl TmFill
	ldr r4, .L0808D560 @ =gUnk_0833C01C
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #0x20
	bl ApplyPaletteExt
	adds r4, #0x20
	movs r1, #0x90
	lsls r1, r1, #2
	adds r0, r4, #0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L0808D564 @ =gUnk_0833C09C
	ldr r1, .L0808D568 @ =0x06011000
	bl Decompress
	ldr r4, .L0808D56C @ =Img_MuralBackground
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	adds r0, r4, #0
	bl Decompress
	ldr r0, .L0808D570 @ =0x06003000
	bl UnpackUiWindowFrameImg
	bl UnpackUiWindowFrameGraphics
	ldr r1, .L0808D574 @ =gUnk_0833C1D8
	movs r4, #0x8c
	lsls r4, r4, #5
	adds r0, r5, #0
	adds r2, r4, #0
	bl TmApplyTsa_thm
	adds r5, #0x56
	ldr r1, .L0808D578 @ =gUnk_0833C234
	adds r0, r5, #0
	adds r2, r4, #0
	bl TmApplyTsa_thm
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r6, #0
	bl func_fe6_08090854
	bl ResetTextFont
	movs r6, #0
.L0808D460:
	lsls r5, r6, #3
	ldr r0, .L0808D57C @ =0x020169E0
	adds r5, r5, r0
	adds r0, r5, #0
	movs r1, #6
	bl InitText
	adds r0, r5, #0
	bl ClearText
	ldr r0, .L0808D580 @ =gUnk_0868AEB4
	lsls r4, r6, #2
	adds r0, r4, r0
	ldr r0, [r0]
	bl DecodeMsg
	ldr r1, .L0808D584 @ =gUnk_0868AF58
	adds r4, r4, r1
	ldrb r2, [r4, #1]
	lsls r1, r2, #5
	ldrb r4, [r4]
	adds r1, r4, r1
	lsls r1, r1, #1
	ldr r2, .L0808D554 @ =gBg0Tm
	adds r1, r1, r2
	movs r2, #6
	str r2, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl PutDrawText
	adds r6, #1
	cmp r6, #6
	ble .L0808D460
	ldr r1, .L0808D588 @ =0x020169CC
	movs r0, #0
	strh r0, [r1]
	movs r0, #0
	movs r1, #0
	bl func_fe6_0808D6D4
	movs r0, #0x80
	lsls r0, r0, #2
	movs r1, #2
	movs r2, #1
	bl InitTalk
	ldr r1, .L0808D58C @ =gUnk_0868AF74
	ldr r0, .L0808D54C @ =0x020169DB
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #1
	str r1, [sp]
	movs r1, #0x20
	movs r2, #0x50
	movs r3, #3
	bl StartTalkFace
	ldr r0, .L0808D590 @ =gUnk_0868AFD8
	movs r1, #3
	bl SpawnProc
	movs r0, #0xb
	bl EnableBgSync
	bl func_fe6_0808F33C
	ldr r5, .L0808D594 @ =0x02016A2E
	ldr r4, .L0808D598 @ =0x020169D4
	strb r0, [r4, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5]
	bl func_fe6_0808F490
	strb r0, [r4, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #2]
	bl func_fe6_0808F524
	strb r0, [r4, #3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #4]
	bl func_fe6_0808F5AC
	strb r0, [r4, #4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #6]
	bl func_fe6_0808F600
	strb r0, [r4, #5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #8]
	bl func_fe6_0808F68C
	strb r0, [r4, #6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0xa]
	bl func_fe6_0808F6E0
	strb r0, [r4]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808D544: .4byte 0x020169CE
.L0808D548: .4byte 0x020169DC
.L0808D54C: .4byte 0x020169DB
.L0808D550: .4byte gDispIo
.L0808D554: .4byte gBg0Tm
.L0808D558: .4byte gBg1Tm
.L0808D55C: .4byte gBg3Tm
.L0808D560: .4byte gUnk_0833C01C
.L0808D564: .4byte gUnk_0833C09C
.L0808D568: .4byte 0x06011000
.L0808D56C: .4byte Img_MuralBackground
.L0808D570: .4byte 0x06003000
.L0808D574: .4byte gUnk_0833C1D8
.L0808D578: .4byte gUnk_0833C234
.L0808D57C: .4byte 0x020169E0
.L0808D580: .4byte gUnk_0868AEB4
.L0808D584: .4byte gUnk_0868AF58
.L0808D588: .4byte 0x020169CC
.L0808D58C: .4byte gUnk_0868AF74
.L0808D590: .4byte gUnk_0868AFD8
.L0808D594: .4byte 0x02016A2E
.L0808D598: .4byte 0x020169D4

	thumb_func_start func_fe6_0808D59C
func_fe6_0808D59C: @ 0x0808D59C
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, .L0808D5B0 @ =0x020169CE
	ldrh r1, [r3]
	cmp r1, #0
	beq .L0808D5B4
	cmp r1, #1
	beq .L0808D5D0
	b .L0808D62A
	.align 2, 0
.L0808D5B0: .4byte 0x020169CE
.L0808D5B4:
	ldr r0, .L0808D5C8 @ =0x020169D0
	strh r1, [r0]
	ldr r1, .L0808D5CC @ =0x020169D2
	movs r0, #0x10
	strh r0, [r1]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	b .L0808D62A
	.align 2, 0
.L0808D5C8: .4byte 0x020169D0
.L0808D5CC: .4byte 0x020169D2
.L0808D5D0:
	ldr r2, .L0808D614 @ =0x020169D2
	ldrh r0, [r2]
	lsrs r1, r0, #2
	cmp r1, #0
	bne .L0808D5DC
	movs r1, #1
.L0808D5DC:
	cmp r0, #1
	bls .L0808D620
	ldr r0, .L0808D618 @ =0x020169D0
	ldrh r4, [r0]
	adds r3, r4, r1
	strh r3, [r0]
	ldrh r0, [r2]
	subs r4, r0, r1
	strh r4, [r2]
	ldr r1, .L0808D61C @ =gDispIo
	mov ip, r1
	mov r2, ip
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x44
	movs r1, #0
	strb r3, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r1, [r0]
	b .L0808D62A
	.align 2, 0
.L0808D614: .4byte 0x020169D2
.L0808D618: .4byte 0x020169D0
.L0808D61C: .4byte gDispIo
.L0808D620:
	movs r0, #0
	strh r0, [r3]
	adds r0, r4, #0
	bl Proc_Break
.L0808D62A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0808D630
func_fe6_0808D630: @ 0x0808D630
	push {r4, r5, lr}
	ldr r5, .L0808D640 @ =0x020169CE
	ldrh r1, [r5]
	cmp r1, #0
	beq .L0808D644
	cmp r1, #1
	beq .L0808D678
	b .L0808D6CE
	.align 2, 0
.L0808D640: .4byte 0x020169CE
.L0808D644:
	bl IsTalkActive
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	cmp r4, #0
	bne .L0808D6CE
	bl ClearTalkText
	bl EndTalk
	movs r0, #1
	bl EnableBgSync
	ldr r1, .L0808D670 @ =0x020169D0
	movs r0, #0x10
	strh r0, [r1]
	ldr r0, .L0808D674 @ =0x020169D2
	strh r4, [r0]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	b .L0808D6CE
	.align 2, 0
.L0808D670: .4byte 0x020169D0
.L0808D674: .4byte 0x020169D2
.L0808D678:
	ldr r3, .L0808D6BC @ =0x020169D0
	ldrh r4, [r3]
	lsrs r1, r4, #2
	cmp r1, #0
	bne .L0808D684
	movs r1, #1
.L0808D684:
	adds r2, r4, #0
	cmp r2, #0
	beq .L0808D6C8
	subs r4, r4, r1
	strh r4, [r3]
	ldr r0, .L0808D6C0 @ =0x020169D2
	ldrh r2, [r0]
	adds r3, r2, r1
	strh r3, [r0]
	ldr r0, .L0808D6C4 @ =gDispIo
	mov ip, r0
	mov r2, ip
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x44
	movs r1, #0
	strb r4, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r1, [r0]
	b .L0808D6CE
	.align 2, 0
.L0808D6BC: .4byte 0x020169D0
.L0808D6C0: .4byte 0x020169D2
.L0808D6C4: .4byte gDispIo
.L0808D6C8:
	strh r2, [r5]
	bl Proc_Break
.L0808D6CE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0808D6D4
func_fe6_0808D6D4: @ 0x0808D6D4
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r6, r5, #0
	ldr r2, .L0808D79C @ =0x000011DE
	ldr r3, .L0808D7A0 @ =0x000011DD
	cmp r0, #3
	bhi .L0808D6EE
	adds r1, r2, #0
	adds r2, r3, #0
	adds r3, r1, #0
.L0808D6EE:
	ldr r7, .L0808D7A4 @ =gUnk_0868AF58
	lsls r0, r0, #2
	adds r0, r0, r7
	ldrb r1, [r0, #1]
	adds r1, #1
	lsls r1, r1, #5
	ldrb r0, [r0]
	adds r1, r0, r1
	subs r0, r1, #1
	ldr r4, .L0808D7A8 @ =gBg1Tm
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r2, [r0]
	lsls r0, r1, #1
	adds r0, r0, r4
	strh r3, [r0]
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r2, [r0]
	adds r0, r1, #2
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r3, [r0]
	adds r0, r1, #3
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r2, [r0]
	adds r0, r1, #4
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r3, [r0]
	adds r1, #5
	lsls r1, r1, #1
	adds r1, r1, r4
	strh r2, [r1]
	ldr r2, .L0808D7AC @ =0x000011F8
	ldr r3, .L0808D7B0 @ =0x000011FB
	cmp r5, #3
	bhi .L0808D744
	adds r1, r2, #0
	adds r2, r3, #0
	adds r3, r1, #0
.L0808D744:
	lsls r0, r6, #2
	adds r0, r0, r7
	ldrb r1, [r0, #1]
	adds r1, #1
	lsls r1, r1, #5
	ldrb r0, [r0]
	adds r1, r0, r1
	subs r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r2, [r0]
	adds r2, #1
	adds r3, #1
	lsls r0, r1, #1
	adds r0, r0, r4
	strh r2, [r0]
	adds r0, r1, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r3, [r0]
	adds r0, r1, #2
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r2, [r0]
	adds r0, r1, #3
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r3, [r0]
	adds r0, r1, #4
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r2, [r0]
	adds r3, #1
	adds r1, #5
	lsls r1, r1, #1
	adds r1, r1, r4
	strh r3, [r1]
	movs r0, #2
	bl EnableBgSync
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808D79C: .4byte 0x000011DE
.L0808D7A0: .4byte 0x000011DD
.L0808D7A4: .4byte gUnk_0868AF58
.L0808D7A8: .4byte gBg1Tm
.L0808D7AC: .4byte 0x000011F8
.L0808D7B0: .4byte 0x000011FB

	thumb_func_start func_fe6_0808D7B4
func_fe6_0808D7B4: @ 0x0808D7B4
	push {lr}
	ldr r0, .L0808D7E8 @ =gUnk_0868AF74
	ldr r1, .L0808D7EC @ =0x020169DB
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r0, .L0808D7F0 @ =0x020169CC
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl func_fe6_0808D1B8
	ldr r0, .L0808D7F4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0808D7E4
	movs r0, #0x66
	bl m4aSongNumStart
.L0808D7E4:
	pop {r0}
	bx r0
	.align 2, 0
.L0808D7E8: .4byte gUnk_0868AF74
.L0808D7EC: .4byte 0x020169DB
.L0808D7F0: .4byte 0x020169CC
.L0808D7F4: .4byte gPlaySt

	thumb_func_start func_fe6_0808D7F8
func_fe6_0808D7F8: @ 0x0808D7F8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r2, #4
	ldr r0, .L0808D820 @ =gKeySt
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	cmp r0, #1
	beq .L0808D828
	cmp r0, #2
	beq .L0808D858
	ldr r0, .L0808D824 @ =0x020169CC
	movs r3, #0
	ldrsh r4, [r0, r3]
	ldrh r1, [r1, #6]
	adds r6, r0, #0
	cmp r1, #0x20
	beq .L0808D8D0
	cmp r1, #0x20
	bgt .L0808D89A
	b .L0808D894
	.align 2, 0
.L0808D820: .4byte gKeySt
.L0808D824: .4byte 0x020169CC
.L0808D828:
	bl ClearTalkText
	bl EndTalk
	ldr r1, .L0808D850 @ =0x020169DC
	movs r0, #2
	strb r0, [r1]
	ldr r0, .L0808D854 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0808D846
	movs r0, #0x6a
	bl m4aSongNumStart
.L0808D846:
	adds r0, r5, #0
	movs r1, #3
	bl Proc_Goto
	b .L0808D8FA
	.align 2, 0
.L0808D850: .4byte 0x020169DC
.L0808D854: .4byte gPlaySt
.L0808D858:
	bl ClearTalkText
	bl EndTalk
	ldr r0, .L0808D88C @ =gBg1Tm+0x350
	movs r1, #0x15
	movs r2, #6
	movs r3, #0
	bl TmFillRect_thm
	movs r0, #2
	bl EnableBgSync
	ldr r0, .L0808D890 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0808D882
	movs r0, #0x6b
	bl m4aSongNumStart
.L0808D882:
	adds r0, r5, #0
	movs r1, #4
	bl Proc_Goto
	b .L0808D8FA
	.align 2, 0
.L0808D88C: .4byte gBg1Tm+0x350
.L0808D890: .4byte gPlaySt
.L0808D894:
	cmp r1, #0x10
	beq .L0808D8D0
	b .L0808D8E0
.L0808D89A:
	cmp r1, #0x40
	beq .L0808D8A4
	cmp r1, #0x80
	beq .L0808D8B8
	b .L0808D8E0
.L0808D8A4:
	cmp r4, #4
	bge .L0808D8B0
	cmp r4, #0
	bne .L0808D8B4
	movs r4, #3
	b .L0808D8E0
.L0808D8B0:
	cmp r4, #4
	ble .L0808D8DA
.L0808D8B4:
	subs r4, #1
	b .L0808D8E0
.L0808D8B8:
	cmp r4, #4
	bge .L0808D8C4
	cmp r4, #3
	blt .L0808D8C8
	movs r4, #0
	b .L0808D8E0
.L0808D8C4:
	cmp r4, #5
	bgt .L0808D8CC
.L0808D8C8:
	adds r4, #1
	b .L0808D8E0
.L0808D8CC:
	movs r4, #4
	b .L0808D8E0
.L0808D8D0:
	cmp r4, r2
	bge .L0808D8DE
	adds r4, r4, r2
	cmp r4, #6
	ble .L0808D8E0
.L0808D8DA:
	movs r4, #6
	b .L0808D8E0
.L0808D8DE:
	subs r4, r4, r2
.L0808D8E0:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, r4
	beq .L0808D8FA
	ldrh r0, [r6]
	lsls r1, r4, #0x10
	lsrs r1, r1, #0x10
	bl func_fe6_0808D6D4
	strh r4, [r6]
	adds r0, r5, #0
	bl func_fe6_0808D7B4
.L0808D8FA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0808D900
func_fe6_0808D900: @ 0x0808D900
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0808D91C @ =gKeySt
	ldr r1, [r0]
	movs r0, #2
	ldrh r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L0808D920
	adds r0, r4, #0
	movs r1, #4
	bl Proc_Goto
	b .L0808D930
	.align 2, 0
.L0808D91C: .4byte gKeySt
.L0808D920:
	bl IsTalkActive
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0808D930
	adds r0, r4, #0
	bl Proc_Break
.L0808D930:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0808D938
func_fe6_0808D938: @ 0x0808D938
	push {r4, lr}
	adds r4, r0, #0
	bl IsTalkActive
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0808D94C
	adds r0, r4, #0
	bl Proc_Break
.L0808D94C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0808D954
func_fe6_0808D954: @ 0x0808D954
	push {lr}
	adds r1, r0, #0
	ldr r2, .L0808D970 @ =gUnk_0868AF74
	ldr r0, .L0808D974 @ =0x020169DB
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r2, #4
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r0, [r0]
	bl func_fe6_0808D168
	pop {r0}
	bx r0
	.align 2, 0
.L0808D970: .4byte gUnk_0868AF74
.L0808D974: .4byte 0x020169DB

	thumb_func_start func_fe6_0808D978
func_fe6_0808D978: @ 0x0808D978
	push {lr}
	adds r1, r0, #0
	ldr r2, .L0808D994 @ =gUnk_0868AF74
	ldr r0, .L0808D998 @ =0x020169DB
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r2, #4
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r0, [r0, #4]
	bl func_fe6_0808D168
	pop {r0}
	bx r0
	.align 2, 0
.L0808D994: .4byte gUnk_0868AF74
.L0808D998: .4byte 0x020169DB

	thumb_func_start func_fe6_0808D99C
func_fe6_0808D99C: @ 0x0808D99C
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0808D9AC @ =0x000006FF
	bl func_fe6_0808D168
	pop {r0}
	bx r0
	.align 2, 0
.L0808D9AC: .4byte 0x000006FF

	thumb_func_start func_fe6_0808D9B0
func_fe6_0808D9B0: @ 0x0808D9B0
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, .L0808D9E0 @ =gUnk_0868AF74
	ldr r2, .L0808D9E4 @ =0x020169DB
	ldrb r2, [r2]
	lsls r2, r2, #4
	adds r0, #8
	adds r2, r2, r0
	ldr r3, .L0808D9E8 @ =0x020169D4
	ldr r0, .L0808D9EC @ =0x020169CC
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r0, r0, r3
	ldr r2, [r2]
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl func_fe6_0808D168
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808D9E0: .4byte gUnk_0868AF74
.L0808D9E4: .4byte 0x020169DB
.L0808D9E8: .4byte 0x020169D4
.L0808D9EC: .4byte 0x020169CC

	thumb_func_start func_fe6_0808D9F0
func_fe6_0808D9F0: @ 0x0808D9F0
	push {lr}
	adds r1, r0, #0
	ldr r2, .L0808DA0C @ =gUnk_0868AF74
	ldr r0, .L0808DA10 @ =0x020169DB
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r2, #4
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r0, [r0, #8]
	bl func_fe6_0808D168
	pop {r0}
	bx r0
	.align 2, 0
.L0808DA0C: .4byte gUnk_0868AF74
.L0808DA10: .4byte 0x020169DB

	thumb_func_start func_fe6_0808DA14
func_fe6_0808DA14: @ 0x0808DA14
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r4, r1, #0
	mov r8, r2
	adds r7, r3, #0
	ldr r0, [sp, #0x1c]
	lsls r0, r0, #5
	movs r1, #0x10
	bl Div
	adds r6, r0, #0
	mov r5, r8
	adds r0, r5, r7
	cmp r5, r0
	bge .L0808DA84
	movs r0, #0x1f
	mov ip, r0
	lsls r1, r5, #1
	lsls r0, r4, #5
	add r0, sb
	adds r4, r1, r0
.L0808DA44:
	ldrh r1, [r4]
	movs r3, #0x1f
	ands r3, r1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x15
	mov r0, ip
	ands r2, r0
	lsrs r1, r1, #0x1a
	ands r1, r0
	adds r0, r3, #0
	muls r0, r6, r0
	asrs r0, r0, #5
	subs r3, r3, r0
	adds r0, r2, #0
	muls r0, r6, r0
	asrs r0, r0, #5
	subs r2, r2, r0
	adds r0, r1, #0
	muls r0, r6, r0
	asrs r0, r0, #5
	subs r1, r1, r0
	lsls r2, r2, #5
	orrs r3, r2
	lsls r1, r1, #0xa
	orrs r3, r1
	strh r3, [r4]
	adds r4, #2
	adds r5, #1
	mov r1, r8
	adds r0, r1, r7
	cmp r5, r0
	blt .L0808DA44
.L0808DA84:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0808DA90
func_fe6_0808DA90: @ 0x0808DA90
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	adds r4, r1, #0
	mov sb, r2
	mov r8, r3
	ldr r0, [sp, #0x20]
	lsls r0, r0, #5
	movs r1, #0x10
	bl Div
	adds r7, r0, #0
	mov r5, sb
	mov r1, r8
	adds r0, r5, r1
	cmp r5, r0
	bge .L0808DB06
	movs r0, #0x1f
	mov ip, r0
	movs r6, #0x1f
	lsls r1, r5, #1
	lsls r0, r4, #5
	add r0, sl
	adds r4, r1, r0
.L0808DAC6:
	ldrh r1, [r4]
	adds r3, r6, #0
	ands r3, r1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x15
	mov r0, ip
	ands r2, r0
	lsrs r1, r1, #0x1a
	ands r1, r0
	subs r0, r6, r3
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r3, r3, r0
	subs r0, r6, r2
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r2, r2, r0
	subs r0, r6, r1
	muls r0, r7, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	lsls r2, r2, #5
	orrs r3, r2
	lsls r1, r1, #0xa
	orrs r3, r1
	strh r3, [r4]
	adds r4, #2
	adds r5, #1
	mov r0, sb
	add r0, r8
	cmp r5, r0
	blt .L0808DAC6
.L0808DB06:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0808DB14
func_fe6_0808DB14: @ 0x0808DB14
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r7, [sp, #0x20]
	movs r4, #0x37
	str r4, [sp]
	movs r0, #1
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl Interpolate
	adds r6, r0, #0
	str r4, [sp]
	movs r0, #1
	mov r1, r8
	mov r2, sb
	adds r3, r7, #0
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0808DB88 @ =gUnk_0833C01C
	ldr r4, .L0808DB8C @ =gPal+0x80
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	subs r4, #0x80
	str r6, [sp]
	adds r0, r4, #0
	movs r1, #4
	movs r2, #0xa
	movs r3, #5
	bl func_fe6_0808DA90
	str r5, [sp]
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	movs r3, #8
	bl func_fe6_0808DA14
	bl EnablePalSync
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808DB88: .4byte gUnk_0833C01C
.L0808DB8C: .4byte gPal+0x80

	thumb_func_start func_fe6_0808DB90
func_fe6_0808DB90: @ 0x0808DB90
	movs r1, #0
	strh r1, [r0, #0x2a]
	strh r1, [r0, #0x2c]
	bx lr

	thumb_func_start func_fe6_0808DB98
func_fe6_0808DB98: @ 0x0808DB98
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x2c
	ldrsh r5, [r4, r0]
	cmp r5, #5
	beq .L0808DBDA
	cmp r5, #5
	bgt .L0808DBB0
	cmp r5, #0
	beq .L0808DBB6
	b .L0808DC20
.L0808DBB0:
	cmp r5, #0xa
	beq .L0808DC1C
	b .L0808DC20
.L0808DBB6:
	movs r1, #0x2a
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #5
	movs r2, #0
	movs r3, #4
	bl func_fe6_0808DB14
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x37
	ble .L0808DC26
	strh r5, [r4, #0x2a]
	b .L0808DC20
.L0808DBDA:
	movs r1, #0x2a
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #5
	movs r1, #0
	movs r2, #4
	movs r3, #0
	bl func_fe6_0808DB14
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x37
	ble .L0808DC26
	movs r0, #0
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	ldr r0, .L0808DC18 @ =0x02016A18
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0808DC26
	adds r0, r4, #0
	bl Proc_Break
	b .L0808DC26
	.align 2, 0
.L0808DC18: .4byte 0x02016A18
.L0808DC1C:
	movs r0, #0
	b .L0808DC24
.L0808DC20:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
.L0808DC24:
	strh r0, [r4, #0x2c]
.L0808DC26:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0808DC30
func_fe6_0808DC30: @ 0x0808DC30
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	strh r5, [r4, #0x2a]
	bl GetCurrentBgmSong
	str r0, [r4, #0x30]
	ldr r0, .L0808DC48 @ =0x02016A18
	strh r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0808DC48: .4byte 0x02016A18

	thumb_func_start func_fe6_0808DC4C
func_fe6_0808DC4C: @ 0x0808DC4C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0808DC6C @ =0x020169DB
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0808DCA6
	movs r1, #0x2a
	ldrsh r0, [r4, r1]
	cmp r0, #0x1e
	beq .L0808DC84
	cmp r0, #0x1e
	bgt .L0808DC70
	cmp r0, #0
	beq .L0808DC76
	b .L0808DCFC
	.align 2, 0
.L0808DC6C: .4byte 0x020169DB
.L0808DC70:
	cmp r0, #0xd2
	beq .L0808DC9C
	b .L0808DCCA
.L0808DC76:
	ldr r0, .L0808DC80 @ =gUnk_0868AFF0
	movs r1, #3
	bl SpawnProc
	b .L0808DCFC
	.align 2, 0
.L0808DC80: .4byte gUnk_0868AFF0
.L0808DC84:
	ldr r0, .L0808DC98 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0808DCFC
	movs r0, #0x41
	bl m4aSongNumStart
	b .L0808DCFC
	.align 2, 0
.L0808DC98: .4byte gPlaySt
.L0808DC9C:
	movs r0, #1
	rsbs r0, r0, #0
	bl FadeBgmOut
	b .L0808DCFC
.L0808DCA6:
	movs r1, #0x2a
	ldrsh r0, [r4, r1]
	cmp r0, #0x69
	beq .L0808DCD8
	cmp r0, #0x69
	bgt .L0808DCBC
	cmp r0, #0
	beq .L0808DCD0
	cmp r0, #0x41
	beq .L0808DCD8
	b .L0808DCFC
.L0808DCBC:
	cmp r0, #0x96
	beq .L0808DCD8
	cmp r0, #0x96
	bgt .L0808DCCA
	cmp r0, #0x73
	beq .L0808DCD8
	b .L0808DCFC
.L0808DCCA:
	cmp r0, #0xe6
	beq .L0808DCF4
	b .L0808DCFC
.L0808DCD0:
	ldr r0, .L0808DCEC @ =gUnk_0868AFF0
	movs r1, #3
	bl SpawnProc
.L0808DCD8:
	ldr r0, .L0808DCF0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0808DCFC
	movs r0, #0xee
	bl m4aSongNumStart
	b .L0808DCFC
	.align 2, 0
.L0808DCEC: .4byte gUnk_0868AFF0
.L0808DCF0: .4byte gPlaySt
.L0808DCF4:
	ldr r1, .L0808DD20 @ =0x02016A18
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L0808DCFC:
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
	ldr r0, .L0808DD20 @ =0x02016A18
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0808DD1A
	ldr r0, [r4, #0x30]
	movs r1, #0
	bl StartBgm
	adds r0, r4, #0
	bl Proc_Break
.L0808DD1A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808DD20: .4byte 0x02016A18

	thumb_func_start func_fe6_0808DD24
func_fe6_0808DD24: @ 0x0808DD24
	push {lr}
	bl ClearPutTalkText
	bl EndTalk
	bl ClearTalk
	ldr r0, .L0808DD3C @ =gUnk_0868AFD8
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
.L0808DD3C: .4byte gUnk_0868AFD8

	thumb_func_start func_fe6_0808DD40
func_fe6_0808DD40: @ 0x0808DD40
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r6, .L0808DD70 @ =gUnk_0868B3FC
	ldr r0, .L0808DD74 @ =gUnk_0868B420
	adds r4, r0, #0
	adds r4, #0xc
.L0808DD4C:
	ldr r2, [r6]
	lsls r3, r5, #1
	adds r0, r2, #0
	adds r0, #0x42
	adds r0, r0, r3
	ldrb r1, [r4]
	strh r1, [r0]
	adds r2, #0x50
	adds r2, r2, r3
	ldrb r0, [r4, #1]
	strh r0, [r2]
	adds r4, #0x10
	adds r5, #1
	cmp r5, #6
	ble .L0808DD4C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808DD70: .4byte gUnk_0868B3FC
.L0808DD74: .4byte gUnk_0868B420

	thumb_func_start func_fe6_0808DD78
func_fe6_0808DD78: @ 0x0808DD78
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r6, .L0808DDF8 @ =gUnk_0868B3FC
	ldr r0, .L0808DDFC @ =gUnk_0868B490
	adds r5, r0, #0
	adds r5, #0xc
.L0808DD84:
	ldr r2, [r6]
	lsls r3, r4, #1
	adds r0, r2, #0
	adds r0, #0x42
	adds r0, r0, r3
	ldrb r1, [r5]
	strh r1, [r0]
	adds r2, #0x50
	adds r2, r2, r3
	ldrb r0, [r5, #1]
	strh r0, [r2]
	adds r5, #0x10
	adds r4, #1
	cmp r4, #3
	ble .L0808DD84
	bl func_fe6_0808F3E8
	ldr r5, .L0808DE00 @ =0x02016A2E
	ldr r4, .L0808DDF8 @ =gUnk_0868B3FC
	ldr r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, #0x6c
	strh r0, [r1]
	strh r0, [r5]
	bl func_fe6_0808F550
	ldr r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, #0x6e
	strh r0, [r1]
	strh r0, [r5, #2]
	bl func_fe6_0808F4B8
	ldr r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, #0x70
	strh r0, [r1]
	strh r0, [r5, #4]
	bl func_fe6_0808F73C
	ldr r1, [r4]
	adds r1, #0x72
	strh r0, [r1]
	movs r4, #0
.L0808DDE2:
	adds r0, r4, #0
	movs r1, #0
	bl func_fe6_0808DF78
	adds r4, #1
	cmp r4, #3
	ble .L0808DDE2
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808DDF8: .4byte gUnk_0868B3FC
.L0808DDFC: .4byte gUnk_0868B490
.L0808DE00: .4byte 0x02016A2E

	thumb_func_start func_fe6_0808DE04
func_fe6_0808DE04: @ 0x0808DE04
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	movs r0, #8
	str r0, [sp]
	movs r0, #1
	adds r1, r4, #0
	adds r2, r5, #0
	adds r3, r6, #0
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0808DE54 @ =gUnk_08342AB8
	mov r2, r8
	lsls r1, r2, #5
	ldr r4, .L0808DE58 @ =gPal
	adds r1, r1, r4
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	mov r1, r8
	movs r2, #1
	adds r3, r5, #0
	bl EfxPalWhiteInOut
	bl EnablePalSync
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808DE54: .4byte gUnk_08342AB8
.L0808DE58: .4byte gPal

	thumb_func_start func_fe6_0808DE5C
func_fe6_0808DE5C: @ 0x0808DE5C
	movs r1, #0
	strh r1, [r0, #0x2a]
	strh r1, [r0, #0x2c]
	ldr r1, .L0808DE6C @ =gUnk_0868B5E0
	ldrb r1, [r1]
	strh r1, [r0, #0x2e]
	bx lr
	.align 2, 0
.L0808DE6C: .4byte gUnk_0868B5E0

	thumb_func_start func_fe6_0808DE70
func_fe6_0808DE70: @ 0x0808DE70
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x2a
	ldrsh r2, [r4, r0]
	ldrh r3, [r4, #0x36]
	adds r3, #0x14
	movs r0, #8
	movs r1, #0x10
	bl func_fe6_0808DE04
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble .L0808DE9C
	movs r0, #0
	strh r0, [r4, #0x2a]
	adds r0, r4, #0
	bl Proc_Break
.L0808DE9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0808DEA4
func_fe6_0808DEA4: @ 0x0808DEA4
	push {r4, lr}
	sub sp, #0x48
	adds r4, r0, #0
	movs r1, #0x2a
	ldrsh r0, [r4, r1]
	cmp r0, #8
	bgt .L0808DEC6
	adds r2, r0, #0
	ldrh r3, [r4, #0x36]
	adds r3, #0x14
	movs r0, #0x10
	movs r1, #0
	bl func_fe6_0808DE04
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
.L0808DEC6:
	movs r0, #0
	str r0, [sp, #0x1c]
	ldr r0, .L0808DF30 @ =gUnk_0868B5C8
	str r0, [sp, #0x3c]
	mov r1, sp
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	adds r0, #7
	lsls r0, r0, #3
	strh r0, [r1, #2]
	movs r3, #0x34
	ldrsh r0, [r4, r3]
	adds r0, #1
	lsls r0, r0, #3
	strh r0, [r1, #4]
	mov r2, sp
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r3, .L0808DF34 @ =0xFFFFC000
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2, #8]
	mov r0, sp
	bl BasPutOam
	ldrh r0, [r4, #0x2e]
	subs r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0808DF28
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	ldr r1, .L0808DF38 @ =gUnk_0868B5E0
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	adds r0, r0, r1
	ldrb r0, [r0]
	strh r0, [r4, #0x2e]
	cmp r0, #0
	bne .L0808DF28
	adds r0, r4, #0
	bl Proc_Break
.L0808DF28:
	add sp, #0x48
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808DF30: .4byte gUnk_0868B5C8
.L0808DF34: .4byte 0xFFFFC000
.L0808DF38: .4byte gUnk_0868B5E0

	thumb_func_start func_fe6_0808DF3C
func_fe6_0808DF3C: @ 0x0808DF3C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	ldr r0, .L0808DF70 @ =gUnk_08342AD8
	movs r1, #0xe0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L0808DF74 @ =gUnk_0868B5E8
	movs r1, #3
	bl SpawnProc
	strh r4, [r0, #0x36]
	strh r5, [r0, #0x32]
	strh r6, [r0, #0x34]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808DF70: .4byte gUnk_08342AD8
.L0808DF74: .4byte gUnk_0868B5E8

	thumb_func_start func_fe6_0808DF78
func_fe6_0808DF78: @ 0x0808DF78
	push {lr}
	adds r3, r0, #0
	ldr r0, .L0808DFB8 @ =gUnk_0868B3FC
	ldr r0, [r0]
	mov ip, r0
	lsls r2, r3, #1
	adds r0, #0x5e
	adds r0, r0, r2
	strh r1, [r0]
	lsls r0, r3, #2
	mov r2, ip
	adds r2, #0x7c
	adds r2, r2, r0
	ldr r0, .L0808DFBC @ =gUnk_0868B4D0
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	mov r0, ip
	adds r0, #0x98
	adds r0, r0, r3
	ldrb r1, [r1, #4]
	strb r1, [r0]
	ldr r0, .L0808DFC0 @ =gUnk_08342AB8
	adds r3, #0x14
	lsls r3, r3, #5
	adds r1, r3, #0
	movs r2, #0x20
	bl ApplyPaletteExt
	pop {r0}
	bx r0
	.align 2, 0
.L0808DFB8: .4byte gUnk_0868B3FC
.L0808DFBC: .4byte gUnk_0868B4D0
.L0808DFC0: .4byte gUnk_08342AB8

	thumb_func_start func_fe6_0808DFC4
func_fe6_0808DFC4: @ 0x0808DFC4
	movs r1, #0
	strh r1, [r0, #0x2a]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0808DFCC
func_fe6_0808DFCC: @ 0x0808DFCC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x80
	lsls r0, r0, #1
	mov r8, r0
	movs r1, #0x2a
	ldrsh r3, [r7, r1]
	movs r2, #8
	str r2, [sp]
	movs r0, #5
	movs r1, #2
	mov r2, r8
	bl Interpolate
	mov sb, r0
	ldr r4, .L0808E0A0 @ =gSinLut
	movs r0, #0x80
	adds r0, r0, r4
	mov sl, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	mov r1, sb
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r2, #0
	ldrsh r0, [r4, r2]
	rsbs r0, r0, #0
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r0, r0, #4
	mov r1, sb
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r2, sl
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0x1f
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	ldr r0, .L0808E0A4 @ =gKeySt
	ldr r1, [r0]
	movs r0, #1
	ldrh r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L0808E068
	ldrh r0, [r7, #0x2a]
	adds r0, #1
	strh r0, [r7, #0x2a]
.L0808E068:
	ldrh r0, [r7, #0x2a]
	adds r1, r0, #1
	strh r1, [r7, #0x2a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble .L0808E0CA
	movs r2, #8
	strh r2, [r7, #0x2a]
	ldr r0, .L0808E0A8 @ =gUnk_0868B3FC
	ldr r1, [r0]
	adds r0, r7, #0
	adds r0, #0x9f
	ldrb r3, [r0]
	lsls r2, r3, #1
	adds r0, r1, #0
	adds r0, #0x5e
	adds r0, r0, r2
	adds r1, #0x6c
	adds r1, r1, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs .L0808E0AC
	adds r0, r7, #0
	bl Proc_Break
	b .L0808E0CA
	.align 2, 0
.L0808E0A0: .4byte gSinLut
.L0808E0A4: .4byte gKeySt
.L0808E0A8: .4byte gUnk_0868B3FC
.L0808E0AC:
	cmp r3, #5
	bhi .L0808E0C2
	cmp r0, #3
	bls .L0808E0C2
	movs r0, #0x32
	ldrsh r1, [r7, r0]
	movs r0, #0x34
	ldrsh r2, [r7, r0]
	adds r0, r3, #0
	bl func_fe6_0808DF3C
.L0808E0C2:
	adds r0, r7, #0
	movs r1, #1
	bl Proc_Goto
.L0808E0CA:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0808E0DC
func_fe6_0808E0DC: @ 0x0808E0DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x80
	lsls r0, r0, #1
	mov r8, r0
	movs r1, #0x2a
	ldrsh r0, [r7, r1]
	movs r3, #0x11
	subs r3, r3, r0
	movs r0, #8
	str r0, [sp]
	movs r0, #5
	movs r1, #2
	mov r2, r8
	bl Interpolate
	mov sb, r0
	ldr r4, .L0808E1C4 @ =gSinLut
	movs r2, #0x80
	adds r2, r2, r4
	mov sl, r2
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #4
	mov r1, sb
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r2, #0
	ldrsh r0, [r4, r2]
	rsbs r0, r0, #0
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r0, r0, #4
	mov r1, sb
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r2, sl
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0x1f
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	ldr r0, .L0808E1C8 @ =gKeySt
	ldr r1, [r0]
	movs r0, #1
	ldrh r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L0808E17C
	ldrh r0, [r7, #0x2a]
	adds r0, #1
	strh r0, [r7, #0x2a]
.L0808E17C:
	ldrh r0, [r7, #0x2a]
	adds r1, r0, #1
	strh r1, [r7, #0x2a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	ble .L0808E1B4
	movs r0, #0x10
	strh r0, [r7, #0x2a]
	ldr r0, .L0808E1CC @ =gUnk_0868B3FC
	ldr r0, [r0]
	adds r1, r7, #0
	adds r1, #0x9f
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r0, #0x5e
	adds r0, r0, r1
	ldrh r1, [r0]
	cmp r1, #5
	bgt .L0808E1B4
	adds r1, #1
	adds r0, r2, #0
	bl func_fe6_0808DF78
	adds r0, r7, #0
	movs r1, #0
	bl Proc_Goto
.L0808E1B4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808E1C4: .4byte gSinLut
.L0808E1C8: .4byte gKeySt
.L0808E1CC: .4byte gUnk_0868B3FC

	thumb_func_start func_fe6_0808E1D0
func_fe6_0808E1D0: @ 0x0808E1D0
	ldr r0, .L0808E1E0 @ =gUnk_0868B3FC
	ldr r0, [r0]
	adds r0, #0x9f
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
.L0808E1E0: .4byte gUnk_0868B3FC

	thumb_func_start func_fe6_0808E1E4
func_fe6_0808E1E4: @ 0x0808E1E4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #4
	ldr r4, .L0808E260 @ =gSinLut
	movs r0, #0x80
	adds r0, r0, r4
	mov sb, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	movs r1, #2
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r2, #0
	ldrsh r0, [r4, r2]
	rsbs r0, r0, #0
	lsls r0, r0, #4
	movs r1, #0x80
	lsls r1, r1, #1
	mov r8, r1
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	movs r2, #0
	ldrsh r0, [r4, r2]
	lsls r0, r0, #4
	movs r1, #2
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0x1f
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808E260: .4byte gSinLut

	thumb_func_start func_fe6_0808E264
func_fe6_0808E264: @ 0x0808E264
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0808E280 @ =gUnk_0868B3FC
	ldr r0, [r0]
	adds r0, #0x9f
	ldrb r0, [r0]
	cmp r0, #4
	bhi .L0808E27C
	adds r0, r1, #0
	movs r1, #2
	bl Proc_Goto
.L0808E27C:
	pop {r0}
	bx r0
	.align 2, 0
.L0808E280: .4byte gUnk_0868B3FC

	thumb_func_start func_fe6_0808E284
func_fe6_0808E284: @ 0x0808E284
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, .L0808E2C8 @ =gUnk_0868B610
	bl SpawnProcLocking
	ldr r2, .L0808E2CC @ =gUnk_0868B3FC
	ldr r1, [r2]
	adds r1, #0x9f
	ldrb r1, [r1]
	adds r3, r0, #0
	adds r3, #0x9f
	strb r1, [r3]
	ldr r3, [r2]
	movs r1, #0x9f
	adds r1, r1, r3
	mov ip, r1
	ldrb r4, [r1]
	lsls r2, r4, #1
	adds r1, r3, #0
	adds r1, #0x42
	adds r1, r1, r2
	ldrh r1, [r1]
	strh r1, [r0, #0x32]
	mov r1, ip
	ldrb r1, [r1]
	lsls r2, r1, #1
	adds r1, r3, #0
	adds r1, #0x50
	adds r1, r1, r2
	ldrh r1, [r1]
	strh r1, [r0, #0x34]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808E2C8: .4byte gUnk_0868B610
.L0808E2CC: .4byte gUnk_0868B3FC

	thumb_func_start func_fe6_0808E2D0
func_fe6_0808E2D0: @ 0x0808E2D0
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0808E2EC @ =gUnk_0868B3FC
	ldr r0, [r0]
	adds r0, #0x9f
	ldrb r0, [r0]
	cmp r0, #5
	bls .L0808E2E8
	adds r0, r1, #0
	movs r1, #3
	bl Proc_Goto
.L0808E2E8:
	pop {r0}
	bx r0
	.align 2, 0
.L0808E2EC: .4byte gUnk_0868B3FC

	thumb_func_start func_fe6_0808E2F0
func_fe6_0808E2F0: @ 0x0808E2F0
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0808E2F4
func_fe6_0808E2F4: @ 0x0808E2F4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #4
	movs r0, #0x80
	lsls r0, r0, #1
	mov r8, r0
	str r0, [sp]
	movs r0, #0xa
	mov r1, r8
	movs r2, #0
	movs r3, #0
	bl SetObjAffine
	ldr r4, .L0808E388 @ =gSinLut
	movs r1, #0x80
	adds r1, r1, r4
	mov sb, r1
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	movs r1, #2
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r1, #0
	ldrsh r0, [r4, r1]
	rsbs r0, r0, #0
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	movs r2, #0
	ldrsh r0, [r4, r2]
	lsls r0, r0, #4
	movs r1, #2
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0x1f
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	ldr r0, .L0808E38C @ =gUnk_0868B648
	movs r1, #3
	bl SpawnProc
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808E388: .4byte gSinLut
.L0808E38C: .4byte gUnk_0868B648

	thumb_func_start func_fe6_0808E390
func_fe6_0808E390: @ 0x0808E390
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r6, #0
	ldr r1, .L0808E41C @ =gUnk_0868B3FC
	ldr r0, [r1]
	adds r0, #0x9f
	ldrb r0, [r0]
	adds r0, #1
	cmp r6, r0
	bge .L0808E414
	adds r7, r1, #0
.L0808E3A6:
	ldr r3, [r7]
	lsls r1, r6, #1
	adds r0, r3, #0
	adds r0, #0x42
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, #6
	lsls r5, r0, #3
	adds r0, r3, #0
	adds r0, #0x50
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r4, r0, #3
	adds r0, r3, #0
	adds r0, #0x9f
	ldrb r0, [r0]
	cmp r6, r0
	bne .L0808E3DA
	movs r0, #0xf8
	lsls r0, r0, #6
	orrs r5, r0
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r4, r0
.L0808E3DA:
	adds r0, r3, #0
	adds r0, #0x5e
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r2, r0, #1
	adds r2, #0xc0
	lsls r1, r6, #2
	adds r0, r3, #0
	adds r0, #0x7c
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r6, #4
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	orrs r0, r2
	str r0, [sp]
	movs r0, #4
	adds r1, r5, #0
	adds r2, r4, #0
	bl PutSpriteExt
	adds r6, #1
	ldr r0, [r7]
	adds r0, #0x9f
	ldrb r0, [r0]
	adds r0, #1
	cmp r6, r0
	blt .L0808E3A6
.L0808E414:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808E41C: .4byte gUnk_0868B3FC

	thumb_func_start func_fe6_0808E420
func_fe6_0808E420: @ 0x0808E420
	movs r1, #0
	strh r1, [r0, #0x2a]
	ldr r1, .L0808E430 @ =0x02016A28
	ldrh r1, [r1]
	subs r1, #1
	strh r1, [r0, #0x2c]
	bx lr
	.align 2, 0
.L0808E430: .4byte 0x02016A28

	thumb_func_start func_fe6_0808E434
func_fe6_0808E434: @ 0x0808E434
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldrh r0, [r7, #0x2a]
	adds r1, r0, #1
	strh r1, [r7, #0x2a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble .L0808E456
	adds r0, r7, #0
	bl Proc_Break
.L0808E456:
	movs r0, #0x80
	lsls r0, r0, #1
	mov r8, r0
	movs r1, #0x2a
	ldrsh r3, [r7, r1]
	movs r0, #8
	str r0, [sp]
	movs r0, #5
	movs r1, #2
	mov r2, r8
	bl Interpolate
	mov sl, r0
	ldr r4, .L0808E4E4 @ =gSinLut
	movs r2, #0x80
	adds r2, r2, r4
	mov sb, r2
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r2, #0
	ldrsh r0, [r4, r2]
	rsbs r0, r0, #0
	lsls r0, r0, #4
	mov r1, sl
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r2, sb
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #4
	mov r1, sl
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x2c
	ldrsh r1, [r7, r2]
	str r0, [sp]
	adds r0, r1, #0
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808E4E4: .4byte gSinLut

	thumb_func_start func_fe6_0808E4E8
func_fe6_0808E4E8: @ 0x0808E4E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, .L0808E5DC @ =0x02016A28
	movs r0, #0
	strh r0, [r1]
	movs r0, #0
	strh r0, [r7, #0x2c]
	strh r0, [r7, #0x2e]
	ldr r1, .L0808E5E0 @ =gUnk_0868B5B0
	ldr r0, .L0808E5E4 @ =0x02016A2A
	ldrh r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L0808E53C
.L0808E524:
	ldrh r0, [r7, #0x2e]
	adds r0, #1
	strh r0, [r7, #0x2e]
	movs r3, #0x2e
	ldrsh r0, [r7, r3]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	bne .L0808E524
.L0808E53C:
	movs r0, #0
	mov r8, r0
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	cmp r8, r0
	bge .L0808E5CC
	movs r2, #0x80
	lsls r2, r2, #1
	mov sb, r2
	ldr r3, .L0808E5E8 @ =gSinLut
	mov sl, r3
.L0808E552:
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	mov r1, sb
	movs r2, #0
	movs r3, #0
	bl SetObjAffine
	ldr r1, .L0808E5EC @ =gSinLut+0x80
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	mov r1, sb
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	mov r3, sl
	movs r1, #0
	ldrsh r0, [r3, r1]
	rsbs r0, r0, #0
	lsls r0, r0, #4
	movs r1, #2
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	mov r2, sl
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #4
	mov r1, sb
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r1, .L0808E5EC @ =gSinLut+0x80
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	movs r1, #2
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, r8
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	movs r3, #1
	add r8, r3
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	cmp r8, r0
	blt .L0808E552
.L0808E5CC:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808E5DC: .4byte 0x02016A28
.L0808E5E0: .4byte gUnk_0868B5B0
.L0808E5E4: .4byte 0x02016A2A
.L0808E5E8: .4byte gSinLut
.L0808E5EC: .4byte gSinLut+0x80

	thumb_func_start func_fe6_0808E5F0
func_fe6_0808E5F0: @ 0x0808E5F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	movs r7, #0
	ldr r1, .L0808E6B8 @ =0x02016A1E
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r1]
	subs r1, r0, r1
	ldr r0, .L0808E6BC @ =0x02016A2A
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0808E61E
	adds r1, #0x80
	ldr r0, .L0808E6C0 @ =0x000001FF
	ands r1, r0
	ldr r2, .L0808E6C4 @ =gUnk_0868B720
	ldr r3, .L0808E6C8 @ =0x00002084
	movs r0, #0xa2
	bl PutOamHiRam
.L0808E61E:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	bgt .L0808E646
	strh r7, [r4, #0x2c]
	ldr r2, .L0808E6CC @ =0x02016A28
	ldrh r1, [r2]
	movs r3, #0x2e
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bge .L0808E646
	adds r0, r1, #1
	strh r0, [r2]
	ldr r0, .L0808E6D0 @ =gUnk_0868B700
	movs r1, #3
	bl SpawnProc
.L0808E646:
	ldr r2, .L0808E6D4 @ =gUnk_0868B5B0
	ldr r0, .L0808E6BC @ =0x02016A2A
	ldrh r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r1, [r0]
	movs r6, #0
	ldr r0, .L0808E6CC @ =0x02016A28
	ldrh r0, [r0]
	cmp r6, r0
	bge .L0808E6AA
	mov r8, r2
	adds r4, r1, #0
.L0808E660:
	ldr r0, .L0808E6BC @ =0x02016A2A
	ldrh r0, [r0]
	lsls r1, r0, #3
	add r1, r8
	ldrb r0, [r1, #4]
	adds r2, r0, r7
	lsls r0, r6, #9
	adds r3, r2, r0
	ldrb r1, [r1, #5]
	movs r0, #0x84
	lsls r0, r0, #1
	adds r2, r1, r0
	ldrb r0, [r4, #2]
	ldr r5, .L0808E6D8 @ =gUnk_0868B410
	cmp r0, #0
	beq .L0808E682
	ldr r5, .L0808E6DC @ =gUnk_0868B418
.L0808E682:
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #1
	movs r1, #0xc6
	lsls r1, r1, #6
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #4
	adds r1, r3, #0
	adds r3, r5, #0
	bl PutSpriteExt
	ldrb r3, [r4, #1]
	adds r7, r3, r7
	adds r4, #4
	adds r6, #1
	ldr r0, .L0808E6CC @ =0x02016A28
	ldrh r0, [r0]
	cmp r6, r0
	blt .L0808E660
.L0808E6AA:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808E6B8: .4byte 0x02016A1E
.L0808E6BC: .4byte 0x02016A2A
.L0808E6C0: .4byte 0x000001FF
.L0808E6C4: .4byte gUnk_0868B720
.L0808E6C8: .4byte 0x00002084
.L0808E6CC: .4byte 0x02016A28
.L0808E6D0: .4byte gUnk_0868B700
.L0808E6D4: .4byte gUnk_0868B5B0
.L0808E6D8: .4byte gUnk_0868B410
.L0808E6DC: .4byte gUnk_0868B418

	thumb_func_start func_fe6_0808E6E0
func_fe6_0808E6E0: @ 0x0808E6E0
	push {lr}
	ldr r2, .L0808E6F4 @ =gUnk_0868B720
	ldr r3, .L0808E6F8 @ =0x00002084
	movs r0, #0x58
	movs r1, #0x3e
	bl PutOamHiRam
	pop {r0}
	bx r0
	.align 2, 0
.L0808E6F4: .4byte gUnk_0868B720
.L0808E6F8: .4byte 0x00002084

	thumb_func_start func_fe6_0808E6FC
func_fe6_0808E6FC: @ 0x0808E6FC
	push {lr}
	ldr r0, .L0808E70C @ =gUnk_0868B750
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0808E70C: .4byte gUnk_0868B750

	thumb_func_start func_fe6_0808E710
func_fe6_0808E710: @ 0x0808E710
	ldr r2, .L0808E72C @ =gUnk_0868B3FC
	ldr r0, [r2]
	movs r1, #0
	str r1, [r0, #0x38]
	str r1, [r0, #0x3c]
	adds r0, #0x40
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x41
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x9f
	strb r1, [r0]
	bx lr
	.align 2, 0
.L0808E72C: .4byte gUnk_0868B3FC

	thumb_func_start func_fe6_0808E730
func_fe6_0808E730: @ 0x0808E730
	push {r4, lr}
	ldr r3, .L0808E798 @ =gUnk_0868B3FC
	ldr r0, [r3]
	adds r0, #0x40
	ldrb r1, [r0]
	adds r1, #3
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, #0x41
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r0, [r3]
	mov ip, r0
	mov r2, ip
	adds r2, #0x40
	ldrb r4, [r2]
	lsrs r1, r4, #2
	mov r4, ip
	ldr r0, [r4, #0x38]
	adds r0, r0, r1
	str r0, [r4, #0x38]
	mov r0, ip
	adds r0, #0x41
	ldrb r0, [r0]
	lsrs r1, r0, #2
	ldr r0, [r4, #0x3c]
	adds r0, r0, r1
	str r0, [r4, #0x3c]
	movs r1, #3
	adds r0, r1, #0
	ldrb r4, [r2]
	ands r0, r4
	strb r0, [r2]
	ldr r0, [r3]
	adds r0, #0x41
	ldrb r2, [r0]
	ands r1, r2
	strb r1, [r0]
	ldr r2, [r3]
	ldr r1, [r2, #0x38]
	movs r0, #0xff
	ands r1, r0
	ldr r2, [r2, #0x3c]
	ands r2, r0
	movs r0, #2
	bl SetBgOffset
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808E798: .4byte gUnk_0868B3FC

	thumb_func_start func_fe6_0808E79C
func_fe6_0808E79C: @ 0x0808E79C
	push {r4, r5, r6, lr}
	ldr r6, .L0808E7C8 @ =gUnk_0868B3FC
	movs r5, #0xa0
	movs r4, #7
.L0808E7A4:
	ldr r0, [r6]
	adds r0, r0, r5
	movs r1, #0xf
	bl InitText
	adds r5, #8
	subs r4, #1
	cmp r4, #0
	bge .L0808E7A4
	ldr r0, .L0808E7C8 @ =gUnk_0868B3FC
	ldr r0, [r0]
	adds r0, #0xe0
	movs r1, #3
	bl InitText
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808E7C8: .4byte gUnk_0868B3FC

	thumb_func_start func_fe6_0808E7CC
func_fe6_0808E7CC: @ 0x0808E7CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	mov r8, r1
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	str r4, [sp, #0x10]
	movs r6, #0
	cmp r1, #0x32
	bne .L0808E818
	ldr r7, .L0808E814 @ =0x00000BA1
	adds r0, r7, #0
	bl DecodeMsg
	bl GetStringTextLen
	adds r5, r0, #0
	cmp r4, #0
	beq .L0808E800
	movs r0, #0x30
	subs r0, r0, r5
	asrs r6, r0, #1
.L0808E800:
	adds r0, r7, #0
	bl DecodeMsg
	adds r3, r0, #0
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl Text_InsertDrawString
	b .L0808E91E
	.align 2, 0
.L0808E814: .4byte 0x00000BA1
.L0808E818:
	ldr r0, .L0808E930 @ =0x00000B9E
	bl DecodeMsg
	bl GetStringTextLen
	str r0, [sp]
	adds r5, r0, #0
	mov r0, r8
	asrs r4, r0, #1
	adds r0, r4, #0
	movs r1, #0xa
	bl __divsi3
	adds r7, r0, #0
	adds r0, r4, #0
	movs r1, #0xa
	bl __modsi3
	adds r4, r0, #0
	cmp r7, #0
	beq .L0808E858
	ldr r1, .L0808E934 @ =gUnk_0868B788
	lsls r0, r7, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl DecodeMsg
	bl GetStringTextLen
	subs r0, #1
	str r0, [sp, #4]
	adds r5, r5, r0
.L0808E858:
	lsls r0, r4, #1
	ldr r1, .L0808E934 @ =gUnk_0868B788
	adds r0, r0, r1
	mov sl, r0
	ldrh r0, [r0]
	bl DecodeMsg
	bl GetStringTextLen
	subs r0, #1
	str r0, [sp, #8]
	adds r5, r5, r0
	ldr r0, .L0808E938 @ =0x00000B9F
	bl DecodeMsg
	bl GetStringTextLen
	str r0, [sp, #0xc]
	adds r5, r5, r0
	movs r4, #1
	mov r0, r8
	ands r4, r0
	cmp r4, #0
	beq .L0808E896
	movs r0, #0xba
	lsls r0, r0, #4
	bl DecodeMsg
	bl GetStringTextLen
	adds r5, r5, r0
.L0808E896:
	ldr r1, [sp, #0x10]
	cmp r1, #0
	beq .L0808E8A2
	movs r0, #0x30
	subs r0, r0, r5
	asrs r6, r0, #1
.L0808E8A2:
	ldr r0, .L0808E930 @ =0x00000B9E
	bl DecodeMsg
	adds r3, r0, #0
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl Text_InsertDrawString
	ldr r0, [sp]
	adds r6, r6, r0
	cmp r7, #0
	beq .L0808E8D8
	lsls r0, r7, #1
	ldr r1, .L0808E934 @ =gUnk_0868B788
	adds r0, r0, r1
	ldrh r0, [r0]
	bl DecodeMsg
	adds r3, r0, #0
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl Text_InsertDrawString
	ldr r0, [sp, #4]
	adds r6, r6, r0
.L0808E8D8:
	mov r1, sl
	ldrh r0, [r1]
	bl DecodeMsg
	adds r3, r0, #0
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl Text_InsertDrawString
	ldr r0, [sp, #8]
	adds r6, r6, r0
	ldr r0, .L0808E938 @ =0x00000B9F
	bl DecodeMsg
	adds r3, r0, #0
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl Text_InsertDrawString
	ldr r0, [sp, #0xc]
	adds r6, r6, r0
	cmp r4, #0
	beq .L0808E91E
	movs r0, #0xba
	lsls r0, r0, #4
	bl DecodeMsg
	adds r3, r0, #0
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl Text_InsertDrawString
.L0808E91E:
	adds r0, r5, #0
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L0808E930: .4byte 0x00000B9E
.L0808E934: .4byte gUnk_0868B788
.L0808E938: .4byte 0x00000B9F

	thumb_func_start func_fe6_0808E93C
func_fe6_0808E93C: @ 0x0808E93C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	ldr r7, .L0808E95C @ =0x02016A24
	ldrh r4, [r7]
	bl GetNextChapterStatsSlot
	cmp r4, r0
	blt .L0808E960
	movs r0, #1
	b .L0808EA58
	.align 2, 0
.L0808E95C: .4byte 0x02016A24
.L0808E960:
	ldrh r0, [r7]
	bl GetChapterStats
	mov sb, r0
	movs r6, #7
	ldrh r0, [r7]
	ands r6, r0
	ldr r1, .L0808EA68 @ =gUnk_0868B3FC
	mov r8, r1
	lsls r6, r6, #3
	adds r6, #0xa0
	ldr r0, [r1]
	adds r0, r0, r6
	bl ClearText
	mov r2, r8
	ldr r0, [r2]
	adds r0, #0xe0
	bl ClearText
	mov r3, sb
	ldr r0, [r3]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1a
	bl GetChapterInfo
	adds r0, #0x3e
	ldrb r1, [r0]
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r6
	movs r2, #1
	bl func_fe6_0808E7CC
	mov r3, sb
	ldr r0, [r3]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1a
	bl GetChapterInfo
	ldrh r0, [r0, #0x38]
	bl DecodeMsg
	bl GetStringTextLen
	movs r4, #0x46
	subs r4, r4, r0
	lsrs r0, r4, #0x1f
	adds r4, r4, r0
	asrs r4, r4, #1
	mov r0, r8
	ldr r5, [r0]
	adds r5, r5, r6
	adds r4, #0x28
	mov r1, sb
	ldr r0, [r1]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1a
	bl GetChapterInfo
	ldrh r0, [r0, #0x38]
	bl DecodeMsg
	adds r3, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Text_InsertDrawString
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r6
	mov r3, sl
	lsls r5, r3, #6
	ldr r4, .L0808EA6C @ =gBg0Tm+0x2
	adds r1, r5, r4
	bl PutText
	adds r0, r4, #0
	adds r0, #0x1e
	adds r0, r5, r0
	mov r1, sb
	ldr r2, [r1]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x16
	movs r1, #2
	bl PutNumber
	ldr r0, .L0808EA70 @ =0x00000725
	bl DecodeMsg
	adds r3, r0, #0
	mov r2, r8
	ldr r0, [r2]
	adds r0, #0xe0
	adds r1, r4, #0
	adds r1, #0x20
	adds r1, r5, r1
	movs r2, #3
	str r2, [sp]
	str r3, [sp, #4]
	movs r2, #0
	movs r3, #0
	bl PutDrawText
	adds r4, #0x26
	adds r5, r5, r4
	movs r0, #0xb4
	mov r3, sb
	ldrh r3, [r3, #2]
	adds r2, r3, #0
	muls r2, r0, r2
	adds r0, r5, #0
	movs r1, #2
	movs r3, #1
	bl PutTime
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	movs r0, #1
	bl EnableBgSync
	movs r0, #0
.L0808EA58:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L0808EA68: .4byte gUnk_0868B3FC
.L0808EA6C: .4byte gBg0Tm+0x2
.L0808EA70: .4byte 0x00000725

	thumb_func_start func_fe6_0808EA74
func_fe6_0808EA74: @ 0x0808EA74
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	bl func_fe6_0808F33C
	ldr r6, .L0808EB84 @ =0x02016A2E
	ldr r4, .L0808EB88 @ =gUnk_0868B3FC
	ldr r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, #0x6c
	strh r0, [r1]
	strh r0, [r6]
	bl func_fe6_0808F490
	ldr r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, #0x6e
	strh r0, [r1]
	strh r0, [r6, #2]
	bl func_fe6_0808F524
	ldr r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, #0x70
	strh r0, [r1]
	strh r0, [r6, #4]
	bl func_fe6_0808F5AC
	ldr r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, #0x72
	strh r0, [r1]
	strh r0, [r6, #6]
	bl func_fe6_0808F600
	ldr r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, #0x74
	strh r0, [r1]
	strh r0, [r6, #8]
	bl func_fe6_0808F68C
	ldr r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, #0x76
	strh r0, [r1]
	strh r0, [r6, #0xa]
	movs r6, #0
.L0808EAE6:
	adds r0, r6, #0
	movs r1, #0
	bl func_fe6_0808DF78
	adds r6, #1
	cmp r6, #5
	ble .L0808EAE6
	bl func_fe6_0808F6E0
	ldr r4, .L0808EB88 @ =gUnk_0868B3FC
	ldr r1, [r4]
	adds r1, #0x78
	strh r0, [r1]
	movs r0, #6
	movs r1, #0
	bl func_fe6_0808DF78
	movs r6, #0
	subs r7, #6
	mov sb, r7
	mov r8, r4
	ldr r5, .L0808EB8C @ =gUnk_0868B420
	movs r7, #0xe8
.L0808EB14:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r7
	movs r1, #6
	bl InitText
	mov r2, r8
	ldr r0, [r2]
	adds r0, r0, r7
	bl ClearText
	ldrh r0, [r5]
	bl DecodeMsg
	str r0, [sp, #8]
	mov r4, r8
	ldr r3, [r4]
	adds r0, r3, r7
	lsls r4, r6, #1
	adds r1, r3, #0
	adds r1, #0x50
	adds r1, r1, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	add r1, sb
	movs r2, #0x1f
	ands r1, r2
	lsls r1, r1, #5
	adds r3, #0x42
	adds r3, r3, r4
	movs r4, #0
	ldrsh r2, [r3, r4]
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, .L0808EB90 @ =gBg0Tm
	adds r1, r1, r2
	ldr r2, [r5, #4]
	movs r3, #6
	str r3, [sp]
	ldr r3, [sp, #8]
	str r3, [sp, #4]
	movs r3, #0
	bl PutDrawText
	adds r5, #0x10
	adds r7, #8
	adds r6, #1
	cmp r6, #6
	ble .L0808EB14
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808EB84: .4byte 0x02016A2E
.L0808EB88: .4byte gUnk_0868B3FC
.L0808EB8C: .4byte gUnk_0868B420
.L0808EB90: .4byte gBg0Tm

	thumb_func_start func_fe6_0808EB94
func_fe6_0808EB94: @ 0x0808EB94
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	adds r6, r0, #0
	movs r0, #6
	mov sb, r0
	adds r6, #0x16
	ldr r4, .L0808EC10 @ =gUnk_0868B3FC
	movs r5, #0x8c
	lsls r5, r5, #1
	ldr r0, [r4]
	adds r0, r0, r5
	movs r1, #6
	bl InitText
	ldr r0, [r4]
	adds r0, r0, r5
	bl ClearText
	ldr r2, .L0808EC14 @ =gUnk_0868B420
	mov r8, r2
	mov r0, r8
	adds r0, #0x60
	ldrh r0, [r0]
	bl DecodeMsg
	ldr r3, [r4]
	adds r5, r3, r5
	adds r1, r3, #0
	adds r1, #0x5c
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r1, r1, r6
	movs r2, #0x1f
	ands r1, r2
	lsls r1, r1, #5
	adds r3, #0x4e
	movs r4, #0
	ldrsh r2, [r3, r4]
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, .L0808EC18 @ =gBg0Tm
	adds r1, r1, r2
	mov r3, r8
	ldr r2, [r3, #0x64]
	mov r4, sb
	str r4, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl PutDrawText
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808EC10: .4byte gUnk_0868B3FC
.L0808EC14: .4byte gUnk_0868B420
.L0808EC18: .4byte gBg0Tm

	thumb_func_start func_fe6_0808EC1C
func_fe6_0808EC1C: @ 0x0808EC1C
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	bl GetNextChapterStatsSlot
	adds r5, r0, #0
	movs r4, #0
	cmp r6, r5
	bge .L0808EC40
	movs r7, #0xb4
.L0808EC2E:
	adds r0, r4, #0
	bl GetChapterStats
	ldrh r0, [r0, #2]
	muls r0, r7, r0
	adds r6, r6, r0
	adds r4, #1
	cmp r4, r5
	blt .L0808EC2E
.L0808EC40:
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0808EC48
func_fe6_0808EC48: @ 0x0808EC48
	push {r4, lr}
	adds r4, r0, #0
	bl func_fe6_0808EC1C
	adds r2, r0, #0
	adds r4, #3
	movs r0, #0x1f
	ands r4, r0
	lsls r4, r4, #6
	ldr r0, .L0808EC74 @ =gBg0Tm+0x28
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #2
	movs r3, #1
	bl PutTime
	movs r0, #1
	bl EnableBgSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808EC74: .4byte gBg0Tm+0x28

	thumb_func_start func_fe6_0808EC78
func_fe6_0808EC78: @ 0x0808EC78
	push {r4, r5, r6, lr}
	subs r0, #0x50
	lsls r0, r0, #2
	movs r2, #0xf0
	lsls r2, r2, #2
	ands r0, r2
	adds r1, r0, #0
	adds r1, #0x40
	ands r1, r2
	ldr r2, .L0808ECCC @ =gBg0Tm
	movs r5, #0
	adds r3, r1, #0
	adds r3, #0x20
	lsls r1, r1, #1
	adds r4, r1, r2
	adds r1, r0, #0
	adds r1, #0x20
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0x1f
	lsls r1, r1, #1
	adds r1, r1, r2
	lsls r3, r3, #1
	adds r3, r3, r2
.L0808ECA8:
	strh r5, [r0]
	strh r5, [r1]
	strh r5, [r4]
	strh r5, [r3]
	adds r3, #2
	adds r4, #2
	adds r1, #2
	adds r0, #2
	subs r6, #1
	cmp r6, #0
	bge .L0808ECA8
	movs r0, #1
	bl EnableBgSync
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808ECCC: .4byte gBg0Tm

	thumb_func_start func_fe6_0808ECD0
func_fe6_0808ECD0: @ 0x0808ECD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp]
	lsls r2, r2, #0x10
	movs r3, #0
	lsrs r2, r2, #4
	mov ip, r2
.L0808ECE6:
	movs r2, #0
	lsls r0, r3, #8
	str r0, [sp, #0x10]
	adds r3, #1
	str r3, [sp, #8]
.L0808ECF0:
	lsls r0, r2, #3
	ldr r3, [sp, #0x10]
	adds r0, r3, r0
	movs r6, #0
	str r6, [sp, #4]
	adds r2, #1
	str r2, [sp, #0xc]
	lsls r2, r0, #1
	adds r0, r2, #0
	adds r0, #0xc0
	ldr r7, [sp]
	adds r0, r0, r7
	str r0, [sp, #0x14]
	adds r0, r2, #0
	adds r0, #0x80
	adds r0, r0, r7
	str r0, [sp, #0x18]
	adds r0, r2, #0
	adds r0, #0x40
	adds r0, r0, r7
	str r0, [sp, #0x1c]
	adds r2, r2, r7
	mov r0, ip
	adds r0, #0xe0
	adds r0, r0, r1
	mov sl, r0
	mov r0, ip
	adds r0, #0xc0
	adds r0, r0, r1
	mov sb, r0
	mov r0, ip
	adds r0, #0xa0
	adds r0, r0, r1
	mov r8, r0
	mov r0, ip
	adds r0, #0x80
	adds r0, r1, r0
	str r0, [sp, #0x20]
	mov r0, ip
	adds r0, #0x60
	adds r0, r1, r0
	str r0, [sp, #0x24]
	mov r0, ip
	adds r0, #0x40
	adds r5, r1, r0
	subs r0, #0x20
	adds r4, r1, r0
	mov r0, ip
	adds r3, r1, r0
.L0808ED52:
	strh r3, [r2]
	ldr r6, [sp, #0x1c]
	strh r4, [r6]
	ldr r7, [sp, #0x18]
	strh r5, [r7]
	mov r0, sp
	ldrh r6, [r0, #0x24]
	ldr r0, [sp, #0x14]
	strh r6, [r0]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r2, r7
	mov r6, sp
	ldrh r6, [r6, #0x20]
	strh r6, [r0]
	adds r7, #0x40
	adds r0, r2, r7
	mov r6, r8
	strh r6, [r0]
	adds r7, #0x40
	adds r0, r2, r7
	mov r6, sb
	strh r6, [r0]
	adds r7, #0x40
	adds r0, r2, r7
	mov r6, sl
	strh r6, [r0]
	ldr r7, [sp, #0x14]
	adds r7, #2
	str r7, [sp, #0x14]
	ldr r0, [sp, #0x18]
	adds r0, #2
	str r0, [sp, #0x18]
	ldr r6, [sp, #0x1c]
	adds r6, #2
	str r6, [sp, #0x1c]
	adds r2, #2
	movs r7, #1
	add sl, r7
	movs r0, #1
	add sb, r0
	add r8, r0
	ldr r6, [sp, #0x20]
	adds r6, #1
	str r6, [sp, #0x20]
	ldr r7, [sp, #0x24]
	adds r7, #1
	str r7, [sp, #0x24]
	adds r5, #1
	adds r4, #1
	adds r3, #1
	ldr r0, [sp, #4]
	adds r0, #1
	str r0, [sp, #4]
	cmp r0, #7
	ble .L0808ED52
	ldr r2, [sp, #0xc]
	cmp r2, #3
	ble .L0808ECF0
	ldr r3, [sp, #8]
	cmp r3, #3
	ble .L0808ECE6
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0808EDE0
func_fe6_0808EDE0: @ 0x0808EDE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl ResetText
	bl UnpackUiWindowFrameGraphics
	bl ResetTextFont
	bl func_fe6_0808E79C
	ldr r7, .L0808EFE8 @ =gDispIo
	movs r4, #1
	ldrb r0, [r7, #1]
	orrs r0, r4
	movs r1, #2
	mov sb, r1
	mov r2, sb
	orrs r0, r2
	movs r5, #4
	mov sl, r5
	mov r1, sl
	orrs r0, r1
	movs r2, #8
	orrs r0, r2
	movs r5, #0x10
	mov r8, r5
	mov r1, r8
	orrs r0, r1
	strb r0, [r7, #1]
	ldr r0, .L0808EFEC @ =0x02016A24
	movs r6, #0
	strh r6, [r0]
	ldr r0, .L0808EFF0 @ =0x02016A26
	strh r6, [r0]
	ldr r0, .L0808EFF4 @ =0x02016A2C
	strb r6, [r0]
	ldr r1, .L0808EFF8 @ =0x02016A1C
	movs r0, #0x80
	strh r0, [r1]
	ldr r5, .L0808EFFC @ =0x02016A1E
	movs r0, #0xe0
	strh r0, [r5]
	ldr r1, .L0808F000 @ =0x02016A20
	movs r0, #0xff
	strh r0, [r1]
	movs r0, #0
	movs r1, #0
	movs r2, #0x80
	bl SetBgOffset
	ldrh r2, [r5]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r2, #0x20
	ldrb r0, [r7, #1]
	orrs r0, r2
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r7, #1]
	adds r0, r7, #0
	adds r0, #0x2d
	strb r6, [r0]
	adds r1, r7, #0
	adds r1, #0x31
	movs r0, #0x18
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x88
	strb r0, [r1]
	adds r1, #4
	ldrb r5, [r1]
	orrs r4, r5
	mov r0, sb
	orrs r4, r0
	mov r5, sl
	orrs r4, r5
	movs r0, #8
	orrs r4, r0
	mov r5, r8
	orrs r4, r5
	adds r3, r7, #0
	adds r3, #0x36
	subs r0, #0xa
	ldrb r5, [r3]
	ands r0, r5
	mov r5, sb
	orrs r0, r5
	mov r5, sl
	orrs r0, r5
	movs r5, #8
	orrs r0, r5
	mov r5, r8
	orrs r0, r5
	orrs r4, r2
	strb r4, [r1]
	orrs r0, r2
	strb r0, [r3]
	ldr r0, .L0808F004 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r5, .L0808F008 @ =gBg1Tm
	adds r0, r5, #0
	movs r1, #0
	bl TmFill
	ldr r0, .L0808F00C @ =gBg2Tm
	mov r8, r0
	movs r1, #0
	bl TmFill
	ldr r1, .L0808F010 @ =gBg3Tm
	mov sl, r1
	mov r0, sl
	movs r1, #0
	bl TmFill
	adds r2, r7, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #6
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, .L0808F014 @ =0x0000FFE0
	ldrh r2, [r7, #0x3c]
	ands r0, r2
	movs r1, #4
	orrs r0, r1
	ldr r1, .L0808F018 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r7, #0x3c]
	bl func_fe6_0808DD40
	ldr r0, .L0808F01C @ =gUnk_0834138C
	movs r1, #0x80
	movs r2, #0x40
	bl ApplyPaletteExt
	ldr r0, .L0808F020 @ =gUnk_08341DA0
	movs r1, #0xc0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L0808F024 @ =gUnk_0833C03C
	movs r1, #0x90
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r4, .L0808F028 @ =gUnk_08342A98
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r4, #0
	movs r2, #0x20
	bl ApplyPaletteExt
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r0, r4, #0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L0808F02C @ =Img_Unk_083092CC
	ldr r1, .L0808F030 @ =0x06011000
	bl Decompress
	ldr r0, .L0808F034 @ =gUnk_08342438
	ldr r1, .L0808F038 @ =0x06011800
	bl Decompress
	ldr r0, .L0808F03C @ =gUnk_08341DC0
	ldr r1, .L0808F040 @ =0x06013000
	bl Decompress
	ldr r0, .L0808F044 @ =gUnk_083413CC
	ldr r1, .L0808F048 @ =0x0600D000
	bl Decompress
	ldr r4, .L0808F04C @ =gUnk_0833C984
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	adds r0, r4, #0
	bl Decompress
	ldr r1, .L0808F050 @ =0x00000426
	adds r5, r5, r1
	ldr r1, .L0808F054 @ =gUnk_08342AF8
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r5, #0
	bl TmApplyTsa_thm
	movs r1, #0xa0
	lsls r1, r1, #2
	mov r0, r8
	movs r2, #6
	bl func_fe6_0808ECD0
	ldr r1, .L0808F058 @ =gUnk_08340ED8
	movs r2, #0x80
	lsls r2, r2, #7
	mov r0, sl
	bl TmApplyTsa_thm
	ldr r0, .L0808F05C @ =gUnk_0868B768
	movs r1, #3
	bl SpawnProc
	movs r0, #0xf
	bl EnableBgSync
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808EFE8: .4byte gDispIo
.L0808EFEC: .4byte 0x02016A24
.L0808EFF0: .4byte 0x02016A26
.L0808EFF4: .4byte 0x02016A2C
.L0808EFF8: .4byte 0x02016A1C
.L0808EFFC: .4byte 0x02016A1E
.L0808F000: .4byte 0x02016A20
.L0808F004: .4byte gBg0Tm
.L0808F008: .4byte gBg1Tm
.L0808F00C: .4byte gBg2Tm
.L0808F010: .4byte gBg3Tm
.L0808F014: .4byte 0x0000FFE0
.L0808F018: .4byte 0x0000E0FF
.L0808F01C: .4byte gUnk_0834138C
.L0808F020: .4byte gUnk_08341DA0
.L0808F024: .4byte gUnk_0833C03C
.L0808F028: .4byte gUnk_08342A98
.L0808F02C: .4byte Img_Unk_083092CC
.L0808F030: .4byte 0x06011000
.L0808F034: .4byte gUnk_08342438
.L0808F038: .4byte 0x06011800
.L0808F03C: .4byte gUnk_08341DC0
.L0808F040: .4byte 0x06013000
.L0808F044: .4byte gUnk_083413CC
.L0808F048: .4byte 0x0600D000
.L0808F04C: .4byte gUnk_0833C984
.L0808F050: .4byte 0x00000426
.L0808F054: .4byte gUnk_08342AF8
.L0808F058: .4byte gUnk_08340ED8
.L0808F05C: .4byte gUnk_0868B768

	thumb_func_start func_fe6_0808F060
func_fe6_0808F060: @ 0x0808F060
	push {r4, lr}
	movs r4, #0
	movs r1, #4
	strh r1, [r0, #0x2e]
	strh r4, [r0, #0x30]
	ldr r2, .L0808F08C @ =0x02016A1C
	ldr r1, .L0808F090 @ =0x02016A22
	movs r0, #0x7a
	strh r0, [r1]
	strh r0, [r2]
	movs r0, #0
	bl func_fe6_0808E93C
	ldr r0, .L0808F094 @ =0x02016A24
	strh r4, [r0]
	movs r0, #1
	bl EnableBgSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808F08C: .4byte 0x02016A1C
.L0808F090: .4byte 0x02016A22
.L0808F094: .4byte 0x02016A24

	thumb_func_start func_fe6_0808F098
func_fe6_0808F098: @ 0x0808F098
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq .L0808F0B0
	ldr r0, .L0808F12C @ =0x02016A1C
	ldrh r0, [r0]
	bl func_fe6_0808EC78
	movs r0, #0
	strh r0, [r4, #0x30]
.L0808F0B0:
	ldr r7, .L0808F130 @ =0x02016A26
	ldrh r0, [r7]
	cmp r0, #8
	bhi .L0808F0CC
	ldrh r0, [r4, #0x2e]
	adds r1, r0, #1
	strh r1, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bgt .L0808F0C8
	b .L0808F220
.L0808F0C8:
	movs r0, #0
	strh r0, [r4, #0x2e]
.L0808F0CC:
	ldr r5, .L0808F12C @ =0x02016A1C
	ldrh r2, [r5]
	adds r2, #1
	strh r2, [r5]
	movs r6, #0xff
	ands r2, r6
	movs r0, #0
	movs r1, #0
	bl SetBgOffset
	ldrh r1, [r7]
	cmp r1, #0xc
	bls .L0808F0F8
	ldr r0, .L0808F134 @ =0x02016A1E
	ldrh r2, [r0]
	adds r2, #1
	strh r2, [r0]
	ands r2, r6
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
.L0808F0F8:
	ldr r2, .L0808F138 @ =0x02016A22
	ldrh r5, [r5]
	ldrh r1, [r2]
	subs r0, r5, r1
	movs r1, #0xf0
	ands r0, r1
	asrs r1, r0, #3
	ldr r0, .L0808F13C @ =0x02016A20
	adds r3, r0, #0
	ldrh r0, [r3]
	cmp r1, r0
	bne .L0808F112
	b .L0808F220
.L0808F112:
	strh r1, [r3]
	movs r0, #1
	strh r0, [r4, #0x30]
	ldrh r0, [r7]
	cmp r0, #0xe
	bls .L0808F120
	b .L0808F218
.L0808F120:
	lsls r0, r0, #2
	ldr r1, .L0808F140 @ =.L0808F144
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0808F12C: .4byte 0x02016A1C
.L0808F130: .4byte 0x02016A26
.L0808F134: .4byte 0x02016A1E
.L0808F138: .4byte 0x02016A22
.L0808F13C: .4byte 0x02016A20
.L0808F140: .4byte .L0808F144
.L0808F144: @ jump table
	.4byte .L0808F180 @ case 0
	.4byte .L0808F218 @ case 1
	.4byte .L0808F218 @ case 2
	.4byte .L0808F218 @ case 3
	.4byte .L0808F218 @ case 4
	.4byte .L0808F218 @ case 5
	.4byte .L0808F218 @ case 6
	.4byte .L0808F218 @ case 7
	.4byte .L0808F18E @ case 8
	.4byte .L0808F1A4 @ case 9
	.4byte .L0808F218 @ case 10
	.4byte .L0808F1BC @ case 11
	.4byte .L0808F218 @ case 12
	.4byte .L0808F1C4 @ case 13
	.4byte .L0808F1EC @ case 14
.L0808F180:
	ldrh r0, [r3]
	bl func_fe6_0808E93C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0808F220
	b .L0808F218
.L0808F18E:
	ldr r0, .L0808F1A0 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	movs r0, #1
	bl EnableBgSync
	b .L0808F218
	.align 2, 0
.L0808F1A0: .4byte gBg0Tm
.L0808F1A4:
	movs r1, #0x80
	strh r1, [r2]
	ldr r0, .L0808F1B8 @ =0x02016A1C
	strh r1, [r0]
	movs r0, #0
	strh r0, [r3]
	bl func_fe6_0808EA74
	b .L0808F218
	.align 2, 0
.L0808F1B8: .4byte 0x02016A1C
.L0808F1BC:
	ldrh r0, [r3]
	bl func_fe6_0808EB94
	b .L0808F218
.L0808F1C4:
	ldrh r0, [r3]
	bl func_fe6_0808EC48
	ldr r2, .L0808F1E8 @ =gDispIo
	adds r2, #0x36
	movs r0, #1
	ldrb r1, [r2]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	b .L0808F218
	.align 2, 0
.L0808F1E8: .4byte gDispIo
.L0808F1EC:
	ldr r1, .L0808F20C @ =0x02016A2A
	movs r0, #0
	strh r0, [r1]
	ldr r0, .L0808F210 @ =gUnk_0868B730
	movs r1, #3
	bl SpawnProc
	ldr r0, .L0808F214 @ =gUnk_0868B6D8
	movs r1, #3
	bl SpawnProc
	adds r0, r4, #0
	bl Proc_Break
	b .L0808F220
	.align 2, 0
.L0808F20C: .4byte 0x02016A2A
.L0808F210: .4byte gUnk_0868B730
.L0808F214: .4byte gUnk_0868B6D8
.L0808F218:
	ldr r1, .L0808F228 @ =0x02016A26
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L0808F220:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808F228: .4byte 0x02016A26

	thumb_func_start func_fe6_0808F22C
func_fe6_0808F22C: @ 0x0808F22C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0808F254 @ =gKeySt
	ldr r1, [r0]
	movs r0, #3
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0808F25C
	ldr r0, .L0808F258 @ =gUnk_0868B3FC
	ldr r0, [r0]
	adds r0, #0x9f
	ldrb r0, [r0]
	cmp r0, #6
	bne .L0808F25C
	adds r0, r4, #0
	bl Proc_Break
	b .L0808F270
	.align 2, 0
.L0808F254: .4byte gKeySt
.L0808F258: .4byte gUnk_0868B3FC
.L0808F25C:
	bl func_fe6_08036DEC
	cmp r0, #0
	beq .L0808F270
	ldr r1, .L0808F278 @ =0x02016A2C
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0808F270:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808F278: .4byte 0x02016A2C

	thumb_func_start func_fe6_0808F27C
func_fe6_0808F27C: @ 0x0808F27C
	push {lr}
	ldr r0, .L0808F298 @ =gUnk_0868B5E8
	bl Proc_EndEach
	ldr r0, .L0808F29C @ =gUnk_0868B88C
	bl Proc_EndEach
	ldr r0, .L0808F2A0 @ =gUnk_0868B610
	bl Proc_EndEach
	bl EndGreenText
	pop {r0}
	bx r0
	.align 2, 0
.L0808F298: .4byte gUnk_0868B5E8
.L0808F29C: .4byte gUnk_0868B88C
.L0808F2A0: .4byte gUnk_0868B610

	thumb_func_start func_fe6_0808F2A4
func_fe6_0808F2A4: @ 0x0808F2A4
	push {lr}
	ldr r0, .L0808F2D4 @ =gUnk_0868B648
	bl Proc_EndEach
	ldr r0, .L0808F2D8 @ =gUnk_0868B768
	bl Proc_EndEach
	ldr r0, .L0808F2DC @ =gUnk_0868B730
	bl Proc_EndEach
	ldr r0, .L0808F2E0 @ =gUnk_0868B6D8
	bl Proc_EndEach
	ldr r0, .L0808F2E4 @ =gUnk_0868B80C
	bl Proc_EndEach
	ldr r0, .L0808F2E8 @ =gUnk_0868B8AC
	bl Proc_EndEach
	ldr r0, .L0808F2EC @ =gUnk_0868B750
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
.L0808F2D4: .4byte gUnk_0868B648
.L0808F2D8: .4byte gUnk_0868B768
.L0808F2DC: .4byte gUnk_0868B730
.L0808F2E0: .4byte gUnk_0868B6D8
.L0808F2E4: .4byte gUnk_0868B80C
.L0808F2E8: .4byte gUnk_0868B8AC
.L0808F2EC: .4byte gUnk_0868B750

	thumb_func_start func_fe6_0808F2F0
func_fe6_0808F2F0: @ 0x0808F2F0
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0808F308 @ =0x02016A2C
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0808F304
	adds r0, r1, #0
	movs r1, #1
	bl Proc_Goto
.L0808F304:
	pop {r0}
	bx r0
	.align 2, 0
.L0808F308: .4byte 0x02016A2C

	thumb_func_start func_fe6_0808F30C
func_fe6_0808F30C: @ 0x0808F30C
	push {r4, r5, r6, lr}
	movs r6, #0
	bl GetNextChapterStatsSlot
	adds r5, r0, #0
	movs r4, #0
	cmp r6, r5
	bge .L0808F330
.L0808F31C:
	adds r0, r4, #0
	bl GetChapterStats
	ldr r0, [r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x16
	adds r6, r6, r0
	adds r4, #1
	cmp r4, r5
	blt .L0808F31C
.L0808F330:
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0808F33C
func_fe6_0808F33C: @ 0x0808F33C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	bl func_fe6_0808F30C
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r1, #0
	add r0, sp, #0xc
.L0808F34C:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge .L0808F34C
	bl GetNextChapterStatsSlot
	adds r6, r0, #0
	movs r4, #0
	cmp r4, r6
	bge .L0808F3C6
	ldr r5, .L0808F3E4 @ =ChapterInfoTable
.L0808F362:
	adds r0, r4, #0
	bl GetChapterStats
	ldr r2, [r0]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1a
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r5
	ldr r2, [sp]
	ldrb r1, [r1, #0x1e]
	adds r2, r1, r2
	str r2, [sp]
	ldr r2, [r0]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1a
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r5
	ldr r2, [sp, #4]
	ldrb r1, [r1, #0x1d]
	adds r2, r1, r2
	str r2, [sp, #4]
	ldr r2, [r0]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1a
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r5
	ldr r2, [sp, #8]
	ldrb r1, [r1, #0x1c]
	adds r2, r1, r2
	str r2, [sp, #8]
	ldr r1, [r0]
	lsls r1, r1, #0x1a
	lsrs r1, r1, #0x1a
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [sp, #0xc]
	ldrb r0, [r0, #0x1b]
	adds r1, r0, r1
	str r1, [sp, #0xc]
	adds r4, #1
	cmp r4, r6
	blt .L0808F362
.L0808F3C6:
	movs r4, #0
	mov r1, sp
.L0808F3CA:
	ldr r0, [r1]
	cmp r7, r0
	bgt .L0808F3D8
	adds r1, #4
	adds r4, #1
	cmp r4, #3
	ble .L0808F3CA
.L0808F3D8:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L0808F3E4: .4byte ChapterInfoTable

	thumb_func_start func_fe6_0808F3E8
func_fe6_0808F3E8: @ 0x0808F3E8
	push {lr}
	sub sp, #0x10
	bl func_fe6_08086AAC
	ldr r3, .L0808F44C @ =ChapterInfoTable
	ldr r2, [r0]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1a
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #0x1e]
	str r1, [sp]
	ldr r2, [r0]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1a
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #0x1d]
	str r1, [sp, #4]
	ldr r2, [r0]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1a
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #0x1c]
	str r1, [sp, #8]
	ldr r2, [r0]
	lsls r2, r2, #0x1a
	lsrs r2, r2, #0x1a
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #0x1b]
	str r1, [sp, #0xc]
	ldr r0, [r0]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x16
	ldr r0, .L0808F450 @ =0x02016A2D
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0808F454
	movs r0, #0
	b .L0808F46A
	.align 2, 0
.L0808F44C: .4byte ChapterInfoTable
.L0808F450: .4byte 0x02016A2D
.L0808F454:
	movs r2, #0
	mov r1, sp
.L0808F458:
	ldr r0, [r1]
	cmp r3, r0
	bgt .L0808F466
	adds r1, #4
	adds r2, #1
	cmp r2, #3
	ble .L0808F458
.L0808F466:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
.L0808F46A:
	add sp, #0x10
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0808F470
func_fe6_0808F470: @ 0x0808F470
	push {r4, lr}
	bl PidStatsCountTotalBattles
	adds r4, r0, #0
	bl PidStatsCountTotalWins
	movs r1, #0x64
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0808F490
func_fe6_0808F490: @ 0x0808F490
	push {lr}
	bl func_fe6_0808F470
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r1, #0
	ldr r3, .L0808F4B4 @ =gUnk_0868B79C
.L0808F49E:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r2, r0
	blt .L0808F4AC
	adds r1, #1
	cmp r1, #3
	ble .L0808F49E
.L0808F4AC:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
.L0808F4B4: .4byte gUnk_0868B79C

	thumb_func_start func_fe6_0808F4B8
func_fe6_0808F4B8: @ 0x0808F4B8
	push {r4, lr}
	bl PidStatsCountTotalBattles
	adds r4, r0, #0
	bl PidStatsCountTotalWins
	movs r1, #0x64
	muls r0, r1, r0
	adds r1, r4, #0
	bl __divsi3
	adds r2, r0, #0
	movs r1, #0
	ldr r3, .L0808F4EC @ =gUnk_0868B79C
.L0808F4D4:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r2, r0
	blt .L0808F4E2
	adds r1, #1
	cmp r1, #3
	ble .L0808F4D4
.L0808F4E2:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0808F4EC: .4byte gUnk_0868B79C

	thumb_func_start func_fe6_0808F4F0
func_fe6_0808F4F0: @ 0x0808F4F0
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #1
.L0808F4F6:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0808F514
	ldr r0, [r1]
	cmp r0, #0
	beq .L0808F514
	movs r0, #4
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	beq .L0808F514
	adds r5, #1
.L0808F514:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0808F4F6
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0808F524
func_fe6_0808F524: @ 0x0808F524
	push {lr}
	bl func_fe6_0808F4F0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r1, #0
	ldr r3, .L0808F54C @ =gUnk_0868B7A0
.L0808F532:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r2, r0
	bge .L0808F544
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls .L0808F532
.L0808F544:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
.L0808F54C: .4byte gUnk_0868B7A0

	thumb_func_start func_fe6_0808F550
func_fe6_0808F550: @ 0x0808F550
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #1
.L0808F556:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0808F574
	ldr r0, [r1]
	cmp r0, #0
	beq .L0808F574
	movs r0, #4
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	beq .L0808F574
	adds r5, #1
.L0808F574:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0808F556
	movs r1, #0
	ldr r2, .L0808F598 @ =gUnk_0868B7A4
.L0808F57E:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r5, r0
	bge .L0808F590
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls .L0808F57E
.L0808F590:
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L0808F598: .4byte gUnk_0868B7A4

	thumb_func_start func_fe6_0808F59C
func_fe6_0808F59C: @ 0x0808F59C
	push {lr}
	bl PidStatsCountTotalLevelsGained
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0808F5AC
func_fe6_0808F5AC: @ 0x0808F5AC
	push {r4, lr}
	bl func_fe6_0808F59C
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl GetNextChapterStatsSlot
	subs r0, #1
	bl GetChapterStats
	ldr r1, [r0]
	lsls r1, r1, #0x1a
	lsrs r1, r1, #0x1a
	movs r3, #0
	ldr r2, .L0808F5FC @ =ChapterInfoTable
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x26]
	cmp r4, r1
	ble .L0808F5F2
	movs r3, #1
	ldrh r1, [r0, #0x24]
	cmp r4, r1
	ble .L0808F5F2
	movs r3, #2
	ldrh r1, [r0, #0x22]
	cmp r4, r1
	ble .L0808F5F2
	movs r3, #3
	ldrh r0, [r0, #0x20]
	cmp r4, r0
	ble .L0808F5F2
	movs r3, #4
.L0808F5F2:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0808F5FC: .4byte ChapterInfoTable

	thumb_func_start func_fe6_0808F600
func_fe6_0808F600: @ 0x0808F600
	push {r4, lr}
	bl func_fe6_08017104
	adds r4, r0, #0
	bl GetNextChapterStatsSlot
	bl GetChapterStats
	ldr r0, .L0808F640 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterInfo
	adds r0, #0x3e
	ldrb r0, [r0]
	lsrs r3, r0, #1
	movs r1, #0
	ldr r2, .L0808F644 @ =gUnk_0868B7A8
.L0808F626:
	ldr r0, [r2]
	muls r0, r3, r0
	cmp r4, r0
	blo .L0808F636
	adds r2, #4
	adds r1, #1
	cmp r1, #3
	ble .L0808F626
.L0808F636:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0808F640: .4byte gPlaySt
.L0808F644: .4byte gUnk_0868B7A8

	thumb_func_start func_fe6_0808F648
func_fe6_0808F648: @ 0x0808F648
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #1
.L0808F64E:
	adds r0, r4, #0
	bl GetUnit
	adds r2, r0, #0
	cmp r2, #0
	beq .L0808F67A
	ldr r1, [r2]
	cmp r1, #0
	beq .L0808F67A
	ldr r0, [r2, #4]
	ldr r1, [r1, #0x28]
	ldr r0, [r0, #0x24]
	orrs r1, r0
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	beq .L0808F674
	adds r5, #0x14
.L0808F674:
	movs r0, #8
	ldrsb r0, [r2, r0]
	adds r5, r5, r0
.L0808F67A:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0808F64E
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0808F68C
func_fe6_0808F68C: @ 0x0808F68C
	push {r4, lr}
	bl func_fe6_0808F648
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl GetNextChapterStatsSlot
	subs r0, #1
	bl GetChapterStats
	ldr r1, [r0]
	lsls r1, r1, #0x1a
	lsrs r1, r1, #0x1a
	movs r3, #0
	ldr r2, .L0808F6DC @ =ChapterInfoTable
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x2e]
	cmp r4, r1
	ble .L0808F6D2
	movs r3, #1
	ldrh r1, [r0, #0x2c]
	cmp r4, r1
	ble .L0808F6D2
	movs r3, #2
	ldrh r1, [r0, #0x2a]
	cmp r4, r1
	ble .L0808F6D2
	movs r3, #3
	ldrh r0, [r0, #0x28]
	cmp r4, r0
	ble .L0808F6D2
	movs r3, #4
.L0808F6D2:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0808F6DC: .4byte ChapterInfoTable

	thumb_func_start func_fe6_0808F6E0
func_fe6_0808F6E0: @ 0x0808F6E0
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r5, .L0808F72C @ =gUnk_0868B7B8
	movs r3, #0
	ldr r1, .L0808F730 @ =0x02016A2E
	movs r2, #5
.L0808F6EC:
	ldrh r6, [r1]
	adds r0, r6, r3
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r3, #5
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge .L0808F6EC
	movs r2, #0
	ldr r0, .L0808F734 @ =gUnk_0868B7D6
.L0808F708:
	ldrh r1, [r0]
	cmp r4, r1
	blo .L0808F724
	adds r0, #2
	adds r2, #1
	cmp r2, #4
	ble .L0808F708
	ldr r1, .L0808F738 @ =gPlaySt
	movs r0, #0x40
	ldrb r1, [r1, #0x14]
	ands r0, r1
	cmp r0, #0
	beq .L0808F724
	adds r2, #1
.L0808F724:
	adds r0, r2, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L0808F72C: .4byte gUnk_0868B7B8
.L0808F730: .4byte 0x02016A2E
.L0808F734: .4byte gUnk_0868B7D6
.L0808F738: .4byte gPlaySt

	thumb_func_start func_fe6_0808F73C
func_fe6_0808F73C: @ 0x0808F73C
	push {r4, r5, lr}
	movs r3, #0
	ldr r4, .L0808F774 @ =gUnk_0868B7E2
	ldr r2, .L0808F778 @ =0x02016A2E
	movs r1, #2
.L0808F746:
	ldrh r5, [r2]
	adds r0, r5, r4
	ldrb r0, [r0]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bge .L0808F746
	movs r1, #0
	ldr r0, .L0808F77C @ =gUnk_0868B7E8
.L0808F75E:
	ldrh r2, [r0]
	cmp r3, r2
	blo .L0808F76C
	adds r0, #2
	adds r1, #1
	cmp r1, #4
	ble .L0808F75E
.L0808F76C:
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L0808F774: .4byte gUnk_0868B7E2
.L0808F778: .4byte 0x02016A2E
.L0808F77C: .4byte gUnk_0868B7E8

	thumb_func_start func_fe6_0808F780
func_fe6_0808F780: @ 0x0808F780
	push {lr}
	ldr r0, .L0808F78C @ =gUnk_0868B7F4
	bl InitBgs
	pop {r0}
	bx r0
	.align 2, 0
.L0808F78C: .4byte gUnk_0868B7F4

	thumb_func_start func_fe6_0808F790
func_fe6_0808F790: @ 0x0808F790
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0808F7AC @ =gUnk_0868B3FC
	ldr r0, [r0]
	adds r0, #0x9f
	ldrb r0, [r0]
	cmp r0, #2
	bls .L0808F7A8
	adds r0, r1, #0
	movs r1, #3
	bl Proc_Goto
.L0808F7A8:
	pop {r0}
	bx r0
	.align 2, 0
.L0808F7AC: .4byte gUnk_0868B3FC

	thumb_func_start func_fe6_0808F7B0
func_fe6_0808F7B0: @ 0x0808F7B0
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0808F7CC @ =gUnk_0868B3FC
	ldr r0, [r0]
	adds r0, #0x9f
	ldrb r0, [r0]
	cmp r0, #1
	bhi .L0808F7C8
	adds r0, r1, #0
	movs r1, #2
	bl Proc_Goto
.L0808F7C8:
	pop {r0}
	bx r0
	.align 2, 0
.L0808F7CC: .4byte gUnk_0868B3FC

	thumb_func_start func_fe6_0808F7D0
func_fe6_0808F7D0: @ 0x0808F7D0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r4, [sp, #0x18]
	ldr r6, [sp, #0x1c]
	str r4, [sp]
	bl Interpolate
	adds r5, r0, #0
	ldr r2, .L0808F810 @ =gUnk_08343358
	ldr r7, .L0808F814 @ =0x02016A2D
	ldrb r0, [r7]
	cmp r0, #0
	bne .L0808F7EC
	adds r2, #0x20
.L0808F7EC:
	lsls r1, r6, #5
	ldr r4, .L0808F818 @ =gPal
	adds r1, r1, r4
	adds r0, r2, #0
	movs r2, #8
	bl CpuFastSet
	ldrb r0, [r7]
	cmp r0, #0
	beq .L0808F81C
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #1
	movs r3, #7
	bl func_fe6_0808DA90
	b .L0808F82A
	.align 2, 0
.L0808F810: .4byte gUnk_08343358
.L0808F814: .4byte 0x02016A2D
.L0808F818: .4byte gPal
.L0808F81C:
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #1
	movs r3, #0xb
	bl func_fe6_0808DA14
.L0808F82A:
	bl EnablePalSync
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0808F838
func_fe6_0808F838: @ 0x0808F838
	movs r1, #0
	strh r1, [r0, #0x2a]
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0808F844
func_fe6_0808F844: @ 0x0808F844
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #2
	beq .L0808F87C
	cmp r0, #2
	bgt .L0808F85C
	cmp r0, #0
	beq .L0808F862
	b .L0808F8A4
.L0808F85C:
	cmp r0, #0x11
	beq .L0808F8A0
	b .L0808F8A4
.L0808F862:
	movs r1, #0x2a
	ldrsh r0, [r4, r1]
	cmp r0, #0x59
	bgt .L0808F8A4
	adds r3, r0, #0
	movs r0, #0x5a
	str r0, [sp]
	movs r0, #0x13
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0xf
	b .L0808F894
.L0808F87C:
	movs r1, #0x2a
	ldrsh r0, [r4, r1]
	cmp r0, #0x77
	bgt .L0808F8A4
	adds r3, r0, #0
	movs r0, #0x78
	str r0, [sp]
	movs r0, #0x13
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0xf
	movs r2, #0
.L0808F894:
	bl func_fe6_0808F7D0
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
	b .L0808F8AE
.L0808F8A0:
	movs r0, #0
	b .L0808F8AC
.L0808F8A4:
	movs r0, #0
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
.L0808F8AC:
	strh r0, [r4, #0x2e]
.L0808F8AE:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0808F8B8
func_fe6_0808F8B8: @ 0x0808F8B8
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #4
	movs r0, #0x80
	lsls r0, r0, #1
	mov r8, r0
	str r0, [sp]
	movs r0, #0xa
	mov r1, r8
	movs r2, #0
	movs r3, #0
	bl SetObjAffine
	ldr r4, .L0808F96C @ =gSinLut
	movs r1, #0x80
	adds r1, r1, r4
	mov sb, r1
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	movs r1, #2
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r1, #0
	ldrsh r0, [r4, r1]
	rsbs r0, r0, #0
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	movs r2, #0
	ldrsh r0, [r4, r2]
	lsls r0, r0, #4
	movs r1, #2
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0x1f
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	ldr r2, .L0808F970 @ =0x02016A2A
	ldr r0, .L0808F974 @ =0x02016A2D
	ldrb r0, [r0]
	movs r1, #2
	cmp r0, #0
	beq .L0808F944
	movs r1, #1
.L0808F944:
	strh r1, [r2]
	ldr r0, .L0808F978 @ =gUnk_0868B730
	movs r1, #3
	bl SpawnProc
	ldr r0, .L0808F97C @ =gUnk_0868B80C
	movs r1, #3
	bl SpawnProc
	ldr r0, .L0808F980 @ =gUnk_0868B88C
	movs r1, #3
	bl SpawnProc
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808F96C: .4byte gSinLut
.L0808F970: .4byte 0x02016A2A
.L0808F974: .4byte 0x02016A2D
.L0808F978: .4byte gUnk_0868B730
.L0808F97C: .4byte gUnk_0868B80C
.L0808F980: .4byte gUnk_0868B88C

	thumb_func_start func_fe6_0808F984
func_fe6_0808F984: @ 0x0808F984
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r6, #0
	ldr r1, .L0808FA10 @ =gUnk_0868B3FC
	ldr r0, [r1]
	adds r0, #0x9f
	ldrb r0, [r0]
	adds r0, #1
	cmp r6, r0
	bge .L0808FA08
	adds r7, r1, #0
.L0808F99A:
	ldr r3, [r7]
	lsls r1, r6, #1
	adds r0, r3, #0
	adds r0, #0x42
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, #6
	lsls r5, r0, #3
	adds r0, r3, #0
	adds r0, #0x50
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r4, r0, #3
	adds r0, r3, #0
	adds r0, #0x9f
	ldrb r0, [r0]
	cmp r6, r0
	bne .L0808F9CE
	movs r0, #0xf8
	lsls r0, r0, #6
	orrs r5, r0
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r4, r0
.L0808F9CE:
	adds r0, r3, #0
	adds r0, #0x5e
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r2, r0, #1
	adds r2, #0xc0
	lsls r1, r6, #2
	adds r0, r3, #0
	adds r0, #0x7c
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r6, #4
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #0xc
	orrs r0, r2
	str r0, [sp]
	movs r0, #4
	adds r1, r5, #0
	adds r2, r4, #0
	bl PutSpriteExt
	adds r6, #1
	ldr r0, [r7]
	adds r0, #0x9f
	ldrb r0, [r0]
	adds r0, #1
	cmp r6, r0
	blt .L0808F99A
.L0808FA08:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808FA10: .4byte gUnk_0868B3FC

	thumb_func_start func_fe6_0808FA14
func_fe6_0808FA14: @ 0x0808FA14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	bl HasNextChapter
	ldr r1, .L0808FCA0 @ =0x02016A2D
	strb r0, [r1]
	bl ResetText
	bl UnpackUiWindowFrameGraphics
	bl ResetTextFont
	bl func_fe6_0808E79C
	ldr r7, .L0808FCA4 @ =gDispIo
	movs r4, #1
	ldrb r0, [r7, #1]
	orrs r0, r4
	movs r2, #2
	mov sb, r2
	mov r6, sb
	orrs r0, r6
	movs r1, #4
	mov r8, r1
	mov r2, r8
	orrs r0, r2
	movs r6, #8
	orrs r0, r6
	movs r5, #0x10
	orrs r0, r5
	strb r0, [r7, #1]
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
	movs r2, #0x20
	ldrb r0, [r7, #1]
	orrs r0, r2
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r7, #1]
	adds r0, r7, #0
	adds r0, #0x2d
	movs r1, #0
	mov sl, r1
	mov r6, sl
	strb r6, [r0]
	adds r1, r7, #0
	adds r1, #0x31
	movs r0, #0x18
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x88
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	orrs r4, r0
	mov r6, sb
	orrs r4, r6
	mov r0, r8
	orrs r4, r0
	movs r6, #8
	orrs r4, r6
	orrs r4, r5
	adds r3, r7, #0
	adds r3, #0x36
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r6, [r3]
	ands r0, r6
	mov r6, sb
	orrs r0, r6
	mov r6, r8
	orrs r0, r6
	movs r6, #8
	orrs r0, r6
	orrs r0, r5
	orrs r4, r2
	strb r4, [r1]
	orrs r0, r2
	strb r0, [r3]
	ldr r0, .L0808FCA8 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L0808FCAC @ =gBg1Tm
	movs r1, #0
	bl TmFill
	ldr r5, .L0808FCB0 @ =gBg2Tm
	adds r0, r5, #0
	movs r1, #0
	bl TmFill
	ldr r6, .L0808FCB4 @ =gBg3Tm
	adds r0, r6, #0
	movs r1, #0
	bl TmFill
	adds r2, r7, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #6
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x46
	mov r2, sl
	strb r2, [r0]
	ldr r0, .L0808FCB8 @ =0x0000FFE0
	ldrh r1, [r7, #0x3c]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	ldr r1, .L0808FCBC @ =0x0000E0FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r7, #0x3c]
	bl func_fe6_0808DD78
	ldr r0, .L0808FCC0 @ =gUnk_0834138C
	movs r1, #0x80
	movs r2, #0x40
	bl ApplyPaletteExt
	ldr r0, .L0808FCC4 @ =gUnk_08341DA0
	movs r1, #0xc0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L0808FCC8 @ =gUnk_0833C03C
	movs r1, #0x90
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r2, .L0808FCCC @ =gUnk_08343358
	ldr r1, .L0808FCA0 @ =0x02016A2D
	ldrb r0, [r1]
	cmp r0, #0
	bne .L0808FB7C
	adds r2, #0x20
.L0808FB7C:
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r2, #0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L0808FCD0 @ =gUnk_08342A98
	movs r1, #0xd8
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L0808FCD4 @ =Img_Unk_083092CC
	ldr r1, .L0808FCD8 @ =0x06011000
	bl Decompress
	ldr r0, .L0808FCDC @ =gUnk_08342438
	ldr r1, .L0808FCE0 @ =0x06011800
	bl Decompress
	ldr r0, .L0808FCE4 @ =gUnk_08342B54
	ldr r1, .L0808FCE8 @ =0x06013000
	bl Decompress
	ldr r0, .L0808FCEC @ =gUnk_083413CC
	ldr r1, .L0808FCF0 @ =0x0600D000
	bl Decompress
	ldr r4, .L0808FCF4 @ =gUnk_0833C984
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	adds r0, r4, #0
	bl Decompress
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r5, #0
	movs r2, #6
	bl func_fe6_0808ECD0
	ldr r1, .L0808FCF8 @ =gUnk_08340ED8
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r6, #0
	bl TmApplyTsa_thm
	ldr r5, .L0808FCFC @ =gUnk_0868B3FC
	movs r4, #0xe8
	movs r6, #3
.L0808FBE8:
	ldr r0, [r5]
	adds r0, r0, r4
	movs r1, #6
	bl InitText
	adds r4, #8
	subs r6, #1
	cmp r6, #0
	bge .L0808FBE8
	bl func_fe6_08086AAC
	adds r5, r0, #0
	ldr r4, .L0808FD00 @ =gBg0Tm+0x1CA
	ldr r2, [r5]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x16
	adds r0, r4, #0
	movs r1, #2
	bl PutNumber
	ldr r0, .L0808FD04 @ =0x00000725
	bl DecodeMsg
	adds r1, r4, #2
	movs r2, #6
	str r2, [sp]
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl PutDrawText
	adds r4, #0x1a
	movs r0, #0xb4
	ldrh r5, [r5, #2]
	adds r2, r5, #0
	muls r2, r0, r2
	adds r0, r4, #0
	movs r1, #2
	movs r3, #1
	bl PutTime
	movs r7, #0xe8
	ldr r5, .L0808FD08 @ =gUnk_0868B490
	movs r6, #3
.L0808FC42:
	ldrh r0, [r5]
	bl DecodeMsg
	adds r4, r0, #0
	ldr r0, .L0808FCFC @ =gUnk_0868B3FC
	ldr r0, [r0]
	adds r0, r0, r7
	ldrb r2, [r5, #0xd]
	lsls r1, r2, #5
	subs r1, #1
	ldrb r2, [r5, #0xc]
	adds r1, r2, r1
	lsls r1, r1, #1
	ldr r2, .L0808FCA8 @ =gBg0Tm
	adds r1, r1, r2
	ldr r2, [r5, #4]
	movs r3, #6
	str r3, [sp]
	str r4, [sp, #4]
	movs r3, #0
	bl PutDrawText
	adds r7, #8
	adds r5, #0x10
	subs r6, #1
	cmp r6, #0
	bge .L0808FC42
	ldr r0, .L0808FD0C @ =gUnk_0868B768
	movs r1, #3
	bl SpawnProc
	ldr r0, .L0808FD10 @ =gUnk_0868B8AC
	movs r1, #3
	bl SpawnProc
	movs r0, #0xf
	bl EnableBgSync
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808FCA0: .4byte 0x02016A2D
.L0808FCA4: .4byte gDispIo
.L0808FCA8: .4byte gBg0Tm
.L0808FCAC: .4byte gBg1Tm
.L0808FCB0: .4byte gBg2Tm
.L0808FCB4: .4byte gBg3Tm
.L0808FCB8: .4byte 0x0000FFE0
.L0808FCBC: .4byte 0x0000E0FF
.L0808FCC0: .4byte gUnk_0834138C
.L0808FCC4: .4byte gUnk_08341DA0
.L0808FCC8: .4byte gUnk_0833C03C
.L0808FCCC: .4byte gUnk_08343358
.L0808FCD0: .4byte gUnk_08342A98
.L0808FCD4: .4byte Img_Unk_083092CC
.L0808FCD8: .4byte 0x06011000
.L0808FCDC: .4byte gUnk_08342438
.L0808FCE0: .4byte 0x06011800
.L0808FCE4: .4byte gUnk_08342B54
.L0808FCE8: .4byte 0x06013000
.L0808FCEC: .4byte gUnk_083413CC
.L0808FCF0: .4byte 0x0600D000
.L0808FCF4: .4byte gUnk_0833C984
.L0808FCF8: .4byte gUnk_08340ED8
.L0808FCFC: .4byte gUnk_0868B3FC
.L0808FD00: .4byte gBg0Tm+0x1CA
.L0808FD04: .4byte 0x00000725
.L0808FD08: .4byte gUnk_0868B490
.L0808FD0C: .4byte gUnk_0868B768
.L0808FD10: .4byte gUnk_0868B8AC

	thumb_func_start func_fe6_0808FD14
func_fe6_0808FD14: @ 0x0808FD14
	push {lr}
	adds r2, r0, #0
	ldr r0, .L0808FD3C @ =gKeySt
	ldr r1, [r0]
	movs r0, #3
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0808FD38
	ldr r0, .L0808FD40 @ =gUnk_0868B3FC
	ldr r0, [r0]
	adds r0, #0x9f
	ldrb r0, [r0]
	cmp r0, #3
	bne .L0808FD38
	adds r0, r2, #0
	bl Proc_Break
.L0808FD38:
	pop {r0}
	bx r0
	.align 2, 0
.L0808FD3C: .4byte gKeySt
.L0808FD40: .4byte gUnk_0868B3FC

	thumb_func_start func_fe6_0808FD44
func_fe6_0808FD44: @ 0x0808FD44
	push {lr}
	adds r1, r0, #0
	cmp r1, #0
	bne .L0808FD5C
	ldr r0, .L0808FD58 @ =gUnk_0868B8E4
	movs r1, #3
	bl SpawnProc
	b .L0808FD62
	.align 2, 0
.L0808FD58: .4byte gUnk_0868B8E4
.L0808FD5C:
	ldr r0, .L0808FD68 @ =gUnk_0868B8E4
	bl SpawnProcLocking
.L0808FD62:
	pop {r0}
	bx r0
	.align 2, 0
.L0808FD68: .4byte gUnk_0868B8E4

	thumb_func_start func_fe6_0808FD6C
func_fe6_0808FD6C: @ 0x0808FD6C
	push {lr}
	adds r1, r0, #0
	cmp r1, #0
	bne .L0808FD84
	ldr r0, .L0808FD80 @ =gUnk_0868B99C
	movs r1, #3
	bl SpawnProc
	b .L0808FD8A
	.align 2, 0
.L0808FD80: .4byte gUnk_0868B99C
.L0808FD84:
	ldr r0, .L0808FD90 @ =gUnk_0868B99C
	bl SpawnProcLocking
.L0808FD8A:
	pop {r0}
	bx r0
	.align 2, 0
.L0808FD90: .4byte gUnk_0868B99C

	thumb_func_start func_fe6_0808FD94
func_fe6_0808FD94: @ 0x0808FD94
	push {r4, lr}
	ldr r4, .L0808FDCC @ =gUnk_083442C4
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #0x20
	bl ApplyPaletteExt
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, #0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L0808FDD0 @ =gUnk_08343398
	ldr r1, .L0808FDD4 @ =0x06015000
	bl Decompress
	ldr r0, .L0808FDD8 @ =gUnk_08343A80
	ldr r1, .L0808FDDC @ =0x06014000
	bl Decompress
	ldr r0, .L0808FDE0 @ =gUnk_08343FAC
	ldr r1, .L0808FDE4 @ =0x06001000
	bl Decompress
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808FDCC: .4byte gUnk_083442C4
.L0808FDD0: .4byte gUnk_08343398
.L0808FDD4: .4byte 0x06015000
.L0808FDD8: .4byte gUnk_08343A80
.L0808FDDC: .4byte 0x06014000
.L0808FDE0: .4byte gUnk_08343FAC
.L0808FDE4: .4byte 0x06001000

	thumb_func_start func_fe6_0808FDE8
func_fe6_0808FDE8: @ 0x0808FDE8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	adds r3, r5, #0
	lsls r0, r3, #0x10
	cmp r0, #0
	beq .L0808FE30
.L0808FE00:
	asrs r0, r0, #0x10
	subs r0, r5, r0
	lsls r0, r0, #6
	adds r2, r7, r0
	lsls r1, r6, #0x10
	lsls r3, r3, #0x10
	cmp r1, #0
	beq .L0808FE24
.L0808FE10:
	strh r4, [r2]
	adds r2, #2
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, .L0808FE38 @ =0xFFFF0000
	adds r1, r1, r0
	asrs r0, r1, #0x10
	cmp r0, #0
	bgt .L0808FE10
.L0808FE24:
	ldr r1, .L0808FE38 @ =0xFFFF0000
	adds r0, r3, r1
	lsrs r3, r0, #0x10
	lsls r0, r3, #0x10
	cmp r0, #0
	bgt .L0808FE00
.L0808FE30:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808FE38: .4byte 0xFFFF0000

	thumb_func_start func_fe6_0808FE3C
func_fe6_0808FE3C: @ 0x0808FE3C
	push {r4, lr}
	adds r4, r0, #0
	bl UnpackUiWindowFrameGraphics
	adds r4, #0x64
	movs r3, #0
	movs r0, #0
	strh r0, [r4]
	ldr r0, .L0808FEA4 @ =0x02016A3C
	strb r3, [r0]
	ldr r0, .L0808FEA8 @ =0x02016A3D
	strb r3, [r0]
	ldr r0, .L0808FEAC @ =0x02016A3F
	strb r3, [r0]
	ldr r0, .L0808FEB0 @ =0x02016A40
	strb r3, [r0]
	ldr r4, .L0808FEB4 @ =gDispIo
	adds r2, r4, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x44
	strb r3, [r0]
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x46
	strb r3, [r0]
	ldr r0, .L0808FEB8 @ =0x0000FFE0
	ldrh r2, [r4, #0x3c]
	ands r0, r2
	movs r1, #3
	orrs r0, r1
	ldr r1, .L0808FEBC @ =0x0000E0FF
	ands r0, r1
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4, #0x3c]
	bl func_fe6_0808FD94
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808FEA4: .4byte 0x02016A3C
.L0808FEA8: .4byte 0x02016A3D
.L0808FEAC: .4byte 0x02016A3F
.L0808FEB0: .4byte 0x02016A40
.L0808FEB4: .4byte gDispIo
.L0808FEB8: .4byte 0x0000FFE0
.L0808FEBC: .4byte 0x0000E0FF

	thumb_func_start func_fe6_0808FEC0
func_fe6_0808FEC0: @ 0x0808FEC0
	push {lr}
	ldr r2, .L0808FED4 @ =0x02016A41
	movs r1, #1
	strb r1, [r2]
	bl func_fe6_0808FE3C
	bl func_fe6_08091588
	pop {r0}
	bx r0
	.align 2, 0
.L0808FED4: .4byte 0x02016A41

	thumb_func_start func_fe6_0808FED8
func_fe6_0808FED8: @ 0x0808FED8
	push {lr}
	ldr r2, .L0808FEEC @ =0x02016A41
	movs r1, #2
	strb r1, [r2]
	bl func_fe6_0808FE3C
	bl func_fe6_08091588
	pop {r0}
	bx r0
	.align 2, 0
.L0808FEEC: .4byte 0x02016A41

	thumb_func_start func_fe6_0808FEF0
func_fe6_0808FEF0: @ 0x0808FEF0
	push {lr}
	ldr r2, .L0808FF00 @ =0x02016A41
	movs r1, #0
	strb r1, [r2]
	bl func_fe6_0808FE3C
	pop {r0}
	bx r0
	.align 2, 0
.L0808FF00: .4byte 0x02016A41

	thumb_func_start func_fe6_0808FF04
func_fe6_0808FF04: @ 0x0808FF04
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r0, .L0808FF34 @ =0x02016A42
	ldrb r0, [r0]
	cmp r0, #0x13
	bhi .L0808FF40
	ldr r1, .L0808FF38 @ =0x02016A43
	adds r2, r3, #0
	adds r2, #0x4c
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, r0, r1
	movs r1, #0x16
	strb r1, [r0]
	ldr r1, .L0808FF3C @ =0x02016AC3
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, r0, r1
	asrs r1, r4, #1
	strb r1, [r0]
	b .L0808FF8C
	.align 2, 0
.L0808FF34: .4byte 0x02016A42
.L0808FF38: .4byte 0x02016A43
.L0808FF3C: .4byte 0x02016AC3
.L0808FF40:
	ldr r1, .L0808FF5C @ =0x02016AC3
	adds r0, r3, #0
	adds r0, #0x4c
	movs r2, #0
	ldrsh r4, [r0, r2]
	adds r3, r4, r1
	ldrb r1, [r3]
	adds r2, r0, #0
	cmp r1, #0
	beq .L0808FF60
	subs r0, r1, #1
	strb r0, [r3]
	b .L0808FF8C
	.align 2, 0
.L0808FF5C: .4byte 0x02016AC3
.L0808FF60:
	ldr r3, .L0808FF88 @ =0x02016A43
	adds r0, r4, r3
	ldrb r1, [r0]
	adds r1, #4
	strb r1, [r0]
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r0, r0, r3
	ldrb r1, [r0]
	cmp r1, r5
	ble .L0808FF78
	strb r5, [r0]
.L0808FF78:
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r3
	ldrb r0, [r0]
	b .L0808FF94
	.align 2, 0
.L0808FF88: .4byte 0x02016A43
.L0808FF8C:
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	movs r0, #0xf0
.L0808FF94:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0808FF9C
func_fe6_0808FF9C: @ 0x0808FF9C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	ldr r2, .L0808FFC8 @ =gUnk_0868BB1C
	ldrb r0, [r2]
	cmp r0, #0
	beq .L0808FFD8
	movs r1, #0
	adds r3, r2, #0
.L0808FFB0:
	ldrb r0, [r3]
	cmp r0, r6
	bne .L0808FFCC
	ldrb r0, [r3, #1]
	cmp r0, r5
	bne .L0808FFCC
	ldrb r3, [r3, #2]
	adds r0, r3, r4
	adds r4, r0, #0
	subs r4, #8
	b .L0808FFD8
	.align 2, 0
.L0808FFC8: .4byte gUnk_0868BB1C
.L0808FFCC:
	adds r1, #4
	adds r3, #4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0808FFB0
.L0808FFD8:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0808FFE0
func_fe6_0808FFE0: @ 0x0808FFE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	mov r8, r1
	ldr r2, .L08090050 @ =gUnk_0866354C
	lsls r0, r1, #1
	add r0, r8
	lsls r4, r0, #2
	adds r1, r4, r2
	ldrb r3, [r1, #8]
	lsls r0, r3, #3
	adds r5, r0, #0
	adds r5, #0x16
	ldrb r0, [r1, #9]
	adds r0, #2
	lsls r7, r0, #3
	movs r6, #0
	str r6, [sp, #8]
	movs r3, #0
	mov ip, r3
	ldr r1, .L08090054 @ =0x02016A3C
	ldrb r6, [r1]
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	subs r0, #1
	cmp r0, #1
	bhi .L08090026
	b .L080902D0
.L08090026:
	ldr r0, [sp]
	adds r0, #0x4c
	mov r1, sp
	ldrh r1, [r1, #8]
	strh r1, [r0]
	ldr r0, .L08090058 @ =0x02016A3F
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0809003A
	b .L080902D0
.L0809003A:
	movs r6, #0
	str r6, [sp, #4]
	cmp r0, #1
	bne .L08090048
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [sp, #4]
.L08090048:
	adds r0, r2, #4
	adds r0, r4, r0
	ldr r0, [r0]
	b .L080902BA
	.align 2, 0
.L08090050: .4byte gUnk_0866354C
.L08090054: .4byte 0x02016A3C
.L08090058: .4byte 0x02016A3F
.L0809005C:
	mov r0, sl
	subs r0, #0xa
	cmp r0, #0x24
	bls .L08090066
	b .L0809017C
.L08090066:
	lsls r0, r0, #2
	ldr r1, .L08090070 @ =.L08090074
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08090070: .4byte .L08090074
.L08090074: @ jump table
	.4byte .L08090108 @ case 0
	.4byte .L0809017C @ case 1
	.4byte .L0809017C @ case 2
	.4byte .L0809017C @ case 3
	.4byte .L0809017C @ case 4
	.4byte .L0809017C @ case 5
	.4byte .L0809017C @ case 6
	.4byte .L0809017C @ case 7
	.4byte .L0809017C @ case 8
	.4byte .L0809017C @ case 9
	.4byte .L0809017C @ case 10
	.4byte .L0809017C @ case 11
	.4byte .L0809017C @ case 12
	.4byte .L0809017C @ case 13
	.4byte .L0809017C @ case 14
	.4byte .L0809017C @ case 15
	.4byte .L0809017C @ case 16
	.4byte .L0809017C @ case 17
	.4byte .L0809017C @ case 18
	.4byte .L0809017C @ case 19
	.4byte .L0809017C @ case 20
	.4byte .L0809017C @ case 21
	.4byte .L08090128 @ case 22
	.4byte .L0809017C @ case 23
	.4byte .L0809017C @ case 24
	.4byte .L0809017C @ case 25
	.4byte .L0809017C @ case 26
	.4byte .L0809017C @ case 27
	.4byte .L0809012C @ case 28
	.4byte .L0809017C @ case 29
	.4byte .L0809017C @ case 30
	.4byte .L0809017C @ case 31
	.4byte .L0809017C @ case 32
	.4byte .L0809017C @ case 33
	.4byte .L08090130 @ case 34
	.4byte .L0809017C @ case 35
	.4byte .L08090134 @ case 36
.L08090108:
	adds r7, #0x10
	ldr r1, .L08090124 @ =gUnk_0866354C
	mov r3, r8
	lsls r2, r3, #1
	adds r0, r2, r3
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #8]
	lsls r0, r0, #3
	adds r5, r0, #0
	adds r5, #0x16
	movs r3, #0
	b .L080902A2
	.align 2, 0
.L08090124: .4byte gUnk_0866354C
.L08090128:
	adds r5, #7
	b .L0809029E
.L0809012C:
	movs r4, #0x1c
	b .L08090136
.L08090130:
	movs r4, #0x1a
	b .L08090136
.L08090134:
	movs r4, #0x1b
.L08090136:
	ldr r0, [sp]
	adds r1, r5, #0
	adds r2, r7, #0
	bl func_fe6_0808FF04
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r7, #0
	ldr r6, [sp, #4]
	orrs r1, r6
	ldr r2, .L08090174 @ =Sprite_16x16
	lsls r3, r4, #1
	movs r4, #0xa8
	lsls r4, r4, #2
	adds r3, r3, r4
	movs r4, #0x80
	lsls r4, r4, #7
	orrs r3, r4
	bl PutOamHiRam
	adds r2, r5, #1
	ldr r1, .L08090178 @ =gUnk_0868BA3C
	adds r0, r1, #0
	adds r0, #0xd0
	ldrb r0, [r0]
	adds r5, r0, r2
	adds r1, #0xd2
	ldrb r3, [r1]
	mov r6, r8
	lsls r2, r6, #1
	b .L080902A2
	.align 2, 0
.L08090174: .4byte Sprite_16x16
.L08090178: .4byte gUnk_0868BA3C
.L0809017C:
	cmp r4, #0x60
	bgt .L08090214
	subs r4, #0x41
	movs r0, #0
	mov sb, r0
	cmp r4, #0xf
	ble .L0809018E
	movs r1, #0x20
	mov sb, r1
.L0809018E:
	cmp r3, #0
	beq .L080901B4
	ldr r0, .L080901B0 @ =gUnk_0868BA3C
	lsls r1, r4, #3
	adds r0, r1, r0
	ldrb r0, [r0, #1]
	adds r2, r0, r3
	movs r0, #0xff
	ands r2, r0
	adds r6, r1, #0
	cmp r2, #0x7f
	bgt .L080901C8
	movs r0, #0xf
	ands r2, r0
	asrs r0, r2, #1
	subs r5, r5, r0
	b .L080901C8
	.align 2, 0
.L080901B0: .4byte gUnk_0868BA3C
.L080901B4:
	ldr r0, .L0809020C @ =gUnk_0868BA3C
	lsls r2, r4, #3
	adds r0, r2, r0
	movs r1, #0x40
	ldrb r0, [r0, #1]
	ands r1, r0
	adds r6, r2, #0
	cmp r1, #0
	beq .L080901C8
	subs r5, #2
.L080901C8:
	adds r0, r5, #0
	mov r1, ip
	mov r2, sl
	bl func_fe6_0808FF9C
	adds r5, r0, #0
	ldr r0, [sp]
	adds r1, r5, #0
	adds r2, r7, #0
	bl func_fe6_0808FF04
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r7, #0
	ldr r2, [sp, #4]
	orrs r1, r2
	ldr r2, .L08090210 @ =Sprite_16x16
	lsls r3, r4, #1
	movs r4, #0xa0
	lsls r4, r4, #2
	add r4, sb
	adds r3, r3, r4
	movs r4, #0x80
	lsls r4, r4, #7
	orrs r3, r4
	bl PutOamHiRam
	adds r1, r5, #1
	ldr r0, .L0809020C @ =gUnk_0868BA3C
	adds r0, r6, r0
	ldrb r3, [r0]
	adds r5, r3, r1
	ldrb r3, [r0, #2]
	b .L0809029E
	.align 2, 0
.L0809020C: .4byte gUnk_0868BA3C
.L08090210: .4byte Sprite_16x16
.L08090214:
	subs r4, #0x61
	movs r6, #0
	mov sb, r6
	cmp r4, #0xf
	ble .L08090222
	movs r0, #0x20
	mov sb, r0
.L08090222:
	cmp r3, #0
	beq .L08090248
	ldr r0, .L08090244 @ =gUnk_0868BA3C
	lsls r1, r4, #3
	adds r0, r1, r0
	ldrb r0, [r0, #4]
	adds r2, r0, r3
	movs r0, #0xff
	ands r2, r0
	adds r6, r1, #0
	cmp r2, #0x7f
	bgt .L0809025C
	movs r0, #0xf
	ands r2, r0
	asrs r0, r2, #1
	subs r5, r5, r0
	b .L0809025C
	.align 2, 0
.L08090244: .4byte gUnk_0868BA3C
.L08090248:
	ldr r0, .L080902E0 @ =gUnk_0868BA3C
	lsls r2, r4, #3
	adds r0, r2, r0
	movs r1, #0x40
	ldrb r0, [r0, #4]
	ands r1, r0
	adds r6, r2, #0
	cmp r1, #0
	beq .L0809025C
	subs r5, #2
.L0809025C:
	adds r0, r5, #0
	mov r1, ip
	mov r2, sl
	bl func_fe6_0808FF9C
	adds r5, r0, #0
	ldr r0, [sp]
	adds r1, r5, #0
	adds r2, r7, #0
	bl func_fe6_0808FF04
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r7, #1
	ldr r2, [sp, #4]
	orrs r1, r2
	ldr r2, .L080902E4 @ =Sprite_16x16
	lsls r3, r4, #1
	movs r4, #0x80
	lsls r4, r4, #2
	add r4, sb
	adds r3, r3, r4
	movs r4, #0x80
	lsls r4, r4, #7
	orrs r3, r4
	bl PutOamHiRam
	adds r1, r5, #1
	ldr r0, .L080902E0 @ =gUnk_0868BA3C
	adds r0, r6, r0
	ldrb r3, [r0, #3]
	adds r5, r3, r1
	ldrb r3, [r0, #5]
.L0809029E:
	mov r4, r8
	lsls r2, r4, #1
.L080902A2:
	mov ip, sl
	ldr r6, [sp, #8]
	adds r6, #1
	str r6, [sp, #8]
	ldr r1, .L080902E8 @ =gUnk_0866354C
	mov r4, r8
	adds r0, r2, r4
	lsls r0, r0, #2
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r0, r6
.L080902BA:
	ldrb r4, [r0]
	mov sl, r4
	cmp r4, #0
	beq .L080902C4
	b .L0809005C
.L080902C4:
	ldr r1, .L080902EC @ =0x02016A42
	ldrb r0, [r1]
	cmp r0, #0x13
	bhi .L080902D0
	adds r0, #1
	strb r0, [r1]
.L080902D0:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080902E0: .4byte gUnk_0868BA3C
.L080902E4: .4byte Sprite_16x16
.L080902E8: .4byte gUnk_0866354C
.L080902EC: .4byte 0x02016A42

	thumb_func_start func_fe6_080902F0
func_fe6_080902F0: @ 0x080902F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	ldr r4, .L08090374 @ =gUnk_0866354C
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r4
	mov r8, r0
	ldrb r6, [r0, #8]
	adds r6, #1
	ldrb r1, [r0, #9]
	lsls r1, r1, #5
	mov sl, r1
	movs r0, #0
	mov sb, r0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r0, .L08090378 @ =0x02016A42
	mov r1, sb
	strb r1, [r0]
	cmp r5, #0
	beq .L0809035E
	subs r1, r5, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r0, [r0, #9]
	lsls r4, r0, #6
	ldr r0, .L0809037C @ =gBg0Tm
	adds r0, r4, r0
	movs r1, #0x1e
	movs r2, #2
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L08090380 @ =gBg1Tm
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x1e
	movs r2, #2
	movs r3, #0
	bl TmFillRect_thm
.L0809035E:
	movs r7, #0x81
	lsls r7, r7, #7
	mov r1, r8
	ldr r0, [r1]
	cmp r0, #0
	bne .L0809036C
	b .L080904D6
.L0809036C:
	ldr r1, .L0809037C @ =gBg0Tm
	mov r8, r1
	b .L080904CE
	.align 2, 0
.L08090374: .4byte gUnk_0866354C
.L08090378: .4byte 0x02016A42
.L0809037C: .4byte gBg0Tm
.L08090380: .4byte gBg1Tm
.L08090384:
	adds r0, r4, #0
	subs r0, #0xa
	cmp r0, #0x24
	bls .L0809038E
	b .L0809049C
.L0809038E:
	lsls r0, r0, #2
	ldr r1, .L0809039C @ =.L080903A0
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r2, r5, #1
	mov pc, r0
	.align 2, 0
.L0809039C: .4byte .L080903A0
.L080903A0: @ jump table
	.4byte .L08090434 @ case 0
	.4byte .L0809049C @ case 1
	.4byte .L0809049C @ case 2
	.4byte .L0809049C @ case 3
	.4byte .L0809049C @ case 4
	.4byte .L0809049C @ case 5
	.4byte .L0809049C @ case 6
	.4byte .L0809049C @ case 7
	.4byte .L0809049C @ case 8
	.4byte .L0809049C @ case 9
	.4byte .L0809049C @ case 10
	.4byte .L0809049C @ case 11
	.4byte .L0809049C @ case 12
	.4byte .L0809049C @ case 13
	.4byte .L0809049C @ case 14
	.4byte .L0809049C @ case 15
	.4byte .L0809049C @ case 16
	.4byte .L0809049C @ case 17
	.4byte .L0809049C @ case 18
	.4byte .L0809049C @ case 19
	.4byte .L0809049C @ case 20
	.4byte .L0809049C @ case 21
	.4byte .L080904B4 @ case 22
	.4byte .L0809049C @ case 23
	.4byte .L0809049C @ case 24
	.4byte .L0809049C @ case 25
	.4byte .L0809049C @ case 26
	.4byte .L0809049C @ case 27
	.4byte .L08090468 @ case 28
	.4byte .L0809049C @ case 29
	.4byte .L0809049C @ case 30
	.4byte .L0809049C @ case 31
	.4byte .L0809049C @ case 32
	.4byte .L0809049C @ case 33
	.4byte .L08090494 @ case 34
	.4byte .L0809049C @ case 35
	.4byte .L08090498 @ case 36
.L08090434:
	ldr r0, .L08090460 @ =gUnk_0866354C
	lsls r4, r5, #1
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r6, [r1, #8]
	adds r6, #1
	movs r0, #0
	movs r1, #0
	movs r2, #0xa
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0xfe
	bl SetBgOffset
	ldr r0, .L08090464 @ =gBg1Tm
	mov r8, r0
	adds r2, r4, #0
	b .L080904B4
	.align 2, 0
.L08090460: .4byte gUnk_0866354C
.L08090464: .4byte gBg1Tm
.L08090468:
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	mov r0, sl
	adds r1, r0, r2
	lsls r1, r1, #1
	add r1, r8
	adds r0, r7, #0
	adds r0, #0x1c
	strh r0, [r1]
	adds r0, #1
	strh r0, [r1, #2]
	adds r3, r1, #0
	adds r3, #0x40
	adds r0, #0x1f
	strh r0, [r3]
	adds r1, #0x42
	adds r0, #1
	strh r0, [r1]
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	b .L080904B2
.L08090494:
	movs r4, #0x1a
	b .L0809049E
.L08090498:
	movs r4, #0x1b
	b .L0809049E
.L0809049C:
	subs r4, #0x41
.L0809049E:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	add r0, sl
	lsls r0, r0, #1
	add r0, r8
	adds r1, r7, r4
	strh r1, [r0]
	adds r0, #0x40
	adds r1, #0x20
	strh r1, [r0]
.L080904B2:
	lsls r2, r5, #1
.L080904B4:
	lsls r0, r6, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r6, r0, #0x10
	movs r0, #1
	add sb, r0
	ldr r1, .L080904EC @ =gUnk_0866354C
	adds r0, r2, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	add r0, sb
.L080904CE:
	ldrb r4, [r0]
	cmp r4, #0
	beq .L080904D6
	b .L08090384
.L080904D6:
	movs r0, #3
	bl EnableBgSync
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080904EC: .4byte gUnk_0866354C

	thumb_func_start func_fe6_080904F0
func_fe6_080904F0: @ 0x080904F0
	adds r1, r0, #0
	adds r1, #0x64
	movs r2, #0
	strh r2, [r1]
	adds r0, #0x66
	strh r2, [r0]
	ldr r1, .L08090504 @ =0x02016A3F
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
.L08090504: .4byte 0x02016A3F

	thumb_func_start func_fe6_08090508
func_fe6_08090508: @ 0x08090508
	push {r4, lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x66
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne .L08090578
	adds r4, r2, #0
	adds r4, #0x64
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	ble .L08090536
	adds r0, r2, #0
	bl Proc_Break
.L08090536:
	ldr r3, .L08090580 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	ldrh r1, [r4]
	adds r0, r3, #0
	adds r0, #0x44
	strb r1, [r0]
	movs r0, #0x10
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x45
	strb r0, [r1]
	adds r1, #1
	movs r0, #0
	strb r0, [r1]
	ldr r0, .L08090584 @ =0x0000FFE0
	ldrh r2, [r3, #0x3c]
	ands r0, r2
	movs r1, #3
	orrs r0, r1
	ldr r1, .L08090588 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3, #0x3c]
.L08090578:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08090580: .4byte gDispIo
.L08090584: .4byte 0x0000FFE0
.L08090588: .4byte 0x0000E0FF

	thumb_func_start func_fe6_0809058C
func_fe6_0809058C: @ 0x0809058C
	push {lr}
	ldr r0, .L0809059C @ =gUnk_0868BB3C
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0809059C: .4byte gUnk_0868BB3C

	thumb_func_start func_fe6_080905A0
func_fe6_080905A0: @ 0x080905A0
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x66
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne .L080905FC
	adds r4, r2, #0
	adds r4, #0x64
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	ble .L080905D4
	adds r0, r2, #0
	bl Proc_Break
	ldr r0, .L08090604 @ =0x02016A3F
	strb r5, [r0]
.L080905D4:
	ldr r3, .L08090608 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	ldrh r2, [r4]
	movs r0, #0x10
	subs r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x44
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x45
	strb r2, [r0]
	adds r0, #1
	strb r5, [r0]
.L080905FC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08090604: .4byte 0x02016A3F
.L08090608: .4byte gDispIo

	thumb_func_start func_fe6_0809060C
func_fe6_0809060C: @ 0x0809060C
	push {lr}
	ldr r0, .L0809061C @ =gUnk_0868BB5C
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0809061C: .4byte gUnk_0868BB5C

	thumb_func_start func_fe6_08090620
func_fe6_08090620: @ 0x08090620
	ldr r1, .L0809062C @ =0x02016A40
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
.L0809062C: .4byte 0x02016A40

	thumb_func_start func_fe6_08090630
func_fe6_08090630: @ 0x08090630
	movs r1, #0
	ldr r0, .L08090640 @ =0x02016A3C
	ldrb r0, [r0]
	cmp r0, #0x31
	bls .L0809063C
	movs r1, #1
.L0809063C:
	adds r0, r1, #0
	bx lr
	.align 2, 0
.L08090640: .4byte 0x02016A3C

	thumb_func_start func_fe6_08090644
func_fe6_08090644: @ 0x08090644
	push {lr}
	ldr r1, .L08090658 @ =0x02016A3F
	movs r0, #0xff
	strb r0, [r1]
	ldr r0, .L0809065C @ =0x02016A3C
	ldrb r0, [r0]
	bl func_fe6_080902F0
	pop {r0}
	bx r0
	.align 2, 0
.L08090658: .4byte 0x02016A3F
.L0809065C: .4byte 0x02016A3C

	thumb_func_start func_fe6_08090660
func_fe6_08090660: @ 0x08090660
	push {lr}
	ldr r1, .L08090670 @ =0x02016A3C
	ldrb r1, [r1]
	bl func_fe6_0808FFE0
	pop {r0}
	bx r0
	.align 2, 0
.L08090670: .4byte 0x02016A3C

	thumb_func_start func_fe6_08090674
func_fe6_08090674: @ 0x08090674
	push {r4, lr}
	adds r0, #0x64
	movs r4, #0
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L08090704 @ =gUnk_0868BA24
	bl InitBgs
	ldr r2, .L08090708 @ =gDispIo
	movs r0, #1
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #4
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x44
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	ldr r0, .L0809070C @ =0x0000FFE0
	ldrh r1, [r2, #0x3c]
	ands r0, r1
	ldr r1, .L08090710 @ =0x0000E0FF
	ands r0, r1
	strh r0, [r2, #0x3c]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r0, .L08090714 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L08090718 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	bl func_fe6_0808FD94
	ldr r0, .L0809071C @ =gUnk_0868BB7C
	movs r1, #3
	bl SpawnProc
	movs r0, #3
	bl EnableBgSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08090704: .4byte gUnk_0868BA24
.L08090708: .4byte gDispIo
.L0809070C: .4byte 0x0000FFE0
.L08090710: .4byte 0x0000E0FF
.L08090714: .4byte gBg0Tm
.L08090718: .4byte gBg1Tm
.L0809071C: .4byte gUnk_0868BB7C

	thumb_func_start func_fe6_08090720
func_fe6_08090720: @ 0x08090720
	push {lr}
	adds r2, r0, #0
	adds r0, #0x64
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	movs r0, #0x96
	lsls r0, r0, #0x11
	cmp r1, r0
	ble .L0809073C
	adds r0, r2, #0
	bl Proc_Break
.L0809073C:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08090740
func_fe6_08090740: @ 0x08090740
	push {lr}
	ldr r1, .L08090760 @ =0x02016A3F
	movs r0, #0
	strb r0, [r1]
	ldr r0, .L08090764 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	movs r0, #1
	bl EnableBgSync
	ldr r0, .L08090768 @ =gUnk_0868BB7C
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
.L08090760: .4byte 0x02016A3F
.L08090764: .4byte gBg0Tm
.L08090768: .4byte gUnk_0868BB7C

	thumb_func_start func_fe6_0809076C
func_fe6_0809076C: @ 0x0809076C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L08090814 @ =gUnk_0868BA24
	bl InitBgs
	adds r4, #0x4e
	movs r2, #0
	movs r0, #0x8c
	lsls r0, r0, #2
	strh r0, [r4]
	ldr r3, .L08090818 @ =gDispIo
	movs r0, #1
	ldrb r1, [r3, #1]
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r3, #1]
	adds r1, r3, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r4, [r1]
	ands r0, r4
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x44
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	ldr r0, .L0809081C @ =0x0000FFE0
	ldrh r1, [r3, #0x3c]
	ands r0, r1
	ldr r1, .L08090820 @ =0x0000E0FF
	ands r0, r1
	strh r0, [r3, #0x3c]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r4, .L08090824 @ =gBg0Tm
	adds r0, r4, #0
	movs r1, #0
	bl TmFill
	ldr r0, .L08090828 @ =gUnk_08345420
	movs r1, #0x40
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r5, .L0809082C @ =gUnk_08344CD0
	movs r0, #0
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	adds r0, r5, #0
	bl Decompress
	movs r1, #0xa3
	lsls r1, r1, #1
	adds r4, r4, r1
	ldr r1, .L08090830 @ =gUnk_0834523C
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r4, #0
	bl TmApplyTsa_thm
	movs r0, #1
	bl EnableBgSync
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08090814: .4byte gUnk_0868BA24
.L08090818: .4byte gDispIo
.L0809081C: .4byte 0x0000FFE0
.L08090820: .4byte 0x0000E0FF
.L08090824: .4byte gBg0Tm
.L08090828: .4byte gUnk_08345420
.L0809082C: .4byte gUnk_08344CD0
.L08090830: .4byte gUnk_0834523C

	thumb_func_start func_fe6_08090834
func_fe6_08090834: @ 0x08090834
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x4e
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0809084E
	adds r0, r2, #0
	bl Proc_Break
.L0809084E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08090854
func_fe6_08090854: @ 0x08090854
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	movs r0, #0
.L0809085C:
	movs r3, #0
	adds r4, r0, #1
	lsls r1, r0, #5
	lsls r0, r0, #6
	adds r2, r0, r6
.L08090866:
	adds r0, r1, r3
	orrs r0, r5
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, #0x1f
	ble .L08090866
	adds r0, r4, #0
	cmp r0, #0x13
	ble .L0809085C
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08090880
func_fe6_08090880: @ 0x08090880
	push {lr}
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r1, .L080908A0 @ =gDispIo
	adds r1, #0x3d
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
.L080908A0: .4byte gDispIo

	thumb_func_start func_fe6_080908A4
func_fe6_080908A4: @ 0x080908A4
	push {r4, r5, r6, lr}
	adds r0, #0x64
	movs r4, #0
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L080909DC @ =gUnk_0868BA24
	bl InitBgs
	ldr r3, .L080909E0 @ =gDispIo
	movs r0, #1
	ldrb r1, [r3, #1]
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r3, #1]
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x44
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x45
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	ldr r0, .L080909E4 @ =0x0000FFE0
	ldrh r2, [r3, #0x3c]
	ands r0, r2
	movs r1, #0x18
	orrs r0, r1
	ldr r1, .L080909E8 @ =0x0000E0FF
	ands r0, r1
	strh r0, [r3, #0x3c]
	adds r1, r3, #0
	adds r1, #0x3d
	movs r0, #0x20
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	movs r0, #0
	movs r1, #4
	movs r2, #4
	bl SetBgOffset
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r6, .L080909EC @ =gBg0Tm
	adds r0, r6, #0
	movs r1, #0
	bl TmFill
	ldr r5, .L080909F0 @ =gBg3Tm
	adds r0, r5, #0
	movs r1, #0
	bl TmFill
	ldr r0, .L080909F4 @ =gUnk_08344CB0
	movs r1, #0xc0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L080909F8 @ =gUnk_08320D98
	movs r1, #0x80
	movs r2, #0x40
	bl ApplyPaletteExt
	ldr r0, .L080909FC @ =gUnk_08344304
	ldr r1, .L08090A00 @ =0x06001000
	bl Decompress
	ldr r4, .L08090A04 @ =gUnk_0831B0A8
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	adds r0, r4, #0
	bl Decompress
	ldr r1, .L08090A08 @ =gUnk_08345440
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r5, #0
	bl TmApplyTsa_thm
	movs r3, #0xc1
	lsls r3, r3, #7
	movs r2, #0
.L0809097C:
	ldr r1, .L08090A0C @ =0x00000107
	adds r0, r2, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	adds r1, r3, r2
	strh r1, [r0]
	ldr r0, .L08090A10 @ =0x00000127
	adds r1, r2, r0
	lsls r1, r1, #1
	adds r1, r1, r6
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, .L08090A14 @ =0x00000147
	adds r1, r2, r0
	lsls r1, r1, #1
	adds r1, r1, r6
	adds r0, r3, #0
	adds r0, #0x40
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, .L08090A18 @ =0x00000167
	adds r1, r2, r0
	lsls r1, r1, #1
	adds r1, r1, r6
	adds r0, r3, #0
	adds r0, #0x60
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, .L08090A1C @ =0x00000187
	adds r1, r2, r0
	lsls r1, r1, #1
	adds r1, r1, r6
	adds r0, r3, #0
	adds r0, #0x80
	adds r0, r0, r2
	strh r0, [r1]
	adds r2, #1
	cmp r2, #0x10
	ble .L0809097C
	movs r0, #9
	bl EnableBgSync
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080909DC: .4byte gUnk_0868BA24
.L080909E0: .4byte gDispIo
.L080909E4: .4byte 0x0000FFE0
.L080909E8: .4byte 0x0000E0FF
.L080909EC: .4byte gBg0Tm
.L080909F0: .4byte gBg3Tm
.L080909F4: .4byte gUnk_08344CB0
.L080909F8: .4byte gUnk_08320D98
.L080909FC: .4byte gUnk_08344304
.L08090A00: .4byte 0x06001000
.L08090A04: .4byte gUnk_0831B0A8
.L08090A08: .4byte gUnk_08345440
.L08090A0C: .4byte 0x00000107
.L08090A10: .4byte 0x00000127
.L08090A14: .4byte 0x00000147
.L08090A18: .4byte 0x00000167
.L08090A1C: .4byte 0x00000187

	thumb_func_start func_fe6_08090A20
func_fe6_08090A20: @ 0x08090A20
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble .L08090A3C
	adds r0, r2, #0
	bl Proc_Break
.L08090A3C:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08090A40
func_fe6_08090A40: @ 0x08090A40
	push {r4, r5, r6, lr}
	adds r0, #0x64
	movs r4, #0
	movs r1, #0
	strh r1, [r0]
	ldr r0, .L08090B54 @ =gUnk_0868BA24
	bl InitBgs
	ldr r2, .L08090B58 @ =gDispIo
	movs r0, #1
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2, #1]
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x44
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	ldr r0, .L08090B5C @ =0x0000FFE0
	ldrh r1, [r2, #0x3c]
	ands r0, r1
	ldr r1, .L08090B60 @ =0x0000E0FF
	ands r0, r1
	strh r0, [r2, #0x3c]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r6, .L08090B64 @ =gBg0Tm
	adds r0, r6, #0
	movs r1, #0
	bl TmFill
	ldr r5, .L08090B68 @ =gBg3Tm
	adds r0, r5, #0
	movs r1, #0
	bl TmFill
	ldr r0, .L08090B6C @ =Pal_MuralBackground
	movs r1, #0x80
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L08090B70 @ =gUnk_08344CB0
	movs r1, #0xc0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L08090B74 @ =gUnk_083449F8
	ldr r1, .L08090B78 @ =0x06001000
	bl Decompress
	ldr r4, .L08090B7C @ =Img_MuralBackground
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r3, #0xc0
	lsls r3, r3, #0x13
	adds r1, r1, r3
	adds r0, r4, #0
	bl Decompress
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r5, #0
	bl func_fe6_08090854
	movs r3, #0xc1
	lsls r3, r3, #7
	movs r2, #0
.L08090AFC:
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r2, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	adds r1, r3, r2
	strh r1, [r0]
	movs r0, #0x96
	lsls r0, r0, #1
	adds r1, r2, r0
	lsls r1, r1, #1
	adds r1, r1, r6
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xa6
	lsls r0, r0, #1
	adds r1, r2, r0
	lsls r1, r1, #1
	adds r1, r1, r6
	adds r0, r3, #0
	adds r0, #0x40
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r2, r0
	lsls r1, r1, #1
	adds r1, r1, r6
	adds r0, r3, #0
	adds r0, #0x60
	adds r0, r0, r2
	strh r0, [r1]
	adds r2, #1
	cmp r2, #5
	ble .L08090AFC
	movs r0, #9
	bl EnableBgSync
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08090B54: .4byte gUnk_0868BA24
.L08090B58: .4byte gDispIo
.L08090B5C: .4byte 0x0000FFE0
.L08090B60: .4byte 0x0000E0FF
.L08090B64: .4byte gBg0Tm
.L08090B68: .4byte gBg3Tm
.L08090B6C: .4byte Pal_MuralBackground
.L08090B70: .4byte gUnk_08344CB0
.L08090B74: .4byte gUnk_083449F8
.L08090B78: .4byte 0x06001000
.L08090B7C: .4byte Img_MuralBackground

	thumb_func_start func_fe6_08090B80
func_fe6_08090B80: @ 0x08090B80
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble .L08090B9C
	adds r0, r2, #0
	bl Proc_Break
.L08090B9C:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08090BA0
func_fe6_08090BA0: @ 0x08090BA0
	ldr r1, .L08090BBC @ =0x02016A3D
	ldrb r0, [r1]
	cmp r0, #0xc
	bhi .L08090BC4
	ldr r0, .L08090BC0 @ =gUnk_0868BCE4
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r1, r1, r0
	ldr r0, [r1]
	cmp r0, #0
	beq .L08090BC4
	movs r0, #1
	b .L08090BC6
	.align 2, 0
.L08090BBC: .4byte 0x02016A3D
.L08090BC0: .4byte gUnk_0868BCE4
.L08090BC4:
	movs r0, #0
.L08090BC6:
	bx lr

	thumb_func_start func_fe6_08090BC8
func_fe6_08090BC8: @ 0x08090BC8
	push {r4, r5, lr}
	movs r5, #0
	adds r0, #0x64
	movs r4, #0
	strh r5, [r0]
	ldr r0, .L08090C48 @ =gUnk_0868BA24
	bl InitBgs
	ldr r2, .L08090C4C @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2, #1]
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x44
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	ldr r0, .L08090C50 @ =0x0000FFE0
	ldrh r1, [r2, #0x3c]
	ands r0, r1
	ldr r1, .L08090C54 @ =0x0000E0FF
	ands r0, r1
	strh r0, [r2, #0x3c]
	ldr r2, .L08090C58 @ =0x0000FFFC
	movs r0, #2
	movs r1, #0
	bl SetBgOffset
	ldr r0, .L08090C5C @ =gBg2Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L08090C60 @ =0x02016A3D
	ldrb r0, [r0]
	cmp r0, #0xa
	beq .L08090C64
	cmp r0, #0xa
	blt .L08090C96
	cmp r0, #0xb
	beq .L08090C74
	cmp r0, #0xc
	beq .L08090C88
	b .L08090C96
	.align 2, 0
.L08090C48: .4byte gUnk_0868BA24
.L08090C4C: .4byte gDispIo
.L08090C50: .4byte 0x0000FFE0
.L08090C54: .4byte 0x0000E0FF
.L08090C58: .4byte 0x0000FFFC
.L08090C5C: .4byte gBg2Tm
.L08090C60: .4byte 0x02016A3D
.L08090C64:
	movs r0, #0x6b
	bl CheckFlag
	movs r1, #0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08090C84
	b .L08090C82
.L08090C74:
	bl GetEndingId
	movs r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne .L08090C84
.L08090C82:
	movs r1, #1
.L08090C84:
	adds r5, r1, #0
	b .L08090C96
.L08090C88:
	bl GetEndingId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r5, r1, #0x1f
.L08090C96:
	lsls r0, r5, #0x18
	adds r5, r0, #0
	cmp r5, #0
	beq .L08090CB8
	ldr r0, .L08090CB0 @ =gUnk_0868BCE4
	ldr r1, .L08090CB4 @ =0x02016A3D
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r0, #8
	adds r1, r1, r0
	ldr r4, [r1]
	b .L08090CC4
	.align 2, 0
.L08090CB0: .4byte gUnk_0868BCE4
.L08090CB4: .4byte 0x02016A3D
.L08090CB8:
	ldr r1, .L08090CE8 @ =gUnk_0868BCE4
	ldr r0, .L08090CEC @ =0x02016A3D
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldr r4, [r0]
.L08090CC4:
	movs r0, #2
	bl GetBgChrOffset
	adds r1, r0, #0
	ldr r3, .L08090CF0 @ =0x06002800
	adds r1, r1, r3
	adds r0, r4, #0
	bl Decompress
	cmp r5, #0
	beq .L08090CF4
	ldr r0, .L08090CE8 @ =gUnk_0868BCE4
	ldr r1, .L08090CEC @ =0x02016A3D
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r0, #0xc
	b .L08090CFE
	.align 2, 0
.L08090CE8: .4byte gUnk_0868BCE4
.L08090CEC: .4byte 0x02016A3D
.L08090CF0: .4byte 0x06002800
.L08090CF4:
	ldr r0, .L08090D24 @ =gUnk_0868BCE4
	ldr r1, .L08090D28 @ =0x02016A3D
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r0, #4
.L08090CFE:
	adds r1, r1, r0
	ldr r0, [r1]
	movs r1, #0xc0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L08090D2C @ =gBg2Tm+0x14E
	ldr r1, .L08090D30 @ =0x00006140
	movs r2, #0xf
	movs r3, #0xa
	bl func_fe6_0808FDE8
	movs r0, #4
	bl EnableBgSync
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08090D24: .4byte gUnk_0868BCE4
.L08090D28: .4byte 0x02016A3D
.L08090D2C: .4byte gBg2Tm+0x14E
.L08090D30: .4byte 0x00006140

	thumb_func_start func_fe6_08090D34
func_fe6_08090D34: @ 0x08090D34
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble .L08090D50
	adds r0, r2, #0
	bl Proc_Break
.L08090D50:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08090D54
func_fe6_08090D54: @ 0x08090D54
	ldr r0, .L08090D60 @ =0x02016A40
	ldrb r0, [r0]
	cmp r0, #1
	bls .L08090D64
	movs r0, #0
	b .L08090D66
	.align 2, 0
.L08090D60: .4byte 0x02016A40
.L08090D64:
	movs r0, #1
.L08090D66:
	bx lr

	thumb_func_start func_fe6_08090D68
func_fe6_08090D68: @ 0x08090D68
	push {lr}
	adds r0, #0x64
	movs r1, #0
	strh r1, [r0]
	bl EndAllMus
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08090D78
func_fe6_08090D78: @ 0x08090D78
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x64
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #7
	bls .L08090D88
	b .L08090F2A
.L08090D88:
	lsls r0, r0, #2
	ldr r1, .L08090D94 @ =.L08090D98
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08090D94: .4byte .L08090D98
.L08090D98: @ jump table
	.4byte .L08090DB8 @ case 0
	.4byte .L08090E84 @ case 1
	.4byte .L08090EC0 @ case 2
	.4byte .L08090ED0 @ case 3
	.4byte .L08090EDC @ case 4
	.4byte .L08090EF2 @ case 5
	.4byte .L08090F1C @ case 6
	.4byte .L08090F24 @ case 7
.L08090DB8:
	ldr r0, .L08090DD0 @ =0x02016A3E
	movs r1, #0
	strb r1, [r0]
	bl func_fe6_08090630
	cmp r0, #1
	bne .L08090DD4
	adds r1, r4, #0
	adds r1, #0x64
	movs r0, #2
	strh r0, [r1]
	b .L08090F2A
	.align 2, 0
.L08090DD0: .4byte 0x02016A3E
.L08090DD4:
	ldr r2, .L08090DFC @ =gUnk_0866354C
	ldr r1, .L08090E00 @ =0x02016A3C
	ldrb r3, [r1]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #1
	bne .L08090E0C
	ldr r0, .L08090E04 @ =0x02016A41
	ldrb r0, [r0]
	cmp r0, #0
	beq .L08090E68
	ldr r0, .L08090E08 @ =gUnk_0868BC44
	adds r1, r4, #0
	bl SpawnProcLocking
	b .L08090E68
	.align 2, 0
.L08090DFC: .4byte gUnk_0866354C
.L08090E00: .4byte 0x02016A3C
.L08090E04: .4byte 0x02016A41
.L08090E08: .4byte gUnk_0868BC44
.L08090E0C:
	cmp r0, #2
	bne .L08090E60
	bl func_fe6_0809164C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3f
	bhi .L08090E38
	ldr r0, .L08090E30 @ =0x02016A41
	ldrb r0, [r0]
	cmp r0, #0
	beq .L08090E38
	ldr r0, .L08090E34 @ =gUnk_0868BE74
	adds r1, r4, #0
	bl SpawnProcLocking
	b .L08090E4A
	.align 2, 0
.L08090E30: .4byte 0x02016A41
.L08090E34: .4byte gUnk_0868BE74
.L08090E38:
	bl func_fe6_08090BA0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08090E4A
	ldr r0, .L08090E58 @ =gUnk_0868BDB4
	adds r1, r4, #0
	bl SpawnProcLocking
.L08090E4A:
	ldr r1, .L08090E5C @ =0x02016A3E
	movs r0, #2
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	b .L08090E68
	.align 2, 0
.L08090E58: .4byte gUnk_0868BDB4
.L08090E5C: .4byte 0x02016A3E
.L08090E60:
	ldr r0, .L08090E7C @ =gUnk_0868BB9C
	adds r1, r4, #0
	bl SpawnProcLocking
.L08090E68:
	ldr r1, .L08090E80 @ =0x02016A3E
	movs r0, #1
	ldrb r3, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x64
	movs r0, #1
	strh r0, [r1]
	b .L08090F2A
	.align 2, 0
.L08090E7C: .4byte gUnk_0868BB9C
.L08090E80: .4byte 0x02016A3E
.L08090E84:
	ldr r2, .L08090EB4 @ =0x02016A3E
	movs r0, #1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq .L08090E98
	ldr r1, .L08090EB8 @ =0x02016A3C
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
.L08090E98:
	movs r0, #2
	ldrb r2, [r2]
	ands r0, r2
	cmp r0, #0
	beq .L08090EAA
	ldr r1, .L08090EBC @ =0x02016A3D
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
.L08090EAA:
	adds r1, r4, #0
	adds r1, #0x64
	movs r0, #0
	strh r0, [r1]
	b .L08090F2A
	.align 2, 0
.L08090EB4: .4byte 0x02016A3E
.L08090EB8: .4byte 0x02016A3C
.L08090EBC: .4byte 0x02016A3D
.L08090EC0:
	ldr r0, .L08090ECC @ =gUnk_0868BBEC
.L08090EC2:
	adds r1, r4, #0
	bl SpawnProcLocking
	b .L08090F10
	.align 2, 0
.L08090ECC: .4byte gUnk_0868BBEC
.L08090ED0:
	bl func_fe6_0806DEB4
	ldr r0, .L08090ED8 @ =gUnk_0868B8E4
	b .L08090EC2
	.align 2, 0
.L08090ED8: .4byte gUnk_0868B8E4
.L08090EDC:
	movs r0, #0x36
	movs r1, #0
	bl StartBgm
	bl func_fe6_08091588
	adds r1, r4, #0
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L08090EF2:
	movs r0, #0
	bl func_fe6_080916AC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3f
	bhi .L08090F10
	ldr r0, .L08090F0C @ =gUnk_0868BF3C
	adds r1, r4, #0
	bl SpawnProcLocking
	b .L08090F2A
	.align 2, 0
.L08090F0C: .4byte gUnk_0868BF3C
.L08090F10:
	adds r1, r4, #0
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b .L08090F2A
.L08090F1C:
	ldr r0, .L08090F30 @ =gUnk_0868BC8C
	adds r1, r4, #0
	bl SpawnProcLocking
.L08090F24:
	adds r0, r4, #0
	bl Proc_Break
.L08090F2A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08090F30: .4byte gUnk_0868BC8C

	thumb_func_start func_fe6_08090F34
func_fe6_08090F34: @ 0x08090F34
	push {lr}
	adds r1, r0, #0
	ldr r0, .L08090F44 @ =gUnk_0868BDF4
	bl SpawnProcLocking
	pop {r0}
	bx r0
	.align 2, 0
.L08090F44: .4byte gUnk_0868BDF4

	thumb_func_start func_fe6_08090F48
func_fe6_08090F48: @ 0x08090F48
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08090F68 @ =gUnk_0866354C
	ldr r3, .L08090F6C @ =0x02016A3C
	ldrb r2, [r3]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	subs r0, #1
	cmp r0, #1
	bhi .L08090F70
	adds r0, r2, #1
	strb r0, [r3]
	b .L08090FFC
	.align 2, 0
.L08090F68: .4byte gUnk_0866354C
.L08090F6C: .4byte 0x02016A3C
.L08090F70:
	adds r0, r5, #0
	adds r0, #0x64
	movs r4, #0
	ldrsh r1, [r0, r4]
	adds r4, r0, #0
	cmp r1, #0xb4
	beq .L08090FEC
	cmp r1, #0xb4
	bgt .L08090F88
	cmp r1, #0x3c
	beq .L08090F98
	b .L08090FEC
.L08090F88:
	movs r0, #0xd2
	lsls r0, r0, #1
	cmp r1, r0
	beq .L08090FA4
	adds r0, #0x78
	cmp r1, r0
	beq .L08090FAA
	b .L08090FEC
.L08090F98:
	adds r0, r2, #0
	bl func_fe6_080902F0
	bl func_fe6_0809058C
	b .L08090FEC
.L08090FA4:
	bl func_fe6_0809060C
	b .L08090FEC
.L08090FAA:
	movs r0, #0
	strh r0, [r4]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldr r0, .L08090FE0 @ =0x02016A40
	ldrb r0, [r0]
	cmp r0, #0
	beq .L08090FF2
	ldr r0, .L08090FE4 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L08090FE8 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	movs r0, #3
	bl EnableBgSync
	adds r0, r5, #0
	bl Proc_Break
	bl func_fe6_08090620
	b .L08090FF2
	.align 2, 0
.L08090FE0: .4byte 0x02016A40
.L08090FE4: .4byte gBg0Tm
.L08090FE8: .4byte gBg1Tm
.L08090FEC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
.L08090FF2:
	ldr r0, .L08091004 @ =0x02016A3C
	ldrb r1, [r0]
	adds r0, r5, #0
	bl func_fe6_0808FFE0
.L08090FFC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08091004: .4byte 0x02016A3C

	thumb_func_start func_fe6_08091008
func_fe6_08091008: @ 0x08091008
	push {lr}
	ldr r0, .L08091018 @ =gUnk_0868BE2C
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L08091018: .4byte gUnk_0868BE2C

	thumb_func_start func_fe6_0809101C
func_fe6_0809101C: @ 0x0809101C
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #1
	bl GetUnitByPid
	adds r5, r0, #0
	adds r1, r4, #0
	bl GetUnitSupportNumByPid
	adds r1, r0, #0
	adds r0, r5, #0
	bl GetUnitSupportLevel
	cmp r0, #2
	bgt .L08091042
	movs r0, #0
	b .L08091044
.L08091042:
	movs r0, #1
.L08091044:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0809104C
func_fe6_0809104C: @ 0x0809104C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r4, #1
	ldr r3, .L080910B8 @ =0x02016B94
	ldr r2, .L080910BC @ =gPal
.L0809105A:
	lsls r1, r4, #1
	adds r1, r1, r3
	adds r0, r4, #0
	adds r0, #0x20
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq .L080910C8
	movs r4, #0
	ldr r7, .L080910C0 @ =gPal+0x40
	ldr r0, .L080910B8 @ =0x02016B94
	mov r8, r0
	ldr r5, .L080910C4 @ =0x02016C94
	mov sb, r5
	mov r6, r8
.L0809107C:
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #8
	bl CpuFastSet
	mov r0, r8
	adds r1, r4, #0
	movs r2, #1
	adds r3, r4, #0
	bl EfxPalBlackInOut
	adds r0, r7, #0
	adds r0, #0x20
	adds r1, r5, #0
	movs r2, #8
	bl CpuFastSet
	mov r0, sb
	adds r1, r4, #0
	movs r2, #1
	adds r3, r4, #0
	bl EfxPalBlackInOut
	adds r5, #0x20
	adds r6, #0x20
	adds r4, #1
	cmp r4, #7
	ble .L0809107C
	b .L080910CE
	.align 2, 0
.L080910B8: .4byte 0x02016B94
.L080910BC: .4byte gPal
.L080910C0: .4byte gPal+0x40
.L080910C4: .4byte 0x02016C94
.L080910C8:
	adds r4, #1
	cmp r4, #0xf
	ble .L0809105A
.L080910CE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080910DC
func_fe6_080910DC: @ 0x080910DC
	push {r4, r5, lr}
	movs r2, #0
	ldr r0, .L080910F4 @ =0x04000006
	ldrh r0, [r0]
	cmp r0, #0x18
	beq .L080910FE
	cmp r0, #0x18
	bgt .L080910F8
	cmp r0, #0
	beq .L0809110C
	b .L08091110
	.align 2, 0
.L080910F4: .4byte 0x04000006
.L080910F8:
	cmp r0, #0x30
	beq .L0809110C
	b .L08091110
.L080910FE:
	ldr r1, .L08091108 @ =0x04000012
	movs r0, #4
	strh r0, [r1]
	b .L08091110
	.align 2, 0
.L08091108: .4byte 0x04000012
.L0809110C:
	ldr r0, .L08091134 @ =0x04000012
	strh r2, [r0]
.L08091110:
	ldr r0, .L08091138 @ =0x04000006
	ldrh r0, [r0]
	cmp r0, #0x3c
	beq .L08091186
	cmp r0, #0x3c
	bgt .L08091156
	cmp r0, #0x34
	beq .L0809118E
	cmp r0, #0x34
	bgt .L08091142
	cmp r0, #0x30
	beq .L08091192
	cmp r0, #0x30
	bgt .L0809113C
	cmp r0, #0
	beq .L08091194
	b .L080911BA
	.align 2, 0
.L08091134: .4byte 0x04000012
.L08091138: .4byte 0x04000006
.L0809113C:
	cmp r0, #0x32
	beq .L08091190
	b .L080911BA
.L08091142:
	cmp r0, #0x38
	beq .L0809118A
	cmp r0, #0x38
	bgt .L08091150
	cmp r0, #0x36
	beq .L0809118C
	b .L080911BA
.L08091150:
	cmp r0, #0x3a
	beq .L08091188
	b .L080911BA
.L08091156:
	cmp r0, #0x96
	beq .L0809118E
	cmp r0, #0x96
	bgt .L08091172
	cmp r0, #0x92
	beq .L0809118A
	cmp r0, #0x92
	bgt .L0809116C
	cmp r0, #0x90
	beq .L08091188
	b .L080911BA
.L0809116C:
	cmp r0, #0x94
	beq .L0809118C
	b .L080911BA
.L08091172:
	cmp r0, #0x9a
	beq .L08091192
	cmp r0, #0x9a
	bgt .L08091180
	cmp r0, #0x98
	beq .L08091190
	b .L080911BA
.L08091180:
	cmp r0, #0x9c
	beq .L08091194
	b .L080911BA
.L08091186:
	adds r2, #1
.L08091188:
	adds r2, #1
.L0809118A:
	adds r2, #1
.L0809118C:
	adds r2, #1
.L0809118E:
	adds r2, #1
.L08091190:
	adds r2, #1
.L08091192:
	adds r2, #1
.L08091194:
	lsls r0, r2, #5
	ldr r2, .L080911C0 @ =0x02016B94
	ldr r1, .L080911C4 @ =0x02016C94
	adds r3, r0, r1
	ldr r5, .L080911C8 @ =0x05000060
	adds r1, r0, r2
	ldr r4, .L080911CC @ =0x05000040
	movs r2, #0xf
.L080911A4:
	ldrh r0, [r1]
	strh r0, [r4]
	ldrh r0, [r3]
	strh r0, [r5]
	adds r3, #2
	adds r5, #2
	adds r1, #2
	adds r4, #2
	subs r2, #1
	cmp r2, #0
	bge .L080911A4
.L080911BA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080911C0: .4byte 0x02016B94
.L080911C4: .4byte 0x02016C94
.L080911C8: .4byte 0x05000060
.L080911CC: .4byte 0x05000040

	thumb_func_start func_fe6_080911D0
func_fe6_080911D0: @ 0x080911D0
	push {r4, r5, lr}
	movs r3, #0
	ldr r4, .L08091210 @ =0x04000006
	ldrh r0, [r4]
	cmp r0, #0
	bne .L080911E8
	ldr r2, .L08091214 @ =0x04000010
	ldr r0, .L08091218 @ =0x02016B90
	ldrh r1, [r0]
	strh r1, [r2]
	ldr r0, .L0809121C @ =0x04000014
	strh r1, [r0]
.L080911E8:
	ldrh r0, [r4]
	cmp r0, #0x50
	bne .L080911FA
	ldr r2, .L08091214 @ =0x04000010
	ldr r0, .L08091218 @ =0x02016B90
	ldrh r1, [r0, #2]
	strh r1, [r2]
	ldr r0, .L0809121C @ =0x04000014
	strh r1, [r0]
.L080911FA:
	ldrh r0, [r4]
	cmp r0, #0x2a
	beq .L0809124C
	cmp r0, #0x2a
	bgt .L08091220
	cmp r0, #0
	beq .L08091234
	cmp r0, #0x18
	beq .L08091240
	b .L08091252
	.align 2, 0
.L08091210: .4byte 0x04000006
.L08091214: .4byte 0x04000010
.L08091218: .4byte 0x02016B90
.L0809121C: .4byte 0x04000014
.L08091220:
	cmp r0, #0x68
	beq .L08091240
	cmp r0, #0x68
	bgt .L0809122E
	cmp r0, #0x50
	beq .L08091234
	b .L08091252
.L0809122E:
	cmp r0, #0x7a
	beq .L0809124C
	b .L08091252
.L08091234:
	ldr r1, .L0809123C @ =0x04000012
	movs r0, #0
	b .L08091250
	.align 2, 0
.L0809123C: .4byte 0x04000012
.L08091240:
	ldr r1, .L08091248 @ =0x04000012
	movs r0, #4
	b .L08091250
	.align 2, 0
.L08091248: .4byte 0x04000012
.L0809124C:
	ldr r1, .L08091268 @ =0x04000012
	movs r0, #5
.L08091250:
	strh r0, [r1]
.L08091252:
	ldr r0, .L0809126C @ =0x04000006
	ldrh r0, [r0]
	subs r0, #9
	cmp r0, #0x86
	bls .L0809125E
	b .L080914C4
.L0809125E:
	lsls r0, r0, #2
	ldr r1, .L08091270 @ =.L08091274
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08091268: .4byte 0x04000012
.L0809126C: .4byte 0x04000006
.L08091270: .4byte .L08091274
.L08091274: @ jump table
	.4byte .L0809149E @ case 0
	.4byte .L080914C4 @ case 1
	.4byte .L080914C4 @ case 2
	.4byte .L080914C4 @ case 3
	.4byte .L080914C4 @ case 4
	.4byte .L080914C4 @ case 5
	.4byte .L080914C4 @ case 6
	.4byte .L080914C4 @ case 7
	.4byte .L080914C4 @ case 8
	.4byte .L0809149C @ case 9
	.4byte .L080914C4 @ case 10
	.4byte .L080914C4 @ case 11
	.4byte .L080914C4 @ case 12
	.4byte .L080914C4 @ case 13
	.4byte .L080914C4 @ case 14
	.4byte .L080914C4 @ case 15
	.4byte .L080914C4 @ case 16
	.4byte .L080914C4 @ case 17
	.4byte .L0809149A @ case 18
	.4byte .L080914C4 @ case 19
	.4byte .L080914C4 @ case 20
	.4byte .L080914C4 @ case 21
	.4byte .L080914C4 @ case 22
	.4byte .L080914C4 @ case 23
	.4byte .L080914C4 @ case 24
	.4byte .L080914C4 @ case 25
	.4byte .L080914C4 @ case 26
	.4byte .L08091498 @ case 27
	.4byte .L080914C4 @ case 28
	.4byte .L080914C4 @ case 29
	.4byte .L080914C4 @ case 30
	.4byte .L080914C4 @ case 31
	.4byte .L080914C4 @ case 32
	.4byte .L080914C4 @ case 33
	.4byte .L080914C4 @ case 34
	.4byte .L080914C4 @ case 35
	.4byte .L08091496 @ case 36
	.4byte .L080914C4 @ case 37
	.4byte .L080914C4 @ case 38
	.4byte .L080914C4 @ case 39
	.4byte .L080914C4 @ case 40
	.4byte .L080914C4 @ case 41
	.4byte .L080914C4 @ case 42
	.4byte .L080914C4 @ case 43
	.4byte .L080914C4 @ case 44
	.4byte .L08091494 @ case 45
	.4byte .L080914C4 @ case 46
	.4byte .L080914C4 @ case 47
	.4byte .L080914C4 @ case 48
	.4byte .L080914C4 @ case 49
	.4byte .L080914C4 @ case 50
	.4byte .L080914C4 @ case 51
	.4byte .L080914C4 @ case 52
	.4byte .L080914C4 @ case 53
	.4byte .L08091492 @ case 54
	.4byte .L080914C4 @ case 55
	.4byte .L080914C4 @ case 56
	.4byte .L080914C4 @ case 57
	.4byte .L080914C4 @ case 58
	.4byte .L080914C4 @ case 59
	.4byte .L080914C4 @ case 60
	.4byte .L080914C4 @ case 61
	.4byte .L080914C4 @ case 62
	.4byte .L08091490 @ case 63
	.4byte .L080914C4 @ case 64
	.4byte .L080914C4 @ case 65
	.4byte .L080914C4 @ case 66
	.4byte .L080914C4 @ case 67
	.4byte .L080914C4 @ case 68
	.4byte .L080914C4 @ case 69
	.4byte .L080914C4 @ case 70
	.4byte .L080914C4 @ case 71
	.4byte .L080914C4 @ case 72
	.4byte .L080914C4 @ case 73
	.4byte .L080914C4 @ case 74
	.4byte .L080914C4 @ case 75
	.4byte .L080914C4 @ case 76
	.4byte .L080914C4 @ case 77
	.4byte .L080914C4 @ case 78
	.4byte .L080914C4 @ case 79
	.4byte .L08091492 @ case 80
	.4byte .L080914C4 @ case 81
	.4byte .L080914C4 @ case 82
	.4byte .L080914C4 @ case 83
	.4byte .L080914C4 @ case 84
	.4byte .L080914C4 @ case 85
	.4byte .L080914C4 @ case 86
	.4byte .L080914C4 @ case 87
	.4byte .L080914C4 @ case 88
	.4byte .L08091494 @ case 89
	.4byte .L080914C4 @ case 90
	.4byte .L080914C4 @ case 91
	.4byte .L080914C4 @ case 92
	.4byte .L080914C4 @ case 93
	.4byte .L080914C4 @ case 94
	.4byte .L080914C4 @ case 95
	.4byte .L080914C4 @ case 96
	.4byte .L080914C4 @ case 97
	.4byte .L08091496 @ case 98
	.4byte .L080914C4 @ case 99
	.4byte .L080914C4 @ case 100
	.4byte .L080914C4 @ case 101
	.4byte .L080914C4 @ case 102
	.4byte .L080914C4 @ case 103
	.4byte .L080914C4 @ case 104
	.4byte .L080914C4 @ case 105
	.4byte .L080914C4 @ case 106
	.4byte .L08091498 @ case 107
	.4byte .L080914C4 @ case 108
	.4byte .L080914C4 @ case 109
	.4byte .L080914C4 @ case 110
	.4byte .L080914C4 @ case 111
	.4byte .L080914C4 @ case 112
	.4byte .L080914C4 @ case 113
	.4byte .L080914C4 @ case 114
	.4byte .L080914C4 @ case 115
	.4byte .L0809149A @ case 116
	.4byte .L080914C4 @ case 117
	.4byte .L080914C4 @ case 118
	.4byte .L080914C4 @ case 119
	.4byte .L080914C4 @ case 120
	.4byte .L080914C4 @ case 121
	.4byte .L080914C4 @ case 122
	.4byte .L080914C4 @ case 123
	.4byte .L080914C4 @ case 124
	.4byte .L0809149C @ case 125
	.4byte .L080914C4 @ case 126
	.4byte .L080914C4 @ case 127
	.4byte .L080914C4 @ case 128
	.4byte .L080914C4 @ case 129
	.4byte .L080914C4 @ case 130
	.4byte .L080914C4 @ case 131
	.4byte .L080914C4 @ case 132
	.4byte .L080914C4 @ case 133
	.4byte .L0809149E @ case 134
.L08091490:
	adds r3, #1
.L08091492:
	adds r3, #1
.L08091494:
	adds r3, #1
.L08091496:
	adds r3, #1
.L08091498:
	adds r3, #1
.L0809149A:
	adds r3, #1
.L0809149C:
	adds r3, #1
.L0809149E:
	lsls r0, r3, #5
	ldr r2, .L080914CC @ =0x02016B94
	ldr r1, .L080914D0 @ =0x02016C94
	adds r3, r0, r1
	ldr r5, .L080914D4 @ =0x05000060
	adds r1, r0, r2
	ldr r4, .L080914D8 @ =0x05000040
	movs r2, #0xf
.L080914AE:
	ldrh r0, [r1]
	strh r0, [r4]
	ldrh r0, [r3]
	strh r0, [r5]
	adds r3, #2
	adds r5, #2
	adds r1, #2
	adds r4, #2
	subs r2, #1
	cmp r2, #0
	bge .L080914AE
.L080914C4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080914CC: .4byte 0x02016B94
.L080914D0: .4byte 0x02016C94
.L080914D4: .4byte 0x05000060
.L080914D8: .4byte 0x05000040

	thumb_func_start func_fe6_080914DC
func_fe6_080914DC: @ 0x080914DC
	push {r4, r5, r6, lr}
	movs r5, #0
	movs r6, #0
	movs r4, #1
.L080914E4:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L08091520
	ldr r0, [r1]
	cmp r0, #0
	beq .L08091520
	movs r0, #8
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L08091514
	cmp r5, #0xd
	bgt .L08091520
	ldr r0, .L08091510 @ =gUnk_0203DCA7
	adds r0, r5, r0
	strb r4, [r0]
	adds r5, #1
	b .L08091520
	.align 2, 0
.L08091510: .4byte gUnk_0203DCA7
.L08091514:
	cmp r6, #0x35
	bgt .L08091520
	ldr r0, .L08091544 @ =0x0203DC70
	adds r0, r6, r0
	strb r4, [r0]
	adds r6, #1
.L08091520:
	adds r4, #1
	cmp r4, #0x3f
	ble .L080914E4
	ldr r0, .L08091548 @ =gUnk_0203DCA7
	adds r0, r5, r0
	movs r2, #0xff
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	ldr r0, .L08091544 @ =0x0203DC70
	adds r0, r6, r0
	ldrb r1, [r0]
	orrs r2, r1
	strb r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08091544: .4byte 0x0203DC70
.L08091548: .4byte gUnk_0203DCA7

	thumb_func_start func_fe6_0809154C
func_fe6_0809154C: @ 0x0809154C
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #1
.L08091552:
	adds r0, r4, #0
	bl GetUnit
	cmp r0, #0
	beq .L0809156E
	ldr r0, [r0]
	cmp r0, #0
	beq .L0809156E
	cmp r5, #0x35
	bgt .L0809156E
	ldr r0, .L08091584 @ =0x0203DC70
	adds r0, r5, r0
	strb r4, [r0]
	adds r5, #1
.L0809156E:
	adds r4, #1
	cmp r4, #0x3f
	ble .L08091552
	ldr r0, .L08091584 @ =0x0203DC70
	adds r0, r5, r0
	movs r1, #0xff
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08091584: .4byte 0x0203DC70

	thumb_func_start func_fe6_08091588
func_fe6_08091588: @ 0x08091588
	ldr r0, .L08091594 @ =0x02016B88
	movs r1, #1
	strb r1, [r0]
	ldr r0, .L08091598 @ =0x02016B89
	strb r1, [r0]
	bx lr
	.align 2, 0
.L08091594: .4byte 0x02016B88
.L08091598: .4byte 0x02016B89

	thumb_func_start func_fe6_0809159C
func_fe6_0809159C: @ 0x0809159C
	push {lr}
	sub sp, #0x18
	ldr r1, .L08091624 @ =gUnk_08346574
	mov r0, sp
	movs r2, #0x18
	bl memcpy
	mov r0, sp
	bl InitBgs
	ldr r2, .L08091628 @ =gDispIo
	movs r0, #1
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r1, #8
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r0, .L0809162C @ =0x0000FFE0
	ldrh r1, [r2, #0x3c]
	ands r0, r1
	ldr r1, .L08091630 @ =0x0000E0FF
	ands r0, r1
	strh r0, [r2, #0x3c]
	bl InitFaces
	bl ResetText
	ldr r0, .L08091634 @ =gUnk_08320D98
	movs r1, #0x40
	movs r2, #0x40
	bl ApplyPaletteExt
	ldr r0, .L08091638 @ =gUnk_0831B0A8
	ldr r1, .L0809163C @ =0x06008000
	bl Decompress
	ldr r0, .L08091640 @ =gUnk_08346184
	movs r1, #0x80
	movs r2, #0x40
	bl ApplyPaletteExt
	ldr r0, .L08091644 @ =gUnk_08345934
	ldr r1, .L08091648 @ =0x06006000
	bl Decompress
	add sp, #0x18
	pop {r0}
	bx r0
	.align 2, 0
.L08091624: .4byte gUnk_08346574
.L08091628: .4byte gDispIo
.L0809162C: .4byte 0x0000FFE0
.L08091630: .4byte 0x0000E0FF
.L08091634: .4byte gUnk_08320D98
.L08091638: .4byte gUnk_0831B0A8
.L0809163C: .4byte 0x06008000
.L08091640: .4byte gUnk_08346184
.L08091644: .4byte gUnk_08345934
.L08091648: .4byte 0x06006000

	thumb_func_start func_fe6_0809164C
func_fe6_0809164C: @ 0x0809164C
	push {r4, r5, lr}
	ldr r0, .L080916A4 @ =0x02016B88
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0x3f
	bgt .L08091698
	movs r5, #1
	rsbs r5, r5, #0
.L0809165C:
	adds r0, r4, #0
	bl GetUnit
	cmp r0, #0
	beq .L08091692
	ldr r0, [r0]
	cmp r0, #0
	beq .L08091692
	ldrb r0, [r0, #4]
	cmp r0, #0x42
	beq .L08091692
	ldr r1, .L080916A8 @ =gUnk_0203DCA7
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r5
	beq .L08091692
	movs r2, #1
	rsbs r2, r2, #0
.L08091680:
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r4
	beq .L08091698
	adds r1, #1
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r2
	bne .L08091680
.L08091692:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0809165C
.L08091698:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L080916A4: .4byte 0x02016B88
.L080916A8: .4byte gUnk_0203DCA7

	thumb_func_start func_fe6_080916AC
func_fe6_080916AC: @ 0x080916AC
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080916BC
	ldr r0, .L080916B8 @ =0x02016B88
	b .L080916BE
	.align 2, 0
.L080916B8: .4byte 0x02016B88
.L080916BC:
	ldr r0, .L08091724 @ =0x02016B89
.L080916BE:
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r4, r0, #0
	cmp r4, #0x3f
	bgt .L08091718
	movs r6, #1
	rsbs r6, r6, #0
.L080916CE:
	adds r0, r4, #0
	bl GetUnit
	cmp r0, #0
	beq .L08091712
	ldr r0, [r0]
	cmp r0, #0
	beq .L08091712
	ldrb r0, [r0, #4]
	cmp r0, #0x42
	beq .L08091712
	movs r2, #0
	ldr r0, .L08091728 @ =0x0203DC70
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r3, r0, #0
	cmp r1, r6
	beq .L08091712
	adds r5, r3, #0
	movs r1, #1
	rsbs r1, r1, #0
.L080916F8:
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r4
	beq .L08091718
	adds r2, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	bne .L080916F8
.L08091712:
	adds r4, #1
	cmp r4, #0x3f
	ble .L080916CE
.L08091718:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L08091724: .4byte 0x02016B89
.L08091728: .4byte 0x0203DC70

	thumb_func_start func_fe6_0809172C
func_fe6_0809172C: @ 0x0809172C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	ldr r0, .L08091808 @ =0x02016B88
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	bl GetUnit
	str r0, [sp, #4]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	mov r8, r0
	bl GetPidStats
	mov sl, r0
	ldr r0, .L0809180C @ =ProcScr_Unk_08677FD0
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	movs r5, #0
	movs r7, #0xe0
	lsls r7, r7, #1
.L08091766:
	lsls r0, r5, #3
	ldr r1, .L08091810 @ =0x02016B48
	mov sb, r1
	adds r4, r0, r1
	movs r1, #0x1e
	cmp r5, #1
	bgt .L08091776
	movs r1, #0x14
.L08091776:
	adds r0, r4, #0
	bl InitText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	ldr r1, .L08091814 @ =gBg0Tm+0x2
	adds r1, r7, r1
	adds r0, r4, #0
	bl PutText
	lsls r1, r5, #2
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r0, r1
	str r4, [r0]
	adds r7, #0x80
	adds r5, #1
	cmp r5, #5
	ble .L08091766
	movs r0, #4
	ldr r2, [sp, #4]
	ldrh r2, [r2, #0xc]
	ands r0, r2
	cmp r0, #0
	beq .L08091818
	mov r1, sl
	ldrb r1, [r1, #3]
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x1a
	bl GetChapterInfo
	adds r0, #0x3e
	ldrb r1, [r0]
	mov r0, sb
	movs r2, #0
	bl func_fe6_0808E7CC
	adds r1, r0, #0
	ldr r2, [sp]
	str r1, [r2, #0x54]
	adds r1, #3
	mov r0, sb
	bl Text_SetCursor
	mov r1, sl
	ldrb r1, [r1, #3]
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x1a
	bl GetChapterInfo
	ldrh r0, [r0, #0x38]
	bl DecodeMsg
	str r0, [r6, #0x2c]
	mov r2, sl
	ldrb r2, [r2, #3]
	lsls r0, r2, #0x1a
	lsrs r0, r0, #0x1a
	bl GetChapterInfo
	ldrh r0, [r0, #0x38]
	bl DecodeMsg
	bl GetStringTextLen
	ldr r2, [sp]
	ldr r1, [r2, #0x54]
	adds r1, #6
	adds r1, r1, r0
	str r1, [r2, #0x54]
	b .L08091848
	.align 2, 0
.L08091808: .4byte 0x02016B88
.L0809180C: .4byte ProcScr_Unk_08677FD0
.L08091810: .4byte 0x02016B48
.L08091814: .4byte gBg0Tm+0x2
.L08091818:
	mov r0, r8
	bl func_fe6_0809101C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08091838
	ldr r0, .L08091834 @ =gUnk_0868BFCC
	mov r2, r8
	lsls r1, r2, #3
	adds r1, r1, r0
	ldrh r0, [r1, #2]
	bl DecodeMsg
	b .L08091846
	.align 2, 0
.L08091834: .4byte gUnk_0868BFCC
.L08091838:
	ldr r0, .L0809187C @ =gUnk_0868BFCC
	mov r2, r8
	lsls r1, r2, #3
	adds r1, r1, r0
	ldrh r0, [r1]
	bl DecodeMsg
.L08091846:
	str r0, [r6, #0x2c]
.L08091848:
	adds r0, r6, #0
	adds r0, #0x5c
	movs r2, #0
	strh r2, [r0]
	str r2, [r6, #0x30]
	adds r1, r6, #0
	adds r1, #0x60
	movs r0, #4
	strh r0, [r1]
	adds r1, #2
	movs r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x5e
	strh r2, [r0]
	movs r0, #1
	bl EnableBgSync
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0809187C: .4byte gUnk_0868BFCC

	thumb_func_start func_fe6_08091880
func_fe6_08091880: @ 0x08091880
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, .L08091908 @ =0x02016B88
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	bl GetUnit
	movs r1, #4
	ldrh r0, [r0, #0xc]
	ands r1, r0
	cmp r1, #0
	beq .L080918FC
	ldr r4, .L0809190C @ =ProcScr_Unk_08677FD0
	adds r0, r4, #0
	bl FindProc
	cmp r0, #0
	bne .L08091902
	adds r0, r4, #0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	ldr r0, .L08091910 @ =0x02016B48
	movs r3, #5
	adds r2, r0, #0
	adds r2, #0x28
	adds r1, r5, #0
	adds r1, #0x48
.L080918BE:
	str r2, [r1]
	subs r2, #8
	subs r1, #4
	subs r3, #1
	cmp r3, #0
	bge .L080918BE
	movs r4, #0
	ldr r1, [r6, #0x54]
	bl Text_SetCursor
	ldr r0, .L08091914 @ =0x00000A6E
	bl DecodeMsg
	str r0, [r5, #0x2c]
	adds r0, r5, #0
	adds r0, #0x5c
	strh r4, [r0]
	str r4, [r5, #0x30]
	adds r1, r5, #0
	adds r1, #0x60
	movs r0, #4
	strh r0, [r1]
	adds r1, #2
	movs r0, #1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x5e
	strh r4, [r0]
	movs r0, #1
	bl EnableBgSync
.L080918FC:
	adds r0, r6, #0
	bl Proc_Break
.L08091902:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08091908: .4byte 0x02016B88
.L0809190C: .4byte ProcScr_Unk_08677FD0
.L08091910: .4byte 0x02016B48
.L08091914: .4byte 0x00000A6E

	thumb_func_start func_fe6_08091918
func_fe6_08091918: @ 0x08091918
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0809193C @ =0x02016B88
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	bl GetUnit
	movs r1, #4
	ldrh r0, [r0, #0xc]
	ands r1, r0
	cmp r1, #0
	beq .L08091940
	movs r0, #0x96
	lsls r0, r0, #1
	b .L08091942
	.align 2, 0
.L0809193C: .4byte 0x02016B88
.L08091940:
	ldr r0, .L08091954 @ =0x00000352
.L08091942:
	str r0, [r4, #0x30]
	ldr r0, .L08091958 @ =gUnk_0868BE4C
	movs r1, #3
	bl SpawnProc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08091954: .4byte 0x00000352
.L08091958: .4byte gUnk_0868BE4C

	thumb_func_start func_fe6_0809195C
func_fe6_0809195C: @ 0x0809195C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	mov r8, r0
	bl func_fe6_0809164C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, .L080919E8 @ =0x02016B88
	adds r1, r0, #1
	strb r1, [r2]
	bl GetUnit
	adds r6, r0, #0
	bl GetUnitFid
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl ResetText
	ldr r0, .L080919EC @ =gBg3Tm
	ldr r1, .L080919F0 @ =gUnk_08345440
	movs r2, #0x80
	lsls r2, r2, #6
	bl TmApplyTsa_thm
	movs r5, #0
	str r5, [sp, #4]
	ldr r1, .L080919F4 @ =0x0600D800
	ldr r2, .L080919F8 @ =0x01000800
	add r0, sp, #4
	bl CpuFastSet
	movs r0, #0x42
	str r0, [sp]
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0xbe
	movs r3, #2
	bl StartFace
	movs r0, #0
	movs r1, #0
	adds r2, r6, #0
	movs r3, #0
	bl func_fe6_080920B4
	mov r0, r8
	str r5, [r0, #0x2c]
	ldr r0, .L080919FC @ =0x02016B44
	strb r5, [r0]
	ldr r0, .L08091A00 @ =gUnk_0868BFAC
	movs r1, #0
	bl SpawnProc
	ldr r0, .L08091A04 @ =func_fe6_080910DC
	bl SetOnHBlankA
	movs r0, #3
	bl EnableBgSync
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080919E8: .4byte 0x02016B88
.L080919EC: .4byte gBg3Tm
.L080919F0: .4byte gUnk_08345440
.L080919F4: .4byte 0x0600D800
.L080919F8: .4byte 0x01000800
.L080919FC: .4byte 0x02016B44
.L08091A00: .4byte gUnk_0868BFAC
.L08091A04: .4byte func_fe6_080910DC

	thumb_func_start func_fe6_08091A08
func_fe6_08091A08: @ 0x08091A08
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x2c]
	adds r0, #1
	str r0, [r2, #0x2c]
	ldr r1, [r2, #0x30]
	cmp r0, r1
	bne .L08091A1E
	adds r0, r2, #0
	bl Proc_Break
.L08091A1E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08091A24
func_fe6_08091A24: @ 0x08091A24
	push {lr}
	movs r0, #0
	bl EndFaceById
	ldr r0, .L08091A44 @ =ProcScr_Unk_08677FD0
	bl Proc_EndEach
	ldr r0, .L08091A48 @ =gUnk_0868BFAC
	bl Proc_EndEach
	movs r0, #0
	bl SetOnHBlankA
	pop {r0}
	bx r0
	.align 2, 0
.L08091A44: .4byte ProcScr_Unk_08677FD0
.L08091A48: .4byte gUnk_0868BFAC

	thumb_func_start func_fe6_08091A4C
func_fe6_08091A4C: @ 0x08091A4C
	push {lr}
	ldr r0, .L08091A60 @ =gUnk_0868BE74
	bl FindProc
	cmp r0, #0
	beq .L08091A5A
	movs r0, #1
.L08091A5A:
	pop {r1}
	bx r1
	.align 2, 0
.L08091A60: .4byte gUnk_0868BE74

	thumb_func_start func_fe6_08091A64
func_fe6_08091A64: @ 0x08091A64
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	ldr r0, .L08091B3C @ =0x02016B88
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	bl GetUnit
	str r0, [sp]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	str r0, [sp, #4]
	bl GetPidStats
	mov sb, r0
	ldr r0, .L08091B40 @ =ProcScr_Unk_08677FD0
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	movs r5, #0
	movs r7, #0xc0
	lsls r7, r7, #1
.L08091A9E:
	lsls r4, r5, #3
	ldr r0, .L08091B44 @ =0x02016B48
	mov r8, r0
	add r4, r8
	adds r0, r4, #0
	movs r1, #0x14
	bl InitText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	ldr r1, .L08091B48 @ =gBg0Tm+0x4
	adds r1, r7, r1
	adds r0, r4, #0
	bl PutText
	lsls r1, r5, #2
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r0, r1
	str r4, [r0]
	adds r7, #0x80
	adds r5, #1
	cmp r5, #1
	ble .L08091A9E
	movs r0, #4
	ldr r1, [sp]
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	beq .L08091B4C
	mov r2, sb
	ldrb r2, [r2, #3]
	lsls r0, r2, #0x1a
	lsrs r0, r0, #0x1a
	bl GetChapterInfo
	adds r0, #0x3e
	ldrb r1, [r0]
	mov r0, r8
	movs r2, #0
	bl func_fe6_0808E7CC
	adds r1, r0, #0
	mov r0, sl
	str r1, [r0, #0x54]
	adds r1, #3
	mov r0, r8
	bl Text_SetCursor
	mov r1, sb
	ldrb r1, [r1, #3]
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x1a
	bl GetChapterInfo
	ldrh r0, [r0, #0x38]
	bl DecodeMsg
	str r0, [r6, #0x2c]
	mov r2, sb
	ldrb r2, [r2, #3]
	lsls r0, r2, #0x1a
	lsrs r0, r0, #0x1a
	bl GetChapterInfo
	ldrh r0, [r0, #0x38]
	bl DecodeMsg
	bl GetStringTextLen
	mov r2, sl
	ldr r1, [r2, #0x54]
	adds r1, #6
	adds r1, r1, r0
	str r1, [r2, #0x54]
	b .L08091B5C
	.align 2, 0
.L08091B3C: .4byte 0x02016B88
.L08091B40: .4byte ProcScr_Unk_08677FD0
.L08091B44: .4byte 0x02016B48
.L08091B48: .4byte gBg0Tm+0x4
.L08091B4C:
	ldr r1, .L08091B90 @ =gUnk_0868BFCC
	ldr r2, [sp, #4]
	lsls r0, r2, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	bl DecodeMsg
	str r0, [r6, #0x2c]
.L08091B5C:
	adds r0, r6, #0
	adds r0, #0x5c
	movs r2, #0
	strh r2, [r0]
	str r2, [r6, #0x30]
	adds r1, r6, #0
	adds r1, #0x60
	movs r0, #4
	strh r0, [r1]
	adds r1, #2
	movs r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x5e
	strh r2, [r0]
	movs r0, #1
	bl EnableBgSync
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08091B90: .4byte gUnk_0868BFCC

	thumb_func_start func_fe6_08091B94
func_fe6_08091B94: @ 0x08091B94
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, .L08091C1C @ =0x02016B88
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	bl GetUnit
	movs r1, #4
	ldrh r0, [r0, #0xc]
	ands r1, r0
	cmp r1, #0
	beq .L08091C10
	ldr r4, .L08091C20 @ =ProcScr_Unk_08677FD0
	adds r0, r4, #0
	bl FindProc
	cmp r0, #0
	bne .L08091C16
	adds r0, r4, #0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	ldr r0, .L08091C24 @ =0x02016B48
	movs r3, #1
	adds r2, r0, #0
	adds r2, #8
	adds r1, r5, #0
	adds r1, #0x38
.L08091BD2:
	str r2, [r1]
	subs r2, #8
	subs r1, #4
	subs r3, #1
	cmp r3, #0
	bge .L08091BD2
	movs r4, #0
	ldr r1, [r6, #0x54]
	bl Text_SetCursor
	ldr r0, .L08091C28 @ =0x00000A6E
	bl DecodeMsg
	str r0, [r5, #0x2c]
	adds r0, r5, #0
	adds r0, #0x5c
	strh r4, [r0]
	str r4, [r5, #0x30]
	adds r1, r5, #0
	adds r1, #0x60
	movs r0, #4
	strh r0, [r1]
	adds r1, #2
	movs r0, #1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x5e
	strh r4, [r0]
	movs r0, #1
	bl EnableBgSync
.L08091C10:
	adds r0, r6, #0
	bl Proc_Break
.L08091C16:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08091C1C: .4byte 0x02016B88
.L08091C20: .4byte ProcScr_Unk_08677FD0
.L08091C24: .4byte 0x02016B48
.L08091C28: .4byte 0x00000A6E

	thumb_func_start func_fe6_08091C2C
func_fe6_08091C2C: @ 0x08091C2C
	push {lr}
	ldr r0, .L08091C3C @ =gUnk_0868BEEC
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L08091C3C: .4byte gUnk_0868BEEC

	thumb_func_start func_fe6_08091C40
func_fe6_08091C40: @ 0x08091C40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	ldr r0, .L08091D18 @ =0x02016B89
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	bl GetUnit
	str r0, [sp]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	str r0, [sp, #4]
	bl GetPidStats
	mov sb, r0
	ldr r0, .L08091D1C @ =ProcScr_Unk_08677FD0
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	movs r5, #0
	movs r7, #0x80
	lsls r7, r7, #3
.L08091C7A:
	lsls r4, r5, #3
	ldr r0, .L08091D20 @ =0x02016B78
	mov r8, r0
	add r4, r8
	adds r0, r4, #0
	movs r1, #0x14
	bl InitText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	ldr r1, .L08091D24 @ =gBg0Tm+0x1A
	adds r1, r7, r1
	adds r0, r4, #0
	bl PutText
	lsls r1, r5, #2
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r0, r1
	str r4, [r0]
	adds r7, #0x80
	adds r5, #1
	cmp r5, #1
	ble .L08091C7A
	movs r0, #4
	ldr r1, [sp]
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	beq .L08091D28
	mov r2, sb
	ldrb r2, [r2, #3]
	lsls r0, r2, #0x1a
	lsrs r0, r0, #0x1a
	bl GetChapterInfo
	adds r0, #0x3e
	ldrb r1, [r0]
	mov r0, r8
	movs r2, #0
	bl func_fe6_0808E7CC
	adds r1, r0, #0
	mov r0, sl
	str r1, [r0, #0x54]
	adds r1, #3
	mov r0, r8
	bl Text_SetCursor
	mov r1, sb
	ldrb r1, [r1, #3]
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x1a
	bl GetChapterInfo
	ldrh r0, [r0, #0x38]
	bl DecodeMsg
	str r0, [r6, #0x2c]
	mov r2, sb
	ldrb r2, [r2, #3]
	lsls r0, r2, #0x1a
	lsrs r0, r0, #0x1a
	bl GetChapterInfo
	ldrh r0, [r0, #0x38]
	bl DecodeMsg
	bl GetStringTextLen
	mov r2, sl
	ldr r1, [r2, #0x54]
	adds r1, #6
	adds r1, r1, r0
	str r1, [r2, #0x54]
	b .L08091D38
	.align 2, 0
.L08091D18: .4byte 0x02016B89
.L08091D1C: .4byte ProcScr_Unk_08677FD0
.L08091D20: .4byte 0x02016B78
.L08091D24: .4byte gBg0Tm+0x1A
.L08091D28:
	ldr r1, .L08091D6C @ =gUnk_0868BFCC
	ldr r2, [sp, #4]
	lsls r0, r2, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	bl DecodeMsg
	str r0, [r6, #0x2c]
.L08091D38:
	adds r0, r6, #0
	adds r0, #0x5c
	movs r2, #0
	strh r2, [r0]
	str r2, [r6, #0x30]
	adds r1, r6, #0
	adds r1, #0x60
	movs r0, #4
	strh r0, [r1]
	adds r1, #2
	movs r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x5e
	strh r2, [r0]
	movs r0, #1
	bl EnableBgSync
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08091D6C: .4byte gUnk_0868BFCC

	thumb_func_start func_fe6_08091D70
func_fe6_08091D70: @ 0x08091D70
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, .L08091DF8 @ =0x02016B89
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	bl GetUnit
	movs r1, #4
	ldrh r0, [r0, #0xc]
	ands r1, r0
	cmp r1, #0
	beq .L08091DEC
	ldr r4, .L08091DFC @ =ProcScr_Unk_08677FD0
	adds r0, r4, #0
	bl FindProc
	cmp r0, #0
	bne .L08091DF2
	adds r0, r4, #0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	ldr r0, .L08091E00 @ =0x02016B78
	movs r3, #1
	adds r2, r0, #0
	adds r2, #8
	adds r1, r5, #0
	adds r1, #0x38
.L08091DAE:
	str r2, [r1]
	subs r2, #8
	subs r1, #4
	subs r3, #1
	cmp r3, #0
	bge .L08091DAE
	movs r4, #0
	ldr r1, [r6, #0x54]
	bl Text_SetCursor
	ldr r0, .L08091E04 @ =0x00000A6E
	bl DecodeMsg
	str r0, [r5, #0x2c]
	adds r0, r5, #0
	adds r0, #0x5c
	strh r4, [r0]
	str r4, [r5, #0x30]
	adds r1, r5, #0
	adds r1, #0x60
	movs r0, #4
	strh r0, [r1]
	adds r1, #2
	movs r0, #1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x5e
	strh r4, [r0]
	movs r0, #1
	bl EnableBgSync
.L08091DEC:
	adds r0, r6, #0
	bl Proc_Break
.L08091DF2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08091DF8: .4byte 0x02016B89
.L08091DFC: .4byte ProcScr_Unk_08677FD0
.L08091E00: .4byte 0x02016B78
.L08091E04: .4byte 0x00000A6E

	thumb_func_start func_fe6_08091E08
func_fe6_08091E08: @ 0x08091E08
	push {lr}
	ldr r0, .L08091E20 @ =0x02016B8A
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08091E1A
	ldr r0, .L08091E24 @ =gUnk_0868BF14
	movs r1, #3
	bl SpawnProc
.L08091E1A:
	pop {r0}
	bx r0
	.align 2, 0
.L08091E20: .4byte 0x02016B8A
.L08091E24: .4byte gUnk_0868BF14

	thumb_func_start func_fe6_08091E28
func_fe6_08091E28: @ 0x08091E28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldr r7, .L08091F3C @ =0x02016B8A
	movs r0, #1
	mov sl, r0
	strb r0, [r7]
	movs r0, #0
	bl func_fe6_080916AC
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, .L08091F40 @ =0x02016B88
	adds r0, r4, #1
	strb r0, [r1]
	movs r0, #1
	bl func_fe6_080916AC
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x3f
	ble .L08091E60
	movs r0, #0
	strb r0, [r7]
.L08091E60:
	ldr r1, .L08091F44 @ =0x02016B89
	adds r0, r6, #1
	strb r0, [r1]
	bl ResetText
	ldr r0, .L08091F48 @ =gBg3Tm
	ldr r1, .L08091F4C @ =gUnk_08345440
	movs r2, #0x80
	lsls r2, r2, #6
	bl TmApplyTsa_thm
	movs r1, #0
	mov r8, r1
	str r1, [sp, #4]
	ldr r1, .L08091F50 @ =0x0600D800
	ldr r2, .L08091F54 @ =0x01000800
	add r0, sp, #4
	bl CpuFastSet
	adds r0, r4, #0
	bl GetUnit
	adds r5, r0, #0
	bl GetUnitFid
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r1, #0xff
	lsls r1, r1, #8
	movs r0, #0
	movs r2, #0
	bl SetBgOffset
	movs r2, #0xdf
	lsls r2, r2, #1
	movs r0, #0x42
	str r0, [sp]
	movs r0, #0
	adds r1, r4, #0
	movs r3, #0
	bl StartFace
	ldr r1, .L08091F58 @ =gUnk_030048D4
	str r0, [r1]
	movs r0, #0
	movs r1, #0
	adds r2, r5, #0
	movs r3, #1
	bl func_fe6_080920B4
	ldrb r7, [r7]
	cmp r7, #1
	bne .L08091F0C
	adds r0, r6, #0
	bl GetUnit
	adds r5, r0, #0
	bl GetUnitFid
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #1
	movs r2, #0
	bl SetBgOffset
	movs r2, #0xce
	rsbs r2, r2, #0
	movs r0, #0x43
	str r0, [sp]
	movs r0, #1
	adds r1, r4, #0
	movs r3, #0x50
	bl StartFace
	ldr r1, .L08091F5C @ =0x02016B8C
	str r0, [r1]
	movs r0, #0xb
	movs r1, #0xa
	adds r2, r5, #0
	movs r3, #1
	bl func_fe6_080920B4
.L08091F0C:
	mov r0, r8
	mov r1, sb
	str r0, [r1, #0x2c]
	ldr r0, .L08091F60 @ =0x02016B44
	mov r1, sl
	strb r1, [r0]
	ldr r0, .L08091F64 @ =gUnk_0868BFAC
	movs r1, #0
	bl SpawnProc
	ldr r0, .L08091F68 @ =func_fe6_080911D0
	bl SetOnHBlankA
	movs r0, #3
	bl EnableBgSync
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08091F3C: .4byte 0x02016B8A
.L08091F40: .4byte 0x02016B88
.L08091F44: .4byte 0x02016B89
.L08091F48: .4byte gBg3Tm
.L08091F4C: .4byte gUnk_08345440
.L08091F50: .4byte 0x0600D800
.L08091F54: .4byte 0x01000800
.L08091F58: .4byte gUnk_030048D4
.L08091F5C: .4byte 0x02016B8C
.L08091F60: .4byte 0x02016B44
.L08091F64: .4byte gUnk_0868BFAC
.L08091F68: .4byte func_fe6_080911D0

	thumb_func_start func_fe6_08091F6C
func_fe6_08091F6C: @ 0x08091F6C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x2c]
	cmp r1, #0x3c
	beq .L08091FDE
	cmp r1, #0x3c
	bgt .L08091F80
	cmp r1, #0x2d
	beq .L08091FC8
	b .L08091F8C
.L08091F80:
	cmp r1, #0xc8
	beq .L08091FE4
	movs r0, #0xf0
	lsls r0, r0, #1
	cmp r1, r0
	beq .L08091FEA
.L08091F8C:
	ldr r0, [r4, #0x2c]
	cmp r0, #0x2c
	bgt .L08091FF0
	ldr r0, .L08091FB8 @ =gUnk_030048D4
	ldr r1, [r0]
	ldr r2, .L08091FBC @ =0x02016B90
	movs r0, #0xbe
	ldrh r3, [r2]
	subs r0, r0, r3
	strh r0, [r1, #0x2e]
	ldr r0, .L08091FC0 @ =0x02016B8A
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08091FF0
	ldr r0, .L08091FC4 @ =0x02016B8C
	ldr r1, [r0]
	movs r0, #0x32
	ldrh r2, [r2, #2]
	subs r0, r0, r2
	strh r0, [r1, #0x2e]
	b .L08091FF0
	.align 2, 0
.L08091FB8: .4byte gUnk_030048D4
.L08091FBC: .4byte 0x02016B90
.L08091FC0: .4byte 0x02016B8A
.L08091FC4: .4byte 0x02016B8C
.L08091FC8:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	b .L08091FF0
.L08091FDE:
	bl func_fe6_08091C2C
	b .L08091FF0
.L08091FE4:
	bl func_fe6_08091E08
	b .L08091FF0
.L08091FEA:
	adds r0, r4, #0
	bl Proc_Break
.L08091FF0:
	ldr r0, [r4, #0x2c]
	adds r0, #1
	str r0, [r4, #0x2c]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08091FFC
func_fe6_08091FFC: @ 0x08091FFC
	push {lr}
	movs r0, #0
	bl EndFaceById
	movs r0, #1
	bl EndFaceById
	ldr r0, .L08092020 @ =ProcScr_Unk_08677FD0
	bl Proc_EndEach
	ldr r0, .L08092024 @ =gUnk_0868BFAC
	bl Proc_EndEach
	movs r0, #0
	bl SetOnHBlankA
	pop {r0}
	bx r0
	.align 2, 0
.L08092020: .4byte ProcScr_Unk_08677FD0
.L08092024: .4byte gUnk_0868BFAC

	thumb_func_start func_fe6_08092028
func_fe6_08092028: @ 0x08092028
	push {lr}
	ldr r0, .L0809203C @ =gUnk_0868BF3C
	bl FindProc
	cmp r0, #0
	beq .L08092036
	movs r0, #1
.L08092036:
	pop {r1}
	bx r1
	.align 2, 0
.L0809203C: .4byte gUnk_0868BF3C

	thumb_func_start func_fe6_08092040
func_fe6_08092040: @ 0x08092040
	ldr r0, .L08092050 @ =0x02016B90
	movs r1, #0xff
	lsls r1, r1, #8
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0, #2]
	bx lr
	.align 2, 0
.L08092050: .4byte 0x02016B90

	thumb_func_start func_fe6_08092054
func_fe6_08092054: @ 0x08092054
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r0, .L080920A4 @ =0x02016B44
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq .L08092098
	ldr r6, .L080920A8 @ =0x02016B90
	ldrh r0, [r6, #2]
	cmp r0, #0
	beq .L08092098
	ldr r0, .L080920AC @ =gUnk_0868BF3C
	bl FindProc
	adds r5, r0, #0
	ldr r1, .L080920B0 @ =0xFFFFFF00
	ldr r3, [r5, #0x2c]
	movs r4, #0x2d
	str r4, [sp]
	movs r0, #4
	movs r2, #0
	bl Interpolate
	strh r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r3, [r5, #0x2c]
	str r4, [sp]
	movs r0, #4
	movs r2, #0
	bl Interpolate
	strh r0, [r6, #2]
.L08092098:
	bl func_fe6_0809104C
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080920A4: .4byte 0x02016B44
.L080920A8: .4byte 0x02016B90
.L080920AC: .4byte gUnk_0868BF3C
.L080920B0: .4byte 0xFFFFFF00

	thumb_func_start func_fe6_080920B4
func_fe6_080920B4: @ 0x080920B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r2, #0
	adds r4, r3, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, [r7]
	ldrb r0, [r0, #4]
	bl GetPidStats
	mov sl, r0
	ldr r0, [r7]
	ldrb r6, [r0, #4]
	cmp r4, #0
	bne .L08092128
	ldr r4, .L08092118 @ =gBg1Tm
	ldr r1, .L0809211C @ =gUnk_083461C4
	movs r5, #0x86
	lsls r5, r5, #7
	adds r0, r4, #0
	adds r2, r5, #0
	bl TmApplyTsa_thm
	movs r1, #0xd1
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, .L08092120 @ =gUnk_08346330
	adds r2, r5, #0
	bl TmApplyTsa_thm
	movs r0, #0x98
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r1, .L08092124 @ =gUnk_083463B4
	adds r0, r4, #0
	adds r2, r5, #0
	bl TmApplyTsa_thm
	b .L0809213E
	.align 2, 0
.L08092118: .4byte gBg1Tm
.L0809211C: .4byte gUnk_083461C4
.L08092120: .4byte gUnk_08346330
.L08092124: .4byte gUnk_083463B4
.L08092128:
	mov r1, sb
	lsls r0, r1, #5
	add r0, r8
	lsls r0, r0, #1
	ldr r1, .L0809225C @ =gBg1Tm
	adds r0, r0, r1
	ldr r1, .L08092260 @ =gUnk_083463F4
	movs r2, #0x86
	lsls r2, r2, #7
	bl TmApplyTsa_thm
.L0809213E:
	ldr r0, .L08092264 @ =gUnk_0868BFCC
	lsls r4, r6, #3
	adds r4, r4, r0
	ldrh r0, [r4, #6]
	bl DecodeMsg
	bl GetStringTextLen
	movs r1, #0x48
	subs r1, r1, r0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r6, r1, #1
	ldrh r0, [r4, #6]
	bl DecodeMsg
	mov r4, sb
	adds r4, #1
	lsls r4, r4, #5
	adds r1, r4, #2
	add r1, r8
	lsls r1, r1, #1
	ldr r5, .L08092268 @ =gBg0Tm
	adds r1, r1, r5
	movs r2, #9
	str r2, [sp]
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0
	adds r3, r6, #0
	bl PutDrawText
	ldr r0, [r7]
	ldrh r0, [r0]
	bl DecodeMsg
	bl GetStringTextLen
	movs r1, #0x28
	subs r1, r1, r0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r6, r1, #1
	ldr r0, [r7]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r4, #0xb
	add r4, r8
	lsls r4, r4, #1
	adds r4, r4, r5
	movs r1, #5
	str r1, [sp]
	str r0, [sp, #4]
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	adds r3, r6, #0
	bl PutDrawText
	add r0, sp, #8
	movs r1, #0xf
	bl InitText
	mov r1, sb
	adds r1, #4
	lsls r1, r1, #5
	adds r1, #2
	add r1, r8
	lsls r1, r1, #1
	adds r1, r1, r5
	add r0, sp, #8
	bl PutText
	mov r0, sl
	ldrh r0, [r0, #0xa]
	lsls r3, r0, #0x12
	lsrs r3, r3, #0x14
	add r0, sp, #8
	movs r1, #0x1e
	movs r2, #0
	bl Text_InsertDrawNumberOrBlank
	ldr r0, .L0809226C @ =0x000009C6
	bl DecodeMsg
	adds r3, r0, #0
	add r0, sp, #8
	movs r1, #0x26
	movs r2, #0
	bl Text_InsertDrawString
	movs r4, #0
	mov r1, sl
	ldrb r1, [r1]
	cmp r1, #0x63
	bhi .L08092202
	movs r4, #6
.L08092202:
	adds r1, r4, #0
	adds r1, #0x3f
	mov r0, sl
	ldr r3, [r0, #8]
	lsls r3, r3, #0xe
	lsrs r3, r3, #0x16
	add r0, sp, #8
	movs r2, #0
	bl Text_InsertDrawNumberOrBlank
	adds r4, #0x47
	ldr r0, .L08092270 @ =0x000009C7
	bl DecodeMsg
	adds r3, r0, #0
	add r0, sp, #8
	adds r1, r4, #0
	movs r2, #0
	bl Text_InsertDrawString
	mov r1, sl
	ldrb r3, [r1]
	add r0, sp, #8
	movs r1, #0x5f
	movs r2, #0
	bl Text_InsertDrawNumberOrBlank
	ldr r0, .L08092274 @ =0x000009C8
	bl DecodeMsg
	adds r3, r0, #0
	add r0, sp, #8
	movs r1, #0x67
	movs r2, #0
	bl Text_InsertDrawString
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0809225C: .4byte gBg1Tm
.L08092260: .4byte gUnk_083463F4
.L08092264: .4byte gUnk_0868BFCC
.L08092268: .4byte gBg0Tm
.L0809226C: .4byte 0x000009C6
.L08092270: .4byte 0x000009C7
.L08092274: .4byte 0x000009C8

	thumb_func_start func_fe6_08092278
func_fe6_08092278: @ 0x08092278
	ldr r2, .L08092288 @ =gUnk_0868C2DC
	lsls r0, r0, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bx lr
	.align 2, 0
.L08092288: .4byte gUnk_0868C2DC

	thumb_func_start func_fe6_0809228C
func_fe6_0809228C: @ 0x0809228C
	push {r4, lr}
	bl func_fe6_08092278
	ldr r4, .L080922AC @ =gBuf
	adds r1, r4, #0
	bl Decompress
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	movs r1, #0
	bl ApplyPaletteExt
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080922AC: .4byte gBuf

	thumb_func_start func_fe6_080922B0
func_fe6_080922B0: @ 0x080922B0
	push {lr}
	ldr r0, .L080922C0 @ =gUnk_0868C324
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L080922C0: .4byte gUnk_0868C324

	thumb_func_start func_fe6_080922C4
func_fe6_080922C4: @ 0x080922C4
	push {lr}
	ldr r0, .L080922D4 @ =gUnk_0868C324
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L080922D4: .4byte gUnk_0868C324

	thumb_func_start func_fe6_080922D8
func_fe6_080922D8: @ 0x080922D8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov ip, r0
	ldr r3, .L080923C0 @ =gDispIo
	movs r4, #8
	rsbs r4, r4, #0
	ldrb r0, [r3]
	ands r4, r0
	movs r2, #4
	orrs r4, r2
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r3, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	orrs r0, r2
	subs r1, #6
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r3, #1]
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r5, [r3, #0x10]
	ands r0, r5
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x10]
	ldrb r7, [r3, #0x14]
	ands r1, r7
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x14]
	movs r0, #3
	ldrb r1, [r3, #0x18]
	orrs r0, r1
	strb r0, [r3, #0x18]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r4, r0
	strb r4, [r3]
	movs r1, #0
	mov r2, ip
	str r1, [r2, #0x2c]
	str r1, [r2, #0x30]
	movs r0, #0xf0
	lsls r0, r0, #6
	str r0, [r2, #0x34]
	movs r0, #0xa0
	lsls r0, r0, #6
	str r0, [r2, #0x38]
	str r1, [r2, #0x44]
	mov r5, ip
	adds r5, #0x48
	movs r2, #0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r5]
	mov r6, ip
	adds r6, #0x4a
	strh r0, [r6]
	mov r0, ip
	adds r0, #0x4c
	strh r1, [r0]
	adds r0, #6
	strb r2, [r0]
	subs r0, #4
	strh r1, [r0]
	adds r0, #5
	strb r2, [r0]
	subs r0, #3
	strh r1, [r0]
	adds r0, #4
	strb r2, [r0]
	mov r3, ip
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	ldr r2, [r3, #0x34]
	ldr r3, [r3, #0x38]
	mov r7, ip
	ldr r4, [r7, #0x44]
	str r4, [sp]
	movs r7, #0
	ldrsh r4, [r5, r7]
	str r4, [sp, #4]
	movs r5, #0
	ldrsh r4, [r6, r5]
	str r4, [sp, #8]
	bl func_fe6_08092EB0
	movs r0, #0
	movs r1, #1
	bl func_fe6_0809228C
	movs r0, #0
	movs r1, #0
	bl func_fe6_08092278
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl Decompress
	bl func_fe6_08092838
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080923C0: .4byte gDispIo

	thumb_func_start func_fe6_080923C4
func_fe6_080923C4: @ 0x080923C4
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_080923C8
func_fe6_080923C8: @ 0x080923C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, .L080923F4 @ =gUnk_0868C37C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	bl func_fe6_08092854
	adds r1, r0, #0
	str r1, [r4, #0x58]
	cmp r1, #0
	bne .L080923F8
	adds r0, r4, #0
	bl Proc_End
	b .L0809241A
	.align 2, 0
.L080923F4: .4byte gUnk_0868C37C
.L080923F8:
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x58]
	strb r5, [r0, #1]
	ldr r0, [r4, #0x58]
	strb r6, [r0, #5]
	ldr r1, [r4, #0x58]
	adds r0, r1, #0
	adds r0, #0xd4
	str r7, [r0]
	adds r0, #4
	mov r2, r8
	str r2, [r0]
	ldr r0, [sp, #0x18]
	str r0, [r1, #0xc]
	ldr r0, [sp, #0x1c]
	str r0, [r1, #8]
.L0809241A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08092424
func_fe6_08092424: @ 0x08092424
	push {lr}
	ldr r0, .L08092430 @ =gUnk_0868C37C
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
.L08092430: .4byte gUnk_0868C37C

	thumb_func_start func_fe6_08092434
func_fe6_08092434: @ 0x08092434
	push {lr}
	ldr r0, .L08092444 @ =gUnk_0868C37C
	bl FindProc
	cmp r0, #0
	bne .L08092448
	movs r0, #0
	b .L0809244A
	.align 2, 0
.L08092444: .4byte gUnk_0868C37C
.L08092448:
	movs r0, #1
.L0809244A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08092450
func_fe6_08092450: @ 0x08092450
	ldr r1, [r0, #0x58]
	movs r0, #0
	strb r0, [r1]
	bx lr

	thumb_func_start func_fe6_08092458
func_fe6_08092458: @ 0x08092458
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r7, [r0, #0x58]
	ldrb r0, [r7, #1]
	bl func_fe6_0809325C
	bl func_fe6_08093284
	movs r1, #0
	strb r0, [r7, #4]
	str r1, [r7, #0x14]
	movs r3, #0
	cmp r3, r0
	bge .L080924CE
.L0809247C:
	ldrb r0, [r7, #1]
	str r3, [sp]
	bl func_fe6_0809325C
	ldr r3, [sp]
	adds r1, r3, #0
	bl func_fe6_08093288
	ldr r3, [sp]
	lsls r4, r3, #2
	adds r2, r7, #0
	adds r2, #0x74
	adds r2, r2, r4
	adds r1, r7, #0
	adds r1, #0xd4
	ldr r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #8
	str r0, [r2]
	ldrb r0, [r7, #1]
	str r3, [sp]
	bl func_fe6_0809325C
	ldr r3, [sp]
	adds r1, r3, #0
	bl func_fe6_080932D8
	adds r2, r7, #0
	adds r2, #0xa4
	adds r2, r2, r4
	adds r1, r7, #0
	adds r1, #0xd8
	ldr r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #8
	str r0, [r2]
	ldr r3, [sp]
	adds r3, #1
	ldrb r1, [r7, #4]
	cmp r3, r1
	blt .L0809247C
.L080924CE:
	movs r3, #1
	movs r0, #0x14
	adds r0, r0, r7
	mov sb, r0
	ldrb r1, [r7, #4]
	cmp r3, r1
	bge .L08092556
	movs r0, #0x74
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0
	mov r8, r1
.L080924E6:
	lsls r6, r3, #2
	mov r0, sl
	ldr r5, [r0, #4]
	adds r1, r0, #0
	adds r1, #4
	mov sl, r1
	subs r1, #4
	ldm r1!, {r0}
	subs r5, r5, r0
	adds r0, r7, #0
	adds r0, #0xa4
	adds r1, r0, r6
	add r0, r8
	ldr r4, [r1]
	ldr r0, [r0]
	subs r4, r4, r0
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r3, [sp]
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sb
	adds r2, r1, r6
	add r1, r8
	ldr r1, [r1]
	adds r1, r1, r0
	str r1, [r2]
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2
	adds r4, r7, #0
	adds r4, #0x44
	adds r4, r4, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x3f
	bl __divsi3
	str r0, [r4]
	movs r0, #4
	add r8, r0
	ldr r3, [sp]
	adds r3, #1
	ldrb r1, [r7, #4]
	cmp r3, r1
	blt .L080924E6
.L08092556:
	ldrb r0, [r7, #4]
	subs r0, #1
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	str r0, [r7, #0x10]
	ldr r1, [r7, #8]
	bl __divsi3
	adds r0, #1
	strb r0, [r7, #3]
	movs r3, #0
	ldrb r1, [r7, #3]
	cmp r3, r1
	bge .L080925B2
	movs r6, #0
.L08092576:
	lsls r5, r3, #2
	movs r0, #0x91
	lsls r0, r0, #2
	adds r4, r7, r0
	adds r4, r4, r5
	ldr r0, [r7, #0xc]
	muls r0, r3, r0
	subs r1, #1
	str r3, [sp]
	bl __divsi3
	str r0, [r4]
	adds r0, r7, #0
	adds r0, #0xdc
	ldr r3, [sp]
	adds r0, r0, r3
	strb r6, [r0]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r0, r0, r5
	str r6, [r0]
	adds r0, r7, #0
	adds r0, #0xf0
	adds r0, r0, r3
	strb r6, [r0]
	adds r3, #1
	ldrb r1, [r7, #3]
	cmp r3, r1
	blt .L08092576
.L080925B2:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080925C4
func_fe6_080925C4: @ 0x080925C4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	lsls r7, r1, #2
	movs r2, #0xa5
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r0, r0, r7
	ldr r0, [r0]
	adds r0, #0x20
	ldr r2, .L08092640 @ =0x000003FF
	ands r0, r2
	asrs r2, r0, #6
	asrs r0, r0, #8
	lsls r3, r0, #8
	movs r0, #3
	ands r2, r0
	lsls r6, r2, #1
	ldrb r0, [r5, #3]
	subs r0, #1
	cmp r1, r0
	bne .L08092648
	ldrb r0, [r5, #2]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r4, #0
	adds r2, r4, #0
	bl func_fe6_08093064
	movs r0, #0xf
	ldrb r1, [r5, #5]
	ands r0, r1
	lsls r0, r0, #0xc
	movs r1, #0xc4
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r6, r6, r0
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r0, r0, r7
	ldr r1, [r0]
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x17
	ldrb r2, [r5, #2]
	lsls r0, r2, #9
	orrs r1, r0
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r0, r0, r7
	ldr r2, [r0]
	asrs r2, r2, #8
	movs r0, #0xff
	ands r2, r0
	orrs r2, r4
	ldr r3, .L08092644 @ =gUnk_0868C2D4
	str r6, [sp]
	movs r0, #0xc
	bl PutSpriteExt
	b .L0809267A
	.align 2, 0
.L08092640: .4byte 0x000003FF
.L08092644: .4byte gUnk_0868C2D4
.L08092648:
	movs r0, #0xf
	ldrb r1, [r5, #5]
	ands r0, r1
	lsls r0, r0, #0xc
	ldr r1, .L08092684 @ =0x00000323
	adds r6, r0, r1
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r0, r0, r7
	ldr r1, [r0]
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x17
	adds r2, #0x50
	adds r0, r5, r2
	adds r0, r0, r7
	ldr r2, [r0]
	asrs r2, r2, #8
	movs r0, #0xff
	ands r2, r0
	ldr r3, .L08092688 @ =gUnk_0868C2CC
	str r6, [sp]
	movs r0, #0xc
	bl PutSpriteExt
.L0809267A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08092684: .4byte 0x00000323
.L08092688: .4byte gUnk_0868C2CC

	thumb_func_start func_fe6_0809268C
func_fe6_0809268C: @ 0x0809268C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, [r0, #0x58]
	movs r0, #0
	mov sl, r0
	ldrb r1, [r4, #3]
	cmp sl, r1
	blt .L080926A4
	b .L08092828
.L080926A4:
	movs r2, #0xf0
	adds r2, r2, r4
	mov sb, r2
	mov r8, r0
.L080926AC:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #1
	beq .L0809276E
	cmp r0, #1
	bgt .L080926BE
	cmp r0, #0
	beq .L080926C6
	b .L08092816
.L080926BE:
	cmp r0, #0x63
	bne .L080926C4
	b .L0809280E
.L080926C4:
	b .L08092816
.L080926C6:
	adds r0, r4, #0
	adds r0, #0xdc
	add r0, sl
	ldrb r6, [r0]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r1, r4, r2
	add r1, r8
	lsls r2, r6, #2
	adds r0, r4, #0
	adds r0, #0x74
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r4, r0
	add r1, r8
	adds r0, r4, #0
	adds r0, #0xa4
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r0, r4, r1
	mov r2, r8
	adds r7, r0, r2
	adds r1, r6, #1
	lsls r1, r1, #2
	adds r0, r4, #0
	adds r0, #0x44
	adds r0, r0, r1
	ldr r1, [r0]
	str r1, [r7]
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r0, r4, r2
	mov r2, r8
	adds r5, r0, r2
	movs r2, #0x91
	lsls r2, r2, #2
	adds r0, r4, r2
	mov r2, r8
	adds r3, r0, r2
	ldr r0, .L080927E4 @ =gUnk_08353328
	mov ip, r0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
	ldr r6, .L080927E8 @ =0x000003FF
	ands r1, r6
	lsls r1, r1, #2
	add r1, ip
	ldr r2, [r3]
	ldr r0, [r1]
	muls r0, r2, r0
	cmp r0, #0
	bge .L08092740
	ldr r1, .L080927EC @ =0x00007FFF
	adds r0, r0, r1
.L08092740:
	asrs r0, r0, #0xf
	str r0, [r5]
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r0, r4, r2
	mov r1, r8
	adds r2, r0, r1
	ldr r0, [r7]
	ands r0, r6
	lsls r0, r0, #2
	add r0, ip
	ldr r1, [r3]
	ldr r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	bge .L08092764
	ldr r1, .L080927EC @ =0x00007FFF
	adds r0, r0, r1
.L08092764:
	asrs r0, r0, #0xf
	str r0, [r2]
	movs r0, #1
	mov r2, sb
	strb r0, [r2]
.L0809276E:
	adds r0, r4, #0
	mov r1, sl
	bl func_fe6_080925C4
	adds r0, r4, #0
	adds r0, #0xdc
	mov r1, sl
	adds r7, r0, r1
	ldrb r6, [r7]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r4, r0
	add r2, r8
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r4, r1
	add r0, r8
	ldr r1, [r2]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r2]
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r2, r4, r0
	add r2, r8
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r4, r1
	add r0, r8
	ldr r1, [r2]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r2]
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r1, r4, r2
	add r1, r8
	subs r2, #0xa0
	adds r0, r4, r2
	add r0, r8
	ldr r2, [r1]
	ldr r0, [r0]
	adds r5, r2, r0
	str r5, [r1]
	ldr r0, [r4, #0x10]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	ldrb r1, [r4, #3]
	subs r1, #1
	bl __divsi3
	cmp r5, r0
	blt .L080927F0
	movs r0, #0x63
	mov r2, sb
	strb r0, [r2]
	b .L08092816
	.align 2, 0
.L080927E4: .4byte gUnk_08353328
.L080927E8: .4byte 0x000003FF
.L080927EC: .4byte 0x00007FFF
.L080927F0:
	adds r0, r6, #1
	lsls r0, r0, #2
	adds r1, r4, #0
	adds r1, #0x14
	adds r1, r1, r0
	ldr r0, [r1]
	cmp r5, r0
	blt .L08092816
	ldrb r0, [r7]
	adds r0, #1
	movs r1, #0
	strb r0, [r7]
	mov r0, sb
	strb r1, [r0]
	b .L08092816
.L0809280E:
	adds r0, r4, #0
	mov r1, sl
	bl func_fe6_080925C4
.L08092816:
	movs r1, #1
	add sb, r1
	movs r2, #4
	add r8, r2
	add sl, r1
	ldrb r0, [r4, #3]
	cmp sl, r0
	bge .L08092828
	b .L080926AC
.L08092828:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08092838
func_fe6_08092838: @ 0x08092838
	movs r1, #0
	movs r3, #0
	ldr r0, .L08092850 @ =gUnk_030048E0
	movs r2, #0xcd
	lsls r2, r2, #2
.L08092842:
	strb r3, [r0]
	strb r1, [r0, #2]
	adds r0, r0, r2
	adds r1, #1
	cmp r1, #2
	ble .L08092842
	bx lr
	.align 2, 0
.L08092850: .4byte gUnk_030048E0

	thumb_func_start func_fe6_08092854
func_fe6_08092854: @ 0x08092854
	ldr r1, .L0809286C @ =gUnk_030048E0
	movs r0, #0xcd
	lsls r0, r0, #3
	adds r3, r1, r0
	movs r2, #0xcd
	lsls r2, r2, #2
.L08092860:
	ldrb r0, [r1]
	cmp r0, #0
	bne .L08092870
	adds r0, r1, #0
	b .L08092878
	.align 2, 0
.L0809286C: .4byte gUnk_030048E0
.L08092870:
	adds r1, r1, r2
	cmp r1, r3
	ble .L08092860
	movs r0, #0
.L08092878:
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0809287C
func_fe6_0809287C: @ 0x0809287C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08092898 @ =gUnk_0868C3AC
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x2c]
	adds r0, #0x66
	movs r1, #0
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08092898: .4byte gUnk_0868C3AC

	thumb_func_start func_fe6_0809289C
func_fe6_0809289C: @ 0x0809289C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x66
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	ldrsh r1, [r1, r0]
	ldr r0, [r2, #0x2c]
	cmp r1, r0
	bne .L080928BA
	adds r0, r2, #0
	bl Proc_Break
.L080928BA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080928C0
func_fe6_080928C0: @ 0x080928C0
	push {lr}
	ldr r0, .L080928D0 @ =gUnk_0868C3AC
	bl FindProc
	cmp r0, #0
	bne .L080928D4
	movs r0, #0
	b .L080928D6
	.align 2, 0
.L080928D0: .4byte gUnk_0868C3AC
.L080928D4:
	movs r0, #1
.L080928D6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_080928DC
func_fe6_080928DC: @ 0x080928DC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r1, r2, #0
	ldr r0, .L08092904 @ =gUnk_0868C3C4
	bl SpawnProc
	adds r4, r0, #0
	ldr r0, .L08092908 @ =gUnk_0868C324
	bl FindProc
	str r0, [r4, #0x4c]
	lsls r5, r5, #8
	str r5, [r4, #0x2c]
	lsls r6, r6, #8
	str r6, [r4, #0x30]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08092904: .4byte gUnk_0868C3C4
.L08092908: .4byte gUnk_0868C324

	thumb_func_start func_fe6_0809290C
func_fe6_0809290C: @ 0x0809290C
	adds r2, r0, #0
	adds r2, #0x66
	movs r1, #0
	strh r1, [r2]
	adds r0, #0x68
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0809291C
func_fe6_0809291C: @ 0x0809291C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r4, [r7, #0x4c]
	ldr r0, [r7, #0x2c]
	str r0, [r4, #0x3c]
	ldr r1, [r7, #0x30]
	str r1, [r4, #0x40]
	movs r2, #0x66
	adds r2, r2, r7
	mov r8, r2
	movs r3, #0
	ldrsh r5, [r2, r3]
	cmp r5, #1
	beq .L0809296A
	cmp r5, #1
	bgt .L08092948
	cmp r5, #0
	beq .L0809294E
	b .L08092960
.L08092948:
	cmp r5, #2
	beq .L080929C8
	b .L08092960
.L0809294E:
	bl func_fe6_08092A9C
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x68
	strh r5, [r0]
.L08092960:
	adds r6, r4, #0
	adds r6, #0x4a
	adds r5, r4, #0
	adds r5, #0x48
	b .L08092A68
.L0809296A:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x80
	lsls r2, r2, #2
	adds r7, #0x68
	movs r5, #0
	ldrsh r3, [r7, r5]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #5
	bl Interpolate
	adds r2, r4, #0
	adds r2, #0x4a
	strh r0, [r2]
	adds r1, r4, #0
	adds r1, #0x48
	strh r0, [r1]
	ldr r0, [r4, #0x3c]
	ldr r3, .L080929C0 @ =0xFFFF8800
	adds r0, r0, r3
	str r0, [r4, #0x34]
	ldr r0, [r4, #0x40]
	ldr r5, .L080929C4 @ =0xFFFFB000
	adds r0, r0, r5
	str r0, [r4, #0x38]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r6, r2, #0
	adds r5, r1, #0
	cmp r0, #0x21
	bne .L08092A68
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r7]
	b .L08092A68
	.align 2, 0
.L080929C0: .4byte 0xFFFF8800
.L080929C4: .4byte 0xFFFFB000
.L080929C8:
	adds r0, r7, #0
	adds r0, #0x68
	movs r5, #1
	ldrh r2, [r0]
	ands r5, r2
	mov r8, r0
	cmp r5, #0
	beq .L08092A14
	movs r0, #1
	movs r1, #1
	bl func_fe6_0809228C
	movs r1, #0
	str r1, [r4, #0x2c]
	str r1, [r4, #0x30]
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r4, #0x34]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [r4, #0x38]
	str r1, [r4, #0x44]
	adds r3, r4, #0
	adds r3, #0x48
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r3]
	adds r2, r4, #0
	adds r2, #0x4a
	strh r0, [r2]
	ldr r1, .L08092A10 @ =gDispIo
	movs r0, #0x10
	ldrb r5, [r1]
	orrs r0, r5
	b .L08092A4C
	.align 2, 0
.L08092A10: .4byte gDispIo
.L08092A14:
	movs r0, #0
	movs r1, #1
	bl func_fe6_0809228C
	str r5, [r4, #0x2c]
	str r5, [r4, #0x30]
	ldr r0, [r4, #0x3c]
	ldr r1, .L08092A90 @ =0xFFFF8800
	adds r0, r0, r1
	str r0, [r4, #0x34]
	ldr r0, [r4, #0x40]
	ldr r2, .L08092A94 @ =0xFFFFB000
	adds r0, r0, r2
	str r0, [r4, #0x38]
	str r5, [r4, #0x44]
	adds r3, r4, #0
	adds r3, #0x48
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r3]
	adds r2, r4, #0
	adds r2, #0x4a
	strh r0, [r2]
	ldr r1, .L08092A98 @ =gDispIo
	movs r0, #0x11
	rsbs r0, r0, #0
	ldrb r5, [r1]
	ands r0, r5
.L08092A4C:
	strb r0, [r1]
	adds r6, r2, #0
	adds r5, r3, #0
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	bne .L08092A68
	adds r0, r7, #0
	bl Proc_Break
.L08092A68:
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	ldr r2, [r4, #0x34]
	ldr r3, [r4, #0x38]
	ldr r4, [r4, #0x44]
	str r4, [sp]
	movs r7, #0
	ldrsh r4, [r5, r7]
	str r4, [sp, #4]
	movs r5, #0
	ldrsh r4, [r6, r5]
	str r4, [sp, #8]
	bl func_fe6_08092EB0
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08092A90: .4byte 0xFFFF8800
.L08092A94: .4byte 0xFFFFB000
.L08092A98: .4byte gDispIo

	thumb_func_start func_fe6_08092A9C
func_fe6_08092A9C: @ 0x08092A9C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r2, r0, #0
	adds r3, r1, #0
	asrs r0, r2, #8
	adds r2, r0, #0
	subs r2, #0x78
	asrs r0, r3, #8
	adds r3, r0, #0
	subs r3, #0x50
	movs r1, #0xf0
	subs r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov sb, r4
	asrs r0, r0, #0x10
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x14]
	movs r1, #0xa0
	subs r4, r1, r3
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x10
	asrs r4, r4, #0x10
	subs r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	adds r0, r0, r2
	subs r0, #0xf0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	mov r0, r8
	str r0, [sp, #8]
	ldr r1, [sp, #0x14]
	str r1, [sp]
	adds r0, r4, r3
	subs r0, #0xa0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	mov r2, sl
	str r2, [sp, #4]
	str r0, [sp, #0x10]
	movs r0, #1
	movs r1, #0
	bl func_fe6_08092278
	ldr r1, .L08092CD0 @ =0x02000000
	bl Decompress
	movs r2, #0
	cmp r2, r4
	bge .L08092B66
	ldr r4, [sp, #8]
	lsls r0, r4, #0x10
	asrs r7, r0, #0x10
	ldr r1, [sp, #0x14]
	lsls r0, r1, #0x10
	asrs r6, r0, #0x10
.L08092B20:
	lsls r0, r2, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #4
	subs r0, r0, r4
	lsls r0, r0, #4
	ldr r2, .L08092CD4 @ =0x0600A000
	adds r3, r0, r2
	adds r1, r7, r4
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r6
	ldr r1, .L08092CD0 @ =0x02000000
	adds r1, r0, r1
	mov r2, sb
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge .L08092B48
	adds r0, #3
.L08092B48:
	lsls r2, r0, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r1, #0
	adds r1, r3, #0
	bl CpuSet
	adds r1, r4, #1
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	lsls r0, r5, #0x10
	cmp r1, r0
	blt .L08092B20
.L08092B66:
	movs r0, #2
	movs r1, #0
	bl func_fe6_08092278
	ldr r1, .L08092CD0 @ =0x02000000
	bl Decompress
	lsls r0, r5, #0x10
	movs r2, #0
	adds r5, r0, #0
	mov r4, r8
	lsls r6, r4, #0x10
	cmp r5, #0
	ble .L08092BDE
	mov r1, sb
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	ldr r4, .L08092CD4 @ =0x0600A000
	adds r4, r4, r0
	mov r8, r4
	ldr r1, [sp, #8]
	lsls r0, r1, #0x10
	asrs r7, r0, #0x10
.L08092B94:
	lsls r0, r2, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #4
	subs r0, r0, r4
	lsls r0, r0, #4
	mov r2, r8
	adds r3, r0, r2
	adds r0, r7, r4
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #4
	mov r2, sl
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	ldr r0, .L08092CD0 @ =0x02000000
	adds r1, r1, r0
	ldr r2, [sp, #0x14]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge .L08092BC2
	adds r0, #3
.L08092BC2:
	lsls r2, r0, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r1, #0
	adds r1, r3, #0
	bl CpuSet
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, r5
	blt .L08092B94
.L08092BDE:
	movs r0, #3
	movs r1, #0
	bl func_fe6_08092278
	ldr r1, .L08092CD0 @ =0x02000000
	bl Decompress
	movs r2, #0
	cmp r6, #0
	ble .L08092C4A
	ldr r4, [sp, #0xc]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	ldr r1, [sp]
	lsls r0, r1, #0x10
	asrs r7, r0, #0x10
.L08092C00:
	asrs r1, r5, #0x10
	lsls r0, r2, #0x10
	asrs r4, r0, #0x10
	adds r1, r1, r4
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	ldr r2, .L08092CD4 @ =0x0600A000
	adds r3, r0, r2
	mov r0, r8
	adds r1, r0, r4
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r7
	ldr r1, .L08092CD0 @ =0x02000000
	adds r1, r0, r1
	mov r2, sb
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge .L08092C2E
	adds r0, #3
.L08092C2E:
	lsls r2, r0, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r1, #0
	adds r1, r3, #0
	bl CpuSet
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, r6
	blt .L08092C00
.L08092C4A:
	movs r0, #4
	movs r1, #0
	bl func_fe6_08092278
	ldr r1, .L08092CD0 @ =0x02000000
	bl Decompress
	movs r2, #0
	cmp r6, #0
	ble .L08092CBE
	mov r4, sb
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ldr r1, .L08092CD4 @ =0x0600A000
	adds r1, r1, r0
	mov r8, r1
	ldr r4, [sp, #0x10]
	lsls r0, r4, #0x10
	asrs r7, r0, #0x10
.L08092C70:
	asrs r1, r5, #0x10
	lsls r0, r2, #0x10
	asrs r4, r0, #0x10
	adds r1, r1, r4
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	mov r1, r8
	adds r3, r0, r1
	adds r0, r7, r4
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #4
	ldr r2, [sp, #4]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	ldr r0, .L08092CD0 @ =0x02000000
	adds r1, r1, r0
	ldr r2, [sp, #0x14]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge .L08092CA2
	adds r0, #3
.L08092CA2:
	lsls r2, r0, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r1, #0
	adds r1, r3, #0
	bl CpuSet
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, r6
	blt .L08092C70
.L08092CBE:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08092CD0: .4byte 0x02000000
.L08092CD4: .4byte 0x0600A000

	thumb_func_start func_fe6_08092CD8
func_fe6_08092CD8: @ 0x08092CD8
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, .L08092CF4 @ =gUnk_0868C3EC
	bl SpawnProc
	adds r4, r0, #0
	ldr r0, .L08092CF8 @ =gUnk_0868C324
	bl FindProc
	str r0, [r4, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08092CF4: .4byte gUnk_0868C3EC
.L08092CF8: .4byte gUnk_0868C324

	thumb_func_start func_fe6_08092CFC
func_fe6_08092CFC: @ 0x08092CFC
	adds r2, r0, #0
	adds r2, #0x66
	movs r1, #0
	strh r1, [r2]
	adds r0, #0x68
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08092D0C
func_fe6_08092D0C: @ 0x08092D0C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov r8, r0
	ldr r5, [r0, #0x4c]
	adds r0, #0x66
	movs r1, #0
	ldrsh r4, [r0, r1]
	cmp r4, #0
	beq .L08092D32
	cmp r4, #1
	beq .L08092DE8
	adds r7, r5, #0
	adds r7, #0x48
	adds r6, r5, #0
	adds r6, #0x4a
	b .L08092E36
.L08092D32:
	mov r0, r8
	adds r0, #0x68
	movs r6, #1
	ldrh r3, [r0]
	ands r6, r3
	mov sb, r0
	cmp r6, #0
	beq .L08092D7C
	movs r0, #1
	movs r1, #1
	bl func_fe6_0809228C
	str r4, [r5, #0x2c]
	str r4, [r5, #0x30]
	movs r0, #0xf0
	lsls r0, r0, #7
	str r0, [r5, #0x34]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [r5, #0x38]
	str r4, [r5, #0x44]
	adds r3, r5, #0
	adds r3, #0x48
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r3]
	adds r2, r5, #0
	adds r2, #0x4a
	strh r0, [r2]
	ldr r1, .L08092D78 @ =gDispIo
	movs r0, #0x10
	ldrb r4, [r1]
	orrs r0, r4
	b .L08092DB4
	.align 2, 0
.L08092D78: .4byte gDispIo
.L08092D7C:
	movs r0, #0
	movs r1, #1
	bl func_fe6_0809228C
	str r6, [r5, #0x2c]
	str r6, [r5, #0x30]
	ldr r0, [r5, #0x3c]
	ldr r1, .L08092DDC @ =0xFFFF8800
	adds r0, r0, r1
	str r0, [r5, #0x34]
	ldr r0, [r5, #0x40]
	ldr r3, .L08092DE0 @ =0xFFFFB000
	adds r0, r0, r3
	str r0, [r5, #0x38]
	str r6, [r5, #0x44]
	adds r3, r5, #0
	adds r3, #0x48
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r3]
	adds r2, r5, #0
	adds r2, #0x4a
	strh r0, [r2]
	ldr r1, .L08092DE4 @ =gDispIo
	movs r0, #0x11
	rsbs r0, r0, #0
	ldrb r4, [r1]
	ands r0, r4
.L08092DB4:
	strb r0, [r1]
	adds r7, r3, #0
	adds r6, r2, #0
	mov r1, sb
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bne .L08092E36
	mov r0, r8
	adds r0, #0x66
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r0, #0
	mov r3, sb
	strh r0, [r3]
	b .L08092E36
	.align 2, 0
.L08092DDC: .4byte 0xFFFF8800
.L08092DE0: .4byte 0xFFFFB000
.L08092DE4: .4byte gDispIo
.L08092DE8:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0x80
	lsls r2, r2, #1
	mov r4, r8
	adds r4, #0x68
	movs r0, #0
	ldrsh r3, [r4, r0]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #5
	bl Interpolate
	adds r2, r5, #0
	adds r2, #0x4a
	strh r0, [r2]
	adds r1, r5, #0
	adds r1, #0x48
	strh r0, [r1]
	ldr r0, [r5, #0x3c]
	ldr r3, .L08092E60 @ =0xFFFF8800
	adds r0, r0, r3
	str r0, [r5, #0x34]
	ldr r0, [r5, #0x40]
	ldr r3, .L08092E64 @ =0xFFFFB000
	adds r0, r0, r3
	str r0, [r5, #0x38]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r7, r1, #0
	adds r6, r2, #0
	cmp r0, #0x21
	bne .L08092E36
	mov r0, r8
	bl Proc_Break
.L08092E36:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	ldr r2, [r5, #0x34]
	ldr r3, [r5, #0x38]
	ldr r4, [r5, #0x44]
	str r4, [sp]
	movs r5, #0
	ldrsh r4, [r7, r5]
	str r4, [sp, #4]
	movs r5, #0
	ldrsh r4, [r6, r5]
	str r4, [sp, #8]
	bl func_fe6_08092EB0
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08092E60: .4byte 0xFFFF8800
.L08092E64: .4byte 0xFFFFB000

	thumb_func_start func_fe6_08092E68
func_fe6_08092E68: @ 0x08092E68
	push {lr}
	ldr r0, .L08092E84 @ =gUnk_0868C3C4
	bl FindProc
	cmp r0, #0
	bne .L08092E8C
	ldr r0, .L08092E88 @ =gUnk_0868C3EC
	bl FindProc
	cmp r0, #0
	bne .L08092E8C
	movs r0, #0
	b .L08092E8E
	.align 2, 0
.L08092E84: .4byte gUnk_0868C3C4
.L08092E88: .4byte gUnk_0868C3EC
.L08092E8C:
	movs r0, #1
.L08092E8E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08092E94
func_fe6_08092E94: @ 0x08092E94
	push {lr}
	ldr r0, .L08092EA8 @ =gUnk_0868C3C4
	bl Proc_EndEach
	ldr r0, .L08092EAC @ =gUnk_0868C3EC
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
.L08092EA8: .4byte gUnk_0868C3C4
.L08092EAC: .4byte gUnk_0868C3EC

	thumb_func_start func_fe6_08092EB0
func_fe6_08092EB0: @ 0x08092EB0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov sl, r1
	adds r6, r2, #0
	mov r8, r3
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	ldr r2, [sp, #0x30]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #4]
	movs r1, #0x20
	bl Div
	adds r5, r0, #0
	movs r1, #2
	bl Div
	adds r4, r0, #0
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L08092F18
	ldr r2, .L08092F10 @ =gUnk_08353328
	ldr r3, .L08092F14 @ =0x000003FF
	adds r1, r4, #0
	ands r1, r3
	lsls r1, r1, #2
	adds r1, r1, r2
	adds r0, r4, #1
	ands r0, r3
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, [r1]
	ldr r0, [r0]
	adds r1, r1, r0
	asrs r7, r1, #1
	adds r3, r2, #0
	b .L08092F26
	.align 2, 0
.L08092F10: .4byte gUnk_08353328
.L08092F14: .4byte 0x000003FF
.L08092F18:
	ldr r1, .L08092F50 @ =gUnk_08353328
	ldr r0, .L08092F54 @ =0x000003FF
	ands r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r7, [r0]
	adds r3, r1, #0
.L08092F26:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L08092F5C
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r2, .L08092F54 @ =0x000003FF
	ands r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldr r5, .L08092F58 @ =0x00000101
	adds r0, r4, r5
	ands r0, r2
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r1, [r1]
	ldr r0, [r0]
	adds r1, r1, r0
	asrs r5, r1, #1
	b .L08092F6C
	.align 2, 0
.L08092F50: .4byte gUnk_08353328
.L08092F54: .4byte 0x000003FF
.L08092F58: .4byte 0x00000101
.L08092F5C:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, .L08093050 @ =0x000003FF
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r5, [r0]
.L08092F6C:
	mov r0, sb
	cmp r0, #0
	bge .L08092F74
	adds r0, #0xff
.L08092F74:
	asrs r0, r0, #8
	mov sb, r0
	mov r0, sl
	cmp r0, #0
	bge .L08092F80
	adds r0, #0xff
.L08092F80:
	asrs r0, r0, #8
	mov sl, r0
	adds r0, r6, #0
	cmp r6, #0
	bge .L08092F8C
	adds r0, #0xff
.L08092F8C:
	asrs r6, r0, #8
	mov r0, r8
	cmp r0, #0
	bge .L08092F96
	adds r0, #0xff
.L08092F96:
	asrs r0, r0, #8
	mov r8, r0
	ldr r4, .L08093054 @ =gDispIo
	ldr r2, [sp]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #9
	bl __divsi3
	adds r1, r0, #0
	adds r0, r1, #0
	muls r0, r5, r0
	cmp r0, #0
	bge .L08092FB6
	adds r0, #0xff
.L08092FB6:
	asrs r0, r0, #0xf
	ldr r3, .L08093058 @ =gDispIo+0x48
	strh r0, [r3]
	adds r0, r1, #0
	muls r0, r7, r0
	cmp r0, #0
	bge .L08092FC6
	adds r0, #0xff
.L08092FC6:
	asrs r0, r0, #0xf
	ldr r1, .L0809305C @ =gDispIo+0x4A
	strh r0, [r1]
	ldr r2, [sp, #4]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #9
	bl __divsi3
	adds r1, r0, #0
	adds r0, r1, #0
	muls r0, r7, r0
	cmp r0, #0
	bge .L08092FE6
	adds r0, #0xff
.L08092FE6:
	asrs r0, r0, #0xf
	rsbs r0, r0, #0
	movs r3, #0x4c
	adds r3, r3, r4
	mov ip, r3
	strh r0, [r3]
	adds r0, r1, #0
	muls r0, r5, r0
	cmp r0, #0
	bge .L08092FFC
	adds r0, #0xff
.L08092FFC:
	asrs r0, r0, #0xf
	ldr r5, .L08093060 @ =gDispIo+0x4E
	strh r0, [r5]
	ldr r7, .L08093058 @ =gDispIo+0x48
	movs r1, #0
	ldrsh r0, [r7, r1]
	mov r2, sb
	subs r3, r2, r6
	adds r1, r0, #0
	muls r1, r3, r1
	ldr r5, .L0809305C @ =gDispIo+0x4A
	movs r7, #0
	ldrsh r0, [r5, r7]
	mov r5, sl
	mov r7, r8
	subs r2, r5, r7
	muls r0, r2, r0
	adds r1, r1, r0
	lsls r0, r6, #8
	adds r1, r1, r0
	str r1, [r4, #0x50]
	mov r1, ip
	movs r5, #0
	ldrsh r0, [r1, r5]
	muls r0, r3, r0
	ldr r7, .L08093060 @ =gDispIo+0x4E
	movs r3, #0
	ldrsh r1, [r7, r3]
	muls r1, r2, r1
	adds r0, r0, r1
	mov r5, r8
	lsls r1, r5, #8
	adds r0, r0, r1
	str r0, [r4, #0x54]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08093050: .4byte 0x000003FF
.L08093054: .4byte gDispIo
.L08093058: .4byte gDispIo+0x48
.L0809305C: .4byte gDispIo+0x4A
.L08093060: .4byte gDispIo+0x4E

	thumb_func_start func_fe6_08093064
func_fe6_08093064: @ 0x08093064
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r6, .L080930CC @ =gUnk_08353328
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, .L080930D0 @ =0x000003FF
	ands r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r1, [r1]
	mov r8, r1
	mov r1, r8
	muls r1, r4, r1
	lsls r1, r1, #1
	asrs r1, r1, #0x10
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	ands r3, r2
	lsls r3, r3, #2
	adds r3, r3, r6
	ldr r3, [r3]
	adds r2, r5, #0
	muls r2, r3, r2
	lsls r2, r2, #1
	asrs r2, r2, #0x10
	muls r3, r4, r3
	asrs r3, r3, #0xf
	rsbs r3, r3, #0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	mov r4, r8
	muls r4, r5, r4
	lsls r4, r4, #1
	asrs r4, r4, #0x10
	str r4, [sp]
	bl PutSpriteAffine
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080930CC: .4byte gUnk_08353328
.L080930D0: .4byte 0x000003FF

	thumb_func_start StartWorldMapIntroScen
StartWorldMapIntroScen: @ 0x080930D4
	push {r4, r5, lr}
	ldr r5, .L0809310C @ =ChapterAssets
	ldr r4, .L08093110 @ =gPlaySt
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	bl GetChapterInfo
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	cmp r0, #0
	beq .L08093106
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	bl GetChapterInfo
	adds r0, #0x3b
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	bl StartEvent
.L08093106:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0809310C: .4byte ChapterAssets
.L08093110: .4byte gPlaySt

	thumb_func_start func_fe6_08093114
func_fe6_08093114: @ 0x08093114
	push {lr}
	movs r0, #4
	bl FadeBgmOut
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08093120
func_fe6_08093120: @ 0x08093120
	push {lr}
	movs r0, #1
	bl FadeBgmOut
	pop {r0}
	bx r0

	thumb_func_start SetWMFlag
SetWMFlag: @ 0x0809312C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L0809314C @ =gUnk_0868C648
	bl FindProc
	cmp r0, #0
	beq .L08093144
	lsls r1, r4, #2
	adds r0, #0x30
	adds r0, r0, r1
	str r5, [r0]
.L08093144:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0809314C: .4byte gUnk_0868C648

	thumb_func_start GetWMFlag
GetWMFlag: @ 0x08093150
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08093164 @ =gUnk_0868C648
	bl FindProc
	adds r1, r0, #0
	cmp r1, #0
	bne .L08093168
	movs r0, #0
	b .L08093170
	.align 2, 0
.L08093164: .4byte gUnk_0868C648
.L08093168:
	lsls r0, r4, #2
	adds r1, #0x30
	adds r1, r1, r0
	ldr r0, [r1]
.L08093170:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start SetWMDot
SetWMDot: @ 0x08093178
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08093198 @ =gUnk_0868C648
	bl FindProc
	cmp r0, #0
	beq .L08093190
	lsls r1, r4, #2
	adds r0, #0x40
	adds r0, r0, r1
	str r5, [r0]
.L08093190:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08093198: .4byte gUnk_0868C648

	thumb_func_start GetWMDot
GetWMDot: @ 0x0809319C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080931B0 @ =gUnk_0868C648
	bl FindProc
	adds r1, r0, #0
	cmp r1, #0
	bne .L080931B4
	movs r0, #0
	b .L080931BC
	.align 2, 0
.L080931B0: .4byte gUnk_0868C648
.L080931B4:
	lsls r0, r4, #2
	adds r1, #0x40
	adds r1, r1, r0
	ldr r0, [r1]
.L080931BC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start SetWMHighlight
SetWMHighlight: @ 0x080931C4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L080931E4 @ =gUnk_0868C648
	bl FindProc
	cmp r0, #0
	beq .L080931DC
	lsls r1, r4, #2
	adds r0, #0x48
	adds r0, r0, r1
	str r5, [r0]
.L080931DC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080931E4: .4byte gUnk_0868C648

	thumb_func_start GetWMHighlight
GetWMHighlight: @ 0x080931E8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080931FC @ =gUnk_0868C648
	bl FindProc
	adds r1, r0, #0
	cmp r1, #0
	bne .L08093200
	movs r0, #0
	b .L08093208
	.align 2, 0
.L080931FC: .4byte gUnk_0868C648
.L08093200:
	lsls r0, r4, #2
	adds r1, #0x48
	adds r1, r1, r0
	ldr r0, [r1]
.L08093208:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start SetWMMapText
SetWMMapText: @ 0x08093210
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08093230 @ =gUnk_0868C648
	bl FindProc
	cmp r0, #0
	beq .L08093228
	lsls r1, r4, #2
	adds r0, #0x50
	adds r0, r0, r1
	str r5, [r0]
.L08093228:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08093230: .4byte gUnk_0868C648

	thumb_func_start GetWMMapText
GetWMMapText: @ 0x08093234
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08093248 @ =gUnk_0868C648
	bl FindProc
	adds r1, r0, #0
	cmp r1, #0
	bne .L0809324C
	movs r0, #0
	b .L08093254
	.align 2, 0
.L08093248: .4byte gUnk_0868C648
.L0809324C:
	lsls r0, r4, #2
	adds r1, #0x50
	adds r1, r1, r0
	ldr r0, [r1]
.L08093254:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0809325C
func_fe6_0809325C: @ 0x0809325C
	ldr r1, .L08093280 @ =gUnk_0868C414
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r1
	ldr r0, [r2]
	ldrh r3, [r0]
	lsrs r1, r3, #1
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r2, [r2, #8]
	lsls r1, r2, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	lsrs r1, r1, #1
	lsls r1, r1, #1
	adds r0, r0, r1
	bx lr
	.align 2, 0
.L08093280: .4byte gUnk_0868C414

	thumb_func_start func_fe6_08093284
func_fe6_08093284: @ 0x08093284
	ldrh r0, [r0]
	bx lr

	thumb_func_start func_fe6_08093288
func_fe6_08093288: @ 0x08093288
	push {r4, lr}
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #1
	adds r2, r2, r0
	ldr r4, .L080932CC @ =0x000001FF
	ldrh r2, [r2, #4]
	ands r4, r2
	ldr r0, .L080932D0 @ =gUnk_0868C648
	bl FindProc
	adds r1, r0, #0
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq .L080932AE
	ldr r0, .L080932D4 @ =0xFFFFFE00
	orrs r4, r0
.L080932AE:
	adds r0, r1, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080932C2
	adds r0, r4, #0
	movs r1, #2
	bl Div
	adds r4, r0, #0
.L080932C2:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L080932CC: .4byte 0x000001FF
.L080932D0: .4byte gUnk_0868C648
.L080932D4: .4byte 0xFFFFFE00

	thumb_func_start func_fe6_080932D8
func_fe6_080932D8: @ 0x080932D8
	push {r4, lr}
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #1
	adds r2, r2, r0
	ldrb r4, [r2, #2]
	ldr r0, .L08093314 @ =gUnk_0868C648
	bl FindProc
	adds r1, r0, #0
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq .L080932F8
	ldr r0, .L08093318 @ =0xFFFFFF00
	orrs r4, r0
.L080932F8:
	adds r0, r1, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0809330C
	adds r0, r4, #0
	movs r1, #2
	bl Div
	adds r4, r0, #0
.L0809330C:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L08093314: .4byte gUnk_0868C648
.L08093318: .4byte 0xFFFFFF00

	thumb_func_start func_fe6_0809331C
func_fe6_0809331C: @ 0x0809331C
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0x2a]
	strh r0, [r3, #0x2c]
	adds r0, r3, #0
	adds r0, #0x2e
	strb r1, [r0]
	ldr r6, .L08093388 @ =gUnk_0868C658
	movs r4, #0
	movs r2, #3
	adds r1, r3, #0
	adds r1, #0x3c
.L08093338:
	str r4, [r1]
	subs r1, #4
	subs r2, #1
	cmp r2, #0
	bge .L08093338
	adds r4, r3, #0
	adds r4, #0x50
	adds r5, r3, #0
	adds r5, #0x48
	adds r2, r3, #0
	adds r2, #0x40
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0x44
.L08093354:
	str r0, [r1]
	subs r1, #4
	cmp r1, r2
	bge .L08093354
	adds r2, r4, #0
	movs r0, #0
	adds r1, r2, #4
.L08093362:
	str r0, [r1]
	subs r1, #4
	cmp r1, r2
	bge .L08093362
	adds r2, r5, #0
	movs r0, #0
	adds r1, r2, #4
.L08093370:
	str r0, [r1]
	subs r1, #4
	cmp r1, r2
	bge .L08093370
	adds r0, r6, #0
	adds r1, r3, #0
	bl SpawnProc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08093388: .4byte gUnk_0868C658

	thumb_func_start func_fe6_0809338C
func_fe6_0809338C: @ 0x0809338C
	adds r0, #0x64
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start func_fe6_08093394
func_fe6_08093394: @ 0x08093394
	push {r4, lr}
	sub sp, #0x38
	adds r4, r0, #0
	ldr r1, .L080933EC @ =gUnk_08354728
	mov r0, sp
	movs r2, #0x37
	bl memcpy
	adds r4, #0x64
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	add r0, sp
	ldrb r0, [r0]
	cmp r0, #0xff
	bne .L080933BC
	movs r0, #0
	strh r0, [r4]
.L080933BC:
	movs r1, #0
	ldrsh r0, [r4, r1]
	add r0, sp
	ldrb r0, [r0]
	lsls r4, r0, #5
	ldr r0, .L080933F0 @ =gUnk_082D37E4
	adds r0, r4, r0
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L080933F4 @ =gUnk_082D3764
	adds r4, r4, r0
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r4, #0
	movs r2, #0x20
	bl ApplyPaletteExt
	add sp, #0x38
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080933EC: .4byte gUnk_08354728
.L080933F0: .4byte gUnk_082D37E4
.L080933F4: .4byte gUnk_082D3764

	thumb_func_start func_fe6_080933F8
func_fe6_080933F8: @ 0x080933F8
	push {lr}
	ldr r0, .L08093430 @ =gUnk_082D33B8
	ldr r1, .L08093434 @ =0x06016200
	bl Decompress
	ldr r0, .L08093438 @ =gUnk_082D36E4
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0x80
	bl ApplyPaletteExt
	ldr r0, .L0809343C @ =gUnk_082D3864
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r2, #0x40
	bl ApplyPaletteExt
	bl func_fe6_08092838
	ldr r0, .L08093440 @ =gUnk_0868C648
	movs r1, #3
	bl SpawnProc
	bl func_fe6_080934A0
	pop {r0}
	bx r0
	.align 2, 0
.L08093430: .4byte gUnk_082D33B8
.L08093434: .4byte 0x06016200
.L08093438: .4byte gUnk_082D36E4
.L0809343C: .4byte gUnk_082D3864
.L08093440: .4byte gUnk_0868C648

	thumb_func_start func_fe6_08093444
func_fe6_08093444: @ 0x08093444
	push {lr}
	ldr r0, .L08093458 @ =gUnk_0868C648
	bl FindProc
	cmp r0, #0
	beq .L08093452
	movs r0, #1
.L08093452:
	pop {r1}
	bx r1
	.align 2, 0
.L08093458: .4byte gUnk_0868C648

	thumb_func_start func_fe6_0809345C
func_fe6_0809345C: @ 0x0809345C
	push {lr}
	movs r0, #8
	bl Proc_EndEachMarked
	bl EndEachSpriteAnimProc
	bl EndPutTalkSpriteText
	ldr r0, .L08093478 @ =gUnk_0868C648
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
.L08093478: .4byte gUnk_0868C648

	thumb_func_start func_fe6_0809347C
func_fe6_0809347C: @ 0x0809347C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L0809349C @ =gUnk_0868C648
	bl FindProc
	subs r4, #0x78
	strh r4, [r0, #0x2a]
	subs r5, #0x50
	strh r5, [r0, #0x2c]
	adds r0, #0x2e
	movs r1, #1
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0809349C: .4byte gUnk_0868C648

	thumb_func_start func_fe6_080934A0
func_fe6_080934A0: @ 0x080934A0
	push {lr}
	ldr r0, .L080934B8 @ =gUnk_0868C648
	bl FindProc
	movs r2, #0
	movs r1, #0
	strh r1, [r0, #0x2a]
	strh r1, [r0, #0x2c]
	adds r0, #0x2e
	strb r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
.L080934B8: .4byte gUnk_0868C648

	thumb_func_start func_fe6_080934BC
func_fe6_080934BC: @ 0x080934BC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, .L08093510 @ =gUnk_0868C648
	bl FindProc
	lsls r1, r5, #1
	adds r1, r1, r5
	lsls r1, r1, #2
	ldr r2, .L08093514 @ =gUnk_0868C414
	adds r2, r1, r2
	movs r3, #4
	ldrsh r1, [r2, r3]
	ldrh r7, [r0, #0x2a]
	subs r4, r1, r7
	movs r3, #6
	ldrsh r1, [r2, r3]
	ldrh r7, [r0, #0x2c]
	subs r3, r1, r7
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080934F4
	asrs r4, r4, #1
	asrs r3, r3, #1
	subs r4, #2
	subs r3, #2
.L080934F4:
	ldrh r0, [r2, #0xa]
	str r0, [sp]
	ldrb r2, [r2, #9]
	lsls r0, r2, #8
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_fe6_080923C8
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08093510: .4byte gUnk_0868C648
.L08093514: .4byte gUnk_0868C414

	thumb_func_start func_fe6_08093518
func_fe6_08093518: @ 0x08093518
	push {lr}
	ldr r0, .L08093554 @ =gUnk_082D33B8
	ldr r1, .L08093558 @ =0x06016200
	bl Decompress
	ldr r0, .L0809355C @ =gUnk_082D36E4
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0x80
	bl ApplyPaletteExt
	ldr r0, .L08093560 @ =Pal_SystemObjects
	movs r1, #0xd8
	lsls r1, r1, #2
	movs r2, #0x40
	bl ApplyPaletteExt
	ldr r0, .L08093564 @ =gUnk_082AA9A8
	ldr r1, .L08093568 @ =0x06016800
	bl Decompress
	ldr r0, .L0809356C @ =gUnk_082AAD5C
	movs r1, #0xc8
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	pop {r0}
	bx r0
	.align 2, 0
.L08093554: .4byte gUnk_082D33B8
.L08093558: .4byte 0x06016200
.L0809355C: .4byte gUnk_082D36E4
.L08093560: .4byte Pal_SystemObjects
.L08093564: .4byte gUnk_082AA9A8
.L08093568: .4byte 0x06016800
.L0809356C: .4byte gUnk_082AAD5C

	thumb_func_start StartWMIntroRotation
StartWMIntroRotation: @ 0x08093570
	push {lr}
	adds r1, r0, #0
	ldr r0, .L08093580 @ =gUnk_0868C668
	bl SpawnProcLocking
	pop {r0}
	bx r0
	.align 2, 0
.L08093580: .4byte gUnk_0868C668

	thumb_func_start func_fe6_08093584
func_fe6_08093584: @ 0x08093584
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0x44
	movs r2, #0
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1]
	adds r1, #4
	movs r0, #0x80
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x64
	strh r2, [r0]
	bx lr

	thumb_func_start func_fe6_080935A0
func_fe6_080935A0: @ 0x080935A0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r7, r0, #0
	movs r1, #0x80
	lsls r1, r1, #8
	adds r4, r7, #0
	adds r4, #0x64
	movs r0, #0
	ldrsh r3, [r4, r0]
	movs r5, #0x23
	str r5, [sp]
	movs r0, #5
	movs r2, #0
	bl Interpolate
	adds r6, r0, #0
	movs r1, #0x80
	lsls r1, r1, #3
	movs r2, #0x80
	lsls r2, r2, #1
	ldrh r3, [r4]
	adds r0, r3, #1
	strh r0, [r4]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	str r5, [sp]
	movs r0, #5
	bl Interpolate
	movs r2, #0xf0
	lsls r2, r2, #7
	movs r3, #0xa0
	lsls r3, r3, #7
	str r6, [sp]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	bl func_fe6_08092EB0
	ldrh r4, [r4]
	cmp r4, #0x28
	bne .L08093600
	adds r0, r7, #0
	bl Proc_Break
.L08093600:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08093608
func_fe6_08093608: @ 0x08093608
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	movs r0, #0x64
	add sb, r0
	movs r0, #0
	mov r1, sb
	strh r0, [r1]
	bl InitScanlineEffect
	bl func_fe6_08069C74
	ldr r2, .L080936E0 @ =gDispIo+0x3C
	mov ip, r2
	ldr r0, .L080936E4 @ =0x0000FFE0
	ldrh r3, [r2]
	ands r0, r3
	movs r1, #0x1f
	orrs r0, r1
	strh r0, [r2]
	subs r2, #0x3c
	movs r4, #0x20
	mov r6, ip
	ldrb r0, [r6]
	orrs r0, r4
	strb r0, [r6]
	ldrb r0, [r2, #1]
	orrs r0, r4
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	movs r0, #8
	rsbs r0, r0, #0
	add r0, ip
	mov sl, r0
	ldrb r0, [r0]
	orrs r0, r4
	mov r1, sl
	strb r0, [r1]
	mov r7, ip
	subs r7, #6
	movs r2, #0x21
	rsbs r2, r2, #0
	adds r0, r2, #0
	ldrb r3, [r7]
	ands r0, r3
	strb r0, [r7]
	movs r1, #1
	mov r6, sl
	ldrb r0, [r6]
	orrs r0, r1
	movs r3, #2
	mov r8, r3
	mov r6, r8
	orrs r0, r6
	movs r3, #4
	orrs r0, r3
	movs r5, #8
	orrs r0, r5
	movs r3, #0x10
	orrs r0, r3
	mov r6, sl
	strb r0, [r6]
	ldrb r0, [r7]
	orrs r1, r0
	mov r6, r8
	orrs r1, r6
	movs r0, #4
	orrs r1, r0
	orrs r1, r5
	orrs r1, r3
	strb r1, [r7]
	mov r1, sl
	ldrb r1, [r1]
	orrs r4, r1
	mov r3, sl
	strb r4, [r3]
	ldrb r6, [r7]
	ands r2, r6
	strb r2, [r7]
	movs r0, #0x3f
	mov r1, ip
	ldrb r1, [r1]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	mov r2, ip
	strb r0, [r2]
	movs r3, #0
	strb r3, [r2, #8]
	strb r3, [r2, #9]
	mov r6, sb
	ldrh r0, [r6]
	strb r0, [r2, #0xa]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080936E0: .4byte gDispIo+0x3C
.L080936E4: .4byte 0x0000FFE0

	thumb_func_start func_fe6_080936E8
func_fe6_080936E8: @ 0x080936E8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x64
	movs r0, #0
	ldrsh r3, [r4, r0]
	movs r0, #0x2d
	str r0, [sp]
	movs r0, #5
	movs r1, #1
	movs r2, #0xc8
	bl Interpolate
	adds r2, r0, #0
	movs r0, #0x78
	movs r1, #0x50
	bl func_fe6_08069DA4
	ldr r5, .L08093760 @ =gDispIo
	adds r2, r5, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x44
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
	ldrsh r3, [r4, r0]
	movs r0, #0x28
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r1, r5, #0
	adds r1, #0x46
	strb r0, [r1]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	bne .L08093758
	adds r0, r6, #0
	bl Proc_Break
.L08093758:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08093760: .4byte gDispIo

	thumb_func_start func_fe6_08093764
func_fe6_08093764: @ 0x08093764
	push {r4, lr}
	ldr r4, .L080937A8 @ =gDispIo
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	adds r1, #8
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x45
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	movs r0, #0
	bl SetOnHBlankA
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r4, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r4, #1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080937A8: .4byte gDispIo

	thumb_func_start StartWMHighlight
StartWMHighlight: @ 0x080937AC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, .L080937D0 @ =gUnk_0868C704
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	adds r0, #0x64
	strh r5, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, r4, #0
	bl SetWMHighlight
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080937D0: .4byte gUnk_0868C704

	thumb_func_start func_fe6_080937D4
func_fe6_080937D4: @ 0x080937D4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r7, .L0809389C @ =gUnk_0868C6B0
	adds r4, r5, #0
	adds r4, #0x64
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldr r2, [r1]
	adds r6, r5, #0
	adds r6, #0x66
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r1, .L080938A0 @ =0x06015100
	cmp r0, #0
	bne .L080937FC
	ldr r1, .L080938A4 @ =0x06014000
.L080937FC:
	adds r0, r2, #0
	bl Decompress
	ldr r0, .L080938A8 @ =gUnk_082D3398
	movs r1, #0xd0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r7, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xd
	bl StartSpriteAnim
	adds r1, r0, #0
	str r1, [r5, #0x50]
	movs r4, #0
	ldrsh r0, [r6, r4]
	ldr r2, .L080938AC @ =0x0000A288
	adds r4, r2, #0
	cmp r0, #0
	bne .L0809383A
	movs r0, #0xa2
	lsls r0, r0, #8
	adds r4, r0, #0
.L0809383A:
	movs r2, #0
	movs r3, #0
	strh r4, [r1, #0x22]
	ldr r1, .L080938B0 @ =gDispIo
	mov ip, r1
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r4, [r1]
	ands r0, r4
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x44
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x46
	strb r2, [r0]
	ldr r0, .L080938B4 @ =0x0000FFE0
	mov r1, ip
	ldrh r1, [r1, #0x3c]
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	ldr r1, .L080938B8 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	mov r4, ip
	strh r0, [r4, #0x3c]
	mov r1, ip
	adds r1, #0x3d
	movs r0, #0x20
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	str r3, [r5, #0x54]
	adds r1, r5, #0
	adds r1, #0x44
	movs r0, #0xc0
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0809389C: .4byte gUnk_0868C6B0
.L080938A0: .4byte 0x06015100
.L080938A4: .4byte 0x06014000
.L080938A8: .4byte gUnk_082D3398
.L080938AC: .4byte 0x0000A288
.L080938B0: .4byte gDispIo
.L080938B4: .4byte 0x0000FFE0
.L080938B8: .4byte 0x0000E0FF

	thumb_func_start func_fe6_080938BC
func_fe6_080938BC: @ 0x080938BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, [r5, #0x50]
	ldr r2, .L08093954 @ =gUnk_0868C6B0
	adds r1, r5, #0
	adds r1, #0x64
	movs r3, #0
	ldrsh r1, [r1, r3]
	lsls r3, r1, #1
	adds r3, r3, r1
	lsls r3, r3, #2
	adds r3, r3, r2
	ldrb r1, [r3, #8]
	movs r2, #0x80
	lsls r2, r2, #3
	ldrb r3, [r3, #9]
	orrs r2, r3
	bl DisplaySpriteAnim
	ldr r1, .L08093958 @ =gSinLut
	adds r2, r5, #0
	adds r2, #0x44
	ldrb r7, [r2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #0xb
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r2]
	adds r0, #3
	movs r6, #0
	strh r0, [r2]
	ldr r1, .L0809395C @ =gDispIo
	adds r4, r1, #0
	adds r4, #0x3c
	movs r2, #0x3f
	ldrb r7, [r4]
	ands r2, r7
	strb r2, [r4]
	movs r0, #0x44
	adds r0, r0, r1
	mov r8, r0
	strb r3, [r0]
	movs r0, #0x10
	subs r0, r0, r3
	movs r7, #0x45
	adds r7, r7, r1
	strb r0, [r7]
	adds r1, #0x46
	strb r6, [r1]
	ldr r0, [r5, #0x54]
	cmp r0, #0
	beq .L08093948
	cmp r3, #2
	bne .L08093948
	strb r2, [r4]
	mov r0, r8
	strb r6, [r0]
	movs r0, #0x10
	strb r0, [r7]
	strb r6, [r1]
	adds r0, r5, #0
	bl Proc_End
.L08093948:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08093954: .4byte gUnk_0868C6B0
.L08093958: .4byte gSinLut
.L0809395C: .4byte gDispIo

	thumb_func_start func_fe6_08093960
func_fe6_08093960: @ 0x08093960
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	bl EndSpriteAnim
	adds r4, #0x66
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0
	bl SetWMHighlight
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0809397C
func_fe6_0809397C: @ 0x0809397C
	push {lr}
	bl GetWMHighlight
	cmp r0, #0
	beq .L0809398A
	bl Proc_End
.L0809398A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08093990
func_fe6_08093990: @ 0x08093990
	push {r4, lr}
	movs r4, #0
.L08093994:
	adds r0, r4, #0
	bl func_fe6_0809397C
	adds r4, #1
	cmp r4, #1
	ble .L08093994
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080939A8
func_fe6_080939A8: @ 0x080939A8
	push {lr}
	bl GetWMHighlight
	adds r1, r0, #0
	cmp r1, #0
	beq .L080939B8
	movs r0, #1
	str r0, [r1, #0x54]
.L080939B8:
	pop {r0}
	bx r0

	thumb_func_start WMHighlightExists
WMHighlightExists: @ 0x080939BC
	push {lr}
	bl GetWMHighlight
	cmp r0, #0
	bne .L080939CA
	movs r0, #0
	b .L080939CC
.L080939CA:
	movs r0, #1
.L080939CC:
	pop {r1}
	bx r1

	thumb_func_start func_fe6_080939D0
func_fe6_080939D0: @ 0x080939D0
	push {lr}
	movs r0, #0
	bl GetWMHighlight
	cmp r0, #0
	bne .L080939EA
	movs r0, #1
	bl GetWMHighlight
	cmp r0, #0
	bne .L080939EA
	movs r0, #0
	b .L080939EC
.L080939EA:
	movs r0, #1
.L080939EC:
	pop {r1}
	bx r1

	thumb_func_start func_fe6_080939F0
func_fe6_080939F0: @ 0x080939F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	mov r8, r2
	adds r7, r3, #0
	adds r0, r7, #0
	bl GetWMDot
	adds r6, r0, #0
	lsls r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r4, r4, #0x10
	orrs r4, r5
	str r4, [sp, #8]
	add r4, sp, #8
	adds r0, r4, #0
	bl func_fe6_08093FD8
	cmp r6, #0
	beq .L08093A34
	add r0, sp, #8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #2
	ldrsh r2, [r4, r3]
	movs r3, #0xc4
	lsls r3, r3, #2
	adds r0, r6, #0
	bl SetSpriteAnimProcParameters
	b .L08093A62
.L08093A34:
	ldr r0, .L08093A70 @ =gUnk_082D3674
	add r1, sp, #8
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #2
	ldrsh r2, [r4, r3]
	movs r3, #0xf
	mov r4, r8
	ands r3, r4
	lsls r3, r3, #0xc
	movs r4, #0xc4
	lsls r4, r4, #2
	orrs r3, r4
	movs r4, #1
	str r4, [sp]
	movs r4, #0xa
	str r4, [sp, #4]
	bl StartSpriteAnimProc
	adds r1, r0, #0
	adds r0, r7, #0
	bl SetWMDot
.L08093A62:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08093A70: .4byte gUnk_082D3674

	thumb_func_start EndWMDot
EndWMDot: @ 0x08093A74
	push {r4, lr}
	adds r4, r0, #0
	bl GetWMDot
	cmp r0, #0
	beq .L08093A84
	bl EndSpriteAnimProc
.L08093A84:
	adds r0, r4, #0
	movs r1, #0
	bl SetWMDot
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start StartWMFlag
StartWMFlag: @ 0x08093A94
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	mov r8, r3
	mov r0, r8
	bl GetWMFlag
	adds r6, r0, #0
	lsls r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r4, r4, #0x10
	orrs r4, r5
	str r4, [sp, #8]
	add r4, sp, #8
	adds r0, r4, #0
	bl func_fe6_08093FD8
	cmp r6, #0
	beq .L08093AE0
	add r0, sp, #8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #2
	ldrsh r2, [r4, r3]
	movs r3, #0xf
	ands r3, r7
	lsls r3, r3, #0xc
	movs r0, #0xc4
	lsls r0, r0, #2
	orrs r3, r0
	adds r0, r6, #0
	bl SetSpriteAnimProcParameters
	b .L08093B0A
.L08093AE0:
	ldr r0, .L08093B18 @ =gUnk_082D3674
	add r1, sp, #8
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #2
	ldrsh r2, [r4, r3]
	movs r3, #0xf
	ands r3, r7
	lsls r3, r3, #0xc
	movs r4, #0xc4
	lsls r4, r4, #2
	orrs r3, r4
	str r6, [sp]
	movs r4, #7
	str r4, [sp, #4]
	bl StartSpriteAnimProc
	adds r1, r0, #0
	mov r0, r8
	bl SetWMFlag
.L08093B0A:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08093B18: .4byte gUnk_082D3674

	thumb_func_start EndWMFlag
EndWMFlag: @ 0x08093B1C
	push {r4, lr}
	adds r4, r0, #0
	bl GetWMFlag
	cmp r0, #0
	beq .L08093B2C
	bl EndSpriteAnimProc
.L08093B2C:
	adds r0, r4, #0
	movs r1, #0
	bl SetWMFlag
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start StartWMMapText
StartWMMapText: @ 0x08093B3C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r2, #0
	mov r8, r3
	ldr r7, [sp, #0x1c]
	ldr r5, [sp, #0x20]
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	mov r4, sp
	mov r0, sp
	bl func_fe6_08093FD8
	ldr r0, .L08093B9C @ =gUnk_0868C8D8
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [r1, #0x2c]
	movs r2, #2
	ldrsh r0, [r4, r2]
	str r0, [r1, #0x30]
	adds r0, r1, #0
	adds r0, #0x64
	strh r6, [r0]
	adds r0, #2
	mov r2, r8
	strh r2, [r0]
	adds r0, #2
	strh r7, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r0, r5, #0
	bl SetWMMapText
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08093B9C: .4byte gUnk_0868C8D8

	thumb_func_start func_fe6_08093BA0
func_fe6_08093BA0: @ 0x08093BA0
	push {lr}
	bl GetWMMapText
	cmp r0, #0
	beq .L08093BAE
	bl Proc_End
.L08093BAE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08093BB4
func_fe6_08093BB4: @ 0x08093BB4
	push {lr}
	bl GetWMMapText
	adds r1, r0, #0
	cmp r1, #0
	beq .L08093BC4
	movs r0, #1
	str r0, [r1, #0x54]
.L08093BC4:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08093BC8
func_fe6_08093BC8: @ 0x08093BC8
	push {r4, r5, lr}
	adds r5, r1, #0
	ldr r4, .L08093C14 @ =gBuf
	adds r1, r4, #0
	bl Decompress
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #8
	movs r3, #4
	bl func_fe6_08015298
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #4
	movs r3, #4
	bl func_fe6_08015298
	movs r0, #0xc0
	lsls r0, r0, #3
	adds r4, r4, r0
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r5, r5, r1
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	movs r3, #4
	bl func_fe6_08015298
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08093C14: .4byte gBuf

	thumb_func_start func_fe6_08093C18
func_fe6_08093C18: @ 0x08093C18
	adds r2, r0, #0
	adds r2, #0x44
	movs r1, #0
	strh r1, [r2]
	str r1, [r0, #0x54]
	bx lr

	thumb_func_start func_fe6_08093C24
func_fe6_08093C24: @ 0x08093C24
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, .L08093C58 @ =gUnk_082D38A4
	movs r1, #0xb
	bl StartSpriteAnim
	str r0, [r4, #0x50]
	adds r2, r0, #0
	adds r0, r4, #0
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa2
	lsls r1, r1, #2
	cmp r0, #0
	bne .L08093C46
	subs r1, #0x88
.L08093C46:
	adds r0, r4, #0
	adds r0, #0x68
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne .L08093C5C
	movs r0, #0xa0
	lsls r0, r0, #7
	b .L08093C60
	.align 2, 0
.L08093C58: .4byte gUnk_082D38A4
.L08093C5C:
	movs r0, #0x80
	lsls r0, r0, #7
.L08093C60:
	orrs r0, r1
	strh r0, [r2, #0x22]
	ldr r2, .L08093C8C @ =gUnk_0868C734
	adds r3, r4, #0
	adds r3, #0x64
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #8
	adds r0, r0, r2
	ldr r1, [r0]
	ldr r0, .L08093C90 @ =gUnk_082D5910
	adds r5, r3, #0
	cmp r1, r0
	bne .L08093C94
	ldr r0, [r4, #0x50]
	movs r1, #1
	bl SetSpriteAnimId
	b .L08093C9C
	.align 2, 0
.L08093C8C: .4byte gUnk_0868C734
.L08093C90: .4byte gUnk_082D5910
.L08093C94:
	ldr r0, [r4, #0x50]
	movs r1, #2
	bl SetSpriteAnimId
.L08093C9C:
	ldr r6, .L08093D34 @ =gUnk_0868C734
	movs r2, #0
	ldrsh r1, [r5, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r6, #4
	adds r0, r0, r1
	ldr r2, [r0]
	adds r4, #0x6a
	movs r3, #0
	ldrsh r0, [r4, r3]
	ldr r1, .L08093D38 @ =0x06015100
	cmp r0, #0
	bne .L08093CBC
	ldr r1, .L08093D3C @ =0x06014000
.L08093CBC:
	adds r0, r2, #0
	bl func_fe6_08093BC8
	movs r0, #0
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r6, #0
	adds r1, #8
	adds r0, r0, r1
	ldr r3, [r0]
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, .L08093D40 @ =0x06015300
	cmp r0, #0
	bne .L08093CE0
	ldr r1, .L08093D44 @ =0x06014200
.L08093CE0:
	adds r0, r3, #0
	bl func_fe6_08093BC8
	ldr r2, .L08093D48 @ =gDispIo
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x44
	movs r1, #0
	strb r1, [r0]
	adds r3, r2, #0
	adds r3, #0x45
	movs r0, #0x10
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0x46
	strb r1, [r0]
	ldr r0, .L08093D4C @ =0x0000FFE0
	ldrh r1, [r2, #0x3c]
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	ldr r1, .L08093D50 @ =0x0000E0FF
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2, #0x3c]
	adds r1, r2, #0
	adds r1, #0x3d
	movs r0, #0x20
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08093D34: .4byte gUnk_0868C734
.L08093D38: .4byte 0x06015100
.L08093D3C: .4byte 0x06014000
.L08093D40: .4byte 0x06015300
.L08093D44: .4byte 0x06014200
.L08093D48: .4byte gDispIo
.L08093D4C: .4byte 0x0000FFE0
.L08093D50: .4byte 0x0000E0FF

	thumb_func_start func_fe6_08093D54
func_fe6_08093D54: @ 0x08093D54
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x2c]
	ldr r2, [r5, #0x30]
	movs r3, #0x80
	lsls r3, r3, #3
	orrs r2, r3
	adds r3, r5, #0
	adds r3, #0x64
	movs r4, #0
	ldrsh r3, [r3, r4]
	adds r4, r5, #0
	adds r4, #0x66
	movs r6, #0
	ldrsh r4, [r4, r6]
	str r4, [sp]
	adds r4, r5, #0
	adds r4, #0x68
	movs r6, #0
	ldrsh r4, [r4, r6]
	str r4, [sp, #4]
	bl func_fe6_08093EAC
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r1, #1
	movs r3, #0
	strh r1, [r0]
	ldr r4, .L08093DD0 @ =gDispIo
	adds r2, r4, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r6, [r2]
	ands r0, r6
	strb r0, [r2]
	adds r2, r1, #0
	adds r0, r4, #0
	adds r0, #0x44
	strb r2, [r0]
	movs r0, #0x10
	subs r0, r0, r2
	adds r2, r4, #0
	adds r2, #0x45
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x46
	strb r3, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xf
	ble .L08093DC6
	adds r0, r5, #0
	bl Proc_Break
.L08093DC6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08093DD0: .4byte gDispIo

	thumb_func_start func_fe6_08093DD4
func_fe6_08093DD4: @ 0x08093DD4
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x2c]
	ldr r2, [r5, #0x30]
	adds r3, r5, #0
	adds r3, #0x64
	movs r4, #0
	ldrsh r3, [r3, r4]
	adds r4, r5, #0
	adds r4, #0x66
	movs r6, #0
	ldrsh r4, [r4, r6]
	str r4, [sp]
	adds r4, r5, #0
	adds r4, #0x68
	movs r6, #0
	ldrsh r4, [r4, r6]
	str r4, [sp, #4]
	bl func_fe6_08093EAC
	ldr r0, [r5, #0x54]
	cmp r0, #0
	beq .L08093E0C
	adds r0, r5, #0
	bl Proc_Break
.L08093E0C:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08093E14
func_fe6_08093E14: @ 0x08093E14
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x2c]
	ldr r2, [r5, #0x30]
	movs r3, #0x80
	lsls r3, r3, #3
	orrs r2, r3
	adds r3, r5, #0
	adds r3, #0x64
	movs r4, #0
	ldrsh r3, [r3, r4]
	adds r4, r5, #0
	adds r4, #0x66
	movs r6, #0
	ldrsh r4, [r4, r6]
	str r4, [sp]
	adds r4, r5, #0
	adds r4, #0x68
	movs r6, #0
	ldrsh r4, [r4, r6]
	str r4, [sp, #4]
	bl func_fe6_08093EAC
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r2, [r0]
	subs r2, #1
	movs r3, #0
	strh r2, [r0]
	ldr r4, .L08093E8C @ =gDispIo
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r6, [r1]
	ands r0, r6
	strb r0, [r1]
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x44
	strb r1, [r0]
	movs r0, #0x10
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x45
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x46
	strb r3, [r0]
	lsls r2, r2, #0x10
	cmp r2, #0
	bne .L08093E84
	adds r0, r5, #0
	bl Proc_Break
.L08093E84:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08093E8C: .4byte gDispIo

	thumb_func_start func_fe6_08093E90
func_fe6_08093E90: @ 0x08093E90
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x6a
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0
	bl SetWMMapText
	ldr r0, [r4, #0x50]
	bl EndSpriteAnim
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08093EAC
func_fe6_08093EAC: @ 0x08093EAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp, #4]
	adds r4, r1, #0
	adds r7, r2, #0
	str r3, [sp, #8]
	ldr r0, [sp, #0x30]
	mov r8, r0
	ldr r5, [sp, #0x34]
	ldr r1, .L08093EEC @ =0xFFFFFE00
	mov sb, r1
	mov r2, sb
	ands r2, r4
	mov sb, r2
	ldr r0, .L08093EF0 @ =0xFFFFFF00
	mov sl, r0
	mov r1, sl
	ands r1, r7
	mov sl, r1
	mov r2, r8
	cmp r2, #1
	beq .L08093F08
	cmp r2, #1
	bgt .L08093EF4
	cmp r2, #0
	beq .L08093F00
	b .L08093F0A
	.align 2, 0
.L08093EEC: .4byte 0xFFFFFE00
.L08093EF0: .4byte 0xFFFFFF00
.L08093EF4:
	mov r0, r8
	cmp r0, #2
	beq .L08093F04
	cmp r0, #3
	beq .L08093F08
	b .L08093F0A
.L08093F00:
	subs r4, #2
	b .L08093F0A
.L08093F04:
	subs r4, #3
	b .L08093F0A
.L08093F08:
	adds r4, #2
.L08093F0A:
	lsls r5, r5, #1
	subs r5, #1
	movs r0, #1
	rsbs r0, r0, #0
	mov r1, r8
	lsls r1, r1, #1
	str r1, [sp, #0xc]
	cmp r5, r0
	beq .L08093F54
	ldr r1, .L08093F64 @ =gUnk_0868C940
	ldr r0, [sp, #0xc]
	add r0, r8
	lsls r0, r0, #2
	adds r6, r0, r1
.L08093F26:
	ldr r1, .L08093F68 @ =0x000001FF
	ands r1, r4
	add r1, sb
	movs r2, #0xff
	ands r2, r7
	add r2, sl
	ldr r3, [r6]
	ldr r0, .L08093F6C @ =0x00004320
	str r0, [sp]
	movs r0, #0xb
	bl PutSpriteExt
	movs r2, #4
	ldrsh r0, [r6, r2]
	adds r4, r4, r0
	movs r1, #6
	ldrsh r0, [r6, r1]
	adds r7, r7, r0
	subs r5, #1
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L08093F26
.L08093F54:
	mov r2, r8
	cmp r2, #1
	beq .L08093F96
	cmp r2, #1
	bgt .L08093F70
	cmp r2, #0
	beq .L08093F7E
	b .L08093F96
	.align 2, 0
.L08093F64: .4byte gUnk_0868C940
.L08093F68: .4byte 0x000001FF
.L08093F6C: .4byte 0x00004320
.L08093F70:
	mov r0, r8
	cmp r0, #2
	beq .L08093F7C
	cmp r0, #3
	beq .L08093F94
	b .L08093F96
.L08093F7C:
	adds r4, #2
.L08093F7E:
	ldr r0, .L08093F90 @ =gUnk_0868C734
	ldr r2, [sp, #8]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	subs r4, r4, r0
	b .L08093F96
	.align 2, 0
.L08093F90: .4byte gUnk_0868C734
.L08093F94:
	subs r4, #2
.L08093F96:
	ldr r0, .L08093FD0 @ =gUnk_0868C940
	ldr r2, [sp, #0xc]
	add r2, r8
	lsls r2, r2, #2
	adds r2, r2, r0
	movs r0, #8
	ldrsh r1, [r2, r0]
	adds r1, r4, r1
	ldr r0, .L08093FD4 @ =0x000001FF
	ands r1, r0
	add r1, sb
	movs r0, #0xa
	ldrsh r2, [r2, r0]
	adds r2, r7, r2
	movs r0, #0xff
	ands r2, r0
	add r2, sl
	ldr r0, [sp, #4]
	bl DisplaySpriteAnim
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08093FD0: .4byte gUnk_0868C940
.L08093FD4: .4byte 0x000001FF

	thumb_func_start func_fe6_08093FD8
func_fe6_08093FD8: @ 0x08093FD8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L0809400C @ =gUnk_0868C648
	bl FindProc
	ldrh r1, [r4]
	ldrh r3, [r0, #0x2a]
	subs r2, r1, r3
	strh r2, [r4]
	ldrh r5, [r4, #2]
	ldrh r3, [r0, #0x2c]
	subs r1, r5, r3
	strh r1, [r4, #2]
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08094006
	lsls r0, r2, #0x10
	asrs r0, r0, #0x11
	strh r0, [r4]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x11
	strh r0, [r4, #2]
.L08094006:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0809400C: .4byte gUnk_0868C648

	thumb_func_start PlayWMIntroBGM
PlayWMIntroBGM: @ 0x08094010
	push {lr}
	ldr r0, .L0809402C @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterInfo
	ldrb r0, [r0, #0x17]
	movs r1, #0
	bl StartBgm
	pop {r0}
	bx r0
	.align 2, 0
.L0809402C: .4byte gPlaySt

	thumb_func_start func_fe6_08094030
func_fe6_08094030: @ 0x08094030
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r1, r3, #0
	ldr r0, .L08094058 @ =gUnk_0868C970
	bl SpawnProcLocking
	ldr r1, .L0809405C @ =0x000003FF
	ands r1, r4
	lsls r1, r1, #5
	ldr r2, .L08094060 @ =0x06010000
	adds r1, r1, r2
	str r1, [r0, #0x4c]
	str r5, [r0, #0x54]
	str r6, [r0, #0x58]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08094058: .4byte gUnk_0868C970
.L0809405C: .4byte 0x000003FF
.L08094060: .4byte 0x06010000

	thumb_func_start func_fe6_08094064
func_fe6_08094064: @ 0x08094064
	adds r0, #0x64
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start func_fe6_0809406C
func_fe6_0809406C: @ 0x0809406C
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldr r6, [r3, #0x4c]
	movs r1, #0
	b .L080940C8
.L08094076:
	movs r2, #0
	lsls r0, r1, #2
	adds r5, r1, #0
	adds r5, #8
	adds r4, r0, r6
.L08094080:
	lsls r0, r2, #2
	adds r1, r0, r4
	ldr r0, [r1, #4]
	str r0, [r1]
	ldr r0, [r1, #8]
	str r0, [r1, #4]
	ldr r0, [r1, #0xc]
	str r0, [r1, #8]
	ldr r0, [r1, #0x10]
	str r0, [r1, #0xc]
	ldr r0, [r1, #0x14]
	str r0, [r1, #0x10]
	ldr r0, [r1, #0x18]
	str r0, [r1, #0x14]
	ldr r0, [r1, #0x1c]
	str r0, [r1, #0x18]
	ldr r0, .L080940B0 @ =0x000002FF
	cmp r2, r0
	bgt .L080940B4
	movs r7, #0x80
	lsls r7, r7, #3
	adds r0, r1, r7
	ldr r0, [r0]
	b .L080940B6
	.align 2, 0
.L080940B0: .4byte 0x000002FF
.L080940B4:
	ldr r0, [r3, #0x58]
.L080940B6:
	str r0, [r1, #0x1c]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r2, r0
	ble .L08094080
	adds r1, r5, #0
.L080940C8:
	ldr r0, [r3, #0x54]
	lsls r0, r0, #3
	cmp r1, r0
	blt .L08094076
	adds r1, r3, #0
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	ble .L080940E8
	adds r0, r3, #0
	bl Proc_Break
.L080940E8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080940F0
func_fe6_080940F0: @ 0x080940F0
	push {lr}
	bl EndMapUi
	ldr r0, .L08094104 @ =gUnk_0868C988
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L08094104: .4byte gUnk_0868C988

	thumb_func_start func_fe6_08094108
func_fe6_08094108: @ 0x08094108
	adds r0, #0x34
	movs r1, #1
	strb r1, [r0]
	bx lr

	thumb_func_start func_fe6_08094110
func_fe6_08094110: @ 0x08094110
	push {lr}
	movs r1, #0
	str r1, [r0, #0x2c]
	ldr r1, .L08094128 @ =gPlaySt
	ldrb r1, [r1, #0xe]
	adds r2, r0, #0
	adds r2, #0x35
	strb r1, [r2]
	bl func_fe6_08094108
	pop {r0}
	bx r0
	.align 2, 0
.L08094128: .4byte gPlaySt

	thumb_func_start func_fe6_0809412C
func_fe6_0809412C: @ 0x0809412C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x2c]
	bl IsEventRunning
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08094204
	adds r0, r5, #0
	adds r0, #0x34
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne .L08094158
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #9
	bl DebugInitObj
	adds r0, r5, #0
	bl func_fe6_08094108
.L08094158:
	movs r0, #0x70
	movs r1, #0x64
	adds r2, r4, #0
	movs r3, #4
	bl DebugPutObjNumber
	ldr r1, .L0809417C @ =gKeySt
	ldr r2, [r1]
	movs r0, #4
	ldrh r3, [r2, #8]
	ands r0, r3
	cmp r0, #0
	beq .L08094180
	adds r0, r5, #0
	bl Proc_Break
	b .L08094204
	.align 2, 0
.L0809417C: .4byte gKeySt
.L08094180:
	ldrh r2, [r2, #6]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq .L0809418C
	adds r4, #1
.L0809418C:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq .L08094196
	subs r4, #1
.L08094196:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq .L080941A0
	adds r4, #0xa
.L080941A0:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq .L080941AA
	subs r4, #0xa
.L080941AA:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq .L080941B6
	adds r4, #0x64
.L080941B6:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L080941C2
	subs r4, #0x64
.L080941C2:
	cmp r4, #0
	bge .L080941C8
	movs r4, #0
.L080941C8:
	cmp r4, #0x26
	ble .L080941CE
	movs r4, #0x26
.L080941CE:
	ldr r0, [r5, #0x2c]
	cmp r4, r0
	beq .L080941E2
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #9
	bl DebugInitObj
	str r4, [r5, #0x2c]
	b .L08094204
.L080941E2:
	ldr r1, [r1]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08094204
	movs r0, #0
	strb r0, [r6]
	ldr r1, .L0809420C @ =gPlaySt
	adds r0, r5, #0
	adds r0, #0x35
	ldrb r0, [r0]
	strb r0, [r1, #0xe]
	ldr r0, .L08094210 @ =ProcScr_WorldMapIntroEvent
	movs r1, #3
	bl SpawnProc
.L08094204:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0809420C: .4byte gPlaySt
.L08094210: .4byte ProcScr_WorldMapIntroEvent

	thumb_func_start func_fe6_08094214
func_fe6_08094214: @ 0x08094214
	push {lr}
	adds r1, r0, #0
	ldr r0, .L08094224 @ =gUnk_0868FDB4
	bl SpawnProcLocking
	pop {r0}
	bx r0
	.align 2, 0
.L08094224: .4byte gUnk_0868FDB4

	thumb_func_start func_fe6_08094228
func_fe6_08094228: @ 0x08094228
	push {lr}
	movs r0, #0
	bl SetOnHBlankA
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08094234
func_fe6_08094234: @ 0x08094234
	push {r4, r5, lr}
	ldr r0, .L080943BC @ =gUnk_0868FE0C
	bl InitBgs
	bl func_fe6_08015344
	bl ResetText
	ldr r3, .L080943C0 @ =gDispIo
	movs r0, #1
	ldrb r1, [r3, #1]
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r3, #1]
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x44
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r2, [r0]
	ldr r0, .L080943C4 @ =0x0000FFE0
	ldrh r2, [r3, #0x3c]
	ands r0, r2
	movs r1, #1
	orrs r0, r1
	ldr r1, .L080943C8 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3, #0x3c]
	bl InitScanlineEffect
	ldr r0, .L080943CC @ =OnHBlank_08069FD8
	bl SetOnHBlankA
	bl func_fe6_0806A7AC
	ldr r4, .L080943D0 @ =gUnk_0831B0A8
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	adds r0, r4, #0
	bl Decompress
	ldr r4, .L080943D4 @ =gBuf
	ldr r1, .L080943D8 @ =gUnk_08320434
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r4, #0
	bl TmApplyTsa_thm
	ldr r1, .L080943DC @ =gBg3Tm
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	bl VramCopy
	ldr r0, .L080943E0 @ =gUnk_08320D98
	movs r1, #0x80
	movs r2, #0x80
	bl ApplyPaletteExt
	movs r0, #4
	bl func_fe6_080154AC
	movs r0, #5
	bl func_fe6_080154AC
	movs r0, #6
	bl func_fe6_080154AC
	movs r0, #7
	bl func_fe6_080154AC
	ldr r4, .L080943E4 @ =gBg0Tm
	adds r0, r4, #0
	movs r1, #0
	bl TmFill
	ldr r0, .L080943E8 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L080943EC @ =gUnk_08349A78
	movs r1, #0x60
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r5, .L080943F0 @ =gUnk_0834658C
	movs r0, #0
	bl GetBgChrOffset
	adds r1, r0, #0
	ldr r2, .L080943F4 @ =0x06000020
	adds r1, r1, r2
	adds r0, r5, #0
	bl Decompress
	adds r0, r4, #4
	ldr r1, .L080943F8 @ =0x00003001
	bl func_fe6_08094438
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, .L080943FC @ =0x00003041
	bl func_fe6_08094438
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, .L08094400 @ =0x00003081
	bl func_fe6_08094438
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r1, .L08094404 @ =0x000030C1
	bl func_fe6_08094438
	movs r1, #0xd1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, .L08094408 @ =0x00003101
	bl func_fe6_08094438
	ldr r2, .L0809440C @ =0x00000404
	adds r0, r4, r2
	ldr r1, .L08094410 @ =0x00003141
	bl func_fe6_08094438
	ldr r1, .L08094414 @ =0x000004C4
	adds r0, r4, r1
	ldr r1, .L08094418 @ =0x00003181
	bl func_fe6_08094438
	ldr r2, .L0809441C @ =0x00000584
	adds r0, r4, r2
	ldr r1, .L08094420 @ =0x000031C1
	bl func_fe6_08094438
	ldr r1, .L08094424 @ =0x00000644
	adds r0, r4, r1
	ldr r1, .L08094428 @ =0x00003201
	bl func_fe6_08094438
	ldr r2, .L0809442C @ =0x00000744
	adds r4, r4, r2
	ldr r1, .L08094430 @ =0x00003241
	adds r0, r4, #0
	bl func_fe6_08094438
	movs r0, #1
	bl EnableBgSync
	movs r0, #2
	bl EnableBgSync
	ldr r2, .L08094434 @ =0x0000FF60
	movs r0, #0
	movs r1, #0
	bl SetBgOffset
	movs r0, #0x47
	bl m4aSongNumStart
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080943BC: .4byte gUnk_0868FE0C
.L080943C0: .4byte gDispIo
.L080943C4: .4byte 0x0000FFE0
.L080943C8: .4byte 0x0000E0FF
.L080943CC: .4byte OnHBlank_08069FD8
.L080943D0: .4byte gUnk_0831B0A8
.L080943D4: .4byte gBuf
.L080943D8: .4byte gUnk_08320434
.L080943DC: .4byte gBg3Tm
.L080943E0: .4byte gUnk_08320D98
.L080943E4: .4byte gBg0Tm
.L080943E8: .4byte gBg1Tm
.L080943EC: .4byte gUnk_08349A78
.L080943F0: .4byte gUnk_0834658C
.L080943F4: .4byte 0x06000020
.L080943F8: .4byte 0x00003001
.L080943FC: .4byte 0x00003041
.L08094400: .4byte 0x00003081
.L08094404: .4byte 0x000030C1
.L08094408: .4byte 0x00003101
.L0809440C: .4byte 0x00000404
.L08094410: .4byte 0x00003141
.L08094414: .4byte 0x000004C4
.L08094418: .4byte 0x00003181
.L0809441C: .4byte 0x00000584
.L08094420: .4byte 0x000031C1
.L08094424: .4byte 0x00000644
.L08094428: .4byte 0x00003201
.L0809442C: .4byte 0x00000744
.L08094430: .4byte 0x00003241
.L08094434: .4byte 0x0000FF60

	thumb_func_start func_fe6_08094438
func_fe6_08094438: @ 0x08094438
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	movs r1, #0
	adds r3, r4, #0
	adds r3, #0x20
.L08094444:
	adds r0, r4, r1
	strh r0, [r2]
	adds r0, r2, #0
	adds r0, #0x40
	strh r3, [r0]
	adds r2, #2
	adds r3, #1
	adds r1, #1
	cmp r1, #0x1f
	ble .L08094444
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08094460
func_fe6_08094460: @ 0x08094460
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x64
	movs r0, #0xe4
	lsls r0, r0, #2
	ldrh r1, [r5]
	cmp r1, r0
	bne .L080944AA
	ldr r4, .L080944D8 @ =gBg1Tm+0x4
	ldr r1, .L080944DC @ =0x00003281
	adds r0, r4, #0
	bl func_fe6_08094438
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r1, .L080944E0 @ =0x000032C1
	bl func_fe6_08094438
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, .L080944E4 @ =0x00003301
	bl func_fe6_08094438
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, .L080944E8 @ =0x00003341
	bl func_fe6_08094438
	movs r0, #1
	bl EnableBgSync
	movs r0, #2
	bl EnableBgSync
.L080944AA:
	ldr r0, .L080944EC @ =gKeySt
	ldr r1, [r0]
	movs r0, #8
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L080944BE
	adds r0, r6, #0
	bl Proc_Break
.L080944BE:
	ldrh r0, [r5]
	adds r1, r0, #1
	strh r1, [r5]
	lsls r0, r0, #0x10
	ldr r1, .L080944F0 @ =0x06C70000
	cmp r0, r1
	ble .L080944D2
	adds r0, r6, #0
	bl Proc_Break
.L080944D2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080944D8: .4byte gBg1Tm+0x4
.L080944DC: .4byte 0x00003281
.L080944E0: .4byte 0x000032C1
.L080944E4: .4byte 0x00003301
.L080944E8: .4byte 0x00003341
.L080944EC: .4byte gKeySt
.L080944F0: .4byte 0x06C70000

	thumb_func_start func_fe6_080944F4
func_fe6_080944F4: @ 0x080944F4
	adds r1, r0, #0
	adds r1, #0x64
	movs r2, #0
	strh r2, [r1]
	adds r0, #0x66
	strh r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08094504
func_fe6_08094504: @ 0x08094504
	push {lr}
	adds r3, r0, #0
	adds r2, r3, #0
	adds r2, #0x64
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble .L08094528
	movs r0, #0
	strh r0, [r2]
	adds r1, r3, #0
	adds r1, #0x66
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
.L08094528:
	adds r0, r3, #0
	adds r0, #0x66
	ldrh r2, [r0]
	subs r2, #0x90
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	movs r1, #0
	bl SetBgOffset
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08094540
func_fe6_08094540: @ 0x08094540
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r4, .L080945EC @ =gDispIo
	movs r0, #8
	rsbs r0, r0, #0
	ldrb r1, [r4]
	ands r0, r1
	strb r0, [r4]
	movs r0, #0
	bl InitBgs
	bl NewEfxAnimeDrvProc
	bl func_fe6_08057EF4
	adds r0, r7, #0
	adds r0, #0x2e
	movs r5, #0
	strb r5, [r0]
	ldr r1, .L080945F0 @ =gUnk_0869056C
	subs r0, #1
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r1, r7, #0
	adds r1, #0x30
	strb r0, [r1]
	movs r6, #0
	strh r5, [r7, #0x2a]
	str r5, [r7, #0x34]
	str r5, [r7, #0x38]
	ldrb r1, [r1]
	adds r0, r7, #0
	bl func_fe6_08094C80
	str r0, [r7, #0x34]
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r4, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #1]
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
	bl GetGameTime
	str r0, [r7, #0x40]
	str r5, [r7, #0x3c]
	adds r1, r7, #0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x32
	strb r6, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080945EC: .4byte gDispIo
.L080945F0: .4byte gUnk_0869056C

	thumb_func_start func_fe6_080945F4
func_fe6_080945F4: @ 0x080945F4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	bl GetGameTime
	ldr r1, [r4, #0x40]
	subs r0, r0, r1
	str r0, [r4, #0x3c]
	adds r5, r4, #0
	adds r5, #0x2c
	ldrb r0, [r5]
	cmp r0, #2
	beq .L08094644
	cmp r0, #2
	bgt .L0809461A
	cmp r0, #1
	beq .L08094620
	b .L080946C4
.L0809461A:
	cmp r0, #3
	beq .L080946B2
	b .L080946C4
.L08094620:
	ldr r0, .L08094640 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0xb
	ldrh r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L080946C4
	movs r0, #0
	bl SetNextGameAction
	adds r0, r4, #0
	movs r1, #4
	bl Proc_Goto
	b .L080946C4
	.align 2, 0
.L08094640: .4byte gKeySt
.L08094644:
	adds r3, r4, #0
	adds r3, #0x30
	ldrb r5, [r3]
	ldr r0, .L0809469C @ =gUnk_0869056C
	mov r8, r0
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r2, [r1]
	movs r6, #0x2d
	adds r6, r6, r4
	ldrb r7, [r6]
	lsls r0, r7, #2
	adds r0, r2, r0
	add r0, r8
	ldrb r0, [r0]
	adds r0, #4
	cmp r5, r0
	blt .L080946A4
	adds r0, r2, #1
	strb r0, [r1]
	ldrb r2, [r1]
	ldrb r1, [r6]
	lsls r0, r1, #2
	adds r0, r2, r0
	add r0, r8
	ldrb r1, [r0]
	adds r0, r1, #0
	cmp r0, #0xff
	beq .L08094682
	cmp r2, #3
	bls .L080946A0
.L08094682:
	movs r0, #1
	bl SetNextGameAction
	adds r0, r4, #0
	movs r1, #5
	bl Proc_Goto
	movs r0, #1
	rsbs r0, r0, #0
	bl FadeBgmOut
	b .L080946C4
	.align 2, 0
.L0809469C: .4byte gUnk_0869056C
.L080946A0:
	strb r1, [r3]
	b .L080946A8
.L080946A4:
	adds r0, r5, #1
	strb r0, [r3]
.L080946A8:
	adds r0, r4, #0
	movs r1, #2
	bl Proc_Goto
	b .L080946C4
.L080946B2:
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r1, [r0]
	adds r0, r4, #0
	bl func_fe6_08095AB8
	str r0, [r4, #0x38]
	movs r0, #1
	strb r0, [r5]
.L080946C4:
	movs r0, #0
	strh r0, [r4, #0x2a]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080946D4
func_fe6_080946D4: @ 0x080946D4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq .L080946E4
	movs r1, #4
	bl Proc_Goto
.L080946E4:
	ldr r2, .L08094720 @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r1, [r0]
	adds r0, r4, #0
	bl func_fe6_08094C80
	str r0, [r4, #0x34]
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08094720: .4byte gDispIo

	thumb_func_start func_fe6_08094724
func_fe6_08094724: @ 0x08094724
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08094794 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0xb
	ldrh r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L08094752
	adds r4, r5, #0
	adds r4, #0x32
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08094752
	movs r0, #0
	bl SetNextGameAction
	movs r0, #1
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #4
	bl Proc_Goto
.L08094752:
	ldrh r0, [r5, #0x2a]
	cmp r0, #0
	bne .L0809475C
	bl func_fe6_08057F24
.L0809475C:
	ldrh r0, [r5, #0x2a]
	adds r0, #1
	adds r1, r0, #0
	strh r0, [r5, #0x2a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x11
	cmp r0, #0xd
	bls .L0809479C
	ldr r2, .L08094798 @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2, #1]
	adds r0, r5, #0
	bl Proc_Break
	b .L080947A4
	.align 2, 0
.L08094794: .4byte gKeySt
.L08094798: .4byte gDispIo
.L0809479C:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	bl func_fe6_0809485C
.L080947A4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080947AC
func_fe6_080947AC: @ 0x080947AC
	push {lr}
	movs r0, #1
	bl FadeBgmOut
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080947B8
func_fe6_080947B8: @ 0x080947B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq .L080947C8
	movs r1, #4
	bl Proc_Goto
.L080947C8:
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq .L080947D4
	movs r1, #4
	bl Proc_Goto
.L080947D4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080947DC
func_fe6_080947DC: @ 0x080947DC
	push {r4, lr}
	adds r4, r0, #0
	bl EndEfxAnimeDrvProc
	adds r0, r4, #0
	bl CleanupGame
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start StartClassDemo
StartClassDemo: @ 0x080947F0
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, .L08094808 @ =ProcScr_ClassDemo
	bl SpawnProcLocking
	adds r0, #0x2d
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08094808: .4byte ProcScr_ClassDemo

	thumb_func_start func_fe6_0809480C
func_fe6_0809480C: @ 0x0809480C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r3, .L08094854 @ =gPal
	ldr r2, .L08094858 @ =0x02000000
	movs r1, #0x80
	lsls r1, r1, #2
.L08094818:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne .L08094818
	ldr r4, .L08094858 @ =0x02000000
	ldrh r5, [r5, #0x2a]
	lsrs r3, r5, #1
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	bl EfxPalBlackInOut
	ldr r2, .L08094854 @ =gPal
	movs r1, #0x80
	lsls r1, r1, #2
.L0809483C:
	ldrh r0, [r4]
	strh r0, [r2]
	adds r4, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne .L0809483C
	bl EnablePalSync
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08094854: .4byte gPal
.L08094858: .4byte 0x02000000

	thumb_func_start func_fe6_0809485C
func_fe6_0809485C: @ 0x0809485C
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, .L08094874 @ =gUnk_0868FEDC
	movs r1, #4
	bl SpawnProc
	strh r4, [r0, #0x2a]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08094874: .4byte gUnk_0868FEDC

	thumb_func_start func_fe6_08094878
func_fe6_08094878: @ 0x08094878
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r2, [sp, #0x30]
	ldr r3, [sp, #0x34]
	ldr r4, [sp, #0x38]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sl, r2
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r5, #1
	ldr r2, .L080948D4 @ =gPal
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r1, .L080948D8 @ =0x0000021E
	adds r6, r2, r1
	adds r0, r4, r0
	lsls r1, r7, #5
	lsls r0, r0, #1
	adds r0, r0, r2
	adds r3, r0, #2
	ldr r0, .L080948DC @ =0x00000222
	adds r1, r1, r0
	adds r1, r1, r2
.L080948C4:
	adds r0, r5, r4
	cmp r0, #0xf
	ble .L080948E0
	ldrh r0, [r6]
	strh r0, [r1]
	adds r2, r7, #1
	mov sb, r2
	b .L080948E8
	.align 2, 0
.L080948D4: .4byte gPal
.L080948D8: .4byte 0x0000021E
.L080948DC: .4byte 0x00000222
.L080948E0:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r0, r7, #1
	mov sb, r0
.L080948E8:
	adds r1, #2
	adds r3, #2
	adds r5, #1
	cmp r5, #0xf
	ble .L080948C4
	bl EnablePalSync
	mov r1, sl
	cmp r1, #7
	bhi .L08094900
	movs r2, #8
	mov sl, r2
.L08094900:
	mov r3, r8
	cmp r3, #7
	bhi .L0809490A
	movs r0, #8
	mov r8, r0
.L0809490A:
	ldr r4, .L080949A8 @ =gSinLut
	ldr r1, .L080949AC @ =gSinLut+0x80
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	mov r1, sl
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r3, #0
	ldrsh r0, [r4, r3]
	rsbs r0, r0, #0
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r0, r0, #4
	mov r1, sl
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r2, .L080949AC @ =gSinLut+0x80
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	ldr r0, .L080949B0 @ =0x000001FF
	ldr r1, [sp, #8]
	ands r1, r0
	str r1, [sp, #8]
	lsls r1, r7, #9
	ldr r2, [sp, #8]
	adds r1, r2, r1
	ldr r3, [sp, #0xc]
	ands r3, r0
	str r3, [sp, #0xc]
	ldr r2, .L080949B4 @ =gUnk_08690288
	ldr r3, [sp, #4]
	adds r0, r3, r7
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r3, [r0]
	movs r0, #0xf
	mov r2, sb
	ands r2, r0
	lsls r0, r2, #0xc
	str r0, [sp]
	movs r0, #4
	ldr r2, [sp, #0xc]
	bl PutSpriteExt
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080949A8: .4byte gSinLut
.L080949AC: .4byte gSinLut+0x80
.L080949B0: .4byte 0x000001FF
.L080949B4: .4byte gUnk_08690288

	thumb_func_start func_fe6_080949B8
func_fe6_080949B8: @ 0x080949B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	ldr r2, .L08094A04 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	movs r0, #0
	strh r0, [r5, #0x2a]
	adds r2, r5, #0
	adds r2, #0x30
	ldrb r0, [r2]
	cmp r0, #0
	bne .L08094A0C
	adds r1, r5, #0
	adds r1, #0x2f
	movs r0, #0
	strb r0, [r1]
	mov sb, r2
	ldr r2, .L08094A08 @ =gUnk_08690288
	mov ip, r2
	movs r0, #0x2e
	adds r0, r0, r5
	mov r8, r0
	movs r2, #0x34
	adds r2, r2, r5
	mov sl, r2
	b .L08094A42
	.align 2, 0
.L08094A04: .4byte gDispIo
.L08094A08: .4byte gUnk_08690288
.L08094A0C:
	movs r4, #0
	movs r3, #0
	mov sb, r2
	adds r1, r5, #0
	adds r1, #0x2f
	ldr r0, .L08094A78 @ =gUnk_08690288
	mov ip, r0
	movs r2, #0x2e
	adds r2, r2, r5
	mov r8, r2
	movs r0, #0x34
	adds r0, r0, r5
	mov sl, r0
	mov r6, sb
	adds r7, r1, #0
	mov r2, ip
.L08094A2C:
	adds r2, #4
	adds r4, #1
	ldr r0, [r2]
	cmp r0, #0
	bne .L08094A2C
	adds r3, #1
	ldrb r0, [r6]
	cmp r3, r0
	bne .L08094A2C
	adds r0, r4, #1
	strb r0, [r7]
.L08094A42:
	movs r0, #0
	mov r2, r8
	strb r0, [r2]
	ldrb r1, [r1]
	lsls r0, r1, #2
	mov r2, ip
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, #0
	beq .L08094A66
	mov r2, r8
.L08094A58:
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	adds r1, #4
	ldr r0, [r1]
	cmp r0, #0
	bne .L08094A58
.L08094A66:
	mov r0, sb
	ldrb r0, [r0]
	cmp r0, #0x13
	bls .L08094A84
	ldr r0, .L08094A7C @ =gUnk_08357140
	ldr r1, .L08094A80 @ =0x06010000
	bl Decompress
	b .L08094A8C
	.align 2, 0
.L08094A78: .4byte gUnk_08690288
.L08094A7C: .4byte gUnk_08357140
.L08094A80: .4byte 0x06010000
.L08094A84:
	ldr r0, .L08094B0C @ =gUnk_08354780
	ldr r1, .L08094B10 @ =0x06010000
	bl Decompress
.L08094A8C:
	ldr r0, .L08094B14 @ =gUnk_08354760
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r4, .L08094B18 @ =gUnk_0835A368
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, #0
	movs r2, #0x20
	bl ApplyPaletteExt
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r0, r4, #0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L08094B1C @ =gUnk_083599AC
	ldr r1, .L08094B20 @ =0x06016000
	bl Decompress
	mov r1, sl
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0x24
.L08094AC2:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge .L08094AC2
	mov r2, r8
	ldrb r2, [r2]
	lsls r1, r2, #3
	mov r0, r8
	ldrb r0, [r0]
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0xf0
	subs r0, r0, r1
	asrs r0, r0, #1
	subs r0, #0x10
	ldr r2, .L08094B24 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	movs r1, #0
	bl func_fe6_08094EE8
	str r0, [r5, #0x34]
	mov r0, sb
	ldrb r1, [r0]
	adds r0, r5, #0
	bl func_fe6_080951DC
	str r0, [r5, #0x5c]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08094B0C: .4byte gUnk_08354780
.L08094B10: .4byte 0x06010000
.L08094B14: .4byte gUnk_08354760
.L08094B18: .4byte gUnk_0835A368
.L08094B1C: .4byte gUnk_083599AC
.L08094B20: .4byte 0x06016000
.L08094B24: .4byte 0x000001FF

	thumb_func_start func_fe6_08094B28
func_fe6_08094B28: @ 0x08094B28
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L08094B7C @ =gDispIo
	mov ip, r0
	mov r3, ip
	adds r3, #0x3c
	movs r2, #0x3f
	ldrb r0, [r3]
	ands r2, r0
	movs r0, #0x80
	orrs r2, r0
	mov r0, ip
	adds r0, #0x44
	movs r5, #0
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	ldrh r0, [r4, #0x2a]
	lsrs r1, r0, #1
	movs r0, #0x10
	subs r0, r0, r1
	mov r1, ip
	adds r1, #0x46
	strb r0, [r1]
	movs r0, #0x20
	orrs r2, r0
	strb r2, [r3]
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bne .L08094B74
	strh r5, [r4, #0x2a]
	adds r0, r4, #0
	bl Proc_Break
.L08094B74:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08094B7C: .4byte gDispIo

	thumb_func_start func_fe6_08094B80
func_fe6_08094B80: @ 0x08094B80
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2a]
	cmp r0, #0x5f
	bls .L08094B94
	adds r0, r4, #0
	bl Proc_Break
	movs r0, #0
	b .L08094BD8
.L08094B94:
	cmp r0, #0xf
	bls .L08094BD4
	ldrh r1, [r4, #0x2a]
	adds r6, r1, #0
	subs r6, #0x10
	movs r0, #3
	ands r0, r6
	cmp r0, #0
	bne .L08094BD4
	adds r0, r6, #0
	cmp r6, #0
	bge .L08094BB0
	adds r0, r1, #0
	subs r0, #0xd
.L08094BB0:
	asrs r0, r0, #2
	adds r5, r0, #1
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r5, r0
	bge .L08094BD4
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl func_fe6_08094EE8
	adds r2, r0, #0
	lsls r1, r5, #2
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r1
	str r2, [r0]
.L08094BD4:
	ldrh r0, [r4, #0x2a]
	adds r0, #1
.L08094BD8:
	strh r0, [r4, #0x2a]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08094BE0
func_fe6_08094BE0: @ 0x08094BE0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2a]
	cmp r0, #0x14
	bne .L08094BF2
	ldr r0, [r4, #0x5c]
	movs r1, #4
	bl Proc_Goto
.L08094BF2:
	ldrh r0, [r4, #0x2a]
	cmp r0, #0x4f
	bls .L08094C0E
	adds r0, r4, #0
	bl Proc_Break
	movs r0, #0
	strh r0, [r4, #0x2a]
	adds r1, r4, #0
	adds r1, #0x30
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b .L08094C48
.L08094C0E:
	ldrh r5, [r4, #0x2a]
	adds r0, r5, #0
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08094C42
	adds r0, r5, #0
	movs r1, #6
	bl __udivsi3
	adds r1, r4, #0
	adds r1, #0x2e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1]
	cmp r0, r1
	bhs .L08094C42
	lsls r0, r0, #2
	adds r1, r4, #0
	adds r1, #0x34
	adds r1, r1, r0
	ldr r0, [r1]
	bl Proc_Break
.L08094C42:
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
.L08094C48:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08094C50
func_fe6_08094C50: @ 0x08094C50
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x34
	movs r5, #7
.L08094C5A:
	ldr r0, [r4]
	cmp r0, #0
	beq .L08094C64
	bl Proc_End
.L08094C64:
	adds r4, #4
	subs r5, #1
	cmp r5, #0
	bge .L08094C5A
	ldr r0, [r6, #0x60]
	movs r1, #0
	str r1, [r0, #0x34]
	adds r0, #0x2c
	movs r1, #3
	strb r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08094C80
func_fe6_08094C80: @ 0x08094C80
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x18
	lsrs r4, r4, #0x18
	ldr r0, .L08094CB4 @ =gUnk_0868FEFC
	adds r1, r5, #0
	bl SpawnProc
	adds r2, r0, #0
	str r5, [r2, #0x60]
	adds r0, #0x30
	strb r4, [r0]
	movs r3, #0
	movs r1, #9
	adds r0, #0x28
.L08094C9E:
	str r3, [r0]
	subs r0, #4
	subs r1, #1
	cmp r1, #0
	bge .L08094C9E
	movs r0, #0
	str r0, [r2, #0x5c]
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08094CB4: .4byte gUnk_0868FEFC

	thumb_func_start func_fe6_08094CB8
func_fe6_08094CB8: @ 0x08094CB8
	push {r4, lr}
	movs r1, #0
	strh r1, [r0, #0x2a]
	ldr r2, [r0, #0x14]
	adds r1, r2, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	strh r1, [r0, #0x2c]
	adds r3, r0, #0
	adds r3, #0x2e
	ldrb r4, [r3]
	lsls r1, r4, #3
	subs r1, r1, r4
	lsls r1, r1, #2
	ldrh r2, [r2, #0x2c]
	adds r1, r2, r1
	ldr r3, .L08094CE8 @ =0x000001FF
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r0, #0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08094CE8: .4byte 0x000001FF

	thumb_func_start func_fe6_08094CEC
func_fe6_08094CEC: @ 0x08094CEC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	movs r0, #0x2e
	adds r0, r0, r7
	mov sb, r0
	ldrb r1, [r0]
	mov sl, r1
	cmp r1, #0
	bne .L08094DC0
	ldr r3, .L08094DB8 @ =gSinLut
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r5, #0
	ldrsh r6, [r0, r5]
	asrs r6, r6, #6
	adds r0, r3, #0
	adds r0, #0xc0
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r4, r0, #1
	adds r4, r4, r0
	asrs r4, r4, #9
	ldrh r0, [r7, #0x2a]
	movs r2, #0xc0
	subs r2, r2, r0
	movs r1, #0xff
	ands r2, r1
	adds r1, r2, #0
	adds r1, #0x40
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r5, #0
	ldrsh r1, [r1, r5]
	asrs r5, r1, #6
	lsls r2, r2, #1
	adds r2, r2, r3
	movs r1, #0
	ldrsh r2, [r2, r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	asrs r3, r1, #9
	lsls r0, r0, #8
	movs r1, #0x60
	str r3, [sp, #0xc]
	bl __divsi3
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r2, #0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r7, #0x2c]
	mov r8, r0
	mov r2, sb
	ldrb r2, [r2]
	mov sb, r2
	ldrh r0, [r7, #0x30]
	adds r5, r0, r5
	subs r5, r5, r6
	ldr r0, .L08094DBC @ =0x000001FF
	ands r5, r0
	subs r4, #0x18
	ldr r3, [sp, #0xc]
	subs r4, r3, r4
	ands r4, r0
	str r1, [sp]
	str r1, [sp, #4]
	ldrh r0, [r7, #0x2a]
	movs r1, #0xc
	bl __divsi3
	movs r1, #8
	subs r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #8]
	mov r0, r8
	mov r1, sb
	adds r2, r5, #0
	adds r3, r4, #0
	bl func_fe6_08094878
	ldrh r0, [r7, #0x2a]
	adds r0, #4
	strh r0, [r7, #0x2a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x60
	bne .L08094E10
	mov r1, sl
	strh r1, [r7, #0x2a]
	adds r0, r7, #0
	bl Proc_Break
	b .L08094E10
	.align 2, 0
.L08094DB8: .4byte gSinLut
.L08094DBC: .4byte 0x000001FF
.L08094DC0:
	ldrh r1, [r7, #0x2a]
	adds r0, r1, #0
	adds r2, r1, #0
	asrs r6, r0, #4
	movs r0, #0x10
	subs r5, r0, r6
	adds r3, r5, #0
	ldrh r4, [r7, #0x2c]
	mov r2, sb
	ldrb r5, [r2]
	ldrh r0, [r7, #0x30]
	subs r2, r0, r3
	movs r0, #0x18
	subs r3, r0, r3
	str r1, [sp]
	movs r1, #0x80
	lsls r1, r1, #1
	mov r8, r1
	str r1, [sp, #4]
	movs r0, #0x10
	subs r0, r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r1, r5, #0
	bl func_fe6_08094878
	ldrh r0, [r7, #0x2a]
	adds r0, #0x10
	strh r0, [r7, #0x2a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r8
	bne .L08094E10
	movs r0, #0
	strh r0, [r7, #0x2a]
	adds r0, r7, #0
	bl Proc_Break
.L08094E10:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08094E20
func_fe6_08094E20: @ 0x08094E20
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r1, [r1]
	ldrh r2, [r4, #0x30]
	movs r3, #0x80
	lsls r3, r3, #1
	str r3, [sp]
	str r3, [sp, #4]
	movs r5, #0
	str r5, [sp, #8]
	movs r3, #0x18
	bl func_fe6_08094878
	strh r5, [r4, #0x2a]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08094E4C
func_fe6_08094E4C: @ 0x08094E4C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldrh r2, [r4, #0x2a]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r6, r2, r0
	subs r0, r0, r2
	mov ip, r0
	ldrh r0, [r4, #0x30]
	cmp r0, #0xff
	bls .L08094E78
	adds r1, r2, #0
	muls r1, r2, r1
	asrs r1, r1, #7
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	lsls r0, r0, #3
	rsbs r0, r0, #0
	b .L08094E86
.L08094E78:
	movs r1, #0xff
	ands r1, r0
	subs r1, #0x58
	adds r0, r2, #0
	muls r0, r2, r0
	asrs r0, r0, #7
	muls r0, r1, r0
.L08094E86:
	cmp r0, #0
	bge .L08094E8C
	adds r0, #0xff
.L08094E8C:
	asrs r0, r0, #8
	ldrh r3, [r4, #0x2c]
	adds r5, r4, #0
	adds r5, #0x2e
	ldrb r1, [r5]
	ldrh r7, [r4, #0x30]
	adds r2, r7, r0
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	mov r6, ip
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r4, #0x2a]
	asrs r0, r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	adds r0, r3, #0
	movs r3, #0x18
	bl func_fe6_08094878
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r7, [r4, #0x2a]
	cmp r7, r0
	bne .L08094ED8
	ldr r0, [r4, #0x14]
	ldrb r5, [r5]
	lsls r1, r5, #2
	adds r0, #0x34
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	adds r0, r4, #0
	bl Proc_Break
.L08094ED8:
	ldrh r0, [r4, #0x2a]
	adds r0, #8
	strh r0, [r4, #0x2a]
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08094EE8
func_fe6_08094EE8: @ 0x08094EE8
	push {r4, lr}
	adds r2, r0, #0
	lsls r4, r1, #0x18
	lsrs r4, r4, #0x18
	ldr r0, .L08094F04 @ =gUnk_0868FF4C
	adds r1, r2, #0
	bl SpawnProc
	adds r1, r0, #0
	adds r1, #0x2e
	strb r4, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L08094F04: .4byte gUnk_0868FF4C

	thumb_func_start func_fe6_08094F08
func_fe6_08094F08: @ 0x08094F08
	push {lr}
	bl EnablePalSync
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08094F14
func_fe6_08094F14: @ 0x08094F14
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	movs r0, #0
	strh r0, [r3, #0x2a]
	ldr r0, .L08094F88 @ =gPal
	movs r1, #0
	movs r4, #0xf
	ldr r2, .L08094F8C @ =0x000003FE
	adds r0, r0, r2
.L08094F2A:
	strh r1, [r0]
	subs r0, #2
	subs r4, #1
	cmp r4, #0
	bge .L08094F2A
	adds r0, r3, #0
	adds r0, #0x2e
	movs r1, #0
	strb r1, [r0]
	adds r2, r3, #0
	adds r2, #0x2d
	strb r1, [r2]
	movs r4, #0
	adds r7, r3, #0
	adds r7, #0x2c
	ldr r1, .L08094F90 @ =gUnk_08690A99
	mov r8, r1
	adds r6, r0, #0
	adds r5, r2, #0
.L08094F50:
	ldrb r0, [r7]
	add r0, r8
	ldrb r0, [r0]
	bl GetJInfo
	adds r0, #0x28
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq .L08094F74
	movs r0, #1
	lsls r0, r4
	ldrb r2, [r6]
	orrs r0, r2
	strb r0, [r6]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
.L08094F74:
	adds r4, #1
	cmp r4, #7
	ble .L08094F50
	bl EnablePalSync
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08094F88: .4byte gPal
.L08094F8C: .4byte 0x000003FE
.L08094F90: .4byte gUnk_08690A99

	thumb_func_start func_fe6_08094F94
func_fe6_08094F94: @ 0x08094F94
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x18
	movs r7, #0xe0
	lsls r7, r7, #8
	cmp r1, #0
	beq .L08094FB2
	movs r7, #0xf0
	lsls r7, r7, #8
.L08094FB2:
	ldr r4, .L08094FF4 @ =gUnk_086900F8
	str r7, [sp]
	movs r0, #4
	movs r1, #0x74
	movs r2, #0x48
	adds r3, r4, #0
	bl PutSpriteExt
	movs r5, #0
	cmp r5, r8
	bge .L0809501E
	mov sb, r4
	movs r6, #0x74
	movs r4, #0x74
.L08094FCE:
	mov r0, r8
	subs r0, #1
	cmp r5, r0
	bge .L08094FF8
	str r7, [sp]
	movs r0, #4
	adds r1, r4, #0
	movs r2, #0x48
	mov r3, sb
	bl PutSpriteExt
	str r7, [sp]
	movs r0, #4
	adds r1, r6, #0
	movs r2, #0x48
	mov r3, sb
	bl PutSpriteExt
	b .L08095014
	.align 2, 0
.L08094FF4: .4byte gUnk_086900F8
.L08094FF8:
	str r7, [sp]
	movs r0, #4
	adds r1, r4, #0
	movs r2, #0x48
	ldr r3, .L0809502C @ =gUnk_086900F0
	bl PutSpriteExt
	str r7, [sp]
	movs r0, #4
	adds r1, r6, #0
	movs r2, #0x48
	ldr r3, .L08095030 @ =gUnk_08690100
	bl PutSpriteExt
.L08095014:
	adds r6, #8
	subs r4, #8
	adds r5, #1
	cmp r5, r8
	blt .L08094FCE
.L0809501E:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0809502C: .4byte gUnk_086900F0
.L08095030: .4byte gUnk_08690100

	thumb_func_start func_fe6_08095034
func_fe6_08095034: @ 0x08095034
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sb, r2
	movs r0, #0xe0
	lsls r0, r0, #8
	mov sl, r0
	cmp r5, #0
	beq .L08095060
	movs r1, #0xf0
	lsls r1, r1, #8
	mov sl, r1
.L08095060:
	movs r4, #0
	ldr r6, .L080950F0 @ =gPal
	movs r7, #0xf8
	lsls r7, r7, #2
	adds r3, r6, r7
	lsls r2, r5, #0x10
	movs r0, #0xf0
	lsls r0, r0, #1
	mov ip, r0
.L08095072:
	adds r0, r5, r4
	movs r1, #0xf
	cmp r0, #0xf
	bgt .L0809507C
	lsrs r1, r2, #0x10
.L0809507C:
	mov r7, ip
	adds r0, r1, r7
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	strh r0, [r3]
	adds r3, #2
	movs r0, #0x80
	lsls r0, r0, #9
	adds r2, r2, r0
	adds r4, #1
	cmp r4, #0xf
	ble .L08095072
	bl EnablePalSync
	movs r4, #0
	mov r1, r8
	lsls r0, r1, #5
	subs r0, #0x88
	ldr r6, .L080950F4 @ =gUnk_086900BC
	rsbs r5, r0, #0
.L080950A6:
	mov r0, sb
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L080950C8
	ldr r1, .L080950F8 @ =0x000001FF
	ands r1, r5
	ldr r3, [r6]
	movs r0, #0xf0
	lsls r0, r0, #8
	str r0, [sp]
	movs r0, #4
	movs r2, #0x50
	bl PutSpriteExt
	adds r5, #0x20
.L080950C8:
	adds r6, #4
	adds r4, #1
	cmp r4, #7
	ble .L080950A6
	ldr r3, .L080950FC @ =gUnk_086900DC
	mov r7, sl
	str r7, [sp]
	movs r0, #4
	movs r1, #0x90
	movs r2, #0x50
	bl PutSpriteExt
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080950F0: .4byte gPal
.L080950F4: .4byte gUnk_086900BC
.L080950F8: .4byte 0x000001FF
.L080950FC: .4byte gUnk_086900DC

	thumb_func_start func_fe6_08095100
func_fe6_08095100: @ 0x08095100
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	adds r1, r0, #0
	strh r0, [r4, #0x2a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xd
	bhi .L08095120
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl func_fe6_08094F94
	b .L08095132
.L08095120:
	movs r0, #0xe
	movs r1, #0
	bl func_fe6_08094F94
	movs r0, #0
	strh r0, [r4, #0x2a]
	adds r0, r4, #0
	bl Proc_Break
.L08095132:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08095138
func_fe6_08095138: @ 0x08095138
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	adds r1, r0, #0
	strh r0, [r4, #0x2a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bls .L08095156
	movs r5, #0
	adds r0, r4, #0
	bl Proc_Break
	b .L0809515E
.L08095156:
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
.L0809515E:
	movs r0, #0xe
	movs r1, #0
	bl func_fe6_08094F94
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r1, [r0]
	adds r0, #1
	ldrb r2, [r0]
	adds r0, r5, #0
	bl func_fe6_08095034
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0809517C
func_fe6_0809517C: @ 0x0809517C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe
	movs r1, #0
	bl func_fe6_08094F94
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r1, [r0]
	adds r0, #1
	ldrb r2, [r0]
	movs r0, #0
	bl func_fe6_08095034
	movs r0, #0
	strh r0, [r4, #0x2a]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080951A4
func_fe6_080951A4: @ 0x080951A4
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2a]
	adds r0, #1
	strh r0, [r2, #0x2a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x11
	cmp r0, #0x10
	bls .L080951BE
	adds r0, r2, #0
	bl Proc_Break
	b .L080951D8
.L080951BE:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r2, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	adds r2, #0x2e
	ldrb r2, [r2]
	bl func_fe6_08095034
	movs r0, #0xe
	movs r1, #1
	bl func_fe6_08094F94
.L080951D8:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080951DC
func_fe6_080951DC: @ 0x080951DC
	push {r4, lr}
	adds r2, r0, #0
	lsls r4, r1, #0x18
	lsrs r4, r4, #0x18
	ldr r0, .L080951F8 @ =gUnk_0868FF84
	adds r1, r2, #0
	bl SpawnProc
	adds r1, r0, #0
	adds r1, #0x2c
	strb r4, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L080951F8: .4byte gUnk_0868FF84

	thumb_func_start func_fe6_080951FC
func_fe6_080951FC: @ 0x080951FC
	ldr r0, .L08095224 @ =0x04000006
	ldrh r0, [r0]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x6d
	bhi .L08095234
	ldr r3, .L08095228 @ =0x04000008
	ldrh r2, [r3]
	ldr r1, .L0809522C @ =0x0000FFFC
	adds r0, r1, #0
	ands r0, r2
	adds r0, #2
	strh r0, [r3]
	ldr r2, .L08095230 @ =0x0400000C
	ldrh r0, [r2]
	ands r1, r0
	adds r1, #2
	b .L0809524A
	.align 2, 0
.L08095224: .4byte 0x04000006
.L08095228: .4byte 0x04000008
.L0809522C: .4byte 0x0000FFFC
.L08095230: .4byte 0x0400000C
.L08095234:
	ldr r3, .L08095250 @ =0x04000008
	ldrh r2, [r3]
	ldr r1, .L08095254 @ =0x0000FFFC
	adds r0, r1, #0
	ands r0, r2
	adds r0, #1
	strh r0, [r3]
	ldr r2, .L08095258 @ =0x0400000C
	ldrh r0, [r2]
	ands r1, r0
	adds r1, #1
.L0809524A:
	strh r1, [r2]
	bx lr
	.align 2, 0
.L08095250: .4byte 0x04000008
.L08095254: .4byte 0x0000FFFC
.L08095258: .4byte 0x0400000C

	thumb_func_start func_fe6_0809525C
func_fe6_0809525C: @ 0x0809525C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, .L08095328 @ =gDispIo
	mov ip, r0
	mov r2, ip
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	mov r1, ip
	adds r1, #0x44
	movs r2, #0
	movs r3, #0x10
	mov r8, r3
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x46
	strb r2, [r0]
	ldr r0, .L0809532C @ =0x0000FFE0
	mov r1, ip
	ldrh r1, [r1, #0x3c]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	ldr r1, .L08095330 @ =0x0000E0FF
	ands r0, r1
	movs r3, #0xe0
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	mov r1, ip
	strh r0, [r1, #0x3c]
	movs r5, #0x20
	ldrb r0, [r1, #1]
	orrs r0, r5
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r3, ip
	strb r0, [r3, #1]
	mov r0, ip
	adds r0, #0x2d
	strb r2, [r0]
	adds r0, #4
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x2c
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xa0
	strb r0, [r1]
	mov r6, ip
	adds r6, #0x34
	movs r0, #1
	ldrb r1, [r6]
	orrs r1, r0
	movs r2, #2
	orrs r1, r2
	movs r4, #4
	orrs r1, r4
	movs r3, #8
	orrs r1, r3
	mov r2, r8
	orrs r1, r2
	mov r7, ip
	adds r7, #0x36
	ldrb r2, [r7]
	orrs r0, r2
	movs r2, #3
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r4
	orrs r0, r3
	mov r3, r8
	orrs r0, r3
	orrs r1, r5
	strb r1, [r6]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r7]
	mov r0, ip
	adds r0, #0x3d
	ldrb r1, [r0]
	orrs r5, r1
	strb r5, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08095328: .4byte gDispIo
.L0809532C: .4byte 0x0000FFE0
.L08095330: .4byte 0x0000E0FF

	thumb_func_start func_fe6_08095334
func_fe6_08095334: @ 0x08095334
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r7, r0, #0
	movs r0, #0
	str r0, [sp, #0x1c]
	add r1, sp, #4
	ldr r0, .L08095358 @ =gUnk_0835C80C
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	movs r6, #4
	ldr r4, .L0809535C @ =gUnk_08690A99
	b .L08095362
	.align 2, 0
.L08095358: .4byte gUnk_0835C80C
.L0809535C: .4byte gUnk_08690A99
.L08095360:
	adds r6, #1
.L08095362:
	movs r0, #0x31
	adds r0, r0, r7
	mov sl, r0
	cmp r6, #7
	bgt .L08095384
	ldrb r1, [r0]
	adds r0, r1, r4
	ldrb r0, [r0]
	bl GetJInfo
	adds r0, #0x28
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq .L08095360
	movs r2, #1
	str r2, [sp, #0x1c]
.L08095384:
	movs r0, #0
	strh r0, [r7, #0x2a]
	strh r0, [r7, #0x2c]
	strh r0, [r7, #0x2e]
	adds r1, r7, #0
	adds r1, #0x3e
	movs r0, #1
	strb r0, [r1]
	adds r1, #6
	movs r0, #0xfa
	strb r0, [r1]
	ldr r0, .L080953EC @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L080953F0 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L080953F4 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	mov r3, sl
	ldrb r0, [r3]
	cmp r0, #0
	bne .L08095400
	strh r0, [r7, #0x2e]
	ldr r4, .L080953F8 @ =gUnk_086905F8
	mov r8, r4
	adds r5, r7, #0
	adds r5, #0x30
	ldr r4, .L080953FC @ =gDispIo
	adds r6, r7, #0
	adds r6, #0x38
	str r6, [sp, #0x24]
	movs r0, #0x39
	adds r0, r0, r7
	mov sb, r0
	adds r1, r7, #0
	adds r1, #0x3a
	str r1, [sp, #0x28]
	adds r2, r7, #0
	adds r2, #0x3b
	str r2, [sp, #0x2c]
	adds r3, r7, #0
	adds r3, #0x3c
	str r3, [sp, #0x30]
	adds r6, #5
	str r6, [sp, #0x34]
	b .L08095448
	.align 2, 0
.L080953EC: .4byte gBg0Tm
.L080953F0: .4byte gBg1Tm
.L080953F4: .4byte gBg2Tm
.L080953F8: .4byte gUnk_086905F8
.L080953FC: .4byte gDispIo
.L08095400:
	movs r6, #0
	movs r2, #0
	ldr r0, .L080955E8 @ =gUnk_086905F8
	mov r8, r0
	adds r5, r7, #0
	adds r5, #0x30
	ldr r4, .L080955EC @ =gDispIo
	adds r1, r7, #0
	adds r1, #0x38
	str r1, [sp, #0x24]
	movs r3, #0x39
	adds r3, r3, r7
	mov sb, r3
	adds r0, r7, #0
	adds r0, #0x3a
	str r0, [sp, #0x28]
	adds r1, #3
	str r1, [sp, #0x2c]
	adds r3, r7, #0
	adds r3, #0x3c
	str r3, [sp, #0x30]
	adds r0, #3
	str r0, [sp, #0x34]
	mov r3, sl
	mov r1, r8
.L08095432:
	adds r1, #4
	adds r6, #1
	ldrb r0, [r1, #1]
	cmp r0, #0
	bne .L08095432
	adds r2, #1
	ldrb r0, [r3]
	cmp r2, r0
	bne .L08095432
	adds r0, r6, #1
	strh r0, [r7, #0x2e]
.L08095448:
	ldrh r1, [r7, #0x2e]
	lsls r0, r1, #2
	add r0, r8
	ldrb r0, [r0]
	strb r0, [r5]
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r2, [r4, #1]
	ands r0, r2
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r4, #1]
	bl ResetTextFont
	bl ResetText
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r3, [r4, #0xc]
	ands r0, r3
	movs r2, #2
	orrs r0, r2
	strb r0, [r4, #0xc]
	adds r0, r1, #0
	ldrb r6, [r4, #0x10]
	ands r0, r6
	orrs r0, r2
	strb r0, [r4, #0x10]
	ldrb r0, [r4, #0x14]
	ands r1, r0
	orrs r1, r2
	strb r1, [r4, #0x14]
	movs r0, #3
	ldrb r1, [r4, #0x18]
	orrs r0, r1
	strb r0, [r4, #0x18]
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
	ldr r4, .L080955F0 @ =gUnk_0831B0A8
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r5, #0xc0
	lsls r5, r5, #0x13
	adds r1, r1, r5
	adds r0, r4, #0
	bl Decompress
	ldr r0, .L080955F4 @ =gUnk_0835AB08
	movs r1, #0xa0
	lsls r1, r1, #1
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L080955F8 @ =gBg3Tm
	ldr r1, .L080955FC @ =gUnk_0835AB28
	movs r2, #0xa0
	lsls r2, r2, #8
	bl TmApplyTsa_thm
	ldr r4, .L08095600 @ =gUnk_0835A3E8
	movs r0, #2
	bl GetBgChrOffset
	adds r1, r0, #0
	adds r1, r1, r5
	adds r0, r4, #0
	bl Decompress
	ldr r0, .L08095604 @ =gUnk_0835A5D0
	movs r1, #0x90
	lsls r1, r1, #1
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L08095608 @ =gBg2Tm
	ldr r1, .L0809560C @ =gUnk_0835A5F0
	movs r2, #0x90
	lsls r2, r2, #8
	bl TmApplyTsa_thm
	movs r0, #0xf
	bl EnableBgSync
	ldr r5, .L08095610 @ =gBg0Tm
	adds r0, r5, #0
	movs r1, #0
	bl TmFill
	ldr r4, .L08095614 @ =gUnk_08690A99
	mov r2, sl
	ldrb r2, [r2]
	adds r0, r2, r4
	ldrb r0, [r0]
	bl GetJInfo
	ldrb r0, [r0, #0xb]
	ldr r3, [sp, #0x24]
	strb r0, [r3]
	mov r6, sl
	ldrb r6, [r6]
	adds r0, r6, r4
	ldrb r0, [r0]
	bl GetJInfo
	ldrb r0, [r0, #0xc]
	mov r1, sb
	strb r0, [r1]
	mov r2, sl
	ldrb r2, [r2]
	adds r0, r2, r4
	ldrb r0, [r0]
	bl GetJInfo
	ldrb r0, [r0, #0xd]
	ldr r3, [sp, #0x28]
	strb r0, [r3]
	mov r6, sl
	ldrb r6, [r6]
	adds r0, r6, r4
	ldrb r0, [r0]
	bl GetJInfo
	ldrb r0, [r0, #0xe]
	ldr r1, [sp, #0x2c]
	strb r0, [r1]
	mov r2, sl
	ldrb r2, [r2]
	adds r0, r2, r4
	ldrb r0, [r0]
	bl GetJInfo
	ldrb r0, [r0, #0xf]
	ldr r3, [sp, #0x30]
	strb r0, [r3]
	mov r6, sl
	ldrb r6, [r6]
	adds r4, r6, r4
	ldrb r0, [r4]
	bl GetJInfo
	ldrb r0, [r0, #0x10]
	ldr r1, [sp, #0x34]
	strb r0, [r1]
	movs r6, #0
	ldr r2, .L08095618 @ =0x0200FF24
	str r2, [sp, #0x20]
	movs r3, #0x4a
	adds r3, r3, r5
	mov sb, r3
	adds r5, #0x42
	mov r8, r5
	adds r4, r2, #0
	add r5, sp, #4
.L080955B2:
	adds r0, r4, #0
	movs r1, #3
	bl InitText
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #3
	bl Text_SetColor
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetCursor
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq .L08095620
	cmp r6, #1
	bne .L08095620
	ldr r0, [sp, #0x20]
	adds r0, #8
	ldr r1, .L0809561C @ =gUnk_0835C824
	bl Text_DrawString
	b .L08095628
	.align 2, 0
.L080955E8: .4byte gUnk_086905F8
.L080955EC: .4byte gDispIo
.L080955F0: .4byte gUnk_0831B0A8
.L080955F4: .4byte gUnk_0835AB08
.L080955F8: .4byte gBg3Tm
.L080955FC: .4byte gUnk_0835AB28
.L08095600: .4byte gUnk_0835A3E8
.L08095604: .4byte gUnk_0835A5D0
.L08095608: .4byte gBg2Tm
.L0809560C: .4byte gUnk_0835A5F0
.L08095610: .4byte gBg0Tm
.L08095614: .4byte gUnk_08690A99
.L08095618: .4byte 0x0200FF24
.L0809561C: .4byte gUnk_0835C824
.L08095620:
	ldr r1, [r5]
	adds r0, r4, #0
	bl Text_DrawString
.L08095628:
	adds r0, r4, #0
	mov r1, r8
	bl PutText
	ldr r1, [sp, #0x24]
	adds r0, r1, r6
	ldrb r2, [r0]
	mov r0, sb
	movs r1, #0
	bl PutNumber
	movs r2, #0x80
	add sb, r2
	add r8, r2
	adds r4, #8
	adds r5, #4
	adds r6, #1
	cmp r6, #5
	ble .L080955B2
	movs r5, #0
	adds r0, r7, #0
	bl func_fe6_08095D2C
	str r0, [r7, #0x40]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #2
	movs r2, #0
	bl InitTalk
	bl SetInitTalkTextFont
	bl ClearTalkText
	bl EndTalk
	ldr r1, .L08095800 @ =gUnk_086905B0
	mov r3, sl
	ldrb r3, [r3]
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #2
	movs r1, #0xf
	bl StartTalkMsg
	movs r0, #0
	bl SetTalkPrintColor
	movs r0, #1
	bl SetTalkFlag
	movs r0, #2
	bl SetTalkFlag
	movs r0, #4
	bl SetTalkFlag
	movs r0, #8
	bl SetTalkFlag
	movs r0, #0x40
	bl SetTalkFlag
	movs r0, #4
	bl SetTalkPrintDelay
	ldr r0, .L08095804 @ =0x02000400
	movs r2, #0
	movs r1, #0x82
	lsls r1, r1, #1
	strh r1, [r0, #2]
	movs r1, #0x58
	strh r1, [r0, #4]
	ldr r1, .L08095808 @ =gUnk_0869058C
	mov r4, sl
	ldrb r4, [r4]
	adds r1, r4, r1
	ldrb r1, [r1]
	strh r1, [r0, #6]
	movs r1, #6
	strh r1, [r0, #8]
	strb r2, [r0, #1]
	movs r4, #1
	strh r4, [r0, #0xa]
	movs r1, #0xc0
	lsls r1, r1, #1
	strh r1, [r0, #0xc]
	movs r1, #2
	strh r1, [r0, #0xe]
	ldr r1, .L0809580C @ =0x02000434
	str r1, [r0, #0x18]
	ldr r1, .L08095810 @ =0x02002434
	str r1, [r0, #0x20]
	ldr r1, .L08095814 @ =0x02007C34
	str r1, [r0, #0x1c]
	ldr r1, .L08095818 @ =0x02007CD4
	str r1, [r0, #0x24]
	ldr r2, .L0809581C @ =0x0200A6D4
	str r2, [r0, #0x2c]
	ldr r3, .L08095820 @ =gUnk_086909A4
	mov r6, sl
	ldrb r6, [r6]
	lsls r1, r6, #2
	mov r7, sl
	ldrb r7, [r7]
	adds r1, r1, r7
	adds r1, r1, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r2]
	mov r6, sl
	ldrb r6, [r6]
	lsls r1, r6, #2
	mov r7, sl
	ldrb r7, [r7]
	adds r1, r1, r7
	adds r1, #1
	adds r1, r1, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r2, #2]
	mov r6, sl
	ldrb r6, [r6]
	lsls r1, r6, #2
	mov r7, sl
	ldrb r7, [r7]
	adds r1, r1, r7
	adds r1, #2
	adds r1, r1, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r2, #4]
	mov r6, sl
	ldrb r6, [r6]
	lsls r1, r6, #2
	mov r7, sl
	ldrb r7, [r7]
	adds r1, r1, r7
	adds r1, #3
	adds r1, r1, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r2, #6]
	mov r6, sl
	ldrb r6, [r6]
	lsls r1, r6, #2
	mov r7, sl
	ldrb r7, [r7]
	adds r1, r1, r7
	adds r1, #4
	adds r1, r1, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r2, #8]
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r2, #0xe]
	movs r3, #0xf
	strh r3, [r2, #0x10]
	subs r1, #0x80
	strh r1, [r2, #0xa]
	strh r3, [r2, #0xc]
	strh r4, [r2, #0x12]
	ldr r1, .L08095824 @ =gBg1Tm
	str r1, [r2, #0x14]
	ldr r1, .L08095828 @ =0x0200A6FC
	str r1, [r2, #0x18]
	ldr r1, .L0809582C @ =0x0200C6FC
	str r1, [r2, #0x1c]
	ldr r1, .L08095830 @ =0x0200CEFC
	str r1, [r2, #0x20]
	ldr r1, .L08095834 @ =func_fe6_0809525C
	str r1, [r2, #0x24]
	bl NewEkrUnitMainMini
	ldr r4, .L08095838 @ =0x0200DEFC
	ldr r1, .L0809583C @ =gUnk_08690A53
	mov r2, sl
	ldrb r2, [r2]
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strh r0, [r4]
	movs r0, #0xa
	strh r0, [r4, #2]
	movs r0, #0xe0
	lsls r0, r0, #2
	strh r0, [r4, #4]
	mov r3, sl
	ldrb r3, [r3]
	lsls r0, r3, #1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strh r0, [r4, #6]
	movs r0, #0xb
	strh r0, [r4, #8]
	movs r0, #0xf0
	lsls r0, r0, #2
	strh r0, [r4, #0xa]
	strh r5, [r4, #0xc]
	ldr r0, .L08095840 @ =0x0000FFFF
	strh r0, [r4, #0xe]
	ldr r0, .L08095844 @ =0x06010000
	str r0, [r4, #0x1c]
	ldr r0, .L08095848 @ =0x0200DF24
	str r0, [r4, #0x20]
	adds r0, r4, #0
	bl func_fe6_0804BF40
	movs r3, #0x98
	lsls r3, r3, #1
	movs r0, #0x68
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0xd0
	movs r2, #0x68
	bl func_fe6_0804C318
	ldr r0, .L0809584C @ =func_fe6_080951FC
	bl SetOnHBlankA
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08095800: .4byte gUnk_086905B0
.L08095804: .4byte 0x02000400
.L08095808: .4byte gUnk_0869058C
.L0809580C: .4byte 0x02000434
.L08095810: .4byte 0x02002434
.L08095814: .4byte 0x02007C34
.L08095818: .4byte 0x02007CD4
.L0809581C: .4byte 0x0200A6D4
.L08095820: .4byte gUnk_086909A4
.L08095824: .4byte gBg1Tm
.L08095828: .4byte 0x0200A6FC
.L0809582C: .4byte 0x0200C6FC
.L08095830: .4byte 0x0200CEFC
.L08095834: .4byte func_fe6_0809525C
.L08095838: .4byte 0x0200DEFC
.L0809583C: .4byte gUnk_08690A53
.L08095840: .4byte 0x0000FFFF
.L08095844: .4byte 0x06010000
.L08095848: .4byte 0x0200DF24
.L0809584C: .4byte func_fe6_080951FC

	thumb_func_start func_fe6_08095850
func_fe6_08095850: @ 0x08095850
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	adds r5, r7, #0
	adds r5, #0x44
	movs r0, #0x50
	ldrh r1, [r7, #0x2a]
	subs r0, r0, r1
	movs r1, #0xe
	bl __divsi3
	adds r0, #1
	ldrb r1, [r5]
	subs r0, r1, r0
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb3
	bhi .L08095882
	movs r0, #0xb4
	strb r0, [r5]
.L08095882:
	ldr r0, .L08095934 @ =gDispIo
	mov ip, r0
	movs r2, #1
	ldrb r0, [r0, #1]
	orrs r0, r2
	movs r1, #2
	mov r8, r1
	mov r1, r8
	orrs r0, r1
	movs r1, #4
	mov sl, r1
	mov r1, sl
	orrs r0, r1
	movs r1, #8
	mov sb, r1
	mov r1, sb
	orrs r0, r1
	movs r4, #0x10
	orrs r0, r4
	movs r1, #0x20
	orrs r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r1, ip
	strb r0, [r1, #1]
	mov r0, ip
	adds r0, #0x2d
	movs r1, #0
	strb r1, [r0]
	ldrh r6, [r7, #0x2a]
	adds r1, r6, #0
	movs r0, #0x50
	subs r0, r0, r1
	mov r3, ip
	adds r3, #0x31
	strb r0, [r3]
	subs r3, #5
	movs r0, #0xf0
	strb r0, [r3]
	adds r1, #0x50
	mov r0, ip
	adds r0, #0x30
	strb r1, [r0]
	adds r0, #4
	ldrb r1, [r0]
	orrs r2, r1
	mov r1, r8
	orrs r2, r1
	mov r1, sl
	orrs r2, r1
	mov r1, sb
	orrs r2, r1
	orrs r2, r4
	strb r2, [r0]
	mov r2, ip
	adds r2, #0x36
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2]
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x50
	bne .L08095938
	movs r0, #0xb4
	strb r0, [r5]
	movs r0, #0
	strh r0, [r7, #0x2a]
	adds r0, r7, #0
	bl Proc_Break
	ldr r0, [r7, #0x40]
	bl func_fe6_08095D48
	b .L0809593C
	.align 2, 0
.L08095934: .4byte gDispIo
.L08095938:
	adds r0, r6, #4
	strh r0, [r7, #0x2a]
.L0809593C:
	ldr r0, .L08095974 @ =0x02000400
	adds r4, r7, #0
	adds r4, #0x44
	ldrb r1, [r4]
	movs r2, #0x58
	bl func_fe6_0804BE20
	ldr r0, .L08095978 @ =0x0200DEFC
	ldrb r3, [r4]
	adds r1, r3, #0
	subs r1, #0x30
	adds r3, #0x30
	movs r2, #0x68
	str r2, [sp]
	bl func_fe6_0804C318
	ldr r0, [r7, #0x40]
	movs r1, #0x78
	bl func_fe6_08095D40
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08095974: .4byte 0x02000400
.L08095978: .4byte 0x0200DEFC

	thumb_func_start func_fe6_0809597C
func_fe6_0809597C: @ 0x0809597C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r6, #0
	ldrh r1, [r4, #0x2c]
	ldr r0, .L08095994 @ =0x0000018F
	cmp r1, r0
	bls .L08095998
	ldr r0, [r4, #0x34]
	adds r0, #0x2c
	movs r1, #2
	strb r1, [r0]
	b .L080959E8
	.align 2, 0
.L08095994: .4byte 0x0000018F
.L08095998:
	ldrh r2, [r4, #0x2a]
	adds r2, #1
	strh r2, [r4, #0x2a]
	adds r0, r1, #1
	strh r0, [r4, #0x2c]
	ldr r1, .L08095A18 @ =gUnk_086905F8
	ldrh r3, [r4, #0x2e]
	lsls r0, r3, #2
	adds r1, r0, r1
	ldrb r0, [r1, #1]
	cmp r0, #0
	beq .L080959E8
	adds r1, r0, #0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bhi .L080959EC
	cmp r1, #0xff
	bne .L080959E8
	adds r5, r4, #0
	adds r5, #0x3e
	ldrb r0, [r5]
	cmp r0, #0
	beq .L080959DA
	ldr r0, .L08095A1C @ =0x02000400
	bl func_fe6_0804BE4C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080959EC
	ldrb r0, [r5]
	cmp r0, #0
	bne .L080959E8
.L080959DA:
	ldr r0, .L08095A1C @ =0x02000400
	bl func_fe6_0804BE80
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080959E8
	movs r6, #1
.L080959E8:
	cmp r6, #0
	beq .L08095A62
.L080959EC:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	ldr r7, .L08095A18 @ =gUnk_086905F8
	lsls r0, r0, #2
	adds r1, r0, r7
	ldrb r0, [r1, #1]
	cmp r0, #0
	beq .L08095A62
	ldrb r2, [r1]
	cmp r2, #0xff
	bne .L08095A20
	ldr r0, .L08095A1C @ =0x02000400
	bl func_fe6_0804BE6C
	adds r1, r4, #0
	adds r1, #0x3e
	movs r0, #0
	strb r0, [r1]
	adds r6, r4, #0
	adds r6, #0x30
	b .L08095A52
	.align 2, 0
.L08095A18: .4byte gUnk_086905F8
.L08095A1C: .4byte 0x02000400
.L08095A20:
	adds r0, r4, #0
	adds r0, #0x30
	adds r6, r0, #0
	ldrb r0, [r6]
	cmp r0, r2
	beq .L08095A52
	ldr r5, .L08095A68 @ =0x02000400
	ldrb r0, [r1]
	strh r0, [r5, #8]
	adds r0, r5, #0
	bl func_fe6_0804BCC8
	ldrh r1, [r4, #0x2e]
	lsls r0, r1, #2
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, #4
	bne .L08095A4A
	adds r0, r5, #0
	bl func_fe6_0804BE6C
.L08095A4A:
	adds r1, r4, #0
	adds r1, #0x3e
	movs r0, #1
	strb r0, [r1]
.L08095A52:
	ldr r1, .L08095A6C @ =gUnk_086905F8
	ldrh r2, [r4, #0x2e]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #0
	strb r0, [r6]
	strh r1, [r4, #0x2a]
.L08095A62:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08095A68: .4byte 0x02000400
.L08095A6C: .4byte gUnk_086905F8

	thumb_func_start func_fe6_08095A70
func_fe6_08095A70: @ 0x08095A70
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08095A74
func_fe6_08095A74: @ 0x08095A74
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	bl SetOnHBlankA
	bl EndTalk
	bl func_fe6_08057F24
	ldr r0, .L08095AB0 @ =0x0200DEFC
	bl func_fe6_0804C2EC
	bl func_fe6_08057F08
	ldr r0, .L08095AB4 @ =0x02000400
	bl func_fe6_0804BF00
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq .L08095AA2
	movs r1, #4
	bl Proc_Goto
.L08095AA2:
	ldr r1, [r4, #0x34]
	movs r0, #0
	str r0, [r1, #0x38]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08095AB0: .4byte 0x0200DEFC
.L08095AB4: .4byte 0x02000400

	thumb_func_start func_fe6_08095AB8
func_fe6_08095AB8: @ 0x08095AB8
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x18
	lsrs r4, r4, #0x18
	ldr r0, .L08095ADC @ =gUnk_0868FFCC
	adds r1, r5, #0
	bl SpawnProc
	adds r2, r0, #0
	adds r2, #0x31
	movs r1, #0
	strb r4, [r2]
	str r5, [r0, #0x34]
	str r1, [r0, #0x40]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08095ADC: .4byte gUnk_0868FFCC

	thumb_func_start func_fe6_08095AE0
func_fe6_08095AE0: @ 0x08095AE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	ldr r0, [r0, #0x14]
	mov r1, ip
	str r0, [r1, #0x30]
	movs r1, #0
	movs r0, #0
	mov r2, ip
	strh r0, [r2, #0x2a]
	adds r2, #0x42
	strb r1, [r2]
	mov r1, ip
	adds r1, #0x43
	movs r0, #0xfa
	strb r0, [r1]
	movs r4, #0
	ldr r0, .L08095B48 @ =gUnk_08690D44
	mov sb, r0
	movs r1, #0x34
	add r1, ip
	mov r8, r1
	adds r7, r2, #0
	mov sl, sb
.L08095B16:
	lsls r0, r4, #2
	ldr r2, .L08095B4C @ =0x0200FF54
	adds r0, r0, r2
	movs r1, #0
	strb r1, [r0]
	strb r1, [r0, #1]
	mov r1, ip
	ldr r0, [r1, #0x30]
	adds r0, #0x31
	ldrb r0, [r0]
	lsls r3, r0, #2
	mov r2, sb
	adds r0, r3, r2
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L08095B64
	mov r0, r8
	adds r1, r0, r4
	movs r0, #0xff
	strb r0, [r1]
	b .L08095B98
	.align 2, 0
.L08095B48: .4byte gUnk_08690D44
.L08095B4C: .4byte 0x0200FF54
.L08095B50:
	mov r1, r8
	adds r0, r1, r4
	strb r5, [r0]
	ldrb r2, [r3, #6]
	ldrb r1, [r3, #5]
	subs r0, r2, r1
	ldrb r2, [r7]
	adds r0, r2, r0
	strb r0, [r7]
	b .L08095B92
.L08095B64:
	movs r5, #0
	ldr r1, .L08095BBC @ =gUnk_08690C14
	ldr r0, [r1]
	adds r6, r4, #1
	cmp r0, #0
	beq .L08095B92
	mov r2, sl
	adds r0, r3, r2
	ldr r0, [r0]
	adds r0, r0, r4
	movs r2, #0
	ldrsb r2, [r0, r2]
	adds r3, r1, #0
.L08095B7E:
	movs r0, #4
	ldrsb r0, [r3, r0]
	cmp r0, r2
	beq .L08095B50
	adds r1, #8
	adds r3, #8
	adds r5, #1
	ldr r0, [r1]
	cmp r0, #0
	bne .L08095B7E
.L08095B92:
	adds r4, r6, #0
	cmp r4, #0xd
	ble .L08095B16
.L08095B98:
	ldr r1, .L08095BC0 @ =0x06010000
	ldr r0, .L08095BC4 @ =gUnk_0835B040
	bl Decompress
	ldr r0, .L08095BC8 @ =gUnk_0835C034
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r2, #0x40
	bl ApplyPaletteExt
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08095BBC: .4byte gUnk_08690C14
.L08095BC0: .4byte 0x06010000
.L08095BC4: .4byte gUnk_0835B040
.L08095BC8: .4byte gUnk_0835C034

	thumb_func_start func_fe6_08095BCC
func_fe6_08095BCC: @ 0x08095BCC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r0, [sp, #0x10]
	ldr r1, .L08095D1C @ =gUnk_0835C829
	add r0, sp, #4
	movs r2, #0xc
	bl memcpy
	movs r0, #0
	mov sb, r0
	ldr r1, [sp, #0x10]
	adds r1, #0x42
	str r1, [sp, #0x18]
	ldr r2, [sp, #0x10]
	adds r2, #0x43
	str r2, [sp, #0x1c]
	ldr r3, [sp, #0x10]
	adds r3, #0x34
	str r3, [sp, #0x14]
.L08095BFA:
	ldr r1, [sp, #0x10]
	ldr r0, [r1, #0x30]
	adds r0, #0x38
	add r0, sb
	ldrb r0, [r0]
	mov r8, r0
	movs r7, #0
	lsrs r0, r0, #2
	movs r2, #1
	add r2, sb
	mov sl, r2
	cmp r7, r0
	bge .L08095C3E
	adds r6, r0, #0
	movs r4, #0x30
	mov r3, sb
	lsls r5, r3, #4
	adds r7, r6, #0
.L08095C1E:
	ldr r0, .L08095D20 @ =gUnk_0869006C
	ldr r3, [r0, #0xc]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [sp]
	movs r0, #0xd
	adds r1, r4, #0
	adds r2, r5, #0
	adds r2, #0x10
	bl PutSpriteExt
	adds r4, #8
	subs r7, #1
	cmp r7, #0
	bne .L08095C1E
	adds r7, r6, #0
.L08095C3E:
	movs r0, #3
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq .L08095C68
	lsls r1, r7, #3
	adds r1, #0x30
	mov r3, sb
	lsls r2, r3, #4
	adds r2, #0x10
	subs r0, #1
	lsls r0, r0, #2
	ldr r3, .L08095D20 @ =gUnk_0869006C
	adds r0, r0, r3
	ldr r3, [r0]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [sp]
	movs r0, #0xd
	bl PutSpriteExt
.L08095C68:
	mov sb, sl
	mov r0, sb
	cmp r0, #5
	ble .L08095BFA
	movs r0, #0x78
	ldr r1, [sp, #0x18]
	ldrb r1, [r1]
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	ldr r2, [sp, #0x1c]
	ldrb r2, [r2]
	adds r7, r2, r0
	movs r3, #0
	mov sb, r3
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
	cmp r0, #0xff
	beq .L08095D00
	ldr r5, .L08095D24 @ =gUnk_08690C14
	adds r4, r1, #0
.L08095C94:
	ldrb r2, [r4]
	lsls r0, r2, #3
	adds r0, r0, r5
	movs r1, #5
	ldrsb r1, [r0, r1]
	subs r1, r7, r1
	movs r3, #7
	ldrsb r3, [r0, r3]
	movs r2, #8
	subs r2, r2, r3
	ldr r3, [r0]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [sp]
	movs r0, #4
	bl PutSpriteExt
	ldrb r3, [r4]
	lsls r0, r3, #3
	adds r0, r0, r5
	movs r1, #5
	ldrsb r1, [r0, r1]
	subs r1, r7, r1
	subs r1, #2
	movs r3, #7
	ldrsb r3, [r0, r3]
	movs r2, #6
	subs r2, r2, r3
	ldr r3, [r0]
	movs r0, #0x80
	lsls r0, r0, #7
	str r0, [sp]
	movs r0, #4
	bl PutSpriteExt
	ldrb r1, [r4]
	lsls r0, r1, #3
	adds r0, r0, r5
	movs r1, #6
	ldrsb r1, [r0, r1]
	ldrb r0, [r0, #5]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	adds r7, r7, r1
	adds r4, #1
	movs r2, #1
	add sb, r2
	mov r3, sb
	cmp r3, #0xd
	bgt .L08095D00
	ldrb r0, [r4]
	cmp r0, #0xff
	bne .L08095C94
.L08095D00:
	ldr r1, [sp, #0x10]
	ldrh r0, [r1, #0x2a]
	cmp r0, #0xfe
	bhi .L08095D0C
	adds r0, #1
	strh r0, [r1, #0x2a]
.L08095D0C:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08095D1C: .4byte gUnk_0835C829
.L08095D20: .4byte gUnk_0869006C
.L08095D24: .4byte gUnk_08690C14

	thumb_func_start func_fe6_08095D28
func_fe6_08095D28: @ 0x08095D28
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08095D2C
func_fe6_08095D2C: @ 0x08095D2C
	push {lr}
	adds r1, r0, #0
	ldr r0, .L08095D3C @ =gUnk_08690014
	bl SpawnProc
	pop {r1}
	bx r1
	.align 2, 0
.L08095D3C: .4byte gUnk_08690014

	thumb_func_start func_fe6_08095D40
func_fe6_08095D40: @ 0x08095D40
	adds r0, #0x43
	strb r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08095D48
func_fe6_08095D48: @ 0x08095D48
	ldr r0, .L08095D54 @ =0x0200FF54
	movs r1, #0x80
	strb r1, [r0]
	movs r1, #2
	strb r1, [r0, #1]
	bx lr
	.align 2, 0
.L08095D54: .4byte 0x0200FF54

	thumb_func_start func_fe6_08095D58
func_fe6_08095D58: @ 0x08095D58
	bx lr
	.align 2, 0
