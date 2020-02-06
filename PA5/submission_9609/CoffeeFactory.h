//
//  CoffeeFactory.h
//  t2
//
//  Created by Fan Qu on 2018/5/23.
//  Copyright © 2018年 GF. All rights reserved.
//

#ifndef CoffeeFactory_h
#define CoffeeFactory_h

#include <vector>

#include "Cup.h"
#include "Coffee.h"
#include "MakeCoffee.h"


class CoffeeFactory {
    std::vector<Cup *> cups;
    std::vector<AbstractCoffee *> ordered_coffees;
    
    Cup *find_empty_cup() {
        Cup *empty_cup = nullptr;
        for (Cup *cup : cups)
            if (!cup->contains_coffee()) {
                empty_cup = cup;
                break;
            }
        return empty_cup;
    }
    
    MakeCoffee* wayToMakeCoffee;
    
public:
    
    CoffeeFactory(MakeCoffee* makeCoffeeWay): wayToMakeCoffee(makeCoffeeWay) {};
    
    int orderedCoffeeNum() const {
        return (int)ordered_coffees.size();
    }
    
    void drinkAllCoffees() {
        for (AbstractCoffee *coffee : ordered_coffees)
            if (coffee != nullptr)
                coffee->drink();
    }
    
    void washAllCups() {
        for (AbstractCoffee *coffee : ordered_coffees)
            if (coffee != nullptr) {
                delete coffee;
            }
        ordered_coffees.clear();
    }
    
    void clearCoffees() {
        for (AbstractCoffee *coffee : ordered_coffees)
            if (coffee != nullptr) {
                coffee->drink();
                delete coffee;
            }
        ordered_coffees.clear();
    }
    
    
    ~CoffeeFactory() {
        for(Cup *cup : cups) {
            delete cup;
        }
        for(AbstractCoffee *coffee : ordered_coffees) {
            delete coffee;
        }
    }
   
    
    
    AbstractCoffee* makeCoffee(const string& type) {
        Cup *cup = find_empty_cup();
        AbstractCoffee* coffee = wayToMakeCoffee->makeCoffee(type, cup);
        if(coffee != nullptr)
            ordered_coffees.push_back(coffee);
        return coffee;
    }
    
    void makeCup(const string& cupName) {
        cups.push_back(new Cup(cupName));
        //return cups.back();
    }
    
    
    
};


#endif /* CoffeeFactory_h */
