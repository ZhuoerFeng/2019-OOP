#ifndef NODE_H
#define NODE_H

enum Type {
    BOOL, INT
};

class Node {
private:
    int v;
    Type t;

public:
    Node(int _v, Type _t) : v(_v), t(_t) {}
    int value();
    Type type();
    void print();
};

#endif
