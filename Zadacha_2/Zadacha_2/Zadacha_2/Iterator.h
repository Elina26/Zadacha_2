#pragma once
#include <iostream>
#include "Queue.h"

class Iterator {
private:
    Queue q;
    //int first;

public:
    Iterator(Queue q) {
        this->q = q;
    }
    int start() {
        return q.getHeadElement();
    }
    void next() {
        if (!q.isEmpty()) {
            q.pop();
        }
    }
    bool finish() {
        if (q.isEmpty()) {
            return true;
        }
        else return false;
    }
    int getValue() {
        return q.getHeadElement();
    }
};