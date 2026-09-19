#ifndef _C_MENU_OPCJE
#define _C_MENU_OPCJE

#include <globals.h>

#include "cMagSprite.h"

class MenuModule;
class UIButton;

class CMenuOpcje : public cMagSprite {
public:
	/* 436D70 */ CMenuOpcje();
	/* 436ED0 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 436EF0 */ ~CMenuOpcje();
	/* 436F50 */ void OnActivate();
	/* 437C70 */ void FUN00437c70();
	/* 437DE0 */ void FUN00437de0();
	/* 437E90 */ void FUN00437e90(CMenuOpcje* param_1);
	/* 437ED0 */ void OnFrame();
	/* 437FC0 */ void OnActivateLevel();
	/* 438010 */ void FUN00438010(MenuModule* param_1);
	/* 4381C0 */ void FUN004381c0();
	/* 4384A0 */ void OnButtonDown(cMagKernel* param_1);
	/* 4387F0 */ void FUN004387f0();
	/* 438A10 */ void OnInputKey(int param_1);
	/* 439050 */ void FUN00439050(int param_1, char* param_2);
	/* 4390B0 */ void FUN004390b0();
	/* 439160 */ void FUN00439160();
	/* 4391F0 */ void OnButtonUp(cMagKernel* param_1);
	/* 439280 */ void OnInputMouse(uint param_1, uint param_2, bool param_3);
	/* 4392F0 */ void FUN004392f0(UIButton* param_1, bool param_2);
	/* 4393D0 */ void FUN004393d0();
	/* 439620 */ void FUN00439620(bool param_1);
	/* 4398D0 */ void FUN004398d0();
	/* 439DE0 */ void OnMouseArrive(int param_1);
	/* 439E30 */ void OnMouseLeave(int param_1);

public:
	/* 0x1740 */ MenuModule* menuModule;
	/* 0x1744 */ uchar field_0x1744[0x1b50 - 0x1744];
};

#endif