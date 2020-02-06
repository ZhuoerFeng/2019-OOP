//
//  Cup.h
//  t2
//
//  Created by Fan Qu on 2018/5/23.
//  Copyright © 2018年 GF. All rights reserved.
//

#ifndef Cup_h
#define Cup_h

class Cup {
    string _id;
    class AbstractCoffee *coffee;
    
public:
    Cup(const string &id) : _id(id), coffee(nullptr) {}
    ~Cup() {
        cout << "Sold " << _id << " cup." << endl;
    }
    bool contains_coffee() const {
        return this->coffee != nullptr;
    }
    void hold_coffee(AbstractCoffee *coffee) {
        this->coffee = coffee;
    }
    const string &id() const {
        return _id;
    }
};

#endif /* Cup_h */
