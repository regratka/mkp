#ifndef _MAGNUM_MESH
#define _MAGNUM_MESH

#include <globals.h>

#include "cMagUtility.h"

class MagnumMesh : public cMagUtility {
public:
	/* 1000DA50 */ int GetNumVerts();
	/* 1000DA60 */ int GetNumFaces();
	/* 1000DA70 */ void EnableScaleTile(bool param_1);
	/* 1000DA80 */ MagnumMesh(MagnumMesh* param_1);
	/* 1000E390 */ MagnumMesh* operator=(MagnumMesh* param_1);
	/* 1000EC80 */ MagnumMesh* scalar_destructor(uchar param_1);
	/* 10030740 */ void CalculateDynamicVertexColor();
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
	/* 10036500 */ void GetVectorMinAndMax(uchar param_1, uchar param_2);
	/* 10036540 */ void InitWater();
	/* 10036570 */ long SetAlpha(int param_1);
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
	/* 100373F0 */ uchar CalculateColor(float* param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7);
	/* 100375F0 */ float Odleglosc(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6);
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
	/* 10039A50 */ void TransformHelpers(uchar param_1);
	/* 10039A70 */ uchar GetHelperPosition(uint* param_1, uchar* param_2);
	/* 10039BA0 */ ulonglong TestVector(uint param_1, uint param_2, uint param_3, uint param_4, uint param_5, uint param_6, uint param_7, uint param_8, uint param_9, uint param_10, uint param_11, uint param_12);
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
	/* 10039FA0 */ void SetAnimTextureLightMap(uchar param_1);
	/* 10039FB0 */ void SetBumpMap(uchar param_1);
	/* 10039FC0 */ void SetDetailTile(float param_1);

private:
	/* 0xd4c */ uchar field_0xd4c[0x1950-0xd4c];
};

STATIC_ASSERT(sizeof(MagnumMesh) == 0x1950);

#endif