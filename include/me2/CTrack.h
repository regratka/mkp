#ifndef _C_TRACK
#define _C_TRACK

#include <globals.h>

class CTrack {
public:
	/* 10090A50 */ CTrack(CTrack* param_1);
	/* 10090D50 */ CTrack* operator=(CTrack* param_1);
	/* 100910A0 */ CTrack* scalar_destructor(uchar param_1);
	/* 100B8220 */ CTrack();
	/* 100B83E0 */ ~CTrack();
	/* 100B8510 */ void Load(basic_ifstream<char,struct_std::char_traits<char>_>* param_1);
};

#endif