/*算法的实现文件
 *
 *
 *
 *
 */

#include "algorithms.h"

Evaluate::Evaluate(){
    ;
}

Evaluate::~Evaluate(){
    ;
}

/*
 *
 */
int Evaluate::inputExpression(std::string expression){
    //!参数校验
    //

    //！若是运算符，则压入栈
    //

    //若是“”）” 弹出运算符号和操作数，计算结果并压入栈
    return 0;
}
/*
 *
 *
 */
int Evaluate::getResult(){
    ;
}


void leftOneShift(char *word, int n){
    if(nullptr == word){
        return;
    }
    char a = word[0];
    for (int i = 1; i < n; ++i) {
        word[i-1] = word[i];
    }
    word[n-1] = a;
}

void ratorWord(char *word, int n, int m){
    if(nullptr == word ){
        return;
    }
    while(m--){
        leftOneShift(word,n);
    }
}