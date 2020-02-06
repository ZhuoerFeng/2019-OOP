#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::vector;
using std::map;

template<class A>
struct Point {
    Pos pos;
    A value;
    Point (Pos p) : pos(p) {}
    Point (Pos p, A v): pos(p), value(v) {}
    bool operator < (const Point &t ) const { 
        if (pos.first != t.pos.first) {
            return pos.first < t.pos.first;
        } else {
            return pos.second < t.pos.second;
        }
    }
};

template<class A, class C>
class Container : public BasicContainer<A> {
public:
    void insert(const Pos &p, const A &v) {};
    A* find(Pos p) { return NULL; };
};

template <class A>
class Container<A, vector<A> > : public BasicContainer<A> {
    vector< Point<A> > base;
    bool sorted = false;
    
public:
    void insert(const Pos &p, const A &v) {
        base.push_back(Point<A>(p, v));
    }
 
    A* find(Pos p) {
        if (!sorted) {
            std::sort(base.begin(), base.end());
            sorted = true;
        }
        auto temp = lower_bound(base.begin(), base.end(), p);
        if (p == temp->pos && temp != base.end()) {
            return &(temp->value);
        }
        return NULL;
    }
};

template <class A>
class Container<A, map<Pos, A> > : public BasicContainer<A> {
    map<Pos, A> base;
    
public:
    void insert(const Pos &p, const A &v) {
        base.insert(make_pair(p, v));
    }
 
    A* find(Pos p) {
        auto it = base.find(p);
        if (it != base.end()) {
            return &(it->second);
        }
        return NULL;
    }
};


#endif
