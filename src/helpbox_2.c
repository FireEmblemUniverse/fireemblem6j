#include "helpbox.h"

#include "armfunc.h"
#include "oam.h"
#include "sound.h"
#include "text.h"
#include "sprite.h"
#include "msg.h"
#include "util.h"
#include "item.h"
#include "talk.h"
#include "bm.h"
#include "chapter.h"
#include "chapterinfo.h"
#include "ui.h"

#include "constants/videoalloc_global.h"
#include "constants/songs.h"

struct HelpBoxSt
{
    /* 00 */ struct Font font;
    /* 18 */ struct Text text[3];
    /* 30 */ u16 oam2_base;
};

struct HelpBoxPrintProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad_29[0x58 - 0x29];
    /* 58 */ i32 item;
    /* 5C */ i32 msg;
    /* 60 */ u8 pad_60[0x64 - 0x60];
    /* 64 */ i16 line; // NOTE: might not be same proc
};

struct HelpDialogueProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ i32 x;
    /* 30 */ i32 y;
    /* 34 */ i32 msg;
    /* 38 */ u8 pal;
};

struct HelpDialoguePrintProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ char const * str;
    /* 30 */ struct Font * font;
    /* 34 */ struct Text * text[6];
    /* 4C */ i16 line;
    /* 4E */ i16 clock;
    /* 50 */ i16 clock_interval;
    /* 52 */ i16 chars_per_frame;
    /* 54 */ u8 pad_54[0x56 - 0x54];
    /* 56 */ u8 x, y;
    /* 58 */ u8 clear_pending;
    /* 5C */ i32 msg; // Maybe other proc?
};

int EWRAM_DATA unused_0203D408 = 0;
struct HelpBoxSt EWRAM_DATA gHelpBoxSt = { { 0 } };

void LoadHelpBoxGfx(void * vram, int pal)
{
    if (vram == NULL)
        vram = ((void *) VRAM) + 0x10000 + OBCHR_HELPBOX_180 * CHR_SIZE;

    if (pal < 0)
        pal = OBPAL_HELPBOX_5;

    pal = (pal & 15) + 0x10;

    Decompress(Img_HelpBox, vram);

    InitSpriteTextFont(&gHelpBoxSt.font, vram, pal);
    InitSpriteText(gHelpBoxSt.text + 0);
    InitSpriteText(gHelpBoxSt.text + 1);
    InitSpriteText(gHelpBoxSt.text + 2);
    SetTextFont(NULL);

    ApplyPalette(Pal_HelpBox, pal);

    gHelpBoxSt.oam2_base = OAM2_CHR(((uptr) vram) / CHR_SIZE) + OAM2_PAL(pal);
}

// unused
void LoadHelpBoxGfxTwoLines(void * vram, int pal)
{
    if (vram == NULL)
        vram = ((void *) VRAM) + 0x10000 + OBCHR_HELPBOX_180 * CHR_SIZE;

    if (pal < 0)
        pal = OBPAL_HELPBOX_5;

    pal = (pal & 15) + 0x10;

    Decompress(Img_HelpBox, vram);

    InitSpriteTextFont(&gHelpBoxSt.font, vram, pal);
    InitSpriteText(gHelpBoxSt.text + 0);
    InitSpriteText(gHelpBoxSt.text + 1);
    gHelpBoxSt.text[2].tile_width = 0; // ok???
    SetTextFont(NULL);

    ApplyPalette(Pal_HelpBox, pal);

    gHelpBoxSt.oam2_base = OAM2_CHR(((uptr) vram) / CHR_SIZE) + OAM2_PAL(pal);
}

