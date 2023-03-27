#include "eventfunctions.h"

#include "random.h"
#include "ramfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "talk.h"
#include "event.h"
#include "util.h"
#include "unit.h"
#include "item.h"
#include "bm.h"
#include "bmfx.h"
#include "trap.h"
#include "gold.h"
#include "faction.h"
#include "action.h"
#include "mapselect.h"
#include "chapterinfo.h"
#include "chapterevents.h"
#include "helpbox.h"
#include "save_stats.h"

#include "constants/flags.h"
#include "constants/pids.h"
#include "constants/chapters.h"
#include "constants/msg.h"
#include "constants/videoalloc_global.h"

extern u16 const gUnk_08342A98[]; // colors

extern u8 gUnk_030048A8;
extern u32 EWRAM_DATA gUnk_0203D354;
extern u32 EWRAM_DATA gUnk_0203D358;
extern u8 EWRAM_DATA gUnk_0203D35C;
extern u8 EWRAM_DATA gUnk_0203D35D;

struct HardModeBonusLevelsOverrideEnt
{
    /* 00 */ u8 pid;
    /* 04 */ int bonus_levels;
};

extern struct HardModeBonusLevelsOverrideEnt CONST_DATA gHardModeBonusLevelsOverrideList[];

bool IsHard(void)
{
    if (gPlaySt.flags & PLAY_FLAG_HARD)
        return TRUE;

    return FALSE;
}

int GetHardModeBonusLevelsByPid(fu8 pid)
{
    struct HardModeBonusLevelsOverrideEnt const * it = gHardModeBonusLevelsOverrideList;

    while (it->pid != 0)
    {
        if (it->pid == pid)
            return it->bonus_levels;

        ++it;
    }

    return GetChapterInfo(gPlaySt.chapter)->hard_bonus_levels;
}

void ApplyAllHardModeBonusLevels(void)
{
    if (gPlaySt.flags & PLAY_FLAG_HARD)
    {
        FOR_UNITS_FACTION(FACTION_RED, unit,
        {
            int bonus_levels = GetHardModeBonusLevelsByPid(unit->pinfo->id);

            if (bonus_levels != 0)
                UnitApplyBonusLevels(unit, bonus_levels);
        })
    }
}

bool func_fe6_0806BB34(struct EventInfo * info)
{
    if (CheckFlag(FLAG_CHAPTER11A_10))
        return FALSE;

    if (!IsKleinNonBlue())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BB68(struct EventInfo * info)
{
    if (!CheckFlag(FLAG_CHAPTER11A_7))
        return FALSE;

    if (!IsKleinBlue())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BB9C(struct EventInfo * info)
{
    if (CheckFlag(FLAG_CHAPTER11A_7))
        return FALSE;

    if (!IsKleinBlue())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BBD0(struct EventInfo * info)
{
    if (gPlaySt.turn < 4)
        return FALSE;

    return CheckAnyBlueUnitArea(20, 0, 45, 24);
}

bool func_fe6_0806BBF8(void)
{
    if (gPlaySt.faction != FACTION_BLUE)
        return FALSE;

    if (DivRem(RandNextB(), 11) == 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806BC20(struct EventInfo * info)
{
    if (!IsPercivalBlueDeployed())
        return FALSE;

    if (EventInfoCheckTalk(info, PID_ROY, PID_PERCEVAL))
        return TRUE;

    if (EventInfoCheckTalk(info, PID_PERCEVAL, PID_ROY))
        return TRUE;

    return FALSE;
}

bool func_fe6_0806BC5C(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (!CheckFlag(FLAG_CHAPTER24_4))
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_5))
        return FALSE;

    if ((gPlaySt.turn % 2) != 0)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_17))
        return FALSE;

    return TRUE;
}

bool func_fe6_0806BCA4(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (!CheckFlag(FLAG_CHAPTER24_5))
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_6))
        return FALSE;

    if ((gPlaySt.turn % 2) == 0)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_17))
        return FALSE;

    return TRUE;
}

bool func_fe6_0806BCEC(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (!CheckFlag(FLAG_CHAPTER24_6))
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_7))
        return FALSE;

    if ((gPlaySt.turn % 2) != 0)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_17))
        return FALSE;

    return TRUE;
}

