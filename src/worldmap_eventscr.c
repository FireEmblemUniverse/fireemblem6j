#include "prelude.h"
#include "event.h"
#include "monologue.h"
#include "worldmap.h"
#include "constants/msg.h"
#include "constants/faces.h"
#include "constants/worldmap.h"

CONST_DATA EventScr EventScr_Wm_Tutorial[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmTalkBoxTop
    EvtWmPutMapText(0, 0xC8, 0xB4, WM_MAPTEXT_LOC_02, 0, 0)
    EvtSleep(20)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_3)
    EvtWmTalk(MSG_B6B)
    EvtWmRemoveBothHighlights
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmTalkBoxRemove
    EvtSleep(2)
    EvtWmZoomTo(0xB4, 0x96)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x14A, 0xDE, 1)
    EvtWmPutMapText(1, 0x14A, 0xDE, WM_MAPTEXT_LOC_0D, 0, 1)
    EvtSleep(20)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_B6C)
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmRemoveDot(0)
    EvtWmRemoveDot(1)
    EvtStartWmDot(0, 0xF4, 0xB3, 1)
    EvtWmPutMapText(1, 0xF4, 0xB3, WM_MAPTEXT_LOC_18, 3, 1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmTalk(MSG_B6D)
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_34)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch1[] = {
    EvtFunc(StartIntroMonologue)
    EvtSleep(1)
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmTalkBoxBottom
    EvtWmTalk(MSG_A76)
    EvtWmPutMapText(0, 0x50, 0x64, WM_MAPTEXT_LOC_00, 0, 0)
    EvtSleep(20)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_6)
    EvtWmTalk(MSG_A77)
    EvtWmRemoveBothHighlights
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmTalkBoxRemove
    EvtSleep(2)
    EvtWmPutMapText(0, 0xF0, 0xA0, WM_MAPTEXT_LOC_01, 0, 0)
    EvtSleep(20)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_4)
    EvtWmTalkBoxTop
    EvtWmTalk(MSG_A78)
    EvtWmRemoveBothHighlights
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmTalkBoxRemove
    EvtSleep(2)
    EvtWmTalkBoxBottom
    EvtWmPutHighlight(0, WM_HIGHLIGHT_NATION_6)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_4)
    EvtWmTalk(MSG_A79)
    EvtWmRemoveBothHighlights
    EvtWmTalkBoxRemove
    EvtSleep(2)
    EvtWmPutMapText(0, 0xC8, 0xB4, WM_MAPTEXT_LOC_02, 0, 0)
    EvtSleep(20)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_3)
    EvtWmTalkBoxTop
    EvtWmTalk(MSG_A7A)
    EvtWmRemoveBothHighlights
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmTalkBoxRemove
    EvtSleep(2)
    EvtWmPutMapText(1, 0x136, 0x3C, WM_MAPTEXT_LOC_03, 0, 0)
    EvtSleep(20)
    EvtWmPutHighlight(0, WM_HIGHLIGHT_NATION_5)
    EvtWmTalkBoxBottom
    EvtWmTalk(MSG_A7B)
    EvtWmRemoveBothHighlights
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmPutMapText(0, 0x154, 0x8C, WM_MAPTEXT_LOC_0A, 0, 0)
    EvtSleep(20)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_1)
    EvtWmTalk(MSG_A7C)
    EvtWmRemoveBothHighlights
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmTalk(MSG_A7D)
    EvtWmTalkBoxRemove
    EvtSleep(2)
    EvtWmPutFace(0, 0x28, 0x2C, FID_49)
    EvtSleep(20)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_4)
    EvtWmTalkBoxTop
    EvtWmTalk(MSG_A7E)
    EvtWmRemoveBothHighlights
    EvtWmTalkBoxRemove
    EvtSleep(2)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_4)
    EvtWmTalkBoxBottom
    EvtWmPutArrow(42, 0)
    EvtWmPutArrow(41, 0)
    EvtWmTalk(MSG_A7F)
    EvtWmPutArrow(43, 0)
    EvtTalkContinue
    EvtWmRemoveBothHighlights
    EvtFunc(EndWmArrow)
    EvtWmTalkBoxRemove
    EvtSleep(2)
    EvtWmZoomTo(0xB4, 0x96)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x14A, 0xDE, 1)
    EvtWmPutMapText(1, 0x14A, 0xDE, WM_MAPTEXT_LOC_0D, 0, 1)
    EvtSleep(20)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_A80)
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmRemoveDot(0)
    EvtWmRemoveDot(1)
    EvtStartWmDot(0, 0xF4, 0xB3, 1)
    EvtWmPutMapText(1, 0xF4, 0xB3, WM_MAPTEXT_LOC_18, 3, 1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtStartWmDot(1, 0x14A, 0xDE, 1)
    EvtWmPutMapText(0, 0x14A, 0xDE, WM_MAPTEXT_LOC_0D, 0, 1)
    EvtSleep(20)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_56)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmTalk(MSG_A81)
    EvtWmPutFace(0, 0x28, 0x2C, FID_58)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_22)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtSleep(30)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_A82)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_09)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutArrow(44, 1)
    EvtTalkContinue
    EvtFunc(EndWmArrow)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmRemoveDot(0)
    EvtWmPutFlag(0, 0x14C, 0xEB, 1)
    EvtWmPutMapText(1, 0x14A, 0xDE, WM_MAPTEXT_LOC_0D, 0, 1)
    EvtSleep(20)
    EvtWmTalk(MSG_A83)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch2[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmPutHighlight(0, WM_HIGHLIGHT_NATION_3)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_4)
    EvtWmTalkBoxTop
    EvtWmTalk(MSG_A8A)
    EvtStartWmDot(0, 0x153, 0xCF, 1)
    EvtTalkContinue
    EvtWmRemoveBothHighlights
    EvtWmRemoveDot(0)
    EvtWmRemoveDot(1)
    EvtWmTalkBoxRemove
    EvtSleep(2)
    EvtWmZoomTo(0xB4, 0x8C)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x14A, 0xDE, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmPutArrow(2, 1)
    EvtWmTalk(MSG_A8B)
    EvtWmPutFlag(0, 0x153, 0xCF, 1)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch3[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0xB4, 0x8C)
    EvtWmPutMapText(0, 0x13E, 0xB3, WM_MAPTEXT_LOC_1C, 0, 1)
    EvtSleep(20)
    EvtWmTalkBoxBottom
    EvtWmTalk(MSG_A8F)
    EvtWmPutFlag(0, 0x13E, 0xB3, 1)
    EvtTalkContinue
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtStartWmDot(0, 0x153, 0xCF, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_57)
    EvtSleep(20)
    EvtWmPutArrow(3, 1)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmTalk(MSG_A90)
    EvtWmPutFace(0, 0x28, 0x2C, FID_48)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_42)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmTalk(MSG_A91)
    EvtWmRemoveDot(0)
    EvtWmRemoveDot(1)
    EvtFunc(EndWmArrow)
    EvtWmPutMapText(0, 0x13E, 0xB3, WM_MAPTEXT_LOC_1C, 0, 1)
    EvtSleep(20)
    EvtWmPutFace(1, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmPutArrow(45, 1)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch4[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x9C, 0x78)
    EvtWmTalkBoxBottom
    EvtWmPutFace(0, 0x79, 0x2C, FID_58)
    EvtSleep(20)
    EvtWmTalk(MSG_A98)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtStartWmDot(0, 0x13E, 0xB3, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_22)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtSleep(20)
    EvtStartWmDot(1, 0xF4, 0xB3, 1)
    EvtWmPutMapText(0, 0xF4, 0xB3, WM_MAPTEXT_LOC_18, 0, 1)
    EvtSleep(20)
    EvtWmPutArrow(4, 1)
    EvtTalkContinue
    EvtWmRemoveMapText(0)
    EvtSleep(20)
    EvtWmPutFlag(0, 0x125, 0xC1, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_3A)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch5[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x9C, 0x78)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x125, 0xC1, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_3A)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_A99)
    EvtWmRemoveFace(0)
    EvtSleep(20)
    EvtTalkContinue
    EvtStartWmDot(1, 0xF4, 0xB3, 1)
    EvtWmPutMapText(0, 0xF4, 0xB3, WM_MAPTEXT_LOC_18, 0, 1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFlag(0, 0x113, 0xBB, 1)
    EvtWmPutArrow(5, 1)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch6[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x9C, 0x78)
    EvtWmTalkBoxBottom
    EvtStartWmDot(1, 0xF4, 0xB3, 1)
    EvtStartWmDot(0, 0x113, 0xBB, 1)
    EvtWmTalk(MSG_A9F)
    EvtWmPutFace(0, 0x28, 0x2C, FID_0E)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_0C)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutArrow(6, 1)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutMapText(1, 0x106, 0xB7, WM_MAPTEXT_LOC_1B, 2, 2)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmTalk(MSG_AA0)
    EvtFunc(EndWmArrow)
    EvtWmRemoveDot(0)
    EvtWmPutFlag(0, 0x106, 0xB7, 1)
    EvtWmPutFace(0, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_AA1)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch7[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x8C, 0x78)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x106, 0xB7, 1)
    EvtWmPutFlag(0, 0xF4, 0xB3, 1)
    EvtWmPutMapText(0, 0xF4, 0xB3, WM_MAPTEXT_LOC_18, 0, 1)
    EvtSleep(20)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmPutArrow(7, 1)
    EvtWmTalk(MSG_AA5)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmTalk(MSG_AA6)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_44)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(0, 0x28, 0x2C, FID_3C)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtSleep(20)
    EvtSleep(30)
    EvtWmPutFace(0, 0x28, 0x2C, FID_22)
    EvtSleep(20)
    EvtWmTalk(MSG_AA7)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtSleep(30)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_AA8)
    EvtWmTalk(MSG_AA9)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch8[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x8C, 0x78)
    EvtWmTalkBoxBottom
    EvtWmPutFlag(0, 0xF4, 0xB3, 1)
    EvtWmPutMapText(0, 0xF4, 0xB3, WM_MAPTEXT_LOC_18, 0, 1)
    EvtSleep(20)
    EvtWmPutFace(1, 0x28, 0x2C, FID_58)
    EvtSleep(20)
    EvtWmTalk(MSG_AAE)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch9[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0xF4, 0xB3, 1)
    EvtWmPutFace(0, 0xC8, 0x2C, FID_42)
    EvtSleep(20)
    EvtWmTalk(MSG_ABA)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtSleep(10)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_4)
    EvtTalkContinue
    EvtWmRemoveBothHighlights
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtSleep(30)
    EvtWmPutFace(0, 0x28, 0x2C, FID_56)
    EvtSleep(20)
    EvtWmTalk(MSG_ABB)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtSleep(20)
    EvtWmPutHighlight(0, WM_HIGHLIGHT_NATION_6)
    EvtWmTalk(MSG_ABC)
    EvtWmRemoveBothHighlights
    EvtWmPutHighlight(0, WM_HIGHLIGHT_NATION_0)
    EvtTalkContinue
    EvtWmTalk(MSG_ABD)
    EvtWmPutArrow(46, 1)
    EvtTalkContinue
    EvtWmRemoveBothHighlights
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmRemoveDot(0)
    EvtWmRemoveDot(1)
    EvtFunc(EndWmArrow)
    EvtWmZoomTo(0x00, 0x3C)
    EvtWmPutFlag(0, 0x94, 0x7E, 1)
    EvtWmTalk(MSG_ABE)
    EvtWmPutFace(0, 0x28, 0x2C, FID_51)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_3E)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch10a[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x00, 0x2C)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x94, 0x7E, 1)
    EvtWmTalk(MSG_ACA)
    EvtWmPutMapText(0, 0x40, 0x64, WM_MAPTEXT_LOC_05, 0, 0)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmTalkBoxRemove
    EvtSleep(2)
    EvtWmTalkBoxTop
    EvtWmTalk(MSG_ACB)
    EvtWmPutMapText(0, 0x02, 0xA8, WM_MAPTEXT_LOC_08, 0, 0)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmTalkBoxRemove
    EvtSleep(2)
    EvtWmTalkBoxBottom
    EvtWmTalk(MSG_ACC)
    EvtWmPutMapText(0, 0x88, 0x48, WM_MAPTEXT_LOC_09, 0, 0)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutMapText(1, 0x79, 0x56, WM_MAPTEXT_LOC_10, 0, 1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutArrow(10, 1)
    EvtTalkContinue
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmPutFace(0, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmPutFlag(0, 0x87, 0x66, 1)
    EvtWmTalk(MSG_ACD)
    EvtWmPutFace(1, 0x28, 0x2C, FID_E4)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch11a[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x00, 0x2C)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x87, 0x66, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_26)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_ACE)
    EvtWmRemoveFace(0)
    EvtSleep(20)
    EvtSleep(10)
    EvtWmPutFace(0, 0x28, 0x2C, FID_34)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtSleep(20)
    EvtWmPutMapText(0, 0x79, 0x56, WM_MAPTEXT_LOC_10, 0, 1)
    EvtSleep(20)
    EvtWmPutArrow(11, 1)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutFlag(0, 0x79, 0x56, 1)
    EvtWmTalk(MSG_ACF)
    EvtWmPutFace(1, 0x28, 0x2C, FID_40)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmTalk(MSG_AD0)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch12[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtGotoIfNotFlag(0, 106)
    EvtWmZoomTo(0x00, 0x2C)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x79, 0x56, 1)
    EvtWmPutMapText(1, 0x66, 0x62, WM_MAPTEXT_LOC_1D, 3, 1)
    EvtSleep(20)
    EvtWmTalk(MSG_ADC)
    EvtWmPutFace(0, 0xC8, 0x2C, FID_46)
    EvtSleep(20)
    EvtWmTalk(MSG_ADD)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutFlag(0, 0x66, 0x62, 1)
    EvtWmTalk(MSG_ADE)
    EvtWmPutFace(0, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmPutArrow(12, 1)
    EvtTalkContinue
    EvtGoto(1)
EvtLabel(0)
    EvtWmZoomTo(0x00, 0x58)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x3D, 0xC6, 1)
    EvtWmPutMapText(1, 0x66, 0x62, WM_MAPTEXT_LOC_1D, 3, 1)
    EvtSleep(20)
    EvtWmTalk(MSG_ADC)
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmPutFace(0, 0xC8, 0x2C, FID_46)
    EvtSleep(20)
    EvtWmTalk(MSG_ADD)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutFlag(0, 0x66, 0x62, 1)
    EvtWmTalk(MSG_ADE)
    EvtWmPutFace(0, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmPutArrow(28, 1)
    EvtTalkContinue
EvtLabel(1)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch10b[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x00, 0x2C)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x94, 0x7E, 1)
    EvtWmPutFace(0, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_AD4)
    EvtWmPutArrow(26, 1)
    EvtTalkContinue
    EvtWmPutFlag(0, 0x73, 0x88, 1)
    EvtWmTalk(MSG_AD5)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch11b[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x00, 0x70)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x73, 0x88, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_2B)
    EvtSleep(20)
    EvtWmTalk(MSG_AD8)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutMapText(0, 0x02, 0xA8, WM_MAPTEXT_LOC_08, 0, 0)
    EvtSleep(20)
    EvtWmPutArrow(27, 1)
    EvtTalkContinue
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmPutMapText(0, 0x3D, 0xC6, WM_MAPTEXT_LOC_14, 0, 1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmTalk(MSG_AD9)
    EvtWmPutFlag(0, 0x49, 0xBB, 1)
    EvtWmTalk(MSG_ADA)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch13[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmTalkBoxBottom
    EvtWmPutMapText(0, 0xCD, 0xAE, WM_MAPTEXT_LOC_20, 1, 1)
    EvtSleep(20)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_6)
    EvtWmTalk(MSG_AE8)
    EvtWmRemoveBothHighlights
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmPutFace(0, 0x28, 0x2C, FID_34)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_57)
    EvtSleep(20)
    EvtWmTalk(MSG_AE9)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_4)
    EvtTalkContinue
    EvtWmRemoveBothHighlights
    EvtWmPutFace(0, 0x79, 0x2C, FID_59)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_0A)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(0, 0x28, 0x2C, FID_1A)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmTalkBoxRemove
    EvtSleep(2)
    EvtWmTalkBoxTop
    EvtWmTalk(MSG_AEA)
    EvtWmPutMapText(1, 0x5E, 0xFF, WM_MAPTEXT_LOC_04, 0, 0)
    EvtSleep(20)
    EvtWmPutFlag(0, 0x40, 0x10C, 1)
    EvtTalkContinue
    EvtWmPutFace(0, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_AEB)
    EvtWmTalkBoxRemove
    EvtSleep(2)
    EvtWmPutArrow(13, 1)
    EvtSleep(90)
    EvtWmTalkBoxTop
    EvtWmTalk(MSG_AEC)
    EvtWmTalk(MSG_AED)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch14[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x00, 0xA0)
    EvtWmTalkBoxTop
    EvtStartWmDot(0, 0x40, 0x10C, 1)
    EvtWmPutMapText(1, 0x5E, 0xFF, WM_MAPTEXT_LOC_06, 1, 0)
    EvtSleep(20)
    EvtWmPutFace(0, 0xC8, 0x50, FID_02)
    EvtWmTalk(MSG_AF3)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtSleep(30)
    EvtWmPutFace(0, 0xC8, 0x50, FID_2D)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmPutArrow(14, 1)
    EvtWmTalk(MSG_AF4)
    EvtWmPutFlag(0, 0xA0, 0xF7, 1)
    EvtWmTalk(MSG_AF5)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch15[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x00, 0xA0)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0xA0, 0xF7, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_1B)
    EvtSleep(20)
    EvtWmTalk(MSG_AFA)
    EvtWmRemoveFace(0)
    EvtSleep(50)
    EvtWmPutArrow(15, 1)
    EvtTalkContinue
    EvtWmTalk(MSG_AFB)
    EvtWmPutFace(0, 0x79, 0x2C, FID_04)
    EvtSleep(20)
    EvtWmTalk(MSG_AFC)
    EvtWmPutFlag(0, 0xBC, 0xE6, 1)
    EvtWmTalk(MSG_AFD)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch16[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x50, 0x82)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0xBC, 0xE6, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_04)
    EvtSleep(20)
    EvtWmTalk(MSG_B00)
    EvtWmPutFlag(0, 0xCD, 0xAC, 1)
    EvtWmPutArrow(16, 1)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmRemoveFlag(0)
    EvtWmRemoveFlag(1)
    EvtWmRemoveDot(0)
    EvtWmRemoveDot(1)
    EvtFunc(EndWmArrow)
