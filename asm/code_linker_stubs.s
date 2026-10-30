	.include "asm_macros.inc"

	@ modern ld doesn't generate the same sequences
	@ so we can't use it to replace this file in matching builds

	thumb_function ClearOam_thm
ClearOam_thm: @ 0x0809FA90
	bx pc
	.align
	.arm
	b ClearOam

	thumb_function TmApplyTsa_thm
TmApplyTsa_thm: @ 0x0809FA98
	bx pc
	.align
	.arm
	b TmApplyTsa

	thumb_function TmFillRect_thm
TmFillRect_thm: @ 0x0809FAA0
	bx pc
	.align
	.arm
	b TmFillRect

	thumb_function ColorFadeTick_thm
ColorFadeTick_thm: @ 0x0809FAA8
	bx pc
	.align
	.arm
	b ColorFadeTick

	thumb_function TmCopyRect_thm
TmCopyRect_thm: @ 0x0809FAB0
	bx pc
	.align
	.arm
	b TmCopyRect

	thumb_function Checksum32_thm
Checksum32_thm: @ 0x0809FAB8
	bx pc
	.align
	.arm
	b Checksum32
