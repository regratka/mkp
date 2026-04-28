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

	this->texture = MagTextureMgr::getInstance()->GetTexture(param_1);
	this->verticesAmount = param_4 * sizeof(MAGVERTEX); // liczba sekcji * liczba wierzchołków w sekcji
	HRESULT result = this->engine->CreateVertexBuffer(verticesAmount * 36, D3DUSAGE_WRITEONLY, D3DFVF_TEX1 | D3DFVF_DIFFUSE | D3DFVF_XYZ, 
		D3DPOOL_MANAGED, &this->vertexBuffer);
	if (result < S_OK) {
		return result;
	}

	MAGVERTEX* data;
	result = this->vertexBuffer->Lock(0, 0, (BYTE**)&data, 0);
	if (result < S_OK) {
		return result;
	}

	float angleGrowth = 360.0f / param_4;
	double angle = 0.0;
	while (angle < 360.0f) {
		double radians = GpgDegToRad(angle);
		float var_2 = cos(radians);
		float var_3 = this->range * cos(radians);
		float var_4 = sin(radians);
		float var_5 = this->range * var_4;
		float var_6 = this->range - this->radius;

		angle += angleGrowth;

		float var_7 = cos(GpgDegToRad(angle));
		float var_8 = sin(GpgDegToRad(angle));

		data[0].pos.x = var_2 * var_6;
		data[0].pos.y = 0.0f;
		data[0].pos.z = var_4 * var_6;
		data[0].color = D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff);
		data[0].u = 0.0f;
		data[0].v = 1.0f;

		data[1].pos.x = var_3;
		data[1].pos.y = 0.0f;
		data[1].pos.z = var_5;
 		data[1].color = D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff);
		data[1].u = 0.0f;
		data[1].v = 0.0f;

		data[2].pos.x = var_6 * var_7;
		data[2].pos.y = 0.0f;
		data[2].pos.z = var_6 * var_8;
		data[2].color = D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff);
		data[2].u = 1.0f;
		data[2].v = 1.0f;
		
		data[3].pos.x = var_3;
		data[3].pos.y = 0.0f;
		data[3].pos.z = var_5;
 		data[3].color = D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff);
		data[3].u = 0.0f;
		data[3].v = 0.0f;

		data[4].pos.x = this->range * var_7;
		data[4].pos.y = 0.0f;
		data[4].pos.z = this->range * var_8;
 		data[4].color = D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff);
		data[4].u = 1.0f;
		data[4].v = 0.0f;

		data[5].pos.x = var_6 * var_7;
		data[5].pos.y = 0.0f;
		data[5].pos.z = var_6 * var_8;
		data[5].color = D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff);
		data[5].u = 1.0f;
		data[5].v = 1.0f;

		data += 6;
	}
	this->vertexBuffer->Unlock();
}

/* 10076860-100768C0 00060	*/
void cFX_Shockwave::SetAlpha(int param_1) {
	MAGVERTEX* data;
	HRESULT result = this->vertexBuffer->Lock(0, 0, (BYTE**)&data, 0);
	if (result < S_OK) {
		return;
	}

	for (int index = 0; index < verticesAmount; index++) {
		data->color = D3DCOLOR_ARGB(param_1, 0xFF, 0xFF, 0xFF);
		data += 1;
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
	D3DXMatrixTranslation(&translationMatrix, shockwavePosition.x, shockwavePosition.y, shockwavePosition.z);
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

