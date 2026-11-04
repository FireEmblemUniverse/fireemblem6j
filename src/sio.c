#include "prelude.h"
#include "proc.h"
#include "armfunc.h"
#include "msg.h"
#include "ui.h"
#include "util.h"
#include "unitsprite.h"
#include "sound.h"
#include "unitlistscreen.h"
#include "secretscreen.h"
#include "faction.h"
#include "sprite.h"
#include "oam.h"
#include "talk.h"
#include "random.h"
#include "helpbox.h"
#include "prepscreen.h"
#include "sioerror.h"
#include "bmio.h"
#include "debugmenu.h"
#include "statscreen.h"
#include "save_core.h"
#include "save_xmap.h"
#include "sio_core.h"
#include "sio.h"

#include "constants/iids.h"
#include "constants/songs.h"
#include "constants/msg.h"
#include "constants/faces.h"

struct TacticianTextConf const gTacticianTextConf[] = {
	{ { { "", "", "" }, { "", "", "" }, { "", "", "" } }, 0, 0, 0, { 0, 0, 0, 0 }, 0 },
	{ { { "　", "", "" }, { "　", "", "" }, { "　", "", "" } }, 202, 72, 1, { 5, 2, 60, 6 }, 1 },
	{ { { "　", "", "" }, { "　", "", "" }, { "　", "", "" } }, 202, 88, 1, { 1, 3, 65, 11 }, 2 },
	{ { { "　", "", "" }, { "　", "", "" }, { "　", "", "" } }, 202, 104, 1, { 2, 4, 70, 16 }, 3 },
	{ { { "　", "", "" }, { "　", "", "" }, { "　", "", "" } }, 202, 120, 1, { 3, 5, 75, 21 }, 4 },
	{ { { "　", "", "" }, { "　", "", "" }, { "　", "", "" } }, 202, 136, 1, { 4, 1, 80, 26 }, 5 },
	{ { { "あ", "", "" }, { "ア", "", "" }, { "Ａ", "", "" } }, 16, 72, 0, { 26, 11, 1, 7 }, 0 },
	{ { { "い", "", "" }, { "イ", "", "" }, { "Ｂ", "", "" } }, 26, 72, 0, { 27, 12, 6, 8 }, 0 },
	{ { { "う", "", "" }, { "ウ", "", "" }, { "Ｃ", "", "" } }, 36, 72, 0, { 28, 13, 7, 9 }, 0 },
	{ { { "え", "", "" }, { "エ", "", "" }, { "Ｄ", "", "" } }, 46, 72, 0, { 29, 14, 8, 10 }, 0 },
	{ { { "お", "", "" }, { "オ", "", "" }, { "Ｅ", "", "" } }, 56, 72, 0, { 30, 15, 9, 31 }, 0 },
	{ { { "か", "が", "" }, { "カ", "ガ", "" }, { "Ｋ", "", "" } }, 16, 88, 0, { 6, 16, 2, 12 }, 0 },
	{ { { "き", "ぎ", "" }, { "キ", "ギ", "" }, { "Ｌ", "", "" } }, 26, 88, 0, { 7, 17, 11, 13 }, 0 },
	{ { { "く", "ぐ", "" }, { "ク", "グ", "" }, { "Ｍ", "", "" } }, 36, 88, 0, { 8, 18, 12, 14 }, 0 },
	{ { { "け", "げ", "" }, { "ケ", "ゲ", "" }, { "Ｎ", "", "" } }, 46, 88, 0, { 9, 19, 13, 15 }, 0 },
	{ { { "こ", "ご", "" }, { "コ", "ゴ", "" }, { "Ｏ", "", "" } }, 56, 88, 0, { 10, 20, 14, 36 }, 0 },
	{ { { "さ", "ざ", "" }, { "サ", "ザ", "" }, { "Ｕ", "", "" } }, 16, 104, 0, { 11, 21, 3, 17 }, 0 },
	{ { { "し", "じ", "" }, { "シ", "ジ", "" }, { "Ｖ", "", "" } }, 26, 104, 0, { 12, 22, 16, 18 }, 0 },
	{ { { "す", "ず", "" }, { "ス", "ズ", "" }, { "Ｗ", "", "" } }, 36, 104, 0, { 13, 23, 17, 19 }, 0 },
	{ { { "せ", "ぜ", "" }, { "セ", "ゼ", "" }, { "Ｘ", "", "" } }, 46, 104, 0, { 14, 24, 18, 20 }, 0 },
	{ { { "そ", "ぞ", "" }, { "\x83\x5C", "ゾ", "" }, { "Ｙ", "", "" } }, 56, 104, 0, { 15, 25, 19, 41 }, 0 },
	{ { { "た", "だ", "" }, { "タ", "ダ", "" }, { "０", "", "" } }, 16, 120, 0, { 16, 26, 4, 22 }, 0 },
	{ { { "ち", "ぢ", "" }, { "チ", "ヂ", "" }, { "１", "", "" } }, 26, 120, 0, { 17, 27, 21, 23 }, 0 },
	{ { { "つ", "づ", "" }, { "ツ", "ヅ", "" }, { "２", "", "" } }, 36, 120, 0, { 18, 28, 22, 24 }, 0 },
	{ { { "て", "で", "" }, { "テ", "デ", "" }, { "３", "", "" } }, 46, 120, 0, { 19, 29, 23, 25 }, 0 },
	{ { { "と", "ど", "" }, { "ト", "ド", "" }, { "４", "", "" } }, 56, 120, 0, { 20, 30, 24, 46 }, 0 },
	{ { { "な", "", "" }, { "ナ", "", "" }, { "", "", "" } }, 16, 136, 0, { 21, 6, 5, 27 }, 0 },
	{ { { "に", "", "" }, { "ニ", "", "" }, { "", "", "" } }, 26, 136, 0, { 22, 7, 26, 28 }, 0 },
	{ { { "ぬ", "", "" }, { "ヌ", "", "" }, { "", "", "" } }, 36, 136, 0, { 23, 8, 27, 29 }, 0 },
	{ { { "ね", "", "" }, { "ネ", "", "" }, { "", "", "" } }, 46, 136, 0, { 24, 9, 28, 30 }, 0 },
	{ { { "の", "", "" }, { "ノ", "", "" }, { "", "", "" } }, 56, 136, 0, { 25, 10, 29, 51 }, 0 },
	{ { { "は", "ば", "ぱ" }, { "ハ", "バ", "パ" }, { "Ｆ", "", "" } }, 80, 72, 0, { 51, 36, 10, 32 }, 0 },
	{ { { "ひ", "び", "ぴ" }, { "ヒ", "ビ", "ピ" }, { "Ｇ", "", "" } }, 90, 72, 0, { 52, 37, 31, 33 }, 0 },
	{ { { "ふ", "ぶ", "ぷ" }, { "フ", "ブ", "プ" }, { "Ｈ", "", "" } }, 100, 72, 0, { 53, 38, 32, 34 }, 0 },
	{ { { "へ", "べ", "ぺ" }, { "ヘ", "ベ", "ペ" }, { "Ｉ", "", "" } }, 110, 72, 0, { 54, 39, 33, 35 }, 0 },
	{ { { "ほ", "ぼ", "ぽ" }, { "ホ", "ボ", "ポ" }, { "Ｊ", "", "" } }, 120, 72, 0, { 55, 40, 34, 56 }, 0 },
	{ { { "ま", "", "" }, { "マ", "", "" }, { "Ｐ", "", "" } }, 80, 88, 0, { 31, 41, 15, 37 }, 0 },
	{ { { "み", "", "" }, { "ミ", "", "" }, { "Ｑ", "", "" } }, 90, 88, 0, { 32, 42, 36, 38 }, 0 },
	{ { { "む", "", "" }, { "ム", "", "" }, { "Ｒ", "", "" } }, 100, 88, 0, { 33, 43, 37, 39 }, 0 },
	{ { { "め", "", "" }, { "メ", "", "" }, { "Ｓ", "", "" } }, 110, 88, 0, { 34, 44, 38, 40 }, 0 },
	{ { { "も", "", "" }, { "モ", "", "" }, { "Ｔ", "", "" } }, 120, 88, 0, { 35, 45, 39, 61 }, 0 },
	{ { { "や", "", "" }, { "ヤ", "", "" }, { "Ｚ", "", "" } }, 80, 104, 0, { 36, 46, 20, 42 }, 0 },
	{ { { "　", "", "" }, { "　", "", "" }, { "！", "", "" } }, 90, 104, 0, { 37, 47, 41, 43 }, 0 },
	{ { { "ゆ", "", "" }, { "ユ", "", "" }, { "？", "", "" } }, 100, 104, 0, { 38, 48, 42, 44 }, 0 },
	{ { { "　", "", "" }, { "　", "", "" }, { "　", "", "" } }, 110, 104, 0, { 39, 49, 43, 45 }, 0 },
	{ { { "よ", "", "" }, { "ヨ", "", "" }, { "〒", "", "" } }, 120, 104, 0, { 40, 50, 44, 66 }, 0 },
	{ { { "ら", "", "" }, { "ラ", "", "" }, { "５", "", "" } }, 80, 120, 0, { 41, 51, 25, 47 }, 0 },
	{ { { "り", "", "" }, { "リ", "", "" }, { "６", "", "" } }, 90, 120, 0, { 42, 52, 46, 48 }, 0 },
	{ { { "る", "", "" }, { "ル", "", "" }, { "７", "", "" } }, 100, 120, 0, { 43, 53, 47, 49 }, 0 },
	{ { { "れ", "", "" }, { "レ", "", "" }, { "８", "", "" } }, 110, 120, 0, { 44, 54, 48, 50 }, 0 },
	{ { { "ろ", "", "" }, { "ロ", "", "" }, { "９", "", "" } }, 120, 120, 0, { 45, 55, 49, 71 }, 0 },
	{ { { "わ", "", "" }, { "ワ", "", "" }, { "", "", "" } }, 80, 136, 0, { 46, 31, 30, 52 }, 0 },
	{ { { "を", "", "" }, { "ヲ", "", "" }, { "", "", "" } }, 90, 136, 0, { 47, 32, 51, 53 }, 0 },
	{ { { "ん", "", "" }, { "ン", "", "" }, { "", "", "" } }, 100, 136, 0, { 48, 33, 52, 54 }, 0 },
	{ { { "　", "", "" }, { "　", "", "" }, { "", "", "" } }, 110, 136, 0, { 49, 34, 53, 55 }, 0 },
	{ { { "　", "", "" }, { "　", "", "" }, { "", "", "" } }, 120, 136, 0, { 50, 35, 54, 76 }, 0 },
	{ { { "ぁ", "", "" }, { "ァ", "", "" }, { "軍", "", "" } }, 144, 72, 0, { 76, 61, 35, 57 }, 0 },
	{ { { "ぃ", "", "" }, { "ィ", "", "" }, { "騎", "", "" } }, 154, 72, 0, { 77, 62, 56, 58 }, 0 },
	{ { { "ぅ", "", "" }, { "ゥ", "", "" }, { "士", "", "" } }, 164, 72, 0, { 78, 63, 57, 59 }, 0 },
	{ { { "ぇ", "", "" }, { "ェ", "", "" }, { "団", "", "" } }, 174, 72, 0, { 79, 64, 58, 60 }, 0 },
	{ { { "ぉ", "", "" }, { "ォ", "", "" }, { "隊", "", "" } }, 184, 72, 0, { 80, 65, 59, 1 }, 0 },
	{ { { "ゃ", "", "" }, { "ャ", "", "" }, { "飛", "", "" } }, 144, 88, 0, { 56, 66, 40, 62 }, 0 },
	{ { { "　", "", "" }, { "　", "", "" }, { "竜", "", "" } }, 154, 88, 0, { 57, 67, 61, 63 }, 0 },
	{ { { "ゅ", "", "" }, { "ュ", "", "" }, { "天", "", "" } }, 164, 88, 0, { 58, 68, 62, 64 }, 0 },
	{ { { "　", "", "" }, { "　", "", "" }, { "馬", "", "" } }, 174, 88, 0, { 59, 69, 63, 65 }, 0 },
	{ { { "ょ", "", "" }, { "ョ", "", "" }, { "聖", "", "" } }, 184, 88, 0, { 60, 70, 64, 2 }, 0 },
	{ { { "っ", "", "" }, { "ッ", "", "" }, { "魔", "", "" } }, 144, 104, 0, { 61, 71, 45, 67 }, 0 },
	{ { { "゛", "", "" }, { "゛", "", "" }, { "道", "", "" } }, 154, 104, 0, { 62, 72, 66, 68 }, 6 },
	{ { { "゜", "", "" }, { "゜", "", "" }, { "戦", "", "" } }, 164, 104, 0, { 63, 73, 67, 69 }, 7 },
	{ { { "ー", "", "" }, { "ー", "", "" }, { "光", "", "" } }, 174, 104, 0, { 64, 74, 68, 70 }, 0 },
	{ { { "　", "", "" }, { "　", "", "" }, { "闇", "", "" } }, 184, 104, 0, { 65, 75, 69, 3 }, 0 },
	{ { { "", "", "" }, { "", "", "" }, { "理", "", "" } }, 144, 120, 0, { 66, 76, 50, 72 }, 0 },
	{ { { "", "", "" }, { "", "", "" }, { "傭", "", "" } }, 154, 120, 0, { 67, 77, 71, 73 }, 0 },
	{ { { "", "", "" }, { "", "", "" }, { "兵", "", "" } }, 164, 120, 0, { 68, 78, 72, 74 }, 0 },
	{ { { "", "", "" }, { "", "", "" }, { "装", "", "" } }, 174, 120, 0, { 69, 79, 73, 75 }, 0 },
	{ { { "", "", "" }, { "", "", "" }, { "撃", "", "" } }, 184, 120, 0, { 70, 80, 74, 4 }, 0 },
	{ { { "", "", "" }, { "", "", "" }, { "勇", "", "" } }, 144, 136, 0, { 71, 56, 55, 77 }, 0 },
	{ { { "", "", "" }, { "", "", "" }, { "神", "", "" } }, 154, 136, 0, { 72, 57, 76, 78 }, 0 },
	{ { { "", "", "" }, { "", "", "" }, { "将", "", "" } }, 164, 136, 0, { 73, 58, 77, 79 }, 0 },
	{ { { "", "", "" }, { "", "", "" }, { "重", "", "" } }, 174, 136, 0, { 74, 59, 78, 80 }, 0 },
	{ { { "", "", "" }, { "", "", "" }, { "軽", "", "" } }, 184, 136, 0, { 75, 60, 79, 5 }, 0 },
};

i16 const gUnk_Sio_0810EFD2[] = {
	0x06, 0x07, 0x08, 0x09, 0x0A, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x38, 0x39, 0x3A, 0x3B, 0x3C,
	0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x24, 0x25, 0x26, 0x27, 0x28, 0x3D, 0x3E, 0x3F, 0x40, 0x41,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x42, 0x43, 0x44, 0x45, 0x46,
	0x15, 0x16, 0x17, 0x18, 0x19, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x47, 0x48, 0x49, 0x4A, 0x4B,
	0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x33, 0x34, 0x35, 0x36, 0x37, 0x4C, 0x4D, 0x4E, 0x4F, 0x50,
};

char const SioText_HideUnits[] = "ユニットを隠す";
char const SioText_VictoryCondition[] = "対戦勝利条件";
char const SioText_Points[] = "ポイント";
char const SioText_Survival[] = "サバイバル";
char const SioText_AutoWeapons[] = "自動武器選択";
char const SioText_On[] = "オン";
char const SioText_Off[] = "オフ";
char const SioText_NowLoading[] = "ＮＯＷ　ＬＯＡＤＩＮＧ";
char const SioText_ConnectionSuccess[] = "接続　成功";
char const SioText_ConnectionError[] = "接続エラー";
char const SioText_Preparing[] = "準　備　中";
char const SioText_NotConnected[] = "未　接　続";
char const SioText_CreateTeam[] = "チーム作成";
char const SioText_VersusTeam[] = "対戦チーム";
char const SioText_UnitList[] = "部隊\x95\x5C"; // \x95\x5C = 表
char const SioText_SwapTeams[] = "チーム入替え";
char const SioText_EraseTeam[] = "チーム削除";
char const SioText_LinkMenu[] = "通信メニュー";

u32 SioStrCpy(void const * src, void * dst)
{
	u8 const * s = src;
	u8 * d = dst;
	u32 ret = 0;

	while (*s != '\0') {
		*d++ = *s++;
		ret++;
	}

	*d = *s;
	return ret;
}

void SIOCON_Init(void)
{
	SioInit_HW();
	SioInit_SW();

	gSioSt->unk_001 = 1;
	gSioSt->unk_004 = 0;
}

void SIOCON_Loop(ProcPtr proc)
{
	u16 magic = 0x2586;

	if (SioPollingMsg() != -1) {
		gSioSt->unk_011 = 0;
		gSioSt->unk_004 = 5;
		gSioSt->self_id = GetSioIndex();
		SioSend16(&magic, -1);
		Proc_Break(proc);
	}
}

void SetBmStLinkArenaFlag(void)
{
	gBmSt.flags |= BM_FLAG_LINKARENA;
}

void UnsetBmStLinkArenaFlag(void)
{
	gBmSt.flags &= ~BM_FLAG_LINKARENA;
}

int CheckInLinkArena(void)
{
	return (gBmSt.flags >> 6) & 1;
}

void func_fe6_08036994(void)
{
	gLinkArenaSt.unk_04 = -1;
}

void func_fe6_080369A0(struct ProcSioBlend * proc)
{
	SetBlendTargetA(0, 0, 1, 0, 0);
	SetBlendTargetB(1, 1, 0, 1, 1);
	SetBlendConfig(BLEND_EFFECT_NONE, 0, 0, 0);

	proc->timer = 0;
}

void func_fe6_080369E0(struct ProcSioBlend * proc)
{
	int time = (++proc->timer) % 0x40;

	if (time >= 0x20)
		time = 0x40 - time;

	if (time > 0x10)
		time = 0x10;

	SetBlendTargetA(0, 0, 1, 0, 0);
	SetBlendTargetB(1, 1, 0, 1, 1);
	SetBlendAlpha(time, 0x10 - time);
}

