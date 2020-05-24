//
// Created by wangxy on 2020/5/23.
//

#ifndef TINYREDIS_SDS_H
#define TINYREDIS_SDS_H

#include <iostream>
#include <string>
#include <ostream>

using namespace std;

class sdshr {
    friend ostream &operator<<(ostream &os, const sdshr &sds);

public:
    sdshr() : sdshr(10) {};//default length 10；

    explicit sdshr(int length);//initial empty_buf sdshr

    sdshr(int length, string content);//initial buf with existing content

    explicit sdshr(string content);//initial buf with content;

    sdshr(const sdshr &sds);//拷贝构造函数

    int sdsavail() const;//获得可用长度

    inline int sdslen() const;//获得已经使用字节数

    void sdsfree();//释放数据

    void sdsclear();//清空数据

    sdshr sdsdup(const sdshr &sds);//创建副本

    void sdscat(const string &s);//拷贝、拼接

    bool operator==(const sdshr &rsd);

    bool sdscmp(const sdshr &rsd);

    void sdscpy(const string &s);//复制

    void printLog();

    ~sdshr();

private:
    void empty_buf();

    bool check_free(const string &s);

    void concatBuf(const string &s);

    void expand_buf(const size_t &size);//扩张buf，不包括\0位置

    int cal_length(int need);//判断最终长度

    int len;//the length of the buf
    char *buf;
    int free;//unused memory

};


#endif //TINYREDIS_SDS_H
