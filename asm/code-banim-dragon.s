
	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_08058A80
func_fe6_08058A80: @ 0x08058A80
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, .L08058AAC @ =gUnk_081BF434
	ldr r5, .L08058AB0 @ =gPal+0x20
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
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

	thumb_func_start func_fe6_08058ACC
func_fe6_08058ACC: @ 0x08058ACC
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
	bl func_fe6_08047C68
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	adds r1, r0, #0
	cmp r1, #0
	bne .L08058B50
	ldr r0, .L08058B74 @ =gEkrDistanceType
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
	bl EfxTmCpyExtHFlip
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
	bl EfxTmCpyExt
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
.L08058B74: .4byte gEkrDistanceType
.L08058B78: .4byte gUnk_Banim_0201D414
.L08058B7C: .4byte gBg3Tm
.L08058B80: .4byte 0x06008000

	thumb_func_start func_fe6_08058B84
func_fe6_08058B84: @ 0x08058B84
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
	bl func_fe6_08047C68
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	adds r1, r0, #0
	cmp r1, #0
	bne .L08058C08
	ldr r0, .L08058C2C @ =gEkrDistanceType
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
	bl EfxTmCpyExtHFlip
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
	bl EfxTmCpyExt
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
.L08058C2C: .4byte gEkrDistanceType
.L08058C30: .4byte gUnk_Banim_0201D414
.L08058C34: .4byte gBg3Tm
.L08058C38: .4byte 0x06008000

	thumb_func_start func_fe6_08058C3C
func_fe6_08058C3C: @ 0x08058C3C
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
	bl func_fe6_08047C68
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08058CBE
	ldr r0, .L08058CDC @ =gEkrDistanceType
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
	bl EfxTmCpyExtHFlip
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
	bl EfxTmCpyExt
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
.L08058CDC: .4byte gEkrDistanceType
.L08058CE0: .4byte gUnk_Banim_0201D414
.L08058CE4: .4byte gBg3Tm
.L08058CE8: .4byte 0x06008000

	thumb_func_start func_fe6_08058CEC
func_fe6_08058CEC: @ 0x08058CEC
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

	thumb_func_start func_fe6_08058D08
func_fe6_08058D08: @ 0x08058D08
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

	thumb_func_start func_fe6_08058D34
func_fe6_08058D34: @ 0x08058D34
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
	bl func_fe6_08047C68
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
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
	bl EfxTmCpyBgHFlip
	ldr r0, .L08058DAC @ =gEkrDistanceType
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
.L08058DAC: .4byte gEkrDistanceType
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
	ldr r4, .L08058E00 @ =gEkrBgPosition
	ldr r0, [r4]
	adds r0, #0x30
	bl func_fe6_08058CEC
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
	bl func_fe6_0805B094
	adds r0, r6, #4
	str r4, [sp]
	movs r1, #2
	movs r2, #0x16
	movs r3, #0xf0
	bl func_fe6_0805B094
	b .L08058E14
	.align 2, 0
.L08058E00: .4byte gEkrBgPosition
.L08058E04:
	movs r0, #0x10
	bl func_fe6_08058CEC
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

	thumb_func_start func_fe6_08058E24
func_fe6_08058E24: @ 0x08058E24
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

	thumb_func_start func_fe6_08058E58
func_fe6_08058E58: @ 0x08058E58
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

	thumb_func_start func_fe6_08058E90
func_fe6_08058E90: @ 0x08058E90
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

	thumb_func_start func_fe6_08058EC8
func_fe6_08058EC8: @ 0x08058EC8
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

	thumb_func_start func_fe6_08058F00
func_fe6_08058F00: @ 0x08058F00
	push {lr}
	bl GetEkrDragonStatueType70
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

	thumb_func_start InitEkrDragonStatus
InitEkrDragonStatus: @ 0x08058F28
	push {lr}
	bl func_fe6_08058F00
	bl SetAnimStateHidden
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08058F38
func_fe6_08058F38: @ 0x08058F38
	push {lr}
	bl GetEkrDragonStatueType70
	cmp r0, #0
	beq .L08058F58
	ldr r0, .L08058F54 @ =gAnims
	ldr r0, [r0]
	bl GetEkrDragonStatusIdx
	ldrh r0, [r0]
	cmp r0, #1
	bne .L08058F58
	movs r0, #1
	b .L08058F5A
	.align 2, 0
.L08058F54: .4byte gAnims
.L08058F58:
	movs r0, #0
.L08058F5A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08058F60
func_fe6_08058F60: @ 0x08058F60
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
	bl EfxTmCpyExt
	movs r0, #8
	bl EnableBgSync
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08058FA0: .4byte gUnk_Banim_0201D456
.L08058FA4: .4byte gBg3Tm

	thumb_func_start func_fe6_08058FA8
func_fe6_08058FA8: @ 0x08058FA8
	push {r4, lr}
	sub sp, #0x10
	ldr r4, .L08058FDC @ =gUnk_Banim_0201977C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L08058FE0 @ =gEkrDistanceType
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
	bl EfxTmCpyExt
	b .L08059006
	.align 2, 0
.L08058FDC: .4byte gUnk_Banim_0201977C
.L08058FE0: .4byte gEkrDistanceType
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
	bl EfxTmCpyExt
.L08059006:
	movs r0, #8
	bl EnableBgSync
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08059014: .4byte gBg3Tm

	thumb_func_start func_fe6_08059018
func_fe6_08059018: @ 0x08059018
	push {lr}
	sub sp, #0x10
	ldr r1, .L08059068 @ =gUnk_Banim_0201E7CC
	bl LZ77UnCompWram
	ldr r0, .L0805906C @ =gEkrDistanceType
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
	bl EfxTmCpyExt
	ldr r0, .L08059074 @ =gEkrBgPosition
	ldr r0, [r0]
	bl func_fe6_08058F60
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
.L08059068: .4byte gUnk_Banim_0201E7CC
.L0805906C: .4byte gEkrDistanceType
.L08059070: .4byte gUnk_Banim_0201D414
.L08059074: .4byte gEkrBgPosition

	thumb_func_start func_fe6_08059078
func_fe6_08059078: @ 0x08059078
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

	thumb_func_start func_fe6_08059090
func_fe6_08059090: @ 0x08059090
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x5c]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xe6
	bl EfxPlaySE
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r0, #0xe6
	movs r2, #1
	bl M4aPlayWithPostionCtrl
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080590B8
func_fe6_080590B8: @ 0x080590B8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl GetAnimPosition
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
	bl GetAnimPosition
	ldr r1, .L080590F8 @ =gEkrDragonState
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
.L080590F8: .4byte gEkrDragonState

	thumb_func_start func_fe6_080590FC
func_fe6_080590FC: @ 0x080590FC
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
	bl func_fe6_0805B9A4
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
	bl func_fe6_08046C14
	adds r0, r4, #0
	bl Proc_Break
