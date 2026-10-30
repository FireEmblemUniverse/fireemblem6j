#pragma once

#include "prelude.h"
#include "proc.h"
#include "text.h"
#include "save_multiarena.h"
#include "sio_core.h"

struct ProcSioBlend
{
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x58);

    /* 58 */ u32 timer;
};

struct ProcSioHold
{
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ int x;
    /* 30 */ int y;
    /* 34 */ int y_min;
    /* 38 */ int y_max;
};

struct SioSaveConf
{
    u8 unk_0 : 1;
    u8 unk_1 : 1;
    u8 unk_2 : 1;
    u8 unk_3 : 1;
    u8 unk_4 : 4;
    u8 unk_8;
} __attribute__((packed));

struct LinkArenaTeamEnt
{
    /* 00 */ char name[MULTIARENA_TEAMNAME_SIZE + 1];
    /* 0F */ u8 unk_0F;
    /* 10 */ u8 unk_10;
    /* 11 */ STRUCT_PAD(0x11, 0x14);
};

struct LATeamListConfig
{
    /* 00 */ u8 kind;
    /* 01 */ STRUCT_PAD(0x01, 0x02);
    /* 02 */ u16 help_msg;
    /* 04 */ u8 unk_04;
    /* 05 */ u8 unk_05;
    /* 06 */ STRUCT_PAD(0x06, 0x08);
    /* 08 */ char const * menu_text;
    /* 0C */ bool (* is_valid)(void);
};

enum
{
    MULTIARENA_LIST_NONE = 0,
    MULTIARENA_LIST_BUILDTEAM = 1,
    MULTIARENA_LIST_SELECTTEAM = 2,
    MULTIARENA_LIST_UNITLIST = 3,
    MULTIARENA_LIST_SWAP = 4,
    MULTIARENA_LIST_CONFIRMSWAP = 5,
    MULTIARENA_LIST_DISBAND = 6,
    MULTIARENA_LIST_LINKMENU = 7,
    MULTIARENA_LIST_8 = 8,
};

struct SioProc85AAA78
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ int unk_2C;
    /* 30 */ i16 unk_30[5];
    /* 3A */ u8 unk_3A[5];
    /* 3F */ STRUCT_PAD(0x3F, 0x40);
    /* 40 */ int unk_40;
    /* 44 */ i8 unk_44;
    /* 45 */ STRUCT_PAD(0x45, 0x48);
    /* 48 */ int unk_48;
};

struct SioTeamListProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ struct SioProc85AAA78 * unk_2C;
    /* 30 */ ProcPtr sio_hold_proc;
    /* 34 */ int num_active_options;
    /* 38 */ int unk_38;
    /* 3C */ int option_idx;
    /* 40 */ int unk_40;
    /* 44 */ int unk_44;
    /* 48 */ u8 unk_48;
    /* 49 */ STRUCT_PAD(0x49, 0x4A);
    /* 4A */ u16 y_bg1;
    /* 4C */ i8 unk_4C;
    /* 4D */ u8 valid_options[5];
    /* 52 */ u8 selected_option;
    /* 53 */ u8 selected_team;
    /* 54 */ u8 unk_54;
    /* 55 */ u8 unk_55;
    /* 56 */ STRUCT_PAD(0x56, 0x58);
    /* 58 */ int unk_58;
    /* 5C */ i8 unk_5C;
};

extern struct Text gSioMenuTexts[];
extern struct Text gSioPromptText;
extern struct SioSaveConf gSioSaveConfig;
extern struct Font gSioFont;
extern struct LinkArenaTeamEnt gLinkArenaTeamList[];
extern struct Text gSioTexts[2];
extern u16 gKeyInputSequenceBuffer[16];
extern int gKeyInputSequenceTimer;
extern char gSioSelectedTeamNames[][MULTIARENA_TEAMNAME_SIZE + 1];
extern int gCurrentKeyInSeqIndex;
extern int gTargetKeyInSeqIndex;

extern int const gUnk_Sio_0810F190[];
extern u8 const gUnk_Sio_0810F19C[];
extern i8 const gXposArray_SioTeamListSwicthing[];

extern struct ProcScr CONST_DATA ProcScr_SioHOLD[];
extern u16 CONST_DATA KeyList_SioSecretTeam[];
extern u16 CONST_DATA gSioKeyList_PasswordScreenEN[];
extern struct LATeamListConfig * CONST_DATA gSioTeamListConfigLut[];
extern void const * CONST_DATA gUnk_Sio_085C9AD4[];
extern struct ProcScr CONST_DATA ProcScr_SioTeamList[];

extern u8 const Img_TacticianSelObj[];
extern u16 const Pal_TacticianSelObj[];
extern u8 const Img_Sio_081080D4[];
extern u8 const Tsa_Sio_08109DF4[];

