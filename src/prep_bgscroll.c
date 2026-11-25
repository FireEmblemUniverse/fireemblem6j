#include "prelude.h"
#include "hardware.h"
#include "proc.h"
#include "prepscreen.h"

struct ProcScr CONST_DATA ProcScr_PrepBgScrolling[] =
{
    PROC_SLEEP(0),
    PROC_CALL(PrepBgScrolling_Init),
    PROC_SLEEP(0),
    PROC_REPEAT(PrepBgScrolling_Loop),
PROC_LABEL(0),
    PROC_CALL(PrepBgScrolling_End),
    PROC_END,
};

void PrepBgScrolling_Init(struct Proc_0867968C *proc)
{
	fu16 ix, iy;
	u16 const *src;

	TmFill(gBg3Tm, 0);

	src = Tsa_MonologueScrollingBG;

	for (iy = 0; iy < 32; iy++) {
		u32 row_offset = TM_OFFSET(0, iy);

		for (ix = 0; ix < MONOLOGUE_BG_WIDTH; ix++)
			(gBg3Tm + row_offset)[ix] = (src + (MONOLOGUE_BG_HEIGHT - (iy + 1)) * MONOLOGUE_BG_WIDTH)[ix] + TILEREF(0, BGPAL_PREP_BGSCROLL);
	}

	EnableBgSync(BG3_SYNC_BIT);

	proc->pos = 0;
	SetBgOffset(BG_3, 0, proc->pos & 0xFF);
	REG_BG3VOFS = proc->pos & 0xFF;

	proc->timer = 0;
	proc->pos = 0;
}

void PrepBgScrolling_Loop(struct Proc_0867968C *proc)
{
	if (proc->timer == 3) {
		if (++proc->pos == MONOLOGUE_BG_SCROLL_WRAP)
			proc->pos = 0;

		SetBgOffset(BG_3, 0, proc->pos & 0xFF);
		REG_BG3VOFS = proc->pos & 0xFF;

		proc->timer = 0;
	}

	proc->timer++;

	if ((proc->pos % 8) == 0) {
		fu16 ix;

		u16 const *src = Tsa_MonologueScrollingBG;
		u32 dst_row_off = TM_OFFSET(0, (proc->pos / 8 - 1) & 0x1F);
		// BUG: the rewritten row next shows 31 rows down, so TSA row 30 repeats on the first pass
#if BUGFIX
		fu8 src_row = (proc->pos / 8 - 1 + 32) % MONOLOGUE_BG_HEIGHT;
#else
		fu8 src_row = (proc->pos / 8 + 30) % MONOLOGUE_BG_HEIGHT;
#endif

		for (ix = 0; ix < MONOLOGUE_BG_WIDTH; ix++)
			(gBg3Tm + dst_row_off)[ix] = (src + (MONOLOGUE_BG_HEIGHT - (src_row + 1)) * MONOLOGUE_BG_WIDTH)[ix] + TILEREF(0, BGPAL_PREP_BGSCROLL);

		CpuFastCopy(gBg3Tm + dst_row_off, (u16 *)BG_SCREEN_ADDR(15) + dst_row_off, MONOLOGUE_BG_WIDTH * sizeof(u16));
	}
}

void PrepBgScrolling_End(struct Proc_0867968C *proc)
{}

ProcPtr StartPrepBgScrolling(ProcPtr parent)
{
	return SpawnProc(ProcScr_PrepBgScrolling, PROC_TREE_VSYNC);
}
