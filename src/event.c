#include "event.h"
#include "eventscript.h"

#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "armfunc.h"
#include "proc.h"
#include "icon.h"
#include "sprite.h"
#include "talk.h"
#include "gamecontroller.h"
#include "msg.h"
#include "util.h"
#include "bm.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "bmfx.h"
#include "faction.h"
#include "gold.h"
#include "unitsprite.h"
#include "battle.h"
#include "trap.h"
#include "bmio.h"
#include "chapter.h"
#include "chapterinfo.h"
#include "subtitlehelp.h"
#include "ai_decide.h"
#include "ai_perform.h"
#include "ai_utility.h"
#include "ui.h"
#include "mu.h"
#include "worldmap.h"
#include "banim_ekrbattle.h"
#include "eventinfo.h"

#include "constants/videoalloc_global.h"
#include "constants/videoalloc_wm.h"
#include "constants/videoalloc_banim.h"
#include "constants/terrains.h"
#include "constants/songs.h"
#include "constants/msg.h"

static int sUnk_085C3FD8 = 0;
static int sUnk_030000F0;

static struct Unit * sPopupUnit;
static u16 sPopupItem;
static int sPopupNumber;

void func_fe6_0800CCD4(void)
{
    sUnk_085C3FD8++;
}

void MoveUnitFromInfo(struct UnitInfo const * info, struct Unit * unit, ProcPtr parent);

void LoadUnitWrapper(struct UnitInfo const * info, ProcPtr parent)
{
    struct Unit * unit;

    if (UnitInfoRequiresNoMovement(info))
        return;

    if (info->faction_id == FACTION_ID_BLUE)
        unit = GetUnitByPid(info->pid);
    else
        unit = NULL;

    if (!unit)
        unit = CreateUnit(info);

    if ((gPlaySt.flags & PLAY_FLAG_HARD) && info->faction_id == FACTION_ID_RED)
        UnitApplyBonusLevels(unit, GetChapterInfo(gPlaySt.chapter)->hard_bonus_levels);

    MoveUnitFromInfo(info, unit, parent);
    RefreshEntityMaps();
}

void FakeLoadUnit(struct UnitInfo const * info, struct Unit * unit)
{
    MoveUnitFromInfo(info, unit, NULL);
    RefreshEntityMaps();
}

void MoveUnitFromInfo(struct UnitInfo const * info, struct Unit * unit, ProcPtr parent)
{
    if (!unit)
        return;

    if (parent && !(unit->flags & UNIT_FLAG_UNDER_ROOF))
    {
        TryMoveUnit(unit, info->x_load, info->y_load, FALSE);
        RefreshUnitSprites();

        if (info->x_load != info->x_move || info->y_load != info->y_move)
            TryMoveUnitDisplayed(parent, unit, info->x_move, info->y_move);
    }
    else
    {
        TryMoveUnit(unit, info->x_move, info->y_move, TRUE);
        RefreshUnitSprites();
    }
}

bool func_fe6_0800CE44(void)
{
    if (gKeySt->held & KEY_BUTTON_R)
        return TRUE;

    return FALSE;
}

bool func_fe6_0800CE74(void)
{
    sUnk_030000F0 = 0;
    return TRUE;
}

int func_fe6_0800CE90(void)
{
    static u8 CONST_DATA gUnk_085C3FDC[] = { 9, 27, 28, 31, 38, 1, 0 };

    return gUnk_085C3FDC[sUnk_030000F0++];
}

int PreparePopup(struct PopupProc * proc)
{
    int result = 0;

    char buf[0x10];
    struct PopupInfo const * it;

    for (it = proc->info; it->cmd; ++it)
    {
        switch (it->cmd)
        {

        case POPUP_CMD_SONG:
            proc->songPlayed = it->arg;
            break;

        case POPUP_CMD_NUMBER:
            result += NumberToString(sPopupNumber, buf)*8;
            break;

        case POPUP_CMD_ICON_ITEM:
            proc->iconX = result;
            proc->icon = GetItemIcon(sPopupItem);
            ApplyIconPalette(0, proc->iconPalid);

            result += 16;
            break;

        case POPUP_CMD_ICON_IKIND:
            proc->iconX = result;
            proc->icon = sPopupItem + 0x70; // TODO: icon constants?
            ApplyIconPalette(1, proc->iconPalid);

            result += 16;
            break;

        case POPUP_CMD_COLOR:
            break;

        case POPUP_CMD_MSG:
            result += GetStringTextLen(DecodeMsg(it->arg));
            break;

        case POPUP_CMD_STR:
            result += GetStringTextLen((char const *) it->arg);
            break;

        case POPUP_CMD_UNIT_NAME:
            result += GetStringTextLen(DecodeMsg(sPopupUnit->pinfo->msg_name));
            break;

        case POPUP_CMD_ITEM_NAME:
            result += GetStringTextLen(GetItemName(sPopupItem));
            break;

        case POPUP_CMD_SPACE:
            result += it->arg;
            break;

        default:
            break;

        }
    }

    return result;
}

void PutPopup(struct PopupInfo const * info, struct Text text)
{
    char buf[0x10];

    for (; info->cmd; ++info)
    {
        switch (info->cmd)
        {

        case POPUP_CMD_NUMBER:
            NumberToString(sPopupNumber, buf);
            Text_DrawString(&text, buf);
            break;

        case POPUP_CMD_ICON_ITEM:
            Text_Skip(&text, 16);
            break;

        case POPUP_CMD_ICON_IKIND:
            Text_Skip(&text, 16);
            break;

        case POPUP_CMD_COLOR:
            Text_SetColor(&text, info->arg);
            break;

        case POPUP_CMD_MSG:
            Text_DrawString(&text, DecodeMsg(info->arg));
            break;

        case POPUP_CMD_STR:
            Text_DrawString(&text, (char const *) info->arg);
            break;

        case POPUP_CMD_UNIT_NAME:
            Text_DrawString(&text, DecodeMsg(sPopupUnit->pinfo->msg_name));
            break;

        case POPUP_CMD_ITEM_NAME:
            Text_DrawString(&text, GetItemName(sPopupItem));
            break;

        case POPUP_CMD_SPACE:
            Text_Skip(&text, info->arg);
            break;

        default:
            break;

        }
    }

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);
}

void Popup_OnInit(struct PopupProc * proc)
{
    proc->xParam = 0xFF;
    proc->yParam = 0xFF;

    proc->color = TEXT_COLOR_SYSTEM_WHITE;

    proc->icon = UINT16_MAX;
    proc->iconX = 0;

    proc->songPlayed = 0;
}

void Popup_Prepare(struct PopupProc * proc)
{
    InitTextFont(NULL,
        (u8 *) VRAM + GetBgChrOffset(0) + BGCHR_0_TEXT_POPUP * CHR_SIZE,
        BGCHR_0_TEXT_POPUP, BGPAL_TEXT_DEFAULT);

    ClearIcons();
    UnpackUiWindowFrameGraphics();

    SetBlendNone();
    SetWinEnable(0, 0, 0);

    proc->widthPx = PreparePopup(proc);
}

void Popup_FadeBgmOut(struct PopupProc * proc)
{
    if (proc->songPlayed != 0)
        StartBgmVolumeChange(0x100, 0x80, 16, proc);
}

void Popup_PlaySe(struct PopupProc * proc)
{
    if (proc->songPlayed != 0)
        PlaySe(proc->songPlayed);
}

void Popup_FadeBgmIn(struct PopupProc * proc)
{
    if (proc->songPlayed != 0)
        StartBgmVolumeChange(0x80, 0x100, 16, proc);
}

void PopupIconSprite_OnIdle(struct GenericProc * proc)
{
    PutOamHi(proc->x, proc->y, Sprite_16x16, (u16) proc->unk4A);
}

void Popup_Display(struct PopupProc * proc)
{
    struct GenericProc * gproc;

    struct Text text;

    int width;
    int textoff;
    int x, y;

    proc->widthPx = PreparePopup(proc);
    width = proc->widthPx >> 3;

    if (proc->widthPx & 7)
        width++;

    textoff = (width*8 - proc->widthPx) >> 1;

    if (proc->xParam == -1)
        x = ((30 - width) >> 1) - 1;
    else
        x = proc->xParam;

    if (proc->yParam == -1)
        y = 8;
    else
        y = proc->yParam;

    PutUiWindowFrame(x, y, width + 2, 4, proc->window_kind);

    proc->frameX = x;
    proc->frameY = y;

    proc->frameWidth = width + 2;
    proc->frameHeight = 3;

    proc->iconX += textoff;

    InitText(&text, width);

    Text_SetColor(&text, proc->color);
    Text_SetCursor(&text, textoff);

    PutPopup(proc->info, text);

    if (proc->icon != UINT16_MAX)
        PutIconObjImg(proc->icon, proc->iconChr);

    PutText(&text, gBg0Tm + TM_OFFSET(x + 1, y + 1));

    ResetText();

    if (proc->icon != UINT16_MAX)
    {
        gproc = SpawnProc(ProcScr_PopupIconSprite, proc);

        gproc->x = (proc->frameX+1)*8 + proc->iconX;
        gproc->y = (proc->frameY+1)*8;

        gproc->unk4A = proc->iconChr | OAM2_PAL(proc->iconPalid);
    }
}

void Popup_WaitForEnd(struct PopupProc * proc)
{
    if (proc->clock < 0)
    {
        if (gKeySt->pressed)
            Proc_Break(proc);
    }
    else
    {
        if (proc->clock == 0)
            return;

        proc->clock--;

        if (proc->clock == 0)
            Proc_Break(proc);
    }
}

void Popup_Clear(struct PopupProc * proc)
{
    TmFillRect(gBg0Tm + TM_OFFSET(proc->frameX, proc->frameY), proc->frameWidth, proc->frameHeight, 0);
    TmFillRect(gBg1Tm + TM_OFFSET(proc->frameX, proc->frameY), proc->frameWidth, proc->frameHeight, 0);

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);
}

void SetPopupUnit(struct Unit * unit)
{
    sPopupUnit = unit;
}

void SetPopupItem(u16 item)
{
    sPopupItem = item;
}

void SetPopupNumber(int number)
{
    sPopupNumber = number;
}

ProcPtr StartPopup(struct PopupInfo const * info, int duration, int window_kind, ProcPtr parent)
{
    return StartPopupExt(info, duration, window_kind, 0x240, 4, parent);
}

ProcPtr StartPopupExt(struct PopupInfo const * info, int duration, int window_kind, int iconChr, int iconPal, ProcPtr parent)
{
    struct PopupProc * proc;

    if (parent)
        proc = SpawnProcLocking(ProcScr_Popup, parent);
    else
        proc = SpawnProc(ProcScr_Popup, PROC_TREE_3);

    proc->clock = duration;
    proc->info = info;
    proc->window_kind = window_kind;
    proc->iconChr = iconChr;
    proc->iconPalid = iconPal + 0x10;

    return proc;
}

void EndPopup(void)
{
    Proc_EndEach(ProcScr_Popup);
}

void DisableEventSkip(void)
{
    Proc_ForEach(ProcScr_Event, EventDisableSkip);
}