bool func_fe6_0806BD34(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (!CheckFlag(FLAG_CHAPTER24_7))
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_8))
        return FALSE;

    if ((gPlaySt.turn % 2) == 0)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_17))
        return FALSE;

    return TRUE;
}

bool func_fe6_0806BD7C(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (!CheckFlag(FLAG_CHAPTER24_8))
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_9))
        return FALSE;

    if ((gPlaySt.turn % 2) != 0)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_17))
        return FALSE;

    return TRUE;
}

bool func_fe6_0806BDC4(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (!CheckFlag(FLAG_CHAPTER24_9))
        return FALSE;

    if ((gPlaySt.turn % 2) == 0)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_17))
        return FALSE;

    return TRUE;
}

#if BUGFIX
#  define IsKleinNonBlueBugged IsKleinNonBlue
#  define IsKleinBlueBugged IsKleinBlue
#else
#  define IsKleinNonBlueBugged ((int (*)(void))(IsKleinNonBlue))
#  define IsKleinBlueBugged ((int (*)(void))(IsKleinBlue))
#endif

bool Chapter10B_CheckTalkShannaThea(struct EventInfo * info)
{
    if (CheckFlag(FLAG_CHAPTER10B_8))
        return FALSE;

    if (!IsKleinNonBlueBugged())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool Chapter10B_CheckTalkShannaTheaAfterKlein(struct EventInfo * info)
{
    if (CheckFlag(FLAG_CHAPTER10B_5))
        return FALSE;

    if (!IsKleinBlueBugged())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool Chapter10B_CheckShannaRecruitsThea(struct EventInfo * info)
{
    if (!CheckFlag(FLAG_CHAPTER10B_5))
        return FALSE;

    if (!IsKleinBlueBugged())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

#undef IsKleinBlueBugged
#undef IsKleinNonBlueBugged

bool func_fe6_0806BE90(struct EventInfo * info)
{
    if (!IsDouglasNonBlue())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BEB8(struct EventInfo * info)
{
    if (!CheckFlag(9)) // TODO: which chapter?
        return FALSE;

    if (IsDouglasNonBlue())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BEEC(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    return func_fe6_0806AE7C(10, 14, 10, 14);
}

bool func_fe6_0806BF14(struct EventInfo * info)
{
    if (!CheckFlag(FLAG_CHAPTER_BASE))
        return FALSE;

    if (IsPidNonBlue(PID_UNKNOWN_DA))
        return FALSE;

    return TRUE;
}

bool IsGuinivereAround(void)
{
    if (gPlaySt.chapter > CHAPTER_12)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_2)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_3)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_4)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_5)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_6)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_7)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_8)
        return TRUE;

    // NOTE: this last check is useless, CHAPTER_8X (=0x20) is greater than CHAPTER_12 (=0x0C)
    if (gPlaySt.chapter == CHAPTER_8X)
        return TRUE;

    return FALSE;
}

void func_fe6_0806BF70(void)
{
    SoftReset(GBA_RESET_ALL & ~GBA_RESET_EWRAM);
}

bool func_fe6_0806BF7C(void)
{
    if (gKeySt->pressed & KEY_BUTTON_A)
        return FALSE;

    return TRUE;
}

void func_fe6_0806BF98(void)
{
    SoftReset(GBA_RESET_ALL & ~GBA_RESET_EWRAM);
}

bool func_fe6_0806BFA4(void)
{
    if (gKeySt->pressed & KEY_BUTTON_A)
        return TRUE;

    return FALSE;
}

void RemoveFog(void)
{
    SetFogVision(0);
}

void AddFiveThousandGold(void)
{
    SetGold(GetGold() + 5000);
}

void RemoveGold(int gold_amount)
{
    if (GetGold() >= gold_amount)
    {
        SetGold(GetGold() - gold_amount);
    }
}

void WeakenUnitStats(struct Unit * unit)
{
    if (unit->max_hp > 0)
        unit->max_hp--;

    if (unit->pow > 0)
        unit->pow--;

    if (unit->skl > 0)
        unit->skl--;

    if (unit->spd > 0)
        unit->spd--;

    if (unit->def > 0)
        unit->def--;

    if (unit->res > 0)
        unit->res--;

    if (unit->lck > 0)
        unit->lck--;
}

