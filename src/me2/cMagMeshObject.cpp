#include "cMagMeshObject.h"

#include "CGame.h"
#include "cMagEngineMgr.h"
#include "cMagLight.h"
#include "MagProfile.h"
#include "cMagMeshMgr.h"
#include "CAlphaObject.h"
#include "CCamera.h"

/* 10051E50-10052DEC 00F9C	*/
cMagMeshObject::cMagMeshObject() {
}

/* 10052DF0-100530E2 002F2	*/
cMagMeshObject::~cMagMeshObject() {
	if (magQuadBuffer != NULL) {
		magQuadBuffer->Release();
		magQuadBuffer = NULL;
	}
	if (lineTexture != NULL) {
		(*lineTexture)->Release();
	}
	DeletePatrols();
	ClearSound();
	DebugLog("------ Destruktor cMagMeshObject -------: %s", GetObjectName());
}

/* 100531E0-100534BB 002DB	*/
int cMagMeshObject::Is3dmFile(char* param_1) {
	std::ifstream fileStream;
	fileStream.open(param_1);

	if (!fileStream.good()){
		CrashLog("Can`t open file: %s", param_1);
		return -1;
	}

	char signatureBuffer[3];
	fileStream.read(signatureBuffer, 3);
	if (strncmp(signatureBuffer, "MEM", 3) == 0) {
		fileStream.close();
		unk_ed2 = true;
		return 2;
	}

	if (strncmp(signatureBuffer, "MAG", 3) == 0
		|| strncmp(signatureBuffer, "MES", 3) == 0
		|| strncmp(signatureBuffer, "M3D", 3) == 0) {
		fileStream.close();
		unk_ed1 = true;
		return 1;
	}
	fileStream.close();
	return -1;
}

/* 100534C0-10053A27 00567	*/
void cMagMeshObject::LoadMesh(char* param_1) {
	unk_eca = true;
	DataLog("[MESH]:%s", param_1);
	strcpy(fileMeshName, CreateNiceString(param_1));
	strcpy(filePath, param_1);

	char exclamationMeshFilepath[300];
	char exclamationMeshFilepath2[300];
	strcpy(exclamationMeshFilepath, "data\\Interface\\wykrzyknik.3DM");
	strcpy(exclamationMeshFilepath2, "data\\Interface\\wykrzyknik.3DM");
	try {
		cMagGameObject* gameObject = cMagEngineMgr::getInstance()->gameObject;
		if (gameObject->dataPath != NULL) {
			sprintf(exclamationMeshFilepath, "%s%s", cMagEngineMgr::getInstance()->gameObject->dataPath, param_1);
			
			cMagGameObject* gameObject = cMagEngineMgr::getInstance()->gameObject;
			sprintf(exclamationMeshFilepath2, "%s%s", gameObject->dataPath, "data\\Interface\\wykrzyknik.3DM");
			if (Is3dmFile(exclamationMeshFilepath) == -1) {
				MagProfile::getInstance()->ProfileLoadBegin(param_1);
				cMagMeshMgr* meshMgr = cMagMeshMgr::getInstance();
				staticMesh = meshMgr->GetMesh(exclamationMeshFilepath2);
				if (staticMesh == NULL) {
					CrashLog("[ERROR] can`t load mesh %s", param_1);
				}
				unk_ed1 = true;
				enableFrustum = false;
				SetDirection(0.0f,0.0f,0.0f);
				MagProfile::getInstance()->ProfileLoadEnd();
				return;
			}

			if (unk_ed1) {
				MagProfile::getInstance()->ProfileLoadBegin(param_1);
				cMagMeshMgr* meshMgr = cMagMeshMgr::getInstance();
				staticMesh = meshMgr->GetMesh(exclamationMeshFilepath);
				if (staticMesh == NULL) {
					CrashLog("[ERROR] can`t load mesh %s", param_1);
					staticMesh = cMagMeshMgr::getInstance()->GetMesh(exclamationMeshFilepath2);
				}
				for (int index = 0; index < staticMesh->GetSurfaceCount(); index++) {
					if (staticMesh->surfaces[index].unk_174) {
						cMagEngineMgr::getInstance()->gameObject->AddAlphaMeshObjects(new CAlphaObject(&staticMesh->surfaces[index], this));
					}
				}
				MagProfile::getInstance()->ProfileLoadEnd();
			}
			if (unk_ed2) {
				MagProfile::getInstance()->ProfileLoadBegin(param_1);
				studioMesh = new IStudioMesh();
				bool loaded = studioMesh->LoadMesh(exclamationMeshFilepath, this);
				if (!loaded) {
					if (studioMesh != NULL) {
						delete studioMesh;
					}
					studioMesh = NULL;
					staticMesh = cMagMeshMgr::getInstance()->GetMesh(exclamationMeshFilepath2);
					if (staticMesh == NULL) {
						CrashLog("[ERROR] can`t load mesh %s", param_1);
					}
					unk_ed2 = false;
					unk_ed1 = true;
					enableFrustum = false;
				} else {
					studioMesh->SetShadowType(0);
					studioMesh->EnableLight(false);
				}
				MagProfile::getInstance()->ProfileLoadEnd();
			}
		} else {
			if (Is3dmFile(param_1) == -1) {
				MagProfile::getInstance()->ProfileLoadBegin(param_1);
				staticMesh = cMagMeshMgr::getInstance()->GetMesh(exclamationMeshFilepath2);
				if (staticMesh == NULL) {
					CrashLog("[ERROR] can`t load mesh %s", param_1);
				}
				unk_ed1 = true;
				enableFrustum = false;
				SetDirection(0.0f,0.0f,0.0f);
				MagProfile::getInstance()->ProfileLoadEnd();
				return;
			}

			if (unk_ed1) {
				MagProfile::getInstance()->ProfileLoadBegin(param_1);
				staticMesh = cMagMeshMgr::getInstance()->GetMesh(param_1);
				if (staticMesh == NULL) {
					CrashLog("[ERROR] can`t load mesh %s", param_1);
					staticMesh = cMagMeshMgr::getInstance()->GetMesh(exclamationMeshFilepath2);
				}
				for (int index = 0; index < staticMesh->GetSurfaceCount(); index++) {
					if (staticMesh->surfaces[index].unk_174) {
						cMagEngineMgr::getInstance()->gameObject->AddAlphaMeshObjects(new CAlphaObject(&staticMesh->surfaces[index], this));
					}
				}
				MagProfile::getInstance()->ProfileLoadEnd();
			}
			if (unk_ed2) {
				MagProfile::getInstance()->ProfileLoadBegin(param_1);
				studioMesh = new IStudioMesh();
				bool loaded = studioMesh->LoadMesh(param_1, this);
				if (loaded) {
					studioMesh->SetShadowType(0);
					studioMesh->EnableLight(false);
				} else {
					if (studioMesh != NULL) {
						delete studioMesh;
					}
					studioMesh = NULL;
					staticMesh = cMagMeshMgr::getInstance()->GetMesh(exclamationMeshFilepath2);
					if (staticMesh == NULL) {
						CrashLog("[ERROR] can`t load mesh %s", param_1);
					}
					unk_ed2 = false;
					unk_ed1 = true;
					enableFrustum = false;
				}
				MagProfile::getInstance()->ProfileLoadEnd();
			}
		}	
		InitBoundingBox();
	} catch (...) {
		CrashLog("Can`t load mesh: %s   (error)", param_1);
		staticMesh = cMagMeshMgr::getInstance()->GetMesh(exclamationMeshFilepath2);
		unk_ed1 = true;
  		enableFrustum = false;
	}
	SetDirection(0.0f,0.0f,0.0f);
	LoadLod(param_1);
}

/* 10053AA0-10053B25 00085	*/
void cMagMeshObject::SetPosition(D3DXVECTOR3 param_1) {
	positionVector = param_1;
	D3DXMatrixIdentity(&computationMatrix);
	D3DXMatrixTranslation(&computationMatrix, positionVector.x, positionVector.y, positionVector.z);
	translationMatrix = computationMatrix;
}

/* 10053B30-10053BB5 00085	*/
void cMagMeshObject::SetScale(D3DXVECTOR3 param_1) {
	scaleVector = param_1;
	D3DXMatrixIdentity(&computationMatrix);
	D3DXMatrixScaling(&computationMatrix, scaleVector.x, scaleVector.y, scaleVector.z);
	scaleMatrix = computationMatrix;
}

