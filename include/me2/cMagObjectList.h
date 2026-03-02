#ifndef C_MAG_OBJECT_LIST
#define C_MAG_OBJECT_LIST

#include <globals.h>
#include <vector>

#include "cMagKernel.h"

class __declspec(dllexport) cMagObjectList : public cMagKernel {
public:
	/* 100014C0-100014C7 00007	*/
	std::vector<cMagKernel*>::iterator cMagObjectList::begin() {
		return objects.begin();
	}

	/* 100014D0-100014D7 00007	*/
	std::vector<cMagKernel*>::iterator cMagObjectList::end() {
		return objects.end();
	}

	/* 100167E0 */ cMagObjectList();
	/* 10016A90 */ virtual ~cMagObjectList();
	/* 10016CF0 */ bool AddObject(cMagKernel* param_1);
	/* 10016EA0 */ bool AddAlphaMeshObjects(cMagKernel* param_1);
	/* 10017050 */ bool AddParticleObject(cMagKernel* param_1);
	/* 10017200 */ bool AddBillboardObject(cMagKernel* param_1);
	/* 100173B0 */ bool AddCameraObject(cMagKernel* param_1);
	/* 10017560 */ bool AddNoShadowObjects(cMagKernel* param_1);
	/* 10017710 */ bool AddSkyBoxObject(cMagKernel* param_1);
	/* 10017720 */ bool AddFogObject(cMagKernel* param_1);
	/* 10017730 */ bool AddSunObject(cMagKernel* param_1);
	/* 10017740 */ bool AddTerrainObject(cMagKernel* param_1);
	/* 10017750 */ bool AddSpriteObject(cMagKernel* param_1);
	/* 10017900 */ bool AddFxObject(cMagKernel* param_1);
	/* 10017AB0 */ bool AddWaterObject(cMagKernel* param_1);
	/* 10017C60 */ bool AddBlobObject(cMagKernel* param_1);
	/* 10017E10 */ bool AddPortalObject(cMagKernel* param_1);
	/* 10017FC0 */ bool AddSector(cMagKernel* param_1);
	/* 10018170 */ bool RenderWaterList();
	/* 100181B0 */ bool RenderBlobList();
	/* 100181F0 */ bool RenderObjectList();
	/* 10018240 */ bool RenderAlphaList();
	/* 10018270 */ bool RenderAlphaMeshObjectsList();
	/* 100182A0 */ bool RenderParticleList();
	/* 100182E0 */ bool RenderFxList();
	/* 10018320 */ bool RenderSpriteList();
	/* 10018360 */ bool RenderBillboardList();
	/* 100183A0 */ bool RenderNoShadowObjects();
	/* 100183E0 */ void AddShadowsObject(cMagKernel* param_1);
	/* 100185A0 */ void RenderShadowsList();
	/* 100185D0 */ bool RenderPortalList();
	/* 10018600 */ bool RenderSectors();
	/* 10018630 */ void CallHandlerOnInputKey(int param_1, bool param_2);
	/* 10018670 */ bool RenderCameraList();
	/* 100186B0 */ bool RenderSkyBox();
	/* 100186D0 */ bool RenderFog();
	/* 100186F0 */ bool RenderSun();
	/* 10018710 */ bool RenderTerrain();
	/* 10018730 */ cMagKernel* Find(ulong param_1);
	/* 10018750 */ cMagKernel* Find(cMagKernel* param_1);
	/* 10018780 */ void CleanList();
	/* 10018800 */ void RenderLensFlare();

protected:
	/* 0x1dc */	std::vector<cMagKernel*> objects;
	/* 0x1ec */	std::vector<cMagKernel*> particleObjects;
	/* 0x1fc */	std::vector<cMagKernel*> billboardObjects;
	/* 0x20c */	std::vector<cMagKernel*> cameraObjects;
	/* 0x21c */	std::vector<cMagKernel*> spriteObjects;
	/* 0x22c */	std::vector<cMagKernel*> fxObjects;
	/* 0x23c */	cMagKernel* skyBoxObject;
	/* 0x240 */	cMagKernel* sunObject;
	/* 0x244 */	cMagKernel* fogObject;
	/* 0x248 */ cMagKernel* lensFlare;
	/* 0x24c */ cMagKernel* terrainObject;
	/* 0x250 */ std::vector<cMagKernel*> waterObjects;
	/* 0x260 */ std::vector<cMagKernel*> blobObjects;
	/* 0x270 */ std::vector<cMagKernel*> alphaMeshObjects;
	/* 0x280 */ std::vector<cMagKernel*> noShadowObjects;
	/* 0x290 */ std::vector<cMagKernel*> f_290;
	/* 0x2a0 */ std::vector<cMagKernel*> shadowObjects;
	/* 0x2b0 */ std::vector<cMagKernel*> f_2b0;
	/* 0x2c0 */ std::vector<cMagKernel*> portalObjects;
	/* 0x2d0 */ std::vector<cMagKernel*> sectors;
};

STATIC_ASSERT(sizeof(cMagObjectList) == 0x2e0);

#endif