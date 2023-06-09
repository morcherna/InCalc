
#ifndef SDL4_STACK_H
#define SDL4_STACK_H

#include "List.h"

class Stack
{
private:
    List list;

public:
    Stack();

    void push(int data);
    void pop();
    int top();
    int size();
};


#endif //SDL4_STACK_H
