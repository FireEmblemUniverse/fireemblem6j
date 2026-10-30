#include "prelude.h"
#include "sio_core.h"
#include "oam.h"
#include "irq.h"
#include "oam.h"
#include "text.h"
#include "event.h"
#include "face.h"
#include "map.h"
#include "mapwork.h"
#include "ai_decide.h"
#include "manim.h"
#include "eventinfo.h"
#include "secretscreen.h"
#include "worldmap.h"
#include "m4a.h"

/**
 * hardware ?
 */
IWRAM_DATA u8 SoundMainRam[0x400] = {};
IWRAM_DATA u16 *gOamLoPutIt = NULL;
IWRAM_DATA int Pad_Common_030026A4[3] = {};
IWRAM_DATA struct DispIo gDispIo = {};

/**
 * IRQ
 */
IWRAM_DATA IrqFunc gIrqFuncs[INT_COUNT] = {};

/**
 * RAM func
 */
IWRAM_DATA void (* MapFloodCoreRamFunc)(void) = NULL;

/**
 * OAM
 */
IWRAM_DATA u16 gOamAffinePutId = 0;
IWRAM_DATA void (* PutOamHiRamFunc)(int x, int y, u16 const * oam_list, int oam2) = NULL;
IWRAM_DATA Func gOnHBlankA = NULL;
IWRAM_DATA int Pad_Common_03002768[2] = {};
IWRAM_DATA u16 gOam[0x200] = {};
IWRAM_DATA u8 Pad_Common_03002B70[0x200] = {};
IWRAM_DATA void (* DrawGlyphRamFunc)(u16 const * cvtLut, void * chr, u32 const * glyph, int offset) = NULL;
IWRAM_DATA u16 *gOamHiPutIt = NULL;
IWRAM_DATA Func gOnHBlankB = NULL;
IWRAM_DATA int Pad_Common_03002D7C = 0;

/**
 * Arm func
 */
IWRAM_DATA u8 RamFuncArea[0xA00] = {};
IWRAM_DATA void (* DecodeStringRamFunc)(char const * src, char * dst) = NULL;
IWRAM_DATA void (* PutOamLoRamFunc)(int x, int y, u16 const * oam_list, int oam2) = NULL;
IWRAM_DATA struct OamView *gOamAffinePutIt = NULL;
IWRAM_DATA int Pad_Common_0300378C = 0;
IWRAM_DATA u32 IntrMainRam[0x200] = {};
IWRAM_DATA void (* MapFloodCoreStepRamFunc)(void) = NULL;
IWRAM_DATA u8 Pad_Common_03003F94[12] = {};

/**
 * Event
 */
IWRAM_DATA u8 gEventScriptQueueIt = 0;
IWRAM_DATA u8 Pad_Common_03003FA1[0xF] = {};
IWRAM_DATA EventScr const *gEventScriptQueue[8] = {};
IWRAM_DATA struct SpriteEntry *gSpriteAllocIt = NULL;
IWRAM_DATA u8 Pad_Common_03003FD4[0x2C] = {};

/**
 * Face
 */
IWRAM_DATA struct FaceProc *gFaces[FACE_SLOT_COUNT] = {};

/**
 * Map
 */
IWRAM_DATA u8 **gWorkingMap = NULL;
IWRAM_DATA u8 Pad_Common_03004014[0xC] = {};
IWRAM_DATA struct MapFloodSquareEnt gMapFloodSquareBufB[0x80] = {};
IWRAM_DATA i8 gWorkingMovTable[0x40] = {};
IWRAM_DATA struct Unit gStatGainSimUnit = {};

// ALIGN(16)
IWRAM_DATA u8 Pad_Common_030042A8[0x8] = {};
IWRAM_DATA struct MapFloodSquareEnt gMapFloodSquareBufA[0x80] = {};

/**
 * Unit
 */
IWRAM_DATA struct Unit *gActiveUnit = NULL;

// ALIGN(16)
IWRAM_DATA u8 Pad_Common_030042B8[0xC] = {};

IWRAM_DATA struct MapFloodSt gMapFloodSt = {};

// ALIGN(16)
IWRAM_DATA u8 Pad_Common_030044CC[0x4] = {};

/**
 * SIO
 */
