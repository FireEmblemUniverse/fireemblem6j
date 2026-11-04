#include "helpbox.h"

#include "oam.h"
#include "sound.h"
#include "msg.h"
#include "util.h"
#include "item.h"
#include "ui.h"

#include "constants/songs.h"

void HelpBoxAlt_OnLoop(struct HelpBoxProc * proc)
{
    UpdateHelpBoxDisplay(proc, INTERPOLATE_RCUBIC);

    if (proc->timer < proc->timer_end)
        proc->timer++;
}

void HelpBoxAlt_OnClose(struct HelpBoxProc * proc)
{
    ResetHelpBoxAltInitSize(proc);
    SetHelpBoxAltInitPosition(proc, proc->info->x, proc->info->y);

    proc->timer_end = proc->timer_end / 3;
    proc->timer = proc->timer_end;
}

void HelpBoxAlt_WaitClose(struct HelpBoxProc * proc)
{
    UpdateHelpBoxDisplay(proc, INTERPOLATE_LINEAR);

    proc->timer--;

    if (proc->timer < 0)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_HelpBoxAlt[] =
{
    PROC_REPEAT(HelpBoxAlt_OnLoop),
    PROC_CALL(HelpBoxAlt_OnClose),
    PROC_REPEAT(HelpBoxAlt_WaitClose),
    PROC_END,
};

void StartHelpBoxAlt(int x, int y, int msg)
{
    static struct HelpBoxInfo EWRAM_DATA static_info = { 0 };

    static_info.x = x;
    static_info.y = y;
    static_info.msg = msg;
    static_info.redirect = NULL;
    static_info.populate = NULL;

    StartHelpBoxAltControl(&static_info);
}

struct HelpBoxInfo const * EWRAM_DATA gLastHelpBoxAltInfo = NULL;

void StartHelpBoxAltExt(struct HelpBoxInfo const * info)
{
    struct HelpBoxProc * proc;
    int w_text_box, h_text_box;

    proc = FindProc(ProcScr_HelpBoxAlt);

    if (proc == NULL)
    {
        proc = SpawnProc(ProcScr_HelpBoxAlt, PROC_TREE_3);

        PlaySe(SONG_70);

        SetHelpBoxAltInitPosition(proc, info->x, info->y);
        ResetHelpBoxAltInitSize(proc);
    }
    else
    {
        proc->x_box_init = proc->x_box;
        proc->y_box_init = proc->y_box;
        proc->w_box_init = proc->w_box_fini;
        proc->h_box_init = proc->h_box_fini;
    }

    proc->info = info;
    proc->timer = 0;
    proc->timer_end = 12;
    proc->msg = info->msg;

    SetTextFontGlyphs(TEXT_GLYPHS_TALK);
    GetStringTextBox(DecodeMsg(proc->msg), &w_text_box, &h_text_box);
    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);

    ApplyHelpBoxAltContentSize(proc, w_text_box, h_text_box);
    ApplyHelpBoxAltPosition(proc, info->x, info->y);
    ClearHelpBoxText();
    StartHelpBoxPrint(proc->item, proc->msg);

    gLastHelpBoxAltInfo = info;
}

void CloseHelpBoxAlt(void)
{
    PlaySe(SONG_71);
    ClearHelpBoxText();
    Proc_BreakEach(ProcScr_HelpBoxAlt);
}

void HelpBoxAltControl_OnInitBox(struct HelpBoxProc * proc)
{
    proc->move_key_bit = 0;

    if (proc->info->redirect)
        proc->info->redirect(proc);

    StartHelpBoxAltExt(proc->info);
}

