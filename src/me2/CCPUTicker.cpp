#include "CCPUTicker.h"

#include <Windows.h>
#include <stdio.h>

#define MAX_MEASURES 10

typedef BOOL (WINAPI *PGNSI)(LPOSVERSIONINFO);

inline longlong rdtsc(void)
{
    uint lowV, highV;
    __asm {
        xor eax, eax
        cpuid
        rdtsc
        mov highV, edx
        mov lowV,  eax
    }
    return (longlong)lowV | (longlong)highV << 32;
}

/* 10006C60-10006C67 00007	*/
longlong CCPUTicker::GetTickCount() const {
	return tickCount;
}

/* 1008DC40-1008DC80 00040	*/
BOOL CCPUTicker::CheckHasRDTSC() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    BOOL res = FALSE;
    if (sysInfo.dwProcessorType == PROCESSOR_INTEL_PENTIUM) {
        DWORD64 firstCount;
        DWORD64 secondCount;
        try {
            __asm  rdtsc  
            firstCount = rdtsc();
            secondCount = rdtsc();
            res = firstCount < secondCount;
        } catch (...) {
            res = FALSE;
        }
        
    }
    return res;
}

/* 1008DD00-1008DD06 00006	*/
BOOL CCPUTicker::IsAvailable() const {
    return CCPUTicker::m_bHasRDTSC;
}

/* 1008DD10-1008DD5F 0004F	*/
CCPUTicker::CCPUTicker() {
    tickCount = 0;
    memset(measures, 0, sizeof(measures));
    measuresCount = 0;
    if (!CCPUTicker::m_bStaticsCalculated) {
        CCPUTicker::m_bStaticsCalculated = TRUE;
        CCPUTicker::m_bHasRDTSC = CCPUTicker::CheckHasRDTSC();
        CCPUTicker::m_bRunningOnNT = CCPUTicker::RunningOnNT();
    }
}

/* 1008DDC0-1008DDDB 0001B	*/
CCPUTicker::CCPUTicker(CCPUTicker const& p_other) {
	tickCount = p_other.tickCount;
}

/* 1008DDE0-1008DDF5 00015	*/
CCPUTicker& CCPUTicker::operator=(CCPUTicker const& p_other) {
    tickCount = p_other.tickCount;
    return *this;
}

/* 1008DE00-1008DE76 00076	*/
int CCPUTicker::RunningOnNT() {
    HMODULE kernelHandle =  GetModuleHandle("KERNEL32.DLL");
    if (kernelHandle == NULL) {
        return 0;
    }

    PGNSI versionProcAddress = (PGNSI) GetProcAddress(kernelHandle, "GetVersionEx");
    if (versionProcAddress != NULL) {
        OSVERSIONINFO info;
        ZeroMemory(&info, sizeof(OSVERSIONINFO));
        info.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
        BOOL res = versionProcAddress(&info);
        if (res == FALSE) {
            return FALSE;
        }
        return info.dwPlatformId == VER_PLATFORM_WIN32_NT;
    }
    return TRUE;
}

/* 1008DE80-1008DF39 000B9	*/
void CCPUTicker::Measure() {
    LONGLONG count;
    if (CCPUTicker::m_bHasRDTSC == FALSE) {
        count = 0;
        return;
    } else {

        if (CCPUTicker::m_bRunningOnNT == TRUE) {
            __asm CLI
        } 
    
        count = rdtsc();
        if (CCPUTicker::m_bRunningOnNT == TRUE) {
            __asm STI
        } 
    }
    tickCount = count;
    
    if (CCPUTicker::m_bFrequencyCalculated != TRUE) {
      double dVar2 = GetTickCountAsSeconds();
      this->measures[this->measuresCount] = dVar2;
      int newCount = this->measuresCount + 1;
      this->measuresCount = newCount;
      if (this->measuresCount  > 9) {
        this->measuresCount = 0;
      }
    //   this->measuresCount = newCount;
    } 
}

