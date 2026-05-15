#ifndef _C_ELEVATOR
#define _C_ELEVATOR

#include <globals.h>

class CElevator {
public:
	/* 41AFD0 */ CElevator();
	/* 41B050 */ CElevator* scalar_destructor(uchar param_1);
	/* 41B070 */ ~CElevator();
	/* 41B100 */ void* EXP();
	/* 41B160 */ void OnFrame();
	/* 41B320 */ void OnUpdateMenuSettings();
	/* 41B350 */ void OnActivate();
	/* 41B360 */ void OnDestinationPos();
	/* 41B3B0 */ void OnAction();
	/* 41B4E0 */ uchar OnCollisionObject(int* param_1);
	/* 41B500 */ uchar OnAttachChild(int* param_1);
	/* 41B530 */ uchar OnDetachChild(int* param_1);
	/* 41B560 */ void OnActivateLevel();
	/* 41B600 */ void OnCrash();
	/* 41B630 */ uchar OnLoadChunk(int param_1, int param_2, uint param_3, void* param_4);
	/* 41B940 */ uchar Save(int* param_1);
	/* 41BA60 */ uchar Load(void* param_1, uint param_2, int param_3);
};

#endif