#ifndef _C_MUSIC_MANAGER
#define _C_MUSIC_MANAGER

#include <globals.h>
#include <windows.h>
#include "CMusicSegment.h"
#include "CMusicScript.h"

class __declspec(dllexport) CMusicManager {
public:
	/* 1000B520-1000B524 00004	*/
	IDirectMusicPerformance8* GetPerformance() {
		return musicPerformance;
	}

	/* 1009AAC0 */ CMusicManager();
	/* 1009AAE0 */ ~CMusicManager();
	/* 1009AB40 */ HRESULT Initialize(HWND__* param_1, ulong param_2, ulong param_3);
	/* 1009ABC0 */ HRESULT SetSearchDirectory(char const* param_1);
	/* 1009AC20 */ IDirectMusicAudioPath* GetDefaultAudioPath();
	/* 1009AC50 */ void CollectGarbage();
	/* 1009AC60 */ long CreateSegmentFromFile(CMusicSegment** param_1, char* param_2, int param_3, int param_4);
	/* 1009AD80 */ long CreateSegmentFromResource(CMusicSegment** param_1, char* param_2, char* param_3, int param_4, int param_5);
	/* 1009AF20 */ long CreateScriptFromFile(CMusicScript** param_1, char* param_2);
	/* 1009B000 */ long CreateChordMapFromFile(IDirectMusicChordMap** param_1, char* param_2);
	/* 1009B050 */ long CreateStyleFromFile(IDirectMusicStyle8** param_1, char* param_2);
	/* 1009B0A0 */ long GetMotifFromStyle(uchar param_1, char* param_2, char* param_3);

private:
	/* 0x00 */ BOOL initalizedCOMLibrary;
	/* 0x04 */ IDirectMusicLoader8* musicLoader;
	/* 0x08 */ IDirectMusicPerformance8* musicPerformance;
};

STATIC_ASSERT(sizeof(CMusicManager) == 0x0c);

#endif