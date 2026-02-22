#ifndef _C_STATE
#define _C_STATE

#include <globals.h>

class CState {
public:
	/* 10001320 */ CState* operator=(CState* param_1);
	/* 10011020 */ CState(CState* param_1);
	/* 10011140 */ CState* scalar_destructor(uchar param_1);
	/* 100BEB00 */ CState();
	/* 100BEB20 */ ~CState();
	/* 100BEB30 */ void SetState(char* param_1);
	/* 100BEB40 */ void SetState(CState* param_1);
};

#endif