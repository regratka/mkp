#ifndef _C_C_P_U_TICKER
#define _C_C_P_U_TICKER

#include <globals.h>

class CCPUTicker {
public:
	/* 10006c60 */ longlong GetTickCount();
	/* 1008dc40 */ static i32 CheckHasRDTSC();
	/* 1008dd00 */ i32 IsAvailable();
	/* 1008dd10 */ CCPUTicker();
	/* 1008dd60 */ CCPUTicker* scalar_destructor(u8 param_1);
	/* 1008ddc0 */ CCPUTicker(CCPUTicker* param_1);
	/* 1008dde0 */ CCPUTicker* operator=(CCPUTicker* param_1);
	/* 1008de00 */ static i32 RunningOnNT();
	/* 1008de80 */ void Measure();
	/* 1008df40 */ static i32 GetCPUFrequency(double* param_1, double* param_2, unsigned long param_3, u32 param_4);
	/* 1008e300 */ double GetTickCountAsSeconds();
	/* 1008e350 */ ~CCPUTicker();
	/* 1008e360 */ static bool WriteRegistry(char* param_1, char* param_2);
	/* 1008e3e0 */ static bool Installed();
	/* 1008e420 */ static char* GetRegistryValue(char* param_1);
	/* 1008e490 */ static void DeleteRegistryKey();
	/* 1008e4b0 */ double GetAverageTime();
	/* 1008e4f0 */ void Reset();
};

#endif