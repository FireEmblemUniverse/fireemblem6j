#include "statscreen.h"

#include <stdlib.h>

#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "proc.h"
#include "icon.h"
#include "sprite.h"
#include "text.h"
#include "face.h"
#include "msg.h"
#include "util.h"
#include "item.h"
#include "unit.h"
#include "bm.h"
#include "faction.h"
#include "unitsprite.h"
#include "battle.h"
#include "bmio.h"
#include "support.h"
#include "ui.h"
#include "mu.h"
#include "helpbox.h"
#include "systemlabels.h"
#include "save_stats.h"

#include "constants/videoalloc_global.h"
#include "constants/songs.h"
#include "constants/msg.h"

enum
{
    PAGE_FRAME_SCREEN_X = 12,
    PAGE_FRAME_SCREEN_Y = 2,
};

struct StatScreenInfo EWRAM_DATA gStatScreenInfo = { 0 };

extern struct StatScreenSt gStatScreenSt; // TODO: ewram overlay

void DrawUiGaugeBitmapEdgeColumn(u8 * bitmap, int pixels_per_line, int column)
{
    bitmap[1 * pixels_per_line + column] = 4;
    bitmap[2 * pixels_per_line + column] = 14;
    bitmap[3 * pixels_per_line + column] = 3;
}

void DrawUiGaugeBitmapBaseColumn(u8 * bitmap, int pixels_per_line, int column)
{
    bitmap[0 * pixels_per_line + column] = 4;
    bitmap[1 * pixels_per_line + column] = 14;
    bitmap[2 * pixels_per_line + column] = 14;
    bitmap[3 * pixels_per_line + column] = 14;
    bitmap[4 * pixels_per_line + column] = 3;
}

void DrawUiGaugeBitmapFilledColumn(u8 * bitmap, int pixels_per_line, int column)
{
    bitmap[1 * pixels_per_line + column] = 1;
    bitmap[2 * pixels_per_line + column] = 5;
}

void DrawUiGaugeBitmapBonusColumn(u8 * bitmap, int pixels_per_line, int column)
{
    bitmap[1 * pixels_per_line + column] = 13;
    bitmap[2 * pixels_per_line + column] = 12;
}

void DrawUiGauge(int chr, int dot_x, int chr_count, int dot_width, int dot_plain, int dot_bonus)
{
    int i;

    u8 * bitmap = gBuf;

    CpuFastFill(0, bitmap, chr_count * 8 * 8);

    DrawUiGaugeBitmapEdgeColumn(bitmap, chr_count * 8, dot_x);
    DrawUiGaugeBitmapEdgeColumn(bitmap, chr_count * 8, dot_x + dot_width + 3);

    for (i = 0; i < dot_width + 2; i++)
    {
        DrawUiGaugeBitmapBaseColumn(bitmap, chr_count * 8, i + 1 + dot_x);
    }

    for (i = 0; i < dot_plain; i++)
    {
        DrawUiGaugeBitmapFilledColumn(bitmap, chr_count * 8, i + 2 + dot_x);
    }

    for (i = 0; i < dot_bonus; i++)
    {
        DrawUiGaugeBitmapBonusColumn(bitmap, chr_count * 8, dot_plain + i + 2 + dot_x);
    }

    ApplyBitmap(bitmap, ((void *) VRAM) + chr * CHR_SIZE, chr_count, 1);
}

void PutDrawUiGauge(int chr, int width, u16 * tm, int tileref, int dot_width, int dot_plain, int dot_bonus)
{
    DrawUiGauge(chr, 2, width, dot_width, dot_plain, dot_bonus);

    tileref += chr & 0x3FF; // TODO: macro?
    PutAppliedBitmap(tm, tileref, width, 1);
}

void BackgroundSlide_Init(struct MuralBackgroundProc * proc)
{
    proc->offset = 0;
}

void BackgroundSlide_Loop(struct MuralBackgroundProc * proc)
{
    proc->offset++;

    SetBgOffset(3, proc->offset / 4, 0);
    REG_BG3HOFS = proc->offset / 4;
}

struct ProcScr CONST_DATA ProcScr_BackgroundSlide[] =
{
    PROC_CALL(BackgroundSlide_Init),
    PROC_REPEAT(BackgroundSlide_Loop),
    PROC_END,
};

ProcPtr StartMuralBackground(ProcPtr parent, void * vram, int pal)
{
    int i, tileref;
    u16 * tm = gBg3Tm;

    if (vram == NULL)
        vram = ((void*) VRAM) + GetBgChrOffset(3);

    if (pal < 0)
        pal = BGPAL_MURALBACKGROUND;

    if (gBmSt.flags & BM_FLAG_LINKARENA)
        ApplyPalettes(Pal_LinkArenaMuralBackground, pal, 2);
    else
        ApplyPalettes(Pal_MuralBackground, pal, 2);

    Decompress(Img_MuralBackground, vram);

    tileref = ((((uptr) (vram - GetBgChrOffset(3))) / CHR_SIZE) & 0xFFF) + TILE_PAL_SAFE(pal);

    // TODO: constant
    for (i = 0; i < 0x280; i++)
        *tm++ = i + tileref;

    return SpawnProc(ProcScr_BackgroundSlide, parent);
}

void EndMuralBackground(void)
{
    Proc_EndEach(ProcScr_BackgroundSlide);
}

int GetLastStatScreenUnitId(void)
{
    return gStatScreenInfo.unit_id;
}

void SetStatScreenLastUnitId(int unit_id)
{
    gStatScreenInfo.unit_id = unit_id;
}

void SetStatScreenExcludedUnitFlags(int flags)
{
    gStatScreenInfo.excluded_unit_flags = flags;
}

struct TextInitInfo CONST_DATA gStatScreenTextList[] =
{
    { gStatScreenSt.text + STATSCREEN_TEXT_PNAME, 7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_JNAME, 7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_UNUSED, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_POW, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_SKL, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_SPD, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_LCK, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_DEF, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_RES, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_MOV, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_CON, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_AID, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_RESCUE, 9 },
    { gStatScreenSt.text + STATSCREEN_TEXT_AFFINITY, 7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_STATUS, 9 },
    { gStatScreenSt.text + STATSCREEN_TEXT_ITEM_A, 7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_ITEM_B, 7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_ITEM_C, 7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_ITEM_D, 7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_ITEM_E, 7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_EQUIPRANGE, 6 },
    { gStatScreenSt.text + STATSCREEN_TEXT_EQUIPATTACK, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_EQUIPHIT, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_EQUIPCRIT, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_EQUIPAVOID, 3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_WEXP_A, 2 },
    { gStatScreenSt.text + STATSCREEN_TEXT_WEXP_B, 2 },
    { gStatScreenSt.text + STATSCREEN_TEXT_WEXP_C, 2 },
    { gStatScreenSt.text + STATSCREEN_TEXT_WEXP_D, 2 },
    { gStatScreenSt.text + STATSCREEN_TEXT_SUPPORT_A, 7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_SUPPORT_B, 7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_SUPPORT_C, 7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_SUPPORT_D, 7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_SUPPORT_E, 7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_BWL, 16 },

    { 0 }, // end!
};

