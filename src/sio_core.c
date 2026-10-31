#include "prelude.h"
#include "irq.h"
#include "proc.h"
#include "hardware.h"
#include "sound.h"
#include "sioerror.h"
#include "sio_core.h"

#include "constants/songs.h"

struct SioSt EWRAM_DATA gSioStInstance = {};

struct SioSt * SHOULD_BE_CONST gSioSt = &gSioStInstance;

u16 EWRAM_DATA gSioOutgoing[0x200] = {};
u16 EWRAM_DATA gSioIncoming[0x200][4] = {};

struct ProcScr CONST_DATA ProcScr_SioBigSend[] = {
	PROC_SLEEP(0),
	PROC_CALL(func_fe6_0803661C),
	PROC_REPEAT(func_fe6_0803667C),
	PROC_END,
};

struct ProcScr CONST_DATA ProcScr_SioBigReceive[] = {
	PROC_SLEEP(0),
	PROC_CALL(func_fe6_080366EC),
	PROC_REPEAT(func_fe6_08036714),
	PROC_REPEAT(func_fe6_08036758),
	PROC_END,
};

extern u8 sSioCnt;
extern int sSioId;
extern struct SioPending * gUnk_030013C0;
extern u32 gUnk_030013C4;
extern u16 gUnk_030013C8;
extern u16 gUnk_030013CA;
extern u16 sReadCursor[4];
extern u16 sRecvCursor[4];

struct SioRegs
{
	u16 siocnt;
	u16 siodata;
};

#define SIO ((struct SioRegs *)(&REG_SIOCNT))

int SioPollingMsg(void)
{
	u16 siocnt;

	switch (gSioStateId) {
	case 0:
		REG_RCNT = 0;

		SIO->siodata = ~gSioSt->unk_1B78;
		SIO->siocnt = sSioCnt | SIO_INTR_ENABLE | SIO_MULTI_MODE;

		siocnt = REG_SIOCNT;

		if ((siocnt & SIO_MULTI_SD) != 0) {
			sSioId = siocnt & SIO_MULTI_SI;

			if (sSioId != 0)
				sSioId = -1;

			gUnk_Sio_030044D4 = 0;
			gSioStateId = 1;
		}

		return -1;

	case 1:
		siocnt = REG_SIOCNT;

		if (gUnk_Sio_030044D4 != 0 && (siocnt & SIO_ERROR) == 0 && gSioSt->last_recv[1] != 0xFFFF) {
			sSioId = (siocnt & SIO_ID) >> 4;
			gSioStateId = 2;

			return sSioId;
		} else {
			SIO->siodata = ~gSioSt->unk_1B78;

			if (sSioId != 0)
				REG_SIOCNT = sSioCnt | SIO_INTR_ENABLE | SIO_MULTI_MODE;
			else
				REG_SIOCNT = sSioCnt | SIO_INTR_ENABLE | SIO_MULTI_MODE | SIO_MULTI_BUSY;

			return -1;
		}

	default:
		return sSioId;
	}
}

int GetSioIndex(void)
{
	return (REG_SIOCNT & SIO_ID) >> 4;
}

void func_fe6_080351F4(u16 arg_0, u16 sio_cnt, u16 arg_2)
{
	gSioSt->unk_1B78 = arg_0;
	gSioSt->unk_1B7A = sio_cnt;
	gSioSt->unk_1B7C = arg_2;
	sSioCnt = sio_cnt;
}

