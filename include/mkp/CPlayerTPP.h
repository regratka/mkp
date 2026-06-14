#ifndef _C_PLAYER_T_P_P
#define _C_PLAYER_T_P_P

#include <globals.h>

#include "cMagMeshObject.h"
#include "CCollisionCamera.h"

class CPlayerTPP : public cMagMeshObject {

	class STATE_Death {
	public:
		/* 40B320 */ uchar OnChangeMovement(uint param_1);
		/* 40B580 */ void OnEnterState();
		/* 40B640 */ void OnFadeOutEnd();
	};

	class STATE_Empty {
	};

	class STATE_Idle {
	public:
		/* 40A520 */ void OnEnterState();
		/* 40A5B0 */ void OnFrame();
		/* 40A630 */ void OnExitState();
		/* 40A650 */ uchar OnInputKey(uint param_1);
		/* 40B4B0 */ uchar OnCollisionObject(uint param_1);
	};

	class STATE_Jump {
	public:
		/* 40B260 */ uchar OnEnterState(int param_1);
		/* 40B310 */ void OnFrame();
		/* 40B340 */ uchar OnInputKey(int param_1);
		/* 40B4D0 */ uchar OnAnimEnd(char* param_1);
		/* 40B560 */ void OnExitState();
	};

	class STATE_Run_Back {
	public:
		/* 40AE20 */ uchar OnEnterState(int param_1);
		/* 40AEB0 */ void OnFrame();
		/* 40AF20 */ uchar OnInputKey(int param_1);
		/* 40B060 */ uchar OnInputMouse(uchar param_1, uchar param_2, uchar param_3, uchar param_4);
		/* 40B1D0 */ uchar OnAnimEnd(char* param_1);
		/* 40B240 */ uchar OnExitState(int param_1);
	};

	class STATE_Run_Forward {
	public:
		/* 40A670 */ uchar OnEnterState(int param_1);
		/* 40A720 */ uchar OnFrame(int param_1);
		/* 40A790 */ uchar OnInputKey(int param_1);
		/* 40AC50 */ uchar OnInputMouse(uchar param_1, uchar param_2, uchar param_3, uchar param_4);
		/* 40ADC0 */ uchar OnAnimEnd(char* param_1);
	};

public:
	/* 407E30 */ CPlayerTPP();
	/* 407EC0 */ CPlayerTPP* scalar_destructor(uchar param_1);
	/* 4080B0 */ ~CPlayerTPP();
	/* 408180 */ void* EXP();
	/* 4081E0 */ void OnActivate();
	/* 4082F0 */ void OnActivateLevel();
	/* 408840 */ CCollisionCamera* FUN00408840();
	/* 4094C0 */ void OnPlaySoundEnd(int param_1);
	/* 4094E0 */ uchar OnFrame(uchar param_1);
	/* 409500 */ uchar OnChangeMovement(uint param_1);
	/* 409650 */ uchar OnCollisionObject(int* param_1);
	/* 4098B0 */ uchar OnExitYesNo(char* param_1);
	/* 409AB0 */ uchar OnInputKey(int param_1);
	/* 409E30 */ uchar OnInputMouse(uchar param_1, uchar param_2, uchar param_3, uint param_4);
	/* 409FF0 */ void FUN00409ff0(bool param_1);
	/* 40C760 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
	/* 40C790 */ uchar Save(int* param_1);
	/* 40C8A0 */ uchar Load(void* param_1, uint param_2, int param_3);
};


#endif