void HelpBoxAltControl_WaitA(struct HelpBoxProc * proc)
{
    if (gKeySt->pressed & KEY_BUTTON_A)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_HelpBoxAltControl[] =
{
    PROC_SLEEP(1),
PROC_LABEL(0),
    PROC_CALL(HelpBoxAltControl_OnInitBox),
    PROC_REPEAT(HelpBoxAltControl_WaitA),
    PROC_CALL(CloseHelpBoxAlt),
    PROC_END,
};

void EndHelpBoxAltControl(struct HelpBoxProc * proc)
{
    CloseHelpBoxAlt();
    Proc_End(proc);
}

void StartHelpBoxAltControl(struct HelpBoxInfo const * info)
{
    struct HelpBoxProc * proc;

    proc = SpawnProc(ProcScr_HelpBoxAltControl, PROC_TREE_3);
    proc->info = info;
}

bool IsHelpBoxAltControlActive(void)
{
    return FindProc(ProcScr_HelpBoxAltControl) != NULL;
}

void ApplyHelpBoxAltContentSize(struct HelpBoxProc * proc, int w_inner, int h_inner)
{
    // identical to ApplyHelpBoxContentSize
    // except it calls GetHelpBoxAltItemInfoKind

    w_inner = (w_inner + 31) & 0xE0; // align to 32 pixel multiple (the 8-bit mask also wraps widths of 0x100 and up)

    switch (GetHelpBoxAltItemInfoKind(proc->item))
    {

    case HELPBOX_INFO_WEAPON:
        w_inner = 0xA0;
        h_inner += 0x20;
        break;

    case HELPBOX_INFO_STAFF:
        if (w_inner < 0x60)
            w_inner = 0x60;
        h_inner += 0x10;
        break;

    }

    proc->w_box_fini = w_inner;
    proc->h_box_fini = h_inner;
}

void ApplyHelpBoxAltPosition(struct HelpBoxProc * proc, int x, int y)
{
    // identical to ApplyHelpBoxPosition
    // except it doesn't care for gHelpBoxOrigin

    int x_span = proc->w_box_fini + 0x10;
    int y_span = proc->h_box_fini + 0x10;

    proc->x_box_fini = x - 0x10 - x_span / 6;

    if (proc->x_box_fini < 0)
        proc->x_box_fini = 0;

    if (proc->x_box_fini + x_span > DISPLAY_WIDTH)
        proc->x_box_fini = DISPLAY_WIDTH - x_span;

    proc->y_box_fini = y + 0x10;

    if (proc->y_box_fini + y_span > DISPLAY_HEIGHT)
        proc->y_box_fini = y - y_span;

    proc->x_box_fini += 8;
    proc->y_box_fini += 8;
}

void SetHelpBoxAltInitPosition(struct HelpBoxProc * proc, int x, int y)
{
    // identical to SetHelpBoxInitPosition
    // except it doesn't care for gHelpBoxOrigin

    proc->x_box_init = x;
    proc->y_box_init = y;
}

void ResetHelpBoxAltInitSize(struct HelpBoxProc * proc)
{
    // identical to ResetHelpBoxInitSize

    proc->w_box_init = 32;
    proc->h_box_init = 16;
}

int GetHelpBoxAltItemInfoKind(int item)
{
    // identical to GetHelpBoxItemInfoKind

    if (GetItemAttributes(item) & ITEM_ATTR_LOCK_DRAGON)
        return HELPBOX_INFO_NONE;

    if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
        return HELPBOX_INFO_WEAPON;

    if (GetItemAttributes(item) & ITEM_ATTR_STAFF)
        return HELPBOX_INFO_STAFF;

    return HELPBOX_INFO_NONE;
}

void HelpBoxAltLockHelper_Loop(struct HelpBoxProc * proc)
{
    if (gKeySt->pressed & KEY_BUTTON_A)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_HelpBoxAltLockHelper[] =
{
    PROC_REPEAT(HelpBoxAltLockHelper_Loop),
    PROC_END,
};

// unused
int StartLockingHelpBoxAlt(int msg, ProcPtr parent)
{
    LoadHelpBoxGfx(NULL, -1);
    StartHelpBoxAlt(GetUiHandPrevX(), GetUiHandPrevY(), msg);
    SpawnProcLocking(ProcScr_HelpBoxAltLockHelper, parent);
    return 1; // ?
}
