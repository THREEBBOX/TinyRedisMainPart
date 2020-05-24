#include <iostream>
#include "sds.h"
#include <string>
using namespace std;
#define LOGPRINT 1

int main() {
    sdshr a("shit");
    cout<<a<<endl;
    a.sdscpy("nimamasilema");
    a.printLog();
    a.sdscat("ni ma shi bu shi zhen de si le");
    a.printLog();
    printf("%d",)
    return 0;
}

