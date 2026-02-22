#ifndef C_MAG_AUDIO
#define C_MAG_AUDIO

#include <globals.h>

class cMagAudio {
public:
	/* 10001ED0 */ cMagAudio(cMagAudio* param_1);
	/* 10001F00 */ cMagAudio* operator=(cMagAudio* param_1);
	/* 10001F30 */ cMagAudio* scalar_destructor(uchar param_1);
	/* 100884A0 */ cMagAudio();
	/* 100884C0 */ ~cMagAudio();
	/* 100884D0 */ long Setup();
	/* 10088540 */ void Kill();
};

#endif