struct StatScreenTextInfo const gStatScreenPersonalInfoLabelsInfo[] =
{
    { gStatScreenSt.text + STATSCREEN_TEXT_SKL,      gUiTmScratchA + TM_OFFSET(1, 3),  TEXT_COLOR_SYSTEM_GOLD, 4, SystemLabel_Skill },
    { gStatScreenSt.text + STATSCREEN_TEXT_SPD,      gUiTmScratchA + TM_OFFSET(1, 5),  TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_Speed },
    { gStatScreenSt.text + STATSCREEN_TEXT_LCK,      gUiTmScratchA + TM_OFFSET(1, 7),  TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_Luck },
    { gStatScreenSt.text + STATSCREEN_TEXT_DEF,      gUiTmScratchA + TM_OFFSET(1, 9),  TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_Defense },
    { gStatScreenSt.text + STATSCREEN_TEXT_RES,      gUiTmScratchA + TM_OFFSET(1, 11), TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_Resistance },
    { gStatScreenSt.text + STATSCREEN_TEXT_MOV,      gUiTmScratchA + TM_OFFSET(9, 1),  TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_Movement },
    { gStatScreenSt.text + STATSCREEN_TEXT_CON,      gUiTmScratchA + TM_OFFSET(9, 3),  TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_Constitution },
    { gStatScreenSt.text + STATSCREEN_TEXT_AID,      gUiTmScratchA + TM_OFFSET(9, 5),  TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_Aid },
    { gStatScreenSt.text + STATSCREEN_TEXT_RESCUE,   gUiTmScratchA + TM_OFFSET(9, 7),  TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_Rescue },
    { gStatScreenSt.text + STATSCREEN_TEXT_AFFINITY, gUiTmScratchA + TM_OFFSET(9, 9),  TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_Affinity },
    { gStatScreenSt.text + STATSCREEN_TEXT_STATUS,   gUiTmScratchA + TM_OFFSET(9, 11), TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_Status },

    { 0 }, // end
};

struct StatScreenTextInfo const gStatScreenEquipmentLabelsInfo[] =
{
    { gStatScreenSt.text + STATSCREEN_TEXT_EQUIPATTACK, gUiTmScratchA + TM_OFFSET(3,  13), TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_EquipAttack },
    { gStatScreenSt.text + STATSCREEN_TEXT_EQUIPHIT,    gUiTmScratchA + TM_OFFSET(3,  15), TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_EquipHit },
    { gStatScreenSt.text + STATSCREEN_TEXT_EQUIPRANGE,  gUiTmScratchA + TM_OFFSET(10, 11), TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_EquipRange },
    { gStatScreenSt.text + STATSCREEN_TEXT_EQUIPCRIT,   gUiTmScratchA + TM_OFFSET(10, 13), TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_EquipCrit },
    { gStatScreenSt.text + STATSCREEN_TEXT_EQUIPAVOID,  gUiTmScratchA + TM_OFFSET(10, 15), TEXT_COLOR_SYSTEM_GOLD, 0, SystemLabel_EquipAvoid },

    { 0 }, // end
};

struct StatScreenTextInfo const gStatScreenWeaponExpLabelsPhysicalInfo[] =
{
    { gStatScreenSt.text + STATSCREEN_TEXT_WEXP_A, gUiTmScratchA + TM_OFFSET(3,  1), TEXT_COLOR_SYSTEM_WHITE, 0, SystemLabel_WeaponKindSword },
    { gStatScreenSt.text + STATSCREEN_TEXT_WEXP_B, gUiTmScratchA + TM_OFFSET(3,  3), TEXT_COLOR_SYSTEM_WHITE, 0, SystemLabel_WeaponKindLance },
    { gStatScreenSt.text + STATSCREEN_TEXT_WEXP_C, gUiTmScratchA + TM_OFFSET(11, 1), TEXT_COLOR_SYSTEM_WHITE, 0, SystemLabel_WeaponKindAxe },
    { gStatScreenSt.text + STATSCREEN_TEXT_WEXP_D, gUiTmScratchA + TM_OFFSET(11, 3), TEXT_COLOR_SYSTEM_WHITE, 0, SystemLabel_WeaponKindBow },

    { 0 }, // end
};

struct StatScreenTextInfo const gStatScreenWeaponExpLabelsMagicalInfo[] =
{
    { gStatScreenSt.text + STATSCREEN_TEXT_WEXP_A, gUiTmScratchA + TM_OFFSET(3,  1), TEXT_COLOR_SYSTEM_WHITE, 0, SystemLabel_WeaponKindAnima },
    { gStatScreenSt.text + STATSCREEN_TEXT_WEXP_B, gUiTmScratchA + TM_OFFSET(3,  3), TEXT_COLOR_SYSTEM_WHITE, 0, SystemLabel_WeaponKindLight },
    { gStatScreenSt.text + STATSCREEN_TEXT_WEXP_C, gUiTmScratchA + TM_OFFSET(11, 1), TEXT_COLOR_SYSTEM_WHITE, 0, SystemLabel_WeaponKindElder },
    { gStatScreenSt.text + STATSCREEN_TEXT_WEXP_D, gUiTmScratchA + TM_OFFSET(11, 3), TEXT_COLOR_SYSTEM_WHITE, 0, SystemLabel_WeaponKindStaff },

    { 0 }, // end
};

void InitStatScreenText(void)
{
    InitTextList(gStatScreenTextList);
}

void PutStatScreenText(struct StatScreenTextInfo const * list)
{
    while (list->text != NULL)
    {
        if (list->str_list != NULL)
        {
            PutDrawText(list->text, list->tm, list->color, list->x_offset, 0, list->str_list[GetLang()]);
        }
        else
        {
            PutText(list->text, list->tm);
        }

        list++;
    }
}

void PutStatScreenLeftPanelInfo(void)
{
    char const * pname_str = DecodeMsg(gStatScreenSt.unit->pinfo->msg_name);
    int pname_text_x = GetStringTextCenteredPos(8 * 7, pname_str);

    TmFill(gBg0Tm, 0);

    BattleGenerateDisplayStats(gStatScreenSt.unit, GetUnitEquippedWeaponSlot(gStatScreenSt.unit));

    // display pname & jname

    PutDrawText(gStatScreenSt.text + STATSCREEN_TEXT_PNAME,
        gBg0Tm + TM_OFFSET(4, 10), TEXT_COLOR_SYSTEM_WHITE, pname_text_x, 0, pname_str);

    PutDrawText(gStatScreenSt.text + STATSCREEN_TEXT_JNAME,
        gBg0Tm + TM_OFFSET(1, 13), TEXT_COLOR_SYSTEM_WHITE, 0, 0, DecodeMsg(gStatScreenSt.unit->jinfo->msg_name));

    // display level, exp, hp

    PutTwoSpecialChar(gBg0Tm + TM_OFFSET(1, 15), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_LV_A, TEXT_SPECIAL_LV_B);
    PutSpecialChar(gBg0Tm + TM_OFFSET(5, 15), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_EXP_E);

    PutTwoSpecialChar(gBg0Tm + TM_OFFSET(1, 17), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_A, TEXT_SPECIAL_HP_B);
    PutSpecialChar(gBg0Tm + TM_OFFSET(5, 17), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_SLASH);

    PutNumberOrBlank(gBg0Tm + TM_OFFSET(4, 15), TEXT_COLOR_SYSTEM_BLUE, gStatScreenSt.unit->level);
    PutNumberOrBlank(gBg0Tm + TM_OFFSET(7, 15), TEXT_COLOR_SYSTEM_BLUE, gStatScreenSt.unit->exp);

    PutNumberOrBlank(gBg0Tm + TM_OFFSET(4, 17), TEXT_COLOR_SYSTEM_BLUE, GetUnitCurrentHp(gStatScreenSt.unit));
    PutNumberOrBlank(gBg0Tm + TM_OFFSET(7, 17), TEXT_COLOR_SYSTEM_BLUE, GetUnitMaxHp(gStatScreenSt.unit));
}

void PutStatScreenStatWithBar(int num, int x, int y, int base, int total, int max)
{
    int bonus = total - base;

    PutNumberOrBlank(gUiTmScratchA + TM_OFFSET(x, y),
        (base == max) ? TEXT_COLOR_SYSTEM_GREEN : TEXT_COLOR_SYSTEM_BLUE, base);

    PutNumberBonus(bonus, gUiTmScratchA + TM_OFFSET(x + 1, y));

    if (total > 30)
    {
        total = 30;
        bonus = total - base;
    }

    PutDrawUiGauge(0x400 + 1 + num*6, 6,
        gUiTmScratchC + TM_OFFSET(x - 2, y + 1),
        TILEREF(0, BGPAL_STATSCREEN_6), max * 41 / 30, base * 41 / 30, bonus * 41 / 30);
}

