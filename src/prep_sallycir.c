#include "prelude.h"
#include "hardware.h"
#include "proc.h"
#include "prepscreen.h"

EWRAM_OVERLAY(0) struct Win1H sSallyCirWinH_obj[2][160] = {};
EWRAM_OVERLAY(0) struct Win1H *sSallyCirWinH[2] = {};
EWRAM_OVERLAY(0) u16 gPrepUiPal[0x3A] = {};

struct ProcScr CONST_DATA ProcScr_SallyCir1[] = {
	PROC_NAME_DEBUG("SallyCir"),
	PROC_SLEEP(1),
	PROC_CALL(SallyCir1_Init),
	PROC_REPEAT(SallyCir1_Loop),
	PROC_CALL(SallyCir1_End),
	PROC_END,
};

void SallyCir1_HBlank(void)
{
	u16 vcount = REG_VCOUNT;

	if (vcount == 160) {
		struct Win1H *swap;

		vcount = 0;

		swap = sSallyCirWinH[0];
		sSallyCirWinH[0] = sSallyCirWinH[1];
		sSallyCirWinH[1] = swap;
	} else if (vcount > 160)
		vcount = 0;

	REG_WIN1H = ((*sSallyCirWinH + vcount)->left << 8) | (*sSallyCirWinH + vcount)->right;
}

void SallyCir1_Init(struct ProcSallyCir *proc)
{
	u16 i;

	SetWinEnable(0, 1, 0);

	if (proc->direct < 0) {
		proc->pos = 150;

		for (i = 0; i < 160; i++) {
			sSallyCirWinH_obj[0][i].left  = 0;
			sSallyCirWinH_obj[0][i].right = 240;

			sSallyCirWinH_obj[1][i].left  = 0;
			sSallyCirWinH_obj[1][i].right = 240;
		}

		SetWin1Box(0, 0, 240, 160);
	} else {
		proc->pos = 0;

		for (i = 0; i < 160; i++) {
			sSallyCirWinH_obj[0][i].left  = 120;
			sSallyCirWinH_obj[0][i].right = 120;

			sSallyCirWinH_obj[1][i].left  = 120;
			sSallyCirWinH_obj[1][i].right = 120;
		}

		SetWin1Box(120, 0, 120, 160);
	}

	SetWin1Layers(1, 1, 1, 1, 1);
	SetWOutLayers(0, 0, 0, 0, 0);

	proc->timer = 0;

	sSallyCirWinH[0] = sSallyCirWinH_obj[0];
	sSallyCirWinH[1] = sSallyCirWinH_obj[1];

	SetOnHBlankA(SallyCir1_HBlank);
}

void SallyCir1_Loop(struct ProcSallyCir *proc)
{
	i16 i;

	proc->pos += proc->direct;

	LIMIT_AREA(proc->pos, 0, 150);

	for (i = 0; i < 160; i++) {
		i16 distance;
		int var;

		if (proc->pos < 1 ||
			((var = (proc->pos * proc->pos) - ((i - 80) * (i - 80))) < 0)) {
				sSallyCirWinH[1][i].left = 120;
				sSallyCirWinH[1][i].right = 120;
				continue;
			}

			distance = Sqrt(var);
			if (distance > 120)
				distance = 120;

			sSallyCirWinH[1][i].left = 120 - distance;
			sSallyCirWinH[1][i].right = distance + 120;
	}

	proc->timer++;
	if (proc->timer == 40)
		Proc_Break(proc);
}

void SallyCir1_End(struct ProcSallyCir *proc)
{
	SetOnHBlankA(NULL);
}

ProcPtr NewSallyCir1(ProcPtr parent, i8 direct)
{
	struct ProcSallyCir *proc;

	proc = SpawnProcLocking(ProcScr_SallyCir1, parent);
	proc->direct = direct;

	return proc;
}

struct ProcScr CONST_DATA ProcScr_SallyCir2[] = {
	PROC_SLEEP(0),
	PROC_CALL(SallyCir2_Init),
	PROC_SLEEP(0),
	PROC_REPEAT(SallyCir2_Loop),
	PROC_END,
};

void SallyCir2_Init(struct ProcSallyCir *proc)
{
	proc->timer = 0;

	SetDispEnable(1, 1, 1, 1, 1);
	SetWinEnable(0, 1, 0);
	SetWin1Layers(1, 1, 1, 1, 1);
	SetWOutLayers(0, 0, 0, 0, 0);

	if (proc->direct > 0) {
		SetWin1Box(0, 0, 240, 160);
	} else {
		SetWin1Box(120, 80, 120, 80);
	}
}

void SallyCir2_Loop(struct ProcSallyCir *proc)
{
	int a, t;

	proc->timer++;

	SetWinEnable(0, 1, 0);

	a = proc->timer;
	t = ((a * 1280 - (a * 640 * a) / 15) / 15) >> 4;

	if (proc->direct > 0) {
		SetWin1Box(
			t * 3,
			t * 2,
			-16 - t * 3,
			-96 - t * 2);
	} else {
		SetWin1Box(
			120 - t * 3,
			 80 - t * 2,
			120 + t * 3,
			 80 + t * 2
		);
	}

	SetWin1Layers(1, 1, 1, 1, 1);
	SetWOutLayers(0, 0, 0, 0, 0);

	if (t >= 40) {
		Proc_Break(proc);

		if (proc->direct > 0) {
			SetDispEnable(0, 0, 0, 0, 0);
		}
	}
}

ProcPtr NewSallyCir2(ProcPtr parent, i8 direct)
{
	struct ProcSallyCir *proc;

	proc = SpawnProcLocking(ProcScr_SallyCir2, parent);
	proc->direct = direct;

	return proc;
}