void WeakenUnitStatsByPid(fu8 pid)
{
    WeakenUnitStats(GetUnitByPid(pid));
}

bool IsPidBlueDeployed(fu8 pid)
{
    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->flags & (UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED))
            continue;

        if (UNIT_PID(unit) == pid)
            return TRUE;
    })

    return FALSE;
}

bool IsLilinaBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_LILINA);
}

bool IsMarcusBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_MARCUS);
}

bool IsMerlinusBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_MERLINUS);
}

bool IsJunoBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_JUNO);
}

bool IsZelotBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_ZELOT);
}

bool IsSinBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_SIN);
}

bool IsDayanBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_DAYAN);
}

bool IsSueBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_SUE);
}

bool IsMeladyBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_MELADY);
}

bool IsZeissBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_ZEISS);
}

bool IsPercivalBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_PERCEVAL);
}

bool IsPidBlue(fu8 pid)
{
    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        if (UNIT_PID(unit) == pid)
            return TRUE;
    })

    return FALSE;
}

bool IsBorsBlue(void)
{
    return IsPidBlue(PID_BORS);
}

bool IsLilinaBlue(void)
{
    return IsPidBlue(PID_LILINA);
}

bool IsElenBlue(void)
{
    return IsPidBlue(PID_ELEN);
}

bool IsRaighBlue(void)
{
    return IsPidBlue(PID_RAIGH);
}

bool IsSueBlue(void)
{
    return IsPidBlue(PID_SUE);
}

bool IsCathBlue(void)
{
    return IsPidBlue(PID_CATH);
}

bool IsMeladyBlue(void)
{
    return IsPidBlue(PID_MELADY);
}

bool IsZeissBlue(void)
{
    return IsPidBlue(PID_ZEISS);
}

bool IsSophiaBlue(void)
{
    return IsPidBlue(PID_SOPHIA);
}

bool IsJunoBlue(void)
{
    return IsPidBlue(PID_JUNO);
}

bool IsZelotBlue(void)
{
    return IsPidBlue(PID_ZELOT);
}

bool IsElffinBlue(void)
{
    return IsPidBlue(PID_ELFFIN);
}

bool IsFaeBlue(void)
{
    return IsPidBlue(PID_FAE);
}

bool IsSinBlue(void)
{
    return IsPidBlue(PID_SIN);
}

bool IsDayanBlue(void)
{
    return IsPidBlue(PID_DAYAN);
}

bool IsKleinBlue(void)
{
    return IsPidBlue(PID_KLEIN);
}

bool IsTheaBlue(void)
{
    return IsPidBlue(PID_THEA);
}

bool IsDouglasBlue(void)
{
    return IsPidBlue(PID_DOUGLAS);
}

bool func_fe6_0806C2C4(void)
{
    FOR_UNITS(FACTION_GREEN + 1, FACTION_RED + 0x40, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        return TRUE;
    })

    return FALSE;
}

bool func_fe6_0806C2F8(void)
{
    return func_fe6_0806C2C4() ? FALSE : TRUE;
}

bool IsPidNonBlue(fu8 pid)
{
    FOR_UNITS(FACTION_GREEN + 1, FACTION_RED + 0x40, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        if (unit->pinfo->id == pid)
            return TRUE;
    })

    return FALSE;
}

bool IsTheaNonBlue(void)
{
    return IsPidNonBlue(PID_THEA);
}

bool func_fe6_0806C35C(void)
{
    return IsPidNonBlue(PID_UNKNOWN_5E);
}

bool IsKleinNonBlue(void)
{
    return IsPidNonBlue(PID_KLEIN);
}

bool IsCathNonBlue(void)
{
    return IsPidNonBlue(PID_CATH);
}

bool IsHughNonBlue(void)
{
    return IsPidNonBlue(PID_HUGH);
}

bool IsGalleNonBlue(void)
{
    return IsPidNonBlue(PID_GALLE);
}

bool func_fe6_0806C3AC(void)
{
    return IsPidNonBlue(PID_UNKNOWN_C4);
}

