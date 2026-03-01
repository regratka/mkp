#include "cMagObjectList.h"

/* 100167E0-10016A8A 002AA	*/
cMagObjectList::cMagObjectList() {
	SetObjectName("No name");
	SetClassName("cMagObjectList");
	skyBoxObject = NULL;
	sunObject = NULL;
	lensFlare = NULL;
	terrainObject = NULL;
	noShadowObjects.clear();
	waterObjects.clear();
	portalObjects.clear();
	blobObjects.clear();
	alphaMeshObjects.clear();
	f_2b0.clear();
}

/* 10016A90-10016CF0 00260	*/
cMagObjectList::~cMagObjectList() {
}

/* 10016CF0-10016E9F 001AF	*/
bool cMagObjectList::AddObject(cMagKernel* param_1) {
	objects.push_back(param_1);
	return true;
}

/* 10016EA0-1001704F 001AF	*/
bool cMagObjectList::AddAlphaMeshObjects(cMagKernel* param_1) {
	alphaMeshObjects.push_back(param_1);
	return true;
}

/* 10017050-100171FF 001AF	*/
bool cMagObjectList::AddParticleObject(cMagKernel* param_1) {
	particleObjects.push_back(param_1);
	return true;
}

/* 10017200-100173AF 001AF	*/
bool cMagObjectList::AddBillboardObject(cMagKernel* param_1) {
	billboardObjects.push_back(param_1);
	return true;
}

/* 100173B0-1001755F 001AF	*/
bool cMagObjectList::AddCameraObject(cMagKernel* param_1) {
	cameraObjects.push_back(param_1);
	return true;
}

/* 10017560-1001770F 001AF	*/
bool cMagObjectList::AddNoShadowObjects(cMagKernel* param_1) {
	noShadowObjects.push_back(param_1);
	return true;
}

/* 10017710-1001771F 0000F	*/
bool cMagObjectList::AddSkyBoxObject(cMagKernel* param_1) {
	skyBoxObject = param_1;
	return true;
}

/* 10017720-1001772F 0000F	*/
bool cMagObjectList::AddFogObject(cMagKernel* param_1) {
	fogObject = param_1;
	return true;
}

/* 10017730-1001773F 0000F	*/
bool cMagObjectList::AddSunObject(cMagKernel* param_1) {
	sunObject = param_1;
	return true;
}

/* 10017740-1001774F 0000F	*/
bool cMagObjectList::AddTerrainObject(cMagKernel* param_1) {
	terrainObject = param_1;
	return true;
}

/* 10017750-100178FF 001AF	*/
bool cMagObjectList::AddSpriteObject(cMagKernel* param_1) {
	spriteObjects.push_back(param_1);
	return true;
}

/* 10017900-10017AAF 001AF	*/
bool cMagObjectList::AddFxObject(cMagKernel* param_1) {
	fxObjects.push_back(param_1);
	return true;
}

/* 10017AB0-10017C5F 001AF	*/
bool cMagObjectList::AddWaterObject(cMagKernel* param_1) {
	waterObjects.push_back(param_1);
	return true;
}

/* 10017C60-10017E0F 001AF	*/
bool cMagObjectList::AddBlobObject(cMagKernel* param_1) {
	blobObjects.push_back(param_1);
	return true;
}

/* 10017E10-10017FBF 001AF	*/
bool cMagObjectList::AddPortalObject(cMagKernel* param_1) {
	portalObjects.push_back(param_1);
	return true;
}

/* 10017FC0-1001816F 001AF	*/
bool cMagObjectList::AddSector(cMagKernel* param_1) {
	sectors.push_back(param_1);
	return true;
}

/* 10018170-100181A5 00035	*/
bool cMagObjectList::RenderWaterList() {
	for (std::vector<cMagKernel*>::iterator it = waterObjects.begin(); 
			it != waterObjects.end(); it++) {
		(*it)->OnRender();
		(*it)->vtbl_0x4c();
	}
	return true;
}

/* 100181B0-100181E5 00035	*/
bool cMagObjectList::RenderBlobList() {
	for (std::vector<cMagKernel*>::iterator it = blobObjects.begin(); 
			it != blobObjects.end(); it++) {
		(*it)->OnRender();
		(*it)->vtbl_0x4c();
	}
	return true;
}

/* 100181F0-10018231 00041	*/
bool cMagObjectList::RenderObjectList() {
	for (std::vector<cMagKernel*>::iterator it = f_290.begin(); 
			it != f_290.end(); it++) {
		if ((*it)->GetShadowType() != 2) {
			(*it)->vtbl_0x4c();
			(*it)->OnRender();
		}
	}
	return true;
}

/* 10018240-1001826E 0002E	*/
bool cMagObjectList::RenderAlphaList() {
	for (std::vector<cMagKernel*>::iterator it = f_2b0.begin(); 
			it != f_2b0.end(); it++) {
		(*it)->OnRender();
	}
	return true;
}

/* 10018270-1001829E 0002E	*/
bool cMagObjectList::RenderAlphaMeshObjectsList() {
	for (std::vector<cMagKernel*>::iterator it = alphaMeshObjects.begin(); 
			it != alphaMeshObjects.end(); it++) {
		(*it)->OnRender();
	}
	return true;
}

