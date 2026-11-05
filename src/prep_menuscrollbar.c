#include "prelude.h"
#include "proc.h"
#include "oam.h"
#include "sprite.h"
#include "prepscreen.h"

u16 CONST_DATA Sprite_MenuScrollContainer8[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x1),
};

u16 CONST_DATA Sprite_MenuScrollContainer16[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x1),
};

u16 CONST_DATA Sprite_MenuScrollContainer32[] = {
	1,
	OAM0_SHAPE_8x32, OAM1_SIZE_8x32, OAM2_CHR(0x1),
};

u16 CONST_DATA Sprite_MenuScroll_TopDecal[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x15),
};

u16 CONST_DATA Sprite_MenuScroll_BottomDecal[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x16),
};

u16 CONST_DATA Sprite_MenuScrollSegmentEmpty[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x14),
};

u16 CONST_DATA Sprite_MenuScrollSegmentA[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xC),
};

u16 CONST_DATA Sprite_MenuScrollSegmentB[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xD),
};

u16 CONST_DATA Sprite_MenuScrollSegmentC[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xE),
};

u16 CONST_DATA Sprite_MenuScrollSegmentD[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xF),
};

u16 CONST_DATA Sprite_MenuScrollSegmentE[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x10),
};

u16 CONST_DATA Sprite_MenuScrollSegmentF[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x11),
};

u16 CONST_DATA Sprite_MenuScrollSegmentG[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x12),
};

u16 CONST_DATA Sprite_MenuScrollSegmentH[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x13),
};

u16 CONST_DATA Sprite_MenuScrollSegment16[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, 0,
};

u16 CONST_DATA Sprite_MenuScrollSegment32[] = {
	1,
	OAM0_SHAPE_8x32, OAM1_SIZE_8x32, 0,
};

u16 *CONST_DATA MenuScrollBarSegmentSprites[] = {
	Sprite_MenuScrollSegmentEmpty,
	Sprite_MenuScrollSegmentA,
	Sprite_MenuScrollSegmentB,
	Sprite_MenuScrollSegmentC,
	Sprite_MenuScrollSegmentD,
	Sprite_MenuScrollSegmentE,
	Sprite_MenuScrollSegmentF,
	Sprite_MenuScrollSegmentG,
	Sprite_MenuScrollSegmentH,
	Sprite_MenuScrollSegment16,
	Sprite_MenuScrollSegment32
};

u16 CONST_DATA Sprite_MenuScrollArrowA[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x17),
};

u16 CONST_DATA Sprite_MenuScrollArrowB[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x18),
};

u16 CONST_DATA Sprite_MenuScrollArrowC[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x19),
};

u16 CONST_DATA Sprite_MenuScrollArrowD[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x1A),
};

u16 CONST_DATA Sprite_MenuScrollArrowE[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x1B),
};

u16 CONST_DATA Sprite_MenuScrollArrowF[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x1C),
};

u16 *CONST_DATA MenuScrollArrowSprites[] = {
	Sprite_MenuScrollArrowA,
	Sprite_MenuScrollArrowB,
	Sprite_MenuScrollArrowC,
	Sprite_MenuScrollArrowD,
	Sprite_MenuScrollArrowE,
	Sprite_MenuScrollArrowF
};


struct ProcScr CONST_DATA ProcScr_menu_scroll[] = {
	PROC_NAME_DEBUG("menu_scroll"),
	PROC_CALL(MenuScroll_Init),
	PROC_REPEAT(MenuScroll_Loop),
	PROC_END,
};

void MenuScroll_Init(struct MenuScrollBarProc * proc)
{
	proc->xBase = 0;
	proc->yBase = 0;
	proc->numSegments = 0;

	proc->currentSegment = 0;
	proc->numTotalRows = proc->currentSegment;
	proc->numVisibleRows = 0;
	proc->prevSegment = proc->currentSegment;
	proc->oam2Chr = OBCHR_PREPMENU_390;
	proc->oam2Pal = OAM2_PAL(OBPAL_PREPMENU_1);
	proc->topArrowFrameIdx = 0;
	proc->bottomArrowFrameIdx = 0;
}

