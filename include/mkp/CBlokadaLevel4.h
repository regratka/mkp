#ifndef _C_BLOKADA_LEVEL4
#define _C_BLOKADA_LEVEL4

#include <globals.h>

#include "cMagKernel.h"

class CBlokadaLevel4 {
public:
	/* 441000 */ CBlokadaLevel4();
	/* 441030 */ uchar scalar_destructor(uchar param_1);
	/* 441050 */ ~CBlokadaLevel4();
	/* 441060 */ void* EXP();
	/* 4410C0 */ void OnActivateLevel();
	/* 441170 */ uchar OnPlaySoundEnd(cMagKernel* param_1);
	/* 4411B0 */ uchar OnCollisionObject(int* param_1);
};

#endif