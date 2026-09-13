#include "cMagSun.h"

#include "cMagEngineMgr.h"
#include "MagTextureMgr.h"
#include "CCamera.h"

/* 10012910-10012911 00001	*/
void cMagSun::DeleteTexture() {
}


/* 1005A5E0-1005A5E3 00003	*/
void cMagSun::InitDeviceDx(cMagGameObject* param_1) {
}

/* 10072620-1007262D 0000D	*/
void cMagSun::SetAnimTextureFPS(int param_1) {
	animTextureFPS = param_1;
}

/* 10072630-1007263D 0000D	*/
void cMagSun::SetAnimTextureFrameCount(int param_1) {
	animTextureFrameCount = param_1;
}

/* 100731B0-1007333A 0018A	*/
cMagSun::cMagSun() {
	SetObjectName("No name");
	SetClassName("cMagSun");
	texture = NULL;
	buffer = NULL;
	unk_d7c = 0.0f;
	unk_d80 = 0.0f;
	unk_d84 = 0.0f;
	magLog.FileLog("Create Sun ... ");
	CreateQuad(&buffer, D3DPOOL_MANAGED, 1.0f, -1, cMagEngineMgr::getInstance()->engine, 1.0f, 1.0f, true);
	unk_d4c = true;
	unk_d4d = false;
	animTextureFPS = 30;
	animTextureFrameCount = 0;
	unk_d58 = 0.0f;
	unk_d5c = 0.0f;
	meshObject.SetPosition(D3DXVECTOR3(0.0f, 0.0f, 1000.0f));
	meshObject.EnableRendering(false);
	unk_33e8 = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	unk_3434 = 0.0f;
	unk_3438 = 0.0f;
	angleXZ = 0.0f;
	angleYZ = 0.0f;
	distance = 1000.0f;
}

/* 10073340-10073401 000C1	*/
cMagSun::~cMagSun() {
	DeleteTexture();
	DeleteQuad();
	unk_d60.clear();
}

/* 10073410-1007345A 0004A	*/
void cMagSun::RestoreSun() {
	if (buffer != NULL) {
		buffer->Release();
	}
	buffer = NULL;
	CreateQuad(&buffer, D3DPOOL_MANAGED, 1.0f, -1, cMagEngineMgr::getInstance()->engine, 1.0f, 1.0f, true);
}

/* 10073460-1007349E 0003E	*/
IDirect3DTexture8* cMagSun::AddTexture(char const * param_1) {
	char* texName = strtok(strrchr(param_1, '\\'), "\\");
	if (texName == NULL) {
		return NULL;
	}
	texture = MagTextureMgr::getInstance()->GetTexture(texName);
	return texture;
}

/* 100734A0-100734BE 0001E	*/
D3DXVECTOR3 cMagSun::GetPosition() {
	return meshObject.GetPosition();
}

/* 100734C0-100739DC 0051C	*/
void cMagSun::Render(D3DXMATRIX param_1) {
	D3DXMATRIX local_364;
	D3DXMatrixIdentity(&local_364);
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_WORLD, &local_364);
	D3DXMATRIX auStack_280 = param_1;
	D3DXMATRIX afStack_40 = param_1;
	auStack_280(3,0) = 0.0f;
	auStack_280(3,1) = 0.0f;
	auStack_280(3,2) = 0.0f;
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_VIEW, &auStack_280);
	D3DXMATRIX DStack_2e4;
	D3DXMatrixTranspose(&DStack_2e4, &param_1);
	D3DXMATRIX DStack_324 = DStack_2e4;
	DStack_324(3,2) = 0.0f;
	DStack_324(3,1) = 0.0f;
	DStack_324(3,0) = 0.0f;
	DStack_324(2,3) = 0.0f;
	DStack_324(1,3) = 0.0f;
	DStack_324(0,3) = 0.0f;
	DStack_324(3,3) = 1.0f;

	D3DXMatrixTranslation(&local_364, meshObject.GetPosition().x, meshObject.GetPosition().y, meshObject.GetPosition().z);
	D3DXMATRIX Dstack_240;
	D3DXMatrixRotationYawPitchRoll(&Dstack_240, unk_d7c, unk_d80, unk_d84);
	D3DXMATRIX Dstack_100;
	D3DXMatrixScaling(&Dstack_100, unk_d74.x, unk_d74.y, 1.0f);

	D3DXMATRIX DStack_180;
	D3DXMatrixMultiply(&DStack_180, &Dstack_100, &Dstack_240);
	D3DXMATRIX DStack_80 = DStack_180;

	D3DXMATRIX DStack_200;
	D3DXMatrixMultiply(&DStack_200, &DStack_80, &DStack_324);
	D3DXMATRIX DStack_1c0 = DStack_200;
	
	D3DXMATRIX DStack_140;
	D3DXMatrixMultiply(&DStack_140, &DStack_1c0, &local_364);
	D3DXMATRIX DStack_c0 = DStack_140;

	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_WORLD, &DStack_c0);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_LIGHTING, FALSE);
	MagTextureMgr::getInstance()->BeginFilterTexture();
	MagTextureMgr::getInstance()->BeginAlphaTexture();
	MagTextureMgr::getInstance()->BeginFilterVertexColorTexture();
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_ALPHAOP, 2);
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, 0);
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_ADDRESSU, 4);
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_ADDRESSV, 3);
	if (buffer == NULL) {
		magLog.CrashLog("cMagSun Quad is NULL (error)");
	}

	if (texture != NULL) {
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHAREF, 2);
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
		
		if (unk_d4d) {
			RenderAnimTexture();
		} else {
			cMagEngineMgr::getInstance()->engine->SetTexture(0, texture);
		}
		cMagEngineMgr::getInstance()->engine->SetVertexShader(0x142);
		cMagEngineMgr::getInstance()->engine->SetStreamSource(0, buffer, 0x24);
		cMagEngineMgr::getInstance()->engine->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	}
	
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ZENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ZERO);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ONE);
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_VIEW, &afStack_40);
}