EvtWmZoomBack
    EvtStartWmDot(0, 0xCD, 0xAE, 1)
    EvtWmPutMapText(0, 0xCD, 0xAE, WM_MAPTEXT_LOC_20, 1, 1)
    EvtSleep(20)
    EvtWmTalk(MSG_B01)
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmPutFace(0, 0x28, 0x2C, FID_3D)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_46)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtSleep(10)
    EvtWmPutFace(0, 0x28, 0x2C, FID_0E)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveDot(0)
    EvtWmRemoveDot(1)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmTalk(MSG_B02)
    EvtWmPutHighlight(0, WM_HIGHLIGHT_NATION_6)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_4)
    EvtTalkContinue
    EvtWmRemoveBothHighlights
    EvtWmPutFace(1, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmPutFlag(0, 0xCD, 0xAC, 1)
    EvtTalkContinue
    EvtWmPutFace(0, 0xC8, 0x2C, FID_42)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch17c[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x50, 0x61)
    EvtWmTalkBoxBottom
    EvtWmPutFlag(0, 0xCD, 0xAE, 1)
    EvtWmPutMapText(0, 0xCD, 0xAE, WM_MAPTEXT_LOC_20, 0, 2)
    EvtSleep(20)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_B0A)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(0, 0x28, 0x2C, FID_3D)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_46)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFlag(0)
    EvtWmRemoveFlag(1)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
