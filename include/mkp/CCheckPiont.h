#ifndef _C_CHECK_PIONT
#define _C_CHECK_PIONT

#include <globals.h>
#include "cMagMeshObject.h"

class CCheckPiont {
public:
	/* 432930 */ CCheckPiont();
	/* 432950 */ CCheckPiont* scalar_destructor(uchar param_1);
	/* 432970 */ ~CCheckPiont();
	/* 432980 */ void* EXP();
	/* 4329F0 */ uchar OnCollisionObject(cMagMeshObject* param_1);
};

#endif