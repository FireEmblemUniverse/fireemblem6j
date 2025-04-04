
#include "action.h"

#include "random.h"
#include "sound.h"
#include "util.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "bmfx.h"
#include "support.h"
#include "battle.h"
#include "unitsprite.h"
#include "itemaction.h"
#include "mu.h"
#include "manim.h"
#include "eventinfo.h"
#include "save_stats.h"

#include "constants/terrains.h"
#include "constants/songs.h"

struct DeathDropAnimProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ i32 x_drop, y_drop;
    /* 38 */ i16 x_from, y_from;
    /* 3C */ i16 x_to, y_to;
    /* 40 */ i16 y_offset;
    /* 42 */ i16 y_speed;
    /* 44 */ i16 y_acceleration;
    /* 46 */ i16 clock;
    /* 48 */ i16 clock_end;
};

bool DoRescueAction(ProcPtr proc);
bool DoRescueDropAction(ProcPtr proc);
bool DoVisitAction(ProcPtr proc);
bool func_fe6_0802A274(ProcPtr proc);
bool func_fe6_0802A2C0(ProcPtr proc);
bool DoCombatAction(ProcPtr proc);
bool func_fe6_0802A35C(ProcPtr proc);
bool DoRefreshAction(ProcPtr proc);
bool DoTalkAction(ProcPtr proc);
bool DoSupportAction(ProcPtr proc);
bool DoStealAction(ProcPtr proc);

struct Action EWRAM_DATA gAction = { { 0 } };

void DeathDropSpriteAnim_Loop(struct DeathDropAnimProc * proc);
void DeathDropSpriteAnim_End(struct DeathDropAnimProc * proc);

struct ProcScr CONST_DATA ProcScr_DeathDropAnim[] =
{
    PROC_REPEAT(DeathDropSpriteAnim_Loop),
    PROC_CALL(DeathDropSpriteAnim_End),
    PROC_END,
};

void CombatAction_MaybeSkipPostBanimDeathFades(struct GenericProc * proc);
void CombatAction_PostBanimDeathFades(struct GenericProc * proc);
void CombatAction_PostBanimDeathFadesEnd(struct GenericProc * proc);
void CombatAction_DoHandleDeaths(struct GenericProc * proc);
void ArenaAction_MaybeSkipDeathFades(struct GenericProc * proc);
void ArenaAction_DoHandleDeaths(struct GenericProc * proc);

struct ProcScr CONST_DATA ProcScr_CombatAction[] =
{
    PROC_CALL(BeginBattleAnimations),
    PROC_SLEEP(1),

    PROC_CALL(BattleApplyGameStateUpdates),

    PROC_WHILE(IsMapFadeActive),

    PROC_CALL(CombatAction_MaybeSkipPostBanimDeathFades),
    PROC_CALL(CombatAction_PostBanimDeathFades),

    PROC_SLEEP(32),

