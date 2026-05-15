#ifndef _MENU_OKNO_WYBORU__C_Z1
#define _MENU_OKNO_WYBORU__C_Z1

#include <globals.h>
#include "cMagSprite.h"

class MenuOknoWyboru_CZ1 {
public:
	/* 435380 */ MenuOknoWyboru_CZ1();
	/* 435460 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 435480 */ ~MenuOknoWyboru_CZ1();
	/* 435490 */ void OnActivate();
	/* 435B80 */ void OnFrame();
	/* 435E60 */ uchar OnMouseArrive(int param_1);
	/* 435FA0 */ uchar OnMouseLeave(int param_1);
	/* 435FF0 */ uchar OnInputMouse(uint param_1, uint param_2, char param_3);
	/* 436160 */ void OnActivateLevel();
};

#endif