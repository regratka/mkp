#ifndef _C_MUSIC_SEGMENT
#define _C_MUSIC_SEGMENT

#include <globals.h>

#include "windows.h"
#include <dsound.h>
#include <dmusici.h>

class CMusicSegment {
public:
	/* 100020F0 */ CMusicSegment(CMusicSegment* param_1);
	/* 10002120 */ CMusicSegment* operator=(CMusicSegment* param_1);
	/* 10002150 */ CMusicSegment* scalar_destructor(uchar param_1);
	/* 1009B150 */ CMusicSegment(IDirectMusicPerformance8* param_1, IDirectMusicLoader8* param_2, IDirectMusicSegment8* param_3);
	/* 1009B1C0 */ ~CMusicSegment();
	/* 1009B230 */ long Play(ulong param_1, uchar param_2);
	/* 1009B290 */ long Download(IDirectMusicAudioPath* param_1);
	/* 1009B2E0 */ long Unload(uchar param_1);
	/* 1009B330 */ long SetVolume(int param_1, IDirectMusicAudioPath* param_2);
	/* 1009B3A0 */ int IsPlaying();
	/* 1009B3D0 */ long Stop(ulong param_1);
	/* 1009B400 */ long SetRepeats(ulong param_1);
	/* 1009B420 */ long GetStyle(IDirectMusicStyle8** param_1, ulong param_2);
};

#endif