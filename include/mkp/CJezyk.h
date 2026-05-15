#ifndef _C_JEZYK
#define _C_JEZYK

#include <globals.h>

class CJezyk {
class Idle {
public:
	/* 43DC50 */ void OnEnterState();
};

class WalkNaviPath {
public:
	/* 43D7C0 */ void OnEnterState();
	/* 43D8A0 */ void OnFrame();
	/* 43DAC0 */ uchar OnDestinationPos(int param_1);
	/* 43DB60 */ uchar OnCollisionObject(int* param_1);
	/* 43DC30 */ uchar OnAnimEnd(char* param_1);
};


public:
	/* 43D110 */ CJezyk();
	/* 43D260 */ CJezyk* scalar_destructor(uchar param_1);
	/* 43D280 */ ~CJezyk();
	/* 43D2C0 */ void* EXP();
	/* 43D320 */ void OnActivateLevel();
	/* 43D420 */ void FUN0043d420();
	/* 43D4D0 */ uchar OnPlaySoundEnd(int param_1);
	/* 43D500 */ void FUN0043d500();
	/* 43D5F0 */ uchar FUN0043d5f0();
	/* 43D620 */ uchar FUN0043d620();
};


#endif