#include "cGlow.h"

#include "cMagEngineMgr.h"

/* 10076E10-10076EE9 000D9	*/
cGlow::cGlow() {
	SetClassName("cGlow");
	scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	texture = NULL;
	vertexBuffer = NULL; 
	size = 100.0f;
	enableRendering = true;
}

/* 10076EF0-10076F54 00064	*/
cGlow::~cGlow() {
	if (vertexBuffer != NULL) {
		vertexBuffer->Release();
		vertexBuffer = NULL;
	}
}

/* 10076F60-10076FE9 00089	*/
void cGlow::Create(char* param_1) {
	texture = MagTextureMgr::getInstance()->GetTexture(param_1);
	HRESULT res = cMagEngineMgr::getInstance()->engine->CreateVertexBuffer(sizeof(GLOWVERTEX), D3DUSAGE_POINTS, D3DFVF_DIFFUSE|D3DFVF_XYZ, D3DPOOL_MANAGED, &vertexBuffer);
	if (res < S_OK) {
		return;
	}

	GLOWVERTEX* data;
	res = vertexBuffer->Lock(0, sizeof(GLOWVERTEX), (BYTE**)&data, 0);
	if (res < S_OK) {
		return;
	}

	data->pos.x = 0.5f;
	data->pos.y = 0.5f;
	data->pos.z =  -3.5f;
	data->color = D3DCOLOR_RGBA(0xff,0xff,0xff,0xff);
	vertexBuffer->Unlock();
}

/* 10076FF0-1007717D 0018D	*/
void cGlow::OnRender() {
	if (!enableRendering || texture == NULL) {
		return;
	}
	D3DXMATRIX local_40;
	D3DXMatrixIdentity(&local_40);
	cMagEngineMgr::getInstance()->engine->SetTransform(D3DTS_WORLD, &local_40);
	D3DXMatrixIdentity(&scaleMatrix);
	D3DXMatrixIdentity(&positionMatrix);
	D3DXMatrixScaling(&scaleMatrix, scale.x, scale.y, scale.z);
	D3DXMatrixTranslation(&positionMatrix, position.x, position.y, position.z);

	GLOWVERTEX* data;
	HRESULT res = vertexBuffer->Lock(0, sizeof(GLOWVERTEX), (BYTE**)&data, 0);
	if (res < S_OK) {
		return;
	}

	data->pos.x = position.x;
	data->pos.y = position.y;
	data->pos.z = position.z;
	vertexBuffer->Unlock();
	RenderGlow();
}

/* 10077180-10077367 001E7	*/
void cGlow::RenderGlow() {
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ZENABLE, FALSE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_POINTSCALEENABLE, TRUE);
	float s_SIZE = size;
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_POINTSIZE, *(DWORD*)&s_SIZE);
	float s_sizemin = 10.0f;
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_POINTSIZE_MIN,*(DWORD*)&s_sizemin);
	float s_scaleA = 0.0f;
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_POINTSCALE_A, *(DWORD*)&s_scaleA);
	float s_scaleB = 0.0f;
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_POINTSCALE_B, *(DWORD*)&s_scaleB);
	float s_scaleC = 1.0f;
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_POINTSCALE_C, *(DWORD*)&s_scaleC);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_POINTSPRITEENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_LIGHTING, FALSE);

	if (texture != NULL) {
		cMagEngineMgr::getInstance()->engine->SetTexture(0, texture);
	}
	cMagEngineMgr::getInstance()->engine->SetStreamSource(0, vertexBuffer, sizeof(GLOWVERTEX));
	cMagEngineMgr::getInstance()->engine->SetVertexShader(D3DFVF_DIFFUSE|D3DFVF_XYZ);
	cMagEngineMgr::getInstance()->engine->DrawPrimitive(D3DPT_POINTLIST, 0, 1);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
}

/* 10077370-1007738D 0001D	*/
void cGlow::SetScale(D3DXVECTOR3 param_1) {
	scale = param_1;

}

/* 10077390-100773AD 0001D	*/
void cGlow::SetPosition(D3DXVECTOR3 param_1) {
	position = param_1;
}

/* 100773B0-100773BD 0000D	*/
void cGlow::SetSize(float param_1) {
	size = param_1;
}

/* 100773C0-100773CD 0000D	*/
void cGlow::EnableRendering(bool param_1) {
	enableRendering = param_1;
}

/* 100773D0-100773D7 00007	*/
bool cGlow::EnableRendering() {
	return enableRendering;
}

