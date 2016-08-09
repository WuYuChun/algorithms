//
// Created by wuyuchun on 16-8-4.
//
// 这个是小巧的数字压缩算法

#ifndef ALGORITHMS_ZIPZAP_H
#define ALGORITHMS_ZIPZAP_H

typedef unsigned char byte;
const int BYTE_BITS=8;
const int INT_BIT_SIZE= sizeof(int)*BYTE_BITS;

const char *bytes_to_binary_str(byte *v, int byte_count, char *out, int out_size);

const char *int_to_binary_str(int v, char *out, int out_size);

int zigzag_to_int(int n);

int int_to_zigzag(int n);

int write_to_buffer(int zz, byte *buf, int size);

int read_from_buffer(byte *buf, int max_size);


#endif //ALGORITHMS_ZIPZAP_H