void PutStatScreenPersonalInfoPage(void)
{
    Decompress(gUnk_08307D58, gBuf);
    TmApplyTsa(gUiTmScratchB, gBuf, TILEREF(BGCHR_WINDOWFRAME, BGPAL_WINDOWFRAME));

    PutStatScreenText(gStatScreenPersonalInfoLabelsInfo);

    // display strength/magic labels

    if (UnitKnowsMagic(gStatScreenSt.unit))
    {
        // magic
        PutDrawText(gStatScreenSt.text + STATSCREEN_TEXT_POW,
            gUiTmScratchA + TM_OFFSET(1, 1),
            TEXT_COLOR_SYSTEM_GOLD, 0, 0,
            TEXT("魔力", "Mag"));
    }
    else
    {
        // strength
        PutDrawText(gStatScreenSt.text + STATSCREEN_TEXT_POW,
            gUiTmScratchA + TM_OFFSET(1, 1),
            TEXT_COLOR_SYSTEM_GOLD, 4, 0,
            TEXT("力", "Str"));
    }

    // display strength/magic stat value
    PutStatScreenStatWithBar(0, 5, 1,
        gStatScreenSt.unit->pow,
        GetUnitPower(gStatScreenSt.unit),
        UNIT_POW_CAP(gStatScreenSt.unit));

    // display skill stat value
    PutStatScreenStatWithBar(1, 5, 3,
        gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING
            ? gStatScreenSt.unit->skl / 2 : gStatScreenSt.unit->skl,
        GetUnitSkill(gStatScreenSt.unit),
        gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING
            ? UNIT_SKL_CAP(gStatScreenSt.unit) / 2 : UNIT_SKL_CAP(gStatScreenSt.unit));

    // display speed stat value
    PutStatScreenStatWithBar(2, 5, 5,
        gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING
            ? gStatScreenSt.unit->spd/2 : gStatScreenSt.unit->spd,
        GetUnitSpeed(gStatScreenSt.unit),
        gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING
            ? UNIT_SPD_CAP(gStatScreenSt.unit) / 2 : UNIT_SPD_CAP(gStatScreenSt.unit));

    // display luck stat value
    PutStatScreenStatWithBar(3, 5, 7,
        gStatScreenSt.unit->lck,
        GetUnitLuck(gStatScreenSt.unit),
        UNIT_LCK_CAP(gStatScreenSt.unit));

    // display defense stat value
    PutStatScreenStatWithBar(4, 5, 9,
        gStatScreenSt.unit->def,
        GetUnitDefense(gStatScreenSt.unit),
        UNIT_DEF_CAP(gStatScreenSt.unit));

    // display resistance stat value
    PutStatScreenStatWithBar(5, 5, 11,
        gStatScreenSt.unit->res,
        GetUnitResistance(gStatScreenSt.unit),
        UNIT_RES_CAP(gStatScreenSt.unit));

    // display movement stat value
    PutStatScreenStatWithBar(6, 13, 1,
        UNIT_MOV_BASE(gStatScreenSt.unit),
        UNIT_MOV(gStatScreenSt.unit),
        UNIT_MOV_CAP(gStatScreenSt.unit));

    // display constitution stat value
    PutStatScreenStatWithBar(7, 13, 3,
        UNIT_CON_BASE(gStatScreenSt.unit),
        UNIT_CON(gStatScreenSt.unit),
        UNIT_CON_CAP(gStatScreenSt.unit));

    // display unit aid
    PutNumber(gUiTmScratchA + TM_OFFSET(13, 5), TEXT_COLOR_SYSTEM_BLUE,
        GetUnitAid(gStatScreenSt.unit));

    // display unit aid icon
    PutIcon(gUiTmScratchA + TM_OFFSET(14, 5),
        GetAidIconFromAttributes(UNIT_ATTRIBUTES(gStatScreenSt.unit)),
        TILEREF(0, BGPAL_ICONS + 1));

    // display unit rescue name
    Text_InsertDrawString(gStatScreenSt.text + STATSCREEN_TEXT_RESCUE,
        24, TEXT_COLOR_SYSTEM_BLUE,
        GetUnitRescueName(gStatScreenSt.unit));

    // display status name
    Text_InsertDrawString(gStatScreenSt.text + STATSCREEN_TEXT_STATUS,
        24, TEXT_COLOR_SYSTEM_BLUE,
        GetUnitStatusName(gStatScreenSt.unit));

    // display status turns

    if (gStatScreenSt.unit->status != UNIT_STATUS_NONE)
    {
        PutNumberSmall(gUiTmScratchA + TM_OFFSET(16, 11),
            TEXT_COLOR_SYSTEM_WHITE,
            gStatScreenSt.unit->status_duration);
    }

    // display affininity icon and name

    PutIcon(gUiTmScratchA + TM_OFFSET(12, 9),
        GetUnitAffinityIcon(gStatScreenSt.unit),
        TILEREF(0, BGPAL_ICONS + 1));

    Text_InsertDrawString(gStatScreenSt.text + STATSCREEN_TEXT_AFFINITY,
        40, TEXT_COLOR_SYSTEM_BLUE, GetAffinityName(gStatScreenSt.unit->pinfo->affinity));
}

void PutStatScreenItemsPage(void)
{
    int i, item;

    Decompress(gUnk_08307DD4, gBuf);
    TmApplyTsa(gUiTmScratchB, gBuf, TILEREF(BGCHR_WINDOWFRAME, BGPAL_WINDOWFRAME));

    Decompress(gUnk_08308070, gBuf);
    TmApplyTsa(gUiTmScratchC + TM_OFFSET(1, 11), gBuf, TILEREF(BGCHR_STATSCREEN_EQUIPSTATFRAME, BGPAL_STATSCREEN_EQUIPSTATFRAME));

    PutStatScreenText(gStatScreenEquipmentLabelsInfo);

    for (i = 0; (i < ITEMSLOT_INV_COUNT) && (item = gStatScreenSt.unit->items[i]); i++)
    {
        func_fe6_08016860(gStatScreenSt.text + STATSCREEN_TEXT_ITEM_A + i,
            item, IsItemDisplayUseable(gStatScreenSt.unit, item),
            gUiTmScratchA + TM_OFFSET(1, 1 + i * 2));
    }

    i = GetUnitEquippedWeaponSlot(gStatScreenSt.unit);
    item = 0;

    if (i >= 0)
    {
        PutSpecialChar(
            gUiTmScratchA + TM_OFFSET(16, 1 + i * 2),
            0, TEXT_SPECIAL_EXP_E);

        TmApplyTsa(
            gUiTmScratchC + TM_OFFSET(1, 2 + i * 2),
            gUnk_083080AC, TILEREF(BGCHR_STATSCREEN_EQUIPSTATFRAME, BGPAL_STATSCREEN_EQUIPSTATFRAME));

        item = gStatScreenSt.unit->items[i];
    }

    PutNumberOrBlank(gUiTmScratchA + TM_OFFSET(8,  13),
        TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_attack);

    PutNumberOrBlank(gUiTmScratchA + TM_OFFSET(8,  15),
        TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_hit);

    PutNumberOrBlank(gUiTmScratchA + TM_OFFSET(15, 13),
        TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_crit);

    PutNumberOrBlank(gUiTmScratchA + TM_OFFSET(15, 15),
        TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_avoid);

    Text_InsertDrawString(gStatScreenSt.text + STATSCREEN_TEXT_EQUIPRANGE,
        16, TEXT_COLOR_SYSTEM_BLUE, GetItemRangeString(item));

    for (i = 0; i < 8; ++i)
    {
        gUiTmScratchA[TM_OFFSET(2 + i, 11)] = TILEREF(0x278 + i, BGPAL_ICONS + 1);
        gUiTmScratchA[TM_OFFSET(2 + i, 12)] = TILEREF(0x270 + i, BGPAL_ICONS + 1);
    }
}

