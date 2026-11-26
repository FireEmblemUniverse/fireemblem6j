#include "prelude.h"
#include "proc.h"
#include "ui.h"
#include "oam.h"
#include "sprite.h"
#include "unitsprite.h"
#include "unitlistscreen.h"
#include "chapterinfo.h"
#include "prepscreen.h"

void PrepMenuFade_Init(struct ProcPrepFade * proc)
{
    int i;

    proc->timer = 0;

    for (i = 0; i < 0x200; i++)
        gPrepFadePal[i] = gPal[i];
}

void PrepMenuFadeOut_Loop(struct ProcPrepFade * proc)
{
    #define SCALE 0x10
    int i;
    u8 coef = proc->timer;

    SetDispEnable(1, 1, 1, 1, 1);

    for (i = 0; i < 0x200; i++)
    {
        int b_scaled = (gPrepFadePal[i] & RGB5_MASK_B) * coef;
        int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

        int g_scaled = (gPrepFadePal[i] & RGB5_MASK_G) * coef;
        int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

        int r_scaled = (gPrepFadePal[i] & RGB5_MASK_R) * coef;
        int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

        gPal[i] = b_out | g_out | r_out;
    }

    EnablePalSync();
    proc->timer++;
    if (coef == 0x10)
        Proc_Break(proc);

    #undef SCALE
}

void PrepMenuFadeIn_Loop(struct ProcPrepFade * proc)
{
    #define SCALE 0x10
    int i;
    u8 coef = 0x10 - proc->timer;

    for (i = 0; i < 0x200; i++)
    {
        int b_scaled = (gPrepFadePal[i] & RGB5_MASK_B) * coef;
        int b_out = (b_scaled / SCALE) & RGB5_MASK_B;

        int g_scaled = (gPrepFadePal[i] & RGB5_MASK_G) * coef;
        int g_out = (g_scaled / SCALE) & RGB5_MASK_G;

        int r_scaled = (gPrepFadePal[i] & RGB5_MASK_R) * coef;
        int r_out = (r_scaled / SCALE) & RGB5_MASK_R;

        gPal[i] = b_out | g_out | r_out;
    }

    EnablePalSync();
    proc->timer++;
    if (coef == 0)
    {
        SetDispEnable(0, 0, 0, 0, 0);
        Proc_Break(proc);
    }

    #undef SCALE
}

