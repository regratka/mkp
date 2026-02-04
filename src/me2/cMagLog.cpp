#include "cMagLog.h"

#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <windows.h>

static char read_flag[] = "r";
static char print_buf[] ="%s\n";

cMagLog::cMagLog(){
    logEnabled = false;
    logFilename = "log.txt";
    ReadSettings("data\\Ustawienia.cfg");
}

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

void cMagLog::DataLog(char const * format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, format);
    _snprintf(buffer, 0x200, format, args);
    FILE* dataFile = fopen("data.txt", "a");
    fprintf(dataFile, print_buf, buffer);
    fclose(dataFile);
}

void cMagLog::CrashLog(char const * format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, format);
    _snprintf(buffer, 0x200, format, args);
    FILE* dataFile = fopen("crash.txt", "a");
    fprintf(dataFile, print_buf, buffer);
    fclose(dataFile);
    DebugLog(buffer);
}

void cMagLog::TextureErrorLog(char const * format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, format);
    _snprintf(buffer, 0x200, format, args);
    FILE* dataFile = fopen("TexCrash.txt", "a");
    fprintf(dataFile, print_buf, buffer);
    fclose(dataFile);
    DebugLog(buffer);
}

void cMagLog::TexturesLog(char const * format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, format);
    _snprintf(buffer, 0x200, format, args);
    FILE* dataFile = fopen("Textures.txt", "a");
    fprintf(dataFile, print_buf, buffer);
    fclose(dataFile);
    DebugLog(buffer);
}

void cMagLog::FileLog(char const * format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, format);
    _snprintf(buffer, 0x200, format, args);
    FILE* dataFile = fopen(logFilename, "a");
    fprintf(dataFile, print_buf, buffer);
    fclose(dataFile);
    DebugLog(buffer);
}

void cMagLog::DummyLog(char const * format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, format);
    _snprintf(buffer, 0x200, format, args);
    FILE* dataFile = fopen("Dummy.txt", "a");
    fprintf(dataFile, print_buf, buffer);
    fclose(dataFile);
    DebugLog(buffer);
}

void cMagLog::DebugLog(char const * format, ...) {
    if (logEnabled == false) {
        return;
    }    
    char buffer[512];
    va_list args;
    va_start(args, format);
    _snprintf(buffer,0x200,format,args);
    OutputDebugStringA(buffer);
}


void cMagLog::DebugLog(D3DXMATRIX matrix) {
    return;
}

void cMagLog::ClientServerLog(char const * format, ...) {
    if (logEnabled == false) {
        return;
    }
    char buffer[512];
    va_list args;
    va_start(args, format);
    _snprintf(buffer, 0x200, format, args);
    FILE* dataFile = fopen("clientserver.txt", "a");
    fprintf(dataFile, print_buf, buffer);
    fclose(dataFile);
    DebugLog(buffer);
}

void cMagLog::ReadSettings(char* settingsPath) {
    FILE* settingsFile = fopen(settingsPath, read_flag);
    if (settingsFile == NULL) {
        return;
    }
    char buffer[101] = {0};
    while (!feof(settingsFile)) {
        fgets(buffer, 99, settingsFile);
        char* settingName = strtok(buffer," :,");
        bool cmpRes = stricmp(settingName, "Log");
        if (cmpRes == 0) {
            char* settingVal = strtok(NULL," :");
            if (settingVal != NULL) {
                logEnabled = atoi(settingVal);
            }
        }
    }
    fclose(settingsFile);
}

void cMagLog::DebugLog(D3DXVECTOR3* vector) {
    return;
}