void ResetSioSW(void)
{
	int j, i;

	gUnk_Sio_030044D0 = 0;

	gSioSt->unk_022 = 0;
	gSioSt->self_seq = 0;
	gSioSt->next_pending_send = 0;
	gSioSt->next_pending_write = 0;
	gSioSt->next_pending_read = 0;
	gSioSt->next_pending_recv = 0;
	gSioSt->unk_01E = 0;
	gSioSt->unk_01F = 0;
	gSioSt->unk_020 = 0;
	gSioSt->unk_030 = 0;

	for (i = 0; i < 4; i++) {
		gSioSt->player_status[i] = 0;
		gSioSt->last_recv[i] = 0;
		gSioSt->timeout_clock[i] = 0;
		gSioSt->seq[i] = 0;
	}

	for (i = 0; i < SIO_MAX_PACKET; i++) {
		gUnk_Sio_03004580[i] = 0;
		gSioSt->buf[i] = 0;
	}

	for (j = 0; j < SIO_MAX_PENDING_SEND; j++) {
		struct SioPending * ent = &gSioSt->pending_send[j];

		ent->unk_00 = 0;
		ent->packet.head.kind = 0;

		for (i = 0; i < (int)ARRAY_COUNT(ent->packet.bytes); i++)
			ent->packet.bytes[i] = 0;
	}

	for (j = 0; j < SIO_MAX_PENDING_RECV; j++) {
		struct SioPending * ent = &gSioSt->pending_recv[j];

		ent->unk_00 = 0;
		ent->packet.head.kind = 0;

		for (i = 0; i < (int)ARRAY_COUNT(ent->packet.bytes); i++)
			ent->packet.bytes[i] = 0;
	}

	gUnk_030013C8 = gUnk_030013CA = 0;

	for (i = 0; i < 0x200; i++)
		gSioOutgoing[i] = 0;

	for (j = 0; j < 4; j++) {
		sReadCursor[j] = sRecvCursor[j] = 0;

		for (i = 0; i < 0x200; i++)
			gSioIncoming[i][j] = 0;
	}
}

void SioInit_SW(void)
{
	gSioSt->unk_000 = 0;
	gSioSt->unk_001 = 0;
	gSioSt->last_sio_cnt = 0;
	gSioSt->unk_004 = 0;
	gSioSt->self_id = -1;
	gSioSt->unk_007 = 0;
	gSioSt->recv_flags = 0;
	gSioSt->unk_009 = 0;
	gSioSt->unk_00F = 0;
	gSioSt->unk_010 = 0;
	gSioSt->unk_011 = 0;
	gSioSt->unk_02E = 0;
	gSioSt->unk_00A = 0;

	func_fe6_080351F4(0x4321, 3, 0x88);
	SetXmapTransferState(0);
	ResetSioSW();

	gUnk_030013C4 = 0;
}

void SioInit_HW(void)
{
	REG_RCNT = 0;
	REG_SIOCNT = sSioCnt | SIO_MULTI_MODE;

	REG_TM3CNT_H = 0;

	gUnk_Sio_030044D4 = gUnk_Sio_030044D0 = 0;
	gSioStateId = 0;
	sSioId = -1;

	SetIrqFunc(7, func_fe6_080354F0);
	SetIrqFunc(6, func_fe6_08035880);

	REG_IE |= INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
}

void SioReleaseIrq(void)
{
	REG_RCNT = 0x8000;
	REG_SIOCNT = 0;

	gUnk_Sio_030044D4 = gUnk_Sio_030044D0 = 0;
	gSioStateId = 0;
	sSioId = -1;

	SetIrqFunc(7, NULL);
	SetIrqFunc(6, NULL);

	REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
}

void func_fe6_080354F0(void)
{
	int i;
	u16 recv[4];
	u16 var_08;
	u16 siocnt;

	u16 count = 0;

	gUnk_Sio_030044D4 = 1;
	gSioSt->unk_01E = 0;
	gUnk_Sio_030044D0 = 1;
	gSioSt->recv_flags = 0;

	REG_TM3CNT_H = 0;

	gSioSt->last_sio_cnt = siocnt = REG_SIOCNT;

	if (gSioSt->unk_004 != 6)
		gSioSt->self_id = (siocnt >> 4) & 3;

	*(u64 *)(recv) = REG_SIOMLT_RECV;

	REG_SIOCNT = sSioCnt | SIO_MULTI_MODE | SIO_INTR_ENABLE;
	SIO->siodata = 0x7FFF;

	for (i = 0; i < 4; i++) {
		if (recv[i] != 0 && recv[i] != 0xFFFF) {
			if (gSioSt->player_status[i] == 0)
				gSioSt->player_status[i] = 1;

			gSioSt->recv_flags |= 1 << i;
		} else if (func_fe6_08035CB0(i) == TRUE) {
			if (gSioSt->last_recv[i] == 0xFFFF)
				gSioSt->timeout_clock[i]++;
			else
				gSioSt->timeout_clock[i] = 0;
		}

		gSioSt->last_recv[i] = gSioIncoming[sRecvCursor[i]][i] = recv[i];

		sRecvCursor[i] = (sRecvCursor[i] + 1) & 0x1FF;
	}

	if (gSioSt->unk_004 > 4) {
		switch (gSioSt->unk_001) {
		case 1:
			if (gUnk_030013CA != gUnk_030013C8) {
				var_08 = gSioOutgoing[gUnk_030013C8];
				gUnk_030013C8 = (gUnk_030013C8 + 1) & 0x1FF;
				SioSend16(&var_08, 1);
			}

			if (gSioSt->self_id == 0 && gSioSt->unk_1B7C != 0) {
				REG_TM3CNT = -gSioSt->unk_1B7C;
				REG_TM3CNT_H = 0xC3;
			}

			break;

		case 3:
			if (gSioSt->self_id != 0) {
				SioSend16(&gSioSt->unk_030, 1);
				gSioSt->unk_030 = 0x5FFF;
			}

			for (i = 0; i < 4; i++) {
				if (func_fe6_08035CB0(i) && recv[i] != 0x9ABC)
					count++;
			}

			if (count == 0)
				gSioSt->unk_1B7E = 1;

			break;
		}
	}

	gUnk_Sio_030044D0 = 0;
}

