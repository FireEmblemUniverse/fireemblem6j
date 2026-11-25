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

		for (ix = 0; ix < 30; ix++)
			(gBg3Tm + row_offset)[ix] = (src + (40 - (iy + 1)) * 30)[ix] + TILEREF(0, 10);
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
		if (++proc->pos == 0x500)
			proc->pos = 0;

		SetBgOffset(BG_3, 0, proc->pos & 0xFF);
		REG_BG3VOFS = proc->pos & 0xFF;

		proc->timer = 0;
	}

	proc->timer++;

	if ((proc->pos % 8) == 0) {
		fu16 ix;

		u16 const *src = Tsa_MonologueScrollingBG;
		u32 dst_row_off = TM_OFFSET(0, TM_WRAP_Y(proc->pos / 8 - 1));
		fu8 src_row = (proc->pos / 8 + 30) % 40;

		for (ix = 0; ix < 30; ix++)
			(gBg3Tm + dst_row_off)[ix] = (src + (40 - (src_row + 1)) * 30)[ix] + TILEREF(0, 10);

		CpuFastCopy(gBg3Tm + dst_row_off, (u16 *)(VRAM + 0x7800) + dst_row_off, 0x3C);
	}
}

void PrepBgScrolling_End(struct Proc_0867968C *proc)
{}

ProcPtr func_fe6_08082560(ProcPtr parent)
{
	return SpawnProc(ProcScr_PrepBgScrolling, PROC_TREE_VSYNC);
}
