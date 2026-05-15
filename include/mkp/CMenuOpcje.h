#ifndef _C_MENU_OPCJE
#define _C_MENU_OPCJE

#include <globals.h>

#include "cMagSprite.h"

class CMenuOpcje {
public:
	/* 436D70 */ CMenuOpcje();
	/* 436ED0 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 436EF0 */ ~CMenuOpcje();
	/* 436F50 */ void OnActivate();
	/* 437ED0 */ void OnFrame();
	/* 437FC0 */ void OnActivateLevel();
	/* 4384A0 */ uchar OnButtonDown(void* param_1);
	/* 438A10 */ uchar OnInputKey(int param_1);
	/* 4391F0 */ uchar OnButtonUp(int param_1);
	/* 439280 */ uchar OnInputMouse(uint param_1, uint param_2, bool param_3);
	/* 439DE0 */ uchar OnMouseArrive(int param_1);
	/* 439E30 */ uchar OnMouseLeave(int param_1);
};

#endif