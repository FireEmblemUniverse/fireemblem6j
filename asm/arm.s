	.include "macro.inc"

	@ TODO: fix this file

	arm_func_start Checksum32
Checksum32: @ 0x08000360
	push {r4, r5, r6, r7}
	sub r1, r1, #2
	mov r2, #0
	mov r3, #0
.L08000370:
	ldrh r4, [r0]
	add r2, r2, r4
	eor r3, r3, r4
	add r0, r0, #2
	subs r1, r1, #2
	bpl .L08000370
	mov r0, #0x10000
	sub r0, r0, #1
	and r2, r2, r0
	lsl r3, r3, #0x10
	mov r0, r2
	add r0, r0, r3
	pop {r4, r5, r6, r7}
	bx lr

	arm_func_start TmFillRect
TmFillRect: @ 0x080003A8
	push {r4, r5, r6, r7}
	mov r4, r0
	sub r6, r2, #0
.L080003B4:
	sub r5, r1, #0
.L080003B8:
	strh r3, [r4]
	add r4, r4, #2
	subs r5, r5, #1
	bpl .L080003B8
	add r0, r0, #0x40
	mov r4, r0
	subs r6, r6, #1
	bpl .L080003B4
	pop {r4, r5, r6, r7}
	bx lr

	arm_func_start TmCopyRect
TmCopyRect: @ 0x080003E0
	push {r4, r5, r6, r7}
	tst r2, r2
	beq .L08000434
	bmi .L08000434
	tst r3, r3
	beq .L08000434
	bmi .L08000434
	mov r4, #0x40
	sub r4, r4, r2, lsl #1
	sub r6, r3, #1
.L08000408:
	sub r5, r2, #1
.L0800040C:
	ldrh r7, [r0]
	strh r7, [r1]
	add r0, r0, #2
	add r1, r1, #2
	subs r5, r5, #1
	bpl .L0800040C
	add r0, r0, r4
	add r1, r1, r4
	subs r6, r6, #1
	bpl .L08000408
.L08000434:
	pop {r4, r5, r6, r7}
	bx lr

	arm_func_start TmApplyTsa
