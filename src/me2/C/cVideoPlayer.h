#ifndef C_VIDEO_PLAYER
#define C_VIDEO_PLAYER

#include <globals.h>

class cVideoPlayer {
public:
	 /* 10007760 */ cVideoPlayer(cVideoPlayer* p_other);
	 /* 10088B80 */ void Load(char* p_videoName);

private:
	 /* 0x00 */ unsigned char field_0x0[0xd64];
};

STATIC_ASSERT(sizeof(cVideoPlayer) == 0xd64);
#endif