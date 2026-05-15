#ifndef _C_PLANSZA_ZADANIE04
#define _C_PLANSZA_ZADANIE04

#include <globals.h>

class CPlanszaZadanie04 {
public:
	/* 423940 */ CPlanszaZadanie04();
	/* 4239F0 */ CPlanszaZadanie04* scalar_destructor(uchar param_1);
	/* 423A10 */ ~CPlanszaZadanie04();
	/* 423A20 */ void* EXP();
	/* 423A80 */ void OnActivate();
	/* 423B70 */ void OnActivateLevel();
	/* 424290 */ uchar OnPlaySoundEnd(int param_1);
	/* 424480 */ uchar OnMouseArrive(int param_1);
	/* 4245B0 */ uchar OnInputMouse(uint param_1, uint param_2, char param_3);
	/* 424920 */ void OnFrame();
	/* 424CF0 */ uchar OnCollisionObject(int* param_1);
	/* 424D40 */ uchar Load(void* param_1, uint param_2, int param_3);
};

#endif