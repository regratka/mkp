#ifndef C_HANDS
#define C_HANDS

#include <globals.h>

class cHands {
public:
	/* 404AF0 */ cHands();
	/* 404B10 */ uchar scalar_destructor(uchar param_1);
	/* 404B30 */ ~cHands();
	/* 404B40 */ void OnActivate();
	/* 404B90 */ void OnActivateLevel();
	/* 404C60 */ void OnFrame();
	/* 404CD0 */ uchar FUN00404cd0();
	/* 404CE0 */ uchar FUN00404ce0();
	/* 404CF0 */ uchar FUN00404cf0();
	/* 404D00 */ void FUN00404d00();
	/* 404D10 */ void OnAnimEnd(char* param_1);
};

#endif