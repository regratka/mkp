#ifndef C_MAG_FX
#define C_MAG_FX

#include <globals.h>

#include "cFX_Shockwave.h"


class DLLEXPORT cMagFx : public cFX_Shockwave {
public:
    // populated based on dxutil.cpp TIMER_COMMAND
	enum TIMER_COMMAND { 
		TIMER_RESET, 
		TIMER_START, 
		TIMER_STOP, 
		TIMER_ADVANCE,
        TIMER_GETABSOLUTETIME, 
		TIMER_GETAPPTIME, 
		TIMER_GETELAPSEDTIME 
	};

	/* 10077490 */ cMagFx();
	/* 100777B0 */ virtual ~cMagFx();
	/* 100777C0 */ void SetPosition(D3DXVECTOR3 param_1);
	/* 10077850 */ void SetScale(D3DXVECTOR3 param_1);
	/* 100778E0 */ void AddTexture(char* param_1);
	/* 10077940 */ void Restore();
	/* 10077970 */ virtual void OnRender();
	/* 10077BB0 */ float DXUtil_Timer(TIMER_COMMAND param_1);

private:

	/* 0xd88 */ char shockwaveName[256];
	/* 0xe88 */ D3DXVECTOR3 position;
	/* 0xe94 */ D3DXVECTOR3 scale;
	/* 0xea0 */ D3DXVECTOR3 unkn_ea0;
	/* 0xeac */ D3DXMATRIX unkn_eac;
	/* 0xeec */ D3DXMATRIX unkn_eec;
	/* 0xf2c */ D3DXMATRIX positionMatrix;
	/* 0xf6c */ D3DXMATRIX scaleMatrix;
	/* 0xfac */ D3DXMATRIX temporaryMatrix;
	/* 0xfec */ D3DXMATRIX unkn_fec;
	/* 0x102c */ bool unkn_102c;
	/* 0x1030 */ float unkn_1030;
	/* 0x1034 */ float unkn_1034;
	/* 0x1038 */ float unkn_1038;
	/* 0x103c */ BOOL timerInitialized;
	/* 0x1040 */ BOOL usingQPF;
	/* 0x1044 */ int unkn_1044;
	/* 0x1048 */ LONGLONG ticksPerSec;
	/* 0x1050 */ LONGLONG llStopTime;
	/* 0x1058 */ LONGLONG llLastElapsedTime;
	/* 0x1060 */ LONGLONG llBaseTime;
	/* 0x1068 */ double lastElapsedTime;
	/* 0x1070 */ double baseTime;
	/* 0x1078 */ double stopTime;
};

STATIC_ASSERT(sizeof(cMagFx) == 0x1080);

#endif