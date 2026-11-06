#include "xmap.h"

#include "armfunc.h"
#include "map.h"
#include "proc.h"
#include "sprite.h"
#include "sound.h"
#include "util.h"
#include "gamecontroller.h"
#include "ui.h"
#include "savemenu.h"
#include "save_xmap.h"
#include "minimap.h"
#include "helpbox.h"
#include "oam.h"

#include "constants/songs.h"

EWRAM_DATA struct XmapState gXmapState = { 0 };

EWRAM_DATA struct Text gXmapTexts[MAX_TRIAL_CHAPTERS] = { 0 };
EWRAM_DATA u8 gXmapFadeTimer = 0;
EWRAM_DATA u8 gXmapWindowStep = 0;

bool Xmap_DrawInfoText(struct ProcXmap * proc)
{
    int i;

    proc->info_delay--;

    if (proc->info_delay > 0)
        return FALSE;

    proc->info_delay = XMAP_INFO_CHAR_DELAY;

    SetTextFont(&gXmapState.font);
    SetTextFontGlyphs(TEXT_GLYPHS_TALK);

    for (i = 0; i < proc->info_speed; i++)
    {
        switch (*proc->info_str)
        {
            case 0:
                SetTextFont(NULL);
                return TRUE;

            case 1:
            case 2:
            case 3:
                proc->info_str++;
                proc->info_line++;
                proc->info_delay = XMAP_INFO_LINE_DELAY;

                if (proc->info_line == XMAP_INFO_LINES)
                {
                    // NOTE: not resetting text font?
                    return TRUE;
                }

                break;

            case 4:
                proc->info_str++;
                break;

            default:
                proc->info_str = Text_DrawCharacter(&gXmapState.text[XMAP_TEXT_INFO + proc->info_line], proc->info_str);
                PlaySe(SONG_6E);
                break;
        }
    }

    SetTextFont(NULL);

    return FALSE;
}

void Xmap_OnHBlank(void)
{
    fu16 val = REG_VCOUNT;

    if (val == 0x20)
    {
        REG_BLDCNT = BLDCNT_TARGETA(1, 1, 1, 1, 0) | BLDCNT_EFFECT_DARKEN;
        (*(u16 volatile *)((void*) &REG_BLDY)) = gXmapFadeTimer / 2;
        return;
    }

    if (val == 0x78)
    {
        REG_BLDCNT = 0;
        return;
    }

    if (val == 0x84)
    {
        REG_BLDCNT = BLDCNT_TARGETA(1, 1, 1, 1, 0) | BLDCNT_EFFECT_DARKEN;
        REG_WIN0H = (((XMAP_WINDOW_STEPS - gXmapWindowStep) * 12) << 8) + (120 + (gXmapWindowStep * 12));
        REG_WINOUT = 0x000F;
        return;
    }

    if (val == 0x98)
    {
        REG_BLDCNT = 0;
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

    Decompress(Img_XmapObj, OBJ_VRAM0 + CHR_SIZE * OBCHR_XMAP_BANNER);
    ApplyObPalette(Pal_XmapObj, OBPAL_XMAP_BANNER);

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

    proc->minimap_x = gMapSize.x * 2 - 0x40;
    proc->minimap_y = gMapSize.y * 2 - 0x40;

    SetBgOffset(1, proc->minimap_x - 0x6C, proc->minimap_y - 0x1C);

    proc->selected_idx = 0;

    for (i = 0; i < proc->num_chapters; i++)
    {
        Text_SetParams(&gXmapTexts[i], 0, proc->chapter_list[i] < 0 ? TEXT_COLOR_SYSTEM_GREEN : TEXT_COLOR_SYSTEM_WHITE);
        Text_DrawString(&gXmapTexts[i], GetExtraMapChapterTitle(proc->chapter_list[i]));

        PutText(&gXmapTexts[i], gBg0Tm + TM_OFFSET(2, 6 + 2 * i));
    }

    proc->minimap_blend = 0;
    proc->scroll_clock = 0;
    proc->scroll_dir = 0;
    proc->info_state = XMAP_INFO_NONE;
    proc->confirm_choice = XMAP_CONFIRM_NO;
    proc->info_delay = XMAP_INFO_CHAR_DELAY;

    StartXmapSprites(proc);

    Decompress(Img_MonologueBG, (void *)VRAM + GetBgChrOffset(3));
    ApplyPalette(Pal_MonologueBG, BGPAL_XMAP_BACKGROUND);

    proc->bg_scroll_proc = StartXmapBgScroll(proc);

    gXmapFadeTimer = 0;
    gXmapWindowStep = 0;

    Xmap_DrawBanner(proc);

    StartGreenText(proc);
}

void Xmap_DrawBanner(struct ProcXmap * proc)
{
    SetTextFont(&gXmapState.font);
    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);

    SpriteText_DrawBackgroundExt(&gXmapState.text[XMAP_TEXT_BANNER], 0);

    Text_SetColor(&gXmapState.text[XMAP_TEXT_BANNER], TEXT_COLOR_SYSTEM_BLUE);
    Text_DrawString(&gXmapState.text[XMAP_TEXT_BANNER], GetExtraMapChapterTitle(proc->chapter_list[proc->selected_idx]));

    SetTextFont(NULL);
}

