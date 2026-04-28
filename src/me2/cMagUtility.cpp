#include "cMagUtility.h"

#include "cMagEngineMgr.h"

/* 1002D170-1002D1EE 0007E	*/
cMagUtility::cMagUtility() {
	SetObjectName("No name");
	SetClassName("cMagUtility");
}

/* 1002D1F0-1002D1FB 0000B	*/
cMagUtility::~cMagUtility() {
}

/* 1002D200-1002D20D 0000D	*/
void cMagUtility::InitDeviceDx(cMagGameObject* param_1) {
	deviceDx = param_1;
}

/* 1002D210-1002D253 00043	*/
void cMagUtility::D3DUtil_InitMaterial(D3DMATERIAL8& param_1, float param_2, float param_3, float param_4, float param_5) {
	ZeroMemory(&param_1, sizeof(D3DMATERIAL8));
    param_1.Diffuse.r = param_1.Ambient.r = param_2;
    param_1.Diffuse.g = param_1.Ambient.g = param_3;
    param_1.Diffuse.b = param_1.Ambient.b = param_4;
    param_1.Diffuse.a = param_1.Ambient.a = param_5;
}

/* 1002D260-1002D2D2 00072	*/
void cMagUtility::D3DUtil_InitLight(D3DLIGHT8& param_1, D3DLIGHTTYPE param_2, float param_3, float param_4, float param_5) {
	ZeroMemory(&param_1, sizeof(D3DLIGHT8));
	param_1.Type = param_2;
	param_1.Diffuse.r = 1.0f;
	param_1.Diffuse.g = 1.0f;
	param_1.Diffuse.b = 1.0f;
	D3DXVec3Normalize((D3DXVECTOR3*)&param_1.Direction, &D3DXVECTOR3(param_3, param_4, param_5));
	param_1.Position.x = param_3;
	param_1.Position.y = param_4;
	param_1.Position.z = param_5;
	param_1.Range = 1000.0f;
}

/* 1002D2E0-1002D661 00381	*/
HRESULT cMagUtility::CreateQuad(IDirect3DVertexBuffer8** param_1, D3DPOOL param_2, float param_3, ulong param_4, IDirect3DDevice8* param_5, float param_6, float param_7, bool param_8) {
	HRESULT result = param_5->CreateVertexBuffer(216, 0, D3DFVF_TEX1|D3DFVF_DIFFUSE|D3DFVF_XYZ, param_2, param_1);
	if (result < S_OK) {
		return result;
	}
	float half_pos = param_3 / 2.0f;
	MAGVERTEX* data;
	result = (*param_1)->Lock(0, 216, (BYTE**)&data, 0);
	if (result < S_OK) {
		return result;
	}

	if (param_8) {
		data[0].pos.x = -half_pos;
		data[0].pos.y = half_pos;
		data[0].pos.z = 0.0f;
		data[0].color = param_4;
		data[0].u = 0.0f;
		data[0].v = 0.0f;
	} else {
		data[0].pos.x = -half_pos;
		data[0].pos.y = half_pos + 0.5f;
		data[0].pos.z = 0.0f;
		data[0].color = param_4;
		data[0].u = 0.0f;
		data[0].v = 0.0f;
	}

	if (param_8) {
		data[1].pos.x = half_pos;
		data[1].pos.y = half_pos;
		data[1].pos.z = 0.0f;
		data[1].color = param_4;
		data[1].u = param_6;
		data[1].v = 0.0f;
	} else {
		data[1].pos.x = half_pos;
		data[1].pos.y = half_pos + 0.5f;
		data[1].pos.z = 0.0f;
		data[1].color = param_4;
		data[1].u = param_6;
		data[1].v = 0.0f;
	}

	if (param_8) {
		data[2].pos.x = half_pos;
		data[2].pos.y = -half_pos;
		data[2].pos.z = 0.0f;
		data[2].color = param_4;
		data[2].u = param_6;
		data[2].v = param_7;
	} else {
		data[2].pos.x = half_pos;
		data[2].pos.y = 0.0f;
		data[2].pos.z = 0.0f;
		data[2].color = param_4;
		data[2].u = param_6;
		data[2].v = param_7;
	}

	if (param_8) {
		data[3].pos.x = -half_pos;
		data[3].pos.y = half_pos;
		data[3].pos.z = 0.0f;
		data[3].color = param_4;
		data[3].u = 0.0f;
		data[3].v = 0.0f;
	} else {
		data[3].pos.x = -half_pos;
		data[3].pos.y = half_pos + 0.5f;
		data[3].pos.z = 0.0f;
		data[3].color = param_4;
		data[3].u = 0.0f;
		data[3].v = 0.0f;
	}

	if (param_8) {
		data[4].pos.x = half_pos;
		data[4].pos.y = -half_pos;
		data[4].pos.z = 0.0f;
		data[4].color = param_4;
		data[4].u = param_6;
		data[4].v = param_7;
	} else {
		data[4].pos.x = half_pos;
		data[4].pos.y = 0.0f;
		data[4].pos.z = 0.0f;
		data[4].color = param_4;
		data[4].u = param_6;
		data[4].v = param_7;
	}

	if (param_8) {
		data[5].pos.x = -half_pos;
		data[5].pos.y = -half_pos;
		data[5].pos.z = 0.0f;
		data[5].color = param_4;
		data[5].u = 0.0f;
		data[5].v = param_7;
	} else {
		data[5].pos.x = -half_pos;
		data[5].pos.y = 0.0f;
		data[5].pos.z = 0.0f;
		data[5].color = param_4;
		data[5].u = 0.0f;
		data[5].v = param_7;
	}

	result = (*param_1)->Unlock();
	if (result < S_OK) {
		return result;
	}
	return S_OK;
}

