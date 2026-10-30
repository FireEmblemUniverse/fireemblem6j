#include "prelude.h"
#include "gbaio.h"
#include "proc.h"
#include "hardware.h"
#include "armfunc.h"
#include "text.h"
#include "msg.h"
#include "ui.h"
#include "util.h"
#include "bm.h"
#include "unit.h"
#include "unitsprite.h"
#include "sound.h"
#include "m4a.h"
#include "save_multiarena.h"
#include "unitlistscreen.h"
#include "secretscreen.h"
#include "unknown_objects.h"
#include "faction.h"
#include "face.h"
#include "sprite.h"
#include "oam.h"
#include "talk.h"
#include "random.h"
#include "save_game.h"
#include "helpbox.h"
#include "prepscreen.h"
#include "sioerror.h"
#include "bmio.h"
#include "save.h"
#include "debugmenu.h"
#include "event.h"
#include "statscreen.h"
#include "gbasram.h"
#include "save_core.h"
#include "save_xmap.h"
#include "mu.h"
#include "map.h"
#include "trap.h"
#include "chapterinfo.h"
#include "bmio.h"
#include "debugtext.h"
#include "item.h"
#include "menu.h"
#include "icon.h"
#include "battle.h"
#include "battlepreview.h"
#include "action.h"
#include "ai.h"
#include "ai_battle.h"
#include "ai_perform.h"
#include "mapwork.h"
#include "talk.h"
#include "helpbox.h"
#include "banim.h"
#include "banim_ekrbattle.h"
#include "manim.h"
#include "sprite.h"
#include "statscreen.h"
#include "sio_core.h"
#include "sio.h"

#include "constants/iids.h"
#include "constants/songs.h"
#include "constants/msg.h"
#include "constants/faces.h"


u8 const gUnk_Sio_0810F390[][4] = {
	{ 0, 2, 1, 3 },
	{ 1, 3, 0, 2 },
	{ 2, 1, 3, 0 },
	{ 3, 0, 2, 1 },
};

u8 const gUnk_Sio_0810F3A0[][4] = {
	{ 0, 2, 1, 3 },
	{ 2, 0, 3, 1 },
	{ 3, 1, 0, 2 },
	{ 1, 3, 2, 0 },
};

struct Vec2i const gUnk_Sio_0810F3B0[] = {
	{ 5, 9 }, { 6, 9 }, { 7, 9 }, { 8, 9 }, { 9, 9 },
	{ 12, 7 }, { 12, 6 }, { 12, 5 }, { 12, 4 }, { 12, 3 },
	{ 9, 1 }, { 8, 1 }, { 7, 1 }, { 6, 1 }, { 5, 1 },
	{ 2, 3 }, { 2, 4 }, { 2, 5 }, { 2, 6 }, { 2, 7 },
};

u8 const gUnk_Sio_0810F400[] = {
	1, 16,
	24, 16,
	24, 1,
	1, 1,
};

char const gUnk_Sio_0810F408[] = "ＧＥＴ　ＰＯＩＮＴ";

void DrawLinkArenaPointsBox(struct Text * text, int x, int y, int tileref, int number)
{
	int ix, iy;

	u16 * tm = gBg1Tm + TM_OFFSET(x, y);

	for (iy = 0; iy < 4; iy++) {
		for (ix = 0; ix < 6; ix++) {
			*tm = tileref;
			tm++;
			tileref++;
		}

		tm += 0x1A;
	}

	ClearText(text);
	Text_InsertDrawNumberOrBlank(text, 24, TEXT_COLOR_SYSTEM_BLUE, number);
	PutText(text, gBg0Tm + TM_OFFSET(x + 1, y + 1));
}

void LAPointsBox_LoadBoxes(struct LAPointsBoxProc * proc)
{
	int i;
	int tileref;

	Decompress(Img_LAPointsBox, (void *) 0x06002000);
	ApplyPalettes(Pal_TacticianSelObj, 2, 4);

	SetTextFont(NULL);
	ResetTextFont();

	for (i = 0; i < 4; i++) {
		int player_id = gUnk_Sio_0810F390[gSioSt->self_id][i];

		if (func_fe6_08035CB0(player_id)) {
			if (gSioBmSt.unk_0A[player_id] == 0)
				ApplyPalette(gUnk_08109C60, player_id + 2);

			tileref = 0x100 + OAM2_PAL(player_id + 2);

			InitTextDb(&proc->text[i], 4);
			DrawLinkArenaPointsBox(&proc->text[i], gUnk_Sio_0810F400[i * 2 + 0], gUnk_Sio_0810F400[i * 2 + 1], tileref,
				gSioBmSt.current_score[player_id]);
		}
	}

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void LAPointsBox_Dummy(void)
{
}

void StartLinkArenaPointsBox(void)
{
	SetBgOffset(0, 0, 0);
	SetBgOffset(1, 0, 0);

	SpawnProc(ProcScr_LinkArenaPointsBox, PROC_TREE_3);
}

void EndLinkArenaPointsBox(void)
{
	Proc_EndEach(ProcScr_LinkArenaPointsBox);
	ClearUi();
}

void PointsNumberMover_Init(struct PointsNumberMoverProc * proc)
{
	struct Unit * unit = GetUnit(proc->unit_id);

	int idx = gUnk_Sio_0810F3A0[gSioSt->self_id][proc->player_id];

	if (proc->unk_40 != 0) {
		if (unit->x == 8)
			proc->x = unit->x * 16 - 16;
		else
			proc->x = unit->x * 16 - 16;

		proc->y = unit->y * 16;
	} else {
		proc->x = unit->x * 16 + gUnk_Sio_085CA70C[idx * 2 + 0] - 12;
		proc->y = unit->y * 16 + gUnk_Sio_085CA70C[idx * 2 + 1];
	}

	proc->x_target = gUnk_Sio_0810F400[idx * 2 + 0] * 8 + 8;
	proc->y_target = gUnk_Sio_0810F400[idx * 2 + 1] * 8 + 8;

	SetTextFont(&gFont_Unk_Sio_02001000);
	Text_InsertDrawNumberOrBlank(gText_Unk_Sio_02001018, proc->player_id * 32 + 24, TEXT_COLOR_SYSTEM_BLUE, proc->difference);

	proc->timer = 0;
}

void PointsNumberMover_LoopNumberEmerge(struct PointsNumberMoverProc * proc)
{
	struct Unit * unit = GetUnit(proc->unit_id);

	if (proc->timer <= 0x10) {
		int scale = Interpolate(INTERPOLATE_SQUARE, 0x10, 0x100, proc->timer, 0x10);

		SetObjAffine(0,
			Div(+COS_Q12(0) * 16, 0x100),
			Div(-SIN_Q12(0) * 16, scale),
			Div(+SIN_Q12(0) * 16, 0x100),
			Div(+COS_Q12(0) * 16, scale));
	}

	if (proc->unk_40 != 0 && proc->timer > 3 && proc->timer < 23) {
		int idx = proc->timer - 4;

		if (unit->x == 8)
			proc->x = proc->x + gUnk_Sio_085CA72C[idx];
		else
			proc->x = proc->x - gUnk_Sio_085CA72C[idx];

		proc->y = proc->y - gUnk_Sio_085CA752[idx];
	}

	PutOamHiRam(proc->x, proc->y + 0x100, Sprite_32x16, 0x9340 + proc->player_id * 4);

	proc->timer++;

	if (proc->timer > 0x40) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void PointsNumberMover_LoopMoveToPointsBox(struct PointsNumberMoverProc * proc)
{
	int x = Interpolate(INTERPOLATE_RCUBIC, proc->x, proc->x_target, proc->timer, 0x30);
	int y = Interpolate(INTERPOLATE_RCUBIC, proc->y, proc->y_target, proc->timer, 0x30);

	PutOamHiRam(x, y, Sprite_32x16, 0x9340 + proc->player_id * 4);

	proc->timer++;

	if (proc->timer > 0x20)
		Proc_Break(proc);
}

void DrawLinkArenaScoreNumber(struct Text * text, int x, int y, int number)
{
	ClearText(text);
	Text_InsertDrawNumberOrBlank(text, 24, TEXT_COLOR_SYSTEM_BLUE, number);
	PutText(text, gBg0Tm + TM_OFFSET(x + 1, y + 1));
	EnableBgSync(BG0_SYNC_BIT);
}

void PointsNumberMover_InitScoreChange(struct PointsNumberMoverProc * proc)
{
	int idx = gUnk_Sio_0810F3A0[gSioSt->self_id][proc->player_id];

	proc->x = gUnk_Sio_0810F400[idx * 2 + 0];
	proc->y = gUnk_Sio_0810F400[idx * 2 + 1];

	SetTextFont(NULL);

	DrawLinkArenaScoreNumber(&proc->text, proc->x, proc->y, proc->new_score - proc->difference);

	proc->timer = 0;
	proc->unk_44 = proc->new_score - proc->difference;
}

void PointsNumberMover_TickScore(struct PointsNumberMoverProc * proc)
{
	int number = Interpolate(INTERPOLATE_LINEAR, proc->new_score - proc->difference, proc->new_score, proc->timer, 10);

	SetTextFont(NULL);

	DrawLinkArenaScoreNumber(&proc->text, proc->x, proc->y, number);

	if (proc->unk_44 != number && proc->player_id == gSioSt->self_id)
		PlaySe(SONG_80);

	proc->unk_44 = number;

	proc->timer++;

	if (proc->timer > 10) {
		proc->timer = 0;
		gSioBmSt.current_score[proc->player_id] = proc->new_score;
		Proc_Break(proc);
	}
}

void PointsNumberMover_AwaitEnd(struct PointsNumberMoverProc * proc)
{
	proc->timer++;

	if (proc->timer > 20)
		Proc_Break(proc);
}

void PointsSpriteText_Init(struct PointsSpriteTextProc * proc)
{
	SetTextFont(&gFont_Unk_Sio_02001000);
	Text_InsertDrawString(gText_Unk_Sio_02001018, 128, 0, proc->str);
	proc->timer = 0;
}

void PointsSpriteText_LoopIn(struct PointsSpriteTextProc * proc)
{
	if (proc->timer <= 0x10) {
		int scale = Interpolate(INTERPOLATE_SQUARE, 0x10, 0x100, proc->timer, 0x10);

		SetObjAffine(1,
			Div(+COS_Q12(0) * 16, 0x100),
			Div(-SIN_Q12(0) * 16, scale),
			Div(+SIN_Q12(0) * 16, 0x100),
			Div(+COS_Q12(0) * 16, scale));
	}

	PutOamHiRam(proc->x + 0x200, proc->y + 0x100, Sprite_32x16, 0x9350);
	PutOamHiRam(proc->x + 0x220, proc->y + 0x100, Sprite_32x16, 0x9354);
	PutOamHiRam(proc->x + 0x240, proc->y + 0x100, Sprite_16x16, 0x9358);

	proc->timer++;

	if (proc->timer > 0x40) {
		proc->timer = 0;
		Proc_Break(proc);
	}
}

void PointsSpriteText_LoopOut(struct PointsSpriteTextProc * proc)
{
	int scale;

	if (proc->timer <= 0x10) {
		scale = Interpolate(INTERPOLATE_RSQUARE, 0x100, 0x10, proc->timer, 0x10);

		SetObjAffine(1,
			Div(+COS_Q12(0) * 16, 0x100),
			Div(-SIN_Q12(0) * 16, scale),
			Div(+SIN_Q12(0) * 16, 0x100),
			Div(+COS_Q12(0) * 16, scale));
	}

	PutOamHiRam(proc->x + 0x200, proc->y + 0x100, Sprite_32x16, 0x9350);
	PutOamHiRam(proc->x + 0x220, proc->y + 0x100, Sprite_32x16, 0x9354);
	PutOamHiRam(proc->x + 0x240, proc->y + 0x100, Sprite_16x16, 0x9358);

	proc->timer++;

	if (proc->timer > 0x10)
		Proc_Break(proc);
}

bool NewSioPointsSpriteText(int x, int y, char const * str, u8 flag, ProcPtr parent)
{
	int i;
	struct Text text;

	int count = 0;

	ApplyPalette(Pal_Text, 0x19);

	InitSpriteTextFont(&gFont_Unk_Sio_02001000, (void *) 0x06016800, 3);

	SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);
	ResetTextFont();

	InitSpriteText(gText_Unk_Sio_02001018);
	SpriteText_DrawBackgroundExt(gText_Unk_Sio_02001018, 0);

	SetTextFont(NULL);

	for (i = 0; i < 4; i++) {
		int player_id = gUnk_Sio_0810F3A0[gSioSt->self_id][i];

		if (func_fe6_08035CB0(player_id)) {
			if (gSioBmSt.unk_2C[player_id].new_score != 0) {
				struct PointsNumberMoverProc * proc = SpawnProcLocking(ProcScr_LinkArena_PointsNumberMover, parent);
				proc->player_id = player_id;
				proc->unit_id = gSioBmSt.unk_2C[player_id].unit_id;
				proc->new_score = gSioBmSt.current_score[player_id] + gSioBmSt.unk_2C[player_id].new_score;

				if (proc->new_score > 9999)
					proc->new_score = 9999;

				proc->difference = proc->new_score - gSioBmSt.current_score[player_id];
				proc->unk_40 = flag;

				InitTextDb(&proc->text, 4);

				count++;
			} else {
				InitTextDb(&text, 4);
			}
		}
	}

	if (count != 0) {
		if (flag != 0) {
			struct PointsSpriteTextProc * proc = SpawnProcLocking(ProcScr_LinkArena_PointsSpriteText, parent);
			proc->x = x;
			proc->y = y;
			proc->str = str;
		}

		return TRUE;
	}

	return FALSE;
}

void StartSioPoints1(ProcPtr parent)
{
	StartLinkArenaPointsBox();

	if (!NewSioPointsSpriteText(88, 60, gUnk_Sio_0810F408, 1, parent))
		EndLinkArenaPointsBox();
}

void StartSioPoints2(ProcPtr parent)
{
	StartLinkArenaPointsBox();
	NewSioPointsSpriteText(88, 60, gUnk_Sio_0810F408, 0, parent);
}

void func_fe6_0803CA90(struct Unit * unit)
{
	int i;

	for (i = 0; i < ITEMSLOT_INV_COUNT; i++)
		gUnk_03001418[i] = unit->items[i];
}

void func_fe6_0803CAAC(struct Unit * unit)
{
	int i;

	for (i = 0; i < ITEMSLOT_INV_COUNT; i++)
		unit->items[i] = gUnk_03001418[i];
}

void func_fe6_0803CAC8(void)
{
	func_fe6_0803CD74();
	RefreshUnitSprites();
}

void func_fe6_0803CAD8(int player_id)
{
	int current = player_id;
	int next = 0;

	while (TRUE) {
		switch (current) {
		case 0:
			next = 2;
			break;

		case 1:
			next = 3;
			break;

		case 2:
			next = 1;
			break;

		case 3:
			next = 0;
			break;

		case 0xFF:
			next = 0xFF;
			break;
		}

		if (gSioBmSt.unk_0A[next] != 0 || next == 0xFF)
			break;

		current = next;
	}

	gSioBmSt.unk_01 = next;
}

void func_fe6_0803CB28(void)
{
	gUnk_0300140C[0] = 0;
	gUnk_0300140C[1] = 0;
	gUnk_0300140C[3] = 0;
	gUnk_0300140C[2] = 0;
}

u16 func_fe6_0803CB3C(u8 a, u8 b, u8 c, u8 d)
{
	func_fe6_0803CB28();

	gUnk_0300140C[0] = a;
	gUnk_0300140C[1] = b;
	gUnk_0300140C[2] = c;
	gUnk_0300140C[3] = d;

	if (gLinkArenaSt.unk_00 == 2)
		return SioEmitData(gUnk_0300140C, 4);

	return 0;
}

int func_fe6_0803CB94(u8 unit_id)
{
	int i = 0;

	for (i = 0; i < 20; i++) {
		if (gUnk_030013F0[i] == unit_id)
			return i;
	}
}

void func_fe6_0803CBB4(u8 unit_id, int mu_idx, u8 * idx_out, int * x_out, int * y_out)
{
	struct Unit * unit;

	u8 movescr[8] = {
		MOVE_CMD_MOVE_UP, MOVE_CMD_HALT,
		MOVE_CMD_MOVE_LEFT, MOVE_CMD_HALT,
		MOVE_CMD_MOVE_DOWN, MOVE_CMD_HALT,
		MOVE_CMD_MOVE_RIGHT, MOVE_CMD_HALT,
	};

	i8 offsets[8] = {
		+0, -1,
		-1, +0,
		+0, +1,
		+1, +0,
	};

	int var = func_fe6_0803CB94(unit_id);
	int index = Div(var, 5) << 1;

	*idx_out = var;

	unit = GetUnit(gUnk_030013F0[var]);

	if ((unit->flags & UNIT_FLAG_CONCEALED) == 0) {
		gUnk_03001410[mu_idx] = StartMu(unit);
		DisableMuCamera(gUnk_03001410[mu_idx]);
		SetMuMoveScript(gUnk_03001410[mu_idx], movescr + index);
	}

	unit->flags |= UNIT_FLAG_HIDDEN;

	RefreshUnitSprites();

	*x_out = unit->x + offsets[index + 0];
	*y_out = unit->y + offsets[index + 1];

	if ((unit->flags & UNIT_FLAG_CONCEALED) != 0) {
		unit->x = *x_out;
		unit->y = *y_out;

		*x_out = *x_out - offsets[index + 0];
		*y_out = *y_out - offsets[index + 1];

		gUnk_03001410[mu_idx] = NULL;
	}
}

void func_fe6_0803CCBC(void)
{
	int i = 0;

	for (i = 0; i < 20; i++)
		gUnk_030013F0[i] = 0;
}

u8 const gUnk_Sio_0810F42B[] = { 4, 2, 0, 1, 3 };

void func_fe6_0803CCD4(void)
{
	int unit_base;
	int i, j;

	for (i = 0; i < 4; i++) {
		int player_id = gUnk_Sio_0810F390[gSioSt->self_id][i];

		if (!func_fe6_08035CB0(player_id))
			continue;

		unit_base = player_id * 0x40 + 1;

		for (j = 0; j < 5; j++) {
			int idx = i * 5 + j;
			int unit_id = unit_base + gUnk_Sio_0810F42B[j];

			struct Unit * unit = GetUnit(unit_id);

			if (unit->pinfo != NULL) {
				gUnk_030013F0[idx] = unit_id;

				unit->x = gUnk_Sio_0810F3B0[idx].x;
				unit->y = gUnk_Sio_0810F3B0[idx].y;
			}
		}
	}
}

void func_fe6_0803CD74(void)
{
	int i;

	MapFill(gMapUnit, 0);
	MapFill(gMapFog, 1);

	for (i = FACTION_BLUE + 1; i < FACTION_PURPLE + 6; i++) {
		struct Unit * unit = GetUnit(i);

		if (unit == NULL || unit->pinfo == NULL)
			continue;

		if ((unit->flags & UNIT_FLAG_HIDDEN) != 0)
			continue;

		gMapUnit[unit->y][unit->x] = i;
	}
}

void func_fe6_0803CDD4(void)
{
	int i, j;

	for (i = 0; i < 4; i++) {
		int unit_base;

		int player_id = gUnk_Sio_0810F390[gSioSt->self_id][i];

		if (!func_fe6_08035CB0(player_id))
			continue;

		unit_base = player_id * 0x40 + 1;

		for (j = 0; j < 5; j++) {
			int idx = i * 5 + j;
			int unit_id = unit_base + gUnk_Sio_0810F42B[j];

			struct Unit * unit = GetUnit(unit_id);

			if (unit->pinfo == NULL || (unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD)) != 0)
				gUnk_030013F0[idx] = 0;
			else
				gUnk_030013F0[idx] = unit_id;
		}
	}
}