/* 10053BC0-10053C01 00041	*/
D3DXVECTOR3 cMagMeshObject::GetPosition() {
	D3DXVECTOR3 pos;
	pos.x = translationMatrix(3,0);
	pos.y = translationMatrix(3,1);
	pos.z = translationMatrix(3,2);
	return pos;
}

/* 10053C10-10053C31 00021	*/
D3DXVECTOR3 cMagMeshObject::GetScale() {
	return scaleVector;
}

/* 10053C40-10053C5A 0001A	*/
D3DXMATRIX cMagMeshObject::GetRotateMatrix() {
	return rotateMatrix;
}

/* 10053C60-10053C78 00018	*/
void cMagMeshObject::SetRotateMatrix(D3DXMATRIX param_1) {
	rotateMatrix = param_1;

}

/* 10053C80-10053C92 00012	*/
int cMagMeshObject::GetFrameCount() {
	if (studioMesh == NULL) {
		return 0;
	}
	return studioMesh->GetFrameCount();
}

/* 10053CA0-10053CC8 00028	*/
bool cMagMeshObject::InitAnimSeq(char* param_1, int param_2, int param_3) {
	if (studioMesh == NULL) {
		return false;
	}
 	studioMesh->InitAnimSeq(param_1, param_2, param_3);
	return true;
}

/* 10053CD0-10053CD5 00005	*/
bool cMagMeshObject::InitAnimSeq(char* param_1, char* param_2, int param_3, int param_4, int param_5, char* param_6) {
	return false;
}

/* 10053CE0-10053CF7 00017	*/
void cMagMeshObject::DeleteAnimSeq(char* param_1) {
	if (studioMesh != NULL) {
		studioMesh->DeleteAnimSeq(param_1);
	}
}

/* 10053D00-10053D10 00010	*/
void cMagMeshObject::DeleteAllAnimSeq() {
	if (studioMesh != NULL) {
		studioMesh->DeleteAllAnimSeq();
	}
}

/* 10053D10-10053D39 00029	*/
void cMagMeshObject::PlayAnimSeq(int param_1, int param_2) {
	InitAnimSeq("seq0", param_1, param_2);
	PlayAnim("seq0");
}

/* 10053D40-10053D5F 0001F	*/
void cMagMeshObject::SetAnimFreq(char* param_1, int param_2) {
	if (studioMesh != NULL) {
		studioMesh->SetAnimFreq(param_1, param_2);
	}
}

/* 10053D60-10053D7C 0001C	*/
bool cMagMeshObject::IsPlaying(char* param_1) {
	if (studioMesh == NULL) {
		return false;
	}
 	return studioMesh->IsPlaying(param_1);
}

/* 10053D80-10053D9B 0001B	*/
void cMagMeshObject::StopAnim(char* param_1) {
	if (param_1 != NULL && studioMesh != NULL) {
		studioMesh->StopAnim(param_1);
	}
}

/* 10053DA0-10053DC3 00023	*/
bool cMagMeshObject::PlayAnim(char* param_1, int param_2) {
	if (studioMesh == NULL) {
		return false;
	}
 	studioMesh->PlayAnim(param_1, param_2);
	return true;
}

/* 10053DD0-10053DE7 00017	*/
void cMagMeshObject::EnableAnimKeys(bool param_1) {
	if (studioMesh != NULL) {
		studioMesh->EnableAnimKeys(param_1);
	}
}

/* 10053DF0-10053E07 00017	*/
void cMagMeshObject::SetMeshType(int param_1) {
	if (studioMesh != NULL) {
		studioMesh->SetMeshType(param_1);
	}
}

/* 10053E10-10053E29 00019	*/
bool cMagMeshObject::PlayAnim(char* param_1) {
	if (studioMesh != NULL) {
		studioMesh->PlayAnim(param_1);
	}
	return false;
}

/* 10053E30-10053E35 00005	*/
bool cMagMeshObject::InitAnimSeq(char* param_1) {
	return false;
}

/* 10053E30-10053E35 00005	*/
bool cMagMeshObject::PlayAnim1(char* param_1) {
	return false;
}

/* 10053E30-10053E35 00005	*/
bool cMagMeshObject::PlayAnimBack(char* param_1) {
	return false;
}

/* 10053E40-10053EDE 0009E	*/
int cMagMeshObject::FrameRate() {
	if (unkn_1320) {
		frameRate = 0.0f;
		unkn_1320 = false;
	}

	float time = timeGetTime() * 0.001f;
	framesSinceLastMeasure += 1.0f;
	if (time - lastMeasureTime > 1.0f) {
		frameRate = framesSinceLastMeasure / (time - lastMeasureTime);
		framesSinceLastMeasure = 0.0f;
		lastMeasureTime = time;
		return frameRate;
	}
	return frameRate;
}

/* 10053EF0-10053EFD 0000D	*/
void cMagMeshObject::OnAnimEnd1(char* param_1) {
	CallOnAnimEnd(param_1);
}

/* 10053F00-10053F2F 0002F	*/
bool cMagMeshObject::OnPlayAnim() {
	if (studioMesh == NULL) {
		return false;
	}

	studioMesh->UpdateAnimation(unkn_1448);
	return true;
}

/* 10053F30-10053F47 00017	*/
void cMagMeshObject::SetAnimMorphTime(float param_1) {
	if (studioMesh != NULL) {
		studioMesh->animMorphTime = param_1;
	}
}

/* 10053F50-10053F67 00017	*/
void cMagMeshObject::SetStepMorph(float param_1) {
	if (studioMesh != NULL) {
		studioMesh->SetStepMorph(param_1);
	}
}

/* 10053F70-10053F87 00017	*/
void cMagMeshObject::EnableMorph(bool param_1) {
		if (studioMesh != NULL) {
		studioMesh->EnableMorph1(param_1);
	}
}

/* 10053F90-10053FA2 00012	*/
void cMagMeshObject::AnimFrameMeter(char* param_1, int param_2) {
	OnAnimFrameMeter(param_1, param_2);
}

/* 10053FB0-10054400 00450	*/
void cMagMeshObject::RenderMesh() {
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FILLMODE, showWireframe ? D3DFILL_WIREFRAME : D3DFILL_SOLID);
	if (unk_ed1) {
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_LIGHTING, FALSE);	
		cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_WORLD, &worldMat);
		if (staticMesh == NULL) {
			return;
		}
		MagTextureMgr::getInstance()->BeginFilterTexture();
		MagTextureMgr::getInstance()->BeginFilterVertexColorTexture();
		MagTextureMgr::getInstance()->BeginAlphaTexture();
		if (unk_1ee4) {
			cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_SRCBLEND, unk_1ee8);
			cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_DESTBLEND, unk_1eec);
		} else {
			cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
			cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		}
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHAREF, unk_1ec4);
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_CULLMODE, cullMode);
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ZWRITEENABLE, enableZBufferWrite);
		// TODO loop
		AnimateLightMap();
		if (enableAnimTexture) {
			// TODO
			RenderAnimTexture();
			staticMesh->Render(unkn_1448, animTexture);
		} else {
			// TODO
			staticMesh->Render(unkn_1448, animTexture);
		}
	} else if (unk_ed2) {
		if (!unk_228b){
			OnPlayAnim();
		}
		cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_WORLD, &worldMat);
		MagTextureMgr::getInstance()->BeginFilterTexture();
		MagTextureMgr::getInstance()->BeginFilterVertexColorTexture();
		MagTextureMgr::getInstance()->BeginAlphaTexture();
		if (unk_1ee4) {
			cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_SRCBLEND, unk_1ee8);
			cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_DESTBLEND, unk_1eec);
		} else {
			cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
			cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		}
		cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0); 
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ZWRITEENABLE, enableZBufferWrite);
		if (studioMesh != NULL) {
			studioMesh->EnableAnimTexture(enableAnimTexture);
			if (enableAnimTexture) {
				RenderAnimTexture();
			}
			if (animTexture != NULL) {
				studioMesh->EnableAnimTexture(true);
				cMagEngineMgr::getInstance()->engine->SetTexture(0, animTexture);
			}
			studioMesh->RenderMesh(unkn_1448);
		}
		MagTextureMgr::getInstance()->EndAlphaTexture();
	}

}