void func_fe6_08035734(void)
{
	int i;
	u32 len;
	struct SioData * dat;

	if (gSioSt->unk_004 > 4 && gSioSt->unk_001 != 0) {
		gSioSt->unk_01E++;

		if (gSioSt->unk_004 == 6) {
			switch (gSioSt->unk_021) {
			case 3:
				if (gSioSt->unk_01E > 60) {
					gSioSt->player_status[gSioSt->self_id] = 0;
					StartSioErrorScreen();
				}

				// fallthrough

			case 2:
				if (gSioSt->unk_001 != 0 && !func_fe6_08035CF8()) {
					gSioSt->player_status[gSioSt->self_id] = 0;
					StartSioErrorScreen();
				}

				// fallthrough

			case 1:
				for (i = 0; i < 4; i++) {
					if (gSioSt->timeout_clock[i] > 60) {
						gSioSt->player_status[i] = 0;
						StartSioErrorScreen();
					}
				}

				break;
			}
		}

		if (gSioSt->unk_001 == 1) {
			if (gSioSt->unk_010 == 0) {
				if (gSioSt->unk_011 > 60) {
					StartSioErrorScreen();
					gSioSt->unk_004 = 2;
					return;
				}

				dat = func_fe6_080361A4(&len);

				if (dat != NULL) {
					if (SioSend(dat, len + offsetof(struct SioData, bytes)) > 0) {
						gSioSt->unk_010 = 0;
						gSioSt->unk_011++;
						gSioSt->unk_02E = 1;
					}
				}
			}

			gSioSt->unk_010++;
			gSioSt->unk_010 = gSioSt->unk_010 % 38;
		} else if (gSioSt->unk_001 == 2 || gSioSt->unk_001 == 3) {
			if (gSioSt->self_id == 0) {
				SioSend16(&gSioSt->unk_030, -1);
				gSioSt->unk_030 = 0x5FFF;
			}
		}
	}
}

void func_fe6_08035880(void)
{
	REG_TM3CNT_H = 0;
	REG_SIOCNT = sSioCnt | SIO_MULTI_MODE | SIO_INTR_ENABLE | SIO_ENABLE;
}

void func_fe6_080358A4(int num)
{
	u32 table[4] = { SONG_6C, SONG_6C, SONG_6C, SONG_6C };

	PlaySe(table[num]);
}

