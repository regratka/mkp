#ifndef C_MENU_LOGO
#define C_MENU_LOGO

#include <globals.h>
#include <algorithm>

#include "cMagSprite.h"
#include "MenuModule.h"
#include "cFadeInOut.h"

class cMenuLogo : public cMagSprite {
public:
	/* 419BA0 */ void OnActivateLevel();
	/* 419BA0 */ void OnFadeInEnd();
	/* 433B70 */ cMenuLogo(MenuModule* param_1);
	/* 433B90 */ virtual ~cMenuLogo();
	/* 433BA0 */ void OnActivate();
	/* 433C10 */ void FUN00433c10();
	/* 433CD0 */ void OnFadeOutEnd();
	/* 433D80 */ void OnFrame();
	/* 433DD0 */ void OnInputKey(uchar* param_1);

private:
	/* 0x1740 */ int logoEgmontTexID;
	/* 0x1744 */ int logoGratkaTexID;
	/* 0x1748 */ uchar field_0x1748[0x174c-0x1748];
	/* 0x174c */ int madefadesOut;
	/* 0x1750 */ float timeFromLastFade;
	/* 0x1754 */ MenuModule* menuModule;
	/* 0x1758 */ cFadeInOut* fadeInOut;
	/* 0x175c */ uchar field_0x175c[0x1760-0x175c];
};

STATIC_ASSERT(sizeof(cMenuLogo) == 0x1760);

#endif