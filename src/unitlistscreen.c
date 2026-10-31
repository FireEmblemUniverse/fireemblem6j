#include "unitlistscreen.h"

#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "icon.h"
#include "sprite.h"
#include "event.h"
#include "msg.h"
#include "util.h"
#include "item.h"
#include "unit.h"
#include "battle.h"
#include "bmio.h"
#include "chapter.h"
#include "support.h"
#include "faction.h"
#include "unitsprite.h"
#include "unitrearrange.h"
#include "ui.h"
#include "mu.h"
#include "statscreen.h"
#include "helpbox.h"
#include "prepscreen.h"

#include "constants/icons.h"
#include "constants/msg.h"
#include "constants/songs.h"
#include "constants/pids.h"

#include "constants/videoalloc_global.h"

// TODO: fix nonmatches

EWRAM_OVERLAY(0) struct SortedUnitEnt gSortedUnitsBuf[0x40] = {};
EWRAM_OVERLAY(0) struct SortedUnitEnt *gSortedUnits[0x40] = {};
EWRAM_OVERLAY(0) u8 gUnitListCount = 0;
EWRAM_OVERLAY(0) u16 gUnitListRowsTmBuf[0x20][0x20] = {};
EWRAM_OVERLAY(0) u16 gUnitListHeaderTmBuf[2][0x20] = {};
EWRAM_OVERLAY(0) struct Text gUnitListNameTexts[7] = {};
EWRAM_OVERLAY(0) struct Text gUnitListFieldTexts[7][3] = {};
EWRAM_OVERLAY(0) struct Text gUnitListNameLabelText = {};
EWRAM_OVERLAY(0) struct Text gUnitListFieldLabelText = {};
EWRAM_OVERLAY(0) struct Text gUnitListSortKeyText = {};
EWRAM_OVERLAY(0) u8 gUnitRearrangeBuf[0x1000] = {};
EWRAM_OVERLAY(0) u32 gUnitListItemIcons[8] = {};

void func_fe6_080741EC(void)
{
    int i;

    UnitRearrangeInit((void *)gUnitRearrangeBuf);

    for (i = 0; i < gUnitListCount; i++)
    {
        UnitRearrangeAdd(gSortedUnits[i]->unit);
    }

    for (i = 1; i < 0x40; i++)
    {
        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if ((unit->flags & UNIT_FLAG_DEAD) == 0)
            continue;

        UnitRearrangeAdd(unit);
    }

    UnitRearrangeApply();
}

void func_fe6_08074254(fu8 x, fu8 y, fu8 width)
{
    int i;

    PutSpriteExt(0x0D, x, y, gUnk_08678744[0], OAM2_PAL(5));

    for (i = 0; i < width - 1; i++)
    {
        PutSpriteExt(0x0D, x + i * 16 + 8, y, gUnk_08678744[1], OAM2_PAL(5));
    }

    PutSpriteExt(0x0D, x + i * 16 + 8, y, gUnk_08678744[2], OAM2_PAL(5));
}

void func_fe6_080742D0(fu8 sort_key)
{
    int i, j;

    TmFillRect(gBg2Tm + 0x34, 4, 1, 0);

    ClearText(&gUnitListSortKeyText);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (UnitListPageFields[i][j].sort_key == sort_key)
            {
                if (i == 5 && j != 0)
                {
                    PutIcon(gBg2Tm + 0x34, ICON_ITEM_KIND_BASE + j - 1, 0xA0 << 7);
                }
                else
                {
                    Text_SetCursor(&gUnitListSortKeyText, 0);
                    Text_SetColor(&gUnitListSortKeyText, TEXT_COLOR_SYSTEM_WHITE);
                    Text_DrawString(&gUnitListSortKeyText, UnitListPageFields[i][j].label_string);
                    PutText(&gUnitListSortKeyText, gBg2Tm + 0x34);
                }

                break;
            }
        }
    }

    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_08074384(int arg_0)
{
    fu8 i;

    for (i = 0; i < 8; i++)
    {
        if (gUnitListItemIcons[i] == arg_0)
            return;
    }

    for (i = 0; i < 8; i++)
    {
        if (gUnitListItemIcons[i] == UINT8_MAX)
        {
            gUnitListItemIcons[i] = arg_0;
            return;
        }
    }
}

void func_fe6_080743C8(fu16 arg_0)
{
    int icons_to_display[10];
    fu8 i, j;

    fu8 offset = arg_0 / 16;

    for (i = 0; i < 8; i++)
    {
        icons_to_display[i] = UINT8_MAX;
    }

    if (offset != 0)
        offset = offset - 1;

    for (i = 0; i < 8 && i + offset < gUnitListCount; i++)
    {
        if (GetUnitEquippedWeapon(gSortedUnits[offset + i]->unit) != 0)
        {
            icons_to_display[i] = GetItemIcon(GetUnitEquippedWeapon(gSortedUnits[offset + i]->unit));
        }
    }

    for (i = 0; i < 8; i++)
    {
        if (gUnitListItemIcons[i] != UINT8_MAX)
        {
            bool icon_in_use = FALSE;

            for (j = 0; j < 8; j++)
            {
                if (icons_to_display[j] == gUnitListItemIcons[i])
                    icon_in_use = TRUE;
            }

            if (!icon_in_use)
            {
                ClearIcon(gUnitListItemIcons[i]);
                gUnitListItemIcons[i] = UINT8_MAX;
            }
        }
    }
}