void PutStatScreenSupportList(void)
{
    int count, i;

    int y_tm = 6;
    int line = 0;

    int text_color = GetUnitTotalSupportLevel(gStatScreenSt.unit) == MAX_SIMULTANEOUS_SUPPORT_COUNT_PER_UNIT
        ? TEXT_COLOR_SYSTEM_GREEN : TEXT_COLOR_SYSTEM_WHITE;

    for (count = GetUnitSupportCount(gStatScreenSt.unit), i = 0; i < count; i++)
    {
        int support_level = GetUnitSupportLevel(gStatScreenSt.unit, i);

        if (support_level != 0)
        {
            int rank_color;

            u8 pid = GetUnitSupportPid(gStatScreenSt.unit, i);

            PutIcon(gUiTmScratchA + TM_OFFSET(4, y_tm),
                GetAffinityIconByPid(pid),
                TILEREF(0, BGPAL_ICONS + 1));

            PutDrawText(gStatScreenSt.text + STATSCREEN_TEXT_SUPPORT_A + line,
                gUiTmScratchA + TM_OFFSET(7, y_tm),
                text_color, 0, 0, DecodeMsg(GetPInfo(pid)->msg_name));

            rank_color = TEXT_COLOR_SYSTEM_BLUE;

            if (support_level == SUPPORT_LEVEL_A)
                rank_color = TEXT_COLOR_SYSTEM_GREEN;

            if (text_color == TEXT_COLOR_SYSTEM_GREEN)
                rank_color = TEXT_COLOR_SYSTEM_GREEN;

            PutSpecialChar(gUiTmScratchA + TM_OFFSET(13, y_tm),
                rank_color, GetSupportLevelSpecialChar(support_level));

            y_tm += 2;
            line++;
        }
    }
}

void PutStatScreenWeaponExpBar(int num, int x, int y, int item_kind)
{
    int color;
    int wexp = gStatScreenSt.unit->wexp[item_kind];

    PutIcon(gUiTmScratchA + TM_OFFSET(x, y),
        0x70 + item_kind, // TODO: icon id definitions
        TILEREF(0, BGPAL_ICONS + 1));

    color = (wexp >= WEXP_S)
        ? TEXT_COLOR_SYSTEM_GREEN : TEXT_COLOR_SYSTEM_BLUE;

    // display rank letter
    PutSpecialChar(gUiTmScratchA + TM_OFFSET(x + 5, y),
        color, GetWeaponLevelSpecialCharFromExp(wexp));

    // this code makes the following assumptions
    STATIC_ASSERT(WEXP_C - WEXP_D == (WEXP_D - WEXP_E));
    STATIC_ASSERT(WEXP_B - WEXP_C == (WEXP_D - WEXP_E));
    STATIC_ASSERT(WEXP_A - WEXP_B == (WEXP_D - WEXP_E));
    STATIC_ASSERT(WEXP_S - WEXP_A == (WEXP_D - WEXP_E));

    if (wexp != WEXP_0)
        wexp -= WEXP_E;

    PutDrawUiGauge(0x400 + 1 + num * 6, 5,
        gUiTmScratchC + TM_OFFSET(x + 3, y + 1), TILEREF(0, BGPAL_STATSCREEN_6),
        34, ((wexp % (WEXP_D - WEXP_E)) * 33) / 48, 0); // math look weird but gets something that ranges from 0 to 33. I would do "((wexp % 50) * 34) / 50"
}

void PutStatScreenWeaponExpAndSupportsPage(void)
{
    Decompress(gUnk_08307E50, gBuf);
    TmApplyTsa(gUiTmScratchB, gBuf, TILEREF(BGCHR_WINDOWFRAME, BGPAL_WINDOWFRAME));

    if (UnitKnowsMagic(gStatScreenSt.unit))
    {
        PutStatScreenText(gStatScreenWeaponExpLabelsMagicalInfo);

        PutStatScreenWeaponExpBar(0, 1, 1, ITEM_KIND_ANIMA);
        PutStatScreenWeaponExpBar(1, 1, 3, ITEM_KIND_LIGHT);
        PutStatScreenWeaponExpBar(2, 9, 1, ITEM_KIND_ELDER);
        PutStatScreenWeaponExpBar(3, 9, 3, ITEM_KIND_STAFF);
    }
    else
    {
        PutStatScreenText(gStatScreenWeaponExpLabelsPhysicalInfo);

        PutStatScreenWeaponExpBar(0, 1, 1, ITEM_KIND_SWORD);
        PutStatScreenWeaponExpBar(1, 1, 3, ITEM_KIND_LANCE);
        PutStatScreenWeaponExpBar(2, 9, 1, ITEM_KIND_AXE);
        PutStatScreenWeaponExpBar(3, 9, 3, ITEM_KIND_BOW);
    }

    PutStatScreenSupportList();
}

void PutStatScreenPage(int page_id)
{
    typedef void (* PutPageFunc)(void);

    PutPageFunc func_table[4] =
    {
        PutStatScreenPersonalInfoPage,
        PutStatScreenItemsPage,
        PutStatScreenWeaponExpAndSupportsPage,
        PutStatScreenPersonalInfoPage,
    };

    CpuFastFill(0, gUiTmScratchA, sizeof(u16) * 0x20 * 20);
    CpuFastFill(0, gUiTmScratchC, sizeof(u16) * 0x20 * 18);

    func_table[page_id]();
}

struct Unit * FindNextStatScreenUnit(struct Unit * current_unit, int iter_step)
{
    int faction = UNIT_FACTION(current_unit);
    int i = current_unit->id;

    struct Unit * unit;

    while (TRUE)
    {
        i = (i + iter_step) & 0x3F;

        unit = GetUnit(faction + i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        STATIC_ASSERT(sizeof(gStatScreenInfo.excluded_unit_flags) == sizeof(unit->flags));

        if ((unit->flags & gStatScreenInfo.excluded_unit_flags) != 0)
            continue;

        return unit;
    }
}

i8 CONST_DATA gStatScreenPageSlideOffsetLut[] =
{
    // transition page out
    -4, -7, -10, -12, -14,

    INT8_MAX, // draw new page

    // transition page in
    13, 9, 7, 5, 3, 2, 1, 0,

    INT8_MIN, // end
};

void StatScreenPageSlide_Loop(struct StatScreenPageSlideProc * proc)
{
    int off;
    int len, dst_offset, src_offset;

    // clear page frame on bg0, bg1, bg2
    TmFillRect(gBg0Tm + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y), 18, 18, 0);
    TmFillRect(gBg1Tm + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y), 18, 18, 0);
    TmFillRect(gBg2Tm + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y), 18, 18, 0);

    off = gStatScreenPageSlideOffsetLut[proc->clock];

    if (off == INT8_MAX)
    {
        // INT8_MAX offset means switch to displaying next page

        PutStatScreenPage(proc->new_page);

        proc->clock++;
        off = gStatScreenPageSlideOffsetLut[proc->clock];
    }

    // compute len, dst_offset and src_offset
    // len is the length of the display bit of the page
    // dst_offset is the x offset to which to copy the page to
    // src_offset is the x offset from which to copy the page from

    if (proc->key_bit & KEY_DPAD_LEFT)
        off = -off;

    len = 18 - abs(off);

    if (off < 0)
    {
        dst_offset = 0;
        src_offset = -off;
    }
    else
    {
        dst_offset = off;
        src_offset = 0;
    }

    TmCopyRect(gUiTmScratchA + src_offset,
        gBg0Tm + dst_offset + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y),
        len, 18);

    TmCopyRect(gUiTmScratchB + src_offset,
        gBg1Tm + dst_offset + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y),
        len, 18);

    TmCopyRect(gUiTmScratchC + src_offset,
        gBg2Tm + dst_offset + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y),
        len, 18);

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT + BG2_SYNC_BIT);

    proc->clock++;
    off = gStatScreenPageSlideOffsetLut[proc->clock];

    if (off == INT8_MIN)
        Proc_Break(proc);
}

