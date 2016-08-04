#ifndef CHINESEANDNUMBER_H_
#define CHINESEANDNUMBER_H_

//用于阿拉伯数字与中文数字之间的转换，注意这里的算法实现

#include <string>

const char *chnNumChar[]={"零","一","二","三","四","五","六","七","八","九",};
const char *chnUnitSection[]={"","万","亿","万亿"};
const char *chnUnitChar[]={"","十","百","千"};

void SectionToChinese(unsigned int section, std::string &chnStr);
void NumberToChinese(unsigned int num, std::string &chnStr);


typedef struct{
    const char *name; //中文权位名称
    int value; //10的倍数
    bool secUnit; //是否是节权位
}CHN_NAME_VALUE;

CHN_NAME_VALUE chnValuePair[]={
    {"十",10,false},{"百",100,false},{"千",1000,false},{"万",10000,true},{"亿",100000000,true}
};

unsigned int ChinsesToNumber(const std::string & chnString);


#endif