void Xmap_DrawInfoScreen(struct ProcXmap * proc)
{
    int i;

    SetTextFont(&gXmapState.font);
    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);

    for (i = 0; i < (int)ARRAY_COUNT(gXmapState.text); i++)
    {
        SpriteText_DrawBackgroundExt(&gXmapState.text[i], 0);
    }

    Text_DrawString(&gXmapState.text[XMAP_TEXT_CONFIRM], JTEXT("このマップでよろしいですか？"));
    Text_SetCursor(&gXmapState.text[XMAP_TEXT_CONFIRM], 0x80);
    Text_DrawString(&gXmapState.text[XMAP_TEXT_CONFIRM], JTEXT("はい"));
    Text_SetCursor(&gXmapState.text[XMAP_TEXT_CONFIRM], 0xA0);
    Text_DrawString(&gXmapState.text[XMAP_TEXT_CONFIRM], JTEXT("いいえ"));

    Text_SetColor(&gXmapState.text[XMAP_TEXT_BANNER], TEXT_COLOR_SYSTEM_BLUE);
    Text_DrawString(&gXmapState.text[XMAP_TEXT_BANNER], GetExtraMapChapterTitle(proc->chapter_list[proc->selected_idx]));
    Text_SetCursor(&gXmapState.text[XMAP_TEXT_BANNER], 0x58);
    Text_SetColor(&gXmapState.text[XMAP_TEXT_BANNER], TEXT_COLOR_SYSTEM_WHITE);
    Text_DrawString(&gXmapState.text[XMAP_TEXT_BANNER], JTEXT("目的："));
    Text_SetCursor(&gXmapState.text[XMAP_TEXT_BANNER], 0x70);
    Text_SetColor(&gXmapState.text[XMAP_TEXT_BANNER], TEXT_COLOR_SYSTEM_BLUE);
    Text_DrawString(&gXmapState.text[XMAP_TEXT_BANNER], DecodeExtraMapGoalMsg(proc->chapter_list[proc->selected_idx]));

    SetTextFont(NULL);
}

void Xmap_SelectLoop(struct ProcXmap * proc)
{
    int prev_select = proc->selected_idx;

    if ((gKeySt->pressed & KEY_BUTTON_A) != 0)
    {
        int w, h;

        SetTextFontGlyphs(TEXT_GLYPHS_TALK);

        Xmap_DrawInfoScreen(proc);
        proc->info_str = DecodeExtraMapInfoMsg(proc->chapter_list[proc->selected_idx]);

        GetPagedStringTextBox(proc->info_str, &w, &h);

        proc->info_x = (DISPLAY_WIDTH - w) / 2;
        proc->info_y = (0x58 - h) / 2;

        proc->info_line = 0;
        proc->info_speed = 1;

        PlaySe(SONG_6A);

        proc->info_state = XMAP_INFO_DRAWING;
        proc->confirm_choice = XMAP_CONFIRM_YES;

        SetOnHBlankA(Xmap_OnHBlank);

        Proc_Goto(proc, PL_XMAP_INFO);
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

        proc->scroll_dir = -1;
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

        proc->scroll_dir = +1;
    }
    else if ((gKeySt->pressed & KEY_BUTTON_B) != 0)
    {
        PlaySe(SONG_6B);
        Proc_Goto(proc, PL_XMAP_END);
    }

    if (proc->selected_idx != prev_select)
    {
        RemoveUiEntryHover(1, 0x26 + 2 * prev_select, 0x0A);
        PutUiEntryHover(1, 0x26 + 2 * proc->selected_idx, 0x0A);
        EnableBgSync(BG2_SYNC_BIT);
        Proc_Break(proc);
    }
}

