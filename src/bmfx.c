// TODO: better name for this file
// (I am considering replacing "bm" by "field")

#include "bmfx.h"

#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "icon.h"
#include "sound.h"
#include "sprite.h"
#include "face.h"
#include "spriteanim.h"
#include "util.h"
#include "msg.h"
#include "bm.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "mapmenu.h"
#include "faction.h"
#include "unitsprite.h"
#include "battle.h"
#include "trap.h"
#include "bmio.h"
#include "supply.h"
#include "chapterinfo.h"
#include "subtitlehelp.h"
#include "menuinfo.h"
#include "ui.h"
#include "menu.h"
#include "mu.h"
#include "manim.h"
#include "statscreen.h"
#include "helpbox.h"
#include "prepscreen.h"

#include "constants/videoalloc_global.h"
#include "constants/pids.h"
#include "constants/jids.h"
#include "constants/icons.h"
#include "constants/songs.h"
#include "constants/msg.h"

extern u16 gChapterIntroMotifTmBuf[];

struct RescueTransferAnimProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ int facing;
    /* 30 */ struct Unit * unit;
    /* 34 */ struct MuProc * mu;
    /* 38 */ u8 movescr[4];
    /* 3C */ bool8 unk_3C;
};

struct EquipInfoWindowProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Unit * unit;
    /* 30 */ u8 x;
    /* 31 */ u8 y;
    /* 32 */ u8 iconPalid;
    /* 33 */ i8 compareWeaponSlot;
    /* 34 */ struct Text text[3];
};

struct UnitPrepSwapAnimProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Unit * unit;
    /* 30 */ i16 x_from;
    /* 32 */ i16 y_from;
    /* 34 */ i16 x_target;
    /* 36 */ i16 y_target;
    /* 38 */ STRUCT_PAD(0x38, 0x3C);
    /* 3C */ i16 unk_3C;
    /* 3E */ i16 unk_3E;
    /* 40 */ STRUCT_PAD(0x40, 0x44);
    /* 44 */ i32 unk_44;
};

struct ShowMapChangeProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ int map_change_id;
    /* 30 */ int alt_song;
    /* 34 */ int sndx;
};

static void RescueTransferSpriteAnim_Loop(struct RescueTransferAnimProc * proc);

struct ProcScr CONST_DATA ProcScr_RescueTransferAnim[] =
{
    PROC_19,

    PROC_REPEAT(RescueTransferSpriteAnim_Loop),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_RescueTransferAnimParentless[] =
{
    PROC_19,

    PROC_CALL(LockGame),
    PROC_REPEAT(RescueTransferSpriteAnim_Loop),
    PROC_CALL(UnlockGame),

    PROC_END,
};

static void MapFade_Init(struct Proc * proc);
static void MapFade_Loop(struct Proc * proc);
static void MapFade_End(struct Proc * proc);

struct ProcScr CONST_DATA ProcScr_MapFade[] =
{
    PROC_19,
    PROC_END_IF_DUP,

    PROC_ONEND(MapFade_End),

    PROC_CALL(MapFade_Init),

    PROC_CALL(MapFade_Loop),
    PROC_REPEAT(MapFade_Loop),