/* 10054400-10054501 00101	*/
void cMagMeshObject::DrawLine(float param_1, float param_2, float param_3, float param_4) {
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE); 
	lineVertex->pos.x = param_4 * param_1;
	lineVertex->pos.y = param_4 * param_2;
	lineVertex->pos.z = param_4 * param_3;
	lineVertex->color = D3DCOLOR_ARGB(0xff, 0x0, 0xff, 0x0);
	cMagEngineMgr::getInstance()->engine->SetTexture(0, *lineTexture); 
	cMagEngineMgr::getInstance()->engine->SetVertexShader(D3DFVF_TEX1|D3DFVF_DIFFUSE|D3DFVF_XYZ); 
	cMagEngineMgr::getInstance()->engine->DrawPrimitiveUP(D3DPT_LINELIST, 1, lineVertex, 0x24);
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_COLOROP, 0);
	cMagEngineMgr::getInstance()->engine->SetTextureStageState(0, D3DTSS_COLORARG1, 0); 
}

/* 10054510-10054560 00050	*/
void cMagMeshObject::InitBoundingBox() {
	if (unk_ed1) {
		if(staticMesh != NULL) {
			staticMesh->ComputeBoundingBox(boundary1, boundary2);
		}
	} else if (unk_ed2) {
		if(studioMesh != NULL) {
			studioMesh->ComputeBoundingBox(boundary1, boundary2);
		}
	}

}

/* 10054560-1005456D 0000D	*/
void cMagMeshObject::ShowBoundingBox(bool param_1) {
	showBoundingBox = param_1;
}

/* 10054570-1005458D 0001D	*/
void cMagMeshObject::CorrectTranslationBoundingBox(D3DXVECTOR3 param_1) {
	translationBoundingBox = param_1;
}

/* 10054590-100545F8 00068	*/
void cMagMeshObject::CorrectScaleBoundingBox(D3DXVECTOR3 param_1) {
	if (param_1.x == 0.0f) {
		param_1.x = 1.0f;
	}
	if (param_1.y == 0.0f) {
		param_1.y = 1.0f;
	}
	if (param_1.z == 0.0f) {
		param_1.z = 1.0f;
	}
	scaleBoundingBox = param_1;
}

/* 10054600-10054C46 00646	*/
bool cMagMeshObject::_TestDistance(float param_1) {
	if (!enableTestDistance) {
		return true;
	}
	D3DXVECTOR3 cameraPos(0.0f,0.0f,0.0f);
	if (cMagEngineMgr::getInstance()->gameObject->GetActiveCamera() != NULL) {
		cameraPos = cMagEngineMgr::getInstance()->gameObject->GetActiveCamera()->GetPosition();
	}
	
	D3DXVECTOR3 bond111(boundary1);
	D3DXVECTOR3 bond222(boundary2);
	
	D3DXVECTOR3 vec222;
	vec222 = D3DXVECTOR3(bond222.x, bond222.y, bond222.z);
	D3DXVECTOR3 vec221;
	vec221 = D3DXVECTOR3(bond222.x, bond222.y, bond111.z);
	D3DXVECTOR3 vec212;
	vec212 = D3DXVECTOR3(bond222.x, bond111.y, bond222.z);
	D3DXVECTOR3 vec211;
	vec211 = D3DXVECTOR3(bond222.x, bond111.y, bond111.z);
	D3DXVECTOR3 vec122;
	vec122 = D3DXVECTOR3(bond111.x, bond222.y, bond222.z);
	D3DXVECTOR3 vec121;
	vec121 = D3DXVECTOR3(bond111.x, bond222.y, bond111.z);
	D3DXVECTOR3 vec112;
	vec112 = D3DXVECTOR3(bond111.x, bond111.y, bond222.z);
	D3DXVECTOR3 vec111;
	vec111 = D3DXVECTOR3(bond111.x, bond111.y, bond111.z);
	
	D3DXVECTOR3 center = D3DXVECTOR3((bond111.x + bond222.x) / 2.0f, (bond111.y + bond222.y) / 2.0f, (bond111.z + bond222.z) / 2.0f);
	
	D3DXVec3TransformCoord(&vec111, &vec111, &unkn_1448);
	D3DXVec3TransformCoord(&vec112, &vec112, &unkn_1448);
	D3DXVec3TransformCoord(&vec121, &vec121, &unkn_1448);
	D3DXVec3TransformCoord(&vec211, &vec211, &unkn_1448);
	D3DXVec3TransformCoord(&vec122, &vec122, &unkn_1448);
	D3DXVec3TransformCoord(&vec212, &vec212, &unkn_1448);
	D3DXVec3TransformCoord(&vec221, &vec221, &unkn_1448);
	D3DXVec3TransformCoord(&vec222, &vec222, &unkn_1448);
	D3DXVec3TransformCoord(&center, &center, &unkn_1448);

	float distVec4 = D3DXVec3Length(&(cameraPos-vec111));
	float distVec7 = D3DXVec3Length(&(cameraPos-vec112));
	float minDist = distVec4;
	if (distVec7 < distVec4) {
		minDist = distVec7;
	}
	float distVec00 = D3DXVec3Length(&(cameraPos-vec121));
	if (distVec00 < minDist) {
		minDist = distVec00;
	}
	float distVec2 = D3DXVec3Length(&(cameraPos-vec211));
	if (distVec2 < minDist) {
		minDist = distVec2;
	}
	float distVec6 = D3DXVec3Length(&(cameraPos-vec122));
	if (distVec6 < minDist) {
		minDist = distVec6;
	}
	float distVec0 = D3DXVec3Length(&(cameraPos-vec212));
	if (distVec0 < minDist) {
		minDist = distVec0;
	}
	float distVec1 = D3DXVec3Length(&(cameraPos-vec221));
	if (distVec1 < minDist) {
		minDist = distVec1;
	}
	float distVec3 = D3DXVec3Length(&(cameraPos-vec222));
	if (distVec3 < minDist) {
		minDist = distVec3;
	}
	float distVec5 = D3DXVec3Length(&(cameraPos-center));
	if (distVec5 < minDist) {
		minDist = distVec5;
	}

	if (2*param_1 < minDist) {
		return false;
	}

	if (param_1 < minDist && minDist < 2 * param_1) {
		unk_1ec4 = 2;
		unk_1f5e = true;
		return true;
	}

	unk_1f5e = false;
	SetAlphaGreatereQual(unk_1ec8);
	return true;
}

/* 10054C50-10054C5D 0000D	*/
bool cMagMeshObject::TestDistance(float param_1) {
	return _TestDistance(param_1);
}

/* 10054C60-10054C6D 0000D	*/
void cMagMeshObject::EnableTestSector(bool param_1) {
	enableTestSector = param_1;
}

/* 10054C70-10054FDB 0036B	*/
void cMagMeshObject::OnUpdate_() {
	TestSoundRanges();
	if (enableCallHandlerOnPlaySoundEnd) {
		bool playing = IsPlaying(unk_179c);
		if (!playing) {
			enableCallHandlerOnPlaySoundEnd = playing;
			if (handlerOnPlaySoundEnd != NULL) {
				handlerOnPlaySoundEnd->OnPlaySoundEnd(unk_179c);
				handlerOnPlaySoundEnd = NULL;
			} else {
				OnPlaySoundEnd(unk_179c);
			}
		}
	}

	if (!unk_eca || !enableRendering) {
		return;
	}

	D3DXMatrixIdentity(&worldMat);
	if (enableForceTransform) {
		D3DXMATRIX res;
		unkn_1448 = *D3DXMatrixMultiply(&res, &scaleMatrix, &forceTransformMatrix);
	} else {
		D3DXMATRIX res;
		D3DXMATRIX res2;
		D3DXMATRIX res3 = *D3DXMatrixMultiply(&res2, &scaleMatrix, &rotateMatrix);;
		unkn_1448 = *D3DXMatrixMultiply(&res, &res3, &translationMatrix);
	}
	D3DXMatrixMultiply(&worldMat, &unkn_1448, &worldMat);
	D3DXMATRIX projection;
	cMagEngineMgr::getInstance()->engine->GetTransform(D3DTS_PROJECTION, &projection);
	D3DXMATRIX view;
	cMagEngineMgr::getInstance()->engine->GetTransform(D3DTS_PROJECTION, &view);
	cMagEngineMgr::getInstance()->frustumCull->ComputeBoundingBox(boundary1, boundary2);


	D3DXMATRIX temp = unkn_1448;
	StructUnk184* structUnk184 = cMagEngineMgr::getInstance()->frustumCull->structUnk184;
	structUnk184->unk_14 = temp;
	for (int index = 0; index < 8; index++) {
		D3DXVec3TransformCoord(&structUnk184->unk_b4[index], &structUnk184->unk_54[index], &structUnk184->unk_14);
	}
	D3DXPlaneFromPoints(&structUnk184->unk_120[0], &structUnk184->unk_b4[0], &structUnk184->unk_b4[1], &structUnk184->unk_b4[2]);
	D3DXPlaneFromPoints(&structUnk184->unk_120[1], &structUnk184->unk_b4[6], &structUnk184->unk_b4[7], &structUnk184->unk_b4[5]);
	D3DXPlaneFromPoints(&structUnk184->unk_120[2], &structUnk184->unk_b4[2], &structUnk184->unk_b4[6], &structUnk184->unk_b4[4]);
	D3DXPlaneFromPoints(&structUnk184->unk_120[3], &structUnk184->unk_b4[7], &structUnk184->unk_b4[3], &structUnk184->unk_b4[5]);
	D3DXPlaneFromPoints(&structUnk184->unk_120[4], &structUnk184->unk_b4[2], &structUnk184->unk_b4[3], &structUnk184->unk_b4[6]);
	D3DXPlaneFromPoints(&structUnk184->unk_120[5], &structUnk184->unk_b4[1], &structUnk184->unk_b4[0], &structUnk184->unk_b4[4]);
	cMagEngineMgr::getInstance()->frustumCull->UpdateCull(&view, &projection);
	cMagEngineMgr::getInstance()->frustumCull->CullObjects();
	cullState = cMagEngineMgr::getInstance()->frustumCull->structUnk184->cullState;

	if (showBoundingBox) {
		cMagEngineMgr::getInstance()->frustumCull->UpdateBB(boundary1, boundary2, unk_1b10);
	}
}

