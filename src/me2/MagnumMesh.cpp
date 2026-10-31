#include "MagnumMesh.h"

#include "cMagEngineMgr.h"

#include "CRay.h"

/* 10012910-10012911 00001 	*/ 
void MagnumMesh::RenderAnimTexture() {
}

/* 10012910-10012911 00001 	*/ 
void MagnumMesh::RestoreMesh() {
}

/* 10030740-10030743 00003	*/
void MagnumMesh::CalculateDynamicVertexColor(D3DXVECTOR3 param_1) {
}

/* 10031850-10031D8E 0053E	*/
MagnumMesh::MagnumMesh() {
}

/* 10031D90-1003205F 002CF	*/
MagnumMesh::~MagnumMesh() {
}

/* 10032060-10032226 001C6	*/
void MagnumMesh::Clear() {
}

/* 10032230-10032503 002D3	*/
bool MagnumMesh::LoadMagnumMesh(char* param_1) {
	return 0;
}

/* 10032510-1003303F 00B2F	*/
long MagnumMesh::LoadMagnumMeshOld(char* param_1) {
	return 0;
}

/* 10033040-10034710 016D0	*/
long MagnumMesh::LoadMagnumMesh3dm(char* param_1) {
	return 0;
}

/* 10034750-10035EF4 017A4	*/
long MagnumMesh::LoadMagnumMesh3dm_NEW(char* param_1) {
	return 0;
}

/* 10035F00-10035FA1 00159	*/
long MagnumMesh::LoadMagMesh(char* param_1) {
	strcpy(unk_13e4, param_1);
	try {
		LoadMagnumMesh(param_1);
		LoadColTypeTexIni(param_1);
	} catch(...) {
		CrashLog("can`t load static mesh: %s (error) ", param_1);
		return E_FAIL;
	}

	try {
		CreateTextures(param_1);
	} catch(...) {
		char buffer[255];
		sprintf(buffer, "[ERROR] can`t create textures:%s ", param_1);
		MessageBox(NULL, buffer, "error", 0);
		CrashLog("[ERROR] can`t create textures: %s", param_1);
		return E_FAIL;
	}

	try {
		CreateStaticMesh();
	} catch(...) {
		char buffer[255];
		sprintf(buffer, "blad ladowania5:%s ", param_1);
		CrashLog("%s", buffer);
		return E_FAIL;
	}

	return S_OK;
}

/* 10036060-10036428 0047C	*/
long MagnumMesh::CreateTextures(char* param_1) {
	return 0;
}

/* 100364E0-100364E5 00005	*/
void MagnumMesh::RenderMagMesh() {
	RenderStaticMesh();
}

/* 100364F0-100364FD 0000D	*/
void MagnumMesh::SetCullMode(int param_1) {
	cullMode = param_1;
}

/* 10036500-10036539 00039	*/
void MagnumMesh::GetVectorMinAndMax(D3DXVECTOR3& param_1, D3DXVECTOR3& param_2) {
	param_1 = unk_14e4;
	param_2 = unk_14f0;
}

/* 10036500-10036539 00039	*/
void MagnumMesh::MagComputeBoundingBox(D3DXVECTOR3& param_1, D3DXVECTOR3& param_2) {
	param_1 = unk_14e4;
	param_2 = unk_14f0;
}

/* 10036540-1003656D 0002D	*/
void MagnumMesh::InitWater() {
	SetAlpha(opacity);
	SetMultipleTexture(unk_fa0);
	isWaterInitialized = true;
}

/* 10036570-1003657F 0000F	*/
long MagnumMesh::SetAlpha(int param_1) {
	SetStaticMeshAlpha(param_1);
	return S_OK;
}

/* 10036570-1003657F 0000F	*/
long MagnumMesh::SetMeshAlpha(int param_1) {
	SetStaticMeshAlpha(param_1);
	return S_OK;
}

/* 10036580-10036670 000F0	*/
void MagnumMesh::RenderWaterAnim() {
	if (isWaterAnimated) {
		float DVar4 = timeGetTime() * 0.001f;
		if (fps < DVar4 - unk_f74) {
			unk_f74 = DVar4;
			unk_13e0 += 1.0f;
		}

		if (unk_f8c.size() <= unk_13e0) {
			unk_13e0 = 0.0f;
		}
	}
	

	cMagEngineMgr::getInstance()->engine->SetTexture(0, unk_f8c[unk_13e0].waterTex);
	SetBlendTexture();
}

/* 10036670-10036773 00103	*/
long MagnumMesh::SetMultipleTexture(float param_1) {
	return 0;
}

/* 10036780-10036905 00185	*/
long MagnumMesh::SetMultipleAndMoveTexture(float param_1, float param_2, float param_3) {
	return 0;
}

