#ifndef PG_TERRAIN_P_V_S
#define PG_TERRAIN_P_V_S

#include <globals.h>

class pgTerrainPVS {
public:
	/* 1000B540 */ pgTerrainPVS* operator=(pgTerrainPVS* param_1);
	/* 10081090 */ pgTerrainPVS();
	/* 100810B0 */ ~pgTerrainPVS();
	/* 100810C0 */ void calc(uchar* param_1, uchar* param_2, uint param_3, uint param_4, uint param_5, uint param_6);
	/* 10081330 */ void shrink();
	/* 10081520 */ bool save(char* param_1);
	/* 100815C0 */ bool load(char* param_1);
	/* 100816B0 */ void setVisible(int param_1, int param_2, int param_3, int param_4, int param_5, bool param_6);
	/* 10081710 */ bool isVisible(int param_1, int param_2, int param_3, int param_4, int param_5);
	/* 10081790 */ uint getIdx(int param_1, int param_2, int param_3, int param_4, int param_5);
};

#endif