#include "ai_perform.h"

#include "hardware.h"
#include "sound.h"
#include "event.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "playerphase.h"
#include "bmfx.h"
#include "faction.h"
#include "action.h"
#include "unitsprite.h"
#include "battle.h"
#include "itemaction.h"
#include "ai_decide.h"
#include "ai_unk.h"
#include "ui.h"
#include "mu.h"
#include "eventinfo.h"

#include "constants/chapters.h"
#include "constants/terrains.h"
#include "constants/songs.h"
#include "constants/msg.h"

struct AiPerformProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ bool (* func)(struct AiPerformProc * proc);
    /* 30 */ u8 unk_30;
    /* 31 */ u8 isUnitVisible;
};

static void AiStartCombatAction(struct AiPerformProc * proc);
static void AiStartEscapeAction(struct AiPerformProc * proc);
static void AiStartStealAction(struct AiPerformProc * proc);
static bool AiPillageAction(struct AiPerformProc * proc);
static bool AiStaffAction(struct AiPerformProc * proc);
static bool AiUseItemAction(struct AiPerformProc * proc);
static bool AiRefreshAction(struct AiPerformProc * proc);
static bool AiTalkAction(struct AiPerformProc * proc);
static bool AiDummyAction(struct AiPerformProc * proc);
static bool AiEscapeAction(struct AiPerformProc * proc);
static bool AiWaitAndClearScreenAction(struct AiPerformProc * proc);

static void AiActionCursor_Idle(struct GenericProc * proc);

struct ProcScr CONST_DATA ProcScr_AiActionCursor[] =
{
    PROC_YIELD,

    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_REPEAT(AiActionCursor_Idle),
    PROC_END,
};

static void AiPerform_WatchUnit(struct AiPerformProc * proc);
static void AiPerform_StartMovement(struct AiPerformProc * proc);
static void AiPerform_WatchTarget(struct AiPerformProc * proc);
static void AiPerform_StartAction(struct AiPerformProc * proc);
static void AiPerform_WaitAction(struct AiPerformProc * proc);
static void AiPerform_Cleanup(struct AiPerformProc * proc);
static void AiPerform_EquipBest(struct AiPerformProc * proc);

struct ProcScr CONST_DATA ProcScr_AiPerform[] =
{
    PROC_19,

    PROC_CALL(AiPerform_WatchUnit),
    PROC_YIELD,

    PROC_CALL(AiPerform_StartMovement),
    PROC_WHILE(MuExistsActive),

    PROC_CALL(AiPerform_WatchTarget),
    PROC_YIELD,

    PROC_CALL(AiPerform_StartAction),
    PROC_REPEAT(AiPerform_WaitAction),

    PROC_CALL_2(StartAvailableMoveEvents),

    PROC_CALL(AiPerform_Cleanup),
    PROC_CALL(AiPerform_EquipBest),

PROC_LABEL(1),
    PROC_END,
};

void AiActionCursor_Idle(struct GenericProc * proc)
{
    PutMapCursor(proc->x, proc->y, proc->unk58);

    if ((gKeySt->held & (KEY_BUTTON_A | KEY_BUTTON_START)) || proc->timer1 > 45)
        Proc_Break(proc);

    proc->timer1++;
}

void AiStartActionCursor(int x, int y, int kind, ProcPtr parent)
{
    struct GenericProc * proc;

    proc = SpawnProcLocking(ProcScr_AiActionCursor, parent);

    proc->x = x;
    proc->y = y;
    proc->unk58 = kind;
    proc->timer1 = 0;
}

void AiPerform_WatchUnit(struct AiPerformProc * proc)
{
    proc->isUnitVisible = TRUE;

    if (gPlaySt.vision != 0 && gPlaySt.faction == FACTION_RED)
    {
        if (gMapFog[gActiveUnit->y][gActiveUnit->x] != 0 || gMapFog[gAiDecision.y_move][gAiDecision.x_move] != 0)
        {
            CameraMoveWatchPosition(proc, gActiveUnit->x, gActiveUnit->y);
        }
        else
        {
            proc->isUnitVisible = FALSE;

            if (gAiDecision.action_id == AI_ACTION_PILLAGE)
            {
                CameraMoveWatchPosition(proc, gAiDecision.x_move, gAiDecision.y_move);
            }
        }
    }
    else
    {
        CameraMoveWatchPosition(proc, gActiveUnit->x, gActiveUnit->y);
    }
}

void AiPerform_StartMovement(struct AiPerformProc * proc)
{
    UnitBeginAction(gActiveUnit);

    HideUnitSprite(gActiveUnit);

    MapFlood_UpToMove(gActiveUnit);
    SetWorkingMap(gMapMovement);

    BuildBestMoveScript(gAiDecision.x_move, gAiDecision.y_move, gWorkingMoveScr);

    if (proc->isUnitVisible)
    {
        StartMu(gActiveUnit);
        SetAutoMuDefaultFacing();
        SetAutoMuMoveScript(gWorkingMoveScr);
    }
}