IWRAM_DATA int gUnk_Sio_030044D0 = 0;
IWRAM_DATA int gUnk_Sio_030044D4 = 0;
IWRAM_DATA u8 Pad_Common_030044D8[0x8] = {};
IWRAM_DATA struct SioData gSioBuf_030044E0 = {};
IWRAM_DATA u32 gSioStateId = 0;
IWRAM_DATA struct SioMessage gSioMsgBuf = {};

/**
 * AI
 */
IWRAM_DATA void (*AiDecideFunc)(void) = NULL;
// ALIGN(16)
IWRAM_DATA u8 Pad_Common_03004574[0xC] = {};

/**
 * Map anim
 */
IWRAM_DATA u8 gUnk_Sio_03004580[0x80] = {};
IWRAM_DATA struct ManimDebugSt gManimDebugStObj = {};
IWRAM_DATA struct ManimStarSt gManimStars[0x10] = {};
IWRAM_DATA u16 gManimPalBackup[10 * 0x10] = {};

/**
 * Event info
 */
IWRAM_DATA ALIGNED(4) u8 gPermanentFlagBits[(MAX_PERMANENT_FLAGS + CHAR_BIT - 1) / CHAR_BIT] = {};
IWRAM_DATA ALIGNED(4) u8 gChapterFlagBits[(MAX_CHAPTER_FLAGS + CHAR_BIT - 1) / CHAR_BIT] = {};
IWRAM_DATA u8 Pad_Common_0300489C[8] = {};
IWRAM_DATA ALIGNED(4) u8 gEndingMonologueState = 0;
IWRAM_DATA ALIGNED(4) u8 gUnk_030048A8 = 0;
// ALIGN 16
IWRAM_DATA u8 Pad_Common_030048A9[0xF] = {};

IWRAM_DATA u8 gEndingMonologueTextDone = 0;
IWRAM_DATA u8 Pad_Common_030048B9[7] = {};

/**
 * Secret screen
 */
IWRAM_DATA struct SecretScreenPlayRankStats gSecretScreenPlayRankStats = {};

/**
 * Play rank
 */
IWRAM_DATA ProcPtr gEndingFace1 = NULL;
IWRAM_DATA u8 Pad_Common_030048D8[8] = {};

/**
 * WM
 */
IWRAM_DATA struct WmArrowSt gWmArrowSt[3] = {};
IWRAM_DATA u8 Pad_Common_0300527C[4] = {};

/**
 * OP
 */
IWRAM_DATA u8 gOpAnimTextMask[4] = {};
IWRAM_DATA bool bool_opanim_03005284 = false;
IWRAM_DATA u8 Pad_Common_03005285[11] = {};
IWRAM_DATA int gOpAnimStep[8] = {};

/**
 * m4a
 */
IWRAM_DATA struct SoundInfo gSoundInfo = { 0 };
IWRAM_DATA struct MusicPlayer gMPlayInfo_SE4_BMP2 = {};
IWRAM_DATA struct MusicPlayer gMPlayInfo_SE5_BMP3 = {};
IWRAM_DATA struct MusicPlayer gMusicPlayer_FightBgm = {};
IWRAM_DATA MPlayFunc gMPlayJumpTable[36] = { 0 };
IWRAM_DATA struct CgbChannel gCgbChans[4] = { { 0 } };
IWRAM_DATA struct MusicPlayer gMPlayInfo_SE6_BMP4 = {};
IWRAM_DATA struct MusicPlayer gMusicPlayer_MainBgm = {};
IWRAM_DATA struct MusicPlayer gMPlayInfo_SE1_SYS1 = {};
IWRAM_DATA struct MusicPlayer gMPlayInfo_SE3_BMP1 = {};
IWRAM_DATA u8 gMPlayMemAccArea[0x10] = { 0 };
IWRAM_DATA struct MusicPlayer gMPlayInfo_SE7_EVT = {};
IWRAM_DATA struct MusicPlayer gMPlayInfo_SE2_SYS2 = {};

/**
 * Save
 */
IWRAM_DATA void (* ReadSramFast)(void const * src, void * dest, u32 size) = NULL;
IWRAM_DATA u32 (* VerifySramFast)(void const * src, void * dest, u32 size) = NULL;