/* 1002DE90-1002DF8F 000FF	*/
int cMagUtility::LoadBitmapToSurface(char* param_1, IDirect3DSurface8** param_2, IDirect3DDevice8* param_3) {
	HANDLE imageHandle = LoadImage(NULL, param_1, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION|LR_LOADFROMFILE);
	if (imageHandle == NULL) {
		this->magLog.FileLog("Unable to load bitmap");
		return E_FAIL;
	}

	BITMAP bitmap;
	GetObject(imageHandle, sizeof(BITMAP), &bitmap);
	DeleteObject(imageHandle);
	HRESULT result = param_3->CreateImageSurface(bitmap.bmWidth, bitmap.bmHeight, D3DFMT_A8R8G8B8, param_2);
	if (result < S_OK) {
		DebugLog("-------------- %d %d", bitmap.bmWidth, bitmap.bmHeight);
		this->magLog.FileLog("Unable to create surface for bitmap load");
		return E_FAIL;
	}

	result = D3DXLoadSurfaceFromFile(*param_2, NULL, NULL, param_1, NULL, D3DX_FILTER_NONE, 0, NULL);
	if (result < S_OK) {
		this->magLog.FileLog("Unable to load file to surface");
		return E_FAIL;
	}

	return S_OK;
}

/* 1002DF90-1002E070 000E0	*/
long cMagUtility::LoadAlphabet(char* param_1, int param_2, int param_3) {
	if (param_1 == NULL || param_2 == 0 || param_3 == 0) {
		return E_FAIL;
	}

	DebugLog("%s", param_1);
	cMagEngineMgr* mgr =  cMagEngineMgr::getInstance();
	int result = LoadBitmapToSurface(param_1, &surface, mgr->engine);
	if (result < S_OK) {
		this->magLog.FileLog("Unable to load alphabet bitmap");
		return E_FAIL;
	}
	D3DSURFACE_DESC surfaceDesc;
	surface->GetDesc(&surfaceDesc);
	width = surfaceDesc.Width;
	height = surfaceDesc.Height;
	unkn_d34 = param_2;
	unkn_d38 = param_3;
	unkn_d3c = width / unkn_d34;
	alphabetLoaded = TRUE;

	DebugLog("%d %d %d %d %d", width, height, unkn_d34, unkn_d38, unkn_d3c);
	return S_OK;
}

/* 1002E070-1002E09B 0002B	*/
HRESULT cMagUtility::UnloadAlphabet() {
	if (surface != NULL) {
		surface->Release();
		surface = NULL;
		alphabetLoaded = FALSE;
	}
	return S_OK;
	
}

/* 1002E0A0-1002E270 001D0	*/
void cMagUtility::PrintChar(int param_1, int param_2, char param_3, int param_4, ulong param_5, ulong* param_6, int param_7) {
	if (!alphabetLoaded) {
		return;
	}
  
	RECT rect = {0,0,0,0};
	this->magLog.DebugLog("-----------1------------");
	div_t res = div(param_3 - ' ', unkn_d3c);
	int xLeft = unkn_d34 * res.rem;
	int yTop = unkn_d38 * res.quot;
	SetRect(&rect, xLeft, yTop, unkn_d34 + xLeft, unkn_d38 + yTop);
	this->magLog.DebugLog("-----------3------------");
	D3DLOCKED_RECT lockedRect;
	HRESULT result = surface->LockRect(&lockedRect, NULL, D3DLOCK_READONLY);
	if (result < S_OK) {
		this->magLog.FileLog("Couldnt lock alphabet surface for PrintChar()");
		return;
	}
	this->magLog.DebugLog("-----------4------------");

	


}

/* 1002E270-1002E2EF 0007F	*/
void cMagUtility::PrintString(int param_1, int param_2, char* param_3, int param_4, ulong param_5, ulong* param_6, int param_7) {
}

/* 1002E2F0-1002E4FA 0020A	*/
long cMagUtility::CopySurfaceToSurface(tagRECT* param_1, IDirect3DSurface8* param_2, tagPOINT* param_3, IDirect3DSurface8* param_4, int param_5, ulong param_6) {
	return 0;
}

