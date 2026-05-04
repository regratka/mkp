#ifndef _MAG_ANIM_MESH_MGR
#define _MAG_ANIM_MESH_MGR

#include <globals.h>
#include <vector>

#include "MagSingleton.h"
#include "cMagLog.h"

struct AnimData {
	/* 0x00 */ uchar f_00[0x600-0x00];
	/* 0x600 */ int unkn_600;
};

class MagAnimMeshMgr : public MagSingleton<MagAnimMeshMgr> {
public:
	/* 10044900 */ MagAnimMeshMgr();
	/* 100449A0 */ virtual ~MagAnimMeshMgr();

private:
    /* 0x04 */ std::vector<AnimData> data;
	/* 0x14 */ cMagLog log;
};

#endif