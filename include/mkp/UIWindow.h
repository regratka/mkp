#ifndef _U_I_WINDOW
#define _U_I_WINDOW

#include <globals.h>
#include "cMagSprite.h"

class UIWindow {
public:
	/* 4133E0 */ UIWindow();
	/* 413450 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 413470 */ UIWindow(uint param_1);
	/* 4134D0 */ ~UIWindow();
	/* 413720 */ void OnFrame();
	/* 4138C0 */ uchar OnMouseArrive(uint param_1);
	/* 4138E0 */ uchar OnMouseLeave(uint param_1);
};

#endif