    PROC_END,
};

static void InitPhaseCursor_Init(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_InitPhaseCursor[] =
{
    PROC_CALL(InitPhaseCursor_Init),
    PROC_YIELD,

    PROC_END,
};

static void ReturnFromStatScreen_Init(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_ReturnFromStatScreen[] =
{
    PROC_19,

    PROC_CALL(ReturnFromStatScreen_Init),
    PROC_SLEEP(1),

    PROC_END,
};

static int DiscardItem_StartItemSelect(ProcPtr proc);
static int DiscardItem_PostItemSelect(ProcPtr proc);
static int DiscardItem_0801C58C(ProcPtr proc);
static int DiscardItem_0801C59C(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_DiscardItem[] =
{
    PROC_CALL_2(DiscardItem_StartItemSelect),
    PROC_CALL_2(DiscardItem_PostItemSelect),
    PROC_SLEEP(1),

    PROC_CALL_2(DiscardItem_0801C58C),
    PROC_CALL_2(DiscardItem_0801C59C),

PROC_LABEL(99),
    PROC_END,
};

static void EquipInfoWindow_Loop(struct EquipInfoWindowProc * proc);

struct ProcScr CONST_DATA ProcScr_EquipInfoWindow[] =
{
    PROC_19,

    PROC_REPEAT(EquipInfoWindow_Loop),

    PROC_END,
};

static void UnitPrepSwapAnim_Init(struct UnitPrepSwapAnimProc * proc);
static void UnitPrepSwapAnim_Loop(struct UnitPrepSwapAnimProc * proc);
static void UnitPrepSwapAnim_Cleanup(struct UnitPrepSwapAnimProc * proc);

struct ProcScr CONST_DATA ProcScr_UnitPrepSwapAnim[] =
{
    PROC_YIELD,

    PROC_CALL(UnitPrepSwapAnim_Init),
    PROC_REPEAT(UnitPrepSwapAnim_Loop),
    PROC_CALL(UnitPrepSwapAnim_Cleanup),

    PROC_END,
};

static void PhaseIntroText_Init(struct Proc * proc);
static void PhaseIntroText_PutText(struct Proc * proc);
static void PhaseIntroText_InLoop(struct Proc * proc);
static void PhaseIntroText_OutLoop(struct Proc * proc);
static void PhaseIntroText_Clear(struct Proc * proc);

struct ProcScr CONST_DATA ProcScr_PhaseIntroText[] =
{
    PROC_CALL(PhaseIntroText_Init),

    PROC_SLEEP(6),

    PROC_CALL(PhaseIntroText_PutText),

    PROC_REPEAT(PhaseIntroText_InLoop),
    PROC_SLEEP(14),
    PROC_REPEAT(PhaseIntroText_OutLoop),

    PROC_CALL(PhaseIntroText_Clear),

    PROC_END,
};

static void PhaseIntroSquares_Init(struct Proc * proc);
static void PhaseIntroSquares_InLoop(struct Proc * proc);
static void PhaseIntroSquares_OutLoop(struct Proc * proc);

struct ProcScr CONST_DATA ProcScr_PhaseIntroSquares[] =
{
    PROC_CALL(PhaseIntroSquares_Init),
    PROC_REPEAT(PhaseIntroSquares_InLoop),
    PROC_REPEAT(PhaseIntroSquares_OutLoop),

    PROC_END,
};

static void PhaseIntroBlendBox_Init(struct Proc * proc);
static void PhaseIntroBlendBox_InLoop(struct Proc * proc);
static void PhaseIntroBlendBox_OutLoop(struct Proc * proc);

struct ProcScr CONST_DATA ProcScr_PhaseIntroBlendBox[] =
{
    PROC_CALL(PhaseIntroBlendBox_Init),
    PROC_REPEAT(PhaseIntroBlendBox_InLoop),
    PROC_REPEAT(PhaseIntroBlendBox_OutLoop),

    PROC_END,
};

static void PhaseIntro_EndIfNoUnits(ProcPtr proc);
static void PhaseIntro_InitGraphics(ProcPtr proc);
static void PhaseIntro_InitDisp(ProcPtr proc);
static void PhaseIntro_WaitForEnd(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_PhaseIntro[] =
{
    PROC_CALL(PhaseIntro_EndIfNoUnits),
    PROC_CALL(PhaseIntro_InitGraphics),

    PROC_START_CHILD(ProcScr_PhaseIntroText),
    PROC_START_CHILD(ProcScr_PhaseIntroSquares),
    PROC_START_CHILD(ProcScr_PhaseIntroBlendBox),

    PROC_CALL(PhaseIntro_InitDisp),

    PROC_REPEAT(PhaseIntro_WaitForEnd),

    PROC_CALL(StartMapSongBgm),

    PROC_END,
};

static void GasTrapSpriteAnim_Init(struct Proc * proc);

struct ProcScr CONST_DATA ProcScr_GasTrapAnim[] =
{
    PROC_YIELD,

    PROC_CALL(GasTrapSpriteAnim_Init),
    PROC_WHILE(SpriteAnimProcExists),

    PROC_END,
};

static void FireTrapSpriteAnim_Init(struct Proc * proc);

struct ProcScr CONST_DATA ProcScr_FireTrapAnim[] =
{
    PROC_YIELD,

    PROC_CALL(FireTrapSpriteAnim_Init),
    PROC_WHILE(SpriteAnimProcExists),

    PROC_END,
};

static void ArrowTrapSpriteAnim_Init(struct Proc * proc);

struct ProcScr CONST_DATA ProcScr_ArrowTrapAnim[] =
{
    PROC_YIELD,

    PROC_CALL(ArrowTrapSpriteAnim_Init),
    PROC_WHILE(SpriteAnimProcExists),

    PROC_SLEEP(15),

    PROC_END,
};

static void func_fe6_0801D8B8(struct ShowMapChangeProc * proc);
static void func_fe6_0801D8E4(struct ShowMapChangeProc * proc);

struct ProcScr CONST_DATA ProcScr_MapChange_085C5B50[] =
{
    PROC_YIELD,

    PROC_CALL(func_fe6_0801D8B8),
    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_CALL(func_fe6_0801D8E4),
    PROC_WHILE(IsMapFadeActive),

    PROC_END,
};

static void PikeTrapSpriteAnim_Init(struct Proc * proc);

struct ProcScr CONST_DATA ProcScr_PikeTrapAnim[] =
{
    PROC_YIELD,

    PROC_CALL(PikeTrapSpriteAnim_Init),
    PROC_WHILE(SpriteAnimProcExists),

    PROC_END,
};

static void func_fe6_0801DA1C(struct Proc * proc);
static void func_fe6_0801DA24(struct Proc * proc);

struct ProcScr CONST_DATA ProcScr_Unk_085C5BA0[] =
{
    PROC_CALL(func_fe6_0801DA1C),
    PROC_REPEAT(func_fe6_0801DA24),

    PROC_CALL(ClearUi),

    PROC_END,
};

static void ChapterIntro_Bg3Scroll_Loop(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_ChapterIntro_Bg3Scroll[] =
{
    PROC_REPEAT(ChapterIntro_Bg3Scroll_Loop),
    PROC_END,
};

static void ChapterIntro_KeyListen_Init(struct Proc * proc);
static void ChapterIntro_KeyListen_Loop(struct Proc * proc);

struct ProcScr CONST_DATA ProcScr_ChapterIntro_KeyListen[] =
{
    PROC_CALL(ChapterIntro_KeyListen_Init),
    PROC_REPEAT(ChapterIntro_KeyListen_Loop),

    PROC_END,
};

static void ChapterIntro_Init(struct Proc * proc);
static void ChapterIntro_BeginFadeIn(struct Proc * proc);
static void ChapterIntro_LoopFadeIn(struct Proc * proc);
static void ChapterIntro_BeginMotifFadeIn(struct Proc * proc);
static void ChapterIntro_LoopMotifFadeIn(struct Proc * proc);
static void ChapterIntro_BeginHOpenText(struct Proc * proc);
static void ChapterIntro_LoopHOpenText(struct Proc * proc);
static void ChapterIntro_BeginVOpenText(struct Proc * proc);
static void ChapterIntro_LoopVOpenText(struct Proc * proc);
static void ChapterIntro_Begin_0801E1A0(struct Proc * proc);
static void ChapterIntro_Loop_0801E1F8(struct Proc * proc);
static void ChapterIntro_Begin_0801E220(struct Proc * proc);
static void ChapterIntro_Loop_0801E244(struct Proc * proc);
static void ChapterIntro_0801E2B0(struct Proc * proc);
static void ChapterIntro_InitMapDisplay(struct Proc * proc);
static void ChapterIntro_BeginFadeToMap(struct Proc * proc);
static void ChapterIntro_LoopFadeToMap(struct Proc * proc);
static void ChapterIntro_BeginCloseText(struct Proc * proc);
static void ChapterIntro_LoopCloseText(struct Proc * proc);
static void ChapterIntro_BeginFastCloseText(struct Proc * proc);
static void ChapterIntro_LoopFastCloseText(struct Proc * proc);
static void ChapterIntro_BeginFadeOut(struct Proc * proc);
static void ChapterIntro_LoopFadeOut(struct Proc * proc);
static void ChapterIntro_BeginFastFadeToMap(struct Proc * proc);
static void ChapterIntro_LoopFastFadeToMap(struct Proc * proc);
static void ChapterIntro_SetSkipTarget(short arg, struct Proc * proc);

struct ProcScr CONST_DATA ProcScr_ChapterIntro[] =
{
    PROC_CALL(LockBmDisplay),

    PROC_CALL(ChapterIntro_Init),

    PROC_START_CHILD(ProcScr_ChapterIntro_Bg3Scroll),
    PROC_START_CHILD(ProcScr_ChapterIntro_KeyListen),

    PROC_CALL_ARG(ChapterIntro_SetSkipTarget, 1),

    PROC_CALL(ChapterIntro_BeginFadeIn),
    PROC_REPEAT(ChapterIntro_LoopFadeIn),

    PROC_SLEEP(40),

    PROC_CALL(ChapterIntro_BeginMotifFadeIn),
    PROC_REPEAT(ChapterIntro_LoopMotifFadeIn),

    PROC_SLEEP(80),

    PROC_CALL_ARG(ChapterIntro_SetSkipTarget, 0),

    PROC_CALL(ChapterIntro_BeginHOpenText),
    PROC_REPEAT(ChapterIntro_LoopHOpenText),

    PROC_CALL(ChapterIntro_BeginVOpenText),
    PROC_REPEAT(ChapterIntro_LoopVOpenText),

    PROC_CALL_ARG(ChapterIntro_SetSkipTarget, 1),

    PROC_CALL(ChapterIntro_Begin_0801E1A0),
    PROC_REPEAT(ChapterIntro_Loop_0801E1F8),

    PROC_SLEEP(120),

    PROC_CALL(ChapterIntro_Begin_0801E220),
    PROC_REPEAT(ChapterIntro_Loop_0801E244),

    PROC_END_EACH(ProcScr_ChapterIntro_Bg3Scroll),

    PROC_CALL_ARG(ChapterIntro_SetSkipTarget, 0),

    PROC_CALL(ChapterIntro_0801E2B0),

    PROC_CALL(UnlockBmDisplay),

    PROC_CALL(ChapterIntro_InitMapDisplay),

    PROC_CALL(ChapterIntro_BeginFadeToMap),
    PROC_REPEAT(ChapterIntro_LoopFadeToMap),

    PROC_CALL_ARG(ChapterIntro_SetSkipTarget, 2),

    PROC_SLEEP(90),

    PROC_CALL_ARG(ChapterIntro_SetSkipTarget, 0),

    PROC_CALL(ChapterIntro_BeginCloseText),
    PROC_REPEAT(ChapterIntro_LoopCloseText),

    PROC_SLEEP(30),

    PROC_GOTO(99),

PROC_LABEL(1),
    PROC_CALL(ChapterIntro_BeginFadeOut),
    PROC_REPEAT(ChapterIntro_LoopFadeOut),

    PROC_CALL(ChapterIntro_0801E2B0),

    PROC_CALL(UnlockBmDisplay),

    PROC_CALL(ChapterIntro_InitMapDisplay),

    PROC_CALL(ChapterIntro_BeginFastFadeToMap),
    PROC_REPEAT(ChapterIntro_LoopFastFadeToMap),

    PROC_GOTO(99),

PROC_LABEL(2),
    PROC_CALL(ChapterIntro_BeginFastCloseText),
    PROC_REPEAT(ChapterIntro_LoopFastCloseText),

PROC_LABEL(99),
    PROC_END,
};

static void GameOverScreen_RandomScroll_Init(struct Proc * proc);
static void GameOverScreen_RandomScroll_Loop(struct Proc * proc);

struct ProcScr CONST_DATA ProcScr_GameOverScreen_RandomScroll[] =
{
    PROC_CALL(GameOverScreen_RandomScroll_Init),
    PROC_REPEAT(GameOverScreen_RandomScroll_Loop),

    PROC_END,
};

static void GameOverScreen_Init(struct Proc * proc);
static void GameOverScreen_LoopFadeIn(struct Proc * proc);
static void GameOverScreen_BeginIdle(struct Proc * proc);
static void GameOverScreen_LoopIdle(struct Proc * proc);
static void GameOverScreen_BeginFadeOut(struct Proc * proc);
static void GameOverScreen_LoopFadeOut(struct Proc * proc);
static void GameOverScreen_End(struct Proc * proc);

struct ProcScr CONST_DATA ProcScr_GameOverScreen[] =
{
    PROC_ONEND(GameOverScreen_End),
    PROC_CALL(GameOverScreen_Init),

    PROC_CALL(EndAllMus),

    PROC_START_CHILD(ProcScr_GameOverScreen_RandomScroll),

    PROC_REPEAT(GameOverScreen_LoopFadeIn),

    PROC_CALL(GameOverScreen_BeginIdle),
    PROC_REPEAT(GameOverScreen_LoopIdle),

PROC_LABEL(99),
    PROC_CALL(GameOverScreen_BeginFadeOut),
    PROC_REPEAT(GameOverScreen_LoopFadeOut),

    PROC_END,
};

int GetRescueTransferFacing(int xa, int ya, int xb, int yb)
{
    if (xa == xb)
    {
        if (ya < yb)
            return FACING_UP;

        if (ya > yb)
            return FACING_DOWN;
    }

    if (ya == yb)
    {
        if (xa < xb)
            return FACING_LEFT;

        if (xa > xb)
            return FACING_RIGHT;
    }

    return FACING_LEFT;
}

static struct MuProc * StartMuForRescueTransferAnim(struct Unit * unit)
{
    if (!(UNIT_ATTRIBUTES(unit) & UNIT_ATTR_MOUNTED))
        return StartMu(unit);

    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_FEMALE)
        return StartMuExt(unit->x, unit->y, JID_DISMOUNTED_F, 12);
    else
        return StartMuExt(unit->x, unit->y, JID_DISMOUNTED, 12);
}

static void RescueTransferSpriteAnim_Loop(struct RescueTransferAnimProc * proc)
{
    if (MuExistsActive())
        return;

    EndMu(proc->mu);
    Proc_Break(proc);

    if (proc->unk_3C)
    {
        RefreshEntityMaps();
        RefreshUnitSprites();
        ForceSyncUnitSpriteSheet();
    }
}

void StartRescueTransferAnim(struct Unit * unit, int facing, bool arg_2, ProcPtr parent)
{
    struct RescueTransferAnimProc * proc;

    proc = SpawnProcLocking(ProcScr_RescueTransferAnim, parent);

    proc->unit = unit;
    proc->facing = facing;

    proc->movescr[0] = MOVE_CMD_CAMERA_OFF;
    proc->movescr[1] = MOVE_CMD_MOVE_BASE + facing;
    proc->movescr[2] = MOVE_CMD_HALT;

    proc->unk_3C = arg_2;

    proc->mu = StartMuForRescueTransferAnim(unit);
    SetMuMoveScript(proc->mu, proc->movescr);
}

void StartRescueTransferAnimParentless(struct Unit * unit, int facing)
{
    struct RescueTransferAnimProc * proc;

    proc = SpawnProc(ProcScr_RescueTransferAnimParentless, PROC_TREE_3);

    proc->unit = unit;
    proc->facing = facing;

    proc->movescr[0] = MOVE_CMD_CAMERA_OFF;
    proc->movescr[1] = MOVE_CMD_MOVE_BASE + facing;
    proc->movescr[2] = MOVE_CMD_HALT;

    proc->unk_3C = FALSE;

    proc->mu = StartMuForRescueTransferAnim(unit);
    SetMuMoveScript(proc->mu, proc->movescr);
}

static void MapFade_Init(struct Proc * proc)
{
    proc->unk4C = 0x10;

    InitBmBgLayers();

    SetBlendTargetA(0, 0, 1, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 1);
}

static void MapFade_Loop(struct Proc * proc)
{
    SetBlendAlpha(proc->unk4C, 0x10 - proc->unk4C);

    proc->unk4C--;

    if (proc->unk4C < 0)
    {
        Proc_Break(proc);

        SetBlendNone();

        SetBgChrOffset(2, 0);
        TmFill(gBg2Tm, 0);

        EnableBgSync(BG2_SYNC_BIT);
    }
}

static void MapFade_End(struct Proc * proc)
{
    ClearMapFadeUnits();

    if (proc->unk4E)
        UnlockGame();
}

void StartMapFade(bool locks_game)
{
    struct Proc * proc;

    proc = SpawnProc(ProcScr_MapFade, PROC_TREE_3);
    proc->unk4E = locks_game;

    if (locks_game)
        LockGame();
}

bool IsMapFadeActive(void)
{
    return Proc_Exists(ProcScr_MapFade);
}

static void GetPlayerInitialCursorPosition(int * x_out, int * y_out)
{
    struct Unit * unit;

    if (gPlaySt.turn == 1)
    {
        unit = GetUnitByPid(PID_ROY);

        gPlaySt.x_cursor = unit->x;
        gPlaySt.y_cursor = unit->y;
    }

    if (!gPlaySt.config_no_auto_cursor)
    {
        unit = GetUnitByPid(PID_ROY);

        *x_out = unit->x;
        *y_out = unit->y;
    }
    else
    {
        *x_out = gPlaySt.x_cursor;
        *y_out = gPlaySt.y_cursor;
    }
}

static void GetAiInitialCursorPosition(int * x_out, int * y_out)
{
    int i;

    for (i = gPlaySt.faction + 1; i < gPlaySt.faction + 0x40; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if (unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_CONCEALED))
            continue;

        *x_out = unit->x;
        *y_out = unit->y;

        if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_BOSS)
            return;
    }
}

static void InitPhaseCursor_Init(ProcPtr proc)
{
    int x = -1;
    int y = -1;

    if (CountFactionMoveableUnits(gPlaySt.faction) == 0)
    {
        Proc_End(proc);
        return;
    }

    switch (gPlaySt.faction)
    {

    case FACTION_BLUE:
        GetPlayerInitialCursorPosition(&x, &y);
        break;

    case FACTION_RED:
    case FACTION_GREEN:
        GetAiInitialCursorPosition(&x, &y);
        break;

    }

    if (x >= 0 && y >= 0)
    {
        CameraMoveWatchPosition(proc, x, y);
        SetMapCursorPosition(x, y);
    }
}

static void ReturnFromStatScreen_Init(ProcPtr proc)
{
    struct Unit * unit = GetUnit(GetLastStatScreenUnitId());

    if (unit != NULL)
    {
        int x = unit->x;
        int y = unit->y;

        CameraMoveWatchPosition(proc, x, y);
        SetMapCursorPosition(x, y);
    }
}

static int DiscardItem_StartItemSelect(ProcPtr proc)
{
    ApplyIconPalettes(BGPAL_ICONS);
    StartLockingMenu(&MenuInfo_DiscardItem, proc);

    return FALSE;
}

static int DiscardItem_PostItemSelect(ProcPtr proc)
{
    EndSubtitleHelp();
    EndEquipInfoWindow();

    if (gBmSt.convoy_item_overflow == 0)
    {
        Proc_Goto(proc, 99);
        return TRUE;
    }

    return FALSE;
}

static int DiscardItem_0801C58C(ProcPtr proc)
{
    func_fe6_08081620(NULL, proc);
    return FALSE;
}

static int DiscardItem_0801C59C(ProcPtr proc)
{
    return AddSupplyItem(gBmSt.convoy_item_overflow);
}

void HandleGiveUnitItem(struct Unit * unit, int item, ProcPtr parent)
{
    gActiveUnit = unit;

    if (!UnitAddItem(unit, item))
    {
        gBmSt.inventory_item_overflow = item;

        StartFace(0, GetUnitFid(unit), 22*8, 4, FACE_DISP_KIND(FACE_96x80));
        StartEquipInfoWindow(parent, unit, 15, 10);
        StartSubtitleHelp(parent, DecodeMsg(MSG_C26));

        SpawnProcLocking(ProcScr_DiscardItem, parent);
    }
}

u32 DiscardItemMenu_InventoryEntry_Display(struct MenuProc * menu, struct MenuEntProc * ent)
{
    return UnitItemMenu_Entry_Display(menu, ent);
}

u32 DiscardItemMenu_ExtraEntry_Display(struct MenuProc * menu, struct MenuEntProc * ent)
{
    int item = gBmSt.inventory_item_overflow;

    Text_SetColor(&ent->text, TEXT_COLOR_SYSTEM_BLUE);
    DrawItemMenuLineNoColor(&ent->text, item, gBg0Tm + TM_OFFSET(ent->x, ent->y));

    EnableBgSync(BG0_SYNC_BIT);

#if BUGFIX
    return 0;
#endif
}

fu8 DiscardItemMenu_InventoryEntry_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    AddSupplyItem(gActiveUnit->items[ent->id]);

    UnitRemoveItem(gActiveUnit, ent->id);
    UnitAddItem(gActiveUnit, gBmSt.inventory_item_overflow);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR | MENU_ACTION_ENDFACE;
}

fu8 DiscardItemMenu_ExtraEntry_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    AddSupplyItem(gBmSt.inventory_item_overflow);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR | MENU_ACTION_ENDFACE;
}

void SetFogVision(int vision)
{
    if (vision < 0)
        vision = GetChapterInfo(gPlaySt.chapter)->fog;

    RenderMapForFade();

    gPlaySt.vision = vision;

    RefreshEntityMaps();
    RefreshUnitSprites();
    RenderMap();

    StartMapFade(TRUE);
}

void BuildWarpDestinationMap(struct Unit * actor, struct Unit * target)
{
    int ix, iy;

    MapFill(gMapMovement, -1);
    MapFill(gMapRange, 0);

    SetWorkingMap(gMapMovement);

    MapIncInBoundedRange(target->x, target->y, 1, GetUnitMagRange(actor));

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (!CanUnitCrossTerrain(target, gMapTerrain[iy][ix]) || gMapUnit[iy][ix] != 0 || gMapFog[iy][ix] == 0)
                gMapMovementSigned[iy][ix] = -1;
        }
    }

    gMapMovementSigned[actor->y][actor->x] = -1;
}

