#include "prelude.h"
#include "chapterinfo.h"
#include "bmio.h"
#include "constants/chapterassets.h"

// 08664398
void const * CONST_DATA ChapterAssets[] = {
	[PLIST_0] = NULL,

	[PLIST_MAPASSET1_IMG1] = MapAsset01_Img1,
	[PLIST_MAPASSET1_IMG2] = MapAsset01_Img2,
	[PLIST_MAPASSET1_PAL] = MapAsset01_Pal,
	[PLIST_MAPASSET1_TSA_CONF] = MapAsset01_TsaConf,

	[PLIST_CH0_MAP] = MapTsa_Chapter0,
	[PLIST_MAPASSET1_IMGANIM] = MapAsset01_Anims,
	[PLIST_CH0_MAPCHG] = MapChange_Ch0,
	[PLIST_CH0_EVENT] = &ChapterEventInfo_Tutorial,
	[PLIST_CH0_EVENTWM] = EventScr_Wm_Tutorial,

	[PLIST_CH1_MAP] = MapTsa_Ch1,
	[PLIST_CH1_MAPCHG] = MapChange_Ch1,
	[PLIST_CH1_EVENT] = &ChapterEventInfo_Chapter1,
	[PLIST_CH1_EVENTWM] = EventScr_Wm_Ch1,

	[PLIST_CH2_MAP] = MapTsa_Ch2,
	[PLIST_CH2_MAPCHG] = MapChange_Ch2,
	[PLIST_CH2_EVENT] = &ChapterEventInfo_Chapter2,
	[PLIST_CH2_EVENTWM] = EventScr_Wm_Ch2,

	[PLIST_MAPASSET2_IMG] = MapAsset02_Img,
	[PLIST_MAPASSET2_PAL] = MapAsset02_Pal,
	[PLIST_MAPASSET2_TSA_CONF] = MapAsset02_TsaConf,

	[PLIST_CH3_MAP] = MapTsa_Ch3,
	[PLIST_CH3_MAPCHG] = MapChange_Ch3,
	[PLIST_CH3_EVENT] = &ChapterEventInfo_Chapter3,
	[PLIST_CH3_EVENTWM] = EventScr_Wm_Ch3,

	[PLIST_CH4_MAP] = MapTsa_Ch4,
	[PLIST_CH4_MAPCHG] = MapChange_Ch4,
	[PLIST_CH4_EVENT] = &ChapterEventInfo_Chapter4,
	[PLIST_CH4_EVENTWM] = EventScr_Wm_Ch4,

	[PLIST_CH5_MAP] = MapTsa_Ch5,
	[PLIST_CH5_MAPCHG] = MapChange_Ch5,
	[PLIST_CH5_EVENT] = &ChapterEventInfo_Chapter5,
	[PLIST_CH5_EVENTWM] = EventScr_Wm_Ch5,

	[PLIST_MAPASSET3_IMG] = MapAsset03_Img,
	[PLIST_MAPASSET3_PAL] = MapAsset03_Pal,
	[PLIST_MAPASSET3_TSA_CONF] = MapAsset03_TsaConf,

	[PLIST_CH6_MAP] = MapTsa_Ch6,
	[PLIST_CH6_MAPCHG] = MapChange_Ch6,
	[PLIST_CH6_EVENT] = &ChapterEventInfo_Ch6,
	[PLIST_CH6_EVENTWM] = EventScr_Wm_Ch6,

	[PLIST_CH7_MAP] = MapTsa_Ch7,
	[PLIST_CH7_MAPCHG] = MapChange_Ch7,
	[PLIST_CH7_EVENT] = &ChapterEventInfo_Ch7,
	[PLIST_CH7_EVENTWM] = EventScr_Wm_Ch7,

	[PLIST_MAPASSET4_IMG] = MapAsset04_Img,
	[PLIST_MAPASSET4_PAL] = MapAsset04_Pal,
	[PLIST_MAPASSET4_TSA_CONF] = MapAsset04_TsaConf,

	[PLIST_CH8_MAP] = MapTsa_Ch8,
	[PLIST_CH8_MAPCHG] = MapChange_Ch8,
	[PLIST_CH8_EVENT] = &ChapterEventInfo_Ch8,
	[PLIST_CH8_EVENTWM] = EventScr_Wm_Ch8,

	[PLIST_MAPASSET5_IMG] = MapAsset05_Img,
	[PLIST_MAPASSET5_PAL] = MapAsset05_Pal,
	[PLIST_MAPASSET5_TSA_CONF] = MapAsset05_TsaConf,

	[PLIST_CH9_MAP] = MapTsa_Ch9,
	[PLIST_CH9_MAPCHG] = MapChange_Ch9,
	[PLIST_CH9_EVENT] = &ChapterEventInfo_Ch9,
	[PLIST_CH9_EVENTWM] = EventScr_Wm_Ch9,

	[PLIST_CH10A_MAP] = MapTsa_Ch10a,
	[PLIST_CH10A_MAPCHG] = MapChange_Ch10a,
	[PLIST_CH10A_EVENT] = &ChapterEventInfo_Ch10a,
	[PLIST_CH10A_EVENTWM] = EventScr_Wm_Ch10a,

	[PLIST_MAPASSET6_IMG] = MapAsset06_Img,
	[PLIST_MAPASSET6_PAL] = MapAsset06_Pal,
	[PLIST_MAPASSET6_TSA_CONF] = MapAsset06_TsaConf,

	[PLIST_CH11A_MAP] = MapTsa_Ch11a,
	[PLIST_CH11A_MAPCHG] = MapChange_Ch11a,
	[PLIST_CH11A_EVENT] = &ChapterEventInfo_Ch11a,
	[PLIST_CH11A_EVENTWM] = EventScr_Wm_Ch11a,

	[PLIST_MAPASSET7_IMG] = MapAsset07_Img,
	[PLIST_MAPASSET7_PAL] = MapAsset07_Pal,
	[PLIST_MAPASSET7_TSA_CONF] = MapAsset07_TsaConf,

	[PLIST_CH12_MAP] = MapTsa_Ch12,
	[PLIST_CH12_MAPCHG] = MapChange_Ch12,
	[PLIST_CH12_EVENT] = &ChapterEventInfo_Ch12,
	[PLIST_CH12_EVENTWM] = EventScr_Wm_Ch12,

	[PLIST_MAPASSET1B_IMG2] = MapAsset01B_Img2,
	[PLIST_MAPASSET1B_PAL] = MapAsset01B_Pal,
	[PLIST_MAPASSET1B_TSA_CONF] = MapAsset01B_TsaConf,

	[PLIST_CH13_MAP] = MapTsa_Ch13,
	[PLIST_CH13_MAPCHG] = MapChange_Ch13,
	[PLIST_CH13_EVENT] = &ChapterEventInfo_Ch13,
	[PLIST_CH13_EVENTWM] = EventScr_Wm_Ch13,

	[PLIST_MAPASSET8_IMG] = MapAsset08_Img,
	[PLIST_MAPASSET8_PAL] = MapAsset08_Pal,
	[PLIST_MAPASSET8_TSA_CONF] = MapAsset08_TsaConf,

	[PLIST_CH14_MAP] = MapTsa_Ch14,
	[PLIST_CH14_EVENT] = &ChapterEventInfo_Ch14,
	[PLIST_CH14_EVENTWM] = EventScr_Wm_Ch14,

	[PLIST_CH15_MAP] = MapTsa_Ch15,
	[PLIST_CH15_MAPCHG] = MapChange_Ch15,
	[PLIST_CH15_EVENT] = &ChapterEventInfo_Ch15,
	[PLIST_CH15_EVENTWM] = EventScr_Wm_Ch15,

	[PLIST_MAPASSET4B_PAL] = MapAsset04b_Pal,

	[PLIST_CH16_MAP] = MapTsa_Ch16,
	[PLIST_CH16_MAPCHG] = MapChange_Ch16,
	[PLIST_CH16_EVENT] = &ChapterEventInfo_Ch16,
	[PLIST_CH16_EVENTWM] = EventScr_Wm_Ch16,

	[PLIST_CH17C_MAP] = MapTsa_Ch17c,
	[PLIST_CH17C_MAPCHG] = MapChange_Ch17c,
	[PLIST_CH17C_EVENT] = &ChapterEventInfo_Ch17c,
	[PLIST_CH17C_EVENTWM] = EventScr_Wm_Ch17c,

	[PLIST_MAPASSET9_IMG] = MapAsset09_Img,
	[PLIST_MAPASSET9_PAL] = MapAsset09_Pal,
	[PLIST_MAPASSET9_TSA_CONF] = MapAsset09_TsaConf,
	[PLIST_CH18C_MAP] = MapTsa_Ch18c,
	[PLIST_MAPASSET9_IMGANIM] = MapAsset09_ImgAnims,
	[PLIST_MAPASSET9_PALANIM] = MapAsset09_PalAnims,

	[PLIST_CH18C_MAPCHG] = MapChange_Ch18c,
	[PLIST_CH18C_EVENT] = &ChapterEventInfo_Ch18c,
	[PLIST_CH18C_EVENTWM] = EventScr_Wm_Ch18c,

	[PLIST_CH19C_MAP] = MapTsa_Ch19c,
	[PLIST_CH19C_MAPCHG] = MapChange_Ch19c,
	[PLIST_CH19C_EVENT] = &ChapterEventInfo_Ch19c,
	[PLIST_CH19C_EVENTWM] = EventScr_Wm_Ch19c,

	[PLIST_MAPASSET10_IMG] = MapAsset10_Img,
	[PLIST_MAPASSET10_PAL] = MapAsset10_Pal,
	[PLIST_MAPASSET10_TSA_CONF] = MapAsset10_TsaConf,

	[PLIST_CH20C_MAP] = MapTsa_Ch20c,
	[PLIST_CH20C_MAPCHG] = MapChange_Ch20c,
	[PLIST_CH20C_EVENT] = &ChapterEventInfo_Ch20c,
	[PLIST_CH20C_EVENTWM] = EventScr_Wm_Ch20c,

	[PLIST_MAPASSET01C_IMG] = MapAsset1c_Img,
	[PLIST_MAPASSET01C_PAL] = MapAsset1c_Pal,
	[PLIST_MAPASSET01C_TSA_CONF] = MapAsset1c_TsaConf,

	[PLIST_CH21_MAP] = MapTsa_Ch21,
	[PLIST_CH21_MAPCHG] = MapChange_Ch21,
	[PLIST_CH21_EVENT] = &ChapterEventInfo_Ch21,
	[PLIST_CH21_EVENTWM] = EventScr_Wm_Ch21,

	[PLIST_MAPASSET11_IMG] = MapAsset11_Img,
	[PLIST_MAPASSET11_PAL] = MapAsset11_Pal,
	[PLIST_MAPASSET11_TSA_CONF] = MapAsset11_TsaConf,
	[PLIST_MAPASSET11_IMGANIM] = MapAsset11_ImgAnims,
	[PLIST_MAPASSET11_PALANIM] = MapAsset11_PalAnims,

	[PLIST_CH22_MAP] = MapTsa_Ch22,
	[PLIST_CH22_MAPCHG] = MapChange_Ch22,
	[PLIST_CH22_EVENT] = &ChapterEventInfo_Ch22,
	[PLIST_CH22_EVENTWM] = EventScr_Wm_Ch22,

	[PLIST_CH23_MAP] = MapTsa_Ch23,
	[PLIST_CH23_MAPCHG] = MapChange_Ch23,
	[PLIST_CH23_EVENT] = &ChapterEventInfo_Ch23,
	[PLIST_CH23_EVENTWM] = EventScr_Wm_Ch23,

	[PLIST_MAPASSET12_IMG] = MapAsset12_Img,
	[PLIST_MAPASSET12_PAL] = MapAsset12_Pal,
	[PLIST_MAPASSET12_TSA_CONF] = MapAsset12_TsaConf,

	[PLIST_CH24_MAP] = MapTsa_Ch24,
	[PLIST_CH24_MAPCHG] = MapChange_Ch24,
	[PLIST_CH24_EVENT] = &ChapterEventInfo_Ch24,
	[PLIST_CH24_EVENTWM] = EventScr_Wm_Ch24,

	[PLIST_CH25_MAP] = MapTsa_Ch25,
	[PLIST_MAPASSET12_PALANIM] = MapAsset12_PalAnims,
	[PLIST_CH25_EVENT] = &ChapterEventInfo_Ch25,

	[PLIST_CH10B_MAP] = MapTsa_Ch10b,
	[PLIST_CH10B_MAPCHG] = MapChange_Ch10b,
	[PLIST_CH10B_EVENT] = &ChapterEventInfo_Ch10b,
	[PLIST_CH10B_EVENTWM] = EventScr_Wm_Ch10b,

	[PLIST_CH11B_MAP] = MapTsa_Ch11b,
	[PLIST_CH11B_MAPCHG] = MapChange_Ch11b,
	[PLIST_CH11B_EVENT] = &ChapterEventInfo_Ch11b,
	[PLIST_CH11B_EVENTWM] = EventScr_Wm_Ch11b,

	[PLIST_MAPASSET1_PAL_NIGHT] = MapAsset01_NightPal,

	[PLIST_CH17D_MAP] = MapTsa_Ch17d,
	[PLIST_CH17D_MAPCHG] = MapChange_Ch17d,
	[PLIST_CH17D_EVENT] = &ChapterEventInfo_Ch17d,
	[PLIST_CH17D_EVENTWM] = EventScr_Wm_Ch17d,

	[PLIST_MAPASSET13_IMG] = MapAsset13_Img,
	[PLIST_MAPASSET13_PAL] = MapAsset13_Pal,
	[PLIST_MAPASSET13_TSA_CONF] = MapAsset13_TsaConf,

	[PLIST_CH18D_MAP] = MapTsa_Ch18d,
	[PLIST_CH18D_EVENT] = &ChapterEventInfo_Ch18d,
	[PLIST_CH18D_EVENTWM] = EventScr_Wm_Ch18d,

	[PLIST_MAPASSET13B_PAL] = MapAsset13b_Pal,
	[PLIST_MAPASSET13B_TSA_CONF] = MapAsset13b_TsaConf,

	[PLIST_CH19D_MAP] = MapTsa_Ch19d,
	[PLIST_CH19D_MAPCHG] = MapChange_Ch19d,
	[PLIST_CH19D_EVENT] = &ChapterEventInfo_Ch19d,
	[PLIST_CH19D_EVENTWM] = EventScr_Wm_Ch19d,

	[PLIST_MAPASSET14_IMG] = MapAsset14_Img,
	[PLIST_MAPASSET14_PAL] = MapAsset14_Pal,
	[PLIST_MAPASSET14_TSA_CONF] = MapAsset14_TsaConf,

	[PLIST_CH20D_MAP] = MapTsa_Ch20d,
	[PLIST_CH20D_MAPCHG] = MapChange_Ch20d,
	[PLIST_CH20D_EVENT] = &ChapterEventInfo_Ch20d,
	[PLIST_CH20D_EVENTWM] = EventScr_Wm_Ch20d,

	[PLIST_MAPASSET7B_PAL] = MapAsset7b_Pal,
	[PLIST_CH8X_MAP] = MapTsa_Ch8x,
	[PLIST_MAPASSET7B_PALANIM] = MapAsset7b_PalAnims,
	[PLIST_CH8X_EVENT] = &ChapterEventInfo_Ch8x,
	[PLIST_CH8X_EVENTWM] = EventScr_Wm_Ch8x,

	[PLIST_MAPASSET8B_PAL] = MapAsset8b_Pal,
	[PLIST_MAPASSET8B_TSA_CONF] = MapAsset8b_TsaConf,

	[PLIST_CH12X_MAP] = MapTsa_Ch12x,
	[PLIST_CH12X_MAPCHG] = MapChange_Ch12x,
	[PLIST_CH12X_EVENT] = &ChapterEventInfo_Ch12x,
	[PLIST_CH12X_EVENTWM] = EventScr_Wm_Ch12x,

	[PLIST_MAPASSET4C_PAL] = MapAsset04c_Pal,
	[PLIST_CH14X_MAP] = MapTsa_Ch14x,
	[PLIST_MAPASSET4C_IMGANIM] = MapAsset4c_ImgAnims,
	[PLIST_CH14X_MAPCHG] = MapChange_Ch14x,
	[PLIST_CH14X_EVENT] = &ChapterEventInfo_Ch14x,
	[PLIST_CH14X_EVENTWM] = EventScr_Wm_Ch14x,

	[PLIST_MAPASSET12B_PAL] = MapAsset12b_Pal,
	[PLIST_CH16X_MAP] = MapTsa_Ch16x,
	[PLIST_CH16X_EVENT] = &ChapterEventInfo_Ch16x,
	[PLIST_CH16X_EVENTWM] = EventScr_Wm_Ch16x,

	[PLIST_MAPASSET10B_PAL] = MapAsset10b_Pal,

	[PLIST_CH20CX_MAP] = MapTsa_Ch20cx,
	[PLIST_CH20CX_MAPCHG] = MapChange_Ch20cx,
	[PLIST_CH20CX_EVENT] = &ChapterEventInfo_Ch20cx,
	[PLIST_CH20CX_EVENTWM] = EventScr_Wm_Ch20cx,

	[PLIST_CH20DX_MAP] = MapTsa_Ch20dx,
	[PLIST_CH20DX_EVENT] = &ChapterEventInfo_Ch20dx,
	[PLIST_CH20DX_EVENTWM] = EventScr_Wm_Ch20dx,

	[PLIST_MAPASSET4D_PAL] = MapAsset04d_Pal,

	[PLIST_CH21X_MAP] = MapTsa_Ch21x,
	[PLIST_CH21X_MAPCHG] = MapChange_Ch21x,
	[PLIST_CH21X_EVENT] = &ChapterEventInfo_Ch21x,
	[PLIST_CH21X_EVENTWM] = EventScr_Wm_Ch21x,

	[PLIST_MULTIARENA_MAP] = MapTsa_MultiArena,

	[PLIST_XMAP1_MAP] = MapTsa_Xmap1,
	[PLIST_XMAP1_EVENT] = &ChapterEventInfo_Xmap1,
	[PLIST_XMAP2_MAP] = MapTsa_Xmap2,
	[PLIST_XMAP2_EVENT] = &ChapterEventInfo_Xmap2,
	[PLIST_XMAP3_MAP] = MapTsa_Xmap3,
	[PLIST_XMAP3_EVENT] = &ChapterEventInfo_Xmap3,
	[PLIST_XMAP4_MAP] = MapTsa_Xmap4,
	[PLIST_XMAP4_EVENT] = &ChapterEventInfo_Xmap4,
	[PLIST_XMAP5_MAP] = MapTsa_Xmap5,
	[PLIST_XMAP5_EVENT] = &ChapterEventInfo_Xmap5,
};
