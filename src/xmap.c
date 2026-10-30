#include "xmap.h"

#include "armfunc.h"
#include "map.h"
#include "proc.h"
#include "sprite.h"
#include "sound.h"
#include "util.h"
#include "text.h"
#include "bm.h"
#include "gamecontroller.h"
#include "ui.h"
#include "hardware.h"
#include "savemenu.h"
#include "save_xmap.h"
#include "minimap.h"
#include "helpbox.h"
#include "oam.h"

#include "constants/songs.h"

#define BGCHR_XMAP_MINIMAP 0x100
#define BGPAL_XMAP_MINIMAP 0x0A // x2
#define BGPAL_XMAP_BACKGROUND 0x0F

#define OBCHR_XMAP_BANNER 0x80
#define OBCHR_XMAP_SPRITETEXT 0x100

#define OBPAL_XMAP_BANNER 4
#define OBPAL_XMAP_SPRITETEXT 5 // x2

EWRAM_DATA struct XmapState gXmapState = { 0 };

EWRAM_DATA struct Text gXmapTexts[MAX_TRIAL_CHAPTERS] = { 0 };
EWRAM_DATA u8 gUnk_0203DC6C = 0;
EWRAM_DATA u8 gUnk_0203DC6D = 0;

bool func_fe6_0808AA84(struct ProcXmap * proc)
{
    int i;

    proc->unk_46--;

    if (proc->unk_46 > 0)
        return FALSE;

    proc->unk_46 = 4;

    SetTextFont(&gXmapState.font);
    SetTextFontGlyphs(TEXT_GLYPHS_TALK);

    for (i = 0; i < proc->unk_45; i++)
    {
        switch (*proc->unk_40)
        {
            case 0:
                SetTextFont(NULL);
                return TRUE;

            case 1:
            case 2:
            case 3:
                proc->unk_40++;
                proc->unk_44++;
                proc->unk_46 = 8;

                if (proc->unk_44 == 5)
                {
                    // NOTE: not resetting text font?
                    return TRUE;
                }

                break;

            case 4:
                proc->unk_40++;
                break;

            default:
                proc->unk_40 = Text_DrawCharacter(&gXmapState.text[2 + proc->unk_44], proc->unk_40);
                PlaySe(SONG_6E);
                break;
        }
    }

    SetTextFont(NULL);

    return FALSE;
}

void func_fe6_0808AB44(void)
{
    fu16 val = REG_VCOUNT;

    if (val == 0x20)
    {
        REG_BLDCNT = 0xCF;
        (*(u16 volatile *)((void*) &REG_BLDY)) = gUnk_0203DC6C / 2;
        return;
    }

    if (val == 0x78)
    {
        REG_BLDCNT = 0x00;
        return;
    }

    if (val == 0x84)
    {
        REG_BLDCNT = 0xCF;
        REG_WIN0H = (((10 - gUnk_0203DC6D) * 12) << 8) + (120 + (gUnk_0203DC6D * 12));
        REG_WINOUT = 0x000F;
        return;
    }

    if (val == 0x98)
    {
        REG_BLDCNT = 0x00;
        REG_WINOUT = 0xFFFF;
        return;
    }
}

