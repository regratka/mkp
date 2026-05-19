#ifndef _MAG_STATE
#define _MAG_STATE

#include <globals.h>

#include "cMagGameObject.h"

struct UNKN_0x14 {
	/* 0x00 */ int unkn_00;
	/* 0x04 */ uchar f_04[0x14-0x04];
};

struct MsgObject {
	/* 0x00 */ int unkn_00;
	/* 0x04 */ int unkn_04;
	/* 0x08 */ int unkn_08;
	/* 0x0c */ float unkn_0c;
	/* 0x10 */ int unkn_10;
};


struct StateObject_Str {
	/* 0x00 */ int unkn_00;
	/* 0x04 */ BOOL unkn_04;
	/* 0x08 */ int unkn_08;
	/* 0x0c */ int unkn_0c;
	/* 0x10 */ bool unkn_10;
	/* 0x11 */ char name[256];
	/* 0x114 */ StateObject_Str* next;
};

class DLLEXPORT MagState : public cMagGameObject {
private:
	struct DelayedMessage_Str {
		/* 0x00 */ MsgObject object;
		/* 0x10 */ uchar f_10[0x14-0x10];
		/* 0x14 */ bool unkn_14;
		/* 0x18 */ DelayedMessage_Str* next;
	};


public:
	/* 10089470 */ MagState();
	/* 100894C0 */ ~MagState();
	/* 10089560 */ void RouteMessage(MsgObject* param_1);
	/* 10089650 */ bool RouteMessageHelper(StateObject_Str* param_1, int param_2, MsgObject* param_3);
	/* 10089680 */ void StoreDelayedMessage(MsgObject* param_1);
	/* 100896C0 */ void PushBackDelayedMessage(DelayedMessage_Str* param_1);
	/* 10089720 */ void InitDelayedMessages();
	/* 10089730 */ StateObject_Str* GODBGetGOFromName(char* param_1);
	/* 100897A0 */ StateObject_Str* GODBGetGO(int param_1);
	/* 100897D0 */ virtual void OnUpdateStateMachine();
	/* 100897F0 */ virtual void OnPreUpdateStateMachine();
	/* 100898C0 */ void GOUpdate(StateObject_Str* param_1);
	/* 10089900 */ void SendMsg(int param_1);
	/* 10089920 */ void GOUpdateRelay(StateObject_Str* param_1);
	/* 100899A0 */ void SendOnAnimEnd();

private:
	/* 0xd10 */ DelayedMessage_Str** delayedMessages;
	/* 0xd14 */ UNKN_0x14* unkn_d14;
	/* 0xd18 */ StateObject_Str* stateObject;
	/* 0xd1c */ bool unkn_d1c;
	/* 0xd20 */ StateObject_Str** stateObjects;
	/* 0xd24 */ StateObject_Str* unkn_d24;
	/* 0xd28 */ int unkn_d28;
};

STATIC_ASSERT(sizeof(MagState) == 0xd2c);

#endif