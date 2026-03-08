#ifndef C_MAG_INPUT
#define C_MAG_INPUT

#include <globals.h>
#include <windows.h>

#include "cMagLog.h"

class cMagInput {
public:
	/* 10001080 */ cMagInput();
	/* 100010A0 */ cMagInput* operator=(cMagInput* param_1);
	/* 1002CE60 */ bool Init(HWND__* param_1, HINSTANCE__* param_2);
	/* 1002CF90 */ bool Kill();
	/* 1002CFF0 */ bool Update();
	/* 1002D0D0 */ bool IsKeyDown();

public:
	/* 0x00 */ uchar f_00[0x1c - 0x00];
	/* 0x1c */ uchar unkn_1c;
	/* 0x1d */ uchar f_01d[0x11c - 0x1d];
	/* 0x11c */ float unkn_11c;
	/* 0x120 */ float unkn_120;
	/* 0x124 */ uchar f_124[0x128 - 0x124];
	/* 0x128 */ bool unkn_128;
	/* 0x129 */ bool unkn_129;
	/* 0x12c */ cMagLog log;

};

STATIC_ASSERT(sizeof(cMagInput) == 0x134);

#endif