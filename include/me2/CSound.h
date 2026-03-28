#ifndef _C_SOUND
#define _C_SOUND

#include <globals.h>

class CSound {
public:
	/* 1009B910 */ CSound(int param_1, uint param_2, uint param_3, uint param_4);
	/* 1009B9B0 */ virtual ~CSound();
	/* 1009BA20 */ int FUN_1009ba20(int* param_1);

private:
	/* 0x04 */ uchar f_04[0x14-0x04];
};

STATIC_ASSERT(sizeof(CSound) == 0x14);

#endif