/* 100182A0-100182D5 00035	*/
bool cMagObjectList::RenderParticleList() {
	for (std::vector<cMagKernel*>::iterator it = particleObjects.begin(); 
			it != particleObjects.end(); it++) {
		(*it)->OnRender();
		(*it)->vtbl_0x4c();
	}
	return true;
}

/* 100182E0-10018315 00035	*/
bool cMagObjectList::RenderFxList() {
	for (std::vector<cMagKernel*>::iterator it = fxObjects.begin(); 
			it != fxObjects.end(); it++) {
		(*it)->OnRender();
		(*it)->vtbl_0x4c();
	}
	return true;
}

/* 10018320-10018355 00035	*/
bool cMagObjectList::RenderSpriteList() {
	for (std::vector<cMagKernel*>::iterator it = spriteObjects.begin(); 
			it != spriteObjects.end(); it++) {
		(*it)->OnRender();
		(*it)->vtbl_0x4c();
	}
	return true;
}

/* 10018360-10018395 00035	*/
bool cMagObjectList::RenderBillboardList() {
	for (std::vector<cMagKernel*>::iterator it = billboardObjects.begin(); 
			it != billboardObjects.end(); it++) {
		(*it)->OnRender();
		(*it)->vtbl_0x4c();
	}
	return true;
}

/* 100183A0-100183D5 00035	*/
bool cMagObjectList::RenderNoShadowObjects() {
	for (std::vector<cMagKernel*>::iterator it = shadowObjects.begin(); 
			it != shadowObjects.end(); it++) {
		(*it)->OnRender();
		(*it)->vtbl_0x4c();
	}
	return true;
}

/* 100183E0-10018591 001B1	*/
void cMagObjectList::AddShadowsObject(cMagKernel* param_1) {
	shadowObjects.push_back(param_1);
}

/* 100185A0-100185CC 0002C	*/
void cMagObjectList::RenderShadowsList() {
	for (std::vector<cMagKernel*>::iterator it = shadowObjects.begin(); 
			it != shadowObjects.end(); it++) {
		(*it)->vtb_0xf0();
	}
}

/* 100185D0-100185FE 0002E	*/
bool cMagObjectList::RenderPortalList() {
	for (std::vector<cMagKernel*>::iterator it = portalObjects.begin(); 
			it != portalObjects.end(); it++) {
		(*it)->OnRender();
	}
	return true;
}

/* 10018600-1001862E 0002E	*/
bool cMagObjectList::RenderSectors() {
	for (std::vector<cMagKernel*>::iterator it = sectors.begin(); 
			it != sectors.end(); it++) {
		(*it)->OnRender();
	}
	return true;
}

/* 10018630-1001866C 0003C	*/
void cMagObjectList::CallHandlerOnInputKey(int param_1, bool param_2) {
	for (std::vector<cMagKernel*>::iterator it = objects.begin(); 
			it != objects.end(); it++) {
		(*it)->OnInputKey(param_1, param_2);
	}
}

/* 10018670-100186A5 00035	*/
bool cMagObjectList::RenderCameraList() {
	for (std::vector<cMagKernel*>::iterator it = cameraObjects.begin(); 
			it != cameraObjects.end(); it++) {
		(*it)->OnRender();
		(*it)->vtbl_0x4c();
	}
	return true;
}

/* 100186B0-100186C8 00018	*/
bool cMagObjectList::RenderSkyBox() {
	if (skyBoxObject == NULL) {
		return false;
	}
	skyBoxObject->OnRender();
	return true;
}

/* 100186D0-100186E8 00018	*/
bool cMagObjectList::RenderFog() {
	if (fogObject == NULL) {
		return false;
	}
	fogObject->OnRender();
	return true;
}

/* 100186F0-10018708 00018	*/
bool cMagObjectList::RenderSun() {
	if (sunObject == NULL) {
		return false;
	}
	sunObject->OnRender();
	return true;
}

/* 10018710-10018728 00018	*/
bool cMagObjectList::RenderTerrain() {
	if (terrainObject == NULL) {
		return false;
	}
	terrainObject->OnRender();
	return true;
}

/* 10018730-10018741 00011	*/
cMagKernel* cMagObjectList::Find(ulong param_1) {
	cMagKernel* found = this;
	found = *begin();
	return found;
}

/* 10018750-10018779 00029	*/
cMagKernel* cMagObjectList::Find(cMagKernel* param_1) {
	for (std::vector<cMagKernel*>::iterator it = objects.begin(); 
			it != objects.end(); it++) {
		if (*it == param_1) {
			return *it;
		}
	}
	return NULL;
}

/* 10018780-10018800 00080	*/
void cMagObjectList::CleanList() {
	while (objects.begin() != objects.end()) {
		cMagKernel* first =  dynamic_cast<cMagKernel*>(objects[0]);
		objects.erase(objects.begin());
		if (first != NULL) {
			delete first;
		}
	} 
}

/* 10018800-10018813 00013	*/
void cMagObjectList::RenderLensFlare() {
	if (lensFlare != NULL) {
		lensFlare->OnRender();
	}
}

