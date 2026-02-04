#include "CCPUTicker.h"
#include <stdio.h>
#include <math.h>

#define MAX_MEASURES 10

LONGLONG CCPUTicker::GetTickCount() const {
    return tickCount;
}

inline LONGLONG rdtsc(void)
{
    unsigned int lowV, highV;
    __asm {
        xor eax, eax
        cpuid
        rdtsc
        mov highV, edx
        mov lowV,  eax
    }
    return (LONGLONG)lowV | (LONGLONG)highV << 32;
}

// TODO
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

BOOL CCPUTicker::IsAvailable() const {
    return CCPUTicker::m_bHasRDTSC;
}

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

CCPUTicker::CCPUTicker(CCPUTicker const& other) {
    tickCount = other.tickCount;
}


CCPUTicker& CCPUTicker::operator=(CCPUTicker const & other) {
    tickCount = other.tickCount;
    return *this;
}

typedef BOOL (WINAPI *PGNSI)(LPOSVERSIONINFO);

BOOL CCPUTicker::RunningOnNT() {
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


void CCPUTicker::Measure() {
    if (CCPUTicker::m_bHasRDTSC == FALSE) {
        tickCount = 0;
        return;
    }
    
    if (CCPUTicker::m_bRunningOnNT == TRUE) {
        __asm CLI
    } 

    tickCount = rdtsc();
    if (CCPUTicker::m_bRunningOnNT == TRUE) {
        __asm STI
    } 
    
    
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


BOOL CCPUTicker::GetCPUFrequency(double& frequency, double& ave_dev, u_long freqRatio, u_int maxMeasures) {
    if (Installed()) {
        frequency = atof(GetRegistryValue("frequency"));
        ave_dev = atof(GetRegistryValue("target_ave_dev"));
        return TRUE;
    } 

    CCPUTicker ticker1;
    CCPUTicker ticker2;
    LARGE_INTEGER counterFrequency;
    if (!QueryPerformanceFrequency(&counterFrequency)) {
        return FALSE;
    }

    counterFrequency.QuadPart = counterFrequency.QuadPart * freqRatio / 1000;

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
    double ticksDiff = (ticker2.tickCount - ticker1.tickCount) * 1000.0 / freqRatio;

    u_int measuresCount = 0;
    double totalDeviation = 0.0;
    double avgDeviation;
    double ticksDiffAvg;

    for (u_int measureId = 0; measureId < maxMeasures; measureId++) {
        QueryPerformanceCounter(&firstCounter);
        firstCounter.QuadPart += counterFrequency.QuadPart; 
    
        ticker1.Measure();
        
        QueryPerformanceCounter(&secondCounter);
        while (secondCounter.QuadPart < firstCounter.QuadPart) {
            QueryPerformanceCounter(&secondCounter);
        }
        ticker2.Measure();
        double nextTicksDiff = (ticker2.tickCount - ticker1.tickCount) * 1000.0 / freqRatio;
        ticksDiffAvg = (nextTicksDiff + ticksDiff) / 2.0;
        totalDeviation += (nextTicksDiff - ticksDiff);
        avgDeviation = totalDeviation / measuresCount;
        
        if (avgDeviation <= ave_dev) {
            break;
        }
    }
    ave_dev = avgDeviation;
    frequency = ticksDiffAvg;
    char buffer[50];
    sprintf(buffer, "%f", frequency);
    CCPUTicker::WriteRegistry("frequency", buffer);
    sprintf(buffer, "%f", ave_dev);
    CCPUTicker::WriteRegistry("target_ave_dev", buffer);
    return TRUE;
}

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

CCPUTicker::~CCPUTicker() {}

bool CCPUTicker::WriteRegistry(char* registry, char* value) {
    HKEY key;
    DWORD disposition = 0;
    LONG status = RegCreateKeyEx(HKEY_CURRENT_USER, "Software\\Magnum", 0, "ble", 0, KEY_ALL_ACCESS, 
        NULL, &key, &disposition);
    if (status == ERROR_SUCCESS) {
        RegSetValueEx(key, registry, 0, 1, (BYTE*) value, strlen(value) + 1);
        RegCloseKey(key);
    }
    return true;
}

bool CCPUTicker::Installed() {
    HKEY key;
    LONG status = RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Magnum", 0, KEY_READ, &key);
    if (status == ERROR_SUCCESS) {
        RegCloseKey(key);
        return true;
    }
    return false;
}

char* CCPUTicker::GetRegistryValue(char* registry) {
    char buffer[500];
    DWORD valueSize = sizeof(buffer);
    HKEY key;
    LONG status = RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Magnum", 0, KEY_READ, &key);
    if (status == ERROR_SUCCESS) {
        RegQueryValueEx(key, registry, NULL, NULL, (BYTE*) buffer, &valueSize);
        RegCloseKey(key);
        return buffer;
    }
    return "";
}

void CCPUTicker::DeleteRegistryKey() {
    RegDeleteKey(HKEY_CURRENT_USER, "Software\\Magnum");
}

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

void CCPUTicker::Reset() {
    for (int i = 0; i < MAX_MEASURES; i++) {
        measures[i] = 0;
    }
}