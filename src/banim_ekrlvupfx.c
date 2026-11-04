#include "prelude.h"
#include "proc.h"
#include "hardware.h"

#include "banim.h"

struct ProcScr CONST_DATA ProcScr_EkrlvupSubAnimeEmulator[] = {
	PROC_19,
	PROC_REPEAT(EkrlvupSubAnimeEmulator_Loop),
	PROC_END,
};

ProcPtr NewEkrlvupSubAnimeEmulator(int x, int y, const AnimScr *scr, int act_type)
{
	struct ProcEkrSubAnimeEmulator *proc;

	proc = SpawnProc(ProcScr_EkrlvupSubAnimeEmulator, PROC_TREE_3);

	proc->timer = 0;
	proc->scr_offset = 0;
	proc->act_type = act_type;
	proc->x1 = x;
	proc->y1 = y;
	proc->x2 = 0;
	proc->y2 = 0;
	proc->scr = scr;
	proc->oam2 = 0;

	return proc;
}

void EkrlvupSubAnimeEmulator_Loop(struct ProcEkrSubAnimeEmulator *proc)
{
	struct Anim local_anim;
	const AnimScr *scr = proc->scr;

	if (proc->timer == 0) {
		u32 inst = scr[proc->scr_offset];

		if (BAS_INS_KIND_STOP == ANINS_GET_TYPE(inst)) {
			switch (proc->act_type) {
			case EKR_SUBANIMEMU_ACT_ONE_TURN:
				Proc_Break(proc);
				return;
				break;

			case EKR_SUBANIMEMU_ACT_LOOP:
				proc->timer = 1;
				proc->scr_offset = 0;
				break;

			case EKR_SUBANIMEMU_ACT_END:
				proc->timer = 1;
				proc->scr_offset--;
				break;

			default:
				break;
			}
		} else if (BAS_INS_KIND_WAIT == ANINS_GET_TYPE(inst)) {
			proc->timer = inst;
			proc->scr_offset++;
		} else {
			proc->sprite_data = ANINS_FORCESPRITE_GET_ADDRESS(inst);
			proc->timer = ANINS_FORCESPRITE_GET_DELAY(inst);
			proc->scr_offset++;
		}
	}

	proc->timer--;

	local_anim.oam01 = 0;
	local_anim.sprData = proc->sprite_data;
	local_anim.oam2 = proc->oam2;
	local_anim.xPosition = proc->x1 + proc->x2;
	local_anim.yPosition = proc->y1 + proc->y2;
	local_anim.flags2 = 0;
	BasPutOam(&local_anim);
}

struct ProcScr CONST_DATA ProcScr_EfxPartsofScroll[] = {
	PROC_19,
	PROC_ONEND(EfxPartsofScroll_OnEnd),
	PROC_REPEAT(EfxPartsofScroll_Loop),
	PROC_END,
};

ProcPtr NewEfxPartsofScroll(void)
{
	struct ProcEfx *proc =
		SpawnProc(ProcScr_EfxPartsofScroll, PROC_TREE_3);

	proc->timer = 0;
	proc->step = 0;
	return proc;
}

void EfxPartsofScroll_LoopExt(void)
{
	u32 i;

	u16 *buf1 = (gEkrBg1ScrollFlip == 0)
			? gpBg2ScrollOffsetTable2
			: gpBg2ScrollOffsetTable1;

	u16 *buf2 = (gEkrBg1ScrollFlip == 0)
			? gpBg1ScrollOffsetList2
			: gpBg1ScrollOffsetList1;

	for (i = 0; i < 0xA0; i++) {
		if (i < 0x28) {
			*buf1++ = 0;
			*buf2++ = 0;
			continue;
		}

		if (i <= 0x47) {
			*buf1++ = gEkrLvupScrollPos1;
			*buf2++ = gEkrLvupScrollPos1;
			continue;
		}

		if (i <= 0x9F) {
			*buf1++ = gEkrLvupScrollPos2;
			*buf2++ = gEkrLvupScrollPos2;
			continue;
		}
	}
}

void EfxPartsofScroll_OnEnd(ProcPtr proc)
{
}

void EfxPartsofScroll_Loop(ProcPtr proc)
{
	EfxPartsofScroll_LoopExt();
}

struct ProcScr CONST_DATA ProcScr_EfxPartsofScroll2[] = {
	PROC_19,
	PROC_ONEND(EfxPartsofScroll2_OnEnd),
	PROC_REPEAT(EfxPartsofScroll2_Loop),
	PROC_END,
};

ProcPtr NewEfxPartsofScroll2(void)
{
	struct ProcEfx *proc =
		SpawnProc(ProcScr_EfxPartsofScroll2, PROC_TREE_3);

	proc->timer = 0;
	proc->step = 0;
	return proc;
}

void EfxPartsofScroll2_OnEnd(ProcPtr proc)
{
}

