//
// Created by wuyuchun on 16-6-22.
//
//!测试文件

#include "unit_test.h"

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <opencv2/opencv.hpp>

#include "GreedyAlgo.h"
#include "chineseAndnumber.h"
#include "zipzap.h"
#include "imgHash.h"

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


void testFunc2(){

    int number(10000000);
    std::string chineseNumber;
    NumberToChinese(number, chineseNumber);
    std::cout << "中文数字： " << chineseNumber << std::endl;
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

void testFunc4(){

#if 0
    int zz = int_to_zigzag(-1);
    int rr = zigzag_to_int(zz);
#endif

    int a[]={(int)(-pow(2L,32)),-1000, -1, 0, 1, 1000, (int)(pow(2L,31)-1L)};
    for (int i = 0; i < sizeof(a) / sizeof(int) ; ++i) {
        int n = a[i];
        char str[INT_BIT_SIZE+INT_BIT_SIZE/BYTE_BITS+1];
        int_to_binary_str(n,str,sizeof(str));

        int zz = int_to_zigzag(n);
        char str_zz[INT_BIT_SIZE+INT_BIT_SIZE/BYTE_BITS+1];
        int_to_binary_str(zz,str_zz,sizeof(str_zz));

        byte write_buffer[5];
        int to_write_size = write_to_buffer(zz,write_buffer,sizeof(write_buffer));
        char str_write[to_write_size * BYTE_BITS+ to_write_size +1];
        bytes_to_binary_str(write_buffer,to_write_size,str_write, sizeof(str_write));

        int read_num = read_from_buffer(write_buffer,to_write_size);

        int last_num =zigzag_to_int(read_num);

        printf("%11d [%s] ==to-zigzag==>  %6d [%s]  ====to-buf===>    %s\n",n,str,zz,str_zz,str_write);
    }

}

//！计算图像的相似度
void testFunc5(){

    cv::Mat img = cv::imread("../image/1.jpg");
    if( img.empty() ){
        std::cout << "open img Err!" << std::endl;
    }

    imgHash test(img);
    long lRet(0);
    lRet = test.getHashValue();

    std::cout << "img Hash Value: " << lRet << std::endl;

}
