//
// Created by wuyuchun on 16-6-22.
//
//!贪心算法 0-1背包问题

#ifndef ALGORITHMS_GREEDYALGO_H
#define ALGORITHMS_GREEDYALGO_H

#include <vector>
#include <streambuf>


//！表示物品
typedef struct tagObject
{
    int weight;
    int price;
    int status; //0 未选中， 1 已选中 2 已经不能选（表示若选中的话将超出重量）
    tagObject(int iweight, int iprice, int istatus):weight(iweight),price(iprice),status(istatus){
    }
}OBJECT;

//！表示背包
typedef struct tagKnapsackProblem
{
    std::vector<OBJECT> objs;
    int totalc;
}KNAPSACK_PROBLEM;

//!表示策略 定义为函数指针
typedef int (*func)( std::vector<OBJECT> &objs, int c);

void GreadyAlgo( KNAPSACK_PROBLEM *problem, func spFunc);

//！第一种策略，每一次选择最重的物品
int Choosefunc1( std::vector<OBJECT> &objs, int c);

//!第二种策略，每一次选择最贵的物品
int Choosefunc2( std::vector<OBJECT> &objs, int c);

//!第三种策略，每一次选择价值密度最大的物品
int Choosefunc3( std::vector<OBJECT> &objs, int c);

//!打印出所选中的物品
void printResult(std::vector<OBJECT> &);


//!计算两个色子之和的概率分布
void calcDicePro();

//!自定义缓冲区类 streambuf
class outbuf:public std::streambuf{
protected:
    virtual int_type overflow(int_type c);
};

#endif //ALGORITHMS_GREEDYALGO_H
