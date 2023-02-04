#ifndef _LIB_STEINHARTHART
#define _LIB_STEINHARTHART

#include "therm.h"

class SteinhartHart
{
private:
    float a;
    float b;
    float c;
    float kalvin(float ohms);
    volatile temp_s temp;

public:
    SteinhartHart(float aParam, float bParam, float cParam);
    static SteinhartHart bParam(uint32_t bCoefficient);

    volatile temp_s *getTemp(float ohms);
};

#endif