#ifndef _C_ARMATA
#define _C_ARMATA

#include <globals.h>

class CArmata {
public:
	/* 4262D0 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
	/* 439F40 */ CArmata();
	/* 43A010 */ uchar scalar_destructor(uchar param_1);
	/* 43A030 */ ~CArmata();
	/* 43A0B0 */ void* EXP();
	/* 43A110 */ void OnActivate();
	/* 43A150 */ void OnActivateLevel();
	/* 43A1B0 */ uchar FUN0043a1b0(float param_1);
	/* 43A280 */ void OnInputKey(uchar* param_1);
	/* 43A7E0 */ uchar FUN0043a7e0();
	/* 43A890 */ uchar FUN0043a890();
	/* 43A900 */ uchar FUN0043a90();
	/* 43AB90 */ uchar FUN0043ab90(float param_1);
};

#endif