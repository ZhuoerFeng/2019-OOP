#include "node.h"
#include "operator.h"

int GT::priority() {
    return 1;
}

int ST::priority() {
    return 1;
}

int GTE::priority() {
    return 1;
}

int STE::priority() {
    return 1;
}

int DEQ::priority() {
    return 1;
}

int NEQ::priority() {
    return 1;
}

int NOT::priority() {
    return 2;
}

int AND::priority() {
    return 3;
}

int OR::priority() {
    return 4;
}

void GT::calc(stack<Node*>& h) {
    auto* b = h.top(); h.pop();
    auto* a = h.top(); h.pop();
    h.push(new Node(a->value() > b->value(), BOOL));
}

void ST::calc(stack<Node*>& h) {
    auto* b = h.top(); h.pop();
    auto* a = h.top(); h.pop();
    h.push(new Node(a->value() < b->value(), BOOL));
}

void GTE::calc(stack<Node*>& h) {
    auto* b = h.top(); h.pop();
    auto* a = h.top(); h.pop();
    h.push(new Node(a->value() >= b->value(), BOOL));
}

void STE::calc(stack<Node*>& h) {
    auto* b = h.top(); h.pop();
    auto* a = h.top(); h.pop();
    h.push(new Node(a->value() <= b->value(), BOOL));
}

void DEQ::calc(stack<Node*>& h) {
    auto* b = h.top(); h.pop();
    auto* a = h.top(); h.pop();
    h.push(new Node(a->value() == b->value(), BOOL));
}

void NEQ::calc(stack<Node*>& h) {
    auto* b = h.top(); h.pop();
    auto* a = h.top(); h.pop();
    h.push(new Node(a->value() != b->value(), BOOL));
}

void NOT::calc(stack<Node*>& h) {
    auto* a = h.top(); h.pop();
    h.push(new Node(!a->value(), BOOL));
}

void AND::calc(stack<Node*>& h) {
    auto* b = h.top(); h.pop();
    auto* a = h.top(); h.pop();
    h.push(new Node(a->value() && b->value(), BOOL));
}

void OR::calc(stack<Node*>& h) {
    auto* b = h.top(); h.pop();
    auto* a = h.top(); h.pop();
    h.push(new Node(a->value() || b->value(), BOOL));
}
