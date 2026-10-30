#include "prelude.h"
#include "proc.h"
#include "ui.h"
#include "support.h"
#include "item.h"
#include "statscreen.h"
#include "hardware.h"
#include "util.h"
#include "playrank.h"
#include "secretscreen.h"

EWRAM_DATA u8 SioPidPool[SID_PID_POOL_SIZE] = {};
EWRAM_DATA u8 _pad_0203D499[7] = { 0 };
EWRAM_DATA struct SecretScreenData gSecretScreenData[SID_PID_POOL_SIZE] = {};
EWRAM_DATA u8 gSecretScreenSupportLevels[10] = {};

EWRAM_OVERLAY(0) int gSecretScreenBitCount = 0;
EWRAM_OVERLAY(0) int gSecretScreenBitMask = 0;
EWRAM_OVERLAY(0) int gSecretScreenSymbolCount = 0;
EWRAM_OVERLAY(0) int gSecretScreenInitSeed = 0;
EWRAM_OVERLAY(0) struct Text gSecretScreenTexts[5] = {};
EWRAM_OVERLAY(0) int gSecretScreenRN = 0;
EWRAM_OVERLAY(0) u8 gSecretScreenPasswordBuf[0xA0] = {};
EWRAM_OVERLAY(0) struct SecretScreenPasswordMeta gSecretScreenPasswordMeta = {};

CONST_DATA u8 gSecretScreenPlayRankGlyphTable[] = JTEXT("２３４５６７８９ＡＢＣＤＥＦＧＨＪＫＬＭＮＰＱＲＳＴＵＶＷＸＹＺ");

