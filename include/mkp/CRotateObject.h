#ifndef _C_ROTATE_OBJECT
#define _C_ROTATE_OBJECT

#include <globals.h>

class CRotateObject {
public:
	/* 419320 */ CRotateObject();
	/* 419350 */ CRotateObject* scalar_destructor(uchar param_1);
	/* 419370 */ ~CRotateObject();
	/* 419380 */ void* EXP();
	/* 4193E0 */ void OnActivateLevel();
	/* 4194F0 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
};

#endif