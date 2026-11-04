#include "prelude.h"
#include "util.h"
#include "hardware.h"
#include "armfunc.h"
#include "gamecontroller.h"
#include "sound.h"
#include "oam.h"
#include "spriteanim.h"
#include "constants/songs.h"

#include "opanim.h"
#include "titlescreen.h"

struct ProcScr CONST_DATA ProcScr_TitleScreen[] =
{
    PROC_MARK(9),
    PROC_ONEND(Title_End),
    PROC_CALL(Title_Init),
    PROC_CALL(Title_InitDisp),
    PROC_CALL(Title_StartBgm),
    PROC_CALL(FadeInBlackSpeed20),
    PROC_YIELD,
    PROC_CALL(Title_ReinitTimer),
    PROC_REPEAT(Title_Idle),
    PROC_YIELD,
    PROC_END,
};

void Title_ReinitTimer(struct ProcTitle * proc)
{
    proc->timer = 0;
}

void Title_Idle(struct ProcTitle * proc)
{
    proc->timer++;

    if (proc->timer >= gTitleDuration)
    {
        SetNextGameAction(GAME_ACTION_1);
        FadeInBlackWithCallBack_Speed10(proc);
        Proc_Break(proc);
        return;
    }

    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_START))
    {
        PlaySe(SONG_6D);
        SetNextGameAction(GAME_ACTION_0);
        FadeInBlackWithCallBack_Speed20(proc);
        Proc_Break(proc);
        return;
    }
}

void Title_End(struct ProcTitle * proc)
{
    EndEachSpriteAnimProc();
}

void Title_EndIfOpAnimSkipped(ProcPtr proc)
{
    if (bool_opanim_03005284)
        Proc_End(proc);
}

void Title_Init(struct ProcTitle * proc)
{
    int i;
    u16 * tm;

    CONST_DATA static u16 bg_config[12] =
    {
        0x0000, 0x6800, 0,
        0x0000, 0x7000, 0,
        0x0000, 0xE000, 3,
        0x8000, 0x7800, 0,
    };

    InitBgs(bg_config);
    DisableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

    SetDispEnable(0, 0, 0, 1, 1);
    SetTm((void *)BG_VRAM + GetBgTilemapOffset(BG_2), 0x1000, 0);

    Decompress(Img_Title_BG, (void *)BG_VRAM + GetBgChrOffset(BG_0));
    Decompress(Tsa_Title_BG0, (void *)BG_VRAM + GetBgTilemapOffset(BG_0));
    Decompress(Tsa_Title_BG1, (void *)BG_VRAM + GetBgTilemapOffset(BG_1));
    Decompress(Tsa_Title_BG2, (void *)BG_VRAM + GetBgTilemapOffset(BG_2));
    ApplyPalettes(Pal_Title_BG, BGPAL_TITLE_BG, BGPAL_TITLE_BG_COUNT);

    Decompress(Img_Title_BG3, (void *)BG_VRAM + GetBgChrOffset(BG_3));
    ApplyPalette(Pal_Title_BG3, BGPAL_TITLE_BG3);

    /* This may be a pure ApplyTsa ? No: it lays out Img_Title_BG3's tiles in order. */
    tm = gBg3Tm;
    for (i = 0; i < TITLE_BG3_TILE_COUNT; i++)
        *tm++ = TILEREF(i, BGPAL_TITLE_BG3);

    EnableBgSync(BG3_SYNC_BIT);
    proc->timer = 0;
}

void Title_InitDisp(struct ProcTitle * proc)
{
    Decompress(Img_Title_Sprites, OBJ_VRAM0);
    ApplyObPalettes(Pal_Title_BG, OBPAL_TITLE_SPRITES, OBPAL_TITLE_SPRITES_COUNT);

    StartSpriteAnimProc(SpriteAnim_Title, 0xA3, 0x1B, 0, TITLE_SPRITEANIM_ENGLISH_LOGO, 0);
    StartSpriteAnimProc(SpriteAnim_Title, 0x78, 0x55, 0, TITLE_SPRITEANIM_SUBTITLE, 0);
    StartSpriteAnimProc(SpriteAnim_Title, 0x78, 0x78, 0, TITLE_SPRITEANIM_PRESS_START, 0);
    StartSpriteAnimProc(SpriteAnim_Title, 0x78, 0x98, 0, TITLE_SPRITEANIM_COPYRIGHT, 0);

    SpawnProc(ProcScr_TitlePressStartGlow, proc);
    SpawnProc(ProcScr_TitleLogoShadow, proc);
}

