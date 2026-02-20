#ifndef _C_C_P_U_TICKER
#define _C_C_P_U_TICKER

#include <globals.h>

class CCPUTicker {
public:
	/* 10006C60 */ longlong GetTickCount() const;
	/* 1008DD00 */ int IsAvailable() const;
	/* 1008DD10 */ CCPUTicker();
	/* 1008DDC0 */ CCPUTicker(CCPUTicker const& p_other);
	/* 1008DDE0 */ CCPUTicker& operator=(CCPUTicker const& p_other);

	/* 1008DE80 */ void Measure();
	/* 1008DF40 */ static int GetCPUFrequency(double& p_frequency, double& p_aveDev, ulong p_freqRation, uint p_maxMeasures);
	/* 1008E300 */ double GetTickCountAsSeconds() const;
	/* 1008E350 */ virtual ~CCPUTicker();
	/* 1008E360 */ static bool WriteRegistry(char* param_1, char* param_2);
	/* 1008E3E0 */ static bool Installed();
	/* 1008E420 */ static char* GetRegistryValue(char* param_1);
	/* 1008E490 */ static void DeleteRegistryKey();
	/* 1008E4B0 */ double GetAverageTime() const;
	/* 1008E4F0 */ void Reset();

protected:
	/* 1008DC40 */ static int CheckHasRDTSC();
	/* 1008DE00 */ static int RunningOnNT();

protected:
	static BOOL m_bHasRDTSC;
    static BOOL m_bRunningOnNT;
    static BOOL m_bStaticsCalculated;
    static double m_deviation;
    static double m_freq;
    static BOOL m_bFrequencyCalculated;

private:
	/* 0x008 */	longlong tickCount;
    /* 0x010 */	double measures[100];
    /* 0x330 */	int measuresCount;
};

STATIC_ASSERT(sizeof(CCPUTicker) == 0x338);

#endif