#ifndef LIB_CONFIG
#define LIB_CONFIG

#include <stdint.h>

enum temp_scale_e
{
    celcius,
    fahrenheit,
    kalvin
};

struct config_s
{
    int32_t setPoint;
    int32_t tempDifferential;
    int32_t aParam;
    int32_t bParam;
    int32_t cParam;
    temp_scale_e scale = temp_scale_e::celcius;
};

#endif