EvtWmZoomBack
    EvtWmPutArrow(29, 0)
    EvtWmPutMapText(1, 0x136, 0x3C, WM_MAPTEXT_LOC_03, 0, 0)
    EvtSleep(20)
    EvtWmPutHighlight(0, WM_HIGHLIGHT_NATION_5)
    EvtTalkContinue
    EvtFunc(EndWmArrow)
    EvtWmTalk(MSG_B0B)
    EvtWmRemoveBothHighlights
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_59)
    EvtSleep(20)
    EvtWmTalk(MSG_B0C)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutArrow(29, 1)
    EvtTalkContinue
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_4)
    EvtTalkContinue
    EvtWmRemoveBothHighlights
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtFunc(EndWmArrow)
    EvtWmZoomTo(0x94, 0x00)
    EvtWmPutFlag(0, 0x107, 0x56, 1)
    EvtWmTalk(MSG_B0D)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_47)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutMapText(0, 0x107, 0x56, WM_MAPTEXT_LOC_12, 0, 1)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch18c[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0xB4, 0x00)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x107, 0x56, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_46)
    EvtSleep(20)
    EvtWmTalk(MSG_B17)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutArrow(30, 1)
    EvtTalkContinue
    EvtWmPutFlag(0, 0x145, 0x4B, 1)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_D4)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch19c[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0xF0, 0x00)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x145, 0x4B, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_D4)
    EvtSleep(20)
    EvtWmTalk(MSG_B1D)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutArrow(31, 1)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(0, 0x28, 0x2C, FID_45)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFlag(0, 0x19B, 0x4E, 1)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch20c[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0xF0, 0x00)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x19B, 0x4E, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_45)
    EvtSleep(20)
    EvtWmTalk(MSG_B22)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutMapText(1, 0x1B4, 0x31, WM_MAPTEXT_LOC_15, 0, 1)
    EvtSleep(20)
    EvtWmPutArrow(32, 1)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmRemoveDot(0)
    EvtWmRemoveDot(1)
    EvtFunc(EndWmArrow)
    EvtWmPutFlag(0, 0x1B4, 0x31, 1)
    EvtWmTalk(MSG_B23)
    EvtWmPutFace(0, 0x79, 0x2C, FID_32)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(0, 0x79, 0x2C, FID_47)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtSleep(10)
    EvtWmPutFace(0, 0x79, 0x2C, FID_3D)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch17d[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x50, 0x61)
    EvtWmTalkBoxBottom
    EvtWmPutFlag(0, 0xCD, 0xAE, 1)
    EvtWmPutMapText(0, 0xCD, 0xAE, WM_MAPTEXT_LOC_20, 0, 2)
    EvtSleep(20)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_B2E)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(0, 0x28, 0x2C, FID_3D)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_46)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFlag(0)
    EvtWmRemoveFlag(1)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
