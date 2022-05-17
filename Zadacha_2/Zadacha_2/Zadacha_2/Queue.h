#pragma once
#include <iostream>
using namespace std;

class Queue {
private:
    int* items;
    int head, tail;
    int SIZE;

public:
    Queue();

    Queue(int SIZE);

    // 1) добавить элемент в конец очереди (при переполнении Ц исключение)
    void push(int element);

    // 2) вз€ть элемент в начале очереди (при отсутствии Ц исключение)
    void pop();

    // 3) получить элемент в начале очереди (без его изъ€ти€)
    int getHeadElement();

    // 4) размер очереди
    int size();

    // 5) сделать очередь пустой
    void makeEmpty();

    // 6) проверка очереди на пустоту
    bool isEmpty();

    // 6+) проверка очереди на полноту
    bool isFull();

    void display();
};