void StatScreenPageSlide_End(struct StatScreenPageSlideProc * proc)
{
    gStatScreenSt.is_transitioning = FALSE;
}

struct ProcScr CONST_DATA ProcScr_StatScreenPageSlide[] =
{
    PROC_REPEAT(StatScreenPageSlide_Loop),
    PROC_CALL(StatScreenPageSlide_End),
    PROC_END,
};

void StartStatScreenPageSlide(fu16 key_bit, int new_page, ProcPtr parent)
{
    struct StatScreenPageSlideProc * proc;

    if (FindProc(ProcScr_StatScreenPageSlide) != NULL)
        return;

    PlaySe(SONG_6F);

    proc = SpawnProcLocking(ProcScr_StatScreenPageSlide, parent);

    proc->clock = 0;
    proc->new_page = new_page;
    proc->key_bit = key_bit;

    gStatScreenSt.page_slide_key_bit = key_bit;
    gStatScreenSt.help = NULL;
    gStatScreenSt.is_transitioning = TRUE;
}

void StatScreenUnitSlide_FadeOutInit(struct StatScreenUnitSlideProc * proc)
{
    gStatScreenSt.is_transitioning = TRUE;

    proc->clock = 4;

    // TODO: macro?
    gDispIo.bg0_ct.priority = 1;
    gDispIo.bg1_ct.priority = 3;
    gDispIo.bg2_ct.priority = 2;
    gDispIo.bg3_ct.priority = 0;

    SetBlendTargetA(0, 0, 0, 1, 0);
    SetBlendTargetB(1, 1, 1, 0, 1); SetBlendBackdropB(0);

    if (proc->direction > 0)
    {
        proc->y_disp_init = 0;
        proc->y_disp_fini = -60;
    }
    else
    {
        proc->y_disp_init = 0;
        proc->y_disp_fini = +60;
    }
}

void StatScreenUnitSlide_FadeOutLoop(struct StatScreenUnitSlideProc * proc)
{
    enum { CLOCK_STEP = 3, CLOCK_END = 0x10 };

    SetBlendAlpha(proc->clock * 0x10 / CLOCK_END, (CLOCK_END - proc->clock) * 0x10 / CLOCK_END);

    SetMuScreenPosition(gStatScreenSt.mu, 80, 138 + gStatScreenSt.y_disp_off);

    gStatScreenSt.y_disp_off = Interpolate(INTERPOLATE_CUBIC, proc->y_disp_init, proc->y_disp_fini, proc->clock, CLOCK_END);

    proc->clock += CLOCK_STEP;

    if (proc->clock > CLOCK_END)
        Proc_Break(proc);
}

void StatScreenUnitSlide_FadeInInit(struct StatScreenUnitSlideProc * proc)
{
    proc->clock = 1;

    // TODO: macro?
    gDispIo.bg0_ct.priority = 1;
    gDispIo.bg1_ct.priority = 3;
    gDispIo.bg2_ct.priority = 2;
    gDispIo.bg3_ct.priority = 0;

    SetBlendTargetA(0, 0, 0, 1, 0);
    SetBlendTargetB(1, 1, 1, 0, 1);

    if (proc->direction > 0)
    {
        proc->y_disp_init = +60;
        proc->y_disp_fini = 0;
    }
    else
    {
        proc->y_disp_init = -60;
        proc->y_disp_fini = 0;
    }
}

void StatScreenUnitSlide_FadeInLoop(struct StatScreenUnitSlideProc * proc)
{
    enum { CLOCK_STEP = 3, CLOCK_END = 0x10 };

    SetBlendAlpha((CLOCK_END - proc->clock) * 0x10 / CLOCK_END, proc->clock * 0x10 / CLOCK_END);

    SetMuScreenPosition(gStatScreenSt.mu, 80, 138 + gStatScreenSt.y_disp_off);

    gStatScreenSt.y_disp_off = Interpolate(INTERPOLATE_RCUBIC, proc->y_disp_init, proc->y_disp_fini, proc->clock, CLOCK_END);

    proc->clock += CLOCK_STEP;

    if (proc->clock >= CLOCK_END)
        Proc_Break(proc);
}

void StatScreenUnitSlide_ChangeUnit(struct StatScreenUnitSlideProc * proc)
{
    gStatScreenSt.unit = GetUnit(proc->new_unit_id);
    StatScreen_InitUnit(NULL);
    Proc_Break(proc);
}

void StatScreenUnitSlide_End(struct StatScreenUnitSlideProc * proc)
{
    if (gStatScreenSt.mu != NULL)
    {
        SetMuScreenPosition(gStatScreenSt.mu, 80, 138);
    }

    // TODO: macro?
    gDispIo.bg0_ct.priority = 1;
    gDispIo.bg1_ct.priority = 3;
    gDispIo.bg2_ct.priority = 2;
    gDispIo.bg3_ct.priority = 3;

    SetBlendTargetA(0, 0, 1, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 0);
    SetBlendAlpha(6, 8);

    gStatScreenSt.is_transitioning = FALSE;
}

struct ProcScr CONST_DATA ProcScr_StatScreenUnitSlide[] =
{
    PROC_YIELD,
    PROC_CALL(StatScreenUnitSlide_FadeOutInit),
    PROC_REPEAT(StatScreenUnitSlide_FadeOutLoop),
    PROC_CALL(StatScreenUnitSlide_ChangeUnit),
    PROC_CALL(StatScreenUnitSlide_FadeInInit),
    PROC_REPEAT(StatScreenUnitSlide_FadeInLoop),
    PROC_CALL(StatScreenUnitSlide_End),
    PROC_END,
};

void StartStatScreenUnitSlide(struct Unit * unit, int direction, ProcPtr parent)
{
    struct StatScreenUnitSlideProc * proc;

    proc = SpawnProcLocking(ProcScr_StatScreenUnitSlide, parent);

    proc->new_unit_id = unit->id;
    proc->direction = direction;

    PlaySe(SONG_C8);
}

u16 CONST_DATA Sprite_StatScreenPageName[] =
{
    3,
    OAM0_SHAPE_32x16 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x16 + OAM1_X(0)  + OAM1_AFFINE_ID(8), OAM2_CHR(0),
    OAM0_SHAPE_32x16 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x16 + OAM1_X(32) + OAM1_AFFINE_ID(8), OAM2_CHR(4),
    OAM0_SHAPE_32x16 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x16 + OAM1_X(64) + OAM1_AFFINE_ID(8), OAM2_CHR(8),
};

u16 CONST_DATA gStatScreenPageNameChrOffsetLut[] =
{
    OAM2_CHR(0x14),
    OAM2_CHR(0x08),
    OAM2_CHR(0x54),
};

void PutUpdateStatScreenPageName(int page_id)
{
    int color_num;

    PutSprite(4,
        105 + gStatScreenSt.x_disp_off,
        5 + gStatScreenSt.y_disp_off,
        Sprite_StatScreenPageName,
        OAM2_CHR(OBCHR_STATSCREEN_240) + OAM2_PAL(OBPAL_STATSCREEN_PAGENAME) + gStatScreenPageNameChrOffsetLut[page_id] + OAM2_LAYER(3));

    color_num = (GetGameTime() / 4) % 16;

    CpuCopy16(
        Pal_Unk_083087C8[page_id] + color_num,
        gPal + (0x10 + OBPAL_STATSCREEN_PAGENAME) * 0x10 + 4,
        sizeof(u16) * 11);

    EnablePalSync();
}

enum { STATSCREEN_PAGE_NAME_SCALE_STEPS = 6 };