void func_fe6_08036A40(void)
{
	gDispIo.bg_off[BG_1].x++;
	gDispIo.bg_off[BG_2].x--;
}

void func_fe6_08036A54(ProcPtr proc)
{
	gSioSt->unk_030 = 0x9ABC;

	if (gSioSt->unk_1B7E != 0)
		Proc_Break(proc);
}

void func_fe6_08036A80(void)
{
	gSioSt->unk_00A = 1 << gSioSt->self_id;
}

void func_fe6_08036A94(ProcPtr proc)
{
	gSioMsgBuf.kind = SIO_MSG_19;
	gSioMsgBuf.sender = gSioSt->self_id;
	gSioMsgBuf.param = 0;

	SioSend(&gSioMsgBuf, 4);

	if ((gSioSt->unk_00A & gSioSt->unk_009) == gSioSt->unk_009) {
		gSioSt->unk_00A = 1 << gSioSt->self_id;
		Proc_Break(proc);
	}
}

void SioHold_Loop(struct ProcSioHold * proc)
{
	if (proc->y < proc->y_max && proc->y > proc->y_min)
		PutFrozenUiHand(proc->x, proc->y);
}

ProcPtr StartSioHold(ProcPtr parent, int x, int y, int y_max, int y_min)
{
	struct ProcSioHold * proc;

	proc = SpawnProc(ProcScr_SioHOLD, parent);
	proc->x = x;
	proc->y = y;
	proc->y_max = y_max;
	proc->y_min = y_min;

	return proc;
}

void EndSioHold(void)
{
	Proc_EndEach(ProcScr_SioHOLD);
}

void func_fe6_08036B38(ProcPtr proc, int num)
{
	((struct ProcSioHold *) proc)->y += num;
}

void ClearSioBG(void)
{
	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_1, 0, 0);
	SetBgOffset(BG_2, 0, 0);
	SetBgOffset(BG_3, 0, 0);

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT);
}

void ClearSioAllBGs(void)
{
	SetBgOffset(BG_0, 0, 0);
	SetBgOffset(BG_1, 0, 0);
	SetBgOffset(BG_2, 0, 0);
	SetBgOffset(BG_3, 0, 0);

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);
	TmFill(gBg3Tm, 0);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

void SioPutText(int msg, int text_idx)
{
	struct Text * text = &gSioTexts[text_idx];

	ClearText(text);

	if (msg < 0) {
		PutText(text, gBg2Tm + TM_OFFSET(1, text_idx * 2 + 0x10));
	} else {
		Text_DrawString(text, DecodeMsg(msg));
		PutText(text, gBg2Tm + TM_OFFSET(1, text_idx * 2 + 0x10));
		EnableBgSync(BG2_SYNC_BIT);
	}
}

void func_fe6_08036C60(void)
{
	int i;

	for (i = 0; i < 6; i++)
		InitText(&gSioMenuTexts[i], 12);

	for (i = 0; i < 11; i++)
		InitText(&gLinkArenaSt.texts[i], 12);

	for (i = 0; i < 2; i++)
		InitText(&gSioTexts[i], 24);
}

void SioSetNormalWeapons(struct Unit * unit)
{
	int i;
	u8 item_list[] = {
		IID_IRONSWORD,
		IID_IRONLANCE,
		IID_IRONAXE,
		IID_IRONBOW,
		IID_NONE,
		IID_FIRE,
		IID_LIGHTNING,
		IID_FLUX,
	};

	for (i = 0; i < ITEMSLOT_INV_COUNT; i++)
		unit->items[i] = 0;

	for (i = 0; i < 8; i++) {
		if (i == 4)
			continue;

		if (unit->wexp[i] == 0)
			continue;

		UnitAddItem(unit, item_list[i] | (0xFF << 8));
	}
}

void SioPlaySe(int idx)
{
	u16 se_list[] = { SONG_6C, SONG_6B, SONG_6A, SONG_66 };

	PlaySe(se_list[idx]);
}

void func_fe6_08036D3C(void)
{
	ReadMultiArenaSaveConfig((u16 *) &gSioSaveConfig);
	gSioSaveConfig.unk_3 = true;
	WriteMultiArenaSaveConfig((u16 *) &gSioSaveConfig);
}

bool SioIsKeyInputSequenceComplete(u16 const * list)
{
	if (gKeySt->pressed == 0) {
		if (++gKeyInputSequenceTimer >= 20)
			gTargetKeyInSeqIndex = gKeyInputSequenceTimer = 0;

		return false;
	}

	gKeyInputSequenceTimer = 0;
	gKeyInputSequenceBuffer[gCurrentKeyInSeqIndex] = gKeySt->pressed;

	if (gKeyInputSequenceBuffer[gCurrentKeyInSeqIndex] == list[gTargetKeyInSeqIndex]) {
		gTargetKeyInSeqIndex = gTargetKeyInSeqIndex + 1;

		if (list[gTargetKeyInSeqIndex] == 0xFFFF)
			return true;
	} else {
		gTargetKeyInSeqIndex = 0;
	}

	gCurrentKeyInSeqIndex = (gCurrentKeyInSeqIndex + 1) & 0xF;
	return false;
}

int CheckDisplayPasswordScreenCombo(void)
{
	return SioIsKeyInputSequenceComplete(gSioKeyList_PasswordScreenEN);
}

void StartLinkArenaTeamList(ProcPtr parent)
{
	SpawnProcLocking(ProcScr_SioTeamList, parent);
}

void SioTeamList_Init(struct SioTeamListProc * proc)
{
	proc->y_bg1 = 216;
	proc->unk_48 = 0;
	proc->unk_40 = 0;
	proc->option_idx = 0;
	proc->selected_option = MULTIARENA_LIST_NONE;
	proc->unk_54 = 0xFF;
	proc->selected_team = 0xFF;
	proc->unk_4C = 0;
}

bool CanBuildNewLinkArenaTeam(void)
{
	int i;

	if (gLinkArenaSt.unk_0A == 0)
		return FALSE;

	for (i = 0; i < MULTIARENA_MAX_TEAMS; i++) {
		if ((gLinkArenaTeamList[i].unk_0F & 0x80) != 0)
			return TRUE;
	}

	return FALSE;
}

bool CanDirectlyBuildNewLinkArenaTeam(void)
{
	int i;

	for (i = 0; i < MULTIARENA_MAX_TEAMS; i++) {
		if ((gLinkArenaTeamList[i].unk_0F & 0x80) == 0)
			return TRUE;
	}

	return FALSE;
}

int GetSioTeams(int active_option, u8 mode)
{
	int i;
	int count = 0;
	char buf[16];

	struct LATeamListConfig * conf = gSioTeamListConfigLut[mode];

	InitUnits();

	switch (mode) {
	case 0:
		for (i = 0; i < MULTIARENA_MAX_TEAMS; i++) {
			if (ReadMultiArenaSaveTeamName(i, gLinkArenaTeamList[i].name) == 1) {
				gLinkArenaTeamList[i].unk_10 = conf[active_option].unk_04;
				gLinkArenaTeamList[i].unk_0F = i;
			} else {
				SioStrCpy("未　使　用", gLinkArenaTeamList[i].name);
				gLinkArenaTeamList[i].unk_10 = conf[active_option].unk_05;
				gLinkArenaTeamList[i].unk_0F = i | 0x80;
			}

			ReadMultiArenaSaveTeam(i, GetUnit(i * 5 + 1), buf);
		}

		count = i;
		break;

	case 1:
	case 2:
		for (i = 0; i < MULTIARENA_MAX_TEAMS; i++) {
			if (ReadMultiArenaSaveTeamName(i, gLinkArenaTeamList[count].name) == 1) {
				gLinkArenaTeamList[count].unk_10 = conf[active_option].unk_04;
				gLinkArenaTeamList[count].unk_0F = i;
				ReadMultiArenaSaveTeam(i, GetUnit(count * 5 + 1), buf);

				count++;
			}
		}

		break;
	}

	return count;
}

void DrawLinkArenaTeamName(int idx)
{
	ClearText(&gLinkArenaSt.texts[idx]);
	Text_SetColor(&gLinkArenaSt.texts[idx], TEXT_COLOR_SYSTEM_WHITE);
	Text_DrawString(&gLinkArenaSt.texts[idx], gLinkArenaTeamList[idx].name);

	gLinkArenaSt.texts[idx].chr_position =
		(gLinkArenaSt.texts[idx].chr_position & 0xFFF) | ((gLinkArenaTeamList[idx].unk_10 & 0xF) << 12);

	PutText(&gLinkArenaSt.texts[idx], gBg1Tm + TM_OFFSET(11, idx * 2));
}

void DrawAllLinkArenaTeams(struct SioTeamListProc * proc)
{
	int i;

	for (i = 0; i < proc->unk_38; i++)
		DrawLinkArenaTeamName(i);
}

void func_fe6_0803703C(struct SioTeamListProc * proc, u8 mode)
{
	int i;

	struct LATeamListConfig * conf = gSioTeamListConfigLut[mode];

	for (i = 0; i < proc->unk_38; i++) {
		if ((gLinkArenaTeamList[i].unk_0F & 0x80) == 0)
			gLinkArenaTeamList[i].unk_10 = conf[proc->option_idx].unk_04;
		else
			gLinkArenaTeamList[i].unk_10 = conf[proc->option_idx].unk_05;

		gLinkArenaSt.texts[i].chr_position =
			(gLinkArenaSt.texts[i].chr_position & 0xFFF) | ((gLinkArenaTeamList[i].unk_10 & 0xF) << 12);

		PutText(&gLinkArenaSt.texts[i], gBg1Tm + TM_OFFSET(11, i * 2));
	}

	EnableBgSync(BG1_SYNC_BIT);
}

void SioTeamList_EraseTeam(struct SioTeamListProc * proc)
{
	int team = proc->unk_40;

	struct LATeamListConfig * conf = gSioTeamListConfigLut[gLinkArenaSt.unk_00];

	struct Unit * unit = GetUnit(team * 5 + 1);

	WipeMultiArenaSaveTeam(gLinkArenaTeamList[team].unk_0F & 0x7F);
	ReadMultiArenaSaveTeam(team, unit, gLinkArenaTeamList[team].name);

	SioStrCpy("未　使　用", gLinkArenaTeamList[team].name);

	gLinkArenaTeamList[team].unk_10 = conf[proc->option_idx].unk_05;
	gLinkArenaTeamList[team].unk_0F = team | 0x80;
	DrawLinkArenaTeamName(team);

	if (!CanDirectlyBuildNewLinkArenaTeam()) {
		func_fe6_080372B0(gLinkArenaSt.unk_00, proc);
		Proc_Goto(proc, 2);
	} else if (proc->valid_options[0] == 0) {
		func_fe6_080372B0(gLinkArenaSt.unk_00, proc);
	}

	UpdateLinkArenaMenuScrollBar(proc->unk_38, proc->y_bg1 + 40);

	EnableBgSync(BG1_SYNC_BIT);
}

void SioTeamList_SwapTeams(struct SioTeamListProc * proc)
{
	int tmp;

	int team_b = proc->unk_40;
	int team_a = proc->selected_team;

	SwapMultiArenaSaveTeams(gLinkArenaTeamList[team_a].unk_0F & 0x7F, gLinkArenaTeamList[team_b].unk_0F & 0x7F);

	tmp = gLinkArenaTeamList[team_a].unk_10;
	gLinkArenaTeamList[team_a].unk_10 = gLinkArenaTeamList[team_b].unk_10;
	gLinkArenaTeamList[team_b].unk_10 = tmp;

	if (ReadMultiArenaSaveTeam(team_a, GetUnit(team_a * 5 + 1), gLinkArenaTeamList[team_a].name) == 0) {
		SioStrCpy("未　使　用", gLinkArenaTeamList[team_a].name);
		gLinkArenaTeamList[team_a].unk_0F = team_a | 0x80;
	} else {
		gLinkArenaTeamList[team_a].unk_0F = team_a;
	}

	if (ReadMultiArenaSaveTeam(team_b, GetUnit(team_b * 5 + 1), gLinkArenaTeamList[team_b].name) == 0) {
		SioStrCpy("未　使　用", gLinkArenaTeamList[team_b].name);
		gLinkArenaTeamList[team_b].unk_0F = team_b | 0x80;
	} else {
		gLinkArenaTeamList[team_b].unk_0F = team_b;
	}

	DrawLinkArenaTeamName(team_b);
	DrawLinkArenaTeamName(team_a);

	UpdateLinkArenaMenuScrollBar(proc->unk_38, proc->y_bg1 + 40);

	Proc_End(proc->sio_hold_proc);

	proc->selected_option = MULTIARENA_LIST_SWAP;

	EnableBgSync(BG1_SYNC_BIT);
}

int func_fe6_080372B0(u8 mode, struct SioTeamListProc * proc)
{
	int color;

	int i = 0;
	struct LATeamListConfig * conf = gSioTeamListConfigLut[mode];

	if (mode == 1) {
		for (i = 0; i < gLinkArenaSt.unk_05 + 2; i++) {
			SioStrCpy("未選択", gSioSelectedTeamNames[i]);
			ClearText(&gLinkArenaSt.unk_64[i]);
			PutDrawTextCentered(&gLinkArenaSt.unk_64[i], 1, i * 3 + 5, gSioSelectedTeamNames[i], 10);
		}

		return gLinkArenaSt.unk_05 + 2;
	}

	while (1) {
		if (conf[i].menu_text == NULL)
			return i;

		proc->valid_options[i] = 1;
		color = TEXT_COLOR_SYSTEM_WHITE;

		if (conf[i].is_valid != NULL && !conf[i].is_valid()) {
			proc->valid_options[i] = 0;
			color = TEXT_COLOR_SYSTEM_GRAY;
		}

		ClearText(&gSioMenuTexts[i]);
		Text_SetColor(&gSioMenuTexts[i], color);
		PutDrawTextCentered(&gSioMenuTexts[i], 1, i * 2 + 5, conf[i].menu_text, 7);

		i++;
	}
}

u16 GetLATeamListHelpTextId(struct SioTeamListProc * proc)
{
	struct LATeamListConfig * conf = gSioTeamListConfigLut[gLinkArenaSt.unk_00];

	if (gLinkArenaSt.unk_00 != 1)
		return conf[proc->option_idx].help_msg;

	if (proc->option_idx == 0)
		return MSG_6D1;
	else
		return MSG_6D2;
}

u8 const gUnk_Sio_0810F177[] = { 0x12, 0x04, 0x13, 0x14, 0x0F, 0x19, 0x0F, 0x11, 0x00 };
u8 const gUnk_Sio_0810F180[] = { 0x02, 0x13, 0x08, 0x02, 0x04, 0x19, 0x15, 0x12, 0x0C, 0x0E, 0x03, 0x04, 0x19, 0x00 };

int const gUnk_Sio_0810F190[] = { 6, 9, 7 };
u8 const gUnk_Sio_0810F19C[] = { 1, 2, 4 };