static void EquipInfoWindow_Loop(struct EquipInfoWindowProc * proc)
{
    if (proc->compareWeaponSlot < 0)
        return;

    if (gBattleUnitA.battle_attack > gBattleUnitB.battle_attack)
        PutSysArrow(51 + 8*proc->x, 8*(proc->y+3), FALSE);

    if (gBattleUnitA.battle_attack < gBattleUnitB.battle_attack)
        PutSysArrow(51 + 8*proc->x, 8*(proc->y+3), TRUE);

    if (gBattleUnitA.battle_hit > gBattleUnitB.battle_hit)
        PutSysArrow(51 + 8*proc->x, 8*(proc->y+5), FALSE);

    if (gBattleUnitA.battle_hit < gBattleUnitB.battle_hit)
        PutSysArrow(51 + 8*proc->x, 8*(proc->y+5), TRUE);

    if (gBattleUnitA.battle_crit > gBattleUnitB.battle_crit)
        PutSysArrow(99 + 8*proc->x, 8*(proc->y+3), FALSE);

    if (gBattleUnitA.battle_crit < gBattleUnitB.battle_crit)
        PutSysArrow(99 + 8*proc->x, 8*(proc->y+3), TRUE);

    if (gBattleUnitA.battle_avoid > gBattleUnitB.battle_avoid)
        PutSysArrow(99 + 8*proc->x, 8*(proc->y+5), FALSE);

    if (gBattleUnitA.battle_avoid < gBattleUnitB.battle_avoid)
        PutSysArrow(99 + 8*proc->x, 8*(proc->y+5), TRUE);
}

