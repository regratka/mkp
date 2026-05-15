#ifndef _C_SAMOUCZEK
#define _C_SAMOUCZEK

#include <globals.h>

class CSamouczek {
public:
	/* 442A80 */ CSamouczek();
	/* 442AB0 */ CSamouczek* scalar_destructor(uchar param_1);
	/* 442AD0 */ ~CSamouczek();
	/* 442AE0 */ void* EXP();
	/* 442B40 */ void OnActivateLevel();
	/* 442B70 */ uchar OnCollisionObject(int* param_1);
};

#endif