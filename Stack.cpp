#include "Stack.h"
Stack::Stack(){

}
void Stack::push(int data) {
    list.insertFirst(data); // Добавляем элемент в начало списка (вершину стека)
}
void Stack::pop() {
    list.deleteIndex(1);
}

int Stack::top() {
    if (list.getCount() > 0) {
        return list.getHead()->data;
    }
    return -1; // Если стек пуст
}


int Stack::size() {
    return list.getCount();
}



