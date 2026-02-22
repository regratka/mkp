#ifndef _C_LENS_FLARE
#define _C_LENS_FLARE

#include <globals.h>

class CLensFlare {
public:
	/* 10022600 */ CMinMax<float> GetIntensity(uint* param_1);
	/* 10022630 */ void SetIntensity(CMinMax<float>* param_1);
	/* 10022650 */ float GetIntensityBorder();
	/* 10022660 */ void SetIntensityBorder(float param_1);
	/* 10022670 */ uchar GetPosition(uint* param_1);
	/* 100226A0 */ CLensFlare(CLensFlare* param_1);
	/* 100229B0 */ CLensFlare* operator=(CLensFlare* param_1);
	/* 10022CA0 */ CLensFlare* scalar_destructor(uchar param_1);
	/* 10074110 */ void InitDeviceDx(cMagGameObject* param_1);
	/* 10074230 */ CLensFlare();
	/* 10074300 */ ~CLensFlare();
	/* 100743C0 */ long RestoreDeviceObjects(IDirect3DDevice8* param_1);
	/* 100743F0 */ long RecreateVB();
	/* 10074460 */ void InvalidateDeviceObjects();
	/* 10074490 */ void CalcLightSourceScreenCoords(uchar param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uint param_10, uint param_11);
	/* 100746C0 */ void Render();
	/* 100747E0 */ void Render(int param_1, int param_2, int param_3, int param_4, bool param_5);
	/* 10075760 */ void DeleteTextures();
	/* 100757E0 */ void DeleteSpots();
	/* 10075910 */ uchar AddTexture(char* param_1);
	/* 10075AF0 */ void AddSpot(int param_1, CLensFlareSpot* param_2);
	/* 10075CA0 */ void DeleteSpots(int param_1);
	/* 10075E10 */ void SetPosition(D3DXVECTOR3 param_1);
	/* 10075E30 */ void OnRender();
	/* 10075EF0 */ void EnableRendering(bool param_1);
	/* 10075F00 */ bool IsEnabled();
	/* 10075F10 */ bool TestVisibility();
};

#endif