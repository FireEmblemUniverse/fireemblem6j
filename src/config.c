#include "prelude.h"
#include "proc.h"
#include "hardware.h"
#include "armfunc.h"
#include "oam.h"
#include "bm.h"
#include "bmio.h"
#include "ui.h"
#include "util.h"
#include "msg.h"
#include "text.h"
#include "icon.h"
#include "shop.h"
#include "chapter.h"
#include "battle.h"
#include "statscreen.h"
#include "helpbox.h"
#include "sound.h"
#include "unitlistscreen.h"
#include "constants/songs.h"
#include "constants/msg.h"
#include "constants/videoalloc_global.h"

#include "config.h"

// #include "save_core.h"
int IsNotFirstPlaythrough(); // ?

/**
 * Actually this is not a good design as it may cause bug if any other procs use gBuf.
 * A better idea is to move this area to ewram_overlay_0
 */
CONST_DATA struct ConfigSt * gpUiConfigSt = (struct ConfigSt *)gBuf;

CONST_DATA u8 gUiConfigSelectIndex1[] = {
    [ 0] = GAME_OPTION_ANIMATION,
    [ 1] = GAME_OPTION_GAME_SPEED,
    [ 2] = GAME_OPTION_TEXT_SPEED,
    [ 3] = GAME_OPTION_TERRAIN,
    [ 4] = GAME_OPTION_UNIT,
    [ 5] = GAME_OPTION_COMBAT,
    [ 6] = GAME_OPTION_SUBTITLE_HELP,
    [ 7] = GAME_OPTION_AUTOCURSOR,
    [ 8] = GAME_OPTION_AUTOEND_TURNS,
    [ 9] = GAME_OPTION_MUSIC,
    [10] = GAME_OPTION_SOUND_EFFECTS,
    [11] = GAME_OPTION_WINDOW_COLOR,
    [12] = GAME_OPTION_UNIT_COLOR,
};

CONST_DATA u8 gUiConfigSelectIndex2[] = {
    [ 0] = GAME_OPTION_ANIMATION,
    [ 1] = GAME_OPTION_TERRAIN,
    [ 2] = GAME_OPTION_UNIT,
    [ 3] = GAME_OPTION_AUTOCURSOR,
    [ 4] = GAME_OPTION_TEXT_SPEED,
    [ 5] = GAME_OPTION_GAME_SPEED,
    [ 6] = GAME_OPTION_MUSIC,
    [ 7] = GAME_OPTION_SOUND_EFFECTS,
    [ 8] = GAME_OPTION_AUTOEND_TURNS,
    [ 9] = GAME_OPTION_WINDOW_COLOR,
    [10] = GAME_OPTION_CPU_LEVEL,
};

CONST_DATA struct UiConfigOrder gUiConfigOrder[] = {
    { 0xC, gUiConfigSelectIndex1 },
    { 0xD, gUiConfigSelectIndex1 },
    { 0xB, gUiConfigSelectIndex2 },
};

CONST_DATA u16 Sprite_UiConfigTitle[] = {
    6,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8, 0,
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(32), OAM2_CHR(0x4),
    OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(64), OAM2_CHR(0x8),
    OAM0_SHAPE_32x8 + OAM0_Y(8), OAM1_SIZE_32x8, OAM2_CHR(0x20),
    OAM0_SHAPE_32x8 + OAM0_Y(8), OAM1_SIZE_32x8 + OAM1_X(32), OAM2_CHR(0x24),
    OAM0_SHAPE_32x8 + OAM0_Y(8), OAM1_SIZE_32x8 + OAM1_X(64), OAM2_CHR(0x28),
};


u8 GetSelectedGameOption(void)
{
    return gpUiConfigSt->sel_index;
}

u8 GetSelectedOptionValue(void)
{
    return GetGameOption(GetConfigItemCur());
}

