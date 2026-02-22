#ifndef _C_TRACK
#define _C_TRACK

#include <globals.h>
#include <fstream>

class CTrack {
public:
	/* 10090A50 */ CTrack(CTrack* param_1);
	/* 10090D50 */ CTrack* operator=(CTrack* param_1);
	/* 100910A0 */ CTrack* scalar_destructor(uchar param_1);
	/* 100B8220 */ CTrack();
	/* 100B83E0 */ ~CTrack();
	/* 100B8510 */ void Load(std::ifstream* param_1);
};

#endif