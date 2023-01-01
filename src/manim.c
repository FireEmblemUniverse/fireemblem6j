#include "common.h"

#include "hardware.h"
#include "move.h"
#include "oam.h"
#include "armfunc.h"
#include "sound.h"
#include "text.h"
#include "event.h"
#include "msg.h"
#include "util.h"
#include "item.h"
#include "unit.h"
#include "debugmenu.h"
#include "faction.h"
#include "unitsprite.h"
#include "battle.h"
#include "ui.h"
#include "mu.h"
#include "eventinfo.h"

#include "constants/iids.h"
#include "constants/pids.h"
#include "constants/jids.h"
#include "constants/videoalloc_global.h"
#include "constants/songs.h"
#include "constants/terrains.h"

struct MapAnimSt EWRAM_DATA gMapAnimSt = { { 0 } };

// GARBAGE START
// TODO: organize

extern u16 const gUnk_082DC840[]; // pal blue
extern u16 const gUnk_082DC860[]; // pal red
extern u16 const gUnk_082DC880[]; // pal green
extern u16 const gUnk_082DC8A0[]; // pal purple
extern u8 const gUnk_082DC8C0[]; // tsa
extern u8 const gUnk_082DC8EC[]; // tsa
extern u8 const gUnk_082DC918[]; // tsa
extern u8 const gUnk_08113584[]; // img exp bar a
extern u8 const gUnk_08113884[]; // img exp bar b
extern u8 const gUnk_08113B84[]; // img exp bar c
extern u16 const gUnk_08113D50[]; // pal exp bar
extern u8 const gUnk_082DC5B0[]; // tsa exp bar
extern u8 const gUnk_082DCAE4[]; // img
extern u16 const gUnk_082DCD70[]; // pal
extern u16 const gUnk_082A9228[]; // sprite anim
extern u8 const gUnk_082DB1C0[]; // img
extern u16 const gUnk_082DB2B0[]; // sprite anim
extern u8 const gUnk_082DB418[]; // img
extern u16 const gUnk_082DB55C[]; // sprite anim
extern u8 const gUnk_082DCEF4[]; // img
extern u16 const gUnk_082DD248[]; // pal
extern u16 const gUnk_082A9190[]; // sprite anim
extern u8 const gUnk_082DE994[]; // img
extern u16 const gUnk_082DEFBC[]; // pal/colors
extern u8 const gUnk_082DEFFC[]; // img
extern u16 const gUnk_082DE354[]; // tm
extern u8 const gUnk_082DD268[]; // img
extern u16 const gUnk_082DD4C8[]; // pal
extern u16 const gUnk_082DD4E8[]; // tm
extern u8 const gUnk_082DF3D8[]; // img
extern u16 const gUnk_082DF690[]; // pal
extern u16 const gUnk_082A8448[]; // sprite anim
extern u8 const gUnk_082E0E14[]; // img
extern u16 const gUnk_082E10EC[]; // pal
extern u16 const gUnk_082E110C[]; // sprite anim
extern u8 const gUnk_082DFAD4[]; // img
extern u16 const gUnk_081B4274[]; // pal
extern u8 const gUnk_082E07A8[]; // ???
extern u8 const gUnk_082DF868[]; // ??? ^
extern u8 const gUnk_08307928[]; // ???

enum { MAX_MANIM_DEBUG_HITS = 5 };

enum
{
    MANIM_DEBUG_PARAM_PID,
    MANIM_DEBUG_PARAM_X,
    MANIM_DEBUG_PARAM_Y,
    MANIM_DEBUG_PARAM_JID,
    MANIM_DEBUG_PARAM_IID,
    MANIM_DEBUG_PARAM_HITS,
    MAX_MANIM_DEBUG_PARAM = MANIM_DEBUG_PARAM_HITS + MAX_MANIM_DEBUG_HITS,
};

enum
{
    MANIM_DEBUG_HIT_KIND_NONE,
    MANIM_DEBUG_HIT_KIND_REGULAR,
    MANIM_DEBUG_HIT_KIND_REGULAR_DEVIL,
    MANIM_DEBUG_HIT_KIND_REGULAR_HPSTEAL,
    MANIM_DEBUG_HIT_KIND_REGULAR_POISON,
    MANIM_DEBUG_HIT_KIND_CRIT,
    MANIM_DEBUG_HIT_KIND_CRIT_DEVIL,
    MANIM_DEBUG_HIT_KIND_CRIT_HPSTEAL,
    MANIM_DEBUG_HIT_KIND_CRIT_POISON,
    MANIM_DEBUG_HIT_KIND_MISS,

    MAX_MANIM_DEBUG_HIT_KIND,
};

struct ManimDebugStEnt
{
    /* 00 */ short data[MAX_MANIM_DEBUG_PARAM];
    /* 14 */ struct Text text[MAX_MANIM_DEBUG_PARAM];
};

struct ManimDebugSt
{
    /* 00 */ u8 unk_00[8]; // unused?
    /* 08 */ struct ManimDebugStEnt ent[2];
};

struct ManimDebugParamInfo
{
    /* 00 */ u8 text_width;
    /* 01 */ i8 param_up;
    /* 02 */ i8 param_down;
    /* 03 */ i8 param_left;
    /* 04 */ i8 param_right;
    /* 05 */ u8 min;
    /* 06 */ u8 max;
};

struct ManimEffectProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 unk_40;
    /* 42 */ u16 unk_42;
    /* 44 */ u16 unk_44;
    /* 44 */ u8 pad_46[0x48 - 0x46];
    /* 48 */ short unk_48;
    /* 4A */ short unk_4A;
    /* 4C */ short unk_4C;
    /* 4E */ /* pad */
    /* 50 */ void const * img;
    /* 54 */ void const * pal;
    /* 58 */ u16 unk_58;
    /* 5A */ u8 pad_5A[0x64 - 0x5A];
    /* 64 */ short unk_64;
};

extern struct ProcScr CONST_DATA ProcScr_Unk_0866510C[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0866512C[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0866514C[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08665194[];

#define UNIT_SCREEN_TILE_X(unit) (((unit)->x - (gBmSt.camera.x >> 4)) << 1)
#define UNIT_SCREEN_TILE_Y(unit) (((unit)->y - (gBmSt.camera.y >> 4)) << 1)

void func_fe6_08063CF4(struct GenericProc * proc);
void func_fe6_08063EF0(struct GenericProc * proc);
void func_fe6_080640D0(struct GenericProc * proc);
void func_fe6_0806495C(struct GenericProc * proc);

void func_fe6_08064B20(struct ManimEffectProc * proc);
void func_fe6_08064BEC(struct ManimEffectProc * proc);
void func_fe6_08064CC0(struct ManimEffectProc * proc);
void func_fe6_08064DF8(struct ManimEffectProc * proc);
void func_fe6_08064F4C(struct ManimEffectProc * proc);
void func_fe6_08064FD0(struct ManimEffectProc * proc);
void func_fe6_08065AF8(ProcPtr proc);

enum
{
    MANIM_FACING_OPPONENT,
    MANIM_FACING_DEFAULT,
    MANIM_FACING_UNKNOWN,
};

struct MAnimExpBarProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad_29[0x64 - 0x29];
    /* 64 */ short exp_from;
    /* 66 */ short exp_to;
    /* 68 */ short actor_id;
    /* 6A */ short unk_6A;
};

struct MAnimInfoWindowProc
{
    /* 00 */ PROC_HEADER;

    /* 2A */ i16 open_transition_value;
    /* 2C */ u16 unk_2C;
    /* 2E */ u8 x_tile;
    /* 2F */ u8 y_tile;
    /* 30 */ ProcPtr main_proc;
};

void func_fe6_08062D64(ProcPtr proc);
void func_fe6_08062D80(struct MAnimInfoWindowProc * proc);
void func_fe6_08062E94(struct MAnimInfoWindowProc * proc);
void func_fe6_08062FE8(struct MAnimInfoWindowProc * proc, int actor_id);
void func_fe6_08063120(struct MAnimInfoWindowProc * proc, int actor_id, int x_offset);
void func_fe6_080632C4(struct MAnimInfoWindowProc * proc);
void func_fe6_080633B0(struct MAnimInfoWindowProc * proc);
void func_fe6_08063504(struct MAnimExpBarProc * proc);
void func_fe6_080635B8(struct MAnimExpBarProc * proc);
void func_fe6_080635E0(struct MAnimExpBarProc * proc);
void func_fe6_0806367C(struct MAnimExpBarProc * proc);
void func_fe6_0806376C(struct MAnimExpBarProc * proc);
void func_fe6_08063848(struct MAnimExpBarProc * proc);

// GARBAGE END

struct ProcScr CONST_DATA ProcScr_Unk_08664C0C[] =
{
    PROC_CALL(LockGame),
    PROC_CALL(MA_MoveCameraOntoActor),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08061E14),
    PROC_SLEEP(15),
    PROC_START_CHILD_LOCKING((void *) 0x08665F04), // TODO
    PROC_SLEEP(1),
    PROC_GOTO_SCR(ProcScr_Unk_08664E4C),
};

struct ProcScr CONST_DATA ProcScr_Unk_08664C4C[] =
{
    PROC_CALL(LockGame),
    PROC_CALL(MA_MoveCameraOntoActor),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08061E14),
    PROC_SLEEP(15),
    PROC_START_CHILD_LOCKING((void *) 0x08665F54), // TODO
    PROC_SLEEP(1),
    PROC_GOTO_SCR(ProcScr_Unk_08664E4C),
};

struct ProcScr CONST_DATA ProcScr_Unk_08664C8C[] =
{
    PROC_CALL(LockGame),
    PROC_CALL(MA_MoveCamOntoTarget),
    PROC_SLEEP(2),
    PROC_CALL(MA_MoveCameraOntoActor),
    PROC_SLEEP(2),
    PROC_SLEEP(20),
    PROC_CALL(func_fe6_08068C84),
    PROC_CALL(func_fe6_08068E80),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068E80),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068E80),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068E80),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_0806210C),
    PROC_SLEEP(20),
    PROC_CALL(func_fe6_08068F04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068F04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068F04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068F04),
    PROC_SLEEP(20),
    PROC_GOTO_SCR(ProcScr_Unk_08664E4C),
};

struct ProcScr CONST_DATA ProcScr_Unk_08664D5C[] =
{
    PROC_CALL(LockGame),
    PROC_CALL(MA_MoveCameraOntoActor),
    PROC_SLEEP(2),
    PROC_SLEEP(20),
    PROC_CALL(func_fe6_08068ADC),
    PROC_SLEEP(90),
    PROC_CALL(func_fe6_08068C28),
    PROC_SLEEP(20),
    PROC_GOTO_SCR(ProcScr_Unk_08664E4C),
};

struct ProcScr CONST_DATA ProcScr_Unk_08664DA4[] =
{
    PROC_CALL(LockGame),
    PROC_CALL(func_fe6_0806199C),
    PROC_SLEEP(1),
    PROC_CALL(MA_MoveCameraOntoActor),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08061FD0),
    PROC_WHILE(IsEventRunning),
    PROC_SLEEP(5),
    PROC_CALL(func_fe6_080620D8),
    PROC_CALL(func_fe6_080622FC),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08061E14),
    PROC_SLEEP(15),
PROC_LABEL(0),
    PROC_REPEAT(func_fe6_08061AC8),
    PROC_CALL(func_fe6_08061B10),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08061B30),
    PROC_SLEEP(1),
    PROC_SLEEP(5),
    PROC_GOTO(0),
};

