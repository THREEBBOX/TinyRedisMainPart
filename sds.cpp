//
// Created by wangxy on 2020/5/23.
//

#include "sds.h"
#include <iostream>

using namespace std;

sdshr::sdshr(int length) : len(length) {
    buf = new char[length + 1];
    buf[0] = '\0';
    free = len;
}

sdshr::sdshr(string content) {
    len = content.length();
    buf = new char[len + 1];
    strcpy(buf, content.c_str());
    free = 0;
}

ostream &operator<<(ostream &os, const sdshr &sds) {
    os << sds.buf;
    return os;
}

void sdshr::empty_buf() {
    buf[0] = '\0';
}
/**
 * 释放空间
 */
void sdshr::sdsfree() {
    delete [] buf;
    len=0;
    free=0;
}
/**
 * 使用字节数
 * @return
 */
int sdshr::sdslen() const {
    return len - free;
}

sdshr::~sdshr() {
    delete [] buf;
}
/**
 * 清空但不释放空间
 */
void sdshr::sdsclear() {
    buf[0]='\0';
    free=len;
}


