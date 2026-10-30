#pragma once

#include "prelude.h"
#include "proc.h"

extern IWRAM_DATA u8 gOpAnimTextMask[4];
extern IWRAM_DATA bool bool_opanim_03005284;
extern IWRAM_DATA u8 Pad_Common_03005285[11];
extern IWRAM_DATA int gOpAnimStep[8];

extern EWRAM_OVERLAY(opanim) u8 OpAnimGlyphBuffer[0x2800];
extern EWRAM_OVERLAY(opanim) int OpAnimGlyphIndex;
extern EWRAM_OVERLAY(opanim) u8 gOpAnimBgTmBuf[0x2000];

void StartOpAnim_unused(void);
void OpAnimfxTerminator_Loop(ProcPtr proc);
void OpAnim_ResetDispIO(void);
void OpAnim_OnEnd(void);
void OpAnim_Init(void);
void func_fe6_080988BC(void);
void OpAnim6_ResetBG(void);
void OpAnim_SetWin0Layers(int arg_0, int arg_1, int arg_2, int arg_3, int arg_4);
void OpAnim_StartBGM(void);

struct ProcOpAnimTimer {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x54);
	u32 timer;
};

void OpAnim_StartTimer(ProcPtr proc);
void OpAnimTimer_Init(struct ProcOpAnimTimer *proc);
void OpAnimTimer_Loop(struct ProcOpAnimTimer *proc);
void OpAnimAdvance(void);
void PutOpAnimSubtitle0(void);
void PutOpAnimSubtitle1(void);
void PutOpAnimSubtitle2(void);
void PutOpAnimSubtitle3(void);
void PutOpAnimSubtitle4(void);
void PutOpAnimSubtitle5(void);
void PutOpAnimSubtitle6(void);
void PutOpAnimSubtitle7(void);
void OpAnim_SetupGlyph(int pal_id);
void OpAnim_PutSubtitle(int idx);

struct ProcOpAnimText {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x2C);

	/* 2C */ int x_center;
	/* 30 */ int unk_30;

	STRUCT_PAD(0x34, 0x44);

	/* 44 */ i16 delay_timer;

	STRUCT_PAD(0x46, 0x4A);

	/* 4A */ u16 unk_4A;
	/* 4C */ const char *str;

	STRUCT_PAD(0x50, 0x54);

	/* 54 */ int index;
	/* 58 */ int unk_58;

	STRUCT_PAD(0x5C, 0x64);

	/* 64 */ i16 unk_64;
};

void NewOpAnimSubtitleDisp(int idx, int a, int b, const char *str);
void OpAnimSubtitleDisp_Init(struct ProcOpAnimText *proc);
void OpAnimSubtitleDisp_Wait(struct ProcOpAnimText *proc);
void OpAnimSubtitleDisp_Setup(struct ProcOpAnimText *proc);
void OpAnimSubtitleDisp_Loop(struct ProcOpAnimText *proc);
void func_fe6_08098C90(void);
void RemoveOpAnimText(void);
void func_fe6_08098CC0(struct ProcOpAnimText *proc);
void func_fe6_08098D10(struct ProcOpAnimText *proc);
void func_fe6_08098DB0(struct ProcOpAnimText *proc);
void func_fe6_08098DEC(struct ProcOpAnimText *proc);
void func_fe6_08098E74(struct ProcOpAnimText *proc);
void func_fe6_08098EC8(struct ProcOpAnimText *proc);
void OpAnimText_Init1(struct ProcOpAnimText *proc);
void func_fe6_08098FA8(struct ProcOpAnimText *proc);
void OpAnimText_Loop1(struct ProcOpAnimText *proc);
void OpAnimText_Init2(struct ProcOpAnimText *proc);
void OpAnimText_Loop2(struct ProcOpAnimText *proc);
void func_fe6_080990FC(struct ProcOpAnimText *proc);
void func_fe6_08099194(struct ProcOpAnimText *proc);
void func_fe6_080992B8(void);
void func_fe6_080992D0(struct ProcOpAnimText *proc);
int GetOpAnimTextIndex(const char *str);
int GetOpAnimTextChLength(const char *str);
int GetOpAnimTextStrLength(const char *str);
const char *GetOpAnimTextPrNext(const char *str);
void ResetOpAnimTextIndexMask(void);
int GetNextOpAnimTextIndex(void);
void ClearOpAnimTextIndex(int index);
void PutImg_OpAnimGlyphs(void);
void func_fe6_08099424(int);
int func_fe6_0809947C(int index, int speed, ProcPtr parent);
int func_fe6_08099520(ProcPtr proc);