    PROC_CALL(CombatAction_PostBanimDeathFadesEnd),

PROC_LABEL(1),
    PROC_CALL(CombatAction_DoHandleDeaths),
    PROC_YIELD,

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_ArenaAction[] =
{
    PROC_YIELD,

    PROC_CALL(ArenaAction_MaybeSkipDeathFades),
    PROC_CALL(CombatAction_PostBanimDeathFades),

    PROC_SLEEP(32),

    PROC_CALL(CombatAction_PostBanimDeathFadesEnd),

PROC_LABEL(1),
    PROC_CALL(ArenaAction_DoHandleDeaths),
    PROC_YIELD,

    PROC_END,
};

void SaveActionRand(void)
{
    RandGetSt(gAction.action_rand_st);
}

void RestoreActionRand(void)
{
    RandSetSt(gAction.action_rand_st);
}

bool DoAction(ProcPtr proc)
{
    gActiveUnit = GetUnit(gAction.instigator);

    switch (gAction.id)
    {

    case ACTION_WAIT:
    case ACTION_TRAPPED:
        gActiveUnit->flags |= UNIT_FLAG_HAD_ACTION;
        return TRUE;

    case ACTION_RESCUE:
        return DoRescueAction(proc);

    case ACTION_DROP:
        return DoRescueDropAction(proc);

    case ACTION_VISIT:
    case ACTION_SEIZE:
        return DoVisitAction(proc);

    case ACTION_COMBAT:
        return DoCombatAction(proc);

    case ACTION_STAFF:
        DoItemAction(proc);
        return FALSE;

    case ACTION_REFRESH:
        return DoRefreshAction(proc);

    case ACTION_TALK:
        return DoTalkAction(proc);

    case ACTION_SUPPORT:
        return DoSupportAction(proc);

    case ACTION_DOOR:
    case ACTION_CHEST:
        DoItemAction(proc);
        return FALSE;

    case ACTION_STEAL:
        return DoStealAction(proc);

    case ACTION_16:
        return func_fe6_0802A35C(proc);

    case ACTION_USEITEM:
        DoItemAction(proc);
        return FALSE;

    default:
        return TRUE;

    }
}

bool DoRescueAction(ProcPtr proc)
{
    struct Unit * instigator = GetUnit(gAction.instigator);
    struct Unit * target = GetUnit(gAction.target);

    StartRescueTransferAnim(target, GetRescueTransferFacing(instigator->x, instigator->y, target->x, target->y), FALSE, proc);
    UnitRescue(instigator, target);
    HideUnitSprite(target);

    return FALSE;
}

bool DoRescueDropAction(ProcPtr proc)
{
    struct Unit * target = GetUnit(gAction.target);

    if (gMapHidden[gAction.y_target][gAction.x_target] != 0)
    {
        gWorkingMoveScr[0] = MOVE_CMD_BUMP;
        gWorkingMoveScr[1] = MOVE_CMD_HALT;

        SetAutoMuMoveScript(gWorkingMoveScr);

        return FALSE;
    }

    UnitSyncMovement(GetUnit(gAction.instigator));

    StartRescueTransferAnim(target, GetRescueTransferFacing(gAction.x_target, gAction.y_target, target->x, target->y), TRUE, proc);
    UnitDropRescue(GetUnit(gAction.instigator), gAction.x_target, gAction.y_target);

    return FALSE;
}

bool DoVisitAction(ProcPtr proc)
{
    int x = GetUnit(gAction.instigator)->x;
    int y = GetUnit(gAction.instigator)->y;

    StartAvailableTileEvent(x, y);

    return FALSE;
}

void func_fe6_0802A234(ProcPtr proc, struct Unit * unit_a, struct Unit * unit_b)
{
    struct Unit * rescue = GetUnit(unit_a->rescue);

    StartRescueTransferAnim(rescue, GetRescueTransferFacing(unit_b->x, unit_b->y, unit_a->x, unit_a->y), FALSE, proc);
}

bool func_fe6_0802A274(ProcPtr proc)
{
    UnitSyncMovement(GetUnit(gAction.target));

    func_fe6_0802A234(proc, GetUnit(gAction.target), GetUnit(gAction.instigator));
    UnitGiveRescue(GetUnit(gAction.target), GetUnit(gAction.instigator));

    return FALSE;
}

bool func_fe6_0802A2C0(ProcPtr proc)
{
    UnitSyncMovement(GetUnit(gAction.instigator));

    func_fe6_0802A234(proc, GetUnit(gAction.instigator), GetUnit(gAction.target));
    UnitGiveRescue(GetUnit(gAction.instigator), GetUnit(gAction.target));

    return FALSE;
}

bool DoCombatAction(ProcPtr proc)
{
    struct Unit * target = GetUnit(gAction.target);

    if (target == NULL)
        InitObstacleBattleUnit();

    if (gAction.item_slot == ITEMSLOT_BALLISTA)
        BattleGenerateBallistaReal(GetUnit(gAction.instigator), target);
    else
        BattleGenerateReal(GetUnit(gAction.instigator), target);

    SpawnProcLocking(ProcScr_CombatAction, proc);

    return FALSE;
}

bool func_fe6_0802A35C(ProcPtr proc)
{
    SpawnProcLocking(ProcScr_ArenaAction, proc);
    return FALSE;
}

bool DoRefreshAction(ProcPtr proc)
{
    GetUnit(gAction.target)->flags &= ~(UNIT_FLAG_TURN_ENDED | UNIT_FLAG_HAD_ACTION | UNIT_FLAG_AI_PROCESSED);

    BattleInitItemEffect(GetUnit(gAction.instigator), -1);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    gBattleSt.flags = BATTLE_FLAG_REFRESH;

    BattleApplyMiscAction(proc);

    BeginBattleAnimations();

    return FALSE;
}

bool DoTalkAction(ProcPtr proc)
{
    StartAvailableTalkEvent(GetUnit(gAction.instigator)->pinfo->id, GetUnit(gAction.target)->pinfo->id);
    return FALSE;
}

bool DoSupportAction(ProcPtr proc)
{
    int expA, expB;

    struct Unit * target = GetUnit(gAction.target);

    int numA = GetUnitSupportNumByPid(gActiveUnit, target->pinfo->id);
    int numB = GetUnitSupportNumByPid(target, gActiveUnit->pinfo->id);

    if (!CanUnitSupportNow(target, numB))
    {
    }

    UnitGainSupportLevel(gActiveUnit, numA);
    UnitGainSupportLevel(target, numB);

    StartAvailableSupportEvent(gActiveUnit->pinfo->id, target->pinfo->id, GetUnitSupportLevel(gActiveUnit, numA));

    expA = gActiveUnit->supports[numA];
    expB = target->supports[numB];

    if (expA != expB)
    {
        if (expA > expB)
            target->supports[numB] = expA;

        if (expA < expB)
            gActiveUnit->supports[numA] = expB;
    }

    return FALSE;
}

bool DoStealAction(ProcPtr proc)
{
    int item = GetUnit(gAction.target)->items[gAction.item_slot];
    UnitRemoveItem(GetUnit(gAction.target), gAction.item_slot);
    UnitAddItem(GetUnit(gAction.instigator), item);

    BattleInitItemEffect(GetUnit(gAction.instigator), -1);

    gBattleUnitB.terrain = TERRAIN_PLAINS;

    InitBattleUnit(&gBattleUnitB, GetUnit(gAction.target));
    gBattleUnitB.weapon = item;

    BattleApplyMiscAction(proc);

    EndAllMus();
    StartStealManim();

    return FALSE;
}

void DeathDropSpriteAnim_Loop(struct DeathDropAnimProc * proc)
{
    int x = Interpolate(INTERPOLATE_LINEAR, proc->x_from, proc->x_to, proc->clock, proc->clock_end);
    int y = Interpolate(INTERPOLATE_LINEAR, proc->y_from, proc->y_to, proc->clock, proc->clock_end);

    y += proc->y_offset;

    proc->y_offset += proc->y_speed;
    proc->y_speed += proc->y_acceleration;

    PutUnitSprite(7, x - gBmSt.camera.x, y - gBmSt.camera.y, proc->unit);

    ++proc->clock;

    if (proc->clock == proc->clock_end)
        Proc_Break(proc);
}

void DeathDropSpriteAnim_End(struct DeathDropAnimProc * proc)
{
    RefreshEntityMaps();
    RefreshUnitSprites();
}

void DropRescueOnDeath(ProcPtr parent, struct Unit * unit)
{
    if (GetUnitCurrentHp(unit) == 0 && (unit->flags & UNIT_FLAG_RESCUING))
    {
        struct DeathDropAnimProc * proc = SpawnProcLocking(ProcScr_DeathDropAnim, parent);

        proc->unit = GetUnit(unit->rescue);

        UnitGetDropPositionOnDeath(unit, &proc->x_drop, &proc->y_drop);
        UnitDropRescue(unit, proc->x_drop, proc->y_drop);

        proc->x_from = unit->x*16;
        proc->y_from = unit->y*16;

        proc->x_to = proc->x_drop*16;
        proc->y_to = proc->y_drop*16;

        proc->y_offset = 0;
        proc->y_speed = -5;
        proc->y_acceleration = +1;

        proc->clock = 0;
        proc->clock_end = 11;

        proc->unit->flags &= ~UNIT_FLAG_TURN_ENDED;

        UseUnitSprite(GetUnitMapSprite(proc->unit));
        ForceSyncUnitSpriteSheet();

        PlaySe(SONG_AC);
    }
}

void KillUnitOnCombatDeath(struct Unit * unit, struct Unit * opponent)
{
    if (GetUnitCurrentHp(unit) == 0)
    {
        PidStatsSetDefeatInfo(unit->pinfo->id, opponent->pinfo->id, DEFEAT_CAUSE_COMBAT);
        KillUnit(unit);
    }
}

void KillUnitOnArenaDeath(struct Unit * unit)
{
    if (GetUnitCurrentHp(unit) == 0)
    {
        KillUnit(unit);
        PidStatsSetDefeatInfo(unit->pinfo->id, 0, DEFEAT_CAUSE_ARENA);
    }
}

void CombatAction_MaybeSkipPostBanimDeathFades(struct GenericProc * proc)
{
    if ((gBattleSt.flags & BATTLE_FLAG_MAPANIMS) || (gBattleUnitA.unit.hp != 0 && gBattleUnitB.unit.hp != 0))
        Proc_Goto(proc, 1);
}

void CombatAction_PostBanimDeathFades(struct GenericProc * proc)
{
    struct MuProc * mu;

    if (gBattleUnitA.unit.hp == 0)
    {
        mu = FindProc(ProcScr_Mu);

        StartMuDeathFade(mu);
        proc->ptr = mu;
    }

    if (gBattleUnitB.unit.hp == 0)
    {
        RefreshUnitSprites();
        HideUnitSprite(GetUnit(gBattleUnitB.unit.id));

        mu = StartMu(&gBattleUnitB.unit);

        gWorkingMoveScr[0] = MOVE_CMD_MOVE_BASE
            + GetFacingFromTo(gBattleUnitA.unit.x, gBattleUnitA.unit.y, gBattleUnitB.unit.x, gBattleUnitB.unit.y);
        gWorkingMoveScr[1] = MOVE_CMD_HALT;

        SetMuMoveScript(mu, gWorkingMoveScr);
        StartMuDeathFade(mu);

        proc->ptr = mu;
    }
}

void CombatAction_PostBanimDeathFadesEnd(struct GenericProc * proc)
{
    EndMu(proc->ptr);
}

void CombatAction_DoHandleDeaths(struct GenericProc * proc)
{
    struct Unit * unit_a = GetUnit(gBattleUnitA.unit.id);
    struct Unit * unit_b = GetUnit(gBattleUnitB.unit.id);

    DropRescueOnDeath(proc, unit_a);
    DropRescueOnDeath(proc, unit_b);

    KillUnitOnCombatDeath(unit_a, unit_b);
    KillUnitOnCombatDeath(unit_b, unit_a);
}

void func_fe6_0802A7F4(void)
{
    int song = GetActiveMapSong();

    if (GetCurrentBgmSong() != song)
        StartBgmExt(song, 6, NULL);
}

void ArenaAction_MaybeSkipDeathFades(struct GenericProc * proc)
{
    // prevent playing any animations for battler B (which would be the arena opponent, not on the map)
    gBattleUnitB.unit.hp = 1;

    if (gBattleUnitA.unit.hp != 0)
        Proc_Goto(proc, 1);
}

void ArenaAction_DoHandleDeaths(struct GenericProc * proc)
{
    KillUnitOnArenaDeath(gActiveUnit);
    DropRescueOnDeath(proc, gActiveUnit);
}