void Config_InitBg(void)
{
    CONST_DATA static u16 bg_config[12] =
    {
        0x0000, 0x6000, 0,
        0x0000, 0x6800, 0,
        0x0000, 0x7000, 0,
        0x8000, 0x7800, 0,
    };

    InitBgs(bg_config);
}

void StartMuralBackgroundExt(ProcPtr parent, void * vram_dst, int pal_bank)
{
    int i, tileref;
    int oam2_chr, oam2_pal;
    const struct ProcScr * proc_scr;
    u16 * tm = gBg3Tm;

    if (vram_dst == NULL)
        vram_dst = (void *)BG_VRAM + GetBgChrOffset(BG_3);

    if (pal_bank < 0)
        pal_bank = BGPAL_MURALBACKGROUND;

    Decompress(Img_MuralBackground, vram_dst);
    ApplyPalettes(Pal_MuralBackground, pal_bank, 2);

    oam2_chr = (((uintptr_t)vram_dst - GetBgChrOffset(BG_3)) / CHR_SIZE) & 0xFFF; // ?
    oam2_pal = OAM2_PAL(pal_bank);

    tileref = oam2_chr + oam2_pal;

    /* This is an important reference to manually setup TSA */
    for (i = 0; i < 0x280; i++)
        *tm++ = i + tileref;

    tm = gBg3Tm + TM_OFFSET(0, 3);

    for (i = 0; i < 0x1C0; i++)
        *tm++ += OAM2_PAL(1);

    SpawnProc(ProcScr_BackgroundSlide, parent);
}