void PutSpriteTalkBox(int x_box, int y_box, int w_box, int h_box)
{
    int y_count, x_count;
    int iy, ix, x_px, y_px;

    if (w_box < 0x20)
        w_box = 0x20;

    if (w_box > 0xC0)
        w_box = 0xC0;

    if (h_box < 0x10)
        h_box = 0x10;

    if (h_box > 0x30)
        h_box = 0x30;

    x_count = (w_box + 0x1F) / 0x20;
    y_count = (h_box + 0x0F) / 0x10;

    for (ix = x_count - 1; ix >= 0; ix--)
    {
        for (iy = y_count; iy >= 0; iy--)
        {
            x_px = (ix + 1) * 0x20;
            if (x_px > w_box)
                x_px = w_box;
            x_px = x_px - 0x20;

            y_px = (iy + 1) * 0x10;
            if (y_px > h_box)
                y_px = h_box;
            y_px = y_px - 0x10;

            PutSprite(0, x_box + x_px, y_box + y_px, Sprite_32x16, gHelpBoxSt.oam2_base + ix * 4 + iy * 0x40);
        }
    }

    for (ix = x_count - 1; ix >= 0; ix--)
    {
        x_px = (ix + 1) * 0x20;
        if (x_px > w_box)
            x_px = w_box;
        x_px = x_px - 0x20;

        PutSprite(0, x_box + x_px, y_box - 8, Sprite_32x8, gHelpBoxSt.oam2_base + 0x1B);
        PutSprite(0, x_box + x_px, y_box + h_box, Sprite_32x8_VFlipped, gHelpBoxSt.oam2_base + 0x1B);
    }

    for (iy = y_count; iy >= 0; iy--)
    {
        y_px = (iy + 1) * 0x10;
        if (y_px > h_box)
            y_px = h_box;
        y_px -= 0x10;

        PutSprite(0, x_box - 8, y_box + y_px, Sprite_8x16, gHelpBoxSt.oam2_base + 0x1F);
        PutSprite(0, x_box + w_box, y_box + y_px, Sprite_8x16_HFlipped, gHelpBoxSt.oam2_base + 0x1F);
    }

    PutSprite(0, x_box - 8, y_box - 8, Sprite_8x8, gHelpBoxSt.oam2_base + 0x3E);
    PutSprite(0, x_box + w_box, y_box - 8, Sprite_8x8_HFlipped, gHelpBoxSt.oam2_base + 0x3E);
    PutSprite(0, x_box - 8, y_box + h_box, Sprite_8x8_VFlipped, gHelpBoxSt.oam2_base + 0x3E);
    PutSprite(0, x_box + w_box, y_box + h_box, Sprite_8x8_HFlipped_VFlipped, gHelpBoxSt.oam2_base + 0x3E);
}

int DrawHelpBoxWeaponLabels(int item)
{
    Text_InsertDrawString(&gHelpBoxSt.text[0], 0x00, TEXT_COLOR_47CF, GetItemKindString(GetItemKind(item)));
    Text_InsertDrawString(&gHelpBoxSt.text[0], 0x24, TEXT_COLOR_47CF, JTEXT("射程"));
    Text_InsertDrawString(&gHelpBoxSt.text[0], 0x60, TEXT_COLOR_47CF, JTEXT("重さ"));
    Text_InsertDrawString(&gHelpBoxSt.text[1], 0x00, TEXT_COLOR_47CF, JTEXT("威力"));
    Text_InsertDrawString(&gHelpBoxSt.text[1], 0x30, TEXT_COLOR_47CF, JTEXT("命中"));
    Text_InsertDrawString(&gHelpBoxSt.text[1], 0x60, TEXT_COLOR_47CF, JTEXT("必殺"));

    return 2; // TODO: what?
}

void DrawHelpBoxWeaponStats(int item)
{
    Text_InsertDrawString(&gHelpBoxSt.text[0], 0x0C, TEXT_COLOR_456F, GetWeaponLevelStringFromExp(GetItemRequiredExp(item)));
    Text_InsertDrawString(&gHelpBoxSt.text[0], 0x38, TEXT_COLOR_456F, GetItemRangeString(item));
    Text_InsertDrawNumberOrBlank(&gHelpBoxSt.text[0], 0x80, TEXT_COLOR_456F, GetItemWeight(item));
    Text_InsertDrawNumberOrBlank(&gHelpBoxSt.text[1], 0x20, TEXT_COLOR_456F, GetItemMight(item));
    Text_InsertDrawNumberOrBlank(&gHelpBoxSt.text[1], 0x50, TEXT_COLOR_456F, GetItemHit(item));
    Text_InsertDrawNumberOrBlank(&gHelpBoxSt.text[1], 0x80, TEXT_COLOR_456F, GetItemCrit(item));
}