void Xmap_MinimapScrollOut(struct ProcXmap * proc)
{
    if (proc->minimap_blend == 0)
    {
        PlaySe(SONG_66);
    }

    proc->minimap_blend += 2;
    proc->scroll_clock += 1;

    SetBgOffset(1, proc->minimap_x - 0x6C, proc->minimap_y - 0x1C + proc->scroll_dir * ((0x80 * proc->scroll_clock - 8 * proc->scroll_clock * proc->scroll_clock) / 8));

    SetBlendAlpha(0x10 - proc->minimap_blend, proc->minimap_blend);
    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 0);

    if (proc->minimap_blend == 0x10)
    {
        Proc_Break(proc);

        DrawMinimap(proc->chapter_list[proc->selected_idx], (void *)VRAM + BGCHR_XMAP_MINIMAP * CHR_SIZE, BGPAL_XMAP_MINIMAP);

        proc->minimap_x = gMapSize.x * 2 - 0x40;
        proc->minimap_y = gMapSize.y * 2 - 0x40;

        Xmap_DrawBanner(proc);

        EnableBgSync(BG1_SYNC_BIT);

        proc->scroll_clock = 0;
    }
}

void Xmap_MinimapScrollIn(struct ProcXmap * proc)
{
    proc->minimap_blend -= 2;
    proc->scroll_clock += 1;

    SetBgOffset(
        1, proc->minimap_x - 0x6C, proc->minimap_y - 0x1C + proc->scroll_dir * -0x40 + proc->scroll_dir * ((0x80 * proc->scroll_clock - 8 * proc->scroll_clock * proc->scroll_clock) / 8));

    SetBlendAlpha(0x10 - proc->minimap_blend, proc->minimap_blend);
    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 0);

    if (proc->minimap_blend == 0)
    {
        Proc_Break(proc);

        proc->scroll_clock = 0;
    }
}

void Xmap_DarkenLoop(struct ProcXmap * proc)
{
    gXmapFadeTimer++;

    if ((gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B)) != 0)
    {
        proc->info_speed = -1;
        gXmapFadeTimer = XMAP_DARKEN_FRAMES;
    }

    if (gXmapFadeTimer >= XMAP_DARKEN_FRAMES)
    {
        Proc_Break(proc);
    }
}

void Xmap_InfoTextLoop(struct ProcXmap * proc)
{
    if ((gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B)) != 0)
    {
        proc->info_speed = -1;
    }

    if (Xmap_DrawInfoText(proc))
    {
        PlaySe(SONG_6A);
        proc->info_state = XMAP_INFO_CONFIRM;
        Proc_Break(proc);
    }
}

void Xmap_OpenConfirmWindow(struct ProcXmap * proc)
{
    gXmapWindowStep++;

    if (gXmapWindowStep == XMAP_WINDOW_STEPS)
    {
        Proc_Break(proc);
    }
}

void Xmap_ConfirmLoop(struct ProcXmap * proc)
{
    u8 unused = proc->confirm_choice;

    if ((gKeySt->pressed & (KEY_DPAD_LEFT | KEY_DPAD_RIGHT)) != 0)
    {
        proc->confirm_choice = (proc->confirm_choice + 1) & 1;
        PlaySe(SONG_67);
    }
    else if ((gKeySt->pressed & KEY_BUTTON_B) != 0)
    {
        PlaySe(SONG_6B);

        proc->info_state = XMAP_INFO_NONE;

        SetOnHBlankA(NULL);

        gXmapFadeTimer = 0;
        gXmapWindowStep = 0;

        Proc_Break(proc);

        proc->confirm_choice = XMAP_CONFIRM_NO;
    }
    else if ((gKeySt->pressed & KEY_BUTTON_A) != 0)
    {
        if (proc->confirm_choice != XMAP_CONFIRM_YES)
        {
            PlaySe(SONG_6B);

            proc->info_state = XMAP_INFO_NONE;

            SetOnHBlankA(NULL);

            gXmapFadeTimer = 0;
            gXmapWindowStep = 0;

            Proc_Break(proc);
        }
        else
        {
            gPlaySt.chapter = proc->chapter_list[proc->selected_idx];

            PlaySe(SONG_6A);
            Proc_Goto(proc, PL_XMAP_END);
        }
    }
}

