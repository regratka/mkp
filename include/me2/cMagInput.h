#ifndef C_MAG_INPUT
#define C_MAG_INPUT

#include <globals.h>
#include <windows.h>

class cMagInput {
public:
	/* 10001080 */ cMagInput();
	/* 100010A0 */ cMagInput* operator=(cMagInput* param_1);
	/* 1002CE60 */ bool Init(HWND__* param_1, HINSTANCE__* param_2);
	/* 1002CF90 */ bool Kill();
	/* 1002CFF0 */ bool Update();
	/* 1002D0D0 */ bool IsKeyDown();
};

#endif