void Xmap_Init(struct ProcXmap * proc)
{
    int i;

    InitBgs(NULL);
    ResetTextFont();
    ResetText();
    ApplySystemObjectsGraphics();
    UnpackUiWindowFrameGraphics();
    InitSystemTextFont();

    SetDispEnable(1, 1, 1, 1, 1);

    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg1_ct.priority = 2;
    gDispIo.bg2_ct.priority = 1;
    gDispIo.bg3_ct.priority = 3;

    SetWinEnable(1, 0, 0);
    SetWin0Layers(1, 1, 1, 1, 1);
    SetWin0Box(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    SetWOutLayers(1, 1, 1, 1, 1);

    SetBlankChr(0);
    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    TmFill(gBg2Tm, 0);

    Decompress(Img_XmapObj, (void *)VRAM + 0x10000 + CHR_SIZE * OBCHR_XMAP_BANNER);
    ApplyPalette(Pal_XmapObj, 0x10 + OBPAL_XMAP_BANNER);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

    for (i = 0; i < (int)ARRAY_COUNT(gXmapTexts); i++)
    {
        InitText(&gXmapTexts[i], 10);
        ClearText(&gXmapTexts[i]); // redundant
    }

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(2, -8, 0);

    ListAvailableTrialChapters(proc->chapter_list);

    proc->num_chapters = 0;

    for (i = 0; i < (int)ARRAY_COUNT(gXmapTexts); i++)
    {
        if (proc->chapter_list[i] != 0)
        {
            proc->num_chapters++;
        }
        else
        {
            break;
        }
    }

    PutUiWindowFrame(0, 5, 12, 2 + 2 * proc->num_chapters, UI_WINDOW_FILL);

    // copy window frame from bg1 to bg2 (work around hardwired bg1 in PutUiWindowFrame)
    TmCopyRect(gBg1Tm, gBg2Tm, 12, 19);
    TmFillRect(gBg1Tm, 12, 19, 0);

    PutUiEntryHover(1, 0x26, 10);

    DrawMinimap(proc->chapter_list[0], (void *)VRAM + CHR_SIZE * BGCHR_XMAP_MINIMAP, BGPAL_XMAP_MINIMAP);

    proc->unk_30 = gMapSize.x * 2 - 0x40;
    proc->unk_34 = gMapSize.y * 2 - 0x40;

    SetBgOffset(1, proc->unk_30 - 0x6C, proc->unk_34 - 0x1C);

    proc->selected_idx = 0;

    for (i = 0; i < proc->num_chapters; i++)
    {
        Text_SetParams(&gXmapTexts[i], 0, proc->chapter_list[i] < 0 ? TEXT_COLOR_SYSTEM_GREEN : TEXT_COLOR_SYSTEM_WHITE);
        Text_DrawString(&gXmapTexts[i], GetExtraMapChapterTitle(proc->chapter_list[i]));

        PutText(&gXmapTexts[i], gBg0Tm + TM_OFFSET(2, 6 + 2 * i));
    }

    proc->unk_2C = 0;
    proc->unk_2D = 0;
    proc->unk_2E = 0;
    proc->unk_3E = 0;
    proc->unk_3F = 1;
    proc->unk_46 = 4;

    func_fe6_0808B7A0(proc);

    Decompress(Img_MonologueBG, (void *)VRAM + GetBgChrOffset(3));
    ApplyPalette(Pal_MonologueBG, BGPAL_XMAP_BACKGROUND);

    proc->vsync_proc = func_fe6_0808B928(proc);

    gUnk_0203DC6C = 0;
    gUnk_0203DC6D = 0;

    func_fe6_0808AEFC(proc);

    StartGreenText(proc);
}

void func_fe6_0808AEFC(struct ProcXmap * proc)
{
    SetTextFont(&gXmapState.font);
    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);

    SpriteText_DrawBackgroundExt(&gXmapState.text[0], 0);

    Text_SetColor(&gXmapState.text[0], TEXT_COLOR_SYSTEM_BLUE);
    Text_DrawString(&gXmapState.text[0], GetExtraMapChapterTitle(proc->chapter_list[proc->selected_idx]));

    SetTextFont(NULL);
}

