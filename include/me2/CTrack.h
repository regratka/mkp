#ifndef _C_TRACK
#define _C_TRACK

#include <globals.h>
#include <vector>
#include <fstream>

#include "cMagKernel.h"
#include "CTrackData.h"

class __declspec(dllexport) CTrack : public cMagKernel {
public:
	/* 100B8220 */ CTrack();
	/* 100B83E0 */ ~CTrack();
	/* 100B8510 */ void Load(std::ifstream& param_1);

private: 
	/* 0x1dc */ std::vector<CTrackData> dataVector;
	/* 0x1ec */ int trackPointCoords;
};

STATIC_ASSERT(sizeof(CTrack) == 0x1f0);


#endif