/* 10054FE0-1005561B 0063B	*/
void cMagMeshObject::OnRender() {
}

/* 10055620-1005569D 0007D	*/
void cMagMeshObject::OnRenderShadow() {
	if (!enableRendering) {
		return;
	} 

	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ZENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_WORLD, &worldMat);
	if (studioMesh != NULL) {
		studioMesh->OnRenderShadow(unkn_1448);
	}
}

/* 100556A0-100556D7 00037	*/
void cMagMeshObject::SetShadowType(int param_1) {
	shadowType = param_1;
	if (studioMesh != NULL) {
		studioMesh->SetShadowType(param_1);
	}
	if (param_1 == 2) {
		GetGame()->AddShadowsObject(this);
	}
}

/* 100556E0-100556E7 00007	*/
int cMagMeshObject::GetShadowType() {
	return shadowType;
}

/* 100556F0-100556F8 00008	*/
cMagGameObject* cMagMeshObject::GetEngine() {
	return cMagEngineMgr::getInstance()->gameObject;
}

/* 10055700-10055C6C 0056C	*/
void cMagMeshObject::SetDirection(float param_1, float param_2, float param_3) {
}

/* 10055C70-10056267 005F7	*/
void cMagMeshObject::SetDirection(D3DXVECTOR3 param_1) {
}

/* 10056270-10056291 00021	*/
D3DXVECTOR3 cMagMeshObject::GetDirection() {
	return directionVector;
}

/* 100562A0-100562C7 00027	*/
void cMagMeshObject::GetDirection(float& param_1, float& param_2, float& param_3) {
	param_1 = rotateVector.x;
	param_2 = rotateVector.y;
	param_3 = rotateVector.z;
}

/* 100562D0-1005633B 0006B	*/
void cMagMeshObject::SetSpeed(D3DXVECTOR3 param_1) {
	float speed = D3DXVec3Length(&param_1);
	if (speed >= 1.0f) {
		speedVector = param_1;
		D3DXVec3Normalize(&speedDirection, &speedVector);
		speedValue = speed;
	}

}

/* 10056340-100563AA 0006A	*/
D3DXVECTOR3 cMagMeshObject::GetSpeed() {
	if (slideObject != NULL) {
		D3DXVECTOR3 slideSpeed = slideObject->GetSpeed();
		return speedVector + slideSpeed;
	}
	return speedVector;
}

/* 100563B0-100563BD 0000D	*/
void cMagMeshObject::SetGravityAcceleration(float param_1) {
	gravityAcceleration = param_1;
}

/* 100563C0-100563DD 0001D	*/
float cMagMeshObject::GetGravityAcceleration() {
	cMagMeshObject* source = this;
	while(source->slideObject != NULL) {
		source = source->slideObject;
	}
	return source->gravityAcceleration;
}

/* 100563E0-10056437 00057	*/
void cMagMeshObject::SetSpeedValue(float param_1) {
	speedValue = param_1;
	speedVector = speedDirection * param_1;
}

/* 10056440-10056447 00007	*/
float cMagMeshObject::GetSpeedValue() {
	return speedValue;
}

/* 10056450-100564A9 00059	*/
void cMagMeshObject::SetSpeedDirection(D3DXVECTOR3 param_1) {
	speedDirection = param_1;
	speedVector = speedDirection * speedValue;
}

/* 100564B0-100564D1 00021	*/
D3DXVECTOR3 cMagMeshObject::GetSpeedDirection() {
	return speedDirection;
}

/* 100564E0-100564FD 0001D	*/
void cMagMeshObject::Jump(D3DXVECTOR3 param_1) {
	fallSpeed = param_1;
}

/* 10056500-10056521 00021	*/
D3DXVECTOR3 cMagMeshObject::GetFallSpeed() {
	return fallSpeed;
}

/* 10056530-10056586 00056	*/
void cMagMeshObject::SetDestinationPos(D3DXVECTOR3 param_1, float param_2) {
	ClearDestinationPos();
	destinationPos = new D3DXVECTOR3(param_1);
	unkn_19c8 = param_2;
}

/* 10056590-100565B2 00022	*/
void cMagMeshObject::ClearDestinationPos() {
	if (destinationPos != NULL) {
		delete destinationPos;
		destinationPos = NULL;
	}
}

/* 100565C0-10056622 00062	*/
void cMagMeshObject::SetDestinationDir(D3DXVECTOR3 param_1, int param_2) {
	ClearDestinationDir();
	destinationDir = new D3DXVECTOR3(param_1);
	if (!freeDestinationDir) {
		destinationDir->y = 0.0f;
	}
	D3DXVec3Normalize(destinationDir, destinationDir);
	unk_d5c = param_2;
}

/* 10056630-10056652 00022	*/
void cMagMeshObject::ClearDestinationDir() {
	if (destinationDir != NULL) {
		delete destinationDir;
		destinationDir = NULL;
	}
}

/* 10056660-1005666D 0000D	*/
void cMagMeshObject::SetMaxAngSpeed(float param_1) {
	maxAngSpeed = param_1;
}

/* 10056670-10056677 00007	*/
float cMagMeshObject::GetMaxAngSpeed() {
	return maxAngSpeed;
}

/* 10056680-100566CE 0004E	*/
void cMagMeshObject::Rotate(float param_1, float param_2, float param_3) {
	float x,y,z;
	GetDirection(x, y, z);
	SetDirection(x + param_1, y + param_2, z + param_3);
}

/* 100566D0-100566ED 0001D	*/
void cMagMeshObject::SetAngSpeed(D3DXVECTOR3 param_1) {
	angSpeed = param_1;

}

/* 100566F0-10056711 00021	*/
D3DXVECTOR3 cMagMeshObject::GetAngSpeed() {
	return angSpeed;
}

/* 10056720-10056772 00052	*/
bool cMagMeshObject::RestrictFrameRate(float param_1) {
	float time = GetTickCount() * 0.001f;
	
	static float lastMeasureTime;
	if (time - lastMeasureTime > 1.0f / param_1) {
		lastMeasureTime = time;
		return true;
	}
	return false;
}

/* 10056780-1005679A 0001A	*/
D3DXMATRIX cMagMeshObject::GetSpace() {
	return space;
}

/* 100567A0-1005699F 001FF	*/
void cMagMeshObject::Rotate(D3DXVECTOR3 param_1, float param_2) {
}

/* 100569A0-100569AD 0000D	*/
void cMagMeshObject::EnableTestDistance(bool param_1) {
	enableTestDistance = param_1;
}

/* 100569B0-10056B6B 001BB	*/
D3DXVECTOR3 cMagMeshObject::GetBoneWorldPosition(char* param_1) {
	if (studioMesh == NULL) {
		return 0;
	}
	D3DXMATRIX matrix1;
	D3DXMatrixIdentity(&matrix1);
	D3DXMATRIX matrix2;
	D3DXMatrixIdentity(&matrix2);
	studioMesh->GetBoneMatrix(param_1, matrix1, matrix2);
	D3DXMATRIX out;
	D3DXMatrixMultiply(&out, &matrix1, &unkn_1448);
	return D3DXVECTOR3(out(3,0), out(3,1), out(3,2));
}