void func_fe6_0803CE7C(void)
{
	CpuFill16(0, &gBmSt, sizeof(gBmSt));

	gBmSt.flags |= BM_FLAG_LINKARENA;

	InitTraps();

	gPlaySt.chapter = 0x27;
	gPlaySt.turn = 0;

	gPlaySt.vision = GetChapterInfo(gPlaySt.chapter)->fog;
	gPlaySt.weather = GetChapterInfo(gPlaySt.chapter)->weather;

	InitMapForChapter(0x27);

	gPlaySt.time_chapter_started = GetGameTime();
}

void func_fe6_0803CEDC(void)
{
	func_fe6_0803CE7C();
	func_fe6_0803CCBC();
	func_fe6_0803CCD4();

	MapFill(gMapFog, gPlaySt.vision == 0);

	func_fe6_0803CD74();

	RenderMap();
}

void func_fe6_0803CF14(void)
{
	int i;

	for (i = 0; i < 4; i++)
		gSioBmSt.unk_0A[i] = 0;

	for (i = 0; i < 20; i++) {
		u32 unit_id = gUnk_030013F0[i];

		if (unit_id != 0)
			gSioBmSt.unk_0A[unit_id >> 6]++;
	}
}

void func_fe6_0803CF58(void)
{
	Decompress(gUnk_08109854, (void *) 0x06014800);
}

void func_fe6_0803CF70(void)
{
	InitBgs(NULL);
	ApplySystemGraphics();
	ApplyUnitSpritePalettes();
	ForceSyncUnitSpriteSheet();
	func_fe6_0803CF58();
	InitSystemTextFont();

	gSioBmSt.unk_03 = 0xFF;
}

void func_fe6_0803CF9C(void)
{
	gPlaySt.config_battle_anim = PLAY_ANIMCONF_ON;
	gPlaySt.config_no_auto_cursor = 1;
	gPlaySt.config_talk_speed = 2;
	gPlaySt.config_walk_speed = 0;
	gPlaySt.config_bgm_disable = 0;
	gPlaySt.config_se_disable = 0;
	gPlaySt.config_window_theme = 0;
	gPlaySt.config_battle_preview_kind = 0;
	gPlaySt.config_unique_pal = 1;
}

void func_fe6_0803CFE4(void)
{
	int i;
	struct Unit * unit;

	InitBgs(NULL);
	ClearSioBG();

	func_fe6_0803CEDC();
	func_fe6_0803CF14();

	gSioBmSt.unk_09 = 0;
	gLinkArenaSt.unk_0B = 0;

	func_fe6_0803CAD8(gUnk_Sio_085CA7E0[gSioBmSt.unk_00]);

	gSioBmSt.unk_0E = 1;
	gSioBmSt.unk_02 = 0;
	gSioBmSt.unk_03 = 1;

	for (i = 0; i < 4; i++)
		gSioBmSt.current_score[i] = 0;

	unit = GetUnit(gUnk_030013F0[3]);

	gUnk_03001404.x = unit->x * 16;
	gUnk_03001404.y = unit->y * 16;

	SetMapCursorPosition(unit->x, unit->y);

	gBmSt.camera.x = 0;
	gBmSt.camera.y = 0;

	ApplySystemGraphics();

	ApplyUnitSpritePalettes();
	ResetUnitSprites();
	RefreshUnitSprites();

	func_fe6_0803CF58();
	func_fe6_0803EA30();

	SpawnProc(ProcScr_MapTask, PROC_TREE_4);
	StartBmVSync();
	func_fe6_0803CF9C();
}

void func_fe6_0803D0A0(void)
{
	struct Unit * unit = GetUnit(gUnk_030013F0[gSioBmSt.unk_04]);

	gUnk_03001410[0] = StartMu(unit);

	SetMuScreenPosition(gUnk_03001410[0], unit->x * 16, (unit->y - 1) * 16);

	DisableMuCamera(gUnk_03001410[0]);
	SetMuFacing(gUnk_03001410[0], 3);
}

void func_fe6_0803D0EC(ProcPtr proc)
{
	if ((gKeySt->pressed & KEY_BUTTON_L) != 0)
		Proc_Break(proc);
}

void func_fe6_0803D110(ProcPtr parent)
{
	switch (gLinkArenaSt.unk_00) {
	case 1:
		if (gPlaySt.faction == FACTION_BLUE)
			SpawnProcLocking(gUnk_Sio_085CA974, parent);
		else
			SpawnProcLocking(gUnk_Sio_085CAC14, parent);

		break;

	case 2:
		if (gPlaySt.faction == gSioSt->self_id)
			SpawnProcLocking(gUnk_Sio_085CA974, parent);
		else
			SpawnProcLocking(gUnk_Sio_085CAB24, parent);

		break;
	}

	Proc_Break(parent);
}

void func_fe6_0803D178(ProcPtr proc)
{
	int i = 0;

	if (gLinkArenaSt.unk_00 == 1) {
		if (gLinkArenaSt.unk_0B == 1) {
			Proc_Goto(proc, 3);
			return;
		}
	} else if (gLinkArenaSt.unk_0B == 2) {
		Proc_Goto(proc, 3);
		return;
	}

	if (gSioBmSt.unk_01 == 0xFF) {
		Proc_Goto(proc, 2);
		return;
	}

	gPlaySt.faction = gSioBmSt.unk_01;

	for (; gUnk_030013F0[i] == 0; i++) {
	}

	gSioBmSt.unk_02 = i;
	gSioBmSt.unk_03 = i + 1;

	ApplySystemObjectsGraphics();

	for (i = 0; i < 4; i++) {
		gSioBmSt.unk_2C[i].new_score = 0;
		gSioBmSt.unk_2C[i].unit_id = 0;
	}

	DebugInitObj(-1, 9);
}

int func_fe6_0803D208(void)
{
	int i;

	u32 ret = 4;

	u32 score = gSioBmSt.current_score[gSioSt->self_id];

	if (gLinkArenaSt.rules.unk_0_1) {
		for (i = 0; i < 4; i++) {
			if (func_fe6_08035CB0(i) && gSioSt->self_id == gSioBmSt.unk_0F[i])
				return i;
		}

		ret = 3;
	} else {
		for (i = 0; i < 4; i++) {
			if (!func_fe6_08035CB0(i)) {
				ret--;
				continue;
			}

			if (gSioSt->self_id == i) {
				ret--;
				continue;
			}

			if (score > gSioBmSt.current_score[i]) {
				ret--;
				continue;
			}
		}
	}

	return ret;
}

void func_fe6_0803D2AC(void)
{
	Proc_EndEach(ProcScr_MapTask);

	func_fe6_0803EA44();

	EndBmVSync();
	FadeBgmOut(1);
}

void func_fe6_0803D2CC(u16 keys, i8 flag)
{
	u8 cur;
	int base;
	int dir;

	cur = gSioBmSt.unk_02;
	dir = cur;
	gSioBmSt.unk_03 = gSioBmSt.unk_02;

	if ((keys & KEY_DPAD_ANY) == 0)
		return;

	base = cur << 2;

	if ((keys & KEY_DPAD_UP) != 0)
		cur = gUnk_Sio_085CA7E4[base + 0];
	else if ((keys & KEY_DPAD_DOWN) != 0)
		cur = gUnk_Sio_085CA7E4[base + 1];
	else if ((keys & KEY_DPAD_LEFT) != 0)
		cur = gUnk_Sio_085CA7E4[base + 2];
	else if ((keys & KEY_DPAD_RIGHT) != 0)
		cur = gUnk_Sio_085CA7E4[base + 3];

	dir = cur - dir;

	if (gSioBmSt.unk_03 == 0 && (keys & KEY_DPAD_LEFT) != 0)
		dir = -1;

	if (gSioBmSt.unk_03 == 19 && (keys & KEY_DPAD_DOWN) != 0)
		dir = +1;

	while (TRUE) {
		if (gUnk_030013F0[cur] != 0) {
			if (flag == 0 || (gUnk_030013F0[cur] >> 6) != gSioSt->self_id)
				goto end;
		}

		if (dir < 0) {
			cur--;

			if (cur == 0xFF)
				cur = 19;
		} else {
			cur++;
			cur = cur % 20;
		}
	}

end:
	gSioBmSt.unk_02 = cur;
}

void func_fe6_0803D3C0(void)
{
	struct Unit * unit_a;
	struct Unit * unit_b;

	if (gSioBmSt.unk_02 == gSioBmSt.unk_03)
		return;

	unit_a = GetUnit(gUnk_030013F0[gSioBmSt.unk_03]);
	unit_b = GetUnit(gUnk_030013F0[gSioBmSt.unk_02]);

	if (unit_a != NULL) {
		EndAllMus();
		ShowUnitSprite(unit_a);
	}

	if (unit_b == NULL)
		return;

	if ((unit_b->flags & UNIT_FLAG_TURN_ENDED) != 0)
		return;

	if ((gUnk_030013F0[gSioBmSt.unk_02] >> 6) != gSioSt->self_id)
		return;

	DisableMuCamera(StartMu(unit_b));
	HideUnitSprite(unit_b);
}

bool func_fe6_0803D438(struct Unit * unit)
{
	int i;

	for (i = 0; i < ITEMSLOT_INV_COUNT; i++) {
		u16 item = unit->items[i];

		if ((GetItemAttributes(item) & ITEM_ATTR_WEAPON) == 0)
			continue;

		if (CanUnitUseWeapon(unit, item) == TRUE)
			return TRUE;
	}

	return FALSE;
}

void func_fe6_0803D478(ProcPtr proc)
{
	if (gSioBmSt.unk_09 >= gLinkArenaSt.unk_A0 * 3) {
		EndLinkArenaPointsBox();
		StartEvent(gUnk_Sio_085CA958);
		Proc_Goto(proc, 3);
	}

	Proc_Break(proc);
}

void func_fe6_0803D4B8(ProcPtr proc)
{
	if (func_fe6_08035D4C() < 8)
		Proc_Break(proc);
}

void func_fe6_0803D4D0(struct SioBattleMapProc * proc)
{
	int x, y;

	u8 movescr[2] = { MOVE_CMD_MOVE_UP, MOVE_CMD_HALT };

	u8 previous = gSioBmSt.unk_02;

	func_fe6_0803D3C0();
	func_fe6_0803D2CC(gKeySt->repeated, 0);

	gActiveUnitId = gUnk_030013F0[gSioBmSt.unk_02];
	gActiveUnit = GetUnit(gActiveUnitId);

	if ((gKeySt->pressed & KEY_BUTTON_A) != 0) {
		if ((gActiveUnitId >> 6) == gSioSt->self_id && func_fe6_0803D438(gActiveUnit) == TRUE) {
			PlaySe(SONG_69);
			EndAllMus();

			gUnk_03001410[0] = StartMu(gActiveUnit);
			DisableMuCamera(gUnk_03001410[0]);
			SetMuMoveScript(gUnk_03001410[0], movescr);

			proc->unk_2C = gActiveUnit->x;
			proc->unk_30 = gActiveUnit->y - 1;
			gActiveUnit->flags |= UNIT_FLAG_HIDDEN;

			func_fe6_0803CAC8();

			gSioBmSt.unk_04 = gSioBmSt.unk_02;

			func_fe6_0803D2CC(KEY_DPAD_UP, 1);
			func_fe6_0803CB3C(1, gActiveUnitId, 0, 0);

			Proc_Goto(proc, 5);
			return;
		}

		PlaySe(SONG_6C);
	}

	if ((gKeySt->pressed & KEY_BUTTON_R) != 0) {
		if ((gActiveUnit->flags & UNIT_FLAG_CONCEALED) == 0) {
			EndAllMus();
			Proc_Goto(proc, 4);
			return;
		}
	}

	if ((gKeySt->pressed & KEY_BUTTON_START) != 0) {
		EndLinkArenaPointsBox();

		if (!gPlaySt.config_se_disable) {
			m4aSongNumStart(SONG_68);
			StartEvent(gUnk_Sio_085CA93C);
		}

		Proc_Goto(proc, 2);
		return;
	}

	x = gActiveUnit->x * 16;
	y = gActiveUnit->y * 16;

	SetMapCursorPosition(gActiveUnit->x, gActiveUnit->y);

	if (GetGameTime() - 1 == gUnk_03001408) {
		x = (x + gUnk_03001404.x) >> 1;
		y = (y + gUnk_03001404.y) >> 1;
	}

	gUnk_03001404.x = x;
	gUnk_03001404.y = y;

	gUnk_03001408 = GetGameTime();

	PutMapCursor(x, y, 0);

	if (previous != gSioBmSt.unk_02)
		PlaySe(SONG_65);
}

