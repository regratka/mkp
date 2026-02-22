#ifndef PG_TERRAIN_PATCH_BASE
#define PG_TERRAIN_PATCH_BASE

#include <globals.h>

class pgTerrain;
class PATCHVERTEX;
class pgVec3;
class pgPlane;
class pgVec2;

class pgTerrainPatchBase {
public:
	/* 1000ACE0 */ int render(uchar param_1);
	/* 1000ACF0 */ void setRendered(bool param_1);
	/* 1000AD00 */ bool getRendered();
	/* 1000AD10 */ void setVisFlags(int param_1);
	/* 1000AD20 */ int getVisFlags();
	/* 1000AD30 */ void setMaster(pgTerrain* param_1);
	/* 1000AD40 */ float getCurrentError();
	/* 1000AD50 */ int getCurrentTessellation();
	/* 1000AD60 */ int getNewTessellation();
	/* 1000AD70 */ int getRealTessellation();
	/* 1000AD80 */ int getNumIndices();
	/* 1000AD90 */ int getNumVertices();
	/* 1000ADA0 */ PATCHVERTEX* getVertices();
	/* 1000ADB0 */ bool isVisible();
	/* 1000ADC0 */ bool isActive();
	/* 1000ADD0 */ float getProjectedError(int param_1);
	/* 1000ADF0 */ void setTessellation(int param_1);
	/* 1000AE00 */ pgTerrainPatchBase* getNextActive();
	/* 1000AE10 */ int getGridPosX();
	/* 1000AE20 */ int getGridPosY();
	/* 1000AE30 */ void setFlagActive(bool param_1);
	/* 1000AE40 */ bool getFlagActive();
	/* 1000AE50 */ void setPosition(pgVec3* param_1);
	/* 1000AE80 */ static int getAddLayerFlag(int param_1);
	/* 1000AE90 */ pgTerrainPatchBase* getLeft();
	/* 1000AEA0 */ pgTerrainPatchBase* getRight();
	/* 1000AEB0 */ pgTerrainPatchBase* getBottom();
	/* 1000AEC0 */ pgTerrainPatchBase* getTop();
	/* 1000AED0 */ pgTerrainPatchBase(pgTerrainPatchBase* param_1);
	/* 1000B150 */ pgTerrainPatchBase* operator=(pgTerrainPatchBase* param_1);
	/* 1000B3D0 */ void addIndex(ushort param_1);
	/* 1000B3F0 */ void addLastIndexAgain();
	/* 1007BA40 */ pgTerrainPatchBase(pgTerrain* param_1, int param_2, int param_3);
	/* 1007BBC0 */ void setNeighbors(pgTerrainPatchBase* param_1, pgTerrainPatchBase* param_2, pgTerrainPatchBase* param_3, pgTerrainPatchBase* param_4);
	/* 1007BBF0 */ void init();
	/* 1007BCB0 */ void deinit();
	/* 1007BD20 */ void addToActiveList();
	/* 1007BD50 */ void removeFromActiveList();
	/* 1007BDA0 */ int fillBaseVertices(PATCHVERTEX* param_1);
	/* 1007BDE0 */ void setScale(pgVec3* param_1);
	/* 1007BE10 */ void setHeightMapPosition(int param_1, int param_2);
	/* 1007BE30 */ void setRealTessellation(int param_1);
	/* 1007BE50 */ bool updateTessellation();
	/* 1007BFA0 */ bool checkVisibility(uchar param_1, pgPlane* param_2);
	/* 1007BFD0 */ void setVisible(bool param_1);
	/* 1007C000 */ void updateVisibility(uchar param_1, pgPlane* param_2);
	/* 1007C320 */ void calcMinMaxY();
	/* 1007C3C0 */ void calcMinMax();
	/* 1007C4E0 */ void updateProjectedErrors(uchar param_1);
	/* 1007C5E0 */ void calcErrors();
	/* 1007C600 */ void calcError(int param_1);
	/* 1007C900 */ float getExactTessellation();
	/* 1007C940 */ static int getPowerTwo(int param_1);
	/* 1007C9A0 */ void createTessellation(int param_1, int param_2, int param_3, int param_4, int param_5);
	/* 1007CA90 */ void reduceShapeTo(int param_1, PATCHVERTEX* param_2);
	/* 1007CAC0 */ void makeBordersSimpler(PATCHVERTEX* param_1);
	/* 1007CE30 */ void makeSimpler(int param_1, PATCHVERTEX* param_2);
	/* 1007CE90 */ void calculateInbetweenVertex(int param_1, int param_2, int param_3, int param_4, int param_5, PATCHVERTEX* param_6);
	/* 1007CF00 */ int calculateDiagonalVertices(int param_1, int param_2, int param_3, int param_4, int param_5, PATCHVERTEX* param_6, float* param_7, int* param_8, float* param_9, int* param_10);
	/* 1007D080 */ void addTriangleRow(int param_1, int param_2, bool param_3, bool param_4, bool param_5, bool param_6);
	/* 1007D3A0 */ void addTriangleBottomRow(int param_1, bool param_2, bool param_3);
	/* 1007D720 */ void addTriangleTopRow(int param_1, bool param_2, bool param_3);
	/* 1007DAB0 */ void addLevel4PatchTriangles(bool param_1, bool param_2, bool param_3, bool param_4);
	/* 1007E520 */ float getHeight(int param_1, int param_2);
	/* 1007E570 */ void getVertex(int param_1, int param_2, pgVec3* param_3);
	/* 1007E600 */ void getTexCoord(int param_1, int param_2, pgVec2* param_3);
	/* 1007E660 */ void getNormal(int param_1, int param_2, pgVec3* param_3);
	/* 1007E6B0 */ ushort getIndex(int param_1, int param_2);
	/* 1007E7F0 */ int getNewTessellationSafe();
};

#endif