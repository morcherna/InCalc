#ifndef SDL4_NODE_H
#define SDL4_NODE_H

#include <iostream>

class Node {
public:
    int data; //значение
    Node* next; //след элемент

    Node(int d) {//инициализация
        data = d;
        next = nullptr;
    }
};


#endif //SDL4_NODE_H