TmApplyTsa: @ 0x0800043C
	push {r4, r5, r6, r7}
	ldrb r3, [r1]
	ldrb r4, [r1, #1]
	add r1, r1, #2
	lsl r7, r4, #6
	add r0, r0, r7
	mov r6, r4
.L08000458:
	mov r5, r3
.L0800045C:
	ldrh r7, [r1]
	add r7, r7, r2
	strh r7, [r0]
	add r0, r0, #2
	add r1, r1, #2
	subs r5, r5, #1
	bpl .L0800045C
	sub r0, r0, r3, lsl #1
	sub r0, r0, #0x42
	subs r6, r6, #1
	bpl .L08000458
	pop {r4, r5, r6, r7}
	bx lr
	.align 2, 0
.L08000490: .4byte gOamHiPutIt

	arm_func_start PutOamHi
PutOamHi: @ 0x08000494
	push {r4, r5, r6, r7}
	ldr r7, .L08000490 @ =gOamHiPutIt
.L0800049C:
	ldr r5, [r7]
	ldrh r4, [r2]
	tst r4, r4
	beq .L08000528
	bmi .L08000528
	add r2, r2, #2
	add r6, r5, r4, lsl #3
	str r6, [r7]
	mov r7, #0x10000
	sub r7, r7, #1
	and r0, r0, r7
	and r1, r1, r7
	orr r0, r0, r1, lsl #16
.L080004D0:
	ldrh r1, [r2]
	orr r6, r1, r0, lsr #16
	and r6, r6, #0xff00
	add r7, r1, r0, lsr #16
	and r7, r7, #0xff
	orr r6, r6, r7
	strh r6, [r5]
	ldrh r1, [r2, #2]
	orr r6, r1, r0
	and r6, r6, #0xfe00
	add r7, r1, r0
	lsl r7, r7, #0x17
	lsr r7, r7, #0x17
	orr r6, r6, r7
	strh r6, [r5, #2]
	ldrh r1, [r2, #4]
	add r6, r1, r3
	strh r6, [r5, #4]
	add r2, r2, #6
	add r5, r5, #8
	subs r4, r4, #1
	bne .L080004D0
.L08000528:
	pop {r4, r5, r6, r7}
	bx lr
	.align 2, 0
.L08000530: .4byte gOamLoPutIt

	arm_func_start PutOamLo
PutOamLo: @ 0x08000534
	push {r4, r5, r6, r7}
	ldr r7, .L08000530 @ =gOamLoPutIt
	b .L0800049C
.L08000540:
	.byte 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00
	.byte 0x00, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00
.L08000560: .4byte 0x08000540

	arm_func_start DrawGlyph
DrawGlyph: @ 0x08000564
	push {r4, r5, r6, r7, r8, sb, sl}
	mov sb, #0xf
	mov sl, #0x10000
	sub sl, sl, #1
.L08000574:
	ldr r4, .L08000560 @ =0x08000540
	ldr r5, [r4, r3, lsl #2]
	ldr r4, [r2]
	umull r5, r6, r4, r5
	mov r7, r5
	and r7, r7, #0xff
	ldr r7, [r0, r7, lsl #1]
	lsr r8, r5, #8
	and r8, r8, #0xff
	ldr r8, [r0, r8, lsl #1]
	and r7, r7, sl
	orr r7, r7, r8, lsl #16
	ldr r4, [r1]
	orr r4, r4, r7
	str r4, [r1]
	lsr r7, r5, #0x10
	and r7, r7, #0xff
	ldr r7, [r0, r7, lsl #1]
	lsr r8, r5, #0x18
	and r8, r8, #0xff
	ldr r8, [r0, r8, lsl #1]
	and r7, r7, sl
	orr r7, r7, r8, lsl #16
	ldr r4, [r1, #0x40]
	orr r4, r4, r7
	str r4, [r1, #0x40]
	mov r7, r6
	and r7, r7, #0xff
	ldr r7, [r0, r7, lsl #1]
	lsr r8, r6, #8
	and r8, r8, #0xff
	ldr r8, [r0, r8, lsl #1]
	and r7, r7, sl
	orr r7, r7, r8, lsl #16
	ldr r4, [r1, #0x80]
	orr r4, r4, r7
	str r4, [r1, #0x80]
	add r1, r1, #4
	add r2, r2, #4
	subs sb, sb, #1
	bpl .L08000574
	pop {r4, r5, r6, r7, r8, sb, sl}
	bx lr

	arm_func_start func_fe6_08000620
func_fe6_08000620: @ 0x08000620
	push {r4, r5, r6, r7, r8, sb, sl}
	mov sb, #7
	mov sl, #0x10000
	sub sl, sl, #1
.L08000630:
	ldr r4, .L08000560 @ =0x08000540
	ldr r5, [r4, r3, lsl #2]
	ldr r4, [r2]
	umull r5, r6, r4, r5
	mov r7, r5
	and r7, r7, #0xff
	ldr r7, [r0, r7, lsl #1]
	lsr r8, r5, #8
	and r8, r8, #0xff
	ldr r8, [r0, r8, lsl #1]
	and r7, r7, sl
	orr r7, r7, r8, lsl #16
	ldr r4, [r1]
	orr r4, r4, r7
	str r4, [r1]
	lsr r7, r5, #0x10
	and r7, r7, #0xff
	ldr r7, [r0, r7, lsl #1]
	lsr r8, r5, #0x18
	and r8, r8, #0xff
	ldr r8, [r0, r8, lsl #1]
	and r7, r7, sl
	orr r7, r7, r8, lsl #16
	ldr r4, [r1, #0x40]
	orr r4, r4, r7
	str r4, [r1, #0x20]
	mov r7, r6
	and r7, r7, #0xff
	ldr r7, [r0, r7, lsl #1]
	lsr r8, r6, #8
	and r8, r8, #0xff
	ldr r8, [r0, r8, lsl #1]
	and r7, r7, sl
	orr r7, r7, r8, lsl #16
	ldr r4, [r1, #0x80]
	orr r4, r4, r7
	str r4, [r1, #0x40]
	add r1, r1, #4
	add r2, r2, #4
	subs sb, sb, #1
	bpl .L08000630
	pop {r4, r5, r6, r7, r8, sb, sl}
	bx lr
	.align 2, 0
.L080006DC: .4byte gMsgHuffmanTableRoot
.L080006E0: .4byte gMsgHuffmanTable

	arm_func_start DecodeString
DecodeString: @ 0x080006E4
	push {r4, r5, r6, r7}
	sub r3, r3, r3
	ldr r5, .L080006E0 @ =gMsgHuffmanTable
	ldr r7, .L080006DC @ =gMsgHuffmanTableRoot
	ldr r7, [r7]
.L080006F8:
	mov r4, r7
.L080006FC:
	subs r3, r3, #1
	bpl .L08000710
	ldrb r2, [r0]
	add r0, r0, #1
	mov r3, #7
.L08000710:
	tst r2, #1
	beq .L08000720
	ldrh r6, [r4, #2]
	b .L08000724
.L08000720:
	ldrh r6, [r4]
.L08000724:
	add r4, r5, r6, lsl #2
	lsr r2, r2, #1
	ldr r6, [r4]
	tst r6, r6
	bpl .L080006FC
	tst r6, #0xff00
	beq .L08000754
	strb r6, [r1]
	lsr r6, r6, #8
	strb r6, [r1, #1]
	add r1, r1, #2
	b .L080006F8
.L08000754:
	strb r6, [r1]
	tst r6, #0xff
	beq .L08000768
	add r1, r1, #1
	b .L080006F8
.L08000768:
	pop {r4, r5, r6, r7}
	bx lr
	.align 2, 0
.L08000770: .4byte gWorkingMovTable
.L08000774: .4byte gMapFloodSt
.L08000778: .4byte gWorkingMap
.L0800077C: .4byte gMapTerrain
.L08000780: .4byte gMapUnit

	arm_func_start MapFloodCoreStep
MapFloodCoreStep: @ 0x08000784
	push {r4, r5, r6, r7, r8, sb, sl}
	ldr r3, .L08000774 @ =gMapFloodSt
	ldr r4, [r3]
	ldrb r5, [r4]
	add r1, r1, r5
	ldrb r6, [r4, #1]
	add r2, r2, r6
	ldr r7, .L0800077C @ =gMapTerrain
	ldr r7, [r7]
	ldr r7, [r7, r2, lsl #2]
	ldrb r7, [r7, r1]
	ldr r8, .L08000770 @ =gWorkingMovTable
	ldrb sl, [r8, r7]
	ldr r7, .L08000778 @ =gWorkingMap
	ldr r7, [r7]
	ldr sb, [r7, r6, lsl #2]
	ldrb sb, [sb, r5]
	add sl, sl, sb
	ldr sb, [r7, r2, lsl #2]
	ldrb sb, [sb, r1]
	cmp sl, sb
	bhs .L08000848
	ldrb r4, [r3, #8]
	tst r4, r4
	beq .L08000810
	ldr r7, .L08000780 @ =gMapUnit
	ldr r7, [r7]
	ldr r7, [r7, r2, lsl #2]
	ldrb r7, [r7, r1]
	tst r7, r7
	beq .L08000810
	ldrb r4, [r3, #0xa]
	eor r4, r4, r7
	ands r4, r4, #0x80
	bne .L08000848
.L08000810:
	ldrb r4, [r3, #9]
	cmp sl, r4
	bhi .L08000848
	ldr r4, [r3, #4]
	strb r1, [r4]
	strb r2, [r4, #1]
	strb r0, [r4, #2]
	strb sl, [r4, #3]
	add r4, r4, #4
	str r4, [r3, #4]
	ldr r7, .L08000778 @ =gWorkingMap
	ldr r7, [r7]
	ldr r7, [r7, r2, lsl #2]
	strb sl, [r7, r1]
.L08000848:
	pop {r4, r5, r6, r7, r8, sb, sl}
	bx lr
	.align 2, 0
.L08000850: .4byte gMapFloodSquareBufB
.L08000854: .4byte gMapFloodSquareBufA
.L08000858:
	.byte 0x4D, 0x00, 0x00, 0xEA, 0x59, 0x00, 0x00, 0xEA
	.byte 0x3E, 0x00, 0x00, 0xEA, 0x30, 0x00, 0x00, 0xEA, 0x69, 0x00, 0x00, 0xEA, 0x1D, 0x00, 0x00, 0xEA
	.byte 0x58, 0x08, 0x00, 0x08

	arm_func_start MapFloodCore
MapFloodCore: @ 0x08000874
	push {r4, r5, r6, lr}
	mov r4, #0
	ldr r5, .L08000774 @ =gMapFloodSt
	eors r4, r4, #1
	beq .L0800089C
	ldr r0, .L08000850 @ =gMapFloodSquareBufB
	str r0, [r5]
	ldr r0, .L08000854 @ =gMapFloodSquareBufA
	str r0, [r5, #4]
	b .L080008AC
.L0800089C:
	ldr r0, .L08000854 @ =gMapFloodSquareBufA
	str r0, [r5]
	ldr r0, .L08000850 @ =gMapFloodSquareBufB
	str r0, [r5, #4]
.L080008AC:
	ldr r6, [r5]
	ldrb r6, [r6, #2]
	cmp r6, #4
	beq .L08000A18
	ldr r6, [r5]
	ldrb r6, [r6, #2]
	mov r0, pc
	add r0, r0, #8
	add r0, r0, r6, lsl #2
	bx r0
.L080008D4:
	.byte 0x2E, 0x00, 0x00, 0xEA, 0x3A, 0x00, 0x00, 0xEA, 0x1F, 0x00, 0x00, 0xEA
	.byte 0x11, 0x00, 0x00, 0xEA, 0x4A, 0x00, 0x00, 0xEA, 0x03, 0x00, 0xA0, 0xE3, 0x00, 0x10, 0xA0, 0xE3
	.byte 0x00, 0x20, 0xE0, 0xE3, 0xA2, 0xFF, 0xFF, 0xEB, 0x02, 0x00, 0xA0, 0xE3, 0x00, 0x10, 0xA0, 0xE3
	.byte 0x01, 0x20, 0xA0, 0xE3, 0x9E, 0xFF, 0xFF, 0xEB, 0x00, 0x00, 0xA0, 0xE3, 0x00, 0x10, 0xE0, 0xE3
	.byte 0x00, 0x20, 0xA0, 0xE3, 0x9A, 0xFF, 0xFF, 0xEB, 0x01, 0x00, 0xA0, 0xE3, 0x01, 0x10, 0xA0, 0xE3
	.byte 0x00, 0x20, 0xA0, 0xE3, 0x96, 0xFF, 0xFF, 0xEB, 0x32, 0x00, 0x00, 0xEA, 0x03, 0x00, 0xA0, 0xE3
	.byte 0x00, 0x10, 0xA0, 0xE3, 0x00, 0x20, 0xE0, 0xE3, 0x91, 0xFF, 0xFF, 0xEB, 0x00, 0x00, 0xA0, 0xE3
	.byte 0x00, 0x10, 0xE0, 0xE3, 0x00, 0x20, 0xA0, 0xE3, 0x8D, 0xFF, 0xFF, 0xEB, 0x01, 0x00, 0xA0, 0xE3
	.byte 0x01, 0x10, 0xA0, 0xE3, 0x00, 0x20, 0xA0, 0xE3, 0x89, 0xFF, 0xFF, 0xEB, 0x25, 0x00, 0x00, 0xEA
	.byte 0x02, 0x00, 0xA0, 0xE3, 0x00, 0x10, 0xA0, 0xE3, 0x01, 0x20, 0xA0, 0xE3, 0x84, 0xFF, 0xFF, 0xEB
	.byte 0x00, 0x00, 0xA0, 0xE3, 0x00, 0x10, 0xE0, 0xE3, 0x00, 0x20, 0xA0, 0xE3, 0x80, 0xFF, 0xFF, 0xEB
	.byte 0x01, 0x00, 0xA0, 0xE3, 0x01, 0x10, 0xA0, 0xE3, 0x00, 0x20, 0xA0, 0xE3, 0x7C, 0xFF, 0xFF, 0xEB
	.byte 0x18, 0x00, 0x00, 0xEA, 0x03, 0x00, 0xA0, 0xE3, 0x00, 0x10, 0xA0, 0xE3, 0x00, 0x20, 0xE0, 0xE3
	.byte 0x77, 0xFF, 0xFF, 0xEB, 0x02, 0x00, 0xA0, 0xE3, 0x00, 0x10, 0xA0, 0xE3, 0x01, 0x20, 0xA0, 0xE3
	.byte 0x73, 0xFF, 0xFF, 0xEB, 0x00, 0x00, 0xA0, 0xE3, 0x00, 0x10, 0xE0, 0xE3, 0x00, 0x20, 0xA0, 0xE3
	.byte 0x6F, 0xFF, 0xFF, 0xEB, 0x0B, 0x00, 0x00, 0xEA, 0x03, 0x00, 0xA0, 0xE3, 0x00, 0x10, 0xA0, 0xE3
	.byte 0x00, 0x20, 0xE0, 0xE3, 0x6A, 0xFF, 0xFF, 0xEB, 0x02, 0x00, 0xA0, 0xE3, 0x00, 0x10, 0xA0, 0xE3
	.byte 0x01, 0x20, 0xA0, 0xE3, 0x66, 0xFF, 0xFF, 0xEB, 0x01, 0x00, 0xA0, 0xE3, 0x01, 0x10, 0xA0, 0xE3
	.byte 0x00, 0x20, 0xA0, 0xE3, 0x62, 0xFF, 0xFF, 0xEB, 0x04, 0x60, 0x95, 0xE5, 0x04, 0x00, 0xA0, 0xE3
	.byte 0x02, 0x00, 0xC6, 0xE5, 0x00, 0x60, 0x95, 0xE5, 0x04, 0x60, 0x86, 0xE2, 0x00, 0x60, 0x85, 0xE5
	.byte 0xA9, 0xFF, 0xFF, 0xEA, 0x99, 0xFF, 0xFF, 0xEA
.L08000A18:
	pop {r4, r5, r6, lr}
	bx lr

	.global ArmCodeEnd
	.type   ArmCodeEnd, object

ArmCodeEnd:
