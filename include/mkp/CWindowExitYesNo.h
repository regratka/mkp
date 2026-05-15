#ifndef _C_WINDOW_EXIT_YES_NO
#define _C_WINDOW_EXIT_YES_NO

#include <globals.h>
#include "cMagSprite.h"

class CWindowExitYesNo {
public:
	/* 4264A0 */ CWindowExitYesNo();
	/* 426530 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 426550 */ ~CWindowExitYesNo();
	/* 426560 */ void OnActivate();
	/* 426EB0 */ void OnFrame();
	/* 427030 */ uchar OnMouseArrive(int param_1);
	/* 427130 */ uchar OnMouseLeave(int param_1);
	/* 427190 */ uchar OnInputMouse(uint param_1, uint param_2, char param_3);
};

#endif