void StartEquipInfoWindow(ProcPtr parent, struct Unit * unit, int x, int y)
{
    struct EquipInfoWindowProc * proc;

    if (FindProc(ProcScr_EquipInfoWindow) != NULL)
        return;

    proc = SpawnProc(ProcScr_EquipInfoWindow, parent);

    proc->unit = unit;
    proc->x = x;
    proc->y = y;
    proc->iconPalid = BGPAL_EQUIP_INFO_ICON;
    proc->compareWeaponSlot = GetUnitEquippedWeaponSlot(unit);

    InitTextDb(proc->text + 0, 12);
    InitTextDb(proc->text + 1, 12);
    InitTextDb(proc->text + 2, 12);

    ApplyIconPalette(1, proc->iconPalid);

    BattleGenerateDisplayStats(proc->unit, -1);

    gBattleUnitB.battle_attack = gBattleUnitA.battle_attack;
    gBattleUnitB.battle_hit = gBattleUnitA.battle_hit;
    gBattleUnitB.battle_crit = gBattleUnitA.battle_crit;
    gBattleUnitB.battle_avoid = gBattleUnitA.battle_avoid;
}

void UpdateEquipInfoWindow(int item_slot)
{
    struct EquipInfoWindowProc * proc = FindProc(ProcScr_EquipInfoWindow);

    int item;

    ClearText(proc->text + 0);
    ClearText(proc->text + 1);
    ClearText(proc->text + 2);

    PutUiWindowFrame(proc->x, proc->y, 14, 8, UI_WINDOW_REGULAR);

    switch (item_slot)
    {

    case ITEMSLOT_INV0 ... ITEMSLOT_INV_COUNT - 1:
        item = proc->unit->items[item_slot];
        break;

    case ITEMSLOT_OVERFLOW:
        item = gBmSt.inventory_item_overflow;
        break;

    default:
        item = item_slot;
        item_slot = ITEMSLOT_BALLISTA;

    }

    switch (GetItemKind(item))
    {

    case ITEM_KIND_STAFF:
    case ITEM_KIND_ITEM:
    case ITEM_KIND_DRAGONSTONE:
    {
        // print use description

        char const * str = DecodeMsg(GetItemUseDescMsg(item));
        int line = 0;

        while (TRUE)
        {
            Text_InsertDrawString(proc->text + line, 0, TEXT_COLOR_SYSTEM_WHITE, str);
            str = GetStringLineEnd(str);

            if (str[0] == '\0')
                break;

            str++;
            line++;
        }

        gBattleUnitA.battle_attack = gBattleUnitB.battle_attack;
        gBattleUnitA.battle_hit = gBattleUnitB.battle_hit;
        gBattleUnitA.battle_crit = gBattleUnitB.battle_crit;
        gBattleUnitA.battle_avoid = gBattleUnitB.battle_avoid;

        PutText(proc->text + 0, gBg0Tm + TM_OFFSET(proc->x+1, proc->y+1));
        PutText(proc->text + 1, gBg0Tm + TM_OFFSET(proc->x+1, proc->y+3));
        PutText(proc->text + 2, gBg0Tm + TM_OFFSET(proc->x+1, proc->y+5));

        break;
    }

    default:
    {
        // print stats

        int color;

        BattleGenerateDisplayStats(proc->unit, item_slot);

        if (item_slot == ITEMSLOT_BALLISTA)
        {
            gBattleUnitB.battle_attack = gBattleUnitA.battle_attack;
            gBattleUnitB.battle_hit = gBattleUnitA.battle_hit;
            gBattleUnitB.battle_crit = gBattleUnitA.battle_crit;
            gBattleUnitB.battle_avoid = gBattleUnitA.battle_avoid;
        }

        if (CanUnitUseWeapon(proc->unit, gBattleUnitA.weapon))
            color = TEXT_COLOR_SYSTEM_BLUE;
        else
            color = TEXT_COLOR_SYSTEM_GRAY;

        Text_InsertDrawString(proc->text + 0, 0x20,   TEXT_COLOR_SYSTEM_WHITE, TEXT("属性", "Attr"));
        Text_InsertDrawString(proc->text + 1, 0x00+2, TEXT_COLOR_SYSTEM_WHITE, TEXT("攻撃", "Atk"));
        Text_InsertDrawString(proc->text + 2, 0x00+2, TEXT_COLOR_SYSTEM_WHITE, TEXT("命中", "Hit"));
        Text_InsertDrawString(proc->text + 1, 0x30+2, TEXT_COLOR_SYSTEM_WHITE, TEXT("必殺", "Crit"));
        Text_InsertDrawString(proc->text + 2, 0x30+2, TEXT_COLOR_SYSTEM_WHITE, TEXT("回避", "Avo"));

        Text_InsertDrawNumberOrBlank(proc->text + 1, 0x20+4, color, gBattleUnitA.battle_attack);
        Text_InsertDrawNumberOrBlank(proc->text + 2, 0x20+4, color, gBattleUnitA.battle_hit);
        Text_InsertDrawNumberOrBlank(proc->text + 1, 0x50+4, color, gBattleUnitA.battle_crit);
        Text_InsertDrawNumberOrBlank(proc->text + 2, 0x50+4, color, gBattleUnitA.battle_avoid);

        PutText(proc->text + 0, gBg0Tm + TM_OFFSET(proc->x+1, proc->y+1));
        PutText(proc->text + 1, gBg0Tm + TM_OFFSET(proc->x+1, proc->y+3));
        PutText(proc->text + 2, gBg0Tm + TM_OFFSET(proc->x+1, proc->y+5));

        PutIcon(gBg0Tm + TM_OFFSET(proc->x+7, proc->y+1),
            ICON_ITEM_KIND_BASE + GetItemKind(gBattleUnitA.weapon), TILEREF(0, BGPAL_EQUIP_INFO_ICON));

        break;
    }

    }

    EnableBgSync(BG0_SYNC_BIT);
}

void EndEquipInfoWindow(void)
{
    Proc_EndEach(ProcScr_EquipInfoWindow);
}

static void UnitPrepSwapAnim_Init(struct UnitPrepSwapAnimProc * proc)
{
    int xd, yd, dist;

    proc->x_from = proc->unit->x << 4;
    proc->y_from = proc->unit->y << 4;

    xd = proc->x_target - proc->x_from;
    yd = proc->y_target - proc->y_from;

    dist = Sqrt(xd * xd + yd * yd);

    proc->unk_44 = Interpolate(INTERPOLATE_LINEAR, 0x01 << 12, 0x20 << 12, dist, 0x200);
    proc->unk_3E = Interpolate(INTERPOLATE_LINEAR, 12, 48, dist, 0x200);

    proc->unk_3C = 0;
}

static void UnitPrepSwapAnim_Loop(struct UnitPrepSwapAnimProc * proc)
{
    int var = Interpolate(INTERPOLATE_LINEAR, 0, 1 << 16, proc->unk_3C, proc->unk_3E);

    int xd = proc->x_target - proc->x_from;
    int yd = proc->y_target - proc->y_from;

    int xunk = xd * SIN_Q12(var >> 9) / proc->unk_44;
    int yunk = yd * SIN_Q12(var >> 9) / proc->unk_44;

    int x = ((xd * var) >> 16) + yunk;
    int y = ((yd * var) >> 16) - xunk;

    x = x + proc->x_from - gBmSt.camera.x;
    y = y + proc->y_from - gBmSt.camera.y;

    if ((x >= -16 && x <= DISPLAY_WIDTH) && (y >= -32 && y <= DISPLAY_HEIGHT))
    {
        PutSprite(4, x, y - 12, Sprite_16x16, TILEREF(6, 0));
        PutUnitSprite(4, x, y, proc->unit);
    }

    proc->unk_3C++;

    if (proc->unk_3C > proc->unk_3E)
        Proc_Break(proc);
}

static void UnitPrepSwapAnim_Cleanup(struct UnitPrepSwapAnimProc * proc)
{
    proc->unit->x = proc->x_target / 16;
    proc->unit->y = proc->y_target / 16;

    RefreshEntityMaps();
    RefreshUnitSprites();
}

void StartUnitPrepSwapAnim(ProcPtr parent, struct Unit * unit, int x, int y)
{
    struct UnitPrepSwapAnimProc * proc;

    proc = SpawnProcLocking(ProcScr_UnitPrepSwapAnim, parent);

    proc->unit = unit;

    proc->x_target = x * 16;
    proc->y_target = y * 16;

    HideUnitSprite(unit);
}

static void PhaseIntroVMatchHi(void);
static void PhaseIntroVMatchMid(void);
static void PhaseIntroVMatchLo(void);

static void PhaseIntroVMatchHi(void)
{
    REG_BLDCNT = BLDCNT_EFFECT_ALPHA
        | BLDCNT_TARGETA(0, 1, 0, 0, 0)
        | BLDCNT_TARGETB(0, 0, 1, 1, 1) | BLDCNT_TARGETB_BD;

    REG_BLDCA = gBmSt.alt_blend_b_ca;
    REG_BLDCB = gBmSt.alt_blend_b_cb;

    SetNextVCount(72);
    SetOnVMatch(PhaseIntroVMatchMid);
}

static void PhaseIntroVMatchMid(void)
{
    REG_BLDCNT = BLDCNT_EFFECT_ALPHA
        | BLDCNT_TARGETA(1, 0, 0, 0, 0)
        | BLDCNT_TARGETB(0, 1, 1, 1, 1) | BLDCNT_TARGETB_BD;

    REG_BLDCA = gBmSt.alt_blend_a_ca;
    REG_BLDCB = gBmSt.alt_blend_a_cb;

    SetNextVCount(96);
    SetOnVMatch(PhaseIntroVMatchLo);
}

