
#pragma once

#include "gba/gba.h"
#include "types.h"

struct KeySt
{
    /* 00 */ u8 repeatDelay;     // initial delay before generating auto-repeat presses
    /* 01 */ u8 repeatInterval;  // time between auto-repeat presses
    /* 02 */ u8 repeatTimer;     // (decreased by one each frame, reset to repeatDelay when Presses change and repeatInterval when reaches 0)
    /* 04 */ u16 held;           // keys that are currently held down
    /* 06 */ u16 repeated;       // auto-repeated keys
    /* 08 */ u16 pressed;        // keys that went down this frame
    /* 0A */ u16 previous;       // keys that were held down last frame
    /* 0C */ u16 last;
    /* 0E */ bool16 ABLRPressed; // 1 for Release (A B L R Only), 0 Otherwise
    /* 10 */ u16 pressed2;
    /* 12 */ u16 timeSinceStartSelect; // Time since last Non-Start Non-Select Button was pressed
};

struct DispIo
{
    /* 00 */ struct DispCnt dispCt;
    /* 04 */ struct DispStat dispStat;
    /* 08 */ u8 pad08[4];
    /* 0C */ struct BgCnt bg0Ct;
    /* 10 */ struct BgCnt bg1Ct;
    /* 14 */ struct BgCnt bg2Ct;
    /* 18 */ struct BgCnt bg3Ct;
    /* 1C */ struct Vec2u bgOff[4];
    /* 2C */ u8 win0_right, win0_left, win1_right, win1_left;
    /* 30 */ u8 win0_bottom, win0_top;
    /* 30 */ u8 win1_bottom, win1_top;
    /* 34 */ struct WinCnt winCt;
    /* 38 */ u16 mosaic;
    /* 3A */ u8 pad3A[2];
    /* 3C */ struct BlendCnt blendCt;
    /* 40 */ u8 pad40[4];
    /* 44 */ u8 blendCoeffA;
    /* 45 */ u8 blendCoeffB;
    /* 46 */ u8 blendY;
    /* 48 */ u16 bg2pa;
    /* 4A */ u16 bg2pb;
    /* 4C */ u16 bg2pc;
    /* 4E */ u16 bg2pd;
    /* 50 */ u32 bg2x;
    /* 54 */ u32 bg2y;
    /* 58 */ u16 bg3pa;
    /* 5A */ u16 bg3pb;
    /* 5C */ u16 bg3pc;
    /* 5E */ u16 bg3pd;
    /* 60 */ u32 bg3x;
    /* 64 */ u32 bg3y;
    /* 68 */ s8 colorAddition;
};

enum
{
    BG0_SYNC_BIT = (1 << 0),
    BG1_SYNC_BIT = (1 << 1),
    BG2_SYNC_BIT = (1 << 2),
    BG3_SYNC_BIT = (1 << 3),
};

extern u16 EWRAM_DATA gPal[0x200];

extern u16 EWRAM_DATA gBg0Tm[0x400];
extern u16 EWRAM_DATA gBg1Tm[0x400];
extern u16 EWRAM_DATA gBg2Tm[0x400];
extern u16 EWRAM_DATA gBg3Tm[0x400];

extern struct KeySt* CONST_DATA gKeySt;

extern struct DispIo gDispIo;

unsigned GetGameTime(void);
void SetGameTime(unsigned time);
void IncGameTime(void);
s8 FormatTime(unsigned time, u16* hours, u16* minutes, u16* seconds);
void EnableBgSync(int bits);
void EnableBgSyncById(int bgid);
void DisableBgSync(int bits);
void EnablePalSync(void);
void DisablePalSync(void);
void ApplyPaletteExt(void const* data, int startOffset, int size);
void SyncDispIo(void);
int GetBgChrOffset(int bg);
int GetBgChrId(int bg, int offset);
int GetBgTilemapOffset(int bg);
void SetBgChrOffset(int bg, int offset);
void SetBgTilemapOffset(int bg, int offset);
void SetBgScreenSize(int bg, int size);
void SetBgBpp(int bg, int bpp);
void SyncBgsAndPal(void);
void FillTm(u16* dest, int tileref);
void SetBlankChr(int chr);
void SetOnVBlank(Func func);
void SetOnVMatch(Func func);
void SetNextVCount(int vcount);
void SetVCount(int vcount);
void SetMainFunc(Func func);
void RunMainFunc(void);
void RefreshKeySt(struct KeySt* keySt);
void ClearKeySt(struct KeySt* keySt);
void InitKeySt(struct KeySt* keySt);
void SetBgOffset(u16 bgid, u16 xOffset, u16 yOffset);
void sub_8001AE4(void);
void sub_8001B18(u8 a, u8 b);
void sub_8001B4C(u16* a, u16* b);
void sub_8001B8C(void* outTm, void const* inData, u8 base, u8 linebits);
void sub_8001C68(u16* outTm, short const* inData, int unused);
void sub_8001D0C(void);
void sub_8001D44(u16 const* inPal, int bank, int count, int unk);
void sub_8001E68(int a, int b, int c, int d);
void sub_8001F88(int a, int b, int c);
void sub_8001FD4(u8 a);
void sub_800210C(u8 a);
void sub_8002234(u8 a);
void sub_80019E8(u8 a);
void sub_80024A4(void);
void InitBgs(u16 const* config);
u16* GetBgTilemap(int bg);
void SoftResetIfKeyCombo(void);
void sub_800285C(int unk);
void SetOnHBlankA(Func func);
void SetOnHBlankB(Func func);

#define RGB_GET_RED(color) ((color) & 0x1F)
#define RGB_GET_GREEN(color) (((color) >> 5) & 0x1F)
#define RGB_GET_BLUE(color) (((color) >> 10) & 0x1F)

#define TM_OFFSET(x, y) (((y) << 5) + (x))

#define TILEREF(chr, pal) ((chr) + ((pal) << 12))

#define ApplyPalettes(src, num, count) ApplyPaletteExt((src), 0x20 * (num), 0x20 * (count))
#define ApplyPalette(src, num) ApplyPalettes((src), (num), 1)

#define PAL_COLOR(palid, colornum) gPal[(palid) * 0x10 + (colornum)]
#define PAL_BG_COLOR(palid, colornum) PAL_COLOR(palid, colornum)
#define PAL_OBJ_COLOR(palid, colornum) PAL_COLOR((palid) + 0x10, colornum)
