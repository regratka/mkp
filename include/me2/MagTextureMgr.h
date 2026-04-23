#ifndef _MAG_TEXTURE_MGR
#define _MAG_TEXTURE_MGR

#include <globals.h>

#include <d3dx8tex.h>

class MagTextureMgr {
public:
    static MagTextureMgr* getInstance() {
		return instance;
	}

	/* 10004040 */ MagTextureMgr(MagTextureMgr* param_1);
	/* 10004140 */ MagTextureMgr* operator=(MagTextureMgr* param_1);
	/* 10004380 */ MagTextureMgr* scalar_destructor(uchar param_1);
	/* 100393E0 */ char* CreateNiceString(char* param_1);
	/* 10086680 */ MagTextureMgr();
	/* 10086730 */ ~MagTextureMgr();
	/* 10086760 */ void RestoreTextures();
	/* 10086810 */ uchar GetTexture(char* param_1, _D3DXIMAGE_INFO* param_2);
	/* 100869A0 */ IDirect3DTexture8* GetTexture(char const* param_1);
	/* 10086B20 */ uchar GetTextureMesh(char* param_1);
	/* 10086C00 */ int GetID();
	/* 10086C10 */ IDirect3DTexture8* ReplaceTexture(char* param_1, char* param_2);
	/* 10086CE0 */ void DeleteTexture(char* param_1);
	/* 10086D70 */ bool IsTexture(char* param_1, int* param_2);
	/* 10086DE0 */ uchar LoadTexture(char* param_1, _D3DXIMAGE_INFO* param_2, int param_3);
	/* 10087290 */ uchar LoadTextureMesh(char* param_1, _D3DXIMAGE_INFO* param_2, int param_3);
	/* 10087730 */ int GetBuforSize();
	/* 10087760 */ uchar LoadTextureA(char* param_1, _D3DXIMAGE_INFO* param_2);
	/* 100878D0 */ uchar GetTextureA(char* param_1);
	/* 10087940 */ void Clear();
	/* 100879D0 */ uchar LoadTextureFullPath(char* param_1, _D3DXIMAGE_INFO* param_2, char* param_3, int param_4);
	/* 10087E10 */ void SetAlfaGreatereQual(ulong param_1);
	/* 10087E20 */ void BeginAlphaTexture();
	/* 10087E70 */ void EndAlphaTexture();
	/* 10087EA0 */ void BeginFilterTexture();
	/* 10087F30 */ void BeginFilterVertexColorTexture();
	/* 10087FE0 */ uchar ComputeBumpMap(char* param_1);
	/* 100881F0 */ uchar GetTextureBoundingBox();
	/* 10088210 */ uchar GetTextureGird();

private:
	static MagTextureMgr* instance;
};

MagTextureMgr* MagTextureMgr::instance = NULL;

#endif