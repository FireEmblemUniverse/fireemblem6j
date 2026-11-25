#pragma once

#include "prelude.h"

#include "proc.h"
#include "text.h"

enum
{
    INTERPOLATE_LINEAR,
    INTERPOLATE_SQUARE,
    INTERPOLATE_CUBIC,
    INTERPOLATE_POW4,
    INTERPOLATE_RSQUARE,
    INTERPOLATE_RCUBIC,
};

struct PalFadeSt
{
    /* 00 */ u16 from_colors[0x10];
    /* 20 */ u16 const * to_colors;
    /* 24 */ u16 * pal;
    /* 28 */ u16 clock;
    /* 2A */ u16 clock_end;
    /* 2C */ u16 clock_stop;
};

int Interpolate(int method, int lo, int hi, int x, int end);
void func_fe6_08013BEC(void);
bool StringEquals(char const * strA, char const * strB);
void StringCopy(char * dst, char const * src);
void Decompress_Unused_08013C74(void const * src, void * dst);
void Decompress(void const * src, void * dst);
int GetDataSize(void const * data);
void Register2dChrMove(u8 const * img, u8 * vram, int width, int height);
void Copy2dChr(void const * src, u8 * dst, int width, int height);
void ApplyBitmap(u8 const * src, void * dst, int width, int height);
void PutAppliedBitmap(u16 * tm, int tileref, int width, int height);
void PutDigits(u16 * tm, u8 const * src, int tileref, int len);
// func_fe6_08013EBC
// func_fe6_08013EC4
// func_fe6_08013ED8
void func_fe6_08013EE4(i16 * array);
void func_fe6_08013F04(i16 * array, int x_a, int y_a, int x_b, int y_b);
struct Vec2i * func_fe6_08013F7C(int arg_0);
void DarkenPals(int reduction);
// func_fe6_0801412C
// func_fe6_08014130
void StartSpacialSeTest(void);
void func_fe6_080141DC(void);
void StartPalFadeToBlack(int palid, int duration, ProcPtr parent);
void StartPalFadeToWhite(int palid, int duration, ProcPtr parent);
struct PalFadeSt * StartPalFade(u16 const * colors, int pal, int duration, ProcPtr parent);
void EndPalFade(void);
void SetPalFadeStop(struct PalFadeSt * st, int val);
void SetBlackPal(int palid);
void SetWhitePal(int palid);
void SetAllBlackPals(void);
void SetAllWhitePals(void);
bool FadeExists(void);
void StartFadeToBlack(int q4_speed);
void StartFadeFromBlack(int q4_speed);
void StartLockingFadeToBlack(int q4_speed, ProcPtr parent);
void StartLockingFadeFromBlack(int q4_speed, ProcPtr parent);
void StartLockingFadeToWhite(int q4_speed, ProcPtr parent);
void StartLockingFadeFromWhite(int q4_speed, ProcPtr parent);
void StartMidFadeToBlack(void);
void StartSlowFadeToBlack(void);
void StartFastFadeToBlack(void);
void StartMidFadeFromBlack(void);
void StartSlowFadeFromBlack(void);
void StartFastFadeFromBlack(void);
void StartMidLockingFadeToBlack(ProcPtr parent);
void StartSlowLockingFadeToBlack(ProcPtr parent);
void StartFastLockingFadeToBlack(ProcPtr parent);
void StartMidLockingFadeFromBlack(ProcPtr parent);
void StartSlowLockingFadeFromBlack(ProcPtr parent);
void StartFastLockingFadeFromBlack(ProcPtr parent);
void StartSlowLockingFadeToWhite(ProcPtr parent);
void StartSlowLockingFadeFromWhite(ProcPtr parent);
// func_fe6_08014778
void func_fe6_08014790(ProcPtr parent);
// func_fe6_080147A8
// func_fe6_080147C0
// func_fe6_080147D8
// func_fe6_080147F0
// func_fe6_08014804
// func_fe6_08014818
// func_fe6_0801482C
void FadeInBlackWithCallBack_Speed04(ProcPtr parent);
void FadeInBlackWithCallBack_Speed08(ProcPtr parent);
void FadeInBlackWithCallBack_Speed10(ProcPtr parent);
void FadeInBlackWithCallBack_Speed20(ProcPtr parent);
void FadeInBlackWithCallBack_Speed40(ProcPtr parent);
void FadeInBlackSpeed04(ProcPtr parent);
void FadeInBlackSpeed08(ProcPtr parent);
void FadeInBlackSpeed08Unk(ProcPtr parent);
void FadeInBlackSpeed10(ProcPtr parent);
void FadeInBlackSpeed20(ProcPtr parent);
void FadeInBlackSpeed40(ProcPtr parent);
// func_fe6_08014934
// func_fe6_08014948
// func_fe6_0801495C
// func_fe6_08014970
void func_fe6_08014984(ProcPtr parent);
void func_fe6_08014998(ProcPtr parent);
void WhileFadeExists(ProcPtr proc);
// func_fe6_080149CC
void StartFadeCore(int kind, int speed, ProcPtr parent, Func end_callback);
// EndFadeCore
// ColFade_Init
// ColFade_Loop
// ColFade_Step
void func_fe6_08014AB8(void);
void func_fe6_08014ACC(int a, int b);
void RemoveFadeCoreCallBack(void);
void Fade_CommonCallBack(void);
void func_fe6_08014B68(void);
void StartTemporaryLock(ProcPtr proc, int arg_1);
int NumberToString(int number, char * buf);
struct Text * PutStringCentered(u16 * tm, int color, int width, char const * str);
struct Text * PutString(u16 * tm, int color, char const * str);
void func_fe6_08014D50(void);
// func_fe6_08014D60
void func_fe6_08014D9C(u16 const * colors, int pal_offset, int pal_size, int interval, ProcPtr parent);
void func_fe6_08014DB4(u16 const * colors, int pal_offset, int pal_size, int interval, ProcPtr parent);
// func_fe6_08014DCC
void func_fe6_08014E30(u16 * tm, int x, int y, u16 tileref, int width, int height);
void func_fe6_08014E98(u16 * tm, int x, int y, u16 tileref, int width, int height, u16 const * src, bool hflip);
void func_fe6_08014F70(u16 * tm, int x, int y, u16 tileref, int width, int height, u16 const * src, int arg_7);
void func_fe6_0801501C(u16 * tm, int x, int y, u16 tileref, int width, int height, u8 const * src, int arg_7);
// func_fe6_080150DC
void CallDelayed(void (* func)(void), int delay);
void CallDelayedArg(void (* func)(int), int arg, int delay);
void ClearBytes(u8 * out, int size);
// FillBytes
void FillHalfwords(u16 * out, int size, int value);
void StartPartialGameLock(ProcPtr proc);
void VramCopy(void const * src, void * dst, int size);
void func_fe6_08015298(u8 const * src, u8 * dst, int width, int height);
void PutTmLinear(u16 const * src, u16 * dst, int size, u16 tileref);
u16 * GetTmOffsetById(int bgid, int x, int y);
void Clear4bppFirstTile(void);
int Screen2Pan(int x);
void PlaySeSpacial(int song, int x);
void PlaySeDelayed(int song, int delay);
void _StartBgm(short song);
void _FadeBgmOut(short speed);
void DarkenPalette(int palid);
void PutDrawTextCentered(struct Text * text, int x, int y, char const * str, int width);
void VecMulMat(int const * vec, int const * mat, int * ovec);
void MatMulMat(int const * lmat, int const * rmat, int * omat);
void MatIdent(int * mat);
void MatCopy(int const * src, int * dst);
void MatRotA(int * mat, short angle);
void MatRotB(int * mat, short angle);
void MatRotC(int * mat, short angle);
void func_fe6_08015858(void);
int VecDotVec(int const * lvec, int const * rvec);
void VecCrossVec(int const * lvec, int const * rvec, int * ovec);
int func_fe6_080158B8(int arg_0, int arg_1, int arg_2, int arg_3);

extern u16 CONST_DATA Pal_AllBlack[];
extern u16 CONST_DATA Pal_AllWhite[];
extern u16 CONST_DATA Pal_AllRed[];
extern u16 CONST_DATA Pal_AllGreen[];
extern u16 CONST_DATA Pal_AllBlue[];
extern u16 CONST_DATA Pal_085C4F2C[];
