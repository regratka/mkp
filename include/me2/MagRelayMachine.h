#ifndef _MAG_RELAY_MACHINE
#define _MAG_RELAY_MACHINE

#include <globals.h>

class MagRelayMachine {
public:
	/* 10006180 */ MagRelayMachine(MagRelayMachine* param_1);
	/* 10006240 */ MagRelayMachine* operator=(MagRelayMachine* param_1);
	/* 100063F0 */ MagRelayMachine* scalar_destructor(uchar param_1);
	/* 10053EE0 */ bool IsMessage();
	/* 10089100 */ MagRelayMachine();
	/* 10089160 */ ~MagRelayMachine();
	/* 100891C0 */ void SendMsg(int param_1);
	/* 100C5C30 */ int GetMessageName();
};

#endif