void func_fe6_080744A0(fu8 arg_0, fu8 arg_1, fi8 arg_2)
{
    // TODO: chr & pal constants

    fu8 chr_offset = (arg_1 / 8) % 6;

    if (arg_0 == 0)
    {
        if (arg_2 != 0)
        {
            gBg2Tm[TM_OFFSET(0, 4)] = TILEREF(0x368 + chr_offset, 0xF);
            gBg2Tm[TM_OFFSET(0, 5)] = TILEREF(0x36E + chr_offset, 0xF);
        }
        else
        {
            gBg2Tm[TM_OFFSET(0, 4)] = 0;
            gBg2Tm[TM_OFFSET(0, 5)] = 0;
        }
    }
    else
    {
        if (arg_2 != 0)
        {
            gBg2Tm[TM_OFFSET(29, 4)] = TILEREF(0x368 + chr_offset, 0xF) + TILE_HFLIP;
            gBg2Tm[TM_OFFSET(29, 5)] = TILEREF(0x36E + chr_offset, 0xF) + TILE_HFLIP;
        }
        else
        {
            gBg2Tm[TM_OFFSET(29, 4)] = 0;
            gBg2Tm[TM_OFFSET(29, 5)] = 0;
        }
    }

    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_08074558(struct UnitListScreenProc * proc, fi8 arg_1)
{
    fu8 i;

    int unit_id;

    if (arg_1 != 0)
    {
        unit_id = gPrepCursorUnitPid;
    }
    else
    {
        unit_id = GetLastStatScreenUnitId();
    }

    for (i = 0; i < gUnitListCount; i++)
    {
        if (arg_1 != 0)
        {
            if (UNIT_PID(gSortedUnits[i]->unit) == unit_id)
                goto found_unit;

            continue;
        }
        else
        {
            if (gSortedUnits[i]->unit->id == unit_id)
                goto found_unit;

            continue;
        }

    found_unit:
        proc->unk_30 = i;

        if (i == 0)
        {
            proc->unk_2C = 0;
            proc->unk_40 = 0;
            return;
        }

        if (i == gUnitListCount - 1)
        {
            if (gUnitListCount < 7)
            {
                proc->unk_2C = i;
                proc->unk_40 = 0;
                return;
            }
            else
            {
                proc->unk_2C = 5;
                proc->unk_40 = (gUnitListCount - 6) * 16;
                return;
            }
        }

        if (i > proc->unk_40 / 16 && i < proc->unk_40 / 16 + 5)
        {
            proc->unk_2C = i - proc->unk_40 / 16;
            return;
        }

        if (proc->unk_40 > (i - 1) * 16)
        {
            proc->unk_2C = 1;
            proc->unk_40 = (i - 1) * 16;
            return;
        }

        if (proc->unk_40 < (i - 4) * 16)
        {
            proc->unk_2C = 4;
            proc->unk_40 = (i - 4) * 16;
            return;
        }

        return;
    }
}

void func_fe6_08074668(bool use_win1)
{
    if (use_win1)
    {
        SetWinEnable(1, 1, 0);
        SetWin0Box(0, 0x38, DISPLAY_WIDTH, 0x98);
        SetWin1Box(0, 0x00, DISPLAY_WIDTH, 0x20);
        SetWin0Layers(1, 1, 1, 1, 1);
        SetWin1Layers(0, 1, 1, 1, 1);
        SetWOutLayers(0, 1, 1, 1, 0);
    }
    else
    {
        SetWinEnable(1, 0, 0);
        SetWin0Box(0, 0x38, DISPLAY_WIDTH, 0x98);
        SetWin0Layers(1, 1, 1, 1, 1);
        SetWOutLayers(0, 1, 1, 1, 1);
    }
}

void UnitList_StartStatScreen(struct UnitListScreenProc * proc)
{
    EndAllMus();
    Proc_End(proc->sprites_proc);
    Proc_End(proc->unk_48);
    EndGreenText();

    SetWinEnable(0, 0, 0);

    if (proc->mode == UNITLIST_MODE_PREPMENU)
    {
        SetStatScreenExcludedUnitFlags(UNIT_FLAG_DEAD);
    }
    else
    {
        SetStatScreenExcludedUnitFlags(UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED);
    }

    StartStatScreen(gSortedUnits[proc->unk_30]->unit, proc);

    gPlaySt.last_sort_key = (proc->sort_order << 7) + proc->sort_key;

    proc->unk_29 = 4;
}

void UnitList_ResetFromStatScreen(struct UnitListScreenProc * proc)
{
    func_fe6_08074EF0(proc);
    SetDispEnable(0, 0, 0, 0, 0);
}

void UnitList_ResetDispFromStatScreen(struct UnitListScreenProc * proc)
{
    SetDispEnable(1, 1, 1, 1, 1);
}

void UnitListScreenSprites_Init(struct UnitListScreenSpritesProc * proc)
{
    proc->main_proc = proc->proc_parent;
    proc->unk_3B = 0;
    proc->unk_3C = 0;
    proc->unk_38 = proc->main_proc->unk_40;
    proc->unk_3A = 0;
    proc->unk_30 = 0;
    proc->unk_34 = StartMenuScrollBar(proc);

    SetPrepMenuScrollBarBaseInfo(proc->unk_34, 0xE0, 0x40, 10, proc->main_proc->unk_40, gUnitListCount, 6);

    ForceSyncUnitSpriteSheet();
}

void UnitListScreenSprites_Main(struct UnitListScreenSpritesProc * proc)
{
    fu8 r5;
    fi8 sl;
    fu8 i;

    u8 sp_0C[4] = { 0, 1, 2, 1 };

    if (proc->main_proc->sort_order == 0)
    {
        PutSpriteExt(0x0B, 0xB8, sp_0C[(proc->unk_3B / 8) % 4] + 7, Sprite_08678750, OAM2_PAL(9));
    }
    else
    {
        PutSpriteExt(0x0B, 0xB8 + 0x2000, sp_0C[(proc->unk_3B / 8) % 4] + 7, Sprite_08678750, OAM2_PAL(9));
    }

    PutSpriteExt(0x0D, 0x20, 0x08, gUnk_08678818[proc->main_proc->page], OAM2_PAL(9));
    PutSpriteExt(0x0D, 0xA0, 0, Sprite_08678758, OAM2_PAL(9));

    SetPrepMenuScrollBarBaseInfo(proc->unk_34, 0xE0, 0x40, 0x0A, proc->main_proc->unk_40, gUnitListCount, 6);

    if (proc->main_proc->unk_29 > 2)
    {
        PutUiHand(
            UnitListPageFields[proc->main_proc->page][proc->main_proc->unk_2D].x_column,
            40 + proc->main_proc->unk_2C * 16);
    }
    else
    {
        PutSpriteExt(0x0D, 4, 0x40 + proc->main_proc->unk_2C * 16, Sprite_08678760, OAM2_PAL(9));
    }

    if (proc->unk_38 != proc->main_proc->unk_40 || (proc->main_proc->unk_40 % 0x10) != 0)
    {
        gPal[0x19E] = gPrepUiPal[8];
        EnablePalSync();

        proc->unk_3C = 0x20;
        proc->unk_38 = proc->main_proc->unk_40;

        if (proc->unk_3A == 0)
        {
            func_fe6_08074668(TRUE);
            proc->unk_3A = 1;
        }
    }
    else
    {
        gPal[0x19E] = gPrepUiPal[(proc->unk_3C / 4) & 0x0F];
        EnablePalSync();

        if (proc->unk_3A == 1)
        {
            func_fe6_08074668(FALSE);
            proc->unk_3A = 0;
        }
    }

    SyncUnitSpriteSheet();

    r5 = proc->unk_38 / 0x10;
    sl = -(proc->unk_38 % 0x10);

    for (i = 0; i < 6 && i + r5 < gUnitListCount; i++)
    {
        PutUnitSprite(4, 8, 56 + i * 16 + sl, gSortedUnits[i + r5]->unit);
    }

    if (proc->unk_3A != 0 && i + r5 < gUnitListCount)
    {
        PutUnitSprite(4, 8, 56 + i * 16 + sl, gSortedUnits[i + r5]->unit);
    }

    if (proc->main_proc->page < proc->main_proc->unk_2E && proc->main_proc->mode != UNITLIST_MODE_SOLOANIM)
    {
        func_fe6_080744A0(1, proc->unk_30, 1);
    }
    else
    {
        func_fe6_080744A0(1, proc->unk_30, 0);
    }

    if (proc->main_proc->page > 1 && proc->main_proc->mode != UNITLIST_MODE_SOLOANIM)
    {
        func_fe6_080744A0(0, proc->unk_30, 1);
    }
    else
    {
        func_fe6_080744A0(0, proc->unk_30, 0);
    }

    proc->unk_30++;

    if ((proc->unk_30 >> 3) > 5)
        proc->unk_30 = 0;

    proc->unk_3B++;
    proc->unk_3C++;
}

void UnitListScreenSprites_Dummy(struct UnitListScreenSpritesProc * proc)
{
}

void func_fe6_08074BA4(struct UnitListScreenProc * proc)
{
    int support_count;
    fu8 i, support_now_count;

    FOR_UNITS_FACTION(gPlaySt.faction, unit,
    {
        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        if (proc->mode != UNITLIST_MODE_PREPMENU && (unit->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
            continue;

        if ((unit->flags & UNIT_FLAG_NOT_DEPLOYED) == 0)
            proc->unk_3B++;

        gSortedUnitsBuf[gUnitListCount].unit = unit;

        BattleGenerateDisplayStats(unit, -1);

        gSortedUnitsBuf[gUnitListCount].battle_attack = ((gBattleUnitA.battle_attack + 1) & 0xFF) - 1;
        gSortedUnitsBuf[gUnitListCount].battle_hit = ((gBattleUnitA.battle_hit + 1) & 0xFF) - 1;
        gSortedUnitsBuf[gUnitListCount].battle_avoid = ((gBattleUnitA.battle_avoid + 1) & 0xFF) - 1;

        support_count = GetUnitSupportCount(unit);
        support_now_count = 0;

        for (i = 0; i < support_count; i++)
        {
            if (CanUnitSupportNow(unit, i))
                support_now_count++;
        }

        if (support_now_count > 3)
            proc->unk_2E = 6 + (support_now_count - 1) / 3;

        gSortedUnitsBuf[gUnitListCount].support_talk_count = support_now_count;
        gSortedUnits[gUnitListCount] = &gSortedUnitsBuf[gUnitListCount];

        gUnitListCount++;

        UseUnitSprite(GetUnitMapSprite(unit));
    })
}

void func_fe6_08074D54(struct UnitListScreenProc * proc)
{
    // this function is identical to func_fe6_08074BA4
    // except it uses FACTION_BLUE instead of gPlaySt.faction

    int support_count;
    fu8 i, support_now_count;

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        if (proc->mode != UNITLIST_MODE_PREPMENU && (unit->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
            continue;

        if ((unit->flags & UNIT_FLAG_NOT_DEPLOYED) == 0)
            proc->unk_3B++;

        gSortedUnitsBuf[gUnitListCount].unit = unit;

        BattleGenerateDisplayStats(unit, -1);

        gSortedUnitsBuf[gUnitListCount].battle_attack = ((gBattleUnitA.battle_attack + 1) & 0xFF) - 1;
        gSortedUnitsBuf[gUnitListCount].battle_hit = ((gBattleUnitA.battle_hit + 1) & 0xFF) - 1;
        gSortedUnitsBuf[gUnitListCount].battle_avoid = ((gBattleUnitA.battle_avoid + 1) & 0xFF) - 1;

        support_count = GetUnitSupportCount(unit);
        support_now_count = 0;

        for (i = 0; i < support_count; i++)
        {
            if (CanUnitSupportNow(unit, i))
                support_now_count++;
        }

        if (support_now_count > 3)
            proc->unk_2E = 6 + (support_now_count - 1) / 3;

        gSortedUnitsBuf[gUnitListCount].support_talk_count = support_now_count;
        gSortedUnits[gUnitListCount] = &gSortedUnitsBuf[gUnitListCount];

        gUnitListCount++;

        UseUnitSprite(GetUnitMapSprite(unit));
    })
}

void func_fe6_08074EF0(struct UnitListScreenProc * proc)
{
    fu8 i, thing;

    SetDispEnable(1, 1, 1, 1, 1);
    SetOnVMatch(NULL);
    InitBgs(NULL);
    ResetText();
    ResetTextFont();
    ClearIcons();
    ApplyUnitSpritePalettes();
    ApplySystemObjectsGraphics();

    StartGreenText(proc);

    gUnitListCount = 0;
    proc->unk_3B = 0;
    proc->unk_2E = 6;

    func_fe6_08074D54(proc);

    if (proc->mode != UNITLIST_MODE_PREPMENU || proc->unk_2A == 1)
    {
        thing = gPlaySt.last_sort_key;

        if (thing != 0)
        {
            proc->target_sort_order = (thing >> 7) & 1;
            proc->sort_order = proc->target_sort_order;
            proc->sort_key = thing & 0x7F;
        }

        if (proc->unk_29 != 4 && proc->page != 0)
        {
            thing = gPlaySt.last_unit_list_page;

            if (thing != 0)
            {
                if (thing > 6)
                    proc->page = 6;
                else
                    proc->page = thing;

                proc->page_target = proc->page;
            }
        }

        SortUnitList(proc->sort_key, proc->sort_order);
    }

    Decompress(Img_Prep_083198CC, OBJ_VRAM0 + OBCHR_UNITLIST_390 * CHR_SIZE);
    ApplyPalettes(Pal_SpinningArrow, 0x10 + OBPAL_UNITLIST_1, 3);

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    TmFill(gBg2Tm, 0);

    InitIcons();
    ApplyIconPalettes(4);
    UnpackUiWindowFrameGraphics();
    Decompress(Img_UnitList_Title, OBJ_VRAM0 + OBCHR_UNITLIST_240 * CHR_SIZE);
    ApplyPalette(Pal_UnitList_Title, 0x10 + OBPAL_UNITLIST_9);

    SetupPrepUiPalette();
    TmApplyTsa(gBg1Tm, Tsa_UnitList_083210A0, TILEREF(0, BGPAL_WINDOWFRAME));

    for (i = 0; i < 7 ; i++)
    {
        InitText(&gUnitListNameTexts[i], 5);
        InitTextDb(&gUnitListFieldTexts[i][0], 7);
        InitText(&gUnitListFieldTexts[i][1], 7);
        InitText(&gUnitListFieldTexts[i][2], 5);
    }

    InitText(&gUnitListNameLabelText, 4);
    InitText(&gUnitListFieldLabelText, 20);
    InitText(&gUnitListSortKeyText, 4);

    func_fe6_080742D0(proc->sort_key);

    if (proc->unk_29 == 4)
    {
        func_fe6_08074558(proc, 0);
        proc->unk_29 = 0;
    }
    else
    {
        if (proc->mode == UNITLIST_MODE_PREPMENU)
            func_fe6_08074558(proc, 1);
    }

    proc->unk_3E = 0;
    proc->unk_2B = 0;

    ClearText(&gUnitListNameLabelText);
    Text_SetCursor(&gUnitListNameLabelText, 0);
    Text_SetColor(&gUnitListNameLabelText, 0);
    Text_DrawString(&gUnitListNameLabelText, JTEXT("名　前"));
    PutText(&gUnitListNameLabelText, gBg2Tm + TM_OFFSET(3, 5));

    for (i = 0; i < 20; i++)
    {
        gUnitListItemIcons[i] = UINT8_MAX;
    }

    for (i = proc->unk_40 / 16; i < proc->unk_40 / 16 + 6 && i < gUnitListCount; i++)
    {
        func_fe6_08076448(proc, i, gBg0Tm, proc->page, TRUE);
    }

    func_fe6_080763D8(proc->unk_2E, proc->page, TRUE);

    SetWinEnable(1, 0, 0);
    SetWin0Box(0x10, 0x38, 0xe0, 0x98);
    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(0, 1, 1, 1, 1);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

    SetBgOffset(3, 0, 0);
    SetBgOffset(2, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(0, 0, (proc->unk_40 - 0x38) & 0xFF);

    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg1_ct.priority = 2;
    gDispIo.bg2_ct.priority = 1;
    gDispIo.bg3_ct.priority = 3;

    Decompress(Img_HorizontalSpinningArrow, gBg1Tm + TM_OFFSET(0, 20));
    ApplyPalette(Pal_SpinningArrow, BGPAL_UNITLIST_15);

    proc->sprites_proc = SpawnProc(ProcScr_UnitListScreenSprites, proc);

    if (proc->mode == UNITLIST_MODE_PREPMENU && proc->unk_3C == 0)
    {
        Decompress(Img_MonologueBG, (void *) VRAM + GetBgChrOffset(3));
        ApplyPalettes(Pal_MonologueBG, BGPAL_UNITLIST_10, 4);
        proc->unk_48 = func_fe6_08082560(proc);
    }
    else
    {
        proc->unk_48 = StartMuralBackground(NULL, NULL, BGPAL_UNITLIST_10);
    }

    LoadHelpBoxGfx(NULL, -1);
}

void UnitList_Init(struct UnitListScreenProc * proc)
{
    proc->unk_29 = 0;
    proc->unk_31 = 1;
    proc->unk_2C = 0;
    proc->unk_2D = 0;
    proc->unk_30 = 0;

    if (proc->mode == UNITLIST_MODE_SOLOANIM)
        proc->page = UNITLIST_PAGE_SOLOANIM;
    else
        proc->page = UNITLIST_PAGE_1;

    proc->page_target = proc->page;
    proc->unk_40 = 0;
    proc->sort_key = 1;
    proc->unk_2A = 0;
    proc->target_sort_order = 1;
    proc->sort_order = 0;
    proc->unk_35 = 0;

    func_fe6_08074EF0(proc);
}

void func_fe6_080753A0(struct UnitListScreenProc * proc)
{
    fu8 idx = proc->unk_30;

    if ((gSortedUnits[idx]->unit->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
    {
        if (proc->unk_3C == 0 || CanUnitUseWeaponsInArena(gSortedUnits[idx]->unit))
        {
            if (proc->unk_3A > proc->unk_3B)
            {
                gSortedUnits[idx]->unit->flags &= ~(UNIT_FLAG_TURN_ENDED | UNIT_FLAG_NOT_DEPLOYED);
                RegisterSioPid(UNIT_PID(gSortedUnits[idx]->unit));
                proc->unk_3B++;
                PlaySe(SONG_6A);
                func_fe6_08076448(proc, idx, gBg0Tm, proc->page, TRUE);
            }
            else
            {
                PlaySe(SONG_6C);
            }
        }
        else
        {
            StartPrepErrorHelpbox(0, proc->unk_2C * 16 + 0x38, MSG_6C1, proc);
        }

        return;
    }
    else
    {
        if (proc->unk_3C != 0 || !IsUnitMandatoryDeploy(gSortedUnits[idx]->unit))
        {
            gSortedUnits[idx]->unit->flags |= UNIT_FLAG_TURN_ENDED | UNIT_FLAG_NOT_DEPLOYED;
            RemoveSioPid(UNIT_PID(gSortedUnits[idx]->unit));
            PlaySe(SONG_6B);
            proc->unk_3B--;
            func_fe6_08076448(proc, idx, gBg0Tm, proc->page, TRUE);
        }
        else
        {
            PlaySe(SONG_6C);
        }
    }
}

void func_fe6_080754F4(struct Unit * unit, int step)
{
    int anim_param;

    if (UNIT_PID(unit) == PID_MERLINUS)
    {
        PlaySe(SONG_6C);
        return;
    }

    anim_param = unit->flags & UNIT_FLAG_SOLOANIM;

    anim_param = anim_param >> 14;
    anim_param = ((anim_param + step + 3)) % 3;
    anim_param = anim_param << 14;

    unit->flags = anim_param | (unit->flags & ~UNIT_FLAG_SOLOANIM);

    if ((anim_param & UNIT_FLAG_SOLOANIM) != 0)
    {
        PlaySe(SONG_6A);
    }
    else
    {
        PlaySe(SONG_6B);
    }
}

void func_fe6_08075570(struct UnitListScreenProc * proc)
{
    fu8 var_04 = proc->unk_2D;

    int i;
    fu8 var_08;

    switch (proc->unk_29)
    {
        case 0:
            if ((gKeySt->held & KEY_BUTTON_L) != 0)
            {
                proc->unk_31 = 2;
            }
            else
            {
                proc->unk_31 = 1;
            }

            if ((gKeySt->pressed & KEY_BUTTON_R) != 0)
            {
                Proc_Goto(proc, 3);
                return;
            }

            if ((gKeySt->pressed & KEY_BUTTON_A) != 0)
            {
                switch (proc->mode)
                {
                    case UNITLIST_MODE_PREPMENU:
                        func_fe6_080753A0(proc);
                        break;

                    case UNITLIST_MODE_SOLOANIM:
                        func_fe6_080754F4(gSortedUnits[proc->unk_30]->unit, 1);
                        func_fe6_08076448(proc, proc->unk_30, gBg0Tm, proc->page, FALSE);
                        break;

                    case UNITLIST_MODE_FIELD:
                        SetStatScreenLastUnitId(gSortedUnits[proc->unk_30]->unit->id);
                        PlaySe(SONG_6A);
                        Proc_Break(proc);
                        break;

                    default:
                        break;
                }

                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_LEFT) != 0)
            {
                if (proc->mode == UNITLIST_MODE_SOLOANIM)
                {
                    if ((gKeySt->pressed & KEY_DPAD_LEFT) == 0)
                        break;

                    func_fe6_080754F4(gSortedUnits[proc->unk_30]->unit, -1);
                    func_fe6_08076448(proc, proc->unk_30, gBg0Tm, proc->page, 0);

                    break;
                }

                if (proc->page < 2)
                    break;

                proc->page_target--;
                Proc_Goto(proc, 2);
                proc->unk_2D = 0;
                PlaySe(SONG_6F);

                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_RIGHT) != 0)
            {
                if (proc->mode == UNITLIST_MODE_SOLOANIM)
                {
                    if ((gKeySt->pressed & KEY_DPAD_RIGHT) == 0)
                        break;

                    func_fe6_080754F4(gSortedUnits[proc->unk_30]->unit, +1);
                    func_fe6_08076448(proc, proc->unk_30, gBg0Tm, proc->page, 0);

                    break;
                }

                if (proc->page < proc->unk_2E)
                {
                    proc->page_target++;
                    proc->unk_2D = 0;
                    PlaySe(SONG_6F);
                    Proc_Goto(proc, 2);
                }

                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_UP) != 0 || ((gKeySt->held & KEY_BUTTON_L) != 0 && (gKeySt->pressed2 & KEY_DPAD_UP) != 0))
            {
                if (proc->unk_30 == 0)
                {
                    if ((gKeySt->pressed & KEY_DPAD_UP) == 0)
                        break;

                    PlaySe(SONG_66);
                    proc->unk_29 = 3;
                    break;
                }

                proc->unk_30--;
                PlaySe(SONG_66);

                if (proc->unk_2C < 2)
                {
                    if (proc->unk_40 / 16 != 0)
                    {
                        if (proc->unk_2C == 0)
                        {
                            proc->unk_30++;
                            proc->unk_2C = 1;
                        }

                        func_fe6_08076448(proc, proc->unk_40 / 16 - 1, gBg0Tm, proc->page, 1);
                        proc->unk_29 = 2;
                        proc->unk_40 = -(proc->unk_31 * 4) + proc->unk_40;
                        SetBgOffset(0, 0, (proc->unk_40 - 0x38) & 0xFF);

                        if (proc->unk_2C == 0)
                        {
                            proc->unk_2C++;
                        }

                        break;
                    }
                }

                proc->unk_2C--;

                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_DOWN) != 0 || ((gKeySt->held & KEY_BUTTON_L) != 0 && (gKeySt->pressed2 & KEY_DPAD_DOWN) != 0))
            {
                if (proc->unk_30 < gUnitListCount - 1)
                {
                    proc->unk_30++;
                    PlaySe(SONG_66);
    
                    if (proc->unk_2C == 4 && proc->unk_30 != gUnitListCount - 1)
                    {
                        func_fe6_08076448(proc, 6 + proc->unk_40 / 16, gBg0Tm, proc->page, 1);
                        proc->unk_29 = 1;
                        proc->unk_40 = proc->unk_40 + proc->unk_31 * 4;
                        SetBgOffset(0, 0, (proc->unk_40 - 0x38) & 0xFF);
                        break;
                    }
    
                    proc->unk_2C++;
                }
                break;
            }

            break;

        case 1:
            proc->unk_40 += 4 * proc->unk_31;
            SetBgOffset(0, 0, (proc->unk_40 - 0x38) & 0xFF);

            if ((proc->unk_40 % 0x10) == 0)
            {
                proc->unk_29 = 0;
                func_fe6_080743C8(proc->unk_40);
            }

            break;

        case 2:
            proc->unk_40 += -(4 * proc->unk_31);
            SetBgOffset(0, 0, (proc->unk_40 - 0x38) & 0xFF);

            if ((proc->unk_40 % 0x10) == 0)
            {
                proc->unk_29 = 0;
                func_fe6_080743C8(proc->unk_40);
            }

            break;

        case 3:
            if (proc->unk_2B != 0 && (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R)) != 0)
            {
                CloseHelpBox();
                proc->unk_2B = 0;
                return;
            }

            if ((gKeySt->pressed & KEY_BUTTON_A) != 0 && proc->unk_2B == 0)
            {
                var_08 = proc->sort_key;

                proc->unk_2A = 1;
                PlaySe(SONG_6A);
                proc->sort_key = UnitListPageFields[proc->page][proc->unk_2D].sort_key;
                proc->target_sort_order = (proc->target_sort_order + 1) & 1;

                if (SortUnitList(proc->sort_key, proc->target_sort_order))
                {
                    for (i = 0; i < 6 && i < gUnitListCount; i++)
                    {
                        func_fe6_08076448(proc, i, gBg0Tm, proc->page, 1);
                    }

                    func_fe6_080743C8(proc->unk_40);
                    EnableBgSync(1);
                }

                proc->sort_order = proc->target_sort_order;
                proc->unk_35 = proc->unk_2D;
                
                if (proc->sort_key != var_08)
                    func_fe6_080742D0(proc->sort_key);

                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_DOWN) != 0 && proc->unk_2B == 0)
            {
                PlaySe(SONG_66);
                proc->target_sort_order = 1;
                proc->unk_29 = 0;
                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_LEFT) != 0)
            {
                proc->target_sort_order = 1;

                if (proc->unk_2D == 0)
                {
                    if (proc->page < 2)
                        break;

                    if (proc->mode == UNITLIST_MODE_SOLOANIM)
                        break;

                    PlaySe(SONG_6F);
                    proc->page_target--;

                    for (i = 8; i > 0 && UnitListPageFields[proc->page_target][i].x_column == 0; i--)
                    {
                    }

                    proc->unk_2D = i;
                    Proc_Goto(proc, 2);
                    break;
                }

                proc->unk_2D--;
                PlaySe(SONG_67);
                break;
            }

            if ((gKeySt->repeated & KEY_DPAD_RIGHT) != 0)
            {
                proc->target_sort_order = 1;

                if (proc->unk_2D == 8 || UnitListPageFields[proc->page][proc->unk_2D + 1].x_column == 0)
                {
                    if (proc->page < proc->unk_2E)
                    {
                        if (proc->mode == UNITLIST_MODE_SOLOANIM)
                            break;
    
                        proc->unk_2D = 0;
                        PlaySe(SONG_6F);
    
                        proc->page_target++;
                        Proc_Goto(proc, 2);
                    }
                    break;
                }
                else
                {
                    proc->unk_2D = proc->unk_2D + 1;
                    PlaySe(SONG_67);
                }

                break;
            }

            if ((gKeySt->pressed & KEY_BUTTON_R) != 0 && proc->unk_2B == 0)
            {
                proc->unk_2B = 1;

                StartHelpBox(
                    UnitListPageFields[proc->page][proc->unk_2D].x_column, 0x28,
                    UnitListPageFields[proc->page][proc->unk_2D].msg_help);
            }

            break;
    }

    if ((gKeySt->pressed & KEY_BUTTON_B) != 0 && proc->unk_2B == 0)
    {
        PlaySe(SONG_6B);
        SetStatScreenLastUnitId(0);
        Proc_Break(proc);
    }

    if (proc->unk_2B != 0 && var_04 != proc->unk_2D)
    {
        StartHelpBox(
            UnitListPageFields[proc->page_target][proc->unk_2D].x_column, 0x28,
            UnitListPageFields[proc->page_target][proc->unk_2D].msg_help);
    }
}

