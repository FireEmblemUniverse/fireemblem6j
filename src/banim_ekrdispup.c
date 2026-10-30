#include "prelude.h"
#include "proc.h"
#include "hardware.h"

#include "banim.h"

EWRAM_OVERLAY(banim) struct ProcEkrDispUP *gpProcEkrDispUP = NULL;

struct ProcScr CONST_DATA ProcScr_EkrDispUP[] = {
	PROC_19,
	PROC_REPEAT(EkrDispUP_Loop),
	PROC_END,
};

void NewEkrDispUP(void)
{
	gpProcEkrDispUP = SpawnProc(ProcScr_EkrDispUP, PROC_TREE_5);
	EkrDispUP_SetPositionUnsync(0, 0);
	EkrDispUpClear4C50();
	UnAsyncEkrDispUP();
	UnsyncEkrDispUP();
}

void EndEkrDispUP(void)
{
	Proc_End(gpProcEkrDispUP);
}

void EkrDispUpClear4C50(void)
{
	gpProcEkrDispUP->unk4C = 0;
	gpProcEkrDispUP->unk50 = 0;
}

void EkrDispUpSet4C50(void)
{
	gpProcEkrDispUP->unk4C = 1;
	gpProcEkrDispUP->unk50 = 1;
}

void EkrDispUpSet4C(void)
{
	gpProcEkrDispUP->unk4C = 1;
}

void EkrDispUpSet50(void)
{
	gpProcEkrDispUP->unk50 = 1;
}

void EkrDispUP_SetPositionUnsync(u16 x, u16 y)
{
	gpProcEkrDispUP->x = x; /* unused actually */
	gpProcEkrDispUP->y = y; /* unused actually */
	gpProcEkrDispUP->sync = 0;
}

void EkrDispUP_SetPositionSync(u16 x, u16 y)
{
	gpProcEkrDispUP->x = x; /* unused actually */
	gpProcEkrDispUP->y = y; /* unused actually */
	gpProcEkrDispUP->sync = 1;
}

void SyncEkrDispUP(void)
{
	gpProcEkrDispUP->sync = true;
}

void UnsyncEkrDispUP(void)
{
	gpProcEkrDispUP->sync = false;
}

void AsyncEkrDispUP(void)
{
	gpProcEkrDispUP->asnyc = true;
}

void UnAsyncEkrDispUP(void)
{
	gpProcEkrDispUP->asnyc = false;
}

void EkrDispUP_Loop(struct ProcEkrDispUP *proc)
{
	int val0, iy, height, map_idx, ix1;
	int ix2 = 15; // for matching

	if (proc->asnyc == true)
		return;

	if (proc->sync != false)
		return;

	val0 = (proc->y << 0x10) >> 0x13;
	iy = val0 << 5;
	if (iy < 0)
		iy = 0;

	height = val0 + 7;
	if (height > 6)
		height = 6;

	map_idx = 30 * (6 - height);

	if (gEkrDistanceType >= 0) {
		if (gEkrDistanceType <= 2)
			ix1 = 0;
		else
			goto label;
	} else {
		ix1 = 0; // for matching, can be any value
	label:
		ix1 = 15;
	}

#if FE8
	FillBGRect(gBg0Tm, 30, 7, 0, 128);
#else
	FillBGRect(gBg0Tm, 30, 7, 0, 159);
#endif

	if (height > 0) {
		if (proc->unk4C == 0) { 
			EfxTmCpyBG(&Tsa_EkrDispUP_08112968[map_idx], &gBg0Tm2D[iy][ix1], 15, height, -1, -1);
			FillBGSafelyRect(&gBg0Tm2D[iy][ix1], 15, height, 2, 128);
		}

		if (proc->unk50 == 0) {
			EfxTmCpyBG(&Tsa_EkrDispUP_08112A1C[map_idx], &gBg0Tm2D[iy][ix2], ix2, height, -1, -1);
			FillBGSafelyRect(&gBg0Tm2D[iy][ix2], 15, height, 3, 128);
		}
	}

	EnableBgSync(BG0_SYNC_BIT);
}