CONST_DATA struct ProcScr ProcScr_Prep_Password[] = {
	PROC_SLEEP(0),
	PROC_CALL(SecretScreen_PlayRankPasswordInit),
	PROC_CALL(StartMidFadeFromBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_REPEAT(SecretScreen_PlayRankPasswordLoop),
PROC_LABEL(0),
	PROC_CALL(StartMidFadeToBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_CALL(SecretScreen_PlayRankPasswordEnd),
	PROC_END,
};

CONST_DATA u8 gSecretScreenUnitGlyphTable[] = JTEXT(
	"あいうえおかきくけこさすせそたちてとなにぬねのはひふほまみむめもやゆよらるれろわをん"
	"アイオカキケコサスセタチテトナニヌネノハヒホマミメモヤヨラルロヲ"
	"２３４５６７８９ＡＢＣＤＥＦＧＨＪＫＬＭＮＰＱＲＳＴＵＶＷＸＹＺ"
	"ぎぐごじずぜぞだぢでどびぶギグゲドバビボザげ");

CONST_DATA struct ProcScr ProcScr_SecretScreen[] = {
	PROC_SLEEP(0),
	PROC_CALL(SecretScreen_Init),
	PROC_CALL(StartMidFadeFromBlack),
	PROC_REPEAT(WhileFadeExists),
	PROC_REPEAT(SecretScreen_Loop_Dummy),
	PROC_CALL(StartMidFadeToBlack),
	PROC_REPEAT(WhileFadeExists),
PROC_LABEL(0),
	PROC_CALL(SecretScreen_End),
	PROC_END,
};

void SecretScreen_InitBitstream(int bit_count, int seed)
{
	int remainder;

	gSecretScreenBitCount = bit_count;
	gSecretScreenBitMask = (1 << bit_count) - 1;

	gSecretScreenSymbolCount = 28 / bit_count;
	remainder = 28 % bit_count;

	if (remainder > 0)
		gSecretScreenSymbolCount++;

	gSecretScreenInitSeed = seed;
}

int SecretScreen_CeilDivBitCount(int a)
{
	int quotient;
	int remainder;

	quotient = a / gSecretScreenBitCount;
	remainder = a % gSecretScreenBitCount;

	if (remainder > 0)
		quotient++;

	return quotient;
}

u16 GetSecretScreenRN(void)
{
	u16 rn = gSecretScreenRN * 136;

	rn = rn + rn / 71 + 3;

	gSecretScreenRN = rn;
	return rn;
}

void SecretScreen_ShufflePasswordBuf(void)
{
	int i;

	for (i = 0; i < gSecretScreenSymbolCount; i++) {
		int tmp = gSecretScreenPasswordBuf[i + gSecretScreenSymbolCount + i * 2];

		gSecretScreenPasswordBuf[i + gSecretScreenSymbolCount + i * 2] = gSecretScreenPasswordBuf[i];
		gSecretScreenPasswordBuf[i] = tmp;
	}
}

void SecretScreen_WriteBits(u8 *buf, int *counter, int value, int num_bits)
{
	int i;
	u16 tmp;

	tmp = GetSecretScreenRN();
	value = value + tmp;
	value &= (1 << num_bits) - 1;

	for (i = 0; i < num_bits; i++) {
		buf[*counter / gSecretScreenBitCount] |= ((value & (1 << i)) >> i) << (*counter % gSecretScreenBitCount % 8);
		(*counter)++;
	}
}

u32 SecretScreen_ReadBits(u8 *buf, int *counter, int round)
{
	int i;
	u32 value = 0;
	u16 tmp;

	for (i = 0; i < round; i++) {
		value |= ((buf[*counter / gSecretScreenBitCount] & (1 << (*counter % gSecretScreenBitCount % 8)))
			>> (*counter % gSecretScreenBitCount % 8)) << i;
		(*counter)++;
	}

	tmp = GetSecretScreenRN();
	return (value - tmp) & ((1 << round) - 1);
}

u16 SecretScreen_ChecksumPasswordBuf(u8 *buf, int length)
{
	u16 sum = 0;
	int i = 0;

	while (i < length) {
		sum = (u16)(sum + (buf[i] * (i + 1)));
		i++;
	}

	return (sum + (sum >> 9)) & 0x1FF;
}

void SecretScreen_EmbedPasswordMeta(void)
{
	int idx = 0;
	int bit = 0;
	int i;
	u16 sum;

	sum = SecretScreen_ChecksumPasswordBuf(gSecretScreenPasswordBuf + gSecretScreenSymbolCount, gSecretScreenPasswordMeta.tail_len);

	do {
		if (bit % 3 == 0)
			gSecretScreenPasswordBuf[idx] |= ((gSecretScreenPasswordMeta.rn_seed & (1 << (bit / 3))) >> (bit / 3)) << (bit % gSecretScreenBitCount);
		else if (bit % 3 == 1)
			gSecretScreenPasswordBuf[idx] |= ((gSecretScreenPasswordMeta.checksum_b & (1 << (bit / 3))) >> (bit / 3)) << (bit % gSecretScreenBitCount);
		else
			gSecretScreenPasswordBuf[idx] |= ((gSecretScreenPasswordMeta.checksum_c & (1 << (bit / 3))) >> (bit / 3)) << (bit % gSecretScreenBitCount);

		bit++;

		if (bit % gSecretScreenBitCount == 0)
			idx++;
	} while (bit != 28);

	for (i = 0; i < gSecretScreenSymbolCount; i++)
		gSecretScreenPasswordBuf[i] = (gSecretScreenPasswordBuf[i] + sum) & gSecretScreenBitMask;

	SecretScreen_ShufflePasswordBuf();
}

void SecretScreen_ExtractPasswordMeta(void)
{
	int idx = 0;
	int bit = 0;
	int i;
	u16 sum;

	SecretScreen_ShufflePasswordBuf();

	sum = SecretScreen_ChecksumPasswordBuf(gSecretScreenPasswordBuf + gSecretScreenSymbolCount, gSecretScreenPasswordMeta.tail_len);

	for (i = 0; i < gSecretScreenSymbolCount; i++)
		gSecretScreenPasswordBuf[i] = (gSecretScreenPasswordBuf[i] - sum) & gSecretScreenBitMask;

	gSecretScreenPasswordMeta.rn_seed = 0;
	gSecretScreenPasswordMeta.checksum_b = 0;
	gSecretScreenPasswordMeta.checksum_c = 0;

	do {
		if (bit % 3 == 0)
			gSecretScreenPasswordMeta.rn_seed |= ((gSecretScreenPasswordBuf[idx] >> (bit % gSecretScreenBitCount)) & 1) << (bit / 3);
		else if (bit % 3 == 1)
			gSecretScreenPasswordMeta.checksum_b |= ((gSecretScreenPasswordBuf[idx] >> (bit % gSecretScreenBitCount)) & 1) << (bit / 3);
		else
			gSecretScreenPasswordMeta.checksum_c |= ((gSecretScreenPasswordBuf[idx] >> (bit % gSecretScreenBitCount)) & 1) << (bit / 3);

		bit++;

		if (bit % gSecretScreenBitCount == 0)
			idx++;
	} while (bit != 28);
}

void SecretScreen_ModifyPassword(void (*func)(int *counter, u8 *buf))
{
	int counter = 0;
	int i;

	for (i = 0; i < 0xA0; i++)
		gSecretScreenPasswordBuf[i] = 0;

	func(&counter, gSecretScreenPasswordBuf + gSecretScreenSymbolCount);

	gSecretScreenPasswordMeta.tail_len = SecretScreen_CeilDivBitCount(counter);
	gSecretScreenPasswordMeta.checksum_b = SecretScreen_ChecksumPasswordBuf(gSecretScreenPasswordBuf + gSecretScreenSymbolCount, gSecretScreenPasswordMeta.tail_len);
	gSecretScreenPasswordMeta.rn_seed = (gSecretScreenPasswordMeta.checksum_b + GetGameTime() / 8) % 0x400;

	gSecretScreenRN = gSecretScreenPasswordMeta.rn_seed;
	gSecretScreenPasswordMeta.checksum_b = (gSecretScreenPasswordMeta.checksum_b + GetSecretScreenRN()) & 0x1FF;

	for (i = 0; i < gSecretScreenPasswordMeta.tail_len; i++)
		gSecretScreenPasswordBuf[i + gSecretScreenSymbolCount] = (gSecretScreenPasswordBuf[i + gSecretScreenSymbolCount] + GetSecretScreenRN()) & gSecretScreenBitMask;

	gSecretScreenPasswordMeta.checksum_c = (SecretScreen_ChecksumPasswordBuf(gSecretScreenPasswordBuf + gSecretScreenSymbolCount, gSecretScreenPasswordMeta.tail_len) + GetSecretScreenRN()) & 0x1FF;

	SecretScreen_EmbedPasswordMeta();
}

bool SecretScreen_VerifyPassword(void (*func)(int *counter, u8 *buf))
{
	u16 rn[2];
	int counter = 0;
	u16 sum_c;
	u16 sum_b;
	int i;

	SecretScreen_ExtractPasswordMeta();

	gSecretScreenRN = gSecretScreenPasswordMeta.rn_seed;
	sum_c = SecretScreen_ChecksumPasswordBuf(gSecretScreenPasswordBuf + gSecretScreenSymbolCount, gSecretScreenPasswordMeta.tail_len);
	rn[0] = GetSecretScreenRN();

	for (i = 0; i < gSecretScreenPasswordMeta.tail_len; i++)
		gSecretScreenPasswordBuf[i + gSecretScreenSymbolCount] = (gSecretScreenPasswordBuf[i + gSecretScreenSymbolCount] - GetSecretScreenRN()) & gSecretScreenBitMask;

	rn[1] = GetSecretScreenRN();

	func(&counter, gSecretScreenPasswordBuf + gSecretScreenSymbolCount);

	sum_b = (SecretScreen_ChecksumPasswordBuf(gSecretScreenPasswordBuf + gSecretScreenSymbolCount, gSecretScreenPasswordMeta.tail_len) + rn[0]) & 0x1FF;
	sum_c = (sum_c + rn[1]) & 0x1FF;

	if (gSecretScreenPasswordMeta.checksum_b != sum_b || gSecretScreenPasswordMeta.checksum_c != sum_c)
		return FALSE;

	return TRUE;
}

u16 SecretScreen_FindGlyphIndex(i8 const *glyph, i8 const *table)
{
	int i = 0;

	while (*table != 0) {
		if (*(u16 const *)table == *(u16 const *)glyph)
			return i;

		table += 2;
		i++;
	}

	return 0xFFFF;
}

void SecretScreen_MapGlyphsToPasswordBuf(i8 const *str, i8 const *table)
{
	int i = 0;

	while (str[i * 2] != 0) {
		gSecretScreenPasswordBuf[i] = SecretScreen_FindGlyphIndex(str + i * 2, table);
		i++;
	}
}

void SecretScreen_EncodePlayRankStats(int *counter, u8 *buf)
{
	gSecretScreenRN = gSecretScreenInitSeed;

	SecretScreen_WriteBits(buf, counter, gSecretScreenPlayRankStats.unk_11, 1);
	SecretScreen_WriteBits(buf, counter, PlayRank_GetTotalTurn(), 16);
	SecretScreen_WriteBits(buf, counter, PlayRank_GetWinningRate(), 16);
	SecretScreen_WriteBits(buf, counter, PlayRank_GetDeadAllies(), 7);
	SecretScreen_WriteBits(buf, counter, PlayRank_GetTotalLevelsGained(), 12);
	SecretScreen_WriteBits(buf, counter, GetTotalAsset(), 24);
	SecretScreen_WriteBits(buf, counter, PlayRank_CalcTotalLevel(), 12);
	SecretScreen_WriteBits(buf, counter, gSecretScreenPlayRankStats.hours, 10);
	SecretScreen_WriteBits(buf, counter, gSecretScreenPlayRankStats.minutes, 6);
	SecretScreen_WriteBits(buf, counter, gSecretScreenPlayRankStats.secounds, 6);
}

void SecretScreen_DecodePlayRankStats(int *counter, u8 *buf)
{
	gSecretScreenRN = gSecretScreenInitSeed;

	gSecretScreenPlayRankStats.unk_11 = SecretScreen_ReadBits(buf, counter, 1);
	gSecretScreenPlayRankStats.total_turn = SecretScreen_ReadBits(buf, counter, 16);
	gSecretScreenPlayRankStats.winning_rate = SecretScreen_ReadBits(buf, counter, 16);
	gSecretScreenPlayRankStats.dead_allies = SecretScreen_ReadBits(buf, counter, 7);
	gSecretScreenPlayRankStats.total_level_gained = SecretScreen_ReadBits(buf, counter, 12);
	gSecretScreenPlayRankStats.total_asset = SecretScreen_ReadBits(buf, counter, 24);
	gSecretScreenPlayRankStats.total_power = SecretScreen_ReadBits(buf, counter, 12);
	gSecretScreenPlayRankStats.hours = SecretScreen_ReadBits(buf, counter, 10);
	gSecretScreenPlayRankStats.minutes = SecretScreen_ReadBits(buf, counter, 6);
	gSecretScreenPlayRankStats.secounds = SecretScreen_ReadBits(buf, counter, 6);
}

void SecretScreen_FillPlayRankStats(void)
{
	int hours, minutes, seconds;

	gSecretScreenPlayRankStats.total_turn = PlayRank_GetTotalTurn();
	gSecretScreenPlayRankStats.winning_rate = PlayRank_GetWinningRate();
	gSecretScreenPlayRankStats.dead_allies = PlayRank_GetDeadAllies();
	gSecretScreenPlayRankStats.total_level_gained = PlayRank_GetTotalLevelsGained();
	gSecretScreenPlayRankStats.total_asset = GetTotalAsset();
	gSecretScreenPlayRankStats.total_power = PlayRank_CalcTotalLevel();
	if (gPlaySt.flags & PLAY_FLAG_HARD)
		gSecretScreenPlayRankStats.unk_11 = TRUE;
	else
		gSecretScreenPlayRankStats.unk_11 = FALSE;

	FormatTime(PlayRank_GetTotalPlayTime(), (u16 *)&hours, (u16 *)&minutes, (u16 *)&seconds);

	gSecretScreenPlayRankStats.hours = hours;
	gSecretScreenPlayRankStats.minutes = minutes;
	gSecretScreenPlayRankStats.secounds = seconds;
}

void SecretScreen_PrintPlayRankPassword(struct Text *text, const u8 *table)
{
	char str[3];
	int line;

	str[2] = '\0';

	EnableBgSync(BG2_SYNC_BIT);

	for (line = 0; line < 3; line++) {
		int i, x_offset;

		ClearText(&text[line]);

		x_offset = 2;

		InitTalkTextFont();

		for (i = 0; i < 14; i++) {
			int loc = line * 14 + i;

			if (loc == (gSecretScreenPasswordMeta.tail_len + gSecretScreenSymbolCount))
				return;

			str[0] = table[gSecretScreenPasswordBuf[loc] * 2];
			str[1] = table[gSecretScreenPasswordBuf[loc] * 2 + 1];

			PutDrawText(&text[line], gBg2Tm + TM_OFFSET(4, 3 * line + 7), TEXT_COLOR_SYSTEM_GRAY, x_offset, 0, str);
			x_offset += 11;

			if (((i + 1) % 5) == 0)
				x_offset += 11;
		}
	}
}

void SecretScreen_PrintPlayRankStatNumbers(int y)
{
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(2, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenPlayRankStats.total_turn);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(6, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenPlayRankStats.winning_rate);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(10, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenPlayRankStats.dead_allies);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(14, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenPlayRankStats.total_level_gained);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(22, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenPlayRankStats.total_power);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(22, y + 2), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenPlayRankStats.total_asset);
}

void SecretScreen_PlayRankPasswordInit(struct ProcSecretScreen *proc)
{
	int i;

	InitBgs(NULL);
	ResetTextFont();
	ResetText();

	proc->unk_2A = 0;

	SetDispEnable(1, 1, 1, 1, 0);

	gDispIo.bg0_ct.priority = 1;
	gDispIo.bg1_ct.priority = 2;
	gDispIo.bg2_ct.priority = 0;
	gDispIo.bg3_ct.priority = 3;

	UnpackUiWindowFrameGraphics();
	EnablePalSync();

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);
	TmFill(gBg3Tm, 0);

	SetBgOffset(0, 0, 0);
	SetBgOffset(1, 0, 0);
	SetBgOffset(2, 0, 0);
	SetBgOffset(3, 0, 0);

	SetWinEnable(0, 0, 0);

	PutUiWindowFrame(2, 6, 0x1A, 7, UI_WINDOW_SABLE);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

	for (i = 0; i < 3; i++)
		InitText(&gSecretScreenTexts[i], 0x1B);

	SecretScreen_FillPlayRankStats();
	SecretScreen_InitBitstream(5, 11);
	SecretScreen_ModifyPassword(SecretScreen_EncodePlayRankStats);
	SecretScreen_PrintPlayRankPassword(gSecretScreenTexts, gSecretScreenPlayRankGlyphTable);
	proc->subproc = StartMuralBackground(PROC_TREE_VSYNC, NULL, BGPAL_SECRETSCREEN_MURALBG);
}

