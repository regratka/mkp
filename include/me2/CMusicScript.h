#ifndef _C_MUSIC_SCRIPT
#define _C_MUSIC_SCRIPT

#include <globals.h>
#include <dmusici.h>

class CMusicScript {
public:
	/* 100021B0 */ CMusicScript(CMusicScript* param_1);
	/* 100021E0 */ CMusicScript* operator=(CMusicScript* param_1);
	/* 10002200 */ CMusicScript* scalar_destructor(uchar param_1);
	/* 1009B450 */ CMusicScript(IDirectMusicPerformance8* param_1, IDirectMusicLoader8* param_2, uchar param_3);
	/* 1009B470 */ ~CMusicScript();
	/* 1009B4B0 */ long CallRoutine(char* param_1);
	/* 1009B4F0 */ long SetVariableNumber(char* param_1, long param_2);
	/* 1009B530 */ long GetVariableNumber(char* param_1, long* param_2);
};

#endif