#ifndef _C_KRZAK
#define _C_KRZAK

#include <globals.h>
#include "cMagMeshObject.h"

struct CKrzakChunkData {
	/* 0x00 */ float directionUpdateInterval;
	/* 0x04 */ float directionChangeValue;
};

class CKrzak : public cMagMeshObject {
public:
	/* 441A50 */ CKrzak();
	/* 441AB0 */ virtual ~CKrzak();
	/* 441AC0 */ void* EXP();
	/* 441B20 */ void OnActivate();
	/* 441B60 */ void OnActivateLevel();
	/* 441BB0 */ void OnFrame();
	/* 441C80 */ void OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2);

private:
	/* 0x2658 */ CKrzakChunkData chunkData;
	/* 0x2660 */ float lastUpdateTick;
	/* 0x2664 */ float direction;
	/* 0x2668 */ bool shouldDecreaseDirection;
	/* 0x266c */ float directionUpdateInterval;
	/* 0x2670 */ float directionChangeValue;
};

STATIC_ASSERT(sizeof(CKrzak) == 0x2678);

#endif