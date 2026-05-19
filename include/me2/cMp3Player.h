#ifndef C_MP3_PLAYER
#define C_MP3_PLAYER

#include <globals.h>
#include <Dshow.h>

class DLLEXPORT cMp3Player {
public:

	/* 10088E30 */ cMp3Player();
	/* 10088E60 */ virtual ~cMp3Player();
	/* 10088E70 */ void Cleanup();
	/* 10088ED0 */ void Load(char* param_1);
	/* 10088F60 */ void Play();
	/* 10088F80 */ void Pause();
	/* 10088FA0 */ void Stop();
	/* 10088FC0 */ void SetVolume(float p_volume);
	/* 10089050 */ void Rewind();
	/* 100890A0 */ bool boCompleted();

private:
	/* 0x04 */	IUnknown*  unknown;
    /* 0x08 */	IGraphBuilder* graphBuilder;
    /* 0x0c */	IMediaControl* mediaControl;
    /* 0x10 */	IMediaEventEx* mediaEventExt;
    /* 0x14 */	bool loaded;

};

STATIC_ASSERT(sizeof(cMp3Player) == 0x18);

#endif