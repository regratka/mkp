#ifndef C_MAG_VERTEX
#define C_MAG_VERTEX

#include <globals.h>

class cMagVertex {
public:
	/* 10006660 */ cMagVertex(cMagVertex* param_1);
	/* 100067B0 */ cMagVertex* operator=(cMagVertex* param_1);
	/* 100068F0 */ cMagVertex* scalar_destructor(uchar param_1);
	/* 1002D670 */ cMagVertex();
	/* 1002D6D0 */ cMagVertex(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, ulong param_7, ulong param_8, float param_9, float param_10);
	/* 1002D750 */ ~cMagVertex();
	/* 1002D760 */ void Set(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, ulong param_7, ulong param_8, float param_9, float param_10);
};

#endif