#pragma once

#include "gba.h"
#include "types.h"

#include "proc.h"

// code_0802B814.c
// func_fe6_0802B814
// func_fe6_0802B8A0
// func_fe6_0802B928
// func_fe6_0802B964
// func_fe6_0802B980
// func_fe6_0802B99C
int func_fe6_0802B9DC(void);
int func_fe6_0802BA08(void);
void func_fe6_0802BA44(struct Unit * unit);

u32 SioStrCpy(void const * src, void * dst);
int CheckInLinkArena(void);
void func_fe6_08036994(void);
int CheckDisplayPasswordScreenCombo(void);
void StartLinkArenaMainMenu(ProcPtr parent);
void StartEvent_SioXmap_0803C080(ProcPtr parent);
void func_fe6_0803CF58(void);

// func_fe6_0808AA84
// func_fe6_0808AB44

/* xmap.h */
/* config.h */
/* ending_credit */

/* worldmap.h */
/* monologue.h */
/* shop.h */
/* arena_ui.h */
/* suspend_ui.h */
/* opanim.h */
/* titlescreen.h */