int DrawHelpBoxStaffLabels(int item)
{
    Text_InsertDrawString(&gHelpBoxSt.text[0], 0x00, TEXT_COLOR_47CF, JTEXT("杖"));
    Text_InsertDrawString(&gHelpBoxSt.text[0], 0x0C, TEXT_COLOR_456F, GetWeaponLevelStringFromExp(GetItemRequiredExp(item)));
    Text_InsertDrawString(&gHelpBoxSt.text[0], 0x24, TEXT_COLOR_47CF, JTEXT("射程"));
    Text_InsertDrawString(&gHelpBoxSt.text[0], 0x38, TEXT_COLOR_456F, GetItemRangeString(item));

    return 1; // TODO: what?
}

void TypeWritter_Loop(struct ProcTypeWritter * proc)
{
    int i;

    proc->clock--;

    if (proc->clock > 0)
        return;

    proc->clock = proc->clock_interval;

    SetTextFont(proc->font);

    for (i = 0; i < proc->chars_per_print; i++)
    {
        switch (*proc->str_it)
        {

            // TODO: control character constants

        case 0:
            Proc_Break(proc);
            break;

        case 1:
            proc->str_it++;
            proc->line++;
            continue;

        case 4:
            proc->str_it++;
            continue;

        default:
            proc->str_it = Text_DrawCharacter(proc->text[proc->line], proc->str_it);
            continue;

        }

        break;
    }

    SetTextFont(NULL);
}

struct ProcScr CONST_DATA ProcScr_TypeWritter[] =
{
    PROC_REPEAT(TypeWritter_Loop),
    PROC_END,
};

void DemoMonologueDisp_Main(struct ProcTypeWritter * proc)
{
    int i;

    SetTextFont(proc->font);

    // jumping around switches and for loops requires me to use labels
    // not the nicest

    for (i = 0; i < 6; i++)
    {
        struct Text * text = proc->text[i];

        Text_SetCursor(text, GetStringTextCenteredPos(text->tile_width * 8, proc->str_it));

        for (;;)
        {
            switch (*proc->str_it)
            {

                // TODO: control character constants

            case 0:
                goto end;

            case 4:
            case 5:
                proc->str_it++;
                continue;

            case 1:
                proc->str_it++;
                goto next_line;

            default:
                proc->str_it = Text_DrawCharacter(text, proc->str_it);
                continue;

            }
        }

    next_line:;
    }

end:
    // NOTE: is this supposed to be NULL?
    SetTextFont(proc->font);
}

struct ProcScr CONST_DATA ProcScr_DemoMonologueDisp[] =
{
    PROC_YIELD,
    PROC_CALL(DemoMonologueDisp_Main),
    PROC_END,
};

void HelpBoxPrint_DrawLabels(struct HelpBoxPrintProc * proc)
{
    int item = proc->item;

    SetTextFont(&gHelpBoxSt.font);
    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);

    switch (GetHelpBoxItemInfoKind(item))
    {

    case HELPBOX_INFO_NONE:
        proc->line = 0;
        break;

    case HELPBOX_INFO_WEAPON:
        DrawHelpBoxWeaponLabels(item);
        proc->line = 2;
        break;

    case HELPBOX_INFO_STAFF:
        DrawHelpBoxStaffLabels(item);
        proc->line = 1;
        break;

    }

    SetTextFont(NULL);

    Proc_Break(proc);
}

void HelpBoxPrint_DrawStats(struct HelpBoxPrintProc * proc)
{
    int item = proc->item;

    SetTextFont(&gHelpBoxSt.font);

    if (GetHelpBoxItemInfoKind(item) == HELPBOX_INFO_WEAPON)
    {
        DrawHelpBoxWeaponStats(item);
    }

    SetTextFont(NULL);

    Proc_Break(proc);
}