EvtWmZoomBack
    EvtWmPutMapText(0, 0x154, 0x8C, WM_MAPTEXT_LOC_0A, 0, 0)
    EvtSleep(20)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_1)
    EvtWmRemoveFlag(0)
    EvtWmRemoveFlag(1)
    EvtWmPutArrow(17, 0)
    EvtTalkContinue
    EvtFunc(EndWmArrow)
    EvtWmTalk(MSG_B2F)
    EvtWmRemoveBothHighlights
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_59)
    EvtSleep(20)
    EvtWmTalk(MSG_B30)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutArrow(17, 1)
    EvtTalkContinue
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_4)
    EvtTalkContinue
    EvtWmRemoveBothHighlights
    EvtTalkContinue
    EvtWmTalk(MSG_B31)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_48)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFlag(0, 0x11D, 0x90, 1)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch18d[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0xC8, 0x46)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x11D, 0x90, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_46)
    EvtSleep(20)
    EvtWmTalk(MSG_B3B)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutArrow(18, 1)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_07)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutFlag(0, 0x166, 0x8F, 1)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_CD)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch19d[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0xF0, 0x46)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x166, 0x8F, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_CD)
    EvtSleep(20)
    EvtWmTalk(MSG_B43)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmPutArrow(19, 1)
    EvtWmPutMapText(1, 0x1A6, 0x92, WM_MAPTEXT_LOC_1F, 0, 1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmTalk(MSG_B44)
    EvtWmPutFace(0, 0x28, 0x2C, FID_3D)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFlag(0, 0x1A6, 0x92, 1)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmTalk(MSG_B45)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch20d[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0xF0, 0x46)
    EvtWmTalkBoxBottom
    EvtWmPutFlag(0, 0x1A6, 0x92, 1)
    EvtWmPutMapText(0, 0x1A6, 0x92, WM_MAPTEXT_LOC_1F, 0, 1)
    EvtSleep(20)
    EvtWmPutFace(1, 0x28, 0x2C, FID_24)
    EvtSleep(20)
    EvtWmTalk(MSG_B48)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtSleep(10)
    EvtWmPutFace(1, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtSleep(30)
    EvtWmPutFace(1, 0x28, 0x2C, FID_3D)
    EvtSleep(20)
    EvtWmTalk(MSG_B49)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch21[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtGotoIfNotFlag(0, 107)
    EvtWmTalkBoxBottom
    EvtWmPutFlag(0, 0x1B4, 0x31, 1)
    EvtWmPutHighlight(0, WM_HIGHLIGHT_NATION_4)
    EvtWmTalk(MSG_B4E)
    EvtWmRemoveBothHighlights
    EvtWmRemoveFlag(0)
    EvtWmRemoveFlag(1)
    EvtStartWmDot(0, 0x1B4, 0x31, 1)
    EvtWmPutArrow(33, 1)
    EvtGoto(1)
EvtLabel(0)
    EvtWmTalkBoxBottom
    EvtWmPutFlag(0, 0x1A6, 0x92, 1)
    EvtWmPutHighlight(0, WM_HIGHLIGHT_NATION_4)
    EvtWmTalk(MSG_B4E)
    EvtWmRemoveBothHighlights
    EvtWmRemoveFlag(0)
    EvtWmRemoveFlag(1)
    EvtStartWmDot(0, 0x1A6, 0x92, 1)
    EvtWmPutArrow(21, 1)
EvtLabel(1)
    EvtWmTalk(MSG_B4F)
    EvtWmPutFlag(0, 0x1B3, 0xC8, 1)
    EvtTalkContinue
    EvtWmPutFace(1, 0x79, 0x2C, FID_47)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmRemoveDot(0)
    EvtWmRemoveDot(1)
    EvtFunc(EndWmArrow)
    EvtWmPutHighlight(0, WM_HIGHLIGHT_NATION_6)
    EvtWmPutHighlight(1, WM_HIGHLIGHT_NATION_4)
    EvtWmTalk(MSG_B50)
    EvtWmRemoveBothHighlights
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch22[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0xF0, 0xA0)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x1B3, 0xC8, 1)
    EvtWmPutFace(1, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_B57)
    EvtWmPutArrow(22, 1)
    EvtWmPutMapText(0, 0x18C, 0xD0, WM_MAPTEXT_LOC_0E, 2, 2)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmRemoveMapText(0)
    EvtWmRemoveMapText(1)
    EvtSleep(20)
    EvtWmPutFlag(0, 0x18C, 0xD0, 1)
    EvtTalkContinue
    EvtWmPutFace(0, 0xC8, 0x2C, FID_49)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmTalk(MSG_B58)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch23[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmTalkBoxBottom
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_49)
    EvtSleep(20)
    EvtWmTalk(MSG_B5C)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_4B)
    EvtSleep(20)
    EvtWmTalk(MSG_B5D)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtWmZoomTo(0xF0, 0xA0)
    EvtStartWmDot(0, 0x18C, 0xD0, 1)
    EvtWmPutArrow(23, 1)
    EvtTalkContinue
    EvtWmPutFlag(0, 0x17B, 0xE8, 1)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_48)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmTalk(MSG_B5E)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch24[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0xF0, 0xA0)
    EvtWmTalkBoxBottom
    EvtStartWmDot(0, 0x17B, 0xE8, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_B66)
    EvtWmPutArrow(24, 1)
    EvtTalkContinue
    EvtWmPutFlag(0, 0x18B, 0x103, 1)
    EvtTalkContinue
    EvtWmPutFace(1, 0xC8, 0x2C, FID_4B)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmTalk(MSG_B67)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_0868F84C[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch8x[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x8C, 0x78)
    EvtWmTalkBoxBottom
    EvtWmPutFlag(0, 0xF4, 0xB3, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_22)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_AB7)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch12x[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x00, 0x3C)
    EvtWmTalkBoxBottom
    EvtWmPutFlag(0, 0x66, 0x62, 1)
    EvtWmPutMapText(0, 0x66, 0x62, WM_MAPTEXT_LOC_1D, 3, 1)
    EvtSleep(20)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_2B)
    EvtSleep(20)
    EvtWmTalk(MSG_AE4)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtSleep(30)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_AE5)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch14x[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x00, 0xA0)
    EvtWmTalkBoxBottom
    EvtWmPutFlag(0, 0xA0, 0xF7, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_AF6)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch16x[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0x50, 0x74)
    EvtWmTalkBoxBottom
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtWmPutFace(1, 0xC8, 0x2C, FID_59)
    EvtSleep(20)
    EvtWmPutFlag(0, 0xCD, 0xAE, 1)
    EvtWmTalk(MSG_B09)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(0, 0xC8, 0x2C, FID_3D)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(1, 0x28, 0x2C, FID_D5)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch20cx[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0xF0, 0x00)
    EvtWmTalkBoxBottom
    EvtWmPutFlag(0, 0x1B4, 0x31, 1)
    EvtWmPutMapText(0, 0x1B4, 0x31, WM_MAPTEXT_LOC_15, 0, 1)
    EvtSleep(20)
    EvtWmPutFace(1, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_B2A)
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch20dx[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0xF0, 0x46)
    EvtWmTalkBoxBottom
    EvtWmPutFlag(0, 0x1A6, 0x92, 1)
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmTalk(MSG_B4B)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(0, 0x79, 0x2C, FID_CE)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_Wm_Ch21x[] = {
    EvtNoSkipNoTextSkip
    EvtFuncOnSkip(func_fe6_08093120)
    EvtWmStart
    EvtSleep(42)
    EvtYesSkip
    EvtWmZoomTo(0xF0, 0x6E)
    EvtWmTalkBoxBottom
    EvtWmPutFace(0, 0x28, 0x2C, FID_02)
    EvtSleep(20)
    EvtWmPutFlag(0, 0x1B3, 0xC8, 1)
    EvtWmTalk(MSG_B54)
    EvtWmRemoveFace(0)
    EvtWmRemoveFace(1)
    EvtSleep(20)
    EvtTalkContinue
    EvtWmPutFace(0, 0x79, 0x2C, FID_C7)
    EvtSleep(20)
    EvtTalkContinue
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};

CONST_DATA EventScr EventScr_0868FD8C[] = {
    EvtSleep(60)
    EvtFadeBgmOut(4)
    EvtWmEnd
    EvtSleep(0)
    EvtFunc(EndWmSprite)
    EvtEnd
};