void SioTeamList_SetupGfx(struct SioTeamListProc * proc)
{
	int i;
	u8 buf[8];

	u16 const * text_pal = Pal_Text;

	ClearSioBG();
	InitSioBG();

	Decompress(Img_TacticianSelObj, OBJ_VRAM0 + 0x240 * CHR_SIZE);
	Sio_RestartBgSlide(0, 2);
	TmApplyTsa(gBg2Tm + TM_OFFSET(9, 4), Tsa_Sio_08109DF4, TILEREF(0, 1));
	ApplyPaletteExt(Pal_TacticianSelObj, 0x13 * 0x20, 0x80);

	Decompress(Img_Sio_081080D4, OBJ_VRAM0 + 0x300 * CHR_SIZE);
	ApplyPaletteExt(Pal_Sio_0831AABC, 0x11 * 0x20, 0x40);

	gPal[0x20] = 0;

	for (i = 0; i < 3; i++)
		gPal[0x21 + i] = text_pal[4 + i];

	EnablePalSync();

	SetTextFont(&gSioFont);
	InitSystemTextFont();
	ResetTextFont();

	func_fe6_08036C60();

	ApplyUnitSpritePalettes();
	ResetUnitSprites();
	ForceSyncUnitSpriteSheet();

	proc->unk_38 = GetSioTeams(proc->option_idx, gLinkArenaSt.unk_00);

	for (i = 0; i < 5; i++)
		buf[i] = 0;

	buf[proc->option_idx] = 1;

	proc->num_active_options = func_fe6_080372B0(gLinkArenaSt.unk_00, proc);

	DrawAllLinkArenaTeams(proc);

	proc->unk_2C = func_fe6_080403C0(proc, proc->num_active_options, buf);

	for (i = 0; i < 4; i++)
		gLinkArenaSt.unk_06[i] = 0xFF;

	proc->unk_5C = 0;

	SetBgOffset(BG_1, 0, proc->y_bg1);

	SetWinEnable(1, 1, 0);

	SetWin0Box(0, 40, DISPLAY_WIDTH, 136);
	SetWin1Box(0, 136, DISPLAY_WIDTH, DISPLAY_HEIGHT);

	SetWin0Layers(1, 1, 1, 1, 1);
	SetWin1Layers(1, 0, 1, 1, 0);
	SetWOutLayers(1, 0, 1, 1, 1);

	StartLinkArenaTitleBanner(proc->unk_2C, gUnk_Sio_0810F19C[gLinkArenaSt.unk_00]);
	func_fe6_0803FD40(gUnk_Sio_085C9AD4[gLinkArenaSt.unk_00], gUnk_Sio_0810F190[gLinkArenaSt.unk_00], 0, 8, gLinkArenaSt.unk_00, proc->unk_2C);

	SioPutText(GetLATeamListHelpTextId(proc), 1);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

void SioTeamList_Main_HandleDPadInput(int * selection, u8 max, u8 min, u8 total)
{
	if (gKeySt->repeated & KEY_DPAD_UP) {
		if (*selection > min || gKeySt->repeated == gKeySt->pressed) {
			*selection = *selection - 1;

			if (*selection < 0)
				*selection = total - 1;
		}
	}

	if (gKeySt->repeated & KEY_DPAD_DOWN) {
		if (*selection < max || gKeySt->repeated == gKeySt->pressed) {
			*selection = *selection + 1;
			*selection = *selection % total;
		}
	}
}

void SioTeamList_Loop_MainKeyHandler(struct SioTeamListProc * proc)
{
	int previous = proc->option_idx;

	struct LATeamListConfig * conf = gSioTeamListConfigLut[gLinkArenaSt.unk_00];

	struct SioProc85AAA78 * unk_2C = proc->unk_2C;
	unk_2C->unk_44 = 1;
	unk_2C->unk_48 = -1;

	SioTeamList_Main_HandleDPadInput(&proc->option_idx, proc->num_active_options - 1, 0, proc->num_active_options);

	if (previous != proc->option_idx) {
		SioPlaySe(3);

		unk_2C->unk_3A[previous] = 0;
		unk_2C->unk_3A[proc->option_idx] = 1;

		func_fe6_0803703C(proc, gLinkArenaSt.unk_00);
		SioPutText(GetLATeamListHelpTextId(proc), 1);
	}

	if (gKeySt->pressed & KEY_BUTTON_A) {
		if (gLinkArenaSt.unk_00 != 1) {
			if (proc->valid_options[proc->option_idx] != 0) {
				proc->selected_option = conf[proc->option_idx].kind;

				if (proc->selected_option == MULTIARENA_LIST_LINKMENU) {
					SioPlaySe(1);
					Proc_Goto(proc, 9);
					gLinkArenaSt.unk_03 = 0xFF;
					return;
				}

				SioPlaySe(2);

				Proc_Break(proc);
			} else {
				SioPlaySe(0);
			}
		} else {
			SioPlaySe(2);

			proc->selected_option = MULTIARENA_LIST_8;
			proc->selected_team = proc->option_idx;
			proc->unk_44 = 0;

			Proc_Goto(proc, 5);

			return;
		}
	}

	if (gKeySt->pressed & KEY_BUTTON_B) {
		SioPlaySe(1);
		Proc_Goto(proc, 9);
		gLinkArenaSt.unk_03 = 0xFF;
	}

	if ((gKeySt->pressed & KEY_BUTTON_START) && proc->unk_5C != 0) {
		PlaySe(SONG_6A);
		gLinkArenaSt.unk_03 = 0;
		Proc_Goto(proc, 9);
	}
}

void SioTeamList_StartUnitList(struct SioTeamListProc * proc)
{
	char buf[16];
	struct Unit * unit;

	Proc_End(proc->unk_2C);
	Sio_EndBackgroundSlide();

	InitUnits();

	unit = GetUnit(1);
	ReadMultiArenaSaveTeam(gLinkArenaTeamList[proc->unk_40].unk_0F, unit, buf);

	StartUnitListScreenUnk(proc);
}

void SioTeamList_WaitForUnitListScreen(ProcPtr proc)
{
	if (FindProc(ProcScr_UnitListScreen_PrepMenu) == NULL)
		Proc_Break(proc);
}

int func_fe6_0803784C(void)
{
	int i;

	for (i = 0; i < gLinkArenaSt.unk_05 + 2; i++) {
		if (gLinkArenaSt.unk_06[i] == 0xFF)
			return 0;
	}

	return 1;
}

void SioTeamList_Loop_SubSel(struct SioTeamListProc * proc)
{
	int unk_40 = proc->unk_40;
	struct SioProc85AAA78 * unk_2C = proc->unk_2C;

	if (SioIsKeyInputSequenceComplete(KeyList_SioSecretTeam) && (gLinkArenaTeamList[unk_40].unk_0F & 0x80) == 0) {
		Proc_Goto(proc, 8);
		return;
	}

	unk_2C->unk_44 = 0;
	unk_2C->unk_48 = (proc->unk_40 - proc->unk_48) * 16 + 40;

	if (proc->unk_4C > 0) {
		proc->y_bg1 -= 4;
		proc->unk_4C--;

		SetBgOffset(BG_1, 0, proc->y_bg1);

		if (proc->sio_hold_proc != NULL)
			func_fe6_08036B38(proc->sio_hold_proc, +4);

		ScrollMultiArenaTeamSprites(+4);

		PutUiHand(80, (proc->unk_40 - proc->unk_48) * 16 + 40);
		UpdateLinkArenaMenuScrollBar(proc->unk_38, proc->y_bg1 + 40);

		return;
	} else if (proc->unk_4C < 0) {
		proc->y_bg1 += 4;
		proc->unk_4C++;

		SetBgOffset(BG_1, 0, proc->y_bg1);

		if (proc->sio_hold_proc != NULL)
			func_fe6_08036B38(proc->sio_hold_proc, -4);

		ScrollMultiArenaTeamSprites(-4);

		PutUiHand(80, (proc->unk_40 - proc->unk_48) * 16 + 40);
		UpdateLinkArenaMenuScrollBar(proc->unk_38, proc->y_bg1 + 40);

		return;
	}

	PutUiHand(80, (proc->unk_40 - proc->unk_48) * 16 + 40);

	if (gKeySt->pressed & KEY_BUTTON_A) {
		switch (proc->selected_option) {
		case MULTIARENA_LIST_BUILDTEAM:
			if (gLinkArenaTeamList[unk_40].unk_0F & 0x80) {
				SioPlaySe(2);
				gLinkArenaSt.unk_03 = proc->unk_40;
				Proc_Break(proc);
				return;
			}

			SioPlaySe(0);
			break;

		case MULTIARENA_LIST_SELECTTEAM:
			SioPlaySe(2);
			gLinkArenaSt.unk_03 = gLinkArenaTeamList[unk_40].unk_0F;
			Proc_Break(proc);
			return;

		case MULTIARENA_LIST_UNITLIST:
			if ((gLinkArenaTeamList[unk_40].unk_0F & 0x80) == 0) {
				SioPlaySe(2);
				Proc_Goto(proc, 4);
				return;
			}

			SioPlaySe(0);
			break;

		case MULTIARENA_LIST_SWAP:
			if (proc->unk_38 > 1) {
				SioPlaySe(2);

				proc->selected_team = unk_40;
				proc->sio_hold_proc = StartSioHold(proc, 80, (proc->selected_team - proc->unk_48) * 16 + 40, 0x88, 0x27);

				if (unk_40 + 1 < proc->unk_38)
					gKeySt->repeated |= KEY_DPAD_DOWN;
				else
					gKeySt->repeated |= KEY_DPAD_UP;

				proc->selected_option = MULTIARENA_LIST_CONFIRMSWAP;
			}
			break;

		case MULTIARENA_LIST_LINKMENU:
			break;

		case MULTIARENA_LIST_CONFIRMSWAP:
			SioPlaySe(2);
			SioTeamList_SwapTeams(proc);
			break;

		case MULTIARENA_LIST_DISBAND:
			if ((gLinkArenaTeamList[unk_40].unk_0F & 0x80) == 0) {
				SioPlaySe(2);
				proc->sio_hold_proc = StartSioHold(proc, 80, (unk_40 - proc->unk_48) * 16 + 40, 0x88, 0x27);
				Proc_Goto(proc, 7);
			} else {
				SioPlaySe(0);
			}
			break;

		case MULTIARENA_LIST_8:
			SioPlaySe(2);

			SioStrCpy(gLinkArenaTeamList[unk_40].name, gSioSelectedTeamNames[proc->selected_team]);

			gLinkArenaSt.unk_06[proc->selected_team] = gLinkArenaTeamList[unk_40].unk_0F;

			ClearText(&gLinkArenaSt.unk_64[proc->selected_team]);
			PutDrawTextCentered(
				&gLinkArenaSt.unk_64[proc->selected_team], 1, proc->selected_team * 3 + 5,
				gSioSelectedTeamNames[proc->selected_team], 10);

			proc->unk_5C = func_fe6_0803784C();

			if (proc->unk_5C != 0 && unk_2C->unk_40 == 0)
				unk_2C->unk_40 = 8;

			proc->unk_44 = 0;
			Proc_Goto(proc, 6);
			break;
		}
	}

	if (gKeySt->pressed & KEY_BUTTON_B) {
		SioPlaySe(1);

		if (proc->selected_option == MULTIARENA_LIST_CONFIRMSWAP) {
			proc->selected_option = MULTIARENA_LIST_SWAP;
			Proc_End(proc->sio_hold_proc);
			return;
		}

		if (proc->selected_option != MULTIARENA_LIST_8) {
			Proc_Goto(proc, 2);
		} else {
			proc->unk_44 = 0;
			Proc_Goto(proc, 6);
		}
	}

	if ((gKeySt->pressed & KEY_BUTTON_START) && proc->unk_5C != 0) {
		PlaySe(SONG_6A);
		gLinkArenaSt.unk_03 = 0;
		Proc_Goto(proc, 9);
	}

	if (gKeySt->repeated & KEY_DPAD_UP) {
		if (proc->unk_48 != 0 && (proc->unk_40 - proc->unk_48) < 2) {
			proc->y_bg1 -= 4;

			if (proc->sio_hold_proc != NULL)
				func_fe6_08036B38(proc->sio_hold_proc, +4);

			ScrollMultiArenaTeamSprites(+4);

			proc->unk_48--;
			proc->unk_4C = +3;
			proc->unk_40--;

			SetBgOffset(BG_1, 0, proc->y_bg1);

			UpdateLinkArenaMenuScrollBar(proc->unk_38, proc->y_bg1 + 40);
		} else if (proc->unk_40 > 0) {
			proc->unk_40--;
		}
	}

	if (gKeySt->repeated & KEY_DPAD_DOWN) {
		if (proc->unk_38 > 6 && proc->unk_48 + 6 < proc->unk_38 && (proc->unk_40 - proc->unk_48) > 3) {
			proc->y_bg1 += 4;

			if (proc->sio_hold_proc != NULL)
				func_fe6_08036B38(proc->sio_hold_proc, -4);

			ScrollMultiArenaTeamSprites(-4);

			proc->unk_48++;
			proc->unk_4C = -3;
			proc->unk_40++;

			SetBgOffset(BG_1, 0, proc->y_bg1);

			UpdateLinkArenaMenuScrollBar(proc->unk_38, proc->y_bg1 + 40);
		} else if (proc->unk_40 < proc->unk_38 - 1) {
			proc->unk_40++;
		}
	}

	if (unk_40 != proc->unk_40)
		SioPlaySe(3);
}

void func_fe6_08037D74(struct SioProc85AAA78 * proc, i8 x)
{
	int i;

	for (i = 0; i < 5; i++)
		proc->unk_30[i] = -x - 8;
}

i8 const gXposArray_SioTeamListSwicthing[] = { 2, 6, 13, 19, 20, -2, 20, 19, 13, 6, 2, 0, -1 };

void SioTeamList_SubSel_Switching(struct SioTeamListProc * proc)
{
	struct SioProc85AAA78 * unk_2C = proc->unk_2C;
	i8 x = gXposArray_SioTeamListSwicthing[proc->unk_44];

	if (x == -1)
		Proc_Goto(proc, 3);

	proc->unk_44++;

	if (x == -2) {
		gDispIo.bg1_ct.priority = 0;
		gDispIo.bg2_ct.priority = 1;
		gDispIo.bg0_ct.priority = 2;
		gDispIo.bg3_ct.priority = 3;

		unk_2C->unk_44 = 0;
	} else {
		SetBgOffset(BG_0, x, 0);
		func_fe6_08037D74(unk_2C, x);
	}
}

void func_fe6_08037E14(struct SioTeamListProc * proc)
{
	struct SioProc85AAA78 * unk_2C = proc->unk_2C;
	i8 x = gXposArray_SioTeamListSwicthing[proc->unk_44];

	if (x == -1)
		Proc_Goto(proc, 2);

	proc->unk_44++;

	if (x == -2) {
		gDispIo.bg0_ct.priority = 0;
		gDispIo.bg1_ct.priority = 1;
		gDispIo.bg2_ct.priority = 2;
		gDispIo.bg3_ct.priority = 3;

		unk_2C->unk_44 = 1;
		unk_2C->unk_48 = -1;
	} else {
		SetBgOffset(BG_0, x, 0);
		func_fe6_08037D74(unk_2C, x);
	}
}

void SioTeamList_StartEraseTeamSubMenu(struct SioTeamListProc * proc)
{
	int var;

	proc->unk_55 = 1;

	SioPutSupportMenuImage();

	var = proc->unk_40 - proc->unk_48;

	if (var > 2)
		proc->unk_58 = var * 2 - 2;
	else
		proc->unk_58 = var * 2 + 5;

	ClearText(&gSioPromptText);
	Text_DrawString(&gSioPromptText, "消す　　　やめる");
	PutText(&gSioPromptText, gBg0Tm + TM_OFFSET(15, proc->unk_58 + 4));

	EnableBgSync(BG0_SYNC_BIT);
}

void SioTeamList_EraseTeam_KeyHandler(struct SioTeamListProc * proc)
{
	PutLinkArenaChoiceBannerSprite(96, proc->unk_58 * 8 + 24);

	if ((gKeySt->pressed & KEY_DPAD_LEFT) && proc->unk_55 == 1) {
		proc->unk_55 = 0;
		SioPlaySe(3);
	}

	if ((gKeySt->pressed & KEY_DPAD_RIGHT) && proc->unk_55 == 0) {
		proc->unk_55 = 1;
		SioPlaySe(3);
	}

	PutUiHand(proc->unk_55 * 40 + 112, proc->unk_58 * 8 + 32);

	if (gKeySt->pressed & KEY_BUTTON_B) {
		SioPlaySe(1);

		Proc_End(proc->sio_hold_proc);

		TmFillRect(gBg0Tm + TM_OFFSET(15, proc->unk_58 + 4), 12, 2, 0);
		EnableBgSync(BG0_SYNC_BIT);

		Proc_Break(proc);
	} else if (gKeySt->pressed & KEY_BUTTON_A) {
		Proc_End(proc->sio_hold_proc);

		if (proc->unk_55 == 0) {
			SioTeamList_EraseTeam(proc);
			SioPlaySe(2);
		} else {
			SioPlaySe(1);
		}

		TmFillRect(gBg0Tm + TM_OFFSET(15, proc->unk_58 + 4), 12, 2, 0);
		EnableBgSync(BG0_SYNC_BIT);

		Proc_Break(proc);
	}
}

void SioTeamList_LoadTeam_Dummy(struct SioTeamListProc * proc)
{
	char buf[16];

	ReadMultiArenaSaveTeam(proc->unk_40, GetUnit(1), buf);
	NewGeneralSecretScreen(proc);
}

struct TacticianTextConf const * GetTacticianTextConf(i16 idx)
{
	return gTacticianTextConf + idx;
}

void func_fe6_08038040(struct ProcTactician * proc)
{
	int i, j;

	for (i = 0; i < 5; i++) {
		ClearText(gSioLineTexts + (i + proc->text_idx * 5));
		Text_SetColor(gSioLineTexts + (i + proc->text_idx * 5), TEXT_COLOR_SYSTEM_WHITE);

		for (j = 0; j < 15; j++) {
			i16 idx = gUnk_Sio_0810EFD2[i * 15 + j];
			struct TacticianTextConf const * conf = gTacticianTextConf + idx;

			if (*conf->str[proc->line_idx][0] != '\0') {
				Text_SetCursor(gSioLineTexts + (i + proc->text_idx * 5), conf->x);
				Text_DrawString(gSioLineTexts + (i + proc->text_idx * 5), conf->str[proc->line_idx][0]);
			}
		}

		PutText(gSioLineTexts + (i + proc->text_idx * 5), gBg1Tm + TM_OFFSET(0, i * 2 + 9));
	}
}

void TacticianDrawCharacters(struct ProcTactician * proc)
{
	ClearText(&gSioHeaderText);
	Text_DrawString(&gSioHeaderText, proc->str);
	PutText(&gSioHeaderText, gBg0Tm + TM_OFFSET(12, 5));
	EnableBgSync(BG0_SYNC_BIT);
}

void Tactician_InitScreen(struct ProcTactician * proc)
{
	int i;
	struct TacticianTextConf const * conf;
	u8 list[] = { 13, 0, 12, 4, 4, 13, 19, 17, 24, 25 };

	ClearSioBG();
	InitSioBG();
	Decompress(Img_TacticianSelObj, OBJ_VRAM0 + 0x4800);
	ApplyPalette(Pal_TacticianSelObj, 0x13);
	ApplyPalette(gUnk_08109C40, 0x14);
	Sio_RestartBgSlide(0, 0);
	TmApplyTsa(gBg2Tm + TM_OFFSET(0, 8), gUnk_0810A044, 0x1000);
	SetTextFont(&gSioFont);
	InitSystemTextFont();
	ResetTextFont();

	CpuFill16(0, proc->str, 14);
	CpuFill16(0, proc->unk_4A, 14);

	proc->cur_len = 0;
	InitText(&gSioHeaderText, 8);
	proc->line_idx = 0;
	proc->conf_idx = 6;

	conf = GetTacticianTextConf(6);
	proc->child = func_fe6_0804067C(proc, conf->x - 4, conf->y + 1);
	proc->unk_37 = 0;

	for (i = 0; i < 10; i++)
		InitText(gSioLineTexts + i, 0x1A);

	InitText(&gLinkArenaSt.unk_64[5], 0xC);
	StartLinkArenaTitleBanner(proc->child, 3);
	func_fe6_0803FD40(list, 10, 0, 8, gLinkArenaSt.unk_00, proc->child);
	gUnk_Sio_0203C918 = 0;
	proc->text_idx = 0;
	func_fe6_08038040(proc);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

void SioUpdateTeam(char const * str, int team)
{
	int i;
	struct Unit * buffer = GetUnit(FACTION_RED + 1);

	for (i = 0; i < 5; i++)
		ClearUnit(buffer + i);

	for (i = 0; i < 5; i++) {
		u8 pid = SioPidPool[i];

		if (pid != 0) {
			struct Unit * unit = GetUnitByPid(pid);

			if (!(unit->flags & UNIT_FLAG_NOT_DEPLOYED)) {
				SetUnitStatus(unit, UNIT_STATUS_NONE);
				unit->flags = 0;
				SioMemCpy((u8 const *) unit, (u8 *) (buffer + i), sizeof(struct Unit));
			}
		}
	}

	WriteMultiArenaSaveTeam(team, buffer, str);
}

void Tactician_MoveHand(struct ProcTactician * proc, int pos, struct TacticianTextConf const * conf)
{
	int str_idx;
	u16 adj_idx;
	struct TacticianTextConf const * adj_conf;

	adj_idx = conf->adj_idx[pos];
	adj_conf = gTacticianTextConf + conf->adj_idx[pos];

	str_idx = proc->line_idx * 3;

	while (*adj_conf->str[0][str_idx] == '\0') {
		adj_idx = adj_conf->adj_idx[pos];
		adj_conf = gTacticianTextConf + adj_conf->adj_idx[pos];
	}

	proc->conf_idx = adj_idx;
}

void TacticianTryAppendChar(struct ProcTactician * proc, struct TacticianTextConf const * conf)
{
	int cur_len;

	if (proc->cur_len < 14) {
		SioPlaySe(2);
		SioStrCpy(conf->str[proc->line_idx][0], &proc->str[proc->cur_len]);

		proc->unk_4A[proc->cur_len / 2] = (0x3FFF & proc->conf_idx) | ((3 & proc->line_idx) << 14);
		cur_len = proc->cur_len + 2;

		if (cur_len < 14)
			proc->cur_len = cur_len;

		TacticianDrawCharacters(proc);
		proc->unk_37 = 0;
	} else {
		SioPlaySe(0);
	}
}

void TacticianTryDeleteChar(struct ProcTactician * proc, struct TacticianTextConf const * conf)
{
	if (proc->cur_len != 0) {
		SioPlaySe(2);

		if (proc->unk_4A[proc->cur_len / 2] == 0)
			proc->cur_len -= 2;

		*(proc->str + proc->cur_len) = 0;
		proc->unk_4A[proc->cur_len / 2] = 0;
		proc->unk_37 = 0;

		TacticianDrawCharacters(proc);
	} else {
		SioPlaySe(0);
	}
}

void SaveTactician(struct ProcTactician * proc, struct TacticianTextConf const * conf)
{
	if (proc->str[0] != '\0') {
		SioPlaySe(2);
		SioUpdateTeam(proc->str, gLinkArenaSt.unk_03);
		Proc_Break(proc);
	} else {
		SioPlaySe(0);
	}
}

bool func_fe6_0803848C(struct ProcTactician * proc, struct TacticianTextConf const * conf, int c, int d)
{
	if (proc->line_idx == 2 && d == 0) {
		SioPlaySe(2);
		TacticianTryAppendChar(proc, conf);
		return FALSE;
	}

	if (proc->cur_len != 0) {
		struct TacticianTextConf const * conf2;
		int r8, line_idx;

		if (0x3FFF & proc->unk_4A[proc->cur_len / 2])
			r8 = 0;
		else
			r8 = 1;

		conf2 = GetTacticianTextConf(0x3FFF & proc->unk_4A[proc->cur_len / 2 - r8]);
		line_idx = proc->unk_4A[proc->cur_len / 2 - r8] >> 14;

		if (*conf2->str[proc->line_idx][c] != '\0') {
			SioPlaySe(2);
			SioStrCpy(conf2->str[line_idx][c], &proc->str[proc->cur_len] - r8 * 2);
			TacticianDrawCharacters(proc);
			proc->unk_37 = c;
			return TRUE;
		} else if (d == 0) {
			SioPlaySe(0);
		}
	} else if (d == 0) {
		SioPlaySe(0);
	}

	return FALSE;
}

void Tactician_LoopCore(struct ProcTactician * proc, struct TacticianTextConf const * conf)
{
	u8 prev;

	if (gKeySt->repeated & KEY_DPAD_UP)
		Tactician_MoveHand(proc, 0, conf);

	if (gKeySt->repeated & KEY_DPAD_DOWN)
		Tactician_MoveHand(proc, 1, conf);

	if (gKeySt->repeated & KEY_DPAD_LEFT)
		Tactician_MoveHand(proc, 2, conf);

	if (gKeySt->repeated & KEY_DPAD_RIGHT)
		Tactician_MoveHand(proc, 3, conf);

	if (gKeySt->pressed & KEY_BUTTON_A) {
		switch (conf->action) {
		case 0:
			TacticianTryAppendChar(proc, conf);
			break;

		case 4:
			TacticianTryDeleteChar(proc, conf);
			break;

		case 5:
			SaveTactician(proc, conf);
			break;

		case 6:
			func_fe6_0803848C(proc, conf, 1, 0);
			break;

		case 7:
			func_fe6_0803848C(proc, conf, 2, 0);
			break;

		case 1:
			if (proc->line_idx != 0) {
				SioPlaySe(2);
				proc->line_idx = 0;
				proc->unk_37 = 0;
				Proc_Goto(proc, 1);
				return;
			}

			SioPlaySe(0);
			break;

		case 2:
			if (proc->line_idx != 1) {
				SioPlaySe(2);
				proc->line_idx = 1;
				proc->unk_37 = 0;
				Proc_Goto(proc, 1);
				return;
			}

			SioPlaySe(0);
			break;

		case 3:
			if (proc->line_idx != 2) {
				SioPlaySe(2);
				proc->line_idx = 2;
				proc->unk_37 = 0;
				Proc_Goto(proc, 1);
				return;
			}

			SioPlaySe(0);
			break;
		}
	}

	if (gKeySt->pressed & KEY_BUTTON_R) {
		prev = proc->unk_37;

		do {
			proc->unk_37++;
			proc->unk_37 = proc->unk_37 % 3;

			if (prev == proc->unk_37)
				break;
		} while (!func_fe6_0803848C(proc, conf, proc->unk_37, 1));
	}

	if (gKeySt->pressed & KEY_BUTTON_L)
		TacticianTryDeleteChar(proc, conf);

	if (gKeySt->pressed & KEY_BUTTON_START) {
		SioPlaySe(3);
		proc->conf_idx = 5;
	}

	if (gKeySt->pressed & KEY_BUTTON_SELECT) {
		SioPlaySe(2);

		proc->line_idx++;
		proc->line_idx = proc->line_idx % 3;

		if (*conf->str[proc->line_idx][0] == '\0')
			Tactician_MoveHand(proc, 0, conf);

		Proc_Goto(proc, 1);
	} else if (gKeySt->pressed & KEY_BUTTON_B) {
		if (proc->cur_len != 0) {
			TacticianTryDeleteChar(proc, conf);
		} else {
			SioPlaySe(1);
			Proc_Goto(proc, 3);
		}
	}
}

void Tactician_Loop(struct ProcTactician * proc)
{
	struct TacticianTextConf const * conf;
	char buf[0x10];

	conf = GetTacticianTextConf(proc->conf_idx);
	proc->prev_conf_idx = proc->conf_idx;

	Tactician_LoopCore(proc, conf);

	if (proc->prev_conf_idx != proc->conf_idx)
		SioPlaySe(3);

	conf = GetTacticianTextConf(proc->conf_idx);

	SioStrCpy(proc->str, buf);
	buf[12] = '\0';

	UpdateNameEntrySpriteDraw(proc->child, conf->x - 4, conf->y + 1, GetStringTextLen(buf), conf->kind, proc->line_idx);
}

void Tactician_VBlank(void)
{
	u16 vcount = REG_VCOUNT + 1;

	if (vcount > DISPLAY_HEIGHT)
		return;

	if (vcount < 40) {
		REG_BLDCNT = 0x840;
		REG_BLDALPHA = 0xF08;
	} else {
		REG_BLDCNT = 0x442;
		REG_BLDALPHA = gUnk_030013E8 + ((0xF - gUnk_030013E8) << 8);
	}
}

void Tactician_SetVBlank(struct ProcTactician * proc)
{
	proc->unk_38 = 0;
	SetOnHBlankA(Tactician_VBlank);
}

void func_fe6_080388A4(struct ProcTactician * proc)
{
	gUnk_030013E8 = Interpolate(0, 0xF, 0, proc->unk_38, 8);

	if (++proc->unk_38 > 8)
		Proc_Break(proc);
}

void func_fe6_080388E4(struct ProcTactician * proc)
{
	proc->text_idx++;
	proc->text_idx &= 1;
	func_fe6_08038040(proc);
	EnableBgSync(BG1_SYNC_BIT);
	proc->unk_38 = 0;
}

void func_fe6_08038910(struct ProcTactician * proc)
{
	gUnk_030013E8 = Interpolate(0, 0, 0xF, proc->unk_38, 8);

	if (++proc->unk_38 > 8) {
		SetOnHBlankA(NULL);
		Proc_Break(proc);
	}
}

void NameSelect_DrawName(struct ProcTactician * proc)
{
	proc->unk_39 = 1;
	SioPutSupportMenuImage();
	ClearText(&gSioPromptText);
	Text_DrawString(&gSioPromptText, "戻る　　　やめる");
	PutText(&gSioPromptText, gBg0Tm + TM_OFFSET(11, 12));
	EnableBgSync(BG0_SYNC_BIT);
}

void func_fe6_08038990(struct ProcTactician * proc)
{
	PutLinkArenaChoiceBannerSprite(0x40, 0x58);

	if ((gKeySt->pressed & KEY_DPAD_LEFT) && proc->unk_39 == 1) {
		proc->unk_39 = 0;
		SioPlaySe(3);
	}

	if ((gKeySt->pressed & KEY_DPAD_RIGHT) && proc->unk_39 == 0) {
		proc->unk_39 = 1;
		SioPlaySe(3);
	}

	PutUiHand(proc->unk_39 * 40 + 0x50, 0x60);

	if (gKeySt->pressed & KEY_BUTTON_B) {
		SioPlaySe(1);
		TmFillRect(gBg0Tm + TM_OFFSET(11, 12), 12, 2, 0);
		EnableBgSync(BG0_SYNC_BIT);
		Proc_Break(proc);
	} else if (gKeySt->pressed & KEY_BUTTON_A) {
		if (proc->unk_39 == 0) {
			SioPlaySe(2);
			gUnk_Sio_0203C918 = 1;
			Proc_Goto(proc, 2);
		} else {
			SioPlaySe(1);
		}

		TmFillRect(gBg0Tm + TM_OFFSET(11, 12), 12, 2, 0);
		EnableBgSync(BG0_SYNC_BIT);
		Proc_Break(proc);
	}
}

void SioPostBattleSprites_Init(struct SioPostBattleSpritesProc * proc)
{
	UnpackFaceChibiSprGraphics(proc->fid, proc->oam2 * 8 + 0x180, proc->oam2 + 10);
	proc->timer = 0;
	proc->y = -38;
}

u16 const Sprite_Sio_0810F1DA[] =
{
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x300) + OAM2_LAYER(1) + OAM2_PAL(3),
};

u16 const Sprite_Sio_0810F1E2[] =
{
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x304) + OAM2_LAYER(1) + OAM2_PAL(4),
};