bool func_fe6_0806C3BC(void)
{
    return IsPidNonBlue(PID_UNKNOWN_C6);
}

bool IsDouglasNonBlue(void)
{
    return IsPidNonBlue(PID_DOUGLAS);
}

bool IsPercevalNonBlue(void)
{
    return IsPidNonBlue(PID_PERCEVAL);
}

bool func_fe6_0806C3EC(void)
{
    return IsPidNonBlue(PID_UNKNOWN_D5);
}

bool func_fe6_0806C3FC(void)
{
    return IsPidNonBlue(PID_UNKNOWN_D6);
}

bool func_fe6_0806C40C(void)
{
    return IsPidNonBlue(PID_UNKNOWN_D7);
}

int func_fe6_0806C41C(fu8 pid, int faction)
{
    int count = 0;

    FOR_UNITS_FACTION(faction, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        if (unit->pinfo->id == pid)
            count++;
    })

    return count;
}

int func_fe6_0806C460(int faction)
{
    int count = 0;

    FOR_UNITS_FACTION(faction, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        count++;
    })

    return count;
}

bool IsPastTurn20(void)
{
    if (gPlaySt.turn > 20)
        return TRUE;

    return FALSE;
}

bool IsPastTurn25(void)
{
    if (gPlaySt.turn > 25)
        return TRUE;

    return FALSE;
}

bool IsPastTurn30(void)
{
    if (gPlaySt.turn > 30)
        return TRUE;

    return FALSE;
}

bool IsBluePhase(void)
{
    if (gPlaySt.faction != FACTION_BLUE)
        return FALSE;

    return TRUE;
}

bool IsRedPhase(void)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    return TRUE;
}

