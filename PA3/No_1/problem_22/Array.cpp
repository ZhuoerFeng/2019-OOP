#include "Array.h"

Array::Array(int len) {
    _size = len;
    element = new Node[len];
}

Node& Array::operator[] (const int n) {
    return element[n];
}

void Array::update(int q, int r) {
    element[q] = element[r];
}

void Array::swap(int q, int r) {
    Node temp = std::move(element[r]);
    element[r] = std::move(element[q]);
    element[q] = std::move(temp);
}

void Array::insert(int q, int r) {
    //r [q]
    for (int i = _size - 1; i > q; --i) {
        element[i] = std::move(element[i - 1]);
    }
    Node temp2 = Node(r);
    element[q] = std::move(temp2);
}

