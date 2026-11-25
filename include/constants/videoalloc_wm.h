#pragma once

#include "constants/videoalloc_global.h"

enum
{
    OBCHR_WM_FACE_A = 0x200,
    OBCHR_WM_FACE_B = 0x288,

    // nation highlights and map text share the face slots
    OBCHR_WM_NATION_A = OBCHR_WM_FACE_A,
    OBCHR_WM_NATION_B = OBCHR_WM_FACE_B,

    OBCHR_WM_SPRITES = 0x310,

    OBCHR_WM_TEXT = 0x340,
};

enum
{
    OBPAL_WM_SPRITES = 0, // .. 3
    OBPAL_WM_MAPTEXT = 4, // .. 5

    OBPAL_WM_TEXTBOX = 9,
    OBPAL_WM_HIGHLIGHT = 10,
    OBPAL_WM_SYSTEM_OBJECTS = 11, // .. 12
    OBPAL_WM_TEXT    = 13,

    OBPAL_WM_FACE_A = 14,
    OBPAL_WM_FACE_B = 15,
};
