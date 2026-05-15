#ifndef _C_BUTTON
#define _C_BUTTON

#include <globals.h>

#include "cMagGameObject.h"

class CButton {
	class STATE_Kolizja {
	public:
		/* 40B750 */ void OnEnterState();
		/* 418D80 */ uchar OnCollisionObject(int* param_1);
	};

	class STATE_Odleglosc {
	public:
		/* 418E20 */ void OnEnterState();
		/* 418E40 */ void OnInputKey();
		/* 418F00 */ void OnDestinationDir();
	};

	class STATE_RuchX {
	public:
		/* 418F10 */ void OnEnterState();
		/* 418F70 */ void OnFrame();
	};

	class STATE_RuchY {
	public:
		/* 419070 */ void OnFrame();
	};

	class STATE_RuchZ {
	public:
		/* 419170 */ void OnFrame();
	};

public:
	/* 417DF0 */ CButton();
	/* 417F00 */ CButton* scalar_destructor(uchar param_1);
	/* 417F20 */ ~CButton();
	/* 417F80 */ void* EXP();
	/* 417FE0 */ void OnActivateLevel();
	/* 4182A0 */ void FUN004182a0();
	/* 418380 */ void OnAction();
	/* 4183D0 */ uchar Save(int* param_1);
	/* 418480 */ uchar Load(void* param_1, uint param_2, int param_3);
	/* 418580 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
	/* 4185B0 */ uchar FUN004185b0(float param_1);
	/* 418610 */ uchar FUN00418610(int param_1, int param_2, int param_3);
	/* 418760 */ void OnFadeOutEnd();
	/* 4187B0 */ void FUN004187b0();
	/* 418A90 */ void FUN00418a90();
	/* 418C90 */ void FUN00418c90();
	/* 418D40 */ uchar OnDestTime(cMagGameObject* param_1);
};

#endif