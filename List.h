
#ifndef SDL4_LIST_H
#define SDL4_LIST_H

#include "Node.h"

class List {
        //добавление внутренних полей
    private:
        Node* head = nullptr;
        int count = 0; // количество элементов в списке

    public:
        List();
        void insertFirst(int data);//функция добавления узла в начало
        void insertEnd(int data);//функция добавления в конец
        void insertValue(int value, int pos);//функция вставить в лист
        void deleteIndex(int index);//функция удалить элемент по индексу
        void deleteData(int data);//удаление узла по значению
        int findData(int data);//поиск значения
        int findPosition(int index);//поиск по индексу
        void printList();//функция вывода листа
        int getCount();
        Node* getHead();
};


#endif //SDL4_LIST_H
