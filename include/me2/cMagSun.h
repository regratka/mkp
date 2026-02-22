#ifndef C_MAG_SUN
#define C_MAG_SUN

#include <globals.h>

#include <d3dx8math.h>

class cMagSun {
public:
	/* 10021C20 */ void SetScale(uint param_1, uint param_2);
	/* 10021C40 */ D3DXVECTOR2 GetScale(uint* param_1);
	/* 10021C70 */ cMagSun(cMagSun* param_1);
	/* 10021F10 */ cMagSun* operator=(cMagSun* param_1);
	/* 10022240 */ cMagSun* scalar_destructor(uchar param_1);
	/* 10072620 */ void SetAnimTextureFPS(int param_1);
	/* 10072630 */ void SetAnimTextureFrameCount(int param_1);
	/* 100731B0 */ cMagSun();
	/* 10073340 */ ~cMagSun();
	/* 10073410 */ void RestoreSun();
	/* 10073460 */ uchar AddTexture(char* param_1);
	/* 100734A0 */ uint GetPosition(uint param_1);
	/* 100734C0 */ void Render();
	/* 100739E0 */ void DeleteQuad();
	/* 10073A00 */ void OnRender();
	/* 10073A60 */ void EnableRendering(bool param_1);
	/* 10073A70 */ bool IsEnabled();
	/* 10073A80 */ void AddAnimTexture(char* param_1);
	/* 10073C50 */ void RenderAnimTexture();
	/* 10073D30 */ void EnableAnimTexture(bool param_1);
	/* 10073D40 */ float deg2rad(float param_1);
	/* 10073D50 */ void SetAngleXZ(float param_1);
	/* 10073D60 */ void SetAngleYZ(float param_1);
	/* 10073D70 */ void SetDistance(float param_1);
	/* 10073D80 */ void Update();
};

#endif