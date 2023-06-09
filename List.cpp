#include "List.h"

List::List()
{
    head = nullptr;
    count = 0;
}
    void List::insertFirst(int data){//функция добавления узла в начало
        Node *new_node = new Node(data);//выделяем память
        new_node->data = data;//обращаемся к значению и присваеваем ему значение
        new_node->next = head;//делаем текущий первый узел 2
        head = new_node;//присваиваем добавленому узлу статус первого
        count++;
    }

    void List::insertEnd(int data) {//функция добавления в конец
        Node* newNode = new Node(data);//выделяем память
        newNode->data = data;//создаем новый узел в односвязном списке и заполняет его данными
        newNode->next = nullptr;//следующий узел должен быть пустым

        if (head == nullptr) {//если нет первого узла
            head = newNode;//делаем его первым
            count++;
            return;
        }

        Node* current = head;//объявляем текущим первый узел
        while (current->next != nullptr) {//проходимся по всем пока не дойдем до конца
            current = current->next;
        }

        current->next = newNode;// добавляем узел в конец
        count++;
    }

    void List::insertValue(int value, int pos) {//функция вставить в лист
        Node* newNode = new Node(value);//выделяем память

        if (pos == 0) {//если вставляем в начало
            newNode->next = head;//делаем первый узел вторым
            head = newNode;//вставляем узел в начало
            count++;
        }
        else {
            Node* current = head;//устанавливаем текущий узел первым
            for (int i = 0; i < pos - 1; i++) {//проходимся до нужной позиции
                current = current->next;
            }
            newNode->next = current->next;//двигаем на один узел
            current->next = newNode;//вставляем новый узел
            count++;
        }

    }

    void List::deleteIndex(int index) {//функция удалить элемент по индексу
        index--;
        //if (count == 0 || index < 0 || index >= count)//делаем провекрку
            //std::cout << "enter right index" << std::endl;
        if (index == 0) {//если первый элемент удаляем
            Node* temp = head;//начинаем с первого
            head = head->next;//передвигаем голову на след. значение
            delete temp;//удаляем текущий
            count--;
        } else {//если не первый
            Node* curr = head;//начинаем с первого
            int i = 0;
            while (i < index - 1 && curr->next != nullptr) {//проходимся по всему списку, пока не дойдем до индекса
                curr = curr->next;
                i++;
            }
            if (curr->next != nullptr) {//если не доши до конца
                Node* temp = curr->next;//присваиваемадрес следующего узла после текущего узла
                curr->next = curr->next->next;// соединяем узел до и после текущего
                delete temp;//удаляем узел
                count--;
            }
        }

    }

    void List::deleteData(int data) {//удаление узла по значению
        Node* current = head;//начинаем с первого

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count--;
            return;
        }
        if (current == nullptr) {// Элемент не найден
            //std::cout << "node didn't find" << std::endl;
        }

        while (current->next != nullptr && current->next->data != data) {//ищем нужное значение
            current = current->next;
        }

        Node* temp = current->next;//временный указатель на следующий узел, после текущего узла в списке
        current->next = current->next->next;//пропускаем узел, содержащий значение, которое нужно удалить
        delete temp;
        count--;
    }

    int List::findData(int data) {
        Node* temp = head;
        int index = 0;
        while (temp != nullptr) {
            index++;
            if (temp->data == data) {
                //std::cout << "Value found at index: " << index << std::endl;
                return index;
            }
            temp = temp->next;
        }
        //std::cout << "Value not found" << std::endl;
        return -1;
    }


//    void List::findData(int data) {//поиск значения
//        Node* temp = head;//начинаем с первого
//        int index = 0;
//        while (temp != nullptr) {//проходимся по всему узлу
//            index++;
//            if (temp->data == data) {
//                std::cout << "value found: " << index << std::endl;
//            }
//            temp = temp->next;
//        }
//        if (index>count){//если не нашли
//            std::cout << "value didn't find" << std::endl;
//        }
//
//    }

//    void List::findPosition(int index) {//поиск по индексу
//        index--;
//        int position = 0;
//        Node* temp = head;//начинаем с головы
//        while (temp != nullptr) {//проходимся по всему списку
//            if (position == index) {//если дошли до нужного индекса
//                std::cout << temp->data << std::endl;//выводим значение
//            }
//            position++;
//            temp = temp->next;
//
//        }
//        if(position>count) {//если не нашли
//            std::cout << "value didn't find" << std::endl;
//        }
//
//    }
int List::findPosition(int index) {
    index--;
    int position = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (position == index) {
            //std::cout << "Value at position " << index + 1 << ": " << temp->data << std::endl;
            return temp->data;
        }
        position++;
        temp = temp->next;
    }
    //std::cout << "Value not found" << std::endl;
    return -1;
}


void List::printList(){//функция вывода листа
        Node* temp = head;//начинаем с начала
        if(temp == nullptr){//если пустой
            //std::cout << "list is empty" << std::endl;
        }
        while (temp != nullptr) {//проходимся по всему листу и печатаем каждое значение
            std::cout << temp->data << " ";
            temp= temp->next;
        }
        std::cout << std::endl;

    }
int List::getCount() {
    return count;
}
Node* List::getHead() {
    return head;
}