void EventDisableSkip(ProcPtr proc)
{
    EvtCmd_NoSkip(proc);
}

void Event_FadeOutOfBackgroundTalk(struct EventProc * proc)
{
    SpawnProcLocking(ProcScr_SceneReturnFromBackgroundTalk, proc);
}

void Event_FadeOutOfSkip(struct EventProc * proc)
{
    SpawnProcLocking(ProcScr_SceneEndFade, proc);
}

void FadeFromBg_FadeToBlack(struct GenericProc * proc)
{
    if (((struct EventProc *) proc->proc_parent)->flags & EVENT_FLAG_SKIPPED)
        return;

    StartMidLockingFadeToBlack(proc);
}

void FadeFromBg_FadeFromBlack(struct GenericProc * proc)
{
    struct EventProc * evproc = proc->proc_parent;

    if (!(evproc->flags & EVENT_FLAG_SKIPPED))
        StartMidLockingFadeFromBlack(proc);
}

void FadeFromBg_ClearScreen(struct GenericProc * proc)
{
    InitBmDisplay();
    UnlockBmDisplay();
    ReleaseMus();

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);

    EnableBgSync(BG0_SYNC_BIT);
    EnableBgSync(BG1_SYNC_BIT);

    ClearTalk();
}

void FadeFromSkip_Start(struct GenericProc * proc)
{
    struct EventProc * evproc = proc->proc_parent;

    InitBmDisplay();

    if (evproc->flags & EVENT_FLAG_SKIPPED)
    {
        if (evproc->no_map)
            StartLockingFadeFromBlack(0x20, proc);

        return;
    }

    StartMidLockingFadeFromBlack(proc);
}

ProcPtr StartEvent(EventScr const * script)
{
    return StartEventInternal(script, PROC_TREE_3);
}

ProcPtr StartEventLocking(EventScr const * script, ProcPtr parent)
{
    return StartEventInternal(script, parent);
}

ProcPtr StartEventInternal(EventScr const * script, ProcPtr parent)
{
    struct EventProc * proc = FindProc(ProcScr_Event);

    if (proc)
    {
        gEventScriptQueue[gEventScriptQueueIt] = script;
        gEventScriptQueueIt++;

        return proc;
    }

    gEventScriptQueueIt = 0;
    gEventScriptQueue[gEventScriptQueueIt] = NULL;

    if ((int) parent < 8)
        proc = SpawnProc(ProcScr_Event, parent);
    else
        proc = SpawnProcLocking(ProcScr_Event, parent);

    proc->script_start = script;
    proc->script = script;

    proc->on_idle = NULL;
    proc->on_skip = NULL;

    proc->msg_param = 0;

    proc->flags = EVENT_FLAG_UNITCAM;

    proc->sleep_duration = 0;
    proc->background = -1;
    proc->no_map = FALSE;

    MapFill(gMapOther, 0);

    switch (proc->script[0])
    {

    case EVT_CMD_NOSKIP:
        proc->script++;
        EvtCmd_NoSkip(proc);

        break;

    case EVT_CMD_NOSKIP_NOTEXTSKIP:
        proc->script++;
        EvtCmd_NoSkipNoTextSkip(proc);

        break;

    default:
        break;

    }

    return proc;
}

void Event_OnInit(struct EventProc * proc)
{
    LockGame();
    proc->on_idle = NULL;
}

void Event_OnEnd(struct EventProc * proc)
{
    UnlockGame();
}

void Event_ResetText(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_NOAUTOCLEAR)
        return;

    SetTextFont(NULL);
    InitSystemTextFont();

    UnpackUiWindowFrameGraphics();
}

void Event_RestartFromQueued(struct EventProc * proc)
{
    proc->flags &= ~EVENT_FLAG_SKIPPED;

    if (gEventScriptQueueIt != 0)
    {
        gEventScriptQueueIt--;

        proc->on_idle = NULL;

        proc->script_start = gEventScriptQueue[gEventScriptQueueIt];
        proc->script = gEventScriptQueue[gEventScriptQueueIt];

        Proc_Goto(proc, 0);
    }
}

void Event_MaybeEndMapMain(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_ENDMAPMAIN)
        EndMapMain();
}

void Event_ClearTextOnSkip(struct EventProc * proc)
{
    Fade_CommonCallBack();
    Proc_EndEach(ProcScr_TalkOpen);

    if (proc->background == -1)
        SetMuMaxWalkSpeed();
}

bool Event_SkipAllowed(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return FALSE;

    if (proc->flags & EVENT_FLAG_DISABLESKIP)
        return FALSE;

    if (IsBattleDeamonActive())
        return FALSE;

    return TRUE;
}

void Event_DarkenThenFunc(void (* func)(struct EventProc * proc), struct EventProc * eproc)
{
    struct DarkenFuncProc * proc = SpawnProcLocking(ProcScr_DarkenThenFunc, eproc);

    proc->func = func;
    proc->eventProc = eproc;
}

void DarkenThenFunc_OnInit(struct DarkenFuncProc * proc)
{
    DarkenThenFunc_StartDarken(proc);

    proc->q4_darkenStep = 0x20;
}

void DarkenThenFunc_OnLoop(struct DarkenFuncProc * proc)
{
    void (* func)(struct EventProc * proc) = proc->func;

    DarkenThenFunc_StepDarken(proc);

    if (gDispIo.blend_y == 0x10)
    {
        func(proc->eventProc);
        Proc_Break(proc);
    }
}

void DarkenThenFunc_StartDarken(struct DarkenFuncProc * proc)
{
    gDispIo.win_ct.win0_enable_blend = 1;
    gDispIo.win_ct.win1_enable_blend = 1;
    gDispIo.win_ct.wobj_enable_blend = 1;
    gDispIo.win_ct.wout_enable_blend = 1;

    SetBlendDarken(0);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);

    proc->q4_darkenStep = 0x10;
    proc->q4_darken = 0;
}

void DarkenThenFunc_StepDarken(struct DarkenFuncProc * proc)
{
    if (gDispIo.blend_y == 0x10)
    {
        Proc_End(proc);
        return;
    }

    proc->q4_darken += proc->q4_darkenStep;

    if (proc->q4_darken >= 0x100)
        proc->q4_darken = 0x100;

    gDispIo.blend_y = proc->q4_darken >> 4;
}

void Event_MainLoop(struct EventProc * proc)
{
    if (FindProc(ProcScr_SubtitleHelpDarkener) != NULL)
        return;

    if (IsSubtitleHelpActive())
        return;

    if (IsMapFadeActive())
        return;

    if (Event_SkipAllowed(proc) && (gKeySt->pressed & KEY_BUTTON_START))
    {
        if (proc->on_skip)
            proc->on_skip();

        proc->flags |= EVENT_FLAG_SKIPPED;

        if (!IsTalkDebugActive())
        {
            proc->no_map = TRUE;

            if (WmSpriteExists())
                Event_ClearTextOnSkip(proc);
            else
                Event_DarkenThenFunc(Event_ClearTextOnSkip, proc);
        }

        Proc_LockEachMarked(PROC_MARK_5);
        return;
    }

    if (proc->sleep_duration != 0)
    {
        proc->sleep_duration--;
        return;
    }

    if (proc->on_idle)
    {
        proc->on_idle(proc);
        return;
    }

    while (TRUE)
    {
        int cmd, result;

        cmd = *proc->script++;
        result = gEventCmdInfoTable[cmd].func(proc);

        if (result == EVENT_CMDRET_JUMPED)
            continue;

        if (result == EVENT_CMDRET_REPEAT)
        {
            proc->script--;
            return;
        }

        proc->script = proc->script - 1 + gEventCmdInfoTable[cmd].size;

        if (result == EVENT_CMDRET_YIELD)
            return;
    }
}

void Event_WaitForFaceEnd(struct EventProc * proc)
{
    if (!(proc->flags & EVENT_FLAG_NOAUTOCLEAR) && FaceExists())
        return;

    Proc_Break(proc);
}