/* 10056B70-10056CF1 00181	*/
bool cMagMeshObject::GetBoneMatrix(char* param_1, D3DXMATRIX& param_2) {
	return 0;
}

/* 10056D00-10056D9E 0009E	*/
D3DXMATRIX cMagMeshObject::GetBoneWorldRotateMatrix(char* param_1) {
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	return matrix;
}

/* 10056DA0-10056EBB 0011B	*/
void cMagMeshObject::OnUpdateLink() {
}

/* 10056EC0-10057143 00283	*/
void cMagMeshObject::LinkToBone(cMagMeshObject* param_1, char* param_2) {
}

/* 10057150-1005729A 0014A	*/
void cMagMeshObject::UnLinkFromBone(cMagMeshObject* param_1) {
}

/* 100572A0-100572A7 00007	*/
bool cMagMeshObject::GetPhysics() {
	return physics;
}

/* 100572B0-100572B7 00007	*/
bool cMagMeshObject::GetCollision() {
	return collision;
}

/* 100572C0-100572C7 00007	*/
bool cMagMeshObject::GetCollisionScene() {
	return collisionScene;
}

/* 100572D0-100572D7 00007	*/
bool cMagMeshObject::GetCollisionObjects() {
	return collisionObjects;
}

/* 100572E0-100572E7 00007	*/
uchar cMagMeshObject::GetCollisionType() {
	return collisionType;
}

/* 100572F0-10057376 00086	*/
void cMagMeshObject::EnablePhysics(bool param_1) {
	if (GetGame() == NULL) {
		physics = param_1;
		return;
	}
	physics = param_1;

	if (!param_1 && (collision || physics)) {
		GetGame()->RemoveCollisionObject(this);
		return;
	}

	if (param_1 && !physics && !collision) {
		GetGame()->AddCollisionObject(this);
	}
}

/* 10057380-10057406 00086	*/
void cMagMeshObject::EnableCollision(bool param_1) {
}

/* 10057410-1005741D 0000D	*/
void cMagMeshObject::EnableCollisionScene(bool param_1) {
	collisionScene = param_1;
}

/* 10057420-1005742D 0000D	*/
void cMagMeshObject::EnableCollisionObjects(bool param_1) {
	collisionObjects = param_1;
}

/* 10057430-1005743D 0000D	*/
void cMagMeshObject::SetCollisionType(uchar param_1) {
	collisionType = param_1;
}

/* 10057440-1005744D 0000D	*/
void cMagMeshObject::SetSlideAngle(float param_1) {
	slideAngle = param_1;
}

/* 10057450-1005746D 0001D	*/
float cMagMeshObject::GetSlideAngle() {
	cMagMeshObject* source = this;
	while(source->slideObject != NULL) {
		source = source->slideObject;
	}
	return source->slideAngle;
}

/* 10057470-100574DE 0006E	*/
D3DXMATRIX cMagMeshObject::GetTransformMatrix() {
	D3DXMATRIX matrix1;
	D3DXMATRIX matrix2;
	D3DXMATRIX matrix3;
	D3DXMatrixMultiply(&matrix1, &scaleMatrix, &rotateMatrix);
	matrix2 = matrix1;
	D3DXMatrixMultiply(&matrix3, &matrix2, &translationMatrix);
	return matrix3;
}

/* 10057470-100574DE 0006E	*/
D3DXMATRIX cMagMeshObject::GetVolatileWorldMat() {
	D3DXMATRIX matrix1;
	D3DXMATRIX matrix2;
	D3DXMATRIX matrix3;
	D3DXMatrixMultiply(&matrix1, &scaleMatrix, &rotateMatrix);
	matrix2 = matrix1;
	D3DXMatrixMultiply(&matrix3, &matrix2, &translationMatrix);
	return matrix3;
}

/* 100574E0-100574ED 0000D	*/
void cMagMeshObject::SetSlideObject(cMagMeshObject* param_1) {
	slideObject = param_1;
}

/* 100574F0-100574F7 00007	*/
cMagMeshObject* cMagMeshObject::GetSlideObject() {
	return slideObject;
}

/* 10057500-1005755C 0005C	*/
void cMagMeshObject::AttachTo(cMagMeshObject* param_1) {
	parent = param_1;
	CallOnAttach(param_1);
	parent->OnAttachChild(this);
	if (GetCollisionType() == 1 && parent->GetCollisionType() == 1 
			&& colObject != NULL && param_1->colObject != NULL) {
		param_1->colObject->FUN100aad30(colObject);
	}
}

/* 10057560-100575C4 00064	*/
void cMagMeshObject::Detach() {
	CallOnDetach(parent);
	parent->OnDetachChild(this);
	if (GetCollisionType() == 1 && parent->GetCollisionType() == 1 
			&& colObject != NULL && parent->colObject != NULL) {
		parent->colObject->FUN100aaef0(colObject);
	}
	parent = NULL;
}

/* 100575D0-100575D7 00007	*/
cMagMeshObject* cMagMeshObject::GetParent() {
	return parent;
}

/* 100575E0-10057601 00021	*/
D3DXVECTOR3 cMagMeshObject::GetRotate() {
	D3DXVECTOR3 res;
	res.x = rotateVector.x;
	res.y = rotateVector.y;
	res.z = rotateVector.z;
	return res;
}

/* 10057610-10057643 00033	*/
void cMagMeshObject::LinkTo(cMagMeshObject* param_1) {
	linkParent = param_1;
	EnableCollisionObjects(true);
	SetCollisionType(2);
	EnableCollision(true);
	EnablePhysics(true);
}

/* 10057650-1005768B 0003B	*/
void cMagMeshObject::UnLink() {
	if (linkParent != NULL) {
		EnableCollisionObjects(false);
		SetCollisionType(2);
		EnableCollision(false);
		EnablePhysics(false);
	}
	linkParent = NULL;
}

/* 10057690-10057697 00007	*/
cMagMeshObject* cMagMeshObject::GetLinkParent() {
	return linkParent;
}

/* 100576A0-100576AD 0000D	*/
void cMagMeshObject::SetCollAction(uchar param_1) {
	collAction = param_1;
}

/* 100576B0-100576B7 00007	*/
uchar cMagMeshObject::GetCollAction() {
	return collAction;
}

/* 100576C0-10057704 00044	*/
void cMagMeshObject::SetPauseUpdatePhysics(bool param_1) {
	pauseUpdatePhysics = param_1;
}

/* 10057710-10057717 00007	*/
bool cMagMeshObject::GetPauseUpdatePhysics() {
	return pauseUpdatePhysics;
}

/* 10057720-10057808 000E8	*/
uint* cMagMeshObject::CalculateSpeed(uint* param_1) {
	return 0;
}

/* 10057810-1005781D 0000D	*/
void cMagMeshObject::SetWayType(uchar param_1) {
	wayType = param_1;
}

/* 10057820-10057827 00007	*/
uchar cMagMeshObject::GetWayType() {
	return wayType;
}

/* 10057830-1005783D 0000D	*/
void cMagMeshObject::SetSafeWayMaxYDifference(float param_1) {
	safeWayMaxYDifference = param_1;
}

/* 10057840-10057847 00007	*/
float cMagMeshObject::GetSafeWayMaxYDifference() {
	return safeWayMaxYDifference;
}

/* 10057850-100578FE 000AE	*/
bool cMagMeshObject::InitPathBMP(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2) {
	char bmpPath[200];
	ZeroMemory(bmpPath, sizeof(bmpPath));
	if (GetGame() != NULL) {
		int objectID = GetObjectID();
		sprintf(bmpPath, "%s\\paths\\%d.bmp", GetGame()->GetLevelDirectory(), objectID);
	}
	return path.Init(this, bmpPath, param_1, param_2);
}

/* 10057900-10057927 00027	*/
bool cMagMeshObject::OnPath(D3DXVECTOR3 param_1) {
	return path.OnPath(param_1);
}

/* 10057930-10057970 00040	*/
void cMagMeshObject::SetPathBMPMinMax(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2) {
	path.SetBMPMinMax(param_1, param_2);
}

/* 10057970-10057988 00018	*/
void cMagMeshObject::GetPathBMPMinMax(D3DXVECTOR3& param_1, D3DXVECTOR3& param_2) {
	path.GetBMPMinMax(param_1, param_2);
}

/* 10057990-10057A3A 000AA	*/
D3DXVECTOR3* cMagMeshObject::GetPosPathBMP(D3DXVECTOR3* param_1) {
	return 0;
}