void StatScreenPageName_Init(struct StatScreenSpritesProc * proc)
{
    SetObjAffineAuto(8, 0, 0x100, 0x100);
    proc->page_id = gStatScreenSt.page;
}

void StatScreenPageName_Main(struct StatScreenSpritesProc * proc)
{
    PutUpdateStatScreenPageName(proc->page_id);

    if (gStatScreenSt.page_slide_key_bit != 0)
    {
        proc->vertical_scale = STATSCREEN_PAGE_NAME_SCALE_STEPS - 1;
        Proc_Break(proc);
        return;
    }

    proc->page_id = gStatScreenSt.page;
}

void StatScreenPageName_CloseMain(struct StatScreenSpritesProc * proc)
{
    SetObjAffineAuto(8, 0, 0x100, proc->vertical_scale * 0x100 / STATSCREEN_PAGE_NAME_SCALE_STEPS);
    PutUpdateStatScreenPageName(proc->page_id);

    proc->vertical_scale--;

    if (proc->vertical_scale == 0)
    {
        proc->vertical_scale = 1;
        Proc_Break(proc);
    }
}

void StatScreenPageName_OpenMain(struct StatScreenSpritesProc * proc)
{
    SetObjAffineAuto(8, 0, 0x100, proc->vertical_scale * 0x100 / STATSCREEN_PAGE_NAME_SCALE_STEPS);
    PutUpdateStatScreenPageName(gStatScreenSt.page);

    proc->vertical_scale++;

    if (proc->vertical_scale > STATSCREEN_PAGE_NAME_SCALE_STEPS)
    {
        proc->page_id = gStatScreenSt.page;
        Proc_Break(proc);
    }
}

struct ProcScr CONST_DATA ProcScr_StatScreenPageName[] =
{
    PROC_CALL(StatScreenPageName_Init),

PROC_LABEL(0),
    PROC_REPEAT(StatScreenPageName_Main),

    PROC_REPEAT(StatScreenPageName_CloseMain),
    PROC_SLEEP(1),
    PROC_REPEAT(StatScreenPageName_OpenMain),

    PROC_GOTO(0),

    PROC_END,
};

void StatScreenSprites_Init(struct StatScreenSpritesProc * proc)
{
    proc->x_left = 101;
    proc->x_right = 198;
    proc->clock_right = 0;
    proc->clock_left = 0;
    proc->anim_speed_right = 4;
    proc->anim_speed_left = 4;
}

void StatScreenSprites_BumpCheck(struct StatScreenSpritesProc * proc)
{
    if (gStatScreenSt.page_slide_key_bit & KEY_DPAD_LEFT)
    {
        proc->anim_speed_left = 31;
        proc->x_left = 101 - 6;
    }

    if (gStatScreenSt.page_slide_key_bit & KEY_DPAD_RIGHT)
    {
        proc->anim_speed_right = 31;
        proc->x_right = 198 + 6;
    }

    gStatScreenSt.page_slide_key_bit = 0;
}

void StatScreenSprites_PutArrows(struct StatScreenSpritesProc * proc)
{
    int base_oam2 = OAM2_CHR(OBCHR_STATSCREEN_240) + OAM2_PAL(OBPAL_STATSCREEN_SPRITES) + OAM2_LAYER(3);

    proc->clock_left += proc->anim_speed_left;
    proc->clock_right += proc->anim_speed_right;

    if (proc->anim_speed_left > 4)
        proc->anim_speed_left--;

    if (proc->anim_speed_right > 4)
        proc->anim_speed_right--;

    if ((GetGameTime() % 4) == 0)
    {
        if (proc->x_left < 101)
            proc->x_left++;

        if (proc->x_right > 198)
            proc->x_right--;
    }

    PutSprite(
        4, gStatScreenSt.x_disp_off + proc->x_left,
        gStatScreenSt.y_disp_off + 6, Sprite_8x16,
        base_oam2 + 0x4A + (proc->clock_left >> 5) % 6);

    PutSprite(
        4, gStatScreenSt.x_disp_off + proc->x_right,
        gStatScreenSt.y_disp_off + 6, Sprite_8x16_HFlipped,
        base_oam2 + 0x4A + (proc->clock_right >> 5) % 6);
}

void StatScreenSprites_PutNumberLabel(struct StatScreenSpritesProc * proc)
{
    enum
    {
        PAGENUM_X = 214,
        PAGENUM_Y = 12
    };

    // page amt
    PutSprite(
        2, gStatScreenSt.x_disp_off + PAGENUM_X + 13,
        gStatScreenSt.y_disp_off + PAGENUM_Y, Sprite_8x8,
        OAM2_CHR(OBCHR_STATSCREEN_240 + 0x64) + OAM2_PAL(OBPAL_STATSCREEN_SPRITES) +
            OAM2_LAYER(3) + gStatScreenSt.page_count);

    // '/'
    PutSprite(
        2, gStatScreenSt.x_disp_off + PAGENUM_X + 7,
        gStatScreenSt.y_disp_off + PAGENUM_Y, Sprite_8x8,
        OAM2_CHR(OBCHR_STATSCREEN_240 + 0x05) + OAM2_PAL(OBPAL_STATSCREEN_SPRITES) +
            OAM2_LAYER(3));

    // page num
    PutSprite(
        2, gStatScreenSt.x_disp_off + PAGENUM_X,
        gStatScreenSt.y_disp_off + PAGENUM_Y, Sprite_8x8,
        OAM2_CHR(OBCHR_STATSCREEN_240 + 0x64) + OAM2_PAL(OBPAL_STATSCREEN_SPRITES) +
            OAM2_LAYER(3) + gStatScreenSt.page + 1);
}

u16 CONST_DATA Sprite_StatScreenMuAreaBackground[] =
{
    12,
    OAM0_SHAPE_32x8  + OAM0_Y(128) + OAM0_BLEND, OAM1_SIZE_32x8  + OAM1_X(8), OAM2_CHR(0x45),
    OAM0_SHAPE_32x8  + OAM0_Y(128) + OAM0_BLEND, OAM1_SIZE_32x8  + OAM1_X(32), OAM2_CHR(0x46),
    OAM0_SHAPE_32x8  + OAM0_Y(144) + OAM0_BLEND, OAM1_SIZE_32x8  + OAM1_X(8), OAM2_CHR(0x45),
    OAM0_SHAPE_32x8  + OAM0_Y(144) + OAM0_BLEND, OAM1_SIZE_32x8  + OAM1_X(32), OAM2_CHR(0x46),
    OAM0_SHAPE_32x32 + OAM0_Y(104) + OAM0_BLEND, OAM1_SIZE_32x32, 0,
    OAM0_SHAPE_32x32 + OAM0_Y(104) + OAM0_BLEND, OAM1_SIZE_32x32 + OAM1_X(32), 0,
    OAM0_SHAPE_32x32 + OAM0_Y(104) + OAM0_BLEND, OAM1_SIZE_32x32 + OAM1_X(64), 0,
    OAM0_SHAPE_32x32 + OAM0_Y(120) + OAM0_BLEND, OAM1_SIZE_32x32, 0,
    OAM0_SHAPE_32x32 + OAM0_Y(120) + OAM0_BLEND, OAM1_SIZE_32x32 + OAM1_X(32), 0,
    OAM0_SHAPE_32x32 + OAM0_Y(120) + OAM0_BLEND, OAM1_SIZE_32x32 + OAM1_X(64), 0,
    OAM0_SHAPE_8x32  + OAM0_Y(104) + OAM0_BLEND, OAM1_SIZE_8x32  + OAM1_X(96), OAM2_CHR(0x4),
    OAM0_SHAPE_8x32  + OAM0_Y(120) + OAM0_BLEND, OAM1_SIZE_8x32  + OAM1_X(96) + OAM1_VFLIP, OAM2_CHR(0x4),
};

