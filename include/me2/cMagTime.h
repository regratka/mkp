#ifndef C_MAG_TIME
#define C_MAG_TIME

#include <globals.h>

class cMagTime {
public:
	/* 100010C0 */ float* MagGetCurrentTime();
	/* 100010D0 */ float* MagGetFrameTime();
	/* 100010E0 */ cMagTime(cMagTime* param_1);
	/* 10001130 */ cMagTime* operator=(cMagTime* param_1);
	/* 1008D6A0 */ cMagTime();
	/* 1008D6D0 */ ~cMagTime();
	/* 1008D6E0 */ void InitTimer();
	/* 1008D750 */ float GetPerformanceCounterTime();
	/* 1008D790 */ float GetMMTime();
	/* 1008D7C0 */ void UpdateTimer();
	/* 1008D7E0 */ void ResetTimer();
};

#endif