.L0805913C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08059144
func_fe6_08059144: @ 0x08059144
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl func_fe6_080589C4
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
	bl func_fe6_08059690
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xe8
	bl EfxPlaySE
	ldr r0, [r4, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r0, #0xe8
	movs r2, #1
	bl M4aPlayWithPostionCtrl
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L080591A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080591AC
func_fe6_080591AC: @ 0x080591AC
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

	thumb_func_start func_fe6_080591CC
func_fe6_080591CC: @ 0x080591CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl func_fe6_080589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08059244
	bl func_fe6_08058E24
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
	bl func_fe6_08058A50
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
	bl func_fe6_08058E24
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
	bl func_fe6_08058A50
	adds r0, r4, #0
	bl func_fe6_08058A80
	adds r0, r4, #0
	bl func_fe6_08058ACC
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

	thumb_func_start func_fe6_080592D0
func_fe6_080592D0: @ 0x080592D0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl func_fe6_080589C4
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
	bl func_fe6_08058B84
	movs r0, #5
	bl func_fe6_08046010
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
	bl func_fe6_08059078
	adds r0, r4, #0
	bl Proc_Break
.L08059320:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08059328
func_fe6_08059328: @ 0x08059328
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl func_fe6_080589C4
	lsls r0, r0, #0x18
	asrs r6, r0, #0x18
	cmp r6, #1
	bne .L0805937C
	adds r0, r5, #0
	bl func_fe6_08058C3C
	ldr r0, [r5, #0x5c]
	bl func_fe6_080598F0
	ldr r1, [r5, #0x5c]
	ldr r0, .L08059374 @ =0x0000FFFD
	ldrh r2, [r1]
	ands r0, r2
	movs r4, #0
	strh r0, [r1]
	ldr r0, [r5, #0x5c]
	movs r1, #0x55
	bl func_fe6_0804A528
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	ldr r1, .L08059378 @ =gEkrDragonIntroDone
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r6, [r0]
	strh r4, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
	b .L080593C6
	.align 2, 0
.L08059374: .4byte 0x0000FFFD
.L08059378: .4byte gEkrDragonIntroDone
.L0805937C:
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne .L080593A2
	adds r0, r5, #0
	bl func_fe6_08058C3C
	ldr r0, [r5, #0x5c]
	bl func_fe6_080598F0
	ldr r1, [r5, #0x5c]
	ldr r0, .L080593CC @ =0x0000FFFD
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	ldr r0, [r5, #0x5c]
	movs r1, #0x55
	bl func_fe6_0804A528
.L080593A2:
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3d
	bne .L080593C6
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	ldr r1, .L080593D0 @ =gEkrDragonIntroDone
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
.L080593D0: .4byte gEkrDragonIntroDone

	thumb_func_start func_fe6_080593D4
func_fe6_080593D4: @ 0x080593D4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L080593FC @ =gEkrDragonState
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
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
.L080593FC: .4byte gEkrDragonState

	thumb_func_start func_fe6_08059400
func_fe6_08059400: @ 0x08059400
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl func_fe6_08058A34
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08059418
func_fe6_08059418: @ 0x08059418
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl func_fe6_080589C4
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
	bl func_fe6_08058B84
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

	thumb_func_start func_fe6_0805946C
func_fe6_0805946C: @ 0x0805946C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl func_fe6_080589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805948E
	bl func_fe6_08058E24
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
	bl func_fe6_08058E24
	movs r0, #0x10
	bl func_fe6_0805B9A4
	adds r0, r4, #0
	bl func_fe6_08058A80
	adds r0, r4, #0
	bl func_fe6_08058ACC
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

	thumb_func_start func_fe6_080594CC
func_fe6_080594CC: @ 0x080594CC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L08059504
	ldr r0, [r4, #0x5c]
	bl func_fe6_080589C4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08059504
	ldr r0, [r4, #0x5c]
	movs r1, #1
	bl func_fe6_08059690
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xe9
	bl EfxPlaySE
	ldr r0, [r4, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r0, #0xe9
	movs r2, #1
	bl M4aPlayWithPostionCtrl
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
	bl func_fe6_08058A50
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

	thumb_func_start func_fe6_08059578
func_fe6_08059578: @ 0x08059578
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl func_fe6_080589C4
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
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl func_fe6_0804A528
	ldr r0, [r6, #0x5c]
	movs r1, #0
	movs r2, #0xa
	movs r3, #1
	bl func_fe6_08046C14
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

	thumb_func_start func_fe6_080595EC
func_fe6_080595EC: @ 0x080595EC
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
	bl func_fe6_0805B9A4
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L0805960E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08059614
func_fe6_08059614: @ 0x08059614
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
	bl func_fe6_0805B9A4
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

	thumb_func_start func_fe6_0805966C
func_fe6_0805966C: @ 0x0805966C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	ldr r1, .L0805968C @ =gEkrDragonIntroDone
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
.L0805968C: .4byte gEkrDragonIntroDone

	thumb_func_start func_fe6_08059690
func_fe6_08059690: @ 0x08059690
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
	bl func_fe6_080478DC
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
	bl func_fe6_08047500
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
	bl func_fe6_08047AB0
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

	thumb_func_start func_fe6_08059730
func_fe6_08059730: @ 0x08059730
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

	thumb_func_start func_fe6_08059758
func_fe6_08059758: @ 0x08059758
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

	thumb_func_start func_fe6_0805979C
func_fe6_0805979C: @ 0x0805979C
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

	thumb_func_start func_fe6_080597E0
func_fe6_080597E0: @ 0x080597E0
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

	thumb_func_start func_fe6_08059824
func_fe6_08059824: @ 0x08059824
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

	thumb_func_start func_fe6_08059868
func_fe6_08059868: @ 0x08059868
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

	thumb_func_start func_fe6_080598AC
func_fe6_080598AC: @ 0x080598AC
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

	thumb_func_start func_fe6_080598F0
func_fe6_080598F0: @ 0x080598F0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl GetAnimPosition
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

	thumb_func_start func_fe6_08059928
func_fe6_08059928: @ 0x08059928
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl func_fe6_08046F48
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
	bl func_fe6_08047BA4
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

	thumb_func_start func_fe6_080599D0
func_fe6_080599D0: @ 0x080599D0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl GetAnimPosition
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
	bl GetAnimPosition
	ldr r1, .L08059A18 @ =gEkrDragonState
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
	str r5, [r6, #0x5c]
	adds r0, r5, #0
	bl func_fe6_080589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08059A1C
	movs r0, #0x3c
	b .L08059A1E
	.align 2, 0
.L08059A10: .4byte gUnk_08604840
.L08059A14: .4byte gUnk_Banim_0201E7AC
.L08059A18: .4byte gEkrDragonState
.L08059A1C:
	movs r0, #0
.L08059A1E:
	strh r0, [r6, #0x2c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08059A28
func_fe6_08059A28: @ 0x08059A28
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

	thumb_func_start func_fe6_08059A44
func_fe6_08059A44: @ 0x08059A44
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, .L08059AA0 @ =0x0203CD08
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
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
	bl GetAnimPosition
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
	bl func_fe6_080589C4
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
	bl func_fe6_0804A528
	ldr r0, [r5, #0x5c]
	movs r1, #0
	bl SwitchAISFrameDataFromBARoundType
	adds r0, r5, #0
	bl Proc_Break
.L08059ACA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08059AD0
func_fe6_08059AD0: @ 0x08059AD0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl func_fe6_080589C4
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
	cmp r5, #1
	bne .L08059B04
	ldr r0, [r4, #0x5c]
	movs r1, #0x5b
	bl func_fe6_0804A528
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	ldr r1, .L08059B00 @ =gEkrDragonIntroDone
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r5, [r0]
	adds r0, r4, #0
	bl Proc_Break
	b .L08059B6E
	.align 2, 0
.L08059B00: .4byte gEkrDragonIntroDone
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
	bl EfxPlaySE
	ldr r0, [r4, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r0, #0xdc
	movs r2, #1
	bl M4aPlayWithPostionCtrl
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
	bl EfxPlaySE
	ldr r0, [r4, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r0, #0xde
	movs r2, #1
	bl M4aPlayWithPostionCtrl
	ldr r0, [r4, #0x5c]
	movs r1, #0x5b
	bl func_fe6_0804A528
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	ldr r1, .L08059B74 @ =gEkrDragonIntroDone
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
.L08059B74: .4byte gEkrDragonIntroDone

	thumb_func_start func_fe6_08059B78
func_fe6_08059B78: @ 0x08059B78
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L08059BA4 @ =gEkrDragonState
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #2
	bne .L08059BDC
	ldr r0, [r5, #0x5c]
	bl func_fe6_080589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08059BA8
	adds r0, r5, #0
	bl Proc_Break
	b .L08059BDC
	.align 2, 0
.L08059BA4: .4byte gEkrDragonState
.L08059BA8:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xdd
	bl EfxPlaySE
	ldr r0, [r5, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r0, #0xdd
	movs r2, #1
	bl M4aPlayWithPostionCtrl
	ldr r0, [r5, #0x5c]
	movs r1, #0x6c
	bl func_fe6_0804A528
	ldr r0, [r5, #0x5c]
	movs r1, #0
	bl SwitchAISFrameDataFromBARoundType
	ldr r0, [r5, #0x5c]
	bl func_fe6_08059C78
	adds r0, r5, #0
	bl Proc_Break
.L08059BDC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08059BE4
func_fe6_08059BE4: @ 0x08059BE4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl func_fe6_080589C4
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
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl func_fe6_0804A528
	strh r7, [r6, #0x2c]
	adds r0, r6, #0
	bl Proc_Break
.L08059C2E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08059C34: .4byte 0x0203CD00

	thumb_func_start func_fe6_08059C38
func_fe6_08059C38: @ 0x08059C38
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

	thumb_func_start func_fe6_08059C54
func_fe6_08059C54: @ 0x08059C54
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	ldr r1, .L08059C74 @ =gEkrDragonIntroDone
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
.L08059C74: .4byte gEkrDragonIntroDone

	thumb_func_start func_fe6_08059C78
func_fe6_08059C78: @ 0x08059C78
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
	bl func_fe6_08047ACC
	ldr r0, .L08059CE4 @ =gUnk_081C8F38
	movs r1, #0x20
	bl func_fe6_08047AF4
	bl func_fe6_08047500
	ldr r0, .L08059CE8 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08059CF8
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
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
.L08059CE8: .4byte gEkrDistanceType
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

	thumb_func_start func_fe6_08059D34
func_fe6_08059D34: @ 0x08059D34
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl func_fe6_08047BA4
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
	bl func_fe6_0804799C
	b .L08059D80
.L08059D62:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L08059D80
	bl SpellFx_ClearBG1
	ldr r1, .L08059D88 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl func_fe6_080475D8
	adds r0, r4, #0
	bl Proc_Break
.L08059D80:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08059D88: .4byte gUnk_Banim_02017744

	thumb_func_start func_fe6_08059D8C
func_fe6_08059D8C: @ 0x08059D8C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl GetAnimPosition
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
	bl GetAnimPosition
	ldr r1, .L08059DCC @ =gEkrDragonState
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
.L08059DCC: .4byte gEkrDragonState

	thumb_func_start func_fe6_08059DD0
func_fe6_08059DD0: @ 0x08059DD0
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
	bl func_fe6_0805B9A4
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

	thumb_func_start func_fe6_08059E08
func_fe6_08059E08: @ 0x08059E08
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	movs r1, #0x74
	bl func_fe6_0804A528
	ldr r0, .L08059E6C @ =gAnims
	ldr r3, [r0]
	ldr r4, [r0, #4]
	ldr r2, .L08059E70 @ =gUnk_Banim_02000020
	ldr r7, .L08059E74 @ =gUnk_Banim_02000028
	ldrh r1, [r7]
	adds r1, #0x54
	strh r1, [r2]
	ldr r6, .L08059E78 @ =gEkrBgPosition
	ldr r0, [r6]
	subs r1, r1, r0
	strh r1, [r3, #2]
	ldrh r2, [r2]
	subs r0, r2, r0
	strh r0, [r4, #2]
	ldr r0, [r5, #0x5c]
	bl func_fe6_080589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L08059E5A
	ldr r0, [r5, #0x5c]
	bl func_fe6_0805A77C
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
.L08059E6C: .4byte gAnims
.L08059E70: .4byte gUnk_Banim_02000020
.L08059E74: .4byte gUnk_Banim_02000028
.L08059E78: .4byte gEkrBgPosition
.L08059E7C: .4byte gUnk_Banim_0201E7B4

	thumb_func_start func_fe6_08059E80
func_fe6_08059E80: @ 0x08059E80
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
	bl func_fe6_08047C68
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

	thumb_func_start func_fe6_08059F2C
func_fe6_08059F2C: @ 0x08059F2C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, .L08059F4C @ =gUnk_Banim_0201E7B4
	ldr r5, [r0]
	ldr r0, [r6, #0x5c]
	bl func_fe6_080589C4
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
	bl func_fe6_08058FA8
	ldr r0, [r6, #0x5c]
	movs r1, #3
	movs r2, #0x64
	bl func_fe6_0804685C
	ldr r4, .L08059FFC @ =0x0000013F
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, #0
	bl EfxPlaySE
	ldr r0, [r6, #0x5c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	adds r0, r4, #0
	movs r2, #1
	bl M4aPlayWithPostionCtrl
	movs r0, #6
	bl func_fe6_08046010
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

	thumb_func_start func_fe6_0805A000
func_fe6_0805A000: @ 0x0805A000
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl func_fe6_080589C4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805A028
	ldr r0, [r4, #0x5c]
	bl func_fe6_0805A410
	str r0, [r4, #0x64]
	adds r0, r4, #0
	bl Proc_Break
	b .L0805A096
.L0805A028:
	ldr r5, .L0805A0A4 @ =gUnk_Banim_0201E7B4
	ldr r1, [r5]
	ldr r0, .L0805A0A8 @ =gUnk_Banim_02000028
	mov r8, r0
	ldr r2, .L0805A0AC @ =gEkrBgPosition
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
	bl func_fe6_0805A410
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
.L0805A0AC: .4byte gEkrBgPosition
.L0805A0B0: .4byte gUnk_Banim_02017758
.L0805A0B4: .4byte 0x00007FFF
.L0805A0B8: .4byte gUnk_Banim_02017734

	thumb_func_start func_fe6_0805A0BC
func_fe6_0805A0BC: @ 0x0805A0BC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x64]
	adds r5, r0, #0
	adds r5, #0x29
	ldrb r0, [r5]
	cmp r0, #1
	bne .L0805A132
	ldr r0, [r4, #0x5c]
	bl func_fe6_080589C4
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
	bl func_fe6_0805A598
	str r0, [r4, #0x64]
	ldr r0, [r4, #0x5c]
	bl func_fe6_0805A7EC
	adds r1, r0, #0
	ldr r0, .L0805A10C @ =gUnk_Banim_0201E7B4
	str r1, [r0, #4]
	ldr r0, .L0805A110 @ =gEkrDistanceType
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L0805A114
	movs r0, #0x54
	b .L0805A116
	.align 2, 0
.L0805A10C: .4byte gUnk_Banim_0201E7B4
.L0805A110: .4byte gEkrDistanceType
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
	bl EfxPlaySE
	adds r0, r4, #0
	bl Proc_Break
.L0805A132:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A138: .4byte gUnk_Banim_0201E7B4
.L0805A13C: .4byte 0x0000FFF5

	thumb_func_start func_fe6_0805A140
func_fe6_0805A140: @ 0x0805A140
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
	bl func_fe6_080589C4
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	cmp r4, #1
	bne .L0805A1A8
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	bl SetAnimStateUnHidden
	ldr r0, .L0805A19C @ =gUnk_Banim_0201EFCC
	ldr r1, .L0805A1A0 @ =gPal+0xC0
	movs r2, #8
	bl CpuFastSet
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	ldr r1, .L0805A1A4 @ =gEkrDragonIntroDone
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	ldr r0, [r5, #0x5c]
	bl func_fe6_0805A858
	adds r0, r5, #0
	bl Proc_Break
	b .L0805A216
	.align 2, 0
.L0805A198: .4byte gUnk_Banim_0201E7B4
.L0805A19C: .4byte gUnk_Banim_0201EFCC
.L0805A1A0: .4byte gPal+0xC0
.L0805A1A4: .4byte gEkrDragonIntroDone
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
	bl GetAnimPosition
	bl SetAnimStateUnHidden
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	ldr r1, .L0805A224 @ =gEkrDragonIntroDone
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	ldr r0, [r5, #0x5c]
	bl func_fe6_0805A858
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
.L0805A224: .4byte gEkrDragonIntroDone

	thumb_func_start func_fe6_0805A228
func_fe6_0805A228: @ 0x0805A228
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0805A268 @ =gEkrDragonState
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #2
	bne .L0805A262
	bl func_fe6_0805A894
	ldr r4, .L0805A26C @ =gUnk_Banim_0201E7C4
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #1
	bne .L0805A25C
	ldr r0, [r5, #0x5c]
	bl func_fe6_0805AB5C
	str r0, [r5, #0x64]
.L0805A25C:
	adds r0, r5, #0
	bl Proc_Break
.L0805A262:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A268: .4byte gEkrDragonState
.L0805A26C: .4byte gUnk_Banim_0201E7C4

	thumb_func_start func_fe6_0805A270
func_fe6_0805A270: @ 0x0805A270
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x64]
	ldr r4, .L0805A29C @ =gUnk_Banim_0201E7C4
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0805A2A0
	ldr r0, [r5, #0x5c]
	movs r1, #1
	movs r2, #0x20
	bl func_fe6_0805A658
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

	thumb_func_start func_fe6_0805A2BC
func_fe6_0805A2BC: @ 0x0805A2BC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x64]
	ldr r4, .L0805A2E0 @ =gUnk_Banim_0201E7C4
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #1
	bne .L0805A2E4
	ldr r0, [r5, #0x5c]
	bl func_fe6_0805A4C8
	str r0, [r5, #0x64]
	b .L0805A30E
	.align 2, 0
.L0805A2E0: .4byte gUnk_Banim_0201E7C4
.L0805A2E4:
	ldr r0, [r5, #0x5c]
	bl func_fe6_080589C4
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
	bl func_fe6_0805A4C8
	str r0, [r5, #0x64]
	movs r0, #0x10
	bl func_fe6_0805B9A4
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
	bl func_fe6_0805A4C8
	str r0, [r5, #0x64]
	movs r0, #0x10
	bl func_fe6_0805B9A4
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	ldr r1, .L0805A358 @ =gEkrPairSideVaild
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	bl SetAnimStateHidden
	adds r0, r5, #0
	bl Proc_Break
.L0805A352:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A358: .4byte gEkrPairSideVaild

	thumb_func_start func_fe6_0805A35C
func_fe6_0805A35C: @ 0x0805A35C
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

	thumb_func_start func_fe6_0805A394
func_fe6_0805A394: @ 0x0805A394
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
	bl func_fe6_0805B9A4
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

	thumb_func_start func_fe6_0805A3EC
func_fe6_0805A3EC: @ 0x0805A3EC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	ldr r1, .L0805A40C @ =gEkrDragonIntroDone
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
.L0805A40C: .4byte gEkrDragonIntroDone

	thumb_func_start func_fe6_0805A410
func_fe6_0805A410: @ 0x0805A410
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

	thumb_func_start func_fe6_0805A434
func_fe6_0805A434: @ 0x0805A434
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
	bl EfxPalBlackInOut
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
	bl func_fe6_0805B094
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

	thumb_func_start func_fe6_0805A4B4
func_fe6_0805A4B4: @ 0x0805A4B4
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

	thumb_func_start func_fe6_0805A4C8
func_fe6_0805A4C8: @ 0x0805A4C8
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
	bl func_fe6_0804BF40
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
	bl EfxPalBlackInOut
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A50C: .4byte gUnk_08604968
.L0805A510: .4byte gUnk_Banim_0201E0FC
.L0805A514: .4byte gPal+0x80
.L0805A518: .4byte gUnk_Banim_0201F00C

	thumb_func_start func_fe6_0805A51C
func_fe6_0805A51C: @ 0x0805A51C
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
	bl EfxPalBlackInOut
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

	thumb_func_start func_fe6_0805A584
func_fe6_0805A584: @ 0x0805A584
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

	thumb_func_start func_fe6_0805A598
func_fe6_0805A598: @ 0x0805A598
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

	thumb_func_start func_fe6_0805A5C4
func_fe6_0805A5C4: @ 0x0805A5C4
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
	bl func_fe6_08058FA8
	b .L0805A602
	.align 2, 0
.L0805A5E8: .4byte gUnk_081C4E28
.L0805A5EC:
	cmp r0, #1
	bne .L0805A5FC
	ldr r0, .L0805A5F8 @ =gUnk_081C5264
	bl func_fe6_08058FA8
	b .L0805A602
	.align 2, 0
.L0805A5F8: .4byte gUnk_081C5264
.L0805A5FC:
	ldr r0, .L0805A638 @ =gUnk_081C5688
	bl func_fe6_08058FA8
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

	thumb_func_start func_fe6_0805A63C
func_fe6_0805A63C: @ 0x0805A63C
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

	thumb_func_start func_fe6_0805A658
func_fe6_0805A658: @ 0x0805A658
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

	thumb_func_start func_fe6_0805A6B8
func_fe6_0805A6B8: @ 0x0805A6B8
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

	thumb_func_start func_fe6_0805A6DC
func_fe6_0805A6DC: @ 0x0805A6DC
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
	bl EfxPalBlackInOut
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #1
	adds r3, r5, #0
	bl EfxPalBlackInOut
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

	thumb_func_start func_fe6_0805A768
func_fe6_0805A768: @ 0x0805A768
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

	thumb_func_start func_fe6_0805A77C
func_fe6_0805A77C: @ 0x0805A77C
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

	thumb_func_start func_fe6_0805A7C0
func_fe6_0805A7C0: @ 0x0805A7C0
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

	thumb_func_start func_fe6_0805A7EC
func_fe6_0805A7EC: @ 0x0805A7EC
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

	thumb_func_start func_fe6_0805A82C
func_fe6_0805A82C: @ 0x0805A82C
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

	thumb_func_start func_fe6_0805A858
func_fe6_0805A858: @ 0x0805A858
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

	thumb_func_start func_fe6_0805A894
func_fe6_0805A894: @ 0x0805A894
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

	thumb_func_start func_fe6_0805A8B0
func_fe6_0805A8B0: @ 0x0805A8B0
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
	bl func_fe6_08057B90
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
	bl func_fe6_08047BA4
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0805A958
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl func_fe6_08059018
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
	bl GetAnimAnotherSide
	movs r1, #8
	ldrh r0, [r0, #0x10]
	ands r1, r0
	cmp r1, #0
	beq .L0805A992
	movs r0, #1
	strh r0, [r4, #0x2e]
	b .L0805A992
.L0805A97E:
	bl func_fe6_080449C4
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

	thumb_func_start func_fe6_0805A998
func_fe6_0805A998: @ 0x0805A998
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
	bl EfxPlaySE
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

	thumb_func_start func_fe6_0805A9F8
func_fe6_0805A9F8: @ 0x0805A9F8
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
	bl EfxPalBlackInOut
	adds r0, r5, #0
	movs r1, #0x17
	movs r2, #1
	mov r3, r8
	bl EfxPalBlackInOut
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

	thumb_func_start func_fe6_0805AAA0
func_fe6_0805AAA0: @ 0x0805AAA0
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
	bl EfxPalBlackInOut
	adds r0, r5, #0
	movs r1, #0x17
	movs r2, #1
	mov r3, r8
	bl EfxPalBlackInOut
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

	thumb_func_start func_fe6_0805AB50
func_fe6_0805AB50: @ 0x0805AB50
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805AB5C
func_fe6_0805AB5C: @ 0x0805AB5C
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
	bl EfxTmCpyExt
	ldr r0, [r5, #0x5c]
	movs r1, #0x64
	movs r2, #0xc8
	bl func_fe6_0805A658
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

	thumb_func_start func_fe6_0805ABC0
func_fe6_0805ABC0: @ 0x0805ABC0
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
	bl func_fe6_0805AE1C
	ldr r0, .L0805AC50 @ =0x00000147
	movs r1, #0x80
	lsls r1, r1, #1
	bl EfxPlaySE
.L0805ABE8:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x23
	bne .L0805AC04
	ldr r0, [r4, #0x5c]
	movs r1, #3
	movs r2, #2
	movs r3, #3
	bl func_fe6_0805AE1C
	ldr r0, .L0805AC50 @ =0x00000147
	movs r1, #0x80
	lsls r1, r1, #1
	bl EfxPlaySE
.L0805AC04:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x32
	bne .L0805AC20
	ldr r0, [r4, #0x5c]
	movs r1, #3
	movs r2, #2
	movs r3, #3
	bl func_fe6_0805AE1C
	ldr r0, .L0805AC50 @ =0x00000147
	movs r1, #0x80
	lsls r1, r1, #1
	bl EfxPlaySE
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
	bl DoM4aSongNumStop
	movs r0, #0xa3
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	bl EfxPlaySE
	adds r0, r4, #0
	bl Proc_Break
.L0805AC48:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AC50: .4byte 0x00000147

	thumb_func_start func_fe6_0805AC54
func_fe6_0805AC54: @ 0x0805AC54
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
	ldr r0, .L0805ADC4 @ =gAnims
	ldr r4, [r0]
	ldr r5, [r0, #4]
	ldr r3, .L0805ADC8 @ =gUnk_Banim_02000020
	ldr r0, .L0805ADCC @ =gEkrBgPosition
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
	bl func_fe6_08045F48
	str r0, [r7, #0x5c]
.L0805AD1E:
	ldrh r6, [r7, #0x2c]
	cmp r6, #0x3c
	bne .L0805AD34
	ldr r0, [r7, #0x5c]
	bl Proc_End
	movs r0, #9
	movs r1, #0
	bl func_fe6_08045F48
	str r0, [r7, #0x5c]
.L0805AD34:
	ldrh r0, [r7, #0x2c]
	cmp r0, #0x5a
	bne .L0805AD4A
	ldr r0, [r7, #0x5c]
	bl Proc_End
	movs r0, #0xa
	movs r1, #0
	bl func_fe6_08045F48
	str r0, [r7, #0x5c]
.L0805AD4A:
	ldrh r1, [r7, #0x2c]
	cmp r1, #0x87
	bne .L0805AD5C
	ldr r0, [r7, #0x5c]
	movs r1, #0x3c
	movs r2, #0x1e
	movs r3, #0x78
	bl func_fe6_0805AE1C
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
.L0805ADC4: .4byte gAnims
.L0805ADC8: .4byte gUnk_Banim_02000020
.L0805ADCC: .4byte gEkrBgPosition
.L0805ADD0: .4byte gUnk_Banim_02000024
.L0805ADD4: .4byte gDispIo
.L0805ADD8: .4byte gUnk_Banim_02017758
.L0805ADDC: .4byte gPal+0xC0
.L0805ADE0: .4byte 0x01000010

	thumb_func_start func_fe6_0805ADE4
func_fe6_0805ADE4: @ 0x0805ADE4
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

	thumb_func_start func_fe6_0805AE08
func_fe6_0805AE08: @ 0x0805AE08
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

	thumb_func_start func_fe6_0805AE1C
func_fe6_0805AE1C: @ 0x0805AE1C
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

	thumb_func_start func_fe6_0805AE6C
func_fe6_0805AE6C: @ 0x0805AE6C
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
	bl EfxPalWhiteInOut
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

	thumb_func_start func_fe6_0805AEDC
func_fe6_0805AEDC: @ 0x0805AEDC
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
	bl EfxPalWhiteInOut
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

	thumb_func_start func_fe6_0805AF34
func_fe6_0805AF34: @ 0x0805AF34
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
	bl EfxPalWhiteInOut
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

	thumb_func_start func_fe6_0805AFA4
func_fe6_0805AFA4: @ 0x0805AFA4
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

	thumb_func_start func_fe6_0805AFD4
func_fe6_0805AFD4: @ 0x0805AFD4
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

	thumb_func_start func_fe6_0805AFEC
func_fe6_0805AFEC: @ 0x0805AFEC
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
	bl EfxPlaySE
	bl func_fe6_0805BD8C
	adds r0, r4, #0
	bl Proc_Break
.L0805B012:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805B018: .4byte 0x00000145

	thumb_func_start func_fe6_0805B01C
func_fe6_0805B01C: @ 0x0805B01C
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

	thumb_func_start func_fe6_0805B094
func_fe6_0805B094: @ 0x0805B094
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

	thumb_func_start func_fe6_0805B0D4
func_fe6_0805B0D4: @ 0x0805B0D4
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

	thumb_func_start func_fe6_0805B13C
func_fe6_0805B13C: @ 0x0805B13C
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

	thumb_func_start EfxTmCpyBG
EfxTmCpyBG: @ 0x0805B1AC
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
	bl EfxTmCpyExt
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EfxTmCpyBgHFlip
EfxTmCpyBgHFlip: @ 0x0805B1DC
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
	bl EfxTmCpyExtHFlip
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EfxTmCpyExt
EfxTmCpyExt: @ 0x0805B20C
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

	thumb_func_start EfxTmCpyExtHFlip
EfxTmCpyExtHFlip: @ 0x0805B2BC
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

	thumb_func_start func_fe6_0805B380
func_fe6_0805B380: @ 0x0805B380
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

	thumb_func_start EkrModifyBarfx
EkrModifyBarfx: @ 0x0805B458
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

	thumb_func_start func_fe6_0805B4D8
func_fe6_0805B4D8: @ 0x0805B4D8
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

	thumb_func_start EfxPalBlackInOut
EfxPalBlackInOut: @ 0x0805B5C8
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

	thumb_func_start EfxPalWhiteInOut
EfxPalWhiteInOut: @ 0x0805B644
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

	thumb_func_start EfxPalGrayInOut
EfxPalGrayInOut: @ 0x0805B6C8
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

	thumb_func_start func_fe6_0805B780
func_fe6_0805B780: @ 0x0805B780
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

	thumb_func_start func_fe6_0805B7F4
func_fe6_0805B7F4: @ 0x0805B7F4
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

	thumb_func_start func_fe6_0805B834
func_fe6_0805B834: @ 0x0805B834
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

	thumb_func_start func_fe6_0805B88C
func_fe6_0805B88C: @ 0x0805B88C
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

	thumb_func_start func_fe6_0805B90C
func_fe6_0805B90C: @ 0x0805B90C
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

	thumb_func_start func_fe6_0805B9A4
func_fe6_0805B9A4: @ 0x0805B9A4
	push {r4, lr}
	adds r4, r0, #0
	bl ApplyChapterMapPalettes
	ldr r0, .L0805B9C4 @ =gPal
	movs r1, #6
	movs r2, #0xa
	adds r3, r4, #0
	bl EfxPalBlackInOut
	bl EnablePalSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805B9C4: .4byte gPal

	thumb_func_start func_fe6_0805B9C8
func_fe6_0805B9C8: @ 0x0805B9C8
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

	thumb_func_start func_fe6_0805B9E0
func_fe6_0805B9E0: @ 0x0805B9E0
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

	thumb_func_start func_fe6_0805BA2C
func_fe6_0805BA2C: @ 0x0805BA2C
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

	thumb_func_start func_fe6_0805BAEC
func_fe6_0805BAEC: @ 0x0805BAEC
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

	thumb_func_start func_fe6_0805BB08
func_fe6_0805BB08: @ 0x0805BB08
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

	thumb_func_start func_fe6_0805BB24
func_fe6_0805BB24: @ 0x0805BB24
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
	bl func_fe6_0805BAEC
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
	bl func_fe6_0805BB08
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

	thumb_func_start EfxPlaySE
EfxPlaySE: @ 0x0805BCA8
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
	bl func_fe6_0805BDB4
	cmp r0, #0
	bne .L0805BCEC
	bl func_fe6_0805BDA8
	adds r0, r5, #0
	bl func_fe6_08002F9C
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

	thumb_func_start func_fe6_0805BD04
func_fe6_0805BD04: @ 0x0805BD04
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
	bl func_fe6_0805BDB4
	cmp r0, #0
	bne .L0805BD4A
	bl func_fe6_0805BDA8
	ldr r0, [r4, #0x44]
	bl func_fe6_08002F9C
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

	thumb_func_start DoM4aSongNumStop
DoM4aSongNumStop: @ 0x0805BD54
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStop
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805BD64
func_fe6_0805BD64: @ 0x0805BD64
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

	thumb_func_start func_fe6_0805BD8C
func_fe6_0805BD8C: @ 0x0805BD8C
	push {lr}
	ldr r0, .L0805BD98 @ =gMusicPlayer_FightBgm
	bl m4aMPlayStop
	pop {r0}
	bx r0
	.align 2, 0
.L0805BD98: .4byte gMusicPlayer_FightBgm

	thumb_func_start UnregisterEfxSoundSeExist
UnregisterEfxSoundSeExist: @ 0x0805BD9C
	ldr r1, .L0805BDA4 @ =gUnk_Banim_0201F050
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
.L0805BDA4: .4byte gUnk_Banim_0201F050

	thumb_func_start func_fe6_0805BDA8
func_fe6_0805BDA8: @ 0x0805BDA8
	ldr r1, .L0805BDB0 @ =gUnk_Banim_0201F050
	movs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L0805BDB0: .4byte gUnk_Banim_0201F050

	thumb_func_start func_fe6_0805BDB4
func_fe6_0805BDB4: @ 0x0805BDB4
	ldr r0, .L0805BDBC @ =gUnk_Banim_0201F050
	ldr r0, [r0]
	bx lr
	.align 2, 0
.L0805BDBC: .4byte gUnk_Banim_0201F050

	thumb_func_start M4aPlayWithPostionCtrl
M4aPlayWithPostionCtrl: @ 0x0805BDC0
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
	ldr r2, .L0805BE2C @ =gMusicPlayerTable
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
.L0805BE2C: .4byte gMusicPlayerTable
.L0805BE30: .4byte gSongTable
.L0805BE34: .4byte 0x0000FFFF
.L0805BE38:
	ldr r2, .L0805BE70 @ =gMusicPlayerTable
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
.L0805BE70: .4byte gMusicPlayerTable
.L0805BE74: .4byte gSongTable
.L0805BE78: .4byte 0x0000FFFF

	thumb_func_start EfxPlaySEwithCmdCtrl
EfxPlaySEwithCmdCtrl: @ 0x0805BE7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	mov sb, r1
	bl GetAnimAnotherSide
	adds r6, r0, #0
	mov r0, r8
	bl GetAnimLayer
	cmp r0, #1
	bne .L0805BE9C
	b .L0805C190
.L0805BE9C:
	mov r0, r8
	bl GetAnimPosition
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
	bl func_fe6_0805C1A0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r4, #0x14
	bne .L0805BED6
	mov r0, r8
	bl func_fe6_0805C2B0
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
	bl func_fe6_0805C2E0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r4, .L0805BF34 @ =0x0000FFFF
	mov r0, r8
	str r2, [sp]
	bl func_fe6_0805C76C
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
	bl func_fe6_0805C3B8
	adds r0, r6, #0
	bl func_fe6_0805C308
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
	bl func_fe6_0805C3B8
	adds r0, r6, #0
	bl func_fe6_0805C308
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
	bl func_fe6_0805C3B8
	adds r0, r6, #0
	bl func_fe6_0805C308
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
	bl func_fe6_0805C76C
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
	bl EfxPlaySE
	ldr r3, [sp, #4]
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	movs r2, #1
	adds r0, r4, #0
	bl M4aPlayWithPostionCtrl
.L0805C190:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805C1A0
func_fe6_0805C1A0: @ 0x0805C1A0
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl GetBattleAnimArenaFlag
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

	thumb_func_start func_fe6_0805C2B0
func_fe6_0805C2B0: @ 0x0805C2B0
	push {r4, r5, lr}
	adds r4, r0, #0
	bl func_fe6_0805C76C
	movs r2, #2
	ldrsh r1, [r4, r2]
	adds r5, r0, r1
	adds r0, r4, #0
	bl GetAnimPosition
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

	thumb_func_start func_fe6_0805C2E0
func_fe6_0805C2E0: @ 0x0805C2E0
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

	thumb_func_start func_fe6_0805C308
func_fe6_0805C308: @ 0x0805C308
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, .L0805C348 @ =0x0203CD46
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r0, r5, #0
	bl GetAnimPosition
	lsls r1, r6, #1
	adds r6, r1, r0
	adds r0, r6, #0
	bl func_fe6_0804A5A8
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r6, #2
	bl func_fe6_0804A5A8
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

	thumb_func_start func_fe6_0805C358
func_fe6_0805C358: @ 0x0805C358
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0805C37C @ =0x0000FFFF
	bl func_fe6_0805C3B8
	adds r0, r5, #0
	bl func_fe6_0805C308
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
	bl EfxPlaySE
	movs r0, #2
	ldrsh r1, [r5, r0]
	adds r0, r4, #0
	movs r2, #1
	bl M4aPlayWithPostionCtrl
.L0805C3B2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805C3B8
func_fe6_0805C3B8: @ 0x0805C3B8
	push {r4, r5, lr}
	adds r4, r0, #0
	bl GetAnimAnotherSide
	adds r5, r0, #0
	adds r0, r4, #0
	bl func_fe6_0805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt .L0805C3F4
	cmp r0, #0
	blt .L0805C3F4
	adds r0, r5, #0
	bl func_fe6_0804B7B0
	cmp r0, #1
	bne .L0805C3F4
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xd8
	bl EfxPlaySE
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r0, #0xd8
	movs r2, #1
	bl M4aPlayWithPostionCtrl
.L0805C3F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805C3FC
func_fe6_0805C3FC: @ 0x0805C3FC
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

	thumb_func_start func_fe6_0805C41C
func_fe6_0805C41C: @ 0x0805C41C
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

	thumb_func_start EkrPlayMainBGM
EkrPlayMainBGM: @ 0x0805C520
	push {r4, r5, r6, lr}
	ldr r0, .L0805C570 @ =gpEkrBattleUnitLeft
	ldr r1, .L0805C574 @ =gpEkrBattleUnitRight
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
	ldr r0, .L0805C584 @ =gEkrInitialHitSide
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
	bl GetBattleAnimArenaFlag
	cmp r0, #1
	beq .L0805C564
	bl GetBanimLinkArenaFlag
	cmp r0, #1
	bne .L0805C588
.L0805C564:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x3a
	bl func_fe6_0805BD64
	b .L0805C72E
	.align 2, 0
.L0805C570: .4byte gpEkrBattleUnitLeft
.L0805C574: .4byte gpEkrBattleUnitRight
.L0805C578: .4byte gBmSt
.L0805C57C: .4byte gUnk_Banim_0201F04C
.L0805C580: .4byte 0x0203CD08
.L0805C584: .4byte gEkrInitialHitSide
.L0805C588:
	ldr r0, .L0805C59C @ =gEkrDistanceType
	ldrh r0, [r0]
	cmp r0, #4
	bne .L0805C5A0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x1c
	bl func_fe6_0805BD64
	b .L0805C72E
	.align 2, 0
.L0805C59C: .4byte gEkrDistanceType
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
	bl func_fe6_0805BD64
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
	bl func_fe6_0805BD64
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
	bl func_fe6_0805BD64
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
	bl func_fe6_0805BD64
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
	bl func_fe6_0805BD64
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
	bl func_fe6_0805BD64
	b .L0805C72E
	.align 2, 0
.L0805C694: .4byte gBattleSt
.L0805C698:
	cmp r2, #2
	bne .L0805C6A8
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x41
	bl func_fe6_0805BD64
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
	bl func_fe6_0805BD64
	b .L0805C72E
	.align 2, 0
.L0805C6D0: .4byte gBattleSt
.L0805C6D4:
	movs r0, #0
	bl func_fe6_0805C3FC
	cmp r0, #1
	bne .L0805C6E8
	ldr r0, .L0805C6E4 @ =gBattleUnitA
	b .L0805C6F4
	.align 2, 0
.L0805C6E4: .4byte gBattleUnitA
.L0805C6E8:
	movs r0, #1
	bl func_fe6_0805C3FC
	cmp r0, #1
	bne .L0805C704
	ldr r0, .L0805C700 @ =gBattleUnitB
.L0805C6F4:
	adds r0, #0x4a
	ldrh r0, [r0]
	bl func_fe6_0805C41C
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
	bl func_fe6_0805BD64
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

	thumb_func_start EkrRestoreBGM
EkrRestoreBGM: @ 0x0805C738
	push {lr}
	bl func_fe6_08058F38
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

	thumb_func_start func_fe6_0805C76C
func_fe6_0805C76C: @ 0x0805C76C
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
	bl func_fe6_0805BAEC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r5, r0
	ldr r0, [r6]
	bl func_fe6_0805BAEC
	adds r4, r0, #0
	ldr r0, [r6]
	bl func_fe6_0805BB08
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

	thumb_func_start func_fe6_0805C804
func_fe6_0805C804: @ 0x0805C804
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	adds r6, r3, #0
	bl EfxPlaySE
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl M4aPlayWithPostionCtrl
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805C820
func_fe6_0805C820: @ 0x0805C820
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r2, #0
	bl EfxPlaySE
	adds r0, r4, #0
	bl func_fe6_0805C76C
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #1
	bl M4aPlayWithPostionCtrl
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start EkrClasschgFinished
EkrClasschgFinished: @ 0x0805C840
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

	thumb_func_start EndEkrClasschg
EndEkrClasschg: @ 0x0805C858
	push {lr}
	ldr r0, .L0805C868 @ =gUnk_Banim_0201F054
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L0805C868: .4byte gUnk_Banim_0201F054

	thumb_func_start NewEkrClassChg
NewEkrClassChg: @ 0x0805C86C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl func_fe6_08047300
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

	thumb_func_start func_fe6_0805C89C
func_fe6_0805C89C: @ 0x0805C89C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
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
	bl DisableEfxStatusUnits
	adds r0, r5, #0
	bl DisableEfxStatusUnits
	adds r0, r5, #0
	bl func_fe6_0805CB6C
	adds r0, r5, #0
	bl func_fe6_0805CC64
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
	bl func_fe6_08046794
	ldr r0, .L0805C924 @ =0x0000013B
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
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
	bl func_fe6_0805CFC0
	b .L0805CB56
.L0805C95C:
	cmp r1, #0x78
	bne .L0805C968
	ldr r0, [r4, #0x5c]
	bl func_fe6_0805CD68
	b .L0805CB56
.L0805C968:
	cmp r1, #0x80
	bne .L0805C974
	movs r0, #1
	bl SetAnimStateHidden
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
	bl func_fe6_0804C8D4
	adds r2, r0, #0
	ldr r0, [r4, #0x5c]
	movs r1, #0x40
	str r1, [sp]
	adds r1, r2, #0
	movs r2, #0x38
	movs r3, #0
	bl func_fe6_0805D09C
	ldr r0, [r4, #0x5c]
	ldr r2, .L0805C9B8 @ =func_fe6_0804CD4C
	movs r1, #0x38
	bl func_fe6_0804CC68
	ldr r0, [r4, #0x5c]
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r1, #0
	movs r2, #0x38
	movs r3, #0x10
	bl func_fe6_0804CD88
	b .L0805CB56
	.align 2, 0
.L0805C9B8: .4byte func_fe6_0804CD4C
.L0805C9BC:
	cmp r1, #0xf2
	bne .L0805CA58
	ldr r0, [r4, #0x5c]
	bl func_fe6_0805CBB0
	ldr r0, [r4, #0x5c]
	bl func_fe6_0805CCE8
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
	bl func_fe6_0804C8D4
	adds r2, r0, #0
	ldr r0, [r4, #0x5c]
	mov r3, r8
	str r3, [sp]
	adds r1, r2, #0
	movs r2, #0x38
	movs r3, #0x40
	bl func_fe6_0805D09C
	ldr r0, [r4, #0x5c]
	ldr r2, .L0805CA54 @ =func_fe6_0804CD4C
	movs r1, #0x38
	bl func_fe6_0804CC68
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
	bl func_fe6_0804CD88
	movs r0, #0x9e
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	b .L0805CB36
	.align 2, 0
.L0805CA50: .4byte gDispIo
.L0805CA54: .4byte func_fe6_0804CD4C
.L0805CA58:
	movs r0, #0x9c
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0805CA88
	movs r0, #0
	bl SetAnimStateUnHidden
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
	bl func_fe6_0805CFC0
	b .L0805CB56
	.align 2, 0
.L0805CA84: .4byte 0x0000F3FF
.L0805CA88:
	movs r0, #0x9f
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0805CAAA
	adds r0, r5, #0
	bl func_fe6_0805CD68
	ldr r0, [r4, #0x5c]
	movs r1, #0xa
	bl func_fe6_08046794
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
	bl func_fe6_08047358
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x46
	bl func_fe6_0804685C
	b .L0805CB56
.L0805CAE4:
	movs r0, #0xb2
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0805CB48
	adds r0, r5, #0
	movs r1, #0x82
	bl func_fe6_0805CDCC
	adds r0, r5, #0
	movs r1, #0x82
	bl func_fe6_0805CF38
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x5a
	movs r2, #0x28
	movs r3, #0xe
	bl func_fe6_0804CD88
	movs r4, #0x80
	lsls r4, r4, #1
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0x82
	movs r2, #0xa
	adds r3, r4, #0
	bl func_fe6_0804C8D4
	ldr r2, .L0805CB40 @ =func_fe6_0804CD4C
	adds r0, r5, #0
	movs r1, #0x82
	bl func_fe6_0804CC68
	ldr r0, .L0805CB44 @ =0x0000013D
	movs r3, #2
	ldrsh r2, [r5, r3]
	adds r1, r4, #0
.L0805CB36:
	movs r3, #1
	bl func_fe6_0805C804
	b .L0805CB56
	.align 2, 0
.L0805CB40: .4byte func_fe6_0804CD4C
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

	thumb_func_start func_fe6_0805CB64
func_fe6_0805CB64: @ 0x0805CB64
	adds r0, #0x29
	movs r1, #1
	strb r1, [r0]
	bx lr

	thumb_func_start func_fe6_0805CB6C
func_fe6_0805CB6C: @ 0x0805CB6C
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
	bl func_fe6_08047500
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CB9C: .4byte gUnk_08605FA8
.L0805CBA0: .4byte gUnk_081C9F34
.L0805CBA4: .4byte gUnk_08605FC0
.L0805CBA8: .4byte gUnk_0860601C
.L0805CBAC: .4byte gUnk_08606078

	thumb_func_start func_fe6_0805CBB0
func_fe6_0805CBB0: @ 0x0805CBB0
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
	bl func_fe6_08047500
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CBE0: .4byte gUnk_08605FA8
.L0805CBE4: .4byte gUnk_081C9FA6
.L0805CBE8: .4byte gUnk_08605FC0
.L0805CBEC: .4byte gUnk_0860601C
.L0805CBF0: .4byte gUnk_08606078

	thumb_func_start func_fe6_0805CBF4
func_fe6_0805CBF4: @ 0x0805CBF4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl func_fe6_08047BA4
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
	bl func_fe6_08047ACC
	adds r4, r5, r4
	ldr r0, [r4]
	movs r1, #0x20
	bl func_fe6_08047AF4
	ldr r0, [r7, #0x5c]
	adds r6, r5, r6
	ldr r1, [r6]
	add r5, r8
	ldr r2, [r5]
	bl func_fe6_0804799C
	b .L0805CC58
.L0805CC42:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L0805CC58
	bl SpellFx_ClearBG1
	bl func_fe6_080475D8
	adds r0, r7, #0
	bl Proc_End
.L0805CC58:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805CC64
func_fe6_0805CC64: @ 0x0805CC64
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

	thumb_func_start func_fe6_0805CC80
func_fe6_0805CC80: @ 0x0805CC80
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
	bl func_fe6_0805C804
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

	thumb_func_start func_fe6_0805CCE8
func_fe6_0805CCE8: @ 0x0805CCE8
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

	thumb_func_start func_fe6_0805CD04
func_fe6_0805CD04: @ 0x0805CD04
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
	bl func_fe6_0805C804
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

	thumb_func_start func_fe6_0805CD68
func_fe6_0805CD68: @ 0x0805CD68
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
	bl func_fe6_080478DC
	str r0, [r5, #0x60]
	ldr r0, .L0805CDAC @ =gUnk_0812D80C
	movs r1, #0x20
	bl func_fe6_08047AB0
	ldr r0, .L0805CDB0 @ =gUnk_0812D374
	movs r1, #0x80
	lsls r1, r1, #5
	bl func_fe6_08047A88
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CDA4: .4byte gUnk_08606104
.L0805CDA8: .4byte gUnk_085E5858
.L0805CDAC: .4byte gUnk_0812D80C
.L0805CDB0: .4byte gUnk_0812D374

	thumb_func_start func_fe6_0805CDB4
func_fe6_0805CDB4: @ 0x0805CDB4
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

	thumb_func_start func_fe6_0805CDCC
func_fe6_0805CDCC: @ 0x0805CDCC
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
	bl func_fe6_08047AF4
	ldr r0, .L0805CEC4 @ =gUnk_081B4E9C
	movs r1, #0x80
	lsls r1, r1, #6
	bl func_fe6_08047ACC
	ldr r0, .L0805CEC8 @ =gUnk_081B4F9C
	ldr r1, .L0805CECC @ =gBg1Tm
	movs r2, #1
	str r2, [sp]
	adds r2, #0xff
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x20
	bl EfxTmCpyBG
	movs r0, #2
	bl EnableBgSync
	bl func_fe6_08047500
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

	thumb_func_start func_fe6_0805CEE0
func_fe6_0805CEE0: @ 0x0805CEE0
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
	bl SpellFx_ClearBG1
	bl func_fe6_080475D8
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

	thumb_func_start func_fe6_0805CF38
func_fe6_0805CF38: @ 0x0805CF38
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

	thumb_func_start func_fe6_0805CF58
func_fe6_0805CF58: @ 0x0805CF58
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

	thumb_func_start func_fe6_0805CFBC
func_fe6_0805CFBC: @ 0x0805CFBC
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0805CFC0
func_fe6_0805CFC0: @ 0x0805CFC0
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

	thumb_func_start func_fe6_0805CFF8
func_fe6_0805CFF8: @ 0x0805CFF8
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
	bl GetAnimPosition
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
	bl EfxPalBlackInOut
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
	bl EfxPalBlackInOut
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

	thumb_func_start func_fe6_0805D09C
func_fe6_0805D09C: @ 0x0805D09C
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

	thumb_func_start func_fe6_0805D0E0
func_fe6_0805D0E0: @ 0x0805D0E0
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

	thumb_func_start CheckEkrLvupDone
CheckEkrLvupDone: @ 0x0805D128
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

	thumb_func_start EndEkrLevelUp
EndEkrLevelUp: @ 0x0805D140
	push {lr}
	ldr r0, .L0805D150 @ =gUnk_Banim_0201F058
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L0805D150: .4byte gUnk_Banim_0201F058

	thumb_func_start func_fe6_0805D154
func_fe6_0805D154: @ 0x0805D154
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r2, r0, #0
	ldr r0, [r2, #0x5c]
	cmp r0, #0
	bne .L0805D17C
	ldr r0, .L0805D170 @ =gpEkrBattleUnitLeft
	ldr r4, [r0]
	ldr r0, .L0805D174 @ =gUnk_Banim_0201F0AC
	adds r6, r4, #0
	str r6, [r0]
	ldr r0, .L0805D178 @ =gpEkrBattleUnitRight
	b .L0805D188
	.align 2, 0
.L0805D170: .4byte gpEkrBattleUnitLeft
.L0805D174: .4byte gUnk_Banim_0201F0AC
.L0805D178: .4byte gpEkrBattleUnitRight
.L0805D17C:
	ldr r0, .L0805D298 @ =gpEkrBattleUnitRight
	ldr r4, [r0]
	ldr r0, .L0805D29C @ =gUnk_Banim_0201F0AC
	adds r6, r4, #0
	str r6, [r0]
	ldr r0, .L0805D2A0 @ =gpEkrBattleUnitLeft
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
.L0805D298: .4byte gpEkrBattleUnitRight
.L0805D29C: .4byte gUnk_Banim_0201F0AC
.L0805D2A0: .4byte gpEkrBattleUnitLeft
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

	thumb_func_start func_fe6_0805D4E0
func_fe6_0805D4E0: @ 0x0805D4E0
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

	thumb_func_start func_fe6_0805D538
func_fe6_0805D538: @ 0x0805D538
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

	thumb_func_start func_fe6_0805D570
func_fe6_0805D570: @ 0x0805D570
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

	thumb_func_start NewEkrLevelup
NewEkrLevelup: @ 0x0805D5B0
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
	bl GetAnimAnotherSide
	str r0, [r6, #0x60]
	movs r1, #0
	movs r0, #0
	strh r0, [r6, #0x2c]
	adds r0, r6, #0
	adds r0, #0x29
	strb r1, [r0]
	ldr r0, .L0805D5F0 @ =gEkrDistanceType
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
.L0805D5F0: .4byte gEkrDistanceType
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

	thumb_func_start func_fe6_0805D604
func_fe6_0805D604: @ 0x0805D604
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
	ldr r0, .L0805D6D8 @ =gEkrDistanceType
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
	ldr r0, .L0805D6E8 @ =gEkrSnowWeather
	ldrh r0, [r0]
	strh r0, [r7, #0x10]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #2
	bne .L0805D6F6
	ldr r0, .L0805D6EC @ =gEkrInitPosReal
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
.L0805D6D8: .4byte gEkrDistanceType
.L0805D6DC: .4byte 0x0000FFFF
.L0805D6E0: .4byte 0x06010000
.L0805D6E4: .4byte gUnk_Banim_020145C0
.L0805D6E8: .4byte gEkrSnowWeather
.L0805D6EC: .4byte gEkrInitPosReal
.L0805D6F0:
	adds r0, r4, #0
	orrs r0, r2
	strh r0, [r7]
.L0805D6F6:
	bl GetBattleAnimArenaFlag
	cmp r0, #0
	bne .L0805D71E
	adds r0, r7, #0
	bl func_fe6_0804BF40
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
	bl GetEkrDragonJid
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
	bl func_fe6_0805E230
	ldr r1, .L0805D8AC @ =gUnk_Banim_0201F07C
	str r0, [r1]
	bl func_fe6_0805E370
	ldr r1, .L0805D8B0 @ =gUnk_Banim_0201F080
	str r0, [r1]
	bl func_fe6_0805E248
	movs r0, #2
	bl EkrGauge_08043908
	mov r3, sb
	ldr r0, [r3, #0x5c]
	bl DisableEfxStatusUnits
	mov r1, sb
	ldr r0, [r1, #0x60]
	bl DisableEfxStatusUnits
	bl func_fe6_08047248
	bl func_fe6_08046B5C
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

	thumb_func_start func_fe6_0805D8B4
func_fe6_0805D8B4: @ 0x0805D8B4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, .L0805D95C @ =gpEkrBattleUnitLeft
	ldr r0, [r0]
	mov sb, r0
	ldr r0, .L0805D960 @ =gpEkrBattleUnitRight
	ldr r0, [r0]
	mov r8, r0
	ldr r7, [r6, #0x5c]
	ldr r0, .L0805D964 @ =Img_LevelUpFrame
	ldr r5, .L0805D968 @ =gUnk_Banim_0201777C
	adds r1, r5, #0
	bl LZ77UnCompWram
	ldr r0, .L0805D96C @ =Tm_LevelUpFrame
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
	bl EfxTmCpyBG
	ldr r1, .L0805D978 @ =0x06002000
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r5, #0
	bl RegisterDataMove
	ldr r0, .L0805D97C @ =Pal_LevelUpFrame
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
	bl func_fe6_0805E140
	movs r1, #0x85
	lsls r1, r1, #5
	str r1, [r0, #0x4c]
	strh r4, [r6, #0x2c]
	b .L0805D99C
	.align 2, 0
.L0805D95C: .4byte gpEkrBattleUnitLeft
.L0805D960: .4byte gpEkrBattleUnitRight
.L0805D964: .4byte Img_LevelUpFrame
.L0805D968: .4byte gUnk_Banim_0201777C
.L0805D96C: .4byte Tm_LevelUpFrame
.L0805D970: .4byte gUnk_Banim_0201977C
.L0805D974: .4byte gBg1Tm+0x180
.L0805D978: .4byte 0x06002000
.L0805D97C: .4byte Pal_LevelUpFrame
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
	bl GetAnimPosition
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
	bl func_fe6_0805D154
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

	thumb_func_start func_fe6_0805DA08
func_fe6_0805DA08: @ 0x0805DA08
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805DA34 @ =func_fe6_0805E4D4
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
.L0805DA34: .4byte func_fe6_0805E4D4

	thumb_func_start func_fe6_0805DA38
func_fe6_0805DA38: @ 0x0805DA38
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

	thumb_func_start func_fe6_0805DA7C
func_fe6_0805DA7C: @ 0x0805DA7C
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
	bl EfxPalBlackInOut
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0xc
	mov r3, sl
	bl EfxPalBlackInOut
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

	thumb_func_start func_fe6_0805DBA4
func_fe6_0805DBA4: @ 0x0805DBA4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xa0
	movs r1, #1
	movs r2, #1
	movs r3, #3
	bl StartManimLevelUpStatGainLabels
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

	thumb_func_start func_fe6_0805DBD4
func_fe6_0805DBD4: @ 0x0805DBD4
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
	ldr r0, .L0805DC24 @ =func_fe6_0805E510
	bl SetOnHBlankA
	ldr r4, .L0805DC28 @ =gUnk_Banim_0201F07C
	ldr r0, [r4]
	bl Proc_End
	bl func_fe6_0805E2CC
	str r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x76
	bl EfxPlaySE
	movs r0, #0x76
	movs r1, #0x38
	movs r2, #0
	bl M4aPlayWithPostionCtrl
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
.L0805DC24: .4byte func_fe6_0805E510
.L0805DC28: .4byte gUnk_Banim_0201F07C

	thumb_func_start func_fe6_0805DC2C
func_fe6_0805DC2C: @ 0x0805DC2C
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
	bl func_fe6_0805D538
	ldr r1, .L0805DCAC @ =gUnk_Banim_0201F0B4
	ldr r0, .L0805DCB0 @ =gUnk_Banim_0201F0B6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r5, #0
	bl func_fe6_0805D570
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

	thumb_func_start func_fe6_0805DCB4
func_fe6_0805DCB4: @ 0x0805DCB4
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

	thumb_func_start func_fe6_0805DD08
func_fe6_0805DD08: @ 0x0805DD08
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
	bl StartManimLevelUpStatGainLabelAnim
	ldr r1, .L0805DD4C @ =gUnk_Banim_0201F0B4
	ldr r0, .L0805DD50 @ =gUnk_Banim_0201F0B6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r5, #0
	bl func_fe6_0805D570
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x76
	bl EfxPlaySE
	movs r0, #0x76
	movs r1, #0x38
	movs r2, #0
	bl M4aPlayWithPostionCtrl
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
	bl func_fe6_0805E230
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

	thumb_func_start func_fe6_0805DD78
func_fe6_0805DD78: @ 0x0805DD78
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

	thumb_func_start func_fe6_0805DDA8
func_fe6_0805DDA8: @ 0x0805DDA8
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
	bl func_fe6_0805D4E0
	movs r0, #0x76
	movs r1, #0x80
	lsls r1, r1, #1
	bl EfxPlaySE
	movs r0, #0x76
	movs r1, #0x38
	movs r2, #0
	bl M4aPlayWithPostionCtrl
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
	bl StartManimLevelUpStatGainLabelAnim
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
.L0805DE50: .4byte gUnk_Banim_0201F0C8
.L0805DE54: .4byte gUnk_081CA03C
.L0805DE58: .4byte 0x0203CDA4
.L0805DE5C: .4byte 0x0203CDA8
.L0805DE60: .4byte 0x0000FFFF
.L0805DE64:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	bne .L0805DDCA
.L0805DE72:
	ldrh r0, [r4, #0x2e]
	cmp r0, #8
	bne .L0805DE82
.L0805DE78:
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L0805DE82:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805DE8C
func_fe6_0805DE8C: @ 0x0805DE8C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3b
	ble .L0805DEB2
	movs r0, #0
	strh r0, [r4, #0x2c]
	bl EndManimLevelUpStatGainLabels
	ldr r0, .L0805DEB8 @ =func_fe6_0805E4D4
	bl SetOnHBlankA
	adds r0, r4, #0
	bl Proc_Break
.L0805DEB2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805DEB8: .4byte func_fe6_0805E4D4

	thumb_func_start func_fe6_0805DEBC
func_fe6_0805DEBC: @ 0x0805DEBC
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805DEC8
func_fe6_0805DEC8: @ 0x0805DEC8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r5, .L0805DF7C @ =gUnk_Banim_0201F0D8
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	movs r4, #8
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x90
	bl Interpolate
	strh r0, [r5]
	ldr r5, .L0805DF80 @ =gUnk_Banim_0201F0DA
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x90
	bl Interpolate
	strh r0, [r5]
	movs r2, #0x50
	rsbs r2, r2, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl Interpolate
	adds r5, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #8
	movs r2, #0
	bl Interpolate
	adds r6, r0, #0
	ldr r0, .L0805DF84 @ =gFaces
	ldr r1, [r0]
	movs r0, #0x50
	subs r0, r0, r5
	strh r0, [r1, #0x30]
	ldr r0, .L0805DF88 @ =gUnk_Banim_020165C0
	ldr r4, .L0805DF8C @ =gPal
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r4, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #2
	movs r2, #4
	adds r3, r6, #0
	bl EfxPalBlackInOut
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0xc
	adds r3, r6, #0
	bl EfxPalBlackInOut
	bl EnablePalSync
	movs r0, #7
.L0805DF54:
	subs r0, #1
	cmp r0, #0
	bge .L0805DF54
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble .L0805DF72
	movs r0, #0
	strh r0, [r7, #0x2c]
	adds r0, r7, #0
	bl Proc_Break
.L0805DF72:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805DF7C: .4byte gUnk_Banim_0201F0D8
.L0805DF80: .4byte gUnk_Banim_0201F0DA
.L0805DF84: .4byte gFaces
.L0805DF88: .4byte gUnk_Banim_020165C0
.L0805DF8C: .4byte gPal

	thumb_func_start func_fe6_0805DF90
func_fe6_0805DF90: @ 0x0805DF90
	push {r4, r5, r6, lr}
	sub sp, #0x2c
	adds r5, r0, #0
	ldr r4, .L0805E09C @ =gUnk_Banim_0201F084
	bl GetBattleAnimArenaFlag
	cmp r0, #0
	bne .L0805DFA6
	adds r0, r4, #0
	bl func_fe6_0804C2EC
.L0805DFA6:
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
	movs r0, #1
	movs r1, #0
	bl SetBgScreenSize
	movs r0, #2
	movs r1, #0
	bl SetBgScreenSize
	mov r4, sp
	ldr r2, .L0805E0A0 @ =0x0203CD10
	ldrh r0, [r2]
	movs r6, #0
	strh r0, [r4]
	movs r0, #4
	strh r0, [r4, #2]
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r4, #4]
	ldrh r0, [r2, #2]
	strh r0, [r4, #6]
	movs r0, #5
	strh r0, [r4, #8]
	strh r1, [r4, #0xa]
	ldr r0, .L0805E0A4 @ =gEkrDistanceType
	ldrh r0, [r0]
	strh r0, [r4, #0xc]
	movs r0, #2
	strh r0, [r4, #0xe]
	str r6, [sp, #0x1c]
	ldr r0, .L0805E0A8 @ =gUnk_Banim_020145C0
	str r0, [sp, #0x20]
	ldr r0, .L0805E0AC @ =gEkrSnowWeather
	ldrh r0, [r0]
	strh r0, [r4, #0x10]
	bl GetBattleAnimArenaFlag
	cmp r0, #0
	bne .L0805E020
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	mov r0, sp
	bl func_fe6_0804BF40
.L0805E020:
	ldr r2, [r5, #0x5c]
	ldr r1, .L0805E0B0 @ =0x0000F3FF
	adds r0, r1, #0
	ldrh r3, [r2, #8]
	ands r0, r3
	strh r0, [r2, #8]
	ldr r3, [r5, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #4
	adds r2, r0, #0
	ldrh r0, [r3, #8]
	orrs r0, r2
	strh r0, [r3, #8]
	ldr r0, [r5, #0x60]
	ldrh r3, [r0, #8]
	ands r1, r3
	strh r1, [r0, #8]
	ldr r0, [r5, #0x60]
	ldrh r1, [r0, #8]
	orrs r2, r1
	strh r2, [r0, #8]
	str r6, [sp, #0x28]
	add r0, sp, #0x28
	ldr r1, .L0805E0B4 @ =gBg1Tm
	ldr r2, .L0805E0B8 @ =0x01000200
	bl CpuFastSet
	movs r0, #2
	bl EnableBgSync
	movs r0, #0
	bl EkrGauge_08043908
	movs r0, #0
	bl GetEkrDragonJid
	ldrh r0, [r0]
	cmp r0, #0x53
	bne .L0805E0C0
	ldr r3, .L0805E0BC @ =gDispIo
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
	b .L0805E0EC
	.align 2, 0
.L0805E09C: .4byte gUnk_Banim_0201F084
.L0805E0A0: .4byte 0x0203CD10
.L0805E0A4: .4byte gEkrDistanceType
.L0805E0A8: .4byte gUnk_Banim_020145C0
.L0805E0AC: .4byte gEkrSnowWeather
.L0805E0B0: .4byte 0x0000F3FF
.L0805E0B4: .4byte gBg1Tm
.L0805E0B8: .4byte 0x01000200
.L0805E0BC: .4byte gDispIo
.L0805E0C0:
	ldr r3, .L0805E100 @ =gDispIo
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
.L0805E0EC:
	movs r0, #0
	bl EndFaceById
	adds r0, r5, #0
	bl Proc_Break
	add sp, #0x2c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E100: .4byte gDispIo

	thumb_func_start func_fe6_0805E104
func_fe6_0805E104: @ 0x0805E104
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805E138 @ =gUnk_Banim_0201F07C
	ldr r0, [r0]
	bl Proc_End
	ldr r0, .L0805E13C @ =gUnk_Banim_0201F080
	ldr r0, [r0]
	bl Proc_End
	ldr r0, [r4, #0x5c]
	bl func_fe6_08046EF8
	ldr r0, [r4, #0x60]
	bl func_fe6_08046EF8
	bl func_fe6_08047258
	bl func_fe6_08046B6C
	adds r4, #0x29
	movs r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E138: .4byte gUnk_Banim_0201F07C
.L0805E13C: .4byte gUnk_Banim_0201F080

	thumb_func_start func_fe6_0805E140
func_fe6_0805E140: @ 0x0805E140
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r0, .L0805E17C @ =gUnk_08606254
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	adds r2, r0, #0
	adds r2, #0x29
	strb r4, [r2]
	strh r5, [r0, #0x32]
	strh r6, [r0, #0x3a]
	strh r1, [r0, #0x34]
	strh r1, [r0, #0x3c]
	mov r2, r8
	str r2, [r0, #0x44]
	str r1, [r0, #0x4c]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L0805E17C: .4byte gUnk_08606254

	thumb_func_start func_fe6_0805E180
func_fe6_0805E180: @ 0x0805E180
	push {r4, r5, lr}
	sub sp, #0x48
	adds r3, r0, #0
	ldr r1, [r3, #0x44]
	movs r2, #0x2c
	ldrsh r0, [r3, r2]
	cmp r0, #0
	bne .L0805E1F8
	movs r4, #0x2e
	ldrsh r0, [r3, r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #0x3f
	ldrb r0, [r0, #3]
	ands r1, r0
	cmp r1, #0
	bne .L0805E1D6
	adds r0, r3, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0805E1C6
	cmp r0, #1
	bgt .L0805E1B8
	cmp r0, #0
	beq .L0805E1BE
	b .L0805E1F8
.L0805E1B8:
	cmp r0, #2
	beq .L0805E1CC
	b .L0805E1F8
.L0805E1BE:
	adds r0, r3, #0
	bl Proc_Break
	b .L0805E224
.L0805E1C6:
	strh r0, [r3, #0x2c]
	strh r1, [r3, #0x2e]
	b .L0805E1F8
.L0805E1CC:
	movs r0, #1
	strh r0, [r3, #0x2c]
	ldrh r0, [r3, #0x2e]
	subs r0, #1
	b .L0805E1F6
.L0805E1D6:
	cmp r1, #4
	bne .L0805E1DE
	strh r2, [r3, #0x2c]
	b .L0805E1F2
.L0805E1DE:
	ldr r0, .L0805E22C @ =0x0FFFFFFC
	ands r0, r2
	str r0, [r3, #0x48]
	lsrs r0, r2, #0x1a
	movs r1, #0x1c
	ands r0, r1
	movs r1, #3
	ands r2, r1
	adds r0, r0, r2
	strh r0, [r3, #0x2c]
.L0805E1F2:
	ldrh r0, [r3, #0x2e]
	adds r0, #1
.L0805E1F6:
	strh r0, [r3, #0x2e]
.L0805E1F8:
	ldrh r0, [r3, #0x2c]
	subs r0, #1
	movs r2, #0
	strh r0, [r3, #0x2c]
	str r2, [sp, #0x1c]
	ldr r0, [r3, #0x48]
	str r0, [sp, #0x3c]
	mov r1, sp
	ldr r0, [r3, #0x4c]
	strh r0, [r1, #8]
	ldrh r5, [r3, #0x32]
	ldrh r4, [r3, #0x34]
	adds r0, r5, r4
	strh r0, [r1, #2]
	ldrh r5, [r3, #0x3a]
	ldrh r4, [r3, #0x3c]
	adds r0, r5, r4
	strh r0, [r1, #4]
	mov r0, sp
	strh r2, [r0, #0xc]
	bl BasPutOam
.L0805E224:
	add sp, #0x48
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E22C: .4byte 0x0FFFFFFC

	thumb_func_start func_fe6_0805E230
func_fe6_0805E230: @ 0x0805E230
	push {lr}
	ldr r0, .L0805E244 @ =gUnk_0860626C
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	pop {r1}
	bx r1
	.align 2, 0
.L0805E244: .4byte gUnk_0860626C

	thumb_func_start func_fe6_0805E248
func_fe6_0805E248: @ 0x0805E248
	push {r4, r5, r6, lr}
	ldr r0, .L0805E274 @ =gUnk_Banim_0201E3D8
	ldr r0, [r0]
	ldr r2, .L0805E278 @ =gUnk_Banim_0201E158
	cmp r0, #0
	bne .L0805E256
	ldr r2, .L0805E27C @ =gUnk_Banim_0201E298
.L0805E256:
	ldr r1, .L0805E280 @ =gUnk_Banim_0201E3E4
	cmp r0, #0
	bne .L0805E25E
	ldr r1, .L0805E284 @ =gUnk_Banim_0201E524
.L0805E25E:
	movs r3, #0
	movs r6, #0
	ldr r5, .L0805E288 @ =gUnk_Banim_0201F0D8
	ldr r4, .L0805E28C @ =gUnk_Banim_0201F0DA
.L0805E266:
	cmp r3, #0x27
	bhi .L0805E290
	strh r6, [r2]
	adds r2, #2
	strh r6, [r1]
	b .L0805E2AC
	.align 2, 0
.L0805E274: .4byte gUnk_Banim_0201E3D8
.L0805E278: .4byte gUnk_Banim_0201E158
.L0805E27C: .4byte gUnk_Banim_0201E298
.L0805E280: .4byte gUnk_Banim_0201E3E4
.L0805E284: .4byte gUnk_Banim_0201E524
.L0805E288: .4byte gUnk_Banim_0201F0D8
.L0805E28C: .4byte gUnk_Banim_0201F0DA
.L0805E290:
	cmp r3, #0x47
	bhi .L0805E29E
	ldrh r0, [r5]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r5]
	b .L0805E2AA
.L0805E29E:
	cmp r3, #0x9f
	bhi .L0805E2AE
	ldrh r0, [r4]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r4]
.L0805E2AA:
	strh r0, [r1]
.L0805E2AC:
	adds r1, #2
.L0805E2AE:
	adds r3, #1
	cmp r3, #0x9f
	bls .L0805E266
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805E2BC
func_fe6_0805E2BC: @ 0x0805E2BC
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0805E2C0
func_fe6_0805E2C0: @ 0x0805E2C0
	push {lr}
	bl func_fe6_0805E248
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805E2CC
func_fe6_0805E2CC: @ 0x0805E2CC
	push {lr}
	ldr r0, .L0805E2E0 @ =gUnk_0860628C
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	pop {r1}
	bx r1
	.align 2, 0
.L0805E2E0: .4byte gUnk_0860628C

	thumb_func_start func_fe6_0805E2E4
func_fe6_0805E2E4: @ 0x0805E2E4
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0805E2E8
func_fe6_0805E2E8: @ 0x0805E2E8
	push {r4, r5, r6, lr}
	ldr r0, .L0805E334 @ =gUnk_Banim_0201E3D8
	ldr r0, [r0]
	ldr r3, .L0805E338 @ =gUnk_Banim_0201E158
	cmp r0, #0
	bne .L0805E2F6
	ldr r3, .L0805E33C @ =gUnk_Banim_0201E298
.L0805E2F6:
	ldr r2, .L0805E340 @ =gUnk_Banim_0201E3E4
	cmp r0, #0
	bne .L0805E2FE
	ldr r2, .L0805E344 @ =gUnk_Banim_0201E524
.L0805E2FE:
	movs r4, #0
	movs r5, #0
	ldr r0, .L0805E348 @ =gUnk_086062AC
	adds r6, r0, #0
	subs r6, #0x50
.L0805E308:
	cmp r4, #0x27
	bls .L0805E358
	cmp r4, #0x47
	bhi .L0805E354
	movs r0, #0
	ldrsh r1, [r6, r0]
	ldr r0, .L0805E34C @ =gUnk_Banim_0201F0D8
	ldrh r0, [r0]
	muls r0, r1, r0
	lsls r0, r0, #4
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, r4, r0
	cmp r0, #0x2e
	bls .L0805E32A
	cmp r0, #0x51
	bls .L0805E32C
.L0805E32A:
	ldr r1, .L0805E350 @ =0x0000FFE0
.L0805E32C:
	strh r1, [r3]
	adds r3, #2
	strh r1, [r2]
	b .L0805E35E
	.align 2, 0
.L0805E334: .4byte gUnk_Banim_0201E3D8
.L0805E338: .4byte gUnk_Banim_0201E158
.L0805E33C: .4byte gUnk_Banim_0201E298
.L0805E340: .4byte gUnk_Banim_0201E3E4
.L0805E344: .4byte gUnk_Banim_0201E524
.L0805E348: .4byte gUnk_086062AC
.L0805E34C: .4byte gUnk_Banim_0201F0D8
.L0805E350: .4byte 0x0000FFE0
.L0805E354:
	cmp r4, #0x9f
	bhi .L0805E360
.L0805E358:
	strh r5, [r3]
	adds r3, #2
	strh r5, [r2]
.L0805E35E:
	adds r2, #2
.L0805E360:
	adds r6, #2
	adds r4, #1
	cmp r4, #0x9f
	bls .L0805E308
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805E370
func_fe6_0805E370: @ 0x0805E370
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, .L0805E40C @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r2, .L0805E410 @ =gUnk_Banim_0201E158
	movs r1, #0
	adds r6, r2, #0
	ldr r4, .L0805E414 @ =gUnk_Banim_0201E298
	ldr r0, .L0805E418 @ =gUnk_Banim_0201E3E4
	ldr r5, .L0805E41C @ =gUnk_Banim_0201E524
	ldr r7, .L0805E420 @ =gUnk_Banim_0201E14C
	ldr r3, .L0805E424 @ =gUnk_Banim_0201E3D8
	mov ip, r3
	ldr r3, .L0805E428 @ =gUnk_Banim_0201E150
	mov r8, r3
	ldr r3, .L0805E42C @ =gUnk_Banim_0201E3DC
	mov sb, r3
	ldr r3, .L0805E430 @ =gUnk_Banim_0201E154
	mov sl, r3
	movs r3, #0
.L0805E3A2:
	strh r3, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #0x9f
	bls .L0805E3A2
	adds r2, r4, #0
	movs r1, #0
	movs r3, #0
.L0805E3B2:
	strh r3, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #0x9f
	bls .L0805E3B2
	adds r2, r0, #0
	movs r1, #0
	movs r3, #0
.L0805E3C2:
	strh r3, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #0x9f
	bls .L0805E3C2
	adds r2, r5, #0
	movs r1, #0
	movs r3, #0
.L0805E3D2:
	strh r3, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #0x9f
	bls .L0805E3D2
	movs r4, #0
	str r4, [r7]
	mov r1, ip
	str r4, [r1]
	mov r3, r8
	str r6, [r3]
	mov r1, sb
	str r0, [r1]
	mov r3, sl
	str r6, [r3]
	ldr r1, .L0805E434 @ =gUnk_Banim_0201E3E0
	str r0, [r1]
	ldr r0, .L0805E438 @ =gUnk_086062EC
	movs r1, #0
	bl SpawnProc
	strh r4, [r0, #0x2c]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L0805E40C: .4byte gUnk_Banim_02017744
.L0805E410: .4byte gUnk_Banim_0201E158
.L0805E414: .4byte gUnk_Banim_0201E298
.L0805E418: .4byte gUnk_Banim_0201E3E4
.L0805E41C: .4byte gUnk_Banim_0201E524
.L0805E420: .4byte gUnk_Banim_0201E14C
.L0805E424: .4byte gUnk_Banim_0201E3D8
.L0805E428: .4byte gUnk_Banim_0201E150
.L0805E42C: .4byte gUnk_Banim_0201E3DC
.L0805E430: .4byte gUnk_Banim_0201E154
.L0805E434: .4byte gUnk_Banim_0201E3E0
.L0805E438: .4byte gUnk_086062EC

	thumb_func_start func_fe6_0805E43C
func_fe6_0805E43C: @ 0x0805E43C
	push {lr}
	movs r0, #0
	bl SetOnHBlankA
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805E448
func_fe6_0805E448: @ 0x0805E448
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805E454
func_fe6_0805E454: @ 0x0805E454
	ldr r1, .L0805E468 @ =gUnk_Banim_0201E14C
	ldr r0, [r1]
	cmp r0, #1
	bne .L0805E474
	movs r0, #0
	str r0, [r1]
	ldr r1, .L0805E46C @ =gUnk_Banim_0201E150
	ldr r0, .L0805E470 @ =gUnk_Banim_0201E158
	b .L0805E47C
	.align 2, 0
.L0805E468: .4byte gUnk_Banim_0201E14C
.L0805E46C: .4byte gUnk_Banim_0201E150
.L0805E470: .4byte gUnk_Banim_0201E158
.L0805E474:
	movs r0, #1
	str r0, [r1]
	ldr r1, .L0805E494 @ =gUnk_Banim_0201E150
	ldr r0, .L0805E498 @ =gUnk_Banim_0201E298
.L0805E47C:
	str r0, [r1]
	adds r3, r1, #0
	ldr r1, .L0805E49C @ =gUnk_Banim_0201E3D8
	ldr r0, [r1]
	cmp r0, #1
	bne .L0805E4A8
	movs r0, #0
	str r0, [r1]
	ldr r1, .L0805E4A0 @ =gUnk_Banim_0201E3DC
	ldr r0, .L0805E4A4 @ =gUnk_Banim_0201E3E4
	b .L0805E4B0
	.align 2, 0
.L0805E494: .4byte gUnk_Banim_0201E150
.L0805E498: .4byte gUnk_Banim_0201E298
.L0805E49C: .4byte gUnk_Banim_0201E3D8
.L0805E4A0: .4byte gUnk_Banim_0201E3DC
.L0805E4A4: .4byte gUnk_Banim_0201E3E4
.L0805E4A8:
	movs r0, #1
	str r0, [r1]
	ldr r1, .L0805E4C4 @ =gUnk_Banim_0201E3DC
	ldr r0, .L0805E4C8 @ =gUnk_Banim_0201E524
.L0805E4B0:
	str r0, [r1]
	adds r2, r1, #0
	ldr r1, .L0805E4CC @ =gUnk_Banim_0201E154
	ldr r0, [r3]
	str r0, [r1]
	ldr r1, .L0805E4D0 @ =gUnk_Banim_0201E3E0
	ldr r0, [r2]
	str r0, [r1]
	bx lr
	.align 2, 0
.L0805E4C4: .4byte gUnk_Banim_0201E3DC
.L0805E4C8: .4byte gUnk_Banim_0201E524
.L0805E4CC: .4byte gUnk_Banim_0201E154
.L0805E4D0: .4byte gUnk_Banim_0201E3E0

	thumb_func_start func_fe6_0805E4D4
func_fe6_0805E4D4: @ 0x0805E4D4
	ldr r0, .L0805E500 @ =0x04000004
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0805E4FC
	ldr r3, .L0805E504 @ =0x04000018
	ldr r2, .L0805E508 @ =gUnk_Banim_0201E154
	ldr r0, [r2]
	ldrh r1, [r0]
	strh r1, [r3]
	adds r0, #2
	str r0, [r2]
	subs r3, #4
	ldr r2, .L0805E50C @ =gUnk_Banim_0201E3E0
	ldr r0, [r2]
	ldrh r1, [r0]
	strh r1, [r3]
	adds r0, #2
	str r0, [r2]
.L0805E4FC:
	bx lr
	.align 2, 0
.L0805E500: .4byte 0x04000004
.L0805E504: .4byte 0x04000018
.L0805E508: .4byte gUnk_Banim_0201E154
.L0805E50C: .4byte gUnk_Banim_0201E3E0

	thumb_func_start func_fe6_0805E510
func_fe6_0805E510: @ 0x0805E510
	push {r4, r5, r6, lr}
	ldr r0, .L0805E54C @ =0x04000004
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0805E544
	ldr r3, .L0805E550 @ =0x0400001A
	ldr r4, .L0805E554 @ =gDispIo
	ldr r2, .L0805E558 @ =gUnk_Banim_0201E154
	ldr r0, [r2]
	ldrh r5, [r4, #0x26]
	ldrh r6, [r0]
	adds r1, r5, r6
	strh r1, [r3]
	adds r0, #2
	str r0, [r2]
	subs r3, #4
	ldr r2, .L0805E55C @ =gUnk_Banim_0201E3E0
	ldr r0, [r2]
	ldrh r4, [r4, #0x22]
	ldrh r5, [r0]
	adds r1, r4, r5
	strh r1, [r3]
	adds r0, #2
	str r0, [r2]
.L0805E544:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E54C: .4byte 0x04000004
.L0805E550: .4byte 0x0400001A
.L0805E554: .4byte gDispIo
.L0805E558: .4byte gUnk_Banim_0201E154
.L0805E55C: .4byte gUnk_Banim_0201E3E0

	thumb_func_start CheckEkrTriangleInvalid
CheckEkrTriangleInvalid: @ 0x0805E560
	ldr r0, .L0805E56C @ =gUnk_Banim_0201F0DC
	ldr r0, [r0]
	cmp r0, #1
	beq .L0805E570
	movs r0, #0
	b .L0805E572
	.align 2, 0
.L0805E56C: .4byte gUnk_Banim_0201F0DC
.L0805E570:
	movs r0, #1
.L0805E572:
	bx lr

	thumb_func_start DebugEkrTriangleMsg
DebugEkrTriangleMsg: @ 0x0805E574
	bx lr
	.align 2, 0

	thumb_func_start NewEkrTriangle
NewEkrTriangle: @ 0x0805E578
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805E594 @ =gUnk_08606314
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	ldr r1, .L0805E598 @ =gUnk_Banim_0201F0DC
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E594: .4byte gUnk_08606314
.L0805E598: .4byte gUnk_Banim_0201F0DC

	thumb_func_start func_fe6_0805E59C
func_fe6_0805E59C: @ 0x0805E59C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0
	mov sb, r0
	mov sl, r0
	mov r8, r0
	movs r7, #0
	ldr r0, [r6, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0805E5C8
	ldr r0, .L0805E5C4 @ =gpEkrBattleUnitLeft
	b .L0805E5CA
	.align 2, 0
.L0805E5C4: .4byte gpEkrBattleUnitLeft
.L0805E5C8:
	ldr r0, .L0805E618 @ =gpEkrBattleUnitRight
.L0805E5CA:
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrb r5, [r0, #4]
	cmp r5, #0xc
	bge .L0805E5D6
	b .L0805E6D8
.L0805E5D6:
	cmp r5, #0xf
	ble .L0805E5DC
	b .L0805E6D8
.L0805E5DC:
	ldr r0, .L0805E61C @ =gpEkrTriangleUnits
	ldr r1, [r0]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0xc
	bne .L0805E5EC
	movs r2, #0
	mov sb, r2
.L0805E5EC:
	cmp r0, #0xd
	bne .L0805E5F4
	movs r2, #0
	mov sb, r2
.L0805E5F4:
	cmp r0, #0xe
	bne .L0805E5FC
	movs r2, #1
	mov sb, r2
.L0805E5FC:
	cmp r0, #0xf
	bne .L0805E604
	movs r0, #1
	mov sb, r0
.L0805E604:
	adds r0, r1, #0
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne .L0805E620
	movs r0, #1
	b .L0805E626
	.align 2, 0
.L0805E618: .4byte gpEkrBattleUnitRight
.L0805E61C: .4byte gpEkrTriangleUnits
.L0805E620:
	adds r0, r4, #0
	bl GetItemKind
.L0805E626:
	cmp r0, #1
	beq .L0805E630
	cmp r0, #2
	beq .L0805E636
	b .L0805E648
.L0805E630:
	movs r1, #0
	mov r8, r1
	b .L0805E648
.L0805E636:
	adds r0, r4, #0
	bl GetItemIid
	movs r2, #1
	mov r8, r2
	cmp r0, #0x20
	bne .L0805E648
	movs r0, #2
	mov r8, r0
.L0805E648:
	ldr r0, .L0805E684 @ =gpEkrTriangleUnits
	ldr r1, [r0, #4]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0xc
	bne .L0805E658
	movs r2, #0
	mov sl, r2
.L0805E658:
	cmp r0, #0xd
	bne .L0805E660
	movs r2, #0
	mov sl, r2
.L0805E660:
	cmp r0, #0xe
	bne .L0805E668
	movs r2, #1
	mov sl, r2
.L0805E668:
	cmp r0, #0xf
	bne .L0805E670
	movs r0, #1
	mov sl, r0
.L0805E670:
	adds r0, r1, #0
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne .L0805E688
	movs r0, #1
	b .L0805E68E
	.align 2, 0
.L0805E684: .4byte gpEkrTriangleUnits
.L0805E688:
	adds r0, r4, #0
	bl GetItemKind
.L0805E68E:
	cmp r0, #1
	beq .L0805E698
	cmp r0, #2
	beq .L0805E69C
	b .L0805E6AA
.L0805E698:
	movs r7, #0
	b .L0805E6AA
.L0805E69C:
	adds r0, r4, #0
	bl GetItemIid
	movs r7, #1
	cmp r0, #0x20
	bne .L0805E6AA
	movs r7, #2
.L0805E6AA:
	ldr r0, [r6, #0x5c]
	str r7, [sp]
	mov r1, sb
	mov r2, sl
	mov r3, r8
	bl func_fe6_0805EA38
	ldr r0, .L0805E6D0 @ =gpEkrBattleUnitRight
	ldr r0, [r0]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	cmp r0, #0x20
	bne .L0805E780
	ldr r1, .L0805E6D4 @ =gUnk_Banim_0201F0DC
	movs r0, #0
	b .L0805E784
	.align 2, 0
.L0805E6D0: .4byte gpEkrBattleUnitRight
.L0805E6D4: .4byte gUnk_Banim_0201F0DC
.L0805E6D8:
	ldr r0, .L0805E704 @ =gpEkrTriangleUnits
	ldr r1, [r0]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x2a
	bne .L0805E6E8
	movs r2, #0
	mov sb, r2
.L0805E6E8:
	cmp r0, #0x2b
	bne .L0805E6F0
	movs r0, #1
	mov sb, r0
.L0805E6F0:
	adds r0, r1, #0
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne .L0805E708
	movs r0, #1
	b .L0805E712
	.align 2, 0
.L0805E704: .4byte gpEkrTriangleUnits
.L0805E708:
	adds r0, r4, #0
	bl GetItemKind
	cmp r0, #0
	beq .L0805E71C
.L0805E712:
	cmp r0, #1
	bne .L0805E720
	movs r1, #0
	mov r8, r1
	b .L0805E720
.L0805E71C:
	movs r2, #1
	mov r8, r2
.L0805E720:
	ldr r0, .L0805E74C @ =gpEkrTriangleUnits
	ldr r1, [r0, #4]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x2a
	bne .L0805E730
	movs r2, #0
	mov sl, r2
.L0805E730:
	cmp r0, #0x2b
	bne .L0805E738
	movs r0, #1
	mov sl, r0
.L0805E738:
	adds r0, r1, #0
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne .L0805E750
	movs r0, #1
	b .L0805E75A
	.align 2, 0
.L0805E74C: .4byte gpEkrTriangleUnits
.L0805E750:
	adds r0, r4, #0
	bl GetItemKind
	cmp r0, #0
	beq .L0805E762
.L0805E75A:
	cmp r0, #1
	bne .L0805E764
	movs r7, #0
	b .L0805E764
.L0805E762:
	movs r7, #1
.L0805E764:
	ldr r0, [r6, #0x5c]
	str r7, [sp]
	mov r1, sb
	mov r2, sl
	mov r3, r8
	bl func_fe6_0805E7A0
	cmp r5, #0x2a
	bne .L0805E780
	ldr r1, .L0805E77C @ =gUnk_Banim_0201F0DC
	movs r0, #0
	b .L0805E784
	.align 2, 0
.L0805E77C: .4byte gUnk_Banim_0201F0DC
.L0805E780:
	ldr r1, .L0805E79C @ =gUnk_Banim_0201F0DC
	movs r0, #1
.L0805E784:
	str r0, [r1]
	adds r0, r6, #0
	bl Proc_Break
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E79C: .4byte gUnk_Banim_0201F0DC

	thumb_func_start func_fe6_0805E7A0
func_fe6_0805E7A0: @ 0x0805E7A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r7, [sp, #0x18]
	ldr r0, .L0805E7D4 @ =gUnk_0860632C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
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
.L0805E7D4: .4byte gUnk_0860632C

	thumb_func_start func_fe6_0805E7D8
func_fe6_0805E7D8: @ 0x0805E7D8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	bne .L0805E7FE
	ldr r0, [r4, #0x5c]
	ldr r2, [r4, #0x44]
	ldr r3, [r4, #0x4c]
	movs r1, #0
	bl func_fe6_0805E964
.L0805E7FE:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x1c
	bne .L0805E80C
	adds r0, r5, #0
	movs r1, #6
	bl func_fe6_08046794
.L0805E80C:
	ldrh r3, [r4, #0x2c]
	cmp r3, #0x22
	bne .L0805E83E
	ldr r2, [r4, #0x44]
	ldr r3, [r4, #0x4c]
	adds r0, r5, #0
	movs r1, #0
	bl func_fe6_0805E890
	ldr r0, [r4, #0x5c]
	ldr r2, [r4, #0x48]
	ldr r3, [r4, #0x50]
	movs r1, #1
	bl func_fe6_0805E964
	movs r0, #0x9a
	lsls r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
.L0805E83E:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x33
	bne .L0805E84C
	adds r0, r5, #0
	movs r1, #6
	bl func_fe6_08046794
.L0805E84C:
	ldrh r3, [r4, #0x2c]
	cmp r3, #0x39
	bne .L0805E872
	ldr r2, [r4, #0x48]
	ldr r3, [r4, #0x50]
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_0805E890
	movs r0, #0x9a
	lsls r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
.L0805E872:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x43
	bne .L0805E884
	ldr r1, .L0805E88C @ =gUnk_Banim_0201F0DC
	movs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0805E884:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E88C: .4byte gUnk_Banim_0201F0DC

	thumb_func_start func_fe6_0805E890
func_fe6_0805E890: @ 0x0805E890
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, .L0805E8B8 @ =gUnk_08606344
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	str r4, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	str r0, [r1, #0x44]
	cmp r5, #0
	bne .L0805E8C4
	ldr r0, .L0805E8BC @ =0x0203CD90
	ldr r2, [r0]
	ldr r0, .L0805E8C0 @ =gUnk_081CA054
	b .L0805E8CA
	.align 2, 0
.L0805E8B8: .4byte gUnk_08606344
.L0805E8BC: .4byte 0x0203CD90
.L0805E8C0: .4byte gUnk_081CA054
.L0805E8C4:
	ldr r0, .L0805E900 @ =0x0203CD90
	ldr r2, [r0, #4]
	ldr r0, .L0805E904 @ =gUnk_081CA062
.L0805E8CA:
	str r0, [r1, #0x48]
	ldr r0, .L0805E908 @ =gUnk_0860635C
	str r0, [r1, #0x4c]
	str r0, [r1, #0x50]
	ldr r4, .L0805E90C @ =gUnk_Banim_0201777C
	adds r0, r2, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	adds r0, r4, #0
	movs r1, #0x20
	bl func_fe6_08047AF4
	ldr r0, .L0805E910 @ =gUnk_081CA070
	cmp r6, #0
	beq .L0805E8F2
	ldr r0, .L0805E914 @ =gUnk_081CB404
	cmp r7, #0
	bne .L0805E8F2
	ldr r0, .L0805E918 @ =gUnk_081CAA14
.L0805E8F2:
	movs r1, #0x80
	lsls r1, r1, #6
	bl func_fe6_08047ACC
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E900: .4byte 0x0203CD90
.L0805E904: .4byte gUnk_081CA062
.L0805E908: .4byte gUnk_0860635C
.L0805E90C: .4byte gUnk_Banim_0201777C
.L0805E910: .4byte gUnk_081CA070
.L0805E914: .4byte gUnk_081CB404
.L0805E918: .4byte gUnk_081CAA14

	thumb_func_start func_fe6_0805E91C
func_fe6_0805E91C: @ 0x0805E91C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl func_fe6_08047BA4
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L0805E94A
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl func_fe6_0804799C
	b .L0805E95C
.L0805E94A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L0805E95C
	bl SpellFx_ClearBG1
	adds r0, r4, #0
	bl Proc_Break
.L0805E95C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805E964
func_fe6_0805E964: @ 0x0805E964
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r0, .L0805E998 @ =gUnk_08606374
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r7, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	cmp r4, #0
	bne .L0805E9A4
	movs r0, #0x12
	strh r0, [r5, #0x2e]
	ldr r0, .L0805E99C @ =0x0203CD90
	ldr r6, [r0]
	ldr r3, .L0805E9A0 @ =gUnk_086068A4
	b .L0805E9AE
	.align 2, 0
.L0805E998: .4byte gUnk_08606374
.L0805E99C: .4byte 0x0203CD90
.L0805E9A0: .4byte gUnk_086068A4
.L0805E9A4:
	movs r0, #0x11
	strh r0, [r5, #0x2e]
	ldr r0, .L0805E9F8 @ =0x0203CD90
	ldr r6, [r0, #4]
	ldr r3, .L0805E9FC @ =gUnk_08606BD8
.L0805E9AE:
	str r3, [sp]
	adds r0, r7, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl func_fe6_080478DC
	str r0, [r5, #0x60]
	ldr r4, .L0805EA00 @ =gUnk_Banim_0201A77C
	adds r0, r6, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	adds r0, r4, #0
	movs r1, #0x20
	bl func_fe6_08047AB0
	ldr r0, .L0805EA04 @ =gUnk_081CC428
	mov r1, r8
	cmp r1, #0
	beq .L0805E9E0
	ldr r0, .L0805EA08 @ =gUnk_081CD7AC
	mov r1, sb
	cmp r1, #0
	bne .L0805E9E0
	ldr r0, .L0805EA0C @ =gUnk_081CCDE0
.L0805E9E0:
	movs r1, #0x80
	lsls r1, r1, #5
	bl func_fe6_08047A88
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E9F8: .4byte 0x0203CD90
.L0805E9FC: .4byte gUnk_08606BD8
.L0805EA00: .4byte gUnk_Banim_0201A77C
.L0805EA04: .4byte gUnk_081CC428
.L0805EA08: .4byte gUnk_081CD7AC
.L0805EA0C: .4byte gUnk_081CCDE0

	thumb_func_start func_fe6_0805EA10
func_fe6_0805EA10: @ 0x0805EA10
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805EA30
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0805EA30:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805EA38
func_fe6_0805EA38: @ 0x0805EA38
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r7, [sp, #0x18]
	ldr r0, .L0805EA6C @ =gUnk_0860638C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
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
.L0805EA6C: .4byte gUnk_0860638C

	thumb_func_start func_fe6_0805EA70
func_fe6_0805EA70: @ 0x0805EA70
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0805EAA6
	ldr r0, [r5, #0x5c]
	ldr r1, [r5, #0x44]
	ldr r2, [r5, #0x48]
	ldr r3, [r5, #0x4c]
	ldr r4, [r5, #0x50]
	str r4, [sp]
	bl func_fe6_0805EB40
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r5, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xe2
	movs r3, #1
	bl func_fe6_0805C804
.L0805EAA6:
	ldrh r0, [r5, #0x2c]
	cmp r0, #0x30
	bne .L0805EACA
	ldr r0, [r5, #0x5c]
	ldr r2, [r5, #0x44]
	ldr r3, [r5, #0x4c]
	movs r1, #0
	bl func_fe6_0805ED1C
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r5, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xe2
	movs r3, #1
	bl func_fe6_0805C804
.L0805EACA:
	ldrh r0, [r5, #0x2c]
	cmp r0, #0x3c
	bne .L0805EAE0
	ldr r0, [r5, #0x5c]
	movs r1, #4
	bl func_fe6_08046794
	ldr r0, [r5, #0x5c]
	movs r1, #0xa
	bl func_fe6_0805EE9C
.L0805EAE0:
	ldrh r3, [r5, #0x2c]
	cmp r3, #0x4f
	bne .L0805EB04
	ldr r0, [r5, #0x5c]
	ldr r2, [r5, #0x48]
	ldr r3, [r5, #0x50]
	movs r1, #1
	bl func_fe6_0805ED1C
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r5, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xe2
	movs r3, #1
	bl func_fe6_0805C804
.L0805EB04:
	ldrh r0, [r5, #0x2c]
	cmp r0, #0x5b
	bne .L0805EB10
	ldr r1, .L0805EB3C @ =gUnk_Banim_0201F0DC
	movs r0, #1
	str r0, [r1]
.L0805EB10:
	ldrh r3, [r5, #0x2c]
	cmp r3, #0x60
	bne .L0805EB26
	ldr r0, [r5, #0x5c]
	movs r1, #4
	bl func_fe6_08046794
	ldr r0, [r5, #0x5c]
	movs r1, #0xa
	bl func_fe6_0805EE9C
.L0805EB26:
	ldrh r0, [r5, #0x2c]
	cmp r0, #0x78
	bne .L0805EB32
	adds r0, r5, #0
	bl Proc_Break
.L0805EB32:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805EB3C: .4byte gUnk_Banim_0201F0DC

	thumb_func_start func_fe6_0805EB40
func_fe6_0805EB40: @ 0x0805EB40
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	adds r6, r3, #0
	ldr r0, .L0805EB78 @ =gUnk_086063A4
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	mov r0, r8
	str r0, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #0x14
	strh r0, [r5, #0x2e]
	ldr r0, .L0805EB7C @ =0x0203CD90
	ldr r7, [r0]
	cmp r4, #0
	bne .L0805EB88
	ldr r3, .L0805EB80 @ =gUnk_08606C70
	ldr r6, .L0805EB84 @ =gUnk_081CE154
	b .L0805EBB4
	.align 2, 0
.L0805EB78: .4byte gUnk_086063A4
.L0805EB7C: .4byte 0x0203CD90
.L0805EB80: .4byte gUnk_08606C70
.L0805EB84: .4byte gUnk_081CE154
.L0805EB88:
	cmp r6, #1
	beq .L0805EBA0
	cmp r6, #1
	bhs .L0805EBB0
	ldr r3, .L0805EB98 @ =gUnk_08606D00
	ldr r6, .L0805EB9C @ =gUnk_081CE474
	b .L0805EBB4
	.align 2, 0
.L0805EB98: .4byte gUnk_08606D00
.L0805EB9C: .4byte gUnk_081CE474
.L0805EBA0:
	ldr r3, .L0805EBA8 @ =gUnk_08606D90
	ldr r6, .L0805EBAC @ =gUnk_081CE848
	b .L0805EBB4
	.align 2, 0
.L0805EBA8: .4byte gUnk_08606D90
.L0805EBAC: .4byte gUnk_081CE848
.L0805EBB0:
	ldr r3, .L0805EBF4 @ =gUnk_08606E1C
	ldr r6, .L0805EBF8 @ =gUnk_081CEC7C
.L0805EBB4:
	str r3, [sp]
	mov r0, r8
	adds r1, r3, #0
	adds r2, r3, #0
	bl func_fe6_080478DC
	adds r1, r0, #0
	str r1, [r5, #0x60]
	ldr r0, .L0805EBFC @ =0x00008840
	strh r0, [r1, #8]
	ldr r4, .L0805EC00 @ =gUnk_Banim_0201A77C
	adds r0, r7, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L0805EC04 @ =gPal+0x300
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r6, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L0805EC08 @ =0x0203CD90
	ldr r7, [r0, #4]
	mov r0, sb
	cmp r0, #0
	bne .L0805EC14
	ldr r3, .L0805EC0C @ =gUnk_08606C70
	ldr r6, .L0805EC10 @ =gUnk_081CE154
	b .L0805EC40
	.align 2, 0
.L0805EBF4: .4byte gUnk_08606E1C
.L0805EBF8: .4byte gUnk_081CEC7C
.L0805EBFC: .4byte 0x00008840
.L0805EC00: .4byte gUnk_Banim_0201A77C
.L0805EC04: .4byte gPal+0x300
.L0805EC08: .4byte 0x0203CD90
.L0805EC0C: .4byte gUnk_08606C70
.L0805EC10: .4byte gUnk_081CE154
.L0805EC14:
	ldr r0, [sp, #0x20]
	cmp r0, #1
	beq .L0805EC2C
	cmp r0, #1
	bhs .L0805EC3C
	ldr r3, .L0805EC24 @ =gUnk_08606D00
	ldr r6, .L0805EC28 @ =gUnk_081CE474
	b .L0805EC40
	.align 2, 0
.L0805EC24: .4byte gUnk_08606D00
.L0805EC28: .4byte gUnk_081CE474
.L0805EC2C:
	ldr r3, .L0805EC34 @ =gUnk_08606D90
	ldr r6, .L0805EC38 @ =gUnk_081CE848
	b .L0805EC40
	.align 2, 0
.L0805EC34: .4byte gUnk_08606D90
.L0805EC38: .4byte gUnk_081CE848
.L0805EC3C:
	ldr r3, .L0805ECA8 @ =gUnk_08606E1C
	ldr r6, .L0805ECAC @ =gUnk_081CEC7C
.L0805EC40:
	str r3, [sp]
	mov r0, r8
	adds r1, r3, #0
	adds r2, r3, #0
	bl func_fe6_080478DC
	adds r1, r0, #0
	str r1, [r5, #0x64]
	ldr r0, .L0805ECB0 @ =0x0000A880
	strh r0, [r1, #8]
	ldr r4, .L0805ECB4 @ =gUnk_Banim_0201AF7C
	adds r0, r7, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L0805ECB8 @ =gPal+0x340
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r6, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L0805ECBC @ =0x06010800
	ldr r0, .L0805ECC0 @ =0xFFFFF800
	adds r4, r4, r0
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r4, #0
	bl RegisterDataMove
	bl EnablePalSync
	ldr r1, [r5, #0x60]
	ldr r0, [r5, #0x5c]
	ldrh r0, [r0, #2]
	adds r0, #0x20
	strh r0, [r1, #2]
	ldr r1, [r5, #0x64]
	ldr r0, [r5, #0x5c]
	ldrh r0, [r0, #2]
	subs r0, #0x20
	strh r0, [r1, #2]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805ECA8: .4byte gUnk_08606E1C
.L0805ECAC: .4byte gUnk_081CEC7C
.L0805ECB0: .4byte 0x0000A880
.L0805ECB4: .4byte gUnk_Banim_0201AF7C
.L0805ECB8: .4byte gPal+0x340
.L0805ECBC: .4byte 0x06010800
.L0805ECC0: .4byte 0xFFFFF800

	thumb_func_start func_fe6_0805ECC4
func_fe6_0805ECC4: @ 0x0805ECC4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x20
	movs r2, #0
	bl Interpolate
	ldr r2, [r4, #0x60]
	ldr r1, [r4, #0x5c]
	ldrh r1, [r1, #2]
	adds r1, r1, r0
	strh r1, [r2, #2]
	ldr r2, [r4, #0x64]
	ldr r1, [r4, #0x5c]
	ldrh r1, [r1, #2]
	subs r0, r1, r0
	strh r0, [r2, #2]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805ED14
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r0, [r4, #0x64]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0805ED14:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805ED1C
func_fe6_0805ED1C: @ 0x0805ED1C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov r8, r0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, .L0805ED58 @ =gUnk_086063BC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	mov r0, r8
	str r0, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #5
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	adds r0, #0x29
	strb r5, [r0]
	adds r0, #1
	strb r6, [r0]
	cmp r5, #0
	bne .L0805ED60
	ldr r0, .L0805ED5C @ =0x0203CD90
	ldr r0, [r0]
	b .L0805ED64
	.align 2, 0
.L0805ED58: .4byte gUnk_086063BC
.L0805ED5C: .4byte 0x0203CD90
.L0805ED60:
	ldr r0, .L0805ED70 @ =0x0203CD90
	ldr r0, [r0, #4]
.L0805ED64:
	mov sb, r0
	cmp r6, #0
	bne .L0805ED7C
	ldr r3, .L0805ED74 @ =gUnk_08606F0C
	ldr r6, .L0805ED78 @ =gUnk_081CF03C
	b .L0805EDA8
	.align 2, 0
.L0805ED70: .4byte 0x0203CD90
.L0805ED74: .4byte gUnk_08606F0C
.L0805ED78: .4byte gUnk_081CF03C
.L0805ED7C:
	cmp r7, #1
	beq .L0805ED94
	cmp r7, #1
	bhs .L0805EDA4
	ldr r3, .L0805ED8C @ =gUnk_08607084
	ldr r6, .L0805ED90 @ =gUnk_081CF574
	b .L0805EDA8
	.align 2, 0
.L0805ED8C: .4byte gUnk_08607084
.L0805ED90: .4byte gUnk_081CF574
.L0805ED94:
	ldr r3, .L0805ED9C @ =gUnk_086071D8
	ldr r6, .L0805EDA0 @ =gUnk_081CFCB0
	b .L0805EDA8
	.align 2, 0
.L0805ED9C: .4byte gUnk_086071D8
.L0805EDA0: .4byte gUnk_081CFCB0
.L0805EDA4:
	ldr r3, .L0805EDD4 @ =gUnk_086074A0
	ldr r6, .L0805EDD8 @ =gUnk_081D043C
.L0805EDA8:
	str r3, [sp]
	mov r0, r8
	adds r1, r3, #0
	adds r2, r3, #0
	bl func_fe6_080478DC
	adds r1, r0, #0
	str r1, [r4, #0x60]
	cmp r5, #0
	bne .L0805EDDC
	ldrh r0, [r1, #4]
	adds r0, #0xa
	strh r0, [r1, #4]
	ldr r1, [r4, #0x60]
	movs r0, #0x78
	strh r0, [r1, #0xa]
	bl BasSort
	ldr r0, [r4, #0x5c]
	ldrh r1, [r0, #2]
	adds r1, #0x10
	b .L0805EDF2
	.align 2, 0
.L0805EDD4: .4byte gUnk_086074A0
.L0805EDD8: .4byte gUnk_081D043C
.L0805EDDC:
	ldrh r0, [r1, #4]
	adds r0, #2
	strh r0, [r1, #4]
	ldr r1, [r4, #0x60]
	movs r0, #0x14
	strh r0, [r1, #0xa]
	bl BasSort
	ldr r0, [r4, #0x5c]
	ldrh r1, [r0, #2]
	subs r1, #0xc
.L0805EDF2:
	strh r1, [r4, #0x32]
	ldrh r0, [r0, #2]
	subs r0, #0x10
	strh r0, [r4, #0x34]
	ldr r0, [r4, #0x60]
	strh r1, [r0, #2]
	ldr r4, .L0805EE28 @ =gUnk_Banim_0201A77C
	mov r0, sb
	adds r1, r4, #0
	bl LZ77UnCompWram
	adds r0, r4, #0
	movs r1, #0x20
	bl func_fe6_08047AB0
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r6, #0
	bl func_fe6_08047A88
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805EE28: .4byte gUnk_Banim_0201A77C

	thumb_func_start func_fe6_0805EE2C
func_fe6_0805EE2C: @ 0x0805EE2C
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
	ldr r1, [r4, #0x60]
	strh r0, [r1, #2]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805EE6C
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x14
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	bl Proc_Break
.L0805EE6C:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805EE74
func_fe6_0805EE74: @ 0x0805EE74
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805EE94
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0805EE94:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805EE9C
func_fe6_0805EE9C: @ 0x0805EE9C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, .L0805EECC @ =gUnk_Banim_02017744
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805EED0 @ =gUnk_086063DC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	movs r1, #0
	bl func_fe6_08045F48
	str r0, [r4, #0x60]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r6, [r4, #0x2e]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805EECC: .4byte gUnk_Banim_02017744
.L0805EED0: .4byte gUnk_086063DC

	thumb_func_start func_fe6_0805EED4
func_fe6_0805EED4: @ 0x0805EED4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r5, .L0805F060 @ =gUnk_Banim_02017758
	ldrh r1, [r5]
	ldrh r2, [r5, #2]
	movs r0, #2
	bl SetBgOffset
	ldr r6, .L0805F064 @ =gEkrBg0QuakeVec
	ldrh r0, [r5]
	ldrh r2, [r6]
	adds r1, r0, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r3, [r5, #2]
	ldrh r0, [r6, #2]
	adds r2, r3, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	bl SetBgOffset
	ldrh r1, [r5]
	ldrh r2, [r6]
	adds r0, r1, r2
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r5, #2]
	ldrh r2, [r6, #2]
	adds r1, r3, r2
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_fe6_0804392C
	ldrh r3, [r5]
	ldrh r1, [r6]
	adds r0, r3, r1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r5, #2]
	ldrh r3, [r6, #2]
	adds r1, r2, r3
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl func_fe6_08044230
	bl GetEkrDragonStatueType5370
	cmp r0, #0
	beq .L0805EF58
	ldrh r1, [r5]
	ldrh r2, [r5, #2]
	adds r2, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #3
	bl SetBgOffset
.L0805EF58:
	ldr r0, .L0805F068 @ =gUnk_Banim_02000020
	mov sb, r0
	ldrh r0, [r5]
	mov r2, sb
	ldrh r2, [r2]
	adds r1, r0, r2
	ldr r3, .L0805F06C @ =gEkrBgPosition
	mov sl, r3
	ldr r4, [r3]
	subs r1, r1, r4
	ldr r2, .L0805F070 @ =gUnk_Banim_02000024
	mov r8, r2
	ldrh r3, [r5, #2]
	ldrh r5, [r2]
	subs r5, r5, r3
	mov ip, r5
	mov r2, sb
	ldrh r2, [r2, #2]
	adds r0, r0, r2
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, r8
	ldrh r0, [r0, #2]
	subs r3, r0, r3
	lsls r3, r3, #0x10
	lsrs r4, r3, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	mov r3, ip
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	movs r0, #0
	bl func_fe6_08047C88
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl func_fe6_08047C88
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	ldrh r5, [r7, #0x2e]
	lsls r1, r5, #0x10
	cmp r0, r1
	ble .L0805F052
	ldr r1, .L0805F074 @ =gUnk_Banim_02017744
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldrh r1, [r6]
	ldrh r2, [r6, #2]
	movs r0, #0
	bl SetBgOffset
	ldrh r1, [r6]
	rsbs r0, r1, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r6, #2]
	rsbs r1, r2, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_fe6_0804392C
	ldrh r3, [r6]
	rsbs r0, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r6, [r6, #2]
	rsbs r1, r6, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl func_fe6_08044230
	bl GetEkrDragonStatueType5370
	cmp r0, #0
	beq .L0805F012
	movs r0, #3
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
.L0805F012:
	mov r5, sl
	ldr r0, [r5]
	mov r2, sb
	ldrh r2, [r2]
	subs r1, r2, r0
	mov r3, sb
	ldrh r3, [r3, #2]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, r8
	ldrh r4, [r0, #2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0
	bl func_fe6_08047C88
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl func_fe6_08047C88
	ldr r0, [r7, #0x60]
	bl Proc_End
	adds r0, r7, #0
	bl Proc_Break
.L0805F052:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F060: .4byte gUnk_Banim_02017758
.L0805F064: .4byte gEkrBg0QuakeVec
.L0805F068: .4byte gUnk_Banim_02000020
.L0805F06C: .4byte gEkrBgPosition
.L0805F070: .4byte gUnk_Banim_02000024
.L0805F074: .4byte gUnk_Banim_02017744

	thumb_func_start func_fe6_0805F078
func_fe6_0805F078: @ 0x0805F078
	push {lr}
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, .L0805F090 @ =gUnk_08607504
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r1, .L0805F094 @ =0x06008000
	bl LZ77UnCompVram
	pop {r0}
	bx r0
	.align 2, 0
.L0805F090: .4byte gUnk_08607504
.L0805F094: .4byte 0x06008000

	thumb_func_start func_fe6_0805F098
func_fe6_0805F098: @ 0x0805F098
	push {r4, lr}
	sub sp, #8
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #1
	ldr r0, .L0805F0D0 @ =gUnk_08607504
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r4, .L0805F0D4 @ =gUnk_Banim_0201977C
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L0805F0D8 @ =gBg3Tm
	movs r0, #6
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl EfxTmCpyBG
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F0D0: .4byte gUnk_08607504
.L0805F0D4: .4byte gUnk_Banim_0201977C
.L0805F0D8: .4byte gBg3Tm

	thumb_func_start func_fe6_0805F0DC
func_fe6_0805F0DC: @ 0x0805F0DC
	push {lr}
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #2
	ldr r0, .L0805F0F8 @ =gUnk_08607504
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r1, .L0805F0FC @ =gPal+0xC0
	bl LZ77UnCompWram
	pop {r0}
	bx r0
	.align 2, 0
.L0805F0F8: .4byte gUnk_08607504
.L0805F0FC: .4byte gPal+0xC0

	thumb_func_start func_fe6_0805F100
func_fe6_0805F100: @ 0x0805F100
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl func_fe6_0805F078
	movs r5, #0
	str r5, [sp]
	ldr r1, .L0805F13C @ =0x0600FFE0
	ldr r2, .L0805F140 @ =0x01000008
	mov r0, sp
	bl CpuFastSet
	adds r0, r4, #0
	bl func_fe6_0805F098
	adds r0, r4, #0
	bl func_fe6_0805F0DC
	ldr r0, .L0805F144 @ =gPal
	strh r5, [r0]
	movs r0, #8
	bl EnableBgSync
	bl EnablePalSync
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F13C: .4byte 0x0600FFE0
.L0805F140: .4byte 0x01000008
.L0805F144: .4byte gPal

	thumb_func_start CheckEkrPopupDone
CheckEkrPopupDone: @ 0x0805F148
	ldr r0, .L0805F154 @ =gUnk_Banim_0201F0E4
	ldr r0, [r0]
	cmp r0, #1
	beq .L0805F158
	movs r0, #0
	b .L0805F15A
	.align 2, 0
.L0805F154: .4byte gUnk_Banim_0201F0E4
.L0805F158:
	movs r0, #1
.L0805F15A:
	bx lr

	thumb_func_start EndEkrPopup
EndEkrPopup: @ 0x0805F15C
	push {r4, lr}
	ldr r4, .L0805F174 @ =gUnk_Banim_0201F0E0
	ldr r0, [r4]
	cmp r0, #0
	beq .L0805F16E
	bl Proc_End
	movs r0, #0
	str r0, [r4]
.L0805F16E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F174: .4byte gUnk_Banim_0201F0E0

	thumb_func_start func_fe6_0805F178
func_fe6_0805F178: @ 0x0805F178
	push {lr}
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x5a
	bl EfxPlaySE
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F188
func_fe6_0805F188: @ 0x0805F188
	push {lr}
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x5c
	bl EfxPlaySE
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F198
func_fe6_0805F198: @ 0x0805F198
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov ip, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	ldr r6, .L0805F278 @ =gUnk_Banim_0201977C
	ldrh r1, [r6]
	movs r2, #0x88
	lsls r2, r2, #5
	adds r0, r1, r2
	mov r3, ip
	strh r0, [r3]
	mov r1, ip
	adds r1, #0x40
	ldrh r7, [r6, #0x30]
	adds r0, r7, r2
	strh r0, [r1]
	adds r1, #0x40
	adds r0, r6, #0
	adds r0, #0x60
	ldrh r0, [r0]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #0x40
	adds r0, r6, #0
	adds r0, #0x90
	ldrh r0, [r0]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0
	mov r8, r0
	cmp r8, sb
	bhs .L0805F22C
	adds r3, #0xc2
	str r3, [sp]
	mov r5, ip
	adds r5, #0x82
	adds r4, r6, #0
	adds r4, #0x62
	subs r3, #0x80
	mov r2, ip
	adds r2, #2
	adds r1, r6, #2
.L0805F1F8:
	ldrh r7, [r1]
	movs r0, #0x88
	lsls r0, r0, #5
	adds r7, r7, r0
	strh r7, [r2]
	ldrh r7, [r1, #0x30]
	adds r7, r7, r0
	strh r7, [r3]
	ldrh r7, [r4]
	adds r7, r7, r0
	strh r7, [r5]
	ldrh r7, [r4, #0x30]
	adds r7, r7, r0
	ldr r0, [sp]
	strh r7, [r0]
	adds r0, #2
	str r0, [sp]
	adds r5, #2
	adds r4, #2
	adds r3, #2
	adds r2, #2
	adds r1, #2
	movs r7, #1
	add r8, r7
	cmp r8, sb
	blo .L0805F1F8
.L0805F22C:
	mov r1, r8
	lsls r0, r1, #1
	mov r2, ip
	adds r1, r0, r2
	ldrh r3, [r6, #0x2e]
	movs r7, #0x88
	lsls r7, r7, #5
	adds r0, r3, r7
	strh r0, [r1, #2]
	adds r2, r1, #0
	adds r2, #0x42
	adds r0, r6, #0
	adds r0, #0x5e
	ldrh r0, [r0]
	adds r3, r7, #0
	adds r0, r0, r3
	strh r0, [r2]
	adds r2, #0x40
	adds r0, r6, #0
	adds r0, #0x8e
	ldrh r0, [r0]
	adds r0, r0, r3
	strh r0, [r2]
	adds r1, #0xc2
	adds r0, r6, #0
	adds r0, #0xbe
	ldrh r0, [r0]
	adds r0, r0, r3
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F278: .4byte gUnk_Banim_0201977C

	thumb_func_start func_fe6_0805F27C
func_fe6_0805F27C: @ 0x0805F27C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	mov sb, r1
	adds r7, r2, #0
	ldr r0, .L0805F2D8 @ =gUnk_0811531C
	ldr r1, .L0805F2DC @ =0x06002000
	bl LZ77UnCompVram
	ldr r0, .L0805F2E0 @ =gUnk_08115498
	ldr r1, .L0805F2E4 @ =gUnk_Banim_0201977C
	bl LZ77UnCompWram
	ldr r0, .L0805F2E8 @ =gUnk_Banim_02017640
	ldr r1, .L0805F2EC @ =0x060020C0
	movs r2, #0x83
	lsls r2, r2, #1
	movs r3, #1
	bl InitTextFont
	bl SetTextDrawNoClear
	ldr r0, .L0805F2F0 @ =gUnk_08115478
	ldr r1, .L0805F2F4 @ =gPal+0x20
	movs r2, #8
	bl CpuFastSet
	mov r0, sb
	cmp r0, #0
	bne .L0805F2FC
	movs r0, #0xc7
	lsls r0, r0, #4
	bl DecodeMsg
	adds r4, r0, #0
	bl GetStringTextLen
	mov r8, r0
	mov r5, r8
	adds r5, #0x10
	ldr r0, .L0805F2F8 @ =0x00000C71
	b .L0805F312
	.align 2, 0
.L0805F2D8: .4byte gUnk_0811531C
.L0805F2DC: .4byte 0x06002000
.L0805F2E0: .4byte gUnk_08115498
.L0805F2E4: .4byte gUnk_Banim_0201977C
.L0805F2E8: .4byte gUnk_Banim_02017640
.L0805F2EC: .4byte 0x060020C0
.L0805F2F0: .4byte gUnk_08115478
.L0805F2F4: .4byte gPal+0x20
.L0805F2F8: .4byte 0x00000C71
.L0805F2FC:
	movs r1, #0
	mov r8, r1
	adds r0, r7, #0
	bl GetItemName
	adds r4, r0, #0
	bl GetStringTextLen
	adds r5, r0, #0
	adds r5, #0x10
	ldr r0, .L0805F390 @ =0x00000C72
.L0805F312:
	bl DecodeMsg
	adds r4, r0, #0
	bl GetStringTextLen
	adds r4, r0, r5
	adds r0, r4, #7
	asrs r6, r0, #3
	ldr r0, .L0805F394 @ =gBg1Tm
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	bl func_fe6_0805F198
	ldr r5, .L0805F398 @ =gUnk_Banim_02017658
	adds r0, r5, #0
	adds r1, r6, #0
	bl InitText
	lsls r0, r6, #3
	subs r0, r0, r4
	asrs r0, r0, #1
	mov sl, r0
	adds r0, r5, #0
	mov r1, sl
	bl Text_SetCursor
	ldr r0, .L0805F39C @ =gUnk_08115378
	ldr r1, .L0805F3A0 @ =0x060020C0
	bl LZ77UnCompVram
	mov r3, sb
	cmp r3, #0
	bne .L0805F3A8
	movs r0, #0xc7
	lsls r0, r0, #4
	bl DecodeMsg
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0
	bl Text_SetColor
	adds r0, r5, #0
	adds r1, r4, #0
	bl Text_DrawString
	adds r0, r5, #0
	movs r1, #0x10
	bl Text_Skip
	ldr r0, .L0805F3A4 @ =0x00000C71
	bl DecodeMsg
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0
	bl Text_SetColor
	adds r0, r5, #0
	adds r1, r4, #0
	bl Text_DrawString
	b .L0805F3E0
	.align 2, 0
.L0805F390: .4byte 0x00000C72
.L0805F394: .4byte gBg1Tm
.L0805F398: .4byte gUnk_Banim_02017658
.L0805F39C: .4byte gUnk_08115378
.L0805F3A0: .4byte 0x060020C0
.L0805F3A4: .4byte 0x00000C71
.L0805F3A8:
	adds r0, r5, #0
	movs r1, #0x10
	bl Text_Skip
	adds r0, r7, #0
	bl GetItemName
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #1
	bl Text_SetColor
	adds r0, r5, #0
	adds r1, r4, #0
	bl Text_DrawString
	ldr r0, .L0805F420 @ =0x00000C72
	bl DecodeMsg
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0
	bl Text_SetColor
	adds r0, r5, #0
	adds r1, r4, #0
	bl Text_DrawString
.L0805F3E0:
	adds r1, r6, #2
	lsls r1, r1, #3
	movs r0, #0xf0
	subs r0, r0, r1
	asrs r5, r0, #1
	rsbs r1, r5, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, .L0805F424 @ =0x0000FFD0
	movs r0, #1
	bl SetBgOffset
	movs r0, #2
	bl EnableBgSync
	bl InitIcons
	mov r0, sb
	cmp r0, #0
	bne .L0805F428
	movs r0, #1
	movs r1, #0x12
	bl ApplyIconPalette
	adds r0, r7, #0
	bl GetItemKind
	adds r0, #0x70
	movs r1, #0x40
	bl PutIconObjImg
	b .L0805F43C
	.align 2, 0
.L0805F420: .4byte 0x00000C72
.L0805F424: .4byte 0x0000FFD0
.L0805F428:
	movs r0, #0
	movs r1, #0x12
	bl ApplyIconPalette
	adds r0, r7, #0
	bl GetItemIcon
	movs r1, #0x40
	bl PutIconObjImg
.L0805F43C:
	ldr r0, .L0805F490 @ =gUnk_08607660
	movs r1, #0x96
	bl BasCreate
	ldr r1, [sp]
	str r0, [r1, #0x60]
	movs r4, #0
	movs r1, #0x91
	lsls r1, r1, #6
	strh r1, [r0, #8]
	mov r1, sl
	adds r1, #8
	adds r1, r5, r1
	add r1, r8
	strh r1, [r0, #2]
	movs r1, #0x38
	strh r1, [r0, #4]
	bl EnablePalSync
	ldr r2, .L0805F494 @ =gDispIo
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
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F490: .4byte gUnk_08607660
.L0805F494: .4byte gDispIo

	thumb_func_start NewEkrPopup
NewEkrPopup: @ 0x0805F498
	push {r4, r5, lr}
	ldr r4, .L0805F554 @ =gUnk_Banim_0201F0E0
	ldr r0, .L0805F558 @ =gUnk_08607668
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r5, [r4]
	ldr r1, .L0805F55C @ =gUnk_Banim_0201F0E4
	movs r0, #0
	str r0, [r1]
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x48]
	str r0, [r5, #0x44]
	str r0, [r5, #0x50]
	str r0, [r5, #0x4c]
	bl func_fe6_08058F38
	cmp r0, #0
	bne .L0805F576
	ldr r0, .L0805F560 @ =gEkrDistanceType
	ldrh r0, [r0]
	cmp r0, #4
	beq .L0805F576
	ldr r0, .L0805F564 @ =0x0203CD08
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0805F500
	ldr r4, .L0805F568 @ =gpEkrBattleUnitLeft
	ldr r0, [r4]
	bl HasBattleUnitGainedWeaponLevel
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805F4EA
	ldr r0, [r4]
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r5, #0x44]
.L0805F4EA:
	ldr r0, [r4]
	bl DidBattleUnitBreakWeapon
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805F500
	ldr r0, [r4]
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r5, #0x48]
.L0805F500:
	ldr r0, .L0805F564 @ =0x0203CD08
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0805F538
	ldr r4, .L0805F56C @ =gpEkrBattleUnitRight
	ldr r0, [r4]
	bl HasBattleUnitGainedWeaponLevel
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805F522
	ldr r0, [r4]
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r5, #0x4c]
.L0805F522:
	ldr r0, [r4]
	bl DidBattleUnitBreakWeapon
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805F538
	ldr r0, [r4]
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r5, #0x50]
.L0805F538:
	ldr r0, [r5, #0x44]
	ldr r1, [r5, #0x48]
	adds r0, r0, r1
	ldr r1, [r5, #0x4c]
	adds r0, r0, r1
	ldr r1, [r5, #0x50]
	cmn r0, r1
	bne .L0805F570
	ldr r1, .L0805F55C @ =gUnk_Banim_0201F0E4
	movs r0, #1
	str r0, [r1]
	bl EndEkrPopup
	b .L0805F576
	.align 2, 0
.L0805F554: .4byte gUnk_Banim_0201F0E0
.L0805F558: .4byte gUnk_08607668
.L0805F55C: .4byte gUnk_Banim_0201F0E4
.L0805F560: .4byte gEkrDistanceType
.L0805F564: .4byte 0x0203CD08
.L0805F568: .4byte gpEkrBattleUnitLeft
.L0805F56C: .4byte gpEkrBattleUnitRight
.L0805F570:
	movs r0, #0x80
	bl SetBgmVolume
.L0805F576:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F57C
func_fe6_0805F57C: @ 0x0805F57C
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	ble .L0805F594
	adds r0, r1, #0
	bl Proc_Break
.L0805F594:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F598
func_fe6_0805F598: @ 0x0805F598
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x44]
	cmp r2, #0
	beq .L0805F5B4
	movs r1, #0
	bl func_fe6_0805F27C
	bl func_fe6_0805F178
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x60
	strh r0, [r4, #0x2e]
.L0805F5B4:
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F5C0
func_fe6_0805F5C0: @ 0x0805F5C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L0805F5D2
	adds r0, r4, #0
	bl Proc_Break
	b .L0805F5F2
.L0805F5D2:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805F5F2
	ldr r0, [r4, #0x60]
	bl BasRemove
	bl SpellFx_ClearBG1
	adds r0, r4, #0
	bl Proc_Break
.L0805F5F2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F5F8
func_fe6_0805F5F8: @ 0x0805F5F8
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x4c]
	cmp r2, #0
	beq .L0805F614
	movs r1, #0
	bl func_fe6_0805F27C
	bl func_fe6_0805F178
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x60
	strh r0, [r4, #0x2e]
.L0805F614:
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F620
func_fe6_0805F620: @ 0x0805F620
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	bne .L0805F632
	adds r0, r4, #0
	bl Proc_Break
	b .L0805F652
.L0805F632:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805F652
	ldr r0, [r4, #0x60]
	bl BasRemove
	bl SpellFx_ClearBG1
	adds r0, r4, #0
	bl Proc_Break
.L0805F652:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F658
func_fe6_0805F658: @ 0x0805F658
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x48]
	cmp r2, #0
	beq .L0805F674
	movs r1, #1
	bl func_fe6_0805F27C
	bl func_fe6_0805F188
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x6c
	strh r0, [r4, #0x2e]
.L0805F674:
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F680
func_fe6_0805F680: @ 0x0805F680
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x48]
	cmp r0, #0
	bne .L0805F692
	adds r0, r4, #0
	bl Proc_Break
	b .L0805F6B2
.L0805F692:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805F6B2
	ldr r0, [r4, #0x60]
	bl BasRemove
	bl SpellFx_ClearBG1
	adds r0, r4, #0
	bl Proc_Break
.L0805F6B2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F6B8
func_fe6_0805F6B8: @ 0x0805F6B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x50]
	cmp r2, #0
	beq .L0805F6D4
	movs r1, #1
	bl func_fe6_0805F27C
	bl func_fe6_0805F188
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x6c
	strh r0, [r4, #0x2e]
.L0805F6D4:
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F6E0
func_fe6_0805F6E0: @ 0x0805F6E0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	cmp r0, #0
	bne .L0805F6F2
	adds r0, r4, #0
	bl Proc_Break
	b .L0805F716
.L0805F6F2:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805F716
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x60]
	bl BasRemove
	bl SpellFx_ClearBG1
	adds r0, r4, #0
	bl Proc_Break
.L0805F716:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F71C
func_fe6_0805F71C: @ 0x0805F71C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	ble .L0805F742
	ldr r0, .L0805F748 @ =gUnk_Banim_0201F0E4
	movs r1, #1
	str r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl SetBgmVolume
	adds r0, r4, #0
	bl Proc_Break
.L0805F742:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F748: .4byte gUnk_Banim_0201F0E4

	thumb_func_start func_fe6_0805F74C
func_fe6_0805F74C: @ 0x0805F74C
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0805F750
func_fe6_0805F750: @ 0x0805F750
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, .L0805F77C @ =gUnk_08662E4C
	bl GetItemIid
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4]
	ldr r2, .L0805F780 @ =0x0000FFFF
	cmp r1, r2
	beq .L0805F774
.L0805F768:
	cmp r1, r0
	beq .L0805F774
	adds r4, #0x10
	ldrh r1, [r4]
	cmp r1, r2
	bne .L0805F768
.L0805F774:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0805F77C: .4byte gUnk_08662E4C
.L0805F780: .4byte 0x0000FFFF

	thumb_func_start GetWeaponAnimActorCount
GetWeaponAnimActorCount: @ 0x0805F784
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805F750
	ldrb r0, [r0, #2]
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0805F794
func_fe6_0805F794: @ 0x0805F794
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805F750
	ldrh r0, [r0, #4]
	pop {r1}
	bx r1

	thumb_func_start GetWeaponAnimManimSpecialScr
GetWeaponAnimManimSpecialScr: @ 0x0805F7A4
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805F750
	ldr r0, [r0, #8]
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0805F7B4
func_fe6_0805F7B4: @ 0x0805F7B4
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805F750
	ldrb r0, [r0, #0xc]
	pop {r1}
	bx r1

	thumb_func_start GetItemMaFacing
GetItemMaFacing: @ 0x0805F7C4
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805F750
	ldrb r0, [r0, #0xd]
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0805F7D4
func_fe6_0805F7D4: @ 0x0805F7D4
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805F750
	ldrb r0, [r0, #0xe]
	pop {r1}
	bx r1
