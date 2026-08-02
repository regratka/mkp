#ifndef _MENU_MODULE
#define _MENU_MODULE

#include <globals.h>

class MenuModule {
public:
	/* 433FB0 */ MenuModule();
	/* 434090 */ cMagSprite* scalar_destructor(uchar param_1);
	/* 4340B0 */ ~MenuModule();
	/* 4340C0 */ void OnActivate();
	/* 434500 */ void OnUpdateMenuSettings();
	/* 434560 */ void OnFrame();
	/* 434880 */ uchar OnMouseArrive(int param_1);
	/* 4349A0 */ void FUN004349a0(bool param_1);
	/* 4349F0 */ void OnMouseLeave();
	/* 434A50 */ uchar OnInputMouse(uint param_1, uint param_2, char param_3);
	/* 434B40 */ uchar OnInputKey(int param_1);
	/* 434D30 */ uchar OnExitYesNo(char* param_1);
	/* 4351C0 */ void FUN004351c0();
	/* 4352B0 */ uchar OnPlaySoundEnd(int param_1);
};

#endif