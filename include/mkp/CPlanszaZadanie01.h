#ifndef _C_PLANSZA_ZADANIE01
#define _C_PLANSZA_ZADANIE01

#include <globals.h>

class CPlanszaZadanie01 {
public:
	/* 420880 */ CPlanszaZadanie01();
	/* 420960 */ CPlanszaZadanie01* scalar_destructor(uchar param_1);
	/* 420980 */ ~CPlanszaZadanie01();
	/* 420990 */ void* EXP();
	/* 4209F0 */ void OnActivate();
	/* 420AE0 */ void OnActivateLevel();
	/* 421640 */ void OnFrame();
	/* 421790 */ uchar OnMouseArrive(int param_1);
	/* 421880 */ uchar OnMouseLeave(int param_1);
	/* 4218C0 */ uchar OnInputMouse(uint param_1, uint param_2, char param_3);
	/* 421B00 */ uchar OnPlaySoundEnd(int param_1);
	/* 421D80 */ uchar OnCollisionObject(int* param_1);
	/* 421DD0 */ uchar Load(void* param_1, uint param_2, int param_3);
	/* 426300 */ uchar Save(int* param_1);
};

#endif