struct ProcOpAnimGlyphFallIn {
	PROC_HEADER;

	/* 2C */ const void *src;
	/* 30 */ void *dst;
	/* 34 */ int step;
	/* 38 */ u16 unk_38;
	/* 3A */ u16 unk3A, speed;
};
void OpAnimGlyphFallIn_Init(struct ProcOpAnimGlyphFallIn *proc);
void OpAnimGlyphFallIn_Loop(struct ProcOpAnimGlyphFallIn *proc);
void func_fe6_08099580(const u32 *src, u32 *dst, int index);
void OpAnimTextPutGlyph(const void *src, void *dst, int index);
struct ProcOpAnim5 {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x64);

	i16 unk_64;
	i16 unk_66;
};

struct ProcOpAnimBgScroll {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x2A);

	/* 2A */ u16 bg_off[4];

	STRUCT_PAD(0x32, 0x34);

	/* 34 */ i16 timer;
};

struct ProcOpAnimSprite {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x50);

	/* 50 */ struct SpriteAnim *anim;

	STRUCT_PAD(0x54, 0x64);

	/* 64 */ i16 unk_64;
};

struct ProcOpAnim4 {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x30);

	/* 30 */ int y;

	STRUCT_PAD(0x34, 0x44);

	/* 44 */ i16 timer;

	STRUCT_PAD(0x46, 0x50);

	/* 50 */ struct SpriteAnim *anim;

	STRUCT_PAD(0x54, 0x64);

	/* 64 */ i16 unk_64;
};

struct ProcOpAnim6 {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x44);

	i16 unk_44;

	STRUCT_PAD(0x46, 0x64);

	i16 unk_64;
};

struct ProcOpAnimSparksFall {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x2A);

	/* 2A */ i16 x;
	/* 2C */ i16 y;
	/* 2E */ u8 dx;
	/* 2F */ u8 dy;
	/* 30 */ u8 type;
	/* 31 */ u8 phase;
	/* 32 */ u16 timer;
};

struct ProcOpAnim3Zoom {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x2C);

	/* 2C */ int x;
	/* 30 */ int y;

	STRUCT_PAD(0x34, 0x44);

	/* 44 */ i16 timer2;

	STRUCT_PAD(0x46, 0x54);

	/* 54 */ int zoom;
	/* 58 */ int unk_58;

	STRUCT_PAD(0x5C, 0x64);

	/* 64 */ i16 timer;
};