void SIOCON_Init(void);
void SIOCON_Loop(ProcPtr proc);
void SetBmStLinkArenaFlag(void);
void UnsetBmStLinkArenaFlag(void);
void func_fe6_080369A0(struct ProcSioBlend * proc);
void func_fe6_080369E0(struct ProcSioBlend * proc);
void func_fe6_08036A40(void);
void func_fe6_08036A54(ProcPtr proc);
void func_fe6_08036A80(void);
void func_fe6_08036A94(ProcPtr proc);
void SioHold_Loop(struct ProcSioHold * proc);
ProcPtr StartSioHold(ProcPtr parent, int x, int y, int y_max, int y_min);
void EndSioHold(void);
void func_fe6_08036B38(ProcPtr proc, int num);
void ClearSioBG(void);
void ClearSioAllBGs(void);
void SioPutText(int msg, int text_idx);
void func_fe6_08036C60(void);
void SioSetNormalWeapons(struct Unit * unit);
void SioPlaySe(int idx);
void func_fe6_08036D3C(void);
bool SioIsKeyInputSequenceComplete(u16 const * list);
void StartLinkArenaTeamList(ProcPtr parent);
void SioTeamList_Init(struct SioTeamListProc * proc);
bool CanBuildNewLinkArenaTeam(void);
bool CanDirectlyBuildNewLinkArenaTeam(void);
int GetSioTeams(int active_option, u8 mode);
void DrawLinkArenaTeamName(int idx);
void DrawAllLinkArenaTeams(struct SioTeamListProc * proc);
void func_fe6_0803703C(struct SioTeamListProc * proc, u8 mode);
void SioTeamList_EraseTeam(struct SioTeamListProc * proc);
void SioTeamList_SwapTeams(struct SioTeamListProc * proc);
int func_fe6_080372B0(u8 mode, struct SioTeamListProc * proc);
u16 GetLATeamListHelpTextId(struct SioTeamListProc * proc);
void SioTeamList_SetupGfx(struct SioTeamListProc * proc);
void SioTeamList_Main_HandleDPadInput(int * selection, u8 max, u8 min, u8 total);
void SioTeamList_Loop_MainKeyHandler(struct SioTeamListProc * proc);
void SioTeamList_StartUnitList(struct SioTeamListProc * proc);
void SioTeamList_WaitForUnitListScreen(ProcPtr proc);
int func_fe6_0803784C(void);
void SioTeamList_Loop_SubSel(struct SioTeamListProc * proc);
void func_fe6_08037D74(struct SioProc85AAA78 * proc, i8 x);
void SioTeamList_SubSel_Switching(struct SioTeamListProc * proc);
void func_fe6_08037E14(struct SioTeamListProc * proc);
void SioTeamList_StartEraseTeamSubMenu(struct SioTeamListProc * proc);
void SioTeamList_EraseTeam_KeyHandler(struct SioTeamListProc * proc);
void SioTeamList_LoadTeam_Dummy(struct SioTeamListProc * proc);

void InitSioBG(void);
void Sio_RestartBgSlide(ProcPtr parent, int lines);
void Sio_EndBackgroundSlide(void);
void StartLinkArenaTitleBanner(ProcPtr parent, int kind);
void func_fe6_0803FD40(u8 const * chars, int count, int x, int y, int pal, ProcPtr parent);
struct SioProc85AAA78 * func_fe6_080403C0(struct SioTeamListProc * parent, int count, u8 * buf);
void ScrollMultiArenaTeamSprites(int amount);
void UpdateLinkArenaMenuScrollBar(u8 total, i16 scroll);
void SioPutSupportMenuImage(void);
void PutLinkArenaChoiceBannerSprite(int x, int y);

struct TacticianTextConf
{
    /* 00 */ char const * str[3][3];
    /* 24 */ u16 x;
    /* 26 */ u16 y;
    /* 28 */ u8 kind;
    /* 2A */ i16 adj_idx[4];
    /* 32 */ u8 action;
};

struct ProcTactician
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ ProcPtr child;
    /* 30 */ u8 line_idx;
    /* 31 */ u8 text_idx;
    /* 32 */ i16 conf_idx;
    /* 34 */ i16 prev_conf_idx;
    /* 36 */ u8 cur_len;
    /* 37 */ u8 unk_37;
    /* 38 */ u8 unk_38;
    /* 39 */ u8 unk_39;
    /* 3A */ char str[0x10];
    /* 4A */ u16 unk_4A[7];
};

struct SioRankEntry
{
    /* 00 */ u8 player_id;
    /* 04 */ u32 points;
};

struct SioBattleMapScoreEnt
{
    /* 00 */ u8 unit_id;
    /* 04 */ int new_score;
};

struct SioBattleMapSt
{
    /* 00 */ u8 unk_00;
    /* 01 */ u8 unk_01;
    /* 02 */ u8 unk_02;
    /* 03 */ u8 unk_03;
    /* 04 */ u8 unk_04;
    /* 05 */ u8 unk_05;
    /* 06 */ u8 unk_06;
    /* 07 */ u8 unk_07;
    /* 08 */ u8 unk_08;
    /* 09 */ u8 unk_09;
    /* 0A */ u8 unk_0A[4];
    /* 0E */ u8 unk_0E;
    /* 0F */ u8 unk_0F[4];
    /* 13 */ STRUCT_PAD(0x13, 0x14);
    /* 14 */ int current_score[4];
    /* 24 */ u16 unk_24[4];
    /* 2C */ struct SioBattleMapScoreEnt unk_2C[4];
};

struct SioBattleMapProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ int unk_2C;
    /* 30 */ int unk_30;
    /* 34 */ int unk_34;
    /* 38 */ int unk_38;
    /* 3C */ STRUCT_PAD(0x3C, 0x54);
    /* 54 */ struct MuProc * unk_54;
    /* 58 */ int unk_58;
    /* 5C */ int unk_5C;
};

struct SioAttackProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 game_lock;
};

struct SioWarpWindowProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x4C);
    /* 4C */ i16 clock;
    /* 4E */ STRUCT_PAD(0x4E, 0x64);
    /* 64 */ i16 duration;
};

struct SioMuProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ struct MuProc * mu;
};

struct SioWarpProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ struct Unit * unit;
    /* 30 */ struct MuProc * mu;
    /* 34 */ int x;
    /* 38 */ int y;
    /* 3C */ int facing;
    /* 40 */ u8 clock;
    /* 41 */ i8 play_step_se;
};

struct SioSpriteDrawProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ int x;
    /* 30 */ int y;
};

struct LinkArenaTitleBannerProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x58);
    /* 58 */ int kind;
};

struct SioScrollingTextProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ int x;
    /* 30 */ int y;
    /* 34 */ int x_cur;
    /* 38 */ int y_cur;
    /* 3C */ int count;
    /* 40 */ int clock;
};

struct LATeamSpriteDrawProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ int x;
    /* 30 */ int y;
    /* 34 */ int y_min;
    /* 38 */ int y_max;
    /* 3C */ int count;
};