int EvtCmd_Sleep(struct EventProc * proc)
{
    // script[0]: duration

    int duration = proc->script[0];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_YIELD;

    if (duration > 0)
        duration--;

    proc->sleep_duration = duration;

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_Background(struct EventProc * proc)
{
    // script[0]: background

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    if (proc->background == -1)
    {
        LockBmDisplay();
        LockMus();
    }

    DisplayBackground(proc->script[0]);
    proc->background = proc->script[0];

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_BackgroundMore(struct EventProc * proc)
{
    // script[0]: background

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    if (proc->background == -1)
    {
        LockBmDisplay();
        LockMus();
    }

    DisplayBackgroundNoClear(proc->script[0]);
    proc->background = proc->script[0];

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_ClearTalk(struct EventProc * proc)
{
    if (proc->background == -1)
    {
        EventClearTalkDisplayed(proc);
        SetDispEnable(1, 1, 1, 1, 1);

        return EVENT_CMDRET_YIELD;
    }

    Event_FadeOutOfBackgroundTalk(proc);
    proc->background = -1;

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_ClearSkip(struct EventProc * proc)
{
    if (!(proc->flags & EVENT_FLAG_SKIPPED))
        return EVENT_CMDRET_CONTINUE;

    Event_FadeOutOfSkip(proc);
    proc->background = -1;

    return EVENT_CMDRET_YIELD;
}

void DisplayBackground(int background)
{
    ClearTalk();

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(2, 0, 0);
    SetBgOffset(3, 0, 0);

    Decompress(gBackgroundTable[background].img, (u8 *) VRAM + GetBgChrOffset(3));
    TmApplyTsa(gBg3Tm, gBackgroundTable[background].tsa, TILEREF(0, 8));
    ApplyPalettes(gBackgroundTable[background].pal, 8, 4);

    EnableBgSync(BG3_SYNC_BIT);
    gPal[0] = 0;
}

void DisplayBackgroundNoClear(int background)
{
    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(2, 0, 0);
    SetBgOffset(3, 0, 0);

    Decompress(gBackgroundTable[background].img, (u8 *) VRAM + GetBgChrOffset(3));
    TmApplyTsa(gBg3Tm, gBackgroundTable[background].tsa, TILEREF(0, 8));
    ApplyPalettes(gBackgroundTable[background].pal, 8, 4);

    EnableBgSync(BG3_SYNC_BIT);
    gPal[0] = 0;
}

int EvtCmd_Talk(struct EventProc * proc)
{
    // script[0]: msgid

    proc->flags &= ~EVENT_FLAG_TEXTSKIPPED;

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    InitTalk(0x80, 2, TRUE);
    StartTalkMsg(1, 1, proc->script[0]);

    if (proc->flags & EVENT_FLAG_DISABLETEXTSKIP)
        SetTalkFlag(TALK_FLAG_NOSKIP);

    proc->on_idle = EventTalkWait;

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_TalkMore(struct EventProc * proc)
{
    // script[0]: msgid

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    if (proc->flags & EVENT_FLAG_TEXTSKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartTalkMsg(1, 1, proc->script[0]);

    if (proc->flags & EVENT_FLAG_DISABLETEXTSKIP)
        SetTalkFlag(TALK_FLAG_NOSKIP);

    proc->on_idle = EventTalkWait;

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_TalkAuto(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_YIELD;

    InitTalk(0x80, 2, TRUE);
    StartTalkMsg(1, 1, proc->msg_param);

    if (proc->flags & EVENT_FLAG_DISABLETEXTSKIP)
        SetTalkFlag(TALK_FLAG_NOSKIP);

    proc->on_idle = EventTalkWait;

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_TalkContinue(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        EndTalk();
        return EVENT_CMDRET_YIELD;
    }

    ResumeTalk();
    proc->on_idle = EventTalkWait;

    return EVENT_CMDRET_YIELD;
}

void EventTalkWait(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        EndTalk();
        proc->on_idle = NULL;

        return;
    }

    if (!IsTalkActive() || IsTalkLocked())
        proc->on_idle = NULL;
}

int EvtCmd_CameraPosition(struct EventProc * proc)
{
    // script[0]: coords (u16, u16)

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->no_map)
    {
        gBmSt.camera.x = GetCameraAdjustedX(EVTCMD_GET_X(proc->script[0]) << 4);
        gBmSt.camera.y = GetCameraAdjustedY(EVTCMD_GET_Y(proc->script[0]) << 4);

        SetMapCursorPosition(
            EVTCMD_GET_X(proc->script[0]),
            EVTCMD_GET_Y(proc->script[0]));

        RenderMap();

        return EVENT_CMDRET_YIELD;
    }

    CameraMoveWatchPosition(proc,
        EVTCMD_GET_X(proc->script[0]),
        EVTCMD_GET_Y(proc->script[0]));

    SetMapCursorPosition(
        EVTCMD_GET_X(proc->script[0]),
        EVTCMD_GET_Y(proc->script[0]));

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_CameraPid(struct EventProc * proc)
{
    // script[0]: pid of unit

    struct Unit * unit = GetUnitByPid(proc->script[0]);

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->no_map)
    {
        gBmSt.camera.x = GetCameraAdjustedX(unit->x << 4);
        gBmSt.camera.y = GetCameraAdjustedY(unit->y << 4);

        SetMapCursorPosition(unit->x, unit->y);

        RenderMap();

        return EVENT_CMDRET_YIELD;
    }

    CameraMoveWatchPosition(proc, unit->x, unit->y);
    SetMapCursorPosition(unit->x, unit->y);

    return EVENT_CMDRET_YIELD;
}

bool CanDisplayUnitMovement(struct EventProc * proc, int x, int y)
{
    if (proc->flags & EVENT_FLAG_UNITCAM)
    {
        if (FindProc(ProcScr_CamMove) != NULL || CameraMoveWatchPosition(proc, x, y))
            return FALSE;
    }

    if (!CanStartMu())
        return FALSE;

    return TRUE;
}

int EvtCmd_MovePosition(struct EventProc * proc)
{
    // script[0]: coords (u16, u16) of unit to move
    // script[1]: coords (u16, u16) to move to

    struct Unit * unit;

    int xUnit = EVTCMD_GET_X(proc->script[0]);
    int yUnit = EVTCMD_GET_Y(proc->script[0]);

    int x_target = EVTCMD_GET_X(proc->script[1]);
    int y_target = EVTCMD_GET_Y(proc->script[1]);

    unit = GetUnit(gMapUnit[yUnit][xUnit]);

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->no_map)
    {
        TryMoveUnit(unit, x_target, y_target, TRUE);
        RefreshUnitSprites();

        return EVENT_CMDRET_CONTINUE;
    }

    if (!CanDisplayUnitMovement(proc, xUnit, yUnit))
        return EVENT_CMDRET_REPEAT;

    TryMoveUnitDisplayed(proc, unit, x_target, y_target);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_MovePid(struct EventProc * proc)
{
    // script[0]: pid of unit to move
    // script[1]: coords (u16, u16) to move to

    struct Unit * unit = GetUnitByPid(proc->script[0]);

    int x_target = EVTCMD_GET_X(proc->script[1]);
    int y_target = EVTCMD_GET_Y(proc->script[1]);

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->no_map)
    {
        TryMoveUnit(unit, x_target, y_target, TRUE);
        RefreshUnitSprites();

        return EVENT_CMDRET_CONTINUE;
    }

    if (!CanDisplayUnitMovement(proc, unit->x, unit->y))
        return EVENT_CMDRET_REPEAT;

    TryMoveUnitDisplayed(proc, unit, x_target, y_target);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_MovePidScript(struct EventProc * proc)
{
    // script[0]: pid of unit to move
    // script[1]: pointer to move script

    struct Unit * unit = GetUnitByPid(proc->script[0]);

    int x, y;

    u8 const * movescr = (u8 const *) proc->script[1];

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->no_map)
    {
        x = unit->x;
        y = unit->y;

        ApplyMoveScriptToCoordinates(&x, &y, movescr);

        TryMoveUnit(unit, x, y, FALSE);
        RefreshUnitSprites();

        return EVENT_CMDRET_CONTINUE;
    }

    if (!CanDisplayUnitMovement(proc, unit->x, unit->y))
        return EVENT_CMDRET_REPEAT;

    DisplayMovement(proc, unit, movescr);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_MovePositionScript(struct EventProc * proc)
{
    // script[0]: coords (u16, u16) of unit to move
    // script[1]: pointer to move script

    struct Unit * unit;

    int x = EVTCMD_GET_X(proc->script[0]);
    int y = EVTCMD_GET_Y(proc->script[0]);

    u8 const * movescr = (u8 const *) proc->script[1];

    unit = GetUnit(gMapUnit[y][x]);

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->no_map)
    {
        ApplyMoveScriptToCoordinates(&x, &y, movescr);

        TryMoveUnit(unit, x, y, FALSE);
        RefreshUnitSprites();

        return EVENT_CMDRET_CONTINUE;
    }

    if (!CanDisplayUnitMovement(proc, x, y))
        return EVENT_CMDRET_REPEAT;

    DisplayMovement(proc, unit, movescr);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_MovePidNextTo(struct EventProc * proc)
{
    // script[0]: pid of unit to move
    // script[1]: pid of unit to go next to

    struct Unit * unit = GetUnitByPid(proc->script[1]);

    int x = unit->x;
    int y = unit->y;

    unit = GetUnitByPid(proc->script[0]);

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->no_map)
    {
        TryMoveUnit(unit, x, y, TRUE);
        RefreshUnitSprites();

        return EVENT_CMDRET_CONTINUE;
    }

    if (!CanDisplayUnitMovement(proc, unit->x, unit->y))
        return EVENT_CMDRET_REPEAT;

    TryMoveUnitDisplayed(proc, unit, x, y);

    return EVENT_CMDRET_CONTINUE;
}

void TryMoveUnit(struct Unit * unit, int x, int y, i8 moveClosest)
{
    struct Vec2i vec;

    if (x == 0xFF)
        x = -1;

    if (y == 0xFF)
        y = -1;

    vec.x = x;
    vec.y = y;

    // ..?

    if (gMapTerrain[y][x] == TERRAIN_TILE_00)
    {
    }
    else if (moveClosest)
    {
        AiGetUnitClosestValidPosition(unit, x, y, &vec);
    }

    unit->x = vec.x;
    unit->y = vec.y;

    UnitSyncMovement(unit);

    if (unit->flags & UNIT_FLAG_UNDER_ROOF)
        return;

    unit->flags &= ~(UNIT_FLAG_HIDDEN | UNIT_FLAG_NOT_DEPLOYED);

    RefreshEntityMaps();
}

bool TryMoveUnitDisplayed(ProcPtr proc, struct Unit * unit, int x, int y)
{
    struct Vec2i vec;

    int terrainChanged = FALSE;

    if (x == 0xFF)
        x = -1;

    if (y == 0xFF)
        y = -1;

    vec.x = x;
    vec.y = y;

    if (gMapTerrain[y][x] == TERRAIN_TILE_00)
    {
        terrainChanged = TRUE;
        gMapTerrain[y][x] = TERRAIN_PLAINS;
    }
    else
    {
        AiGetUnitClosestValidPosition(unit, x, y, &vec);
    }

    MapFloodRange_Unitless(unit->x, unit->y, unit->jinfo->mov_table);
    BuildBestMoveScript(vec.x, vec.y, gWorkingMoveScr);

    if (terrainChanged)
        gMapTerrain[y][x] = TERRAIN_TILE_00;

    return DisplayMovement(proc, unit, gWorkingMoveScr);
}

bool DisplayMovement(struct EventProc * proc, struct Unit * unit, u8 const * movescr)
{
    struct GenericProc * gproc;

    struct MuProc * mu = StartMu(unit);

    int x, y;

    if (!(proc->flags & EVENT_FLAG_UNITCAM))
        DisableMuCamera(mu);

    gproc = SpawnProc(ProcScr_EventWaitForMu, PROC_TREE_3);
    gproc->ptr = mu;

    HideUnitSprite(unit);
    unit->flags |= UNIT_FLAG_HIDDEN;

    x = unit->x;
    y = unit->y;

    gMapOther[y][x] = 0;

    ApplyMoveScriptToCoordinates(&x, &y, movescr);

    gproc->x = x;
    gproc->y = y;

    SetMuMoveScript(mu, movescr);

    gMapOther[y][x] = unit->id;

    return TRUE;
}

void WaitForMu_0800F094(struct GenericProc * proc)
{
}

void WaitForMu_OnLoop(struct GenericProc * proc)
{
    struct MuProc * mu = proc->ptr;
    struct Unit * unit;

    if (IsMuActive(mu))
        return;

    EndMu(mu);

    unit = mu->unit;

    unit->x = proc->x;
    unit->y = proc->y;

    UnitSyncMovement(unit);

    ShowUnitSprite(unit);
    unit->flags &= ~UNIT_FLAG_HIDDEN;

    RefreshEntityMaps();
    RefreshUnitSprites();

    Proc_Break(proc);
}

void EventUnitLoadWait(struct EventProc * proc);

int EvtCmd_LoadUnits(struct EventProc * proc)
{
    // script[0]: address of unit info list

    MapFill(gMapOther, 0);

    proc->unit_info = (struct UnitInfo const *) proc->script[0];
    proc->on_idle = EventUnitLoadWait;

    return EVENT_CMDRET_YIELD;
}

void EventLoadUnitsAsParty(struct EventProc * proc);

int EvtCmd_LoadUnitsParty(struct EventProc * proc)
{
    // script[0]: address of unit info list

    MapFill(gMapOther, 0);

    proc->unit_info = (struct UnitInfo const *) proc->script[0];
    EventLoadUnitsAsParty(proc);

    return EVENT_CMDRET_YIELD;
}

int GetNextAvailableBlueUnitId(int start)
{
    int i;

    for (i = start; i < 0x40; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if (unit->flags & UNIT_FLAG_UNAVAILABLE)
            continue;

        return i;
    }

    return 0;
}

bool UnitInfoRequiresNoMovement(struct UnitInfo const * info)
{
    if (info->x_load == info->x_move)
        if (info->y_load == info->y_move)
            if (gMapUnit[info->y_load][info->x_load] != 0)
                return TRUE;

    return FALSE;
}

void EventUnitLoadWait(struct EventProc * proc)
{
    struct UnitInfo const * info = proc->unit_info;

    while (TRUE)
    {
        if (info->pid == 0)
        {
            proc->on_idle = EventMovementWait;
            break;
        }

        if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->no_map)
        {
            while (info->pid != 0)
            {
                LoadUnitWrapper(info, NULL);
                info++;
            }

            proc->on_idle = NULL;
            return;
        }

        if (!UnitInfoRequiresNoMovement(info))
        {
            if (!CanDisplayUnitMovement(proc, info->x_load, info->y_load))
                break;

            LoadUnitWrapper(info, proc);
        }

        info++;
        proc->unit_info = info;
    }

    ForceSyncUnitSpriteSheet();
}

void EventLoadUnitsAsParty(struct EventProc * proc)
{
    struct UnitInfo const * info = proc->unit_info;

    int id;
    struct Unit * unit;

    int blueCount = 0;

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        blueCount++;
    })

    if (blueCount > 0 && GetChapterInfo(gPlaySt.chapter)->has_prep)
        return;

    if (GetChapterInfo(gPlaySt.chapter)->has_prep)
    {
        FOR_UNITS_FACTION(FACTION_BLUE, unit,
        {
            if (unit->flags & UNIT_FLAG_DEAD)
                continue;

            unit->flags |= UNIT_FLAG_HIDDEN;
        })
    }
    else
    {
        FOR_UNITS_FACTION(FACTION_BLUE, unit,
        {
            if (unit->flags & UNIT_FLAG_DEAD)
                continue;

            unit->flags |= UNIT_FLAG_HIDDEN;
            unit->flags &= ~UNIT_FLAG_NOT_DEPLOYED;
        })
    }

    id = 0;

    while (info->pid != 0)
    {
        id = GetNextAvailableBlueUnitId(id);

        if (id == 0)
            break;

        unit = GetUnit(id);
        id++;

        FakeLoadUnit(info, unit);

        info++;
    }

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        if (!(unit->flags & UNIT_FLAG_HIDDEN))
            continue;

        unit->flags |= UNIT_FLAG_NOT_DEPLOYED;
    })

    RefreshEntityMaps();
    RefreshUnitSprites();
}