void func_fe6_0808AF4C(struct ProcXmap * proc)
{
    int i;

    SetTextFont(&gXmapState.font);
    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);

    for (i = 0; i < (int)ARRAY_COUNT(gXmapState.text); i++)
    {
        SpriteText_DrawBackgroundExt(&gXmapState.text[i], 0);
    }

    Text_DrawString(&gXmapState.text[1], JTEXT("このマップでよろしいですか？"));
    Text_SetCursor(&gXmapState.text[1], 0x80);
    Text_DrawString(&gXmapState.text[1], JTEXT("はい"));
    Text_SetCursor(&gXmapState.text[1], 0xA0);
    Text_DrawString(&gXmapState.text[1], JTEXT("いいえ"));

    Text_SetColor(&gXmapState.text[0], TEXT_COLOR_SYSTEM_BLUE);
    Text_DrawString(&gXmapState.text[0], GetExtraMapChapterTitle(proc->chapter_list[proc->selected_idx]));
    Text_SetCursor(&gXmapState.text[0], 0x58);
    Text_SetColor(&gXmapState.text[0], TEXT_COLOR_SYSTEM_WHITE);
    Text_DrawString(&gXmapState.text[0], JTEXT("目的："));
    Text_SetCursor(&gXmapState.text[0], 0x70);
    Text_SetColor(&gXmapState.text[0], 2);
    Text_DrawString(&gXmapState.text[0], DecodeExtraMapGoalMsg(proc->chapter_list[proc->selected_idx]));

    SetTextFont(NULL);
}

void func_fe6_0808B028(struct ProcXmap * proc)
{
    int prev_select = proc->selected_idx;

    if ((gKeySt->pressed & KEY_BUTTON_A) != 0)
    {
        int w, h;

        SetTextFontGlyphs(TEXT_GLYPHS_TALK);

        func_fe6_0808AF4C(proc);
        proc->unk_40 = DecodeExtraMapInfoMsg(proc->chapter_list[proc->selected_idx]);

        func_fe6_08071C00(proc->unk_40, &w, &h);

        proc->unk_47 = (DISPLAY_WIDTH - w) / 2;
        proc->unk_48 = (0x58 - h) / 2;

        proc->unk_44 = 0;
        proc->unk_45 = 1;

        PlaySe(SONG_6A);

        proc->unk_3E = 1;
        proc->unk_3F = 0;

        SetOnHBlankA(func_fe6_0808AB44);

        Proc_Goto(proc, PL_XMAP_1);
    }
    else if ((gKeySt->repeated & KEY_DPAD_UP) != 0)
    {
        if (proc->selected_idx != 0)
        {
            proc->selected_idx = proc->selected_idx - 1;
        }
        else if ((gKeySt->pressed & KEY_DPAD_UP) != 0)
        {
            proc->selected_idx = proc->num_chapters - 1;
        }

        proc->unk_2E = -1;
    }
    else if ((gKeySt->repeated & KEY_DPAD_DOWN) != 0)
    {
        if (proc->selected_idx + 1 < proc->num_chapters)
        {
            proc->selected_idx = proc->selected_idx + 1;
        }
        else if ((gKeySt->pressed & KEY_DPAD_DOWN) != 0)
        {
            proc->selected_idx = 0;
        }

        proc->unk_2E = +1;
    }
    else if ((gKeySt->pressed & KEY_BUTTON_B) != 0)
    {
        PlaySe(SONG_6B);
        Proc_Goto(proc, PL_XMAP_3);
    }

    if (proc->selected_idx != prev_select)
    {
        RemoveUiEntryHover(1, 0x26 + 2 * prev_select, 0x0A);
        PutUiEntryHover(1, 0x26 + 2 * proc->selected_idx, 0x0A);
        EnableBgSync(BG2_SYNC_BIT);
        Proc_Break(proc);
    }
}

void func_fe6_0808B194(struct ProcXmap * proc)
{
    if (proc->unk_2C == 0)
    {
        PlaySe(SONG_66);
    }

    proc->unk_2C += 2;
    proc->unk_2D += 1;

    SetBgOffset(1, proc->unk_30 - 0x6C, proc->unk_34 - 0x1C + proc->unk_2E * ((0x80 * proc->unk_2D - 8 * proc->unk_2D * proc->unk_2D) / 8));

    SetBlendAlpha(0x10 - proc->unk_2C, proc->unk_2C);
    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 0);

    if (proc->unk_2C == 0x10)
    {
        Proc_Break(proc);

        DrawMinimap(proc->chapter_list[proc->selected_idx], (void *)VRAM + BGCHR_XMAP_MINIMAP * CHR_SIZE, BGPAL_XMAP_MINIMAP);

        proc->unk_30 = gMapSize.x * 2 - 0x40;
        proc->unk_34 = gMapSize.y * 2 - 0x40;

        func_fe6_0808AEFC(proc);

        EnableBgSync(BG1_SYNC_BIT);

        proc->unk_2D = 0;
    }
}

