#pragma once
#include <iostream>
#include "CircularBuffer.h"

template <typename T>
class Iterator {
private:
    CircularBuffer<T> q;

public:
    Iterator(CircularBuffer<T> q) {
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