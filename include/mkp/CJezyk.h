#ifndef _C_JEZYK
#define _C_JEZYK

#include <globals.h>
#include "CState.h"
#include "cMagMeshObject.h"
#include "AIControlPoint.h"

class CJezyk : public cMagMeshObject {
	class Idle : public CState {
	public:
		/* 419BA0 */ void OnFrame();
		/* 419BA0 */ void OnExitState();
		/* 43DC50 */ void OnEnterState();

	private:
		/* 0x1dc */ CJezyk* jezyk;
		/* 0x1e0 */ int unk_1e0;

	};

	STATIC_ASSERT(sizeof(Idle) == 0x1e4);

	class WalkNaviPath : public CState {
	public:
		/* 419BA0 */ void OnExitState();
		/* 43D7C0 */ void OnEnterState();
		/* 43D8A0 */ void OnFrame();
		/* 43DAC0 */ void OnDestinationPos(D3DXVECTOR3 param_1);
		/* 43DB60 */ void OnCollisionObject(cMagMeshObject* param_1);
		/* 43DC30 */ void OnAnimEnd(char* param_1);

	private:
		/* 0x1dc */ CJezyk* jezyk;
		/* 0x1e0 */ D3DXVECTOR3 unk_1e0;
		/* 0x1ec */ uchar field_0x1ec[0x1f8-0x1ec];
	};

	STATIC_ASSERT(sizeof(WalkNaviPath) == 0x1f8);

public:
	/* 4164E0 */ void OnDestTime(float param_1);
	/* 419BA0 */ void OnActivate();
	/* 4262D0 */ void OnLoadChunk(_ED_CHUNK param_1, std::ifstream& param_2);
	/* 43D110 */ CJezyk();
	/* 43D280 */ virtual ~CJezyk();
	/* 43D2C0 */ void* EXP();
	/* 43D320 */ void OnActivateLevel();
	/* 43D420 */ void FUN0043d420();
	/* 43D4D0 */ void OnPlaySoundEnd(int param_1);
	/* 43D500 */ void FUN0043d500();
	/* 43D5F0 */ void FUN0043d5f0();
	/* 43D620 */ void FUN0043d620();

public:
	/* 0x2658 */ char navigationPath[200];
	/* 0x2720 */ int unk_2720;
	/* 0x2724 */ int unk_2724;
	/* 0x2728 */ cMagKernel* patrolObject;
	/* 0x272c */ D3DXVECTOR3 unk_272c;
	/* 0x2738 */ std::vector<AIControlPoint*> unk_2738;
	/* 0x2748 */ AIControlPoint* unk_2748;
};

STATIC_ASSERT(sizeof(CJezyk) == 0x2750);

#endif