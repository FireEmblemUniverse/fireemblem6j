#include "prelude.h"
#include "hardware.h"
#include "banim.h"

CONST_DATA u16 *gBattleBGDataTable[] = {
	BanimBG_081D41C8, BanimBG_081E048C, BanimBG_081DDB8C,
	BanimBG_081D41C8, BanimBG_081E0158, BanimBG_081DDAD4,
	BanimBG_081D0B4C, BanimBG_081DE8A0, BanimBG_081DD1D4,
	BanimBG_081D0B4C, BanimBG_081DEA58, BanimBG_081DD2C0,
	BanimBG_081D0B4C, BanimBG_081DED04, BanimBG_081DD3F4,
	BanimBG_081D0B4C, BanimBG_081DEF48, BanimBG_081DD4DC,
	BanimBG_081D8E04, BanimBG_081DF3DC, BanimBG_081DD6D4,
	BanimBG_081D8E04, BanimBG_081DF650, BanimBG_081DD7E4,
	BanimBG_081D0B4C, BanimBG_081DF7DC, BanimBG_081DD890,
	BanimBG_081D8E04, BanimBG_081DFBBC, BanimBG_081DD9DC,
	BanimBG_081D41C8, BanimBG_081DF110, BanimBG_081DD5D4,
	BanimBG_081D41C8, BanimBG_081DFE78, BanimBG_081DDA68,
	BanimBG_081D0B4C, BanimBG_081DF9E0, BanimBG_081DD950,
	BanimBG_081D41C8, BanimBG_081E0724, BanimBG_081DDCBC,
	BanimBG_081D8E04, BanimBG_081E09CC, BanimBG_081DDDAC,
	BanimBG_081D8E04, BanimBG_081E0BF4, BanimBG_081DDE3C,
	BanimBG_081D41C8, BanimBG_081E048C, BanimBG_081DE528,
	BanimBG_081D0B4C, BanimBG_081DE8A0, BanimBG_081DDF24,
	BanimBG_081D0B4C, BanimBG_081DEA58, BanimBG_081DE008,
	BanimBG_081D0B4C, BanimBG_081DED04, BanimBG_081DE120,
	BanimBG_081D0B4C, BanimBG_081DEF48, BanimBG_081DE1E8,
	BanimBG_081D0B4C, BanimBG_081DF7DC, BanimBG_081DE3FC,
	BanimBG_081D41C8, BanimBG_081DF110, BanimBG_081DE2E4,
	BanimBG_081D41C8, BanimBG_081DFE78, BanimBG_081DE4BC,
	BanimBG_081D41C8, BanimBG_081E0158, BanimBG_081DE680,
	BanimBG_081D41C8, BanimBG_081E0724, BanimBG_081DE740,
	BanimBG_081D41C8, BanimBG_081DFE78, BanimBG_081DE830,
};

void PutBanimBgIMG(int index)
{
	int _i = index * 3;

	LZ77UnCompVram(gBattleBGDataTable[_i], BG_CHAR_ADDR(2));
}

void PutBanimBgTSA(int index)
{
	int _i = index * 3 + 1;

	LZ77UnCompWram(gBattleBGDataTable[_i], gEkrTsaBuffer);
	EfxTmCpyBG(gEkrTsaBuffer, gBg3Tm, 0x1E, 0x14, OBPAL_EFX_BG, 0x0);
}

void PutBanimBgPAL(int index)
{
	int _i = index * 3 + 2;

	LZ77UnCompWram(gBattleBGDataTable[_i], PAL_BG(OBPAL_EFX_BG));
}

void PutBanimBG(int index)
{
	PutBanimBgIMG(index);
	CpuFastFill16(0, (u8 *)BG_VRAM + BG_VRAM_SIZE - 0x20, 0x20);
	PutBanimBgTSA(index);
	PutBanimBgPAL(index);

	PAL_BG_COLOR(0, 0) = RGB(0, 0, 0);
	EnableBgSync(BG3_SYNC_BIT);
	EnablePalSync();
}
