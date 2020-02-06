#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::vector;
using std::map;

// base(vector) -> Point( include POS) -> Pos : pos == pair <int, int >  base 1 > base2 := Point 1 > Point 2 := pair1 > pair2
// template <class A>

template<class A>
struct Point {
    Pos pos;
    A value;
    Point();
    Point (Pos p, A v): pos(p), value(v) {}  // construct
    bool operator < (const Point<A> & t);
};

template<class A>
bool Point<A>::operator< (const Point<A>& t) {
    if (pos.first != t.pos.first) {
        return pos.first < t.pos.first;
    } else {
        return pos.second < t.pos.second;
    }
    // return pos < t.pos;
}


template<class A, class C>
class Container : public BasicContainer<A> {
public:
    void insert(const Pos &p, const A &v) {};
    A* find(Pos p) { return NULL; };
};

template <class A>   // specification
class Container<A, vector<A> > : public BasicContainer<A> {
    vector< Point<A> > base;
    
public:
    void insert(const Pos &p, const A &v) {
        base.push_back(Point<A>(p, v));
    }

    A* find(Pos p) {
        
        std::sort(base.begin(), base.end());

        for(auto t = base.begin(); t != base.end(); ++t) {
            if(p == t->pos) return &(t->value);
        }
        return NULL;
    }
};


template <class A>   // specification
class Container<A, map<A> > : public BasicContainer<A> {
    map< Pos, A > base;

public:
    void insert(const Pos &p, const A &v) {
        base.insert(pair<Pos, A>(p, v));
    }

    A* find(Pos p) {
        map<Pos, A>::iterator iter;
        iter = base.find(p);
        if (!iter ) {
            return base[p];
        } else {
            return NULL;
        }

    }
    

};

#endif
