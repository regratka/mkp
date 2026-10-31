#ifndef _MAGNUM_MESH
#define _MAGNUM_MESH

#include <globals.h>

#include "cMagUtility.h"
#include "CCPUTicker.h"
#include "Mesh.h"

struct MagnumMesh_F8C {
	/* 0x00 */ int unk_00;
	/* 0x04 */ IDirect3DTexture8* waterTex;
	/* 0x08 */ char waterTextureName[256];
};

STATIC_ASSERT(sizeof(MagnumMesh_F8C) == 0x108);

struct MagnumMesh_1508 {
	/* 0x00 */ int primitivesCount;
	/* 0x04 */ std::vector<void*> unk_04;
	/* 0x14 */ std::vector<void*> unk_14;
	/* 0x24 */ std::vector<void*> unk_24;
};

STATIC_ASSERT(sizeof(MagnumMesh_1508) == 0x34);

struct MagnumMesh_1528 {
	/* 0x000 */ char lightMapName[256];
	/* 0x100 */ IDirect3DTexture8* unk_100;
};

STATIC_ASSERT(sizeof(MagnumMesh_1528) == 0x104);

struct MagnumMesh_1540 {
	/* 0x000 */ char helperName[256];
	/* 0x100 */ D3DXVECTOR3 unk_100;
	/* 0x10c */ D3DXVECTOR3 unk_10c;
};

STATIC_ASSERT(sizeof(MagnumMesh_1540) == 0x118);

class DLLEXPORT MagnumMesh : public cMagUtility {
public:
	/* 1000DA50-1000DA57 00007	*/
	int GetNumVerts() {
		return mesh.unk_10c;
	}
	
	/* 1000DA60-1000DA67 00007	*/
	int GetNumFaces() {
		return mesh.unk_120;
	}

	/* 1000DA70-1000DA7D 0000D	*/
	void EnableScaleTile(bool param_1) {
		this->scaleTile = param_1;
	}

