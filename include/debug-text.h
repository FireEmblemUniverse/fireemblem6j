
#pragma once

#include "gba/gba.h"

void DebugInitBg(int bg, int vramOffset);
void DebugPutStr(u16* tm, char const* str);
void DebugPutFmt(u16* tm, char const* fmt, ...);

void GenNumberStr(int number);
void GenNumberOrBlankStr(int number);
void GenNumberHexStr(int number);

void DebugScreenInit(void);
void DebugPrintFmt(char const* fmt, ...);
void DebugPrintNumber(int number, int length);
void DebugPrintNumberHex(int number, int length);
void DebugPrintStr(char const* str);
void DebugPutScreen(void);
s8 DebugUpdateScreen(u16 held, u16 pressed);

void DebugInitObj(int offset, int palid);
void DebugPutObjStr(int x, int y, char const* str);
void DebugPutObjNumber(int x, int y, int number, int length);
void DebugPutObjNumberHex(int x, int y, int number, int length);
