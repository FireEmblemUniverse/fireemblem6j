
	.include "macro.inc"

	.syntax unified

	thumb_func_start sub_804256C
sub_804256C: @ 0x0804256C
	ldr r1, .L08042574 @ =0x0203CCE4
	str r0, [r1]
	bx lr
	.align 2, 0
.L08042574: .4byte 0x0203CCE4

	thumb_func_start sub_8042578
sub_8042578: @ 0x08042578
	ldr r0, .L08042580 @ =0x0203CCE4
	ldr r0, [r0]
	bx lr
	.align 2, 0
.L08042580: .4byte 0x0203CCE4

	thumb_func_start sub_8042584
sub_8042584: @ 0x08042584
	push {r4, lr}
	ldr r4, .L080425A4 @ =0x0203CCEC
	ldr r0, .L080425A8 @ =gUnk_085CB508
	movs r1, #3
	bl SpawnProc
	str r0, [r4]
	ldr r1, .L080425AC @ =0x0203CCE8
	movs r0, #1
	str r0, [r1]
	bl LockGame
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080425A4: .4byte 0x0203CCEC
.L080425A8: .4byte gUnk_085CB508
.L080425AC: .4byte 0x0203CCE8

	thumb_func_start sub_80425B0
sub_80425B0: @ 0x080425B0
	push {lr}
	ldr r0, .L080425C0 @ =0x0203CCEC
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L080425C0: .4byte 0x0203CCEC

	thumb_func_start sub_80425C4
sub_80425C4: @ 0x080425C4
	ldr r0, .L080425D0 @ =0x0203CCE8
	ldr r0, [r0]
	cmp r0, #1
	beq .L080425D4
	movs r0, #0
	b .L080425D6
	.align 2, 0
.L080425D0: .4byte 0x0203CCE8
.L080425D4:
	movs r0, #1
.L080425D6:
	bx lr

	thumb_func_start sub_80425D8
sub_80425D8: @ 0x080425D8
	push {lr}
	ldr r1, .L080425E8 @ =0x0203CCE8
	movs r0, #0
	str r0, [r1]
	bl UnlockGame
	pop {r0}
	bx r0
	.align 2, 0
.L080425E8: .4byte 0x0203CCE8

	thumb_func_start nullsub_18
nullsub_18: @ 0x080425EC
	bx lr
	.align 2, 0

	thumb_func_start sub_80425F0
sub_80425F0: @ 0x080425F0
	push {r4, lr}
	bl BasInit
	ldr r4, .L0804263C @ =gUnk_Banim_0200005C
	ldr r0, .L08042640 @ =gUnk_085CB528
	movs r1, #3
	bl SpawnProc
	str r0, [r4]
	ldr r0, .L08042644 @ =sub_8042660
	bl SetMainFunc
	bl sub_8044900
	bl sub_805884C
	ldr r0, .L08042648 @ =gUnk_Banim_0201771C
	movs r1, #0
	str r1, [r0]
	ldr r0, .L0804264C @ =gUnk_Banim_02000010
	str r1, [r0]
	ldr r0, .L08042650 @ =gUnk_Banim_02000014
	str r1, [r0]
	ldr r0, .L08042654 @ =gUnk_Banim_02000018
	str r1, [r0]
	ldr r0, .L08042658 @ =gUnk_Banim_0200001C
	str r1, [r0]
	ldr r0, .L0804265C @ =0x0203CCF0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08042634
	bl sub_805C520
.L08042634:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804263C: .4byte gUnk_Banim_0200005C
.L08042640: .4byte gUnk_085CB528
.L08042644: .4byte sub_8042660
.L08042648: .4byte gUnk_Banim_0201771C
.L0804264C: .4byte gUnk_Banim_02000010
.L08042650: .4byte gUnk_Banim_02000014
.L08042654: .4byte gUnk_Banim_02000018
.L08042658: .4byte gUnk_Banim_0200001C
.L0804265C: .4byte 0x0203CCF0

	thumb_func_start sub_8042660
sub_8042660: @ 0x08042660
	push {lr}
	ldr r0, .L08042678 @ =gKeySt
	ldr r0, [r0]
	bl RefreshKeySt
	ldr r0, .L0804267C @ =gUnk_Banim_02000014
	ldr r0, [r0]
	cmp r0, #0
	bne .L08042680
	bl sub_8042704
	b .L0804268C
	.align 2, 0
.L08042678: .4byte gKeySt
.L0804267C: .4byte gUnk_Banim_02000014
.L08042680:
	ldr r0, .L080426A0 @ =gUnk_Banim_02000018
	ldr r0, [r0]
	cmp r0, #1
	bne .L0804268C
	bl sub_8042704
.L0804268C:
	ldr r0, .L080426A4 @ =gUnk_Banim_0201771C
	ldr r0, [r0]
	cmp r0, #1
	beq .L080426A8
	cmp r0, #1
	blo .L080426E4
	cmp r0, #2
	beq .L080426B8
	b .L080426E4
	.align 2, 0
.L080426A0: .4byte gUnk_Banim_02000018
.L080426A4: .4byte gUnk_Banim_0201771C
.L080426A8:
	ldr r0, .L080426B4 @ =0x0203CCF0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080426E4
	b .L080426C2
	.align 2, 0
.L080426B4: .4byte 0x0203CCF0
.L080426B8:
	ldr r0, .L080426D0 @ =0x0203CCF0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080426D8
.L080426C2:
	ldr r0, .L080426D4 @ =gUnk_Banim_0200005C
	ldr r0, [r0]
	bl Proc_End
	bl sub_8047D14
	b .L080426E4
	.align 2, 0
.L080426D0: .4byte 0x0203CCF0
.L080426D4: .4byte gUnk_Banim_0200005C
.L080426D8:
	ldr r0, .L080426F8 @ =gUnk_Banim_0200005C
	ldr r0, [r0]
	bl Proc_End
	bl sub_80438B4
.L080426E4:
	ldr r1, .L080426FC @ =gBmSt
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L08042700 @ =0x04000006
	ldrh r0, [r0]
	strh r0, [r1, #6]
	bl VBlankIntrWait
	pop {r0}
	bx r0
	.align 2, 0
.L080426F8: .4byte gUnk_Banim_0200005C
.L080426FC: .4byte gBmSt
.L08042700: .4byte 0x04000006

	thumb_func_start sub_8042704
sub_8042704: @ 0x08042704
	push {r4, lr}
	bl ClearSprites
	bl sub_805BD9C
	bl GetGameLock
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08042720
	ldr r0, .L08042770 @ =gProcTreeRootArray
	ldr r0, [r0, #8]
	bl Proc_Run
.L08042720:
	ldr r4, .L08042770 @ =gProcTreeRootArray
	ldr r0, [r4, #0xc]
	bl Proc_Run
	ldr r0, [r4, #0x14]
	bl Proc_Run
	movs r0, #0
	bl PutSpriteLayerOam
	ldr r0, [r4, #4]
	bl Proc_Run
	bl BasUpdateAll
	bl sub_804A5DC
	ldr r0, [r4, #0x10]
	bl Proc_Run
	ldr r1, .L08042774 @ =gUnk_Banim_02000018
	movs r0, #0
	str r0, [r1]
	ldr r1, .L08042778 @ =gUnk_Banim_0201E124
	ldr r0, [r1]
	ldr r1, [r1, #4]
	adds r0, r0, r1
	cmp r0, #2
	beq .L08042762
	ldr r1, .L0804277C @ =gUnk_Banim_02000010
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
.L08042762:
	movs r0, #0xd
	bl PutSpriteLayerOam
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08042770: .4byte gProcTreeRootArray
.L08042774: .4byte gUnk_Banim_02000018
.L08042778: .4byte gUnk_Banim_0201E124
.L0804277C: .4byte gUnk_Banim_02000010

	thumb_func_start nullsub_19
nullsub_19: @ 0x08042780
	bx lr
	.align 2, 0

	thumb_func_start sub_8042784
sub_8042784: @ 0x08042784
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080427A4 @ =gUnk_Banim_0201E12C
	movs r0, #0
	str r0, [r1]
	ldr r0, .L080427A8 @ =gUnk_Banim_0201773C
	ldr r0, [r0]
	cmp r0, #0
	bne .L080427B6
	ldr r0, .L080427AC @ =0x0203CD14
	ldrh r0, [r0]
	cmp r0, #1
	bne .L080427B0
	movs r0, #0x20
	rsbs r0, r0, #0
	b .L080427B4
	.align 2, 0
.L080427A4: .4byte gUnk_Banim_0201E12C
.L080427A8: .4byte gUnk_Banim_0201773C
.L080427AC: .4byte 0x0203CD14
.L080427B0:
	movs r0, #0xf0
	rsbs r0, r0, #0
.L080427B4:
	str r0, [r1]
.L080427B6:
	bl sub_804B294
	bl sub_8058F28
	ldr r0, .L080427D0 @ =gUnk_Banim_0200001C
	movs r1, #1
	str r1, [r0]
	bl sub_804C500
	cmp r0, #1
	bne .L080427D4
	movs r0, #0
	b .L080427D6
	.align 2, 0
.L080427D0: .4byte gUnk_Banim_0200001C
.L080427D4:
	movs r0, #0x1e
.L080427D6:
	strh r0, [r4, #0x2c]
	ldr r0, .L080427EC @ =0x0203CCF4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080427F4
	ldr r1, .L080427F0 @ =0x0203CD84
	ldrb r0, [r1]
	ldrb r1, [r1, #1]
	b .L080427FA
	.align 2, 0
.L080427EC: .4byte 0x0203CCF4
.L080427F0: .4byte 0x0203CD84
.L080427F4:
	ldr r1, .L08042814 @ =0x0203CD84
	ldrb r0, [r1, #1]
	ldrb r1, [r1]
.L080427FA:
	bl sub_806B6F8
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [r4, #0x54]
	movs r0, #0
	str r0, [r4, #0x58]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08042814: .4byte 0x0203CD84

	thumb_func_start sub_8042818
sub_8042818: @ 0x08042818
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	bne .L08042860
	bl sub_8042578
	cmp r0, #1
	beq .L08042858
	ldr r0, [r4, #0x54]
	cmp r0, #1
	beq .L0804283E
	ldr r0, [r4, #0x58]
	cmp r0, #1
	bne .L08042858
.L0804283E:
	movs r0, #1
	movs r1, #7
	bl sub_8048DA4
	movs r0, #1
	movs r1, #7
	movs r2, #0
	bl sub_8048E88
	ldr r0, .L08042854 @ =sub_804286C
	b .L0804285A
	.align 2, 0
.L08042854: .4byte sub_804286C
.L08042858:
	ldr r0, .L08042868 @ =sub_8042970
.L0804285A:
	str r0, [r4, #0xc]
	movs r0, #0
	strh r0, [r4, #0x2c]
.L08042860:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08042868: .4byte sub_8042970

	thumb_func_start sub_804286C
sub_804286C: @ 0x0804286C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl sub_8048DF4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L080428F6
	bl sub_8043960
	bl sub_8044264
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080428D0 @ =gBg0Tm
	ldr r2, .L080428D4 @ =0x01000200
	mov r0, sp
	bl CpuFastSet
	ldr r0, .L080428D8 @ =gUnk_Banim_02000030
	ldrh r1, [r0]
	ldrh r2, [r0, #2]
	movs r0, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	bl EnableBgSync
	bl sub_80438D8
	ldr r0, [r4, #0x54]
	cmp r0, #1
	bne .L080428F2
	ldr r0, .L080428DC @ =0x0203CCF4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080428E4
	ldr r1, .L080428E0 @ =0x0203CD84
	ldrb r0, [r1]
	ldrb r1, [r1, #1]
	bl sub_806B754
	b .L080428EE
	.align 2, 0
.L080428D0: .4byte gBg0Tm
.L080428D4: .4byte 0x01000200
.L080428D8: .4byte gUnk_Banim_02000030
.L080428DC: .4byte 0x0203CCF4
.L080428E0: .4byte 0x0203CD84
.L080428E4:
	ldr r1, .L08042900 @ =0x0203CD84
	ldrb r0, [r1, #1]
	ldrb r1, [r1]
	bl sub_806B754
.L080428EE:
	movs r0, #0
	str r0, [r4, #0x54]
.L080428F2:
	ldr r0, .L08042904 @ =sub_8042908
	str r0, [r4, #0xc]
.L080428F6:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08042900: .4byte 0x0203CD84
.L08042904: .4byte sub_8042908

	thumb_func_start sub_8042908
sub_8042908: @ 0x08042908
	push {r4, lr}
	adds r4, r0, #0
	bl IsEventRunning
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08042942
	bl sub_8044608
	movs r0, #1
	bl EnableBgSync
	movs r0, #0
	movs r1, #7
	bl sub_8048DA4
	movs r0, #0
	movs r1, #7
	movs r2, #0
	bl sub_8048E88
	bl sub_8043970
	bl sub_8044274
	bl sub_80438C8
	ldr r0, .L08042948 @ =sub_804294C
	str r0, [r4, #0xc]
.L08042942:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08042948: .4byte sub_804294C

	thumb_func_start sub_804294C
sub_804294C: @ 0x0804294C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_8048DF4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08042964
	ldr r0, .L0804296C @ =sub_8042970
	str r0, [r4, #0xc]
	movs r0, #0
	strh r0, [r4, #0x2c]
.L08042964:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804296C: .4byte sub_8042970

	thumb_func_start sub_8042970
sub_8042970: @ 0x08042970
	ldr r1, .L08042984 @ =0x0203CCF4
	movs r2, #0
	ldrsh r1, [r1, r2]
	str r1, [r0, #0x44]
	movs r1, #0
	str r1, [r0, #0x48]
	ldr r1, .L08042988 @ =sub_804298C
	str r1, [r0, #0xc]
	bx lr
	.align 2, 0
.L08042984: .4byte 0x0203CCF4
.L08042988: .4byte sub_804298C

	thumb_func_start sub_804298C
sub_804298C: @ 0x0804298C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl sub_80588E0
	adds r5, r0, #0
	ldr r0, [r4, #0x48]
	cmp r0, #2
	bne .L080429A8
	ldr r0, .L080429A4 @ =sub_8042A5C
	str r0, [r4, #0xc]
	b .L08042A2C
	.align 2, 0
.L080429A4: .4byte sub_8042A5C
.L080429A8:
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L080429F8
	ldr r0, .L080429F0 @ =gUnk_Banim_02000000
	ldr r1, [r0]
	str r1, [r4, #0x5c]
	movs r6, #1
	adds r0, r5, #0
	ands r0, r6
	cmp r0, #0
	beq .L080429C8
	adds r0, r1, #0
	bl sub_80590B8
	ldr r0, .L080429F4 @ =sub_8042A3C
	str r0, [r4, #0xc]
.L080429C8:
	movs r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L080429DA
	ldr r0, [r4, #0x5c]
	bl sub_80599D0
	ldr r0, .L080429F4 @ =sub_8042A3C
	str r0, [r4, #0xc]
.L080429DA:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L080429EC
	ldr r0, [r4, #0x5c]
	bl sub_8059D8C
	ldr r0, .L080429F4 @ =sub_8042A3C
	str r0, [r4, #0xc]
.L080429EC:
	str r6, [r4, #0x44]
	b .L08042A26
	.align 2, 0
.L080429F0: .4byte gUnk_Banim_02000000
.L080429F4: .4byte sub_8042A3C
.L080429F8:
	ldr r0, .L08042A34 @ =gUnk_Banim_02000000
	ldr r1, [r0, #8]
	str r1, [r4, #0x5c]
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L08042A10
	adds r0, r1, #0
	bl sub_80590B8
	ldr r0, .L08042A38 @ =sub_8042A3C
	str r0, [r4, #0xc]
.L08042A10:
	movs r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L08042A22
	ldr r0, [r4, #0x5c]
	bl sub_80599D0
	ldr r0, .L08042A38 @ =sub_8042A3C
	str r0, [r4, #0xc]
.L08042A22:
	movs r0, #0
	str r0, [r4, #0x44]
.L08042A26:
	ldr r0, [r4, #0x48]
	adds r0, #1
	str r0, [r4, #0x48]
.L08042A2C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08042A34: .4byte gUnk_Banim_02000000
.L08042A38: .4byte sub_8042A3C

	thumb_func_start sub_8042A3C
sub_8042A3C: @ 0x08042A3C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_8058880
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08042A52
	ldr r0, .L08042A58 @ =sub_804298C
	str r0, [r4, #0xc]
.L08042A52:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08042A58: .4byte sub_804298C

	thumb_func_start sub_8042A5C
sub_8042A5C: @ 0x08042A5C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08042A88 @ =0x0203CCF4
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, .L08042A8C @ =gUnk_Banim_0201773C
	ldr r0, [r0]
	cmp r1, r0
	beq .L08042A98
	ldr r1, .L08042A90 @ =gUnk_Banim_02000000
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, .L08042A94 @ =sub_8042AA8
	b .L08042A9A
	.align 2, 0
.L08042A88: .4byte 0x0203CCF4
.L08042A8C: .4byte gUnk_Banim_0201773C
.L08042A90: .4byte gUnk_Banim_02000000
.L08042A94: .4byte sub_8042AA8
.L08042A98:
	ldr r0, .L08042AA4 @ =sub_8042AC4
.L08042A9A:
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08042AA4: .4byte sub_8042AC4

	thumb_func_start sub_8042AA8
sub_8042AA8: @ 0x08042AA8
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	bne .L08042ABC
	ldr r0, .L08042AC0 @ =sub_8042AC4
	str r0, [r1, #0xc]
.L08042ABC:
	bx lr
	.align 2, 0
.L08042AC0: .4byte sub_8042AC4

	thumb_func_start sub_8042AC4
sub_8042AC4: @ 0x08042AC4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L08042B08 @ =gUnk_Banim_02000000
	ldr r0, [r4]
	bl sub_8046DA0
	ldr r0, [r4, #8]
	bl sub_8046DA0
	ldr r1, .L08042B0C @ =0x0203CDCC
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r2, #2
	ldrsh r1, [r1, r2]
	bl sub_80471E4
	ldr r1, .L08042B10 @ =gBattleSt
	movs r0, #0x40
	ldrb r1, [r1, #1]
	ands r0, r1
	cmp r0, #0
	beq .L08042AF6
	ldr r0, [r4]
	bl sub_8046ED8
.L08042AF6:
	ldr r0, [r4]
	bl sub_8046A6C
	ldr r0, .L08042B14 @ =sub_8042B18
	str r0, [r5, #0xc]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08042B08: .4byte gUnk_Banim_02000000
.L08042B0C: .4byte 0x0203CDCC
.L08042B10: .4byte gBattleSt
.L08042B14: .4byte sub_8042B18

	thumb_func_start sub_8042B18
sub_8042B18: @ 0x08042B18
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08042B30 @ =0x0203CD88
	ldr r0, [r0]
	cmp r0, #0
	beq .L08042B3C
	ldr r0, .L08042B34 @ =gUnk_Banim_02000000
	ldr r0, [r0, #8]
	bl sub_805E578
	ldr r0, .L08042B38 @ =sub_8042B4C
	b .L08042B3E
	.align 2, 0
.L08042B30: .4byte 0x0203CD88
.L08042B34: .4byte gUnk_Banim_02000000
.L08042B38: .4byte sub_8042B4C
.L08042B3C:
	ldr r0, .L08042B48 @ =sub_8042B74
.L08042B3E:
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08042B48: .4byte sub_8042B74

	thumb_func_start sub_8042B4C
sub_8042B4C: @ 0x08042B4C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_805E560
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08042B68
	bl nullsub_5
	movs r0, #0x1e
	strh r0, [r4, #0x2c]
	ldr r0, .L08042B70 @ =sub_8042B74
	str r0, [r4, #0xc]
.L08042B68:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08042B70: .4byte sub_8042B74

	thumb_func_start sub_8042B74
sub_8042B74: @ 0x08042B74
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1e
	ble .L08042BE0
	ldr r6, .L08042BE8 @ =0x0203CCF8
	ldrh r0, [r6]
	cmp r0, #1
	bne .L08042BB0
	ldr r3, .L08042BEC @ =gUnk_Banim_02000000
	ldr r4, [r3]
	movs r2, #0x80
	lsls r2, r2, #8
	strh r2, [r4, #0x10]
	movs r0, #0x80
	lsls r0, r0, #7
	adds r1, r0, #0
	ldrh r0, [r4, #0xc]
	orrs r0, r1
	strh r0, [r4, #0xc]
	ldr r4, [r3, #4]
	strh r2, [r4, #0x10]
	ldrh r0, [r4, #0xc]
	orrs r1, r0
	strh r1, [r4, #0xc]
.L08042BB0:
	ldrh r6, [r6, #2]
	cmp r6, #1
	bne .L08042BD6
	ldr r3, .L08042BEC @ =gUnk_Banim_02000000
	ldr r4, [r3, #8]
	movs r2, #0x80
	lsls r2, r2, #8
	strh r2, [r4, #0x10]
	movs r0, #0x80
	lsls r0, r0, #7
	adds r1, r0, #0
	ldrh r0, [r4, #0xc]
	orrs r0, r1
	strh r0, [r4, #0xc]
	ldr r4, [r3, #0xc]
	strh r2, [r4, #0x10]
	ldrh r0, [r4, #0xc]
	orrs r1, r0
	strh r1, [r4, #0xc]
.L08042BD6:
	ldr r0, .L08042BF0 @ =gUnk_Banim_0201E124
	str r7, [r0]
	str r7, [r0, #4]
	ldr r0, .L08042BF4 @ =sub_8042BF8
	str r0, [r5, #0xc]
.L08042BE0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08042BE8: .4byte 0x0203CCF8
.L08042BEC: .4byte gUnk_Banim_02000000
.L08042BF0: .4byte gUnk_Banim_0201E124
.L08042BF4: .4byte sub_8042BF8

	thumb_func_start sub_8042BF8
sub_8042BF8: @ 0x08042BF8
	ldr r2, .L08042C04 @ =gUnk_Banim_0200001C
	movs r1, #0
	str r1, [r2]
	ldr r1, .L08042C08 @ =sub_8042C0C
	str r1, [r0, #0xc]
	bx lr
	.align 2, 0
.L08042C04: .4byte gUnk_Banim_0200001C
.L08042C08: .4byte sub_8042C0C

	thumb_func_start sub_8042C0C
sub_8042C0C: @ 0x08042C0C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08042C24 @ =0x0203CD14
	ldrh r0, [r0]
	cmp r0, #4
	bne .L08042C30
	ldr r0, .L08042C28 @ =gUnk_Banim_02000000
	ldr r0, [r0, #8]
	bl sub_805C86C
	ldr r0, .L08042C2C @ =sub_8042C48
	b .L08042C3A
	.align 2, 0
.L08042C24: .4byte 0x0203CD14
.L08042C28: .4byte gUnk_Banim_02000000
.L08042C2C: .4byte sub_8042C48
.L08042C30:
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	ldr r0, .L08042C44 @ =sub_8042C74
.L08042C3A:
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08042C44: .4byte sub_8042C74

	thumb_func_start sub_8042C48
sub_8042C48: @ 0x08042C48
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_805C840
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	cmp r4, #1
	bne .L08042C64
	bl sub_805C858
	ldr r0, .L08042C6C @ =0x0203CDBC
	strh r4, [r0]
	ldr r0, .L08042C70 @ =sub_80433B0
	str r0, [r5, #0xc]
.L08042C64:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08042C6C: .4byte 0x0203CDBC
.L08042C70: .4byte sub_80433B0

	thumb_func_start sub_8042C74
sub_8042C74: @ 0x08042C74
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r4, #0
	ldr r0, .L08042CA4 @ =gKeySt
	ldr r1, [r0]
	movs r0, #2
	ldrh r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L08042C90
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
.L08042C90:
	ldr r0, .L08042CA8 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #3
	beq .L08042D4C
	cmp r0, #3
	ble .L08042CAC
	cmp r0, #4
	beq .L08042D58
	b .L08042D5A
	.align 2, 0
.L08042CA4: .4byte gKeySt
.L08042CA8: .4byte 0x0203CD14
.L08042CAC:
	cmp r0, #0
	blt .L08042D5A
	ldr r0, .L08042CF4 @ =gUnk_Banim_0201E124
	ldr r1, [r0]
	ldr r0, [r0, #4]
	adds r1, r1, r0
	cmp r1, #2
	bne .L08042D5A
	bl sub_804C500
	cmp r0, #0
	beq .L08042D58
	ldr r5, .L08042CF8 @ =0x0203CDBC
	ldr r0, .L08042CFC @ =0x0203CD7C
	ldr r0, [r0]
	adds r0, #0x6a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5]
	ldr r0, .L08042D00 @ =0x0203CD80
	ldr r0, [r0]
	adds r0, #0x6a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5, #2]
	ldr r1, .L08042D04 @ =0x0203CDA0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne .L08042D08
	movs r0, #1
	bl ArenaSetResult
	b .L08042D58
	.align 2, 0
.L08042CF4: .4byte gUnk_Banim_0201E124
.L08042CF8: .4byte 0x0203CDBC
.L08042CFC: .4byte 0x0203CD7C
.L08042D00: .4byte 0x0203CD80
.L08042D04: .4byte 0x0203CDA0
.L08042D08:
	movs r2, #2
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne .L08042D1A
	movs r0, #2
.L08042D12:
	bl ArenaSetResult
	strh r4, [r5, #2]
	b .L08042D58
.L08042D1A:
	adds r0, r6, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08042D2C
	bl sub_804C56C
	movs r0, #4
	b .L08042D12
.L08042D2C:
	bl ArenaContinueBattle
	bl sub_8049F1C
	bl BasInit
	bl sub_804B048
	bl sub_804B294
	strh r4, [r6, #0x2c]
	ldr r0, .L08042D48 @ =sub_8042B74
	str r0, [r6, #0xc]
	b .L08042D5A
	.align 2, 0
.L08042D48: .4byte sub_8042B74
.L08042D4C:
	ldr r0, .L08042D68 @ =gUnk_Banim_0201E124
	ldr r1, [r0]
	ldr r0, [r0, #4]
	adds r1, r1, r0
	cmp r1, #1
	bne .L08042D5A
.L08042D58:
	movs r4, #1
.L08042D5A:
	cmp r4, #1
	bne .L08042D62
	ldr r0, .L08042D6C @ =sub_8042D70
	str r0, [r6, #0xc]
.L08042D62:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08042D68: .4byte gUnk_Banim_0201E124
.L08042D6C: .4byte sub_8042D70

	thumb_func_start sub_8042D70
sub_8042D70: @ 0x08042D70
	adds r2, r0, #0
	adds r2, #0x29
	movs r1, #0
	strb r1, [r2]
	ldr r1, .L08042D80 @ =sub_8042D84
	str r1, [r0, #0xc]
	bx lr
	.align 2, 0
.L08042D80: .4byte sub_8042D84

	thumb_func_start sub_8042D84
sub_8042D84: @ 0x08042D84
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, .L08042DFC @ =gUnk_Banim_02017720
	ldr r0, [r0]
	cmp r0, #0
	bne .L08042DF4
	ldr r0, .L08042E00 @ =gUnk_Banim_02017730
	ldr r4, [r0]
	cmp r4, #0
	bne .L08042DF4
	bl sub_8048ED8
	lsls r0, r0, #0x18
	asrs r6, r0, #0x18
	cmp r6, #1
	bne .L08042DF4
	strh r4, [r5, #0x2c]
	ldr r0, .L08042E04 @ =sub_8042E14
	str r0, [r5, #0xc]
	bl sub_8058998
	cmp r0, #0
	beq .L08042DC0
	ldr r0, .L08042E08 @ =gUnk_Banim_02000000
	ldr r0, [r0]
	bl sub_8058A08
	ldrh r0, [r0]
	cmp r0, #1
	beq .L08042DF4
.L08042DC0:
	ldr r0, .L08042E0C @ =0x0203CDBC
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #1
	cmp r0, #0
	beq .L08042DCE
	movs r2, #0
.L08042DCE:
	ldr r3, .L08042E10 @ =gUnk_Banim_0201773C
	ldr r0, [r3]
	adds r1, r5, #0
	adds r1, #0x29
	cmp r2, r0
	beq .L08042DDC
	strb r6, [r1]
.L08042DDC:
	ldrb r1, [r1]
	cmp r1, #1
	bne .L08042DF4
	ldr r1, .L08042E08 @ =gUnk_Banim_02000000
	ldr r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L08042DF4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08042DFC: .4byte gUnk_Banim_02017720
.L08042E00: .4byte gUnk_Banim_02017730
.L08042E04: .4byte sub_8042E14
.L08042E08: .4byte gUnk_Banim_02000000
.L08042E0C: .4byte 0x0203CDBC
.L08042E10: .4byte gUnk_Banim_0201773C

	thumb_func_start sub_8042E14
sub_8042E14: @ 0x08042E14
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1d
	ble .L08042E4C
	bl sub_8042578
	cmp r0, #1
	beq .L08042E48
	ldr r0, .L08042E40 @ =0x0203CDBC
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #2
	ldrsh r0, [r0, r2]
	cmn r1, r0
	beq .L08042E48
	ldr r0, .L08042E44 @ =sub_8042E58
	b .L08042E4A
	.align 2, 0
.L08042E40: .4byte 0x0203CDBC
.L08042E44: .4byte sub_8042E58
.L08042E48:
	ldr r0, .L08042E54 @ =sub_804340C
.L08042E4A:
	str r0, [r4, #0xc]
.L08042E4C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08042E54: .4byte sub_804340C

	thumb_func_start sub_8042E58
sub_8042E58: @ 0x08042E58
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	ldr r0, .L08042F54 @ =gUnk_Banim_0201947C
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	mov sl, r0
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r7, .L08042F58 @ =gDispIo
	movs r0, #0x20
	ldrb r2, [r7, #1]
	orrs r0, r2
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r7, #1]
	adds r1, r7, #0
	adds r1, #0x2d
	movs r0, #0
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x31
	movs r2, #0x94
	strb r2, [r0]
	subs r1, #1
	movs r0, #0xf0
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x30
	strb r2, [r0]
	movs r3, #1
	mov r8, r3
	mov r1, r8
	ldr r6, .L08042F5C @ =0x030026E4
	ldrb r6, [r6]
	orrs r1, r6
	movs r0, #2
	mov sb, r0
	mov r2, sb
	orrs r1, r2
	movs r5, #4
	orrs r1, r5
	movs r4, #8
	orrs r1, r4
	movs r3, #0x10
	orrs r1, r3
	movs r6, #0x36
	mov r0, r8
	ldrb r2, [r6, r7]
	orrs r0, r2
	movs r2, #3
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r5
	orrs r0, r4
	orrs r0, r3
	subs r2, #0x1e
	ands r1, r2
	ldr r3, .L08042F5C @ =0x030026E4
	strb r1, [r3]
	ands r0, r2
	strb r0, [r6, r7]
	ldr r0, .L08042F60 @ =gUnk_08113584
	ldr r1, .L08042F64 @ =0x06002000
	movs r2, #0xc0
	lsls r2, r2, #2
	bl RegisterDataMove
	ldr r0, .L08042F68 @ =gUnk_08113CE4
	ldr r1, .L08042F6C @ =gBg1Tm+0x44C
	movs r2, #1
	str r2, [sp]
	adds r2, #0xff
	str r2, [sp, #4]
	movs r2, #0x12
	movs r3, #3
	bl sub_805B1AC
	ldr r0, .L08042F70 @ =gUnk_08113D50
	ldr r1, .L08042F74 @ =gPal+0x20
	movs r2, #8
	bl CpuFastSet
	movs r0, #2
	bl EnableBgSync
	bl EnablePalSync
	bl sub_805894C
	cmp r0, #0
	bne .L08042F78
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r6, [r7, #0x10]
	ands r0, r6
	strb r0, [r7, #0x10]
	adds r0, r1, #0
	ldrb r2, [r7, #0xc]
	ands r0, r2
	mov r3, r8
	orrs r0, r3
	strb r0, [r7, #0xc]
	ldrb r6, [r7, #0x14]
	ands r1, r6
	mov r0, sb
	orrs r1, r0
	strb r1, [r7, #0x14]
	movs r0, #3
	ldrb r1, [r7, #0x18]
	orrs r0, r1
	strb r0, [r7, #0x18]
	b .L08042FA2
	.align 2, 0
.L08042F54: .4byte gUnk_Banim_0201947C
.L08042F58: .4byte gDispIo
.L08042F5C: .4byte 0x030026E4
.L08042F60: .4byte gUnk_08113584
.L08042F64: .4byte 0x06002000
.L08042F68: .4byte gUnk_08113CE4
.L08042F6C: .4byte gBg1Tm+0x44C
.L08042F70: .4byte gUnk_08113D50
.L08042F74: .4byte gPal+0x20
.L08042F78:
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r7, #0x10]
	ands r0, r2
	strb r0, [r7, #0x10]
	adds r0, r1, #0
	ldrb r3, [r7, #0xc]
	ands r0, r3
	mov r6, r8
	orrs r0, r6
	strb r0, [r7, #0xc]
	ldrb r0, [r7, #0x18]
	ands r1, r0
	mov r2, sb
	orrs r1, r2
	strb r1, [r7, #0x18]
	movs r0, #3
	ldrb r3, [r7, #0x14]
	orrs r0, r3
	strb r0, [r7, #0x14]
.L08042FA2:
	movs r0, #1
	bl sub_8043908
	ldr r0, .L08042FBC @ =0x0203CDBC
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #0
	beq .L08042FC4
	ldr r0, .L08042FC0 @ =0x0203CDB8
	movs r1, #0
	ldrsh r0, [r0, r1]
	b .L08042FCA
	.align 2, 0
.L08042FBC: .4byte 0x0203CDBC
.L08042FC0: .4byte 0x0203CDB8
.L08042FC4:
	ldr r0, .L08043060 @ =0x0203CDB8
	movs r2, #2
	ldrsh r0, [r0, r2]
.L08042FCA:
	movs r1, #0x64
	bl DivRem
	adds r6, r0, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #1
	subs r4, r6, r0
	cmp r5, #0
	bne .L08042FE8
	movs r5, #0xa
.L08042FE8:
	ldr r0, .L08043064 @ =gUnk_Banim_0201947C
	adds r1, r6, #0
	bl sub_805B458
	lsls r5, r5, #5
	mov r8, r5
	lsls r4, r4, #5
	mov sb, r4
	mov r5, sl
	ldr r4, .L08043064 @ =gUnk_Banim_0201947C
	ldr r7, .L08043068 @ =gUnk_08113884
	movs r6, #0xc
.L08043000:
	ldrh r3, [r4]
	lsls r0, r3, #5
	adds r0, r0, r7
	adds r1, r5, #0
	movs r2, #8
	bl CpuFastSet
	adds r5, #0x20
	adds r4, #2
	subs r6, #1
	cmp r6, #0
	bge .L08043000
	ldr r4, .L0804306C @ =gUnk_08113B84
	mov r6, r8
	adds r0, r6, r4
	movs r1, #0xd0
	lsls r1, r1, #1
	add r1, sl
	movs r2, #8
	bl CpuFastSet
	add r4, sb
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, sl
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r1, .L08043070 @ =0x060020E0
	movs r2, #0xf0
	lsls r2, r2, #1
	mov r0, sl
	bl RegisterDataMove
	movs r0, #0
	ldr r1, [sp, #8]
	strh r0, [r1, #0x2c]
	ldr r0, .L08043074 @ =sub_8043078
	str r0, [r1, #0xc]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08043060: .4byte 0x0203CDB8
.L08043064: .4byte gUnk_Banim_0201947C
.L08043068: .4byte gUnk_08113884
.L0804306C: .4byte gUnk_08113B84
.L08043070: .4byte 0x060020E0
.L08043074: .4byte sub_8043078

	thumb_func_start sub_8043078
sub_8043078: @ 0x08043078
	adds r2, r0, #0
	ldrh r1, [r2, #0x2c]
	adds r1, #1
	strh r1, [r2, #0x2c]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	ble .L08043098
	movs r0, #0
	strh r0, [r2, #0x2c]
	ldr r0, .L08043094 @ =sub_80430C4
	str r0, [r2, #0xc]
	b .L080430BE
	.align 2, 0
.L08043094: .4byte sub_80430C4
.L08043098:
	ldr r3, .L080430C0 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x2d
	movs r0, #0
	strb r0, [r2]
	movs r2, #0x6c
	rsbs r2, r2, #0
	adds r0, r2, #0
	subs r0, r0, r1
	adds r2, r3, #0
	adds r2, #0x31
	strb r0, [r2]
	subs r2, #5
	movs r0, #0xf0
	strb r0, [r2]
	subs r1, #0x6c
	adds r0, r3, #0
	adds r0, #0x30
	strb r1, [r0]
.L080430BE:
	bx lr
	.align 2, 0
.L080430C0: .4byte gDispIo

	thumb_func_start sub_80430C4
sub_80430C4: @ 0x080430C4
	push {r4, lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	ble .L0804311C
	ldr r2, .L080430E8 @ =0x0203CDBC
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	beq .L080430F0
	ldr r0, .L080430EC @ =0x0203CDB8
	ldrh r0, [r0]
	b .L080430FE
	.align 2, 0
.L080430E8: .4byte 0x0203CDBC
.L080430EC: .4byte 0x0203CDB8
.L080430F0:
	ldrh r3, [r2, #2]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmp r0, #0
	beq .L08043104
	ldr r0, .L08043124 @ =0x0203CDB8
	ldrh r0, [r0, #2]
.L080430FE:
	strh r0, [r1, #0x2c]
	adds r0, r0, r3
	strh r0, [r1, #0x2e]
.L08043104:
	ldr r0, .L08043128 @ =sub_804312C
	str r0, [r1, #0xc]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x74
	bl sub_805BCA8
	movs r0, #0x74
	movs r1, #0x78
	movs r2, #0
	bl sub_805BDC0
.L0804311C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08043124: .4byte 0x0203CDB8
.L08043128: .4byte sub_804312C

	thumb_func_start sub_804312C
sub_804312C: @ 0x0804312C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, .L080431F4 @ =gUnk_Banim_0201947C
	mov r8, r0
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, r8
	mov sl, r1
	movs r2, #0x2c
	ldrsh r0, [r7, r2]
	movs r1, #0x64
	bl DivRem
	adds r5, r0, #0
	movs r1, #0xa
	bl Div
	adds r4, r0, #0
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #1
	subs r6, r5, r0
	cmp r4, #0
	bne .L08043168
	movs r4, #0xa
.L08043168:
	mov r0, r8
	adds r1, r5, #0
	bl sub_805B458
	lsls r4, r4, #5
	mov sb, r4
	lsls r6, r6, #5
	str r6, [sp]
	mov r6, sl
	mov r5, r8
	ldr r0, .L080431F8 @ =gUnk_08113884
	mov r8, r0
	movs r4, #0xc
.L08043182:
	ldrh r1, [r5]
	lsls r0, r1, #5
	add r0, r8
	adds r1, r6, #0
	movs r2, #8
	bl CpuFastSet
	adds r6, #0x20
	adds r5, #2
	subs r4, #1
	cmp r4, #0
	bge .L08043182
	ldr r4, .L080431FC @ =gUnk_08113B84
	mov r2, sb
	adds r0, r2, r4
	movs r1, #0xd0
	lsls r1, r1, #1
	add r1, sl
	movs r2, #8
	bl CpuFastSet
	ldr r0, [sp]
	adds r4, r0, r4
	movs r1, #0xe0
	lsls r1, r1, #1
	add r1, sl
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r1, .L08043200 @ =0x060020E0
	movs r2, #0xf0
	lsls r2, r2, #1
	mov r0, sl
	bl RegisterDataMove
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r7, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L080431E2
	movs r0, #0
	strh r0, [r7, #0x2c]
	ldr r0, .L08043204 @ =sub_8043208
	str r0, [r7, #0xc]
.L080431E2:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080431F4: .4byte gUnk_Banim_0201947C
.L080431F8: .4byte gUnk_08113884
.L080431FC: .4byte gUnk_08113B84
.L08043200: .4byte 0x060020E0
.L08043204: .4byte sub_8043208

	thumb_func_start sub_8043208
sub_8043208: @ 0x08043208
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L0804321A
	movs r0, #0x74
	bl sub_805BD54
.L0804321A:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1e
	ble .L08043230
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, .L08043238 @ =sub_804323C
	str r0, [r4, #0xc]
.L08043230:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08043238: .4byte sub_804323C

	thumb_func_start sub_804323C
sub_804323C: @ 0x0804323C
	adds r1, r0, #0
	ldrh r2, [r1, #0x2c]
	adds r2, #1
	strh r2, [r1, #0x2c]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	ble .L0804325C
	movs r0, #0
	strh r0, [r1, #0x2c]
	ldr r0, .L08043258 @ =sub_8043288
	str r0, [r1, #0xc]
	b .L08043282
	.align 2, 0
.L08043258: .4byte sub_8043288
.L0804325C:
	ldr r3, .L08043284 @ =gDispIo
	adds r1, r3, #0
	adds r1, #0x2d
	movs r0, #0
	strb r0, [r1]
	adds r0, r2, #0
	subs r0, #0x78
	adds r1, #4
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xf0
	strb r0, [r1]
	movs r1, #0x60
	rsbs r1, r1, #0
	adds r0, r1, #0
	subs r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x30
	strb r0, [r1]
.L08043282:
	bx lr
	.align 2, 0
.L08043284: .4byte gDispIo

	thumb_func_start sub_8043288
sub_8043288: @ 0x08043288
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x18
	bne .L080432CC
	ldr r2, .L080432B0 @ =0x0203CDBC
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq .L080432B8
	ldr r0, .L080432B4 @ =0x0203CDB8
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0
	ldrsh r0, [r2, r3]
	b .L080432C2
	.align 2, 0
.L080432B0: .4byte 0x0203CDBC
.L080432B4: .4byte 0x0203CDB8
.L080432B8:
	ldr r0, .L08043314 @ =0x0203CDB8
	movs r3, #2
	ldrsh r1, [r0, r3]
	movs r3, #2
	ldrsh r0, [r2, r3]
.L080432C2:
	adds r1, r1, r0
	cmp r1, #0x63
	ble .L080432CC
	bl sub_8043590
.L080432CC:
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #0x28
	ble .L080433A4
	bl sub_80474D8
	movs r0, #0
	bl sub_8043908
	bl sub_805894C
	cmp r0, #0
	bne .L0804331C
	ldr r3, .L08043318 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r2, [r3, #0x10]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x10]
	ldrb r0, [r3, #0x14]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x14]
	movs r0, #3
	ldrb r1, [r3, #0x18]
	orrs r0, r1
	strb r0, [r3, #0x18]
	b .L08043348
	.align 2, 0
.L08043314: .4byte 0x0203CDB8
.L08043318: .4byte gDispIo
.L0804331C:
	ldr r3, .L08043378 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r2, [r3, #0x10]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x10]
	ldrb r0, [r3, #0x18]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x18]
	movs r0, #3
	ldrb r1, [r3, #0x14]
	orrs r0, r1
	strb r0, [r3, #0x14]
.L08043348:
	adds r2, r3, #0
	adds r1, r2, #0
	adds r1, #0x2d
	movs r0, #0
	strb r0, [r1]
	adds r1, #4
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xa0
	strb r0, [r1]
	ldr r2, .L0804337C @ =0x0203CDBC
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	beq .L08043384
	ldr r0, .L08043380 @ =0x0203CDB8
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0
	ldrsh r0, [r2, r3]
	b .L0804338E
	.align 2, 0
.L08043378: .4byte gDispIo
.L0804337C: .4byte 0x0203CDBC
.L08043380: .4byte 0x0203CDB8
.L08043384:
	ldr r0, .L08043398 @ =0x0203CDB8
	movs r3, #2
	ldrsh r1, [r0, r3]
	movs r3, #2
	ldrsh r0, [r2, r3]
.L0804338E:
	adds r1, r1, r0
	cmp r1, #0x63
	ble .L080433A0
	ldr r0, .L0804339C @ =sub_80433B0
	b .L080433A2
	.align 2, 0
.L08043398: .4byte 0x0203CDB8
.L0804339C: .4byte sub_80433B0
.L080433A0:
	ldr r0, .L080433AC @ =sub_804340C
.L080433A2:
	str r0, [r4, #0xc]
.L080433A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080433AC: .4byte sub_804340C

	thumb_func_start sub_80433B0
sub_80433B0: @ 0x080433B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080433C4 @ =0x0203CDBC
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L080433CC
	ldr r0, .L080433C8 @ =gUnk_Banim_02000000
	ldr r0, [r0]
	b .L080433D0
	.align 2, 0
.L080433C4: .4byte 0x0203CDBC
.L080433C8: .4byte gUnk_Banim_02000000
.L080433CC:
	ldr r0, .L080433E0 @ =gUnk_Banim_02000000
	ldr r0, [r0, #8]
.L080433D0:
	bl sub_805D5B0
	ldr r0, .L080433E4 @ =sub_80433E8
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080433E0: .4byte gUnk_Banim_02000000
.L080433E4: .4byte sub_80433E8

	thumb_func_start sub_80433E8
sub_80433E8: @ 0x080433E8
	push {r4, lr}
	adds r4, r0, #0
	bl sub_805D128
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08043400
	bl sub_805D140
	ldr r0, .L08043408 @ =sub_804340C
	str r0, [r4, #0xc]
.L08043400:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08043408: .4byte sub_804340C

	thumb_func_start sub_804340C
sub_804340C: @ 0x0804340C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_805F498
	ldr r0, .L08043420 @ =sub_8043424
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08043420: .4byte sub_8043424

	thumb_func_start sub_8043424
sub_8043424: @ 0x08043424
	push {r4, lr}
	adds r4, r0, #0
	bl sub_805F148
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0804343C
	bl sub_805F15C
	ldr r0, .L08043444 @ =sub_8043448
	str r0, [r4, #0xc]
.L0804343C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08043444: .4byte sub_8043448

	thumb_func_start sub_8043448
sub_8043448: @ 0x08043448
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L08043478 @ =gUnk_Banim_02000000
	ldr r0, [r4]
	bl sub_8046E9C
	ldr r0, [r4, #8]
	bl sub_8046E9C
	bl sub_804722C
	bl sub_8046B48
	ldr r0, .L0804347C @ =0x0203CCF4
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [r5, #0x44]
	movs r0, #0
	str r0, [r5, #0x48]
	ldr r0, .L08043480 @ =sub_8043484
	str r0, [r5, #0xc]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08043478: .4byte gUnk_Banim_02000000
.L0804347C: .4byte 0x0203CCF4
.L08043480: .4byte sub_8043484

	thumb_func_start sub_8043484
sub_8043484: @ 0x08043484
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl sub_80588E0
	adds r5, r0, #0
	ldr r0, [r4, #0x48]
	cmp r0, #2
	bne .L080434A0
	ldr r0, .L0804349C @ =sub_8043554
	str r0, [r4, #0xc]
	b .L08043524
	.align 2, 0
.L0804349C: .4byte sub_8043554
.L080434A0:
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L080434F0
	ldr r0, .L080434E8 @ =gUnk_Banim_02000000
	ldr r1, [r0]
	str r1, [r4, #0x5c]
	movs r6, #1
	adds r0, r5, #0
	ands r0, r6
	cmp r0, #0
	beq .L080434C0
	adds r0, r1, #0
	bl sub_80588A4
	ldr r0, .L080434EC @ =sub_8043534
	str r0, [r4, #0xc]
.L080434C0:
	movs r0, #4
	ands r0, r5
	cmp r0, #0
	beq .L080434D2
	ldr r0, [r4, #0x5c]
	bl sub_80588A4
	ldr r0, .L080434EC @ =sub_8043534
	str r0, [r4, #0xc]
.L080434D2:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L080434E4
	ldr r0, [r4, #0x5c]
	bl sub_80588A4
	ldr r0, .L080434EC @ =sub_8043534
	str r0, [r4, #0xc]
.L080434E4:
	str r6, [r4, #0x44]
	b .L0804351E
	.align 2, 0
.L080434E8: .4byte gUnk_Banim_02000000
.L080434EC: .4byte sub_8043534
.L080434F0:
	ldr r0, .L0804352C @ =gUnk_Banim_02000000
	ldr r1, [r0, #8]
	str r1, [r4, #0x5c]
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L08043508
	adds r0, r1, #0
	bl sub_80588A4
	ldr r0, .L08043530 @ =sub_8043534
	str r0, [r4, #0xc]
.L08043508:
	movs r0, #8
	ands r0, r5
	cmp r0, #0
	beq .L0804351A
	ldr r0, [r4, #0x5c]
	bl sub_80588A4
	ldr r0, .L08043530 @ =sub_8043534
	str r0, [r4, #0xc]
.L0804351A:
	movs r0, #0
	str r0, [r4, #0x44]
.L0804351E:
	ldr r0, [r4, #0x48]
	adds r0, #1
	str r0, [r4, #0x48]
.L08043524:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804352C: .4byte gUnk_Banim_02000000
.L08043530: .4byte sub_8043534

	thumb_func_start sub_8043534
sub_8043534: @ 0x08043534
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_80588BC
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0804354A
	ldr r0, .L08043550 @ =sub_8043484
	str r0, [r4, #0xc]
.L0804354A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08043550: .4byte sub_8043484

	thumb_func_start sub_8043554
sub_8043554: @ 0x08043554
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08043580 @ =gUnk_Banim_0201771C
	movs r0, #1
	str r0, [r1]
	ldr r0, .L08043584 @ =0x0203CCF0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08043576
	movs r0, #2
	movs r1, #7
	movs r2, #0
	bl sub_8048E88
	bl sub_805C738
.L08043576:
	ldr r0, .L08043588 @ =nullsub_20
	str r0, [r4, #0xc]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08043580: .4byte gUnk_Banim_0201771C
.L08043584: .4byte 0x0203CCF0
.L08043588: .4byte nullsub_20

	thumb_func_start nullsub_20
nullsub_20: @ 0x0804358C
	bx lr
	.align 2, 0

	thumb_func_start sub_8043590
sub_8043590: @ 0x08043590
	push {lr}
	ldr r0, .L080435A8 @ =gUnk_085CB550
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	movs r0, #0x80
	bl SetBgmVolume
	pop {r0}
	bx r0
	.align 2, 0
.L080435A8: .4byte gUnk_085CB550

	thumb_func_start sub_80435AC
sub_80435AC: @ 0x080435AC
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	bne .L080435D4
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x5b
	bl sub_805BCA8
	movs r0, #0x5b
	movs r1, #0x78
	movs r2, #0
	bl sub_805BDC0
	b .L080435E6
.L080435D4:
	cmp r0, #0x74
	bne .L080435E6
	movs r0, #0x80
	lsls r0, r0, #1
	bl SetBgmVolume
	adds r0, r4, #0
	bl Proc_Break
.L080435E6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_80435EC
sub_80435EC: @ 0x080435EC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r7, r1, #0
	movs r6, #0
	adds r5, r7, #0
.L080435F8:
	movs r0, #0xf
	ldrh r1, [r4]
	cmp r1, #0xff
	beq .L08043602
	ldrh r0, [r4]
.L08043602:
	lsls r0, r0, #5
	ldr r1, .L08043634 @ =gUnk_08113224
	adds r0, r0, r1
	adds r1, r5, #0
	movs r2, #8
	bl CpuFastSet
	adds r4, #2
	adds r5, #0x20
	adds r6, #1
	cmp r6, #0xa
	bls .L080435F8
	movs r0, #0
	str r0, [sp]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r2, .L08043638 @ =0x01000008
	mov r0, sp
	bl CpuFastSet
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08043634: .4byte gUnk_08113224
.L08043638: .4byte 0x01000008

	thumb_func_start sub_804363C
sub_804363C: @ 0x0804363C
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	cmp r6, r0
	bne .L08043658
	movs r0, #0xb
	strh r0, [r5]
	movs r0, #0xa
	strh r0, [r5, #2]
	strh r0, [r5, #4]
	b .L0804369E
.L08043658:
	adds r0, r6, #0
	movs r1, #0x64
	bl Div
	strh r0, [r5]
	movs r0, #0x64
	ldrh r1, [r5]
	adds r4, r1, #0
	muls r4, r0, r4
	subs r4, r6, r4
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	strh r0, [r5, #2]
	lsls r0, r0, #2
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	lsls r0, r0, #1
	subs r4, r4, r0
	strh r4, [r5, #4]
	adds r1, r2, #0
	ldrh r2, [r5]
	adds r0, r1, r2
	cmp r0, #0
	bne .L08043694
	movs r0, #0xb
	strh r0, [r5, #2]
.L08043694:
	ldrh r0, [r5]
	cmp r0, #0
	bne .L0804369E
	movs r0, #0xb
	strh r0, [r5]
.L0804369E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_80436A4
sub_80436A4: @ 0x080436A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r4, .L08043850 @ =gUnk_Banim_02000060
	ldr r0, .L08043854 @ =gUnk_085CB568
	movs r1, #1
	bl SpawnProc
	str r0, [r4]
	movs r0, #0
	bl sub_8043908
	bl sub_80438C8
	bl sub_8043970
	bl sub_8043950
	ldr r1, .L08043858 @ =gUnk_Banim_02000030
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r2, #2
	ldrsh r1, [r1, r2]
	bl sub_8043918
	ldr r6, .L0804385C @ =0x0203CD08
	movs r1, #0
	ldrsh r0, [r6, r1]
	lsls r0, r0, #5
	ldr r4, .L08043860 @ =gUnk_08113424
	adds r0, r0, r4
	ldr r5, .L08043864 @ =gPal+0x360
	adds r1, r5, #0
	movs r2, #0x10
	bl CpuSet
	movs r2, #2
	ldrsh r0, [r6, r2]
	lsls r0, r0, #5
	adds r0, r0, r4
	adds r1, r5, #0
	adds r1, #0x20
	movs r2, #0x10
	bl CpuSet
	ldr r1, .L08043868 @ =0x0203CDA8
	ldr r2, .L0804386C @ =0x0000FFFF
	adds r0, r2, #0
	ldrh r2, [r1]
	orrs r2, r0
	strh r2, [r1]
	ldrh r2, [r1, #2]
	orrs r0, r2
	strh r0, [r1, #2]
	ldr r0, .L08043870 @ =gUnk_08112D54
	ldr r1, .L08043874 @ =0x06013800
	bl LZ77UnCompVram
	ldr r0, .L08043878 @ =gUnk_08112DF4
	ldr r1, .L0804387C @ =0x06013C00
	bl LZ77UnCompVram
	movs r1, #0
	ldrsh r0, [r6, r1]
	lsls r0, r0, #5
	ldr r4, .L08043880 @ =gUnk_081131A4
	adds r0, r0, r4
	adds r1, r5, #0
	subs r1, #0xc0
	movs r2, #8
	bl CpuFastSet
	movs r2, #2
	ldrsh r0, [r6, r2]
	lsls r0, r0, #5
	adds r0, r0, r4
	subs r5, #0xa0
	adds r1, r5, #0
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	ldr r6, .L08043884 @ =0x0203CDAC
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r7, .L08043888 @ =gUnk_Banim_020176F8
	adds r1, r7, #0
	bl sub_804363C
	ldr r5, .L0804388C @ =0x0203CDB0
	movs r2, #0
	ldrsh r0, [r5, r2]
	adds r1, r7, #6
	bl sub_804363C
	ldr r4, .L08043890 @ =0x0203CDB4
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r7, #0
	adds r1, #0xc
	bl sub_804363C
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r7, #0
	adds r1, #0x12
	bl sub_804363C
	movs r1, #2
	ldrsh r0, [r5, r1]
	adds r1, r7, #0
	adds r1, #0x18
	bl sub_804363C
	movs r2, #2
	ldrsh r0, [r4, r2]
	adds r1, r7, #0
	adds r1, #0x1e
	bl sub_804363C
	movs r0, #0
	str r0, [sp]
	ldr r1, .L08043894 @ =gUnk_Banim_020169C0
	ldr r2, .L08043898 @ =0x01000100
	mov r0, sp
	bl CpuFastSet
	movs r6, #0
	mov sb, r7
.L080437AC:
	movs r5, #0
	lsls r3, r6, #1
	adds r0, r6, #1
	mov r8, r0
	lsls r4, r6, #7
.L080437B6:
	adds r0, r3, r6
	adds r0, r0, r5
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, .L0804389C @ =gUnk_08113024
	adds r0, r0, r1
	ldr r7, .L08043894 @ =gUnk_Banim_020169C0
	adds r1, r4, r7
	movs r2, #0x10
	str r3, [sp, #4]
	bl CpuSet
	adds r4, #0x20
	adds r5, #1
	ldr r3, [sp, #4]
	cmp r5, #2
	bls .L080437B6
	mov r6, r8
	cmp r6, #5
	bls .L080437AC
	ldr r1, .L080438A0 @ =0x06013A00
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r7, #0
	adds r2, r4, #0
	bl RegisterDataMove
	adds r0, r7, r4
	ldr r1, .L080438A4 @ =0x06013E00
	adds r2, r4, #0
	bl RegisterDataMove
	bl InitIcons
	movs r0, #0
	movs r1, #0x1d
	bl ApplyIconPalette
	movs r0, #0
	movs r1, #0x1e
	bl ApplyIconPalette
	ldr r0, .L080438A8 @ =0x0203CD7C
	ldr r0, [r0]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIcon
	movs r1, #0xee
	lsls r1, r1, #1
	bl PutIconObjImg
	ldr r0, .L080438AC @ =0x0203CD80
	ldr r0, [r0]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIcon
	movs r1, #0xef
	lsls r1, r1, #1
	bl PutIconObjImg
	ldr r0, .L080438B0 @ =Pal_SystemObjects
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08043850: .4byte gUnk_Banim_02000060
.L08043854: .4byte gUnk_085CB568
.L08043858: .4byte gUnk_Banim_02000030
.L0804385C: .4byte 0x0203CD08
.L08043860: .4byte gUnk_08113424
.L08043864: .4byte gPal+0x360
.L08043868: .4byte 0x0203CDA8
.L0804386C: .4byte 0x0000FFFF
.L08043870: .4byte gUnk_08112D54
.L08043874: .4byte 0x06013800
.L08043878: .4byte gUnk_08112DF4
.L0804387C: .4byte 0x06013C00
.L08043880: .4byte gUnk_081131A4
.L08043884: .4byte 0x0203CDAC
.L08043888: .4byte gUnk_Banim_020176F8
.L0804388C: .4byte 0x0203CDB0
.L08043890: .4byte 0x0203CDB4
.L08043894: .4byte gUnk_Banim_020169C0
.L08043898: .4byte 0x01000100
.L0804389C: .4byte gUnk_08113024
.L080438A0: .4byte 0x06013A00
.L080438A4: .4byte 0x06013E00
.L080438A8: .4byte 0x0203CD7C
.L080438AC: .4byte 0x0203CD80
.L080438B0: .4byte Pal_SystemObjects

	thumb_func_start sub_80438B4
sub_80438B4: @ 0x080438B4
	push {lr}
	ldr r0, .L080438C4 @ =gUnk_Banim_02000060
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L080438C4: .4byte gUnk_Banim_02000060

	thumb_func_start sub_80438C8
sub_80438C8: @ 0x080438C8
	ldr r0, .L080438D4 @ =gUnk_Banim_02000060
	ldr r1, [r0]
	movs r0, #0
	str r0, [r1, #0x4c]
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L080438D4: .4byte gUnk_Banim_02000060

	thumb_func_start sub_80438D8
sub_80438D8: @ 0x080438D8
	ldr r0, .L080438E4 @ =gUnk_Banim_02000060
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x4c]
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L080438E4: .4byte gUnk_Banim_02000060

	thumb_func_start sub_80438E8
sub_80438E8: @ 0x080438E8
	ldr r0, .L080438F4 @ =gUnk_Banim_02000060
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x4c]
	bx lr
	.align 2, 0
.L080438F4: .4byte gUnk_Banim_02000060

	thumb_func_start sub_80438F8
sub_80438F8: @ 0x080438F8
	ldr r0, .L08043904 @ =gUnk_Banim_02000060
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L08043904: .4byte gUnk_Banim_02000060

	thumb_func_start sub_8043908
sub_8043908: @ 0x08043908
	lsls r0, r0, #0x10
	ldr r1, .L08043914 @ =gUnk_Banim_02000060
	ldr r1, [r1]
	lsrs r0, r0, #6
	str r0, [r1, #0x44]
	bx lr
	.align 2, 0
.L08043914: .4byte gUnk_Banim_02000060

	thumb_func_start sub_8043918
sub_8043918: @ 0x08043918
	ldr r2, .L08043928 @ =gUnk_Banim_02000060
	ldr r2, [r2]
	movs r3, #0
	strh r0, [r2, #0x32]
	strh r1, [r2, #0x3a]
	adds r2, #0x29
	strb r3, [r2]
	bx lr
	.align 2, 0
.L08043928: .4byte gUnk_Banim_02000060

	thumb_func_start sub_804392C
sub_804392C: @ 0x0804392C
	ldr r2, .L0804393C @ =gUnk_Banim_02000060
	ldr r2, [r2]
	strh r0, [r2, #0x32]
	strh r1, [r2, #0x3a]
	adds r2, #0x29
	movs r0, #1
	strb r0, [r2]
	bx lr
	.align 2, 0
.L0804393C: .4byte gUnk_Banim_02000060

	thumb_func_start sub_8043940
sub_8043940: @ 0x08043940
	ldr r0, .L0804394C @ =gUnk_Banim_02000060
	ldr r0, [r0]
	adds r0, #0x29
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
.L0804394C: .4byte gUnk_Banim_02000060

	thumb_func_start sub_8043950
sub_8043950: @ 0x08043950
	ldr r0, .L0804395C @ =gUnk_Banim_02000060
	ldr r0, [r0]
	adds r0, #0x29
	movs r1, #0
	strb r1, [r0]
	bx lr
	.align 2, 0
.L0804395C: .4byte gUnk_Banim_02000060

	thumb_func_start sub_8043960
sub_8043960: @ 0x08043960
	ldr r0, .L0804396C @ =gUnk_Banim_02000060
	ldr r0, [r0]
	adds r0, #0x2a
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
.L0804396C: .4byte gUnk_Banim_02000060

	thumb_func_start sub_8043970
sub_8043970: @ 0x08043970
	ldr r0, .L0804397C @ =gUnk_Banim_02000060
	ldr r0, [r0]
	adds r0, #0x2a
	movs r1, #0
	strb r1, [r0]
	bx lr
	.align 2, 0
.L0804397C: .4byte gUnk_Banim_02000060

	thumb_func_start sub_8043980
sub_8043980: @ 0x08043980
	adds r3, r0, #0
	cmp r1, #0
	ble .L080439A8
	cmp r2, #1
	beq .L08043998
	cmp r2, #1
	bhs .L080439A0
	ldr r0, .L08043994 @ =gUnk_085CB688
	b .L080439C2
	.align 2, 0
.L08043994: .4byte gUnk_085CB688
.L08043998:
	ldr r0, .L0804399C @ =gUnk_085CB6A0
	b .L080439C2
	.align 2, 0
.L0804399C: .4byte gUnk_085CB6A0
.L080439A0:
	ldr r0, .L080439A4 @ =gUnk_085CB6B8
	b .L080439C2
	.align 2, 0
.L080439A4: .4byte gUnk_085CB6B8
.L080439A8:
	cmp r2, #1
	beq .L080439B8
	cmp r2, #1
	bhs .L080439C0
	ldr r0, .L080439B4 @ =gUnk_085CB6D0
	b .L080439C2
	.align 2, 0
.L080439B4: .4byte gUnk_085CB6D0
.L080439B8:
	ldr r0, .L080439BC @ =gUnk_085CB6E8
	b .L080439C2
	.align 2, 0
.L080439BC: .4byte gUnk_085CB6E8
.L080439C0:
	ldr r0, .L080439C8 @ =gUnk_085CB700
.L080439C2:
	str r0, [r3, #0x3c]
	bx lr
	.align 2, 0
.L080439C8: .4byte gUnk_085CB700

	thumb_func_start sub_80439CC
sub_80439CC: @ 0x080439CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x118
	mov sl, r0
	movs r0, #0
	str r0, [sp, #0xd8]
	bl GetGameTime
	lsrs r0, r0, #3
	movs r1, #3
	bl DivRem
	str r0, [sp, #0xe8]
	mov r0, sl
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #1
	bne .L080439F8
	b .L08044152
.L080439F8:
	mov r0, sl
	adds r0, #0x29
	ldrb r1, [r0]
	str r0, [sp, #0x104]
	cmp r1, #0
	bne .L08043AE6
	mov r1, sl
	ldrh r1, [r1, #0x3a]
	lsls r0, r1, #0x10
	asrs r4, r0, #0x13
	lsls r0, r4, #5
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r7, r0, r2
	cmp r7, #0
	bge .L08043A1A
	movs r7, #0
.L08043A1A:
	adds r6, r4, #7
	cmp r6, #7
	ble .L08043A22
	movs r6, #7
.L08043A22:
	movs r0, #7
	subs r0, r0, r6
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	mov sb, r1
	ldr r0, .L08043A44 @ =0x0203CD14
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt .L08043A48
	cmp r0, #2
	bgt .L08043A48
	movs r4, #0
	movs r0, #0xf
	str r0, [sp, #0xdc]
	b .L08043A4E
	.align 2, 0
.L08043A44: .4byte 0x0203CD14
.L08043A48:
	movs r1, #8
	str r1, [sp, #0xdc]
	movs r4, #8
.L08043A4E:
	ldr r2, .L08043B34 @ =gBg0Tm+0x340
	mov r8, r2
	movs r0, #0x9f
	str r0, [sp]
	mov r0, r8
	movs r1, #0x1e
	movs r2, #8
	movs r3, #0
	bl sub_805B094
	mov r3, sl
	ldr r0, [r3, #0x4c]
	cmp r0, #0
	bne .L08043AA0
	ldr r0, .L08043B38 @ =gUnk_08112AD0
	add r0, sb
	lsls r5, r7, #1
	lsls r1, r4, #1
	ldr r2, .L08043B3C @ =0xFFFFFCC0
	add r2, r8
	adds r1, r1, r2
	adds r5, r5, r1
	lsls r4, r6, #0x10
	lsrs r4, r4, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r2, #0xf
	adds r3, r4, #0
	bl sub_805B1AC
	movs r0, #0x80
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0xf
	adds r2, r4, #0
	movs r3, #2
	bl sub_805B01C
.L08043AA0:
	mov r4, sl
	ldr r0, [r4, #0x50]
	cmp r0, #0
	bne .L08043AE0
	ldr r0, .L08043B40 @ =gUnk_08112BA4
	add r0, sb
	lsls r5, r7, #1
	ldr r2, [sp, #0xdc]
	lsls r1, r2, #1
	ldr r2, .L08043B3C @ =0xFFFFFCC0
	add r2, r8
	adds r1, r1, r2
	adds r5, r5, r1
	lsls r4, r6, #0x10
	lsrs r4, r4, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r2, #0x10
	adds r3, r4, #0
	bl sub_805B1AC
	movs r0, #0x80
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0x10
	adds r2, r4, #0
	movs r3, #3
	bl sub_805B01C
.L08043AE0:
	movs r0, #1
	bl EnableBgSync
.L08043AE6:
	ldr r1, .L08043B44 @ =0x0203CDA8
	ldr r0, .L08043B48 @ =0x0203CDA0
	ldrh r2, [r0]
	adds r5, r0, #0
	ldrh r3, [r1]
	ldrh r4, [r5]
	cmp r3, r4
	beq .L08043AFA
	movs r0, #1
	str r0, [sp, #0xd8]
.L08043AFA:
	ldrh r0, [r5, #2]
	ldrh r3, [r1, #2]
	cmp r3, r0
	beq .L08043B06
	movs r4, #1
	str r4, [sp, #0xd8]
.L08043B06:
	strh r2, [r1]
	strh r0, [r1, #2]
	ldrh r7, [r5]
	ldr r0, .L08043B4C @ =0x0203CDA4
	ldrh r6, [r0]
	ldrh r1, [r5, #2]
	mov r8, r1
	ldrh r0, [r0, #2]
	str r0, [sp, #0xd4]
	ldr r0, .L08043B50 @ =0x0203CD14
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #3
	beq .L08043B54
	cmp r0, #3
	bgt .L08043B74
	cmp r0, #0
	blt .L08043B74
	mov r3, sl
	movs r4, #0x32
	ldrsh r3, [r3, r4]
	str r3, [sp, #0xe0]
	b .L08043B7E
	.align 2, 0
.L08043B34: .4byte gBg0Tm+0x340
.L08043B38: .4byte gUnk_08112AD0
.L08043B3C: .4byte 0xFFFFFCC0
.L08043B40: .4byte gUnk_08112BA4
.L08043B44: .4byte 0x0203CDA8
.L08043B48: .4byte 0x0203CDA0
.L08043B4C: .4byte 0x0203CDA4
.L08043B50: .4byte 0x0203CD14
.L08043B54:
	ldr r0, .L08043B68 @ =0x0203CCF8
	ldrh r0, [r0]
	cmp r0, #1
	bne .L08043B6C
	mov r1, sl
	movs r2, #0x32
	ldrsh r0, [r1, r2]
	adds r0, #0x38
	b .L08043B7C
	.align 2, 0
.L08043B68: .4byte 0x0203CCF8
.L08043B6C:
	mov r3, sl
	movs r4, #0x32
	ldrsh r0, [r3, r4]
	b .L08043B7A
.L08043B74:
	mov r1, sl
	movs r2, #0x32
	ldrsh r0, [r1, r2]
.L08043B7A:
	subs r0, #0x38
.L08043B7C:
	str r0, [sp, #0xe0]
.L08043B7E:
	ldr r3, [sp, #0x104]
	ldrb r0, [r3]
	cmp r0, #0
	bne .L08043B98
	ldr r4, .L08043B94 @ =0x0000FFF8
	mov r0, sl
	ldrh r1, [r0, #0x3a]
	ands r1, r4
	str r1, [sp, #0xe4]
	b .L08043BA0
	.align 2, 0
.L08043B94: .4byte 0x0000FFF8
.L08043B98:
	mov r2, sl
	movs r3, #0x3a
	ldrsh r2, [r2, r3]
	str r2, [sp, #0xe4]
.L08043BA0:
	adds r4, r5, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl Div
	add r2, sp, #0x68
	strh r0, [r2]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	ldrh r4, [r4]
	subs r1, r4, r1
	strh r1, [r2, #2]
	lsls r0, r0, #0x10
	mov sb, r2
	cmp r0, #0
	bne .L08043BC8
	movs r0, #0xb
	strh r0, [r2]
.L08043BC8:
	movs r2, #2
	ldrsh r0, [r5, r2]
	movs r1, #0xa
	bl Div
	mov r3, sb
	strh r0, [r3, #4]
	adds r4, r0, #0
	lsls r1, r4, #2
	adds r2, r0, #0
	adds r1, r1, r2
	lsls r1, r1, #1
	ldrh r5, [r5, #2]
	subs r1, r5, r1
	strh r1, [r3, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08043BF0
	movs r0, #0xb
	strh r0, [r3, #4]
.L08043BF0:
	ldr r3, [sp, #0xe0]
	adds r3, #9
	str r3, [sp, #0xf0]
	ldr r4, [sp, #0xe4]
	adds r4, #0x91
	str r4, [sp, #0x110]
	ldr r0, [sp, #0xe0]
	adds r0, #0x81
	str r0, [sp, #0x10c]
	lsls r1, r7, #0x10
	str r1, [sp, #0xf4]
	lsls r6, r6, #0x10
	str r6, [sp, #0xf8]
	ldr r2, [sp, #0xe0]
	adds r2, #0x1d
	str r2, [sp, #0x108]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xfc]
	ldr r4, [sp, #0xd4]
	lsls r4, r4, #0x10
	str r4, [sp, #0x100]
	ldr r0, [sp, #0xe0]
	adds r0, #0x95
	str r0, [sp, #0x114]
	ldr r1, [sp, #0xd8]
	cmp r1, #1
	bne .L08043C7E
	add r0, sp, #0xd0
	movs r1, #0
	str r1, [r0]
	ldr r1, .L08043CB8 @ =gUnk_Banim_02016DC0
	ldr r2, .L08043CBC @ =0x01000020
	bl CpuFastSet
	movs r0, #0
.L08043C38:
	adds r2, r0, #1
	mov r8, r2
	lsls r5, r0, #6
	lsls r0, r0, #2
	mov r3, sb
	adds r4, r0, r3
	movs r6, #1
.L08043C46:
	ldrh r1, [r4]
	lsls r0, r1, #5
	ldr r1, .L08043CC0 @ =gUnk_08113024
	adds r0, r0, r1
	ldr r7, .L08043CB8 @ =gUnk_Banim_02016DC0
	adds r1, r5, r7
	movs r2, #0x10
	bl CpuSet
	adds r5, #0x20
	adds r4, #2
	subs r6, #1
	cmp r6, #0
	bge .L08043C46
	mov r0, r8
	cmp r0, #1
	ble .L08043C38
	ldr r1, .L08043CC4 @ =0x060139C0
	adds r0, r7, #0
	movs r2, #0x40
	bl RegisterDataMove
	adds r0, r7, #0
	adds r0, #0x40
	ldr r1, .L08043CC8 @ =0x06013DC0
	movs r2, #0x40
	bl RegisterDataMove
.L08043C7E:
	add r0, sp, #8
	movs r4, #0
	ldr r1, .L08043CCC @ =0x000051CE
	strh r1, [r0, #8]
	adds r2, r0, #0
	mov r3, sl
	ldr r0, [r3, #0x44]
	orrs r0, r1
	strh r0, [r2, #8]
	adds r0, r2, #0
	add r1, sp, #0xf0
	ldrh r1, [r1]
	strh r1, [r0, #2]
	add r2, sp, #0x110
	ldrh r2, [r2]
	strh r2, [r0, #4]
	strh r4, [r0, #0xc]
	movs r0, #0
	bl sub_80449E4
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #1
	beq .L08043CD4
	ldr r0, .L08043CD0 @ =gUnk_085CB5B0
	str r0, [sp, #0x44]
	str r4, [sp, #0x24]
	b .L08043CFE
	.align 2, 0
.L08043CB8: .4byte gUnk_Banim_02016DC0
.L08043CBC: .4byte 0x01000020
.L08043CC0: .4byte gUnk_08113024
.L08043CC4: .4byte 0x060139C0
.L08043CC8: .4byte 0x06013DC0
.L08043CCC: .4byte 0x000051CE
.L08043CD0: .4byte gUnk_085CB5B0
.L08043CD4:
	add r1, sp, #0x70
	str r1, [sp, #0x44]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x24]
	add r2, sp, #8
	adds r0, r2, #0
	ldrh r0, [r0, #2]
	subs r0, #8
	strh r0, [r2, #2]
	adds r0, r2, #0
	ldrh r0, [r0, #4]
	subs r0, #8
	strh r0, [r2, #4]
	ldr r0, .L08043D48 @ =gUnk_085CB5B0
	movs r2, #0x80
	lsls r2, r2, #1
	str r3, [sp]
	movs r3, #0x80
	bl sub_805BB24
.L08043CFE:
	mov r3, sl
	ldr r0, [r3, #0x4c]
	cmp r0, #0
	bne .L08043D0C
	add r0, sp, #8
	bl BasPutOam
.L08043D0C:
	movs r4, #0
	str r4, [sp, #0x24]
	add r0, sp, #8
	ldr r1, .L08043D4C @ =0x000061EE
	strh r1, [r0, #8]
	adds r2, r0, #0
	mov r3, sl
	ldr r0, [r3, #0x44]
	orrs r0, r1
	strh r0, [r2, #8]
	adds r0, r2, #0
	add r1, sp, #0x10c
	ldrh r1, [r1]
	strh r1, [r0, #2]
	add r2, sp, #0x110
	ldrh r2, [r2]
	strh r2, [r0, #4]
	strh r4, [r0, #0xc]
	movs r0, #1
	bl sub_80449E4
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #1
	beq .L08043D50
	ldr r0, .L08043D48 @ =gUnk_085CB5B0
	str r0, [sp, #0x44]
	str r4, [sp, #0x24]
	b .L08043D7A
	.align 2, 0
.L08043D48: .4byte gUnk_085CB5B0
.L08043D4C: .4byte 0x000061EE
.L08043D50:
	add r1, sp, #0x70
	str r1, [sp, #0x44]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x24]
	add r2, sp, #8
	adds r0, r2, #0
	ldrh r0, [r0, #2]
	subs r0, #8
	strh r0, [r2, #2]
	adds r0, r2, #0
	ldrh r0, [r0, #4]
	subs r0, #8
	strh r0, [r2, #4]
	ldr r0, .L08043E5C @ =gUnk_085CB5B0
	movs r2, #0x80
	lsls r2, r2, #1
	str r3, [sp]
	movs r3, #0x80
	bl sub_805BB24
.L08043D7A:
	mov r3, sl
	ldr r0, [r3, #0x50]
	cmp r0, #0
	bne .L08043D88
	add r0, sp, #8
	bl BasPutOam
.L08043D88:
	ldr r4, [sp, #0xf4]
	ldr r0, .L08043E60 @ =0xFFD80000
	adds r1, r4, r0
	ldr r2, [sp, #0xf8]
	adds r0, r2, r0
	lsrs r5, r0, #0x10
	lsrs r6, r4, #0x10
	lsrs r7, r2, #0x10
	lsrs r3, r1, #0x10
	mov r8, r3
	cmp r1, #0
	bge .L08043DA4
	movs r4, #0
	mov r8, r4
.L08043DA4:
	lsls r0, r5, #0x10
	cmp r0, #0
	bge .L08043DAC
	movs r5, #0
.L08043DAC:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	ble .L08043DB6
	movs r6, #0x28
.L08043DB6:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	ble .L08043DC0
	movs r7, #0x28
.L08043DC0:
	add r0, sp, #8
	movs r3, #0
	movs r1, #0xb0
	lsls r1, r1, #8
	strh r1, [r0, #8]
	adds r2, r0, #0
	mov r4, sl
	ldr r0, [r4, #0x44]
	orrs r0, r1
	strh r0, [r2, #8]
	str r3, [sp, #0x24]
	adds r0, r2, #0
	add r1, sp, #0x108
	ldrh r1, [r1]
	strh r1, [r0, #2]
	ldr r0, .L08043E64 @ =gUnk_085CB580
	str r0, [sp, #0x44]
	ldr r2, [r4, #0x4c]
	mov sb, r2
	cmp r2, #0
	bne .L08043E94
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	add r4, sp, #0x50
	cmp r2, #0
	beq .L08043E30
	mov r3, r8
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_805B380
	ldr r0, [sp, #0xd8]
	cmp r0, #1
	bne .L08043E0E
	ldr r1, .L08043E68 @ =gUnk_Banim_02016E40
	adds r0, r4, #0
	bl sub_80435EC
.L08043E0E:
	add r1, sp, #8
	ldr r0, [sp, #0xe4]
	adds r0, #0x8e
	strh r0, [r1, #4]
	adds r2, r1, #0
	movs r0, #0xfc
	lsls r0, r0, #8
	ldrh r1, [r1, #8]
	ands r0, r1
	strh r0, [r2, #8]
	adds r1, r2, #0
	strh r0, [r1, #8]
	adds r0, r1, #0
	mov r1, sb
	strh r1, [r0, #0xc]
	bl BasPutOam
.L08043E30:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r2, r7, #0x10
	asrs r2, r2, #0x10
	adds r0, r4, #0
	bl sub_805B380
	ldr r2, [sp, #0xd8]
	cmp r2, #1
	bne .L08043E4C
	ldr r1, .L08043E6C @ =gUnk_Banim_02017240
	adds r0, r4, #0
	bl sub_80435EC
.L08043E4C:
	cmp r5, #0
	beq .L08043E70
	add r1, sp, #8
	ldr r0, [sp, #0xe4]
	adds r0, #0x95
	strh r0, [r1, #4]
	b .L08043E78
	.align 2, 0
.L08043E5C: .4byte gUnk_085CB5B0
.L08043E60: .4byte 0xFFD80000
.L08043E64: .4byte gUnk_085CB580
.L08043E68: .4byte gUnk_Banim_02016E40
.L08043E6C: .4byte gUnk_Banim_02017240
.L08043E70:
	add r0, sp, #8
	add r3, sp, #0x110
	ldrh r3, [r3]
	strh r3, [r0, #4]
.L08043E78:
	add r2, sp, #8
	adds r1, r2, #0
	movs r0, #0xfc
	lsls r0, r0, #8
	ldrh r1, [r1, #8]
	ands r0, r1
	movs r3, #0
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r2, #8]
	adds r0, r2, #0
	strh r3, [r0, #0xc]
	bl BasPutOam
.L08043E94:
	ldr r4, [sp, #0xfc]
	ldr r0, .L08043F74 @ =0xFFD80000
	adds r1, r4, r0
	ldr r2, [sp, #0x100]
	adds r0, r2, r0
	lsrs r5, r0, #0x10
	lsrs r6, r4, #0x10
	lsrs r7, r2, #0x10
	lsrs r3, r1, #0x10
	mov r8, r3
	cmp r1, #0
	bge .L08043EB0
	movs r4, #0
	mov r8, r4
.L08043EB0:
	lsls r0, r5, #0x10
	cmp r0, #0
	bge .L08043EB8
	movs r5, #0
.L08043EB8:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	ble .L08043EC2
	movs r6, #0x28
.L08043EC2:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	ble .L08043ECC
	movs r7, #0x28
.L08043ECC:
	add r0, sp, #8
	movs r1, #0
	mov sb, r1
	movs r1, #0xc0
	lsls r1, r1, #8
	strh r1, [r0, #8]
	adds r2, r0, #0
	mov r3, sl
	ldr r0, [r3, #0x44]
	movs r4, #0
	add r3, sp, #0xec
	strh r4, [r3]
	orrs r0, r1
	strh r0, [r2, #8]
	mov r4, sb
	str r4, [sp, #0x24]
	adds r0, r2, #0
	add r1, sp, #0x114
	ldrh r1, [r1]
	strh r1, [r0, #2]
	ldr r0, .L08043F78 @ =gUnk_085CB580
	str r0, [sp, #0x44]
	mov r2, sl
	ldr r2, [r2, #0x50]
	mov sb, r2
	cmp r2, #0
	bne .L08043FA8
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	adds r5, r0, #0
	add r4, sp, #0x50
	cmp r2, #0
	beq .L08043F4A
	mov r3, r8
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_805B380
	ldr r0, [sp, #0xd8]
	cmp r0, #1
	bne .L08043F28
	ldr r1, .L08043F7C @ =gUnk_Banim_02017040
	adds r0, r4, #0
	bl sub_80435EC
.L08043F28:
	add r1, sp, #8
	ldr r0, [sp, #0xe4]
	adds r0, #0x8e
	strh r0, [r1, #4]
	adds r2, r1, #0
	movs r0, #0xfc
	lsls r0, r0, #8
	ldrh r1, [r1, #8]
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2, #8]
	adds r0, r2, #0
	mov r1, sb
	strh r1, [r0, #0xc]
	bl BasPutOam
.L08043F4A:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r2, r7, #0x10
	asrs r2, r2, #0x10
	adds r0, r4, #0
	bl sub_805B380
	ldr r2, [sp, #0xd8]
	cmp r2, #1
	bne .L08043F66
	ldr r1, .L08043F80 @ =gUnk_Banim_02017440
	adds r0, r4, #0
	bl sub_80435EC
.L08043F66:
	cmp r5, #0
	beq .L08043F84
	add r1, sp, #8
	ldr r0, [sp, #0xe4]
	adds r0, #0x95
	strh r0, [r1, #4]
	b .L08043F8C
	.align 2, 0
.L08043F74: .4byte 0xFFD80000
.L08043F78: .4byte gUnk_085CB580
.L08043F7C: .4byte gUnk_Banim_02017040
.L08043F80: .4byte gUnk_Banim_02017440
.L08043F84:
	add r0, sp, #8
	add r3, sp, #0x110
	ldrh r3, [r3]
	strh r3, [r0, #4]
.L08043F8C:
	add r2, sp, #8
	adds r1, r2, #0
	movs r0, #0xfc
	lsls r0, r0, #8
	ldrh r1, [r1, #8]
	ands r0, r1
	movs r3, #0
	movs r1, #0x30
	orrs r0, r1
	strh r0, [r2, #8]
	adds r0, r2, #0
	strh r3, [r0, #0xc]
	bl BasPutOam
.L08043FA8:
	ldr r4, [sp, #0xd8]
	cmp r4, #1
	bne .L08043FBA
	ldr r0, .L08044164 @ =gUnk_Banim_02016E40
	ldr r1, .L08044168 @ =0x06013000
	movs r2, #0x80
	lsls r2, r2, #4
	bl RegisterDataMove
.L08043FBA:
	mov r0, sl
	ldr r4, [r0, #0x4c]
	cmp r4, #0
	bne .L0804401A
	str r4, [sp, #0x24]
	ldr r0, .L0804416C @ =gUnk_085CB5C8
	str r0, [sp, #0x44]
	add r0, sp, #8
	ldr r1, .L08044170 @ =0x000051D0
	strh r1, [r0, #8]
	adds r2, r0, #0
	mov r3, sl
	ldr r0, [r3, #0x44]
	orrs r0, r1
	strh r0, [r2, #8]
	adds r1, r2, #0
	ldr r0, [sp, #0xe0]
	adds r0, #0xf
	strh r0, [r1, #2]
	ldr r0, [sp, #0xe4]
	adds r0, #0x70
	strh r0, [r1, #4]
	adds r0, r1, #0
	strh r4, [r0, #0xc]
	bl BasPutOam
	str r4, [sp, #0x24]
	ldr r0, .L08044174 @ =gUnk_085CB5F8
	str r0, [sp, #0x44]
	add r0, sp, #8
	ldr r1, .L08044178 @ =0x000051C0
	strh r1, [r0, #8]
	adds r2, r0, #0
	mov r3, sl
	ldr r0, [r3, #0x44]
	orrs r0, r1
	strh r0, [r2, #8]
	adds r1, r2, #0
	ldr r0, [sp, #0xe0]
	adds r0, #0x65
	strh r0, [r1, #2]
	ldr r0, [sp, #0xe4]
	adds r0, #0x78
	strh r0, [r1, #4]
	adds r0, r1, #0
	strh r4, [r0, #0xc]
	bl BasPutOam
.L0804401A:
	mov r0, sl
	ldr r4, [r0, #0x50]
	cmp r4, #0
	bne .L0804407A
	str r4, [sp, #0x24]
	ldr r0, .L0804416C @ =gUnk_085CB5C8
	str r0, [sp, #0x44]
	add r0, sp, #8
	ldr r1, .L0804417C @ =0x000061F0
	strh r1, [r0, #8]
	adds r2, r0, #0
	mov r3, sl
	ldr r0, [r3, #0x44]
	orrs r0, r1
	strh r0, [r2, #8]
	adds r1, r2, #0
	ldr r0, [sp, #0xe0]
	adds r0, #0xd7
	strh r0, [r1, #2]
	ldr r0, [sp, #0xe4]
	adds r0, #0x70
	strh r0, [r1, #4]
	adds r0, r1, #0
	strh r4, [r0, #0xc]
	bl BasPutOam
	str r4, [sp, #0x24]
	ldr r0, .L08044180 @ =gUnk_085CB634
	str r0, [sp, #0x44]
	add r0, sp, #8
	ldr r1, .L08044184 @ =0x000061C0
	strh r1, [r0, #8]
	adds r2, r0, #0
	mov r3, sl
	ldr r0, [r3, #0x44]
	orrs r0, r1
	strh r0, [r2, #8]
	adds r1, r2, #0
	ldr r0, [sp, #0xe0]
	adds r0, #0x87
	strh r0, [r1, #2]
	ldr r0, [sp, #0xe4]
	adds r0, #0x78
	strh r0, [r1, #4]
	adds r0, r1, #0
	strh r4, [r0, #0xc]
	bl BasPutOam
.L0804407A:
	mov r0, sl
	ldr r4, [r0, #0x4c]
	cmp r4, #0
	bne .L080440E6
	str r4, [sp, #0x24]
	ldr r1, .L08044188 @ =0x0203CDC8
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r5, [sp, #0xe4]
	adds r5, #0x7a
	cmp r0, #0
	beq .L080440C0
	adds r1, r0, #0
	add r0, sp, #8
	ldr r2, [sp, #0xe8]
	bl sub_8043980
	add r0, sp, #8
	movs r1, #0xe5
	lsls r1, r1, #1
	strh r1, [r0, #8]
	adds r2, r0, #0
	mov r3, sl
	ldr r0, [r3, #0x44]
	orrs r0, r1
	strh r0, [r2, #8]
	adds r1, r2, #0
	ldr r0, [sp, #0xe0]
	adds r0, #0x36
	strh r0, [r1, #2]
	adds r0, r1, #0
	strh r5, [r0, #4]
	strh r4, [r0, #0xc]
	bl BasPutOam
.L080440C0:
	ldr r0, .L0804418C @ =gUnk_085CB670
	str r0, [sp, #0x44]
	add r0, sp, #8
	ldr r1, .L08044190 @ =0x0000D1DC
	strh r1, [r0, #8]
	adds r2, r0, #0
	mov r3, sl
	ldr r0, [r3, #0x44]
	orrs r0, r1
	strh r0, [r2, #8]
	adds r1, r2, #0
	ldr r0, [sp, #0xe0]
	adds r0, #0x2c
	strh r0, [r1, #2]
	adds r0, r1, #0
	strh r5, [r0, #4]
	strh r4, [r0, #0xc]
	bl BasPutOam
.L080440E6:
	mov r0, sl
	ldr r4, [r0, #0x50]
	cmp r4, #0
	bne .L08044152
	str r4, [sp, #0x24]
	ldr r1, .L08044188 @ =0x0203CDC8
	movs r2, #2
	ldrsh r0, [r1, r2]
	ldr r5, [sp, #0xe4]
	adds r5, #0x7a
	cmp r0, #0
	beq .L0804412C
	adds r1, r0, #0
	add r0, sp, #8
	ldr r2, [sp, #0xe8]
	bl sub_8043980
	add r0, sp, #8
	movs r1, #0xe5
	lsls r1, r1, #1
	strh r1, [r0, #8]
	adds r2, r0, #0
	mov r3, sl
	ldr r0, [r3, #0x44]
	orrs r0, r1
	strh r0, [r2, #8]
	adds r1, r2, #0
	ldr r0, [sp, #0xe0]
	adds r0, #0x85
	strh r0, [r1, #2]
	adds r0, r1, #0
	strh r5, [r0, #4]
	strh r4, [r0, #0xc]
	bl BasPutOam
.L0804412C:
	ldr r0, .L0804418C @ =gUnk_085CB670
	str r0, [sp, #0x44]
	add r0, sp, #8
	ldr r1, .L08044194 @ =0x0000E1DE
	strh r1, [r0, #8]
	adds r2, r0, #0
	mov r3, sl
	ldr r0, [r3, #0x44]
	orrs r0, r1
	strh r0, [r2, #8]
	adds r1, r2, #0
	ldr r0, [sp, #0xe0]
	adds r0, #0x7b
	strh r0, [r1, #2]
	adds r0, r1, #0
	strh r5, [r0, #4]
	strh r4, [r0, #0xc]
	bl BasPutOam
.L08044152:
	add sp, #0x118
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08044164: .4byte gUnk_Banim_02016E40
.L08044168: .4byte 0x06013000
.L0804416C: .4byte gUnk_085CB5C8
.L08044170: .4byte 0x000051D0
.L08044174: .4byte gUnk_085CB5F8
.L08044178: .4byte 0x000051C0
.L0804417C: .4byte 0x000061F0
.L08044180: .4byte gUnk_085CB634
.L08044184: .4byte 0x000061C0
.L08044188: .4byte 0x0203CDC8
.L0804418C: .4byte gUnk_085CB670
.L08044190: .4byte 0x0000D1DC
.L08044194: .4byte 0x0000E1DE

	thumb_func_start sub_8044198
sub_8044198: @ 0x08044198
	push {r4, lr}
	ldr r4, .L080441C0 @ =gUnk_Banim_02000064
	ldr r0, .L080441C4 @ =gUnk_085CB718
	movs r1, #5
	bl SpawnProc
	str r0, [r4]
	movs r0, #0
	movs r1, #0
	bl sub_804421C
	bl sub_80441DC
	bl sub_8044274
	bl sub_8044254
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080441C0: .4byte gUnk_Banim_02000064
.L080441C4: .4byte gUnk_085CB718

	thumb_func_start sub_80441C8
sub_80441C8: @ 0x080441C8
	push {lr}
	ldr r0, .L080441D8 @ =gUnk_Banim_02000064
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L080441D8: .4byte gUnk_Banim_02000064

	thumb_func_start sub_80441DC
sub_80441DC: @ 0x080441DC
	ldr r0, .L080441E8 @ =gUnk_Banim_02000064
	ldr r1, [r0]
	movs r0, #0
	str r0, [r1, #0x4c]
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L080441E8: .4byte gUnk_Banim_02000064

	thumb_func_start sub_80441EC
sub_80441EC: @ 0x080441EC
	ldr r0, .L080441F8 @ =gUnk_Banim_02000064
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x4c]
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L080441F8: .4byte gUnk_Banim_02000064

	thumb_func_start sub_80441FC
sub_80441FC: @ 0x080441FC
	ldr r0, .L08044208 @ =gUnk_Banim_02000064
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x4c]
	bx lr
	.align 2, 0
.L08044208: .4byte gUnk_Banim_02000064

	thumb_func_start sub_804420C
sub_804420C: @ 0x0804420C
	ldr r0, .L08044218 @ =gUnk_Banim_02000064
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L08044218: .4byte gUnk_Banim_02000064

	thumb_func_start sub_804421C
sub_804421C: @ 0x0804421C
	ldr r2, .L0804422C @ =gUnk_Banim_02000064
	ldr r2, [r2]
	movs r3, #0
	strh r0, [r2, #0x32]
	strh r1, [r2, #0x3a]
	adds r2, #0x29
	strb r3, [r2]
	bx lr
	.align 2, 0
.L0804422C: .4byte gUnk_Banim_02000064

	thumb_func_start sub_8044230
sub_8044230: @ 0x08044230
	ldr r2, .L08044240 @ =gUnk_Banim_02000064
	ldr r2, [r2]
	strh r0, [r2, #0x32]
	strh r1, [r2, #0x3a]
	adds r2, #0x29
	movs r0, #1
	strb r0, [r2]
	bx lr
	.align 2, 0
.L08044240: .4byte gUnk_Banim_02000064

	thumb_func_start sub_8044244
sub_8044244: @ 0x08044244
	ldr r0, .L08044250 @ =gUnk_Banim_02000064
	ldr r0, [r0]
	adds r0, #0x29
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
.L08044250: .4byte gUnk_Banim_02000064

	thumb_func_start sub_8044254
sub_8044254: @ 0x08044254
	ldr r0, .L08044260 @ =gUnk_Banim_02000064
	ldr r0, [r0]
	adds r0, #0x29
	movs r1, #0
	strb r1, [r0]
	bx lr
	.align 2, 0
.L08044260: .4byte gUnk_Banim_02000064

	thumb_func_start sub_8044264
sub_8044264: @ 0x08044264
	ldr r0, .L08044270 @ =gUnk_Banim_02000064
	ldr r0, [r0]
	adds r0, #0x2a
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
.L08044270: .4byte gUnk_Banim_02000064

	thumb_func_start sub_8044274
sub_8044274: @ 0x08044274
	ldr r0, .L08044280 @ =gUnk_Banim_02000064
	ldr r0, [r0]
	adds r0, #0x2a
	movs r1, #0
	strb r1, [r0]
	bx lr
	.align 2, 0
.L08044280: .4byte gUnk_Banim_02000064

	thumb_func_start sub_8044284
sub_8044284: @ 0x08044284
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #1
	beq .L08044374
	adds r0, r7, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08044374
	ldrh r1, [r7, #0x3a]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x13
	lsls r2, r0, #5
	mov r8, r2
	cmp r2, #0
	bge .L080442B6
	movs r1, #0
	mov r8, r1
.L080442B6:
	adds r6, r0, #7
	cmp r6, #6
	ble .L080442BE
	movs r6, #6
.L080442BE:
	movs r0, #6
	subs r0, r0, r6
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	mov sl, r1
	ldr r0, .L080442DC @ =0x0203CD14
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt .L080442E0
	cmp r0, #2
	bgt .L080442E0
	movs r4, #0
	b .L080442E2
	.align 2, 0
.L080442DC: .4byte 0x0203CD14
.L080442E0:
	movs r4, #0xf
.L080442E2:
	ldr r0, .L08044384 @ =gBg0Tm
	mov sb, r0
	movs r0, #0x9f
	str r0, [sp]
	mov r0, sb
	movs r1, #0x1e
	movs r2, #7
	movs r3, #0
	bl sub_805B094
	cmp r6, #0
	ble .L0804436E
	ldr r0, [r7, #0x4c]
	cmp r0, #0
	bne .L08044334
	ldr r0, .L08044388 @ =gUnk_08112968
	add r0, sl
	mov r1, r8
	lsls r5, r1, #1
	lsls r1, r4, #1
	add r1, sb
	adds r5, r5, r1
	lsls r4, r6, #0x10
	lsrs r4, r4, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r2, #0xf
	adds r3, r4, #0
	bl sub_805B1AC
	movs r0, #0x80
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0xf
	adds r2, r4, #0
	movs r3, #2
	bl sub_805B01C
.L08044334:
	ldr r0, [r7, #0x50]
	cmp r0, #0
	bne .L0804436E
	ldr r0, .L0804438C @ =gUnk_08112A1C
	add r0, sl
	mov r2, r8
	lsls r5, r2, #1
	movs r2, #0xf
	lsls r1, r2, #1
	add r1, sb
	adds r5, r5, r1
	lsls r4, r6, #0x10
	lsrs r4, r4, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	adds r1, r5, #0
	adds r3, r4, #0
	bl sub_805B1AC
	movs r0, #0x80
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0xf
	adds r2, r4, #0
	movs r3, #3
	bl sub_805B01C
.L0804436E:
	movs r0, #1
	bl EnableBgSync
.L08044374:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08044384: .4byte gBg0Tm
.L08044388: .4byte gUnk_08112968
.L0804438C: .4byte gUnk_08112A1C

	thumb_func_start sub_8044390
sub_8044390: @ 0x08044390
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r4, .L08044484 @ =gDispIo
	movs r2, #8
	rsbs r2, r2, #0
	ldrb r0, [r4]
	ands r2, r0
	movs r5, #1
	ldrb r0, [r4, #1]
	orrs r0, r5
	movs r6, #2
	orrs r0, r6
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #1]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r2, r0
	strb r2, [r4]
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
	movs r0, #0
	movs r1, #0
	bl SetBgChrOffset
	movs r0, #1
	movs r1, #0
	bl SetBgChrOffset
	movs r0, #2
	movs r1, #0
	bl SetBgChrOffset
	movs r1, #0x80
	lsls r1, r1, #8
	movs r0, #3
	bl SetBgChrOffset
	movs r1, #0xc0
	lsls r1, r1, #7
	movs r0, #0
	bl SetBgTilemapOffset
	movs r1, #0xd0
	lsls r1, r1, #7
	movs r0, #1
	bl SetBgTilemapOffset
	movs r1, #0xe0
	lsls r1, r1, #7
	movs r0, #2
	bl SetBgTilemapOffset
	movs r1, #0xf0
	lsls r1, r1, #7
	movs r0, #3
	bl SetBgTilemapOffset
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r4, #0xc]
	ands r0, r2
	strb r0, [r4, #0xc]
	adds r0, r1, #0
	ldrb r2, [r4, #0x10]
	ands r0, r2
	orrs r0, r5
	strb r0, [r4, #0x10]
	ldrb r0, [r4, #0x14]
	ands r1, r0
	orrs r1, r6
	strb r1, [r4, #0x14]
	movs r0, #3
	ldrb r1, [r4, #0x18]
	orrs r0, r1
	strb r0, [r4, #0x18]
	movs r4, #0
	str r4, [sp]
	ldr r1, .L08044488 @ =gBg0Tm
	ldr r5, .L0804448C @ =0x01000200
	mov r0, sp
	adds r2, r5, #0
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r1, .L08044490 @ =gBg1Tm
	adds r2, r5, #0
	bl CpuFastSet
	str r4, [sp, #8]
	add r0, sp, #8
	ldr r6, .L08044494 @ =gBg2Tm
	adds r1, r6, #0
	adds r2, r5, #0
	bl CpuFastSet
	bl sub_804C500
	cmp r0, #0
	bne .L08044498
	bl sub_80444EC
	b .L080444A4
	.align 2, 0
.L08044484: .4byte gDispIo
.L08044488: .4byte gBg0Tm
.L0804448C: .4byte 0x01000200
.L08044490: .4byte gBg1Tm
.L08044494: .4byte gBg2Tm
.L08044498:
	str r4, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r6, #0
	adds r2, r5, #0
	bl CpuFastSet
.L080444A4:
	bl sub_8044608
	bl EnablePalSync
	movs r0, #1
	bl EnableBgSync
	movs r0, #2
	bl EnableBgSync
	movs r0, #4
	bl EnableBgSync
	ldr r3, .L080444E8 @ =gDispIo
	adds r1, r3, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	adds r1, #8
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x45
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080444E8: .4byte gDispIo

	thumb_func_start sub_80444EC
sub_80444EC: @ 0x080444EC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, .L0804452C @ =gUnk_Banim_0201E0FC
	ldr r2, .L08044530 @ =0x0203CD10
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r3, .L08044534 @ =0x087EA008
	adds r5, r0, r3
	movs r6, #2
	ldrsh r1, [r2, r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r3, r0, r3
	ldr r0, .L08044538 @ =0x0203CD14
	movs r7, #0
	ldrsh r1, [r0, r7]
	mov r8, r2
	adds r6, r0, #0
	cmp r1, #3
	bgt .L08044540
	cmp r1, #1
	bge .L08044564
	cmp r1, #0
	beq .L08044548
	ldr r0, .L0804453C @ =gUnk_Banim_020145C0
	b .L08044576
	.align 2, 0
.L0804452C: .4byte gUnk_Banim_0201E0FC
.L08044530: .4byte 0x0203CD10
.L08044534: .4byte 0x087EA008
.L08044538: .4byte 0x0203CD14
.L0804453C: .4byte gUnk_Banim_020145C0
.L08044540:
	ldr r7, .L0804455C @ =gUnk_Banim_020145C0
	mov ip, r7
	cmp r1, #4
	bne .L08044578
.L08044548:
	ldr r0, .L08044560 @ =gUnk_Banim_02000034
	ldr r1, .L0804455C @ =gUnk_Banim_020145C0
	str r1, [r0]
	movs r7, #0x80
	lsls r7, r7, #5
	adds r2, r1, r7
	str r2, [r0, #4]
	mov ip, r1
	b .L08044578
	.align 2, 0
.L0804455C: .4byte gUnk_Banim_020145C0
.L08044560: .4byte gUnk_Banim_02000034
.L08044564:
	ldr r0, .L080445E8 @ =gUnk_Banim_02000034
	ldr r1, .L080445EC @ =gUnk_Banim_02014DC0
	str r1, [r0]
	movs r7, #0x80
	lsls r7, r7, #5
	adds r2, r1, r7
	str r2, [r0, #4]
	ldr r0, .L080445F0 @ =0xFFFFF800
	adds r0, r0, r1
.L08044576:
	mov ip, r0
.L08044578:
	ldr r0, .L080445F4 @ =gPlaySt
	ldrb r0, [r0, #0x15]
	ldr r0, .L080445F8 @ =gUnk_Banim_02000044
	ldr r1, [r5, #0x10]
	str r1, [r0]
	ldr r1, [r3, #0x10]
	str r1, [r0, #4]
	ldr r2, .L080445FC @ =gUnk_Banim_0200003C
	ldr r1, .L08044600 @ =gUnk_085CBDB0
	movs r3, #0
	ldrsh r0, [r6, r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	movs r7, #0
	ldrsh r0, [r6, r7]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2, #4]
	mov r1, r8
	ldrh r0, [r1]
	movs r2, #0
	strh r0, [r4]
	movs r0, #4
	strh r0, [r4, #2]
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r4, #4]
	mov r3, r8
	ldrh r0, [r3, #2]
	strh r0, [r4, #6]
	movs r0, #5
	strh r0, [r4, #8]
	strh r1, [r4, #0xa]
	ldrh r0, [r6]
	strh r0, [r4, #0xc]
	movs r0, #2
	strh r0, [r4, #0xe]
	str r2, [r4, #0x1c]
	mov r6, ip
	str r6, [r4, #0x20]
	ldr r0, .L08044604 @ =0x0203CCF6
	ldrh r0, [r0]
	strh r0, [r4, #0x10]
	adds r0, r4, #0
	bl sub_804BF40
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080445E8: .4byte gUnk_Banim_02000034
.L080445EC: .4byte gUnk_Banim_02014DC0
.L080445F0: .4byte 0xFFFFF800
.L080445F4: .4byte gPlaySt
.L080445F8: .4byte gUnk_Banim_02000044
.L080445FC: .4byte gUnk_Banim_0200003C
.L08044600: .4byte gUnk_085CBDB0
.L08044604: .4byte 0x0203CCF6

	thumb_func_start sub_8044608
sub_8044608: @ 0x08044608
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r4, .L08044648 @ =Pal_SystemText
	adds r0, r4, #0
	movs r1, #0x40
	movs r2, #0x20
	bl ApplyPaletteExt
	adds r0, r4, #0
	movs r1, #0x60
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L0804464C @ =gUnk_Banim_02017640
	ldr r1, .L08044650 @ =0x06001400
	movs r2, #0xa0
	movs r3, #2
	bl InitTextFont
	bl SetTextDrawNoClear
	ldr r0, .L08044654 @ =gUnk_081125E0
	ldr r1, .L08044658 @ =0x06001000
	bl LZ77UnCompVram
	ldr r0, .L0804465C @ =0x0203CCF8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08044664
	ldr r5, .L08044660 @ =gUnk_085CB504
	b .L08044672
	.align 2, 0
.L08044648: .4byte Pal_SystemText
.L0804464C: .4byte gUnk_Banim_02017640
.L08044650: .4byte 0x06001400
.L08044654: .4byte gUnk_081125E0
.L08044658: .4byte 0x06001000
.L0804465C: .4byte 0x0203CCF8
.L08044660: .4byte gUnk_085CB504
.L08044664:
	ldr r0, .L080446AC @ =0x0203CD7C
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r5, r0, #0
.L08044672:
	ldr r4, .L080446B0 @ =gUnk_Banim_02017658
	adds r0, r4, #0
	movs r1, #6
	bl InitText
	movs r0, #0x30
	adds r1, r5, #0
	bl GetStringTextCenteredPos
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_SetCursor
	ldr r0, .L080446B4 @ =gUnk_081127F0
	ldr r1, .L080446B8 @ =0x06001400
	bl LZ77UnCompVram
	adds r0, r4, #0
	adds r1, r5, #0
	bl Text_DrawString
	ldr r0, .L080446BC @ =0x0203CCF8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080446C4
	ldr r5, .L080446C0 @ =gUnk_085CB504
	b .L080446D2
	.align 2, 0
.L080446AC: .4byte 0x0203CD7C
.L080446B0: .4byte gUnk_Banim_02017658
.L080446B4: .4byte gUnk_081127F0
.L080446B8: .4byte 0x06001400
.L080446BC: .4byte 0x0203CCF8
.L080446C0: .4byte gUnk_085CB504
.L080446C4:
	ldr r0, .L0804470C @ =0x0203CD7C
	ldr r0, [r0]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemName
	adds r5, r0, #0
.L080446D2:
	ldr r4, .L08044710 @ =gUnk_Banim_02017668
	adds r0, r4, #0
	movs r1, #7
	bl InitText
	movs r0, #0x38
	adds r1, r5, #0
	bl GetStringTextCenteredPos
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_SetCursor
	ldr r0, .L08044714 @ =gUnk_08112840
	ldr r1, .L08044718 @ =0x06001580
	bl LZ77UnCompVram
	adds r0, r4, #0
	adds r1, r5, #0
	bl Text_DrawString
	ldr r0, .L0804471C @ =0x0203CCF8
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08044724
	ldr r5, .L08044720 @ =gUnk_085CB504
	b .L08044732
	.align 2, 0
.L0804470C: .4byte 0x0203CD7C
.L08044710: .4byte gUnk_Banim_02017668
.L08044714: .4byte gUnk_08112840
.L08044718: .4byte 0x06001580
.L0804471C: .4byte 0x0203CCF8
.L08044720: .4byte gUnk_085CB504
.L08044724:
	ldr r0, .L0804476C @ =0x0203CD80
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r5, r0, #0
.L08044732:
	ldr r4, .L08044770 @ =gUnk_Banim_02017670
	adds r0, r4, #0
	movs r1, #6
	bl InitText
	movs r0, #0x30
	adds r1, r5, #0
	bl GetStringTextCenteredPos
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_SetCursor
	ldr r0, .L08044774 @ =gUnk_081128AC
	ldr r1, .L08044778 @ =0x06001740
	bl LZ77UnCompVram
	adds r0, r4, #0
	adds r1, r5, #0
	bl Text_DrawString
	ldr r0, .L0804477C @ =0x0203CCF8
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08044784
	ldr r5, .L08044780 @ =gUnk_085CB504
	b .L08044792
	.align 2, 0
.L0804476C: .4byte 0x0203CD80
.L08044770: .4byte gUnk_Banim_02017670
.L08044774: .4byte gUnk_081128AC
.L08044778: .4byte 0x06001740
.L0804477C: .4byte 0x0203CCF8
.L08044780: .4byte gUnk_085CB504
.L08044784:
	ldr r0, .L08044848 @ =0x0203CD80
	ldr r0, [r0]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemName
	adds r5, r0, #0
.L08044792:
	ldr r4, .L0804484C @ =gUnk_Banim_02017660
	adds r0, r4, #0
	movs r1, #7
	bl InitText
	movs r0, #0x38
	adds r1, r5, #0
	bl GetStringTextCenteredPos
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_SetCursor
	ldr r0, .L08044850 @ =gUnk_081128FC
	ldr r1, .L08044854 @ =0x060018C0
	bl LZ77UnCompVram
	adds r0, r4, #0
	adds r1, r5, #0
	bl Text_DrawString
	ldr r4, .L08044858 @ =gBg0Tm
	adds r0, r4, #0
	movs r1, #0x9f
	bl TmFill
	ldr r0, .L0804485C @ =gUnk_08112C84
	adds r6, r4, #0
	adds r6, #0x3c
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #0x14
	bl sub_805B1AC
	adds r4, #0x3e
	movs r5, #0x80
	str r5, [sp]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x14
	movs r3, #2
	bl sub_805B01C
	str r5, [sp]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x14
	movs r3, #3
	bl sub_805B01C
	movs r0, #1
	bl EnableBgSync
	ldr r6, .L08044860 @ =0x0203CD08
	movs r1, #0
	ldrsh r0, [r6, r1]
	lsls r0, r0, #5
	ldr r5, .L08044864 @ =gUnk_08112CD4
	adds r0, r0, r5
	ldr r4, .L08044868 @ =gPal+0x40
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	movs r1, #2
	ldrsh r0, [r6, r1]
	lsls r0, r0, #5
	adds r0, r0, r5
	adds r4, #0x20
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	ldr r1, .L0804486C @ =gUnk_Banim_02000030
	movs r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08044848: .4byte 0x0203CD80
.L0804484C: .4byte gUnk_Banim_02017660
.L08044850: .4byte gUnk_081128FC
.L08044854: .4byte 0x060018C0
.L08044858: .4byte gBg0Tm
.L0804485C: .4byte gUnk_08112C84
.L08044860: .4byte 0x0203CD08
.L08044864: .4byte gUnk_08112CD4
.L08044868: .4byte gPal+0x40
.L0804486C: .4byte gUnk_Banim_02000030

	thumb_func_start sub_8044870
sub_8044870: @ 0x08044870
	push {r4, r5, lr}
	ldr r0, .L08044888 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bhi .L080448B0
	lsls r0, r0, #2
	ldr r1, .L0804488C @ =.L08044890
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08044888: .4byte 0x0203CD14
.L0804488C: .4byte .L08044890
.L08044890: @ jump table
	.4byte .L080448F8 @ case 0
	.4byte .L080448A4 @ case 1
	.4byte .L080448B0 @ case 2
	.4byte .L080448F8 @ case 3
	.4byte .L080448F8 @ case 4
.L080448A4:
	ldr r0, .L080448AC @ =0x0203CCF4
	movs r2, #0
	ldrsh r0, [r0, r2]
	b .L080448FA
	.align 2, 0
.L080448AC: .4byte 0x0203CCF4
.L080448B0:
	movs r1, #0
	movs r5, #0
	ldr r0, .L080448E0 @ =0x0203CCF0
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080448D8
	ldr r4, .L080448E4 @ =0x0203CD84
	ldrb r0, [r4]
	ldrb r1, [r4, #1]
	bl sub_806B6F8
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
	ldrb r0, [r4, #1]
	ldrb r1, [r4]
	bl sub_806B6F8
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
.L080448D8:
	cmp r5, #1
	bne .L080448E8
	movs r0, #0
	b .L080448FA
	.align 2, 0
.L080448E0: .4byte 0x0203CCF0
.L080448E4: .4byte 0x0203CD84
.L080448E8:
	cmp r1, #1
	beq .L080448F8
	ldr r0, .L080448F4 @ =0x0203CCF4
	movs r1, #0
	ldrsh r0, [r0, r1]
	b .L080448FA
	.align 2, 0
.L080448F4: .4byte 0x0203CCF4
.L080448F8:
	movs r0, #1
.L080448FA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_8044900
sub_8044900: @ 0x08044900
	push {r4, lr}
	ldr r0, .L0804496C @ =gUnk_Banim_02017720
	movs r4, #0
	str r4, [r0]
	ldr r0, .L08044970 @ =gUnk_Banim_02017724
	str r4, [r0]
	ldr r0, .L08044974 @ =gUnk_Banim_02017728
	str r4, [r0]
	ldr r0, .L08044978 @ =gUnk_Banim_02017730
	str r4, [r0]
	ldr r0, .L0804497C @ =gUnk_Banim_02017734
	str r4, [r0]
	ldr r0, .L08044980 @ =gUnk_Banim_02017738
	str r4, [r0]
	ldr r0, .L08044984 @ =gUnk_Banim_02017740
	str r4, [r0]
	ldr r0, .L08044988 @ =gUnk_Banim_02017744
	str r4, [r0]
	ldr r0, .L0804498C @ =gUnk_Banim_02017748
	str r4, [r0]
	ldr r0, .L08044990 @ =gUnk_Banim_0201774C
	str r4, [r0]
	ldr r0, .L08044994 @ =gUnk_Banim_02017750
	str r4, [r0]
	ldr r0, .L08044998 @ =gUnk_Banim_02017754
	str r4, [r0]
	ldr r0, .L0804499C @ =gUnk_Banim_02017758
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, .L080449A0 @ =gUnk_Banim_0201775C
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, .L080449A4 @ =gUnk_Banim_02017760
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, .L080449A8 @ =gUnk_Banim_02017778
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, .L080449AC @ =gUnk_Banim_02017764
	str r4, [r0]
	str r4, [r0, #4]
	ldr r0, .L080449B0 @ =gUnk_Banim_02017770
	str r4, [r0]
	ldr r0, .L080449B4 @ =gUnk_Banim_02017774
	str r4, [r0]
	ldr r0, .L080449B8 @ =gUnk_08113D70
	ldr r1, .L080449BC @ =0x06012000
	bl LZ77UnCompVram
	ldr r0, .L080449C0 @ =gUnk_Banim_0201E7A4
	str r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804496C: .4byte gUnk_Banim_02017720
.L08044970: .4byte gUnk_Banim_02017724
.L08044974: .4byte gUnk_Banim_02017728
.L08044978: .4byte gUnk_Banim_02017730
.L0804497C: .4byte gUnk_Banim_02017734
.L08044980: .4byte gUnk_Banim_02017738
.L08044984: .4byte gUnk_Banim_02017740
.L08044988: .4byte gUnk_Banim_02017744
.L0804498C: .4byte gUnk_Banim_02017748
.L08044990: .4byte gUnk_Banim_0201774C
.L08044994: .4byte gUnk_Banim_02017750
.L08044998: .4byte gUnk_Banim_02017754
.L0804499C: .4byte gUnk_Banim_02017758
.L080449A0: .4byte gUnk_Banim_0201775C
.L080449A4: .4byte gUnk_Banim_02017760
.L080449A8: .4byte gUnk_Banim_02017778
.L080449AC: .4byte gUnk_Banim_02017764
.L080449B0: .4byte gUnk_Banim_02017770
.L080449B4: .4byte gUnk_Banim_02017774
.L080449B8: .4byte gUnk_08113D70
.L080449BC: .4byte 0x06012000
.L080449C0: .4byte gUnk_Banim_0201E7A4

	thumb_func_start sub_80449C4
sub_80449C4: @ 0x080449C4
	ldr r0, .L080449D8 @ =gUnk_Banim_02017720
	ldr r0, [r0]
	cmp r0, #0
	bne .L080449E0
	ldr r0, .L080449DC @ =gUnk_Banim_02017724
	ldr r0, [r0]
	cmp r0, #0
	bne .L080449E0
	movs r0, #1
	b .L080449E2
	.align 2, 0
.L080449D8: .4byte gUnk_Banim_02017720
.L080449DC: .4byte gUnk_Banim_02017724
.L080449E0:
	movs r0, #0
.L080449E2:
	bx lr

	thumb_func_start sub_80449E4
sub_80449E4: @ 0x080449E4
	ldr r1, .L080449F0 @ =gUnk_Banim_02017778
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
.L080449F0: .4byte gUnk_Banim_02017778

	thumb_func_start sub_80449F4
sub_80449F4: @ 0x080449F4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, .L08044A24 @ =gUnk_Banim_02017720
	ldr r0, [r1]
	cmp r0, #0
	bne .L08044AB4
	movs r0, #1
	str r0, [r1]
	ldr r0, .L08044A28 @ =gUnk_085CB730
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x64]
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08044A30
	ldr r0, .L08044A2C @ =gUnk_Banim_02000000
	ldr r1, [r0, #8]
	str r1, [r6, #0x5c]
	ldr r0, [r0]
	b .L08044A38
	.align 2, 0
.L08044A24: .4byte gUnk_Banim_02017720
.L08044A28: .4byte gUnk_085CB730
.L08044A2C: .4byte gUnk_Banim_02000000
.L08044A30:
	ldr r0, .L08044A8C @ =gUnk_Banim_02000000
	ldr r1, [r0]
	str r1, [r6, #0x5c]
	ldr r0, [r0, #8]
.L08044A38:
	str r0, [r6, #0x60]
	ldr r4, .L08044A90 @ =0x0203CD46
	ldr r0, [r6, #0x60]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r5, [r0, r1]
	adds r4, r5, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [r6, #0x60]
	bl sub_804B6C4
	lsls r5, r5, #1
	adds r5, r5, r0
	adds r0, r5, #0
	bl sub_804A5A8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r6, #0x4c]
	ldr r0, [r6, #0x60]
	bl sub_804B6C4
	lsls r4, r4, #0x10
	asrs r4, r4, #0xf
	adds r4, r4, r0
	adds r0, r4, #0
	bl sub_804A5A8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r6, #0x50]
	ldr r1, [r6, #0x4c]
	cmp r1, r0
	ble .L08044A94
	movs r0, #1
	rsbs r0, r0, #0
	b .L08044A96
	.align 2, 0
.L08044A8C: .4byte gUnk_Banim_02000000
.L08044A90: .4byte 0x0203CD46
.L08044A94:
	movs r0, #1
.L08044A96:
	str r0, [r6, #0x48]
	movs r1, #0
	strh r1, [r6, #0x2c]
	ldr r0, [r6, #0x4c]
	strh r0, [r6, #0x2e]
	str r1, [r6, #0x54]
	str r1, [r6, #0x58]
	ldr r0, [r6, #0x60]
	bl sub_804B6C4
	ldr r1, .L08044ABC @ =gUnk_Banim_02017778
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
.L08044AB4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08044ABC: .4byte gUnk_Banim_02017778

	thumb_func_start sub_8044AC0
sub_8044AC0: @ 0x08044AC0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r4, .L08044B88 @ =gUnk_Banim_02000000
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r6, [r0]
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r7, [r0]
	ldr r1, [r5, #0x58]
	cmp r1, #0
	bne .L08044B26
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne .L08044B26
	strh r1, [r5, #0x2c]
	ldr r0, [r5, #0x48]
	ldrh r1, [r5, #0x2e]
	adds r0, r1, r0
	strh r0, [r5, #0x2e]
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	ldr r1, .L08044B8C @ =0x0203CDA0
	lsls r0, r0, #1
	adds r0, r0, r1
	ldr r1, [r5, #0x48]
	ldrh r2, [r0]
	adds r1, r2, r1
	strh r1, [r0]
	movs r0, #0x2e
	ldrsh r1, [r5, r0]
	ldr r0, [r5, #0x50]
	cmp r1, r0
	bne .L08044B26
	movs r0, #1
	str r0, [r5, #0x58]
.L08044B26:
	ldr r1, .L08044B90 @ =0x0203CD84
	mov r8, r1
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0x66
	beq .L08044B46
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #3
	bne .L08044BC0
.L08044B46:
	ldr r1, [r5, #0x54]
	cmp r1, #0x50
	bne .L08044BB4
	ldr r0, [r5, #0x58]
	cmp r0, #1
	bne .L08044BB4
	ldr r4, .L08044B94 @ =0x0203CD46
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r1, #1
	movs r4, #0
	strh r1, [r0]
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	ldr r1, .L08044B98 @ =gUnk_Banim_02017778
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	ldr r0, [r5, #0x50]
	cmp r0, #0
	bne .L08044C44
	bl sub_8042578
	cmp r0, #1
	bne .L08044B9C
	movs r0, #0
	b .L08044BAE
	.align 2, 0
.L08044B88: .4byte gUnk_Banim_02000000
.L08044B8C: .4byte 0x0203CDA0
.L08044B90: .4byte 0x0203CD84
.L08044B94: .4byte 0x0203CD46
.L08044B98: .4byte gUnk_Banim_02017778
.L08044B9C:
	adds r0, r6, #0
	bl sub_804B6C4
	add r0, r8
	ldrb r0, [r0]
	bl ShouldDisplayDeathQuote
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
.L08044BAE:
	cmp r0, #1
	beq .L08044C1E
	b .L08044C28
.L08044BB4:
	adds r0, r1, #1
	str r0, [r5, #0x54]
	cmp r0, #0x4f
	bls .L08044C5C
	movs r0, #0x50
	b .L08044C5A
.L08044BC0:
	ldr r1, [r5, #0x54]
	cmp r1, #0x1e
	bne .L08044C50
	ldr r0, [r5, #0x58]
	cmp r0, #1
	bne .L08044C50
	ldr r4, .L08044C00 @ =0x0203CD46
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r1, #1
	movs r4, #0
	strh r1, [r0]
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	ldr r1, .L08044C04 @ =gUnk_Banim_02017778
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	ldr r0, [r5, #0x50]
	cmp r0, #0
	bne .L08044C44
	bl sub_8042578
	cmp r0, #1
	bne .L08044C08
	movs r0, #0
	b .L08044C1A
	.align 2, 0
.L08044C00: .4byte 0x0203CD46
.L08044C04: .4byte gUnk_Banim_02017778
.L08044C08:
	adds r0, r6, #0
	bl sub_804B6C4
	add r0, r8
	ldrb r0, [r0]
	bl ShouldDisplayDeathQuote
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
.L08044C1A:
	cmp r0, #1
	bne .L08044C28
.L08044C1E:
	adds r0, r6, #0
	adds r1, r7, #0
	bl sub_80455C0
	b .L08044C44
.L08044C28:
	bl sub_804C554
	adds r0, r6, #0
	adds r1, r7, #0
	bl sub_80457E8
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	ldr r1, .L08044C4C @ =0x0203CCF8
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
.L08044C44:
	adds r0, r5, #0
	bl Proc_Break
	b .L08044C5C
	.align 2, 0
.L08044C4C: .4byte 0x0203CCF8
.L08044C50:
	adds r0, r1, #1
	str r0, [r5, #0x54]
	cmp r0, #0x1d
	bls .L08044C5C
	movs r0, #0x1e
.L08044C5A:
	str r0, [r5, #0x54]
.L08044C5C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8044C68
sub_8044C68: @ 0x08044C68
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08044CB0 @ =gUnk_Banim_02017744
	ldr r0, [r0]
	cmp r0, #0
	bne .L08044D00
	ldr r0, .L08044CB4 @ =gUnk_Banim_02017724
	ldr r0, [r0]
	cmp r0, #0
	bne .L08044D00
	strh r0, [r5, #0x2c]
	movs r0, #1
	strh r0, [r5, #0x2e]
	ldr r0, [r5, #0x64]
	bl sub_804B80C
	adds r4, r0, #0
	bl sub_804B848
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B768
	cmp r0, #1
	bne .L08044CFA
	ldr r0, .L08044CB8 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bhi .L08044CFA
	lsls r0, r0, #2
	ldr r1, .L08044CBC @ =.L08044CC0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08044CB0: .4byte gUnk_Banim_02017744
.L08044CB4: .4byte gUnk_Banim_02017724
.L08044CB8: .4byte 0x0203CD14
.L08044CBC: .4byte .L08044CC0
.L08044CC0: @ jump table
	.4byte .L08044CD4 @ case 0
	.4byte .L08044CD4 @ case 1
	.4byte .L08044CE8 @ case 2
	.4byte .L08044CD4 @ case 3
	.4byte .L08044CD4 @ case 4
.L08044CD4:
	movs r0, #0x10
	strh r0, [r5, #0x2e]
	adds r0, r4, #0
	bl sub_804B80C
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	b .L08044CFA
.L08044CE8:
	movs r0, #0x14
	strh r0, [r5, #0x2e]
	adds r0, r4, #0
	bl sub_804B80C
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L08044CFA:
	adds r0, r5, #0
	bl Proc_Break
.L08044D00:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8044D08
sub_8044D08: @ 0x08044D08
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	movs r3, #0x2e
	ldrsh r0, [r2, r3]
	subs r0, #4
	cmp r1, r0
	bne .L08044D2E
	ldr r0, [r2, #0x64]
	bl sub_804B80C
	movs r0, #4
	bl EnableBgSync
	b .L08044D44
.L08044D2E:
	movs r3, #0x2e
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bne .L08044D44
	ldr r1, .L08044D48 @ =gUnk_Banim_02017720
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r2, #0
	bl Proc_Break
.L08044D44:
	pop {r0}
	bx r0
	.align 2, 0
.L08044D48: .4byte gUnk_Banim_02017720

	thumb_func_start sub_8044D4C
sub_8044D4C: @ 0x08044D4C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, .L08044D84 @ =gUnk_Banim_02017720
	ldr r0, [r1]
	cmp r0, #0
	bne .L08044E1E
	movs r0, #1
	str r0, [r1]
	ldr r0, .L08044D88 @ =gUnk_085CB758
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	adds r0, r4, #0
	bl sub_804B80C
	str r0, [r6, #0x64]
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08044D90
	ldr r0, .L08044D8C @ =gUnk_Banim_02000000
	ldr r1, [r0, #8]
	str r1, [r6, #0x5c]
	ldr r0, [r0]
	b .L08044D98
	.align 2, 0
.L08044D84: .4byte gUnk_Banim_02017720
.L08044D88: .4byte gUnk_085CB758
.L08044D8C: .4byte gUnk_Banim_02000000
.L08044D90:
	ldr r0, .L08044DEC @ =gUnk_Banim_02000000
	ldr r1, [r0]
	str r1, [r6, #0x5c]
	ldr r0, [r0, #8]
.L08044D98:
	str r0, [r6, #0x60]
	ldr r4, .L08044DF0 @ =0x0203CD46
	ldr r0, [r6, #0x60]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r5, [r0, r1]
	adds r4, r5, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [r6, #0x60]
	bl sub_804B6C4
	lsls r5, r5, #1
	adds r5, r5, r0
	adds r0, r5, #0
	bl sub_804A5A8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r6, #0x4c]
	ldr r0, [r6, #0x60]
	bl sub_804B6C4
	lsls r4, r4, #0x10
	asrs r4, r4, #0xf
	adds r4, r4, r0
	adds r0, r4, #0
	bl sub_804A5A8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r6, #0x50]
	ldr r1, [r6, #0x4c]
	cmp r1, r0
	ble .L08044DF4
	movs r0, #1
	rsbs r0, r0, #0
	b .L08044DF6
	.align 2, 0
.L08044DEC: .4byte gUnk_Banim_02000000
.L08044DF0: .4byte 0x0203CD46
.L08044DF4:
	movs r0, #1
.L08044DF6:
	str r0, [r6, #0x48]
	adds r0, r6, #0
	adds r0, #0x29
	movs r1, #0
	strb r1, [r0]
	strh r1, [r6, #0x2c]
	ldr r0, [r6, #0x4c]
	strh r0, [r6, #0x2e]
	str r1, [r6, #0x54]
	str r1, [r6, #0x58]
	ldr r0, .L08044E24 @ =gUnk_Banim_02017748
	str r1, [r0]
	ldr r0, [r6, #0x60]
	bl sub_804B6C4
	ldr r1, .L08044E28 @ =gUnk_Banim_02017778
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
.L08044E1E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08044E24: .4byte gUnk_Banim_02017748
.L08044E28: .4byte gUnk_Banim_02017778

	thumb_func_start sub_8044E2C
sub_8044E2C: @ 0x08044E2C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	ldr r1, [r5, #0x58]
	cmp r1, #0
	bne .L08044E7C
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne .L08044E7C
	strh r1, [r5, #0x2c]
	ldr r0, [r5, #0x48]
	ldrh r1, [r5, #0x2e]
	adds r0, r1, r0
	strh r0, [r5, #0x2e]
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	ldr r1, .L08044EC8 @ =0x0203CDA0
	lsls r0, r0, #1
	adds r0, r0, r1
	ldr r1, [r5, #0x48]
	ldrh r2, [r0]
	adds r1, r2, r1
	strh r1, [r0]
	movs r0, #0x2e
	ldrsh r1, [r5, r0]
	ldr r0, [r5, #0x50]
	cmp r1, r0
	bne .L08044E7C
	movs r0, #1
	str r0, [r5, #0x58]
.L08044E7C:
	ldr r0, [r5, #0x54]
	cmp r0, #0x54
	bne .L08044ED8
	ldr r6, [r5, #0x58]
	cmp r6, #1
	bne .L08044ED8
	ldr r4, .L08044ECC @ =0x0203CD46
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r1, #1
	movs r4, #0
	strh r1, [r0]
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	ldr r1, .L08044ED0 @ =gUnk_Banim_02017778
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	ldr r0, [r5, #0x50]
	cmp r0, #0
	bne .L08044EB6
	adds r0, r5, #0
	adds r0, #0x29
	strb r6, [r0]
.L08044EB6:
	strh r4, [r5, #0x2c]
	movs r0, #0xa
	strh r0, [r5, #0x2e]
	ldr r0, .L08044ED4 @ =gUnk_Banim_02017748
	str r6, [r0]
	adds r0, r5, #0
	bl Proc_Break
	b .L08044EE4
	.align 2, 0
.L08044EC8: .4byte 0x0203CDA0
.L08044ECC: .4byte 0x0203CD46
.L08044ED0: .4byte gUnk_Banim_02017778
.L08044ED4: .4byte gUnk_Banim_02017748
.L08044ED8:
	adds r0, #1
	str r0, [r5, #0x54]
	cmp r0, #0x53
	bls .L08044EE4
	movs r0, #0x54
	str r0, [r5, #0x54]
.L08044EE4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8044EEC
sub_8044EEC: @ 0x08044EEC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r6, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08044F86
	ldr r4, .L08044F68 @ =0x0203CD46
	ldr r0, [r6, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r5, [r0, r1]
	adds r4, r5, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [r6, #0x5c]
	bl sub_804B6C4
	lsls r5, r5, #1
	adds r5, r5, r0
	adds r0, r5, #0
	bl sub_804A5A8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r6, #0x4c]
	ldr r0, [r6, #0x5c]
	bl sub_804B6C4
	lsls r4, r4, #0x10
	asrs r4, r4, #0xf
	adds r4, r4, r0
	adds r0, r4, #0
	bl sub_804A5A8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r6, #0x50]
	strh r7, [r6, #0x2c]
	ldr r1, [r6, #0x4c]
	strh r1, [r6, #0x2e]
	str r7, [r6, #0x54]
	str r7, [r6, #0x58]
	cmp r1, r0
	bne .L08044F58
	movs r0, #1
	str r0, [r6, #0x58]
.L08044F58:
	ldr r1, [r6, #0x4c]
	ldr r0, [r6, #0x50]
	cmp r1, r0
	ble .L08044F6C
	movs r0, #1
	rsbs r0, r0, #0
	b .L08044F6E
	.align 2, 0
.L08044F68: .4byte 0x0203CD46
.L08044F6C:
	movs r0, #1
.L08044F6E:
	str r0, [r6, #0x48]
	adds r0, r6, #0
	bl Proc_Break
	ldr r0, [r6, #0x5c]
	bl sub_804B6C4
	ldr r1, .L08044F8C @ =gUnk_Banim_02017778
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #2
	strh r1, [r0]
.L08044F86:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08044F8C: .4byte gUnk_Banim_02017778

	thumb_func_start sub_8044F90
sub_8044F90: @ 0x08044F90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r4, .L08045064 @ =gUnk_Banim_02000000
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r7, [r0]
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r6, [r0]
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	mov r8, r0
	ldr r1, [r5, #0x58]
	cmp r1, #0
	bne .L08045020
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne .L08045020
	strh r1, [r5, #0x2c]
	ldr r0, [r5, #0x48]
	ldrh r1, [r5, #0x2e]
	adds r0, r1, r0
	strh r0, [r5, #0x2e]
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	ldr r1, .L08045068 @ =0x0203CDA0
	lsls r0, r0, #1
	adds r0, r0, r1
	ldr r1, [r5, #0x48]
	ldrh r2, [r0]
	adds r1, r2, r1
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x75
	bl sub_805BCA8
	movs r0, #2
	ldrsh r1, [r7, r0]
	movs r0, #0x75
	movs r2, #1
	bl sub_805BDC0
	movs r2, #0x2e
	ldrsh r1, [r5, r2]
	ldr r0, [r5, #0x50]
	cmp r1, r0
	bne .L08045020
	movs r0, #1
	str r0, [r5, #0x58]
.L08045020:
	ldr r1, [r5, #0x54]
	cmp r1, #0x1e
	bne .L080450C4
	ldr r0, [r5, #0x58]
	cmp r0, #1
	bne .L080450C4
	ldr r4, .L0804506C @ =0x0203CD46
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r1, #1
	movs r4, #0
	strh r1, [r0]
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	ldr r1, .L08045070 @ =gUnk_Banim_02017778
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L080450B8
	bl sub_8042578
	cmp r0, #1
	bne .L08045074
	movs r0, #0
	b .L08045088
	.align 2, 0
.L08045064: .4byte gUnk_Banim_02000000
.L08045068: .4byte 0x0203CDA0
.L0804506C: .4byte 0x0203CD46
.L08045070: .4byte gUnk_Banim_02017778
.L08045074:
	ldr r4, .L08045098 @ =0x0203CD84
	adds r0, r6, #0
	bl sub_804B6C4
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ShouldDisplayDeathQuote
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
.L08045088:
	cmp r0, #1
	bne .L0804509C
	adds r0, r6, #0
	mov r1, r8
	bl sub_80455C0
	b .L080450B8
	.align 2, 0
.L08045098: .4byte 0x0203CD84
.L0804509C:
	bl sub_804C554
	adds r0, r6, #0
	mov r1, r8
	bl sub_80457E8
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	ldr r1, .L080450C0 @ =0x0203CCF8
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
.L080450B8:
	adds r0, r5, #0
	bl Proc_Break
	b .L080450D0
	.align 2, 0
.L080450C0: .4byte 0x0203CCF8
.L080450C4:
	adds r0, r1, #1
	str r0, [r5, #0x54]
	cmp r0, #0x1d
	bls .L080450D0
	movs r0, #0x1e
	str r0, [r5, #0x54]
.L080450D0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80450DC
sub_80450DC: @ 0x080450DC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl sub_80588E0
	adds r7, r0, #0
	ldr r1, .L08045114 @ =gUnk_Banim_02017720
	ldr r5, [r1]
	cmp r5, #0
	bne .L0804517A
	movs r0, #1
	str r0, [r1]
	ldr r0, .L08045118 @ =gUnk_085CB790
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	strh r5, [r4, #0x2c]
	adds r0, r6, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08045120
	ldr r0, .L0804511C @ =gUnk_Banim_02000000
	ldr r1, [r0, #8]
	str r1, [r4, #0x5c]
	ldr r0, [r0]
	b .L08045128
	.align 2, 0
.L08045114: .4byte gUnk_Banim_02017720
.L08045118: .4byte gUnk_085CB790
.L0804511C: .4byte gUnk_Banim_02000000
.L08045120:
	ldr r0, .L08045148 @ =gUnk_Banim_02000000
	ldr r1, [r0]
	str r1, [r4, #0x5c]
	ldr r0, [r0, #8]
.L08045128:
	str r0, [r4, #0x60]
	ldr r0, [r4, #0x60]
	movs r1, #1
	bl sub_8056A18
	str r6, [r4, #0x64]
	adds r4, #0x29
	movs r0, #0
	strb r0, [r4]
	adds r0, r6, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804514C
	movs r0, #0x10
	b .L0804514E
	.align 2, 0
.L08045148: .4byte gUnk_Banim_02000000
.L0804514C:
	movs r0, #0x20
.L0804514E:
	ands r0, r7
	cmp r0, #0
	beq .L08045158
	movs r0, #1
	strb r0, [r4]
.L08045158:
	ldrb r4, [r4]
	cmp r4, #1
	bne .L08045164
	adds r0, r6, #0
	bl sub_805A998
.L08045164:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xd7
	bl sub_805BCA8
	movs r0, #2
	ldrsh r1, [r6, r0]
	movs r0, #0xd7
	movs r2, #1
	bl sub_805BDC0
.L0804517A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_8045180
sub_8045180: @ 0x08045180
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080451C6
	ldr r4, .L080451AC @ =0x0203CD84
	ldr r0, [r5, #0x60]
	bl sub_804B6C4
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #3
	bne .L080451B0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x50
	bne .L080451DA
	b .L080451BE
	.align 2, 0
.L080451AC: .4byte 0x0203CD84
.L080451B0:
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1e
	bne .L080451DA
.L080451BE:
	adds r0, r5, #0
	bl Proc_Break
	b .L080451DA
.L080451C6:
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x50
	bne .L080451DA
	adds r0, r5, #0
	bl Proc_Break
.L080451DA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_80451E0
sub_80451E0: @ 0x080451E0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r1, .L08045210 @ =gUnk_Banim_02017720
	ldr r0, [r1]
	cmp r0, #0
	bne .L080452AC
	movs r0, #1
	str r0, [r1]
	ldr r0, .L08045214 @ =gUnk_085CB7B8
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	adds r0, r7, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804521C
	ldr r0, .L08045218 @ =gUnk_Banim_02000000
	ldr r1, [r0, #8]
	str r1, [r6, #0x5c]
	ldr r0, [r0]
	b .L08045224
	.align 2, 0
.L08045210: .4byte gUnk_Banim_02017720
.L08045214: .4byte gUnk_085CB7B8
.L08045218: .4byte gUnk_Banim_02000000
.L0804521C:
	ldr r0, .L0804527C @ =gUnk_Banim_02000000
	ldr r1, [r0]
	str r1, [r6, #0x5c]
	ldr r0, [r0, #8]
.L08045224:
	str r0, [r6, #0x60]
	ldr r4, .L08045280 @ =0x0203CD46
	ldr r0, [r6, #0x60]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r5, [r0, r1]
	adds r4, r5, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, [r6, #0x60]
	bl sub_804B6C4
	lsls r5, r5, #1
	adds r5, r5, r0
	adds r0, r5, #0
	bl sub_804A5A8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [r6, #0x4c]
	ldr r0, [r6, #0x60]
	bl sub_804B6C4
	lsls r4, r4, #0x10
	asrs r4, r4, #0xf
	adds r4, r4, r0
	adds r0, r4, #0
	bl sub_804A5A8
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	str r1, [r6, #0x50]
	movs r0, #0
	str r0, [r6, #0x54]
	str r0, [r6, #0x58]
	ldr r0, [r6, #0x4c]
	cmp r0, r1
	bne .L08045284
	movs r0, #1
	str r0, [r6, #0x58]
	b .L08045292
	.align 2, 0
.L0804527C: .4byte gUnk_Banim_02000000
.L08045280: .4byte 0x0203CD46
.L08045284:
	cmp r0, r1
	ble .L0804528E
	movs r0, #1
	rsbs r0, r0, #0
	b .L08045290
.L0804528E:
	movs r0, #1
.L08045290:
	str r0, [r6, #0x48]
.L08045292:
	movs r0, #0
	strh r0, [r6, #0x2c]
	ldr r0, [r6, #0x4c]
	strh r0, [r6, #0x2e]
	str r7, [r6, #0x64]
	ldr r0, [r6, #0x5c]
	bl sub_804B6C4
	ldr r1, .L080452B4 @ =gUnk_Banim_02017778
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #2
	strh r1, [r0]
.L080452AC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080452B4: .4byte gUnk_Banim_02017778

	thumb_func_start sub_80452B8
sub_80452B8: @ 0x080452B8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x60]
	ldr r1, [r5, #0x58]
	cmp r1, #0
	bne .L08045314
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne .L08045314
	strh r1, [r5, #0x2c]
	ldr r0, [r5, #0x48]
	ldrh r1, [r5, #0x2e]
	adds r0, r1, r0
	strh r0, [r5, #0x2e]
	adds r0, r6, #0
	bl sub_804B6C4
	ldr r1, .L0804534C @ =0x0203CDA0
	lsls r0, r0, #1
	adds r0, r0, r1
	ldr r1, [r5, #0x48]
	ldrh r2, [r0]
	adds r1, r2, r1
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x75
	bl sub_805BCA8
	movs r0, #2
	ldrsh r1, [r6, r0]
	movs r0, #0x75
	movs r2, #1
	bl sub_805BDC0
	movs r2, #0x2e
	ldrsh r1, [r5, r2]
	ldr r0, [r5, #0x50]
	cmp r1, r0
	bne .L08045314
	movs r0, #1
	str r0, [r5, #0x58]
.L08045314:
	ldr r1, [r5, #0x54]
	cmp r1, #0x1e
	bne .L08045358
	ldr r0, [r5, #0x58]
	cmp r0, #1
	bne .L08045358
	ldr r4, .L08045350 @ =0x0203CD46
	adds r0, r6, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r1, #1
	movs r4, #0
	strh r1, [r0]
	adds r0, r6, #0
	bl sub_804B6C4
	ldr r1, .L08045354 @ =gUnk_Banim_02017778
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	adds r0, r5, #0
	bl Proc_Break
	b .L08045364
	.align 2, 0
.L0804534C: .4byte 0x0203CDA0
.L08045350: .4byte 0x0203CD46
.L08045354: .4byte gUnk_Banim_02017778
.L08045358:
	adds r0, r1, #1
	str r0, [r5, #0x54]
	cmp r0, #0x1d
	bls .L08045364
	movs r0, #0x1e
	str r0, [r5, #0x54]
.L08045364:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804536C
sub_804536C: @ 0x0804536C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r1, .L080453B8 @ =gUnk_Banim_02017720
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080453BC @ =gUnk_085CB7E0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	str r6, [r4, #0x60]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x29
	mov r1, r8
	strb r1, [r0]
	str r5, [r4, #0x64]
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl sub_8056A18
	ldr r0, [r4, #0x5c]
	ldr r1, [r4, #0x60]
	bl sub_8045478
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080453B8: .4byte gUnk_Banim_02017720
.L080453BC: .4byte gUnk_085CB7E0

	thumb_func_start sub_80453C0
sub_80453C0: @ 0x080453C0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r6, r0, #0
	ldr r5, .L08045428 @ =0x0203CD84
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0x66
	beq .L080453EA
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #3
	bne .L08045430
.L080453EA:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	cmp r0, #0x3a
	bne .L0804546C
	ldr r5, .L0804542C @ =0x0203CD46
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08045420
	adds r0, r6, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
.L08045420:
	adds r0, r4, #0
	bl Proc_Break
	b .L0804546C
	.align 2, 0
.L08045428: .4byte 0x0203CD84
.L0804542C: .4byte 0x0203CD46
.L08045430:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	cmp r0, #8
	bne .L0804546C
	ldr r5, .L08045474 @ =0x0203CD46
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08045466
	adds r0, r6, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
.L08045466:
	adds r0, r4, #0
	bl Proc_Break
.L0804546C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08045474: .4byte 0x0203CD46

	thumb_func_start sub_8045478
sub_8045478: @ 0x08045478
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08045498 @ =gUnk_085CB808
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	str r5, [r0, #0x60]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08045498: .4byte gUnk_085CB808

	thumb_func_start sub_804549C
sub_804549C: @ 0x0804549C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, [r7, #0x5c]
	mov r8, r0
	ldr r1, [r7, #0x60]
	mov sb, r1
	ldr r4, .L080454F8 @ =gUnk_08111C44
	movs r2, #0x2c
	ldrsh r0, [r7, r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08045504
	mov r0, r8
	bl sub_804B6C4
	ldr r5, .L080454FC @ =gUnk_Banim_02000020
	lsls r0, r0, #1
	adds r0, r0, r5
	ldr r4, .L08045500 @ =gUnk_Banim_0201E12C
	ldrh r0, [r0]
	ldrh r1, [r4]
	subs r0, r0, r1
	mov r2, r8
	strh r0, [r2, #2]
	ldr r0, [r7, #0x60]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldrh r4, [r4]
	subs r0, r0, r4
	mov r1, sb
	strh r0, [r1, #2]
	adds r0, r7, #0
	bl Proc_Break
	b .L08045564
	.align 2, 0
.L080454F8: .4byte gUnk_08111C44
.L080454FC: .4byte gUnk_Banim_02000020
.L08045500: .4byte gUnk_Banim_0201E12C
.L08045504:
	mov r0, r8
	bl sub_804B6C4
	cmp r0, #1
	bne .L08045520
	movs r2, #0x2c
	ldrsh r0, [r7, r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b .L0804552A
.L08045520:
	movs r1, #0x2c
	ldrsh r0, [r7, r1]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r4, [r0]
.L0804552A:
	ldr r0, [r7, #0x5c]
	bl sub_804B6C4
	ldr r6, .L08045570 @ =gUnk_Banim_02000020
	lsls r0, r0, #1
	adds r0, r0, r6
	ldr r5, .L08045574 @ =gUnk_Banim_0201E12C
	ldr r1, [r5]
	ldrh r0, [r0]
	subs r1, r0, r1
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r1, r4, r1
	mov r2, r8
	strh r1, [r2, #2]
	ldr r0, [r7, #0x60]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r6
	ldr r1, [r5]
	ldrh r0, [r0]
	subs r1, r0, r1
	adds r4, r4, r1
	mov r0, sb
	strh r4, [r0, #2]
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
.L08045564:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08045570: .4byte gUnk_Banim_02000020
.L08045574: .4byte gUnk_Banim_0201E12C

	thumb_func_start sub_8045578
sub_8045578: @ 0x08045578
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, .L0804559C @ =gUnk_Banim_02017720
	ldr r4, [r1]
	cmp r4, #0
	bne .L08045594
	movs r0, #1
	str r0, [r1]
	ldr r0, .L080455A0 @ =gUnk_085CB820
	movs r1, #3
	bl SpawnProc
	strh r4, [r0, #0x2c]
	str r5, [r0, #0x64]
.L08045594:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804559C: .4byte gUnk_Banim_02017720
.L080455A0: .4byte gUnk_085CB820

	thumb_func_start sub_80455A4
sub_80455A4: @ 0x080455A4
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x11
	bne .L080455BC
	adds r0, r1, #0
	bl Proc_Break
.L080455BC:
	pop {r0}
	bx r0

	thumb_func_start sub_80455C0
sub_80455C0: @ 0x080455C0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08045604 @ =gUnk_085CB850
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x5c]
	str r5, [r6, #0x60]
	ldr r1, .L08045608 @ =gUnk_Banim_02017730
	movs r0, #1
	str r0, [r1]
	bl sub_8058998
	cmp r0, #0
	beq .L080455FC
	ldr r0, [r6, #0x5c]
	bl sub_805A77C
	str r0, [r6, #0x64]
	ldr r2, .L0804560C @ =gUnk_Banim_02000028
	ldr r1, .L08045610 @ =gUnk_Banim_0201E12C
	ldr r1, [r1]
	subs r1, #0x4e
	ldrh r2, [r2]
	subs r1, r2, r1
	strh r1, [r0, #0x32]
	movs r1, #0xb2
	strh r1, [r0, #0x3a]
.L080455FC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08045604: .4byte gUnk_085CB850
.L08045608: .4byte gUnk_Banim_02017730
.L0804560C: .4byte gUnk_Banim_02000028
.L08045610: .4byte gUnk_Banim_0201E12C

	thumb_func_start sub_8045614
sub_8045614: @ 0x08045614
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl sub_804B80C
	adds r7, r0, #0
	movs r6, #0
	ldr r0, .L08045680 @ =gUnk_Banim_02017744
	ldr r0, [r0]
	cmp r0, #0
	bne .L08045646
	ldr r0, .L08045684 @ =gUnk_Banim_02017724
	ldr r0, [r0]
	cmp r0, #0
	bne .L08045646
	ldr r4, .L08045688 @ =gUnk_Banim_0201E124
	adds r0, r7, #0
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, #1
	bne .L08045646
	movs r6, #1
.L08045646:
	cmp r6, #1
	bne .L0804567A
	movs r0, #7
	strh r0, [r5, #0x2c]
	ldr r0, .L0804568C @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08045674
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	ldr r1, .L08045690 @ =gUnk_Banim_0201773C
	ldr r1, [r1]
	cmp r0, r1
	beq .L08045674
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r7, #0
	bl sub_8045C90
	movs r0, #0
	strh r0, [r5, #0x2c]
.L08045674:
	adds r0, r5, #0
	bl Proc_Break
.L0804567A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08045680: .4byte gUnk_Banim_02017744
.L08045684: .4byte gUnk_Banim_02017724
.L08045688: .4byte gUnk_Banim_0201E124
.L0804568C: .4byte 0x0203CD14
.L08045690: .4byte gUnk_Banim_0201773C

	thumb_func_start sub_8045694
sub_8045694: @ 0x08045694
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	bne .L080456BE
	movs r0, #1
	movs r1, #7
	bl sub_8048DA4
	movs r0, #1
	movs r1, #7
	movs r2, #0
	bl sub_8048E88
	adds r0, r4, #0
	bl Proc_Break
.L080456BE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_80456C4
sub_80456C4: @ 0x080456C4
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl sub_8048DF4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08045734
	bl sub_8043960
	bl sub_8044264
	movs r0, #0
	str r0, [sp]
	ldr r1, .L0804573C @ =gBg0Tm
	ldr r2, .L08045740 @ =0x01000200
	mov r0, sp
	bl CpuFastSet
	ldr r0, .L08045744 @ =gUnk_Banim_02000030
	ldrh r1, [r0]
	ldrh r2, [r0, #2]
	movs r0, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	bl EnableBgSync
	bl sub_80438D8
	ldr r5, .L08045748 @ =0x0203CD84
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0x66
	bne .L08045720
	bl sub_805AFD4
.L08045720:
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	adds r0, r0, r5
	ldrb r0, [r0]
	bl sub_806B808
	adds r0, r4, #0
	bl Proc_Break
.L08045734:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804573C: .4byte gBg0Tm
.L08045740: .4byte 0x01000200
.L08045744: .4byte gUnk_Banim_02000030
.L08045748: .4byte 0x0203CD84

	thumb_func_start sub_804574C
sub_804574C: @ 0x0804574C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl IsEventRunning
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
	cmp r5, #0
	bne .L080457A4
	bl sub_804C554
	ldr r0, [r4, #0x5c]
	ldr r1, [r4, #0x60]
	bl sub_80457E8
	bl sub_8044608
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	ldr r1, .L080457AC @ =0x0203CCF8
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r5, [r0]
	movs r0, #1
	bl EnableBgSync
	movs r0, #0
	movs r1, #7
	bl sub_8048DA4
	movs r0, #0
	movs r1, #7
	movs r2, #0
	bl sub_8048E88
	bl sub_8043970
	bl sub_8044274
	bl sub_80438C8
	adds r0, r4, #0
	bl Proc_Break
.L080457A4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080457AC: .4byte 0x0203CCF8

	thumb_func_start sub_80457B0
sub_80457B0: @ 0x080457B0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x64]
	bl sub_8048DF4
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	cmp r4, #1
	bne .L080457DC
	ldr r0, .L080457E4 @ =gUnk_Banim_02017730
	movs r1, #0
	str r1, [r0]
	bl sub_8058998
	cmp r0, #0
	beq .L080457D6
	adds r0, r6, #0
	adds r0, #0x29
	strb r4, [r0]
.L080457D6:
	adds r0, r5, #0
	bl Proc_Break
.L080457DC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080457E4: .4byte gUnk_Banim_02017730

	thumb_func_start sub_80457E8
sub_80457E8: @ 0x080457E8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L0804581C @ =gUnk_Banim_02017720
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r1, .L08045820 @ =gUnk_Banim_0201772C
	movs r0, #1
	str r0, [r1]
	ldr r0, .L08045824 @ =gUnk_085CB888
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	str r5, [r0, #0x60]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	adds r0, r4, #0
	bl sub_8046ED8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804581C: .4byte gUnk_Banim_02017720
.L08045820: .4byte gUnk_Banim_0201772C
.L08045824: .4byte gUnk_085CB888

	thumb_func_start sub_8045828
sub_8045828: @ 0x08045828
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl sub_80588E0
	adds r4, r0, #0
	ldr r6, [r5, #0x5c]
	ldr r7, [r5, #0x60]
	adds r0, r6, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08045844
	movs r0, #0x15
	b .L08045846
.L08045844:
	movs r0, #0x2a
.L08045846:
	ands r4, r0
	ldr r0, .L0804587C @ =gUnk_Banim_02017744
	ldr r0, [r0]
	cmp r0, #0
	bne .L080458BA
	ldr r0, .L08045880 @ =gUnk_Banim_02017724
	ldr r0, [r0]
	cmp r0, #0
	bne .L080458BA
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq .L08045884
	movs r1, #2
	ldrh r0, [r6]
	orrs r0, r1
	strh r0, [r6]
	ldrh r0, [r7]
	orrs r0, r1
	strh r0, [r7]
	ldr r0, [r5, #0x5c]
	bl sub_8058A1C
	bl sub_8058D34
	b .L0804589C
	.align 2, 0
.L0804587C: .4byte gUnk_Banim_02017744
.L08045880: .4byte gUnk_Banim_02017724
.L08045884:
	movs r0, #0x30
	ands r0, r4
	cmp r0, #0
	bne .L0804589C
	movs r0, #0xc
	ands r0, r4
	cmp r0, #0
	beq .L080458A8
	ldr r0, [r5, #0x5c]
	ldr r1, [r5, #0x60]
	bl sub_8045974
.L0804589C:
	ldr r0, [r5, #0x5c]
	bl sub_8058A08
	movs r1, #1
	strh r1, [r0]
	b .L080458B0
.L080458A8:
	ldr r0, [r5, #0x5c]
	ldr r1, [r5, #0x60]
	bl sub_8045974
.L080458B0:
	movs r0, #0x32
	strh r0, [r5, #0x2e]
	adds r0, r5, #0
	bl Proc_Break
.L080458BA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_80458C0
sub_80458C0: @ 0x080458C0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl sub_80588E0
	adds r5, r0, #0
	ldr r6, [r4, #0x5c]
	adds r0, r6, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L080458DA
	movs r0, #0x15
	b .L080458DC
.L080458DA:
	movs r0, #0x2a
.L080458DC:
	ands r5, r0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0x1e
	bne .L0804594A
	movs r0, #3
	ands r0, r5
	cmp r0, #0
	beq .L08045918
	ldr r0, [r4, #0x5c]
	ldr r1, [r4, #0x60]
	bl sub_8045B24
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xd6
	bl sub_805BCA8
	movs r0, #2
	ldrsh r1, [r6, r0]
	movs r0, #0xd6
	movs r2, #1
	bl sub_805BDC0
	movs r0, #0x64
	strh r0, [r4, #0x2e]
	b .L08045966
.L08045918:
	movs r0, #0x30
	ands r0, r5
	cmp r0, #0
	beq .L08045926
	movs r0, #0x1f
	strh r0, [r4, #0x2e]
	b .L08045966
.L08045926:
	ldr r0, [r4, #0x5c]
	ldr r1, [r4, #0x60]
	bl sub_80459F8
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xd6
	bl sub_805BCA8
	movs r2, #2
	ldrsh r1, [r6, r2]
	movs r0, #0xd6
	movs r2, #1
	bl sub_805BDC0
	movs r0, #0x32
	strh r0, [r4, #0x2e]
	b .L08045966
.L0804594A:
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne .L08045966
	ldr r1, .L0804596C @ =gUnk_Banim_02017720
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r1, .L08045970 @ =gUnk_Banim_0201772C
	movs r0, #0
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08045966:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804596C: .4byte gUnk_Banim_02017720
.L08045970: .4byte gUnk_Banim_0201772C

	thumb_func_start sub_8045974
sub_8045974: @ 0x08045974
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08045994 @ =gUnk_085CB8A8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	str r5, [r0, #0x60]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08045994: .4byte gUnk_085CB8A8

	thumb_func_start sub_8045998
sub_8045998: @ 0x08045998
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x5c]
	ldr r4, [r2, #0x60]
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	ble .L080459D0
	ldr r1, .L080459CC @ =0x0000FFFD
	adds r0, r1, #0
	ldrh r5, [r3]
	ands r0, r5
	strh r0, [r3]
	ldrh r0, [r4]
	ands r1, r0
	strh r1, [r4]
	movs r0, #0
	strh r0, [r2, #0x2c]
	ldrh r0, [r2, #0x2e]
	adds r0, #1
	strh r0, [r2, #0x2e]
	b .L080459DE
	.align 2, 0
.L080459CC: .4byte 0x0000FFFD
.L080459D0:
	movs r0, #2
	ldrh r1, [r3]
	orrs r1, r0
	strh r1, [r3]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
.L080459DE:
	movs r5, #0x2e
	ldrsh r0, [r2, r5]
	cmp r0, #5
	ble .L080459F2
	movs r0, #0
	strh r0, [r2, #0x2c]
	strh r0, [r2, #0x2e]
	adds r0, r2, #0
	bl Proc_Break
.L080459F2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_80459F8
sub_80459F8: @ 0x080459F8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08045A60 @ =gUnk_085CB8C0
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	str r5, [r0, #0x60]
	movs r6, #0
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	movs r0, #0xa
	strh r0, [r4, #0xa]
	strh r0, [r5, #0xa]
	bl BasSort
	ldr r2, .L08045A64 @ =gDispIo
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x44
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r6, [r0]
	ldr r0, .L08045A68 @ =0x0000FFE0
	ldrh r1, [r2, #0x3c]
	ands r0, r1
	ldr r1, .L08045A6C @ =0x0000E0FF
	ands r0, r1
	movs r3, #0xc0
	lsls r3, r3, #4
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
.L08045A60: .4byte gUnk_085CB8C0
.L08045A64: .4byte gDispIo
.L08045A68: .4byte 0x0000FFE0
.L08045A6C: .4byte 0x0000E0FF

	thumb_func_start sub_8045A70
sub_8045A70: @ 0x08045A70
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r2, [r4, #0x5c]
	ldr r3, [r4, #0x60]
	ldr r0, [r2, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r2, #0x1c]
	ldr r0, [r3, #0x1c]
	orrs r0, r1
	str r0, [r3, #0x1c]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3c
	ble .L08045AE4
	movs r0, #2
	ldrh r1, [r2]
	orrs r1, r0
	strh r1, [r2]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r0, [r2, #0x1c]
	ldr r1, .L08045ADC @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r2, #0x1c]
	ldr r0, [r3, #0x1c]
	ands r0, r1
	str r0, [r3, #0x1c]
	ldr r2, .L08045AE0 @ =gDispIo
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r1, #8
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x45
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, r4, #0
	bl Proc_Break
	b .L08045B16
	.align 2, 0
.L08045ADC: .4byte 0xFFFFFBFF
.L08045AE0: .4byte gDispIo
.L08045AE4:
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r0, #0x3c
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	ldr r3, .L08045B20 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r1, #0x3f
	ldrb r4, [r2]
	ands r1, r4
	strb r1, [r2]
	adds r1, r3, #0
	adds r1, #0x44
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r5, [r0]
.L08045B16:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08045B20: .4byte gDispIo

	thumb_func_start sub_8045B24
sub_8045B24: @ 0x08045B24
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08045BE8 @ =gUnk_085CB8D8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	str r5, [r0, #0x60]
	movs r2, #2
	movs r6, #0
	movs r3, #0
	ldrh r1, [r4]
	orrs r1, r2
	strh r1, [r4]
	ldrh r1, [r5]
	orrs r2, r1
	strh r2, [r5]
	strh r3, [r0, #0x2c]
	strh r3, [r0, #0x2e]
	ldr r0, [r0, #0x5c]
	bl sub_8058A34
	ldr r5, .L08045BEC @ =gDispIo
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
	movs r4, #0x10
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, .L08045BF0 @ =0x0000FFE0
	ldrh r2, [r5, #0x3c]
	ands r0, r2
	movs r1, #8
	orrs r0, r1
	ldr r1, .L08045BF4 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #0x3c]
	movs r2, #0x20
	ldrb r0, [r5, #1]
	orrs r0, r2
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r5, #1]
	adds r0, r5, #0
	adds r0, #0x2d
	strb r6, [r0]
	adds r0, #4
	strb r6, [r0]
	adds r1, r5, #0
	adds r1, #0x2c
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xa0
	strb r0, [r1]
	adds r3, r5, #0
	adds r3, #0x34
	movs r0, #1
	ldrb r1, [r3]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	orrs r0, r4
	orrs r0, r2
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x3d
	ldrb r1, [r0]
	orrs r2, r1
	strb r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08045BE8: .4byte gUnk_085CB8D8
.L08045BEC: .4byte gDispIo
.L08045BF0: .4byte 0x0000FFE0
.L08045BF4: .4byte 0x0000E0FF

	thumb_func_start sub_8045BF8
sub_8045BF8: @ 0x08045BF8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3c
	ble .L08045C4C
	ldr r0, .L08045C44 @ =gBg3Tm
	movs r1, #0xf0
	lsls r1, r1, #8
	bl TmFill
	movs r0, #8
	bl EnableBgSync
	ldr r2, .L08045C48 @ =gDispIo
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r1, #8
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x45
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, r4, #0
	bl Proc_Break
	b .L08045C84
	.align 2, 0
.L08045C44: .4byte gBg3Tm
.L08045C48: .4byte gDispIo
.L08045C4C:
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r0, #0x3c
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	ldr r1, .L08045C8C @ =gDispIo
	mov ip, r1
	mov r3, ip
	adds r3, #0x3c
	movs r1, #0x3f
	ldrb r2, [r3]
	ands r1, r2
	movs r2, #0x40
	orrs r1, r2
	strb r1, [r3]
	mov r1, ip
	adds r1, #0x44
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x10
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x46
	strb r5, [r0]
.L08045C84:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08045C8C: .4byte gDispIo

	thumb_func_start sub_8045C90
sub_8045C90: @ 0x08045C90
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r0, .L08045CAC @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bhi .L08045D5C
	lsls r0, r0, #2
	ldr r1, .L08045CB0 @ =.L08045CB4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08045CAC: .4byte 0x0203CD14
.L08045CB0: .4byte .L08045CB4
.L08045CB4: @ jump table
	.4byte .L08045D5C @ case 0
	.4byte .L08045CC8 @ case 1
	.4byte .L08045CC8 @ case 2
	.4byte .L08045D5C @ case 3
	.4byte .L08045D5C @ case 4
.L08045CC8:
	ldr r0, .L08045CFC @ =gUnk_085CB8F0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	adds r0, r5, #0
	bl sub_804B6C4
	adds r2, r4, #0
	adds r2, #0x29
	movs r1, #0
	strb r0, [r2]
	strh r1, [r4, #0x2c]
	lsls r1, r6, #0x10
	asrs r2, r1, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	beq .L08045D04
	asrs r0, r1, #0x11
	strh r0, [r4, #0x2e]
	subs r0, r2, r0
	strh r0, [r4, #0x30]
	ldr r2, .L08045D00 @ =0x0203CD14
	b .L08045D1E
	.align 2, 0
.L08045CFC: .4byte gUnk_085CB8F0
.L08045D00: .4byte 0x0203CD14
.L08045D04:
	ldr r0, .L08045D14 @ =0x0203CD14
	adds r2, r0, #0
	ldrh r0, [r2]
	cmp r0, #1
	bne .L08045D18
	movs r0, #5
	b .L08045D1A
	.align 2, 0
.L08045D14: .4byte 0x0203CD14
.L08045D18:
	movs r0, #7
.L08045D1A:
	strh r0, [r4, #0x2e]
	strh r0, [r4, #0x30]
.L08045D1E:
	movs r1, #0xf0
	ldrh r2, [r2]
	cmp r2, #1
	bne .L08045D28
	movs r1, #0x20
.L08045D28:
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r2, [r0]
	cmp r2, #0
	bne .L08045D40
	rsbs r0, r1, #0
	strh r0, [r4, #0x32]
	lsrs r0, r0, #1
	strh r0, [r4, #0x34]
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x38]
	b .L08045D4E
.L08045D40:
	movs r0, #0
	strh r0, [r4, #0x32]
	rsbs r1, r1, #0
	lsrs r0, r1, #1
	strh r0, [r4, #0x34]
	strh r0, [r4, #0x36]
	strh r1, [r4, #0x38]
.L08045D4E:
	ldr r1, .L08045D64 @ =gUnk_Banim_0201E12C
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	str r0, [r1]
	ldr r1, .L08045D68 @ =gUnk_Banim_02017740
	movs r0, #1
	str r0, [r1]
.L08045D5C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08045D64: .4byte gUnk_Banim_0201E12C
.L08045D68: .4byte gUnk_Banim_02017740

	thumb_func_start sub_8045D6C
sub_8045D6C: @ 0x08045D6C
	push {r4, r5, lr}
	ldr r3, .L08045D9C @ =gUnk_Banim_02000000
	ldr r4, [r3]
	rsbs r1, r1, #0
	ldr r2, .L08045DA0 @ =gUnk_Banim_02000020
	ldrh r5, [r2]
	adds r0, r5, r1
	strh r0, [r4, #2]
	ldr r4, [r3, #4]
	ldrh r5, [r2]
	adds r0, r5, r1
	strh r0, [r4, #2]
	ldr r4, [r3, #8]
	ldrh r5, [r2, #2]
	adds r0, r5, r1
	strh r0, [r4, #2]
	ldr r4, [r3, #0xc]
	ldrh r2, [r2, #2]
	adds r1, r2, r1
	strh r1, [r4, #2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08045D9C: .4byte gUnk_Banim_02000000
.L08045DA0: .4byte gUnk_Banim_02000020

	thumb_func_start sub_8045DA4
sub_8045DA4: @ 0x08045DA4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	adds r0, r4, #0
	bl sub_8045D6C
	bl sub_805894C
	cmp r0, #0
	beq .L08045DC2
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	bl sub_8058F60
.L08045DC2:
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	bl sub_8045EE8
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8045DDC
sub_8045DDC: @ 0x08045DDC
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	movs r5, #0x34
	ldrsh r2, [r4, r5]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r5, #0x2e
	ldrsh r0, [r4, r5]
	str r0, [sp]
	movs r0, #1
	bl Interpolate
	adds r1, r0, #0
	ldr r5, .L08045E4C @ =gUnk_Banim_0201E12C
	str r1, [r5]
	adds r0, r4, #0
	bl sub_8045D6C
	bl sub_805894C
	cmp r0, #0
	beq .L08045E14
	ldr r0, [r5]
	bl sub_8058F60
.L08045E14:
	ldr r0, [r5]
	bl sub_8045EE8
	bl sub_804C500
	cmp r0, #0
	beq .L08045E28
	ldr r0, [r5]
	bl sub_804C50C
.L08045E28:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08045E42
	movs r0, #1
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L08045E42:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08045E4C: .4byte gUnk_Banim_0201E12C

	thumb_func_start sub_8045E50
sub_8045E50: @ 0x08045E50
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	movs r5, #0x38
	ldrsh r2, [r4, r5]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r5, #0x30
	ldrsh r0, [r4, r5]
	str r0, [sp]
	movs r0, #4
	bl Interpolate
	adds r1, r0, #0
	ldr r5, .L08045EBC @ =gUnk_Banim_0201E12C
	str r1, [r5]
	adds r0, r4, #0
	bl sub_8045D6C
	bl sub_805894C
	cmp r0, #0
	beq .L08045E88
	ldr r0, [r5]
	bl sub_8058F60
.L08045E88:
	ldr r0, [r5]
	bl sub_8045EE8
	bl sub_804C500
	cmp r0, #0
	beq .L08045E9C
	ldr r0, [r5]
	bl sub_804C50C
.L08045E9C:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08045ED6
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08045EC4
	ldr r1, .L08045EC0 @ =gUnk_Banim_0201773C
	movs r0, #1
	b .L08045EC8
	.align 2, 0
.L08045EBC: .4byte gUnk_Banim_0201E12C
.L08045EC0: .4byte gUnk_Banim_0201773C
.L08045EC4:
	ldr r1, .L08045EE0 @ =gUnk_Banim_0201773C
	movs r0, #0
.L08045EC8:
	str r0, [r1]
	ldr r1, .L08045EE4 @ =gUnk_Banim_02017740
	movs r0, #0
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08045ED6:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08045EE0: .4byte gUnk_Banim_0201773C
.L08045EE4: .4byte gUnk_Banim_02017740

	thumb_func_start sub_8045EE8
sub_8045EE8: @ 0x08045EE8
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	bl sub_8058998
	cmp r0, #0
	bne .L08045F38
	bl sub_804C500
	cmp r0, #0
	bne .L08045F38
	asrs r4, r5, #3
	movs r1, #7
	ands r1, r5
	movs r0, #2
	movs r2, #0
	bl SetBgOffset
	lsls r4, r4, #1
	ldr r0, .L08045F40 @ =gUnk_Banim_0201C8FE
	adds r4, r4, r0
	movs r0, #0x84
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r2, .L08045F44 @ =gBg2Tm
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	subs r0, #0x15
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x42
	movs r3, #0x20
	bl sub_805B20C
	movs r0, #4
	bl EnableBgSync
.L08045F38:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08045F40: .4byte gUnk_Banim_0201C8FE
.L08045F44: .4byte gBg2Tm

	thumb_func_start sub_8045F48
sub_8045F48: @ 0x08045F48
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08045F80 @ =gUnk_085CB918
	movs r1, #3
	bl SpawnProc
	ldr r2, .L08045F84 @ =gUnk_085CB930
	lsls r1, r4, #3
	adds r1, r1, r2
	ldr r1, [r1]
	str r1, [r0, #0x44]
	lsls r4, r4, #1
	adds r4, #1
	lsls r4, r4, #2
	adds r4, r4, r2
	ldr r1, [r4]
	adds r3, r0, #0
	adds r3, #0x29
	movs r2, #0
	strb r1, [r3]
	adds r1, r0, #0
	adds r1, #0x2a
	strb r5, [r1]
	strh r2, [r0, #0x2c]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08045F80: .4byte gUnk_085CB918
.L08045F84: .4byte gUnk_085CB930

	thumb_func_start sub_8045F88
sub_8045F88: @ 0x08045F88
	push {r4, lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x44]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r4, [r0]
	ldr r1, .L08045FB8 @ =0x00007FFF
	cmp r4, r1
	beq .L08045FC0
	ldr r1, .L08045FBC @ =gUnk_Banim_02017758
	strh r4, [r1]
	movs r4, #0x2c
	ldrsh r0, [r2, r4]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	b .L08045FEC
	.align 2, 0
.L08045FB8: .4byte 0x00007FFF
.L08045FBC: .4byte gUnk_Banim_02017758
.L08045FC0:
	adds r0, r2, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	beq .L08045FD0
	cmp r0, #1
	beq .L08045FE4
	b .L08045FEC
.L08045FD0:
	strh r0, [r2, #0x2c]
	ldr r0, .L08045FE0 @ =gUnk_Banim_02017758
	ldrh r1, [r3]
	strh r1, [r0]
	ldrh r1, [r3, #2]
	strh r1, [r0, #2]
	b .L08045FEC
	.align 2, 0
.L08045FE0: .4byte gUnk_Banim_02017758
.L08045FE4:
	ldr r1, .L08045FF4 @ =gUnk_Banim_02017758
	movs r0, #0
	strh r0, [r1, #2]
	strh r0, [r1]
.L08045FEC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08045FF4: .4byte gUnk_Banim_02017758

	thumb_func_start sub_8045FF8
sub_8045FF8: @ 0x08045FF8
	push {lr}
	ldr r0, .L08046008 @ =gUnk_085CB988
	movs r1, #3
	bl SpawnProc
	pop {r1}
	bx r1
	.align 2, 0
.L08046008: .4byte gUnk_085CB988

	thumb_func_start nullsub_21
nullsub_21: @ 0x0804600C
	bx lr
	.align 2, 0

	thumb_func_start sub_8046010
sub_8046010: @ 0x08046010
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08046020 @ =gUnk_Banim_02017740
	ldr r0, [r0]
	cmp r0, #1
	bne .L08046024
	movs r0, #0
	b .L08046100
	.align 2, 0
.L08046020: .4byte gUnk_Banim_02017740
.L08046024:
	ldr r1, .L08046050 @ =gUnk_Banim_02017734
	movs r0, #1
	str r0, [r1]
	ldr r0, .L08046054 @ =gUnk_085CB9A0
	movs r1, #3
	bl SpawnProc
	adds r2, r0, #0
	movs r0, #0
	strh r0, [r2, #0x2c]
	ldr r1, .L08046058 @ =gUnk_Banim_02000000
	ldr r0, [r1]
	str r0, [r2, #0x5c]
	ldr r0, [r1, #8]
	str r0, [r2, #0x60]
	cmp r4, #6
	bhi .L080460EC
	lsls r0, r4, #2
	ldr r1, .L0804605C @ =.L08046060
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08046050: .4byte gUnk_Banim_02017734
.L08046054: .4byte gUnk_085CB9A0
.L08046058: .4byte gUnk_Banim_02000000
.L0804605C: .4byte .L08046060
.L08046060: @ jump table
	.4byte .L0804607C @ case 0
	.4byte .L0804608C @ case 1
	.4byte .L0804609C @ case 2
	.4byte .L080460AC @ case 3
	.4byte .L080460BC @ case 4
	.4byte .L080460CC @ case 5
	.4byte .L080460DC @ case 6
.L0804607C:
	ldr r0, .L08046088 @ =gUnk_08111C60
	str r0, [r2, #0x44]
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #0
	b .L080460F6
	.align 2, 0
.L08046088: .4byte gUnk_08111C60
.L0804608C:
	ldr r0, .L08046098 @ =gUnk_08111C82
	str r0, [r2, #0x44]
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #0
	b .L080460F6
	.align 2, 0
.L08046098: .4byte gUnk_08111C82
.L0804609C:
	ldr r0, .L080460A8 @ =gUnk_08111CCC
	str r0, [r2, #0x44]
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #0
	b .L080460F6
	.align 2, 0
.L080460A8: .4byte gUnk_08111CCC
.L080460AC:
	ldr r0, .L080460B8 @ =gUnk_08111D16
	str r0, [r2, #0x44]
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #0
	b .L080460F6
	.align 2, 0
.L080460B8: .4byte gUnk_08111D16
.L080460BC:
	ldr r0, .L080460C8 @ =gUnk_08111D60
	str r0, [r2, #0x44]
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #0
	b .L080460F6
	.align 2, 0
.L080460C8: .4byte gUnk_08111D60
.L080460CC:
	ldr r0, .L080460D8 @ =gUnk_08111DAA
	str r0, [r2, #0x44]
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #1
	b .L080460F6
	.align 2, 0
.L080460D8: .4byte gUnk_08111DAA
.L080460DC:
	ldr r0, .L080460E8 @ =gUnk_08111E14
	str r0, [r2, #0x44]
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #1
	b .L080460F6
	.align 2, 0
.L080460E8: .4byte gUnk_08111E14
.L080460EC:
	ldr r0, .L08046108 @ =gUnk_08111C60
	str r0, [r2, #0x44]
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #0
.L080460F6:
	strb r0, [r1]
	movs r0, #0
	strh r0, [r2, #0x34]
	strh r0, [r2, #0x3c]
	adds r0, r2, #0
.L08046100:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L08046108: .4byte gUnk_08111C60

	thumb_func_start sub_804610C
sub_804610C: @ 0x0804610C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r3, [r7, #0x44]
	ldrh r4, [r7, #0x2c]
	movs r1, #0x2c
	ldrsh r0, [r7, r1]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r2, [r0]
	ldr r1, .L0804618C @ =0x00007FFF
	cmp r2, r1
	bne .L080461A0
	ldr r3, .L08046190 @ =gUnk_Banim_02000020
	movs r4, #0
	ldrsh r2, [r3, r4]
	ldr r0, .L08046194 @ =gUnk_Banim_0201E12C
	ldr r1, [r0]
	subs r6, r2, r1
	ldr r2, .L08046198 @ =gUnk_Banim_02000024
	movs r4, #2
	ldrsh r0, [r3, r4]
	subs r4, r0, r1
	movs r0, #2
	ldrsh r5, [r2, r0]
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	movs r3, #0
	ldrsh r2, [r2, r3]
	movs r0, #0
	bl sub_8047C88
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r2, r5, #0
	movs r0, #1
	bl sub_8047C88
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	bl sub_805894C
	cmp r0, #0
	beq .L0804617C
	ldrh r1, [r7, #0x34]
	ldrh r2, [r7, #0x3c]
	adds r2, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #3
	bl SetBgOffset
.L0804617C:
	ldr r1, .L0804619C @ =gUnk_Banim_02017734
	movs r0, #0
	str r0, [r1]
	adds r0, r7, #0
	bl Proc_End
	b .L080462B2
	.align 2, 0
.L0804618C: .4byte 0x00007FFF
.L08046190: .4byte gUnk_Banim_02000020
.L08046194: .4byte gUnk_Banim_0201E12C
.L08046198: .4byte gUnk_Banim_02000024
.L0804619C: .4byte gUnk_Banim_02017734
.L080461A0:
	ldr r5, .L080461F8 @ =gUnk_Banim_02017758
	strh r2, [r5]
	movs r1, #0x2c
	ldrsh r0, [r7, r1]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	strh r0, [r5, #2]
	adds r0, r4, #1
	strh r0, [r7, #0x2c]
	ldrh r1, [r5]
	ldrh r2, [r5, #2]
	movs r0, #2
	bl SetBgOffset
	bl sub_805894C
	cmp r0, #0
	beq .L080461E2
	ldrh r2, [r7, #0x34]
	ldrh r3, [r5]
	adds r1, r2, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r4, [r7, #0x3c]
	ldrh r0, [r5, #2]
	adds r2, r4, r0
	adds r2, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #3
	bl SetBgOffset
.L080461E2:
	bl sub_805894C
	cmp r0, #0
	beq .L08046200
	ldr r4, .L080461FC @ =gUnk_Banim_02000020
	movs r2, #0
	ldrsh r1, [r4, r2]
	movs r3, #0
	ldrsh r0, [r5, r3]
	subs r1, r1, r0
	b .L0804620C
	.align 2, 0
.L080461F8: .4byte gUnk_Banim_02017758
.L080461FC: .4byte gUnk_Banim_02000020
.L08046200:
	ldr r4, .L0804626C @ =gUnk_Banim_02000020
	movs r2, #0
	ldrsh r1, [r4, r2]
	movs r3, #0
	ldrsh r0, [r5, r3]
	adds r1, r1, r0
.L0804620C:
	ldr r3, .L08046270 @ =gUnk_Banim_0201E12C
	ldr r0, [r3]
	subs r6, r1, r0
	ldr r2, .L08046274 @ =gUnk_Banim_02000024
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r8, r0
	movs r1, #2
	ldrsh r0, [r5, r1]
	mov r1, r8
	subs r1, r1, r0
	mov r8, r1
	adds r5, r2, #0
	movs r2, #2
	ldrsh r1, [r4, r2]
	ldr r2, .L08046278 @ =gUnk_Banim_02017758
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r1, r1, r0
	ldr r0, [r3]
	subs r4, r1, r0
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	subs r5, r1, r0
	ldr r0, .L0804627C @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08046280
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	mov r3, r8
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	movs r0, #0
	bl sub_8047C88
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl sub_8047C88
	b .L080462B2
	.align 2, 0
.L0804626C: .4byte gUnk_Banim_02000020
.L08046270: .4byte gUnk_Banim_0201E12C
.L08046274: .4byte gUnk_Banim_02000024
.L08046278: .4byte gUnk_Banim_02017758
.L0804627C: .4byte 0x0203CD14
.L08046280:
	cmp r0, #0
	blt .L080462B2
	cmp r0, #2
	bgt .L080462B2
	ldr r0, [r7, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L080462A4
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	mov r4, r8
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	movs r0, #0
	bl sub_8047C88
	b .L080462B2
.L080462A4:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl sub_8047C88
.L080462B2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_80462BC
sub_80462BC: @ 0x080462BC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	mov r8, r1
	adds r6, r2, #0
	ldr r0, .L08046300 @ =gUnk_Banim_02017738
	ldr r7, [r0]
	cmp r7, #0
	beq .L080462D4
	b .L08046446
.L080462D4:
	movs r4, #1
	str r4, [r0]
	ldr r0, .L08046304 @ =gUnk_085CB9B8
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	mov r0, sb
	str r0, [r5, #0x5c]
	mov r1, r8
	str r1, [r5, #0x60]
	strh r7, [r5, #0x2c]
	adds r0, r5, #0
	adds r0, #0x29
	strb r4, [r0]
	cmp r6, #0
	beq .L0804633C
	cmp r6, #1
	bne .L0804630C
	ldr r0, .L08046308 @ =gUnk_08111C82
	b .L0804633E
	.align 2, 0
.L08046300: .4byte gUnk_Banim_02017738
.L08046304: .4byte gUnk_085CB9B8
.L08046308: .4byte gUnk_08111C82
.L0804630C:
	cmp r6, #2
	bne .L08046318
	ldr r0, .L08046314 @ =gUnk_08111CCC
	b .L0804633E
	.align 2, 0
.L08046314: .4byte gUnk_08111CCC
.L08046318:
	cmp r6, #3
	bne .L08046324
	ldr r0, .L08046320 @ =gUnk_08111D16
	b .L0804633E
	.align 2, 0
.L08046320: .4byte gUnk_08111D16
.L08046324:
	cmp r6, #4
	bne .L08046330
	ldr r0, .L0804632C @ =gUnk_08111F30
	b .L0804633E
	.align 2, 0
.L0804632C: .4byte gUnk_08111F30
.L08046330:
	cmp r6, #5
	bne .L0804633C
	ldr r0, .L08046338 @ =gUnk_08111FC6
	b .L0804633E
	.align 2, 0
.L08046338: .4byte gUnk_08111FC6
.L0804633C:
	ldr r0, .L08046354 @ =gUnk_08111C60
.L0804633E:
	str r0, [r5, #0x44]
	movs r0, #1
	str r0, [r5, #0x48]
	bl sub_8058998
	adds r4, r0, #0
	cmp r4, #0
	beq .L08046358
	movs r0, #0
	str r0, [r5, #0x64]
	b .L08046446
	.align 2, 0
.L08046354: .4byte gUnk_08111C60
.L08046358:
	bl sub_804C500
	cmp r0, #0
	beq .L08046364
	str r4, [r5, #0x64]
	b .L08046446
.L08046364:
	ldr r0, .L08046374 @ =0x0203CD14
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L08046378
	str r0, [r5, #0x64]
	b .L08046446
	.align 2, 0
.L08046374: .4byte 0x0203CD14
.L08046378:
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	ldr r1, .L080463A8 @ =gUnk_Banim_0201E12C
	ldr r1, [r1]
	ldr r2, .L080463AC @ =gUnk_Banim_02000028
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov r0, sb
	bl sub_804B6C4
	cmp r0, #0
	bne .L080463B4
	movs r0, #0x40
	strh r0, [r5, #0x36]
	movs r0, #0x68
	strh r0, [r5, #0x3e]
	ldr r0, .L080463B0 @ =gUnk_085CCE38
	b .L080463BE
	.align 2, 0
.L080463A8: .4byte gUnk_Banim_0201E12C
.L080463AC: .4byte gUnk_Banim_02000028
.L080463B0: .4byte gUnk_085CCE38
.L080463B4:
	movs r0, #0xb0
	strh r0, [r5, #0x36]
	movs r0, #0x68
	strh r0, [r5, #0x3e]
	ldr r0, .L080463E4 @ =gUnk_085CCDAC
.L080463BE:
	movs r1, #5
	bl BasCreate
	adds r1, r0, #0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r5, #0x36]
	subs r0, r2, r0
	strh r0, [r1, #2]
	ldrh r0, [r5, #0x3e]
	strh r0, [r1, #4]
	ldr r0, .L080463E8 @ =gUnk_Banim_02017754
	ldr r0, [r0]
	cmp r0, #1
	bne .L080463EC
	movs r0, #0xd3
	lsls r0, r0, #6
	b .L080463F0
	.align 2, 0
.L080463E4: .4byte gUnk_085CCDAC
.L080463E8: .4byte gUnk_Banim_02017754
.L080463EC:
	movs r0, #0xf3
	lsls r0, r0, #6
.L080463F0:
	strh r0, [r1, #8]
	str r1, [r5, #0x64]
	ldr r4, .L08046454 @ =gUnk_Banim_02000034
	mov r0, sb
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r1, .L08046458 @ =0x06011800
	movs r2, #0x80
	lsls r2, r2, #4
	bl RegisterDataMove
	ldr r4, .L0804645C @ =gUnk_Banim_02000044
	mov r0, sb
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r1, .L08046460 @ =gPal+0x260
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	ldr r0, .L08046464 @ =0x0203CD14
	movs r1, #0
	ldrsh r4, [r0, r1]
	mov r0, sb
	bl sub_804B6C4
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_804C478
	ldr r0, .L08046468 @ =gUnk_Banim_0201E12C
	ldr r0, [r0]
	bl sub_8045EE8
.L08046446:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08046454: .4byte gUnk_Banim_02000034
.L08046458: .4byte 0x06011800
.L0804645C: .4byte gUnk_Banim_02000044
.L08046460: .4byte gPal+0x260
.L08046464: .4byte 0x0203CD14
.L08046468: .4byte gUnk_Banim_0201E12C

	thumb_func_start sub_804646C
sub_804646C: @ 0x0804646C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r5, [r6, #0x44]
	movs r1, #0x2c
	ldrsh r0, [r6, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, .L080464B4 @ =0x00007FFF
	ldrh r0, [r0]
	cmp r0, r1
	beq .L0804648A
	b .L08046598
.L0804648A:
	ldr r0, .L080464B8 @ =0x0203CD14
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080464BC
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	bl sub_805894C
	cmp r0, #0
	beq .L080464DE
	movs r0, #3
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
	b .L080464DE
	.align 2, 0
.L080464B4: .4byte 0x00007FFF
.L080464B8: .4byte 0x0203CD14
.L080464BC:
	cmp r0, #0
	blt .L080464DE
	cmp r0, #2
	bgt .L080464DE
	bl sub_805894C
	cmp r0, #0
	beq .L080464D6
	movs r0, #3
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
.L080464D6:
	ldr r0, .L08046580 @ =gUnk_Banim_0201E12C
	ldr r0, [r0]
	bl sub_8045EE8
.L080464DE:
	ldr r0, [r6, #0x64]
	cmp r0, #0
	beq .L080464EE
	bl BasRemove
	ldr r0, .L08046584 @ =gUnk_Banim_0201E0FC
	bl sub_804C330
.L080464EE:
	ldr r3, .L08046588 @ =gUnk_Banim_02000020
	movs r4, #0
	ldrsh r2, [r3, r4]
	ldr r0, .L08046580 @ =gUnk_Banim_0201E12C
	ldr r1, [r0]
	subs r7, r2, r1
	ldr r2, .L0804658C @ =gUnk_Banim_02000024
	movs r5, #2
	ldrsh r0, [r3, r5]
	subs r4, r0, r1
	movs r0, #2
	ldrsh r5, [r2, r0]
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	movs r3, #0
	ldrsh r2, [r2, r3]
	movs r0, #0
	bl sub_8047C88
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	adds r2, r5, #0
	movs r0, #1
	bl sub_8047C88
	ldr r1, .L08046590 @ =gUnk_Banim_02017738
	movs r0, #0
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08046576
	bl sub_805894C
	cmp r0, #0
	beq .L08046542
	movs r0, #3
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
.L08046542:
	ldr r4, .L08046594 @ =gUnk_Banim_02000030
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #0
	bl SetBgOffset
	ldrh r5, [r4]
	rsbs r0, r5, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r4, #2]
	rsbs r1, r2, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_804392C
	ldrh r3, [r4]
	rsbs r0, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r4, #2]
	rsbs r1, r4, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_8044230
.L08046576:
	adds r0, r6, #0
	bl Proc_End
	b .L08046786
	.align 2, 0
.L08046580: .4byte gUnk_Banim_0201E12C
.L08046584: .4byte gUnk_Banim_0201E0FC
.L08046588: .4byte gUnk_Banim_02000020
.L0804658C: .4byte gUnk_Banim_02000024
.L08046590: .4byte gUnk_Banim_02017738
.L08046594: .4byte gUnk_Banim_02000030
.L08046598:
	movs r0, #0x2c
	ldrsh r4, [r6, r0]
	cmp r4, #0
	bne .L080465C4
	ldr r0, [r6, #0x64]
	cmp r0, #0
	beq .L080465C4
	ldr r0, [r6, #0x5c]
	bl sub_804B6C4
	adds r1, r0, #0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	ldr r1, .L0804661C @ =gBg2Tm+0x2C0
	adds r0, r0, r1
	str r4, [sp]
	movs r1, #0xf
	movs r2, #5
	movs r3, #0
	bl sub_805B094
.L080465C4:
	ldr r4, .L08046620 @ =gUnk_Banim_02017758
	movs r1, #0x2c
	ldrsh r0, [r6, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	strh r0, [r4]
	movs r3, #0x2c
	ldrsh r0, [r6, r3]
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r5, #2
	ldrsh r0, [r0, r5]
	strh r0, [r4, #2]
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	ldr r0, [r6, #0x64]
	cmp r0, #0
	beq .L0804662C
	ldr r0, [r6, #0x5c]
	bl sub_804B6C4
	ldr r1, .L08046624 @ =gUnk_Banim_0201E12C
	ldr r1, [r1]
	ldr r2, .L08046628 @ =gUnk_Banim_02000028
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	subs r1, r1, r0
	ldr r2, [r6, #0x64]
	ldrh r3, [r6, #0x36]
	ldrh r5, [r4]
	adds r0, r3, r5
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r6, #0x3e]
	ldrh r4, [r4, #2]
	subs r0, r1, r4
	strh r0, [r2, #4]
	b .L08046636
	.align 2, 0
.L0804661C: .4byte gBg2Tm+0x2C0
.L08046620: .4byte gUnk_Banim_02017758
.L08046624: .4byte gUnk_Banim_0201E12C
.L08046628: .4byte gUnk_Banim_02000028
.L0804662C:
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #2
	bl SetBgOffset
.L08046636:
	adds r0, r6, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08046696
	ldr r5, .L080466CC @ =gUnk_Banim_02017758
	ldr r4, .L080466D0 @ =gUnk_Banim_02000030
	ldrh r2, [r5]
	ldrh r3, [r4]
	adds r1, r2, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r5, #2]
	ldrh r3, [r4, #2]
	adds r2, r0, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	bl SetBgOffset
	ldrh r1, [r5]
	ldrh r2, [r4]
	adds r0, r1, r2
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r5, #2]
	ldrh r2, [r4, #2]
	adds r1, r3, r2
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_804392C
	ldrh r3, [r5]
	ldrh r1, [r4]
	adds r0, r3, r1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r5, [r5, #2]
	ldrh r4, [r4, #2]
	adds r1, r5, r4
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_8044230
.L08046696:
	bl sub_805894C
	cmp r0, #0
	beq .L080466B0
	ldr r0, .L080466CC @ =gUnk_Banim_02017758
	ldrh r1, [r0]
	ldrh r2, [r0, #2]
	adds r2, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #3
	bl SetBgOffset
.L080466B0:
	bl sub_805894C
	cmp r0, #0
	beq .L080466D8
	ldr r2, .L080466D4 @ =gUnk_Banim_02000020
	mov ip, r2
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r2, .L080466CC @ =gUnk_Banim_02017758
	movs r4, #0
	ldrsh r0, [r2, r4]
	subs r1, r1, r0
	b .L080466E8
	.align 2, 0
.L080466CC: .4byte gUnk_Banim_02017758
.L080466D0: .4byte gUnk_Banim_02000030
.L080466D4: .4byte gUnk_Banim_02000020
.L080466D8:
	ldr r0, .L08046740 @ =gUnk_Banim_02000020
	mov ip, r0
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, .L08046744 @ =gUnk_Banim_02017758
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r1, r1, r0
.L080466E8:
	ldr r4, .L08046748 @ =gUnk_Banim_0201E12C
	ldr r0, [r4]
	subs r7, r1, r0
	ldr r3, .L0804674C @ =gUnk_Banim_02000024
	movs r5, #0
	ldrsh r1, [r3, r5]
	movs r5, #2
	ldrsh r0, [r2, r5]
	subs r1, r1, r0
	mov r8, r1
	mov r5, ip
	movs r1, #2
	ldrsh r0, [r5, r1]
	movs r5, #0
	ldrsh r1, [r2, r5]
	adds r0, r0, r1
	ldr r1, [r4]
	subs r4, r0, r1
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	subs r5, r1, r0
	ldr r0, .L08046750 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08046754
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	mov r3, r8
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	movs r0, #0
	bl sub_8047C88
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl sub_8047C88
	b .L08046786
	.align 2, 0
.L08046740: .4byte gUnk_Banim_02000020
.L08046744: .4byte gUnk_Banim_02017758
.L08046748: .4byte gUnk_Banim_0201E12C
.L0804674C: .4byte gUnk_Banim_02000024
.L08046750: .4byte 0x0203CD14
.L08046754:
	cmp r0, #0
	blt .L08046786
	cmp r0, #2
	bgt .L08046786
	ldr r0, [r6, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08046778
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	mov r4, r8
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	movs r0, #0
	bl sub_8047C88
	b .L08046786
.L08046778:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl sub_8047C88
.L08046786:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8046794
sub_8046794: @ 0x08046794
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L080467C4 @ =gUnk_085CB9D0
	movs r1, #0
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp]
	ldr r1, .L080467C8 @ =gUnk_Banim_020165C0
	ldr r2, .L080467CC @ =0x01000100
	mov r0, sp
	bl CpuFastSet
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080467C4: .4byte gUnk_085CB9D0
.L080467C8: .4byte gUnk_Banim_020165C0
.L080467CC: .4byte 0x01000100

	thumb_func_start sub_80467D0
sub_80467D0: @ 0x080467D0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08046800 @ =gUnk_085CB9D0
	movs r1, #0
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	ldr r0, .L08046804 @ =0x001F001F
	str r0, [sp]
	ldr r1, .L08046808 @ =gUnk_Banim_020165C0
	ldr r2, .L0804680C @ =0x01000100
	mov r0, sp
	bl CpuFastSet
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08046800: .4byte gUnk_085CB9D0
.L08046804: .4byte 0x001F001F
.L08046808: .4byte gUnk_Banim_020165C0
.L0804680C: .4byte 0x01000100

	thumb_func_start sub_8046810
sub_8046810: @ 0x08046810
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08046844 @ =gUnk_Banim_020165C0
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	blt .L0804683C
	adds r0, r4, #0
	bl Proc_Break
.L0804683C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08046844: .4byte gUnk_Banim_020165C0

	thumb_func_start sub_8046848
sub_8046848: @ 0x08046848
	push {r4, lr}
	adds r4, r0, #0
	bl EnablePalSync
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_804685C
sub_804685C: @ 0x0804685C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, .L0804687C @ =gUnk_085CB9F8
	movs r1, #0
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r6, [r0, #0x30]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804687C: .4byte gUnk_085CB9F8

	thumb_func_start sub_8046880
sub_8046880: @ 0x08046880
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, .L080468D0 @ =gPal
	ldr r4, .L080468D4 @ =gUnk_Banim_020165C0
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	movs r3, #0x10
	bl sub_805B644
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r0, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r6, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L080468CA
	movs r0, #0
	strh r0, [r6, #0x2c]
	adds r0, r6, #0
	bl Proc_Break
.L080468CA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080468D0: .4byte gPal
.L080468D4: .4byte gUnk_Banim_020165C0

	thumb_func_start sub_80468D8
sub_80468D8: @ 0x080468D8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	movs r1, #0x30
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r6, r0, #0
	ldr r0, .L08046940 @ =gPal
	ldr r4, .L08046944 @ =gUnk_Banim_020165C0
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	adds r3, r6, #0
	bl sub_805B644
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r0, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r7, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08046936
	adds r0, r7, #0
	bl Proc_Break
.L08046936:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08046940: .4byte gPal
.L08046944: .4byte gUnk_Banim_020165C0

	thumb_func_start sub_8046948
sub_8046948: @ 0x08046948
	push {r4, lr}
	adds r4, r0, #0
	bl EnablePalSync
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_804695C
sub_804695C: @ 0x0804695C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L08046990 @ =gUnk_085CBA20
	movs r1, #4
	bl SpawnProc
	adds r1, r0, #0
	str r6, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	strh r4, [r1, #0x2e]
	strh r5, [r1, #0x30]
	cmp r4, #0
	bne .L0804698A
	adds r0, r1, #0
	bl Proc_Break
.L0804698A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08046990: .4byte gUnk_085CBA20

	thumb_func_start sub_8046994
sub_8046994: @ 0x08046994
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r2, #0x2e]
	lsls r1, r3, #0x10
	cmp r0, r1
	blt .L080469AE
	adds r0, r2, #0
	bl Proc_Break
.L080469AE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80469B4
sub_80469B4: @ 0x080469B4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L080469D8
	ldr r0, .L080469D0 @ =gUnk_081134A4
	ldr r1, .L080469D4 @ =gPal+0x360
	movs r2, #0x10
	bl CpuSet
	b .L080469E2
	.align 2, 0
.L080469D0: .4byte gUnk_081134A4
.L080469D4: .4byte gPal+0x360
.L080469D8:
	ldr r0, .L08046A04 @ =gUnk_081134A4
	ldr r1, .L08046A08 @ =gPal+0x380
	movs r2, #0x10
	bl CpuSet
.L080469E2:
	bl EnablePalSync
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	blt .L080469FC
	adds r0, r4, #0
	bl Proc_Break
.L080469FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08046A04: .4byte gUnk_081134A4
.L08046A08: .4byte gPal+0x380

	thumb_func_start sub_8046A0C
sub_8046A0C: @ 0x08046A0C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08046A3C
	ldr r0, .L08046A30 @ =0x0203CD08
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	ldr r1, .L08046A34 @ =gUnk_08113424
	adds r0, r0, r1
	ldr r1, .L08046A38 @ =gPal+0x360
	movs r2, #0x10
	bl CpuSet
	b .L08046A50
	.align 2, 0
.L08046A30: .4byte 0x0203CD08
.L08046A34: .4byte gUnk_08113424
.L08046A38: .4byte gPal+0x360
.L08046A3C:
	ldr r0, .L08046A60 @ =0x0203CD08
	movs r1, #2
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	ldr r1, .L08046A64 @ =gUnk_08113424
	adds r0, r0, r1
	ldr r1, .L08046A68 @ =gPal+0x380
	movs r2, #0x10
	bl CpuSet
.L08046A50:
	bl EnablePalSync
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08046A60: .4byte 0x0203CD08
.L08046A64: .4byte gUnk_08113424
.L08046A68: .4byte gPal+0x380

	thumb_func_start sub_8046A6C
sub_8046A6C: @ 0x08046A6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, .L08046B24 @ =gUnk_Banim_02017774
	ldr r0, .L08046B28 @ =gUnk_085CBA50
	movs r1, #3
	bl SpawnProc
	str r0, [r4]
	str r5, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	str r2, [r0, #0x44]
	ldr r1, .L08046B2C @ =gUnk_081120F8
	str r1, [r0, #0x48]
	str r2, [r0, #0x4c]
	str r2, [r0, #0x50]
	ldr r0, .L08046B30 @ =0x0203CD08
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	ldr r7, .L08046B34 @ =gUnk_08113424
	adds r0, r0, r7
	ldr r6, .L08046B38 @ =gUnk_Banim_0201DF6C
	adds r1, r6, #0
	movs r2, #0x10
	bl sub_805B7F4
	mov r2, r8
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #5
	ldr r2, .L08046B3C @ =gUnk_081134C4
	mov sl, r2
	add r0, sl
	ldr r4, .L08046B40 @ =gUnk_Banim_0201DFCC
	adds r1, r4, #0
	movs r2, #0x10
	bl sub_805B7F4
	ldr r5, .L08046B44 @ =gUnk_Banim_0201E02C
	movs r0, #5
	mov sb, r0
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0x10
	bl sub_805B88C
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	lsls r0, r0, #5
	adds r0, r0, r7
	adds r6, #0x30
	adds r1, r6, #0
	movs r2, #0x10
	bl sub_805B7F4
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	lsls r0, r0, #5
	add r0, sl
	adds r4, #0x30
	adds r1, r4, #0
	movs r2, #0x10
	bl sub_805B7F4
	adds r5, #0x60
	mov r0, sb
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0x10
	bl sub_805B88C
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08046B24: .4byte gUnk_Banim_02017774
.L08046B28: .4byte gUnk_085CBA50
.L08046B2C: .4byte gUnk_081120F8
.L08046B30: .4byte 0x0203CD08
.L08046B34: .4byte gUnk_08113424
.L08046B38: .4byte gUnk_Banim_0201DF6C
.L08046B3C: .4byte gUnk_081134C4
.L08046B40: .4byte gUnk_Banim_0201DFCC
.L08046B44: .4byte gUnk_Banim_0201E02C

	thumb_func_start sub_8046B48
sub_8046B48: @ 0x08046B48
	push {lr}
	ldr r0, .L08046B58 @ =gUnk_Banim_02017774
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L08046B58: .4byte gUnk_Banim_02017774

	thumb_func_start sub_8046B5C
sub_8046B5C: @ 0x08046B5C
	ldr r0, .L08046B68 @ =gUnk_Banim_02017774
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L08046B68: .4byte gUnk_Banim_02017774

	thumb_func_start sub_8046B6C
sub_8046B6C: @ 0x08046B6C
	ldr r0, .L08046B78 @ =gUnk_Banim_02017774
	ldr r1, [r0]
	movs r0, #0
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L08046B78: .4byte gUnk_Banim_02017774

	thumb_func_start sub_8046B7C
sub_8046B7C: @ 0x08046B7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, [r7, #0x50]
	cmp r0, #1
	beq .L08046BF4
	adds r0, r7, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt .L08046BA8
	str r0, [r7, #0x4c]
.L08046BA8:
	ldr r4, .L08046C04 @ =gPal+0x360
	ldr r5, .L08046C08 @ =gUnk_Banim_0201DF6C
	ldr r6, .L08046C0C @ =gUnk_Banim_0201DFCC
	ldr r0, .L08046C10 @ =gUnk_Banim_0201E02C
	mov r8, r0
	movs r0, #0x10
	mov sl, r0
	str r0, [sp]
	ldr r0, [r7, #0x4c]
	str r0, [sp, #4]
	movs r0, #5
	mov sb, r0
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	mov r3, r8
	bl sub_805B90C
	adds r4, #0x20
	adds r5, #0x30
	adds r6, #0x30
	movs r0, #0x60
	add r8, r0
	mov r0, sl
	str r0, [sp]
	ldr r0, [r7, #0x4c]
	str r0, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	mov r3, r8
	bl sub_805B90C
	bl EnablePalSync
.L08046BF4:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08046C04: .4byte gPal+0x360
.L08046C08: .4byte gUnk_Banim_0201DF6C
.L08046C0C: .4byte gUnk_Banim_0201DFCC
.L08046C10: .4byte gUnk_Banim_0201E02C

	thumb_func_start sub_8046C14
sub_8046C14: @ 0x08046C14
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	mov r8, r3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L08046C4C @ =gUnk_085CBA70
	movs r1, #4
	bl SpawnProc
	str r6, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	strh r5, [r0, #0x30]
	adds r0, #0x29
	mov r1, r8
	strb r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08046C4C: .4byte gUnk_085CBA70

	thumb_func_start sub_8046C50
sub_8046C50: @ 0x08046C50
	push {r4, r5, lr}
	adds r4, r0, #0
	bl sub_805894C
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	blt .L08046CF6
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08046CB0
	ldr r0, .L08046CA8 @ =gUnk_08113564
	ldr r1, .L08046CAC @ =gPal+0x2E0
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08046CE0
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L08046C96
	movs r0, #0
	bl sub_8058EC8
.L08046C96:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L08046CE0
	movs r0, #0
	bl sub_8058EC8
	b .L08046CE0
	.align 2, 0
.L08046CA8: .4byte gUnk_08113564
.L08046CAC: .4byte gPal+0x2E0
.L08046CB0:
	ldr r0, .L08046CFC @ =gUnk_08113564
	ldr r1, .L08046D00 @ =gPal+0x320
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08046CE0
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L08046CD2
	movs r0, #1
	bl sub_8058EC8
.L08046CD2:
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq .L08046CE0
	movs r0, #1
	bl sub_8058EC8
.L08046CE0:
	bl EnablePalSync
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0x30
	ldrsh r0, [r4, r2]
	cmp r1, r0
	blt .L08046CF6
	adds r0, r4, #0
	bl Proc_Break
.L08046CF6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08046CFC: .4byte gUnk_08113564
.L08046D00: .4byte gPal+0x320

	thumb_func_start sub_8046D04
sub_8046D04: @ 0x08046D04
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_805894C
	adds r4, r0, #0
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08046D54
	ldr r0, .L08046D4C @ =gUnk_Banim_0200004C
	ldr r0, [r0]
	ldr r1, .L08046D50 @ =gPal+0x2E0
	movs r2, #8
	bl CpuFastSet
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08046D86
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq .L08046D3C
	movs r0, #0
	bl sub_8058E58
.L08046D3C:
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0
	beq .L08046D86
	movs r0, #0
	bl sub_8058E90
	b .L08046D86
	.align 2, 0
.L08046D4C: .4byte gUnk_Banim_0200004C
.L08046D50: .4byte gPal+0x2E0
.L08046D54:
	ldr r0, .L08046D98 @ =gUnk_Banim_0200004C
	ldr r0, [r0, #4]
	ldr r1, .L08046D9C @ =gPal+0x320
	movs r2, #8
	bl CpuFastSet
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08046D86
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq .L08046D78
	movs r0, #1
	bl sub_8058E58
.L08046D78:
	movs r0, #0x20
	ands r0, r4
	cmp r0, #0
	beq .L08046D86
	movs r0, #1
	bl sub_8058E90
.L08046D86:
	bl EnablePalSync
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08046D98: .4byte gUnk_Banim_0200004C
.L08046D9C: .4byte gPal+0x320

	thumb_func_start sub_8046DA0
sub_8046DA0: @ 0x08046DA0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08046DB8
	ldr r0, .L08046DB4 @ =0x0203CD7C
	b .L08046DBA
	.align 2, 0
.L08046DB4: .4byte 0x0203CD7C
.L08046DB8:
	ldr r0, .L08046E40 @ =0x0203CD80
.L08046DBA:
	ldr r6, [r0]
	ldr r0, .L08046E44 @ =gUnk_085CBA98
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	adds r0, #0x29
	movs r1, #0
	strb r1, [r0]
	str r5, [r4, #0x5c]
	strh r1, [r4, #0x2c]
	str r1, [r4, #0x44]
	ldr r0, .L08046E48 @ =gUnk_08112122
	str r0, [r4, #0x48]
	adds r0, r6, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	str r0, [r4, #0x4c]
	ldr r0, .L08046E4C @ =0x0203CCF0
	ldrh r0, [r0]
	cmp r0, #1
	bne .L08046DEC
	str r1, [r4, #0x4c]
.L08046DEC:
	str r1, [r4, #0x50]
	strh r1, [r4, #0x36]
	strh r1, [r4, #0x34]
	strh r1, [r4, #0x32]
	adds r0, r5, #0
	bl sub_804B6C4
	ldr r1, .L08046E50 @ =gUnk_Banim_02017764
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r0]
	adds r0, r5, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08046E5C
	ldr r5, .L08046E54 @ =gUnk_Banim_0200004C
	ldr r0, [r5]
	ldr r4, .L08046E58 @ =gUnk_02021108
	adds r1, r4, #0
	movs r2, #0x10
	bl sub_805B7F4
	ldr r0, [r5]
	adds r5, r4, #0
	adds r5, #0x30
	adds r1, r5, #0
	movs r2, #0x10
	bl sub_805B834
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r0, #0x10
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0x10
	bl sub_805B88C
	b .L08046E8C
	.align 2, 0
.L08046E40: .4byte 0x0203CD80
.L08046E44: .4byte gUnk_085CBA98
.L08046E48: .4byte gUnk_08112122
.L08046E4C: .4byte 0x0203CCF0
.L08046E50: .4byte gUnk_Banim_02017764
.L08046E54: .4byte gUnk_Banim_0200004C
.L08046E58: .4byte gUnk_02021108
.L08046E5C:
	ldr r5, .L08046E94 @ =gUnk_Banim_0200004C
	ldr r0, [r5, #4]
	ldr r4, .L08046E98 @ =gUnk_02021108+0x60
	adds r1, r4, #0
	movs r2, #0x10
	bl sub_805B7F4
	ldr r0, [r5, #4]
	adds r5, r4, #0
	adds r5, #0x30
	adds r1, r5, #0
	movs r2, #0x10
	bl sub_805B834
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r0, #0x10
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0x10
	bl sub_805B88C
.L08046E8C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08046E94: .4byte gUnk_Banim_0200004C
.L08046E98: .4byte gUnk_02021108+0x60

	thumb_func_start sub_8046E9C
sub_8046E9C: @ 0x08046E9C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, .L08046ED4 @ =gUnk_Banim_02017764
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	cmp r0, #0
	beq .L08046ECE
	adds r0, r4, #0
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	bl Proc_End
	adds r0, r4, #0
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #0
	str r1, [r0]
.L08046ECE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08046ED4: .4byte gUnk_Banim_02017764

	thumb_func_start sub_8046ED8
sub_8046ED8: @ 0x08046ED8
	push {r4, lr}
	ldr r4, .L08046EF4 @ =gUnk_Banim_02017764
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	adds r0, #0x29
	movs r1, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08046EF4: .4byte gUnk_Banim_02017764

	thumb_func_start sub_8046EF8
sub_8046EF8: @ 0x08046EF8
	push {r4, lr}
	ldr r4, .L08046F14 @ =gUnk_Banim_02017764
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	adds r0, #0x29
	movs r1, #0
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08046F14: .4byte gUnk_Banim_02017764

	thumb_func_start sub_8046F18
sub_8046F18: @ 0x08046F18
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r4, .L08046F44 @ =gUnk_Banim_02017764
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	str r5, [r0, #0x4c]
	cmp r5, #0
	bne .L08046F3C
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_8046F64
.L08046F3C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08046F44: .4byte gUnk_Banim_02017764

	thumb_func_start sub_8046F48
sub_8046F48: @ 0x08046F48
	push {r4, lr}
	ldr r4, .L08046F60 @ =gUnk_Banim_02017764
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r0, [r0, #0x4c]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L08046F60: .4byte gUnk_Banim_02017764

	thumb_func_start sub_8046F64
sub_8046F64: @ 0x08046F64
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	mov r8, r1
	adds r6, r2, #0
	adds r7, r3, #0
	bl sub_805894C
	adds r5, r0, #0
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08046FE8
	ldr r0, .L08046FDC @ =gUnk_Banim_0200004C
	ldr r0, [r0]
	ldr r4, .L08046FE0 @ =gPal+0x2E0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L08046FE4 @ =0xFFFFFD20
	adds r4, r4, r0
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #1
	mov r3, r8
	bl sub_805B6C8
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L08046FB4
	movs r0, #0
	bl sub_8058E58
.L08046FB4:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L08046FC2
	movs r0, #0
	bl sub_8058E90
.L08046FC2:
	movs r0, #0x11
	ands r0, r5
	cmp r0, #0
	beq .L0804703E
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	movs r1, #6
	movs r2, #1
	mov r3, r8
	bl sub_805B6C8
	b .L0804703E
	.align 2, 0
.L08046FDC: .4byte gUnk_Banim_0200004C
.L08046FE0: .4byte gPal+0x2E0
.L08046FE4: .4byte 0xFFFFFD20
.L08046FE8:
	ldr r0, .L0804704C @ =gUnk_Banim_0200004C
	ldr r0, [r0, #4]
	ldr r4, .L08047050 @ =gPal+0x320
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L08047054 @ =0xFFFFFCE0
	adds r4, r4, r0
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	mov r3, r8
	bl sub_805B6C8
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L08047018
	movs r0, #1
	bl sub_8058E58
.L08047018:
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq .L08047026
	movs r0, #1
	bl sub_8058E90
.L08047026:
	movs r0, #0x22
	ands r0, r5
	cmp r0, #0
	beq .L0804703E
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	mov r3, r8
	bl sub_805B6C8
.L0804703E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804704C: .4byte gUnk_Banim_0200004C
.L08047050: .4byte gPal+0x320
.L08047054: .4byte 0xFFFFFCE0

	thumb_func_start sub_8047058
sub_8047058: @ 0x08047058
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_8046F48
	cmp r0, #0
	beq .L0804714E
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0804714E
	ldr r1, [r4, #0x4c]
	ldr r0, [r4, #0x50]
	cmp r1, r0
	beq .L08047082
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	str r1, [r4, #0x50]
.L08047082:
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L080470D2
	ldr r0, [r4, #0x4c]
	cmp r0, #2
	beq .L080470BA
	cmp r0, #2
	bgt .L080470A8
	cmp r0, #1
	beq .L080470B2
	b .L080470CC
.L080470A8:
	cmp r0, #3
	beq .L080470CC
	cmp r0, #4
	beq .L080470C2
	b .L080470CC
.L080470B2:
	movs r0, #0
	strh r1, [r4, #0x32]
	strh r0, [r4, #0x34]
	b .L080470D0
.L080470BA:
	movs r0, #0
	strh r0, [r4, #0x32]
	strh r0, [r4, #0x34]
	b .L080470D0
.L080470C2:
	movs r0, #0
	strh r1, [r4, #0x32]
	strh r0, [r4, #0x34]
	strh r0, [r4, #0x36]
	b .L080470D2
.L080470CC:
	strh r1, [r4, #0x32]
	strh r1, [r4, #0x34]
.L080470D0:
	strh r1, [r4, #0x36]
.L080470D2:
	ldr r0, [r4, #0x4c]
	cmp r0, #3
	beq .L080470FA
	cmp r0, #3
	bgt .L080470E2
	cmp r0, #1
	blt .L0804714A
	b .L080470E6
.L080470E2:
	cmp r0, #4
	bne .L0804714A
.L080470E6:
	ldr r0, [r4, #0x5c]
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	movs r3, #0x34
	ldrsh r2, [r4, r3]
	movs r5, #0x36
	ldrsh r3, [r4, r5]
	bl sub_8046F64
	b .L0804714A
.L080470FA:
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804712C
	ldr r0, .L08047124 @ =gPal+0x2E0
	ldr r1, .L08047128 @ =gUnk_02021108
	adds r2, r1, #0
	adds r2, #0x30
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r3, r1, r6
	movs r5, #0x10
	str r5, [sp]
	movs r6, #0x32
	ldrsh r4, [r4, r6]
	str r4, [sp, #4]
	str r5, [sp, #8]
	bl sub_805B90C
	b .L0804714A
	.align 2, 0
.L08047124: .4byte gPal+0x2E0
.L08047128: .4byte gUnk_02021108
.L0804712C:
	ldr r0, .L08047158 @ =gPal+0x320
	ldr r1, .L0804715C @ =gUnk_02021108+0x60
	adds r2, r1, #0
	adds r2, #0x30
	movs r5, #0xa8
	lsls r5, r5, #2
	adds r3, r1, r5
	movs r5, #0x10
	str r5, [sp]
	movs r6, #0x32
	ldrsh r4, [r4, r6]
	str r4, [sp, #4]
	str r5, [sp, #8]
	bl sub_805B90C
.L0804714A:
	bl EnablePalSync
.L0804714E:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08047158: .4byte gPal+0x320
.L0804715C: .4byte gUnk_02021108+0x60

	thumb_func_start sub_8047160
sub_8047160: @ 0x08047160
	push {r4, r5, lr}
	adds r4, r0, #0
	bl sub_805894C
	adds r5, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L080471A8
	ldr r0, .L080471A0 @ =gUnk_Banim_0200004C
	ldr r0, [r0]
	ldr r1, .L080471A4 @ =gPal+0x2E0
	movs r2, #8
	bl CpuFastSet
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L0804718E
	movs r0, #0
	bl sub_8058E58
.L0804718E:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L080471D0
	movs r0, #0
	bl sub_8058E90
	b .L080471D0
	.align 2, 0
.L080471A0: .4byte gUnk_Banim_0200004C
.L080471A4: .4byte gPal+0x2E0
.L080471A8:
	ldr r0, .L080471DC @ =gUnk_Banim_0200004C
	ldr r0, [r0, #4]
	ldr r1, .L080471E0 @ =gPal+0x320
	movs r2, #8
	bl CpuFastSet
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L080471C2
	movs r0, #1
	bl sub_8058E58
.L080471C2:
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq .L080471D0
	movs r0, #1
	bl sub_8058E90
.L080471D0:
	bl EnablePalSync
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080471DC: .4byte gUnk_Banim_0200004C
.L080471E0: .4byte gPal+0x320

	thumb_func_start sub_80471E4
sub_80471E4: @ 0x080471E4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L08047220 @ =gUnk_085CBAC0
	movs r1, #3
	bl SpawnProc
	movs r2, #0
	strh r2, [r0, #0x2c]
	str r2, [r0, #0x44]
	ldr r1, .L08047224 @ =gUnk_08112144
	str r1, [r0, #0x48]
	str r2, [r0, #0x4c]
	str r2, [r0, #0x50]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	str r4, [r0, #0x54]
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	str r5, [r0, #0x58]
	ldr r1, .L08047228 @ =gUnk_Banim_0201776C
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08047220: .4byte gUnk_085CBAC0
.L08047224: .4byte gUnk_08112144
.L08047228: .4byte gUnk_Banim_0201776C

	thumb_func_start sub_804722C
sub_804722C: @ 0x0804722C
	push {r4, lr}
	ldr r4, .L08047244 @ =gUnk_Banim_0201776C
	ldr r0, [r4]
	cmp r0, #0
	beq .L0804723E
	bl Proc_End
	movs r0, #0
	str r0, [r4]
.L0804723E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08047244: .4byte gUnk_Banim_0201776C

	thumb_func_start sub_8047248
sub_8047248: @ 0x08047248
	ldr r0, .L08047254 @ =gUnk_Banim_0201776C
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L08047254: .4byte gUnk_Banim_0201776C

	thumb_func_start sub_8047258
sub_8047258: @ 0x08047258
	ldr r0, .L08047264 @ =gUnk_Banim_0201776C
	ldr r1, [r0]
	movs r0, #0
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L08047264: .4byte gUnk_Banim_0201776C

	thumb_func_start sub_8047268
sub_8047268: @ 0x08047268
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	cmp r0, #1
	beq .L080472C6
	bl InitIcons
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt .L0804728E
	str r0, [r4, #0x4c]
.L0804728E:
	ldr r0, [r4, #0x54]
	cmp r0, #0
	beq .L080472A8
	movs r0, #0
	movs r1, #0x1d
	bl ApplyIconPalette
	ldr r0, .L080472CC @ =gPal
	ldr r3, [r4, #0x4c]
	movs r1, #0x1d
	movs r2, #1
	bl sub_805B644
.L080472A8:
	ldr r0, [r4, #0x58]
	cmp r0, #0
	beq .L080472C2
	movs r0, #0
	movs r1, #0x1e
	bl ApplyIconPalette
	ldr r0, .L080472CC @ =gPal
	ldr r3, [r4, #0x4c]
	movs r1, #0x1e
	movs r2, #1
	bl sub_805B644
.L080472C2:
	bl EnablePalSync
.L080472C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080472CC: .4byte gPal

	thumb_func_start sub_80472D0
sub_80472D0: @ 0x080472D0
	push {r4, lr}
	adds r4, r0, #0
	bl InitIcons
	ldr r0, [r4, #0x54]
	cmp r0, #0
	beq .L080472E6
	movs r0, #0
	movs r1, #0x1d
	bl ApplyIconPalette
.L080472E6:
	ldr r0, [r4, #0x58]
	cmp r0, #0
	beq .L080472F4
	movs r0, #0
	movs r1, #0x1e
	bl ApplyIconPalette
.L080472F4:
	bl EnablePalSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8047300
sub_8047300: @ 0x08047300
	push {r4, r5, lr}
	bl sub_805894C
	adds r4, r0, #0
	cmp r4, #0
	bne .L0804734C
	ldr r0, .L08047334 @ =gUnk_085CBAE8
	movs r1, #4
	bl SpawnProc
	adds r5, r0, #0
	adds r0, #0x29
	strb r4, [r0]
	strh r4, [r5, #0x2c]
	movs r0, #4
	strh r0, [r5, #0x2e]
	ldr r0, .L08047338 @ =gUnk_Banim_02017770
	ldr r0, [r0]
	cmp r0, #0
	bne .L08047344
	ldr r0, .L0804733C @ =gPal+0xC0
	ldr r1, .L08047340 @ =gUnk_Banim_0201C77C
	movs r2, #0x50
	bl CpuFastSet
	b .L08047348
	.align 2, 0
.L08047334: .4byte gUnk_085CBAE8
.L08047338: .4byte gUnk_Banim_02017770
.L0804733C: .4byte gPal+0xC0
.L08047340: .4byte gUnk_Banim_0201C77C
.L08047344:
	bl Proc_End
.L08047348:
	ldr r0, .L08047354 @ =gUnk_Banim_02017770
	str r5, [r0]
.L0804734C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08047354: .4byte gUnk_Banim_02017770

	thumb_func_start sub_8047358
sub_8047358: @ 0x08047358
	ldr r0, .L0804736C @ =gUnk_Banim_02017770
	ldr r0, [r0]
	cmp r0, #0
	beq .L08047368
	adds r1, r0, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
.L08047368:
	bx lr
	.align 2, 0
.L0804736C: .4byte gUnk_Banim_02017770

	thumb_func_start sub_8047370
sub_8047370: @ 0x08047370
	push {lr}
	ldr r1, .L08047388 @ =gUnk_Banim_02017770
	ldr r0, [r1]
	cmp r0, #0
	beq .L08047382
	movs r0, #0
	str r0, [r1]
	bl Proc_End
.L08047382:
	pop {r0}
	bx r0
	.align 2, 0
.L08047388: .4byte gUnk_Banim_02017770

	thumb_func_start sub_804738C
sub_804738C: @ 0x0804738C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #8
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L080473E8 @ =gUnk_Banim_0201C77C
	ldr r4, .L080473EC @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #0x50
	bl CpuFastSet
	subs r4, #0xc0
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0xa
	adds r3, r5, #0
	bl sub_805B5C8
	bl EnablePalSync
	ldrh r1, [r6, #0x2c]
	adds r1, #1
	strh r1, [r6, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	adds r0, #1
	cmp r1, r0
	bne .L080473E0
	adds r0, r6, #0
	bl Proc_Break
.L080473E0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080473E8: .4byte gUnk_Banim_0201C77C
.L080473EC: .4byte gPal+0xC0

	thumb_func_start sub_80473F0
sub_80473F0: @ 0x080473F0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08047428 @ =gUnk_Banim_0201C77C
	ldr r4, .L0804742C @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #0x50
	bl CpuFastSet
	subs r4, #0xc0
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0xa
	movs r3, #8
	bl sub_805B5C8
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08047422
	movs r0, #0
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L08047422:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08047428: .4byte gUnk_Banim_0201C77C
.L0804742C: .4byte gPal+0xC0

	thumb_func_start sub_8047430
sub_8047430: @ 0x08047430
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #8
	movs r2, #0
	bl Interpolate
	adds r4, r0, #0
	ldr r7, .L080474A4 @ =gUnk_Banim_0201C77C
	ldr r6, .L080474A8 @ =gPal+0xC0
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0x50
	bl CpuFastSet
	adds r0, r6, #0
	subs r0, #0xc0
	movs r1, #6
	movs r2, #0xa
	adds r3, r4, #0
	bl sub_805B5C8
	bl EnablePalSync
	ldrh r1, [r5, #0x2c]
	adds r1, #1
	strh r1, [r5, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	adds r0, #1
	cmp r1, r0
	bne .L0804749A
	ldr r1, .L080474AC @ =gUnk_Banim_02017770
	movs r0, #0
	str r0, [r1]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0x50
	bl CpuFastSet
	bl EnablePalSync
	adds r0, r5, #0
	bl Proc_Break
.L0804749A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080474A4: .4byte gUnk_Banim_0201C77C
.L080474A8: .4byte gPal+0xC0
.L080474AC: .4byte gUnk_Banim_02017770

	thumb_func_start sub_80474B0
sub_80474B0: @ 0x080474B0
	ldr r1, .L080474B8 @ =gUnk_Banim_02017724
	movs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L080474B8: .4byte gUnk_Banim_02017724

	thumb_func_start sub_80474BC
sub_80474BC: @ 0x080474BC
	ldr r1, .L080474C4 @ =gUnk_Banim_02017724
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
.L080474C4: .4byte gUnk_Banim_02017724

	thumb_func_start sub_80474C8
sub_80474C8: @ 0x080474C8
	push {lr}
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	pop {r0}
	bx r0

	thumb_func_start sub_80474D8
sub_80474D8: @ 0x080474D8
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, .L080474F8 @ =gBg1Tm
	ldr r2, .L080474FC @ =0x01000200
	mov r0, sp
	bl CpuFastSet
	movs r0, #2
	bl EnableBgSync
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
.L080474F8: .4byte gBg1Tm
.L080474FC: .4byte 0x01000200

	thumb_func_start sub_8047500
sub_8047500: @ 0x08047500
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, .L080475CC @ =gDispIo
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
	ldr r0, .L080475D0 @ =0x0000FFE0
	mov r1, ip
	ldrh r1, [r1, #0x3c]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	ldr r1, .L080475D4 @ =0x0000E0FF
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
.L080475CC: .4byte gDispIo
.L080475D0: .4byte 0x0000FFE0
.L080475D4: .4byte 0x0000E0FF

	thumb_func_start sub_80475D8
sub_80475D8: @ 0x080475D8
	ldr r3, .L080475FC @ =gDispIo
	adds r1, r3, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	adds r1, #8
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x45
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	bx lr
	.align 2, 0
.L080475FC: .4byte gDispIo

	thumb_func_start sub_8047600
sub_8047600: @ 0x08047600
	push {lr}
	movs r2, #3
	movs r3, #4
	bl sub_8047620
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8047610
sub_8047610: @ 0x08047610
	push {lr}
	movs r2, #5
	movs r3, #5
	bl sub_8047620
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8047620
sub_8047620: @ 0x08047620
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r1, #0
	str r2, [sp]
	mov sl, r3
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804764C
	ldr r0, .L08047648 @ =gUnk_Banim_02000000
	ldr r7, [r0, #8]
	ldr r1, [r0, #0xc]
	mov sb, r1
	ldr r5, [r0]
	ldr r0, [r0, #4]
	b .L08047658
	.align 2, 0
.L08047648: .4byte gUnk_Banim_02000000
.L0804764C:
	ldr r0, .L08047668 @ =gUnk_Banim_02000000
	ldr r7, [r0]
	ldr r1, [r0, #4]
	mov sb, r1
	ldr r5, [r0, #8]
	ldr r0, [r0, #0xc]
.L08047658:
	mov r8, r0
	cmp r4, #0
	beq .L0804766C
	cmp r4, #1
	bne .L08047664
	b .L08047796
.L08047664:
	b .L0804779C
	.align 2, 0
.L08047668: .4byte gUnk_Banim_02000000
.L0804766C:
	adds r0, r7, #0
	bl sub_804B6C4
	adds r1, r0, #0
	ldrh r0, [r7, #0xe]
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	bl sub_804A57C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r5, #0
	bl sub_804B6C4
	adds r1, r0, #0
	ldrh r0, [r5, #0xe]
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	bl sub_804A57C
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #6
	ands r0, r1
	cmp r0, #0
	beq .L080476BC
	adds r0, r7, #0
	bl sub_8046F48
	cmp r0, #0
	bne .L080476BC
	adds r0, r7, #0
	movs r1, #1
	bl sub_8046F18
.L080476BC:
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #6
	ands r1, r2
	adds r4, r0, #0
	cmp r1, #0
	beq .L080476DE
	adds r0, r5, #0
	bl sub_8046F48
	cmp r0, #0
	bne .L080476DE
	adds r0, r5, #0
	movs r1, #1
	bl sub_8046F18
.L080476DE:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne .L080476F4
	asrs r0, r4, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L080476FC
.L080476F4:
	adds r0, r5, #0
	adds r5, r7, #0
	adds r7, r0, #0
	mov r8, sb
.L080476FC:
	ldr r4, .L08047764 @ =0x0203CD46
	adds r0, r5, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r0, r5, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r4, #1
	adds r0, r5, #0
	bl sub_804B6C4
	adds r1, r0, #0
	lsls r0, r6, #1
	adds r0, r0, r1
	bl sub_804A5A8
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	adds r0, r5, #0
	bl sub_804B6C4
	adds r1, r0, #0
	lsls r0, r4, #1
	adds r0, r0, r1
	bl sub_804A5A8
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r6, r4
	beq .L0804778A
	adds r0, r5, #0
	bl sub_80449F4
	adds r0, r7, #0
	bl sub_804B7B0
	cmp r0, #1
	bne .L08047768
	adds r0, r5, #0
	adds r1, r7, #0
	mov r2, sl
	bl sub_80462BC
	b .L08047772
	.align 2, 0
.L08047764: .4byte 0x0203CD46
.L08047768:
	adds r0, r5, #0
	adds r1, r7, #0
	ldr r2, [sp]
	bl sub_80462BC
.L08047772:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #5
	bl sub_804695C
	adds r0, r5, #0
	movs r1, #0
	movs r2, #8
	movs r3, #0
	bl sub_8046C14
	b .L0804779C
.L0804778A:
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0
	bl sub_804536C
	b .L0804779C
.L08047796:
	adds r0, r5, #0
	bl sub_80450DC
.L0804779C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_80477AC
sub_80477AC: @ 0x080477AC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r1
	bl sub_804B6C4
	cmp r0, #0
	bne .L080477CC
	ldr r0, .L080477C8 @ =gUnk_Banim_02000000
	ldr r7, [r0, #8]
	ldr r5, [r0]
	ldr r0, [r0, #4]
	b .L080477D4
	.align 2, 0
.L080477C8: .4byte gUnk_Banim_02000000
.L080477CC:
	ldr r0, .L0804782C @ =gUnk_Banim_02000000
	ldr r7, [r0]
	ldr r5, [r0, #8]
	ldr r0, [r0, #0xc]
.L080477D4:
	mov r8, r0
	ldr r4, .L08047830 @ =0x0203CD46
	adds r0, r5, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r0, r5, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r4, #1
	adds r0, r5, #0
	bl sub_804B6C4
	adds r1, r0, #0
	lsls r0, r6, #1
	adds r0, r0, r1
	bl sub_804A5A8
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	adds r0, r5, #0
	bl sub_804B6C4
	adds r1, r0, #0
	lsls r0, r4, #1
	adds r0, r0, r1
	bl sub_804A5A8
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	mov r0, sb
	cmp r0, #0
	beq .L08047834
	cmp r0, #1
	beq .L0804788C
	b .L08047892
	.align 2, 0
.L0804782C: .4byte gUnk_Banim_02000000
.L08047830: .4byte 0x0203CD46
.L08047834:
	cmp r6, r4
	beq .L08047876
	adds r0, r5, #0
	bl sub_8044D4C
	adds r0, r7, #0
	bl sub_804B7B0
	cmp r0, #1
	bne .L08047854
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #4
	bl sub_80462BC
	b .L0804785E
.L08047854:
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #3
	bl sub_80462BC
.L0804785E:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #5
	bl sub_804695C
	adds r0, r5, #0
	movs r1, #0
	movs r2, #8
	movs r3, #0
	bl sub_8046C14
	b .L08047892
.L08047876:
	ldr r1, .L08047888 @ =gUnk_Banim_02017748
	movs r0, #2
	str r0, [r1]
	adds r0, r5, #0
	mov r1, r8
	movs r2, #1
	bl sub_804536C
	b .L08047892
	.align 2, 0
.L08047888: .4byte gUnk_Banim_02017748
.L0804788C:
	adds r0, r5, #0
	bl sub_80450DC
.L08047892:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80478A0
sub_80478A0: @ 0x080478A0
	push {r4, lr}
	adds r4, r1, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L080478B8
	ldr r0, .L080478B4 @ =gUnk_Banim_02000000
	ldr r0, [r0]
	b .L080478BC
	.align 2, 0
.L080478B4: .4byte gUnk_Banim_02000000
.L080478B8:
	ldr r0, .L080478C8 @ =gUnk_Banim_02000000
	ldr r0, [r0, #8]
.L080478BC:
	cmp r4, #0
	beq .L080478CC
	cmp r4, #1
	beq .L080478D2
	b .L080478D6
	.align 2, 0
.L080478C8: .4byte gUnk_Banim_02000000
.L080478CC:
	bl sub_8045578
	b .L080478D6
.L080478D2:
	bl sub_80450DC
.L080478D6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_80478DC
sub_80478DC: @ 0x080478DC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r3, #0
	ldr r0, .L08047900 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08047908
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08047904
	adds r0, r7, #0
	b .L08047918
	.align 2, 0
.L08047900: .4byte 0x0203CD14
.L08047904:
	adds r0, r6, #0
	b .L08047918
.L08047908:
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08047916
	adds r0, r5, #0
	b .L08047918
.L08047916:
	ldr r0, [sp, #0x14]
.L08047918:
	movs r1, #0x78
	bl BasCreate
	adds r1, r0, #0
	movs r0, #0xa1
	lsls r0, r0, #6
	strh r0, [r1, #8]
	ldrh r0, [r4, #2]
	strh r0, [r1, #2]
	ldrh r0, [r4, #4]
	strh r0, [r1, #4]
	adds r0, r1, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8047938
sub_8047938: @ 0x08047938
	push {r4, lr}
	sub sp, #8
	adds r3, r0, #0
	ldr r0, .L0804796C @ =0x0203CD14
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r4, r2, #0
	cmp r0, #0
	bne .L0804794C
	adds r4, r1, #0
.L0804794C:
	adds r0, r3, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08047974
	ldr r1, .L08047970 @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl sub_805B1DC
	b .L08047988
	.align 2, 0
.L0804796C: .4byte 0x0203CD14
.L08047970: .4byte gBg1Tm
.L08047974:
	ldr r1, .L08047998 @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl sub_805B1AC
.L08047988:
	movs r0, #2
	bl EnableBgSync
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08047998: .4byte gBg1Tm

	thumb_func_start sub_804799C
sub_804799C: @ 0x0804799C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r0, .L080479B8 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080479C0
	ldr r1, .L080479BC @ =gUnk_Banim_0201977C
	adds r0, r3, #0
	bl LZ77UnCompWram
	b .L080479C8
	.align 2, 0
.L080479B8: .4byte 0x0203CD14
.L080479BC: .4byte gUnk_Banim_0201977C
.L080479C0:
	ldr r1, .L080479EC @ =gUnk_Banim_0201977C
	adds r0, r2, #0
	bl LZ77UnCompWram
.L080479C8:
	ldr r5, .L080479EC @ =gUnk_Banim_0201977C
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L080479F4
	ldr r1, .L080479F0 @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl sub_805B1DC
	b .L08047A08
	.align 2, 0
.L080479EC: .4byte gUnk_Banim_0201977C
.L080479F0: .4byte gBg1Tm
.L080479F4:
	ldr r1, .L08047A18 @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl sub_805B1AC
.L08047A08:
	movs r0, #2
	bl EnableBgSync
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08047A18: .4byte gBg1Tm

	thumb_func_start sub_8047A1C
sub_8047A1C: @ 0x08047A1C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r7, .L08047A54 @ =gUnk_Banim_0201977C
	adds r1, r7, #0
	bl LZ77UnCompWram
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08047A5C
	ldr r1, .L08047A58 @ =gBg1Tm
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r6, #0x10
	lsrs r3, r3, #0x10
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r7, #0
	bl sub_805B1DC
	b .L08047A74
	.align 2, 0
.L08047A54: .4byte gUnk_Banim_0201977C
.L08047A58: .4byte gBg1Tm
.L08047A5C:
	ldr r1, .L08047A84 @ =gBg1Tm
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r6, #0x10
	lsrs r3, r3, #0x10
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r7, #0
	bl sub_805B1AC
.L08047A74:
	movs r0, #2
	bl EnableBgSync
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08047A84: .4byte gBg1Tm

	thumb_func_start sub_8047A88
sub_8047A88: @ 0x08047A88
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	ldr r5, .L08047AA8 @ =0x06010800
	ldr r4, .L08047AAC @ =gUnk_Banim_0201A77C
	adds r1, r4, #0
	bl LZ77UnCompWram
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl RegisterDataMove
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08047AA8: .4byte 0x06010800
.L08047AAC: .4byte gUnk_Banim_0201A77C

	thumb_func_start sub_8047AB0
sub_8047AB0: @ 0x08047AB0
	push {lr}
	adds r2, r1, #0
	ldr r1, .L08047AC8 @ =gPal+0x240
	lsls r2, r2, #9
	lsrs r2, r2, #0xb
	bl CpuFastSet
	bl EnablePalSync
	pop {r0}
	bx r0
	.align 2, 0
.L08047AC8: .4byte gPal+0x240

	thumb_func_start sub_8047ACC
sub_8047ACC: @ 0x08047ACC
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	ldr r5, .L08047AEC @ =0x06002000
	ldr r4, .L08047AF0 @ =gUnk_Banim_0201777C
	adds r1, r4, #0
	bl LZ77UnCompWram
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl RegisterDataMove
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08047AEC: .4byte 0x06002000
.L08047AF0: .4byte gUnk_Banim_0201777C

	thumb_func_start sub_8047AF4
sub_8047AF4: @ 0x08047AF4
	push {lr}
	adds r2, r1, #0
	ldr r1, .L08047B0C @ =gPal+0x20
	lsls r2, r2, #9
	lsrs r2, r2, #0xb
	bl CpuFastSet
	bl EnablePalSync
	pop {r0}
	bx r0
	.align 2, 0
.L08047B0C: .4byte gPal+0x20

	thumb_func_start sub_8047B10
sub_8047B10: @ 0x08047B10
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r3, #0
	ldr r4, [sp, #0x10]
	movs r3, #0
	cmp r3, r4
	bhs .L08047B36
.L08047B1E:
	cmp r2, r5
	blo .L08047B24
	movs r2, #0
.L08047B24:
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	adds r2, #1
	cmp r3, r4
	blo .L08047B1E
.L08047B36:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_8047B3C
sub_8047B3C: @ 0x08047B3C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r3, #0
	ldr r4, [sp, #0x10]
	movs r3, #0
	cmp r3, r4
	bhs .L08047B62
.L08047B4A:
	cmp r2, r5
	blo .L08047B50
	movs r2, #0
.L08047B50:
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	strh r0, [r1, #0x20]
	adds r1, #2
	adds r3, #1
	adds r2, #1
	cmp r3, r4
	blo .L08047B4A
.L08047B62:
	bl EnablePalSync
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_8047B6C
sub_8047B6C: @ 0x08047B6C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r3, #0
	ldr r4, [sp, #0x10]
	movs r3, #0
	cmp r3, r4
	bhs .L08047B98
	movs r0, #0x90
	lsls r0, r0, #2
	adds r1, r1, r0
.L08047B80:
	cmp r2, r5
	blo .L08047B86
	movs r2, #0
.L08047B86:
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	adds r2, #1
	cmp r3, r4
	blo .L08047B80
.L08047B98:
	bl EnablePalSync
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8047BA4
sub_8047BA4: @ 0x08047BA4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	ldrh r0, [r5]
	adds r6, r0, #0
	cmp r6, #0
	bne .L08047C0C
	ldrh r0, [r3]
	mov ip, r0
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r4, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L08047BD0
	movs r0, #4
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08047BD4
.L08047BD0:
	adds r0, r1, #0
	b .L08047C14
.L08047BD4:
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08047BE2
	strh r6, [r3]
	ldrh r4, [r2]
	b .L08047BF6
.L08047BE2:
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08047BF6
	mov r0, ip
	subs r0, #1
	strh r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r4, [r0]
.L08047BF6:
	ldrh r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	adds r1, #1
	strh r1, [r3]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	b .L08047C14
.L08047C0C:
	subs r0, #1
	strh r0, [r5]
	movs r0, #5
	rsbs r0, r0, #0
.L08047C14:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8047C1C
sub_8047C1C: @ 0x08047C1C
	ldr r1, .L08047C24 @ =gUnk_Banim_02017754
	movs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L08047C24: .4byte gUnk_Banim_02017754

	thumb_func_start sub_8047C28
sub_8047C28: @ 0x08047C28
	ldr r0, .L08047C38 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #2
	bne .L08047C3C
	movs r0, #0x18
	b .L08047C46
	.align 2, 0
.L08047C38: .4byte 0x0203CD14
.L08047C3C:
	cmp r0, #1
	beq .L08047C44
	movs r0, #0
	b .L08047C46
.L08047C44:
	movs r0, #0x10
.L08047C46:
	bx lr

	thumb_func_start sub_8047C48
sub_8047C48: @ 0x08047C48
	push {lr}
	sub sp, #4
	ldr r1, .L08047C60 @ =gUnk_Banim_0201C8BC
	str r0, [sp]
	ldr r2, .L08047C64 @ =0x050002D6
	mov r0, sp
	bl CpuSet
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
.L08047C60: .4byte gUnk_Banim_0201C8BC
.L08047C64: .4byte 0x050002D6

	thumb_func_start sub_8047C68
sub_8047C68: @ 0x08047C68
	push {lr}
	sub sp, #4
	ldr r1, .L08047C80 @ =gUnk_Banim_0201D414
	str r0, [sp]
	ldr r2, .L08047C84 @ =0x050002D6
	mov r0, sp
	bl CpuSet
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
.L08047C80: .4byte gUnk_Banim_0201D414
.L08047C84: .4byte 0x050002D6

	thumb_func_start sub_8047C88
sub_8047C88: @ 0x08047C88
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r0, #0
	bne .L08047CA4
	ldr r0, .L08047CA0 @ =gUnk_Banim_02000000
	ldr r3, [r0]
	strh r1, [r3, #2]
	strh r2, [r3, #4]
	ldr r3, [r0, #4]
	b .L08047CAE
	.align 2, 0
.L08047CA0: .4byte gUnk_Banim_02000000
.L08047CA4:
	ldr r0, .L08047CB4 @ =gUnk_Banim_02000000
	ldr r3, [r0, #8]
	strh r1, [r3, #2]
	strh r2, [r3, #4]
	ldr r3, [r0, #0xc]
.L08047CAE:
	strh r1, [r3, #2]
	strh r2, [r3, #4]
	bx lr
	.align 2, 0
.L08047CB4: .4byte gUnk_Banim_02000000

	thumb_func_start sub_8047CB8
sub_8047CB8: @ 0x08047CB8
	push {lr}
	bl sub_8049058
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8047CC8
sub_8047CC8: @ 0x08047CC8
	push {lr}
	bl sub_804C500
	cmp r0, #1
	bne .L08047CD8
	bl sub_804C580
	b .L08047D04
.L08047CD8:
	bl sub_8042584
	bl BasInit
	bl sub_8044870
	ldr r1, .L08047D08 @ =gUnk_Banim_0201773C
	str r0, [r1]
	bl sub_8047DAC
	ldr r1, .L08047D0C @ =gUnk_Banim_02000000
	movs r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	str r0, [r1, #0xc]
	ldr r0, .L08047D10 @ =sub_8047D38
	bl SetMainFunc
	movs r0, #0
	bl SetOnHBlankA
.L08047D04:
	pop {r0}
	bx r0
	.align 2, 0
.L08047D08: .4byte gUnk_Banim_0201773C
.L08047D0C: .4byte gUnk_Banim_02000000
.L08047D10: .4byte sub_8047D38

	thumb_func_start sub_8047D14
sub_8047D14: @ 0x08047D14
	push {lr}
	bl sub_804C500
	cmp r0, #1
	bne .L08047D24
	bl sub_804C5A4
	b .L08047D2E
.L08047D24:
	bl sub_80481B4
	ldr r0, .L08047D34 @ =sub_8047D38
	bl SetMainFunc
.L08047D2E:
	pop {r0}
	bx r0
	.align 2, 0
.L08047D34: .4byte sub_8047D38

	thumb_func_start sub_8047D38
sub_8047D38: @ 0x08047D38
	push {r4, lr}
	ldr r0, .L08047D9C @ =gKeySt
	ldr r0, [r0]
	bl RefreshKeySt
	bl ClearSprites
	ldr r4, .L08047DA0 @ =gProcTreeRootArray
	ldr r0, [r4, #4]
	bl Proc_Run
	bl GetGameLock
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08047D5E
	ldr r0, [r4, #8]
	bl Proc_Run
.L08047D5E:
	ldr r0, [r4, #0xc]
	bl Proc_Run
	ldr r0, [r4, #0x14]
	bl Proc_Run
	movs r0, #0
	bl PutSpriteLayerOam
	ldr r0, [r4, #0x10]
	bl Proc_Run
	bl BasUpdateAll
	bl sub_804A5DC
	movs r0, #0xd
	bl PutSpriteLayerOam
	ldr r1, .L08047DA4 @ =gBmSt
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L08047DA8 @ =0x04000006
	ldrh r0, [r0]
	strh r0, [r1, #6]
	bl VBlankIntrWait
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08047D9C: .4byte gKeySt
.L08047DA0: .4byte gProcTreeRootArray
.L08047DA4: .4byte gBmSt
.L08047DA8: .4byte 0x04000006

	thumb_func_start sub_8047DAC
sub_8047DAC: @ 0x08047DAC
	push {lr}
	ldr r0, .L08047DBC @ =gUnk_085CBB18
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L08047DBC: .4byte gUnk_085CBB18

	thumb_func_start sub_8047DC0
sub_8047DC0: @ 0x08047DC0
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #4
	adds r5, r0, #0
	movs r4, #0
	movs r3, #0
	strh r3, [r5, #0x2c]
	movs r0, #0xf
	strh r0, [r5, #0x2e]
	ldr r2, .L08047EC0 @ =0x0203CD16
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r6, #4
	ldrsh r1, [r2, r6]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x32]
	movs r1, #2
	ldrsh r0, [r2, r1]
	movs r6, #6
	ldrsh r1, [r2, r6]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r5, #0x3c]
	strh r0, [r5, #0x3a]
	str r3, [sp]
	ldr r1, .L08047EC4 @ =gBg2Tm
	ldr r2, .L08047EC8 @ =0x01000200
	mov r0, sp
	bl CpuFastSet
	movs r0, #4
	bl EnableBgSync
	ldr r6, .L08047ECC @ =gDispIo
	adds r1, r6, #0
	adds r1, #0x3c
	movs r0, #0xc0
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x44
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r1, #0xa
	movs r0, #4
	mov sl, r0
	movs r0, #4
	strb r0, [r1]
	ldr r0, .L08047ED0 @ =0x0000FFE0
	ldrh r1, [r6, #0x3c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r6, #0x3c]
	movs r2, #0x20
	mov sb, r2
	mov r0, sb
	ldrb r1, [r6, #1]
	orrs r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r6, #1]
	adds r0, r6, #0
	adds r0, #0x2d
	strb r4, [r0]
	adds r0, #4
	strb r4, [r0]
	adds r1, r6, #0
	adds r1, #0x2c
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xa0
	strb r0, [r1]
	movs r2, #0x34
	adds r2, r2, r6
	mov r8, r2
	movs r0, #1
	ldrb r1, [r2]
	orrs r1, r0
	movs r4, #2
	orrs r1, r4
	mov r2, sl
	orrs r1, r2
	movs r3, #8
	orrs r1, r3
	movs r2, #0x10
	orrs r1, r2
	adds r6, #0x36
	ldrb r2, [r6]
	orrs r0, r2
	orrs r0, r4
	mov r2, sl
	orrs r0, r2
	orrs r0, r3
	movs r2, #0x11
	rsbs r2, r2, #0
	ands r0, r2
	subs r2, #0x10
	ands r1, r2
	mov r2, r8
	strb r1, [r2]
	mov r1, sb
	orrs r0, r1
	strb r0, [r6]
	adds r0, r5, #0
	bl Proc_Break
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08047EC0: .4byte 0x0203CD16
.L08047EC4: .4byte gBg2Tm
.L08047EC8: .4byte 0x01000200
.L08047ECC: .4byte gDispIo
.L08047ED0: .4byte 0x0000FFE0

	thumb_func_start sub_8047ED4
sub_8047ED4: @ 0x08047ED4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldrh r0, [r7, #0x2c]
	ldrh r1, [r7, #0x2e]
	cmp r0, r1
	beq .L08047EEC
	adds r0, #1
	strh r0, [r7, #0x2c]
.L08047EEC:
	movs r0, #0x32
	ldrsh r2, [r7, r0]
	movs r1, #0x2c
	ldrsh r3, [r7, r1]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl Interpolate
	adds r6, r0, #0
	movs r0, #0x3a
	ldrsh r2, [r7, r0]
	movs r1, #0x2c
	ldrsh r3, [r7, r1]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl Interpolate
	adds r5, r0, #0
	movs r0, #0x34
	ldrsh r2, [r7, r0]
	movs r1, #0x2c
	ldrsh r3, [r7, r1]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0xf0
	bl Interpolate
	adds r4, r0, #0
	movs r0, #0x3c
	ldrsh r2, [r7, r0]
	movs r1, #0x2c
	ldrsh r3, [r7, r1]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0xa0
	bl Interpolate
	ldr r1, .L08047FD4 @ =gDispIo
	movs r2, #0x2d
	adds r2, r2, r1
	mov r8, r2
	movs r2, #0
	mov sb, r2
	mov r2, r8
	strb r6, [r2]
	adds r6, r1, #0
	adds r6, #0x31
	strb r5, [r6]
	adds r5, r1, #0
	adds r5, #0x2c
	strb r4, [r5]
	adds r4, r1, #0
	adds r4, #0x30
	strb r0, [r4]
	ldrh r0, [r7, #0x2c]
	ldrh r2, [r7, #0x2e]
	cmp r0, r2
	bne .L08047FC4
	adds r2, r1, #0
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
	movs r0, #0
	bl InitOam
	bl LockBmDisplay
	mov r0, sb
	mov r2, r8
	strb r0, [r2]
	strb r0, [r6]
	movs r0, #0xf0
	strb r0, [r5]
	movs r0, #0xa0
	strb r0, [r4]
	ldr r0, .L08047FD8 @ =gPal
	movs r1, #6
	movs r2, #0xa
	movs r3, #4
	bl sub_805B5C8
	bl EnablePalSync
	bl EndAllMus
	adds r0, r7, #0
	bl Proc_Break
.L08047FC4:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08047FD4: .4byte gDispIo
.L08047FD8: .4byte gPal

	thumb_func_start sub_8047FDC
sub_8047FDC: @ 0x08047FDC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08048008 @ =0x0203CCF0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08048040
	bl sub_80436A4
	bl sub_8044198
	ldr r0, .L0804800C @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #3
	beq .L08048010
	cmp r0, #3
	ble .L08048040
	cmp r0, #4
	beq .L08048038
	b .L08048040
	.align 2, 0
.L08048008: .4byte 0x0203CCF0
.L0804800C: .4byte 0x0203CD14
.L08048010:
	ldr r4, .L08048034 @ =0x0203CCF8
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L08048022
	bl sub_80438E8
	bl sub_80441FC
.L08048022:
	movs r1, #2
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L08048040
	bl sub_80438F8
	bl sub_804420C
	b .L08048040
	.align 2, 0
.L08048034: .4byte 0x0203CCF8
.L08048038:
	bl sub_80438E8
	bl sub_80441FC
.L08048040:
	bl sub_8044390
	movs r0, #0
	bl sub_80489E8
	movs r0, #0
	bl sub_8048574
	movs r0, #0
	movs r1, #0xb
	bl sub_8048DA4
	movs r0, #0
	movs r1, #0xb
	movs r2, #0
	bl sub_8048E88
	movs r0, #0
	movs r1, #0xb
	bl sub_8048F88
	movs r0, #0
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804807C
sub_804807C: @ 0x0804807C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	ble .L080480BC
	ldr r0, .L080480AC @ =0x0203CCF2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L080480A0
	bl sub_805894C
	cmp r0, #0
	beq .L080480B0
.L080480A0:
	bl sub_80425F0
	adds r0, r4, #0
	bl Proc_End
	b .L080480BC
	.align 2, 0
.L080480AC: .4byte 0x0203CCF2
.L080480B0:
	strh r0, [r4, #0x2c]
	bl sub_80425F0
	adds r0, r4, #0
	bl Proc_Break
.L080480BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80480C4
sub_80480C4: @ 0x080480C4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #0
	movs r1, #4
	movs r2, #0x10
	bl Interpolate
	bl sub_805B9A4
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L080480F8
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L080480F8:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8048100
sub_8048100: @ 0x08048100
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08048114 @ =0x0203CCF6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0804811C
	ldr r1, .L08048118 @ =gUnk_Banim_0201E0F8
	movs r0, #6
	b .L08048120
	.align 2, 0
.L08048114: .4byte 0x0203CCF6
.L08048118: .4byte gUnk_Banim_0201E0F8
.L0804811C:
	ldr r1, .L08048148 @ =gUnk_Banim_0201E0F8
	movs r0, #0xa
.L08048120:
	str r0, [r1]
	ldr r0, .L0804814C @ =0x0203CCF2
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r0, #1
	bl sub_805F100
	ldr r0, .L08048150 @ =gPal
	movs r1, #6
	movs r2, #0xa
	movs r3, #0x10
	bl sub_805B5C8
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08048148: .4byte gUnk_Banim_0201E0F8
.L0804814C: .4byte 0x0203CCF2
.L08048150: .4byte gPal

	thumb_func_start sub_8048154
sub_8048154: @ 0x08048154
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r4, r0, #0
	ldr r0, .L080481AC @ =0x0203CCF2
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r0, #1
	bl sub_805F0DC
	ldr r0, .L080481B0 @ =gPal
	movs r1, #6
	movs r2, #0xa
	adds r3, r4, #0
	bl sub_805B5C8
	bl EnablePalSync
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L080481A2
	movs r0, #0
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L080481A2:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080481AC: .4byte 0x0203CCF2
.L080481B0: .4byte gPal

	thumb_func_start sub_80481B4
sub_80481B4: @ 0x080481B4
	push {lr}
	ldr r0, .L080481C8 @ =gUnk_085CBB60
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r0}
	bx r0
	.align 2, 0
.L080481C8: .4byte gUnk_085CBB60

	thumb_func_start sub_80481CC
sub_80481CC: @ 0x080481CC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r7, .L080481F0 @ =0x0203CCF2
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #0
	beq .L080481E6
	bl sub_805894C
	adds r6, r0, #0
	cmp r6, #0
	beq .L080481F4
.L080481E6:
	adds r0, r5, #0
	bl Proc_Break
	b .L08048238
	.align 2, 0
.L080481F0: .4byte 0x0203CCF2
.L080481F4:
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r4, r0, #0
	movs r1, #0
	ldrsh r0, [r7, r1]
	subs r0, #1
	bl sub_805F0DC
	ldr r0, .L08048240 @ =gPal
	movs r1, #6
	movs r2, #0xa
	adds r3, r4, #0
	bl sub_805B5C8
	bl EnablePalSync
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L08048238
	strh r6, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L08048238:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08048240: .4byte gPal

	thumb_func_start sub_8048244
sub_8048244: @ 0x08048244
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08048264 @ =0x0203CCF2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804825A
	bl sub_805894C
	cmp r0, #0
	beq .L08048268
.L0804825A:
	adds r0, r4, #0
	bl Proc_Break
	b .L0804828E
	.align 2, 0
.L08048264: .4byte 0x0203CCF2
.L08048268:
	ldr r0, .L08048294 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl ApplyChapterMapGraphics
	movs r0, #0x10
	bl sub_805B9A4
	bl RenderMap
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	adds r0, r4, #0
	bl Proc_Break
.L0804828E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08048294: .4byte gPlaySt

	thumb_func_start sub_8048298
sub_8048298: @ 0x08048298
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, .L080482BC @ =0x0203CCF2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L080482B2
	bl sub_805894C
	adds r5, r0, #0
	cmp r5, #0
	beq .L080482C0
.L080482B2:
	adds r0, r4, #0
	bl Proc_Break
	b .L080482EC
	.align 2, 0
.L080482BC: .4byte 0x0203CCF2
.L080482C0:
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #4
	bl Interpolate
	bl sub_805B9A4
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L080482EC
	strh r5, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L080482EC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_80482F4
sub_80482F4: @ 0x080482F4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r2, .L08048350 @ =0x0203CD16
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r4, #0x34]
	strh r0, [r4, #0x32]
	movs r1, #2
	ldrsh r0, [r2, r1]
	movs r3, #6
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r4, #0x3c]
	strh r0, [r4, #0x3a]
	bl BasInit
	movs r0, #1
	bl sub_80489E8
	movs r0, #1
	bl sub_8048574
	movs r0, #1
	movs r1, #0xb
	bl sub_8048DA4
	movs r0, #1
	movs r1, #0xb
	bl sub_8048F88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08048350: .4byte 0x0203CD16

	thumb_func_start sub_8048354
sub_8048354: @ 0x08048354
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	ble .L080483D4
	bl sub_80438B4
	adds r0, r4, #0
	bl Proc_Break
	bl InitBmBgLayers
	ldr r0, .L080483DC @ =gDispIo
	mov ip, r0
	movs r0, #0x20
	mov r1, ip
	ldrb r1, [r1, #1]
	orrs r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r2, ip
	strb r0, [r2, #1]
	mov r0, ip
	adds r0, #0x2d
	strb r5, [r0]
	adds r0, #4
	strb r5, [r0]
	subs r0, #5
	strb r5, [r0]
	adds r0, #4
	strb r5, [r0]
	mov r5, ip
	adds r5, #0x34
	movs r1, #1
	ldrb r0, [r5]
	orrs r0, r1
	movs r6, #2
	orrs r0, r6
	movs r4, #4
	orrs r0, r4
	movs r3, #8
	orrs r0, r3
	movs r2, #0x10
	orrs r0, r2
	strb r0, [r5]
	mov r2, ip
	adds r2, #0x36
	ldrb r0, [r2]
	orrs r1, r0
	orrs r1, r6
	orrs r1, r4
	orrs r1, r3
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r2]
.L080483D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080483DC: .4byte gDispIo

	thumb_func_start sub_80483E0
sub_80483E0: @ 0x080483E0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #0xf
	strh r0, [r5, #0x2e]
	bl ResetUnitSprites
	bl sub_80292B8
	bl RefreshUnitSprites
	bl ForceSyncUnitSpriteSheet
	bl ApplyUnitSpritePalettes
	ldr r2, .L08048468 @ =gDispIo
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0xc0
	ldrb r3, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x44
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r1, #0xa
	movs r0, #4
	strb r0, [r1]
	ldr r0, .L0804846C @ =0x0000FFE0
	ldrh r1, [r2, #0x3c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r2, #0x3c]
	adds r1, r2, #0
	adds r1, #0x34
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r1, #2
	movs r0, #0x20
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	bl sub_804C500
	cmp r0, #1
	beq .L08048450
	bl ApplyChapterMapPalettes
.L08048450:
	bl sub_8042578
	cmp r0, #1
	bne .L0804845C
	bl sub_803CF58
.L0804845C:
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08048468: .4byte gDispIo
.L0804846C: .4byte 0x0000FFE0

	thumb_func_start sub_8048470
sub_8048470: @ 0x08048470
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldrh r0, [r7, #0x2c]
	ldrh r1, [r7, #0x2e]
	cmp r0, r1
	beq .L08048488
	adds r0, #1
	strh r0, [r7, #0x2c]
.L08048488:
	movs r2, #0x32
	ldrsh r1, [r7, r2]
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0
	bl Interpolate
	adds r6, r0, #0
	movs r0, #0x3a
	ldrsh r1, [r7, r0]
	movs r2, #0x2c
	ldrsh r3, [r7, r2]
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0
	bl Interpolate
	adds r5, r0, #0
	movs r0, #0x34
	ldrsh r1, [r7, r0]
	movs r2, #0x2c
	ldrsh r3, [r7, r2]
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0xf0
	bl Interpolate
	adds r4, r0, #0
	movs r0, #0x3c
	ldrsh r1, [r7, r0]
	movs r2, #0x2c
	ldrsh r3, [r7, r2]
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0xa0
	bl Interpolate
	ldr r1, .L08048550 @ =gDispIo
	movs r2, #0x2d
	adds r2, r2, r1
	mov sb, r2
	movs r2, #0
	mov r8, r2
	mov r2, sb
	strb r6, [r2]
	adds r6, r1, #0
	adds r6, #0x31
	strb r5, [r6]
	adds r5, r1, #0
	adds r5, #0x2c
	strb r4, [r5]
	adds r4, r1, #0
	adds r4, #0x30
	strb r0, [r4]
	mov r0, r8
	str r0, [sp, #4]
	ldr r1, .L08048554 @ =gBg2Tm
	ldr r2, .L08048558 @ =0x01000200
	add r0, sp, #4
	bl CpuFastSet
	movs r0, #4
	bl EnableBgSync
	ldrh r1, [r7, #0x2c]
	ldrh r2, [r7, #0x2e]
	cmp r1, r2
	bne .L08048542
	movs r0, #0
	mov r1, r8
	strh r1, [r7, #0x2c]
	mov r2, sb
	strb r0, [r2]
	strb r0, [r6]
	movs r0, #0xf0
	strb r0, [r5]
	movs r0, #0xa0
	strb r0, [r4]
	bl EnablePalSync
	adds r0, r7, #0
	bl Proc_Break
.L08048542:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08048550: .4byte gDispIo
.L08048554: .4byte gBg2Tm
.L08048558: .4byte 0x01000200

	thumb_func_start sub_804855C
sub_804855C: @ 0x0804855C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_80425B0
	bl sub_8029240
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8048574
sub_8048574: @ 0x08048574
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r3, .L080485DC @ =gDispIo
	adds r1, r3, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	adds r1, #8
	movs r2, #0
	movs r0, #0xa
	strb r0, [r1]
	adds r1, #1
	movs r0, #6
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r2, [r0]
	ldr r0, .L080485E0 @ =0x0000FFE0
	ldrh r4, [r3, #0x3c]
	ands r0, r4
	ldr r1, .L080485E4 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3, #0x3c]
	adds r1, r3, #0
	adds r1, #0x3d
	movs r0, #0x20
	ldrb r3, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldr r0, .L080485E8 @ =0x0203CD16
	movs r4, #0
	ldrsh r3, [r0, r4]
	movs r1, #4
	ldrsh r2, [r0, r1]
	cmp r3, r2
	bne .L080485EC
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r3, #6
	ldrsh r0, [r0, r3]
	movs r4, #2
	cmp r1, r0
	blt .L08048618
	movs r4, #6
	b .L08048618
	.align 2, 0
.L080485DC: .4byte gDispIo
.L080485E0: .4byte 0x0000FFE0
.L080485E4: .4byte 0x0000E0FF
.L080485E8: .4byte 0x0203CD16
.L080485EC:
	movs r4, #2
	ldrsh r1, [r0, r4]
	movs r4, #6
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bne .L08048602
	movs r4, #4
	cmp r3, r2
	bge .L08048618
	movs r4, #0
	b .L08048618
.L08048602:
	cmp r3, r2
	bge .L08048610
	movs r4, #1
	cmp r1, r0
	blt .L08048618
	movs r4, #7
	b .L08048618
.L08048610:
	movs r4, #3
	cmp r1, r0
	blt .L08048618
	movs r4, #5
.L08048618:
	ldr r0, .L0804862C @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #3
	bgt .L08048630
	cmp r0, #1
	bge .L0804863C
	cmp r0, #0
	beq .L08048634
	b .L0804863C
	.align 2, 0
.L0804862C: .4byte 0x0203CD14
.L08048630:
	cmp r0, #4
	bne .L0804863C
.L08048634:
	ldr r0, .L08048638 @ =gUnk_085CBBC8
	b .L0804863E
	.align 2, 0
.L08048638: .4byte gUnk_085CBBC8
.L0804863C:
	ldr r0, .L08048670 @ =gUnk_085CBBE8
.L0804863E:
	lsls r1, r4, #2
	adds r0, r1, r0
	ldr r0, [r0]
	adds r6, r1, #0
	ldr r1, .L08048674 @ =0x06010000
	bl LZ77UnCompVram
	ldr r0, .L08048678 @ =gUnk_08119CD8
	ldr r1, .L0804867C @ =gPal+0x280
	movs r2, #1
	bl CpuFastSet
	bl EnablePalSync
	ldr r0, .L08048680 @ =0x0203CD14
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #4
	bls .L08048666
	b .L08048942
.L08048666:
	lsls r0, r0, #2
	ldr r1, .L08048684 @ =.L08048688
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08048670: .4byte gUnk_085CBBE8
.L08048674: .4byte 0x06010000
.L08048678: .4byte gUnk_08119CD8
.L0804867C: .4byte gPal+0x280
.L08048680: .4byte 0x0203CD14
.L08048684: .4byte .L08048688
.L08048688: @ jump table
	.4byte .L0804869C @ case 0
	.4byte .L0804873C @ case 1
	.4byte .L0804873C @ case 2
	.4byte .L080488A8 @ case 3
	.4byte .L0804869C @ case 4
.L0804869C:
	ldr r0, .L080486EC @ =gUnk_085CBBB0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r7, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	strh r0, [r5, #0x2c]
	movs r0, #0xb
	strh r0, [r5, #0x2e]
	ldr r2, .L080486F0 @ =0x0203CD16
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r4, #4
	ldrsh r1, [r2, r4]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r5, #0x32]
	movs r1, #2
	ldrsh r0, [r2, r1]
	movs r3, #6
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r5, #0x3a]
	movs r0, #0x78
	strh r0, [r5, #0x34]
	movs r0, #0x68
	strh r0, [r5, #0x3c]
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L080486F8
	ldr r0, .L080486F4 @ =gUnk_085CBC08
	b .L080486FA
	.align 2, 0
.L080486EC: .4byte gUnk_085CBBB0
.L080486F0: .4byte 0x0203CD16
.L080486F4: .4byte gUnk_085CBC08
.L080486F8:
	ldr r0, .L08048728 @ =gUnk_085CBC68
.L080486FA:
	adds r0, r6, r0
	ldr r0, [r0]
	movs r1, #0x64
	bl BasCreate
	adds r2, r0, #0
	str r2, [r5, #0x5c]
	movs r0, #0x90
	lsls r0, r0, #7
	strh r0, [r2, #8]
	ldr r0, [r2, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r2, #0x1c]
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L0804872C
	ldrh r0, [r5, #0x32]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3a]
	b .L08048732
	.align 2, 0
.L08048728: .4byte gUnk_085CBC68
.L0804872C:
	ldrh r0, [r5, #0x34]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3c]
.L08048732:
	strh r0, [r2, #4]
	ldr r0, .L08048738 @ =gUnk_085CBCC8
	b .L08048936
	.align 2, 0
.L08048738: .4byte gUnk_085CBCC8
.L0804873C:
	ldr r0, .L08048798 @ =gUnk_085CBBB0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r7, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	strh r0, [r5, #0x2c]
	movs r0, #0xb
	strh r0, [r5, #0x2e]
	ldr r1, .L0804879C @ =0x0203CD16
	movs r4, #0
	ldrsh r0, [r1, r4]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r5, #0x32]
	movs r2, #2
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r5, #0x3a]
	movs r2, #0x48
	strh r2, [r5, #0x34]
	movs r0, #0x68
	strh r0, [r5, #0x3c]
	ldr r0, .L080487A0 @ =gUnk_Banim_0201773C
	ldr r0, [r0]
	cmp r0, #1
	bne .L0804878E
	ldr r1, .L080487A4 @ =gUnk_081122D0
	ldr r0, .L080487A8 @ =0x0203CD14
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, r2, r0
	strh r0, [r5, #0x34]
.L0804878E:
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L080487B0
	ldr r0, .L080487AC @ =gUnk_085CBC28
	b .L080487B2
	.align 2, 0
.L08048798: .4byte gUnk_085CBBB0
.L0804879C: .4byte 0x0203CD16
.L080487A0: .4byte gUnk_Banim_0201773C
.L080487A4: .4byte gUnk_081122D0
.L080487A8: .4byte 0x0203CD14
.L080487AC: .4byte gUnk_085CBC28
.L080487B0:
	ldr r0, .L080487E0 @ =gUnk_085CBC88
.L080487B2:
	adds r0, r6, r0
	ldr r0, [r0]
	movs r1, #0x64
	bl BasCreate
	adds r2, r0, #0
	str r2, [r5, #0x5c]
	movs r0, #0x90
	lsls r0, r0, #7
	strh r0, [r2, #8]
	ldr r0, [r2, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r2, #0x1c]
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L080487E4
	ldrh r0, [r5, #0x32]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3a]
	b .L080487EA
	.align 2, 0
.L080487E0: .4byte gUnk_085CBC88
.L080487E4:
	ldrh r0, [r5, #0x34]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3c]
.L080487EA:
	strh r0, [r2, #4]
	ldr r0, .L08048858 @ =gUnk_085CBCE8
	adds r0, r6, r0
	ldr r0, [r0]
	str r0, [r5, #0x60]
	movs r4, #0
	strh r4, [r5, #0x3e]
	strh r4, [r5, #0x36]
	ldr r0, .L0804885C @ =gUnk_085CBBB0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r7, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	strh r4, [r5, #0x2c]
	movs r0, #0xb
	strh r0, [r5, #0x2e]
	ldr r1, .L08048860 @ =0x0203CD16
	movs r4, #4
	ldrsh r0, [r1, r4]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r5, #0x32]
	movs r2, #6
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r5, #0x3a]
	movs r0, #0xa8
	strh r0, [r5, #0x34]
	movs r0, #0x68
	strh r0, [r5, #0x3c]
	ldr r0, .L08048864 @ =gUnk_Banim_0201773C
	ldr r0, [r0]
	cmp r0, #0
	bne .L0804884C
	ldr r1, .L08048868 @ =gUnk_081122D0
	ldr r0, .L0804886C @ =0x0203CD14
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, #0xa8
	strh r0, [r5, #0x34]
.L0804884C:
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L08048874
	ldr r0, .L08048870 @ =gUnk_085CBC48
	b .L08048876
	.align 2, 0
.L08048858: .4byte gUnk_085CBCE8
.L0804885C: .4byte gUnk_085CBBB0
.L08048860: .4byte 0x0203CD16
.L08048864: .4byte gUnk_Banim_0201773C
.L08048868: .4byte gUnk_081122D0
.L0804886C: .4byte 0x0203CD14
.L08048870: .4byte gUnk_085CBC48
.L08048874:
	ldr r0, .L080488A4 @ =gUnk_085CBCA8
.L08048876:
	adds r0, r6, r0
	ldr r0, [r0]
	movs r1, #0x64
	bl BasCreate
	adds r2, r0, #0
	str r2, [r5, #0x5c]
	movs r0, #0x90
	lsls r0, r0, #7
	strh r0, [r2, #8]
	ldr r0, [r2, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r2, #0x1c]
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L0804892C
	ldrh r0, [r5, #0x32]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3a]
	b .L08048932
	.align 2, 0
.L080488A4: .4byte gUnk_085CBCA8
.L080488A8:
	ldr r0, .L080488EC @ =gUnk_085CBBB0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r7, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	strh r0, [r5, #0x2c]
	movs r0, #0xb
	strh r0, [r5, #0x2e]
	ldr r1, .L080488F0 @ =0x0203CD16
	movs r4, #4
	ldrsh r0, [r1, r4]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r5, #0x32]
	movs r2, #6
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r5, #0x3a]
	movs r0, #0x78
	strh r0, [r5, #0x34]
	movs r0, #0x68
	strh r0, [r5, #0x3c]
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L080488F8
	ldr r0, .L080488F4 @ =gUnk_085CBC48
	b .L080488FA
	.align 2, 0
.L080488EC: .4byte gUnk_085CBBB0
.L080488F0: .4byte 0x0203CD16
.L080488F4: .4byte gUnk_085CBC48
.L080488F8:
	ldr r0, .L08048928 @ =gUnk_085CBCA8
.L080488FA:
	adds r0, r6, r0
	ldr r0, [r0]
	movs r1, #0x64
	bl BasCreate
	adds r2, r0, #0
	str r2, [r5, #0x5c]
	movs r0, #0x90
	lsls r0, r0, #7
	strh r0, [r2, #8]
	ldr r0, [r2, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r2, #0x1c]
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L0804892C
	ldrh r0, [r5, #0x32]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3a]
	b .L08048932
	.align 2, 0
.L08048928: .4byte gUnk_085CBCA8
.L0804892C:
	ldrh r0, [r5, #0x34]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3c]
.L08048932:
	strh r0, [r2, #4]
	ldr r0, .L08048948 @ =gUnk_085CBD08
.L08048936:
	adds r0, r6, r0
	ldr r0, [r0]
	str r0, [r5, #0x60]
	movs r0, #0
	strh r0, [r5, #0x3e]
	strh r0, [r5, #0x36]
.L08048942:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08048948: .4byte gUnk_085CBD08

	thumb_func_start sub_804894C
sub_804894C: @ 0x0804894C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, [r4, #0x5c]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	blt .L0804896E
	adds r0, r5, #0
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
	b .L080489DE
.L0804896E:
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048998
	movs r3, #0x32
	ldrsh r1, [r4, r3]
	movs r6, #0x34
	ldrsh r2, [r4, r6]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	strh r0, [r5, #2]
	movs r0, #0x3a
	ldrsh r1, [r4, r0]
	movs r3, #0x3c
	ldrsh r2, [r4, r3]
	b .L080489BA
.L08048998:
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	movs r3, #0x32
	ldrsh r2, [r4, r3]
	movs r6, #0x2c
	ldrsh r3, [r4, r6]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	strh r0, [r5, #2]
	movs r0, #0x3c
	ldrsh r1, [r4, r0]
	movs r3, #0x3a
	ldrsh r2, [r4, r3]
.L080489BA:
	movs r6, #0x2c
	ldrsh r3, [r4, r6]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	strh r0, [r5, #4]
	ldrh r2, [r4, #0x2c]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r3, #0x2e
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bgt .L080489DE
	adds r0, r2, #1
	strh r0, [r4, #0x2c]
.L080489DE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80489E8
sub_80489E8: @ 0x080489E8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08048A14 @ =gUnk_085CBD28
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x44]
	movs r1, #0
	str r1, [r4, #0x50]
	str r1, [r4, #0x4c]
	ldr r0, .L08048A18 @ =0x0203CD14
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt .L08048A5E
	cmp r0, #3
	ble .L08048A1C
	cmp r0, #4
	beq .L08048A4C
	b .L08048A5E
	.align 2, 0
.L08048A14: .4byte gUnk_085CBD28
.L08048A18: .4byte 0x0203CD14
.L08048A1C:
	ldr r0, .L08048A48 @ =0x0203CCF8
	movs r1, #0
	ldrsh r5, [r0, r1]
	cmp r5, #1
	bne .L08048A30
	bl sub_8058F00
	cmp r0, #0
	beq .L08048A30
	str r5, [r4, #0x4c]
.L08048A30:
	ldr r0, .L08048A48 @ =0x0203CCF8
	movs r2, #2
	ldrsh r5, [r0, r2]
	cmp r5, #1
	bne .L08048A5E
	bl sub_8058F00
	cmp r0, #1
	beq .L08048A5E
	str r5, [r4, #0x50]
	b .L08048A5E
	.align 2, 0
.L08048A48: .4byte 0x0203CCF8
.L08048A4C:
	cmp r5, #0
	bne .L08048A58
	str r1, [r4, #0x4c]
	movs r0, #1
	str r0, [r4, #0x50]
	b .L08048A5E
.L08048A58:
	movs r0, #1
	str r0, [r4, #0x4c]
	str r1, [r4, #0x50]
.L08048A5E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8048A64
sub_8048A64: @ 0x08048A64
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, .L08048B74 @ =gUnk_081122C0
	ldr r0, .L08048B78 @ =0x0203CD14
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, r0, r1
	ldr r1, .L08048B7C @ =gUnk_08112298
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r6, [r0]
	bl sub_804B048
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048A9C
	ldr r1, .L08048B80 @ =gBattleSt
	movs r0, #0x40
	ldrb r1, [r1, #1]
	ands r0, r1
	cmp r0, #0
	beq .L08048A9C
	ldr r0, .L08048B84 @ =gPal
	movs r1, #0x17
	movs r2, #1
	bl sub_805B780
.L08048A9C:
	ldr r5, .L08048B88 @ =0x0203CCF8
	ldrh r3, [r5]
	cmp r3, #1
	bne .L08048AC2
	ldr r0, .L08048B8C @ =gUnk_Banim_02000054
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L08048B90 @ =gUnk_Banim_0200F1C0
	adds r1, r1, r0
	ldr r0, [r1, #4]
	ldr r1, [r1, #8]
	ldr r2, .L08048B94 @ =gUnk_Banim_020041C0
	adds r1, r1, r2
	str r1, [r4, #0x54]
	ldr r1, .L08048B98 @ =gUnk_Banim_02000080
	bl LZ77UnCompWram
.L08048AC2:
	ldrh r5, [r5, #2]
	cmp r5, #1
	bne .L08048AE6
	ldr r0, .L08048B9C @ =gUnk_Banim_02000058
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L08048BA0 @ =gUnk_Banim_02011BC0
	adds r1, r1, r0
	ldr r0, [r1, #4]
	ldr r1, [r1, #8]
	ldr r2, .L08048BA4 @ =gUnk_Banim_020099C0
	adds r1, r1, r2
	str r1, [r4, #0x58]
	ldr r1, .L08048BA8 @ =gUnk_Banim_02002080
	bl LZ77UnCompWram
.L08048AE6:
	ldr r5, .L08048BAC @ =0x0203CD98
	ldr r0, [r5]
	cmp r0, #0
	beq .L08048AF4
	ldr r1, .L08048BB0 @ =gUnk_Banim_02001080
	bl LZ77UnCompWram
.L08048AF4:
	ldr r0, [r5, #4]
	cmp r0, #0
	beq .L08048B00
	ldr r1, .L08048BB4 @ =gUnk_Banim_02003080
	bl LZ77UnCompWram
.L08048B00:
	ldr r1, .L08048BB8 @ =0x06014000
	ldr r0, .L08048B98 @ =gUnk_Banim_02000080
	movs r2, #0x80
	lsls r2, r2, #7
	bl RegisterDataMove
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0xb
	strh r0, [r4, #0x2e]
	ldr r1, .L08048BBC @ =0x0203CD16
	movs r5, #0
	ldrsh r0, [r1, r5]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r4, #0x32]
	movs r2, #2
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r4, #0x3a]
	movs r3, #4
	ldrsh r0, [r1, r3]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r4, #0x34]
	movs r5, #6
	ldrsh r0, [r1, r5]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r4, #0x3c]
	ldr r1, .L08048BC0 @ =gUnk_081122C5
	ldr r2, .L08048B78 @ =0x0203CD14
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, r0, r1
	ldrb r5, [r0]
	strh r5, [r4, #0x36]
	ldr r1, .L08048BC4 @ =gUnk_081122CA
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, r0, r1
	ldrb r3, [r0]
	strh r3, [r4, #0x38]
	ldr r0, .L08048BC8 @ =gUnk_Banim_0201773C
	ldr r0, [r0]
	cmp r0, #0
	bne .L08048BD0
	ldr r0, .L08048BCC @ =gUnk_081122D0
	movs r5, #0
	ldrsh r1, [r2, r5]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r1, r3
	strh r0, [r4, #0x38]
	b .L08048BE0
	.align 2, 0
.L08048B74: .4byte gUnk_081122C0
.L08048B78: .4byte 0x0203CD14
.L08048B7C: .4byte gUnk_08112298
.L08048B80: .4byte gBattleSt
.L08048B84: .4byte gPal
.L08048B88: .4byte 0x0203CCF8
.L08048B8C: .4byte gUnk_Banim_02000054
.L08048B90: .4byte gUnk_Banim_0200F1C0
.L08048B94: .4byte gUnk_Banim_020041C0
.L08048B98: .4byte gUnk_Banim_02000080
.L08048B9C: .4byte gUnk_Banim_02000058
.L08048BA0: .4byte gUnk_Banim_02011BC0
.L08048BA4: .4byte gUnk_Banim_020099C0
.L08048BA8: .4byte gUnk_Banim_02002080
.L08048BAC: .4byte 0x0203CD98
.L08048BB0: .4byte gUnk_Banim_02001080
.L08048BB4: .4byte gUnk_Banim_02003080
.L08048BB8: .4byte 0x06014000
.L08048BBC: .4byte 0x0203CD16
.L08048BC0: .4byte gUnk_081122C5
.L08048BC4: .4byte gUnk_081122CA
.L08048BC8: .4byte gUnk_Banim_0201773C
.L08048BCC: .4byte gUnk_081122D0
.L08048BD0:
	ldr r0, .L08048BEC @ =gUnk_081122D0
	movs r3, #0
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	subs r0, r5, r1
	strh r0, [r4, #0x36]
.L08048BE0:
	adds r0, r4, #0
	bl Proc_Break
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08048BEC: .4byte gUnk_081122D0

	thumb_func_start sub_8048BF0
sub_8048BF0: @ 0x08048BF0
	push {r4, r5, r6, r7, lr}
	ldr r4, .L08048C10 @ =0xFFFFFCB4
	add sp, r4
	adds r4, r0, #0
	add r5, sp, #0x304
	ldrh r2, [r4, #0x2c]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r3, #0x2e
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt .L08048C14
	adds r0, r4, #0
	bl Proc_Break
	b .L08048D8A
	.align 2, 0
.L08048C10: .4byte 0xFFFFFCB4
.L08048C14:
	adds r0, r2, #1
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048C2C
	movs r1, #0x94
	lsls r1, r1, #2
	movs r2, #0x80
	lsls r2, r2, #1
	movs r6, #0x2c
	ldrsh r3, [r4, r6]
	b .L08048C38
.L08048C2C:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x94
	lsls r2, r2, #2
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
.L08048C38:
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, [r4, #0x4c]
	cmp r0, #1
	bne .L08048CEA
	ldr r0, [r4, #0x54]
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	movs r1, #0
	str r1, [sp]
	add r1, sp, #4
	adds r2, r3, #0
	bl sub_805BB24
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048C96
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	movs r3, #0x36
	ldrsh r2, [r4, r3]
	movs r6, #0x2c
	ldrsh r3, [r4, r6]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x3a
	ldrsh r1, [r4, r0]
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0x58
	b .L08048CC4
.L08048C96:
	movs r3, #0x36
	ldrsh r1, [r4, r3]
	movs r6, #0x32
	ldrsh r2, [r4, r6]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x3a
	ldrsh r2, [r4, r0]
	movs r1, #0x2c
	ldrsh r3, [r4, r1]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x58
.L08048CC4:
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	add r2, sp, #4
	str r2, [r5, #0x3c]
	movs r0, #0
	strh r6, [r5, #2]
	strh r1, [r5, #4]
	movs r1, #0x80
	lsls r1, r1, #3
	strh r1, [r5, #0xc]
	movs r1, #0xe4
	lsls r1, r1, #7
	strh r1, [r5, #8]
	str r0, [r5, #0x1c]
	adds r0, r5, #0
	bl BasPutOam
.L08048CEA:
	ldr r1, [r4, #0x50]
	cmp r1, #1
	bne .L08048D8A
	ldr r0, [r4, #0x58]
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	str r1, [sp]
	add r1, sp, #4
	adds r2, r3, #0
	bl sub_805BB24
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048D36
	movs r3, #0x34
	ldrsh r1, [r4, r3]
	movs r6, #0x38
	ldrsh r2, [r4, r6]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x3c
	ldrsh r1, [r4, r0]
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0x58
	b .L08048D64
.L08048D36:
	movs r3, #0x38
	ldrsh r1, [r4, r3]
	movs r6, #0x34
	ldrsh r2, [r4, r6]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x3c
	ldrsh r2, [r4, r0]
	movs r1, #0x2c
	ldrsh r3, [r4, r1]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x58
.L08048D64:
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	add r2, sp, #4
	str r2, [r5, #0x3c]
	movs r0, #0
	strh r6, [r5, #2]
	strh r1, [r5, #4]
	movs r1, #0x80
	lsls r1, r1, #3
	strh r1, [r5, #0xc]
	movs r1, #0x93
	lsls r1, r1, #8
	strh r1, [r5, #8]
	str r0, [r5, #0x1c]
	adds r0, r5, #0
	bl BasPutOam
.L08048D8A:
	movs r3, #0xd3
	lsls r3, r3, #2
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8048D98
sub_8048D98: @ 0x08048D98
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8048DA4
sub_8048DA4: @ 0x08048DA4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, .L08048DE8 @ =gUnk_085CBD50
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x44]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	movs r1, #0x39
	strh r1, [r0, #0x30]
	movs r2, #0
	cmp r5, #0
	bne .L08048DC6
	movs r2, #0x39
.L08048DC6:
	ldr r1, .L08048DEC @ =gUnk_Banim_02000030
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldrh r1, [r1, #2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_8043918
	ldr r1, .L08048DF0 @ =gUnk_Banim_0201E0EC
	movs r0, #1
	str r0, [r1]
	bl sub_8043950
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08048DE8: .4byte gUnk_085CBD50
.L08048DEC: .4byte gUnk_Banim_02000030
.L08048DF0: .4byte gUnk_Banim_0201E0EC

	thumb_func_start sub_8048DF4
sub_8048DF4: @ 0x08048DF4
	ldr r0, .L08048E00 @ =gUnk_Banim_0201E0EC
	ldr r0, [r0]
	cmp r0, #0
	beq .L08048E04
	movs r0, #0
	b .L08048E06
	.align 2, 0
.L08048E00: .4byte gUnk_Banim_0201E0EC
.L08048E04:
	movs r0, #1
.L08048E06:
	bx lr

	thumb_func_start sub_8048E08
sub_8048E08: @ 0x08048E08
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrh r2, [r4, #0x2c]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r3, #0x2e
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt .L08048E34
	ldr r1, .L08048E30 @ =gUnk_Banim_0201E0EC
	movs r0, #0
	str r0, [r1]
	bl sub_8043940
	adds r0, r4, #0
	bl Proc_Break
	b .L08048E7C
	.align 2, 0
.L08048E30: .4byte gUnk_Banim_0201E0EC
.L08048E34:
	adds r0, r2, #1
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048E52
	movs r0, #0x30
	ldrsh r1, [r4, r0]
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	str r0, [sp]
	movs r0, #1
	movs r2, #0
	b .L08048E64
.L08048E52:
	movs r3, #0x30
	ldrsh r2, [r4, r3]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #4
	movs r1, #0
.L08048E64:
	bl Interpolate
	adds r2, r0, #0
	ldr r1, .L08048E84 @ =gUnk_Banim_02000030
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldrh r1, [r1, #2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_8043918
.L08048E7C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08048E84: .4byte gUnk_Banim_02000030

	thumb_func_start sub_8048E88
sub_8048E88: @ 0x08048E88
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, .L08048EB8 @ =gUnk_085CBD68
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x44]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r6, [r0, #0x30]
	subs r1, #0x31
	str r1, [r0, #0x48]
	cmp r4, #0
	bne .L08048EBC
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0
	bl sub_804421C
	b .L08048EC4
	.align 2, 0
.L08048EB8: .4byte gUnk_085CBD68
.L08048EBC:
	movs r0, #0
	movs r1, #0
	bl sub_804421C
.L08048EC4:
	ldr r1, .L08048ED4 @ =gUnk_Banim_0201E0F0
	movs r0, #1
	str r0, [r1]
	bl sub_8044254
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08048ED4: .4byte gUnk_Banim_0201E0F0

	thumb_func_start sub_8048ED8
sub_8048ED8: @ 0x08048ED8
	ldr r0, .L08048EE4 @ =gUnk_Banim_0201E0F0
	ldr r0, [r0]
	cmp r0, #0
	beq .L08048EE8
	movs r0, #0
	b .L08048EEA
	.align 2, 0
.L08048EE4: .4byte gUnk_Banim_0201E0F0
.L08048EE8:
	movs r0, #1
.L08048EEA:
	bx lr

	thumb_func_start sub_8048EEC
sub_8048EEC: @ 0x08048EEC
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	ldrh r2, [r1, #0x30]
	cmp r0, r2
	bne .L08048F04
	movs r0, #0
	strh r0, [r1, #0x2c]
	adds r0, r1, #0
	bl Proc_Break
	b .L08048F08
.L08048F04:
	adds r0, #1
	strh r0, [r1, #0x2c]
.L08048F08:
	pop {r0}
	bx r0

	thumb_func_start sub_8048F0C
sub_8048F0C: @ 0x08048F0C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrh r2, [r4, #0x2c]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r3, #0x2e
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt .L08048F40
	ldr r0, .L08048F3C @ =gUnk_Banim_0201E0F0
	movs r1, #0
	str r1, [r0]
	bl sub_8044244
	ldr r0, [r4, #0x44]
	cmp r0, #2
	bne .L08048F34
	bl sub_80441C8
.L08048F34:
	adds r0, r4, #0
	bl Proc_Break
	b .L08048F7E
	.align 2, 0
.L08048F3C: .4byte gUnk_Banim_0201E0F0
.L08048F40:
	adds r0, r2, #1
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048F60
	ldr r1, [r4, #0x48]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	str r0, [sp]
	movs r0, #1
	movs r2, #0
	bl Interpolate
	b .L08048F74
.L08048F60:
	ldr r2, [r4, #0x48]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #4
	movs r1, #0
	bl Interpolate
.L08048F74:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0
	bl sub_804421C
.L08048F7E:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8048F88
sub_8048F88: @ 0x08048F88
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08048FAC @ =gUnk_085CBD88
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x44]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	cmp r4, #0
	bne .L08048FB4
	ldr r2, .L08048FB0 @ =0x0000FFA8
	movs r0, #2
	bl SetBgOffset
	b .L08048FBE
	.align 2, 0
.L08048FAC: .4byte gUnk_085CBD88
.L08048FB0: .4byte 0x0000FFA8
.L08048FB4:
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
.L08048FBE:
	ldr r1, .L08048FCC @ =gUnk_Banim_0201E0F4
	movs r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08048FCC: .4byte gUnk_Banim_0201E0F4

	thumb_func_start sub_8048FD0
sub_8048FD0: @ 0x08048FD0
	ldr r0, .L08048FDC @ =gUnk_Banim_0201E0F4
	ldr r0, [r0]
	cmp r0, #0
	beq .L08048FE0
	movs r0, #0
	b .L08048FE2
	.align 2, 0
.L08048FDC: .4byte gUnk_Banim_0201E0F4
.L08048FE0:
	movs r0, #1
.L08048FE2:
	bx lr

	thumb_func_start sub_8048FE4
sub_8048FE4: @ 0x08048FE4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrh r2, [r4, #0x2c]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r3, #0x2e
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt .L0804900C
	ldr r1, .L08049008 @ =gUnk_Banim_0201E0F4
	movs r0, #0
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
	b .L08049050
	.align 2, 0
.L08049008: .4byte gUnk_Banim_0201E0F4
.L0804900C:
	adds r0, r2, #1
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L0804902E
	movs r1, #0x50
	rsbs r1, r1, #0
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	str r0, [sp]
	movs r0, #1
	movs r2, #0
	bl Interpolate
	b .L08049044
.L0804902E:
	movs r2, #0x50
	rsbs r2, r2, #0
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #4
	movs r1, #0
	bl Interpolate
.L08049044:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	movs r0, #2
	movs r1, #0
	bl SetBgOffset
.L08049050:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8049058
sub_8049058: @ 0x08049058
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	movs r0, #1
	str r0, [sp, #0x18]
	ldr r1, .L0804907C @ =gBattleSt
	movs r0, #0x20
	ldrb r1, [r1, #1]
	ands r0, r1
	cmp r0, #0
	bne .L08049080
	movs r0, #0
	bl sub_804C4F4
	b .L08049086
	.align 2, 0
.L0804907C: .4byte gBattleSt
.L08049080:
	movs r0, #1
	bl sub_804C4F4
.L08049086:
	ldr r1, .L0804909C @ =gBmSt
	movs r0, #0x40
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	bne .L080490A0
	movs r0, #0
	bl sub_804256C
	b .L080490A6
	.align 2, 0
.L0804909C: .4byte gBmSt
.L080490A0:
	movs r0, #1
	bl sub_804256C
.L080490A6:
	ldr r1, .L080490C0 @ =gBattleSt
	movs r0, #0x10
	ldrb r1, [r1, #1]
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq .L080490C8
	ldr r1, .L080490C4 @ =0x0203CD14
	movs r0, #4
	strh r0, [r1]
	adds r0, r1, #0
	b .L080490CC
	.align 2, 0
.L080490C0: .4byte gBattleSt
.L080490C4: .4byte 0x0203CD14
.L080490C8:
	ldr r0, .L080490F8 @ =0x0203CD14
	strh r2, [r0]
.L080490CC:
	ldrh r0, [r0]
	cmp r0, #4
	bne .L08049114
	ldr r1, .L080490FC @ =0x0203CD7C
	ldr r0, .L08049100 @ =gBattleUnitA
	str r0, [r1]
	str r0, [sp]
	ldr r1, .L08049104 @ =0x0203CD80
	ldr r0, .L08049108 @ =gBattleUnitB
	str r0, [r1]
	str r0, [sp, #4]
	ldr r1, .L0804910C @ =0x0203CCFC
	movs r0, #0
	strh r0, [r1, #2]
	strh r0, [r1]
	ldr r0, .L08049110 @ =0x0203CCF8
	movs r1, #1
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r7, [sp]
	adds r3, r0, #0
	b .L0804920E
	.align 2, 0
.L080490F8: .4byte 0x0203CD14
.L080490FC: .4byte 0x0203CD7C
.L08049100: .4byte gBattleUnitA
.L08049104: .4byte 0x0203CD80
.L08049108: .4byte gBattleUnitB
.L0804910C: .4byte 0x0203CCFC
.L08049110: .4byte 0x0203CCF8
.L08049114:
	ldr r5, .L0804914C @ =gBattleUnitA
	movs r4, #0x40
	rsbs r4, r4, #0
	adds r0, r4, #0
	ldrb r1, [r5, #0xb]
	ands r0, r1
	bl sub_804A500
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, .L08049150 @ =gBattleUnitB
	ldrb r0, [r0, #0xb]
	ands r4, r0
	adds r0, r4, #0
	bl sub_804A500
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r1, .L08049154 @ =gBattleSt
	movs r0, #0x40
	ldrb r1, [r1, #1]
	ands r0, r1
	cmp r0, #0
	beq .L08049158
	movs r2, #2
	str r2, [sp, #0x18]
	b .L0804917C
	.align 2, 0
.L0804914C: .4byte gBattleUnitA
.L08049150: .4byte gBattleUnitB
.L08049154: .4byte gBattleSt
.L08049158:
	adds r1, r5, #0
	adds r1, #0x4a
	ldrh r0, [r1]
	cmp r0, #0
	bne .L08049168
	movs r3, #2
	str r3, [sp, #0x18]
	b .L0804917C
.L08049168:
	ldrh r0, [r1]
	bl GetItemIid
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_805F784
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x18]
.L0804917C:
	ldr r1, .L080491D0 @ =0x0203CCF8
	movs r0, #1
	strh r0, [r1, #2]
	strh r0, [r1]
	movs r4, #0
	bl sub_8042578
	cmp r0, #1
	beq .L080491A4
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	beq .L080491A2
	cmp r0, #2
	beq .L080491A2
	cmp r0, #1
	bne .L080491A4
	cmp r6, #1
	bne .L080491A4
.L080491A2:
	movs r4, #1
.L080491A4:
	adds r2, r4, #0
	cmp r2, #1
	bne .L080491E8
	ldr r1, .L080491D4 @ =0x0203CD7C
	ldr r0, .L080491D8 @ =gBattleUnitB
	str r0, [r1]
	str r0, [sp]
	ldr r1, .L080491DC @ =0x0203CD80
	ldr r0, .L080491E0 @ =gBattleUnitA
	str r0, [r1]
	str r0, [sp, #4]
	ldr r0, .L080491E4 @ =0x0203CCFC
	movs r1, #0
	strh r2, [r0]
	strh r1, [r0, #2]
	ldr r7, [sp, #4]
	ldr r3, .L080491D0 @ =0x0203CCF8
	ldr r4, [sp, #0x18]
	cmp r4, #1
	bne .L0804920E
	strh r1, [r3]
	b .L0804920E
	.align 2, 0
.L080491D0: .4byte 0x0203CCF8
.L080491D4: .4byte 0x0203CD7C
.L080491D8: .4byte gBattleUnitB
.L080491DC: .4byte 0x0203CD80
.L080491E0: .4byte gBattleUnitA
.L080491E4: .4byte 0x0203CCFC
.L080491E8:
	ldr r1, .L080492C4 @ =0x0203CD7C
	ldr r0, .L080492C8 @ =gBattleUnitA
	str r0, [r1]
	str r0, [sp]
	ldr r1, .L080492CC @ =0x0203CD80
	ldr r0, .L080492D0 @ =gBattleUnitB
	str r0, [r1]
	str r0, [sp, #4]
	ldr r1, .L080492D4 @ =0x0203CCFC
	movs r2, #0
	strh r2, [r1]
	movs r0, #1
	strh r0, [r1, #2]
	ldr r7, [sp]
	ldr r3, .L080492D8 @ =0x0203CCF8
	ldr r0, [sp, #0x18]
	cmp r0, #1
	bne .L0804920E
	strh r2, [r3, #2]
.L0804920E:
	ldr r1, [sp]
	str r1, [sp, #0x10]
	ldr r2, [sp, #4]
	mov sl, r2
	ldr r4, [r1]
	str r4, [sp, #8]
	ldr r0, [r2]
	str r0, [sp, #0xc]
	movs r1, #0
	mov sb, r1
	mov r8, r1
	ldrh r1, [r3, #2]
	ldrh r2, [r3]
	str r2, [sp, #0x14]
	movs r4, #0
	ldrsh r6, [r3, r4]
	cmp r6, #0
	beq .L0804923A
	ldr r2, [sp, #0x10]
	ldr r0, [r2, #4]
	ldr r0, [r0, #0x30]
	mov r8, r0
.L0804923A:
	lsls r0, r1, #0x10
	asrs r5, r0, #0x10
	str r0, [sp, #0x20]
	cmp r5, #0
	beq .L0804924C
	mov r3, sl
	ldr r0, [r3, #4]
	ldr r0, [r0, #0x30]
	mov sb, r0
.L0804924C:
	cmp r6, #0
	beq .L08049278
	ldr r3, .L080492DC @ =0x0203CD16
	ldr r4, [sp, #0x10]
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	lsls r0, r0, #4
	ldr r2, .L080492E0 @ =gBmSt
	movs r4, #0xc
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	asrs r0, r0, #4
	strh r0, [r3]
	ldr r1, [sp, #0x10]
	movs r0, #0xf
	ldrsb r0, [r1, r0]
	lsls r0, r0, #4
	movs r4, #0xe
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	asrs r0, r0, #4
	strh r0, [r3, #2]
.L08049278:
	cmp r5, #0
	beq .L080492A4
	ldr r3, .L080492DC @ =0x0203CD16
	mov r1, sl
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	lsls r0, r0, #4
	ldr r2, .L080492E0 @ =gBmSt
	movs r4, #0xc
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	asrs r0, r0, #4
	strh r0, [r3, #4]
	mov r1, sl
	movs r0, #0xf
	ldrsb r0, [r1, r0]
	lsls r0, r0, #4
	movs r4, #0xe
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	asrs r0, r0, #4
	strh r0, [r3, #6]
.L080492A4:
	ldr r4, .L080492E4 @ =0x0203CD14
	ldrh r0, [r4]
	cmp r0, #4
	beq .L08049372
	adds r0, r7, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemAttributes
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq .L080492E8
	movs r0, #2
	strh r0, [r4]
	b .L0804936A
	.align 2, 0
.L080492C4: .4byte 0x0203CD7C
.L080492C8: .4byte gBattleUnitA
.L080492CC: .4byte 0x0203CD80
.L080492D0: .4byte gBattleUnitB
.L080492D4: .4byte 0x0203CCFC
.L080492D8: .4byte 0x0203CCF8
.L080492DC: .4byte 0x0203CD16
.L080492E0: .4byte gBmSt
.L080492E4: .4byte 0x0203CD14
.L080492E8:
	movs r0, #3
	strh r0, [r4]
	adds r0, r6, r5
	cmp r0, #2
	bne .L0804936A
	ldr r0, .L0804930C @ =0x0203CD16
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #4
	ldrsh r2, [r0, r3]
	subs r1, r1, r2
	adds r2, r0, #0
	cmp r1, #0
	blt .L08049310
	ldrh r4, [r2]
	ldrh r1, [r2, #4]
	subs r0, r4, r1
	b .L08049316
	.align 2, 0
.L0804930C: .4byte 0x0203CD16
.L08049310:
	ldrh r3, [r2, #4]
	ldrh r4, [r2]
	subs r0, r3, r4
.L08049316:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r3, r0, #0
	movs r1, #2
	ldrsh r0, [r2, r1]
	movs r4, #6
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	cmp r0, #0
	blt .L08049330
	ldrh r1, [r2, #2]
	ldrh r4, [r2, #6]
	b .L08049334
.L08049330:
	ldrh r1, [r2, #6]
	ldrh r4, [r2, #2]
.L08049334:
	subs r0, r1, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, r1, r0
	cmp r0, #1
	bgt .L08049354
	ldr r1, .L08049350 @ =0x0203CD14
	movs r0, #0
	b .L08049368
	.align 2, 0
.L08049350: .4byte 0x0203CD14
.L08049354:
	cmp r0, #3
	bgt .L08049364
	ldr r1, .L08049360 @ =0x0203CD14
	movs r0, #1
	b .L08049368
	.align 2, 0
.L08049360: .4byte 0x0203CD14
.L08049364:
	ldr r1, .L080493A0 @ =0x0203CD14
	movs r0, #2
.L08049368:
	strh r0, [r1]
.L0804936A:
	ldr r0, .L080493A0 @ =0x0203CD14
	ldrh r0, [r0]
	cmp r0, #4
	bne .L080493AC
.L08049372:
	ldr r0, [sp]
	adds r0, #0x48
	ldrh r1, [r0]
	mov r0, r8
	bl sub_8049BAC
	ldr r5, .L080493A4 @ =0x0203CD76
	ldr r4, .L080493A8 @ =0x0203CD00
	strh r0, [r4]
	strh r0, [r5]
	ldr r0, [sp, #4]
	adds r0, #0x48
	ldrh r1, [r0]
	mov r0, sb
	bl sub_8049BAC
	strh r0, [r4, #2]
	strh r0, [r5, #2]
	ldr r0, [sp, #0x14]
	lsls r0, r0, #0x10
	str r0, [sp, #0x1c]
	b .L080493E4
	.align 2, 0
.L080493A0: .4byte 0x0203CD14
.L080493A4: .4byte 0x0203CD76
.L080493A8: .4byte 0x0203CD00
.L080493AC:
	ldr r1, [sp, #0x14]
	lsls r0, r1, #0x10
	str r0, [sp, #0x1c]
	cmp r0, #0
	beq .L080493CA
	ldr r0, [sp]
	adds r0, #0x4a
	ldrh r1, [r0]
	mov r0, r8
	bl sub_8049BAC
	ldr r2, .L08049514 @ =0x0203CD76
	ldr r1, .L08049518 @ =0x0203CD00
	strh r0, [r1]
	strh r0, [r2]
.L080493CA:
	ldr r2, [sp, #0x20]
	cmp r2, #0
	beq .L080493E4
	ldr r0, [sp, #4]
	adds r0, #0x4a
	ldrh r1, [r0]
	mov r0, sb
	bl sub_8049BAC
	ldr r2, .L08049514 @ =0x0203CD76
	ldr r1, .L08049518 @ =0x0203CD00
	strh r0, [r1, #2]
	strh r0, [r2, #2]
.L080493E4:
	ldr r3, [sp, #0x1c]
	asrs r7, r3, #0x10
	cmp r7, #0
	beq .L080493F6
	ldr r0, [sp, #0x10]
	bl sub_804A49C
	ldr r1, .L0804951C @ =0x0203CD04
	strh r0, [r1]
.L080493F6:
	ldr r4, [sp, #0x20]
	asrs r4, r4, #0x10
	mov r8, r4
	cmp r4, #0
	beq .L0804940A
	mov r0, sl
	bl sub_804A49C
	ldr r1, .L0804951C @ =0x0203CD04
	strh r0, [r1, #2]
.L0804940A:
	cmp r7, #0
	beq .L08049422
	ldr r0, .L08049514 @ =0x0203CD76
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [sp]
	adds r1, #0x4a
	ldrh r1, [r1]
	bl sub_804A4B8
	ldr r1, .L08049520 @ =0x0203CD90
	str r0, [r1]
.L08049422:
	mov r2, r8
	cmp r2, #0
	beq .L0804943C
	ldr r0, .L08049514 @ =0x0203CD76
	movs r3, #2
	ldrsh r0, [r0, r3]
	ldr r1, [sp, #4]
	adds r1, #0x4a
	ldrh r1, [r1]
	bl sub_804A4B8
	ldr r1, .L08049520 @ =0x0203CD90
	str r0, [r1, #4]
.L0804943C:
	ldr r4, .L08049524 @ =0x0203CDC0
	mov sb, r4
	ldr r2, [sp]
	adds r2, #0x53
	ldrb r0, [r2]
	strh r0, [r4]
	ldr r6, [sp, #4]
	adds r6, #0x53
	ldrb r0, [r6]
	strh r0, [r4, #2]
	ldr r5, .L08049528 @ =0x0203CD10
	ldr r1, .L0804952C @ =0x0000FFFF
	adds r0, r1, #0
	ldrh r1, [r5, #2]
	orrs r1, r0
	strh r1, [r5, #2]
	ldrh r3, [r5]
	orrs r0, r3
	strh r0, [r5]
	cmp r7, #0
	beq .L0804947E
	ldrb r4, [r2]
	ldr r0, .L08049530 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterInfo
	ldrb r1, [r0, #0x12]
	adds r0, r4, #0
	bl sub_8049C5C
	strh r0, [r5]
.L0804947E:
	mov r4, r8
	cmp r4, #0
	beq .L0804949C
	ldrb r4, [r6]
	ldr r0, .L08049530 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterInfo
	ldrb r1, [r0, #0x12]
	adds r0, r4, #0
	bl sub_8049C5C
	strh r0, [r5, #2]
.L0804949C:
	ldr r1, .L08049534 @ =gBmSt
	movs r0, #0x40
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L080494EA
	movs r0, #0x30
	mov r1, sb
	strh r0, [r1]
	strh r0, [r1, #2]
	cmp r7, #0
	beq .L080494CA
	ldr r0, .L08049530 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterInfo
	ldrb r1, [r0, #0x12]
	movs r0, #0x30
	bl sub_8049C5C
	strh r0, [r5]
.L080494CA:
	mov r2, r8
	cmp r2, #0
	beq .L080494EA
	mov r3, sb
	ldrh r4, [r3, #2]
	ldr r0, .L08049530 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterInfo
	ldrb r1, [r0, #0x12]
	adds r0, r4, #0
	bl sub_8049C5C
	strh r0, [r5, #2]
.L080494EA:
	ldr r0, .L08049538 @ =0x0203CD14
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt .L08049502
	cmp r0, #3
	ble .L08049502
	cmp r0, #4
	bne .L08049502
	ldr r1, .L08049528 @ =0x0203CD10
	ldrh r0, [r1, #2]
	strh r0, [r1]
.L08049502:
	ldr r0, .L08049530 @ =gPlaySt
	ldrb r0, [r0, #0x15]
	cmp r0, #2
	bgt .L08049540
	cmp r0, #1
	blt .L08049540
	ldr r1, .L0804953C @ =0x0203CCF6
	movs r0, #1
	b .L08049544
	.align 2, 0
.L08049514: .4byte 0x0203CD76
.L08049518: .4byte 0x0203CD00
.L0804951C: .4byte 0x0203CD04
.L08049520: .4byte 0x0203CD90
.L08049524: .4byte 0x0203CDC0
.L08049528: .4byte 0x0203CD10
.L0804952C: .4byte 0x0000FFFF
.L08049530: .4byte gPlaySt
.L08049534: .4byte gBmSt
.L08049538: .4byte 0x0203CD14
.L0804953C: .4byte 0x0203CCF6
.L08049540:
	ldr r1, .L080495C0 @ =0x0203CCF6
	movs r0, #0
.L08049544:
	strh r0, [r1]
	ldr r0, [sp, #0x1c]
	asrs r4, r0, #0x10
	cmp r4, #0
	beq .L0804955C
	ldr r0, .L080495C4 @ =0x0203CDC4
	ldr r2, [sp, #0x10]
	ldr r1, [r2, #4]
	ldrb r1, [r1, #0x11]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r0]
.L0804955C:
	ldr r3, [sp, #0x20]
	asrs r5, r3, #0x10
	cmp r5, #0
	beq .L08049572
	ldr r0, .L080495C4 @ =0x0203CDC4
	mov r2, sl
	ldr r1, [r2, #4]
	ldrb r1, [r1, #0x11]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	strh r1, [r0, #2]
.L08049572:
	cmp r4, #0
	beq .L0804958E
	ldr r1, .L080495C8 @ =0x0203CDA0
	ldr r0, [sp]
	adds r0, #0x6e
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	ldr r1, .L080495CC @ =0x0203CDA4
	ldr r3, [sp, #0x10]
	movs r0, #0x10
	ldrsb r0, [r3, r0]
	strh r0, [r1]
.L0804958E:
	cmp r5, #0
	beq .L080495AA
	ldr r1, .L080495C8 @ =0x0203CDA0
	ldr r0, [sp, #4]
	adds r0, #0x6e
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #2]
	ldr r1, .L080495CC @ =0x0203CDA4
	mov r2, sl
	movs r0, #0x10
	ldrsb r0, [r2, r0]
	strh r0, [r1, #2]
.L080495AA:
	bl sub_8049F1C
	ldr r0, .L080495D0 @ =0x0203CD14
	ldrh r0, [r0]
	cmp r0, #4
	bne .L080495D8
	ldr r1, .L080495D4 @ =0x0203CD0C
	movs r0, #1
	strh r0, [r1, #2]
	strh r0, [r1]
	b .L08049634
	.align 2, 0
.L080495C0: .4byte 0x0203CCF6
.L080495C4: .4byte 0x0203CDC4
.L080495C8: .4byte 0x0203CDA0
.L080495CC: .4byte 0x0203CDA4
.L080495D0: .4byte 0x0203CD14
.L080495D4: .4byte 0x0203CD0C
.L080495D8:
	cmp r4, #0
	beq .L080495F0
	ldr r3, [sp, #0x10]
	ldr r0, [r3, #4]
	ldrb r0, [r0, #4]
	ldr r1, [sp]
	adds r1, #0x4a
	ldrh r1, [r1]
	bl sub_8049D98
	ldr r1, .L08049918 @ =0x0203CD0C
	strh r0, [r1]
.L080495F0:
	cmp r5, #0
	beq .L08049608
	mov r4, sl
	ldr r0, [r4, #4]
	ldrb r0, [r0, #4]
	ldr r1, [sp, #4]
	adds r1, #0x4a
	ldrh r1, [r1]
	bl sub_8049D98
	ldr r1, .L08049918 @ =0x0203CD0C
	strh r0, [r1, #2]
.L08049608:
	ldr r1, .L0804991C @ =gBattleSt
	movs r0, #0x40
	ldrb r1, [r1, #1]
	ands r0, r1
	cmp r0, #0
	beq .L08049634
	mov r1, sl
	ldr r0, [r1, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x36
	bne .L08049624
	ldr r1, .L08049918 @ =0x0203CD0C
	movs r0, #0xe
	strh r0, [r1, #2]
.L08049624:
	mov r2, sl
	ldr r0, [r2, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x37
	bne .L08049634
	ldr r1, .L08049918 @ =0x0203CD0C
	movs r0, #0xf
	strh r0, [r1, #2]
.L08049634:
	ldr r3, [sp, #0x1c]
	asrs r5, r3, #0x10
	cmp r5, #0
	beq .L0804964A
	ldr r0, .L08049918 @ =0x0203CD0C
	ldr r1, [sp]
	adds r1, #0x4a
	ldrh r2, [r1]
	movs r1, #0
	bl sub_8049E9C
.L0804964A:
	ldr r4, [sp, #0x20]
	cmp r4, #0
	beq .L0804965E
	ldr r0, .L08049920 @ =0x0203CD0E
	ldr r1, [sp, #4]
	adds r1, #0x4a
	ldrh r2, [r1]
	movs r1, #1
	bl sub_8049E9C
.L0804965E:
	movs r0, #0
	bl sub_80589FC
	movs r4, #0
	strh r4, [r0]
	movs r0, #1
	bl sub_80589FC
	strh r4, [r0]
	ldr r0, .L08049924 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt .L08049730
	cmp r0, #2
	bgt .L08049730
	cmp r5, #0
	beq .L0804969A
	ldr r0, [sp]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	adds r4, r0, #0
	cmp r4, #0x53
	bne .L0804969A
	movs r0, #0
	bl sub_80589FC
	strh r4, [r0]
.L0804969A:
	ldr r2, [sp, #0x20]
	cmp r2, #0
	beq .L080496B8
	ldr r0, [sp, #4]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	adds r4, r0, #0
	cmp r4, #0x53
	bne .L080496B8
	movs r0, #1
	bl sub_80589FC
	strh r4, [r0]
.L080496B8:
	ldr r3, [sp, #0x1c]
	cmp r3, #0
	beq .L080496D6
	ldr r0, [sp]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	adds r4, r0, #0
	cmp r4, #0x54
	bne .L080496D6
	movs r0, #0
	bl sub_80589FC
	strh r4, [r0]
.L080496D6:
	ldr r4, [sp, #0x20]
	cmp r4, #0
	beq .L080496F4
	ldr r0, [sp, #4]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	adds r4, r0, #0
	cmp r4, #0x54
	bne .L080496F4
	movs r0, #1
	bl sub_80589FC
	strh r4, [r0]
.L080496F4:
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq .L08049712
	ldr r0, [sp]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	adds r4, r0, #0
	cmp r4, #0x70
	bne .L08049712
	movs r0, #0
	bl sub_80589FC
	strh r4, [r0]
.L08049712:
	ldr r1, [sp, #0x20]
	cmp r1, #0
	beq .L08049730
	ldr r0, [sp, #4]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	adds r4, r0, #0
	cmp r4, #0x70
	bne .L08049730
	movs r0, #1
	bl sub_80589FC
	strh r4, [r0]
.L08049730:
	ldr r2, [sp, #0x1c]
	asrs r5, r2, #0x10
	cmp r5, #0
	beq .L0804974A
	movs r0, #0x40
	rsbs r0, r0, #0
	ldr r3, [sp, #0x10]
	ldrb r3, [r3, #0xb]
	ands r0, r3
	bl sub_804A500
	ldr r1, .L08049928 @ =0x0203CD08
	strh r0, [r1]
.L0804974A:
	ldr r0, [sp, #0x20]
	asrs r4, r0, #0x10
	cmp r4, #0
	beq .L08049764
	movs r0, #0x40
	rsbs r0, r0, #0
	mov r1, sl
	ldrb r1, [r1, #0xb]
	ands r0, r1
	bl sub_804A500
	ldr r1, .L08049928 @ =0x0203CD08
	strh r0, [r1, #2]
.L08049764:
	ldr r1, .L0804992C @ =0x0203CD84
	movs r3, #0
	strb r3, [r1, #1]
	strb r3, [r1]
	cmp r5, #0
	beq .L08049776
	ldr r2, [sp, #8]
	ldrb r0, [r2, #4]
	strb r0, [r1]
.L08049776:
	cmp r4, #0
	beq .L08049780
	ldr r2, [sp, #0xc]
	ldrb r0, [r2, #4]
	strb r0, [r1, #1]
.L08049780:
	ldr r0, .L08049930 @ =0x0203CDAC
	mov r8, r0
	cmp r5, #0
	beq .L08049792
	ldr r0, [sp]
	adds r0, #0x62
	ldrh r0, [r0]
	mov r1, r8
	strh r0, [r1]
.L08049792:
	cmp r4, #0
	beq .L080497A0
	ldr r0, [sp, #4]
	adds r0, #0x62
	ldrh r0, [r0]
	mov r2, r8
	strh r0, [r2, #2]
.L080497A0:
	mov r4, r8
	ldrh r0, [r4]
	adds r1, r0, #0
	cmp r1, #0xff
	bne .L080497AE
	ldr r0, .L08049934 @ =0x0000FFFF
	strh r0, [r4]
.L080497AE:
	mov r2, r8
	ldrh r0, [r2, #2]
	adds r4, r0, #0
	cmp r4, #0xff
	bne .L080497BC
	ldr r0, .L08049934 @ =0x0000FFFF
	strh r0, [r2, #2]
.L080497BC:
	cmp r5, #0
	beq .L080497E4
	ldr r2, .L08049938 @ =0x0203CDB0
	ldr r1, [sp]
	adds r1, #0x58
	ldr r0, [sp, #4]
	adds r0, #0x5a
	ldrh r4, [r1]
	ldrh r0, [r0]
	subs r0, r4, r0
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L080497DA
	strh r3, [r2]
.L080497DA:
	ldrh r1, [r1]
	cmp r1, #0xff
	bne .L080497E4
	ldr r0, .L08049934 @ =0x0000FFFF
	strh r0, [r2]
.L080497E4:
	ldr r0, [sp, #0x20]
	cmp r0, #0
	beq .L08049810
	ldr r2, .L08049938 @ =0x0203CDB0
	ldr r1, [sp, #4]
	adds r1, #0x58
	ldr r0, [sp]
	adds r0, #0x5a
	ldrh r3, [r1]
	ldrh r0, [r0]
	subs r0, r3, r0
	strh r0, [r2, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L08049806
	movs r0, #0
	strh r0, [r2, #2]
.L08049806:
	ldrh r1, [r1]
	cmp r1, #0xff
	bne .L08049810
	ldr r0, .L08049934 @ =0x0000FFFF
	strh r0, [r2, #2]
.L08049810:
	ldr r4, [sp, #0x1c]
	asrs r7, r4, #0x10
	ldr r3, .L0804993C @ =0x0203CDB4
	cmp r7, #0
	beq .L08049822
	ldr r0, [sp]
	adds r0, #0x68
	ldrh r0, [r0]
	strh r0, [r3]
.L08049822:
	ldr r0, [sp, #0x20]
	asrs r6, r0, #0x10
	cmp r6, #0
	beq .L08049832
	ldr r0, [sp, #4]
	adds r0, #0x68
	ldrh r0, [r0]
	strh r0, [r3, #2]
.L08049832:
	adds r1, r3, #0
	ldrh r0, [r1]
	cmp r0, #0xff
	bne .L0804983E
	ldr r0, .L08049934 @ =0x0000FFFF
	strh r0, [r1]
.L0804983E:
	ldrh r0, [r1, #2]
	cmp r0, #0xff
	bne .L08049848
	ldr r0, .L08049934 @ =0x0000FFFF
	strh r0, [r1, #2]
.L08049848:
	ldr r0, .L08049924 @ =0x0203CD14
	ldrh r0, [r0]
	cmp r0, #4
	bne .L0804986A
	ldr r2, .L08049934 @ =0x0000FFFF
	adds r1, r2, #0
	mov r4, r8
	ldrh r0, [r4, #2]
	orrs r0, r1
	strh r0, [r4, #2]
	ldr r2, .L08049938 @ =0x0203CDB0
	ldrh r0, [r2, #2]
	orrs r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #2]
	orrs r1, r0
	strh r1, [r3, #2]
.L0804986A:
	cmp r7, #0
	beq .L0804987C
	ldr r1, .L08049940 @ =0x0203CDB8
	ldr r0, [sp]
	adds r0, #0x6d
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
.L0804987C:
	cmp r6, #0
	beq .L0804988E
	ldr r1, .L08049940 @ =0x0203CDB8
	ldr r0, [sp, #4]
	adds r0, #0x6d
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #2]
.L0804988E:
	cmp r7, #0
	beq .L080498A0
	ldr r1, .L08049944 @ =0x0203CDBC
	ldr r0, [sp]
	adds r0, #0x6a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
.L080498A0:
	cmp r6, #0
	beq .L080498B2
	ldr r1, .L08049944 @ =0x0203CDBC
	ldr r0, [sp, #4]
	adds r0, #0x6a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #2]
.L080498B2:
	ldr r1, .L08049948 @ =0x0203CDC8
	movs r5, #0
	strh r5, [r1, #2]
	strh r5, [r1]
	cmp r7, #0
	beq .L080498CA
	ldr r0, [sp]
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
.L080498CA:
	cmp r6, #0
	beq .L080498DA
	ldr r0, [sp, #4]
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #2]
.L080498DA:
	ldr r4, .L0804994C @ =0x0203CDCC
	strh r5, [r4, #2]
	strh r5, [r4]
	cmp r7, #0
	beq .L080498F6
	ldr r0, [sp]
	adds r0, #0x48
	ldrh r0, [r0]
	mov r1, sl
	bl IsItemEffectiveAgainst
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r4]
.L080498F6:
	cmp r6, #0
	beq .L0804990C
	ldr r0, [sp, #4]
	adds r0, #0x48
	ldrh r0, [r0]
	ldr r1, [sp, #0x10]
	bl IsItemEffectiveAgainst
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r4, #2]
.L0804990C:
	ldr r4, .L08049950 @ =0x0203CD98
	str r5, [r4, #4]
	str r5, [r4]
	cmp r7, #0
	b .L08049954
	.align 2, 0
.L08049918: .4byte 0x0203CD0C
.L0804991C: .4byte gBattleSt
.L08049920: .4byte 0x0203CD0E
.L08049924: .4byte 0x0203CD14
.L08049928: .4byte 0x0203CD08
.L0804992C: .4byte 0x0203CD84
.L08049930: .4byte 0x0203CDAC
.L08049934: .4byte 0x0000FFFF
.L08049938: .4byte 0x0203CDB0
.L0804993C: .4byte 0x0203CDB4
.L08049940: .4byte 0x0203CDB8
.L08049944: .4byte 0x0203CDBC
.L08049948: .4byte 0x0203CDC8
.L0804994C: .4byte 0x0203CDCC
.L08049950: .4byte 0x0203CD98
.L08049954:
	beq .L08049994
	ldr r0, [sp]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	cmp r0, #0x32
	bgt .L08049994
	cmp r0, #0x30
	blt .L08049994
	ldr r1, [sp, #0x10]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x11
	beq .L08049980
	cmp r0, #0x11
	ble .L08049994
	cmp r0, #0x12
	beq .L08049988
	cmp r0, #0x13
	beq .L08049990
	b .L08049994
.L08049980:
	ldr r0, .L08049984 @ =gUnk_08113FF8
	b .L08049992
	.align 2, 0
.L08049984: .4byte gUnk_08113FF8
.L08049988:
	ldr r0, .L0804998C @ =gUnk_0811446C
	b .L08049992
	.align 2, 0
.L0804998C: .4byte gUnk_0811446C
.L08049990:
	ldr r0, .L080499C4 @ =gUnk_0811490C
.L08049992:
	str r0, [r4]
.L08049994:
	ldr r2, [sp, #0x20]
	cmp r2, #0
	beq .L080499EE
	ldr r0, [sp, #4]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	cmp r0, #0x32
	bgt .L080499EE
	cmp r0, #0x30
	blt .L080499EE
	mov r3, sl
	ldr r0, [r3, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x11
	beq .L080499C8
	cmp r0, #0x11
	ble .L080499EE
	cmp r0, #0x12
	beq .L080499D8
	cmp r0, #0x13
	beq .L080499E8
	b .L080499EE
	.align 2, 0
.L080499C4: .4byte gUnk_0811490C
.L080499C8:
	ldr r1, .L080499D0 @ =0x0203CD98
	ldr r0, .L080499D4 @ =gUnk_08113FF8
	b .L080499EC
	.align 2, 0
.L080499D0: .4byte 0x0203CD98
.L080499D4: .4byte gUnk_08113FF8
.L080499D8:
	ldr r1, .L080499E0 @ =0x0203CD98
	ldr r0, .L080499E4 @ =gUnk_0811446C
	b .L080499EC
	.align 2, 0
.L080499E0: .4byte 0x0203CD98
.L080499E4: .4byte gUnk_0811446C
.L080499E8:
	ldr r1, .L08049A08 @ =0x0203CD98
	ldr r0, .L08049A0C @ =gUnk_0811490C
.L080499EC:
	str r0, [r1, #4]
.L080499EE:
	bl sub_8042578
	cmp r0, #1
	beq .L08049A00
	ldr r0, .L08049A10 @ =gPlaySt
	ldrb r0, [r0, #0x1c]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq .L08049A18
.L08049A00:
	ldr r1, .L08049A14 @ =0x0203CDD0
	movs r0, #1
	b .L08049A1C
	.align 2, 0
.L08049A08: .4byte 0x0203CD98
.L08049A0C: .4byte gUnk_0811490C
.L08049A10: .4byte gPlaySt
.L08049A14: .4byte 0x0203CDD0
.L08049A18:
	ldr r1, .L08049A40 @ =0x0203CDD0
	movs r0, #0
.L08049A1C:
	strh r0, [r1, #2]
	strh r0, [r1]
	ldr r5, .L08049A44 @ =0x0203CCF2
	movs r0, #0
	strh r0, [r5]
	bl GetBattleAnimType
	cmp r0, #3
	bne .L08049A6A
	ldr r0, .L08049A48 @ =0x0203CCF8
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq .L08049A50
	ldr r0, .L08049A4C @ =0x0203CDC0
	ldrh r4, [r0]
	b .L08049A54
	.align 2, 0
.L08049A40: .4byte 0x0203CDD0
.L08049A44: .4byte 0x0203CCF2
.L08049A48: .4byte 0x0203CCF8
.L08049A4C: .4byte 0x0203CDC0
.L08049A50:
	ldr r0, .L08049B78 @ =0x0203CDC0
	ldrh r4, [r0, #2]
.L08049A54:
	ldr r0, .L08049B7C @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterInfo
	ldrb r1, [r0, #0x12]
	adds r0, r4, #0
	bl sub_8049CFC
	strh r0, [r5]
.L08049A6A:
	movs r4, #0
	bl GetBattleAnimType
	cmp r0, #0
	bne .L08049A76
	movs r4, #1
.L08049A76:
	bl GetBattleAnimType
	cmp r0, #3
	bne .L08049A80
	movs r4, #1
.L08049A80:
	bl GetBattleAnimType
	cmp r0, #1
	bne .L08049AC8
	ldr r0, .L08049B80 @ =0x0203CD14
	ldrh r0, [r0]
	cmp r0, #4
	bne .L08049A92
	movs r4, #1
.L08049A92:
	bl sub_804C500
	cmp r0, #1
	bne .L08049A9C
	movs r4, #1
.L08049A9C:
	ldr r1, [sp, #0x10]
	ldr r0, [r1]
	ldrb r0, [r0, #4]
	cmp r0, #0x64
	bne .L08049AB2
	ldr r0, .L08049B84 @ =0x0203CD08
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq .L08049AB2
	movs r4, #1
.L08049AB2:
	mov r3, sl
	ldr r0, [r3]
	ldrb r0, [r0, #4]
	cmp r0, #0x64
	bne .L08049AC8
	ldr r0, .L08049B84 @ =0x0203CD08
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08049AC8
	movs r4, #1
.L08049AC8:
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldrb r1, [r0, #4]
	cmp r1, #0x42
	beq .L08049B72
	mov r3, sl
	ldr r0, [r3]
	ldrb r0, [r0, #4]
	cmp r0, #0x42
	beq .L08049B72
	ldr r0, [sp, #0x18]
	cmp r0, #1
	beq .L08049AE6
	cmp r1, #0x66
	beq .L08049B98
.L08049AE6:
	cmp r4, #0
	beq .L08049B72
	ldr r0, .L08049B88 @ =0x0203CCF8
	adds r3, r0, #0
	ldrh r1, [r3]
	cmp r1, #1
	bne .L08049B30
	ldr r1, [sp, #0x10]
	adds r1, #0x2e
	movs r0, #0xf
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #4
	beq .L08049B72
	ldr r0, .L08049B8C @ =0x0203CD76
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, r2
	beq .L08049B72
	ldr r0, .L08049B90 @ =0x0203CD0C
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L08049B72
	ldr r0, .L08049B94 @ =0x0203CD10
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, r2
	beq .L08049B72
	ldr r0, .L08049B78 @ =0x0203CDC0
	ldrh r0, [r0]
	cmp r0, #0x1b
	beq .L08049B72
.L08049B30:
	ldrh r3, [r3, #2]
	cmp r3, #1
	bne .L08049B98
	mov r1, sl
	adds r1, #0x2e
	movs r0, #0xf
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #4
	beq .L08049B72
	ldr r0, .L08049B8C @ =0x0203CD76
	movs r2, #2
	ldrsh r0, [r0, r2]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, r2
	beq .L08049B72
	ldr r0, .L08049B90 @ =0x0203CD0C
	movs r3, #2
	ldrsh r1, [r0, r3]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L08049B72
	ldr r0, .L08049B94 @ =0x0203CD10
	movs r4, #2
	ldrsh r0, [r0, r4]
	cmp r0, r2
	beq .L08049B72
	ldr r0, .L08049B78 @ =0x0203CDC0
	ldrh r0, [r0, #2]
	cmp r0, #0x1b
	bne .L08049B98
.L08049B72:
	movs r0, #0
	b .L08049B9A
	.align 2, 0
.L08049B78: .4byte 0x0203CDC0
.L08049B7C: .4byte gPlaySt
.L08049B80: .4byte 0x0203CD14
.L08049B84: .4byte 0x0203CD08
.L08049B88: .4byte 0x0203CCF8
.L08049B8C: .4byte 0x0203CD76
.L08049B90: .4byte 0x0203CD0C
.L08049B94: .4byte 0x0203CD10
.L08049B98:
	movs r0, #1
.L08049B9A:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8049BAC
sub_8049BAC: @ 0x08049BAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	movs r0, #0
	mov sb, r0
	mov r2, sl
	cmp r2, #0
	beq .L08049BD4
	mov r0, r8
	bl GetItemKind
	cmp r0, #9
	bne .L08049BDC
.L08049BD4:
	ldr r0, .L08049BD8 @ =0x0000FFFF
	b .L08049C4A
	.align 2, 0
.L08049BD8: .4byte 0x0000FFFF
.L08049BDC:
	mov r3, r8
	cmp r3, #0
	bne .L08049BE6
	movs r1, #9
	b .L08049BF0
.L08049BE6:
	mov r0, r8
	bl GetItemKind
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
.L08049BF0:
	movs r6, #0
	movs r7, #0
.L08049BF4:
	mov r5, sl
	b .L08049C32
.L08049BF8:
	cmp r6, #0
	bne .L08049C00
	cmp r0, #0xff
	bhi .L08049C30
.L08049C00:
	cmp r6, #1
	bne .L08049C0A
	ldrh r0, [r5]
	cmp r0, #0xff
	bls .L08049C30
.L08049C0A:
	ldrh r4, [r5]
	mov r0, r8
	str r1, [sp]
	bl GetItemIid
	ldr r1, [sp]
	cmp r4, r0
	beq .L08049C24
	ldrh r2, [r5]
	ldr r3, .L08049C2C @ =0xFFFFFF00
	adds r0, r2, r3
	cmp r0, r1
	bne .L08049C30
.L08049C24:
	ldrh r5, [r5, #2]
	mov sb, r5
	movs r7, #1
	b .L08049C38
	.align 2, 0
.L08049C2C: .4byte 0xFFFFFF00
.L08049C30:
	adds r5, #4
.L08049C32:
	ldrh r0, [r5]
	cmp r0, #0
	bne .L08049BF8
.L08049C38:
	cmp r7, #1
	beq .L08049C42
	adds r6, #1
	cmp r6, #1
	ble .L08049BF4
.L08049C42:
	mov r0, sb
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L08049C4A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8049C5C
sub_8049C5C: @ 0x08049C5C
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #9
	bhi .L08049CE8
	lsls r0, r0, #2
	ldr r1, .L08049C74 @ =.L08049C78
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08049C74: .4byte .L08049C78
.L08049C78: @ jump table
	.4byte .L08049CE8 @ case 0
	.4byte .L08049CA0 @ case 1
	.4byte .L08049CA8 @ case 2
	.4byte .L08049CB0 @ case 3
	.4byte .L08049CB8 @ case 4
	.4byte .L08049CC0 @ case 5
	.4byte .L08049CC8 @ case 6
	.4byte .L08049CD0 @ case 7
	.4byte .L08049CD8 @ case 8
	.4byte .L08049CE0 @ case 9
.L08049CA0:
	ldr r0, .L08049CA4 @ =gUnk_0860CC42
	b .L08049CEA
	.align 2, 0
.L08049CA4: .4byte gUnk_0860CC42
.L08049CA8:
	ldr r0, .L08049CAC @ =gUnk_0860CC75
	b .L08049CEA
	.align 2, 0
.L08049CAC: .4byte gUnk_0860CC75
.L08049CB0:
	ldr r0, .L08049CB4 @ =gUnk_0860CCA8
	b .L08049CEA
	.align 2, 0
.L08049CB4: .4byte gUnk_0860CCA8
.L08049CB8:
	ldr r0, .L08049CBC @ =gUnk_0860CCDB
	b .L08049CEA
	.align 2, 0
.L08049CBC: .4byte gUnk_0860CCDB
.L08049CC0:
	ldr r0, .L08049CC4 @ =gUnk_0860CD0E
	b .L08049CEA
	.align 2, 0
.L08049CC4: .4byte gUnk_0860CD0E
.L08049CC8:
	ldr r0, .L08049CCC @ =gUnk_0860CD41
	b .L08049CEA
	.align 2, 0
.L08049CCC: .4byte gUnk_0860CD41
.L08049CD0:
	ldr r0, .L08049CD4 @ =gUnk_0860CD74
	b .L08049CEA
	.align 2, 0
.L08049CD4: .4byte gUnk_0860CD74
.L08049CD8:
	ldr r0, .L08049CDC @ =gUnk_0860CDA7
	b .L08049CEA
	.align 2, 0
.L08049CDC: .4byte gUnk_0860CDA7
.L08049CE0:
	ldr r0, .L08049CE4 @ =gUnk_0860CDDA
	b .L08049CEA
	.align 2, 0
.L08049CE4: .4byte gUnk_0860CDDA
.L08049CE8:
	ldr r0, .L08049CF8 @ =gUnk_0860CC0F
.L08049CEA:
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	bx lr
	.align 2, 0
.L08049CF8: .4byte gUnk_0860CC0F

	thumb_func_start sub_8049CFC
sub_8049CFC: @ 0x08049CFC
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #9
	bhi .L08049D88
	lsls r0, r0, #2
	ldr r1, .L08049D14 @ =.L08049D18
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08049D14: .4byte .L08049D18
.L08049D18: @ jump table
	.4byte .L08049D88 @ case 0
	.4byte .L08049D40 @ case 1
	.4byte .L08049D48 @ case 2
	.4byte .L08049D50 @ case 3
	.4byte .L08049D58 @ case 4
	.4byte .L08049D60 @ case 5
	.4byte .L08049D68 @ case 6
	.4byte .L08049D70 @ case 7
	.4byte .L08049D78 @ case 8
	.4byte .L08049D80 @ case 9
.L08049D40:
	ldr r0, .L08049D44 @ =gUnk_0860CE40
	b .L08049D8A
	.align 2, 0
.L08049D44: .4byte gUnk_0860CE40
.L08049D48:
	ldr r0, .L08049D4C @ =gUnk_0860CE73
	b .L08049D8A
	.align 2, 0
.L08049D4C: .4byte gUnk_0860CE73
.L08049D50:
	ldr r0, .L08049D54 @ =gUnk_0860CEA6
	b .L08049D8A
	.align 2, 0
.L08049D54: .4byte gUnk_0860CEA6
.L08049D58:
	ldr r0, .L08049D5C @ =gUnk_0860CED9
	b .L08049D8A
	.align 2, 0
.L08049D5C: .4byte gUnk_0860CED9
.L08049D60:
	ldr r0, .L08049D64 @ =gUnk_0860CF0C
	b .L08049D8A
	.align 2, 0
.L08049D64: .4byte gUnk_0860CF0C
.L08049D68:
	ldr r0, .L08049D6C @ =gUnk_0860CF3F
	b .L08049D8A
	.align 2, 0
.L08049D6C: .4byte gUnk_0860CF3F
.L08049D70:
	ldr r0, .L08049D74 @ =gUnk_0860CF72
	b .L08049D8A
	.align 2, 0
.L08049D74: .4byte gUnk_0860CF72
.L08049D78:
	ldr r0, .L08049D7C @ =gUnk_0860CFA5
	b .L08049D8A
	.align 2, 0
.L08049D7C: .4byte gUnk_0860CFA5
.L08049D80:
	ldr r0, .L08049D84 @ =gUnk_0860CFD8
	b .L08049D8A
	.align 2, 0
.L08049D84: .4byte gUnk_0860CFD8
.L08049D88:
	ldr r0, .L08049D94 @ =gUnk_0860CE0D
.L08049D8A:
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bx lr
	.align 2, 0
.L08049D94: .4byte gUnk_0860CE0D

	thumb_func_start sub_8049D98
sub_8049D98: @ 0x08049D98
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	bl GetItemIid
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, .L08049DB4 @ =gUnk_08662E4C
	ldrh r1, [r3]
	ldr r2, .L08049DB8 @ =0x0000FFFF
	b .L08049DC0
	.align 2, 0
.L08049DB4: .4byte gUnk_08662E4C
.L08049DB8: .4byte 0x0000FFFF
.L08049DBC:
	adds r3, #0x10
	ldrh r1, [r3]
.L08049DC0:
	cmp r1, r2
	beq .L08049DC8
	cmp r1, r0
	bne .L08049DBC
.L08049DC8:
	ldrh r2, [r3, #4]
	ldrh r3, [r3, #4]
	cmp r3, #3
	bne .L08049E92
	adds r0, r4, #0
	subs r0, #0xe
	cmp r0, #0x22
	bhi .L08049E92
	lsls r0, r0, #2
	ldr r1, .L08049DE4 @ =.L08049DE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08049DE4: .4byte .L08049DE8
.L08049DE8: @ jump table
	.4byte .L08049E90 @ case 0
	.4byte .L08049E90 @ case 1
	.4byte .L08049E92 @ case 2
	.4byte .L08049E92 @ case 3
	.4byte .L08049E92 @ case 4
	.4byte .L08049E92 @ case 5
	.4byte .L08049E92 @ case 6
	.4byte .L08049E92 @ case 7
	.4byte .L08049E92 @ case 8
	.4byte .L08049E92 @ case 9
	.4byte .L08049E92 @ case 10
	.4byte .L08049E92 @ case 11
	.4byte .L08049E92 @ case 12
	.4byte .L08049E92 @ case 13
	.4byte .L08049E92 @ case 14
	.4byte .L08049E92 @ case 15
	.4byte .L08049E92 @ case 16
	.4byte .L08049E92 @ case 17
	.4byte .L08049E74 @ case 18
	.4byte .L08049E74 @ case 19
	.4byte .L08049E7C @ case 20
	.4byte .L08049E7C @ case 21
	.4byte .L08049E92 @ case 22
	.4byte .L08049E92 @ case 23
	.4byte .L08049E92 @ case 24
	.4byte .L08049E92 @ case 25
	.4byte .L08049E92 @ case 26
	.4byte .L08049E92 @ case 27
	.4byte .L08049E80 @ case 28
	.4byte .L08049E84 @ case 29
	.4byte .L08049E88 @ case 30
	.4byte .L08049E88 @ case 31
	.4byte .L08049E8C @ case 32
	.4byte .L08049E8C @ case 33
	.4byte .L08049E78 @ case 34
.L08049E74:
	movs r2, #4
	b .L08049E92
.L08049E78:
	movs r2, #5
	b .L08049E92
.L08049E7C:
	movs r2, #6
	b .L08049E92
.L08049E80:
	movs r2, #7
	b .L08049E92
.L08049E84:
	movs r2, #8
	b .L08049E92
.L08049E88:
	movs r2, #9
	b .L08049E92
.L08049E8C:
	movs r2, #0xa
	b .L08049E92
.L08049E90:
	movs r2, #0xb
.L08049E92:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_8049E9C
sub_8049E9C: @ 0x08049E9C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, r2, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemIid
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08049EC2
	movs r0, #0
	strh r0, [r4]
.L08049EC2:
	ldr r0, .L08049EE0 @ =0x0203CCF4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, r5
	beq .L08049F14
	adds r0, r2, #0
	subs r0, #0x48
	cmp r0, #9
	bhi .L08049F14
	lsls r0, r0, #2
	ldr r1, .L08049EE4 @ =.L08049EE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08049EE0: .4byte 0x0203CCF4
.L08049EE4: .4byte .L08049EE8
.L08049EE8: @ jump table
	.4byte .L08049F10 @ case 0
	.4byte .L08049F10 @ case 1
	.4byte .L08049F14 @ case 2
	.4byte .L08049F14 @ case 3
	.4byte .L08049F14 @ case 4
	.4byte .L08049F10 @ case 5
	.4byte .L08049F14 @ case 6
	.4byte .L08049F10 @ case 7
	.4byte .L08049F14 @ case 8
	.4byte .L08049F10 @ case 9
.L08049F10:
	movs r0, #0
	strh r0, [r4]
.L08049F14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8049F1C
sub_8049F1C: @ 0x08049F1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r0, .L08049F58 @ =gBattleHits
	str r0, [sp, #4]
	ldr r0, .L08049F5C @ =0x0203CD88
	movs r3, #0
	str r3, [r0, #4]
	str r3, [r0]
	ldr r2, .L08049F60 @ =0x0203CD14
	movs r5, #0
	ldrsh r1, [r2, r5]
	cmp r1, #4
	bne .L08049F6C
	ldr r0, .L08049F64 @ =0x0203CD1E
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r2, .L08049F68 @ =0x0000FFFF
	adds r1, r2, #0
	ldrh r2, [r0, #4]
	orrs r2, r1
	strh r2, [r0, #4]
	ldrh r5, [r0, #6]
	orrs r1, r5
	strh r1, [r0, #6]
	b .L0804A46E
	.align 2, 0
.L08049F58: .4byte gBattleHits
.L08049F5C: .4byte 0x0203CD88
.L08049F60: .4byte 0x0203CD14
.L08049F64: .4byte 0x0203CD1E
.L08049F68: .4byte 0x0000FFFF
.L08049F6C:
	ldr r1, .L08049F94 @ =gBattleSt
	movs r0, #0x40
	ldrb r1, [r1, #1]
	ands r0, r1
	cmp r0, #0
	beq .L08049FA0
	ldr r2, .L08049F98 @ =0x0203CD1E
	movs r0, #6
	strh r0, [r2]
	strh r3, [r2, #2]
	ldr r1, .L08049F9C @ =0x0000FFFF
	adds r0, r1, #0
	ldrh r1, [r2, #4]
	orrs r1, r0
	strh r1, [r2, #4]
	ldrh r5, [r2, #6]
	orrs r0, r5
	strh r0, [r2, #6]
	b .L0804A46E
	.align 2, 0
.L08049F94: .4byte gBattleSt
.L08049F98: .4byte 0x0203CD1E
.L08049F9C: .4byte 0x0000FFFF
.L08049FA0:
	ldrh r2, [r2]
	str r2, [sp, #0x18]
	str r2, [sp, #0x1c]
	movs r0, #0
	str r0, [sp, #0x20]
	ldr r0, .L0804A0A4 @ =0x0203CD7C
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r0, .L0804A0A8 @ =0x0203CD80
	ldr r0, [r0]
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	cmp r0, #0x7d
	bne .L08049FCE
	ldr r1, [sp, #0x18]
	cmp r1, #0
	bne .L08049FCE
	movs r2, #1
	str r2, [sp, #0x18]
.L08049FCE:
	ldr r4, [sp, #0xc]
	adds r4, #0x4a
	ldrh r0, [r4]
	bl GetItemIid
	adds r5, r4, #0
	cmp r0, #0x7d
	bne .L08049FE8
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	bne .L08049FE8
	movs r1, #1
	str r1, [sp, #0x1c]
.L08049FE8:
	ldr r4, [sp, #8]
	adds r4, #0x4a
	ldrh r0, [r4]
	bl GetItemIid
	cmp r0, #0x20
	bne .L0804A000
	ldr r2, [sp, #0x18]
	cmp r2, #0
	bne .L0804A000
	movs r0, #1
	str r0, [sp, #0x18]
.L0804A000:
	ldrh r0, [r5]
	bl GetItemIid
	cmp r0, #0x20
	bne .L0804A014
	ldr r1, [sp, #0x1c]
	cmp r1, #0
	bne .L0804A014
	movs r2, #1
	str r2, [sp, #0x1c]
.L0804A014:
	ldrh r0, [r4]
	bl GetItemIid
	cmp r0, #0x7f
	bne .L0804A028
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne .L0804A028
	movs r1, #1
	str r1, [sp, #0x18]
.L0804A028:
	ldrh r0, [r5]
	bl GetItemIid
	cmp r0, #0x7f
	bne .L0804A03C
	ldr r2, [sp, #0x1c]
	cmp r2, #0
	bne .L0804A03C
	movs r5, #1
	str r5, [sp, #0x1c]
.L0804A03C:
	ldrh r0, [r4]
	bl GetItemIid
	cmp r0, #0x53
	bne .L0804A050
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne .L0804A050
	movs r1, #1
	str r1, [sp, #0x18]
.L0804A050:
	ldrh r0, [r4]
	bl GetItemIid
	cmp r0, #0x70
	bne .L0804A05E
	movs r2, #1
	str r2, [sp, #0x20]
.L0804A05E:
	movs r2, #0
	ldr r4, .L0804A0AC @ =0x0203CD4A
	ldr r5, .L0804A0B0 @ =0x0203CDA0
	ldr r0, .L0804A0B4 @ =0x0000FFFF
	adds r3, r0, #0
	ldr r1, .L0804A0B8 @ =0x0203CD1E
.L0804A06A:
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #0x13
	bls .L0804A06A
	movs r2, #0
	ldr r0, .L0804A0AC @ =0x0203CD4A
	ldr r1, .L0804A0B4 @ =0x0000FFFF
	adds r3, r1, #0
	adds r1, r0, #4
.L0804A082:
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #0x13
	bls .L0804A082
	ldrh r0, [r5]
	strh r0, [r4]
	ldrh r0, [r5, #2]
	strh r0, [r4, #2]
	movs r2, #0
	str r2, [sp, #0x10]
	mov r8, r2
	movs r7, #0
	ldr r5, [sp, #4]
	b .L0804A462
	.align 2, 0
.L0804A0A4: .4byte 0x0203CD7C
.L0804A0A8: .4byte 0x0203CD80
.L0804A0AC: .4byte 0x0203CD4A
.L0804A0B0: .4byte 0x0203CDA0
.L0804A0B4: .4byte 0x0000FFFF
.L0804A0B8: .4byte 0x0203CD1E
.L0804A0BC:
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	str r0, [sp, #0x14]
	ldr r0, .L0804A0F4 @ =0x0203CCFC
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x14]
	cmp r0, r2
	bne .L0804A0FC
	mov r5, sp
	movs r0, #2
	add r0, sp
	mov sb, r0
	ldr r4, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	mov sl, r1
	ldr r6, [sp, #8]
	ldr r3, [sp, #0x20]
	ldr r2, [sp, #0x10]
	cmp r2, #0
	bne .L0804A118
	ldr r0, .L0804A0F8 @ =0x0203CCF4
	strh r2, [r0]
	b .L0804A118
	.align 2, 0
.L0804A0F4: .4byte 0x0203CCFC
.L0804A0F8: .4byte 0x0203CCF4
.L0804A0FC:
	mov r5, sp
	adds r5, #2
	mov sb, sp
	ldr r4, [sp, #0x1c]
	ldr r0, [sp, #0x18]
	mov sl, r0
	ldr r6, [sp, #0xc]
	movs r3, #0
	ldr r1, [sp, #0x10]
	cmp r1, #0
	bne .L0804A118
	ldr r1, .L0804A150 @ =0x0203CCF4
	movs r0, #1
	strh r0, [r1]
.L0804A118:
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r2, #0
	ldr r1, [sp, #4]
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0804A134
	ldr r2, .L0804A154 @ =0x0203CD88
	ldr r1, .L0804A158 @ =gBattleSt
	ldr r0, [r1, #0xc]
	str r0, [r2]
	ldr r0, [r1, #0x10]
	str r0, [r2, #4]
.L0804A134:
	movs r0, #1
	ldr r2, [sp, #4]
	ldrh r2, [r2]
	ands r0, r2
	cmp r0, #0
	beq .L0804A168
	adds r0, r6, #0
	bl UnitKnowsMagic
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0804A160
	ldr r0, .L0804A15C @ =gUnk_08112248
	b .L0804A1B6
	.align 2, 0
.L0804A150: .4byte 0x0203CCF4
.L0804A154: .4byte 0x0203CD88
.L0804A158: .4byte gBattleSt
.L0804A15C: .4byte gUnk_08112248
.L0804A160:
	ldr r0, .L0804A164 @ =gUnk_08112270
	b .L0804A1B6
	.align 2, 0
.L0804A164: .4byte gUnk_08112270
.L0804A168:
	cmp r3, #0
	bne .L0804A188
	adds r0, r6, #0
	bl UnitKnowsMagic
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0804A180
	ldr r0, .L0804A17C @ =gUnk_08112234
	b .L0804A1B6
	.align 2, 0
.L0804A17C: .4byte gUnk_08112234
.L0804A180:
	ldr r0, .L0804A184 @ =gUnk_08112266
	b .L0804A1B6
	.align 2, 0
.L0804A184: .4byte gUnk_08112266
.L0804A188:
	movs r0, #2
	bl sub_805B9C8
	cmp r0, #1
	beq .L0804A1AC
	cmp r0, #1
	bgt .L0804A19C
	cmp r0, #0
	beq .L0804A1A2
	b .L0804A1C0
.L0804A19C:
	cmp r0, #2
	beq .L0804A1B4
	b .L0804A1C0
.L0804A1A2:
	ldr r0, .L0804A1A8 @ =gUnk_0811227A
	b .L0804A1B6
	.align 2, 0
.L0804A1A8: .4byte gUnk_0811227A
.L0804A1AC:
	ldr r0, .L0804A1B0 @ =gUnk_08112284
	b .L0804A1B6
	.align 2, 0
.L0804A1B0: .4byte gUnk_08112284
.L0804A1B4:
	ldr r0, .L0804A1DC @ =gUnk_0811228E
.L0804A1B6:
	lsls r1, r4, #0x10
	asrs r1, r1, #0xf
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r5]
.L0804A1C0:
	movs r0, #2
	ldr r1, [sp, #4]
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0804A1FC
	adds r0, r6, #0
	bl UnitKnowsMagic
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0804A1E4
	ldr r0, .L0804A1E0 @ =gUnk_0811223E
	b .L0804A1E6
	.align 2, 0
.L0804A1DC: .4byte gUnk_0811228E
.L0804A1E0: .4byte gUnk_0811223E
.L0804A1E4:
	ldr r0, .L0804A1F4 @ =gUnk_08112266
.L0804A1E6:
	lsls r1, r4, #0x10
	asrs r1, r1, #0xf
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r5]
	ldr r0, .L0804A1F8 @ =gUnk_08112252
	b .L0804A1FE
	.align 2, 0
.L0804A1F4: .4byte gUnk_08112266
.L0804A1F8: .4byte gUnk_08112252
.L0804A1FC:
	ldr r0, .L0804A27C @ =gUnk_0811225C
.L0804A1FE:
	mov r2, sl
	lsls r1, r2, #0x10
	asrs r1, r1, #0xf
	adds r1, r1, r0
	ldrh r0, [r1]
	mov r5, sb
	strh r0, [r5]
	ldr r1, .L0804A280 @ =0x0203CD1E
	ldr r2, [sp, #0x10]
	lsls r0, r2, #2
	adds r5, r0, r1
	mov r0, sp
	ldrh r0, [r0]
	movs r6, #0
	strh r0, [r5]
	lsls r0, r2, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r4, r0, r1
	mov r1, sp
	ldrh r0, [r1, #2]
	strh r0, [r4]
	ldr r2, [sp, #4]
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0804A238
	b .L0804A456
.L0804A238:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L0804A2D0
	ldr r0, .L0804A284 @ =0x0203CCFC
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x14]
	cmp r0, r2
	bne .L0804A290
	lsls r0, r7, #1
	bl sub_804A5A8
	ldr r2, [sp, #4]
	movs r1, #3
	ldrsb r1, [r2, r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804A264
	movs r2, #0
.L0804A264:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r0, r7, #2
	ldr r1, .L0804A288 @ =0x0203CD4A
	adds r0, r0, r1
	strh r2, [r0]
	ldr r2, .L0804A28C @ =0xFFFF8000
	adds r0, r2, #0
	ldrh r1, [r5]
	orrs r0, r1
	b .L0804A454
	.align 2, 0
.L0804A27C: .4byte gUnk_0811225C
.L0804A280: .4byte 0x0203CD1E
.L0804A284: .4byte 0x0203CCFC
.L0804A288: .4byte 0x0203CD4A
.L0804A28C: .4byte 0xFFFF8000
.L0804A290:
	mov r2, r8
	lsls r0, r2, #1
	adds r0, #1
	bl sub_804A5A8
	ldr r5, [sp, #4]
	movs r1, #3
	ldrsb r1, [r5, r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804A2AC
	movs r2, #0
.L0804A2AC:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	ldr r1, .L0804A2C8 @ =0x0203CD4A
	adds r0, r0, r1
	strh r2, [r0]
	ldr r2, .L0804A2CC @ =0xFFFF8000
	b .L0804A406
	.align 2, 0
.L0804A2C8: .4byte 0x0203CD4A
.L0804A2CC: .4byte 0xFFFF8000
.L0804A2D0:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq .L0804A3B8
	ldr r0, .L0804A344 @ =0x0203CCFC
	movs r5, #0
	ldrsh r0, [r0, r5]
	ldr r1, [sp, #0x14]
	cmp r0, r1
	bne .L0804A350
	mov r2, r8
	lsls r0, r2, #1
	adds r0, #1
	bl sub_804A5A8
	ldr r5, [sp, #4]
	movs r1, #3
	ldrsb r1, [r5, r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804A304
	movs r2, #0
.L0804A304:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r4, .L0804A348 @ =0x0203CD4A
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	strh r2, [r0]
	lsls r0, r7, #1
	bl sub_804A5A8
	ldr r2, [sp, #4]
	movs r1, #3
	ldrsb r1, [r2, r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r3, .L0804A34C @ =0x0203CDA4
	lsrs r2, r0, #0x10
	ldrh r5, [r3]
	lsls r1, r5, #0x10
	cmp r0, r1
	ble .L0804A338
	ldrh r2, [r3]
.L0804A338:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r0, r7, #2
	b .L0804A3A8
	.align 2, 0
.L0804A344: .4byte 0x0203CCFC
.L0804A348: .4byte 0x0203CD4A
.L0804A34C: .4byte 0x0203CDA4
.L0804A350:
	lsls r0, r7, #1
	bl sub_804A5A8
	ldr r2, [sp, #4]
	movs r1, #3
	ldrsb r1, [r2, r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804A368
	movs r2, #0
.L0804A368:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r4, .L0804A3B0 @ =0x0203CD4A
	lsls r0, r7, #2
	adds r0, r0, r4
	strh r2, [r0]
	mov r5, r8
	lsls r0, r5, #1
	adds r0, #1
	bl sub_804A5A8
	ldr r2, [sp, #4]
	movs r1, #3
	ldrsb r1, [r2, r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r3, .L0804A3B4 @ =0x0203CDA4
	lsrs r2, r0, #0x10
	ldrh r5, [r3, #2]
	lsls r1, r5, #0x10
	cmp r0, r1
	ble .L0804A398
	ldrh r2, [r3, #2]
.L0804A398:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
.L0804A3A8:
	adds r0, r0, r4
	strh r2, [r0]
	b .L0804A456
	.align 2, 0
.L0804A3B0: .4byte 0x0203CD4A
.L0804A3B4: .4byte 0x0203CDA4
.L0804A3B8:
	ldr r0, .L0804A410 @ =0x0203CCFC
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x14]
	cmp r0, r2
	bne .L0804A418
	mov r5, r8
	lsls r0, r5, #1
	adds r0, #1
	bl sub_804A5A8
	ldr r2, [sp, #4]
	movs r1, #3
	ldrsb r1, [r2, r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804A3E0
	movs r2, #0
.L0804A3E0:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	ldr r5, .L0804A414 @ =0x0203CD4A
	adds r0, r0, r5
	strh r2, [r0]
	movs r0, #0x40
	ldr r1, [sp, #4]
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0804A456
	movs r2, #0x80
	lsls r2, r2, #6
.L0804A406:
	adds r0, r2, #0
	ldrh r5, [r4]
	orrs r0, r5
	strh r0, [r4]
	b .L0804A456
	.align 2, 0
.L0804A410: .4byte 0x0203CCFC
.L0804A414: .4byte 0x0203CD4A
.L0804A418:
	lsls r0, r7, #1
	bl sub_804A5A8
	ldr r2, [sp, #4]
	movs r1, #3
	ldrsb r1, [r2, r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804A430
	movs r2, #0
.L0804A430:
	adds r0, r7, #1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r0, r7, #2
	ldr r1, .L0804A480 @ =0x0203CD4A
	adds r0, r0, r1
	strh r2, [r0]
	movs r0, #0x40
	ldr r2, [sp, #4]
	ldrh r2, [r2]
	ands r0, r2
	cmp r0, #0
	beq .L0804A456
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	ldrh r2, [r5]
	orrs r0, r2
.L0804A454:
	strh r0, [r5]
.L0804A456:
	ldr r5, [sp, #4]
	adds r5, #4
	str r5, [sp, #4]
	ldr r0, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0x10]
.L0804A462:
	ldrb r1, [r5, #2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne .L0804A46E
	b .L0804A0BC
.L0804A46E:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804A480: .4byte 0x0203CD4A

	thumb_func_start sub_804A484
sub_804A484: @ 0x0804A484
	ldr r1, .L0804A494 @ =gBattleHits
	movs r0, #2
	ldrb r1, [r1, #2]
	ands r0, r1
	cmp r0, #0
	bne .L0804A498
	movs r0, #0
	b .L0804A49A
	.align 2, 0
.L0804A494: .4byte gBattleHits
.L0804A498:
	movs r0, #1
.L0804A49A:
	bx lr

	thumb_func_start sub_804A49C
sub_804A49C: @ 0x0804A49C
	ldr r2, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r2, #0x28]
	ldr r1, [r1, #0x24]
	orrs r0, r1
	lsrs r0, r0, #8
	movs r1, #1
	ands r0, r1
	adds r2, #0x23
	adds r2, r2, r0
	ldrb r0, [r2]
	subs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start sub_804A4B8
sub_804A4B8: @ 0x0804A4B8
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x67
	bne .L0804A4F8
	adds r0, r1, #0
	bl GetItemIid
	cmp r0, #0x31
	beq .L0804A4E8
	cmp r0, #0x31
	bgt .L0804A4DA
	cmp r0, #0x30
	beq .L0804A4E0
	b .L0804A4F8
.L0804A4DA:
	cmp r0, #0x32
	beq .L0804A4F0
	b .L0804A4F8
.L0804A4E0:
	ldr r0, .L0804A4E4 @ =gUnk_08113FB8
	b .L0804A4FA
	.align 2, 0
.L0804A4E4: .4byte gUnk_08113FB8
.L0804A4E8:
	ldr r0, .L0804A4EC @ =gUnk_08113F98
	b .L0804A4FA
	.align 2, 0
.L0804A4EC: .4byte gUnk_08113F98
.L0804A4F0:
	ldr r0, .L0804A4F4 @ =gUnk_08113FD8
	b .L0804A4FA
	.align 2, 0
.L0804A4F4: .4byte gUnk_08113FD8
.L0804A4F8:
	movs r0, #0
.L0804A4FA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_804A500
sub_804A500: @ 0x0804A500
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #0x40
	beq .L0804A51C
	cmp r0, #0x40
	ble .L0804A524
	cmp r1, #0x80
	beq .L0804A518
	cmp r1, #0xc0
	beq .L0804A520
	b .L0804A524
.L0804A518:
	movs r0, #1
	b .L0804A526
.L0804A51C:
	movs r0, #2
	b .L0804A526
.L0804A520:
	movs r0, #3
	b .L0804A526
.L0804A524:
	movs r0, #0
.L0804A526:
	bx lr

	thumb_func_start sub_804A528
sub_804A528: @ 0x0804A528
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	bl sub_804B6C4
	ldr r1, .L0804A550 @ =0x0203CD76
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	bl sub_804B048
	adds r0, r5, #0
	movs r1, #6
	bl sub_804B5E0
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804A550: .4byte 0x0203CD76

	thumb_func_start sub_804A554
sub_804A554: @ 0x0804A554
	ldr r1, .L0804A570 @ =0x0203CD1E
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L0804A578
	ldr r0, .L0804A574 @ =0x00000FFF
	ands r0, r2
	b .L0804A57A
	.align 2, 0
.L0804A570: .4byte 0x0203CD1E
.L0804A574: .4byte 0x00000FFF
.L0804A578:
	adds r0, r1, #0
.L0804A57A:
	bx lr

	thumb_func_start sub_804A57C
sub_804A57C: @ 0x0804A57C
	ldr r1, .L0804A59C @ =0x0203CD1E
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L0804A5A4
	ldr r0, .L0804A5A0 @ =0xFFFFF000
	ands r0, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b .L0804A5A6
	.align 2, 0
.L0804A59C: .4byte 0x0203CD1E
.L0804A5A0: .4byte 0xFFFFF000
.L0804A5A4:
	movs r0, #0
.L0804A5A6:
	bx lr

	thumb_func_start sub_804A5A8
sub_804A5A8: @ 0x0804A5A8
	ldr r1, .L0804A5B8 @ =0x0203CD4A
	lsls r0, r0, #1
	adds r0, r0, r1
	ldr r1, .L0804A5BC @ =0x00000FFF
	ldrh r0, [r0]
	ands r1, r0
	adds r0, r1, #0
	bx lr
	.align 2, 0
.L0804A5B8: .4byte 0x0203CD4A
.L0804A5BC: .4byte 0x00000FFF

	thumb_func_start sub_804A5C0
sub_804A5C0: @ 0x0804A5C0
	ldr r1, .L0804A5D4 @ =0x0203CD4A
	lsls r0, r0, #1
	adds r0, r0, r1
	ldr r1, .L0804A5D8 @ =0xFFFFF000
	ldrh r0, [r0]
	ands r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0
	bx lr
	.align 2, 0
.L0804A5D4: .4byte 0x0203CD4A
.L0804A5D8: .4byte 0xFFFFF000

	thumb_func_start sub_804A5DC
sub_804A5DC: @ 0x0804A5DC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	movs r2, #0

	thumb_func_start sub_0804A5E8
sub_0804A5E8: @ 0x0804A5E8
	ldr r1, .L0804A640 @ =gUnk_Banim_02000000
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r7, [r0]
	adds r2, #1
	mov sb, r2
	cmp r7, #0
	bne .L0804A5FC
	bl .L0804AF52
.L0804A5FC:
	movs r0, #0xf0
	lsls r0, r0, #8
	ldrh r1, [r7, #0xc]
	ands r1, r0
	mov r8, r1
	cmp r1, #0
	bne .L0804A60E
	bl .L0804AF52
.L0804A60E:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r1
	cmp r0, #0
	bne .L0804A61A
	b .L0804AD94
.L0804A61A:
	ldrb r0, [r7, #0x14]
	cmp r0, #0
	bne .L0804A622
	b .L0804AD8A
.L0804A622:
	subs r1, r0, #1
	adds r2, r7, #0
	adds r2, #0x15
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r3, r0, #0
	cmp r1, #0x4a
	bls .L0804A634
	b .L0804AD82
.L0804A634:
	lsls r0, r1, #2
	ldr r1, .L0804A644 @ =.L0804A648
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804A640: .4byte gUnk_Banim_02000000
.L0804A644: .4byte .L0804A648
.L0804A648: @ jump table
	.4byte .L0804AD82 @ case 0
	.4byte .L0804A774 @ case 1
	.4byte .L0804A7B4 @ case 2
	.4byte .L0804A7C8 @ case 3
	.4byte .L0804A7EE @ case 4
	.4byte .L0804A874 @ case 5
	.4byte .L0804A8C8 @ case 6
	.4byte .L0804AD82 @ case 7
	.4byte .L0804A8F8 @ case 8
	.4byte .L0804A8F8 @ case 9
	.4byte .L0804A8F8 @ case 10
	.4byte .L0804A8F8 @ case 11
	.4byte .L0804A8F8 @ case 12
	.4byte .L0804A968 @ case 13
	.4byte .L0804AD82 @ case 14
	.4byte .L0804AD82 @ case 15
	.4byte .L0804AD82 @ case 16
	.4byte .L0804AD82 @ case 17
	.4byte .L0804AD82 @ case 18
	.4byte .L0804AB08 @ case 19
	.4byte .L0804AB38 @ case 20
	.4byte .L0804AB4C @ case 21
	.4byte .L0804AD82 @ case 22
	.4byte .L0804AD82 @ case 23
	.4byte .L0804AB60 @ case 24
	.4byte .L0804AD60 @ case 25
	.4byte .L0804AB9C @ case 26
	.4byte .L0804AD60 @ case 27
	.4byte .L0804AD60 @ case 28
	.4byte .L0804AD60 @ case 29
	.4byte .L0804AD60 @ case 30
	.4byte .L0804AD60 @ case 31
	.4byte .L0804AD60 @ case 32
	.4byte .L0804AD60 @ case 33
	.4byte .L0804AD60 @ case 34
	.4byte .L0804AD60 @ case 35
	.4byte .L0804AD60 @ case 36
	.4byte .L0804AD60 @ case 37
	.4byte .L0804ABF2 @ case 38
	.4byte .L0804AC08 @ case 39
	.4byte .L0804AD60 @ case 40
	.4byte .L0804AD60 @ case 41
	.4byte .L0804AD60 @ case 42
	.4byte .L0804AD60 @ case 43
	.4byte .L0804AC1E @ case 44
	.4byte .L0804AC32 @ case 45
	.4byte .L0804AC3A @ case 46
	.4byte .L0804AC50 @ case 47
	.4byte .L0804AC66 @ case 48
	.4byte .L0804AC7C @ case 49
	.4byte .L0804AC92 @ case 50
	.4byte .L0804AD60 @ case 51
	.4byte .L0804AD60 @ case 52
	.4byte .L0804AD60 @ case 53
	.4byte .L0804AD60 @ case 54
	.4byte .L0804AD60 @ case 55
	.4byte .L0804AD60 @ case 56
	.4byte .L0804ACA6 @ case 57
	.4byte .L0804ACEC @ case 58
	.4byte .L0804AD14 @ case 59
	.4byte .L0804AD60 @ case 60
	.4byte .L0804AD60 @ case 61
	.4byte .L0804AD60 @ case 62
	.4byte .L0804AD60 @ case 63
	.4byte .L0804AD60 @ case 64
	.4byte .L0804AD60 @ case 65
	.4byte .L0804AD60 @ case 66
	.4byte .L0804AD60 @ case 67
	.4byte .L0804AD3C @ case 68
	.4byte .L0804AD4E @ case 69
	.4byte .L0804AD60 @ case 70
	.4byte .L0804AD6E @ case 71
	.4byte .L0804AD76 @ case 72
	.4byte .L0804AD76 @ case 73
	.4byte .L0804AD76 @ case 74
.L0804A774:
	ldr r0, .L0804A784 @ =gUnk_Banim_0200001C
	ldr r0, [r0]
	cmp r0, #1
	bne .L0804A788
	ldr r0, [r7, #0x24]
	str r0, [r7, #0x20]
	b .L0804AD82
	.align 2, 0
.L0804A784: .4byte gUnk_Banim_0200001C
.L0804A788:
	ldrh r1, [r7, #0x10]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne .L0804A794
	b .L0804ACDC
.L0804A794:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L0804A79E
	b .L0804AD82
.L0804A79E:
	bl sub_80449C4
	cmp r0, #1
	beq .L0804A7A8
	b .L0804AD82
.L0804A7A8:
	ldr r0, .L0804A7B0 @ =0x0000FFF2
	ldrh r2, [r7, #0x10]
	ands r0, r2
	b .L0804ACDA
	.align 2, 0
.L0804A7B0: .4byte 0x0000FFF2
.L0804A7B4:
	ldrh r1, [r7, #0x10]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0804A7C0
	b .L0804AD82
.L0804A7C0:
	ldr r0, .L0804A7C4 @ =0x0000FFFE
	b .L0804ACD8
	.align 2, 0
.L0804A7C4: .4byte 0x0000FFFE
.L0804A7C8:
	ldrh r1, [r7, #0x10]
	movs r2, #0x20
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L0804A7EA
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r7, #0x10]
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	bne .L0804A7EA
	adds r0, r7, #0
	bl sub_8057860
.L0804A7EA:
	ldrh r1, [r7, #0x10]
	b .L0804ACCA
.L0804A7EE:
	ldrh r1, [r7, #0x10]
	movs r2, #0x20
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L0804A804
	adds r0, r2, #0
	orrs r0, r1
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r7, #0x10]
.L0804A804:
	ldrh r2, [r7, #0x10]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	bne .L0804A810
	b .L0804AD82
.L0804A810:
	ldr r1, .L0804A86C @ =0x0000FFDF
	ands r1, r2
	ldr r0, .L0804A870 @ =0x0000FFBF
	ands r1, r0
	ldr r0, [r7, #0x20]
	adds r0, #4
	str r0, [r7, #0x20]
	movs r5, #9
	movs r6, #0
	orrs r1, r5
	strh r1, [r7, #0x10]
	adds r0, r7, #0
	bl sub_804B80C
	adds r2, r0, #0
	adds r0, r7, #0
	str r2, [sp]
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	mov r4, r8
	adds r0, r4, #0
	bl sub_804B6D8
	ldr r2, [sp]
	cmp r0, #1
	beq .L0804A84C
	b .L0804AD82
.L0804A84C:
	cmp r2, #0
	bne .L0804A852
	b .L0804AD82
.L0804A852:
	ldrh r0, [r2, #0x10]
	orrs r0, r5
	strh r0, [r2, #0x10]
	adds r0, r7, #0
	str r2, [sp]
	bl sub_804B6B0
	cmp r0, #0
	beq .L0804A866
	b .L0804AD82
.L0804A866:
	adds r0, r4, #0
	b .L0804A958
	.align 2, 0
.L0804A86C: .4byte 0x0000FFDF
.L0804A870: .4byte 0x0000FFBF
.L0804A874:
	ldrh r1, [r7, #0x10]
	movs r2, #0x20
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L0804A88A
	adds r0, r2, #0
	orrs r0, r1
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r7, #0x10]
.L0804A88A:
	ldrh r2, [r7, #0x10]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	bne .L0804A896
	b .L0804AD82
.L0804A896:
	ldr r1, .L0804A8C0 @ =0x0000FFDF
	ands r1, r2
	ldr r0, .L0804A8C4 @ =0x0000FFBF
	ands r1, r0
	ldr r0, [r7, #0x20]
	adds r0, #4
	str r0, [r7, #0x20]
	movs r0, #9
	orrs r1, r0
	strh r1, [r7, #0x10]
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	beq .L0804A8B6
	b .L0804AD82
.L0804A8B6:
	adds r0, r7, #0
	bl sub_804C898
	b .L0804AD82
	.align 2, 0
.L0804A8C0: .4byte 0x0000FFDF
.L0804A8C4: .4byte 0x0000FFBF
.L0804A8C8:
	adds r0, r7, #0
	bl sub_804B80C
	adds r2, r0, #0
	cmp r2, #0
	bne .L0804A8D6
	b .L0804AD82
.L0804A8D6:
	str r2, [sp]
	bl sub_804B88C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	movs r0, #1
	rsbs r0, r0, #0
	ldr r2, [sp]
	cmp r8, r0
	bne .L0804A8EE
	b .L0804AD82
.L0804A8EE:
	movs r0, #2
	ldrh r3, [r2, #0x10]
	orrs r0, r3
	strh r0, [r2, #0x10]
	b .L0804AD82
.L0804A8F8:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	beq .L0804A904
	b .L0804AD82
.L0804A904:
	adds r0, r7, #0
	bl sub_804B80C
	adds r2, r0, #0
	adds r0, r7, #0
	str r2, [sp]
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	bl sub_804B6D8
	ldr r2, [sp]
	cmp r0, #0
	bne .L0804A93C
	adds r0, r2, #0
	bl sub_805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp]
	cmp r0, #2
	beq .L0804A93C
	adds r0, r2, #0
	bl sub_8056B08
	ldr r2, [sp]
.L0804A93C:
	cmp r2, #0
	bne .L0804A942
	b .L0804AD82
.L0804A942:
	movs r0, #9
	ldrh r1, [r2, #0x10]
	orrs r0, r1
	strh r0, [r2, #0x10]
	adds r0, r7, #0
	str r2, [sp]
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
.L0804A958:
	bl sub_804B6D8
	adds r1, r0, #0
	ldr r2, [sp]
	adds r0, r2, #0
	bl sub_8047600
	b .L0804AD82
.L0804A968:
	adds r0, r7, #0
	bl sub_804B848
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	ldr r4, .L0804A9A8 @ =gUnk_Banim_02000000
	adds r0, r7, #0
	bl sub_804B6C4
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r2, [r0]
	adds r0, r7, #0
	str r2, [sp]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r6, [r0]
	ldrb r0, [r7, #0x12]
	ldr r2, [sp]
	cmp r0, #9
	bls .L0804A99E
	b .L0804AD82
.L0804A99E:
	lsls r0, r0, #2
	ldr r1, .L0804A9AC @ =.L0804A9B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804A9A8: .4byte gUnk_Banim_02000000
.L0804A9AC: .4byte .L0804A9B0
.L0804A9B0: @ jump table
	.4byte .L0804A9D8 @ case 0
	.4byte .L0804A9D8 @ case 1
	.4byte .L0804A9D8 @ case 2
	.4byte .L0804A9D8 @ case 3
	.4byte .L0804AAE0 @ case 4
	.4byte .L0804AAE0 @ case 5
	.4byte .L0804AAEE @ case 6
	.4byte .L0804AAEE @ case 7
	.4byte .L0804AAEE @ case 8
	.4byte .L0804A9D8 @ case 9
.L0804A9D8:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r8, r0
	bne .L0804A9E2
	b .L0804AAE0
.L0804A9E2:
	ldrh r0, [r2, #0xe]
	adds r0, #1
	strh r0, [r2, #0xe]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	adds r0, r2, #0
	mov r1, r8
	str r2, [sp]
	bl sub_804B5E0
	adds r0, r6, #0
	mov r1, r8
	bl sub_804B5E0
	movs r1, #4
	ldr r2, [sp]
	ldrh r0, [r2, #0x10]
	orrs r0, r1
	strh r0, [r2, #0x10]
	ldrh r0, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	ldr r1, .L0804AA38 @ =gUnk_081122C0
	ldr r0, .L0804AA3C @ =0x0203CD14
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r8, r0
	ldr r1, .L0804AA40 @ =gUnk_08112298
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r4, [r0]
	adds r0, r7, #0
	str r2, [sp]
	bl sub_804B6C4
	ldr r2, [sp]
	cmp r0, #0
	bne .L0804AA48
	ldr r0, .L0804AA44 @ =gUnk_Banim_02000054
	b .L0804AA4A
	.align 2, 0
.L0804AA38: .4byte gUnk_081122C0
.L0804AA3C: .4byte 0x0203CD14
.L0804AA40: .4byte gUnk_08112298
.L0804AA44: .4byte gUnk_Banim_02000054
.L0804AA48:
	ldr r0, .L0804AACC @ =gUnk_Banim_02000058
.L0804AA4A:
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r7, #0
	str r2, [sp]
	bl sub_804B6C4
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #9
	ldr r0, .L0804AAD0 @ =gUnk_Banim_0200F1C0
	adds r1, r1, r0
	adds r1, r4, r1
	ldr r0, [r1, #4]
	ldr r2, [sp]
	str r0, [r2, #0x28]
	ldr r4, [r2, #0x30]
	ldr r1, [r1, #8]
	adds r4, r4, r1
	str r4, [r2, #0x3c]
	ldr r4, [r6, #0x30]
	ldr r0, .L0804AAD4 @ =0x000057F0
	adds r4, r4, r0
	str r4, [r6, #0x3c]
	ldr r4, .L0804AAD8 @ =0x0203CD98
	adds r0, r7, #0
	str r2, [sp]
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r2, [sp]
	cmp r0, #0
	beq .L0804AA98
	b .L0804AD8A
.L0804AA98:
	ldr r4, .L0804AADC @ =gUnk_Banim_0201E13C
	adds r0, r2, #0
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, [r0]
	ldr r2, [sp]
	ldr r0, [r2, #0x28]
	cmp r1, r0
	bne .L0804AAB0
	b .L0804AD8A
.L0804AAB0:
	adds r0, r2, #0
	bl sub_804AF70
	ldr r2, [sp]
	adds r0, r2, #0
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r2, [sp]
	ldr r1, [r2, #0x28]
	str r1, [r0]
	b .L0804AD8A
	.align 2, 0
.L0804AACC: .4byte gUnk_Banim_02000058
.L0804AAD0: .4byte gUnk_Banim_0200F1C0
.L0804AAD4: .4byte 0x000057F0
.L0804AAD8: .4byte 0x0203CD98
.L0804AADC: .4byte gUnk_Banim_0201E13C
.L0804AAE0:
	ldr r1, .L0804AB00 @ =gUnk_081122C0
	ldr r0, .L0804AB04 @ =0x0203CD14
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r8, r0
.L0804AAEE:
	adds r0, r2, #0
	mov r1, r8
	bl sub_804B5E0
	adds r0, r6, #0
	mov r1, r8
	bl sub_804B5E0
	b .L0804AD8A
	.align 2, 0
.L0804AB00: .4byte gUnk_081122C0
.L0804AB04: .4byte 0x0203CD14
.L0804AB08:
	ldrh r2, [r7, #0x10]
	movs r1, #0x20
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne .L0804AB1C
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r7, #0x10]
	b .L0804AD82
.L0804AB1C:
	ldr r1, .L0804AB30 @ =gUnk_Banim_02017750
	ldr r0, [r1]
	cmp r0, #1
	beq .L0804AB26
	b .L0804AD82
.L0804AB26:
	movs r0, #0
	str r0, [r1]
	ldr r0, .L0804AB34 @ =0x0000FFDF
	ands r0, r2
	b .L0804ACDA
	.align 2, 0
.L0804AB30: .4byte gUnk_Banim_02017750
.L0804AB34: .4byte 0x0000FFDF
.L0804AB38:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	beq .L0804AB44
	b .L0804AD82
.L0804AB44:
	movs r0, #3
	bl sub_8046010
	b .L0804AD82
.L0804AB4C:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	beq .L0804AB58
	b .L0804AD82
.L0804AB58:
	movs r0, #0
	bl sub_8046010
	b .L0804AD82
.L0804AB60:
	ldrh r1, [r7, #0x10]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0804AB6C
	b .L0804AD82
.L0804AB6C:
	ldr r0, .L0804AB94 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r7, #0x10]
	ldr r0, [r7, #0x20]
	adds r0, #4
	str r0, [r7, #0x20]
	ldr r0, .L0804AB98 @ =0x0000F3FF
	ldrh r1, [r7, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r7, #8]
	movs r0, #0x8c
	strh r0, [r7, #0xa]
	bl BasSort
	b .L0804AD82
	.align 2, 0
.L0804AB94: .4byte 0x0000FFFE
.L0804AB98: .4byte 0x0000F3FF
.L0804AB9C:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	beq .L0804ABA8
	b .L0804AD82
.L0804ABA8:
	adds r0, r7, #0
	bl sub_804B80C
	adds r2, r0, #0
	cmp r2, #0
	beq .L0804ABDA
	movs r0, #9
	ldrh r3, [r2, #0x10]
	orrs r0, r3
	strh r0, [r2, #0x10]
	adds r0, r7, #0
	str r2, [sp]
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	bl sub_804B6D8
	adds r1, r0, #0
	ldr r2, [sp]
	adds r0, r2, #0
	bl sub_8047600
	ldr r2, [sp]
.L0804ABDA:
	adds r0, r2, #0
	bl sub_805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne .L0804ABEA
	b .L0804AD82
.L0804ABEA:
	adds r0, r7, #0
	bl sub_8056C3C
	b .L0804AD82
.L0804ABF2:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	beq .L0804ABFE
	b .L0804AD82
.L0804ABFE:
	adds r0, r7, #0
	movs r1, #0
	bl sub_8056D80
	b .L0804AD82
.L0804AC08:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	beq .L0804AC14
	b .L0804AD82
.L0804AC14:
	adds r0, r7, #0
	movs r1, #1
	bl sub_8056D80
	b .L0804AD82
.L0804AC1E:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	beq .L0804AC2A
	b .L0804AD82
.L0804AC2A:
	adds r0, r7, #0
	bl sub_8056F50
	b .L0804AD82
.L0804AC32:
	adds r0, r7, #0
	bl sub_804B6B0
	b .L0804AD82
.L0804AC3A:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	beq .L0804AC46
	b .L0804AD82
.L0804AC46:
	adds r0, r7, #0
	movs r1, #0
	bl sub_80571A0
	b .L0804AD82
.L0804AC50:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	beq .L0804AC5C
	b .L0804AD82
.L0804AC5C:
	adds r0, r7, #0
	movs r1, #1
	bl sub_80571A0
	b .L0804AD82
.L0804AC66:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	beq .L0804AC72
	b .L0804AD82
.L0804AC72:
	adds r0, r7, #0
	movs r1, #0
	bl sub_8057344
	b .L0804AD82
.L0804AC7C:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	beq .L0804AC88
	b .L0804AD82
.L0804AC88:
	adds r0, r7, #0
	movs r1, #1
	bl sub_8057344
	b .L0804AD82
.L0804AC92:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	bne .L0804AD82
	adds r0, r7, #0
	movs r1, #2
	bl sub_8057344
	b .L0804AD82
.L0804ACA6:
	ldrh r1, [r7, #0x10]
	movs r2, #0x20
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L0804ACCA
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r7, #0x10]
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	bne .L0804AD82
	adds r0, r7, #0
	bl sub_805755C
	b .L0804AD82
.L0804ACCA:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L0804AD82
	ldr r0, .L0804ACE4 @ =0x0000FFDF
	ands r0, r1
	ldr r1, .L0804ACE8 @ =0x0000FFBF
.L0804ACD8:
	ands r0, r1
.L0804ACDA:
	strh r0, [r7, #0x10]
.L0804ACDC:
	ldr r0, [r7, #0x20]
	adds r0, #4
	str r0, [r7, #0x20]
	b .L0804AD82
	.align 2, 0
.L0804ACE4: .4byte 0x0000FFDF
.L0804ACE8: .4byte 0x0000FFBF
.L0804ACEC:
	ldrh r0, [r7, #2]
	adds r0, #0x20
	strh r0, [r7, #2]
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	bne .L0804AD82
	adds r0, r7, #0
	bl sub_804B6C4
	ldr r1, .L0804AD10 @ =gUnk_Banim_02000020
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #0x20
	strh r1, [r0]
	b .L0804AD82
	.align 2, 0
.L0804AD10: .4byte gUnk_Banim_02000020
.L0804AD14:
	ldrh r0, [r7, #2]
	subs r0, #0x20
	strh r0, [r7, #2]
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	bne .L0804AD82
	adds r0, r7, #0
	bl sub_804B6C4
	ldr r1, .L0804AD38 @ =gUnk_Banim_02000020
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	subs r1, #0x20
	strh r1, [r0]
	b .L0804AD82
	.align 2, 0
.L0804AD38: .4byte gUnk_Banim_02000020
.L0804AD3C:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	bne .L0804AD82
	adds r0, r7, #0
	bl sub_80575E8
	b .L0804AD82
.L0804AD4E:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	bne .L0804AD82
	adds r0, r7, #0
	bl sub_80576AC
	b .L0804AD82
.L0804AD60:
	subs r0, r3, #1
	adds r0, r2, r0
	ldrb r1, [r0]
	adds r0, r7, #0
	bl sub_805BE7C
	b .L0804AD82
.L0804AD6E:
	adds r0, r7, #0
	bl sub_8057D20
	b .L0804AD82
.L0804AD76:
	subs r0, r3, #1
	adds r0, r2, r0
	ldrb r1, [r0]
	adds r0, r7, #0
	bl sub_805BE7C
.L0804AD82:
	ldrb r0, [r7, #0x14]
	subs r0, #1
	strb r0, [r7, #0x14]
	b .L0804A61A
.L0804AD8A:
	movs r0, #0xe7
	lsls r0, r0, #8
	ldrh r1, [r7, #0xc]
	ands r0, r1
	strh r0, [r7, #0xc]
.L0804AD94:
	movs r0, #0x80
	lsls r0, r0, #6
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq .L0804ADFA
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	bne .L0804ADF0
	ldr r4, .L0804AE4C @ =0x0203CD98
	adds r0, r7, #0
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, #0
	bne .L0804ADF0
	movs r0, #0x80
	lsls r0, r0, #7
	ldrh r3, [r7, #0x10]
	ands r0, r3
	cmp r0, #0
	bne .L0804ADF0
	ldr r4, .L0804AE50 @ =gUnk_Banim_0201E13C
	adds r0, r7, #0
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, [r0]
	ldr r0, [r7, #0x28]
	cmp r1, r0
	beq .L0804ADF0
	adds r0, r7, #0
	bl sub_804AFA0
	adds r0, r7, #0
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, [r7, #0x28]
	str r1, [r0]
.L0804ADF0:
	movs r0, #0xd7
	lsls r0, r0, #8
	ldrh r1, [r7, #0xc]
	ands r0, r1
	strh r0, [r7, #0xc]
.L0804ADFA:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ands r2, r0
	cmp r2, #0
	bne .L0804AE10
	ldr r0, .L0804AE54 @ =gUnk_Banim_0200001C
	ldr r0, [r0]
	cmp r0, #1
	beq .L0804AE10
	b .L0804AF52
.L0804AE10:
	ldrh r1, [r7, #0x10]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0804AE98
	adds r0, r7, #0
	bl sub_804B848
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r8, r0
	beq .L0804AE60
	ldr r6, .L0804AE58 @ =gUnk_Banim_02000000
	adds r0, r7, #0
	bl sub_804B6C4
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r2, [r0]
	adds r0, r2, #0
	mov r1, r8
	str r2, [sp]
	bl sub_804B5E0
	ldr r4, .L0804AE5C @ =0x0000FFFD
	b .L0804AED0
	.align 2, 0
.L0804AE4C: .4byte 0x0203CD98
.L0804AE50: .4byte gUnk_Banim_0201E13C
.L0804AE54: .4byte gUnk_Banim_0200001C
.L0804AE58: .4byte gUnk_Banim_02000000
.L0804AE5C: .4byte 0x0000FFFD
.L0804AE60:
	ldr r5, .L0804AE90 @ =gUnk_Banim_02000000
	adds r0, r7, #0
	bl sub_804B6C4
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r2, [r0]
	ldr r4, .L0804AE94 @ =0x0000FFFD
	adds r0, r4, #0
	ldrh r1, [r2, #0x10]
	ands r0, r1
	strh r0, [r2, #0x10]
	adds r0, r7, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r6, [r0]
	ldrh r2, [r6, #0x10]
	ands r4, r2
	strh r4, [r6, #0x10]
	b .L0804AF52
	.align 2, 0
.L0804AE90: .4byte gUnk_Banim_02000000
.L0804AE94: .4byte 0x0000FFFD
.L0804AE98:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L0804AF18
	adds r0, r7, #0
	bl sub_804B848
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r8, r0
	beq .L0804AF52
	ldr r6, .L0804AF10 @ =gUnk_Banim_02000000
	adds r0, r7, #0
	bl sub_804B6C4
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r2, [r0]
	adds r0, r2, #0
	mov r1, r8
	str r2, [sp]
	bl sub_804B5E0
	ldr r4, .L0804AF14 @ =0x00007FFF
.L0804AED0:
	adds r0, r4, #0
	ldr r2, [sp]
	ldrh r3, [r2, #0x10]
	ands r0, r3
	movs r5, #4
	orrs r0, r5
	strh r0, [r2, #0x10]
	adds r0, r7, #0
	str r2, [sp]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r6, [r0]
	adds r0, r6, #0
	mov r1, r8
	bl sub_804B5E0
	ldrh r0, [r6, #0x10]
	ands r4, r0
	orrs r4, r5
	strh r4, [r6, #0x10]
	ldr r2, [sp]
	ldrh r0, [r2, #0xe]
	adds r0, #1
	strh r0, [r2, #0xe]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	b .L0804AF52
	.align 2, 0
.L0804AF10: .4byte gUnk_Banim_02000000
.L0804AF14: .4byte 0x00007FFF
.L0804AF18:
	adds r0, r7, #0
	bl sub_804B6B0
	cmp r0, #0
	bne .L0804AF52
	adds r0, r7, #0
	bl sub_804B6C4
	adds r1, r0, #0
	ldrh r2, [r7, #0xe]
	lsls r0, r2, #1
	adds r0, r0, r1
	bl sub_804A554
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r8, r0
	bne .L0804AF52
	adds r0, r7, #0
	bl sub_804B6C4
	ldr r1, .L0804AF6C @ =gUnk_Banim_0201E124
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
.L0804AF52:
	mov r2, sb
	cmp r2, #3
	bhi .L0804AF5C
	bl sub_0804A5E8
.L0804AF5C:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804AF6C: .4byte gUnk_Banim_0201E124

	thumb_func_start sub_804AF70
sub_804AF70: @ 0x0804AF70
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0804AF84 @ =gUnk_085CBDD8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804AF84: .4byte gUnk_085CBDD8

	thumb_func_start sub_804AF88
sub_804AF88: @ 0x0804AF88
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804AFA0
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804AFA0
sub_804AFA0: @ 0x0804AFA0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0804AFCC @ =0x000003FF
	ldrh r0, [r5, #8]
	ands r4, r0
	lsls r4, r4, #5
	ldr r0, .L0804AFD0 @ =0x06010000
	adds r4, r4, r0
	ldr r0, [r5, #0x28]
	ldr r1, [r5, #0x2c]
	bl LZ77UnCompWram
	ldr r0, [r5, #0x2c]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r4, #0
	bl RegisterDataMove
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804AFCC: .4byte 0x000003FF
.L0804AFD0: .4byte 0x06010000

	thumb_func_start sub_804AFD4
sub_804AFD4: @ 0x0804AFD4
	adds r2, r0, #0
	ldr r0, .L0804AFF8 @ =0x0203CDD0
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq .L0804AFF4
	movs r1, #0
	adds r3, r2, #0
	adds r3, #0x80
.L0804AFEA:
	ldm r3!, {r0}
	stm r2!, {r0}
	adds r1, #1
	cmp r1, #7
	bls .L0804AFEA
.L0804AFF4:
	bx lr
	.align 2, 0
.L0804AFF8: .4byte 0x0203CDD0

	thumb_func_start sub_804AFFC
sub_804AFFC: @ 0x0804AFFC
	adds r2, r0, #0
	cmp r1, #0
	bne .L0804B00C
	ldr r0, .L0804B008 @ =0x0203CD7C
	b .L0804B00E
	.align 2, 0
.L0804B008: .4byte 0x0203CD7C
.L0804B00C:
	ldr r0, .L0804B024 @ =0x0203CD80
.L0804B00E:
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x11
	beq .L0804B036
	cmp r0, #0x11
	bhi .L0804B028
	cmp r0, #0x10
	beq .L0804B032
	b .L0804B042
	.align 2, 0
.L0804B024: .4byte 0x0203CD80
.L0804B028:
	cmp r0, #0x12
	beq .L0804B03A
	cmp r0, #0x13
	beq .L0804B03E
	b .L0804B042
.L0804B032:
	movs r0, #0xe
	b .L0804B044
.L0804B036:
	movs r0, #0xf
	b .L0804B044
.L0804B03A:
	movs r0, #4
	b .L0804B044
.L0804B03E:
	movs r0, #5
	b .L0804B044
.L0804B042:
	adds r0, r2, #0
.L0804B044:
	bx lr
	.align 2, 0

	thumb_func_start sub_804B048
sub_804B048: @ 0x0804B048
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, .L0804B0F8 @ =0x086A0008
	mov sl, r0
	ldr r1, .L0804B0FC @ =gUnk_Banim_0201E13C
	movs r0, #0
	str r0, [r1, #4]
	str r0, [r1]
	ldr r0, .L0804B100 @ =0x0203CCF8
	ldrh r1, [r0]
	cmp r1, #1
	bne .L0804B140
	ldr r0, .L0804B104 @ =0x0203CD76
	movs r2, #0
	ldrsh r7, [r0, r2]
	ldr r0, .L0804B108 @ =0x0203CD08
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r8, r1
	ldr r0, .L0804B10C @ =0x0203CD04
	movs r1, #0
	ldrsh r4, [r0, r1]
	lsls r0, r7, #5
	ldr r2, .L0804B0F8 @ =0x086A0008
	adds r6, r0, r2
	ldr r0, [r6, #0x10]
	ldr r1, .L0804B110 @ =gUnk_Banim_0200F1C0
	bl LZ77UnCompWram
	ldr r1, .L0804B114 @ =gUnk_Banim_02000054
	ldr r0, [r6, #0xc]
	str r0, [r1]
	adds r0, r7, #0
	movs r1, #0
	bl sub_804AFFC
	lsls r0, r0, #5
	ldr r1, .L0804B0F8 @ =0x086A0008
	adds r0, r0, r1
	ldr r0, [r0, #0x1c]
	ldr r5, .L0804B118 @ =gUnk_Banim_02004080
	adds r1, r5, #0
	bl LZ77UnCompWram
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L0804B0C4
	lsls r0, r4, #4
	ldr r2, .L0804B11C @ =0x087FC008
	adds r0, r0, r2
	ldr r0, [r0, #0xc]
	adds r1, r5, #0
	bl LZ77UnCompWram
	adds r0, r5, #0
	movs r1, #0
	bl sub_804AFD4
.L0804B0C4:
	ldr r1, .L0804B120 @ =gUnk_Banim_0200004C
	mov r2, r8
	lsls r0, r2, #5
	adds r0, r0, r5
	str r0, [r1]
	ldr r4, .L0804B124 @ =gPal+0x2E0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L0804B128 @ =0x0203CD90
	ldr r0, [r0]
	adds r4, #0x20
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	cmp r7, #0x74
	beq .L0804B130
	ldr r0, [r6, #0x18]
	ldr r1, .L0804B12C @ =gUnk_Banim_020041C0
	bl LZ77UnCompWram
	b .L0804B138
	.align 2, 0
.L0804B0F8: .4byte 0x086A0008
.L0804B0FC: .4byte gUnk_Banim_0201E13C
.L0804B100: .4byte 0x0203CCF8
.L0804B104: .4byte 0x0203CD76
.L0804B108: .4byte 0x0203CD08
.L0804B10C: .4byte 0x0203CD04
.L0804B110: .4byte gUnk_Banim_0200F1C0
.L0804B114: .4byte gUnk_Banim_02000054
.L0804B118: .4byte gUnk_Banim_02004080
.L0804B11C: .4byte 0x087FC008
.L0804B120: .4byte gUnk_Banim_0200004C
.L0804B124: .4byte gPal+0x2E0
.L0804B128: .4byte 0x0203CD90
.L0804B12C: .4byte gUnk_Banim_020041C0
.L0804B130:
	ldr r0, [r6, #0x14]
	ldr r1, .L0804B254 @ =gUnk_Banim_020041C0
	bl LZ77UnCompWram
.L0804B138:
	ldr r4, .L0804B258 @ =gUnk_Banim_020099B0
	movs r0, #1
	str r0, [r4]
	ldr r0, .L0804B25C @ =0x0203CCF8
.L0804B140:
	movs r2, #2
	ldrsh r1, [r0, r2]
	mov sb, r1
	cmp r1, #1
	bne .L0804B1DE
	ldr r0, .L0804B260 @ =0x0203CD76
	movs r1, #2
	ldrsh r7, [r0, r1]
	ldr r0, .L0804B264 @ =0x0203CD08
	movs r1, #2
	ldrsh r2, [r0, r1]
	mov r8, r2
	ldr r0, .L0804B268 @ =0x0203CD04
	movs r2, #2
	ldrsh r4, [r0, r2]
	lsls r0, r7, #5
	mov r1, sl
	adds r6, r0, r1
	ldr r0, [r6, #0x10]
	ldr r1, .L0804B26C @ =gUnk_Banim_02011BC0
	bl LZ77UnCompWram
	ldr r1, .L0804B270 @ =gUnk_Banim_02000058
	ldr r0, [r6, #0xc]
	str r0, [r1]
	adds r0, r7, #0
	movs r1, #1
	bl sub_804AFFC
	lsls r0, r0, #5
	add r0, sl
	ldr r0, [r0, #0x1c]
	ldr r5, .L0804B274 @ =gUnk_Banim_02004120
	adds r1, r5, #0
	bl LZ77UnCompWram
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L0804B1A6
	lsls r0, r4, #4
	ldr r2, .L0804B278 @ =0x087FC008
	adds r0, r0, r2
	ldr r0, [r0, #0xc]
	adds r1, r5, #0
	bl LZ77UnCompWram
	adds r0, r5, #0
	movs r1, #1
	bl sub_804AFD4
.L0804B1A6:
	ldr r1, .L0804B27C @ =gUnk_Banim_0200004C
	mov r2, r8
	lsls r0, r2, #5
	adds r0, r0, r5
	str r0, [r1, #4]
	ldr r4, .L0804B280 @ =gPal+0x320
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L0804B284 @ =0x0203CD90
	ldr r0, [r0, #4]
	adds r4, #0x20
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	ldr r0, [r6, #0x14]
	ldr r4, .L0804B288 @ =gUnk_Banim_020099C0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L0804B28C @ =0x000057F0
	adds r4, r4, r0
	mov r1, sb
	str r1, [r4]
.L0804B1DE:
	ldr r6, .L0804B290 @ =0x0203CD88
	ldr r0, [r6]
	cmp r0, #0
	beq .L0804B246
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x30]
	movs r1, #0
	bl sub_8049BAC
	lsls r0, r0, #0x10
	ldr r5, .L0804B284 @ =0x0203CD90
	lsrs r0, r0, #0xb
	add r0, sl
	ldr r0, [r0, #0x1c]
	str r0, [r5]
	ldr r0, [r6]
	bl sub_804A49C
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	movs r7, #1
	rsbs r7, r7, #0
	cmp r4, r7
	beq .L0804B218
	lsls r0, r4, #4
	ldr r2, .L0804B278 @ =0x087FC008
	adds r0, r0, r2
	ldr r0, [r0, #0xc]
	str r0, [r5]
.L0804B218:
	ldr r0, [r6, #4]
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x30]
	movs r1, #0
	bl sub_8049BAC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xb
	add r0, sl
	ldr r0, [r0, #0x1c]
	str r0, [r5, #4]
	ldr r0, [r6, #4]
	bl sub_804A49C
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, r7
	beq .L0804B246
	lsls r0, r4, #4
	ldr r1, .L0804B278 @ =0x087FC008
	adds r0, r0, r1
	ldr r0, [r0, #0xc]
	str r0, [r5, #4]
.L0804B246:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804B254: .4byte gUnk_Banim_020041C0
.L0804B258: .4byte gUnk_Banim_020099B0
.L0804B25C: .4byte 0x0203CCF8
.L0804B260: .4byte 0x0203CD76
.L0804B264: .4byte 0x0203CD08
.L0804B268: .4byte 0x0203CD04
.L0804B26C: .4byte gUnk_Banim_02011BC0
.L0804B270: .4byte gUnk_Banim_02000058
.L0804B274: .4byte gUnk_Banim_02004120
.L0804B278: .4byte 0x087FC008
.L0804B27C: .4byte gUnk_Banim_0200004C
.L0804B280: .4byte gPal+0x320
.L0804B284: .4byte 0x0203CD90
.L0804B288: .4byte gUnk_Banim_020099C0
.L0804B28C: .4byte 0x000057F0
.L0804B290: .4byte 0x0203CD88

	thumb_func_start sub_804B294
sub_804B294: @ 0x0804B294
	push {lr}
	ldr r0, .L0804B2AC @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bhi .L0804B30E
	lsls r0, r0, #2
	ldr r1, .L0804B2B0 @ =.L0804B2B4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804B2AC: .4byte 0x0203CD14
.L0804B2B0: .4byte .L0804B2B4
.L0804B2B4: @ jump table
	.4byte .L0804B2C8 @ case 0
	.4byte .L0804B2D2 @ case 1
	.4byte .L0804B2DC @ case 2
	.4byte .L0804B2C8 @ case 3
	.4byte .L0804B2C8 @ case 4
.L0804B2C8:
	movs r0, #6
	movs r1, #6
	bl sub_804B324
	b .L0804B30E
.L0804B2D2:
	movs r0, #8
	movs r1, #8
	bl sub_804B324
	b .L0804B30E
.L0804B2DC:
	movs r0, #8
	movs r1, #8
	bl sub_804B324
	bl sub_8044870
	cmp r0, #0
	bne .L0804B300
	ldr r1, .L0804B2FC @ =gUnk_Banim_02000000
	ldr r2, [r1, #8]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r2, #2]
	ldr r1, [r1, #0xc]
	b .L0804B30C
	.align 2, 0
.L0804B2FC: .4byte gUnk_Banim_02000000
.L0804B300:
	ldr r1, .L0804B31C @ =gUnk_Banim_02000000
	ldr r2, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r2, #2]
	ldr r1, [r1, #4]
.L0804B30C:
	strh r0, [r1, #2]
.L0804B30E:
	ldr r1, .L0804B320 @ =0x0203CD46
	movs r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	pop {r0}
	bx r0
	.align 2, 0
.L0804B31C: .4byte gUnk_Banim_02000000
.L0804B320: .4byte 0x0203CD46

	thumb_func_start sub_804B324
sub_804B324: @ 0x0804B324
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r6, r1, #0
	ldr r4, .L0804B370 @ =gUnk_Banim_02000000
	movs r0, #0
	str r0, [r4]
	str r0, [r4, #4]
	str r0, [r4, #8]
	str r0, [r4, #0xc]
	ldr r5, .L0804B374 @ =0x0203CCF8
	ldrh r0, [r5]
	cmp r0, #1
	bne .L0804B344
	adds r0, r2, #0
	bl sub_804B37C
.L0804B344:
	ldrh r5, [r5, #2]
	cmp r5, #1
	bne .L0804B350
	adds r0, r6, #0
	bl sub_804B4C0
.L0804B350:
	ldr r0, .L0804B378 @ =0x0203CD14
	ldrh r0, [r0]
	cmp r0, #4
	bne .L0804B36A
	ldr r1, [r4]
	movs r2, #2
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	ldr r1, [r4, #4]
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
.L0804B36A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804B370: .4byte gUnk_Banim_02000000
.L0804B374: .4byte 0x0203CCF8
.L0804B378: .4byte 0x0203CD14

	thumb_func_start sub_804B37C
sub_804B37C: @ 0x0804B37C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r2, .L0804B484 @ =gUnk_08112298
	lsls r1, r7, #2
	adds r0, r1, r2
	ldrb r5, [r0]
	adds r0, r1, #1
	adds r0, r0, r2
	ldrb r6, [r0]
	adds r0, r1, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	mov r8, r0
	adds r1, #3
	adds r1, r1, r2
	ldrb r1, [r1]
	mov sb, r1
	ldr r0, .L0804B488 @ =gUnk_081122C5
	ldr r1, .L0804B48C @ =0x0203CD14
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r1, r0
	ldrb r4, [r0]
	ldr r3, .L0804B490 @ =gUnk_Banim_02000028
	ldr r0, .L0804B494 @ =gUnk_081122D0
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	rsbs r1, r1, #0
	movs r2, #0
	strh r1, [r3]
	ldr r0, .L0804B498 @ =gUnk_Banim_0200002C
	strh r2, [r0]
	ldr r0, .L0804B49C @ =gUnk_Banim_02000020
	adds r1, r1, r4
	strh r1, [r0]
	ldr r1, .L0804B4A0 @ =gUnk_Banim_02000024
	movs r0, #0x58
	strh r0, [r1]
	ldr r0, .L0804B4A4 @ =gUnk_Banim_02000054
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L0804B4A8 @ =gUnk_Banim_0200F1C0
	adds r0, r1, r0
	cmp r5, #0xff
	bne .L0804B3E4
	ldr r0, .L0804B4AC @ =gUnk_085CBDA0
.L0804B3E4:
	adds r1, r6, #0
	bl BasCreate
	adds r2, r0, #0
	ldr r1, .L0804B49C @ =gUnk_Banim_02000020
	ldr r0, .L0804B4B0 @ =gUnk_Banim_0201E12C
	ldrh r1, [r1]
	ldrh r0, [r0]
	subs r0, r1, r0
	movs r1, #0
	strh r0, [r2, #2]
	ldr r0, .L0804B4A0 @ =gUnk_Banim_02000024
	ldrh r0, [r0]
	strh r0, [r2, #4]
	movs r0, #0xf4
	lsls r0, r0, #7
	strh r0, [r2, #8]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r3, #0
	ldrh r3, [r2, #0xc]
	orrs r0, r3
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strb r7, [r2, #0x12]
	ldr r0, .L0804B4B4 @ =gUnk_Banim_02000080
	str r0, [r2, #0x2c]
	ldr r0, .L0804B4B8 @ =gUnk_Banim_020041C0
	str r0, [r2, #0x30]
	ldr r0, .L0804B4BC @ =gUnk_Banim_02000000
	str r2, [r0]
	ldr r0, .L0804B4A4 @ =gUnk_Banim_02000054
	ldr r1, [r0]
	mov r2, r8
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L0804B4A8 @ =gUnk_Banim_0200F1C0
	adds r0, r1, r0
	cmp r2, #0xff
	bne .L0804B438
	ldr r0, .L0804B4AC @ =gUnk_085CBDA0
.L0804B438:
	mov r1, sb
	bl BasCreate
	adds r2, r0, #0
	ldr r1, .L0804B49C @ =gUnk_Banim_02000020
	ldr r0, .L0804B4B0 @ =gUnk_Banim_0201E12C
	ldrh r1, [r1]
	ldrh r0, [r0]
	subs r0, r1, r0
	movs r1, #0
	strh r0, [r2, #2]
	ldr r0, .L0804B4A0 @ =gUnk_Banim_02000024
	ldrh r0, [r0]
	strh r0, [r2, #4]
	movs r0, #0xf4
	lsls r0, r0, #7
	strh r0, [r2, #8]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r0, r3, #0
	ldrh r3, [r2, #0xc]
	orrs r0, r3
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strb r7, [r2, #0x12]
	ldr r0, .L0804B4B4 @ =gUnk_Banim_02000080
	str r0, [r2, #0x2c]
	ldr r0, .L0804B4B8 @ =gUnk_Banim_020041C0
	str r0, [r2, #0x30]
	ldr r0, .L0804B4BC @ =gUnk_Banim_02000000
	str r2, [r0, #4]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804B484: .4byte gUnk_08112298
.L0804B488: .4byte gUnk_081122C5
.L0804B48C: .4byte 0x0203CD14
.L0804B490: .4byte gUnk_Banim_02000028
.L0804B494: .4byte gUnk_081122D0
.L0804B498: .4byte gUnk_Banim_0200002C
.L0804B49C: .4byte gUnk_Banim_02000020
.L0804B4A0: .4byte gUnk_Banim_02000024
.L0804B4A4: .4byte gUnk_Banim_02000054
.L0804B4A8: .4byte gUnk_Banim_0200F1C0
.L0804B4AC: .4byte gUnk_085CBDA0
.L0804B4B0: .4byte gUnk_Banim_0201E12C
.L0804B4B4: .4byte gUnk_Banim_02000080
.L0804B4B8: .4byte gUnk_Banim_020041C0
.L0804B4BC: .4byte gUnk_Banim_02000000

	thumb_func_start sub_804B4C0
sub_804B4C0: @ 0x0804B4C0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r2, .L0804B5A8 @ =gUnk_08112298
	lsls r1, r5, #2
	adds r0, r1, r2
	ldrb r3, [r0]
	adds r0, r1, #1
	adds r0, r0, r2
	ldrb r4, [r0]
	adds r0, r1, #2
	adds r0, r0, r2
	ldrb r6, [r0]
	adds r1, #3
	adds r1, r1, r2
	ldrb r7, [r1]
	ldr r1, .L0804B5AC @ =gUnk_081122CA
	ldr r0, .L0804B5B0 @ =0x0203CD14
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, r0, r1
	ldrb r2, [r0]
	ldr r0, .L0804B5B4 @ =gUnk_Banim_02000028
	movs r1, #0
	strh r1, [r0, #2]
	ldr r0, .L0804B5B8 @ =gUnk_Banim_0200002C
	strh r1, [r0, #2]
	ldr r0, .L0804B5BC @ =gUnk_Banim_02000020
	strh r2, [r0, #2]
	ldr r1, .L0804B5C0 @ =gUnk_Banim_02000024
	movs r0, #0x58
	strh r0, [r1, #2]
	ldr r0, .L0804B5C4 @ =gUnk_Banim_02000058
	ldr r1, [r0]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L0804B5C8 @ =gUnk_Banim_02011BC0
	adds r0, r1, r0
	cmp r3, #0xff
	bne .L0804B512
	ldr r0, .L0804B5CC @ =gUnk_085CBDA0
.L0804B512:
	adds r1, r4, #0
	bl BasCreate
	adds r2, r0, #0
	ldr r1, .L0804B5BC @ =gUnk_Banim_02000020
	ldr r0, .L0804B5D0 @ =gUnk_Banim_0201E12C
	ldrh r1, [r1, #2]
	ldrh r0, [r0]
	subs r0, r1, r0
	movs r1, #0
	strh r0, [r2, #2]
	ldr r0, .L0804B5C0 @ =gUnk_Banim_02000024
	ldrh r0, [r0, #2]
	strh r0, [r2, #4]
	movs r0, #0x9b
	lsls r0, r0, #8
	strh r0, [r2, #8]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r0, r3, #0
	ldrh r3, [r2, #0xc]
	orrs r0, r3
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strb r5, [r2, #0x12]
	ldr r0, .L0804B5D4 @ =gUnk_Banim_02002080
	str r0, [r2, #0x2c]
	ldr r0, .L0804B5D8 @ =gUnk_Banim_020099C0
	str r0, [r2, #0x30]
	ldr r0, .L0804B5DC @ =gUnk_Banim_02000000
	str r2, [r0, #8]
	ldr r0, .L0804B5C4 @ =gUnk_Banim_02000058
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L0804B5C8 @ =gUnk_Banim_02011BC0
	adds r0, r1, r0
	cmp r6, #0xff
	bne .L0804B564
	ldr r0, .L0804B5CC @ =gUnk_085CBDA0
.L0804B564:
	adds r1, r7, #0
	bl BasCreate
	adds r2, r0, #0
	ldr r1, .L0804B5BC @ =gUnk_Banim_02000020
	ldr r0, .L0804B5D0 @ =gUnk_Banim_0201E12C
	ldrh r1, [r1, #2]
	ldrh r0, [r0]
	subs r0, r1, r0
	movs r1, #0
	strh r0, [r2, #2]
	ldr r0, .L0804B5C0 @ =gUnk_Banim_02000024
	ldrh r0, [r0, #2]
	strh r0, [r2, #4]
	movs r0, #0x9b
	lsls r0, r0, #8
	strh r0, [r2, #8]
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r0, r3, #0
	ldrh r3, [r2, #0xc]
	orrs r0, r3
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strb r5, [r2, #0x12]
	ldr r0, .L0804B5D4 @ =gUnk_Banim_02002080
	str r0, [r2, #0x2c]
	ldr r0, .L0804B5D8 @ =gUnk_Banim_020099C0
	str r0, [r2, #0x30]
	ldr r0, .L0804B5DC @ =gUnk_Banim_02000000
	str r2, [r0, #0xc]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804B5A8: .4byte gUnk_08112298
.L0804B5AC: .4byte gUnk_081122CA
.L0804B5B0: .4byte 0x0203CD14
.L0804B5B4: .4byte gUnk_Banim_02000028
.L0804B5B8: .4byte gUnk_Banim_0200002C
.L0804B5BC: .4byte gUnk_Banim_02000020
.L0804B5C0: .4byte gUnk_Banim_02000024
.L0804B5C4: .4byte gUnk_Banim_02000058
.L0804B5C8: .4byte gUnk_Banim_02011BC0
.L0804B5CC: .4byte gUnk_085CBDA0
.L0804B5D0: .4byte gUnk_Banim_0201E12C
.L0804B5D4: .4byte gUnk_Banim_02002080
.L0804B5D8: .4byte gUnk_Banim_020099C0
.L0804B5DC: .4byte gUnk_Banim_02000000

	thumb_func_start sub_804B5E0
sub_804B5E0: @ 0x0804B5E0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	bl sub_804B6B0
	cmp r0, #0
	bne .L0804B600
	ldr r0, .L0804B5FC @ =gUnk_08112298
	lsls r1, r6, #2
	adds r2, r1, r0
	ldrb r5, [r2]
	adds r1, #1
	adds r1, r1, r0
	b .L0804B60E
	.align 2, 0
.L0804B5FC: .4byte gUnk_08112298
.L0804B600:
	ldr r2, .L0804B62C @ =gUnk_08112298
	lsls r1, r6, #2
	adds r0, r1, #2
	adds r0, r0, r2
	ldrb r5, [r0]
	adds r1, #3
	adds r1, r1, r2
.L0804B60E:
	ldrb r7, [r1]
	cmp r5, #0xff
	beq .L0804B654
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804B638
	ldr r0, .L0804B630 @ =gUnk_Banim_02000054
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L0804B634 @ =gUnk_Banim_0200F1C0
	b .L0804B644
	.align 2, 0
.L0804B62C: .4byte gUnk_08112298
.L0804B630: .4byte gUnk_Banim_02000054
.L0804B634: .4byte gUnk_Banim_0200F1C0
.L0804B638:
	ldr r0, .L0804B64C @ =gUnk_Banim_02000058
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L0804B650 @ =gUnk_Banim_02011BC0
.L0804B644:
	adds r1, r1, r0
	str r1, [r4, #0x24]
	str r1, [r4, #0x20]
	b .L0804B65E
	.align 2, 0
.L0804B64C: .4byte gUnk_Banim_02000058
.L0804B650: .4byte gUnk_Banim_02011BC0
.L0804B654:
	ldr r0, .L0804B6A4 @ =gUnk_085CBDA0
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #0x10]
.L0804B65E:
	movs r3, #0
	movs r2, #0
	strh r7, [r4, #0xa]
	ldr r0, .L0804B6A8 @ =0x0000F3FF
	ldrh r1, [r4, #8]
	ands r0, r1
	movs r5, #0x80
	lsls r5, r5, #4
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r4, #8]
	strh r2, [r4, #6]
	movs r0, #0xe0
	lsls r0, r0, #3
	ldrh r1, [r4, #0xc]
	ands r0, r1
	strh r0, [r4, #0xc]
	strb r6, [r4, #0x12]
	strb r3, [r4, #0x14]
	adds r0, r4, #0
	bl sub_804B6C4
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	subs r1, r1, r0
	lsls r1, r1, #0xb
	ldr r0, .L0804B6AC @ =gUnk_Banim_020041C0
	adds r1, r1, r0
	str r1, [r4, #0x30]
	bl BasSort
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804B6A4: .4byte gUnk_085CBDA0
.L0804B6A8: .4byte 0x0000F3FF
.L0804B6AC: .4byte gUnk_Banim_020041C0

	thumb_func_start sub_804B6B0
sub_804B6B0: @ 0x0804B6B0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r0, #0xc]
	ands r1, r0
	cmp r1, #0
	beq .L0804B6C0
	movs r0, #1
	b .L0804B6C2
.L0804B6C0:
	movs r0, #0
.L0804B6C2:
	bx lr

	thumb_func_start sub_804B6C4
sub_804B6C4: @ 0x0804B6C4
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r0, #0xc]
	ands r1, r0
	cmp r1, #0
	beq .L0804B6D4
	movs r0, #1
	b .L0804B6D6
.L0804B6D4:
	movs r0, #0
.L0804B6D6:
	bx lr

	thumb_func_start sub_804B6D8
sub_804B6D8: @ 0x0804B6D8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bhi .L0804B71C
	lsls r0, r0, #2
	ldr r1, .L0804B6EC @ =.L0804B6F0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804B6EC: .4byte .L0804B6F0
.L0804B6F0: @ jump table
	.4byte .L0804B71C @ case 0
	.4byte .L0804B71C @ case 1
	.4byte .L0804B71C @ case 2
	.4byte .L0804B71C @ case 3
	.4byte .L0804B718 @ case 4
	.4byte .L0804B718 @ case 5
	.4byte .L0804B71C @ case 6
	.4byte .L0804B71C @ case 7
	.4byte .L0804B71C @ case 8
	.4byte .L0804B71C @ case 9
.L0804B718:
	movs r0, #1
	b .L0804B71E
.L0804B71C:
	movs r0, #0
.L0804B71E:
	bx lr

	thumb_func_start sub_804B720
sub_804B720: @ 0x0804B720
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bhi .L0804B764
	lsls r0, r0, #2
	ldr r1, .L0804B734 @ =.L0804B738
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804B734: .4byte .L0804B738
.L0804B738: @ jump table
	.4byte .L0804B764 @ case 0
	.4byte .L0804B764 @ case 1
	.4byte .L0804B764 @ case 2
	.4byte .L0804B764 @ case 3
	.4byte .L0804B764 @ case 4
	.4byte .L0804B764 @ case 5
	.4byte .L0804B760 @ case 6
	.4byte .L0804B760 @ case 7
	.4byte .L0804B760 @ case 8
	.4byte .L0804B764 @ case 9
.L0804B760:
	movs r0, #1
	b .L0804B766
.L0804B764:
	movs r0, #0
.L0804B766:
	bx lr

	thumb_func_start sub_804B768
sub_804B768: @ 0x0804B768
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bhi .L0804B7AC
	lsls r0, r0, #2
	ldr r1, .L0804B77C @ =.L0804B780
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804B77C: .4byte .L0804B780
.L0804B780: @ jump table
	.4byte .L0804B7A8 @ case 0
	.4byte .L0804B7A8 @ case 1
	.4byte .L0804B7A8 @ case 2
	.4byte .L0804B7A8 @ case 3
	.4byte .L0804B7AC @ case 4
	.4byte .L0804B7AC @ case 5
	.4byte .L0804B7AC @ case 6
	.4byte .L0804B7AC @ case 7
	.4byte .L0804B7AC @ case 8
	.4byte .L0804B7A8 @ case 9
.L0804B7A8:
	movs r0, #1
	b .L0804B7AE
.L0804B7AC:
	movs r0, #0
.L0804B7AE:
	bx lr

	thumb_func_start sub_804B7B0
sub_804B7B0: @ 0x0804B7B0
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x12]
	cmp r0, #9
	bhi .L0804B806
	lsls r0, r0, #2
	ldr r1, .L0804B7C4 @ =.L0804B7C8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804B7C4: .4byte .L0804B7C8
.L0804B7C8: @ jump table
	.4byte .L0804B806 @ case 0
	.4byte .L0804B802 @ case 1
	.4byte .L0804B806 @ case 2
	.4byte .L0804B7F0 @ case 3
	.4byte .L0804B806 @ case 4
	.4byte .L0804B806 @ case 5
	.4byte .L0804B806 @ case 6
	.4byte .L0804B806 @ case 7
	.4byte .L0804B806 @ case 8
	.4byte .L0804B806 @ case 9
.L0804B7F0:
	adds r0, r2, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804B802
	bl sub_8058998
	cmp r0, #0
	bne .L0804B806
.L0804B802:
	movs r0, #1
	b .L0804B808
.L0804B806:
	movs r0, #0
.L0804B808:
	pop {r1}
	bx r1

	thumb_func_start sub_804B80C
sub_804B80C: @ 0x0804B80C
	push {r4, lr}
	ldr r4, .L0804B824 @ =gUnk_Banim_02000000
	bl sub_804B6C4
	movs r1, #1
	eors r1, r0
	lsls r1, r1, #3
	adds r1, r1, r4
	ldr r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0804B824: .4byte gUnk_Banim_02000000

	thumb_func_start sub_804B828
sub_804B828: @ 0x0804B828
	push {r4, lr}
	adds r4, r0, #0
	bl sub_804B6C4
	adds r1, r0, #0
	ldrh r0, [r4, #0xe]
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	bl sub_804A554
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_804B848
sub_804B848: @ 0x0804B848
	push {r4, lr}
	adds r4, r0, #0
	bl sub_804B6C4
	adds r1, r0, #0
	ldrh r4, [r4, #0xe]
	lsls r0, r4, #1
	adds r0, r0, r1
	bl sub_804A554
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_804B868
sub_804B868: @ 0x0804B868
	push {r4, lr}
	adds r4, r0, #0
	bl sub_804B6C4
	adds r2, r0, #0
	ldrh r0, [r4, #0xe]
	subs r0, #1
	lsls r0, r0, #1
	movs r1, #1
	eors r1, r2
	adds r0, r0, r1
	bl sub_804A554
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_804B88C
sub_804B88C: @ 0x0804B88C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_804B6C4
	adds r2, r0, #0
	ldrh r4, [r4, #0xe]
	lsls r0, r4, #1
	movs r1, #1
	eors r1, r2
	adds r0, r0, r1
	bl sub_804A554
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_804B8B0
sub_804B8B0: @ 0x0804B8B0
	cmp r0, #0
	bne .L0804B8C8
	ldr r2, .L0804B8C4 @ =gUnk_Banim_02000000
	ldr r3, [r2]
	movs r1, #2
	ldrh r0, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r3, [r2, #4]
	b .L0804B8DA
	.align 2, 0
.L0804B8C4: .4byte gUnk_Banim_02000000
.L0804B8C8:
	cmp r0, #1
	bne .L0804B8E0
	ldr r2, .L0804B8E4 @ =gUnk_Banim_02000000
	ldr r3, [r2, #8]
	movs r1, #2
	ldrh r0, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r3, [r2, #0xc]
.L0804B8DA:
	ldrh r0, [r3]
	orrs r0, r1
	strh r0, [r3]
.L0804B8E0:
	bx lr
	.align 2, 0
.L0804B8E4: .4byte gUnk_Banim_02000000

	thumb_func_start sub_804B8E8
sub_804B8E8: @ 0x0804B8E8
	push {r4, lr}
	cmp r0, #0
	bne .L0804B908
	ldr r2, .L0804B900 @ =gUnk_Banim_02000000
	ldr r3, [r2]
	ldr r1, .L0804B904 @ =0x0000FFFD
	adds r0, r1, #0
	ldrh r4, [r3]
	ands r0, r4
	strh r0, [r3]
	ldr r3, [r2, #4]
	b .L0804B91C
	.align 2, 0
.L0804B900: .4byte gUnk_Banim_02000000
.L0804B904: .4byte 0x0000FFFD
.L0804B908:
	cmp r0, #1
	bne .L0804B922
	ldr r2, .L0804B928 @ =gUnk_Banim_02000000
	ldr r3, [r2, #8]
	ldr r1, .L0804B92C @ =0x0000FFFD
	adds r0, r1, #0
	ldrh r4, [r3]
	ands r0, r4
	strh r0, [r3]
	ldr r3, [r2, #0xc]
.L0804B91C:
	ldrh r0, [r3]
	ands r1, r0
	strh r1, [r3]
.L0804B922:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804B928: .4byte gUnk_Banim_02000000
.L0804B92C: .4byte 0x0000FFFD

	thumb_func_start sub_804B930
sub_804B930: @ 0x0804B930
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	bne .L0804B93C
	b .L0804BAC2
.L0804B93C:
	movs r5, #0xf0
	lsls r5, r5, #8
	ldrh r0, [r4, #0xc]
	ands r5, r0
	cmp r5, #0
	bne .L0804B94A
	b .L0804BAC2
.L0804B94A:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r5
	cmp r0, #0
	bne .L0804B956
	b .L0804BA84
.L0804B956:
	ldrb r0, [r4, #0x14]
	cmp r0, #0
	bne .L0804B95E
	b .L0804BA7A
.L0804B95E:
	ldrb r1, [r4, #0x14]
	adds r0, r1, r4
	ldrb r0, [r0, #0x14]
	cmp r0, #0x32
	bls .L0804B96A
	b .L0804BA72
.L0804B96A:
	lsls r0, r0, #2
	ldr r1, .L0804B974 @ =.L0804B978
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804B974: .4byte .L0804B978
.L0804B978: @ jump table
	.4byte .L0804BA72 @ case 0
	.4byte .L0804BA44 @ case 1
	.4byte .L0804BA44 @ case 2
	.4byte .L0804BA5C @ case 3
	.4byte .L0804BA5C @ case 4
	.4byte .L0804BA4C @ case 5
	.4byte .L0804BA72 @ case 6
	.4byte .L0804BA72 @ case 7
	.4byte .L0804BA72 @ case 8
	.4byte .L0804BA72 @ case 9
	.4byte .L0804BA72 @ case 10
	.4byte .L0804BA72 @ case 11
	.4byte .L0804BA72 @ case 12
	.4byte .L0804BA64 @ case 13
	.4byte .L0804BA72 @ case 14
	.4byte .L0804BA72 @ case 15
	.4byte .L0804BA72 @ case 16
	.4byte .L0804BA72 @ case 17
	.4byte .L0804BA72 @ case 18
	.4byte .L0804BA72 @ case 19
	.4byte .L0804BA72 @ case 20
	.4byte .L0804BA72 @ case 21
	.4byte .L0804BA72 @ case 22
	.4byte .L0804BA72 @ case 23
	.4byte .L0804BA6C @ case 24
	.4byte .L0804BA72 @ case 25
	.4byte .L0804BA72 @ case 26
	.4byte .L0804BA72 @ case 27
	.4byte .L0804BA72 @ case 28
	.4byte .L0804BA72 @ case 29
	.4byte .L0804BA72 @ case 30
	.4byte .L0804BA72 @ case 31
	.4byte .L0804BA72 @ case 32
	.4byte .L0804BA72 @ case 33
	.4byte .L0804BA72 @ case 34
	.4byte .L0804BA72 @ case 35
	.4byte .L0804BA72 @ case 36
	.4byte .L0804BA72 @ case 37
	.4byte .L0804BA72 @ case 38
	.4byte .L0804BA72 @ case 39
	.4byte .L0804BA72 @ case 40
	.4byte .L0804BA72 @ case 41
	.4byte .L0804BA72 @ case 42
	.4byte .L0804BA72 @ case 43
	.4byte .L0804BA72 @ case 44
	.4byte .L0804BA72 @ case 45
	.4byte .L0804BA72 @ case 46
	.4byte .L0804BA72 @ case 47
	.4byte .L0804BA72 @ case 48
	.4byte .L0804BA72 @ case 49
	.4byte .L0804BA72 @ case 50
.L0804BA44:
	adds r0, r4, #0
	bl sub_804BACC
	b .L0804BA72
.L0804BA4C:
	adds r0, r4, #0
	bl sub_804B6B0
	cmp r0, #0
	bne .L0804BA5C
	adds r0, r4, #0
	bl sub_8058158
.L0804BA5C:
	ldr r0, [r4, #0x20]
	adds r0, #4
	str r0, [r4, #0x20]
	b .L0804BA72
.L0804BA64:
	adds r0, r4, #0
	bl sub_804BAF0
	b .L0804BA72
.L0804BA6C:
	adds r0, r4, #0
	bl sub_804BACC
.L0804BA72:
	ldrb r0, [r4, #0x14]
	subs r0, #1
	strb r0, [r4, #0x14]
	b .L0804B956
.L0804BA7A:
	movs r0, #0xe7
	lsls r0, r0, #8
	ldrh r1, [r4, #0xc]
	ands r0, r1
	strh r0, [r4, #0xc]
.L0804BA84:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r5
	cmp r0, #0
	beq .L0804BAB4
	adds r0, r4, #0
	bl sub_804B6B0
	cmp r0, #0
	bne .L0804BAAA
	ldr r1, [r6, #0x28]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	beq .L0804BAAA
	adds r0, r4, #0
	bl sub_804AFA0
	ldr r0, [r4, #0x28]
	str r0, [r6, #0x28]
.L0804BAAA:
	movs r0, #0xd7
	lsls r0, r0, #8
	ldrh r1, [r4, #0xc]
	ands r0, r1
	strh r0, [r4, #0xc]
.L0804BAB4:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r5, r0
	cmp r5, #0
	beq .L0804BAC2
	ldr r0, .L0804BAC8 @ =0x0000FFFF
	strh r0, [r4, #0xe]
.L0804BAC2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804BAC8: .4byte 0x0000FFFF

	thumb_func_start sub_804BACC
sub_804BACC: @ 0x0804BACC
	adds r1, r0, #0
	ldr r0, .L0804BAEC @ =0x0000FFFE
	strh r0, [r1, #0xe]
	movs r0, #8
	ldrh r2, [r1, #0x10]
	ands r0, r2
	cmp r0, #0
	beq .L0804BAE8
	strh r0, [r1, #0x10]
	movs r0, #0
	strh r0, [r1, #0xe]
	ldr r0, [r1, #0x20]
	adds r0, #4
	str r0, [r1, #0x20]
.L0804BAE8:
	bx lr
	.align 2, 0
.L0804BAEC: .4byte 0x0000FFFE

	thumb_func_start sub_804BAF0
sub_804BAF0: @ 0x0804BAF0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, [r7, #0x44]
	bl sub_804B6B0
	cmp r0, #0
	bne .L0804BB40
	ldr r3, .L0804BB48 @ =gUnk_08112298
	ldrh r1, [r6, #6]
	lsls r0, r1, #5
	ldr r1, .L0804BB4C @ =0x086A0008
	adds r0, r0, r1
	ldr r1, [r0, #0xc]
	ldr r2, [r6, #0x10]
	ldr r4, [r6, #0x14]
	ldr r5, [r6, #0x24]
	ldrb r3, [r3, #0x18]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r5, r0
	ldr r0, [r1, #4]
	str r0, [r2, #0x28]
	ldr r5, [r2, #0x30]
	ldr r0, [r1, #8]
	adds r5, r5, r0
	str r5, [r2, #0x3c]
	ldr r5, [r4, #0x30]
	ldr r0, .L0804BB50 @ =0x000057F0
	adds r5, r5, r0
	str r5, [r4, #0x3c]
	ldr r1, [r6, #0x28]
	ldr r0, [r7, #0x28]
	cmp r1, r0
	beq .L0804BB40
	adds r0, r7, #0
	bl sub_804AF70
	ldr r0, [r7, #0x28]
	str r0, [r6, #0x28]
.L0804BB40:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804BB48: .4byte gUnk_08112298
.L0804BB4C: .4byte 0x086A0008
.L0804BB50: .4byte 0x000057F0

	thumb_func_start sub_804BB54
sub_804BB54: @ 0x0804BB54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, .L0804BBD8 @ =0x086A0008
	mov sb, r0
	ldr r2, .L0804BBDC @ =gUnk_08112298
	ldrh r3, [r6, #8]
	lsls r1, r3, #2
	adds r0, r1, r2
	ldrb r4, [r0]
	adds r0, r1, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r1, #2
	adds r0, r0, r2
	ldrb r5, [r0]
	adds r1, #3
	adds r1, r1, r2
	ldrb r1, [r1]
	str r1, [sp]
	ldrh r1, [r6, #6]
	lsls r0, r1, #5
	add r0, sb
	ldr r0, [r0, #0x10]
	ldr r1, [r6, #0x24]
	bl LZ77UnCompWram
	ldrh r2, [r6, #6]
	lsls r0, r2, #5
	mov r3, sb
	adds r1, r0, r3
	ldr r2, [r1, #0xc]
	ldr r3, [r6, #0x24]
	ldr r7, .L0804BBE0 @ =gUnk_085CBDA0
	cmp r4, #0xff
	beq .L0804BBAE
	lsls r0, r4, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r7, r3, r0
.L0804BBAE:
	ldr r0, .L0804BBE0 @ =gUnk_085CBDA0
	mov sl, r0
	cmp r5, #0xff
	beq .L0804BBC0
	lsls r0, r5, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r3, r3, r0
	mov sl, r3
.L0804BBC0:
	ldrh r0, [r6, #0xa]
	cmp r0, #0
	bne .L0804BBE8
	ldr r4, [r6, #0x20]
	ldr r0, [r1, #0x18]
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r2, .L0804BBE4 @ =0x000057F0
	adds r1, r4, r2
	b .L0804BBF6
	.align 2, 0
.L0804BBD8: .4byte 0x086A0008
.L0804BBDC: .4byte gUnk_08112298
.L0804BBE0: .4byte gUnk_085CBDA0
.L0804BBE4: .4byte 0x000057F0
.L0804BBE8:
	ldr r4, [r6, #0x20]
	ldr r0, [r1, #0x14]
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r3, .L0804BCC0 @ =0x000057F0
	adds r1, r4, r3
.L0804BBF6:
	movs r0, #1
	str r0, [r1]
	mov r1, r8
	adds r0, r7, #0
	bl BasCreate
	adds r2, r0, #0
	ldr r0, [r6, #0x20]
	str r0, [r2, #0x30]
	ldrh r0, [r6, #2]
	movs r4, #0
	strh r0, [r2, #2]
	ldrh r0, [r6, #4]
	strh r0, [r2, #4]
	ldrh r1, [r6, #0xe]
	lsls r0, r1, #0xc
	movs r3, #0x80
	lsls r3, r3, #4
	adds r5, r3, #0
	orrs r0, r5
	ldrh r1, [r6, #0xc]
	orrs r0, r1
	strh r0, [r2, #8]
	ldrh r3, [r6, #0xa]
	lsls r0, r3, #9
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	ldrh r1, [r2, #0xc]
	orrs r0, r1
	strh r0, [r2, #0xc]
	strh r4, [r2, #0xe]
	ldrh r0, [r6, #8]
	strb r0, [r2, #0x12]
	ldr r0, [r6, #0x18]
	str r0, [r2, #0x2c]
	str r2, [r6, #0x10]
	str r6, [r2, #0x44]
	ldr r1, [sp]
	mov r0, sl
	bl BasCreate
	adds r2, r0, #0
	ldr r0, [r6, #0x20]
	str r0, [r2, #0x30]
	ldrh r0, [r6, #2]
	strh r0, [r2, #2]
	ldrh r0, [r6, #4]
	strh r0, [r2, #4]
	ldrh r3, [r6, #0xe]
	lsls r0, r3, #0xc
	orrs r0, r5
	ldrh r1, [r6, #0xc]
	orrs r0, r1
	strh r0, [r2, #8]
	ldrh r3, [r6, #0xa]
	lsls r0, r3, #9
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	ldrh r1, [r2, #0xc]
	orrs r0, r1
	strh r0, [r2, #0xc]
	strh r4, [r2, #0xe]
	ldrh r0, [r6, #8]
	strb r0, [r2, #0x12]
	ldr r0, [r6, #0x18]
	str r0, [r2, #0x2c]
	str r2, [r6, #0x14]
	str r6, [r2, #0x44]
	ldrh r2, [r6, #6]
	lsls r0, r2, #5
	add r0, sb
	ldr r0, [r0, #0x1c]
	ldr r1, [r6, #0x1c]
	bl LZ77UnCompWram
	ldrb r3, [r6, #1]
	lsls r1, r3, #5
	ldr r0, [r6, #0x1c]
	adds r0, r0, r1
	ldrh r2, [r6, #0xe]
	lsls r1, r2, #5
	ldr r2, .L0804BCC4 @ =gPal+0x200
	adds r1, r1, r2
	movs r2, #8
	bl CpuFastSet
	str r4, [r6, #0x28]
	bl EnablePalSync
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804BCC0: .4byte 0x000057F0
.L0804BCC4: .4byte gPal+0x200

	thumb_func_start sub_804BCC8
sub_804BCC8: @ 0x0804BCC8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldr r0, .L0804BD38 @ =0x086A0008
	mov sb, r0
	ldr r2, .L0804BD3C @ =gUnk_08112298
	ldrh r1, [r6, #8]
	lsls r0, r1, #2
	adds r1, r0, r2
	ldrb r4, [r1]
	adds r0, #2
	adds r0, r0, r2
	ldrb r5, [r0]
	ldrh r2, [r6, #6]
	lsls r0, r2, #5
	add r0, sb
	ldr r0, [r0, #0x10]
	ldr r1, [r6, #0x24]
	bl LZ77UnCompWram
	ldrh r3, [r6, #6]
	lsls r0, r3, #5
	mov r7, sb
	adds r1, r0, r7
	ldr r2, [r1, #0xc]
	ldr r3, [r6, #0x24]
	ldr r7, .L0804BD40 @ =gUnk_085CBDA0
	cmp r4, #0xff
	beq .L0804BD0E
	lsls r0, r4, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r7, r3, r0
.L0804BD0E:
	ldr r0, .L0804BD40 @ =gUnk_085CBDA0
	mov r8, r0
	cmp r5, #0xff
	beq .L0804BD20
	lsls r0, r5, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r3, r3, r0
	mov r8, r3
.L0804BD20:
	ldrh r0, [r6, #0xa]
	cmp r0, #0
	bne .L0804BD48
	ldr r4, [r6, #0x20]
	ldr r0, [r1, #0x18]
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r2, .L0804BD44 @ =0x000057F0
	adds r1, r4, r2
	b .L0804BD56
	.align 2, 0
.L0804BD38: .4byte 0x086A0008
.L0804BD3C: .4byte gUnk_08112298
.L0804BD40: .4byte gUnk_085CBDA0
.L0804BD44: .4byte 0x000057F0
.L0804BD48:
	ldr r4, [r6, #0x20]
	ldr r0, [r1, #0x14]
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r3, .L0804BE0C @ =0x000057F0
	adds r1, r4, r3
.L0804BD56:
	movs r0, #1
	str r0, [r1]
	ldr r5, [r6, #0x10]
	str r7, [r5, #0x24]
	str r7, [r5, #0x20]
	ldr r0, [r6, #0x20]
	str r0, [r5, #0x30]
	ldrh r0, [r6, #2]
	movs r4, #0
	movs r2, #0
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	strh r0, [r5, #4]
	ldrh r7, [r6, #0xe]
	lsls r0, r7, #0xc
	movs r1, #0x80
	lsls r1, r1, #4
	adds r3, r1, #0
	orrs r0, r3
	ldrh r7, [r6, #0xc]
	orrs r0, r7
	strh r0, [r5, #8]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r0, r1, #0
	ldrh r7, [r5, #0xc]
	ands r0, r7
	strh r0, [r5, #0xc]
	strh r2, [r5, #0x10]
	strh r2, [r5, #6]
	strh r2, [r5, #0xe]
	ldrh r0, [r6, #8]
	strb r0, [r5, #0x12]
	ldr r0, [r6, #0x18]
	str r0, [r5, #0x2c]
	strb r4, [r5, #0x14]
	str r5, [r6, #0x10]
	ldr r5, [r6, #0x14]
	mov r0, r8
	str r0, [r5, #0x24]
	str r0, [r5, #0x20]
	ldr r0, [r6, #0x20]
	str r0, [r5, #0x30]
	ldrh r0, [r6, #2]
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	strh r0, [r5, #4]
	ldrh r7, [r6, #0xe]
	lsls r0, r7, #0xc
	orrs r0, r3
	ldrh r3, [r6, #0xc]
	orrs r0, r3
	strh r0, [r5, #8]
	ldrh r7, [r5, #0xc]
	ands r1, r7
	strh r1, [r5, #0xc]
	strh r2, [r5, #0x10]
	strh r2, [r5, #6]
	strh r2, [r5, #0xe]
	ldrh r0, [r6, #8]
	strb r0, [r5, #0x12]
	ldr r0, [r6, #0x18]
	str r0, [r5, #0x2c]
	strb r4, [r5, #0x14]
	str r5, [r6, #0x14]
	ldrh r1, [r6, #6]
	lsls r0, r1, #5
	add r0, sb
	ldr r0, [r0, #0x1c]
	ldr r1, [r6, #0x1c]
	bl LZ77UnCompWram
	ldrb r2, [r6, #1]
	lsls r1, r2, #5
	ldr r0, [r6, #0x1c]
	adds r0, r0, r1
	ldrh r6, [r6, #0xe]
	lsls r1, r6, #5
	ldr r2, .L0804BE10 @ =gPal+0x200
	adds r1, r1, r2
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804BE0C: .4byte 0x000057F0
.L0804BE10: .4byte gPal+0x200

	thumb_func_start sub_804BE14
sub_804BE14: @ 0x0804BE14
	push {lr}
	strh r1, [r0, #6]
	bl sub_804BCC8
	pop {r0}
	bx r0

	thumb_func_start sub_804BE20
sub_804BE20: @ 0x0804BE20
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	strh r1, [r0, #2]
	strh r2, [r0, #4]
	ldr r2, [r0, #0x10]
	strh r1, [r2, #2]
	ldrh r1, [r0, #4]
	strh r1, [r2, #4]
	ldr r2, [r0, #0x14]
	ldrh r1, [r0, #2]
	strh r1, [r2, #2]
	ldrh r0, [r0, #4]
	strh r0, [r2, #4]
	bx lr

	thumb_func_start sub_804BE3C
sub_804BE3C: @ 0x0804BE3C
	lsls r1, r1, #0x10
	ldr r2, [r0, #0x10]
	lsrs r1, r1, #6
	strh r1, [r2, #8]
	ldr r2, [r0, #0x14]
	strh r1, [r2, #8]
	bx lr
	.align 2, 0

	thumb_func_start sub_804BE4C
sub_804BE4C: @ 0x0804BE4C
	ldr r1, [r0, #0x10]
	ldr r2, [r0, #0x14]
	ldr r0, .L0804BE64 @ =0x0000FFFE
	ldrh r1, [r1, #0xe]
	cmp r1, r0
	beq .L0804BE68
	ldrh r2, [r2, #0xe]
	cmp r2, r0
	beq .L0804BE68
	movs r0, #0
	b .L0804BE6A
	.align 2, 0
.L0804BE64: .4byte 0x0000FFFE
.L0804BE68:
	movs r0, #1
.L0804BE6A:
	bx lr

	thumb_func_start sub_804BE6C
sub_804BE6C: @ 0x0804BE6C
	ldr r3, [r0, #0x10]
	movs r2, #8
	ldrh r1, [r3, #0x10]
	orrs r1, r2
	strh r1, [r3, #0x10]
	ldr r3, [r0, #0x14]
	ldrh r0, [r3, #0x10]
	orrs r0, r2
	strh r0, [r3, #0x10]
	bx lr

	thumb_func_start sub_804BE80
sub_804BE80: @ 0x0804BE80
	ldr r1, [r0, #0x10]
	ldr r0, .L0804BE90 @ =0x0000FFFF
	ldrh r1, [r1, #0xe]
	cmp r1, r0
	bne .L0804BE94
	movs r0, #1
	b .L0804BE96
	.align 2, 0
.L0804BE90: .4byte 0x0000FFFF
.L0804BE94:
	movs r0, #0
.L0804BE96:
	bx lr

	thumb_func_start sub_804BE98
sub_804BE98: @ 0x0804BE98
	push {r4, lr}
	ldr r4, .L0804BEB0 @ =gUnk_Banim_0201E138
	ldr r0, .L0804BEB4 @ =gUnk_085CBDF0
	movs r1, #4
	bl SpawnProc
	str r0, [r4]
	bl BasInit
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804BEB0: .4byte gUnk_Banim_0201E138
.L0804BEB4: .4byte gUnk_085CBDF0

	thumb_func_start sub_804BEB8
sub_804BEB8: @ 0x0804BEB8
	push {lr}
	ldr r0, .L0804BEC8 @ =gUnk_Banim_0201E138
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L0804BEC8: .4byte gUnk_Banim_0201E138

	thumb_func_start sub_804BECC
sub_804BECC: @ 0x0804BECC
	push {lr}
	bl BasUpdateAll
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804BED8
sub_804BED8: @ 0x0804BED8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L0804BEFC @ =gUnk_085CBE08
	movs r1, #4
	bl SpawnProc
	adds r5, r0, #0
	adds r0, r4, #0
	bl sub_804BB54
	str r4, [r5, #0x5c]
	str r5, [r4, #0x30]
	movs r0, #1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804BEFC: .4byte gUnk_085CBE08

	thumb_func_start sub_804BF00
sub_804BF00: @ 0x0804BF00
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x10]
	bl BasRemove
	ldr r0, [r4, #0x14]
	bl BasRemove
	movs r0, #0
	str r0, [r4, #0x10]
	str r0, [r4, #0x14]
	ldr r0, [r4, #0x30]
	bl Proc_End
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804BF24
sub_804BF24: @ 0x0804BF24
	push {r4, lr}
	ldr r4, [r0, #0x5c]
	ldr r1, [r4, #0x10]
	adds r0, r4, #0
	bl sub_804B930
	ldr r1, [r4, #0x14]
	adds r0, r4, #0
	bl sub_804B930
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804BF40
sub_804BF40: @ 0x0804BF40
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r0, #0
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r2, .L0804BFA8 @ =0x087EA008
	adds r0, r0, r2
	mov r8, r0
	movs r0, #6
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r5, r0, r2
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r4, #1
	rsbs r4, r4, #0
	cmp r0, r4
	beq .L0804BF7E
	mov r2, r8
	ldr r0, [r2, #0xc]
	ldr r1, [r6, #0x20]
	bl LZ77UnCompWram
.L0804BF7E:
	movs r1, #6
	ldrsh r0, [r6, r1]
	cmp r0, r4
	beq .L0804BF94
	ldr r0, [r5, #0xc]
	ldr r1, [r6, #0x20]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl LZ77UnCompWram
.L0804BF94:
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	cmp r0, #3
	bgt .L0804BFAC
	cmp r0, #1
	bge .L0804BFBA
	cmp r0, #0
	beq .L0804BFB0
	b .L0804BFBA
	.align 2, 0
.L0804BFA8: .4byte 0x087EA008
.L0804BFAC:
	cmp r0, #4
	bne .L0804BFBA
.L0804BFB0:
	ldr r3, [r6, #0x20]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r7, r3, r2
	b .L0804BFC8
.L0804BFBA:
	ldr r0, [r6, #0x20]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r3, r0, r1
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r7, r0, r2
.L0804BFC8:
	mov r0, r8
	ldr r0, [r0, #0x10]
	mov r8, r0
	ldr r5, [r5, #0x10]
	mov sb, r5
	movs r1, #0xe
	ldrsh r4, [r6, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L0804C04C
	cmp r4, r0
	blt .L0804C0AC
	cmp r4, #3
	bgt .L0804C0AC
	movs r2, #4
	ldrsh r0, [r6, r2]
	adds r0, #0x40
	lsls r0, r0, #5
	movs r4, #0xc0
	lsls r4, r4, #0x13
	adds r0, r0, r4
	ldr r1, [r6, #0x1c]
	adds r1, r1, r0
	movs r5, #0x80
	lsls r5, r5, #4
	adds r0, r3, #0
	adds r2, r5, #0
	bl RegisterDataMove
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	lsls r0, r0, #5
	adds r0, r0, r4
	ldr r1, [r6, #0x1c]
	adds r1, r1, r0
	adds r0, r7, #0
	adds r2, r5, #0
	bl RegisterDataMove
	movs r2, #2
	ldrsh r1, [r6, r2]
	lsls r1, r1, #5
	ldr r4, .L0804C048 @ =gPal
	adds r1, r1, r4
	mov r0, r8
	movs r2, #8
	bl CpuFastSet
	movs r0, #8
	ldrsh r1, [r6, r0]
	lsls r1, r1, #5
	adds r1, r1, r4
	mov r0, sb
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	adds r0, r6, #0
	bl sub_804C330
	b .L0804C0AC
	.align 2, 0
.L0804C048: .4byte gPal
.L0804C04C:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, r4
	beq .L0804C07A
	movs r2, #4
	ldrsh r0, [r6, r2]
	lsls r0, r0, #5
	ldr r1, [r6, #0x1c]
	adds r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r3, #0
	bl RegisterDataMove
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r1, r1, #5
	ldr r0, .L0804C0C4 @ =gPal+0x200
	adds r1, r1, r0
	mov r0, r8
	movs r2, #8
	bl CpuFastSet
.L0804C07A:
	movs r1, #6
	ldrsh r0, [r6, r1]
	cmp r0, r4
	beq .L0804C0A8
	movs r2, #0xa
	ldrsh r0, [r6, r2]
	lsls r0, r0, #5
	ldr r1, [r6, #0x1c]
	adds r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r7, #0
	bl RegisterDataMove
	movs r0, #8
	ldrsh r1, [r6, r0]
	lsls r1, r1, #5
	ldr r0, .L0804C0C4 @ =gPal+0x200
	adds r1, r1, r0
	mov r0, sb
	movs r2, #8
	bl CpuFastSet
.L0804C0A8:
	bl EnablePalSync
.L0804C0AC:
	ldrh r0, [r6, #0xe]
	adds r0, #1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bls .L0804C0BA
	b .L0804C2DA
.L0804C0BA:
	lsls r0, r0, #2
	ldr r1, .L0804C0C8 @ =.L0804C0CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804C0C4: .4byte gPal+0x200
.L0804C0C8: .4byte .L0804C0CC
.L0804C0CC: @ jump table
	.4byte .L0804C100 @ case 0
	.4byte .L0804C0E0 @ case 1
	.4byte .L0804C0E8 @ case 2
	.4byte .L0804C0F0 @ case 3
	.4byte .L0804C0F8 @ case 4
.L0804C0E0:
	movs r0, #1
	bl EnableBgSync
	b .L0804C2DA
.L0804C0E8:
	movs r0, #2
	bl EnableBgSync
	b .L0804C2DA
.L0804C0F0:
	movs r0, #4
	bl EnableBgSync
	b .L0804C2DA
.L0804C0F8:
	movs r0, #8
	bl EnableBgSync
	b .L0804C2DA
.L0804C100:
	movs r0, #0
	str r0, [r6, #0x14]
	str r0, [r6, #0x18]
	movs r2, #0
	ldrsh r1, [r6, r2]
	subs r0, #1
	cmp r1, r0
	beq .L0804C1EE
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	cmp r0, #4
	bhi .L0804C1EE
	lsls r0, r0, #2
	ldr r1, .L0804C124 @ =.L0804C128
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804C124: .4byte .L0804C128
.L0804C128: @ jump table
	.4byte .L0804C13C @ case 0
	.4byte .L0804C168 @ case 1
	.4byte .L0804C194 @ case 2
	.4byte .L0804C1C0 @ case 3
	.4byte .L0804C13C @ case 4
.L0804C13C:
	movs r2, #2
	ldrsh r0, [r6, r2]
	lsls r0, r0, #0xc
	ldrh r1, [r6, #4]
	orrs r0, r1
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C164 @ =gUnk_085CCF38
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0x48
	b .L0804C1E4
	.align 2, 0
.L0804C164: .4byte gUnk_085CCF38
.L0804C168:
	movs r1, #2
	ldrsh r0, [r6, r1]
	lsls r0, r0, #0xc
	ldrh r2, [r6, #4]
	orrs r0, r2
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C190 @ =gUnk_085CCE38
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0x20
	b .L0804C1E4
	.align 2, 0
.L0804C190: .4byte gUnk_085CCE38
.L0804C194:
	movs r1, #2
	ldrsh r0, [r6, r1]
	lsls r0, r0, #0xc
	ldrh r2, [r6, #4]
	orrs r0, r2
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C1BC @ =gUnk_085CCE38
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0x40
	b .L0804C1E4
	.align 2, 0
.L0804C1BC: .4byte gUnk_085CCE38
.L0804C1C0:
	movs r1, #2
	ldrsh r0, [r6, r1]
	lsls r0, r0, #0xc
	ldrh r2, [r6, #4]
	orrs r0, r2
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C20C @ =gUnk_085CCF38
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0x78
.L0804C1E4:
	movs r1, #0x68
	movs r3, #2
	bl sub_805B9E0
	str r0, [r6, #0x14]
.L0804C1EE:
	movs r0, #6
	ldrsh r1, [r6, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L0804C2DA
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	cmp r0, #4
	bhi .L0804C2DA
	lsls r0, r0, #2
	ldr r1, .L0804C210 @ =.L0804C214
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804C20C: .4byte gUnk_085CCF38
.L0804C210: .4byte .L0804C214
.L0804C214: @ jump table
	.4byte .L0804C228 @ case 0
	.4byte .L0804C254 @ case 1
	.4byte .L0804C280 @ case 2
	.4byte .L0804C2AC @ case 3
	.4byte .L0804C228 @ case 4
.L0804C228:
	movs r2, #8
	ldrsh r0, [r6, r2]
	lsls r0, r0, #0xc
	ldrh r1, [r6, #0xa]
	orrs r0, r1
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C250 @ =gUnk_085CCEB8
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0xa8
	b .L0804C2D0
	.align 2, 0
.L0804C250: .4byte gUnk_085CCEB8
.L0804C254:
	movs r1, #8
	ldrsh r0, [r6, r1]
	lsls r0, r0, #0xc
	ldrh r2, [r6, #0xa]
	orrs r0, r2
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C27C @ =gUnk_085CCDAC
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0xb0
	b .L0804C2D0
	.align 2, 0
.L0804C27C: .4byte gUnk_085CCDAC
.L0804C280:
	movs r1, #8
	ldrsh r0, [r6, r1]
	lsls r0, r0, #0xc
	ldrh r2, [r6, #0xa]
	orrs r0, r2
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C2A8 @ =gUnk_085CCDAC
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0xb0
	b .L0804C2D0
	.align 2, 0
.L0804C2A8: .4byte gUnk_085CCDAC
.L0804C2AC:
	movs r1, #8
	ldrsh r0, [r6, r1]
	lsls r0, r0, #0xc
	ldrh r2, [r6, #0xa]
	orrs r0, r2
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C2E8 @ =gUnk_085CCDAC
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0x80
.L0804C2D0:
	movs r1, #0x68
	movs r3, #2
	bl sub_805B9E0
	str r0, [r6, #0x18]
.L0804C2DA:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C2E8: .4byte gUnk_085CCDAC

	thumb_func_start sub_804C2EC
sub_804C2EC: @ 0x0804C2EC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe
	ldrsh r1, [r4, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804C310
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq .L0804C306
	bl Proc_End
.L0804C306:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq .L0804C310
	bl Proc_End
.L0804C310:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804C318
sub_804C318: @ 0x0804C318
	push {r4, r5, lr}
	ldr r4, [sp, #0xc]
	ldr r5, [r0, #0x14]
	strh r1, [r5, #0x32]
	strh r2, [r5, #0x3a]
	ldr r5, [r0, #0x18]
	strh r3, [r5, #0x32]
	strh r4, [r5, #0x3a]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804C330
sub_804C330: @ 0x0804C330
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	movs r4, #0
	mov sl, r4
	ldr r0, .L0804C374 @ =gUnk_085CBDB0
	movs r2, #0xc
	ldrsh r1, [r7, r2]
	lsls r2, r1, #3
	adds r2, r2, r0
	ldr r2, [r2]
	str r2, [sp, #0x10]
	lsls r1, r1, #1
	adds r1, #1
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	str r1, [sp, #0x14]
	movs r0, #0
	bl sub_8047C48
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	cmp r0, #4
	bhi .L0804C3C4
	lsls r0, r0, #2
	ldr r1, .L0804C378 @ =.L0804C37C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804C374: .4byte gUnk_085CBDB0
.L0804C378: .4byte .L0804C37C
.L0804C37C: @ jump table
	.4byte .L0804C390 @ case 0
	.4byte .L0804C398 @ case 1
	.4byte .L0804C3B0 @ case 2
	.4byte .L0804C3C4 @ case 3
	.4byte .L0804C390 @ case 4
.L0804C390:
	movs r4, #0x21
	movs r2, #0x30
	mov sl, r2
	b .L0804C3E4
.L0804C398:
	movs r4, #0x1d
	movs r0, #0x30
	mov sl, r0
	ldr r0, .L0804C3AC @ =gUnk_Banim_0201773C
	ldr r0, [r0]
	movs r5, #4
	rsbs r5, r5, #0
.L0804C3A6:
	cmp r0, #1
	bne .L0804C3E6
	b .L0804C3E4
	.align 2, 0
.L0804C3AC: .4byte gUnk_Banim_0201773C
.L0804C3B0:
	movs r4, #3
	movs r1, #0x30
	mov sl, r1
	ldr r0, .L0804C3C0 @ =gUnk_Banim_0201773C
	ldr r0, [r0]
	movs r5, #0x1e
	rsbs r5, r5, #0
	b .L0804C3A6
	.align 2, 0
.L0804C3C0: .4byte gUnk_Banim_0201773C
.L0804C3C4:
	movs r2, #0
	ldrsh r0, [r7, r2]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L0804C3D6
	movs r4, #0x27
	movs r0, #3
	mov sl, r0
.L0804C3D6:
	movs r2, #6
	ldrsh r0, [r7, r2]
	cmp r0, r1
	beq .L0804C3E4
	movs r4, #3
	movs r0, #0x2a
	mov sl, r0
.L0804C3E4:
	movs r5, #0
.L0804C3E6:
	movs r1, #1
	rsbs r1, r1, #0
	mov sb, r1
	lsls r2, r4, #1
	ldr r4, .L0804C46C @ =gUnk_Banim_0201CF70
	adds r2, r2, r4
	movs r0, #0xf
	mov r8, r0
	str r0, [sp]
	movs r6, #5
	str r6, [sp, #4]
	movs r1, #2
	ldrsh r0, [r7, r1]
	str r0, [sp, #8]
	movs r1, #4
	ldrsh r0, [r7, r1]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	mov r1, sb
	movs r3, #0x42
	bl sub_805B20C
	mov r0, sl
	lsls r2, r0, #1
	adds r2, r2, r4
	mov r1, r8
	str r1, [sp]
	str r6, [sp, #4]
	movs r1, #8
	ldrsh r0, [r7, r1]
	str r0, [sp, #8]
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x14]
	mov r1, sb
	movs r3, #0x42
	bl sub_805B20C
	lsls r0, r5, #1
	adds r4, r4, r0
	ldr r2, .L0804C470 @ =0xFFFFFA96
	adds r4, r4, r2
	ldr r2, .L0804C474 @ =gBg2Tm
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x42
	movs r3, #0x20
	bl sub_805B20C
	movs r0, #4
	bl EnableBgSync
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C46C: .4byte gUnk_Banim_0201CF70
.L0804C470: .4byte 0xFFFFFA96
.L0804C474: .4byte gBg2Tm

	thumb_func_start sub_804C478
sub_804C478: @ 0x0804C478
	push {lr}
	sub sp, #0x10
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bhi .L0804C4C0
	lsls r0, r0, #2
	ldr r1, .L0804C494 @ =.L0804C498
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804C494: .4byte .L0804C498
.L0804C498: @ jump table
	.4byte .L0804C4AC @ case 0
	.4byte .L0804C4B6 @ case 1
	.4byte .L0804C4C0 @ case 2
	.4byte .L0804C4C0 @ case 3
	.4byte .L0804C4AC @ case 4
.L0804C4AC:
	movs r2, #0x30
	cmp r3, #0
	bne .L0804C4C8
	movs r2, #0x21
	b .L0804C4C8
.L0804C4B6:
	movs r2, #0x30
	cmp r3, #0
	bne .L0804C4C8
	movs r2, #0x1d
	b .L0804C4C8
.L0804C4C0:
	movs r2, #0x30
	cmp r3, #0
	bne .L0804C4C8
	movs r2, #3
.L0804C4C8:
	ldr r0, .L0804C4EC @ =gUnk_081122DA
	movs r1, #1
	rsbs r1, r1, #0
	lsls r2, r2, #1
	ldr r3, .L0804C4F0 @ =gUnk_Banim_0201CF70
	adds r2, r2, r3
	movs r3, #0xf
	str r3, [sp]
	movs r3, #5
	str r3, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r3, #0x42
	bl sub_805B20C
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
.L0804C4EC: .4byte gUnk_081122DA
.L0804C4F0: .4byte gUnk_Banim_0201CF70

	thumb_func_start sub_804C4F4
sub_804C4F4: @ 0x0804C4F4
	ldr r1, .L0804C4FC @ =0x0203CDD4
	str r0, [r1]
	bx lr
	.align 2, 0
.L0804C4FC: .4byte 0x0203CDD4

	thumb_func_start sub_804C500
sub_804C500: @ 0x0804C500
	ldr r0, .L0804C508 @ =0x0203CDD4
	ldr r0, [r0]
	bx lr
	.align 2, 0
.L0804C508: .4byte 0x0203CDD4

	thumb_func_start sub_804C50C
sub_804C50C: @ 0x0804C50C
	push {r4, lr}
	sub sp, #0x10
	asrs r4, r0, #3
	movs r1, #7
	ands r1, r0
	movs r0, #3
	movs r2, #0
	bl SetBgOffset
	lsls r4, r4, #1
	ldr r0, .L0804C54C @ =gUnk_Banim_0201D424
	adds r4, r4, r0
	ldr r2, .L0804C550 @ =gBg3Tm
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	subs r0, #0x17
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x42
	movs r3, #0x20
	bl sub_805B20C
	movs r0, #8
	bl EnableBgSync
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C54C: .4byte gUnk_Banim_0201D424
.L0804C550: .4byte gBg3Tm

	thumb_func_start sub_804C554
sub_804C554: @ 0x0804C554
	push {lr}
	bl sub_804C500
	cmp r0, #0
	beq .L0804C568
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x8f
	bl sub_805BCA8
.L0804C568:
	pop {r0}
	bx r0

	thumb_func_start sub_804C56C
sub_804C56C: @ 0x0804C56C
	push {lr}
	bl sub_804C500
	cmp r0, #0
	beq .L0804C57C
	movs r0, #0x8e
	bl sub_805BD54
.L0804C57C:
	pop {r0}
	bx r0

	thumb_func_start sub_804C580
sub_804C580: @ 0x0804C580
	push {lr}
	bl sub_8042584
	bl BasInit
	bl sub_8044870
	ldr r1, .L0804C5A0 @ =gUnk_Banim_0201773C
	str r0, [r1]
	bl sub_804C5BC
	movs r0, #0
	bl SetOnHBlankA
	pop {r0}
	bx r0
	.align 2, 0
.L0804C5A0: .4byte gUnk_Banim_0201773C

	thumb_func_start sub_804C5A4
sub_804C5A4: @ 0x0804C5A4
	push {lr}
	bl BasInit
	bl sub_804C744
	ldr r0, .L0804C5B8 @ =sub_8047D38
	bl SetMainFunc
	pop {r0}
	bx r0
	.align 2, 0
.L0804C5B8: .4byte sub_8047D38

	thumb_func_start sub_804C5BC
sub_804C5BC: @ 0x0804C5BC
	push {lr}
	ldr r0, .L0804C5CC @ =gUnk_085CBE20
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0804C5CC: .4byte gUnk_085CBE20

	thumb_func_start sub_804C5D0
sub_804C5D0: @ 0x0804C5D0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	movs r0, #0
	bl InitOam
	ldr r1, .L0804C644 @ =gUnk_Banim_0201773C
	ldr r0, .L0804C648 @ =0x0203CCF4
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [r1]
	bl sub_8044390
	bl sub_804B048
	bl sub_80436A4
	bl sub_8044198
	bl sub_80425F0
	ldr r0, .L0804C64C @ =gUnk_08118330
	ldr r4, .L0804C650 @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #0x20
	bl CpuFastSet
	subs r4, #0xc0
	ldr r5, .L0804C654 @ =gUnk_Banim_020165C0
	movs r6, #0x80
	lsls r6, r6, #1
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl CpuFastSet
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	movs r3, #0x10
	bl sub_805B5C8
	bl EnablePalSync
	mov r0, r8
	bl Proc_Break
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C644: .4byte gUnk_Banim_0201773C
.L0804C648: .4byte 0x0203CCF4
.L0804C64C: .4byte gUnk_08118330
.L0804C650: .4byte gPal+0xC0
.L0804C654: .4byte gUnk_Banim_020165C0

	thumb_func_start sub_804C658
sub_804C658: @ 0x0804C658
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, .L0804C6B8 @ =gUnk_08115524
	ldr r1, .L0804C6BC @ =0x06008000
	bl LZ77UnCompVram
	ldr r0, .L0804C6C0 @ =gUnk_08117B90
	ldr r6, .L0804C6C4 @ =gUnk_Banim_0201977C
	adds r1, r6, #0
	bl LZ77UnCompWram
	movs r1, #1
	rsbs r1, r1, #0
	ldr r2, .L0804C6C8 @ =gUnk_Banim_0201D414
	movs r0, #0x2e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #6
	str r0, [sp, #8]
	movs r4, #0
	str r4, [sp, #0xc]
	adds r0, r6, #0
	movs r3, #0x42
	bl sub_805B20C
	movs r0, #0
	bl sub_804C50C
	movs r0, #8
	bl EnableBgSync
	strh r4, [r5, #0x2c]
	movs r0, #0x10
	strh r0, [r5, #0x2e]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x8e
	bl sub_805BCA8
	adds r0, r5, #0
	bl Proc_Break
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C6B8: .4byte gUnk_08115524
.L0804C6BC: .4byte 0x06008000
.L0804C6C0: .4byte gUnk_08117B90
.L0804C6C4: .4byte gUnk_Banim_0201977C
.L0804C6C8: .4byte gUnk_Banim_0201D414

	thumb_func_start sub_804C6CC
sub_804C6CC: @ 0x0804C6CC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0804C728 @ =gUnk_Banim_020165C0
	ldr r4, .L0804C72C @ =gPal
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r4, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	adds r3, r5, #0
	bl sub_805B5C8
	bl EnablePalSync
	ldrh r1, [r6, #0x2c]
	adds r1, #1
	strh r1, [r6, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	adds r0, #1
	cmp r1, r0
	bne .L0804C720
	adds r0, r6, #0
	bl Proc_Break
.L0804C720:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C728: .4byte gUnk_Banim_020165C0
.L0804C72C: .4byte gPal

	thumb_func_start sub_804C730
sub_804C730: @ 0x0804C730
	push {r4, lr}
	adds r4, r0, #0
	bl sub_804C818
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_804C744
sub_804C744: @ 0x0804C744
	push {lr}
	ldr r0, .L0804C758 @ =gUnk_085CBE50
	movs r1, #3
	bl SpawnProc
	bl sub_804C84C
	pop {r0}
	bx r0
	.align 2, 0
.L0804C758: .4byte gUnk_085CBE50

	thumb_func_start sub_804C75C
sub_804C75C: @ 0x0804C75C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0804C780 @ =gPal
	ldr r1, .L0804C784 @ =gUnk_Banim_020165C0
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuFastSet
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x10
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C780: .4byte gPal
.L0804C784: .4byte gUnk_Banim_020165C0

	thumb_func_start sub_804C788
sub_804C788: @ 0x0804C788
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0804C7E4 @ =gUnk_Banim_020165C0
	ldr r4, .L0804C7E8 @ =gPal
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r4, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	adds r3, r5, #0
	bl sub_805B5C8
	bl EnablePalSync
	ldrh r1, [r6, #0x2c]
	adds r1, #1
	strh r1, [r6, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	adds r0, #1
	cmp r1, r0
	bne .L0804C7DC
	adds r0, r6, #0
	bl Proc_Break
.L0804C7DC:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C7E4: .4byte gUnk_Banim_020165C0
.L0804C7E8: .4byte gPal

	thumb_func_start sub_804C7EC
sub_804C7EC: @ 0x0804C7EC
	push {r4, lr}
	adds r4, r0, #0
	bl sub_80425B0
	bl sub_80438B4
	ldr r0, .L0804C810 @ =OnMain
	bl SetMainFunc
	ldr r0, .L0804C814 @ =OnVBlank
	bl SetOnVBlank
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C810: .4byte OnMain
.L0804C814: .4byte OnVBlank

	thumb_func_start sub_804C818
sub_804C818: @ 0x0804C818
	push {r4, lr}
	ldr r4, .L0804C83C @ =gUnk_Banim_0201E144
	ldr r0, .L0804C840 @ =gUnk_085CBE78
	movs r1, #3
	bl SpawnProc
	str r0, [r4]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804C844 @ =gUnk_08112370
	str r1, [r0, #0x48]
	ldr r1, .L0804C848 @ =gUnk_085CBE90
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C83C: .4byte gUnk_Banim_0201E144
.L0804C840: .4byte gUnk_085CBE78
.L0804C844: .4byte gUnk_08112370
.L0804C848: .4byte gUnk_085CBE90

	thumb_func_start sub_804C84C
sub_804C84C: @ 0x0804C84C
	push {lr}
	ldr r0, .L0804C85C @ =gUnk_Banim_0201E144
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L0804C85C: .4byte gUnk_Banim_0201E144

	thumb_func_start sub_804C860
sub_804C860: @ 0x0804C860
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt .L0804C88C
	ldr r1, [r4, #0x4c]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, .L0804C894 @ =gPal+0xC0
	movs r2, #0x20
	bl CpuFastSet
	bl EnablePalSync
.L0804C88C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C894: .4byte gPal+0xC0

	thumb_func_start sub_804C898
sub_804C898: @ 0x0804C898
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0804C8C4 @ =0x0203CD0C
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldr r1, .L0804C8C8 @ =gUnk_085D0DA0
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r1, .L0804C8CC @ =gUnk_Banim_0201E7A4
	movs r0, #0
	str r0, [r1]
	adds r0, r5, #0
	bl _call_via_r2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C8C4: .4byte 0x0203CD0C
.L0804C8C8: .4byte gUnk_085D0DA0
.L0804C8CC: .4byte gUnk_Banim_0201E7A4

	thumb_func_start nullsub_22
nullsub_22: @ 0x0804C8D0
	bx lr
	.align 2, 0

	thumb_func_start sub_804C8D4
sub_804C8D4: @ 0x0804C8D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r7, [sp, #0x18]
	ldr r1, .L0804C910 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804C914 @ =gUnk_085D0E94
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	str r5, [r0, #0x44]
	str r6, [r0, #0x48]
	mov r1, r8
	str r1, [r0, #0x4c]
	str r7, [r0, #0x50]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L0804C910: .4byte gUnk_Banim_02017744
.L0804C914: .4byte gUnk_085D0E94

	thumb_func_start sub_804C918
sub_804C918: @ 0x0804C918
	ldr r1, .L0804C924 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L0804C924: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804C928
sub_804C928: @ 0x0804C928
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r2, r0, #0
	ldr r0, .L0804C9A8 @ =gUnk_Banim_0201E3D8
	ldr r0, [r0]
	ldr r4, .L0804C9AC @ =gUnk_Banim_0201E3E4
	cmp r0, #0
	bne .L0804C940
	ldr r4, .L0804C9B0 @ =gUnk_Banim_0201E524
.L0804C940:
	ldrh r0, [r2, #0x2e]
	lsls r1, r0, #0x18
	lsrs r3, r1, #0x18
	ldr r1, [r2, #0x50]
	adds r0, r0, r1
	strh r0, [r2, #0x2e]
	movs r1, #0
	ldr r0, [r2, #0x44]
	mov r8, r0
	ldr r6, [r2, #0x48]
	mov sl, r6
	ldr r7, .L0804C9B4 @ =gUnk_08605A94
	mov ip, r7
	ldr r5, [r2, #0x4c]
	ldr r0, .L0804C9B8 @ =gDispIo
	mov sb, r0
.L0804C960:
	mov r6, sl
	adds r0, r3, r6
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r0, r3, #1
	add r0, ip
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r5, r0
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	mov r6, sb
	ldrh r6, [r6, #0x20]
	adds r0, r6, r0
	strh r0, [r4]
	adds r4, #2
	adds r1, #1
	cmp r1, #0x77
	bls .L0804C960
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	bne .L0804C99A
	adds r0, r2, #0
	bl Proc_End
.L0804C99A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C9A8: .4byte gUnk_Banim_0201E3D8
.L0804C9AC: .4byte gUnk_Banim_0201E3E4
.L0804C9B0: .4byte gUnk_Banim_0201E524
.L0804C9B4: .4byte gUnk_08605A94
.L0804C9B8: .4byte gDispIo

	thumb_func_start sub_804C9BC
sub_804C9BC: @ 0x0804C9BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L0804C9E4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804C9E8 @ =gUnk_085D0EB4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	str r5, [r0, #0x44]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C9E4: .4byte gUnk_Banim_02017744
.L0804C9E8: .4byte gUnk_085D0EB4

	thumb_func_start sub_804C9EC
sub_804C9EC: @ 0x0804C9EC
	ldr r1, .L0804C9F8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L0804C9F8: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804C9FC
sub_804C9FC: @ 0x0804C9FC
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, .L0804CA38 @ =gUnk_Banim_0201E3D8
	ldr r0, [r0]
	ldr r1, .L0804CA3C @ =gUnk_Banim_0201E3E4
	cmp r0, #0
	bne .L0804CA0C
	ldr r1, .L0804CA40 @ =gUnk_Banim_0201E524
.L0804CA0C:
	movs r2, #0
	ldr r5, [r3, #0x44]
	ldr r4, .L0804CA44 @ =gDispIo
.L0804CA12:
	ldrh r0, [r4, #0x20]
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #0x77
	bls .L0804CA12
	ldrh r0, [r3, #0x2c]
	adds r0, #1
	strh r0, [r3, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r5
	bne .L0804CA32
	adds r0, r3, #0
	bl Proc_End
.L0804CA32:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CA38: .4byte gUnk_Banim_0201E3D8
.L0804CA3C: .4byte gUnk_Banim_0201E3E4
.L0804CA40: .4byte gUnk_Banim_0201E524
.L0804CA44: .4byte gDispIo

	thumb_func_start sub_804CA48
sub_804CA48: @ 0x0804CA48
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r1, .L0804CA90 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804CA94 @ =gUnk_085D0ED4
	movs r1, #3
	bl SpawnProc
	adds r7, r0, #0
	mov r0, r8
	str r0, [r7, #0x5c]
	movs r1, #0
	mov sb, r1
	movs r0, #0
	strh r0, [r7, #0x2c]
	strh r0, [r7, #0x2e]
	str r4, [r7, #0x44]
	str r5, [r7, #0x54]
	str r6, [r7, #0x58]
	mov r0, r8
	bl sub_804B80C
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804CA9C
	ldr r0, .L0804CA98 @ =0x0000FFB8
	b .L0804CA9E
	.align 2, 0
.L0804CA90: .4byte gUnk_Banim_02017744
.L0804CA94: .4byte gUnk_085D0ED4
.L0804CA98: .4byte 0x0000FFB8
.L0804CA9C:
	ldr r0, .L0804CABC @ =0x0000FFF8
.L0804CA9E:
	strh r0, [r7, #0x32]
	ldr r0, .L0804CAC0 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804CACA
	mov r0, r8
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804CAC4
	ldrh r0, [r7, #0x32]
	adds r0, #0x18
	b .L0804CAC8
	.align 2, 0
.L0804CABC: .4byte 0x0000FFF8
.L0804CAC0: .4byte 0x0203CD14
.L0804CAC4:
	ldrh r0, [r7, #0x32]
	subs r0, #0x18
.L0804CAC8:
	strh r0, [r7, #0x32]
.L0804CACA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804CAD8
sub_804CAD8: @ 0x0804CAD8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, .L0804CB20 @ =gUnk_Banim_0201E14C
	ldr r0, [r0]
	ldr r5, .L0804CB24 @ =gUnk_Banim_0201E158
	cmp r0, #0
	bne .L0804CAE8
	ldr r5, .L0804CB28 @ =gUnk_Banim_0201E298
.L0804CAE8:
	ldr r1, [r4, #0x54]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, [r4, #0x58]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r0, .L0804CB2C @ =0x0000FFFF
	cmp r2, r0
	beq .L0804CB54
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	movs r2, #0
	ldr r6, [r4, #0x44]
	ldr r7, .L0804CB30 @ =0x00007FFF
	mov ip, r7
.L0804CB10:
	ldrh r1, [r3]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r0, ip
	bne .L0804CB34
	movs r0, #0
	b .L0804CB46
	.align 2, 0
.L0804CB20: .4byte gUnk_Banim_0201E14C
.L0804CB24: .4byte gUnk_Banim_0201E158
.L0804CB28: .4byte gUnk_Banim_0201E298
.L0804CB2C: .4byte 0x0000FFFF
.L0804CB30: .4byte 0x00007FFF
.L0804CB34:
	ldrh r0, [r4, #0x32]
	adds r1, r1, r0
	ldrh r7, [r3, #2]
	adds r0, r0, r7
	lsls r1, r1, #0x10
	asrs r1, r1, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
.L0804CB46:
	strh r0, [r5]
	adds r3, #4
	adds r5, #2
	adds r2, #1
	cmp r2, #0x77
	bls .L0804CB10
	b .L0804CB64
.L0804CB54:
	movs r2, #0
	ldr r6, [r4, #0x44]
	movs r0, #0
.L0804CB5A:
	strh r0, [r5]
	adds r5, #2
	adds r2, #1
	cmp r2, #0x77
	bls .L0804CB5A
.L0804CB64:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, r6
	bne .L0804CB80
	ldr r1, .L0804CB88 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804CB80:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CB88: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804CB8C
sub_804CB8C: @ 0x0804CB8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov sb, r1
	adds r5, r3, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, .L0804CC34 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r1, .L0804CC38 @ =gUnk_Banim_0201E158
	movs r0, #0
	adds r7, r1, #0
	ldr r4, .L0804CC3C @ =gUnk_Banim_0201E298
	ldr r3, .L0804CC40 @ =gUnk_Banim_0201E3E4
	ldr r6, .L0804CC44 @ =gUnk_Banim_0201E14C
	mov ip, r6
	ldr r6, .L0804CC48 @ =gUnk_Banim_0201E3D8
	mov sl, r6
.L0804CBBA:
	strh r2, [r1]
	adds r1, #2
	adds r0, #1
	cmp r0, #0x9f
	bls .L0804CBBA
	adds r1, r4, #0
	movs r0, #0
.L0804CBC8:
	strh r2, [r1]
	adds r1, #2
	adds r0, #1
	cmp r0, #0x9f
	bls .L0804CBC8
	adds r1, r3, #0
	movs r0, #0
.L0804CBD6:
	strh r2, [r1]
	adds r1, #2
	adds r0, #1
	cmp r0, #0x9f
	bls .L0804CBD6
	ldr r1, .L0804CC4C @ =gUnk_Banim_0201E524
	movs r0, #0
.L0804CBE4:
	strh r2, [r1]
	adds r1, #2
	adds r0, #1
	cmp r0, #0x9f
	bls .L0804CBE4
	movs r4, #0
	mov r0, ip
	str r4, [r0]
	mov r1, sl
	str r4, [r1]
	ldr r6, .L0804CC50 @ =gUnk_Banim_0201E150
	str r7, [r6]
	ldr r0, .L0804CC54 @ =gUnk_Banim_0201E3DC
	str r3, [r0]
	ldr r1, .L0804CC58 @ =gUnk_Banim_0201E154
	str r7, [r1]
	ldr r6, .L0804CC5C @ =gUnk_Banim_0201E3E0
	str r3, [r6]
	adds r0, r5, #0
	bl SetOnHBlankA
	ldr r1, .L0804CC60 @ =gUnk_Banim_0201E7A4
	movs r0, #1
	str r0, [r1]
	ldr r0, .L0804CC64 @ =gUnk_085D0EEC
	movs r1, #0
	bl SpawnProc
	mov r1, r8
	str r1, [r0, #0x5c]
	strh r4, [r0, #0x2c]
	mov r6, sb
	str r6, [r0, #0x44]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CC34: .4byte gUnk_Banim_02017744
.L0804CC38: .4byte gUnk_Banim_0201E158
.L0804CC3C: .4byte gUnk_Banim_0201E298
.L0804CC40: .4byte gUnk_Banim_0201E3E4
.L0804CC44: .4byte gUnk_Banim_0201E14C
.L0804CC48: .4byte gUnk_Banim_0201E3D8
.L0804CC4C: .4byte gUnk_Banim_0201E524
.L0804CC50: .4byte gUnk_Banim_0201E150
.L0804CC54: .4byte gUnk_Banim_0201E3DC
.L0804CC58: .4byte gUnk_Banim_0201E154
.L0804CC5C: .4byte gUnk_Banim_0201E3E0
.L0804CC60: .4byte gUnk_Banim_0201E7A4
.L0804CC64: .4byte gUnk_085D0EEC

	thumb_func_start sub_804CC68
sub_804CC68: @ 0x0804CC68
	push {lr}
	adds r3, r2, #0
	movs r2, #0
	bl sub_804CB8C
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804CC78
sub_804CC78: @ 0x0804CC78
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804CC84
sub_804CC84: @ 0x0804CC84
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0804CCA8 @ =gBmSt
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq .L0804CD04
	ldr r1, .L0804CCAC @ =gUnk_Banim_0201E14C
	ldr r0, [r1]
	cmp r0, #1
	bne .L0804CCB8
	movs r0, #0
	str r0, [r1]
	ldr r1, .L0804CCB0 @ =gUnk_Banim_0201E150
	ldr r0, .L0804CCB4 @ =gUnk_Banim_0201E158
	b .L0804CCC0
	.align 2, 0
.L0804CCA8: .4byte gBmSt
.L0804CCAC: .4byte gUnk_Banim_0201E14C
.L0804CCB0: .4byte gUnk_Banim_0201E150
.L0804CCB4: .4byte gUnk_Banim_0201E158
.L0804CCB8:
	movs r0, #1
	str r0, [r1]
	ldr r1, .L0804CCD8 @ =gUnk_Banim_0201E150
	ldr r0, .L0804CCDC @ =gUnk_Banim_0201E298
.L0804CCC0:
	str r0, [r1]
	adds r3, r1, #0
	ldr r1, .L0804CCE0 @ =gUnk_Banim_0201E3D8
	ldr r0, [r1]
	cmp r0, #1
	bne .L0804CCEC
	movs r0, #0
	str r0, [r1]
	ldr r1, .L0804CCE4 @ =gUnk_Banim_0201E3DC
	ldr r0, .L0804CCE8 @ =gUnk_Banim_0201E3E4
	b .L0804CCF4
	.align 2, 0
.L0804CCD8: .4byte gUnk_Banim_0201E150
.L0804CCDC: .4byte gUnk_Banim_0201E298
.L0804CCE0: .4byte gUnk_Banim_0201E3D8
.L0804CCE4: .4byte gUnk_Banim_0201E3DC
.L0804CCE8: .4byte gUnk_Banim_0201E3E4
.L0804CCEC:
	movs r0, #1
	str r0, [r1]
	ldr r1, .L0804CD34 @ =gUnk_Banim_0201E3DC
	ldr r0, .L0804CD38 @ =gUnk_Banim_0201E524
.L0804CCF4:
	str r0, [r1]
	adds r2, r1, #0
	ldr r1, .L0804CD3C @ =gUnk_Banim_0201E154
	ldr r0, [r3]
	str r0, [r1]
	ldr r1, .L0804CD40 @ =gUnk_Banim_0201E3E0
	ldr r0, [r2]
	str r0, [r1]
.L0804CD04:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x44]
	cmp r0, r1
	bne .L0804CD2E
	ldr r1, .L0804CD44 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	movs r0, #0
	bl SetOnHBlankA
	ldr r1, .L0804CD48 @ =gUnk_Banim_0201E7A4
	movs r0, #0
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804CD2E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CD34: .4byte gUnk_Banim_0201E3DC
.L0804CD38: .4byte gUnk_Banim_0201E524
.L0804CD3C: .4byte gUnk_Banim_0201E154
.L0804CD40: .4byte gUnk_Banim_0201E3E0
.L0804CD44: .4byte gUnk_Banim_02017744
.L0804CD48: .4byte gUnk_Banim_0201E7A4

	thumb_func_start sub_804CD4C
sub_804CD4C: @ 0x0804CD4C
	ldr r0, .L0804CD78 @ =0x04000004
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0804CD74
	ldr r3, .L0804CD7C @ =0x04000040
	ldr r2, .L0804CD80 @ =gUnk_Banim_0201E154
	ldr r0, [r2]
	ldrh r1, [r0]
	strh r1, [r3]
	adds r0, #2
	str r0, [r2]
	subs r3, #0x2c
	ldr r2, .L0804CD84 @ =gUnk_Banim_0201E3E0
	ldr r0, [r2]
	ldrh r1, [r0]
	strh r1, [r3]
	adds r0, #2
	str r0, [r2]
.L0804CD74:
	bx lr
	.align 2, 0
.L0804CD78: .4byte 0x04000004
.L0804CD7C: .4byte 0x04000040
.L0804CD80: .4byte gUnk_Banim_0201E154
.L0804CD84: .4byte gUnk_Banim_0201E3E0

	thumb_func_start sub_804CD88
sub_804CD88: @ 0x0804CD88
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r7, [sp, #0x18]
	ldr r1, .L0804CDC8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804CDCC @ =gUnk_085D0F0C
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	adds r4, r4, r6
	strh r4, [r0, #0x30]
	mov r1, r8
	str r1, [r0, #0x44]
	str r7, [r0, #0x48]
	ldr r1, [sp, #0x1c]
	str r1, [r0, #0x4c]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CDC8: .4byte gUnk_Banim_02017744
.L0804CDCC: .4byte gUnk_085D0F0C

	thumb_func_start sub_804CDD0
sub_804CDD0: @ 0x0804CDD0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	blt .L0804CEC4
	ldr r1, [r5, #0x44]
	ldr r2, [r5, #0x48]
	movs r6, #0x2c
	ldrsh r3, [r5, r6]
	movs r0, #0x2e
	ldrsh r4, [r5, r0]
	subs r3, r3, r4
	movs r6, #0x30
	ldrsh r0, [r5, r6]
	subs r0, r0, r4
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	adds r6, r0, #0
	ldr r0, [r5, #0x4c]
	cmp r0, #1
	beq .L0804CE44
	cmp r0, #1
	bgt .L0804CE16
	cmp r0, #0
	beq .L0804CE1C
	b .L0804CEAA
.L0804CE16:
	cmp r0, #2
	beq .L0804CE6C
	b .L0804CEAA
.L0804CE1C:
	ldr r3, .L0804CE40 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	b .L0804CEA6
	.align 2, 0
.L0804CE40: .4byte gDispIo
.L0804CE44:
	ldr r3, .L0804CE68 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r7, [r0]
	adds r0, #1
	strb r7, [r0]
	adds r0, #1
	strb r6, [r0]
	b .L0804CEAA
	.align 2, 0
.L0804CE68: .4byte gDispIo
.L0804CE6C:
	movs r2, #0x2c
	ldrsh r3, [r5, r2]
	movs r0, #0x2e
	ldrsh r1, [r5, r0]
	subs r3, r3, r1
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r0, r0, r1
	str r0, [sp]
	movs r0, #0
	movs r1, #8
	movs r2, #0x10
	bl Interpolate
	ldr r4, .L0804CECC @ =gDispIo
	adds r3, r4, #0
	adds r3, #0x3c
	movs r1, #0x3f
	ldrb r2, [r3]
	ands r1, r2
	movs r2, #0x40
	orrs r1, r2
	strb r1, [r3]
	adds r1, r4, #0
	adds r1, #0x44
	strb r6, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r4, #0
.L0804CEA6:
	adds r0, #0x46
	strb r7, [r0]
.L0804CEAA:
	movs r6, #0x2c
	ldrsh r1, [r5, r6]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt .L0804CEC4
	ldr r1, .L0804CED0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L0804CEC4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CECC: .4byte gDispIo
.L0804CED0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804CED4
sub_804CED4: @ 0x0804CED4
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	adds r5, r3, #0
	ldr r6, [sp, #0x1c]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	ldr r1, .L0804CF2C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804CF30 @ =gUnk_085D0F24
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	mov r0, r8
	str r0, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	mov r0, sb
	str r0, [r4, #0x44]
	mov r0, sl
	str r0, [r4, #0x54]
	mov r0, r8
	bl sub_804B80C
	strh r5, [r4, #0x32]
	strh r6, [r4, #0x3a]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CF2C: .4byte gUnk_Banim_02017744
.L0804CF30: .4byte gUnk_085D0F24

	thumb_func_start sub_804CF34
sub_804CF34: @ 0x0804CF34
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r0, .L0804CFB4 @ =gUnk_Banim_0201E14C
	ldr r0, [r0]
	ldr r1, .L0804CFB8 @ =gUnk_Banim_0201E158
	mov r8, r1
	cmp r0, #0
	bne .L0804CF4E
	ldr r2, .L0804CFBC @ =gUnk_Banim_0201E298
	mov r8, r2
.L0804CF4E:
	ldr r4, [r5, #0x54]
	movs r7, #0x2e
	ldrsh r0, [r5, r7]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r7, [r0]
	adds r0, r7, #0
	bl sub_8013F7C
	adds r6, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldr r1, .L0804CFC0 @ =0x0000FFFF
	ldrh r0, [r0, #2]
	cmp r0, r1
	beq .L0804CF78
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
.L0804CF78:
	ldrh r1, [r5, #0x3a]
	subs r0, r1, r7
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804CF86
	movs r2, #0
.L0804CF86:
	adds r0, r7, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa0
	ble .L0804CF94
	movs r1, #0xa0
.L0804CF94:
	movs r3, #0
	lsls r0, r2, #0x10
	ldr r2, [r5, #0x44]
	mov ip, r2
	asrs r0, r0, #0x10
	mov sb, r0
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
.L0804CFA4:
	cmp sb, r3
	bhi .L0804CFAC
	cmp r4, r3
	bhs .L0804CFC4
.L0804CFAC:
	movs r0, #0
	mov r7, r8
	strh r0, [r7]
	b .L0804CFF4
	.align 2, 0
.L0804CFB4: .4byte gUnk_Banim_0201E14C
.L0804CFB8: .4byte gUnk_Banim_0201E158
.L0804CFBC: .4byte gUnk_Banim_0201E298
.L0804CFC0: .4byte 0x0000FFFF
.L0804CFC4:
	ldrh r2, [r5, #0x32]
	ldrh r1, [r6]
	adds r0, r2, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r0, #0
	bge .L0804CFD4
	movs r1, #0
.L0804CFD4:
	ldrh r7, [r6, #2]
	adds r0, r2, r7
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble .L0804CFE4
	movs r2, #0xf0
.L0804CFE4:
	lsls r1, r1, #0x10
	asrs r1, r1, #8
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	mov r1, r8
	strh r0, [r1]
	adds r6, #4
.L0804CFF4:
	movs r2, #2
	add r8, r2
	adds r3, #1
	cmp r3, #0x9f
	bls .L0804CFA4
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	movs r3, #0
	strh r0, [r5, #0x2c]
	movs r4, #0x2c
	ldrsh r0, [r5, r4]
	cmp r0, ip
	bne .L0804D03A
	ldr r1, .L0804D048 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r2, .L0804D04C @ =gDispIo
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r7, [r1]
	ands r0, r7
	strb r0, [r1]
	adds r1, #8
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x45
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, r5, #0
	bl Proc_Break
.L0804D03A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D048: .4byte gUnk_Banim_02017744
.L0804D04C: .4byte gDispIo

	thumb_func_start sub_804D050
sub_804D050: @ 0x0804D050
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, .L0804D080 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804D084 @ =gUnk_085D0F3C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #6
	movs r1, #0
	bl sub_8045F48
	str r0, [r4, #0x60]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r6, [r4, #0x2e]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D080: .4byte gUnk_Banim_02017744
.L0804D084: .4byte gUnk_085D0F3C

	thumb_func_start sub_804D088
sub_804D088: @ 0x0804D088
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	ldr r5, .L0804D120 @ =gUnk_Banim_02017758
	ldrh r1, [r5]
	ldrh r2, [r5, #2]
	movs r0, #2
	bl SetBgOffset
	ldr r4, .L0804D124 @ =gUnk_Banim_02000030
	ldrh r0, [r5]
	ldrh r2, [r4]
	adds r1, r0, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r3, [r5, #2]
	ldrh r0, [r4, #2]
	adds r2, r3, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	bl SetBgOffset
	ldrh r1, [r5]
	ldrh r2, [r4]
	adds r0, r1, r2
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r5, #2]
	ldrh r2, [r4, #2]
	adds r1, r3, r2
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_804392C
	ldrh r3, [r5]
	ldrh r1, [r4]
	adds r0, r3, r1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r5, #2]
	ldrh r4, [r4, #2]
	adds r1, r2, r4
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_8044230
	bl sub_805894C
	cmp r0, #0
	beq .L0804D10C
	ldrh r1, [r5]
	ldrh r2, [r5, #2]
	adds r2, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #3
	bl SetBgOffset
.L0804D10C:
	bl sub_805894C
	cmp r0, #0
	beq .L0804D12C
	ldr r3, .L0804D128 @ =gUnk_Banim_02000020
	ldrh r4, [r3]
	ldrh r1, [r5]
	subs r0, r4, r1
	b .L0804D134
	.align 2, 0
.L0804D120: .4byte gUnk_Banim_02017758
.L0804D124: .4byte gUnk_Banim_02000030
.L0804D128: .4byte gUnk_Banim_02000020
.L0804D12C:
	ldr r3, .L0804D244 @ =gUnk_Banim_02000020
	ldrh r1, [r3]
	ldrh r2, [r5]
	adds r0, r1, r2
.L0804D134:
	ldr r2, .L0804D248 @ =gUnk_Banim_0201E12C
	ldr r1, [r2]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r1, .L0804D24C @ =gUnk_Banim_02000024
	ldrh r4, [r1]
	ldrh r5, [r5, #2]
	subs r0, r4, r5
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov sb, r3
	mov sl, r1
	ldr r2, .L0804D250 @ =gUnk_Banim_02017758
	mov r1, sb
	ldrh r1, [r1, #2]
	ldrh r3, [r2]
	adds r0, r1, r3
	ldr r4, .L0804D248 @ =gUnk_Banim_0201E12C
	ldr r1, [r4]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r1, sl
	ldrh r1, [r1, #2]
	ldrh r2, [r2, #2]
	subs r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	movs r0, #0
	bl sub_8047C88
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl sub_8047C88
	mov r2, r8
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r2, #0x2e]
	lsls r1, r3, #0x10
	cmp r0, r1
	ble .L0804D236
	ldr r1, .L0804D254 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r4, .L0804D258 @ =gUnk_Banim_02000030
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #0
	bl SetBgOffset
	ldrh r1, [r4]
	rsbs r0, r1, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r4, #2]
	rsbs r1, r2, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_804392C
	ldrh r3, [r4]
	rsbs r0, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r4, #2]
	rsbs r1, r4, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_8044230
	bl sub_805894C
	cmp r0, #0
	beq .L0804D1F4
	movs r0, #3
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
.L0804D1F4:
	ldr r4, .L0804D248 @ =gUnk_Banim_0201E12C
	ldr r0, [r4]
	mov r2, sb
	ldrh r2, [r2]
	subs r1, r2, r0
	mov r3, sb
	ldrh r3, [r3, #2]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, sl
	ldrh r4, [r0, #2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0
	bl sub_8047C88
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl sub_8047C88
	mov r4, r8
	ldr r0, [r4, #0x60]
	bl Proc_End
	mov r0, r8
	bl Proc_Break
.L0804D236:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D244: .4byte gUnk_Banim_02000020
.L0804D248: .4byte gUnk_Banim_0201E12C
.L0804D24C: .4byte gUnk_Banim_02000024
.L0804D250: .4byte gUnk_Banim_02017758
.L0804D254: .4byte gUnk_Banim_02017744
.L0804D258: .4byte gUnk_Banim_02000030

	thumb_func_start sub_804D25C
sub_804D25C: @ 0x0804D25C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804D27C @ =gUnk_085D0F54
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D27C: .4byte gUnk_085D0F54

	thumb_func_start sub_804D280
sub_804D280: @ 0x0804D280
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl sub_804B80C
	adds r4, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804D2A6
	movs r0, #9
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
	b .L0804D2CE
.L0804D2A6:
	cmp r0, #0xa
	bne .L0804D2CE
	adds r0, r4, #0
	bl sub_804B848
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L0804D2C4
	movs r0, #2
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
.L0804D2C4:
	bl sub_80474BC
	adds r0, r5, #0
	bl Proc_Break
.L0804D2CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_804D2D4
sub_804D2D4: @ 0x0804D2D4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804D308 @ =gUnk_085D0F6C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D308: .4byte gUnk_085D0F6C

	thumb_func_start sub_804D30C
sub_804D30C: @ 0x0804D30C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl sub_804B80C
	adds r6, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804D38A
	ldr r0, [r5, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	ldr r0, [r5, #0x5c]
	bl sub_804D3A8
	ldrh r0, [r5, #0x2c]
	cmp r0, #1
	bne .L0804D38A
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r6, #0
	bl sub_8047600
	adds r0, r6, #0
	bl sub_805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	beq .L0804D37C
	ldr r0, [r5, #0x5c]
	bl sub_804B7B0
	cmp r0, #1
	bne .L0804D370
	adds r0, r6, #0
	bl sub_8056B08
	b .L0804D37C
.L0804D370:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804D3A0
	ldr r0, [r5, #0x5c]
	bl sub_8056C3C
.L0804D37C:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804D3A0
	adds r0, r6, #0
	bl sub_805C358
	b .L0804D3A0
.L0804D38A:
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0x46
	beq .L0804D3A0
	cmp r0, #0x50
	bne .L0804D3A0
	bl sub_80474BC
	adds r0, r5, #0
	bl Proc_Break
.L0804D3A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804D3A8
sub_804D3A8: @ 0x0804D3A8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L0804D3EC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804D3F0 @ =gUnk_085D0F84
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	ldr r1, .L0804D3F4 @ =gUnk_085D4148
	ldr r2, .L0804D3F8 @ =gUnk_085D3DB0
	ldr r3, .L0804D3FC @ =gUnk_085D41A4
	ldr r0, .L0804D400 @ =gUnk_085D3E0C
	str r0, [sp]
	adds r0, r4, #0
	bl sub_80478DC
	adds r5, r0, #0
	str r5, [r6, #0x60]
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804D404
	ldrh r0, [r5, #2]
	adds r0, #0x48
	b .L0804D408
	.align 2, 0
.L0804D3EC: .4byte gUnk_Banim_02017744
.L0804D3F0: .4byte gUnk_085D0F84
.L0804D3F4: .4byte gUnk_085D4148
.L0804D3F8: .4byte gUnk_085D3DB0
.L0804D3FC: .4byte gUnk_085D41A4
.L0804D400: .4byte gUnk_085D3E0C
.L0804D404:
	ldrh r0, [r5, #2]
	subs r0, #0x48
.L0804D408:
	strh r0, [r5, #2]
	ldr r0, .L0804D418 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0804D41C
	movs r0, #0x23
	b .L0804D41E
	.align 2, 0
.L0804D418: .4byte 0x0203CD14
.L0804D41C:
	movs r0, #0xa
.L0804D41E:
	strh r0, [r6, #0x2e]
	ldr r0, [r6, #0x5c]
	ldr r1, [r6, #0x60]
	bl sub_804D590
	str r0, [r6, #0x64]
	ldr r0, .L0804D444 @ =gUnk_0811B3E8
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804D448 @ =gUnk_0811AFE8
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D444: .4byte gUnk_0811B3E8
.L0804D448: .4byte gUnk_0811AFE8

	thumb_func_start sub_804D44C
sub_804D44C: @ 0x0804D44C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0804D49E
	ldr r1, .L0804D48C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r0, .L0804D490 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0804D498
	ldr r0, .L0804D494 @ =gUnk_Banim_02017750
	movs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x64]
	bl Proc_End
	adds r0, r4, #0
	bl Proc_End
	b .L0804D49E
	.align 2, 0
.L0804D48C: .4byte gUnk_Banim_02017744
.L0804D490: .4byte 0x0203CD14
.L0804D494: .4byte gUnk_Banim_02017750
.L0804D498:
	adds r0, r4, #0
	bl Proc_Break
.L0804D49E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_804D4A4
sub_804D4A4: @ 0x0804D4A4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804D4C8 @ =gUnk_Banim_0201774C
	movs r0, #0
	str r0, [r1]
	ldr r0, [r4, #0x64]
	bl Proc_End
	ldr r0, [r4, #0x5c]
	bl sub_804D4CC
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D4C8: .4byte gUnk_Banim_0201774C

	thumb_func_start sub_804D4CC
sub_804D4CC: @ 0x0804D4CC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L0804D50C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804D510 @ =gUnk_085D0FA4
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	ldr r3, .L0804D514 @ =gUnk_085D41C4
	ldr r2, .L0804D518 @ =gUnk_085D3E2C
	str r2, [sp]
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_80478DC
	adds r5, r0, #0
	str r5, [r6, #0x60]
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804D51C
	ldrh r0, [r5, #2]
	adds r0, #0x48
	b .L0804D520
	.align 2, 0
.L0804D50C: .4byte gUnk_Banim_02017744
.L0804D510: .4byte gUnk_085D0FA4
.L0804D514: .4byte gUnk_085D41C4
.L0804D518: .4byte gUnk_085D3E2C
.L0804D51C:
	ldrh r0, [r5, #2]
	subs r0, #0x48
.L0804D520:
	strh r0, [r5, #2]
	ldr r0, .L0804D548 @ =gUnk_0811B3E8
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804D54C @ =gUnk_0811AFE8
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	ldr r0, [r6, #0x5c]
	ldr r1, [r6, #0x60]
	bl sub_804D590
	str r0, [r6, #0x64]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D548: .4byte gUnk_0811B3E8
.L0804D54C: .4byte gUnk_0811AFE8

	thumb_func_start sub_804D550
sub_804D550: @ 0x0804D550
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x11
	bne .L0804D582
	ldr r1, .L0804D588 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r1, .L0804D58C @ =gUnk_Banim_02017750
	movs r0, #1
	str r0, [r1]
	ldr r0, [r4, #0x64]
	bl Proc_End
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0804D582:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D588: .4byte gUnk_Banim_02017744
.L0804D58C: .4byte gUnk_Banim_02017750

	thumb_func_start sub_804D590
sub_804D590: @ 0x0804D590
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r1, .L0804D5CC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804D5D0 @ =gUnk_085D0FBC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r6, [r4, #0x5c]
	str r5, [r4, #0x60]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #1
	strh r0, [r4, #0x2e]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r6, r0]
	movs r0, #0xcd
	movs r3, #1
	bl sub_805C804
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L0804D5CC: .4byte gUnk_Banim_02017744
.L0804D5D0: .4byte gUnk_085D0FBC

	thumb_func_start sub_804D5D4
sub_804D5D4: @ 0x0804D5D4
	ldr r1, .L0804D5E0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L0804D5E0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804D5E4
sub_804D5E4: @ 0x0804D5E4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	bne .L0804D626
	ldr r0, [r4, #0x60]
	bl sub_805C76C
	adds r2, r0, #0
	ldr r0, [r4, #0x60]
	ldrh r0, [r0, #2]
	adds r2, r0, r2
	movs r1, #0x80
	lsls r1, r1, #1
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r0, #0xcd
	movs r3, #1
	bl sub_805C804
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x2e]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r0, #8
	bgt .L0804D626
	adds r0, r1, #1
	strh r0, [r4, #0x2e]
.L0804D626:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_804D62C
sub_804D62C: @ 0x0804D62C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804D660 @ =gUnk_085D0FDC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D660: .4byte gUnk_085D0FDC

	thumb_func_start sub_804D664
sub_804D664: @ 0x0804D664
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl sub_804B80C
	adds r6, r0, #0
	bl sub_8047C28
	adds r4, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804D6FA
	ldr r0, [r5, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	ldr r0, [r5, #0x5c]
	bl sub_804D728
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r5, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xcc
	movs r3, #1
	bl sub_805C804
	ldrh r0, [r5, #0x2c]
	cmp r0, #1
	bne .L0804D6FA
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r6, #0
	bl sub_8047600
	adds r0, r6, #0
	bl sub_805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	beq .L0804D6EC
	ldr r0, [r5, #0x5c]
	bl sub_804B7B0
	cmp r0, #1
	bne .L0804D6E0
	adds r0, r6, #0
	bl sub_8056B08
	b .L0804D6EC
.L0804D6E0:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804D720
	ldr r0, [r5, #0x5c]
	bl sub_8056C3C
.L0804D6EC:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804D720
	adds r0, r6, #0
	bl sub_805C358
	b .L0804D720
.L0804D6FA:
	movs r3, #0x2c
	ldrsh r1, [r5, r3]
	adds r0, r4, #0
	adds r0, #9
	cmp r1, r0
	bne .L0804D70E
	ldr r0, [r5, #0x5c]
	bl sub_804B80C
	b .L0804D720
.L0804D70E:
	adds r0, r4, #0
	adds r0, #0xa
	cmp r1, r0
	bne .L0804D720
	bl sub_80474BC
	adds r0, r5, #0
	bl Proc_Break
.L0804D720:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804D728
sub_804D728: @ 0x0804D728
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804D770 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804D774 @ =gUnk_085D0FF4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r1, .L0804D778 @ =gUnk_085D42F0
	ldr r2, .L0804D77C @ =gUnk_085D4264
	ldr r3, .L0804D780 @ =gUnk_085D4300
	ldr r0, .L0804D784 @ =gUnk_085D4274
	str r0, [sp]
	adds r0, r5, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r0, .L0804D788 @ =gUnk_0811B3E8
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804D78C @ =gUnk_0811B408
	movs r1, #0x60
	bl sub_8047A88
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D770: .4byte gUnk_Banim_02017744
.L0804D774: .4byte gUnk_085D0FF4
.L0804D778: .4byte gUnk_085D42F0
.L0804D77C: .4byte gUnk_085D4264
.L0804D780: .4byte gUnk_085D4300
.L0804D784: .4byte gUnk_085D4274
.L0804D788: .4byte gUnk_0811B3E8
.L0804D78C: .4byte gUnk_0811B408

	thumb_func_start sub_804D790
sub_804D790: @ 0x0804D790
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne .L0804D7B6
	ldr r0, .L0804D7BC @ =gUnk_Banim_02017744
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0804D7B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D7BC: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804D7C0
sub_804D7C0: @ 0x0804D7C0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804D810 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	bl sub_804DBAC
	ldr r0, .L0804D814 @ =gUnk_0811B674
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804D818 @ =gUnk_0811B444
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D810: .4byte gUnk_085D100C
.L0804D814: .4byte gUnk_0811B674
.L0804D818: .4byte gUnk_0811B444

	thumb_func_start sub_804D81C
sub_804D81C: @ 0x0804D81C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804D86C @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl sub_804DBAC
	ldr r0, .L0804D870 @ =gUnk_0811B8B0
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804D874 @ =gUnk_0811B694
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D86C: .4byte gUnk_085D100C
.L0804D870: .4byte gUnk_0811B8B0
.L0804D874: .4byte gUnk_0811B694

	thumb_func_start sub_804D878
sub_804D878: @ 0x0804D878
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804D8C8 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	bl sub_804DBAC
	ldr r0, .L0804D8CC @ =gUnk_0811BAE8
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804D8D0 @ =gUnk_0811B8D0
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D8C8: .4byte gUnk_085D100C
.L0804D8CC: .4byte gUnk_0811BAE8
.L0804D8D0: .4byte gUnk_0811B8D0

	thumb_func_start sub_804D8D4
sub_804D8D4: @ 0x0804D8D4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804D924 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl sub_804DBAC
	ldr r0, .L0804D928 @ =gUnk_0811BD24
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804D92C @ =gUnk_0811BB08
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D924: .4byte gUnk_085D100C
.L0804D928: .4byte gUnk_0811BD24
.L0804D92C: .4byte gUnk_0811BB08

	thumb_func_start sub_804D930
sub_804D930: @ 0x0804D930
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804D980 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl sub_804DBAC
	ldr r0, .L0804D984 @ =gUnk_0811BF70
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804D988 @ =gUnk_0811BD44
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D980: .4byte gUnk_085D100C
.L0804D984: .4byte gUnk_0811BF70
.L0804D988: .4byte gUnk_0811BD44

	thumb_func_start sub_804D98C
sub_804D98C: @ 0x0804D98C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804D9DC @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl sub_804DBAC
	ldr r0, .L0804D9E0 @ =gUnk_0811C1D8
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804D9E4 @ =gUnk_0811BF90
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D9DC: .4byte gUnk_085D100C
.L0804D9E0: .4byte gUnk_0811C1D8
.L0804D9E4: .4byte gUnk_0811BF90

	thumb_func_start sub_804D9E8
sub_804D9E8: @ 0x0804D9E8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804DA38 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl sub_804DBAC
	ldr r0, .L0804DA3C @ =gUnk_0811C430
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804DA40 @ =gUnk_0811C1F8
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DA38: .4byte gUnk_085D100C
.L0804DA3C: .4byte gUnk_0811C430
.L0804DA40: .4byte gUnk_0811C1F8

	thumb_func_start sub_804DA44
sub_804DA44: @ 0x0804DA44
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804DA94 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl sub_804DBAC
	ldr r0, .L0804DA98 @ =gUnk_0811C6B4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804DA9C @ =gUnk_0811C450
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DA94: .4byte gUnk_085D100C
.L0804DA98: .4byte gUnk_0811C6B4
.L0804DA9C: .4byte gUnk_0811C450

	thumb_func_start sub_804DAA0
sub_804DAA0: @ 0x0804DAA0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804DAF0 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl sub_804DBAC
	ldr r0, .L0804DAF4 @ =gUnk_0811C944
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804DAF8 @ =gUnk_0811C6D4
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DAF0: .4byte gUnk_085D100C
.L0804DAF4: .4byte gUnk_0811C944
.L0804DAF8: .4byte gUnk_0811C6D4

	thumb_func_start sub_804DAFC
sub_804DAFC: @ 0x0804DAFC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804DB86
	ldr r0, [r5, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r5, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xca
	movs r3, #1
	bl sub_805C804
	ldrh r0, [r5, #0x2c]
	cmp r0, #1
	bne .L0804DB86
	ldr r0, [r5, #0x5c]
	bl sub_804B80C
	adds r6, r0, #0
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r6, #0
	bl sub_8047600
	adds r0, r6, #0
	bl sub_805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	beq .L0804DB78
	ldr r0, [r5, #0x5c]
	bl sub_804B7B0
	cmp r0, #1
	bne .L0804DB6C
	adds r0, r6, #0
	bl sub_8056B08
	b .L0804DB78
.L0804DB6C:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804DBA4
	ldr r0, [r5, #0x5c]
	bl sub_8056C3C
.L0804DB78:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804DBA4
	adds r0, r6, #0
	bl sub_805C358
	b .L0804DBA4
.L0804DB86:
	movs r3, #0x2c
	ldrsh r0, [r5, r3]
	cmp r0, #0xe
	bne .L0804DB96
	ldr r0, [r5, #0x5c]
	bl sub_804B80C
	b .L0804DBA4
.L0804DB96:
	cmp r0, #0x10
	bne .L0804DBA4
	bl sub_80474BC
	adds r0, r5, #0
	bl Proc_Break
.L0804DBA4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804DBAC
sub_804DBAC: @ 0x0804DBAC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r1, .L0804DBD8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804DBDC @ =gUnk_085D1024
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	cmp r4, #0
	bne .L0804DBE8
	ldr r2, .L0804DBE0 @ =gUnk_085D44E4
	ldr r3, .L0804DBE4 @ =gUnk_085D4738
	b .L0804DBEC
	.align 2, 0
.L0804DBD8: .4byte gUnk_Banim_02017744
.L0804DBDC: .4byte gUnk_085D1024
.L0804DBE0: .4byte gUnk_085D44E4
.L0804DBE4: .4byte gUnk_085D4738
.L0804DBE8:
	ldr r2, .L0804DC0C @ =gUnk_085D4998
	ldr r3, .L0804DC10 @ =gUnk_085D4BF8
.L0804DBEC:
	str r2, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	bl sub_80478DC
	adds r4, r0, #0
	str r4, [r5, #0x60]
	adds r0, r6, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804DC14
	ldrh r0, [r4, #2]
	adds r0, #0x38
	b .L0804DC18
	.align 2, 0
.L0804DC0C: .4byte gUnk_085D4998
.L0804DC10: .4byte gUnk_085D4BF8
.L0804DC14:
	ldrh r0, [r4, #2]
	subs r0, #0x38
.L0804DC18:
	strh r0, [r4, #2]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804DC24
sub_804DC24: @ 0x0804DC24
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	bne .L0804DC4A
	ldr r0, .L0804DC50 @ =gUnk_Banim_02017744
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0804DC4A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DC50: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804DC54
sub_804DC54: @ 0x0804DC54
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804DC88 @ =gUnk_085D103C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DC88: .4byte gUnk_085D103C

	thumb_func_start sub_804DC8C
sub_804DC8C: @ 0x0804DC8C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl sub_804B80C
	adds r4, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x27
	bne .L0804DCC4
	adds r0, r4, #0
	bl sub_804DD38
	adds r0, r4, #0
	bl sub_804DDC8
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r4, r0]
	movs r0, #0xef
	movs r3, #1
	bl sub_805C804
.L0804DCC4:
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0x45
	bne .L0804DD1C
	movs r0, #9
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r1, [r0]
	adds r0, r4, #0
	bl sub_80478A0
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804DD00
	ldr r0, .L0804DCF8 @ =gUnk_Banim_0200004C
	ldr r0, [r0]
	ldr r1, .L0804DCFC @ =gPal+0x2E0
	movs r2, #8
	bl CpuFastSet
	b .L0804DD0C
	.align 2, 0
.L0804DCF8: .4byte gUnk_Banim_0200004C
.L0804DCFC: .4byte gPal+0x2E0
.L0804DD00:
	ldr r0, .L0804DD14 @ =gUnk_Banim_0200004C
	ldr r0, [r0, #4]
	ldr r1, .L0804DD18 @ =gPal+0x320
	movs r2, #8
	bl CpuFastSet
.L0804DD0C:
	adds r0, r4, #0
	bl sub_8046EF8
	b .L0804DD32
	.align 2, 0
.L0804DD14: .4byte gUnk_Banim_0200004C
.L0804DD18: .4byte gPal+0x320
.L0804DD1C:
	cmp r0, #0x64
	bne .L0804DD32
	movs r0, #2
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
	bl sub_80474BC
	adds r0, r5, #0
	bl Proc_Break
.L0804DD32:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_804DD38
sub_804DD38: @ 0x0804DD38
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, .L0804DD80 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804DD84 @ =gUnk_085D1054
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, .L0804DD88 @ =gUnk_0811CAF8
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, .L0804DD8C @ =gUnk_0811CD14
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, [r4, #0x5c]
	ldr r2, .L0804DD90 @ =gUnk_0811D0D4
	adds r1, r2, #0
	bl sub_804799C
	bl sub_80474C8
	bl sub_8047500
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DD80: .4byte gUnk_Banim_02017744
.L0804DD84: .4byte gUnk_085D1054
.L0804DD88: .4byte gUnk_0811CAF8
.L0804DD8C: .4byte gUnk_0811CD14
.L0804DD90: .4byte gUnk_0811D0D4

	thumb_func_start sub_804DD94
sub_804DD94: @ 0x0804DD94
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	bne .L0804DDBC
	bl sub_80474D8
	bl sub_80475D8
	ldr r1, .L0804DDC4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804DDBC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DDC4: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804DDC8
sub_804DDC8: @ 0x0804DDC8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804DDF4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804DDF8 @ =gUnk_085D106C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804DDFC @ =gUnk_08119CDC
	str r1, [r0, #0x48]
	ldr r1, .L0804DE00 @ =gUnk_0811CD14
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DDF4: .4byte gUnk_Banim_02017744
.L0804DDF8: .4byte gUnk_085D106C
.L0804DDFC: .4byte gUnk_08119CDC
.L0804DE00: .4byte gUnk_0811CD14

	thumb_func_start sub_804DE04
sub_804DE04: @ 0x0804DE04
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0804DE2A
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
	b .L0804DE40
.L0804DE2A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804DE40
	ldr r1, .L0804DE48 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804DE40:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DE48: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804DE4C
sub_804DE4C: @ 0x0804DE4C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804DE80 @ =gUnk_085D108C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DE80: .4byte gUnk_085D108C

	thumb_func_start sub_804DE84
sub_804DE84: @ 0x0804DE84
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl sub_804B80C
	adds r4, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x19
	bne .L0804DEBC
	adds r0, r4, #0
	bl sub_804DD38
	adds r0, r4, #0
	bl sub_804DDC8
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r4, r0]
	movs r0, #0xef
	movs r3, #1
	bl sub_805C804
.L0804DEBC:
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0x37
	bne .L0804DF14
	movs r0, #9
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r1, [r0]
	adds r0, r4, #0
	bl sub_80478A0
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804DEF8
	ldr r0, .L0804DEF0 @ =gUnk_Banim_0200004C
	ldr r0, [r0]
	ldr r1, .L0804DEF4 @ =gPal+0x2E0
	movs r2, #8
	bl CpuFastSet
	b .L0804DF04
	.align 2, 0
.L0804DEF0: .4byte gUnk_Banim_0200004C
.L0804DEF4: .4byte gPal+0x2E0
.L0804DEF8:
	ldr r0, .L0804DF0C @ =gUnk_Banim_0200004C
	ldr r0, [r0, #4]
	ldr r1, .L0804DF10 @ =gPal+0x320
	movs r2, #8
	bl CpuFastSet
.L0804DF04:
	adds r0, r4, #0
	bl sub_8046EF8
	b .L0804DF2A
	.align 2, 0
.L0804DF0C: .4byte gUnk_Banim_0200004C
.L0804DF10: .4byte gPal+0x320
.L0804DF14:
	cmp r0, #0x64
	bne .L0804DF2A
	movs r0, #2
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
	bl sub_80474BC
	adds r0, r5, #0
	bl Proc_Break
.L0804DF2A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_804DF30
sub_804DF30: @ 0x0804DF30
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804DF7C @ =gUnk_085D10A4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r1, r4, #0
	adds r1, #0x29
	strb r0, [r1]
	movs r0, #0x9b
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl sub_805C804
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DF7C: .4byte gUnk_085D10A4

	thumb_func_start sub_804DF80
sub_804DF80: @ 0x0804DF80
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl sub_804B80C
	adds r6, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne .L0804DFA6
	ldr r0, [r5, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	b .L0804E038
.L0804DFA6:
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0x22
	bne .L0804DFC8
	ldr r0, .L0804DFC4 @ =0x00000137
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r5, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl sub_805C804
	b .L0804E038
	.align 2, 0
.L0804DFC4: .4byte 0x00000137
.L0804DFC8:
	cmp r0, #0x2a
	bne .L0804DFD4
	adds r0, r6, #0
	bl sub_804E040
	b .L0804E038
.L0804DFD4:
	cmp r0, #0x2d
	bne .L0804E026
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r6, #0
	bl sub_8047600
	adds r0, r6, #0
	bl sub_805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	beq .L0804E018
	ldr r0, [r5, #0x5c]
	bl sub_804B7B0
	cmp r0, #1
	bne .L0804E00C
	adds r0, r6, #0
	bl sub_8056B08
	b .L0804E018
.L0804E00C:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804E038
	ldr r0, [r5, #0x5c]
	bl sub_8056C3C
.L0804E018:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804E038
	adds r0, r6, #0
	bl sub_805C358
	b .L0804E038
.L0804E026:
	cmp r0, #0x3e
	beq .L0804E038
	cmp r0, #0x40
	bne .L0804E038
	bl sub_80474BC
	adds r0, r5, #0
	bl Proc_Break
.L0804E038:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804E040
sub_804E040: @ 0x0804E040
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804E094 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E098 @ =gUnk_085D10BC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r7, #0
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L0804E09C @ =gUnk_085D4CFC
	ldr r2, .L0804E0A0 @ =gUnk_085D4D98
	str r2, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	bl sub_80478DC
	adds r6, r0, #0
	str r6, [r4, #0x60]
	ldrh r0, [r6, #4]
	adds r0, #0x10
	strh r0, [r6, #4]
	movs r0, #0xc0
	lsls r0, r0, #4
	ldrh r1, [r6, #8]
	ands r0, r1
	strh r0, [r6, #8]
	adds r0, r5, #0
	bl sub_804B6C4
	cmp r0, #1
	bne .L0804E0A4
	movs r1, #0xe4
	lsls r1, r1, #7
	b .L0804E0A8
	.align 2, 0
.L0804E094: .4byte gUnk_Banim_02017744
.L0804E098: .4byte gUnk_085D10BC
.L0804E09C: .4byte gUnk_085D4CFC
.L0804E0A0: .4byte gUnk_085D4D98
.L0804E0A4:
	movs r1, #0x93
	lsls r1, r1, #8
.L0804E0A8:
	adds r0, r1, #0
	ldrh r1, [r6, #8]
	orrs r0, r1
	strh r0, [r6, #8]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_804E0B8
sub_804E0B8: @ 0x0804E0B8
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	ble .L0804E0DE
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804E0E4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804E0DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E0E4: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804E0E8
sub_804E0E8: @ 0x0804E0E8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L0804E120 @ =gUnk_085D10D4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E120: .4byte gUnk_085D10D4

	thumb_func_start sub_804E124
sub_804E124: @ 0x0804E124
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804E148
	ldr r0, [r4, #0x5c]
	movs r1, #6
	bl sub_8046794
	b .L0804E1BA
.L0804E148:
	cmp r0, #6
	bne .L0804E180
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	adds r0, r5, #0
	movs r1, #9
	bl sub_804E1C0
	adds r0, r5, #0
	movs r1, #9
	bl sub_804E2B4
	adds r0, r5, #0
	bl sub_804E3C0
	movs r0, #0x86
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	b .L0804E1BA
.L0804E180:
	cmp r0, #0xa
	bne .L0804E1A4
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804E1BA
	adds r0, r5, #0
	bl sub_805C358
	b .L0804E1BA
.L0804E1A4:
	cmp r0, #0x19
	beq .L0804E1BA
	cmp r0, #0x1e
	bne .L0804E1BA
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L0804E1BA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_804E1C0
sub_804E1C0: @ 0x0804E1C0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, .L0804E220 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E224 @ =gUnk_085D10EC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r6, [r4, #0x2e]
	ldr r0, .L0804E228 @ =gUnk_0811F22C
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L0804E22C @ =gUnk_0811E36C
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, .L0804E230 @ =gUnk_0811F32C
	ldr r5, .L0804E234 @ =gUnk_Banim_0201977C
	adds r1, r5, #0
	bl LZ77UnCompWram
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804E23C
	ldr r1, .L0804E238 @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x14
	bl sub_805B1AC
	b .L0804E250
	.align 2, 0
.L0804E220: .4byte gUnk_Banim_02017744
.L0804E224: .4byte gUnk_085D10EC
.L0804E228: .4byte gUnk_0811F22C
.L0804E22C: .4byte gUnk_0811E36C
.L0804E230: .4byte gUnk_0811F32C
.L0804E234: .4byte gUnk_Banim_0201977C
.L0804E238: .4byte gBg1Tm
.L0804E23C:
	ldr r1, .L0804E278 @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x14
	bl sub_805B1DC
.L0804E250:
	movs r0, #2
	bl EnableBgSync
	bl sub_8047500
	ldr r2, .L0804E27C @ =gDispIo
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
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E278: .4byte gBg1Tm
.L0804E27C: .4byte gDispIo

	thumb_func_start sub_804E280
sub_804E280: @ 0x0804E280
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0804E2AA
	bl sub_80474D8
	ldr r1, .L0804E2B0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L0804E2AA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E2B0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804E2B4
sub_804E2B4: @ 0x0804E2B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L0804E2E4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E2E8 @ =gUnk_085D1104
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	strh r5, [r6, #0x2e]
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804E2EC
	movs r0, #0xd8
	b .L0804E2F0
	.align 2, 0
.L0804E2E4: .4byte gUnk_Banim_02017744
.L0804E2E8: .4byte gUnk_085D1104
.L0804E2EC:
	movs r0, #0xd8
	rsbs r0, r0, #0
.L0804E2F0:
	str r0, [r6, #0x44]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_804E2F8
sub_804E2F8: @ 0x0804E2F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r2, [r6, #0x44]
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl Interpolate
	ldr r4, .L0804E330 @ =gDispIo
	strh r0, [r4, #0x20]
	ldr r0, [r6, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804E334
	ldrh r4, [r4, #0x20]
	lsrs r0, r4, #3
	adds r7, r0, #0
	adds r7, #0x1e
	b .L0804E33A
	.align 2, 0
.L0804E330: .4byte gDispIo
.L0804E334:
	ldrh r4, [r4, #0x20]
	lsrs r0, r4, #3
	subs r7, r0, #1
.L0804E33A:
	movs r2, #0x1f
	mov r8, r2
	adds r0, r7, #0
	ands r0, r2
	lsls r0, r0, #1
	ldr r5, .L0804E3B8 @ =gBg1Tm
	adds r0, r0, r5
	movs r4, #0x80
	lsls r4, r4, #1
	str r4, [sp]
	movs r1, #1
	movs r2, #0x14
	movs r3, #1
	bl sub_805B094
	adds r0, r7, #1
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	str r4, [sp]
	movs r1, #1
	movs r2, #0x14
	movs r3, #1
	bl sub_805B094
	adds r0, r7, #2
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r5
	str r4, [sp]
	movs r1, #1
	movs r2, #0x14
	movs r3, #1
	bl sub_805B094
	movs r0, #2
	bl EnableBgSync
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r6, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0804E3AC
	ldr r1, .L0804E3BC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80474D8
	adds r0, r6, #0
	bl Proc_Break
.L0804E3AC:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E3B8: .4byte gBg1Tm
.L0804E3BC: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804E3C0
sub_804E3C0: @ 0x0804E3C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804E3EC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E3F0 @ =gUnk_085D111C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804E3F4 @ =gUnk_08119D56
	str r1, [r0, #0x48]
	ldr r1, .L0804E3F8 @ =gUnk_0811F22C
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E3EC: .4byte gUnk_Banim_02017744
.L0804E3F0: .4byte gUnk_085D111C
.L0804E3F4: .4byte gUnk_08119D56
.L0804E3F8: .4byte gUnk_0811F22C

	thumb_func_start sub_804E3FC
sub_804E3FC: @ 0x0804E3FC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0804E422
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
	b .L0804E43C
.L0804E422:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804E43C
	bl sub_80475D8
	ldr r1, .L0804E444 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804E43C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E444: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804E448
sub_804E448: @ 0x0804E448
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L0804E480 @ =gUnk_085D113C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E480: .4byte gUnk_085D113C

	thumb_func_start sub_804E484
sub_804E484: @ 0x0804E484
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804E4B2
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L0804E4B2:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #1
	cmp r1, r0
	bne .L0804E500
	ldr r0, .L0804E4FC @ =0x0000010D
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	adds r0, r5, #0
	bl sub_804E540
	ldr r0, [r4, #0x5c]
	movs r1, #6
	bl sub_8046794
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804E536
	adds r0, r5, #0
	bl sub_805C358
	b .L0804E536
	.align 2, 0
.L0804E4FC: .4byte 0x0000010D
.L0804E500:
	adds r0, r6, #0
	adds r0, #0x1c
	cmp r1, r0
	bne .L0804E51A
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xe
	movs r3, #0x10
	bl sub_804CD88
	b .L0804E536
.L0804E51A:
	adds r0, r6, #0
	adds r0, #0x32
	cmp r1, r0
	beq .L0804E536
	adds r0, #5
	cmp r1, r0
	bne .L0804E536
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L0804E536:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804E540
sub_804E540: @ 0x0804E540
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804E598 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E59C @ =gUnk_085D1154
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x34
	strh r0, [r4, #0x2e]
	adds r0, r5, #0
	bl sub_804B6C4
	ldr r3, .L0804E5A0 @ =gUnk_085D6E78
	cmp r0, #0
	bne .L0804E570
	ldr r3, .L0804E5A4 @ =gUnk_085D6218
.L0804E570:
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r0, .L0804E5A8 @ =gUnk_081203F4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804E5AC @ =gUnk_0811F6F4
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E598: .4byte gUnk_Banim_02017744
.L0804E59C: .4byte gUnk_085D1154
.L0804E5A0: .4byte gUnk_085D6E78
.L0804E5A4: .4byte gUnk_085D6218
.L0804E5A8: .4byte gUnk_081203F4
.L0804E5AC: .4byte gUnk_0811F6F4

	thumb_func_start sub_804E5B0
sub_804E5B0: @ 0x0804E5B0
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0804E5D8
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804E5E0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804E5D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E5E0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804E5E4
sub_804E5E4: @ 0x0804E5E4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804E618 @ =gUnk_085D116C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E618: .4byte gUnk_085D116C

	thumb_func_start sub_804E61C
sub_804E61C: @ 0x0804E61C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804E67C
	ldr r0, [r4, #0x5c]
	movs r1, #0x5a
	bl sub_804D050
	adds r0, r5, #0
	bl sub_804E6BC
	adds r0, r5, #0
	bl sub_804E778
	adds r0, r5, #0
	bl sub_804E848
	str r6, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x28
	movs r2, #0xf
	movs r3, #0x10
	bl sub_804CD88
	ldr r0, .L0804E678 @ =0x0000011D
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	b .L0804E6B2
	.align 2, 0
.L0804E678: .4byte 0x0000011D
.L0804E67C:
	cmp r0, #0xf
	bne .L0804E6A0
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804E6B2
	adds r0, r5, #0
	bl sub_805C358
	b .L0804E6B2
.L0804E6A0:
	cmp r0, #0x78
	beq .L0804E6B2
	cmp r0, #0x82
	bne .L0804E6B2
	bl sub_80474BC
	adds r0, r4, #0
	bl Proc_Break
.L0804E6B2:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804E6BC
sub_804E6BC: @ 0x0804E6BC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, .L0804E70C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E710 @ =gUnk_085D1184
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #0x34
	strh r0, [r5, #0x2e]
	adds r0, r6, #0
	bl sub_804B6C4
	ldr r3, .L0804E714 @ =gUnk_085D9208
	cmp r0, #0
	bne .L0804E6EC
	ldr r3, .L0804E718 @ =gUnk_085D8608
.L0804E6EC:
	str r3, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	adds r4, r0, #0
	str r4, [r5, #0x60]
	adds r0, r6, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804E71C
	ldrh r0, [r4, #2]
	adds r0, #0x20
	b .L0804E720
	.align 2, 0
.L0804E70C: .4byte gUnk_Banim_02017744
.L0804E710: .4byte gUnk_085D1184
.L0804E714: .4byte gUnk_085D9208
.L0804E718: .4byte gUnk_085D8608
.L0804E71C:
	ldrh r0, [r4, #2]
	subs r0, #0x20
.L0804E720:
	strh r0, [r4, #2]
	ldr r0, .L0804E73C @ =gUnk_081203F4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804E740 @ =gUnk_0811F6F4
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E73C: .4byte gUnk_081203F4
.L0804E740: .4byte gUnk_0811F6F4

	thumb_func_start sub_804E744
sub_804E744: @ 0x0804E744
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0804E76C
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804E774 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804E76C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E774: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804E778
sub_804E778: @ 0x0804E778
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L0804E7D8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E7DC @ =gUnk_085D119C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #0x70
	strh r0, [r5, #0x2e]
	ldr r0, .L0804E7E0 @ =gUnk_0813A6F8
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r5, #0x5c]
	ldr r2, .L0804E7E4 @ =gUnk_0813BA64
	adds r1, r2, #0
	bl sub_804799C
	bl sub_80474C8
	bl sub_8047500
	ldr r0, .L0804E7E8 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804E808
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804E7EC
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0804E7F6
	.align 2, 0
.L0804E7D8: .4byte gUnk_Banim_02017744
.L0804E7DC: .4byte gUnk_085D119C
.L0804E7E0: .4byte gUnk_0813A6F8
.L0804E7E4: .4byte gUnk_0813BA64
.L0804E7E8: .4byte 0x0203CD14
.L0804E7EC:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0804E7F6:
	ldr r0, .L0804E810 @ =gBg1Tm+0x3C
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #2
	movs r2, #0x14
	movs r3, #1
	bl sub_805B0D4
.L0804E808:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E810: .4byte gBg1Tm+0x3C

	thumb_func_start sub_804E814
sub_804E814: @ 0x0804E814
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0804E83E
	bl sub_80474D8
	bl sub_80475D8
	ldr r1, .L0804E844 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804E83E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E844: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804E848
sub_804E848: @ 0x0804E848
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804E874 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E878 @ =gUnk_085D11B4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804E87C @ =gUnk_08119D78
	str r1, [r0, #0x48]
	ldr r1, .L0804E880 @ =gUnk_0813B6B4
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E874: .4byte gUnk_Banim_02017744
.L0804E878: .4byte gUnk_085D11B4
.L0804E87C: .4byte gUnk_08119D78
.L0804E880: .4byte gUnk_0813B6B4

	thumb_func_start sub_804E884
sub_804E884: @ 0x0804E884
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0804E8AA
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
	b .L0804E8C0
.L0804E8AA:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804E8C0
	ldr r1, .L0804E8C8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804E8C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E8C8: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804E8CC
sub_804E8CC: @ 0x0804E8CC
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L0804E904 @ =gUnk_085D11D4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E904: .4byte gUnk_085D11D4

	thumb_func_start sub_804E908
sub_804E908: @ 0x0804E908
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804E942
	ldr r0, [r4, #0x5c]
	movs r1, #0x5a
	bl sub_804D050
	ldr r0, [r4, #0x5c]
	bl sub_804E988
	movs r0, #0x8f
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
.L0804E942:
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #4
	bne .L0804E96A
	movs r0, #9
	ldrh r3, [r5, #0x10]
	orrs r0, r3
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804E980
	adds r0, r5, #0
	bl sub_805C358
	b .L0804E980
.L0804E96A:
	cmp r0, #0x32
	beq .L0804E980
	cmp r0, #0x3c
	bne .L0804E980
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L0804E980:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804E988
sub_804E988: @ 0x0804E988
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L0804E9C4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E9C8 @ =gUnk_085D11EC
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	ldr r2, .L0804E9CC @ =gUnk_085D9E38
	ldr r3, .L0804E9D0 @ =gUnk_085DAA68
	str r2, [sp]
	adds r0, r4, #0
	adds r1, r3, #0
	bl sub_80478DC
	adds r6, r0, #0
	str r6, [r5, #0x60]
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804E9D4
	ldrh r0, [r6, #2]
	adds r0, #0x20
	b .L0804E9D8
	.align 2, 0
.L0804E9C4: .4byte gUnk_Banim_02017744
.L0804E9C8: .4byte gUnk_085D11EC
.L0804E9CC: .4byte gUnk_085D9E38
.L0804E9D0: .4byte gUnk_085DAA68
.L0804E9D4:
	ldrh r0, [r6, #2]
	subs r0, #0x20
.L0804E9D8:
	strh r0, [r6, #2]
	ldr r0, .L0804E9F4 @ =gUnk_081214B8
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804E9F8 @ =gUnk_0811F6F4
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E9F4: .4byte gUnk_081214B8
.L0804E9F8: .4byte gUnk_0811F6F4

	thumb_func_start sub_804E9FC
sub_804E9FC: @ 0x0804E9FC
	push {lr}
	ldr r2, .L0804EA10 @ =gUnk_Banim_02017744
	ldr r1, [r2]
	subs r1, #1
	str r1, [r2]
	ldr r0, [r0, #0x60]
	bl BasRemove
	pop {r0}
	bx r0
	.align 2, 0
.L0804EA10: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804EA14
sub_804EA14: @ 0x0804EA14
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_80474C8
	ldr r0, .L0804EA48 @ =gUnk_085D120C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EA48: .4byte gUnk_085D120C

	thumb_func_start sub_804EA4C
sub_804EA4C: @ 0x0804EA4C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804EA90
	ldr r0, [r4, #0x5c]
	movs r1, #0x5a
	bl sub_804D050
	ldr r0, [r4, #0x5c]
	bl sub_804EAD4
	ldr r0, [r4, #0x5c]
	bl sub_804EB7C
	ldr r0, [r4, #0x5c]
	bl sub_804EC04
	ldr r0, .L0804EAB8 @ =0x0000011F
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
.L0804EA90:
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #4
	bne .L0804EABC
	movs r0, #9
	ldrh r3, [r5, #0x10]
	orrs r0, r3
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804EACE
	adds r0, r5, #0
	bl sub_805C358
	b .L0804EACE
	.align 2, 0
.L0804EAB8: .4byte 0x0000011F
.L0804EABC:
	cmp r0, #0x20
	beq .L0804EACE
	cmp r0, #0x30
	bne .L0804EACE
	bl sub_80474BC
	adds r0, r4, #0
	bl Proc_Break
.L0804EACE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_804EAD4
sub_804EAD4: @ 0x0804EAD4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804EB10 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804EB14 @ =gUnk_085D1224
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804EB18 @ =gUnk_08119DEA
	str r1, [r0, #0x48]
	ldr r1, .L0804EB1C @ =gUnk_085D123C
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r0, .L0804EB20 @ =gUnk_081214F8
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	bl sub_8047500
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EB10: .4byte gUnk_Banim_02017744
.L0804EB14: .4byte gUnk_085D1224
.L0804EB18: .4byte gUnk_08119DEA
.L0804EB1C: .4byte gUnk_085D123C
.L0804EB20: .4byte gUnk_081214F8

	thumb_func_start sub_804EB24
sub_804EB24: @ 0x0804EB24
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L0804EB52
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl sub_804799C
	b .L0804EB70
.L0804EB52:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L0804EB70
	bl sub_80474D8
	ldr r1, .L0804EB78 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L0804EB70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EB78: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804EB7C
sub_804EB7C: @ 0x0804EB7C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804EBA8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804EBAC @ =gUnk_085D126C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804EBB0 @ =gUnk_08119E30
	str r1, [r0, #0x48]
	ldr r1, .L0804EBB4 @ =gUnk_0813E75C
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EBA8: .4byte gUnk_Banim_02017744
.L0804EBAC: .4byte gUnk_085D126C
.L0804EBB0: .4byte gUnk_08119E30
.L0804EBB4: .4byte gUnk_0813E75C

	thumb_func_start sub_804EBB8
sub_804EBB8: @ 0x0804EBB8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0804EBDE
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
	b .L0804EBF8
.L0804EBDE:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804EBF8
	bl sub_80475D8
	ldr r1, .L0804EC00 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804EBF8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EC00: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804EC04
sub_804EC04: @ 0x0804EC04
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804EC48 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804EC4C @ =gUnk_085D128C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x37
	strh r0, [r4, #0x2e]
	ldr r3, .L0804EC50 @ =gUnk_085DB6A4
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	adds r6, r0, #0
	str r6, [r4, #0x60]
	adds r0, r5, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804EC54
	ldrh r0, [r6, #2]
	adds r0, #0x24
	b .L0804EC58
	.align 2, 0
.L0804EC48: .4byte gUnk_Banim_02017744
.L0804EC4C: .4byte gUnk_085D128C
.L0804EC50: .4byte gUnk_085DB6A4
.L0804EC54:
	ldrh r0, [r6, #2]
	subs r0, #0x24
.L0804EC58:
	strh r0, [r6, #2]
	ldrh r0, [r6, #4]
	adds r0, #0xc
	strh r0, [r6, #4]
	ldr r0, .L0804EC7C @ =gUnk_081214D8
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804EC80 @ =gUnk_0811F6F4
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EC7C: .4byte gUnk_081214D8
.L0804EC80: .4byte gUnk_0811F6F4

	thumb_func_start sub_804EC84
sub_804EC84: @ 0x0804EC84
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0804ECAC
	ldr r0, .L0804ECB4 @ =gUnk_Banim_02017744
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0804ECAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804ECB4: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804ECB8
sub_804ECB8: @ 0x0804ECB8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L0804ECF0 @ =gUnk_085D12A4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804ECF0: .4byte gUnk_085D12A4

	thumb_func_start sub_804ECF4
sub_804ECF4: @ 0x0804ECF4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804ED1E
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L0804ED1E:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #1
	cmp r1, r0
	bne .L0804ED3C
	adds r0, r5, #0
	bl sub_804ED94
	adds r0, r5, #0
	bl sub_804EE9C
	adds r0, r5, #0
	bl sub_804EF24
	b .L0804ED8E
.L0804ED3C:
	adds r0, r6, #4
	cmp r1, r0
	bne .L0804ED72
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r5, r0]
	movs r0, #0xf5
	movs r3, #1
	bl sub_805C804
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804ED8E
	adds r0, r5, #0
	bl sub_805C358
	b .L0804ED8E
.L0804ED72:
	adds r0, r6, #0
	adds r0, #0x50
	cmp r1, r0
	beq .L0804ED8E
	adds r0, #0x10
	cmp r1, r0
	bne .L0804ED8E
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L0804ED8E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_804ED94
sub_804ED94: @ 0x0804ED94
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L0804EDEC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804EDF0 @ =gUnk_085D12BC
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L0804EDF4 @ =gUnk_08119ED2
	str r0, [r5, #0x48]
	ldr r0, .L0804EDF8 @ =gUnk_085D12D4
	str r0, [r5, #0x4c]
	ldr r0, .L0804EDFC @ =gUnk_085D12DC
	str r0, [r5, #0x50]
	ldr r0, .L0804EE00 @ =gUnk_0812C68C
	movs r1, #0x86
	lsls r1, r1, #5
	bl sub_8047ACC
	bl sub_8047500
	ldr r0, .L0804EE04 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804EE12
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804EE08
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0804EE12
	.align 2, 0
.L0804EDEC: .4byte gUnk_Banim_02017744
.L0804EDF0: .4byte gUnk_085D12BC
.L0804EDF4: .4byte gUnk_08119ED2
.L0804EDF8: .4byte gUnk_085D12D4
.L0804EDFC: .4byte gUnk_085D12DC
.L0804EE00: .4byte gUnk_0812C68C
.L0804EE04: .4byte 0x0203CD14
.L0804EE08:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0804EE12:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_804EE18
sub_804EE18: @ 0x0804EE18
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r6, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	blt .L0804EE70
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r5, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl sub_804799C
	cmp r5, #0
	bne .L0804EE4E
	ldr r6, .L0804EE68 @ =0x0000011F
.L0804EE4E:
	cmp r5, #1
	bne .L0804EE56
	movs r6, #0xa8
	lsls r6, r6, #1
.L0804EE56:
	ldr r0, .L0804EE6C @ =gBg1Tm+0x3C
	str r6, [sp]
	movs r1, #2
	movs r2, #0x14
	movs r3, #1
	bl sub_805B094
	b .L0804EE8E
	.align 2, 0
.L0804EE68: .4byte 0x0000011F
.L0804EE6C: .4byte gBg1Tm+0x3C
.L0804EE70:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L0804EE8E
	bl sub_80474D8
	ldr r1, .L0804EE98 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L0804EE8E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EE98: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804EE9C
sub_804EE9C: @ 0x0804EE9C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804EEC8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804EECC @ =gUnk_085D12E4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804EED0 @ =gUnk_08119EDC
	str r1, [r0, #0x48]
	ldr r1, .L0804EED4 @ =gUnk_0812CF48
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EEC8: .4byte gUnk_Banim_02017744
.L0804EECC: .4byte gUnk_085D12E4
.L0804EED0: .4byte gUnk_08119EDC
.L0804EED4: .4byte gUnk_0812CF48

	thumb_func_start sub_804EED8
sub_804EED8: @ 0x0804EED8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0804EEFE
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
	b .L0804EF18
.L0804EEFE:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804EF18
	bl sub_80475D8
	ldr r1, .L0804EF20 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804EF18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EF20: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804EF24
sub_804EF24: @ 0x0804EF24
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804EF6C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804EF70 @ =gUnk_085D1304
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L0804EF74 @ =gUnk_085E2508
	ldr r2, .L0804EF78 @ =gUnk_085E19DC
	str r2, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r0, .L0804EF7C @ =gUnk_0812D80C
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804EF80 @ =gUnk_0812D374
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EF6C: .4byte gUnk_Banim_02017744
.L0804EF70: .4byte gUnk_085D1304
.L0804EF74: .4byte gUnk_085E2508
.L0804EF78: .4byte gUnk_085E19DC
.L0804EF7C: .4byte gUnk_0812D80C
.L0804EF80: .4byte gUnk_0812D374

	thumb_func_start sub_804EF84
sub_804EF84: @ 0x0804EF84
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	ble .L0804EFAA
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804EFB0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804EFAA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EFB0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804EFB4
sub_804EFB4: @ 0x0804EFB4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L0804EFF4 @ =gUnk_085D131C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r1, #0
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x2a
	strb r1, [r0]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EFF4: .4byte gUnk_085D131C

	thumb_func_start sub_804EFF8
sub_804EFF8: @ 0x0804EFF8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L0804F038 @ =gUnk_085D131C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r1, r4, #0
	adds r1, #0x2a
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F038: .4byte gUnk_085D131C

	thumb_func_start sub_804F03C
sub_804F03C: @ 0x0804F03C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r6, r0, #0
	ldr r0, .L0804F068 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0804F06C
	movs r5, #0x20
	movs r7, #0x34
	movs r3, #0x36
	mov r8, r3
	movs r0, #0x55
	mov sb, r0
	b .L0804F078
	.align 2, 0
.L0804F068: .4byte 0x0203CD14
.L0804F06C:
	movs r5, #0x28
	movs r7, #0x3c
	movs r1, #0x41
	mov r8, r1
	movs r3, #0x60
	mov sb, r3
.L0804F078:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804F0A4
	ldr r0, [r4, #0x5c]
	bl sub_804F144
	ldr r0, [r4, #0x5c]
	bl sub_804F1FC
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf1
	movs r3, #1
	bl sub_805C804
.L0804F0A4:
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, r5
	bne .L0804F0B8
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	b .L0804F138
.L0804F0B8:
	cmp r0, r7
	bne .L0804F122
	movs r0, #9
	ldrh r3, [r6, #0x10]
	orrs r0, r3
	strh r0, [r6, #0x10]
	adds r5, r4, #0
	adds r5, #0x29
	ldrb r1, [r5]
	adds r0, r6, #0
	bl sub_8047600
	ldrb r0, [r5]
	cmp r0, #0
	bne .L0804F138
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0804F0F8
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r6, r0]
	movs r0, #0xf7
	movs r3, #1
	bl sub_805C804
	adds r0, r6, #0
	bl sub_804F2D0
	b .L0804F11A
.L0804F0F8:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r6, r3]
	movs r0, #0xf8
	movs r3, #1
	bl sub_805C804
	adds r0, r6, #0
	bl sub_804F3B8
	adds r0, r6, #0
	bl sub_804F484
	adds r0, r6, #0
	bl sub_804F510
.L0804F11A:
	adds r0, r6, #0
	bl sub_805C358
	b .L0804F138
.L0804F122:
	cmp r0, r8
	beq .L0804F138
	cmp r0, sb
	bne .L0804F138
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L0804F138:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_804F144
sub_804F144: @ 0x0804F144
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804F188 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F18C @ =gUnk_085D1334
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804F190 @ =gUnk_08119F1E
	str r1, [r0, #0x48]
	ldr r1, .L0804F194 @ =gUnk_085D134C
	str r1, [r0, #0x4c]
	ldr r1, .L0804F198 @ =gUnk_085D137C
	str r1, [r0, #0x50]
	ldr r0, .L0804F19C @ =gUnk_0812E4A4
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L0804F1A0 @ =gUnk_0812D8AC
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	bl sub_8047500
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F188: .4byte gUnk_Banim_02017744
.L0804F18C: .4byte gUnk_085D1334
.L0804F190: .4byte gUnk_08119F1E
.L0804F194: .4byte gUnk_085D134C
.L0804F198: .4byte gUnk_085D137C
.L0804F19C: .4byte gUnk_0812E4A4
.L0804F1A0: .4byte gUnk_0812D8AC

	thumb_func_start sub_804F1A4
sub_804F1A4: @ 0x0804F1A4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L0804F1D2
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl sub_804799C
	b .L0804F1F0
.L0804F1D2:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L0804F1F0
	bl sub_80474D8
	ldr r1, .L0804F1F8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L0804F1F0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F1F8: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804F1FC
sub_804F1FC: @ 0x0804F1FC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, .L0804F240 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F244 @ =gUnk_085D13AC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r6, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r1, .L0804F248 @ =gUnk_085E2CA8
	ldr r2, .L0804F24C @ =gUnk_085E2920
	ldr r3, .L0804F250 @ =gUnk_085E2CD4
	ldr r0, .L0804F254 @ =gUnk_085E294C
	str r0, [sp]
	adds r0, r6, #0
	bl sub_80478DC
	adds r5, r0, #0
	str r5, [r4, #0x60]
	adds r0, r6, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804F258
	ldrh r0, [r6, #2]
	subs r0, #8
	b .L0804F25C
	.align 2, 0
.L0804F240: .4byte gUnk_Banim_02017744
.L0804F244: .4byte gUnk_085D13AC
.L0804F248: .4byte gUnk_085E2CA8
.L0804F24C: .4byte gUnk_085E2920
.L0804F250: .4byte gUnk_085E2CD4
.L0804F254: .4byte gUnk_085E294C
.L0804F258:
	ldrh r0, [r6, #2]
	adds r0, #8
.L0804F25C:
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	adds r0, #8
	strh r0, [r5, #4]
	ldr r0, .L0804F280 @ =gUnk_0812FFD8
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804F284 @ =gUnk_0812F9DC
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F280: .4byte gUnk_0812FFD8
.L0804F284: .4byte gUnk_0812F9DC

	thumb_func_start sub_804F288
sub_804F288: @ 0x0804F288
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x25
	bne .L0804F2AE
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf2
	movs r3, #1
	bl sub_805C804
	b .L0804F2C6
.L0804F2AE:
	cmp r0, #0x32
	ble .L0804F2C6
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804F2CC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804F2C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F2CC: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804F2D0
sub_804F2D0: @ 0x0804F2D0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L0804F328 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F32C @ =gUnk_085D13C4
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L0804F330 @ =gUnk_08119F50
	str r0, [r5, #0x48]
	ldr r0, .L0804F334 @ =gUnk_085D1430
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L0804F338 @ =gUnk_085D13DC
	str r0, [r5, #0x54]
	ldr r0, .L0804F33C @ =gUnk_08138BF0
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	ldr r0, .L0804F340 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804F34E
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804F344
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0804F34E
	.align 2, 0
.L0804F328: .4byte gUnk_Banim_02017744
.L0804F32C: .4byte gUnk_085D13C4
.L0804F330: .4byte gUnk_08119F50
.L0804F334: .4byte gUnk_085D1430
.L0804F338: .4byte gUnk_085D13DC
.L0804F33C: .4byte gUnk_08138BF0
.L0804F340: .4byte 0x0203CD14
.L0804F344:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0804F34E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_804F354
sub_804F354: @ 0x0804F354
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L0804F390
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl sub_804799C
	b .L0804F3AE
.L0804F390:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L0804F3AE
	bl sub_80474D8
	ldr r1, .L0804F3B4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r7, #0
	bl Proc_End
.L0804F3AE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F3B4: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804F3B8
sub_804F3B8: @ 0x0804F3B8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L0804F414 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F418 @ =gUnk_085D1484
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	ldr r0, .L0804F41C @ =gUnk_0813A6F8
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r5, #0x5c]
	ldr r2, .L0804F420 @ =gUnk_0813B8B4
	adds r1, r2, #0
	bl sub_804799C
	bl sub_80474C8
	bl sub_8047500
	ldr r0, .L0804F424 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804F444
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804F428
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0804F432
	.align 2, 0
.L0804F414: .4byte gUnk_Banim_02017744
.L0804F418: .4byte gUnk_085D1484
.L0804F41C: .4byte gUnk_0813A6F8
.L0804F420: .4byte gUnk_0813B8B4
.L0804F424: .4byte 0x0203CD14
.L0804F428:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0804F432:
	ldr r0, .L0804F44C @ =gBg1Tm+0x3C
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #2
	movs r2, #0x14
	movs r3, #1
	bl sub_805B0D4
.L0804F444:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F44C: .4byte gBg1Tm+0x3C

	thumb_func_start sub_804F450
sub_804F450: @ 0x0804F450
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	bne .L0804F478
	bl sub_80474D8
	bl sub_80475D8
	ldr r1, .L0804F480 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804F478:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F480: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804F484
sub_804F484: @ 0x0804F484
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804F4B8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F4BC @ =gUnk_085D149C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804F4C0 @ =gUnk_08119FA6
	str r1, [r0, #0x48]
	ldr r1, .L0804F4C4 @ =gUnk_0813B6B4
	str r1, [r0, #0x4c]
	adds r0, r1, #0
	movs r1, #0x20
	bl sub_8047AF4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F4B8: .4byte gUnk_Banim_02017744
.L0804F4BC: .4byte gUnk_085D149C
.L0804F4C0: .4byte gUnk_08119FA6
.L0804F4C4: .4byte gUnk_0813B6B4

	thumb_func_start sub_804F4C8
sub_804F4C8: @ 0x0804F4C8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0804F4EE
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
	b .L0804F504
.L0804F4EE:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804F504
	ldr r1, .L0804F50C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804F504:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F50C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804F510
sub_804F510: @ 0x0804F510
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804F550 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F554 @ =gUnk_085D14BC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L0804F558 @ =gUnk_085E48C4
	ldr r2, .L0804F55C @ =gUnk_085E3AA4
	str r2, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	bl sub_80478DC
	adds r6, r0, #0
	str r6, [r4, #0x60]
	adds r0, r5, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804F560
	ldrh r0, [r6, #2]
	subs r0, #8
	b .L0804F564
	.align 2, 0
.L0804F550: .4byte gUnk_Banim_02017744
.L0804F554: .4byte gUnk_085D14BC
.L0804F558: .4byte gUnk_085E48C4
.L0804F55C: .4byte gUnk_085E3AA4
.L0804F560:
	ldrh r0, [r6, #2]
	adds r0, #8
.L0804F564:
	strh r0, [r6, #2]
	ldr r0, [r6, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r6, #0x1c]
	ldr r0, .L0804F58C @ =gUnk_0813BD74
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804F590 @ =gUnk_0813BAFC
	movs r1, #0x80
	lsls r1, r1, #4
	bl sub_8047A88
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F58C: .4byte gUnk_0813BD74
.L0804F590: .4byte gUnk_0813BAFC

	thumb_func_start sub_804F594
sub_804F594: @ 0x0804F594
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	ble .L0804F5BA
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804F5C0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804F5BA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F5C0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804F5C4
sub_804F5C4: @ 0x0804F5C4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L0804F5FC @ =gUnk_085D14D4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F5FC: .4byte gUnk_085D14D4

	thumb_func_start sub_804F600
sub_804F600: @ 0x0804F600
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804F636
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L0804F636:
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	adds r0, r6, #1
	cmp r1, r0
	bne .L0804F692
	adds r0, r5, #0
	bl sub_804F738
	adds r0, r5, #0
	bl sub_804F99C
	ldr r3, .L0804F6A8 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	mov r2, r8
	strb r2, [r0]
	adds r0, #1
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	str r1, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x10
	movs r3, #0
	bl sub_804CD88
	movs r0, #0x91
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
.L0804F692:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #0
	adds r0, #0x52
	cmp r1, r0
	bne .L0804F6AC
	ldr r0, [r4, #0x5c]
	movs r1, #4
	bl sub_8046794
	b .L0804F72C
	.align 2, 0
.L0804F6A8: .4byte gDispIo
.L0804F6AC:
	adds r0, r6, #0
	adds r0, #0x55
	cmp r1, r0
	bne .L0804F6E8
	adds r0, r5, #0
	bl sub_804F820
	adds r0, r5, #0
	bl sub_804F908
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #0x10
	movs r3, #0x10
	bl sub_804CD88
	ldr r0, .L0804F6E4 @ =0x00000123
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	b .L0804F72C
	.align 2, 0
.L0804F6E4: .4byte 0x00000123
.L0804F6E8:
	adds r0, r6, #0
	adds r0, #0x58
	cmp r1, r0
	bne .L0804F710
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804F72C
	adds r0, r5, #0
	bl sub_805C358
	b .L0804F72C
.L0804F710:
	adds r0, r6, #0
	adds r0, #0x88
	cmp r1, r0
	beq .L0804F72C
	adds r0, #0x19
	cmp r1, r0
	bne .L0804F72C
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L0804F72C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_804F738
sub_804F738: @ 0x0804F738
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L0804F78C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F790 @ =gUnk_085D14EC
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L0804F794 @ =gUnk_08119FFC
	str r0, [r5, #0x48]
	ldr r0, .L0804F798 @ =gUnk_085D1504
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L0804F79C @ =gUnk_085D151C
	str r0, [r5, #0x54]
	ldr r0, .L0804F7A0 @ =gUnk_081521C0
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L0804F7A4 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804F7B2
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804F7A8
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0804F7B2
	.align 2, 0
.L0804F78C: .4byte gUnk_Banim_02017744
.L0804F790: .4byte gUnk_085D14EC
.L0804F794: .4byte gUnk_08119FFC
.L0804F798: .4byte gUnk_085D1504
.L0804F79C: .4byte gUnk_085D151C
.L0804F7A0: .4byte gUnk_081521C0
.L0804F7A4: .4byte 0x0203CD14
.L0804F7A8:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0804F7B2:
	bl sub_8047500
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_804F7BC
sub_804F7BC: @ 0x0804F7BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L0804F7F8
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	ldr r5, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	lsls r4, r3, #2
	adds r1, r4, r1
	ldr r1, [r1]
	adds r2, r4, r2
	ldr r2, [r2]
	bl sub_804799C
	adds r4, r4, r5
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	b .L0804F816
.L0804F7F8:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne .L0804F816
	bl sub_80474D8
	ldr r1, .L0804F81C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L0804F816:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F81C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804F820
sub_804F820: @ 0x0804F820
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L0804F874 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F878 @ =gUnk_085D1534
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L0804F87C @ =gUnk_0811A06A
	str r0, [r5, #0x48]
	ldr r0, .L0804F880 @ =gUnk_085D154C
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L0804F884 @ =gUnk_085D1578
	str r0, [r5, #0x54]
	ldr r0, .L0804F888 @ =gUnk_0814A498
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L0804F88C @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804F89A
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L0804F890
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0804F89A
	.align 2, 0
.L0804F874: .4byte gUnk_Banim_02017744
.L0804F878: .4byte gUnk_085D1534
.L0804F87C: .4byte gUnk_0811A06A
.L0804F880: .4byte gUnk_085D154C
.L0804F884: .4byte gUnk_085D1578
.L0804F888: .4byte gUnk_0814A498
.L0804F88C: .4byte 0x0203CD14
.L0804F890:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0804F89A:
	bl sub_8047500
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_804F8A4
sub_804F8A4: @ 0x0804F8A4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L0804F8E0
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	ldr r5, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	lsls r4, r3, #2
	adds r1, r4, r1
	ldr r1, [r1]
	adds r2, r4, r2
	ldr r2, [r2]
	bl sub_804799C
	adds r4, r4, r5
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	b .L0804F8FE
.L0804F8E0:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne .L0804F8FE
	bl sub_80474D8
	ldr r1, .L0804F904 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L0804F8FE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F904: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804F908
sub_804F908: @ 0x0804F908
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804F958 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F95C @ =gUnk_085D15A4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L0804F960 @ =gUnk_085E79F8
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldrh r1, [r0, #2]
	adds r1, #0x18
	strh r1, [r0, #2]
	ldr r0, .L0804F964 @ =gUnk_081AC0F4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804F968 @ =gUnk_08152E78
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F958: .4byte gUnk_Banim_02017744
.L0804F95C: .4byte gUnk_085D15A4
.L0804F960: .4byte gUnk_085E79F8
.L0804F964: .4byte gUnk_081AC0F4
.L0804F968: .4byte gUnk_08152E78

	thumb_func_start sub_804F96C
sub_804F96C: @ 0x0804F96C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x33
	ble .L0804F992
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804F998 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804F992:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F998: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804F99C
sub_804F99C: @ 0x0804F99C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804F9D8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F9DC @ =gUnk_085D15BC
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	strh r2, [r0, #0x2e]
	movs r1, #1
	str r1, [r0, #0x44]
	str r2, [r0, #0x48]
	ldr r0, .L0804F9E0 @ =gUnk_081AC0F4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804F9E4 @ =gUnk_08152E78
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F9D8: .4byte gUnk_Banim_02017744
.L0804F9DC: .4byte gUnk_085D15BC
.L0804F9E0: .4byte gUnk_081AC0F4
.L0804F9E4: .4byte gUnk_08152E78

	thumb_func_start sub_804F9E8
sub_804F9E8: @ 0x0804F9E8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
.L0804F9EE:
	ldr r0, [r5, #0x5c]
	adds r1, r4, #0
	bl sub_804FA14
	adds r4, #1
	cmp r4, #0x1f
	ble .L0804F9EE
	ldr r1, .L0804FA10 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FA10: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804FA14
sub_804FA14: @ 0x0804FA14
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	mov r8, r1
	mov r4, sp
	mov r0, sp
	movs r1, #0
	movs r2, #8
	bl memset
	movs r5, #0
	movs r0, #1
	strb r0, [r4, #6]
	strb r0, [r4, #7]
	ldr r1, .L0804FAA4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804FAA8 @ =gUnk_085D15D4
	movs r1, #3
	bl SpawnProc
	adds r7, r0, #0
	str r6, [r7, #0x5c]
	strh r5, [r7, #0x2c]
	movs r0, #0x64
	strh r0, [r7, #0x2e]
	movs r0, #7
	mov r1, r8
	ands r0, r1
	mov r2, sp
	adds r4, r2, r0
	ldrb r0, [r4]
	adds r1, r7, #0
	adds r1, #0x29
	strb r0, [r1]
	ldr r0, .L0804FAAC @ =gUnk_085E7A64
	movs r1, #0x78
	bl BasCreate
	str r0, [r7, #0x60]
	movs r1, #0xa1
	lsls r1, r1, #6
	strh r1, [r0, #8]
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	ldr r5, .L0804FAB0 @ =0x0000FFFF
	adds r0, r5, #0
	bl sub_805B9C8
	strh r0, [r7, #0x32]
	adds r0, r5, #0
	bl sub_805B9C8
	strh r0, [r7, #0x3a]
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804FAB8
	adds r0, r5, #0
	bl sub_805B9C8
	ldr r2, .L0804FAB4 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #0xe0
	lsls r1, r1, #3
	b .L0804FACA
	.align 2, 0
.L0804FAA4: .4byte gUnk_Banim_02017744
.L0804FAA8: .4byte gUnk_085D15D4
.L0804FAAC: .4byte gUnk_085E7A64
.L0804FAB0: .4byte 0x0000FFFF
.L0804FAB4: .4byte 0x000001FF
.L0804FAB8:
	adds r0, r5, #0
	bl sub_805B9C8
	ldr r2, .L0804FB14 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r2, #0
.L0804FACA:
	adds r0, r0, r1
	strh r0, [r7, #0x34]
	ldr r4, .L0804FB18 @ =0x0000FF0F
	adds r0, r4, #0
	bl sub_805B9C8
	ldr r2, .L0804FB1C @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	ldr r1, .L0804FB20 @ =0xFFFFFF00
	adds r0, r0, r1
	strh r0, [r7, #0x3c]
	adds r0, r4, #0
	bl sub_805B9C8
	strh r0, [r7, #0x36]
	adds r0, r4, #0
	bl sub_805B9C8
	strh r0, [r7, #0x3e]
	movs r0, #7
	mov r2, r8
	ands r0, r2
	add r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0804FB24
	adds r0, r4, #0
	bl sub_805B9C8
	ldr r2, .L0804FB14 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #0xe0
	lsls r1, r1, #3
	b .L0804FB36
	.align 2, 0
.L0804FB14: .4byte 0x000001FF
.L0804FB18: .4byte 0x0000FF0F
.L0804FB1C: .4byte 0x000003FF
.L0804FB20: .4byte 0xFFFFFF00
.L0804FB24:
	adds r0, r4, #0
	bl sub_805B9C8
	ldr r2, .L0804FB5C @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r2, #0
.L0804FB36:
	adds r0, r0, r1
	strh r0, [r7, #0x38]
	ldr r0, .L0804FB60 @ =0x0000FF0F
	bl sub_805B9C8
	ldr r2, .L0804FB64 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	ldr r1, .L0804FB68 @ =0xFFFFFF00
	adds r0, r0, r1
	adds r1, r7, #0
	adds r1, #0x40
	strh r0, [r1]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FB5C: .4byte 0x000001FF
.L0804FB60: .4byte 0x0000FF0F
.L0804FB64: .4byte 0x000003FF
.L0804FB68: .4byte 0xFFFFFF00

	thumb_func_start sub_804FB6C
sub_804FB6C: @ 0x0804FB6C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r3, [r4, #0x60]
	ldrh r2, [r4, #0x2c]
	adds r2, #1
	strh r2, [r4, #0x2c]
	lsls r1, r2, #0x10
	ldrh r5, [r4, #0x2e]
	lsls r0, r5, #0x10
	cmp r1, r0
	ble .L0804FB9C
	ldr r1, .L0804FB98 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r3, #0
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
	b .L0804FC1C
	.align 2, 0
.L0804FB98: .4byte gUnk_Banim_02017744
.L0804FB9C:
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	bne .L0804FBE0
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0804FBB8
	ldr r0, .L0804FBB4 @ =gUnk_085E7AC4
	b .L0804FBBA
	.align 2, 0
.L0804FBB4: .4byte gUnk_085E7AC4
.L0804FBB8:
	ldr r0, .L0804FBDC @ =gUnk_085E7ACC
.L0804FBBA:
	str r0, [r3, #0x24]
	str r0, [r3, #0x20]
	movs r0, #0
	strh r0, [r3, #6]
	ldrh r1, [r4, #0x32]
	ldrh r2, [r4, #0x34]
	adds r0, r1, r2
	strh r0, [r4, #0x32]
	ldrh r5, [r4, #0x3a]
	ldrh r2, [r4, #0x3c]
	adds r1, r5, r2
	strh r1, [r4, #0x3a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	strh r0, [r3, #2]
	ldrh r4, [r4, #0x3a]
	b .L0804FC18
	.align 2, 0
.L0804FBDC: .4byte gUnk_085E7ACC
.L0804FBE0:
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0804FBF4
	ldr r0, .L0804FBF0 @ =gUnk_085E7AC4
	b .L0804FBF6
	.align 2, 0
.L0804FBF0: .4byte gUnk_085E7AC4
.L0804FBF4:
	ldr r0, .L0804FC24 @ =gUnk_085E7ACC
.L0804FBF6:
	str r0, [r3, #0x24]
	str r0, [r3, #0x20]
	movs r0, #0
	strh r0, [r3, #6]
	ldrh r5, [r4, #0x3e]
	ldrh r1, [r4, #0x38]
	adds r0, r5, r1
	strh r0, [r4, #0x3e]
	adds r1, r4, #0
	adds r1, #0x40
	ldrh r1, [r1]
	adds r0, r1, r0
	strh r0, [r4, #0x3e]
	ldrh r2, [r4, #0x36]
	lsrs r0, r2, #8
	strh r0, [r3, #2]
	ldrh r4, [r4, #0x3e]
.L0804FC18:
	lsrs r0, r4, #8
	strh r0, [r3, #4]
.L0804FC1C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FC24: .4byte gUnk_085E7ACC

	thumb_func_start sub_804FC28
sub_804FC28: @ 0x0804FC28
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L0804FC60 @ =gUnk_085D15EC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FC60: .4byte gUnk_085D15EC

	thumb_func_start sub_804FC64
sub_804FC64: @ 0x0804FC64
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804FC8E
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L0804FC8E:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #1
	cmp r1, r0
	bne .L0804FCB4
	ldr r0, .L0804FCFC @ =0x00000119
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	adds r0, r5, #0
	bl sub_804FD24
	adds r0, r5, #0
	bl sub_804FE60
.L0804FCB4:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #0
	adds r0, #0x59
	cmp r1, r0
	bne .L0804FCCA
	adds r0, r5, #0
	movs r1, #2
	movs r2, #3
	bl sub_804FF94
.L0804FCCA:
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	adds r0, r6, #0
	adds r0, #0x5e
	cmp r1, r0
	bne .L0804FD00
	adds r0, r5, #0
	bl sub_804FDD4
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804FD1C
	adds r0, r5, #0
	bl sub_805C358
	b .L0804FD1C
	.align 2, 0
.L0804FCFC: .4byte 0x00000119
.L0804FD00:
	adds r0, r6, #0
	adds r0, #0xc3
	cmp r1, r0
	beq .L0804FD1C
	adds r0, #5
	cmp r1, r0
	bne .L0804FD1C
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L0804FD1C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804FD24
sub_804FD24: @ 0x0804FD24
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804FD60 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804FD64 @ =gUnk_085D1604
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804FD68 @ =gUnk_0811A098
	str r1, [r0, #0x48]
	ldr r1, .L0804FD6C @ =gUnk_085D1648
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L0804FD70 @ =gUnk_085D161C
	str r1, [r0, #0x54]
	ldr r0, .L0804FD74 @ =gUnk_0813E75C
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FD60: .4byte gUnk_Banim_02017744
.L0804FD64: .4byte gUnk_085D1604
.L0804FD68: .4byte gUnk_0811A098
.L0804FD6C: .4byte gUnk_085D1648
.L0804FD70: .4byte gUnk_085D161C
.L0804FD74: .4byte gUnk_0813E75C

	thumb_func_start sub_804FD78
sub_804FD78: @ 0x0804FD78
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L0804FDB4
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl sub_804799C
	b .L0804FDCA
.L0804FDB4:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L0804FDCA
	ldr r1, .L0804FDD0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r7, #0
	bl Proc_End
.L0804FDCA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FDD0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804FDD4
sub_804FDD4: @ 0x0804FDD4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804FDF0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804FDF4 @ =gUnk_085D1674
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FDF0: .4byte gUnk_Banim_02017744
.L0804FDF4: .4byte gUnk_085D1674

	thumb_func_start sub_804FDF8
sub_804FDF8: @ 0x0804FDF8
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	ldr r3, .L0804FE30 @ =gUnk_085E5858
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r0, .L0804FE34 @ =gUnk_0812D80C
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0804FE38 @ =gUnk_0812D374
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FE30: .4byte gUnk_085E5858
.L0804FE34: .4byte gUnk_0812D80C
.L0804FE38: .4byte gUnk_0812D374

	thumb_func_start sub_804FE3C
sub_804FE3C: @ 0x0804FE3C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804FE5C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FE5C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804FE60
sub_804FE60: @ 0x0804FE60
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804FE7C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804FE80 @ =gUnk_085D169C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FE7C: .4byte gUnk_Banim_02017744
.L0804FE80: .4byte gUnk_085D169C

	thumb_func_start sub_804FE84
sub_804FE84: @ 0x0804FE84
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x8d
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl sub_805C804
	ldr r0, [r4, #0x5c]
	movs r1, #0x26
	bl sub_8046794
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #5
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_804FEB8
sub_804FEB8: @ 0x0804FEB8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0804FF14 @ =gPal
	ldr r4, .L0804FF18 @ =gUnk_Banim_020165C0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r4, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	adds r3, r5, #0
	bl sub_805B644
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r6, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0804FF0C
	movs r0, #0
	strh r0, [r6, #0x2c]
	movs r0, #0xa
	strh r0, [r6, #0x2e]
	adds r0, r6, #0
	bl Proc_Break
.L0804FF0C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FF14: .4byte gPal
.L0804FF18: .4byte gUnk_Banim_020165C0

	thumb_func_start sub_804FF1C
sub_804FF1C: @ 0x0804FF1C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	ldr r2, .L0804FF8C @ =gDispIo
	mov ip, r2
	mov r3, ip
	adds r3, #0x3c
	movs r1, #0x3f
	ldrb r2, [r3]
	ands r1, r2
	movs r2, #0x40
	orrs r1, r2
	strb r1, [r3]
	mov r1, ip
	adds r1, #0x44
	movs r2, #0
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x10
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x46
	strb r2, [r0]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0804FF84
	bl sub_80474D8
	bl sub_80475D8
	ldr r1, .L0804FF90 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804FF84:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FF8C: .4byte gDispIo
.L0804FF90: .4byte gUnk_Banim_02017744

	thumb_func_start sub_804FF94
sub_804FF94: @ 0x0804FF94
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r1, .L0804FFC8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804FFCC @ =gPal
	ldr r1, .L0804FFD0 @ =gUnk_Banim_020165C0
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuFastSet
	ldr r0, .L0804FFD4 @ =gUnk_085D16DC
	movs r1, #0
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r6, [r0, #0x30]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FFC8: .4byte gUnk_Banim_02017744
.L0804FFCC: .4byte gPal
.L0804FFD0: .4byte gUnk_Banim_020165C0
.L0804FFD4: .4byte gUnk_085D16DC

	thumb_func_start sub_804FFD8
sub_804FFD8: @ 0x0804FFD8
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r3, r0, #0
	ldr r4, .L08050034 @ =gUnk_Banim_020165C0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	bl sub_805B5C8
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r4, #0
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805002C
	movs r0, #0
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L0805002C:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08050034: .4byte gUnk_Banim_020165C0

	thumb_func_start sub_8050038
sub_8050038: @ 0x08050038
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08050074 @ =gUnk_Banim_020165C0
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805006C
	ldr r1, .L08050078 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0805006C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08050074: .4byte gUnk_Banim_020165C0
.L08050078: .4byte gUnk_Banim_02017744

	thumb_func_start sub_805007C
sub_805007C: @ 0x0805007C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L080500B4 @ =gUnk_085D16FC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080500B4: .4byte gUnk_085D16FC

	thumb_func_start sub_80500B8
sub_80500B8: @ 0x080500B8
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r2, r0, #0
	ldr r0, .L08050110 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #0x3a
	cmp r0, #0
	beq .L080500DA
	movs r3, #0x32
.L080500DA:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08050114
	ldr r0, [r4, #0x5c]
	bl sub_8050308
	movs r0, #0x84
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl sub_805C804
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	b .L080501B0
	.align 2, 0
.L08050110: .4byte 0x0203CD14
.L08050114:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r3, r2
	cmp r1, r0
	bne .L08050128
	ldr r0, [r4, #0x5c]
	movs r1, #6
	bl sub_8046794
	b .L080501B0
.L08050128:
	adds r0, r2, #6
	adds r0, r3, r0
	cmp r1, r0
	bne .L08050164
	adds r0, r5, #0
	bl sub_80501B8
	adds r0, r5, #0
	bl sub_805027C
	str r6, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	movs r1, #6
	movs r2, #5
	movs r3, #0x10
	bl sub_804CD88
	ldr r0, .L08050160 @ =0x00000109
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	b .L080501B0
	.align 2, 0
.L08050160: .4byte 0x00000109
.L08050164:
	adds r0, r2, #0
	adds r0, #8
	adds r0, r3, r0
	cmp r1, r0
	bne .L0805018E
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L080501B0
	adds r0, r5, #0
	bl sub_805C358
	b .L080501B0
.L0805018E:
	adds r0, r2, #0
	adds r0, #0xc
	adds r0, r3, r0
	cmp r1, r0
	beq .L080501B0
	adds r0, r2, #0
	adds r0, #0xe
	adds r0, r3, r0
	cmp r1, r0
	bne .L080501B0
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L080501B0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_80501B8
sub_80501B8: @ 0x080501B8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, .L08050204 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050208 @ =gUnk_085D1714
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	ldr r0, .L0805020C @ =gUnk_0811A0DE
	str r0, [r4, #0x48]
	ldr r0, .L08050210 @ =gUnk_085D172C
	str r0, [r4, #0x4c]
	ldr r0, .L08050214 @ =gUnk_08159D98
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	bl sub_8047500
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08050218
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08050222
	.align 2, 0
.L08050204: .4byte gUnk_Banim_02017744
.L08050208: .4byte gUnk_085D1714
.L0805020C: .4byte gUnk_0811A0DE
.L08050210: .4byte gUnk_085D172C
.L08050214: .4byte gUnk_08159D98
.L08050218:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08050222:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8050228
sub_8050228: @ 0x08050228
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L08050254
	ldr r2, [r4, #0x4c]
	ldr r0, [r4, #0x5c]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #0x20
	movs r3, #0x14
	bl sub_8047A1C
	b .L08050272
.L08050254:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08050272
	bl sub_80474D8
	ldr r1, .L08050278 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L08050272:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08050278: .4byte gUnk_Banim_02017744

	thumb_func_start sub_805027C
sub_805027C: @ 0x0805027C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080502B0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080502B4 @ =gUnk_085D1734
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	str r1, [r0, #0x44]
	ldr r1, .L080502B8 @ =gUnk_0811A0E8
	str r1, [r0, #0x48]
	ldr r1, .L080502BC @ =gUnk_0815B364
	str r1, [r0, #0x4c]
	adds r0, r1, #0
	movs r1, #0x20
	bl sub_8047AF4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080502B0: .4byte gUnk_Banim_02017744
.L080502B4: .4byte gUnk_085D1734
.L080502B8: .4byte gUnk_0811A0E8
.L080502BC: .4byte gUnk_0815B364

	thumb_func_start sub_80502C0
sub_80502C0: @ 0x080502C0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L080502E6
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
	b .L080502FC
.L080502E6:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080502FC
	ldr r1, .L08050304 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080502FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08050304: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8050308
sub_8050308: @ 0x08050308
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L0805034C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050350 @ =gUnk_085D1754
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	ldr r1, .L08050354 @ =gUnk_085EA7F0
	ldr r2, .L08050358 @ =gUnk_085E90AC
	ldr r3, .L0805035C @ =gUnk_085EA8A4
	ldr r0, .L08050360 @ =gUnk_085E9160
	str r0, [sp]
	adds r0, r4, #0
	bl sub_80478DC
	adds r5, r0, #0
	str r5, [r6, #0x60]
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08050364
	ldrh r0, [r5, #2]
	adds r0, #0x48
	b .L08050368
	.align 2, 0
.L0805034C: .4byte gUnk_Banim_02017744
.L08050350: .4byte gUnk_085D1754
.L08050354: .4byte gUnk_085EA7F0
.L08050358: .4byte gUnk_085E90AC
.L0805035C: .4byte gUnk_085EA8A4
.L08050360: .4byte gUnk_085E9160
.L08050364:
	ldrh r0, [r5, #2]
	subs r0, #0x48
.L08050368:
	strh r0, [r5, #2]
	movs r0, #0x60
	strh r0, [r6, #0x2e]
	ldr r0, .L08050388 @ =gUnk_0815BED4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0805038C @ =gUnk_0815B910
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08050388: .4byte gUnk_0815BED4
.L0805038C: .4byte gUnk_0815B910

	thumb_func_start sub_8050390
sub_8050390: @ 0x08050390
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r2, #0x2e]
	lsls r1, r3, #0x10
	cmp r0, r1
	bne .L080503B2
	ldr r1, .L080503B8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r2, #0
	bl Proc_Break
.L080503B2:
	pop {r0}
	bx r0
	.align 2, 0
.L080503B8: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80503BC
sub_80503BC: @ 0x080503BC
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L080503F4 @ =gUnk_085D176C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080503F4: .4byte gUnk_085D176C

	thumb_func_start sub_80503F8
sub_80503F8: @ 0x080503F8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r2, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08050434
	movs r0, #0x85
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl sub_805C804
	adds r0, r5, #0
	bl sub_80504F0
	b .L080504E8
.L08050434:
	cmp r0, #0x18
	bne .L08050440
	ldr r0, [r4, #0x5c]
	bl sub_80506B4
	b .L080504E8
.L08050440:
	cmp r0, #0x82
	bne .L08050450
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	b .L080504E8
.L08050450:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r2, #0
	adds r0, #0x83
	cmp r1, r0
	bne .L08050466
	adds r0, r5, #0
	bl sub_80506F8
	str r0, [r4, #0x64]
	b .L080504E8
.L08050466:
	adds r0, r2, #0
	adds r0, #0x96
	cmp r1, r0
	bne .L0805048C
	ldr r0, .L08050488 @ =0x0000010B
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	ldr r0, [r4, #0x5c]
	bl sub_80505A0
	b .L080504E8
	.align 2, 0
.L08050488: .4byte 0x0000010B
.L0805048C:
	adds r0, r2, #0
	adds r0, #0xaa
	cmp r1, r0
	bne .L0805049C
	ldr r0, [r4, #0x64]
	bl Proc_End
	b .L080504E8
.L0805049C:
	adds r0, r2, #0
	adds r0, #0xc3
	cmp r1, r0
	bne .L080504CC
	ldr r0, [r4, #0x5c]
	movs r1, #6
	bl sub_8046794
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L080504E8
	adds r0, r5, #0
	bl sub_805C358
	b .L080504E8
.L080504CC:
	adds r0, r2, #0
	adds r0, #0xe6
	cmp r1, r0
	beq .L080504E8
	adds r0, #0xa
	cmp r1, r0
	bne .L080504E8
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L080504E8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80504F0
sub_80504F0: @ 0x080504F0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08050548 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805054C @ =gUnk_085D1784
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08050550 @ =gUnk_0811A102
	str r0, [r5, #0x48]
	ldr r0, .L08050554 @ =gUnk_085D179C
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08050558 @ =gUnk_085D1840
	str r0, [r5, #0x54]
	ldr r0, .L0805055C @ =gUnk_0815F880
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	ldr r0, .L08050560 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0805056E
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08050564
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
	b .L0805056E
	.align 2, 0
.L08050548: .4byte gUnk_Banim_02017744
.L0805054C: .4byte gUnk_085D1784
.L08050550: .4byte gUnk_0811A102
.L08050554: .4byte gUnk_085D179C
.L08050558: .4byte gUnk_085D1840
.L0805055C: .4byte gUnk_0815F880
.L08050560: .4byte 0x0203CD14
.L08050564:
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
.L0805056E:
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08050584
	ldr r0, .L08050580 @ =gDispIo
	ldrh r1, [r0, #0x20]
	adds r1, #4
	b .L0805058A
	.align 2, 0
.L08050580: .4byte gDispIo
.L08050584:
	ldr r0, .L0805059C @ =gDispIo
	ldrh r1, [r0, #0x20]
	subs r1, #4
.L0805058A:
	strh r1, [r0, #0x20]
	adds r1, r0, #0
	ldrh r0, [r1, #0x22]
	adds r0, #8
	strh r0, [r1, #0x22]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805059C: .4byte gDispIo

	thumb_func_start sub_80505A0
sub_80505A0: @ 0x080505A0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08050620 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050624 @ =gUnk_085D1784
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r4, #0
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08050628 @ =gUnk_0811A134
	str r0, [r5, #0x48]
	ldr r0, .L0805062C @ =gUnk_085D179C
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08050630 @ =gUnk_085D1840
	str r0, [r5, #0x54]
	ldr r0, .L08050634 @ =gUnk_0815F8A0
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	ldr r3, .L08050638 @ =gDispIo
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
	adds r1, #1
	movs r0, #7
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r4, [r0]
	ldr r0, .L0805063C @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0805064A
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08050640
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
	b .L0805064A
	.align 2, 0
.L08050620: .4byte gUnk_Banim_02017744
.L08050624: .4byte gUnk_085D1784
.L08050628: .4byte gUnk_0811A134
.L0805062C: .4byte gUnk_085D179C
.L08050630: .4byte gUnk_085D1840
.L08050634: .4byte gUnk_0815F8A0
.L08050638: .4byte gDispIo
.L0805063C: .4byte 0x0203CD14
.L08050640:
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
.L0805064A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8050650
sub_8050650: @ 0x08050650
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L0805068C
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl sub_804799C
	b .L080506AA
.L0805068C:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L080506AA
	bl sub_80474D8
	ldr r1, .L080506B0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r7, #0
	bl Proc_End
.L080506AA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080506B0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80506B4
sub_80506B4: @ 0x080506B4
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L080506EC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080506F0 @ =gUnk_085D18E4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	adds r0, r5, #0
	bl sub_804B80C
	ldr r3, .L080506F4 @ =gUnk_085D0E8C
	ldr r0, [r4, #0x5c]
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080506EC: .4byte gUnk_Banim_02017744
.L080506F0: .4byte gUnk_085D18E4
.L080506F4: .4byte gUnk_085D0E8C

	thumb_func_start sub_80506F8
sub_80506F8: @ 0x080506F8
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08050738 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805073C @ =gUnk_085D192C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	adds r0, r5, #0
	bl sub_804B80C
	ldr r3, .L08050740 @ =gUnk_085D0E8C
	ldr r0, [r4, #0x5c]
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldrh r1, [r0, #4]
	subs r1, #4
	strh r1, [r0, #4]
	adds r0, r4, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08050738: .4byte gUnk_Banim_02017744
.L0805073C: .4byte gUnk_085D192C
.L08050740: .4byte gUnk_085D0E8C

	thumb_func_start sub_8050744
sub_8050744: @ 0x08050744
	push {lr}
	ldr r2, .L08050758 @ =gUnk_Banim_02017744
	ldr r1, [r2]
	subs r1, #1
	str r1, [r2]
	ldr r0, [r0, #0x60]
	bl BasRemove
	pop {r0}
	bx r0
	.align 2, 0
.L08050758: .4byte gUnk_Banim_02017744

	thumb_func_start sub_805075C
sub_805075C: @ 0x0805075C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L0805078C @ =gUnk_085EABC0
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08050790 @ =gUnk_081629D4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08050794 @ =gUnk_08161DDC
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805078C: .4byte gUnk_085EABC0
.L08050790: .4byte gUnk_081629D4
.L08050794: .4byte gUnk_08161DDC

	thumb_func_start sub_8050798
sub_8050798: @ 0x08050798
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L080507C8 @ =gUnk_085EADB0
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L080507CC @ =gUnk_081629D4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L080507D0 @ =gUnk_081621DC
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080507C8: .4byte gUnk_085EADB0
.L080507CC: .4byte gUnk_081629D4
.L080507D0: .4byte gUnk_081621DC

	thumb_func_start sub_80507D4
sub_80507D4: @ 0x080507D4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08050804 @ =gUnk_085EB264
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08050808 @ =gUnk_081629D4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0805080C @ =gUnk_0816261C
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08050804: .4byte gUnk_085EB264
.L08050808: .4byte gUnk_081629D4
.L0805080C: .4byte gUnk_0816261C

	thumb_func_start sub_8050810
sub_8050810: @ 0x08050810
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08050838 @ =gUnk_085EB1A8
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	movs r0, #0x14
	strh r0, [r1, #0xa]
	bl BasSort
	movs r0, #0x27
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08050838: .4byte gUnk_085EB1A8

	thumb_func_start sub_805083C
sub_805083C: @ 0x0805083C
	adds r1, r0, #0
	ldr r2, [r1, #0x60]
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	movs r3, #0
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	bne .L0805085A
	ldr r0, .L0805085C @ =gUnk_085EB1DC
	str r0, [r2, #0x24]
	str r0, [r2, #0x20]
	strh r3, [r2, #6]
	strh r3, [r1, #0x2c]
.L0805085A:
	bx lr
	.align 2, 0
.L0805085C: .4byte gUnk_085EB1DC

	thumb_func_start sub_8050860
sub_8050860: @ 0x08050860
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L08050898 @ =gUnk_085D195C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08050898: .4byte gUnk_085D195C

	thumb_func_start sub_805089C
sub_805089C: @ 0x0805089C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r6, r0, #0
	bl sub_8047C28
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080508D2
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L080508D2:
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	adds r0, r5, #1
	cmp r1, r0
	bne .L08050930
	ldr r3, .L0805092C @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	mov r2, r8
	strb r2, [r0]
	adds r0, #1
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	str r1, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0xa
	movs r3, #0
	bl sub_804CD88
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x28
	movs r2, #0x28
	movs r3, #0x10
	bl sub_804CD88
	adds r0, r6, #0
	bl sub_8050A70
	movs r0, #0x92
	lsls r0, r0, #1
	b .L08050982
	.align 2, 0
.L0805092C: .4byte gDispIo
.L08050930:
	adds r0, r5, #0
	adds r0, #0xf
	cmp r1, r0
	bne .L0805096C
	movs r0, #2
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #0x52
	movs r2, #0xf
	movs r3, #0
	bl sub_804C8D4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x3c
	bl sub_8050D68
	ldr r0, .L08050964 @ =gDispIo
	movs r1, #0x20
	ldrsh r2, [r0, r1]
	ldr r3, .L08050968 @ =sub_804CD4C
	adds r0, r6, #0
	movs r1, #0x53
	bl sub_804CB8C
	b .L080509D8
	.align 2, 0
.L08050964: .4byte gDispIo
.L08050968: .4byte sub_804CD4C
.L0805096C:
	adds r0, r5, #0
	adds r0, #0x64
	cmp r1, r0
	bne .L08050998
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r1, [r0]
	adds r0, r6, #0
	bl sub_80509E4
	ldr r0, .L08050994 @ =0x00000125
.L08050982:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r6, r3]
	movs r3, #1
	bl sub_805C804
	b .L080509D8
	.align 2, 0
.L08050994: .4byte 0x00000125
.L08050998:
	adds r0, r5, #0
	adds r0, #0x69
	cmp r1, r0
	bne .L080509C0
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r6, #0
	bl sub_80477AC
	ldrb r0, [r4]
	cmp r0, #0
	bne .L080509D8
	adds r0, r6, #0
	bl sub_805C358
	b .L080509D8
.L080509C0:
	adds r0, r5, #0
	adds r0, #0x96
	cmp r1, r0
	beq .L080509D8
	adds r0, #0x14
	cmp r1, r0
	bne .L080509D8
	bl sub_80474BC
	adds r0, r4, #0
	bl Proc_Break
.L080509D8:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_80509E4
sub_80509E4: @ 0x080509E4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08050A44 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050A48 @ =gUnk_085D1974
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x5c]
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #0
	strb r5, [r1]
	strh r0, [r6, #0x2c]
	str r0, [r6, #0x44]
	ldr r0, .L08050A4C @ =gUnk_0811A1AA
	str r0, [r6, #0x48]
	ldr r0, .L08050A50 @ =gUnk_085D1A88
	str r0, [r6, #0x4c]
	str r0, [r6, #0x50]
	ldr r0, .L08050A54 @ =gUnk_085D19BC
	str r0, [r6, #0x54]
	ldr r0, .L08050A58 @ =gUnk_0816B328
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	ldr r0, .L08050A5C @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08050A6A
	ldr r0, [r6, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08050A60
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08050A6A
	.align 2, 0
.L08050A44: .4byte gUnk_Banim_02017744
.L08050A48: .4byte gUnk_085D1974
.L08050A4C: .4byte gUnk_0811A1AA
.L08050A50: .4byte gUnk_085D1A88
.L08050A54: .4byte gUnk_085D19BC
.L08050A58: .4byte gUnk_0816B328
.L08050A5C: .4byte 0x0203CD14
.L08050A60:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08050A6A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_8050A70
sub_8050A70: @ 0x08050A70
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08050AE0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050AE4 @ =gUnk_085D19A4
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08050AE8 @ =gUnk_0811A276
	str r0, [r5, #0x48]
	ldr r0, .L08050AEC @ =gUnk_085D1A88
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08050AF0 @ =gUnk_085D19BC
	str r0, [r5, #0x54]
	ldr r0, .L08050AF4 @ =gUnk_0816B328
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	ldr r2, .L08050AF8 @ =gDispIo
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
	ldr r0, .L08050AFC @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08050B0A
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08050B00
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08050B0A
	.align 2, 0
.L08050AE0: .4byte gUnk_Banim_02017744
.L08050AE4: .4byte gUnk_085D19A4
.L08050AE8: .4byte gUnk_0811A276
.L08050AEC: .4byte gUnk_085D1A88
.L08050AF0: .4byte gUnk_085D19BC
.L08050AF4: .4byte gUnk_0816B328
.L08050AF8: .4byte gDispIo
.L08050AFC: .4byte 0x0203CD14
.L08050B00:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08050B0A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8050B10
sub_8050B10: @ 0x08050B10
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08050B4C
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl sub_804799C
	b .L08050B8E
.L08050B4C:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08050B8E
	bl sub_80474D8
	adds r0, r7, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08050B80
	ldr r1, .L08050B7C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	bl sub_8047358
	adds r0, r7, #0
	bl Proc_End
	b .L08050B8E
	.align 2, 0
.L08050B7C: .4byte gUnk_Banim_02017744
.L08050B80:
	movs r0, #0
	strh r0, [r7, #0x2c]
	movs r0, #0x1e
	strh r0, [r7, #0x2e]
	adds r0, r7, #0
	bl Proc_Break
.L08050B8E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_8050B94
sub_8050B94: @ 0x08050B94
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, .L08050BB8 @ =gUnk_Banim_02017748
	ldr r0, [r5]
	cmp r0, #2
	bne .L08050BC0
	ldr r1, .L08050BBC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_End
	b .L08050C1A
	.align 2, 0
.L08050BB8: .4byte gUnk_Banim_02017748
.L08050BBC: .4byte gUnk_Banim_02017744
.L08050BC0:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r3, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x2e
	ldrsh r2, [r4, r1]
	ldrh r1, [r4, #0x2e]
	cmp r0, r2
	ble .L08050BD8
	strh r1, [r4, #0x2c]
.L08050BD8:
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, r2
	bne .L08050C1A
	ldr r0, [r5]
	cmp r0, #1
	bne .L08050C1A
	strh r3, [r4, #0x2c]
	strh r3, [r4, #0x2e]
	str r3, [r4, #0x44]
	ldr r0, .L08050C20 @ =gUnk_0811A218
	str r0, [r4, #0x48]
	ldr r0, .L08050C24 @ =gUnk_085D1A88
	str r0, [r4, #0x4c]
	str r0, [r4, #0x50]
	ldr r0, .L08050C28 @ =gUnk_085D19BC
	str r0, [r4, #0x54]
	ldr r0, .L08050C2C @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08050C14
	bl sub_8047C28
	strh r0, [r4, #0x2e]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L08050C14:
	adds r0, r4, #0
	bl Proc_Break
.L08050C1A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08050C20: .4byte gUnk_0811A218
.L08050C24: .4byte gUnk_085D1A88
.L08050C28: .4byte gUnk_085D19BC
.L08050C2C: .4byte 0x0203CD14

	thumb_func_start sub_8050C30
sub_8050C30: @ 0x08050C30
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08050C96
	ldr r0, .L08050C6C @ =0x0203CD14
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq .L08050C7A
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08050C70
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
	b .L08050C7A
	.align 2, 0
.L08050C6C: .4byte 0x0203CD14
.L08050C70:
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
.L08050C7A:
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x93
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	adds r0, r4, #0
	bl Proc_Break
.L08050C96:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8050C9C
sub_8050C9C: @ 0x08050C9C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08050CD8
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl sub_804799C
	b .L08050CFA
.L08050CD8:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08050CFA
	bl sub_80474D8
	ldr r1, .L08050D00 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	bl sub_8047358
	adds r0, r7, #0
	bl Proc_Break
.L08050CFA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08050D00: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8050D04
sub_8050D04: @ 0x08050D04
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08050D40
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl sub_804799C
	b .L08050D5E
.L08050D40:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08050D5E
	bl sub_80474D8
	ldr r1, .L08050D64 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r7, #0
	bl Proc_Break
.L08050D5E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08050D64: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8050D68
sub_8050D68: @ 0x08050D68
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	ldr r1, .L08050D90 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050D94 @ =gUnk_085D1B54
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	str r6, [r0, #0x64]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08050D90: .4byte gUnk_Banim_02017744
.L08050D94: .4byte gUnk_085D1B54

	thumb_func_start sub_8050D98
sub_8050D98: @ 0x08050D98
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, [r5, #0x64]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #4
	movs r1, #0
	movs r2, #0x80
	bl Interpolate
	str r0, [r4, #0x4c]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08050DD4
	ldr r1, .L08050DDC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L08050DD4:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08050DDC: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8050DE0
sub_8050DE0: @ 0x08050DE0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L08050E18 @ =gUnk_085D1B6C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08050E18: .4byte gUnk_085D1B6C

	thumb_func_start sub_8050E1C
sub_8050E1C: @ 0x08050E1C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08050E46
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L08050E46:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #1
	cmp r1, r0
	bne .L08050E6A
	movs r0, #0x90
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	adds r0, r5, #0
	bl sub_8050ED4
	b .L08050ECC
.L08050E6A:
	adds r0, r6, #0
	adds r0, #0x1a
	cmp r1, r0
	bne .L08050EB0
	ldr r0, .L08050EAC @ =0x00000121
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	ldr r0, [r4, #0x5c]
	movs r1, #4
	bl sub_8046794
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08050ECC
	adds r0, r5, #0
	bl sub_805C358
	b .L08050ECC
	.align 2, 0
.L08050EAC: .4byte 0x00000121
.L08050EB0:
	adds r0, r6, #0
	adds r0, #0x2f
	cmp r1, r0
	beq .L08050ECC
	adds r0, #1
	cmp r1, r0
	bne .L08050ECC
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L08050ECC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8050ED4
sub_8050ED4: @ 0x08050ED4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08050F28 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050F2C @ =gUnk_085D1B84
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08050F30 @ =gUnk_0811A27C
	str r0, [r5, #0x48]
	ldr r0, .L08050F34 @ =gUnk_085D1CA4
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08050F38 @ =gUnk_085D1B9C
	str r0, [r5, #0x54]
	ldr r0, .L08050F3C @ =gUnk_085D1C20
	str r0, [r5, #0x58]
	bl sub_8047500
	ldr r0, .L08050F40 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08050F4E
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08050F44
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08050F4E
	.align 2, 0
.L08050F28: .4byte gUnk_Banim_02017744
.L08050F2C: .4byte gUnk_085D1B84
.L08050F30: .4byte gUnk_0811A27C
.L08050F34: .4byte gUnk_085D1CA4
.L08050F38: .4byte gUnk_085D1B9C
.L08050F3C: .4byte gUnk_085D1C20
.L08050F40: .4byte 0x0203CD14
.L08050F44:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08050F4E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8050F54
sub_8050F54: @ 0x08050F54
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	blt .L08050FDC
	ldr r6, [r7, #0x4c]
	ldr r0, [r7, #0x50]
	mov r8, r0
	ldr r0, [r7, #0x54]
	ldr r4, [r7, #0x58]
	lsls r5, r5, #2
	adds r0, r5, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	adds r4, r5, r4
	ldr r0, [r4]
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, [r7, #0x5c]
	adds r6, r5, r6
	ldr r1, [r6]
	add r5, r8
	ldr r2, [r5]
	bl sub_804799C
	ldr r0, .L08050FBC @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08050FFA
	ldr r0, [r7, #0x5c]
	bl sub_804B6C4
	adds r1, r0, #0
	cmp r1, #0
	bne .L08050FC4
	ldr r0, .L08050FC0 @ =gBg1Tm
	b .L08050FC8
	.align 2, 0
.L08050FBC: .4byte 0x0203CD14
.L08050FC0: .4byte gBg1Tm
.L08050FC4:
	ldr r0, .L08050FD8 @ =gBg1Tm+0x3A
	movs r1, #0
.L08050FC8:
	str r1, [sp]
	movs r1, #3
	movs r2, #0x14
	movs r3, #0
	bl sub_805B094
	b .L08050FFA
	.align 2, 0
.L08050FD8: .4byte gBg1Tm+0x3A
.L08050FDC:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L08050FFA
	bl sub_80474D8
	ldr r1, .L08051008 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r7, #0
	bl Proc_End
.L08050FFA:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08051008: .4byte gUnk_Banim_02017744

	thumb_func_start sub_805100C
sub_805100C: @ 0x0805100C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L08051048 @ =gUnk_085D1D28
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r6, #0
	strh r6, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	ldr r0, .L0805104C @ =gUnk_Banim_0201E7A8
	str r6, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08051048: .4byte gUnk_085D1D28
.L0805104C: .4byte gUnk_Banim_0201E7A8

	thumb_func_start sub_8051050
sub_8051050: @ 0x08051050
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, .L0805106C @ =gUnk_Banim_0201E7A8
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L08051070
	adds r1, #0xff
	movs r0, #0xfe
	bl sub_805C804
	b .L0805107A
	.align 2, 0
.L0805106C: .4byte gUnk_Banim_0201E7A8
.L08051070:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xff
	bl sub_805C804
.L0805107A:
	ldr r1, .L08051088 @ =gUnk_Banim_0201E7A8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
.L08051088: .4byte gUnk_Banim_0201E7A8

	thumb_func_start sub_805108C
sub_805108C: @ 0x0805108C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r4, r0, #0
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080510BA
	ldr r0, [r6, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L080510BA:
	movs r0, #0x2c
	ldrsh r1, [r6, r0]
	adds r0, r4, #1
	cmp r1, r0
	bne .L080510DC
	adds r0, r5, #0
	movs r1, #4
	bl sub_8046794
	adds r0, r5, #0
	bl sub_80511BC
	adds r0, r5, #0
	bl sub_8051288
	movs r0, #0x30
	b .L08051102
.L080510DC:
	adds r0, r4, #0
	adds r0, #0x15
	cmp r1, r0
	bne .L080510F0
	adds r0, r5, #0
	movs r1, #4
	bl sub_8046794
	movs r0, #0xa0
	b .L08051102
.L080510F0:
	adds r0, r4, #0
	adds r0, #0x29
	cmp r1, r0
	bne .L0805110A
	adds r0, r5, #0
	movs r1, #4
	bl sub_8046794
	movs r0, #0x70
.L08051102:
	movs r1, #0
	bl sub_8051050
	b .L080511B4
.L0805110A:
	adds r0, r4, #0
	adds r0, #0x3d
	cmp r1, r0
	bne .L0805113E
	adds r0, r5, #0
	movs r1, #4
	bl sub_8046794
	movs r0, #0x10
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0xa
	movs r3, #0
	bl sub_804CD88
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	adds r0, r1, #0
	movs r3, #1
	bl sub_805C804
	b .L080511B4
.L0805113E:
	adds r0, r4, #0
	adds r0, #0x5e
	cmp r1, r0
	bne .L08051184
	adds r0, r5, #0
	movs r1, #4
	bl sub_8046794
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, r6, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldr r0, .L08051180 @ =0x00000101
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	ldrb r0, [r4]
	cmp r0, #0
	bne .L080511B4
	adds r0, r5, #0
	bl sub_805C358
	b .L080511B4
	.align 2, 0
.L08051180: .4byte 0x00000101
.L08051184:
	adds r0, r4, #0
	adds r0, #0x69
	cmp r1, r0
	bne .L0805119E
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x14
	movs r3, #8
	bl sub_804CD88
	b .L080511B4
.L0805119E:
	adds r0, r4, #0
	adds r0, #0x71
	cmp r1, r0
	bne .L080511B4
	bl sub_80474BC
	bl sub_8047358
	adds r0, r6, #0
	bl Proc_Break
.L080511B4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_80511BC
sub_80511BC: @ 0x080511BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080511F4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080511F8 @ =gUnk_085D1D40
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L080511FC @ =gUnk_0811A302
	str r1, [r0, #0x48]
	ldr r1, .L08051200 @ =gUnk_085D1FC8
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L08051204 @ =gUnk_085D1D58
	str r1, [r0, #0x54]
	ldr r1, .L08051208 @ =gUnk_085D1E90
	str r1, [r0, #0x58]
	bl sub_8047500
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080511F4: .4byte gUnk_Banim_02017744
.L080511F8: .4byte gUnk_085D1D40
.L080511FC: .4byte gUnk_0811A302
.L08051200: .4byte gUnk_085D1FC8
.L08051204: .4byte gUnk_085D1D58
.L08051208: .4byte gUnk_085D1E90

	thumb_func_start sub_805120C
sub_805120C: @ 0x0805120C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	blt .L0805125A
	ldr r6, [r7, #0x4c]
	ldr r0, [r7, #0x50]
	mov r8, r0
	ldr r0, [r7, #0x54]
	ldr r4, [r7, #0x58]
	lsls r5, r5, #2
	adds r0, r5, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	adds r4, r5, r4
	ldr r0, [r4]
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, [r7, #0x5c]
	adds r6, r5, r6
	ldr r1, [r6]
	add r5, r8
	ldr r2, [r5]
	bl sub_804799C
	b .L08051278
.L0805125A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L08051278
	bl sub_80474D8
	ldr r1, .L08051284 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r7, #0
	bl Proc_End
.L08051278:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08051284: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8051288
sub_8051288: @ 0x08051288
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080512B4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080512B8 @ =gUnk_085D2100
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	movs r1, #7
	str r1, [r0, #0x44]
	strh r2, [r0, #0x2e]
	movs r1, #6
	str r1, [r0, #0x48]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080512B4: .4byte gUnk_Banim_02017744
.L080512B8: .4byte gUnk_085D2100

	thumb_func_start sub_80512BC
sub_80512BC: @ 0x080512BC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x44]
	cmp r0, r1
	ble .L08051318
	movs r0, #0
	strh r0, [r5, #0x2c]
	ldr r2, .L08051320 @ =gUnk_085D2120
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	lsls r1, r0, #3
	adds r1, r1, r2
	ldr r4, [r1]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r0, [r5, #0x60]
	adds r1, r4, #0
	bl sub_8051328
	adds r0, r4, #0
	movs r1, #1
	bl sub_8051050
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x48]
	cmp r0, r1
	ble .L08051318
	ldr r1, .L08051324 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L08051318:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08051320: .4byte gUnk_085D2120
.L08051324: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8051328
sub_8051328: @ 0x08051328
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r1, .L08051380 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051384 @ =gUnk_085D2158
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L08051388 @ =gUnk_085EDCC8
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	strh r6, [r0, #2]
	mov r1, r8
	strh r1, [r0, #4]
	ldr r0, .L0805138C @ =gUnk_081AB190
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08051390 @ =gUnk_081AAECC
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08051380: .4byte gUnk_Banim_02017744
.L08051384: .4byte gUnk_085D2158
.L08051388: .4byte gUnk_085EDCC8
.L0805138C: .4byte gUnk_081AB190
.L08051390: .4byte gUnk_081AAECC

	thumb_func_start sub_8051394
sub_8051394: @ 0x08051394
	push {lr}
	ldr r0, [r0, #0x60]
	bl BasRemove
	ldr r1, .L080513A8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
.L080513A8: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80513AC
sub_80513AC: @ 0x080513AC
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L080513E4 @ =gUnk_085D2178
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080513E4: .4byte gUnk_085D2178

	thumb_func_start sub_80513E8
sub_80513E8: @ 0x080513E8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r4, r0, #0
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08051416
	ldr r0, [r6, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L08051416:
	movs r0, #0x2c
	ldrsh r1, [r6, r0]
	adds r0, r4, #1
	cmp r1, r0
	bne .L08051448
	adds r0, r5, #0
	bl sub_805151C
	bl sub_80516B8
	adds r0, r5, #0
	movs r1, #0xa0
	bl sub_8051624
	ldr r0, .L08051444 @ =0x0000012D
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	b .L08051514
	.align 2, 0
.L08051444: .4byte 0x0000012D
.L08051448:
	adds r0, r4, #0
	adds r0, #0x5a
	cmp r1, r0
	bne .L0805146A
	adds r0, r5, #0
	movs r1, #0x3c
	bl sub_8051720
	movs r0, #0x97
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x78
	movs r3, #0
	bl sub_805C804
	b .L08051514
.L0805146A:
	adds r0, r4, #0
	adds r0, #0xa0
	cmp r1, r0
	bne .L0805147C
	ldr r0, [r6, #0x5c]
	movs r1, #3
	bl sub_80467D0
	b .L08051514
.L0805147C:
	adds r0, r4, #0
	adds r0, #0xa3
	cmp r1, r0
	bne .L080514F4
	adds r0, r5, #0
	movs r1, #0x64
	bl sub_804D050
	adds r0, r5, #0
	movs r1, #0x64
	bl sub_8051870
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x50
	movs r2, #0x14
	movs r3, #0x10
	bl sub_804CD88
	ldr r2, .L080514EC @ =sub_8051C00
	adds r0, r5, #0
	movs r1, #0x64
	bl sub_804CC68
	movs r0, #0x64
	bl sub_8051C30
	adds r0, r5, #0
	bl sub_8051A14
	ldr r0, .L080514F0 @ =0x0000012F
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x78
	movs r3, #0
	bl sub_805C804
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, r6, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08051514
	adds r0, r5, #0
	bl sub_805C358
	b .L08051514
	.align 2, 0
.L080514EC: .4byte sub_8051C00
.L080514F0: .4byte 0x0000012F
.L080514F4:
	adds r0, r4, #0
	adds r0, #0xfa
	cmp r1, r0
	beq .L08051514
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08051514
	bl sub_80474BC
	bl sub_8047358
	adds r0, r6, #0
	bl Proc_Break
.L08051514:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_805151C
sub_805151C: @ 0x0805151C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08051570 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051574 @ =gUnk_085D2190
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08051578 @ =gUnk_0811A478
	str r0, [r5, #0x48]
	ldr r0, .L0805157C @ =gUnk_085D21A8
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08051580 @ =gUnk_085D21DC
	str r0, [r5, #0x54]
	ldr r0, .L08051584 @ =gUnk_081408CC
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L08051588 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08051596
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L0805158C
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08051596
	.align 2, 0
.L08051570: .4byte gUnk_Banim_02017744
.L08051574: .4byte gUnk_085D2190
.L08051578: .4byte gUnk_0811A478
.L0805157C: .4byte gUnk_085D21A8
.L08051580: .4byte gUnk_085D21DC
.L08051584: .4byte gUnk_081408CC
.L08051588: .4byte 0x0203CD14
.L0805158C:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08051596:
	bl sub_8047500
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_80515A0
sub_80515A0: @ 0x080515A0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L080515F8
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl sub_804799C
	ldr r0, .L080515F0 @ =gBg1Tm+0x3C
	ldr r1, .L080515F4 @ =0x0000011F
	str r1, [sp]
	movs r1, #2
	movs r2, #0x14
	movs r3, #1
	bl sub_805B094
	b .L08051616
	.align 2, 0
.L080515F0: .4byte gBg1Tm+0x3C
.L080515F4: .4byte 0x0000011F
.L080515F8:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08051616
	bl sub_80474D8
	ldr r1, .L08051620 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r7, #0
	bl Proc_Break
.L08051616:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08051620: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8051624
sub_8051624: @ 0x08051624
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L0805165C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051660 @ =gUnk_085D2210
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r1, [r0, #0x44]
	ldr r1, .L08051664 @ =gUnk_0811A50E
	str r1, [r0, #0x48]
	ldr r1, .L08051668 @ =gUnk_081408CC
	str r1, [r0, #0x4c]
	adds r0, r1, #0
	movs r1, #0x20
	bl sub_8047AF4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805165C: .4byte gUnk_Banim_02017744
.L08051660: .4byte gUnk_085D2210
.L08051664: .4byte gUnk_0811A50E
.L08051668: .4byte gUnk_081408CC

	thumb_func_start sub_805166C
sub_805166C: @ 0x0805166C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L08051690
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
.L08051690:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L080516AE
	ldr r1, .L080516B4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080516AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080516B4: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80516B8
sub_80516B8: @ 0x080516B8
	push {lr}
	ldr r0, .L080516D0 @ =gUnk_Banim_02017744
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	ldr r0, .L080516D4 @ =gUnk_085D2230
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L080516D0: .4byte gUnk_Banim_02017744
.L080516D4: .4byte gUnk_085D2230

	thumb_func_start sub_80516D8
sub_80516D8: @ 0x080516D8
	push {lr}
	ldr r2, .L080516E8 @ =gDispIo
	movs r1, #8
	strh r1, [r2, #0x22]
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0
.L080516E8: .4byte gDispIo

	thumb_func_start sub_80516EC
sub_80516EC: @ 0x080516EC
	push {lr}
	ldr r2, .L080516FC @ =gDispIo
	movs r1, #0x10
	strh r1, [r2, #0x22]
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0
.L080516FC: .4byte gDispIo

	thumb_func_start sub_8051700
sub_8051700: @ 0x08051700
	push {lr}
	ldr r2, .L08051718 @ =gDispIo
	movs r1, #0x18
	strh r1, [r2, #0x22]
	ldr r2, .L0805171C @ =gUnk_Banim_02017744
	ldr r1, [r2]
	subs r1, #1
	str r1, [r2]
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0
.L08051718: .4byte gDispIo
.L0805171C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8051720
sub_8051720: @ 0x08051720
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08051760 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051764 @ =gUnk_085D2270
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r2, [r0, #0x30]
	movs r1, #1
	str r1, [r0, #0x44]
	str r2, [r0, #0x48]
	ldr r0, .L08051768 @ =gUnk_08143EE4
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	ldr r0, .L0805176C @ =gUnk_08144A00
	movs r1, #0x20
	bl sub_8047AB0
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08051760: .4byte gUnk_Banim_02017744
.L08051764: .4byte gUnk_085D2270
.L08051768: .4byte gUnk_08143EE4
.L0805176C: .4byte gUnk_08144A00

	thumb_func_start sub_8051770
sub_8051770: @ 0x08051770
	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2c]
	adds r0, #1
	movs r2, #0
	strh r0, [r3, #0x2c]
	lsls r0, r0, #0x10
	ldrh r4, [r3, #0x2e]
	lsls r1, r4, #0x10
	cmp r0, r1
	bne .L0805179C
	ldr r1, .L08051798 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r3, #0
	bl Proc_Break
	b .L080517DA
	.align 2, 0
.L08051798: .4byte gUnk_Banim_02017744
.L0805179C:
	ldrh r0, [r3, #0x30]
	adds r0, #1
	strh r0, [r3, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r3, #0x44]
	cmp r0, r1
	bne .L080517DA
	strh r2, [r3, #0x30]
	movs r0, #2
	str r0, [r3, #0x44]
	ldr r4, .L080517E0 @ =gUnk_085D2288
	ldr r0, [r3, #0x48]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080517C6
	str r2, [r3, #0x48]
.L080517C6:
	ldr r2, [r3, #0x48]
	lsls r0, r2, #2
	adds r0, r0, r4
	ldr r1, [r0]
	adds r2, #1
	str r2, [r3, #0x48]
	ldr r0, [r3, #0x5c]
	movs r2, #0x50
	bl sub_80517E4
.L080517DA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080517E0: .4byte gUnk_085D2288

	thumb_func_start sub_80517E4
sub_80517E4: @ 0x080517E4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r1, .L08051830 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051834 @ =gUnk_085D22E0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0xc
	strh r0, [r4, #0x2e]
	ldr r3, .L08051838 @ =gUnk_085E5C10
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	strh r6, [r0, #2]
	mov r1, r8
	strh r1, [r0, #4]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08051830: .4byte gUnk_Banim_02017744
.L08051834: .4byte gUnk_085D22E0
.L08051838: .4byte gUnk_085E5C10

	thumb_func_start sub_805183C
sub_805183C: @ 0x0805183C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08051864
	ldr r0, .L0805186C @ =gUnk_Banim_02017744
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08051864:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805186C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8051870
sub_8051870: @ 0x08051870
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L080518E0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080518E4 @ =gUnk_085D22F8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r1, [r0, #0x30]
	ldr r0, .L080518E8 @ =gUnk_08141320
	ldr r1, .L080518EC @ =gUnk_Banim_0201777C
	bl LZ77UnCompWram
	ldr r0, .L080518F0 @ =gUnk_08142EAC
	ldr r1, .L080518F4 @ =gUnk_Banim_0201B77C
	bl LZ77UnCompWram
	ldr r0, .L080518F8 @ =gUnk_08143AB8
	ldr r4, .L080518FC @ =gUnk_Banim_0201977C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L08051900 @ =gUnk_08143DA8
	movs r1, #0x80
	lsls r1, r1, #4
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	movs r0, #2
	bl EnableBgSync
	bl sub_8047500
	ldr r2, .L08051904 @ =gDispIo
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
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080518E0: .4byte gUnk_Banim_02017744
.L080518E4: .4byte gUnk_085D22F8
.L080518E8: .4byte gUnk_08141320
.L080518EC: .4byte gUnk_Banim_0201777C
.L080518F0: .4byte gUnk_08142EAC
.L080518F4: .4byte gUnk_Banim_0201B77C
.L080518F8: .4byte gUnk_08143AB8
.L080518FC: .4byte gUnk_Banim_0201977C
.L08051900: .4byte gUnk_08143DA8
.L08051904: .4byte gDispIo

	thumb_func_start sub_8051908
sub_8051908: @ 0x08051908
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r5, #1
	adds r0, r5, #0
	ldrh r1, [r4, #0x2c]
	ands r0, r1
	cmp r0, #0
	bne .L080519A0
	movs r2, #0x30
	ldrsh r0, [r4, r2]
	cmp r0, #1
	beq .L0805193C
	cmp r0, #1
	bgt .L0805192C
	cmp r0, #0
	beq .L08051932
	b .L0805194C
.L0805192C:
	cmp r0, #2
	beq .L08051944
	b .L0805194C
.L08051932:
	ldr r0, .L08051938 @ =gUnk_08143A38
	b .L0805194E
	.align 2, 0
.L08051938: .4byte gUnk_08143A38
.L0805193C:
	ldr r0, .L08051940 @ =gUnk_08143A58
	b .L0805194E
	.align 2, 0
.L08051940: .4byte gUnk_08143A58
.L08051944:
	ldr r0, .L08051948 @ =gUnk_08143A78
	b .L0805194E
	.align 2, 0
.L08051948: .4byte gUnk_08143A78
.L0805194C:
	movs r0, #0
.L0805194E:
	movs r1, #0x20
	bl sub_8047AF4
	ldrh r0, [r4, #0x30]
	adds r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bne .L08051966
	movs r0, #0
	strh r0, [r4, #0x30]
.L08051966:
	ldr r0, .L08051990 @ =gUnk_Banim_0201777C
	ldr r1, .L08051994 @ =0x06002000
	movs r2, #0x80
	lsls r2, r2, #6
	bl RegisterDataMove
	ldr r0, .L08051998 @ =gUnk_Banim_0201977C
	ldr r1, .L0805199C @ =gBg1Tm
	movs r2, #1
	str r2, [sp]
	adds r2, #0xff
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x10
	bl sub_805B1AC
	movs r0, #2
	bl EnableBgSync
	b .L080519CE
	.align 2, 0
.L08051990: .4byte gUnk_Banim_0201777C
.L08051994: .4byte 0x06002000
.L08051998: .4byte gUnk_Banim_0201977C
.L0805199C: .4byte gBg1Tm
.L080519A0:
	ldr r0, .L080519FC @ =gUnk_08143A98
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L08051A00 @ =gUnk_Banim_0201B77C
	ldr r1, .L08051A04 @ =0x06002000
	movs r2, #0x80
	lsls r2, r2, #5
	bl RegisterDataMove
	ldr r0, .L08051A08 @ =gUnk_Banim_02019F7C
	ldr r1, .L08051A0C @ =gBg1Tm
	str r5, [sp]
	movs r2, #0x80
	lsls r2, r2, #1
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x10
	bl sub_805B1AC
	movs r0, #2
	bl EnableBgSync
.L080519CE:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L080519F4
	bl sub_80474D8
	ldr r1, .L08051A10 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_End
.L080519F4:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080519FC: .4byte gUnk_08143A98
.L08051A00: .4byte gUnk_Banim_0201B77C
.L08051A04: .4byte 0x06002000
.L08051A08: .4byte gUnk_Banim_02019F7C
.L08051A0C: .4byte gBg1Tm
.L08051A10: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8051A14
sub_8051A14: @ 0x08051A14
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08051A50 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051A54 @ =gUnk_085D2310
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	strh r2, [r0, #0x2e]
	movs r1, #2
	str r1, [r0, #0x44]
	str r2, [r0, #0x48]
	ldr r0, .L08051A58 @ =gUnk_08143EE4
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	ldr r0, .L08051A5C @ =gUnk_08144A00
	movs r1, #0x20
	bl sub_8047AB0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08051A50: .4byte gUnk_Banim_02017744
.L08051A54: .4byte gUnk_085D2310
.L08051A58: .4byte gUnk_08143EE4
.L08051A5C: .4byte gUnk_08144A00

	thumb_func_start sub_8051A60
sub_8051A60: @ 0x08051A60
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x41
	bne .L08051A88
	ldr r1, .L08051A84 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
	b .L08051ABC
	.align 2, 0
.L08051A84: .4byte gUnk_Banim_02017744
.L08051A88:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x44]
	cmp r0, r1
	bne .L08051ABC
	movs r0, #0
	strh r0, [r4, #0x2e]
	movs r0, #2
	str r0, [r4, #0x44]
	ldr r0, [r4, #0x5c]
	ldr r2, [r4, #0x48]
	adds r1, r2, #0
	adds r2, #1
	str r2, [r4, #0x48]
	bl sub_8051AC4
	ldr r0, [r4, #0x5c]
	ldr r2, [r4, #0x48]
	adds r1, r2, #0
	adds r2, #1
	str r2, [r4, #0x48]
	bl sub_8051AC4
.L08051ABC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8051AC4
sub_8051AC4: @ 0x08051AC4
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08051B1C @ =gUnk_0811A520
	mov r0, sp
	movs r2, #0x10
	bl memcpy
	ldr r1, .L08051B20 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051B24 @ =gUnk_085D2328
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x5c]
	movs r4, #0
	strh r4, [r6, #0x2c]
	movs r0, #7
	ands r0, r5
	lsls r0, r0, #1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r6, #0x2e]
	movs r0, #0xe0
	bl sub_805B9C8
	adds r0, #8
	strh r0, [r6, #0x32]
	strh r4, [r6, #0x3a]
	movs r0, #9
	bl sub_805B9C8
	cmp r0, #9
	bhi .L08051B78
	lsls r0, r0, #2
	ldr r1, .L08051B28 @ =.L08051B2C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08051B1C: .4byte gUnk_0811A520
.L08051B20: .4byte gUnk_Banim_02017744
.L08051B24: .4byte gUnk_085D2328
.L08051B28: .4byte .L08051B2C
.L08051B2C: @ jump table
	.4byte .L08051B54 @ case 0
	.4byte .L08051B54 @ case 1
	.4byte .L08051B54 @ case 2
	.4byte .L08051B54 @ case 3
	.4byte .L08051B54 @ case 4
	.4byte .L08051B54 @ case 5
	.4byte .L08051B54 @ case 6
	.4byte .L08051B5C @ case 7
	.4byte .L08051B64 @ case 8
	.4byte .L08051B6C @ case 9
.L08051B54:
	ldr r0, .L08051B58 @ =gUnk_085E5C44
	b .L08051B6E
	.align 2, 0
.L08051B58: .4byte gUnk_085E5C44
.L08051B5C:
	ldr r0, .L08051B60 @ =gUnk_085E5C3C
	b .L08051B6E
	.align 2, 0
.L08051B60: .4byte gUnk_085E5C3C
.L08051B64:
	ldr r0, .L08051B68 @ =gUnk_085E5C34
	b .L08051B6E
	.align 2, 0
.L08051B68: .4byte gUnk_085E5C34
.L08051B6C:
	ldr r0, .L08051B8C @ =gUnk_085E5C2C
.L08051B6E:
	movs r1, #0x78
	bl BasCreate
	adds r4, r0, #0
	str r4, [r6, #0x60]
.L08051B78:
	cmp r4, #0
	bne .L08051B94
	ldr r1, .L08051B90 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl Proc_End
	b .L08051BA2
	.align 2, 0
.L08051B8C: .4byte gUnk_085E5C2C
.L08051B90: .4byte gUnk_Banim_02017744
.L08051B94:
	movs r0, #0x91
	lsls r0, r0, #6
	strh r0, [r4, #8]
	ldrh r0, [r6, #0x32]
	strh r0, [r4, #2]
	ldrh r0, [r6, #0x3a]
	strh r0, [r4, #4]
.L08051BA2:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8051BAC
sub_8051BAC: @ 0x08051BAC
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, [r4, #0x60]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble .L08051BDC
	ldr r1, .L08051BD8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
	b .L08051BF8
	.align 2, 0
.L08051BD8: .4byte gUnk_Banim_02017744
.L08051BDC:
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0x78
	movs r2, #8
	bl Interpolate
	strh r0, [r5, #4]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08051BF8:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8051C00
sub_8051C00: @ 0x08051C00
	ldr r0, .L08051C24 @ =0x04000004
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L08051C20
	ldr r2, .L08051C28 @ =0x04000014
	ldr r3, .L08051C2C @ =gUnk_Banim_0201E154
	ldr r1, [r3]
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	str r1, [r3]
.L08051C20:
	bx lr
	.align 2, 0
.L08051C24: .4byte 0x04000004
.L08051C28: .4byte 0x04000014
.L08051C2C: .4byte gUnk_Banim_0201E154

	thumb_func_start sub_8051C30
sub_8051C30: @ 0x08051C30
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08051C54 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051C58 @ =gUnk_085D2340
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	strh r1, [r0, #0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08051C54: .4byte gUnk_Banim_02017744
.L08051C58: .4byte gUnk_085D2340

	thumb_func_start sub_8051C5C
sub_8051C5C: @ 0x08051C5C
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldr r0, .L08051CBC @ =gUnk_Banim_0201E3D8
	ldr r0, [r0]
	ldr r4, .L08051CC0 @ =gUnk_Banim_0201E158
	cmp r0, #0
	bne .L08051C6C
	ldr r4, .L08051CC4 @ =gUnk_Banim_0201E298
.L08051C6C:
	movs r2, #0
	ldr r6, .L08051CC8 @ =gSinLut
	movs r5, #0xff
.L08051C72:
	lsls r0, r2, #1
	movs r7, #0x30
	ldrsh r1, [r3, r7]
	adds r0, r0, r1
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	asrs r0, r0, #0xa
	adds r0, #4
	strh r0, [r4]
	adds r4, #2
	adds r2, #1
	cmp r2, #0x9f
	bls .L08051C72
	ldrh r0, [r3, #0x30]
	adds r0, #2
	strh r0, [r3, #0x30]
	ldrh r0, [r3, #0x2c]
	adds r0, #1
	strh r0, [r3, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r3, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08051CB6
	ldr r1, .L08051CCC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r3, #0
	bl Proc_Break
.L08051CB6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08051CBC: .4byte gUnk_Banim_0201E3D8
.L08051CC0: .4byte gUnk_Banim_0201E158
.L08051CC4: .4byte gUnk_Banim_0201E298
.L08051CC8: .4byte gSinLut
.L08051CCC: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8051CD0
sub_8051CD0: @ 0x08051CD0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L08051D08 @ =gUnk_085D2358
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08051D08: .4byte gUnk_085D2358

	thumb_func_start sub_8051D0C
sub_8051D0C: @ 0x08051D0C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r3, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #1
	bne .L08051D50
	ldr r0, .L08051D4C @ =0x00000127
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl sub_805C804
	adds r0, r5, #0
	bl sub_8051DFC
	ldr r0, [r4, #0x5c]
	bl sub_8051FEC
	b .L08051DF6
	.align 2, 0
.L08051D4C: .4byte 0x00000127
.L08051D50:
	cmp r2, #0x14
	bne .L08051D64
	movs r0, #0x94
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	b .L08051D90
.L08051D64:
	cmp r2, #0x32
	bne .L08051D74
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	b .L08051DF6
.L08051D74:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r3, #0
	adds r0, #0x46
	cmp r1, r0
	bne .L08051D9C
	adds r0, r5, #0
	bl sub_8051E80
	ldr r0, .L08051D98 @ =0x00000129
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
.L08051D90:
	movs r3, #1
	bl sub_805C804
	b .L08051DF6
	.align 2, 0
.L08051D98: .4byte 0x00000129
.L08051D9C:
	adds r0, r3, #0
	adds r0, #0x49
	cmp r1, r0
	bne .L08051DAE
	ldr r0, [r4, #0x5c]
	movs r1, #0xa
	bl sub_8046794
	b .L08051DF6
.L08051DAE:
	adds r0, r3, #0
	adds r0, #0x4b
	cmp r1, r0
	bne .L08051DDC
	adds r0, r5, #0
	bl sub_8051F04
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08051DF6
	adds r0, r5, #0
	bl sub_805C358
	b .L08051DF6
.L08051DDC:
	adds r0, r3, #0
	adds r0, #0x5a
	cmp r1, r0
	beq .L08051DF6
	cmp r2, #0x64
	bne .L08051DF6
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L08051DF6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8051DFC
sub_8051DFC: @ 0x08051DFC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08051E50 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051E54 @ =gUnk_085D2370
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08051E58 @ =gUnk_0811A530
	str r0, [r5, #0x48]
	ldr r0, .L08051E5C @ =gUnk_085D23D8
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08051E60 @ =gUnk_085D2388
	str r0, [r5, #0x54]
	ldr r0, .L08051E64 @ =gUnk_08176A6C
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L08051E68 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08051E76
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08051E6C
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
	b .L08051E76
	.align 2, 0
.L08051E50: .4byte gUnk_Banim_02017744
.L08051E54: .4byte gUnk_085D2370
.L08051E58: .4byte gUnk_0811A530
.L08051E5C: .4byte gUnk_085D23D8
.L08051E60: .4byte gUnk_085D2388
.L08051E64: .4byte gUnk_08176A6C
.L08051E68: .4byte 0x0203CD14
.L08051E6C:
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
.L08051E76:
	bl sub_8047500
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8051E80
sub_8051E80: @ 0x08051E80
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08051ED4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051ED8 @ =gUnk_085D2370
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08051EDC @ =gUnk_0811A59E
	str r0, [r5, #0x48]
	ldr r0, .L08051EE0 @ =gUnk_085D2434
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08051EE4 @ =gUnk_085D2428
	str r0, [r5, #0x54]
	ldr r0, .L08051EE8 @ =gUnk_08176A6C
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L08051EEC @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08051EFA
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08051EF0
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08051EFA
	.align 2, 0
.L08051ED4: .4byte gUnk_Banim_02017744
.L08051ED8: .4byte gUnk_085D2370
.L08051EDC: .4byte gUnk_0811A59E
.L08051EE0: .4byte gUnk_085D2434
.L08051EE4: .4byte gUnk_085D2428
.L08051EE8: .4byte gUnk_08176A6C
.L08051EEC: .4byte 0x0203CD14
.L08051EF0:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08051EFA:
	bl sub_8047500
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8051F04
sub_8051F04: @ 0x08051F04
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08051F58 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051F5C @ =gUnk_085D2370
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08051F60 @ =gUnk_0811A5AC
	str r0, [r5, #0x48]
	ldr r0, .L08051F64 @ =gUnk_085D2494
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08051F68 @ =gUnk_085D2440
	str r0, [r5, #0x54]
	ldr r0, .L08051F6C @ =gUnk_08176A4C
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L08051F70 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08051F7E
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08051F74
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08051F7E
	.align 2, 0
.L08051F58: .4byte gUnk_Banim_02017744
.L08051F5C: .4byte gUnk_085D2370
.L08051F60: .4byte gUnk_0811A5AC
.L08051F64: .4byte gUnk_085D2494
.L08051F68: .4byte gUnk_085D2440
.L08051F6C: .4byte gUnk_08176A4C
.L08051F70: .4byte 0x0203CD14
.L08051F74:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08051F7E:
	bl sub_8047500
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8051F88
sub_8051F88: @ 0x08051F88
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08051FC4
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl sub_804799C
	b .L08051FE2
.L08051FC4:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08051FE2
	bl sub_80474D8
	ldr r1, .L08051FE8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r7, #0
	bl Proc_Break
.L08051FE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08051FE8: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8051FEC
sub_8051FEC: @ 0x08051FEC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0805202C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052030 @ =gUnk_085D24E8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L08052034 @ =gUnk_085EB83C
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	adds r6, r0, #0
	str r6, [r4, #0x60]
	adds r0, r5, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08052038
	ldrh r0, [r6, #2]
	subs r0, #6
	b .L0805203C
	.align 2, 0
.L0805202C: .4byte gUnk_Banim_02017744
.L08052030: .4byte gUnk_085D24E8
.L08052034: .4byte gUnk_085EB83C
.L08052038:
	ldrh r0, [r6, #2]
	adds r0, #6
.L0805203C:
	strh r0, [r6, #2]
	ldr r0, .L08052058 @ =gUnk_0817AC2C
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0805205C @ =gUnk_0817AAC0
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08052058: .4byte gUnk_0817AC2C
.L0805205C: .4byte gUnk_0817AAC0

	thumb_func_start sub_8052060
sub_8052060: @ 0x08052060
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x2c
	bne .L08052086
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0805208C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08052086:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805208C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8052090
sub_8052090: @ 0x08052090
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L080520C8 @ =gUnk_085D2500
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080520C8: .4byte gUnk_085D2500

	thumb_func_start sub_80520CC
sub_80520CC: @ 0x080520CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r7, #0
	movs r1, #0
	mov r8, r1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08052100
	ldr r0, [r4, #0x5c]
	subs r1, #1
	bl sub_8045C90
.L08052100:
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	adds r0, r6, #1
	cmp r1, r0
	bne .L08052158
	adds r0, r5, #0
	bl sub_8052238
	ldr r3, .L08052154 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r7, [r0]
	adds r0, #1
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r7, [r0]
	str r1, [sp]
	mov r2, r8
	str r2, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x20
	movs r3, #0
	bl sub_804CD88
	adds r0, r5, #0
	movs r1, #0xaa
	bl sub_80524F4
	movs r0, #0x95
	lsls r0, r0, #1
	b .L08052162
	.align 2, 0
.L08052154: .4byte gDispIo
.L08052158:
	ldr r2, .L08052174 @ =0x0000011B
	adds r0, r6, r2
	cmp r1, r0
	bne .L0805217C
	ldr r0, .L08052178 @ =0x0000012B
.L08052162:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	b .L0805222A
	.align 2, 0
.L08052174: .4byte 0x0000011B
.L08052178: .4byte 0x0000012B
.L0805217C:
	ldr r2, .L08052190 @ =0x0000013B
	adds r0, r6, r2
	cmp r1, r0
	bne .L08052194
	adds r0, r5, #0
	movs r1, #0x19
	bl sub_80526F4
	b .L0805222A
	.align 2, 0
.L08052190: .4byte 0x0000013B
.L08052194:
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r0, r6, r3
	cmp r1, r0
	bne .L080521C6
	adds r0, r5, #0
	movs r1, #0xc
	bl sub_8046794
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047610
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0805222A
	adds r0, r5, #0
	bl sub_805C358
	b .L0805222A
.L080521C6:
	movs r2, #0xad
	lsls r2, r2, #1
	adds r0, r6, r2
	cmp r1, r0
	bne .L08052212
	movs r0, #0x96
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x78
	movs r3, #0
	bl sub_805C804
	adds r0, r5, #0
	movs r1, #0x64
	bl sub_804D050
	adds r0, r5, #0
	movs r1, #0x64
	bl sub_8052334
	adds r0, r5, #0
	movs r1, #0x64
	bl sub_8052460
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x46
	movs r2, #0x1e
	movs r3, #0x10
	bl sub_804CD88
	adds r0, r5, #0
	bl sub_8052848
	b .L0805222A
.L08052212:
	movs r2, #0xf5
	lsls r2, r2, #1
	adds r0, r6, r2
	cmp r1, r0
	bne .L0805222A
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L0805222A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8052238
sub_8052238: @ 0x08052238
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L0805228C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052290 @ =gUnk_085D2518
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08052294 @ =gUnk_0811A602
	str r0, [r5, #0x48]
	ldr r0, .L08052298 @ =gUnk_085D2544
	str r0, [r5, #0x4c]
	ldr r0, .L0805229C @ =gUnk_085D2530
	str r0, [r5, #0x54]
	ldr r0, .L080522A0 @ =gUnk_081BB35C
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_80474C8
	bl sub_8047500
	ldr r0, .L080522A4 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080522B4
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L080522A8
	movs r0, #1
	movs r1, #0xf8
	b .L080522AC
	.align 2, 0
.L0805228C: .4byte gUnk_Banim_02017744
.L08052290: .4byte gUnk_085D2518
.L08052294: .4byte gUnk_0811A602
.L08052298: .4byte gUnk_085D2544
.L0805229C: .4byte gUnk_085D2530
.L080522A0: .4byte gUnk_081BB35C
.L080522A4: .4byte 0x0203CD14
.L080522A8:
	movs r0, #1
	movs r1, #0x18
.L080522AC:
	movs r2, #0
	bl SetBgOffset
	b .L080522C8
.L080522B4:
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L080522C8
	movs r0, #1
	movs r1, #0x10
	movs r2, #0
	bl SetBgOffset
.L080522C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80522D0
sub_80522D0: @ 0x080522D0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x2c
	adds r1, r6, #0
	adds r1, #0x44
	ldr r2, [r6, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L0805230A
	ldr r5, [r6, #0x4c]
	ldr r0, [r6, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r6, #0x5c]
	adds r4, r4, r5
	ldr r1, [r4]
	movs r2, #0x20
	movs r3, #0x14
	bl sub_8047A1C
	b .L08052328
.L0805230A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08052328
	bl sub_80474D8
	ldr r1, .L08052330 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r6, #0
	bl Proc_Break
.L08052328:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08052330: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8052334
sub_8052334: @ 0x08052334
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L0805237C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052380 @ =gUnk_085D2558
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r1, [r0, #0x32]
	strh r1, [r0, #0x3a]
	strh r1, [r0, #0x34]
	strh r1, [r0, #0x3c]
	ldr r0, .L08052384 @ =gUnk_081B8E64
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, .L08052388 @ =gUnk_081BB37C
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_80474C8
	bl sub_8047500
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805237C: .4byte gUnk_Banim_02017744
.L08052380: .4byte gUnk_085D2558
.L08052384: .4byte gUnk_081B8E64
.L08052388: .4byte gUnk_081BB37C

	thumb_func_start sub_805238C
sub_805238C: @ 0x0805238C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r6, #1
	adds r0, r6, #0
	ldrh r1, [r5, #0x2c]
	ands r0, r1
	cmp r0, #0
	beq .L080523E8
	ldrh r2, [r5, #0x32]
	subs r2, #0xc
	strh r2, [r5, #0x32]
	ldrh r1, [r5, #0x3a]
	adds r1, #0xc
	strh r1, [r5, #0x3a]
	ldr r0, .L080523D8 @ =gDispIo
	strh r2, [r0, #0x20]
	strh r1, [r0, #0x22]
	ldr r0, .L080523DC @ =gUnk_081BB5E4
	ldr r4, .L080523E0 @ =gUnk_Banim_0201977C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080523E4 @ =gBg1Tm
	str r6, [sp]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x20
	movs r3, #0x20
	bl sub_805B1AC
	movs r0, #2
	bl EnableBgSync
	b .L0805241E
	.align 2, 0
.L080523D8: .4byte gDispIo
.L080523DC: .4byte gUnk_081BB5E4
.L080523E0: .4byte gUnk_Banim_0201977C
.L080523E4: .4byte gBg1Tm
.L080523E8:
	ldrh r2, [r5, #0x34]
	adds r2, #8
	strh r2, [r5, #0x34]
	ldrh r1, [r5, #0x3c]
	adds r1, #8
	strh r1, [r5, #0x3c]
	ldr r0, .L0805244C @ =gDispIo
	strh r2, [r0, #0x20]
	strh r1, [r0, #0x22]
	ldr r0, .L08052450 @ =gUnk_081BB5E4
	ldr r4, .L08052454 @ =gUnk_Banim_0201977C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L08052458 @ =gBg1Tm
	str r6, [sp]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x20
	movs r3, #0x20
	bl sub_805B1DC
	movs r0, #2
	bl EnableBgSync
.L0805241E:
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08052444
	bl sub_80474D8
	bl sub_80475D8
	ldr r1, .L0805245C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L08052444:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805244C: .4byte gDispIo
.L08052450: .4byte gUnk_081BB5E4
.L08052454: .4byte gUnk_Banim_0201977C
.L08052458: .4byte gBg1Tm
.L0805245C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8052460
sub_8052460: @ 0x08052460
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08052498 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805249C @ =gUnk_085D2570
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r1, [r0, #0x44]
	ldr r1, .L080524A0 @ =gUnk_0811A618
	str r1, [r0, #0x48]
	ldr r1, .L080524A4 @ =gUnk_081BB37C
	str r1, [r0, #0x4c]
	adds r0, r1, #0
	movs r1, #0x20
	bl sub_8047AF4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08052498: .4byte gUnk_Banim_02017744
.L0805249C: .4byte gUnk_085D2570
.L080524A0: .4byte gUnk_0811A618
.L080524A4: .4byte gUnk_081BB37C

	thumb_func_start sub_80524A8
sub_80524A8: @ 0x080524A8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L080524CC
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
.L080524CC:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L080524EA
	ldr r1, .L080524F0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080524EA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080524F0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80524F4
sub_80524F4: @ 0x080524F4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08052534 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052538 @ =gUnk_085D2590
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r2, [r0, #0x30]
	movs r1, #0xa
	str r1, [r0, #0x44]
	str r2, [r0, #0x48]
	ldr r0, .L0805253C @ =gUnk_081BC0A8
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08052540 @ =gUnk_081BBBB4
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08052534: .4byte gUnk_Banim_02017744
.L08052538: .4byte gUnk_085D2590
.L0805253C: .4byte gUnk_081BC0A8
.L08052540: .4byte gUnk_081BBBB4

	thumb_func_start sub_8052544
sub_8052544: @ 0x08052544
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2c]
	adds r0, #1
	strh r0, [r3, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r3, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0805256C
	ldr r1, .L08052568 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r3, #0
	bl Proc_Break
	b .L08052592
	.align 2, 0
.L08052568: .4byte gUnk_Banim_02017744
.L0805256C:
	ldrh r0, [r3, #0x30]
	adds r0, #1
	strh r0, [r3, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r3, #0x44]
	cmp r0, r1
	bne .L08052592
	movs r0, #0
	strh r0, [r3, #0x30]
	movs r0, #0xa
	str r0, [r3, #0x44]
	ldr r0, [r3, #0x5c]
	ldr r2, [r3, #0x48]
	adds r1, r2, #0
	adds r2, #1
	str r2, [r3, #0x48]
	bl sub_8052598
.L08052592:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8052598
sub_8052598: @ 0x08052598
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, .L08052624 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052628 @ =gUnk_085D25A8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r6, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x1e
	bl sub_805B9C8
	adds r0, #0x8c
	strh r0, [r4, #0x2e]
	movs r0, #0x1e
	bl sub_805B9C8
	adds r5, r0, #0
	movs r0, #0x1e
	bl sub_805B9C8
	adds r1, r0, #0
	adds r0, r5, #0
	adds r0, #0x46
	strh r0, [r4, #0x32]
	adds r0, r1, #0
	adds r0, #0x28
	strh r0, [r4, #0x34]
	ldr r0, .L0805262C @ =0x0000FFEC
	strh r0, [r4, #0x3a]
	movs r0, #0xa0
	strh r0, [r4, #0x3c]
	ldr r0, .L08052630 @ =0x0203CD14
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080525F8
	adds r0, r5, #0
	adds r0, #0x5e
	strh r0, [r4, #0x32]
	adds r0, r1, #0
	adds r0, #0x40
	strh r0, [r4, #0x34]
.L080525F8:
	adds r0, r6, #0
	bl sub_804B6C4
	cmp r0, #1
	bne .L08052610
	movs r0, #0xf0
	ldrh r2, [r4, #0x32]
	subs r1, r0, r2
	strh r1, [r4, #0x32]
	ldrh r1, [r4, #0x34]
	subs r0, r0, r1
	strh r0, [r4, #0x34]
.L08052610:
	movs r0, #2
	bl sub_805B9C8
	cmp r0, #0
	beq .L08052638
	cmp r0, #1
	beq .L08052640
	ldr r0, .L08052634 @ =gUnk_08603B2C
	b .L08052642
	.align 2, 0
.L08052624: .4byte gUnk_Banim_02017744
.L08052628: .4byte gUnk_085D25A8
.L0805262C: .4byte 0x0000FFEC
.L08052630: .4byte 0x0203CD14
.L08052634: .4byte gUnk_08603B2C
.L08052638:
	ldr r0, .L0805263C @ =gUnk_08603B1C
	b .L08052642
	.align 2, 0
.L0805263C: .4byte gUnk_08603B1C
.L08052640:
	ldr r0, .L08052660 @ =gUnk_08603B24
.L08052642:
	movs r1, #0x78
	bl BasCreate
	adds r1, r0, #0
	str r1, [r4, #0x60]
	cmp r1, #0
	bne .L08052668
	ldr r1, .L08052664 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_End
	b .L08052676
	.align 2, 0
.L08052660: .4byte gUnk_08603B24
.L08052664: .4byte gUnk_Banim_02017744
.L08052668:
	movs r0, #0x91
	lsls r0, r0, #6
	strh r0, [r1, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #2]
	strh r0, [r1, #4]
.L08052676:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_805267C
sub_805267C: @ 0x0805267C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r6, [r5, #0x60]
	movs r0, #0x2c
	ldrsh r1, [r5, r0]
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	ble .L080526AC
	ldr r1, .L080526A8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl BasRemove
	adds r0, r5, #0
	bl Proc_Break
	b .L080526EC
	.align 2, 0
.L080526A8: .4byte gUnk_Banim_02017744
.L080526AC:
	movs r4, #0x32
	ldrsh r1, [r5, r4]
	movs r7, #0x34
	ldrsh r2, [r5, r7]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r4, #0x2e
	ldrsh r0, [r5, r4]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r7, #0x3a
	ldrsh r1, [r5, r7]
	movs r0, #0x3c
	ldrsh r2, [r5, r0]
	movs r7, #0x2c
	ldrsh r3, [r5, r7]
	movs r7, #0x2e
	ldrsh r0, [r5, r7]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	strh r4, [r6, #2]
	strh r0, [r6, #4]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
.L080526EC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_80526F4
sub_80526F4: @ 0x080526F4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r1, .L0805278C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052790 @ =gUnk_085D25C0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	strh r0, [r5, #0x2e]
	strh r4, [r5, #0x30]
	movs r0, #0x5b
	strh r0, [r5, #0x32]
	movs r0, #0x3f
	strh r0, [r5, #0x34]
	ldr r0, .L08052794 @ =0x0000FFF6
	strh r0, [r5, #0x3a]
	movs r0, #0x64
	strh r0, [r5, #0x3c]
	ldr r0, .L08052798 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0805273A
	movs r0, #0x73
	strh r0, [r5, #0x32]
	movs r0, #0x57
	strh r0, [r5, #0x34]
.L0805273A:
	adds r0, r6, #0
	bl sub_804B6C4
	cmp r0, #1
	bne .L08052752
	movs r0, #0xf0
	ldrh r2, [r5, #0x32]
	subs r1, r0, r2
	strh r1, [r5, #0x32]
	ldrh r1, [r5, #0x34]
	subs r0, r0, r1
	strh r0, [r5, #0x34]
.L08052752:
	ldr r3, .L0805279C @ =gUnk_08603B34
	str r3, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r5, #0x60]
	ldrh r1, [r5, #0x32]
	strh r1, [r0, #2]
	ldrh r1, [r5, #0x3a]
	strh r1, [r0, #4]
	ldr r3, .L080527A0 @ =gUnk_08603B58
	str r3, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r5, #0x64]
	ldrh r1, [r5, #0x32]
	strh r1, [r0, #2]
	ldrh r1, [r5, #0x3a]
	strh r1, [r0, #4]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805278C: .4byte gUnk_Banim_02017744
.L08052790: .4byte gUnk_085D25C0
.L08052794: .4byte 0x0000FFF6
.L08052798: .4byte 0x0203CD14
.L0805279C: .4byte gUnk_08603B34
.L080527A0: .4byte gUnk_08603B58

	thumb_func_start sub_80527A4
sub_80527A4: @ 0x080527A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r6, [r4, #0x60]
	ldr r5, [r4, #0x64]
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	movs r7, #0x34
	ldrsh r2, [r4, r7]
	movs r0, #0x2e
	ldrsh r3, [r4, r0]
	movs r7, #0x30
	ldrsh r0, [r4, r7]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	movs r1, #0
	mov r8, r1
	strh r0, [r5, #2]
	strh r0, [r6, #2]
	movs r2, #0x3a
	ldrsh r1, [r4, r2]
	movs r7, #0x3c
	ldrsh r2, [r4, r7]
	movs r0, #0x2e
	ldrsh r3, [r4, r0]
	movs r7, #0x30
	ldrsh r0, [r4, r7]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	strh r0, [r5, #4]
	strh r0, [r6, #4]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x11
	bne .L0805280A
	mov r0, r8
	strh r0, [r4, #0x2c]
	ldr r0, .L08052840 @ =gUnk_08603B58
	str r0, [r5, #0x24]
	str r0, [r5, #0x20]
	mov r1, r8
	strh r1, [r6, #6]
.L0805280A:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08052834
	adds r0, r6, #0
	bl BasRemove
	adds r0, r5, #0
	bl BasRemove
	ldr r1, .L08052844 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08052834:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08052840: .4byte gUnk_08603B58
.L08052844: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8052848
sub_8052848: @ 0x08052848
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08052870 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052874 @ =gUnk_085D25D8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	strh r2, [r0, #0x2e]
	movs r1, #1
	str r1, [r0, #0x44]
	str r2, [r0, #0x48]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08052870: .4byte gUnk_Banim_02017744
.L08052874: .4byte gUnk_085D25D8

	thumb_func_start sub_8052878
sub_8052878: @ 0x08052878
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2c]
	adds r0, #1
	strh r0, [r3, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x2f
	bne .L080528A0
	ldr r1, .L0805289C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r3, #0
	bl Proc_Break
	b .L080528C6
	.align 2, 0
.L0805289C: .4byte gUnk_Banim_02017744
.L080528A0:
	ldrh r0, [r3, #0x2e]
	adds r0, #1
	strh r0, [r3, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r3, #0x44]
	cmp r0, r1
	bne .L080528C6
	movs r0, #0
	strh r0, [r3, #0x2e]
	movs r0, #1
	str r0, [r3, #0x44]
	ldr r0, [r3, #0x5c]
	ldr r2, [r3, #0x48]
	adds r1, r2, #0
	adds r2, #1
	str r2, [r3, #0x48]
	bl sub_80528CC
.L080528C6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80528CC
sub_80528CC: @ 0x080528CC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08052928 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805292C @ =gUnk_085D25F0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #0x14
	strh r0, [r5, #0x2e]
	movs r0, #0x78
	bl sub_805B9C8
	adds r1, r0, #0
	subs r1, #0x3c
	strh r1, [r5, #0x32]
	adds r0, #0xb4
	strh r0, [r5, #0x34]
	movs r1, #0x32
	ldrsh r0, [r5, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	asrs r1, r1, #1
	movs r0, #0x34
	ldrsh r2, [r5, r0]
	lsls r0, r2, #1
	adds r0, r0, r2
	asrs r0, r0, #1
	adds r1, #0xc0
	strh r1, [r5, #0x3a]
	ldr r1, .L08052930 @ =0xFFFFFEB8
	adds r0, r0, r1
	strh r0, [r5, #0x3c]
	movs r0, #2
	bl sub_805B9C8
	cmp r0, #1
	bne .L08052938
	ldr r0, .L08052934 @ =gUnk_08603BA4
	b .L0805293A
	.align 2, 0
.L08052928: .4byte gUnk_Banim_02017744
.L0805292C: .4byte gUnk_085D25F0
.L08052930: .4byte 0xFFFFFEB8
.L08052934: .4byte gUnk_08603BA4
.L08052938:
	ldr r0, .L08052958 @ =gUnk_08603BC0
.L0805293A:
	movs r1, #0x78
	bl BasCreate
	adds r1, r0, #0
	str r1, [r5, #0x60]
	cmp r1, #0
	bne .L08052960
	ldr r1, .L0805295C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_End
	b .L0805296E
	.align 2, 0
.L08052958: .4byte gUnk_08603BC0
.L0805295C: .4byte gUnk_Banim_02017744
.L08052960:
	movs r0, #0x91
	lsls r0, r0, #6
	strh r0, [r1, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #2]
	strh r0, [r1, #4]
.L0805296E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8052974
sub_8052974: @ 0x08052974
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r6, [r5, #0x60]
	movs r0, #0x2c
	ldrsh r1, [r5, r0]
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	ble .L080529A4
	ldr r1, .L080529A0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl BasRemove
	adds r0, r5, #0
	bl Proc_Break
	b .L080529E4
	.align 2, 0
.L080529A0: .4byte gUnk_Banim_02017744
.L080529A4:
	movs r4, #0x32
	ldrsh r1, [r5, r4]
	movs r7, #0x34
	ldrsh r2, [r5, r7]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r4, #0x2e
	ldrsh r0, [r5, r4]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r7, #0x3a
	ldrsh r1, [r5, r7]
	movs r0, #0x3c
	ldrsh r2, [r5, r0]
	movs r7, #0x2c
	ldrsh r3, [r5, r7]
	movs r7, #0x2e
	ldrsh r0, [r5, r7]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	strh r4, [r6, #2]
	strh r0, [r6, #4]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
.L080529E4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_80529EC
sub_80529EC: @ 0x080529EC
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L08052A24 @ =gUnk_085D2608
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08052A24: .4byte gUnk_085D2608

	thumb_func_start sub_8052A28
sub_8052A28: @ 0x08052A28
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r4, r0, #0
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08052A56
	ldr r0, [r6, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L08052A56:
	movs r0, #0x2c
	ldrsh r1, [r6, r0]
	adds r0, r4, #1
	cmp r1, r0
	bne .L08052AD4
	ldr r4, .L08052AC4 @ =0x000001D1
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_8052BA8
	adds r0, r5, #0
	bl sub_8052D40
	adds r0, r5, #0
	bl sub_8052C68
	ldr r1, .L08052AC8 @ =0x0000018B
	adds r0, r5, #0
	movs r2, #0xa
	bl sub_805315C
	ldr r1, .L08052ACC @ =0x0000019F
	adds r0, r5, #0
	movs r2, #0x14
	bl sub_80531C4
	adds r0, r5, #0
	bl sub_8052DF4
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_805304C
	movs r0, #3
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x14
	movs r3, #0x80
	bl sub_804C8D4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x8c
	bl sub_80530E4
	ldr r2, .L08052AD0 @ =sub_804CD4C
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_804CC68
	movs r0, #0x82
	lsls r0, r0, #1
	b .L08052B38
	.align 2, 0
.L08052AC4: .4byte 0x000001D1
.L08052AC8: .4byte 0x0000018B
.L08052ACC: .4byte 0x0000019F
.L08052AD0: .4byte sub_804CD4C
.L08052AD4:
	adds r0, r4, #0
	adds r0, #0x92
	cmp r1, r0
	bne .L08052AE4
	ldr r0, .L08052AE0 @ =0x00000105
	b .L08052B38
	.align 2, 0
.L08052AE0: .4byte 0x00000105
.L08052AE4:
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08052AFA
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x14
	bl sub_804685C
	b .L08052B9A
.L08052AFA:
	ldr r2, .L08052B48 @ =0x000001D5
	adds r0, r4, r2
	cmp r1, r0
	bne .L08052B4C
	adds r0, r5, #0
	movs r1, #0xa0
	bl sub_805327C
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x6e
	movs r2, #0x28
	movs r3, #0x10
	bl sub_804CD88
	adds r0, r5, #0
	movs r1, #0x8c
	movs r2, #0x18
	bl sub_8053420
	adds r0, r5, #0
	movs r1, #0x3c
	bl sub_8053530
	adds r0, r5, #0
	movs r1, #0x5a
	bl sub_804D050
	movs r0, #0x83
	lsls r0, r0, #1
.L08052B38:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x78
	movs r3, #0
	bl sub_805C804
	b .L08052B9A
	.align 2, 0
.L08052B48: .4byte 0x000001D5
.L08052B4C:
	ldr r2, .L08052B78 @ =0x0000020D
	adds r0, r4, r2
	cmp r1, r0
	bne .L08052B7C
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, r6, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08052B9A
	adds r0, r5, #0
	bl sub_805C358
	b .L08052B9A
	.align 2, 0
.L08052B78: .4byte 0x0000020D
.L08052B7C:
	ldr r2, .L08052BA4 @ =0x00000271
	adds r0, r4, r2
	cmp r1, r0
	beq .L08052B9A
	adds r2, #0xa
	adds r0, r4, r2
	cmp r1, r0
	bne .L08052B9A
	bl sub_80474BC
	bl sub_8047358
	adds r0, r6, #0
	bl Proc_Break
.L08052B9A:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08052BA4: .4byte 0x00000271

	thumb_func_start sub_8052BA8
sub_8052BA8: @ 0x08052BA8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08052C18 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052C1C @ =gUnk_085D2620
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	ldr r0, .L08052C20 @ =gUnk_0817AC4C
	movs r1, #0x84
	lsls r1, r1, #5
	bl sub_8047ACC
	bl sub_80474D8
	ldr r0, .L08052C24 @ =gUnk_0817B438
	ldr r4, .L08052C28 @ =gUnk_Banim_0201977C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L08052C2C @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x20
	movs r3, #0x14
	bl sub_805B1AC
	bl sub_8047500
	ldr r2, .L08052C30 @ =gDispIo
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
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08052C18: .4byte gUnk_Banim_02017744
.L08052C1C: .4byte gUnk_085D2620
.L08052C20: .4byte gUnk_0817AC4C
.L08052C24: .4byte gUnk_0817B438
.L08052C28: .4byte gUnk_Banim_0201977C
.L08052C2C: .4byte gBg1Tm
.L08052C30: .4byte gDispIo

	thumb_func_start sub_8052C34
sub_8052C34: @ 0x08052C34
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08052C5E
	bl sub_80474D8
	ldr r1, .L08052C64 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_End
.L08052C5E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08052C64: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8052C68
sub_8052C68: @ 0x08052C68
	push {r4, lr}
	ldr r1, .L08052C94 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052C98 @ =gUnk_085D2638
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	movs r0, #1
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	strh r0, [r4, #0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08052C94: .4byte gUnk_Banim_02017744
.L08052C98: .4byte gUnk_085D2638

	thumb_func_start sub_8052C9C
sub_8052C9C: @ 0x08052C9C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x30
	ldrsh r3, [r6, r0]
	movs r0, #0x96
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0xff
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r1, [r6, #0x30]
	movs r3, #0x30
	ldrsh r0, [r6, r3]
	cmp r0, #0x96
	bgt .L08052CC6
	adds r0, r1, #1
	strh r0, [r6, #0x30]
.L08052CC6:
	ldrh r3, [r6, #0x2e]
	movs r1, #0xff
	ands r1, r3
	ldr r5, .L08052D34 @ =gUnk_08605A94
	lsls r0, r1, #1
	adds r0, r0, r5
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r0, [r0]
	muls r0, r2, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	ldr r4, .L08052D38 @ =gDispIo
	strh r0, [r4, #0x20]
	adds r1, #0x40
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	adds r0, r1, #0
	muls r0, r2, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #0x10
	strh r0, [r4, #0x22]
	adds r3, #2
	strh r3, [r6, #0x2e]
	movs r0, #1
	ldrh r1, [r6, #0x2c]
	ands r0, r1
	cmp r0, #0
	bne .L08052D0E
	movs r0, #1
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
.L08052D0E:
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	movs r1, #0xa0
	lsls r1, r1, #0x11
	cmp r0, r1
	bne .L08052D2C
	ldr r1, .L08052D3C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl Proc_Break
.L08052D2C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08052D34: .4byte gUnk_08605A94
.L08052D38: .4byte gDispIo
.L08052D3C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8052D40
sub_8052D40: @ 0x08052D40
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08052D7C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052D80 @ =gUnk_085D2658
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	movs r1, #0x10
	strh r1, [r0, #0x2e]
	ldr r0, .L08052D84 @ =gUnk_0817B418
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L08052D88 @ =gPal
	movs r1, #1
	movs r2, #1
	movs r3, #0x10
	bl sub_805B5C8
	bl EnablePalSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08052D7C: .4byte gUnk_Banim_02017744
.L08052D80: .4byte gUnk_085D2658
.L08052D84: .4byte gUnk_0817B418
.L08052D88: .4byte gPal

	thumb_func_start sub_8052D8C
sub_8052D8C: @ 0x08052D8C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r4, r0, #0
	ldr r0, .L08052DE8 @ =gUnk_0817B418
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L08052DEC @ =gPal
	movs r1, #1
	movs r2, #1
	adds r3, r4, #0
	bl sub_805B5C8
	bl EnablePalSync
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08052DDE
	ldr r1, .L08052DF0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L08052DDE:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08052DE8: .4byte gUnk_0817B418
.L08052DEC: .4byte gPal
.L08052DF0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8052DF4
sub_8052DF4: @ 0x08052DF4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
.L08052DFA:
	ldr r0, .L08052E24 @ =gUnk_085D2678
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	str r4, [r0, #0x44]
	adds r4, #1
	cmp r4, #7
	bls .L08052DFA
	ldr r0, .L08052E28 @ =gUnk_0817BBB4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08052E2C @ =gUnk_0817B8D0
	movs r1, #0x80
	lsls r1, r1, #4
	bl sub_8047A88
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08052E24: .4byte gUnk_085D2678
.L08052E28: .4byte gUnk_0817BBB4
.L08052E2C: .4byte gUnk_0817B8D0

	thumb_func_start sub_8052E30
sub_8052E30: @ 0x08052E30
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L08052E90 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	ldr r0, [r4, #0x44]
	lsls r1, r0, #0xd
	strh r1, [r4, #0x30]
	ldr r1, .L08052E94 @ =gUnk_085D26B0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r0, [r4, #0x5c]
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r1, .L08052E98 @ =0x0000F3FF
	ldrh r2, [r0, #8]
	ands r1, r2
	movs r3, #0x80
	lsls r3, r3, #3
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r0, #8]
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	movs r0, #0x78
	strh r0, [r4, #0x32]
	movs r0, #0x40
	strh r0, [r4, #0x3a]
	adds r0, r4, #0
	bl Proc_Break
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08052E90: .4byte gUnk_Banim_02017744
.L08052E94: .4byte gUnk_085D26B0
.L08052E98: .4byte 0x0000F3FF

	thumb_func_start sub_8052E9C
sub_8052E9C: @ 0x08052E9C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r7, #0x3c
	str r7, [sp]
	movs r0, #0
	movs r1, #0xb4
	movs r2, #0x32
	bl Interpolate
	ldrh r2, [r5, #0x30]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r6, #0
	strh r1, [r5, #0x30]
	lsrs r2, r1, #8
	ldr r3, .L08052F24 @ =gSinLut
	lsls r1, r2, #1
	adds r1, r1, r3
	adds r2, #0x40
	lsls r2, r2, #1
	adds r2, r2, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r1, r0, r1
	lsls r1, r1, #4
	movs r3, #0
	ldrsh r2, [r2, r3]
	muls r0, r2, r0
	lsls r0, r0, #4
	asrs r1, r1, #0x10
	ldrh r2, [r5, #0x32]
	adds r1, r2, r1
	asrs r0, r0, #0x10
	ldrh r3, [r5, #0x3a]
	adds r0, r3, r0
	strh r1, [r4, #2]
	strh r0, [r4, #4]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3c
	ble .L08052F04
	strh r7, [r5, #0x2c]
.L08052F04:
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x78
	ble .L08052F1C
	strh r6, [r5, #0x2c]
	strh r6, [r5, #0x2e]
	adds r0, r5, #0
	bl Proc_Break
.L08052F1C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08052F24: .4byte gSinLut

	thumb_func_start sub_8052F28
sub_8052F28: @ 0x08052F28
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r7, #0x50
	str r7, [sp]
	movs r0, #0
	movs r1, #0x32
	movs r2, #0
	bl Interpolate
	ldrh r2, [r5, #0x30]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r6, #0
	strh r1, [r5, #0x30]
	lsrs r2, r1, #8
	ldr r3, .L08052FB0 @ =gSinLut
	lsls r1, r2, #1
	adds r1, r1, r3
	adds r2, #0x40
	lsls r2, r2, #1
	adds r2, r2, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r1, r0, r1
	lsls r1, r1, #4
	movs r3, #0
	ldrsh r2, [r2, r3]
	muls r0, r2, r0
	lsls r0, r0, #4
	asrs r1, r1, #0x10
	ldrh r2, [r5, #0x32]
	adds r1, r2, r1
	asrs r0, r0, #0x10
	ldrh r3, [r5, #0x3a]
	adds r0, r3, r0
	strh r1, [r4, #2]
	strh r0, [r4, #4]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x50
	ble .L08052F90
	strh r7, [r5, #0x2c]
.L08052F90:
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x50
	ble .L08052FA8
	strh r6, [r5, #0x2c]
	strh r6, [r5, #0x2e]
	adds r0, r5, #0
	bl Proc_Break
.L08052FA8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08052FB0: .4byte gSinLut

	thumb_func_start sub_8052FB4
sub_8052FB4: @ 0x08052FB4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r6, #0x32
	str r6, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xb4
	bl Interpolate
	ldrh r2, [r5, #0x30]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r2, r3
	strh r1, [r5, #0x30]
	lsrs r2, r1, #8
	ldr r3, .L08053044 @ =gSinLut
	lsls r1, r2, #1
	adds r1, r1, r3
	adds r2, #0x40
	lsls r2, r2, #1
	adds r2, r2, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r1, r0, r1
	lsls r1, r1, #4
	movs r3, #0
	ldrsh r2, [r2, r3]
	muls r0, r2, r0
	lsls r0, r0, #4
	asrs r1, r1, #0x10
	ldrh r2, [r5, #0x32]
	adds r1, r2, r1
	asrs r0, r0, #0x10
	ldrh r3, [r5, #0x3a]
	adds r0, r3, r0
	strh r1, [r4, #2]
	strh r0, [r4, #4]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	ble .L0805301A
	strh r6, [r5, #0x2c]
.L0805301A:
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	ble .L0805303C
	ldr r0, .L08053048 @ =gUnk_Banim_02017744
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r5, #0x60]
	bl BasRemove
	adds r0, r5, #0
	bl Proc_Break
.L0805303C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08053044: .4byte gSinLut
.L08053048: .4byte gUnk_Banim_02017744

	thumb_func_start sub_805304C
sub_805304C: @ 0x0805304C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L0805307C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053080 @ =gUnk_085D26D0
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r1, [r0, #0x44]
	ldr r1, .L08053084 @ =gUnk_0811A62A
	str r1, [r0, #0x48]
	ldr r1, .L08053088 @ =gUnk_0817BBB6
	str r1, [r0, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805307C: .4byte gUnk_Banim_02017744
.L08053080: .4byte gUnk_085D26D0
.L08053084: .4byte gUnk_0811A62A
.L08053088: .4byte gUnk_0817BBB6

	thumb_func_start sub_805308C
sub_805308C: @ 0x0805308C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L080530B6
	ldr r0, [r4, #0x4c]
	ldr r1, .L080530DC @ =gPal+0x2
	movs r2, #0xf
	str r2, [sp]
	adds r2, r3, #0
	movs r3, #0xf
	bl sub_8047B6C
.L080530B6:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L080530D4
	ldr r1, .L080530E0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080530D4:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080530DC: .4byte gPal+0x2
.L080530E0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80530E4
sub_80530E4: @ 0x080530E4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	ldr r1, .L0805310C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053110 @ =gUnk_085D26F0
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	str r6, [r0, #0x64]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805310C: .4byte gUnk_Banim_02017744
.L08053110: .4byte gUnk_085D26F0

	thumb_func_start sub_8053114
sub_8053114: @ 0x08053114
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, [r5, #0x64]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #4
	movs r1, #0x80
	movs r2, #0
	bl Interpolate
	str r0, [r4, #0x4c]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08053150
	ldr r1, .L08053158 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L08053150:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08053158: .4byte gUnk_Banim_02017744

	thumb_func_start sub_805315C
sub_805315C: @ 0x0805315C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r1, .L08053184 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053188 @ =gUnk_085D2708
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r6, [r0, #0x5c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08053184: .4byte gUnk_Banim_02017744
.L08053188: .4byte gUnk_085D2708

	thumb_func_start sub_805318C
sub_805318C: @ 0x0805318C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L080531B8
	ldr r1, .L080531C0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r0, [r4, #0x5c]
	movs r2, #0x30
	ldrsh r1, [r4, r2]
	bl sub_8046794
	adds r0, r4, #0
	bl Proc_Break
.L080531B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080531C0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80531C4
sub_80531C4: @ 0x080531C4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r1, .L080531EC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080531F0 @ =gUnk_085D2720
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r6, [r0, #0x5c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080531EC: .4byte gUnk_Banim_02017744
.L080531F0: .4byte gUnk_085D2720

	thumb_func_start sub_80531F4
sub_80531F4: @ 0x080531F4
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r2, #0x2e]
	lsls r1, r3, #0x10
	cmp r0, r1
	ble .L08053212
	movs r0, #0
	strh r0, [r2, #0x2c]
	adds r0, r2, #0
	bl Proc_Break
.L08053212:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8053218
sub_8053218: @ 0x08053218
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r1, #0x30
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r4, r0, #0
	ldr r0, .L08053270 @ =gUnk_0817B418
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L08053274 @ =gPal
	movs r1, #1
	movs r2, #1
	adds r3, r4, #0
	bl sub_805B644
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08053266
	ldr r1, .L08053278 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L08053266:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08053270: .4byte gUnk_0817B418
.L08053274: .4byte gPal
.L08053278: .4byte gUnk_Banim_02017744

	thumb_func_start sub_805327C
sub_805327C: @ 0x0805327C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r1, .L08053320 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053324 @ =gUnk_085D2740
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	strh r0, [r5, #0x2e]
	strh r4, [r5, #0x30]
	str r0, [r5, #0x44]
	ldr r0, .L08053328 @ =gUnk_0811A668
	str r0, [r5, #0x48]
	ldr r0, .L0805332C @ =gUnk_085D2768
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08053330 @ =gUnk_085D2758
	str r0, [r5, #0x54]
	ldr r0, .L08053334 @ =gUnk_08181E60
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	bl sub_805894C
	cmp r0, #0
	beq .L08053318
	ldr r0, [r5, #0x5c]
	bl sub_804B80C
	ldr r4, .L08053338 @ =gDispIo
	movs r2, #4
	rsbs r2, r2, #0
	adds r1, r2, #0
	ldrb r3, [r4, #0xc]
	ands r1, r3
	strb r1, [r4, #0xc]
	adds r1, r2, #0
	ldrb r3, [r4, #0x18]
	ands r1, r3
	movs r3, #1
	orrs r1, r3
	strb r1, [r4, #0x18]
	ldrb r1, [r4, #0x10]
	ands r2, r1
	movs r1, #2
	orrs r2, r1
	strb r2, [r4, #0x10]
	movs r1, #3
	ldrb r2, [r4, #0x14]
	orrs r1, r2
	strb r1, [r4, #0x14]
	ldr r1, .L0805333C @ =0x0000F3FF
	adds r2, r1, #0
	ldrh r3, [r6, #8]
	ands r2, r3
	movs r4, #0x80
	lsls r4, r4, #3
	adds r3, r4, #0
	orrs r2, r3
	strh r2, [r6, #8]
	ldrh r2, [r0, #8]
	ands r1, r2
	orrs r1, r3
	strh r1, [r0, #8]
.L08053318:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08053320: .4byte gUnk_Banim_02017744
.L08053324: .4byte gUnk_085D2740
.L08053328: .4byte gUnk_0811A668
.L0805332C: .4byte gUnk_085D2768
.L08053330: .4byte gUnk_085D2758
.L08053334: .4byte gUnk_08181E60
.L08053338: .4byte gDispIo
.L0805333C: .4byte 0x0000F3FF

	thumb_func_start sub_8053340
sub_8053340: @ 0x08053340
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, [r7, #0x5c]
	bl sub_804B80C
	mov r8, r0
	adds r0, r7, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08053388
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl sub_804799C
.L08053388:
	ldrh r0, [r7, #0x2e]
	adds r0, #1
	strh r0, [r7, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r7, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08053408
	bl sub_805894C
	cmp r0, #0
	beq .L080533F2
	ldr r3, .L08053414 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r2, [r3, #0x10]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x10]
	ldrb r0, [r3, #0x18]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x18]
	movs r0, #3
	ldrb r1, [r3, #0x14]
	orrs r0, r1
	strb r0, [r3, #0x14]
	ldr r2, [r7, #0x5c]
	ldr r1, .L08053418 @ =0x0000F3FF
	adds r0, r1, #0
	ldrh r3, [r2, #8]
	ands r0, r3
	strh r0, [r2, #8]
	ldr r2, [r7, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #4
	adds r3, r0, #0
	ldrh r0, [r2, #8]
	orrs r0, r3
	strh r0, [r2, #8]
	mov r2, r8
	ldrh r2, [r2, #8]
	ands r1, r2
	orrs r1, r3
	mov r3, r8
	strh r1, [r3, #8]
.L080533F2:
	bl sub_80474D8
	ldr r1, .L0805341C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r7, #0
	bl Proc_End
.L08053408:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08053414: .4byte gDispIo
.L08053418: .4byte 0x0000F3FF
.L0805341C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8053420
sub_8053420: @ 0x08053420
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r1, .L080534A4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080534A8 @ =gUnk_085D2778
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r6, [r4, #0x2e]
	mov r0, r8
	strh r0, [r4, #0x30]
	ldr r3, .L080534AC @ =gUnk_085EBF40
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	adds r5, r0, #0
	str r5, [r4, #0x60]
	movs r0, #0x78
	strh r0, [r5, #2]
	movs r0, #0x48
	strh r0, [r5, #4]
	movs r0, #0x14
	strh r0, [r5, #0xa]
	bl BasSort
	bl sub_805894C
	cmp r0, #0
	beq .L08053486
	ldr r0, .L080534B0 @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
.L08053486:
	ldr r0, .L080534B4 @ =gUnk_081629D4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L080534B8 @ =gUnk_081830F4
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080534A4: .4byte gUnk_Banim_02017744
.L080534A8: .4byte gUnk_085D2778
.L080534AC: .4byte gUnk_085EBF40
.L080534B0: .4byte 0x0000F3FF
.L080534B4: .4byte gUnk_081629D4
.L080534B8: .4byte gUnk_081830F4

	thumb_func_start sub_80534BC
sub_80534BC: @ 0x080534BC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x60]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r3, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r5, [r4, #0x2e]
	lsls r1, r5, #0x10
	cmp r0, r1
	ble .L080534EE
	strh r3, [r4, #0x2c]
	ldr r0, .L080534F4 @ =gUnk_085EC478
	str r0, [r2, #0x24]
	str r0, [r2, #0x20]
	strh r3, [r2, #6]
	ldr r0, .L080534F8 @ =gUnk_0818360C
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
.L080534EE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080534F4: .4byte gUnk_085EC478
.L080534F8: .4byte gUnk_0818360C

	thumb_func_start sub_80534FC
sub_80534FC: @ 0x080534FC
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08053524
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0805352C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08053524:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805352C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8053530
sub_8053530: @ 0x08053530
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08053560 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053564 @ =gUnk_085D2798
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r2, [r0, #0x30]
	movs r1, #1
	str r1, [r0, #0x44]
	str r2, [r0, #0x48]
	str r2, [r0, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08053560: .4byte gUnk_Banim_02017744
.L08053564: .4byte gUnk_085D2798

	thumb_func_start sub_8053568
sub_8053568: @ 0x08053568
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov ip, r1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08053594
	ldr r1, .L08053590 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
	b .L080535E4
	.align 2, 0
.L08053590: .4byte gUnk_Banim_02017744
.L08053594:
	ldrh r0, [r4, #0x30]
	adds r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x44]
	cmp r0, r1
	bne .L080535E4
	mov r0, ip
	strh r0, [r4, #0x30]
	movs r0, #2
	str r0, [r4, #0x44]
	ldr r3, .L080535EC @ =gUnk_085D27B0
	ldr r1, [r4, #0x4c]
	lsls r2, r1, #2
	adds r0, r2, r3
	ldr r7, [r0]
	ldr r0, .L080535F0 @ =gUnk_085D287C
	adds r0, r2, r0
	ldr r6, [r0]
	ldr r0, .L080535F4 @ =gUnk_085D2944
	adds r2, r2, r0
	ldr r5, [r2]
	adds r1, #1
	str r1, [r4, #0x4c]
	lsls r1, r1, #2
	adds r1, r1, r3
	ldr r1, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080535D8
	mov r1, ip
	str r1, [r4, #0x4c]
.L080535D8:
	ldr r0, [r4, #0x5c]
	adds r1, r7, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl sub_80535F8
.L080535E4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080535EC: .4byte gUnk_085D27B0
.L080535F0: .4byte gUnk_085D287C
.L080535F4: .4byte gUnk_085D2944

	thumb_func_start sub_80535F8
sub_80535F8: @ 0x080535F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r1, .L08053644 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053648 @ =gUnk_085D2A0C
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	mov r0, r8
	str r0, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	strh r4, [r6, #0x2e]
	str r5, [r6, #0x44]
	lsls r4, r4, #0xb
	adds r5, r5, r4
	str r5, [r6, #0x48]
	movs r0, #0x78
	strh r0, [r6, #0x32]
	movs r0, #0x48
	strh r0, [r6, #0x3a]
	cmp r7, #6
	bhi .L0805367C
	lsls r0, r7, #2
	ldr r1, .L0805364C @ =.L08053650
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08053644: .4byte gUnk_Banim_02017744
.L08053648: .4byte gUnk_085D2A0C
.L0805364C: .4byte .L08053650
.L08053650: @ jump table
	.4byte .L0805366C @ case 0
	.4byte .L0805366C @ case 1
	.4byte .L0805366C @ case 2
	.4byte .L0805366C @ case 3
	.4byte .L0805366C @ case 4
	.4byte .L08053674 @ case 5
	.4byte .L0805367C @ case 6
.L0805366C:
	ldr r3, .L08053670 @ =gUnk_085EBF60
	b .L0805367E
	.align 2, 0
.L08053670: .4byte gUnk_085EBF60
.L08053674:
	ldr r3, .L08053678 @ =gUnk_085EBF58
	b .L0805367E
	.align 2, 0
.L08053678: .4byte gUnk_085EBF58
.L0805367C:
	ldr r3, .L080536BC @ =gUnk_085EBF50
.L0805367E:
	str r3, [sp]
	mov r0, r8
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	adds r4, r0, #0
	str r4, [r6, #0x60]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #2]
	strh r0, [r4, #4]
	bl sub_805894C
	cmp r0, #0
	beq .L080536AE
	ldr r0, .L080536C0 @ =0x0000F3FF
	ldrh r1, [r4, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4, #8]
.L080536AE:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080536BC: .4byte gUnk_085EBF50
.L080536C0: .4byte 0x0000F3FF

	thumb_func_start sub_80536C4
sub_80536C4: @ 0x080536C4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r5, [r6, #0x60]
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0x6e
	movs r2, #0
	bl Interpolate
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r1, [r6, #0x44]
	ldr r2, [r6, #0x48]
	movs r7, #0x2c
	ldrsh r3, [r6, r7]
	movs r7, #0x2e
	ldrsh r0, [r6, r7]
	str r0, [sp]
	movs r0, #1
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	ldr r2, .L0805375C @ =gSinLut
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	muls r1, r4, r1
	lsls r1, r1, #4
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	lsls r0, r0, #4
	asrs r1, r1, #0x10
	ldrh r2, [r6, #0x32]
	adds r1, r2, r1
	asrs r0, r0, #0x10
	ldrh r7, [r6, #0x3a]
	adds r0, r7, r0
	strh r1, [r5, #2]
	strh r0, [r5, #4]
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r6, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08053752
	ldr r0, [r6, #0x60]
	bl BasRemove
	ldr r1, .L08053760 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl Proc_Break
.L08053752:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805375C: .4byte gSinLut
.L08053760: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8053764
sub_8053764: @ 0x08053764
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L0805379C @ =gUnk_085D2A24
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805379C: .4byte gUnk_085D2A24

	thumb_func_start sub_80537A0
sub_80537A0: @ 0x080537A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r4, r0, #0
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080537D6
	ldr r0, [r6, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L080537D6:
	movs r2, #0x2c
	ldrsh r1, [r6, r2]
	adds r0, r4, #1
	cmp r1, r0
	bne .L08053848
	ldr r3, .L08053844 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	mov r2, r8
	strb r2, [r0]
	adds r0, #1
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	str r1, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x1e
	movs r3, #0
	bl sub_804CD88
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xa0
	movs r2, #0x1e
	movs r3, #0x10
	bl sub_804CD88
	ldr r0, [r6, #0x5c]
	bl sub_8053954
	ldr r0, [r6, #0x5c]
	bl sub_8053CB4
	movs r0, #0x9c
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x78
	movs r3, #0
	bl sub_805C804
	b .L08053946
	.align 2, 0
.L08053844: .4byte gDispIo
.L08053848:
	adds r0, r4, #0
	adds r0, #0x7f
	cmp r1, r0
	bne .L0805387C
	movs r0, #2
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0x52
	movs r2, #0xf
	movs r3, #0
	bl sub_804C8D4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x3c
	bl sub_8050D68
	ldr r2, .L08053878 @ =sub_804CD4C
	adds r0, r5, #0
	movs r1, #0x53
	bl sub_804CC68
	b .L08053946
	.align 2, 0
.L08053878: .4byte sub_804CD4C
.L0805387C:
	adds r0, r4, #0
	adds r0, #0xd2
	cmp r1, r0
	bne .L0805388C
	adds r0, r5, #0
	bl sub_80539C4
	b .L08053946
.L0805388C:
	adds r0, r4, #0
	adds r0, #0xd7
	cmp r1, r0
	bne .L080538AC
	ldr r0, .L080538A8 @ =0x00000139
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	b .L08053946
	.align 2, 0
.L080538A8: .4byte 0x00000139
.L080538AC:
	adds r0, r4, #0
	adds r0, #0xf1
	cmp r1, r0
	bne .L080538BC
	ldr r0, [r6, #0x5c]
	bl sub_8053AFC
	b .L08053946
.L080538BC:
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08053902
	movs r0, #0x9d
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	adds r0, r5, #0
	movs r1, #0xa
	bl sub_8046794
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, r6, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08053946
	adds r0, r5, #0
	bl sub_805C358
	b .L08053946
.L08053902:
	movs r2, #0xa3
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08053924
	adds r0, r5, #0
	bl sub_8053A44
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x10
	movs r2, #0xa
	movs r3, #0x10
	bl sub_804CD88
	b .L08053946
.L08053924:
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r0, r4, r3
	cmp r1, r0
	beq .L08053946
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08053946
	bl sub_80474BC
	bl sub_8047358
	adds r0, r6, #0
	bl Proc_Break
.L08053946:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8053954
sub_8053954: @ 0x08053954
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080539A8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080539AC @ =gUnk_085D2A3C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L080539B0 @ =gUnk_0811A67A
	str r1, [r0, #0x48]
	ldr r1, .L080539B4 @ =gUnk_085D2A54
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L080539B8 @ =gUnk_085D2AC0
	str r1, [r0, #0x54]
	ldr r0, .L080539BC @ =gUnk_0816B328
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	ldr r2, .L080539C0 @ =gDispIo
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
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080539A8: .4byte gUnk_Banim_02017744
.L080539AC: .4byte gUnk_085D2A3C
.L080539B0: .4byte gUnk_0811A67A
.L080539B4: .4byte gUnk_085D2A54
.L080539B8: .4byte gUnk_085D2AC0
.L080539BC: .4byte gUnk_0816B328
.L080539C0: .4byte gDispIo

	thumb_func_start sub_80539C4
sub_80539C4: @ 0x080539C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08053A28 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053A2C @ =gUnk_085D2A3C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r4, #0
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L08053A30 @ =gUnk_0811A680
	str r1, [r0, #0x48]
	ldr r1, .L08053A34 @ =gUnk_085D2A54
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L08053A38 @ =gUnk_085D2AC0
	str r1, [r0, #0x54]
	ldr r0, .L08053A3C @ =gUnk_0818BBCC
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	ldr r3, .L08053A40 @ =gDispIo
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
	movs r0, #0xc
	strb r0, [r1]
	adds r1, #1
	movs r0, #6
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08053A28: .4byte gUnk_Banim_02017744
.L08053A2C: .4byte gUnk_085D2A3C
.L08053A30: .4byte gUnk_0811A680
.L08053A34: .4byte gUnk_085D2A54
.L08053A38: .4byte gUnk_085D2AC0
.L08053A3C: .4byte gUnk_0818BBCC
.L08053A40: .4byte gDispIo

	thumb_func_start sub_8053A44
sub_8053A44: @ 0x08053A44
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08053A80 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053A84 @ =gUnk_085D2A3C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L08053A88 @ =gUnk_0811A722
	str r1, [r0, #0x48]
	ldr r1, .L08053A8C @ =gUnk_085D2A54
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L08053A90 @ =gUnk_085D2AC0
	str r1, [r0, #0x54]
	ldr r0, .L08053A94 @ =gUnk_0818BBEC
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08053A80: .4byte gUnk_Banim_02017744
.L08053A84: .4byte gUnk_085D2A3C
.L08053A88: .4byte gUnk_0811A722
.L08053A8C: .4byte gUnk_085D2A54
.L08053A90: .4byte gUnk_085D2AC0
.L08053A94: .4byte gUnk_0818BBEC

	thumb_func_start sub_8053A98
sub_8053A98: @ 0x08053A98
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08053AD4
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl sub_804799C
	b .L08053AF2
.L08053AD4:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08053AF2
	bl sub_80474D8
	ldr r1, .L08053AF8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r7, #0
	bl Proc_Break
.L08053AF2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08053AF8: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8053AFC
sub_8053AFC: @ 0x08053AFC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08053B54 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053B58 @ =gUnk_085D2B2C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	adds r0, r5, #0
	bl sub_804B80C
	adds r5, r0, #0
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L08053B5C @ =gUnk_085D0E8C
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	adds r6, r0, #0
	str r6, [r4, #0x60]
	ldr r0, .L08053B60 @ =0x0000F3FF
	ldrh r1, [r6, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r6, #8]
	adds r0, r5, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08053B64
	ldrh r0, [r6, #2]
	subs r0, #8
	b .L08053B68
	.align 2, 0
.L08053B54: .4byte gUnk_Banim_02017744
.L08053B58: .4byte gUnk_085D2B2C
.L08053B5C: .4byte gUnk_085D0E8C
.L08053B60: .4byte 0x0000F3FF
.L08053B64:
	ldrh r0, [r6, #2]
	adds r0, #8
.L08053B68:
	strh r0, [r6, #2]
	ldrh r0, [r6, #4]
	subs r0, #0x10
	strh r0, [r6, #4]
	bl sub_8058998
	cmp r0, #0
	beq .L08053B7E
	ldrh r0, [r6, #2]
	subs r0, #0x10
	strh r0, [r6, #2]
.L08053B7E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8053B88
sub_8053B88: @ 0x08053B88
	push {lr}
	ldr r2, .L08053B9C @ =gUnk_Banim_02017744
	ldr r1, [r2]
	subs r1, #1
	str r1, [r2]
	ldr r0, [r0, #0x60]
	bl BasRemove
	pop {r0}
	bx r0
	.align 2, 0
.L08053B9C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8053BA0
sub_8053BA0: @ 0x08053BA0
	push {r4, lr}
	adds r1, r0, #0
	ldr r2, [r1, #0x60]
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	movs r4, #0
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #1
	bne .L08053BE4
	ldr r0, .L08053BD8 @ =gUnk_085EC630
	str r0, [r2, #0x24]
	str r0, [r2, #0x20]
	strh r4, [r2, #6]
	movs r0, #0xa
	strh r0, [r1, #0x2e]
	ldr r0, .L08053BDC @ =gUnk_0818EA78
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08053BE0 @ =gUnk_0818DD18
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	b .L08053BF4
	.align 2, 0
.L08053BD8: .4byte gUnk_085EC630
.L08053BDC: .4byte gUnk_0818EA78
.L08053BE0: .4byte gUnk_0818DD18
.L08053BE4:
	movs r2, #0x2e
	ldrsh r0, [r1, r2]
	cmp r3, r0
	bne .L08053BF4
	strh r4, [r1, #0x2c]
	adds r0, r1, #0
	bl Proc_Break
.L08053BF4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8053BFC
sub_8053BFC: @ 0x08053BFC
	push {r4, lr}
	adds r1, r0, #0
	ldr r2, [r1, #0x60]
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	movs r4, #0
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #1
	bne .L08053C40
	ldr r0, .L08053C34 @ =gUnk_085EC938
	str r0, [r2, #0x24]
	str r0, [r2, #0x20]
	strh r4, [r2, #6]
	movs r0, #0xa
	strh r0, [r1, #0x2e]
	ldr r0, .L08053C38 @ =gUnk_0818EA78
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08053C3C @ =gUnk_0818E1E4
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	b .L08053C50
	.align 2, 0
.L08053C34: .4byte gUnk_085EC938
.L08053C38: .4byte gUnk_0818EA78
.L08053C3C: .4byte gUnk_0818E1E4
.L08053C40:
	movs r2, #0x2e
	ldrsh r0, [r1, r2]
	cmp r3, r0
	bne .L08053C50
	strh r4, [r1, #0x2c]
	adds r0, r1, #0
	bl Proc_Break
.L08053C50:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8053C58
sub_8053C58: @ 0x08053C58
	push {r4, lr}
	adds r1, r0, #0
	ldr r2, [r1, #0x60]
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	movs r4, #0
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #1
	bne .L08053C9C
	ldr r0, .L08053C90 @ =gUnk_085ECC34
	str r0, [r2, #0x24]
	str r0, [r2, #0x20]
	strh r4, [r2, #6]
	movs r0, #0xa
	strh r0, [r1, #0x2e]
	ldr r0, .L08053C94 @ =gUnk_0818EA78
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08053C98 @ =gUnk_0818E67C
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	b .L08053CAC
	.align 2, 0
.L08053C90: .4byte gUnk_085ECC34
.L08053C94: .4byte gUnk_0818EA78
.L08053C98: .4byte gUnk_0818E67C
.L08053C9C:
	movs r2, #0x2e
	ldrsh r0, [r1, r2]
	cmp r3, r0
	bne .L08053CAC
	strh r4, [r1, #0x2c]
	adds r0, r1, #0
	bl Proc_Break
.L08053CAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8053CB4
sub_8053CB4: @ 0x08053CB4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08053CEC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053CF0 @ =gUnk_085D2B74
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	movs r1, #0x64
	strh r1, [r0, #0x30]
	ldr r0, .L08053CF4 @ =gUnk_081629D4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08053CF8 @ =gUnk_08161DDC
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08053CEC: .4byte gUnk_Banim_02017744
.L08053CF0: .4byte gUnk_085D2B74
.L08053CF4: .4byte gUnk_081629D4
.L08053CF8: .4byte gUnk_08161DDC

	thumb_func_start sub_8053CFC
sub_8053CFC: @ 0x08053CFC
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x12
	bne .L08053D4E
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, .L08053D54 @ =gUnk_085D2B8C
	movs r1, #0x2e
	ldrsh r2, [r4, r1]
	lsls r1, r2, #2
	adds r1, r1, r0
	lsls r2, r2, #1
	adds r2, #1
	lsls r2, r2, #1
	adds r2, r2, r0
	ldr r0, [r4, #0x5c]
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r3, #0
	ldrsh r2, [r2, r3]
	bl sub_8053D5C
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	bne .L08053D4E
	ldr r1, .L08053D58 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08053D4E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08053D54: .4byte gUnk_085D2B8C
.L08053D58: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8053D5C
sub_8053D5C: @ 0x08053D5C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r1, .L08053DA4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053DA8 @ =gUnk_085D2BA4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L08053DAC @ =gUnk_085EAC34
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	strh r6, [r0, #2]
	mov r1, r8
	strh r1, [r0, #4]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08053DA4: .4byte gUnk_Banim_02017744
.L08053DA8: .4byte gUnk_085D2BA4
.L08053DAC: .4byte gUnk_085EAC34

	thumb_func_start sub_8053DB0
sub_8053DB0: @ 0x08053DB0
	push {lr}
	ldr r2, .L08053DC4 @ =gUnk_Banim_02017744
	ldr r1, [r2]
	subs r1, #1
	str r1, [r2]
	ldr r0, [r0, #0x60]
	bl BasRemove
	pop {r0}
	bx r0
	.align 2, 0
.L08053DC4: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8053DC8
sub_8053DC8: @ 0x08053DC8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L08053E00 @ =gUnk_085D2BC4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08053E00: .4byte gUnk_085D2BC4

	thumb_func_start sub_8053E04
sub_8053E04: @ 0x08053E04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r4, r0, #0
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08053E3A
	ldr r0, [r6, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L08053E3A:
	movs r2, #0x2c
	ldrsh r1, [r6, r2]
	adds r0, r4, #1
	cmp r1, r0
	bne .L08053ED0
	adds r0, r5, #0
	movs r1, #0x64
	bl sub_8053FF4
	adds r0, r5, #0
	movs r1, #0x64
	bl sub_80540D0
	movs r4, #0x80
	lsls r4, r4, #1
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0x64
	movs r2, #2
	adds r3, r4, #0
	bl sub_804C8D4
	ldr r2, .L08053EC8 @ =sub_804CD4C
	adds r0, r5, #0
	movs r1, #0x69
	bl sub_804CC68
	ldr r3, .L08053ECC @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	mov r2, r8
	strb r2, [r0]
	adds r0, #1
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	str r1, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xf
	movs r3, #0
	bl sub_804CD88
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x46
	movs r2, #0xf
	movs r3, #0x10
	bl sub_804CD88
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r4, #0
	movs r2, #0x78
	movs r3, #0
	bl sub_805C804
	b .L08053FE8
	.align 2, 0
.L08053EC8: .4byte sub_804CD4C
.L08053ECC: .4byte gDispIo
.L08053ED0:
	adds r0, r4, #0
	adds r0, #0x28
	cmp r1, r0
	bne .L08053EE8
	adds r0, r5, #0
	movs r1, #0x4a
	bl sub_8054168
	ldr r0, .L08053EE4 @ =0x00000131
	b .L08053F40
	.align 2, 0
.L08053EE4: .4byte 0x00000131
.L08053EE8:
	adds r0, r4, #0
	adds r0, #0x6e
	cmp r1, r0
	bne .L08053EF8
	adds r0, r5, #0
	bl sub_80541FC
	b .L08053FE8
.L08053EF8:
	adds r0, r4, #0
	adds r0, #0x6f
	cmp r1, r0
	beq .L08053F3C
	adds r0, r4, #0
	adds r0, #0x8b
	cmp r1, r0
	beq .L08053F3C
	adds r0, r4, #0
	adds r0, #0xa7
	cmp r1, r0
	beq .L08053F3C
	adds r0, r4, #0
	adds r0, #0xc3
	cmp r1, r0
	beq .L08053F3C
	adds r0, r4, #0
	adds r0, #0xdf
	cmp r1, r0
	beq .L08053F3C
	adds r0, r4, #0
	adds r0, #0xfb
	cmp r1, r0
	beq .L08053F3C
	ldr r2, .L08053F50 @ =0x00000117
	adds r0, r4, r2
	cmp r1, r0
	beq .L08053F3C
	movs r0, #0x2c
	ldrsh r1, [r6, r0]
	ldr r7, .L08053F54 @ =0x00000133
	adds r0, r4, r7
	cmp r1, r0
	bne .L08053F58
.L08053F3C:
	movs r0, #0x99
	lsls r0, r0, #1
.L08053F40:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl sub_805C804
	b .L08053FE8
	.align 2, 0
.L08053F50: .4byte 0x00000117
.L08053F54: .4byte 0x00000133
.L08053F58:
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08053FA2
	adds r0, r5, #0
	movs r1, #0xa
	bl sub_8046794
	adds r0, r5, #0
	bl sub_80543C4
	movs r0, #9
	ldrh r3, [r5, #0x10]
	orrs r0, r3
	strh r0, [r5, #0x10]
	adds r4, r6, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_8047600
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r5, r0]
	adds r0, r7, #0
	movs r3, #1
	bl sub_805C804
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08053FE8
	adds r0, r5, #0
	bl sub_805C358
	b .L08053FE8
.L08053FA2:
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08053FC6
	adds r0, r5, #0
	bl sub_805428C
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #8
	movs r3, #0x10
	bl sub_804CD88
	b .L08053FE8
.L08053FC6:
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r0, r4, r3
	cmp r1, r0
	beq .L08053FE8
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08053FE8
	bl sub_80474BC
	bl sub_8047358
	adds r0, r6, #0
	bl Proc_Break
.L08053FE8:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_8053FF4
sub_8053FF4: @ 0x08053FF4
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08054068 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805406C @ =gUnk_085D2BDC
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	ldr r0, .L08054070 @ =gUnk_0818EA98
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	bl sub_80474D8
	ldr r0, .L08054074 @ =gUnk_0818F3D8
	ldr r4, .L08054078 @ =gUnk_Banim_0201977C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L0805407C @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x20
	movs r3, #0x20
	bl sub_805B1AC
	movs r0, #2
	bl EnableBgSync
	bl sub_8047500
	ldr r2, .L08054080 @ =gDispIo
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
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08054068: .4byte gUnk_Banim_02017744
.L0805406C: .4byte gUnk_085D2BDC
.L08054070: .4byte gUnk_0818EA98
.L08054074: .4byte gUnk_0818F3D8
.L08054078: .4byte gUnk_Banim_0201977C
.L0805407C: .4byte gBg1Tm
.L08054080: .4byte gDispIo

	thumb_func_start sub_8054084
sub_8054084: @ 0x08054084
	push {lr}
	bl sub_80474D8
	ldr r1, .L0805409C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	pop {r0}
	bx r0
	.align 2, 0
.L0805409C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80540A0
sub_80540A0: @ 0x080540A0
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080540CC @ =gDispIo
	ldrh r1, [r0, #0x22]
	adds r1, #1
	strh r1, [r0, #0x22]
	ldrh r1, [r0, #0x20]
	subs r1, #1
	strh r1, [r0, #0x20]
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r2, #0x2e]
	lsls r1, r3, #0x10
	cmp r0, r1
	ble .L080540C8
	adds r0, r2, #0
	bl Proc_Break
.L080540C8:
	pop {r0}
	bx r0
	.align 2, 0
.L080540CC: .4byte gDispIo

	thumb_func_start sub_80540D0
sub_80540D0: @ 0x080540D0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08054108 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805410C @ =gUnk_085D2BFC
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r1, [r0, #0x44]
	ldr r1, .L08054110 @ =gUnk_0811A758
	str r1, [r0, #0x48]
	ldr r1, .L08054114 @ =gUnk_0818F1F8
	str r1, [r0, #0x4c]
	adds r0, r1, #0
	movs r1, #0x20
	bl sub_8047AF4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08054108: .4byte gUnk_Banim_02017744
.L0805410C: .4byte gUnk_085D2BFC
.L08054110: .4byte gUnk_0811A758
.L08054114: .4byte gUnk_0818F1F8

	thumb_func_start sub_8054118
sub_8054118: @ 0x08054118
	ldr r1, .L08054124 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L08054124: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8054128
sub_8054128: @ 0x08054128
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0805414C
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
.L0805414C:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08054162
	adds r0, r4, #0
	bl Proc_Break
.L08054162:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8054168
sub_8054168: @ 0x08054168
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, .L080541B4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080541B8 @ =gUnk_085D2C24
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r6, [r4, #0x2e]
	ldr r3, .L080541BC @ =gUnk_085ED924
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r0, .L080541C0 @ =gUnk_0819875C
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L080541C4 @ =gUnk_08197BE0
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080541B4: .4byte gUnk_Banim_02017744
.L080541B8: .4byte gUnk_085D2C24
.L080541BC: .4byte gUnk_085ED924
.L080541C0: .4byte gUnk_0819875C
.L080541C4: .4byte gUnk_08197BE0

	thumb_func_start sub_80541C8
sub_80541C8: @ 0x080541C8
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L080541F0
	ldr r0, .L080541F8 @ =gUnk_Banim_02017744
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L080541F0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080541F8: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80541FC
sub_80541FC: @ 0x080541FC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08054260 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054264 @ =gUnk_085D2C3C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08054268 @ =gUnk_0811A796
	str r0, [r5, #0x48]
	ldr r0, .L0805426C @ =gUnk_085D2D20
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08054270 @ =gUnk_085D2C54
	str r0, [r5, #0x54]
	ldr r0, .L08054274 @ =gUnk_08193598
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r0, .L08054278 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08054286
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L0805427C
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08054286
	.align 2, 0
.L08054260: .4byte gUnk_Banim_02017744
.L08054264: .4byte gUnk_085D2C3C
.L08054268: .4byte gUnk_0811A796
.L0805426C: .4byte gUnk_085D2D20
.L08054270: .4byte gUnk_085D2C54
.L08054274: .4byte gUnk_08193598
.L08054278: .4byte 0x0203CD14
.L0805427C:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08054286:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_805428C
sub_805428C: @ 0x0805428C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L080542E4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080542E8 @ =gUnk_085D2C3C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L080542EC @ =gUnk_08119F50
	str r0, [r5, #0x48]
	ldr r0, .L080542F0 @ =gUnk_085D1430
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L080542F4 @ =gUnk_085D13DC
	str r0, [r5, #0x54]
	ldr r0, .L080542F8 @ =gUnk_081935B8
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	ldr r0, .L080542FC @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0805430A
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08054300
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0805430A
	.align 2, 0
.L080542E4: .4byte gUnk_Banim_02017744
.L080542E8: .4byte gUnk_085D2C3C
.L080542EC: .4byte gUnk_08119F50
.L080542F0: .4byte gUnk_085D1430
.L080542F4: .4byte gUnk_085D13DC
.L080542F8: .4byte gUnk_081935B8
.L080542FC: .4byte 0x0203CD14
.L08054300:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0805430A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8054310
sub_8054310: @ 0x08054310
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08054398
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl sub_804799C
	ldr r0, .L08054374 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L080543B6
	ldr r0, [r7, #0x5c]
	bl sub_804B6C4
	adds r1, r0, #0
	cmp r1, #0
	bne .L0805437C
	ldr r0, .L08054378 @ =gBg1Tm
	str r1, [sp]
	movs r1, #3
	movs r2, #0x14
	movs r3, #0
	bl sub_805B094
	b .L0805438C
	.align 2, 0
.L08054374: .4byte 0x0203CD14
.L08054378: .4byte gBg1Tm
.L0805437C:
	ldr r0, .L08054394 @ =gBg1Tm+0x3A
	movs r1, #0
	str r1, [sp]
	movs r1, #3
	movs r2, #0x14
	movs r3, #0
	bl sub_805B094
.L0805438C:
	movs r0, #2
	bl EnableBgSync
	b .L080543B6
	.align 2, 0
.L08054394: .4byte gBg1Tm+0x3A
.L08054398:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L080543B6
	bl sub_80474D8
	ldr r1, .L080543C0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r7, #0
	bl Proc_Break
.L080543B6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080543C0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80543C4
sub_80543C4: @ 0x080543C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080543FC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054400 @ =gUnk_085D2DEC
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	str r1, [r0, #0x44]
	ldr r0, .L08054404 @ =gUnk_0819877C
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08054408 @ =gUnk_08197BE0
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080543FC: .4byte gUnk_Banim_02017744
.L08054400: .4byte gUnk_085D2DEC
.L08054404: .4byte gUnk_0819877C
.L08054408: .4byte gUnk_08197BE0

	thumb_func_start sub_805440C
sub_805440C: @ 0x0805440C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne .L0805444C
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x5c]
	ldr r2, [r4, #0x44]
	adds r1, r2, #0
	adds r2, #1
	str r2, [r4, #0x44]
	bl sub_8054458
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	bne .L0805444C
	ldr r1, .L08054454 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0805444C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08054454: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8054458
sub_8054458: @ 0x08054458
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r1, .L08054498 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805449C @ =gUnk_085D2E04
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #0x1e
	strh r0, [r5, #0x2e]
	ldr r1, .L080544A0 @ =gUnk_085D2E1C
	movs r0, #7
	ands r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r5, #0x44]
	movs r1, #0
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq .L080544A4
	cmp r0, #1
	beq .L080544AC
	b .L080544B8
	.align 2, 0
.L08054498: .4byte gUnk_Banim_02017744
.L0805449C: .4byte gUnk_085D2E04
.L080544A0: .4byte gUnk_085D2E1C
.L080544A4:
	ldr r0, .L080544A8 @ =gUnk_085ED8CC
	b .L080544AE
	.align 2, 0
.L080544A8: .4byte gUnk_085ED8CC
.L080544AC:
	ldr r0, .L080544D4 @ =gUnk_085ED8F8
.L080544AE:
	movs r1, #0x78
	bl BasCreate
	adds r1, r0, #0
	str r1, [r5, #0x60]
.L080544B8:
	movs r0, #0xa1
	lsls r0, r0, #6
	strh r0, [r1, #8]
	ldrh r0, [r6, #2]
	strh r0, [r1, #2]
	ldrh r0, [r6, #2]
	strh r0, [r5, #0x32]
	ldrh r0, [r6, #4]
	strh r0, [r1, #4]
	ldrh r0, [r6, #4]
	strh r0, [r5, #0x3a]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080544D4: .4byte gUnk_085ED8F8

	thumb_func_start sub_80544D8
sub_80544D8: @ 0x080544D8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r5, [r6, #0x60]
	movs r2, #0x96
	lsls r2, r2, #1
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl Interpolate
	ldr r4, .L08054550 @ =gSinLut
	ldr r2, [r6, #0x44]
	lsls r1, r2, #1
	adds r1, r1, r4
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r3, r0, #0
	muls r3, r1, r3
	adds r2, #0x40
	lsls r2, r2, #1
	adds r2, r2, r4
	movs r4, #0
	ldrsh r1, [r2, r4]
	muls r0, r1, r0
	asrs r3, r3, #0xc
	ldrh r1, [r6, #0x32]
	adds r3, r1, r3
	strh r3, [r5, #2]
	asrs r0, r0, #0xc
	ldrh r2, [r6, #0x3a]
	adds r0, r2, r0
	strh r0, [r5, #4]
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r6, #0x2e]
	lsls r1, r3, #0x10
	cmp r0, r1
	ble .L08054546
	ldr r0, .L08054554 @ =gUnk_Banim_02017744
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r6, #0x60]
	bl BasRemove
	adds r0, r6, #0
	bl Proc_Break
.L08054546:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08054550: .4byte gSinLut
.L08054554: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8054558
sub_8054558: @ 0x08054558
	push {r4, lr}
	adds r4, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L0805457C @ =gUnk_085D2E3C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805457C: .4byte gUnk_085D2E3C

	thumb_func_start sub_8054580
sub_8054580: @ 0x08054580
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080545B0
	ldr r0, [r4, #0x5c]
	bl sub_8054F8C
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf3
	b .L0805465C
.L080545B0:
	cmp r0, #0x34
	bne .L08054618
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl sub_8054B98
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl sub_8054D78
	ldr r3, .L08054614 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl sub_8054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x23
	movs r2, #0x19
	movs r3, #1
	bl sub_8054EA0
	movs r0, #0x87
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	b .L0805465C
	.align 2, 0
.L08054614: .4byte gDispIo
.L08054618:
	cmp r0, #0x37
	bne .L08054626
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	b .L080546A0
.L08054626:
	cmp r0, #0x71
	bne .L08054668
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl sub_8054C54
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl sub_8054DE8
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl sub_8054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x1d
	movs r2, #0x19
	movs r3, #1
	bl sub_8054EA0
	ldr r0, .L08054664 @ =0x0000010F
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
.L0805465C:
	movs r3, #1
	bl sub_805C804
	b .L080546A0
	.align 2, 0
.L08054664: .4byte 0x0000010F
.L08054668:
	cmp r0, #0xa6
	bne .L08054674
	adds r0, r5, #0
	bl sub_80451E0
	b .L080546A0
.L08054674:
	cmp r0, #0xb5
	bne .L080546A0
	bl sub_80474BC
	bl sub_8047358
	adds r0, r5, #0
	bl sub_804B848
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L0805469A
	movs r0, #2
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
.L0805469A:
	adds r0, r4, #0
	bl Proc_Break
.L080546A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80546A8
sub_80546A8: @ 0x080546A8
	push {r4, lr}
	adds r4, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L080546CC @ =gUnk_085D2E54
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080546CC: .4byte gUnk_085D2E54

	thumb_func_start sub_80546D0
sub_80546D0: @ 0x080546D0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r2, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08054706
	ldr r0, [r4, #0x5c]
	bl sub_8054F8C
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf3
	b .L080547EE
.L08054706:
	cmp r0, #0x34
	bne .L0805476C
	ldr r0, [r4, #0x5c]
	movs r1, #1
	bl sub_8054B98
	ldr r0, [r4, #0x5c]
	movs r1, #1
	bl sub_8054D78
	ldr r3, .L08054768 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl sub_8054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x23
	movs r2, #0x19
	movs r3, #1
	bl sub_8054EA0
	movs r0, #0x88
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	b .L080547EE
	.align 2, 0
.L08054768: .4byte gDispIo
.L0805476C:
	cmp r0, #0x37
	bne .L0805477A
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	b .L08054840
.L0805477A:
	cmp r0, #0x71
	bne .L0805478A
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	b .L08054840
.L0805478A:
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	adds r0, r2, #0
	adds r0, #0x72
	cmp r1, r0
	bne .L08054800
	ldr r0, [r4, #0x5c]
	movs r1, #1
	bl sub_8054C54
	ldr r0, [r4, #0x5c]
	movs r1, #1
	bl sub_8054DE8
	ldr r3, .L080547F8 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl sub_8054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x1d
	movs r2, #0x19
	movs r3, #1
	bl sub_8054EA0
	ldr r0, .L080547FC @ =0x00000111
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
.L080547EE:
	movs r3, #1
	bl sub_805C804
	b .L08054840
	.align 2, 0
.L080547F8: .4byte gDispIo
.L080547FC: .4byte 0x00000111
.L08054800:
	adds r0, r2, #0
	adds r0, #0xa6
	cmp r1, r0
	bne .L08054810
	adds r0, r5, #0
	bl sub_80451E0
	b .L08054840
.L08054810:
	adds r0, r2, #0
	adds r0, #0xb5
	cmp r1, r0
	bne .L08054840
	bl sub_80474BC
	bl sub_8047358
	adds r0, r5, #0
	bl sub_804B848
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L0805483A
	movs r0, #2
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
.L0805483A:
	adds r0, r4, #0
	bl Proc_Break
.L08054840:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8054848
sub_8054848: @ 0x08054848
	push {r4, lr}
	adds r4, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L0805486C @ =gUnk_085D2E6C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805486C: .4byte gUnk_085D2E6C

	thumb_func_start sub_8054870
sub_8054870: @ 0x08054870
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r2, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080548A6
	ldr r0, [r4, #0x5c]
	bl sub_8054F8C
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf3
	b .L0805498E
.L080548A6:
	cmp r0, #0x34
	bne .L0805490C
	ldr r0, [r4, #0x5c]
	movs r1, #2
	bl sub_8054B98
	ldr r0, [r4, #0x5c]
	movs r1, #2
	bl sub_8054D78
	ldr r3, .L08054908 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl sub_8054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x23
	movs r2, #0x19
	movs r3, #1
	bl sub_8054EA0
	movs r0, #0x89
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	b .L0805498E
	.align 2, 0
.L08054908: .4byte gDispIo
.L0805490C:
	cmp r0, #0x37
	bne .L0805491A
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	b .L080549E0
.L0805491A:
	cmp r0, #0x71
	bne .L0805492A
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	b .L080549E0
.L0805492A:
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	adds r0, r2, #0
	adds r0, #0x72
	cmp r1, r0
	bne .L080549A0
	ldr r0, [r4, #0x5c]
	movs r1, #2
	bl sub_8054C54
	ldr r0, [r4, #0x5c]
	movs r1, #2
	bl sub_8054DE8
	ldr r3, .L08054998 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl sub_8054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x1d
	movs r2, #0x19
	movs r3, #1
	bl sub_8054EA0
	ldr r0, .L0805499C @ =0x00000113
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
.L0805498E:
	movs r3, #1
	bl sub_805C804
	b .L080549E0
	.align 2, 0
.L08054998: .4byte gDispIo
.L0805499C: .4byte 0x00000113
.L080549A0:
	adds r0, r2, #0
	adds r0, #0xa6
	cmp r1, r0
	bne .L080549B0
	adds r0, r5, #0
	bl sub_80451E0
	b .L080549E0
.L080549B0:
	adds r0, r2, #0
	adds r0, #0xb5
	cmp r1, r0
	bne .L080549E0
	bl sub_80474BC
	bl sub_8047358
	adds r0, r5, #0
	bl sub_804B848
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L080549DA
	movs r0, #2
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
.L080549DA:
	adds r0, r4, #0
	bl Proc_Break
.L080549E0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80549E8
sub_80549E8: @ 0x080549E8
	push {r4, lr}
	adds r4, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L08054A0C @ =gUnk_085D2E84
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08054A0C: .4byte gUnk_085D2E84

	thumb_func_start sub_8054A10
sub_8054A10: @ 0x08054A10
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r2, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08054A4E
	ldr r0, [r4, #0x5c]
	bl sub_8054F8C
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl sub_80550EC
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf3
	b .L08054B3E
.L08054A4E:
	cmp r0, #0x34
	bne .L08054AB4
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl sub_8054B98
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl sub_8054D78
	ldr r3, .L08054AB0 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl sub_8054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x23
	movs r2, #0x19
	movs r3, #1
	bl sub_8054EA0
	movs r0, #0x87
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	b .L08054B3E
	.align 2, 0
.L08054AB0: .4byte gDispIo
.L08054AB4:
	cmp r0, #0x37
	bne .L08054AC2
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	b .L08054B90
.L08054AC2:
	cmp r0, #0x97
	bne .L08054ADA
	ldr r0, [r4, #0x5c]
	movs r1, #1
	bl sub_80550EC
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	b .L08054B90
.L08054ADA:
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	adds r0, r2, #0
	adds r0, #0xa1
	cmp r1, r0
	bne .L08054B50
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl sub_8054C54
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl sub_8054DE8
	ldr r3, .L08054B48 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl sub_8054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x1d
	movs r2, #0x19
	movs r3, #1
	bl sub_8054EA0
	ldr r0, .L08054B4C @ =0x0000010F
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
.L08054B3E:
	movs r3, #1
	bl sub_805C804
	b .L08054B90
	.align 2, 0
.L08054B48: .4byte gDispIo
.L08054B4C: .4byte 0x0000010F
.L08054B50:
	adds r0, r2, #0
	adds r0, #0xd3
	cmp r1, r0
	bne .L08054B60
	adds r0, r5, #0
	bl sub_80451E0
	b .L08054B90
.L08054B60:
	adds r0, r2, #0
	adds r0, #0xdd
	cmp r1, r0
	bne .L08054B90
	bl sub_80474BC
	bl sub_8047358
	adds r0, r5, #0
	bl sub_804B848
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L08054B8A
	movs r0, #2
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
.L08054B8A:
	adds r0, r4, #0
	bl Proc_Break
.L08054B90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8054B98
sub_8054B98: @ 0x08054B98
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, .L08054BE0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054BE4 @ =gUnk_085D2E9C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	cmp r6, #0
	beq .L08054BF8
	cmp r6, #2
	bhi .L08054C4A
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L08054BE8 @ =gUnk_0811A8A4
	str r0, [r5, #0x48]
	ldr r0, .L08054BEC @ =gUnk_081AC90C
	str r0, [r5, #0x4c]
	ldr r0, .L08054BF0 @ =gUnk_081AD26C
	str r0, [r5, #0x50]
	ldr r0, .L08054BF4 @ =gUnk_081AC114
	movs r1, #0xa8
	lsls r1, r1, #5
	bl sub_8047ACC
	b .L08054C4A
	.align 2, 0
.L08054BE0: .4byte gUnk_Banim_02017744
.L08054BE4: .4byte gUnk_085D2E9C
.L08054BE8: .4byte gUnk_0811A8A4
.L08054BEC: .4byte gUnk_081AC90C
.L08054BF0: .4byte gUnk_081AD26C
.L08054BF4: .4byte gUnk_081AC114
.L08054BF8:
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L08054C30 @ =gUnk_0811A898
	str r0, [r5, #0x48]
	ldr r0, .L08054C34 @ =gUnk_081AB340
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08054C38 @ =gUnk_081AB1B0
	movs r1, #0x80
	lsls r1, r1, #3
	bl sub_8047ACC
	ldr r0, .L08054C3C @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08054C4A
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08054C40
	movs r0, #1
	movs r1, #0x18
	b .L08054C44
	.align 2, 0
.L08054C30: .4byte gUnk_0811A898
.L08054C34: .4byte gUnk_081AB340
.L08054C38: .4byte gUnk_081AB1B0
.L08054C3C: .4byte 0x0203CD14
.L08054C40:
	movs r0, #1
	movs r1, #0xe8
.L08054C44:
	movs r2, #0
	bl SetBgOffset
.L08054C4A:
	bl sub_8047500
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_8054C54
sub_8054C54: @ 0x08054C54
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, .L08054C9C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054CA0 @ =gUnk_085D2E9C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r1, #0
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	adds r0, r5, #0
	adds r0, #0x29
	strb r1, [r0]
	cmp r6, #0
	beq .L08054CB4
	cmp r6, #2
	bhi .L08054CFE
	ldr r0, .L08054CA4 @ =gUnk_0811A8AA
	str r0, [r5, #0x48]
	ldr r0, .L08054CA8 @ =gUnk_081AC90C
	str r0, [r5, #0x4c]
	ldr r0, .L08054CAC @ =gUnk_081AD26C
	str r0, [r5, #0x50]
	ldr r0, .L08054CB0 @ =gUnk_081AC114
	movs r1, #0xa8
	lsls r1, r1, #5
	bl sub_8047ACC
	b .L08054CFE
	.align 2, 0
.L08054C9C: .4byte gUnk_Banim_02017744
.L08054CA0: .4byte gUnk_085D2E9C
.L08054CA4: .4byte gUnk_0811A8AA
.L08054CA8: .4byte gUnk_081AC90C
.L08054CAC: .4byte gUnk_081AD26C
.L08054CB0: .4byte gUnk_081AC114
.L08054CB4:
	ldr r0, .L08054CE4 @ =gUnk_0811A89E
	str r0, [r5, #0x48]
	ldr r0, .L08054CE8 @ =gUnk_081AB340
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08054CEC @ =gUnk_081AB1B0
	movs r1, #0x80
	lsls r1, r1, #3
	bl sub_8047ACC
	ldr r0, .L08054CF0 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08054CFE
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08054CF4
	movs r0, #1
	movs r1, #0xe8
	b .L08054CF8
	.align 2, 0
.L08054CE4: .4byte gUnk_0811A89E
.L08054CE8: .4byte gUnk_081AB340
.L08054CEC: .4byte gUnk_081AB1B0
.L08054CF0: .4byte 0x0203CD14
.L08054CF4:
	movs r0, #1
	movs r1, #0x18
.L08054CF8:
	movs r2, #0
	bl SetBgOffset
.L08054CFE:
	bl sub_8047500
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_8054D08
sub_8054D08: @ 0x08054D08
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L08054D3A
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r4, r3, #2
	adds r4, r4, r3
	lsls r3, r4, #4
	subs r3, r3, r4
	lsls r3, r3, #4
	adds r1, r1, r3
	adds r2, r2, r3
	bl sub_8047938
	b .L08054D6C
.L08054D3A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne .L08054D6C
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08054D54
	bl sub_80474D8
	bl sub_80475D8
.L08054D54:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r1, .L08054D74 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08054D6C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08054D74: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8054D78
sub_8054D78: @ 0x08054D78
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08054DA0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054DA4 @ =gUnk_085D2EB4
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	str r4, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	str r0, [r1, #0x44]
	cmp r5, #0
	bne .L08054DAC
	ldr r0, .L08054DA8 @ =gUnk_0811A8B0
	b .L08054DBA
	.align 2, 0
.L08054DA0: .4byte gUnk_Banim_02017744
.L08054DA4: .4byte gUnk_085D2EB4
.L08054DA8: .4byte gUnk_0811A8B0
.L08054DAC:
	cmp r5, #1
	bne .L08054DB8
	ldr r0, .L08054DB4 @ =gUnk_0811A934
	b .L08054DBA
	.align 2, 0
.L08054DB4: .4byte gUnk_0811A934
.L08054DB8:
	ldr r0, .L08054DC4 @ =gUnk_0811A966
.L08054DBA:
	str r0, [r1, #0x48]
	cmp r5, #0
	bne .L08054DCC
	ldr r0, .L08054DC8 @ =gUnk_081ABCA0
	b .L08054DDA
	.align 2, 0
.L08054DC4: .4byte gUnk_0811A966
.L08054DC8: .4byte gUnk_081ABCA0
.L08054DCC:
	cmp r5, #1
	bne .L08054DD8
	ldr r0, .L08054DD4 @ =gUnk_081ADDEC
	b .L08054DDA
	.align 2, 0
.L08054DD4: .4byte gUnk_081ADDEC
.L08054DD8:
	ldr r0, .L08054DE4 @ =gUnk_081ADBCC
.L08054DDA:
	str r0, [r1, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08054DE4: .4byte gUnk_081ADBCC

	thumb_func_start sub_8054DE8
sub_8054DE8: @ 0x08054DE8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08054E10 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054E14 @ =gUnk_085D2EB4
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	str r4, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	str r0, [r1, #0x44]
	cmp r5, #0
	bne .L08054E1C
	ldr r0, .L08054E18 @ =gUnk_0811A8F2
	b .L08054E2A
	.align 2, 0
.L08054E10: .4byte gUnk_Banim_02017744
.L08054E14: .4byte gUnk_085D2EB4
.L08054E18: .4byte gUnk_0811A8F2
.L08054E1C:
	cmp r5, #1
	bne .L08054E28
	ldr r0, .L08054E24 @ =gUnk_0811A934
	b .L08054E2A
	.align 2, 0
.L08054E24: .4byte gUnk_0811A934
.L08054E28:
	ldr r0, .L08054E34 @ =gUnk_0811A966
.L08054E2A:
	str r0, [r1, #0x48]
	cmp r5, #0
	bne .L08054E3C
	ldr r0, .L08054E38 @ =gUnk_081ABCA0
	b .L08054E4A
	.align 2, 0
.L08054E34: .4byte gUnk_0811A966
.L08054E38: .4byte gUnk_081ABCA0
.L08054E3C:
	cmp r5, #1
	bne .L08054E48
	ldr r0, .L08054E44 @ =gUnk_081ADDEC
	b .L08054E4A
	.align 2, 0
.L08054E44: .4byte gUnk_081ADDEC
.L08054E48:
	ldr r0, .L08054E54 @ =gUnk_081ADBCC
.L08054E4A:
	str r0, [r1, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08054E54: .4byte gUnk_081ADBCC

	thumb_func_start sub_8054E58
sub_8054E58: @ 0x08054E58
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L08054E7E
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
	b .L08054E94
.L08054E7E:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08054E94
	ldr r1, .L08054E9C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08054E94:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08054E9C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8054EA0
sub_8054EA0: @ 0x08054EA0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r1, .L08054ED4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054ED8 @ =gUnk_085D2ED4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	strh r5, [r0, #0x2c]
	strh r6, [r0, #0x2e]
	adds r0, #0x29
	mov r1, r8
	strb r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08054ED4: .4byte gUnk_Banim_02017744
.L08054ED8: .4byte gUnk_085D2ED4

	thumb_func_start sub_8054EDC
sub_8054EDC: @ 0x08054EDC
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	subs r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08054EF2
	adds r0, r1, #0
	bl Proc_Break
.L08054EF2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8054EF8
sub_8054EF8: @ 0x08054EF8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble .L08054F20
	ldr r1, .L08054F1C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
	b .L08054F7E
	.align 2, 0
.L08054F1C: .4byte gUnk_Banim_02017744
.L08054F20:
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08054F3C
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	b .L08054F4C
.L08054F3C:
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
.L08054F4C:
	bl Interpolate
	adds r5, r0, #0
	ldr r3, .L08054F88 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	movs r1, #0
	strb r5, [r0]
	adds r2, #9
	movs r0, #0x10
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x46
	strb r1, [r0]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08054F7E:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08054F88: .4byte gDispIo

	thumb_func_start sub_8054F8C
sub_8054F8C: @ 0x08054F8C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08054FD8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054FDC @ =gUnk_085D2EF4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x33
	strh r0, [r4, #0x2e]
	ldr r3, .L08054FE0 @ =gUnk_085F0A14
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r0, .L08054FE4 @ =gUnk_081AC0F4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08054FE8 @ =gUnk_081ABEA0
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08054FD8: .4byte gUnk_Banim_02017744
.L08054FDC: .4byte gUnk_085D2EF4
.L08054FE0: .4byte gUnk_085F0A14
.L08054FE4: .4byte gUnk_081AC0F4
.L08054FE8: .4byte gUnk_081ABEA0

	thumb_func_start sub_8054FEC
sub_8054FEC: @ 0x08054FEC
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0805503C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055040 @ =gUnk_085D2F0C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x33
	strh r0, [r4, #0x2e]
	movs r0, #0x34
	strh r0, [r4, #0x30]
	ldr r3, .L08055044 @ =gUnk_085F0A14
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r0, .L08055048 @ =gUnk_081AC0F4
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0805504C @ =gUnk_081ABEA0
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805503C: .4byte gUnk_Banim_02017744
.L08055040: .4byte gUnk_085D2F0C
.L08055044: .4byte gUnk_085F0A14
.L08055048: .4byte gUnk_081AC0F4
.L0805504C: .4byte gUnk_081ABEA0

	thumb_func_start sub_8055050
sub_8055050: @ 0x08055050
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08055078
	ldr r0, .L08055080 @ =gUnk_Banim_02017744
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08055078:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055080: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8055084
sub_8055084: @ 0x08055084
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x60]
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	movs r4, #0
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r5, [r2, #0x2e]
	lsls r1, r5, #0x10
	cmp r0, r1
	bne .L080550AC
	ldr r0, .L080550B4 @ =gUnk_085F0AA4
	str r0, [r3, #0x24]
	str r0, [r3, #0x20]
	strh r4, [r3, #6]
	strh r4, [r2, #0x2c]
	adds r0, r2, #0
	bl Proc_Break
.L080550AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080550B4: .4byte gUnk_085F0AA4

	thumb_func_start sub_80550B8
sub_80550B8: @ 0x080550B8
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L080550E0
	ldr r0, .L080550E8 @ =gUnk_Banim_02017744
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L080550E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080550E8: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80550EC
sub_80550EC: @ 0x080550EC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, .L0805511C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055120 @ =gUnk_085D2F2C
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	str r5, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	adds r0, r1, #0
	adds r0, #0x29
	strb r4, [r0]
	cmp r4, #0
	bne .L08055124
	movs r0, #0x2b
	strh r0, [r1, #0x2e]
	movs r0, #0x44
	b .L0805512A
	.align 2, 0
.L0805511C: .4byte gUnk_Banim_02017744
.L08055120: .4byte gUnk_085D2F2C
.L08055124:
	movs r0, #0x1f
	strh r0, [r1, #0x2e]
	movs r0, #0x3d
.L0805512A:
	strh r0, [r1, #0x30]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8055134
sub_8055134: @ 0x08055134
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L080551F2
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0805519A
	ldr r0, .L0805517C @ =gUnk_085F1FC0
	mov r8, r0
	ldr r7, .L08055180 @ =gUnk_085F35C0
	ldr r0, .L08055184 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08055188
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	movs r5, #0x88
	cmp r0, #0
	bne .L08055196
	movs r5, #0x68
	b .L08055196
	.align 2, 0
.L0805517C: .4byte gUnk_085F1FC0
.L08055180: .4byte gUnk_085F35C0
.L08055184: .4byte 0x0203CD14
.L08055188:
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	movs r5, #0x70
	cmp r0, #0
	bne .L08055196
	movs r5, #0x80
.L08055196:
	movs r6, #0x4e
	b .L080551D8
.L0805519A:
	ldr r2, .L080551BC @ =gUnk_085F2034
	mov r8, r2
	ldr r7, .L080551C0 @ =gUnk_085F3634
	ldr r0, .L080551C4 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L080551C8
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	movs r5, #0x4c
	cmp r0, #0
	bne .L080551D6
	movs r5, #0xa4
	b .L080551D6
	.align 2, 0
.L080551BC: .4byte gUnk_085F2034
.L080551C0: .4byte gUnk_085F3634
.L080551C4: .4byte 0x0203CD14
.L080551C8:
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	movs r5, #0x64
	cmp r0, #0
	bne .L080551D6
	movs r5, #0x8c
.L080551D6:
	movs r6, #0x40
.L080551D8:
	ldr r0, [r4, #0x5c]
	mov r2, r8
	str r2, [sp]
	adds r1, r7, #0
	adds r3, r7, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	strh r5, [r0, #2]
	strh r6, [r0, #4]
	adds r0, r4, #0
	bl Proc_Break
.L080551F2:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8055200
sub_8055200: @ 0x08055200
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08055228
	ldr r0, .L08055230 @ =gUnk_Banim_02017744
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08055228:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055230: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8055234
sub_8055234: @ 0x08055234
	push {r4, lr}
	adds r4, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L08055260 @ =gUnk_085D2F4C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	movs r1, #0
	strh r1, [r0, #0x2c]
	adds r0, #0x29
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055260: .4byte gUnk_085D2F4C

	thumb_func_start sub_8055264
sub_8055264: @ 0x08055264
	push {r4, lr}
	adds r4, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L08055290 @ =gUnk_085D2F4C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	adds r0, #0x29
	movs r1, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055290: .4byte gUnk_085D2F4C

	thumb_func_start sub_8055294
sub_8055294: @ 0x08055294
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #1
	bne .L080552C2
	ldr r0, [r4, #0x5c]
	bl sub_8054FEC
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf3
	movs r3, #1
	bl sub_805C804
	b .L08055358
.L080552C2:
	cmp r1, #0x34
	bne .L080552DA
	ldr r0, [r4, #0x5c]
	bl sub_8055364
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r1, [r1]
	bl sub_8055434
	b .L08055358
.L080552DA:
	cmp r1, #0xb7
	bne .L08055344
	movs r0, #0x8a
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x78
	movs r3, #0
	bl sub_805C804
	ldr r0, [r4, #0x5c]
	bl sub_80554C8
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r1, [r1]
	bl sub_8055628
	ldr r3, .L08055340 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r5, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r5, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0x14
	movs r3, #0
	bl sub_8054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0xb4
	movs r2, #0x28
	movs r3, #1
	bl sub_8054EA0
	b .L08055358
	.align 2, 0
.L08055340: .4byte gDispIo
.L08055344:
	ldr r0, .L08055360 @ =0x000001C5
	cmp r1, r0
	bne .L08055358
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L08055358:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055360: .4byte 0x000001C5

	thumb_func_start sub_8055364
sub_8055364: @ 0x08055364
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080553A0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080553A4 @ =gUnk_085D2F64
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L080553A8 @ =gUnk_0811A9A8
	str r1, [r0, #0x48]
	ldr r1, .L080553AC @ =gUnk_085D2F7C
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r0, .L080553B0 @ =gUnk_081AB1B0
	movs r1, #0x80
	lsls r1, r1, #3
	bl sub_8047ACC
	bl sub_8047500
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080553A0: .4byte gUnk_Banim_02017744
.L080553A4: .4byte gUnk_085D2F64
.L080553A8: .4byte gUnk_0811A9A8
.L080553AC: .4byte gUnk_085D2F7C
.L080553B0: .4byte gUnk_081AB1B0

	thumb_func_start sub_80553B4
sub_80553B4: @ 0x080553B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r6, r0, #0
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	blt .L0805540C
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	lsls r0, r5, #2
	adds r1, r0, r1
	ldr r1, [r1]
	adds r0, r0, r2
	ldr r2, [r0]
	adds r0, r6, #0
	bl sub_804799C
	ldr r0, .L08055404 @ =gUnk_0811A9BA
	lsls r1, r5, #1
	adds r0, r1, r0
	ldrh r0, [r0]
	ldr r2, .L08055408 @ =gUnk_0811A9C2
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #0
	bl sub_805C804
	b .L0805542A
	.align 2, 0
.L08055404: .4byte gUnk_0811A9BA
.L08055408: .4byte gUnk_0811A9C2
.L0805540C:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L0805542A
	bl sub_80474D8
	ldr r1, .L08055430 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L0805542A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08055430: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8055434
sub_8055434: @ 0x08055434
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08055460 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055464 @ =gUnk_085D2F8C
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	str r4, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	str r0, [r1, #0x44]
	ldr r0, .L08055468 @ =gUnk_0811A9CA
	str r0, [r1, #0x48]
	cmp r5, #0
	bne .L08055470
	ldr r0, .L0805546C @ =gUnk_081AE88C
	b .L08055472
	.align 2, 0
.L08055460: .4byte gUnk_Banim_02017744
.L08055464: .4byte gUnk_085D2F8C
.L08055468: .4byte gUnk_0811A9CA
.L0805546C: .4byte gUnk_081AE88C
.L08055470:
	ldr r0, .L0805547C @ =gUnk_081AEA8C
.L08055472:
	str r0, [r1, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805547C: .4byte gUnk_081AEA8C

	thumb_func_start sub_8055480
sub_8055480: @ 0x08055480
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L080554A6
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
	b .L080554BC
.L080554A6:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080554BC
	ldr r1, .L080554C4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080554BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080554C4: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80554C8
sub_80554C8: @ 0x080554C8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, .L0805555C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055560 @ =gUnk_085D2FAC
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L08055564 @ =gUnk_0811AACC
	str r1, [r0, #0x48]
	ldr r1, .L08055568 @ =gUnk_085D2FC4
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r0, .L0805556C @ =gUnk_081AC114
	movs r1, #0xa8
	lsls r1, r1, #5
	bl sub_8047ACC
	ldr r4, .L08055570 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r4, #0xc]
	ands r0, r2
	strb r0, [r4, #0xc]
	adds r0, r1, #0
	ldrb r2, [r4, #0x14]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r4, #0x14]
	ldrb r0, [r4, #0x10]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r4, #0x10]
	movs r0, #3
	ldrb r1, [r4, #0x18]
	orrs r0, r1
	strb r0, [r4, #0x18]
	bl sub_8047C1C
	ldr r0, .L08055574 @ =0x0000F3FF
	ldrh r2, [r5, #8]
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	bl sub_8047500
	ldr r0, .L08055578 @ =0x0000FFE0
	ldrh r1, [r4, #0x3c]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	ldr r1, .L0805557C @ =0x0000E0FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4, #0x3c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805555C: .4byte gUnk_Banim_02017744
.L08055560: .4byte gUnk_085D2FAC
.L08055564: .4byte gUnk_0811AACC
.L08055568: .4byte gUnk_085D2FC4
.L0805556C: .4byte gUnk_081AC114
.L08055570: .4byte gDispIo
.L08055574: .4byte 0x0000F3FF
.L08055578: .4byte 0x0000FFE0
.L0805557C: .4byte 0x0000E0FF

	thumb_func_start sub_8055580
sub_8055580: @ 0x08055580
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	ldr r6, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L080555BA
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	lsls r0, r3, #2
	adds r1, r0, r1
	ldr r1, [r1]
	adds r0, r0, r2
	ldr r2, [r0]
	adds r0, r5, #0
	bl sub_804799C
	b .L08055614
.L080555BA:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne .L08055614
	bl sub_80474D8
	ldr r1, .L0805561C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r3, .L08055620 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r2, [r3, #0x10]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x10]
	ldrb r0, [r3, #0x14]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x14]
	movs r0, #3
	ldrb r1, [r3, #0x18]
	orrs r0, r1
	strb r0, [r3, #0x18]
	ldr r0, .L08055624 @ =0x0000F3FF
	ldrh r2, [r6, #8]
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r6, #8]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L08055614:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805561C: .4byte gUnk_Banim_02017744
.L08055620: .4byte gDispIo
.L08055624: .4byte 0x0000F3FF

	thumb_func_start sub_8055628
sub_8055628: @ 0x08055628
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08055654 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055658 @ =gUnk_085D2FC8
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	str r4, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	str r0, [r1, #0x44]
	ldr r0, .L0805565C @ =gUnk_0811AAD2
	str r0, [r1, #0x48]
	cmp r5, #0
	bne .L08055664
	ldr r0, .L08055660 @ =gUnk_081ABCA0
	b .L08055666
	.align 2, 0
.L08055654: .4byte gUnk_Banim_02017744
.L08055658: .4byte gUnk_085D2FC8
.L0805565C: .4byte gUnk_0811AAD2
.L08055660: .4byte gUnk_081ABCA0
.L08055664:
	ldr r0, .L08055670 @ =gUnk_081AEC8C
.L08055666:
	str r0, [r1, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055670: .4byte gUnk_081AEC8C

	thumb_func_start sub_8055674
sub_8055674: @ 0x08055674
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0805569A
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
	b .L080556B0
.L0805569A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080556B0
	ldr r1, .L080556B8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080556B0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080556B8: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80556BC
sub_80556BC: @ 0x080556BC
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L080556F4 @ =gUnk_085D2FE8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080556F4: .4byte gUnk_085D2FE8

	thumb_func_start sub_80556F8
sub_80556F8: @ 0x080556F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r6, r0, #0
	bl sub_8047C28
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0805572E
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L0805572E:
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	adds r0, r5, #1
	cmp r1, r0
	bne .L080557A4
	adds r0, r6, #0
	bl sub_805581C
	movs r5, #8
	str r5, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x28
	movs r2, #0x1e
	movs r3, #0x10
	bl sub_804CD88
	movs r4, #0x10
	str r4, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x47
	movs r2, #0x1e
	movs r3, #8
	bl sub_804CD88
	str r5, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x66
	movs r2, #0x1e
	movs r3, #0x10
	bl sub_804CD88
	str r4, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x85
	movs r2, #0x1e
	movs r3, #8
	bl sub_804CD88
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0xa4
	movs r2, #0x3c
	movs r3, #0x10
	bl sub_804CD88
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r6, r0]
	movs r0, #0xfd
	movs r3, #1
	bl sub_805C804
	b .L08055810
.L080557A4:
	adds r0, r5, #0
	adds r0, #0x50
	cmp r1, r0
	bne .L080557B4
	adds r0, r6, #0
	bl sub_80558D4
	b .L08055810
.L080557B4:
	adds r0, r5, #0
	adds r0, #0xa4
	cmp r1, r0
	bne .L080557CA
	adds r0, r6, #0
	movs r1, #1
	movs r2, #5
	movs r3, #0
	bl sub_8046C14
	b .L08055810
.L080557CA:
	adds r0, r5, #0
	adds r0, #0xc8
	cmp r1, r0
	bne .L080557F0
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r1, [r0]
	adds r0, r6, #0
	bl sub_80478A0
	adds r0, r6, #0
	movs r1, #0
	bl sub_8046F18
	b .L08055810
.L080557F0:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r5, r2
	cmp r1, r0
	bne .L08055810
	movs r0, #2
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L08055810:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_805581C
sub_805581C: @ 0x0805581C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08055858 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805585C @ =gUnk_085D3000
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L08055860 @ =gUnk_0811ABB0
	str r1, [r0, #0x48]
	ldr r1, .L08055864 @ =gUnk_085D3018
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L08055868 @ =gUnk_085D304C
	str r1, [r0, #0x54]
	ldr r0, .L0805586C @ =gUnk_081B1710
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055858: .4byte gUnk_Banim_02017744
.L0805585C: .4byte gUnk_085D3000
.L08055860: .4byte gUnk_0811ABB0
.L08055864: .4byte gUnk_085D3018
.L08055868: .4byte gUnk_085D304C
.L0805586C: .4byte gUnk_081B1710

	thumb_func_start sub_8055870
sub_8055870: @ 0x08055870
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L080558AC
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	ldr r5, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	lsls r4, r3, #2
	adds r1, r4, r1
	ldr r1, [r1]
	adds r2, r4, r2
	ldr r2, [r2]
	bl sub_804799C
	adds r4, r4, r5
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	b .L080558CA
.L080558AC:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne .L080558CA
	bl sub_80474D8
	ldr r1, .L080558D0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L080558CA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080558D0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80558D4
sub_80558D4: @ 0x080558D4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L08055910 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055914 @ =gUnk_085D3080
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	ldr r3, .L08055918 @ =gUnk_085F63A8
	str r3, [sp]
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	adds r6, r0, #0
	str r6, [r5, #0x60]
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0805591C
	ldrh r0, [r6, #2]
	subs r0, #8
	b .L08055920
	.align 2, 0
.L08055910: .4byte gUnk_Banim_02017744
.L08055914: .4byte gUnk_085D3080
.L08055918: .4byte gUnk_085F63A8
.L0805591C:
	ldrh r0, [r6, #2]
	adds r0, #8
.L08055920:
	strh r0, [r6, #2]
	ldrh r0, [r6, #4]
	subs r0, #8
	strh r0, [r6, #4]
	ldr r0, .L08055944 @ =gUnk_081B7650
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08055948 @ =gUnk_081B7468
	movs r1, #0x80
	lsls r1, r1, #4
	bl sub_8047A88
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08055944: .4byte gUnk_081B7650
.L08055948: .4byte gUnk_081B7468

	thumb_func_start sub_805594C
sub_805594C: @ 0x0805594C
	ldr r1, .L08055958 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L08055958: .4byte gUnk_Banim_02017744

	thumb_func_start sub_805595C
sub_805595C: @ 0x0805595C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L08055994 @ =gUnk_085D30A0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055994: .4byte gUnk_085D30A0

	thumb_func_start sub_8055998
sub_8055998: @ 0x08055998
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080559DC
	ldr r0, [r4, #0x5c]
	bl sub_8055B84
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xfa
	movs r3, #1
	bl sub_805C804
.L080559DC:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x29
	bne .L080559EE
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
	b .L08055A92
.L080559EE:
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	adds r0, r6, #0
	adds r0, #0x44
	cmp r1, r0
	bne .L08055A22
	ldr r0, [r4, #0x5c]
	bl sub_8055AA0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r5, r0]
	movs r0, #0xfb
	movs r3, #1
	bl sub_805C804
	ldr r0, [r4, #0x5c]
	str r7, [sp]
	str r7, [sp, #4]
	movs r1, #0x42
	movs r2, #0x14
	movs r3, #0x10
	bl sub_804CD88
	b .L08055A92
.L08055A22:
	adds r0, r6, #0
	adds r0, #0x86
	cmp r1, r0
	bne .L08055A74
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r0, #0xfc
	movs r3, #1
	bl sub_805C804
	bl sub_805BD8C
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r6, r4, #0
	adds r6, #0x29
	ldrb r1, [r6]
	adds r0, r5, #0
	bl sub_80478A0
	ldr r0, [r4, #0x5c]
	movs r1, #0xa
	bl sub_8046794
	ldrb r0, [r6]
	cmp r0, #0
	bne .L08055A92
	adds r0, r5, #0
	bl sub_8046F48
	cmp r0, #0
	bne .L08055A92
	adds r0, r5, #0
	movs r1, #3
	bl sub_8046F18
	b .L08055A92
.L08055A74:
	adds r0, r6, #0
	adds r0, #0x9e
	cmp r1, r0
	bne .L08055A92
	movs r0, #2
	ldrh r3, [r5, #0x10]
	orrs r0, r3
	strh r0, [r5, #0x10]
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L08055A92:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8055AA0
sub_8055AA0: @ 0x08055AA0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08055B00 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055B04 @ =gUnk_085D30B8
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08055B08 @ =gUnk_0811ABE6
	str r0, [r5, #0x48]
	ldr r0, .L08055B0C @ =gUnk_085D30D0
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08055B10 @ =gUnk_081B4254
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L08055B14 @ =gUnk_081B2348
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	bl sub_8047500
	ldr r0, .L08055B18 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08055B26
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08055B1C
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
	b .L08055B26
	.align 2, 0
.L08055B00: .4byte gUnk_Banim_02017744
.L08055B04: .4byte gUnk_085D30B8
.L08055B08: .4byte gUnk_0811ABE6
.L08055B0C: .4byte gUnk_085D30D0
.L08055B10: .4byte gUnk_081B4254
.L08055B14: .4byte gUnk_081B2348
.L08055B18: .4byte 0x0203CD14
.L08055B1C:
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
.L08055B26:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8055B2C
sub_8055B2C: @ 0x08055B2C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L08055B5A
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl sub_804799C
	b .L08055B78
.L08055B5A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L08055B78
	bl sub_80474D8
	ldr r1, .L08055B80 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L08055B78:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055B80: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8055B84
sub_8055B84: @ 0x08055B84
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08055BC8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055BCC @ =gUnk_085D3118
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L08055BD0 @ =gUnk_085F6674
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r0, .L08055BD4 @ =gUnk_081B4254
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08055BD8 @ =gUnk_081B3D34
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055BC8: .4byte gUnk_Banim_02017744
.L08055BCC: .4byte gUnk_085D3118
.L08055BD0: .4byte gUnk_085F6674
.L08055BD4: .4byte gUnk_081B4254
.L08055BD8: .4byte gUnk_081B3D34

	thumb_func_start sub_8055BDC
sub_8055BDC: @ 0x08055BDC
	push {lr}
	ldr r0, [r0, #0x60]
	bl BasRemove
	ldr r1, .L08055BF0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
.L08055BF0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8055BF4
sub_8055BF4: @ 0x08055BF4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L08055C2C @ =gUnk_085D3138
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055C2C: .4byte gUnk_085D3138

	thumb_func_start sub_8055C30
sub_8055C30: @ 0x08055C30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08055C74
	ldr r0, [r4, #0x5c]
	bl sub_8055E14
	ldr r0, .L08055CC8 @ =0x0000011B
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl sub_805C804
.L08055C74:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x64
	bne .L08055C84
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L08055C84:
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	adds r0, r6, #0
	adds r0, #0x82
	cmp r1, r0
	bne .L08055CCC
	adds r0, r5, #0
	bl sub_8055E6C
	adds r0, r5, #0
	bl sub_8055ED0
	ldr r0, [r4, #0x5c]
	bl sub_8055D30
	movs r0, #0x10
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x14
	movs r3, #0
	bl sub_804CD88
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xe6
	movs r2, #0x14
	movs r3, #0x10
	bl sub_804CD88
	b .L08055D22
	.align 2, 0
.L08055CC8: .4byte 0x0000011B
.L08055CCC:
	movs r3, #0xa5
	lsls r3, r3, #1
	adds r0, r6, r3
	cmp r1, r0
	bne .L08055D02
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_80478A0
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08055D22
	adds r0, r5, #0
	bl sub_8046F48
	cmp r0, #0
	bne .L08055D22
	adds r0, r5, #0
	movs r1, #2
	bl sub_8046F18
	b .L08055D22
.L08055D02:
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r0, r6, r2
	cmp r1, r0
	bne .L08055D22
	movs r0, #2
	ldrh r3, [r5, #0x10]
	orrs r0, r3
	strh r0, [r5, #0x10]
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L08055D22:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8055D30
sub_8055D30: @ 0x08055D30
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08055D90 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055D94 @ =gUnk_085D3150
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08055D98 @ =gUnk_0811AC30
	str r0, [r5, #0x48]
	ldr r0, .L08055D9C @ =gUnk_085D3168
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08055DA0 @ =gUnk_081B6688
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L08055DA4 @ =gUnk_081B57BC
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	bl sub_8047500
	ldr r0, .L08055DA8 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08055DB6
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08055DAC
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
	b .L08055DB6
	.align 2, 0
.L08055D90: .4byte gUnk_Banim_02017744
.L08055D94: .4byte gUnk_085D3150
.L08055D98: .4byte gUnk_0811AC30
.L08055D9C: .4byte gUnk_085D3168
.L08055DA0: .4byte gUnk_081B6688
.L08055DA4: .4byte gUnk_081B57BC
.L08055DA8: .4byte 0x0203CD14
.L08055DAC:
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
.L08055DB6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8055DBC
sub_8055DBC: @ 0x08055DBC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L08055DEA
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl sub_804799C
	b .L08055E08
.L08055DEA:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L08055E08
	bl sub_80474D8
	ldr r1, .L08055E10 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L08055E08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055E10: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8055E14
sub_8055E14: @ 0x08055E14
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08055E58 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055E5C @ =gUnk_085D31A8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L08055E60 @ =gUnk_085FE544
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r0, .L08055E64 @ =gUnk_081B7650
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08055E68 @ =gUnk_081B7468
	movs r1, #0x80
	lsls r1, r1, #4
	bl sub_8047A88
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055E58: .4byte gUnk_Banim_02017744
.L08055E5C: .4byte gUnk_085D31A8
.L08055E60: .4byte gUnk_085FE544
.L08055E64: .4byte gUnk_081B7650
.L08055E68: .4byte gUnk_081B7468

	thumb_func_start sub_8055E6C
sub_8055E6C: @ 0x08055E6C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08055EB4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055EB8 @ =gUnk_085D31C8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L08055EBC @ =gUnk_085FE3C4
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	adds r5, r0, #0
	str r5, [r4, #0x60]
	ldrh r0, [r5, #4]
	subs r0, #8
	strh r0, [r5, #4]
	bl sub_8058998
	cmp r0, #0
	beq .L08055EAC
	ldrh r0, [r5, #2]
	subs r0, #0x10
	strh r0, [r5, #2]
.L08055EAC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055EB4: .4byte gUnk_Banim_02017744
.L08055EB8: .4byte gUnk_085D31C8
.L08055EBC: .4byte gUnk_085FE3C4

	thumb_func_start sub_8055EC0
sub_8055EC0: @ 0x08055EC0
	ldr r1, .L08055ECC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L08055ECC: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8055ED0
sub_8055ED0: @ 0x08055ED0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08055EEC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055EF0 @ =gUnk_085D31E8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055EEC: .4byte gUnk_Banim_02017744
.L08055EF0: .4byte gUnk_085D31E8

	thumb_func_start sub_8055EF4
sub_8055EF4: @ 0x08055EF4
	push {r4, lr}
	movs r3, #0x8e
	lsls r3, r3, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r0, #0x5c]
	movs r4, #2
	ldrsh r2, [r0, r4]
	adds r0, r3, #0
	movs r3, #1
	bl sub_805C804
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8055F14
sub_8055F14: @ 0x08055F14
	ldr r1, .L08055F20 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L08055F20: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8055F24
sub_8055F24: @ 0x08055F24
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L08055F5C @ =gUnk_085D3230
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055F5C: .4byte gUnk_085D3230

	thumb_func_start sub_8055F60
sub_8055F60: @ 0x08055F60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r6, r0, #0
	bl sub_8047C28
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08055F96
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L08055F96:
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	adds r0, r5, #1
	cmp r1, r0
	bne .L08056010
	adds r0, r6, #0
	bl sub_8056080
	movs r5, #8
	str r5, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x28
	movs r2, #0x1e
	movs r3, #0x10
	bl sub_804CD88
	movs r4, #0x10
	str r4, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x47
	movs r2, #0x1e
	movs r3, #8
	bl sub_804CD88
	str r5, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x66
	movs r2, #0x1e
	movs r3, #0x10
	bl sub_804CD88
	str r4, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x85
	movs r2, #0x1e
	movs r3, #8
	bl sub_804CD88
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0xa4
	movs r2, #0x3c
	movs r3, #0x10
	bl sub_804CD88
	ldr r0, .L0805600C @ =0x00000103
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r6, r3]
	movs r3, #1
	bl sub_805C804
	b .L08056074
	.align 2, 0
.L0805600C: .4byte 0x00000103
.L08056010:
	adds r0, r5, #0
	adds r0, #0x50
	cmp r1, r0
	bne .L08056020
	adds r0, r6, #0
	bl sub_8056138
	b .L08056074
.L08056020:
	adds r0, r5, #0
	adds r0, #0xa4
	cmp r1, r0
	bne .L08056036
	adds r0, r6, #0
	movs r1, #1
	movs r2, #5
	movs r3, #0
	bl sub_8046C14
	b .L08056074
.L08056036:
	adds r0, r5, #0
	adds r0, #0xc8
	cmp r1, r0
	bne .L08056054
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r1, [r0]
	adds r0, r6, #0
	bl sub_80478A0
	b .L08056074
.L08056054:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r5, r2
	cmp r1, r0
	bne .L08056074
	movs r0, #2
	ldrh r3, [r6, #0x10]
	orrs r0, r3
	strh r0, [r6, #0x10]
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L08056074:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_8056080
sub_8056080: @ 0x08056080
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080560BC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080560C0 @ =gUnk_085D3248
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L080560C4 @ =gUnk_0811AD32
	str r1, [r0, #0x48]
	ldr r1, .L080560C8 @ =gUnk_085D3260
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L080560CC @ =gUnk_085D3294
	str r1, [r0, #0x54]
	ldr r0, .L080560D0 @ =gUnk_081B4274
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080560BC: .4byte gUnk_Banim_02017744
.L080560C0: .4byte gUnk_085D3248
.L080560C4: .4byte gUnk_0811AD32
.L080560C8: .4byte gUnk_085D3260
.L080560CC: .4byte gUnk_085D3294
.L080560D0: .4byte gUnk_081B4274

	thumb_func_start sub_80560D4
sub_80560D4: @ 0x080560D4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L08056110
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	ldr r5, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	lsls r4, r3, #2
	adds r1, r4, r1
	ldr r1, [r1]
	adds r2, r4, r2
	ldr r2, [r2]
	bl sub_804799C
	adds r4, r4, r5
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	b .L0805612E
.L08056110:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne .L0805612E
	bl sub_80474D8
	ldr r1, .L08056134 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L0805612E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056134: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8056138
sub_8056138: @ 0x08056138
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0805617C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08056180 @ =gUnk_085D32C8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L08056184 @ =gUnk_085F9358
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r0, .L08056188 @ =gUnk_081B7670
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0805618C @ =gUnk_081B7468
	movs r1, #0x80
	lsls r1, r1, #4
	bl sub_8047A88
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805617C: .4byte gUnk_Banim_02017744
.L08056180: .4byte gUnk_085D32C8
.L08056184: .4byte gUnk_085F9358
.L08056188: .4byte gUnk_081B7670
.L0805618C: .4byte gUnk_081B7468

	thumb_func_start sub_8056190
sub_8056190: @ 0x08056190
	ldr r1, .L0805619C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L0805619C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80561A0
sub_80561A0: @ 0x080561A0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L080561D8 @ =gUnk_085D32E8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080561D8: .4byte gUnk_085D32E8

	thumb_func_start sub_80561DC
sub_80561DC: @ 0x080561DC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	bl sub_8047C28
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0805620A
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L0805620A:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #1
	cmp r1, r0
	bne .L0805625C
	adds r0, r5, #0
	bl sub_80564E4
	adds r0, r5, #0
	movs r1, #0x4a
	bl sub_80562C0
	adds r0, r5, #0
	movs r1, #0x4a
	bl sub_8056444
	movs r4, #0x80
	lsls r4, r4, #1
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0x4a
	movs r2, #0xa
	adds r3, r4, #0
	bl sub_804C8D4
	ldr r2, .L08056258 @ =sub_804CD4C
	adds r0, r5, #0
	movs r1, #0x4a
	bl sub_804CC68
	movs r1, #2
	ldrsh r2, [r5, r1]
	movs r0, #0xf9
	adds r1, r4, #0
	movs r3, #1
	bl sub_805C804
	b .L080562B6
	.align 2, 0
.L08056258: .4byte sub_804CD4C
.L0805625C:
	adds r0, r6, #0
	adds r0, #0x4a
	cmp r1, r0
	bne .L08056298
	adds r0, r5, #0
	movs r1, #5
	bl sub_8046794
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_80478A0
	ldrb r0, [r4]
	cmp r0, #0
	bne .L080562B6
	adds r0, r5, #0
	bl sub_8046F48
	cmp r0, #0
	bne .L080562B6
	adds r0, r5, #0
	movs r1, #4
	bl sub_8046F18
	b .L080562B6
.L08056298:
	adds r0, r6, #0
	adds r0, #0x5a
	cmp r1, r0
	bne .L080562B6
	movs r0, #2
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	bl sub_80474BC
	bl sub_8047358
	adds r0, r4, #0
	bl Proc_Break
.L080562B6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80562C0
sub_80562C0: @ 0x080562C0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, .L080563B8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080563BC @ =gUnk_085D3300
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	movs r6, #0
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	ldr r0, .L080563C0 @ =gUnk_081B7690
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L080563C4 @ =gUnk_081B4E9C
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, .L080563C8 @ =gUnk_081B4F9C
	ldr r1, .L080563CC @ =gBg1Tm
	movs r2, #1
	str r2, [sp]
	adds r2, #0xff
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x20
	bl sub_805B1AC
	movs r0, #2
	bl EnableBgSync
	bl sub_8047500
	ldr r0, .L080563D0 @ =gDispIo
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
	movs r0, #0xe
	strb r0, [r1]
	adds r1, #1
	movs r4, #8
	movs r0, #8
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x46
	strb r6, [r0]
	mov r6, ip
	adds r6, #0x37
	movs r3, #0x20
	ldrb r1, [r6]
	orrs r1, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	mov r2, ip
	ldrb r2, [r2, #1]
	ands r0, r2
	movs r2, #0x41
	rsbs r2, r2, #0
	ands r0, r2
	movs r2, #0x80
	orrs r0, r2
	mov r7, ip
	strb r0, [r7, #1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	movs r0, #4
	orrs r1, r0
	orrs r1, r4
	movs r0, #0x10
	orrs r1, r0
	strb r1, [r6]
	ldr r0, .L080563D4 @ =0x0000FFE0
	ldrh r1, [r7, #0x3c]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	ldr r1, .L080563D8 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0xe0
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r7, #0x3c]
	mov r0, ip
	adds r0, #0x3d
	ldrb r7, [r0]
	orrs r3, r7
	strb r3, [r0]
	ldr r0, [r5, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [r5, #0x1c]
	ldr r0, .L080563DC @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080563B8: .4byte gUnk_Banim_02017744
.L080563BC: .4byte gUnk_085D3300
.L080563C0: .4byte gUnk_081B7690
.L080563C4: .4byte gUnk_081B4E9C
.L080563C8: .4byte gUnk_081B4F9C
.L080563CC: .4byte gBg1Tm
.L080563D0: .4byte gDispIo
.L080563D4: .4byte 0x0000FFE0
.L080563D8: .4byte 0x0000E0FF
.L080563DC: .4byte 0x0000F3FF

	thumb_func_start sub_80563E0
sub_80563E0: @ 0x080563E0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x5c]
	ldr r1, .L08056434 @ =gDispIo
	ldrh r0, [r1, #0x22]
	subs r0, #1
	strh r0, [r1, #0x22]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0805642C
	bl sub_80474D8
	bl sub_80475D8
	ldr r0, [r5, #0x1c]
	ldr r1, .L08056438 @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r5, #0x1c]
	ldr r0, .L0805643C @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	ldr r1, .L08056440 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0805642C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056434: .4byte gDispIo
.L08056438: .4byte 0xFFFFF7FF
.L0805643C: .4byte 0x0000F3FF
.L08056440: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8056444
sub_8056444: @ 0x08056444
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08056468 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805646C @ =gUnk_085D3318
	movs r1, #4
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056468: .4byte gUnk_Banim_02017744
.L0805646C: .4byte gUnk_085D3318

	thumb_func_start sub_8056470
sub_8056470: @ 0x08056470
	push {r4, lr}
	sub sp, #0x48
	adds r4, r0, #0
	ldr r2, [r4, #0x5c]
	mov r1, sp
	ldrh r0, [r2, #2]
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	strh r0, [r1, #4]
	ldr r0, [r2, #0x3c]
	str r0, [sp, #0x3c]
	ldr r0, [r2, #0x1c]
	ldr r1, .L080564CC @ =0xFFFFF7FF
	ands r0, r1
	str r0, [sp, #0x1c]
	mov r0, sp
	ldrh r1, [r2, #8]
	strh r1, [r0, #8]
	mov r2, sp
	ldr r0, .L080564D0 @ =0x0000F3FF
	ands r0, r1
	strh r0, [r2, #8]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2, #8]
	mov r0, sp
	bl BasPutOam
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L080564C2
	adds r0, r4, #0
	bl Proc_Break
.L080564C2:
	add sp, #0x48
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080564CC: .4byte 0xFFFFF7FF
.L080564D0: .4byte 0x0000F3FF

	thumb_func_start sub_80564D4
sub_80564D4: @ 0x080564D4
	ldr r1, .L080564E0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L080564E0: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80564E4
sub_80564E4: @ 0x080564E4
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0805652C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08056530 @ =gUnk_085D3338
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	adds r0, r5, #0
	bl sub_804B80C
	ldr r3, .L08056534 @ =gUnk_085D0E8C
	ldr r0, [r4, #0x5c]
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r1, .L08056538 @ =0x0000F3FF
	ldrh r2, [r0, #8]
	ands r1, r2
	movs r3, #0x80
	lsls r3, r3, #3
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r0, #8]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805652C: .4byte gUnk_Banim_02017744
.L08056530: .4byte gUnk_085D3338
.L08056534: .4byte gUnk_085D0E8C
.L08056538: .4byte 0x0000F3FF

	thumb_func_start sub_805653C
sub_805653C: @ 0x0805653C
	push {lr}
	ldr r2, .L08056550 @ =gUnk_Banim_02017744
	ldr r1, [r2]
	subs r1, #1
	str r1, [r2]
	ldr r0, [r0, #0x60]
	bl BasRemove
	pop {r0}
	bx r0
	.align 2, 0
.L08056550: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8056554
sub_8056554: @ 0x08056554
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08056584 @ =gUnk_085FEAF8
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08056588 @ =gUnk_081B7F68
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0805658C @ =gUnk_081B76B0
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056584: .4byte gUnk_085FEAF8
.L08056588: .4byte gUnk_081B7F68
.L0805658C: .4byte gUnk_081B76B0

	thumb_func_start sub_8056590
sub_8056590: @ 0x08056590
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L080565C0 @ =gUnk_085FEB0C
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L080565C4 @ =gUnk_081B7F68
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L080565C8 @ =gUnk_081B76B0
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080565C0: .4byte gUnk_085FEB0C
.L080565C4: .4byte gUnk_081B7F68
.L080565C8: .4byte gUnk_081B76B0

	thumb_func_start sub_80565CC
sub_80565CC: @ 0x080565CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L080565FC @ =gUnk_085FEB20
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08056600 @ =gUnk_081B7F68
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08056604 @ =gUnk_081B76B0
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080565FC: .4byte gUnk_085FEB20
.L08056600: .4byte gUnk_081B7F68
.L08056604: .4byte gUnk_081B76B0

	thumb_func_start sub_8056608
sub_8056608: @ 0x08056608
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08056638 @ =gUnk_085FEB34
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L0805663C @ =gUnk_081B7F68
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08056640 @ =gUnk_081B76B0
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056638: .4byte gUnk_085FEB34
.L0805663C: .4byte gUnk_081B7F68
.L08056640: .4byte gUnk_081B76B0

	thumb_func_start sub_8056644
sub_8056644: @ 0x08056644
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08056674 @ =gUnk_085FEB48
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08056678 @ =gUnk_081B7F68
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0805667C @ =gUnk_081B76B0
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056674: .4byte gUnk_085FEB48
.L08056678: .4byte gUnk_081B7F68
.L0805667C: .4byte gUnk_081B76B0

	thumb_func_start sub_8056680
sub_8056680: @ 0x08056680
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L080566B0 @ =gUnk_085FEEBC
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L080566B4 @ =gUnk_081B7F68
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L080566B8 @ =gUnk_081B7B48
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080566B0: .4byte gUnk_085FEEBC
.L080566B4: .4byte gUnk_081B7F68
.L080566B8: .4byte gUnk_081B7B48

	thumb_func_start sub_80566BC
sub_80566BC: @ 0x080566BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L080566EC @ =gUnk_085FEEC8
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L080566F0 @ =gUnk_081B7F68
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L080566F4 @ =gUnk_081B7B48
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080566EC: .4byte gUnk_085FEEC8
.L080566F0: .4byte gUnk_081B7F68
.L080566F4: .4byte gUnk_081B7B48

	thumb_func_start sub_80566F8
sub_80566F8: @ 0x080566F8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08056728 @ =gUnk_085FEED4
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L0805672C @ =gUnk_081B7F68
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08056730 @ =gUnk_081B7B48
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056728: .4byte gUnk_085FEED4
.L0805672C: .4byte gUnk_081B7F68
.L08056730: .4byte gUnk_081B7B48

	thumb_func_start sub_8056734
sub_8056734: @ 0x08056734
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08056764 @ =gUnk_085FEEE0
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08056768 @ =gUnk_081B7F68
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0805676C @ =gUnk_081B7B48
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056764: .4byte gUnk_085FEEE0
.L08056768: .4byte gUnk_081B7F68
.L0805676C: .4byte gUnk_081B7B48

	thumb_func_start sub_8056770
sub_8056770: @ 0x08056770
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L080567A0 @ =gUnk_085FEEEC
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L080567A4 @ =gUnk_081B7F68
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L080567A8 @ =gUnk_081B7B48
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080567A0: .4byte gUnk_085FEEEC
.L080567A4: .4byte gUnk_081B7F68
.L080567A8: .4byte gUnk_081B7B48

	thumb_func_start sub_80567AC
sub_80567AC: @ 0x080567AC
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_80474B0
	bl sub_8047300
	bl sub_80474C8
	ldr r0, .L080567E4 @ =gUnk_085D33F0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl sub_804B868
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_804B6D8
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080567E4: .4byte gUnk_085D33F0

	thumb_func_start sub_80567E8
sub_80567E8: @ 0x080567E8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl sub_804B80C
	adds r4, r0, #0
	bl sub_8047C28
	adds r6, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08056814
	ldr r0, [r5, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8045C90
.L08056814:
	movs r0, #0x2c
	ldrsh r1, [r5, r0]
	adds r0, r6, #1
	cmp r1, r0
	bne .L08056844
	ldr r0, [r5, #0x5c]
	bl sub_80568B4
	adds r0, r4, #0
	bl sub_8056968
	adds r0, r4, #0
	bl sub_80569C0
	movs r0, #0x81
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r4, r3]
	movs r3, #1
	bl sub_805C804
	b .L080568AE
.L08056844:
	adds r0, r6, #0
	adds r0, #0x28
	cmp r1, r0
	beq .L08056854
	adds r0, r6, #0
	adds r0, #0x50
	cmp r1, r0
	bne .L0805685C
.L08056854:
	adds r0, r4, #0
	bl sub_80569C0
	b .L080568AE
.L0805685C:
	adds r0, r6, #0
	adds r0, #0xb0
	cmp r1, r0
	bne .L08056872
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #0
	bl sub_8046C14
	b .L080568AE
.L08056872:
	adds r0, r6, #0
	adds r0, #0xe1
	cmp r1, r0
	bne .L08056890
	movs r0, #9
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r1, [r0]
	adds r0, r4, #0
	bl sub_80478A0
	b .L080568AE
.L08056890:
	adds r0, r6, #0
	adds r0, #0xe6
	cmp r1, r0
	bne .L080568AE
	movs r0, #2
	ldrh r3, [r4, #0x10]
	orrs r0, r3
	strh r0, [r4, #0x10]
	bl sub_80474BC
	bl sub_8047358
	adds r0, r5, #0
	bl Proc_Break
.L080568AE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_80568B4
sub_80568B4: @ 0x080568B4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080568F8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080568FC @ =gUnk_085D3408
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L08056900 @ =gUnk_0811AD68
	str r1, [r0, #0x48]
	ldr r1, .L08056904 @ =gUnk_085D3420
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r0, .L08056908 @ =gUnk_081B8934
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L0805690C @ =gUnk_081B80A8
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	bl sub_8047500
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080568F8: .4byte gUnk_Banim_02017744
.L080568FC: .4byte gUnk_085D3408
.L08056900: .4byte gUnk_0811AD68
.L08056904: .4byte gUnk_085D3420
.L08056908: .4byte gUnk_081B8934
.L0805690C: .4byte gUnk_081B80A8

	thumb_func_start sub_8056910
sub_8056910: @ 0x08056910
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L0805693E
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl sub_804799C
	b .L0805695C
.L0805693E:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L0805695C
	bl sub_80474D8
	ldr r1, .L08056964 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L0805695C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056964: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8056968
sub_8056968: @ 0x08056968
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L080569AC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080569B0 @ =gUnk_085D3434
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L080569B4 @ =gUnk_08602FAC
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r0, .L080569B8 @ =gUnk_081B8E44
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L080569BC @ =gUnk_081B7468
	movs r1, #0x80
	lsls r1, r1, #4
	bl sub_8047A88
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080569AC: .4byte gUnk_Banim_02017744
.L080569B0: .4byte gUnk_085D3434
.L080569B4: .4byte gUnk_08602FAC
.L080569B8: .4byte gUnk_081B8E44
.L080569BC: .4byte gUnk_081B7468

	thumb_func_start sub_80569C0
sub_80569C0: @ 0x080569C0
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L080569F4 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080569F8 @ =gUnk_085D3454
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L080569FC @ =gUnk_086030FC
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080569F4: .4byte gUnk_Banim_02017744
.L080569F8: .4byte gUnk_085D3454
.L080569FC: .4byte gUnk_086030FC

	thumb_func_start sub_8056A00
sub_8056A00: @ 0x08056A00
	push {lr}
	ldr r0, [r0, #0x60]
	bl BasRemove
	ldr r1, .L08056A14 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
.L08056A14: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8056A18
sub_8056A18: @ 0x08056A18
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08056A38 @ =gUnk_085D3474
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	adds r0, #0x29
	strb r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056A38: .4byte gUnk_085D3474

	thumb_func_start sub_8056A3C
sub_8056A3C: @ 0x08056A3C
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08056A5A
	ldr r0, [r1, #0x5c]
	adds r1, #0x29
	ldrb r1, [r1]
	bl sub_8056A68
	b .L08056A64
.L08056A5A:
	cmp r0, #0xa
	bne .L08056A64
	adds r0, r1, #0
	bl Proc_Break
.L08056A64:
	pop {r0}
	bx r0

	thumb_func_start sub_8056A68
sub_8056A68: @ 0x08056A68
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, .L08056A8C @ =gUnk_085D348C
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r5, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	cmp r4, #0
	bne .L08056A94
	movs r0, #0x32
	strh r0, [r6, #0x2e]
	ldr r4, .L08056A90 @ =gUnk_085CDCA4
	b .L08056A9A
	.align 2, 0
.L08056A8C: .4byte gUnk_085D348C
.L08056A90: .4byte gUnk_085CDCA4
.L08056A94:
	movs r0, #0x32
	strh r0, [r6, #0x2e]
	ldr r4, .L08056AD4 @ =gUnk_085CDD18
.L08056A9A:
	adds r0, r5, #0
	bl sub_804B6C4
	movs r2, #0xa2
	lsls r2, r2, #7
	cmp r0, #0
	bne .L08056AAC
	movs r2, #0xc2
	lsls r2, r2, #7
.L08056AAC:
	movs r1, #2
	ldrsh r0, [r5, r1]
	movs r3, #4
	ldrsh r1, [r5, r3]
	subs r1, #0x28
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	movs r2, #3
	str r2, [sp, #8]
	adds r2, r4, #0
	movs r3, #2
	bl sub_805B9E0
	str r0, [r6, #0x60]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08056AD4: .4byte gUnk_085CDD18

	thumb_func_start sub_8056AD8
sub_8056AD8: @ 0x08056AD8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, [r4, #0x5c]
	ldrh r0, [r0, #2]
	strh r0, [r1, #0x32]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08056B00
	ldr r0, [r4, #0x60]
	bl Proc_End
	adds r0, r4, #0
	bl Proc_Break
.L08056B00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8056B08
sub_8056B08: @ 0x08056B08
	push {r4, lr}
	adds r4, r0, #0
	bl sub_80474C8
	ldr r0, .L08056B24 @ =gUnk_085D34A4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056B24: .4byte gUnk_085D34A4

	thumb_func_start sub_8056B28
sub_8056B28: @ 0x08056B28
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08056B48
	ldr r0, [r4, #0x5c]
	bl sub_8056B58
	ldr r0, [r4, #0x5c]
	bl sub_8056BD0
	b .L08056B52
.L08056B48:
	cmp r0, #0x11
	bne .L08056B52
	adds r0, r4, #0
	bl Proc_Break
.L08056B52:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8056B58
sub_8056B58: @ 0x08056B58
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08056B94 @ =gUnk_085D34BC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, .L08056B98 @ =gUnk_08122A3C
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, .L08056B9C @ =gUnk_08123B1C
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, [r4, #0x5c]
	ldr r1, .L08056BA0 @ =gUnk_08123D1C
	ldr r2, .L08056BA4 @ =gUnk_081241BC
	bl sub_804799C
	bl sub_8047500
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056B94: .4byte gUnk_085D34BC
.L08056B98: .4byte gUnk_08122A3C
.L08056B9C: .4byte gUnk_08123B1C
.L08056BA0: .4byte gUnk_08123D1C
.L08056BA4: .4byte gUnk_081241BC

	thumb_func_start sub_8056BA8
sub_8056BA8: @ 0x08056BA8
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x11
	bne .L08056BC8
	bl sub_80474D8
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L08056BC8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8056BD0
sub_8056BD0: @ 0x08056BD0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08056BF4 @ =gUnk_085D34D4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L08056BF8 @ =gUnk_0811AE34
	str r1, [r0, #0x48]
	ldr r1, .L08056BFC @ =gUnk_08123B1C
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056BF4: .4byte gUnk_085D34D4
.L08056BF8: .4byte gUnk_0811AE34
.L08056BFC: .4byte gUnk_08123B1C

	thumb_func_start sub_8056C00
sub_8056C00: @ 0x08056C00
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L08056C26
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl sub_8047AF4
	b .L08056C34
.L08056C26:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08056C34
	adds r0, r4, #0
	bl Proc_Break
.L08056C34:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8056C3C
sub_8056C3C: @ 0x08056C3C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_80474C8
	ldr r0, .L08056C58 @ =gUnk_085D34F4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056C58: .4byte gUnk_085D34F4

	thumb_func_start sub_8056C5C
sub_8056C5C: @ 0x08056C5C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r1, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08056C80
	ldr r0, [r4, #0x5c]
	movs r1, #4
	bl sub_8046794
	b .L08056C96
.L08056C80:
	cmp r0, #4
	bne .L08056C8C
	adds r0, r1, #0
	bl sub_8056C9C
	b .L08056C96
.L08056C8C:
	cmp r0, #0x18
	bne .L08056C96
	adds r0, r4, #0
	bl Proc_Break
.L08056C96:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8056C9C
sub_8056C9C: @ 0x08056C9C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08056CFC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08056D00 @ =gUnk_085D350C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08056D04 @ =gUnk_0811AE76
	str r0, [r5, #0x48]
	ldr r0, .L08056D08 @ =gUnk_085D3524
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08056D0C @ =gUnk_08124B64
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L08056D10 @ =gUnk_0812479C
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	bl sub_8047500
	ldr r0, .L08056D14 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08056D22
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08056D18
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08056D22
	.align 2, 0
.L08056CFC: .4byte gUnk_Banim_02017744
.L08056D00: .4byte gUnk_085D350C
.L08056D04: .4byte gUnk_0811AE76
.L08056D08: .4byte gUnk_085D3524
.L08056D0C: .4byte gUnk_08124B64
.L08056D10: .4byte gUnk_0812479C
.L08056D14: .4byte 0x0203CD14
.L08056D18:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08056D22:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8056D28
sub_8056D28: @ 0x08056D28
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L08056D56
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl sub_804799C
	b .L08056D74
.L08056D56:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L08056D74
	bl sub_80474D8
	ldr r1, .L08056D7C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L08056D74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056D7C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8056D80
sub_8056D80: @ 0x08056D80
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08056DA4 @ =gUnk_085D354C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_8056DB4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056DA4: .4byte gUnk_085D354C

	thumb_func_start sub_8056DA8
sub_8056DA8: @ 0x08056DA8
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8056DB4
sub_8056DB4: @ 0x08056DB4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, .L08056DDC @ =gUnk_085D3564
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	adds r0, #0x29
	strb r4, [r0]
	cmp r4, #0
	bne .L08056DE8
	ldr r2, .L08056DE0 @ =gUnk_085DC850
	ldr r3, .L08056DE4 @ =gUnk_085DDAF0
	b .L08056DEC
	.align 2, 0
.L08056DDC: .4byte gUnk_085D3564
.L08056DE0: .4byte gUnk_085DC850
.L08056DE4: .4byte gUnk_085DDAF0
.L08056DE8:
	ldr r2, .L08056E18 @ =gUnk_085DEDC0
	ldr r3, .L08056E1C @ =gUnk_085E0090
.L08056DEC:
	str r2, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	bl sub_80478DC
	adds r4, r0, #0
	str r4, [r5, #0x60]
	movs r0, #0xc0
	lsls r0, r0, #4
	ldrh r1, [r4, #8]
	ands r0, r1
	movs r5, #0
	strh r0, [r4, #8]
	adds r0, r6, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08056E20
	movs r1, #0xe4
	lsls r1, r1, #7
	b .L08056E24
	.align 2, 0
.L08056E18: .4byte gUnk_085DEDC0
.L08056E1C: .4byte gUnk_085E0090
.L08056E20:
	movs r1, #0x93
	lsls r1, r1, #8
.L08056E24:
	adds r0, r1, #0
	ldrh r1, [r4, #8]
	orrs r0, r1
	strh r0, [r4, #8]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_8056E34
sub_8056E34: @ 0x08056E34
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x45
	bne .L08056E92
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08056E6C
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08056E64
	ldr r0, .L08056E60 @ =gUnk_085DDBF4
	b .L08056E82
	.align 2, 0
.L08056E60: .4byte gUnk_085DDBF4
.L08056E64:
	ldr r0, .L08056E68 @ =gUnk_085DC954
	b .L08056E82
	.align 2, 0
.L08056E68: .4byte gUnk_085DC954
.L08056E6C:
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08056E80
	ldr r0, .L08056E7C @ =gUnk_085E0194
	b .L08056E82
	.align 2, 0
.L08056E7C: .4byte gUnk_085E0194
.L08056E80:
	ldr r0, .L08056E98 @ =gUnk_085DEEC4
.L08056E82:
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L08056E92:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056E98: .4byte gUnk_085DEEC4

	thumb_func_start sub_8056E9C
sub_8056E9C: @ 0x08056E9C
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x5c]
	ldrh r2, [r0, #0x10]
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq .L08056EBE
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq .L08056EBE
	movs r0, #0
	strh r0, [r1, #0x2c]
	adds r0, r1, #0
	bl Proc_Break
.L08056EBE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8056EC4
sub_8056EC4: @ 0x08056EC4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	bl sub_80449C4
	cmp r0, #1
	bne .L08056F1E
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08056EF8
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08056EF0
	ldr r0, .L08056EEC @ =gUnk_085DDC1C
	b .L08056F0E
	.align 2, 0
.L08056EEC: .4byte gUnk_085DDC1C
.L08056EF0:
	ldr r0, .L08056EF4 @ =gUnk_085DC97C
	b .L08056F0E
	.align 2, 0
.L08056EF4: .4byte gUnk_085DC97C
.L08056EF8:
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08056F0C
	ldr r0, .L08056F08 @ =gUnk_085E01BC
	b .L08056F0E
	.align 2, 0
.L08056F08: .4byte gUnk_085E01BC
.L08056F0C:
	ldr r0, .L08056F24 @ =gUnk_085DEEEC
.L08056F0E:
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L08056F1E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056F24: .4byte gUnk_085DEEEC

	thumb_func_start sub_8056F28
sub_8056F28: @ 0x08056F28
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	bne .L08056F4A
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08056F4A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8056F50
sub_8056F50: @ 0x08056F50
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L08056F7C @ =gUnk_Banim_02017744
	ldr r5, [r0]
	cmp r5, #0
	bne .L08056F8E
	ldr r0, .L08056F80 @ =gUnk_085D3594
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	strh r5, [r0, #0x2c]
	ldr r0, .L08056F84 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08056F88
	adds r0, r4, #0
	bl sub_8056FA0
	b .L08056F8E
	.align 2, 0
.L08056F7C: .4byte gUnk_Banim_02017744
.L08056F80: .4byte gUnk_085D3594
.L08056F84: .4byte 0x0203CD14
.L08056F88:
	adds r0, r4, #0
	bl sub_80570A0
.L08056F8E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8056F94
sub_8056F94: @ 0x08056F94
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8056FA0
sub_8056FA0: @ 0x08056FA0
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08056FD8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08056FDC @ =gUnk_085D35AC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L08056FE0 @ =gUnk_085D0E8C
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056FD8: .4byte gUnk_Banim_02017744
.L08056FDC: .4byte gUnk_085D35AC
.L08056FE0: .4byte gUnk_085D0E8C

	thumb_func_start sub_8056FE4
sub_8056FE4: @ 0x08056FE4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #1
	bne .L08056FFC
	ldr r0, .L08056FF8 @ =gUnk_085D7190
	b .L08056FFE
	.align 2, 0
.L08056FF8: .4byte gUnk_085D7190
.L08056FFC:
	ldr r0, .L08057024 @ =gUnk_085D74FC
.L08056FFE:
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	ldr r0, .L08057028 @ =gUnk_08121498
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0805702C @ =gUnk_08120414
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057024: .4byte gUnk_085D74FC
.L08057028: .4byte gUnk_08121498
.L0805702C: .4byte gUnk_08120414

	thumb_func_start sub_8057030
sub_8057030: @ 0x08057030
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #1
	bne .L08057048
	ldr r0, .L08057044 @ =gUnk_085D77E4
	b .L0805704A
	.align 2, 0
.L08057044: .4byte gUnk_085D77E4
.L08057048:
	ldr r0, .L08057070 @ =gUnk_085D7A40
.L0805704A:
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	ldr r0, .L08057074 @ =gUnk_08121498
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08057078 @ =gUnk_08120CB4
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057070: .4byte gUnk_085D7A40
.L08057074: .4byte gUnk_08121498
.L08057078: .4byte gUnk_08120CB4

	thumb_func_start sub_805707C
sub_805707C: @ 0x0805707C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0805709C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805709C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80570A0
sub_80570A0: @ 0x080570A0
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L080570D8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080570DC @ =gUnk_085D35E4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L080570E0 @ =gUnk_085D0E8C
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080570D8: .4byte gUnk_Banim_02017744
.L080570DC: .4byte gUnk_085D35E4
.L080570E0: .4byte gUnk_085D0E8C

	thumb_func_start sub_80570E4
sub_80570E4: @ 0x080570E4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #1
	bne .L080570FC
	ldr r0, .L080570F8 @ =gUnk_085D71D8
	b .L080570FE
	.align 2, 0
.L080570F8: .4byte gUnk_085D71D8
.L080570FC:
	ldr r0, .L08057124 @ =gUnk_085D7544
.L080570FE:
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	ldr r0, .L08057128 @ =gUnk_08121498
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0805712C @ =gUnk_08120414
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057124: .4byte gUnk_085D7544
.L08057128: .4byte gUnk_08121498
.L0805712C: .4byte gUnk_08120414

	thumb_func_start sub_8057130
sub_8057130: @ 0x08057130
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #1
	bne .L08057148
	ldr r0, .L08057144 @ =gUnk_085D77F4
	b .L0805714A
	.align 2, 0
.L08057144: .4byte gUnk_085D77F4
.L08057148:
	ldr r0, .L08057170 @ =gUnk_085D7A50
.L0805714A:
	str r0, [r4, #0x24]
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	ldr r0, .L08057174 @ =gUnk_08121498
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08057178 @ =gUnk_08120CB4
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057170: .4byte gUnk_085D7A50
.L08057174: .4byte gUnk_08121498
.L08057178: .4byte gUnk_08120CB4

	thumb_func_start sub_805717C
sub_805717C: @ 0x0805717C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0805719C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805719C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80571A0
sub_80571A0: @ 0x080571A0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, .L080571EC @ =gUnk_Banim_02017744
	ldr r4, [r0]
	cmp r4, #0
	bne .L08057200
	bl sub_80474C8
	ldr r0, .L080571F0 @ =gUnk_085D361C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	strh r4, [r5, #0x2c]
	ldr r4, .L080571F4 @ =0x0203CD76
	adds r0, r6, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x11
	beq .L080571F8
	cmp r0, #0x11
	bgt .L080571F8
	cmp r0, #0xd
	bgt .L080571F8
	cmp r0, #0xc
	blt .L080571F8
	ldr r0, [r5, #0x5c]
	adds r1, r7, #0
	bl sub_8057224
	b .L08057200
	.align 2, 0
.L080571EC: .4byte gUnk_Banim_02017744
.L080571F0: .4byte gUnk_085D361C
.L080571F4: .4byte 0x0203CD76
.L080571F8:
	ldr r0, [r5, #0x5c]
	adds r1, r7, #2
	bl sub_8057224
.L08057200:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8057208
sub_8057208: @ 0x08057208
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	bne .L08057220
	adds r0, r1, #0
	bl Proc_Break
.L08057220:
	pop {r0}
	bx r0

	thumb_func_start sub_8057224
sub_8057224: @ 0x08057224
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, .L08057258 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805725C @ =gUnk_085D3634
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	cmp r6, #1
	beq .L08057270
	cmp r6, #1
	blo .L08057260
	cmp r6, #2
	beq .L08057280
	cmp r6, #3
	beq .L08057288
	b .L08057292
	.align 2, 0
.L08057258: .4byte gUnk_Banim_02017744
.L0805725C: .4byte gUnk_085D3634
.L08057260:
	ldr r0, .L08057268 @ =gUnk_0811AEA0
	str r0, [r5, #0x48]
	ldr r0, .L0805726C @ =gUnk_085D364C
	b .L0805728E
	.align 2, 0
.L08057268: .4byte gUnk_0811AEA0
.L0805726C: .4byte gUnk_085D364C
.L08057270:
	ldr r0, .L08057278 @ =gUnk_0811AEB6
	str r0, [r5, #0x48]
	ldr r0, .L0805727C @ =gUnk_085D364C
	b .L0805728E
	.align 2, 0
.L08057278: .4byte gUnk_0811AEB6
.L0805727C: .4byte gUnk_085D364C
.L08057280:
	ldr r0, .L08057284 @ =gUnk_0811AEBC
	b .L0805728A
	.align 2, 0
.L08057284: .4byte gUnk_0811AEBC
.L08057288:
	ldr r0, .L080572C8 @ =gUnk_0811AEDE
.L0805728A:
	str r0, [r5, #0x48]
	ldr r0, .L080572CC @ =gUnk_085D3664
.L0805728E:
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
.L08057292:
	ldr r0, .L080572D0 @ =gUnk_08129504
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, .L080572D4 @ =gUnk_0812A258
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	ldr r0, .L080572D8 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L080572E6
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L080572DC
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L080572E6
	.align 2, 0
.L080572C8: .4byte gUnk_0811AEDE
.L080572CC: .4byte gUnk_085D3664
.L080572D0: .4byte gUnk_08129504
.L080572D4: .4byte gUnk_0812A258
.L080572D8: .4byte 0x0203CD14
.L080572DC:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L080572E6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_80572EC
sub_80572EC: @ 0x080572EC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L0805731A
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl sub_804799C
	b .L08057338
.L0805731A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L08057338
	bl sub_80474D8
	ldr r1, .L08057340 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_End
.L08057338:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057340: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8057344
sub_8057344: @ 0x08057344
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, .L0805736C @ =gUnk_Banim_02017744
	ldr r4, [r0]
	cmp r4, #0
	bne .L08057366
	ldr r0, .L08057370 @ =gUnk_085D36A4
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	strh r4, [r0, #0x2c]
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_8057380
.L08057366:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805736C: .4byte gUnk_Banim_02017744
.L08057370: .4byte gUnk_085D36A4

	thumb_func_start sub_8057374
sub_8057374: @ 0x08057374
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8057380
sub_8057380: @ 0x08057380
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r1, .L080573E8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080573EC @ =gUnk_085D36BC
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	ldr r2, .L080573F0 @ =gUnk_085E0280
	cmp r4, #0
	beq .L080573AE
	ldr r2, .L080573F4 @ =gUnk_085E0510
	cmp r4, #1
	bne .L080573AE
	ldr r2, .L080573F8 @ =gUnk_085E03C8
.L080573AE:
	ldr r3, .L080573FC @ =gUnk_085E0324
	cmp r4, #0
	beq .L080573BC
	ldr r3, .L08057400 @ =gUnk_085E05B4
	cmp r4, #1
	bne .L080573BC
	ldr r3, .L08057404 @ =gUnk_085E046C
.L080573BC:
	str r2, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	bl sub_80478DC
	str r0, [r5, #0x60]
	ldr r4, .L08057408 @ =0x0203CDC0
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x32
	bls .L080573DE
	b .L08057510
.L080573DE:
	lsls r0, r0, #2
	ldr r1, .L0805740C @ =.L08057410
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080573E8: .4byte gUnk_Banim_02017744
.L080573EC: .4byte gUnk_085D36BC
.L080573F0: .4byte gUnk_085E0280
.L080573F4: .4byte gUnk_085E0510
.L080573F8: .4byte gUnk_085E03C8
.L080573FC: .4byte gUnk_085E0324
.L08057400: .4byte gUnk_085E05B4
.L08057404: .4byte gUnk_085E046C
.L08057408: .4byte 0x0203CDC0
.L0805740C: .4byte .L08057410
.L08057410: @ jump table
	.4byte .L08057510 @ case 0
	.4byte .L080574DC @ case 1
	.4byte .L080574DC @ case 2
	.4byte .L080574DC @ case 3
	.4byte .L080574DC @ case 4
	.4byte .L080574DC @ case 5
	.4byte .L08057508 @ case 6
	.4byte .L08057508 @ case 7
	.4byte .L08057508 @ case 8
	.4byte .L08057508 @ case 9
	.4byte .L080574DC @ case 10
	.4byte .L08057508 @ case 11
	.4byte .L080574DC @ case 12
	.4byte .L080574DC @ case 13
	.4byte .L080574DC @ case 14
	.4byte .L080574DC @ case 15
	.4byte .L080574F8 @ case 16
	.4byte .L080574DC @ case 17
	.4byte .L080574DC @ case 18
	.4byte .L080574DC @ case 19
	.4byte .L080574E4 @ case 20
	.4byte .L080574F8 @ case 21
	.4byte .L080574F8 @ case 22
	.4byte .L08057508 @ case 23
	.4byte .L08057508 @ case 24
	.4byte .L080574DC @ case 25
	.4byte .L080574DC @ case 26
	.4byte .L080574DC @ case 27
	.4byte .L080574DC @ case 28
	.4byte .L08057508 @ case 29
	.4byte .L08057508 @ case 30
	.4byte .L08057508 @ case 31
	.4byte .L08057508 @ case 32
	.4byte .L08057508 @ case 33
	.4byte .L080574DC @ case 34
	.4byte .L080574DC @ case 35
	.4byte .L08057508 @ case 36
	.4byte .L080574DC @ case 37
	.4byte .L080574DC @ case 38
	.4byte .L080574DC @ case 39
	.4byte .L080574DC @ case 40
	.4byte .L080574DC @ case 41
	.4byte .L080574DC @ case 42
	.4byte .L080574DC @ case 43
	.4byte .L08057510 @ case 44
	.4byte .L08057508 @ case 45
	.4byte .L08057510 @ case 46
	.4byte .L080574DC @ case 47
	.4byte .L08057508 @ case 48
	.4byte .L08057508 @ case 49
	.4byte .L08057508 @ case 50
.L080574DC:
	ldr r0, .L080574E0 @ =gUnk_0812C62C
	b .L080574FA
	.align 2, 0
.L080574E0: .4byte gUnk_0812C62C
.L080574E4:
	ldr r0, [r5, #0x5c]
	bl sub_805C2B0
	cmp r0, #0
	beq .L080574F8
	ldr r0, .L080574F4 @ =gUnk_0812C62C
	b .L080574FA
	.align 2, 0
.L080574F4: .4byte gUnk_0812C62C
.L080574F8:
	ldr r0, .L08057504 @ =gUnk_0812C64C
.L080574FA:
	movs r1, #0x20
	bl sub_8047AB0
	b .L08057510
	.align 2, 0
.L08057504: .4byte gUnk_0812C64C
.L08057508:
	ldr r0, .L08057524 @ =gUnk_0812C66C
	movs r1, #0x20
	bl sub_8047AB0
.L08057510:
	ldr r0, .L08057528 @ =gUnk_0812C1BC
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08057524: .4byte gUnk_0812C66C
.L08057528: .4byte gUnk_0812C1BC

	thumb_func_start sub_805752C
sub_805752C: @ 0x0805752C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L08057552
	ldr r0, .L08057558 @ =gUnk_Banim_02017744
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08057552:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057558: .4byte gUnk_Banim_02017744

	thumb_func_start sub_805755C
sub_805755C: @ 0x0805755C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08057574 @ =gUnk_085D36D4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057574: .4byte gUnk_085D36D4

	thumb_func_start sub_8057578
sub_8057578: @ 0x08057578
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, [r7, #0x5c]
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0805759A
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x28
	movs r3, #0
	bl sub_8046C14
	b .L080575DE
.L0805759A:
	cmp r0, #0xa
	bne .L080575A8
	adds r0, r6, #0
	movs r1, #0x14
	bl sub_8046794
	b .L080575DE
.L080575A8:
	cmp r0, #0x2d
	bne .L080575DE
	ldr r5, .L080575E4 @ =gUnk_Banim_02000000
	adds r0, r6, #0
	bl sub_804B6C4
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r4, [r0]
	adds r0, r6, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r2, [r0]
	movs r0, #0x40
	ldrh r1, [r4, #0x10]
	orrs r1, r0
	strh r1, [r4, #0x10]
	ldrh r1, [r2, #0x10]
	orrs r0, r1
	strh r0, [r2, #0x10]
	adds r0, r7, #0
	bl Proc_Break
.L080575DE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080575E4: .4byte gUnk_Banim_02000000

	thumb_func_start sub_80575E8
sub_80575E8: @ 0x080575E8
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08057648 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805764C @ =gUnk_085D36EC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x28
	strh r0, [r4, #0x2e]
	ldr r3, .L08057650 @ =gUnk_085D55C0
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r0, .L08057654 @ =gUnk_0811CAD8
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L08057658 @ =gUnk_0811C964
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xee
	movs r3, #1
	bl sub_805C804
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057648: .4byte gUnk_Banim_02017744
.L0805764C: .4byte gUnk_085D36EC
.L08057650: .4byte gUnk_085D55C0
.L08057654: .4byte gUnk_0811CAD8
.L08057658: .4byte gUnk_0811C964

	thumb_func_start sub_805765C
sub_805765C: @ 0x0805765C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x18
	bne .L08057680
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xee
	movs r3, #1
	bl sub_805C804
.L08057680:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble .L080576A0
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L080576A8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080576A0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080576A8: .4byte gUnk_Banim_02017744

	thumb_func_start sub_80576AC
sub_80576AC: @ 0x080576AC
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0805770C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08057710 @ =gUnk_085D3704
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x19
	strh r0, [r4, #0x2e]
	ldr r3, .L08057714 @ =gUnk_085D5590
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	ldr r0, .L08057718 @ =gUnk_0811CAD8
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0805771C @ =gUnk_0811C964
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xe1
	movs r3, #1
	bl sub_805C804
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805770C: .4byte gUnk_Banim_02017744
.L08057710: .4byte gUnk_085D3704
.L08057714: .4byte gUnk_085D5590
.L08057718: .4byte gUnk_0811CAD8
.L0805771C: .4byte gUnk_0811C964

	thumb_func_start sub_8057720
sub_8057720: @ 0x08057720
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08057748
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L08057750 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08057748:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057750: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8057754
sub_8057754: @ 0x08057754
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	bl sub_805894C
	adds r4, r0, #0
	cmp r4, #0
	bne .L0805778E
	ldr r1, .L08057794 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08057798 @ =gUnk_085D371C
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	movs r2, #0
	strh r4, [r0, #0x2c]
	strh r6, [r0, #0x2e]
	strh r7, [r0, #0x30]
	ldr r1, .L0805779C @ =gDispIo
	movs r0, #0x40
	ldrb r3, [r1, #0x18]
	orrs r0, r3
	strb r0, [r1, #0x18]
	adds r1, #0x38
	strb r2, [r1]
.L0805778E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08057794: .4byte gUnk_Banim_02017744
.L08057798: .4byte gUnk_085D371C
.L0805779C: .4byte gDispIo

	thumb_func_start sub_80577A0
sub_80577A0: @ 0x080577A0
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x30
	ldrsh r2, [r4, r0]
	movs r1, #0x2c
	ldrsh r3, [r4, r1]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl Interpolate
	ldr r2, .L080577F0 @ =gDispIo
	adds r2, #0x38
	movs r3, #0xf
	adds r1, r0, #0
	ands r1, r3
	lsls r0, r0, #4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L080577E6
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L080577E6:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080577F0: .4byte gDispIo

	thumb_func_start sub_80577F4
sub_80577F4: @ 0x080577F4
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x30
	ldrsh r1, [r4, r0]
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0
	bl Interpolate
	ldr r3, .L08057858 @ =gDispIo
	adds r5, r3, #0
	adds r5, #0x38
	movs r2, #0xf
	adds r1, r0, #0
	ands r1, r2
	lsls r0, r0, #4
	orrs r0, r1
	strb r0, [r5]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805784E
	ldr r1, .L0805785C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	movs r0, #0x41
	rsbs r0, r0, #0
	ldrb r1, [r3, #0x18]
	ands r0, r1
	strb r0, [r3, #0x18]
	movs r0, #0
	strb r0, [r5]
	adds r0, r4, #0
	bl Proc_Break
.L0805784E:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057858: .4byte gDispIo
.L0805785C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8057860
sub_8057860: @ 0x08057860
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, .L08057894 @ =gUnk_Banim_02017760
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080578BC
	adds r0, r5, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #1
	strh r1, [r0]
	adds r0, r5, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0805789C
	ldr r0, .L08057898 @ =0x0203CD7C
	b .L0805789E
	.align 2, 0
.L08057894: .4byte gUnk_Banim_02017760
.L08057898: .4byte 0x0203CD7C
.L0805789C:
	ldr r0, .L080578EC @ =0x0203CD80
.L0805789E:
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x4a
	ldrh r0, [r4]
	bl GetItemKind
	ldrh r0, [r4]
	bl GetItemRequiredExp
	movs r1, #0
	cmp r0, #0xfb
	bne .L080578B8
	movs r1, #1
.L080578B8:
	cmp r1, #0
	bne .L080578F4
.L080578BC:
	ldr r4, .L080578F0 @ =gUnk_Banim_02000000
	adds r0, r5, #0
	bl sub_804B6C4
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r6, [r0]
	adds r0, r5, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r2, [r0]
	movs r1, #0x40
	ldrh r0, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	ldrh r0, [r2, #0x10]
	orrs r0, r1
	strh r0, [r2, #0x10]
	b .L08057916
	.align 2, 0
.L080578EC: .4byte 0x0203CD80
.L080578F0: .4byte gUnk_Banim_02000000
.L080578F4:
	ldr r0, .L0805791C @ =gUnk_085D373C
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xf0
	movs r2, #0x78
	movs r3, #0
	bl sub_805C804
	adds r0, r5, #0
	bl sub_805792C
.L08057916:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805791C: .4byte gUnk_085D373C

	thumb_func_start sub_8057920
sub_8057920: @ 0x08057920
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805792C
sub_805792C: @ 0x0805792C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_80474C8
	ldr r0, .L08057948 @ =gUnk_085D3754
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057948: .4byte gUnk_085D3754

	thumb_func_start sub_805794C
sub_805794C: @ 0x0805794C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08057966
	ldr r0, [r6, #0x5c]
	bl sub_80579C0
	b .L080579B6
.L08057966:
	cmp r0, #0x15
	bne .L08057980
	ldr r0, [r6, #0x5c]
	ldr r2, .L0805797C @ =sub_8057A34
	movs r1, #0x2d
	bl sub_804CC68
	bl sub_8057A5C
	b .L080579B6
	.align 2, 0
.L0805797C: .4byte sub_8057A34
.L08057980:
	cmp r0, #0x46
	bne .L080579B6
	ldr r5, .L080579BC @ =gUnk_Banim_02000000
	ldr r0, [r6, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r4, [r0]
	ldr r0, [r6, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r2, [r0]
	movs r0, #0x40
	ldrh r1, [r4, #0x10]
	orrs r1, r0
	strh r1, [r4, #0x10]
	ldrh r1, [r2, #0x10]
	orrs r0, r1
	strh r0, [r2, #0x10]
	adds r0, r6, #0
	bl Proc_Break
.L080579B6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080579BC: .4byte gUnk_Banim_02000000

	thumb_func_start sub_80579C0
sub_80579C0: @ 0x080579C0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L080579FC @ =gUnk_085D376C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, .L08057A00 @ =gUnk_08124618
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, .L08057A04 @ =gUnk_081246D8
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, [r4, #0x5c]
	ldr r2, .L08057A08 @ =gUnk_081246F8
	adds r1, r2, #0
	bl sub_804799C
	bl sub_8047500
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080579FC: .4byte gUnk_085D376C
.L08057A00: .4byte gUnk_08124618
.L08057A04: .4byte gUnk_081246D8
.L08057A08: .4byte gUnk_081246F8

	thumb_func_start sub_8057A0C
sub_8057A0C: @ 0x08057A0C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3c
	bne .L08057A2C
	bl sub_80474D8
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L08057A2C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8057A34
sub_8057A34: @ 0x08057A34
	ldr r0, .L08057A50 @ =0x04000004
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L08057A4E
	ldr r3, .L08057A54 @ =0x04000016
	ldr r2, .L08057A58 @ =gUnk_Banim_0201E3E0
	ldr r0, [r2]
	ldrh r1, [r0]
	strh r1, [r3]
	adds r0, #2
	str r0, [r2]
.L08057A4E:
	bx lr
	.align 2, 0
.L08057A50: .4byte 0x04000004
.L08057A54: .4byte 0x04000016
.L08057A58: .4byte gUnk_Banim_0201E3E0

	thumb_func_start sub_8057A5C
sub_8057A5C: @ 0x08057A5C
	push {lr}
	ldr r0, .L08057A78 @ =gUnk_085D3784
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	str r1, [r0, #0x44]
	bl sub_8057B2C
	pop {r0}
	bx r0
	.align 2, 0
.L08057A78: .4byte gUnk_085D3784

	thumb_func_start sub_8057A7C
sub_8057A7C: @ 0x08057A7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	ldr r0, .L08057AD8 @ =gUnk_Banim_0201E3D8
	ldr r0, [r0]
	ldr r5, .L08057ADC @ =gUnk_Banim_0201E158
	cmp r0, #0
	bne .L08057A92
	ldr r5, .L08057AE0 @ =gUnk_Banim_0201E298
.L08057A92:
	ldr r4, .L08057AE4 @ =gUnk_Banim_0201E3E4
	cmp r0, #0
	bne .L08057A9A
	ldr r4, .L08057AE8 @ =gUnk_Banim_0201E524
.L08057A9A:
	movs r3, #0
	movs r0, #0
	mov r8, r0
	movs r1, #0x88
	lsls r1, r1, #0x10
	mov ip, r1
	movs r7, #0x88
	ldr r6, .L08057AEC @ =gUnk_085D37B4
.L08057AAA:
	cmp r3, #0x77
	bhi .L08057B04
	movs r2, #0
	ldrsh r1, [r6, r2]
	mov r2, sb
	ldr r0, [r2, #0x44]
	muls r0, r1, r0
	lsls r0, r0, #4
	lsrs r2, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	beq .L08057AFC
	cmp r3, #0x3b
	bhi .L08057AF4
	adds r0, r3, #0
	subs r0, #0x88
	cmp r1, r0
	bhs .L08057AFC
	ldr r1, .L08057AF0 @ =0x0000FF78
	adds r0, r3, r1
	lsls r0, r0, #0x10
	b .L08057AFA
	.align 2, 0
.L08057AD8: .4byte gUnk_Banim_0201E3D8
.L08057ADC: .4byte gUnk_Banim_0201E158
.L08057AE0: .4byte gUnk_Banim_0201E298
.L08057AE4: .4byte gUnk_Banim_0201E3E4
.L08057AE8: .4byte gUnk_Banim_0201E524
.L08057AEC: .4byte gUnk_085D37B4
.L08057AF0: .4byte 0x0000FF78
.L08057AF4:
	cmp r1, r7
	bls .L08057AFC
	mov r0, ip
.L08057AFA:
	lsrs r2, r0, #0x10
.L08057AFC:
	strh r2, [r5]
	adds r5, #2
	strh r2, [r4]
	b .L08057B0C
.L08057B04:
	mov r1, r8
	strh r1, [r5]
	adds r5, #2
	strh r1, [r4]
.L08057B0C:
	adds r4, #2
	ldr r2, .L08057B28 @ =0xFFFF0000
	add ip, r2
	subs r7, #1
	adds r6, #2
	adds r3, #1
	cmp r3, #0x9f
	bls .L08057AAA
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08057B28: .4byte 0xFFFF0000

	thumb_func_start sub_8057B2C
sub_8057B2C: @ 0x08057B2C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08057B48 @ =gUnk_085D379C
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	movs r1, #0x28
	strh r1, [r0, #0x2e]
	str r4, [r0, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057B48: .4byte gUnk_085D379C

	thumb_func_start sub_8057B4C
sub_8057B4C: @ 0x08057B4C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, [r4, #0x5c]
	movs r2, #0x80
	lsls r2, r2, #0xb
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl Interpolate
	str r0, [r5, #0x44]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08057B88
	adds r0, r5, #0
	bl Proc_End
	adds r0, r4, #0
	bl Proc_Break
.L08057B88:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8057B90
sub_8057B90: @ 0x08057B90
	push {r4, lr}
	adds r4, r0, #0
	bl sub_80474C8
	ldr r0, .L08057BAC @ =gUnk_085D38A4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057BAC: .4byte gUnk_085D38A4

	thumb_func_start sub_8057BB0
sub_8057BB0: @ 0x08057BB0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x11
	bne .L08057BE6
	ldr r0, [r5, #0x5c]
	movs r1, #0x49
	bl sub_8057BF8
	movs r4, #0xa0
	lsls r4, r4, #1
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, #0
	bl sub_805BCA8
	ldr r0, [r5, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	adds r0, r4, #0
	movs r2, #1
	bl sub_805BDC0
.L08057BE6:
	ldrh r0, [r5, #0x2c]
	cmp r0, #0x64
	bne .L08057BF2
	adds r0, r5, #0
	bl Proc_Break
.L08057BF2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8057BF8
sub_8057BF8: @ 0x08057BF8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08057C78 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08057C7C @ =gUnk_085D38BC
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r1, [r0, #0x44]
	ldr r1, .L08057C80 @ =gUnk_0811AF00
	str r1, [r0, #0x48]
	ldr r1, .L08057C84 @ =gUnk_085D38D4
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r0, .L08057C88 @ =gUnk_0812BE10
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L08057C8C @ =gUnk_0812B19C
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	bl sub_8047500
	ldr r3, .L08057C90 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r2, [r3, #0x14]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x14]
	ldrb r0, [r3, #0x10]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x10]
	movs r0, #3
	ldrb r1, [r3, #0x18]
	orrs r0, r1
	strb r0, [r3, #0x18]
	movs r0, #1
	movs r1, #0x10
	movs r2, #0
	bl SetBgOffset
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057C78: .4byte gUnk_Banim_02017744
.L08057C7C: .4byte gUnk_085D38BC
.L08057C80: .4byte gUnk_0811AF00
.L08057C84: .4byte gUnk_085D38D4
.L08057C88: .4byte gUnk_0812BE10
.L08057C8C: .4byte gUnk_0812B19C
.L08057C90: .4byte gDispIo

	thumb_func_start sub_8057C94
sub_8057C94: @ 0x08057C94
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L08057CC0
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl sub_804799C
.L08057CC0:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08057D12
	ldr r3, .L08057D18 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r2, [r3, #0x10]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x10]
	ldrb r0, [r3, #0x18]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x18]
	movs r0, #3
	ldrb r1, [r3, #0x14]
	orrs r0, r1
	strb r0, [r3, #0x14]
	bl sub_80474D8
	ldr r1, .L08057D1C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L08057D12:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057D18: .4byte gDispIo
.L08057D1C: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8057D20
sub_8057D20: @ 0x08057D20
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	bl sub_804B6C4
	ldr r1, .L08057D4C @ =0x0203CD76
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, #0xc
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x29
	bhi .L08057E1C
	lsls r0, r0, #2
	ldr r1, .L08057D50 @ =.L08057D54
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08057D4C: .4byte 0x0203CD76
.L08057D50: .4byte .L08057D54
.L08057D54: @ jump table
	.4byte .L08057DFC @ case 0
	.4byte .L08057DFC @ case 1
	.4byte .L08057E1C @ case 2
	.4byte .L08057E1C @ case 3
	.4byte .L08057E1C @ case 4
	.4byte .L08057E0C @ case 5
	.4byte .L08057E1C @ case 6
	.4byte .L08057E1C @ case 7
	.4byte .L08057E1C @ case 8
	.4byte .L08057E1C @ case 9
	.4byte .L08057E1C @ case 10
	.4byte .L08057E1C @ case 11
	.4byte .L08057E1C @ case 12
	.4byte .L08057E1C @ case 13
	.4byte .L08057E1C @ case 14
	.4byte .L08057E1C @ case 15
	.4byte .L08057E1C @ case 16
	.4byte .L08057E1C @ case 17
	.4byte .L08057E1C @ case 18
	.4byte .L08057E1C @ case 19
	.4byte .L08057E1C @ case 20
	.4byte .L08057E1C @ case 21
	.4byte .L08057E1C @ case 22
	.4byte .L08057E1C @ case 23
	.4byte .L08057E1C @ case 24
	.4byte .L08057E1C @ case 25
	.4byte .L08057E1C @ case 26
	.4byte .L08057E1C @ case 27
	.4byte .L08057E1C @ case 28
	.4byte .L08057E1C @ case 29
	.4byte .L08057E1C @ case 30
	.4byte .L08057E1C @ case 31
	.4byte .L08057E1C @ case 32
	.4byte .L08057E1C @ case 33
	.4byte .L08057E1C @ case 34
	.4byte .L08057E1C @ case 35
	.4byte .L08057E1C @ case 36
	.4byte .L08057E1C @ case 37
	.4byte .L08057E1C @ case 38
	.4byte .L08057E1C @ case 39
	.4byte .L08057E1C @ case 40
	.4byte .L08057E0C @ case 41
.L08057DFC:
	ldr r6, .L08057E04 @ =gUnk_085E0748
	ldr r4, .L08057E08 @ =gUnk_085E08DC
	b .L08057E20
	.align 2, 0
.L08057E04: .4byte gUnk_085E0748
.L08057E08: .4byte gUnk_085E08DC
.L08057E0C:
	ldr r6, .L08057E14 @ =gUnk_085E0A88
	ldr r4, .L08057E18 @ =gUnk_085E0C34
	b .L08057E20
	.align 2, 0
.L08057E14: .4byte gUnk_085E0A88
.L08057E18: .4byte gUnk_085E0C34
.L08057E1C:
	ldr r6, .L08057E68 @ =gUnk_085E0DE0
	ldr r4, .L08057E6C @ =gUnk_085E0F88
.L08057E20:
	ldr r0, .L08057E70 @ =gUnk_085D38E4
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r7, [r5, #0x5c]
	movs r0, #0
	mov r8, r0
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r6, [sp]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	adds r3, r4, #0
	bl sub_80478DC
	adds r4, r0, #0
	str r4, [r5, #0x60]
	movs r0, #0xc0
	lsls r0, r0, #4
	ldrh r1, [r4, #8]
	ands r0, r1
	strh r0, [r4, #8]
	movs r0, #0x64
	strh r0, [r4, #0xa]
	bl BasSort
	adds r0, r7, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08057E74
	movs r1, #0xe4
	lsls r1, r1, #7
	b .L08057E78
	.align 2, 0
.L08057E68: .4byte gUnk_085E0DE0
.L08057E6C: .4byte gUnk_085E0F88
.L08057E70: .4byte gUnk_085D38E4
.L08057E74:
	movs r1, #0x93
	lsls r1, r1, #8
.L08057E78:
	adds r0, r1, #0
	ldrh r1, [r4, #8]
	orrs r0, r1
	strh r0, [r4, #8]
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	bl sub_804B8B0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8057E98
sub_8057E98: @ 0x08057E98
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x60]
	ldr r0, [r2, #0x5c]
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	ldr r0, [r2, #0x5c]
	ldrh r1, [r0, #0x10]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L08057EBE
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L08057EBE
	adds r0, r2, #0
	bl Proc_Break
.L08057EBE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8057EC4
sub_8057EC4: @ 0x08057EC4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, [r4, #0x5c]
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	bl sub_80449C4
	cmp r0, #1
	bne .L08057EEE
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	bl sub_804B8E8
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08057EEE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8057EF4
sub_8057EF4: @ 0x08057EF4
	ldr r0, .L08057F00 @ =0x0203CDD8
	movs r1, #0
	str r1, [r0]
	ldr r0, .L08057F04 @ =0x0203CDDC
	str r1, [r0]
	bx lr
	.align 2, 0
.L08057F00: .4byte 0x0203CDD8
.L08057F04: .4byte 0x0203CDDC

	thumb_func_start sub_8057F08
sub_8057F08: @ 0x08057F08
	push {r4, lr}
	ldr r4, .L08057F20 @ =0x0203CDD8
	ldr r0, [r4]
	cmp r0, #0
	beq .L08057F1A
	bl Proc_End
	movs r0, #0
	str r0, [r4]
.L08057F1A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057F20: .4byte 0x0203CDD8

	thumb_func_start sub_8057F24
sub_8057F24: @ 0x08057F24
	push {r4, lr}
	ldr r4, .L08057F3C @ =0x0203CDDC
	ldr r0, [r4]
	cmp r0, #0
	beq .L08057F36
	bl Proc_End
	movs r0, #0
	str r0, [r4]
.L08057F36:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057F3C: .4byte 0x0203CDDC

	thumb_func_start sub_8057F40
sub_8057F40: @ 0x08057F40
	ldr r1, .L08057F48 @ =0x0203CDD8
	str r0, [r1]
	bx lr
	.align 2, 0
.L08057F48: .4byte 0x0203CDD8

	thumb_func_start sub_8057F4C
sub_8057F4C: @ 0x08057F4C
	ldr r1, .L08057F54 @ =0x0203CDDC
	str r0, [r1]
	bx lr
	.align 2, 0
.L08057F54: .4byte 0x0203CDDC

	thumb_func_start sub_8057F58
sub_8057F58: @ 0x08057F58
	ldr r0, [r0, #0x44]
	ldr r0, [r0, #0x2c]
	bx lr
	.align 2, 0

	thumb_func_start sub_8057F60
sub_8057F60: @ 0x08057F60
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L08057F7C
	ldr r0, .L08057F78 @ =gUnk_081122C5
	ldrh r1, [r4, #2]
	ldrb r0, [r0]
	subs r0, r1, r0
	b .L08057F84
	.align 2, 0
.L08057F78: .4byte gUnk_081122C5
.L08057F7C:
	ldr r0, .L08057FB4 @ =gUnk_081122CA
	ldrb r0, [r0]
	ldrh r3, [r4, #2]
	subs r0, r0, r3
.L08057F84:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0x58
	ldrh r4, [r4, #4]
	subs r2, r2, r4
	ldrh r0, [r5, #0x12]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r3, [r5, #2]
	subs r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r5, [r5, #4]
	subs r2, r2, r5
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl SetBgOffset
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08057FB4: .4byte gUnk_081122CA

	thumb_func_start sub_8057FB8
sub_8057FB8: @ 0x08057FB8
	push {r4, lr}
	sub sp, #4
	bl sub_8057F58
	adds r4, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r1, [r4, #0x14]
	ldr r2, .L08057FE4 @ =0x01000200
	mov r0, sp
	bl CpuFastSet
	movs r0, #1
	ldrh r4, [r4, #0x12]
	lsls r0, r4
	bl EnableBgSync
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08057FE4: .4byte 0x01000200

	thumb_func_start sub_8057FE8
sub_8057FE8: @ 0x08057FE8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	adds r6, r3, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_8057F58
	mov r8, r0
	cmp r4, #0
	bne .L08058008
	adds r0, r7, #0
	b .L0805800A
.L08058008:
	adds r0, r6, #0
.L0805800A:
	movs r1, #0x78
	bl BasCreate
	adds r2, r0, #0
	mov r1, r8
	ldrh r1, [r1, #0x10]
	lsls r0, r1, #0xc
	mov r3, r8
	ldrh r3, [r3, #0xe]
	orrs r0, r3
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2, #8]
	ldrh r0, [r5, #2]
	strh r0, [r2, #2]
	ldrh r0, [r5, #4]
	strh r0, [r2, #4]
	adds r0, r2, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_805803C
sub_805803C: @ 0x0805803C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r2, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r5, r3, #0
	bl sub_8057F58
	adds r4, r0, #0
	cmp r5, #1
	bne .L0805805E
	ldr r1, [r4, #0x1c]
	adds r0, r6, #0
	bl LZ77UnCompWram
.L0805805E:
	adds r2, r6, #0
	cmp r5, #1
	bne .L08058066
	ldr r2, [r4, #0x1c]
.L08058066:
	cmp r7, #0
	bne .L08058080
	ldr r1, [r4, #0x14]
	ldrh r0, [r4, #0xc]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl sub_805B1DC
	b .L08058094
.L08058080:
	ldr r1, [r4, #0x14]
	ldrh r0, [r4, #0xc]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl sub_805B1AC
.L08058094:
	movs r0, #1
	ldrh r4, [r4, #0x12]
	lsls r0, r4
	bl EnableBgSync
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80580A8
sub_80580A8: @ 0x080580A8
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	bl sub_8057F58
	adds r4, r0, #0
	ldrh r0, [r4, #0xa]
	lsls r5, r0, #5
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r5, r5, r0
	ldr r1, [r4, #0x18]
	adds r0, r6, #0
	bl LZ77UnCompWram
	ldr r0, [r4, #0x18]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r5, #0
	bl RegisterDataMove
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80580D8
sub_80580D8: @ 0x080580D8
	push {r4, lr}
	adds r4, r1, #0
	bl sub_8057F58
	ldrh r0, [r0, #0xc]
	lsls r1, r0, #5
	ldr r0, .L080580FC @ =gPal
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080580FC: .4byte gPal

	thumb_func_start sub_8058100
sub_8058100: @ 0x08058100
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	bl sub_8057F58
	adds r4, r0, #0
	ldrh r0, [r4, #0xe]
	lsls r5, r0, #5
	ldr r0, .L0805812C @ =0x06010000
	adds r5, r5, r0
	ldr r1, [r4, #0x20]
	adds r0, r6, #0
	bl LZ77UnCompWram
	ldr r0, [r4, #0x20]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r5, #0
	bl RegisterDataMove
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805812C: .4byte 0x06010000

	thumb_func_start sub_8058130
sub_8058130: @ 0x08058130
	push {r4, lr}
	adds r4, r1, #0
	bl sub_8057F58
	ldrh r0, [r0, #0x10]
	lsls r1, r0, #5
	ldr r0, .L08058154 @ =gPal+0x200
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08058154: .4byte gPal+0x200

	thumb_func_start sub_8058158
sub_8058158: @ 0x08058158
	push {r4, lr}
	adds r4, r0, #0
	bl sub_8057F58
	ldr r1, .L08058178 @ =gUnk_085D3904
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08058178: .4byte gUnk_085D3904

	thumb_func_start nullsub_23
nullsub_23: @ 0x0805817C
	bx lr
	.align 2, 0

	thumb_func_start sub_8058180
sub_8058180: @ 0x08058180
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L0805819C @ =gUnk_085D3924
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	bl sub_8057F40
	str r4, [r5, #0x5c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805819C: .4byte gUnk_085D3924

	thumb_func_start sub_80581A0
sub_80581A0: @ 0x080581A0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl sub_80581C0
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl sub_805826C
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_80581C0
sub_80581C0: @ 0x080581C0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl sub_8057F58
	adds r6, r0, #0
	ldr r0, .L0805820C @ =gUnk_085D394C
	adds r1, r4, #0
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	ldr r0, .L08058210 @ =gUnk_0811AF20
	str r0, [r4, #0x48]
	ldr r0, .L08058214 @ =gUnk_085D3964
	str r0, [r4, #0x4c]
	ldr r1, .L08058218 @ =gUnk_0812E4A4
	adds r0, r5, #0
	bl sub_80580D8
	ldr r0, [r4, #0x5c]
	ldr r1, .L0805821C @ =gUnk_0812D8AC
	bl sub_80580A8
	ldr r0, [r6, #0x24]
	bl _call_via_r0
	ldr r0, [r4, #0x5c]
	adds r1, r6, #0
	bl sub_8057F60
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805820C: .4byte gUnk_085D394C
.L08058210: .4byte gUnk_0811AF20
.L08058214: .4byte gUnk_085D3964
.L08058218: .4byte gUnk_0812E4A4
.L0805821C: .4byte gUnk_0812D8AC

	thumb_func_start sub_8058220
sub_8058220: @ 0x08058220
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0805824C
	ldr r2, [r4, #0x4c]
	ldr r0, [r4, #0x5c]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	movs r1, #1
	movs r3, #1
	bl sub_805803C
	b .L08058264
.L0805824C:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08058264
	ldr r0, [r4, #0x5c]
	bl sub_8057FB8
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L08058264:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805826C
sub_805826C: @ 0x0805826C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl sub_8057F58
	adds r7, r0, #0
	ldr r0, .L080582A8 @ =gUnk_085D3994
	adds r1, r4, #0
	bl SpawnProc
	adds r6, r0, #0
	str r5, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	ldr r2, .L080582AC @ =gUnk_085E2CA8
	ldr r3, .L080582B0 @ =gUnk_085E2920
	adds r0, r5, #0
	movs r1, #1
	bl sub_8057FE8
	adds r4, r0, #0
	str r4, [r6, #0x60]
	adds r0, r5, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L080582B4
	ldrh r0, [r5, #2]
	subs r0, #8
	b .L080582B8
	.align 2, 0
.L080582A8: .4byte gUnk_085D3994
.L080582AC: .4byte gUnk_085E2CA8
.L080582B0: .4byte gUnk_085E2920
.L080582B4:
	ldrh r0, [r5, #2]
	adds r0, #8
.L080582B8:
	strh r0, [r4, #2]
	ldrh r0, [r5, #4]
	adds r0, #8
	strh r0, [r4, #4]
	ldrh r2, [r4, #2]
	ldrh r3, [r7, #6]
	adds r1, r2, r3
	strh r1, [r4, #2]
	ldrh r7, [r7, #8]
	adds r0, r7, r0
	strh r0, [r4, #4]
	ldr r0, [r6, #0x5c]
	ldr r1, .L080582E4 @ =gUnk_0812FFD8
	bl sub_8058130
	ldr r0, [r6, #0x5c]
	ldr r1, .L080582E8 @ =gUnk_0812F9DC
	bl sub_8058100
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080582E4: .4byte gUnk_0812FFD8
.L080582E8: .4byte gUnk_0812F9DC

	thumb_func_start sub_80582EC
sub_80582EC: @ 0x080582EC
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	ble .L0805830A
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0805830A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8058310
sub_8058310: @ 0x08058310
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L0805832C @ =gUnk_085D39AC
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	bl sub_8057F40
	str r4, [r5, #0x5c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805832C: .4byte gUnk_085D39AC

	thumb_func_start sub_8058330
sub_8058330: @ 0x08058330
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl sub_8058358
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl sub_8058438
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl sub_80584AC
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8058358
sub_8058358: @ 0x08058358
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl sub_8057F58
	adds r6, r0, #0
	ldr r0, .L080583A0 @ =gUnk_085D39D4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	ldr r0, .L080583A4 @ =gUnk_0811AF52
	str r0, [r4, #0x48]
	ldr r0, .L080583A8 @ =gUnk_085D39EC
	str r0, [r4, #0x4c]
	ldr r1, .L080583AC @ =gUnk_0812CF48
	adds r0, r5, #0
	bl sub_80580D8
	ldr r0, [r4, #0x5c]
	ldr r1, .L080583B0 @ =gUnk_0812C68C
	bl sub_80580A8
	ldr r0, [r6, #0x24]
	bl _call_via_r0
	ldr r0, [r4, #0x5c]
	adds r1, r6, #0
	bl sub_8057F60
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080583A0: .4byte gUnk_085D39D4
.L080583A4: .4byte gUnk_0811AF52
.L080583A8: .4byte gUnk_085D39EC
.L080583AC: .4byte gUnk_0812CF48
.L080583B0: .4byte gUnk_0812C68C

	thumb_func_start sub_80583B4
sub_80583B4: @ 0x080583B4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r7, #0
	ldr r0, [r4, #0x5c]
	bl sub_8057F58
	adds r6, r0, #0
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	blt .L08058416
	ldr r2, [r4, #0x4c]
	ldr r0, [r4, #0x5c]
	lsls r1, r5, #2
	adds r1, r1, r2
	ldr r2, [r1]
	movs r1, #0
	movs r3, #1
	bl sub_805803C
	cmp r5, #0
	bne .L080583F8
	ldrh r0, [r6, #0xa]
	adds r0, #0x1f
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L080583F8:
	cmp r5, #1
	bne .L08058404
	ldrh r0, [r6, #0xa]
	adds r0, #0x50
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
.L08058404:
	ldr r0, [r6, #0x14]
	adds r0, #0x3c
	ldrh r3, [r6, #0xc]
	str r7, [sp]
	movs r1, #2
	movs r2, #0x14
	bl sub_805B094
	b .L0805842E
.L08058416:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L0805842E
	ldr r0, [r4, #0x5c]
	bl sub_8057FB8
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L0805842E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8058438
sub_8058438: @ 0x08058438
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08058460 @ =gUnk_085D39F4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	bl sub_8057F4C
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	ldr r0, .L08058464 @ =gUnk_0811AF5C
	str r0, [r4, #0x48]
	ldr r0, .L08058468 @ =gUnk_0812CF48
	str r0, [r4, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08058460: .4byte gUnk_085D39F4
.L08058464: .4byte gUnk_0811AF5C
.L08058468: .4byte gUnk_0812CF48

	thumb_func_start sub_805846C
sub_805846C: @ 0x0805846C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L08058492
	ldr r1, [r4, #0x4c]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #5
	adds r1, r1, r2
	bl sub_80580D8
	b .L080584A4
.L08058492:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L080584A4
	bl sub_8057F24
	adds r0, r4, #0
	bl Proc_Break
.L080584A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80584AC
sub_80584AC: @ 0x080584AC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl sub_8057F58
	adds r7, r0, #0
	ldr r0, .L080584E8 @ =gUnk_085D3A14
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r5, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	ldr r2, .L080584EC @ =gUnk_085E2508
	ldr r3, .L080584F0 @ =gUnk_085E19DC
	adds r0, r5, #0
	movs r1, #1
	bl sub_8057FE8
	adds r4, r0, #0
	str r4, [r6, #0x60]
	adds r0, r5, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L080584F4
	ldrh r0, [r5, #2]
	adds r0, #0x38
	b .L080584F8
	.align 2, 0
.L080584E8: .4byte gUnk_085D3A14
.L080584EC: .4byte gUnk_085E2508
.L080584F0: .4byte gUnk_085E19DC
.L080584F4:
	ldrh r0, [r5, #2]
	subs r0, #0x38
.L080584F8:
	strh r0, [r4, #2]
	ldrh r1, [r4, #2]
	ldrh r2, [r7, #6]
	adds r0, r1, r2
	strh r0, [r4, #2]
	ldrh r1, [r4, #4]
	ldrh r7, [r7, #8]
	adds r0, r1, r7
	strh r0, [r4, #4]
	ldr r0, [r6, #0x5c]
	ldr r1, .L08058520 @ =gUnk_0812D80C
	bl sub_8058130
	ldr r0, [r6, #0x5c]
	ldr r1, .L08058524 @ =gUnk_0812D374
	bl sub_8058100
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08058520: .4byte gUnk_0812D80C
.L08058524: .4byte gUnk_0812D374

	thumb_func_start sub_8058528
sub_8058528: @ 0x08058528
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	ble .L08058546
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08058546:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_805854C
sub_805854C: @ 0x0805854C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08058564 @ =gUnk_085D3A2C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08058564: .4byte gUnk_085D3A2C

	thumb_func_start sub_8058568
sub_8058568: @ 0x08058568
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl sub_80587C0
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl sub_80585DC
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	bl sub_805867C
	ldr r3, .L080585D8 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	movs r1, #0
	strb r1, [r0]
	adds r2, #9
	movs r0, #0x10
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x46
	strb r1, [r0]
	ldr r0, [r4, #0x5c]
	str r4, [sp]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl sub_80586F0
	ldr r0, [r4, #0x5c]
	str r4, [sp]
	movs r1, #0x23
	movs r2, #0x19
	movs r3, #1
	bl sub_80586F0
	adds r0, r4, #0
	bl Proc_Break
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080585D8: .4byte gDispIo

	thumb_func_start sub_80585DC
sub_80585DC: @ 0x080585DC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl sub_8057F58
	adds r6, r0, #0
	ldr r0, .L08058620 @ =gUnk_085D3A54
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	bl sub_8057F40
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	ldr r0, .L08058624 @ =gUnk_0811AF9E
	str r0, [r4, #0x48]
	ldr r0, .L08058628 @ =gUnk_085D3A6C
	str r0, [r4, #0x4c]
	ldr r1, .L0805862C @ =gUnk_081AB1B0
	adds r0, r5, #0
	bl sub_80580A8
	ldr r0, [r6, #0x24]
	bl _call_via_r0
	ldr r0, [r4, #0x5c]
	adds r1, r6, #0
	bl sub_8057F60
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08058620: .4byte gUnk_085D3A54
.L08058624: .4byte gUnk_0811AF9E
.L08058628: .4byte gUnk_085D3A6C
.L0805862C: .4byte gUnk_081AB1B0

	thumb_func_start sub_8058630
sub_8058630: @ 0x08058630
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0805865C
	ldr r2, [r4, #0x4c]
	ldr r0, [r4, #0x5c]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	movs r1, #1
	movs r3, #0
	bl sub_805803C
	b .L08058674
.L0805865C:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08058674
	ldr r0, [r4, #0x5c]
	bl sub_8057FB8
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L08058674:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805867C
sub_805867C: @ 0x0805867C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L080586A4 @ =gUnk_085D3A70
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	bl sub_8057F4C
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	ldr r0, .L080586A8 @ =gUnk_0811AFA4
	str r0, [r4, #0x48]
	ldr r0, .L080586AC @ =gUnk_081ABCA0
	str r0, [r4, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080586A4: .4byte gUnk_085D3A70
.L080586A8: .4byte gUnk_0811AFA4
.L080586AC: .4byte gUnk_081ABCA0

	thumb_func_start sub_80586B0
sub_80586B0: @ 0x080586B0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L080586D6
	ldr r1, [r4, #0x4c]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #5
	adds r1, r1, r2
	bl sub_80580D8
	b .L080586E8
.L080586D6:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L080586E8
	bl sub_8057F24
	adds r0, r4, #0
	bl Proc_Break
.L080586E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80586F0
sub_80586F0: @ 0x080586F0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r0, .L0805871C @ =gUnk_085D3A90
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	strh r5, [r0, #0x2c]
	strh r6, [r0, #0x2e]
	adds r0, #0x29
	mov r1, r8
	strb r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805871C: .4byte gUnk_085D3A90

	thumb_func_start sub_8058720
sub_8058720: @ 0x08058720
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	subs r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08058736
	adds r0, r1, #0
	bl Proc_Break
.L08058736:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805873C
sub_805873C: @ 0x0805873C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble .L08058756
	adds r0, r4, #0
	bl Proc_Break
	b .L080587B4
.L08058756:
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08058772
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	b .L08058782
.L08058772:
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
.L08058782:
	bl Interpolate
	adds r5, r0, #0
	ldr r3, .L080587BC @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	movs r1, #0
	strb r5, [r0]
	adds r2, #9
	movs r0, #0x10
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x46
	strb r1, [r0]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L080587B4:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080587BC: .4byte gDispIo

	thumb_func_start sub_80587C0
sub_80587C0: @ 0x080587C0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl sub_8057F58
	adds r6, r0, #0
	ldr r0, .L08058814 @ =gUnk_085D3AB0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x33
	strh r0, [r4, #0x2e]
	ldr r3, .L08058818 @ =gUnk_085F0A14
	adds r0, r5, #0
	movs r1, #1
	adds r2, r3, #0
	bl sub_8057FE8
	str r0, [r4, #0x60]
	ldrh r2, [r0, #2]
	ldrh r3, [r6, #6]
	adds r1, r2, r3
	strh r1, [r0, #2]
	ldrh r2, [r0, #4]
	ldrh r6, [r6, #8]
	adds r1, r2, r6
	strh r1, [r0, #4]
	ldr r0, [r4, #0x5c]
	ldr r1, .L0805881C @ =gUnk_081AC0F4
	bl sub_8058130
	ldr r0, [r4, #0x5c]
	ldr r1, .L08058820 @ =gUnk_081ABEA0
	bl sub_8058100
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08058814: .4byte gUnk_085D3AB0
.L08058818: .4byte gUnk_085F0A14
.L0805881C: .4byte gUnk_081AC0F4
.L08058820: .4byte gUnk_081ABEA0

	thumb_func_start sub_8058824
sub_8058824: @ 0x08058824
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08058844
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08058844:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805884C
sub_805884C: @ 0x0805884C
	ldr r1, .L0805886C @ =gUnk_Banim_0201E7AC
	movs r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	ldr r1, .L08058870 @ =gUnk_Banim_0201E7BC
	str r0, [r1]
	ldr r1, .L08058874 @ =gUnk_Banim_0201E7C0
	strh r0, [r1]
	strh r0, [r1, #2]
	ldr r1, .L08058878 @ =gUnk_Banim_0201E7C4
	strh r0, [r1]
	strh r0, [r1, #2]
	ldr r1, .L0805887C @ =gUnk_Banim_0201E7C8
	strh r0, [r1]
	strh r0, [r1, #2]
	bx lr
	.align 2, 0
.L0805886C: .4byte gUnk_Banim_0201E7AC
.L08058870: .4byte gUnk_Banim_0201E7BC
.L08058874: .4byte gUnk_Banim_0201E7C0
.L08058878: .4byte gUnk_Banim_0201E7C4
.L0805887C: .4byte gUnk_Banim_0201E7C8

	thumb_func_start sub_8058880
sub_8058880: @ 0x08058880
	push {r4, lr}
	ldr r4, .L08058898 @ =gUnk_Banim_0201E7C0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #1
	beq .L0805889C
	movs r0, #0
	b .L0805889E
	.align 2, 0
.L08058898: .4byte gUnk_Banim_0201E7C0
.L0805889C:
	movs r0, #1
.L0805889E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_80588A4
sub_80588A4: @ 0x080588A4
	push {lr}
	bl sub_804B6C4
	ldr r1, .L080588B8 @ =gUnk_Banim_0201E7C8
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #2
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
.L080588B8: .4byte gUnk_Banim_0201E7C8

	thumb_func_start sub_80588BC
sub_80588BC: @ 0x080588BC
	push {r4, lr}
	ldr r4, .L080588D4 @ =gUnk_Banim_0201E7C0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #2
	beq .L080588D8
	movs r0, #0
	b .L080588DA
	.align 2, 0
.L080588D4: .4byte gUnk_Banim_0201E7C0
.L080588D8:
	movs r0, #1
.L080588DA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_80588E0
sub_80588E0: @ 0x080588E0
	push {r4, lr}
	movs r4, #0
	movs r0, #0
	bl sub_80589FC
	ldrh r0, [r0]
	cmp r0, #0x53
	bne .L080588F2
	movs r4, #1
.L080588F2:
	movs r0, #1
	bl sub_80589FC
	ldrh r0, [r0]
	cmp r0, #0x53
	bne .L08058902
	movs r0, #2
	orrs r4, r0
.L08058902:
	movs r0, #0
	bl sub_80589FC
	ldrh r0, [r0]
	cmp r0, #0x54
	bne .L08058912
	movs r0, #4
	orrs r4, r0
.L08058912:
	movs r0, #1
	bl sub_80589FC
	ldrh r0, [r0]
	cmp r0, #0x54
	bne .L08058922
	movs r0, #8
	orrs r4, r0
.L08058922:
	movs r0, #0
	bl sub_80589FC
	ldrh r0, [r0]
	cmp r0, #0x70
	bne .L08058932
	movs r0, #0x10
	orrs r4, r0
.L08058932:
	movs r0, #1
	bl sub_80589FC
	ldrh r0, [r0]
	cmp r0, #0x70
	bne .L08058942
	movs r0, #0x20
	orrs r4, r0
.L08058942:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_805894C
sub_805894C: @ 0x0805894C
	push {r4, lr}
	movs r4, #0
	movs r0, #0
	bl sub_80589FC
	ldrh r0, [r0]
	cmp r0, #0x53
	bne .L0805895E
	movs r4, #1
.L0805895E:
	movs r0, #1
	bl sub_80589FC
	ldrh r0, [r0]
	cmp r0, #0x53
	bne .L0805896E
	movs r0, #2
	orrs r4, r0
.L0805896E:
	movs r0, #0
	bl sub_80589FC
	ldrh r0, [r0]
	cmp r0, #0x70
	bne .L0805897E
	movs r0, #0x10
	orrs r4, r0
.L0805897E:
	movs r0, #1
	bl sub_80589FC
	ldrh r0, [r0]
	cmp r0, #0x70
	bne .L0805898E
	movs r0, #0x20
	orrs r4, r0
.L0805898E:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8058998
sub_8058998: @ 0x08058998
	push {r4, lr}
	movs r4, #0
	movs r0, #0
	bl sub_80589FC
	ldrh r0, [r0]
	cmp r0, #0x70
	bne .L080589AA
	movs r4, #0x10
.L080589AA:
	movs r0, #1
	bl sub_80589FC
	ldrh r0, [r0]
	cmp r0, #0x70
	bne .L080589BA
	movs r0, #0x20
	orrs r4, r0
.L080589BA:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_80589C4
sub_80589C4: @ 0x080589C4
	push {r4, lr}
	adds r4, r0, #0
	bl sub_8058A08
	ldrh r0, [r0]
	cmp r0, #1
	beq .L080589F4
	ldr r0, .L080589EC @ =0x0203CD14
	ldrh r0, [r0]
	cmp r0, #2
	bne .L080589E8
	adds r0, r4, #0
	bl sub_804B6C4
	ldr r1, .L080589F0 @ =gUnk_Banim_0201773C
	ldr r1, [r1]
	cmp r0, r1
	bne .L080589F4
.L080589E8:
	movs r0, #0
	b .L080589F6
	.align 2, 0
.L080589EC: .4byte 0x0203CD14
.L080589F0: .4byte gUnk_Banim_0201773C
.L080589F4:
	movs r0, #1
.L080589F6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_80589FC
sub_80589FC: @ 0x080589FC
	lsls r0, r0, #1
	ldr r1, .L08058A04 @ =0x0203CDE0
	adds r0, r0, r1
	bx lr
	.align 2, 0
.L08058A04: .4byte 0x0203CDE0

	thumb_func_start sub_8058A08
sub_8058A08: @ 0x08058A08
	push {lr}
	bl sub_804B6C4
	lsls r0, r0, #1
	ldr r1, .L08058A18 @ =gUnk_Banim_0201E7C4
	adds r0, r0, r1
	pop {r1}
	bx r1
	.align 2, 0
.L08058A18: .4byte gUnk_Banim_0201E7C4

	thumb_func_start sub_8058A1C
sub_8058A1C: @ 0x08058A1C
	push {r4, lr}
	ldr r4, .L08058A30 @ =gUnk_Banim_0201E7AC
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L08058A30: .4byte gUnk_Banim_0201E7AC

	thumb_func_start sub_8058A34
sub_8058A34: @ 0x08058A34
	push {r4, lr}
	ldr r4, .L08058A4C @ =gUnk_Banim_0201E7B4
	bl sub_804B6C4
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	bl Proc_End
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08058A4C: .4byte gUnk_Banim_0201E7B4

	thumb_func_start sub_8058A50
sub_8058A50: @ 0x08058A50
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	ldr r1, .L08058A78 @ =gUnk_Banim_02000000
	ldr r3, [r1]
	ldr r4, [r1, #8]
	ldr r1, .L08058A7C @ =0x0000F3FF
	adds r2, r1, #0
	ldrh r5, [r3, #8]
	ands r2, r5
	lsrs r0, r0, #0xe
	orrs r2, r0
	strh r2, [r3, #8]
	ldrh r2, [r4, #8]
	ands r1, r2
	orrs r1, r0
	strh r1, [r4, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08058A78: .4byte gUnk_Banim_02000000
.L08058A7C: .4byte 0x0000F3FF

	thumb_func_start sub_8058A80
sub_8058A80: @ 0x08058A80
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, .L08058AAC @ =gUnk_081BF434
	ldr r5, .L08058AB0 @ =gPal+0x20
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08058AB4
	adds r1, r5, #0
	adds r1, #0xa0
	adds r0, r6, #0
	movs r2, #8
	bl CpuFastSet
	b .L08058AC0
	.align 2, 0
.L08058AAC: .4byte gUnk_081BF434
.L08058AB0: .4byte gPal+0x20
.L08058AB4:
	adds r1, r5, #0
	adds r1, #0xc0
	adds r0, r6, #0
	movs r2, #8
	bl CpuFastSet
.L08058AC0:
	bl EnablePalSync
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8058ACC
sub_8058ACC: @ 0x08058ACC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, .L08058B64 @ =gUnk_081BC268
	ldr r1, .L08058B68 @ =gUnk_Banim_0201777C
	mov r8, r1
	bl LZ77UnCompWram
	ldr r0, .L08058B6C @ =gUnk_081BF5B4
	ldr r7, .L08058B70 @ =gUnk_Banim_0201977C
	adds r1, r7, #0
	bl LZ77UnCompWram
	movs r0, #0
	bl sub_8047C68
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	adds r1, r0, #0
	cmp r1, #0
	bne .L08058B50
	ldr r0, .L08058B74 @ =0x0203CD14
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0x1d
	cmp r0, #0
	bne .L08058B0A
	movs r2, #0x23
.L08058B0A:
	movs r5, #1
	rsbs r5, r5, #0
	lsls r2, r2, #1
	ldr r4, .L08058B78 @ =gUnk_Banim_0201D414
	adds r2, r2, r4
	movs r0, #0xf
	str r0, [sp]
	movs r6, #0x16
	str r6, [sp, #4]
	movs r0, #6
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r3, #0x42
	bl sub_805B2BC
	adds r4, #0x42
	ldr r2, .L08058B7C @ =gBg3Tm
	movs r0, #0x20
	str r0, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x42
	movs r3, #0x20
	bl sub_805B20C
	ldr r1, .L08058B80 @ =0x06008000
	movs r2, #0x80
	lsls r2, r2, #6
	mov r0, r8
	bl RegisterDataMove
.L08058B50:
	movs r0, #8
	bl EnableBgSync
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08058B64: .4byte gUnk_081BC268
.L08058B68: .4byte gUnk_Banim_0201777C
.L08058B6C: .4byte gUnk_081BF5B4
.L08058B70: .4byte gUnk_Banim_0201977C
.L08058B74: .4byte 0x0203CD14
.L08058B78: .4byte gUnk_Banim_0201D414
.L08058B7C: .4byte gBg3Tm
.L08058B80: .4byte 0x06008000

	thumb_func_start sub_8058B84
sub_8058B84: @ 0x08058B84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, .L08058C1C @ =gUnk_081BCBDC
	ldr r1, .L08058C20 @ =gUnk_Banim_0201777C
	mov r8, r1
	bl LZ77UnCompWram
	ldr r0, .L08058C24 @ =gUnk_081BF6F4
	ldr r7, .L08058C28 @ =gUnk_Banim_0201977C
	adds r1, r7, #0
	bl LZ77UnCompWram
	movs r0, #0
	bl sub_8047C68
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	adds r1, r0, #0
	cmp r1, #0
	bne .L08058C08
	ldr r0, .L08058C2C @ =0x0203CD14
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0x1b
	cmp r0, #0
	bne .L08058BC2
	movs r2, #0x21
.L08058BC2:
	movs r5, #1
	rsbs r5, r5, #0
	lsls r2, r2, #1
	ldr r4, .L08058C30 @ =gUnk_Banim_0201D414
	adds r2, r2, r4
	movs r0, #0xf
	str r0, [sp]
	movs r6, #0x16
	str r6, [sp, #4]
	movs r0, #6
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r3, #0x42
	bl sub_805B2BC
	adds r4, #0x42
	ldr r2, .L08058C34 @ =gBg3Tm
	movs r0, #0x20
	str r0, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x42
	movs r3, #0x20
	bl sub_805B20C
	ldr r1, .L08058C38 @ =0x06008000
	movs r2, #0x80
	lsls r2, r2, #6
	mov r0, r8
	bl RegisterDataMove
.L08058C08:
	movs r0, #8
	bl EnableBgSync
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08058C1C: .4byte gUnk_081BCBDC
.L08058C20: .4byte gUnk_Banim_0201777C
.L08058C24: .4byte gUnk_081BF6F4
.L08058C28: .4byte gUnk_Banim_0201977C
.L08058C2C: .4byte 0x0203CD14
.L08058C30: .4byte gUnk_Banim_0201D414
.L08058C34: .4byte gBg3Tm
.L08058C38: .4byte 0x06008000

	thumb_func_start sub_8058C3C
sub_8058C3C: @ 0x08058C3C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, .L08058CCC @ =gUnk_081BD5E8
	ldr r1, .L08058CD0 @ =gUnk_Banim_0201777C
	bl LZ77UnCompWram
	ldr r0, .L08058CD4 @ =gUnk_081BF848
	ldr r1, .L08058CD8 @ =gUnk_Banim_0201977C
	bl LZ77UnCompWram
	movs r0, #0
	bl sub_8047C68
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08058CBE
	ldr r0, .L08058CDC @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x21
	cmp r0, #0
	beq .L08058C76
	movs r2, #1
	cmp r0, #1
	bne .L08058C76
	movs r2, #0x1b
.L08058C76:
	ldr r0, .L08058CD8 @ =gUnk_Banim_0201977C
	movs r5, #1
	rsbs r5, r5, #0
	lsls r2, r2, #1
	ldr r4, .L08058CE0 @ =gUnk_Banim_0201D414
	adds r2, r2, r4
	movs r1, #0xf
	str r1, [sp]
	movs r6, #0x16
	str r6, [sp, #4]
	movs r1, #6
	str r1, [sp, #8]
	movs r1, #0
	str r1, [sp, #0xc]
	adds r1, r5, #0
	movs r3, #0x42
	bl sub_805B2BC
	adds r4, #0x42
	ldr r2, .L08058CE4 @ =gBg3Tm
	movs r0, #0x20
	str r0, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x42
	movs r3, #0x20
	bl sub_805B20C
	ldr r0, .L08058CD0 @ =gUnk_Banim_0201777C
	ldr r1, .L08058CE8 @ =0x06008000
	movs r2, #0x80
	lsls r2, r2, #6
	bl RegisterDataMove
.L08058CBE:
	movs r0, #8
	bl EnableBgSync
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08058CCC: .4byte gUnk_081BD5E8
.L08058CD0: .4byte gUnk_Banim_0201777C
.L08058CD4: .4byte gUnk_081BF848
.L08058CD8: .4byte gUnk_Banim_0201977C
.L08058CDC: .4byte 0x0203CD14
.L08058CE0: .4byte gUnk_Banim_0201D414
.L08058CE4: .4byte gBg3Tm
.L08058CE8: .4byte 0x06008000

	thumb_func_start sub_8058CEC
sub_8058CEC: @ 0x08058CEC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08058D04 @ =gUnk_086046D8
	movs r1, #4
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r4, [r0, #0x44]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08058D04: .4byte gUnk_086046D8

	thumb_func_start sub_8058D08
sub_8058D08: @ 0x08058D08
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x44]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #3
	movs r2, #0x10
	bl SetBgOffset
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x46
	bne .L08058D2E
	adds r0, r4, #0
	bl Proc_Break
.L08058D2E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8058D34
sub_8058D34: @ 0x08058D34
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, .L08058D94 @ =gUnk_081BE490
	ldr r4, .L08058D98 @ =gUnk_Banim_0201777C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L08058D9C @ =0x06008000
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r4, #0
	bl RegisterDataMove
	movs r0, #0
	bl sub_8047C68
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	adds r5, r0, #0
	cmp r5, #0
	bne .L08058E14
	ldr r0, .L08058DA0 @ =gUnk_081BFA34
	ldr r4, .L08058DA4 @ =gUnk_Banim_0201977C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r6, .L08058DA8 @ =gBg3Tm
	movs r0, #6
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x1e
	movs r3, #0x16
	bl sub_805B1DC
	ldr r0, .L08058DAC @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq .L08058DC2
	cmp r0, #1
	bgt .L08058DB0
	cmp r0, #0
	beq .L08058DB6
	b .L08058E14
	.align 2, 0
.L08058D94: .4byte gUnk_081BE490
.L08058D98: .4byte gUnk_Banim_0201777C
.L08058D9C: .4byte 0x06008000
.L08058DA0: .4byte gUnk_081BFA34
.L08058DA4: .4byte gUnk_Banim_0201977C
.L08058DA8: .4byte gBg3Tm
.L08058DAC: .4byte 0x0203CD14
.L08058DB0:
	cmp r0, #2
	beq .L08058E04
	b .L08058E14
.L08058DB6:
	movs r0, #3
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
	b .L08058E14
.L08058DC2:
	ldr r4, .L08058E00 @ =gUnk_Banim_0201E12C
	ldr r0, [r4]
	adds r0, #0x30
	bl sub_8058CEC
	ldr r1, [r4]
	adds r1, #0x30
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #3
	movs r2, #0x10
	bl SetBgOffset
	ldr r4, [r4]
	cmp r4, #0
	bne .L08058E14
	str r4, [sp]
	adds r0, r6, #0
	movs r1, #2
	movs r2, #0x16
	movs r3, #0xf0
	bl sub_805B094
	adds r0, r6, #4
	str r4, [sp]
	movs r1, #2
	movs r2, #0x16
	movs r3, #0xf0
	bl sub_805B094
	b .L08058E14
	.align 2, 0
.L08058E00: .4byte gUnk_Banim_0201E12C
.L08058E04:
	movs r0, #0x10
	bl sub_8058CEC
	movs r0, #3
	movs r1, #0x10
	movs r2, #0x10
	bl SetBgOffset
.L08058E14:
	movs r0, #8
	bl EnableBgSync
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8058E24
sub_8058E24: @ 0x08058E24
	push {r4, lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r4, .L08058E4C @ =gUnk_Banim_0201C77C
	ldr r2, .L08058E50 @ =0x01000008
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	ldr r1, .L08058E54 @ =0x06008000
	adds r0, r4, #0
	movs r2, #0x20
	bl RegisterDataMove
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08058E4C: .4byte gUnk_Banim_0201C77C
.L08058E50: .4byte 0x01000008
.L08058E54: .4byte 0x06008000

	thumb_func_start sub_8058E58
sub_8058E58: @ 0x08058E58
	push {lr}
	cmp r0, #0
	bne .L08058E74
	ldr r0, .L08058E6C @ =gUnk_081BF434
	ldr r1, .L08058E70 @ =gPal+0xC0
	movs r2, #8
	bl CpuFastSet
	b .L08058E7E
	.align 2, 0
.L08058E6C: .4byte gUnk_081BF434
.L08058E70: .4byte gPal+0xC0
.L08058E74:
	ldr r0, .L08058E88 @ =gUnk_081BF434
	ldr r1, .L08058E8C @ =gPal+0xE0
	movs r2, #8
	bl CpuFastSet
.L08058E7E:
	bl EnablePalSync
	pop {r0}
	bx r0
	.align 2, 0
.L08058E88: .4byte gUnk_081BF434
.L08058E8C: .4byte gPal+0xE0

	thumb_func_start sub_8058E90
sub_8058E90: @ 0x08058E90
	push {lr}
	cmp r0, #0
	bne .L08058EAC
	ldr r0, .L08058EA4 @ =gUnk_081C4DE8
	ldr r1, .L08058EA8 @ =gPal+0xC0
	movs r2, #8
	bl CpuFastSet
	b .L08058EB6
	.align 2, 0
.L08058EA4: .4byte gUnk_081C4DE8
.L08058EA8: .4byte gPal+0xC0
.L08058EAC:
	ldr r0, .L08058EC0 @ =gUnk_081C4DE8
	ldr r1, .L08058EC4 @ =gPal+0xE0
	movs r2, #8
	bl CpuFastSet
.L08058EB6:
	bl EnablePalSync
	pop {r0}
	bx r0
	.align 2, 0
.L08058EC0: .4byte gUnk_081C4DE8
.L08058EC4: .4byte gPal+0xE0

	thumb_func_start sub_8058EC8
sub_8058EC8: @ 0x08058EC8
	push {lr}
	cmp r0, #0
	bne .L08058EE4
	ldr r0, .L08058EDC @ =gUnk_08113564
	ldr r1, .L08058EE0 @ =gPal+0xC0
	movs r2, #8
	bl CpuFastSet
	b .L08058EEE
	.align 2, 0
.L08058EDC: .4byte gUnk_08113564
.L08058EE0: .4byte gPal+0xC0
.L08058EE4:
	ldr r0, .L08058EF8 @ =gUnk_08113564
	ldr r1, .L08058EFC @ =gPal+0xE0
	movs r2, #8
	bl CpuFastSet
.L08058EEE:
	bl EnablePalSync
	pop {r0}
	bx r0
	.align 2, 0
.L08058EF8: .4byte gUnk_08113564
.L08058EFC: .4byte gPal+0xE0

	thumb_func_start sub_8058F00
sub_8058F00: @ 0x08058F00
	push {lr}
	bl sub_8058998
	adds r1, r0, #0
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L08058F14
	movs r0, #0
	b .L08058F22
.L08058F14:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L08058F20
	movs r0, #2
	b .L08058F22
.L08058F20:
	movs r0, #1
.L08058F22:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8058F28
sub_8058F28: @ 0x08058F28
	push {lr}
	bl sub_8058F00
	bl sub_804B8B0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8058F38
sub_8058F38: @ 0x08058F38
	push {lr}
	bl sub_8058998
	cmp r0, #0
	beq .L08058F58
	ldr r0, .L08058F54 @ =gUnk_Banim_02000000
	ldr r0, [r0]
	bl sub_8058A08
	ldrh r0, [r0]
	cmp r0, #1
	bne .L08058F58
	movs r0, #1
	b .L08058F5A
	.align 2, 0
.L08058F54: .4byte gUnk_Banim_02000000
.L08058F58:
	movs r0, #0
.L08058F5A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8058F60
sub_8058F60: @ 0x08058F60
	push {r4, lr}
	sub sp, #0x10
	asrs r4, r0, #3
	movs r1, #7
	ands r1, r0
	movs r0, #3
	movs r2, #0x10
	bl SetBgOffset
	lsls r4, r4, #1
	ldr r0, .L08058FA0 @ =gUnk_Banim_0201D456
	adds r4, r4, r0
	ldr r2, .L08058FA4 @ =gBg3Tm
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	subs r0, #0x17
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x42
	movs r3, #0x20
	bl sub_805B20C
	movs r0, #8
	bl EnableBgSync
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08058FA0: .4byte gUnk_Banim_0201D456
.L08058FA4: .4byte gBg3Tm

	thumb_func_start sub_8058FA8
sub_8058FA8: @ 0x08058FA8
	push {r4, lr}
	sub sp, #0x10
	ldr r4, .L08058FDC @ =gUnk_Banim_0201977C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L08058FE0 @ =0x0203CD14
	movs r1, #0
	ldrsh r3, [r0, r1]
	cmp r3, #0
	bne .L08058FE8
	movs r1, #1
	rsbs r1, r1, #0
	ldr r2, .L08058FE4 @ =gBg3Tm
	movs r0, #0x1e
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #6
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	adds r0, r4, #0
	movs r3, #0x20
	bl sub_805B20C
	b .L08059006
	.align 2, 0
.L08058FDC: .4byte gUnk_Banim_0201977C
.L08058FE0: .4byte 0x0203CD14
.L08058FE4: .4byte gBg3Tm
.L08058FE8:
	adds r0, r4, #0
	adds r0, #8
	ldr r2, .L08059014 @ =gBg3Tm
	movs r1, #0x1a
	str r1, [sp]
	movs r1, #0x1e
	str r1, [sp, #4]
	movs r1, #6
	str r1, [sp, #8]
	movs r1, #0
	str r1, [sp, #0xc]
	movs r1, #0x1e
	movs r3, #0x20
	bl sub_805B20C
.L08059006:
	movs r0, #8
	bl EnableBgSync
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08059014: .4byte gBg3Tm

	thumb_func_start sub_8059018
sub_8059018: @ 0x08059018
	push {lr}
	sub sp, #0x10
	ldr r1, .L08059068 @ =gUnk_Banim_0201E7CC
	bl LZ77UnCompWram
	ldr r0, .L0805906C @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x21
	cmp r0, #0
	beq .L08059036
	movs r2, #3
	cmp r0, #1
	bne .L08059036
	movs r2, #0x1d
.L08059036:
	ldr r0, .L08059068 @ =gUnk_Banim_0201E7CC
	movs r1, #1
	rsbs r1, r1, #0
	lsls r2, r2, #1
	ldr r3, .L08059070 @ =gUnk_Banim_0201D414
	adds r2, r2, r3
	movs r3, #0x1e
	str r3, [sp]
	movs r3, #0x16
	str r3, [sp, #4]
	movs r3, #6
	str r3, [sp, #8]
	movs r3, #0
	str r3, [sp, #0xc]
	movs r3, #0x42
	bl sub_805B20C
	ldr r0, .L08059074 @ =gUnk_Banim_0201E12C
	ldr r0, [r0]
	bl sub_8058F60
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
.L08059068: .4byte gUnk_Banim_0201E7CC
.L0805906C: .4byte 0x0203CD14
.L08059070: .4byte gUnk_Banim_0201D414
.L08059074: .4byte gUnk_Banim_0201E12C

	thumb_func_start sub_8059078
sub_8059078: @ 0x08059078
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805908C @ =gUnk_086046F0
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805908C: .4byte gUnk_086046F0

	thumb_func_start sub_8059090
sub_8059090: @ 0x08059090
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xe6
	bl sub_805BCA8
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r0, #0xe6
	movs r2, #1
	bl sub_805BDC0
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_80590B8
sub_80590B8: @ 0x080590B8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl sub_804B6C4
	adds r4, r0, #0
	ldr r0, .L080590F0 @ =gUnk_08604710
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	ldr r0, .L080590F4 @ =gUnk_Banim_0201E7AC
	lsls r4, r4, #2
	adds r4, r4, r0
	str r5, [r4]
	adds r0, r6, #0
	bl sub_804B6C4
	ldr r1, .L080590F8 @ =gUnk_Banim_0201E7C8
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	movs r1, #1
	strh r1, [r0]
	str r6, [r5, #0x5c]
	strh r2, [r5, #0x2c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080590F0: .4byte gUnk_08604710
.L080590F4: .4byte gUnk_Banim_0201E7AC
.L080590F8: .4byte gUnk_Banim_0201E7C8

	thumb_func_start sub_80590FC
sub_80590FC: @ 0x080590FC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #1
	movs r1, #4
	movs r2, #0x10
	bl Interpolate
	bl sub_805B9A4
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L0805913C
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x5c]
	movs r1, #0
	movs r2, #0xa
	movs r3, #1
	bl sub_8046C14
	adds r0, r4, #0
	bl Proc_Break
.L0805913C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8059144
sub_8059144: @ 0x08059144
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08059162
	movs r0, #0x3c
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
	b .L080591A4
.L08059162:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	bne .L080591A4
	ldr r1, [r4, #0x5c]
	movs r0, #2
	ldrh r2, [r1]
	orrs r0, r2
	strh r0, [r1]
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl sub_8059690
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xe8
	bl sub_805BCA8
	ldr r0, [r4, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r0, #0xe8
	movs r2, #1
	bl sub_805BDC0
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L080591A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80591AC
sub_80591AC: @ 0x080591AC
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3d
	bne .L080591C8
	movs r0, #0
	strh r0, [r1, #0x2c]
	adds r0, r1, #0
	bl Proc_Break
.L080591C8:
	pop {r0}
	bx r0

	thumb_func_start sub_80591CC
sub_80591CC: @ 0x080591CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08059244
	bl sub_8058E24
	ldr r0, .L0805923C @ =gBg3Tm
	movs r1, #0xf0
	lsls r1, r1, #8
	bl TmFill
	movs r0, #3
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
	movs r0, #8
	bl EnableBgSync
	ldr r3, .L08059240 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r2, [r3, #0x10]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x10]
	ldrb r0, [r3, #0x18]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x18]
	movs r0, #3
	ldrb r1, [r3, #0x14]
	orrs r0, r1
	strb r0, [r3, #0x14]
	movs r0, #1
	bl sub_8058A50
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
	b .L080592C0
	.align 2, 0
.L0805923C: .4byte gBg3Tm
.L08059240: .4byte gDispIo
.L08059244:
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne .L080592A8
	bl sub_8058E24
	ldr r0, .L080592C8 @ =gBg3Tm
	movs r1, #0xf0
	lsls r1, r1, #8
	bl TmFill
	movs r0, #3
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
	ldr r3, .L080592CC @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r2, [r3, #0x10]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x10]
	ldrb r0, [r3, #0x18]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x18]
	movs r0, #3
	ldrb r1, [r3, #0x14]
	orrs r0, r1
	strb r0, [r3, #0x14]
	movs r0, #8
	bl EnableBgSync
	movs r0, #1
	bl sub_8058A50
	adds r0, r4, #0
	bl sub_8058A80
	adds r0, r4, #0
	bl sub_8058ACC
.L080592A8:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	bne .L080592C0
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L080592C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080592C8: .4byte gBg3Tm
.L080592CC: .4byte gDispIo

	thumb_func_start sub_80592D0
sub_80592D0: @ 0x080592D0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L080592EE
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
	b .L08059320
.L080592EE:
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L08059302
	adds r0, r4, #0
	bl sub_8058B84
	movs r0, #5
	bl sub_8046010
.L08059302:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	bne .L08059320
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x5c]
	bl sub_8059078
	adds r0, r4, #0
	bl Proc_Break
.L08059320:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8059328
sub_8059328: @ 0x08059328
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r6, r0, #0x18
	cmp r6, #1
	bne .L0805937C
	adds r0, r5, #0
	bl sub_8058C3C
	ldr r0, [r5, #0x5c]
	bl sub_80598F0
	ldr r1, [r5, #0x5c]
	ldr r0, .L08059374 @ =0x0000FFFD
	ldrh r2, [r1]
	ands r0, r2
	movs r4, #0
	strh r0, [r1]
	ldr r0, [r5, #0x5c]
	movs r1, #0x55
	bl sub_804A528
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	ldr r1, .L08059378 @ =gUnk_Banim_0201E7C0
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r6, [r0]
	strh r4, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
	b .L080593C6
	.align 2, 0
.L08059374: .4byte 0x0000FFFD
.L08059378: .4byte gUnk_Banim_0201E7C0
.L0805937C:
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne .L080593A2
	adds r0, r5, #0
	bl sub_8058C3C
	ldr r0, [r5, #0x5c]
	bl sub_80598F0
	ldr r1, [r5, #0x5c]
	ldr r0, .L080593CC @ =0x0000FFFD
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	ldr r0, [r5, #0x5c]
	movs r1, #0x55
	bl sub_804A528
.L080593A2:
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3d
	bne .L080593C6
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	ldr r1, .L080593D0 @ =gUnk_Banim_0201E7C0
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
	adds r0, r5, #0
	bl Proc_Break
.L080593C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080593CC: .4byte 0x0000FFFD
.L080593D0: .4byte gUnk_Banim_0201E7C0

	thumb_func_start sub_80593D4
sub_80593D4: @ 0x080593D4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L080593FC @ =gUnk_Banim_0201E7C8
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #2
	bne .L080593F4
	movs r0, #0
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L080593F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080593FC: .4byte gUnk_Banim_0201E7C8

	thumb_func_start sub_8059400
sub_8059400: @ 0x08059400
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_8058A34
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8059418
sub_8059418: @ 0x08059418
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08059436
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
	b .L08059466
.L08059436:
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L0805944E
	adds r0, r4, #0
	bl sub_8058B84
	ldr r0, [r4, #0x5c]
	movs r1, #2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
.L0805944E:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	bne .L08059466
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L08059466:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_805946C
sub_805946C: @ 0x0805946C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805948E
	bl sub_8058E24
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
	b .L080594C4
.L0805948E:
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L080594AC
	bl sub_8058E24
	movs r0, #0x10
	bl sub_805B9A4
	adds r0, r4, #0
	bl sub_8058A80
	adds r0, r4, #0
	bl sub_8058ACC
.L080594AC:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	bne .L080594C4
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L080594C4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80594CC
sub_80594CC: @ 0x080594CC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L08059504
	ldr r0, [r4, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08059504
	ldr r0, [r4, #0x5c]
	movs r1, #1
	bl sub_8059690
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xe9
	bl sub_805BCA8
	ldr r0, [r4, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r0, #0xe9
	movs r2, #1
	bl sub_805BDC0
.L08059504:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	bne .L08059568
	ldr r0, .L08059570 @ =gBg3Tm
	movs r1, #0xf0
	lsls r1, r1, #8
	bl TmFill
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #8
	bl EnableBgSync
	ldr r3, .L08059574 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r2, [r3, #0x10]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x10]
	ldrb r0, [r3, #0x14]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x14]
	movs r0, #3
	ldrb r1, [r3, #0x18]
	orrs r0, r1
	strb r0, [r3, #0x18]
	movs r0, #2
	bl sub_8058A50
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L08059568:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08059570: .4byte gBg3Tm
.L08059574: .4byte gDispIo

	thumb_func_start sub_8059578
sub_8059578: @ 0x08059578
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08059596
	movs r0, #0x50
	strh r0, [r6, #0x2c]
	adds r0, r6, #0
	bl Proc_Break
	b .L080595DC
.L08059596:
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3d
	bne .L080595DC
	ldr r1, [r6, #0x5c]
	ldr r0, .L080595E4 @ =0x0000FFFD
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	ldr r5, [r6, #0x5c]
	ldr r4, .L080595E8 @ =0x0203CD00
	adds r0, r5, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl sub_804A528
	ldr r0, [r6, #0x5c]
	movs r1, #0
	movs r2, #0xa
	movs r3, #1
	bl sub_8046C14
	movs r0, #0
	strh r0, [r6, #0x2c]
	adds r0, r6, #0
	bl Proc_Break
.L080595DC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080595E4: .4byte 0x0000FFFD
.L080595E8: .4byte 0x0203CD00

	thumb_func_start sub_80595EC
sub_80595EC: @ 0x080595EC
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x51
	bne .L0805960E
	movs r0, #0x10
	bl sub_805B9A4
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L0805960E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8059614
sub_8059614: @ 0x08059614
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L08059632
	ldr r0, .L08059668 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl ApplyChapterMapGraphics
	bl RenderMap
.L08059632:
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #4
	movs r1, #0x10
	movs r2, #4
	bl Interpolate
	bl sub_805B9A4
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L08059660
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L08059660:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08059668: .4byte gPlaySt

	thumb_func_start sub_805966C
sub_805966C: @ 0x0805966C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	ldr r1, .L0805968C @ =gUnk_Banim_0201E7C0
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #2
	strh r1, [r0]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805968C: .4byte gUnk_Banim_0201E7C0

	thumb_func_start sub_8059690
sub_8059690: @ 0x08059690
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r2, .L080596A8 @ =gUnk_Banim_02017744
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	cmp r1, #0
	bne .L080596B0
	ldr r0, .L080596AC @ =gUnk_08604798
	b .L080596B2
	.align 2, 0
.L080596A8: .4byte gUnk_Banim_02017744
.L080596AC: .4byte gUnk_08604798
.L080596B0:
	ldr r0, .L08059718 @ =gUnk_086047E0
.L080596B2:
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L0805971C @ =gUnk_085D0E8C
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r4, #0x60]
	movs r3, #0
	movs r1, #0x98
	lsls r1, r1, #6
	strh r1, [r0, #8]
	ldr r1, [r0, #0x1c]
	movs r2, #0x80
	lsls r2, r2, #3
	orrs r1, r2
	str r1, [r0, #0x1c]
	ldrh r1, [r0, #4]
	adds r1, #8
	strh r1, [r0, #4]
	strh r3, [r4, #0x2c]
	bl sub_8047500
	ldr r2, .L08059720 @ =gDispIo+0x3C
	ldr r0, .L08059724 @ =0x0000FFE0
	ldrh r1, [r2]
	ands r0, r1
	ldr r1, .L08059728 @ =0x0000E0FF
	ands r0, r1
	movs r3, #0xe0
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, .L0805972C @ =gUnk_081C1C74
	movs r1, #0x20
	bl sub_8047AB0
	movs r0, #8
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08059718: .4byte gUnk_086047E0
.L0805971C: .4byte gUnk_085D0E8C
.L08059720: .4byte gDispIo+0x3C
.L08059724: .4byte 0x0000FFE0
.L08059728: .4byte 0x0000E0FF
.L0805972C: .4byte gUnk_081C1C74

	thumb_func_start sub_8059730
sub_8059730: @ 0x08059730
	push {r4, lr}
	ldr r4, [r0, #0x5c]
	ldr r2, .L08059750 @ =gUnk_Banim_02017744
	ldr r1, [r2]
	subs r1, #1
	str r1, [r2]
	ldr r0, [r0, #0x60]
	bl BasRemove
	ldr r0, .L08059754 @ =0x0000FFF7
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08059750: .4byte gUnk_Banim_02017744
.L08059754: .4byte 0x0000FFF7

	thumb_func_start sub_8059758
sub_8059758: @ 0x08059758
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x60]
	ldr r0, .L0805978C @ =gUnk_08604C34
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08059790 @ =gUnk_081BFC74
	ldr r5, .L08059794 @ =0x06014000
	ldr r4, .L08059798 @ =gUnk_Banim_0201A77C
	adds r1, r4, #0
	bl LZ77UnCompWram
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r4, #0
	adds r1, r5, #0
	bl RegisterDataMove
	adds r0, r6, #0
	bl Proc_Break
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805978C: .4byte gUnk_08604C34
.L08059790: .4byte gUnk_081BFC74
.L08059794: .4byte 0x06014000
.L08059798: .4byte gUnk_Banim_0201A77C

	thumb_func_start sub_805979C
sub_805979C: @ 0x0805979C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x60]
	ldr r0, .L080597D0 @ =gUnk_08604E30
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L080597D4 @ =gUnk_081C079C
	ldr r5, .L080597D8 @ =0x06014000
	ldr r4, .L080597DC @ =gUnk_Banim_0201A77C
	adds r1, r4, #0
	bl LZ77UnCompWram
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r4, #0
	adds r1, r5, #0
	bl RegisterDataMove
	adds r0, r6, #0
	bl Proc_Break
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080597D0: .4byte gUnk_08604E30
.L080597D4: .4byte gUnk_081C079C
.L080597D8: .4byte 0x06014000
.L080597DC: .4byte gUnk_Banim_0201A77C

	thumb_func_start sub_80597E0
sub_80597E0: @ 0x080597E0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x60]
	ldr r0, .L08059814 @ =gUnk_08604F94
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08059818 @ =gUnk_081C14D0
	ldr r5, .L0805981C @ =0x06014000
	ldr r4, .L08059820 @ =gUnk_Banim_0201A77C
	adds r1, r4, #0
	bl LZ77UnCompWram
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r4, #0
	adds r1, r5, #0
	bl RegisterDataMove
	adds r0, r6, #0
	bl Proc_Break
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08059814: .4byte gUnk_08604F94
.L08059818: .4byte gUnk_081C14D0
.L0805981C: .4byte 0x06014000
.L08059820: .4byte gUnk_Banim_0201A77C

	thumb_func_start sub_8059824
sub_8059824: @ 0x08059824
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x60]
	ldr r0, .L08059858 @ =gUnk_08604C48
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L0805985C @ =gUnk_081BFC74
	ldr r5, .L08059860 @ =0x06014000
	ldr r4, .L08059864 @ =gUnk_Banim_0201A77C
	adds r1, r4, #0
	bl LZ77UnCompWram
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r4, #0
	adds r1, r5, #0
	bl RegisterDataMove
	adds r0, r6, #0
	bl Proc_Break
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08059858: .4byte gUnk_08604C48
.L0805985C: .4byte gUnk_081BFC74
.L08059860: .4byte 0x06014000
.L08059864: .4byte gUnk_Banim_0201A77C

	thumb_func_start sub_8059868
sub_8059868: @ 0x08059868
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x60]
	ldr r0, .L0805989C @ =gUnk_08604E4C
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L080598A0 @ =gUnk_081C079C
	ldr r5, .L080598A4 @ =0x06014000
	ldr r4, .L080598A8 @ =gUnk_Banim_0201A77C
	adds r1, r4, #0
	bl LZ77UnCompWram
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r4, #0
	adds r1, r5, #0
	bl RegisterDataMove
	adds r0, r6, #0
	bl Proc_Break
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805989C: .4byte gUnk_08604E4C
.L080598A0: .4byte gUnk_081C079C
.L080598A4: .4byte 0x06014000
.L080598A8: .4byte gUnk_Banim_0201A77C

	thumb_func_start sub_80598AC
sub_80598AC: @ 0x080598AC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x60]
	ldr r0, .L080598E0 @ =gUnk_08604FA0
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L080598E4 @ =gUnk_081C14D0
	ldr r5, .L080598E8 @ =0x06014000
	ldr r4, .L080598EC @ =gUnk_Banim_0201A77C
	adds r1, r4, #0
	bl LZ77UnCompWram
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r4, #0
	adds r1, r5, #0
	bl RegisterDataMove
	adds r0, r6, #0
	bl Proc_Break
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080598E0: .4byte gUnk_08604FA0
.L080598E4: .4byte gUnk_081C14D0
.L080598E8: .4byte 0x06014000
.L080598EC: .4byte gUnk_Banim_0201A77C

	thumb_func_start sub_80598F0
sub_80598F0: @ 0x080598F0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_804B6C4
	adds r4, r0, #0
	ldr r0, .L08059920 @ =gUnk_08604828
	movs r1, #4
	bl SpawnProc
	ldr r1, .L08059924 @ =gUnk_Banim_0201E7B4
	lsls r4, r4, #2
	adds r4, r4, r1
	str r0, [r4]
	adds r2, r0, #0
	adds r2, #0x29
	movs r1, #0
	strb r1, [r2]
	str r5, [r0, #0x5c]
	ldrb r1, [r5, #0x12]
	str r1, [r0, #0x54]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08059920: .4byte gUnk_08604828
.L08059924: .4byte gUnk_Banim_0201E7B4

	thumb_func_start sub_8059928
sub_8059928: @ 0x08059928
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_8046F48
	adds r1, r0, #0
	cmp r1, #0
	bne .L080599CA
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r2, [r0]
	adds r5, r0, #0
	cmp r2, #0
	beq .L0805994A
	cmp r2, #1
	beq .L08059958
	b .L08059968
.L0805994A:
	strh r1, [r4, #0x2c]
	str r1, [r4, #0x44]
	ldr r0, .L08059954 @ =gUnk_081BC0C8
	b .L0805995E
	.align 2, 0
.L08059954: .4byte gUnk_081BC0C8
.L08059958:
	strh r1, [r4, #0x2c]
	str r1, [r4, #0x44]
	ldr r0, .L08059994 @ =gUnk_081BC0EE
.L0805995E:
	str r0, [r4, #0x48]
	ldr r0, .L08059998 @ =gUnk_081BF434
	str r0, [r4, #0x4c]
	movs r0, #2
	strb r0, [r5]
.L08059968:
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L080599A0
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, .L0805999C @ =gPal+0xC0
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	b .L080599AC
	.align 2, 0
.L08059994: .4byte gUnk_081BC0EE
.L08059998: .4byte gUnk_081BF434
.L0805999C: .4byte gPal+0xC0
.L080599A0:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080599AC
	movs r0, #0
	strb r0, [r5]
.L080599AC:
	ldr r0, [r4, #0x5c]
	ldrb r1, [r0, #0x12]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	beq .L080599C4
	adds r0, r1, #0
	cmp r0, #1
	beq .L080599C0
	cmp r0, #3
	bne .L080599C4
.L080599C0:
	movs r0, #1
	strb r0, [r5]
.L080599C4:
	ldr r0, [r4, #0x5c]
	ldrb r0, [r0, #0x12]
	str r0, [r4, #0x54]
.L080599CA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_80599D0
sub_80599D0: @ 0x080599D0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl sub_804B6C4
	adds r4, r0, #0
	ldr r0, .L08059A10 @ =gUnk_08604840
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	ldr r0, .L08059A14 @ =gUnk_Banim_0201E7AC
	lsls r4, r4, #2
	adds r4, r4, r0
	str r6, [r4]
	adds r0, r5, #0
	bl sub_804B6C4
	ldr r1, .L08059A18 @ =gUnk_Banim_0201E7C8
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
	str r5, [r6, #0x5c]
	adds r0, r5, #0
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08059A1C
	movs r0, #0x3c
	b .L08059A1E
	.align 2, 0
.L08059A10: .4byte gUnk_08604840
.L08059A14: .4byte gUnk_Banim_0201E7AC
.L08059A18: .4byte gUnk_Banim_0201E7C8
.L08059A1C:
	movs r0, #0
.L08059A1E:
	strh r0, [r6, #0x2c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8059A28
sub_8059A28: @ 0x08059A28
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3d
	bne .L08059A40
	adds r0, r1, #0
	bl Proc_Break
.L08059A40:
	pop {r0}
	bx r0

	thumb_func_start sub_8059A44
sub_8059A44: @ 0x08059A44
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, .L08059AA0 @ =0x0203CD08
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r4, [r0, r1]
	ldr r0, .L08059AA4 @ =0x086A0B68
	ldr r0, [r0, #0x1c]
	ldr r6, .L08059AA8 @ =gUnk_Banim_0201C77C
	adds r1, r6, #0
	bl LZ77UnCompWram
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	movs r1, #0xd0
	lsls r1, r1, #1
	cmp r0, #0
	bne .L08059A74
	subs r1, #0x20
.L08059A74:
	lsls r0, r4, #5
	adds r0, r0, r6
	lsls r1, r1, #1
	ldr r2, .L08059AAC @ =gPal
	adds r1, r1, r2
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	ldr r0, [r5, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08059AB0
	adds r0, r5, #0
	bl Proc_Break
	b .L08059ACA
	.align 2, 0
.L08059AA0: .4byte 0x0203CD08
.L08059AA4: .4byte 0x086A0B68
.L08059AA8: .4byte gUnk_Banim_0201C77C
.L08059AAC: .4byte gPal
.L08059AB0:
	movs r0, #0
	strh r0, [r5, #0x2c]
	ldr r0, [r5, #0x5c]
	movs r1, #0x6b
	bl sub_804A528
	ldr r0, [r5, #0x5c]
	movs r1, #0
	bl sub_804B5E0
	adds r0, r5, #0
	bl Proc_Break
.L08059ACA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_8059AD0
sub_8059AD0: @ 0x08059AD0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
	cmp r5, #1
	bne .L08059B04
	ldr r0, [r4, #0x5c]
	movs r1, #0x5b
	bl sub_804A528
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	ldr r1, .L08059B00 @ =gUnk_Banim_0201E7C0
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r5, [r0]
	adds r0, r4, #0
	bl Proc_Break
	b .L08059B6E
	.align 2, 0
.L08059B00: .4byte gUnk_Banim_0201E7C0
.L08059B04:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1a
	bne .L08059B2A
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xdc
	bl sub_805BCA8
	ldr r0, [r4, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r0, #0xdc
	movs r2, #1
	bl sub_805BDC0
.L08059B2A:
	ldr r0, [r4, #0x5c]
	ldr r1, [r0, #0x20]
	movs r0, #0x3f
	ldrb r1, [r1, #3]
	ands r0, r1
	cmp r0, #0
	bne .L08059B6E
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xde
	bl sub_805BCA8
	ldr r0, [r4, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r0, #0xde
	movs r2, #1
	bl sub_805BDC0
	ldr r0, [r4, #0x5c]
	movs r1, #0x5b
	bl sub_804A528
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	ldr r1, .L08059B74 @ =gUnk_Banim_0201E7C0
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
	adds r0, r4, #0
	bl Proc_Break
.L08059B6E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08059B74: .4byte gUnk_Banim_0201E7C0

	thumb_func_start sub_8059B78
sub_8059B78: @ 0x08059B78
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L08059BA4 @ =gUnk_Banim_0201E7C8
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #2
	bne .L08059BDC
	ldr r0, [r5, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08059BA8
	adds r0, r5, #0
	bl Proc_Break
	b .L08059BDC
	.align 2, 0
.L08059BA4: .4byte gUnk_Banim_0201E7C8
.L08059BA8:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xdd
	bl sub_805BCA8
	ldr r0, [r5, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r0, #0xdd
	movs r2, #1
	bl sub_805BDC0
	ldr r0, [r5, #0x5c]
	movs r1, #0x6c
	bl sub_804A528
	ldr r0, [r5, #0x5c]
	movs r1, #0
	bl sub_804B5E0
	ldr r0, [r5, #0x5c]
	bl sub_8059C78
	adds r0, r5, #0
	bl Proc_Break
.L08059BDC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8059BE4
sub_8059BE4: @ 0x08059BE4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08059C02
	movs r0, #0x3c
	strh r0, [r6, #0x2c]
	adds r0, r6, #0
	bl Proc_Break
	b .L08059C2E
.L08059C02:
	ldr r5, [r6, #0x5c]
	ldr r0, [r5, #0x20]
	movs r7, #0x3f
	ldrb r0, [r0, #3]
	ands r7, r0
	cmp r7, #0
	bne .L08059C2E
	ldr r4, .L08059C34 @ =0x0203CD00
	adds r0, r5, #0
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl sub_804A528
	strh r7, [r6, #0x2c]
	adds r0, r6, #0
	bl Proc_Break
.L08059C2E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08059C34: .4byte 0x0203CD00

	thumb_func_start sub_8059C38
sub_8059C38: @ 0x08059C38
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3d
	bne .L08059C50
	adds r0, r1, #0
	bl Proc_Break
.L08059C50:
	pop {r0}
	bx r0

	thumb_func_start sub_8059C54
sub_8059C54: @ 0x08059C54
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	ldr r1, .L08059C74 @ =gUnk_Banim_0201E7C0
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #2
	strh r1, [r0]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08059C74: .4byte gUnk_Banim_0201E7C0

	thumb_func_start sub_8059C78
sub_8059C78: @ 0x08059C78
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08059CD0 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08059CD4 @ =gUnk_08604888
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08059CD8 @ =gUnk_081BC0FC
	str r0, [r5, #0x48]
	ldr r0, .L08059CDC @ =gUnk_086048A0
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08059CE0 @ =gUnk_081C864C
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, .L08059CE4 @ =gUnk_081C8F38
	movs r1, #0x20
	bl sub_8047AF4
	bl sub_8047500
	ldr r0, .L08059CE8 @ =0x0203CD14
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08059CF8
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L08059CEC
	movs r0, #1
	movs r1, #0x18
	b .L08059CF0
	.align 2, 0
.L08059CD0: .4byte gUnk_Banim_02017744
.L08059CD4: .4byte gUnk_08604888
.L08059CD8: .4byte gUnk_081BC0FC
.L08059CDC: .4byte gUnk_086048A0
.L08059CE0: .4byte gUnk_081C864C
.L08059CE4: .4byte gUnk_081C8F38
.L08059CE8: .4byte 0x0203CD14
.L08059CEC:
	movs r0, #1
	movs r1, #0xe8
.L08059CF0:
	movs r2, #0
	bl SetBgOffset
	b .L08059D02
.L08059CF8:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
.L08059D02:
	ldr r3, .L08059D30 @ =gDispIo
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
	adds r0, r3, #0
	adds r0, #0x45
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08059D30: .4byte gDispIo

	thumb_func_start sub_8059D34
sub_8059D34: @ 0x08059D34
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L08059D62
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl sub_804799C
	b .L08059D80
.L08059D62:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L08059D80
	bl sub_80474D8
	ldr r1, .L08059D88 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl sub_80475D8
	adds r0, r4, #0
	bl Proc_Break
.L08059D80:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08059D88: .4byte gUnk_Banim_02017744

	thumb_func_start sub_8059D8C
sub_8059D8C: @ 0x08059D8C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl sub_804B6C4
	adds r4, r0, #0
	ldr r0, .L08059DC4 @ =gUnk_086048D0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	ldr r0, .L08059DC8 @ =gUnk_Banim_0201E7AC
	lsls r4, r4, #2
	adds r4, r4, r0
	str r5, [r4]
	adds r0, r6, #0
	bl sub_804B6C4
	ldr r1, .L08059DCC @ =gUnk_Banim_0201E7C8
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	movs r1, #1
	strh r1, [r0]
	str r6, [r5, #0x5c]
	strh r2, [r5, #0x2c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08059DC4: .4byte gUnk_086048D0
.L08059DC8: .4byte gUnk_Banim_0201E7AC
.L08059DCC: .4byte gUnk_Banim_0201E7C8

	thumb_func_start sub_8059DD0
sub_8059DD0: @ 0x08059DD0
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #1
	movs r1, #4
	movs r2, #0x10
	bl Interpolate
	bl sub_805B9A4
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L08059E00
	adds r0, r4, #0
	bl Proc_Break
.L08059E00:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8059E08
sub_8059E08: @ 0x08059E08
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	movs r1, #0x74
	bl sub_804A528
	ldr r0, .L08059E6C @ =gUnk_Banim_02000000
	ldr r3, [r0]
	ldr r4, [r0, #4]
	ldr r2, .L08059E70 @ =gUnk_Banim_02000020
	ldr r7, .L08059E74 @ =gUnk_Banim_02000028
	ldrh r1, [r7]
	adds r1, #0x54
	strh r1, [r2]
	ldr r6, .L08059E78 @ =gUnk_Banim_0201E12C
	ldr r0, [r6]
	subs r1, r1, r0
	strh r1, [r3, #2]
	ldrh r2, [r2]
	subs r0, r2, r0
	strh r0, [r4, #2]
	ldr r0, [r5, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L08059E5A
	ldr r0, [r5, #0x5c]
	bl sub_805A77C
	ldr r2, .L08059E7C @ =gUnk_Banim_0201E7B4
	str r0, [r2]
	ldr r1, [r6]
	subs r1, #0x4e
	ldrh r7, [r7]
	subs r1, r7, r1
	strh r1, [r0, #0x34]
	ldr r1, [r2]
	movs r0, #0x50
	strh r0, [r1, #0x3c]
.L08059E5A:
	movs r0, #0
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08059E6C: .4byte gUnk_Banim_02000000
.L08059E70: .4byte gUnk_Banim_02000020
.L08059E74: .4byte gUnk_Banim_02000028
.L08059E78: .4byte gUnk_Banim_0201E12C
.L08059E7C: .4byte gUnk_Banim_0201E7B4

	thumb_func_start sub_8059E80
sub_8059E80: @ 0x08059E80
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, .L08059EFC @ =gUnk_081C1C94
	ldr r1, .L08059F00 @ =0x06008000
	bl LZ77UnCompVram
	ldr r0, .L08059F04 @ =gUnk_081C5AAC
	ldr r1, .L08059F08 @ =gUnk_Banim_0201977C
	bl LZ77UnCompWram
	ldr r0, .L08059F0C @ =0x001F001F
	bl sub_8047C68
	ldr r0, .L08059F10 @ =gBg3Tm
	movs r1, #0x1f
	bl TmFill
	movs r0, #8
	bl EnableBgSync
	ldr r0, .L08059F14 @ =gUnk_081C4DE8
	ldr r4, .L08059F18 @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r1, .L08059F1C @ =gUnk_Banim_0201EFCC
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, .L08059F20 @ =gUnk_Banim_0201EFEC
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	subs r0, #0x40
	ldr r1, .L08059F24 @ =gUnk_Banim_0201F00C
	movs r2, #0x10
	bl CpuFastSet
	movs r0, #0
	str r0, [sp]
	ldr r2, .L08059F28 @ =0x01000008
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	bl EnablePalSync
	adds r0, r5, #0
	bl Proc_Break
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08059EFC: .4byte gUnk_081C1C94
.L08059F00: .4byte 0x06008000
.L08059F04: .4byte gUnk_081C5AAC
.L08059F08: .4byte gUnk_Banim_0201977C
.L08059F0C: .4byte 0x001F001F
.L08059F10: .4byte gBg3Tm
.L08059F14: .4byte gUnk_081C4DE8
.L08059F18: .4byte gPal+0xC0
.L08059F1C: .4byte gUnk_Banim_0201EFCC
.L08059F20: .4byte gUnk_Banim_0201EFEC
.L08059F24: .4byte gUnk_Banim_0201F00C
.L08059F28: .4byte 0x01000008

	thumb_func_start sub_8059F2C
sub_8059F2C: @ 0x08059F2C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, .L08059F4C @ =gUnk_Banim_0201E7B4
	ldr r5, [r0]
	ldr r0, [r6, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08059F50
	adds r0, r6, #0
	bl Proc_Break
	b .L08059FE4
	.align 2, 0
.L08059F4C: .4byte gUnk_Banim_0201E7B4
.L08059F50:
	movs r0, #0x34
	ldrsh r2, [r5, r0]
	adds r1, r2, #0
	adds r1, #0x30
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r4, #0x10
	str r4, [sp]
	movs r0, #1
	bl Interpolate
	strh r0, [r5, #0x32]
	movs r1, #0x3c
	ldrsh r2, [r5, r1]
	adds r1, r2, #0
	subs r1, #0x80
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	str r4, [sp]
	movs r0, #1
	bl Interpolate
	strh r0, [r5, #0x3a]
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x11
	bne .L08059FE4
	ldr r0, .L08059FEC @ =gUnk_Banim_0201EFCC
	ldr r4, .L08059FF0 @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L08059FF4 @ =gUnk_Banim_0201EFEC
	movs r1, #0x88
	lsls r1, r1, #2
	adds r4, r4, r1
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L08059FF8 @ =gUnk_081C4E28
	bl sub_8058FA8
	ldr r0, [r6, #0x5c]
	movs r1, #3
	movs r2, #0x64
	bl sub_804685C
	ldr r4, .L08059FFC @ =0x0000013F
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, #0
	bl sub_805BCA8
	ldr r0, [r6, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	adds r0, r4, #0
	movs r2, #1
	bl sub_805BDC0
	movs r0, #6
	bl sub_8046010
	adds r5, r0, #0
	movs r0, #0x72
	strh r0, [r5, #0x3c]
	adds r0, r6, #0
	bl Proc_Break
.L08059FE4:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08059FEC: .4byte gUnk_Banim_0201EFCC
.L08059FF0: .4byte gPal+0xC0
.L08059FF4: .4byte gUnk_Banim_0201EFEC
.L08059FF8: .4byte gUnk_081C4E28
.L08059FFC: .4byte 0x0000013F

	thumb_func_start sub_805A000
sub_805A000: @ 0x0805A000
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805A028
	ldr r0, [r4, #0x5c]
	bl sub_805A410
	str r0, [r4, #0x64]
	adds r0, r4, #0
	bl Proc_Break
	b .L0805A096
.L0805A028:
	ldr r5, .L0805A0A4 @ =gUnk_Banim_0201E7B4
	ldr r1, [r5]
	ldr r0, .L0805A0A8 @ =gUnk_Banim_02000028
	mov r8, r0
	ldr r2, .L0805A0AC @ =gUnk_Banim_0201E12C
	mov sb, r2
	ldr r0, [r2]
	subs r0, #0x4e
	mov r3, r8
	ldrh r3, [r3]
	subs r0, r3, r0
	strh r0, [r1, #0x32]
	ldr r0, [r5]
	movs r6, #0x50
	strh r6, [r0, #0x3a]
	ldr r2, .L0805A0B0 @ =gUnk_Banim_02017758
	ldrh r3, [r2]
	ldr r0, .L0805A0B4 @ =0x00007FFF
	cmp r3, r0
	beq .L0805A062
	ldr r1, [r5]
	ldrh r7, [r1, #0x32]
	adds r0, r3, r7
	strh r0, [r1, #0x32]
	ldr r1, [r5]
	ldrh r3, [r1, #0x3a]
	ldrh r2, [r2, #2]
	adds r0, r3, r2
	strh r0, [r1, #0x3a]
.L0805A062:
	ldr r0, .L0805A0B8 @ =gUnk_Banim_02017734
	ldr r0, [r0]
	cmp r0, #0
	bne .L0805A096
	movs r0, #3
	movs r1, #0
	movs r2, #0x82
	bl SetBgOffset
	ldr r1, [r5]
	mov r7, sb
	ldr r0, [r7]
	subs r0, #0x4e
	mov r2, r8
	ldrh r2, [r2]
	subs r0, r2, r0
	strh r0, [r1, #0x32]
	ldr r0, [r5]
	strh r6, [r0, #0x3a]
	ldr r0, [r4, #0x5c]
	bl sub_805A410
	str r0, [r4, #0x64]
	adds r0, r4, #0
	bl Proc_Break
.L0805A096:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A0A4: .4byte gUnk_Banim_0201E7B4
.L0805A0A8: .4byte gUnk_Banim_02000028
.L0805A0AC: .4byte gUnk_Banim_0201E12C
.L0805A0B0: .4byte gUnk_Banim_02017758
.L0805A0B4: .4byte 0x00007FFF
.L0805A0B8: .4byte gUnk_Banim_02017734

	thumb_func_start sub_805A0BC
sub_805A0BC: @ 0x0805A0BC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x64]
	adds r5, r0, #0
	adds r5, #0x29
	ldrb r0, [r5]
	cmp r0, #1
	bne .L0805A132
	ldr r0, [r4, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805A0E2
	adds r0, r4, #0
	bl Proc_Break
	b .L0805A132
.L0805A0E2:
	movs r1, #0
	movs r0, #2
	strb r0, [r5]
	strh r1, [r4, #0x2c]
	ldr r0, [r4, #0x5c]
	bl sub_805A598
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x5c]
	bl sub_805A7EC
	adds r1, r0, #0
	ldr r0, .L0805A10C @ =gUnk_Banim_0201E7B4
	str r1, [r0, #4]
	ldr r0, .L0805A110 @ =0x0203CD14
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L0805A114
	movs r0, #0x54
	b .L0805A116
	.align 2, 0
.L0805A10C: .4byte gUnk_Banim_0201E7B4
.L0805A110: .4byte 0x0203CD14
.L0805A114:
	movs r0, #0x34
.L0805A116:
	strh r0, [r1, #0x32]
	ldr r0, .L0805A138 @ =gUnk_Banim_0201E7B4
	ldr r1, [r0, #4]
	ldr r0, .L0805A13C @ =0x0000FFF5
	strh r0, [r1, #0x3a]
	movs r0, #0xa2
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	bl sub_805BCA8
	adds r0, r4, #0
	bl Proc_Break
.L0805A132:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A138: .4byte gUnk_Banim_0201E7B4
.L0805A13C: .4byte 0x0000FFF5

	thumb_func_start sub_805A140
sub_805A140: @ 0x0805A140
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r7, [r5, #0x64]
	ldr r6, .L0805A198 @ =gUnk_Banim_0201E7B4
	ldr r0, [r6]
	mov r8, r0
	ldr r1, [r6, #4]
	mov sb, r1
	ldr r0, [r5, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	cmp r4, #1
	bne .L0805A1A8
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	bl sub_804B8E8
	ldr r0, .L0805A19C @ =gUnk_Banim_0201EFCC
	ldr r1, .L0805A1A0 @ =gPal+0xC0
	movs r2, #8
	bl CpuFastSet
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	ldr r1, .L0805A1A4 @ =gUnk_Banim_0201E7C0
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	ldr r0, [r5, #0x5c]
	bl sub_805A858
	adds r0, r5, #0
	bl Proc_Break
	b .L0805A216
	.align 2, 0
.L0805A198: .4byte gUnk_Banim_0201E7B4
.L0805A19C: .4byte gUnk_Banim_0201EFCC
.L0805A1A0: .4byte gPal+0xC0
.L0805A1A4: .4byte gUnk_Banim_0201E7C0
.L0805A1A8:
	movs r2, #0x2c
	ldrsh r3, [r5, r2]
	movs r0, #0x90
	lsls r0, r0, #1
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x72
	bl Interpolate
	rsbs r1, r0, #0
	adds r1, #0x82
	strh r1, [r7, #0x3a]
	adds r1, r0, #0
	adds r1, #0x50
	mov r2, r8
	strh r1, [r2, #0x3a]
	subs r0, #0xb
	mov r1, sb
	strh r0, [r1, #0x3a]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	bne .L0805A216
	adds r0, r7, #0
	adds r0, #0x29
	movs r4, #1
	strb r4, [r0]
	ldr r0, [r6]
	adds r0, #0x29
	strb r4, [r0]
	ldr r0, [r6, #4]
	adds r0, #0x29
	strb r4, [r0]
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	bl sub_804B8E8
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	ldr r1, .L0805A224 @ =gUnk_Banim_0201E7C0
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	ldr r0, [r5, #0x5c]
	bl sub_805A858
	adds r0, r5, #0
	bl Proc_Break
.L0805A216:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A224: .4byte gUnk_Banim_0201E7C0

	thumb_func_start sub_805A228
sub_805A228: @ 0x0805A228
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0805A268 @ =gUnk_Banim_0201E7C8
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #2
	bne .L0805A262
	bl sub_805A894
	ldr r4, .L0805A26C @ =gUnk_Banim_0201E7C4
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #1
	bne .L0805A25C
	ldr r0, [r5, #0x5c]
	bl sub_805AB5C
	str r0, [r5, #0x64]
.L0805A25C:
	adds r0, r5, #0
	bl Proc_Break
.L0805A262:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A268: .4byte gUnk_Banim_0201E7C8
.L0805A26C: .4byte gUnk_Banim_0201E7C4

	thumb_func_start sub_805A270
sub_805A270: @ 0x0805A270
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x64]
	ldr r4, .L0805A29C @ =gUnk_Banim_0201E7C4
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0805A2A0
	ldr r0, [r5, #0x5c]
	movs r1, #1
	movs r2, #0x20
	bl sub_805A658
	str r0, [r5, #0x64]
	adds r0, r5, #0
	bl Proc_Break
	b .L0805A2B4
	.align 2, 0
.L0805A29C: .4byte gUnk_Banim_0201E7C4
.L0805A2A0:
	adds r1, r6, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #1
	bne .L0805A2B4
	movs r0, #2
	strb r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L0805A2B4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805A2BC
sub_805A2BC: @ 0x0805A2BC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x64]
	ldr r4, .L0805A2E0 @ =gUnk_Banim_0201E7C4
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #1
	bne .L0805A2E4
	ldr r0, [r5, #0x5c]
	bl sub_805A4C8
	str r0, [r5, #0x64]
	b .L0805A30E
	.align 2, 0
.L0805A2E0: .4byte gUnk_Banim_0201E7C4
.L0805A2E4:
	ldr r0, [r5, #0x5c]
	bl sub_80589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805A316
	adds r1, r6, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #1
	bne .L0805A352
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5, #0x5c]
	bl sub_805A4C8
	str r0, [r5, #0x64]
	movs r0, #0x10
	bl sub_805B9A4
.L0805A30E:
	adds r0, r5, #0
	bl Proc_Break
	b .L0805A352
.L0805A316:
	adds r1, r6, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #1
	bne .L0805A352
	movs r4, #0
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5, #0x5c]
	bl sub_805A4C8
	str r0, [r5, #0x64]
	movs r0, #0x10
	bl sub_805B9A4
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	ldr r1, .L0805A358 @ =0x0203CCF8
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	bl sub_804B8B0
	adds r0, r5, #0
	bl Proc_Break
.L0805A352:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A358: .4byte 0x0203CCF8

	thumb_func_start sub_805A35C
sub_805A35C: @ 0x0805A35C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x64]
	adds r1, r0, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #1
	bne .L0805A38A
	movs r4, #0
	movs r0, #2
	strb r0, [r1]
	ldr r0, .L0805A390 @ =gBg3Tm
	movs r1, #0xf0
	lsls r1, r1, #8
	bl TmFill
	movs r0, #8
	bl EnableBgSync
	strh r4, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L0805A38A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A390: .4byte gBg3Tm

	thumb_func_start sub_805A394
sub_805A394: @ 0x0805A394
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L0805A3B2
	ldr r0, .L0805A3E8 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl ApplyChapterMapGraphics
	bl RenderMap
.L0805A3B2:
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #4
	movs r1, #0x10
	movs r2, #4
	bl Interpolate
	bl sub_805B9A4
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L0805A3E0
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L0805A3E0:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A3E8: .4byte gPlaySt

	thumb_func_start sub_805A3EC
sub_805A3EC: @ 0x0805A3EC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B6C4
	ldr r1, .L0805A40C @ =gUnk_Banim_0201E7C0
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #2
	strh r1, [r0]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A40C: .4byte gUnk_Banim_0201E7C0

	thumb_func_start sub_805A410
sub_805A410: @ 0x0805A410
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805A430 @ =gUnk_08604948
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	adds r2, r0, #0
	adds r2, #0x29
	movs r1, #0
	strb r1, [r2]
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A430: .4byte gUnk_08604948

	thumb_func_start sub_805A434
sub_805A434: @ 0x0805A434
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0805A4A8 @ =gUnk_Banim_0201F00C
	ldr r4, .L0805A4AC @ =gPal+0x80
	adds r1, r4, #0
	movs r2, #0x10
	bl CpuFastSet
	subs r4, #0x80
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	adds r3, r5, #0
	bl sub_805B5C8
	bl EnablePalSync
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	movs r2, #0
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L0805A4A0
	strh r2, [r6, #0x2c]
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L0805A4B0 @ =gBg2Tm+0x2C0
	str r2, [sp]
	movs r1, #0x1e
	movs r2, #5
	movs r3, #0
	bl sub_805B094
	movs r0, #4
	bl EnableBgSync
	adds r0, r6, #0
	bl Proc_Break
.L0805A4A0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A4A8: .4byte gUnk_Banim_0201F00C
.L0805A4AC: .4byte gPal+0x80
.L0805A4B0: .4byte gBg2Tm+0x2C0

	thumb_func_start sub_805A4B4
sub_805A4B4: @ 0x0805A4B4
	push {lr}
	adds r1, r0, #0
	adds r1, #0x29
	ldrb r1, [r1]
	cmp r1, #2
	bne .L0805A4C4
	bl Proc_Break
.L0805A4C4:
	pop {r0}
	bx r0

	thumb_func_start sub_805A4C8
sub_805A4C8: @ 0x0805A4C8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L0805A50C @ =gUnk_08604968
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	strh r0, [r5, #0x2c]
	ldr r0, .L0805A510 @ =gUnk_Banim_0201E0FC
	bl sub_804BF40
	ldr r4, .L0805A514 @ =gPal+0x80
	ldr r1, .L0805A518 @ =gUnk_Banim_0201F00C
	adds r0, r4, #0
	movs r2, #0x10
	bl CpuFastSet
	subs r4, #0x80
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	movs r3, #0x10
	bl sub_805B5C8
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A50C: .4byte gUnk_08604968
.L0805A510: .4byte gUnk_Banim_0201E0FC
.L0805A514: .4byte gPal+0x80
.L0805A518: .4byte gUnk_Banim_0201F00C

	thumb_func_start sub_805A51C
sub_805A51C: @ 0x0805A51C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #1
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0805A57C @ =gUnk_Banim_0201F00C
	ldr r4, .L0805A580 @ =gPal+0x80
	adds r1, r4, #0
	movs r2, #0x10
	bl CpuFastSet
	subs r4, #0x80
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	adds r3, r5, #0
	bl sub_805B5C8
	bl EnablePalSync
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L0805A574
	movs r0, #0
	strh r0, [r6, #0x2c]
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl Proc_Break
.L0805A574:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A57C: .4byte gUnk_Banim_0201F00C
.L0805A580: .4byte gPal+0x80

	thumb_func_start sub_805A584
sub_805A584: @ 0x0805A584
	push {lr}
	adds r1, r0, #0
	adds r1, #0x29
	ldrb r1, [r1]
	cmp r1, #2
	bne .L0805A594
	bl Proc_Break
.L0805A594:
	pop {r0}
	bx r0

	thumb_func_start sub_805A598
sub_805A598: @ 0x0805A598
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805A5C0 @ =gUnk_08604988
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r3, #0
	movs r2, #0
	strh r2, [r0, #0x32]
	strh r2, [r0, #0x3a]
	movs r1, #9
	strh r1, [r0, #0x2c]
	strh r2, [r0, #0x2e]
	adds r1, r0, #0
	adds r1, #0x29
	strb r3, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A5C0: .4byte gUnk_08604988

	thumb_func_start sub_805A5C4
sub_805A5C4: @ 0x0805A5C4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	bne .L0805A616
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L0805A5EC
	ldr r0, .L0805A5E8 @ =gUnk_081C4E28
	bl sub_8058FA8
	b .L0805A602
	.align 2, 0
.L0805A5E8: .4byte gUnk_081C4E28
.L0805A5EC:
	cmp r0, #1
	bne .L0805A5FC
	ldr r0, .L0805A5F8 @ =gUnk_081C5264
	bl sub_8058FA8
	b .L0805A602
	.align 2, 0
.L0805A5F8: .4byte gUnk_081C5264
.L0805A5FC:
	ldr r0, .L0805A638 @ =gUnk_081C5688
	bl sub_8058FA8
.L0805A602:
	movs r1, #0
	strh r1, [r4, #0x2c]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bne .L0805A616
	strh r1, [r4, #0x2e]
.L0805A616:
	ldrh r1, [r4, #0x32]
	ldrh r2, [r4, #0x3a]
	movs r0, #3
	bl SetBgOffset
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0805A630
	adds r0, r4, #0
	bl Proc_Break
.L0805A630:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A638: .4byte gUnk_081C5688

	thumb_func_start sub_805A63C
sub_805A63C: @ 0x0805A63C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x32]
	ldrh r2, [r4, #0x3a]
	movs r0, #3
	bl SetBgOffset
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805A658
sub_805A658: @ 0x0805A658
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	mov r8, r1
	adds r6, r2, #0
	ldr r0, .L0805A6A8 @ =gUnk_086049A8
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	strh r0, [r5, #0x2c]
	strh r6, [r5, #0x2e]
	mov r0, r8
	strh r0, [r5, #0x30]
	ldr r4, .L0805A6AC @ =gPal+0xC0
	ldr r1, .L0805A6B0 @ =gUnk_Banim_0201EFCC
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	movs r0, #0x88
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r1, .L0805A6B4 @ =gUnk_Banim_0201EFEC
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r5, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A6A8: .4byte gUnk_086049A8
.L0805A6AC: .4byte gPal+0xC0
.L0805A6B0: .4byte gUnk_Banim_0201EFCC
.L0805A6B4: .4byte gUnk_Banim_0201EFEC

	thumb_func_start sub_805A6B8
sub_805A6B8: @ 0x0805A6B8
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r2, #0x30]
	lsls r1, r3, #0x10
	cmp r0, r1
	bne .L0805A6D6
	movs r0, #0
	strh r0, [r2, #0x2c]
	adds r0, r2, #0
	bl Proc_Break
.L0805A6D6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805A6DC
sub_805A6DC: @ 0x0805A6DC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0805A75C @ =gUnk_Banim_0201EFCC
	ldr r4, .L0805A760 @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L0805A764 @ =gUnk_Banim_0201EFEC
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #8
	bl CpuFastSet
	subs r4, #0xc0
	adds r0, r4, #0
	movs r1, #6
	movs r2, #1
	adds r3, r5, #0
	bl sub_805B5C8
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #1
	adds r3, r5, #0
	bl sub_805B5C8
	bl EnablePalSync
	ldrh r1, [r6, #0x2c]
	adds r1, #1
	strh r1, [r6, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	adds r0, #1
	cmp r1, r0
	bne .L0805A752
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl Proc_Break
.L0805A752:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A75C: .4byte gUnk_Banim_0201EFCC
.L0805A760: .4byte gPal+0xC0
.L0805A764: .4byte gUnk_Banim_0201EFEC

	thumb_func_start sub_805A768
sub_805A768: @ 0x0805A768
	push {lr}
	adds r1, r0, #0
	adds r1, #0x29
	ldrb r1, [r1]
	cmp r1, #2
	bne .L0805A778
	bl Proc_Break
.L0805A778:
	pop {r0}
	bx r0

	thumb_func_start sub_805A77C
sub_805A77C: @ 0x0805A77C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L0805A7B8 @ =gUnk_086049D0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r0, .L0805A7BC @ =gUnk_08605A50
	movs r1, #0x78
	bl BasCreate
	movs r2, #0
	movs r1, #0xf4
	lsls r1, r1, #7
	strh r1, [r0, #8]
	movs r1, #0xc0
	lsls r1, r1, #1
	strh r1, [r4, #0x32]
	strh r1, [r0, #2]
	strh r1, [r4, #0x3a]
	strh r1, [r0, #4]
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x29
	strb r2, [r0]
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A7B8: .4byte gUnk_086049D0
.L0805A7BC: .4byte gUnk_08605A50

	thumb_func_start sub_805A7C0
sub_805A7C0: @ 0x0805A7C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x60]
	ldrh r1, [r4, #0x32]
	strh r1, [r0, #2]
	ldrh r1, [r4, #0x3a]
	strh r1, [r0, #4]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0805A7E4
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0805A7E4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805A7EC
sub_805A7EC: @ 0x0805A7EC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L0805A824 @ =gUnk_086049E8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r0, .L0805A828 @ =gUnk_08605A70
	movs r1, #0x78
	bl BasCreate
	movs r2, #0
	movs r1, #0xf4
	lsls r1, r1, #7
	strh r1, [r0, #8]
	movs r1, #0xc0
	lsls r1, r1, #1
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x29
	strb r2, [r0]
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A824: .4byte gUnk_086049E8
.L0805A828: .4byte gUnk_08605A70

	thumb_func_start sub_805A82C
sub_805A82C: @ 0x0805A82C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x60]
	ldrh r1, [r4, #0x32]
	strh r1, [r0, #2]
	ldrh r1, [r4, #0x3a]
	strh r1, [r0, #4]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0805A850
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0805A850:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805A858
sub_805A858: @ 0x0805A858
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805A884 @ =gUnk_08604A00
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	str r1, [r0, #0x44]
	ldr r1, .L0805A888 @ =gUnk_081BC132
	str r1, [r0, #0x48]
	ldr r1, .L0805A88C @ =gUnk_08604A18
	str r1, [r0, #0x4c]
	ldrb r1, [r4, #0x12]
	str r1, [r0, #0x54]
	ldr r1, .L0805A890 @ =gUnk_Banim_0201E7BC
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A884: .4byte gUnk_08604A00
.L0805A888: .4byte gUnk_081BC132
.L0805A88C: .4byte gUnk_08604A18
.L0805A890: .4byte gUnk_Banim_0201E7BC

	thumb_func_start sub_805A894
sub_805A894: @ 0x0805A894
	push {r4, lr}
	ldr r4, .L0805A8AC @ =gUnk_Banim_0201E7BC
	ldr r0, [r4]
	cmp r0, #0
	beq .L0805A8A6
	bl Proc_End
	movs r0, #0
	str r0, [r4]
.L0805A8A6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A8AC: .4byte gUnk_Banim_0201E7BC

	thumb_func_start sub_805A8B0
sub_805A8B0: @ 0x0805A8B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	ldrb r1, [r0, #0x12]
	ldr r0, [r4, #0x54]
	cmp r0, r1
	beq .L0805A930
	str r1, [r4, #0x54]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	str r0, [r4, #0x44]
	cmp r1, #9
	bhi .L0805A930
	lsls r0, r1, #2
	ldr r1, .L0805A8D8 @ =.L0805A8DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0805A8D8: .4byte .L0805A8DC
.L0805A8DC: @ jump table
	.4byte .L0805A904 @ case 0
	.4byte .L0805A91C @ case 1
	.4byte .L0805A90C @ case 2
	.4byte .L0805A914 @ case 3
	.4byte .L0805A92C @ case 4
	.4byte .L0805A92C @ case 5
	.4byte .L0805A92C @ case 6
	.4byte .L0805A92C @ case 7
	.4byte .L0805A92C @ case 8
	.4byte .L0805A904 @ case 9
.L0805A904:
	ldr r0, .L0805A908 @ =gUnk_081BC140
	b .L0805A92E
	.align 2, 0
.L0805A908: .4byte gUnk_081BC140
.L0805A90C:
	ldr r0, .L0805A910 @ =gUnk_081BC15E
	b .L0805A92E
	.align 2, 0
.L0805A910: .4byte gUnk_081BC15E
.L0805A914:
	ldr r0, .L0805A918 @ =gUnk_081BC17C
	b .L0805A92E
	.align 2, 0
.L0805A918: .4byte gUnk_081BC17C
.L0805A91C:
	ldr r0, .L0805A928 @ =gUnk_081BC19A
	str r0, [r4, #0x48]
	ldr r0, [r4, #0x5c]
	bl sub_8057B90
	b .L0805A930
	.align 2, 0
.L0805A928: .4byte gUnk_081BC19A
.L0805A92C:
	ldr r0, .L0805A954 @ =gUnk_081BC132
.L0805A92E:
	str r0, [r4, #0x48]
.L0805A930:
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0805A958
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl sub_8059018
	b .L0805A992
	.align 2, 0
.L0805A954: .4byte gUnk_081BC132
.L0805A958:
	movs r0, #4
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0805A992
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L0805A97E
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	movs r1, #8
	ldrh r0, [r0, #0x10]
	ands r1, r0
	cmp r1, #0
	beq .L0805A992
	movs r0, #1
	strh r0, [r4, #0x2e]
	b .L0805A992
.L0805A97E:
	bl sub_80449C4
	cmp r0, #1
	bne .L0805A992
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
.L0805A992:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_805A998
sub_805A998: @ 0x0805A998
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L0805A9E4 @ =gUnk_08604A3C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	strh r0, [r5, #0x2c]
	movs r0, #0x10
	strh r0, [r5, #0x2e]
	ldr r4, .L0805A9E8 @ =gPal+0xC0
	ldr r1, .L0805A9EC @ =gUnk_Banim_0201EFCC
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	movs r0, #0x88
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r1, .L0805A9F0 @ =gUnk_Banim_0201EFEC
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L0805A9F4 @ =0x00000143
	movs r1, #0x80
	lsls r1, r1, #1
	bl sub_805BCA8
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A9E4: .4byte gUnk_08604A3C
.L0805A9E8: .4byte gPal+0xC0
.L0805A9EC: .4byte gUnk_Banim_0201EFCC
.L0805A9F0: .4byte gUnk_Banim_0201EFEC
.L0805A9F4: .4byte 0x00000143

	thumb_func_start sub_805A9F8
sub_805A9F8: @ 0x0805A9F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	mov r8, r0
	ldr r0, .L0805AA90 @ =gUnk_Banim_0201EFCC
	ldr r4, .L0805AA94 @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r6, .L0805AA98 @ =gUnk_Banim_0201EFEC
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r4, r2
	adds r0, r6, #0
	movs r2, #8
	bl CpuFastSet
	adds r5, r4, #0
	subs r5, #0xc0
	adds r0, r5, #0
	movs r1, #6
	movs r2, #1
	mov r3, r8
	bl sub_805B5C8
	adds r0, r5, #0
	movs r1, #0x17
	movs r2, #1
	mov r3, r8
	bl sub_805B5C8
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r6, #0x1c]
	strh r0, [r1]
	ldr r1, .L0805AA9C @ =0x0000023E
	adds r4, r4, r1
	ldrh r0, [r6, #0x1e]
	strh r0, [r4]
	bl EnablePalSync
	ldrh r1, [r7, #0x2c]
	adds r1, #1
	strh r1, [r7, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	adds r0, #1
	cmp r1, r0
	bne .L0805AA84
	movs r0, #0
	strh r0, [r7, #0x2c]
	adds r0, r7, #0
	bl Proc_Break
.L0805AA84:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AA90: .4byte gUnk_Banim_0201EFCC
.L0805AA94: .4byte gPal+0xC0
.L0805AA98: .4byte gUnk_Banim_0201EFEC
.L0805AA9C: .4byte 0x0000023E

	thumb_func_start sub_805AAA0
sub_805AAA0: @ 0x0805AAA0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	mov r8, r0
	ldr r0, .L0805AB40 @ =gUnk_Banim_0201EFCC
	ldr r4, .L0805AB44 @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r6, .L0805AB48 @ =gUnk_Banim_0201EFEC
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r4, r2
	adds r0, r6, #0
	movs r2, #8
	bl CpuFastSet
	adds r5, r4, #0
	subs r5, #0xc0
	adds r0, r5, #0
	movs r1, #6
	movs r2, #1
	mov r3, r8
	bl sub_805B5C8
	adds r0, r5, #0
	movs r1, #0x17
	movs r2, #1
	mov r3, r8
	bl sub_805B5C8
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r6, #0x1c]
	strh r0, [r1]
	ldr r1, .L0805AB4C @ =0x0000023E
	adds r4, r4, r1
	ldrh r0, [r6, #0x1e]
	strh r0, [r4]
	bl EnablePalSync
	ldrh r1, [r7, #0x2c]
	adds r1, #1
	strh r1, [r7, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	adds r0, #1
	cmp r1, r0
	bne .L0805AB34
	movs r0, #0
	strh r0, [r7, #0x2c]
	adds r1, r7, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	bl Proc_Break
.L0805AB34:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AB40: .4byte gUnk_Banim_0201EFCC
.L0805AB44: .4byte gPal+0xC0
.L0805AB48: .4byte gUnk_Banim_0201EFEC
.L0805AB4C: .4byte 0x0000023E

	thumb_func_start sub_805AB50
sub_805AB50: @ 0x0805AB50
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805AB5C
sub_805AB5C: @ 0x0805AB5C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, .L0805ABB0 @ =gUnk_08604A6C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	adds r0, #0x29
	movs r4, #0
	strb r4, [r0]
	strh r4, [r5, #0x2c]
	ldr r0, .L0805ABB4 @ =gUnk_081C4E28
	ldr r6, .L0805ABB8 @ =gUnk_Banim_0201977C
	adds r1, r6, #0
	bl LZ77UnCompWram
	movs r1, #1
	rsbs r1, r1, #0
	ldr r2, .L0805ABBC @ =gBg3Tm
	movs r0, #0x1e
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #6
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	movs r3, #0x20
	bl sub_805B20C
	ldr r0, [r5, #0x5c]
	movs r1, #0x64
	movs r2, #0xc8
	bl sub_805A658
	str r0, [r5, #0x60]
	adds r0, r5, #0
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L0805ABB0: .4byte gUnk_08604A6C
.L0805ABB4: .4byte gUnk_081C4E28
.L0805ABB8: .4byte gUnk_Banim_0201977C
.L0805ABBC: .4byte gBg3Tm

	thumb_func_start sub_805ABC0
sub_805ABC0: @ 0x0805ABC0
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0805ABE8
	ldr r0, [r4, #0x5c]
	movs r1, #3
	movs r2, #2
	movs r3, #3
	bl sub_805AE1C
	ldr r0, .L0805AC50 @ =0x00000147
	movs r1, #0x80
	lsls r1, r1, #1
	bl sub_805BCA8
.L0805ABE8:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x23
	bne .L0805AC04
	ldr r0, [r4, #0x5c]
	movs r1, #3
	movs r2, #2
	movs r3, #3
	bl sub_805AE1C
	ldr r0, .L0805AC50 @ =0x00000147
	movs r1, #0x80
	lsls r1, r1, #1
	bl sub_805BCA8
.L0805AC04:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x32
	bne .L0805AC20
	ldr r0, [r4, #0x5c]
	movs r1, #3
	movs r2, #2
	movs r3, #3
	bl sub_805AE1C
	ldr r0, .L0805AC50 @ =0x00000147
	movs r1, #0x80
	lsls r1, r1, #1
	bl sub_805BCA8
.L0805AC20:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x64
	bne .L0805AC48
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4, #0x2e]
	adds r0, #0x19
	bl sub_805BD54
	movs r0, #0xa3
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	bl sub_805BCA8
	adds r0, r4, #0
	bl Proc_Break
.L0805AC48:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AC50: .4byte 0x00000147

	thumb_func_start sub_805AC54
sub_805AC54: @ 0x0805AC54
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xa0
	bl Interpolate
	adds r6, r0, #0
	rsbs r4, r6, #0
	adds r4, #0xf0
	movs r0, #0xff
	ands r4, r0
	asrs r4, r4, #3
	movs r2, #0x20
	subs r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #3
	movs r1, #0
	bl SetBgOffset
	add r1, sp, #4
	movs r0, #0x1f
	strh r0, [r1]
	lsls r4, r4, #6
	ldr r0, .L0805ADBC @ =gBg3Tm
	adds r4, r4, r0
	ldr r2, .L0805ADC0 @ =0x01000020
	adds r0, r1, #0
	adds r1, r4, #0
	bl CpuSet
	movs r0, #8
	bl EnableBgSync
	ldr r0, .L0805ADC4 @ =gUnk_Banim_02000000
	ldr r4, [r0]
	ldr r5, [r0, #4]
	ldr r3, .L0805ADC8 @ =gUnk_Banim_02000020
	ldr r0, .L0805ADCC @ =gUnk_Banim_0201E12C
	ldr r1, [r0]
	ldrh r2, [r3]
	subs r0, r2, r1
	movs r2, #0
	mov r8, r2
	strh r0, [r4, #2]
	ldr r2, .L0805ADD0 @ =gUnk_Banim_02000024
	ldrh r0, [r2]
	adds r0, r0, r6
	strh r0, [r4, #4]
	ldrh r3, [r3]
	subs r1, r3, r1
	strh r1, [r5, #2]
	ldrh r2, [r2]
	adds r6, r2, r6
	strh r6, [r5, #4]
	ldr r1, .L0805ADD4 @ =gDispIo
	ldr r3, .L0805ADD8 @ =gUnk_Banim_02017758
	ldrh r2, [r3]
	ldrh r6, [r1, #0x28]
	adds r0, r2, r6
	strh r0, [r1, #0x28]
	ldrh r0, [r1, #0x2a]
	ldrh r6, [r3, #2]
	adds r0, r0, r6
	strh r0, [r1, #0x2a]
	ldrh r0, [r4, #2]
	subs r2, r0, r2
	strh r2, [r4, #2]
	ldrh r1, [r4, #4]
	ldrh r2, [r3, #2]
	subs r0, r1, r2
	strh r0, [r4, #4]
	ldrh r6, [r5, #2]
	ldrh r1, [r3]
	subs r0, r6, r1
	strh r0, [r5, #2]
	ldrh r2, [r5, #4]
	ldrh r3, [r3, #2]
	subs r0, r2, r3
	strh r0, [r5, #4]
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0805AD1E
	movs r0, #8
	movs r1, #0
	bl sub_8045F48
	str r0, [r7, #0x5c]
.L0805AD1E:
	ldrh r6, [r7, #0x2c]
	cmp r6, #0x3c
	bne .L0805AD34
	ldr r0, [r7, #0x5c]
	bl Proc_End
	movs r0, #9
	movs r1, #0
	bl sub_8045F48
	str r0, [r7, #0x5c]
.L0805AD34:
	ldrh r0, [r7, #0x2c]
	cmp r0, #0x5a
	bne .L0805AD4A
	ldr r0, [r7, #0x5c]
	bl Proc_End
	movs r0, #0xa
	movs r1, #0
	bl sub_8045F48
	str r0, [r7, #0x5c]
.L0805AD4A:
	ldrh r1, [r7, #0x2c]
	cmp r1, #0x87
	bne .L0805AD5C
	ldr r0, [r7, #0x5c]
	movs r1, #0x3c
	movs r2, #0x1e
	movs r3, #0x78
	bl sub_805AE1C
.L0805AD5C:
	ldrh r2, [r7, #0x2c]
	cmp r2, #0xc8
	bne .L0805AD92
	mov r0, sp
	adds r0, #6
	mov r6, r8
	strh r6, [r0]
	ldr r4, .L0805ADDC @ =gPal+0xC0
	ldr r5, .L0805ADE0 @ =0x01000010
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuSet
	add r0, sp, #8
	strh r6, [r0]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r4, r4, r1
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuSet
	bl EnablePalSync
	ldr r0, [r7, #0x60]
	bl Proc_End
.L0805AD92:
	movs r2, #0x2c
	ldrsh r1, [r7, r2]
	movs r6, #0x2e
	ldrsh r0, [r7, r6]
	adds r0, #1
	cmp r1, r0
	bne .L0805ADB0
	mov r0, r8
	strh r0, [r7, #0x2c]
	ldr r0, [r7, #0x5c]
	bl Proc_End
	adds r0, r7, #0
	bl Proc_Break
.L0805ADB0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805ADBC: .4byte gBg3Tm
.L0805ADC0: .4byte 0x01000020
.L0805ADC4: .4byte gUnk_Banim_02000000
.L0805ADC8: .4byte gUnk_Banim_02000020
.L0805ADCC: .4byte gUnk_Banim_0201E12C
.L0805ADD0: .4byte gUnk_Banim_02000024
.L0805ADD4: .4byte gDispIo
.L0805ADD8: .4byte gUnk_Banim_02017758
.L0805ADDC: .4byte gPal+0xC0
.L0805ADE0: .4byte 0x01000010

	thumb_func_start sub_805ADE4
sub_805ADE4: @ 0x0805ADE4
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc8
	bne .L0805AE04
	adds r2, r1, #0
	adds r2, #0x29
	movs r0, #1
	strb r0, [r2]
	adds r0, r1, #0
	bl Proc_Break
.L0805AE04:
	pop {r0}
	bx r0

	thumb_func_start sub_805AE08
sub_805AE08: @ 0x0805AE08
	push {lr}
	adds r1, r0, #0
	adds r1, #0x29
	ldrb r1, [r1]
	cmp r1, #2
	bne .L0805AE18
	bl Proc_Break
.L0805AE18:
	pop {r0}
	bx r0

	thumb_func_start sub_805AE1C
sub_805AE1C: @ 0x0805AE1C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r0, .L0805AE64 @ =gUnk_08604A9C
	movs r1, #0
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r5, [r0, #0x44]
	str r6, [r0, #0x48]
	mov r1, r8
	str r1, [r0, #0x4c]
	ldr r2, .L0805AE68 @ =gDispIo
	adds r3, r2, #0
	adds r3, #0x3c
	movs r1, #0x21
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r4, [r3]
	ands r0, r4
	strb r0, [r3]
	adds r2, #0x3d
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AE64: .4byte gUnk_08604A9C
.L0805AE68: .4byte gDispIo

	thumb_func_start sub_805AE6C
sub_805AE6C: @ 0x0805AE6C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	ldr r0, [r7, #0x44]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r6, r0, #0
	ldr r0, .L0805AED4 @ =gPal
	ldr r4, .L0805AED8 @ =gUnk_Banim_020165C0
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	adds r3, r6, #0
	bl sub_805B644
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r0, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r7, #0x44]
	cmp r0, r1
	ble .L0805AECC
	movs r0, #0
	strh r0, [r7, #0x2c]
	adds r0, r7, #0
	bl Proc_Break
.L0805AECC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AED4: .4byte gPal
.L0805AED8: .4byte gUnk_Banim_020165C0

	thumb_func_start sub_805AEDC
sub_805AEDC: @ 0x0805AEDC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, .L0805AF2C @ =gPal
	ldr r4, .L0805AF30 @ =gUnk_Banim_020165C0
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	movs r3, #0x10
	bl sub_805B644
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r0, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r6, #0x48]
	cmp r0, r1
	ble .L0805AF26
	movs r0, #0
	strh r0, [r6, #0x2c]
	adds r0, r6, #0
	bl Proc_Break
.L0805AF26:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AF2C: .4byte gPal
.L0805AF30: .4byte gUnk_Banim_020165C0

	thumb_func_start sub_805AF34
sub_805AF34: @ 0x0805AF34
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	ldr r0, [r7, #0x4c]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r6, r0, #0
	ldr r0, .L0805AF9C @ =gPal
	ldr r4, .L0805AFA0 @ =gUnk_Banim_020165C0
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	adds r3, r6, #0
	bl sub_805B644
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r0, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r7, #0x4c]
	cmp r0, r1
	ble .L0805AF94
	movs r0, #0
	strh r0, [r7, #0x2c]
	adds r0, r7, #0
	bl Proc_Break
.L0805AF94:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AF9C: .4byte gPal
.L0805AFA0: .4byte gUnk_Banim_020165C0

	thumb_func_start sub_805AFA4
sub_805AFA4: @ 0x0805AFA4
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, .L0805AFD0 @ =gDispIo
	adds r3, r2, #0
	adds r3, #0x3c
	movs r0, #0x20
	ldrb r1, [r3]
	orrs r1, r0
	strb r1, [r3]
	adds r2, #0x3d
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	bl EnablePalSync
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AFD0: .4byte gDispIo

	thumb_func_start sub_805AFD4
sub_805AFD4: @ 0x0805AFD4
	push {lr}
	ldr r0, .L0805AFE8 @ =gUnk_08604ACC
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r0}
	bx r0
	.align 2, 0
.L0805AFE8: .4byte gUnk_08604ACC

	thumb_func_start sub_805AFEC
sub_805AFEC: @ 0x0805AFEC
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	bne .L0805B012
	ldr r0, .L0805B018 @ =0x00000145
	movs r1, #0x80
	lsls r1, r1, #1
	bl sub_805BCA8
	bl sub_805BD8C
	adds r0, r4, #0
	bl Proc_Break
.L0805B012:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805B018: .4byte 0x00000145

	thumb_func_start sub_805B01C
sub_805B01C: @ 0x0805B01C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r3, #0
	ldr r3, [sp, #0x1c]
	mov r8, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov ip, r1
	lsls r2, r2, #0x10
	adds r1, r0, #0
	lsrs r2, r2, #0x10
	cmp r2, #0
	beq .L0805B082
	movs r0, #0x20
	mov r3, ip
	subs r0, r0, r3
	lsls r0, r0, #0x10
	mov sb, r0
.L0805B044:
	mov r3, ip
	subs r5, r2, #1
	cmp r3, #0
	beq .L0805B076
	movs r2, #1
	rsbs r2, r2, #0
	ldr r7, .L0805B090 @ =0x00000FFF
	lsls r4, r6, #0xc
.L0805B054:
	ldrh r0, [r1]
	cmp r6, r2
	beq .L0805B062
	ands r0, r7
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L0805B062:
	cmp r8, r2
	beq .L0805B06C
	add r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L0805B06C:
	strh r0, [r1]
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bne .L0805B054
.L0805B076:
	mov r2, sb
	lsrs r0, r2, #0xf
	adds r1, r1, r0
	adds r2, r5, #0
	cmp r2, #0
	bne .L0805B044
.L0805B082:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805B090: .4byte 0x00000FFF

	thumb_func_start sub_805B094
sub_805B094: @ 0x0805B094
	push {r4, r5, r6, r7, lr}
	adds r5, r3, #0
	ldr r7, [sp, #0x14]
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	adds r3, r0, #0
	lsrs r2, r2, #0x10
	cmp r2, #0
	beq .L0805B0CC
	movs r0, #0x20
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0xf
	lsls r5, r5, #0xc
.L0805B0B2:
	adds r0, r4, #0
	subs r2, #1
	cmp r0, #0
	beq .L0805B0C6
	adds r1, r7, r5
.L0805B0BC:
	strh r1, [r3]
	adds r3, #2
	subs r0, #1
	cmp r0, #0
	bne .L0805B0BC
.L0805B0C6:
	adds r3, r3, r6
	cmp r2, #0
	bne .L0805B0B2
.L0805B0CC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805B0D4
sub_805B0D4: @ 0x0805B0D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r3, #0
	ldr r3, [sp, #0x18]
	mov ip, r3
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	adds r1, r0, #0
	lsrs r2, r2, #0x10
	cmp r2, #0
	beq .L0805B130
	movs r0, #0x20
	subs r0, r0, r7
	lsls r0, r0, #0x10
	mov r8, r0
.L0805B0F6:
	adds r3, r7, #0
	subs r5, r2, #1
	cmp r3, #0
	beq .L0805B124
	movs r2, #1
	rsbs r2, r2, #0
	lsls r4, r6, #0xc
.L0805B104:
	ldrh r0, [r1]
	cmp r6, r2
	beq .L0805B110
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L0805B110:
	cmp ip, r2
	beq .L0805B11A
	add r0, ip
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L0805B11A:
	strh r0, [r1]
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bne .L0805B104
.L0805B124:
	mov r2, r8
	lsrs r0, r2, #0xf
	adds r1, r1, r0
	adds r2, r5, #0
	cmp r2, #0
	bne .L0805B0F6
.L0805B130:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805B13C
sub_805B13C: @ 0x0805B13C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov ip, r1
	lsls r2, r2, #0x10
	adds r3, r0, #0
	lsrs r2, r2, #0x10
	cmp r2, #0
	beq .L0805B198
	movs r0, #0x20
	subs r0, r0, r1
	lsls r0, r0, #0x10
	mov r8, r0
	ldr r0, .L0805B1A4 @ =gUnk_08605D14
	mov sb, r0
.L0805B160:
	mov r4, ip
	subs r2, #1
	cmp r4, #0
	beq .L0805B18E
	ldr r7, .L0805B1A8 @ =0x00000FFF
	mov r6, sb
	movs r5, #0xf
.L0805B16E:
	ldrh r0, [r3]
	adds r1, r0, #0
	lsrs r0, r0, #0xc
	ands r0, r5
	subs r0, #6
	lsls r0, r0, #0x10
	ands r1, r7
	lsrs r0, r0, #0xf
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r1, r0, r1
	strh r1, [r3]
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bne .L0805B16E
.L0805B18E:
	mov r1, r8
	lsrs r0, r1, #0xf
	adds r3, r3, r0
	cmp r2, #0
	bne .L0805B160
.L0805B198:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805B1A4: .4byte gUnk_08605D14
.L0805B1A8: .4byte 0x00000FFF

	thumb_func_start sub_805B1AC
sub_805B1AC: @ 0x0805B1AC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r1, #0
	ldr r4, [sp, #0x20]
	ldr r5, [sp, #0x24]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	str r2, [sp]
	str r3, [sp, #4]
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	adds r2, r6, #0
	movs r3, #0x20
	bl sub_805B20C
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805B1DC
sub_805B1DC: @ 0x0805B1DC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r1, #0
	ldr r4, [sp, #0x20]
	ldr r5, [sp, #0x24]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	str r2, [sp]
	str r3, [sp, #4]
	str r4, [sp, #8]
	str r5, [sp, #0xc]
	adds r2, r6, #0
	movs r3, #0x20
	bl sub_805B2BC
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805B20C
sub_805B20C: @ 0x0805B20C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r2, #0
	ldr r0, [sp, #0x28]
	ldr r2, [sp, #0x2c]
	ldr r6, [sp, #0x30]
	mov r8, r6
	ldr r6, [sp, #0x34]
	mov ip, r6
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r2, #0
	beq .L0805B2A8
	lsls r0, r6, #0x10
	lsls r1, r3, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	asrs r1, r1, #0x10
	str r1, [sp, #4]
	subs r0, r6, r7
	lsls r0, r0, #0x10
	mov sl, r0
	subs r0, r3, r7
	lsls r0, r0, #0x10
	mov sb, r0
.L0805B254:
	adds r1, r7, #0
	subs r6, r2, #1
	cmp r1, #0
	beq .L0805B286
	movs r2, #1
	rsbs r2, r2, #0
	mov r0, r8
	lsls r3, r0, #0xc
.L0805B264:
	ldrh r0, [r5]
	cmp r8, r2
	beq .L0805B270
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L0805B270:
	cmp ip, r2
	beq .L0805B27A
	add r0, ip
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L0805B27A:
	strh r0, [r4]
	adds r5, #2
	adds r4, #2
	subs r1, #1
	cmp r1, #0
	bne .L0805B264
.L0805B286:
	ldr r2, .L0805B2B8 @ =0xFFFF0000
	asrs r1, r2, #0x10
	ldr r0, [sp]
	cmp r0, r1
	beq .L0805B296
	mov r2, sl
	lsrs r0, r2, #0xf
	adds r5, r5, r0
.L0805B296:
	ldr r0, [sp, #4]
	cmp r0, r1
	beq .L0805B2A2
	mov r1, sb
	lsrs r0, r1, #0xf
	adds r4, r4, r0
.L0805B2A2:
	adds r2, r6, #0
	cmp r2, #0
	bne .L0805B254
.L0805B2A8:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805B2B8: .4byte 0xFFFF0000

	thumb_func_start sub_805B2BC
sub_805B2BC: @ 0x0805B2BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r2, #0
	ldr r0, [sp, #0x2c]
	ldr r2, [sp, #0x30]
	ldr r6, [sp, #0x34]
	mov sb, r6
	ldr r6, [sp, #0x38]
	mov r8, r6
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	lsls r2, r2, #0x10
	lsls r0, r0, #1
	subs r0, #2
	adds r4, r4, r0
	lsrs r2, r2, #0x10
	cmp r2, #0
	beq .L0805B36A
	lsls r0, r6, #0x10
	lsls r1, r3, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	asrs r1, r1, #0x10
	str r1, [sp, #8]
	mov r1, ip
	subs r0, r6, r1
	lsls r0, r0, #0x10
	str r0, [sp, #4]
	adds r0, r1, r3
	lsls r0, r0, #0x10
	mov sl, r0
.L0805B30E:
	mov r1, ip
	subs r7, r2, #1
	cmp r1, #0
	beq .L0805B348
	movs r2, #1
	rsbs r2, r2, #0
	mov r6, sb
	lsls r3, r6, #0xc
	movs r0, #0x80
	lsls r0, r0, #3
	adds r6, r0, #0
.L0805B324:
	ldrh r0, [r5]
	cmp sb, r2
	beq .L0805B330
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L0805B330:
	cmp r8, r2
	beq .L0805B33A
	add r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
.L0805B33A:
	eors r0, r6
	strh r0, [r4]
	adds r5, #2
	subs r4, #2
	subs r1, #1
	cmp r1, #0
	bne .L0805B324
.L0805B348:
	ldr r2, .L0805B37C @ =0xFFFF0000
	asrs r1, r2, #0x10
	ldr r6, [sp]
	cmp r6, r1
	beq .L0805B358
	ldr r2, [sp, #4]
	lsrs r0, r2, #0xf
	adds r5, r5, r0
.L0805B358:
	ldr r6, [sp, #8]
	cmp r6, r1
	beq .L0805B364
	mov r1, sl
	lsrs r0, r1, #0xf
	adds r4, r4, r0
.L0805B364:
	adds r2, r7, #0
	cmp r2, #0
	bne .L0805B30E
.L0805B36A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805B37C: .4byte 0xFFFF0000

	thumb_func_start sub_805B380
sub_805B380: @ 0x0805B380
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r0, #0
	mov ip, r0
	cmp r7, #0
	beq .L0805B450
	movs r2, #0
.L0805B392:
	cmp r7, r2
	bgt .L0805B3A8
	mov r1, ip
	cmp r1, #0
	bne .L0805B3A4
	movs r0, #1
	mov ip, r0
	movs r0, #0xe
	b .L0805B408
.L0805B3A4:
	movs r0, #0xff
	b .L0805B408
.L0805B3A8:
	adds r0, r2, #1
	cmp r7, r0
	bne .L0805B3C4
	movs r1, #1
	mov ip, r1
	cmp r6, r2
	bgt .L0805B3BA
	movs r0, #0xd
	b .L0805B408
.L0805B3BA:
	adds r1, r2, #4
	cmp r6, r0
	bne .L0805B44A
	movs r0, #0xc
	b .L0805B446
.L0805B3C4:
	adds r4, r2, #2
	cmp r7, r4
	bne .L0805B3E8
	movs r1, #1
	mov ip, r1
	cmp r6, r2
	bgt .L0805B3D6
	movs r0, #0xb
	b .L0805B408
.L0805B3D6:
	cmp r6, r0
	bne .L0805B3DE
	movs r0, #0xa
	b .L0805B408
.L0805B3DE:
	adds r1, r2, #4
	cmp r6, r4
	bne .L0805B44A
	movs r0, #9
	b .L0805B446
.L0805B3E8:
	adds r5, r2, #3
	cmp r7, r5
	bne .L0805B41A
	movs r1, #1
	mov ip, r1
	cmp r6, r2
	bgt .L0805B3FA
	movs r0, #8
	b .L0805B408
.L0805B3FA:
	cmp r6, r0
	bne .L0805B402
	movs r0, #7
	b .L0805B408
.L0805B402:
	cmp r6, r4
	bne .L0805B410
	movs r0, #6
.L0805B408:
	strh r0, [r3]
	adds r3, #2
	adds r1, r2, #4
	b .L0805B44A
.L0805B410:
	adds r1, r2, #4
	cmp r6, r5
	bne .L0805B44A
	movs r0, #5
	b .L0805B446
.L0805B41A:
	adds r1, r2, #4
	cmp r7, r1
	blt .L0805B44A
	cmp r6, r2
	bgt .L0805B428
	movs r0, #4
	b .L0805B446
.L0805B428:
	cmp r6, r0
	bne .L0805B430
	movs r0, #3
	b .L0805B446
.L0805B430:
	cmp r6, r4
	bne .L0805B438
	movs r0, #2
	b .L0805B446
.L0805B438:
	cmp r6, r5
	bne .L0805B440
	movs r0, #1
	b .L0805B446
.L0805B440:
	cmp r6, r1
	blt .L0805B44A
	movs r0, #0
.L0805B446:
	strh r0, [r3]
	adds r3, #2
.L0805B44A:
	adds r2, r1, #0
	cmp r2, #0x28
	ble .L0805B392
.L0805B450:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805B458
sub_805B458: @ 0x0805B458
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	cmp r3, #5
	ble .L0805B466
	movs r0, #6
	b .L0805B46E
.L0805B466:
	ldr r0, .L0805B488 @ =gUnk_081C9EC8
	lsls r1, r3, #1
	adds r1, r1, r0
	ldrh r0, [r1]
.L0805B46E:
	strh r0, [r2]
	adds r2, #2
	movs r1, #0
	movs r7, #0x10
	ldr r6, .L0805B48C @ =gUnk_081C9ED6
	subs r4, r3, #6
	movs r5, #7
.L0805B47C:
	adds r0, r1, #0
	adds r0, #0xe
	cmp r3, r0
	blt .L0805B490
	strh r7, [r2]
	b .L0805B4A4
	.align 2, 0
.L0805B488: .4byte gUnk_081C9EC8
.L0805B48C: .4byte gUnk_081C9ED6
.L0805B490:
	adds r0, r1, #6
	cmp r3, r0
	blt .L0805B4A2
	subs r0, r4, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	strh r0, [r2]
	b .L0805B4A4
.L0805B4A2:
	strh r5, [r2]
.L0805B4A4:
	adds r2, #2
	adds r1, #8
	cmp r1, #0x57
	ble .L0805B47C
	cmp r3, #0x62
	ble .L0805B4B4
	movs r0, #0x17
	b .L0805B4CE
.L0805B4B4:
	cmp r3, #0x5d
	ble .L0805B4CC
	ldr r0, .L0805B4C8 @ =gUnk_081C9EE8
	adds r1, r3, #0
	subs r1, #0x5e
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	b .L0805B4CE
	.align 2, 0
.L0805B4C8: .4byte gUnk_081C9EE8
.L0805B4CC:
	movs r0, #0x11
.L0805B4CE:
	strh r0, [r2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805B4D8
sub_805B4D8: @ 0x0805B4D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, [sp, #0x3c]
	ldr r1, [sp, #0x40]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x14]
	cmp r3, #0
	beq .L0805B5A8
	str r3, [sp, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov sl, r0
	lsls r0, r1, #0x10
	asrs r7, r0, #0x10
.L0805B50E:
	ldr r1, [sp, #4]
	ldrh r0, [r1]
	movs r1, #0x1f
	ands r1, r0
	movs r6, #0xf8
	lsls r6, r6, #2
	ands r6, r0
	movs r2, #0xf8
	lsls r2, r2, #7
	mov sb, r2
	mov r3, sb
	ands r3, r0
	mov sb, r3
	ldr r2, [sp, #8]
	ldrh r0, [r2]
	movs r2, #0x1f
	ands r2, r0
	movs r4, #0xf8
	lsls r4, r4, #2
	ands r4, r0
	movs r3, #0xf8
	lsls r3, r3, #7
	mov r8, r3
	ands r3, r0
	mov r8, r3
	str r7, [sp]
	movs r0, #0
	mov r3, sl
	bl Interpolate
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r7, [sp]
	movs r0, #0
	adds r1, r6, #0
	adds r2, r4, #0
	mov r3, sl
	bl Interpolate
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r7, [sp]
	movs r0, #0
	mov r1, sb
	mov r2, r8
	mov r3, sl
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xf8
	lsls r1, r1, #7
	ands r0, r1
	movs r2, #0xf8
	lsls r2, r2, #2
	ands r4, r2
	orrs r0, r4
	movs r3, #0x1f
	ands r5, r3
	orrs r0, r5
	ldr r1, [sp, #0xc]
	strh r0, [r1]
	ldr r2, [sp, #4]
	adds r2, #2
	str r2, [sp, #4]
	ldr r3, [sp, #8]
	adds r3, #2
	str r3, [sp, #8]
	adds r1, #2
	str r1, [sp, #0xc]
	ldr r0, [sp, #0x18]
	subs r0, #1
	str r0, [sp, #0x18]
	cmp r0, #0
	bne .L0805B50E
.L0805B5A8:
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	cmp r1, r2
	beq .L0805B5B4
	movs r0, #0
	b .L0805B5B6
.L0805B5B4:
	movs r0, #1
.L0805B5B6:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_805B5C8
sub_805B5C8: @ 0x0805B5C8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r0, r3, #5
	movs r1, #0x10
	bl Div
	adds r6, r0, #0
	adds r0, r4, r5
	cmp r4, r0
	bge .L0805B638
	mov r8, r0
	movs r0, #0x1f
	mov ip, r0
.L0805B5EC:
	lsls r0, r4, #5
	adds r7, r4, #1
	mov r1, sb
	adds r5, r1, r0
	movs r4, #0xf
.L0805B5F6:
	ldrh r1, [r5]
	movs r2, #0x1f
	ands r2, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	mov r0, ip
	ands r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r0
	adds r0, r2, #0
	muls r0, r6, r0
	asrs r0, r0, #5
	subs r2, r2, r0
	adds r0, r3, #0
	muls r0, r6, r0
	asrs r0, r0, #5
	subs r3, r3, r0
	adds r0, r1, #0
	muls r0, r6, r0
	asrs r0, r0, #5
	subs r1, r1, r0
	lsls r3, r3, #5
	orrs r2, r3
	lsls r1, r1, #0xa
	orrs r2, r1
	strh r2, [r5]
	adds r5, #2
	subs r4, #1
	cmp r4, #0
	bge .L0805B5F6
	adds r4, r7, #0
	cmp r4, r8
	blt .L0805B5EC
.L0805B638:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_805B644
sub_805B644: @ 0x0805B644
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r0, r3, #5
	movs r1, #0x10
	bl Div
	adds r6, r0, #0
	adds r0, r4, r5
	cmp r4, r0
	bge .L0805B6BA
	mov sb, r0
	movs r0, #0x1f
	mov r8, r0
	movs r7, #0x1f
.L0805B66C:
	lsls r0, r4, #5
	adds r4, #1
	mov ip, r4
	mov r1, sl
	adds r5, r1, r0
	movs r4, #0xf
.L0805B678:
	ldrh r1, [r5]
	adds r2, r7, #0
	ands r2, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	mov r0, r8
	ands r3, r0
	lsrs r1, r1, #0x1a
	ands r1, r0
	subs r0, r7, r2
	muls r0, r6, r0
	asrs r0, r0, #5
	adds r2, r2, r0
	subs r0, r7, r3
	muls r0, r6, r0
	asrs r0, r0, #5
	adds r3, r3, r0
	subs r0, r7, r1
	muls r0, r6, r0
	asrs r0, r0, #5
	adds r1, r1, r0
	lsls r3, r3, #5
	orrs r2, r3
	lsls r1, r1, #0xa
	orrs r2, r1
	strh r2, [r5]
	adds r5, #2
	subs r4, #1
	cmp r4, #0
	bge .L0805B678
	mov r4, ip
	cmp r4, sb
	blt .L0805B66C
.L0805B6BA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_805B6C8
sub_805B6C8: @ 0x0805B6C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	adds r6, r1, #0
	mov r8, r2
	adds r0, r3, #0
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	lsls r0, r0, #5
	movs r1, #0x10
	bl Div
	mov sl, r0
	lsls r4, r4, #5
	adds r0, r4, #0
	movs r1, #0x10
	bl Div
	mov sb, r0
	lsls r5, r5, #5
	adds r0, r5, #0
	movs r1, #0x10
	bl Div
	mov ip, r0
	mov r1, r8
	adds r0, r6, r1
	cmp r6, r0
	bge .L0805B76E
	str r0, [sp, #4]
	movs r0, #0x1f
	mov r8, r0
	movs r7, #0x1f
.L0805B712:
	lsls r0, r6, #5
	adds r6, #1
	str r6, [sp, #8]
	ldr r1, [sp]
	adds r4, r1, r0
	movs r5, #0xf
.L0805B71E:
	ldrh r1, [r4]
	adds r2, r7, #0
	ands r2, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	mov r6, r8
	ands r3, r6
	lsrs r1, r1, #0x1a
	ands r1, r6
	subs r0, r7, r2
	mov r6, sl
	muls r6, r0, r6
	adds r0, r6, #0
	asrs r0, r0, #5
	adds r2, r2, r0
	subs r0, r7, r3
	mov r6, sb
	muls r6, r0, r6
	adds r0, r6, #0
	asrs r0, r0, #5
	adds r3, r3, r0
	subs r0, r7, r1
	mov r6, ip
	muls r6, r0, r6
	adds r0, r6, #0
	asrs r0, r0, #5
	adds r1, r1, r0
	lsls r3, r3, #5
	orrs r2, r3
	lsls r1, r1, #0xa
	orrs r2, r1
	strh r2, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge .L0805B71E
	ldr r6, [sp, #8]
	ldr r0, [sp, #4]
	cmp r6, r0
	blt .L0805B712
.L0805B76E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805B780
sub_805B780: @ 0x0805B780
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	adds r0, r1, r2
	cmp r1, r0
	bge .L0805B7E6
	mov sl, r0
	movs r0, #0x1f
	mov r8, r0
.L0805B798:
	movs r5, #0
	lsls r6, r1, #5
	adds r7, r1, #1
.L0805B79E:
	mov r1, sb
	adds r4, r1, r6
	lsls r0, r5, #1
	adds r4, r4, r0
	ldrh r2, [r4]
	movs r0, #0x1f
	ands r0, r2
	lsls r2, r2, #0x10
	lsrs r3, r2, #0x15
	mov r1, r8
	ands r3, r1
	lsrs r2, r2, #0x1a
	ands r2, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r1, r1, r2
	adds r0, r1, #0
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	lsls r0, r1, #5
	orrs r0, r1
	lsls r1, r1, #0xa
	orrs r0, r1
	strh r0, [r4]
	adds r5, #1
	cmp r5, #0xf
	ble .L0805B79E
	adds r1, r7, #0
	cmp r1, sl
	blt .L0805B798
.L0805B7E6:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_805B7F4
sub_805B7F4: @ 0x0805B7F4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r6, r2, #0
	movs r5, #0
	cmp r5, r6
	bhs .L0805B82C
	movs r7, #0x1f
	movs r0, #0x1f
	mov ip, r0
.L0805B808:
	ldrh r0, [r4]
	adds r4, #2
	adds r1, r0, #0
	mov r2, ip
	ands r1, r2
	lsrs r2, r0, #5
	ands r2, r7
	lsrs r0, r0, #0xa
	ands r0, r7
	strb r1, [r3]
	adds r3, #1
	strb r2, [r3]
	adds r3, #1
	strb r0, [r3]
	adds r3, #1
	adds r5, #1
	cmp r5, r6
	blo .L0805B808
.L0805B82C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805B834
sub_805B834: @ 0x0805B834
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	movs r6, #0
	cmp r6, r7
	bhs .L0805B882
	movs r0, #0x1f
	mov r8, r0
.L0805B84A:
	ldrh r2, [r5]
	adds r5, #2
	movs r1, #0x1f
	ands r1, r2
	lsrs r3, r2, #5
	mov r0, r8
	ands r3, r0
	lsrs r2, r2, #0xa
	ands r2, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r0, r2
	movs r1, #0xa
	bl Div
	strb r0, [r4]
	adds r4, #1
	strb r0, [r4]
	adds r4, #1
	strb r0, [r4]
	adds r4, #1
	adds r6, #1
	cmp r6, r7
	blo .L0805B84A
.L0805B882:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_805B88C
sub_805B88C: @ 0x0805B88C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	mov r8, r3
	ldr r0, [sp, #0x1c]
	mov sb, r0
	movs r7, #0
	cmp r7, r8
	bhs .L0805B900
.L0805B8A6:
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r1, #0
	ldrsb r1, [r6, r1]
	adds r6, #1
	adds r5, #1
	subs r0, r0, r1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x10
	mov r1, sb
	bl Div
	strh r0, [r4]
	adds r4, #2
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r1, #0
	ldrsb r1, [r6, r1]
	adds r6, #1
	adds r5, #1
	subs r0, r0, r1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x10
	mov r1, sb
	bl Div
	strh r0, [r4]
	adds r4, #2
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r1, #0
	ldrsb r1, [r6, r1]
	adds r6, #1
	adds r5, #1
	subs r0, r0, r1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x10
	mov r1, sb
	bl Div
	strh r0, [r4]
	adds r4, #2
	adds r7, #1
	cmp r7, r8
	blo .L0805B8A6
.L0805B900:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_805B90C
sub_805B90C: @ 0x0805B90C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov ip, r0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r4, r3, #0
	ldr r0, [sp, #0x1c]
	mov sb, r0
	ldr r7, [sp, #0x20]
	movs r0, #0
	mov r8, r0
	cmp r8, sb
	bhs .L0805B998
.L0805B92A:
	ldr r0, [sp, #0x24]
	cmp r7, r0
	beq .L0805B96E
	movs r0, #0
	ldrsh r1, [r4, r0]
	adds r4, #2
	movs r0, #0
	ldrsh r3, [r4, r0]
	adds r4, #2
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r4, #2
	adds r0, r1, #0
	muls r0, r7, r0
	asrs r1, r0, #8
	adds r0, r3, #0
	muls r0, r7, r0
	asrs r3, r0, #8
	adds r0, r2, #0
	muls r0, r7, r0
	asrs r2, r0, #8
	movs r0, #0
	ldrsb r0, [r6, r0]
	adds r1, r1, r0
	adds r6, #1
	movs r0, #0
	ldrsb r0, [r6, r0]
	adds r3, r3, r0
	adds r6, #1
	movs r0, #0
	ldrsb r0, [r6, r0]
	adds r2, r2, r0
	adds r6, #1
	b .L0805B980
.L0805B96E:
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r5, #1
	movs r3, #0
	ldrsb r3, [r5, r3]
	adds r5, #1
	movs r2, #0
	ldrsb r2, [r5, r2]
	adds r5, #1
.L0805B980:
	lsls r0, r3, #5
	orrs r1, r0
	lsls r0, r2, #0xa
	orrs r1, r0
	mov r0, ip
	strh r1, [r0]
	movs r0, #2
	add ip, r0
	movs r0, #1
	add r8, r0
	cmp r8, sb
	blo .L0805B92A
.L0805B998:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_805B9A4
sub_805B9A4: @ 0x0805B9A4
	push {r4, lr}
	adds r4, r0, #0
	bl ApplyChapterMapPalettes
	ldr r0, .L0805B9C4 @ =gPal
	movs r1, #6
	movs r2, #0xa
	adds r3, r4, #0
	bl sub_805B5C8
	bl EnablePalSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805B9C4: .4byte gPal

	thumb_func_start sub_805B9C8
sub_805B9C8: @ 0x0805B9C8
	push {r4, lr}
	adds r4, r0, #0
	bl RandNextB
	adds r4, #1
	adds r1, r4, #0
	bl DivRem
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_805B9E0
sub_805B9E0: @ 0x0805B9E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r7, [sp, #0x18]
	ldr r1, [sp, #0x20]
	ldr r0, .L0805BA28 @ =gUnk_08605D28
	bl SpawnProc
	movs r2, #0
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	adds r3, r0, #0
	adds r3, #0x29
	strb r4, [r3]
	adds r3, #1
	strb r2, [r3]
	strh r5, [r0, #0x32]
	strh r6, [r0, #0x3a]
	strh r1, [r0, #0x34]
	strh r1, [r0, #0x3c]
	mov r2, r8
	str r2, [r0, #0x44]
	str r1, [r0, #0x48]
	str r7, [r0, #0x4c]
	ldr r1, [sp, #0x1c]
	str r1, [r0, #0x50]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L0805BA28: .4byte gUnk_08605D28

	thumb_func_start sub_805BA2C
sub_805BA2C: @ 0x0805BA2C
	push {r4, r5, lr}
	sub sp, #0x48
	adds r2, r0, #0
	ldr r1, [r2, #0x44]
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bne .L0805BAA4
	movs r4, #0x2e
	ldrsh r0, [r2, r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r1, #0x3f
	ldrb r0, [r0, #3]
	ands r1, r0
	cmp r1, #0
	bne .L0805BA82
	adds r0, r2, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0805BA72
	cmp r0, #1
	bgt .L0805BA64
	cmp r0, #0
	beq .L0805BA6A
	b .L0805BAA4
.L0805BA64:
	cmp r0, #2
	beq .L0805BA78
	b .L0805BAA4
.L0805BA6A:
	adds r0, r2, #0
	bl Proc_Break
	b .L0805BADE
.L0805BA72:
	strh r0, [r2, #0x2c]
	strh r1, [r2, #0x2e]
	b .L0805BAA4
.L0805BA78:
	movs r0, #1
	strh r0, [r2, #0x2c]
	ldrh r0, [r2, #0x2e]
	subs r0, #1
	b .L0805BAA2
.L0805BA82:
	cmp r1, #4
	bne .L0805BA8A
	strh r3, [r2, #0x2c]
	b .L0805BA9E
.L0805BA8A:
	ldr r0, .L0805BAE8 @ =0x0FFFFFFC
	ands r0, r3
	str r0, [r2, #0x48]
	lsrs r0, r3, #0x1a
	movs r1, #0x1c
	ands r0, r1
	movs r1, #3
	ands r3, r1
	adds r0, r0, r3
	strh r0, [r2, #0x2c]
.L0805BA9E:
	ldrh r0, [r2, #0x2e]
	adds r0, #1
.L0805BAA2:
	strh r0, [r2, #0x2e]
.L0805BAA4:
	ldrh r0, [r2, #0x2c]
	subs r0, #1
	strh r0, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0x2a
	ldrb r3, [r0]
	cmp r3, #0
	bne .L0805BADE
	ldr r0, [r2, #0x48]
	cmp r0, #0
	beq .L0805BADE
	str r0, [sp, #0x3c]
	mov r1, sp
	ldr r0, [r2, #0x4c]
	strh r0, [r1, #8]
	ldr r0, [r2, #0x50]
	str r0, [sp, #0x1c]
	ldrh r5, [r2, #0x32]
	ldrh r4, [r2, #0x34]
	adds r0, r5, r4
	strh r0, [r1, #2]
	ldrh r5, [r2, #0x3a]
	ldrh r4, [r2, #0x3c]
	adds r0, r5, r4
	strh r0, [r1, #4]
	mov r0, sp
	strh r3, [r0, #0xc]
	bl BasPutOam
.L0805BADE:
	add sp, #0x48
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805BAE8: .4byte 0x0FFFFFFC

	thumb_func_start sub_805BAEC
sub_805BAEC: @ 0x0805BAEC
	lsrs r1, r0, #0x1e
	movs r2, #0xc0
	lsls r2, r2, #8
	ands r2, r0
	ldr r0, .L0805BB04 @ =gUnk_081C9EF4
	lsls r1, r1, #1
	lsrs r2, r2, #0xb
	adds r1, r1, r2
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	bx lr
	.align 2, 0
.L0805BB04: .4byte gUnk_081C9EF4

	thumb_func_start sub_805BB08
sub_805BB08: @ 0x0805BB08
	lsrs r1, r0, #0x1e
	movs r2, #0xc0
	lsls r2, r2, #8
	ands r2, r0
	ldr r0, .L0805BB20 @ =gUnk_081C9F14
	lsls r1, r1, #1
	lsrs r2, r2, #0xb
	adds r1, r1, r2
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	bx lr
	.align 2, 0
.L0805BB20: .4byte gUnk_081C9F14

	thumb_func_start sub_805BB24
sub_805BB24: @ 0x0805BB24
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r1, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	adds r7, r0, #0
	ldr r1, .L0805BC9C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
	lsls r3, r3, #0x10
	mov sb, r3
	mov r0, r8
	orrs r0, r3
	str r0, [sp]
	ldr r4, .L0805BCA0 @ =0xFFFF0004
	adds r1, r6, #0
	stm r1!, {r4}
	mov r0, sp
	movs r2, #1
	movs r3, #2
	bl ObjAffineSet
	adds r5, r6, #0
	adds r5, #0xc
	str r4, [r6, #0xc]
	adds r1, r6, #0
	adds r1, #0x10
	mov r0, sp
	movs r2, #1
	movs r3, #2
	bl ObjAffineSet
	ldrh r1, [r5, #4]
	rsbs r0, r1, #0
	strh r0, [r5, #4]
	ldrh r2, [r5, #6]
	rsbs r0, r2, #0
	strh r0, [r5, #6]
	adds r5, #0xc
	str r4, [r6, #0x18]
	adds r1, r6, #0
	adds r1, #0x1c
	mov r0, sp
	movs r2, #1
	movs r3, #2
	bl ObjAffineSet
	ldrh r3, [r5, #8]
	rsbs r0, r3, #0
	strh r0, [r5, #8]
	ldrh r1, [r5, #0xa]
	rsbs r0, r1, #0
	strh r0, [r5, #0xa]
	adds r5, #0xc
	str r4, [r6, #0x24]
	adds r1, r6, #0
	adds r1, #0x28
	mov r0, sp
	movs r2, #1
	movs r3, #2
	bl ObjAffineSet
	ldrh r2, [r5, #4]
	rsbs r0, r2, #0
	strh r0, [r5, #4]
	ldrh r3, [r5, #6]
	rsbs r0, r3, #0
	strh r0, [r5, #6]
	ldrh r1, [r5, #8]
	rsbs r0, r1, #0
	strh r0, [r5, #8]
	ldrh r2, [r5, #0xa]
	rsbs r0, r2, #0
	strh r0, [r5, #0xa]
	adds r6, #0x30
	ldr r0, [r7]
	cmp r0, #1
	beq .L0805BC7C
	mov r3, r8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	mov r0, sb
	asrs r5, r0, #0x10
.L0805BBD6:
	ldr r2, [r7]
	movs r0, #0x80
	lsls r0, r0, #0x15
	ands r0, r2
	rsbs r0, r0, #0
	asrs r1, r0, #0x1f
	movs r0, #0x80
	lsls r0, r0, #0x12
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #0x16
	ands r0, r2
	cmp r0, #0
	beq .L0805BBF8
	movs r3, #0x80
	lsls r3, r3, #0x13
	adds r1, r1, r3
.L0805BBF8:
	ldr r0, .L0805BCA4 @ =0xC1FFFFFF
	ands r0, r2
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
	adds r0, r0, r1
	str r0, [r6]
	ldrh r0, [r7, #4]
	strh r0, [r6, #4]
	adds r0, r2, #0
	bl sub_805BAEC
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x11
	lsls r1, r4, #8
	adds r0, r1, #0
	mov r1, r8
	bl Div
	subs r1, r4, r0
	movs r2, #6
	ldrsh r0, [r7, r2]
	subs r4, r0, r1
	lsls r1, r0, #8
	adds r0, r1, #0
	mov r1, r8
	bl Div
	adds r1, r0, #0
	movs r3, #6
	ldrsh r0, [r7, r3]
	subs r1, r0, r1
	subs r4, r4, r1
	strh r4, [r6, #6]
	ldr r0, [r7]
	bl sub_805BB08
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x11
	lsls r1, r4, #8
	adds r0, r1, #0
	adds r1, r5, #0
	bl Div
	subs r1, r4, r0
	movs r2, #8
	ldrsh r0, [r7, r2]
	subs r4, r0, r1
	lsls r1, r0, #8
	adds r0, r1, #0
	adds r1, r5, #0
	bl Div
	adds r1, r0, #0
	movs r3, #8
	ldrsh r0, [r7, r3]
	subs r1, r0, r1
	subs r4, r4, r1
	strh r4, [r6, #8]
	adds r6, #0xc
	adds r7, #0xc
	ldr r0, [r7]
	cmp r0, #1
	bne .L0805BBD6
.L0805BC7C:
	ldr r0, [r7]
	str r0, [r6]
	ldrh r0, [r7, #4]
	strh r0, [r6, #4]
	ldrh r0, [r7, #6]
	strh r0, [r6, #6]
	ldrh r0, [r7, #8]
	strh r0, [r6, #8]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805BC9C: .4byte 0xFFFF0000
.L0805BCA0: .4byte 0xFFFF0004
.L0805BCA4: .4byte 0xC1FFFFFF

	thumb_func_start sub_805BCA8
sub_805BCA8: @ 0x0805BCA8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r1, .L0805BCE4 @ =gBmSt
	movs r0, #0x20
	ldrb r1, [r1, #4]
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne .L0805BCFA
	bl sub_805BDB4
	cmp r0, #0
	bne .L0805BCEC
	bl sub_805BDA8
	adds r0, r5, #0
	bl sub_8002F9C
	ldr r0, .L0805BCE8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0805BCFA
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStart
	b .L0805BCFA
	.align 2, 0
.L0805BCE4: .4byte gBmSt
.L0805BCE8: .4byte gPlaySt
.L0805BCEC:
	ldr r0, .L0805BD00 @ =gUnk_08605D40
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x44]
	str r6, [r0, #0x48]
	strh r4, [r0, #0x2c]
.L0805BCFA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805BD00: .4byte gUnk_08605D40

	thumb_func_start sub_805BD04
sub_805BD04: @ 0x0805BD04
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	bne .L0805BD1E
	adds r0, r4, #0
	bl Proc_Break
	b .L0805BD4A
.L0805BD1E:
	bl sub_805BDB4
	cmp r0, #0
	bne .L0805BD4A
	bl sub_805BDA8
	ldr r0, [r4, #0x44]
	bl sub_8002F9C
	ldr r0, .L0805BD50 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0805BD44
	ldr r0, [r4, #0x48]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStart
.L0805BD44:
	adds r0, r4, #0
	bl Proc_Break
.L0805BD4A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805BD50: .4byte gPlaySt

	thumb_func_start sub_805BD54
sub_805BD54: @ 0x0805BD54
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStop
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805BD64
sub_805BD64: @ 0x0805BD64
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	ldr r1, .L0805BD88 @ =gBmSt
	movs r0, #0x20
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	bne .L0805BD82
	adds r0, r2, #0
	bl SetBgmVolume
	adds r0, r4, #0
	bl OverrideBgm
.L0805BD82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805BD88: .4byte gBmSt

	thumb_func_start sub_805BD8C
sub_805BD8C: @ 0x0805BD8C
	push {lr}
	ldr r0, .L0805BD98 @ =gMpi_FightBgm
	bl m4aMPlayStop
	pop {r0}
	bx r0
	.align 2, 0
.L0805BD98: .4byte gMpi_FightBgm

	thumb_func_start sub_805BD9C
sub_805BD9C: @ 0x0805BD9C
	ldr r1, .L0805BDA4 @ =gUnk_Banim_0201F050
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
.L0805BDA4: .4byte gUnk_Banim_0201F050

	thumb_func_start sub_805BDA8
sub_805BDA8: @ 0x0805BDA8
	ldr r1, .L0805BDB0 @ =gUnk_Banim_0201F050
	movs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L0805BDB0: .4byte gUnk_Banim_0201F050

	thumb_func_start sub_805BDB4
sub_805BDB4: @ 0x0805BDB4
	ldr r0, .L0805BDBC @ =gUnk_Banim_0201F050
	ldr r0, [r0]
	bx lr
	.align 2, 0
.L0805BDBC: .4byte gUnk_Banim_0201F050

	thumb_func_start sub_805BDC0
sub_805BDC0: @ 0x0805BDC0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, .L0805BDEC @ =gBmSt
	movs r0, #0x20
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	bne .L0805BE68
	cmp r2, #0
	beq .L0805BE38
	cmp r6, #0x77
	bgt .L0805BDF0
	adds r0, r6, #0
	muls r0, r6, r0
	movs r1, #0x78
	bl Div
	adds r5, r0, #0
	subs r5, #0x78
	b .L0805BE04
	.align 2, 0
.L0805BDEC: .4byte gBmSt
.L0805BDF0:
	movs r0, #0xf0
	subs r0, r0, r6
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	movs r1, #0x78
	bl Div
	movs r1, #0x78
	subs r5, r1, r0
.L0805BE04:
	ldr r2, .L0805BE2C @ =gMPlayTable
	ldr r0, .L0805BE30 @ =gSongTable
	lsls r1, r4, #3
	adds r1, r1, r0
	ldrh r3, [r1, #4]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r4, [r0]
	adds r0, r4, #0
	bl m4aMPlayImmInit
	ldr r1, .L0805BE34 @ =0x0000FFFF
	lsls r2, r5, #0x18
	asrs r2, r2, #0x18
	adds r0, r4, #0
	bl m4aMPlayPanpotControl
	b .L0805BE68
	.align 2, 0
.L0805BE2C: .4byte gMPlayTable
.L0805BE30: .4byte gSongTable
.L0805BE34: .4byte 0x0000FFFF
.L0805BE38:
	ldr r2, .L0805BE70 @ =gMPlayTable
	ldr r0, .L0805BE74 @ =gSongTable
	lsls r1, r4, #3
	adds r1, r1, r0
	ldrh r3, [r1, #4]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r4, [r0]
	adds r0, r4, #0
	bl m4aMPlayImmInit
	ldr r5, .L0805BE78 @ =0x0000FFFF
	adds r0, r6, #0
	bl Screen2Pan
	adds r2, r0, #0
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	bl m4aMPlayPanpotControl
.L0805BE68:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805BE70: .4byte gMPlayTable
.L0805BE74: .4byte gSongTable
.L0805BE78: .4byte 0x0000FFFF

	thumb_func_start sub_805BE7C
sub_805BE7C: @ 0x0805BE7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	mov sb, r1
	bl sub_804B80C
	adds r6, r0, #0
	mov r0, r8
	bl sub_804B6B0
	cmp r0, #1
	bne .L0805BE9C
	b .L0805C190
.L0805BE9C:
	mov r0, r8
	bl sub_804B6C4
	adds r5, r0, #0
	cmp r5, #0
	bne .L0805BEB4
	ldr r0, .L0805BEB0 @ =0x0203CDC0
	movs r1, #0
	ldrsh r4, [r0, r1]
	b .L0805BEBA
	.align 2, 0
.L0805BEB0: .4byte 0x0203CDC0
.L0805BEB4:
	ldr r0, .L0805BEE4 @ =0x0203CDC0
	movs r3, #2
	ldrsh r4, [r0, r3]
.L0805BEBA:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl sub_805C1A0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r4, #0x14
	bne .L0805BED6
	mov r0, r8
	bl sub_805C2B0
	cmp r0, #0
	bne .L0805BED6
	movs r7, #2
.L0805BED6:
	cmp r5, #0
	bne .L0805BEEC
	ldr r0, .L0805BEE8 @ =0x0203CDC4
	movs r1, #0
	ldrsh r0, [r0, r1]
	b .L0805BEF2
	.align 2, 0
.L0805BEE4: .4byte 0x0203CDC0
.L0805BEE8: .4byte 0x0203CDC4
.L0805BEEC:
	ldr r0, .L0805BF30 @ =0x0203CDC4
	movs r3, #2
	ldrsh r0, [r0, r3]
.L0805BEF2:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_805C2E0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r4, .L0805BF34 @ =0x0000FFFF
	mov r0, r8
	str r2, [sp]
	bl sub_805C76C
	mov r1, r8
	ldrh r1, [r1, #2]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #1
	mov r8, r0
	mov r0, sb
	subs r0, #0x19
	ldr r2, [sp]
	cmp r0, #0x31
	bls .L0805BF24
	b .L0805C16A
.L0805BF24:
	lsls r0, r0, #2
	ldr r1, .L0805BF38 @ =.L0805BF3C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0805BF30: .4byte 0x0203CDC4
.L0805BF34: .4byte 0x0000FFFF
.L0805BF38: .4byte .L0805BF3C
.L0805BF3C: @ jump table
	.4byte .L0805C004 @ case 0
	.4byte .L0805C16A @ case 1
	.4byte .L0805C0D4 @ case 2
	.4byte .L0805C008 @ case 3
	.4byte .L0805C010 @ case 4
	.4byte .L0805C018 @ case 5
	.4byte .L0805C020 @ case 6
	.4byte .L0805C040 @ case 7
	.4byte .L0805C060 @ case 8
	.4byte .L0805C09E @ case 9
	.4byte .L0805C0A2 @ case 10
	.4byte .L0805C0A6 @ case 11
	.4byte .L0805C0AA @ case 12
	.4byte .L0805C16A @ case 13
	.4byte .L0805C16A @ case 14
	.4byte .L0805C0B4 @ case 15
	.4byte .L0805C0B8 @ case 16
	.4byte .L0805C0C0 @ case 17
	.4byte .L0805C0C6 @ case 18
	.4byte .L0805C16A @ case 19
	.4byte .L0805C16A @ case 20
	.4byte .L0805C16A @ case 21
	.4byte .L0805C16A @ case 22
	.4byte .L0805C16A @ case 23
	.4byte .L0805C16A @ case 24
	.4byte .L0805C16A @ case 25
	.4byte .L0805C0D0 @ case 26
	.4byte .L0805C0D4 @ case 27
	.4byte .L0805C0EC @ case 28
	.4byte .L0805C0FC @ case 29
	.4byte .L0805C100 @ case 30
	.4byte .L0805C104 @ case 31
	.4byte .L0805C16A @ case 32
	.4byte .L0805C16A @ case 33
	.4byte .L0805C16A @ case 34
	.4byte .L0805C108 @ case 35
	.4byte .L0805C11C @ case 36
	.4byte .L0805C130 @ case 37
	.4byte .L0805C134 @ case 38
	.4byte .L0805C13A @ case 39
	.4byte .L0805C144 @ case 40
	.4byte .L0805C148 @ case 41
	.4byte .L0805C14C @ case 42
	.4byte .L0805C16A @ case 43
	.4byte .L0805C16A @ case 44
	.4byte .L0805C152 @ case 45
	.4byte .L0805C16A @ case 46
	.4byte .L0805C156 @ case 47
	.4byte .L0805C15A @ case 48
	.4byte .L0805C164 @ case 49
.L0805C004:
	movs r4, #0xd1
	b .L0805C16C
.L0805C008:
	ldr r1, .L0805C00C @ =gUnk_08605F34
	b .L0805C0D6
	.align 2, 0
.L0805C00C: .4byte gUnk_08605F34
.L0805C010:
	ldr r1, .L0805C014 @ =gUnk_08605F50
	b .L0805C0D6
	.align 2, 0
.L0805C014: .4byte gUnk_08605F50
.L0805C018:
	ldr r1, .L0805C01C @ =gUnk_08605F6C
	b .L0805C0D6
	.align 2, 0
.L0805C01C: .4byte gUnk_08605F6C
.L0805C020:
	adds r0, r6, #0
	bl sub_805C3B8
	adds r0, r6, #0
	bl sub_805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L0805C088
	cmp r0, #1
	bgt .L0805C07E
	cmp r0, #0
	bne .L0805C08E
	movs r4, #0xd2
	b .L0805C08E
.L0805C040:
	adds r0, r6, #0
	bl sub_805C3B8
	adds r0, r6, #0
	bl sub_805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L0805C088
	cmp r0, #1
	bgt .L0805C07E
	cmp r0, #0
	bne .L0805C08E
	movs r4, #0xd3
	b .L0805C08E
.L0805C060:
	adds r0, r6, #0
	bl sub_805C3B8
	adds r0, r6, #0
	bl sub_805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L0805C088
	cmp r0, #1
	bgt .L0805C07E
	cmp r0, #0
	beq .L0805C084
	b .L0805C08E
.L0805C07E:
	cmp r0, #2
	beq .L0805C08C
	b .L0805C08E
.L0805C084:
	movs r4, #0xd4
	b .L0805C08E
.L0805C088:
	movs r4, #0xd5
	b .L0805C08E
.L0805C08C:
	movs r4, #0xec
.L0805C08E:
	adds r0, r6, #0
	bl sub_805C76C
	ldrh r6, [r6, #2]
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	b .L0805C16C
.L0805C09E:
	movs r4, #0xc9
	b .L0805C16C
.L0805C0A2:
	movs r4, #0xc8
	b .L0805C16C
.L0805C0A6:
	movs r4, #0xca
	b .L0805C16C
.L0805C0AA:
	ldr r4, .L0805C0B0 @ =0x00000263
	b .L0805C0EE
	.align 2, 0
.L0805C0B0: .4byte 0x00000263
.L0805C0B4:
	movs r4, #0xf6
	b .L0805C16C
.L0805C0B8:
	ldr r4, .L0805C0BC @ =0x00000141
	b .L0805C16C
	.align 2, 0
.L0805C0BC: .4byte 0x00000141
.L0805C0C0:
	movs r4, #0xa1
	lsls r4, r4, #1
	b .L0805C16C
.L0805C0C6:
	ldr r4, .L0805C0CC @ =0x00000267
	b .L0805C0EE
	.align 2, 0
.L0805C0CC: .4byte 0x00000267
.L0805C0D0:
	movs r4, #0xe7
	b .L0805C16C
.L0805C0D4:
	ldr r1, .L0805C0E8 @ =gUnk_08605F18
.L0805C0D6:
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	b .L0805C16C
	.align 2, 0
.L0805C0E8: .4byte gUnk_08605F18
.L0805C0EC:
	ldr r4, .L0805C0F8 @ =0x00000265
.L0805C0EE:
	cmp r5, #0
	bne .L0805C16C
	subs r4, #1
	b .L0805C16C
	.align 2, 0
.L0805C0F8: .4byte 0x00000265
.L0805C0FC:
	movs r4, #0xce
	b .L0805C16C
.L0805C100:
	movs r4, #0xcf
	b .L0805C16C
.L0805C104:
	movs r4, #0xcb
	b .L0805C16C
.L0805C108:
	ldr r4, .L0805C118 @ =0x00000263
	cmp r5, #0
	bne .L0805C110
	subs r4, #1
.L0805C110:
	movs r1, #0x80
	mov r8, r1
	b .L0805C16C
	.align 2, 0
.L0805C118: .4byte 0x00000263
.L0805C11C:
	ldr r4, .L0805C12C @ =0x00000267
	cmp r5, #0
	bne .L0805C124
	subs r4, #1
.L0805C124:
	movs r0, #0x80
	mov r8, r0
	b .L0805C16C
	.align 2, 0
.L0805C12C: .4byte 0x00000267
.L0805C130:
	movs r4, #0xf1
	b .L0805C16C
.L0805C134:
	movs r4, #0x9b
	lsls r4, r4, #1
	b .L0805C16C
.L0805C13A:
	ldr r4, .L0805C140 @ =0x00000117
	b .L0805C16C
	.align 2, 0
.L0805C140: .4byte 0x00000117
.L0805C144:
	movs r4, #0xeb
	b .L0805C16C
.L0805C148:
	movs r4, #0xea
	b .L0805C16C
.L0805C14C:
	movs r4, #0x8c
	lsls r4, r4, #1
	b .L0805C16C
.L0805C152:
	movs r4, #0xe0
	b .L0805C16C
.L0805C156:
	movs r4, #0xed
	b .L0805C16C
.L0805C15A:
	ldr r4, .L0805C160 @ =0x00000135
	b .L0805C16C
	.align 2, 0
.L0805C160: .4byte 0x00000135
.L0805C164:
	movs r4, #0x9a
	lsls r4, r4, #1
	b .L0805C16C
.L0805C16A:
	movs r4, #0
.L0805C16C:
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L0805C190
	mov r1, r8
	adds r0, r4, #0
	str r3, [sp, #4]
	bl sub_805BCA8
	ldr r3, [sp, #4]
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	movs r2, #1
	adds r0, r4, #0
	bl sub_805BDC0
.L0805C190:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805C1A0
sub_805C1A0: @ 0x0805C1A0
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl sub_804C500
	cmp r0, #1
	bne .L0805C1B2
.L0805C1AE:
	movs r0, #0
	b .L0805C2AA
.L0805C1B2:
	cmp r4, #0x32
	bhi .L0805C2A8
	lsls r0, r4, #2
	ldr r1, .L0805C1C0 @ =.L0805C1C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0805C1C0: .4byte .L0805C1C4
.L0805C1C4: @ jump table
	.4byte .L0805C2A8 @ case 0
	.4byte .L0805C1AE @ case 1
	.4byte .L0805C1AE @ case 2
	.4byte .L0805C1AE @ case 3
	.4byte .L0805C1AE @ case 4
	.4byte .L0805C1AE @ case 5
	.4byte .L0805C2A4 @ case 6
	.4byte .L0805C2A4 @ case 7
	.4byte .L0805C2A4 @ case 8
	.4byte .L0805C2A4 @ case 9
	.4byte .L0805C1AE @ case 10
	.4byte .L0805C2A4 @ case 11
	.4byte .L0805C290 @ case 12
	.4byte .L0805C290 @ case 13
	.4byte .L0805C29C @ case 14
	.4byte .L0805C29C @ case 15
	.4byte .L0805C294 @ case 16
	.4byte .L0805C1AE @ case 17
	.4byte .L0805C298 @ case 18
	.4byte .L0805C2A0 @ case 19
	.4byte .L0805C2A0 @ case 20
	.4byte .L0805C294 @ case 21
	.4byte .L0805C294 @ case 22
	.4byte .L0805C2A4 @ case 23
	.4byte .L0805C2A4 @ case 24
	.4byte .L0805C1AE @ case 25
	.4byte .L0805C1AE @ case 26
	.4byte .L0805C1AE @ case 27
	.4byte .L0805C1AE @ case 28
	.4byte .L0805C2A4 @ case 29
	.4byte .L0805C2A4 @ case 30
	.4byte .L0805C2A4 @ case 31
	.4byte .L0805C2A4 @ case 32
	.4byte .L0805C2A4 @ case 33
	.4byte .L0805C1AE @ case 34
	.4byte .L0805C1AE @ case 35
	.4byte .L0805C2A4 @ case 36
	.4byte .L0805C1AE @ case 37
	.4byte .L0805C298 @ case 38
	.4byte .L0805C1AE @ case 39
	.4byte .L0805C1AE @ case 40
	.4byte .L0805C1AE @ case 41
	.4byte .L0805C298 @ case 42
	.4byte .L0805C1AE @ case 43
	.4byte .L0805C2A8 @ case 44
	.4byte .L0805C2A4 @ case 45
	.4byte .L0805C2A8 @ case 46
	.4byte .L0805C1AE @ case 47
	.4byte .L0805C2A4 @ case 48
	.4byte .L0805C2A4 @ case 49
	.4byte .L0805C2A4 @ case 50
.L0805C290:
	movs r0, #1
	b .L0805C2AA
.L0805C294:
	movs r0, #2
	b .L0805C2AA
.L0805C298:
	movs r0, #3
	b .L0805C2AA
.L0805C29C:
	movs r0, #4
	b .L0805C2AA
.L0805C2A0:
	movs r0, #5
	b .L0805C2AA
.L0805C2A4:
	movs r0, #6
	b .L0805C2AA
.L0805C2A8:
	movs r0, #0
.L0805C2AA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_805C2B0
sub_805C2B0: @ 0x0805C2B0
	push {r4, r5, lr}
	adds r4, r0, #0
	bl sub_805C76C
	movs r2, #2
	ldrsh r1, [r4, r2]
	adds r5, r0, r1
	adds r0, r4, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0805C2CE
	cmp r5, #0x58
	bgt .L0805C2D6
	b .L0805C2D2
.L0805C2CE:
	cmp r5, #0x97
	ble .L0805C2D6
.L0805C2D2:
	movs r0, #1
	b .L0805C2D8
.L0805C2D6:
	movs r0, #0
.L0805C2D8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_805C2E0
sub_805C2E0: @ 0x0805C2E0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r0, #0
	movs r1, #0
	cmp r0, #4
	bls .L0805C302
	cmp r0, #8
	bhi .L0805C2F4
	movs r1, #1
	b .L0805C302
.L0805C2F4:
	cmp r0, #0xb
	bhi .L0805C2FC
	movs r1, #2
	b .L0805C302
.L0805C2FC:
	cmp r2, #0xf
	bhi .L0805C302
	movs r1, #3
.L0805C302:
	adds r0, r1, #0
	bx lr
	.align 2, 0

	thumb_func_start sub_805C308
sub_805C308: @ 0x0805C308
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, .L0805C348 @ =0x0203CD46
	bl sub_804B6C4
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r0, r5, #0
	bl sub_804B6C4
	lsls r1, r6, #1
	adds r6, r1, r0
	adds r0, r6, #0
	bl sub_804A5A8
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r6, #2
	bl sub_804A5A8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r4, r0
	beq .L0805C350
	cmp r0, #0
	beq .L0805C34C
	movs r0, #0
	b .L0805C352
	.align 2, 0
.L0805C348: .4byte 0x0203CD46
.L0805C34C:
	movs r0, #1
	b .L0805C352
.L0805C350:
	movs r0, #2
.L0805C352:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_805C358
sub_805C358: @ 0x0805C358
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0805C37C @ =0x0000FFFF
	bl sub_805C3B8
	adds r0, r5, #0
	bl sub_805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L0805C38A
	cmp r0, #1
	bgt .L0805C380
	cmp r0, #0
	beq .L0805C386
	b .L0805C390
	.align 2, 0
.L0805C37C: .4byte 0x0000FFFF
.L0805C380:
	cmp r0, #2
	beq .L0805C38E
	b .L0805C390
.L0805C386:
	movs r4, #0xd4
	b .L0805C390
.L0805C38A:
	movs r4, #0xd5
	b .L0805C390
.L0805C38E:
	movs r4, #0xec
.L0805C390:
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L0805C3B2
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, #0
	bl sub_805BCA8
	movs r0, #2
	ldrsh r1, [r5, r0]
	adds r0, r4, #0
	movs r2, #1
	bl sub_805BDC0
.L0805C3B2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_805C3B8
sub_805C3B8: @ 0x0805C3B8
	push {r4, r5, lr}
	adds r4, r0, #0
	bl sub_804B80C
	adds r5, r0, #0
	adds r0, r4, #0
	bl sub_805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt .L0805C3F4
	cmp r0, #0
	blt .L0805C3F4
	adds r0, r5, #0
	bl sub_804B7B0
	cmp r0, #1
	bne .L0805C3F4
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xd8
	bl sub_805BCA8
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r0, #0xd8
	movs r2, #1
	bl sub_805BDC0
.L0805C3F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805C3FC
sub_805C3FC: @ 0x0805C3FC
	ldr r2, .L0805C414 @ =gBattleHits
	movs r1, #8
	ldrb r2, [r2, #2]
	ands r1, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	rsbs r1, r1, #0
	lsrs r1, r1, #0x1f
	cmp r0, r1
	beq .L0805C418
	movs r0, #0
	b .L0805C41A
	.align 2, 0
.L0805C414: .4byte gBattleHits
.L0805C418:
	movs r0, #1
.L0805C41A:
	bx lr

	thumb_func_start sub_805C41C
sub_805C41C: @ 0x0805C41C
	push {lr}
	cmp r0, #0
	beq .L0805C518
	bl GetItemIid
	subs r0, #0x43
	cmp r0, #0x34
	bhi .L0805C518
	lsls r0, r0, #2
	ldr r1, .L0805C438 @ =.L0805C43C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0805C438: .4byte .L0805C43C
.L0805C43C: @ jump table
	.4byte .L0805C510 @ case 0
	.4byte .L0805C510 @ case 1
	.4byte .L0805C510 @ case 2
	.4byte .L0805C510 @ case 3
	.4byte .L0805C510 @ case 4
	.4byte .L0805C518 @ case 5
	.4byte .L0805C518 @ case 6
	.4byte .L0805C510 @ case 7
	.4byte .L0805C514 @ case 8
	.4byte .L0805C514 @ case 9
	.4byte .L0805C518 @ case 10
	.4byte .L0805C510 @ case 11
	.4byte .L0805C518 @ case 12
	.4byte .L0805C514 @ case 13
	.4byte .L0805C518 @ case 14
	.4byte .L0805C510 @ case 15
	.4byte .L0805C518 @ case 16
	.4byte .L0805C518 @ case 17
	.4byte .L0805C518 @ case 18
	.4byte .L0805C518 @ case 19
	.4byte .L0805C518 @ case 20
	.4byte .L0805C518 @ case 21
	.4byte .L0805C518 @ case 22
	.4byte .L0805C518 @ case 23
	.4byte .L0805C518 @ case 24
	.4byte .L0805C518 @ case 25
	.4byte .L0805C518 @ case 26
	.4byte .L0805C518 @ case 27
	.4byte .L0805C518 @ case 28
	.4byte .L0805C518 @ case 29
	.4byte .L0805C518 @ case 30
	.4byte .L0805C518 @ case 31
	.4byte .L0805C518 @ case 32
	.4byte .L0805C518 @ case 33
	.4byte .L0805C518 @ case 34
	.4byte .L0805C518 @ case 35
	.4byte .L0805C518 @ case 36
	.4byte .L0805C518 @ case 37
	.4byte .L0805C518 @ case 38
	.4byte .L0805C518 @ case 39
	.4byte .L0805C518 @ case 40
	.4byte .L0805C518 @ case 41
	.4byte .L0805C518 @ case 42
	.4byte .L0805C518 @ case 43
	.4byte .L0805C518 @ case 44
	.4byte .L0805C518 @ case 45
	.4byte .L0805C518 @ case 46
	.4byte .L0805C518 @ case 47
	.4byte .L0805C518 @ case 48
	.4byte .L0805C518 @ case 49
	.4byte .L0805C518 @ case 50
	.4byte .L0805C510 @ case 51
	.4byte .L0805C510 @ case 52
.L0805C510:
	movs r0, #2
	b .L0805C51A
.L0805C514:
	movs r0, #1
	b .L0805C51A
.L0805C518:
	movs r0, #0
.L0805C51A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_805C520
sub_805C520: @ 0x0805C520
	push {r4, r5, r6, lr}
	ldr r0, .L0805C570 @ =0x0203CD7C
	ldr r1, .L0805C574 @ =0x0203CD80
	ldr r4, [r0]
	ldr r6, [r1]
	ldr r1, .L0805C578 @ =gBmSt
	movs r0, #0x20
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L0805C538
	b .L0805C728
.L0805C538:
	ldr r1, .L0805C57C @ =gUnk_Banim_0201F04C
	movs r0, #1
	str r0, [r1]
	ldr r1, .L0805C580 @ =0x0203CD08
	ldr r0, .L0805C584 @ =0x0203CCF4
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r5, #0x49
	ldrh r0, [r0]
	cmp r0, #1
	beq .L0805C554
	movs r5, #0x48
.L0805C554:
	bl sub_804C500
	cmp r0, #1
	beq .L0805C564
	bl sub_8042578
	cmp r0, #1
	bne .L0805C588
.L0805C564:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x3a
	bl sub_805BD64
	b .L0805C72E
	.align 2, 0
.L0805C570: .4byte 0x0203CD7C
.L0805C574: .4byte 0x0203CD80
.L0805C578: .4byte gBmSt
.L0805C57C: .4byte gUnk_Banim_0201F04C
.L0805C580: .4byte 0x0203CD08
.L0805C584: .4byte 0x0203CCF4
.L0805C588:
	ldr r0, .L0805C59C @ =0x0203CD14
	ldrh r0, [r0]
	cmp r0, #4
	bne .L0805C5A0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x1c
	bl sub_805BD64
	b .L0805C72E
	.align 2, 0
.L0805C59C: .4byte 0x0203CD14
.L0805C5A0:
	movs r2, #0
	ldr r0, [r4]
	ldrb r1, [r0, #4]
	adds r3, r0, #0
	cmp r1, #0x65
	bne .L0805C5AE
	movs r2, #1
.L0805C5AE:
	cmp r1, #0x66
	bne .L0805C5B4
	movs r2, #1
.L0805C5B4:
	cmp r2, #1
	bne .L0805C5C4
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x19
	bl sub_805BD64
	b .L0805C72E
.L0805C5C4:
	movs r2, #0
	cmp r1, #0x62
	bne .L0805C5CC
	movs r2, #1
.L0805C5CC:
	ldr r0, [r6]
	ldrb r0, [r0, #4]
	cmp r0, #0x62
	bne .L0805C5D6
	movs r2, #1
.L0805C5D6:
	cmp r1, #0x63
	bne .L0805C5DC
	movs r2, #1
.L0805C5DC:
	cmp r0, #0x63
	bne .L0805C5E2
	movs r2, #1
.L0805C5E2:
	cmp r1, #0x59
	bne .L0805C5E8
	movs r2, #1
.L0805C5E8:
	cmp r0, #0x59
	bne .L0805C5EE
	movs r2, #1
.L0805C5EE:
	cmp r2, #1
	bne .L0805C5FE
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x17
	bl sub_805BD64
	b .L0805C72E
.L0805C5FE:
	movs r2, #0
	ldrb r1, [r3, #4]
	cmp r1, #0x64
	bne .L0805C608
	movs r2, #1
.L0805C608:
	cmp r0, #0x64
	bne .L0805C60E
	movs r2, #1
.L0805C60E:
	cmp r2, #1
	bne .L0805C61E
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x18
	bl sub_805BD64
	b .L0805C72E
.L0805C61E:
	movs r2, #0
	cmp r1, #0x67
	bne .L0805C626
	movs r2, #1
.L0805C626:
	cmp r2, #1
	bne .L0805C636
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x15
	bl sub_805BD64
	b .L0805C72E
.L0805C636:
	movs r2, #0
	ldr r1, [r4, #4]
	ldr r0, [r3, #0x28]
	ldr r1, [r1, #0x24]
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L0805C656
	movs r0, #0xc0
	ldrb r4, [r4, #0xb]
	ands r0, r4
	cmp r0, #0x80
	bne .L0805C656
	movs r2, #1
.L0805C656:
	cmp r2, #1
	bne .L0805C666
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x16
	bl sub_805BD64
	b .L0805C72E
.L0805C666:
	movs r2, #0
	ldr r0, [r6, #4]
	adds r3, r0, #0
	ldrb r0, [r3, #4]
	cmp r0, #0x37
	bne .L0805C682
	ldr r1, .L0805C694 @ =gBattleSt
	movs r0, #0x40
	ldrb r1, [r1, #1]
	ands r0, r1
	movs r2, #1
	cmp r0, #0
	beq .L0805C682
	movs r2, #2
.L0805C682:
	cmp r2, #1
	bne .L0805C698
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x40
	bl sub_805BD64
	b .L0805C72E
	.align 2, 0
.L0805C694: .4byte gBattleSt
.L0805C698:
	cmp r2, #2
	bne .L0805C6A8
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x41
	bl sub_805BD64
	b .L0805C72E
.L0805C6A8:
	movs r2, #0
	ldrb r3, [r3, #4]
	cmp r3, #0x36
	bne .L0805C6C0
	ldr r1, .L0805C6D0 @ =gBattleSt
	movs r0, #0x40
	ldrb r1, [r1, #1]
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	lsrs r2, r0, #0x1f
.L0805C6C0:
	cmp r2, #1
	bne .L0805C6D4
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x14
	bl sub_805BD64
	b .L0805C72E
	.align 2, 0
.L0805C6D0: .4byte gBattleSt
.L0805C6D4:
	movs r0, #0
	bl sub_805C3FC
	cmp r0, #1
	bne .L0805C6E8
	ldr r0, .L0805C6E4 @ =gBattleUnitA
	b .L0805C6F4
	.align 2, 0
.L0805C6E4: .4byte gBattleUnitA
.L0805C6E8:
	movs r0, #1
	bl sub_805C3FC
	cmp r0, #1
	bne .L0805C704
	ldr r0, .L0805C700 @ =gBattleUnitB
.L0805C6F4:
	adds r0, #0x4a
	ldrh r0, [r0]
	bl sub_805C41C
	b .L0805C706
	.align 2, 0
.L0805C700: .4byte gBattleUnitB
.L0805C704:
	movs r0, #0
.L0805C706:
	cmp r0, #1
	beq .L0805C712
	cmp r0, #2
	bne .L0805C714
	movs r5, #0x1b
	b .L0805C714
.L0805C712:
	movs r5, #0x1a
.L0805C714:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	beq .L0805C728
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, #0
	bl sub_805BD64
	b .L0805C72E
.L0805C728:
	ldr r1, .L0805C734 @ =gUnk_Banim_0201F04C
	movs r0, #0
	str r0, [r1]
.L0805C72E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805C734: .4byte gUnk_Banim_0201F04C

	thumb_func_start sub_805C738
sub_805C738: @ 0x0805C738
	push {lr}
	bl sub_8058F38
	cmp r0, #0
	bne .L0805C756
	ldr r1, .L0805C75C @ =gBmSt
	movs r0, #0x20
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	bne .L0805C756
	ldr r0, .L0805C760 @ =gUnk_Banim_0201F04C
	ldr r0, [r0]
	cmp r0, #0
	bne .L0805C764
.L0805C756:
	bl MakeBgmOverridePersist
	b .L0805C768
	.align 2, 0
.L0805C75C: .4byte gBmSt
.L0805C760: .4byte gUnk_Banim_0201F04C
.L0805C764:
	bl RestoreBgm
.L0805C768:
	pop {r0}
	bx r0

	thumb_func_start sub_805C76C
sub_805C76C: @ 0x0805C76C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r2, [r0, #0x3c]
	ldr r3, [r2]
	ldr r1, .L0805C79C @ =0xFFFF0000
	adds r0, r3, #0
	ands r0, r1
	cmp r0, r1
	bne .L0805C790
	ldr r7, .L0805C7A0 @ =0x0000FFFF
	ands r7, r3
	cmp r7, #0
	beq .L0805C790
.L0805C788:
	subs r7, #1
	adds r2, #0xc
	cmp r7, #0
	bne .L0805C788
.L0805C790:
	adds r6, r2, #0
	movs r7, #0
	movs r0, #0
	mov r8, r0
	b .L0805C7D8
	.align 2, 0
.L0805C79C: .4byte 0xFFFF0000
.L0805C7A0: .4byte 0x0000FFFF
.L0805C7A4:
	movs r0, #6
	ldrsh r5, [r6, r0]
	ldr r0, [r6]
	bl sub_805BAEC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r5, r0
	ldr r0, [r6]
	bl sub_805BAEC
	adds r4, r0, #0
	ldr r0, [r6]
	bl sub_805BB08
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r4, #0
	muls r1, r0, r1
	adds r0, r1, #0
	muls r0, r5, r0
	add r8, r0
	adds r7, r7, r1
	adds r6, #0xc
.L0805C7D8:
	ldr r0, [r6]
	cmp r0, #1
	bne .L0805C7A4
	cmp r7, #0
	bne .L0805C7EC
	ldr r0, .L0805C7E8 @ =0x7FFFFFFF
	b .L0805C7F4
	.align 2, 0
.L0805C7E8: .4byte 0x7FFFFFFF
.L0805C7EC:
	mov r0, r8
	adds r1, r7, #0
	bl Div
.L0805C7F4:
	mov r8, r0
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_805C804
sub_805C804: @ 0x0805C804
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	adds r6, r3, #0
	bl sub_805BCA8
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl sub_805BDC0
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_805C820
sub_805C820: @ 0x0805C820
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r2, #0
	bl sub_805BCA8
	adds r0, r4, #0
	bl sub_805C76C
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #1
	bl sub_805BDC0
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_805C840
sub_805C840: @ 0x0805C840
	ldr r0, .L0805C850 @ =gUnk_Banim_0201F054
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0805C854
	movs r0, #0
	b .L0805C856
	.align 2, 0
.L0805C850: .4byte gUnk_Banim_0201F054
.L0805C854:
	movs r0, #1
.L0805C856:
	bx lr

	thumb_func_start sub_805C858
sub_805C858: @ 0x0805C858
	push {lr}
	ldr r0, .L0805C868 @ =gUnk_Banim_0201F054
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L0805C868: .4byte gUnk_Banim_0201F054

	thumb_func_start sub_805C86C
sub_805C86C: @ 0x0805C86C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_8047300
	ldr r4, .L0805C894 @ =gUnk_Banim_0201F054
	ldr r0, .L0805C898 @ =gUnk_08605F88
	movs r1, #3
	bl SpawnProc
	str r0, [r4]
	str r5, [r0, #0x5c]
	movs r2, #0
	movs r1, #0
	strh r1, [r0, #0x2c]
	adds r0, #0x29
	strb r2, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805C894: .4byte gUnk_Banim_0201F054
.L0805C898: .4byte gUnk_08605F88

	thumb_func_start sub_805C89C
sub_805C89C: @ 0x0805C89C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl sub_804B80C
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r7, #0
	movs r1, #0
	mov r8, r1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #1
	bne .L0805C8F8
	ldr r0, [r4, #0x5c]
	bl sub_8046ED8
	adds r0, r5, #0
	bl sub_8046ED8
	adds r0, r5, #0
	bl sub_805CB6C
	adds r0, r5, #0
	bl sub_805CC64
	ldr r2, .L0805C8F4 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r3, [r2, #1]
	ands r0, r3
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	b .L0805CB56
	.align 2, 0
.L0805C8F4: .4byte gDispIo
.L0805C8F8:
	cmp r1, #0x5f
	bne .L0805C928
	ldr r0, [r4, #0x5c]
	movs r1, #0xa
	bl sub_8046794
	ldr r0, .L0805C924 @ =0x0000013B
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl sub_805C804
	movs r0, #1
	movs r1, #0
	movs r2, #8
	bl SetBgOffset
	b .L0805CB56
	.align 2, 0
.L0805C924: .4byte 0x0000013B
.L0805C928:
	cmp r1, #0x6a
	bne .L0805C94C
	ldr r1, [r4, #0x5c]
	ldr r0, .L0805C948 @ =0x0000F3FF
	ldrh r2, [r1, #8]
	ands r0, r2
	strh r0, [r1, #8]
	ldr r1, [r4, #0x5c]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r3, #0
	ldrh r2, [r1, #8]
	orrs r0, r2
	strh r0, [r1, #8]
	b .L0805CB56
	.align 2, 0
.L0805C948: .4byte 0x0000F3FF
.L0805C94C:
	cmp r1, #0x74
	bne .L0805C95C
	ldr r0, [r4, #0x5c]
	movs r1, #0xc
	movs r2, #0
	bl sub_805CFC0
	b .L0805CB56
.L0805C95C:
	cmp r1, #0x78
	bne .L0805C968
	ldr r0, [r4, #0x5c]
	bl sub_805CD68
	b .L0805CB56
.L0805C968:
	cmp r1, #0x80
	bne .L0805C974
	movs r0, #1
	bl sub_804B8B0
	b .L0805CB56
.L0805C974:
	cmp r1, #0x7e
	bne .L0805C9BC
	ldr r0, [r4, #0x5c]
	movs r1, #2
	str r1, [sp]
	movs r1, #0x38
	movs r2, #7
	movs r3, #0
	bl sub_804C8D4
	adds r2, r0, #0
	ldr r0, [r4, #0x5c]
	movs r1, #0x40
	str r1, [sp]
	adds r1, r2, #0
	movs r2, #0x38
	movs r3, #0
	bl sub_805D09C
	ldr r0, [r4, #0x5c]
	ldr r2, .L0805C9B8 @ =sub_804CD4C
	movs r1, #0x38
	bl sub_804CC68
	ldr r0, [r4, #0x5c]
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r1, #0
	movs r2, #0x38
	movs r3, #0x10
	bl sub_804CD88
	b .L0805CB56
	.align 2, 0
.L0805C9B8: .4byte sub_804CD4C
.L0805C9BC:
	cmp r1, #0xf2
	bne .L0805CA58
	ldr r0, [r4, #0x5c]
	bl sub_805CBB0
	ldr r0, [r4, #0x5c]
	bl sub_805CCE8
	ldr r6, .L0805CA50 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r6, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r6, #1]
	ldr r0, [r4, #0x5c]
	movs r1, #2
	str r1, [sp]
	movs r1, #0x38
	movs r2, #7
	movs r3, #0x40
	bl sub_804C8D4
	adds r2, r0, #0
	ldr r0, [r4, #0x5c]
	mov r3, r8
	str r3, [sp]
	adds r1, r2, #0
	movs r2, #0x38
	movs r3, #0x40
	bl sub_805D09C
	ldr r0, [r4, #0x5c]
	ldr r2, .L0805CA54 @ =sub_804CD4C
	movs r1, #0x38
	bl sub_804CC68
	adds r2, r6, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x44
	strb r7, [r0]
	adds r0, #1
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r7, [r0]
	ldr r0, [r4, #0x5c]
	str r1, [sp]
	mov r2, r8
	str r2, [sp, #4]
	movs r1, #0
	movs r2, #0x38
	movs r3, #0
	bl sub_804CD88
	movs r0, #0x9e
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	b .L0805CB36
	.align 2, 0
.L0805CA50: .4byte gDispIo
.L0805CA54: .4byte sub_804CD4C
.L0805CA58:
	movs r0, #0x9c
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0805CA88
	movs r0, #0
	bl sub_804B8E8
	ldr r0, .L0805CA84 @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #1
	bl sub_805CFC0
	b .L0805CB56
	.align 2, 0
.L0805CA84: .4byte 0x0000F3FF
.L0805CA88:
	movs r0, #0x9f
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0805CAAA
	adds r0, r5, #0
	bl sub_805CD68
	ldr r0, [r4, #0x5c]
	movs r1, #0xa
	bl sub_8046794
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	b .L0805CB56
.L0805CAAA:
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	movs r0, #0xa5
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0805CACC
	ldr r0, .L0805CAC8 @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	b .L0805CB56
	.align 2, 0
.L0805CAC8: .4byte 0x0000F3FF
.L0805CACC:
	movs r0, #0xad
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0805CAE4
	bl sub_8047358
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x46
	bl sub_804685C
	b .L0805CB56
.L0805CAE4:
	movs r0, #0xb2
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0805CB48
	adds r0, r5, #0
	movs r1, #0x82
	bl sub_805CDCC
	adds r0, r5, #0
	movs r1, #0x82
	bl sub_805CF38
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x5a
	movs r2, #0x28
	movs r3, #0xe
	bl sub_804CD88
	movs r4, #0x80
	lsls r4, r4, #1
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0x82
	movs r2, #0xa
	adds r3, r4, #0
	bl sub_804C8D4
	ldr r2, .L0805CB40 @ =sub_804CD4C
	adds r0, r5, #0
	movs r1, #0x82
	bl sub_804CC68
	ldr r0, .L0805CB44 @ =0x0000013D
	movs r3, #2
	ldrsh r2, [r5, r3]
	adds r1, r4, #0
.L0805CB36:
	movs r3, #1
	bl sub_805C804
	b .L0805CB56
	.align 2, 0
.L0805CB40: .4byte sub_804CD4C
.L0805CB44: .4byte 0x0000013D
.L0805CB48:
	movs r0, #0x94
	lsls r0, r0, #2
	cmp r1, r0
	bne .L0805CB56
	adds r0, r4, #0
	bl Proc_Break
.L0805CB56:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805CB64
sub_805CB64: @ 0x0805CB64
	adds r0, #0x29
	movs r1, #1
	strb r1, [r0]
	bx lr

	thumb_func_start sub_805CB6C
sub_805CB6C: @ 0x0805CB6C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805CB9C @ =gUnk_08605FA8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0805CBA0 @ =gUnk_081C9F34
	str r1, [r0, #0x48]
	ldr r1, .L0805CBA4 @ =gUnk_08605FC0
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L0805CBA8 @ =gUnk_0860601C
	str r1, [r0, #0x54]
	ldr r1, .L0805CBAC @ =gUnk_08606078
	str r1, [r0, #0x58]
	bl sub_8047500
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CB9C: .4byte gUnk_08605FA8
.L0805CBA0: .4byte gUnk_081C9F34
.L0805CBA4: .4byte gUnk_08605FC0
.L0805CBA8: .4byte gUnk_0860601C
.L0805CBAC: .4byte gUnk_08606078

	thumb_func_start sub_805CBB0
sub_805CBB0: @ 0x0805CBB0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805CBE0 @ =gUnk_08605FA8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0805CBE4 @ =gUnk_081C9FA6
	str r1, [r0, #0x48]
	ldr r1, .L0805CBE8 @ =gUnk_08605FC0
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L0805CBEC @ =gUnk_0860601C
	str r1, [r0, #0x54]
	ldr r1, .L0805CBF0 @ =gUnk_08606078
	str r1, [r0, #0x58]
	bl sub_8047500
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CBE0: .4byte gUnk_08605FA8
.L0805CBE4: .4byte gUnk_081C9FA6
.L0805CBE8: .4byte gUnk_08605FC0
.L0805CBEC: .4byte gUnk_0860601C
.L0805CBF0: .4byte gUnk_08606078

	thumb_func_start sub_805CBF4
sub_805CBF4: @ 0x0805CBF4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl sub_8047BA4
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	blt .L0805CC42
	ldr r6, [r7, #0x4c]
	ldr r0, [r7, #0x50]
	mov r8, r0
	ldr r0, [r7, #0x54]
	ldr r4, [r7, #0x58]
	lsls r5, r5, #2
	adds r0, r5, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	adds r4, r5, r4
	ldr r0, [r4]
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, [r7, #0x5c]
	adds r6, r5, r6
	ldr r1, [r6]
	add r5, r8
	ldr r2, [r5]
	bl sub_804799C
	b .L0805CC58
.L0805CC42:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L0805CC58
	bl sub_80474D8
	bl sub_80475D8
	adds r0, r7, #0
	bl Proc_End
.L0805CC58:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805CC64
sub_805CC64: @ 0x0805CC64
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805CC7C @ =gUnk_086060D4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CC7C: .4byte gUnk_086060D4

	thumb_func_start sub_805CC80
sub_805CC80: @ 0x0805CC80
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L0805CCC2
	cmp r0, #0x11
	beq .L0805CCC2
	cmp r0, #0x22
	beq .L0805CCC2
	cmp r0, #0x28
	beq .L0805CCC2
	cmp r0, #0x2e
	beq .L0805CCC2
	cmp r0, #0x34
	beq .L0805CCC2
	cmp r0, #0x3a
	beq .L0805CCC2
	cmp r0, #0x3e
	beq .L0805CCC2
	cmp r0, #0x42
	beq .L0805CCC2
	cmp r0, #0x44
	beq .L0805CCC2
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	cmp r0, #0x46
	beq .L0805CCC2
	cmp r0, #0x48
	bne .L0805CCD8
.L0805CCC2:
	movs r0, #0x9f
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r2, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl sub_805C804
	b .L0805CCE2
.L0805CCD8:
	cmp r0, #0x50
	bne .L0805CCE2
	adds r0, r2, #0
	bl Proc_Break
.L0805CCE2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805CCE8
sub_805CCE8: @ 0x0805CCE8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805CD00 @ =gUnk_086060EC
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CD00: .4byte gUnk_086060EC

	thumb_func_start sub_805CD04
sub_805CD04: @ 0x0805CD04
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x56
	beq .L0805CD42
	cmp r0, #0x58
	beq .L0805CD42
	cmp r0, #0x5a
	beq .L0805CD42
	cmp r0, #0x5c
	beq .L0805CD42
	cmp r0, #0x5e
	beq .L0805CD42
	cmp r0, #0x60
	beq .L0805CD42
	cmp r0, #0x62
	beq .L0805CD42
	cmp r0, #0x64
	beq .L0805CD42
	cmp r0, #0x66
	beq .L0805CD42
	cmp r0, #0x68
	beq .L0805CD42
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	cmp r0, #0x6a
	bne .L0805CD58
.L0805CD42:
	movs r0, #0x9f
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r2, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl sub_805C804
	b .L0805CD62
.L0805CD58:
	cmp r0, #0x6e
	bne .L0805CD62
	adds r0, r2, #0
	bl Proc_Break
.L0805CD62:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805CD68
sub_805CD68: @ 0x0805CD68
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, .L0805CDA4 @ =gUnk_08606104
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	ldr r3, .L0805CDA8 @ =gUnk_085E5858
	str r3, [sp]
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl sub_80478DC
	str r0, [r5, #0x60]
	ldr r0, .L0805CDAC @ =gUnk_0812D80C
	movs r1, #0x20
	bl sub_8047AB0
	ldr r0, .L0805CDB0 @ =gUnk_0812D374
	movs r1, #0x80
	lsls r1, r1, #5
	bl sub_8047A88
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CDA4: .4byte gUnk_08606104
.L0805CDA8: .4byte gUnk_085E5858
.L0805CDAC: .4byte gUnk_0812D80C
.L0805CDB0: .4byte gUnk_0812D374

	thumb_func_start sub_805CDB4
sub_805CDB4: @ 0x0805CDB4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805CDCC
sub_805CDCC: @ 0x0805CDCC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, .L0805CEBC @ =gUnk_08606124
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	movs r6, #0
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	ldr r0, .L0805CEC0 @ =gUnk_08127778
	movs r1, #0x20
	bl sub_8047AF4
	ldr r0, .L0805CEC4 @ =gUnk_081B4E9C
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_8047ACC
	ldr r0, .L0805CEC8 @ =gUnk_081B4F9C
	ldr r1, .L0805CECC @ =gBg1Tm
	movs r2, #1
	str r2, [sp]
	adds r2, #0xff
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x20
	bl sub_805B1AC
	movs r0, #2
	bl EnableBgSync
	bl sub_8047500
	ldr r0, .L0805CED0 @ =gDispIo
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
	movs r0, #0xe
	strb r0, [r1]
	adds r1, #1
	movs r4, #8
	movs r0, #8
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x46
	strb r6, [r0]
	mov r6, ip
	adds r6, #0x37
	movs r3, #0x20
	ldrb r1, [r6]
	orrs r1, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	mov r2, ip
	ldrb r2, [r2, #1]
	ands r0, r2
	movs r2, #0x41
	rsbs r2, r2, #0
	ands r0, r2
	movs r2, #0x80
	orrs r0, r2
	mov r7, ip
	strb r0, [r7, #1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	movs r0, #4
	orrs r1, r0
	orrs r1, r4
	movs r0, #0x10
	orrs r1, r0
	strb r1, [r6]
	ldr r0, .L0805CED4 @ =0x0000FFE0
	ldrh r1, [r7, #0x3c]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	ldr r1, .L0805CED8 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0xe0
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r7, #0x3c]
	mov r0, ip
	adds r0, #0x3d
	ldrb r7, [r0]
	orrs r3, r7
	strb r3, [r0]
	ldr r0, [r5, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [r5, #0x1c]
	ldr r0, .L0805CEDC @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CEBC: .4byte gUnk_08606124
.L0805CEC0: .4byte gUnk_08127778
.L0805CEC4: .4byte gUnk_081B4E9C
.L0805CEC8: .4byte gUnk_081B4F9C
.L0805CECC: .4byte gBg1Tm
.L0805CED0: .4byte gDispIo
.L0805CED4: .4byte 0x0000FFE0
.L0805CED8: .4byte 0x0000E0FF
.L0805CEDC: .4byte 0x0000F3FF

	thumb_func_start sub_805CEE0
sub_805CEE0: @ 0x0805CEE0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x5c]
	ldr r1, .L0805CF2C @ =gDispIo
	ldrh r0, [r1, #0x22]
	subs r0, #1
	strh r0, [r1, #0x22]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0805CF24
	bl sub_80474D8
	bl sub_80475D8
	ldr r0, [r5, #0x1c]
	ldr r1, .L0805CF30 @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r5, #0x1c]
	ldr r0, .L0805CF34 @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	adds r0, r4, #0
	bl Proc_Break
.L0805CF24:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CF2C: .4byte gDispIo
.L0805CF30: .4byte 0xFFFFF7FF
.L0805CF34: .4byte 0x0000F3FF

	thumb_func_start sub_805CF38
sub_805CF38: @ 0x0805CF38
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L0805CF54 @ =gUnk_0860613C
	movs r1, #4
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CF54: .4byte gUnk_0860613C

	thumb_func_start sub_805CF58
sub_805CF58: @ 0x0805CF58
	push {r4, lr}
	sub sp, #0x48
	adds r4, r0, #0
	ldr r2, [r4, #0x5c]
	mov r1, sp
	ldrh r0, [r2, #2]
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	strh r0, [r1, #4]
	ldr r0, [r2, #0x3c]
	str r0, [sp, #0x3c]
	ldr r0, [r2, #0x1c]
	ldr r1, .L0805CFB4 @ =0xFFFFF7FF
	ands r0, r1
	str r0, [sp, #0x1c]
	mov r0, sp
	ldrh r1, [r2, #8]
	strh r1, [r0, #8]
	mov r2, sp
	ldr r0, .L0805CFB8 @ =0x0000F3FF
	ands r0, r1
	strh r0, [r2, #8]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2, #8]
	mov r0, sp
	bl BasPutOam
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0805CFAA
	adds r0, r4, #0
	bl Proc_Break
.L0805CFAA:
	add sp, #0x48
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CFB4: .4byte 0xFFFFF7FF
.L0805CFB8: .4byte 0x0000F3FF

	thumb_func_start nullsub_24
nullsub_24: @ 0x0805CFBC
	bx lr
	.align 2, 0

	thumb_func_start sub_805CFC0
sub_805CFC0: @ 0x0805CFC0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, .L0805CFE8 @ =gUnk_0860615C
	movs r1, #4
	bl SpawnProc
	adds r1, r0, #0
	str r4, [r1, #0x5c]
	movs r2, #0
	strh r2, [r1, #0x2c]
	strh r5, [r1, #0x2e]
	cmp r6, #0
	bne .L0805CFEC
	strh r2, [r1, #0x32]
	movs r0, #0x10
	strh r0, [r1, #0x34]
	b .L0805CFF2
	.align 2, 0
.L0805CFE8: .4byte gUnk_0860615C
.L0805CFEC:
	movs r0, #0x10
	strh r0, [r1, #0x32]
	strh r2, [r1, #0x34]
.L0805CFF2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_805CFF8
sub_805CFF8: @ 0x0805CFF8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x32
	ldrsh r1, [r5, r0]
	movs r4, #0x34
	ldrsh r2, [r5, r4]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r4, #0x2e
	ldrsh r0, [r5, r4]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	adds r6, r0, #0
	ldr r0, [r5, #0x5c]
	bl sub_804B6C4
	cmp r0, #0
	bne .L0805D050
	ldr r0, .L0805D044 @ =gUnk_Banim_0200004C
	ldr r0, [r0]
	ldr r4, .L0805D048 @ =gPal+0x2E0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L0805D04C @ =0xFFFFFD20
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #1
	adds r3, r6, #0
	bl sub_805B5C8
	b .L0805D06E
	.align 2, 0
.L0805D044: .4byte gUnk_Banim_0200004C
.L0805D048: .4byte gPal+0x2E0
.L0805D04C: .4byte 0xFFFFFD20
.L0805D050:
	ldr r0, .L0805D090 @ =gUnk_Banim_0200004C
	ldr r0, [r0, #4]
	ldr r4, .L0805D094 @ =gPal+0x320
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r2, .L0805D098 @ =0xFFFFFCE0
	adds r4, r4, r2
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	adds r3, r6, #0
	bl sub_805B5C8
.L0805D06E:
	bl EnablePalSync
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r4, [r5, #0x2e]
	lsls r1, r4, #0x10
	cmp r0, r1
	ble .L0805D088
	adds r0, r5, #0
	bl Proc_Break
.L0805D088:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805D090: .4byte gUnk_Banim_0200004C
.L0805D094: .4byte gPal+0x320
.L0805D098: .4byte 0xFFFFFCE0

	thumb_func_start sub_805D09C
sub_805D09C: @ 0x0805D09C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	mov r8, r1
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r7, [sp, #0x18]
	ldr r1, .L0805D0D8 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805D0DC @ =gUnk_08606174
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	str r6, [r0, #0x44]
	str r7, [r0, #0x48]
	mov r1, r8
	str r1, [r0, #0x64]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805D0D8: .4byte gUnk_Banim_02017744
.L0805D0DC: .4byte gUnk_08606174

	thumb_func_start sub_805D0E0
sub_805D0E0: @ 0x0805D0E0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, [r5, #0x64]
	ldr r1, [r5, #0x44]
	ldr r2, [r5, #0x48]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r6, #0x2e
	ldrsh r0, [r5, r6]
	str r0, [sp]
	movs r0, #4
	bl Interpolate
	str r0, [r4, #0x4c]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805D11C
	ldr r1, .L0805D124 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L0805D11C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805D124: .4byte gUnk_Banim_02017744

	thumb_func_start sub_805D128
sub_805D128: @ 0x0805D128
	ldr r0, .L0805D138 @ =gUnk_Banim_0201F058
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0805D13C
	movs r0, #0
	b .L0805D13E
	.align 2, 0
.L0805D138: .4byte gUnk_Banim_0201F058
.L0805D13C:
	movs r0, #1
.L0805D13E:
	bx lr

	thumb_func_start sub_805D140
sub_805D140: @ 0x0805D140
	push {lr}
	ldr r0, .L0805D150 @ =gUnk_Banim_0201F058
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L0805D150: .4byte gUnk_Banim_0201F058

	thumb_func_start sub_805D154
sub_805D154: @ 0x0805D154
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r2, r0, #0
	ldr r0, [r2, #0x5c]
	cmp r0, #0
	bne .L0805D17C
	ldr r0, .L0805D170 @ =0x0203CD7C
	ldr r4, [r0]
	ldr r0, .L0805D174 @ =gUnk_Banim_0201F0AC
	adds r6, r4, #0
	str r6, [r0]
	ldr r0, .L0805D178 @ =0x0203CD80
	b .L0805D188
	.align 2, 0
.L0805D170: .4byte 0x0203CD7C
.L0805D174: .4byte gUnk_Banim_0201F0AC
.L0805D178: .4byte 0x0203CD80
.L0805D17C:
	ldr r0, .L0805D298 @ =0x0203CD80
	ldr r4, [r0]
	ldr r0, .L0805D29C @ =gUnk_Banim_0201F0AC
	adds r6, r4, #0
	str r6, [r0]
	ldr r0, .L0805D2A0 @ =0x0203CD7C
.L0805D188:
	ldr r1, .L0805D2A4 @ =gUnk_Banim_0201F0B0
	ldr r3, [r0]
	str r3, [r1]
	adds r0, r2, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	beq .L0805D19A
	b .L0805D2B8
.L0805D19A:
	movs r0, #0xb
	ldrsb r0, [r6, r0]
	bl GetUnit
	adds r6, r0, #0
	ldr r1, .L0805D2A8 @ =gUnk_Banim_0201F0B4
	adds r3, r4, #0
	adds r3, #0x6c
	movs r0, #0
	ldrsb r0, [r3, r0]
	strh r0, [r1]
	ldr r2, .L0805D2AC @ =gUnk_Banim_0201F0B8
	movs r0, #0x10
	ldrsb r0, [r6, r0]
	strh r0, [r2]
	movs r0, #0x12
	ldrsb r0, [r6, r0]
	strh r0, [r2, #2]
	movs r0, #0x13
	ldrsb r0, [r6, r0]
	strh r0, [r2, #4]
	movs r0, #0x17
	ldrsb r0, [r6, r0]
	strh r0, [r2, #8]
	movs r0, #0x14
	ldrsb r0, [r6, r0]
	strh r0, [r2, #6]
	movs r0, #0x15
	ldrsb r0, [r6, r0]
	strh r0, [r2, #0xa]
	movs r0, #0x16
	ldrsb r0, [r6, r0]
	strh r0, [r2, #0xc]
	ldr r0, [r6, #4]
	ldrb r0, [r0, #0x11]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [r6]
	ldrb r1, [r1, #0x13]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	strh r0, [r2, #0xe]
	ldr r1, .L0805D2B0 @ =gUnk_Banim_0201F0B6
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, #1
	strh r0, [r1]
	ldr r2, .L0805D2B4 @ =gUnk_Banim_0201F0C8
	movs r0, #0x10
	ldrsb r0, [r6, r0]
	adds r1, r4, #0
	adds r1, #0x6f
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	strh r0, [r2]
	movs r0, #0x12
	ldrsb r0, [r6, r0]
	adds r1, r4, #0
	adds r1, #0x70
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	strh r0, [r2, #2]
	movs r0, #0x13
	ldrsb r0, [r6, r0]
	adds r1, r4, #0
	adds r1, #0x71
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	strh r0, [r2, #4]
	movs r0, #0x17
	ldrsb r0, [r6, r0]
	adds r1, r4, #0
	adds r1, #0x75
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	strh r0, [r2, #8]
	movs r0, #0x14
	ldrsb r0, [r6, r0]
	adds r1, r4, #0
	adds r1, #0x72
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	strh r0, [r2, #6]
	movs r0, #0x15
	ldrsb r0, [r6, r0]
	adds r1, r4, #0
	adds r1, #0x73
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	strh r0, [r2, #0xa]
	movs r0, #0x16
	ldrsb r0, [r6, r0]
	adds r1, r4, #0
	adds r1, #0x74
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	strh r0, [r2, #0xc]
	ldr r0, [r6, #4]
	movs r1, #0x11
	ldrsb r1, [r0, r1]
	ldr r0, [r6]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x76
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0805D342
	.align 2, 0
.L0805D298: .4byte 0x0203CD80
.L0805D29C: .4byte gUnk_Banim_0201F0AC
.L0805D2A0: .4byte 0x0203CD7C
.L0805D2A4: .4byte gUnk_Banim_0201F0B0
.L0805D2A8: .4byte gUnk_Banim_0201F0B4
.L0805D2AC: .4byte gUnk_Banim_0201F0B8
.L0805D2B0: .4byte gUnk_Banim_0201F0B6
.L0805D2B4: .4byte gUnk_Banim_0201F0C8
.L0805D2B8:
	ldr r1, .L0805D36C @ =gUnk_Banim_0201F0B4
	movs r0, #8
	ldrsb r0, [r6, r0]
	strh r0, [r1]
	ldr r2, .L0805D370 @ =gUnk_Banim_0201F0B8
	movs r0, #0x10
	ldrsb r0, [r6, r0]
	strh r0, [r2]
	movs r0, #0x12
	ldrsb r0, [r6, r0]
	strh r0, [r2, #2]
	movs r0, #0x13
	ldrsb r0, [r6, r0]
	strh r0, [r2, #4]
	movs r0, #0x17
	ldrsb r0, [r6, r0]
	strh r0, [r2, #8]
	movs r0, #0x14
	ldrsb r0, [r6, r0]
	strh r0, [r2, #6]
	movs r0, #0x15
	ldrsb r0, [r6, r0]
	strh r0, [r2, #0xa]
	movs r0, #0x16
	ldrsb r0, [r6, r0]
	strh r0, [r2, #0xc]
	ldr r0, [r6, #4]
	ldrb r0, [r0, #0x11]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [r6]
	ldrb r1, [r1, #0x13]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	strh r0, [r2, #0xe]
	ldr r1, .L0805D374 @ =gUnk_Banim_0201F0B6
	movs r0, #1
	strh r0, [r1]
	ldr r2, .L0805D378 @ =gUnk_Banim_0201F0C8
	movs r0, #0x10
	ldrsb r0, [r3, r0]
	strh r0, [r2]
	movs r0, #0x12
	ldrsb r0, [r3, r0]
	strh r0, [r2, #2]
	movs r0, #0x13
	ldrsb r0, [r3, r0]
	strh r0, [r2, #4]
	movs r0, #0x17
	ldrsb r0, [r3, r0]
	strh r0, [r2, #8]
	movs r0, #0x14
	ldrsb r0, [r3, r0]
	strh r0, [r2, #6]
	movs r0, #0x15
	ldrsb r0, [r3, r0]
	strh r0, [r2, #0xa]
	movs r0, #0x16
	ldrsb r0, [r3, r0]
	strh r0, [r2, #0xc]
	ldr r0, [r3, #4]
	ldrb r0, [r0, #0x11]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [r3]
	ldrb r1, [r1, #0x13]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
.L0805D342:
	adds r0, r0, r1
	strh r0, [r2, #0xe]
	ldr r0, .L0805D37C @ =gUnk_Banim_02017640
	ldr r1, .L0805D380 @ =0x06002400
	movs r2, #0x90
	lsls r2, r2, #1
	movs r3, #0
	bl InitTextFont
	movs r7, #0
	movs r0, #0
	mov r8, r0
.L0805D35A:
	adds r0, r6, #0
	bl UnitKnowsMagic
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0805D388
	ldr r0, .L0805D384 @ =gUnk_081C9FEC
	b .L0805D38A
	.align 2, 0
.L0805D36C: .4byte gUnk_Banim_0201F0B4
.L0805D370: .4byte gUnk_Banim_0201F0B8
.L0805D374: .4byte gUnk_Banim_0201F0B6
.L0805D378: .4byte gUnk_Banim_0201F0C8
.L0805D37C: .4byte gUnk_Banim_02017640
.L0805D380: .4byte 0x06002400
.L0805D384: .4byte gUnk_081C9FEC
.L0805D388:
	ldr r0, .L0805D4B8 @ =gUnk_081CA014
.L0805D38A:
	mov r1, r8
	adds r5, r1, r0
	lsls r1, r7, #3
	ldr r0, .L0805D4BC @ =gUnk_Banim_02017658
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #3
	bl InitText
	adds r0, r5, #0
	bl GetStringTextLen
	adds r1, r0, #0
	movs r0, #0x10
	subs r0, r0, r1
	asrs r1, r0, #1
	cmp r1, #0
	bge .L0805D3B0
	movs r1, #0
.L0805D3B0:
	adds r0, r4, #0
	bl Text_SetCursor
	adds r0, r4, #0
	movs r1, #3
	bl Text_SetColor
	adds r0, r4, #0
	adds r1, r5, #0
	bl Text_DrawString
	ldr r1, .L0805D4C0 @ =gUnk_081CA03C
	lsls r0, r7, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r1, r0, #1
	ldr r0, .L0805D4C4 @ =gBg2Tm
	adds r1, r1, r0
	adds r0, r4, #0
	bl PutText
	movs r0, #5
	add r8, r0
	adds r7, #1
	cmp r7, #7
	ble .L0805D35A
	movs r7, #0
.L0805D3E6:
	lsls r5, r7, #3
	ldr r1, .L0805D4C8 @ =gUnk_Banim_02017698
	mov r8, r1
	add r5, r8
	adds r0, r5, #0
	movs r1, #2
	bl InitText
	adds r0, r5, #0
	movs r1, #8
	bl Text_SetCursor
	adds r0, r5, #0
	movs r1, #2
	bl Text_SetColor
	ldr r0, .L0805D4CC @ =gUnk_Banim_0201F0B8
	lsls r4, r7, #1
	adds r0, r4, r0
	ldrh r1, [r0]
	adds r0, r5, #0
	bl Text_DrawNumber
	ldr r0, .L0805D4C0 @ =gUnk_081CA03C
	adds r4, r4, r0
	ldrh r4, [r4]
	lsls r1, r4, #1
	ldr r6, .L0805D4D0 @ =gBg2Tm+0x6
	adds r1, r1, r6
	adds r0, r5, #0
	bl PutText
	adds r7, #1
	cmp r7, #7
	ble .L0805D3E6
	mov r4, r8
	adds r4, #0x40
	adds r0, r4, #0
	movs r1, #8
	bl InitText
	ldr r0, .L0805D4D4 @ =gUnk_Banim_0201F0AC
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_DrawString
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r6, r0
	adds r0, r4, #0
	bl PutText
	adds r4, #8
	adds r0, r4, #0
	movs r1, #3
	bl InitText
	adds r0, r4, #0
	movs r1, #3
	bl Text_SetColor
	ldr r1, .L0805D4D8 @ =gUnk_081CA04C
	adds r0, r4, #0
	bl Text_DrawString
	movs r0, #0xe7
	lsls r0, r0, #1
	adds r1, r6, r0
	adds r0, r4, #0
	bl PutText
	adds r4, #8
	adds r0, r4, #0
	movs r1, #2
	bl InitText
	adds r0, r4, #0
	movs r1, #8
	bl Text_SetCursor
	adds r0, r4, #0
	movs r1, #2
	bl Text_SetColor
	ldr r0, .L0805D4DC @ =gUnk_Banim_0201F0B4
	ldrh r1, [r0]
	adds r0, r4, #0
	bl Text_DrawNumber
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r6, r0
	adds r0, r4, #0
	bl PutText
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805D4B8: .4byte gUnk_081CA014
.L0805D4BC: .4byte gUnk_Banim_02017658
.L0805D4C0: .4byte gUnk_081CA03C
.L0805D4C4: .4byte gBg2Tm
.L0805D4C8: .4byte gUnk_Banim_02017698
.L0805D4CC: .4byte gUnk_Banim_0201F0B8
.L0805D4D0: .4byte gBg2Tm+0x6
.L0805D4D4: .4byte gUnk_Banim_0201F0AC
.L0805D4D8: .4byte gUnk_081CA04C
.L0805D4DC: .4byte gUnk_Banim_0201F0B4

	thumb_func_start sub_805D4E0
sub_805D4E0: @ 0x0805D4E0
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r5, r4, #3
	ldr r0, .L0805D528 @ =gUnk_Banim_02017698
	adds r5, r5, r0
	adds r0, r5, #0
	bl ClearText
	adds r0, r5, #0
	movs r1, #8
	bl Text_SetCursor
	adds r0, r5, #0
	movs r1, #2
	bl Text_SetColor
	ldr r0, .L0805D52C @ =gUnk_Banim_0201F0B8
	lsls r4, r4, #1
	adds r0, r4, r0
	ldrh r1, [r0]
	adds r0, r5, #0
	bl Text_DrawNumber
	ldr r0, .L0805D530 @ =gUnk_081CA03C
	adds r4, r4, r0
	ldrh r4, [r4]
	lsls r1, r4, #1
	ldr r0, .L0805D534 @ =gBg2Tm+0x6
	adds r1, r1, r0
	adds r0, r5, #0
	bl PutText
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805D528: .4byte gUnk_Banim_02017698
.L0805D52C: .4byte gUnk_Banim_0201F0B8
.L0805D530: .4byte gUnk_081CA03C
.L0805D534: .4byte gBg2Tm+0x6

	thumb_func_start sub_805D538
sub_805D538: @ 0x0805D538
	push {r4, lr}
	ldr r4, .L0805D564 @ =gUnk_Banim_020176D8
	adds r0, r4, #0
	bl ClearText
	ldr r0, .L0805D568 @ =gUnk_Banim_0201F0AC
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_DrawString
	ldr r1, .L0805D56C @ =gBg2Tm+0x1C4
	adds r0, r4, #0
	bl PutText
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805D564: .4byte gUnk_Banim_020176D8
.L0805D568: .4byte gUnk_Banim_0201F0AC
.L0805D56C: .4byte gBg2Tm+0x1C4

	thumb_func_start sub_805D570
sub_805D570: @ 0x0805D570
	push {r4, lr}
	ldr r4, .L0805D5A4 @ =gUnk_Banim_020176E8
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #8
	bl Text_SetCursor
	adds r0, r4, #0
	movs r1, #2
	bl Text_SetColor
	ldr r0, .L0805D5A8 @ =gUnk_Banim_0201F0B4
	ldrh r1, [r0]
	adds r0, r4, #0
	bl Text_DrawNumber
	ldr r1, .L0805D5AC @ =gBg2Tm+0x1DA
	adds r0, r4, #0
	bl PutText
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805D5A4: .4byte gUnk_Banim_020176E8
.L0805D5A8: .4byte gUnk_Banim_0201F0B4
.L0805D5AC: .4byte gBg2Tm+0x1DA

	thumb_func_start sub_805D5B0
sub_805D5B0: @ 0x0805D5B0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, .L0805D5E8 @ =gUnk_Banim_0201F058
	ldr r0, .L0805D5EC @ =gUnk_086061AC
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r6, [r5]
	str r4, [r6, #0x5c]
	adds r0, r4, #0
	bl sub_804B80C
	str r0, [r6, #0x60]
	movs r1, #0
	movs r0, #0
	strh r0, [r6, #0x2c]
	adds r0, r6, #0
	adds r0, #0x29
	strb r1, [r0]
	ldr r0, .L0805D5F0 @ =0x0203CD14
	ldrh r0, [r0]
	cmp r0, #4
	beq .L0805D5F4
	adds r0, r6, #0
	adds r0, #0x2a
	strb r1, [r0]
	b .L0805D5FC
	.align 2, 0
.L0805D5E8: .4byte gUnk_Banim_0201F058
.L0805D5EC: .4byte gUnk_086061AC
.L0805D5F0: .4byte 0x0203CD14
.L0805D5F4:
	adds r1, r6, #0
	adds r1, #0x2a
	movs r0, #1
	strb r0, [r1]
.L0805D5FC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_805D604
sub_805D604: @ 0x0805D604
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldr r7, .L0805D6B4 @ =gUnk_Banim_0201F084
	movs r4, #0
	str r4, [sp]
	ldr r5, .L0805D6B8 @ =gBg1Tm
	ldr r0, .L0805D6BC @ =0x01000200
	mov r8, r0
	mov r0, sp
	adds r1, r5, #0
	mov r2, r8
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r6, .L0805D6C0 @ =gBg2Tm
	adds r1, r6, #0
	mov r2, r8
	bl CpuFastSet
	ldr r1, .L0805D6C4 @ =0x06006800
	movs r4, #0x80
	lsls r4, r4, #4
	adds r0, r5, #0
	adds r2, r4, #0
	bl RegisterDataMove
	ldr r1, .L0805D6C8 @ =0x06007000
	adds r0, r5, #0
	adds r2, r4, #0
	bl RegisterDataMove
	ldr r1, .L0805D6CC @ =0x06005000
	adds r0, r6, #0
	adds r2, r4, #0
	bl RegisterDataMove
	ldr r1, .L0805D6D0 @ =0x06005800
	adds r0, r6, #0
	adds r2, r4, #0
	bl RegisterDataMove
	ldr r1, .L0805D6D4 @ =0x0203CD10
	ldrh r4, [r1]
	strh r4, [r7]
	movs r0, #3
	strh r0, [r7, #2]
	adds r0, #0xfd
	strh r0, [r7, #4]
	ldrh r3, [r1, #2]
	strh r3, [r7, #6]
	movs r0, #4
	strh r0, [r7, #8]
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r7, #0xa]
	ldr r0, .L0805D6D8 @ =0x0203CD14
	ldrh r1, [r0]
	strh r1, [r7, #0xc]
	ldr r0, .L0805D6DC @ =0x0000FFFF
	adds r2, r0, #0
	ldrh r0, [r7, #0xe]
	orrs r0, r2
	strh r0, [r7, #0xe]
	ldr r0, .L0805D6E0 @ =0x06010000
	str r0, [r7, #0x1c]
	ldr r0, .L0805D6E4 @ =gUnk_Banim_020145C0
	str r0, [r7, #0x20]
	ldr r0, .L0805D6E8 @ =0x0203CCF6
	ldrh r0, [r0]
	strh r0, [r7, #0x10]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #2
	bne .L0805D6F6
	ldr r0, .L0805D6EC @ =gUnk_Banim_0201773C
	ldr r0, [r0]
	cmp r0, #0
	bne .L0805D6F0
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r7, #6]
	b .L0805D6F6
	.align 2, 0
.L0805D6B4: .4byte gUnk_Banim_0201F084
.L0805D6B8: .4byte gBg1Tm
.L0805D6BC: .4byte 0x01000200
.L0805D6C0: .4byte gBg2Tm
.L0805D6C4: .4byte 0x06006800
.L0805D6C8: .4byte 0x06007000
.L0805D6CC: .4byte 0x06005000
.L0805D6D0: .4byte 0x06005800
.L0805D6D4: .4byte 0x0203CD10
.L0805D6D8: .4byte 0x0203CD14
.L0805D6DC: .4byte 0x0000FFFF
.L0805D6E0: .4byte 0x06010000
.L0805D6E4: .4byte gUnk_Banim_020145C0
.L0805D6E8: .4byte 0x0203CCF6
.L0805D6EC: .4byte gUnk_Banim_0201773C
.L0805D6F0:
	adds r0, r4, #0
	orrs r0, r2
	strh r0, [r7]
.L0805D6F6:
	bl sub_804C500
	cmp r0, #0
	bne .L0805D71E
	adds r0, r7, #0
	bl sub_804BF40
	ldr r3, [r7, #0x14]
	ldr r0, [r3, #0x4c]
	ldr r2, .L0805D89C @ =0x0000F3FF
	ands r0, r2
	movs r1, #0xc0
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [r3, #0x4c]
	ldr r3, [r7, #0x18]
	ldr r0, [r3, #0x4c]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #0x4c]
.L0805D71E:
	mov r2, sb
	ldr r1, [r2, #0x5c]
	ldr r7, .L0805D89C @ =0x0000F3FF
	adds r0, r7, #0
	ldrh r3, [r1, #8]
	ands r0, r3
	strh r0, [r1, #8]
	ldr r1, [r2, #0x5c]
	movs r0, #0xc0
	lsls r0, r0, #4
	adds r2, r0, #0
	ldrh r0, [r1, #8]
	orrs r0, r2
	strh r0, [r1, #8]
	mov r3, sb
	ldr r1, [r3, #0x60]
	adds r0, r7, #0
	ldrh r3, [r1, #8]
	ands r0, r3
	strh r0, [r1, #8]
	mov r0, sb
	ldr r1, [r0, #0x60]
	movs r3, #0
	mov sl, r3
	ldrh r0, [r1, #8]
	orrs r0, r2
	strh r0, [r1, #8]
	ldr r4, .L0805D8A0 @ =gDispIo
	movs r5, #4
	rsbs r5, r5, #0
	adds r0, r5, #0
	ldrb r1, [r4, #0x14]
	ands r0, r1
	strb r0, [r4, #0x14]
	adds r0, r5, #0
	ldrb r2, [r4, #0x10]
	ands r0, r2
	movs r3, #1
	mov r8, r3
	mov r1, r8
	orrs r0, r1
	strb r0, [r4, #0x10]
	adds r0, r5, #0
	ldrb r2, [r4, #0xc]
	ands r0, r2
	movs r6, #2
	orrs r0, r6
	strb r0, [r4, #0xc]
	movs r0, #3
	ldrb r3, [r4, #0x18]
	orrs r0, r3
	strb r0, [r4, #0x18]
	movs r0, #0
	bl sub_80589FC
	ldrh r0, [r0]
	cmp r0, #0x53
	bne .L0805D7D6
	mov r0, sb
	ldr r1, [r0, #0x60]
	adds r0, r7, #0
	ldrh r2, [r1, #8]
	ands r0, r2
	strh r0, [r1, #8]
	mov r3, sb
	ldr r1, [r3, #0x60]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r2, #0
	ldrh r3, [r1, #8]
	orrs r0, r3
	strh r0, [r1, #8]
	adds r0, r5, #0
	ldrb r1, [r4, #0xc]
	ands r0, r1
	orrs r0, r6
	strb r0, [r4, #0xc]
	adds r0, r5, #0
	ldrb r2, [r4, #0x10]
	ands r0, r2
	mov r3, r8
	orrs r0, r3
	strb r0, [r4, #0x10]
	adds r0, r5, #0
	ldrb r1, [r4, #0x14]
	ands r0, r1
	strb r0, [r4, #0x14]
	adds r0, r5, #0
	ldrb r2, [r4, #0x18]
	ands r0, r2
	orrs r0, r6
	strb r0, [r4, #0x18]
.L0805D7D6:
	ldr r0, .L0805D8A4 @ =gUnk_Banim_0201F0D8
	movs r1, #0x90
	strh r1, [r0]
	ldr r0, .L0805D8A8 @ =gUnk_Banim_0201F0DA
	strh r1, [r0]
	movs r0, #2
	movs r1, #0
	movs r2, #8
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #8
	bl SetBgOffset
	movs r1, #0xc0
	lsls r1, r1, #7
	movs r0, #0
	bl SetBgTilemapOffset
	movs r1, #0xd0
	lsls r1, r1, #7
	movs r0, #1
	bl SetBgTilemapOffset
	movs r1, #0xa0
	lsls r1, r1, #7
	movs r0, #2
	bl SetBgTilemapOffset
	movs r0, #1
	movs r1, #1
	bl SetBgScreenSize
	movs r0, #2
	movs r1, #1
	bl SetBgScreenSize
	bl sub_805E230
	ldr r1, .L0805D8AC @ =gUnk_Banim_0201F07C
	str r0, [r1]
	bl sub_805E370
	ldr r1, .L0805D8B0 @ =gUnk_Banim_0201F080
	str r0, [r1]
	bl sub_805E248
	movs r0, #2
	bl sub_8043908
	mov r3, sb
	ldr r0, [r3, #0x5c]
	bl sub_8046ED8
	mov r1, sb
	ldr r0, [r1, #0x60]
	bl sub_8046ED8
	bl sub_8047248
	bl sub_8046B5C
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r2, [r4, #1]
	ands r0, r2
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r4, #1]
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r1, #8
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x45
	mov r1, sl
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	mov r0, sb
	bl Proc_Break
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805D89C: .4byte 0x0000F3FF
.L0805D8A0: .4byte gDispIo
.L0805D8A4: .4byte gUnk_Banim_0201F0D8
.L0805D8A8: .4byte gUnk_Banim_0201F0DA
.L0805D8AC: .4byte gUnk_Banim_0201F07C
.L0805D8B0: .4byte gUnk_Banim_0201F080

	thumb_func_start sub_805D8B4
sub_805D8B4: @ 0x0805D8B4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, .L0805D95C @ =0x0203CD7C
	ldr r0, [r0]
	mov sb, r0
	ldr r0, .L0805D960 @ =0x0203CD80
	ldr r0, [r0]
	mov r8, r0
	ldr r7, [r6, #0x5c]
	ldr r0, .L0805D964 @ =gUnk_08114D80
	ldr r5, .L0805D968 @ =gUnk_Banim_0201777C
	adds r1, r5, #0
	bl LZ77UnCompWram
	ldr r0, .L0805D96C @ =gUnk_08114FCC
	ldr r4, .L0805D970 @ =gUnk_Banim_0201977C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L0805D974 @ =gBg1Tm+0x180
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x20
	movs r3, #0x14
	bl sub_805B1AC
	ldr r1, .L0805D978 @ =0x06002000
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r5, #0
	bl RegisterDataMove
	ldr r0, .L0805D97C @ =gUnk_081150C8
	ldr r4, .L0805D980 @ =gPal+0x20
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L0805D984 @ =gUnk_081150E8
	ldr r5, .L0805D988 @ =gUnk_Banim_0201A77C
	adds r1, r5, #0
	bl LZ77UnCompWram
	ldr r1, .L0805D98C @ =0x06011400
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r5, #0
	bl RegisterDataMove
	ldr r0, .L0805D990 @ =gUnk_081152FC
	movs r1, #0x80
	lsls r1, r1, #2
	adds r4, r4, r1
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	adds r0, r6, #0
	adds r0, #0x2a
	ldrb r4, [r0]
	cmp r4, #0
	bne .L0805D998
	movs r1, #2
	ldrsh r0, [r7, r1]
	ldr r2, .L0805D994 @ =gUnk_085CCC40
	movs r1, #0x30
	movs r3, #0
	bl sub_805E140
	movs r1, #0x85
	lsls r1, r1, #5
	str r1, [r0, #0x4c]
	strh r4, [r6, #0x2c]
	b .L0805D99C
	.align 2, 0
.L0805D95C: .4byte 0x0203CD7C
.L0805D960: .4byte 0x0203CD80
.L0805D964: .4byte gUnk_08114D80
.L0805D968: .4byte gUnk_Banim_0201777C
.L0805D96C: .4byte gUnk_08114FCC
.L0805D970: .4byte gUnk_Banim_0201977C
.L0805D974: .4byte gBg1Tm+0x180
.L0805D978: .4byte 0x06002000
.L0805D97C: .4byte gUnk_081150C8
.L0805D980: .4byte gPal+0x20
.L0805D984: .4byte gUnk_081150E8
.L0805D988: .4byte gUnk_Banim_0201A77C
.L0805D98C: .4byte 0x06011400
.L0805D990: .4byte gUnk_081152FC
.L0805D994: .4byte gUnk_085CCC40
.L0805D998:
	movs r0, #0x50
	strh r0, [r6, #0x2c]
.L0805D99C:
	adds r0, r7, #0
	bl sub_804B6C4
	cmp r0, #0
	bne .L0805D9AA
	mov r1, sb
	b .L0805D9AC
.L0805D9AA:
	mov r1, r8
.L0805D9AC:
	ldr r0, [r1]
	ldrh r4, [r0, #6]
	ldr r0, .L0805D9F8 @ =gUnk_0860618C
	bl SetFaceConfig
	movs r0, #0x42
	str r0, [sp]
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0xbc
	movs r3, #0x50
	bl StartFace
	ldr r0, .L0805D9FC @ =gFaces
	ldr r1, [r0]
	movs r2, #0
	movs r0, #0xa0
	strh r0, [r1, #0x30]
	str r2, [sp, #8]
	ldr r1, .L0805DA00 @ =gBg2Tm
	ldr r2, .L0805DA04 @ =0x01000200
	add r0, sp, #8
	bl CpuFastSet
	adds r0, r6, #0
	bl sub_805D154
	adds r0, r6, #0
	bl Proc_Break
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805D9F8: .4byte gUnk_0860618C
.L0805D9FC: .4byte gFaces
.L0805DA00: .4byte gBg2Tm
.L0805DA04: .4byte 0x01000200

	thumb_func_start sub_805DA08
sub_805DA08: @ 0x0805DA08
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805DA34 @ =sub_805E4D4
	bl SetOnHBlankA
	movs r0, #1
	bl EnableBgSync
	movs r0, #4
	bl EnableBgSync
	movs r0, #2
	bl EnableBgSync
	bl EnablePalSync
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805DA34: .4byte sub_805E4D4

	thumb_func_start sub_805DA38
sub_805DA38: @ 0x0805DA38
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x50
	ble .L0805DA6E
	strh r1, [r4, #0x2c]
	str r1, [r4, #0x44]
	str r1, [r4, #0x48]
	movs r0, #2
	rsbs r0, r0, #0
	str r0, [r4, #0x4c]
	subs r0, #2
	str r0, [r4, #0x50]
	ldr r0, .L0805DA74 @ =gPal
	ldr r1, .L0805DA78 @ =gUnk_Banim_020165C0
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuFastSet
	adds r0, r4, #0
	bl Proc_Break
.L0805DA6E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805DA74: .4byte gPal
.L0805DA78: .4byte gUnk_Banim_020165C0

	thumb_func_start sub_805DA7C
sub_805DA7C: @ 0x0805DA7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r3, [r7, #0x44]
	ldr r5, [r7, #0x48]
	ldr r6, [r7, #0x4c]
	ldr r0, [r7, #0x50]
	mov sb, r0
	cmp r3, #0
	bge .L0805DA9C
	movs r3, #0
	b .L0805DAA2
.L0805DA9C:
	cmp r3, #8
	ble .L0805DAA2
	movs r3, #8
.L0805DAA2:
	cmp r5, #0
	bge .L0805DAAA
	movs r5, #0
	b .L0805DAB0
.L0805DAAA:
	cmp r5, #8
	ble .L0805DAB0
	movs r5, #8
.L0805DAB0:
	cmp r6, #0
	bge .L0805DAB8
	movs r6, #0
	b .L0805DABE
.L0805DAB8:
	cmp r6, #8
	ble .L0805DABE
	movs r6, #8
.L0805DABE:
	mov r2, sb
	cmp r2, #0
	bge .L0805DAC8
	movs r0, #0
	b .L0805DAD0
.L0805DAC8:
	mov r2, sb
	cmp r2, #8
	ble .L0805DAD2
	movs r0, #8
.L0805DAD0:
	mov sb, r0
.L0805DAD2:
	ldr r0, [r7, #0x44]
	adds r0, #1
	str r0, [r7, #0x44]
	ldr r0, [r7, #0x48]
	adds r0, #1
	str r0, [r7, #0x48]
	ldr r0, [r7, #0x4c]
	adds r0, #1
	str r0, [r7, #0x4c]
	ldr r0, [r7, #0x50]
	adds r0, #1
	str r0, [r7, #0x50]
	movs r1, #0x50
	rsbs r1, r1, #0
	movs r4, #8
	str r4, [sp]
	movs r0, #0
	movs r2, #0
	bl Interpolate
	mov r8, r0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #8
	adds r3, r5, #0
	bl Interpolate
	mov sl, r0
	ldr r5, .L0805DB90 @ =gUnk_Banim_0201F0D8
	str r4, [sp]
	movs r0, #0
	movs r1, #0x90
	movs r2, #0
	adds r3, r6, #0
	bl Interpolate
	strh r0, [r5]
	ldr r5, .L0805DB94 @ =gUnk_Banim_0201F0DA
	str r4, [sp]
	movs r0, #0
	movs r1, #0x90
	movs r2, #0
	mov r3, sb
	bl Interpolate
	strh r0, [r5]
	ldr r0, .L0805DB98 @ =gFaces
	ldr r1, [r0]
	movs r0, #0x50
	mov r2, r8
	subs r0, r0, r2
	strh r0, [r1, #0x30]
	ldr r0, .L0805DB9C @ =gUnk_Banim_020165C0
	ldr r4, .L0805DBA0 @ =gPal
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r4, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #2
	movs r2, #4
	mov r3, sl
	bl sub_805B5C8
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0xc
	mov r3, sl
	bl sub_805B5C8
	bl EnablePalSync
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	ble .L0805DB7E
	movs r0, #0
	strh r0, [r7, #0x2c]
	adds r0, r7, #0
	bl Proc_Break
.L0805DB7E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805DB90: .4byte gUnk_Banim_0201F0D8
.L0805DB94: .4byte gUnk_Banim_0201F0DA
.L0805DB98: .4byte gFaces
.L0805DB9C: .4byte gUnk_Banim_020165C0
.L0805DBA0: .4byte gPal

	thumb_func_start sub_805DBA4
sub_805DBA4: @ 0x0805DBA4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xa0
	movs r1, #1
	movs r2, #1
	movs r3, #3
	bl sub_8067A28
	adds r0, r4, #0
	bl Proc_Break
	ldr r1, .L0805DBD0 @ =gUnk_Banim_0201F05C
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0x1c
.L0805DBC2:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge .L0805DBC2
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805DBD0: .4byte gUnk_Banim_0201F05C

	thumb_func_start sub_805DBD4
sub_805DBD4: @ 0x0805DBD4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0805DBE8
	adds r0, r5, #0
	bl Proc_Break
	b .L0805DC1E
.L0805DBE8:
	ldr r0, .L0805DC24 @ =sub_805E510
	bl SetOnHBlankA
	ldr r4, .L0805DC28 @ =gUnk_Banim_0201F07C
	ldr r0, [r4]
	bl Proc_End
	bl sub_805E2CC
	str r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x76
	bl sub_805BCA8
	movs r0, #0x76
	movs r1, #0x38
	movs r2, #0
	bl sub_805BDC0
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #8
	strh r0, [r5, #0x2e]
	adds r0, r5, #0
	bl Proc_Break
.L0805DC1E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805DC24: .4byte sub_805E510
.L0805DC28: .4byte gUnk_Banim_0201F07C

	thumb_func_start sub_805DC2C
sub_805DC2C: @ 0x0805DC2C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0805DC42
	adds r0, r5, #0
	bl Proc_Break
	b .L0805DC96
.L0805DC42:
	ldr r4, .L0805DCA0 @ =gUnk_Banim_0201F0D8
	movs r2, #0x80
	lsls r2, r2, #5
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	bl Interpolate
	strh r0, [r4]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805DC96
	ldr r1, .L0805DCA4 @ =gUnk_Banim_0201F0AC
	ldr r0, .L0805DCA8 @ =gUnk_Banim_0201F0B0
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r5, #0
	bl sub_805D538
	ldr r1, .L0805DCAC @ =gUnk_Banim_0201F0B4
	ldr r0, .L0805DCB0 @ =gUnk_Banim_0201F0B6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r5, #0
	bl sub_805D570
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #8
	strh r0, [r5, #0x2e]
	adds r0, r5, #0
	bl Proc_Break
.L0805DC96:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805DCA0: .4byte gUnk_Banim_0201F0D8
.L0805DCA4: .4byte gUnk_Banim_0201F0AC
.L0805DCA8: .4byte gUnk_Banim_0201F0B0
.L0805DCAC: .4byte gUnk_Banim_0201F0B4
.L0805DCB0: .4byte gUnk_Banim_0201F0B6

	thumb_func_start sub_805DCB4
sub_805DCB4: @ 0x0805DCB4
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0805DCCA
	adds r0, r5, #0
	bl Proc_Break
	b .L0805DCFA
.L0805DCCA:
	ldr r4, .L0805DD04 @ =gUnk_Banim_0201F0D8
	movs r1, #0x80
	lsls r1, r1, #5
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	str r0, [sp]
	movs r0, #4
	movs r2, #0
	bl Interpolate
	strh r0, [r4]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805DCFA
	adds r0, r5, #0
	bl Proc_Break
.L0805DCFA:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805DD04: .4byte gUnk_Banim_0201F0D8

	thumb_func_start sub_805DD08
sub_805DD08: @ 0x0805DD08
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0805DD54
	strh r0, [r5, #0x2c]
	movs r0, #0x84
	movs r1, #0x3c
	movs r2, #0
	movs r3, #0
	bl sub_8067B08
	ldr r1, .L0805DD4C @ =gUnk_Banim_0201F0B4
	ldr r0, .L0805DD50 @ =gUnk_Banim_0201F0B6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r5, #0
	bl sub_805D570
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x76
	bl sub_805BCA8
	movs r0, #0x76
	movs r1, #0x38
	movs r2, #0
	bl sub_805BDC0
	adds r0, r5, #0
	bl Proc_Break
	b .L0805DD6E
	.align 2, 0
.L0805DD4C: .4byte gUnk_Banim_0201F0B4
.L0805DD50: .4byte gUnk_Banim_0201F0B6
.L0805DD54:
	ldr r4, .L0805DD74 @ =gUnk_Banim_0201F07C
	ldr r0, [r4]
	bl Proc_End
	bl sub_805E230
	str r0, [r4]
	movs r0, #0
	strh r0, [r5, #0x2c]
	strh r0, [r5, #0x2e]
	adds r0, r5, #0
	bl Proc_Break
.L0805DD6E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805DD74: .4byte gUnk_Banim_0201F07C

	thumb_func_start sub_805DD78
sub_805DD78: @ 0x0805DD78
	push {lr}
	adds r1, r0, #0
	adds r0, #0x2a
	ldrb r2, [r0]
	cmp r2, #0
	beq .L0805DD8C
	adds r0, r1, #0
	bl Proc_Break
	b .L0805DDA4
.L0805DD8C:
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1d
	bgt .L0805DDA4
	strh r2, [r1, #0x2c]
	strh r2, [r1, #0x2e]
	adds r0, r1, #0
	bl Proc_Break
.L0805DDA4:
	pop {r0}
	bx r0

	thumb_func_start sub_805DDA8
sub_805DDA8: @ 0x0805DDA8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	bne .L0805DE72
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldrh r0, [r4, #0x2e]
	cmp r0, #8
	beq .L0805DE78
	ldr r6, .L0805DE4C @ =gUnk_Banim_0201F0B8
.L0805DDCA:
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	lsls r0, r0, #1
	adds r2, r0, r6
	ldr r1, .L0805DE50 @ =gUnk_Banim_0201F0C8
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r7, [r2]
	subs r5, r0, r7
	cmp r5, #0
	beq .L0805DE64
	movs r1, #0
	mov r8, r1
	strh r0, [r2]
	movs r2, #0x2e
	ldrsh r1, [r4, r2]
	adds r0, r4, #0
	bl sub_805D4E0
	movs r0, #0x76
	movs r1, #0x80
	lsls r1, r1, #1
	bl sub_805BCA8
	movs r0, #0x76
	movs r1, #0x38
	movs r2, #0
	bl sub_805BDC0
	ldr r1, .L0805DE54 @ =gUnk_081CA03C
	movs r7, #0x2e
	ldrsh r2, [r4, r7]
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	lsls r0, r0, #3
	adds r0, #0x35
	movs r7, #0xfc
	lsls r7, r7, #3
	adds r3, r7, #0
	ands r1, r3
	lsrs r1, r1, #2
	adds r1, #6
	adds r2, #1
	adds r3, r5, #0
	bl sub_8067B08
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L0805DE44
	ldr r1, .L0805DE58 @ =0x0203CDA4
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	strh r0, [r1, #2]
	ldr r1, .L0805DE5C @ =0x0203CDA8
	ldr r0, .L0805DE60 @ =0x0000FFFF
	strh r0, [r1, #2]
.L0805DE44:
	mov r7, r8
	strh r7, [r4, #0x2c]
	b .L0805DE72
	.align 2, 0
.L0805DE4C: .4byte gUnk_Banim_0201F0B8
	bx r0