struct ProcScr CONST_DATA ProcScr_TitlePressStartGlow[] = {
    PROC_CALL(TitlePressStartGlow_Init),
    PROC_REPEAT(TitlePressStartGlow_Loop),

    // PROC_END ? Not needed: TitlePressStartGlow_Loop never breaks; the proc ends along with its parent title proc.
};

struct ProcScr CONST_DATA ProcScr_TitleSwordDelay[] = {
    PROC_CALL(TitleSwordDelay_Init),
    PROC_REPEAT(TitleSwordDelay_Loop),
    PROC_END,
};

void TitlePressStartGlow_Init(struct ProcTitleDisp * proc)
{
    proc->timer1 = 0;
    proc->timer2 = 0;
}

void TitlePressStartGlow_Loop(struct ProcTitleDisp * proc)
{

    if ((proc->timer1++) > 3)
    {
        proc->timer1 = 0;
        proc->timer2 = (proc->timer2 + 1) & (TITLE_PRESS_START_GLOW_LENGTH - 1);
        ApplyPaletteExt(
            Pal_Title_PressStartGlow + proc->timer2,
            (OBPAL_OFFSET(OBPAL_TITLE_PRESS_START) + TITLE_PRESS_START_GLOW_COLOR) * sizeof(u16),
            sizeof(u16));
    }
}

void Title_StartLogoFadeIn(struct ProcTitleDisp * proc)
{
    SetDispEnable(1, 0, 0, 1, 1);
    SetBlendTargetA(1, 0, 0, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 0);
    SetBlendAlpha(0, 0x10);
    proc->timer1 = 0;
}

void Title_LogoFadeIn(struct ProcTitleDisp * proc)
{
    int ret;

    proc->timer1++;

    ret = Interpolate(INTERPOLATE_RCUBIC, 0, 0x10, proc->timer1, gTitleLogoFadeInDuration);
    SetBlendAlpha(ret, 0x10 - ret);

    SetBgOffset(BG_0, 0, Interpolate(INTERPOLATE_RCUBIC, -0x10, 0, proc->timer1, gTitleLogoFadeInDuration));

    if (proc->timer1 >= gTitleLogoFadeInDuration)
    {
        Proc_Break(proc);
        proc->timer1 = 0;
    }
}

void TitleSwordDelay_Init(struct ProcTitleDisp * proc)
{
    proc->timer1 = 0;
}

