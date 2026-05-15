#ifndef _C_PLAYER_R_P_G
#define _C_PLAYER_R_P_G

#include <globals.h>

class CPlayerRPG {
	
class Idle {
public:
	/* 40FEA0 */ void OnEnterState();
	/* 40FEF0 */ void OnFrame();
};

class Walk {
public:
	/* 40FC90 */ void OnEnterState();
	/* 40FCF0 */ void OnFrame();
	/* 40FDF0 */ void OnDestinationPos();
	/* 40FE60 */ void OnCollisionObject();
	/* 40FE80 */ uchar OnAnimEnd(char* param_1);
};

public:
	/* 40F0C0 */ CPlayerRPG();
	/* 40F0F0 */ CPlayerRPG* scalar_destructor(uchar param_1);
	/* 40F110 */ ~CPlayerRPG();
	/* 40F120 */ void* EXP();
	/* 40F180 */ void OnActivate();
	/* 40F1D0 */ void OnActivateLevel();
	/* 40F7A0 */ uchar OnInputMouse(uint param_1, uint param_2, char param_3, char param_4);
	/* 40F860 */ void OnFrame();
};

#endif