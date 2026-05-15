#ifndef _C_PLANSZA_ZADANIE02
#define _C_PLANSZA_ZADANIE02

#include <globals.h>

class CPlanszaZadanie02 {
public:
	/* 421EC0 */ CPlanszaZadanie02();
	/* 421FD0 */ CPlanszaZadanie02* scalar_destructor(uchar param_1);
	/* 421FF0 */ ~CPlanszaZadanie02();
	/* 422000 */ void* EXP();
	/* 422060 */ void OnActivate();
	/* 422150 */ void OnActivateLevel();
	/* 422EA0 */ uchar OnInputMouse(uint param_1, uint param_2, char param_3);
	/* 423410 */ uchar OnPlaySoundEnd(int param_1);
	/* 423490 */ void OnFrame();
	/* 4236B0 */ uchar OnMouseArrive(int param_1);
	/* 4237C0 */ uchar OnMouseLeave(int param_1);
	/* 423800 */ uchar OnCollisionObject(int* param_1);
	/* 423850 */ uchar Load(void* param_1, uint param_2, int param_3);
};

#endif