#ifndef _C_ACTION
#define _C_ACTION

#include <globals.h>

class CAction {

	class STATE_Empty {
		public:
			/* 4177B0 */ STATE_Empty* scalar_destructor(uchar param_1);
			/* 417D10 */ void OnEnterState();
		};

	class STATE_RuchX {
		public:
			/* 4177D0 */ uchar OnEnterState(int param_1);
			/* 417830 */ void OnFrame();
		};

	class STATE_RuchY {
		public:
			/* 4179D0 */ void OnFrame();
		};

	class STATE_RuchZ {
		public:
			/* 417B70 */ void OnFrame();
		};

public:
	/* 416980 */ CAction();
	/* 4169E0 */ uchar scalar_destruction(uchar param_1);
	/* 416A00 */ ~CAction();
	/* 416A10 */ void* EXP();
	/* 416A70 */ void OnActivateLevel();
	/* 416BD0 */ uchar FUN00416bd0(uchar param_1);
	/* 416CF0 */ void OnFrame();
	/* 416D50 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
	/* 416D80 */ void OnAction();
	/* 416E50 */ void OnAnimFrameMeter(char* param_1, int param_2);
	/* 416EF0 */ uchar FUN00416ef0();
	/* 416F20 */ void FUN00416f20();
	/* 416F90 */ uchar OnAnimEnd(char* param_1);
	/* 416FF0 */ uchar FUN00416ff0();
	/* 417100 */ uchar FUN00417100();
	/* 417140 */ void FUN00417140();
	/* 4171E0 */ uchar FUN004171e0();
	/* 417210 */ uchar FUN00417210(uchar param_1);
	/* 417310 */ uchar FUN00417310();
	/* 417440 */ uchar Save(int* param_1);
	/* 4175B0 */ uchar Load(void* param_1, uint param_2, int param_3);
};



#endif