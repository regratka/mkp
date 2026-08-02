#ifndef _MENU_OKNO_WYBORU__C_Z1
#define _MENU_OKNO_WYBORU__C_Z1

#include <globals.h>

#include "cMagSprite.h"
#include "MenuModule.h"

class MenuOknoWyboru_CZ1 : public cMagSprite {
public:
	/* 435380 */ MenuOknoWyboru_CZ1();
	/* 435480 */ virtual ~MenuOknoWyboru_CZ1();
	/* 435490 */ void OnActivate();
	/* 435B60 */ void FUN00435b60(MenuModule* param_1);
	/* 435B80 */ void OnFrame();
	/* 435C90 */ void FUN00435c90();
	/* 435D40 */ void FUN00435d40();
	/* 435E60 */ void OnMouseArrive(int param_1);
	/* 435FA0 */ void OnMouseLeave(int param_1);
	/* 435FF0 */ void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
	/* 436160 */ void OnActivateLevel();
	/* 436330 */ void FUN00436330();
	/* 4363E0 */ void FUN004363e0();
	/* 436420 */ void FUN00436420();
	/* 436450 */ void FUN00436450();
	/* 4368C0 */ void FUN004368c0();
};

#endif