struct NameEntrySpriteDrawProc
{
    /* 00 */ PROC_HEADER_EXT(struct ProcTactician);
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ int x_cur;
    /* 30 */ int y_cur;
    /* 34 */ int x_new;
    /* 38 */ int y_new;
    /* 3C */ int cursor_kind;
    /* 40 */ int x_pointer;
    /* 44 */ int line;
};

struct RuleSettingSpriteDrawProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ i16 y_prev;
    /* 2C */ i16 y_new;
    /* 2E */ i16 x_option;
    /* 30 */ i16 y_option;
};

struct SioMenuBurstFxProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ int x;
    /* 30 */ int y;
    /* 34 */ STRUCT_PAD(0x34, 0x4C);
    /* 4C */ i16 clock;
};

struct LAMenuScrollBarProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ int x;
    /* 30 */ int y;
    /* 34 */ int height;
    /* 38 */ int bar_len;
    /* 3C */ u8 total;
    /* 3D */ u8 visible;
    /* 3E */ i16 scroll;
    /* 40 */ i16 prev_scroll;
    /* 42 */ u16 unk_42;
    /* 44 */ u8 arrow_clock[2];
};

struct LAPointsBoxProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ struct Text text[4];
};

struct PointsNumberMoverProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ i16 x;
    /* 2C */ i16 y;
    /* 2E */ i16 x_target;
    /* 30 */ i16 y_target;
    /* 32 */ u8 player_id;
    /* 33 */ u8 unit_id;
    /* 34 */ int difference;
    /* 38 */ u32 new_score;
    /* 3C */ u32 timer;
    /* 40 */ i8 unk_40;
    /* 41 */ STRUCT_PAD(0x41, 0x44);
    /* 44 */ int unk_44;
    /* 48 */ struct Text text;
};

struct PointsSpriteTextProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ int x;
    /* 30 */ int y;
    /* 34 */ STRUCT_PAD(0x34, 0x4C);
    /* 4C */ i16 timer;
    /* 4E */ STRUCT_PAD(0x4E, 0x54);
    /* 54 */ char const * str;
};

struct SioPostBattleProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ ProcPtr unk_2C[4];
    /* 3C */ STRUCT_PAD(0x3C, 0x40);
    /* 40 */ u8 unk_40;
    /* 41 */ u8 unk_41;
    /* 42 */ u8 player_id;
    /* 43 */ u8 unk_43;
    /* 44 */ struct SioRankEntry unk_44[4];
    /* 64 */ int unk_64;
};

struct SioPostBattleSpritesProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ struct SioPostBattleProc * unk_2C;
    /* 30 */ int x;
    /* 34 */ int y;
    /* 38 */ int delay;
    /* 3C */ int timer;
    /* 40 */ u16 fid;
    /* 42 */ u8 oam2;
    /* 43 */ u8 ranking;
};

struct SioPostBattleMusicProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x58);
    /* 58 */ int is_player_winner;
};

struct SioBatProc_Unk2C
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ int x;
    /* 30 */ int y;
    /* 34 */ int unk_34;
    /* 38 */ int unk_38;
    /* 3C */ u16 scale[4];
};

struct SioBatProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ struct SioBatProc_Unk2C * unk_2C;
    /* 30 */ int unk_30;
    /* 34 */ int unk_34;
    /* 38 */ u8 unk_38;
    /* 39 */ u8 unk_39;
    /* 3A */ u8 unk_3A;
    /* 3B */ u8 unk_3B;
    /* 3C */ STRUCT_PAD(0x3C, 0x4C);
    /* 4C */ i16 unk_4C;
    /* 4E */ STRUCT_PAD(0x4E, 0x58);
    /* 58 */ int unk_58;
    /* 5C */ STRUCT_PAD(0x5C, 0x64);
    /* 64 */ i16 unk_64;
};

struct SioTermProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ int unk_2C[3];
    /* 38 */ int unk_38[3];
    /* 44 */ STRUCT_PAD(0x44, 0x48);
    /* 48 */ int unk_48;
    /* 4C */ int unk_4C;
    /* 50 */ int unk_50;
};

struct LinkArenaRuleInfo
{
    /* 00 */ char const * label;
    /* 04 */ int x_pos[2];
    /* 0C */ char const * option_text[2];
};

struct SioResultProcUnk2C
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x30);
    /* 30 */ int unk_30;
};

struct SioResultProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ struct SioResultProcUnk2C * unk_2C;
    /* 30 */ int unk_30;
    /* 34 */ u8 unk_34;
    /* 35 */ u8 unk_35;
    /* 36 */ u16 unk_36;
    /* 38 */ i8 unk_38;
    /* 39 */ u8 unk_39;
    /* 3A */ STRUCT_PAD(0x3A, 0x3C);
    /* 3C */ int unk_3C;
    /* 40 */ int unk_40;
};

struct ProcSioRuleSettings
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ ProcPtr unk_2C;
    /* 30 */ int unk_30;
};

struct SioMenuItemProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ i16 x_base;
    /* 2C */ i16 y_base;
    /* 2E */ u8 state;
    /* 2F */ u8 index;
    /* 30 */ u8 glow_frame;
    /* 32 */ i16 x_left_arrow;
    /* 34 */ i16 x_right_arrow;
    /* 36 */ u16 left_arrow_clock;
    /* 38 */ u16 right_arrow_clock;
    /* 3A */ i16 left_arrow_speed;
    /* 3C */ i16 right_arrow_speed;
    /* 3E */ u8 unk_3E;
};

struct SioMenuProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ struct SioMenuItemProc * menu_items[5];
    /* 40 */ u8 menu_item_state[5];
    /* 45 */ STRUCT_PAD(0x45, 0x48);
    /* 48 */ int unk_48;
    /* 4C */ int unk_4C;
    /* 50 */ int unk_50;
    /* 54 */ int unk_54;
    /* 58 */ i8 unk_58;
    /* 59 */ i8 unk_59;
};

