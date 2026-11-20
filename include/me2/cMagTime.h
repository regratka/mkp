#ifndef C_MAG_TIME
#define C_MAG_TIME

#include <globals.h>
#include <Windows.h>



class DLLEXPORT cMagTime {
public:
	typedef float (cMagTime::*ElapseFunction)();

	/* 100010C0-100010C4 00004	*/
	float& MagGetCurrentTime() {
		return currentTime;
	}
	
	/* 100010D0-100010D4 00004	*/
	float& MagGetFrameTime() {
		return frameTime;
	}

	/* 1008D6A0 */ cMagTime();
	/* 1008D6D0 */ virtual ~cMagTime();
	/* 1008D6E0 */ void InitTimer();

private:
	/* 1008D750 */ float GetPerformanceCounterTime();
	/* 1008D790 */ float GetMMTime();

public:
	/* 1008D7C0 */ void UpdateTimer();
	/* 1008D7E0 */ void ResetTimer();

private:
	/* 0x08 */ ElapseFunction elapseFunction;
	/* 0x0c */ float resetTime;
	/* 0x10 */ float lastTimeChange;
	/* 0x14 */ float countPeriod;
	/* 0x18 */ float currentTime;
	/* 0x1c */ float frameTime;
	/* 0x20 */ LARGE_INTEGER initTimestamp;
	/* 0x28 */ LARGE_INTEGER measureTimestamp;

};



STATIC_ASSERT(sizeof(cMagTime) == 0x30);

#endif