CONST_DATA struct UiConfigOption gUiConfigOptions[] = {
    [GAME_OPTION_ANIMATION] = {
        .msg = MSG_CONFIG_0,
        .selectors = {
            { MSG_CONFIG_14, MSG_CONFIG_41, 0x78, 0x01 },
            { MSG_CONFIG_15, MSG_CONFIG_42, 0x87, 0x01 },
            { MSG_CONFIG_16, MSG_CONFIG_40, 0x96, 0x02 },
            { MSG_CONFIG_17, MSG_CONFIG_49, 0xAD, 0x02 },
        },
        .icon_chr = 0x00,
        .func = GenericOptionChangeHandler,
    },

    [GAME_OPTION_TERRAIN] = {
        .msg = MSG_CONFIG_1,
        .selectors = {
            { MSG_CONFIG_24, MSG_CONFIG_39, 0x78, 0x02 },
            { MSG_CONFIG_24, MSG_CONFIG_40, 0x8F, 0x02 },
            { 0, 0, 0xC6, 0x00 },
            { 0, 0, 0xC5, 0x00 },
        },
        .icon_chr = 0x02,
        .func = GenericOptionChangeHandler,
    },

    [GAME_OPTION_UNIT] = {
        .msg = MSG_CONFIG_2,
        .selectors = {
            { MSG_CONFIG_25, MSG_CONFIG_52, 0x78, 0x03 },
            { MSG_CONFIG_26, MSG_CONFIG_53, 0x97, 0x04 },
            { MSG_CONFIG_27, MSG_CONFIG_40, 0xBE, 0x02 },
            { 0, 0, 0xC5, 0x00 },
        },
        .icon_chr = 0x04,
        .func = GenericOptionChangeHandler,
    },

    [GAME_OPTION_AUTOCURSOR] = {
        .msg = MSG_CONFIG_5,
        .selectors = {
            { MSG_CONFIG_32, MSG_CONFIG_39, 0x78, 0x02 },
            { MSG_CONFIG_32, MSG_CONFIG_40, 0x8F, 0x02 },
            { 0, 0, 0xC6, 0x00 },
            { 0, 0, 0xC5, 0x00 },
        },
        .icon_chr = 0x06,
        .func = GenericOptionChangeHandler,
    },

    [GAME_OPTION_TEXT_SPEED] = {
        .msg = MSG_CONFIG_6,
        .selectors = {
            { MSG_CONFIG_20, MSG_CONFIG_45, 0x78, 0x03 },
            { MSG_CONFIG_21, MSG_CONFIG_46, 0x97, 0x03 },
            { MSG_CONFIG_22, MSG_CONFIG_47, 0xB6, 0x03 },
            { MSG_CONFIG_23, MSG_CONFIG_48, 0xD5, 0x02 },
        },
        .icon_chr = 0x08,
        .func = GenericOptionChangeHandler,
    },

    [GAME_OPTION_GAME_SPEED] = {
        .msg = MSG_CONFIG_7,
        .selectors = {
            { MSG_CONFIG_18, MSG_CONFIG_46, 0x78, 0x03 },
            { MSG_CONFIG_19, MSG_CONFIG_47, 0x97, 0x03 },
            { 0, 0, 0xC6, 0x00 },
            { 0, 0, 0xC5, 0x00 },
        },
        .icon_chr = 0x0A,
        .func = GenericOptionChangeHandler,
    },

    [GAME_OPTION_MUSIC] = {
        .msg = MSG_CONFIG_8,
        .selectors = {
            { MSG_CONFIG_34, MSG_CONFIG_39, 0x78, 0x02 },
            { MSG_CONFIG_34, MSG_CONFIG_40, 0x8F, 0x02 },
            { 0, 0, 0xC6, 0x00 },
            { 0, 0, 0xC5, 0x00 },
        },
        .icon_chr = 0x0C,
        .func = MusicOptionChangeHandler,
    },

    [GAME_OPTION_SOUND_EFFECTS] = {
        .msg = MSG_CONFIG_9,
        .selectors = {
            { MSG_CONFIG_35, MSG_CONFIG_39, 0x78, 0x02 },
            { MSG_CONFIG_35, MSG_CONFIG_40, 0x8F, 0x02 },
            { 0, 0, 0xC6, 0x00 },
            { 0, 0, 0xC5, 0x00 },
        },
        .icon_chr = 0x0E,
        .func = GenericOptionChangeHandler,
    },

    [GAME_OPTION_WINDOW_COLOR] = {
        .msg = MSG_CONFIG_10,
        .selectors = {
            { MSG_CONFIG_36, MSG_CONFIG_41, 0x78, 0x01 },
            { MSG_CONFIG_36, MSG_CONFIG_42, 0x87, 0x01 },
            { MSG_CONFIG_36, MSG_CONFIG_43, 0x96, 0x01 },
            { MSG_CONFIG_36, MSG_CONFIG_44, 0xA5, 0x01 },
        },
        .icon_chr = 0x10,
        .func = WindowColorOptionChangeHandler,
    },

    [GAME_OPTION_CPU_LEVEL] = {
        .msg = MSG_CONFIG_11,
        .selectors = {
            { MSG_CONFIG_37, MSG_CONFIG_41, 0x78, 0x01 },
            { MSG_CONFIG_37, MSG_CONFIG_42, 0x87, 0x01 },
            { MSG_CONFIG_37, MSG_CONFIG_43, 0x96, 0x01 },
            { 0, 0, 0xC5, 0x00 },
        },
        .icon_chr = 0x12,
        .func = GenericOptionChangeHandler,
    },

    [GAME_OPTION_COMBAT] = {
        .msg = MSG_CONFIG_3,
        .selectors = {
            { MSG_CONFIG_28, MSG_CONFIG_50, 0x78, 0x03 },
            { MSG_CONFIG_29, MSG_CONFIG_51, 0x8F, 0x03 },
            { MSG_CONFIG_30, MSG_CONFIG_40, 0xA6, 0x02 },
            { 0, 0, 0xC5, 0x00 },
        },
        .icon_chr = 0x14,
        .func = GenericOptionChangeHandler,
    },

    [GAME_OPTION_SUBTITLE_HELP] = {
        .msg = MSG_CONFIG_4,
        .selectors = {
            { MSG_CONFIG_31, MSG_CONFIG_39, 0x78, 0x02 },
            { MSG_CONFIG_31, MSG_CONFIG_40, 0x8F, 0x02 },
            { 0, 0, 0xC6, 0x00 },
            { 0, 0, 0xC5, 0x00 },
        },
        .icon_chr = 0x16,
        .func = GenericOptionChangeHandler,
    },

    [GAME_OPTION_AUTOEND_TURNS] = {
        .msg = MSG_CONFIG_12,
        .selectors = {
            { MSG_CONFIG_33, MSG_CONFIG_39, 0x78, 0x02 },
            { MSG_CONFIG_33, MSG_CONFIG_40, 0x8F, 0x02 },
            { 0, 0, 0xC6, 0x00 },
            { 0, 0, 0xC5, 0x00 },
        },
        .icon_chr = 0x18,
        .func = GenericOptionChangeHandler,
    },

    [GAME_OPTION_UNIT_COLOR] = {
        .msg = MSG_CONFIG_13,
        .selectors = {
            { MSG_CONFIG_38, MSG_CONFIG_39, 0x78, 0x02 },
            { MSG_CONFIG_38, MSG_CONFIG_40, 0x8F, 0x02 },
            { 0, 0, 0xC6, 0x00 },
            { 0, 0, 0xC5, 0x00 },
        },
        .icon_chr = 0x1A,
        .func = GenericOptionChangeHandler,
    },
};

