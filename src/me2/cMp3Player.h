#include <Dshow.h>

class cMp3Player {

public:
    cMp3Player();
    virtual ~cMp3Player();

    void Cleanup();
    void Load(char* path);
    bool boCompleted();
    void Pause();
    void Stop();
    void SetVolume(float);
    void Rewind();
    void Play();

private:
    IUnknown*  unknown;
    IGraphBuilder* graphBuilder;
    IMediaControl* mediaControl;
    IMediaEventEx* mediaEventExt;
    bool loaded;
};

