#ifndef _MAG_RELAY_MACHINE
#define _MAG_RELAY_MACHINE

#include <globals.h>
#include <VECTOR>

#include "MagSingleton.h" 

struct Message {
	/* 0x00 */ bool unkn_00;
	/* 0x04 */ int msgID;
};

class DLLEXPORT MagRelayMachine : public MagSingleton<MagRelayMachine> {
public:
    static MagRelayMachine* getInstance() {
		return instance;
	}

	/* 10053EE0 */ bool IsMessage();
	/* 10089100 */ MagRelayMachine();
	/* 10089160 */ virtual ~MagRelayMachine();
	/* 100891C0 */ void SendMsg(int param_1);
	/* 100C5C30 */ int GetMessageName();

private:
	/* 0x04 */ std::vector<Message> msgs;
	static MagRelayMachine* instance;
};

STATIC_ASSERT(sizeof(MagRelayMachine) == 0x14);

MagRelayMachine* MagRelayMachine::instance = NULL;

#endif