/* 10057A40-10057BBC 0017C	*/
void cMagMeshObject::CreatePathBillboard() {
}

/* 10057BC0-10057BEE 0002E	*/
void cMagMeshObject::DisableCollideClass(char* param_1) {
	strcpy(disabledCollideClass, param_1);
}

/* 10057BF0-10057BF7 00007	*/
char* cMagMeshObject::GetDisabledCollideClass() {
	return disabledCollideClass;
}

/* 10057C00-10057C2E 0002E	*/
void cMagMeshObject::SetOnlyCollidingClass(char* param_1) {
	strcpy(onlyCollidingClass, param_1);
}

/* 10057C30-10057C37 00007	*/
char* cMagMeshObject::GetOnlyCollidingClass() {
	return onlyCollidingClass;
}

/* 10057C40-10057EA5 00265	*/
uchar cMagMeshObject::LinearSpeedFromAngSpeed(uint* param_1) {
	return 0;
}

/* 10057EB0-10057EF8 00048	*/
cMagMeshObject::PatrolPoint const * cMagMeshObject::GetPatrolPointAt(int param_1) {
	if (param_1 <= patrolPoints.size()-1 && param_1 >= 0) {
		return &patrolPoints[param_1];
	}
	return NULL;
}

/* 10057F00-10057F87 00087	*/
void cMagMeshObject::DeletePatrols() {
}

/* 10057F90-10057FB7 00027	*/
int cMagMeshObject::GetPatrolPointsCount() {
	return patrolPoints.size();
}

/* 10057FC0-10058037 00077	*/
bool cMagMeshObject::LoadVideo(char* param_1) {
	videoPlayer = new cVideoPlayer();
	videoPlayer->Load(param_1);
	return true;
}

/* 10058080-1005809A 0001A	*/
void cMagMeshObject::PlayVideo() {
}

/* 100580A0-100581BD 0011D	*/
bool cMagMeshObject::LoadMp3Sound(char* param_1) {
	return 0;
}

/* 100581E0-10058201 00021	*/
void cMagMeshObject::SetMp3Volume(float param_1) {
}

/* 10058210-1005822A 0001A	*/
void cMagMeshObject::PlayMp3Sound() {
}

/* 10058230-1005824A 0001A	*/
void cMagMeshObject::StopMp3Sound() {
}

/* 10058250-10058276 00026	*/
bool cMagMeshObject::IsPlayingMp3Sound() {
	return 0;
}

/* 10058280-1005829C 0001C	*/
bool cMagMeshObject::IsEndMp3Sound() {
	return 0;
}

/* 100582A0-100582BA 0001A	*/
void cMagMeshObject::RewindMp3Sound() {
}

/* 100582C0-100586CC 0040C	*/
int cMagMeshObject::LoadSound(char* param_1) {
	return 0;
}

/* 100586D0-10058772 000A2	*/
void cMagMeshObject::PlaySoundA(int param_1, bool param_2) {
}

/* 10058780-10058794 00014	*/
void cMagMeshObject::EnableCallHandlerOnPlaySoundEnd(int param_1) {
	unk_179c = param_1;
	enableCallHandlerOnPlaySoundEnd = true;
}

/* 100587A0-100587BE 0001E	*/
void cMagMeshObject::EnableCallHandlerOnPlaySoundEnd(int param_1, cMagKernel* param_2) {
	unk_179c = param_1;
	enableCallHandlerOnPlaySoundEnd = true;
	handlerOnPlaySoundEnd = param_2;
}

/* 100587C0-10058850 00090	*/
void cMagMeshObject::StopSound(int param_1) {
}

/* 10058850-100588C1 00071	*/
bool cMagMeshObject::IsPlaying(int param_1) {
	return 0;
}

/* 100588D0-1005899E 000CE	*/
void cMagMeshObject::SetVolume(int param_1, float param_2) {
}

/* 100589A0-10058A10 00070	*/
void cMagMeshObject::SetFrequency(int param_1, int param_2) {
}

/* 10058A10-10058A7D 0006D	*/
void cMagMeshObject::ResetFrequency(int param_1) {
}

/* 10058A80-10058B47 000C7	*/
void cMagMeshObject::ClearSound() {
}

/* 10058B50-10058BEA 0009A	*/
void cMagMeshObject::SetDefaultSoundRanges(int param_1, float param_2, float param_3) {
}

/* 10058BF0-10058D8F 0019F	*/
void cMagMeshObject::TestSoundRanges() {
}

/* 10058D90-10058E86 000F6	*/
void cMagMeshObject::MatrixToEuler(float param_1) {
}

/* 10058E90-10058E9C 0000C	*/
void cMagMeshObject::RepairEuler(bool param_1) {
	cMagMeshObject::m_bRepairEuler = param_1;
}

/* 10058EA0-10058EA7 00007	*/
bool cMagMeshObject::EnableRendering() {
	return enableRendering;
}

/* 10058EB0-10058F2D 0007D	*/
void cMagMeshObject::OnAttachChild(cMagMeshObject* param_1) {
}

/* 10058F30-10058FB5 00085	*/
void cMagMeshObject::OnDetachChild(cMagMeshObject* param_1) {
}

/* 10058FC0-10059002 00042	*/
void cMagMeshObject::SetDestRotation(D3DXVECTOR3 param_1) {
	ClearDestRotation();
	destRotation = new D3DXVECTOR3(param_1);
}

/* 10059010-10059032 00022	*/
void cMagMeshObject::ClearDestRotation() {
	if (destRotation != NULL) {
		delete destRotation;
		destRotation = NULL;
	}
}

/* 10059040-1005905D 0001D	*/
void cMagMeshObject::SetRotationAngSpeed(D3DXVECTOR3 param_1) {
	rotationAngSpeed = param_1;
}

/* 10059060-10059280 00220	*/
void cMagMeshObject::SetMotionDirection(float param_1) {
}

/* 10059280-100592A1 00021	*/
D3DXVECTOR3 cMagMeshObject::GetRotationAngSpeed() {
	return rotationAngSpeed;
}

/* 100592B0-100592CD 0001D	*/
void cMagMeshObject::SetMotionRotationAngSpeed(D3DXVECTOR3 param_1) {
	motionRotationAngSpeed = param_1;
	
}

/* 100592D0-100592F1 00021	*/
D3DXVECTOR3 cMagMeshObject::GetMotionRotationAngSpeed() {
	return motionRotationAngSpeed;
}

/* 10059300-10059328 00028	*/
void cMagMeshObject::PauseMovableTreeCollision(bool param_1) {
}

/* 10059330-10059346 00016	*/
long cMagMeshObject::SetStaticMeshAlpha(int param_1) {
	return 0;
}

/* 10059350-1005936E 0001E	*/
bool cMagMeshObject::SetMultiple(float param_1) {
	if (staticMesh != NULL) {
		staticMesh->SetMultiple(param_1);
		return true;
	}
	return false;
}

/* 10059370-100593CC 0005C	*/
long cMagMeshObject::SetAlpha(int param_1) {
	if (studioMesh != NULL) {
		studioMesh->SetAlpha(param_1);
		return S_OK;
	}

	if (staticMesh != NULL) {
		staticMesh->SetAlpha(param_1);
		return S_OK;
	}

	if (!unk_ed1) {
		return E_FAIL;
	}
	unk_1ea4 = true;
	unk_1ea8 = param_1;
	return S_OK;
}

/* 100593D0-1005940B 0003B	*/
void cMagMeshObject::SetAlpha(ulong param_1, ulong param_2) {
	if (param_1 == 0 && param_2 == 0) {
		this->unk_1ee4 = false;
		this->unk_1ee8 = 0;
		this->unk_1eec = 0;
	} else {
		this->unk_1ee4 = true;
		this->unk_1ee8 = param_1;
		this->unk_1eec = param_2;
	}
}

/* 10059410-10059456 00046	*/
long cMagMeshObject::SetColor(float param_1, float param_2, float param_3, float param_4) {
	if (!unk_ed1) {
		return E_FAIL;
	}
	unk_1eac = true;
	unk_1eb0 = param_1;
	unk_1eb4 = param_2;
	unk_1eb8 = param_3;
	unk_1ebc = param_4;
	return S_OK;
}

/* 10059460-1005947D 0001D	*/
void cMagMeshObject::SetCullMode(int param_1) {
	cullMode = param_1;
	if (studioMesh != NULL) {
		studioMesh->SetCullMode(param_1);
	}
}