void DrawGameOptionIcon(int index, int offset)
{
    int tileref;
    int tm_offset = TM_OFFSET(0, index * 2 + offset);
    int icon_chr = gUiConfigOptions[GetConfigItem(index)].icon_chr;

    tileref = icon_chr + 0x4200;

    gBg2Tm[tm_offset + 0x02] = tileref;
    gBg2Tm[tm_offset + 0x03] = icon_chr + 0x4201;
    gBg2Tm[tm_offset + 0x22] = icon_chr + 0x4220;
    gBg2Tm[tm_offset + 0x23] = icon_chr + 0x4221;
}

struct ProcScr CONST_DATA ProcScr_RewriteUiConfigExplanition[] =
{
    PROC_NAME_DEBUG("E_CfExplReWrite"),
    PROC_SLEEP(1),
    PROC_CALL(DrawGameOptionHelpText),
    PROC_END,
};

void DrawGameOptionHelpText(void)
{
    ClearText(&gpUiConfigSt->text_helpbox);

    PutDrawText(
        &gpUiConfigSt->text_helpbox,
        gBg0Tm + TM_OFFSET(4, 17),
        TEXT_COLOR_SYSTEM_WHITE,
        0, 22,
        DecodeMsg(gUiConfigOptions[GetConfigItemCur()].selectors[GetSelectedOptionValue()].desc)
    );
}

void DrawGameOptionText(int order_index, int text_index, int y)
{
    ClearText(&gpUiConfigSt->texts_name[text_index]);

    PutDrawText(
        &gpUiConfigSt->texts_name[text_index],
        gBg2Tm + TM_OFFSET(4, y),
        TEXT_COLOR_SYSTEM_WHITE,
        0, 9,
        DecodeMsg(gUiConfigOptions[GetConfigItem(order_index)].msg)
    );
}

void DrawOptionValueTexts(int order_index, int text_index, int y)
{
    int i;
    int item_index = GetConfigItem(order_index);
    int x = gUiConfigOptions[item_index].selectors[0].x / 8;

    ClearText(&gpUiConfigSt->texts_options[text_index]);

    for (i = 0; i < 4; i++)
    {
        if (gUiConfigOptions[item_index].selectors[i].name == 0)
            break;

        Text_InsertDrawString(
            &gpUiConfigSt->texts_options[text_index],
            gUiConfigOptions[item_index].selectors[i].x - 0x78,
            i == GetGameOption(item_index)
                ? TEXT_COLOR_SYSTEM_BLUE
                : TEXT_COLOR_SYSTEM_GRAY,
            DecodeMsg(gUiConfigOptions[item_index].selectors[i].name)
        );
    }

    PutText(
        &gpUiConfigSt->texts_options[text_index],
        gBg2Tm + TM_OFFSET(x, y)
    );
}