void EventMovementWait(struct EventProc * proc)
{
    if (MuExistsActive())
        return;

    MapFill(gMapOther, 0);
    proc->on_idle = NULL;
}

int EvtCmd_WaitForMovement(struct EventProc * proc)
{
    if (MuExistsActive())
        return EVENT_CMDRET_REPEAT;

    MapFill(gMapOther, 0);
    return EVENT_CMDRET_YIELD;
}

int EvtCmd_UnitCameraOn(struct EventProc * proc)
{
    proc->flags |= EVENT_FLAG_UNITCAM;
    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_UnitCameraOff(struct EventProc * proc)
{
    proc->flags &= ~EVENT_FLAG_UNITCAM;
    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_Func(struct EventProc * proc)
{
    // script[0]: address of function

    typedef void (* FuncType)(struct EventProc * proc);
    FuncType func;

    EventScr const * script = proc->script;

    func = (FuncType) proc->script[0];
    func(proc);

    if (script != proc->script)
        return EVENT_CMDRET_JUMPED;

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_FuncUntil(struct EventProc * proc)
{
    // script[0]: address of function

    i8 result;

    typedef bool (* FuncType)(struct EventProc * proc);
    FuncType func;

    EventScr const * script = proc->script;

    func = (FuncType) proc->script[0];
    result = func(proc);

    if (script != proc->script)
        return EVENT_CMDRET_JUMPED;

    if (result)
        return EVENT_CMDRET_CONTINUE;
    else
        return EVENT_CMDRET_REPEAT;
}

int EvtCmd_FuncWhile(struct EventProc * proc)
{
    // script[0]: address of function

    i8 result;

    typedef bool (* FuncType)(struct EventProc * proc);
    FuncType func;

    EventScr const * script = proc->script;

    func = (FuncType) proc->script[0];
    result = func(proc);

    if (script != proc->script)
        return EVENT_CMDRET_JUMPED;

    if (result)
        return EVENT_CMDRET_REPEAT;
    else
        return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_Stop(struct EventProc * proc)
{
    return EVENT_CMDRET_REPEAT;
}

int EvtCmd_Label(struct EventProc * proc)
{
    return EVENT_CMDRET_CONTINUE;
}

int EventGotoLabel(ProcPtr proc, int label)
{
    EventScr const * it;

    for (it = ((struct EventProc *) proc)->script_start; it[0] != EVT_CMD_END; it += gEventCmdInfoTable[it[0]].size)
    {
        if (it[0] == EVT_CMD_LABEL && it[1] == label)
        {
            ((struct EventProc *) proc)->script = it + gEventCmdInfoTable[EVT_CMD_LABEL].size;
            return EVENT_CMDRET_JUMPED;
        }
    }

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_Goto(struct EventProc * proc)
{
    // script[0]: label to go to

    return EventGotoLabel(proc, proc->script[0]);
}

int EvtCmd_GotoIfnAlive(struct EventProc * proc)
{
    // script[0]: label to go to
    // script[1]: pid of character

    u16 pid = proc->script[1];

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        if (unit->pinfo->id == pid)
            return EVENT_CMDRET_CONTINUE;
    })

    return EventGotoLabel(proc, proc->script[0]);
}

int EvtCmd_GotoIfnInTeam(struct EventProc * proc)
{
    // script[0]: label to go to
    // script[1]: pid of character

    u16 pid = proc->script[1];

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->flags & UNIT_FLAG_UNAVAILABLE)
            continue;

        if (unit->pinfo->id == pid)
            return EVENT_CMDRET_CONTINUE;
    })

    return EventGotoLabel(proc, proc->script[0]);
}

