#ifndef _U_I_EDIT
#define _U_I_EDIT

#include <globals.h>
#include "cMagSprite.h"

class UIEdit : public cMagSprite{
public:
	/* 412380 */ uchar scalar_destructor(uchar param_1);
	/* 4123A0 */ UIEdit(char* param_1, cMagSprite* param_2);
	/* 412610 */ ~UIEdit();
	/* 4126F0 */ void OnActivate();
	/* 412770 */ void FUN00412770(bool param_1);
	/* 4127D0 */ void FUN004127d0(cMagSprite* param_1);
	/* 4127E0 */ void FUN004127e0(float param_1, float param_2);
	/* 412830 */ void FUN00412830(float param_1, float param_2);
	/* 412910 */ void FUN00412910(char* param_1);
	/* 412A20 */ char* FUN00412a20(bool param_1);
	/* 412B30 */ void OnInputChar(char param_1);
	/* 412E10 */ void OnInputKey(int param_1);
	/* 412E60 */ void OnInputMouse(uint param_1, uint param_2, char param_3);
	/* 413060 */ void FUN00413060();

private:
	/* 0x1740 */ uchar field_0x1740[0x1b08-0x1740];
};

STATIC_ASSERT(sizeof(UIEdit) == 0x1b08);

#endif