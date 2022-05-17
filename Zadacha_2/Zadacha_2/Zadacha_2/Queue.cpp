#include "Queue.h"

Queue::Queue() {
    head = -1;
    tail = -1;
}

Queue::Queue(int SIZE) {
    head = -1;
    tail = -1;
    this->SIZE = SIZE;
    items = new int[this->SIZE];
}

// 1) добавить элемент в конец очереди (при переполнении – исключение)
void Queue::push(int element) {
    if (isFull()) {
        throw "\nQueue is full\n";
    }
    else {
        if (head == -1) head = 0;
        tail = (tail + 1) % SIZE;
        items[tail] = element;
    }
}

// 2) взять элемент в начале очереди (при отсутствии – исключение)
void Queue::pop() {
    int element;
    if (isEmpty()) {
        throw "\nQueue is empty\n";
    }
    else {
        element = items[head];
        if (head == tail) {
            head = -1;
            tail = -1;
        }
        else {
            head = (head + 1) % SIZE;
        }
    }
}

// 3) получить элемент в начале очереди (без его изъятия)
int Queue::getHeadElement() {
    return items[head];
}

// 4) размер очереди
int Queue::size() {
    return SIZE;
}

// 5) сделать очередь пустой
void Queue::makeEmpty() {
    while (!isEmpty()) {
        pop();
    }
    SIZE = 0;
}

// 6) проверка очереди на пустоту
bool Queue::isEmpty() {
    return head == tail;
}

// 6+) проверка очереди на полноту
bool Queue::isFull() {
    if (head == 0 && tail == SIZE - 1) {
        return true;
    }
    if (head == tail + 1) {
        return true;
    }
    return false;
}

void Queue::display() {
    int i;
    if (isEmpty()) {
        throw "\nQueue is empty\n";
    }
    else {
        for (i = head; i != tail; i = (i + 1) % SIZE)
            cout << items[i];
        cout << items[i];
    }
}