void func_fe6_0803D6E0(ProcPtr proc)
{
	StartLinkArenaPointsBox();
}

void func_fe6_0803D6EC(struct SioBattleMapProc * proc)
{
	int x, y;

	u8 previous = gSioBmSt.unk_02;

	func_fe6_0803D2CC(gKeySt->repeated, 1);

	gActiveUnitId = gUnk_030013F0[gSioBmSt.unk_02];

	gActiveUnit = GetUnit(gActiveUnitId);
	x = gActiveUnit->x * 16;
	y = gActiveUnit->y * 16;

	SetMapCursorPosition(gActiveUnit->x, gActiveUnit->y);

	if (GetGameTime() - 1 == gUnk_03001408) {
		x = (x + gUnk_03001404.x) >> 1;
		y = (y + gUnk_03001404.y) >> 1;
	}

	gUnk_03001404.x = x;
	gUnk_03001404.y = y;

	gUnk_03001408 = GetGameTime();

	PutMapCursor(x, y, 0);

	if ((gKeySt->pressed & KEY_BUTTON_A) != 0) {
		PlaySe(SONG_69);

		func_fe6_0803CBB4(gUnk_030013F0[gSioBmSt.unk_02], 1, &gSioBmSt.unk_05, &proc->unk_34, &proc->unk_38);
		func_fe6_0803CB3C(3, gUnk_030013F0[gSioBmSt.unk_05], gActiveUnitId, 0);
		EndLinkArenaPointsBox();

		Proc_Goto(proc, 7);
		return;
	}

	if ((gKeySt->pressed & KEY_BUTTON_B) != 0) {
		PlaySe(SONG_6B);

		EndMu(gUnk_03001410[0]);
		GetUnit(gUnk_030013F0[gSioBmSt.unk_04])->flags &= ~UNIT_FLAG_HIDDEN;

		func_fe6_0803CAC8();

		gSioBmSt.unk_02 = gSioBmSt.unk_04;
		gSioBmSt.unk_03 = gSioBmSt.unk_04 + 1;

		func_fe6_0803CB3C(2, gActiveUnitId, gUnk_030013F0[gSioBmSt.unk_04], 0);

		Proc_Goto(proc, 1);
		return;
	}

	if ((gKeySt->pressed & KEY_BUTTON_R) != 0) {
		if ((gActiveUnit->flags & UNIT_FLAG_CONCEALED) == 0) {
			EndAllMus();
			Proc_Goto(proc, 6);
			return;
		}
	}

	if (previous != gSioBmSt.unk_02)
		PlaySe(SONG_65);
}

void func_fe6_0803D8AC(struct SioAttackProc * proc)
{
	ResetTextFont();

	gSioBmSt.unk_06 = 0xFF;

	gActiveUnit = GetUnit(gUnk_030013F0[gSioBmSt.unk_04]);
	func_fe6_0803CA90(gActiveUnit);

	proc->game_lock = GetGameLock();
	ApplyIconPalettes(4);

	StartMenu(&gUnk_Sio_085CB384);
}

void func_fe6_0803D8FC(struct SioAttackProc * proc)
{
	if (proc->game_lock != GetGameLock())
		return;

	if (gSioBmSt.unk_06 == 0) {
		func_fe6_0803CAAC(gActiveUnit);
		Proc_End(proc);
	}

	Proc_Break(proc);
}

void func_fe6_0803D93C(struct SioAttackProc * proc)
{
	u16 item = gActiveUnit->items[gSioBmSt.unk_07];

	proc->game_lock = GetGameLock();

	if (GetItemMinRange(item) == 1 && GetItemMaxRange(item) == 1) {
		gSioBmSt.unk_06 = 1;
		return;
	}

	if (GetItemMinRange(item) == 2 && GetItemMaxRange(item) == 2) {
		gSioBmSt.unk_06 = 2;
		return;
	}

	if (GetItemMinRange(item) == 2 && GetItemMaxRange(item) == 3) {
		gSioBmSt.unk_06 = 2;
		return;
	}

	item = GetUnitEquippedWeapon(GetUnit(gUnk_030013F0[gSioBmSt.unk_05]));

	if (item == 0) {
		gSioBmSt.unk_06 = 1;
		return;
	}

	if (GetItemMinRange(item) >= 2) {
		gSioBmSt.unk_06 = 2;
		return;
	}

	gSioBmSt.unk_06 = 1;
	ApplyIconPalettes(4);
}

void func_fe6_0803DA04(struct SioAttackProc * proc)
{
	int x_offset = 0;

	struct Unit * unit_a = GetUnit(gUnk_030013F0[gSioBmSt.unk_04]);
	struct Unit * unit_b = GetUnit(gUnk_030013F0[gSioBmSt.unk_05]);

	if (proc->game_lock != GetGameLock())
		return;

	if (gSioBmSt.unk_06 == 0) {
		func_fe6_0803CAAC(gActiveUnit);
		Proc_Goto(proc, 0);
		return;
	}

	UnitEquipItemSlot(gActiveUnit, gSioBmSt.unk_07);

	if ((unit_b->flags & UNIT_FLAG_CONCEALED) == 0) {
		StartBattlePreview((struct MapSelectProc *) proc);
		x_offset = (gSioBmSt.unk_06 == 2) ? 1 : 0;
		BattleGenerateSimulation(unit_a, unit_b, unit_b->x + x_offset, unit_b->y + 1, 0);
		UpdateBattlePreviewContents();
		func_fe6_0803CAAC(gActiveUnit);
		Proc_Break(proc);
	} else {
		func_fe6_0803CAAC(gActiveUnit);
		Proc_Goto(proc, 1);
	}
}

void func_fe6_0803DAE8(ProcPtr proc)
{
	if ((gKeySt->pressed & KEY_BUTTON_A) != 0) {
		PlaySe(SONG_6A);
		CloseBattlePreview();

		Proc_Break(proc);
		return;
	}

	if ((gKeySt->pressed & KEY_BUTTON_B) != 0) {
		PlaySe(SONG_6B);
		CloseBattlePreview();

		Proc_Goto(proc, 0);
	}
}

void func_fe6_0803DB50(ProcPtr proc)
{
	SpawnProcLocking(gUnk_Sio_085CA834, proc);
	Proc_Break(proc);
}

void func_fe6_0803DB6C(struct SioBattleMapProc * proc)
{
	struct Unit * unit = GetUnit(gUnk_030013F0[gSioBmSt.unk_05]);

	ClearUi();

	if (gSioBmSt.unk_06 == 0) {
		if ((unit->flags & UNIT_FLAG_CONCEALED) == 0) {
			EndMu(gUnk_03001410[1]);
		} else {
			unit->x = proc->unk_34;
			unit->y = proc->unk_38;
		}

		unit->flags &= ~UNIT_FLAG_HIDDEN;

		RefreshUnitSprites();

		gSioBmSt.unk_02 = gSioBmSt.unk_05;
		gSioBmSt.unk_03 = gSioBmSt.unk_05 + 1;
		func_fe6_0803CB3C(4, 0, gUnk_030013F0[gSioBmSt.unk_05], 0);
		func_fe6_0803D6E0(proc);
		Proc_Goto(proc, 5);
	} else {
		if ((unit->flags & UNIT_FLAG_CONCEALED) != 0) {
			gUnk_03001410[1] = StartMu(unit);
			proc->unk_34 = unit->x;
			proc->unk_38 = unit->y;
			unit->flags &= ~UNIT_FLAG_CONCEALED;
		}

		func_fe6_0803CB3C(5, 0, gSioBmSt.unk_06, gSioBmSt.unk_07);
	}
}

void func_fe6_0803DC3C(struct SioBattleMapProc * proc)
{
	struct Unit * unit_a = GetUnit(gUnk_030013F0[gSioBmSt.unk_04]);
	struct Unit * unit_b = GetUnit(gUnk_030013F0[gSioBmSt.unk_05]);

	unit_a->x = proc->unk_2C;
	unit_a->y = proc->unk_30;

	unit_b->x = proc->unk_34;
	unit_b->y = proc->unk_38;

	NewSioWarpFx(unit_a, gUnk_03001410[0], 6, 5, 1, 1, proc);
	NewSioWarpFx(unit_b, gUnk_03001410[1], 8, 5, 0, 0, proc);
}

void func_fe6_0803DCC0(void)
{
	struct Unit * unit_b;
	struct Unit * unit_a = GetUnit(gUnk_030013F0[gSioBmSt.unk_04]);

	u8 movescr[2] = { MOVE_CMD_MOVE_RIGHT, MOVE_CMD_HALT };

	EndMu(gUnk_03001410[1]);

	unit_b = GetUnit(gUnk_030013F0[gSioBmSt.unk_05]);
	unit_b->flags &= ~UNIT_FLAG_HIDDEN;

	if (gUnk_0300140C[2] == 1) {
		SetMuMoveScript(gUnk_03001410[0], movescr);
		unit_a->x = 7;
	}

	func_fe6_0803CAC8();
}

void func_fe6_0803DD30(ProcPtr proc)
{
	struct Unit * unit_a;
	struct Unit * unit_b;

	if (MuExistsActive() == TRUE)
		return;

	unit_a = GetUnit(gUnk_030013F0[gSioBmSt.unk_04]);
	unit_b = GetUnit(gUnk_030013F0[gSioBmSt.unk_05]);

	HideUnitSprite(unit_a);

	gAction.id = ACTION_COMBAT;
	gAction.target = gUnk_030013F0[gSioBmSt.unk_05];

	UnitEquipItemSlot(unit_a, gUnk_0300140C[3]);
	BattleGenerateReal(unit_a, unit_b);

	gBmSt.flags |= BM_FLAG_LINKARENA;

	SpawnProcLocking(gUnk_Sio_085CADA4, proc);
	Proc_Break(proc);
}

void func_fe6_0803DDC0(ProcPtr proc)
{
	u8 unit_id_a = gUnk_030013F0[gSioBmSt.unk_04];
	u8 unit_id_b = gUnk_030013F0[gSioBmSt.unk_05];

	struct Unit * unit_a = GetUnit(unit_id_a);
	struct Unit * unit_b = GetUnit(unit_id_b);

	func_fe6_0803CF58();

	gSioBmSt.unk_2C[unit_id_a >> 6].new_score = gBattleUnitA.exp_gain;
	gSioBmSt.unk_2C[unit_id_a >> 6].unit_id = unit_id_a;
	unit_a->exp = 0;

	gSioBmSt.unk_2C[unit_id_b >> 6].new_score = gBattleUnitB.exp_gain;
	gSioBmSt.unk_2C[unit_id_b >> 6].unit_id = unit_id_b;
	unit_b->exp = 0;

	SioSetUniqueWeapons(unit_a);
	SioSetUniqueWeapons(unit_b);

	SetUnitStatus(unit_a, 0);
	SetUnitStatus(unit_b, 0);

	EndAllMus();

	if (GetUnitCurrentHp(unit_a) != 0) {
		ShowUnitSprite(unit_a);
		unit_a->flags &= ~UNIT_FLAG_HIDDEN;
	}

	func_fe6_0803CAC8();
	SetBgOffset(2, 0, 0);

	if (GetUnitCurrentHp(unit_a) == gBattleUnitA.previous_hp && GetUnitCurrentHp(unit_b) == gBattleUnitB.previous_hp)
		gSioBmSt.unk_09++;
	else
		gSioBmSt.unk_09 = 0;

	Proc_Break(proc);
}

void func_fe6_0803DEE0(ProcPtr proc)
{
	u8 unit_id_a = gUnk_030013F0[gSioBmSt.unk_04];
	u8 unit_id_b = gUnk_030013F0[gSioBmSt.unk_05];

	struct Unit * unit_a = GetUnit(unit_id_a);
	struct Unit * unit_b = GetUnit(unit_id_b);

	i8 flag = 0;

	int idx_a = func_fe6_0803CB94(unit_id_a);
	int idx_b = func_fe6_0803CB94(unit_id_b);

	gUnk_03001410[1] = NULL;
	gUnk_03001410[0] = NULL;

	if ((unit_a->flags & UNIT_FLAG_DEAD) != 0 || unit_a->pinfo == NULL) {
		gSioBmSt.unk_0A[unit_id_a >> 6]--;
	} else {
		gUnk_03001410[0] = StartMu(unit_a);
		DisableMuCamera(gUnk_03001410[0]);

		unit_a->flags |= UNIT_FLAG_HIDDEN;

		flag = 1;

		NewSioWarpFx(unit_a, gUnk_03001410[0], gUnk_Sio_0810F3B0[idx_a].x, gUnk_Sio_0810F3B0[idx_a].y, 2, flag, proc);
	}

	if ((unit_b->flags & UNIT_FLAG_DEAD) != 0 || unit_b->pinfo == NULL) {
		gSioBmSt.unk_0A[unit_id_b >> 6]--;
	} else {
		gUnk_03001410[1] = StartMu(unit_b);
		DisableMuCamera(gUnk_03001410[1]);

		unit_b->flags |= UNIT_FLAG_HIDDEN;

		if (!flag)
			flag = 1;
		else
			flag = 0;

		NewSioWarpFx(unit_b, gUnk_03001410[1], gUnk_Sio_0810F3B0[idx_b].x, gUnk_Sio_0810F3B0[idx_b].y, 2, flag, proc);
	}

	func_fe6_0803CAC8();

	Proc_Break(proc);
}

void func_fe6_0803E028(void)
{
	int i;

	for (i = 0; i < 4; i++) {
		int j;
		int usable_count;
		int count;

		if (!func_fe6_08035CB0(i))
			continue;

		usable_count = 0;
		count = 0;

		for (j = 0; j < 5; j++) {
			struct Unit * unit;

			if (gUnk_030013F0[i + j * 5] == 0)
				continue;

			count++;

			unit = GetUnit(gUnk_030013F0[i + j * 5]);

			if ((unit->flags & UNIT_FLAG_DEAD) != 0)
				continue;

			if (func_fe6_0803D438(unit) == TRUE)
				usable_count++;
		}

		if (usable_count == 0 && count != 0)
			gSioBmSt.unk_0A[i] = 0;
	}
}

void func_fe6_0803E0B4(ProcPtr proc)
{
	u8 player_id;

	u8 unit_id_a = gUnk_030013F0[gSioBmSt.unk_04];
	u8 unit_id_b = gUnk_030013F0[gSioBmSt.unk_05];

	struct Unit * unit_a = GetUnit(unit_id_a);
	struct Unit * unit_b = GetUnit(unit_id_b);

	if ((unit_a->flags & UNIT_FLAG_DEAD) == 0)
		unit_a->flags &= ~UNIT_FLAG_HIDDEN;

	if ((unit_b->flags & UNIT_FLAG_DEAD) == 0)
		unit_b->flags &= ~UNIT_FLAG_HIDDEN;

	if (gSioBmSt.unk_0A[unit_id_a >> 6] == 0)
		player_id = unit_id_a >> 6;
	else if (gSioBmSt.unk_0A[unit_id_b >> 6] == 0)
		player_id = unit_id_b >> 6;
	else
		goto end;

	gSioBmSt.unk_0F[gLinkArenaSt.unk_A0 - gSioBmSt.unk_0E] = player_id;
	gSioBmSt.unk_0E++;

	if (gSioBmSt.unk_0E == gLinkArenaSt.unk_A0) {
		if (gSioBmSt.unk_0A[unit_id_a >> 6] != 0)
			player_id = unit_id_a >> 6;
		else
			player_id = unit_id_b >> 6;

		gSioBmSt.unk_0F[0] = player_id;

		func_fe6_0803CAD8(0xFF);

		Proc_Break(proc);
		return;
	}

end:
	func_fe6_0803CAD8(gPlaySt.faction);
	Proc_Break(proc);
}

void func_fe6_0803E194(void)
{
	EndAllMus();
	EndAllMus();

	func_fe6_0803CD74();
	func_fe6_0803CDD4();

	RefreshUnitSprites();
}

void func_fe6_0803E1B0(void)
{
	if ((gKeySt->pressed & KEY_BUTTON_B) != 0) {
		gSioMsgBuf.kind = SIO_MSG_14;
		gSioMsgBuf.sender = gSioSt->self_id;
		gSioMsgBuf.param = 0;
		SioSend(&gSioMsgBuf, sizeof(gSioMsgBuf));
	}
}