void func_fe6_080358DC(void)
{
	int i, j;

	if (gSioSt->unk_001 != 1)
		return;

	gSioSt->unk_00F |= 1 << gSioSt->self_id;

	for (i = 0; i < 4; i++) {
		u16 len;

	redo:
		len = func_fe6_08035EC0(i, gSioSt->buf);

		if (len != 0) {
			switch (len) {
				struct SioMessage * message;
				struct SioData * data_message;

			case 0x0A:
			case 0x16:
			case 0x2A:
			case 0x2E:
			case 0x80:
				data_message = (void *)gSioSt->buf;

				if (data_message->head.kind != SIO_MSG_1C) {
					if (data_message->head.kind != SIO_MSG_DATA)
						break;

					if (data_message->head.sender == gSioSt->self_id)
						break;

					if (data_message->head.param != gSioSt->seq[data_message->head.sender]) {
						gSioMsgBuf.kind = SIO_MSG_DATA_ACK;
						gSioMsgBuf.sender = (gSioSt->self_id << 4) | data_message->head.sender;
						gSioMsgBuf.param = gSioSt->seq[data_message->head.sender];

						SioSend(&gSioMsgBuf, sizeof(gSioMsgBuf));

						goto redo;
					} else {
						func_fe6_08036130(data_message);

						gSioMsgBuf.kind = SIO_MSG_DATA_ACK;
						gSioMsgBuf.sender = (gSioSt->self_id << 4) | data_message->head.sender;
						gSioMsgBuf.param = gSioSt->seq[data_message->head.sender] + 1;

						SioSend(&gSioMsgBuf, sizeof(gSioMsgBuf));
					}

					break;
				}

				for (j = 0; j < 15; j++)
					gLinkArenaSt.unk_A1[i][j] = data_message->bytes[j];

				if ((func_fe6_08035CB0(i) == 0 && gSioSt->unk_000 == data_message->head.param && gSioSt->unk_004 <= 5) || func_fe6_08035CB0(i) == 1) {
					if (gSioSt->self_id == 0) {
						gSioMsgBuf.kind = SIO_MSG_16;
						gSioMsgBuf.sender = gSioSt->self_id;
						gSioMsgBuf.param = i;

						SioSend(&gSioMsgBuf, sizeof(gSioMsgBuf));
					}

					break;
				}

				if (gSioSt->self_id == 0) {
					u32 cmd = gSioSt->unk_000 != data_message->head.param ? SIO_MSG_17 : SIO_MSG_15;

					gSioMsgBuf.kind = cmd;
					gSioMsgBuf.sender = gSioSt->self_id;
					gSioMsgBuf.param = i;

					SioSend(&gSioMsgBuf, sizeof(gSioMsgBuf));
				}

				break;

			case 0x04:
				message = (void *)gSioSt->buf;

				switch (message->kind) {
				case SIO_MSG_19:
					gSioSt->unk_00A |= 1 << message->sender;
					break;

				case SIO_MSG_DATA_ACK:
					if (gSioSt->unk_02E != 0) {
						if ((message->sender >> 4) != gSioSt->self_id && (message->sender & 0x0F) == gSioSt->self_id && (message->param == (u16)(gSioSt->self_seq + 1))) {
							gSioSt->unk_00F |= 1 << (message->sender >> 4);
							gUnk_030013C0->unk_00 = gSioSt->unk_00F;

							if ((gSioSt->unk_00F & gSioSt->unk_009) == gSioSt->unk_009) {
								gSioSt->self_seq++;
								gSioSt->pending_send[gSioSt->next_pending_send].packet.head.kind = 0;
								gSioSt->next_pending_send++;
								gSioSt->next_pending_send &= (SIO_MAX_PENDING_SEND - 1);
								gSioSt->unk_02E = 0;
								gSioSt->unk_010 = gSioSt->unk_011 = gSioSt->unk_00F = 0;
							}
						}
					}

					break;

				case SIO_MSG_17:
					if (func_fe6_08035CB0(message->param) == 0) {
						gSioSt->player_status[gSioSt->self_id] = PLAYER_STATUS_2;
						gSioSt->player_status[(gSioSt->last_sio_cnt & 0x30) >> 4] = PLAYER_STATUS_2;
						gSioSt->player_status[message->param] = PLAYER_STATUS_2;
						gSioSt->unk_004 = 6;
					}

					break;

				case SIO_MSG_15:
					if (func_fe6_08035CB0(message->param) == 0) {
						gSioSt->player_status[message->param] = PLAYER_STATUS_2;
						gSioSt->unk_004 = 6;
					}

					break;

				case SIO_MSG_16:
					gLinkArenaSt.linking_status[message->param] = 1;
					gSioSt->player_status[message->param] = PLAYER_STATUS_5;
					gSioSt->unk_009 |= 1 << message->param;
					gSioSt->timeout_clock[message->param] = 0;
					break;

				case SIO_MSG_14:
					func_fe6_080358A4(message->sender);
					break;
				}

				break;
			}
		}
	}
}

void func_fe6_08035C54(void)
{
}

int func_fe6_08035C58(void)
{
	int i;
	u8 count = 0;

	for (i = 0; i < 4; i++) {
		if (func_fe6_08035CB0(i) == TRUE)
			count++;
	}

	return count;
}

int func_fe6_08035C84(void)
{
	int i;
	u8 count = 0;

	for (i = 0; i < 4; i++) {
		if (func_fe6_08035CD4(i) == TRUE)
			count++;
	}

	return count;
}

