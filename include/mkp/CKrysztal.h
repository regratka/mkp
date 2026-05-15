#ifndef _C_KRYSZTAL
#define _C_KRYSZTAL

#include <globals.h>

class CKrysztal {
public:
	/* 432DB0 */ CKrysztal();
	/* 432DD0 */ CKrysztal* scalar_destructor(uchar param_1);
	/* 432DF0 */ ~CKrysztal();
	/* 432E00 */ void* EXP();
	/* 432F70 */ uchar OnCollisionObject(int* param_1);
	/* 433090 */ uchar Load(void* param_1, int param_2, int param_3, uint param_4);
};

#endif