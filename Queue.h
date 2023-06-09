

#ifndef SDL4_QUEUE_H
#define SDL4_QUEUE_H

#include "List.h"
class Queue {
public:
    Queue();
    void enqueue(int data);
    int dequeue();
    bool isEmpty();

private:
    List list;
};


#endif //SDL4_QUEUE_H