void HelpBoxPrint_StartText(struct HelpBoxPrintProc * proc)
{
    struct ProcTypeWritter * print_proc;

    SetTextFont(&gHelpBoxSt.font);
    SetTextFontGlyphs(TEXT_GLYPHS_TALK);
    Text_SetColor(&gHelpBoxSt.text[0], TEXT_COLOR_4DEF);
    Text_SetColor(&gHelpBoxSt.text[1], TEXT_COLOR_4DEF);
    Text_SetColor(&gHelpBoxSt.text[2], TEXT_COLOR_4DEF);
    SetTextFont(NULL);

    Proc_EndEach(ProcScr_TypeWritter);

    print_proc = SpawnProc(ProcScr_TypeWritter, PROC_TREE_3);
    print_proc->font = &gHelpBoxSt.font;
    print_proc->text[0] = &gHelpBoxSt.text[0];
    print_proc->text[1] = &gHelpBoxSt.text[1];
    print_proc->text[2] = &gHelpBoxSt.text[2];
    print_proc->line = proc->line;
    print_proc->str_it = DecodeMsg(proc->msg);
    print_proc->chars_per_print = 1;
    print_proc->clock = 0;

    switch (gPlaySt.config_talk_speed)
    {
    case PLAY_TALKSPEED_SLOW:
        print_proc->clock_interval = 2;
        break;

    case PLAY_TALKSPEED_NORMAL:
        print_proc->clock_interval = 1;
        break;

    case PLAY_TALKSPEED_FAST:
        print_proc->clock_interval = 1;
        print_proc->chars_per_print = 2;
        break;

    case PLAY_TALKSPEED_FASTEST:
        print_proc->clock_interval = 0;
        print_proc->chars_per_print = INT8_MAX;
        break;

    }
}

struct ProcScr CONST_DATA ProcScr_HelpBoxPrint[] =
{
    PROC_SLEEP(6),
    PROC_REPEAT(HelpBoxPrint_DrawLabels),
    PROC_REPEAT(HelpBoxPrint_DrawStats),
    PROC_CALL(HelpBoxPrint_StartText),
    PROC_END,
};

void StartHelpBoxPrint(int item, int msg)
{
    struct HelpBoxPrintProc * proc;

    proc = SpawnProc(ProcScr_HelpBoxPrint, PROC_TREE_3);

    proc->item = item;
    proc->msg = msg;
}

void ClearHelpBoxText(void)
{
    SetTextFont(&gHelpBoxSt.font);

    SpriteText_DrawBackground(&gHelpBoxSt.text[0]);
    SpriteText_DrawBackground(&gHelpBoxSt.text[1]);
    SpriteText_DrawBackground(&gHelpBoxSt.text[2]);

    Proc_EndEach(ProcScr_TypeWritter);
    Proc_EndEach(ProcScr_HelpBoxPrint);

    SetTextFont(NULL);
}

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

    w_inner = 0xE0 & (w_inner + 31); // align to 32 pixel multiple

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

bool IsHelpDialogueActive(void)
{
    if (FindProc(ProcScr_HelpDialogue) != NULL)
        return TRUE;

    return FALSE;
}

struct HelpBoxSt EWRAM_DATA gHelpDialogueSt = { { 0 } };

void LoadHelpDialogueGfx(void * vram, int pal)
{
    // identical to LoadHelpBoxGfx
    // except for gHelpDialogueSt instead of gHelpBoxSt

    if (vram == NULL)
        vram = ((void *) VRAM) + 0x10000 + OBCHR_HELPBOX_180 * CHR_SIZE;

    if (pal < 0)
        pal = OBPAL_HELPBOX_5;

    pal = (pal & 15) + 0x10;

    Decompress(Img_HelpBox, vram);

    InitSpriteTextFont(&gHelpDialogueSt.font, vram, pal);
    InitSpriteText(gHelpDialogueSt.text + 0);
    InitSpriteText(gHelpDialogueSt.text + 1);
    InitSpriteText(gHelpDialogueSt.text + 2);
    SetTextFont(NULL);

    ApplyPalette(Pal_HelpBox, pal);

    gHelpDialogueSt.oam2_base = OAM2_CHR(((uptr) vram) / CHR_SIZE) + OAM2_PAL(pal);
}

