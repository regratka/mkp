#ifndef _C_WHEEL
#define _C_WHEEL

#include <globals.h>

#include "cMagGameObject.h"

class CWheel {
public:
	/* 100B6060 */ uint* FUN100b6060(uchar param_1);
	/* 100B6080 */ CWheel(cMagGameObject* param_1, uchar* param_2, char* param_3, uint param_4);
	/* 100B62B0 */ ~CWheel();
	/* 100B62C0 */ uchar FUN100b62c0(float param_1);
	/* 100B63D0 */ uchar FUN100b63d0();
	/* 100B6440 */ uchar FUN100b6440(float param_1);
	/* 100B65D0 */ uint* FUN100b65d0(uint* param_1);
	/* 100B65F0 */ uchar FUN100b65f0(uint param_1);
};

#endif