	/* 10012910 */ void RenderAnimTexture();
	/* 10012910 */ void RestoreMesh();
	/* 10030740 */ void CalculateDynamicVertexColor(D3DXVECTOR3 param_1);
	/* 10031850 */ MagnumMesh();
	/* 10031D90 */ ~MagnumMesh();
	/* 10032060 */ void Clear();
	/* 10032230 */ bool LoadMagnumMesh(char* param_1);
	/* 10032510 */ long LoadMagnumMeshOld(char* param_1);
	/* 10033040 */ long LoadMagnumMesh3dm(char* param_1);
	/* 10034750 */ long LoadMagnumMesh3dm_NEW(char* param_1);
	/* 10035F00 */ long LoadMagMesh(char* param_1);
	/* 10036060 */ long CreateTextures(char* param_1);
	/* 100364E0 */ void RenderMagMesh();
	/* 100364F0 */ void SetCullMode(int param_1);
	/* 10036500 */ void GetVectorMinAndMax(D3DXVECTOR3& param_1, D3DXVECTOR3& param_2);
	/* 10036500 */ void MagComputeBoundingBox(D3DXVECTOR3& param_1, D3DXVECTOR3& param_2);
	/* 10036540 */ void InitWater();
	/* 10036570 */ long SetAlpha(int param_1);
	/* 10036570 */ long SetMeshAlpha(int param_1);
	/* 10036580 */ void RenderWaterAnim();
	/* 10036670 */ long SetMultipleTexture(float param_1);
	/* 10036780 */ long SetMultipleAndMoveTexture(float param_1, float param_2, float param_3);
	/* 10036910 */ void SetBlendTexture();
	/* 10036990 */ void RenderQuad();
	/* 10036A20 */ void RenderWaterEfect();
	/* 10036AF0 */ void RenderWaterEfect1();
	/* 10036BD0 */ void SetiCount(int param_1);
	/* 10036BE0 */ int TextureIsRender(int param_1);
	/* 10036C20 */ void AddWaterTexture(char* param_1);
	/* 10036EA0 */ void SetFadeSpeed(float param_1);
	/* 10036EB0 */ void SetOpacity(float param_1);
	/* 10036EC0 */ void PlayWaterAnim();
	/* 10036ED0 */ void StopWaterAnim();
	/* 10036EE0 */ void SetScaleTile(float param_1);
	/* 10036EF0 */ void SetFps(float param_1);
	/* 10036F00 */ void SetAnimVel(float param_1);
	/* 10036F10 */ void SetSpeedMove(float param_1);
	/* 10036F20 */ void SetAlpha(ulong param_1, ulong param_2);
	/* 10036F40 */ void CalculateVertexColor();
	/* 100373F0 */ D3DXVECTOR3 CalculateColor(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 100375F0 */ float Odleglosc(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2);
	/* 10037630 */ void SetAlphaGreatereQual(ulong param_1);
	/* 10037650 */ ulong GetAlphaGreatereQual();
	/* 10037660 */ void CreateStaticMesh();
	/* 10037FD0 */ long SetColor(float param_1, float param_2, float param_3, float param_4);
	/* 100380F0 */ long SetStaticMeshAlpha(int param_1);
	/* 100382A0 */ void RenderStaticMeshNoTexture();
	/* 10038510 */ void Render(int param_1);
	/* 100389A0 */ void RenderStaticMesh();
	/* 10039380 */ void RenderStaticMeshStreamSource();
	/* 10039440 */ void CreateColTypeTexIni(char* param_1);
	/* 100396D0 */ void LoadColTypeTexIni(char* param_1);
	/* 10039A50 */ void TransformHelpers(D3DXMATRIX param_1);
	/* 10039A70 */ D3DXVECTOR3 GetHelperPosition(char* param_1, D3DXMATRIX param_2);
	/* 10039BA0 */ bool TestVector(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2, D3DXVECTOR3 param_3, D3DXVECTOR3 param_4);
	/* 10039C80 */ void EnableBlur(bool param_1);
	/* 10039C90 */ void EnableEnviromentMapping(bool param_1);
	/* 10039CA0 */ void SetEnviromentMappingTexture(char* param_1);
	/* 10039CD0 */ void ActivateLightMap(int param_1);
	/* 10039D40 */ void EnableAnimTexture(bool param_1);
	/* 10039D50 */ void AddAnimTexture(char* param_1);
	/* 10039F20 */ void SetAnimTextureFPS(int param_1);
	/* 10039F30 */ void SetAnimTextureFrameCount(int param_1);
	/* 10039F40 */ void EnableAnimTextureMove(bool param_1);
	/* 10039F50 */ void Pause(bool param_1);
	/* 10039FA0 */ void SetAnimTextureLightMap(IDirect3DTexture8* param_1);
	/* 10039FB0 */ void SetBumpMap(IDirect3DTexture8* param_1);
	/* 10039FC0 */ void SetDetailTile(float param_1);
	/* 1005A5E0 */ void InitDeviceMeshDx(cMagGameObject* param_1);
	/* 1005A5E0 */ void SetLodLevel(float param_1);
	/* 10072620 */ void SetMagMeshObject(cMagMeshObject* param_1);
	/* 10073A60 */ void EnableZBuffer(bool param_1);

private:
	/* 0x0d4c */ bool isZBufferEnabled;
	/* 0x0d50 */ cMagMeshObject* unk_d50;
	/* 0x0d54 */ int unk_d54[5];
	/* 0x0d68 */ Mesh mesh;
	/* 0x0f5c */ std::vector<void*> unk_f5c;
	/* 0x0f6c */ bool isWaterInitialized;
	/* 0x0f70 */ int unk_f70;
	/* 0x0f74 */ float unk_f74;
	/* 0x0f78 */ int iCount;
	/* 0x0f7c */ int unk_f7c;
	/* 0x0f80 */ bool unk_f80;
	/* 0x0f81 */ bool unk_f81;
	/* 0x0f84 */ int unk_f84;
	/* 0x0f88 */ int unk_f88;
	/* 0x0f8c */ std::vector<MagnumMesh_F8C> unk_f8c;
	/* 0x0f9c */ int unk_f9c;
	/* 0x0fa0 */ float unk_fa0;
	/* 0x0fa4 */ float animVel;
	/* 0x0fa8 */ float speedMove;
	/* 0x0fac */ int unk_fac;
	/* 0x0fb0 */ D3DXVECTOR3 unk_fb0;
	/* 0x0fbc */ char unk_fbc[1024];
	/* 0x13bc */ float fps;
	/* 0x13c0 */ bool unk_13c0;
	/* 0x13c4 */ int cullMode;
	/* 0x13c8 */ int unk_13c8;
	/* 0x13cc */ int unk_13cc;
	/* 0x13d0 */ float fadeSpeed;
	/* 0x13d4 */ float opacity;
	/* 0x13d8 */ bool isWaterAnimated;
	/* 0x13dc */ int unk_13dc;
	/* 0x13e0 */ float unk_13e0;
	/* 0x13e4 */ char unk_13e4[255];
	/* 0x14e3 */ bool scaleTile;
	/* 0x14e4 */ D3DXVECTOR3 unk_14e4;
	/* 0x14f0 */ D3DXVECTOR3 unk_14f0;
	/* 0x14fc */ bool unk_14fc;
	/* 0x1500 */ D3DCOLOR unk_1500;
	/* 0x1504 */ D3DCOLOR unk_1504;
	/* 0x1508 */ MagnumMesh_1508* unk_1508;
	/* 0x150c */ int unk_150c;
	/* 0x1510 */ std::vector<IDirect3DVertexBuffer8*> unk_1510;
	/* 0x1520 */ int unk_1520;
	/* 0x1524 */ int unk_1524;
	/* 0x1528 */ std::vector<MagnumMesh_1528> unk_1528;
	/* 0x1538 */ int activeLightMapIndex;
	/* 0x153c */ bool unk_153c;
	/* 0x153d */ bool unk_153d;
	/* 0x1540 */ std::vector<MagnumMesh_1540> unk_1540;
	/* 0x1550 */ D3DXMATRIX unk_1550;
	/* 0x1590 */ bool isBlurEnabled;
	/* 0x1594 */ IDirect3DTexture8* envMappingTex;
	/* 0x1598 */ bool isEnvMappingEnabled;
	/* 0x1599 */ bool isEnvMappingTexSet;
	/* 0x159a */ bool isAnimTextureEnabled;
	/* 0x159b */ bool isAnimTextureMoveEnabled;
	/* 0x159c */ int animTextureFPS;
	/* 0x15a0 */ int animTextureFrameCount;
	/* 0x15a4 */ std::vector<IDirect3DTexture8*> animTextures;
	/* 0x15b8 */ CCPUTicker cpuTicker;
	/* 0x18f0 */ int unk_18f0;
	/* 0x18f4 */ float unk_18f4;
	/* 0x18f8 */ float unk_18f8;
	/* 0x18fc */ bool paused;
	/* 0x1900 */ IDirect3DTexture8* animTextureLightMap;
	/* 0x1904 */ IDirect3DTexture8* bumpMap;
	/* 0x1908 */ float detailTile;
	/* 0x190c */ D3DXMATRIX unk_190c;
};

STATIC_ASSERT(sizeof(MagnumMesh) == 0x1950);

#endif