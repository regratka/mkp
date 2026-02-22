#ifndef _C_MUSIC_MANAGER
#define _C_MUSIC_MANAGER

#include <globals.h>

class CMusicManager {
public:
	/* 100020D0 */ uchar operator=(uchar param_1);
	/* 1000B520 */ uchar GetPerformance();
	/* 1009AAC0 */ CMusicManager();
	/* 1009AAE0 */ ~CMusicManager();
	/* 1009AB40 */ long Initialize(HWND__* param_1, ulong param_2, ulong param_3);
	/* 1009ABC0 */ long SetSearchDirectory(char* param_1);
	/* 1009AC20 */ uchar GetDefaultAudioPath();
	/* 1009AC50 */ void CollectGarbage();
	/* 1009AC60 */ long CreateSegmentFromFile(CMusicSegment** param_1, char* param_2, int param_3, int param_4);
	/* 1009AD80 */ long CreateSegmentFromResource(CMusicSegment** param_1, char* param_2, char* param_3, int param_4, int param_5);
	/* 1009AF20 */ long CreateScriptFromFile(CMusicScript** param_1, char* param_2);
	/* 1009B000 */ long CreateChordMapFromFile(IDirectMusicChordMap** param_1, char* param_2);
	/* 1009B050 */ long CreateStyleFromFile(IDirectMusicStyle8** param_1, char* param_2);
	/* 1009B0A0 */ long GetMotifFromStyle(uchar param_1, char* param_2, char* param_3);
};

#endif