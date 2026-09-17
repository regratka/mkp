#ifndef _C_KRZAK
#define _C_KRZAK

#include <globals.h>
#include "cMagMeshObject.h"

struct CKrzakChunkData {
	/* 0x00 */ float unk_00;
	/* 0x04 */ float unk_04;
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
	/* 0x2658 */ CKrzakChunkData unk_2658;
	// /* 0x265c */ float unk_265c;
	/* 0x2660 */ float unk_2660;
	/* 0x2664 */ float unk_2664;
	/* 0x2668 */ bool unk_2668;
	/* 0x266c */ float unk_266c;
	/* 0x2670 */ float unk_2670;
};

STATIC_ASSERT(sizeof(CKrzak) == 0x2678);

#endif