/* 10036910-10036988 00078	*/
void MagnumMesh::SetBlendTexture() {
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_MINFILTER, D3DTEXF_LINEAR);
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR);
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_ADDRESSU, D3DTADDRESS_WRAP);
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_ADDRESSV, D3DTADDRESS_WRAP);
}

/* 10036990-10036A1E 0008E	*/
void MagnumMesh::RenderQuad() {
	int index = 0;
	while(index < mesh.unk_1bc) {
		if (unk_1508 == NULL) {
			return;
		}

		if (unk_1508[index].primitivesCount > 0 ) {
			cMagEngineMgr::getInstance()->engine->SetVertexShader(D3DFVF_TEX3|D3DFVF_DIFFUSE|D3DFVF_NORMAL|D3DFVF_XYZ);
			if (unk_1510[index] != NULL) {
				cMagEngineMgr::getInstance()->engine->SetStreamSource(0, unk_1510[index], 0x34);
				cMagEngineMgr::getInstance()->engine->DrawPrimitive(D3DPT_TRIANGLELIST, 0, unk_1508[index].primitivesCount);
			}
		}
		index++;
	}
}

/* 10036A20-10036AEE 000CE	*/
void MagnumMesh::RenderWaterEfect() {
	float DVar1 = timeGetTime() / 1000.0f;
	if (fadeSpeed < DVar1 - unk_f74) {
		unk_f74 = DVar1;
		if (!unk_f80) {
			iCount += 5;
			if (opacity < iCount) {
				unk_f80 = true;
			}
		}

		if (unk_f80) {
			iCount -= 5;
			if (iCount < 1) {
				unk_f80 =false;
			} 
		}
	}

	SetAlpha(iCount);
	cMagEngineMgr::getInstance()->engine->SetTexture(0, unk_f8c.begin()->waterTex);
}

/* 10036AF0-10036BC1 000D1	*/
void MagnumMesh::RenderWaterEfect1() {
	float DVar1 = timeGetTime() / 1000.0f;
	if (fadeSpeed < DVar1 - unk_f74) {
		unk_f74 = DVar1;
		if (!unk_f81) {
			unk_f7c -= 5;
			if (unk_f7c < 1) {
				unk_f81 = true;
			}
		}

		if (unk_f81) {
			unk_f7c += 5;
			if (opacity < unk_f7c) {
				unk_f81 = false;
			} 
		}
	}

	SetAlpha(unk_f7c);
	cMagEngineMgr::getInstance()->engine->SetTexture(0, unk_f8c[1].waterTex);
}

/* 10036BD0-10036BDD 0000D	*/
void MagnumMesh::SetiCount(int param_1) {
	iCount = param_1;
}

/* 10036BE0-10036C1B 0003B	*/
int MagnumMesh::TextureIsRender(int param_1) {
	// return param_1 < unk_f8c.size();
	if (param_1 < unk_f8c.size()) {
		return TRUE;
	}
	return FALSE;
}

/* 10036C20-10036E9E 0027E	*/
void MagnumMesh::AddWaterTexture(char* param_1) {
	MagnumMesh_F8C local_108;
	local_108.waterTex = MagTextureMgr::getInstance()->GetTexture(param_1);
	local_108.unk_00 = 0;
	strcpy(local_108.waterTextureName, param_1);
	unk_f8c.push_back(local_108);
}

/* 10036EA0-10036EAD 0000D	*/
void MagnumMesh::SetFadeSpeed(float param_1) {
	fadeSpeed = param_1;
}

/* 10036EB0-10036EBD 0000D	*/
void MagnumMesh::SetOpacity(float param_1) {
	opacity = param_1;
}

/* 10036EC0-10036EC8 00008	*/
void MagnumMesh::PlayWaterAnim() {
	isWaterAnimated = true;
}

/* 10036ED0-10036ED8 00008	*/
void MagnumMesh::StopWaterAnim() {
	isWaterAnimated = false;
}

/* 10036EE0-10036EED 0000D	*/
void MagnumMesh::SetScaleTile(float param_1) {
	unk_fa0 = param_1;
}

/* 10036EF0-10036EFD 0000D	*/
void MagnumMesh::SetFps(float param_1) {
	fps = param_1;
}

/* 10036F00-10036F0D 0000D	*/
void MagnumMesh::SetAnimVel(float param_1) {
	animVel = param_1;
}

/* 10036F10-10036F1D 0000D	*/
void MagnumMesh::SetSpeedMove(float param_1) {
	speedMove = param_1;
}

/* 10036F20-10036F3E 0001E	*/
void MagnumMesh::SetAlpha(ulong param_1, ulong param_2) {
	unk_14fc = true;
	unk_1500 = param_1;
	unk_1504 = param_2;
}

