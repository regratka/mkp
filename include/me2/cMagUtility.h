#ifndef C_MAG_UTILITY
#define C_MAG_UTILITY

#include <globals.h>

#include "MagState.h"

struct MAGVERTEX{
	D3DXVECTOR3 pos;
	D3DCOLOR color;
	float u;
	float v;
	D3DXVECTOR3 unused;
};

class __declspec(dllexport) cMagUtility : public MagState  {
public:
	/* 1002D170 */ cMagUtility();
	/* 1002D1F0 */ ~cMagUtility();
	/* 1002D200 */ void InitDeviceDx(cMagGameObject* param_1);
	/* 1002D210 */ void D3DUtil_InitMaterial(D3DMATERIAL8& param_1, float param_2, float param_3, float param_4, float param_5);
	/* 1002D260 */ void D3DUtil_InitLight(D3DLIGHT8& param_1, D3DLIGHTTYPE param_2, float param_3, float param_4, float param_5);
	/* 1002D2E0 */ HRESULT CreateQuad(IDirect3DVertexBuffer8** param_1, D3DPOOL param_2, float param_3, ulong param_4, IDirect3DDevice8* param_5, float param_6, float param_7, bool param_8);
	/* 1002DE90 */ int LoadBitmapToSurface(char* param_1, IDirect3DSurface8** param_2, IDirect3DDevice8* param_3);
	/* 1002DF90 */ long LoadAlphabet(char* param_1, int param_2, int param_3);
	/* 1002E070 */ long UnloadAlphabet();
	/* 1002E0A0 */ void PrintChar(int param_1, int param_2, char param_3, int param_4, ulong param_5, ulong* param_6, int param_7);
	/* 1002E270 */ void PrintString(int param_1, int param_2, char* param_3, int param_4, ulong param_5, ulong* param_6, int param_7);
	/* 1002E2F0 */ long CopySurfaceToSurface(tagRECT* param_1, IDirect3DSurface8* param_2, tagPOINT* param_3, IDirect3DSurface8* param_4, int param_5, ulong param_6);

private:
	/* 0xd2c */ int width;
	/* 0xd30 */ int height;
	/* 0xd34 */ int unkn_d34;
	/* 0xd38 */ int unkn_d38;
	/* 0xd3c */ int unkn_d3c;
	/* 0xd40 */ IDirect3DSurface8* surface;
	/* 0xd44 */ BOOL alphabetLoaded;
	/* 0xd48 */ cMagGameObject* deviceDx;
};

STATIC_ASSERT(sizeof(cMagUtility) == 0xd4c);

#endif