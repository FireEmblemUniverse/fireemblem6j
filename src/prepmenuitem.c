#include "prelude.h"
#include "proc.h"
#include "hardware.h"
#include "msg.h"
#include "sound.h"
#include "helpbox.h"
#include "prepscreen.h"
#include "constants/msg.h"
#include "constants/songs.h"

void func_fe6_0807C520(int a, int b)
{
    int unkr6, unkr7, unkr3, unkr5, unkr8;
    int _a = a;
    if ((_a - 0x38) < 0)
    {
        unkr7 = 0;
        unkr6 = _a;
    }
    else if ((_a + 0x38) > 0xF0)
    {
        unkr7 = 0xF;
        unkr6 = _a - 0x78;
    }
    else
    {
        unkr7 = (_a - 0x38) >> 3;
        unkr6 = a - unkr7 * 8;
    }

    unkr3 = b - 0x28;

    if ((b + 0x30) > 0xA0)
    {
        unkr5 = 8;
        unkr8 = b - 0x40;
    }
    else
    {
        int r0 = unkr3;
        if (r0 < 0)
        {
            r0 = b - 0x21;
        }
        unkr5 = r0 >> 3;
        unkr8 = b - (unkr5 * 8);
    }

    PutNumberOrBlank(gBg0Tm + TM_OFFSET(4, 0), TEXT_COLOR_SYSTEM_BLUE, unkr7);
    PutNumberOrBlank(gBg0Tm + TM_OFFSET(4, 2), TEXT_COLOR_SYSTEM_BLUE, unkr5);
    PutNumberOrBlank(gBg0Tm + TM_OFFSET(4, 4), TEXT_COLOR_SYSTEM_BLUE, unkr6);
    PutNumberOrBlank(gBg0Tm + TM_OFFSET(4, 6), TEXT_COLOR_SYSTEM_BLUE, unkr8);

    EnableBgSync(BG0_SYNC_BIT);
}

void PrepScreenMenu_OnPickUnits(struct PrepMenuProc * proc)
{
    if (proc->sel_unit == 0)
    {
        proc->a_button_actions |= 1;
        Proc_Goto(proc, 9);
        PlaySe(SONG_6A);
    }
    else if (proc->sel_unit == 1)
    {
        int cur_counter = proc->cur_counter;

        if ((proc->a_button_actions & 1) && proc->a_button_actions & 2)
        {
            if (cur_counter != 0)
            {
                Proc_Goto(proc, 0x5);
                proc->disp_proc->unk_2A = TRUE;
                PlaySe(SONG_6A);
            }
            else
            {
                PlaySe(SONG_6C);
            }
        }
        else
        {
            struct Unit * unit = GetUnitFromPrepList(proc->list_num_cur);

            if (unit->flags & UNIT_FLAG_NOT_DEPLOYED)
            {
                if ((proc->link_arena_flag & 1) == 0 || CanUnitUseWeaponsInArena(unit) != 0)
                {
                    if (proc->max_counter > proc->cur_counter)
                    {
                        GetUnitFromPrepList(proc->list_num_cur)->flags &= ~(UNIT_FLAG_TURN_ENDED | UNIT_FLAG_NOT_DEPLOYED);
                        RegisterSioPid(UNIT_PID(GetUnitFromPrepList(proc->list_num_cur)));
                        PlaySe(SONG_6A);
                        proc->cur_counter++;
                        PrepUnit_DrawUnitListNames(proc, proc->yDiff_cur / 0x10 + proc->hand_y_pos);
                    }
                    else
                    {
                        PlaySe(SONG_6C);
                    }
                }
                else
                {
                    StartPrepErrorHelpbox(
                        (proc->list_num_cur & 1) * 0x40 + 0x70,
                        proc->hand_y_pos * 0x10 + 0x28,
                        MSG_6C1,
                        proc);

                    return;
                }
            }
            else
            {
                if ((proc->link_arena_flag & 1) || IsUnitMandatoryDeploy(unit) == FALSE)
                {
                    GetUnitFromPrepList(proc->list_num_cur)->flags |= UNIT_FLAG_TURN_ENDED | UNIT_FLAG_NOT_DEPLOYED;
                    RemoveSioPid(UNIT_PID(GetUnitFromPrepList(proc->list_num_cur)));
                    PlaySe(SONG_6B);
                    proc->cur_counter--;
                    PrepUnit_DrawUnitListNames(proc, proc->yDiff_cur / 0x10 + proc->hand_y_pos);
                }
                else
                {
                    PlaySe(SONG_6C);
                }
            }
        }

        if (cur_counter != proc->cur_counter)
            PrepUnit_DrawPickLeftBar(proc);
    }
}

void PrepScreenMenu_OnItems(struct PrepMenuProc * proc)
{
    if (proc->sel_unit == 0)
    {
        Proc_Goto(proc, 0x9);
        PlaySe(SONG_6A);
    }
    else if (proc->sel_unit == 1)
    {
        proc->unk_31 = proc->list_num_cur;
        proc->unk_32 = proc->list_num_cur;
        proc->unk_40 = proc->yDiff_cur;
        proc->unk_37 = proc->hand_y_pos;
        proc->sel_unit = 0;
        proc->submenu_level = 1;
        PlaySe(SONG_6A);
        func_fe6_08079A94(proc);
    }
}