bool func_fe6_0803E1E8(void * data)
{
	u8 * cast = data;

	switch (cast[0]) {
	case 1:
	case 6:
	case 7:
		return TRUE;
	}

	return FALSE;
}

void func_fe6_0803E204(struct SioBattleMapProc * proc)
{
	u8 buf[4];

	u16 got = SioReceiveData(gUnk_0300140C, buf, func_fe6_0803E1E8);

	if (got != 0) {
		switch (gUnk_0300140C[0]) {
		case 1:
			func_fe6_0803CBB4(gUnk_0300140C[1], 0, &gSioBmSt.unk_04, &proc->unk_2C, &proc->unk_30);
			Proc_Goto(proc, 1);
			break;

		case 6:
			EndLinkArenaPointsBox();
			SioStrCpy(gSioTeamNames[buf[0]], gUnk_03001428);
			StartPopup(gUnk_Sio_085CA884, 0x60, 0, NULL);
			Proc_Goto(proc, 3);
			break;

		case 7:
			EndLinkArenaPointsBox();
			StartPopup(gUnk_Sio_085CA8A4, 0x60, 0, NULL);
			Proc_Goto(proc, 4);
			break;
		}
	}

	func_fe6_0803E1B0();
}

bool func_fe6_0803E2BC(void * data)
{
	u8 * cast = data;

	switch (cast[0]) {
	case 2:
	case 3:
		return TRUE;
	}

	return FALSE;
}

void func_fe6_0803E2D0(struct SioBattleMapProc * proc)
{
	struct Unit * unit;
	u8 buf[4];

	u16 got = SioReceiveData(gUnk_0300140C, buf, func_fe6_0803E2BC);

	if (got != 0) {
		switch (gUnk_0300140C[0]) {
		case 2:
			unit = GetUnit(gUnk_0300140C[2]);

			if ((unit->flags & UNIT_FLAG_CONCEALED) == 0) {
				EndMu(gUnk_03001410[0]);
			} else {
				unit->x = proc->unk_2C;
				unit->y = proc->unk_30;
			}

			unit->flags &= ~UNIT_FLAG_HIDDEN;

			RefreshUnitSprites();

			Proc_Goto(proc, 0);
			break;

		case 3:
			func_fe6_0803CBB4(gUnk_0300140C[1], 1, &gSioBmSt.unk_05, &proc->unk_34, &proc->unk_38);
			Proc_Goto(proc, 2);
			break;
		}
	}

	func_fe6_0803E1B0();
}

void func_fe6_0803E370(struct Unit * unit, int idx, int * x_out, int * y_out)
{
	gUnk_03001410[idx] = StartMu(unit);

	*x_out = unit->x;
	*y_out = unit->y;

	unit->flags &= ~UNIT_FLAG_CONCEALED;
}

bool func_fe6_0803E3B4(void * data)
{
	u8 * cast = data;

	switch (cast[0]) {
	case 4:
	case 5:
		return TRUE;
	}

	return FALSE;
}

void func_fe6_0803E3C8(struct SioBattleMapProc * proc)
{
	struct Unit * unit_a;
	struct Unit * unit_b;
	u8 buf[4];

	u16 got = SioReceiveData(gUnk_0300140C, buf, func_fe6_0803E3B4);

	if (got != 0) {
		switch (gUnk_0300140C[0]) {
		case 4:
			unit_a = GetUnit(gUnk_0300140C[2]);

			if ((unit_a->flags & UNIT_FLAG_CONCEALED) == 0) {
				EndMu(gUnk_03001410[1]);
			} else {
				unit_a->x = proc->unk_34;
				unit_a->y = proc->unk_38;
			}

			unit_a->flags &= ~UNIT_FLAG_HIDDEN;

			RefreshUnitSprites();
			Proc_Goto(proc, 1);
			break;

		case 5:
			unit_a = GetUnit(gUnk_030013F0[gSioBmSt.unk_04]);
			unit_b = GetUnit(gUnk_030013F0[gSioBmSt.unk_05]);

			if ((unit_a->flags & UNIT_FLAG_CONCEALED) != 0)
				func_fe6_0803E370(unit_a, 0, &proc->unk_2C, &proc->unk_30);

			if ((unit_b->flags & UNIT_FLAG_CONCEALED) != 0)
				func_fe6_0803E370(unit_b, 1, &proc->unk_34, &proc->unk_38);

			Proc_Break(proc);
			break;
		}
	}

	func_fe6_0803E1B0();
}

int func_fe6_0803E4AC(struct Unit * unit)
{
	int i;

	u16 best_item = 0;
	u32 best_might = 0;

	for (i = 0; i < ITEMSLOT_INV_COUNT; i++) {
		u16 item = unit->items[i];

		if (item == 0)
			break;

		if (!CanUnitUseWeapon(unit, item))
			continue;

		if (GetItemMight(item) <= best_might)
			continue;

		best_item = item;
		best_might = GetItemMight(item);
	}

	if (best_item == 0)
		return 0;

	return best_might + GetUnitPower(unit);
}

int func_fe6_0803E514(int unit_base)
{
	int i;

	int count = 0;
	int score = 0;

	for (i = unit_base; i < unit_base + 5; i++) {
		struct Unit * unit = GetUnit(i);

		if ((unit->flags & UNIT_FLAG_DEAD) != 0)
			continue;

		if (unit->pinfo == NULL)
			continue;

		count++;

		score += func_fe6_0803E4AC(unit);
		score += GetUnitCurrentHp(unit);
	}

	score += gSioBmSt.current_score[unit_base >> 6];

	score = Div(score, count);

	return score;
}

void func_fe6_0803E584(struct SioBattleMapProc * proc, int arg)
{
	if ((gKeySt->held & KEY_BUTTON_START) != 0) {
		EndLinkArenaPointsBox();
		proc->unk_58 = arg;

		if (!gPlaySt.config_se_disable) {
			m4aSongNumStart(SONG_68);
			StartEvent(gUnk_Sio_085CA93C);
		}

		Proc_Goto(proc, 3);
	}
}

void func_fe6_0803E5D0(struct SioBattleMapProc * proc)
{
	int i;

	int best_score = -1;

	func_fe6_0803E584(proc, 0);

	for (i = 0; i < 4; i++) {
		u32 score;

		if (!func_fe6_08035CB0(i))
			continue;

		if (gSioBmSt.unk_0A[i] == 0)
			continue;

		if (gPlaySt.faction == i)
			continue;

		score = func_fe6_0803E514(i * 0x40 + 1);

		if (best_score <= score)
			continue;

		best_score = score;
		gSioBmSt.unk_02 = i;
	}

	Proc_Break(proc);
}

int func_fe6_0803E630(int unused, struct Unit * unit)
{
	u16 weapon = GetUnitEquippedWeapon(unit);

	if (weapon == 0)
		return 1;

	if (GetItemMaxRange(weapon) == 1)
		return 1;

	if (GetItemMinRange(weapon) > 1)
		return 2;

	return 1;
}

void func_fe6_0803E660(struct SioBattleMapProc * proc)
{
	int faction;
	int flags;
	int best_slot;
	u32 best_score = 0;
	struct AiCombatSimulationSt sim;
	u8 selected_unit_id = 0;
	u8 target_unit_id = 0;
	int i;
	int target_faction;

	func_fe6_0803E584(proc, 1);

	gAiSt.combat_wgt_table_id = 0xE;
	faction = gPlaySt.faction * 0x40;

	for (i = faction + 1; i < faction + 6; i++) {
		int slot;
		int j;

		gActiveUnitId = i;
		gActiveUnit = GetUnit(gActiveUnitId);

		if ((gActiveUnit->flags & UNIT_FLAG_DEAD) != 0)
			continue;

		if (gActiveUnit->pinfo == NULL)
			continue;

		for (slot = 0; slot < ITEMSLOT_INV_COUNT; slot++) {
			u16 item = gActiveUnit->items[slot];

			if (item == 0)
				continue;

			if (!CanUnitUseWeapon(gActiveUnit, item))
				continue;

			best_slot = slot;
			flags = 0;

			if (GetItemMinRange(item) > 2)
				continue;

			if ((GetItemAttributes(item) & ITEM_ATTR_UNCOUNTERABLE) != 0)
				continue;

			if (GetItemMinRange(item) == 1)
				flags |= 2;

			if (GetItemMaxRange(item) > 1)
				flags |= 1;

			sim.item_slot = best_slot;

			target_faction = gSioBmSt.unk_02 * 0x40;

			for (j = target_faction + 1; j < target_faction + 6; j++) {
				struct AiCombatSimulationSt * simp = &sim;
				u8 * msg = gUnk_0300140C;
				struct Unit * unit = GetUnit(j);
				int flags2;

				if ((unit->flags & UNIT_FLAG_DEAD) != 0)
					continue;

				if (unit->pinfo == NULL)
					continue;

				flags2 = flags & 2;
				simp->target_id = j;

				if (((u8) flags2) != 0) {
					simp->x_move = unit->x + 1;
					simp->y_move = unit->y;

					AiSimulateBattleAgainstTargetAtPosition(&sim);

					if (best_score <= sim.score) {
						best_score = sim.score;
						selected_unit_id = gActiveUnitId;
						target_unit_id = j;

						if (flags == 3)
							msg[2] = func_fe6_0803E630(3, unit);
						else
							msg[2] = 1;

						msg[3] = best_slot;
					}
				}

				if ((flags & 1) != 0) {
					simp->x_move = unit->x + 1;
					simp->y_move = unit->y - 1;

					AiSimulateBattleAgainstTargetAtPosition(&sim);

					if (best_score <= sim.score) {
						best_score = sim.score;
						selected_unit_id = gActiveUnitId;
						target_unit_id = j;

						if (flags == 3)
							msg[2] = func_fe6_0803E630(3, unit);
						else
							msg[2] = 2;

						msg[3] = best_slot;
					}
				}
			}
		}
	}

	func_fe6_0803CBB4(selected_unit_id, 0, &gSioBmSt.unk_04, &proc->unk_2C, &proc->unk_30);
	gUnk_0300140C[1] = target_unit_id;

	Proc_Break(proc);
}

void func_fe6_0803E880(ProcPtr proc)
{
	struct Unit * unit = GetUnit(gUnk_0300140C[1]);

	AiStartActionCursor(unit->x * 16, unit->y * 16, 2, proc);
}

void func_fe6_0803E8B0(struct SioBattleMapProc * proc)
{
	struct Unit * unit_a;
	struct Unit * unit_b;

	func_fe6_0803CBB4(gUnk_0300140C[1], 1, &gSioBmSt.unk_05, &proc->unk_34, &proc->unk_38);

	unit_a = GetUnit(gUnk_030013F0[gSioBmSt.unk_04]);
	unit_b = GetUnit(gUnk_030013F0[gSioBmSt.unk_05]);

	if ((unit_a->flags & UNIT_FLAG_CONCEALED) != 0)
		func_fe6_0803E370(unit_a, 0, &proc->unk_2C, &proc->unk_30);

	if ((unit_b->flags & UNIT_FLAG_CONCEALED) != 0)
		func_fe6_0803E370(unit_b, 1, &proc->unk_34, &proc->unk_38);
}

void func_fe6_0803E944(struct SioBattleMapProc * proc)
{
	func_fe6_0803E584(proc, 2);

	if (!MuExistsActive())
		Proc_Break(proc);
}

void func_fe6_0803E964(void)
{
	int i, j;

	int y_offset = (gUnk_Sio_085CA8B4[GetGameTime() & 0x1F] + 4) >> 1;

	for (i = 0; i < 4; i++) {
		if (!func_fe6_08035CB0(gUnk_Sio_0810F390[gSioSt->self_id][i]))
			continue;

		for (j = 0; j < 5; j++) {
			struct Unit * unit = GetUnit(gUnk_030013F0[i * 5 + j]);

			if (unit == NULL || unit->pinfo == NULL)
				continue;

			if (!(unit->flags & UNIT_FLAG_CONCEALED))
				continue;

			PutOamHiRam(unit->x * 16, unit->y * 16 - y_offset, Sprite_16x16,
				OAM2_PAL(GetUnitDisplayedSpritePalette(unit)) + OAM2_CHR(0x240) + OAM2_LAYER(2));
		}
	}
}

void func_fe6_0803EA30(void)
{
	SpawnProc(gUnk_Sio_085CA8D4, PROC_TREE_4);
}

void func_fe6_0803EA44(void)
{
	Proc_EndEach(gUnk_Sio_085CA8D4);
}

void func_fe6_0803EA54(ProcPtr proc)
{
	SetStatScreenExcludedUnitFlags(UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED | UNIT_FLAG_UNDER_ROOF | UNIT_FLAG_CONCEALED);
	StartStatScreen(gActiveUnit, proc);
}

void func_fe6_0803EA74(ProcPtr proc)
{
	if (gSioBmSt.unk_08 == 0) {
		Proc_Goto(proc, 0);
		return;
	}

	EndAllMus();
	func_fe6_0803CB3C(6, gPlaySt.faction, 0, 0);
}

void func_fe6_0803EAAC(ProcPtr proc)
{
	if (gSioBmSt.unk_08 == 0) {
		gSioBmSt.unk_09 = 0;
		Proc_Goto(proc, 0);
		return;
	}

	EndAllMus();
	func_fe6_0803CB3C(7, gPlaySt.faction, 0, 0);
}

void func_fe6_0803EAE0(struct SioBattleMapProc * proc)
{
	if (gSioBmSt.unk_08 == 0) {
		Proc_Goto(proc, proc->unk_58);
		return;
	}

	EndAllMus();
	EndAllMus();

	gLinkArenaSt.unk_0B = 1;

	func_fe6_0803CAD8(0xFF);

	Proc_Goto(proc, 5);
}

void func_fe6_0803EB24(struct SioBattleMapProc * proc)
{
	int i;
	int last = 0;

	if (gLinkArenaSt.unk_00 == 1) {
		gLinkArenaSt.unk_0B = 1;
		func_fe6_0803CAD8(0xFF);
		Proc_Goto(proc, 8);
		return;
	}

	gSioBmSt.unk_0F[gLinkArenaSt.unk_A0 - gSioBmSt.unk_0E] = gPlaySt.faction;
	gSioBmSt.unk_0E++;

	gSioBmSt.current_score[gPlaySt.faction] = 0;

	if (gSioBmSt.unk_0E == gLinkArenaSt.unk_A0) {
		for (i = 0; i < gLinkArenaSt.unk_A0; i++) {
			if (gSioBmSt.unk_0A[i] != 0)
				last = i;
		}

		gSioBmSt.unk_0F[0] = last;

		func_fe6_0803CAD8(0xFF);
		Proc_Goto(proc, 8);
		return;
	}

	func_fe6_0803CAD8(gPlaySt.faction);
	Proc_Goto(proc, 8);
}

void func_fe6_0803EBBC(ProcPtr proc)
{
	if (gLinkArenaSt.unk_00 == 1) {
		gLinkArenaSt.unk_0B = 1;
		func_fe6_0803CAD8(0xFF);
		Proc_Goto(proc, 8);
		return;
	}

	gLinkArenaSt.unk_0B = 2;
	func_fe6_0803CAD8(0xFF);
	Proc_Goto(proc, 8);
}

void func_fe6_0803EBF8(struct SioBattleMapProc * proc)
{
	int i;
	int last = 0;

	gSioBmSt.unk_0F[gLinkArenaSt.unk_A0 - gSioBmSt.unk_0E] = gPlaySt.faction;
	gSioBmSt.unk_0E++;

	gSioBmSt.current_score[gPlaySt.faction] = 0;

	if (gSioBmSt.unk_0E == gLinkArenaSt.unk_A0) {
		for (i = 0; i < gLinkArenaSt.unk_A0; i++) {
			if (gSioBmSt.unk_0A[i] != 0)
				last = i;
		}

		gSioBmSt.unk_0F[0] = last;

		func_fe6_0803CAD8(0xFF);
		Proc_Goto(proc, 5);
		return;
	}

	func_fe6_0803CAD8(gPlaySt.faction);
	Proc_Goto(proc, 5);
}

void func_fe6_0803EC84(ProcPtr proc)
{
	gLinkArenaSt.unk_0B = 2;
	func_fe6_0803CAD8(0xFF);
	Proc_Goto(proc, 5);
}

