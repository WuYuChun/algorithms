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


//!用于翻转字符串
void ReverseString(char *s, int from, int to){
    while(from<to){
        char t = s[from];
        s[from++]=s[to];
        s[to--]=t;
    }
}

void LeftRotateString(char *s, int n, int m){
    //若是左移动大于n位，那么%n是等价的
    m %= n;
    ReverseString(s,0,m-1);
    ReverseString(s,m,n-1);
    ReverseString(s,0,n-1);
}

//!用于字符串包含的问题
bool StringContain(std::string &a, std::string &b){
    for(int i =0; i < b.length(), ++i){
        int j(0);
        for(;j<a.length() && (a[j] != b[i]); ++j){
            ;
        }
        if(j >= a.length()){
            return false;
        }
    }
    return true;
}