void StatScreenSprites_PutMuAreaSprites(struct StatScreenSpritesProc * proc)
{
    PutSprite(12,
        gStatScreenSt.x_disp_off,
        gStatScreenSt.y_disp_off,
        Sprite_StatScreenMuAreaBackground,
        OAM2_CHR(OBCHR_STATSCREEN_240 + 0x00) + OAM2_PAL(OBPAL_STATSCREEN_WINDOWFRAME) + OAM2_LAYER(3));

    PutSprite(11,
        gStatScreenSt.x_disp_off + 64,
        gStatScreenSt.y_disp_off + 131,
        Sprite_32x16,
        OAM2_CHR(OBCHR_STATSCREEN_240 + 0x50) + OAM2_PAL(OBPAL_STATSCREEN_SPRITES) + OAM2_LAYER(3));
}

void StatScreenSprites_PutRescueMarkers(struct StatScreenSpritesProc * proc)
{
    bool display_icon = (GetGameTime() % 32) < 20;

    SHOULD_BE_STATIC u16 SHOULD_BE_CONST pal_lut[3] =
    {
        OBPAL_UNITSPRITE_BLUE,
        OBPAL_UNITSPRITE_GREEN,
        OBPAL_UNITSPRITE_RED,
    };

    if (!gStatScreenSt.is_transitioning)
    {
        if ((gStatScreenSt.page == STATSCREEN_PAGE_PERSONALINFO) && (gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING))
        {
            PutSysArrow(120, 40, TRUE);
            PutSysArrow(120, 56, TRUE);

            if (display_icon)
            {
                PutSprite(4,
                    184, 78, Sprite_8x8,
                    OAM2_CHR(3) + OAM2_PAL(pal_lut[gStatScreenSt.unit->rescue >> 6]) + OAM2_LAYER(2));
            }
        }

        if (gStatScreenSt.unit->flags & UNIT_FLAG_RESCUED)
        {
            if (display_icon)
            {
                PutSprite(4,
                    32, 86, Sprite_8x8,
                    OAM2_CHR(3) + OAM2_PAL(pal_lut[gStatScreenSt.unit->rescue >> 6]) + OAM2_LAYER(2));
            }
        }
    }
}

struct ProcScr CONST_DATA ProcScr_StatScreenSprites[] =
{
    PROC_CALL(StatScreenSprites_Init),

PROC_LABEL(0),
    PROC_YIELD,

    PROC_CALL(StatScreenSprites_BumpCheck),
    PROC_CALL(StatScreenSprites_PutArrows),
    PROC_CALL(StatScreenSprites_PutNumberLabel),
    PROC_CALL(StatScreenSprites_PutMuAreaSprites),
    PROC_CALL(StatScreenSprites_PutRescueMarkers),

    PROC_GOTO(0),

    PROC_END,
};

void StatScreen_DisableScreen(ProcPtr proc)
{
    SetDispEnable(0, 0, 0, 0, 0);
    SetBlendDarken(0x10);
    SetBlendTargetA(0, 0, 0, 0, 0);
    SetBlendBackdropA(1);
    SetBackdropColor(0);
}

void StatScreen_Init(ProcPtr proc)
{
    SHOULD_BE_STATIC u16 SHOULD_BE_CONST bg_config[12] =
    {
        0x0000, 0x6000, 0,
        0x0000, 0x6800, 0,
        0x8000, 0x7000, 0,
        0x8000, 0x7800, 0,
    };

    InitBgs(bg_config);

    SetBlankChr(0x400);
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    ApplySystemGraphics();
    ApplyUnitSpritePalettes();

    StartMuralBackground(NULL, ((void *) VRAM) + 0x8000 + BGCHR_STATSCREEN_BACKMURAL * CHR_SIZE, -1);

    Decompress(gUnk_083080D0, ((void *) VRAM + 0x10000) + OBCHR_STATSCREEN_240 * CHR_SIZE);

    ApplyIconPalettes(BGPAL_ICONS);
    ApplyUiStatBarPal(BGPAL_STATSCREEN_6);
    ApplyIconPalette(1, 0x10 + OBPAL_STATSCREEN_PAGENAME);

    Decompress(gUnk_08307CEC, gBuf);
    TmApplyTsa(gBg1Tm, gBuf, TILEREF(BGCHR_WINDOWFRAME, BGPAL_WINDOWFRAME));

    Decompress(gUnk_08307ED4, ((void *) VRAM) + 0x8000 + BGCHR_STATSCREEN_EQUIPSTATFRAME * CHR_SIZE);
    ApplyPalette(gUnk_08308050, BGPAL_STATSCREEN_EQUIPSTATFRAME);

    CpuFastCopy(gPal + 0x10 * BGPAL_WINDOWFRAME, gPal + 0x100 + 0x10 * OBPAL_STATSCREEN_WINDOWFRAME, 0x20);

    ApplyIconPalette(1, 0x10 + OBPAL_STATSCREEN_SPRITES);

    Decompress(gUnk_08308920, ((void *) VRAM) + BGCHR_STATSCREEN_EQUIPMENTLABEL * CHR_SIZE);

    gStatScreenSt.mu = NULL;

    StatScreenUnitSlide_End(proc);
}

void StatScreen_InitUnit(ProcPtr proc)
{
    if (UNIT_FACTION(gStatScreenSt.unit) == FACTION_BLUE || (gBmSt.flags & BM_FLAG_LINKARENA))
    {
        gStatScreenSt.page_count = 3;
    }
    else
    {
        gStatScreenSt.page_count = 2;

        if (gStatScreenSt.page == 2)
            gStatScreenSt.page = 1;
    }

    ResetText();
    InitIcons();
    InitStatScreenText();

    PutFace80x72(gBg2Tm + TM_OFFSET(1, 1),
        GetUnitFid(gStatScreenSt.unit),
        0x400 + BGCHR_STATSCREEN_FACE, BGPAL_STATSCREEN_FACE);

    EndAllMus();
    gStatScreenSt.mu = StartUiMu(gStatScreenSt.unit, 80, 138);

    PutStatScreenLeftPanelInfo();
    PutStatScreenPage(gStatScreenSt.page);

    TmCopyRect(gUiTmScratchA,
        gBg0Tm + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y),
        18, 18);

    TmCopyRect(gUiTmScratchB,
        gBg1Tm + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y),
        18, 18);

    TmCopyRect(gUiTmScratchC,
        gBg2Tm + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y),
        18, 18);

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT + BG2_SYNC_BIT);
}

void StatScreen_Main(ProcPtr proc)
{
    struct Unit * unit;

    if (gKeySt->pressed & KEY_BUTTON_B)
    {
        SetDispEnable(0, 0, 0, 0, 0);
        SetBlendDarken(0x10);
        SetBlendTargetA(0, 0, 0, 0, 0);
        SetBlendBackdropA(1);
        SetBackdropColor(0);

        Proc_Break(proc);

        PlaySe(SONG_6B);
    }

    else if (gKeySt->repeated & KEY_DPAD_LEFT)
    {
        gStatScreenSt.page = (gStatScreenSt.page + gStatScreenSt.page_count - 1) % gStatScreenSt.page_count;
        StartStatScreenPageSlide(KEY_DPAD_LEFT, gStatScreenSt.page, proc);
        return;
    }

    else if (gKeySt->repeated & KEY_DPAD_RIGHT)
    {
        gStatScreenSt.page = (gStatScreenSt.page + gStatScreenSt.page_count + 1) % gStatScreenSt.page_count;
        StartStatScreenPageSlide(KEY_DPAD_RIGHT, gStatScreenSt.page, proc);
    }

    else if (gKeySt->repeated & KEY_DPAD_UP)
    {
        unit = FindNextStatScreenUnit(gStatScreenSt.unit, -1);
        StartStatScreenUnitSlide(unit, -1, proc);
    }

    else if (gKeySt->repeated & KEY_DPAD_DOWN)
    {
        unit = FindNextStatScreenUnit(gStatScreenSt.unit, +1);
        StartStatScreenUnitSlide(unit, +1, proc);
    }

    else if ((gKeySt->repeated & KEY_BUTTON_A) && (gStatScreenSt.unit->rescue != 0))
    {
        unit = GetUnit(gStatScreenSt.unit->rescue);
        StartStatScreenUnitSlide(unit, (gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING) ? +1 : -1, proc);
    }

    else if (gKeySt->pressed & KEY_BUTTON_R)
    {
        Proc_Goto(proc, 0); // goto help idle
        StartStatScreenHelp(gStatScreenSt.page, proc);
    }
}

