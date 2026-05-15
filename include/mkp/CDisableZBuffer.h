#ifndef _C_DISABLE_Z_BUFFER
#define _C_DISABLE_Z_BUFFER

#include <globals.h>

class CDisableZBuffer {
public:
	/* 441D60 */ CDisableZBuffer();
	/* 441D80 */ CDisableZBuffer* scalar_destructor(uchar param_1);
	/* 441DA0 */ ~CDisableZBuffer();
	/* 441DB0 */ void* EXP();
	/* 441E10 */ void OnActivateLevel();
};

#endif