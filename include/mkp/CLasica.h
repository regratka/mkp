#ifndef _C_LASICA
#define _C_LASICA

#include <globals.h>

class CLasica {
	class Idle {
	public:
		/* 43EBC0 */ void OnEnterState();
		/* 43EC10 */ void OnFrame();
		/* 43ED20 */ uchar OnAnimEnd(char* param_1);
	};

public:
	/* 43E1D0 */ CLasica();
	/* 43E330 */ CLasica* scalar_destructor(uchar param_1);
	/* 43E350 */ ~CLasica();
	/* 43E3E0 */ void* EXP();
	/* 43E440 */ void OnActivateLevel();
	/* 43E520 */ void FUN0043e520();
	/* 43E8D0 */ uchar OnLoadChunk(int param_1, int param_2, uint param_3, void* param_4);
	/* 43ED80 */ uchar FUN0043ed80(char* param_1);
};



#endif