#ifndef _C_MUSIC_SEGMENT
#define _C_MUSIC_SEGMENT

#include <globals.h>

#include <windows.h>
#include <dmusici.h>

class __declspec(dllexport) CMusicSegment {
public:
	/* 1009B150 */ CMusicSegment(IDirectMusicPerformance8* param_1, IDirectMusicLoader8* param_2, IDirectMusicSegment8* param_3);
	/* 1009B1C0 */ virtual ~CMusicSegment();
	/* 1009B230 */ long Play(ulong param_1, uchar param_2);
	/* 1009B290 */ long Download(IDirectMusicAudioPath* param_1);
	/* 1009B2E0 */ long Unload(uchar param_1);
	/* 1009B330 */ long SetVolume(int param_1, IDirectMusicAudioPath* param_2);
	/* 1009B3A0 */ int IsPlaying();
	/* 1009B3D0 */ long Stop(ulong param_1);
	/* 1009B400 */ long SetRepeats(ulong param_1);
	/* 1009B420 */ long GetStyle(IDirectMusicStyle8** param_1, ulong param_2);

private:
	/* 0x04 */ IDirectMusicSegment8* directMusicSegment;
	/* 0x08 */ IDirectMusicLoader8* directMusicLoader;
	/* 0x0c */ IDirectMusicPerformance8* directMusicPerformance;
	/* 0x10 */ IDirectMusicAudioPath8* directMusicAudioPath;
	/* 0x14 */ BOOL downloaded;
};

STATIC_ASSERT(sizeof(CMusicSegment) == 0x18);

#endif