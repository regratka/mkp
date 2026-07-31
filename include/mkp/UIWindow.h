#ifndef _U_I_WINDOW
#define _U_I_WINDOW

#include <globals.h>
#include "cMagSprite.h"

class UIWindow : public cMagSprite {
public:
	/* 4133E0 */ UIWindow();
	/* 413450 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 413470 */ UIWindow(cMagSprite* param_1);
	/* 4134D0 */ ~UIWindow();
	/* 4134E0 */ void FUN004134e0(char* param_1);
	/* 413510 */ void FUN00413510(bool param_1);
	/* 413540 */ void FUN00413540(D3DXVECTOR2 param_1);
	/* 413560 */ void FUN00413560(D3DXVECTOR2 param_1);
	/* 413580 */ void FUN00413580(bool param_1);
	/* 413720 */ void OnFrame();
	/* 4138C0 */ uchar OnMouseArrive(uint param_1);
	/* 4138E0 */ uchar OnMouseLeave(uint param_1);

private:
	/* 0x1740 */ uchar field_0x1740[0x1770-0x1740];
};

STATIC_ASSERT(sizeof(UIWindow) == 0x1770);


#endif