static void PhaseIntroVMatchLo(void)
{
    REG_BLDCNT = BLDCNT_EFFECT_ALPHA
        | BLDCNT_TARGETA(0, 1, 0, 0, 0)
        | BLDCNT_TARGETB(0, 0, 1, 1, 1) | BLDCNT_TARGETB_BD;

    REG_BLDCA = gBmSt.alt_blend_b_ca;
    REG_BLDCB = gBmSt.alt_blend_b_cb;

    SetNextVCount(0);
    SetOnVMatch(PhaseIntroVMatchHi);
}

static void PhaseIntroText_PutText(struct Proc * proc)
{
    u16 * tm = gBg0Tm + TM_OFFSET(0, 9);
    int i;

    for (i = 0; i < 0x60; ++i)
        *tm++ = TILEREF(BGCHR_PHASE_CHANGE_NAME + i, BGPAL_PHASE_CHANGE);

    EnableBgSync(BG0_SYNC_BIT);
}

static void PhaseIntroText_Init(struct Proc * proc)
{
    if (GetCurrentBgmSong() != GetActiveMapSong())
        FadeBgmOut(4);

    PlaySe(SONG_73);

    proc->unk4C = 15;
}

static void PhaseIntroText_InLoop(struct Proc * proc)
{
    SetBgOffset(0, Interpolate(INTERPOLATE_CUBIC, -28, -64, proc->unk4C, 0x10), 0);

    gBmSt.alt_blend_a_ca++;
    gBmSt.alt_blend_a_cb--;

    proc->unk4C--;

    if (proc->unk4C < 0)
    {
        proc->unk4C = 15;
        Proc_Break(proc);
    }
}

static void PhaseIntroText_OutLoop(struct Proc * proc)
{
    SetBgOffset(0, Interpolate(INTERPOLATE_RCUBIC, +36, -28, proc->unk4C, 0x10), 0);

    gBmSt.alt_blend_a_ca--;
    gBmSt.alt_blend_a_cb++;

    proc->unk4C--;

    if (proc->unk4C < 0)
    {
        proc->unk4C = 15;
        Proc_Break(proc);
    }
}

static void PhaseIntroText_Clear(struct Proc * proc)
{
    TmFill(gBg0Tm, 0);
    EnableBgSync(BG0_SYNC_BIT);
}

static void PhaseIntroSquares_Init(struct Proc * proc)
{
    proc->unk4C = 4;
}

static void PhaseIntroSquares_InLoop(struct Proc * proc)
{
    int ix, iy;

    for (iy = 10-1; iy >= 0; --iy)
    {
        for (ix = 15-1; ix >= 0; --ix)
        {
            int num = (1 - proc->unk4C) + (10 + ix) + (10 - iy);

            if (num > 0x10)
                num = 0x10;

            if (num < 0)
                num = 0;

            num = (0x10 - num) & 0xFE;

            gBg1Tm[TM_OFFSET(ix*2+0, iy*2+0)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x00, BGPAL_PHASE_CHANGE);
            gBg1Tm[TM_OFFSET(ix*2+1, iy*2+0)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x01, BGPAL_PHASE_CHANGE);
            gBg1Tm[TM_OFFSET(ix*2+0, iy*2+1)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x20, BGPAL_PHASE_CHANGE);
            gBg1Tm[TM_OFFSET(ix*2+1, iy*2+1)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x21, BGPAL_PHASE_CHANGE);
        }
    }

    proc->unk4C++;

    EnableBgSync(BG1_SYNC_BIT);

    if (proc->unk4C == 0x22)
    {
        proc->unk4C = 0;
        Proc_Break(proc);
    }
}

static void PhaseIntroSquares_OutLoop(struct Proc * proc)
{
    int ix, iy;

    for (iy = 10-1; iy >= 0; --iy)
    {
        for (ix = 15-1; ix >= 0; --ix)
        {
            int num = (1 - proc->unk4C) + (10 + ix) + (10 - iy);

            if (num > 0x10)
                num = 0x10;

            if (num < 0)
                num = 0;

            num = num & 0xFE;

            gBg1Tm[TM_OFFSET(ix*2+0, iy*2+0)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x01, BGPAL_PHASE_CHANGE) + TILE_HFLIP;
            gBg1Tm[TM_OFFSET(ix*2+1, iy*2+0)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x00, BGPAL_PHASE_CHANGE) + TILE_HFLIP;
            gBg1Tm[TM_OFFSET(ix*2+0, iy*2+1)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x21, BGPAL_PHASE_CHANGE) + TILE_HFLIP;
            gBg1Tm[TM_OFFSET(ix*2+1, iy*2+1)] = TILEREF(BGCHR_PHASE_CHANGE_SQUARES + num + 0x20, BGPAL_PHASE_CHANGE) + TILE_HFLIP;
        }
    }

    proc->unk4C++;

    EnableBgSync(BG1_SYNC_BIT);

    if (proc->unk4C == 0x24)
    {
        proc->unk4C = 0;
        Proc_Break(proc);
    }
}

static void PhaseIntroBlendBox_Init(struct Proc * proc)
{
    proc->unk4C = 4;
}

static void PhaseIntroBlendBox_InLoop(struct Proc * proc)
{
    int yoff, blend;

    yoff = Interpolate(INTERPOLATE_RCUBIC, 16, 60, proc->unk4C, 0x20);

    SetWin0Box(0, 8 + yoff, DISPLAY_WIDTH, -0x60 - yoff);

    blend = Interpolate(INTERPOLATE_LINEAR, 0, 7, proc->unk4C, 0x20);

    gBmSt.alt_blend_b_ca = blend;
    gBmSt.alt_blend_b_cb = 0x10 - blend;

    proc->unk4C++;

    if (proc->unk4C == 0x20)
        Proc_Break(proc);
}

static void PhaseIntroBlendBox_OutLoop(struct Proc * proc)
{
    int yoff, blend;

    yoff = Interpolate(INTERPOLATE_RCUBIC, 0, 60, proc->unk4C, 0x20);

    SetWin0Box(0, 8 + yoff, DISPLAY_WIDTH, -0x60 - yoff);

    blend = Interpolate(INTERPOLATE_LINEAR, 0, 7, proc->unk4C, 0x20);

    gBmSt.alt_blend_b_ca = blend;
    gBmSt.alt_blend_b_cb = 0x10 - blend;

    proc->unk4C--;

    if (proc->unk4C < 0)
        Proc_Break(proc);
}

static void PhaseIntro_EndIfNoUnits(ProcPtr proc)
{
    if (CountFactionMoveableUnits(gPlaySt.faction) == 0)
        Proc_End(proc);
}

static void PhaseIntro_InitGraphics(ProcPtr proc)
{
    Decompress(Img_PhaseChangeSquares, (u8 *) VRAM + CHR_SIZE*BGCHR_PHASE_CHANGE_SQUARES);

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(2, 0, 0);

    switch (gPlaySt.faction)
    {

    case FACTION_BLUE:
        Decompress(Img_PhaseChangePlayer, (u8 *) VRAM + CHR_SIZE*BGCHR_PHASE_CHANGE_NAME);
        ApplyPalette(Pal_PhaseChangePlayer, BGPAL_PHASE_CHANGE);

        break;

    case FACTION_RED:
        Decompress(Img_PhaseChangeEnemy, (u8 *) VRAM + CHR_SIZE*BGCHR_PHASE_CHANGE_NAME);
        ApplyPalette(Pal_PhaseChangeEnemy, BGPAL_PHASE_CHANGE);

        break;

    case FACTION_GREEN:
        Decompress(Img_PhaseChangeOther, (u8 *) VRAM + CHR_SIZE*BGCHR_PHASE_CHANGE_NAME);
        ApplyPalette(Pal_PhaseChangeOther, BGPAL_PHASE_CHANGE);

        break;

    }
}

static void PhaseIntro_InitDisp(ProcPtr proc)
{
    SetWinEnable(1, 0, 0);

    SetWin0Box(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);

    SetWin0Layers(1, 0, 1, 1, 1);
    SetWOutLayers(1, 1, 1, 1, 1);

    gDispIo.win_ct.win0_enable_blend = 1;
    gDispIo.win_ct.wout_enable_blend = 1;

    gBmSt.alt_blend_b_ca = 0;
    gBmSt.alt_blend_b_cb = 0x10;

    gBmSt.alt_blend_a_ca = 0;
    gBmSt.alt_blend_a_cb = 0x10;

    SetBlendAlpha(gBmSt.alt_blend_b_ca, gBmSt.alt_blend_b_cb);

    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 1, 1);

    SetVCount(0);
    SetOnVMatch(PhaseIntroVMatchHi);
}

static void PhaseIntro_WaitForEnd(ProcPtr proc)
{
    SetBlendAlpha(gBmSt.alt_blend_b_ca, gBmSt.alt_blend_b_cb);

    if (FindProc(ProcScr_PhaseIntroText) == NULL && FindProc(ProcScr_PhaseIntroSquares) == NULL && FindProc(ProcScr_PhaseIntroBlendBox) == NULL)
    {
        ClearUi();

        SetOnVMatch(NULL);

        SetBgOffset(0, 0, 0);
        SetBgOffset(1, 0, 0);
        SetBgOffset(2, 0, 0);

        Proc_Break(proc);
    }
}

