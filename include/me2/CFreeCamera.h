#ifndef _C_FREE_CAMERA
#define _C_FREE_CAMERA

#include <globals.h>

#include "CCamera.h"

class DLLEXPORT CFreeCamera : public CCamera {
public:
	/* 10061C20 */ CFreeCamera();
	/* 10061CE0 */ virtual ~CFreeCamera();
	/* 10061CF0 */ void OnInputKey(uchar* param_1);
	/* 10061D10 */ void OnInputMouse(float param_1, float param_2, bool param_3, bool param_4);
	/* 10061F80 */ double GetUpdate(int param_1);
	/* 10062050 */ virtual void OnActivateView();
	/* 100620C0 */ void SetSpeedValue(float param_1);
	/* 100620D0 */ bool CheckWindowActivation();
	/* 10062120 */ void ReadSettings(char* param_1);

private:
	/* 0xdf0 */ double unk_df0;
	/* 0xdf8 */ double unk_df8;
	/* 0xe00 */ double unk_e00;
	/* 0xe08 */ HWND activeWindow;
	/* 0xe0c */ float freeCameraSpeed;
	/* 0xe10 */ bool unk_e10;
	/* 0xe14 */ float freeCameraAngSpeed;
};

STATIC_ASSERT(sizeof(CFreeCamera) == 0xe18);

#endif