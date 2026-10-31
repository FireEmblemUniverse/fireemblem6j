#include "eventfunctions.h"

#include "random.h"
#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "talk.h"
#include "event.h"
#include "msg.h"
#include "util.h"
#include "gamecontroller.h"
#include "unit.h"
#include "item.h"
#include "map.h"
#include "unitsprite.h"
#include "supply.h"
#include "battle.h"
#include "bm.h"
#include "bmfx.h"
#include "bmio.h"
#include "support.h"
#include "chapter.h"
#include "trap.h"
#include "gold.h"
#include "faction.h"
#include "action.h"
#include "itemaction.h"
#include "mapselect.h"
#include "mu.h"
#include "manim.h"
#include "ui.h"
#include "chapterinfo.h"
#include "chapterevents.h"
#include "helpbox.h"
#include "mapui.h"
#include "save_stats.h"
#include "banim.h"
#include "opanim.h"
#include "ending.h"
#include "ending_monologue.h"
#include "chapterunits.h"

#include "constants/flags.h"
#include "constants/pids.h"
#include "constants/jids.h"
#include "constants/iids.h"
#include "constants/chapters.h"
#include "constants/msg.h"
#include "constants/songs.h"
#include "constants/videoalloc_global.h"

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

    if (EventRandNext_N(11) == 0)
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
    gTutorialActionsInPlace = unk;
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
    gTutorialActionsAfterMove = unk;

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

    CpuFastCopy(Pal_08342A98, gPal + 0x12 * 0x10, 0x10 * sizeof(u16));
    EfxPalWhiteInOut(gPal, 18, 1, var);
    EnablePalSync();
}

void func_fe6_0806C7BC(struct TutorialEventProcA * proc)
{
    proc->unk_64 = 0;
    proc->unk_66 = 0;
    ApplyPalette(Pal_08342A98, 0x12);
}

