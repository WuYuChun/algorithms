//
// Created by wuyuchun on 16-6-22.
//
//!贪心问题
#include <iostream>
#include "GreedyAlgo.h"

#include <streambuf>

//!总体解决思路
void GreadyAlgo( KNAPSACK_PROBLEM *problem, func spFunc )
{
    int idx = 0;
    int ntc = 0;

    //！每一次选最符合策略的那个物品，选中之后再进行检查
    while( (idx = spFunc( problem->objs, problem->totalc-ntc)) != -1 )
    {
        //!所选择的物品是否满足背包承重的要求
        if( (ntc + problem->objs[idx].weight) <= problem->totalc )
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

//!根据最重的进行选择
int Choosefunc1( std::vector<OBJECT> &objs, int c)
{
    int index = -1;
    int mp = 0;
    for (int i = 0; i < static_cast<int>(objs.size()); ++i)
    {
        if( ( 0 == objs[i].status ) && ( objs[i].weight >= mp ) )
        {
            mp = objs[i].weight;
            index = i;
        }
    }
    return index;
}

//!根据价格最高的进行选择
int Choosefunc2( std::vector<OBJECT> &objs, int c)
{
    int index(-1);
    int mp(0);
    for (int i = 0; i < static_cast<int >(objs.size()) ; ++i) {
        if( (0 == objs[i].status) && ( objs[i].price >= mp) ){
            mp = objs[i].price;
            index = i;
        }
    }
    return index;
}

//!根据性价比最高的进行选择
int Choosefunc3( std::vector<OBJECT> &objs, int c)
{
    int index(-1);
    float mp(0.0);
    for (auto i = 0; i < objs.size(); ++i) {
        float wp = (float)objs[i].price / objs[i].weight;
        if( (0 == objs[i].status) && (wp >= mp) ){
            mp = wp;
            index = i;
        }
    }
    return index;
}

void printResult(std::vector<OBJECT> &objs)
{
    int totalWeight(0);
    for (int i = 0; i < static_cast<int>(objs.size()); ++i)
    {
        if( 1 == objs[i].status )
        {
            totalWeight += objs[i].weight;
            std::cout << "重量：" << objs[i].weight << "  价格：" << objs[i].price << std::endl;
        }
    }
    std::cout << "总的重量：" << totalWeight << std::endl;
}


void calcDicePro(){
    enum{ SIDES = 6};
    double sumDice[13]={0};
    for(int i = 1; i <= 6; ++i){
        for(int j = 1; j <= 6; ++j){
            sumDice[i+j]+=1.0;
        }
    }

    for(int i = 2; i <= 12; ++i){
        sumDice[i] /= 36.0 ;
        std::cout << sumDice[i]*100 << "% ";
    }
}


//!编写自定义的streambuf用于自己的输出
std::streambuf::int_type outbuf::overflow(int_type c) {
    if(c!= EOF){
        c = std::toupper(c);
        if(std::putchar(c) == EOF){
            return EOF;
        }
    }
    return c;
}

