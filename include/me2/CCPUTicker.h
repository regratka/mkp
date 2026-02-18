#ifndef _C_C_P_U_TICKER
#define _C_C_P_U_TICKER

#include <globals.h>

class CCPUTicker {
public:
	/* 10006c60 */ longlong GetTickCount();
	/* 1008dc40 */ static int CheckHasRDTSC();
	/* 1008dd00 */ int IsAvailable();
	/* 1008dd10 */ CCPUTicker();
	/* 1008ddc0 */ CCPUTicker(CCPUTicker* param_1);
	/* 1008dde0 */ CCPUTicker* operator=(CCPUTicker* param_1);
	/* 1008de00 */ static int RunningOnNT();
	/* 1008de80 */ void Measure();
	/* 1008df40 */ static int GetCPUFrequency(double* param_1, double* param_2, ulong param_3, uint param_4);
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