#include <d3dx8math.h>

class cMagLog {
public:
    cMagLog();
    void DeleteLog();
    void DataLog(char const * format, ...);
    void CrashLog(char const * format, ...);
    void TextureErrorLog(char const * format, ...);
    void ClientServerLog(char const * format, ...);
    void TexturesLog(char const * format, ...);
    void FileLog(char const * format, ...);
    void DummyLog(char const * format, ...);
    void DebugLog(char const * format, ...);
    void DebugLog(D3DXVECTOR3* vector);
    void DebugLog(D3DXMATRIX matrix);

    void ReadSettings(char* settingsPath);

private:
    bool logEnabled;
    char* logFilename;
};