//
// Created by wuyuchun on 16-6-22.
//
//!测试文件

#include "unit_test.h"

#include <cstdlib>
#include <iostream>

#include "GreedyAlgo.h"

//！测试三种策略策略时候的场景
void testFunc1()
{
    KNAPSACK_PROBLEM problem;
    OBJECT obj1(35,10,0), obj2(30,40,0), obj3(60,30,0), obj4(50,50,0),
           obj5(40,35,0), obj6(10,40,0), obj7(25,30,0);
    problem.totalc = 150;
    problem.objs.push_back(obj1);
    problem.objs.push_back(obj2);
    problem.objs.push_back(obj3);
    problem.objs.push_back(obj4);
    problem.objs.push_back(obj5);
    problem.objs.push_back(obj6);
    problem.objs.push_back(obj7);
    std::cout << "------------------------第一种情况---------------------------" << std::endl;
    GreadyAlgo(&problem, Choosefunc1);
    std::cout << "------------------------第二种情况---------------------------" << std::endl;
    for (int i = 0; i < problem.objs.size(); ++i) { //初始化
        problem.objs[i].status = 0;
    }
    GreadyAlgo(&problem, Choosefunc2);
    std::cout << "------------------------第三种情况---------------------------" << std::endl;
    for (int i = 0; i < problem.objs.size(); ++i) { //初始化
        problem.objs[i].status = 0;
    }
    GreadyAlgo(&problem, Choosefunc3);
}


void testFunc3(){
    union {
        float f;
        unsigned int u;
    } p;

    p.f = -13.0;
    unsigned int sign = (p.u >> 31) & 1;
    unsigned int exp = (p.u >> 23) & 0xff;

    unsigned int coef_mask = (1 << 23) -1;
    unsigned int coef = p.u & coef_mask;

    std::cout << "sign: " << sign << "\nexp:" << exp << "\ncoef: " << coef << std::endl;
}

double get_seconds(){
    struct timespec ts;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}
