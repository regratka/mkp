#ifndef _C_BRAMA
#define _C_BRAMA

#include <globals.h>

#include "_Platform.h"

struct CBramaMeshData {
	/* 0x00 */ float fWysokosc;
	/* 0x04 */ float fPredkosc;
	/* 0x08 */ BOOL RuchWPoziomie;
	/* 0x0c */ char SoundName[200];
	/* 0xd4 */ int SoundRangesMin;
	/* 0xd8 */ int SoundRangesMax;
};

STATIC_ASSERT(sizeof(CBramaMeshData) == 0xdc);

class CBrama : public _Platform {
public:
	/* 4164E0 */ void OnCollisionObject(cMagMeshObject* param_1);
	/* 419BA0 */ void OnFrame();
	/* 41A860 */ CBrama();
	/* 41A8D0 */ ~CBrama();
	/* 41A8E0 */ void* EXP();
	/* 41A940 */ void OnActivate();
	/* 41A970 */ void OnActivateLevel();
	/* 41AAD0 */ void OnCrash();
	/* 41AB00 */ bool OnProcessStateMachine(StateObject_Str* param_1, int param_2, MsgObject* param_3);
	/* 41AEF0 */ void OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2);

private:
	/* 0x2658 */ CBramaMeshData meshData;
	/* 0x2734 */ float unk_2734;
	/* 0x2738 */ uchar f_2738[0x2748 - 0x2738];
	/* 0x2748 */ int unk_2748;
	/* 0x274c */ bool unk_274c;
	/* 0x274d */ bool unk_274d;
	/* 0x2750 */ D3DXVECTOR3 unk_2750;
	/* 0x275c */ D3DXVECTOR3 unk_275c;
	/* 0x2768 */ int unk_2768;
	/* 0x276c */ bool unk_276c;
};

STATIC_ASSERT(sizeof(CBrama) == 0x2770);

#endif