void UnitList_OnEnd(struct UnitListScreenProc * proc)
{
    if (proc->mode == UNITLIST_MODE_PREPMENU)
    {
        gPrepCursorUnitPid = UNIT_PID(gSortedUnits[proc->unk_30]->unit);
        func_fe6_080741EC();
    }

    gPlaySt.last_sort_key = (proc->sort_order << 7) + proc->sort_key;

    if (proc->page != UNITLIST_PAGE_SOLOANIM)
        gPlaySt.last_unit_list_page = proc->page;

    Proc_End(proc->sprites_proc);

    if (proc->unk_48 != NULL)
        Proc_End(proc->unk_48);

    EndGreenText();

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    TmFill(gBg2Tm, 0);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

    SetWinEnable(0, 0, 0);

    ResetTextFont();
    ClearIcons();
}

void UnitList_StartPageChange(struct UnitListScreenProc * proc)
{
    int i;

    TmFillRect(gUnitListRowsTmBuf[0], 31, 31, 0);

    for (i = proc->unk_40 / 16; i < proc->unk_40 / 16 + 6 && i < gUnitListCount; i++)
    {
        func_fe6_08076448(proc, i, gUnitListRowsTmBuf[0], proc->page, 0);
    }

    TmFillRect(gUnitListHeaderTmBuf[0], 31, 1, 0);

    func_fe6_08076314(gUnitListHeaderTmBuf[0], proc->page);

    proc->unk_3E = 0;
    proc->unk_37 = proc->page;
    proc->unk_38 = 0;
}

