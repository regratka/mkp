#ifndef _C_MENU_HUD
#define _C_MENU_HUD

#include <globals.h>
#include "cMagSprite.h"

class CMenuHud {
public:
	/* 413E60 */ CMenuHud();
	/* 413F90 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 413FB0 */ ~CMenuHud();
	/* 413FE0 */ void OnActivate();
	/* 414580 */ uchar OnMouseArrive(int param_1);
	/* 414730 */ void OnMouseLeave(cMagKernel* param_1);
	/* 4147C0 */ uchar OnButtonDown(int param_1);
	/* 414970 */ void OnFadeOutEnd();
	/* 414EF0 */ void OnActivateLevel();
	/* 415080 */ void OnFrame();
	/* 415150 */ void FUN00415150();
};

#endif