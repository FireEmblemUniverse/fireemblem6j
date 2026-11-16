#pragma once

#include "types.h"

// Type decls for types that don't have a home yet :/
// TODO: move

enum
{
    FACING_LEFT,
    FACING_RIGHT,
    FACING_DOWN,
    FACING_UP,
};

enum
{
    MOVE_CMD_END = -1, // end

    MOVE_CMD_MOVE_BASE,

    MOVE_CMD_MOVE_LEFT  = MOVE_CMD_MOVE_BASE + FACING_LEFT,
    MOVE_CMD_MOVE_RIGHT = MOVE_CMD_MOVE_BASE + FACING_RIGHT,
    MOVE_CMD_MOVE_DOWN  = MOVE_CMD_MOVE_BASE + FACING_DOWN,
    MOVE_CMD_MOVE_UP    = MOVE_CMD_MOVE_BASE + FACING_UP,

    MOVE_CMD_HALT,

    MOVE_CMD_FACE_BASE,

    MOVE_CMD_FACE_LEFT  = MOVE_CMD_FACE_BASE + FACING_LEFT,
    MOVE_CMD_FACE_RIGHT = MOVE_CMD_FACE_BASE + FACING_RIGHT,
    MOVE_CMD_FACE_DOWN  = MOVE_CMD_FACE_BASE + FACING_DOWN,
    MOVE_CMD_FACE_UP    = MOVE_CMD_FACE_BASE + FACING_UP,

    MOVE_CMD_SLEEP,
    MOVE_CMD_BUMP,
    MOVE_CMD_UNK11,
    MOVE_CMD_SET_SPEED,

    MOVE_CMD_CAMERA_ON,
    MOVE_CMD_CAMERA_OFF,

    MOVE_SCRIPT_MAX_LENGTH = 0x40,
};

enum ChapterInfo_RefRanks
{
    REFRANK_A,
    REFRANK_B,
    REFRANK_C,
    REFRANK_D,

    REFRANK_MAX
};

struct ChapterInfo
{
    /* 00 */ char const * debug_name;

    /* 04 */ u8 asset_img_a;
    /* 05 */ u8 asset_img_b;
    /* 06 */ u8 asset_pal;
    /* 07 */ u8 asset_tileset;
    /* 08 */ u8 asset_map;
    /* 09 */ u8 asset_img_anims;
    /* 0A */ u8 asset_pal_anims;
    /* 0B */ u8 asset_map_changes;

    /* 0C */ u8 fog;
    /* 0D */ u8 has_prep;
    /* 0E */ u8 title_id;
    /* 0F */ u8 coord_x;
    /* 10 */ u8 coord_y;
    /* 11 */ u8 weather;
    /* 12 */ u8 banim_terrain_id;
    /* 13 */ u8 hard_bonus_levels;

    /* 14 */ u8 song_blue_bgm;
    /* 15 */ u8 song_red_bgm;
    /* 16 */ u8 song_green_bgm;
    /* 17 */ u8 song_intro_bgm;
    /* 18 */ u8 song_opening_bgm;

    /* 19 */ u8 wall_hp;
    /* 1A */ u8 class_roll_set;

    // ranks
    /* 1B */ u8 tactics_ranks[REFRANK_MAX];
    /* 20 */ u16 exp_ranks[REFRANK_MAX];
    /* 28 */ u16 combat_ranks[REFRANK_MAX];

    /* 30 */ u16 msg_clear_condition;
    /* 32 */ u16 msg_upper_army;
    /* 34 */ u16 msg_lower_army;
    /* 36 */ u16 enemy_flag_chibi;
    /* 38 */ u16 msg_chapter_title;
    /* 3A */ u8 asset_event_info;
    /* 3B */ u8 asset_event_info_wm;

    /* 3C */ u16 msg_wm_location;
    /* 3E */ u8 index_gaiden; /* bit0: gaiden, bit[7:1]: chapter index */
    /* 3F */ u8 gmap_dispx;
    /* 40 */ u8 gmap_dispy;
    /* 41 */ u8 gmap_cursorx;
    /* 42 */ u8 gmap_cursory;
    /* 43 */ i8 victory_bgm_enemy_threshold;
};

struct MapChangeInfo
{
    /* 00 */ i8 id;
    /* 01 */ u8 x, y, width, height;
    /* 05 */ // pad
    /* 08 */ u16 const * metatiles;
};

struct BanimInfoEnt
{
    u16 wtype, index;
};

struct SioMessage
{
    /* 00 */ u8 kind;
    /* 01 */ u8 sender;
    /* 02 */ u16 param;
};
