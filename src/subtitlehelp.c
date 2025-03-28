#include "subtitlehelp.h"

#include "hardware.h"
#include "oam.h"
#include "proc.h"
#include "text.h"
#include "sprite.h"
#include "map.h"
#include "bm.h"

#include "constants/videoalloc_global.h"

void PutSubtitleHelpText(struct SubtitleHelpProc * proc, int y)
{
    static u16 lut[] =
    {
        0x00, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x18,
              0x44, 0x48, 0x4C, 0x50, 0x54, 0x58,
    };

    int i;

    for (i = 0; i < 9; ++i)
    {
        int x = i*32 - 32 + proc->text_offset;
        int num = (proc->text_num + i) % proc->text_count;

        PutSprite(2, x, y,
            Sprite_32x16, OAM2_CHR(OBCHR_SUBTITLEHELP_TEXT) + OAM2_PAL(OBPAL_SUBTITLEHELP_TEXT) + lut[num]);
    }
}

void InitSubtitleHelpText(struct SubtitleHelpProc * proc)
{
    enum { TEXT_WIDTH = DISPLAY_WIDTH-16 };

    int line;

    char const * it = proc->string;

    InitSpriteTextFont(&proc->font, OBJ_VRAM0 + OBCHR_SUBTITLEHELP_TEXT*CHR_SIZE, 0x10+OBPAL_SUBTITLEHELP_TEXT);
    SetTextFontGlyphs(TEXT_GLYPHS_TALK);

    ApplyPalette(Pal_Text+0x10, 0x10+OBPAL_SUBTITLEHELP_TEXT);

    for (line = 0; line < 2; ++line)
    {
        InitSpriteText(proc->text+line);

        SpriteText_DrawBackgroundExt(proc->text+line, 0);
        Text_SetColor(proc->text+line, TEXT_COLOR_0123);
    }

    line = 0;

    while (*it > 1)
    {
        it = Text_DrawCharacter(proc->text+line, it);

        if (Text_GetCursor(proc->text+line) > TEXT_WIDTH)
        {
            i32 width;

            // NOTE: this assumes characters are always encoded on two bytes
            it -= 2;
            line += 1;

            GetCharTextLen(it, &width);

            Text_SetCursor(proc->text+line,
                Text_GetCursor(proc->text+0) + 32 - width - TEXT_WIDTH);
        }
    }

    proc->text_count = ((GetStringTextLen(proc->string)+16) >> 5) + 1;
    proc->text_num = proc->text_count - 1;

    SetTextFont(NULL);
}

void SubtitleHelpDarkenerOnHBlank(void)
{
    static u8 bldyLut[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, // 128 .. 135
        0, 0, 0, 0, 1, 2, 3, 4, // 136 .. 143
        5, 6, 7, 7, 7, 7, 7, 7, // 144 .. 151
        7, 7, 7, 7, 7, 7, 7, 7, // 152 .. 159
    };

    u16 vcount = REG_VCOUNT;

    if (vcount < 140 || vcount > 160)
    {
        REG_BLDCNT   = *(u16 *)(&gDispIo.blend_ct);
        REG_BLDALPHA = *(u16 *)(&gDispIo.blend_coef_a);
        REG_BLDY     = gDispIo.blend_y;
    }
    else
    {
        int bldy;

        bldy = bldyLut[vcount - 128];
        bldy = bldy - gBmSt.alt_blend_a_ca;

        if (bldy < 0)
            bldy = 0;

        REG_BLDCNT = BLDCNT_EFFECT_DARKEN | BLDCNT_TARGETA(0, 0, 1, 1, 0) | BLDCNT_TARGETA_BD;
        REG_BLDY   = bldy;
    }
}

void SubtitleHelpDarkener_Init(ProcPtr proc)
{
    gBmSt.alt_blend_a_ca = 8;
    SetOnHBlankA(SubtitleHelpDarkenerOnHBlank);
}

void SubtitleHelpDarkener_FadeIn(ProcPtr proc)
{
    if (gBmSt.alt_blend_a_ca != 0)
        gBmSt.alt_blend_a_ca -= 1;
}

void SubtitleHelpDarkener_FadeOut(ProcPtr proc)
{
    gBmSt.alt_blend_a_ca += 1;

    if (gBmSt.alt_blend_a_ca == 8)
    {
        SetOnHBlankA(NULL);
        Proc_Break(proc);
    }
}

struct ProcScr CONST_DATA ProcScr_SubtitleHelpDarkener[] =
{
    PROC_END_DUPS,

    PROC_CALL(SubtitleHelpDarkener_Init),
    PROC_REPEAT(SubtitleHelpDarkener_FadeIn),
    PROC_REPEAT(SubtitleHelpDarkener_FadeOut),

    PROC_END,
};

void SubtitleHelp_Init(struct SubtitleHelpProc * proc)
{
    proc->text_offset = 31;
    proc->text_show_clock = 6;

    SpawnProc(ProcScr_SubtitleHelpDarkener, PROC_TREE_3);
}

void SubtitleHelp_OnEnd(struct SubtitleHelpProc * proc)
{
    gBmSt.camera_max.y -= 16;
    CameraMove_08016290(NULL);

    Proc_BreakEach(ProcScr_SubtitleHelpDarkener);
}

void SubtitleHelp_Loop(struct SubtitleHelpProc * proc)
{
    static u8 lut[] =
    {
        144, 145, 146, 148, 150, 153, 156,
    };

    PutSubtitleHelpText(proc, lut[proc->text_show_clock]);

    if (proc->text_show_clock != 0)
        proc->text_show_clock--;

    proc->text_offset--;

    if (proc->text_offset < 0)
    {
        proc->text_offset = 31;
        proc->text_num++;
    }
}

struct ProcScr CONST_DATA ProcScr_SubtitleHelp[] =
{
    PROC_19,
    PROC_19,

    PROC_ONEND(SubtitleHelp_OnEnd),
    PROC_YIELD,

    PROC_CALL(SubtitleHelp_Init),
    PROC_REPEAT(SubtitleHelp_Loop),

    PROC_BLOCK,
};

void StartSubtitleHelp(ProcPtr parent, char const * str)
{
    if (gPlaySt.config_no_subtitle_help != TRUE)
    {
        struct SubtitleHelpProc * proc;

        proc = SpawnProc(ProcScr_SubtitleHelp, parent);
        proc->string = str;

        InitSubtitleHelpText(proc);

        func_fe6_080192E4();

        gBmSt.camera_max.y += 16;
    }
}

void EndSubtitleHelp(void)
{
    Proc_EndEach(ProcScr_SubtitleHelp);
}

bool IsSubtitleHelpActive(void)
{
    return Proc_Exists(ProcScr_SubtitleHelp);
}