void MakeActiveMuWatchPosition(int x, int y)
{
    int cmd = MOVE_CMD_FACE_BASE + GetFacingFromTo(gActiveUnit->x, gActiveUnit->y, x, y);

    gWorkingMoveScr[0] = cmd;
    gWorkingMoveScr[1] = MOVE_CMD_HALT;

    SetAutoMuMoveScript(gWorkingMoveScr);
}

static void GasTrapSpriteAnim_Init(struct Proc * proc)
{
    int x, y, oam2;

    u8 const * img = NULL;
    u16 const * anim = NULL;
    int animNum = 0;

    switch (proc->unk4A)
    {

    case FACING_UP:
        img = Img_GasTrapVertical;
        anim = SpriteAnim_GasTrapVertical;
        break;

    case FACING_DOWN:
        img = Img_GasTrapVertical;
        anim = SpriteAnim_GasTrapVertical;
        animNum = 1;
        break;

    case FACING_LEFT:
        img = Img_GasTrapHorizontal;
        anim = SpriteAnim_GasTrapHorizontal;
        animNum = 1;
        break;

    case FACING_RIGHT:
        img = Img_GasTrapHorizontal;
        anim = SpriteAnim_GasTrapHorizontal;
        break;

    }

    Decompress(img, (u8 *) OBJ_VRAM0 + CHR_SIZE*OBCHR_TRAPFX);
    ApplyPalette(Pal_GasTrap, 0x10 + OBPAL_TRAPFX);

    x = proc->x*16 + 8 - gBmSt.camera.x;
    y = proc->y*16 + 8 - gBmSt.camera.y;
    oam2 = OAM2_CHR(OBCHR_TRAPFX) | OAM2_PAL(OBPAL_TRAPFX) | OAM2_LAYER(1);

    StartSpriteAnimProc(anim, x, y, oam2, animNum, 0);
    PlaySeSpacial(SONG_BA, x+8);
}

void StartGasTrapAnim(ProcPtr parent, int x, int y, int facing)
{
    struct Proc * proc;

    proc = SpawnProcLocking(ProcScr_GasTrapAnim, parent);

    proc->x = x;
    proc->y = y;
    proc->unk4A = facing;
}

static void FireTrapSpriteAnim_Init(struct Proc * proc)
{
    int x, y, oam2;

    Decompress(Img_FireTrap, (u8 *) OBJ_VRAM0 + CHR_SIZE*OBCHR_TRAPFX);
    ApplyPalette(Pal_FireTrap, 0x10 + OBPAL_TRAPFX);

    x = proc->x*16 + 8 - gBmSt.camera.x;
    y = proc->y*16 + 8 - gBmSt.camera.y;
    oam2 = OAM2_CHR(OBCHR_TRAPFX) | OAM2_PAL(OBPAL_TRAPFX) | OAM2_LAYER(1);

    StartSpriteAnimProc(SpriteAnim_FireTrap, x, y, oam2, 0, 0);
    PlaySeSpacial(SONG_BF, x+8);
}

void StartFireTrapAnim(ProcPtr parent, int x, int y)
{
    struct Proc * proc;

    proc = SpawnProcLocking(ProcScr_FireTrapAnim, parent);

    proc->x = x;
    proc->y = y;
}

static void ArrowTrapSpriteAnim_Init(struct Proc * proc)
{
    int x, oam2;

    Decompress(Img_ArrowTrap, (u8 *) OBJ_VRAM0 + CHR_SIZE*OBCHR_TRAPFX);
    ApplyPalette(Pal_ArrowTrap, 0x10 + OBPAL_TRAPFX);

    x = proc->x*16 + 8 - gBmSt.camera.x;
    oam2 = OAM2_CHR(OBCHR_TRAPFX) | OAM2_PAL(OBPAL_TRAPFX) | OAM2_LAYER(1);

    StartSpriteAnimProc(SpriteAnim_ArrowTrap, x, DISPLAY_HEIGHT/2, oam2, 0, 0);
    PlaySeSpacial(SONG_BC, x+8);

    CameraMoveWatchPosition(proc, proc->x, 31);
}

void StartArrowTrapAnim(ProcPtr parent, int x)
{
    struct Proc * proc;

    proc = SpawnProcLocking(ProcScr_ArrowTrapAnim, parent);
    proc->x = x;
}

static void func_fe6_0801D8B8(struct ShowMapChangeProc * proc)
{
    struct MapChangeInfo const * info = GetMapChange(proc->map_change_id);

    int x = info->x + info->width/2;
    int y = info->y + info->height/2;

    CameraMoveWatchPosition(proc, x, y);

    proc->sndx = x;
}

static void func_fe6_0801D8E4(struct ShowMapChangeProc * proc)
{
    int x, song;

    RenderMapForFade();

    func_fe6_080188F4();
    RenderMap();

    StartMapFade(FALSE);

    if (proc->alt_song)
        song = SONG_BE;
    else
        song = SONG_BD;

    PlaySeSpacial(song, proc->sndx /* *16 + 8 */ - gBmSt.camera.x);
}

void StartTimedMapChangeAnim(ProcPtr parent, int unused, int trapid)
{
    struct ShowMapChangeProc * proc;
    struct Trap * trap;

    proc = SpawnProcLocking(ProcScr_MapChange_085C5B50, parent);

    trap = GetTrap(trapid);
    trap->extra ^= 1;

    if (trap->extra != 0)
        proc->map_change_id = trap->y;
    else
        proc->map_change_id = trap->x;

    proc->alt_song = trap->extra;
}

static void PikeTrapSpriteAnim_Init(struct Proc * proc)
{
    int x, y, oam2;

    Decompress(Img_PikeTrap, (u8 *) OBJ_VRAM0 + CHR_SIZE*OBCHR_TRAPFX);
    ApplyPalette(Pal_PikeTrap, 0x10 + OBPAL_TRAPFX);

    x = proc->x*16 + 8 - gBmSt.camera.x;
    y = proc->y*16 + 8 - gBmSt.camera.y;
    oam2 = OAM2_CHR(OBCHR_TRAPFX) | OAM2_PAL(OBPAL_TRAPFX) | OAM2_LAYER(1);

    StartSpriteAnimProc(SpriteAnim_PikeTrap, x, y, oam2, proc->unk4A, 0);
    PlaySeSpacial(SONG_BB, x + 8);
}

void StartPikeTrapAnim(ProcPtr parent, int x, int y, int facing)
{
    struct Proc * proc;

    proc = SpawnProcLocking(ProcScr_PikeTrapAnim, parent);

    proc->x = x;
    proc->y = y;

    switch (facing)
    {

    case FACING_RIGHT:
        proc->unk4A = 0;
        break;

    case FACING_LEFT:
        proc->unk4A = 1;
        break;

    case FACING_UP:
        proc->unk4A = 2;
        break;

    }
}

static void func_fe6_0801DA1C(struct Proc * proc)
{
    proc->unk4C = 120; // 2 seconds
}

static void func_fe6_0801DA24(struct Proc * proc)
{
    proc->unk4C--;

    if (proc->unk4C < 0 || (gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B)))
        Proc_Break(proc);
}

void func_fe6_0801DA54(ProcPtr parent, int icon, char const * str)
{
    int x, len = GetStringTextLen(str);

    if (icon >= 0)
        len += 16;

    len += 24;

    x = (DISPLAY_WIDTH - len) / 16;

    PutUiWindowFrame(x, 8, len / 8, 4, UI_WINDOW_REGULAR);

    if (icon >= 0)
    {
        InitIcons();
        ApplyIconPalettes(BGPAL_ICONS);

        PutIcon(gBg0Tm + TM_OFFSET(1 + x, 9), icon, TILEREF(0, BGPAL_ICONS));
        x += 2;
    }

    ResetTextFont();
    PutDrawText(NULL, gBg0Tm + TM_OFFSET(1 + x, 9), TEXT_COLOR_SYSTEM_WHITE, 0, 20, str);

    SpawnProcLocking(ProcScr_Unk_085C5BA0, parent);
}

static void ChapterIntro_Bg3Scroll_Loop(ProcPtr proc)
{
    int offset = (GetGameTime()/2) % 0x100;

    SetBgOffset(3, offset, offset);
}

static void ChapterIntro_KeyListen_Init(struct Proc * proc)
{
    struct Proc * parent = proc->proc_parent;

    parent->unk50 = 0;
    proc->unk50 = 0;
}

static void ChapterIntro_KeyListen_Loop(struct Proc * proc)
{
    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B | KEY_BUTTON_START))
        proc->unk50 = 1;

    if (proc->unk50 != 0)
    {
        struct Proc * parent = proc->proc_parent;

        if (parent->unk50)
        {
            Proc_Goto(parent, parent->unk50);
            Proc_End(proc);
        }
    }
}

void PutChapterIntroMotif(void)
{
    int ix, iy;
    int tile = 0;

    TmFill(gBg2Tm, 0);

    Decompress(Tm_ChapterIntroMotif, gChapterIntroMotifTmBuf);

    for (iy = 0; iy < 18; ++iy)
        for (ix = 0; ix < 24; ++ix)
            gBg2Tm[TM_OFFSET(3 + ix, 1 + iy)] = TILEREF(1 + gChapterIntroMotifTmBuf[tile++], BGPAL_CHAPTERINTRO_MOTIF);
}

