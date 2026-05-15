#ifndef C_MENU_LOGO
#define C_MENU_LOGO

#include <globals.h>
#include "cMagSprite.h"

class cMenuLogo {
public:
	/* 433B50 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 433B70 */ cMenuLogo(int* param_1);
	/* 433B90 */ ~cMenuLogo();
	/* 433BA0 */ void OnActivate();
	/* 433CD0 */ void OnFadeOutEnd();
	/* 433D80 */ void OnFrame();
	/* 433DD0 */ uchar OnInputKey(int param_1);
};

#endif