struct ProcScr CONST_DATA ProcScr_Unk_08664E4C[] =
{
    PROC_CALL(MA_DisplayDeathQuote),
    PROC_WHILE(IsEventRunning),
    PROC_CALL(MapAnimProc_DisplayDeathFade),
    PROC_WHILE_EXISTS(ProcScr_MuDeathFade),
    PROC_CALL(func_fe6_08062CF0),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08061838),
    PROC_SLEEP(0),
    PROC_CALL(MapAnimProc_DisplayExpBar),
    PROC_SLEEP(0),
    PROC_CALL(func_fe6_08061878),
    PROC_SLEEP(8),
    PROC_CALL(func_fe6_08061908),
    PROC_SLEEP(0),
    PROC_CALL(MA_MoveCameraOntoActor),
    PROC_SLEEP(2),
    PROC_CALL(UnlockGame),
    PROC_CALL(func_fe6_080619B0),
    PROC_END,
};

u16 CONST_DATA gUnk_08664EE4[] =
{
    4, 42,
    9, 47,
    9, 57,
    9, 67,
    9, 77,
    5, 87,
    0, 0,
};

int CONST_DATA gUnk_08664F00[] = { 5, 6 };

u8 const * CONST_DATA gUnk_08664F08[][2] = // tsa lut
{
    { gUnk_082DC8C0, gUnk_082DC8C0 },
    { gUnk_082DC8C0, gUnk_082DC8C0 },
    { gUnk_082DC8EC, gUnk_082DC918 },
};

struct ProcScr CONST_DATA ProcScr_MAnimInfoWindow[] =
{
    PROC_ONEND(func_fe6_08062D64),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_080632C4),
    PROC_CALL(func_fe6_08062D80),
    PROC_REPEAT(func_fe6_080633B0),
    PROC_REPEAT(func_fe6_08062E94),
    PROC_END,
};

u16 CONST_DATA gUnk_08664F58[] =
{
    6, BGCHR_MANIM_200 + 7,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    6, BGCHR_MANIM_200 + 24,
    0, // end
};

struct ProcScr CONST_DATA ProcScr_MAnimExpBar[] =
{
    PROC_ONEND(func_fe6_08062D64),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08063504),
    PROC_CALL(func_fe6_0806367C),
    PROC_REPEAT(func_fe6_0806376C),
    PROC_SLEEP(20),
    PROC_CALL(func_fe6_080635B8),
    PROC_SLEEP(2),
    PROC_REPEAT(func_fe6_080635E0),
    PROC_SLEEP(20),
    PROC_CALL(func_fe6_08062D64),
    PROC_SLEEP(8),
    PROC_CALL(func_fe6_08063848),
    PROC_SLEEP(1),
    PROC_END,
};

void func_fe6_08061838(ProcPtr proc)
{
    switch (gMapAnimSt.unk_62)
    {

    case 1:
        break;

    default:
        return;

    }

    StartPopup_08012178(gMapAnimSt.actor[1].bu->weapon, proc);
}

void func_fe6_08061878(ProcPtr proc)
{
    struct BattleUnit * bu = NULL;

    if (func_fe6_080618D4(&gBattleUnitA))
        bu = &gBattleUnitA;

    if (func_fe6_080618D4(&gBattleUnitB))
        bu = &gBattleUnitB;

    if (bu != NULL)
    {
        StartWeaponBrokePopup(bu->weapon_before, proc);
    }
}

bool func_fe6_080618D4(struct BattleUnit * bu)
{
    if (UNIT_FACTION(&bu->unit) == FACTION_BLUE)
        return DidBattleUnitBreakWeapon(bu);

    return FALSE;
}

void func_fe6_08061908(ProcPtr proc)
{
    struct BattleUnit * bu = NULL;

    if (func_fe6_08061964(&gBattleUnitA))
        bu = &gBattleUnitA;

    if (func_fe6_08061964(&gBattleUnitB))
        bu = &gBattleUnitB;

    if (bu != NULL)
    {
        StartWeaponLevelGainedPopup(bu->weapon_kind, proc);
    }
}

bool func_fe6_08061964(struct BattleUnit * bu)
{
    if (UNIT_FACTION(&bu->unit) == FACTION_BLUE)
        if (HasBattleUnitGainedWeaponLevel(bu))
            return TRUE;

    return FALSE;
}

void func_fe6_0806199C(ProcPtr proc)
{
    ResetText();
}

void func_fe6_080619B0(ProcPtr proc)
{
    ResetMuAnims();
    ResetTextFont();
    func_fe6_08062CF0();
    InitBmBgLayers();
    UnpackUiWindowFrameGraphics();
    ApplySystemObjectsGraphics();

    if (IsEventRunning())
        EndAllMus();
}

void func_fe6_080619E8(void)
{
    gMapAnimSt.attacker_actor = !!(gMapAnimSt.hit_it->info & BATTLE_HIT_INFO_ACTORB);
    gMapAnimSt.defender_actor = 1 - gMapAnimSt.attacker_actor;

    gMapAnimSt.hit_attributes = gMapAnimSt.hit_it->attributes;
    gMapAnimSt.hit_info = gMapAnimSt.hit_it->info;
    gMapAnimSt.hit_damage = gMapAnimSt.hit_it->damage;

    if (gMapAnimSt.main_actor_count == 1)
    {
        gMapAnimSt.attacker_actor = 0;
        gMapAnimSt.defender_actor = 0;
    }

    gMapAnimSt.hit_it++;
}

void func_fe6_08061AC8(ProcPtr proc)
{
    if (gMapAnimSt.hit_it->info & BATTLE_HIT_INFO_END)
    {
        Proc_Break(proc);
        Proc_GotoScript(proc, ProcScr_Unk_08664E4C);

        return;
    }

    func_fe6_080619E8();

    Proc_Break(proc);
}

void func_fe6_08061B10(ProcPtr proc)
{
    SpawnProcLocking(func_fe6_08068A48(), proc);
}

void func_fe6_08061B30(ProcPtr proc)
{
    if (gMapAnimSt.hit_attributes & BATTLE_HIT_ATTR_POISON)
    {
        func_fe6_08064B7C(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit);
        StartTemporaryLock(proc, 100);
    }
}

void MA_MoveCameraOntoActor(ProcPtr proc)
{
    CameraMoveWatchPosition(proc, gMapAnimSt.actor[0].unit->x, gMapAnimSt.actor[0].unit->y);
}

void MA_MoveCamOntoTarget(ProcPtr proc)
{
    if (gMapAnimSt.main_actor_count == 1)
        return;

    CameraMoveWatchPosition(proc, gMapAnimSt.actor[1].unit->x, gMapAnimSt.actor[1].unit->y);
}

void MA_DisplayDeathQuote(ProcPtr proc)
{
    int actor_id = -1;

    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        if (gMapAnimSt.actor[1].hp_cur == 0)
            actor_id = 1;

        // fallthrough

    case 1:
        if (gMapAnimSt.actor[0].hp_cur == 0)
            actor_id = 0;

        break;

    }

    if (actor_id != -1)
    {
        int pid = gMapAnimSt.actor[actor_id].unit->pinfo->id;

        if (CheckBattleDefeatTalk(pid))
        {
            func_fe6_08062CF0();
            StartBattleDefeatTalk(pid);
            DisableEventSkip();
        }
    }
}

void MapAnimProc_DisplayDeathFade(ProcPtr proc)
{
    int actor_id = -1;

    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        if (gMapAnimSt.actor[1].hp_cur == 0)
            actor_id = 1;

        // fallthrough

    case 1:
        if (gMapAnimSt.actor[0].hp_cur == 0)
            actor_id = 0;

        break;

    }

    if (actor_id != -1)
    {
        StartMuDeathFade(gMapAnimSt.actor[actor_id].mu);
    }
}

void MapAnimProc_DisplayExpBar(ProcPtr proc)
{
    struct MAnimExpBarProc * exp_bar_proc;
    int actor_id = -1;

    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        if (gMapAnimSt.actor[1].bu->exp_gain != 0)
            actor_id = 1;

        // fallthrough

    case 1:
        if (gMapAnimSt.actor[0].bu->exp_gain != 0)
            actor_id = 0;

        break;

    }

    if (actor_id >= 0)
    {
        exp_bar_proc = SpawnProcLocking(ProcScr_MAnimExpBar, proc);

        exp_bar_proc->exp_from = gMapAnimSt.actor[actor_id].bu->previous_exp;
        exp_bar_proc->exp_to = gMapAnimSt.actor[actor_id].bu->previous_exp + gMapAnimSt.actor[actor_id].bu->exp_gain;
        exp_bar_proc->actor_id = actor_id;
    }
}

void func_fe6_08061E14(ProcPtr proc)
{
    int y;

    SetBlendNone();

    switch (gMapAnimSt.unk_62)
    {

    case 1:
    case 2:
        return;

    default:
        break;

    }

    if (func_fe6_0805F7B4(gMapAnimSt.actor[0].bu->weapon_before) == 0)
        return;

    if (gMapAnimSt.main_actor_count == 1)
    {
        y = (gMapAnimSt.actor[0].unit->y << 4) - gBmSt.camera.y;

        if (y >= 112)
            y = y - 40;
        else
            y = y + 24;
    }
    else
    {
        int array[2];
        int i, actor_id;

        for (i = 0; i < gMapAnimSt.main_actor_count; ++i)
        {
            array[i] = (gMapAnimSt.actor[i].unit->y << 4) - gBmSt.camera.y;
        }

        if ((array[0] - array[1] >= 0)
            ? (array[0] - array[1] >= 80)
            : (array[1] - array[0] >= 80))
        {
            y = 64;
        }
        else
        {
            actor_id = array[0] > array[1] ? 0 : 1;

            if (array[actor_id] >= 112)
                y = array[1 - actor_id] - 40;
            else
                y = array[actor_id] + 24;
        }
    }

    MA_StartBattleInfoBox(15, y / 8, proc);
}

void func_fe6_08061FD0(ProcPtr proc)
{
    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        StartBattleTalk(
            gMapAnimSt.actor[0].unit->pinfo->id,
            gMapAnimSt.actor[1].unit->pinfo->id);

        break;

    default:
        break;

    }

    DisableEventSkip();
}

void func_fe6_08062018(int actor_id)
{
    switch (GetItemIid(gMapAnimSt.actor[actor_id].bu->weapon_before))
    {

    case IID_FIRESTONE:
        SetMuPal(gMapAnimSt.actor[actor_id].mu, OBJPAL_MANIM_SPECIALMU + actor_id);
        SetMuSpecialSprite(gMapAnimSt.actor[actor_id].mu, JID_FIREDRAGON, Pal_ManimFireDragonMu);
        break;

    case IID_DIVINESTONE:
        SetMuPal(gMapAnimSt.actor[actor_id].mu, OBJPAL_MANIM_SPECIALMU + actor_id);
        SetMuSpecialSprite(gMapAnimSt.actor[actor_id].mu, JID_DIVINEDRAGON, Pal_ManimDivineDragonMu);
        break;

    }
}

void func_fe6_080620D8(ProcPtr proc)
{
    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        func_fe6_08062018(1);
        // fallthrough

    case 1:
        func_fe6_08062018(0);
        // fallthrough

    }
}

void func_fe6_0806210C(void)
{
    PlaySe(SONG_A0);
}

