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