void func_fe6_0807C840(struct PrepMenuProc * proc)
{
    int list_num_cur;

    if (proc->list_num_cur != proc->unk_31)
        return;

    list_num_cur = proc->list_num_cur;

    if ((list_num_cur & 1) == 0)
    {
        if ((list_num_cur + 1) < proc->unk_2D)
            proc->list_num_cur = list_num_cur + 1;
        else if ((u32)list_num_cur >= 2)
        {
            proc->list_num_cur = list_num_cur - 2;
            proc->hand_y_pos--;
        }
    }
    else
    {
        proc->list_num_cur = list_num_cur - 1;
    }
}

void PrepScreenSubMenu_OnTrade(struct PrepMenuProc * proc)
{
    if (proc->sel_unit == 0)
    {
        if (proc->unk_2D != 1)
        {
            func_fe6_0807B8B0(proc->disp_proc, 5);
            proc->list_num_cur = proc->unk_32;
            proc->sel_unit = 1;
            func_fe6_0807C840(proc);
            func_fe6_08079D84(proc);
            func_fe6_080798EC(proc);
            PlaySe(SONG_6A);
        }
        else
        {
            PlaySe(SONG_6C);
            return;
        }
    }
    else if (proc->sel_unit == 1)
    {
        if (proc->list_num_cur == proc->unk_31 || (GetUnitItemCount(GetUnitFromPrepList(proc->list_num_cur)) + GetUnitItemCount(GetUnitFromPrepList(proc->unk_31))) == 0)
        {
            PlaySe(SONG_6C);
        }
        else
        {
            proc->unit1 = GetUnitFromPrepList(proc->unk_31);
            proc->unit2 = GetUnitFromPrepList(proc->list_num_cur);
            NewSallyCir2(proc, 1);
            proc->sub2_action = 2;
            Proc_Goto(proc, 3);
            PlaySe(SONG_6A);
        }
    }
}

void PrepScreenSubMenu_OnDiscard(struct PrepMenuProc * proc)
{
    if (proc->sel_unit == 0)
    {
        if (GetUnitItemCount(GetUnitFromPrepList(proc->list_num_cur)) == 0)
        {
            PlaySe(SONG_6C);
        }
        else
        {
            proc->unit1 = GetUnitFromPrepList(proc->list_num_cur);
            NewSallyCir2(proc, 1);
            proc->sub2_action = 4;
            Proc_Goto(proc, 3);
            PlaySe(SONG_6A);
        }
    }
}

void PrepScreenSubMenu_Convoy(struct PrepMenuProc * proc)
{
    if (proc->sel_unit == 0)
    {
        proc->unit1 = GetUnitFromPrepList(proc->list_num_cur);
        NewSallyCir2(proc, 1);
        proc->sub2_action = 3;
        Proc_Goto(proc, 3);
        PlaySe(SONG_6A);
    }
}

void PrepScreenSubMenu_AllItems(struct PrepMenuProc * proc)
{
    if (proc->sel_unit == 0)
    {
        proc->unit1 = GetUnitFromPrepList(proc->list_num_cur);
        NewSallyCir2(proc, 1);
        proc->sub2_action = 5;
        Proc_Goto(proc, 3);
        PlaySe(SONG_6A);
    }
}

void PrepScreenSubMenu_Shop(struct PrepMenuProc * proc)
{
    if (proc->sel_unit == 0)
    {
        PlaySe(SONG_6A);
        proc->sub2_action = 10;
        Proc_Goto(proc, 0xD);
    }
}

void func_fe6_0807CAD4(struct PrepMenuProc * proc)
{
    if (proc->sel_unit == 0)
    {
        proc->submenu_level = 2;
        PlaySe(SONG_6A);
        func_fe6_08079A94(proc);
    }
}

void PrepScreenMenu_Augury(struct PrepMenuProc * proc)
{
    if (proc->sel_unit == 0)
    {
        PlaySe(SONG_6A);
        proc->sub2_action = 8;
        Proc_Goto(proc, 0xD);
    }
}

void func_fe6_0807CB40(struct PrepMenuProc * proc)
{
    if (proc->sel_unit == 0)
    {
        PlaySe(SONG_6A);
        proc->sub2_action = 9;
        Proc_Goto(proc, 0xD);
    }
}

void PrepScreenMenu_OnSave(struct PrepMenuProc * proc)
{
    if (proc->sel_unit == 0)
    {
        PlaySe(SONG_6A);
        proc->sub2_action = 7;
        Proc_Goto(proc, 0xD);
    }
}

void PrepScreenMenu_OnCheckMap(struct PrepMenuProc * proc)
{
    if (proc->sel_unit == 0)
    {
        Proc_Goto(proc, 0x6);
        PlaySe(SONG_6A);
    }
}

