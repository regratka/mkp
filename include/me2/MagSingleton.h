#ifndef MAG_SINGLETON
#define MAG_SINGLETON

#include <globals.h>

template <typename T>
class MagSingleton {
public:
    static T& getInstance() {
        return instance;
    }
protected:
    MagSingleton(T* inst) {
        instance = inst;
    }
    ~MagSingleton() {
        instance = NULL;
    }


private: 
    static T* instance;
};

#endif