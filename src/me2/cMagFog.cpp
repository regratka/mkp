#include "cMagFog.h"

#include "cMagEngineMgr.h"

/* 1005A5E0-1005A5E3 00003	*/
void cMagFog::InitDeviceObjects(cMagGameObject* param_1) {
}

/* 10072470-100724F2 00082	*/
cMagFog::cMagFog() {
	SetObjectName("No name");
	SetClassName("cMagFog");
	fogRangeNear = 0.0f;
	fogRangeFar = 1.0f;
	fogDensity = 0;
	typeFog = D3DFOG_LINEAR;
}

/* 10072500-10072551 00051	*/
cMagFog::~cMagFog() {
	Enable(false);
}

/* 10072560-1007256D 0000D	*/
void cMagFog::TypeFog(ulong param_1) {
	typeFog = (D3DFOGMODE) param_1;
}

/* 10072570-10072607 00097	*/
void cMagFog::InitFog() {
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGENABLE, TRUE);
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGCOLOR, colorFog);
	if (typeFog == D3DFOG_LINEAR) {
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGSTART, *(int*)&fogRangeNear);
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGEND, *(int*)&fogRangeFar);
	} else {
		cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGDENSITY, *(int*)&fogDensity);
	}
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGTABLEMODE, typeFog);

}

/* 10072610-1007261D 0000D	*/
void cMagFog::SetFogRangeNear(float param_1) {
	fogRangeNear = param_1;
}

/* 10072620-1007262D 0000D	*/
void cMagFog::SetFogRangeFar(float param_1) {
	fogRangeFar = param_1;
}

/* 10072630-1007263D 0000D	*/
void cMagFog::SetFogDensity(float param_1) {
	fogDensity = param_1;
}

/* 10072640-10072675 00035	*/
void cMagFog::SetColorFog(uchar param_1, uchar param_2, uchar param_3) {
	colorFog = D3DCOLOR_XRGB(param_1, param_2, param_3);
}

/* 10072680-100726A5 00025	*/
void cMagFog::EnableFog() {
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGENABLE, TRUE);
	cMagEngineMgr::getInstance()->gameObject->enabledFog = true;
}

/* 100726B0-100726D5 00025	*/
void cMagFog::DisableFog() {
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGENABLE, FALSE);
	cMagEngineMgr::getInstance()->gameObject->enabledFog = false;
}

/* 100726E0-100726ED 0000D	*/
void cMagFog::SetColorFog(D3DCOLOR param_1) {
	colorFog = param_1;
}

/* 100726F0-100726F7 00007	*/
D3DCOLOR cMagFog::GetColorFog() {
	return colorFog;
}

/* 10072700-10072732 00032	*/
void cMagFog::Enable(bool param_1) {
	cMagEngineMgr::getInstance()->engine->SetRenderState(D3DRS_FOGENABLE, param_1);
	cMagEngineMgr::getInstance()->gameObject->enabledFog = param_1;
}