void SecretScreen_PlayRankPasswordLoop(struct ProcSecretScreen *proc) {}

void SecretScreen_PlayRankPasswordEnd(struct ProcSecretScreen *proc)
{
	Proc_End(proc->subproc);
	SetDispEnable(0, 0, 0, 0, 0);
}

ProcPtr NewPassword(ProcPtr parent)
{
	return SpawnProcLocking(ProcScr_Prep_Password, parent);
}

void SecretScreen_EncodeUnitData(int *counter, u8 *buf)
{
	int i, j;

	gSecretScreenRN = gSecretScreenInitSeed;

	for (i = 0; i < 5; i++) {
		SecretScreen_WriteBits(buf, counter, gSecretScreenData[i].numbers[0], 8);
		SecretScreen_WriteBits(buf, counter, gSecretScreenData[i].numbers[1], 1);
		SecretScreen_WriteBits(buf, counter, gSecretScreenData[i].numbers[2], 5);
		SecretScreen_WriteBits(buf, counter, gSecretScreenData[i].numbers[3], 6);
		SecretScreen_WriteBits(buf, counter, gSecretScreenData[i].numbers[4], 5);
		SecretScreen_WriteBits(buf, counter, gSecretScreenData[i].numbers[5], 5);
		SecretScreen_WriteBits(buf, counter, gSecretScreenData[i].numbers[6], 5);
		SecretScreen_WriteBits(buf, counter, gSecretScreenData[i].numbers[7], 5);
		SecretScreen_WriteBits(buf, counter, gSecretScreenData[i].numbers[8], 5);
		SecretScreen_WriteBits(buf, counter, gSecretScreenData[i].numbers[9], 5);
		SecretScreen_WriteBits(buf, counter, gSecretScreenData[i].numbers[10], 5);

		for (j = 0; j < 8; j++)
			SecretScreen_WriteBits(buf, counter, gSecretScreenData[i].numbers[11 + j], 3);

		for (j = 0; j < 5; j++)
			SecretScreen_WriteBits(buf, counter, gSecretScreenData[i].numbers[19 + j], 8);
	}

	for (i = 0; i < 10; i++)
		SecretScreen_WriteBits(buf, counter, gSecretScreenSupportLevels[i], 2);
}

