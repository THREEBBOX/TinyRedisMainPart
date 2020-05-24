//
// Created by wangxy on 2020/5/23.
//

#include "sds.h"
#include <iostream>

using namespace std;
#define MAX_LENGTH 1024
//#define LOGPRINT
//空间预分配策略边界
#ifdef MAX_LENGTH
static const int maxlength = MAX_LENGTH;
#else
static const int maxlength=1024;
#endif


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
    delete[] buf;
    len = 0;
    free = 0;
}

/**
 * 使用字节数
 * @return
 */
inline int sdshr::sdslen() const {
    return len - free;
}

sdshr::~sdshr() {
    delete[] buf;
}

/**
 * 清空但不释放空间
 */
void sdshr::sdsclear() {
    buf[0] = '\0';
    free = len;
}

/**
 * 深拷贝
 * @param sds
 * @return
 */
sdshr sdshr::sdsdup(const sdshr &sds) {
    sdshr nsds(sds);
    return nsds;
}

/**
 * 拷贝构造函数
 * @param sds
 */
sdshr::sdshr(const sdshr &sds) {
    this->len = sds.len;
    this->free = sds.free;
    buf = new char[len + 1];
    strcpy(buf, sds.buf);
}
/**
 * 判断空间是否足够
 * @param s
 * @return
 */
bool sdshr::check_free(const string &s) {
    return (s.length() > free);
}

/**
 * 拼接
 * @param s
 */
void sdshr::sdscat(const string &s) {
    bool isEnough = check_free(s);
    int curLen = sdslen();
    int needLen = curLen + s.length();
    if (free < s.length()) {
        int expandLength = cal_length(needLen);

        expand_buf(expandLength);
    }
    concatBuf(s);
}
/**
 * 拼接过程中针对buf的操作
 * @param s
 */
void sdshr::concatBuf(const string &s) {
    int start = sdslen();
    void *t = (void *) s.c_str();
//    strcat(buf,s.c_str());
    memcpy(buf + start, t, s.length());
    free -= s.length();
}
/**
 * 扩张buf至size大小
 * @param size
 */
void sdshr::expand_buf(const size_t &size) {
#ifdef LOGPRINT
    cout<<"expand buf size to "<<size<<endl;
    cout<<"the cur len "<<sdslen()<<endl;
#else
#endif
    try {
        char *newbuf = new char[size + 1];
        memcpy(newbuf, (void *) buf, sdslen());
        newbuf[sdslen()] = '\0';
        free += size - len;
        len = size;
        delete[] buf;
        buf = newbuf;
#ifdef LOGPRINT
        cout<<"expand buf to "<<len<<" the free is "<<free<<endl;
        cout<<"current content is "<<buf<<endl;
#else

#endif
    } catch (exception e) {
        e.what();
    }

    free += size - len;
    len = size;
}

/**
 * 返回剩余大小
 * @return
 */
int sdshr::sdsavail() const {
    return free;
}

bool sdshr::operator==(const sdshr &rsd) {
    return strcmp(buf, rsd.buf);
}
/**
 * compare function
 * @param rsd
 * @return
 */
bool sdshr::sdscmp(const sdshr &rsd) {
    return *this == rsd;
}
/**
 * copy function
 * @param s
 */
void sdshr::sdscpy(const string &s) {
    if (s.length() > len) {
        int need = cal_length(s.length());
        expand_buf(need);
    }
    strcpy(buf, s.c_str());
    free = len - s.length();
}

void sdshr::printLog() {
    cout << "the content is " << buf << endl;
    cout << "the free is " << free << endl;
    cout << "the length is " << len << endl;
}

/*
 * 计算扩张长度
 */
int sdshr::cal_length(int need) {
    int expand = len;
    while (expand <= need) {
        if (expand > maxlength)
            expand += maxlength;
        else
            expand *= 2;
    }
    return expand;
}