/* 10059480-10059493 00013	*/
void cMagMeshObject::SetAlphaGreatereQual(ulong param_1) {
	unk_1ec4 = param_1;
	unk_1ec8 = param_1;
}

/* 100594A0-1005971E 0027E	*/
void cMagMeshObject::AddWaterTexture(char* param_1) {
}

/* 10059720-1005972D 0000D	*/
void cMagMeshObject::SetFps(float param_1) {
	fps = param_1;
}

/* 10059730-1005973D 0000D	*/
void cMagMeshObject::SetFpsMove(float param_1) {
	fpsMove = param_1;
}

/* 10059740-1005974D 0000D	*/
void cMagMeshObject::SetVelocityAnimMove(float param_1) {
	velocityAnimMove = param_1;
}

/* 10059750-10059767 00017	*/
void cMagMeshObject::EnableWaterEffect(bool param_1) {
	if (unk_ed1) {
		enableWaterEffect = param_1;
	}
}

/* 10059770-10059778 00008	*/
void cMagMeshObject::PlayWaterAnim() {
	playWaterAnim = true;
}

/* 10059780-10059788 00008	*/
void cMagMeshObject::StopWaterAnim() {
	playWaterAnim = false;
}

/* 10059790-100597AE 0001E	*/
void cMagMeshObject::SetScaleTile(float param_1) {
	if (unk_ed1) {
		unk_1ede = true;
		scaleTile = param_1;
	}
}

/* 100597B0-100597BD 0000D	*/
void cMagMeshObject::EnableRiverEffect(bool param_1) {
	enableRiverEffect = param_1;
}

/* 100597C0-100597CD 0000D	*/
void cMagMeshObject::SetMoveWater(bool param_1) {
	moveWater = param_1;
}

/* 100597D0-100597D7 00007	*/
bool cMagMeshObject::GetFreeDestinationDir() {
	return freeDestinationDir;
}

/* 100597E0-100597ED 0000D	*/
void cMagMeshObject::SetFreeDestinationDir(bool param_1) {
	freeDestinationDir = param_1;
}

/* 100597F0-1005981F 0002F	*/
void cMagMeshObject::EnableDynamicLight(bool param_1) {
}

/* 10059820-10059B90 00370	*/
void cMagMeshObject::SetUp(float param_1) {
}

/* 10059B90-10059BB1 00021	*/
uchar cMagMeshObject::GetUp(uint* param_1) {
	return 0;
}

/* 10059BC0-10059F4D 0038D	*/
void cMagMeshObject::SetRight(float param_1) {
}

/* 10059F50-10059F71 00021	*/
uchar cMagMeshObject::GetRight(uint* param_1) {
	return 0;
}

/* 10059F80-10059F8D 0000D	*/
void cMagMeshObject::SetFreeRotationMatrix(bool param_1) {
	freeRotationMatrix = param_1;
}

/* 10059F90-10059F97 00007	*/
bool cMagMeshObject::GetFreeRotationMatrix() {
	return freeRotationMatrix;
}

/* 10059FA0-10059FBB 0001B	*/
void cMagMeshObject::SetOutsideViewPhysicsActivityRange(float param_1) {
	outsideViewPhysicsActivityRange = param_1;
	outsideViewPhysicsActivityRangePow = param_1 * param_1;
}

/* 10059FC0-10059FC7 00007	*/
float cMagMeshObject::GetOutsideViewPhysicsActivityRange() {
	return outsideViewPhysicsActivityRange;
}

/* 10059FD0-1005A053 00083	*/
bool cMagMeshObject::PhysicsActivityRange() {
	return 0;
}

/* 1005A060-1005A06D 0000D	*/
void cMagMeshObject::EnableFrustumPhysicsPause(bool param_1) {
	enableFrustumPhysicsPause = param_1;
}

/* 1005A070-1005A077 00007	*/
bool cMagMeshObject::EnableFrustumPhysicsPause() {
	return enableFrustumPhysicsPause;
}

/* 1005A080-1005A0A5 00025	*/
void cMagMeshObject::SetFrustumPhysicsPause(bool param_1) {
	if (enableFrustumPhysicsPause && param_1) {
		SetPauseUpdatePhysics(param_1);
	} else {
		SetPauseUpdatePhysics(false);
	}
}

/* 1005A0B0-1005A0B5 00005	*/
bool cMagMeshObject::GetFrustumPhysicsPause() {
	return pauseUpdatePhysics;
}

/* 1005A0C0-1005A0CD 0000D	*/
void cMagMeshObject::EnableDynamicPointLight(bool param_1) {
	enableDynamicPointLight = param_1;

}

/* 1005A0D0-1005A0FC 0002C	*/
void cMagMeshObject::AddDynamicLight(D3DLIGHT8 param_1) {
	dynamicLightID = cMagLight::getInstance()->AddDynamicLight(param_1);
}

/* 1005A100-1005A11F 0001F	*/
void cMagMeshObject::DisableDynamicLight() {
	if (dynamicLightID > 0) {
		cMagEngineMgr::getInstance()->engine->LightEnable(dynamicLightID, FALSE);
	}
}

/* 1005A120-1005A12D 0000D	*/
void cMagMeshObject::SetLightingObject(bool param_1) {
	lightingObject = param_1;
}

/* 1005A130-1005A147 00017	*/
void cMagMeshObject::SetAmbient(float param_1, float param_2, float param_3) {
}

/* 1005A150-1005A164 00014	*/
bool cMagMeshObject::JumpEnabled() {
	if (colObject == NULL) {
		return true;
	}
	return false;
}

/* 1005A170-1005A1D3 00063	*/
int cMagMeshObject::ClassifyPoint(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2, D3DXVECTOR3 param_3) {
	return 0;
}

/* 1005A1E0-1005A216 00036	*/
float cMagMeshObject::GetMagnitude(D3DXVECTOR3 param_1) {
	float length = D3DXVec3Length(&param_1);
	if (length == 0.0f) {
		return 1.0f;
	}
	return length;
}

/* 1005A220-1005A289 00069	*/
D3DXVECTOR3 cMagMeshObject::GetHelperPosition(char* param_1) {
	return 0;
}

/* 1005A290-1005A3F5 00165	*/
void cMagMeshObject::SetPhysicsType(uchar param_1) {
}

/* 1005A410-1005A417 00007	*/
uchar cMagMeshObject::GetPhysicsType() {
	return physicsType;
}

/* 1005A420-1005A489 00069	*/
uint cMagMeshObject::TraceScene(uint param_1, uint param_2, uint param_3, uint param_4, uint param_5, uint param_6, uint param_7, uint param_8, uint param_9) {
	return 0;
}

/* 1005A490-1005A49D 0000D	*/
void cMagMeshObject::EnablePushing(bool param_1) {
	enablePushing = param_1;
}

/* 1005A4A0-1005A4A7 00007	*/
bool cMagMeshObject::EnablePushing() {
	return enablePushing;
}

/* 1005A4B0-1005A5BA 0010A	*/
void cMagMeshObject::SetRotationMatrix(D3DXMATRIX param_1) {
}

/* 1005A5C0-1005A5CD 0000D	*/
void cMagMeshObject::EnableNBFacesCollision(bool param_1) {
	enableNBFacesCollision = param_1;
}

/* 1005A5D0-1005A5D7 00007	*/
bool cMagMeshObject::EnableNBFacesCollision() {
	return enableNBFacesCollision;
}

/* 1005A600-1005A60D 0000D	*/
void cMagMeshObject::ActivateLightMap(int param_1) {
	lightMap = param_1;
}

/* 1005A610-1005A641 00031	*/
void cMagMeshObject::SetEllipsoid(uint param_1, uint param_2, uint param_3) {
}

/* 1005A650-1005A67A 0002A	*/
uchar cMagMeshObject::GetEllipsoid(uint* param_1) {
	return 0;
}

/* 1005A680-1005A6AD 0002D	*/
bool cMagMeshObject::TraceObjects(uchar param_1) {
	return 0;
}

/* 1005A6B0-1005A6DD 0002D	*/
bool cMagMeshObject::TraceScene(uchar param_1) {
	return 0;
}

/* 1005A6E0-1005A749 00069	*/
void cMagMeshObject::CreateMagQuad() {
	magQuadBuffer = NULL;
	CreateQuad(&magQuadBuffer, D3DPOOL_MANAGED, 1.0, 0xffffffff, 
		cMagEngineMgr::getInstance()->engine, 1.0f, 1.0f, true);
	magQuadTexture = MagTextureMgr::getInstance()->GetTexture("red.png");
	unk_2154 = true;
	unk_ed1 = true;
	SetDirection(0.0f,0.0f,0.0f);
}