void PutScreenFogEffect(void)
{
    int ix, iy;

    int tilerefA = TILEREF(0x3FF & (BGCHR_CHAPTERINTRO_FOG+0x00), BGPAL_CHAPTERINTRO_FOG);
    int tilerefB = TILEREF(0x3FF & (BGCHR_CHAPTERINTRO_FOG+0x10), BGPAL_CHAPTERINTRO_FOG);

    for (iy = 0; iy < 8; ++iy)
    {
        for (ix = 0; ix < 16; ++ix)
        {
            gBg3Tm[TM_OFFSET(0x00+ix, iy+0x00)] = tilerefA;
            gBg3Tm[TM_OFFSET(0x10+ix, iy+0x00)] = tilerefA;
            gBg3Tm[TM_OFFSET(0x00+ix, iy+0x10)] = tilerefA;
            gBg3Tm[TM_OFFSET(0x10+ix, iy+0x10)] = tilerefA;

            gBg3Tm[TM_OFFSET(0x00+ix, iy+0x08)] = tilerefB;
            gBg3Tm[TM_OFFSET(0x10+ix, iy+0x08)] = tilerefB;
            gBg3Tm[TM_OFFSET(0x00+ix, iy+0x18)] = tilerefB;
            gBg3Tm[TM_OFFSET(0x10+ix, iy+0x18)] = tilerefB;

            tilerefA += 1;
            tilerefB += 1;
        }

        tilerefA += 0x10;
        tilerefB += 0x10;
    }
}

void PutScreenFogEffectOverlayed(void)
{
    int ix, iy;

    int tilerefA = TILEREF(0x3FF & (BGCHR_CHAPTERINTRO_FOG+0x00), BGPAL_CHAPTERINTRO_FOG);
    int tilerefB = TILEREF(0x3FF & (BGCHR_CHAPTERINTRO_FOG+0x10), BGPAL_CHAPTERINTRO_FOG);

    for (iy = 0; iy < 8; ++iy)
    {
        for (ix = 0; ix < 16; ++ix)
        {
            gBg2Tm[TM_OFFSET(0x0F-ix, iy+0x00)] = tilerefA + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(0x1F-ix, iy+0x00)] = tilerefA + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(0x0F-ix, iy+0x10)] = tilerefA + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(0x1F-ix, iy+0x10)] = tilerefA + TILE_HFLIP;

            gBg2Tm[TM_OFFSET(0x0F-ix, iy+0x08)] = tilerefB + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(0x1F-ix, iy+0x08)] = tilerefB + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(0x0F-ix, iy+0x18)] = tilerefB + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(0x1F-ix, iy+0x18)] = tilerefB + TILE_HFLIP;

            tilerefA += 1;
            tilerefB += 1;
        }

        tilerefA += 0x10;
        tilerefB += 0x10;
    }
}

static void ChapterIntro_Init(struct Proc * proc)
{
    InitBmBgLayers();

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(2, 0, 0);
    SetBgOffset(3, 0, 0);

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    TmFill(gBg2Tm, 0);
    TmFill(gBg3Tm, 0);

    SetBgChrOffset(2, CHR_SIZE*BGCHR_CHAPTERINTRO_MOTIF);

    SetWinEnable(1, 0, 0);

    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(0, 0, 1, 1, 1);

    gDispIo.win_ct.win0_enable_blend = 1;
    gDispIo.win_ct.wout_enable_blend = 1;

    SetWin0Box(0, 0, 0, 0);

    PutChapterTitlePalettle(8, BGPAL_CHAPTERINTRO_0);
    PutChapterTitlePalettle(0, BGPAL_CHAPTERINTRO_1);

    PutChapterTitleBG2(BGCHR_CHAPTERINTRO_80);

    PutChapterTitleGfx(BGCHR_CHAPTERINTRO_100, GetChapterTitleExtra(&gPlaySt));

    PutChapterTitleBgDefaultTSA(gBg1Tm + TM_OFFSET(0, 8), BGPAL_CHAPTERINTRO_0);
    PutChapterTitleTextTSA(gBg0Tm + TM_OFFSET(3, 9), BGPAL_CHAPTERINTRO_1);

    ColorFadeInit();
    ColFadeStep(BGPAL_CHAPTERINTRO_0, 2, 0x40, -1);
    ColorFadeTick();

    EnablePalSync();

    Decompress(Img_ChapterIntroFog, (u8 *) VRAM + CHR_SIZE*BGCHR_CHAPTERINTRO_FOG);
    ApplyPalette(Pal_ChapterIntroFog, BGPAL_CHAPTERINTRO_FOG);

    Decompress(Img_ChapterIntroMotif, (u8 *) VRAM + CHR_SIZE*(BGCHR_CHAPTERINTRO_MOTIF+1));
    ApplyPalette(Pal_ChapterIntroMotif, BGPAL_CHAPTERINTRO_MOTIF);

    SetBlankChr(BGCHR_CHAPTERINTRO_MOTIF);

    gPal[0] = 0;

    PutChapterIntroMotif();
    PutScreenFogEffect();

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT + BG2_SYNC_BIT + BG3_SYNC_BIT);
}

static void ChapterIntro_BeginFadeIn(struct Proc * proc)
{
    SetDispEnable(0, 0, 0, 1, 1);
    SetBlendTargetA(0, 0, 0, 1, 1);

    proc->unk4C = 12;

    FadeBgmOut(2);
}

static void ChapterIntro_LoopFadeIn(struct Proc * proc)
{
    SetBlendDarken(proc->unk4C);

    if (proc->unk50 == 3 || (GetGameTime() % 4) == 0)
    {
        proc->unk4C--;

        if (proc->unk4C < 0)
            Proc_Break(proc);
    }
}

static void ChapterIntro_BeginMotifFadeIn(struct Proc * proc)
{
    SetDispEnable(0, 0, 1, 1, 1);

    proc->unk4C = 0x10;

    SetBlendTargetA(0, 0, 1, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 0);

    PlaySe(SONG_90);
}

static void ChapterIntro_LoopMotifFadeIn(struct Proc * proc)
{
    SetBlendAlpha(0x10 - proc->unk4C, 0x10);

    if (proc->unk50 == 3 || (GetGameTime() % 4) == 0)
    {
        proc->unk4C--;

        if (proc->unk4C < 0)
            Proc_Break(proc);
    }
}

static void ChapterIntro_BeginHOpenText(struct Proc * proc)
{
    proc->unk4C = 0;

    SetDispEnable(1, 1, 1, 1, 1);
    PlaySe(SONG_91);
}

static void ChapterIntro_LoopHOpenText(struct Proc * proc)
{
    int val = Interpolate(INTERPOLATE_RSQUARE, 0, DISPLAY_WIDTH/2, proc->unk4C, 0x10);
    SetWin0Box(DISPLAY_WIDTH/2 - val, 78, DISPLAY_WIDTH/2 + val, 81);

    proc->unk4C++;

    if (proc->unk4C > 0x10)
        Proc_Break(proc);
}

static void ChapterIntro_BeginVOpenText(struct Proc * proc)
{
    proc->unk4C = 1;
}

static void ChapterIntro_LoopVOpenText(struct Proc * proc)
{
    int val = Interpolate(INTERPOLATE_LINEAR, 0, 0x10, proc->unk4C, 3);
    SetWin0Box(0, DISPLAY_HEIGHT/2 - val, DISPLAY_WIDTH, DISPLAY_HEIGHT/2 + val);

    proc->unk4C++;

    if (proc->unk4C > 3)
        Proc_Break(proc);
}

static void ChapterIntro_Begin_0801E1A0(struct Proc * proc)
{
    proc->unk4C = 0x20;

    SetBlendAlpha(0x10, 0x10);

    SetBlendTargetA(0, 1, 1, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 1);
}

static void ChapterIntro_Loop_0801E1F8(struct Proc * proc)
{
    ColorFadeTick();
    EnablePalSync();

    proc->unk4C--;

    if (proc->unk4C < 0)
        Proc_Break(proc);
}

static void ChapterIntro_Begin_0801E220(struct Proc * proc)
{
    proc->unk4C = 13;

    ColorFadeInit();
    ColFadeDirect(gPal + 0x10*BGPAL_CHAPTERINTRO_FOG, BGPAL_CHAPTERINTRO_FOG, 2, -1);
}

static void ChapterIntro_Loop_0801E244(struct Proc * proc)
{
    if ((GetGameTime() % 4) == 0)
    {
        ColorFadeTick();
        EnablePalSync();

        proc->unk4C--;

        if (proc->unk4C < 0)
        {
            SetDispEnable(1, 1, 0, 0, 0);
            SetBgChrOffset(2, 0);
            SetBackdropColor(0);
            Proc_Break(proc);
        }
    }
}

static void ChapterIntro_0801E2B0(struct Proc * proc)
{
    gBmSt.camera.y = 40*16;
}

static void ChapterIntro_InitMapDisplay(struct Proc * proc)
{
    int val;

    SetDispEnable(1, 1, 1, 1, 1);

    SetBlendAlpha(0x10, 0);

    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 1); SetBlendBackdropB(1);

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    DisableTilesetPalAnim();

    ApplyChapterMapGraphics(gPlaySt.chapter);
    ApplyUnitSpritePalettes();
    ApplySystemObjectsGraphics();

    val = GetChapterInfo(gPlaySt.chapter)->unk_0F;
    val = GetCameraCenteredX(val*16);
    val = (val + 15) & 0x1F0;
    gBmSt.camera.x = val;

    val = GetChapterInfo(gPlaySt.chapter)->unk_10;
    val = GetCameraCenteredY(val*16);
    val = (val + 15) & 0x3F0;
    gBmSt.camera.y = val;

    RefreshEntityMaps();
    RenderMap();
}