void func_fe6_0808B2BC(struct ProcXmap * proc)
{
    proc->unk_2C -= 2;
    proc->unk_2D += 1;

    SetBgOffset(
        1, proc->unk_30 - 0x6C, proc->unk_34 - 0x1C + proc->unk_2E * -0x40 + proc->unk_2E * ((0x80 * proc->unk_2D - 8 * proc->unk_2D * proc->unk_2D) / 8));

    SetBlendAlpha(0x10 - proc->unk_2C, proc->unk_2C);
    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 0);

    if (proc->unk_2C == 0)
    {
        Proc_Break(proc);

        proc->unk_2D = 0;
    }
}

void func_fe6_0808B378(struct ProcXmap * proc)
{
    gUnk_0203DC6C++;

    if ((gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B)) != 0)
    {
        proc->unk_45 = -1;
        gUnk_0203DC6C = 20;
    }

    if (gUnk_0203DC6C >= 20)
    {
        Proc_Break(proc);
    }
}

void func_fe6_0808B3B8(struct ProcXmap * proc)
{
    if ((gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B)) != 0)
    {
        proc->unk_45 = -1;
    }

    if (func_fe6_0808AA84(proc))
    {
        PlaySe(SONG_6A);
        proc->unk_3E = 2;
        Proc_Break(proc);
    }
}

void func_fe6_0808B40C(struct ProcXmap * proc)
{
    gUnk_0203DC6D++;

    if (gUnk_0203DC6D == 10)
    {
        Proc_Break(proc);
    }
}

void func_fe6_0808B430(struct ProcXmap * proc)
{
    u8 unused = proc->unk_3F;

    if ((gKeySt->pressed & (KEY_DPAD_LEFT | KEY_DPAD_RIGHT)) != 0)
    {
        proc->unk_3F = (proc->unk_3F + 1) & 1;
        PlaySe(SONG_67);
    }
    else if ((gKeySt->pressed & KEY_BUTTON_B) != 0)
    {
        PlaySe(SONG_6B);

        proc->unk_3E = 0;

        SetOnHBlankA(NULL);

        gUnk_0203DC6C = 0;
        gUnk_0203DC6D = 0;

        Proc_Break(proc);

        proc->unk_3F = 1;
    }
    else if ((gKeySt->pressed & KEY_BUTTON_A) != 0)
    {
        if (proc->unk_3F != 0)
        {
            PlaySe(SONG_6B);

            proc->unk_3E = 0;

            SetOnHBlankA(NULL);

            gUnk_0203DC6C = 0;
            gUnk_0203DC6D = 0;

            Proc_Break(proc);
        }
        else
        {
            gPlaySt.chapter = proc->chapter_list[proc->selected_idx];

            PlaySe(SONG_6A);
            Proc_Goto(proc, PL_XMAP_3);
        }
    }
}

void Xmap_End(struct ProcXmap * proc)
{
    Proc_End(proc->vsync_proc);

    if (proc->unk_3F == 0)
    {
        StartBgmVolumeChange(0x80, 0x00, 16, NULL);
        SetNextGameAction(GAME_ACTION_6);
        Proc_End(proc->proc_parent); // dangerous?
        SetOnHBlankA(NULL);
    }
    else
    {
        ForceEnableSounds();
    }
}

void Xmap_TextEnd(struct ProcXmap * proc)
{
    EndGreenText();
}

