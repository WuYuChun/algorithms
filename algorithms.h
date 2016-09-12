/*这个用于练习算法（第四版）
 *
 *by wuyuchun
 *date:2016-09-05
 *
 */

#ifndef ALGORITHMS
#define ALGORITHMS

#include<string>
#include<vector>

class Evaluate{

public:
    Evaluate();
    ~Evaluate();
    int inputExpression(std::string expression);
    int getResult();
private:
    std::vector<std::string> m_ops;
    std::vector<double> m_vals;
};

/*
 * @prief 用于在字符串中移动一个字符
 * @params word 需要移动的字符串  n 字符串的长度
 *
 */
void leftOneShift(char *word, int n);

/*
 * @pried 用于移动字符串中的多个字符，并把前面的字符串放在后面
 * @params word 需要移动的字符串， n 字符串的长度， m 移动的个数
 *
 */
void ratorWord(char *word, int n, int m);

#endif