void TitleSwordDelay_Loop(struct ProcTitleDisp * proc)
{
    if (proc->timer1++ >= gTitleSwordDelay)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_TitleSwordSlideIn[] =
{
    PROC_CALL(TitleSwordSlideIn_Init),
    PROC_REPEAT(TitleSwordSlideIn_Loop),
    PROC_END,
};

void TitleSwordSlideIn_Init(struct ProcTitleDisp * proc)
{
    SetDispEnable(1, 0, 1, 1, 1);
    proc->timer1 = 0;
}

void TitleSwordSlideIn_Loop(struct ProcTitleDisp * proc)
{
    proc->timer1++;

    SetBgOffset(
        BG_2,
        Interpolate(INTERPOLATE_RSQUARE, 0xF0, 0, proc->timer1, gTitleSwordSlideInDuration),
        Interpolate(INTERPOLATE_RSQUARE, 0x69, 0, proc->timer1, gTitleSwordSlideInDuration));

    if (proc->timer1 >= gTitleSwordSlideInDuration)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_TitleLogoShadow[] =
{
    PROC_CALL(TitleLogoShadow_Init),
    PROC_REPEAT(TitleLogoShadow_Loop),
    PROC_END,
};

void TitleLogoShadow_Init(struct ProcTitleDisp * proc)
{
    SetDispEnable(1, 1, 1, 1, 1);
    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 1, 0);
    SetBlendAlpha(0, 0x10);
    proc->timer1 = 0;
}

void TitleLogoShadow_Loop(struct ProcTitleDisp * proc)
{
    int ret;

    proc->timer1++;

    SetBgOffset(
        BG_1,
        0,
        Interpolate(INTERPOLATE_RSQUARE, 8, 0, proc->timer1, gTitleLogoShadowDuration));

    ret = Interpolate(INTERPOLATE_RSQUARE, 0, 8, proc->timer1, gTitleLogoShadowDuration);
    SetBlendAlpha(ret, 0x10 - ret);

    if (proc->timer1 >= gTitleLogoShadowDuration)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_TitleLensFlareFadeIn[] =
{
    PROC_CALL(TitleLensFlareFadeIn_Init),
    PROC_REPEAT(TitleLensFlareFadeIn_Loop),
    PROC_END,
};

void TitleLensFlareFadeIn_Init(struct ProcTitleDisp * proc)
{
    SetBlendAlpha(0, 0x10);
    proc->timer1 = 0;
}

void TitleLensFlareFadeIn_Loop(struct ProcTitleDisp * proc)
{
    SetBlendAlpha(
        Interpolate(INTERPOLATE_LINEAR, 0, 0x10, proc->timer1, TITLE_LENSFLARE_FADE_FRAMES),
        0x10);

    if (proc->timer1++ >= TITLE_LENSFLARE_FADE_FRAMES)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_TitleLensFlare[] =
{
    PROC_START_CHILD(ProcScr_TitleLensFlareFadeIn),
    PROC_CALL(TitleLensFlare_Init),
    PROC_REPEAT(TitleLensFlare_Loop),
    PROC_REPEAT(TitleLensFlare_Put),
    PROC_END,
};

void TitleLensFlare_Init(struct ProcTitleDisp * proc)
{
    Decompress(Img_Title_LensFlare, OBJ_VRAM0 + OBCHR_TITLE_LENSFLARE * CHR_SIZE);
    ApplyObPalette(Pal_Title_LensFlare, OBPAL_TITLE_LENSFLARE);
    SetDispEnable(1, 0, 0, 1, 1);
    SetBlendTargetA(0, 0, 0, 0, 1);
    SetBlendTargetB(1, 1, 1, 1, 0);
    proc->timer1 = 0;
}

void TitleLensFlare_Loop(struct ProcTitleDisp * proc)
{
    TitleLensFlare_Put(proc);

    if (proc->timer1 == gTitleLensFlareDuration)
        Proc_Break(proc);
    else
        proc->timer1++;
}

u16 CONST_DATA Sprite_TitleLensFlareSmall[] =
{
    1,
    OAM0_SHAPE_8x8 + OAM0_Y(2), OAM1_SIZE_8x8 + OAM1_X(2), OAM2_CHR(0xC),
};

u16 CONST_DATA Sprite_TitleLensFlareMedium[] =
{
    1,
    OAM0_SHAPE_32x32 + OAM0_Y(246), OAM1_SIZE_32x32 + OAM1_X(501), OAM2_CHR(0x8),
};

u16 CONST_DATA Sprite_TitleLensFlareLarge[] =
{
    1,
    OAM0_SHAPE_64x64 + OAM0_Y(220) + OAM0_AFFINE_ENABLE + OAM0_DOUBLESIZE, OAM1_SIZE_64x64 + OAM1_X(472), 0,
};

void TitleLensFlare_Put(struct ProcTitleDisp * proc)
{
    int x = Interpolate(INTERPOLATE_RSQUARE, 0x96, 0, proc->timer1, gTitleLensFlareDuration);
    int y = Interpolate(INTERPOLATE_RSQUARE, 0x64, 0, proc->timer1, gTitleLensFlareDuration);
    int scale = Interpolate(INTERPOLATE_RSQUARE, 0x80, 0x200, proc->timer1, gTitleLensFlareDuration);

    PutOamHi(
        OAM1_X(x + 0x23C),
        OAM0_Y(y + 0x120),
        Sprite_TitleLensFlareLarge,
        OAM2_CHR(OBCHR_TITLE_LENSFLARE) + OAM2_PAL(OBPAL_TITLE_LENSFLARE)
    );

    PutOamHi(
        OAM1_X((x * 3) / 8 + 0x23C),
        OAM0_Y(y / 2 + 0x120),
        Sprite_TitleLensFlareMedium,
        OAM2_CHR(OBCHR_TITLE_LENSFLARE) + OAM2_PAL(OBPAL_TITLE_LENSFLARE)
    );

    PutOamHi(
        OAM1_X(x / 8 + 0x23C),
        OAM0_Y(y / 6 + 0x120),
        Sprite_TitleLensFlareSmall,
        OAM2_CHR(OBCHR_TITLE_LENSFLARE) + OAM2_PAL(OBPAL_TITLE_LENSFLARE)
    );

    SetObjAffineAuto(0, 0, scale, scale);
}

void Title_StartBgm(struct ProcTitle * proc)
{
    StartBgmExt(SONG_01, 0, NULL);
}

// Guess: plays as the logo finishes appearing
void Title_PlayRevealSe(void)
{
    PlaySe(SONG_92);
}