// BUG: the parameter type is incorrect?
void StartXmap(fu8 arg_0, struct ProcXmap * proc)
{
    proc = SpawnProcLocking(ProcScr_Xmap, proc);
    proc->unk_29 = arg_0;
}

void func_fe6_0808B598(struct ProcXmapSprites * proc)
{
    int i;

    void * vram = (void *)VRAM + 0x10000 + CHR_SIZE * OBCHR_XMAP_SPRITETEXT;

    InitSpriteTextFont(&gXmapState.font, vram, 5);

    ApplyPalettes(Pal_Text, 0x10 + OBPAL_XMAP_SPRITETEXT, 2);
    gPal[PAL_OFFSET(0x10 + OBPAL_XMAP_SPRITETEXT) + 0] = 0;

    SetTextFont(&gXmapState.font);

    for (i = 0; i < (int)ARRAY_COUNT(gXmapState.text); i++)
    {
        InitSpriteText(&gXmapState.text[i]);
        SpriteText_DrawBackgroundExt(&gXmapState.text[i], 0);
        Text_SetColor(&gXmapState.text[i], TEXT_COLOR_SYSTEM_WHITE);
    }

    SetTextFont(NULL);

    gXmapState.unk_50 = OAM2_CHR((((uptr)vram) & 0x1FFFF) >> 5) + OAM2_PAL(0x10 + OBPAL_XMAP_SPRITETEXT);
}

void func_fe6_0808B628(struct ProcXmapSprites * proc)
{
    proc->trial_menu_proc = proc->proc_parent;
    proc->unk_30 = proc->trial_menu_proc->selected_idx;

    func_fe6_0808B598(proc);
}

u16 SHOULD_BE_CONST Sprite_0868A568[] =
{
    1,
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x80) + OAM2_LAYER(1),
};

u16 SHOULD_BE_CONST Sprite_Unk_0868A570[] =
{
    4,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x84) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x88) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x8C) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(96), OAM2_CHR(0x90) + OAM2_LAYER(1),
};

struct ProcScr SHOULD_BE_CONST ProcScr_Xmap[] =
{
    PROC_SLEEP(1),
    PROC_CALL(Xmap_Init),
    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

PROC_LABEL(PL_XMAP_0),
    PROC_REPEAT(func_fe6_0808B028),
    PROC_REPEAT(func_fe6_0808B194),
    PROC_REPEAT(func_fe6_0808B2BC),
    PROC_GOTO(PL_XMAP_0),

PROC_LABEL(PL_XMAP_1),
    PROC_REPEAT(func_fe6_0808B378),
    PROC_REPEAT(func_fe6_0808B3B8),
    PROC_REPEAT(func_fe6_0808B40C),
    PROC_REPEAT(func_fe6_0808B430),
    PROC_GOTO(PL_XMAP_0),

PROC_LABEL(PL_XMAP_3),
    PROC_CALL(Xmap_TextEnd),
    PROC_CALL(StartSaveDrawFadeOut),
    PROC_SLEEP(0),
    PROC_CALL(Xmap_End),
    PROC_END,
};

