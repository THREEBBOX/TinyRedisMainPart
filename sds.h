//
// Created by wangxy on 2020/5/23.
//

#ifndef TINYREDIS_SDS_H
#define TINYREDIS_SDS_H

#include <iostream>
#include <string>s

using namespace std;

class sdshr {

public:
    sdshr() = delete;

    explicit sdshr(int length);

    sdshr(int length, string content);

    explicit sdshr(string content);

    int length() const;

    int print() const;

    int unused()const;

    ~sdshr() = default;

private:
    int len;//the length of the buf
    char *buf;
    int free;//unused memory

};

sdshr::sdshr(int length) : len(length) {
    buf = new char[length + 1];
    buf[0] = '\0';
    free = len;
}

sdshr::sdshr(string content) {
    len = content.length();
    buf = new char[len + 1];
    strcpy(string)
}


#endif //TINYREDIS_SDS_H
