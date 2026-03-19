#ifndef C_MAG_CAMERA
#define C_MAG_CAMERA

#include <globals.h>

#include "cMagUtility.h"

class cMagCamera : public cMagUtility {
public:
	/* 10021350 */ void SetPosition(uint param_1, uint param_2, uint param_3);
	/* 10021370 */ void SetView(uint param_1, uint param_2, uint param_3);
	/* 10021390 */ uchar GePosition(uint* param_1);
	/* 100213C0 */ uchar GetView(uint* param_1);
	/* 100213F0 */ cMagCamera(cMagCamera* param_1);
	/* 10021520 */ cMagCamera* operator=(cMagCamera* param_1);
	/* 10021660 */ cMagCamera* scalar_destructor(uchar param_1);
	/* 10060620 */ ~cMagCamera();
	/* 10060630 */ cMagCamera(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9);
	/* 10060690 */ void Init(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9);
	/* 100606D0 */ void PositionCamera(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9);
	/* 10060790 */ void RotateView(float param_1, float param_2, float param_3);
	/* 100608B0 */ void MoveCamera(float param_1);
	/* 10060960 */ bool MoveCameraByMouse(int param_1, int param_2, int param_3, int param_4);
};

#endif