void ApplyHelpDialogueBoxPosition(struct HelpBoxProc * proc, int x, int y)
{
    int x_span, y_span;

    y_span = proc->h_box_fini + 0x10;

    if (proc->w_box_fini >= 0xC0)
        proc->w_box_fini = 0xC0;

    x_span = proc->w_box_fini + 0x10;

    proc->x_box_fini = x;

    if (proc->x_box_fini + x_span > DISPLAY_WIDTH)
        proc->x_box_fini = DISPLAY_WIDTH - x_span;

    proc->y_box_fini = y + 8;

    if (proc->y_box_fini + y_span > DISPLAY_HEIGHT)
        proc->y_box_fini = y - y_span - 8;

    proc->x_box_fini += 8;
}

void ApplyHelpDialogueBoxContentSize(struct HelpBoxProc * proc, int w, int h)
{
    w = 0xE0 & (w + 8 + 0x1F); // w + 8 aligned 0x20 up

    proc->w_box_fini = w;
    proc->h_box_fini = h;
}

void HelpDialogue_Init(struct HelpDialogueProc * proc)
{
    if (proc->pal == UINT8_MAX)
        LoadHelpDialogueGfx(NULL, -1);
    else
        LoadHelpDialogueGfx(NULL, proc->pal);

    StartHelpDialogueBox(proc->x, proc->y, proc->msg);
}

void HelpDialogue_Idle(void)
{
}

void HelpDialogue_Close(void)
{
    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);
    CloseHelpDialogueBox();
}

struct ProcScr CONST_DATA ProcScr_HelpDialogue[] =
{
    PROC_CALL(LockGame),
    PROC_SLEEP(1),
    PROC_CALL(HelpDialogue_Init),
    PROC_REPEAT(HelpDialogue_Idle),
PROC_LABEL(0),
    PROC_CALL(HelpDialogue_Close),
    PROC_SLEEP(10),
    PROC_CALL(UnlockGame),
    PROC_END,
};

void UpdateHelpDialogueBoxDisplay(struct HelpBoxProc * proc, int interpolate_method)
{
    int x_box = Interpolate(interpolate_method, proc->x_box_init, proc->x_box_fini, proc->timer, proc->timer_end);
    int y_box = Interpolate(interpolate_method, proc->y_box_init, proc->y_box_fini, proc->timer, proc->timer_end);
    int w_box = Interpolate(interpolate_method, proc->w_box_init, proc->w_box_fini, proc->timer, proc->timer_end);
    int h_box = Interpolate(interpolate_method, proc->h_box_init, proc->h_box_fini, proc->timer, proc->timer_end);

    proc->x_box = x_box;
    proc->y_box = y_box;

    PutSpriteHelpDialogueBox(x_box, y_box, w_box, h_box);
}

void HelpDialogueBox_OnLoop(struct HelpBoxProc * proc)
{
    UpdateHelpDialogueBoxDisplay(proc, INTERPOLATE_RCUBIC);

    if (proc->timer < proc->timer_end)
        proc->timer++;
}

void HelpDialogueBox_OnClose(struct HelpBoxProc * proc)
{
    ResetHelpBoxInitSize(proc);

    proc->timer_end = proc->timer_end / 3;
    proc->timer = proc->timer_end;
}