void func_fe6_08099644(void);
void OpAnim1_Init(ProcPtr proc);
void func_fe6_08099738(ProcPtr proc);
void func_fe6_08099750(ProcPtr proc);
void func_fe6_08099768(ProcPtr proc);
void func_fe6_08099784(ProcPtr proc);
void func_fe6_08099794(struct Proc *proc);
void func_fe6_0809979C(struct Proc *proc);
void func_fe6_0809980C(struct ProcOpAnimBgScroll *proc);
void func_fe6_08099824(struct ProcOpAnimBgScroll *proc);
void func_fe6_08099868(struct ProcOpAnimBgScroll *proc);
void func_fe6_080998D4(const u16 *tsa, u16 *tm, int a, int b);
void func_fe6_0809992C(int bg, int x);
void func_fe6_0809997C(ProcPtr proc);
void func_fe6_08099A2C(ProcPtr proc);
void func_fe6_08099A84(struct ProcOpAnimSprite *proc);
void func_fe6_08099A90(struct ProcOpAnimSprite *proc);
void func_fe6_08099AD0(struct ProcOpAnimSprite *proc);
void func_fe6_08099B18(struct ProcOpAnimSprite *proc);
void func_fe6_08099B34(struct ProcOpAnim5 *proc);
void func_fe6_08099B44(struct ProcOpAnim5 *proc);
void func_fe6_08099B5C(struct ProcOpAnim5 *proc);
void func_fe6_08099BA8(int offset);
int func_fe6_08099BCC(void);
void func_fe6_08099BE4(void);
void func_fe6_08099CCC(void);
void func_fe6_08099D3C(ProcPtr proc);
void func_fe6_08099DA4(ProcPtr proc);
void func_fe6_08099E50(ProcPtr proc);
void func_fe6_08099EC0(ProcPtr proc);
void func_fe6_08099F98(void);
void func_fe6_08099F9C(struct ProcOpAnim4 *proc);
void func_fe6_08099FA8(struct ProcOpAnim4 *proc);
void func_fe6_08099FD0(struct ProcOpAnim4 *proc);
void func_fe6_0809A014(struct ProcOpAnim4 *proc);
void func_fe6_0809A034(struct ProcOpAnim4 *proc);
void func_fe6_0809A048(struct ProcOpAnim4 *proc);
void func_fe6_0809A068(struct ProcOpAnim4 *proc);
void func_fe6_0809A0A8(struct ProcOpAnim4 *proc);
void OpAnimSparksOBJ_Init(struct ProcOpAnim5 *proc);
void OpAnimSparksOBJ_Loop(struct ProcOpAnim5 *proc);
void PutOpAnimSparksObjGfx(void);
void func_fe6_0809A13C(ProcPtr proc);
void OpAnimSparksOBJFALL_Init(struct ProcOpAnimSparksFall *proc);
void OpAnimSparksOBJFALL_Loop(struct ProcOpAnimSparksFall *proc);
void func_fe6_0809A264(struct ProcOpAnim5 *proc);
void func_fe6_0809A26C(struct ProcOpAnim5 *proc);
void func_fe6_0809A2CC(ProcPtr proc);
void func_fe6_0809A3A4(struct ProcOpAnim5 *proc);
void func_fe6_0809A3D4(struct ProcOpAnim5 *proc);
void func_fe6_0809A484(struct ProcOpAnim6 *proc);
void func_fe6_0809A4C4(struct ProcOpAnim6 *proc);
void func_fe6_0809A53C(struct ProcOpAnim6 *proc);
void func_fe6_0809A564(struct ProcOpAnim6 *proc);
void func_fe6_0809A588(struct ProcOpAnim6 *proc);
void func_fe6_0809A600(struct ProcOpAnim6 *proc);
void func_fe6_0809A638(struct ProcOpAnim6 *proc);
void func_fe6_0809A6DC(struct ProcOpAnim3Zoom *proc);
void func_fe6_0809A6E4(struct ProcOpAnim3Zoom *proc);
void func_fe6_0809A804(struct ProcOpAnim3Zoom *proc);
void func_fe6_0809A80C(struct ProcOpAnim3Zoom *proc);
void func_fe6_0809A868(int x, int y, int zoom, int unk);
void func_fe6_0809A8A4(struct ProcOpAnim5 *proc);
void func_fe6_0809A8B4(struct ProcOpAnim5 *proc);
void func_fe6_0809A900(void);

void OpAnim_PutThunderStormGfx(void);
void func_fe6_0809AA20(int a, int b);
void OpAnim6_StartBGM(struct ProcOpAnim6 *proc);
void OpAnim6_PutThunderStormGfx(struct ProcOpAnim6 *proc);
void OpAnim6_StartThunderStorm(struct ProcOpAnim6 *proc);
void OpAnimThunderStorm_Init(struct ProcOpAnim6 *proc);
void OpAnimThunderStorm_PutPal1(struct ProcOpAnim6 *proc);
void OpAnimThunderStorm_PutPal2(struct ProcOpAnim6 *proc);
void OpAnimThunderStorm_PutPal3(struct ProcOpAnim6 *proc);
void OpAnimThunderStorm_PutPal4(struct ProcOpAnim6 *proc);
void OpAnimThunderStorm_PutPal5(struct ProcOpAnim6 *proc);
void OpAnim6_PutIdunnGfx(struct ProcOpAnim6 *proc);
void func_fe6_0809AD3C(struct ProcOpAnim6 *proc);
void func_fe6_0809AD64(struct ProcOpAnim6 *proc);

void func_fe6_0809AD88(ProcPtr proc);
void func_fe6_0809ADCC(ProcPtr proc);
void func_fe6_0809AE60(ProcPtr proc);
void func_fe6_0809AEA0(void);
void func_fe6_0809AEC4(void);
void func_fe6_0809AED4(void);
void func_fe6_0809AF30(ProcPtr proc);
void func_fe6_0809AF74(struct ProcOpAnim5 *proc);
void func_fe6_0809AF84(struct ProcOpAnim5 *proc);
void func_fe6_0809AFE4(struct ProcOpAnim5 *proc);
void func_fe6_0809B01C(struct ProcOpAnim5 *proc);
void func_fe6_0809B024(struct ProcOpAnim5 *proc);
void func_fe6_0809B094(struct ProcOpAnim5 *proc);
void func_fe6_0809B0A4(struct ProcOpAnim5 *proc);
void func_fe6_0809B0E8(void);
void func_fe6_0809B188(void);
void func_fe6_0809B220(u16 *tm, u16 tileref, int width, int height);
void func_fe6_0809B280(ProcPtr proc);

