#ifndef OPERATOR_H
#define OPERATOR_H

#include <stack>

#include "node.h"

using std::stack;
class Operator {
public:
    virtual int priority() = 0;
    virtual void calc(stack<Node*>& h) = 0;
};

class DEQ : public Operator { 
public:
    virtual int priority();
    virtual void calc(stack<Node*>& h);
};

class ST : public Operator {
public:
    virtual int priority();
    virtual void calc(stack<Node*>& h);
};

class STE : public Operator {
public:
    virtual int priority();
    virtual void calc(stack<Node*>& h);
};

class GT : public Operator {
public:
    virtual int priority();
    virtual void calc(stack<Node*>& h);
};

class GTE : public Operator {
public:
    virtual int priority();
    virtual void calc(stack<Node*>& h);
};

class NEQ : public Operator {
public:
    virtual int priority();
    virtual void calc(stack<Node*>& h);
};

class NOT : public Operator {
public:
    virtual int priority();
    virtual void calc(stack<Node*>& h);
};

class AND : public Operator {
public:
    virtual int priority();
    virtual void calc(stack<Node*>& h);
};

class OR : public Operator {
public:
    virtual int priority();
    virtual void calc(stack<Node*>& h);
};

class EQ : public Operator {
public:
    virtual int priority();
    virtual void calc(stack<Node*>& h);
};

#endif
