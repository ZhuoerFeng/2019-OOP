#pragma once
#include "Node.h"

class Array {
private:
    int _size = 0;
    Node* element;
public:
    // Array() : {}
    Array(int len);
    ~Array() {
        delete[] element;
    }
    Node& operator[] (const int n);
    void update(int q, int r);
    void swap(int q, int r);
    void insert(int q, int r);
};