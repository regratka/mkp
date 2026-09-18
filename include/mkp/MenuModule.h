#ifndef _MENU_MODULE
#define _MENU_MODULE

#include <globals.h>
#include "cMagSprite.h"

class MenuModule : public cMagSprite {
public:
	/* 4164E0 */ void OnButtonUp(cMagKernel* param_1);
	/* 419BA0 */ void OnActivateLevel();
	/* 433FB0 */ MenuModule();
	/* 4340B0 */ virtual ~MenuModule();
	/* 4340C0 */ void OnActivate();
	/* 434500 */ void OnUpdateMenuSettings();
	/* 434560 */ void OnFrame();
	/* 434680 */ void FUN00434680();
	/* 434880 */ void OnMouseArrive(int param_1);
	/* 4349A0 */ void FUN004349a0(bool param_1);
	/* 4349F0 */ void OnMouseLeave();
	/* 434A50 */ void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
	/* 434B40 */ void OnInputKey(uchar* param_1);
	/* 434D30 */ void OnExitYesNo(char* param_1);
	/* 434D80 */ void FUN00434d80();
	/* 434F50 */ void FUN00434f50();
	/* 435000 */ void FUN00435000();
	/* 435040 */ void FUN00435040();
	/* 435070 */ void FUN00435070();
	/* 4351C0 */ void FUN004351c0();
	/* 4351E0 */ void FUN004351e0();
	/* 435260 */ void FUN00435260(int param_1);
	/* 4352B0 */ void OnPlaySoundEnd(int param_1);
};

#endif