struct ProcScr CONST_DATA ProcScr_ConfigObj[] =
{
    PROC_NAME_DEBUG("E_cfObj"),
    PROC_CALL(CfObj_Init),

PROC_LABEL(0),
    PROC_CALL(CfObj_Loop),
    PROC_CALL(CfObj_DrawAButton),
    PROC_YIELD,
    PROC_GOTO(0),

    PROC_END,
};

void CfObj_Init(ProcPtr proc)
{
    ApplyIconPalette(1, 0x12);
    UnpackUiVArrowGfx(0x80, 3);
}

void CfObj_DrawAButton(ProcPtr proc)
{
    if (GetSelectedGameOption() == 0 && GetSelectedOptionValue() == 3)
        PutSysAButton(0xC0, 0x20, 0x12);
}

void CfObj_Loop(ProcPtr proc)
{
    int y;
    int item_index = GetConfigItemCur();

    PutOamHi(0x22, 8, Sprite_UiConfigTitle, 0x20C0);

    y = (gpUiConfigSt->sel_index - gpUiConfigSt->top_index) * 0x10 + 0x20;

    PutFrozenUiHand(0x10, y);
    PutUiHand(gUiConfigOptions[item_index].selectors[GetGameOption(item_index)].x - 2, y);

    if (gpUiConfigSt->max_item > 6)
    {
        if (gpUiConfigSt->top_index != 0)
            DisplayUiVArrow(0x64, 0x1D, 0x3080, 1);

        if (gpUiConfigSt->top_index < (gpUiConfigSt->max_item - 6))
            DisplayUiVArrow(0x64, 0x7D, 0x3080, 0);
    }
}

