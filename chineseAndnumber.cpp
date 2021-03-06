#include "chineseAndnumber.h"

const char *chnNumChar[]={"零","一","二","三","四","五","六","七","八","九",};
const char *chnUnitSection[]={"","万","亿","万亿"};
const char *chnUnitChar[]={"","十","百","千"};


typedef struct{
    const char *name; //中文权位名称
    int value; //10的倍数
    bool secUnit; //是否是节权位
}CHN_NAME_VALUE;

CHN_NAME_VALUE chnValuePair[]={
        {"十",10,false},{"百",100,false},{"千",1000,false},{"万",10000,true},{"亿",100000000,true}
};


//0==num 需要特殊处理，直接返回零
void NumberToChinese(unsigned int num, std::string &chnStr){
    int unitPos(0);
    std::string strIns;
    bool needZero(false);

    while(num > 0){
        unsigned int section = num % 10000;
        if(needZero){
            chnStr.insert(0, chnNumChar[0]);
        }
        SectionToChinese(section,strIns);
        //是否需要节权位
        strIns += (section != 0) ? chnUnitSection[unitPos]:chnUnitSection[0];
        chnStr.insert(0,strIns);
        //千位是0，需要在下一个section补零
        needZero = (section < 1000)&&(section > 0);
        num /= 10000;
        unitPos++;
    }
}

void SectionToChinese(unsigned int section, std::string &chnStr){
    std::string strIns;
    int unitPos(0);
    bool zero(true);
    while(section > 0 ){
        int v = section % 10;
        if( 0 == v ){
            if( (0 == section )|| !zero){
                zero = true; //需要补，zero的作用就是确保对连续的多个，只补一个零
                chnStr.insert(0,chnNumChar[v]);
            }
        }
        else{
            zero = false; //至少有一个数字不是
            strIns = chnNumChar[v]; //此处对应的中文数字
            strIns += chnUnitChar[unitPos]; //此处对应的中文权位
            chnStr.insert(0,strIns);
        }
        ++unitPos;
        section /= 10;
    }
}


unsigned int ChinesToNumber( const std::string &chnString){
    unsigned int rtn(0);
    unsigned int section(0);
    int number(0);
    bool secUnit(false);
    std::string::size_type pos(0);

    while( pos < chnString.length()){
        ; //待实现
    }
    return 1;
}
