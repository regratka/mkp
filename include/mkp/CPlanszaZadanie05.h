#ifndef _C_PLANSZA_ZADANIE05
#define _C_PLANSZA_ZADANIE05

#include <globals.h>
#include "cMagGameObject.h"

class CPlanszaZadanie05 {
public:
	/* 424570 */ uchar OnMouseLeave(int param_1);
	/* 424E30 */ CPlanszaZadanie05();
	/* 424F00 */ CPlanszaZadanie05* scalar_destructor(uchar param_1);
	/* 424F20 */ ~CPlanszaZadanie05();
	/* 424F30 */ void* EXP();
	/* 424F90 */ uchar OnActivate(uchar param_1);
	/* 425080 */ void OnActivateLevel();
	/* 425A10 */ uchar OnPlaySoundEnd(int param_1);
	/* 425E10 */ uchar OnFrame(cMagGameObject* param_1);
	/* 425F60 */ uchar OnMouseArrive(int param_1);
	/* 426050 */ uchar OnInputMouse(uint param_1, uint param_2, char param_3);
	/* 426280 */ uchar OnCollisionObject(int* param_1);
	/* 4263B0 */ uchar Load(void* param_1, uint param_2, int param_3);
};

#endif