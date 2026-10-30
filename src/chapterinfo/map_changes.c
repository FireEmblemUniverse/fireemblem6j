#include "prelude.h"

static const u16 Tiles_MapChange_Ch0_0[] = {
	0x80,
};

const struct MapChangeInfo MapChange_Ch0[] = {
	{
		.id = 0,
		.x = 12,
		.y = 3,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch0_0,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch1_0[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch1_1[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24
};

static const u16 Tiles_MapChange_Ch1_2[] = {
	0x80,
};

static const u16 Tiles_MapChange_Ch1_3[] = {
	0x80,
};

const struct MapChangeInfo MapChange_Ch1[] = {
	{
		.id = 0,
		.x = 11,
		.y = 17,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch1_0,
	},
	{
		.id = 1,
		.x = 3,
		.y = 7,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch1_1,
	},
	{
		.id = 2,
		.x = 12,
		.y = 19,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch1_2,
	},
	{
		.id = 3,
		.x = 4,
		.y = 9,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch1_3,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch2_0[] = {
	0x00, 0x00, 0x00,
	0x00, 0x00, 0x00,
	0x00, 0x80, 0x00,
};

static const u16 Tiles_MapChange_Ch2_1[] = {
	0x80,
};

const struct MapChangeInfo MapChange_Ch2[] = {
	{
		.id = 0,
		.x = 2,
		.y = 2,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch2_0,
	},
	{
		.id = 1,
		.x = 3,
		.y = 4,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch2_1,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch3_0[] = {
	0x44, 0x48, 0x4C,
	0xC4, 0xC8, 0xCC,
};

static const u16 Tiles_MapChange_Ch3_1[] = {
	0x44, 0x48,
	0x4C, 0xC4,
	0xC8, 0xCC,
};

static const u16 Tiles_MapChange_Ch3_2[] = {
	0x80,
};

static const u16 Tiles_MapChange_Ch3_3[] = {
	0x80,
};

static const u16 Tiles_MapChange_Ch3_4[] = {
	4,
};

static const u16 Tiles_MapChange_Ch3_5[] = {
	4,
};

static const u16 Tiles_MapChange_Ch3_6[] = {
	0x734, 0x738, 0x6AC, 0x6A8, 0x6AC,
	0x6A8, 0x6AC, 0x6A8, 0x824, 0x7A8,
	0x564, 0x568, 0x550, 0x554, 0x558,
	0x564, 0x568, 0x72C, 0xCE0, 0x5E8,
	0x5E8, 0x5D0, 0x5D4, 0x5D8, 0x5E4,
	0x5E8, 0x7AC, 0x728, 0x5E4, 0x5E8,
	0x5E8, 0x568, 0x5E8, 0x5E8, 0x5E8,
	0x7AC, 0x000, 0x000, 0x000, 0x000,
	0x5E4, 0x5E8, 0x000, 0x000, 0x000,
};

const struct MapChangeInfo MapChange_Ch3[] = {
	{
		.id = 0,
		.x = 2,
		.y = 2,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch3_0,
	},
	{
		.id = 1,
		.x = 18,
		.y = 18,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch3_1,
	},
	{
		.id = 2,
		.x = 3,
		.y = 3,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch3_2,
	},
	{
		.id = 3,
		.x = 19,
		.y = 19,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch3_3,
	},
	{
		.id = 4,
		.x = 20,
		.y = 11,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch3_4,
	},
	{
		.id = 5,
		.x = 22,
		.y = 12,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch3_5,
	},
	{
		.id = 6,
		.x = 15,
		.y = 2,
		.width = 9,
		.height = 5,
		.metatiles = Tiles_MapChange_Ch3_6,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch4_0[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch4_1[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch4_2[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch4_3[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch4_4[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch4_5[] = {
	0x080,
};

const struct MapChangeInfo MapChange_Ch4[] = {
	{
		.id = 0,
		.x = 7,
		.y = 13,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch4_0,
	},
	{
		.id = 1,
		.x = 10,
		.y = 2,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch4_1,
	},
	{
		.id = 2,
		.x = 26,
		.y = 0,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch4_2,
	},
	{
		.id = 3,
		.x = 8,
		.y = 15,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch4_3,
	},
	{
		.id = 4,
		.x = 11,
		.y = 4,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch4_4,
	},
	{
		.id = 5,
		.x = 27,
		.y = 2,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch4_5,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch5_0[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch5_1[] = {
	0xE80,
	0xF00,
};

static const u16 Tiles_MapChange_Ch5_2[] = {
	0x080,
};

const struct MapChangeInfo MapChange_Ch5[] = {
	{
		.id = 0,
		.x = 9,
		.y = 0,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch5_0,
	},
	{
		.id = 1,
		.x = 6,
		.y = 16,
		.width = 1,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch5_1,
	},
	{
		.id = 2,
		.x = 10,
		.y = 2,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch5_2,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch6_0[] = {
	0x6BC, 0x6AC, 0x6AC, 0x6B4, 0xB40, 0x73C,
	0x72C, 0xB4C, 0xB48, 0xBC8, 0xB44, 0x72C,
	0x72C, 0xB40, 0xA40, 0xA44, 0xB44, 0x72C,
	0x72C, 0xB40, 0xAC0, 0xAC4, 0xBC4, 0x7AC,
	0x7AC, 0x68C, 0xBC4, 0xB44, 0xB44, 0x728,
};

static const u16 Tiles_MapChange_Ch6_1[] = {
	0x834, 0x738, 0x6A8, 0x6A8, 0x730, 0x7B4, 0x000,
	0x72C, 0xB4C, 0xB48, 0xBC8, 0xB48, 0x72C, 0x000,
	0x728, 0xB40, 0x184, 0xB40, 0xB44, 0x7A8, 0x000,
	0x72C, 0xBC0, 0xB48, 0xB44, 0xB44, 0xB48, 0x944,
	0x72C, 0xBC0, 0x184, 0xB40, 0xB44, 0x728, 0x000,
	0x7AC, 0xB40, 0xB48, 0xB44, 0xB44, 0x72C, 0x000,
};

static const u16 Tiles_MapChange_Ch6_2[] = {
	0x73C, 0x6A8, 0x6A8, 0x6A8, 0x6A8, 0x824,
	0x72C, 0xB4C, 0xBC8, 0xB48, 0xBC8, 0x72C,
	0x7AC, 0xB40, 0xA40, 0xA44, 0xB44, 0x7A8,
	0x72C, 0xBC0, 0xAC0, 0xAC4, 0xBC4, 0xB48,
	0x7AC, 0xB40, 0xB44, 0xB44, 0xB44, 0x728,
};

static const u16 Tiles_MapChange_Ch6_3[] = {
	0x73C, 0x6A8, 0x6A8, 0x6A8, 0x6A8, 0x730, 0x7B4, 0x000,
	0x72C, 0x184, 0xB4C, 0xB48, 0xBC8, 0xB48, 0x7A8, 0x000,
	0x7AC, 0xB4C, 0x944, 0x954, 0x948, 0xB44, 0xB48, 0xB44,
	0x728, 0xB40, 0xB44, 0xBC4, 0xB44, 0xB44, 0x728, 0x000,
};

static const u16 Tiles_MapChange_Ch6_4[] = {
	0xB40,
};

static const u16 Tiles_MapChange_Ch6_5[] = {
	0xB40,
};

static const u16 Tiles_MapChange_Ch6_6[] = {
	0x834, 0x738, 0x6A8, 0x6A8, 0x6A8, 0x6A8, 0x824,
	0x7A8, 0xB4C, 0xB48, 0xBC8, 0xB48, 0xB48, 0x72C,
	0xB48, 0xB44, 0x944, 0x954, 0x948, 0xB44, 0x72C,
	0x728, 0xB40, 0xB44, 0xBC4, 0xB44, 0xB44, 0x72C,
};

static const u16 Tiles_MapChange_Ch6_7[] = {
	0x73C, 0x6A8, 0x6A8, 0x6A8, 0x6A8, 0x824,
	0x72C, 0xCDC, 0xCE0, 0xCE0, 0xCE4, 0x72C,
	0x7A8, 0xCD0, 0x184, 0xCD0, 0xCD4, 0x72C,
	0xB48, 0xCD4, 0xCE0, 0x184, 0xCD0, 0x72C,
	0x728, 0xCD0, 0x184, 0xCDC, 0xCD4, 0x72C,
};

static const u16 Tiles_MapChange_Ch6_8[] = {
	0x834, 0x738, 0x6A8, 0x6A8, 0x730, 0x7B4,
	0x72C, 0xCDC, 0xCE0, 0xCE0, 0xCE4, 0x72C,
	0x7A8, 0xCD0, 0xCD4, 0x184, 0xCD0, 0x72C,
	0xB48, 0xCD4, 0xCD4, 0xCE0, 0xCD4, 0x72C,
	0x728, 0xCD0, 0x184, 0xCD0, 0xCD4, 0x72C,
	0x72C, 0xCD0, 0xCE0, 0xCD4, 0xCD4, 0x72C,
};

static const u16 Tiles_MapChange_Ch6_9[] = {
	0x6BC, 0x738, 0xB40, 0x6B0, 0x730, 0x6BC,
	0x72C, 0xB4C, 0xB44, 0xBC8, 0xB48, 0x72C,
	0x72C, 0xB40, 0xA40, 0xA44, 0xBC4, 0x72C,
	0x7AC, 0xBC0, 0xAC0, 0xAC4, 0xBC4, 0x72C,
	0x72C, 0xB40, 0xBC4, 0xB44, 0x68C, 0x72C,
};

static const u16 Tiles_MapChange_Ch6_10[] = {
	0x104,
};

static const u16 Tiles_MapChange_Ch6_11[] = {
	0x104,
};

static const u16 Tiles_MapChange_Ch6_12[] = {
	0x104,
};

static const u16 Tiles_MapChange_Ch6_13[] = {
	0x104,
};

static const u16 Tiles_MapChange_Ch6_14[] = {
	0x104,
};

static const u16 Tiles_MapChange_Ch6_15[] = {
	0x104,
};

static const u16 Tiles_MapChange_Ch6_16[] = {
	0x104,
};

static const u16 Tiles_MapChange_Ch6_17[] = {
	0x104,
};

static const u16 Tiles_MapChange_Ch6_18[] = {
	0x944,
};

const struct MapChangeInfo MapChange_Ch6[] = {
	{
		.id = 0,
		.x = 3,
		.y = 17,
		.width = 6,
		.height = 5,
		.metatiles = Tiles_MapChange_Ch6_0,
	},
	{
		.id = 1,
		.x = 0,
		.y = 11,
		.width = 7,
		.height = 6,
		.metatiles = Tiles_MapChange_Ch6_1,
	},
	{
		.id = 2,
		.x = 0,
		.y = 6,
		.width = 6,
		.height = 5,
		.metatiles = Tiles_MapChange_Ch6_2,
	},
	{
		.id = 3,
		.x = 2,
		.y = 2,
		.width = 8,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch6_3,
	},
	{
		.id = 4,
		.x = 6,
		.y = 6,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch6_4,
	},
	{
		.id = 5,
		.x = 19,
		.y = 6,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch6_5,
	},
	{
		.id = 6,
		.x = 16,
		.y = 2,
		.width = 7,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch6_6,
	},
	{
		.id = 7,
		.x = 20,
		.y = 6,
		.width = 6,
		.height = 5,
		.metatiles = Tiles_MapChange_Ch6_7,
	},
	{
		.id = 8,
		.x = 20,
		.y = 11,
		.width = 6,
		.height = 6,
		.metatiles = Tiles_MapChange_Ch6_8,
	},
	{
		.id = 9,
		.x = 17,
		.y = 17,
		.width = 6,
		.height = 5,
		.metatiles = Tiles_MapChange_Ch6_9,
	},
	{
		.id = 10,
		.x = 2,
		.y = 15,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch6_10,
	},
	{
		.id = 11,
		.x = 2,
		.y = 13,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch6_11,
	},
	{
		.id = 12,
		.x = 3,
		.y = 3,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch6_12,
	},
	{
		.id = 13,
		.x = 22,
		.y = 8,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch6_13,
	},
	{
		.id = 14,
		.x = 23,
		.y = 9,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch6_14,
	},
	{
		.id = 15,
		.x = 22,
		.y = 10,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch6_15,
	},
	{
		.id = 16,
		.x = 23,
		.y = 13,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch6_16,
	},
	{
		.id = 17,
		.x = 22,
		.y = 15,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch6_17,
	},
	{
		.id = 18,
		.x = 6,
		.y = 9,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch6_18,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch7_0[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch7_1[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch7_2[] = {
	0x034, 0x048, 0x04C,
	0x0B4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch7_3[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch7_4[] = {
	0x044, 0x048, 0x038,
	0x0C4, 0x0C8, 0x0B8,
};

static const u16 Tiles_MapChange_Ch7_5[] = {
	0x034, 0x048, 0x04C,
	0x0B4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch7_6[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch7_7[] = {
	0x044, 0x048, 0x038,
	0x0C4, 0x0C8, 0x0B8,
};

static const u16 Tiles_MapChange_Ch7_8[] = {
	0xB64, 0xB68,
};

static const u16 Tiles_MapChange_Ch7_9[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch7_10[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch7_11[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch7_12[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch7_13[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch7_14[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch7_15[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch7_16[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch7_17[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch7_18[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch7_19[] = {
	0xCD0,
};

const struct MapChangeInfo MapChange_Ch7[] = {
	{
		.id = 0,
		.x = 0,
		.y = 17,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch7_0,
	},
	{
		.id = 1,
		.x = 0,
		.y = 23,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch7_1,
	},
	{
		.id = 2,
		.x = 14,
		.y = 14,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch7_2,
	},
	{
		.id = 3,
		.x = 18,
		.y = 14,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch7_3,
	},
	{
		.id = 4,
		.x = 12,
		.y = 17,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch7_4,
	},
	{
		.id = 5,
		.x = 14,
		.y = 20,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch7_5,
	},
	{
		.id = 6,
		.x = 18,
		.y = 20,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch7_6,
	},
	{
		.id = 7,
		.x = 12,
		.y = 23,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch7_7,
	},
	{
		.id = 8,
		.x = 4,
		.y = 8,
		.width = 2,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch7_8,
	},
	{
		.id = 9,
		.x = 18,
		.y = 1,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch7_9,
	},
	{
		.id = 10,
		.x = 20,
		.y = 1,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch7_10,
	},
	{
		.id = 11,
		.x = 1,
		.y = 18,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch7_11,
	},
	{
		.id = 12,
		.x = 1,
		.y = 24,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch7_12,
	},
	{
		.id = 13,
		.x = 15,
		.y = 15,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch7_13,
	},
	{
		.id = 14,
		.x = 19,
		.y = 15,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch7_14,
	},
	{
		.id = 15,
		.x = 13,
		.y = 18,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch7_15,
	},
	{
		.id = 16,
		.x = 15,
		.y = 21,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch7_16,
	},
	{
		.id = 17,
		.x = 19,
		.y = 21,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch7_17,
	},
	{
		.id = 18,
		.x = 13,
		.y = 24,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch7_18,
	},
	{
		.id = 19,
		.x = 17,
		.y = 3,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch7_19,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch8_0[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch8_1[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch8_2[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch8_3[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch8_4[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch8_5[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch8_6[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch8_7[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch8_8[] = {
	0x8A4, 0xB40, 0x8A0,
	0x000, 0xB44, 0x000,
};

static const u16 Tiles_MapChange_Ch8_9[] = {
	0x7A8, 0x000,
	0xB48, 0xB44,
};

static const u16 Tiles_MapChange_Ch8_10[] = {
	0x748, 0x000,
	0x7C8, 0x000,
	0xCE0, 0xCD8,
	0x728, 0x000,
};

static const u16 Tiles_MapChange_Ch8_11[] = {
	0x748, 0x000,
	0x7C8, 0x000,
	0xCE0, 0xCD4,
	0x7AC, 0x000,
};

static const u16 Tiles_MapChange_Ch8_12[] = {
	0xCD0,
};

static const u16 Tiles_MapChange_Ch8_13[] = {
	0x7A8, 0x000,
	0xCE4, 0xCD8,
};

const struct MapChangeInfo MapChange_Ch8[] = {
	{
		.id = 0,
		.x = 0,
		.y = 9,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch8_0,
	},
	{
		.id = 1,
		.x = 1,
		.y = 10,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch8_1,
	},
	{
		.id = 2,
		.x = 0,
		.y = 11,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch8_2,
	},
	{
		.id = 3,
		.x = 1,
		.y = 12,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch8_3,
	},
	{
		.id = 4,
		.x = 8,
		.y = 9,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch8_4,
	},
	{
		.id = 5,
		.x = 9,
		.y = 10,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch8_5,
	},
	{
		.id = 6,
		.x = 10,
		.y = 9,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch8_6,
	},
	{
		.id = 7,
		.x = 11,
		.y = 10,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch8_7,
	},
	{
		.id = 8,
		.x = 0,
		.y = 15,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch8_8,
	},
	{
		.id = 9,
		.x = 6,
		.y = 0,
		.width = 2,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch8_9,
	},
	{
		.id = 10,
		.x = 6,
		.y = 7,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch8_10,
	},
	{
		.id = 11,
		.x = 13,
		.y = 8,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch8_11,
	},
	{
		.id = 12,
		.x = 18,
		.y = 12,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch8_12,
	},
	{
		.id = 13,
		.x = 19,
		.y = 10,
		.width = 2,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch8_13,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch9_0[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch9_1[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch9_2[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch9_3[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch9_4[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch9_5[] = {
	0x080,
};

const struct MapChangeInfo MapChange_Ch9[] = {
	{
		.id = 0,
		.x = 1,
		.y = 22,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch9_0,
	},
	{
		.id = 1,
		.x = 17,
		.y = 0,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch9_1,
	},
	{
		.id = 2,
		.x = 20,
		.y = 0,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch9_2,
	},
	{
		.id = 3,
		.x = 2,
		.y = 24,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch9_3,
	},
	{
		.id = 4,
		.x = 18,
		.y = 2,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch9_4,
	},
	{
		.id = 5,
		.x = 21,
		.y = 2,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch9_5,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch10a_0[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch10a_1[] = {
	0x080,
};

const struct MapChangeInfo MapChange_Ch10a[] = {
	{
		.id = 0,
		.x = 17,
		.y = 15,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch10a_0,
	},
	{
		.id = 1,
		.x = 18,
		.y = 17,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch10a_1,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch11a_0[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch11a_1[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch11a_2[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch11a_3[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch11a_4[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch11a_5[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch11a_6[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch11a_7[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch11a_8[] = {
	0x7DC, 0x284, 0x7D8,
};

static const u16 Tiles_MapChange_Ch11a_9[] = {
	0x7DC, 0x284, 0x7D8,
};

static const u16 Tiles_MapChange_Ch11a_10[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch11a_11[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch11a_12[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch11a_13[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch11a_14[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch11a_15[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch11a_16[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch11a_17[] = {
	0x080,
};

const struct MapChangeInfo MapChange_Ch11a[] = {
	{
		.id = 0,
		.x = 4,
		.y = 17,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch11a_0,
	},
	{
		.id = 1,
		.x = 4,
		.y = 23,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch11a_1,
	},
	{
		.id = 2,
		.x = 10,
		.y = 23,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch11a_2,
	},
	{
		.id = 3,
		.x = 10,
		.y = 17,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch11a_3,
	},
	{
		.id = 4,
		.x = 23,
		.y = 17,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch11a_4,
	},
	{
		.id = 5,
		.x = 17,
		.y = 13,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch11a_5,
	},
	{
		.id = 6,
		.x = 17,
		.y = 5,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch11a_6,
	},
	{
		.id = 7,
		.x = 23,
		.y = 5,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch11a_7,
	},
	{
		.id = 8,
		.x = 18,
		.y = 2,
		.width = 3,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch11a_8,
	},
	{
		.id = 9,
		.x = 13,
		.y = 21,
		.width = 3,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch11a_9,
	},
	{
		.id = 10,
		.x = 5,
		.y = 24,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch11a_10,
	},
	{
		.id = 11,
		.x = 11,
		.y = 24,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch11a_11,
	},
	{
		.id = 12,
		.x = 5,
		.y = 18,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch11a_12,
	},
	{
		.id = 13,
		.x = 11,
		.y = 18,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch11a_13,
	},
	{
		.id = 14,
		.x = 24,
		.y = 18,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch11a_14,
	},
	{
		.id = 15,
		.x = 18,
		.y = 14,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch11a_15,
	},
	{
		.id = 16,
		.x = 18,
		.y = 6,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch11a_16,
	},
	{
		.id = 17,
		.x = 24,
		.y = 6,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch11a_17,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch10b_0[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch10b_1[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch10b_2[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch10b_3[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch10b_4[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch10b_5[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch10b_6[] = {
	0x044, 0x048, 0x04C,
	0x0C4, 0x0C8, 0x0CC,
};

static const u16 Tiles_MapChange_Ch10b_7[] = {
	0x7DC, 0x284,
};

static const u16 Tiles_MapChange_Ch10b_8[] = {
	0x7DC, 0x284,
};

static const u16 Tiles_MapChange_Ch10b_9[] = {
	0x7DC, 0x284,
};

static const u16 Tiles_MapChange_Ch10b_10[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch10b_11[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch10b_12[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch10b_13[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch10b_14[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch10b_15[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch10b_16[] = {
	0x080,
};

const struct MapChangeInfo MapChange_Ch10b[] = {
	{
		.id = 0,
		.x = 3,
		.y = 7,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch10b_0,
	},
	{
		.id = 1,
		.x = 7,
		.y = 7,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch10b_1,
	},
	{
		.id = 2,
		.x = 4,
		.y = 12,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch10b_2,
	},
	{
		.id = 3,
		.x = 7,
		.y = 19,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch10b_3,
	},
	{
		.id = 4,
		.x = 17,
		.y = 10,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch10b_4,
	},
	{
		.id = 5,
		.x = 17,
		.y = 15,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch10b_5,
	},
	{
		.id = 6,
		.x = 16,
		.y = 22,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch10b_6,
	},
	{
		.id = 7,
		.x = 12,
		.y = 10,
		.width = 2,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch10b_7,
	},
	{
		.id = 8,
		.x = 18,
		.y = 18,
		.width = 2,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch10b_8,
	},
	{
		.id = 9,
		.x = 8,
		.y = 24,
		.width = 2,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch10b_9,
	},
	{
		.id = 10,
		.x = 4,
		.y = 8,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch10b_10,
	},
	{
		.id = 11,
		.x = 8,
		.y = 8,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch10b_11,
	},
	{
		.id = 12,
		.x = 5,
		.y = 13,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch10b_12,
	},
	{
		.id = 13,
		.x = 8,
		.y = 20,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch10b_13,
	},
	{
		.id = 14,
		.x = 18,
		.y = 11,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch10b_14,
	},
	{
		.id = 15,
		.x = 18,
		.y = 16,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch10b_15,
	},
	{
		.id = 16,
		.x = 17,
		.y = 23,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch10b_16,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch11b_0[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch11b_1[] = {
	0x080,
};

const struct MapChangeInfo MapChange_Ch11b[] = {
	{
		.id = 0,
		.x = 17,
		.y = 19,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch11b_0,
	},
	{
		.id = 1,
		.x = 18,
		.y = 21,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch11b_1,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch12_0[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12_1[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12_2[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12_3[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12_4[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12_5[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12_6[] = {
	0x828, 0x184,
	0xAE0, 0xB50,
	0x7A8, 0xB7C,
};

static const u16 Tiles_MapChange_Ch12_7[] = {
	0x734, 0xAD0, 0xAD4, 0x730,
};

static const u16 Tiles_MapChange_Ch12_8[] = {
	0x9B8, 0xAD0, 0x930,
};

static const u16 Tiles_MapChange_Ch12_9[] = {
	0x734, 0xAD0, 0x730,
	0x000, 0xAD8, 0x000,
};

static const u16 Tiles_MapChange_Ch12_10[] = {
	0x828, 0x000,
	0xAE0, 0xAD4,
	0x7A8, 0x000,
};

static const u16 Tiles_MapChange_Ch12_11[] = {
	0x828, 0x480,
	0xAE0, 0x224,
};

static const u16 Tiles_MapChange_Ch12_12[] = {
	0x828, 0xBFC,
	0xAE4, 0xB50,
	0x000, 0xB7C,
};

const struct MapChangeInfo MapChange_Ch12[] = {
	{
		.id = 0,
		.x = 5,
		.y = 20,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12_0,
	},
	{
		.id = 1,
		.x = 5,
		.y = 23,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12_1,
	},
	{
		.id = 2,
		.x = 26,
		.y = 12,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12_2,
	},
	{
		.id = 3,
		.x = 27,
		.y = 8,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12_3,
	},
	{
		.id = 4,
		.x = 26,
		.y = 6,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12_4,
	},
	{
		.id = 5,
		.x = 27,
		.y = 4,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12_5,
	},
	{
		.id = 6,
		.x = 7,
		.y = 19,
		.width = 2,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch12_6,
	},
	{
		.id = 7,
		.x = 7,
		.y = 7,
		.width = 4,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12_7,
	},
	{
		.id = 8,
		.x = 26,
		.y = 14,
		.width = 3,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12_8,
	},
	{
		.id = 9,
		.x = 25,
		.y = 10,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch12_9,
	},
	{
		.id = 10,
		.x = 24,
		.y = 4,
		.width = 2,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch12_10,
	},
	{
		.id = 11,
		.x = 22,
		.y = 17,
		.width = 2,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch12_11,
	},
	{
		.id = 12,
		.x = 14,
		.y = 4,
		.width = 2,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch12_12,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch13_0[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch13_1[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch13_2[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch13_3[] = {
	0x080,
};

const struct MapChangeInfo MapChange_Ch13[] = {
	{
		.id = 0,
		.x = 6,
		.y = 4,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch13_0,
	},
	{
		.id = 1,
		.x = 37,
		.y = 16,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch13_1,
	},
	{
		.id = 2,
		.x = 7,
		.y = 6,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch13_2,
	},
	{
		.id = 3,
		.x = 38,
		.y = 18,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch13_3,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch15_0[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch15_1[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch15_2[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch15_3[] = {
	0x080,
};

const struct MapChangeInfo MapChange_Ch15[] = {
	{
		.id = 0,
		.x = 7,
		.y = 20,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch15_0,
	},
	{
		.id = 1,
		.x = 24,
		.y = 13,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch15_1,
	},
	{
		.id = 2,
		.x = 8,
		.y = 22,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch15_2,
	},
	{
		.id = 3,
		.x = 25,
		.y = 15,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch15_3,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch16_0[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch16_1[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch16_2[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch16_3[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch16_4[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch16_5[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch16_6[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch16_7[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch16_8[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch16_9[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch16_10[] = {
	0x7A8, 0x000,
	0xC48, 0xB44,
};

static const u16 Tiles_MapChange_Ch16_11[] = {
	0xCD8,
	0xCD0,
};

static const u16 Tiles_MapChange_Ch16_12[] = {
	0xD40, 0xD44,
};

static const u16 Tiles_MapChange_Ch16_13[] = {
	0xCD0,
};

const struct MapChangeInfo MapChange_Ch16[] = {
	{
		.id = 0,
		.x = 1,
		.y = 16,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch16_0,
	},
	{
		.id = 1,
		.x = 2,
		.y = 18,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch16_1,
	},
	{
		.id = 2,
		.x = 1,
		.y = 20,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch16_2,
	},
	{
		.id = 3,
		.x = 2,
		.y = 22,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch16_3,
	},
	{
		.id = 4,
		.x = 3,
		.y = 23,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch16_4,
	},
	{
		.id = 5,
		.x = 28,
		.y = 2,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch16_5,
	},
	{
		.id = 6,
		.x = 30,
		.y = 3,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch16_6,
	},
	{
		.id = 7,
		.x = 30,
		.y = 6,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch16_7,
	},
	{
		.id = 8,
		.x = 30,
		.y = 9,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch16_8,
	},
	{
		.id = 9,
		.x = 30,
		.y = 11,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch16_9,
	},
	{
		.id = 10,
		.x = 2,
		.y = 2,
		.width = 2,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch16_10,
	},
	{
		.id = 11,
		.x = 5,
		.y = 14,
		.width = 1,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch16_11,
	},
	{
		.id = 12,
		.x = 11,
		.y = 15,
		.width = 2,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch16_12,
	},
	{
		.id = 13,
		.x = 27,
		.y = 4,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch16_13,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch17c_0[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch17c_1[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch17c_2[] = {
	0x000, 0x000, 0x000, 0x4E0, 0x644, 0x000,
	0x000, 0x46C, 0x4EC, 0x358, 0x644, 0x644,
	0x4E0, 0x644, 0x644, 0x644, 0x644, 0x3DC,
	0x358, 0x644, 0x644, 0x3DC, 0x4E4, 0x000,
	0x644, 0x644, 0x644, 0x468, 0x000, 0x000,
	0x000, 0x644, 0x3DC, 0x000, 0x000, 0x000,
	0x000, 0x4E4, 0x000, 0x000, 0x000, 0x000,
};

const struct MapChangeInfo MapChange_Ch17c[] = {
	{
		.id = 0,
		.x = 1,
		.y = 10,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch17c_0,
	},
	{
		.id = 1,
		.x = 2,
		.y = 12,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch17c_1,
	},
	{
		.id = 2,
		.x = 9,
		.y = 6,
		.width = 6,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch17c_2,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch17d_0[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch17d_1[] = {
	0xE1C, 0xE20, 0xE24,
	0xE9C, 0xEA0, 0xEA4,
	0xF1C, 0xF20, 0xF24,
};

static const u16 Tiles_MapChange_Ch17d_2[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch17d_3[] = {
	0x080,
};

const struct MapChangeInfo MapChange_Ch17d[] = {
	{
		.id = 0,
		.x = 1,
		.y = 15,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch17d_0,
	},
	{
		.id = 1,
		.x = 29,
		.y = 0,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch17d_1,
	},
	{
		.id = 2,
		.x = 2,
		.y = 17,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch17d_2,
	},
	{
		.id = 3,
		.x = 30,
		.y = 2,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch17d_3,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch18c_0[] = {
	0xC1C, 0xC20, 0xC24,
	0xC9C, 0xCA0, 0xCA4,
	0xD1C, 0xD20, 0xD24,
};

static const u16 Tiles_MapChange_Ch18c_1[] = {
	0xC1C, 0xC20, 0xC24,
	0xC9C, 0xCA0, 0xCA4,
	0xD1C, 0xD20, 0xD24,
};

static const u16 Tiles_MapChange_Ch18c_2[] = {
	0xC1C, 0xC20, 0xC24,
	0xC9C, 0xCA0, 0xCA4,
	0xD1C, 0xD20, 0xD24,
};

static const u16 Tiles_MapChange_Ch18c_3[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch18c_4[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch18c_5[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch18c_6[] = {
	0x000, 0x000, 0x000, 0x5D0,
	0x000, 0x000, 0x65C, 0x5D8,
	0x000, 0x000, 0x650, 0x000,
	0x000, 0x000, 0x860, 0x000,
	0x000, 0x85C, 0x7D8, 0x000,
	0x85C, 0x7D8, 0x000, 0x000,
	0x7E0, 0x000, 0x000, 0x000,
	0x5E4, 0x000, 0x000, 0x000,
	0x5D4, 0x000, 0x000, 0x000,
};

static const u16 Tiles_MapChange_Ch18c_7[] = {
	0x85C,
	0x7E0,
	0x7E8,
	0x5E4,
	0x5D8,
};

static const u16 Tiles_MapChange_Ch18c_8[] = {
	0x000, 0x000, 0x000, 0x65C,
	0x000, 0x000, 0x85C, 0x5D4,
	0x85C, 0x7F0, 0x7D8, 0x000,
	0x7D8, 0x000, 0x000, 0x000,
};

static const u16 Tiles_MapChange_Ch18c_9[] = {
	0x858, 0x000, 0x000, 0x000,
	0x7DC, 0x5E0, 0x858, 0x000,
	0x000, 0x000, 0x7DC, 0x7F4,
};

static const u16 Tiles_MapChange_Ch18c_10[] = {
	0x858, 0x000, 0x000, 0x000,
	0x7DC, 0x5E0, 0x858, 0x000,
	0x000, 0x000, 0x5D0, 0x000,
	0x000, 0x000, 0x650, 0x000,
	0x000, 0x000, 0x7E8, 0x000,
	0x000, 0x000, 0x7DC, 0x858,
	0x000, 0x000, 0x000, 0x7E0,
};

static const u16 Tiles_MapChange_Ch18c_11[] = {
	0x6D4, 0x6FC, 0x6FC, 0x6E8, 0x55C, 0x6DC, 0x768, 0x76C, 0x760,
	0x000, 0x874, 0x6FC, 0x750, 0x000, 0x000, 0x6D4, 0x5F8, 0x558,
	0x000, 0x5D0, 0x6EC, 0x6FC, 0x750, 0x578, 0x668, 0x67C, 0x66C,
	0x85C, 0x5D4, 0x000, 0x7FC, 0x6EC, 0x6F0, 0x670, 0x66C, 0x000,
	0x7E0, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000,
};

static const u16 Tiles_MapChange_Ch18c_12[] = {
	0x000, 0x000, 0x7DC, 0x858, 0x578, 0x85C, 0x5D4,
	0x000, 0x000, 0x000, 0x7DC, 0x6FC, 0x7D8, 0xA80,
	0x000, 0x654, 0x558, 0x7D0, 0x7D8, 0x000, 0x000,
	0x568, 0x67C, 0x678, 0x6FC, 0x7D4, 0x568, 0x558,
	0x5E8, 0x678, 0x6FC, 0x6FC, 0x5F8, 0x67C, 0x66C,
};

static const u16 Tiles_MapChange_Ch18c_13[] = {
	0x000, 0x85C, 0x7D8,
	0x000, 0x5D0, 0x000,
	0x000, 0x664, 0x000,
	0x000, 0x000, 0x000,
	0x000, 0x860, 0x000,
	0x85C, 0x7D8, 0x000,
	0x860, 0x000, 0x000,
	0x7DC, 0x858, 0x000,
	0x000, 0x860, 0x000,
	0x000, 0x7DC, 0x858,
};

static const u16 Tiles_MapChange_Ch18c_14[] = {
	0x7DC, 0x858,
	0x000, 0x7E0,
	0x000, 0x5D0,
	0x65C, 0x5D8,
	0x650, 0x000,
	0x5D0, 0x000,
	0x650, 0x000,
};

static const u16 Tiles_MapChange_Ch18c_15[] = {
	0x000, 0x85C,
	0x7D0, 0x7D8,
	0x5D0, 0x000,
};

static const u16 Tiles_MapChange_Ch18c_16[] = {
	0x000, 0x85C, 0x7F0, 0x7F4,
	0x65C, 0x7D8, 0x000, 0x000,
	0x5D8, 0x000, 0x000, 0x000,
};

static const u16 Tiles_MapChange_Ch18c_17[] = {
	0x858,
	0x7DC,
};

static const u16 Tiles_MapChange_Ch18c_18[] = {
	0x7DC,
};

static const u16 Tiles_MapChange_Ch18c_19[] = {
	0x000, 0x000, 0x7E0, 0x000, 0x664, 0x000, 0x000, 0x000, 0x000, 0x7E0, 0x000,
	0x000, 0x85C, 0x7D8, 0x000, 0x650, 0x000, 0x000, 0x000, 0x000, 0x7DC, 0x858,
	0x000, 0x7E0, 0x000, 0x85C, 0x7D8, 0x000, 0x000, 0x000, 0x000, 0x000, 0x5D0,
	0x85C, 0x7D8, 0x000, 0x7DC, 0x858, 0x000, 0x000, 0x000, 0x000, 0x000, 0x650,
	0x860, 0x000, 0x000, 0x000, 0x7DC, 0x858, 0x85C, 0x000, 0x858, 0x85C, 0x7D8,
	0x7D8, 0x000, 0x000, 0x000, 0x000, 0x7DC, 0x7D8, 0x000, 0x7DC, 0x87C, 0x000,
};

const struct MapChangeInfo MapChange_Ch18c[] = {
	{
		.id = 0,
		.x = 1,
		.y = 2,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch18c_0,
	},
	{
		.id = 1,
		.x = 17,
		.y = 22,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch18c_1,
	},
	{
		.id = 2,
		.x = 19,
		.y = 7,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch18c_2,
	},
	{
		.id = 3,
		.x = 2,
		.y = 4,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch18c_3,
	},
	{
		.id = 4,
		.x = 18,
		.y = 24,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch18c_4,
	},
	{
		.id = 5,
		.x = 20,
		.y = 9,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch18c_5,
	},
	{
		.id = 6,
		.x = 5,
		.y = 0,
		.width = 4,
		.height = 9,
		.metatiles = Tiles_MapChange_Ch18c_6,
	},
	{
		.id = 7,
		.x = 4,
		.y = 8,
		.width = 1,
		.height = 5,
		.metatiles = Tiles_MapChange_Ch18c_7,
	},
	{
		.id = 8,
		.x = 0,
		.y = 12,
		.width = 4,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch18c_8,
	},
	{
		.id = 9,
		.x = 0,
		.y = 23,
		.width = 4,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch18c_9,
	},
	{
		.id = 10,
		.x = 5,
		.y = 25,
		.width = 4,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch18c_10,
	},
	{
		.id = 11,
		.x = 10,
		.y = 27,
		.width = 9,
		.height = 5,
		.metatiles = Tiles_MapChange_Ch18c_11,
	},
	{
		.id = 12,
		.x = 10,
		.y = 22,
		.width = 7,
		.height = 5,
		.metatiles = Tiles_MapChange_Ch18c_12,
	},
	{
		.id = 13,
		.x = 10,
		.y = 5,
		.width = 3,
		.height = 10,
		.metatiles = Tiles_MapChange_Ch18c_13,
	},
	{
		.id = 14,
		.x = 12,
		.y = 15,
		.width = 2,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch18c_14,
	},
	{
		.id = 15,
		.x = 16,
		.y = 19,
		.width = 2,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch18c_15,
	},
	{
		.id = 16,
		.x = 19,
		.y = 17,
		.width = 4,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch18c_16,
	},
	{
		.id = 17,
		.x = 22,
		.y = 6,
		.width = 1,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch18c_17,
	},
	{
		.id = 18,
		.x = 21,
		.y = 6,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch18c_18,
	},
	{
		.id = 19,
		.x = 12,
		.y = 0,
		.width = 11,
		.height = 6,
		.metatiles = Tiles_MapChange_Ch18c_19,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch19c_0[] = {
	0xC1C, 0xC20, 0xC24,
	0xC9C, 0xCA0, 0xCA4,
	0xD1C, 0xD20, 0xD24,
};

static const u16 Tiles_MapChange_Ch19c_1[] = {
	0xC1C, 0xC20, 0xC24,
	0xC9C, 0xCA0, 0xCA4,
	0xD1C, 0xD20, 0xD24,
};

static const u16 Tiles_MapChange_Ch19c_2[] = {
	0x080,
};

static const u16 Tiles_MapChange_Ch19c_3[] = {
	0x080,
};

const struct MapChangeInfo MapChange_Ch19c[] = {
	{
		.id = 0,
		.x = 9,
		.y = 12,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch19c_0,
	},
	{
		.id = 1,
		.x = 28,
		.y = 12,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch19c_1,
	},
	{
		.id = 2,
		.x = 10,
		.y = 14,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch19c_2,
	},
	{
		.id = 3,
		.x = 29,
		.y = 14,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch19c_3,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch20c_0[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20c_1[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20c_2[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20c_3[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20c_4[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20c_5[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20c_6[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20c_7[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20c_8[] = {
	0x3E0,
};

static const u16 Tiles_MapChange_Ch20c_9[] = {
	0x9CC,
	0x2D4,
	0x9D0,
};

static const u16 Tiles_MapChange_Ch20c_10[] = {
	0x358,
};

static const u16 Tiles_MapChange_Ch20c_11[] = {
	0x8D8, 0x358, 0x8D4,
};

static const u16 Tiles_MapChange_Ch20c_12[] = {
	0x8D8, 0x460,
	0x000, 0x2D0,
};

static const u16 Tiles_MapChange_Ch20c_13[] = {
	0x848, 0x460, 0x8D4,
	0x000, 0x2D0, 0x000,
};

static const u16 Tiles_MapChange_Ch20c_14[] = {
	0xA60, 0x358,
};

const struct MapChangeInfo MapChange_Ch20c[] = {
	{
		.id = 0,
		.x = 2,
		.y = 10,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20c_0,
	},
	{
		.id = 1,
		.x = 3,
		.y = 11,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20c_1,
	},
	{
		.id = 2,
		.x = 4,
		.y = 11,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20c_2,
	},
	{
		.id = 3,
		.x = 5,
		.y = 10,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20c_3,
	},
	{
		.id = 4,
		.x = 12,
		.y = 16,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20c_4,
	},
	{
		.id = 5,
		.x = 15,
		.y = 16,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20c_5,
	},
	{
		.id = 6,
		.x = 17,
		.y = 16,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20c_6,
	},
	{
		.id = 7,
		.x = 16,
		.y = 18,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20c_7,
	},
	{
		.id = 8,
		.x = 9,
		.y = 8,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20c_8,
	},
	{
		.id = 9,
		.x = 7,
		.y = 10,
		.width = 1,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20c_9,
	},
	{
		.id = 10,
		.x = 7,
		.y = 17,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20c_10,
	},
	{
		.id = 11,
		.x = 12,
		.y = 15,
		.width = 3,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20c_11,
	},
	{
		.id = 12,
		.x = 15,
		.y = 20,
		.width = 2,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch20c_12,
	},
	{
		.id = 13,
		.x = 17,
		.y = 20,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch20c_13,
	},
	{
		.id = 14,
		.x = 21,
		.y = 18,
		.width = 2,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20c_14,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch21_0[] = {
	0xE84, 0xE88, 0xE8C,
	0xF04, 0xF08, 0xF0C,
	0xF84, 0xF88, 0xF8C,
};

static const u16 Tiles_MapChange_Ch21_1[] = {
	0x080,
};

const struct MapChangeInfo MapChange_Ch21[] = {
	{
		.id = 0,
		.x = 10,
		.y = 9,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch21_0,
	},
	{
		.id = 1,
		.x = 11,
		.y = 11,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch21_1,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch22_0[] = {
	0x480, 0x400, 0x400, 0x400, 0x400, 0x400, 0x400, 0x400, 0x400, 0x400, 0x400, 0x400, 0x484,
	0x580, 0x018, 0x250, 0x254, 0x018, 0x418, 0x408, 0x408, 0x018, 0x250, 0x254, 0x018, 0x584,
	0x48C, 0x09C, 0x2D0, 0x2D4, 0x09C, 0x018, 0x018, 0x018, 0x098, 0x2D0, 0x2D4, 0x098, 0x48C,
	0x48C, 0x118, 0x704, 0x030, 0x118, 0x09C, 0x008, 0x098, 0x118, 0x030, 0x680, 0x118, 0x48C,
	0x50C, 0x680, 0x218, 0x030, 0x12C, 0x118, 0x088, 0x118, 0x12C, 0x030, 0x218, 0x688, 0x50C,
	0x48C, 0x680, 0x684, 0x0B0, 0x12C, 0x12C, 0x12C, 0x12C, 0x12C, 0x0B0, 0x700, 0x684, 0x48C,
	0x48C, 0x680, 0x684, 0x684, 0x684, 0x12C, 0x12C, 0x12C, 0x684, 0x684, 0x700, 0x684, 0x48C,
	0x50C, 0x680, 0x684, 0x684, 0x304, 0x210, 0x210, 0x210, 0x308, 0x684, 0x684, 0x684, 0x50C,
	0x48C, 0x680, 0x684, 0x684, 0x214, 0x288, 0x05C, 0x288, 0x294, 0x684, 0x684, 0x684, 0x48C,
	0x48C, 0x680, 0x684, 0x030, 0x064, 0x0D8, 0x0DC, 0x0E0, 0x058, 0x030, 0x680, 0x684, 0x48C,
	0x48C, 0x680, 0x684, 0x0B0, 0x08C, 0x158, 0x15C, 0x160, 0x294, 0x0B0, 0x700, 0x684, 0x50C,
	0x48C, 0x680, 0x684, 0x684, 0x18C, 0x1D8, 0x1DC, 0x1E0, 0x294, 0x684, 0x684, 0x684, 0x48C,
	0x48C, 0x680, 0x684, 0x218, 0x214, 0x288, 0x060, 0x288, 0x294, 0x218, 0x684, 0x684, 0x50C,
	0x48C, 0x680, 0x684, 0x684, 0x384, 0x290, 0x290, 0x290, 0x388, 0x684, 0x684, 0x684, 0x48C,
	0x000, 0x000, 0x000, 0x000, 0x000, 0x684, 0x684, 0x684, 0x000, 0x000, 0x000, 0x000, 0x000,
	0x000, 0x000, 0x000, 0x000, 0x000, 0x680, 0x684, 0x684, 0x000, 0x000, 0x000, 0x000, 0x000,
};

static const u16 Tiles_MapChange_Ch22_1[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch22_2[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch22_3[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch22_4[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch22_5[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch22_6[] = {
	0x004,
};

const struct MapChangeInfo MapChange_Ch22[] = {
	{
		.id = 0,
		.x = 9,
		.y = 4,
		.width = 13,
		.height = 16,
		.metatiles = Tiles_MapChange_Ch22_0,
	},
	{
		.id = 1,
		.x = 1,
		.y = 8,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch22_1,
	},
	{
		.id = 2,
		.x = 1,
		.y = 10,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch22_2,
	},
	{
		.id = 3,
		.x = 1,
		.y = 12,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch22_3,
	},
	{
		.id = 4,
		.x = 29,
		.y = 8,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch22_4,
	},
	{
		.id = 5,
		.x = 29,
		.y = 11,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch22_5,
	},
	{
		.id = 6,
		.x = 29,
		.y = 14,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch22_6,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch23_0[] = {
	0xE84, 0xE88, 0xE8C,
	0xF04, 0xF08, 0xF0C,
	0xF84, 0xF88, 0xF8C,
};

static const u16 Tiles_MapChange_Ch23_1[] = {
	0x080,
};

const struct MapChangeInfo MapChange_Ch23[] = {
	{
		.id = 0,
		.x = 21,
		.y = 21,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch23_0,
	},
	{
		.id = 1,
		.x = 22,
		.y = 23,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch23_1,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch24_0[] = {
	0x000, 0x000, 0x188, 0x18C, 0x190, 0x000, 0x000,
	0x008, 0x01C, 0x208, 0x08C, 0x210, 0x214, 0x218,
	0x220, 0x01C, 0x118, 0x0AC, 0x098, 0x018, 0x224,
	0x2A0, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x2A4,
	0x320, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x324,
	0x3A0, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x3A4,
	0x420, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x424,
	0x280, 0x284, 0x288, 0x01C, 0x290, 0x294, 0x298,
	0x000, 0x000, 0x11C, 0x01C, 0x124, 0x000, 0x000,
};

static const u16 Tiles_MapChange_Ch24_1[] = {
	0x000, 0x000, 0x188, 0x18C, 0x190, 0x000, 0x000,
	0x200, 0x204, 0x208, 0x08C, 0x210, 0x214, 0x218,
	0x220, 0x020, 0x118, 0x0AC, 0x098, 0x018, 0x224,
	0x2A0, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x2A4,
	0x320, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x324,
	0x088, 0x024, 0x014, 0x014, 0x014, 0x014, 0x090,
	0x0A0, 0x014, 0x014, 0x014, 0x014, 0x014, 0x014,
	0x100, 0x284, 0x288, 0x01C, 0x290, 0x294, 0x104,
};

static const u16 Tiles_MapChange_Ch24_2[] = {
	0x000, 0x000, 0x188, 0x18C, 0x190, 0x000, 0x000,
	0x008, 0x020, 0x208, 0x08C, 0x210, 0x214, 0x218,
	0x220, 0x01C, 0x118, 0x0AC, 0x098, 0x018, 0x224,
	0x2A0, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x2A4,
	0x320, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x324,
	0x3A0, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x3A4,
	0x420, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x424,
	0x280, 0x284, 0x288, 0x01C, 0x290, 0x294, 0x298,
	0x000, 0x000, 0x11C, 0x01C, 0x124, 0x000, 0x000,
};

static const u16 Tiles_MapChange_Ch24_3[] = {
	0x000, 0x000, 0x188, 0x18C, 0x190, 0x000, 0x000,
	0x200, 0x204, 0x208, 0x08C, 0x210, 0x214, 0x218,
	0x220, 0x020, 0x118, 0x0AC, 0x098, 0x018, 0x224,
	0x2A0, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x2A4,
	0x320, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x324,
	0x088, 0x024, 0x014, 0x014, 0x014, 0x014, 0x090,
	0x0A0, 0x014, 0x014, 0x014, 0x014, 0x014, 0x014,
	0x100, 0x284, 0x288, 0x01C, 0x290, 0x294, 0x104,
};

static const u16 Tiles_MapChange_Ch24_4[] = {
	0x000, 0x000, 0x188, 0x18C, 0x190, 0x000, 0x000,
	0x200, 0x204, 0x208, 0x08C, 0x210, 0x214, 0x218,
	0x220, 0x020, 0x118, 0x0AC, 0x098, 0x018, 0x224,
	0x2A0, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x2A4,
	0x320, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x324,
	0x3A0, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x090,
	0x420, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x014,
	0x280, 0x284, 0x288, 0x01C, 0x290, 0x294, 0x104,
	0x000, 0x000, 0x11C, 0x01C, 0x124, 0x000, 0x000,
};

static const u16 Tiles_MapChange_Ch24_5[] = {
	0x000, 0x000, 0x188, 0x18C, 0x190, 0x000, 0x000,
	0x008, 0x020, 0x208, 0x08C, 0x210, 0x214, 0x218,
	0x220, 0x01C, 0x118, 0x0AC, 0x098, 0x018, 0x224,
	0x2A0, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x2A4,
	0x320, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x324,
	0x3A0, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x3A4,
	0x420, 0x01C, 0x014, 0x014, 0x014, 0x014, 0x424,
	0x280, 0x284, 0x288, 0x01C, 0x290, 0x294, 0x298,
	0x000, 0x000, 0x11C, 0x01C, 0x124, 0x000, 0x000,
};

const struct MapChangeInfo MapChange_Ch24[] = {
	{
		.id = 0,
		.x = 3,
		.y = 1,
		.width = 7,
		.height = 9,
		.metatiles = Tiles_MapChange_Ch24_0,
	},
	{
		.id = 1,
		.x = 15,
		.y = 4,
		.width = 7,
		.height = 8,
		.metatiles = Tiles_MapChange_Ch24_1,
	},
	{
		.id = 2,
		.x = 24,
		.y = 12,
		.width = 7,
		.height = 9,
		.metatiles = Tiles_MapChange_Ch24_2,
	},
	{
		.id = 3,
		.x = 13,
		.y = 19,
		.width = 7,
		.height = 8,
		.metatiles = Tiles_MapChange_Ch24_3,
	},
	{
		.id = 4,
		.x = 2,
		.y = 21,
		.width = 7,
		.height = 9,
		.metatiles = Tiles_MapChange_Ch24_4,
	},
	{
		.id = 5,
		.x = 4,
		.y = 33,
		.width = 7,
		.height = 9,
		.metatiles = Tiles_MapChange_Ch24_5,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch19d_0[] = {
	0x000,
	0xE18,
};

static const u16 Tiles_MapChange_Ch19d_1[] = {
	0x000,
	0xE18,
};

static const u16 Tiles_MapChange_Ch19d_2[] = {
	0x000,
	0xE18,
};

static const u16 Tiles_MapChange_Ch19d_3[] = {
	0x000,
	0xE18,
};

static const u16 Tiles_MapChange_Ch19d_4[] = {
	0x000,
	0xE18,
};

static const u16 Tiles_MapChange_Ch19d_5[] = {
	0xC0C, 0x58C, 0xC08,
	0xD0C, 0xCD4, 0xD08,
};

static const u16 Tiles_MapChange_Ch19d_6[] = {
	0xE1C,
	0x148,
};

static const u16 Tiles_MapChange_Ch19d_7[] = {
	0x238,
};

static const u16 Tiles_MapChange_Ch19d_8[] = {
	0x1C8, 0x000,
	0xF54, 0x1B8,
	0x60C, 0xDE4,
	0xCF8, 0x214,
};

static const u16 Tiles_MapChange_Ch19d_9[] = {
	0xE1C,
	0x19C,
};

static const u16 Tiles_MapChange_Ch19d_10[] = {
	0xC0C, 0xF54, 0xC08,
	0xD0C, 0x60C, 0xD08,
	0x000, 0xCF8, 0x000,
};

static const u16 Tiles_MapChange_Ch19d_11[] = {
	0xD90,
};

static const u16 Tiles_MapChange_Ch19d_12[] = {
	0xD90,
};

static const u16 Tiles_MapChange_Ch19d_13[] = {
	0xD90,
};

static const u16 Tiles_MapChange_Ch19d_14[] = {
	0xD90,
};

static const u16 Tiles_MapChange_Ch19d_15[] = {
	0xD90,
};

const struct MapChangeInfo MapChange_Ch19d[] = {
	{
		.id = 0,
		.x = 6,
		.y = 4,
		.width = 1,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch19d_0,
	},
	{
		.id = 1,
		.x = 10,
		.y = 9,
		.width = 1,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch19d_1,
	},
	{
		.id = 2,
		.x = 15,
		.y = 11,
		.width = 1,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch19d_2,
	},
	{
		.id = 3,
		.x = 17,
		.y = 9,
		.width = 1,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch19d_3,
	},
	{
		.id = 4,
		.x = 26,
		.y = 2,
		.width = 1,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch19d_4,
	},
	{
		.id = 5,
		.x = 3,
		.y = 7,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch19d_5,
	},
	{
		.id = 6,
		.x = 10,
		.y = 4,
		.width = 1,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch19d_6,
	},
	{
		.id = 7,
		.x = 14,
		.y = 8,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch19d_7,
	},
	{
		.id = 8,
		.x = 15,
		.y = 14,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch19d_8,
	},
	{
		.id = 9,
		.x = 22,
		.y = 4,
		.width = 1,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch19d_9,
	},
	{
		.id = 10,
		.x = 27,
		.y = 5,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch19d_10,
	},
	{
		.id = 11,
		.x = 6,
		.y = 5,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch19d_11,
	},
	{
		.id = 12,
		.x = 10,
		.y = 10,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch19d_12,
	},
	{
		.id = 13,
		.x = 15,
		.y = 12,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch19d_13,
	},
	{
		.id = 14,
		.x = 17,
		.y = 10,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch19d_14,
	},
	{
		.id = 15,
		.x = 26,
		.y = 3,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch19d_15,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch20d_0[] = {
	0xE28, 0xAF0,
	0xB68, 0xB64,
	0xDAC, 0xA70,
};

static const u16 Tiles_MapChange_Ch20d_1[] = {
	0xB68, 0xB68,
	0xDAC, 0xA70,
};

static const u16 Tiles_MapChange_Ch20d_2[] = {
	0xA6C,
	0xB64,
};

static const u16 Tiles_MapChange_Ch20d_3[] = {
	0xC24, 0xAF0,
	0xCA4, 0xB68,
	0xDAC, 0xA70,
};

static const u16 Tiles_MapChange_Ch20d_4[] = {
	0xC90, 0x000,
	0xB68, 0xB68,
	0xDAC, 0xA70,
};

static const u16 Tiles_MapChange_Ch20d_5[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20d_6[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20d_7[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20d_8[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20d_9[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20d_10[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch20d_11[] = {
	0xE28, 0xAF0,
	0xB68, 0xB64,
};

const struct MapChangeInfo MapChange_Ch20d[] = {
	{
		.id = 0,
		.x = 10,
		.y = 3,
		.width = 2,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20d_0,
	},
	{
		.id = 1,
		.x = 20,
		.y = 5,
		.width = 2,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch20d_1,
	},
	{
		.id = 2,
		.x = 25,
		.y = 11,
		.width = 1,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch20d_2,
	},
	{
		.id = 3,
		.x = 23,
		.y = 14,
		.width = 2,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20d_3,
	},
	{
		.id = 4,
		.x = 19,
		.y = 14,
		.width = 2,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20d_4,
	},
	{
		.id = 5,
		.x = 26,
		.y = 4,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20d_5,
	},
	{
		.id = 6,
		.x = 24,
		.y = 5,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20d_6,
	},
	{
		.id = 7,
		.x = 22,
		.y = 6,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20d_7,
	},
	{
		.id = 8,
		.x = 26,
		.y = 6,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20d_8,
	},
	{
		.id = 9,
		.x = 24,
		.y = 8,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20d_9,
	},
	{
		.id = 10,
		.x = 26,
		.y = 9,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch20d_10,
	},
	{
		.id = 11,
		.x = 10,
		.y = 6,
		.width = 2,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch20d_11,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch12x_0[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12x_1[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12x_2[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12x_3[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12x_4[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12x_5[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12x_6[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12x_7[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12x_8[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12x_9[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12x_10[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch12x_11[] = {
	0x004,
};

const struct MapChangeInfo MapChange_Ch12x[] = {
	{
		.id = 0,
		.x = 1,
		.y = 3,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12x_0,
	},
	{
		.id = 1,
		.x = 3,
		.y = 17,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12x_1,
	},
	{
		.id = 2,
		.x = 7,
		.y = 8,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12x_2,
	},
	{
		.id = 3,
		.x = 11,
		.y = 4,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12x_3,
	},
	{
		.id = 4,
		.x = 13,
		.y = 0,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12x_4,
	},
	{
		.id = 5,
		.x = 13,
		.y = 15,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12x_5,
	},
	{
		.id = 6,
		.x = 19,
		.y = 9,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12x_6,
	},
	{
		.id = 7,
		.x = 12,
		.y = 24,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12x_7,
	},
	{
		.id = 8,
		.x = 18,
		.y = 16,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12x_8,
	},
	{
		.id = 9,
		.x = 25,
		.y = 12,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12x_9,
	},
	{
		.id = 10,
		.x = 25,
		.y = 20,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12x_10,
	},
	{
		.id = 11,
		.x = 26,
		.y = 24,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch12x_11,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch14x_0[] = {
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
};

static const u16 Tiles_MapChange_Ch14x_1[] = {
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
};

static const u16 Tiles_MapChange_Ch14x_2[] = {
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
};

static const u16 Tiles_MapChange_Ch14x_3[] = {
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
};

static const u16 Tiles_MapChange_Ch14x_4[] = {
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
};

static const u16 Tiles_MapChange_Ch14x_5[] = {
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
};

static const u16 Tiles_MapChange_Ch14x_6[] = {
	0x354, 0x354, 0x354, 0x354,
	0x354, 0x354, 0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_7[] = {
	0x354, 0x354, 0x354,
	0x354, 0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_8[] = {
	0x354, 0x354, 0x354,
	0x354, 0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_9[] = {
	0x354, 0x354, 0x354, 0x354,
	0x354, 0x354, 0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_10[] = {
	0x354, 0x354, 0x354, 0x354, 0x354, 0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_11[] = {
	0x354,
	0x354,
	0x354,
	0x354,
};

static const u16 Tiles_MapChange_Ch14x_12[] = {
	0x354,
	0x354,
	0x354,
	0x354,
};

static const u16 Tiles_MapChange_Ch14x_13[] = {
	0x354,
	0x354,
	0x354,
	0x354,
};

static const u16 Tiles_MapChange_Ch14x_14[] = {
	0x354,
	0x354,
	0x354,
	0x354,
};

static const u16 Tiles_MapChange_Ch14x_15[] = {
	0x354,
	0x354,
	0x354,
	0x354,
};

static const u16 Tiles_MapChange_Ch14x_16[] = {
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_17[] = {
	0x354, 0x354, 0x354,
	0x354, 0x354, 0x354,
	0x354, 0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_18[] = {
	0x354, 0x354, 0x354,
	0x354, 0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_19[] = {
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_20[] = {
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_21[] = {
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_22[] = {
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_23[] = {
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_24[] = {
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
	0x354, 0x354,
};

static const u16 Tiles_MapChange_Ch14x_25[] = {
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
	0x354,
};

static const u16 Tiles_MapChange_Ch14x_26[] = {
	0x6CC,
	0x74C,
	0x6CC,
	0x6CC,
	0x74C,
	0x6CC,
	0x74C,
};

static const u16 Tiles_MapChange_Ch14x_27[] = {
	0x74C,
	0x74C,
	0x74C,
	0x750,
	0x750,
	0x74C,
	0x74C,
};

static const u16 Tiles_MapChange_Ch14x_28[] = {
	0x750,
	0x6CC,
	0x74C,
	0x750,
	0x6CC,
	0x750,
	0x6CC,
};

static const u16 Tiles_MapChange_Ch14x_29[] = {
	0x6CC,
	0x74C,
	0x6CC,
	0x74C,
	0x6CC,
	0x74C,
	0x6CC,
};

static const u16 Tiles_MapChange_Ch14x_30[] = {
	0x74C,
	0x750,
	0x750,
	0x750,
	0x74C,
	0x74C,
	0x74C,
};

static const u16 Tiles_MapChange_Ch14x_31[] = {
	0x74C,
	0x74C,
	0x750,
	0x6CC,
	0x750,
	0x6CC,
	0x74C,
};

static const u16 Tiles_MapChange_Ch14x_32[] = {
	0x74C, 0x750, 0x74C, 0x750,
	0x74C, 0x750, 0x6CC, 0x750,
};

static const u16 Tiles_MapChange_Ch14x_33[] = {
	0x74C, 0x750, 0x6CC,
	0x74C, 0x750, 0x74C,
};

static const u16 Tiles_MapChange_Ch14x_34[] = {
	0x74C, 0x74C, 0x6CC,
	0x6CC, 0x74C, 0x74C,
};

static const u16 Tiles_MapChange_Ch14x_35[] = {
	0x6CC, 0x74C, 0x74C, 0x6CC,
	0x74C, 0x750, 0x6CC, 0x6CC,
};

static const u16 Tiles_MapChange_Ch14x_36[] = {
	0x6CC, 0x74C, 0x750, 0x74C, 0x6CC, 0x74C, 0x750,
};

static const u16 Tiles_MapChange_Ch14x_37[] = {
	0x74C,
	0x6CC,
	0x750,
	0x74C,
};

static const u16 Tiles_MapChange_Ch14x_38[] = {
	0x750,
	0x74C,
	0x74C,
	0x6CC,
};

static const u16 Tiles_MapChange_Ch14x_39[] = {
	0x750,
	0x74C,
	0x6CC,
	0x6CC,
};

static const u16 Tiles_MapChange_Ch14x_40[] = {
	0x6CC,
	0x6CC,
	0x6CC,
	0x6CC,
};

static const u16 Tiles_MapChange_Ch14x_41[] = {
	0x6CC,
	0x6CC,
	0x750,
	0x74C,
};

static const u16 Tiles_MapChange_Ch14x_42[] = {
	0x74C, 0x750,
	0x74C, 0x750,
	0x6CC, 0x74C,
	0x74C, 0x750,
	0x6CC, 0x6CC,
};

static const u16 Tiles_MapChange_Ch14x_43[] = {
	0x6CC, 0x74C, 0x750,
	0x6CC, 0x750, 0x750,
	0x750, 0x6CC, 0x750,
};

static const u16 Tiles_MapChange_Ch14x_44[] = {
	0x6CC, 0x6CC, 0x74C,
	0x74C, 0x750, 0x6CC,
};

static const u16 Tiles_MapChange_Ch14x_45[] = {
	0x750, 0x6CC,
	0x6CC, 0x74C,
	0x74C, 0x6CC,
	0x74C, 0x750,
};

static const u16 Tiles_MapChange_Ch14x_46[] = {
	0x6CC, 0x6CC,
	0x750, 0x750,
	0x750, 0x750,
	0x6CC, 0x750,
};

static const u16 Tiles_MapChange_Ch14x_47[] = {
	0x74C, 0x750,
	0x6CC, 0x750,
	0x6CC, 0x750,
	0x6CC, 0x74C,
};

static const u16 Tiles_MapChange_Ch14x_48[] = {
	0x6CC, 0x750,
	0x74C, 0x750,
	0x6CC, 0x750,
	0x74C, 0x750,
	0x6CC, 0x750,
	0x6CC, 0x750,
};

static const u16 Tiles_MapChange_Ch14x_49[] = {
	0x6CC, 0x74C,
	0x74C, 0x6CC,
	0x6CC, 0x74C,
	0x74C, 0x6CC,
	0x6CC, 0x74C,
	0x74C, 0x6CC,
};

static const u16 Tiles_MapChange_Ch14x_50[] = {
	0x74C, 0x750,
	0x6CC, 0x750,
	0x6CC, 0x750,
	0x6CC, 0x74C,
	0x6CC, 0x6CC,
};

static const u16 Tiles_MapChange_Ch14x_51[] = {
	0x6CC,
	0x74C,
	0x6CC,
	0x74C,
	0x6D4,
	0x754,
	0x6D4,
	0x754,
	0x6D4,
};

const struct MapChangeInfo MapChange_Ch14x[] = {
	{
		.id = 0,
		.x = 2,
		.y = 8,
		.width = 1,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch14x_0,
	},
	{
		.id = 1,
		.x = 3,
		.y = 8,
		.width = 1,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch14x_1,
	},
	{
		.id = 2,
		.x = 4,
		.y = 8,
		.width = 1,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch14x_2,
	},
	{
		.id = 3,
		.x = 2,
		.y = 15,
		.width = 1,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch14x_3,
	},
	{
		.id = 4,
		.x = 3,
		.y = 15,
		.width = 1,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch14x_4,
	},
	{
		.id = 5,
		.x = 4,
		.y = 15,
		.width = 1,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch14x_5,
	},
	{
		.id = 6,
		.x = 5,
		.y = 22,
		.width = 4,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch14x_6,
	},
	{
		.id = 7,
		.x = 9,
		.y = 22,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch14x_7,
	},
	{
		.id = 8,
		.x = 5,
		.y = 25,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch14x_8,
	},
	{
		.id = 9,
		.x = 8,
		.y = 25,
		.width = 4,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch14x_9,
	},
	{
		.id = 10,
		.x = 5,
		.y = 24,
		.width = 7,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch14x_10,
	},
	{
		.id = 11,
		.x = 12,
		.y = 18,
		.width = 1,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_11,
	},
	{
		.id = 12,
		.x = 14,
		.y = 18,
		.width = 1,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_12,
	},
	{
		.id = 13,
		.x = 16,
		.y = 18,
		.width = 1,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_13,
	},
	{
		.id = 14,
		.x = 13,
		.y = 18,
		.width = 1,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_14,
	},
	{
		.id = 15,
		.x = 15,
		.y = 18,
		.width = 1,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_15,
	},
	{
		.id = 16,
		.x = 17,
		.y = 22,
		.width = 2,
		.height = 5,
		.metatiles = Tiles_MapChange_Ch14x_16,
	},
	{
		.id = 17,
		.x = 19,
		.y = 22,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch14x_17,
	},
	{
		.id = 18,
		.x = 19,
		.y = 25,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch14x_18,
	},
	{
		.id = 19,
		.x = 24,
		.y = 14,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_19,
	},
	{
		.id = 20,
		.x = 26,
		.y = 14,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_20,
	},
	{
		.id = 21,
		.x = 26,
		.y = 10,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_21,
	},
	{
		.id = 22,
		.x = 26,
		.y = 4,
		.width = 2,
		.height = 6,
		.metatiles = Tiles_MapChange_Ch14x_22,
	},
	{
		.id = 23,
		.x = 18,
		.y = 4,
		.width = 2,
		.height = 6,
		.metatiles = Tiles_MapChange_Ch14x_23,
	},
	{
		.id = 24,
		.x = 18,
		.y = 10,
		.width = 2,
		.height = 5,
		.metatiles = Tiles_MapChange_Ch14x_24,
	},
	{
		.id = 25,
		.x = 17,
		.y = 6,
		.width = 1,
		.height = 9,
		.metatiles = Tiles_MapChange_Ch14x_25,
	},
	{
		.id = 26,
		.x = 2,
		.y = 8,
		.width = 1,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch14x_26,
	},
	{
		.id = 27,
		.x = 3,
		.y = 8,
		.width = 1,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch14x_27,
	},
	{
		.id = 28,
		.x = 4,
		.y = 8,
		.width = 1,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch14x_28,
	},
	{
		.id = 29,
		.x = 2,
		.y = 15,
		.width = 1,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch14x_29,
	},
	{
		.id = 30,
		.x = 3,
		.y = 15,
		.width = 1,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch14x_30,
	},
	{
		.id = 31,
		.x = 4,
		.y = 15,
		.width = 1,
		.height = 7,
		.metatiles = Tiles_MapChange_Ch14x_31,
	},
	{
		.id = 32,
		.x = 5,
		.y = 22,
		.width = 4,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch14x_32,
	},
	{
		.id = 33,
		.x = 9,
		.y = 22,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch14x_33,
	},
	{
		.id = 34,
		.x = 5,
		.y = 25,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch14x_34,
	},
	{
		.id = 35,
		.x = 8,
		.y = 25,
		.width = 4,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch14x_35,
	},
	{
		.id = 36,
		.x = 5,
		.y = 24,
		.width = 7,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch14x_36,
	},
	{
		.id = 37,
		.x = 12,
		.y = 18,
		.width = 1,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_37,
	},
	{
		.id = 38,
		.x = 14,
		.y = 18,
		.width = 1,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_38,
	},
	{
		.id = 39,
		.x = 16,
		.y = 18,
		.width = 1,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_39,
	},
	{
		.id = 40,
		.x = 13,
		.y = 18,
		.width = 1,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_40,
	},
	{
		.id = 41,
		.x = 15,
		.y = 18,
		.width = 1,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_41,
	},
	{
		.id = 42,
		.x = 17,
		.y = 22,
		.width = 2,
		.height = 5,
		.metatiles = Tiles_MapChange_Ch14x_42,
	},
	{
		.id = 43,
		.x = 19,
		.y = 22,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch14x_43,
	},
	{
		.id = 44,
		.x = 19,
		.y = 25,
		.width = 3,
		.height = 2,
		.metatiles = Tiles_MapChange_Ch14x_44,
	},
	{
		.id = 45,
		.x = 24,
		.y = 14,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_45,
	},
	{
		.id = 46,
		.x = 26,
		.y = 14,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_46,
	},
	{
		.id = 47,
		.x = 26,
		.y = 10,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch14x_47,
	},
	{
		.id = 48,
		.x = 26,
		.y = 4,
		.width = 2,
		.height = 6,
		.metatiles = Tiles_MapChange_Ch14x_48,
	},
	{
		.id = 49,
		.x = 18,
		.y = 4,
		.width = 2,
		.height = 6,
		.metatiles = Tiles_MapChange_Ch14x_49,
	},
	{
		.id = 50,
		.x = 18,
		.y = 10,
		.width = 2,
		.height = 5,
		.metatiles = Tiles_MapChange_Ch14x_50,
	},
	{
		.id = 51,
		.x = 17,
		.y = 6,
		.width = 1,
		.height = 9,
		.metatiles = Tiles_MapChange_Ch14x_51,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch20cx_0[] = {
	0xEA8, 0xD90, 0xFAC,
	0xF28, 0xE9C, 0xF2C,
	0x000, 0xEA0, 0x000,
};

static const u16 Tiles_MapChange_Ch20cx_1[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xEA0, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_2[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xE20, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_3[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xE20, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_4[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xE20, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_5[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xEA0, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_6[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xE20, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_7[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xE20, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_8[] = {
	0xEA8, 0xD90, 0xEAC,
	0xFA8, 0xE98, 0xF2C,
	0x000, 0xEA0, 0x000,
};

static const u16 Tiles_MapChange_Ch20cx_9[] = {
	0xD28, 0xD90, 0xEAC,
	0xFA8, 0xD98, 0xF2C,
	0x000, 0xEA0, 0x000,
};

static const u16 Tiles_MapChange_Ch20cx_10[] = {
	0xEA8, 0xD90, 0xEAC,
	0xF28, 0xD98, 0xF2C,
	0x000, 0xE1C, 0x000,
};

static const u16 Tiles_MapChange_Ch20cx_11[] = {
	0xE3C, 0x000,
	0xEBC, 0x374,
	0xEA0, 0x4F0,
};

static const u16 Tiles_MapChange_Ch20cx_12[] = {
	0xEA8, 0xD90, 0xEAC,
	0xFA8, 0xD98, 0xF2C,
	0x000, 0xEA0, 0x000,
};

static const u16 Tiles_MapChange_Ch20cx_13[] = {
	0xEA8, 0xD90, 0xEAC,
	0xFA8, 0xE98, 0xF2C,
	0x000, 0xE20, 0x000,
};

static const u16 Tiles_MapChange_Ch20cx_14[] = {
	0xEA8, 0xD90, 0xEAC,
	0xF28, 0xD98, 0xF2C,
	0x000, 0xEA0, 0x000,
};

static const u16 Tiles_MapChange_Ch20cx_15[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xE20, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_16[] = {
	0xEA8, 0xD90, 0xEAC,
	0xF28, 0xE98, 0xF2C,
	0x000, 0xE20, 0x000,
};

static const u16 Tiles_MapChange_Ch20cx_17[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xE1C, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_18[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xE1C, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_19[] = {
	0xEA8, 0xD90, 0xEAC,
	0xFA8, 0xD98, 0xF2C,
	0x000, 0xEA0, 0x000,
};

static const u16 Tiles_MapChange_Ch20cx_20[] = {
	0xEA8, 0xD90, 0xFAC,
	0xF28, 0xE98, 0xF2C,
	0x000, 0xE20, 0x000,
};

static const u16 Tiles_MapChange_Ch20cx_21[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xE20, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_22[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xE20, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_23[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xE20, 0xD9C,
};

static const u16 Tiles_MapChange_Ch20cx_24[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xE1C, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_25[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xEA0, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_26[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xEA0, 0xD9C,
	0x000, 0xDA0,
};

static const u16 Tiles_MapChange_Ch20cx_27[] = {
	0xE3C, 0x000,
	0xEBC, 0x000,
	0xE20, 0xD9C,
	0x000, 0xDA0,
};

const struct MapChangeInfo MapChange_Ch20cx[] = {
	{
		.id = 0,
		.x = 1,
		.y = 20,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20cx_0,
	},
	{
		.id = 1,
		.x = 4,
		.y = 7,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_1,
	},
	{
		.id = 2,
		.x = 4,
		.y = 13,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_2,
	},
	{
		.id = 3,
		.x = 4,
		.y = 23,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_3,
	},
	{
		.id = 4,
		.x = 7,
		.y = 0,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_4,
	},
	{
		.id = 5,
		.x = 7,
		.y = 17,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_5,
	},
	{
		.id = 6,
		.x = 10,
		.y = 4,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_6,
	},
	{
		.id = 7,
		.x = 10,
		.y = 15,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_7,
	},
	{
		.id = 8,
		.x = 8,
		.y = 23,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20cx_8,
	},
	{
		.id = 9,
		.x = 11,
		.y = 19,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20cx_9,
	},
	{
		.id = 10,
		.x = 11,
		.y = 27,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20cx_10,
	},
	{
		.id = 11,
		.x = 13,
		.y = 9,
		.width = 2,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20cx_11,
	},
	{
		.id = 12,
		.x = 16,
		.y = 15,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20cx_12,
	},
	{
		.id = 13,
		.x = 15,
		.y = 23,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20cx_13,
	},
	{
		.id = 14,
		.x = 18,
		.y = 27,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20cx_14,
	},
	{
		.id = 15,
		.x = 19,
		.y = 8,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_15,
	},
	{
		.id = 16,
		.x = 19,
		.y = 19,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20cx_16,
	},
	{
		.id = 17,
		.x = 22,
		.y = 2,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_17,
	},
	{
		.id = 18,
		.x = 22,
		.y = 13,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_18,
	},
	{
		.id = 19,
		.x = 22,
		.y = 23,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20cx_19,
	},
	{
		.id = 20,
		.x = 23,
		.y = 27,
		.width = 3,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20cx_20,
	},
	{
		.id = 21,
		.x = 25,
		.y = 0,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_21,
	},
	{
		.id = 22,
		.x = 25,
		.y = 9,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_22,
	},
	{
		.id = 23,
		.x = 25,
		.y = 18,
		.width = 2,
		.height = 3,
		.metatiles = Tiles_MapChange_Ch20cx_23,
	},
	{
		.id = 24,
		.x = 26,
		.y = 28,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_24,
	},
	{
		.id = 25,
		.x = 28,
		.y = 4,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_25,
	},
	{
		.id = 26,
		.x = 28,
		.y = 15,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_26,
	},
	{
		.id = 27,
		.x = 28,
		.y = 23,
		.width = 2,
		.height = 4,
		.metatiles = Tiles_MapChange_Ch20cx_27,
	},
	{ .id = -1 }
};

static const u16 Tiles_MapChange_Ch21x_0[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch21x_1[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch21x_2[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch21x_3[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch21x_4[] = {
	0x004,
};

static const u16 Tiles_MapChange_Ch21x_5[] = {
	0x004,
};

const struct MapChangeInfo MapChange_Ch21x[] = {
	{
		.id = 0,
		.x = 3,
		.y = 1,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch21x_0,
	},
	{
		.id = 1,
		.x = 6,
		.y = 1,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch21x_1,
	},
	{
		.id = 2,
		.x = 14,
		.y = 12,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch21x_2,
	},
	{
		.id = 3,
		.x = 16,
		.y = 12,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch21x_3,
	},
	{
		.id = 4,
		.x = 25,
		.y = 1,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch21x_4,
	},
	{
		.id = 5,
		.x = 29,
		.y = 1,
		.width = 1,
		.height = 1,
		.metatiles = Tiles_MapChange_Ch21x_5,
	},
	{ .id = -1 }
};
