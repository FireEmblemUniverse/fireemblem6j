#pragma once

#include "prelude.h"
#include "proc.h"

enum {
    BGPAL_TITLE_BG = 0,
    BGPAL_TITLE_BG_COUNT = 8,
    BGPAL_TITLE_BG3 = 15,

    OBPAL_TITLE_SPRITES = 0,
    OBPAL_TITLE_SPRITES_COUNT = 5,
    OBPAL_TITLE_PRESS_START = OBPAL_TITLE_SPRITES + 1,
    OBPAL_TITLE_LENSFLARE = 0,

    OBCHR_TITLE_LENSFLARE = 0x200,
};

enum {
    TITLE_SPRITEANIM_SUBTITLE,
    TITLE_SPRITEANIM_PRESS_START,
    TITLE_SPRITEANIM_COPYRIGHT,
    TITLE_SPRITEANIM_ENGLISH_LOGO,
};

enum {
    TITLE_BG3_TILE_COUNT = 0x280,
    TITLE_PRESS_START_GLOW_COLOR = 8,
    TITLE_PRESS_START_GLOW_LENGTH = 0x10,
    TITLE_LENSFLARE_FADE_FRAMES = 0x18,
};

struct ProcTitle {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x64);

    /* 64 */ i16 timer;
};

struct ProcTitleDisp {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x64);

    /* 64 */ i16 timer1, timer2;
};

void Title_ReinitTimer(struct ProcTitle * proc);
void Title_Idle(struct ProcTitle * proc);
void Title_End(struct ProcTitle * proc);
void Title_EndIfOpAnimSkipped(ProcPtr proc);
void Title_Init(struct ProcTitle * proc);
void Title_InitDisp(struct ProcTitle * proc);
void TitlePressStartGlow_Init(struct ProcTitleDisp * proc);
void TitlePressStartGlow_Loop(struct ProcTitleDisp * proc);
void Title_StartLogoFadeIn(struct ProcTitleDisp * proc);
void Title_LogoFadeIn(struct ProcTitleDisp * proc);
void TitleSwordDelay_Init(struct ProcTitleDisp * proc);
void TitleSwordDelay_Loop(struct ProcTitleDisp * proc);
void TitleSwordSlideIn_Init(struct ProcTitleDisp * proc);
void TitleSwordSlideIn_Loop(struct ProcTitleDisp * proc);
void TitleLogoShadow_Init(struct ProcTitleDisp * proc);
void TitleLogoShadow_Loop(struct ProcTitleDisp * proc);
void TitleLensFlareFadeIn_Init(struct ProcTitleDisp * proc);
void TitleLensFlareFadeIn_Loop(struct ProcTitleDisp * proc);
void TitleLensFlare_Init(struct ProcTitleDisp * proc);
void TitleLensFlare_Loop(struct ProcTitleDisp * proc);
void TitleLensFlare_Put(struct ProcTitleDisp * proc);
void Title_StartBgm(struct ProcTitle * proc);
void Title_PlayRevealSe(void);

extern struct ProcScr CONST_DATA ProcScr_TitleScreen[];
extern struct ProcScr CONST_DATA ProcScr_TitleScreenFromOp[];
extern struct ProcScr CONST_DATA ProcScr_TitlePressStartGlow[];
extern struct ProcScr CONST_DATA ProcScr_TitleSwordDelay[];
extern struct ProcScr CONST_DATA ProcScr_TitleSwordSlideIn[];
extern struct ProcScr CONST_DATA ProcScr_TitleLogoShadow[];
extern struct ProcScr CONST_DATA ProcScr_TitleLensFlareFadeIn[];
extern struct ProcScr CONST_DATA ProcScr_TitleLensFlare[];
extern u16 CONST_DATA Sprite_TitleLensFlareSmall[];
extern u16 CONST_DATA Sprite_TitleLensFlareMedium[];
extern u16 CONST_DATA Sprite_TitleLensFlareLarge[];

extern CONST_DATA int gTitleDuration;
extern CONST_DATA int gTitleSwordSlideInDuration;
extern CONST_DATA int gTitleLogoFadeInDuration;
extern CONST_DATA int gTitleLogoShadowDuration;
extern CONST_DATA int gTitleLensFlareDuration;
extern CONST_DATA int gTitleSwordDelay;

extern u16 const Pal_Title_BG[];
extern u8 const Img_Title_BG[];
extern u8 const Img_Title_Sprites[];
extern u16 const SpriteAnim_Title[];
extern u16 const Pal_Title_PressStartGlow[];
extern u8 const Tsa_Title_BG2[];
extern u8 const Tsa_Title_BG0[];
extern u8 const Tsa_Title_BG1[];
extern u8 const Img_Title_BG3[];
extern u16 const Pal_Title_BG3[];
extern u8 const Img_Title_LensFlare[];
extern u16 const Pal_Title_LensFlare[];
