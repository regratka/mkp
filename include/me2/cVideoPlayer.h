#ifndef C_VIDEO_PLAYER
#define C_VIDEO_PLAYER

#include <globals.h>

class cVideoPlayer {
public:
	/* 10007760 */ cVideoPlayer(cVideoPlayer* param_1);
	/* 10007890 */ cVideoPlayer* operator=(cVideoPlayer* param_1);
	/* 10088a60 */ cVideoPlayer();
	/* 10088aa0 */ virtual ~cVideoPlayer();
	/* 10088af0 */ void Cleanup();
	/* 10088b80 */ void Load(char* param_1);
	/* 10088c80 */ void Play();
	/* 10088ca0 */ void Pause();
	/* 10088cc0 */ void Stop();
	/* 10088ce0 */ void SetVolume(long param_1);
	/* 10088d50 */ void Rewind();
	/* 10088da0 */ bool boCompleted();
};

#endif