/* 100739E0-100739FF 0001F	*/
void cMagSun::DeleteQuad() {
	if (buffer != NULL) {
		buffer->Release();
	}
	buffer = NULL;
}

/* 10073A00-10073A5D 0005D	*/
void cMagSun::OnRender() {
	if (!unk_d4c) {
		return;
	}

	D3DXMATRIX local_40;
	cMagEngineMgr::getInstance()->engine->GetTransform(D3DTS_VIEW, &local_40);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	Render(local_40);
}

/* 10073A60-10073A6D 0000D	*/
void cMagSun::EnableRendering(bool param_1) {
	unk_d4c = param_1;
}

/* 10073A70-10073A77 00007	*/
bool cMagSun::IsEnabled() {
	return unk_d4c;
}

/* 10073A80-10073C47 001C7	*/
void cMagSun::AddAnimTexture(char* param_1) {
	unk_d60.push_back(MagTextureMgr::getInstance()->GetTexture(param_1));
}

/* 10073C50-10073D2C 000DC	*/
void cMagSun::RenderAnimTexture() {
	float fVar1 = timeGetTime() * 0.001f;
    if (fVar1 - unk_d58 > 1.0f / animTextureFPS) {
		unk_d58 = fVar1;
		unk_d5c += 1.0f;
    }

	if (animTextureFrameCount <= unk_d5c) {
		unk_d5c = 0.0f;
	}

	if (unk_d60.size() <= unk_d5c) {
		unk_d5c = 0.0f;
	}

	cMagEngineMgr::getInstance()->engine->SetTexture(0, unk_d60[unk_d5c]);
}

/* 10073D30-10073D3D 0000D	*/
void cMagSun::EnableAnimTexture(bool param_1) {
	unk_d4d = param_1;
}

/* 10073D40-10073D4D 0000D	*/
float cMagSun::deg2rad(float param_1) {
	return param_1 * (3.141592741012574 / 180.0);
}

/* 10073D50-10073D5D 0000D	*/
void cMagSun::SetAngleXZ(float param_1) {
	angleXZ = param_1;
}

/* 10073D60-10073D6D 0000D	*/
void cMagSun::SetAngleYZ(float param_1) {
	angleYZ = param_1;
}

/* 10073D70-10073D7D 0000D	*/
void cMagSun::SetDistance(float param_1) {
	distance = param_1;
}

/* 10073D80-10074060 002E0	*/
void cMagSun::Update() {

	meshObject.SetPosition(D3DXVECTOR3(0.0f, 0.0f, distance));
	meshObject.Rotate(D3DXVECTOR3(0.0f, 1.0f, 0.0f), -unk_3434);
	meshObject.Rotate(meshObject.GetRight(), -unk_3438);
	unk_3434 = angleXZ;
	unk_3438 = angleYZ;
	
	D3DXVECTOR3 local_30(0.0f, 0.0f, 0.0f);
	if (cMagEngineMgr::getInstance()->gameObject->GetActiveCamera() != NULL) {
		local_30 = cMagEngineMgr::getInstance()->gameObject->GetActiveCamera()->GetPosition();
	}

	D3DXVECTOR3 local_c = meshObject.GetPosition();
	D3DXVECTOR3 fVar8 = local_30 - local_c;
	if (unk_33e8 != local_30) {
		meshObject.SetDirection(fVar8);
		unk_33e8 = local_30;
	}
	
	float fVar9 = angleXZ;
	float fVar10 = angleYZ;
	meshObject.Rotate(D3DXVECTOR3(0.0f, 1.0f, 0.0f), fVar9);
	meshObject.Rotate(meshObject.GetRight(), fVar10);
	D3DXVECTOR3 local_18 = local_30 - D3DXVec3Length(&fVar8) * meshObject.GetDirection();
	meshObject.SetPosition(local_18);

}

