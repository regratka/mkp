#ifndef _I_STUDIO_MESH
#define _I_STUDIO_MESH

#include <globals.h>

#include "cMagMeshObject.h"

class IStudioMesh {
public:
	/* 10006C70 */ IStudioMesh(IStudioMesh* param_1);
	/* 10006ED0 */ IStudioMesh* operator=(IStudioMesh* param_1);
	/* 100072E0 */ IStudioMesh* scalar_destructor(uchar param_1);
	/* 1005CF90 */ IStudioMesh();
	/* 1005D0E0 */ virtual ~IStudioMesh();
	/* 1005D210 */ bool LoadMesh(char* param_1, cMagMeshObject* param_2);
	/* 1005D2E0 */ void LoadColTypeTexIni(char* param_1);
	/* 1005D380 */ void CreateColTypeTexIni(char* param_1);
	/* 1005D670 */ void EnableAnimTexture(bool param_1);
	/* 1005D680 */ void SetShadowType(int param_1);
	/* 1005D6A0 */ void RenderMesh(uchar param_1);
	/* 1005D700 */ void EnableRenderShadow(bool param_1);
	/* 1005D710 */ bool EnableRenderShadow();
	/* 1005D720 */ void OnRenderShadow();
	/* 1005D7D0 */ void SetCullMode(int param_1);
	/* 1005D850 */ void SetAlpha(int param_1);
	/* 1005D8E0 */ uint* GetHelperPosition(uint* param_1, uchar* param_2);
	/* 1005D930 */ void UpdateMorfing();
	/* 1005D950 */ bool PlayMorfing();
	/* 1005DA10 */ void EnableMorph1(bool param_1);
	/* 1005DA20 */ void SetMorphData(int param_1, int param_2, float param_3);
	/* 1005DA50 */ void SetStepMorph(float param_1);
	/* 1005DA60 */ void SetStep(float param_1);
	/* 1005DA80 */ void EnableMorph(bool param_1);
	/* 1005DAA0 */ void UpdateAnimation(D3DXMATRIX param_1);
	/* 1005E060 */ bool InitAnimSeq(char* param_1, int param_2, int param_3);
	/* 1005E410 */ void SetAnimFreq(char* param_1, float param_2);
	/* 1005E490 */ void PlayAnim(char* param_1);
	/* 1005E600 */ void PlayAnim(char* param_1, int param_2);
	/* 1005E770 */ void StopAnim(char* param_1);
	/* 1005E880 */ bool IsPlaying(char* param_1);
	/* 1005E900 */ void DeleteAnimSeq(char* param_1);
	/* 1005E990 */ void DeleteAllAnimSeq();
	/* 1005E9F0 */ void EnableLight(bool param_1);
	/* 1005EA10 */ void SetMaterialDiffuse(float param_1, float param_2, float param_3, float param_4);
	/* 1005EA40 */ void SetMaterialAmbient(float param_1, float param_2, float param_3, float param_4);
	/* 1005EA70 */ void SetLightDiffuse(float param_1, float param_2, float param_3, float param_4);
	/* 1005EAA0 */ void SetLightAmbient(float param_1, float param_2, float param_3, float param_4);
	/* 1005EAD0 */ int GetFrameCount();
	/* 1005EAF0 */ int GetFaceCount();
	/* 1005EB10 */ void SetLightPosition(D3DXVECTOR3 param_1);
	/* 1005EB30 */ void ComputeBoundingBox(D3DXVECTOR3& param_1, D3DXVECTOR3& param_2);
	/* 1005EE60 */ bool GetBoneMatrix(char* param_1, D3DXMATRIX& param_2, D3DXMATRIX& param_3);
	/* 1005EED0 */ void EnableAnimKeys(bool param_1);
	/* 1005EEF0 */ void SetMeshType(int param_1);
	/* 1005EF10 */ void GetPerfCounter(_LARGE_INTEGER* param_1);

public:
	/* 0x4 */ uchar f_4[0x1ac - 0x4];
	/* 0x1ac */ float animMorphTime;
	/* 0x1b0 */ uchar f_1b0[0x510 - 0x1b0];
};

#endif