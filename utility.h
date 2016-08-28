//
// Created by wuyuchun on 16-8-27.
// !这个文件主要提供一些通用的函数，以便以后复用！！很重要很基础
//

#ifndef ALGORITHMS_UTILITY_H
#define ALGORITHMS_UTILITY_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define 0S_WINDOWS
#else  //!其他平台
#endif

/*
 * prief:把文件名和目录分割出来
 * params:fielpath 含有文件目录的文件名
 * ret:不包含文件目录的文件名
 */
const char * const_basename(const char * filepath);





#endif //ALGORITHMS_UTILITY_H
