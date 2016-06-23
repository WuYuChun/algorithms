//
// Created by wuyuchun on 16-6-22.
//
//!贪心问题
#include <iostream>
#include "GreedyAlgo.h"

//!总体解决思路
void GreedyAlgo( KNAPSACK_PROBLEM *problem, func spFunc )
{
    int idx = 0;
    int ntc = 0;

    //！每一次选最符合策略的那个物品，选中之后再进行检查
    while( (idx = spFunc( problem->objs, problem->totalC-ntc)) != -1 )
    {
        //!所选择的物品是否满足背包承重的要求
        if( (ntc + problem->objs[idx].weight) <= problem->totalC )
        {
            problem->objs[idx].status = 1;
            ntc += problem->objs[idx].weight;
        }
        else
        {
            //!不能再次选择该物品
            problem->objs[idx].status = 2;
        }
    }

    printResult( problem->objs);
}

//!根据最重的策略进行选择
int Choosefunc1( std::vector<OBJECT> &objs, int c)
{
    int index = -1;
    int mp = 0;
    for (int i = 0; i < static_cast<int>(objs.size()); ++i)
    {
        mp = objs[i].price;
        index = i;
    }
    return index;
}

//!第二种策略
int Choosefunc2( std::vector<OBJECT> &objs, int c)
{
    return 0;
}

//!第三种策略
int Choosefunc3( std::vector<OBJECT> &objs, int c)
{
    return 0;
}

void printResult(std::vector<OBJECT> &objs)
{
    for (int i = 0; i < static_cast<int>(objs.size()); ++i)
    {
        if( 1 == objs[i].status )
        {
            std::cout << "重量：" << objs[i].weight << "  价格：" << objs[i].price << std::endl;
        }
    }
}