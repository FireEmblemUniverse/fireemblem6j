#pragma once

#include "prelude.h"
#include "proc.h"

enum OpInfoModeIndex {
	OPINFO_STATE_0,
	OPINFO_STATE_IDLE,
	OPINFO_STATE_2,
	OPINFO_STATE_3,
};

enum class_demo_set {
	CLASSDEMO_SET0,
	CLASSDEMO_SET1,
	CLASSDEMO_SET2,
	CLASSDEMO_SET3,
	CLASSDEMO_SET4,
	CLASSDEMO_SET5,
	CLASSDEMO_SET6,
};

struct ClassDemoData {
	STRUCT_PAD(0x00, 0x2C);

	u8 jids_2C[5];
	u8 jids_31[8];
};

enum OpInfoProcLabel {
	PL_OPINFO_BRANMCH = 1,
	PL_OPINFO_IDLE = 2,
	PL_OPINFO_NAME_INTRO = 4,
	PL_OPINFO_END_TITLE = 5,
	PL_OPINFO_END_EXT = 6,
};

struct ProcOpInfo {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x2A);

	/* 2A */ u16 fade_speed;
	/* 2C */ u8 mode;
	/* 2D */ u8 class_set;
	/* 2E */ u8 unk_2E;
	/* 2F */ u8 unk_2F;
	/* 30 */ u8 unk_30;
	/* 31 */ u8 unk_31, unk_32;

	/* 34 */ ProcPtr subproc1;
	/* 38 */ ProcPtr anim_proc;
	/* 3C */ int proc_run_time;
	/* 40 */ int proc_start_time;
};

void OpInfo_Init(struct ProcOpInfo *proc);
void OpInfo_Branch(struct ProcOpInfo *proc);
void OpInfo_PostAnim(struct ProcOpInfo *proc);
void OpInfo_Idle(struct ProcOpInfo *proc);
void OpInfo_FadeBgmOut(struct ProcOpInfo *proc);
void OpInfo_EndSubProcs(struct ProcOpInfo *proc);
void OpInfo_End(struct ProcOpInfo *proc);
void StartClassDemo(u8 arg_0, ProcPtr parent);

struct ProcOpInfoFadeOut {
	PROC_HEADER;

	/* 2A */ u16 speed;
};

void OpInfoFadeOut_Sync(struct ProcOpInfoFadeOut *proc);
void OpInfo_FadeOut(u8 speed);

void PutOpInfoViewLetter(u16 char_base, u8 char_index, int x, int y, u16 x_scale, u16 y_scale, u8 pal_off);

struct ProcOpInfoEnter {
	PROC_HEADER;

	/* 2A */ u16 timer;
	/* 2C */ u16 x;
	/* 2E */ u8 letter_count;
	/* 2F */ u8 sprite_base;
	/* 30 */ u8 class_index;
	/* 34 */ ProcPtr letter_procs[10];
	/* 5C */ ProcPtr icon_proc;
	/* 60 */ struct ProcOpInfo *opinfo;
};

struct ProcOpInfoView {
	PROC_HEADER;

	/* 2A */ u16 timer;
	/* 2C */ u16 sprite_base;
	/* 2E */ u8 index;
	/* 30 */ u16 x;
};

struct ProcOpInfoIcon {
	PROC_HEADER;

	/* 2A */ u16 timer;
	/* 2C */ u8 class_index;
	/* 2D */ u8 icon_count;
	/* 2E */ u8 icon_bits;
};

void OpInfoEnter_Init(struct ProcOpInfoEnter *proc);
void func_fe6_08094B28(struct ProcOpInfoEnter *proc);
void OpInfoEnter_Loop_In(struct ProcOpInfoEnter *proc);
void OpInfoEnter_Loop_Out(struct ProcOpInfoEnter *proc);
void OpInfoEnter_OnEnd(struct ProcOpInfoEnter *proc);
ProcPtr NewOpInfoEnter(struct ProcOpInfo *parent, u8 class_index);
void OpInfoView_Init(struct ProcOpInfoView *proc);
void OpInfoView_Loop_FadeIn(struct ProcOpInfoView *proc);
void OpInfoView_Loop_Display(struct ProcOpInfoView *proc);
void OpInfoView_Loop_FadeOut(struct ProcOpInfoView *proc);
ProcPtr NewOpInfoView(struct ProcOpInfoEnter *parent, u8 index);
void func_fe6_08094F08(void);
void OpInfoIcon_Init(struct ProcOpInfoIcon *proc);
void func_fe6_08094F94(u8 len, u8 flag);
void func_fe6_08095034(u8 fade, u8 count, u8 bits);
void OpInfoIcon_Loop_FadeIn(struct ProcOpInfoIcon *proc);
void OpInfoIcon_LoopA(struct ProcOpInfoIcon *proc);
void OpInfoIcon_LoopB(struct ProcOpInfoIcon *proc);
void OpInfoIcon_Loop_FadeOut(struct ProcOpInfoIcon *proc);
ProcPtr NewOpInfoIcon(struct ProcOpInfoEnter *parent, u8 class_index);

struct ProcClassDemoStatus;

struct ProcClassDemoMain {
	PROC_HEADER;

	/* 2A */ u16 frame_timer;
	/* 2C */ u16 total_timer;
	/* 2E */ u16 ctrl_index;
	/* 30 */ u8 round_type;
	/* 31 */ u8 index;
	/* 34 */ struct ProcOpInfo *opinfo;
	/* 38 */ u8 unit_status[6];
	/* 3E */ u8 unk_3E;
	/* 40 */ struct ProcClassDemoStatus *procfx;
	/* 44 */ u8 anim_x;
};

