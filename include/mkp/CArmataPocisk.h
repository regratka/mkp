#ifndef _C_ARMATA_POCISK
#define _C_ARMATA_POCISK

#include <globals.h>

class CArmataPocisk {
public:
	/* 43B090 */ CArmataPocisk();
	/* 43B0B0 */ uchar scalar_destructor(uchar param_1);
	/* 43B0D0 */ ~CArmataPocisk();
	/* 43B0E0 */ void OnActivate();
	/* 43B1A0 */ uchar FUN0043b1a0(uint param_1, uint param_2, uint param_3, uint param_4, uint param_5, uint param_6);
	/* 43B1F0 */ void OnCollisionObject();
};

#endif