#ifndef _C_BLOKADA_LEVEL3
#define _C_BLOKADA_LEVEL3

#include <globals.h>

class CBlokadaLevel3 {
public:
	/* 440A30 */ CBlokadaLevel3();
	/* 440A60 */ uchar scalar_destructor(uchar param_1);
	/* 440A80 */ ~CBlokadaLevel3();
	/* 440A90 */ void* EXP();
	/* 440AF0 */ void OnActivateLevel();
	/* 440B70 */ uchar OnCollisionObject(int* param_1);
	/* 440CA0 */ uchar OnPlaySoundEnd(int param_1);
	/* 440CE0 */ uchar Load(void* param_1, uint param_2, int param_3);
};

#endif