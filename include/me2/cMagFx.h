#ifndef C_MAG_FX
#define C_MAG_FX

#include <globals.h>

struct TIMER_COMMAND {

};

class cMagFx {
public:
	/* 10023440 */ cMagFx(cMagFx* param_1);
	/* 100237A0 */ cMagFx* operator=(cMagFx* param_1);
	/* 10023B00 */ cMagFx* scalar_destructor(uchar param_1);
	/* 10077490 */ cMagFx();
	/* 100777B0 */ ~cMagFx();
	/* 100777C0 */ void SetPosition(uint param_1, uint param_2, uint param_3);
	/* 10077850 */ void SetScale(uint param_1, uint param_2, uint param_3);
	/* 100778E0 */ void AddTexture(char* param_1);
	/* 10077940 */ void Restore();
	/* 10077970 */ void OnRender();
	/* 10077BB0 */ float DXUtil_Timer(TIMER_COMMAND param_1);
};

#endif