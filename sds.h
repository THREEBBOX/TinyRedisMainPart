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
    sdshr() = delete;

    explicit sdshr(int length);//initial empty_buf sdshr

    sdshr(int length, string content);//initial buf with existing content

    explicit sdshr(string content);//initial buf with content;

    int sdsavail() const;//获得可用长度

    int sdslen() const;//获得已经使用字节数

    void sdsfree();//释放数据

    void sdsclear();//清空数据

    sdshr* sdsdup(const sdshr& sds);//创建副本

    ~sdshr();

private:
    void empty_buf();

    int len;//the length of the buf
    char *buf;
    int free;//unused memory

};


#endif //TINYREDIS_SDS_H
