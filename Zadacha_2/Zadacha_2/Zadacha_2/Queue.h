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

    // 1) �������� ������� � ����� ������� (��� ������������ � ����������)
    void push(int element);

    // 2) ����� ������� � ������ ������� (��� ���������� � ����������)
    void pop();

    // 3) �������� ������� � ������ ������� (��� ��� �������)
    int getHeadElement();

    // 4) ������ �������
    int size();

    // 5) ������� ������� ������
    void makeEmpty();

    // 6) �������� ������� �� �������
    bool isEmpty();

    // 6+) �������� ������� �� �������
    bool isFull();

    void display();
};