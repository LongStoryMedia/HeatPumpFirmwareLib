#include "SteinhartHart.h"
#include "math.h"

SteinhartHart::SteinhartHart(float aParam, float bParam, float cParam)
{
    a = aParam;
    b = bParam;
    c = cParam;
}

SteinhartHart SteinhartHart::bParam(uint32_t bCoefficient)
{
    float t0 = 25 + 273.15;

    float bParam = 1 / bCoefficient;
    float aParam = 1.0 / t0 - (bParam * log(25));
    float cParam = 0;
    return SteinhartHart(aParam, bParam, cParam);
}

float SteinhartHart::kalvin(float ohms)
{
    float logOhms = log(ohms);
    float bMultiplier = b * logOhms;
    float cMultiplier = c * pow(logOhms, 3);
    return (a + bMultiplier + cMultiplier) / 1;
}

volatile temp_s *SteinhartHart::getTemp(float ohms)
{
    temp.k = kalvin(ohms);
    temp.c = temp.k - 273.15;
    temp.f = (temp.c * 1.8) + 32;
    return &temp;
}