void func_fe6_08075E94(struct UnitListScreenProc * proc)
{
    int i;
    int r4;
    u8 r1;

    proc->unk_38 += gUnk_0867871C[proc->unk_3E];

    if (proc->unk_38 > 20)
        proc->unk_38 = 20;

    proc->unk_3E++;

    for (i = 0; i < 20; i++)
    { 
        if (proc->page_target > proc->page)
        {
            if (proc->unk_38 + i > 20)
                r1 = 0;
            else
                r1 = i + proc->unk_38 + 8;
        }
        else
        {
            if (i < proc->unk_38)
                r1 = 0;
            else
                r1 = i - proc->unk_38 + 8;
        }

        for (r4 = proc->unk_40 / 8; r4 < 12 + proc->unk_40 / 8; r4++)
        {
            u16 off = 8 + (r4 & 0x1F) * 0x20;
            gBg0Tm[off + i] = gUnitListRowsTmBuf[r4 & 0x1F][r1];
        }

        for (r4 = 0; r4 < 2; r4++)
        {
            int off = 0xA8 + r4 * 0x20;
            gBg2Tm[off + i] = gUnitListHeaderTmBuf[r4][r1];
        }
    }

    EnableBgSync(BG0_SYNC_BIT | BG2_SYNC_BIT);

    if (proc->unk_38 < 20)
        return;

    proc->page = proc->page_target;

    TmFillRect(gBg2Tm+0x150/2, 0x16, 1, 0);
    TmFillRect(gBg0Tm+0x10/2, 0x16, 0x1F, 0);

    for (r4 = 0; r4 < 20; r4++)
        gUnitListItemIcons[r4] = UINT8_MAX;

    ClearIcons();
    func_fe6_080742D0(proc->sort_key);

    for (r4 = proc->unk_40 / 16; r4 < proc->unk_40 / 16 + 6 && r4 < gUnitListCount; r4++)
    {
        func_fe6_08076448(proc, r4, gUnitListRowsTmBuf[0], proc->page, 0);
    }

    func_fe6_08076314(gUnitListHeaderTmBuf[0], proc->page);
    func_fe6_080763D8(proc->unk_2E, proc->page, 0);

    proc->unk_38 = 0;
    proc->unk_3E = 0;

    Proc_Break(proc);
}