struct ProcClassDemoStatus {
	PROC_HEADER;

	/* 2A */ u16 timer;

	STRUCT_PAD(0x2C, 0x30);

	/* 30 */ struct ProcClassDemoMain *gauge;
	/* 34 */ u8 ch_pos[14];
	/* 42 */ u8 unk_42;
	/* 43 */ u8 unk_43;
};

void HBlank_ClassDemoMain(void);
void OpInfo_EfxmagicMiniCallBack(void);
void ClassDemoMain_ExecEkrMainMini(struct ProcClassDemoMain *proc);
void ClassDemoMain_Loop_Intro(struct ProcClassDemoMain *proc);
void ClassDemoMain_Loop_Main(struct ProcClassDemoMain *proc);
void ClassDemoMain_Block(struct ProcClassDemoMain *proc);
void ClassDemoMain_OnEnd(struct ProcClassDemoMain *proc);

ProcPtr StartClassAnimDisplay(struct ProcOpInfo *proc, u8 index);
void ClassDemoStatus_Init(struct ProcClassDemoStatus *proc);
void ClassDemoStatus_Loop(struct ProcClassDemoStatus *proc);
void func_fe6_08095D28(void);
ProcPtr StartClassDemoStatus(ProcPtr parent);
void SetOpClassDemoStatusPos(struct ProcClassDemoStatus *proc, int pos);
void func_fe6_08095D48(ProcPtr unused);
void func_fe6_08095D58(void);

extern EWRAM_OVERLAY(opinfo) struct EkrMainMiniDesc OpEkrMiniDesc;
extern EWRAM_OVERLAY(opinfo) u16 OpEkrMini_ImgBuf[0x1000];
extern EWRAM_OVERLAY(opinfo) u16 OpEkrMini_OamBuf[0x2C00];
extern EWRAM_OVERLAY(opinfo) u16 OpEkrMini_PalBuf[0x50];
extern EWRAM_OVERLAY(opinfo) u8  OpEkrMini_ScrBuf[0x2A00];
extern EWRAM_OVERLAY(opinfo) struct EfxopMagicDesc OpEkrMagiDesc;
extern EWRAM_OVERLAY(opinfo) u8 OpEkrMagi_BgImgBuf[0x2000];
extern EWRAM_OVERLAY(opinfo) u8 OpEkrMagi_BgTsaBuf[0x800];
extern EWRAM_OVERLAY(opinfo) u8 OpEkrMagi_ObImgBuf[0x1000];
extern EWRAM_OVERLAY(opinfo) struct EkrTerrainfxDesc OpEkrTerrainDesc;
extern EWRAM_OVERLAY(opinfo) u8 OpEkrTerrain_ImgBuf[0x2000];
extern EWRAM_OVERLAY(opinfo) struct Text OpClassDemoTexts[6];
struct OpClassDemoCharPos {
	/* 00 */ u8 x, y;
	STRUCT_PAD(0x02, 0x04);
};

extern EWRAM_OVERLAY(opinfo) struct OpClassDemoCharPos OpClassDemoCharPositions[14];

extern CONST_DATA struct ProcScr ProcScr_OpInfo[];
extern CONST_DATA struct ProcScr ProcScr_OpInfoFadeOut[];
extern CONST_DATA struct ProcScr ProcScr_OpInfoEnter[];
extern CONST_DATA struct ProcScr ProcScr_OpInfoView[];
extern CONST_DATA struct ProcScr ProcScr_OpInfoIcon[];
extern CONST_DATA struct ProcScr ProcScr_ClassDemoMain[];
extern CONST_DATA struct ProcScr ProcScr_ClassDemoStatus[];
extern CONST_DATA u16 *Sprites_OpInfo_0869006C[];
extern CONST_DATA u16 *Sprites_OpInfo_086900BC[];
extern CONST_DATA u16 Sprite_OpInfo_086900DC[];
extern CONST_DATA u16 Sprite_OpInfo_086900F0[];
extern CONST_DATA u16 Sprite_OpInfo_086900F8[];
extern CONST_DATA u16 Sprite_OpInfo_08690100[];
extern CONST_DATA u16 *Sprites_OpInfo_08690288[];
extern CONST_DATA u8 gUnk_0869056C[][4];
extern CONST_DATA u8 OpClassDemo_BIDs[];
extern CONST_DATA u16 OpClassDemo_IntroMsgs[];

struct OpClassDemoBanimCtrl {
	u8 round_type;
	u8 duration;
	u16 unk_02;
};

extern struct OpClassDemoBanimCtrl gOpClassDemoBanimCtrl[];

struct OpEkrMagiConf {
	i8 efxmagi_id;
	i8 x_bg, y_bg;
	i8 x_ob, y_ob;
};
// extern CONST_DATA struct OpEkrMagiConf OpClassDemo_MagiConfig[];
extern CONST_DATA i8 OpClassDemo_MagiConfig[35 * 5];

extern CONST_DATA u8 OpClassDemo_TerrainConfig[35][2];
extern CONST_DATA u8 OpClassDemo_JidConfig[35];

struct ClassDisplayFont {
	u16 *sprite;
	i8 ch;
	i8 x_start, width, c;
};

extern CONST_DATA struct ClassDisplayFont gClassDisplayFont1[];
extern i8 const * CONST_DATA gClassDemoNames[];
