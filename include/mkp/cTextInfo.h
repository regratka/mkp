#ifndef C_TEXT_INFO
#define C_TEXT_INFO

#include <globals.h>

class cTextInfo {
public:
	/* 42BBB0 */ cTextInfo();
	/* 42BC00 */ cTextInfo* scalar_destructor(uchar param_1);
	/* 42BC20 */ ~cTextInfo();
	/* 42BC30 */ void* EXP();
	/* 42BC90 */ void OnActivateLevel();
	/* 42BDC0 */ void OnAction();
	/* 42BE50 */ void OnFrame();
	/* 42BED0 */ uchar OnPlaySoundEnd(int param_1);
	/* 42BF00 */ uchar OnCollisionObject(int* param_1);
	/* 42C0F0 */ void OnNumPadExit();
	/* 42C120 */ void OnNumPadCodeCorrect();
	/* 42C260 */ uchar OnLoadChunk(uint param_1, int param_2, uint param_3, void* param_4);
	/* 42C290 */ uchar Save(int* param_1);
	/* 42C350 */ uchar Load(void* param_1, int param_2, int param_3, int param_4);
};

#endif