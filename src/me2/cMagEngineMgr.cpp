#include "cMagEngineMgr.h"

/* 10003E90-10003E9A 0000A	*/
void cMagEngineMgr::SetEngine(IDirect3DDevice8* param_1) {
	engine = param_1;
}

/* 10003EA0-10003EA9 00009	*/
void cMagEngineMgr::SetGameObject(cMagGameObject* param_1) {
	gameObject = param_1;
}

/* 10003EB0-10003EB7 00007	*/
void cMagEngineMgr::ClearGameObject() {
	gameObject = NULL;
}

/* 10003EC0-10003EE3 00023	*/
void cMagEngineMgr::operator=(cMagEngineMgr* param_1) {

}

/* 1000B500-1000B503 00003	*/
cMagGameObject* cMagEngineMgr::GetGameObject() {
	return gameObject;
}

/* 1000B510-1000B514 00004	*/
IDirect3DDevice8* cMagEngineMgr::GetEngine() {
	return engine;
}

/* 1000B530-1000B534 00004	*/
cMagFrustumCull* cMagEngineMgr::GetFrustumCull() {
	return frustumCull;
}

/* 10088320-10088335 00015	*/
cMagEngineMgr::cMagEngineMgr() {
	instance = this;
	engine = NULL;
	dataPath = NULL;
	gameObject = NULL;
	frustumCull = NULL;
}

/* 10088340-10088398 00058	*/
cMagEngineMgr::~cMagEngineMgr() {
	if (frustumCull != NULL) {
		delete frustumCull;
	}

	if (engine != NULL) {
		engine->Release();
	} 
	engine = NULL;
	instance = NULL;
}

/* 100883A0-100883AA 0000A	*/
void cMagEngineMgr::SetDataPath(char* param_1) {
	dataPath = param_1;
}

/* 100883B0-100883EC 0003C	*/
void cMagEngineMgr::GetDataPath(char* param_1, char* param_2) {
	if (dataPath != NULL) {
		sprintf(param_2, "%s%s", dataPath, param_1);
	} else {
		sprintf(param_2, "%s", param_1);
	}
}

/* 100883F0-10088453 00063	*/
void cMagEngineMgr::CreateFrustumCull() {
	frustumCull = new cMagFrustumCull();
	frustumCull->CreateBox();
}