void MenuScroll_Loop(struct MenuScrollBarProc *proc)
{
	u8 i, j, k;

	if (proc->numTotalRows <= proc->numVisibleRows)
		return;

	for (i = 0; i < proc->numSegments / 4; i++)
		PutSpriteExt(4, proc->xBase, proc->yBase + i * 32,
			Sprite_MenuScrollContainer32, proc->oam2Chr + proc->oam2Pal);

	for (j = 0; j < (proc->numSegments - i * 4) >> 1; j++)
		PutSpriteExt(4, proc->xBase, proc->yBase + j * 16 + i * 32,
			Sprite_MenuScrollContainer16, proc->oam2Chr + proc->oam2Pal);

	for (k = 0; k < proc->numSegments - (i * 4 + j * 2); k++)
		PutSpriteExt(4, proc->xBase, proc->yBase + k * 8 + j * 16 + i * 32,
			Sprite_MenuScrollContainer8, proc->oam2Chr + proc->oam2Pal);

	if (i + j + k > 0) {
		u32 len = proc->numSegments << 19;
		u16 cur = proc->currentSegment;
		u16 total = proc->numTotalRows;
		u8 visible = proc->numVisibleRows;

		if (total > visible) {
			u32 unit = len / total;
			u32 bar = len * visible / total;
			u32 n32;

			if (cur != 0)
				PutSpriteExt(4, (proc->xBase + 1) | OAM1_VFLIP, proc->yBase - 8,
					MenuScrollArrowSprites[proc->topArrowFrameIdx >> 3], proc->oam2Chr + proc->oam2Pal);

			for (n32 = 0; n32 < bar >> 21; n32++)
				PutSpriteExt(4, proc->xBase, proc->yBase + (unit * cur >> 20) + n32 * 32,
					MenuScrollBarSegmentSprites[MENUSCROLL_SEGMENT_FULL32], proc->oam2Chr + proc->oam2Pal);

			for (j = 0; j < ((bar >> 16) - n32 * 32) >> 4; j++)
				PutSpriteExt(4, proc->xBase, proc->yBase + (unit * cur >> 20) + n32 * 32 + j * 16,
					MenuScrollBarSegmentSprites[MENUSCROLL_SEGMENT_FULL16], proc->oam2Chr + proc->oam2Pal);

			for (k = 0; k < ((bar >> 16) - n32 * 32 - j * 16) >> 3; k++)
				PutSpriteExt(4, proc->xBase, proc->yBase + (unit * cur >> 20) + n32 * 32 + j * 16 + k * 8,
					MenuScrollBarSegmentSprites[MENUSCROLL_SEGMENT_FULL], proc->oam2Chr + proc->oam2Pal);

			if ((proc->currentSegment >> 4) + proc->numVisibleRows == proc->numTotalRows) {
				PutSpriteExt(4, proc->xBase, proc->yBase + (unit * cur >> 20) + (n32 * 32 + j * 16 + k * 8),
					MenuScrollBarSegmentSprites[proc->numSegments * 8 - ((unit * cur >> 20) + (n32 * 32 + j * 16 + k * 8))],
					proc->oam2Chr + proc->oam2Pal);
			} else {
				PutSpriteExt(4, proc->xBase, proc->yBase + (unit * cur >> 20) + (n32 * 32 + j * 16 + k * 8),
					MenuScrollBarSegmentSprites[(bar >> 16) & 7], proc->oam2Chr + proc->oam2Pal);

				PutSpriteExt(4, proc->xBase + 1, proc->yBase + proc->numSegments * 8 + 1,
					MenuScrollArrowSprites[proc->bottomArrowFrameIdx >> 3], proc->oam2Chr + proc->oam2Pal);
			}
		}

		PutSpriteExt(4, proc->xBase, proc->yBase - 8, Sprite_MenuScroll_TopDecal, proc->oam2Chr + proc->oam2Pal);
		PutSpriteExt(4, proc->xBase, proc->yBase + proc->numSegments * 8, Sprite_MenuScroll_BottomDecal, proc->oam2Chr + proc->oam2Pal);
	}

	if (proc->prevSegment != proc->currentSegment) {
		if (proc->prevSegment > proc->currentSegment)
			proc->topArrowFrameIdx++;

		if (proc->prevSegment < proc->currentSegment)
			proc->bottomArrowFrameIdx++;

		proc->prevSegment = proc->currentSegment;
	}

	proc->topArrowFrameIdx++;
	proc->bottomArrowFrameIdx++;

	if ((proc->topArrowFrameIdx >> 3) >= MENUSCROLL_ARROW_FRAME_COUNT)
		proc->topArrowFrameIdx = 0;

	if ((proc->bottomArrowFrameIdx >> 3) >= MENUSCROLL_ARROW_FRAME_COUNT)
		proc->bottomArrowFrameIdx = 0;
}

ProcPtr StartMenuScrollBar(ProcPtr parent)
{
	return SpawnProc(ProcScr_menu_scroll, parent);
}