void Xmap_End(struct ProcXmap * proc)
{
    Proc_End(proc->bg_scroll_proc);

    if (proc->confirm_choice == XMAP_CONFIRM_YES)
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

void StartXmap(fu8 unused, ProcPtr parent)
{
    parent = (struct ProcXmap *) SpawnProcLocking(ProcScr_Xmap, parent);
    ((struct ProcXmap *) parent)->unused_29 = unused;
}

void XmapSprites_InitText(struct ProcXmapSprites * proc)
{
    int i;

    void * vram = OBJ_VRAM0 + CHR_SIZE * OBCHR_XMAP_SPRITETEXT;

    InitSpriteTextFont(&gXmapState.font, vram, 5);

    ApplyObPalettes(Pal_Text, OBPAL_XMAP_SPRITETEXT, 2);
    PAL_OBJ_COLOR(OBPAL_XMAP_SPRITETEXT, 0) = 0;

    SetTextFont(&gXmapState.font);

    for (i = 0; i < (int)ARRAY_COUNT(gXmapState.text); i++)
    {
        InitSpriteText(&gXmapState.text[i]);
        SpriteText_DrawBackgroundExt(&gXmapState.text[i], 0);
        Text_SetColor(&gXmapState.text[i], TEXT_COLOR_SYSTEM_WHITE);
    }

    SetTextFont(NULL);

    gXmapState.sprite_oam2 = OAM2_CHR((((uptr)vram) & 0x1FFFF) >> 5) + OAM2_PAL(OBPAL_XMAP_SPRITETEXT);
}

void XmapSprites_Init(struct ProcXmapSprites * proc)
{
    proc->trial_menu_proc = proc->proc_parent;
    proc->unused_30 = proc->trial_menu_proc->selected_idx;

    XmapSprites_InitText(proc);
}

u16 SHOULD_BE_CONST Sprite_XmapBannerBg[] =
{
    1,
    OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(OBCHR_XMAP_BANNER) + OAM2_LAYER(1),
};

u16 SHOULD_BE_CONST Sprite_XmapMapSelect[] =
{
    4,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(OBCHR_XMAP_BANNER + 0x04) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(OBCHR_XMAP_BANNER + 0x08) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(OBCHR_XMAP_BANNER + 0x0C) + OAM2_LAYER(1),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(96), OAM2_CHR(OBCHR_XMAP_BANNER + 0x10) + OAM2_LAYER(1),
};

struct ProcScr SHOULD_BE_CONST ProcScr_Xmap[] =
{
    PROC_SLEEP(1),
    PROC_CALL(Xmap_Init),
    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

PROC_LABEL(PL_XMAP_SELECT),
    PROC_REPEAT(Xmap_SelectLoop),
    PROC_REPEAT(Xmap_MinimapScrollOut),
    PROC_REPEAT(Xmap_MinimapScrollIn),
    PROC_GOTO(PL_XMAP_SELECT),

PROC_LABEL(PL_XMAP_INFO),
    PROC_REPEAT(Xmap_DarkenLoop),
    PROC_REPEAT(Xmap_InfoTextLoop),
    PROC_REPEAT(Xmap_OpenConfirmWindow),
    PROC_REPEAT(Xmap_ConfirmLoop),
    PROC_GOTO(PL_XMAP_SELECT),

PROC_LABEL(PL_XMAP_END),
    PROC_CALL(Xmap_TextEnd),
    PROC_CALL(StartSaveDrawFadeOut),
    PROC_SLEEP(0),
    PROC_CALL(Xmap_End),
    PROC_END,
};

void XmapSprites_Loop(struct ProcXmapSprites * proc)
{
    int i, j;

    for (i = 0; i < XMAP_BANNER_BG_SPRITES; i++)
    {
        // banner background
        PutSprite(11, 0x20 * i, 0, Sprite_XmapBannerBg, OAM2_PAL(OBPAL_XMAP_BANNER));
    }

    switch (proc->trial_menu_proc->info_state)
    {
        case XMAP_INFO_NONE:
            // banner image
            PutSprite(11, 4, 4, Sprite_XmapMapSelect, OAM2_PAL(OBPAL_XMAP_BANNER));

            PutUiHand(0x0E, 0x30 + proc->trial_menu_proc->selected_idx * 16);

            // banner text
            for (i = 0; i < XMAP_BANNER_TEXT_SPRITES; i++)
            {
                PutSpriteExt(4, 0x98 + 0x20 * i, 4, Sprite_32x16, gXmapState.sprite_oam2 + i * 4);
            }

            break;

        case XMAP_INFO_CONFIRM:
            PutUiHand(0x94 + 0x20 * proc->trial_menu_proc->confirm_choice, 0x86);

            // confirm text
            for (i = 0; i < XMAP_LINE_SPRITES; i++)
            {
                PutSprite(4, 0x18 + 0x20 * i, 0x86, Sprite_32x16, gXmapState.sprite_oam2 + i * 4 + XMAP_TEXT_CONFIRM * XMAP_TEXT_CHRS);
            }

            // fallthrough

        case XMAP_INFO_DRAWING:
            // banner text
            for (i = 0; i < XMAP_BANNER_TEXT_SPRITES; i++)
            {
                PutSpriteExt(4, 0x10 + 0x20 * i, 4, Sprite_32x16, gXmapState.sprite_oam2 + i * 4);
            }

            // scrolling exposition text
            for (j = 0; j < XMAP_INFO_LINES; j++)
            {
                for (i = 0; i < XMAP_LINE_SPRITES; i++)
                {
                    PutSprite(
                        4, proc->trial_menu_proc->info_x + 0x20 * i, proc->trial_menu_proc->info_y + 0x10 * j + 0x20 + OAM0_BLEND, Sprite_32x16,
                        gXmapState.sprite_oam2 + i * 4 + (XMAP_TEXT_INFO + j) * XMAP_TEXT_CHRS + OAM2_PAL(1));
                }
            }

            break;
    }
}

struct ProcScr SHOULD_BE_CONST ProcScr_XmapSprites[] =
{
    PROC_CALL(XmapSprites_Init),
    PROC_REPEAT(XmapSprites_Loop),
};

void StartXmapSprites(struct ProcXmap * proc)
{
    SpawnProc(ProcScr_XmapSprites, proc);
}

void XmapBgScroll_Init(struct ProcXmapBgScroll * proc)
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

    proc->timer = 0;
    proc->pos = 0;

    SetBgOffset(3, 0, 0);
    REG_BG3VOFS = 0;
}

