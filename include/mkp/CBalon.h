#ifndef _C_BALON
#define _C_BALON

#include <globals.h>
#include <vector>

#include "cMagMeshObject.h"


class CBalon : public cMagMeshObject {
public:
	/* 4400B0 */ CBalon();
	/* 440160 */ ~CBalon();
	/* 4401A0 */ void* EXP();
	/* 440200 */ void OnAction();
	/* 440220 */ void OnFrame();
	/* 440300 */ void OnDestinationPos(D3DXVECTOR3 param_1);
	/* 440350 */ void OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2);

private:
	/* 0x2658 */ float* pointsLoadBuffer;
	/* 0x265c */ std::vector<D3DXVECTOR3> routePoints;
	/* 0x266c */ int visitedPoints;
	/* 0x2670 */ int routePointsAmount;
};

STATIC_ASSERT(sizeof(CBalon) == 0x2678);

#endif