struct ProcScr CONST_DATA ProcScr_PrepMenuFadeOut[] =
{
    PROC_19,
    PROC_CALL(PrepMenuFade_Init),
    PROC_REPEAT(PrepMenuFadeOut_Loop),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_PrepMenuFadeIn[] =
{
    PROC_19,
    PROC_CALL(PrepMenuFade_Init),
    PROC_REPEAT(PrepMenuFadeIn_Loop),
    PROC_END,
};

void StartPrepMenuFadeOut(ProcPtr proc)
{
    SpawnProcLocking(ProcScr_PrepMenuFadeOut, proc);
}

void StartPrepMenuFadeIn(ProcPtr proc)
{
    SpawnProcLocking(ProcScr_PrepMenuFadeIn, proc);
}

void PrepDisp_ChangeSubmenuDesc(struct ProcPrepUpperDisp * proc, int idx)
{
    u8 _idx = idx;

    if (proc->desc_idx != _idx)
        proc->desc_idx = _idx;

    proc->desc_changing = TRUE;
}

void PrepDisp_SetWorldMapInfo(struct ProcPrepUpperDisp * proc, fu8 x, fu8 y, int index_gaiden)
{
    proc->cursor_x = x;
    proc->cursor_y = y;
    proc->index_gaiden = index_gaiden;
    proc->disp_x = GetChapterInfo(gPlaySt.chapter)->gmap_dispx;
    proc->disp_y = GetChapterInfo(gPlaySt.chapter)->gmap_dispy;
}

void PrepDisp_PutScrollArrow(u8 bottom, u8 clock, i8 visible)
{
    u8 frame = ((clock / 8) % PREPDISP_ARROW_FRAMES) * 2;

    if (bottom == FALSE)
    {
        if (visible)
        {
            gBg0Tm[TM_OFFSET(0x14, 4)] = frame + TILEREF(BGCHR_PREPMENU_240, BGPAL_PREPMENU_F);
            gBg0Tm[TM_OFFSET(0x15, 4)] = frame + TILEREF(BGCHR_PREPMENU_240 + 1, BGPAL_PREPMENU_F);
        }
        else
        {
            gBg0Tm[TM_OFFSET(0x14, 4)] = 0;
            gBg0Tm[TM_OFFSET(0x15, 4)] = 0;
        }
    }
    else
    {
        if (visible)
        {
            gBg0Tm[TM_OFFSET(0x14, 0x13)] = frame + TILEREF(BGCHR_PREPMENU_240, BGPAL_PREPMENU_F) + TILE_VFLIP;
            gBg0Tm[TM_OFFSET(0x15, 0x13)] = frame + TILEREF(BGCHR_PREPMENU_240 + 1, BGPAL_PREPMENU_F) + TILE_VFLIP;
        }
        else
        {
            gBg0Tm[TM_OFFSET(0x14, 0x13)] = 0;
            gBg0Tm[TM_OFFSET(0x15, 0x13)] = 0;
        }
    }
    EnableBgSync(BG0_SYNC_BIT);
}

void PrepUnit_DrawSMSAndObjs(struct ProcPrepUpperDisp * proc)
{
    u8 i;
    int first_idx, base_y;
    i16 ydiff_mod;
    u32 ydiff_quo;

    ydiff_mod = -proc->proc_parent->yDiff_cur % 16;
    ydiff_quo = (u8)(proc->proc_parent->yDiff_cur / 16);

    if (proc->prev_ydiff != proc->proc_parent->yDiff_cur)
    {
        SetWinEnable(1, 1, 0);
        SetWin1Layers(1, 1, 0, 1, 1);
        SetWin0Layers(1, 1, 1, 1, 1);
        SetWin0Box(0, 0x28, 0xF0, 0x98);
        SetWin1Box(0, 0, 0xF0, 0x28);
        SetWOutLayers(1, 1, 0, 1, 0);
        proc->split_win = TRUE;
    }
    else if (proc->split_win == TRUE)
    {
        SetWinEnable(1, 0, 0);
        SetWin1Layers(1, 1, 1, 1, 1);
        SetWin0Layers(1, 1, 1, 1, 1);
        SetWin0Box(0, 0x28, 0xF0, 0x98);
        SetWOutLayers(1, 1, 0, 1, 1);
        proc->split_win = FALSE;
    }

    if (proc->proc_parent->unk_31 != 0xFF)
    {
        u32 tmp = proc->proc_parent->unk_31 / 2 - ydiff_quo;

        if (tmp <= 6)
            PutFrozenUiHand(
                (proc->proc_parent->unk_31 & 1) * 0x40 + 0x70,
                tmp * 0x10 + ydiff_mod + 0x28
            );
    }

    i = 0;
    first_idx = ydiff_quo * 2;
    base_y = ydiff_mod + 0x28;

    for (; i < 0xE; i++)
    {
        int list_idx = first_idx + i;
        int y;

        if (list_idx >= proc->proc_parent->unk_2D)
            continue;

        y = (i >> 1) * 0x10 + base_y;
        if (y > 0x27)
            PutUnitSprite(3, (i & 1) * 0x40 + 0x70, y, GetUnitFromPrepList(list_idx));
    }

    if (ydiff_mod == 0)
        return;

    for (; i < 0x10; i++)
    {
        int list_idx = first_idx + i;
        u32 y = ydiff_mod + 0x28;

        if (list_idx < proc->proc_parent->unk_2D)
            PutUnitSprite(3, (i & 1) * 0x40 + 0x70, ((i >> 1) * 0x10 + y) & 0xFF, GetUnitFromPrepList(list_idx));
    }
}

u16 CONST_DATA Sprite_PrepGmapMarker[] =
{
    1,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(OBCHR_PREPMENU_380) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 1),
};

u16 CONST_DATA Sprite_PrepGmapBattleground[] =
{
    2,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x40) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 1),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(OBCHR_PREPMENU_380 + 0x44) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 1),
};

u16 CONST_DATA Sprite_PrepGmapLineVFlip[] =
{
    2,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_VFLIP, OAM2_CHR(OBCHR_PREPMENU_380 + 0x18) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32) + OAM1_VFLIP, OAM2_CHR(OBCHR_PREPMENU_380 + 0x1C) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6),
};