void MA_InitActor(int actor_id, struct BattleUnit * bu, struct Unit * unit)
{
    if (bu == NULL)
        return;

    gMapAnimSt.actor[actor_id].unit = unit;
    gMapAnimSt.actor[actor_id].bu = bu;
    gMapAnimSt.actor[actor_id].mu = StartMu(unit);

    FreezeSpriteAnim(gMapAnimSt.actor[actor_id].mu->sprite_anim);

    if (bu->terrain == TERRAIN_WALL_1B)
        HideMu(gMapAnimSt.actor[actor_id].mu);
}

void MA_SetActorFacing(int actor_id, int opponent_actor_id, int manim_facing)
{
    int mu_facing;

    switch (manim_facing)
    {

    case MANIM_FACING_OPPONENT:
        mu_facing = GetFacingFromTo(
            gMapAnimSt.actor[actor_id].unit->x, gMapAnimSt.actor[actor_id].unit->y,
            gMapAnimSt.actor[opponent_actor_id].unit->x, gMapAnimSt.actor[opponent_actor_id].unit->y);

        SetMuFacing(gMapAnimSt.actor[actor_id].mu, mu_facing);
        break;

    case MANIM_FACING_DEFAULT:
        SetMuDefaultFacing(gMapAnimSt.actor[actor_id].mu);
        break;

    case MANIM_FACING_UNKNOWN:
        mu_facing = GetFacingFromTo(
            gMapAnimSt.actor[actor_id].unit->x, gMapAnimSt.actor[actor_id].unit->y, 0, 0);

        SetMuFacing(gMapAnimSt.actor[actor_id].mu, mu_facing);
        // break;

    }
}

void func_fe6_080622FC(void)
{
    int manim_facing = GetItemMaFacing(gMapAnimSt.actor[0].bu->weapon_before);

    MA_SortMuLayers();

    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        if (gBattleHits[0].attributes & BATTLE_HIT_ATTR_TATTACK)
        {
            // In triangle attacks, both partners face the opponent too
            MA_SetActorFacing(2, 1, manim_facing);
            MA_SetActorFacing(3, 1, manim_facing);
        }

        MA_SetActorFacing(1, 0, manim_facing);

        // fallthrough

    case 1:
        MA_SetActorFacing(0, 1, manim_facing);
        break;

    }
}

u8 const gManimMuSpriteLayerLut[] = { 10, 9, 8, 7 };

void MA_SortMuLayers(void)
{
    u8 array[4];
    u8 tmp;
    int i, j;
    int swap_requests;

    int actor_count = gMapAnimSt.main_actor_count;

    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        if (gBattleHits[0].attributes & BATTLE_HIT_ATTR_TATTACK)
        {
            actor_count += 2;
        }

        break;

    case 1:
        break;

    }

    // initialize index array

    for (i = 0; i < actor_count; ++i)
        array[i] = i;

    // sort index array
    // it uses selection sort

    for (i = 0; i < actor_count - 1; ++i)
    {
        for (j = i + 1; j < actor_count; ++j)
        {
            swap_requests = 0;

            if (gMapAnimSt.actor[array[i]].unit->y == gMapAnimSt.actor[array[j]].unit->y)
            {
                if (gMapAnimSt.actor[array[i]].unit->x >= gMapAnimSt.actor[array[j]].unit->x)
                    swap_requests++;
            }
            else if (gMapAnimSt.actor[array[i]].unit->y >= gMapAnimSt.actor[array[j]].unit->y)
            {
                swap_requests++;
            }

            if (swap_requests != 0)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }

    // apply

    for (i = 0; i < actor_count; ++i)
        gMapAnimSt.actor[array[i]].mu->sprite_anim->layer = gManimMuSpriteLayerLut[i];
}

void func_fe6_08062598(void)
{
    gBattleUnitA.weapon_before = IID_VULNERARY;

    gMapAnimSt.unk_62 = 0;
    gMapAnimSt.main_actor_count = 1;

    gMapAnimSt.hit_it = gBattleHits;
    func_fe6_080619E8();

    func_fe6_08062890(&gBattleUnitA, &gBattleUnitB, gBattleHits);
    SpawnProc(ProcScr_Unk_08664C0C, PROC_TREE_3);
}

void func_fe6_08062614(void)
{
    gBattleUnitA.weapon_before = IID_VULNERARY;

    gMapAnimSt.unk_62 = 0;
    gMapAnimSt.main_actor_count = 1;

    gMapAnimSt.hit_it = gBattleHits;
    func_fe6_080619E8();

    func_fe6_08062890(&gBattleUnitA, &gBattleUnitB, gBattleHits);
    SpawnProc(ProcScr_Unk_08664C4C, PROC_TREE_3);
}

void func_fe6_08062690(void)
{
    gBattleUnitA.weapon_before = IID_IRONSWORD;

    gMapAnimSt.unk_62 = 1;
    gMapAnimSt.main_actor_count = 2;

    gMapAnimSt.attacker_actor = 0;
    gMapAnimSt.defender_actor = 1;

    func_fe6_08062890(&gBattleUnitA, &gBattleUnitB, gBattleHits);
    SpawnProc(ProcScr_Unk_08664C8C, PROC_TREE_3);
}

void func_fe6_08062734(void)
{
    gBattleUnitA.weapon_before = IID_FORTIFYSTAFF;

    gMapAnimSt.unk_62 = 2;
    gMapAnimSt.main_actor_count = 1;

    gMapAnimSt.attacker_actor = 0;
    gMapAnimSt.defender_actor = 0;

    func_fe6_08062890(&gBattleUnitA, &gBattleUnitB, gBattleHits);
    SpawnProc(ProcScr_Unk_08664D5C, PROC_TREE_3);
}

void func_fe6_080627D0(void)
{
    if (gBattleSt.flags & BATTLE_FLAG_REFRESH)
    {
        func_fe6_08062734();
        return;
    }

    gMapAnimSt.unk_62 = 0;

    func_fe6_0806283C(&gBattleUnitA, &gBattleUnitB, gBattleHits);

    func_fe6_08062890(&gBattleUnitA, &gBattleUnitB, gBattleHits);
    SpawnProc(ProcScr_Unk_08664DA4, PROC_TREE_3);
}

void func_fe6_0806283C(struct BattleUnit * bu_a, struct BattleUnit * bu_b, struct BattleHit * battle_hits)
{
    gMapAnimSt.main_actor_count = func_fe6_0805F784(bu_a->weapon_before);
    gMapAnimSt.hit_it = battle_hits;
    gMapAnimSt.special_proc_scr = func_fe6_0805F7A4(bu_a->weapon_before);
}

void func_fe6_08062890(struct BattleUnit * bu_a, struct BattleUnit * bu_b, struct BattleHit * battle_hits)
{
    int i;

    MA_InitActor(0, bu_a, &bu_a->unit);

    if (gMapAnimSt.main_actor_count > 1)
    {
        HideUnitSprite(&gBattleUnitB.unit);
        MA_InitActor(1, bu_b, &bu_b->unit);
    }

    if (gBattleHits->attributes & BATTLE_HIT_ATTR_TATTACK)
    {
        MA_InitActor(2, bu_a, gBattleSt.ta_unit_a);
        MA_InitActor(3, bu_a, gBattleSt.ta_unit_b);

        HideUnitSprite(gBattleSt.ta_unit_a);
        HideUnitSprite(gBattleSt.ta_unit_b);
    }

    func_fe6_080622FC();

    for (i = 0; i < gMapAnimSt.main_actor_count; ++i)
    {
        gMapAnimSt.actor[i].hp_cur = gMapAnimSt.actor[i].bu->previous_hp;
        gMapAnimSt.actor[i].hp_max = GetUnitMaxHp(gMapAnimSt.actor[i].unit);
    }

    SetBlendNone();
}

int GetFacingFromTo(int x_from, int y_from, int x_to, int y_to)
{
    if (ABS(x_to - x_from) * 2 < ABS(y_to - y_from))
    {
        if (y_from < y_to)
            return FACING_DOWN;
        else
            return FACING_UP;
    }
    else
    {
        if (x_from < x_to)
            return FACING_RIGHT;
        else
            return FACING_LEFT;
    }
}

void func_fe6_08062A80(int chr)
{
    Decompress(Img_Unk_082DC618, (u8 *) VRAM + GetBgChrOffset(0) + ((chr & 0x3FF) << 5));
}

void func_fe6_08062AB4(u16 * tm, int num, int tileref, int len, u16 blank_tileref)
{
    char buf[8];
    int i, j;

    for (i = sizeof(buf)-1; i >= 0; --i)
    {
        buf[i] = '0' + num % 10;
        num = num / 10;

        if (num == 0)
        {
            for (j = i - 1; j >= 0; --j)
                buf[j] = ' ';

            break;
        }
    }

    func_fe6_08013E8C(tm, buf + sizeof(buf) - 1, tileref, len);

    for (i = len - 1; i > 0; --i)
    {
        if (buf[sizeof(buf) - 1 - i] != ' ')
            return;

        *(tm - i) = blank_tileref;
    }
}

void func_fe6_08062BA0(u8 const * src)
{
    func_fe6_08062A80(0x20);
    Decompress(src, (void *) (VRAM + CHR_SIZE * 42)); // TODO: CHR constant
    ApplyPalette(Pal_Unk_082E278C, 5);
}

void func_fe6_08062BD4(u16 * tm, int * arg_1, int pal, int arg_3, int chr)
{
    int tmp;

    if (*arg_1 > arg_3)
        tmp = arg_3;
    else
        tmp = *arg_1;

    *tm = TILEREF(chr + tmp, pal);
    *arg_1 += 1 - arg_3;

    if (*arg_1 < 0)
        *arg_1 = 0;
}

void func_fe6_08062C38(u16 * tm, int arg_1, int arg_2, int arg_3, u16 const * arg_4)
{
    int unk, count = 0;
    u16 const * it;

    for (it = arg_4; it[0] != 0; it += 2)
        count -= 1 - it[0];

    count += 1;

    if (arg_1 == arg_2)
        unk = count;
    else
        unk = ((count << 8) / arg_1 * arg_2) >> 8;

    if (unk == 0 && arg_2 > 0)
        unk++;

    for (it = arg_4; it[0] != 0; tm++, it += 2)
        func_fe6_08062BD4(tm, &unk, gUnk_08664F00[arg_3], it[0], it[1]);
}

void func_fe6_08062CF0(void)
{
    Proc_EndEach(ProcScr_MAnimInfoWindow);
}

void MA_StartBattleInfoBox(int arg0, int arg1, ProcPtr main_proc)
{
    struct MAnimInfoWindowProc * proc = SpawnProc(ProcScr_MAnimInfoWindow, PROC_TREE_3);

    proc->x_tile = arg0;
    proc->y_tile = arg1;
    proc->main_proc = main_proc;
}

void func_fe6_08062D64(ProcPtr proc)
{
    SetOnHBlankA(NULL);
    ClearUi();
}

void func_fe6_08062D80(struct MAnimInfoWindowProc * proc)
{
    int left_actor_id;

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);

    Decompress(
        gUnk_082DC6DC,
        ((void *) VRAM) + GetBgChrOffset(1) + BGCHR_MANIM_1 * CHR_SIZE);

    func_fe6_08062BA0(gUnk_082E25D4);

    switch (gMapAnimSt.main_actor_count)
    {

    case 1:
        func_fe6_08063120(proc, 0, -5);
        break;

    case 2:
        left_actor_id = 0;

        if (gMapAnimSt.actor[0].unit->x > gMapAnimSt.actor[1].unit->x)
            left_actor_id = 1;
        else if (UNIT_FACTION(gMapAnimSt.actor[0].unit) > UNIT_FACTION(gMapAnimSt.actor[1].unit))
            left_actor_id = 1;

        func_fe6_08063120(proc, left_actor_id, -10);
        func_fe6_08063120(proc, 1 - left_actor_id, 0);
        break;

    }

    func_fe6_08069C34();

    func_fe6_0806A0DC(
        gMapAnimSt.actor[0].unk_11 * 8,
        gMapAnimSt.actor[0].unk_11 * 8 + 0x20,
        PAL_COLOR(BGPAL_MANIM_1 + 0, 1),
        PAL_COLOR(BGPAL_MANIM_1 + 1, 1));
}