void PrepScreenSubMenu_StartBattle(struct PrepMenuProc * proc)
{
    if (proc->sel_unit == 0)
    {
        if (proc->cur_counter != 0)
        {
            Proc_Goto(proc, 0xE);
            PlaySe(SONG_6A);
        }
        else
        {
            PlaySe(SONG_6C);
        }
    }
}

void ResetPrepMenuItem(void)
{
    gPrepMenuItemCnt = 0;
}

void SetPrepScreenMenuItem(
    void (* func)(struct PrepMenuProc * proc),
    fu8 is_submenu,
    int name,
    fu8 color,
    int desc,
    fu8 index)
{
    if (gPrepMenuItemCnt < 0x10)
    {
        gPrepMenuItems[gPrepMenuItemCnt].is_submenu = is_submenu;
        gPrepMenuItems[gPrepMenuItemCnt].func = func;
        gPrepMenuItems[gPrepMenuItemCnt].color = color;
        gPrepMenuItems[gPrepMenuItemCnt].name = name;
        gPrepMenuItems[gPrepMenuItemCnt].desc = desc;
        gPrepMenuItems[gPrepMenuItemCnt].index = index;

        gPrepMenuItemCnt++;
    }
}

bool PrepMenuOnSelected(struct PrepMenuProc * proc)
{
    int i;
    u8 disp_idx = 0;
    for (i = 0; i < gPrepMenuItemCnt; i++)
    {
        if (gPrepMenuItems[i].is_submenu != proc->submenu_level)
            continue;

        if (disp_idx == proc->disp_idx[proc->submenu_level])
        {
            if (gPrepMenuItems[i].color != TEXT_COLOR_SYSTEM_GRAY)
            {
                gPrepMenuItems[i].func(proc);
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        disp_idx++;
    }
    return FALSE;
}

u8 GetPrepMenuItemAmount(fu8 is_submenu)
{
    int i;
    u8 ret = 0;
    for (i = 0; i < gPrepMenuItemCnt; i++)
    {
        if (gPrepMenuItems[i].is_submenu == is_submenu)
            ret++;
    }
    return ret;
}

void PutPrepScreenMenuItems(struct Text * texts, fu8 is_submenu, u16 * tm, fu8 max_count)
{
    int i, disp_idx = 0;
    for (i = 0; i < gPrepMenuItemCnt; i++)
    {
        if (gPrepMenuItems[i].is_submenu != is_submenu)
            continue;

        ClearText(&texts[disp_idx]);
        Text_SetCursor(&texts[disp_idx], 0);
        Text_SetColor(
            &texts[disp_idx],
            gPrepMenuItems[i].color != TEXT_COLOR_SYSTEM_GRAY
                ? TEXT_COLOR_SYSTEM_WHITE
                : TEXT_COLOR_SYSTEM_GRAY);

        Text_DrawString(&texts[disp_idx], DecodeMsg(gPrepMenuItems[i].name));
        PutText(&texts[disp_idx], tm + TM_OFFSET(0, 2 * disp_idx));

        disp_idx++;
        if (disp_idx >= max_count)
            break;
    }
}

void PrepMenuHelpbox(struct PrepMenuProc * proc)
{
    int i;
    u8 disp_idx = 0;
    for (i = 0; i < gPrepMenuItemCnt; i++)
    {
        if (gPrepMenuItems[i].is_submenu != proc->submenu_level)
            continue;

        if (disp_idx == proc->disp_idx[proc->submenu_level])
        {
            if (proc->submenu_level == 0)
                StartHelpBox(0xC, proc->disp_idx[0] * 0x10 + 0x28, gPrepMenuItems[i].desc);
            else
                StartHelpBox(0xC, proc->disp_idx[proc->submenu_level] * 0x10 + 0x48, gPrepMenuItems[i].desc);

            proc->do_help = TRUE;
            return;
        }
        disp_idx = disp_idx + 1;
    }
}

u8 GetPrepScreenMenuCurrentItemIndex(struct PrepMenuProc * proc)
{
    int i;
    u8 disp_idx = 0;
    for (i = 0; i < gPrepMenuItemCnt; i++)
    {
        if (gPrepMenuItems[i].is_submenu != proc->submenu_level)
            continue;

        if (disp_idx == proc->disp_idx[proc->submenu_level])
        {
            return gPrepMenuItems[i].index;
        }
        disp_idx = disp_idx + 1;
    }
    return PREPMENUITEM_INVALID;
}

void SetPrepMenuItemUsability(u8 index, u8 color)
{
    int i;
    for (i = 0; i < gPrepMenuItemCnt; i++)
    {
        if (gPrepMenuItems[i].index == index)
        {
            gPrepMenuItems[i].color = color;
            break;
        }
    }
}

u8 GetPrepScreenMenuDispItemIndex(u8 target_disp_idx, fu8 is_submenu)
{
    int i;
    u8 disp_idx = 0;
    for (i = 0; i < gPrepMenuItemCnt; i++)
    {
        if (gPrepMenuItems[i].is_submenu != is_submenu)
            continue;

        if (disp_idx == target_disp_idx)
            return gPrepMenuItems[i].index;

        disp_idx++;
    }
    return PREPMENUITEM_INVALID;
}