u16 CONST_DATA Sprite_PrepGmapLineHFlip[] =
{
    2,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(32) + OAM1_HFLIP, OAM2_CHR(OBCHR_PREPMENU_380 + 0x18) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6),
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_HFLIP, OAM2_CHR(OBCHR_PREPMENU_380 + 0x1C) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6),
};

u16 CONST_DATA Sprite_PrepGmapLine[] =
{
    1,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x18) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6),
};

u16 CONST_DATA Sprite_PrepGmapLineEnd[] =
{
    1,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x1C) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6),
};

u16 CONST_DATA Sprite_PrepChapterLabel[] =
{
    2,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x48) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16 + OAM1_X(32), OAM2_CHR(OBCHR_PREPMENU_380 + 0x4C) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterPlateEnd[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x57) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterPlate[] =
{
    4,
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x5C) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(16), OAM2_CHR(OBCHR_PREPMENU_380 + 0x5D) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(32), OAM2_CHR(OBCHR_PREPMENU_380 + 0x5D) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(48), OAM2_CHR(OBCHR_PREPMENU_380 + 0x5E) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterPlateWide[] =
{
    5,
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x5C) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(16), OAM2_CHR(OBCHR_PREPMENU_380 + 0x5D) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(32), OAM2_CHR(OBCHR_PREPMENU_380 + 0x5D) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16 + OAM1_X(48), OAM2_CHR(OBCHR_PREPMENU_380 + 0x5D) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
    OAM0_SHAPE_16x16, OAM1_SIZE_16x16 + OAM1_X(54), OAM2_CHR(OBCHR_PREPMENU_380 + 0x5E) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterDigit0[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x4D) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterDigit1[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x4E) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterDigit2[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x4F) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterDigit3[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x50) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterDigit4[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x51) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterDigit5[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x52) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterDigit6[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x53) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterDigit7[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x54) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterDigit8[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x55) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterDigit9[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x56) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterSuffixX[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x58) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA Sprite_PrepChapterDigitBlank[] =
{
    1,
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_PREPMENU_380 + 0x59) + OAM2_LAYER(1) + OAM2_PAL(OBPAL_PREPMENU_6 + 2),
};

u16 CONST_DATA * Sprites_PrepChapterDigits[12] =
{
    Sprite_PrepChapterDigit0,
    Sprite_PrepChapterDigit1,
    Sprite_PrepChapterDigit2,
    Sprite_PrepChapterDigit3,
    Sprite_PrepChapterDigit4,
    Sprite_PrepChapterDigit5,
    Sprite_PrepChapterDigit6,
    Sprite_PrepChapterDigit7,
    Sprite_PrepChapterDigit8,
    Sprite_PrepChapterDigit9,
    Sprite_PrepChapterSuffixX,
    Sprite_PrepChapterDigitBlank,
};