void SecretScreen_DecodeUnitData(int *counter, u8 *buf)
{
	int i, j;
	struct SecretScreenData *data;

	gSecretScreenRN = gSecretScreenInitSeed;

	data = gSecretScreenData;

	for (i = 0; i < 5; i++) {
		gSecretScreenData[i].numbers[0]  = SecretScreen_ReadBits(buf, counter, 8);
		gSecretScreenData[i].numbers[1]  = SecretScreen_ReadBits(buf, counter, 1);
		gSecretScreenData[i].numbers[2]  = SecretScreen_ReadBits(buf, counter, 5);
		gSecretScreenData[i].numbers[3]  = SecretScreen_ReadBits(buf, counter, 6);
		gSecretScreenData[i].numbers[4]  = SecretScreen_ReadBits(buf, counter, 5);
		gSecretScreenData[i].numbers[5]  = SecretScreen_ReadBits(buf, counter, 5);
		gSecretScreenData[i].numbers[6]  = SecretScreen_ReadBits(buf, counter, 5);
		gSecretScreenData[i].numbers[7]  = SecretScreen_ReadBits(buf, counter, 5);
		gSecretScreenData[i].numbers[8]  = SecretScreen_ReadBits(buf, counter, 5);
		gSecretScreenData[i].numbers[9]  = SecretScreen_ReadBits(buf, counter, 5);
		gSecretScreenData[i].numbers[10] = SecretScreen_ReadBits(buf, counter, 5);

		for (j = 0; j < 8; j++)
			gSecretScreenData[i].numbers[11 + j] = SecretScreen_ReadBits(buf, counter, 3);

		for (j = 0; j < 5; j++)
			gSecretScreenData[i].numbers[19 + j] = SecretScreen_ReadBits(buf, counter, 8);
	}

	for (i = 0; i < 10; i++)
		gSecretScreenSupportLevels[i] = SecretScreen_ReadBits(buf, counter, 2);
}

