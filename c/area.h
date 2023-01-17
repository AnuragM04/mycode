#include <stdio.h>

float square(float x)
{
    float ar_sq = 0;
    ar_sq = x*x;
    return ar_sq;
}

float rectangle(float x, float y)
{
    float ar_rect = 0;
    ar_rect = x*y;
    return ar_rect;
}

float triangle(float x, float y)
{   
    float ar_tri = 0;
    ar_tri = (x*y) / 2;
    return ar_tri;
}

