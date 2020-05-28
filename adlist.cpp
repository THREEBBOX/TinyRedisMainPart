//
// Created by wangxy on 2020/5/27.
//

#include "adlist.h"

/**
 * 构造函数，防止悬浮指针
 */
baseNode::baseNode() {
    prev = nullptr;
    next = nullptr;
}

template<typename T>
listNode<T>::listNode(T val):value(val), baseNode() {
    //nothing
}

template<typename T>
baseNode *listNode<T>::listPrevNode() {
    return prev;
}

template<typename T>
baseNode *listNode<T>::listNextNode() {
    return next;
}

template<typename T>
T listNode<T>::getValue() {
    return value;
}

template<typename T>
void listNode<T>::setValue(T val) {
    value = val;
}

template<typename T>
void listNode<T>::setNextNode(baseNode *newNextNode) {
    next = newNextNode;
}

template<typename T>
void listNode<T>::setPrevNode(baseNode *newPrevNode) {
    prev = newPrevNode;
}

template<typename T>
T listNode<T>::listNodeValue() {
    return getValue();
}

template<typename T>
void listNode<T>::insertAfter(baseNode *node) {
    node->setNextNode(next);
    node->setPrevNode(this);
    if (next != nullptr)
        next->setPrevNode(node);
    next = node;
}

template<typename T>
void listNode<T>::insertPrev(baseNode *node) {
    node->setPrevNode(prev);
    node->setNextNode(this);
    if (prev != nullptr)
        prev->setNextNode(node);
    prev = node;
}

template<typename T>
listNode<T>::listNode(const listNode &node) {
    value = node.value;
    prev = next = nullptr;
}

template<typename T>
bool listNode<T>::operator>(const listNode &node) const {
    return (this->value > node.value);
}

template<typename T>
bool listNode<T>::operator==(const listNode &node) const {
    return (this->value == node.value);
}

template<typename T>
bool listNode<T>::operator<(const listNode &node) const {
    return (this->value < node.value);
}


/**
 * 构造函数，替换listCreate
 */
template<typename T>
list<T>::list() {
    head = tail = nullptr;
    length = 0;
}

template<typename T>
void list<T>::listAddHeadNode(baseNode *node) {
    if (head != nullptr)
        head->setPrevNode(node);
    else
        tail = node;
    node->setNextNode(head);
    head = node;
    node->setPrevNode(nullptr);
    length++;
}

template<typename T>
void list<T>::listAddTailNode(baseNode *node) {
    if (tail != nullptr)
        tail->setNextNode(node);
    else
        head = node;
    node->setPrevNode(tail);
    node->setNextNode(nullptr);
    tail = node;
    length++;
}

template<typename T>
void list<T>::listAddTailNode(T value) {
    baseNode *p = new listNode<T>(value);
    listAddTailNode(p);
}

template<typename T>
void list<T>::listAddHeadNode(T value) {
    baseNode *p = new listNode<T>(value);
    listAddHeadNode(p);
}

/**
 * list release
 * @tparam T
 */
template<typename T>
list<T>::~list() {
    while (head != nullptr) {
        tail = head;
        head = head->listNextNode();
        delete tail;
    }
}

template<typename T>
int list<T>::listLength() {
    return length;
}

template<typename T>
baseNode *list<T>::listFirst() {
    return head;
}

template<typename T>
baseNode *list<T>::listLast() {
    return tail;
}

/**
 * 插入函数
 * @param destNode 目标节点
 * @param insertNode  操作节点
 * @param after 是否插入后侧
 */
template<typename T>
void list<T>::listInsertNode(baseNode *destNode, baseNode *insertNode, bool after) {
    if (after)
        destNode->insertAfter(insertNode);
    else
        destNode->insertPrev(insertNode);
}

template<typename T>
baseNode *list<T>::listSearchKey(T key) const {
    baseNode *tmp = head;
    while (tmp != nullptr) {
        dynamic_cast<listNode<T> *>(tmp)->getValue() == key;
        return tmp;
    }
    return nullptr;
}

template<typename T>
baseNode *list<T>::checkNode(baseNode *node) {
    for (baseNode *tmp = head; tmp != nullptr; tmp = tmp->listNextNode())
        if (tmp == node) return tmp;
    return nullptr;
}

template<typename T>
int list<T>::listDelNode(baseNode *node) {
    baseNode *tmp = checkNode(node);
    if (tmp == nullptr) return 0;//failed
    if (tmp == head)
        head = tmp->listNextNode();
    else
        tmp->listPrevNode()->setPrevNode(tmp->listNextNode());
    if (tmp == tail)
        tail = tmp->listPrevNode();
    else
        tmp->listNextNode()->setPrevNode(tmp->listPrevNode());
    length--;
    delete tmp;
    return 1;
}

template<typename T>
list<T>::list(const list &duplist) {
    length=duplist.length;
    if(length==0) return ;
    baseNode *tmp=duplist.head;
    while(tmp!= nullptr){
        listAddTailNode(dynamic_cast<listNode<T>*>(tmp)->getValue());
    }
}

int testListFunction(){
    //todo
    return 0;
}