int GetFlattenArrayOffset(int line, int col)
{
	int i, j;
	int ret = 0;

	for (i = 0; i < 5; i++) {
		for (j = (i + 1); j < 5; j++) {
			if (i == line && j == col)
				return (u8)ret;

			ret++;
		}
	}
	return 0;
}

void SecretScreen_PackUnitData(struct Unit *units[], int count)
{
	int i, j, k;

	for (i = 0; i < count; i++) {
		_UNUSED struct Unit *u = units[i];

		gSecretScreenData[i].numbers[0] = units[i]->pinfo->id;
		gSecretScreenData[i].numbers[1] = !!(UNIT_ATTRIBUTES(units[i]) & UNIT_ATTR_PROMOTED);
		gSecretScreenData[i].numbers[2] = units[i]->level & 0x1F;
		gSecretScreenData[i].numbers[3] = units[i]->max_hp & 0x3F;
		gSecretScreenData[i].numbers[4] = units[i]->pow & 0x1F;
		gSecretScreenData[i].numbers[5] = units[i]->skl & 0x1F;
		gSecretScreenData[i].numbers[6] = units[i]->spd & 0x1F;
		gSecretScreenData[i].numbers[7] = units[i]->def & 0x1F;
		gSecretScreenData[i].numbers[8] = units[i]->res & 0x1F;
		gSecretScreenData[i].numbers[9] = units[i]->lck & 0x1F;
		gSecretScreenData[i].numbers[10] = UNIT_CON(units[i]) & 0x1F;

		for (j = 0; j < 8; j++)
			gSecretScreenData[i].numbers[11 + j] = GetWeaponLevelFromExp(units[i]->wexp[j]) & 7;

		for (j = 0; j < 5; j++)
			gSecretScreenData[i].numbers[0x13 + j] = GetItemIid(units[i]->items[j]);
	}

	gSecretScreenRN = (GetGameTime() << 0xD) >> 0x10;

	for (; i < SID_PID_POOL_SIZE; i++) {
		gSecretScreenData[i].numbers[0] = 0;
		gSecretScreenData[i].numbers[1] = GetSecretScreenRN() & 1;
		gSecretScreenData[i].numbers[2] = GetSecretScreenRN() & 0x1F;
		gSecretScreenData[i].numbers[3] = GetSecretScreenRN() & 0x3F;
		gSecretScreenData[i].numbers[4] = GetSecretScreenRN() & 0x1F;
		gSecretScreenData[i].numbers[5] = GetSecretScreenRN() & 0x1F;
		gSecretScreenData[i].numbers[6] = GetSecretScreenRN() & 0x1F;
		gSecretScreenData[i].numbers[7] = GetSecretScreenRN() & 0x1F;
		gSecretScreenData[i].numbers[8] = GetSecretScreenRN() & 0x1F;
		gSecretScreenData[i].numbers[9] = GetSecretScreenRN() & 0x1F;
		gSecretScreenData[i].numbers[10] = GetSecretScreenRN() & 0x1F;

		for (j = 0; j < 8; j++)
			gSecretScreenData[i].numbers[11 + j] = GetSecretScreenRN() & 7;

		for (j = 0; j < 5; j++)
			gSecretScreenData[i].numbers[0x13 + j] = GetSecretScreenRN();
	}

	for (i = 0; i < 10; i++)
		gSecretScreenSupportLevels[i] = 0;

	for (i = 0; i < count; i++) {
		u8 supp = GetUnitSupportCount(units[i]);

		for (j = 0; j < supp; j++) {
			u8 pid = GetUnitSupportPid(units[i], j);

			for (k = (i + 1); k < count; k++) {
				int tmp_r4, supp_lv;

				if (gSecretScreenData[k].numbers[0] != pid)
					continue;

				tmp_r4 = GetFlattenArrayOffset(i, k);
				supp_lv = GetUnitSupportLevel(units[i], j);

				gSecretScreenSupportLevels[(u8)tmp_r4] = supp_lv & 3;
			}
		}
	}
}

