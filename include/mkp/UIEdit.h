#ifndef _U_I_EDIT
#define _U_I_EDIT

#include <globals.h>

class UIEdit {
public:
	/* 412380 */ uchar scalar_destructor(uchar param_1);
	/* 4123A0 */ UIEdit(char* param_1, uint param_2);
	/* 412610 */ ~UIEdit();
	/* 4126F0 */ void OnActivate();
	/* 412A20 */ void FUN00412a20(bool param_1);
	/* 412B30 */ uchar OnInputChar(char param_1);
	/* 412E10 */ uchar OnInputKey(int param_1);
	/* 412E60 */ uchar OnInputMouse(uint param_1, uint param_2, char param_3);
};

#endif