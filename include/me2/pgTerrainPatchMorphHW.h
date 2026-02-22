#ifndef PG_TERRAIN_PATCH_MORPH_H_W
#define PG_TERRAIN_PATCH_MORPH_H_W

#include <globals.h>

#include "pgTerrain.h"

class pgTerrainPatchMorphHW {
public:
	/* 1007BF90 */ static bool setupVertexShader();
	/* 1007E840 */ pgTerrainPatchMorphHW(pgTerrainPatchMorphHW* param_1);
	/* 1007EA30 */ pgTerrainPatchMorphHW* operator=(pgTerrainPatchMorphHW* param_1);
	/* 1007EC90 */ pgTerrainPatchMorphHW(pgTerrain* param_1, int param_2, int param_3);
	/* 1007ECC0 */ void init();
	/* 1007ECD0 */ void deinit();
	/* 1007ECE0 */ int render();
	/* 1007EF70 */ void deleteDeviceObjects();
	/* 1007EF80 */ bool restoreDeviceObjects();
	/* 1007EF90 */ bool fillBuffers();
	/* 1007F230 */ bool checkBuffers();
};

#endif