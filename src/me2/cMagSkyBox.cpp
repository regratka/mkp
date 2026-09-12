#include "cMagSkyBox.h"

#include "cMagMeshMgr.h"
#include "cMagEngineMgr.h"

/* 10012910-10012911 00001	*/
void cMagSkyBox::RestoreSkyBox() {
}

/* 10058EA0-10058EA7 00007	*/
bool cMagSkyBox::IsEnabled() {
	return enableRendering;
}

/* 1005A5E0-1005A5E3 00003	*/
void cMagSkyBox::InitDeviceObjects(cMagGameObject* param_1) {
}

/* 100727F0-100728D3 000E3	*/
cMagSkyBox::cMagSkyBox() {
	SetObjectName("No name");
	SetClassName("cMagSkyBox");
	unk_277c = 1.0f;
	unk_2780 = 1.0f;
	mesh = NULL;
	shouldUseDayCycle = false;
	currentDayTextureIndex = 0;
	nextDayTextureIndex = 0;
	unk_2aed = false;
	lastTickTime = 0.0;
	posY = -10.3f;
	ticksToChangeDay = 0xff;
	shouldGoDayDown = true;
}

/* 100728E0-1007295C 0007C	*/
cMagSkyBox::~cMagSkyBox() {
}

/* 10072960-100729EB 0008B	*/
void cMagSkyBox::CreateSkyBox(char* param_1) {
	strcpy(meshPath, param_1);
	try {
		mesh = cMagMeshMgr::getInstance()->GetMesh(param_1);
		if (mesh == NULL) {
			EnableRendering(false);
			CrashLog("[ERROR] Can`t load skybox: %s", param_1);
		}
	}
	 catch(...) {
		EnableRendering(false);
		CrashLog("[ERROR] Can`t load skybox: %s", param_1);
	}
	D3DXVECTOR3 DVar2(200.0f, 200.0f, 200.0f);
	SetScale(DVar2);
	D3DXMatrixIdentity(&rotateMatrix);
}

/* 10072AD0-10072ADD 0000D	*/
void cMagSkyBox::SetPosY(float param_1) {
	posY = param_1;
}

/* 10072AE0-10072B34 00054	*/
void cMagSkyBox::SetScale(D3DXVECTOR3 param_1) {
	D3DXMatrixIdentity(&scaleMatrix);
	D3DXMatrixScaling(&scaleMatrix, param_1.x, param_1.y, param_1.z);
	
}

/* 10072B40-10072D72 00232	*/
void cMagSkyBox::Render(D3DXMATRIX& param_1) {
	if (!enableRendering) {
		return;
	}

	D3DXMATRIX local_80 = param_1;
	D3DXMATRIX local_40 = param_1;
	local_80(3,0) = 0.0f;
	local_80(3,1) = posY;
	local_80(3,2) = 0.0f;

	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_VIEW, &local_80);
	D3DXMatrixIdentity(&worldMat);
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_WORLD, &worldMat);
	unk_1448 = scaleMatrix;
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_WORLD, &unk_1448);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_LIGHTING, FALSE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_CULLMODE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHAREF, 2);
	MagTextureMgr::getInstance()->BeginFilterTexture();
	MagTextureMgr::getInstance()->BeginFilterVertexColorTexture();
	MagTextureMgr::getInstance()->BeginAlphaTexture();

	if (shouldUseDayCycle) {
		cpuTicker.Measure();
		double dVar8 = cpuTicker.GetTickCountAsSeconds();
		lastTickTime = dVar8;
		double fVar11;
		if (unk_1e98 == 0.0) {
			fVar11 = 0.0;
			unk_1e98 = dVar8;
		} else {
			fVar11 = dVar8 - unk_1e98;
		}

		if (shouldGoDayDown) {
			DayDown(fVar11);
		} else {
			DayUp(fVar11);
		}
	} else if (mesh != NULL) {
		mesh->Render(unk_1448, NULL);
	}
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_VIEW, &local_40);
}

/* 10072D80-10072E2F 000AF	*/
void cMagSkyBox::DayDown(float param_1) {
	if (param_1 <= 0.02f) {
		return;
	}

	ticksToChangeDay--;
	unk_1e98 = lastTickTime;
	if (ticksToChangeDay > 0) {
		return;
	} 
	ticksToChangeDay = 0xff;
	currentDayTextureIndex++;
	nextDayTextureIndex = currentDayTextureIndex+1;

	if (currentDayTextureIndex >= textures.size() - 1) {
		currentDayTextureIndex = textures.size() - 1;
		shouldGoDayDown = false;
	}
}

/* 10072E30-10072E8E 0005E	*/
void cMagSkyBox::DayUp(float param_1) {
	if (param_1 <= 0.02f) {
		return;
	}

	ticksToChangeDay--;
	unk_1e98 = lastTickTime;
	if (ticksToChangeDay > 0) {
		return;
	} 

	ticksToChangeDay = 0;
	currentDayTextureIndex--;
	nextDayTextureIndex = currentDayTextureIndex-1;

	if (currentDayTextureIndex < 0) {
		currentDayTextureIndex = 0;
		shouldGoDayDown = true;
	}
}

/* 10072E90-10072EBF 0002F	*/
void cMagSkyBox::OnRender() {
	D3DXMATRIX local_40;
	cMagEngineMgr::getInstance()->engine->GetTransform(D3DTS_VIEW, &local_40);
	Render(local_40);
}

/* 10072EC0-10072F21 00061	*/
void cMagSkyBox::GetBBox(D3DXVECTOR3& param_1, D3DXVECTOR3& param_2) {
	D3DXVECTOR3 local_18(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 local_c(0.0f, 0.0f, 0.0f);
	D3DXVec3TransformCoord(&param_1, &local_18, &unk_1448);
	D3DXVec3TransformCoord(&param_2, &local_c, &unk_1448);
}

/* 10072F30-100730F7 001C7	*/
void cMagSkyBox::AddTexture(char* param_1) {
	textures.push_back(MagTextureMgr::getInstance()->GetTexture(param_1));
}