void func_fe6_0803ECA8(struct SioBattleMapProc * proc)
{
	proc->unk_58 = 0;

	proc->unk_5C = gPlaySt.faction * 0x40;
	gSioBmSt.unk_0A[gPlaySt.faction] = 0;
}

void func_fe6_0803ECD0(struct SioBattleMapProc * proc)
{
	struct Unit * unit;
	struct MuProc * mu;

retry:
	if (proc->unk_58 == 5) {
		Proc_Goto(proc, 1);
		return;
	}

	unit = GetUnit(proc->unk_5C + proc->unk_58 + 1);

	if ((unit->flags & UNIT_FLAG_DEAD) != 0 || unit->pinfo == NULL) {
		proc->unk_58++;
		goto retry;
	}

	RefreshUnitSprites();
	HideUnitSprite(unit);

	mu = StartMu(unit);

	gWorkingMoveScr[0] = MOVE_CMD_MOVE_DOWN;
	gWorkingMoveScr[1] = MOVE_CMD_HALT;

	SetMuMoveScript(mu, gWorkingMoveScr);

	func_fe6_0803F5C8(mu);

	proc->unk_54 = mu;
	proc->unk_58++;

	unit->flags &= ~UNIT_FLAG_CONCEALED;
	unit->flags |= (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD);
}

void func_fe6_0803ED54(struct SioBattleMapProc * proc)
{
	EndMu(proc->unk_54);
}

void func_fe6_0803ED60(void)
{
	func_fe6_0803CD74();
	func_fe6_0803CDD4();

	RefreshUnitSprites();
}

void func_fe6_0803ED74(void)
{
	if (GetTalkChoiceResult() == TALK_CHOICE_YES) {
		gSioBmSt.unk_08 = 1;
		return;
	}

	gSioBmSt.unk_08 = 0;
}

void func_fe6_0803ED9C(struct SioBattleMapProc * proc)
{
	int i;

	LoadHelpBoxGfx((void *) 0x06015000, 6);
	StartSimpleHelpBox(64, 56, MSG_6E5);

	for (i = 0; i < 4; i++) {
		if (!func_fe6_08035CB0(i))
			continue;

		if (gSioBmSt.unk_0A[i] == 0)
			continue;

		proc->unk_58 = i;
	}

	proc->unk_5C = 0;
}

void func_fe6_0803EDEC(struct SioBattleMapProc * proc)
{
	struct Unit * unit;

	while (TRUE) {
		if (proc->unk_5C > 4) {
			CloseHelpBox();
			Proc_Break(proc);
			return;
		}

		unit = GetUnit(proc->unk_58 * 0x40 + proc->unk_5C + 1);

		if ((unit->flags & UNIT_FLAG_DEAD) != 0) {
			proc->unk_5C++;
			continue;
		}

		if (unit->pinfo == NULL) {
			proc->unk_5C++;
			continue;
		}

		break;
	}

	gSioBmSt.unk_2C[proc->unk_58].new_score = 30;
	gSioBmSt.unk_2C[proc->unk_58].unit_id = proc->unk_58 * 0x40 + proc->unk_5C + 1;

	StartSioPoints2(proc);

	proc->unk_5C++;
}

void func_fe6_0803EE60(ProcPtr proc)
{
	if (gLinkArenaSt.unk_00 == 1)
		Proc_Goto(proc, 1);
}

void func_fe6_0803EE7C(void)
{
	TmFill(gBg2Tm, 0);
	EnableBgSync(BG2_SYNC_BIT);

	RenderMap();

	if (SetupBanim()) {
		SetBanimLinkArenaFlag(1);
		BeginAnimsOnBattleAnimations();
		return;
	}

	EndAllMus();
	RenderMap();

	StartBattleManim();
	gBattleSt.flags |= BATTLE_FLAG_MAPANIMS;
}

void func_fe6_0803EECC(struct SioBattleMapProc * proc)
{
	struct MuProc * mu;

	if (gBattleUnitA.unit.hp == 0) {
		mu = FindProc(ProcScr_Mu);
		func_fe6_0803F5C8(mu);
		proc->unk_54 = mu;
	}

	if (gBattleUnitB.unit.hp == 0) {
		RefreshUnitSprites();

		HideUnitSprite(GetUnit(gBattleUnitB.unit.id));

		mu = StartMu(&gBattleUnitB.unit);

		gWorkingMoveScr[0] = GetFacingFromTo(
			gBattleUnitA.unit.x, gBattleUnitA.unit.y, gBattleUnitB.unit.x, gBattleUnitB.unit.y);
		gWorkingMoveScr[1] = MOVE_CMD_HALT;

		SetMuMoveScript(mu, gWorkingMoveScr);
		func_fe6_0803F5C8(mu);

		proc->unk_54 = mu;
	}
}

void func_fe6_0803EF4C(void)
{
	struct Unit * unit_a = GetUnit(gBattleUnitA.unit.id);
	struct Unit * unit_b = GetUnit(gBattleUnitB.unit.id);

	if (GetUnitCurrentHp(unit_a) == 0)
		unit_a->flags |= (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD);

	if (GetUnitCurrentHp(unit_b) == 0)
		unit_b->flags |= (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD);
}

void func_fe6_0803EF9C(void)
{
	Unk_Sio_0203C9D0 = 1;
}

void func_fe6_0803EFA8(void)
{
	Unk_Sio_0203C9D0 = 0;
}

void func_fe6_0803EFB4(void)
{
	SetWinEnable(0, 0, 0);
	SetBlendConfig(0, 0, 0, 0);
}

void func_fe6_0803EFEC(void)
{
	u16 vcount = REG_VCOUNT + 1;

	if (vcount > DISPLAY_HEIGHT) {
		gUnk_Sio_02001528 = gUnk_Sio_02001520;
		vcount = 0;
	}

	REG_WIN1H = (gUnk_Sio_02001528[vcount * 2 + 0] << 8) + gUnk_Sio_02001528[vcount * 2 + 1];
}

void func_fe6_0803F028(void)
{
	i16 * swap = gUnk_Sio_02001520;
	gUnk_Sio_02001520 = gUnk_Sio_02001524;
	gUnk_Sio_02001524 = swap;
}

void func_fe6_0803F040(void)
{
	SetWinEnable(0, 0, 0);
	SetOnHBlankA(NULL);
}

void func_fe6_0803F068(i16 * buf, int x_a, int y_a, int x_b, int y_b, int x_c, int y_c, int x_d, int y_d, i16 angle, u16 scale)
{
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x4, y4;

	x_a -= DISPLAY_WIDTH / 2;
	y_a -= DISPLAY_HEIGHT / 2;

	x_b -= DISPLAY_WIDTH / 2;
	y_b -= DISPLAY_HEIGHT / 2;

	x_c -= DISPLAY_WIDTH / 2;
	y_c -= DISPLAY_HEIGHT / 2;

	x_d -= DISPLAY_WIDTH / 2;
	y_d -= DISPLAY_HEIGHT / 2;

	x1 = (x_a * SIN_Q12(angle)) + (y_a * COS_Q12(angle));
	y1 = (x_a * COS_Q12(angle)) - (y_a * SIN_Q12(angle));

	x2 = (x_b * SIN_Q12(angle)) + (y_b * COS_Q12(angle));
	y2 = (x_b * COS_Q12(angle)) - (y_b * SIN_Q12(angle));

	x3 = (x_c * SIN_Q12(angle)) + (y_c * COS_Q12(angle));
	y3 = (x_c * COS_Q12(angle)) - (y_c * SIN_Q12(angle));

	x4 = (x_d * SIN_Q12(angle)) + (y_d * COS_Q12(angle));
	y4 = (x_d * COS_Q12(angle)) - (y_d * SIN_Q12(angle));

	x1 = ((scale * (x1 >> 12)) >> 8) + DISPLAY_WIDTH / 2;
	y1 = ((scale * (y1 >> 12)) >> 8) + DISPLAY_HEIGHT / 2;

	x2 = ((scale * (x2 >> 12)) >> 8) + DISPLAY_WIDTH / 2;
	y2 = ((scale * (y2 >> 12)) >> 8) + DISPLAY_HEIGHT / 2;

	x3 = ((scale * (x3 >> 12)) >> 8) + DISPLAY_WIDTH / 2;
	y3 = ((scale * (y3 >> 12)) >> 8) + DISPLAY_HEIGHT / 2;

	x4 = ((scale * (x4 >> 12)) >> 8) + DISPLAY_WIDTH / 2;
	y4 = ((scale * (y4 >> 12)) >> 8) + DISPLAY_HEIGHT / 2;

	func_fe6_08013F04(buf, x1, y1, x2, y2);
	func_fe6_08013F04(buf, x2, y2, x3, y3);
	func_fe6_08013F04(buf, x3, y3, x4, y4);
	func_fe6_08013F04(buf, x4, y4, x1, y1);
}

void func_fe6_0803F1D8(struct SioWarpWindowProc * proc)
{
	gUnk_Sio_02001520 = gUnk_Sio_020012A0;

	gUnk_Sio_02001524 = gUnk_Sio_020012A0 - 320;
	gUnk_Sio_02001528 = gUnk_Sio_020012A0;

	func_fe6_08013EE4(gUnk_Sio_02001520);
	func_fe6_08013EE4(gUnk_Sio_02001524);

	proc->clock = 0;

	SetOnHBlankA(func_fe6_0803EFEC);
}

void func_fe6_0803F224(struct SioWarpWindowProc * proc)
{
	int angle, scale;

	if (proc->clock == proc->duration) {
		SetOnHBlankA(NULL);
		Proc_Break(proc);
		return;
	}

	angle = Interpolate(INTERPOLATE_LINEAR, 0xA0, 0xC0, proc->clock, proc->duration);
	scale = Interpolate(INTERPOLATE_SQUARE, 0x10, 0x110, proc->clock, proc->duration);

	func_fe6_08013EE4(gUnk_Sio_02001524);
	func_fe6_0803F068(gUnk_Sio_02001524, 0, 0, DISPLAY_WIDTH, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0, DISPLAY_HEIGHT, angle, scale);
	func_fe6_0803F028();

	proc->clock++;
}

void func_fe6_0803F2BC(void)
{
	SetDispEnable(1, 1, 1, 1, 1);
	SetWinEnable(0, 0, 0);

	SetWin1Box(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);
}

void func_fe6_0803F304(u16 duration, ProcPtr parent)
{
	struct SioWarpWindowProc * proc = SpawnProcLocking(gUnk_Sio_085CADFC, parent);
	proc->duration = duration;

	SetDispEnable(1, 1, 1, 1, 1);
	SetWinEnable(0, 1, 0);

	SetWin1Box(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);

	SetWin1Layers(1, 1, 1, 1, 1);
	SetWOutLayers(0, 0, 0, 0, 0);

	gDispIo.win_ct.win1_enable_blend = 1;
}

void func_fe6_0803F3AC(ProcPtr parent)
{
	func_fe6_0803F304(0x40, parent);
}

void func_fe6_0803F3BC(struct SioWarpWindowProc * proc)
{
	int angle, scale;

	if (proc->clock == proc->duration) {
		SetOnHBlankA(NULL);
		Proc_Break(proc);
		return;
	}

	angle = Interpolate(INTERPOLATE_RSQUARE, 0xC0, 0xA0, proc->clock, proc->duration);
	scale = Interpolate(INTERPOLATE_RCUBIC, 0x110, 0x10, proc->clock, proc->duration);

	func_fe6_08013EE4(gUnk_Sio_02001524);
	func_fe6_0803F068(gUnk_Sio_02001524, 0, 0, DISPLAY_WIDTH, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0, DISPLAY_HEIGHT, angle, scale);
	func_fe6_0803F028();

	proc->clock++;
}

void func_fe6_0803F454(void)
{
	SetDispEnable(0, 0, 0, 0, 0);
	SetWinEnable(0, 0, 0);

	SetWin1Box(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);
}

void func_fe6_0803F478(u16 duration, ProcPtr parent)
{
	struct SioWarpWindowProc * proc = SpawnProcLocking(gUnk_Sio_085CAE34, parent);
	proc->duration = duration;

	SetWinEnable(0, 1, 0);

	SetWin1Box(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);

	SetWin1Layers(1, 1, 1, 1, 1);
	SetWOutLayers(0, 0, 0, 0, 0);

	gDispIo.win_ct.win1_enable_blend = 1;
}

void func_fe6_0803F504(ProcPtr parent)
{
	func_fe6_0803F478(0x40, parent);
}

void func_fe6_0803F514(ProcPtr proc)
{
	if (FindProc(gUnk_Sio_085CADFC) == NULL)
		Proc_Break(proc);
}

void func_fe6_0803F534(ProcPtr proc)
{
	if (FindProc(gUnk_Sio_085CAE34) == NULL)
		Proc_Break(proc);
}

void func_fe6_0803F554(struct MuProc * mu, int kind)
{
	struct SioMuProc * proc;

	ApplyPalette(gUnk_Sio_085CAE6C[kind], 0x16);

	mu->sprite_anim->oam2 = mu->config->chr + 0x6800;
	StartPalFade(gPal + (mu->config->pal + 0x10) * 0x10, 0x16, 0x14, mu);

	proc = SpawnProc(gUnk_Sio_085CAE84, mu);
	proc->mu = mu;
}

void func_fe6_0803F5AC(struct SioMuProc * proc)
{
	proc->mu->sprite_anim->oam2 = OAM2_PAL(proc->mu->config->pal) + proc->mu->config->chr + 0x800;
}

void func_fe6_0803F5C8(struct MuProc * mu)
{
	struct Proc * proc;

	mu->state = MU_STATE_DEATHFADE;

	proc = SpawnProc(ProcScr_MuDeathFade, mu);
	proc->ptr = mu;
	proc->timer1 = 32;

	SetBlendConfig(0, proc->timer1 >> 1, 0x10, 0);

	mu->sprite_anim->clock = 0;
	mu->sprite_anim->clock_interval_q8 = 0;

	func_fe6_0803F554(mu, 0);

	mu->sprite_anim->layer = 13;

	PlaySe(SONG_D6);
}

void func_fe6_0803F648(struct MuProc * mu, int kind)
{
	mu->sprite_anim->oam2 = mu->config->chr + 0x6800;

	ApplyPalette(gPal + (mu->config->pal + 0x10) * 0x10, 0x16);
	StartPalFade(gUnk_Sio_085CAE6C[kind], 0x16, 8, mu);
}

void func_fe6_0803F694(struct MuProc * mu)
{
	struct Proc * proc;

	StartPalFade(gPal + (mu->config->pal + 0x10) * 0x10, 0x16, 8, mu);

	proc = SpawnProc(ProcScr_MuRestorePalInfo, PROC_TREE_3);
	proc->ptr = mu;
}

void func_fe6_0803F6C8(struct SioWarpProc * proc)
{
	Decompress(Img_ManimWarp, (void *) 0x06004400);
	ApplyPalette(Pal_ManimWarp, 3);

	proc->clock = 0;

	if (proc->play_step_se)
		StartPlayMuStepSe(0x7F, 2, proc->x * 8);
}

void func_fe6_0803F714(struct SioWarpProc * proc)
{
	func_fe6_08014F70(gBg2Tm, proc->x - 1, proc->y - 3, 0x3220, 4, 6, TsaRef_ManimWarp, gUnk_Sio_085CAE9C[proc->clock]);

	EnableBgSync(BG2_SYNC_BIT);

	proc->clock++;

	if (gUnk_Sio_085CAE9C[proc->clock] == 0xFF)
		Proc_Break(proc);

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 0;
	gDispIo.bg2_ct.priority = 0;
	gDispIo.bg3_ct.priority = 3;

	SetBlendTargetA(0, 0, 1, 0, 0);
	SetBlendTargetB(1, 1, 0, 1, 1);

	SetBlendAlpha(12, 12);
}

void func_fe6_0803F7E4(void)
{
	TmFill(gBg2Tm, 0);
	EnableBgSync(BG2_SYNC_BIT);

	SetBlendNone();
}

void NewSioWarp(struct SioWarpProc * parent)
{
	struct SioWarpProc * proc = SpawnProc(ProcScr_SIOWARP, PROC_TREE_2);

	proc->x = parent->unit->x * 2;
	proc->y = parent->unit->y * 2;

	proc->play_step_se = parent->play_step_se;
}