void PrepMenu_DrawGmapSprites(struct ProcPrepUpperDisp * proc)
{
    u8 order[6] = { 8, 5, 4, 3, 4, 5 };
    int i, xpos, ypos = 0x28;

    if (proc->cursor_y < 0x20)
        ypos = 0x74;

    if ((proc->proc_parent->link_arena_flag & PREPMENU_FLAG_MULTIARENA) == 0 && proc->index_gaiden != 0)
    {
        u8 index_gaiden;
        if (proc->index_gaiden & 1)
        {
            xpos = 0xA4;

            PutSpriteExt(4, 0xA6, ypos + 2, Sprite_PrepChapterPlateWide, 0);
            PutSpriteExt(4, 0xDC, ypos + 0, Sprites_PrepChapterDigits[PREPDISP_CHAPTER_DIGIT_X], 0);
        }
        else
        {
            xpos = 0xA8;

            PutSpriteExt(4, 0xAA, ypos + 2, Sprite_PrepChapterPlate, 0);
            PutSpriteExt(4, 0xE0, ypos + 0, Sprite_PrepChapterPlateEnd, 0);
        }

        PutSpriteExt(4, xpos, ypos, Sprite_PrepChapterLabel, 0);

        index_gaiden = proc->index_gaiden / 2;
        if (index_gaiden < 10)
            PutSpriteExt(4, xpos + 0x28, ypos, Sprites_PrepChapterDigits[PREPDISP_CHAPTER_DIGIT_BLANK], 0);
        else
            PutSpriteExt(4, xpos + 0x28, ypos, Sprites_PrepChapterDigits[index_gaiden / 10], 0);

        PutSpriteExt(4, xpos + 0x30, ypos, Sprites_PrepChapterDigits[(proc->index_gaiden / 2) % 10], 0);
    }

    if ((proc->marker_anim & 0xF) == 0)
    {
        proc->marker_anim += 0x10;
        if (proc->marker_anim >= 0x60)
            proc->marker_anim = 0;

        proc->marker_anim = (proc->marker_anim & 0xF0) + order[proc->marker_anim >> 4];
    }

    proc->marker_anim--;

    if (proc->cursor_x < 0x20)
    {
        PutSpriteExt(4, proc->cursor_x + 0x68, proc->cursor_y + 0x26, Sprite_PrepGmapMarker, (proc->marker_anim >> 4) * 4);
        PutSpriteExt(4, OAM1_HFLIP + proc->cursor_x + 0x88, proc->cursor_y + 0x1E, Sprite_PrepGmapLine, 0);
        PutSpriteExt(4, OAM1_HFLIP + proc->cursor_x + 0x68, proc->cursor_y + 0x1E, Sprite_PrepGmapLineEnd, 0);
        PutSpriteExt(4, proc->cursor_x + 0x68, proc->cursor_y + 0x16, Sprite_PrepGmapBattleground, 0);
    }
    else
    {
        PutSpriteExt(4, proc->cursor_x + 0x62, proc->cursor_y + 0x26, Sprite_PrepGmapMarker, (proc->marker_anim >> 4) * 4);
        PutSpriteExt(4, proc->cursor_x + 0x42, proc->cursor_y + 0x1E, Sprite_PrepGmapLine, 0);
        PutSpriteExt(4, proc->cursor_x + 0x62, proc->cursor_y + 0x1E, Sprite_PrepGmapLineEnd, 0);
        PutSpriteExt(4, proc->cursor_x + 0x42, proc->cursor_y + 0x16, Sprite_PrepGmapBattleground, 0);
    }

    for (i = 0; i < 10; i++)
    {
        gPal[OBPAL_OFFSET(OBPAL_PREPMENU_6) + 5 + i] = gPal[OBPAL_OFFSET(OBPAL_PREPMENU_6 + 3) + ((proc->clock / 2 + i) & 0xF)];
    }
    EnablePalSync();
}

u16 CONST_DATA Sprite_PrepUnitHighlight[] =
{
    2,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8, OAM2_CHR(OBCHR_PREPMENU_240 + 0x80) + OAM2_LAYER(2),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(32), OAM2_CHR(OBCHR_PREPMENU_240 + 0x83) + OAM2_LAYER(2),
};

