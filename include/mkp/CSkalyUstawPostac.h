#ifndef _C_SKALY_USTAW_POSTAC
#define _C_SKALY_USTAW_POSTAC

#include <globals.h>

class CSkalyUstawPostac {
public:
	/* 4153C0 */ CSkalyUstawPostac();
	/* 4153F0 */ CSkalyUstawPostac* scalar_destructor(uchar param_1);
	/* 415410 */ ~CSkalyUstawPostac();
	/* 415420 */ void* EXP();
	/* 415480 */ void OnActivate();
	/* 4154C0 */ void OnActivateLevel();
	/* 415510 */ uchar OnCollisionObject(int* param_1);
	/* 415680 */ void OnFrame();
	/* 4156F0 */ void OnFadeOutEnd();
};

#endif