void SioWarpFx_0803F850(struct SioWarpProc * proc)
{
	func_fe6_0803F648(proc->mu, 0);
}

void SioWarpFx_HideMoveUnit(struct SioWarpProc * proc)
{
	HideMu(proc->mu);
}

void SioWarpFx_SetMUPosition(struct SioWarpProc * proc)
{
	SetMuScreenPosition(proc->mu, proc->x * 16, proc->y * 16);

	proc->unit->x = proc->x;
	proc->unit->y = proc->y;
}

void SioWarpFx_ShowMoveUnit(struct SioWarpProc * proc)
{
	if (proc->facing != -1)
		SetMuFacing(proc->mu, proc->facing);

	ShowMu(proc->mu);
}

void SioWarpFx_0803F8B0(struct SioWarpProc * proc)
{
	func_fe6_0803F694(proc->mu);
}

void SioWarpFx_AwaitSioWarp(ProcPtr proc)
{
	i8 found = FindProc(ProcScr_SIOWARP) != NULL;

	if (!found)
		Proc_Break(proc);
}

ProcPtr NewSioWarpFx(struct Unit * unit, struct MuProc * mu, int x, int y, int facing, u8 play_step_se, ProcPtr parent)
{
	struct SioWarpProc * proc;

	if (parent != NULL)
		proc = SpawnProcLocking(ProcScr_SIOWARPFX, parent);
	else
		proc = SpawnProc(ProcScr_SIOWARPFX, PROC_TREE_2);

	proc->unit = unit;
	proc->mu = mu;
	proc->x = x;
	proc->y = y;
	proc->facing = facing;
	proc->play_step_se = play_step_se;

	return proc;
}

ProcPtr NewSioWarpFxPartial(struct Unit * unit, struct MuProc * mu, int x, int y, int facing, u8 play_step_se, ProcPtr parent)
{
	struct SioWarpProc * proc;

	if (parent != NULL)
		proc = SpawnProcLocking(ProcScr_SioWarpFxPartial, parent);
	else
		proc = SpawnProc(ProcScr_SioWarpFxPartial, PROC_TREE_2);

	proc->unit = unit;
	proc->mu = mu;
	proc->x = x;
	proc->y = y;
	proc->facing = facing;
	proc->play_step_se = play_step_se;

	return proc;
}

u16 const Sprite_LinkArenaBButton[] = {
	2,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x2DA) + OAM2_LAYER(1) + OAM2_PAL(8),
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16 + OAM1_X(32), OAM2_CHR(0x2DE) + OAM2_LAYER(1) + OAM2_PAL(8),
};

void PutLinkArenaButtonSpriteAt(int x, int y)
{
	PutSprite(4, x, y, Sprite_LinkArenaBButton, 0);
}

void LAButtonSprites_Loop(struct SioSpriteDrawProc * proc)
{
	PutLinkArenaButtonSpriteAt(proc->x, proc->y);
}

void StartLinkArenaButtonSpriteDraw(int x, int y, ProcPtr parent)
{
	struct SioSpriteDrawProc * proc;

	Proc_EndEach(ProcScr_LAButtonSpriteDraw);
	proc = SpawnProc(ProcScr_LAButtonSpriteDraw, parent);

	proc->x = x;
	proc->y = y;
}

void EndLinkArenaButtonSpriteDraw(void)
{
	if (FindProc(ProcScr_LAButtonSpriteDraw))
		Proc_EndEach(ProcScr_LAButtonSpriteDraw);
}

void InitSioBG(void)
{
	u16 bg_config[] = {
		0x0000, 0x6000, 0x0000,
		0x0000, 0x6800, 0x0000,
		0x0000, 0x7000, 0x0000,
		0x8000, 0x7800, 0x0000,
	};

	InitBgs(bg_config);

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 1;
	gDispIo.bg2_ct.priority = 2;
	gDispIo.bg3_ct.priority = 3;

	ApplySystemGraphics();

	ApplyPalettes(Pal_LinkArenaRankIcons, 0x18, 2);

	Decompress(Img_MuralBackground, (void *) VRAM + GetBgChrOffset(3));
	ApplyPalettes(Pal_LinkArenaMuralBackground, 0xE, 2);
}

void Sio_RestartBgSlide(ProcPtr parent, int lines)
{
	int i;
	u16 * tm = gBg3Tm;

	Proc_EndEach(ProcScr_BackgroundSlide);

	for (i = 0; i < (20 - lines) * 32; i++)
		*tm++ = i + TILEREF(0, 0xE);

	for (i = 0; i < lines * 32; i++)
		*tm++ = i + TILEREF(0, 0xF);

	SpawnProc(ProcScr_BackgroundSlide, parent);
}

void func_fe6_0803FB08(ProcPtr parent)
{
	int i;

	u16 pal_lut[] = {
		0xE, 0xE, 0xE, 0xE, 0xE, 0xF, 0xF, 0xF, 0xF, 0xF,
		0xF, 0xF, 0xF, 0xF, 0xF, 0xE, 0xE, 0xE, 0xF, 0xF,
	};

	u16 * tm = gBg3Tm;

	Proc_EndEach(ProcScr_BackgroundSlide);

	for (i = 0; i < 0x280; i++)
		*tm++ = i + TILE_PAL_SAFE(pal_lut[i / 32]);

	SpawnProc(ProcScr_BackgroundSlide, parent);
}

void Sio_EndBackgroundSlide(void)
{
	Proc_EndEach(ProcScr_BackgroundSlide);
}

void SioCopyVRAM(u8 const * src, u8 * dst, int width, int height)
{
	int i;

	int size = width << 5;

	for (i = 0; i < height; i++) {
		CpuFastCopy(src, dst, size);
		src += 0x400;
		dst += 0x400;
	}
}

void func_fe6_0803FBC4(struct LinkArenaTitleBannerProc * proc)
{
	int x = proc->kind & 3;
	int y = proc->kind / 4;

	Decompress(gUnk_08106784, gBuf);
	SioCopyVRAM(gBuf + (x * 0x100 + y * 0x800), (void *) 0x06014000, 8, 2);

	TmApplyTsa(gBg2Tm, gUnk_08109D78, TILEREF(0, 1));
	EnableBgSync(BG2_SYNC_BIT);
}

u16 const Sprite_Sio_0810F482[] = {
	2,
	OAM0_SHAPE_64x32, OAM1_SIZE_64x32, OAM2_CHR(0x240),
	OAM0_SHAPE_16x32, OAM1_SIZE_16x32 + OAM1_X(64), OAM2_CHR(0x248),
};

u16 const Sprite_Sio_0810F490[] = {
	2,
	OAM0_SHAPE_64x32, OAM1_SIZE_64x32, OAM2_CHR(0x2CA),
	OAM0_SHAPE_16x32, OAM1_SIZE_16x32 + OAM1_X(64), OAM2_CHR(0x2D2),
};

u16 const Sprite_Sio_0810F49E[] = {
	2,
	OAM0_SHAPE_64x32, OAM1_SIZE_64x32, OAM2_CHR(0x2C0),
	OAM0_SHAPE_16x32, OAM1_SIZE_16x32 + OAM1_X(64), OAM2_CHR(0x2C8),
};

u16 const Sprite_Sio_0810F4AC[] = {
	2,
	OAM0_SHAPE_64x32, OAM1_SIZE_64x32, OAM2_CHR(0x24A),
	OAM0_SHAPE_16x32, OAM1_SIZE_16x32 + OAM1_X(64), OAM2_CHR(0x252),
};

u16 const Sprite_Sio_0810F4BA[] = {
	2,
	OAM0_SHAPE_64x32, OAM1_SIZE_64x32, OAM2_CHR(0x254),
	OAM0_SHAPE_16x32, OAM1_SIZE_16x32 + OAM1_X(64), OAM2_CHR(0x25C),
};

void func_fe6_0803FC1C(void)
{
	PutSpriteExt(4, 40, 8, gUnk_Sio_085CAFB4, 0);
}

void StartLinkArenaTitleBanner(ProcPtr parent, int kind)
{
	struct LinkArenaTitleBannerProc * proc;

	Proc_EndEach(gUnk_Sio_085CAFC4);
	proc = SpawnProc(gUnk_Sio_085CAFC4, parent);

	proc->kind = kind;
}

void func_fe6_0803FC60(void)
{
	Proc_EndEach(gUnk_Sio_085CAFC4);
}

void func_fe6_0803FC70(void)
{
	SetBlendAlpha(8, 15);

	SetBlendTargetA(0, 0, 0, 0, 0);
	SetBlendTargetB(0, 0, 0, 1, 0);
}

void func_fe6_0803FCBC(struct SioScrollingTextProc * proc)
{
	int oam2 = OAM2_CHR(0x208) + OAM2_LAYER(3) + OAM2_PAL(7);
	int i;

	int x = (proc->x + proc->x_cur) >> 1;
	int y = (proc->y + proc->y_cur) >> 1;

	proc->x_cur = x;
	proc->y_cur = y;

	for (i = 0; i < 32; i++) {
		int chr = (proc->clock / 8 + i) % proc->count;
		PutSprite(12, x + i * 8 - (proc->clock & 7), y, gUnk_Sio_085CAFE4, chr + oam2);
	}

	proc->clock++;

	if (proc->clock == proc->count * 8)
		proc->clock = 0;
}

void func_fe6_0803FD40(u8 const * chars, int count, int x, int y, int pal, ProcPtr parent)
{
	int i;
	struct SioScrollingTextProc * proc;

	Decompress(gUnk_081065C8, gBuf);

	for (i = 0; i < count; i++)
		SioCopyVRAM(gBuf + chars[i % count] * CHR_SIZE, (void *) 0x06014100 + i * CHR_SIZE, 1, 2);

	ApplyPalette(gUnk_08109B00 + pal * 0x10, 0x17);

	Proc_EndEach(gUnk_Sio_085CAFEC);
	proc = SpawnProc(gUnk_Sio_085CAFEC, parent);

	proc->x = x;
	proc->x_cur = x;
	proc->y = y;
	proc->y_cur = y;
	proc->count = count;
	proc->clock = 0;
}

void func_fe6_0803FDD8(void)
{
	SetBlendConfig(0, 0, 0, 0);
	Proc_EndEach(gUnk_Sio_085CAFEC);
}

void func_fe6_0803FE0C(int x, int y)
{
	struct SioScrollingTextProc * proc = FindProc(gUnk_Sio_085CAFEC);

	proc->x = x;
	proc->y = y;
}

void func_fe6_0803FE28(int x, int y)
{
	struct SioScrollingTextProc * proc = FindProc(gUnk_Sio_085CAFEC);

	proc->x_cur = x;
	proc->x = x;
	proc->y_cur = y;
	proc->y = y;
}

void func_fe6_0803FE48(int pal)
{
	ApplyPalette(gUnk_08109B00 + pal * 0x10, 0x17);
}

u16 const gUnk_Sio_0810F4C8[] = {
	OAM2_LAYER(1) + OAM2_PAL(5),
	OAM2_LAYER(1) + OAM2_PAL(4),
	OAM2_PAL(3),
};

u16 const Sprite_Sio_0810F4CE[] = {
	3,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x318) + OAM2_PAL(8),
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16 + OAM1_X(8), OAM2_CHR(0x319) + OAM2_PAL(8),
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(16), OAM2_CHR(0x31A) + OAM2_PAL(8),
};

u16 const Sprite_Sio_0810F4E2[] = {
	3,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x318) + OAM2_PAL(8),
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16 + OAM1_X(8), OAM2_CHR(0x31E) + OAM2_PAL(8),
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(16), OAM2_CHR(0x31A) + OAM2_PAL(8),
};

u16 const Sprite_Sio_0810F4F6[] = {
	3,
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x318) + OAM2_PAL(8),
	OAM0_SHAPE_8x16, OAM1_SIZE_8x16 + OAM1_X(8), OAM2_CHR(0x31F) + OAM2_PAL(8),
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(16), OAM2_CHR(0x31A) + OAM2_PAL(8),
};

void func_fe6_0803FE64(u8 idx)
{
	u8 lut[] = {
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
		0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08,
		0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00,
	};

	if (Unk_Sio_0203C9D0 == 0) {
		int color = lut[idx] + 0x10;
		PAL_COLOR(0x13, 14) = (color << 10) + (color << 5) + color;
		EnablePalSync();
	}
}

void func_fe6_0803FEB4(struct SioMenuItemProc * proc)
{
	int oam2 = OAM2_CHR(0x2DA) + OAM2_PAL(8);

	PutSprite(4, proc->x_base, proc->y_base, gUnk_Sio_085CB00C[proc->index], gUnk_Sio_0810F4C8[proc->state]);

	if (proc->state == 2)
		func_fe6_0803FE64(proc->glow_frame);

	proc->glow_frame = (proc->glow_frame + 1) & 31;

	if (proc->state == 2 && proc->index == 1) {
		proc->left_arrow_clock += proc->left_arrow_speed;
		proc->right_arrow_clock += proc->right_arrow_speed;

		if (proc->left_arrow_speed > 4)
			proc->left_arrow_speed--;

		if (proc->right_arrow_speed > 4)
			proc->right_arrow_speed--;

		if ((GetGameTime() & 3) == 0) {
			if (proc->x_left_arrow < 0)
				proc->x_left_arrow++;

			if (proc->x_right_arrow > 52)
				proc->x_right_arrow--;
		}

		PutSprite(4, 59 + proc->x_base + proc->x_left_arrow, proc->y_base + 8, Sprite_8x16,
			((proc->left_arrow_clock >> 5) % 6) + oam2);
		PutSprite(4, 59 + proc->x_base + proc->x_right_arrow, proc->y_base + 8, Sprite_8x16_HFlipped,
			((proc->right_arrow_clock >> 5) % 6) + oam2);

		PutSpriteExt(4, 64 + proc->x_base, proc->y_base + 8, gUnk_Sio_085CB020[gLinkArenaSt.unk_05], 0);
	}
}

struct SioMenuItemProc * func_fe6_08040014(ProcPtr parent, u8 x, u8 y, u8 index, u8 state)
{
	struct SioMenuItemProc * proc = SpawnProc(gUnk_Sio_085CB02C, parent);

	proc->x_base = x;
	proc->y_base = y;
	proc->state = state;
	proc->index = index;
	proc->x_left_arrow = 0;
	proc->x_right_arrow = 52;
	proc->right_arrow_clock = 0;
	proc->left_arrow_clock = 0;
	proc->right_arrow_speed = 4;
	proc->left_arrow_speed = 4;
	proc->unk_3E = 0;
	proc->glow_frame = 0;

	return proc;
}

void func_fe6_08040084(struct SioMenuItemProc * proc, int x_left, int x_right, int left_speed, int right_speed)
{
	proc->x_left_arrow = x_left;
	proc->x_right_arrow = x_right;
	proc->left_arrow_speed = left_speed;
	proc->right_arrow_speed = right_speed;
}

void func_fe6_08040098(struct SioMenuItemProc * proc, i16 x, i16 y)
{
	proc->x_base = x;
	proc->y_base = y;
}

void func_fe6_080400A0(void)
{
	u16 const * pal = gUnk_08109BC0;

	u8 lut[] = {
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
		0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08,
		0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00,
	};

	if (Unk_Sio_0203C9D0 == 0) {
		int clock = GetGameTime() % 0x40;
		int idx = lut[clock / 2];

		PAL_COLOR(0x19, 15) = pal[idx];
		EnablePalSync();
	}
}

void func_fe6_080400FC(void)
{
	u16 const * pal = gUnk_08109C20;

	u8 lut[] = {
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
		0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08,
		0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00,
	};

	if (Unk_Sio_0203C9D0 == 0) {
		int clock = GetGameTime() % 0x40;
		int idx = lut[clock / 2];

		PAL_COLOR(0x13, 14) = pal[idx];
		EnablePalSync();
	}
}

u16 const Sprite_LinkArena_NAMEBANNER[] = {
	4,
	OAM0_SHAPE_16x32, OAM1_SIZE_16x32, OAM2_CHR(0x240) + OAM2_PAL(3),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(16), OAM2_CHR(0x243) + OAM2_PAL(3),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(48), OAM2_CHR(0x243) + OAM2_PAL(3),
	OAM0_SHAPE_16x32, OAM1_SIZE_16x32 + OAM1_X(80), OAM2_CHR(0x247) + OAM2_PAL(3),
};