u16 const Sprite_Sio_0810F1EA[] =
{
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x308) + OAM2_LAYER(1) + OAM2_PAL(5),
};

u16 const Sprite_Sio_0810F1F2[] =
{
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x30C) + OAM2_LAYER(1) + OAM2_PAL(6),
};

u16 const Sprite_Sio_0810F1FA[] =
{
	1,
	OAM0_SHAPE_64x32 + OAM0_Y(4), OAM1_SIZE_64x32, OAM2_CHR(0x340) + OAM2_LAYER(1) + OAM2_PAL(7),
};

u16 const Sprite_Sio_0810F202[] =
{
	2,
	OAM0_SHAPE_32x32 + OAM0_Y(8), OAM1_SIZE_32x32 + OAM1_X(8), OAM2_CHR(0x348) + OAM2_LAYER(1) + OAM2_PAL(7),
	OAM0_SHAPE_16x32 + OAM0_Y(8), OAM1_SIZE_16x32 + OAM1_X(40), OAM2_CHR(0x34C) + OAM2_LAYER(1) + OAM2_PAL(7),
};

u16 const Sprite_Sio_0810F210[] =
{
	1,
	OAM0_SHAPE_32x32 + OAM0_Y(8), OAM1_SIZE_32x32 + OAM1_X(16), OAM2_CHR(0x34E) + OAM2_LAYER(1) + OAM2_PAL(7),
};

u16 const Sprite_Sio_0810F218[] =
{
	1,
	OAM0_SHAPE_32x16 + OAM0_Y(16), OAM1_SIZE_32x16 + OAM1_X(16), OAM2_CHR(0x352) + OAM2_LAYER(1) + OAM2_PAL(7),
};

u16 const Sprite_Sio_0810F220[] =
{
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x356) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 const Sprite_Sio_0810F228[] =
{
	4,
	OAM0_SHAPE_16x32, OAM1_SIZE_16x32, OAM2_CHR(0x240) + OAM2_PAL(3),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(16), OAM2_CHR(0x243) + OAM2_PAL(3),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(48), OAM2_CHR(0x243) + OAM2_PAL(3),
	OAM0_SHAPE_16x32, OAM1_SIZE_16x32 + OAM1_X(80), OAM2_CHR(0x247) + OAM2_PAL(3),
};

u16 const Sprite_Sio_0810F242[] =
{
	3,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x100) + OAM2_PAL(14),
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x104) + OAM2_PAL(14),
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16 + OAM1_X(64), OAM2_CHR(0x108) + OAM2_PAL(14),
};

u16 const Sprite_Sio_0810F256[] =
{
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x100) + OAM2_PAL(14),
};

u16 const Sprite_Sio_0810F25E[] =
{
	2,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x0),
	OAM0_SHAPE_32x16 + OAM0_Y(16), OAM1_SIZE_32x16, OAM2_CHR(0x4),
};

void SioPostBattleSprites_Loop_DrawSlideIn(struct SioPostBattleSpritesProc * proc)
{
	struct SioPostBattleProc * parent = proc->unk_2C;

	if (parent->unk_64 == 0) {
		if (proc->timer > 32)
			Proc_Break(proc);
	}

	if (parent->unk_64 != 0)
		proc->y++;

	proc->delay--;

	if (proc->delay < 0)
		proc->delay = 0;

	if (proc->delay == 0) {
		if (proc->timer <= 32)
			proc->x = Interpolate(INTERPOLATE_RSQUARE, -80, 0, proc->timer, 32);

		proc->timer++;

		PutSprite(4, proc->x, proc->y - 16, SpriteArray_Sio_085C9D08[proc->ranking], 0);
		PutSprite(4, proc->x + 72, proc->y - 6, SpriteArray_Sio_085C9CF8[proc->oam2], 0);
		PutSprite(4, proc->x + 96, proc->y + 8, Sprite_Sio_0810F220, 0);
		PutSprite(4, proc->x + 64, proc->y + 8, Sprite_Sio_0810F256, proc->ranking * 4 + 0x50);
		PutSprite(4, -proc->x + 112, proc->y - 8, Sprite_Sio_0810F228, OAM2_PAL(proc->oam2) + 0x400);
		PutSprite(4, -proc->x + 124, proc->y, Sprite_Sio_0810F242, proc->oam2 == 3 ? 0x40 : proc->oam2 * 9);
		PutSprite(5, -proc->x + 208, proc->y - 8, Sprite_Sio_0810F25E, OAM2_PAL(proc->oam2 + 10) + 0x180 + (proc->oam2 << 3));
	}
}

void SioPostBattleSprites_Loop_DrawStatic(struct SioPostBattleSpritesProc * proc)
{
	PutSprite(4, proc->x, proc->y - 16, SpriteArray_Sio_085C9D08[proc->ranking], 0);
	PutSprite(4, proc->x + 72, proc->y - 6, SpriteArray_Sio_085C9CF8[proc->oam2], 0);
	PutSprite(4, proc->x + 96, proc->y + 8, Sprite_Sio_0810F220, 0);
	PutSprite(4, proc->x + 64, proc->y + 8, Sprite_Sio_0810F256, proc->ranking * 4 + 0x50);
	PutSprite(4, -proc->x + 112, proc->y - 8, Sprite_Sio_0810F228, OAM2_PAL(proc->oam2) + 0x400);
	PutSprite(4, -proc->x + 124, proc->y, Sprite_Sio_0810F242, proc->oam2 == 3 ? 0x40 : proc->oam2 * 9);
	PutSprite(5, -proc->x + 208, proc->y - 8, Sprite_Sio_0810F25E, OAM2_PAL(proc->oam2 + 10) + 0x180 + (proc->oam2 << 3));
}

ProcPtr StartDrawLinkArenaRankSprites(struct SioPostBattleProc * parent, int delay, u16 fid, u8 oam2, u8 ranking)
{
	struct SioPostBattleSpritesProc * proc = SpawnProc(ProcScr_LinkArenaPostBattle_DrawSprites, parent);

	proc->unk_2C = parent;
	proc->delay = delay;
	proc->fid = fid;
	proc->ranking = ranking;
	proc->oam2 = oam2;

	return proc;
}

i16 const gUnk_Sio_0810F26C[5][4] =
{
	{ -1, -1, -1, -1 },
	{ -1, -1, -1, -1 },
	{ 7, 13, -1, -1 },
	{ 5, 10, 15, -1 },
	{ 2, 7, 12, 17 },
};

void func_fe6_08038D64(struct SioPostBattleProc * proc)
{
	int i;

	int unk_40 = proc->unk_40;
	u16 * tm = gBg2Tm;

	if (proc->player_id == proc->unk_44[proc->unk_41 - 1].player_id) {
		TmApplyTsa(tm + TM_OFFSET(0, gUnk_Sio_0810F26C[unk_40][proc->unk_41 - 1]), gUnk_08109CC0, TILEREF(0x60, 2));
	} else {
		for (i = 0; i < 0x60; i++)
			tm[TM_OFFSET(i, gUnk_Sio_0810F26C[unk_40][proc->unk_41 - 1])] = 0x1034;
	}
}

void func_fe6_08038DEC(struct SioPostBattleProc * proc)
{
	int i;

	int unk_40 = proc->unk_40;
	SetTextFont(&gSioSpriteFont);

	for (i = 0; i < unk_40; i++) {
		char * str = gLinkArenaSt.unk_A1[i];

		int len = GetStringTextLen(str);
		len = (72 - len) / 2;

		if (i < 3)
			Text_InsertDrawString(&gSioLineTexts[0], 72 * i + len, TEXT_COLOR_SYSTEM_WHITE, str);
		else
			Text_InsertDrawString(&gSioLineTexts[1], len, TEXT_COLOR_SYSTEM_WHITE, str);

		Text_InsertDrawNumberOrBlank(&gSioLineTexts[1], i * 32 + 152, TEXT_COLOR_SYSTEM_BLUE, proc->unk_44[i].points);
	}
}