struct ProcScr CONST_DATA ProcScr_Config[] =
{
    PROC_NAME_DEBUG("E_config"),
    PROC_CALL(LockGame),
    PROC_CALL(StartFastFadeToBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(LockBmDisplay),

PROC_LABEL(0),
    PROC_YIELD,
    PROC_CALL(Config_InitBg),
    PROC_CALL(Config_Init),
    PROC_CALL(StartFastFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_REPEAT(Config_Loop),
    PROC_CALL(StartFastFadeToBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(KillHelpBox),
    PROC_CALL_2(Config_End),

    PROC_CALL(UnlockBmDisplay),
    PROC_CALL(InitBmDisplay),
    PROC_CALL(StartFastFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),
    PROC_CALL(UnlockGame),
    PROC_END,
};

void Config_Init(struct UiConfigProc * proc)
{
    int i;

    gpUiConfigSt->list_index = 0;
    if (IsNotFirstPlaythrough())
        gpUiConfigSt->list_index++;

    gpUiConfigSt->max_item = gUiConfigOrder[gpUiConfigSt->list_index].max_item;
    gpUiConfigSt->sel_index = 0;
    gpUiConfigSt->top_index = 0;

    proc->bg_position = 0;
    proc->scrolling_type = 0;
    proc->goto_unique_anim_sel = 0;

    UnpackUiWindowFrameGraphics();

    SetDispEnable(1, 1, 1, 1, 1);
    SetBgOffset(BG_0, 0, 0);
    SetBgOffset(BG_1, 0, 0);
    SetBgOffset(BG_2, 0, proc->bg_position);
    SetBgOffset(BG_3, 0, 0);

    SetWinEnable(1, 0, 0);
    SetWin0Box(0, 0x20, 0xF0, 0x80);
    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(1, 1, 0, 1, 1);

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    TmFill(gBg2Tm, 0);
    TmFill(gBg3Tm, 0);

    ApplyPalette(Pal_PlayRankTimeOBJ, 4);
    ApplyPalette(Pal_PlayRankTimeOBJ, 0x12);
    Decompress(Img_0833B958, OBJ_VRAM0 + 0x1800);
    Decompress(Img_0833BB28, (void *)BG_VRAM + 0x4000);
    Decompress(Img_0833BB14, (void *)BG_VRAM + 0x5000 + GetBgChrOffset(BG_2));
    TmApplyTsa(gBg1Tm, Tsa_0833BE84, 0x1000);
    TmApplyTsa(gBg1Tm + TM_OFFSET(2, 0x10), Tsa_0833BF08, 0x1000);

    ResetTextFont();
    InitText(&gpUiConfigSt->text_helpbox, 0x16);
    DrawGameOptionHelpText();
    InitText(&gpUiConfigSt->text_68, 0x9);
    InitText(&gpUiConfigSt->text_A0, 0xE);

    for (i = 0; i < 6; i++)
    {
        int y = i * 2 + 4;

        DrawGameOptionIcon(i, 4);
        InitText(&gpUiConfigSt->texts_name[i], 9);
        InitText(&gpUiConfigSt->texts_options[i], 0xE);

        DrawGameOptionText(i, i, y);
        DrawOptionValueTexts(i, i, y);
    }

    StartMuralBackgroundExt(proc, NULL, -1);
    SpawnProc(ProcScr_ConfigObj, proc);
    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

bool WindowColorOptionChangeHandler(ProcPtr proc)
{
    if (GenericOptionChangeHandler(proc))
        UnpackUiWindowFrameGraphics2(-1);

    return false;
}

bool MusicOptionChangeHandler(ProcPtr proc)
{
    if (GenericOptionChangeHandler(proc))
    {
        if (GetGameOption(GetConfigItemCur()) != 0)
            FadeBgmOut(1);
        else
            StartMapSongBgm();
    }
    return false;
}

bool GenericOptionChangeHandler(ProcPtr proc)
{
    bool ret = false;
    int sel_index = gpUiConfigSt->sel_index;
    int item_index = GetConfigItem(sel_index);
    int _item_index = item_index;
    u8 option_value = GetSelectedOptionValue();

    if (gKeySt->repeated & (KEY_DPAD_LEFT | KEY_DPAD_RIGHT))
    {
        if (gKeySt->repeated & KEY_DPAD_LEFT)
        {
            if (option_value != 0)
            {
                option_value--;
                SetGameOption(item_index, option_value);
                ret = true;
            }
        }
        else
        {
            if (gUiConfigOptions[item_index].selectors[option_value + 1].name != 0)
            {
                if (option_value < 3)
                {
                    option_value++;
                    SetGameOption(_item_index, option_value);
                    ret = true;
                }
            }
        }

        if (ret)
        {
            SpawnProc(ProcScr_RewriteUiConfigExplanition, proc);
            DrawOptionValueTexts(sel_index, sel_index % 7, sel_index * 2 + 4);
            EnableBgSync(BG0_SYNC_BIT | BG2_SYNC_BIT);
            PlaySe(SONG_67);
        }
    }

    return ret;
}

u8 GetGameOption(u8 item_index)
{
    int value = 0;

    switch (item_index) {
    case GAME_OPTION_ANIMATION:
        switch (gPlaySt.config_battle_anim) {
        case PLAY_ANIMCONF_ON:
            return 0;
        case PLAY_ANIMCONF_ON_UNIQUE_BG:
            return 1;
        case PLAY_ANIMCONF_OFF:
            return 2;
        case PLAY_ANIMCONF_SOLO_ANIM:
            return 3;
        }

#if BUGFIX
        // lol
        break;
#endif

    case GAME_OPTION_TERRAIN:
        value = gPlaySt.config_terrain_mapui;
        break;

    case GAME_OPTION_UNIT:
        value = gPlaySt.config_unit_mapui;
        break;

    case GAME_OPTION_AUTOCURSOR:
        value = gPlaySt.config_no_auto_cursor;
        break;

    case GAME_OPTION_TEXT_SPEED:
        value = gPlaySt.config_talk_speed;
        break;

    case GAME_OPTION_GAME_SPEED:
        value = gPlaySt.config_walk_speed;
        break;

    case GAME_OPTION_MUSIC:
        value = gPlaySt.config_bgm_disable;
        break;

    case GAME_OPTION_SOUND_EFFECTS:
        value = gPlaySt.config_se_disable;
        break;

    case GAME_OPTION_WINDOW_COLOR:
        value = gPlaySt.config_window_theme;
        break;

    case GAME_OPTION_COMBAT:
        value = gPlaySt.config_battle_preview_kind;
        break;

    case GAME_OPTION_SUBTITLE_HELP:
        value = gPlaySt.config_no_subtitle_help;
        break;

    case GAME_OPTION_AUTOEND_TURNS:
        value = gPlaySt.config_no_auto_end_turn;
        break;

    case GAME_OPTION_UNIT_COLOR:
        value = gPlaySt.config_unique_pal;
        break;
    }

    return value;
}

void SetGameOption(u8 item_index, u8 option_value)
{
    switch (item_index) {
    case GAME_OPTION_ANIMATION:
        switch (option_value) {
        case 0:
            gPlaySt.config_battle_anim = PLAY_ANIMCONF_ON;
            return;

        case 1:
            gPlaySt.config_battle_anim = PLAY_ANIMCONF_ON_UNIQUE_BG;
            return;

        case 2:
            gPlaySt.config_battle_anim = PLAY_ANIMCONF_OFF;
            return;

        case 3:
            gPlaySt.config_battle_anim = PLAY_ANIMCONF_SOLO_ANIM;
            return;
        }

#if BUGFIX
        // lol
        break;
#endif

    case GAME_OPTION_TERRAIN:
        gPlaySt.config_terrain_mapui = option_value;
        break;

    case GAME_OPTION_UNIT:
        gPlaySt.config_unit_mapui = option_value;
        break;

    case GAME_OPTION_AUTOCURSOR:
        gPlaySt.config_no_auto_cursor = option_value;
        break;

    case GAME_OPTION_TEXT_SPEED:
        gPlaySt.config_talk_speed = option_value;
        break;

    case GAME_OPTION_GAME_SPEED:
        gPlaySt.config_walk_speed = option_value;
        break;

    case GAME_OPTION_MUSIC:
        gPlaySt.config_bgm_disable = option_value;
        break;

    case GAME_OPTION_SOUND_EFFECTS:
        gPlaySt.config_se_disable = option_value;
        break;

    case GAME_OPTION_WINDOW_COLOR:
        gPlaySt.config_window_theme = option_value;
        break;

    case GAME_OPTION_COMBAT:
        gPlaySt.config_battle_preview_kind = option_value;
        break;

    case GAME_OPTION_SUBTITLE_HELP:
        gPlaySt.config_no_subtitle_help = option_value;
        break;

    case GAME_OPTION_AUTOEND_TURNS:
        gPlaySt.config_no_auto_end_turn = option_value;
        break;

    case GAME_OPTION_UNIT_COLOR:
        gPlaySt.config_unique_pal = option_value;
        break;
    }
}

void RefrashUiConfigScreen(ProcPtr proc, int sel_index, int tm_offset)
{
    int i, text_index;
    int y = sel_index * 2 + 4;
    int iy = TM_OFFSET(0, y);

    for (i = 0; i <= 0x1A; i++)
    {
        gBg2Tm[iy + 0x02 + i] = 0;
        gBg2Tm[iy + 0x22 + i] = 0;
    }

    text_index = sel_index % 7;

    DrawGameOptionIcon(sel_index, 4);
    DrawGameOptionText(sel_index, text_index, y);
    DrawOptionValueTexts(sel_index, text_index, y);

    for (i = 0; i <= 0x1A; i++)
        gBg0Tm[tm_offset + 0x62 + i] = 0;

    EnableBgSync(BG0_SYNC_BIT | BG2_SYNC_BIT);
}

void Config_Loop(struct UiConfigProc * proc)
{
    bool ret = false;

    switch (proc->scrolling_type) {
    case 0:
        if (gKeySt->pressed & KEY_BUTTON_B)
        {
            PlaySe(SONG_6B);
            Proc_Break(proc);
            break;
        }
        else if (gKeySt->pressed & KEY_BUTTON_A)
        {
            if (GetConfigItemCur() != 0)
                break;

            if (GetGameOption(GAME_OPTION_ANIMATION) != 3)
                break;

            PlaySe(SONG_6A);
            proc->goto_unique_anim_sel = 1; // something related to unique anim selection?
            Proc_Break(proc);
            break;
        }
        else if (gKeySt->repeated & (KEY_DPAD_UP | KEY_DPAD_DOWN))
        {
            if (gKeySt->repeated & KEY_DPAD_UP)
            {
                /* UP */
                if (gpUiConfigSt->sel_index != 0)
                {
                    gpUiConfigSt->sel_index--;

                    if (((gpUiConfigSt->sel_index - gpUiConfigSt->top_index) < 1) && gpUiConfigSt->top_index != 0)
                    {
                        gpUiConfigSt->top_index--;
                        RefrashUiConfigScreen(proc, gpUiConfigSt->sel_index - 1, 0);
                        proc->bg_position -= 4;
                        proc->scrolling_type = 1;
                    }
                    ret = true;
                }
            }
            else
            {
                /* DOWN */
                if (gpUiConfigSt->sel_index < (gpUiConfigSt->max_item - 1))
                {
                    gpUiConfigSt->sel_index++;

                    if (((gpUiConfigSt->sel_index - gpUiConfigSt->top_index) > 4) && gpUiConfigSt->sel_index < (gpUiConfigSt->max_item - 1))
                    {
                        gpUiConfigSt->top_index++;
                        RefrashUiConfigScreen(proc, gpUiConfigSt->sel_index + 1, 0x140);
                        proc->bg_position += 4;
                        proc->scrolling_type = 4;
                    }
                    ret = true;
                }
            }

            if (ret)
            {
                SpawnProc(ProcScr_RewriteUiConfigExplanition, proc);
                EnableBgSync(BG0_SYNC_BIT | BG2_SYNC_BIT);
                PlaySe(0x66);
                break;
            }
        }

        if (gKeySt->pressed & (KEY_DPAD_LEFT | KEY_DPAD_RIGHT))
        {
            if (gUiConfigOptions[GetConfigItemCur()].func)
                gUiConfigOptions[GetConfigItemCur()].func(proc);
        }
        break;

    case 1:
    case 2:
    case 3:
        proc->bg_position -= 4;
        if (proc->scrolling_type == 3)
            proc->scrolling_type = 0;
        else
            proc->scrolling_type++;

        break;

    case 4:
    case 5:
    case 6:
        proc->bg_position += 4;
        if (proc->scrolling_type == 6)
            proc->scrolling_type = 0;
        else
            proc->scrolling_type++;

        break;
    }

    SetBgOffset(BG_2, 0, proc->bg_position);
}

bool Config_End(struct UiConfigProc * proc)
{
    EndMuralBackground();
    Proc_EndEach(ProcScr_ConfigObj);
    Proc_EndEach(ProcScr_RewriteUiConfigExplanition);

    if (proc->goto_unique_anim_sel)
    {
        StartUnitListScreenForSoloAnim(proc);
        Proc_Goto(proc, 0);
        return false;
    }
    return true;
}
