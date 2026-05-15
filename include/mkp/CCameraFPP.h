#ifndef _C_CAMERA_F_P_P
#define _C_CAMERA_F_P_P

#include <globals.h>
#include "CFreeCamera.h"

class CCameraFPP {
public:
	/* 404870 */ CCameraFPP();
	/* 4048A0 */ CFreeCamera* scalar_destructor(uchar param_1);
	/* 4048C0 */ ~CCameraFPP();
	/* 4048D0 */ uchar OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
	/* 404900 */ void OnActivateView();
	/* 404920 */ void FUN00404920();
};

#endif