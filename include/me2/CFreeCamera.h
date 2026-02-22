#ifndef _C_FREE_CAMERA
#define _C_FREE_CAMERA

#include <globals.h>

class CFreeCamera {
public:
	/* 1000BFF0 */ CFreeCamera(CFreeCamera* param_1);
	/* 1000C120 */ CFreeCamera* operator=(CFreeCamera* param_1);
	/* 1000C240 */ CFreeCamera* scalar_destructor(uchar param_1);
	/* 10061C20 */ CFreeCamera();
	/* 10061CE0 */ ~CFreeCamera();
	/* 10061CF0 */ void OnInputKey(uchar* param_1);
	/* 10061D10 */ void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
	/* 10061F80 */ double GetUpdate(int param_1);
	/* 10062050 */ void OnActivateView();
	/* 100620C0 */ void SetSpeedValue(float param_1);
	/* 100620D0 */ bool CheckWindowActivation();
	/* 10062120 */ void ReadSettings(char* param_1);
};

#endif