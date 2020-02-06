#include "node.h"

#include <iostream>

int Node::value () {
    return v;
}

Type Node::type() {
    return t;
}

void Node::print() {
    if (type() == INT) {
        std::cout << v << std::endl;
    } else {
        if (v) {
            std::cout << "True" << std::endl;
        } else {
            std::cout << "False" << std::endl;
        }
    }
}