extern struct TacticianTextConf const gTacticianTextConf[];
extern i16 const gUnk_Sio_0810EFD2[];
extern struct Text gSioLineTexts[];
extern struct Text gSioHeaderText;
extern i8 gUnk_Sio_0203C918;
extern u8 gUnk_030013E8;
extern u16 const gUnk_08109C40[];
extern u8 const gUnk_0810A044[];
extern struct SioBattleMapSt gSioBmSt;
extern struct Font gSioSpriteFont;
extern struct Text gSioSpriteTexts[];
extern u8 gUnk_030013F0[20];
extern struct Vec2i gUnk_03001404;
extern int gUnk_03001408;
extern u8 gUnk_0300140C[4];
extern struct MuProc * gUnk_03001410[2];
extern u16 gUnk_03001418[5];
extern char gUnk_03001428[];
extern u8 const gUnk_08109854[];
extern u8 CONST_DATA gUnk_Sio_085CA7E0[];
extern u8 CONST_DATA gUnk_Sio_085CA7E4[];
extern u8 CONST_DATA gUnk_Sio_085CA8B4[];
extern struct ProcScr CONST_DATA ProcScr_LAButtonSpriteDraw[];
extern u16 CONST_DATA gUnk_Sio_085CAFB4[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CAFC4[];
extern u16 CONST_DATA gUnk_Sio_085CAFE4[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CAFEC[];
extern u16 const * CONST_DATA gUnk_Sio_085CB00C[];
extern u16 const * CONST_DATA gUnk_Sio_085CB020[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CB02C[];
extern u16 CONST_DATA gUnk_Sio_085CB044[];
extern u16 CONST_DATA gUnk_Sio_085CB07A[];
extern u16 const * CONST_DATA gUnk_Sio_085CB0B4[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CB0BC[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CB0D4[];
extern u16 const * CONST_DATA gUnk_Sio_085CB0EC[];
extern u16 const * CONST_DATA gUnk_Sio_085CB0F4[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CB108[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CB12C[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CB144[];
extern u16 CONST_DATA gUnk_Sio_085CB15C[];
extern u16 CONST_DATA gUnk_Sio_085CB164[];
extern u16 CONST_DATA gUnk_Sio_085CB16C[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CB174[];
extern struct ProcScr CONST_DATA ProcScr_LAVersusSpriteDraw[];
extern struct ProcScr CONST_DATA ProcScr_Sio_085CB204[];
extern u8 gSioImgBuf[];
extern u16 const * CONST_DATA SpriteArray_LAVersusPlayerNumbers[];
extern int gUnk_03001438;
extern u8 const gUnk_0810A62C[];
extern u8 const gUnk_0810AADC[];
extern u8 const gUnk_0810AF9C[];
extern u8 const gUnk_0810B44C[];
extern u8 const gUnk_0810B900[];
extern u16 const gUnk_0810BA60[];
extern u16 const gUnk_0810BA80[];
extern u16 const gUnk_0810BAA0[];
extern u16 const gUnk_0810BAC0[];
extern u16 const * CONST_DATA gUnk_Sio_085CB120[];
extern u16 const gUnk_08109C00[];
extern u8 const gUnk_081065C8[];
extern u16 const gUnk_08109B00[];
extern u16 const gUnk_08109BC0[];
extern u16 const gUnk_08109C20[];
extern u8 const gUnk_08106784[];
extern u8 const gUnk_08109D78[];
extern u16 const * CONST_DATA gUnk_Sio_085CAE6C[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CAE84[];
extern u8 CONST_DATA gUnk_Sio_085CAE9C[];
extern struct ProcScr CONST_DATA ProcScr_SIOWARP[];
extern struct ProcScr CONST_DATA ProcScr_SIOWARPFX[];
extern struct ProcScr CONST_DATA ProcScr_SioWarpFxPartial[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CA8D4[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CADFC[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CAE34[];
extern i8 Unk_Sio_0203C9D0;
extern i16 gSioWinLineBuf[];
extern i16 * gSioWinBufFront;
extern i16 * gSioWinBufBack;
extern i16 * gSioWinHBlankBuf;
extern struct PopupInfo CONST_DATA gUnk_Sio_085CA884[];
extern struct PopupInfo CONST_DATA gUnk_Sio_085CA8A4[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CA834[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CADA4[];
extern struct MenuInfo CONST_DATA gUnk_Sio_085CB384;
extern EventScr CONST_DATA gUnk_Sio_085CA93C[];
extern EventScr CONST_DATA gUnk_Sio_085CA958[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CA974[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CAB24[];
extern struct ProcScr CONST_DATA gUnk_Sio_085CAC14[];
extern u8 const Img_LAPointsBox[];
extern int CONST_DATA gUnk_Sio_085CA70C[];
extern i16 CONST_DATA gUnk_Sio_085CA72C[];
extern i16 CONST_DATA gUnk_Sio_085CA752[];
extern struct ProcScr CONST_DATA ProcScr_LinkArenaPointsBox[];
extern struct ProcScr CONST_DATA ProcScr_LinkArena_PointsNumberMover[];
extern struct ProcScr CONST_DATA ProcScr_LinkArena_PointsSpriteText[];
extern struct MultiArenaRankingEnt gSioResultRankings[];
extern u16 const * CONST_DATA SpriteArray_Sio_085C9CF8[];
extern u16 const * CONST_DATA SpriteArray_Sio_085C9D08[];
extern struct ProcScr CONST_DATA ProcScr_LinkArenaPostBattle_DrawSprites[];
extern struct ProcScr CONST_DATA ProcScr_SioPostBattle_PlayMusic[];
extern u8 const Img_LinkArenaPlayerBanners[];
extern u8 const Img_LinkArenaPlacementRanks[];
extern u16 const Pal_LinkArenaPlacementRanks[];
extern u8 const Img_LinkArenaActiveBannerFx[];
extern u16 const Pal_LinkArenaActiveBannerFx[];
extern u8 const Img_LinkArenaPostBattleBg[];
extern u16 const Pal_LinkArenaPostBattleBg[];
extern u8 const Tsa_LinkArenaPostBattleBg[];
extern u8 const gUnk_08109CC0[];
extern struct ProcScr CONST_DATA ProcScr_SIOMAIN2[];
extern struct ProcScr CONST_DATA ProcScr_SIOVSYNC[];
extern struct ProcScr CONST_DATA ProcScr_SIOMAIN[];
extern struct ProcScr CONST_DATA ProcScr_SIOCON[];
extern char const * CONST_DATA gUnk_Sio_085C99B0[];
extern u16 const gUnk_08109C60[];
extern struct SioData gSioBuf_030044E0;
extern struct FaceVramEnt CONST_DATA gUnk_Sio_085C9E88[];
extern int gSioWaitTimer;
extern struct MultiArenaSaveTeam * CONST_DATA gUnk_Sio_085C9EA8;
extern struct ProcScr CONST_DATA gUnk_Sio_085C99C8[];
extern u8 const Img_LinkArenaRankIcons[];
extern u16 const Pal_LinkArenaRankIcons[];
extern char const SioText_HideUnits[];
extern char const SioText_VictoryCondition[];
extern char const SioText_Points[];
extern char const SioText_Survival[];
extern char const SioText_AutoWeapons[];
extern char const SioText_On[];
extern char const SioText_Off[];
extern char const SioText_NowLoading[];
extern struct LinkArenaRuleInfo const gLinkArenaRuleData[];
extern struct ProcScr CONST_DATA ProcScr_SIORESULT_NewHighScore[];
extern u16 const gUnk_08109AC0[];
extern u8 const gUnk_0810A318[];
extern u8 const gUnk_08109648[];
extern u8 const Img_SioMenuBgSlide[];
extern u16 const Pal_SioMenuBgSlide[];
extern u16 CONST_DATA gUnk_Sio_085C99F8[];
extern struct FaceVramEnt CONST_DATA gUnk_Sio_085CA404[];
extern struct FaceVramEnt CONST_DATA gUnk_Sio_085CA424[];
extern struct ProcScr CONST_DATA ProcScr_SIOTERM[];
extern struct ProcScr CONST_DATA ProcScr_SIOPRA[];
extern struct ProcScr CONST_DATA ProcScr_SIOBAT[];
extern struct ProcScr CONST_DATA ProcScr_SIORESULT[];
extern struct ProcScr CONST_DATA ProcScr_SIO_RuleSettings[];
extern struct ProcScr CONST_DATA ProcScr_SioMenuBurstFx[];
extern struct ProcScr CONST_DATA ProcScr_SIOMENU[];
extern int gSioXmapOption;
extern u8 gSioXmapBuf[];
extern EventScr CONST_DATA EventScr_SioXMapTransfer[];
extern EventScr CONST_DATA EventScr_SioXmap_085CA6B8[];

struct TacticianTextConf const * GetTacticianTextConf(i16 idx);
void func_fe6_08038040(struct ProcTactician * proc);
void TacticianDrawCharacters(struct ProcTactician * proc);
void Tactician_InitScreen(struct ProcTactician * proc);
void SioUpdateTeam(char const * str, int team);
void Tactician_MoveHand(struct ProcTactician * proc, int pos, struct TacticianTextConf const * conf);
void TacticianTryAppendChar(struct ProcTactician * proc, struct TacticianTextConf const * conf);
void TacticianTryDeleteChar(struct ProcTactician * proc, struct TacticianTextConf const * conf);
void SaveTactician(struct ProcTactician * proc, struct TacticianTextConf const * conf);
bool func_fe6_0803848C(struct ProcTactician * proc, struct TacticianTextConf const * conf, int c, int d);
void Tactician_LoopCore(struct ProcTactician * proc, struct TacticianTextConf const * conf);
void Tactician_Loop(struct ProcTactician * proc);
void Tactician_VBlank(void);
void Tactician_SetVBlank(struct ProcTactician * proc);
void func_fe6_080388A4(struct ProcTactician * proc);
void func_fe6_080388E4(struct ProcTactician * proc);
void func_fe6_08038910(struct ProcTactician * proc);
void NameSelect_DrawName(struct ProcTactician * proc);
void func_fe6_08038990(struct ProcTactician * proc);
void SioPostBattleSprites_Init(struct SioPostBattleSpritesProc * proc);
void SioPostBattleSprites_Loop_DrawSlideIn(struct SioPostBattleSpritesProc * proc);
void SioPostBattleSprites_Loop_DrawStatic(struct SioPostBattleSpritesProc * proc);
ProcPtr StartDrawLinkArenaRankSprites(struct SioPostBattleProc * parent, int delay, u16 fid, u8 oam2, u8 ranking);
void func_fe6_08038D64(struct SioPostBattleProc * proc);
void func_fe6_08038DEC(struct SioPostBattleProc * proc);
ProcPtr SioPostBattle_StartMusicProc(struct SioPostBattleProc * parent);
void SioPostBattle_Init(struct SioPostBattleProc * proc);
void SioPostBattle_Loop_Main(struct SioPostBattleProc * proc);
void SioPostBattle_AwaitAPress(ProcPtr proc);
void SioPostBattleMusic_PlayFanfare(struct SioPostBattleMusicProc * proc);
void SioPostBattleMusic_PlayStandardBgm(void);
int func_fe6_080391C0(u8 ranking, u32 player_count, u32 mode, u32 points);
void func_fe6_080392F4(struct SioBatProc * proc);
void func_fe6_08039388(void);
void NewSIOMAIN2(void);
void SIOPRA_BranchAfterMain2(ProcPtr proc);
void func_fe6_080394FC(char const * str, int x, int y, ProcPtr parent);
void SioBat_EndHandler(void);
void SioBat_ReleaseIrq(void);
void func_fe6_08039580(void);
void func_fe6_08039650(struct SioBatProc * proc);
void func_fe6_080397AC(ProcPtr proc);
void func_fe6_080397F4(struct SioBatProc * proc);
void func_fe6_08039A1C(struct SioBatProc * proc);
void func_fe6_08039ABC(struct SioBatProc * proc);
void func_fe6_08039B5C(struct SioBatProc * proc);
void func_fe6_08039C30(struct SioBatProc * proc);
void func_fe6_08039CE0(void);
void func_fe6_08039CFC(struct Unit * unit);
void func_fe6_08039D34(struct SioBatProc * proc);
void func_fe6_08039E04(struct SioBatProc * proc);
void func_fe6_08039F84(struct SioBatProc * proc);
void func_fe6_0803A028(ProcPtr proc);
void func_SioBat_0803A08C(ProcPtr proc);
void XMapTransfer_0803A1E4(void);
void XmapTransfer_End(void);
void SioTerm_Init(struct SioTermProc * proc);
void func_fe6_0803A468(int * cur, u8 bottom, u8 top, int * buf, u8 total);
void func_fe6_0803A4F4(struct SioTermProc * proc);
void func_fe6_0803A570(struct SioTermProc * proc);
void func_fe6_0803A5AC(ProcPtr proc);
void func_fe6_0803A5C8(ProcPtr proc);
void SioTerm_WaitAtMenu(ProcPtr proc);
void func_fe6_0803A604(ProcPtr proc);
void DrawLinkArenaRankIcon(u16 * tm, int rank);
void DrawLinkArenaModeIcon(u16 * tm, int mode);
void DrawLinkArenaRankingRow(struct Text * text, char const * name, u8 rank, u16 points, u8 player_count);
void DrawLinkArenaRankings(void);
void SioResult_Init(struct SioResultProc * proc);
void func_fe6_0803A9FC(struct SioResultProc * proc);
u8 func_fe6_0803AAF8(int value);
void SioResult_NewHS_Init(struct SioResultProc * proc);
void SioResult_NewHS_LoopScroll(struct SioResultProc * proc);
void SioResult_NewHS_AwaitAPress(ProcPtr proc);
void StartSioResultNewHighScore(int value, ProcPtr parent);
void LoadLinkArenaRuleSettings(u8 * buf);
void SaveLinkArenaRuleSettings(u8 * buf);
void func_fe6_0803AED0(int idx, int state);
void SioRuleSettings_Init(struct ProcSioRuleSettings * proc);
void SioRuleSettings_Loop(struct ProcSioRuleSettings * proc);
int func_fe6_0803B248(struct SioMenuProc * proc, int line);
bool SioHaskValidSaveSlot(void);
void SioMenu_Init(void);
void SioMenu_LoadGraphics(struct SioMenuProc * proc);
void SioMenu_0803B45C(struct SioMenuProc * proc);
void SioMenu_0803B508(struct SioMenuProc * proc);
void SioMenu_RestartGraphics(struct SioMenuProc * proc);
void SioMenu_HandleDPadInput(struct SioMenuProc * proc, u8 count);
void SioMenu_Loop_HandleKeyInput(struct SioMenuProc * proc);
void SioMenu_0803B93C(struct SioMenuProc * proc);
void SioMenu_End(struct SioMenuProc * proc);
void StartLinkArenaMainMenu(ProcPtr parent);
bool XMapTransfer_0803BAE0(ProcPtr proc);
void XMapTransfer_0803BBF8(ProcPtr proc);
void XMapTransfer_0803BC18(ProcPtr proc);
bool XMapTransfer_0803BC60(ProcPtr proc);
void PutXMapProgressPercent(struct Text * text, char const * str, int number);
void DrawXMapSendProgress(struct SioBigSendProc * proc);
void DrawXMapReceiveProgress(struct SioBigReceiveProc * proc);
void StartXMapTransfer(ProcPtr proc);
bool XMapTransfer_AwaitCompletion(void);
void XMapTransfer_0803BECC(void);
bool XMapTransfer_0803BEE0(void);
void XMapTransfer_0803BF28(void);
void XmapTransfer_SetDisp(void);
void func_fe6_0803BFB0(struct Proc * proc);
void StartEvent_SioXMapTransfer(ProcPtr parent);
void func_fe6_0803C02C(void);
void func_fe6_0803C044(ProcPtr proc);
void func_fe6_0803C060(ProcPtr proc);
void StartEvent_SioXmap_0803C080(ProcPtr parent);
void func_fe6_0803C094(struct SioRankEntry * buf);
void DrawLinkArenaPointsBox(struct Text * text, int x, int y, int tileref, int number);
void LAPointsBox_LoadBoxes(struct LAPointsBoxProc * proc);
void LAPointsBox_Dummy(void);
void StartLinkArenaPointsBox(void);
void EndLinkArenaPointsBox(void);
void PointsNumberMover_Init(struct PointsNumberMoverProc * proc);
void PointsNumberMover_LoopNumberEmerge(struct PointsNumberMoverProc * proc);
void PointsNumberMover_LoopMoveToPointsBox(struct PointsNumberMoverProc * proc);
void DrawLinkArenaScoreNumber(struct Text * text, int x, int y, int number);
void PointsNumberMover_InitScoreChange(struct PointsNumberMoverProc * proc);
void PointsNumberMover_TickScore(struct PointsNumberMoverProc * proc);
void PointsNumberMover_AwaitEnd(struct PointsNumberMoverProc * proc);
void PointsSpriteText_Init(struct PointsSpriteTextProc * proc);
void PointsSpriteText_LoopIn(struct PointsSpriteTextProc * proc);
void PointsSpriteText_LoopOut(struct PointsSpriteTextProc * proc);
bool NewSioPointsSpriteText(int x, int y, char const * str, u8 flag, ProcPtr parent);
void StartSioPoints1(ProcPtr parent);
void StartSioPoints2(ProcPtr parent);

ProcPtr func_fe6_0804067C(ProcPtr parent, int x, int y);
void UpdateNameEntrySpriteDraw(ProcPtr proc, int x, int y, int len, int kind, int line);
void func_fe6_08040F70(void);
int func_fe6_0803D208(void);
void SioSetUniqueWeapons(struct Unit * unit);
void StartLinkArenaButtonSpriteDraw(int x, int y, ProcPtr parent);
ProcPtr StartLinkArenaVersusSpriteDraw(int x, int y, ProcPtr parent);
void EndLinkArenaButtonSpriteDraw(void);
void EndLinkArenaVersusSpriteDraw(void);
void func_fe6_0803FB08(ProcPtr parent);
void func_fe6_0803CE7C(void);
void func_fe6_0803FC60(void);
void func_fe6_0803FDD8(void);
void func_fe6_08040A80(int x, int y, u8 total, u8 visible, u8 scroll, ProcPtr parent);
ProcPtr func_fe6_0804108C(int x, int y, ProcPtr parent);
void func_fe6_0803CF9C(void);
void func_fe6_0803FE0C(int a, int b);
void func_fe6_0803FE28(int a, int b);
void func_fe6_0803FE48(int idx);
struct SioMenuItemProc * func_fe6_08040014(ProcPtr parent, u8 x, u8 y, u8 index, u8 state);
void func_fe6_08040084(struct SioMenuItemProc * proc, int a, int b, int c, int d);
void func_fe6_08040098(struct SioMenuItemProc * proc, i16 x, i16 y);
ProcPtr func_fe6_08040744(ProcPtr parent);
void func_fe6_08040768(ProcPtr proc, i16 y, i16 x_option, i16 y_option);
ProcPtr func_fe6_0804085C(struct SioMenuItemProc * parent, int x, int y);
void SioMemCpy(u8 const * src, u8 * dst, int size);
void func_fe6_0803CA90(struct Unit * unit);
void func_fe6_0803CAAC(struct Unit * unit);
void func_fe6_0803CAC8(void);
void func_fe6_0803CAD8(int player_id);
void func_fe6_0803CB28(void);
u16 func_fe6_0803CB3C(u8 a, u8 b, u8 c, u8 d);
int func_fe6_0803CB94(u8 unit_id);
void func_fe6_0803CBB4(u8 unit_id, int mu_idx, u8 * idx_out, int * x_out, int * y_out);
void func_fe6_0803CCBC(void);
void func_fe6_0803CCD4(void);
void func_fe6_0803CD74(void);
void func_fe6_0803CDD4(void);
void func_fe6_0803CEDC(void);
void func_fe6_0803CF14(void);
void func_fe6_0803CF58(void);
void func_fe6_0803CF70(void);
void func_fe6_0803EA30(void);
void func_fe6_0803EA44(void);
void func_fe6_0803CFE4(void);
void func_fe6_0803D0A0(void);
void func_fe6_0803D0EC(ProcPtr proc);
void func_fe6_0803D110(ProcPtr parent);
void func_fe6_0803D178(ProcPtr proc);
void func_fe6_0803D2AC(void);
void func_fe6_0803D2CC(u16 keys, i8 flag);
void func_fe6_0803D3C0(void);
bool func_fe6_0803D438(struct Unit * unit);
void func_fe6_0803D478(ProcPtr proc);
void func_fe6_0803D4B8(ProcPtr proc);
void func_fe6_0803D4D0(struct SioBattleMapProc * proc);
void func_fe6_0803D6E0(ProcPtr proc);
void func_fe6_0803D6EC(struct SioBattleMapProc * proc);
void func_fe6_0803D8AC(struct SioAttackProc * proc);
void func_fe6_0803D8FC(struct SioAttackProc * proc);
void func_fe6_0803D93C(struct SioAttackProc * proc);
void func_fe6_0803DA04(struct SioAttackProc * proc);
void func_fe6_0803DAE8(ProcPtr proc);
ProcPtr NewSioWarpFx(struct Unit * unit, struct MuProc * mu, int x, int y, int facing, u8 play_step_se, ProcPtr parent);
void func_fe6_0803DB50(ProcPtr proc);
void func_fe6_0803DB6C(struct SioBattleMapProc * proc);
void func_fe6_0803DC3C(struct SioBattleMapProc * proc);
void func_fe6_0803DCC0(void);
void func_fe6_0803DD30(ProcPtr proc);
void func_fe6_0803DDC0(ProcPtr proc);
void func_fe6_0803DEE0(ProcPtr proc);
void func_fe6_0803E028(void);
void func_fe6_0803E0B4(ProcPtr proc);
void func_fe6_0803E194(void);
void func_fe6_0803E1B0(void);
bool func_fe6_0803E1E8(void * data);
void func_fe6_0803E204(struct SioBattleMapProc * proc);
bool func_fe6_0803E2BC(void * data);
void func_fe6_0803E2D0(struct SioBattleMapProc * proc);
void func_fe6_0803E370(struct Unit * unit, int idx, int * x_out, int * y_out);
bool func_fe6_0803E3B4(void * data);
void func_fe6_0803E3C8(struct SioBattleMapProc * proc);
int func_fe6_0803E4AC(struct Unit * unit);
int func_fe6_0803E514(int unit_base);
void func_fe6_0803E584(struct SioBattleMapProc * proc, int arg);
void func_fe6_0803E5D0(struct SioBattleMapProc * proc);
int func_fe6_0803E630(int unused, struct Unit * unit);
void func_fe6_0803E660(struct SioBattleMapProc * proc);
void func_fe6_0803F5C8(struct MuProc * mu);
void func_fe6_0803E880(ProcPtr proc);
void func_fe6_0803E8B0(struct SioBattleMapProc * proc);
void func_fe6_0803E944(struct SioBattleMapProc * proc);
void func_fe6_0803E964(void);
void func_fe6_0803EA54(ProcPtr proc);
void func_fe6_0803EA74(ProcPtr proc);
void func_fe6_0803EAAC(ProcPtr proc);
void func_fe6_0803EAE0(struct SioBattleMapProc * proc);
void func_fe6_0803EB24(struct SioBattleMapProc * proc);
void func_fe6_0803EBBC(ProcPtr proc);
void func_fe6_0803EBF8(struct SioBattleMapProc * proc);
void func_fe6_0803EC84(ProcPtr proc);
void func_fe6_0803ECA8(struct SioBattleMapProc * proc);
void func_fe6_0803ECD0(struct SioBattleMapProc * proc);
void func_fe6_0803ED54(struct SioBattleMapProc * proc);
void func_fe6_0803ED60(void);
void func_fe6_0803ED74(void);
void func_fe6_0803ED9C(struct SioBattleMapProc * proc);
void func_fe6_0803EDEC(struct SioBattleMapProc * proc);
void func_fe6_0803EE60(ProcPtr proc);
void func_fe6_0803EE7C(void);
void func_fe6_0803EECC(struct SioBattleMapProc * proc);
void func_fe6_0803EF4C(void);
void func_fe6_0803EF9C(void);
void func_fe6_0803EFA8(void);
void func_fe6_0803EFB4(void);
void func_fe6_0803EFEC(void);
void func_fe6_0803F028(void);
void func_fe6_0803F040(void);
void func_fe6_0803F068(i16 * buf, int x_a, int y_a, int x_b, int y_b, int x_c, int y_c, int x_d, int y_d, i16 angle, u16 scale);
void func_fe6_0803F1D8(struct SioWarpWindowProc * proc);
void func_fe6_0803F224(struct SioWarpWindowProc * proc);
void func_fe6_0803F2BC(void);
void func_fe6_0803F304(u16 duration, ProcPtr parent);
void func_fe6_0803F3AC(ProcPtr parent);
void func_fe6_0803F3BC(struct SioWarpWindowProc * proc);
void func_fe6_0803F454(void);
void func_fe6_0803F478(u16 duration, ProcPtr parent);
void func_fe6_0803F504(ProcPtr parent);
void func_fe6_0803F514(ProcPtr proc);
void func_fe6_0803F534(ProcPtr proc);
void func_fe6_0803F554(struct MuProc * mu, int kind);
void func_fe6_0803F5AC(struct SioMuProc * proc);
void func_fe6_0803F648(struct MuProc * mu, int kind);
void func_fe6_0803F694(struct MuProc * mu);
void func_fe6_0803F6C8(struct SioWarpProc * proc);
void func_fe6_0803F714(struct SioWarpProc * proc);
void func_fe6_0803F7E4(void);
void NewSioWarp(struct SioWarpProc * parent);
void SioWarpFx_0803F850(struct SioWarpProc * proc);
void SioWarpFx_HideMoveUnit(struct SioWarpProc * proc);
void SioWarpFx_SetMUPosition(struct SioWarpProc * proc);
void SioWarpFx_ShowMoveUnit(struct SioWarpProc * proc);
void SioWarpFx_0803F8B0(struct SioWarpProc * proc);
void SioWarpFx_AwaitSioWarp(ProcPtr proc);
ProcPtr NewSioWarpFxPartial(struct Unit * unit, struct MuProc * mu, int x, int y, int facing, u8 play_step_se, ProcPtr parent);
void PutLinkArenaButtonSpriteAt(int x, int y);
void LAButtonSprites_Loop(struct SioSpriteDrawProc * proc);
void SioCopyVRAM(u8 const * src, u8 * dst, int width, int height);
void func_fe6_0803FBC4(struct LinkArenaTitleBannerProc * proc);
void func_fe6_0803FC1C(void);
void func_fe6_0803FC70(void);
void func_fe6_0803FCBC(struct SioScrollingTextProc * proc);
void func_fe6_0803FE64(u8 idx);
void func_fe6_0803FEB4(struct SioMenuItemProc * proc);
void func_fe6_080400A0(void);
void func_fe6_080400FC(void);
void func_fe6_08040154(struct SioProc85AAA78 * proc);
void func_fe6_08040468(struct LATeamSpriteDrawProc * proc);
void func_fe6_080404E8(int x, int y, int y_max, int y_min, int count, ProcPtr parent);
void func_fe6_0804054C(void);
void func_fe6_080405A0(struct NameEntrySpriteDrawProc * proc);
void func_fe6_080406D0(struct RuleSettingSpriteDrawProc * proc);
void func_fe6_08040770(int idx);
void func_fe6_080407A8(struct SioMenuBurstFxProc * proc);
void func_fe6_08040880(struct LAMenuScrollBarProc * proc);
void func_fe6_080408BC(struct LAMenuScrollBarProc * proc);
void func_fe6_08040B44(void);
void func_fe6_08040C00(void);
void func_fe6_08040C7C(void);
void SioSetUniqueWeaponUnbreakable(struct Unit * unit, int item_slot);
void LAVersusSpriteDraw_Flashing(void);
void LAVersusSpriteDraw_Loop(struct SioBatProc_Unk2C * proc);
ProcPtr GetLinkArenaVersusSpriteDraw(void);
void func_fe6_08040FC0(void);
void func_fe6_08041014(void);
void func_fe6_08041060(struct SioSpriteDrawProc * proc);
fu8 SioAttackItemMenu_Usability(struct MenuEntInfo const * info, int id);
fu8 SioAttackItemMenu_Effect(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_08041188(struct MenuProc * menu, struct MenuEntProc * ent);
u32 SioAttackItemMenu_OnDraw(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_08041200(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_08041210(struct MenuProc * menu, struct MenuEntProc * ent);
