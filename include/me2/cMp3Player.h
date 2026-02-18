#ifndef C_MP3_PLAYER
#define C_MP3_PLAYER

#include <globals.h>

class cMp3Player {
public:
	/* 100076a0 */ cMp3Player(cMp3Player* param_1);
	/* 100076d0 */ cMp3Player* operator=(cMp3Player* param_1);
	/* 10007700 */ cMp3Player* scalar_destructor(u8 param_1);
	/* 10088e30 */ cMp3Player();
	/* 10088e60 */ ~cMp3Player();
	/* 10088e70 */ void Cleanup();
	/* 10088ed0 */ void Load(char* param_1);
	/* 10088f60 */ void Play();
	/* 10088f80 */ void Pause();
	/* 10088fa0 */ void Stop();
	/* 10088fc0 */ u8 SetVolume(f32 param_1);
	/* 10089050 */ void Rewind();
	/* 100890a0 */ bool boCompleted();
};

#endif