void PrintSecretScreenTexts(struct Text *text, const u8 *table)
{
	char str[4];
	int line;

	str[2] = '\0';

	EnableBgSync(BG2_SYNC_BIT);
	InitTalkTextFont();

	for (line = 0; line < SID_PID_POOL_SIZE; line++) {
		int i, x_offset;

		ClearText(&text[line]);

		x_offset = 0;

		for (i = 0; i < 0x13;) {
			const u8 *cur;
			int loc = line * 0x13 + i;

			if (loc == (gSecretScreenPasswordMeta.tail_len + gSecretScreenSymbolCount))
				return;

			cur = table + gSecretScreenPasswordBuf[loc] * 2;

			/* This JP character! */
			str[0] = cur[0];
			str[1] = cur[1];

			PutDrawText(&text[line], gBg2Tm + TM_OFFSET(2, 3 * line + 3), TEXT_COLOR_SYSTEM_GRAY, x_offset, 0, str);
			x_offset += 10;
			i++;

			if ((i % 6) == 0) {
				if ((i / 6) < 3)
					x_offset += 10;
			}
		}
	}
}

void PutSecretScreenLineNumber(int y)
{
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(0x02, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenData->numbers[0]);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(0x04, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenData->numbers[1]);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(0x07, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenData->numbers[2]);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(0x0A, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenData->numbers[3]);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(0x0D, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenData->numbers[4]);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(0x10, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenData->numbers[5]);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(0x13, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenData->numbers[6]);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(0x16, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenData->numbers[7]);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(0x19, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenData->numbers[8]);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(0x1C, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenData->numbers[9]);
	PutNumberOrBlank(gBg2Tm + TM_OFFSET(0x1F, y), TEXT_COLOR_SYSTEM_BLUE, gSecretScreenData->numbers[10]);
}