static void ChapterIntro_BeginFadeToMap(struct Proc * proc)
{
    ColorFadeInit();

    ColFadeDirect(gPal + 0x10*BGPAL_TILESET, 6, 10, +1);
    ColFadeDirect(gPal + 0x10*(0x10+OBPAL_10), 0x10+OBPAL_10, 6, +1);
    ColFadeDirect(gPal + 0x10*(0x10+OBPAL_SYSTEM_OBJECTS), 0x10+OBPAL_SYSTEM_OBJECTS, 2, +1);
    ColFadeDirect(gPal + 0x10*(0x10+OBPAL_7), 0x10+OBPAL_7, 1, +1);

    ColorFadeTick();
    EnablePalSync();

    proc->unk4C = 30;

    if (GetChapterInfo(gPlaySt.chapter)->weather == WEATHER_FLAMES)
        ApplyFlamesWeatherGradient();
}

static void ChapterIntro_LoopFadeToMap(struct Proc * proc)
{
    if ((GetGameTime() % 2) == 0)
    {
        int val;

        ColorFadeTick();

        if (GetChapterInfo(gPlaySt.chapter)->weather == WEATHER_FLAMES)
            ApplyFlamesWeatherGradient();

        EnablePalSync();

        val = (proc->unk4C+7)/8;
        SetBlendAlpha(12 + val, 4 - val);

        proc->unk4C--;

        if (proc->unk4C == 24)
            StartBgm(GetChapterInfo(gPlaySt.chapter)->song_opening_bgm, NULL);

        if (proc->unk4C < 0)
        {
            EnableTilesetPalAnim();
            Proc_Break(proc);
        }
    }
}

static void ChapterIntro_BeginCloseText(struct Proc * proc)
{
    proc->unk4C = 0x10;
}

static void ChapterIntro_LoopCloseText(struct Proc * proc)
{
    SetWin0Box(0, DISPLAY_HEIGHT/2 - proc->unk4C, DISPLAY_WIDTH, DISPLAY_HEIGHT/2 + proc->unk4C);

    proc->unk4C--;

    if (proc->unk4C < 0)
        Proc_Break(proc);
}

static void ChapterIntro_BeginFastCloseText(struct Proc * proc)
{
    proc->unk4C = 8;
}

static void ChapterIntro_LoopFastCloseText(struct Proc * proc)
{
    SetWin0Box(0, DISPLAY_HEIGHT/2 - proc->unk4C, DISPLAY_WIDTH, DISPLAY_HEIGHT/2 + proc->unk4C);

    proc->unk4C -= 2;

    if (proc->unk4C < 0)
        Proc_Break(proc);
}

static void ChapterIntro_BeginFadeOut(struct Proc * proc)
{
    ColorFadeInit();
    ColFadeDirect(gPal, 0, 6, -2);

    proc->unk4C = 15;

    EarthQuakeSoundFadeOut(1);
}

static void ChapterIntro_LoopFadeOut(struct Proc * proc)
{
    ColorFadeTick();
    EnablePalSync();

    proc->unk4C--;

    if (proc->unk4C < 0)
    {
        SetDispEnable(0, 0, 0, 0, 0);

        SetBgChrOffset(2, 0);

        Proc_Break(proc);
    }
}

static void ChapterIntro_BeginFastFadeToMap(struct Proc * proc)
{
    ClearUi();

    ColorFadeInit();

    ColFadeDirect(gPal + 0x10*BGPAL_TILESET, 6, 10, +2);
    ColFadeDirect(gPal + 0x10*(0x10+OBPAL_10), 0x10+OBPAL_10, 6, +2);
    ColFadeDirect(gPal + 0x10*(0x10+OBPAL_SYSTEM_OBJECTS), 0x10+OBPAL_SYSTEM_OBJECTS, 2, +2);
    ColFadeDirect(gPal + 0x10*(0x10+OBPAL_7), 0x10+OBPAL_7, 1, +2);

    ColorFadeTick();
    EnablePalSync();

    proc->unk4C = 14;

    StartBgm(GetChapterInfo(gPlaySt.chapter)->song_opening_bgm, NULL);
}

static void ChapterIntro_LoopFastFadeToMap(struct Proc * proc)
{
    ColorFadeTick();

    if (GetChapterInfo(gPlaySt.chapter)->weather == WEATHER_FLAMES)
        ApplyFlamesWeatherGradient();

    EnablePalSync();

    proc->unk4C--;

    if (proc->unk4C < 0)
    {
        EnableTilesetPalAnim();

        Proc_Break(proc);
    }
}

static void ChapterIntro_SetSkipTarget(short arg, struct Proc * proc)
{
    proc->unk50 = arg;
}

static void GameOverScreen_RandomScroll_Init(struct Proc * proc)
{
    proc->unk34 = +46;
    proc->unk38 = -90;
    proc->unk3C = -16;
    proc->unk40 = -53;

    proc->timer1 = 1234;
    proc->timer2 = 5678;
    proc->unk68 = 6346;
    proc->unk6A = 8536;
}

static void GameOverScreen_RandomScroll_Loop(struct Proc * proc)
{
    proc->timer1 += proc->unk34;
    proc->timer2 += proc->unk38;
    proc->unk68 += proc->unk3C;
    proc->unk6A += proc->unk40;

    SetBgOffset(2, -proc->timer1 >> 8, -proc->timer2 >> 8);
    SetBgOffset(3, -proc->unk68 >> 8, -proc->unk6A >> 8);
}

static void GameOverScreenHBlank(void)
{
    u16 val = REG_VCOUNT + 1;

    if (val > DISPLAY_HEIGHT)
        val = 0;

    if (val > DISPLAY_HEIGHT/2)
        val = DISPLAY_HEIGHT - val;

    val = val / 3;

    if (val > 0x10)
        val = 0x10;

    REG_BLDCA = val;
    REG_BLDCB = val;
}

static void GameOverScreen_Init(struct Proc * proc)
{
    int i;

    LockBmDisplay();

    StartBgm(SONG_37, NULL);

    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg1_ct.priority = 1;
    gDispIo.bg2_ct.priority = 2;
    gDispIo.bg3_ct.priority = 3;

    SetBgChrOffset(2, 0);
    SetBgChrOffset(3, 0);

    Decompress(Img_GameOverText, (u8 *) VRAM + CHR_SIZE*BGCHR_GAMEOVER_TEXT);
    ApplyPalette(Pal_Unk_0830D95C, BGPAL_GAMEOVER_4);
    Decompress(Img_ChapterIntroFog, (u8 *) VRAM + CHR_SIZE*BGCHR_GAMEOVER_100);
    ApplyPalette(Pal_GameOverText, BGPAL_GAMEOVER_TEXT);

    ClearUi();

    TmApplyTsa(gBg0Tm + TM_OFFSET(7, 9), Tsa_Unk_0830D97C, TILEREF(BGCHR_GAMEOVER_TEXT, BGPAL_GAMEOVER_TEXT));

    PutScreenFogEffectOverlayed();
    PutScreenFogEffect();

    EnableBgSync(BG2_SYNC_BIT + BG3_SYNC_BIT);

    SetOnHBlankA(GameOverScreenHBlank);

    SetBlendAlpha(14, 14);

    SetBlendTargetA(0, 0, 1, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 0);

    ColorFadeInit();
    ColFadeDirect(gPal + 0x10*BGPAL_GAMEOVER_TEXT, BGPAL_GAMEOVER_TEXT, 1, +1);
    ColFadeDirect(gPal + 0x10*BGPAL_GAMEOVER_4, BGPAL_GAMEOVER_4, 1, +1);

    proc->unk4C = 21;

    for (i = 0; i < 10; ++i)
        ColorFadeTick();

    EnablePalSync();
}

static void GameOverScreen_LoopFadeIn(struct Proc * proc)
{
    if ((GetGameTime() % 8) == 0)
    {
        ColorFadeTick();
        EnablePalSync();

        proc->unk4C--;

        if (proc->unk4C < 0)
            Proc_Break(proc);
    }
}

static void GameOverScreen_BeginIdle(struct Proc * proc)
{
    proc->unk4E = 1500;
}

static void GameOverScreen_LoopIdle(struct Proc * proc)
{
    proc->unk4E--;

    if (proc->unk4E < 0)
        Proc_Goto(proc, 99);

    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B | KEY_BUTTON_START))
        Proc_Goto(proc, 99);
}

static void GameOverScreen_BeginFadeOut(struct Proc * proc)
{
    ColorFadeInit();
    ColFadeDirect(gPal + 0x10*BGPAL_GAMEOVER_TEXT, BGPAL_GAMEOVER_TEXT, 1, -1);
    ColFadeDirect(gPal + 0x10*BGPAL_GAMEOVER_4, BGPAL_GAMEOVER_4, 1, -1);

    FadeBgmOut(4);
}

static void GameOverScreen_LoopFadeOut(struct Proc * proc)
{
    ColorFadeTick();
    EnablePalSync();

    proc->unk4C++;

    if (proc->unk4C == 0x20)
        Proc_Break(proc);
}

static void GameOverScreen_End(struct Proc * proc)
{
    SetOnHBlankA(NULL);
    SetOnHBlankB(NULL);

    SetDispEnable(0, 0, 0, 0, 0);
    SetBackdropColor(0);
}

void StartGameOverScreen(ProcPtr parent)
{
    if (parent)
        SpawnProcLocking(ProcScr_GameOverScreen, parent);
    else
        SpawnProc(ProcScr_GameOverScreen, PROC_TREE_3);
}