void func_fe6_08062E94(struct MAnimInfoWindowProc * proc)
{
    int i;
    u16 val;
    bool updated = FALSE;

    for (i = 0; i < gMapAnimSt.main_actor_count; ++i)
    {
        val = gMapAnimSt.actor[i].unk_0E;

        if (val > (gMapAnimSt.actor[i].hp_cur << 4))
            val = val - 16;

        if (val < (gMapAnimSt.actor[i].hp_cur << 4))
        {
            val = val + 4;

            if (val % 16 == 0)
                PlaySe(SONG_75);
        }

        if (val != gMapAnimSt.actor[i].unk_0E)
        {
            gMapAnimSt.actor[i].unk_0E = val;
            func_fe6_08062FE8(proc, i);
            updated = TRUE;
        }
    }

    if (!updated && gMapAnimSt.unk_5F)
        gMapAnimSt.unk_5F = FALSE;
}

void func_fe6_08062FE8(struct MAnimInfoWindowProc * proc, int actor_id)
{
    func_fe6_08062AB4(
        gBg0Tm + TM_OFFSET(
            gMapAnimSt.actor[actor_id].unk_10 + 2,
            gMapAnimSt.actor[actor_id].unk_11 + 2),
        gMapAnimSt.actor[actor_id].unk_0E / 16,
        TILEREF(BGCHR_MANIM_1 + 31, BGPAL_MANIM_5), 3, 0);

    func_fe6_08062C38(
        gBg0Tm + TM_OFFSET(
            gMapAnimSt.actor[actor_id].unk_10 + 3,
            gMapAnimSt.actor[actor_id].unk_11 + 2),
        gMapAnimSt.actor[actor_id].hp_max,
        gMapAnimSt.actor[actor_id].unk_0E / 16,
        0, gUnk_08664EE4);

    EnableBgSync(BG0_SYNC_BIT);
}

u16 const * func_fe6_080630C8(struct Unit * unit)
{
    switch (UNIT_FACTION(unit))
    {

    case FACTION_BLUE:
        return gUnk_082DC840;

    case FACTION_RED:
        return gUnk_082DC860;

    case FACTION_GREEN:
        return gUnk_082DC880;

    case FACTION_PURPLE:
        return gUnk_082DC8A0;

    default:
        return NULL;

    }
}

void func_fe6_08063120(struct MAnimInfoWindowProc * proc, int actor_id, int x_offset)
{
    gMapAnimSt.actor[actor_id].unk_10 = proc->x_tile + x_offset;
    gMapAnimSt.actor[actor_id].unk_11 = proc->y_tile;

    ApplyPalette(
        func_fe6_080630C8(gMapAnimSt.actor[actor_id].unit),
        BGPAL_MANIM_1 + actor_id);

    Decompress(
        gUnk_08664F08[gMapAnimSt.main_actor_count][actor_id], gBuf);

    TmApplyTsa_t(
        gBg1Tm + TM_OFFSET(
            gMapAnimSt.actor[actor_id].unk_10,
            gMapAnimSt.actor[actor_id].unk_11),
        gBuf, BGCHR_MANIM_1 | TILEREF(0, BGPAL_MANIM_1 + actor_id));

    EnableBgSync(BG1_SYNC_BIT);

    PutStringCentered(
        gBg0Tm + TM_OFFSET(
            gMapAnimSt.actor[actor_id].unk_10 + 1,
            gMapAnimSt.actor[actor_id].unk_11),
        TEXT_COLOR_SYSTEM_WHITE, 8,
        DecodeMsg(gMapAnimSt.actor[actor_id].unit->pinfo->msg_name));

    EnableBgSync(BG0_SYNC_BIT);

    gMapAnimSt.actor[actor_id].unk_0E = gMapAnimSt.actor[actor_id].hp_cur << 4;

    func_fe6_08062FE8(proc, actor_id);
}

void func_fe6_080632C4(struct MAnimInfoWindowProc * proc)
{
    proc->open_transition_value = 0;

    func_fe6_080633B0(proc);

    SetWinEnable(1, 0, 0);

    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(0, 0, 1, 1, 1);
}

void func_fe6_080633B0(struct MAnimInfoWindowProc * proc)
{
    SetWin0Box(
        0, (proc->y_tile + 2) * 8 - proc->open_transition_value,
        240, (proc->y_tile + 2) * 8 + proc->open_transition_value);

    proc->open_transition_value += 2;

    if (proc->open_transition_value > 0x10)
    {
        SetWinEnable(0, 0, 0);
        Proc_Break(proc);
    }
}

void func_fe6_08063494(int x_tm, int y_tm, int amt)
{
    func_fe6_08062AB4(
        gBg0Tm + TM_OFFSET(
            x_tm + 2,
            y_tm + 1),
        amt, TILEREF(BGCHR_MANIM_200 + 0x1F, BGPAL_MANIM_5), 2, TILEREF(BGCHR_MANIM_200 + 0x29, BGPAL_MANIM_5));

    func_fe6_08062C38(
        gBg0Tm + TM_OFFSET(
            x_tm + 3,
            y_tm + 1),
        99, amt, 0, gUnk_08664F58);

    EnableBgSync(BG0_SYNC_BIT);
}

void func_fe6_08063504(struct MAnimExpBarProc * proc)
{
    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);

    RegisterDataMove(
        gUnk_08113584,
        (void *)(VRAM) + GetBgChrOffset(0) + (BGCHR_MANIM_200 + 0x00) * CHR_SIZE,
        7 * CHR_SIZE);

    RegisterDataMove(
        gUnk_08113884,
        (void *)(VRAM) + GetBgChrOffset(0) + (BGCHR_MANIM_200 + 0x07) * CHR_SIZE,
        24 * CHR_SIZE);

    RegisterDataMove(
        gUnk_08113B84,
        (void *)(VRAM) + GetBgChrOffset(0) + (BGCHR_MANIM_200 + 0x1F) * CHR_SIZE,
        11 * CHR_SIZE);

    ApplyPalette(gUnk_08113D50, BGPAL_MANIM_5);

    TmApplyTsa_t(gBg0Tm + TM_OFFSET(6, 8), gUnk_082DC5B0, TILEREF(BGCHR_MANIM_200, BGPAL_MANIM_5));

    func_fe6_08063494(6, 8, proc->exp_from);
}

void func_fe6_080635B8(struct MAnimExpBarProc * proc)
{
    PlaySe(SONG_74);
}

void func_fe6_080635E0(struct MAnimExpBarProc * proc)
{
    proc->exp_from++;

    if (proc->exp_from >= 100)
        proc->exp_from = 0;

    func_fe6_08063494(6, 8, proc->exp_from);

    if (proc->exp_from == proc->exp_to % 100)
    {
        Proc_Break(proc);
        m4aSongNumStop(SONG_74);
    }
}

void func_fe6_0806367C(struct MAnimExpBarProc * proc)
{
    proc->unk_6A = 0;

    func_fe6_0806376C(proc);

    SetWinEnable(1, 0, 0);

    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(0, 0, 1, 1, 1);
}

void func_fe6_0806376C(struct MAnimExpBarProc * proc)
{
    SetWin0Box(
        0, 76 - proc->unk_6A,
        240, 76 + proc->unk_6A);

    proc->unk_6A += 2;

    if (proc->unk_6A > 12)
    {
        SetWinEnable(0, 0, 0);
        Proc_Break(proc);
    }
}

void func_fe6_08063848(struct MAnimExpBarProc * proc)
{
    if (proc->exp_to < 100)
        return;

    func_fe6_08067CF8(proc->actor_id, proc);
}

char const * CONST_DATA gManimDebugHitKindNameLut[] =
{
    JTEXT("ーーー"),
    JTEXT("攻撃"),
    JTEXT("攻撃デ"),
    JTEXT("攻撃リ"),
    JTEXT("攻撃毒"),
    JTEXT("必殺"),
    JTEXT("必殺デ"),
    JTEXT("必殺リ"),
    JTEXT("必殺毒"),
    JTEXT("空ぶり"),
};

struct ManimDebugParamInfo CONST_DATA gManimDebugParamInfoTable[] =
{
    [MANIM_DEBUG_PARAM_PID] =
    {
        .text_width = 9,
        .param_up = MANIM_DEBUG_PARAM_HITS + 4,
        .param_down = MANIM_DEBUG_PARAM_X,
        .param_left = MANIM_DEBUG_PARAM_PID,
        .param_right = MANIM_DEBUG_PARAM_PID,
        .min = 1, .max = MAX_PIDS,
    },

    [MANIM_DEBUG_PARAM_X] =
    {
        .text_width = 2,
        .param_up = MANIM_DEBUG_PARAM_PID,
        .param_down = MANIM_DEBUG_PARAM_JID,
        .param_left = MANIM_DEBUG_PARAM_Y,
        .param_right = MANIM_DEBUG_PARAM_Y,
        .min = 0, .max = 32,
    },

    [MANIM_DEBUG_PARAM_Y] =
    {
        .text_width = 2,
        .param_up = MANIM_DEBUG_PARAM_PID,
        .param_down = MANIM_DEBUG_PARAM_JID,
        .param_left = MANIM_DEBUG_PARAM_X,
        .param_right = MANIM_DEBUG_PARAM_X,
        .min = 0, .max = 32,
    },

    [MANIM_DEBUG_PARAM_JID] =
    {
        .text_width = 11,
        .param_up = MANIM_DEBUG_PARAM_X,
        .param_down = MANIM_DEBUG_PARAM_IID,
        .param_left = MANIM_DEBUG_PARAM_JID,
        .param_right = MANIM_DEBUG_PARAM_JID,
        .min = 1, .max = MAX_JIDS,
    },

    [MANIM_DEBUG_PARAM_IID] =
    {
        .text_width = 10,
        .param_up = MANIM_DEBUG_PARAM_JID,
        .param_down = MANIM_DEBUG_PARAM_HITS + 0,
        .param_left = MANIM_DEBUG_PARAM_IID,
        .param_right = MANIM_DEBUG_PARAM_IID,
        .min = 1, .max = MAX_IIDS,
    },

    [MANIM_DEBUG_PARAM_HITS + 0] =
    {
        .text_width = 9,
        .param_up = MANIM_DEBUG_PARAM_IID,
        .param_down = MANIM_DEBUG_PARAM_HITS + 1,
        .param_left = MANIM_DEBUG_PARAM_HITS + 0,
        .param_right = MANIM_DEBUG_PARAM_HITS + 0,
        .min = 0, .max = MAX_MANIM_DEBUG_HIT_KIND,
    },

    [MANIM_DEBUG_PARAM_HITS + 1] =
    {
        .text_width = 5,
        .param_up = MANIM_DEBUG_PARAM_HITS + 0,
        .param_down = MANIM_DEBUG_PARAM_HITS + 2,
        .param_left = MANIM_DEBUG_PARAM_HITS + 1,
        .param_right = MANIM_DEBUG_PARAM_HITS + 1,
        .min = 0, .max = MAX_MANIM_DEBUG_HIT_KIND,
    },