bool func_fe6_08035CB0(u8 player_id)
{
	if (((gSioSt->unk_009 >> player_id) & 1) != 0)
		return TRUE;

	return FALSE;
}

bool func_fe6_08035CD4(u8 player_id)
{
	if (((gSioSt->recv_flags >> player_id) & 1) != 0)
		return TRUE;

	return FALSE;
}

bool func_fe6_08035CF8(void)
{
	int last_sio_cnt = gSioSt->last_sio_cnt;
	gSioSt->last_sio_cnt = 0;

	if ((last_sio_cnt & SIO_MULTI_SD) == 0 && (REG_SIOCNT & SIO_MULTI_SD) == 0)
		gSioSt->unk_020++;
	else
		gSioSt->unk_020 = 0;

	if (gSioSt->unk_020 > 10)
		return FALSE;

	return TRUE;
}

int func_fe6_08035D4C(void)
{
	if (gSioSt->next_pending_write >= gSioSt->next_pending_send)
		return gSioSt->next_pending_write - gSioSt->next_pending_send;
	else
		return SIO_MAX_PENDING_SEND + gSioSt->next_pending_write - gSioSt->next_pending_send;
}

bool func_fe6_08035D7C(void)
{
	int i, count = 0;

	for (i = 0; i < 4; i++) {
		if (gSioSt->player_status[i] == PLAYER_STATUS_5)
			count++;
	}

	if ((gSioSt->unk_009 == 0x3 && count == 2) || (gSioSt->unk_009 == 0x7 && count == 3) || (gSioSt->unk_009 == 0xF && count == 4))
		return TRUE;

	return FALSE;
}

i16 SioSend(void const * src, u16 len)
{
	int i;
	u16 magic;
	u16 sum_a = 0;
	u16 sum_b = 0;
	u16 cur = gUnk_030013CA;

	if (len > SIO_MAX_PACKET)
		return -1;

	len = len / 2;
	magic = 0x4FFF;
	sum_a = magic + len;

	gSioOutgoing[cur] = magic;
	cur = cur + 1;
	cur = cur & 0x1FF;

	if (cur == gUnk_030013C8)
		return -1;

	gSioOutgoing[cur] = len;
	cur = cur + 1;
	cur = cur & 0x1FF;

	if (cur == gUnk_030013C8)
		return -1;

	for (i = 0; i < len; i++) {
		u32 frag = ((u16 const *)src)[i] * (i + 1);

		sum_a = sum_a + frag;
		sum_b = sum_b + ~frag;
	}

	gSioOutgoing[cur] = sum_a;
	cur = cur + 1;
	cur = cur & 0x1FF;

	if (cur == gUnk_030013C8)
		return -1;

	gSioOutgoing[cur] = sum_b;
	cur = cur + 1;
	cur = cur & 0x1FF;

	if (cur == gUnk_030013C8)
		return -1;

	for (i = 0; i < len; i++) {
		gSioOutgoing[cur] = ((u16 const *)src)[i];
		cur = cur + 1;
		cur = cur & 0x1FF;

		if (cur == gUnk_030013C8)
			return -1;
	}

	gUnk_030013CA = cur;

	return len;
}