void func_fe6_08076060(struct UnitListScreenProc * proc)
{
    int r4, r5, r3;

    proc->unk_38 += gUnk_08678722[proc->unk_3E];

    if (proc->unk_38 > 20)
        proc->unk_38 = 20;

    proc->unk_3E++;

    if (proc->page_target > proc->unk_37)
    {
        for (r5 = 0; r5 < proc->unk_38; r5++)
        {
            for (r4 = proc->unk_40 / 8; r4 < proc->unk_40 / 8 + 12; r4++)
            {
                r3 = r4 & 0x1F;
                gBg0Tm[r3 * 0x20 + (({r5 + 0x1C;}) - proc->unk_38)] = gUnitListRowsTmBuf[r3][r5 + 8];
            }

            for (r4 = 0; r4 < 2; r4++)
            {
                gBg2Tm[(r4 + 5) * 0x20 + (({r5 + 0x1C;}) - proc->unk_38)] = gUnitListHeaderTmBuf[r4][r5 + 8];
            }
        }
    }
    else
    {
        for (r5 = 0; r5 < proc->unk_38; r5++)
        {
            // FAKEMATCH: these two do-whiles set the allocation order that puts &proc->unk_40 in sl and the mask in r8.
            do
            {
                r4 = proc->unk_40 / 8;
            } while (0);

            for (; r4 < proc->unk_40 / 8 + 12; r4++)
            {
                do
                {
                    r3 = r4 & 0x1F;
                } while (0);

                gBg0Tm[TM_OFFSET(r5 + 8, r3)] = gUnitListRowsTmBuf[r3][({r5 + 0x1C;}) - proc->unk_38];
            }

            for (r4 = 0; r4 < 2; r4++)
            {
                gBg2Tm[TM_OFFSET(r5 + 8, r4 + 5)] = gUnitListHeaderTmBuf[r4][({r5 + 0x1C;}) - proc->unk_38];
            }
        }
    }

    EnableBgSync(BG0_SYNC_BIT | BG2_SYNC_BIT);

    if (proc->unk_38 >= 20)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_UnitListScreen[] =
{
    PROC_19,
    PROC_CALL(LockGame),

    PROC_CALL(StartFastFadeToBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_CALL(LockBmDisplay),

    PROC_CALL(UnitList_Init),

    PROC_CALL(StartFastFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

PROC_LABEL(1),
    PROC_REPEAT(func_fe6_08075570),

    PROC_CALL(StartFastFadeToBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_CALL(UnitList_OnEnd),

    PROC_CALL(UnlockBmDisplay),
    PROC_CALL(InitBmDisplay),
    PROC_CALL(EndAllMus),
    PROC_CALL(StartFastFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(UnlockGame),
    PROC_GOTO(4),

PROC_LABEL(2),
    PROC_CALL(UnitList_StartPageChange),
    PROC_REPEAT(func_fe6_08075E94),
    PROC_REPEAT(func_fe6_08076060),
    PROC_GOTO(1),

PROC_LABEL(3),
    PROC_CALL(UnitList_StartStatScreen),
    PROC_SLEEP(1),
    PROC_CALL(UnitList_ResetFromStatScreen),
    PROC_SLEEP(1),
    PROC_CALL(UnitList_ResetDispFromStatScreen),
    PROC_GOTO(1),

PROC_LABEL(4),
    PROC_END,
};

void StartUnitListScreen(void)
{
    struct UnitListScreenProc * proc;

    proc = SpawnProc(ProcScr_UnitListScreen, PROC_TREE_3);
    proc->mode = UNITLIST_MODE_FIELD;
}

struct ProcScr CONST_DATA ProcScr_UnitListScreen_PrepMenu[] =
{
    PROC_19,
    PROC_SLEEP(1),
    PROC_CALL(UnitList_Init),
    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),
PROC_LABEL(1),
    PROC_REPEAT(func_fe6_08075570),
    PROC_CALL(StartMidFadeToBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(UnitList_OnEnd),
    PROC_GOTO(4),
PROC_LABEL(2),
    PROC_CALL(UnitList_StartPageChange),
    PROC_REPEAT(func_fe6_08075E94),
    PROC_REPEAT(func_fe6_08076060),
    PROC_GOTO(1),
PROC_LABEL(3),
    PROC_CALL(UnitList_StartStatScreen),
    PROC_SLEEP(1),
    PROC_CALL(UnitList_ResetFromStatScreen),
    PROC_SLEEP(1),
    PROC_CALL(UnitList_ResetDispFromStatScreen),
    PROC_GOTO(1),
PROC_LABEL(4),
    PROC_END,
};

void func_fe6_08076250(ProcPtr parent)
{
    struct UnitListScreenProc * proc;

    if (parent == NULL)
    {
        proc = SpawnProc(ProcScr_UnitListScreen_PrepMenu, PROC_TREE_3);
    }
    else
    {
        proc = SpawnProcLocking(ProcScr_UnitListScreen_PrepMenu, parent);
    }

    proc->mode = UNITLIST_MODE_PREPMENU;

    if (CheckInLinkArena() == 1)
    {
        proc->unk_3C = 1;
        proc->unk_3A = 5;
    }
    else
    {
        proc->unk_3C = 0;
        proc->unk_3A = GetPlayerMaxDeployCount();
    }

    proc->unk_3B = 0;
}

struct ProcScr CONST_DATA ProcScr_ConfigSoloAnim[] =
{
    PROC_YIELD,
    PROC_CALL(UnitList_Init),

    PROC_CALL(StartFastFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

PROC_LABEL(1),
    PROC_REPEAT(func_fe6_08075570),
    PROC_CALL(StartFastFadeToBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(UnitList_OnEnd),
    PROC_GOTO(4),
PROC_LABEL(3),
    PROC_CALL(UnitList_StartStatScreen),
    PROC_SLEEP(1),
    PROC_CALL(UnitList_ResetFromStatScreen),
    PROC_SLEEP(1),
    PROC_CALL(UnitList_ResetDispFromStatScreen),
    PROC_GOTO(1),
PROC_LABEL(4),
    PROC_END,
};

void StartUnitListScreenForSoloAnim(ProcPtr parent)
{
    struct UnitListScreenProc * proc;

    if (parent == NULL)
    {
        proc = SpawnProc(ProcScr_ConfigSoloAnim, PROC_TREE_3);
    }
    else
    {
        proc = SpawnProcLocking(ProcScr_ConfigSoloAnim, parent);
    }

    proc->mode = UNITLIST_MODE_SOLOANIM;
}

void StartUnitListScreenUnk(ProcPtr parent)
{
    struct UnitListScreenProc * proc;

    if (parent == NULL)
    {
        proc = SpawnProc(ProcScr_UnitListScreen_PrepMenu, PROC_TREE_3);
    }
    else
    {
        proc = SpawnProcLocking(ProcScr_UnitListScreen_PrepMenu, parent);
    }

    proc->mode = UNITLIST_MODE_4;
}

void func_fe6_08076314(u16 * tm, fu8 page)
{
    fu8 i;

    TmFillRect(tm + 9, 0x13, 1, 0);

    ClearText(&gUnitListFieldLabelText);

    if (page == UNITLIST_PAGE_WEXP)
    {
        for (i = 0; i < 8; i++)
        {
            PutIcon(tm + 9 + 2 * i, ICON_ITEM_KIND_BASE + i, TILEREF(0, BGPAL_ICONS + 1));
        }
    }
    else
    {
        for (i = 1; i < 9 && UnitListPageFields[page][i].x_column != 0; i++)
        {
            Text_SetCursor(&gUnitListFieldLabelText, UnitListPageFields[page][i].x_column - 0x40);
            Text_SetColor(&gUnitListFieldLabelText, TEXT_COLOR_SYSTEM_WHITE);
            Text_DrawString(&gUnitListFieldLabelText, UnitListPageFields[page][i].label_string);
        }
        
        PutText(&gUnitListFieldLabelText, tm + 8);
    }

    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_080763D8(fu8 max_pages, fu8 page, bool arg_2)
{
    if (page != 0)
    {
        PutNumber(gBg2Tm + (0x74 / 2), TEXT_COLOR_SYSTEM_BLUE, page);
        PutSpecialChar(gBg2Tm + (0x74 / 2) + 1, TEXT_COLOR_SYSTEM_WHITE, TEXT_SPECIAL_SLASH);
        PutNumber(gBg2Tm + (0x74 / 2) + 2, TEXT_COLOR_SYSTEM_BLUE, max_pages);
    }
    else
    {
        TmFillRect(gBg1Tm + (0x32 / 2), 6, 3, 0);
        EnableBgSync(BG1_SYNC_BIT);
    }

    if (arg_2)
    {
        func_fe6_08076314(gBg2Tm + (0x140 / 2), page);
    }

    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_08076448(struct UnitListScreenProc * proc, fu8 unit_num, u16 * tm, fu8 page, bool put_name)
{
    fu8 inactive;
    fu8 i;
    fu8 num;
    int icon;

    // this is something permuter found, it matches but ugh
    int dummy_zero = 0;

    int row = unit_num % 7;
    int y = (unit_num * 2) & 0x1F;

    if ((gSortedUnits[unit_num]->unit->flags & UNIT_FLAG_NOT_DEPLOYED) != 0)
        inactive = TRUE;
    else
        inactive = FALSE;

    if (put_name != 0)
    {
        ClearText(&gUnitListNameTexts[row]);
        Text_SetCursor(&gUnitListNameTexts[row], 0);

        if (proc->unk_3C == 0 && proc->mode == UNITLIST_MODE_PREPMENU && IsUnitMandatoryDeploy(gSortedUnits[unit_num]->unit))
        {
            Text_SetColor(&gUnitListNameTexts[row], TEXT_COLOR_SYSTEM_GREEN);
        }
        else
        {
            Text_SetColor(&gUnitListNameTexts[row], inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE);
        }

        Text_DrawString(&gUnitListNameTexts[row], DecodeMsg(gSortedUnits[unit_num]->unit->pinfo->msg_name));
        PutText(&gUnitListNameTexts[row], tm + y * 0x20 + 3);
    }

    ClearText(&gUnitListFieldTexts[row][0]);
    ClearText(&gUnitListFieldTexts[row][1]);

    TmFillRect(tm + y * 0x20 + 8, 0x18, 1, 0);

    switch (page)
    {
        case UNITLIST_PAGE_SOLOANIM:
            PutDrawText(&gUnitListFieldTexts[row][0], tm + y * 0x20 + 8, 0, 0, 0, DecodeMsg(gSortedUnits[unit_num]->unit->jinfo->msg_name));
            Text_SetColor(&gUnitListFieldTexts[row][1], inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE);

            if (GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit) == 0)
            {
                PutDrawText(&gUnitListFieldTexts[row][1], tm + y * 0x20 + 17, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0, JTEXT("ーーーー"));
            }
            else
            {
                PutDrawText(&gUnitListFieldTexts[row][1], tm + y * 0x20 + 17, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0, GetItemName(GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit)));
                PutIcon(tm + y * 0x20 + 15, GetItemIcon(GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit)), TILEREF(0, BGPAL_ICONS));
                func_fe6_08074384(GetItemIcon(GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit)));
            }

            ClearText(&gUnitListFieldTexts[row][2]);

            if (gSortedUnits[unit_num]->unit->pinfo->id == PID_MERLINUS)
            {
                PutDrawText(&gUnitListFieldTexts[row][2], tm + y * 0x20 + 24, 1, 4, 0, JTEXT("オフ"));
            }
            else
            {
                switch (gSortedUnits[unit_num]->unit->flags & UNIT_FLAG_SOLOANIM)
                {
                    case UNIT_FLAG_SOLOANIM_1:
                        PutDrawText(&gUnitListFieldTexts[row][2], tm + y * 0x20 + 24, 4, 8, 0, JTEXT("１"));
                        break;

                    case UNIT_FLAG_SOLOANIM_2:
                        PutDrawText(&gUnitListFieldTexts[row][2], tm + y * 0x20 + 24, 4, 8, 0, JTEXT("２"));
                        break;

                    case 0:
                        PutDrawText(&gUnitListFieldTexts[row][2], tm + y * 0x20 + 24, 1, 4, 0, JTEXT("オフ"));
                        break;
                }
            }

            break;

        case UNITLIST_PAGE_1:
            // jinfo
            PutDrawText(&gUnitListFieldTexts[row][0], tm + y * 0x20 + 8, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0, DecodeMsg(gSortedUnits[unit_num]->unit->jinfo->msg_name));

            // level
            PutNumberOrBlank(tm + y * 0x20 + 17, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE, gSortedUnits[unit_num]->unit->level);

            // exp
            PutNumberOrBlank(tm + y * 0x20 + 20, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE, gSortedUnits[unit_num]->unit->exp);

            // hp
            PutNumberOrBlank(tm + y * 0x20 + 23, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE, GetUnitCurrentHp(gSortedUnits[unit_num]->unit));
            PutSpecialChar(tm + y * 0x20 + 24, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0x16);
            PutNumberOrBlank(tm + y * 0x20 + 26, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE, GetUnitMaxHp(gSortedUnits[unit_num]->unit));

            break;

        case UNITLIST_PAGE_2:
            PutNumberOrBlank(tm + y * 0x20 + 9, UNIT_POW_CAP(gSortedUnits[unit_num]->unit) == gSortedUnits[unit_num]->unit->pow ? 4 : 2, GetUnitPower(gSortedUnits[unit_num]->unit));
            PutNumberOrBlank(tm + y * 0x20 + 12, UNIT_SKL_CAP(gSortedUnits[unit_num]->unit) == gSortedUnits[unit_num]->unit->skl ? 4 : 2, GetUnitSkill(gSortedUnits[unit_num]->unit));
            PutNumberOrBlank(tm + y * 0x20 + 15, UNIT_SPD_CAP(gSortedUnits[unit_num]->unit) == gSortedUnits[unit_num]->unit->spd ? 4 : 2, GetUnitSpeed(gSortedUnits[unit_num]->unit));
            PutNumberOrBlank(tm + y * 0x20 + 18, UNIT_LCK_CAP(gSortedUnits[unit_num]->unit) == gSortedUnits[unit_num]->unit->lck ? 4 : 2, GetUnitLuck(gSortedUnits[unit_num]->unit));
            PutNumberOrBlank(tm + y * 0x20 + 21, UNIT_DEF_CAP(gSortedUnits[unit_num]->unit) == gSortedUnits[unit_num]->unit->def ? 4 : 2, GetUnitDefense(gSortedUnits[unit_num]->unit));
            PutNumberOrBlank(tm + y * 0x20 + 24, UNIT_RES_CAP(gSortedUnits[unit_num]->unit) == gSortedUnits[unit_num]->unit->res ? 4 : 2, GetUnitResistance(gSortedUnits[unit_num]->unit));

            icon = GetUnitAffinityIcon(gSortedUnits[unit_num]->unit);

            if (icon == -1)
                PutSpecialChar(tm + y * 0x20 + 26, 2, TEXT_SPECIAL_DASH);
            else
                PutIcon(tm + y * 0x20 + 26, icon, TILEREF(0, BGPAL_ICONS + 1));

            break;

        case UNITLIST_PAGE_3:
            if (GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit) == 0)
            {
                PutDrawText(&gUnitListFieldTexts[row][0], tm + y * 0x20 + 10, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0, JTEXT("ーーーー"));
            }
            else
            {
                char const * name = GetItemName(GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit));

                PutDrawText(&gUnitListFieldTexts[row][0], tm + y * 0x20 + 10,
                    inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, dummy_zero, name);

                PutIcon(tm + y * 0x20 + 8, GetItemIcon(GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit)), TILEREF(0, BGPAL_ICONS));
                func_fe6_08074384(GetItemIcon(GetUnitEquippedWeapon(gSortedUnits[unit_num]->unit)));
            }

            PutNumberOrBlank(tm + y * 0x20 + 18, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE,
                gSortedUnits[unit_num]->battle_attack);

            PutNumberOrBlank(tm + y * 0x20 + 22, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE,
                gSortedUnits[unit_num]->battle_hit);

            PutNumberOrBlank(tm + y * 0x20 + 26, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE,
                gSortedUnits[unit_num]->battle_avoid);
            
            break;

        case UNITLIST_PAGE_4:
            if ((gSortedUnits[unit_num]->unit->flags & UNIT_FLAG_RESCUING) != 0)
            {
                PutDrawText(&gUnitListFieldTexts[row][1], tm + y * 0x20 + 18,
                    inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0,
                    GetUnitRescueName(gSortedUnits[unit_num]->unit));
            }
            else
            {
                PutDrawText(&gUnitListFieldTexts[row][1], tm + y * 0x20 + 18,
                    inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0,
                    JTEXT("ーーー"));
            }

            PutNumberOrBlank(tm + y * 0x20 + 10, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE,
                UNIT_MOV(gSortedUnits[unit_num]->unit));

            PutNumberOrBlank(tm + y * 0x20 + 13, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE,
                UNIT_CON(gSortedUnits[unit_num]->unit));

            PutNumberOrBlank(tm + y * 0x20 + 16, inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_BLUE,
                GetUnitAid(gSortedUnits[unit_num]->unit));

            PutDrawText(&gUnitListFieldTexts[row][0], tm + y * 0x20 + 23,
                inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0,
                GetUnitStatusName(gSortedUnits[unit_num]->unit));

            break;

        case UNITLIST_PAGE_WEXP:
        {
            for (i = 0; i < 8; i++)
            {
                int special_chars[] =
                {
                    [WPN_LEVEL_0] = TEXT_SPECIAL_DASH,
                    [WPN_LEVEL_E] = TEXT_SPECIAL_E,
                    [WPN_LEVEL_D] = TEXT_SPECIAL_D,
                    [WPN_LEVEL_C] = TEXT_SPECIAL_C,
                    [WPN_LEVEL_B] = TEXT_SPECIAL_B,
                    [WPN_LEVEL_A] = TEXT_SPECIAL_A,
                    [WPN_LEVEL_S] = TEXT_SPECIAL_S,
                };

                num = GetWeaponLevelFromExp(gSortedUnits[unit_num]->unit->wexp[i]);

                PutSpecialChar(tm + y * 0x20 + 10 + 2 * i,
                    num == WPN_LEVEL_S ? TEXT_COLOR_SYSTEM_GREEN : 2, special_chars[num]);
            }

            break;
        }

        default:
        {
            fu8 support_start;
            fu8 support_passed;
            int support_count;

            support_start = (page - UNITLIST_PAGE_SUPPORT) * 3;
            support_passed = 0;
            num = 0;
            support_count = GetUnitSupportCount(gSortedUnits[unit_num]->unit);

            ClearText(&gUnitListFieldTexts[row][2]);

            for (i = 0; i < support_count; i++)
            {
                if (CanUnitSupportNow(gSortedUnits[unit_num]->unit, i))
                {
                    if (support_passed >= support_start)
                    {
                        struct Unit * other = GetUnitSupportUnit(gSortedUnits[unit_num]->unit, i);
    
                        if ((other->flags & UNIT_FLAG_NOT_DEPLOYED) == 0)
                        {
                            char const * name = DecodeMsg(
                                GetPInfo(GetUnitSupportPid(gSortedUnits[unit_num]->unit, i))->msg_name);

                            PutDrawText(&gUnitListFieldTexts[row][num], tm + y * 0x20 + 9 + num * 6,
                                inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0, name);
                        }
                        else
                        {
                            char const * name = DecodeMsg(
                                GetPInfo(GetUnitSupportPid(gSortedUnits[unit_num]->unit, i))->msg_name);

                            PutDrawText(&gUnitListFieldTexts[row][num], tm + y * 0x20 + 9 + num * 6,
                                TEXT_COLOR_SYSTEM_GRAY, 0, 0, name);
                        }
    
                        num++;
    
                        if (num == 3)
                            break;
                    }
                    else
                    {
                        support_passed++;
                    }
                }
            }

            for (; num < 3; num++)
            {
                PutDrawText(&gUnitListFieldTexts[row][num], tm + y * 0x20 + 9 + num * 6 ,
                    inactive ? TEXT_COLOR_SYSTEM_GRAY : TEXT_COLOR_SYSTEM_WHITE, 0, 0, JTEXT("ーーー"));
            }

            break;
        }
    }

    EnableBgSync(BG0_SYNC_BIT);
}

int func_fe6_08076D30(struct Unit * unit)
{
    return (unit->flags & UNIT_FLAG_SOLOANIM);
}

bool SortUnitList(fu8 key, fu8 order)
{
    u8 cache[0x40];

    order = order & 1;

    #define PREPARE_VARS \
        bool changed = FALSE; \
        fu8 i, j, tmp_cache; \
        void * tmp_addr;

    #define BUILD_CACHE(key) \
    { \
        for (i = 0; i < gUnitListCount; i++) \
        { \
            cache[i] = key(i); \
        } \
    }

    #define RETURN_IF_CHANGED if (changed) return TRUE;

    #define SWAP(i, j) \
    { \
        tmp_addr = gSortedUnits[(i)]; \
        gSortedUnits[(i)] = gSortedUnits[(j)]; \
        gSortedUnits[(j)] = tmp_addr; \
    }

    #define SWAP_CACHE(i, j) \
    { \
        tmp_cache = cache[(i)]; \
        cache[(i)] = cache[(j)]; \
        cache[(j)] = tmp_cache; \
        SWAP(i, j) \
    }

    #define SORT_CORE(cond, swap) \
    { \
        /* this is a bubble sort, I think */ \
        for (i = 0; i < gUnitListCount - 1; i++) \
        { \
            for (j = 0; j < gUnitListCount - 1 - i; j++) \
            { \
                if (cond) \
                { \
                    /* swap */ \
                    swap(j, j + 1) \
                    changed = TRUE; \
                } \
            } \
        } \
    }

    #define SORT_CORE_KEY(key, arrow, swap) \
    { \
        /* this is a bubble sort, I think */ \
        for (i = 0; i < gUnitListCount - 1; i++) \
        { \
            for (j = 0; j < gUnitListCount - 1 - i; j++) \
            { \
                if (key(j + 1) arrow key(j)) \
                { \
                    /* swap */ \
                    swap(j, j + 1) \
                    changed = TRUE; \
                } \
            } \
        } \
    }

    #define SORT_REAL(cond_asc, cond_dsc) \
        if (order == 0) \
        { \
            PREPARE_VARS \
            SORT_CORE(cond_asc, SWAP) \
            RETURN_IF_CHANGED \
        } \
        else \
        { \
            PREPARE_VARS \
            SORT_CORE(cond_dsc, SWAP) \
            RETURN_IF_CHANGED \
        }

    #define SORT(cond) SORT_REAL(cond, !(cond))

    #define SORT_BY_KEY(key) \
        if (order == 0) \
        { \
            PREPARE_VARS \
            SORT_CORE_KEY(key, >, SWAP) \
            RETURN_IF_CHANGED \
        } \
        else \
        { \
            PREPARE_VARS \
            SORT_CORE_KEY(key, <, SWAP) \
            RETURN_IF_CHANGED \
        }

    #define SORT_MAIN(sort_a, sort_b) \
        if (order == 0) \
        { \
            PREPARE_VARS \
            sort_a \
            RETURN_IF_CHANGED \
        } \
        else \
        { \
            PREPARE_VARS \
            sort_b \
            RETURN_IF_CHANGED \
        } \
        break;

    #define SORT_BY_FUNC(func) \
        SORT_REAL(func(gSortedUnits[j + 1]->unit) > func(gSortedUnits[j]->unit), \
            func(gSortedUnits[j + 1]->unit) < func(gSortedUnits[j]->unit))

    #define SORT_BY_UNIT_FIELD(field) \
        SORT_REAL((gSortedUnits[j + 1]->unit->field) > (gSortedUnits[j]->unit->field), \
            (gSortedUnits[j + 1]->unit->field) < (gSortedUnits[j]->unit->field))

    switch (key)
    {
        case UNITLIST_SORTKEY_1:
            #define KEY_A(i) (gSortedUnits[(i)]->unit->pinfo->sort_order_key)
            #define KEY_B(i) (gSortedUnits[(i)]->unit->flags & UNIT_FLAG_TURN_ENDED)

            SORT_MAIN(
                SORT_CORE_KEY(KEY_A, <, SWAP) SORT_CORE_KEY(KEY_B, <, SWAP),
                SORT_CORE_KEY(KEY_A, >, SWAP) SORT_CORE_KEY(KEY_B, >, SWAP))

            #undef KEY_B
            #undef KEY_A

        case UNITLIST_SORTKEY_3:
            #define KEY(i) (gSortedUnits[(i)]->unit->level)
            SORT_MAIN(SORT_CORE_KEY(KEY, >, SWAP), SORT_CORE_KEY(KEY, <, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_2:
            #define KEY(i) (gSortedUnits[(i)]->unit->jinfo->sort_order_key)
            SORT_MAIN(SORT_CORE_KEY(KEY, <, SWAP), SORT_CORE_KEY(KEY, >, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_4:
            SORT_BY_UNIT_FIELD(exp)
            break;

        case UNITLIST_SORTKEY_5:
            SORT_BY_FUNC(GetUnitCurrentHp)
            break;

        case UNITLIST_SORTKEY_6:
            SORT_BY_FUNC(GetUnitMaxHp)
            break;

        case UNITLIST_SORTKEY_7:
            SORT_BY_FUNC(GetUnitPower)
            break;

        case UNITLIST_SORTKEY_8:
            SORT_BY_FUNC(GetUnitSkill)
            break;

        case UNITLIST_SORTKEY_9:
            SORT_BY_FUNC(GetUnitSpeed)
            break;

        case UNITLIST_SORTKEY_10:
            SORT_BY_FUNC(GetUnitLuck)
            break;

        case UNITLIST_SORTKEY_11:
            SORT_BY_FUNC(GetUnitDefense)
            break;

        case UNITLIST_SORTKEY_12:
            SORT_BY_FUNC(GetUnitResistance)
            break;

        case UNITLIST_SORTKEY_19:
            SORT_BY_FUNC(UNIT_CON)
            break;

        case UNITLIST_SORTKEY_20:
            SORT_BY_FUNC(GetUnitAid)
            break;

        case UNITLIST_SORTKEY_13:
            #define KEY(i) (GetUnitAffinityIcon(gSortedUnits[(i)]->unit))
            SORT_MAIN(SORT_CORE_KEY(KEY, <, SWAP), SORT_CORE_KEY(KEY, >, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_14:
            SORT_MAIN(
            {
                for (i = 0; i < gUnitListCount; i++)
                {
                    cache[i] = GetItemIid(GetUnitEquippedWeapon(gSortedUnits[i]->unit));
                }

                for (i = 0; i < gUnitListCount - 1; i++)
                {
                    for (j = 0; j < gUnitListCount - 1 - i; j++)
                    {
                        if (cache[j + 1] > cache[j])
                        {
                            SWAP_CACHE(j, j + 1)
                            changed = TRUE;
                        }
                        else if (cache[j + 1] == cache[j] && GetUnitEquippedWeapon(gSortedUnits[j + 1]->unit) > GetUnitEquippedWeapon(gSortedUnits[j]->unit))
                        {
                            SWAP_CACHE(j, j + 1)
                            changed = TRUE;
                        }
                    }
                }
            },
            {
                for (i = 0; i < gUnitListCount; i++)
                {
                    cache[i] = GetItemIid(GetUnitEquippedWeapon(gSortedUnits[i]->unit));
                }

                for (i = 0; i < gUnitListCount - 1; i++)
                {
                    for (j = 0; j < gUnitListCount - 1 - i; j++)
                    {
                        if (cache[j + 1] < cache[j])
                        {
                            SWAP_CACHE(j, j + 1)
                            changed = TRUE;
                        }
                        else if (cache[j + 1] == cache[j] && GetUnitEquippedWeapon(gSortedUnits[j + 1]->unit) < GetUnitEquippedWeapon(gSortedUnits[j]->unit))
                        {
                            SWAP_CACHE(j, j + 1)
                            changed = TRUE;
                        }
                    }
                }
            })

        case UNITLIST_SORTKEY_15:
            #define KEY(i) (gSortedUnits[(i)]->battle_attack)
            SORT_MAIN(SORT_CORE_KEY(KEY, >, SWAP), SORT_CORE_KEY(KEY, <, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_16:
            #define KEY(i) (gSortedUnits[(i)]->battle_hit)
            SORT_MAIN(SORT_CORE_KEY(KEY, >, SWAP), SORT_CORE_KEY(KEY, <, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_17:
            #define KEY(i) (gSortedUnits[(i)]->battle_avoid)
            SORT_MAIN(SORT_CORE_KEY(KEY, >, SWAP), SORT_CORE_KEY(KEY, <, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_18:
            SORT_BY_FUNC(UNIT_MOV)
            break;

        case UNITLIST_SORTKEY_21:
            SORT_BY_UNIT_FIELD(status)
            break;

        case UNITLIST_SORTKEY_22:
            SORT_MAIN(
            {
                for (i = 0; i < gUnitListCount; i++)
                {
                    if ((gSortedUnits[i]->unit->flags & 0x10) != 0)
                        cache[i] = 1;
                    else
                        cache[i] = 0;
                }

                SORT_CORE(cache[j + 1] > cache[j], SWAP_CACHE)
            },
            {
                for (i = 0; i < gUnitListCount; i++)
                {
                    if ((gSortedUnits[i]->unit->flags & 0x10) != 0)
                        cache[i] = 1;
                    else
                        cache[i] = 0;
                }

                SORT_CORE(cache[j + 1] < cache[j], SWAP_CACHE)
            })

        case UNITLIST_SORTKEY_23:
            SORT_BY_UNIT_FIELD(wexp[0])
            break;

        case UNITLIST_SORTKEY_24:
            SORT_BY_UNIT_FIELD(wexp[1])
            break;

        case UNITLIST_SORTKEY_25:
            SORT_BY_UNIT_FIELD(wexp[2])
            break;

        case UNITLIST_SORTKEY_26:
            SORT_BY_UNIT_FIELD(wexp[3])
            break;

        case UNITLIST_SORTKEY_27:
            SORT_BY_UNIT_FIELD(wexp[4])
            break;

        case UNITLIST_SORTKEY_28:
            SORT_BY_UNIT_FIELD(wexp[5])
            break;

        case UNITLIST_SORTKEY_29:
            SORT_BY_UNIT_FIELD(wexp[6])
            break;

        case UNITLIST_SORTKEY_30:
            SORT_BY_UNIT_FIELD(wexp[7])
            break;

        case UNITLIST_SORTKEY_31:
            #define KEY(i) (gSortedUnits[(i)]->support_talk_count)
            SORT_MAIN(SORT_CORE_KEY(KEY, >, SWAP), SORT_CORE_KEY(KEY, <, SWAP))
            #undef KEY

        case UNITLIST_SORTKEY_32:
            SORT_BY_FUNC(func_fe6_08076D30)
            break;
    }

    return FALSE;
}

// TODO: move data above funcs

struct ProcScr CONST_DATA ProcScr_UnitListScreenSprites[] =
{
    PROC_19,
    PROC_CALL(UnitListScreenSprites_Init),
    PROC_REPEAT(UnitListScreenSprites_Main),
    PROC_CALL(UnitListScreenSprites_Dummy),
    PROC_END,
};

u8 CONST_DATA gUnk_0867871C[] =
{
    0x5,
    0x4,
    0x4,
    0x3,
    0x3,
    0x2,
};

u8 CONST_DATA gUnk_08678722[] =
{
    0x5,
    0x4,
    0x3,
    0x2,
    0x2,
    0x2,
    0x1,
    0x1,
    0x1,
    0x0,
};

u16 CONST_DATA Sprite_0867872C[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x25C),
};

u16 CONST_DATA Sprite_08678734[] =
{
    1,
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x25D),
};

u16 CONST_DATA Sprite_0867873C[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x25F),
};

u16 const * CONST_DATA gUnk_08678744[] =
{
    Sprite_0867872C,
    Sprite_08678734,
    Sprite_0867873C,
};

u16 CONST_DATA Sprite_08678750[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x240),
};

u16 CONST_DATA Sprite_08678758[] =
{
    1,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8, OAM2_CHR(0x262) + OAM2_LAYER(2),
};

u16 CONST_DATA Sprite_08678760[] =
{
    7,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8, OAM2_CHR(0x242) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(32), OAM2_CHR(0x243) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(64), OAM2_CHR(0x243) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(96), OAM2_CHR(0x243) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(128), OAM2_CHR(0x243) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(160), OAM2_CHR(0x243) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(192), OAM2_CHR(0x244) + OAM2_LAYER(2),
};

u16 CONST_DATA Sprite_0867878C[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x280),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x284),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x288),
};

u16 CONST_DATA Sprite_086787A0[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x28C),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x290),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x294),
};

u16 CONST_DATA Sprite_086787B4[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x2C0),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x2C4),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x2C8),
};

u16 CONST_DATA Sprite_086787C8[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x2CC),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x2D0),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x2D4),
};