/* 1005A750-1005A76D 0001D	*/
void cMagMeshObject::SetTextureMagQuad(char* param_1) {
}

/* 1005A770-1005A886 00116	*/
void cMagMeshObject::RenderMagQuad() {
}

/* 1005A890-1005A9DE 0014E	*/
void cMagMeshObject::SetAlphaMagQuad(float param_1) {
}

/* 1005A9E0-1005A9F2 00012	*/
float cMagMeshObject::GetPhysicsFrameTime() {
	return 0;
}

/* 1005AA00-1005AA41 00041	*/
void cMagMeshObject::GetBoundingBox(D3DXVECTOR3& param_1, D3DXVECTOR3& param_2, int param_3) {
	if (param_3 == 0) {
		param_1 = boundary1;
		param_2 = boundary2;
	} 
}

/* 1005AA50-1005AA5D 0000D	*/
void cMagMeshObject::EnableAnimTexture(bool param_1) {
	enableAnimTexture = param_1;
}

/* 1005AA60-1005AA6D 0000D	*/
int cMagMeshObject::AddTexture(char* param_1) {
	return AddAnimTexture(param_1);
}

/* 1005AA70-1005AAD4 00064	*/
bool cMagMeshObject::SetTexture(int param_1) {
	return 0;
}

/* 1005AAE0-1005AB46 00066	*/
int cMagMeshObject::AddAnimTexture(char* param_1) {
	return 0;
}

/* 1005AB50-1005AB5D 0000D	*/
void cMagMeshObject::SetAnimTextureFPS(int param_1) {
	animTextureFPS = param_1;
}

/* 1005AB60-1005AB6D 0000D	*/
void cMagMeshObject::SetAnimTextureFrameCount(int param_1) {
	animTextureFrameCount = param_1;
}

/* 1005AB70-1005AC50 000E0	*/
void cMagMeshObject::RenderAnimTexture() {
}

/* 1005AC50-1005AC5D 0000D	*/
void cMagMeshObject::EnableAnimTextureMove(bool param_1) {
	enableAnimTextureMove = param_1;
}

/* 1005AC60-1005AC77 00017	*/
void cMagMeshObject::EnableAttachDynObj(bool param_1) {
}

/* 1005AC80-1005AC94 00014	*/
bool cMagMeshObject::EnableAttachDynObj() {
	return 0;
}

/* 1005ACA0-1005ACB7 00017	*/
void cMagMeshObject::EnableLastParentSpeed(bool param_1) {
}

/* 1005ACC0-1005ACD4 00014	*/
bool cMagMeshObject::EnableLastParentSpeed() {
	return 0;
}

/* 1005ACE0-1005ACED 0000D	*/
void cMagMeshObject::SetAcceleration(float param_1) {
	acceleration = param_1;
}

/* 1005ACF0-1005ACF7 00007	*/
float cMagMeshObject::GetAcceleration() {
	return acceleration;
}

/* 1005AD00-1005ADED 000ED	*/
bool cMagMeshObject::SectorRendering() {
	return 0;
}

/* 1005ADF0-1005ADFD 0000D	*/
void cMagMeshObject::DisableTestMeshInSector(bool param_1) {
	disableTestMeshInSector = param_1;
}

/* 1005AE00-1005AE45 00045	*/
void cMagMeshObject::PauseObject(bool param_1) {
}

/* 1005AE50-1005AE5D 0000D	*/
void cMagMeshObject::EnableAnimTextureLightMap(bool param_1) {
	enableAnimTextureLightMap = param_1;
}

/* 1005AE60-1005B027 001C7	*/
void cMagMeshObject::AddAnimTextureLightMap(char* param_1) {
}

/* 1005B030-1005B03D 0000D	*/
void cMagMeshObject::SetAnimTextureLightMapFPS(int param_1) {
	animTextureLightMapFPS = param_1;
}

/* 1005B040-1005B10B 000CB	*/
void cMagMeshObject::AnimateLightMap() {
}

/* 1005B110-1005B11D 0000D	*/
void cMagMeshObject::EnableZBuffeWrite(bool param_1) {
	enableZBufferWrite = param_1;
}

/* 1005B120-1005B127 00007	*/
bool cMagMeshObject::EnableZBuffeWrite() {
	return enableZBufferWrite;
}

/* 1005B130-1005B155 00025	*/
int cMagMeshObject::GetFaceCount() {
	if (studioMesh != NULL) {
		return studioMesh->GetFaceCount();
	}

	if (staticMesh != NULL) {
		return staticMesh->GetFacesCount();
	}
	return 0;
}

/* 1005B160-1005B16D 0000D	*/
void cMagMeshObject::EnableForceTransform(bool param_1) {
	enableForceTransform = param_1;
}

/* 1005B170-1005B188 00018	*/
void cMagMeshObject::SetForceTransformMatrix(D3DXMATRIX param_1) {
	forceTransformMatrix = param_1;
}

/* 1005B190-1005B1BB 0002B	*/
void cMagMeshObject::SetLightPosition(D3DXVECTOR3 param_1) {
	if (studioMesh != NULL) {
		studioMesh->SetLightPosition(param_1);
	}
}

/* 1005B1C0-1005B1D7 00017	*/
void cMagMeshObject::EnableLight(bool param_1) {
	if (studioMesh != NULL) {
		studioMesh->EnableLight(param_1);
	}
}

/* 1005B1E0-1005B206 00026	*/
void cMagMeshObject::SetMaterialDiffuse(float param_1, float param_2, float param_3, float param_4) {
	if (studioMesh != NULL) {
		studioMesh->SetMaterialDiffuse(param_1, param_2, param_3, param_4);
	}
}

/* 1005B210-1005B236 00026	*/
void cMagMeshObject::SetMaterialAmbient(float param_1, float param_2, float param_3, float param_4) {
	if (studioMesh != NULL) {
		studioMesh->SetMaterialAmbient(param_1, param_2, param_3, param_4);
	}
}

/* 1005B240-1005B266 00026	*/
void cMagMeshObject::SetLightDiffuse(float param_1, float param_2, float param_3, float param_4) {
	if (studioMesh != NULL) {
		studioMesh->SetLightDiffuse(param_1, param_2, param_3, param_4);
	}
}

/* 1005B270-1005B296 00026	*/
void cMagMeshObject::SetLightAmbient(float param_1, float param_2, float param_3, float param_4) {
	if (studioMesh != NULL) {
		studioMesh->SetLightAmbient(param_1, param_2, param_3, param_4);
	}
}

/* 1005B2A0-1005B2B7 00017	*/
void cMagMeshObject::EnableRenderShadow(bool param_1) {
	if (studioMesh != NULL) {
		studioMesh->EnableRenderShadow(param_1);
	}
}

/* 1005B2C0-1005B2D2 00012	*/
bool cMagMeshObject::EnableRenderShadow() {
	if (studioMesh != NULL) {
		return studioMesh->EnableRenderShadow();
	}
	return false;
}

/* 1005B2E0-1005B59A 002BA	*/
void cMagMeshObject::CreateBumpAndEnviromentTexture() {
}

/* 1005B5A0-1005B9A8 00408	*/
void cMagMeshObject::LoadLod(char* param_1) {
}

/* 1005B9B0-1005BB33 00183	*/
bool cMagMeshObject::_TestDistanceLOD(float param_1) {
	return 0;
}

/* 1005BB40-1005BF7E 0043E	*/
bool cMagMeshObject::CreateNavigationPath(char* param_1) {
	return 0;
}

/* 1005C280-1005C5B2 00332	*/
bool cMagMeshObject::BuildNaviPoints(D3DXVECTOR3 param_1, D3DXVECTOR3 param_2) {
	return 0;
}

/* 1005C610-1005C636 00026	*/
int cMagMeshObject::GetNaviPointsCount() {
	return 0;
}

/* 1005C640-1005C705 000C5	*/
uchar cMagMeshObject::GetNaviPointAt(uint* param_1, uint param_2) {
	return 0;
}

/* 1005C710-1005C7B5 000A5	*/
uchar cMagMeshObject::GotoRandomLocation(uint* param_1) {
	return 0;
}

/* 100393E0-10039435 00055	*/
char* cMagMeshObject::CreateNiceString(char* param_1) {
	if (strstr(param_1,"\\") != 0) {
		return strtok(strrchr(param_1, '\\'), "\\");
	} 
	if (strstr(param_1,"/") != 0) {
		return strtok(strrchr(param_1, '/'), "/");
	} 
	return param_1;
}