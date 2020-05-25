//
// Created by wangxy on 2020/5/24.
//
#include <iostream>
#include <string>

using namespace std;

class basedata {

public:
    basedata()=default;

    virtual ~basedata() = default;
    basedata *next,*prev;
    virtual void show()=0;
private:
};

template<typename T>
class data : public basedata{

public:
    data(T da) :value(da){ prev= nullptr;next= nullptr; };

    ~data() = default;
    void show() override {
        cout<<value<<endl;
    }

private:
    T value;
};
int main(){
    basedata * a=new data<float>(3.14);
    basedata *b=new data<int>(3);
    a->next=b;
    b->next=a;
    a->next->show();
    b->next->show();
}