void HelpDialogueBox_WaitClose(struct HelpBoxProc * proc)
{
    UpdateHelpDialogueBoxDisplay(proc, INTERPOLATE_LINEAR);

    proc->timer--;

    if (proc->timer < 0)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_HelpDialogueBox[] =
{
    PROC_REPEAT(HelpDialogueBox_OnLoop),
    PROC_CALL(HelpDialogueBox_OnClose),
    PROC_REPEAT(HelpDialogueBox_WaitClose),
    PROC_END,
};

void CloseHelpDialogueBox(void)
{
    ClearHelpDialogueText();
    Proc_BreakEach(ProcScr_HelpDialogueBox);
}

void StartHelpDialogue(int x, int y, int msg, ProcPtr parent)
{
    // BUG: this function uses proc where it should use parent
    #if !BUGFIX
    #  define parent proc
    #endif

    struct HelpDialogueProc * proc;

    if (parent == NULL)
    {
        proc = SpawnProc(ProcScr_HelpDialogue, PROC_TREE_3);
    }
    else
    {
        proc = SpawnProcLocking(ProcScr_HelpDialogue, parent);
    }

    proc->x = x;
    proc->y = y;
    proc->msg = msg;
    proc->pal = UINT8_MAX;

    #if defined(parent)
    #  undef parent
    #endif
}

// unused
void StartHelpDialogueExt(int x, int y, int msg, ProcPtr parent, u8 pal)
{
    // BUG: this function uses proc where it should use parent
    #if !BUGFIX
    #  define parent proc
    #endif

    struct HelpDialogueProc * proc;

    if (parent == NULL)
    {
        proc = SpawnProc(ProcScr_HelpDialogue, PROC_TREE_3);
    }
    else
    {
        proc = SpawnProcLocking(ProcScr_HelpDialogue, parent);
    }

    proc->x = x;
    proc->y = y;
    proc->msg = msg;
    proc->pal = pal;

    #if defined(parent)
    #  undef parent
    #endif
}

void GetPagedStringTextBox(char const * str, int * out_w, int * out_h)
{
    i32 char_width;
    int w = 0, h = 16;

    *out_w = 0;
    *out_h = 0;

    for (;;)
    {
        switch (*str)
        {

            // TODO: control character constants

        case 1: // newline
            h += 16;

            if (*out_w < w)
                *out_w = w;

            w = 0;

            str++;
            continue;

        case 2:
        case 3:
            if (*out_w < w)
                *out_w = w;

            w = 0;

            if (*out_h < h)
                *out_h = h;

            h = 0;

            str++;
            continue;

        case 4:
            str++;
            continue;

        case 0: // end
            if (*out_w < w)
                *out_w = w;

            if (*out_h < h)
                *out_h = h;

            break;

        default:
            str = GetCharTextLen(str, &char_width);
            w += char_width;
            continue;

        }

        // case end
        break;
    }
}

void GetStringPageEndPos(char const * str, u8 * out_x, u8 * out_y)
{
    i32 char_width;
    int x = 0, y = 0;

    char const * it = str;

    *out_x = 0;
    *out_y = 0;

    SetTextFontGlyphs(TEXT_GLYPHS_TALK);

    for (;;)
    {
        switch (*it)
        {
            // TODO: control character constants

        case 4:
            it++;
            continue;

        case 1: // newline
            it++;
            y += 16;
            x = 0;
            continue;

        default:
            it = GetCharTextLen(it, &char_width);
            x += char_width;
            continue;

        case 2:
        case 3:
            break;

        case 0: // end
            break;

        }

        // case end, 2, 3
        break;
    }

    *out_x = x + 2;
    *out_y = y + 8;
}

void StartHelpDialogueBox(int x, int y, int msg)
{
    int w_inner, h_inner;
    struct HelpBoxProc * proc;

    proc = SpawnProc(ProcScr_HelpDialogueBox, PROC_TREE_3);

    SetHelpBoxInitPosition(proc, x, y);
    ResetHelpBoxInitSize(proc);

    proc->info = NULL;
    proc->timer = 0;
    proc->timer_end = 12;
    proc->item = 0;
    proc->msg = msg;

    SetTextFontGlyphs(TEXT_GLYPHS_TALK);
    GetPagedStringTextBox(DecodeMsg(proc->msg), &w_inner, &h_inner);
    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);

    ApplyHelpDialogueBoxContentSize(proc, w_inner, h_inner);
    ApplyHelpDialogueBoxPosition(proc, x, y);
    ClearHelpDialogueText();
    StartHelpDialoguePrint(proc->msg);
}

