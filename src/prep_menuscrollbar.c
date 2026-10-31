#include "prelude.h"
#include "proc.h"
#include "oam.h"
#include "sprite.h"
#include "prepscreen.h"

u16 CONST_DATA Sprite_08679578[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x1),
};

u16 CONST_DATA Sprite_08679580[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x1),
};

u16 CONST_DATA Sprite_MenuScrollContainer[] = {
	1,
	OAM0_SHAPE_8x32, OAM1_SIZE_8x32, OAM2_CHR(0x1),
};

u16 CONST_DATA Sprite_08679590[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x15),
};

u16 CONST_DATA Sprite_08679598[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x16),
};

u16 CONST_DATA Sprite_086795A0[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x14),
};

u16 CONST_DATA Sprite_086795A8[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xC),
};

u16 CONST_DATA Sprite_086795B0[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xD),
};

u16 CONST_DATA Sprite_086795B8[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xE),
};

u16 CONST_DATA Sprite_086795C0[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0xF),
};

u16 CONST_DATA Sprite_086795C8[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x10),
};

u16 CONST_DATA Sprite_086795D0[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x11),
};

u16 CONST_DATA Sprite_086795D8[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x12),
};

u16 CONST_DATA Sprite_086795E0[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x13),
};

u16 CONST_DATA Sprite_086795E8[] = {
	1,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, 0,
};

u16 CONST_DATA Sprite_086795F0[] = {
	1,
	OAM0_SHAPE_8x32, OAM1_SIZE_8x32, 0,
};

u16 *CONST_DATA MenuScrollBarSegmentSprites[] = {
	Sprite_086795A0,
	Sprite_086795A8,
	Sprite_086795B0,
	Sprite_086795B8,
	Sprite_086795C0,
	Sprite_086795C8,
	Sprite_086795D0,
	Sprite_086795D8,
	Sprite_086795E0,
	Sprite_086795E8,
	Sprite_086795F0
};

u16 CONST_DATA Sprite_08679624[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x17),
};

u16 CONST_DATA Sprite_0867962C[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x18),
};

u16 CONST_DATA Sprite_08679634[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x19),
};

u16 CONST_DATA Sprite_0867963C[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x1A),
};

u16 CONST_DATA Sprite_08679644[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x1B),
};

u16 CONST_DATA Sprite_0867964C[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x1C),
};

u16 *CONST_DATA MenuScrollArrowSprites[] = {
	Sprite_08679624,
	Sprite_0867962C,
	Sprite_08679634,
	Sprite_0867963C,
	Sprite_08679644,
	Sprite_0867964C
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
	proc->oam2Chr = 0x390;
	proc->oam2Pal = 0x1000;
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
			Sprite_MenuScrollContainer, proc->oam2Chr + proc->oam2Pal);

	for (j = 0; j < (proc->numSegments - i * 4) >> 1; j++)
		PutSpriteExt(4, proc->xBase, proc->yBase + j * 16 + i * 32,
			Sprite_08679580, proc->oam2Chr + proc->oam2Pal);

	for (k = 0; k < proc->numSegments - (i * 4 + j * 2); k++)
		PutSpriteExt(4, proc->xBase, proc->yBase + k * 8 + j * 16 + i * 32,
			Sprite_08679578, proc->oam2Chr + proc->oam2Pal);

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
					MenuScrollBarSegmentSprites[10], proc->oam2Chr + proc->oam2Pal);

			for (j = 0; j < ((bar >> 16) - n32 * 32) >> 4; j++)
				PutSpriteExt(4, proc->xBase, proc->yBase + (unit * cur >> 20) + n32 * 32 + j * 16,
					MenuScrollBarSegmentSprites[9], proc->oam2Chr + proc->oam2Pal);

			for (k = 0; k < ((bar >> 16) - n32 * 32 - j * 16) >> 3; k++)
				PutSpriteExt(4, proc->xBase, proc->yBase + (unit * cur >> 20) + n32 * 32 + j * 16 + k * 8,
					MenuScrollBarSegmentSprites[8], proc->oam2Chr + proc->oam2Pal);

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

		PutSpriteExt(4, proc->xBase, proc->yBase - 8, Sprite_08679590, proc->oam2Chr + proc->oam2Pal);
		PutSpriteExt(4, proc->xBase, proc->yBase + proc->numSegments * 8, Sprite_08679598, proc->oam2Chr + proc->oam2Pal);
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

	if ((proc->topArrowFrameIdx >> 3) > 5)
		proc->topArrowFrameIdx = 0;

	if ((proc->bottomArrowFrameIdx >> 3) > 5)
		proc->bottomArrowFrameIdx = 0;
}

ProcPtr StartMenuScrollBar(ProcPtr parent)
{
	return SpawnProc(ProcScr_menu_scroll, parent);
}
