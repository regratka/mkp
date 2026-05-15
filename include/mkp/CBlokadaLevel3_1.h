#ifndef _C_BLOKADA_LEVEL3_1
#define _C_BLOKADA_LEVEL3_1

#include <globals.h>

class CBlokadaLevel3_1 {
public:
	/* 4329E0 */ void OnActivateLevel();
	/* 440E10 */ CBlokadaLevel3_1();
	/* 440E30 */ uchar scalar_destructor(uchar param_1);
	/* 440E50 */ ~CBlokadaLevel3_1();
	/* 440E60 */ void* EXP();
	/* 440EC0 */ uchar OnCollisionObject(int* param_1);
};

#endif