CONST_DATA i16 EfxPartsofScroll2_RefTable[] = {
	-0x100, -0xEE, -0xDD, -0xCC, -0xBB, -0xAA, -0x99, -0x88,
	-0x77, -0x66, -0x55, -0x44, -0x33, -0x22, -0x22, -0x11,
	0x11,  0x22,  0x22,  0x33,  0x44,  0x55,  0x66,  0x77,
	0x88,  0x99,  0xAA,  0xBB,  0xCC,  0xDD,  0xEE, 0x100
};

void EfxPartsofScroll2_Loop(ProcPtr proc)
{
	u16 * buf1 = (gEkrBg1ScrollFlip == 0)
			? gpBg2ScrollOffsetTable2
			: gpBg2ScrollOffsetTable1;

	u16 * buf2 = (gEkrBg1ScrollFlip == 0)
			? gpBg1ScrollOffsetList2
			: gpBg1ScrollOffsetList1;

	u32 i = 0;

	for (; i < 0xA0; i++) {
		const i16 *src = EfxPartsofScroll2_RefTable;
		src = src - 0x28;

		if (i < 0x28) {
			*buf1++ = 0;
			*buf2++ = 0;
			continue;
		}

		if (i <= 0x47) {
			s16 val2 = (src[i] * gEkrLvupScrollPos1) >> 0xC;

			if (i + val2 < 0x2F)
				val2 = -0x20;
			else if (i + val2 >= 0x52)
				val2 = -0x20;

			*buf1++ = val2;
			*buf2++ = val2;
			continue;
		}

		if (i <= 0x9F) {
			*buf1++ = 0;
			*buf2++ = 0;
			continue;
		}
	}
}

struct ProcScr CONST_DATA ProcScr_Efxleveluphb[] = {
	PROC_19,
	PROC_ONEND(Efxleveluphb_OnEnd),
	PROC_REPEAT(Efxleveluphb_Init),
	PROC_REPEAT(Efxleveluphb_Loop),
	PROC_END,
};

ProcPtr NewEfxleveluphb(void)
{
	u32 i;
	struct ProcEfx *proc;
	u16 *buf;

	gEfxBgSemaphore++;

	buf = gpBg2ScrollOffsetTable1;
	for (i = 0; i < 0xA0; i++)
		*buf++ = 0;

	buf = gpBg2ScrollOffsetTable2;
	for (i = 0; i < 0xA0; i++)
		*buf++ = 0;

	buf = gpBg1ScrollOffsetList1;
	for (i = 0; i < 0xA0; i++)
		*buf++ = 0;

	buf = gpBg1ScrollOffsetList2;
	for (i = 0; i < 0xA0; i++)
		*buf++ = 0;

	gEkrBg2ScrollFlip = 0;
	gEkrBg1ScrollFlip = 0;

	buf = gpBg2ScrollOffsetTable1;
	gpBg2ScrollOffsetStart = buf;
	buf = gpBg1ScrollOffsetList1;
	gpBg1ScrollOffsetStart = buf;
	buf = gpBg2ScrollOffsetStart;
	gpBg2ScrollOffset = buf;
	buf = gpBg1ScrollOffsetStart;
	gpBg1ScrollOffset = buf;

	proc = SpawnProc(ProcScr_Efxleveluphb, PROC_TREE_VSYNC);
	proc->timer = 0;
	return proc;
}

void Efxleveluphb_OnEnd(ProcPtr proc)
{
	SetOnHBlankA(NULL);
}

void Efxleveluphb_Init(ProcPtr proc)
{
	Proc_Break(proc);
}

void Efxleveluphb_Loop(ProcPtr proc)
{
#if FE8
	if (gBmSt.main_loop_ended == false) {
		gpBg2ScrollOffset = gpBg2ScrollOffsetStart;
		gpBg1ScrollOffset = gpBg1ScrollOffsetStart;
		return;
	}
#endif

	if (gEkrBg2ScrollFlip == 1) {
		gEkrBg2ScrollFlip = 0;
		gpBg2ScrollOffsetStart = gpBg2ScrollOffsetTable1;
	} else {
		gEkrBg2ScrollFlip = 1;
		gpBg2ScrollOffsetStart = gpBg2ScrollOffsetTable2;
	}

	if (gEkrBg1ScrollFlip == 1) {
		gEkrBg1ScrollFlip = 0;
		gpBg1ScrollOffsetStart = gpBg1ScrollOffsetList1;
	} else {
		gEkrBg1ScrollFlip = 1;
		gpBg1ScrollOffsetStart = gpBg1ScrollOffsetList2;
	}

	gpBg2ScrollOffset = gpBg2ScrollOffsetStart;
	gpBg1ScrollOffset = gpBg1ScrollOffsetStart;
}

void EkrLvupHBlank(void)
{
	if (REG_DISPSTAT & DISPSTAT_VBLANK)
		return;

	REG_BG2HOFS = *gpBg2ScrollOffset++;
	REG_BG1HOFS = *gpBg1ScrollOffset++;
}

void EfxPartsofScroll2HBlank(void)
{
	if (REG_DISPSTAT & DISPSTAT_VBLANK)
		return;

	REG_BG2VOFS = gDispIo.bg_off[2].y + *gpBg2ScrollOffset++;
	REG_BG1VOFS = gDispIo.bg_off[1].y + *gpBg1ScrollOffset++;
}
