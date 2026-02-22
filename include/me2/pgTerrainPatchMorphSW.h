#ifndef PG_TERRAIN_PATCH_MORPH_S_W
#define PG_TERRAIN_PATCH_MORPH_S_W

#include <globals.h>

#include "pgTerrain.h"

class pgTerrainPatchMorphSW {
public:
	/* 1000B560 */ pgTerrainPatchMorphSW(pgTerrainPatchMorphSW* param_1);
	/* 1000B9E0 */ pgTerrainPatchMorphSW* operator=(pgTerrainPatchMorphSW* param_1);
	/* 1007F3F0 */ pgTerrainPatchMorphSW(pgTerrain* param_1, int param_2, int param_3);
	/* 1007F4C0 */ void init();
	/* 1007F600 */ void deinit();
	/* 1007F750 */ bool updateTessellation();
	/* 1007F800 */ bool updateTessellation2();
	/* 1007FA30 */ bool updateTessellation3();
	/* 1007FAB0 */ int render();
	/* 1007FB60 */ void fillMorphVertices();
	/* 1007FC10 */ void checkBorderLeft();
	/* 1007FFE0 */ void checkBorderRight();
	/* 10080400 */ void checkBorderBottom();
	/* 100807D0 */ void checkBorderTop();
	/* 10080BD0 */ bool fillBuffers();
	/* 10080F40 */ bool checkBuffers();
};

#endif