#include "MagState.h"

#include "MagRelayMachine.h"

/* 10089470-100894B2 00042	*/
MagState::MagState() {
	unkn_d14 = NULL;
	stateObject = NULL;
	stateObjects = NULL;
	unkn_d24 = NULL;
	delayedMessages = NULL;
	unkn_d1c = false;
	unkn_d28 = 1;
}

/* 100894C0-10089553 00093	*/
MagState::~MagState() {
	if (unkn_d14 != NULL) {
		delete unkn_d14;
		unkn_d14 = NULL;
	}
	if (stateObject != NULL) {
		delete stateObject;
		stateObject = NULL;
	}
	if (stateObjects != NULL) {
		delete stateObjects;
		stateObjects = NULL;
	}
	if (unkn_d24 != NULL) {
		delete unkn_d24;
		unkn_d24 = NULL;
	}
	if (delayedMessages != NULL) {
		delete delayedMessages;
		delayedMessages = NULL;
	}
}

/* 10089560-1008964C 000EC	*/
void MagState::RouteMessage(MsgObject* param_1) {
	if (GetTickCount() / 10 < param_1->unkn_0c) {
		StoreDelayedMessage(param_1);
		return;
	}

	bool res = RouteMessageHelper(stateObject, stateObject->unkn_08, param_1);
	if (!res) {
		RouteMessageHelper(stateObject, 0, param_1);
	}

	while(stateObject->unkn_10) {
		MsgObject var1;
		var1.unkn_08 = stateObject->unkn_00;
		var1.unkn_04 = stateObject->unkn_00;
		stateObject->unkn_10 = false;
		var1.unkn_00 = 2;
		RouteMessageHelper(stateObject, stateObject->unkn_08, &var1);
		stateObject->unkn_08 = stateObject->unkn_0c;
		var1.unkn_00 = 1;
		RouteMessageHelper(stateObject, stateObject->unkn_08, &var1);
	}
}

/* 10089650-10089674 00024	*/
bool MagState::RouteMessageHelper(StateObject_Str* param_1, int param_2, MsgObject* param_3) {
	return param_1->unkn_04 != 1 ? false : OnProcessStateMachine(param_1, param_2, param_3);
}

/* 10089680-100896BB 0003B	*/
void MagState::StoreDelayedMessage(MsgObject* param_1) {
	DelayedMessage_Str* message = new DelayedMessage_Str;
	// TODO maybe assignment operator (struct?)
	message->object.unkn_00 = param_1->unkn_00;
	message->object.unkn_08 = param_1->unkn_08;
	message->object.unkn_04 = param_1->unkn_04;
	message->object.unkn_0c = param_1->unkn_0c;
	message->next = NULL;
	message->unkn_14 = false;
	PushBackDelayedMessage(message);
}

/* 100896C0-10089712 00052	*/
void MagState::PushBackDelayedMessage(DelayedMessage_Str* param_1) {
	if (*delayedMessages != NULL) {
		DelayedMessage_Str* message = *delayedMessages;
		while (message->next != NULL) {
			if (!message->unkn_14 && message->object.unkn_00 == param_1->object.unkn_00
				&& message->object.unkn_08 == param_1->object.unkn_08
				&& message->object.unkn_04 == param_1->object.unkn_04) {
				return;
			}
			message = message->next;
		}
		message->next = param_1;
		return;
	} else {
		*delayedMessages = param_1;
	}
}

/* 10089720-1008972D 0000D	*/
void MagState::InitDelayedMessages() {
	*delayedMessages = NULL;
}

/* 10089730-10089796 00066	*/
StateObject_Str* MagState::GODBGetGOFromName(char* param_1) {
	StateObject_Str* object = *stateObjects;
	
	while (object != NULL) {
		if (strcmp(object->name, param_1) == 0) {
			return object;
		}
		object = object->next;
	}
	return NULL;
}

/* 100897A0-100897C7 00027	*/
StateObject_Str* MagState::GODBGetGO(int param_1) {
	if (param_1 == 0) {
		return NULL;
	}

	for (StateObject_Str* object = *stateObjects; object != NULL; object = object->next) {
		if (object->unkn_00 == param_1) {
			return object;
		}
	}
	return NULL;
}

/* 100897D0-100897E7 00017	*/
void MagState::OnUpdateStateMachine() {
	if (unkn_d1c) {
		GOUpdate(stateObject);
	}
}

/* 100897F0-100898BE 000CE	*/
void MagState::OnPreUpdateStateMachine() {
	unkn_d14 = new UNKN_0x14;
	stateObject = new StateObject_Str;
	stateObjects = new StateObject_Str*;
	unkn_d24 = new StateObject_Str;
	delayedMessages = new DelayedMessage_Str*;
	stateObject->unkn_00 = 0;
	unkn_d14->unkn_00 = 0;
	InitDelayedMessages();
	unkn_d1c = true;
	stateObject->unkn_10 = false;
	stateObject->unkn_08 = 0;
	stateObject->unkn_0c = 0;
	stateObject->unkn_04 = 1;

	MsgObject msgObject;
	msgObject.unkn_00 = 1;
	msgObject.unkn_04 = stateObject->unkn_00;
	msgObject.unkn_08 = stateObject->unkn_00;
	RouteMessage(&msgObject);
}

/* 100898C0-100898FB 0003B	*/
void MagState::GOUpdate(StateObject_Str* param_1) {
	if (param_1 == NULL) {
		return;
	}

	GOUpdateRelay(param_1);
	MsgObject object;
	object.unkn_08 = param_1->unkn_00;
	object.unkn_04 = param_1->unkn_00;
	object.unkn_00 = 3;
	RouteMessage(&object);
	
}

/* 10089900-10089913 00013	*/
void MagState::SendMsg(int param_1) {
	MagRelayMachine::getInstance()->SendMsg(param_1);
}

/* 10089920-1008999E 0007E	*/
void MagState::GOUpdateRelay(StateObject_Str* param_1) {
	// TODO placeholder
	if (param_1 == 0) {
		return;
	}

	for (StateObject_Str* object = *stateObjects; object != NULL; object = object->next) {
		if (object == param_1) {
			return;
		}
	}
	return;
}

/* 100899A0-100899CB 0002B	*/
void MagState::SendOnAnimEnd() {
	MsgObject object;
	object.unkn_10 = 6;
	object.unkn_08 = stateObject->unkn_00;
	object.unkn_04 = stateObject->unkn_00;
	RouteMessage(&object);
}