    [MANIM_DEBUG_PARAM_HITS + 2] =
    {
        .text_width = 5,
        .param_up = MANIM_DEBUG_PARAM_HITS + 1,
        .param_down = MANIM_DEBUG_PARAM_HITS + 3,
        .param_left = MANIM_DEBUG_PARAM_HITS + 2,
        .param_right = MANIM_DEBUG_PARAM_HITS + 2,
        .min = 0, .max = MAX_MANIM_DEBUG_HIT_KIND,
    },

    [MANIM_DEBUG_PARAM_HITS + 3] =
    {
        .text_width = 5,
        .param_up = MANIM_DEBUG_PARAM_HITS + 2,
        .param_down = MANIM_DEBUG_PARAM_HITS + 4,
        .param_left = MANIM_DEBUG_PARAM_HITS + 3,
        .param_right = MANIM_DEBUG_PARAM_HITS + 3,
        .min = 0, .max = MAX_MANIM_DEBUG_HIT_KIND,
    },

    [MANIM_DEBUG_PARAM_HITS + 4] =
    {
        .text_width = 5,
        .param_up = MANIM_DEBUG_PARAM_HITS + 3,
        .param_down = MANIM_DEBUG_PARAM_PID,
        .param_left = MANIM_DEBUG_PARAM_HITS + 4,
        .param_right = MANIM_DEBUG_PARAM_HITS + 4,
        .min = 0, .max = MAX_MANIM_DEBUG_HIT_KIND,
    },
};

char const * CONST_DATA gManimDebugParamLabelList[] =
{
    JTEXT("ＰＩＤ"),
    JTEXT("ＸＹ"),
    JTEXT("兵種"),
    JTEXT("武器"),
    JTEXT("１"),
    JTEXT("２"),
    JTEXT("３"),
    JTEXT("４"),
    JTEXT("５"),
    NULL, // end
};

extern struct ManimDebugSt gManimDebugStObj; // COMMON
struct ManimDebugSt * CONST_DATA gManimDebugSt = &gManimDebugStObj;

struct ProcScr CONST_DATA ProcScr_ManimDebug[] =
{
    PROC_SLEEP(1),
    PROC_CALL(LockGame),
    PROC_CALL(func_fe6_08073324),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08063CF4),
PROC_LABEL(0),
    PROC_CALL(func_fe6_08063EF0),
    PROC_REPEAT(func_fe6_080640D0),
    PROC_CALL(func_fe6_0806495C),
    PROC_WHILE_EXISTS(ProcScr_Unk_08664DA4),
    PROC_GOTO(0),
    PROC_END,
};

void StartDebugManim(void)
{
    SpawnProc(ProcScr_ManimDebug, PROC_TREE_3);
}

void func_fe6_08063894(int num, int param, int text_color)
{
    #define PARAM_DATA(param) (gManimDebugSt->ent[num].data[(param)])
    #define PARAM_TEXT(param) (&gManimDebugSt->ent[num].text[(param)])

    struct PInfo const * pinfo = GetPInfo(PARAM_DATA(MANIM_DEBUG_PARAM_PID));
    struct JInfo const * jinfo = GetJInfo(PARAM_DATA(MANIM_DEBUG_PARAM_JID));

    int pid = PARAM_DATA(MANIM_DEBUG_PARAM_PID);
    int jid = PARAM_DATA(MANIM_DEBUG_PARAM_JID);
    int iid = PARAM_DATA(MANIM_DEBUG_PARAM_IID);

    switch (param)
    {
        case MANIM_DEBUG_PARAM_PID:
            ClearText(PARAM_TEXT(MANIM_DEBUG_PARAM_PID));
            Text_InsertDrawNumberOrBlank(PARAM_TEXT(MANIM_DEBUG_PARAM_PID), 16, text_color, pid);
            PutDrawText(PARAM_TEXT(MANIM_DEBUG_PARAM_PID), gBg0Tm + TM_OFFSET(num * 12 + 6, 0), text_color, 24, 0, DecodeMsg(pinfo->msg_name));
            EnableBgSync(BG0_SYNC_BIT);
            break;

        case MANIM_DEBUG_PARAM_X:
            ClearText(PARAM_TEXT(MANIM_DEBUG_PARAM_X));
            Text_InsertDrawNumberOrBlank(PARAM_TEXT(MANIM_DEBUG_PARAM_X), 8, text_color, PARAM_DATA(MANIM_DEBUG_PARAM_X));
            PutText(PARAM_TEXT(MANIM_DEBUG_PARAM_X), gBg0Tm + TM_OFFSET(num * 12 + 7, 2));
            EnableBgSync(BG0_SYNC_BIT);
            break;

        case MANIM_DEBUG_PARAM_Y:
            ClearText(PARAM_TEXT(MANIM_DEBUG_PARAM_Y));
            Text_InsertDrawNumberOrBlank(PARAM_TEXT(MANIM_DEBUG_PARAM_Y), 8, text_color, PARAM_DATA(MANIM_DEBUG_PARAM_Y));
            PutText(PARAM_TEXT(MANIM_DEBUG_PARAM_Y), gBg0Tm + TM_OFFSET(num * 12 + 10, 2));
            EnableBgSync(BG0_SYNC_BIT);
            break;

        case MANIM_DEBUG_PARAM_JID:
            ClearText(PARAM_TEXT(MANIM_DEBUG_PARAM_JID));
            Text_InsertDrawNumberOrBlank(PARAM_TEXT(MANIM_DEBUG_PARAM_JID), 16, text_color, jid);
            PutDrawText(PARAM_TEXT(MANIM_DEBUG_PARAM_JID), gBg0Tm + TM_OFFSET(num * 12 + 6, 4), text_color, 24, 0, DecodeMsg(jinfo->msg_name));
            EnableBgSync(BG0_SYNC_BIT);
            break;

        case MANIM_DEBUG_PARAM_IID:
            ClearText(PARAM_TEXT(MANIM_DEBUG_PARAM_IID));
            Text_InsertDrawNumberOrBlank(PARAM_TEXT(MANIM_DEBUG_PARAM_IID), 16, text_color, iid);
            PutDrawText(PARAM_TEXT(MANIM_DEBUG_PARAM_IID), gBg0Tm + TM_OFFSET(num * 12 + 6, 6), text_color, 24, 0, GetItemName(PARAM_DATA(MANIM_DEBUG_PARAM_IID)));
            EnableBgSync(BG0_SYNC_BIT);
            break;

        case MANIM_DEBUG_PARAM_HITS ... MAX_MANIM_DEBUG_PARAM - 1:
            ClearText(PARAM_TEXT(param));
            Text_InsertDrawNumberOrBlank(PARAM_TEXT(param), 8, text_color, PARAM_DATA(param));
            PutDrawText(PARAM_TEXT(param), gBg0Tm + TM_OFFSET(num * 12 + 7, 8 + (param - MANIM_DEBUG_PARAM_HITS) * 2), text_color, 16, 0, gManimDebugHitKindNameLut[PARAM_DATA(param)]);
            EnableBgSync(BG0_SYNC_BIT);
            break;
    }

    #undef PARAM_TEXT
    #undef PARAM_DATA
}

void func_fe6_08063CF4(struct GenericProc * proc)
{
    Proc_EndEach(ProcScr_DebugMonitor);

    proc->unk64 = 0;
    proc->unk66 = 0;

    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_JID] = JID_ROY;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_PID] = PID_ROY;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_IID] = IID_IRONSWORD;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_X] = 4;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_Y] = 8;

    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_JID] = JID_MERCENARY;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_PID] = PID_LILINA;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_IID] = IID_BINDINGBLADE;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_X] = 5;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_Y] = 8;

    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_HITS + 0] = MANIM_DEBUG_HIT_KIND_REGULAR;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_HITS + 1] = MANIM_DEBUG_HIT_KIND_CRIT;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_HITS + 2] = MANIM_DEBUG_HIT_KIND_NONE;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_HITS + 3] = MANIM_DEBUG_HIT_KIND_NONE;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_HITS + 4] = MANIM_DEBUG_HIT_KIND_NONE;

    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_HITS + 0] = MANIM_DEBUG_HIT_KIND_REGULAR;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_HITS + 1] = MANIM_DEBUG_HIT_KIND_NONE;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_HITS + 2] = MANIM_DEBUG_HIT_KIND_NONE;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_HITS + 3] = MANIM_DEBUG_HIT_KIND_NONE;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_HITS + 4] = MANIM_DEBUG_HIT_KIND_NONE;
}

void func_fe6_08063EF0(struct GenericProc * proc)
{
    int i, j;

    EndAllMus();
    ResetText();

    SetBlendConfig(BLEND_EFFECT_BRIGHTEN, 8, 8, 0);
    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 1, 1);
    SetWinEnable(0, 0, 0);

    PutUiWindowFrame(0, 0, 29, 19, UI_WINDOW_FILL);

    for (i = 0; gManimDebugParamLabelList[i] != NULL; i++)
    {
        PutString(gBg0Tm + TM_OFFSET(1, i * 2), 0, gManimDebugParamLabelList[i]);
    }

    for (i = 0; i < MAX_MANIM_DEBUG_PARAM; i++)
    {
        for (j = 0; j < 2; ++j)
        {
            InitTextDb(&gManimDebugSt->ent[j].text[i], gManimDebugParamInfoTable[i].text_width);

            if (j == proc->unk64 && i == proc->unk66)
                func_fe6_08063894(j, i, TEXT_COLOR_SYSTEM_WHITE);
            else
                func_fe6_08063894(j, i, TEXT_COLOR_SYSTEM_GRAY);
        }
    }

    EnableBgSync(BG0_SYNC_BIT);
}

void func_fe6_080640D0(struct GenericProc * proc)
{
    int actor_prev = proc->unk64;
    int param_prev = proc->unk66;
    int step;

    if (gKeySt->pressed & KEY_BUTTON_START)
    {
        if (!func_fe6_080646E4())
            return;

        Proc_Break(proc);
    }

    if (gKeySt->held & KEY_BUTTON_R)
        step = 10;
    else
        step = 1;

    if (gKeySt->repeated & KEY_BUTTON_A)
    {
        gManimDebugSt->ent[proc->unk64].data[proc->unk66] += step;

        if (gManimDebugSt->ent[proc->unk64].data[proc->unk66] >= gManimDebugParamInfoTable[proc->unk66].max)
        {
            if (step == 1)
                gManimDebugSt->ent[proc->unk64].data[proc->unk66] = gManimDebugParamInfoTable[proc->unk66].min;
            else
                gManimDebugSt->ent[proc->unk64].data[proc->unk66] = gManimDebugParamInfoTable[proc->unk66].max - 1;
        }
    }

    if (gKeySt->repeated & KEY_BUTTON_B)
    {
        gManimDebugSt->ent[proc->unk64].data[proc->unk66] -= step;

        if (gManimDebugSt->ent[proc->unk64].data[proc->unk66] < gManimDebugParamInfoTable[proc->unk66].min)
        {
            if (step == 1)
                gManimDebugSt->ent[proc->unk64].data[proc->unk66] = gManimDebugParamInfoTable[proc->unk66].max - 1;
            else
                gManimDebugSt->ent[proc->unk64].data[proc->unk66] = gManimDebugParamInfoTable[proc->unk66].min;
        }
    }

    if (gKeySt->repeated & KEY_DPAD_LEFT)
    {
        if (proc->unk66 != MANIM_DEBUG_PARAM_Y)
            proc->unk64 = 1 - proc->unk64;

        proc->unk66 = gManimDebugParamInfoTable[proc->unk66].param_left;
    }

    if (gKeySt->repeated & KEY_DPAD_RIGHT)
    {
        if (proc->unk66 != MANIM_DEBUG_PARAM_X)
            proc->unk64 = 1 - proc->unk64;

        proc->unk66 = gManimDebugParamInfoTable[proc->unk66].param_right;
    }

    if (gKeySt->repeated & KEY_DPAD_UP)
        proc->unk66 = gManimDebugParamInfoTable[proc->unk66].param_up;

    if (gKeySt->repeated & KEY_DPAD_DOWN)
        proc->unk66 = gManimDebugParamInfoTable[proc->unk66].param_down;

    if (gKeySt->repeated & KEY_DPAD_ANY)
        func_fe6_08063894(actor_prev, param_prev, TEXT_COLOR_SYSTEM_GRAY);

    if (gKeySt->repeated & (KEY_DPAD_ANY | KEY_BUTTON_A | KEY_BUTTON_B))
        func_fe6_08063894(proc->unk64, proc->unk66, TEXT_COLOR_SYSTEM_WHITE);
}