void SecretScreen_Init(struct ProcSecretScreen *proc)
{
	int i;

	InitBgs(NULL);
	ResetTextFont();
	ResetText();

	proc->unk_2A = 0;

	SetDispEnable(1, 1, 1, 1, 0);

	gDispIo.bg0_ct.priority = 1;
	gDispIo.bg1_ct.priority = 2;
	gDispIo.bg2_ct.priority = 0;
	gDispIo.bg3_ct.priority = 3;

	UnpackUiWindowFrameGraphics();
	EnablePalSync();

	TmFill(gBg0Tm, 0);
	TmFill(gBg1Tm, 0);
	TmFill(gBg2Tm, 0);
	TmFill(gBg3Tm, 0);

	SetBgOffset(0, 0, 0);
	SetBgOffset(1, 8, -8);
	SetBgOffset(2, 0, 0);
	SetBgOffset(3, 0, 0);

	SetWinEnable(0, 0, 0);

	PutUiWindowFrame(0, 2, 0x1E, 0x10, UI_WINDOW_SABLE);
	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

	for (i = 0; i < SID_PID_POOL_SIZE; i++)
		InitText(&gSecretScreenTexts[i], 0x1C);

	SecretScreen_PackUnitData(proc->units, proc->count);
	SecretScreen_InitBitstream(7, 11);
	SecretScreen_ModifyPassword(SecretScreen_EncodeUnitData);
	PrintSecretScreenTexts(gSecretScreenTexts, gSecretScreenUnitGlyphTable);
	proc->subproc = StartMuralBackground(PROC_TREE_VSYNC, NULL, BGPAL_SECRETSCREEN_MURALBG);
}

void SecretScreen_Loop_Dummy(struct ProcSecretScreen *proc) {}

void SecretScreen_End(struct ProcSecretScreen *proc)
{
	Proc_End(proc->subproc);
	SetDispEnable(0, 0, 0, 0, 0);
}

ProcPtr NewGeneralSecretScreen(ProcPtr parent)
{
	int i;
	struct ProcSecretScreen *proc;

	proc = SpawnProcLocking(ProcScr_SecretScreen, parent);
	proc->count = 0;

	for (i = 0; i < SID_PID_POOL_SIZE; i++) {
		struct Unit *unit = GetUnit(i + 1);

		proc->units[i] = unit;

		if (!unit->pinfo)
			break;

		proc->count++;
	}
	return proc;
}

ProcPtr NewUniqueSecretScreen(struct Unit *unit, ProcPtr parent)
{
	int i;
	struct ProcSecretScreen *proc;

	proc = SpawnProcLocking(ProcScr_SecretScreen, parent);
	proc->count = 0;

	for (i = 0; i < SID_PID_POOL_SIZE; i++)
		proc->units[i] = unit;

	proc->count = SID_PID_POOL_SIZE;
	return proc;
}
