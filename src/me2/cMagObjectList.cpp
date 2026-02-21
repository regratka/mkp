#include "cMagObjectList.h"

/* 100014C0-100014C7 00007	*/
std::vector<cMagKernel*>::iterator cMagObjectList::begin() {
	return objects.begin();
}

/* 100014D0-100014D7 00007	*/
std::vector<cMagKernel*>::iterator cMagObjectList::end() {
	return objects.end();
}

/* 100014E0-1000196F 0048F	*/
cMagObjectList::cMagObjectList(cMagObjectList const & p_other) {
}

/* 10001970-10001D13 003A3	*/
cMagObjectList& cMagObjectList::operator=(cMagObjectList const & param_1) {
	return *this;
}

/* 100167E0-10016A8A 002AA	*/
cMagObjectList::cMagObjectList() {
}

/* 10016A90-10016CF0 00260	*/
cMagObjectList::~cMagObjectList() {
}

/* 10016CF0-10016E9F 001AF	*/
bool cMagObjectList::AddObject(cMagKernel* param_1) {
	return 0;
}

/* 10016EA0-1001704F 001AF	*/
bool cMagObjectList::AddAlphaMeshObjects(cMagKernel* param_1) {
	return 0;
}

/* 10017050-100171FF 001AF	*/
bool cMagObjectList::AddParticleObject(cMagKernel* param_1) {
	return 0;
}

/* 10017200-100173AF 001AF	*/
bool cMagObjectList::AddBillboardObject(cMagKernel* param_1) {
	return 0;
}

/* 100173B0-1001755F 001AF	*/
bool cMagObjectList::AddCameraObject(cMagKernel* param_1) {
	return 0;
}

/* 10017560-1001770F 001AF	*/
bool cMagObjectList::AddNoShadowObjects(cMagKernel* param_1) {
	return 0;
}

/* 10017710-1001771F 0000F	*/
bool cMagObjectList::AddSkyBoxObject(cMagKernel* param_1) {
	return 0;
}

/* 10017720-1001772F 0000F	*/
bool cMagObjectList::AddFogObject(cMagKernel* param_1) {
	return 0;
}

/* 10017730-1001773F 0000F	*/
bool cMagObjectList::AddSunObject(cMagKernel* param_1) {
	return 0;
}

/* 10017740-1001774F 0000F	*/
bool cMagObjectList::AddTerrainObject(cMagKernel* param_1) {
	return 0;
}

/* 10017750-100178FF 001AF	*/
bool cMagObjectList::AddSpriteObject(cMagKernel* param_1) {
	return 0;
}

/* 10017900-10017AAF 001AF	*/
bool cMagObjectList::AddFxObject(cMagKernel* param_1) {
	return 0;
}

/* 10017AB0-10017C5F 001AF	*/
bool cMagObjectList::AddWaterObject(cMagKernel* param_1) {
	return 0;
}

/* 10017C60-10017E0F 001AF	*/
bool cMagObjectList::AddBlobObject(cMagKernel* param_1) {
	return 0;
}

/* 10017E10-10017FBF 001AF	*/
bool cMagObjectList::AddPortalObject(cMagKernel* param_1) {
	return 0;
}

/* 10017FC0-1001816F 001AF	*/
bool cMagObjectList::AddSector(cMagKernel* param_1) {
	return 0;
}

/* 10018170-100181A5 00035	*/
bool cMagObjectList::RenderWaterList() {
	return 0;
}

/* 100181B0-100181E5 00035	*/
bool cMagObjectList::RenderBlobList() {
	return 0;
}

/* 100181F0-10018231 00041	*/
bool cMagObjectList::RenderObjectList() {
	return 0;
}

/* 10018240-1001826E 0002E	*/
bool cMagObjectList::RenderAlphaList() {
	return 0;
}

/* 10018270-1001829E 0002E	*/
bool cMagObjectList::RenderAlphaMeshObjectsList() {
	return 0;
}

/* 100182A0-100182D5 00035	*/
bool cMagObjectList::RenderParticleList() {
	return 0;
}

/* 100182E0-10018315 00035	*/
bool cMagObjectList::RenderFxList() {
	return 0;
}

/* 10018320-10018355 00035	*/
bool cMagObjectList::RenderSpriteList() {
	return 0;
}

/* 10018360-10018395 00035	*/
bool cMagObjectList::RenderBillboardList() {
	return 0;
}

/* 100183A0-100183D5 00035	*/
bool cMagObjectList::RenderNoShadowObjects() {
	return 0;
}

/* 100183E0-10018591 001B1	*/
void cMagObjectList::AddShadowsObject(cMagKernel* param_1) {
}

/* 100185A0-100185CC 0002C	*/
void cMagObjectList::RenderShadowsList() {
}

/* 100185D0-100185FE 0002E	*/
bool cMagObjectList::RenderPortalList() {
	return 0;
}

/* 10018600-1001862E 0002E	*/
bool cMagObjectList::RenderSectors() {
	return 0;
}

/* 10018630-1001866C 0003C	*/
void cMagObjectList::CallHandlerOnInputKey(int param_1, bool param_2) {
}

/* 10018670-100186A5 00035	*/
bool cMagObjectList::RenderCameraList() {
	return 0;
}

/* 100186B0-100186C8 00018	*/
bool cMagObjectList::RenderSkyBox() {
	return 0;
}

/* 100186D0-100186E8 00018	*/
bool cMagObjectList::RenderFog() {
	return 0;
}

/* 100186F0-10018708 00018	*/
bool cMagObjectList::RenderSun() {
	return 0;
}

/* 10018710-10018728 00018	*/
bool cMagObjectList::RenderTerrain() {
	return 0;
}

/* 10018730-10018741 00011	*/
cMagKernel* cMagObjectList::Find(ulong param_1) {
	return 0;
}

/* 10018750-10018779 00029	*/
cMagKernel* cMagObjectList::Find(cMagKernel* param_1) {
	return 0;
}

/* 10018780-10018800 00080	*/
void cMagObjectList::CleanList() {
}

/* 10018800-10018813 00013	*/
void cMagObjectList::RenderLensFlare() {
}