i16 func_fe6_08035EC0(i8 player_id, void * dst)
{
	int i;
	u16 sum_a = 0;
	u16 recv_sum_a;
	u16 sum_b = 0;
	u16 recv_sum_b;
	u16 count;
	u16 lookahead;
	u16 len;

	if (sReadCursor[player_id] == sRecvCursor[player_id])
		return -2;

	if (gSioIncoming[sReadCursor[player_id]][player_id] != 0x4FFF) {
		while (sReadCursor[player_id] != sRecvCursor[player_id]) {
			sReadCursor[player_id] += 1;
			sReadCursor[player_id] &= 0x1FF;

			if (gSioIncoming[sReadCursor[player_id]][player_id] == 0x4FFF && sReadCursor[player_id] != sRecvCursor[player_id])
				goto yes;
		}

		return -4;
	}

yes:
	if (sRecvCursor[player_id] < sReadCursor[player_id])
		count = 0x200 - sReadCursor[player_id] + sRecvCursor[player_id];
	else
		count = sRecvCursor[player_id] - sReadCursor[player_id];

	if (count <= 4)
		return -4;

	if (sReadCursor[player_id] + 1 < 0x200)
		lookahead = sReadCursor[player_id] + 1;
	else
		lookahead = 0;

	len = gSioIncoming[lookahead][player_id];

	if (len > SIO_MAX_PACKET) {
		sReadCursor[player_id] += 1;
		sReadCursor[player_id] &= 0x1FF;

		return -4;
	}

	if (len + 6 > count)
		return -2;

	sReadCursor[player_id] += 2;
	sReadCursor[player_id] &= 0x1FF;

	recv_sum_a = gSioIncoming[sReadCursor[player_id]][player_id];

	sReadCursor[player_id] += 1;
	sReadCursor[player_id] &= 0x1FF;

	recv_sum_b = gSioIncoming[sReadCursor[player_id]][player_id];

	sReadCursor[player_id] += 1;
	sReadCursor[player_id] &= 0x1FF;

	sum_a += 0x4FFF + len;

	for (i = 0; i < len; i++) {
		u32 data = gSioIncoming[sReadCursor[player_id]][player_id];
		u32 frag = data * (i + 1);

		sum_a = sum_a + frag;
		sum_b = sum_b + ~frag;

		((u16 *)dst)[i] = data;

		sReadCursor[player_id] += 1;
		sReadCursor[player_id] &= 0x1FF;
	}

	if (sum_a != recv_sum_a || sum_b != recv_sum_b)
		return -3;

	return len * 2;
}

int SioSend16(u16 * word, int arg_1)
{
	if (gSioSt->self_id == -1)
		return -1;

	SIO->siodata = *word;

	if (gSioSt->self_id == 0 && arg_1 < 0)
		REG_SIOCNT = sSioCnt | SIO_MULTI_MODE | SIO_INTR_ENABLE | SIO_ENABLE;

	return 0;
}

int func_fe6_080360C4(int unused_0, u16 * arg_1)
{
	int i;

	if (sReadCursor[0] == sRecvCursor[0]) {
		*arg_1++ = 0x7FFF;
		*arg_1++ = 0x7FFF;
		*arg_1++ = 0x7FFF;
		*arg_1++ = 0x7FFF;

		return -2;
	}

	for (i = 0; i < 4; i++) {
		*arg_1++ = gSioIncoming[sReadCursor[i]][i];

		sReadCursor[i] += 1;
		sReadCursor[i] &= 0x1FF;
	}

	return 0;
}

void func_fe6_08036130(struct SioData * data)
{
	int i;

	struct SioPending * ent = &gSioSt->pending_recv[gSioSt->next_pending_recv];

	ent->packet.head.kind = data->head.kind;
	ent->packet.head.sender = data->head.sender;
	ent->packet.head.param = data->head.param;

	ent->packet.len = data->len;

	for (i = 0; i < data->len; i++)
		ent->packet.bytes[i] = data->bytes[i];

	gSioSt->next_pending_recv += 1;
	gSioSt->next_pending_recv &= (SIO_MAX_PENDING_RECV - 1);
}

struct SioData * func_fe6_080361A4(u32 * out)
{
	if (gSioSt->pending_send[gSioSt->next_pending_send].packet.head.kind != SIO_MSG_DATA)
		return NULL;

	gUnk_030013C0 = &gSioSt->pending_send[gSioSt->next_pending_send];

	*out = gSioSt->pending_send[gSioSt->next_pending_send].packet.len;
	return &gSioSt->pending_send[gSioSt->next_pending_send].packet;
}

int SioEmitData(u8 const * src, u16 len)
{
	int result;
	u8 i;

	struct SioData * dat;

	gUnk_030013C4 = 1;

	gSioSt->pending_send[gSioSt->next_pending_write].unk_00 = 0;
	dat = &gSioSt->pending_send[gSioSt->next_pending_write].packet;

	dat->head.kind = SIO_MSG_DATA;
	dat->head.sender = gSioSt->self_id;
	dat->head.param = gSioSt->unk_022;
	dat->len = len;

	gSioSt->unk_022++;

	for (i = 0; i < len; i++)
		dat->bytes[i] = src[i];

	result = gSioSt->next_pending_write;

	gSioSt->next_pending_write += 1;
	gSioSt->next_pending_write &= (SIO_MAX_PENDING_SEND - 1);

	gUnk_030013C4 = 0;

	return result;
}