bool IsActiveUnitMale(void)
{
    // hm
    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_FEMALE)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806C524(void)
{
    if (GetGold() < 10000)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806C540(void)
{
    if (GetGold() < 8000)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806C55C(void)
{
    if (GetGold() < 6000)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806C578(void)
{
    if (GetGold() < 5000)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806C594(void)
{
    if (GetTalkChoiceResult() == 1) // TODO: talk choice constants
        return TRUE;

    return FALSE;
}

bool AreWeGoingToSacae(void)
{
    struct PidStats * stats;
    u32 sacae, ilia;

    stats = GetPidStats(PID_SUE);
    sacae = stats->exp_gained;

    stats = GetPidStats(PID_SIN);
    sacae = stats->exp_gained + sacae;

    stats = GetPidStats(PID_THEA);
    ilia = stats->exp_gained;

    stats = GetPidStats(PID_SHANNA);
    ilia = stats->exp_gained + ilia;

    if (sacae > ilia)
        return TRUE;

    return FALSE;
}

void func_fe6_0806C608(void)
{
    if (gPlaySt.flags & PLAY_FLAG_TUTORIAL || !gPlaySt.config_bgm_disable)
        FadeBgmOut(4);
}

bool func_fe6_0806C62C(void)
{
    if (gPlaySt.flags & PLAY_FLAG_COMPLETE)
        return TRUE;

    if (gPlaySt.flags & PLAY_FLAG_TUTORIAL)
        return TRUE;

    return FALSE;
}

void func_fe6_0806C64C(void)
{
    u32 unk;

    gUnk_030048A8 = 0;
    ClearFlag(FLAG_TUTORIAL_22);
    unk = func_fe6_0802BA08();
    gUnk_0203D358 = unk;
}

void func_fe6_0806C670(void)
{
    if (gUnk_030048A8 == 0)
    {
        gUnk_030048A8++;
        FreezeMenu();
    }
}

bool func_fe6_0806C68C(void)
{
    return gUnk_030048A8;
}

void func_fe6_0806C69C(void)
{
    gUnk_030048A8 = 0;
    ResumeMenu();
}

void func_fe6_0806C6B0(void)
{
    u32 unk = func_fe6_0802B9DC();
    gUnk_0203D354 = unk;

    switch (UNIT_PID(gActiveUnit))
    {
        case PID_ROY:
            StartEvent(gUnk_0866AF5C);
            break;

        case PID_WOLT:
            StartEvent(gUnk_0866AFEC);
            break;

        case PID_LILINA:
            StartEvent(gUnk_0866B07C);
            break;

        case PID_ALEN:
            StartEvent(gUnk_0866B10C);
            break;
    }
}

void func_fe6_0806C718(void)
{
    if (!CheckFlag(FLAG_TUTORIAL_9))
        StartEvent(gUnk_0866AEA8);
}

void func_fe6_0806C734(void)
{
    if (!CheckFlag(FLAG_TUTORIAL_10))
        StartEvent(gUnk_0866AEE0);
}

void func_fe6_0806C750(void)
{
    if (!CheckFlag(FLAG_TUTORIAL_11))
        StartEvent(gUnk_0866AF28);
}

void func_fe6_0806C76C(int a, int b, int c)
{
    int var = Interpolate(INTERPOLATE_SQUARE, a, b, c, 8);

    CpuFastCopy(gUnk_08342A98, gPal + 0x12 * 0x10, 0x10 * sizeof(u16));
    func_fe6_0805B644(gPal, 18, 1, var);
    EnablePalSync();
}

void func_fe6_0806C7BC(struct TutorialEventProcA * proc)
{
    proc->unk_64 = 0;
    proc->unk_66 = 0;
    ApplyPalette(gUnk_08342A98, 0x12);
}

void func_fe6_0806C7E0(struct TutorialEventProcA * proc)
{
    int x, y, r4;

    switch (gUnk_0203D35D)
    {
        case 0:
            for (r4 = 0; r4 < gUnk_0203D35C; r4++)
            {
                struct SelectTarget * target = GetTarget(r4);

                x = (target->x * 16) - gBmSt.camera.x;
                y = (target->y * 16) - gBmSt.camera.y;

                PutOamHiRam(OAM1_X(x + 0x200), OAM0_Y(y + 0x100), Sprite_0866ACCC, OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 0x22) + OAM2_PAL(2) + OAM2_LAYER(2));
            }

            break;

        case 1:
            x = 0xD0 - gBmSt.camera.x;
            y = 0x70 - gBmSt.camera.y;
            PutOamHiRam(OAM1_X(x + 0x200), OAM0_Y(y + 0x100), Sprite_0866ACCC, OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 0x22) + OAM2_PAL(2) + OAM2_LAYER(2));
            break;

        case 2:
            x = 0x160 - gBmSt.camera.x;
            y = 0x40 - gBmSt.camera.y;
            PutOamHiRam(OAM1_X(x + 0x200), OAM0_Y(y + 0x100), Sprite_0866ACCC, OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 0x22) + OAM2_PAL(2) + OAM2_LAYER(2));
            break;

    }

    if ((GetGameTime() & 1) == 0)
    {
        if (proc->unk_66 != 0)
        {
            func_fe6_0806C76C(0x10, 0, proc->unk_64);

            if (++proc->unk_64 > 8)
            {
                proc->unk_64 = 0;
                proc->unk_66 = 0;
            }
        }
        else
        {
            func_fe6_0806C76C(0, 0x10, proc->unk_64);

            if (++proc->unk_64 > 8)
            {
                proc->unk_64 = 0;
                proc->unk_66 = 1;
            }
        }
    }
}

void func_fe6_0806C948(struct TutorialEventProcB * proc)
{
    proc->unk_64 = 60;
}

void func_fe6_0806C950(struct TutorialEventProcB * proc)
{
    if (--proc->unk_64 != 0)
    {
        if (func_fe6_080718E0())
            return;

        if (!(gKeySt->pressed & KEY_BUTTON_R))
            return;
    }

    Proc_EndEach(ProcScr_Unk_0866ACE8);
    Proc_Break(proc);
}

void func_fe6_0806C998(int what)
{
    gUnk_0203D35D = what;

    func_fe6_0802BA44(gActiveUnit);
    gUnk_0203D35C = CountTargets();

    if (gUnk_0203D35C != 0)
    {
        struct SelectTarget * target;

        SpawnProc(ProcScr_Unk_0866ACE8, PROC_TREE_3);

        target = GetTarget(0);
        CameraMoveWatchPosition(NULL, target->x, target->y);
        SetMapCursorPosition(gActiveUnit->x, gActiveUnit->y);
    }
}

bool func_fe6_0806C9F8(void)
{
    bool result = func_fe6_080718E0();

    if (!result)
        SpawnProc(ProcScr_Unk_0866AD00, PROC_TREE_3);

    return result;
}

void func_fe6_0806CA1C(void)
{
    func_fe6_08071B80(16, 104, MSG_019, NULL);
}

void func_fe6_0806CA30(void)
{
    func_fe6_08071B80(16, 104, MSG_01A, NULL);
}

void func_fe6_0806CA44(void)
{
    func_fe6_08071B80(16, 104, MSG_01E, NULL);
}

void func_fe6_0806CA58(void)
{
    func_fe6_08071B80(16, 104, MSG_01F, NULL);
}

void func_fe6_0806CA6C(void)
{
    func_fe6_08071B80(16, 104, MSG_020, NULL);
    func_fe6_0806C998(0);
}

void func_fe6_0806CA84(void)
{
    func_fe6_08071B80(16, 104, MSG_023, NULL);
}

void func_fe6_0806CA98(void)
{
    func_fe6_08071B80(16, 104, MSG_024, NULL);
}

void func_fe6_0806CAAC(void)
{
    func_fe6_08071B80(16, 104, MSG_025, NULL);
    func_fe6_0806C998(0);
}

void func_fe6_0806CAC4(void)
{
    func_fe6_08071B80(16, 104, MSG_029, NULL);
}

void func_fe6_0806CAD8(void)
{
    func_fe6_08071B80(16, 104, MSG_02A, NULL);
}

void func_fe6_0806CAEC(void)
{
    func_fe6_08071B80(40, 104, MSG_02B, NULL);
}

void func_fe6_0806CB00(void)
{
    func_fe6_08071B80(16, 16, MSG_02D, NULL);
    func_fe6_0806C998(1);
}

void func_fe6_0806CB18(void)
{
    func_fe6_08071B80(16, 56, MSG_02E, NULL);
}

void func_fe6_0806CB2C(void)
{
    func_fe6_08071B80(16, 16, MSG_030, NULL);
}

void func_fe6_0806CB40(void)
{
    func_fe6_08071B80(16, 104, MSG_045, NULL);
}

void func_fe6_0806CB54(void)
{
    func_fe6_08071B80(16, 104, MSG_01B, NULL);
    func_fe6_0806C998(0);
}

void func_fe6_0806CB6C(void)
{
    func_fe6_08071B80(16, 104, MSG_040, NULL);
}

void func_fe6_0806CB80(void)
{
    func_fe6_08071B80(16, 104, MSG_03F, NULL);
}

void func_fe6_0806CB94(void)
{
    func_fe6_08071B80(16, 104, MSG_03E, NULL);
}

void func_fe6_0806CBA8(void)
{
    func_fe6_08071B80(16, 104, MSG_042, NULL);
}

void func_fe6_0806CBBC(void)
{
    switch (UNIT_PID(gActiveUnit))
    {
        case PID_ROY:
        case PID_ALEN:
            func_fe6_08071B80(16, 104, MSG_01C, NULL);
            break;

        case PID_WOLT:
            func_fe6_08071B80(16, 104, MSG_021, NULL);
            break;

        case PID_LILINA:
            func_fe6_08071B80(16, 104, MSG_026, NULL);
            break;
    }
}

bool IsActiveUnitRoy(void)
{
    return (UNIT_PID(gActiveUnit) == PID_ROY) ? TRUE : FALSE;
}

bool IsActiveUnitWolt(void)
{
    return (UNIT_PID(gActiveUnit) == PID_WOLT) ? TRUE : FALSE;
}

bool IsActiveUnitLilina(void)
{
    return (UNIT_PID(gActiveUnit) == PID_LILINA) ? TRUE : FALSE;
}

bool IsActiveUnitAlen(void)
{
    return (UNIT_PID(gActiveUnit) == PID_ALEN) ? TRUE : FALSE;
}

bool func_fe6_0806CC68(void)
{
    if ((gUnk_0203D354 & 2) != 0)
        return TRUE;

    return FALSE;
}

bool IsCombatAction(void)
{
    return gAction.id == ACTION_COMBAT ? TRUE : FALSE;
}

bool func_fe6_0806CC94(void)
{
    if (CheckFlag(FLAG_TUTORIAL_22))
        return FALSE;

    if (gAction.id == ACTION_VISIT)
    {
        SetFlag(FLAG_TUTORIAL_22);
        return TRUE;
    }

    return FALSE;
}

bool func_fe6_0806CCC0(void)
{
    return FALSE;
}

void func_fe6_0806CCC4(void)
{
    if (CheckFlag(FLAG_TUTORIAL_18))
        return;

    if (CheckFlag(FLAG_TUTORIAL_19))
        SetFlag(FLAG_TUTORIAL_18);
}

bool IsAnyTutorialUnitDamaged(void)
{
    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (UNIT_PID(unit) == PID_ROY || UNIT_PID(unit) == PID_WOLT || UNIT_PID(unit) == PID_LILINA || UNIT_PID(unit) == PID_ALEN)
        {
            if (GetUnitCurrentHp(unit) < GetUnitMaxHp(unit))
                return TRUE;
        }
    })

    return FALSE;
}