void AiEndMuAndRefreshUnits(void)
{
    SetMapCursorPosition(gAiDecision.x_move, gAiDecision.y_move);

    if (gPlaySt.vision != 0 && gPlaySt.faction != FACTION_RED)
    {
        RenderMapForFade();

        func_fe6_08017EDC(gAiDecision.x_move, gAiDecision.y_move);

        RefreshEntityMaps();
        RenderMap();

        StartMapFade(TRUE);
    }
    else
    {
        func_fe6_08017EDC(gAiDecision.x_move, gAiDecision.y_move);

        RenderMap();
        RefreshEntityMaps();
    }

    if (gPlaySt.chapter == CHAPTER_FINAL && CheckAvailableVictoryEvent())
        StartAvailableVictoryEvent();

    EndAllMus();

    RefreshEntityMaps();

    ShowUnitSprite(gActiveUnit);
    RefreshUnitSprites();
}

void AiStartCombatAction(struct AiPerformProc * proc)
{
    gAction.id = ACTION_COMBAT;
    gAction.target = gAiDecision.target_id;

    gActiveUnit->x = gAiDecision.x_move;
    gActiveUnit->y = gAiDecision.y_move;

    if ((i8) gAiDecision.item_slot != -1)
    {
        UnitEquipItemSlot(gActiveUnit, gAiDecision.item_slot);
        BattleGenerateReal(gActiveUnit, GetUnit(gAiDecision.target_id));
    }
    else
    {
        BattleGenerateBallistaReal(gActiveUnit, GetUnit(gAiDecision.target_id));
    }

    if (gKeySt->held & KEY_BUTTON_R)
        EndAllMus();

    SpawnProcLocking(ProcScr_CombatAction, proc);
}

void AiStartEscapeAction(struct AiPerformProc * proc)
{
    SHOULD_BE_STATIC u8 SHOULD_BE_CONST scripts[4][3] =
    {
        { MOVE_CMD_MOVE_LEFT,  MOVE_CMD_MOVE_LEFT,  MOVE_CMD_HALT },
        { MOVE_CMD_MOVE_RIGHT, MOVE_CMD_MOVE_RIGHT, MOVE_CMD_HALT },
        { MOVE_CMD_MOVE_DOWN,  MOVE_CMD_MOVE_DOWN,  MOVE_CMD_HALT },
        { MOVE_CMD_MOVE_UP,    MOVE_CMD_MOVE_UP,    MOVE_CMD_HALT },
    };

    if (gAiDecision.x_target != 5 && proc->isUnitVisible)
        SetAutoMuMoveScript(scripts[gAiDecision.x_target]);
}

void AiStartStealAction(struct AiPerformProc * proc)
{
    struct Unit * target = GetUnit(gAiDecision.target_id);

    u16 item = target->items[gAiDecision.item_slot];

    UnitAddItem(gActiveUnit, item);
    UnitRemoveItem(target, gAiDecision.item_slot);

    StartStoleItemPopup(item, proc);
}

bool AiPillageAction(struct AiPerformProc * proc)
{
    static struct PopupInfo CONST_DATA Popup_085C85D0[] =
    {
        POPUP_SONG(SONG_5C),
        POPUP_MSG(MSG_6E6),
        POPUP_END,
    };

    int x = gAiDecision.x_move;
    int y = gAiDecision.y_move;

    if (gMapTerrain[y][x] == TERRAIN_CHEST)
    {
        gActiveUnit->x = gAiDecision.x_move;
        gActiveUnit->y = gAiDecision.y_move;

        gAction.id = ACTION_USEITEM;
        gAiDecision.item_slot = gAiDecision.item_slot;
        gAction.item_slot = gAiDecision.item_slot;

        DoItemAction(proc);
    }
    else
    {
        int y2 = y - 1;
        StartAvailableTileEvent(x, y2);

        PlaySe(SONG_AB);
        StartPopup(Popup_085C85D0, 0x60, UI_WINDOW_REGULAR, proc);
    }

    return TRUE;
}

bool AiStaffAction(struct AiPerformProc * proc)
{
    gActiveUnit->x = gAiDecision.x_move;
    gActiveUnit->y = gAiDecision.y_move;

    gAction.id = ACTION_STAFF;
    gAction.target = gAiDecision.target_id;
    gAction.item_slot = gAiDecision.item_slot;

    DoItemAction(proc);

    return TRUE;
}

