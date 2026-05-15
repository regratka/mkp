#ifndef C_POCISK
#define C_POCISK

#include <globals.h>

class cPocisk {
public:
	/* 43DE80 */ cPocisk();
	/* 43DEA0 */ uchar scalar_destructor(uchar param_1);
	/* 43DEC0 */ ~cPocisk();
	/* 43DED0 */ uchar OnCollisionObject(int* param_1);
	/* 43DF70 */ void OnActivate();
	/* 43DFD0 */ void OnFrame();
};

#endif