void XmapBgScroll_Loop(struct ProcXmapBgScroll * proc)
{
    if (proc->timer == 3)
    {
        if (++proc->pos == 0x500)
        {
            proc->pos = 0;
        }

        SetBgOffset(3, 0, proc->pos & 0xFF);
        REG_BG3VOFS = proc->pos & 0xFF;

        proc->timer = 0;
    }

    proc->timer++;

    if ((proc->pos % 8) == 0)
    {
        fu16 ix;

        u16 const * src = Tsa_MonologueScrollingBG;
        u32 dst_row_off = TM_OFFSET(0, (proc->pos / 8 - 1) & 0x1F);
        fu8 src_row = (proc->pos / 8 + 30) % 40;

        for (ix = 0; ix < 30; ix++)
        {
            (gBg3Tm + dst_row_off)[30 - (ix + 1)] =
                (src + (40 - (src_row + 1)) * 30)[ix] +
                TILE_PAL_SAFE(BGPAL_XMAP_BACKGROUND) + TILE_HFLIP;
        }

        CpuFastCopy(gBg3Tm + dst_row_off, (u16*)(VRAM + 0x7800) + dst_row_off, 0x3C);
    }
}

struct ProcScr SHOULD_BE_CONST ProcScr_XmapBgScroll[] =
{
    PROC_CALL(XmapBgScroll_Init),
    PROC_SLEEP(0),
    PROC_REPEAT(XmapBgScroll_Loop),
    PROC_END,
};

struct ProcXmapBgScroll * StartXmapBgScroll(ProcPtr unused)
{
    return SpawnProc(ProcScr_XmapBgScroll, PROC_TREE_VSYNC);
}