/* 1008DF40-1008E2F6 003B6	*/
int CCPUTicker::GetCPUFrequency(double& p_frequency, double& p_aveDev, ulong p_freqRation, uint p_maxMeasures) {
    if (Installed()) {
        p_frequency = atof(GetRegistryValue("frequency"));
        p_aveDev = atof(GetRegistryValue("target_ave_dev"));
        return TRUE;
    } 

    CCPUTicker ticker1;
    CCPUTicker ticker2;
    LARGE_INTEGER counterFrequency;
    if (!QueryPerformanceFrequency(&counterFrequency)) {
        return FALSE;
    }

    counterFrequency.QuadPart = counterFrequency.QuadPart * p_freqRation / 1000;

    LARGE_INTEGER firstCounter;
    QueryPerformanceCounter(&firstCounter);
    firstCounter.QuadPart += counterFrequency.QuadPart; 
    
    ticker1.Measure();
    
    LARGE_INTEGER secondCounter;
    QueryPerformanceCounter(&secondCounter);
    while (secondCounter.QuadPart < firstCounter.QuadPart) {
        QueryPerformanceCounter(&secondCounter);
    }
    ticker2.Measure();
    double ticksDiff = (ticker2.tickCount - ticker1.tickCount) * 1000.0 / p_freqRation;

    u_int measuresCount = 0;
    double totalDeviation = 0.0;
    double avgDeviation;
    double ticksDiffAvg;

    for (u_int measureId = 0; measureId < p_maxMeasures; measureId++) {
        QueryPerformanceCounter(&firstCounter);
        firstCounter.QuadPart += counterFrequency.QuadPart; 
    
        ticker1.Measure();
        
        QueryPerformanceCounter(&secondCounter);
        while (secondCounter.QuadPart < firstCounter.QuadPart) {
            QueryPerformanceCounter(&secondCounter);
        }
        ticker2.Measure();
        double nextTicksDiff = (ticker2.tickCount - ticker1.tickCount) * 1000.0 / p_freqRation;
        ticksDiffAvg = (nextTicksDiff + ticksDiff) / 2.0;
        totalDeviation += (nextTicksDiff - ticksDiff);
        avgDeviation = totalDeviation / measuresCount;
        
        if (avgDeviation <= p_aveDev) {
            break;
        }
    }
    p_aveDev = avgDeviation;
    p_frequency = ticksDiffAvg;
    char buffer[50];
    sprintf(buffer, "%f", p_frequency);
    CCPUTicker::WriteRegistry("frequency", buffer);
    sprintf(buffer, "%f", p_aveDev);
    CCPUTicker::WriteRegistry("target_ave_dev", buffer);
    return TRUE;
}

/* 1008e300-1008e346 00046	*/
double CCPUTicker::GetTickCountAsSeconds() const {
    if (!CCPUTicker::m_bFrequencyCalculated) {
        int freq = GetCPUFrequency(CCPUTicker::m_freq, CCPUTicker::m_deviation, 1000, 2);
        if (freq == FALSE) {
            return 0.0;
        }
        CCPUTicker::m_bFrequencyCalculated = TRUE;
    }
    return tickCount / CCPUTicker::m_freq;
}

/* 1008e350-1008e357 00007	*/
CCPUTicker::~CCPUTicker() {
}

/* 1008e360-1008e3d4 00074	*/
bool CCPUTicker::WriteRegistry(char* p_registry, char* p_value) {
    HKEY key;
    DWORD disposition = 0;
    LONG status = RegCreateKeyEx(HKEY_CURRENT_USER, "Software\\Magnum", 0, "ble", 0, KEY_ALL_ACCESS, 
        NULL, &key, &disposition);
    if (status == ERROR_SUCCESS) {
        RegSetValueEx(key, p_registry, 0, 1, (BYTE*) p_value, strlen(p_value) + 1);
        RegCloseKey(key);
    }
    return true;
}

/* 1008e3e0-1008e414 00034	*/
bool CCPUTicker::Installed() {
    HKEY key;
    LONG status = RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Magnum", 0, KEY_READ, &key);
    if (status == ERROR_SUCCESS) {
        RegCloseKey(key);
        return true;
    }
    return false;
}

/* 1008e420-1008e48f 0006f	*/
char* CCPUTicker::GetRegistryValue(char* p_registry) {
    char buffer[500];
    DWORD valueSize = sizeof(buffer);
    HKEY key;
    LONG status = RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Magnum", 0, KEY_READ, &key);
    if (status == ERROR_SUCCESS) {
        RegQueryValueEx(key, p_registry, NULL, NULL, (BYTE*) buffer, &valueSize);
        RegCloseKey(key);
        return buffer;
    }
    return "";
}

/* 1008e490-1008e4a1 00011	*/
void CCPUTicker::DeleteRegistryKey() {
	RegDeleteKey(HKEY_CURRENT_USER, "Software\\Magnum");
}

/* 1008e4b0-1008e4e4 00034	*/
double CCPUTicker::GetAverageTime() const {
    double timeSum = 0.0f;
    int processedMeasures = 0;
    while(processedMeasures < MAX_MEASURES) {
        if (measures[processedMeasures] == 0.0) {
            return timeSum / processedMeasures;
        }
        timeSum += measures[processedMeasures];
        processedMeasures++;
    }
    return timeSum / processedMeasures;
}

/* 1008e4f0-1008e4ff 0000f	*/
void CCPUTicker::Reset() {
    for (int i = 0; i < MAX_MEASURES; i++) {
        measures[i] = 0;
    }
}

