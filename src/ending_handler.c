#include "prelude.h"
#include "proc.h"
#include "hardware.h"
#include "faction.h"
#include "bmio.h"
#include "sound.h"
#include "mu.h"
#include "eventfunctions.h"
#include "playrank.h"
#include "ending.h"

#include "constants/songs.h"

bool CheckGameEndingDone(void)
{
	if (gEndingDoneFlag <= 1)
		return true;

	return false;
}

struct ProcScr CONST_DATA ProcScr_Ending[] = {
	PROC_19,
	PROC_CALL(LockGame),
	PROC_CALL(LockBmDisplay),
	PROC_CALL(Ending_Init),
	PROC_REPEAT(Ending_Loop),
	PROC_CALL(UnlockGame),
	PROC_END,
};

void Ending_Init(struct ProcGameEnding *proc)
{
	proc->timer = 0;
	EndAllMus();
}

void Ending_Loop(struct ProcGameEnding *proc)
{
	u32 ctrl;

	switch (proc->timer) {
	case 0:
		gGameEndingFlag = 0;
		if (func_fe6_08090630() == 1) {
			proc->timer = 2;
			return;
		}

		ctrl = (u32)gCreditInfo[gCreditInfoDispStep].job;
		if (ctrl == 1) {
			if (gEndingDispType != ENDING_DISP_0)
				SpawnProcLocking(ProcScr_EndingStep1_PutFighterMonologue, proc);
		} else if (ctrl == 2) {
			if (PopNextEndingPerson() < (FACTION_BLUE + 0x40) && gEndingDispType != ENDING_DISP_0)
				SpawnProcLocking(ProcScr_EndingPInfo_x1, proc);
			else if (CheckDisplayEndingCG())
				SpawnProcLocking(ProcScr_EndingCG, proc);

			gGameEndingFlag |= GAME_ENDING_FLAG1;
		} else
			SpawnProcLocking(ProcScr_EndingCredit, proc);

		gGameEndingFlag |= GAME_ENDING_FLAG0;
		proc->timer = 1;
		break;

	case 1:
		if (gGameEndingFlag & GAME_ENDING_FLAG0)
			gCreditInfoDispStep++;
		if (gGameEndingFlag & GAME_ENDING_FLAG1)
			gEndingCgIndex++;

		proc->timer = 0;
		break;

	case 2:
		SpawnProcLocking(ProcScr_EndingCopyRight, proc);
		proc->timer++;
		break;

	case 3:
		EndEndingBgmLooper();
		SpawnProcLocking(ProcScr_PlayRank, proc);
		proc->timer++;
		break;

	case 4:
		StartBgm(SONG_36, NULL);
		SetupEndingPInfo2Uids();
		proc->timer++;

		/* fallthrough */

	case 5:
		if (PopNextEnding2Person(POS_L) < (FACTION_BLUE + 0x40)) {
			SpawnProcLocking(ProcScr_EndingPInfo_x2, proc);
			return;
		}
		proc->timer++;
		break;

	case 6:
		SpawnProcLocking(ProcScr_Fin, proc);

		/* fallthrough */

	case 7:
		Proc_Break(proc);
		break;
	}
}

void StartGameEnding(ProcPtr parent)
{
	SpawnProcLocking(ProcScr_Ending, parent);
}

struct ProcScr CONST_DATA ProcScr_GameCredit[] = {
	PROC_19,
	PROC_CALL(GameCredit_Init),
	PROC_REPEAT(GameCredit_Loop),
	PROC_END,
};

void GameCredit_Loop(struct ProcGameCredit *proc)
{
	u32 ctrl = (u32)gCreditInfo[gCreditInfoDispStep].job - 1;

	if (ctrl <= 1) {
		gCreditInfoDispStep++;
		return;
	}

	switch (proc->timer) {
	case 0x3C:
		EndingCredit_PutJobName(gCreditInfoDispStep);
		func_fe6_0809058C();
		proc->timer++;
		break;

	case 0x1A4:
		func_fe6_0809060C();
		proc->timer++;
		break;

	case 0x21C:
			proc->timer = 0;
			gCreditInfoDispStep++;
		if (gEndingDoneFlag) {

			TmFill(gBg0Tm, 0);
			TmFill(gBg1Tm, 0);
			EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
			Proc_Break(proc);
			TriggerEndingDone();
		}
		break;

	case 0xB4:
	default:
		proc->timer++;
		break;
	}

	func_fe6_0808FFE0(proc, gCreditInfoDispStep);
}

void StartGameCredit(void)
{
	SpawnProc(ProcScr_GameCredit, PROC_TREE_3);
}
