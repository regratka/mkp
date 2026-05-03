#include "MagRelayMachine.h"

/* 10053EE0-10053EE3 00003	*/
bool MagRelayMachine::IsMessage() {
	return true;
}

/* 10089100-10089154 00054	*/
MagRelayMachine::MagRelayMachine(): MagSingleton<MagRelayMachine>(this) {
	msgs.clear();
}

/* 10089160-100891B9 00059	*/
MagRelayMachine::~MagRelayMachine() {
	msgs.clear();
}

/* 100891C0-10089394 001D4	*/
void MagRelayMachine::SendMsg(int param_1) {
	Message msg;
	msg.msgID = param_1;
	msg.unkn_00 = true;

	for (int index = 0; index < this->msgs.size(); index++) {
		if (msgs[index].msgID == param_1) {
			return;
		}
	}
	msgs.push_back(msg);
}

/* 100C5C30-100C5C36 00006	*/
int MagRelayMachine::GetMessageName() {
	return 1;
}

