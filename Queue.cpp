#include "Queue.h"

Queue::Queue() {

}

void Queue::enqueue(int data) {
    list.insertEnd(data);
}

int Queue::dequeue() {
    if (list.getHead() == nullptr) {
        return -1;
    }

    int front = list.getHead()->data;
    list.deleteIndex(1);
    return front;
}

bool Queue::isEmpty() {
    return list.getCount() == 0;
}
