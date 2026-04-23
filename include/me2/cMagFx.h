#ifndef C_MAG_FX
#define C_MAG_FX

#include <globals.h>

#include "cFX_Shockwave.h"

struct TIMER_COMMAND {

};

class __declspec(dllexport) cMagFx : public cFX_Shockwave {
public:
	/* 10077490 */ cMagFx();
	/* 100777B0 */ virtual ~cMagFx();
	/* 100777C0 */ void SetPosition(D3DXVECTOR3 param_1);
	/* 10077850 */ void SetScale(D3DXVECTOR3 param_1);
	/* 100778E0 */ void AddTexture(char* param_1);
	/* 10077940 */ void Restore();
	/* 10077970 */ void OnRender();
	/* 10077BB0 */ float DXUtil_Timer(TIMER_COMMAND param_1);

private:
	/* 0xd88 */ char shockwaveName[255];
	/* 0xe87 */ uchar field_0xe87[0x1080-0xe87];
};

STATIC_ASSERT(sizeof(cMagFx) == 0x1080);

#endif