void func_fe6_0806C7E0(struct TutorialEventProcA * proc)
{
    int x, y, r4;

    switch (gTutorialPointerKind)
    {
        case 0:
            for (r4 = 0; r4 < gTutorialTargetCount; r4++)
            {
                struct SelectTarget * target = GetTarget(r4);

                x = (target->x * 16) - gBmSt.camera.x;
                y = (target->y * 16) - gBmSt.camera.y;

                PutOamHi(OAM1_X(x + 0x200), OAM0_Y(y + 0x100), Sprite_0866ACCC, OAM2_CHR(OBCHR_SYSTEM_OBJECTS + 0x22) + OAM2_PAL(2) + OAM2_LAYER(2));
            }

            break;

        case 1:
            x = 0xD0 - gBmSt.camera.x;
            y = 0x70 - gBmSt.camera.y;
            PutOamHi(OAM1_X(x + 0x200), OAM0_Y(y + 0x100), Sprite_0866ACCC, OAM2_CHR(OBCHR_SYSTEM_OBJECTS + 0x22) + OAM2_PAL(2) + OAM2_LAYER(2));
            break;

        case 2:
            x = 0x160 - gBmSt.camera.x;
            y = 0x40 - gBmSt.camera.y;
            PutOamHi(OAM1_X(x + 0x200), OAM0_Y(y + 0x100), Sprite_0866ACCC, OAM2_CHR(OBCHR_SYSTEM_OBJECTS + 0x22) + OAM2_PAL(2) + OAM2_LAYER(2));
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
    gTutorialPointerKind = what;

    func_fe6_0802BA44(gActiveUnit);
    gTutorialTargetCount = CountTargets();

    if (gTutorialTargetCount != 0)
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
    if ((gTutorialActionsAfterMove & 2) != 0)
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

    if ((gTutorialActionsInPlace & 2) != 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CE18(void)
{
    if ((gTutorialActionsInPlace & 0x8000) != 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CE34(void)
{
    if ((gTutorialActionsInPlace & 0x10000) != 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CE50(void)
{
    if (CheckFlag(FLAG_TUTORIAL_18))
        return FALSE;

    if ((gTutorialActionsInPlace & 0x18002) != 0)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806CE80(void)
{
    if (CheckFlag(FLAG_TUTORIAL_20))
        return FALSE;

    if ((gTutorialActionsInPlace & 0x100) != 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CEAC(void)
{
    if (CheckFlag(FLAG_TUTORIAL_21))
        return FALSE;

    if ((gTutorialActionsInPlace & 0x800000) != 0)
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

void func_fe6_0806CFA0(void)
{
    m4aMPlayStart(&gMusicPlayer_MainBgm, &song_028);
}

void func_fe6_0806CFB8(void)
{
    m4aMPlayStart(&gMusicPlayer_MainBgm, &song_02B);
}

void func_fe6_0806CFD0(void)
{
    m4aMPlayStart(&gMusicPlayer_MainBgm, &song_02A);
}

void func_fe6_0806CFE8(void)
{
    m4aMPlayStart(&gMusicPlayer_MainBgm, &song_026);
}

void func_fe6_0806D000(void)
{
    PlaySe(SONG_C4);
}

void func_fe6_0806D01C(void)
{
    EarthQuakeSoundFadeOut(0);
}

bool func_fe6_0806D028(void)
{
    if (gPlaySt.faction != FACTION_BLUE)
        return FALSE;

    if (UNIT_JID(gActiveUnit) == JID_THIEF)
        return TRUE;

    if (UNIT_JID(gActiveUnit) == JID_THIEF_F)
        return TRUE;

    if (EventRandNext_N(11) == 0)
        return TRUE;

    return FALSE;
}

void func_fe6_0806D064(void)
{
    if (CheckFlag(FLAG_CHAPTER16_15))
    {
        RemoveGold(10000);
    }

    if (CheckFlag(FLAG_CHAPTER16_16))
    {
        WeakenUnitStatsByPid(PID_HUGH);
        RemoveGold(8000);
    }

    if (CheckFlag(FLAG_CHAPTER16_17))
    {
        WeakenUnitStatsByPid(PID_HUGH);
        WeakenUnitStatsByPid(PID_HUGH);
        RemoveGold(6000);
    }

    if (CheckFlag(FLAG_CHAPTER16_18))
    {
        WeakenUnitStatsByPid(PID_HUGH);
        WeakenUnitStatsByPid(PID_HUGH);
        WeakenUnitStatsByPid(PID_HUGH);
        RemoveGold(5000);
    }
}

void func_fe6_0806D0E4(void)
{
    EndMapUi();
    func_fe6_08027DB4(GetUnitByPid(PID_ROY), ITEM_FROM_IID(IID_BINDINGBLADE));
}

bool func_fe6_0806D0FC(int iid)
{
    int i;

    if (FindSupplyItem(ITEM_FROM_IID(iid)) >= 0)
        return TRUE;

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
#if BUGFIX
        // BUG: If Merlinus is holding an item and he retreats, the game counts the item as not being owned, despite him not
        // permanently dying. If he's holding a legendary weapon in chapter 22 and retreats, we're locked out of the true ending.
        if ((unit->flags & UNIT_FLAG_DEAD) != 0 && UNIT_PID(unit) != PID_MERLINUS)
            continue;
#else
        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;
#endif

        for (i = 0; i < ITEMSLOT_INV_COUNT; i++)
        {
            if (GetItemIid(unit->items[i]) == iid)
                return TRUE;
        }
    })

    return FALSE;
}

bool HaveAllLegendaryWeapons(void)
{
    u8 const * it;

    for (it = gUnk_08672458; *it != 0; it++)
    {
        if (!func_fe6_0806D0FC(*it))
            return FALSE;
    }

    return TRUE;
}

void func_fe6_0806D17C(void)
{
    StartMapChangeEvent(GetMapChangeIdAt(22, 23));
}

void func_fe6_0806D194(void)
{
    int i;

    for (i = 0; i <= FLAG_CHAPTER24_17 - FLAG_CHAPTER24_13; i++)
    {
        ClearFlag(FLAG_CHAPTER24_13 + i);
    }
}

void func_fe6_0806D1AC(void)
{
    int i;

    for (i = 0; i <= FLAG_CHAPTER24_17 - FLAG_CHAPTER24_13; i++)
    {
        int flag = FLAG_CHAPTER24_13 + i;

        if (!CheckFlag(flag))
        {
            SetFlag(flag);
            return;
        }
    }
}

void func_fe6_0806D1D4(void)
{
    gDefeatTalkState = 0;
    gDefeatTalkNextIdx = 0;
    gDefeatTalkPid = 0;
    gDefeatTalkMsg = 0;
}

bool func_fe6_0806D1FC(struct EventProc * proc)
{
    struct Unit * unit;
    int i, j;

    if ((proc->flags & EVENT_FLAG_SKIPPED) != 0)
    {
        EndTalk();
        return FALSE;
    }

    if (IsTalkActive())
        return TRUE;

    switch (gDefeatTalkState)
    {
        case 0:
            i = 1;

            if (gDefeatTalkNextIdx != 0)
                i = gDefeatTalkNextIdx;

            for (; i < 0x40; ++i)
            {
                unit = GetUnit(i);

                if (unit == NULL)
                    continue;

                if (unit->pinfo == NULL)
                    continue;

                if ((unit->flags & UNIT_FLAG_UNAVAILABLE) != 0)
                    continue;

                gDefeatTalkPid = UNIT_PID(unit);

                if (gDefeatTalkPid == PID_ROY)
                    continue;

                for (j = 0; gBattleDefeatTalkList[j].pid != 0; j++)
                {
                    if (gDefeatTalkPid == gBattleDefeatTalkList[j].pid)
                    {
                        gDefeatTalkMsg = gBattleDefeatTalkList[j].unk_0C;
                        gDefeatTalkNextIdx = i + 1;
                        gDefeatTalkState++;
                        return TRUE;
                    }
                }
            }

            return FALSE;

        case 1:
            unit = GetUnitByPid(gDefeatTalkPid);

            CameraMoveWatchPosition(proc, unit->x, unit->y);
            SetMapCursorPosition(unit->x, unit->y);

            gDefeatTalkState++;
            break;

        case 2:
            SetInitTalkTextFont();
            ClearTalkText();
            ClearPutTalkText();
            ClearTalk();

            StartTalkExt(10, 14, DecodeMsg(gDefeatTalkMsg), proc);
            SetTalkPrintColor(TEXT_COLOR_0456);
            SetActiveTalkFace(TALK_FACE_1);

            gDefeatTalkState = 0;
            break;
    }

    return TRUE;
}

bool func_fe6_0806D35C(void)
{
    int count = 0;

    FOR_UNITS(FACTION_GREEN + 1, FACTION_RED + 0x40, unit,
    {
        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        count++;
    })

    if (count < 3)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806D398(void)
{
    if (EventRandNext_N(5) == 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806D3B4(void)
{
    if (func_fe6_0806D398())
    {
        if (gChapterFlagBits[sizeof(gChapterFlagBits) - 1] + 4 != func_fe6_0806C460(FACTION_RED))
            return TRUE;
    }

    return FALSE;
}

void func_fe6_0806D3E0(void)
{
    gChapterFlagBits[sizeof(gChapterFlagBits) - 2]++;
    gChapterFlagBits[sizeof(gChapterFlagBits) - 1] = func_fe6_0806C460(FACTION_RED);

    if (IsHard())
    {
        if (gChapterFlagBits[sizeof(gChapterFlagBits) - 2] == 10)
            return;
    }
    else
    {
        if (gChapterFlagBits[sizeof(gChapterFlagBits) - 2] == 5)
            return;
    }

    ClearFlag(FLAG_CHAPTER18S_6);
}

void AddChapter8xFireTraps(void)
{
    AddFireTrap(10, 22, 1, 4);
    AddFireTrap(14, 21, 2, 3);
    AddFireTrap(14, 23, 2, 5);
    AddFireTrap(17, 22, 4, 2);
    AddFireTrap(19, 21, 4, 6);
    AddFireTrap(23, 18, 6, 4);
    AddFireTrap(25, 18, 6, 3);
    AddFireTrap(23, 16, 5, 3);
    AddFireTrap(24,  9, 5, 2);
    AddFireTrap(23,  8, 6, 5);
    AddFireTrap(25,  8, 5, 4);
    AddFireTrap(20,  1, 7, 5);
    AddFireTrap(19,  3, 6, 6);
    AddFireTrap(14,  8, 9, 2);
    AddFireTrap(15,  9, 3, 3);
    AddFireTrap(13,  9, 9, 4);
    AddFireTrap(14, 10, 11, 3);
    AddFireTrap(12, 12, 1, 5);
    AddFireTrap(11, 11, 1, 3);
    AddFireTrap(11, 13, 7, 3);
    AddFireTrap( 9, 13, 8, 4);
    AddFireTrap( 9, 11, 2, 4);
    AddFireTrap( 8, 12, 6, 2);
    AddFireTrap( 7, 11, 5, 3);
    AddFireTrap( 7, 13, 4, 5);
    AddFireTrap( 3, 10, 1, 3);
}

void func_fe6_0806D55C(void)
{
    gPlaySt.chapter = CHAPTER_8X;
}

void AddChapter12xGasTraps(void)
{
    AddGasTrap( 1,  2, FACING_DOWN, 1, 8);
    AddGasTrap( 1, 14, FACING_RIGHT, 7, 8);
    AddGasTrap(10,  7, FACING_LEFT, 2, 8);
    AddGasTrap( 8, 13, FACING_RIGHT, 3, 8);
    AddGasTrap(11,  2, FACING_DOWN, 5, 8);
    AddGasTrap(13, 13, FACING_DOWN, 4, 8);
    AddGasTrap(14, 17, FACING_UP, 1, 8);
    AddGasTrap(15,  1, FACING_UP, 5, 8);
    AddGasTrap(20, 18, FACING_LEFT, 2, 8);
    AddGasTrap(21,  9, FACING_LEFT, 6, 8);
    AddGasTrap(23, 12, FACING_RIGHT, 3, 8);
    AddGasTrap(23, 20, FACING_RIGHT, 7, 8);
}

void AddChapter14xTimedMapChanges(void)
{
    int i;

    for (i = 0; i < (int) ARRAY_COUNT(Chapter14xTimedMapChangeInfoList); i++)
    {
        AddTimedMapChange(i + 26, i, Chapter14xTimedMapChangeInfoList[i].delay, Chapter14xTimedMapChangeInfoList[i].interval);
    }
}

void AddChapter16xArrowTraps(void)
{
    AddArrowTrap(14, 3, 5);
    AddArrowTrap( 6, 1, 9);
    AddArrowTrap( 8, 4, 9);
    AddArrowTrap( 4, 7, 9);
    AddArrowTrap(13, 8, 9);
    AddArrowTrap(16, 3, 5);
    AddArrowTrap(24, 2, 9);
    AddArrowTrap(26, 5, 9);
    AddArrowTrap(22, 9, 9);
    AddArrowTrap(17, 6, 9);
}

void func_fe6_0806D6B4(void)
{
    SetFlag(gUnk_08675750[EventRandNext_N(ARRAY_COUNT(gUnk_08675750))]);
}

void AddChapter21xStepTraps(void)
{
    AddStepFireTrap( 6, 6);
    AddStepFireTrap( 7, 8);
    AddStepFireTrap( 6, 10);
    AddStepFireTrap( 7, 13);
    AddStepFireTrap( 6, 15);
    AddStepFireTrap( 7, 17);
    AddStepFireTrap(24,  6);
    AddStepFireTrap(23,  8);
    AddStepFireTrap(24, 10);
    AddStepFireTrap(23, 13);
    AddStepFireTrap(24, 16);
    AddStepFireTrap(23, 17);

    AddStepPikeTrap(12, 14, FACING_UP);
    AddStepPikeTrap(18, 14, FACING_UP);
    AddStepPikeTrap(10,  7, FACING_RIGHT);
    AddStepPikeTrap(20,  7, FACING_LEFT);
    AddStepPikeTrap(14,  7, FACING_RIGHT);
    AddStepPikeTrap(16,  7, FACING_LEFT);
}

void func_fe6_0806D77C(void)
{
    int i, count;

    for (i = 0, count = 0;; i++)
    {
        if (!CheckFlag(gUnk_08675B90[i % (int) ARRAY_COUNT(gUnk_08675B90)]) && EventRandNext_N(11) == 0)
        {
            SetFlag(gUnk_08675B90[i % (int) ARRAY_COUNT(gUnk_08675B90)]);

            count++;

            if (count == 3)
                return;
        }
    }
}

/**
 * Demo scene
 */

struct DemoMonologueMsg CONST_DATA gDemoMonologueMsg[] = {
    { MSG_BCD, 0x08 },
    { MSG_BCE, 0x08 },
    { MSG_BCF, 0x07 },
    { MSG_BD0, 0x07 },
    { MSG_BD1, 0x06 },
    { MSG_BD2, 0x06 },
};

u8 CONST_DATA MoveScr_Unk_086761B4[] = {
    MOVE_CMD_SET_SPEED, 0x18,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_HALT
};

u8 CONST_DATA MoveScr_Unk_086761CD[] = {
    MOVE_CMD_SET_SPEED, 0x30,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_CAMERA_ON,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_HALT
};

u8 CONST_DATA MoveScr_Unk_086761E7[] = {
    MOVE_CMD_SET_SPEED, 0x30,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_HALT
};

struct BattleHit CONST_DATA FightScr_Unk_08676204[] = {
    {
        .attributes = BATTLE_HIT_ATTR_MISS,
        .info = BATTLE_HIT_INFO_BEGIN,
        .damage = 0,
    },
    {
        .info = BATTLE_HIT_INFO_FINISHES | BATTLE_HIT_INFO_ACTORB,
        .damage = 12,
    },
    {
        .info = BATTLE_HIT_INFO_END,
    },
};

struct BattleHit CONST_DATA FightScr_Unk_08676210[] = {
    {
        .info = BATTLE_HIT_INFO_FINISHES | BATTLE_HIT_INFO_BEGIN,
        .damage = 9,
    },
    {
        .info = BATTLE_HIT_INFO_END,
    },
};

struct BattleHit CONST_DATA FightScr_Unk_08676218[] = {
    {
        .info = BATTLE_HIT_INFO_FINISHES | BATTLE_HIT_INFO_BEGIN,
        .damage = -10,
    },
    {
        .info = BATTLE_HIT_INFO_END,
    },
};

struct ProcScr CONST_DATA ProcScr_DemoSceneIntro[] =
{
    PROC_REPEAT(DemoSceneIntro_Blocked),
    PROC_CALL(DemoSceneIntro_Init),
    PROC_CALL_ARG(_FadeBgmOut, 2),
    PROC_REPEAT(DemoSceneIntro_FadeOut),
    PROC_CALL(DemoSceneIntro_StartExt),
    PROC_END,
};

void DemoScene_StartMonologue(void)
{
    func_fe6_08013A64();
    SetNextGameAction(GAME_ACTION_1);
    SpawnProc(ProcScr_DemoSceneIntro, PROC_TREE_4);
}

void SetBanimConfigUniqueBG(void)
{
    gPlaySt.config_battle_anim = PLAY_ANIMCONF_ON_UNIQUE_BG;
}

void SetBanimConfigON(void)
{
    gPlaySt.config_battle_anim = PLAY_ANIMCONF_ON;
}

void CleanupDemoSceneIntro(void)
{
    InitUnits();
    ClearTalk();
    Proc_EndEachMarked(PROC_MARK_1);
}

void EndDemoSceneIntro(void)
{
    Proc_EndEach(ProcScr_DemoSceneIntro);
}

void DemoSceneIntro_Blocked(ProcPtr proc)
{
    if (gKeySt->pressed & (KEY_BUTTON_ANY & ~KEY_BUTTON_SELECT))
        Proc_Break(proc);
}

void DemoSceneIntro_Init(struct ProcDemoSceneIntro * proc)
{
    SetNextGameAction(GAME_ACTION_0);
    proc->timer = 31;
}

void DemoSceneIntro_FadeOut(struct ProcDemoSceneIntro * proc)
{
    DarkenPals(0x20 - proc->timer);

    proc->timer--;

    if (proc->timer < 0)
        Proc_Break(proc);
}

void DemoSceneIntro_StartExt(void)
{
    CleanupGame(NULL);
    SyncHiOam();
    CleanupDemoSceneIntro();
    EndDemoSceneIntro();
    KillTalkAndEvent();
}

EventScr CONST_DATA EventScr_DemoScene[] =
{
    EvtNoSkipNoTextSkip
    EvtFunc(DemoScene_StartMonologue)
    EvtFunc(CleanupDemoSceneIntro)
    EvtUnitCameraOff
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(DemoScene_JumpToCh4)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtLoadUnits(UnitInfo_Chaper4_UnusedCavaliers)
    EvtLoadUnits(UnitInfo_Chaper4_UnusedPegasi)
    EvtSleep(16)
    EvtMoveScript(21, 10, MoveScr_Unk_086761B4)
    EvtMoveScript(19, 11, MoveScr_Unk_086761B4)
    EvtSleep(30)
    EvtMoveScript(20, 9, MoveScr_Unk_086761CD)
    EvtMoveScript(21, 12, MoveScr_Unk_086761E7)
    EvtSleep(60)
    EvtMoveWait
    EvtSleep(30)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(CleanupDemoSceneIntro)
    EvtFunc(PutDemoMonologueMsg)
    EvtSleep(60)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtSleep(120)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(DemoScene_TmpCleanup)
    EvtFunc(DemoScene_JumpToCh1)
    EvtLoadUnits(UnitInfo_Chapter1_BlueUnused)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtMove(9, 7, 7, 7)
    EvtMoveWait
    EvtTalk(MSG_BA6)
    EvtSleep(60)
    EvtFunc(ClearTalk)
    EvtFightScript(PID_ROY, PID_MARCUS, FightScr_Unk_08676204, FALSE)
    EvtTalk(MSG_BA7)
    EvtSleep(60)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(ClearTalk)
    EvtFunc(CleanupDemoSceneIntro)
    EvtFunc(PutDemoMonologueMsg)
    EvtSleep(60)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtSleep(120)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(DemoScene_TmpCleanup)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BA4)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(ClearTalk)
    EvtFunc(PutDemoMonologueMsg)
    EvtSleep(60)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtSleep(120)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(DemoScene_TmpCleanup)
    EvtFunc(DemoScene_JumpToCh10A)
    EvtLoadUnits(UnitInfo_Unk_0867CC08)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtSleep(30)
    EvtMove(8, 20, 6, 19)
    EvtMoveWait
    EvtSleep(60)
    EvtFightScript(PID_WOLT, PID_UNKNOWN_7B, FightScr_Unk_08676210, TRUE)
    EvtSleep(60)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(CleanupDemoSceneIntro)
    EvtFunc(PutDemoMonologueMsg)
    EvtSleep(60)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtSleep(120)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(DemoScene_TmpCleanup)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BA5)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(ClearTalk)
    EvtFunc(PutDemoMonologueMsg)
    EvtSleep(60)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtSleep(120)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(DemoScene_TmpCleanup)
    EvtFunc(DemoScene_JumpToCh2)
    EvtLoadUnits(UnitInfo_Chapter2_MixedUnused)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtMove(8, 10, 7, 10)
    EvtMoveWait
    EvtFunc(DemoScene_SetRoyHp_10)
    EvtTalk(MSG_BA8)
    EvtSleep(60)
    EvtFunc(ClearTalk)
    EvtFightScript(PID_ELEN, PID_ROY, FightScr_Unk_08676218, FALSE)
    EvtTalk(MSG_BA9)
    EvtSleep(60)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(ClearTalk)
    EvtFunc(CleanupDemoSceneIntro)
    EvtFunc(PutDemoMonologueMsg)
    EvtSleep(60)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtSleep(120)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(DemoScene_TmpCleanup)
    EvtFunc(DemoScene_JumpToCh22)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtLoadUnits(UnitInfo_Unk_08681240)
    EvtMapChangePosition(15, 15)
    EvtSleep(30)
    EvtLoadUnits(UnitInfo_Unk_08681330)
    EvtTalk(MSG_BA2)
    EvtSleep(60)
    EvtFunc(ClearTalk)
    EvtMove(15, 9, 15, 22)
    EvtMoveWait
    EvtSleep(30)
    EvtTalk(MSG_BA3)
    EvtSleep(60)
    EvtFunc(ClearTalk)
    EvtSleep(30)
    EvtMove(15, 8, 15, 10)
    EvtMoveWait
    EvtMove(16, 9, 15, 9)
    EvtMoveWait
    EvtMove(15, 10, 15, 17)
    EvtMove(15, 9, 15, 16)
    EvtMoveWait
    EvtSleep(60)
    EvtFadeBgmOut(-1)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(CleanupDemoSceneIntro)
    EvtFunc(EndDemoSceneIntro)
    EvtClearSkip
    EvtEnd
};

void PutDemoMonologueMsg(void)
{
    struct ProcTypeWritter * proc;
    int i;

    SetDispEnable(1, 0, 0, 0, 0);

    SetBgOffset(0, 0, 0);

    ResetText();
    ResetTextFont();
    InitTalkTextFont();

    TmFill(gBg0Tm, 0);

    CpuFastFill(0, (void *) VRAM + GetBgChrOffset(3) + 0 * CHR_SIZE, CHR_SIZE);

    proc = SpawnProc(ProcScr_DemoMonologueDisp, PROC_TREE_3);

    for (i = 0; i < (int) ARRAY_COUNT(proc->text); i++)
    {
        struct Text * text = Texts_DemoMonologue + i;

        InitText(text, 24);
        ClearText(text);

        Text_SetColor(text, TEXT_COLOR_0123);

        proc->text[i] = text;

        PutText(text, gBg0Tm + TM_OFFSET(3, 2 * i + gDemoMonologueMsg[gDemoMonologueId].y_offset));
    }

    proc->font = NULL;
    proc->line = 0;
    proc->str_it = DecodeMsg(gDemoMonologueMsg[gDemoMonologueId].msg);

    gDemoMonologueId++;

    EnableBgSync(BG0_SYNC_BIT);
}

void DemoScene_TmpCleanup(void)
{
    SetDispEnable(1, 1, 1, 1, 1);
    CpuFastFill(0, (void *) VRAM + 0x6000, 0x2000);
}

void DemoScene_JumpToChapterDirectly(int chapter, int x, int y)
{
    InitUnits();

    gPlaySt.chapter = chapter;

    JumpToChapterDirectly();

    gPlaySt.vision = GetChapterInfo(gPlaySt.chapter)->fog;

    gBmSt.camera.x = GetCameraCenteredX(x * 16 + 8);
    gBmSt.camera.y = GetCameraCenteredY(y * 16 + 8);

    RefreshEntityMaps();
    RenderMap();
    RefreshUnitSprites();
}

void DemoScene_JumpToCh4(void)
{
    DemoScene_JumpToChapterDirectly(CHAPTER_4, 11, 11);
    CpuFastCopy(gPal + (BGPAL_TILESET + 5) * 0x10, gPal + BGPAL_TILESET * 0x10, 5 * 0x20);
    EfxPalWhiteInOut(gPal, 26, 6, 8);
    EnablePalSync();
}

void DemoScene_JumpToCh1(void)
{
    DemoScene_JumpToChapterDirectly(CHAPTER_1, 7, 5);
}

void DemoScene_JumpToCh10A(void)
{
    DemoScene_JumpToChapterDirectly(CHAPTER_10_A, 0, 20);
}

void DemoScene_JumpToCh2(void)
{
    DemoScene_JumpToChapterDirectly(CHAPTER_2, 7, 10);
}

void DemoScene_JumpToCh22(void)
{
    DemoScene_JumpToChapterDirectly(CHAPTER_22, 15, 9);
}

void DemoScene_SetRoyHp_10(void)
{
    struct Unit * unit = GetUnitByPid(PID_ROY);
    SetUnitHp(unit, GetUnitCurrentHp(unit) - 10);
}

EventScr const * CONST_DATA EventScrs_DemoScene[] = {
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene,
    EventScr_DemoScene
};

EventScr const * GetDemoSceneEvent_Unused(int arg_0, int arg_1)
{
    return EventScrs_DemoScene[arg_1];
}

void StartDemoSceneEvent(int arg_0, ProcPtr proc)
{
    StartEventLocking(EventScrs_DemoScene[arg_0], proc);

    gDemoSceneId = arg_0;
    gDemoMonologueId = 0;
}

/**
 * Ending scene
 */
u8 * CONST_DATA gpBuf = gBuf;

// 0x86767D0
CONST_DATA u8 MoveScr_TrueEnding_086767D0[] = {
    MOVE_CMD_SET_SPEED, 16,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_HALT,
};

// 0x86767DB
CONST_DATA u8 MoveScr_TrueEnding_086767DB[] = {
    MOVE_CMD_SET_SPEED, 16,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_HALT,
};

// 0x86767E6
CONST_DATA u8 MoveScr_TrueEnding_086767E6[] = {
    MOVE_CMD_SET_SPEED, 8,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_HALT,
};

// 0x86767EB
CONST_DATA u8 MoveScr_TrueEnding_086767EB[] = {
    MOVE_CMD_SET_SPEED, 12,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_HALT,
};

// 0x86767F3
CONST_DATA u8 MoveScr_TrueEnding_086767F3[] = {
    MOVE_CMD_SET_SPEED, 20,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_SLEEP, 4,
    MOVE_CMD_FACE_RIGHT,
    MOVE_CMD_SLEEP, 64,
    MOVE_CMD_SET_SPEED, 8,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_HALT,
};

// 0x8676805
CONST_DATA u8 MoveScr_TrueEnding_08676805[] = {
    MOVE_CMD_SET_SPEED, 6,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_HALT,
};

// 0x8676810
CONST_DATA u8 MoveScr_Epilogue_FaeWwww[] = {
    MOVE_CMD_SET_SPEED, 32,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_HALT,
};

// 0x8676823
CONST_DATA u8 MoveScr_Epilogue_FaeExit[] = {
    MOVE_CMD_SET_SPEED, 22,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_HALT,
};

// 0x8676831
CONST_DATA u8 MoveScr_TrueEnding_08676831[] = {
    MOVE_CMD_SET_SPEED, 5,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_FACE_RIGHT,
    MOVE_CMD_SLEEP, 24,
    MOVE_CMD_HALT,
};

// 0x867683C
CONST_DATA u8 MoveScr_TrueEnding_0867683C[] = {
    MOVE_CMD_SET_SPEED, 5,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_HALT,
};

void EndAllProcsMark1(void)
{
    Proc_EndEachMarked(PROC_MARK_1);
}

struct ProcScr CONST_DATA ProcScr_TrueEnding_EarthQuake[] =
{
    PROC_REPEAT(TrueEnding_EarthQuake_Main),
    PROC_END,
};

void TrueEnding_EarthQuake_Main(void)
{
    if (GetGameTime() % 2 == 0)
        return;

    gBmSt.camera.x ^= 2;
}

void TrueEnding_EarthQuake(ProcPtr proc)
{
    PlaySe(SONG_26A);
    SpawnProc(ProcScr_TrueEnding_EarthQuake, proc);
}

void TrueEnding_EarthQuakeEnd(void)
{
    Proc_EndEach(ProcScr_TrueEnding_EarthQuake);
    EarthQuakeSoundFadeOut(4);
}

struct ProcScr CONST_DATA ProcScr_Unk_08676854[] =
{
    PROC_CALL(func_fe6_0806DBA0),
    PROC_REPEAT(func_fe6_0806DBA8),
    PROC_END,
};

void func_fe6_0806DBA0(struct UnkProc_08676854 * proc)
{
    proc->unk_64 = 0;
}

void func_fe6_0806DBA8(struct UnkProc_08676854 * proc)
{
    if (GetGameTime() % 2 != 0)
    {
        gBmSt.camera.x ^= 2;

        proc->unk_64++;

        if (proc->unk_64 > 5)
            Proc_Break(proc);
    }

    SetBgOffset(2, gBmSt.camera.x - (u16) gBmSt.map_render_anchor.x * 16, gBmSt.camera.y - (u16) gBmSt.map_render_anchor.y * 16);
    SetBgOffset(3, gBmSt.camera.x - (u16) gBmSt.map_render_anchor.x * 16, gBmSt.camera.y - (u16) gBmSt.map_render_anchor.y * 16);
}

void func_fe6_0806DC24(ProcPtr parent)
{
    SpawnProc(ProcScr_Unk_08676854, parent);
}

void func_fe6_0806DC38(void)
{
    Proc_EndEach(ProcScr_Unk_08676854);
}

struct ProcScr CONST_DATA ProcScr_EndingCreditFade[] =
{
    PROC_CALL(EndingCreditFade_Init),
    PROC_REPEAT(EndingCreditFade_FadeBg),
    PROC_CALL(StartGameCredit),
    PROC_END,
};

void EndingCreditFade_Init(struct ProcGameCreditFade * proc)
{
    proc->unk_64 = 0;
}

void EndingCreditFade_FadeBg(struct ProcGameCreditFade * proc)
{
    if (GetGameTime() % 8 == 0)
    {
        if (proc->unk_64++ > 11)
            Proc_Break(proc);

        ColFadeStep(0, 0x20, 0x20, -1);
        ColFadeTick();
    }
}

void Epilogue_StartCredit(ProcPtr parent)
{
    SpawnProc(ProcScr_EndingCreditFade, parent);
}

void RemoveEndingMonologueBG(void)
{
    InitBgs(NULL);

    SetDispEnable(1, 1, 1, 1, 1);

    CpuFastFill(0, (void *) VRAM + GetBgChrOffset(3), CHR_SIZE);
    CpuFastFill(0, (void *) VRAM + 0x300 * CHR_SIZE, CHR_SIZE * 0x100);
}

struct ProcScr CONST_DATA ProcScr_EndingTimeFlowMonologue[] =
{
    PROC_CALL(EndingTimeFlowMonologue_Init),
    PROC_CALL(StartSlowFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_SLEEP(120),
    PROC_CALL(StartSlowFadeToBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_END,
};

void EndingTimeFlowMonologue_Init(void)
{
    SetDispEnable(1, 0, 0, 0, 0);

    SetBgOffset(0, 0, 0);
    TmFill(gBg0Tm, 0);

    ResetText();
    InitTalkTextFont();

    InitText(&Text_EndingTimeFlowMonologue, 14);
    PutDrawText(&Text_EndingTimeFlowMonologue, gBg0Tm + TM_OFFSET(8, 9),
        TEXT_COLOR_0123, 0, 0, DecodeMsg(MSG_24A));
}

void DrawEndingTimeFlowMonologue(ProcPtr parent)
{
    SpawnProc(ProcScr_EndingTimeFlowMonologue, parent);
}

bool EndingTimeFlowMonologueExists(void)
{
    if (FindProc(ProcScr_EndingTimeFlowMonologue) != NULL)
        return TRUE;

    Proc_EndEach(ProcScr_DemoMonologueDisp);
    RemoveEndingMonologueBG();

    return FALSE;
}

void Epilogue_RemoveEventEngineBG(struct EventProc * proc)
{
    proc->background = -1;
}

void Epilogue_RemoveEventEngineNoMap(struct EventProc * proc)
{
    proc->no_map = true;
}

void TrueEnding_SetNiceWeather(void)
{
    SetWeather(WEATHER_NONE);
}

void Epilogue_StartWind(void)
{
    PlaySe(SONG_C4);
    SetWeather(WEATHER_SANDSTORM);
}

void func_fe6_0806DE00(void)
{
    PlaySe(SONG_269);
}

void TruEnding_PlaySe269(void)
{
    PlaySe(SONG_269);
}

void func_fe6_0806DE40(void)
{
    PlaySe(SONG_6A);
}

struct ProcScr CONST_DATA ProcScr_EndingBgmLooper[] =
{
    PROC_CALL(EndingBgmLooper_Init),
    PROC_REPEAT(EndingBgmLooper_Ioop),
    PROC_END,
};

void EndingBgmLooper_Init(struct UnkProc_086768C4 * proc)
{
    StartBgm(SONG_43, NULL);
    proc->unk_64 = 17600;
}

void EndingBgmLooper_Ioop(struct UnkProc_086768C4 * proc)
{
    proc->unk_64--;

    if (proc->unk_64 == 0)
    {
        StartBgm(SONG_34, NULL);
        Proc_Break(proc);
    }
}

void NewEndingBgmLooper(ProcPtr parent)
{
    SpawnProc(ProcScr_EndingBgmLooper, parent);
}

void EndEndingBgmLooper(void)
{
    Proc_EndEach(ProcScr_EndingBgmLooper);
}

bool GameEnding_TryBuildGreatLycia(void)
{
    // this is funny
#if BUGFIX
    if (IsLilinaBlue())
#else
    if (IsLilinaBlue != NULL)
#endif
    {
        struct Unit * roy = GetUnitByPid(PID_ROY);

        if (GetUnitSupportLevel(roy, GetUnitSupportNumByPid(roy, PID_LILINA)) > 2)
            return TRUE;
    }

    return FALSE;
}

void RenderMapForDirectJump(void)
{
    RenderMapForFade();
    gPlaySt.vision = 0;
    RefreshEntityMaps();
    RefreshUnitSprites();
    RenderMap();
}

struct ProcScr CONST_DATA ProcScr_TrueEnding_SortAllies[] =
{
    PROC_CALL(TrueEnding_SortAllies_Init),
    PROC_REPEAT(TrueEnding_SortAllies_Loop),
    PROC_WHILE(MuExistsActive),
    PROC_END,
};

void TrueEnding_SortAllies_Init(struct UnkProc_086768DC * proc)
{
    proc->unk_64 = 1;

    if (CheckFlag(FLAG_IDUNN_NOT_DIE))
        proc->unk_64++;
}

void TrueEnding_SortAllies_Loop(struct UnkProc_086768DC * proc)
{
    for (;;)
    {
        if (!CanStartMu())
            return;

        proc->unk_64 = GetNextAvailableBlueUnitId(proc->unk_64);

        if (proc->unk_64 != 0)
        {
            TryMoveUnitDisplayed(proc->unk_4C, GetUnit(proc->unk_64), 8, (gBmSt.camera.x >> 4) + 13);
            proc->unk_64++;
            continue;
        }

        Proc_Break(proc);
        return;
    }
}

void TrueEnding_SortAllies(ProcPtr parent)
{
    struct UnkProc_086768DC * proc;

    proc = SpawnProc(ProcScr_TrueEnding_SortAllies, parent);
    proc->unk_4C = parent;
}

bool TrueEnding_SortAlliesExists(void)
{
    return FindProc(ProcScr_TrueEnding_SortAllies) != NULL ? TRUE : FALSE;
}

struct ProcScr CONST_DATA ProcScr_Epilogue_BgmFadeIn[] =
{
    PROC_CALL(Epilogue_BgmFadeIn_Init),
    PROC_REPEAT(Epilogue_BgmFadeIn_Loop),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Epilogue_BgmFadeOut[] =
{
    PROC_CALL(Epilogue_BgmFadeOut_Init),
    PROC_REPEAT(Epilogue_BgmFadeOut_Loop),
    PROC_END,
};

void Epilogue_BgmFadeIn_Init(struct ProcEpilogueBgmFade * proc)
{
    proc->timer = 0x100;
}

void Epilogue_BgmFadeOut_Init(struct ProcEpilogueBgmFade * proc)
{
    proc->timer = 0;
}

void Epilogue_BgmFadeIn_Loop(struct ProcEpilogueBgmFade * proc)
{
    proc->timer -= 3;

    if (proc->timer <= 0)
    {
        proc->timer = 0;
        Proc_Break(proc);
    }

    SetBgmVolume(proc->timer);
}

void Epilogue_BgmFadeOut_Loop(struct ProcEpilogueBgmFade * proc)
{
    proc->timer2++;

    if ((proc->timer2 & 1) != 0)
    {
        proc->timer++;

        if (proc->timer >= 0x100)
            Proc_Break(proc);

        SetBgmVolume(proc->timer);
    }
}

void EarthQuakeSoundFadeOutDefault(void)
{
    EarthQuakeSoundFadeOut(0);
}

void Epilogue_BgmFadeIn(ProcPtr parent)
{
    SpawnProc(ProcScr_Epilogue_BgmFadeIn, parent);
}

void Epilogue_BgmFadeOut(ProcPtr parent)
{
    SpawnProcLocking(ProcScr_Epilogue_BgmFadeOut, parent);
}

void func_fe6_0806E074(void)
{
    int i;

    for (i = FACTION_BLUE; i < FACTION_BLUE + 0x40; i++)
    {
        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        unit->flags &= ~(UNIT_FLAG_HIDDEN | UNIT_FLAG_TURN_ENDED | UNIT_FLAG_NOT_DEPLOYED);
    }

    RefreshEntityMaps();
    RefreshUnitSprites();
}

struct GameEndingPosition CONST_DATA gGameEndingPosition1[] = {
    { 0x08, 0x06, 0 },
    { 0x08, 0x08, 0 },
    { 0x06, 0x08, 0 },
    { 0x0A, 0x08, 0 },
    { 0x07, 0x09, 0 },
    { 0x09, 0x09, 0 },
    { 0x05, 0x09, 0 },
    { 0x0B, 0x09, 0 },
    { 0x04, 0x08, 0 },
    { 0x0C, 0x08, 0 },
    { 0x07, 0x0A, 0 },
    { 0x09, 0x0A, 0 },
};

void GameEnding_PutUnitsOnPosition1(void)
{
    int i, j;
    int next_slot = 1;

    for (i = FACTION_BLUE + 1; i < FACTION_BLUE + 0x40; i++)
    {
        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        switch (UNIT_PID(unit))
        {
            case PID_ROY:
                unit->flags &= ~(UNIT_FLAG_HIDDEN | UNIT_FLAG_NOT_DEPLOYED);
                unit->x = gGameEndingPosition1[0].x;
                unit->y = gGameEndingPosition1[0].y;
                break;

            default:
                for (j = 0; gEndingUids2[j] != -1; j++)
                {
                    if (gEndingUids2[j] == i)
                    {
                        unit->flags &= ~(UNIT_FLAG_HIDDEN | UNIT_FLAG_NOT_DEPLOYED);
                        unit->x = gGameEndingPosition1[next_slot].x;
                        unit->y = gGameEndingPosition1[next_slot].y;
                        next_slot++;
                    }
                }

                break;
        }
    }

    RefreshEntityMaps();
    RefreshUnitSprites();
}

struct GameEndingPosition CONST_DATA gGameEndingPosition2[] = {
    { 0x05, 0x01, 0 },
    { 0x05, 0x06, 0 },
    { 0x03, 0x06, 0 },
    { 0x07, 0x06, 0 },
    { 0x04, 0x07, 0 },
    { 0x06, 0x07, 0 },
    { 0x02, 0x07, 0 },
    { 0x08, 0x07, 0 },
    { 0x03, 0x08, 0 },
    { 0x07, 0x08, 0 },
    { 0x05, 0x08, 0 },
    { 0x02, 0x05, 0 },
    { 0x08, 0x05, 0 },
    { 0x04, 0x09, 0 },
    { 0x06, 0x09, 0 },
};

void GameEnding_PutUnitsOnPosition2(void)
{
    int i, j, pid;
    int next_slot = 2;

    for (i = FACTION_BLUE + 1; i < FACTION_BLUE + 0x40; i++)
    {
        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        switch (UNIT_PID(unit))
        {
            case PID_ROY:
                unit->flags |= UNIT_FLAG_HIDDEN;
                unit->x = gGameEndingPosition2[0].x;
                unit->y = gGameEndingPosition2[0].y;
                break;

            case PID_MERLINUS:
                unit->flags &= ~(UNIT_FLAG_HIDDEN | UNIT_FLAG_NOT_DEPLOYED);
                unit->x = gGameEndingPosition2[1].x;
                unit->y = gGameEndingPosition2[1].y;
                break;

            default:
                for (j = 0; gEndingUids2[j] != -1; j++)
                {
                    if (gEndingUids2[j] == i)
                    {
                        unit->flags &= ~(UNIT_FLAG_HIDDEN | UNIT_FLAG_NOT_DEPLOYED);
                        unit->x = gGameEndingPosition2[next_slot].x;
                        unit->y = gGameEndingPosition2[next_slot].y;
                        next_slot++;
                    }
                }

                break;
        }
    }

    RefreshEntityMaps();
    RefreshUnitSprites();
}

void GameEnding_DeployRoy(void)
{
    int i;

    for (i = FACTION_BLUE + 1; i < FACTION_BLUE + 0x40; i++)
    {
        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if (UNIT_PID(unit) != PID_ROY)
            continue;

        unit->flags &= ~(UNIT_FLAG_HIDDEN | UNIT_FLAG_NOT_DEPLOYED);
        break;
    }
}

void SetFlagIfDefeatedByBindingBlade(void)
{
    if (GetItemIid(gBattleUnitA.weapon_before) == IID_BINDINGBLADE ||
        GetItemIid(gBattleUnitB.weapon_before) == IID_BINDINGBLADE)
    {
        SetFlag(FLAG_IDUNN_NOT_DIE);
    }
}

void UpdateEndingId(void)
{
    if (gPlaySt.chapter == CHAPTER_FINAL) {
        if (CheckFlag(FLAG_IDUNN_NOT_DIE) && IsFaeBlue())
            gEndingId = TRUE_ENDING;
        else
            gEndingId = NORMAL_ENDING;
    } else
        gEndingId = FAKE_ENDING;
}

fu8 GetEndingId(void)
{
    UpdateEndingId();
    return gEndingId;
}

// EventScr @ 08676998
EventScr CONST_DATA EventScr_TrueEnding_IndunnNotDie[] =
{
    EvtSleep(30)
    EvtFunc(TrueEnding_EarthQuake)
    EvtTalk(MSG_239)
    EvtClearTalk
    EvtFunc(TrueEnding_SortAllies)
    EvtFuncWhile(TrueEnding_SortAlliesExists)
    EvtMoveUnitNextTo(PID_ROY, PID_IDUNN)
    EvtMoveWait
    EvtFadeToBlack(4)
    EvtExitMap
    EvtSleep(60)
    EvtFunc(TrueEnding_EarthQuakeEnd)
    EvtFunc(EndAllProcsMark1)
    EvtSetMap(CHAPTER_23, 0, 0)
    EvtFunc(TrueEnding_SetNiceWeather)
    EvtFunc(GameEnding_PutUnitsOnPosition2)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtSleep(150)
    EvtFunc(GameEnding_DeployRoy)
    EvtMoveUnit(PID_ROY, 5, 5)
    EvtMoveWait
    EvtSleep(60)
    EvtSetBgm(SONG_3C)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_23A)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(ClearTalk)
    EvtFunc(StartEndingMonologue0)
    EvtFuncWhile(EndingMonologueExists)
    EvtFadeBgmOut(4)
    EvtSleep(120)
    EvtSetBgm(SONG_34)
    EvtGotoIfNotFunc(3, GameEnding_TryBuildGreatLycia)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_246)
    EvtGoto(4)

EvtLabel(3)
    EvtFunc(EndAllProcsMark1)
    EvtSetMap(CHAPTER_22, 16, 9)
    EvtFunc(Epilogue_RemoveEventEngineNoMap)
    EvtMapChangePosition(15, 15)
    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_Unk_08681350)
    EvtMoveWait
    EvtFunc(RenderMapForDirectJump)
    EvtFunc(Epilogue_RemoveEventEngineBG)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtTalk(MSG_247)
    EvtSleep(30)
    EvtClearTalk
    EvtMoveScript(15, 17, MoveScr_TrueEnding_086767D0)
    EvtMoveWait
    EvtTalk(MSG_248)
    EvtClearTalk
    EvtSleep(30)
    EvtMoveScript(15, 9, MoveScr_TrueEnding_086767DB)
    EvtMoveWait
    EvtMoveUnitScript(PID_GUINIVERE, MoveScr_TrueEnding_086767E6)
    EvtMoveWait
    EvtSleep(45)
    EvtTalk(MSG_249)
    EvtClearTalk
    EvtSleep(30)
    EvtMoveUnitScript(PID_GUINIVERE, MoveScr_TrueEnding_086767EB)
    EvtMoveWait
    EvtSleep(90)

EvtLabel(4)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFadeBgmOut(4)
    EvtSleep(120)
    EvtFunc(ClearTalk)
    EvtFunc(EndAllProcsMark1)
    EvtFunc(DrawEndingTimeFlowMonologue)
    EvtFuncWhile(EndingTimeFlowMonologueExists)
    EvtSetBgm(SONG_26)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_3)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_24B)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(ClearTalk)
    EvtSetMap(CHAPTER_14, 22, 7)
    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_EpilogueFaeIdunn)
    EvtMoveWait
    EvtFunc(RenderMapForDirectJump)
    EvtFunc(TrueEnding_SetNiceWeather)
    EvtFunc(Epilogue_RemoveEventEngineBG)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtMoveUnitScript(PID_FAE, MoveScr_TrueEnding_086767F3)
    EvtSleep(30)
    EvtMoveUnitScript(PID_IDUNN, MoveScr_TrueEnding_08676805)
    EvtMoveWait
    EvtSleep(15)
    EvtFunc(NewEndingBgmLooper)
    EvtTalk(MSG_24C)
    EvtFunc(func_fe6_0806DC24)
    EvtTalkContinue
    EvtSleep(15)
    EvtFunc(func_fe6_0806DE40)
    EvtTalkContinue
    EvtSleep(15)
    EvtTalkContinue
    EvtMoveUnitScript(PID_FAE, MoveScr_Epilogue_FaeWwww)
    EvtTalkContinue
    EvtClearTalk
    EvtMoveWait
    EvtMoveUnitScript(PID_FAE, MoveScr_Epilogue_FaeExit)
    EvtMoveWait
    EvtSleep(60)
    EvtMoveUnitScript(PID_IDUNN, MoveScr_TrueEnding_08676831)
    EvtSleep(100)
    EvtFunc(Epilogue_BgmFadeIn)
    EvtSleep(100)
    EvtFunc(Epilogue_StartWind)
    EvtSleep(15)
    EvtFunc(EarthQuakeSoundFadeOutDefault)
    EvtMoveWait
    EvtFunc(TrueEnding_SetNiceWeather)
    EvtSleep(100)
    EvtTalk(MSG_250)
    EvtClearTalk
    EvtSleep(30)
    EvtFunc(Epilogue_StartCredit)
    EvtSleep(60)
    EvtFunc(Epilogue_BgmFadeOut)
    EvtSleep(420)
    EvtMoveUnitScript(PID_IDUNN, MoveScr_TrueEnding_0867683C)
    EvtSleep(256)
    EvtFunc(TriggerEndingDone)
    EvtFuncWhile(CheckGameEndingDone)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(EndAllProcsMark1)
    EvtSleep(64)
    EvtJump(EventScr_CharacterEnding)

    EvtClearSkip
    EvtEnd
};

// EventScr @ 08676E14
EventScr CONST_DATA EventScr_TrueEnding_IndunnDie[] =
{
    EvtSleep(30)
    EvtFunc(TrueEnding_EarthQuake)
    EvtTalk(MSG_251)
    EvtClearTalk
    EvtFunc(TrueEnding_SortAllies)
    EvtFuncWhile(TrueEnding_SortAlliesExists)
    EvtGotoIfNotFlag(20, FLAG_IDUNN_NOT_DIE)

    EvtMoveUnitNextTo(PID_ROY, PID_IDUNN)
    EvtMoveWait

EvtLabel(20)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtSleep(60)
    EvtFunc(TrueEnding_EarthQuakeEnd)
    EvtFunc(EndAllProcsMark1)
    EvtSetMap(CHAPTER_23, 0, 0)
    EvtFunc(TrueEnding_SetNiceWeather)
    EvtFunc(GameEnding_PutUnitsOnPosition2)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtSleep(150)
    EvtFunc(GameEnding_DeployRoy)
    EvtMoveUnit(PID_ROY, 5, 5)
    EvtMoveWait
    EvtSleep(60)
    EvtSetBgm(SONG_3C)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_252)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(ClearTalk)
    EvtFunc(StartEndingMonologue1)
    EvtFuncWhile(EndingMonologueExists)
    EvtFadeBgmOut(4)
    EvtSleep(120)
    EvtSetBgm(SONG_34)
    EvtGotoIfNotFunc(3, GameEnding_TryBuildGreatLycia)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_25E)
    EvtGoto(4)

EvtLabel(3)
    EvtFunc(EndAllProcsMark1)
    EvtSetMap(CHAPTER_22, 16, 9)
    EvtFunc(Epilogue_RemoveEventEngineNoMap)
    EvtMapChangePosition(15, 15)
    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_Unk_08681350)
    EvtMoveWait
    EvtFunc(RenderMapForDirectJump)
    EvtFunc(Epilogue_RemoveEventEngineBG)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtTalk(MSG_25F)
    EvtSleep(30)
    EvtClearTalk
    EvtMoveScript(15, 17, MoveScr_TrueEnding_086767D0)
    EvtMoveWait
    EvtTalk(MSG_260)
    EvtClearTalk
    EvtSleep(30)
    EvtMoveScript(15, 9, MoveScr_TrueEnding_086767DB)
    EvtMoveWait
    EvtMoveUnitScript(PID_GUINIVERE, MoveScr_TrueEnding_086767E6)
    EvtMoveWait
    EvtSleep(45)
    EvtTalk(MSG_261)
    EvtClearTalk
    EvtSleep(30)
    EvtMoveUnitScript(PID_GUINIVERE, MoveScr_TrueEnding_086767EB)
    EvtSleep(10)
    EvtMoveUnitScript(PID_ROY, MoveScr_TrueEnding_086767EB)
    EvtMoveWait
    EvtSleep(60)

EvtLabel(4)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(ClearTalk)
    EvtFunc(EndAllProcsMark1)
    EvtFunc(StartEndingMonologue2)
    EvtFuncWhile(EndingMonologueExists)
    EvtSleep(75)
    EvtFunc(EndingCredit_ReinitType2)
    EvtJump(EventScr_CharacterEnding)

    EvtClearSkip
    EvtEnd
};

EventScr const * CONST_DATA EventScrs_EndingScene[] = {
    EventScr_TrueEnding,
    EventScr_TrueEnding,
    EventScr_FalseEnding
};

// EventScr @ 086770E0
EventScr CONST_DATA EventScr_TrueEnding[] =
{
    EvtNoSkipNoTextSkip
    EvtSetBgm(0)
    EvtSleep(59)
    EvtFunc(func_fe6_0806E32C)
    EvtUnitCameraOff
    EvtFunc(GC_DarkenScreen)
    EvtSleep(1)
    EvtSetMap(CHAPTER_FINAL, 9, 2)
    EvtFunc(GameEnding_PutUnitsOnPosition1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtGotoIfNotFlag(3, FLAG_IDUNN_NOT_DIE)

    EvtFunc(TruEnding_PlaySe269)
    EvtFadeToWhite(4)
    EvtExitMap
    EvtSleep(30)
    EvtLoadUnits(UnitInfo_TrueEnding_Idunn)
    EvtMoveWait
    EvtFadeFromWhite(4)
    EvtEnterMap

EvtLabel(3)
    EvtSleep(60)
    EvtGotoIfNotFlag(5, FLAG_IDUNN_NOT_DIE)
    EvtGotoIfNotFunc(5, IsFaeBlue)
    EvtJump(EventScr_TrueEnding_IndunnNotDie)
    EvtGoto(9)

EvtLabel(5)
    EvtJump(EventScr_TrueEnding_IndunnDie)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086771CC
EventScr CONST_DATA EventScr_FalseEnding[] =
{
    EvtNoSkipNoTextSkip
    EvtSetBgm(0)
    EvtSleep(30)
    EvtFunc(func_fe6_0806E32C)
    EvtSetBgm(SONG_3C)
    EvtSleep(29)
    EvtFunc(GC_DarkenScreen)
    EvtSleep(1)
    EvtSetMap(CHAPTER_22, 16, 9)
    EvtFunc(func_fe6_0806E074)
    EvtFunc(Epilogue_RemoveEventEngineNoMap)
    EvtMapChangePosition(15, 15)
    EvtFunc(RenderMap)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtSleep(60)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1D1)
    EvtClearTalk
    EvtSleep(64)
    EvtFadeBgmOut(4)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtFunc(EndAllProcsMark1)
    EvtSleep(75)
    EvtSetBgm(SONG_34)
    EvtFunc(StartEndingMonologue3)
    EvtFuncWhile(EndingMonologueExists)
    EvtSleep(128)
    EvtFunc(EndingCredit_ReinitType0)
    EvtJump(EventScr_CharacterEnding)

    EvtClearSkip
    EvtEnd
};

// EventScr @ 086772DC
EventScr CONST_DATA EventScr_CharacterEnding[] =
{
    EvtFunc(StartGameEnding)
    EvtSleep(1)
    EvtFunc(CleanupGame)
    EvtClearSkip
    EvtEnd
};

void StartGameEndingScene(ProcPtr parent)
{
    StartEventLocking(EventScrs_EndingScene[GetEndingId()], parent);
}

void func_fe6_0806E32C(void)
{
    switch (GetEndingId())
    {
        case TRUE_ENDING:
            gEndingSceneKind = 0;
            SetupTrueEndingUids();
            return;

        case NORMAL_ENDING:
            gEndingSceneKind = 1;
            SetupTrueEndingUids();
            return;

        case FAKE_ENDING:
            gEndingSceneKind = 0x80;
            SetupFakeEndingUids();
            return;
    }
}

