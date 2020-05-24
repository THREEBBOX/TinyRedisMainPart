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