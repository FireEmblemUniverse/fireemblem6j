#include "helpbox.h"

#include "oam.h"
#include "text.h"
#include "sprite.h"
#include "msg.h"
#include "util.h"
#include "item.h"

#include "constants/videoalloc_global.h"

int EWRAM_DATA unused_0203D408 = 0;
struct HelpBoxSt EWRAM_DATA gHelpBoxSt = { { 0 } };

void LoadHelpBoxGfx(void * vram, int pal)
{
    if (vram == NULL)
        vram = OBJ_VRAM0 + OBCHR_HELPBOX_180 * CHR_SIZE;

    if (pal < 0)
        pal = OBPAL_HELPBOX_5;

    pal = (pal & 15) + 0x10;

    Decompress(Img_HelpBox, vram);

    InitSpriteTextFont(&gHelpBoxSt.font, vram, pal);
    InitSpriteText(&gHelpBoxSt.text[0]);
    InitSpriteText(&gHelpBoxSt.text[1]);
    InitSpriteText(&gHelpBoxSt.text[2]);
    SetTextFont(NULL);

    ApplyPalette(Pal_HelpBox, pal);

    gHelpBoxSt.oam2_base = OAM2_CHR(((uptr) vram) / CHR_SIZE) + OAM2_PAL(pal);
}

// unused
void LoadHelpBoxGfxTwoLines(void * vram, int pal)
{
    if (vram == NULL)
        vram = OBJ_VRAM0 + OBCHR_HELPBOX_180 * CHR_SIZE;

    if (pal < 0)
        pal = OBPAL_HELPBOX_5;

    pal = (pal & 15) + 0x10;

    Decompress(Img_HelpBox, vram);

    InitSpriteTextFont(&gHelpBoxSt.font, vram, pal);
    InitSpriteText(&gHelpBoxSt.text[0]);
    InitSpriteText(&gHelpBoxSt.text[1]);
    gHelpBoxSt.text[2].tile_width = 0; // ok??? Skips InitSpriteText, so no tiles are reserved for a third line
    SetTextFont(NULL);

    ApplyPalette(Pal_HelpBox, pal);

    gHelpBoxSt.oam2_base = OAM2_CHR(((uptr) vram) / CHR_SIZE) + OAM2_PAL(pal);
}

void PutSpriteTalkBox(int x_box, int y_box, int w_box, int h_box)
{
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

            PutSprite(0, x_box + x_px, y_box + y_px, Sprite_32x16, gHelpBoxSt.oam2_base + ix * 4 + iy * 0x40);
        }
    }

    for (ix = x_count - 1; ix >= 0; ix--)
    {
        x_px = (ix + 1) * 0x20;
        if (x_px > w_box)
            x_px = w_box;
        x_px -= 0x20;

        PutSprite(0, x_box + x_px, y_box - 8, Sprite_32x8, gHelpBoxSt.oam2_base + TALKBOX_CHR_EDGE_H);
        PutSprite(0, x_box + x_px, y_box + h_box, Sprite_32x8_VFlipped, gHelpBoxSt.oam2_base + TALKBOX_CHR_EDGE_H);
    }

    for (iy = y_count; iy >= 0; iy--)
    {
        y_px = (iy + 1) * 0x10;
        if (y_px > h_box)
            y_px = h_box;
        y_px -= 0x10;

        PutSprite(0, x_box - 8, y_box + y_px, Sprite_8x16, gHelpBoxSt.oam2_base + TALKBOX_CHR_EDGE_V);
        PutSprite(0, x_box + w_box, y_box + y_px, Sprite_8x16_HFlipped, gHelpBoxSt.oam2_base + TALKBOX_CHR_EDGE_V);
    }

    PutSprite(0, x_box - 8, y_box - 8, Sprite_8x8, gHelpBoxSt.oam2_base + TALKBOX_CHR_CORNER);
    PutSprite(0, x_box + w_box, y_box - 8, Sprite_8x8_HFlipped, gHelpBoxSt.oam2_base + TALKBOX_CHR_CORNER);
    PutSprite(0, x_box - 8, y_box + h_box, Sprite_8x8_VFlipped, gHelpBoxSt.oam2_base + TALKBOX_CHR_CORNER);
    PutSprite(0, x_box + w_box, y_box + h_box, Sprite_8x8_HFlipped_VFlipped, gHelpBoxSt.oam2_base + TALKBOX_CHR_CORNER);
}

int DrawHelpBoxWeaponLabels(int item)
{
    Text_InsertDrawString(&gHelpBoxSt.text[0], 0x00, TEXT_COLOR_47CF, GetItemKindString(GetItemKind(item)));
    Text_InsertDrawString(&gHelpBoxSt.text[0], 0x24, TEXT_COLOR_47CF, JTEXT("射程"));
    Text_InsertDrawString(&gHelpBoxSt.text[0], 0x60, TEXT_COLOR_47CF, JTEXT("重さ"));
    Text_InsertDrawString(&gHelpBoxSt.text[1], 0x00, TEXT_COLOR_47CF, JTEXT("威力"));
    Text_InsertDrawString(&gHelpBoxSt.text[1], 0x30, TEXT_COLOR_47CF, JTEXT("命中"));
    Text_InsertDrawString(&gHelpBoxSt.text[1], 0x60, TEXT_COLOR_47CF, JTEXT("必殺"));

    return 2; // Label line count; HelpBoxPrint_DrawLabels ignores it and hardcodes 2
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

    return 1; // Label line count; HelpBoxPrint_DrawLabels ignores it and hardcodes 1
}

void TypeWriter_Loop(struct ProcTypeWriter * proc)
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

struct ProcScr CONST_DATA ProcScr_TypeWriter[] =
{
    PROC_REPEAT(TypeWriter_Loop),
    PROC_END,
};

static inline void DemoMonologueDisp_PrintLines(struct ProcTypeWriter * proc)
{
    int i;

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
                return;

            case 4:
            case 5:
                proc->str_it++;
                continue;

            case 1:
                proc->str_it++;
                break;

            default:
                proc->str_it = Text_DrawCharacter(text, proc->str_it);
                continue;

            }

            break;
        }
    }
}

void DemoMonologueDisp_Main(struct ProcTypeWriter * proc)
{
    SetTextFont(proc->font);

    DemoMonologueDisp_PrintLines(proc);

    // NOTE: is this supposed to be NULL? Every other print path resets the font to NULL here
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
    struct ProcTypeWriter * print_proc;

    SetTextFont(&gHelpBoxSt.font);
    SetTextFontGlyphs(TEXT_GLYPHS_TALK);
    Text_SetColor(&gHelpBoxSt.text[0], TEXT_COLOR_4DEF);
    Text_SetColor(&gHelpBoxSt.text[1], TEXT_COLOR_4DEF);
    Text_SetColor(&gHelpBoxSt.text[2], TEXT_COLOR_4DEF);
    SetTextFont(NULL);

    Proc_EndEach(ProcScr_TypeWriter);

    print_proc = SpawnProc(ProcScr_TypeWriter, PROC_TREE_3);
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

    Proc_EndEach(ProcScr_TypeWriter);
    Proc_EndEach(ProcScr_HelpBoxPrint);

    SetTextFont(NULL);
}
