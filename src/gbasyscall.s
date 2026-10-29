	.include "asm_macros.inc"
	.include "asm_gbaio.inc"

	.syntax unified

	thumb_function ArcTan2
ArcTan2:
	swi #0xa
	bx lr

	thumb_function BgAffineSet
BgAffineSet:
	swi #0xe
	bx lr

	thumb_function CpuFastSet
CpuFastSet:
	swi #0xc
	bx lr

	thumb_function CpuSet
CpuSet:
	swi #0xb
	bx lr

	thumb_function Div
Div:
	swi #6
	bx lr

	thumb_function DivRem
DivRem:
	swi #6
	adds r0, r1, #0
	bx lr

	thumb_function HuffUnComp
HuffUnComp:
	swi #0x13
	bx lr

	thumb_function LZ77UnCompVram
LZ77UnCompVram:
	swi #0x12
	bx lr

	thumb_function LZ77UnCompWram
LZ77UnCompWram:
	swi #0x11
	bx lr

	thumb_function ObjAffineSet
ObjAffineSet:
	swi #0xf
	bx lr

	thumb_function RLUnCompVram
RLUnCompVram:
	swi #0x15
	bx lr

	thumb_function RLUnCompWram
RLUnCompWram:
	swi #0x14
	bx lr

	thumb_function SoftReset
SoftReset:
	ldr r3, =REG_IME
	movs r2, #0
	strb r2, [r3]
	ldr r1, =0x03007F00
	mov sp, r1
	swi #1
	swi #0

	.pool

	thumb_function SoundBiasReset
SoundBiasReset:
	movs r0, #0
	swi #0x19
	bx lr

	thumb_function SoundBiasSet
SoundBiasSet:
	movs r0, #1
	swi #0x19
	bx lr

	thumb_function Sqrt
Sqrt:
	swi #8
	bx lr

	thumb_function VBlankIntrWait
VBlankIntrWait:
	movs r2, #0
	swi #5
	bx lr

	.align 2, 0