ProcPtr SioPostBattle_StartMusicProc(struct SioPostBattleProc * parent)
{
	struct SioPostBattleMusicProc * proc = SpawnProc(ProcScr_SioPostBattle_PlayMusic, parent);

	if (parent->player_id == parent->unk_44[0].player_id)
		proc->is_player_winner = 1;
	else
		proc->is_player_winner = 0;

	return proc;
}

void SioPostBattle_Init(struct SioPostBattleProc * proc)
{
	int i;

	ClearSioBG();
	InitSioBG();

	Decompress(Img_TacticianSelObj, OBJ_VRAM0 + 0x4800);
	Decompress(Img_LinkArenaPlayerBanners, OBJ_VRAM0 + 0x6000);
	Decompress(Img_LinkArenaPlacementRanks, OBJ_VRAM0 + 0x6800);

	ApplyPalettes(Pal_TacticianSelObj, 0x13, 4);
	ApplyPalette(Pal_LinkArenaPlacementRanks, 0x17);

	Decompress(Img_LinkArenaActiveBannerFx, (u8 *)BG_VRAM + 0xC00);
	ApplyPalette(Pal_LinkArenaActiveBannerFx, 2);

	Decompress(Img_LinkArenaPostBattleBg, (u8 *)BG_VRAM + GetBgChrOffset(BG_3));
	ApplyPalettes(Pal_LinkArenaPostBattleBg, 10, 4);
	TmApplyTsa(gBg3Tm, Tsa_LinkArenaPostBattleBg, 0);

	InitSpriteTextFont(&gSioSpriteFont, OBJ_VRAM0 + 0x2000, 0xE);
	ApplyPalette(Pal_Text, 0x1E);
	SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);
	ResetTextFont();

	for (i = 0; i < 2; i++) {
		InitSpriteText(&gSioLineTexts[i]);
		SpriteText_DrawBackgroundExt(&gSioLineTexts[i], 0);
	}

	proc->unk_40 = gSioSt->unk_007;
	proc->unk_41 = gSioSt->unk_007;
	proc->player_id = gSioSt->self_id;

	CpuFill16(0, proc->unk_44, sizeof(proc->unk_44));
	func_fe6_0803C094(proc->unk_44);

	func_fe6_08038DEC(proc);

	proc->unk_64 = 176;

	SetBgOffset(BG_2, 0, 176);

	SetWinEnable(0, 0, 0);

	SetBlendAlpha(8, 8);
	SetBlendTargetA(0, 0, 1, 0, 0);
	SetBlendTargetB(0, 0, 0, 1, 0);

	SioPostBattle_StartMusicProc(proc);

	EnableBgSync(BG3_SYNC_BIT);
}

void SioPostBattle_Loop_Main(struct SioPostBattleProc * proc)
{
	int fid;

	int unk_40 = proc->unk_40;

	proc->unk_64--;
	SetBgOffset(BG_2, 0, proc->unk_64);

	func_fe6_08040F70();

	if (proc->unk_41 != 0) {
		if ((proc->unk_64 >> 3) == gUnk_Sio_0810F26C[unk_40][proc->unk_41 - 1] + 4) {
			func_fe6_08038D64(proc);
			EnableBgSync(BG2_SYNC_BIT);

			fid = gSioBmSt.unk_24[proc->unk_44[proc->unk_41 - 1].player_id];
			proc->unk_2C[proc->unk_41 - 1] = StartDrawLinkArenaRankSprites(
				proc, 40, fid, proc->unk_44[proc->unk_41 - 1].player_id, proc->unk_41 - 1);

			proc->unk_41--;
		}
	}

	if (proc->unk_64 == 0)
		Proc_Break(proc);
}

void SioPostBattle_AwaitAPress(ProcPtr proc)
{
	func_fe6_08040F70();

	if (gKeySt->pressed & KEY_BUTTON_A) {
		m4aMPlayFadeOut(gMusicPlayerTable[gSongTable[SONG_81].ms].music_player, 1);
		Proc_Break(proc);
	}
}

void SioPostBattleMusic_PlayFanfare(struct SioPostBattleMusicProc * proc)
{
	if (proc->is_player_winner != 0)
		StartBgmExt(SONG_46, 0, NULL);
	else
		StartBgmExt(SONG_4A, 0, NULL);

	PlaySe(SONG_81);
}

void SioPostBattleMusic_PlayStandardBgm(void)
{
	StartBgmExt(SONG_4A, 0, NULL);
}

int func_fe6_080391C0(u8 ranking, u32 player_count, u32 mode, u32 points)
{
	u32 min_points;
	int i, slot;

	min_points = points;

	for (i = 0; i < MULTIARENA_MAX_RANKINGS; i++) {
		if (gSioResultRankings[i].points >= min_points)
			continue;

		slot = i;
		i = MULTIARENA_MAX_RANKINGS - 1;

		if (i <= slot)
			goto write;
		else
			goto shift;
	}

	return -1;

shift:
	for (i = MULTIARENA_MAX_RANKINGS - 1; i > slot; i--) {
		gSioResultRankings[i].ranking = gSioResultRankings[i - 1].ranking;
		gSioResultRankings[i].points = gSioResultRankings[i - 1].points;
		gSioResultRankings[i].player_count = gSioResultRankings[i - 1].player_count;
		gSioResultRankings[i].mode = gSioResultRankings[i - 1].mode;
		SioStrCpy(gSioResultRankings[i - 1].name, gSioResultRankings[i].name);
	}

write:
	gSioResultRankings[slot].ranking = ranking;
	gSioResultRankings[slot].points = points;
	gSioResultRankings[slot].player_count = player_count;
	gSioResultRankings[slot].mode = mode;

	SioStrCpy(gLinkArenaSt.unk_A1[gSioSt->self_id], gSioResultRankings[slot].name);

	return slot;
}

void func_fe6_080392F4(struct SioBatProc * proc)
{
	int mode = gLinkArenaSt.rules.unk_0_1;
	int player_count = gLinkArenaSt.unk_A0 - 1;
	u8 ranking = func_fe6_0803D208();
	int points = gSioBmSt.current_score[gSioSt->self_id];

	ReadMultiArenaSaveRankings(gSioResultRankings);

	proc->unk_58 = func_fe6_080391C0(ranking, player_count, mode, points);

	WriteMultiArenaSaveRankings(gSioResultRankings);

	if (proc->unk_58 != -1)
		StartSioResultNewHighScore(proc->unk_58, proc);
	else
		FadeBgmOut(1);
}

void func_fe6_08039388(void)
{
	struct SioSaveConf * conf = &gSioSaveConfig;
	int i, j;

	u8 player_counts[] = { 3, 7, 15 };

	InitUnits();

	for (i = 0; i < gLinkArenaSt.unk_05 + 2; i++) {
		int id = i * 0x40 + 1;

		struct Unit * unit = GetUnit(id);
		ReadMultiArenaSaveTeam(gLinkArenaSt.unk_06[i], unit, gSioTeamNames[i]);

		gLinkArenaSt.unk_05 = gLinkArenaSt.unk_05;

		for (j = 0; j < 5; j++) {
			unit = GetUnit(id + j);

			unit->exp = 0;
			SetUnitStatus(unit, UNIT_STATUS_NONE);
			unit->rescue = 0;

			if (!conf->unk_2)
				SioSetNormalWeapons(unit);
			else
				SioSetUniqueWeapons(unit);

			if (j == 0)
				gSioBmSt.unk_24[i] = GetUnitChibiId(unit);

			unit->id = id + j;

			if (i != 0 && !conf->unk_0)
				unit->flags = UNIT_FLAG_CONCEALED;
		}
	}

	gSioBmSt.unk_00 = 0;

	gSioSt->self_id = 0;
	gSioSt->unk_009 = player_counts[gLinkArenaSt.unk_05];
	gSioSt->unk_007 = gLinkArenaSt.unk_05 + 2;

	gLinkArenaSt.unk_A0 = gLinkArenaSt.unk_05 + 2;
}

void NewSIOMAIN2(void)
{
	SpawnProc(ProcScr_SIOMAIN2, PROC_TREE_2);
}

void SIOPRA_BranchAfterMain2(ProcPtr proc)
{
	if (FindProc(ProcScr_SIOMAIN2) != NULL)
		return;

	if (gLinkArenaSt.unk_0B == 1)
		Proc_Goto(proc, 1);

	if (gLinkArenaSt.unk_0B == 2)
		Proc_Goto(proc, 4);

	Proc_Break(proc);
}

void func_fe6_080394FC(char const * str, int x, int y, ProcPtr parent)
{
	SetInitTalkTextFont();
	ClearTalkText();
	ResetTextFont();

	StartTalkExt(x, y, str, parent);

	SetTalkPrintColor(1);

	SetTalkFlag(TALK_FLAG_INSTANTSHIFT);
	SetTalkFlag(TALK_FLAG_NOBUBBLE);
	SetTalkFlag(TALK_FLAG_NOSKIP);

	SetTalkPrintDelay(2);

	SetActiveTalkFace(1);
}

void SioBat_EndHandler(void)
{
	Proc_EndEach(ProcScr_SIOVSYNC);
	Proc_EndEach(ProcScr_SIOMAIN);
	Proc_EndEach(ProcScr_SIOCON);
}

void SioBat_ReleaseIrq(void)
{
	SioReleaseIrq();
}

void func_fe6_08039580(void)
{
	int i;

	for (i = 0; i < 4; i++) {
		if (gLinkArenaSt.linking_status[i] != gSioSt->player_status[i]) {
			gLinkArenaSt.linking_status[i] = gSioSt->player_status[i];

			ClearText(&gLinkArenaSt.texts[i]);
			Text_SetColor(&gLinkArenaSt.texts[i], 0);

			if (gLinkArenaSt.linking_status[i] < 5) {
				PutDrawTextCentered(&gLinkArenaSt.texts[i], 10, 5 + i * 3, gUnk_Sio_085C99B0[gLinkArenaSt.linking_status[i]], 10);
				ApplyPaletteExt(gUnk_08109C60, (0x13 + i) * 0x20, 0x20);
			} else {
				PutDrawTextCentered(&gLinkArenaSt.texts[i], 10, 5 + i * 3, gLinkArenaSt.unk_A1[i], 10);
				ApplyPaletteExt(Pal_TacticianSelObj + i * 0x10, (0x13 + i) * 0x20, 0x20);
			}

			EnableBgSync(BG0_SYNC_BIT);
		}
	}
}

void func_fe6_08039650(struct SioBatProc * proc)
{
	int i;
	char buf[0x10];

	ClearSioBG();
	InitSioBG();

	Decompress(Img_TacticianSelObj, OBJ_VRAM0 + 0x240 * CHR_SIZE);
	Decompress(Img_LinkArenaPlayerBanners, OBJ_VRAM0 + 0x300 * CHR_SIZE);
	Decompress(Img_Sio_081080D4, OBJ_VRAM0 + 0x340 * CHR_SIZE);

	for (i = 0; i < 4; i++)
		ApplyPaletteExt(gUnk_08109C60, (0x13 + i) * 0x20, 0x20);

	Sio_RestartBgSlide(0, 2);

	ReadMultiArenaSaveTeamName(gLinkArenaSt.unk_03, buf);

	SetTextFont(&gSioFont);
	InitSystemTextFont();
	ResetTextFont();
	func_fe6_08036C60();

	for (i = 0; i < 4; i++)
		gLinkArenaSt.linking_status[i] = 0xFF;

	func_fe6_08039580();

	for (i = 0; i < 15; i++)
		gSioBuf_030044E0.bytes[i] = buf[i];

	proc->unk_34 = 0;
	proc->unk_30 = 0;

	StartLinkArenaButtonSpriteDraw(0xC0, 0x10, proc);
	proc->unk_2C = StartLinkArenaVersusSpriteDraw(0x48, 0x20, proc);

	SetFaceConfig(gUnk_Sio_085C9E88);
	StartFace(3, FID_C0, 0xD0, 0x50, 2);

	StartLinkArenaTitleBanner(proc->unk_2C, gUnk_Sio_0810F19C[gLinkArenaSt.unk_00]);
	func_fe6_0803FD40(gUnk_Sio_085C9AD4[gLinkArenaSt.unk_00], gUnk_Sio_0810F190[gLinkArenaSt.unk_00], 0, 8, gLinkArenaSt.unk_00, proc->unk_2C);

	SioPutText(MSG_6D7 + proc->unk_30, 1);

	SetWinEnable(0, 0, 0);
}

void func_fe6_080397AC(ProcPtr proc)
{
	u16 data = 0x2586;

	SpawnProc(ProcScr_SIOVSYNC, PROC_TREE_VSYNC);
	SpawnProc(ProcScr_SIOMAIN, proc);
	SpawnProc(ProcScr_SIOCON, proc);

	SioSend16(&data, -1);
}

void func_fe6_080397F4(struct SioBatProc * proc)
{
	int i;
	u8 buf[4];
	u8 recv_buf[4];

	int timeouts = 0;
	u16 got = 0;
	struct SioBatProc_Unk2C * unk_2C = proc->unk_2C;

	gSioWaitTimer = 0;
	buf[0] = 0;

	func_fe6_08039580();

	if (FindProc(ProcScr_SIOCON) != NULL) {
		if ((gKeySt->pressed & KEY_BUTTON_B) == 0)
			return;

		SioPlaySe(1);
		EndLinkArenaButtonSpriteDraw();
		goto end_link;
	}

	EndLinkArenaButtonSpriteDraw();

	unk_2C->unk_34 = gSioSt->self_id;

	for (i = 0; i < 4; i++) {
		if (gSioSt->timeout_clock[i] > 60)
			timeouts++;
	}

	if (gSioSt->player_status[gSioSt->self_id] == PLAYER_STATUS_2) {
	end_link:
		SioBat_EndHandler();
		SioBat_ReleaseIrq();
		Proc_Goto(proc, 2);
		return;
	}

	if (!func_fe6_08035CF8() || gSioSt->unk_01E > 60 || timeouts != 0) {
		SioBat_EndHandler();
		SioBat_ReleaseIrq();
		func_fe6_080397AC(proc);
		proc->unk_30 = 0;
		SioPutText(MSG_6D7, 1);
		StartLinkArenaButtonSpriteDraw(0xC0, 0x10, proc);
		return;
	}

	if (gSioSt->self_id == 0 && func_fe6_08035D7C() == 1) {
		if (proc->unk_30 != 2) {
			proc->unk_30 = 2;
			SioPutText(MSG_6D9, 1);
		}

		if (gKeySt->pressed & KEY_BUTTON_START) {
			gSioSt->unk_004 = 6;
			gSioSt->unk_01E = 0;

			for (i = 0; i < 4; i++)
				gSioSt->timeout_clock[i] = 0;

			SioPlaySe(2);

			gSioSt->unk_007 = func_fe6_08035C58();
			gLinkArenaSt.unk_A0 = gSioSt->unk_007;
			func_fe6_08036608();

			buf[0] = SIO_MSG_18;
			proc->unk_34 = SioEmitData(buf, 4);

			Proc_Break(proc);
			return;
		}
	} else if (proc->unk_30 != 1) {
		proc->unk_30 = 1;
		SioPutText(MSG_6D8, 1);
	}

	if (gSioSt->self_id != 0 && func_fe6_08035CB0(gSioSt->self_id)) {
		got = SioReceiveData(buf, recv_buf, NULL);

		if (got != 0) {
			gSioSt->unk_004 = 6;
			gSioSt->unk_01E = 0;

			for (i = 0; i < 4; i++)
				gSioSt->timeout_clock[i] = 0;

			gSioSt->unk_007 = func_fe6_08035C58();
			gLinkArenaSt.unk_A0 = gSioSt->unk_007;
			func_fe6_08036608();

			Proc_Break(proc);
			return;
		}
	}

	if ((GetGameTime() % 38) != 0)
		return;

	gSioBuf_030044E0.head.kind = SIO_MSG_1C;
	gSioBuf_030044E0.head.sender = gSioSt->self_id;
	gSioBuf_030044E0.head.param = gSioSt->unk_000;

	SioSend(&gSioBuf_030044E0, 0x16);
}

void func_fe6_08039A1C(struct SioBatProc * proc)
{
	func_fe6_08039580();

	gSioWaitTimer++;

	if (gLinkArenaSt.unk_A0 != gSioSt->unk_007 || gSioWaitTimer > 600) {
		SioBat_EndHandler();
		SioBat_ReleaseIrq();
		func_fe6_080397AC(proc);

		proc->unk_30 = 0;

		SioPutText(MSG_6D7, 1);
		StartLinkArenaButtonSpriteDraw(0xC0, 0x10, proc);

		Proc_Goto(proc, 3);

		goto break_proc;
	} else if (gSioSt->self_id == 0) {
		if ((gSioSt->pending_send[proc->unk_34].unk_00 & gSioSt->unk_009) == gSioSt->unk_009) {
		break_proc:
			Proc_Break(proc);
		}

		return;
	}

	Proc_Break(proc);
}

void func_fe6_08039ABC(struct SioBatProc * proc)
{
	u8 buf[0x10];

	SioPutText(MSG_6D8, 1);

	if (gSioSt->self_id == 0) {
		proc->unk_3B = GetGameTime() % gLinkArenaSt.unk_A0;
		proc->unk_39 = gLinkArenaSt.unk_A0 * ((RandNextB() & 3) + 4) + proc->unk_3B;

		buf[0] = gLinkArenaSt.rules.unk_0_0;
		buf[1] = gLinkArenaSt.rules.unk_0_2;
		buf[2] = gLinkArenaSt.rules.unk_0_1;
		buf[3] = proc->unk_3B;
		buf[4] = proc->unk_39;

		RandGetSt((u16 *) (buf + 6));

		proc->unk_34 = SioEmitData(buf, sizeof(buf));
	}

	proc->unk_3A = 0;
	proc->unk_38 = 0;
}

