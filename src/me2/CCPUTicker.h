#include <Windows.h>

class CCPUTicker {

public:
    LONGLONG GetTickCount() const;
    BOOL IsAvailable() const;

    CCPUTicker();
    virtual ~CCPUTicker();
    CCPUTicker(CCPUTicker const& other);

    CCPUTicker& operator=(CCPUTicker const & other);

    double GetTickCountAsSeconds() const;
    double GetAverageTime() const;
    void Measure();
    static void DeleteRegistryKey();
    static bool WriteRegistry(char* registry, char* value);
    static BOOL GetCPUFrequency(double& frequency, double& ave_dev, u_long freqRation, u_int maxMeasures);
    static bool Installed();
    static char* GetRegistryValue(char* registry);
    void Reset();

protected:
    static int CheckHasRDTSC();
    static int RunningOnNT();

protected:
    static BOOL m_bHasRDTSC;
    static BOOL m_bRunningOnNT;
    static BOOL m_bStaticsCalculated;
    static double m_deviation;
    static double m_freq;
    static BOOL m_bFrequencyCalculated;

private:
    LONGLONG tickCount;
    double measures[100];
    int measuresCount;
};


