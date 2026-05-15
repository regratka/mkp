#ifndef _C_PLANSZA_EDU
#define _C_PLANSZA_EDU

#include <globals.h>

class CPlanszaEdu {
public:
	/* 41DF80 */ CPlanszaEdu();
	/* 41E070 */ CPlanszaEdu* scalar_destructor(uchar param_1);
	/* 41E090 */ ~CPlanszaEdu();
	/* 41E0A0 */ void* EXP();
	/* 41E100 */ void OnActivate();
	/* 41E1B0 */ uchar OnActivateLevel();
	/* 41FA70 */ uchar OnPlaySoundEnd(int param_1);
	/* 41FAA0 */ uchar OnInputMouse(uint param_1, uint param_2, char param_3);
	/* 41FAD0 */ uchar OnInputKey(int param_1);
	/* 41FCC0 */ void FUN0041fcc0();
	/* 420260 */ uchar OnMouseArrive(int param_1);
	/* 4205A0 */ uchar OnMouseLeave(int param_1);
	/* 4205E0 */ void OnFrame();
	/* 420730 */ uchar OnCollisionObject(int* param_1);
	/* 4207A0 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
};

#endif