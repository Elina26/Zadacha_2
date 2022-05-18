#pragma once
#include <iostream>
using namespace std;

template <typename T>
class CircularBuffer {
private:
    T* items;
    int head, tail;
    int SIZE;

public:
    CircularBuffer() {
        head = -1;
        tail = -1;
        SIZE = 0;
        items = nullptr;
    }

    CircularBuffer(int SIZE) {
        head = -1;
        tail = -1;
        this->SIZE = SIZE;
        items = new int[this->SIZE];
    }

    // 1) добавить элемент в конец очереди (при переполнении Ц исключение)
    void push(int element) {
        if (isFull()) {
            throw "\nCircularBuffer is full\n";
        }
        else {
            if (head == -1) head = 0;
            tail = (tail + 1) % SIZE;
            items[tail] = element;
        }
    }

    // 2) вз€ть элемент в начале очереди (при отсутствии Ц исключение)
    void pop() {
        if (isEmpty()) {
            throw "\nCircularBuffer is empty\n";
        }
        else {
            if (head == tail) {
                head = -1;
                tail = -1;
            }
            else {
                head = (head + 1) % SIZE;
            }
        }
    }

    // 3) получить элемент в начале очереди (без его изъ€ти€)
    int getHeadElement() {
        return items[head];
    }

    // 4) размер очереди
    int size() {
        return SIZE;
    }

    // 5) сделать очередь пустой
    void makeEmpty() {
        for (int i = 0; i < SIZE; i++) {
            pop();
        }
        head = -1;
        tail = -1;
    }

    // 6) проверка очереди на пустоту
    bool isEmpty() {
        if (head == -1 && tail == -1) return true;
        else return false;
    }

    // 6+) проверка очереди на полноту
    bool isFull() {
        if (head == 0 && tail == SIZE - 1) {
            return true;
        }
        if (head == tail + 1) {
            return true;
        }
        return false;
    }

    void display() {
        int i;
        if (isEmpty()) {
            cout << "\nCircularBuffer is empty\n";
        }
        else {
            cout << "\n[";
            for (i = head; i != tail; i = (i + 1) % SIZE)
                cout << items[i];
            cout << items[i];
            cout << "]\n";
        }
    }
};