void PutSpriteHelpDialogueBox(int x_box, int y_box, int w_box, int h_box)
{
    // identical to PutSpriteTalkBox
    // except it refers to gHelpDialogueSt instead of gHelpBoxSt, and uses layer 2 instead of 0

    int y_count, x_count;
    int iy, ix, x_px, y_px;

    if (w_box < 0x20)
        w_box = 0x20;

    if (w_box > 0xC0)
        w_box = 0xC0;

    if (h_box < 0x10)
        h_box = 0x10;

    if (h_box > 0x30)
        h_box = 0x30;

    x_count = (w_box + 0x1F) / 0x20;
    y_count = (h_box + 0x0F) / 0x10;

    for (ix = x_count - 1; ix >= 0; ix--)
    {
        for (iy = y_count; iy >= 0; iy--)
        {
            x_px = (ix + 1) * 0x20;
            if (x_px > w_box)
                x_px = w_box;
            x_px = x_px - 0x20;

            y_px = (iy + 1) * 0x10;
            if (y_px > h_box)
                y_px = h_box;
            y_px = y_px - 0x10;

            PutSprite(2, x_box + x_px, y_box + y_px, Sprite_32x16, gHelpDialogueSt.oam2_base + ix * 4 + iy * 0x40);
        }
    }

    for (ix = x_count - 1; ix >= 0; ix--)
    {
        x_px = (ix + 1) * 0x20;
        if (x_px > w_box)
            x_px = w_box;
        x_px = x_px - 0x20;

        PutSprite(2, x_box + x_px, y_box - 8, Sprite_32x8, gHelpDialogueSt.oam2_base + 0x1B);
        PutSprite(2, x_box + x_px, y_box + h_box, Sprite_32x8_VFlipped, gHelpDialogueSt.oam2_base + 0x1B);
    }

    for (iy = y_count; iy >= 0; iy--)
    {
        y_px = (iy + 1) * 0x10;
        if (y_px > h_box)
            y_px = h_box;
        y_px -= 0x10;

        PutSprite(2, x_box - 8, y_box + y_px, Sprite_8x16, gHelpDialogueSt.oam2_base + 0x1F);
        PutSprite(2, x_box + w_box, y_box + y_px, Sprite_8x16_HFlipped, gHelpDialogueSt.oam2_base + 0x1F);
    }

    PutSprite(2, x_box - 8, y_box - 8, Sprite_8x8, gHelpDialogueSt.oam2_base + 0x3E);
    PutSprite(2, x_box + w_box, y_box - 8, Sprite_8x8_HFlipped, gHelpDialogueSt.oam2_base + 0x3E);
    PutSprite(2, x_box - 8, y_box + h_box, Sprite_8x8_VFlipped, gHelpDialogueSt.oam2_base + 0x3E);
    PutSprite(2, x_box + w_box, y_box + h_box, Sprite_8x8_HFlipped_VFlipped, gHelpDialogueSt.oam2_base + 0x3E);
}

void HelpDialoguePrint_Init(struct HelpDialoguePrintProc * proc)
{
    GetStringPageEndPos(proc->str, &proc->x, &proc->y);
}

