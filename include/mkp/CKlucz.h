#ifndef _C_KLUCZ
#define _C_KLUCZ

#include <globals.h>

class CKlucz {
public:
	/* 432B30 */ CKlucz();
	/* 432B50 */ CKlucz* scalar_destructor(uchar param_1);
	/* 432B70 */ ~CKlucz();
	/* 432B80 */ void* EXP();
	/* 432BE0 */ uchar OnCollisionObject(int* param_1);
	/* 432C40 */ uchar Load(void* param_1, int param_2, int param_3, uint param_4);
	/* 432E70 */ uchar OnActivate();
	/* 432FD0 */ uchar Save(int* param_1);
};

#endif