#include "helpbox.h"

#include "oam.h"
#include "sound.h"
#include "sprite.h"
#include "msg.h"
#include "util.h"
#include "talk.h"
#include "chapter.h"

#include "constants/videoalloc_global.h"
#include "constants/songs.h"

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
        vram = OBJ_VRAM0 + OBCHR_HELPBOX_180 * CHR_SIZE;

    if (pal < 0)
        pal = OBPAL_HELPBOX_5;

    pal = (pal & 15) + 0x10;

    Decompress(Img_HelpBox, vram);

    InitSpriteTextFont(&gHelpDialogueSt.font, vram, pal);
    InitSpriteText(&gHelpDialogueSt.text[0]);
    InitSpriteText(&gHelpDialogueSt.text[1]);
    InitSpriteText(&gHelpDialogueSt.text[2]);
    SetTextFont(NULL);

    ApplyPalette(Pal_HelpBox, pal);

    gHelpDialogueSt.oam2_base = OAM2_CHR(((uptr) vram) / CHR_SIZE) + OAM2_PAL(pal);
}

void ApplyHelpDialogueBoxPosition(struct HelpBoxProc * proc, int x, int y)
{
    int x_span, y_span;

    y_span = proc->h_box_fini + 0x10;

    if (proc->w_box_fini >= TALKBOX_MAX_W)
        proc->w_box_fini = TALKBOX_MAX_W;

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
    w = (w + 8 + 0x1F) & 0xE0; // w + 8 aligned 0x20 up (the 8-bit mask also wraps widths of 0x100 and up)

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
    struct HelpDialogueProc * proc;

    // BUG: this function uses proc where it should use parent
#if BUGFIX
    if (parent == NULL)
    {
        proc = SpawnProc(ProcScr_HelpDialogue, PROC_TREE_3);
    }
    else
    {
        proc = SpawnProcLocking(ProcScr_HelpDialogue, parent);
    }
#else
    if (proc == NULL)
    {
        proc = SpawnProc(ProcScr_HelpDialogue, PROC_TREE_3);
    }
    else
    {
        proc = SpawnProcLocking(ProcScr_HelpDialogue, proc);
    }
#endif

    proc->x = x;
    proc->y = y;
    proc->msg = msg;
    proc->pal = UINT8_MAX;
}

// unused
void StartHelpDialogueExt(int x, int y, int msg, ProcPtr parent, u8 pal)
{
    struct HelpDialogueProc * proc;

    // BUG: this function uses proc where it should use parent
#if BUGFIX
    if (parent == NULL)
    {
        proc = SpawnProc(ProcScr_HelpDialogue, PROC_TREE_3);
    }
    else
    {
        proc = SpawnProcLocking(ProcScr_HelpDialogue, parent);
    }
#else
    if (proc == NULL)
    {
        proc = SpawnProc(ProcScr_HelpDialogue, PROC_TREE_3);
    }
    else
    {
        proc = SpawnProcLocking(ProcScr_HelpDialogue, proc);
    }
#endif

    proc->x = x;
    proc->y = y;
    proc->msg = msg;
    proc->pal = pal;
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
            break;

        case 2:
        case 3:
            if (*out_w < w)
                *out_w = w;

            w = 0;

            if (*out_h < h)
                *out_h = h;

            h = 0;

            str++;
            break;

        case 4:
            str++;
            break;

        case 0: // end
            if (*out_w < w)
                *out_w = w;

            if (*out_h < h)
                *out_h = h;

            // case end
            return;

        default:
            str = GetCharTextLen(str, &char_width);
            w += char_width;
            break;

        }
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
            break;

        case 1: // newline
            it++;
            y += 16;
            x = 0;
            break;

        case 2:
        case 3:
        case 0: // end
            // case end, 2, 3
            *out_x = x + 2;
            *out_y = y + 8;
            return;

        default:
            it = GetCharTextLen(it, &char_width);
            x += char_width;
            break;

        }
    }
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

    if (w_box < TALKBOX_MIN_W)
        w_box = TALKBOX_MIN_W;

    if (w_box > TALKBOX_MAX_W)
        w_box = TALKBOX_MAX_W;

    if (h_box < TALKBOX_MIN_H)
        h_box = TALKBOX_MIN_H;

    if (h_box > TALKBOX_MAX_H)
        h_box = TALKBOX_MAX_H;

    x_count = (w_box + 0x1F) / 0x20;
    y_count = (h_box + 0x0F) / 0x10;

    for (ix = x_count - 1; ix >= 0; ix--)
    {
        for (iy = y_count; iy >= 0; iy--)
        {
            x_px = (ix + 1) * 0x20;
            if (x_px > w_box)
                x_px = w_box;
            x_px -= 0x20;

            y_px = (iy + 1) * 0x10;
            if (y_px > h_box)
                y_px = h_box;
            y_px -= 0x10;

            PutSprite(2, x_box + x_px, y_box + y_px, Sprite_32x16, gHelpDialogueSt.oam2_base + ix * 4 + iy * 0x40);
        }
    }

    for (ix = x_count - 1; ix >= 0; ix--)
    {
        x_px = (ix + 1) * 0x20;
        if (x_px > w_box)
            x_px = w_box;
        x_px -= 0x20;

        PutSprite(2, x_box + x_px, y_box - 8, Sprite_32x8, gHelpDialogueSt.oam2_base + TALKBOX_CHR_EDGE_H);
        PutSprite(2, x_box + x_px, y_box + h_box, Sprite_32x8_VFlipped, gHelpDialogueSt.oam2_base + TALKBOX_CHR_EDGE_H);
    }

    for (iy = y_count; iy >= 0; iy--)
    {
        y_px = (iy + 1) * 0x10;
        if (y_px > h_box)
            y_px = h_box;
        y_px -= 0x10;

        PutSprite(2, x_box - 8, y_box + y_px, Sprite_8x16, gHelpDialogueSt.oam2_base + TALKBOX_CHR_EDGE_V);
        PutSprite(2, x_box + w_box, y_box + y_px, Sprite_8x16_HFlipped, gHelpDialogueSt.oam2_base + TALKBOX_CHR_EDGE_V);
    }

    PutSprite(2, x_box - 8, y_box - 8, Sprite_8x8, gHelpDialogueSt.oam2_base + TALKBOX_CHR_CORNER);
    PutSprite(2, x_box + w_box, y_box - 8, Sprite_8x8_HFlipped, gHelpDialogueSt.oam2_base + TALKBOX_CHR_CORNER);
    PutSprite(2, x_box - 8, y_box + h_box, Sprite_8x8_VFlipped, gHelpDialogueSt.oam2_base + TALKBOX_CHR_CORNER);
    PutSprite(2, x_box + w_box, y_box + h_box, Sprite_8x8_HFlipped_VFlipped, gHelpDialogueSt.oam2_base + TALKBOX_CHR_CORNER);
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
