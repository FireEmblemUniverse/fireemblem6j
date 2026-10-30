#ifndef UNITSPRITE_H
#define UNITSPRITE_H

#include "prelude.h"

// TODO: CHR_LINE and CHR_SIZE in appropriate headers
#include "constants/videoalloc.h"

#define UNITSPRITE_ID_BITS 7

// or that to any map sprite id to have it not animate
#define UNITSPRITE_NOTANIMATED (1 << UNITSPRITE_ID_BITS)

#define UNITSPRITE_MAX 0xD0
#define UNITSPRITE_SIMULATANEOUS_MAX 100

#define UNITSPRITE_SHEET_LINES 8
#define UNITSPRITE_SHEET_SIZE (UNITSPRITE_SHEET_LINES * CHR_LINE * CHR_SIZE)

enum
{
    UNITSPRITE_16x16,
    UNITSPRITE_16x32,
    UNITSPRITE_32x32,
};

struct UnitSprite
{
    /* 00 */ struct UnitSprite * next;
    /* 04 */ i16 x, y;
    /* 08 */ u16 oam2;
    /* 0A */ STRUCT_PAD(0x0A, 0x0B);
    /* 0B */ i8 config;
};

struct UnitSpriteInfo
{
    /* 00 */ u16 unk_00;
    /* 02 */ u16 size;
    /* 04 */ u8 const * img;
};

void func_fe6_08021B88(void);
void ApplyUnitSpritePalettes(void);
void ResetUnitSprites(void);
void ResetUnitSpritesB(void);
int UseUnitSprite(u32 id);
void SyncUnitSpriteSheet(void);
void ForceSyncUnitSpriteSheet(void);
int GetUnitDisplayedSpritePalette(struct Unit * unit);
int GetUnitSpritePalette(struct Unit * unit);
void RefreshUnitSprites(void);
void PutUnitSpritesOam(void);
void PutUnitSpriteIconsOam(void);
void func_fe6_08022618(void);
void ResetUnitSpritHover(void);
void UnitSpriteHoverUpdate(void);
bool IsUnitSpriteHoverEnabledAt(int x, int y);
void PutUnitSprite(int layer, int x, int y, struct Unit * unit);
void PutUnitSpriteExt(int layer, int x, int y, int oam2, struct Unit * unit);
void PutBlendWindowUnitSprite(int layer, int x, int y, int oam2, struct Unit * unit);
void func_fe6_08022A2C(void);
void HideUnitSprite(struct Unit * unit);
void ShowUnitSprite(struct Unit * unit);
u8 GetUnitSpriteHiddenFlag(struct Unit * unit);

struct UnitSprite * AddUnitSprite(int y);

extern struct UnitSpriteInfo CONST_DATA UnitSpriteTable[];

extern u8 EWRAM_DATA gUnitSpriteSlots[UNITSPRITE_MAX];

extern u8 EWRAM_DATA gUnitSpriteBuf[3][UNITSPRITE_SHEET_SIZE];

extern int EWRAM_DATA gUnitSpriteSmallAllocCount;
extern int EWRAM_DATA gUnitSpriteLargeAllocCount;

extern struct UnitSprite EWRAM_DATA gUnitSprites[UNITSPRITE_SIMULATANEOUS_MAX];
extern struct UnitSprite * EWRAM_DATA gNextFreeUnitSprite;

extern int EWRAM_DATA gUnitSpriteSyncRequest;

extern int EWRAM_DATA gUnitSpriteHoverClock;

extern u8 * CONST_DATA UnitSpriteUnpackBuf;

#define GetUnitSpriteInfo(id) (UnitSpriteTable[(id) & ((1 << UNITSPRITE_ID_BITS) - 1)])

