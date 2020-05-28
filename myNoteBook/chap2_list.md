# 链表
```c
typedef struct listNode{
    struct listNode *prev,*next;
    void *value;
};

typedef struct list{
    listNode *head ,*tail;
    void (*free)(void *ptr);//释放节点保存值，函数指针
    void *(*dup)(void *ptr);//复制节点值
    int (*match)(void *prt,void *value);//比较节点大小
    
};
```
## C++编程相关
### 1、使用模板类
- prev、next指针因为模板类实例不同导致的无法使用
    - 使用基类和派生类解决
- 释放和创建函数直接使用delete函数解决
- 判断直接使用类型自带的函数