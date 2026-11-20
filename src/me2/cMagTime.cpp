#include "cMagTime.h"


/* 1008D6A0-1008D6CF 0002F	*/
cMagTime::cMagTime() {
	resetTime = 0.0f;
	lastTimeChange = 0.0f;
	countPeriod = 0.0f;
	currentTime = 0.0f;
	frameTime = 0.0f;
	initTimestamp.QuadPart = 0;
	measureTimestamp.QuadPart = 0;
	InitTimer();
}

/* 1008D6D0-1008D6D7 00007	*/
cMagTime::~cMagTime() {
}

/* 1008D6E0-1008D74B 0006B	*/
void cMagTime::InitTimer() {
	LARGE_INTEGER frequency;
	frequency.QuadPart = 0;
	if (QueryPerformanceFrequency(&frequency)) {
		QueryPerformanceCounter(&initTimestamp);
		elapseFunction = GetPerformanceCounterTime;
		countPeriod = 1.0f / frequency.QuadPart;
	} else {
		initTimestamp.QuadPart = timeGetTime();
		countPeriod = 0.001f;
		elapseFunction = GetMMTime;
	}
}

/* 1008D750-1008D785 00035	*/
float cMagTime::GetPerformanceCounterTime() {
	QueryPerformanceCounter(&measureTimestamp);
	return (measureTimestamp.QuadPart - initTimestamp.QuadPart) * countPeriod;
}

/* 1008D790-1008D7BA 0002A	*/
float cMagTime::GetMMTime() {
	return (timeGetTime() - initTimestamp.QuadPart) * countPeriod;
}

/* 1008D7C0-1008D7D9 00019	*/
void cMagTime::UpdateTimer() {
	float fVar1 = (this->*elapseFunction)();
	fVar1 -= resetTime;
	currentTime = fVar1;
	frameTime = fVar1 - lastTimeChange;
	lastTimeChange = fVar1;

}

/* 1008D7E0-1008D7F6 00016	*/
void cMagTime::ResetTimer() {
	resetTime =  (this->*elapseFunction)();
	frameTime = 0.0f;
	currentTime = 0.0f;
	lastTimeChange = 0.0f;
}

