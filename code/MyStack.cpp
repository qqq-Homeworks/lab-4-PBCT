// Copyright 2021 qqq <polyakovdd@student.bmstu.ru>

#include "MyStack.hpp"
#include <iostream>

template<class INF>
bool MyStack<INF>::empty() {
    if (top == nullptr)
        return true;
    else
        return false;
}

template<class INF>
MyStack<INF>::MyStack() {
    this->top = nullptr;
}

template<class INF>
MyStack<INF>::~MyStack() {
    Node tempNode;
    while (top != nullptr) {
        tempNode = (top->next);
        delete top;
        top = &tempNode;
    }
}

template<class INF>
void MyStack<INF>::push(INF n) {
    Node *tempNode = new Node;
    tempNode->d = n;
    tempNode->next = top;
    top = tempNode;
}

template<class INF>
bool MyStack<INF>::pop() {
    if (top == nullptr) return false;
    Node *tempNode = top->next;
    delete top;
    top = tempNode;
    return true;
}

template<class INF>
INF MyStack<INF>::top_inf() {
    if (top == nullptr) return 0;
    return top->d;
}

template<class INF>
void MyStack<INF>::reverse() {
    Node *previousNode = top;
    Node *node = top->next;
    Node *nextNode;
    previousNode->next = nullptr;
    do {
        nextNode = node->next;
        node->next = previousNode;
        previousNode = node;
        node = nextNode;
    } while (node->next != nullptr);
    node->next = previousNode;
    top = node;
}

template<class INF>
void MyStack<INF>::print() {
    Node *node = top;
    while (node != nullptr) {
        std::cout << node->d << '*';
        node = node->next;
    }
    std::cout << "\b \n";
}
