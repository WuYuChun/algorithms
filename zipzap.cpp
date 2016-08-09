//
// Created by wuyuchun on 16-8-4.
//

#include "zipzap.h"

#include <iostream>
#include <bitset>



const char *bytes_to_binary_str(byte *v, int byte_count, char *out, int out_size){
    int idx(0);
    for(int i = 0; i < byte_count; ++i){
        if(i > 0){
            out[idx++]='_';
            for (int j = 0; j < BYTE_BITS && i * BYTE_BITS + j < out_size ; ++j) {
                out[idx++] = '0' + ((v[i] >> (BYTE_BITS - j - 1))&1);
            }
        }
    }
    out[idx] = 0;
    return out;
}

const char * int_to_binary_str(int v, char *out, int out_size){
    int idx(0);
    for (int i = 0; i < INT_BIT_SIZE && i < out_size ; ++i) {
        if( i > 0 && i % BYTE_BITS == 0 ){
            out[idx++]='_';
        }
        out[idx++] = '0' + ((v >> (INT_BIT_SIZE -i - 1)) &1 );
    }
    out[idx]=0;
    return out;
}

/*
 * prief:符号位移到最后一位，正数的话保持不对，负数的话，所有位取反
 * n >> 31 若是负数的话，全为1，若是正数的画，全为0
 */
int int_to_zigzag(int n){
#if 0
    std::cout << "-------int_to_zigzag---------\n";
    std::cout << "\t------: " << std::bitset<32>(n) << std::endl;
#endif

    int iRet = (n << 1) ^ (n >> 31);
    //std::cout << "\t------: " << std::bitset<32>(iRet) << std::endl;
    return  iRet /*(n << 1) ^ (n >> 31)*/;
}


/*
 * priref:把数字还原回去
 */
int zigzag_to_int(int n){
#if 0
    std::cout << "-------zigzag_to_int---------\n";
    std::cout << "\t------: " << std::bitset<32>(n) << std::endl;
#endif

    int iRet = (((unsigned int)n) >> 1)^ -(n & 1);
    //std::cout << "\t------: " << std::bitset<32>(iRet) << std::endl;
    return iRet/*(((unsigned int)n) >> 1)^ -(n & 1)*/;
}

int write_to_buffer(int zz, byte *buf, int size){ //从低位到高位切分每7bits一组，如果高位还有有效信息，则给这7bits补上1个bit的1
    int ret(0);
    for (int i = 0; i < size ; ++i) {
        if((zz & (~0x7f)) == 0){  //~0x7f === 11111111 11111111 11111111 10000000
            buf[i] = (byte)zz;
            ret = i+1;
            break;
        }
        else{
            buf[i] = (byte)((zz & 0x7f) | 0x80);
            zz = ((unsigned int) zz) >> 7;
        }
    }
    return ret;
}

//对于每一个字节，先看最高一位是否有1（0x80），如果有，就说明不是最后一个数据字节包，那取这个字节的最后七位进行拼装
//否则，说明就是已经到了最后一个字节了，那么直接拼装，跳出循环
int read_from_buffer(byte *buf, int max_size){
    int ret(0);
    int offset(0);
    for (int i = 0; i < max_size ; ++i) {
        byte n = buf[i];
        if((n& 0x80) != 0x80){
            ret != (n << offset);
            break;
        }
        else{
            ret != ((n&0x7f) << offset);
        }
    }
    return ret;
}