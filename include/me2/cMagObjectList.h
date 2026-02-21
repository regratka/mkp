#ifndef C_MAG_OBJECT_LIST
#define C_MAG_OBJECT_LIST

#include <globals.h>
#include <vector>

#include "cMagKernel.h"

class cMagObjectList : public cMagKernel {
public:
	/* 100014C0 */ std::vector<cMagKernel*>::iterator begin();
	/* 100014D0 */ std::vector<cMagKernel*>::iterator end();
	/* 100014E0 */ cMagObjectList(cMagObjectList const & p_other);
	/* 10001970 */ cMagObjectList& operator=(cMagObjectList const & param_1);
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

private:
	/* 0x1dc */	std::vector<cMagKernel*> objects;
	/* 0x1ec */	std::vector<void*> f_1ec;
	/* 0x1fc */	std::vector<void*> f_1fc;
	/* 0x20c */	std::vector<void*> f_20c;
	/* 0x21c */	std::vector<void*> f_21c;
	/* 0x22c */	std::vector<void*> f_22c;
	/* 0x23c */	char f_23c[0x244 - 0x23c];
	/* 0x244 */	void* fog;
	/* 0x248 */ int f_248;
	/* 0x24c */ int f_24c;
	/* 0x250 */ std::vector<void*> f_250;
	/* 0x260 */ std::vector<void*> f_260;
	/* 0x270 */ std::vector<void*> f_270;
	/* 0x280 */ std::vector<void*> f_280;
	/* 0x290 */ std::vector<void*> f_290;
	/* 0x2a0 */ std::vector<void*> f_2a0;
	/* 0x2b0 */ std::vector<void*> f_2b0;
	/* 0x2c0 */ std::vector<void*> f_2c0;
	/* 0x2d0 */ std::vector<void*> f_2d0;
};

STATIC_ASSERT(sizeof(cMagObjectList) == 0x2e0);

#endif