u16 CONST_DATA Sprite_086787DC[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x300),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x304),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x308),
};

u16 CONST_DATA Sprite_086787F0[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x24C),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x250),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x254),
};

u16 CONST_DATA Sprite_08678804[] =
{
    3,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x30D),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x311),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(64), OAM2_CHR(0x315),
};

u16 const * CONST_DATA gUnk_08678818[] =
{
    [UNITLIST_PAGE_SOLOANIM] = Sprite_08678804,
    [UNITLIST_PAGE_1] = Sprite_0867878C,
    [UNITLIST_PAGE_2] = Sprite_086787A0,
    [UNITLIST_PAGE_3] = Sprite_086787B4,
    [UNITLIST_PAGE_4] = Sprite_086787C8,
    [UNITLIST_PAGE_WEXP] = Sprite_086787DC,
    [UNITLIST_PAGE_SUPPORT + 0] = Sprite_086787F0,
    [UNITLIST_PAGE_SUPPORT + 1] = Sprite_086787F0,
    [UNITLIST_PAGE_SUPPORT + 2] = Sprite_086787F0,
    [UNITLIST_PAGE_SUPPORT + 3] = Sprite_086787F0,
};

struct UnitListScreenField UnitListPageFields[][9] =
{
    [UNITLIST_PAGE_SOLOANIM] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_2,
            .label_string = JTEXT("クラス"),
            .x_column = 0x48,
            .msg_help = MSG_592,
        },
        {
            .sort_key = UNITLIST_SORTKEY_14,
            .label_string = JTEXT("装備"),
            .x_column = 0x88,
            .msg_help = MSG_669,
        },
        {
            .sort_key = UNITLIST_SORTKEY_32,
            .label_string = JTEXT("アニメ"),
            .x_column = 0xC0,
            .msg_help = MSG_66C,
        },
    },
    [UNITLIST_PAGE_1] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_2,
            .label_string = JTEXT("クラス"),
            .x_column = 0x48,
            .msg_help = MSG_592,
        },
        {
            .sort_key = UNITLIST_SORTKEY_3,
            .label_string = JTEXT("ＬＶ"),
            .x_column = 0x80,
            .msg_help = MSG_593,
        },
        {
            .sort_key = UNITLIST_SORTKEY_4,
            .label_string = JTEXT("ＥＸ"),
            .x_column = 0x98,
            .msg_help = MSG_594,
        },
        {
            .sort_key = UNITLIST_SORTKEY_5,
            .label_string = JTEXT("ＨＰ"),
            .x_column = 0xB0,
            .msg_help = MSG_595,
        },
        {
            .sort_key = UNITLIST_SORTKEY_6,
            .label_string = JTEXT("ＭＨＰ"),
            .x_column = 0xC4,
            .msg_help = MSG_667,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_2] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_7,
            .label_string = JTEXT("力／魔"),
            .x_column = 0x40,
            .msg_help = MSG_668,
        },
        {
            .sort_key = UNITLIST_SORTKEY_8,
            .label_string = JTEXT("技"),
            .x_column = 0x60,
            .msg_help = MSG_59E,
        },
        {
            .sort_key = UNITLIST_SORTKEY_9,
            .label_string = JTEXT("速さ"),
            .x_column = 0x70,
            .msg_help = MSG_59F,
        },
        {
            .sort_key = UNITLIST_SORTKEY_10,
            .label_string = JTEXT("幸運"),
            .x_column = 0x88,
            .msg_help = MSG_5A6,
        },
        {
            .sort_key = UNITLIST_SORTKEY_11,
            .label_string = JTEXT("守備"),
            .x_column = 0xA0,
            .msg_help = MSG_5A0,
        },
        {
            .sort_key = UNITLIST_SORTKEY_12,
            .label_string = JTEXT("魔防"),
            .x_column = 0xB8,
            .msg_help = MSG_5A1,
        },
        {
            .sort_key = UNITLIST_SORTKEY_13,
            .label_string = JTEXT("属性"),
            .x_column = 0xCE,
            .msg_help = MSG_5A7,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_3] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_14,
            .label_string = JTEXT("装備"),
            .x_column = 0x50,
            .msg_help = MSG_669,
        },
        {
            .sort_key = UNITLIST_SORTKEY_15,
            .label_string = JTEXT("攻撃"),
            .x_column = 0x88,
            .msg_help = MSG_597,
        },
        {
            .sort_key = UNITLIST_SORTKEY_16,
            .label_string = JTEXT("命中"),
            .x_column = 0xA8,
            .msg_help = MSG_598,
        },
        {
            .sort_key = UNITLIST_SORTKEY_17,
            .label_string = JTEXT("回避"),
            .x_column = 0xC8,
            .msg_help = MSG_59B,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_4] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_18,
            .label_string = JTEXT("移動"),
            .x_column = 0x48,
            .msg_help = MSG_5A4,
        },
        {
            .sort_key = UNITLIST_SORTKEY_19,
            .label_string = JTEXT("体格"),
            .x_column = 0x60,
            .msg_help = MSG_5A2,
        },
        {
            .sort_key = UNITLIST_SORTKEY_20,
            .label_string = JTEXT("救出"),
            .x_column = 0x78,
            .msg_help = MSG_5A3,
        },
        {
            .sort_key = UNITLIST_SORTKEY_22,
            .label_string = JTEXT("同行"),
            .x_column = 0x94,
            .msg_help = MSG_5A5,
        },
        {
            .sort_key = UNITLIST_SORTKEY_21,
            .label_string = JTEXT("状態"),
            .x_column = 0xBC,
            .msg_help = MSG_66A,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_WEXP] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_23,
            .label_string = "",
            .x_column = 0x4C,
            .msg_help = MSG_62D,
        },
        {
            .sort_key = UNITLIST_SORTKEY_24,
            .label_string = "",
            .x_column = 0x5C,
            .msg_help = MSG_62E,
        },
        {
            .sort_key = UNITLIST_SORTKEY_25,
            .label_string = "",
            .x_column = 0x6C,
            .msg_help = MSG_62F,
        },
        {
            .sort_key = UNITLIST_SORTKEY_26,
            .label_string = "",
            .x_column = 0x7C,
            .msg_help = MSG_630,
        },
        {
            .sort_key = UNITLIST_SORTKEY_27,
            .label_string = "",
            .x_column = 0x8C,
            .msg_help = MSG_631,
        },
        {
            .sort_key = UNITLIST_SORTKEY_28,
            .label_string = "",
            .x_column = 0x9C,
            .msg_help = MSG_632,
        },
        {
            .sort_key = UNITLIST_SORTKEY_29,
            .label_string = "",
            .x_column = 0xAC,
            .msg_help = MSG_633,
        },
        {
            .sort_key = UNITLIST_SORTKEY_30,
            .label_string = "",
            .x_column = 0xBC,
            .msg_help = MSG_634,
        },
    },
    [UNITLIST_PAGE_SUPPORT + 0] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_31,
            .label_string = JTEXT("相手"),
            .x_column = 0x48,
            .msg_help = MSG_636,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_SUPPORT + 1] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_31,
            .label_string = JTEXT("相手"),
            .x_column = 0x48,
            .msg_help = MSG_636,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_SUPPORT + 2] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_31,
            .label_string = JTEXT("相手"),
            .x_column = 0x48,
            .msg_help = MSG_636,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
    [UNITLIST_PAGE_SUPPORT + 3] =
    {
        {
            .sort_key = UNITLIST_SORTKEY_1,
            .label_string = JTEXT("名前"),
            .x_column = 0x14,
            .msg_help = MSG_666,
        },
        {
            .sort_key = UNITLIST_SORTKEY_31,
            .label_string = JTEXT("相手"),
            .x_column = 0x48,
            .msg_help = MSG_636,
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
        {
            .sort_key = UNITLIST_SORTKEY_0,
            .label_string = "",
        },
    },
};