void func_fe6_080645F8(struct BattleUnit * bu, int num)
{
    bu->previous_hp = 30;
    bu->unit.max_hp = 60;

    bu->unit.pinfo = GetPInfo(gManimDebugSt->ent[num].data[MANIM_DEBUG_PARAM_PID]);
    bu->unit.jinfo = GetJInfo(gManimDebugSt->ent[num].data[MANIM_DEBUG_PARAM_JID]);

    bu->unit.x = gManimDebugSt->ent[num].data[MANIM_DEBUG_PARAM_X];
    bu->unit.y = gManimDebugSt->ent[num].data[MANIM_DEBUG_PARAM_Y];

    bu->weapon_before = gManimDebugSt->ent[num].data[MANIM_DEBUG_PARAM_IID];
    bu->exp_gain = 0;
}

bool func_fe6_080646E4(void)
{
    // There's some gross variable reuse going on here

    int hitnum, actnum, i;
    struct BattleHit * hit;
    int var_10;

    hit = gBattleHits;

    func_fe6_080645F8(&gBattleUnitA, 0);
    func_fe6_080645F8(&gBattleUnitB, 1);

    ClearBattleHits();

    var_10 = 0;

    for (hitnum = 0; hitnum < MAX_MANIM_DEBUG_HITS; ++hitnum)
    {
        for (actnum = 0; actnum < 2; ++actnum)
        {
            if (gManimDebugSt->ent[actnum].data[MANIM_DEBUG_PARAM_HITS + hitnum] != 0)
            {
                var_10 = 1;
                break;
            }
        }

        if (var_10 != 0)
            break;
    }

    if (hitnum == MAX_MANIM_DEBUG_HITS && actnum == 2)
        return FALSE;

    for (i = hitnum * 2 + actnum; i < 10; i++)
    {
        hitnum = i / 2;
        actnum = i & 1;

        hit->info = BATTLE_HIT_INFO_ACTOR(actnum);

        var_10 = gManimDebugSt->ent[actnum].data[5 + hitnum];

        switch (var_10)
        {
            case MANIM_DEBUG_HIT_KIND_CRIT ... MANIM_DEBUG_HIT_KIND_MISS - 1:
                hit->attributes |= BATTLE_HIT_ATTR_CRIT;
                hit->damage = 20;
                break;

            case MANIM_DEBUG_HIT_KIND_REGULAR ... MANIM_DEBUG_HIT_KIND_CRIT - 1:
                hit->damage = 10;
                break;

            case MANIM_DEBUG_HIT_KIND_MISS:
                hit->attributes |= BATTLE_HIT_ATTR_MISS;
                break;
        }

        switch (var_10)
        {
            case MANIM_DEBUG_HIT_KIND_REGULAR_DEVIL:
            case MANIM_DEBUG_HIT_KIND_CRIT_DEVIL:
                hit->attributes |= BATTLE_HIT_ATTR_DEVIL;
                break;
                break;

            case MANIM_DEBUG_HIT_KIND_REGULAR_HPSTEAL:
            case MANIM_DEBUG_HIT_KIND_CRIT_HPSTEAL:
                hit->attributes |= BATTLE_HIT_ATTR_HPSTEAL;
                break;
                break;

            case MANIM_DEBUG_HIT_KIND_REGULAR_POISON:
            case MANIM_DEBUG_HIT_KIND_CRIT_POISON:
                hit->attributes |= BATTLE_HIT_ATTR_POISON;
                break;
                break;
        }

        switch (var_10)
        {
            case MANIM_DEBUG_HIT_KIND_NONE:
                continue;

            default:
                hit++;
        }
    }

    hit->info |= BATTLE_HIT_INFO_END;
    return TRUE;
}

void func_fe6_0806495C(struct GenericProc * proc)
{
    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
    func_fe6_080627D0();
}

void func_fe6_08064994(struct Unit * unit)
{
    Decompress(gUnk_082DB1C0, OBJ_VRAM0 + CHR_SIZE * OBJCHR_MANIM_180);

    StartSpriteAnimProc(gUnk_082DB2B0,
        UNIT_SCREEN_TILE_X(unit) * 8 + 8,
        UNIT_SCREEN_TILE_Y(unit) * 8 + 16,
        OAM2_CHR(OBJCHR_MANIM_180), 0, 2);
}

void func_fe6_08064A10(struct Unit * unit)
{
    Decompress(gUnk_082DB418, OBJ_VRAM0 + CHR_SIZE * OBJCHR_MANIM_180);

    StartSpriteAnimProc(gUnk_082DB55C,
        UNIT_SCREEN_TILE_X(unit) * 8 + 8,
        UNIT_SCREEN_TILE_Y(unit) * 8 + 16,
        OAM2_CHR(OBJCHR_MANIM_180), 0, 2);
}

struct ProcScr CONST_DATA ProcScr_Unk_0866510C[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08064B20),
    PROC_WHILE(SpriteAnimProcExists),
    PROC_END,
};

void func_fe6_08064A8C(struct Unit * unit, int arg_04)
{
    struct ManimEffectProc * proc;

    proc = SpawnProc(ProcScr_Unk_0866510C, PROC_TREE_3);

    proc->unit = unit;
    proc->x = UNIT_SCREEN_TILE_X(unit) * 8 + 8;
    proc->y = UNIT_SCREEN_TILE_Y(unit) * 8 - 8;
    proc->unk_48 = arg_04 ^ 1;
}

void func_fe6_08064B20(struct ManimEffectProc * proc)
{
    Decompress(gUnk_082DCAE4, OBJ_VRAM0 + CHR_SIZE * OBJCHR_MANIM_180);
    ApplyPalette(gUnk_082DCD70, 0x10 + OBJPAL_MANIM_3);

    StartSpriteAnimProc(gUnk_082A9228,
        proc->x, proc->y + 16,
        OAM2_CHR(OBJCHR_MANIM_180) | OAM2_PAL(OBJPAL_MANIM_3), proc->unk_48, 2);
}

struct ProcScr CONST_DATA ProcScr_Unk_0866512C[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08064BEC),
    PROC_WHILE(SpriteAnimProcExists),
    PROC_END,
};

void func_fe6_08064B7C(struct Unit * unit)
{
    struct ManimEffectProc * proc;

    proc = SpawnProc(ProcScr_Unk_0866512C, PROC_TREE_3);

    proc->unit = unit;
    proc->x = (UNIT_SCREEN_TILE_X(unit) + 1) * 8;
    proc->y = (UNIT_SCREEN_TILE_Y(unit) + 1) * 8;
}

void func_fe6_08064BEC(struct ManimEffectProc * proc)
{
    PlaySeSpacial(SONG_B7, proc->x);

    Decompress(gUnk_082DCEF4, OBJ_VRAM0 + CHR_SIZE * OBJCHR_MANIM_1C0);
    ApplyPalette(gUnk_082DD248, 0x10 + OBJPAL_MANIM_4);

    StartSpriteAnimProc(gUnk_082A9190,
        proc->x - 8, proc->y + 8,
        OAM2_CHR(OBJCHR_MANIM_1C0) | OAM2_PAL(OBJPAL_MANIM_4), 0, 2);
}

struct ProcScr CONST_DATA ProcScr_Unk_0866514C[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08064CC0),
    PROC_REPEAT(func_fe6_08064DF8),
    PROC_START_CHILD_LOCKING(ProcScr_Unk_08665194),
    PROC_SLEEP(60),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_08064C50(struct Unit * unit)
{
    struct ManimEffectProc * proc;

    proc = SpawnProc(ProcScr_Unk_0866514C, PROC_TREE_3);

    proc->unit = unit;
    proc->x = (UNIT_SCREEN_TILE_X(unit) + 1) * 8;
    proc->y = (UNIT_SCREEN_TILE_Y(unit) + 1) * 8;
}

void func_fe6_08064CC0(struct ManimEffectProc * proc)
{
    func_fe6_08067324();

    SetBgOffset(2, 0, 0);

    Decompress(gUnk_082DE994, ((void *) VRAM) + GetBgChrOffset(2) + BGCHR_MANIM_140 * CHR_SIZE);

    SetBlendAlpha(16, 16);
    SetBlendTargetA(0, 0, 1, 0, 0); SetBlendBackdropA(0);
    SetBlendTargetB(0, 0, 0, 1, 1); SetBlendBackdropB(1);

    proc->unk_40 = 0;
    proc->unk_42 = 0;

    func_fe6_08014D9C(gUnk_082DEFBC, 0x20 * BGPAL_MANIM_4, 0x20, 2, proc);
}

i16 CONST_DATA gUnk_08665184[] =
{
    +1, -1,
    -2, +2,
    +2, +1,
    -2, -2,
};

void func_fe6_08064DF8(struct ManimEffectProc * proc)
{
    if (proc->unk_42 > 2)
    {
        func_fe6_08014D50();
        func_fe6_08014DB4(gUnk_082DEFBC, 0x20 * BGPAL_MANIM_4, 0x20, 4, proc);

        Decompress(gUnk_082DEFFC, ((void *) VRAM) + GetBgChrOffset(2) + BGCHR_MANIM_140 * CHR_SIZE);

        func_fe6_080650A4(proc->x / 8 - 4, proc->y / 8 - 4, 8, 60, 0, proc);

        Proc_Break(proc);
        PlaySeSpacial(SONG_8C, proc->x);
    }
    else
    {
        int x_offset = gUnk_08665184[proc->unk_42 * 2 + 0];
        int y_offset = gUnk_08665184[proc->unk_42 * 2 + 1];

        func_fe6_080650A4(proc->x / 8 + x_offset - 3, proc->y / 8 + y_offset - 3, 6, 10, 8, proc);

        PlaySeSpacial(SONG_89, proc->x);

        proc->unk_42++;
    }
}

void func_fe6_08064F28(struct ManimEffectProc * proc)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);
}

struct ProcScr CONST_DATA ProcScr_Unk_08665194[] =
{
    PROC_CALL(func_fe6_08064F4C),
    PROC_REPEAT(func_fe6_08064FD0),
    PROC_END,
};

void func_fe6_08064F4C(struct ManimEffectProc * proc)
{
    func_fe6_08014D50();

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);

    proc->unk_64 = 64;

    func_fe6_08064FD0(proc);
}

void func_fe6_08064FD0(struct ManimEffectProc * proc)
{
    SetBlendBrighten(proc->unk_64-- >> 2);

    if (proc->unk_64 == 0)
    {
        SetBlendNone();
        Proc_Break(proc);
    }
}