extern const u8 Img_UnitSprite_Roylord[];
extern const u8 Img_UnitSprite_Mercenary[];
extern const u8 Img_UnitSprite_0825073C[];
extern const u8 Img_UnitSprite_082508CC[];
extern const u8 Img_UnitSprite_08250A2C[];
extern const u8 Img_UnitSprite_08250B68[];
extern const u8 Img_UnitSprite_08250C7C[];
extern const u8 Img_UnitSprite_08250D8C[];
extern const u8 Img_UnitSprite_08250E74[];
extern const u8 Img_UnitSprite_08250F50[];
extern const u8 Img_UnitSprite_0825107C[];
extern const u8 Img_UnitSprite_082511FC[];
extern const u8 Img_UnitSprite_08251308[];
extern const u8 Img_UnitSprite_082514A8[];
extern const u8 Img_UnitSprite_082515C0[];
extern const u8 Img_UnitSprite_082516D4[];
extern const u8 Img_UnitSprite_08251818[];
extern const u8 Img_UnitSprite_0825193C[];
extern const u8 Img_UnitSprite_08251A48[];
extern const u8 Img_UnitSprite_08251B6C[];
extern const u8 Img_UnitSprite_08251CC0[];
extern const u8 Img_UnitSprite_08251E18[];
extern const u8 Img_UnitSprite_08251F50[];
extern const u8 Img_UnitSprite_08252090[];
extern const u8 Img_UnitSprite_082521EC[];
extern const u8 Img_UnitSprite_0825234C[];
extern const u8 Img_UnitSprite_082524A4[];
extern const u8 Img_UnitSprite_082525E8[];
extern const u8 Img_UnitSprite_0825275C[];
extern const u8 Img_UnitSprite_082528A8[];
extern const u8 Img_UnitSprite_08252A64[];
extern const u8 Img_UnitSprite_08252B94[];
extern const u8 Img_UnitSprite_08252D64[];
extern const u8 Img_UnitSprite_08252E94[];
extern const u8 Img_UnitSprite_08253050[];
extern const u8 Img_UnitSprite_08253200[];
extern const u8 Img_UnitSprite_082533D0[];
extern const u8 Img_UnitSprite_082535AC[];
extern const u8 Img_UnitSprite_08253788[];
extern const u8 Img_UnitSprite_0825396C[];
extern const u8 Img_UnitSprite_08253B10[];
extern const u8 Img_UnitSprite_08253CBC[];
extern const u8 Img_UnitSprite_08253EB0[];
extern const u8 Img_UnitSprite_082540A4[];
extern const u8 Img_UnitSprite_082541F8[];
extern const u8 Img_UnitSprite_0825436C[];
extern const u8 Img_UnitSprite_082544E8[];
extern const u8 Img_UnitSprite_082546C8[];
extern const u8 Img_UnitSprite_08254804[];
extern const u8 Img_UnitSprite_08254944[];
extern const u8 Img_UnitSprite_08254A88[];
extern const u8 Img_UnitSprite_08254BC4[];
extern const u8 Img_UnitSprite_08254D14[];
extern const u8 Img_UnitSprite_08254E0C[];
extern const u8 Img_UnitSprite_08254EE0[];
extern const u8 Img_UnitSprite_08254F50[];
extern const u8 Img_UnitSprite_082552C0[];
extern const u8 Img_UnitSprite_082554A8[];
extern const u8 Img_UnitSprite_08255588[];
extern const u8 Img_UnitSprite_0825566C[];
extern const u8 Img_UnitSprite_0825573C[];
extern const u8 Img_UnitSprite_08255810[];
extern const u8 Img_UnitSprite_082559B8[];
extern const u8 Img_UnitSprite_08255B4C[];
extern const u8 Img_UnitSprite_08255CB0[];
extern const u8 Img_UnitSprite_08255E34[];
extern const u8 Img_UnitSprite_08255F98[];
extern const u8 Img_UnitSprite_082560DC[];
extern const u8 Img_UnitSprite_0825623C[];
extern const u8 Img_UnitSprite_08256384[];
extern const u8 Img_UnitSprite_082563BC[];

#endif // UNITSPRITE_H
