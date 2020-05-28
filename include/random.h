
#pragma once

#include "common.h"

void RandInit(int seed);

void RandSetSt(u16 const* st);
void RandGetSt(u16* st);

int RandNext_100(void);
int RandNext(int max);
Bool RandRoll(int threshold);
Bool RandRoll2Rn(int threshold);

void RandInitB(int seed);
unsigned RandNextB(void);