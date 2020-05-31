//
// Created by wangxy on 2020/5/27.
//

#ifndef TINYREDIS_ADLIST_H
#define TINYREDIS_ADLIST_H

#include <iostream>

using namespace std;

class baseNode {

public:
    baseNode();

    virtual ~baseNode() = default;

    virtual baseNode *listPrevNode() = 0;

    virtual baseNode *listNextNode() = 0;

    virtual void setPrevNode(baseNode *newPrevNode) = 0;

    virtual void setNextNode(baseNode *newNextNode) = 0;

    virtual void insertAfter(baseNode *node) = 0;

    virtual void insertPrev(baseNode *node) = 0;


protected:
    baseNode *prev, *next;
};

template<typename T>
class listNode : public baseNode {
public:
    listNode() : baseNode() {};

    explicit listNode(T val);

    ~listNode() override = default;

    //return prev or next node
    baseNode *listPrevNode() override;

    baseNode *listNextNode() override;

    //set next or prev node
    void setNextNode(baseNode *newNextNode) override;

    void setPrevNode(baseNode *newPrevNode) override;

    T getValue() override;

    T listNodeValue();

    void setValue(T val);

    //insert node
    void insertAfter(baseNode *node) override;

    void insertPrev(baseNode *node) override;

    //copy function
    listNode(const listNode &node);

    listNode operator=(const listNode &node) = delete;

    //compare function
    bool operator>(const listNode &node) const;

    bool operator==(const listNode &node) const;

    bool operator<(const listNode &node) const;

private:
    T value;
};


template<typename T>
class list {

public:
    list();

    ~list();

    void listAddHeadNode(baseNode *node);

    void listAddTailNode(baseNode *node);

    void listAddTailNode(T value);

    void listAddHeadNode(T value);

    int listLength();

    void listInsertNode(baseNode *destNode, baseNode *insertNode, bool after);

    baseNode *listFirst();

    baseNode *listLast();

    //search function
    baseNode *listSearchKey(T key) const;

    //del node 1=success 0=failed
    int listDelNode(baseNode *node);

    //copy function
    list* listDup(const list &duplist) ;

    list(const list& duplist);

private:
    //check node whether in the list
    baseNode *checkNode(baseNode *node);

    baseNode *head{}, *tail{};
    int length;
};


#endif //TINYREDIS_ADLIST_H