int EvtCmd_GotoIfyFunc(struct EventProc * proc)
{
    // script[0]: label to go to
    // script[1]: address of function

    typedef bool (* FuncType)(void);
    FuncType func;

    func = (FuncType) proc->script[1];

    if (func())
        return EventGotoLabel(proc, proc->script[0]);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_GotoIfnFunc(struct EventProc * proc)
{
    // script[0]: label to go to
    // script[1]: address of function

    typedef bool (* FuncType)(void);
    FuncType func;

    func = (FuncType) proc->script[1];

    if (!func())
        return EventGotoLabel(proc, proc->script[0]);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_GotoIfySkip(struct EventProc * proc)
{
    if (proc->flags & (EVENT_FLAG_SKIPPED | EVENT_FLAG_TEXTSKIPPED))
        return EventGotoLabel(proc, proc->script[0]);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_GotoIfyFlag(struct EventProc * proc)
{
    // script[0]: label to go to
    // script[1]: flag to check

    EventScr const * it = proc->script_start;

    int label = proc->script[0];

    if (!CheckFlag(proc->script[1]))
        return EVENT_CMDRET_CONTINUE;

    while (it[0] != EVT_CMD_END)
    {
        if (it[0] == EVT_CMD_LABEL && it[1] == label)
        {
            proc->script = it + gEventCmdInfoTable[EVT_CMD_LABEL].size;
            return EVENT_CMDRET_JUMPED;
        }

        it += gEventCmdInfoTable[it[0]].size;
    }

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_GotoIfnFlag(struct EventProc * proc)
{
    // script[0]: label to go to
    // script[1]: flag to check

    EventScr const * it = proc->script_start;

    int label = proc->script[0];

    if (CheckFlag(proc->script[1]))
        return EVENT_CMDRET_CONTINUE;

    while (it[0] != EVT_CMD_END)
    {
        if (it[0] == EVT_CMD_LABEL && it[1] == label)
        {
            proc->script = it + gEventCmdInfoTable[EVT_CMD_LABEL].size;
            return EVENT_CMDRET_JUMPED;
        }

        it += gEventCmdInfoTable[it[0]].size;
    }

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_GotoIfyActive(struct EventProc * proc)
{
    // script[0]: label to go to
    // script[1]: pid

    EventScr const * it = proc->script_start;

    int label = proc->script[0];

    if (gActiveUnit->pinfo->id != proc->script[1])
        return EVENT_CMDRET_CONTINUE;

    while (it[0] != EVT_CMD_END)
    {
        if (it[0] == EVT_CMD_LABEL && it[1] == label)
        {
            proc->script = it + gEventCmdInfoTable[EVT_CMD_LABEL].size;
            return EVENT_CMDRET_JUMPED;
        }

        it += gEventCmdInfoTable[it[0]].size;
    }

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_Jump(struct EventProc * proc)
{
    // script[0]: address of new script

    EventScr const * new_script = (EventScr const *) proc->script[0];

    proc->script = new_script;
    proc->script_start = new_script;

    return EVENT_CMDRET_JUMPED;
}

int EvtCmd_GiveItem(struct EventProc * proc)
{
    // script[0]: iid

    u16 iid = proc->script[0];
    return EventGiveItem(gActiveUnit, iid, proc);
}

int EvtCmd_GiveItemTo(struct EventProc * proc)
{
    // script[0]: pid
    // script[1]: iid

    u16 pid = proc->script[0];
    u16 iid = proc->script[1];

    if (pid == 0)
        pid = proc->pid_param;

    return EventGiveItem(GetUnitByPid(pid), iid, proc);
}

int EventGiveItem(struct Unit * unit, u16 iid, struct EventProc * proc)
{
    if (iid == 0)
        iid = proc->iid_param;

    StartGiveItem(unit, iid, proc);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_MapChange(struct EventProc * proc)
{
    // script[0]: map change id

    int id = proc->script[0];

    // Common with EvtCmd_MapChangePosition

    if (id == -1)
        id = proc->map_change_param;

    if (!proc->no_map)
    {
        RenderMapForFade();

        ApplyMapChange(id);
        AddMapChangeTrap(id);

        RefreshTerrainMap();
        UpdateRoofedUnits();
        RenderMap();

        StartMapFade(TRUE);
    }
    else
    {
        ApplyMapChange(id);
        AddMapChangeTrap(id);

        RefreshTerrainMap();
        UpdateRoofedUnits();
    }

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_MapChangePosition(struct EventProc * proc)
{
    // script[0]: (x) | ((y) << 8)

    u32 script = proc->script[0];

    u8 x = (script) % 0x100;
    u8 y = (script >> 8) % 0x100;

    int id = GetMapChangeIdAt(x, y);

    // Common with EvtCmd_MapChange

    if (id == -1)
        id = proc->map_change_param;

    if (!proc->no_map)
    {
        RenderMapForFade();

        ApplyMapChange(id);
        AddMapChangeTrap(id);

        RefreshTerrainMap();
        UpdateRoofedUnits();
        RenderMap();

        StartMapFade(TRUE);
    }
    else
    {
        ApplyMapChange(id);
        AddMapChangeTrap(id);

        RefreshTerrainMap();
        UpdateRoofedUnits();
    }

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_SetFaction(struct EventProc * proc)
{
    // script[0]: pid
    // script[1]: faction

    u8 pid = proc->script[0], id /* unused */;
    int faction = proc->script[1];

    FOR_UNITS_ALL(unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        id = unit->pinfo->id; // unused

        if (unit->pinfo->id == pid)
            UnitChangeFaction(unit, faction);
    })

    RefreshUnitSprites();

    return EVENT_CMDRET_YIELD;
}

void EventFlashCursorWait(struct EventProc * proc);

int EvtCmd_FlashCursorPosition(struct EventProc * proc)
{
    // script[0]: position

    struct GenericProc * gproc;
    short x, y;

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    x = EVTCMD_GET_X(proc->script[0]);
    y = EVTCMD_GET_Y(proc->script[0]);

    gproc = SpawnProc(ProcScr_FlashCursor, proc);

    gproc->timer1 = x;
    gproc->timer2 = y;

    proc->on_idle = EventFlashCursorWait;

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_FlashCursorPid(struct EventProc * proc)
{
    // script[0]: pid

    struct GenericProc * gproc;

    struct Unit * unit = GetUnitByPid(proc->script[0]);

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    gproc = SpawnProc(ProcScr_FlashCursor, proc);

    gproc->timer1 = unit->x;
    gproc->timer2 = unit->y;

    proc->on_idle = EventFlashCursorWait;

    return EVENT_CMDRET_YIELD;
}

void EventFlashCursorWait(struct EventProc * proc)
{
    if (FindProc(ProcScr_FlashCursor) != NULL)
        return;

    proc->on_idle = NULL;
}

void FlashCursor_OnInit(struct GenericProc * proc)
{
    proc->unk58 = 60;
}

void FlashCursor_OnLoop(struct GenericProc * proc)
{
    if (--proc->unk58 <= 0)
        Proc_Break(proc);

    PutMapCursor(proc->timer1 << 4, proc->timer2 << 4, MAP_CURSOR_DEFAULT);
}

int EvtCmd_PutCursor(struct EventProc * proc)
{
    // script[0]: position

    struct GenericProc * gproc;
    short x, y;

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    x = EVTCMD_GET_X(proc->script[0]);
    y = EVTCMD_GET_Y(proc->script[0]);

    gproc = SpawnProc(ProcScr_EventCursor, proc);

    gproc->timer1 = x;
    gproc->timer2 = y;

    return EVENT_CMDRET_YIELD;
}

void EventCursor_OnLoop(struct GenericProc * proc)
{
    PutMapCursor(proc->timer1 << 4, proc->timer2 << 4, MAP_CURSOR_DEFAULT);
}

int EvtCmd_ClearCursors(struct EventProc * proc)
{
    Proc_EndEach(ProcScr_EventCursor);
    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_RemovePid(struct EventProc * proc)
{
    // script[0]: pid

    struct Unit * unit = GetUnitByPid(proc->script[0]);

    ClearUnit(unit);

    RefreshEntityMaps();
    RefreshUnitSprites();

    return EVENT_CMDRET_YIELD;
}

void EventRemoveDisplayedWait(struct EventProc * proc);

int EvtCmd_RemovePidDisplayed(struct EventProc * proc)
{
    // script[0]: pid

    struct MuProc * mu;
    struct Unit * unit;

    proc->pid_param = proc->script[0];
    unit = GetUnitByPid(proc->pid_param);

    HideUnitSprite(unit);

    mu = StartMu(unit);

    SetAutoMuDefaultFacing();
    StartMuDeathFade(mu);

    proc->on_idle = EventRemoveDisplayedWait;
    proc->sleep_duration = 60;

    return EVENT_CMDRET_YIELD;
}

void EventRemoveDisplayedWait(struct EventProc * proc)
{
    // this is only called after the locking death fade proc ended
    // so we can cleanup immediately

    struct Unit * unit = GetUnitByPid(proc->pid_param);

    EndAllMus();

    ClearUnit(unit);

    RefreshEntityMaps();
    RefreshUnitSprites();

    proc->on_idle = NULL;
}

void SetUnitAi(struct Unit * unit, u8 ai_a, u8 ai_b, u8 unused)
{
    if (ai_a != 0x10)
    {
        unit->ai_a = ai_a;
        unit->ai_a_pc = 0;
    }

    if (ai_b != 0x19)
    {
        unit->ai_b = ai_b;
        unit->ai_b_pc = 0;

        if (ai_b == 0x0C)
            unit->ai_flags |= 8;
    }
}

int EvtCmd_SetAiPid(struct EventProc * proc)
{
    // script[0]: pid
    // script[1]: (ai_a) | (ai_b << 8) | (ai_c << 16)

    u8 pid = proc->script[0];

    u8 ai_a = (proc->script[1] & 0x000000FF);
    u8 ai_b = (proc->script[1] & 0x0000FF00) >> 8;
    u8 ai_c = (proc->script[1] & 0x00FF0000) >> 16;

    FOR_UNITS_ALL(unit,
    {
        if (unit->flags & (UNIT_FLAG_DEAD | UNIT_FLAG_HIDDEN))
            continue;

        if (unit->pinfo->id != pid)
            continue;

        SetUnitAi(unit, ai_a, ai_b, ai_c);
    })

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_SetAiPosition(struct EventProc * proc)
{
    // script[0]: position
    // script[1]: (ai_a) | (ai_b << 8) | (ai_c << 16)

    i8 x = EVTCMD_GET_X_RAW(proc->script[0]);
    i8 y = EVTCMD_GET_Y_RAW(proc->script[0]);

    u8 ai_a = (proc->script[1] & 0x000000FF);
    u8 ai_b = (proc->script[1] & 0x0000FF00) >> 8;
    u8 ai_c = (proc->script[1] & 0x00FF0000) >> 16;

    FOR_UNITS(0x41, 0xC0, unit,
    {
        if (unit->flags & (UNIT_FLAG_DEAD | UNIT_FLAG_HIDDEN))
            continue;

        if (unit->x != x)
            continue;

        if (unit->y != y)
            continue;

        SetUnitAi(unit, ai_a, ai_b, ai_c);
    })

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_SetFlag(struct EventProc * proc)
{
    // script[0]: flag

    SetFlag(proc->script[0]);
    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_ClearFlag(struct EventProc * proc)
{
    // script[0]: flag

    ClearFlag(proc->script[0]);
    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_PlayBgm(struct EventProc * proc)
{
    // script[0]: song id

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartBgmExt(proc->script[0], 1, NULL);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_OverrideBgm(struct EventProc * proc)
{
    // script[0]: song id

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    OverrideBgm(proc->script[0]);
    StartTemporaryLock(proc, 33);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_RestoreBgm(struct EventProc * proc)
{
    RestoreBgm();

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_FadeBgmOut(struct EventProc * proc)
{
    // script[0]: speed

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    FadeBgmOut(proc->script[0]);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_LowerBgmVolume(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartBgmVolumeChange(0x100, 0x90, 10, proc);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_RestoreBgmVolume(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        SetBgmVolume(0x100);

        return EVENT_CMDRET_CONTINUE;
    }

    StartBgmVolumeChange(0x90, 0x100, 10, proc);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_PlaySe(struct EventProc * proc)
{
    // script[0]: song id

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    PlaySe(proc->script[0]);

    return EVENT_CMDRET_CONTINUE;
}

int EventEndBattleMap(ProcPtr proc)
{
    ((struct EventProc *) proc)->flags |= EVENT_FLAG_ENDMAPMAIN;
    return 0;
}

int EvtCmd_NextChapter(struct EventProc * proc)
{
    EndAllMus();

    SetNextChapter(proc->script[0]);
    SetNextGameAction(GAME_ACTION_1);

    proc->flags |= EVENT_FLAG_ENDMAPMAIN;

    if (!(proc->flags & EVENT_FLAG_SKIPPED))
    {
        FadeBgmOut(4);
        StartSlowLockingFadeToBlack(proc);
    }
    else
    {
        FadeBgmOut(4);
    }

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_EndGame(struct EventProc * proc)
{
    SetNextGameAction(GAME_ACTION_2);
    EventEndBattleMap(proc);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_SetMap(struct EventProc * proc)
{
    // script[0]: chapter
    // script[1]: camera x
    // script[2]: camera y

    gPlaySt.chapter = proc->script[0];

    JumpToChapterDirectly();
    CleanupUnitsBeforeChapter();

    gBmSt.camera.x = GetCameraCenteredX(proc->script[1] * 16);
    gBmSt.camera.y = GetCameraCenteredY(proc->script[2] * 16);

    RefreshEntityMaps();
    RenderMap();
    RefreshUnitSprites();

    return EVENT_CMDRET_CONTINUE;
}

void EventFadeFromSkipWait(struct EventProc * proc);

int EvtCmd_NoSkip(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        proc->flags &= ~EVENT_FLAG_SKIPPED;

        ApplySystemGraphics();
        ApplyChapterMapPalettes();
        ApplyUnitSpritePalettes();

        proc->on_idle = EventFadeFromSkipWait;
    }

    proc->flags |= EVENT_FLAG_DISABLESKIP;

    return EVENT_CMDRET_YIELD;
}

void EventFadeFromSkipWait(struct EventProc * proc)
{
    proc->no_map = FALSE;
    StartFastLockingFadeFromBlack(proc);

    proc->on_idle = NULL;
}

int EvtCmd_NoSkipNoTextSkip(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        proc->flags &= ~EVENT_FLAG_SKIPPED;

        proc->no_map = FALSE;
        StartFastLockingFadeFromBlack(proc);
    }

    proc->flags |= (EVENT_FLAG_DISABLESKIP | EVENT_FLAG_DISABLETEXTSKIP);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_YesSkip(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    proc->flags &= ~(EVENT_FLAG_DISABLESKIP | EVENT_FLAG_DISABLETEXTSKIP);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_FadeToBlack(struct EventProc * proc)
{
    // script[0]: duration?

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartLockingFadeToBlack(proc->script[0], proc);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_FadeFromBlack(struct EventProc * proc)
{
    // script[0]: duration?

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartLockingFadeFromBlack(proc->script[0], proc);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_FadeToWhite(struct EventProc * proc)
{
    // script[0]: duration?

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartLockingFadeToWhite(proc->script[0], proc);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_FadeFromWhite(struct EventProc * proc)
{
    // script[0]: duration?

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartLockingFadeFromWhite(proc->script[0], proc);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_ExitMap(struct EventProc * proc)
{
    Event_SetExitMap(proc);
    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_EnterMap(struct EventProc * proc)
{
    Event_SetEnterMap(proc);
    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_GiveMoney(struct EventProc * proc)
{
    int money, given;

    given = proc->script[0];

    if (given == 0)
        given = proc->money_param;

    if (UNIT_FACTION(gActiveUnit) == FACTION_BLUE)
    {
        money = GetGold();
        money += given;
        SetGold(money);
    }

    StartPopup_080120D0(given, proc);

    return EVENT_CMDRET_YIELD;
}

void EventScriptedBattleWait(struct EventProc * proc);

int EvtCmd_FightScript(struct EventProc * proc)
{
    // script[0]: instigator pid
    // script[1]: target pid
    // script[2]: battle script address
    // script[3]: is ballista bool?

    struct Unit * unit_a;
    struct Unit * unit_b;

    struct BattleHit const * battlescr;

    int isBallista;

    proc->cmd_short = GetGameLock();
    proc->on_idle = EventScriptedBattleWait;

    unit_a = GetUnitByPid(proc->script[0]);
    unit_b = GetUnitByPid(proc->script[1]);

    battlescr = (struct BattleHit const *) proc->script[2];
    isBallista = proc->script[3];

    UnitBeginAction(unit_a);

    HideUnitSprite(gActiveUnit);

    StartMu(gActiveUnit);
    SetAutoMuDefaultFacing();

    if (GetItemKind(unit_a->items[0]) == ITEM_KIND_STAFF)
    {
        BattleInitItemEffect(unit_a, 0);
        BattleInitItemEffectTarget(unit_b);
    }
    else if (!isBallista)
    {
        BattleGenerateReal(unit_a, unit_b);
    }
    else
    {
        BattleGenerateBallistaReal(unit_a, unit_b);
    }

    gBattleUnitA.exp_gain = 0;
    gBattleUnitB.exp_gain = 0;

    ClearBattleHits();

    while (TRUE)
    {
        *gBattleHitIt = *battlescr;

        if (battlescr->info & BATTLE_HIT_INFO_END)
            break;

        BattleHitAdvance();
        battlescr++;
    }

    BattleHitTerminate();
    BeginBattleAnimations();

    Proc_Mark(proc, PROC_MARK_EVENT_ANIM);

    gAiDecision.x_move = unit_a->x;
    gAiDecision.y_move = unit_a->y;

    return EVENT_CMDRET_YIELD;
}

void EventScriptedBattleWaitB(struct EventProc * proc);

void EventScriptedBattleWait(struct EventProc * proc)
{
    if (proc->cmd_short == GetGameLock())
        proc->on_idle = EventScriptedBattleWaitB;
}

void EventScriptedBattleWaitB(struct EventProc * proc)
{
    proc->on_idle = NULL;

    Proc_Mark(proc, PROC_MARK_6);
    AiEndMuAndRefreshUnits();
}

int EvtCmd_DisableAutoClear(struct EventProc * proc)
{
    proc->flags |= EVENT_FLAG_NOAUTOCLEAR;
    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_FuncOnSkip(struct EventProc * proc)
{
    // script[0]: function address

    proc->on_skip = (void(*)(void)) proc->script[0];
    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_SetWeather(struct EventProc * proc)
{
    // script[0]: weather id

    struct GenericProc * gproc;

    gproc = SpawnProcLocking(ProcScr_WeatherChangeFade, proc);
    gproc->timer1 = proc->script[0];

    return EVENT_CMDRET_YIELD;
}

void DoChangeWeather(struct GenericProc * proc)
{
    SetWeather(proc->timer1);
}

int EvtCmd_WmStart(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartWorldMap();

    SetFaceConfig(gWmEventFaceConfig);
    proc->background = 0;

    StartWmSprite();

    StartWmZoomIntro(proc);
    PlayWmIntroBGM();

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_WmEnd(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_YIELD;

    StartSlowLockingFadeToBlack(proc);
    proc->no_map = TRUE;

    return EVENT_CMDRET_YIELD;
}

void EventWmZoomWait(struct EventProc * proc);

int EvtCmd_WmZoomTo(struct EventProc * proc)
{
    // script[0]: coords relative to center of screen

    int x = DISPLAY_WIDTH/2 + EVTCMD_GET_X(proc->script[0]);
    int y = DISPLAY_HEIGHT/2 + EVTCMD_GET_Y(proc->script[0]);

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartWmZoomTo(x, y, proc);
    func_fe6_0809347C(x, y);

    proc->on_idle = EventWmZoomWait;

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_WmZoomBack(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartWmZoomBack(proc);
    ResetWmSpriteState();

    proc->on_idle = EventWmZoomWait;

    return EVENT_CMDRET_YIELD;
}

void EventWmZoomWait(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        EndWmZoom();
        proc->on_idle = NULL;

        return;
    }

    if (WmZoomExists())
        return;

    proc->on_idle = NULL;
}

int EvtCmd_WmPutFace(struct EventProc * proc)
{
    // script[0]: face slot
    // script[1]: position
    // script[2]: fid

    struct WmEventFaceProc * faceproc;

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    faceproc = SpawnProc(ProcScr_WmEventShowFace, proc);

    faceproc->face_slot = proc->script[0];

    faceproc->x = EVTCMD_GET_X(proc->script[1]);
    faceproc->y = EVTCMD_GET_Y(proc->script[1]);

    faceproc->fid = proc->script[2];
    faceproc->disp = FACE_DISP_HLAYER(1) | FACE_DISP_KIND(FACE_64x72);

    return EVENT_CMDRET_CONTINUE;
}

void WmPutFace_OnInit(struct WmEventFaceProc * proc)
{
    int disp;
    struct FaceProc * face;

    if (proc->x > DISPLAY_WIDTH/2)
        proc->x_offset_start = -0x20;
    else
        proc->x_offset_start = +0x20;

    face = StartFace(proc->face_slot, proc->fid, proc->x + proc->x_offset_start, proc->y, proc->disp);

    proc->blend_value = 0;

    disp = GetFaceDisp(face);
    SetFaceDisp(face, disp | FACE_DISP_BLEND);

    SetBlendConfig(0, proc->blend_value, 0x10 - proc->blend_value, 0);

    SetBlendTargetA(0, 0, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 0, 0); SetBlendBackdropB(1);
}

void WmPutFace_OnLoop(struct WmEventFaceProc * proc)
{
    int x_offset = Interpolate(INTERPOLATE_RSQUARE, proc->x_offset_start, 0, proc->blend_value++, 0x10);
    gFaces[proc->face_slot]->x_disp = proc->x + x_offset;

    SetBlendConfig(0, proc->blend_value, 0x10 - proc->blend_value, 0);

    if (proc->blend_value >= 0x10)
    {
        int disp = GetFaceDisp(gFaces[proc->face_slot]);
        disp &= ~FACE_DISP_BLEND;
        SetFaceDisp(gFaces[proc->face_slot], disp);

        Proc_Break(proc);
    }
}

int EvtCmd_WmRemoveFace(struct EventProc * proc)
{
    // script[0]: face slot

    int face_slot;
    struct WmEventFaceProc * faceproc;

    face_slot = proc->script[0];

    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        EndFaceById(face_slot);
        return EVENT_CMDRET_CONTINUE;
    }

    if (gFaces[face_slot] == NULL)
        return EVENT_CMDRET_YIELD;

    faceproc = SpawnProc(ProcScr_WmEventHideFace, proc);
    faceproc->face_slot = face_slot;

    return EVENT_CMDRET_CONTINUE;
}

void WmRemoveFace_OnInit(struct WmEventFaceProc * proc)
{
    int disp;
    struct FaceProc * face;

    face = gFaces[proc->face_slot];

    proc->x = face->x_disp;

    if (proc->x > DISPLAY_WIDTH/2)
        proc->x_offset_start = +0x10;
    else
        proc->x_offset_start = -0x10;

    proc->blend_value = 0;

    disp = GetFaceDisp(face);
    SetFaceDisp(face, disp | FACE_DISP_BLEND);

    SetBlendConfig(0, 0x10 - proc->blend_value, proc->blend_value, 0);

    SetBlendTargetA(0, 0, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 0, 0); SetBlendBackdropB(1);
}

void WmRemoveFace_OnLoop(struct WmEventFaceProc * proc)
{
    int x_offset = Interpolate(INTERPOLATE_SQUARE, 0, proc->x_offset_start, proc->blend_value++, 0x10);
    gFaces[proc->face_slot]->x_disp = proc->x + x_offset;

    SetBlendConfig(0, 0x10 - proc->blend_value, proc->blend_value, 0);

    if (proc->blend_value >= 0x10)
        Proc_Break(proc);
}

void WmRemoveFace_OnEnd(struct WmEventFaceProc * proc)
{
    EndFaceById(proc->face_slot);
}

int EvtCmd_WmMoveFace(struct EventProc * proc)
{
    // script[0]: face slot
    // script[1]: target coords (note: y unused)

    struct WmEventFaceProc * faceproc;

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    faceproc = SpawnProc(ProcScr_WmEventMoveFace, proc);

    faceproc->face_slot = proc->script[0];
    faceproc->x = EVTCMD_GET_X(proc->script[1]);
    faceproc->y = EVTCMD_GET_Y(proc->script[1]);

    return EVENT_CMDRET_CONTINUE;
}

void WmMoveFace_OnInit(struct WmEventFaceProc * proc)
{
    proc->x_offset_start = 0;
    proc->blend_value = proc->x - gFaces[proc->face_slot]->x_disp;
    proc->x = gFaces[proc->face_slot]->x_disp;
}

void WmMoveFace_OnLoop(struct WmEventFaceProc * proc)
{
    int x_offset = Interpolate(INTERPOLATE_RSQUARE, 0, proc->blend_value, proc->x_offset_start++, 0x20);
    gFaces[proc->face_slot]->x_disp = proc->x + x_offset;

    if (proc->x_offset_start >= 0x20)
        Proc_Break(proc);
}

int EvtCmd_WmNop54(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_WmNop55(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_WmTalk(struct EventProc * proc)
{
    // script[0]: msgid

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    InitSpriteTalk(OBCHR_WM_TEXT + 0x21, 2, OBPAL_WM_TEXT);
    StartTalkMsg(1, 1 + proc->cmd_short, proc->script[0]);

    SetTalkPrintDelay(4);
    SetTalkFlag(TALK_FLAG_SPRITE);
    SetTalkFlag(TALK_FLAG_NOSKIP);
    SetTalkFlag(TALK_FLAG_7);

    if (proc->flags & EVENT_FLAG_DISABLETEXTSKIP)
        SetTalkFlag(TALK_FLAG_NOSKIP);

    proc->on_idle = EventTalkWait;

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_WmTalkBoxBottom(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    SetupWmTalkBoxGfx();

    proc->cmd_short = 14;

    InitSpriteTalk(OBCHR_WM_TEXT + 0x21, 2, OBPAL_WM_TEXT);
    StartPutTalkSpriteText(0, proc->cmd_short*8, OBCHR_WM_TEXT, OBPAL_WM_TEXTBOX, proc);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_WmTalkBoxTop(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    SetupWmTalkBoxGfx();

    proc->cmd_short = 0;

    InitSpriteTalk(OBCHR_WM_TEXT + 0x21, 2, OBPAL_WM_TEXT);
    StartPutTalkSpriteText(0, proc->cmd_short*8, OBCHR_WM_TEXT, OBPAL_WM_TEXTBOX, proc);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_WmTalkBoxRemove(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    EndPutTalkSpriteText();

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_WmArrow(struct EventProc * proc)
{
    int id = EVTCMD_GET_X(proc->script[0]);
    int color = EVTCMD_GET_Y(proc->script[0]);

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    DisplayWmArrow(id, color);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_WmPutHighlight(struct EventProc * proc)
{
    int id = EVTCMD_GET_X(proc->script[0]);
    int var_08 = EVTCMD_GET_Y(proc->script[0]);

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartWmHighlight(var_08, id);

    return EVENT_CMDRET_CONTINUE;
}

void EventWmRemoveHighlightWait(struct EventProc * proc);

int EvtCmd_WmRemoveHighlight(struct EventProc * proc)
{
    int id = proc->script[0];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    WmHighlightFadeOut(id);
    proc->cmd_byte = id;

    proc->on_idle = EventWmRemoveHighlightWait;

    return EVENT_CMDRET_YIELD;
}

void EventWmRemoveHighlightWait(struct EventProc * proc)
{
    if (WmHighlightExists(proc->cmd_byte))
        return;

    proc->on_idle = NULL;
}

void EventWmRemoveHighlightsWait(struct EventProc * proc);

int EvtCmd_WmRemoveBothHighlights(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    WmHighlightFadeOut(0);
    WmHighlightFadeOut(1);

    proc->on_idle = EventWmRemoveHighlightsWait;

    return EVENT_CMDRET_YIELD;
}

void EventWmRemoveHighlightsWait(struct EventProc * proc)
{
    if (WmHighlightAllSideExists())
        return;

    proc->on_idle = NULL;
}

int EvtCmd_StartWmDot(struct EventProc * proc)
{
    int id = proc->script[0];

    int x = EVTCMD_GET_X(proc->script[1]);
    int y = EVTCMD_GET_Y(proc->script[1]);

    int palid = proc->script[2];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartWmDot(x, y, palid, id);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_WmRemoveDot(struct EventProc * proc)
{
    int id = proc->script[0];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    EndWMDot(id);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_WmPutFlag(struct EventProc * proc)
{
    int id = proc->script[0];

    int x = EVTCMD_GET_X(proc->script[1]);
    int y = EVTCMD_GET_Y(proc->script[1]);

    int palid = proc->script[2];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartWmFlag(x, y, palid, id);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_WmRemoveFlag(struct EventProc * proc)
{
    int id = proc->script[0];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    EndWmFlag(id);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_WmPutMapText(struct EventProc * proc)
{
    int id = proc->script[0];

    int x_a = EVTCMD_GET_X(proc->script[1]);
    int y_a = EVTCMD_GET_Y(proc->script[1]);

    int unk = proc->script[2];

    int x_b = EVTCMD_GET_X(proc->script[3]);
    int y_b = EVTCMD_GET_Y(proc->script[3]);

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartWmMapText(x_a, y_a, unk, x_b, y_b, id);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_WmRemoveMapText(struct EventProc * proc)
{
    int id = proc->script[0];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    EndWmMapText(id);

    return EVENT_CMDRET_CONTINUE;
}

int EvtCmd_End(struct EventProc * proc)
{
    Proc_Break(proc);

    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        if (FindProc(ProcScr_Face) != NULL)
            ClearTalk();

        return EVENT_CMDRET_YIELD;
    }

    if (!(proc->flags & EVENT_FLAG_NOAUTOCLEAR))
        EventClearTalkDisplayed(proc);

    return EVENT_CMDRET_YIELD;
}

int EvtCmd_Kill(struct EventProc * proc)
{
    return EvtCmd_End(proc);
}

void EventClearTalkDisplayed(struct EventProc * proc)
{
    if (proc->no_map)
    {
        ClearTalk();
        return;
    }

    if (FindProc(ProcScr_Face) != NULL)
    {
        ClearTalkBubble();
        Proc_ForEach(ProcScr_Face, (ProcFunc) StartFaceFadeOut);

        proc->sleep_duration = 8;
        StartTemporaryLock(proc, 8);
    }
}

void ClearTalk(void)
{
    ClearTalkBubble();
    Proc_EndEach(ProcScr_Face);

    InitFaces();
}

void func_fe6_08011F4C(void)
{
    StartTalkEvent(MSG_281);
}

void func_fe6_08011F64(void)
{
}

bool IsEventRunning(void)
{
    return FindMarkedProc(PROC_MARK_6) != NULL ? TRUE : FALSE;
}

bool IsEventProcRunning(void)
{
    return FindActiveProc(ProcScr_Event) != NULL ? TRUE : FALSE;
}

void KillTalkAndEvent(void)
{
    Proc_EndEachMarked(PROC_MARK_6);
    Proc_EndEachMarked(PROC_MARK_EVENT_ANIM);
    Proc_EndEachMarked(PROC_MARK_5);

    EndAllMus();
}

void SetFightEventFaceConfig(void)
{
    SetFaceConfig(gFightEventFaceConfig);
}

ProcPtr StartTalkEvent(int msgid)
{
    struct EventProc * proc = StartEvent(EventScr_AutoTalk);
    proc->msg_param = msgid;

    return proc;
}

ProcPtr StartTalkSupportEvent(int msgid)
{
    struct EventProc * proc = StartEvent(EventScr_085C46DC);
    proc->msg_param = msgid;

    return proc;
}

void StartWeaponBrokePopup(u16 item, ProcPtr parent)
{
    SetPopupItem(item);
    StartPopup(Popup_085C46FC, 0x60, UI_WINDOW_REGULAR, parent);
}

void StartPopup_08012070(u16 item, ProcPtr parent)
{
    SetPopupItem(item);
    StartPopup(Popup_085C473C, 0x60, UI_WINDOW_REGULAR, parent);
}

void StartWeaponLevelGainedPopup(u16 item, ProcPtr parent)
{
    SetPopupItem(item);
    StartPopup(Popup_085C477C, 0x60, UI_WINDOW_REGULAR, parent);
}

void StartPopup_080120D0(int amount, ProcPtr parent)
{
    SetPopupNumber(amount);

    if (UNIT_FACTION(gActiveUnit) == FACTION_BLUE)
        StartPopup(Popup_085C47A4, 0x60, UI_WINDOW_REGULAR, parent);
    else
        StartPopup(Popup_085C47DC, 0x60, UI_WINDOW_REGULAR, parent);
}

void StartPopup_08012120(u16 item, ProcPtr parent)
{
    SetPopupItem(item);

    if (UNIT_FACTION(gActiveUnit) == FACTION_BLUE)
        StartPopup(Popup_085C4814, 0x60, UI_WINDOW_REGULAR, parent);
    else
        StartPopup(Popup_085C4854, 0x60, UI_WINDOW_REGULAR, parent);
}

void StartStoleItemPopup(u16 item, ProcPtr parent)
{
    SetPopupItem(item);

    if (UNIT_FACTION(gActiveUnit) == FACTION_BLUE)
        StartPopup(Popup_PlayerStoleItem, 0x60, UI_WINDOW_REGULAR, parent);
    else
        StartPopup(Popup_AiStoleItem, 0x60, UI_WINDOW_REGULAR, parent);
}

void StartSupportLevelGaindPopup(ProcPtr parent)
{
    StartPopup(Popup_085C4914, 0x60, UI_WINDOW_REGULAR, parent);
}

void StartGiveItem(struct Unit * unit, u16 iid, ProcPtr parent)
{
    struct GenericProc * proc;

    u32 intParent = (u32) parent;

    if (intParent < 8)
        proc = SpawnProc(ProcScr_GiveItem, parent);
    else
        proc = SpawnProcLocking(ProcScr_GiveItem, parent);

    proc->unk58 = iid;
    proc->ptr = unit;
}

void GiveItem_DoPopup(struct GenericProc * proc)
{
    StartPopup_08012120(proc->unk58, proc);
}

void GiveItem_DoGiveItem(struct GenericProc * proc)
{
    HandleGiveUnitItem(proc->ptr, CreateItem(proc->unk58), proc);
}

void StartGiveItemEvent(u16 iid)
{
    struct EventProc * proc = StartEvent(EventScr_Item);
    proc->iid_param = iid;
}

void StartGiveItemToEvent(u16 pid, u16 iid)
{
    struct EventProc * proc = StartEvent(EventScr_ItemTo);
    proc->pid_param = pid;
    proc->iid_param = iid;
}

void StartGiveMoneyEvent(int amount)
{
    struct EventProc * proc = StartEvent(EventScr_Money);
    proc->money_param = amount;
}

void StartMapChangeEvent(u8 id)
{
    struct EventProc * proc = StartEvent(EventScr_MapChange);
    proc->map_change_param = id;
}

void StartChestItemEvent(u16 iid, u8 id)
{
    struct EventProc * proc = StartEvent(EventScr_ItemChest);
    proc->iid_param = iid;
    proc->map_change_param = id;
}

void StartChestMoneyEvent(int amount, u8 id)
{
    struct EventProc * proc = StartEvent(EventScr_MoneyChest);
    proc->money_param = amount;
    proc->map_change_param = id;
}

void SetEventTalkSkipped(void)
{
    struct EventProc * proc = FindProc(ProcScr_Event);

    if (proc == NULL)
        return;

    proc->flags |= EVENT_FLAG_TEXTSKIPPED;
}

int GetPlayerMaxDeployCount(void)
{
    struct UnitInfo const * info = GetDeployUnitInfoList();

    int count = 0;

    while (info->pid != 0)
    {
        count++;
        info++;
    }

    return count;
}

void InitPlayerDeployUnits(void)
{
    struct UnitInfo const * info = GetDeployUnitInfoList();

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        if (info->pid == 0)
        {
            unit->x = -1; // hide unit offmap
            continue;
        }

        if (unit->flags & UNIT_FLAG_NOT_DEPLOYED)
            continue;

        unit->x = info->x_move;
        unit->y = info->y_move;

        info++;
    })
}

void MoveUnitToFirstAvailableDeployPosition(struct Unit * unit);

void InitPlayerDeployUnitPositions(void)
{
    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        if (unit->flags & UNIT_FLAG_NOT_DEPLOYED)
        {
            unit->x = -1;
            unit->flags |= UNIT_FLAG_HIDDEN;

            continue;
        }

        unit->flags &= ~UNIT_FLAG_HIDDEN;

        if (unit->x == -1)
            MoveUnitToFirstAvailableDeployPosition(unit);
    })
}

void MoveUnitToFirstAvailableDeployPosition(struct Unit * unit)
{
    bool spotOccupied;

    struct UnitInfo const * info = GetDeployUnitInfoList();

    while (info->pid != 0)
    {
        spotOccupied = FALSE;

        FOR_UNITS_FACTION(FACTION_BLUE, unit,
        {
            if (unit->flags & UNIT_FLAG_UNAVAILABLE)
                continue;

            if (unit->x == info->x_move && unit->y == info->y_move)
            {
                spotOccupied = TRUE;
                break;
            }
        })

        if (!spotOccupied)
        {
            unit->x = info->x_move;
            unit->y = info->y_move;

            break;
        }

        info++;
    }
}

void func_fe6_080126FC(int a, int b)
{
}

void Event_SetExitMap(struct EventProc * proc)
{
    proc->no_map = TRUE;
}

void Event_SetEnterMap(struct EventProc * proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return;

    proc->no_map = FALSE;
}

void ResetWeather(void)
{
    SetWeather(WEATHER_NONE);
}

void func_fe6_08012780(void)
{
    m4aMPlayFadeOut(&gMusicPlayer_MainBgm, 3);
}

void func_fe6_08012798(void)
{
    m4aMPlayFadeOutTemporarily(&gMusicPlayer_FightBgm, 3);
}

void func_fe6_080127B0(void)
{
    m4aMPlayFadeIn(&gMusicPlayer_FightBgm, 2);
}

struct ProcScr CONST_DATA ProcScr_Popup[] =
{
    PROC_ONEND(Popup_Clear),

    PROC_CALL(Popup_OnInit),
    PROC_SLEEP(10),

    PROC_CALL(Popup_Prepare),
    PROC_CALL(Popup_FadeBgmOut),
    PROC_YIELD,

    PROC_CALL(Popup_PlaySe),
    PROC_CALL(Popup_Display),
    PROC_REPEAT(Popup_WaitForEnd),

    PROC_CALL(Popup_FadeBgmIn),
    PROC_YIELD,

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_PopupIconSprite[] =
{
    PROC_REPEAT(PopupIconSprite_OnIdle),
};

struct ProcScr CONST_DATA ProcScr_SceneReturnFromBackgroundTalk[] =
{
    PROC_CALL(FadeFromBg_FadeToBlack),
    PROC_YIELD,

    PROC_CALL(FadeFromBg_ClearScreen),
    PROC_SLEEP(1),

    PROC_CALL(FadeFromBg_FadeFromBlack),
    PROC_YIELD,

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_SceneEndFade[] =
{
    PROC_YIELD,

    PROC_CALL(FadeFromSkip_Start),
    PROC_YIELD,

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Event[] =
{
    PROC_MARK(PROC_MARK_6),
    PROC_ONEND(Event_OnEnd),

    PROC_CALL(Event_OnInit),

PROC_LABEL(0),
    PROC_REPEAT(Event_MainLoop),
    PROC_REPEAT(Event_WaitForFaceEnd),
    PROC_YIELD,

    PROC_CALL(Event_ResetText),
    PROC_YIELD,

    PROC_CALL(Event_RestartFromQueued),

    PROC_CALL(Event_MaybeEndMapMain),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Event_Unused_085C4104[] =
{
    PROC_MARK(PROC_MARK_6),

PROC_LABEL(0),
    PROC_REPEAT(Event_MainLoop),
    PROC_REPEAT(Event_WaitForFaceEnd),
    PROC_SLEEP(1),

    PROC_SLEEP(1),

    PROC_CALL(Event_RestartFromQueued),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_DarkenThenFunc[] =
{
    PROC_CALL(DarkenThenFunc_OnInit),
    PROC_YIELD,

    PROC_REPEAT(DarkenThenFunc_OnLoop),

    PROC_END,
};

struct EventCmdInfo CONST_DATA gEventCmdInfoTable[] =
{
    _EventCmds
};

struct BackgroundEnt CONST_DATA gBackgroundTable[] =
{
    [BACKGROUND_0] = { Img_Background_082E4650, Tsa_Background_082E6EB4, Pal_Background_082E7368 },
    [BACKGROUND_1] = { Img_Background_082E73E8, Tsa_Background_082EADF0, Pal_Background_082EB2A4 },
    [BACKGROUND_2] = { Img_Background_082EB324, Tsa_Background_082EDB7C, Pal_Background_082EE030 },
    [BACKGROUND_3] = { Img_Background_082EE0B0, Tsa_Background_082EF97C, Pal_Background_082EFE30 },
    [BACKGROUND_4] = { Img_Background_082EE0B0, Tsa_Background_082EF97C, Pal_Background_082EFEB0 },
    [BACKGROUND_5] = { Img_Background_082EFF30, Tsa_Background_082F1490, Pal_Background_082F1944 },
    [BACKGROUND_6] = { Img_Background_082F19C4, Tsa_Background_082F3494, Pal_Background_082F3948 },
    [BACKGROUND_7] = { Img_Background_082F39C8, Tsa_Background_082F62E0, Pal_Background_082F6794 },
    [BACKGROUND_8] = { Img_Background_082F6894, Tsa_Background_082F85E8, Pal_Background_082F8A9C },
    [BACKGROUND_9] = { Img_Background_082E4650, Tsa_Background_082E6EB4, Pal_Background_082E7368 },
    [BACKGROUND_10] = { Img_Background_082F8B1C, Tsa_Background_082FBE6C, Pal_Background_082FC320 },
    [BACKGROUND_11] = { Img_Background_082FC3A0, Tsa_Background_082FECE0, Pal_Background_082FF194 },
    [BACKGROUND_12] = { Img_Background_082F39C8, Tsa_Background_082F62E0, Pal_Background_082F6814 },
    [BACKGROUND_13] = { Img_Background_082FF214, Tsa_Background_08301244, Pal_Background_083016F8 },
    [BACKGROUND_14] = { Img_Background_082FF214, Tsa_Background_08301244, Pal_Background_08301778 },
    [BACKGROUND_15] = { Img_Background_082FF214, Tsa_Background_08301244, Pal_Background_083017F8 },
    [BACKGROUND_16] = { Img_Background_082D80B0, Tsa_Background_082DAC8C, Pal_Background_082DB140 },
    [BACKGROUND_17] = { Img_Background_08301878, Tsa_Background_0830491C, Pal_Background_08304DD0 },
    [BACKGROUND_18] = { Img_Background_08304E50, Tsa_Background_08306F24, Pal_Background_083073D8 },
    [BACKGROUND_19] = { Img_Background_082E28F8, Tsa_Background_082E35DC, Pal_Background_082E3A90 },
    [BACKGROUND_20] = { Img_Background_082E3B10, Tsa_Background_082E3EC0, Pal_Background_082E4374 },
};

struct ProcScr CONST_DATA ProcScr_EventWaitForMu[] =
{
    PROC_REPEAT(WaitForMu_OnLoop),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_FlashCursor[] =
{
    PROC_CALL(FlashCursor_OnInit),
    PROC_REPEAT(FlashCursor_OnLoop),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_EventCursor[] =
{
    PROC_REPEAT(EventCursor_OnLoop),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unused_085C45B8[] =
{
    PROC_CALL(FadeFromBg_FadeToBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_WeatherChangeFade[] =
{
    PROC_YIELD,

    PROC_CALL(StartSlowLockingFadeToWhite),
    PROC_YIELD,

    PROC_CALL(DoChangeWeather),
    PROC_SLEEP(30),

    PROC_CALL(StartSlowLockingFadeFromWhite),
    PROC_YIELD,

    PROC_END,
};

struct FaceVramEnt CONST_DATA gWmEventFaceConfig[] =
{
    { CHR_SIZE * OBCHR_WM_FACE_A, OBPAL_WM_FACE_A },
    { CHR_SIZE * OBCHR_WM_FACE_B, OBPAL_WM_FACE_B },
    { CHR_SIZE * OBCHR_WM_FACE_A, OBPAL_WM_FACE_A },
    { CHR_SIZE * OBCHR_WM_FACE_B, OBPAL_WM_FACE_B },
};

struct ProcScr CONST_DATA ProcScr_WmEventShowFace[] =
{
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_YIELD,

    PROC_CALL(WmPutFace_OnInit),
    PROC_REPEAT(WmPutFace_OnLoop),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_WmEventHideFace[] =
{
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_ONEND(WmRemoveFace_OnEnd),
    PROC_YIELD,

    PROC_CALL(WmRemoveFace_OnInit),
    PROC_REPEAT(WmRemoveFace_OnLoop),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_WmEventMoveFace[] =
{
    PROC_MARK(PROC_MARK_WMSTUFF),
    PROC_YIELD,

    PROC_CALL(WmMoveFace_OnInit),
    PROC_REPEAT(WmMoveFace_OnLoop),

    PROC_END,
};

struct FaceVramEnt CONST_DATA gFightEventFaceConfig[] =
{
    { CHR_SIZE * OBCHR_BANIM_FACE, OBPAL_BANIM_FACE },
    { CHR_SIZE * OBCHR_BANIM_FACE, OBPAL_BANIM_FACE },
    { CHR_SIZE * OBCHR_BANIM_FACE, OBPAL_BANIM_FACE },
    { CHR_SIZE * OBCHR_BANIM_FACE, OBPAL_BANIM_FACE },
};

EventScr CONST_DATA EventScr_AutoTalk[] =
{
    EvtTalkAuto

    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_085C46DC[] =
{
    EvtTalkAuto

    EvtClearTalk

    EvtFunc(StartSupportLevelGaindPopup)
    EvtSleep(1)

    EvtClearSkip
    EvtEnd
};

struct PopupInfo CONST_DATA Popup_085C46FC[] =
{
    POPUP_SONG(SONG_5C),

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_ICON_ITEM,
    POPUP_ITEM_NAME,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(MSG_POPUP_WeaponBroken),

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C473C[] =
{
    POPUP_SONG(SONG_5C),

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_ICON_ITEM,
    POPUP_ITEM_NAME,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(MSG_POPUP_ItemVanilshed),

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C477C[] =
{
    POPUP_SONG(SONG_5A),

    POPUP_MSG(MSG_POPUP_WexpLvup1),
    POPUP_ICON_IKIND,
    POPUP_MSG(MSG_POPUP_WexpLvup2),

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C47A4[] =
{
    POPUP_SONG(SONG_5A),

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_NUMBER,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(MSG_POPUP_GetGold),

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C47DC[] =
{
    POPUP_SONG(SONG_5C),

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_NUMBER,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(MSG_POPUP_GoldStolen),

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C4814[] =
{
    POPUP_SONG(SONG_5A),

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_ICON_ITEM,
    POPUP_ITEM_NAME,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(MSG_POPUP_GetItem),

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C4854[] =
{
    POPUP_SONG(SONG_5C),

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_ICON_ITEM,
    POPUP_ITEM_NAME,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(MSG_POPUP_ItemStolen1),

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_PlayerStoleItem[] =
{
    POPUP_SONG(SONG_5A),

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_ICON_ITEM,
    POPUP_ITEM_NAME,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(MSG_POPUP_StoleItem),

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_AiStoleItem[] =
{
    POPUP_SONG(SONG_5C),

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_ICON_ITEM,
    POPUP_ITEM_NAME,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(MSG_POPUP_ItemStolen2),

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C4914[] =
{
    POPUP_SONG(SONG_5A),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(MSG_POPUP_Support),

    POPUP_END,
};

struct ProcScr CONST_DATA ProcScr_GiveItem[] =
{
    PROC_YIELD,

    PROC_CALL(GiveItem_DoPopup),
    PROC_YIELD,

    PROC_CALL(GiveItem_DoGiveItem),
    PROC_YIELD,

    PROC_END,
};

EventScr CONST_DATA EventScr_Item[] =
{
    EvtNoSkip
    EvtGiveItem(0)

    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_ItemTo[] =
{
    EvtNoSkip
    EvtGiveItemTo(0, 0)

    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Money[] =
{
    EvtNoSkip
    EvtGiveMoney(0)

    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_MapChange[] =
{
    EvtMapChange(-1)

    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_ItemChest[] =
{
    EvtMapChange(-1)

    EvtNoSkip
    EvtGiveItem(0)

    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_MoneyChest[] =
{
    EvtMapChange(-1)

    EvtNoSkip
    EvtGiveMoney(0)

    EvtClearSkip
    EvtEnd
};