void HelpDialoguePrint_Loop(struct HelpDialoguePrintProc * proc)
{
    int i, chars_per_frame, print_delay;
    struct HelpBoxProc * helpbox_proc;

    if (proc->clear_pending == 1)
    {
        SetTextFont(&gHelpDialogueSt.font);

        SpriteText_DrawBackground(&gHelpDialogueSt.text[0]);
        SpriteText_DrawBackground(&gHelpDialogueSt.text[1]);
        SpriteText_DrawBackground(&gHelpDialogueSt.text[2]);

        SetTextFont(NULL);

        proc->clear_pending = 0;

        return;
    }

    chars_per_frame = proc->chars_per_frame;

    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B | KEY_DPAD_ANY))
    {
        chars_per_frame = 0x80;
    }
    else
    {
        proc->clock--;

        if (proc->clock > 0)
            return;

        proc->clock = proc->clock_interval;
    }

    SetTextFont(proc->font);

    for (i = 0; i < chars_per_frame; i++)
    {
        switch (*proc->str)
        {

            // TODO: control character constants

        case 0:
            Proc_Break(proc);
            break;

        case 1:
            proc->str++;
            proc->line++;
            continue;

        case 4:
            proc->str++;
            continue;

        case 2:
        case 3:
            proc->line = 0;
            proc->str++;
            proc->clear_pending = 1;

            if (*proc->str == 1)
                proc->str++;

            helpbox_proc = FindProc(ProcScr_HelpDialogueBox);

            StartTalkWaitForInput(proc, helpbox_proc->x_box_fini + proc->x, helpbox_proc->y_box_fini + proc->y);
            GetStringPageEndPos(proc->str, &proc->x, &proc->y);

            break;

        default:
            proc->str = Text_DrawCharacter(proc->text[proc->line], proc->str);

            print_delay = GetTextPrintDelay();

            // kinda weird way of preventing delay 1 to play se every frame
            if (print_delay != 1 || (GetGameTime() % 2) != 0)
            {
                PlaySe(SONG_6E);
            }

            continue;

        }

        break;
    }

    SetTextFont(NULL);
}

void HelpDialoguePrint_End(struct HelpDialoguePrintProc * proc)
{
    Proc_Goto(FindProc(ProcScr_HelpDialogue), 0);
    Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_HelpDialoguePrint[] =
{
    PROC_YIELD,
    PROC_CALL(HelpDialoguePrint_Init),
    PROC_REPEAT(HelpDialoguePrint_Loop),
    PROC_CALL(HelpDialoguePrint_End),
    PROC_END,
};

void HelpDialogueStartPrint_Init(struct HelpBoxPrintProc * proc)
{
    struct HelpDialoguePrintProc * new_proc;

    SetTextFont(&gHelpDialogueSt.font);

    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM); // NOTE: useless
    SetTextFontGlyphs(TEXT_GLYPHS_TALK);
    Text_SetColor(&gHelpDialogueSt.text[0], TEXT_COLOR_4DEF);
    Text_SetColor(&gHelpDialogueSt.text[1], TEXT_COLOR_4DEF);
    Text_SetColor(&gHelpDialogueSt.text[2], TEXT_COLOR_4DEF);

    SetTextFont(NULL);

    Proc_EndEach(ProcScr_HelpDialoguePrint);

    new_proc = SpawnProc(ProcScr_HelpDialoguePrint, PROC_TREE_3);

    new_proc->font = &gHelpDialogueSt.font;
    new_proc->text[0] = &gHelpDialogueSt.text[0];
    new_proc->text[1] = &gHelpDialogueSt.text[1];
    new_proc->text[2] = &gHelpDialogueSt.text[2];
    new_proc->line = 0;
    new_proc->str = DecodeMsg(proc->msg);
    new_proc->clock_interval = GetTextPrintDelay();
    new_proc->chars_per_frame = new_proc->clock_interval != 0 ? 1 : 0x80;
    new_proc->clock = 0;
    new_proc->clear_pending = 0;
}

struct ProcScr CONST_DATA ProcScr_HelpDialogueStartPrint[] =
{
    PROC_SLEEP(6),
    PROC_CALL(HelpDialogueStartPrint_Init),
    PROC_END,
};

void StartHelpDialoguePrint(int msg)
{
    struct HelpBoxPrintProc * proc;

    proc = SpawnProc(ProcScr_HelpDialogueStartPrint, PROC_TREE_3);
    proc->msg = msg;
}

void ClearHelpDialogueText(void)
{
    SetTextFont(&gHelpDialogueSt.font);

    SpriteText_DrawBackground(&gHelpDialogueSt.text[0]);
    SpriteText_DrawBackground(&gHelpDialogueSt.text[1]);
    SpriteText_DrawBackground(&gHelpDialogueSt.text[2]);

    Proc_EndEach(ProcScr_HelpDialoguePrint);
    Proc_EndEach(ProcScr_HelpDialogueStartPrint);

    SetTextFont(NULL);
}
