#ifndef _A_I_CONTROL_POINT
#define _A_I_CONTROL_POINT

#include <globals.h>

#include "_AI.h"

class AIControlPoint : public _AI {
public:
	/* 419BA0 */ void OnActivate();
	/* 43CE20 */ AIControlPoint();
	/* 43CE60 */ ~AIControlPoint();
	/* 43CE70 */ void* EXP();
	/* 43CED0 */ void OnActivateLevel();
	/* 43CEE0 */ bool FUN0043cee0();
	/* 43CEF0 */ void FUN0043cef0(bool param_1);
private:
	/* 0x2658 */ bool unk_2658;
};

STATIC_ASSERT(sizeof(AIControlPoint) == 0x2660);

#endif