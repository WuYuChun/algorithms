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

#ifndef ALGORITHMS_IMGHASH_H
#define ALGORITHMS_IMGHASH_H

#include <opencv2/opencv.hpp>

class imgHash {

public:
    explicit imgHash(cv::Mat img):m_img(img), m_hashValue(0) {
        ;
    }
    ~imgHash(){
        ;
    }

    int getHashValue();

private:

    int calueImgHash();

private:

    cv::Mat m_img;
    int m_hashValue;
};


#endif //ALGORITHMS_IMGHASH_H