bool AiUseItemAction(struct AiPerformProc * proc)
{
    gActiveUnit->x = gAiDecision.x_move;
    gActiveUnit->y = gAiDecision.y_move;

    gAction.id = ACTION_USEITEM;
    gAction.item_slot = gAiDecision.item_slot;

    DoItemAction(proc);

    return TRUE;
}

bool AiRefreshAction(struct AiPerformProc * proc)
{
    return TRUE;
}

bool AiTalkAction(struct AiPerformProc * proc)
{
    gActiveUnit->x = gAiDecision.x_move;
    gActiveUnit->y = gAiDecision.y_move;

    if (gAiDecision.target_id == 0)
    {
        StartAvailableTalkEvent(
            GetUnit(gAiDecision.item_slot)->pinfo->id,
            GetUnit(gAiDecision.x_target)->pinfo->id);
    }

    return TRUE;
}

void AiPerform_WatchTarget(struct AiPerformProc * proc)
{
    struct Unit * target;

    int x = 0;
    int y = 0;

    switch (gAiDecision.action_id)
    {

    case AI_ACTION_NONE:
        return;

    case AI_ACTION_COMBAT:
        target = GetUnit(gAiDecision.target_id);

        x = target->x;
        y = target->y;

        break;

    case AI_ACTION_ESCAPE:
        return;

    case AI_ACTION_STEAL:
        target = GetUnit(gAiDecision.target_id);

        x = target->x;
        y = target->y;

        break;

    case AI_ACTION_PILLAGE:
        return;

    case AI_ACTION_USEITEM:
        return;

    case AI_ACTION_REFRESH:
        target = GetUnit(gAiDecision.target_id);

        x = target->x;
        y = target->y;

        break;

    case AI_ACTION_TALK:
        target = GetUnit(gAiDecision.y_target);

        x = target->x;
        y = target->y;

        break;

    case AI_ACTION_STAFF:
        if (gAiDecision.target_id == 0)
            return;

        target = GetUnit(gAiDecision.target_id);

        x = target->x;
        y = target->y;

        break;

    }

    CameraMoveWatchPosition(proc, x, y);
    AiStartActionCursor(x*16, y*16, MAP_CURSOR_RED_MOVING, proc);
}

void AiPerform_StartAction(struct AiPerformProc * proc)
{
    proc->unk_30 = 0;

    switch (gAiDecision.action_id)
    {

    case AI_ACTION_NONE:
        proc->func = AiDummyAction;
        break;

    case AI_ACTION_COMBAT:
        proc->func = AiDummyAction;
        AiStartCombatAction(proc);
        break;

    case AI_ACTION_ESCAPE:
        AiStartEscapeAction(proc);
        proc->func = AiEscapeAction;
        break;

    case AI_ACTION_STEAL:
        AiStartStealAction(proc);
        proc->func = AiWaitAndClearScreenAction;
        break;

    case AI_ACTION_PILLAGE:
        proc->func = AiPillageAction;
        break;

    case AI_ACTION_STAFF:
        proc->func = AiStaffAction;
        break;

    case AI_ACTION_USEITEM:
        proc->func = AiUseItemAction;
        break;

    case AI_ACTION_REFRESH:
        proc->func = AiRefreshAction;
        break;

    case AI_ACTION_TALK:
        proc->func = AiTalkAction;
        break;

    }
}

void AiPerform_WaitAction(struct AiPerformProc * proc)
{
    proc->unk_30++;

    if (proc->func(proc) == TRUE)
        Proc_Break(proc);
}

void AiPerform_Cleanup(struct AiPerformProc * proc)
{
    AiUpdateUnitsSeekHealing();
    AiEndMuAndRefreshUnits();

    if (!gActiveUnit->pinfo || gActiveUnit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD))
        Proc_Goto(proc, 1);
}

bool AiDummyAction(struct AiPerformProc * proc)
{
    return TRUE;
}

bool AiEscapeAction(struct AiPerformProc * proc)
{
    if (!MuExistsActive())
    {
        gActiveUnit->pinfo = NULL;
        return TRUE;
    }

    return FALSE;
}

bool AiWaitAndClearScreenAction(struct AiPerformProc * proc)
{
    if (proc->unk_30 > 4)
    {
        TmFill(gBg0Tm, 0);
        TmFill(gBg1Tm, 0);
        EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);

        return TRUE;
    }

    return FALSE;
}

void AiPerform_EquipBest(struct AiPerformProc * proc)
{
    u16 equip_flags[ITEMSLOT_INV_COUNT];

    if (AiCanEquip() && AiEquipGetFlags(equip_flags))
    {
        u16 range_danger;
        u16 melee_danger;
        u16 combined_danger;

        AiEquipGetDanger(gAiDecision.x_move, gAiDecision.y_move, &range_danger, &melee_danger, &combined_danger);
        AiEquipBestConsideringDanger(range_danger, melee_danger, combined_danger, equip_flags);
    }
}
