#ifndef C_MAG_VERTEX
#define C_MAG_VERTEX

#include "cMagUtility.h"

#include <globals.h>

class DLLEXPORT cMagVertex : public cMagUtility {
public:
	/* 1002D670 */ cMagVertex();
	/* 1002D6D0 */ cMagVertex(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, ulong param_7, ulong param_8, float param_9, float param_10);
	/* 1002D750 */ virtual ~cMagVertex();
	/* 1002D760 */ void Set(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, ulong param_7, ulong param_8, float param_9, float param_10);

private:
	/* 0xd4c */ D3DXVECTOR3 pos;
	/* 0xd58 */ D3DXVECTOR3 unk_d58;
	/* 0xd64 */ ulong unk_d64;
	/* 0xd68 */ ulong unk_d68;
	/* 0xd6c */ float u;
	/* 0xd70 */ float v;
};

STATIC_ASSERT(sizeof(cMagVertex) == 0xd74);

#endif