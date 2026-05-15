#ifndef _C_END_PART1
#define _C_END_PART1

#include <globals.h>

class CEndPart1 {
public:
	/* 43FD00 */ CEndPart1();
	/* 43FD70 */ CEndPart1* scalar_destructor(uchar param_1);
	/* 43FD90 */ ~CEndPart1();
	/* 43FDF0 */ void* EXP();
	/* 43FE50 */ void OnActivate();
	/* 43FEA0 */ void OnActivateLevel();
	/* 43FED0 */ void OnAction(char* param_1);
	/* 43FF00 */ uchar OnAction();
	/* 43FFD0 */ uchar OnPlaySoundEnd(int param_1);
};

#endif