struct ManimSomethingProc_080650A4
{
    /* 00 */ PROC_HEADER;
    /* 2C */ int x, y;
    /* 34 */ u8 pad_34[0x10];
    /* 44 */ short freeze_duration;
    /* 48 */ u8 pad_46[0x54 - 0x48];
    /* 54 */ int square_size;
    /* 58 */ int fadeout_duration;
    /* 5C */ u8 pad_5C[0x64 - 0x5C];
    /* 64 */ short counter;
};

void func_fe6_080650F8(struct ManimSomethingProc_080650A4 * proc);
void func_fe6_0806511C(struct ManimSomethingProc_080650A4 * proc);
void func_fe6_08065140(struct ManimSomethingProc_080650A4 * proc);
void func_fe6_080651E0(struct ManimSomethingProc_080650A4 * proc);
void func_fe6_08065298(struct ManimSomethingProc_080650A4 * proc);
void func_fe6_080652E0(struct ManimSomethingProc_080650A4 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086651AC[] =
{
    PROC_ONEND(func_fe6_080650F8),
    PROC_CALL(func_fe6_0806511C),
    PROC_SLEEP(0),
    PROC_CALL(func_fe6_08065140),
    PROC_REPEAT(func_fe6_080651E0),
    PROC_REPEAT(func_fe6_08065298),
    PROC_REPEAT(func_fe6_080652E0),
    PROC_END,
};

void func_fe6_080650A4(int x, int y, int square_size, int freeze_duration, int fadeout_duration, ProcPtr parent)
{
    struct ManimSomethingProc_080650A4 * proc;

    proc = SpawnProcLocking(ProcScr_Unk_086651AC, parent);

    proc->x = x;
    proc->y = y;
    proc->square_size = square_size;
    proc->fadeout_duration = fadeout_duration;
    proc->freeze_duration = freeze_duration;
}

void func_fe6_080650F8(struct ManimSomethingProc_080650A4 * proc)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_0806511C(struct ManimSomethingProc_080650A4 * proc)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_08065140(struct ManimSomethingProc_080650A4 * proc)
{
    func_fe6_08014E30(gBg2Tm, proc->x, proc->y, TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4), proc->square_size, proc->square_size);
    EnableBgSync(BG2_SYNC_BIT);
    SetBlendAlpha(0, 0x10);
    proc->counter = 0;
}

void func_fe6_080651E0(struct ManimSomethingProc_080650A4 * proc)
{
    proc->counter += 2;
    SetBlendAlpha(proc->counter, 0x10);

    if (proc->counter >= 8)
    {
        proc->counter = 0;
        Proc_Break(proc);
    }
}

void func_fe6_08065298(struct ManimSomethingProc_080650A4 * proc)
{
    if (--proc->freeze_duration == -1)
        Proc_Break(proc);
}

void func_fe6_080652E0(struct ManimSomethingProc_080650A4 * proc)
{
    int coef;

    if (proc->fadeout_duration == 0)
    {
        Proc_Break(proc);
        return;
    }

    coef = Interpolate(INTERPOLATE_LINEAR, 8, 0, proc->counter++, proc->fadeout_duration);
    SetBlendAlpha(coef, 0x10);

    if (proc->counter >= proc->fadeout_duration)
    {
        proc->counter = 0;

        TmFill(gBg2Tm, 0);
        EnableBgSync(BG2_SYNC_BIT);

        Proc_Break(proc);
    }
}

struct ManimSomethingProc_080653BC
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_34[0x40 - 0x38];
    /* 40 */ u16 counter;
    /* 42 */ u8 pad_42[0x50 - 0x42];
    /* 50 */ void const * img;
    /* 54 */ void const * pal;
};

void func_fe6_0806543C(struct ManimSomethingProc_080653BC * proc);
void func_fe6_08065540(struct ManimSomethingProc_080653BC * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086651EC[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_0806543C),
    PROC_REPEAT(func_fe6_08065540),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_080653BC(struct Unit * unit, void const * arg_04, void const * arg_08)
{
    struct ManimSomethingProc_080653BC * proc;

    proc = SpawnProc(ProcScr_Unk_086651EC, PROC_TREE_3);

    proc->unit = unit;
    proc->x = (UNIT_SCREEN_TILE_X(unit) + 1) * 8;
    proc->y = (UNIT_SCREEN_TILE_Y(unit) + 1) * 8;
    proc->img = arg_04;
    proc->pal = arg_08;
}

void func_fe6_0806543C(struct ManimSomethingProc_080653BC * proc)
{
    PlaySeSpacial(SONG_B6, proc->x);

    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg1_ct.priority = 1;
    gDispIo.bg2_ct.priority = 1;
    gDispIo.bg3_ct.priority = 2;

    SetBgOffset(2, 0, 0);

    Decompress(proc->img, ((void *) VRAM) + GetBgChrOffset(2) + CHR_SIZE * BGCHR_MANIM_140);
    ApplyPalette(proc->pal, BGPAL_MANIM_4);

    func_fe6_08067324();

    SetBlendAlpha(0x10, 0x10);

    proc->counter = 0;
}

void func_fe6_08065540(struct ManimSomethingProc_080653BC * proc)
{
    static u8 SHOULD_BE_CONST lut[] =
    {
         0,  1,  2,  3,
         4,  5,  6,  7,
         8,  9, 10, 11,
        12, 13, 14, 15,
        16, 17, 18, 19,

        UINT8_MAX, // end
    };

    func_fe6_08014F70(gBg2Tm, proc->x / 8 - 3, proc->y / 8 - 3, TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4), 6, 6, gUnk_082DE354, lut[proc->counter / 2]);
    EnableBgSync(BG2_SYNC_BIT);

    proc->counter++;

    if (lut[proc->counter / 2] == UINT8_MAX)
    {
        Proc_Break(proc);
    }
}

struct ManimSomethingProc_08065608
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 pad_29[0x30 - 0x29];
    /* 30 */ int x, y;
};

void func_fe6_08065674(struct ManimSomethingProc_08065608 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_08665234[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08065674),
    PROC_SLEEP(100),
    PROC_END,
};

void func_fe6_08065608(struct Unit * unit)
{
    struct ManimSomethingProc_08065608 * proc;

    proc = SpawnProc(ProcScr_Unk_08665234, PROC_TREE_3);

    proc->x = UNIT_SCREEN_TILE_X(unit) * 8 + 8;
    proc->y = UNIT_SCREEN_TILE_Y(unit) * 8 + 8;
}

void func_fe6_08065674(struct ManimSomethingProc_08065608 * proc)
{
    PlaySeSpacial(SONG_10F, proc->x);
}

struct ManimSomethingProc_08065694
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ u8 pad_30[0x40 - 0x30];
    /* 40 */ u16 ca;
    /* 42 */ u16 cb;
    /* 44 */ u8 pad_44[0x50 - 0x44];
    /* 50 */ void const * img;
    /* 54 */ void const * pal;
    /* 58 */ u16 song;
};

void func_fe6_080656F0(struct ManimSomethingProc_08065694 * proc);
void func_fe6_08065830(struct ManimSomethingProc_08065694 * proc);
void func_fe6_08065994(struct ManimSomethingProc_08065694 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_08665254[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_080656F0),
    PROC_REPEAT(func_fe6_08065830),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08065994),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_08065694(struct Unit * unit, void const * img, void const * pal, fu16 song)
{
    struct ManimSomethingProc_08065694 * proc;

    proc = SpawnProc(ProcScr_Unk_08665254, PROC_TREE_3);

    proc->unit = unit;
    proc->img = img;
    proc->pal = pal;
    proc->song = song;
}

void func_fe6_080656F0(struct ManimSomethingProc_08065694 * proc)
{
    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg1_ct.priority = 1;
    gDispIo.bg2_ct.priority = 1;
    gDispIo.bg3_ct.priority = 2;

    SetBgOffset(2, 0, 0);

    Decompress(proc->img, ((void *) VRAM) + GetBgChrOffset(2) + CHR_SIZE * BGCHR_MANIM_140);

    func_fe6_08014E30(gBg2Tm, UNIT_SCREEN_TILE_X(proc->unit) - 2, UNIT_SCREEN_TILE_Y(proc->unit) - 2, TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4), 6, 6);
    EnableBgSync(BG2_SYNC_BIT);

    func_fe6_08014DB4(proc->pal, BGPAL_MANIM_4 * 0x20, 0x20, 4, proc);

    proc->ca = 0;
    proc->cb = 0x10;

    PlaySeSpacial(proc->song, (UNIT_SCREEN_TILE_X(proc->unit) + 1) * 8);
}

void func_fe6_08065830(struct ManimSomethingProc_08065694 * proc)
{
    proc->ca++;

    if (proc->ca == 0x10)
    {
        Proc_Break(proc);
    }

    proc->cb = 0x16 - proc->ca;

    if (proc->cb > 0x10)
        proc->cb = 0x10;

    SetBlendAlpha(proc->ca, proc->cb);

    SetBlendTargetA(0, 0, 1, 0, 0); SetBlendBackdropA(0);
    SetBlendTargetB(0, 0, 0, 1, 1); SetBlendBackdropB(1);
}

void func_fe6_08065994(struct ManimSomethingProc_08065694 * proc)
{
    proc->ca--;

    if (proc->ca == 0)
    {
        Proc_Break(proc);
    }

    proc->cb = 0x16 - proc->ca;

    if (proc->cb > 0x10)
        proc->cb = 0x10;

    SetBlendAlpha(proc->ca, proc->cb);

    SetBlendTargetA(0, 0, 1, 0, 0); SetBlendBackdropA(0);
    SetBlendTargetB(0, 0, 0, 1, 1); SetBlendBackdropB(1);
}

void func_fe6_08065AF8(ProcPtr proc)
{
    func_fe6_08014D50();

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    SetBlendNone();
    SetWinEnable(0, 0, 0);
}

void func_fe6_08065B90(ProcPtr proc)
{
    SetOnHBlankA(NULL);

    func_fe6_08014D50();

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    SetBlendNone();
    SetWinEnable(0, 0, 0);
}

struct ManimSomethingProc_08065C30
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 counter;
};

void func_fe6_08065C9C(struct ManimSomethingProc_08065C30 * proc);
void func_fe6_08065CF4(struct ManimSomethingProc_08065C30 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_0866528C[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08065C9C),
    PROC_REPEAT(func_fe6_08065CF4),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_08065C30(struct Unit * unit, int arg_04, int arg_08)
{
    struct ManimSomethingProc_08065C30 * proc;

    proc = SpawnProc(ProcScr_Unk_0866528C, PROC_TREE_3);

    proc->unit = unit;
    proc->x = UNIT_SCREEN_TILE_X(proc->unit);
    proc->y = UNIT_SCREEN_TILE_Y(proc->unit);
}

void func_fe6_08065C9C(struct ManimSomethingProc_08065C30 * proc)
{
    SetBgOffset(2, 0, 0);

    Decompress(gUnk_082DD268, ((void *) VRAM) + GetBgChrOffset(2) + CHR_SIZE * BGCHR_MANIM_140);
    ApplyPalette(gUnk_082DD4C8, BGPAL_MANIM_4);

    func_fe6_080686D8();

    proc->counter = 0;
}

void func_fe6_08065CF4(struct ManimSomethingProc_08065C30 * proc)
{
    static u8 SHOULD_BE_CONST lut[] =
    {
        0, 1, 2, 3,
        3, 3, 3, 3,
        3, 3, 3, 3,
        3, 3, 3, 4,
        5, 6, 7, 8,
        9,
        UINT8_MAX, // end
    };

    func_fe6_08014F70(gBg2Tm, proc->x - 1, proc->y - 3, TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4), 4, 6, gUnk_082DD4E8, lut[proc->counter / 2]);
    EnableBgSync(BG2_SYNC_BIT);

    proc->counter++;

    if (lut[proc->counter / 2] == UINT8_MAX)
    {
        Proc_Break(proc);
    }

    func_fe6_08067324();

    SetBlendAlpha(12, 12);
}