/* 10036F40-10037369 00429	*/
void MagnumMesh::CalculateVertexColor() {
	D3DXVECTOR3 local_e4(-466.0f, -72.0f, -294.0f);
	float local_138 = 0.0f;

	for (int local_154 = 0; local_154 < mesh.unk_120; local_154++) {
		DebugLog("-------------------------------------------------------");
		D3DXVECTOR3 local_f0 = mesh.unk_124[local_154];
		D3DXVECTOR3 local_13c = mesh.unk_110[local_f0.x];
		D3DXVECTOR3 local_cc = mesh.unk_110[local_f0.y];
		D3DXVECTOR3 local_130 = mesh.unk_110[local_f0.z];

		D3DXVECTOR3 local_150 = local_130 - local_13c;
		D3DXVECTOR3 local_150_2 = local_cc - local_13c;

		D3DXVECTOR3 local_b8;
		D3DXVec3Cross(&local_b8, &local_150_2, &local_150);

		CRay local_124(local_130, local_b8);
		float local_c0;

		local_124.Intersect(CRay(local_e4, local_124.Normal() * -1.0f), local_c0);
		D3DXVECTOR3 DStack_88 = local_e4 - local_124.Normal() * local_c0;

		float fStack_bc;
		local_124.Intersect(CRay(local_e4, local_124.Normal() * -1.0f), fStack_bc);

		float fVar14 = fabs(fStack_bc);
		if (local_138 < fVar14) {
			local_138 = fVar14;
		}

		DebugLog("odleglosc od swiatla : %f", fVar14);
		float fStack_d8 = 1.0f - fVar14;
		mesh.unk_1e0[local_f0.x] = D3DXVECTOR3(fStack_d8, fStack_d8, 0.0f);
		mesh.unk_1e0[local_f0.y] = D3DXVECTOR3(fStack_d8, fStack_d8, 0.0f);
		mesh.unk_1e0[local_f0.z] = D3DXVECTOR3(fStack_d8, fStack_d8, 0.0f);
	}
}

/* 100373F0-100375E2 001F2	*/
D3DXVECTOR3 MagnumMesh::CalculateColor(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2) {
	D3DXVECTOR3 defaultColor(0.3f, 0.3f, 0.3f);
	unk_fb0 = param_2;
	Odleglosc(param_1, param_2);
	D3DXVECTOR3 DVar2;
	DVar2.x = param_1.x + 250.0f;
	DVar2.y = param_1.y + 250.0f;
	DVar2.z = param_1.z + 250.0f;

	float fVar4 =  Odleglosc(param_1, DVar2);
	DebugLog("max odleglosc od swiatla : %f", fVar4);

	D3DXVECTOR3 diff = param_1-param_2;
	float fVar1 = D3DXVec3Length(&diff);
	float fVar2 =  255.0f / fVar4 * fVar1;
	if (fVar2 < 0.0f) {
		fVar2 = 0.0f;
	}

	DebugLog("odleglosc od swiatla : %f", fVar1);
	DebugLog("--alph: %f", fVar2);
	if (fVar2 <= 255.0f && fVar1 <= fVar4) {
		D3DXVECTOR3 retVal(fVar2/255.0f, fVar2/255.0f, fVar2/510.0f);
		return retVal;
	}
	return defaultColor;
}

/* 100375F0-10037623 00033	*/
float MagnumMesh::Odleglosc(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2) {
	return D3DXVec3Length(&D3DXVECTOR3(param_1 - param_2));
}

/* 10037630-10037643 00013	*/
void MagnumMesh::SetAlphaGreatereQual(ulong param_1) {
	unk_13c8 = param_1;
	unk_13cc = param_1;
}

/* 10037650-10037657 00007	*/
ulong MagnumMesh::GetAlphaGreatereQual() {
	return unk_13c8;
}

/* 10037660-10037F8E 0092E	*/
void MagnumMesh::CreateStaticMesh() {
}

/* 10037FD0-100380F0 00120	*/
long MagnumMesh::SetColor(float param_1, float param_2, float param_3, float param_4) {
	return 0;
}

/* 100380F0-10038293 001A3	*/
long MagnumMesh::SetStaticMeshAlpha(int param_1) {
	return 0;
}

/* 100382A0-1003850D 0026D	*/
void MagnumMesh::RenderStaticMeshNoTexture() {
}

/* 10038510-10038999 00489	*/
void MagnumMesh::Render(int param_1) {
}

/* 100389A0-1003937A 009DA	*/
void MagnumMesh::RenderStaticMesh() {
}

