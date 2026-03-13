#ifndef _MAG_STATE
#define _MAG_STATE

#include <globals.h>

#include "cMagGameObject.h"

class MagState : public cMagGameObject {
	struct DelayedMessage_Str {

	};

public:
	/* 100059A0 */ MagState(MagState* param_1);
	/* 10005A10 */ MagState* operator=(MagState* param_1);
	/* 10089470 */ MagState();
	/* 100894C0 */ ~MagState();
	/* 10089560 */ void RouteMessage(MsgObject* param_1);
	/* 10089650 */ bool RouteMessageHelper(StateObject_Str* param_1, int param_2, MsgObject* param_3);
	/* 10089680 */ void StoreDelayedMessage(MsgObject* param_1);
	/* 100896C0 */ void PushBackDelayedMessage(DelayedMessage_Str* param_1);
	/* 10089720 */ void InitDelayedMessages();
	/* 10089730 */ StateObject_Str* GODBGetGOFromName(char* param_1);
	/* 100897A0 */ StateObject_Str* GODBGetGO(int param_1);
	/* 100897D0 */ void OnUpdateStateMachine();
	/* 100897F0 */ void OnPreUpdateStateMachine();
	/* 100898C0 */ void GOUpdate(StateObject_Str* param_1);
	/* 10089900 */ void SendMsg(int param_1);
	/* 10089920 */ void GOUpdateRelay(StateObject_Str* param_1);
	/* 100899A0 */ void SendOnAnimEnd();

private:
	/* 0xd10 */ uchar f_d10[0xd2c-0xd10];
};

STATIC_ASSERT(sizeof(MagState) == 0xd2c);

#endif