void func_fe6_0808B640(struct ProcXmapSprites * proc)
{
    int i, j;

    for (i = 0; i < 8; i++)
    {
        // banner background
        PutSprite(11, 0x20 * i, 0, Sprite_0868A568, OAM2_PAL(OBPAL_XMAP_BANNER));
    }

    switch (proc->trial_menu_proc->unk_3E)
    {
        case 0:
            // banner image
            PutSprite(11, 4, 4, Sprite_Unk_0868A570, OAM2_PAL(OBPAL_XMAP_BANNER));

            PutUiHand(0x0E, 0x30 + proc->trial_menu_proc->selected_idx * 16);

            // banner text
            for (i = 0; i < 7; i++)
            {
                PutSpriteExt(4, 0x98 + 0x20 * i, 4, Sprite_32x16, gXmapState.unk_50 + i * 4);
            }

            break;

        case 2:
            PutUiHand(0x94 + 0x20 * proc->trial_menu_proc->unk_3F, 0x86);

            // confirm text
            for (i = 0; i < 6; i++)
            {
                PutSprite(4, 0x18 + 0x20 * i, 0x86, Sprite_32x16, gXmapState.unk_50 + i * 4 + 0x40);
            }

            // fallthrough

        case 1:
            // banner text
            for (i = 0; i < 7; i++)
            {
                PutSpriteExt(4, 0x10 + 0x20 * i, 4, Sprite_32x16, gXmapState.unk_50 + i * 4);
            }

            // scrolling exposition text
            for (j = 0; j < 5; j++)
            {
                for (i = 0; i < 6; i++)
                {
                    PutSprite(
                        4, proc->trial_menu_proc->unk_47 + 0x20 * i, proc->trial_menu_proc->unk_48 + 0x10 * j + 0x20 + OAM0_BLEND, Sprite_32x16,
                        gXmapState.unk_50 + i * 4 + (j + 2) * 0x40 + OAM2_PAL(1));
                }
            }

            break;
    }
}

struct ProcScr SHOULD_BE_CONST ProcScr_XmapSprites[] =
{
    PROC_CALL(func_fe6_0808B628),
    PROC_REPEAT(func_fe6_0808B640),
};

void func_fe6_0808B7A0(struct ProcXmap * proc)
{
    SpawnProc(ProcScr_XmapSprites, proc);
}

void func_fe6_0808B7B4(struct ProcXmapVSync * proc)
{
    fu16 ix, iy;

    TmFill(gBg3Tm, 0);

    for (iy = 0; iy < 32; iy++)
    {
        u16 const * src = Tsa_MonologueScrollingBG;
        u32 row_offset = TM_OFFSET(0, iy);

        for (ix = 0; ix < 30; ix++)
        {
            (gBg3Tm + row_offset)[30 - (ix + 1)] =
                (src + (40 - (iy + 1)) * 30)[ix] +
                TILE_PAL_SAFE(BGPAL_XMAP_BACKGROUND) + TILE_HFLIP;
        }
    }

    EnableBgSync(BG3_SYNC_BIT);

    proc->unk_2C = 0;
    proc->unk_2A = 0;

    SetBgOffset(3, 0, 0);
    REG_BG3VOFS = 0;
}

void func_fe6_0808B854(struct ProcXmapVSync * proc)
{
    if (proc->unk_2C == 3)
    {
        if (++proc->unk_2A == 0x500)
        {
            proc->unk_2A = 0;
        }

        SetBgOffset(3, 0, proc->unk_2A & 0xFF);
        REG_BG3VOFS = proc->unk_2A & 0xFF;

        proc->unk_2C = 0;
    }

    proc->unk_2C++;

    if ((proc->unk_2A % 8) == 0)
    {
        fu16 ix;

        u16 const * src = Tsa_MonologueScrollingBG;
        u32 dst_row_off = TM_OFFSET(0, (proc->unk_2A / 8 - 1) & 0x1F);
        fu8 src_row = (proc->unk_2A / 8 + 30) % 40;

        for (ix = 0; ix < 30; ix++)
        {
            (gBg3Tm + dst_row_off)[30 - (ix + 1)] =
                (src + (40 - (src_row + 1)) * 30)[ix] +
                TILE_PAL_SAFE(BGPAL_XMAP_BACKGROUND) + TILE_HFLIP;
        }

        CpuFastCopy(gBg3Tm + dst_row_off, (u16*)(VRAM + 0x7800) + dst_row_off, 0x3C);
    }
}

struct ProcScr SHOULD_BE_CONST ProcScr_XmapVSync[] =
{
    PROC_CALL(func_fe6_0808B7B4),
    PROC_SLEEP(0),
    PROC_REPEAT(func_fe6_0808B854),
    PROC_END,
};

struct ProcXmapVSync * func_fe6_0808B928(ProcPtr unused)
{
    return SpawnProc(ProcScr_XmapVSync, PROC_TREE_VSYNC);
}