u16 const gUnk_Sio_0810F544[] = {
	4,
	OAM0_SHAPE_16x32, OAM1_SIZE_16x32, OAM2_CHR(0x249) + OAM2_PAL(3),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(16), OAM2_CHR(0x24C) + OAM2_PAL(3),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(48), OAM2_CHR(0x24C) + OAM2_PAL(3),
	OAM0_SHAPE_16x32, OAM1_SIZE_16x32 + OAM1_X(80), OAM2_CHR(0x250) + OAM2_PAL(3),
};

u16 const gUnk_Sio_0810F55E[] = {
	2,
	OAM0_SHAPE_32x32 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x32, OAM2_CHR(0x300) + OAM2_LAYER(1),
	OAM0_SHAPE_32x32 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(0x304) + OAM2_LAYER(1),
};

u16 const Sprite_Sio_0810F56C[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x252) + OAM2_LAYER(1) + OAM2_PAL(9),
};

u16 const Sprite_Sio_0810F574[] = {
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x292) + OAM2_LAYER(1) + OAM2_PAL(9),
};

void func_fe6_08040154(struct SioProc85AAA78 * proc)
{
	int i;
	int oam2;

	if (gLinkArenaSt.unk_00 == 1) {
		if (proc->unk_44 != 0)
			oam2 = OAM2_LAYER(1);
		else
			oam2 = OAM2_LAYER(3);

		PutSprite(11, 80, 32, gUnk_Sio_085CB044, proc->unk_44 ? OAM2_LAYER(2) : OAM2_LAYER(1));

		for (i = 0; i < proc->unk_2C; i++) {
			PutSprite(4, proc->unk_30[i] + 8, 32 + i * 24, Sprite_LinkArena_NAMEBANNER, OAM2_PAL(i) + oam2);

			if (proc->unk_3A[i] != 0)
				PutSprite(4, proc->unk_30[i] + 8, 32 + i * 24, gUnk_Sio_0810F544, oam2);
		}

		if (proc->unk_40 != 0) {
			if (Unk_Sio_0203C9D0 == 0) {
				PAL_COLOR(0x18, 13) = ((GetGameTime() % 0x40) / 4)[Pal_0831AAFC];
				EnablePalSync();
			}

			if (proc->unk_40 < 0x100)
				proc->unk_40 += 0x10;

			SetObjAffine(0,
				Div(+COS_Q12(0) * 16, 0x100),
				Div(-SIN_Q12(0) * 16, proc->unk_40),
				Div(+SIN_Q12(0) * 16, 0x100),
				Div(+COS_Q12(0) * 16, proc->unk_40));

			PutSprite(4, 120, 0, gUnk_Sio_0810F55E, OAM2_PAL(8));
		}

		func_fe6_080400FC();
	} else {
		PutSprite(11, 80, 32, gUnk_Sio_085CB044, 0);

		for (i = 0; i < proc->unk_2C; i++) {
			PutSprite(2, proc->unk_30[i], 40 + i * 16, gUnk_Sio_085CB0B4[proc->unk_3A[i]], 0);

			if (proc->unk_3A[i] != 0) {
				if (proc->unk_30[i] < 0)
					proc->unk_30[i]++;
			} else if (proc->unk_30[i] > -8) {
				proc->unk_30[i]--;
			}
		}

		func_fe6_080400A0();
	}

	if (gLinkArenaSt.unk_00 == 1)
		oam2 = OAM2_LAYER(1);
	else
		oam2 = OAM2_LAYER(2);

	if (proc->unk_44 != 0)
		PutLinkArenaButtonSpriteAt(192, 16);

	if (proc->unk_48 >= 0)
		PutSprite(4, 80, proc->unk_48 + 8, gUnk_Sio_085CB07A, oam2);
}

struct SioProc85AAA78 * func_fe6_080403C0(struct SioTeamListProc * parent, int count, u8 * buf)
{
	struct SioProc85AAA78 * proc;
	int i;

	Proc_EndEach(gUnk_Sio_085CB0BC);
	proc = SpawnProc(gUnk_Sio_085CB0BC, parent);

	proc->unk_2C = count;
	proc->unk_44 = 1;
	proc->unk_40 = 0;
	proc->unk_48 = -1;

	for (i = 0; i < 5; i++) {
		proc->unk_3A[i] = buf[i];
		proc->unk_30[i] = -8;
	}

	func_fe6_08040A80(224, 40, parent->unk_38, 6, parent->y_bg1 + 40, proc);
	func_fe6_080404E8(152, 40 - parent->unk_48 * 16, 136, 39, parent->unk_38, proc);

	return proc;
}

void func_fe6_08040468(struct LATeamSpriteDrawProc * proc)
{
	int i, j;

	for (i = 0; i < proc->count; i++) {
		int y = proc->y + i * 16;

		if (y >= proc->y_max)
			continue;

		if (y <= proc->y_min)
			continue;

		for (j = 0; j < 5; j++) {
			struct Unit * unit = GetUnit(i * 5 + j + 1);

			if (unit->pinfo == NULL)
				continue;

			PutUnitSpriteExt(4, proc->x + j * 14, y, OAM2_LAYER(1), unit);
		}
	}
}

void func_fe6_080404E8(int x, int y, int y_max, int y_min, int count, ProcPtr parent)
{
	struct LATeamSpriteDrawProc * proc;

	Proc_EndEach(gUnk_Sio_085CB0D4);
	proc = SpawnProc(gUnk_Sio_085CB0D4, parent);

	proc->count = count;

	proc->x = x;
	proc->y = y;

	proc->y_min = y_min;
	proc->y_max = y_max;
}

void ScrollMultiArenaTeamSprites(int amount)
{
	struct LATeamSpriteDrawProc * proc = FindProc(gUnk_Sio_085CB0D4);
	proc->y += amount;
}

void func_fe6_0804054C(void)
{
	int clock;
	int i;

	u16 const * pal = gUnk_08109C00;

	if (Unk_Sio_0203C9D0 == 0) {
		clock = GetGameTime() % 0x20;
		clock = clock >> 1;

		for (i = 0; i < 5; i++)
			PAL_COLOR(0x19, 11 + i) = pal[(clock + i) & 0xF];

		EnablePalSync();
	}
}

u16 const gUnk_Sio_0810F57C[] = {
	1,
	OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(0x274) + OAM2_LAYER(2) + OAM2_PAL(9),
};

u16 const Sprite_Sio_0810F584[] = {
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x2C0) + OAM2_LAYER(1),
};

u16 const Sprite_Sio_0810F58C[] = {
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x2C4) + OAM2_LAYER(1),
};

u16 const Sprite_Sio_0810F594[] = {
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x2C8) + OAM2_LAYER(1),
};

u16 const Sprite_Sio_0810F59C[] = {
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x2CC) + OAM2_LAYER(1),
};

u16 const Sprite_Sio_0810F5A4[] = {
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x2D0) + OAM2_LAYER(1),
};

void func_fe6_080405A0(struct NameEntrySpriteDrawProc * proc)
{
	int i;

	struct ProcTactician * parent = proc->proc_parent;

	int x = (proc->x_new + proc->x_cur) >> 1;
	int y = (proc->y_new + proc->y_cur) >> 1;

	proc->x_cur = x;
	proc->y_cur = y;

	PutSprite(2, x, y, gUnk_Sio_085CB0EC[proc->cursor_kind], 0);
	PutSprite(2, 96 + proc->x_pointer, 48, gUnk_Sio_0810F57C, 0);
	PutSprite(2, 96, 32, gUnk_Sio_085CB044, 0);
	PutSprite(4, 80, 32, Sprite_LinkArena_NAMEBANNER, OAM2_LAYER(2));

	for (i = 0; i < 5; i++) {
		if (proc->line == i || i > 2)
			PutSprite(4, 196, 72 + i * 16, gUnk_Sio_085CB0F4[i], OAM2_PAL(8));
		else
			PutSprite(4, 196, 72 + i * 16, gUnk_Sio_085CB0F4[i], OAM2_PAL(4));
	}

	if (parent->cur_len == 0)
		PutLinkArenaButtonSpriteAt(192, 16);

	func_fe6_0804054C();
}

ProcPtr func_fe6_0804067C(ProcPtr parent, int x, int y)
{
	struct NameEntrySpriteDrawProc * proc;

	Proc_EndEach(gUnk_Sio_085CB108);
	proc = SpawnProc(gUnk_Sio_085CB108, parent);

	proc->x_new = x;
	proc->x_cur = x;

	proc->y_new = y;
	proc->y_cur = y;

	proc->cursor_kind = 0;
	proc->x_pointer = 0;
	proc->line = 0;

	return proc;
}

void UpdateNameEntrySpriteDraw(ProcPtr proc, int x, int y, int len, int kind, int line)
{
	struct NameEntrySpriteDrawProc * draw_proc = proc;

	draw_proc->x_new = x;
	draw_proc->y_new = y;
	draw_proc->cursor_kind = kind;
	draw_proc->x_pointer = len;
	draw_proc->line = line;
}

u16 const Sprite_Sio_0810F5AC[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x2D4) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 const Sprite_Sio_0810F5B4[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x2D6) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 const Sprite_Sio_0810F5BC[] = {
	1,
	OAM0_SHAPE_16x16, OAM1_SIZE_16x16, OAM2_CHR(0x2D8) + OAM2_LAYER(1) + OAM2_PAL(8),
};

void func_fe6_080406D0(struct RuleSettingSpriteDrawProc * proc)
{
	int i;

	int y1 = proc->y_new;
	int y2 = proc->y_prev;
	int y = (y1 + y2) * 12;

	proc->y_prev = proc->y_new;

	for (i = 0; i < 3; i++)
		PutSprite(2, 32, 48 + i * 24, gUnk_Sio_085CB120[i], 0);

	PutFrozenUiHand(32, y + 48);
	PutUiHand(proc->x_option, proc->y_option);

	PutLinkArenaButtonSpriteAt(192, 16);
}

ProcPtr func_fe6_08040744(ProcPtr parent)
{
	struct RuleSettingSpriteDrawProc * proc;

	Proc_EndEach(gUnk_Sio_085CB12C);
	proc = SpawnProc(gUnk_Sio_085CB12C, parent);

	proc->y_prev = 0;

	return proc;
}

void func_fe6_08040768(ProcPtr proc, i16 y, i16 x_option, i16 y_option)
{
	struct RuleSettingSpriteDrawProc * draw_proc = proc;

	draw_proc->y_new = y;
	draw_proc->x_option = x_option;
	draw_proc->y_option = y_option;
}

void func_fe6_08040770(int idx)
{
	u16 const * pal = gUnk_08109C00;

	if (Unk_Sio_0203C9D0 == 0) {
		PAL_COLOR(0x16, 14) = pal[idx];
		EnablePalSync();
	}
}

u16 const gUnk_Sio_0810F5C4[] = {
	2,
	OAM0_SHAPE_16x16, OAM1_SIZE_32x32, OAM2_CHR(0x2D4) + OAM2_PAL(6),
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x2D6) + OAM2_PAL(6),
};

u16 const gUnk_Sio_0810F5D2[] = {
	2,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_HFLIP, OAM2_CHR(0x2D6) + OAM2_PAL(6),
	OAM0_SHAPE_16x16, OAM1_SIZE_32x32 + OAM1_X(32) + OAM1_HFLIP, OAM2_CHR(0x2D4) + OAM2_PAL(6),
};

u16 const gUnk_Sio_0810F5E0[] = {
	2,
	OAM0_SHAPE_16x16, OAM1_SIZE_32x32 + OAM1_VFLIP, OAM2_CHR(0x2D4) + OAM2_PAL(6),
	OAM0_SHAPE_32x16 + OAM0_Y(16), OAM1_SIZE_32x16 + OAM1_X(32) + OAM1_VFLIP, OAM2_CHR(0x2D6) + OAM2_PAL(6),
};

u16 const gUnk_Sio_0810F5EE[] = {
	2,
	OAM0_SHAPE_32x16 + OAM0_Y(16), OAM1_SIZE_32x16 + OAM1_HFLIP + OAM1_VFLIP, OAM2_CHR(0x2D6) + OAM2_PAL(6),
	OAM0_SHAPE_16x16, OAM1_SIZE_32x32 + OAM1_X(32) + OAM1_HFLIP + OAM1_VFLIP, OAM2_CHR(0x2D4) + OAM2_PAL(6),
};

i16 const gUnk_Sio_0810F5FC[] = {
	2, 3,
	2, 6,
	6, 9,
	8, 12,
	7, 11,
	7, 11,
	6, 10,
	6, 9,
	5, 8,
	5, 7,
	4, 6,
	4, 5,
	3, 4,
	2, 3,
	1, 1,
	0, 0,
};

u16 const Sprite_LAVersus_P1[] = {
	1,
	OAM0_SHAPE_32x16 + OAM0_AFFINE_ENABLE + OAM0_DOUBLESIZE, OAM1_SIZE_32x16 + OAM1_AFFINE_ID(0), OAM2_CHR(0x300) + OAM2_LAYER(1) + OAM2_PAL(3),
};

u16 const Sprite_LAVersus_P2[] = {
	1,
	OAM0_SHAPE_32x16 + OAM0_AFFINE_ENABLE + OAM0_DOUBLESIZE, OAM1_SIZE_32x16 + OAM1_AFFINE_ID(1), OAM2_CHR(0x304) + OAM2_LAYER(1) + OAM2_PAL(4),
};

u16 const Sprite_LAVersus_P3[] = {
	1,
	OAM0_SHAPE_32x16 + OAM0_AFFINE_ENABLE + OAM0_DOUBLESIZE, OAM1_SIZE_32x16 + OAM1_AFFINE_ID(2), OAM2_CHR(0x308) + OAM2_LAYER(1) + OAM2_PAL(5),
};

u16 const Sprite_LAVersus_P4[] = {
	1,
	OAM0_SHAPE_32x16 + OAM0_AFFINE_ENABLE + OAM0_DOUBLESIZE, OAM1_SIZE_32x16 + OAM1_AFFINE_ID(3), OAM2_CHR(0x30C) + OAM2_LAYER(1) + OAM2_PAL(6),
};

void func_fe6_080407A8(struct SioMenuBurstFxProc * proc)
{
	int idx;
	int x;
	int y;
	int x_left;

	idx = proc->clock * 2;

	func_fe6_08040770(proc->clock);

	x = gUnk_Sio_0810F5FC[idx + 1];
	x_left = proc->x - x;

	y = gUnk_Sio_0810F5FC[idx + 0];

	PutSprite(2, x_left, proc->y - y, gUnk_Sio_0810F5C4, 0);
	PutSprite(2, proc->x + x + 16, proc->y - y, gUnk_Sio_0810F5D2, 0);
	PutSprite(2, proc->x - x, proc->y + y, gUnk_Sio_0810F5E0, 0);
	PutSprite(2, proc->x + x + 16, proc->y + y, gUnk_Sio_0810F5EE, 0);

	proc->clock++;

	if (proc->clock == 15)
		Proc_Break(proc);
}

ProcPtr func_fe6_0804085C(struct SioMenuItemProc * parent, int x, int y)
{
	struct SioMenuBurstFxProc * proc = SpawnProc(gUnk_Sio_085CB144, parent);

	proc->x = x;
	proc->y = y;
	proc->clock = 0;
}

void func_fe6_08040880(struct LAMenuScrollBarProc * proc)
{
	proc->arrow_clock[1] = 0;
	proc->arrow_clock[0] = 0;

	proc->bar_len = (proc->height * proc->visible * 8) / proc->total;
	proc->unk_42 = (proc->height * 0x800) / (proc->total * 16);
}