int SioReceiveData(void * dst, u8 * out_sender_id, bool (* verify)(void * dst))
{
	u8 i;
	u8 sender_id;

	struct SioData * dat = &gSioSt->pending_recv[gSioSt->next_pending_read].packet;

	if (dat->head.kind != SIO_MSG_DATA || dat->head.sender == gSioSt->self_id)
		return 0;

	if (dat->head.param != gSioSt->seq[dat->head.sender]) {
		gSioMsgBuf.kind = SIO_MSG_DATA_ACK;
		gSioMsgBuf.sender = (gSioSt->self_id << 4) | dat->head.sender;
		gSioMsgBuf.param = gSioSt->seq[dat->head.sender];

		SioSend(&gSioMsgBuf, sizeof(gSioMsgBuf));

		dat->head.kind = 0;

		gSioSt->next_pending_read += 1;
		gSioSt->next_pending_read &= (SIO_MAX_PENDING_RECV - 1);

		return SioReceiveData(dst, out_sender_id, verify);
	} else {
		for (i = 0; i < dat->len; i++)
			((u8 *) dst)[i] = dat->bytes[i];

		if (verify != NULL && !verify(dst)) {
			gSioMsgBuf.kind = SIO_MSG_DATA_ACK;
			gSioMsgBuf.sender = (gSioSt->self_id << 4) | dat->head.sender;
			gSioMsgBuf.param = gSioSt->seq[dat->head.sender];

			SioSend(&gSioMsgBuf, sizeof(gSioMsgBuf));

			dat->head.kind = 0;

			gSioSt->next_pending_read += 1;
			gSioSt->next_pending_read &= (SIO_MAX_PENDING_RECV - 1);

			return SioReceiveData(dst, out_sender_id, verify);
		} else {
			dat->head.kind = 0;

			sender_id = dat->head.sender;

			gSioSt->seq[dat->head.sender] += 1;

			gSioSt->next_pending_read += 1;
			gSioSt->next_pending_read &= (SIO_MAX_PENDING_RECV - 1);

			*out_sender_id = sender_id;

			gSioMsgBuf.kind = SIO_MSG_DATA_ACK;
			gSioMsgBuf.sender = (gSioSt->self_id << 4) | dat->head.sender;
			gSioMsgBuf.param = gSioSt->seq[dat->head.sender];

			SioSend(&gSioMsgBuf, sizeof(gSioMsgBuf));

			return dat->len;
		}
	}
}

void func_fe6_08036440(void)
{
	int i;

	u16 abc = 0x7FFF;

	gSioSt->unk_001 = 0;

	SioSend16(&abc, 1);

	gUnk_030013CA = gUnk_030013C8;

	for (i = 0; i < 4; i++)
		sRecvCursor[i] = sReadCursor[i];
}

void SetXmapTransferState(int state)
{
	gSioSt->unk_021 = state;
}

void func_fe6_080364A4(void)
{
	int i;

	u16 abc = 0x7FFF;

	gSioSt->unk_001 = 0;
	gSioSt->unk_1B7C = 0;

	SioSend16(&abc, 1);

	gUnk_030013CA = gUnk_030013C8;

	for (i = 0; i < 4; i++)
		sRecvCursor[i] = sReadCursor[i];

	gSioSt->unk_1B7E = 0;
	gSioSt->unk_001 = 3;
}

void func_fe6_08036518(void)
{
	int i;

	u16 abc = 0x2586;

	gSioSt->unk_004 = 0;
	gSioSt->unk_001 = 0;
	gSioSt->unk_1B7C = 0x88;

	gUnk_030013CA = gUnk_030013C8;

	for (i = 0; i < 4; i++)
		sRecvCursor[i] = sReadCursor[i];

	gSioSt->unk_001 = 1;
	gSioSt->unk_004 = 6;

	SioSend16(&abc, -1);
}

void XMapTransfer_08036590(void)
{
	int i;

	u16 abc = 0x2586;

	gSioSt->unk_004 = 0;
	gSioSt->unk_001 = 0;
	gSioSt->unk_1B7C = 24;

	gUnk_030013CA = gUnk_030013C8;

	for (i = 0; i < 4; i++)
		sRecvCursor[i] = sReadCursor[i];

	gSioSt->unk_001 = 1;
	gSioSt->unk_004 = 6;

	SioSend16(&abc, -1);
}

void func_fe6_08036608(void)
{
	gUnk_030013CA = gUnk_030013C8;
}

