#ifndef _C_MONETA
#define _C_MONETA

#include <globals.h>

class CMoneta {
public:
	/* 432F20 */ uchar FUN00432f20();
	/* 4331C0 */ CMoneta();
	/* 4331E0 */ CMoneta* scalar_destructor(uchar param_1);
	/* 433200 */ ~CMoneta();
	/* 433210 */ void* EXP();
	/* 433270 */ uchar OnCollisionObject(uchar param_1);
	/* 4332E0 */ uchar Save(int* param_1);
	/* 433390 */ uchar Load(void* param_1, int param_2, int param_3);
};

#endif