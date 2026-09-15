#ifndef C_MAG_AUDIO
#define C_MAG_AUDIO

#include <globals.h>
#include <Dmusici.h>

#include "cMagLog.h"


class DLLEXPORT cMagAudio {
public:
	/* 1000B510 */ IDirectMusicPerformance8* getPerformance();
	/* 1000B520 */ IDirectMusicLoader8* getLoader();
	/* 100884A0 */ cMagAudio();
	/* 100884C0 */ virtual ~cMagAudio();
	/* 100884D0 */ HRESULT Setup();
	/* 10088540 */ void Kill();

private:
	/* 0x04 */ IDirectMusicPerformance8* musicPerformance;
	/* 0x08 */ IDirectMusicLoader8* musicLoader;
	/* 0x0c */ cMagLog log;
};

STATIC_ASSERT(sizeof(cMagAudio) == 0x14);

#endif