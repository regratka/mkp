#ifndef _C_MUSIC_SCRIPT
#define _C_MUSIC_SCRIPT

#include <globals.h>

#include <windows.h>
#include <dmusici.h>

class __declspec(dllexport) CMusicScript {
public:
	/* 1009B450 */ CMusicScript(IDirectMusicPerformance8* param_1, IDirectMusicLoader8* param_2, IDirectMusicScript8* param_3);
	/* 1009B470 */ virtual ~CMusicScript();
	/* 1009B4B0 */ HRESULT CallRoutine(char* param_1);
	/* 1009B4F0 */ HRESULT SetVariableNumber(char* param_1, long param_2);
	/* 1009B530 */ HRESULT GetVariableNumber(char* param_1, long* param_2);

private:
	/* 0x04 */ IDirectMusicScript8* musicScript;
	/* 0x08 */ IDirectMusicLoader8* musicLoader;
	/* 0x0c */ IDirectMusicPerformance8* musicPerformance;
};

STATIC_ASSERT(sizeof(CMusicScript) == 0x10);


#endif