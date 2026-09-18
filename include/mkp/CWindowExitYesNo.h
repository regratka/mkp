#ifndef _C_WINDOW_EXIT_YES_NO
#define _C_WINDOW_EXIT_YES_NO

#include <globals.h>
#include "cMagSprite.h"

class MenuModule;

class CWindowExitYesNo {
public:
	/* 4264A0 */ CWindowExitYesNo();
	/* 426530 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 426550 */ ~CWindowExitYesNo();
	/* 426560 */ void OnActivate();
	/* 4269E0 */ void FUN004269e0(MenuModule* param_1);
	/* 426B70 */ void FUN00426b70();
	/* 426C40 */ bool FUN00426c40();
	/* 426C50 */ void FUN00426c50();
	/* 426DC0 */ void FUN00426dc0();
	/* 426E70 */ void FUN00426e70();
	/* 426EB0 */ void OnFrame();
	/* 426FA0 */ void FUN00426fa0();
	/* 427030 */ void OnMouseArrive(int param_1);
	/* 427130 */ void OnMouseLeave(int param_1);
	/* 427190 */ void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
};

#endif