void func_fe6_080408BC(struct LAMenuScrollBarProc * proc)
{
	int i;
	int frames[2];

	int x = proc->x;
	int y = proc->y + 8;
	int bar_tiles = proc->bar_len >> 3;
	int bar_cap = 8 - (proc->bar_len & 7);
	int bar_offset = (proc->scroll * proc->unk_42) >> 8;

	if (proc->total > proc->visible) {
		proc->arrow_clock[0]++;
		proc->arrow_clock[1]++;

		if (proc->scroll < proc->prev_scroll)
			proc->arrow_clock[0] += 2;

		if (proc->scroll > proc->prev_scroll)
			proc->arrow_clock[1] += 2;

		for (i = 0; i < 2; i++) {
			if (proc->arrow_clock[i] > 48)
				proc->arrow_clock[i] = 0;

			frames[i] = (proc->arrow_clock[i] / 8) % 6;
		}

		if (proc->scroll != 0)
			PutSprite(3, x, y - 9, gUnk_Sio_085CB164, frames[0]);

		if ((proc->scroll / 16) + proc->visible < proc->total)
			PutSprite(3, x, proc->height * 8 + y + 1, gUnk_Sio_085CB15C, frames[1]);

		for (i = 0; i < proc->height; i++)
			PutSprite(2, x, y + i * 8, gUnk_Sio_085CB16C, 1);

		for (i = 0; i < bar_tiles; i++)
			PutSprite(2, x, (y + bar_offset) + i * 8, gUnk_Sio_085CB16C, 0);

		PutSprite(2, x, (y + bar_offset) + (bar_tiles * 8) - bar_cap, gUnk_Sio_085CB16C, 0);
		PutSprite(2, x, y - 8, gUnk_Sio_085CB16C, 2);
		PutSprite(2, x + OAM1_VFLIP, proc->height * 8 + y - 7, gUnk_Sio_085CB16C, 2);

		proc->prev_scroll = proc->scroll;
	}
}

void func_fe6_08040A80(int x, int y, u8 total, u8 visible, u8 scroll, ProcPtr parent)
{
	struct LAMenuScrollBarProc * proc;

	Proc_EndEach(gUnk_Sio_085CB174);
	proc = SpawnProc(gUnk_Sio_085CB174, parent);

	proc->x = x;
	proc->y = y;

	proc->height = visible * 2 - 2;

	proc->total = total;
	proc->visible = visible;
	proc->scroll = scroll;
	proc->prev_scroll = scroll;
}

void UpdateLinkArenaMenuScrollBar(u8 total, i16 scroll)
{
	struct LAMenuScrollBarProc * proc = FindProc(gUnk_Sio_085CB174);

	if (proc == NULL)
		return;

	proc->total = total;
	proc->scroll = scroll & 0xFF;
	proc->bar_len = (proc->height * proc->visible * 8) / proc->total;
	proc->unk_42 = (proc->height * 0x800) / (proc->total * 16);
}

void func_fe6_08040B44(void)
{
	Decompress(gUnk_0810B900, (void *) 0x06002000);

	switch (gPlaySt.faction) {
	case 0:
		Decompress(gUnk_0810A62C, (void *) 0x06002800);
		ApplyPalette(gUnk_0810BA60, 5);
		break;

	case 1:
		Decompress(gUnk_0810AADC, (void *) 0x06002800);
		ApplyPalette(gUnk_0810BAA0, 5);
		break;

	case 2:
		Decompress(gUnk_0810AF9C, (void *) 0x06002800);
		ApplyPalette(gUnk_0810BA80, 5);
		break;

	case 3:
		Decompress(gUnk_0810B44C, (void *) 0x06002800);
		ApplyPalette(gUnk_0810BAC0, 5);
		break;
	}

	gUnk_03001438 = gPlaySt.faction;
	gPlaySt.faction = FACTION_BLUE;
}

void func_fe6_08040C00(void)
{
	gPlaySt.faction = gUnk_03001438;

	SetWinEnable(0, 0, 0);
	SetBlendNone();

	gDispIo.bg0_ct.priority = 0;
	gDispIo.bg1_ct.priority = 1;
	gDispIo.bg2_ct.priority = 2;
	gDispIo.bg3_ct.priority = 3;
}

void func_fe6_08040C7C(void)
{
	StartBgm(SONG_22, &gMusicPlayer_MainBgm);
}

void SioSetUniqueWeaponUnbreakable(struct Unit * unit, int item_slot)
{
	u16 item = unit->items[item_slot];

	if (item != 0)
		unit->items[item_slot] = item | 0xFF00;
}

void SioSetUniqueWeapons(struct Unit * unit)
{
	int i;

	for (i = 0; i < ITEMSLOT_INV_COUNT; i++)
		SioSetUniqueWeaponUnbreakable(unit, i);
}

u16 const gUnk_Sio_0810F65C[] = {
	1,
	OAM0_SHAPE_32x16, OAM1_SIZE_32x16, OAM2_CHR(0x348) + OAM2_LAYER(1) + OAM2_PAL(8),
};

u16 const Sprite_Sio_0810F664[] = {
	2,
	OAM0_SHAPE_32x8, OAM1_SIZE_32x8, OAM2_CHR(0x34C) + OAM2_LAYER(1) + OAM2_PAL(9),
	OAM0_SHAPE_32x8, OAM1_SIZE_32x8 + OAM1_X(32), OAM2_CHR(0x350) + OAM2_LAYER(1) + OAM2_PAL(9),
};

u16 const Sprite_Sio_0810F672[] = {
	8,
	OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16, OAM2_CHR(0x300) + OAM2_LAYER(2) + OAM2_PAL(3),
	OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(32), OAM2_CHR(0x304) + OAM2_LAYER(2) + OAM2_PAL(3),
	OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(64), OAM2_CHR(0x308) + OAM2_LAYER(2) + OAM2_PAL(3),
	OAM0_SHAPE_8x16 + OAM0_BLEND, OAM1_SIZE_8x16 + OAM1_X(96), OAM2_CHR(0x30C) + OAM2_LAYER(2) + OAM2_PAL(3),
	OAM0_SHAPE_8x16 + OAM0_BLEND, OAM1_SIZE_8x16 + OAM1_X(104) + OAM1_HFLIP, OAM2_CHR(0x30C) + OAM2_LAYER(2) + OAM2_PAL(3),
	OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(112) + OAM1_HFLIP, OAM2_CHR(0x308) + OAM2_LAYER(2) + OAM2_PAL(3),
	OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(144) + OAM1_HFLIP, OAM2_CHR(0x304) + OAM2_LAYER(2) + OAM2_PAL(3),
	OAM0_SHAPE_32x16 + OAM0_BLEND, OAM1_SIZE_32x16 + OAM1_X(176) + OAM1_HFLIP, OAM2_CHR(0x300) + OAM2_LAYER(2) + OAM2_PAL(3),
};

void LAVersusSpriteDraw_Flashing(void)
{
	int idx;
	int i;

	u16 const * pal = Pal_LinkArenaActiveBannerFx;

	if (Unk_Sio_0203C9D0 == 0) {
		idx = GetGameTime() % 0x20;
		idx = idx >> 1;

		for (i = 0; i < 15; i++)
			PAL_COLOR(0x19, 1 + i) = pal[(idx + i) & 15];

		EnablePalSync();
	}
}

void LAVersusSpriteDraw_Loop(struct SioBatProc_Unk2C * proc)
{
	int i;

	for (i = 0; i < 4; i++) {
		PutSprite(4, proc->x, proc->y + i * 24, Sprite_LinkArena_NAMEBANNER, OAM2_PAL(i) + OAM2_LAYER(2));

		SetObjAffine(i,
			Div(+COS_Q12(0) * 16, 0x100),
			Div(-SIN_Q12(0) * 16, 0x100),
			Div(+SIN_Q12(0) * 16, 0x100),
			Div(+COS_Q12(0) * 16, 0x100));

		if (proc->unk_38 != -1) {
			if (proc->unk_38 != i) {
				if (proc->scale[i] > 0x100)
					proc->scale[i] -= 8;

				if (proc->unk_38 == i)
					goto grow;
			} else {
			grow:
				if (proc->scale[i] <= 335)
					proc->scale[i] += 8;
			}

			SetObjAffine(i,
				Div(+COS_Q12(0) * 16, proc->scale[i]),
				Div(-SIN_Q12(0) * 16, proc->scale[i]),
				Div(+SIN_Q12(0) * 16, proc->scale[i]),
				Div(+COS_Q12(0) * 16, proc->scale[i]));
		}

		PutSprite(4, proc->x - 48, proc->y + i * 24, SpriteArray_LAVersusPlayerNumbers[i], 0);
	}

	if (proc->unk_34 != -1) {
		PutSprite(4, proc->x - 64, proc->y + proc->unk_34 * 24 + 8, gUnk_Sio_0810F65C, 0);
		PutSprite(4, proc->x - 64, proc->y + proc->unk_34 * 24 + 18, Sprite_Sio_0810F664, 0);
		LAVersusSpriteDraw_Flashing();
	}
}

ProcPtr StartLinkArenaVersusSpriteDraw(int x, int y, ProcPtr parent)
{
	struct SioBatProc_Unk2C * proc;
	int i;

	Proc_EndEach(ProcScr_LAVersusSpriteDraw);
	proc = SpawnProc(ProcScr_LAVersusSpriteDraw, parent);

	proc->x = x;
	proc->y = y;
	proc->unk_34 = -1;
	proc->unk_38 = -1;

	for (i = 0; i < 4; i++)
		proc->scale[i] = 0x100;

	return proc;
}

void EndLinkArenaVersusSpriteDraw(void)
{
	Proc_EndEach(ProcScr_LAVersusSpriteDraw);
}

ProcPtr GetLinkArenaVersusSpriteDraw(void)
{
	return FindProc(ProcScr_LAVersusSpriteDraw);
}

void func_fe6_08040F70(void)
{
	int idx;
	int i;

	u16 const * pal = Pal_LinkArenaActiveBannerFx;

	if (Unk_Sio_0203C9D0 == 0) {
		idx = GetGameTime() % 0x20;
		idx = idx >> 1;

		for (i = 0; i < 15; i++)
			PAL_COLOR(2, 1 + i) = pal[(idx + i) & 15];

		EnablePalSync();
	}
}

void func_fe6_08040FC0(void)
{
	int idx;
	int i;

	u16 const * pal = Pal_LinkArenaActiveBannerFx;

	if (Unk_Sio_0203C9D0 == 0) {
		idx = GetGameTime() % 0x20;
		idx = idx >> 1;

		for (i = 0; i < 15; i++)
			PAL_COLOR(0x13, 1 + i) = pal[(idx + i) & 15];

		EnablePalSync();
	}
}

void func_fe6_08041014(void)
{
	SetBlendAlpha(8, 12);

	SetBlendTargetA(0, 0, 0, 0, 0);
	SetBlendTargetB(0, 1, 1, 1, 0);
}

void func_fe6_08041060(struct SioSpriteDrawProc * proc)
{
	if (proc->y > 30 && proc->y < 153) {
		PutSprite(4, proc->x, proc->y, Sprite_Sio_0810F672, 0);
		func_fe6_08040FC0();
	}
}

struct ProcScr CONST_DATA ProcScr_Sio_085CB204[] =
{
	PROC_YIELD,
	PROC_REPEAT(func_fe6_08041060),
	PROC_END,
};

ProcPtr func_fe6_0804108C(int x, int y, ProcPtr parent)
{
	struct SioSpriteDrawProc * proc;

	Proc_EndEach(ProcScr_Sio_085CB204);
	proc = SpawnProc(ProcScr_Sio_085CB204, parent);

	proc->x = x;
	proc->y = y;

	return proc;
}

void SioPutSupportMenuImage(void)
{
	Decompress(Img_SupportMenu, gSioImgBuf);
	SioCopyVRAM(gSioImgBuf, (void *) 0x06016800, 6, 4);
	ApplyPalette(Pal_SupportMenu, 0x12);
}

u16 const Sprite_LinkArena_ChoiceBanner[] = {
	3,
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32, OAM2_CHR(0x340) + OAM2_LAYER(1) + OAM2_PAL(2),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(32), OAM2_CHR(0x341) + OAM2_LAYER(1) + OAM2_PAL(2),
	OAM0_SHAPE_32x32, OAM1_SIZE_32x32 + OAM1_X(64), OAM2_CHR(0x342) + OAM2_LAYER(1) + OAM2_PAL(2),
};

void PutLinkArenaChoiceBannerSprite(int x, int y)
{
	PutSprite(1, x, y, Sprite_LinkArena_ChoiceBanner, 0);
}

fu8 SioAttackItemMenu_Usability(struct MenuEntInfo const * info, int id)
{
	int item = gActiveUnit->items[id];

	if ((GetItemAttributes(item) & ITEM_ATTR_WEAPON) == 0)
		return MENU_ENTRY_HIDDEN;

	if (GetItemMinRange(item) > 2)
		return MENU_ENTRY_DISABLED;

	if (!CanUnitUseWeapon(gActiveUnit, item))
		return MENU_ENTRY_HIDDEN;

	return MENU_ENTRY_ENABLED;
}

fu8 SioAttackItemMenu_Effect(struct MenuProc * menu, struct MenuEntProc * ent)
{
	if (ent->availability == MENU_ENTRY_DISABLED)
		return MENU_ACTION_SE_6B;

	gSioBmSt.unk_07 = ent->id;

	return MENU_ACTION_SE_6A | MENU_ACTION_DOOM;
}

fu8 func_fe6_08041188(struct MenuProc * menu, struct MenuEntProc * ent)
{
	gSioBmSt.unk_06 = ent->id + 1;
	return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u32 SioAttackItemMenu_OnDraw(struct MenuProc * menu, struct MenuEntProc * ent)
{
	int item = gActiveUnit->items[ent->id];

	i8 is_usable = CanUnitUseWeapon(gActiveUnit, item);

	if (GetItemMinRange(item) > 2)
		is_usable = FALSE;

	DrawItemMenuLine(&ent->text, item, is_usable, gBg0Tm + TM_OFFSET(ent->x, ent->y));
	EnableBgSync(BG0_SYNC_BIT);
}

fu8 func_fe6_08041200(struct MenuProc * menu, struct MenuEntProc * ent)
{
	gSioBmSt.unk_06 = 0;
	return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6B | MENU_ACTION_CLEAR;
}

fu8 func_fe6_08041210(struct MenuProc * menu, struct MenuEntProc * ent)
{
	gSioBmSt.unk_06 = 0;

	TmFillRect(gBg0Tm + TM_OFFSET(menu->rect.x, menu->rect.y), menu->rect.w, menu->rect.h, 0);
	TmFillRect(gBg1Tm + TM_OFFSET(menu->rect.x, menu->rect.y), menu->rect.w, menu->rect.h, 0);

	EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

	return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6B;
}

struct MenuEntInfo CONST_DATA MenuEntInfo_SioAttackKind[] =
{
	{
		.label = JTEXT("　直接攻撃"),
		.available = MenuEntryEnabled,
		.on_select = func_fe6_08041188,
	},

	{
		.label = JTEXT("　間接攻撃"),
		.available = MenuEntryEnabled,
		.on_select = func_fe6_08041188,
	},

	{ 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_SioAttackItem[] =
{
	{
		.label = "",
		.available = SioAttackItemMenu_Usability,
		.display = SioAttackItemMenu_OnDraw,
		.on_select = SioAttackItemMenu_Effect,
	},

	{
		.label = "",
		.available = SioAttackItemMenu_Usability,
		.display = SioAttackItemMenu_OnDraw,
		.on_select = SioAttackItemMenu_Effect,
	},

	{
		.label = "",
		.available = SioAttackItemMenu_Usability,
		.display = SioAttackItemMenu_OnDraw,
		.on_select = SioAttackItemMenu_Effect,
	},

	{
		.label = "",
		.available = SioAttackItemMenu_Usability,
		.display = SioAttackItemMenu_OnDraw,
		.on_select = SioAttackItemMenu_Effect,
	},

	{
		.label = "",
		.available = SioAttackItemMenu_Usability,
		.display = SioAttackItemMenu_OnDraw,
		.on_select = SioAttackItemMenu_Effect,
	},

	{ 0 }, // end
};

struct MenuInfo CONST_DATA MenuInfo_SioAttackKind =
{
	.rect = { 16, 2, 8, 0 },
	.entries = MenuEntInfo_SioAttackKind,
	.on_b_press = func_fe6_08041210,
};

struct MenuInfo CONST_DATA gUnk_Sio_085CB384 =
{
	.rect = { 1, 1, 14, 0 },
	.entries = MenuEntInfo_SioAttackItem,
	.on_b_press = func_fe6_08041200,
};
