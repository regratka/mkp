#ifndef _C_BLOKADA_LEVEL5
#define _C_BLOKADA_LEVEL5

#include <globals.h>

class CBlokadaLevel5 {
public:
	/* 4415C0 */ CBlokadaLevel5();
	/* 4415F0 */ uchar scalar_destructor(uchar param_1);
	/* 441610 */ ~CBlokadaLevel5();
	/* 441620 */ void* EXP();
	/* 441680 */ uchar OnCollisionObject(int* param_1);
	/* 441860 */ uchar OnActivateLevel(uchar param_1);
	/* 441900 */ uchar OnPlaySoundEnd(int param_1);
};

#endif