#include "MagState.h"

/* 100059A0-10005A0F 0006F	*/
MagState::MagState(MagState* param_1) {
}

/* 10005A10-10005A79 00069	*/
MagState* MagState::operator=(MagState* param_1) {
	return 0;
}

/* 10089470-100894B2 00042	*/
MagState::MagState() {
}

/* 100894C0-10089553 00093	*/
MagState::~MagState() {
}

/* 10089560-1008964C 000EC	*/
void MagState::RouteMessage(MsgObject* param_1) {
}

/* 10089650-10089674 00024	*/
bool MagState::RouteMessageHelper(StateObject_Str* param_1, int param_2, MsgObject* param_3) {
	return 0;
}

/* 10089680-100896BB 0003B	*/
void MagState::StoreDelayedMessage(MsgObject* param_1) {
}

/* 100896C0-10089712 00052	*/
void MagState::PushBackDelayedMessage(DelayedMessage_Str* param_1) {
}

/* 10089720-1008972D 0000D	*/
void MagState::InitDelayedMessages() {
}

/* 10089730-10089796 00066	*/
StateObject_Str* MagState::GODBGetGOFromName(char* param_1) {
	return 0;
}

/* 100897A0-100897C7 00027	*/
StateObject_Str* MagState::GODBGetGO(int param_1) {
	return 0;
}

/* 100897D0-100897E7 00017	*/
void MagState::OnUpdateStateMachine() {
}

/* 100897F0-100898BE 000CE	*/
void MagState::OnPreUpdateStateMachine() {
}

/* 100898C0-100898FB 0003B	*/
void MagState::GOUpdate(StateObject_Str* param_1) {
}

/* 10089900-10089913 00013	*/
void MagState::SendMsg(int param_1) {
}

/* 10089920-1008999E 0007E	*/
void MagState::GOUpdateRelay(StateObject_Str* param_1) {
}

/* 100899A0-100899CB 0002B	*/
void MagState::SendOnAnimEnd() {
}

