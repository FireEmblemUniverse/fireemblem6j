	.include "macro.inc"
	.include "asm_gbaio.inc"

	.syntax unified

	THUMB_FUNC_START ArcTan2
ArcTan2:
	swi #0xa
	bx lr

	THUMB_FUNC_START BgAffineSet
BgAffineSet:
	swi #0xe
	bx lr

	THUMB_FUNC_START CpuFastSet
CpuFastSet:
	swi #0xc
	bx lr

	THUMB_FUNC_START CpuSet
CpuSet:
	swi #0xb
	bx lr

	THUMB_FUNC_START Div
Div:
	swi #6
	bx lr

	THUMB_FUNC_START DivRem
DivRem:
	swi #6
	adds r0, r1, #0
	bx lr

	THUMB_FUNC_START HuffUnComp
HuffUnComp:
	swi #0x13
	bx lr

	THUMB_FUNC_START LZ77UnCompVram
LZ77UnCompVram:
	swi #0x12
	bx lr

	THUMB_FUNC_START LZ77UnCompWram
LZ77UnCompWram:
	swi #0x11
	bx lr

	THUMB_FUNC_START ObjAffineSet
ObjAffineSet:
	swi #0xf
	bx lr

	THUMB_FUNC_START RLUnCompVram
RLUnCompVram:
	swi #0x15
	bx lr

	THUMB_FUNC_START RLUnCompWram
RLUnCompWram:
	swi #0x14
	bx lr

	THUMB_FUNC_START SoftReset
SoftReset:
	ldr r3, =REG_IME
	movs r2, #0
	strb r2, [r3]
	ldr r1, =0x03007F00
	mov sp, r1
	swi #1
	swi #0

	.pool

	THUMB_FUNC_START SoundBiasReset
SoundBiasReset:
	movs r0, #0
	swi #0x19
	bx lr

	THUMB_FUNC_START SoundBiasSet
SoundBiasSet:
	movs r0, #1
	swi #0x19
	bx lr

	THUMB_FUNC_START Sqrt
Sqrt:
	swi #8
	bx lr

	THUMB_FUNC_START VBlankIntrWait
VBlankIntrWait:
	movs r2, #0
	swi #5
	bx lr

	.align 2, 0
