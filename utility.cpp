//
// Created by wuyuchun on 16-8-27.
//

#include <cstring>
#include "utility.h"


const char * const_basename(const char *filepath){
    const char *base = strrchr(filepath,'/');
#ifdef OS_WINDOWS
    if(!base){
        base = strrchr(filepath,"\\");
    }
#endif
    return base ? (base+1):filepath;
}

float FastInvSqrt(float x){
    float xhalf = 0.5f * x;
    int i = *(int *)&x;
    i = 0x5f3759df - ( i >> 1); //什么鬼？
    x = *(float *)&i;
    x = x*(1.5f-(xhalf*x*x));
    return x;
}