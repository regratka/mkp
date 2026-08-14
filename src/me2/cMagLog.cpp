#include "cMagLog.h"

#include <stdio.h>

/* 10030390-100303AB 0001B	*/
cMagLog::cMagLog() {
    logEnabled = false;
    logFilename = "log.txt";
    ReadSettings("data\\Ustawienia.cfg");
}

/* 100303B0-100303F0 00040	*/
void cMagLog::DeleteLog() {
    DeleteFileA(logFilename);
    DeleteFileA("loadtime.txt");
    DeleteFileA("crash.txt");
    DeleteFileA("TexCrash.txt");
    DeleteFileA("data.txt");
    DeleteFileA("clientserver.txt");
    DeleteFileA("Textures.txt");
    DeleteFileA("Dummy.txt");
}

/* 100303F0-10030455 00065	*/
void cMagLog::DataLog(char const * p_format, ...) {
    if (logEnabled == false) {
        return; 
    }
    char buffer[512];
    va_list args;
    va_start(args, p_format);
    _snprintf(buffer, 0x200, p_format, args);
    FILE* dataFile = fopen("data.txt", "a");
    fprintf(dataFile, "%s\n", buffer);
    fclose(dataFile);
}

/* 10030460-100304D7 00077	*/
void cMagLog::CrashLog(char const * p_format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, p_format);
    _snprintf(buffer, 0x200, p_format, args);
    FILE* dataFile = fopen("crash.txt", "a");
    fprintf(dataFile, "%s\n", buffer);
    fclose(dataFile);
    DebugLog(buffer);
}

/* 100304E0-10030557 00077	*/
void cMagLog::TextureErrorLog(char const * p_format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, p_format);
    _snprintf(buffer, 0x200, p_format, args);
    FILE* dataFile = fopen("TexCrash.txt", "a");
    fprintf(dataFile, "%s\n", buffer);
    fclose(dataFile);
    DebugLog(buffer);
}

/* 10030560-100305D7 00077	*/
void cMagLog::TexturesLog(char const * p_format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, p_format);
    _snprintf(buffer, 0x200, p_format, args);
    FILE* dataFile = fopen("Textures.txt", "a");
    fprintf(dataFile, "%s\n", buffer);
    fclose(dataFile);
    DebugLog(buffer);
}

/* 100305E0-10030656 00076	*/
void cMagLog::FileLog(char const * p_format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, p_format);
    _snprintf(buffer, 0x200, p_format, args);
    FILE* dataFile = fopen(logFilename, "a");
    fprintf(dataFile, "%s\n", buffer);
    fclose(dataFile);
    DebugLog(buffer);
}

/* 100305E0-10030656 00076	*/
void cMagLog::OutputLog(char const * p_format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, p_format);
    _snprintf(buffer, 0x200, p_format, args);
    FILE* dataFile = fopen(logFilename, "a");
    fprintf(dataFile, "%s\n", buffer);
    fclose(dataFile);
    DebugLog(buffer);
}

/* 10030660-100306D7 00077	*/
void cMagLog::DummyLog(char const * p_format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, p_format);
    _snprintf(buffer, 0x200, p_format, args);
    FILE* dataFile = fopen("Dummy.txt", "a");
    fprintf(dataFile, "%s\n", buffer);
    fclose(dataFile);
    DebugLog(buffer);
}

/* 100306E0-10030724 00044	*/
void cMagLog::DebugLog(char const * p_format, ...) {
    if (logEnabled == false) {
        return;
    }    
    char buffer[512];
    va_list args;
    va_start(args, p_format);
    _snprintf(buffer, 0x200, p_format, args);
    OutputDebugStringA(buffer);
}

/* 10030730-10030733 00003	*/
void cMagLog::DebugLog(D3DXMATRIX matrix) {
    return;
}

/* 10030740-10030743 00003	*/
void cMagLog::DebugLog(D3DXVECTOR3 param_1) {
    return;
}

/* 10030750-100307C7 00077	*/
void cMagLog::ClientServerLog(char const * p_format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, p_format);
    _snprintf(buffer, 0x200, p_format, args);
    FILE* dataFile = fopen("clientserver.txt", "a");
    fprintf(dataFile, "%s\n", buffer);
    fclose(dataFile);
    DebugLog(buffer);
}

/* 100307D0-1003086C 0009C	*/
void cMagLog::ReadSettings(char* p_settingsPath) {
    char buffer[100];
    FILE* settingsFile = fopen(p_settingsPath, "r");
    if (settingsFile == NULL) {
        return;
    }

   memset(buffer, 0, sizeof(buffer));
    while (!feof(settingsFile)) {
        fgets(buffer, 99, settingsFile);
        char* settingName = strtok(buffer," :,");
        int cmpRes = stricmp(settingName, "Log");
        if (cmpRes == 0) {
            char* settingVal = strtok(NULL," :");
            if (settingVal != NULL) {
                logEnabled = atoi(settingVal);
            }
        }
    }
    fclose(settingsFile);
}

/* 1005A5E0-1005A5E3 00003	*/
void cMagLog::DebugLog(D3DXVECTOR3* p_vector) {
    return;
}

/* 1005A5F0-1005A5F3 00003  */ 
void cMagLog::DebugLog(char* param_1, D3DXVECTOR3* param_2) {
    return;
}