bool IsAnyTutorialUnitPastColumn16(void)
{
    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (UNIT_PID(unit) == PID_ROY || UNIT_PID(unit) == PID_WOLT || UNIT_PID(unit) == PID_LILINA || UNIT_PID(unit) == PID_ALEN)
        {
            if (unit->x > 16)
                return TRUE;
        }
    })

    return FALSE;
}

bool IsBossDefeated(void)
{
    FOR_UNITS(FACTION_GREEN + 1, FACTION_RED + 0x40, unit,
    {
        if (unit->pinfo->attributes & UNIT_ATTR_BOSS)
            return FALSE;
    })

    return TRUE;
}

bool IsPastTurn1(void)
{
    if (gPlaySt.turn > 1)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CDC0(void)
{
    switch (UNIT_PID(gActiveUnit))
    {
        case PID_ROY:
        case PID_ALEN:
            if (CheckFlag(FLAG_TUTORIAL_14))
                return FALSE;

            break;

        case PID_WOLT:
            if (CheckFlag(FLAG_TUTORIAL_15))
                return FALSE;

            break;

        case PID_LILINA:
            if (CheckFlag(FLAG_TUTORIAL_16))
                return FALSE;

            break;
    }

    if ((gUnk_0203D358 & 2) != 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CE18(void)
{
    if ((gUnk_0203D358 & 0x8000) != 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CE34(void)
{
    if ((gUnk_0203D358 & 0x10000) != 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CE50(void)
{
    if (CheckFlag(FLAG_TUTORIAL_18))
        return FALSE;

    if ((gUnk_0203D358 & 0x18002) != 0)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806CE80(void)
{
    if (CheckFlag(FLAG_TUTORIAL_20))
        return FALSE;

    if ((gUnk_0203D358 & 0x100) != 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CEAC(void)
{
    if (CheckFlag(FLAG_TUTORIAL_21))
        return FALSE;

    if ((gUnk_0203D358 & 0x800000) != 0)
        return TRUE;

    return FALSE;
}

void RefreshClarine(void)
{
    GetUnitByPid(PID_CLARINE)->flags &= ~UNIT_FLAG_TURN_ENDED;
}

bool func_fe6_0806CEF0(void)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER6_6))
        return TRUE;

    if (CheckFlag(FLAG_CHAPTER6_5))
        SetFlag(FLAG_CHAPTER6_6);

    if (CheckFlag(FLAG_CHAPTER6_4))
        SetFlag(FLAG_CHAPTER6_5);

    return FALSE;
}

bool func_fe6_0806CF3C(void)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER6_10))
        return TRUE;

    if (CheckFlag(FLAG_CHAPTER6_9))
        SetFlag(FLAG_CHAPTER6_10);

    if (CheckFlag(FLAG_CHAPTER6_8))
        SetFlag(FLAG_CHAPTER6_9);

    return FALSE;
}

void Chapter8_WeakenNorthWestWall(void)
{
    // set wall hp to 10

    struct Trap * trap = GetTrapAt(6, 1);

    if (trap != NULL)
        trap->extra = 10;
}
