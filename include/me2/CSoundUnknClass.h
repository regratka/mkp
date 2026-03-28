#ifndef _C_SOUND_UNKN_CLASS
#define _C_SOUND_UNKN_CLASS

#include <globals.h>

class CSoundUnknClass {
public:
	/* 1009BC90 */ CSoundUnknClass();
	/* 1009BCB0 */ ~CSoundUnknClass();
	/* 1009BCE0 */ uint FUN1009bce0(char* param_1, short* param_2, int param_3);
	/* 1009BED0 */ uint FUN1009bed0();

private:
	/* 0x00 */ uchar f_00[0x94-0x00];
};

STATIC_ASSERT(sizeof(CSoundUnknClass) == 0x94);

#endif