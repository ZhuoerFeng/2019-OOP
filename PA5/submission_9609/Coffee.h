//
//  Coffee.h
//  t2
//
//  Created by Fan Qu on 2018/5/23.
//  Copyright © 2018年 GF. All rights reserved.
//

#ifndef Coffee_h
#define Coffee_h

#include "Cup.h"
#include "AbstractCoffee.h"

class Coffee : public AbstractCoffee{
    
protected:
    int coffee, milk;
    bool brewed;
    bool mixed;
    
public:
    Coffee(const string &name, int coffee, int milk):
        AbstractCoffee(name, nullptr), coffee(coffee), milk(milk), brewed(false), mixed(false){}
    
    
    void brew() {
        this->brewed = true;
    }
    void mix() {
        this->mixed = true;
    }
    void pour_into(Cup *cup) {
        this->cup = cup;
        cup->hold_coffee(this);
    }
    
    ~Coffee() {
        this->cup->hold_coffee(nullptr);
        cout << "Washed " << this->cup->id() << " cup." << endl;
    }
    
    void drink() override{
        cout << "Drinking " << this->name << " (";
        float total = (this->coffee + this->milk) / 100.0f;
        if (total == 0.0f) total = 1.0f;
        cout << static_cast<int>(round(this->coffee / total)) << "% coffee";
        cout << " and ";
        cout << static_cast<int>(round(this->milk / total)) << "% milk";
        if (this->brewed || this->mixed) {
            cout << " that is";
            if (this->brewed) cout << " brewed";
            if (this->brewed && this->mixed) cout << " and";
            if (this->mixed) cout << " mixed";
        }
        cout << ") from " << this->cup->id() << " cup.";
        cout << endl;
    }
};



#endif /* Coffee_h */
