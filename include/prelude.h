#pragma once

#define FE6 1
#define FE7J 0
#define FE7E 0
#define FE7U 0
#define FE8J 0
#define FE8U 0

#define FE7 (FE7J || FE7E || FE7U)
#define FE8 (FE8J || FE8U)

#if defined(MODERN) && MODERN
#  ifndef MODERN
#    define MODERN
#  endif
#  ifdef NONMATCHING
#    undef NONMATCHING
#  endif // NONMATCHING
#  ifdef BUGFIX
#    undef BUGFIX
#  endif // BUGFIX
#  define NONMATCHING 1
#  define BUGFIX 1
#endif // MODERN

#include <stdint.h>
#include <stddef.h>

#include "gba.h"

#include "attributes.h"
#include "types.h"

#include "unknown_types.h"
#include "unknown_funcs.h"
#include "unknown_objects.h"

// use to pad a struct that contains unused space
// TODO: use this everywere

#if !MODERN
#  define STRUCT_PAD(from, to) unsigned char _pad_ ## from[(to) - (from)]
#else
#  define STRUCT_PAD(from, to)
#endif

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

#define ABS(val) ((val) >= 0 ? (val) : -(val))

#define RECT_DISTANCE(xa, ya, xb, yb) (ABS((xa) - (xb)) + ABS((ya) - (yb)))

// For translate-able strings.
#define JTEXT(orig) (orig)
#define TEXT(orig, english) (orig)

#if defined(MODERN) && MODERN
#  define STATIC_ASSERT(expr) _Static_assert(expr)
#else
#  define STATIC_ASSERT(expr)
#endif

#define _UNUSED __attribute__((unused))

#define LIMIT_AREA(num, min, max)   \
    if (num > max)                  \
        num = max;                  \
    if (num < min)                  \
        num = min;

#define LIMIT_AREA2(num, min, max)  \
    if (num < min)                  \
        num = min;                  \
    else if (num > max)             \
        num = max;
