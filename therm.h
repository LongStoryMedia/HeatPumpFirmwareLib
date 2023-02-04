#ifndef LIB_THERM
#define LIB_THERM

#include <stdint.h>

struct temp_s
{
    uint32_t c;
    uint32_t f;
    uint32_t k;
};

struct therm_s
{
    volatile temp_s *outside;
    volatile temp_s *tank;
};

#endif