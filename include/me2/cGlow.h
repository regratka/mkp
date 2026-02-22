#ifndef C_GLOW
#define C_GLOW

#include <globals.h>

class cGlow {
public:
	/* 10076C30 */ cGlow(cGlow* param_1);
	/* 10076CF0 */ cGlow* operator=(cGlow* param_1);
	/* 10076DB0 */ cGlow* scalar_destructor(uchar param_1);
	/* 10076E10 */ cGlow();
	/* 10076EF0 */ ~cGlow();
	/* 10076F60 */ void Create(char* param_1);
	/* 10076FF0 */ void OnRender();
	/* 10077180 */ void RenderGlow();
	/* 10077370 */ void SetScale(uint param_1, uint param_2, uint param_3);
	/* 10077390 */ void SetPosition(uint param_1, uint param_2, uint param_3);
	/* 100773B0 */ void SetSize(float param_1);
	/* 100773C0 */ void EnableRendering(bool param_1);
	/* 100773D0 */ bool EnableRendering();
};

#endif