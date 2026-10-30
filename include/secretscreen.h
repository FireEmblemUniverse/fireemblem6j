#pragma once

#include "prelude.h"
#include "proc.h"
#include "unit.h"
#include "text.h"

enum { SID_PID_POOL_SIZE = 5 };

struct ProcSecretScreen {
	PROC_HEADER;

	/* 2A */ u16 unk_2A;
	/* 2C */ u8 count;
	/* 30 */ struct Unit *units[SID_PID_POOL_SIZE];
	/* 44 */ ProcPtr subproc;
};

struct SecretScreenData {
	/* 00 */ u8 numbers[0x18];
};

extern struct SecretScreenData gSecretScreenData[];

/* Immediately follows gSecretScreenPasswordBuf[0xA0] in EWRAM (0x02016924 + 0xA0). */
struct SecretScreenPasswordMeta {
	u16 rn_seed;    /* +0x00: (checksum + game_time) & 0x3FF, seeds gSecretScreenRN */
	u16 checksum_b; /* +0x02: tail checksum mixed with RN, & 0x1FF */
	u16 checksum_c; /* +0x04: final tail checksum mixed with RN, & 0x1FF */
	u16 tail_len;   /* +0x06: byte length of tail checksum region */
};

struct SecretScreenPlayRankStats {
	/* 00 */ u16 total_turn;
	/* 02 */ u16 winning_rate;
	/* 04 */ u16 dead_allies;
	/* 06 */ u16 total_level_gained;
	/* 08 */ u32 total_asset;
	/* 0C */ u16 total_power;
	/* 0E */ u8 hours, minutes, secounds;
	/* 11 */ u8 unk_11;
};

extern IWRAM_DATA struct SecretScreenPlayRankStats gSecretScreenPlayRankStats;

/* Bitstream / password buffer primitives */
void SecretScreen_InitBitstream(int bit_count, int seed);
int SecretScreen_CeilDivBitCount(int a);
u16 GetSecretScreenRN(void);
void SecretScreen_WriteBits(u8 *buf, int *counter, int value, int num_bits);
void SecretScreen_ShufflePasswordBuf(void);
u32 SecretScreen_ReadBits(u8 *buf, int *counter, int round);
u16 SecretScreen_ChecksumPasswordBuf(u8 *buf, int length);

/* Password meta embed / extract */
void SecretScreen_EmbedPasswordMeta(void);
void SecretScreen_ExtractPasswordMeta(void);

/* Password encode / decode pipeline */
void SecretScreen_ModifyPassword(void (*func)(int *counter, u8 *buf));
bool SecretScreen_VerifyPassword(void (*func)(int *counter, u8 *buf));
u16 SecretScreen_FindGlyphIndex(i8 const *glyph, i8 const *table);
void SecretScreen_MapGlyphsToPasswordBuf(i8 const *str, i8 const *table);

/* Play rank password */
void SecretScreen_EncodePlayRankStats(int *counter, u8 *buf);
void SecretScreen_DecodePlayRankStats(int *counter, u8 *buf);
void SecretScreen_FillPlayRankStats(void);
void SecretScreen_PrintPlayRankPassword(struct Text *text, const u8 *table);
void SecretScreen_PrintPlayRankStatNumbers(int y);
void SecretScreen_PlayRankPasswordInit(struct ProcSecretScreen *proc);
void SecretScreen_PlayRankPasswordLoop(struct ProcSecretScreen *proc);
void SecretScreen_PlayRankPasswordEnd(struct ProcSecretScreen *proc);
ProcPtr NewPassword(ProcPtr parent);

/* Unit data encode / decode */
void SecretScreen_EncodeUnitData(int *counter, u8 *buf);
void SecretScreen_DecodeUnitData(int *counter, u8 *buf);
int GetFlattenArrayOffset(int line, int col);
void SecretScreen_PackUnitData(struct Unit *units[], int count);

/* UI */
void PrintSecretScreenTexts(struct Text *text, const u8 *table);
void PutSecretScreenLineNumber(int line);
void SecretScreen_Init(struct ProcSecretScreen *proc);
void SecretScreen_Loop_Dummy(struct ProcSecretScreen *proc);
void SecretScreen_End(struct ProcSecretScreen *proc);
ProcPtr NewGeneralSecretScreen(ProcPtr parent);
ProcPtr NewUniqueSecretScreen(struct Unit *unit, ProcPtr parent);

extern EWRAM_OVERLAY(0) int gSecretScreenBitCount;
extern EWRAM_OVERLAY(0) int gSecretScreenBitMask;
extern EWRAM_OVERLAY(0) int gSecretScreenSymbolCount;
extern EWRAM_OVERLAY(0) int gSecretScreenInitSeed;
extern EWRAM_OVERLAY(0) struct Text gSecretScreenTexts[5];
extern EWRAM_OVERLAY(0) int gSecretScreenRN;
extern EWRAM_OVERLAY(0) u8 gSecretScreenPasswordBuf[0xA0];
extern EWRAM_OVERLAY(0) struct SecretScreenPasswordMeta gSecretScreenPasswordMeta;

extern EWRAM_DATA u8 SioPidPool[SID_PID_POOL_SIZE];
extern EWRAM_DATA u8 gSecretScreenSupportLevels[10];

extern CONST_DATA u8 gSecretScreenPlayRankGlyphTable[];
extern CONST_DATA struct ProcScr ProcScr_Prep_Password[];
extern CONST_DATA u8 gSecretScreenUnitGlyphTable[];
extern CONST_DATA struct ProcScr ProcScr_SecretScreen[];
