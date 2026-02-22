#ifndef PG_TERRAIN
#define PG_TERRAIN

#include <globals.h>

class pgTerrain {
public:
	/* 1000C2A0 */ pgTerrainPatchBase** getActiveList();
	/* 1000C2B0 */ void setMaxError(float param_1);
	/* 1000C2C0 */ float getMaxError();
	/* 1000C2D0 */ void addBufferCreateCount();
	/* 1000C2E0 */ void setNumPatches(int param_1, int param_2);
	/* 1000C300 */ int GetNumTris();
	/* 1000C310 */ bool getMergePatches();
	/* 1000C320 */ void setMergePatches(bool param_1);
	/* 1000C330 */ cMagFrustumCull* GetFrustumCull();
	/* 1000C340 */ pgTerrain(pgTerrain* param_1);
	/* 1000C5C0 */ pgTerrain* operator=(pgTerrain* param_1);
	/* 1000C960 */ float getHeight(int param_1, int param_2);
	/* 1000C990 */ void getTexCoord(int param_1, int param_2, pgVec2* param_3);
	/* 1000C9D0 */ void getNormal(int param_1, int param_2, pgVec3* param_3);
	/* 10083C90 */ pgTerrain();
	/* 10083E00 */ ~pgTerrain();
	/* 10083EF0 */ void setHeightMap(pgImage* param_1);
	/* 10083F10 */ void setGrassMap(pgImage* param_1);
	/* 10083F50 */ int GetColorGrassMap(int param_1, int param_2);
	/* 10083FA0 */ void setPatchSize(float param_1, float param_2, float param_3);
	/* 10083FD0 */ void build();
	/* 100841E0 */ pgTerrainPatchBase* createPatch(int param_1, int param_2);
	/* 10084250 */ void update(uchar param_1);
	/* 10084F40 */ void setD3DVecFromVec3(_D3DVECTOR* param_1, pgVec3* param_2);
	/* 10084F60 */ void createClippingPlanes(pgPlane* param_1);
	/* 100851D0 */ void renderSplit();
	/* 10085740 */ void checkBuffers();
	/* 10085840 */ void addPass(float param_1, float param_2);
	/* 10085A00 */ void fillPassInfo(MultiPassInfo* param_1, float param_2, float param_3);
	/* 10085A60 */ void CreateFrustumCull();
	/* 10085AD0 */ bool projectDown(pgVec3* param_1, pgVec3* param_2);
	/* 10085CC0 */ float getHeightDif(int param_1, int param_2, int param_3, int param_4);
	/* 10085D20 */ void createNormals();
	/* 10086050 */ uint Pick(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float* param_7, uint param_8, int param_9);
};

#endif