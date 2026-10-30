#pragma once

#include "prelude.h"
#include "proc.h"
#include "text.h"

enum config_item_index {
    GAME_OPTION_ANIMATION      =  0,
    GAME_OPTION_TERRAIN        =  1,
    GAME_OPTION_UNIT           =  2,
    GAME_OPTION_AUTOCURSOR     =  3,
    GAME_OPTION_TEXT_SPEED     =  4,
    GAME_OPTION_GAME_SPEED     =  5,
    GAME_OPTION_MUSIC          =  6,
    GAME_OPTION_SOUND_EFFECTS  =  7,
    GAME_OPTION_WINDOW_COLOR   =  8,
    GAME_OPTION_CPU_LEVEL      =  9,
    GAME_OPTION_COMBAT         = 10,
    GAME_OPTION_SUBTITLE_HELP  = 11,
    GAME_OPTION_AUTOEND_TURNS  = 12,
    GAME_OPTION_UNIT_COLOR     = 13,
};

struct ConfigSt {
    PROC_HEADER; /* well.....fine */

    /* 2A */ i16 sel_index;
    /* 2C */ i16 top_index;
    
    STRUCT_PAD(0x2E, 0x32);

    /* 32 */ i16 list_index;
    /* 34 */ i16 max_item;

    STRUCT_PAD(0x36, 0x38);

    /* 38 */ struct Text texts_name[6];
    /* 68 */ struct Text text_68;
    /* 70 */ struct Text texts_options[6];
    /* A0 */ struct Text text_A0;
    /* A8 */ struct Text text_helpbox;
};

extern CONST_DATA struct ConfigSt * gpUiConfigSt;

struct UiConfigOrder {
    u8 max_item;
    const u8 * order_list;
};

extern CONST_DATA struct UiConfigOrder gUiConfigOrder[];

#define GetConfigItem(sel_index) (gUiConfigOrder[gpUiConfigSt->list_index].order_list[(sel_index)])
#define GetConfigItemCur() (GetConfigItem(gpUiConfigSt->sel_index))

struct UiConfigOption {
    /* 00 */ u16 msg;

    struct {
        u16 desc, name;
        u8 x, unk_05;
    } selectors[4];

    /* 24 */ u8 icon_chr;
    /* 28 */ bool (*func)(ProcPtr proc);
};

extern CONST_DATA struct UiConfigOption gUiConfigOptions[];

struct UiConfigProc {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2E);

    /* 2E */ u16 bg_position;
    /* 30 */ i16 scrolling_type;

    STRUCT_PAD(0x32, 0x36);

    /* 36 */ u8 goto_unique_anim_sel;
};

u8 GetSelectedGameOption(void);
u8 GetSelectedOptionValue(void);
void Config_InitBg(void);
void StartMuralBackgroundExt(ProcPtr parent, void * vram_dst, int pal_bank);
void DrawGameOptionIcon(int index, int offset);
void DrawGameOptionHelpText(void);
void DrawGameOptionText(int order_index, int text_index, int y);
void DrawOptionValueTexts(int order_index, int text_index, int y);
void CfObj_Init(ProcPtr proc);
void CfObj_DrawAButton(ProcPtr proc);
void CfObj_Loop(ProcPtr proc);
void Config_Init(struct UiConfigProc * proc);
bool WindowColorOptionChangeHandler(ProcPtr proc);
bool MusicOptionChangeHandler(ProcPtr proc);
bool GenericOptionChangeHandler(ProcPtr proc);
u8 GetGameOption(u8 item_index);
void SetGameOption(u8 item_index, u8 option_value);
void RefrashUiConfigScreen(ProcPtr proc, int sel_index, int tm_offset);
void Config_Loop(struct UiConfigProc * proc);
bool Config_End(struct UiConfigProc * proc);

extern CONST_DATA u16 Sprite_UiConfigTitle[];
extern CONST_DATA struct ProcScr ProcScr_RewriteUiConfigExplanition[];
extern CONST_DATA struct ProcScr ProcScr_ConfigObj[];
extern CONST_DATA struct ProcScr ProcScr_Config[];
