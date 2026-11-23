#ifndef _C_MIN_MAX
#define _C_MIN_MAX

template <typename T>   
class CMinMax {
public:
    T min;
    T max;

    CMinMax(T minVal, T maxVal) {
        min = minVal;
        max = maxVal;
    }

    ~CMinMax(){}
};

#endif