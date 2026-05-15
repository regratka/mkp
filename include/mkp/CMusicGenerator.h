#ifndef _C_MUSIC_GENERATOR
#define _C_MUSIC_GENERATOR

#include <globals.h>

class CMusicGenerator {
public:
	/* 419AB0 */ CMusicGenerator();
	/* 419B10 */ CMusicGenerator* scalar_destructor(uchar param_1);
	/* 419B30 */ ~CMusicGenerator();
	/* 419B40 */ void* EXP();
	/* 419BB0 */ void OnAction();
	/* 419C30 */ void OnFrame();
	/* 419CA0 */ void OnActivate();
	/* 419DE0 */ void OnUpdateMenuSettings();
	/* 419E10 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
};

#endif