struct ManimSomethingProc_08065E08
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 unk_40, unk_42;
};

void func_fe6_08065E78(struct ManimSomethingProc_08065E08 * proc);
void func_fe6_08065F9C(struct ManimSomethingProc_08065E08 * proc);
void func_fe6_08066094(struct ManimSomethingProc_08065E08 * proc);
void func_fe6_08066190(struct ManimSomethingProc_08065E08 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086652D4[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08065E78),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08065F9C),
    PROC_REPEAT(func_fe6_08066094),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08066190),
    PROC_CALL(func_fe6_08065B90),
    PROC_END,
};

void func_fe6_08065E08(struct Unit * unit)
{
    struct ManimSomethingProc_08065E08 * proc;

    proc = SpawnProc(ProcScr_Unk_086652D4, PROC_TREE_3);

    proc->unit = unit;
    proc->x = UNIT_SCREEN_TILE_X(proc->unit) * 8;
    proc->y = UNIT_SCREEN_TILE_Y(proc->unit) * 8;
}

void func_fe6_08065E78(struct ManimSomethingProc_08065E08 * proc)
{
    PlaySe(SONG_B3);

    Decompress(gUnk_082DF3D8, ((void *) VRAM) + 0x10000 + OBJCHR_MANIM_1C0 * CHR_SIZE);
    ApplyPalette(gUnk_082DF690, 0x10 + OBJPAL_MANIM_4);

    SetWhitePal(BGPAL_MANIM_4);
    func_fe6_08015208(((void *) VRAM) + GetBgChrOffset(2) + BGCHR_MANIM_140 * CHR_SIZE, CHR_SIZE / sizeof(u16), 0xFFFF);
    func_fe6_08015208(gBg2Tm, ARRAY_COUNT(gBg2Tm), TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4));
    EnableBgSync(BG2_SYNC_BIT);

    proc->unk_40 = 0;
    proc->unk_42 = 0;

    StartSpriteAnimProc(gUnk_082A8448, proc->x + 4, proc->y, OAM2_CHR(OBJCHR_MANIM_1C0) + OAM2_PAL(OBJPAL_MANIM_4), 0, 2);

    func_fe6_08069C34();
    func_fe6_08069C74();
    func_fe6_08067324();

    SetBlendAlpha(0, 0x10);
}

void func_fe6_08065F9C(struct ManimSomethingProc_08065E08 * proc)
{
    int var_04, ca;

    var_04 = Interpolate(INTERPOLATE_RCUBIC, 1, 160, proc->unk_40, 80);
    func_fe6_08069DA4(proc->x + 8, proc->y + 8, var_04);

    proc->unk_40++;

    ca = (proc->unk_40 * 0x10) / 40;

    if (ca >= 0x10)
        ca = 0x10;

    SetBlendAlpha(ca, 0x10);

    if (proc->unk_40 >= 40)
    {
        Proc_Break(proc);
        EndEachSpriteAnimProc();
    }
}

void func_fe6_08066094(struct ManimSomethingProc_08065E08 * proc)
{
    int var_04, ca;

    var_04 = Interpolate(INTERPOLATE_RCUBIC, 1, 160, proc->unk_40, 80);
    func_fe6_08069DA4(proc->x + 8, proc->y + 8, var_04);

    proc->unk_40++;

    ca = 0x10 - ((proc->unk_40 - 40) * 0x10) / 30;

    if (ca <= 0)
        ca = 0;

    SetBlendAlpha(ca, 0x10);

    if (proc->unk_40 >= 70)
    {
        Proc_Break(proc);
    }
}

void func_fe6_08066190(struct ManimSomethingProc_08065E08 * proc)
{
    func_fe6_08069DD8();
}

struct ManimSomethingProc_080661A4
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x48 - 0x38];
    /* 48 */ u16 unk_48;
};

void func_fe6_08066214(struct ManimSomethingProc_080661A4 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_0866531C[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08066214),
    PROC_SLEEP(120),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_080661A4(struct Unit * unit)
{
    struct ManimSomethingProc_080661A4 * proc;

    proc = SpawnProc(ProcScr_Unk_0866531C, PROC_TREE_3);

    proc->unit = unit;
    proc->x = (UNIT_SCREEN_TILE_X(unit) + 1) * 8;
    proc->y = (UNIT_SCREEN_TILE_Y(unit) + 1) * 8;
}

void func_fe6_08066214(struct ManimSomethingProc_080661A4 * proc)
{
    PlaySeSpacial(SONG_87, proc->x);
    SetBgOffset(2, 0, 0);
    func_fe6_08067324();
    Decompress(gUnk_082E0E14, ((void *) VRAM) + 0x10000 + CHR_SIZE * OBJCHR_MANIM_1C0);
    ApplyPalette(gUnk_082E10EC, 0x10 + OBJPAL_MANIM_4);
    StartSpriteAnimProc(gUnk_082E110C, proc->x, proc->y, OAM2_CHR(OBJCHR_MANIM_1C0) + OAM2_PAL(OBJPAL_MANIM_4), 0, 2);
    proc->unk_48 = 1;
}

struct ManimSomethingProc_08066294
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 unk_40, unk_42;
    /* 44 */ u8 pad_44[0x48 - 0x44];
    /* 48 */ i16 unk_48, unk_4A;
};

void func_fe6_08066300(struct ManimSomethingProc_08066294 * proc);
void func_fe6_0806631C(struct ManimSomethingProc_08066294 * proc);
void func_fe6_080663E0(struct ManimSomethingProc_08066294 * proc);
void func_fe6_08066484(struct ManimSomethingProc_08066294 * proc);
void func_fe6_08066544(struct ManimSomethingProc_08066294 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_08665344[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_0806631C),
    PROC_CALL(func_fe6_08066300),
    PROC_REPEAT(func_fe6_080663E0),
    PROC_REPEAT(func_fe6_08066484),
    PROC_REPEAT(func_fe6_08066544),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_0806664C(struct ManimSomethingProc_08066294 * proc);
void func_fe6_08066678(struct ManimSomethingProc_08066294 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_08665384[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_0806631C),
    PROC_CALL(func_fe6_0806664C),
    PROC_REPEAT(func_fe6_08066678),
    PROC_REPEAT(func_fe6_08066484),
    PROC_REPEAT(func_fe6_08066544),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_08066294(struct Unit * unit)
{
    struct ManimSomethingProc_08066294 * proc;

    proc = SpawnProc(ProcScr_Unk_08665344, PROC_TREE_3);

    proc->x = UNIT_SCREEN_TILE_X(unit) * 8 + 8;
    proc->y = UNIT_SCREEN_TILE_Y(unit) * 8 + 8;
}

void func_fe6_08066300(struct ManimSomethingProc_08066294 * proc)
{
    PlaySeSpacial(SONG_86, proc->x);
}

void func_fe6_0806631C(struct ManimSomethingProc_08066294 * proc)
{
    SetBgOffset(2, 0, 0);
    func_fe6_08067324();
    SetBlendAlpha(0x10, 0x10);
    Decompress(gUnk_082DFAD4, ((void *) VRAM) + GetBgChrOffset(2) + CHR_SIZE * BGCHR_MANIM_140);
    ApplyPalette(gUnk_081B4274, BGPAL_MANIM_4);
    proc->unk_48 = 0;
    proc->unk_4A = 0;
}

void func_fe6_080663E0(struct ManimSomethingProc_08066294 * proc)
{
    static u8 const unk_param_list[] =
    {
        0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        UINT8_MAX, // end
    };

    func_fe6_0801501C(gBg2Tm,
        proc->x / 8 - 2, proc->y / 8 - 9,
        TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4),
        4, 11, gUnk_082E07A8,
        unk_param_list[proc->unk_48++]);

    EnableBgSync(BG2_SYNC_BIT);

    if (unk_param_list[proc->unk_48] == UINT8_MAX)
        Proc_Break(proc);
}

void func_fe6_08066484(struct ManimSomethingProc_08066294 * proc)
{
    SHOULD_BE_STATIC u8 SHOULD_BE_CONST blend_coef_list[] =
    {
        16, 14, 12, 10, 8, 10, 12, 14, 16,
        16, 14, 12, 10, 8, 10, 12, 14, 16,
        UINT8_MAX, // end
    };

    SetBlendAlpha(blend_coef_list[proc->unk_4A++], 0x10);

    if (blend_coef_list[proc->unk_4A] == UINT8_MAX)
    {
        proc->unk_4A = 0;
        Proc_Break(proc);
    }
}

void func_fe6_08066544(struct ManimSomethingProc_08066294 * proc)
{
    enum { DURATION = 30 };

    SetBlendAlpha(
        Interpolate(INTERPOLATE_LINEAR, 0x10, 0, proc->unk_4A++, DURATION), 0x10);

    if (proc->unk_4A > DURATION)
    {
        Proc_Break(proc);
    }
}

void func_fe6_080665E4(struct Unit * unit)
{
    struct ManimSomethingProc_08066294 * proc;

    proc = SpawnProc(ProcScr_Unk_08665384, PROC_TREE_3);

    proc->x = (UNIT_SCREEN_TILE_X(unit) + 1) * 8;
    proc->y = (UNIT_SCREEN_TILE_Y(unit) + 1) * 8;
}

void func_fe6_0806664C(struct ManimSomethingProc_08066294 * proc)
{
    PlaySeSpacial(SONG_82, proc->x);
    ApplyPalette(Pal_Unk_081B1710, BGPAL_MANIM_4);
}

void func_fe6_08066678(struct ManimSomethingProc_08066294 * proc)
{
    // same as func_fe6_080663E0 except gUnk_082E07A8 -> gUnk_082DF868

    static u8 const unk_param_list[] =
    {
        0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        UINT8_MAX, // end
    };

    func_fe6_0801501C(gBg2Tm,
        proc->x / 8 - 2, proc->y / 8 - 9,
        TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4),
        4, 11, gUnk_082DF868,
        unk_param_list[proc->unk_48++]);

    EnableBgSync(BG2_SYNC_BIT);

    if (unk_param_list[proc->unk_48] == UINT8_MAX)
        Proc_Break(proc);
}

struct ManimSomethingProc_0806671C
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 unk_40, unk_42;
    /* 44 */ u8 pad_44[0x48 - 0x44];
    /* 48 */ i16 unk_48, unk_4A;
};

void func_fe6_08066784(struct ManimSomethingProc_0806671C * proc);
void func_fe6_080667F0(struct ManimSomethingProc_0806671C * proc);
void func_fe6_08066830(struct ManimSomethingProc_0806671C * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086653C4[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08066784),
    PROC_SLEEP(50),
    PROC_CALL(func_fe6_080667F0),
    PROC_SLEEP(50),
    PROC_CALL(func_fe6_08066830),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_0806671C(struct Unit * unit)
{
    struct ManimSomethingProc_0806671C * proc;

    proc = SpawnProc(ProcScr_Unk_086653C4, PROC_TREE_3);

    proc->x = (UNIT_SCREEN_TILE_X(unit) + 1) * 8;
    proc->y = (UNIT_SCREEN_TILE_Y(unit) + 1) * 8;
}

/*

*/
