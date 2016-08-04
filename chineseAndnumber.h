#ifndef CHINESEANDNUMBER_H_
#define CHINESEANDNUMBER_H_

//用于阿拉伯数字与中文数字之间的转换，注意这里的算法实现

#include <string>

void SectionToChinese(unsigned int section, std::string &chnStr);
void NumberToChinese(unsigned int num, std::string &chnStr);

unsigned int ChinsesToNumber(const std::string & chnString);


#endif