void func_fe6_08039B5C(struct SioBatProc * proc)
{
	u16 got;
	struct SioBatProc_Unk2C * unk_2C;
	u8 buf[0x10];
	u8 sender[4];

	unk_2C = proc->unk_2C;

	if (gSioSt->self_id == 0) {
		if (gSioSt->pending_send[proc->unk_34].unk_00 == gSioSt->unk_009) {
			SioPutText(MSG_6DD, 1);
			unk_2C->unk_38 = 0;
			Proc_Break(proc);
		}
	} else {
		if ((GetGameTime() % 38) == 0) {
			got = SioReceiveData(buf, sender, NULL);

			if (got != 0) {
				gLinkArenaSt.rules.unk_0_0 = buf[0];
				gLinkArenaSt.rules.unk_0_2 = buf[1];
				gLinkArenaSt.rules.unk_0_1 = buf[2];

				proc->unk_3B = buf[3];
				proc->unk_39 = buf[4];
				RandSetSt((u16 *) (buf + 6));

				SioPutText(MSG_6DD, 1);
				unk_2C->unk_38 = 0;
				Proc_Break(proc);
			}
		}
	}
}

void func_fe6_08039C30(struct SioBatProc * proc)
{
	struct SioBatProc_Unk2C * unk_2C = proc->unk_2C;

	proc->unk_38++;

	if (proc->unk_38 > 16) {
		proc->unk_38 = 0;
		proc->unk_3A++;
		proc->unk_3A = proc->unk_3A % gLinkArenaSt.unk_A0;
		proc->unk_39--;
		unk_2C->unk_38 = proc->unk_3A;

		PlaySe(SONG_7D);

		if (proc->unk_39 == 0) {
			if (proc->unk_3B != gSioSt->self_id)
				SioPutText(MSG_6DF + proc->unk_3B, 1);
			else
				SioPutText(MSG_6DE, 1);

			unk_2C->unk_38 = proc->unk_3B;

			gSioBmSt.unk_00 = proc->unk_3B;
			Proc_Break(proc);
		}
	}
}

void func_fe6_08039CE0(void)
{
	PlaySe(SONG_7E);
}

void func_fe6_08039CFC(struct Unit * unit)
{
	unit->exp = 0;
	SetUnitStatus(unit, 0);
	unit->rescue = 0;

	if (gLinkArenaSt.rules.unk_0_2 == 0)
		SioSetNormalWeapons(unit);
	else
		SioSetUniqueWeapons(unit);
}

void func_fe6_08039D34(struct SioBatProc * proc)
{
	int i;

	int base = gSioSt->self_id * 0x40 + 1;
	gSioWaitTimer = 0;

	InitUnits();
	ReadMultiArenaSaveTeamRaw(gLinkArenaSt.unk_03, gUnk_Sio_085C9EA8);

	for (i = 0; i < 5; i++) {
		struct Unit * unit = GetUnit(base + i);

		ClearUnit(unit);
		ReadGameSavePackedUnit(&gUnk_Sio_085C9EA8->units[i], unit);

		func_fe6_08039CFC(unit);

		unit->id = base + i;

		if (i == 0)
			gSioBmSt.unk_24[gSioSt->self_id] = GetUnitChibiId(unit);
	}

	for (i = 0; i < 4; i++)
		gLinkArenaSt.linking_status[i] = 0;

	gSioSt->unk_00A = 1 << gSioSt->self_id;

	proc->unk_64 = 0;
	proc->unk_4C = 0;
}

void func_fe6_08039E04(struct SioBatProc * proc)
{
	int i;
	u8 buf[0x28];
	u8 sender[4];

	u8 unk = 0;

	if (proc->unk_4C == 0)
		PlaySe(SONG_7C);

	proc->unk_4C++;

	if (proc->unk_4C > 23)
		proc->unk_4C = 0;

	if (proc->unk_64 < 5) {
		proc->unk_58 = (u8) SioEmitData((u8 *) &gUnk_Sio_085C9EA8->units[proc->unk_64], 0x28);
		proc->unk_64++;
		gLinkArenaSt.linking_status[gSioSt->self_id] = proc->unk_64;
	}

	if ((GetGameTime() % 38) == 0) {
		u16 got = SioReceiveData(buf, sender, NULL);

		if (got != 0) {
			int base = sender[0] * 0x40 + 1;
			struct Unit * unit = GetUnit(base + gLinkArenaSt.linking_status[sender[0]]);

			ClearUnit(unit);
			ReadGameSavePackedUnit(buf, unit);
			func_fe6_08039CFC(unit);

			unit->id = gLinkArenaSt.linking_status[sender[0]] + base;

			if (gLinkArenaSt.linking_status[sender[0]] == 0)
				gSioBmSt.unk_24[sender[0]] = GetUnitChibiId(unit);

			if (gLinkArenaSt.rules.unk_0_0 == 0)
				unit->flags = UNIT_FLAG_CONCEALED;

			gLinkArenaSt.linking_status[sender[0]]++;
		}

		for (i = 0; i < 4; i++) {
			if (func_fe6_08035CB0(i) && gLinkArenaSt.linking_status[i] < 5)
				unk++;
		}

		if (unk == 0) {
			gSioSt->unk_00A = 1 << gSioSt->self_id;
			Proc_Break(proc);
		}
	}
}

void func_fe6_08039F84(struct SioBatProc * proc)
{
	if (proc->unk_4C == 0)
		PlaySe(SONG_7C);

	proc->unk_4C++;

	if (proc->unk_4C > 23)
		proc->unk_4C = 0;

	gSioWaitTimer++;

	if (gSioWaitTimer > 600)
		StartSioErrorScreen();

	gSioMsgBuf.kind = SIO_MSG_19;
	gSioMsgBuf.sender = gSioSt->self_id;
	gSioMsgBuf.param = 0;

	SioSend(&gSioMsgBuf, sizeof(gSioMsgBuf));

	if (gSioSt->pending_send[proc->unk_58].unk_00 == gSioSt->unk_009 &&
		(gSioSt->unk_00A & gSioSt->unk_009) == gSioSt->pending_send[proc->unk_58].unk_00) {
		Proc_EndEach(gUnk_Sio_085C99C8);
		Proc_Break(proc);
	}
}

