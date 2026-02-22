#ifndef C_F_X__SHOCKWAVE
#define C_F_X__SHOCKWAVE

#include <globals.h>

class cFX_Shockwave {
public:
	/* 10022F90 */ cFX_Shockwave();
	/* 10022FE0 */ void Begin();
	/* 10022FF0 */ void Pause();
	/* 10023000 */ void Stop();
	/* 10023030 */ void ShockwaveUpdate(float param_1);
	/* 100230B0 */ uchar Pos();
	/* 100230C0 */ uchar GetVB();
	/* 100230D0 */ cFX_Shockwave(cFX_Shockwave* param_1);
	/* 10023260 */ cFX_Shockwave* operator=(cFX_Shockwave* param_1);
	/* 100233E0 */ cFX_Shockwave* scalar_destructor(uchar param_1);
	/* 100764E0 */ ~cFX_Shockwave();
	/* 10076550 */ long RestoreDeviceObjects(char* param_1, float param_2, float param_3, int param_4, float param_5, float param_6);
	/* 10076860 */ void SetAlpha(int param_1);
	/* 100768C0 */ void InvalidateDeviceObjects();
	/* 10076900 */ void ShockwaveRender();
};

#endif