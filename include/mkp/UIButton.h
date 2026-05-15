#ifndef _U_I_BUTTON
#define _U_I_BUTTON

#include <globals.h>

#include "cMagSprite.h"

class UIButton {
public:
	/* 411860 */ UIButton();
	/* 411970 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 411990 */ ~UIButton();
	/* 411FF0 */ uchar OnMouseArrive(int param_1);
	/* 412090 */ uchar OnMouseLeave(int param_1);
	/* 412160 */ uchar OnInputMouse(uint param_1, uint param_2, char param_3);
};

#endif