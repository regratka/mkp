#ifndef _C_BLOKADA_LEVEL1
#define _C_BLOKADA_LEVEL1

#include <globals.h>

class CBlokadaLevel1 {
public:
	/* 4406C0 */ CBlokadaLevel1();
	/* 4406E0 */ uchar scalar_destructor(uchar param_1);
	/* 440700 */ ~CBlokadaLevel1();
	/* 440710 */ void* EXP();
	/* 440770 */ void OnActivateLevel();
	/* 4407D0 */ uchar OnCollisionObject(int* param_1);
	/* 4408B0 */ uchar Save(int* param_1);
	/* 4414D0 */ uchar OnPlaySoundEnd(int param_1);
	/* 441920 */ uchar Load(void* param_1, uint param_2, int param_3);
};

#endif