/* 10039380-100393D9 00059	*/
void MagnumMesh::RenderStaticMeshStreamSource() {
}

/* 10039440-100396A9 00269	*/
void MagnumMesh::CreateColTypeTexIni(char* param_1) {
}

/* 100396D0-10039A4A 0037A	*/
void MagnumMesh::LoadColTypeTexIni(char* param_1) {
}

/* 10039A50-10039A68 00018	*/
void MagnumMesh::TransformHelpers(D3DXMATRIX param_1) {
	unk_1550 = param_1;
}

/* 10039A70-10039BA0 00130	*/
D3DXVECTOR3 MagnumMesh::GetHelperPosition(char* param_1, D3DXMATRIX param_2) {
	for (int index = 0; index < unk_1540.size(); index++) {
		if (stricmp(unk_1540[index].helperName, param_1) == 0) {
			D3DXVECTOR3 local_18 = unk_1540[index].unk_100;
			D3DXVECTOR3 local_24 = unk_1540[index].unk_10c;
			D3DXVECTOR3 local_30;
			local_30.x = (local_24.x + local_18.x) / 2.0f;
			local_30.y = (local_24.y + local_18.y) / 2.0f;
			local_30.z = (local_24.z + local_18.z) / 2.0f;

			D3DXVec3TransformCoord(&local_30, &local_30, &param_2);
			return local_30;
		}
	}

	return D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

/* 10039BA0-10039C72 000D2	*/
bool MagnumMesh::TestVector(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2, D3DXVECTOR3 param_3, D3DXVECTOR3 param_4) {
	return 0;
}

/* 10039C80-10039C8D 0000D	*/
void MagnumMesh::EnableBlur(bool param_1) {
	isBlurEnabled = param_1;
}

/* 10039C90-10039C9D 0000D	*/
void MagnumMesh::EnableEnviromentMapping(bool param_1) {
	isEnvMappingEnabled = param_1;
}

/* 10039CA0-10039CC4 00024	*/
void MagnumMesh::SetEnviromentMappingTexture(char* param_1) {
	envMappingTex = MagTextureMgr::getInstance()->GetTexture(param_1);
	isEnvMappingTexSet = true;
}

/* 10039CD0-10039D3D 0006D	*/
void MagnumMesh::ActivateLightMap(int param_1) {
	if (param_1 < unk_1528.size()) {
		activeLightMapIndex = param_1;
		return;
	} 

	activeLightMapIndex = unk_1528.size() -1;
}

/* 10039D40-10039D4D 0000D	*/
void MagnumMesh::EnableAnimTexture(bool param_1) {
	isAnimTextureEnabled = param_1;
}

/* 10039D50-10039F17 001C7	*/
void MagnumMesh::AddAnimTexture(char* param_1) {
	animTextures.push_back(MagTextureMgr::getInstance()->GetTexture(param_1));
}

/* 10039F20-10039F2D 0000D	*/
void MagnumMesh::SetAnimTextureFPS(int param_1) {
	animTextureFPS = param_1;
}

/* 10039F30-10039F3D 0000D	*/
void MagnumMesh::SetAnimTextureFrameCount(int param_1) {
	animTextureFrameCount = param_1;
}

/* 10039F40-10039F4D 0000D	*/
void MagnumMesh::EnableAnimTextureMove(bool param_1) {
	isAnimTextureMoveEnabled = param_1;
}

/* 10039F50-10039F95 00045	*/
void MagnumMesh::Pause(bool param_1) {
  if (this->paused && !param_1) {
	cpuTicker.Reset();
	unk_18f0 = 0;
  }
  paused = param_1;
}

/* 10039FA0-10039FAD 0000D	*/
void MagnumMesh::SetAnimTextureLightMap(IDirect3DTexture8* param_1) {
	this->animTextureLightMap = param_1;
}

/* 10039FB0-10039FBD 0000D	*/
void MagnumMesh::SetBumpMap(IDirect3DTexture8* param_1) {
	this->bumpMap = param_1;
}

/* 10039FC0-10039FCD 0000D	*/
void MagnumMesh::SetDetailTile(float param_1) {
	this->detailTile = param_1;
}

/* 1005A5E0-1005A5E3 00003	*/
void MagnumMesh::InitDeviceMeshDx(cMagGameObject* param_1) {

}

/* 1005A5E0-1005A5E3 00003	*/
void MagnumMesh::SetLodLevel(float param_1) {

}

/* 10072620-1007262D 0000D	*/
void MagnumMesh::SetMagMeshObject(cMagMeshObject* param_1) {
	unk_d50 = param_1;
}

/* 10073A60-10073A6D 0000D	*/
void MagnumMesh::EnableZBuffer(bool param_1) {
	isZBufferEnabled = param_1;
}