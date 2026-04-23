#include "cFX_Shockwave.h"

#include "cMagEngineMgr.h"
#include "MagTextureMgr.h"

/* 100764E0-10076544 00064	*/
cFX_Shockwave::~cFX_Shockwave() {
	if (vertexBuffer != NULL) {
		vertexBuffer->Release();
		vertexBuffer = NULL;
	}
}

/* 10076550-10076852 00302	*/
HRESULT cFX_Shockwave::RestoreDeviceObjects(char const* param_1, float param_2, float param_3, int param_4, float param_5, float param_6) {
	this->engine = cMagEngineMgr::getInstance()->engine;
	this->range = param_2;
	this->sections = param_4;
	this->radius = param_3;
	this->scaleGrowth = param_5;
	this->duration = param_6;

	if (param_4 < 4) {
		return E_FAIL;
	}

	this->verticesAmount = param_4 * 6; // liczba sekcji * liczba wierzchołków w sekcji
	this->texture = MagTextureMgr::getInstance()->GetTexture(param_1);
	HRESULT result = this->engine->CreateVertexBuffer(this->verticesAmount * 36, D3DUSAGE_WRITEONLY, D3DFVF_TEX1 | D3DFVF_DIFFUSE | D3DFVF_XYZ, 
		D3DPOOL_MANAGED, &this->vertexBuffer);
	if (result < S_OK) {
		return result;
	}

	float* data;
	result = this->vertexBuffer->Lock(0, 0, (BYTE**)&data, 0);
	if (result < S_OK) {
		return result;
	}

	float angle = 0.0f;
	while (angle < 360.0f) {
		float var_2 = cos(GpgDegToRad(angle));
		float var_3 = this->range * var_2;
		float var_4 = sin(GpgDegToRad(angle));
		float var_5 = this->range * var_4;
		float var_6 = this->range - this->radius;

		angle += 360.0f / param_4;

		float var_7 = cos(GpgDegToRad(angle));
		float var_8 = sin(GpgDegToRad(angle));

		data[0] = var_2 * var_6;
		data[1] = 0.0f;
		data[2] = var_4 * var_6;
		((int*)data)[3] = 0xffffffff;
		data[4] = 0.0f;
		data[5] = 1.0f;

		data[9] = var_3;
		data[10] = 0.0f;
		data[11] = var_5;
 		((int*)data)[12] = 0xffffffff;
		data[13] = 0.0f;
		data[14] = 0.0f;

		data[18] = var_6 * var_7;
		data[19] = 0.0f;
		data[20] = var_6 * var_8;
		((int*)data)[21] = 0xffffffff;
		data[22] = 1.0f;
		data[23] = 1.0f;
		
		data[27] = var_3;
		data[28] = 0.0f;
		data[29] = var_5;
 		((int*)data)[30] = 0xffffffff;
		data[31] = 0.0f;
		data[32] = 0.0f;

		data[36] = this->range * var_7;
		data[37] = 0.0f;
		data[38] = this->range * var_8;
 		((int*)data)[39] = 0xffffffff;
		data[40] = 1.0f;
		data[41] = 0.0f;

		data[45] = var_6 * var_7;
		data[46] = 0.0f;
		data[47] = var_6 * var_8;
		((int*)data)[48] = 0xffffffff;
		data[49] = 1.0f;
		data[50] = 1.0f;

		data += 54;
	}
	this->vertexBuffer->Unlock();
}

/* 10076860-100768C0 00060	*/
void cFX_Shockwave::SetAlpha(int param_1) {
	int* data;
	HRESULT result = this->vertexBuffer->Lock(0, 0, (BYTE**)&data, 0);
	if (result < S_OK) {
		return;
	}

	for (int index = 0; index < verticesAmount; index++) {
		data[3] = D3DCOLOR_ARGB(param_1, 0xFF, 0xFF, 0xFF);
		data += 9;
	}
	this->vertexBuffer->Unlock();
}

/* 100768C0-100768F9 00039	*/
void cFX_Shockwave::InvalidateDeviceObjects() {
	if (this->texture != NULL) {
		this->texture->Release();
		this->texture = NULL;
	}

	if (this->vertexBuffer != NULL) {
		this->vertexBuffer->Release();
		this->vertexBuffer = NULL;
	}
}

/* 10076900-10076B79 00279	*/
void cFX_Shockwave::ShockwaveRender() {
	D3DXMATRIX translationMatrix, scaleMatrix;
	D3DXMatrixIdentity(&translationMatrix);
	D3DXMatrixIdentity(&scaleMatrix);
	D3DXMatrixTranslation(&translationMatrix, position.x, position.y, position.z);
	D3DXMatrixScaling(&scaleMatrix, scale, 1.0f, scale);
	D3DXMATRIX matrixOut;
	*D3DXMatrixMultiply(&matrixOut, &scaleMatrix, &translationMatrix);
	D3DXMATRIX result = matrixOut;
	engine->SetTransform(D3DTS_WORLD, &result);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_LIGHTING, FALSE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHAREF, 2);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
	engine->SetTexture(0, texture);
	engine->SetVertexShader(D3DFVF_TEX1|D3DFVF_DIFFUSE|D3DFVF_XYZ);
	engine->SetStreamSource(0, vertexBuffer, 36);
	engine->DrawPrimitive(D3DPT_TRIANGLELIST, 0, verticesAmount / 3);
}

