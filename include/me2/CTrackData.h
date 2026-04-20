#ifndef _C_TRACK_DATA
#define _C_TRACK_DATA

#include <globals.h>
#include <vector>

class CTrackData {
public:
	/* 0x00 */ D3DXVECTOR3 position;
	/* 0x0c */ std::vector<D3DXVECTOR3> vector1;
	/* 0x1c */ std::vector<D3DXVECTOR3> vector2;
	/* 0x2c */ int unkn_2c;
};

STATIC_ASSERT(sizeof(CTrackData) == 0x30);

#endif