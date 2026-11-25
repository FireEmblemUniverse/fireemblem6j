#pragma once

#include "prelude.h"

void RegisterDataMove(void const * src, void * dst, int size);
void RegisterDataFill(u32 value, void * dst, int size);
void ApplyDataMoves(void);

#define RegisterVramMove(src, offset, size) \
    RegisterDataMove( \
        (src), \
        (void *) VRAM + (VRAM_OFFSET_MASK & (offset)), \
        (size))

#define RegisterVramFill(value, offset, size) \
    RegisterDataFill( \
        (value), \
        (void *) VRAM + (VRAM_OFFSET_MASK & (offset)), \
        (size))
