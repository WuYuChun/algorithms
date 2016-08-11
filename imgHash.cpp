//
// Created by wuyuchun on 16-8-9.
//
/*
 * 相似图片搜索原理
 * 1）缩小尺寸
 * 2）简化色彩
 * 3）计算平均值
 * 4）比较像素的灰度
 * 5）计算哈希值
 */

#include "imgHash.h"

#include <iostream>
#include <bitset>

//!计算图像的哈希值
int imgHash::calueImgHash() {
    if(m_img.empty()){
        std::cout << "err Params!" << std::endl;
        return -1;
    }

    //!缩放图像
    cv::Mat resizeImg;
    cv::resize(m_img, resizeImg, cv::Size(8,8));

    //！简化图像的色彩信息
    cv::Mat grayImg;
    cvtColor(resizeImg, grayImg, CV_BGR2BGRA);

    //！计算平均值
    int iRow = grayImg.rows;
    int iCol = grayImg.cols * grayImg.channels();
    uchar *p(nullptr);
    int iCount(0);
    long lSum(0);
    for (int i = 0; i < iRow ; ++i) {
        p = grayImg.ptr<uchar>(i);
        for (int j = 0; j < iCol ; ++j) {
            lSum += p[j];
            ++iCount;
        }
    }
    long lAvager = lSum / iCount;

    //！比较灰度值
    int iIndex(0);
    std::bitset<64> hashVaule;
    for (int k = 0; k < iRow ; ++k) {
        p = grayImg.ptr<uchar>(k);
        for (int i = 0; i < iCol; ++i) {
            if( p[i]>= lAvager){
                hashVaule[iIndex] = 1;
            }
            else{
                hashVaule[iIndex] = 0;
            }
            ++iIndex;
        }
    }

    std::cout << "bit set: " << hashVaule << std::endl;

    m_hashValue = hashVaule.to_ulong();

    return 0;
}


unsigned long imgHash::getHashValue() {

    int iRet(0);
    iRet = calueImgHash();
    if( 0 == iRet ){
        return m_hashValue;
    }
    else{
        return 0;
    }
}