void func_fe6_0803A028(ProcPtr proc)
{
	ClearSioBG();
	InitSioBG();

	EndLinkArenaVersusSpriteDraw();
	EndFaceById(3);

	ClearText(&gLinkArenaSt.texts[9]);
	Text_SetColor(&gLinkArenaSt.texts[9], TEXT_COLOR_SYSTEM_WHITE);
	Text_DrawString(&gLinkArenaSt.texts[9], SioText_NowLoading);
	PutText(&gLinkArenaSt.texts[9], gBg2Tm + TM_OFFSET(9, 12));

	SpawnProc(gUnk_Sio_085C99C8, proc);

	Sio_RestartBgSlide(0, 0);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

const struct LinkArenaRuleInfo gLinkArenaRuleData[] = {
	{ SioText_HideUnits,        { 14, 17 }, { SioText_On,     SioText_Off      } },
	{ SioText_VictoryCondition, { 16, 23 }, { SioText_Points, SioText_Survival } },
	{ SioText_AutoWeapons,      { 14, 17 }, { SioText_On,     SioText_Off      } },
};

void func_SioBat_0803A08C(ProcPtr proc)
{
	int i;
	u8 buf[4];

	ClearSioBG();
	InitSioBG();

	Decompress(Img_LinkArenaRankIcons, (u8 *)BG_VRAM + 0xC00 + GetBgChrOffset(BG_1));
	ApplyPalette(Pal_LinkArenaRankIcons, 6);

	Decompress(Img_TacticianSelObj, OBJ_VRAM0 + 0x4800);
	ApplyPalettes(Pal_TacticianSelObj, 0x13, 4);

	func_fe6_0803FB08(0);

	SetTextFont(&gSioFont);
	ResetTextFont();

	func_fe6_08036C60();
	LoadLinkArenaRuleSettings(buf);

	SetBgOffset(BG_1, 0xFE, 0);

	for (i = 0; i < 3; i++) {
		ClearText(&gLinkArenaSt.texts[i]);
		Text_SetColor(&gLinkArenaSt.texts[i], TEXT_COLOR_SYSTEM_WHITE);
		Text_DrawString(&gLinkArenaSt.texts[i], gLinkArenaRuleData[i].label);
		PutText(&gLinkArenaSt.texts[i], gBg0Tm + TM_OFFSET(6, 6 + i * 3));

		func_fe6_0803AED0(i, buf[i]);
	}

	DrawLinkArenaModeIcon(gBg1Tm + TM_OFFSET(30, 8) + gLinkArenaRuleData[1].x_pos[0], 0);
	DrawLinkArenaModeIcon(gBg1Tm + TM_OFFSET(30, 8) + gLinkArenaRuleData[1].x_pos[1], 1);

	StartLinkArenaTitleBanner(proc, gUnk_Sio_0810F19C[gLinkArenaSt.unk_00]);

	func_fe6_0803FD40(gUnk_Sio_085C9AD4[gLinkArenaSt.unk_00], gUnk_Sio_0810F190[gLinkArenaSt.unk_00], 0, 8, gLinkArenaSt.unk_00, proc);

	SioPutText(0x6DA, 1);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

void XMapTransfer_0803A1E4(void)
{
	SetXmapTransferState(3);
}

void XmapTransfer_End(void)
{
	SetXmapTransferState(0);
}

void SioTerm_Init(struct SioTermProc * proc)
{
	struct PlaySt play_st;
	int local_38 = 0;
	u8 banner_list[] = { 0x12, 0x04, 0x13, 0x14, 0x0F, 0x19 };
	int flags[3];
	int i;

	ClearSioBG();
	InitSioBG();

	Decompress(Img_TacticianSelObj, OBJ_VRAM0 + 0x4800);

	Sio_RestartBgSlide(0, 4);

	SetTextFont(&gSioFont);
	InitSystemTextFont();
	ResetTextFont();

	StartLinkArenaButtonSpriteDraw(0xC0, 0x10, proc);

	InitText(&gSioTexts[0], 24);
	InitText(&gSioTexts[1], 24);

	SioPutText(0x6DB, 0);
	SioPutText(0x6DC, 1);

	proc->unk_4C = -1;

	for (i = 2; i >= 0; i--) {
		flags[i] = 0;

		if (IsSaveValid(i)) {
			ReadGameSavePlaySt(i, &play_st);
			proc->unk_2C[i] = GetChapterTitleExtra(&play_st);

			if (play_st.flags & PLAY_FLAG_HARD)
				flags[i] = 2;

			if (IsGameSavePastFirstChapter(i))
				proc->unk_38[i] = proc->unk_2C[i];
			else
				proc->unk_38[i] = -1;

			if (proc->unk_38[i] != -1) {
				if (local_38 == 0) {
					proc->unk_50 = i;
					local_38 = 1;
				} else {
					proc->unk_4C = i;
				}
			}
		} else {
			proc->unk_2C[i] = proc->unk_38[i] = -1;
		}
	}

	if (proc->unk_4C == -1) {
		proc->unk_4C = proc->unk_50;
		proc->unk_48 = proc->unk_50;
	} else {
		proc->unk_48 = proc->unk_4C;
	}

	PutChapterTitlePalettle(1, 4);
	PutChapterTitlePalettle(3, 5);
	PutChapterTitlePalettle(5, 6);
	PutChapterTitlePalettle(0, 7);
	PutChapterTitlePalettle(2, 8);
	PutChapterTitlePalettle(4, 9);

	PutChapterTitleBG1(0x1A0);

	for (i = 0; i < 3; i++) {
		if (proc->unk_38[i] == -1)
			flags[i] = 1;
		else if (flags[i] != 2)
			flags[i] = 0;

		PutChapterTitleBgTSA(gBg1Tm + TM_OFFSET(3, 4 + i * 4), flags[i] + 4);
		PutChapterTitleGfx(((0x800 * (u32)i + 0x4400) & 0x1FFFF) / 0x20, proc->unk_2C[i]);
		PutChapterTitleTextTSA(gBg0Tm + TM_OFFSET(3, 5 + i * 4), flags[i] + 7);
	}

	SetWinEnable(0, 0, 0);

	StartLinkArenaTitleBanner(proc, 1);
	func_fe6_0803FD40(banner_list, 6, 0, 8, gLinkArenaSt.unk_00, proc);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

void func_fe6_0803A468(int * cur, u8 bottom, u8 top, int * buf, u8 total)
{
	if ((gKeySt->repeated & KEY_DPAD_UP) && (*cur > top || gKeySt->repeated == gKeySt->pressed)) {
		do {
			*cur -= 1;

			if (*cur < 0)
				*cur = total - 1;
		} while (buf[*cur] == -1);
	}

	if ((gKeySt->repeated & KEY_DPAD_DOWN) && (*cur < bottom || gKeySt->repeated == gKeySt->pressed)) {
		do {
			*cur += 1;
			*cur = *cur % total;
		} while (buf[*cur] == -1);
	}
}

void func_fe6_0803A4F4(struct SioTermProc * proc)
{
	int current = proc->unk_48;

	func_fe6_0803A468(&proc->unk_48, proc->unk_50, proc->unk_4C, proc->unk_38, 3);
	PutUiHand(24, 40 + proc->unk_48 * 32);

	if (current != proc->unk_48)
		SioPlaySe(3);

	if (gKeySt->pressed & KEY_BUTTON_A) {
		SioPlaySe(2);
		Proc_Break(proc);
	}

	if (gKeySt->pressed & KEY_BUTTON_B) {
		SioPlaySe(1);
		Proc_Goto(proc, 4);
	}
}

void func_fe6_0803A570(struct SioTermProc * proc)
{
	ReadGameSave(proc->unk_48);

	gPlaySt.flags &= ~PLAY_FLAG_COMPLETE;
	gPlaySt.config_window_theme = 0;

	gLinkArenaSt.unk_04 = proc->unk_48;

	ApplyUnitSpritePalettes();
	func_fe6_0803CE7C();
}

void func_fe6_0803A5AC(ProcPtr proc)
{
	if (gLinkArenaSt.unk_03 == 0xFF)
		Proc_Goto(proc, 1);
}

void func_fe6_0803A5C8(ProcPtr proc)
{
	if (gLinkArenaSt.unk_04 == 0xFF)
		Proc_Goto(proc, 2);
}

void SioTerm_WaitAtMenu(ProcPtr proc)
{
	if (FindProc(ProcScr_AtMenu) == NULL)
		Proc_Break(proc);
}

void func_fe6_0803A604(ProcPtr proc)
{
	if (gUnk_Sio_0203C918 == 0)
		return;

	ClearSioAllBGs();
	Sio_EndBackgroundSlide();
	func_fe6_0803FC60();
	func_fe6_0803FDD8();
	EndLinkArenaButtonSpriteDraw();
	StartPrepAtMenu();

	Proc_Goto(proc, 5);
}

void DrawLinkArenaRankIcon(u16 * tm, int rank)
{
	u16 ref = rank * 3 + TILEREF(0x60, 4);

	if (rank > 2)
		ref += TILEREF(0, 1);

	tm[TM_OFFSET(0, 0)] = ref;
	tm[TM_OFFSET(1, 0)] = ref + 1;
	tm[TM_OFFSET(2, 0)] = ref + 2;
	tm[TM_OFFSET(0, 1)] = ref + 0x20;
	tm[TM_OFFSET(1, 1)] = ref + 0x21;
	tm[TM_OFFSET(2, 1)] = ref + 0x22;
}

void DrawLinkArenaModeIcon(u16 * tm, int mode)
{
	u16 ref = mode * 4 + 0xA0;

	tm[TM_OFFSET(0, 0)] = TILEREF(ref, 6);
	tm[TM_OFFSET(1, 0)] = TILEREF(ref + 1, 6);
	tm[TM_OFFSET(0, 1)] = TILEREF(ref + 2, 6);
	tm[TM_OFFSET(1, 1)] = TILEREF(ref + 3, 6);
}

void DrawLinkArenaRankingRow(struct Text * text, char const * name, u8 rank, u16 points, u8 player_count)
{
	Text_InsertDrawString(text, 8, TEXT_COLOR_SYSTEM_WHITE, name);
	Text_InsertDrawNumberOrBlank(text, 0x60, TEXT_COLOR_SYSTEM_BLUE, points);
	Text_InsertDrawString(text, 0x68, TEXT_COLOR_SYSTEM_WHITE, "Ｐ");
	Text_InsertDrawNumberOrBlank(text, 0x86, TEXT_COLOR_SYSTEM_BLUE, rank);
	Text_InsertDrawString(text, 0x8E, TEXT_COLOR_SYSTEM_WHITE, "位");
	Text_InsertDrawNumberOrBlank(text, 0x9C, TEXT_COLOR_SYSTEM_BLUE, player_count);
	Text_InsertDrawString(text, 0xA4, TEXT_COLOR_SYSTEM_WHITE, "人");
}

void DrawLinkArenaRankings(void)
{
	int i;

	for (i = 0; i < 10; i++) {
		ClearText(&gSioLineTexts[i]);

		DrawLinkArenaRankingRow(
			&gSioLineTexts[i], gSioResultRankings[i].name, gSioResultRankings[i].ranking + 1,
			gSioResultRankings[i].points, gSioResultRankings[i].player_count + 1);

		DrawLinkArenaRankIcon(gBg1Tm + TM_OFFSET(2, i * 2), i);
		PutText(&gSioLineTexts[i], gBg1Tm + TM_OFFSET(5, i * 2));
		DrawLinkArenaModeIcon(gBg1Tm + TM_OFFSET(20, i * 2), gSioResultRankings[i].mode);
	}
}

void SioResult_Init(struct SioResultProc * proc)
{
	int i;
	u8 banner[] = { 0x11, 0x00, 0x0D, 0x0A, 0x08, 0x0D, 0x06, 0x19 };

	ClearSioBG();
	InitSioBG();

	Decompress(Img_LinkArenaRankIcons, (u8 *)BG_VRAM + 0xC00 + GetBgChrOffset(BG_1));
	ApplyPaletteExt(gUnk_08109AC0, 0x80, 0x40);
	ApplyPaletteExt(Pal_LinkArenaRankIcons, 0xC0, 0x20);

	Decompress(Img_TacticianSelObj, (u8 *)OBJ_VRAM0 + 0x4800);
	ApplyPaletteExt(Pal_TacticianSelObj, 0x260, 0x80);

	Sio_RestartBgSlide(0, 2);
	TmApplyTsa(gBg2Tm + TM_OFFSET(1, 4), gUnk_0810A318, TILEREF(0, 1));

	SetTextFont(&gSioFont);
	InitSystemTextFont();
	ResetTextFont();

	proc->unk_36 = 200;
	proc->unk_39 = 0;
	proc->unk_38 = 0;
	proc->unk_34 = 0;

	SetBgOffset(BG_1, 0, proc->unk_36);

	for (i = 0; i < 10; i++)
		InitText(&gSioLineTexts[i], 24);

	InitText(&gSioTexts[0], 24);
	InitText(&gSioTexts[1], 24);

	ClearText(&gSioTexts[0]);

	Text_InsertDrawString(&gSioTexts[0], 0x10, TEXT_COLOR_SYSTEM_WHITE, "チーム名");
	Text_InsertDrawString(&gSioTexts[0], 0x5E, TEXT_COLOR_SYSTEM_WHITE, "得点");
	Text_InsertDrawString(&gSioTexts[0], 0x84, TEXT_COLOR_SYSTEM_WHITE, "順位");
	Text_InsertDrawString(&gSioTexts[0], 0x9C, TEXT_COLOR_SYSTEM_WHITE, "人数");

	PutText(&gSioTexts[0], gBg0Tm + TM_OFFSET(5, 5));

	SioPutText(MSG_6D3, 1);

	ReadMultiArenaSaveRankings(gSioResultRankings);
	DrawLinkArenaRankings();

	SetWinEnable(1, 0, 0);
	SetWin0Box(0, 0x38, DISPLAY_WIDTH, 0x88);
	SetWin0Layers(1, 1, 1, 1, 1);
	SetWOutLayers(1, 0, 1, 1, 1);

	func_fe6_08040A80(0xD8, 0x38, 10, 5, proc->unk_36 + 0x38, proc);
	StartLinkArenaTitleBanner(proc, 5);
	func_fe6_0803FD40(banner, 8, 0, 8, gLinkArenaSt.unk_00, proc);
	StartLinkArenaButtonSpriteDraw(0xC0, 0x10, proc);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

void func_fe6_0803A9FC(struct SioResultProc * proc)
{
	if (proc->unk_38 > 0) {
		proc->unk_36 -= 4;
		proc->unk_38--;

		SetBgOffset(BG_1, 0, proc->unk_36);
		UpdateLinkArenaMenuScrollBar(10, proc->unk_36 + 0x38);

		return;
	}

	if (proc->unk_38 < 0) {
		proc->unk_36 += 4;
		proc->unk_38++;

		SetBgOffset(BG_1, 0, proc->unk_36);
		UpdateLinkArenaMenuScrollBar(10, proc->unk_36 + 0x38);

		return;
	}

	if ((gKeySt->repeated & KEY_DPAD_UP) && proc->unk_34 != 0) {
		SioPlaySe(3);

		proc->unk_36 -= 4;
		proc->unk_34--;

		proc->unk_38 = 3;

		SetBgOffset(BG_1, 0, proc->unk_36);
		UpdateLinkArenaMenuScrollBar(10, proc->unk_36 + 0x38);
	}

	if ((gKeySt->repeated & KEY_DPAD_DOWN) && proc->unk_34 + 5 < 10) {
		SioPlaySe(3);

		proc->unk_36 += 4;
		proc->unk_34++;

		proc->unk_38 = -3;

		SetBgOffset(BG_1, 0, proc->unk_36);
		UpdateLinkArenaMenuScrollBar(10, proc->unk_36 + 0x38);
	}

	if (gKeySt->pressed & KEY_BUTTON_B) {
		SioPlaySe(1);
		Proc_Break(proc);
	}
}

u8 func_fe6_0803AAF8(int value)
{
	int i;

	if (value > 6)
		return 5;

	i = value - 2;

	if (i < 0)
		i = 0;

	return i;
}

void SioResult_NewHS_Init(struct SioResultProc * proc)
{
	int i;
	u8 banner[] = { 0x11, 0x00, 0x0D, 0x0A, 0x08, 0x0D, 0x19 };

	ClearSioBG();
	InitSioBG();

	Decompress(Img_LinkArenaRankIcons, (u8 *)BG_VRAM + 0xC00 + GetBgChrOffset(BG_1));
	ApplyPaletteExt(gUnk_08109AC0, 0x80, 0x40);
	ApplyPaletteExt(Pal_LinkArenaRankIcons, 0xC0, 0x20);

	Decompress(Img_TacticianSelObj, (u8 *)OBJ_VRAM0 + 0x4800);
	Decompress(gUnk_08109648, (u8 *)OBJ_VRAM0 + 0x6000);
	ApplyPaletteExt(Pal_LinkArenaActiveBannerFx, 0x260, 0x20);

	Sio_RestartBgSlide(0, 0);
	TmApplyTsa(gBg2Tm + TM_OFFSET(1, 4), gUnk_0810A318, TILEREF(0, 1));

	SetTextFont(&gSioFont);
	InitSystemTextFont();
	ResetTextFont();

	proc->unk_34 = 5;
	proc->unk_36 = 280;
	proc->unk_39 = 0;
	proc->unk_38 = 0;
	proc->unk_35 = func_fe6_0803AAF8(proc->unk_3C);
	proc->unk_40 = 0;

	SetBgOffset(BG_1, 0, proc->unk_36);

	for (i = 0; i < 10; i++)
		InitText(&gSioLineTexts[i], 24);

	InitText(&gSioTexts[0], 24);
	InitText(&gSioTexts[1], 24);

	ClearText(&gSioTexts[0]);

	Text_InsertDrawString(&gSioTexts[0], 0x10, TEXT_COLOR_SYSTEM_WHITE, "チーム名");
	Text_InsertDrawString(&gSioTexts[0], 0x5E, TEXT_COLOR_SYSTEM_WHITE, "得点");
	Text_InsertDrawString(&gSioTexts[0], 0x84, TEXT_COLOR_SYSTEM_WHITE, "順位");
	Text_InsertDrawString(&gSioTexts[0], 0x9C, TEXT_COLOR_SYSTEM_WHITE, "人数");

	PutText(&gSioTexts[0], gBg0Tm + TM_OFFSET(5, 5));

	ReadMultiArenaSaveRankings(gSioResultRankings);
	DrawLinkArenaRankings();

	SetWinEnable(1, 1, 0);

	SetWin0Box(0, 0x38, DISPLAY_WIDTH, 0x88);
	SetWin0Layers(1, 1, 1, 1, 1);

	SetWin1Box(0, 0x18, DISPLAY_WIDTH, 0x38);
	SetWin1Layers(1, 0, 1, 1, 0);

	SetWOutLayers(1, 0, 1, 1, 1);

	func_fe6_0803FD40(banner, 7, 0, 8, gLinkArenaSt.unk_00, proc);

	proc->unk_2C = func_fe6_0804108C(14, proc->unk_3C * 16 - 24, proc);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

void SioResult_NewHS_LoopScroll(struct SioResultProc * proc)
{
	struct SioResultProcUnk2C * other = proc->unk_2C;

	proc->unk_40++;

	if (proc->unk_40 < 60)
		return;

	if (proc->unk_35 == 5)
		Proc_Break(proc);

	if (proc->unk_38 > 0) {
		proc->unk_36 -= 2;
		proc->unk_38--;

		SetBgOffset(BG_1, 0, proc->unk_36);
		UpdateLinkArenaMenuScrollBar(10, proc->unk_36 + 0x38);

		other->unk_30 += 2;
	} else {
		if (proc->unk_35 != proc->unk_34) {
			proc->unk_36 -= 2;
			proc->unk_34--;

			proc->unk_38 = 7;

			SetBgOffset(BG_1, 0, proc->unk_36);
			UpdateLinkArenaMenuScrollBar(10, proc->unk_36 + 0x38);

			other->unk_30 += 2;
		}

		if (proc->unk_38 == 0 && proc->unk_34 == proc->unk_35)
			Proc_Break(proc);
	}
}

void SioResult_NewHS_AwaitAPress(ProcPtr proc)
{
	if (gKeySt->pressed & KEY_BUTTON_A) {
		FadeBgmOut(0);
		Proc_Break(proc);
	}
}

void StartSioResultNewHighScore(int value, ProcPtr parent)
{
	struct SioResultProc * proc = SpawnProcLocking(ProcScr_SIORESULT_NewHighScore, parent);
	proc->unk_3C = value;
}

void LoadLinkArenaRuleSettings(u8 * buf)
{
	buf[0] = gLinkArenaSt.rules.unk_0_0;
	buf[1] = gLinkArenaSt.rules.unk_0_1;
	buf[2] = gLinkArenaSt.rules.unk_0_2;
}

void SaveLinkArenaRuleSettings(u8 * buf)
{
	gLinkArenaSt.rules.unk_0_0 = buf[0];
	gLinkArenaSt.rules.unk_0_1 = buf[1];
	gLinkArenaSt.rules.unk_0_2 = buf[2];
}

void func_fe6_0803AED0(int idx, int state)
{
	int i;
	int color_lut[2] = { TEXT_COLOR_SYSTEM_BLUE, TEXT_COLOR_SYSTEM_WHITE };

	for (i = 0; i < 2; i++) {
		ClearText(&gSioMenuTexts[idx * 2 + i]);
		Text_SetColor(&gSioMenuTexts[idx * 2 + i], color_lut[(state + i) & 1]);
		Text_DrawString(&gSioMenuTexts[idx * 2 + i], gLinkArenaRuleData[idx].option_text[i]);
		PutText(&gSioMenuTexts[idx * 2 + i], gBg0Tm + TM_OFFSET(gLinkArenaRuleData[idx].x_pos[i], 6 + idx * 3));
	}

	EnableBgSync(BG0_SYNC_BIT);
}

void SioRuleSettings_Init(struct ProcSioRuleSettings * proc)
{
	int i;
	u8 buf[4];
	u8 title[] = { 0x11, 0x14, 0x0B, 0x04, 0x04, 0x03, 0x08, 0x13, 0x19 };

	ClearSioBG();
	InitSioBG();

	Decompress(Img_LinkArenaRankIcons, (u8 *)BG_VRAM + 0xC00 + GetBgChrOffset(BG_1));
	ApplyPaletteExt(Pal_LinkArenaRankIcons, 0xC0, 0x20);

	Decompress(Img_TacticianSelObj, OBJ_VRAM0 + 0x4800);
	ApplyPaletteExt(Pal_TacticianSelObj, 0x260, 0x80);

	func_fe6_0803FB08(0);

	SetTextFont(&gSioFont);
	ResetTextFont();

	func_fe6_08036C60();

	proc->unk_30 = 0;
	proc->unk_2C = func_fe6_08040744(proc);

	SetBgOffset(BG_1, 0xFE, 0);

	LoadLinkArenaRuleSettings(buf);

	func_fe6_08040768(proc->unk_2C, proc->unk_30,
		gLinkArenaRuleData[proc->unk_30].x_pos[buf[proc->unk_30]] * 8,
		proc->unk_30 * 3 * 8 + 48);

	for (i = 0; i < 3; i++) {
		ClearText(&gLinkArenaSt.texts[i]);
		Text_SetColor(&gLinkArenaSt.texts[i], TEXT_COLOR_SYSTEM_WHITE);
		Text_DrawString(&gLinkArenaSt.texts[i], gLinkArenaRuleData[i].label);
		PutText(&gLinkArenaSt.texts[i], gBg0Tm + TM_OFFSET(6, 6 + i * 3));

		func_fe6_0803AED0(i, buf[i]);
	}

	DrawLinkArenaModeIcon(gBg1Tm + 0x11E + gLinkArenaRuleData[1].x_pos[0], 0);
	DrawLinkArenaModeIcon(gBg1Tm + 0x11E + gLinkArenaRuleData[1].x_pos[1], 1);

	StartLinkArenaTitleBanner(proc->unk_2C, 6);
	func_fe6_0803FD40(title, 9, 0, 8, gLinkArenaSt.unk_00, proc->unk_2C);

	SioPutText(MSG_6D4 + proc->unk_30, 1);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

void SioRuleSettings_Loop(struct ProcSioRuleSettings * proc)
{
	u8 buf[4];
	u8 changed = 0;
	int off = 0;

	if (gKeySt->pressed & KEY_BUTTON_B) {
		SioPlaySe(1);
		WriteMultiArenaSaveConfig((u16 *) &gSioSaveConfig);
		Proc_Break(proc);
	}

	LoadLinkArenaRuleSettings(buf);

	if ((gKeySt->repeated & KEY_DPAD_UP) && proc->unk_30 != 0) {
		proc->unk_30--;
		changed = 1;
	}

	if ((gKeySt->repeated & KEY_DPAD_DOWN) && proc->unk_30 < 2) {
		proc->unk_30++;
		changed++;
	}

	if (gKeySt->pressed & KEY_DPAD_LEFT) {
		buf[proc->unk_30] = (buf[proc->unk_30] - 1) & 1;
		func_fe6_0803AED0(proc->unk_30, buf[proc->unk_30]);
		changed++;
	}

	if (gKeySt->pressed & KEY_DPAD_RIGHT) {
		buf[proc->unk_30] = (buf[proc->unk_30] + 1) & 1;
		func_fe6_0803AED0(proc->unk_30, buf[proc->unk_30]);
		changed++;
	}

	SaveLinkArenaRuleSettings(buf);

	if (changed != 0) {
		SioPlaySe(3);

		if (proc->unk_30 == 1)
			off = -2;

		func_fe6_08040768(proc->unk_2C, proc->unk_30,
			(gLinkArenaRuleData[proc->unk_30].x_pos[buf[proc->unk_30]] + off) * 8,
			proc->unk_30 * 3 * 8 + 48);

		SioPutText(MSG_6D4 + proc->unk_30, 1);
	}
}

int func_fe6_0803B248(struct SioMenuProc * proc, int line)
{
	int msg_lut[] = {
		MSG_6C5, -1,
		MSG_6C6, MSG_6C7,
		MSG_6C8, -1,
		MSG_6C9, -1,
		MSG_6CA, -1,
	};

	if (line == 0) {
		if (proc->unk_58 == 0)
			return MSG_6C4;
	} else {
		if (proc->unk_58 == 0)
			return -1;
	}

	return msg_lut[proc->unk_48 * 2 + line];
}

u8 const gUnk_Sio_0810F350[] = {
	128, 16,
	104, 36,
	80, 56,
	56, 76,
	32, 96,
};

bool SioHaskValidSaveSlot(void)
{
	int i;

	for (i = 0; i < 3; i++) {
		if (IsSaveValid(i) && IsGameSavePastFirstChapter(i))
			return TRUE;
	}

	return FALSE;
}

void SioMenu_Init(void)
{
	int i;

	gLinkArenaSt.unk_0A = SioHaskValidSaveSlot();

	for (i = 0; i < 0x10; i++)
		gKeyInputSequenceBuffer[i] = 0;

	gCurrentKeyInSeqIndex = gTargetKeyInSeqIndex = gKeyInputSequenceTimer = 0;
}

void SioMenu_LoadGraphics(struct SioMenuProc * proc)
{
	int enabled;
	int i;
	u8 title[] = { 0x0C, 0x04, 0x0D, 0x14, 0x19 };

	ReadMultiArenaSaveConfig((u16 *) &gSioSaveConfig);
	proc->unk_59 = gSioSaveConfig.unk_3;

	InitSioBG();

	Decompress(Img_SioMenuBgSlide, OBJ_VRAM0 + 0x4800);
	ApplyPaletteExt(Pal_SioMenuBgSlide, 0x260, 0x60);
	Sio_RestartBgSlide(0, 4);

	SetTextFont(&gSioFont);
	InitSystemTextFont();
	ResetTextFont();

	func_fe6_08036C60();

	proc->unk_4C = 0;

	proc->unk_58 = IsMultiArenaSaveReady();
	proc->menu_item_state[0] = TRUE;

	enabled = proc->unk_58 != 0;
	proc->menu_item_state[1] = enabled;
	proc->menu_item_state[2] = enabled;
	proc->menu_item_state[3] = enabled;

	if (proc->unk_59 == 0) {
		enabled = FALSE;
		proc->unk_50 = 3;
	} else {
		enabled = TRUE;
		proc->unk_50 = 4;
	}

	proc->menu_item_state[4] = enabled;

	proc->unk_48 = gLinkArenaSt.unk_01;
	proc->menu_item_state[proc->unk_48] = 2;

	for (i = 4; i >= 0; i--)
		proc->menu_items[i] = func_fe6_08040014(proc, 176, 160, i, proc->menu_item_state[i]);

	StartLinkArenaTitleBanner(proc->menu_items[0], 0);
	func_fe6_0803FD40(title, 5, 0, 0xA8, 0, proc->menu_items[0]);

	SetFaceConfig(gUnk_Sio_085CA404);
	StartFace(3, FID_C0, 208, 80, FACE_DISP_KIND(FACE_96x80));

	proc->unk_54 = 0;

	StartBgm(SONG_39, NULL);
	func_fe6_0803CF9C();
}

void SioMenu_0803B45C(struct SioMenuProc * proc)
{
	int i;

	int x = Interpolate(INTERPOLATE_RSQUARE, -80, gUnk_Sio_0810F350[0], proc->unk_54, 32);
	int y = Interpolate(INTERPOLATE_RCUBIC, 160, gUnk_Sio_0810F350[1], proc->unk_54, 32);

	for (i = 4; i >= 0; i--)
		func_fe6_08040098(proc->menu_items[i], x, y);

	func_fe6_0803FE28(0, y + 8);

	if (proc->unk_54 >= 32) {
		proc->unk_54 = 0;

		SioPutText(func_fe6_0803B248(proc, 0), 0);
		SioPutText(func_fe6_0803B248(proc, 1), 1);

		func_fe6_0803FE28(0, gUnk_Sio_0810F350[1] + 8);

		Proc_Break(proc);
	}

	proc->unk_54++;
}

void SioMenu_0803B508(struct SioMenuProc * proc)
{
	int i;

	int idx = proc->unk_48 * 2;

	for (i = 4; i >= 0; i--) {
		int x = Interpolate(INTERPOLATE_RSQUARE,
			gUnk_Sio_0810F350[idx + 0], gUnk_Sio_0810F350[i * 2 + 0], proc->unk_54, 16);
		int y = Interpolate(INTERPOLATE_RSQUARE,
			gUnk_Sio_0810F350[idx + 1], gUnk_Sio_0810F350[i * 2 + 1], proc->unk_54, 16);

		func_fe6_08040098(proc->menu_items[i], x, y);
	}

	if (proc->unk_54 >= 16)
		Proc_Break(proc);

	proc->unk_54++;
}

void SioMenu_RestartGraphics(struct SioMenuProc * proc)
{
	int enabled;
	int i;
	int idx;
	u8 title[] = { 0x0C, 0x04, 0x0D, 0x14, 0x19 };

	ReadMultiArenaSaveConfig((u16 *) &gSioSaveConfig);
	proc->unk_59 = gSioSaveConfig.unk_3;

	InitSioBG();

	Decompress(Img_SioMenuBgSlide, OBJ_VRAM0 + 0x4800);
	ApplyPaletteExt(Pal_SioMenuBgSlide, 0x260, 0x60);
	Sio_RestartBgSlide(0, 4);

	SetTextFont(&gSioFont);
	InitSystemTextFont();
	ResetTextFont();

	func_fe6_08036C60();

	proc->unk_4C = 0;

	proc->unk_58 = IsMultiArenaSaveReady();
	proc->menu_item_state[0] = TRUE;

	enabled = proc->unk_58 != 0;
	proc->menu_item_state[1] = enabled;
	proc->menu_item_state[2] = enabled;
	proc->menu_item_state[3] = enabled;

	if (proc->unk_59 == 0) {
		enabled = FALSE;
		proc->unk_50 = 3;
	} else {
		enabled = TRUE;
		proc->unk_50 = 4;
	}

	proc->menu_item_state[4] = enabled;

	proc->unk_48 = gLinkArenaSt.unk_01;
	proc->menu_item_state[proc->unk_48] = 2;

	idx = proc->unk_48 * 2;

	for (i = 4; i >= 0; i--) {
		proc->menu_items[i] = func_fe6_08040014(proc,
			gUnk_Sio_0810F350[idx + 0], gUnk_Sio_0810F350[idx + 1], i, proc->menu_item_state[i]);
	}

	StartLinkArenaTitleBanner(proc->menu_items[0], 0);
	func_fe6_0803FD40(title, 5, 0, gUnk_Sio_0810F350[proc->unk_48 * 2 + 1] + 8, 0, proc->menu_items[0]);

	SetFaceConfig(gUnk_Sio_085CA424);
	StartFace(3, FID_C0, 208, 80, FACE_DISP_KIND(FACE_96x80));

	SioPutText(func_fe6_0803B248(proc, 0), 0);
	SioPutText(func_fe6_0803B248(proc, 1), 1);
	func_fe6_0803CF9C();

	StartBgm(SONG_39, NULL);

	proc->unk_54 = 0;
}

void SioMenu_HandleDPadInput(struct SioMenuProc * proc, u8 count)
{
	if (proc->unk_48 == 1) {
		if (gKeySt->pressed & KEY_DPAD_LEFT) {
			gLinkArenaSt.unk_05--;

			if (gLinkArenaSt.unk_05 > 2)
				gLinkArenaSt.unk_05 = 2;

			func_fe6_08040084(proc->menu_items[1], -6, 0x34, 0x1F, 4);
			SioPlaySe(3);
		}

		if (gKeySt->pressed & KEY_DPAD_RIGHT) {
			gLinkArenaSt.unk_05++;
			gLinkArenaSt.unk_05 = gLinkArenaSt.unk_05 % 3;

			func_fe6_08040084(proc->menu_items[1], 0, 0x3A, 4, 0x1F);
			SioPlaySe(3);
		}
	}

	if ((gKeySt->repeated & KEY_DPAD_UP) &&
		(proc->unk_48 > proc->unk_4C || gKeySt->repeated == gKeySt->pressed)) {
		do {
			proc->unk_48--;

			if (proc->unk_48 < 0)
				proc->unk_48 = count - 1;
		} while (proc->menu_item_state[proc->unk_48] == 0);
	}

	if ((gKeySt->repeated & KEY_DPAD_DOWN) &&
		(proc->unk_48 < proc->unk_50 || gKeySt->repeated == gKeySt->pressed)) {
		do {
			proc->unk_48++;
			proc->unk_48 = proc->unk_48 % count;
		} while (proc->menu_item_state[proc->unk_48] == 0);
	}
}

void SioMenu_Loop_HandleKeyInput(struct SioMenuProc * proc)
{
	int idx = proc->unk_48;

	if (SioIsKeyInputSequenceComplete(gUnk_Sio_085C99F8)) {
		gLinkArenaSt.unk_00 = proc->unk_48;
		gLinkArenaSt.unk_01 = proc->unk_48;

		EndFaceById(3);
		SpawnProcLocking(ProcScr_SioMenuBurstFx, proc);
		Proc_Goto(proc, 1);
	}

	SioMenu_HandleDPadInput(proc, 5);

	if (idx != proc->unk_48) {
		struct SioMenuItemProc * child;

		SioPlaySe(3);

		child = proc->menu_items[idx];
		child->state = 1;

		child = proc->menu_items[proc->unk_48];
		child->state = 2;

		func_fe6_0804085C(child, child->x_base, child->y_base);

		SioPutText(func_fe6_0803B248(proc, 0), 0);
		SioPutText(func_fe6_0803B248(proc, 1), 1);

		func_fe6_0803FE0C(0, gUnk_Sio_0810F350[proc->unk_48 * 2 + 1] + 8);
		func_fe6_0803FE48(proc->unk_48);
	}

	if (gKeySt->pressed & KEY_BUTTON_A) {
		proc->unk_54 = 0;
		SioPlaySe(2);
		gLinkArenaSt.unk_00 = proc->unk_48;
		Proc_Break(proc);
	}

	if (gKeySt->pressed & KEY_BUTTON_B) {
		SioPlaySe(1);
		FadeBgmOut(2);
		gLinkArenaSt.unk_00 = 0xFF;
		Proc_Break(proc);
	}
}

void SioMenu_0803B93C(struct SioMenuProc * proc)
{
	int sel;
	int i;

	if (gLinkArenaSt.unk_00 == 0xFF)
		Proc_Break(proc);

	sel = gLinkArenaSt.unk_00;

	if (proc->unk_54 <= 16) {
		for (i = 4; i >= 0; i--) {
			int x = Interpolate(INTERPOLATE_RSQUARE,
				gUnk_Sio_0810F350[i * 2 + 0], gUnk_Sio_0810F350[sel * 2 + 0], proc->unk_54, 16);
			int y = Interpolate(INTERPOLATE_RSQUARE,
				gUnk_Sio_0810F350[i * 2 + 1], gUnk_Sio_0810F350[sel * 2 + 1], proc->unk_54, 16);

			func_fe6_08040098(proc->menu_items[i], x, y);
		}
	}

	if (proc->unk_54 > 32)
		Proc_Break(proc);

	proc->unk_54++;
}

void SioMenu_End(struct SioMenuProc * proc)
{
	int i;

	struct ProcScr const * proc_lut[] = {
		ProcScr_SIOTERM,
		ProcScr_SIOPRA,
		ProcScr_SIOBAT,
		ProcScr_SIORESULT,
		ProcScr_SIO_RuleSettings,
	};

	EndFaceById(3);

	for (i = 0; i < 5; i++)
		Proc_End(proc->menu_items[i]);

	if (gLinkArenaSt.unk_00 == 0xFF) {
		EndBmVSync();
		Sio_EndBackgroundSlide();
		UnsetBmStLinkArenaFlag();

		Proc_EndEach(ProcScr_DebugMonitor);
		Proc_End(proc);
	} else {
		gLinkArenaSt.unk_01 = gLinkArenaSt.unk_00;
		SpawnProcLocking(proc_lut[gLinkArenaSt.unk_00], proc);
	}
}

void StartLinkArenaMainMenu(ProcPtr parent)
{
	UnpackUiWindowFrameGraphics();
	InitTextFont(&gSioFont, (u8 *)BG_VRAM + 0x1800, 0xC0, 0);

	if (!IsSaveValid(SAVE_MULTIARENA))
		WriteNewMultiArenaSave();

	gLinkArenaSt.unk_05 = 0;
	gLinkArenaSt.unk_03 = 0;
	gLinkArenaSt.unk_01 = 0;

	SetBmStLinkArenaFlag();
	func_fe6_0803CE7C();
	StartBmVSync();

	gPlaySt.flags &= ~PLAY_FLAG_COMPLETE;
	gPlaySt.config_window_theme = 0;

	SpawnProcLocking(ProcScr_SIOMENU, parent);
	SpawnProc(ProcScr_DebugMonitor, PROC_TREE_3);
}

bool XMapTransfer_0803BAE0(ProcPtr proc)
{
	int i;
	u8 buf[4];

	int num_timeouts = 0;

	if (FindProc(ProcScr_SIOCON) != NULL) {
		if (gKeySt->pressed & KEY_BUTTON_B) {
			EventGotoLabel(proc, 4);
			return FALSE;
		}

		return TRUE;
	}

	if (gSioSt->self_id > 1 || gSioSt->player_status[gSioSt->self_id] == PLAYER_STATUS_2) {
		EventGotoLabel(proc, 0);
		return FALSE;
	}

	for (i = 0; i < 4; i++) {
		if (gSioSt->timeout_clock[i] > 60)
			num_timeouts++;
	}

	if (!func_fe6_08035CF8() || gSioSt->unk_01E > 60 || num_timeouts != 0) {
		EventGotoLabel(proc, 0);
		return FALSE;
	}

	gSioBuf_030044E0.head.kind = SIO_MSG_1C;
	gSioBuf_030044E0.head.sender = gSioSt->self_id;
	gSioBuf_030044E0.head.param = gSioSt->unk_000;
	SioSend(&gSioBuf_030044E0, 10);

	if (gSioSt->self_id == 0 && !IsExtraMapAvailable()) {
		buf[0] = 1;
		SioEmitData(buf, sizeof(buf));
		EventGotoLabel(proc, 3);
		return FALSE;
	}

	if ((gSioSt->unk_009 & 3) == 3) {
		gSioSt->unk_009 = 3;
		func_fe6_08036608();

		gSioSt->unk_004 = 6;
		gSioSt->unk_01E = 0;

		if (gSioSt->self_id != 0)
			EventGotoLabel(proc, 1);

		return FALSE;
	}

	return TRUE;
}

void XMapTransfer_0803BBF8(ProcPtr proc)
{
	if (gSioSt->unk_009 > 3)
		EventGotoLabel(proc, 0);
}

void XMapTransfer_0803BC18(ProcPtr proc)
{
	u8 buf[4];

	if (GetTalkChoiceResult() == 1)
		gSioXmapOption = 0;
	else
		gSioXmapOption = 1;

	buf[0] = gSioXmapOption;
	SioEmitData(buf, sizeof(buf));

	if (gSioXmapOption != 0)
		EventGotoLabel(proc, 5);
}

bool XMapTransfer_0803BC60(ProcPtr proc)
{
	u16 got;
	int i;
	u8 buf[4];
	u8 sender[4];

	int num_timeouts = 0;

	for (i = 0; i < 4; i++) {
		if (gSioSt->timeout_clock[i] > 60)
			num_timeouts++;
	}

	if (!func_fe6_08035CF8() || gSioSt->unk_01E > 60 || num_timeouts != 0) {
		EventGotoLabel(proc, 0);
		return FALSE;
	}

	got = SioReceiveData(buf, sender, NULL);

	if (got != 0) {
		if (buf[0] != 0)
			EventGotoLabel(proc, 5);

		return FALSE;
	}

	return TRUE;
}

void PutXMapProgressPercent(struct Text * text, char const * str, int number)
{
	ClearText(text);

	Text_InsertDrawString(text, 0, TEXT_COLOR_SYSTEM_WHITE, str);
	Text_InsertDrawNumberOrBlank(text, 54, TEXT_COLOR_SYSTEM_BLUE, number);
	Text_InsertDrawString(text, 62, TEXT_COLOR_SYSTEM_WHITE, "％");

	PutText(text, gBg0Tm + TM_OFFSET(15, 12));
}

void DrawXMapSendProgress(struct SioBigSendProc * proc)
{
	if (proc->unk_3C < proc->completion_percent) {
		PlaySe(SONG_7D);
		proc->unk_3C++;

		PutXMapProgressPercent(gSioMenuTexts, "送信中", proc->unk_3C);
		PutDrawUiGauge(0x100, 14, gBg0Tm + TM_OFFSET(14, 15), TILEREF(0, 6), 100, proc->unk_3C, 100 - proc->unk_3C);
		EnableBgSync(BG0_SYNC_BIT);
	}
}

void DrawXMapReceiveProgress(struct SioBigReceiveProc * proc)
{
	if (proc->unk_3C < proc->completion_percent) {
		PlaySe(SONG_7D);
		proc->unk_3C++;

		PutXMapProgressPercent(gSioMenuTexts, "受信中", proc->unk_3C);
		PutDrawUiGauge(0x100, 14, gBg0Tm + TM_OFFSET(14, 15), TILEREF(0, 6), 100, proc->unk_3C, 100 - proc->unk_3C);
		EnableBgSync(BG0_SYNC_BIT);
	}
}

void StartXMapTransfer(ProcPtr proc)
{
	SetTextFont(&gSioFont);
	InitSystemTextFont();

	if (gSioSt->self_id == 0) {
		ReadSramFast(SRAM_XMAP_ADDR, gSioXmapBuf, SRAM_XMAP_SIZE);
		StartSioBigSend(gSioXmapBuf, SRAM_XMAP_SIZE, DrawXMapSendProgress, 0, proc);
	} else {
		StartSioBigReceive(gSioXmapBuf, DrawXMapReceiveProgress, proc);
	}
}

bool XMapTransfer_AwaitCompletion(void)
{
	if (IsSioBigTransferActive())
		return TRUE;

	PlaySe(SONG_7E);

	InitTalkTextFont();

	if (gSioSt->self_id != 0)
		WriteAndVerifySramFast(gSioXmapBuf, SRAM_XMAP_ADDR, SRAM_XMAP_SIZE);

	return FALSE;
}

void XMapTransfer_0803BECC(void)
{
	gSioSt->unk_00A = 1 << gSioSt->self_id;
}

bool XMapTransfer_0803BEE0(void)
{
	gSioMsgBuf.kind = SIO_MSG_19;
	gSioMsgBuf.sender = gSioSt->self_id;
	gSioMsgBuf.param = 0;
	SioSend(&gSioMsgBuf, 4);

	if ((gSioSt->unk_00A & gSioSt->unk_009) == gSioSt->unk_009) {
		gSioSt->unk_00A = 1 << gSioSt->self_id;
		return FALSE;
	}

	return TRUE;
}

void XMapTransfer_0803BF28(void)
{
	ApplyUiStatBarPal(6);
	PutUiWindowFrame(13, 11, 16, 6, 0);

	SetTextFont(&gSioFont);
	InitSystemTextFont();

	PutXMapProgressPercent(gSioMenuTexts, "準備中", 0);
	PutDrawUiGauge(0x100, 13, gBg0Tm + TM_OFFSET(14, 15), TILEREF(0, 6), 100, 0, 100);

	EnableBgSync(BG0_SYNC_BIT);
}

void XmapTransfer_SetDisp(void)
{
	SetWOutLayers(1, 1, 1, 1, 1);
}

void func_fe6_0803BFB0(struct Proc * proc)
{
	int i;
	struct SioMenuItemProc ** iter;

	struct SioMenuProc * menu_proc = proc->proc_parent;

	EndFaceById(3);

	iter = menu_proc->menu_items;

	for (i = 0; i < 5; i++)
		Proc_End(*iter++);

	InitSioBG();
	Sio_RestartBgSlide(0, 0);

	gSioSt->unk_000 = 3;

	SetTextFont(&gSioFont);
	InitSystemTextFont();

	InitTextDb(gSioMenuTexts, 10);

	FadeBgmOut(1);
}

void StartEvent_SioXMapTransfer(ProcPtr parent)
{
	gSioSt->unk_000 = 3;
	StartEventLocking(EventScr_SioXMapTransfer, parent);
}

void func_fe6_0803C02C(void)
{
	ClearSioBG();

	SioBat_EndHandler();
	SioBat_ReleaseIrq();
	SioInit_SW();
}

void func_fe6_0803C044(ProcPtr proc)
{
	if (GetTalkChoiceResult() != 1)
		EventGotoLabel(proc, 1);
}

void func_fe6_0803C060(ProcPtr proc)
{
	if (GetTalkChoiceResult() == 1)
		InitGlobalSaveInfo();
	else
		EventGotoLabel(proc, 1);
}

void StartEvent_SioXmap_0803C080(ProcPtr parent)
{
	StartEventLocking(EventScr_SioXmap_085CA6B8, parent);
}

void func_fe6_0803C094(struct SioRankEntry * buf)
{
	int i, j;

	int count = gLinkArenaSt.unk_A0;

	if (gLinkArenaSt.rules.unk_0_1) {
		for (i = 0; i < count; i++) {
			buf[i].player_id = gSioBmSt.unk_0F[i];
			buf[i].points = gSioBmSt.current_score[gSioBmSt.unk_0F[i]];
		}
	} else {
		for (i = 0; i < count; i++) {
			buf[i].player_id = i;
			buf[i].points = gSioBmSt.current_score[i];
		}

		for (i = 0; i <= count - 2; i++) {
			for (j = count - 2; j >= i; j--) {
				if (buf[j].points < buf[j + 1].points) {
					int tmp_id;
					int tmp_points;

					tmp_id = buf[j].player_id;
					buf[j].player_id = buf[j + 1].player_id;
					buf[j + 1].player_id = tmp_id;

					tmp_points = buf[j].points;
					buf[j].points = buf[j + 1].points;
					buf[j + 1].points = tmp_points;
				}
			}
		}
	}
}