void func_fe6_0803661C(struct SioBigSendProc * proc)
{
	u8 data[4];

	gSioSt->self_seq = gSioSt->unk_022 = gSioSt->unk_02E = 0;

	gSioSt->seq[0] = gSioSt->seq[1] = gSioSt->seq[2] = gSioSt->seq[3] = 0;

	ResetSioSW();

	data[0] = proc->unk_34;
	data[1] = proc->block_count >> 8;
	data[2] = proc->block_count & 0xFF;
	data[3] = proc->last_block_len;

	SioEmitData(data, sizeof(data));
	gSioSt->unk_02E = 1;
}

void func_fe6_0803667C(struct SioBigSendProc * proc)
{
	if (proc->func != NULL)
		proc->func(proc);

	if (gSioSt->unk_02E == 0) {
		if (proc->current_block != gSioSt->self_seq - 1) {
			proc->data += SIO_MAX_DATA;
			proc->completion_percent = proc->current_block * 100 / proc->block_count;
			proc->current_block++;
		}

		SioEmitData(proc->data, SIO_MAX_DATA);
		gSioSt->unk_02E = 1;

		gSioSt->unk_010 = 0;

		if (proc->current_block >= proc->block_count)
			Proc_Break(proc);
	}
}

void func_fe6_080366EC(struct SioBigReceiveProc * proc)
{
	gSioSt->self_seq = gSioSt->unk_022 = gSioSt->unk_02E = 0;

	gSioSt->seq[0] = gSioSt->seq[1] = gSioSt->seq[2] = gSioSt->seq[3] = 0;

	ResetSioSW();
}

void func_fe6_08036714(struct SioBigReceiveProc * proc)
{
	u8 data[4];
	u8 id;

	u16 got = SioReceiveData(&data, &id, NULL);

	if (got != 0) {
		proc->unk_34 = data[0];
		proc->block_count = (data[1] << 8) + (data[2] & 0xFF);
		proc->last_block_len = data[3];

		Proc_Break(proc);
	}
}

void func_fe6_08036758(struct SioBigReceiveProc * proc)
{
	int i;
	u8 id;

	u8 * buf = gBuf;

	if (proc->current_block < proc->block_count - 1) {
		u16 got = SioReceiveData(proc->data, &id, NULL);

		if (got != 0) {
			proc->data += SIO_MAX_DATA;
			proc->completion_percent = proc->current_block * 100 / proc->block_count;
			proc->current_block++;
		}
	} else {
		u16 got = SioReceiveData(buf, &id, NULL);

		if (got != 0) {
			for (i = 0; i < proc->last_block_len; i++) {
				*((u8 *) proc->data) = buf[i];
				proc->data++;
			}

			proc->completion_percent = proc->current_block * 100 / proc->block_count;
			proc->current_block++;
		}
	}

	if (proc->func != NULL)
		proc->func(proc);

	if (proc->current_block >= proc->block_count)
		Proc_Break(proc);
}

int StartSioBigSend(void * data, u32 len, void (* func)(struct SioBigSendProc * proc), u8 arg_3, ProcPtr parent)
{
	struct SioBigSendProc * proc;

	u8 last_block_len;
	u16 block_count;

	if (len > SIO_MAX_DATA * 0xFFFF)
		return -1;

	block_count = len / SIO_MAX_DATA + 1;

	if (len % SIO_MAX_DATA != 0)
		block_count++;

	last_block_len = len % SIO_MAX_DATA;

	proc = SpawnProcLocking(ProcScr_SioBigSend, parent);

	proc->data = data;
	proc->unk_34 = arg_3;
	proc->func = func;
	proc->block_count = block_count;
	proc->last_block_len = last_block_len;
	proc->completion_percent = 0;
	proc->current_block = 0;
	proc->unk_3C = 0;

	return 0;
}

void StartSioBigReceive(void * data, void (* func)(struct SioBigReceiveProc * proc), ProcPtr parent)
{
	struct SioBigReceiveProc * proc;

	proc = SpawnProcLocking(ProcScr_SioBigReceive, parent);

	proc->func = func;
	proc->data = data;
	proc->completion_percent = 0;
	proc->current_block = 0;
	proc->unk_3C = 0;
}

bool IsSioBigTransferActive(void)
{
	if (FindProc(ProcScr_SioBigSend) == NULL && FindProc(ProcScr_SioBigReceive) == NULL)
		return FALSE;

	return TRUE;
}