extern CONST_DATA struct ProcScr ProcScr_TitleScreenHandler[];
extern CONST_DATA struct ProcScr ProcScr_OpAnim[];
extern u16 CONST_DATA BgConf_OpAnim_08691604[];
extern u16 CONST_DATA BgConf_OpAnim_0869161C[];
extern CONST_DATA struct ProcScr ProcScr_OpAnimTimer[];
extern CONST_DATA char OpAnimTextRef[];
extern CONST_DATA u8 OpAnimTextLenRef[];
extern CONST_DATA int Msgs_OpAnim_08691738[];

struct OpAnimSubtitleConf {
	u16 unk_00;
	u16 unk_02;
	u16 unk_04;

	STRUCT_PAD(0x6, 0x8);

	u16 *unk_08;
};
extern CONST_DATA struct OpAnimSubtitleConf gOpAnimSubtitleConf[];

extern CONST_DATA struct ProcScr ProcScr_OpAnimSubtitleDisp[];
extern CONST_DATA struct ProcScr ProcScr_Unk_08691810[];
extern CONST_DATA struct ProcScr ProcScr_Unk_08691828[];
extern CONST_DATA struct ProcScr ProcScr_Unk_08691840[];
extern CONST_DATA struct ProcScr ProcScr_OpAnimText[];
extern CONST_DATA struct ProcScr ProcScr_OpAnimGlyphFallIn[];
extern CONST_DATA u16 gUnk_086918B0[];
extern CONST_DATA struct ProcScr ProcScr_OpAnim1[];
extern CONST_DATA struct ProcScr ProcScr_Unk_086919D0[];
extern CONST_DATA struct ProcScr ProcScr_Unk_086919E8[];
extern CONST_DATA struct ProcScr ProcScr_OpAnim2[];
extern CONST_DATA struct ProcScr ProcScr_Unk_08691AC0[];
extern CONST_DATA struct ProcScr ProcScr_OpAnim_08691B20[];
extern u16 CONST_DATA BgConf_OpAnim_08691B38[];
extern u16 CONST_DATA BgConf_OpAnim_08691B50[];
extern CONST_DATA struct ProcScr ProcScr_OpAnim4[];
extern CONST_DATA struct ProcScr ProcScr_Unk_08691C38[];
extern CONST_DATA struct ProcScr ProcScr_Unk_08691C58[];
extern CONST_DATA u8 gUnk_08691C78[];
extern CONST_DATA struct ProcScr ProcScr_OpAnimSparksOBJ[];
extern CONST_DATA struct ProcScr ProcScr_OpAnimSparksOBJFALL[];
extern CONST_DATA struct ProcScr ProcScr_OpAnim_08691CC0[];
extern CONST_DATA struct ProcScr ProcScr_OpAnim3[];
extern CONST_DATA struct ProcScr ProcScr_Unk_08691D70[];
extern CONST_DATA struct ProcScr ProcScr_Unk_08691D88[];
extern CONST_DATA struct ProcScr ProcScr_Unk_08691DB8[];
extern CONST_DATA struct ProcScr ProcScr_OpAnim_08691DE8[];
extern u16 CONST_DATA BgConf_OpAnim_08691DF8[];

struct OpAnim_08691E10 {
	u8 unk_00;
	u8 tileref;
	i8 unk_02;
	u8 _pad_;
};
extern CONST_DATA struct OpAnim_08691E10 OpAnim_08691E10[];

struct OpAnim_08691E30 {
	u8 unk_00;
	u8 tileref;
	u16 unk_02;
};
extern CONST_DATA struct OpAnim_08691E30 OpAnim_08691E30[];

extern CONST_DATA struct ProcScr ProcScr_OpAnim6[];
extern CONST_DATA struct ProcScr ProcScr_OpAnimThunderStorm[];
extern CONST_DATA struct ProcScr ProcScr_OpAnim5[];
extern CONST_DATA struct ProcScr ProcScr_Unk_08691FF8[];
extern CONST_DATA struct ProcScr ProcScr_Unk_08692060[];
extern CONST_DATA struct ProcScr ProcScr_Unk_08692090[];
extern u16 CONST_DATA BgConf_OpAnim_086920A0[];
extern u16 CONST_DATA BgConf_OpAnim_086920B8[];
extern CONST_DATA struct ProcScr ProcScr_OpAnim_Nintendo[];
extern CONST_DATA int gTitleDuration;
extern CONST_DATA int gUnk_0869211C;
extern CONST_DATA int gUnk_08692120;
extern CONST_DATA int gUnk_08692124;
extern CONST_DATA int gUnk_08692128;
extern CONST_DATA int gUnk_0869212C;
extern CONST_DATA struct ProcScr ProcScr_TitleScreenFromOp[];