u16 CONST_DATA Sprite_PrepTitleBar[] =
{
    1,
    OAM0_SHAPE_32x32 + OAM0_BLEND, OAM1_SIZE_32x32, OAM2_CHR(OBCHR_PREPMENU_240) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_PrepTitleMenuSelect[] =
{
    5,
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16, OAM2_CHR(OBCHR_PREPMENU_240 + 0xE) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(OBCHR_PREPMENU_240 + 0x12) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(OBCHR_PREPMENU_240 + 0x16) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(96), OAM2_CHR(OBCHR_PREPMENU_240 + 0x1A) + OAM2_LAYER(3),
    OAM0_SHAPE_16x16 + OAM0_BLEND, OAM1_SIZE_16x16 + OAM1_X(128), OAM2_CHR(OBCHR_PREPMENU_240 + 0x1E) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_PrepPressStart[] =
{
    2,
    OAM0_SHAPE_32x32 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x32, OAM2_CHR(OBCHR_PREPMENU_240 + 0x6) + OAM2_LAYER(1),
    OAM0_SHAPE_32x32 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(OBCHR_PREPMENU_240 + 0xA) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_PrepTitleItemEdit[] =
{
    2,
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16, OAM2_CHR(OBCHR_PREPMENU_240 + 0x4E) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(40), OAM2_CHR(OBCHR_PREPMENU_240 + 0x52) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_PrepBackHint[] =
{
    2,
    OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(OBCHR_PREPMENU_240 + 0x5B) + OAM2_LAYER(1),
    OAM0_SHAPE_8x16, OAM1_SIZE_8x16 + OAM1_X(32), OAM2_CHR(OBCHR_PREPMENU_240 + 0x5F) + OAM2_LAYER(1),
};

u16 CONST_DATA Sprite_PrepItemTitleBar[] =
{
    1,
    OAM0_SHAPE_32x32 + OAM0_BLEND, OAM1_SIZE_32x32, OAM2_CHR(0x80) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_PrepTitleTrade[] =
{
    3,
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x94) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(72), OAM2_CHR(0x98) + OAM2_LAYER(3),
    OAM0_SHAPE_16x16 + OAM0_BLEND, OAM1_SIZE_16x16 + OAM1_X(104), OAM2_CHR(0x9C) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_PrepTitleDiscard[] =
{
    4,
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(8), OAM2_CHR(0x94) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(48), OAM2_CHR(0xC4) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(80), OAM2_CHR(0xC8) + OAM2_LAYER(3),
    OAM0_SHAPE_16x16 + OAM0_BLEND, OAM1_SIZE_16x16 + OAM1_X(112), OAM2_CHR(0xCC) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_PrepTitleSupply[] =
{
    4,
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16, OAM2_CHR(0x84) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x88) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x8C) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(96), OAM2_CHR(0x90) + OAM2_LAYER(3),
};

u16 CONST_DATA Sprite_PrepTitleViewAll[] =
{
    2,
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(48), OAM2_CHR(0x94) + OAM2_LAYER(3),
    OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(88), OAM2_CHR(0xCE) + OAM2_LAYER(3),
};

/* maybe unused? */
u16 CONST_DATA * Sprites_PrepItemTitles[] =
{
    Sprite_PrepTitleTrade,
    Sprite_PrepTitleDiscard,
    Sprite_PrepTitleSupply,
    Sprite_PrepTitleViewAll,
};

void PrepDisp_PutHand(struct ProcPrepUpperDisp * proc)
{
    struct PrepMenuProc * parent = proc->proc_parent;

    switch (parent->sel_unit) {
    case 0:
        if (parent->submenu_level == 0)
            PutUiHand(0xC, parent->disp_idx[0] * 0x10 + 0x28);
        else if (parent->submenu_level == 1)
            PutUiHand(0xC, parent->disp_idx[parent->submenu_level] * 0x10 + 0x48);
        break;

    case 1:
        if ((parent->a_button_actions & 2) && parent->disp_idx[0] == 0)
            PutUiHand(0x6C, 0x8);
        else
        {
            PutUiHand(
                (proc->proc_parent->list_num_cur & 1) * 0x40 + 0x70,
                proc->proc_parent->hand_y_pos * 0x10 + 0x28);

            PutSpriteExt(
                0xD,
                (proc->proc_parent->list_num_cur & 1) * 0x40 + 0x70,
                proc->proc_parent->hand_y_pos * 0x10 + 0x30,
                Sprite_PrepUnitHighlight,
                OAM2_PAL(OBPAL_PREPMENU_3));

            gPal[OBPAL_OFFSET(OBPAL_PREPMENU_3) + 0xE] = gPrepUiPal[(proc->clock / 4) & 0xF];
            EnablePalSync();
        }
        break;

    default:
        break;
    }
}

void PrepDisp_PutPressStart(struct ProcPrepUpperDisp * proc)
{
    struct PrepMenuProc * parent = proc->proc_parent;

    if ((parent->a_button_actions & 1) && (parent->cur_counter != 0))
    {
        if (proc->press_start_scale <= 0xFF)
            proc->press_start_scale += 0x20;
    }
    else if (proc->press_start_scale != 0)
    {
        proc->press_start_scale -= 0x20;
    }

    if (proc->press_start_scale > 0x10)
    {
        gPal[OBPAL_OFFSET(OBPAL_PREPMENU_3) + 0xD] = *(Pal_PrepGoldPulse + (proc->clock / 8) % 0x10);
        EnablePalSync();

        if ((proc->start_blink_clock % 10) <= 4)
        {
            SetObjAffineAuto(0, 0, 0x100, proc->press_start_scale);
            PutSprite(4, 0x68, 0x1FE, Sprite_PrepPressStart, OAM2_PAL(OBPAL_PREPMENU_3));
        }

        if (proc->start_blink_clock != 0)
            proc->start_blink_clock++;
    }
}

void PrepDisp_PutTitleSprite(struct ProcPrepUpperDisp * proc)
{
    int i, x;

    SetBlendConfig(0, 0xE, 0x8, 0);
    SetBlendTargetA(0, 0, 0, 0, 1);
    SetBlendTargetB(0, 0, 0, 1, 0);

    for (i = 0; i < 8; i++)
        PutSprite(0xD, 0x20 * i, 4, Sprite_PrepTitleBar, OAM2_PAL(OBPAL_PREPMENU_2));

    if (proc->title_slide_clock != 0)
    {
        proc->title_slide_x = (proc->title_slide_clock * 320 - (proc->title_slide_clock * 0x10) * proc->title_slide_clock) / 10;

        if (proc->title_slide_clock < 10)
            proc->title_slide_clock++;
        else
            proc->title_slide_clock = 0;
    }

    if (proc->proc_parent->unk_2B == 0)
        x = proc->title_slide_x - 0xA0;
    else
        x = -proc->title_slide_x;

    if (proc->proc_parent->submenu_level == 1)
    {
        if (proc->desc_changing == 0)
        {
            if (proc->desc_scale < 0x100)
                proc->desc_scale += 0x20;
        }
        else if (proc->desc_scale >= 0x40)
        {
            proc->desc_scale -= 0x40;
        }
        else
        {
            proc->desc_changing = 0;
            proc->desc_scale = 0;
            func_fe6_08082D54(proc->proc_parent->unk_60, proc->desc_idx);
            proc->desc_scroll = 0x60;
        }
    }

    if (proc->proc_parent->submenu_level != 1)
    {
        PutSprite(0xD, OAM1_X(x + 8), 8, Sprite_PrepTitleMenuSelect, OAM2_PAL(OBPAL_PREPMENU_2));

        if (proc->menu_item == 0)
        {
            if ((proc->proc_parent->link_arena_flag & PREPMENU_FLAG_MULTIARENA) == 0)
                PrepDisp_PutPressStart(proc);
        }
        else
        {
            PutSprite(0xD, OAM1_X(0x140 + x), 8, Sprite_PrepTitleItemEdit, OAM2_PAL(OBPAL_PREPMENU_2));
        }
    }
    else
    {
        func_fe6_08082DA4(proc->proc_parent->unk_60, OAM1_X(0x200 - proc->desc_scroll), 7, proc->desc_scale);
        func_fe6_08082DA4(proc->proc_parent->unk_60, OAM1_X(0x100 - proc->desc_scroll), 7, proc->desc_scale);
        proc->desc_scroll++;
    }

    if ((proc->proc_parent->link_arena_flag & PREPMENU_FLAG_MULTIARENA) && proc->proc_parent->submenu_level == 0)
        PutSpriteExt(4, OAM1_X((x >> 1) + 0xBC), 8, Sprite_PrepBackHint, OAM2_PAL(OBPAL_PREPMENU_4));
}

void PrepUpperDisp_Init(struct ProcPrepUpperDisp * proc)
{
    proc->start_blink_clock = 0;
    proc->clock = 0;
    proc->split_win = 0;
    proc->prev_ydiff = proc->proc_parent->yDiff_cur;

    ForceSyncUnitSpriteSheet();

    proc->prev_disp_idx = proc->proc_parent->disp_idx[proc->proc_parent->submenu_level];
    proc->prev_submenu_level = proc->proc_parent->submenu_level;
    proc->title_slide_x = 0xA0;
    proc->unused_2D = proc->proc_parent->sel_unit;
    proc->prev_not_in_upper_menu = proc->proc_parent->not_in_upper_menu;
    proc->prev_title_flag = proc->proc_parent->unk_2B;
    proc->title_slide_clock = 0;
    proc->arrow_clock = 0;
    proc->marker_anim = 0;

    proc->menu_item = GetPrepScreenMenuCurrentItemIndex(proc->proc_parent);
    proc->desc_changing = 0;
    proc->desc_idx = proc->proc_parent->disp_idx[1];
    proc->desc_scroll = 0x60;

    if (((struct PrepMenuProcBug *)(proc->proc_parent))->_bug_34 == 0x100) // submenu_level == 1 && disp_idx[1] == 0
    {
        proc->desc_scale = ((struct PrepMenuProcBug *)(proc->proc_parent))->_bug_34;
        func_fe6_08082D54(proc->proc_parent->unk_60, 5);
    }
    else
    {
        proc->desc_scale = 0;
        func_fe6_08082D54(proc->proc_parent->unk_60, GetPrepScreenMenuDispItemIndex(proc->desc_idx, 1) - 5);
    }
}

void PrepUpperDisp_Loop(struct ProcPrepUpperDisp * proc)
{
    if (proc->proc_parent->not_in_upper_menu != proc->prev_not_in_upper_menu)
        proc->prev_not_in_upper_menu = proc->proc_parent->not_in_upper_menu;

    if (proc->proc_parent->unk_2B != proc->prev_title_flag)
    {
        proc->menu_item = GetPrepScreenMenuCurrentItemIndex(proc->proc_parent);
        proc->prev_title_flag = proc->proc_parent->unk_2B;
        proc->title_slide_clock = 1;
    }

    SyncUnitSpriteSheet();

    if (proc->proc_parent->not_in_upper_menu == FALSE)
    {
        PrepMenu_DrawGmapSprites(proc);
    }
    else
    {
        SetBgOffset(2, -0x80, (proc->proc_parent->yDiff_cur - 0x28) & 0xFF);
        PrepUnit_DrawSMSAndObjs(proc);

        if (proc->proc_parent->yDiff_cur != 0)
            PrepDisp_PutScrollArrow(0, proc->arrow_clock, 1);
        else
            PrepDisp_PutScrollArrow(0, proc->arrow_clock, 0);

        if (((proc->proc_parent->yDiff_cur / 0x10 + 7) * 2) < proc->proc_parent->unk_2D)
            PrepDisp_PutScrollArrow(1, proc->arrow_clock, 1);
        else
            PrepDisp_PutScrollArrow(1, proc->arrow_clock, 0);
    }

    PrepDisp_PutHand(proc);
    PrepDisp_PutTitleSprite(proc);

    if ((++proc->arrow_clock / 8) > PREPDISP_ARROW_FRAMES - 1)
        proc->arrow_clock = 0;

    proc->prev_ydiff = proc->proc_parent->yDiff_cur;

    if (proc->prev_submenu_level != proc->proc_parent->submenu_level)
    {
        proc->prev_submenu_level = proc->proc_parent->submenu_level;
    }
    else if (proc->prev_disp_idx != proc->proc_parent->disp_idx[proc->proc_parent->submenu_level])
    {
        if (proc->proc_parent->submenu_level == 0)
        {
            RemoveUiEntryHover(1, proc->prev_disp_idx * 2 + 5, 10);
            PutUiEntryHover(1, proc->proc_parent->disp_idx[proc->proc_parent->submenu_level] * 2 + 5, 10);
        }
        else
        {
            RemoveUiEntryHover(1, proc->prev_disp_idx * 2 + 9, 10);
            PutUiEntryHover(1, proc->proc_parent->disp_idx[proc->proc_parent->submenu_level] * 2 + 9, 10);
        }
        EnableBgSync(BG1_SYNC_BIT);
    }

    proc->prev_disp_idx = proc->proc_parent->disp_idx[proc->proc_parent->submenu_level];
    proc->clock++;
}

void PrepUpperDisp_End(struct ProcPrepUpperDisp * proc)
{
    return;
}

void PrepUpperDisp_Block(struct ProcPrepUpperDisp * proc)
{
    return;
}

struct ProcScr CONST_DATA ProcScr_PrepUpperDisp[] = {
    PROC_19,
PROC_LABEL(L_PREPUPPERDISP_INIT),
    PROC_SLEEP(1),
    PROC_CALL(PrepUpperDisp_Init),
PROC_LABEL(L_PREPUPPERDISP_LOOP),
    PROC_REPEAT(PrepUpperDisp_Loop),
    PROC_GOTO(L_PREPUPPERDISP_END),
PROC_LABEL(L_PREPUPPERDISP_BLOCK),
    PROC_REPEAT(PrepUpperDisp_Block),
PROC_LABEL(L_PREPUPPERDISP_END),
    PROC_CALL(PrepUpperDisp_End),
    PROC_END,
};

ProcPtr StartPrepUpperDisp(ProcPtr parent)
{
    struct ProcPrepUpperDisp * proc = SpawnProc(ProcScr_PrepUpperDisp, parent);
    proc->press_start_scale = 0;
    return proc;
}