void StatScreen_BackUpStatus(ProcPtr proc)
{
    gPlaySt.flags = (gPlaySt.flags & ~PLAY_FLAG_STATSCREENPAGE_MASK) | (gStatScreenSt.page & PLAY_FLAG_STATSCREENPAGE_MASK);
    gStatScreenInfo.unit_id = gStatScreenSt.unit->id;
    SetOnVMatch(NULL);
}

void StatScreen_UpdateLastHelpInfo(ProcPtr proc)
{
    gStatScreenSt.help = GetLastHelpBoxInfo();
}

void SyncStatScreenBgOffset(void)
{
    int y_bg = 0xFF & -gStatScreenSt.y_disp_off;

    SetBgOffset(0, 0, y_bg);
    SetBgOffset(1, 0, y_bg);
    SetBgOffset(2, 0, y_bg);
}

struct ProcScr CONST_DATA ProcScr_SyncStatScreenBgOffset[] =
{
    PROC_REPEAT(SyncStatScreenBgOffset),
    PROC_END,
};

void StatScreen_CleanUp(ProcPtr proc)
{
    EndMuralBackground();
}

struct ProcScr CONST_DATA ProcScr_StatScreen[] =
{
    PROC_ONEND(StatScreen_CleanUp),

    PROC_CALL(StatScreen_DisableScreen),
    PROC_CALL(LockBmDisplay),
    PROC_SLEEP(1),

    PROC_CALL(StatScreen_Init),
    PROC_CALL(StartGreenText),
    PROC_CALL(StatScreen_InitUnit),

    PROC_START_CHILD(ProcScr_StatScreenPageName),
    PROC_START_CHILD(ProcScr_StatScreenSprites),
    PROC_START_CHILD(ProcScr_SyncStatScreenBgOffset),

    PROC_GOTO(1),

PROC_LABEL(0),
    PROC_CALL(StatScreen_UpdateLastHelpInfo),

PROC_LABEL(1),
    PROC_REPEAT(StatScreen_Main),

    PROC_CALL(StatScreen_BackUpStatus),
    PROC_CALL(UnlockBmDisplay),
    PROC_CALL(EndAllMus),
    PROC_CALL(EndGreenText),
    PROC_END,
};

void StartStatScreen(struct Unit * unit, ProcPtr parent)
{
    gStatScreenSt.x_disp_off = 0;
    gStatScreenSt.y_disp_off = 0;
    gStatScreenSt.page = (gPlaySt.flags >> PLAY_FLAG_STATSCREENPAGE_SHIFT) & PLAY_FLAG_STATSCREENPAGE_MASK;
    gStatScreenSt.unit = unit;
    gStatScreenSt.help = NULL;
    gStatScreenSt.page_slide_key_bit = 0;
    gStatScreenSt.is_transitioning = FALSE;

    PidStatsAddStatView(unit->pinfo->id);

    PlaySe(SONG_6A);

    SpawnProcLocking(ProcScr_StatScreen, parent);
}

void StartStatScreenHelp(int page_id, ProcPtr proc)
{
    LoadHelpBoxGfx(NULL, -1);

    if (gStatScreenSt.help == NULL)
    {
        switch (page_id)
        {

        case STATSCREEN_PAGE_PERSONALINFO:
            gStatScreenSt.help = &HelpInfo_StatScreenPersonalInfo_Pow;
            break;
        
        case STATSCREEN_PAGE_ITEMS:
            gStatScreenSt.help = &HelpInfo_StatScreenItems_ItemA;
            break;

        case STATSCREEN_PAGE_WEXPANDSUPPORTS:
            gStatScreenSt.help = &HelpInfo_StatScreenWeaponExp_WExpA;
            break;

        }
    }

    StartMovingHelpBox(gStatScreenSt.help, proc);
}

void HelpBoxPopulateStatScreenItem(struct HelpBoxProc * proc)
{
    int item = gStatScreenSt.unit->items[proc->info->msg];

    proc->item = item;
    proc->msg = GetItemDescMsg(item);
}

void HelpBoxPopulateStatScreenStatus(struct HelpBoxProc * proc)
{
    switch (gStatScreenSt.unit->status)
    {

    case UNIT_STATUS_NONE:
        proc->msg = MSG_5A8;
        break;

    case UNIT_STATUS_POISON:
        proc->msg = MSG_5A9;
        break;

    case UNIT_STATUS_SLEEP:
        proc->msg = MSG_5AA;
        break;

    case UNIT_STATUS_SILENCED:
        proc->msg = MSG_5AC;
        break;

    case UNIT_STATUS_BERSERK:
        proc->msg = MSG_5AB;
        break;

    }
}

void HelpBoxPopulateStatScreenPower(struct HelpBoxProc * proc)
{
    if (UnitKnowsMagic(gStatScreenSt.unit))
        proc->msg = MSG_59D;
    else
        proc->msg = MSG_59C;
}

void HelpBoxRedirectStatScreenItem(struct HelpBoxProc * proc)
{
    if (gStatScreenSt.unit->items[0] == 0)
        HelpBoxTryRelocateLeft(proc);

    if (gStatScreenSt.unit->items[proc->info->msg] == 0)
    {
        if (proc->move_key_bit == 0 || proc->move_key_bit == KEY_DPAD_RIGHT || proc->move_key_bit == KEY_DPAD_UP)
            HelpBoxTryRelocateUp(proc);
        else if (proc->move_key_bit == KEY_DPAD_DOWN)
            HelpBoxTryRelocateDown(proc);
    }
}

void HelpBoxPopulateStatScreenWeaponExp(struct HelpBoxProc * proc)
{
    SHOULD_BE_STATIC u16 SHOULD_BE_CONST item_kind_msg_lut[] =
    {
        [ITEM_KIND_SWORD] = MSG_62D,
        [ITEM_KIND_LANCE] = MSG_62E,
        [ITEM_KIND_AXE] = MSG_62F,
        [ITEM_KIND_BOW] = MSG_630,
        [ITEM_KIND_STAFF] = MSG_632,
        [ITEM_KIND_ANIMA] = MSG_633,
        [ITEM_KIND_LIGHT] = MSG_634,
        [ITEM_KIND_ELDER] = MSG_631,
    };

    int item_kind = proc->info->msg;

    if (UnitKnowsMagic(gStatScreenSt.unit))
        item_kind += 4;

    proc->msg = item_kind_msg_lut[item_kind];
}

void HelpBoxPopulateStatScreenPInfo(struct HelpBoxProc * proc)
{
    int msg_desc = gStatScreenSt.unit->pinfo->msg_desc;

    if (msg_desc != 0)
        proc->msg = msg_desc;
    else
        proc->msg = MSG_66D;
}

void HelpBoxPopulateStatScreenJInfo(struct HelpBoxProc * proc)
{
    proc->msg = gStatScreenSt.unit->jinfo->msg_desc;
}

void HelpBoxRedirectStatScreenSupports(struct HelpBoxProc * proc)
{
    if (GetUnitTotalSupportLevel(gStatScreenSt.unit) == 0)
    {
        if (proc->move_key_bit == KEY_DPAD_DOWN)
            HelpBoxTryRelocateDown(proc);
        else
            HelpBoxTryRelocateUp(proc);
    }
}
