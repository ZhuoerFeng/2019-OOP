//
//  EasyMake.h
//  t2
//
//  Created by Fan Qu on 2018/5/23.
//  Copyright © 2018年 GF. All rights reserved.
//

#ifndef EasyMake_h
#define EasyMake_h

#include "MakeCoffee.h"

class EasyMake : public MakeCoffee {
    
    enum CoffeeType {
        notype = 0, espresso = 1, macchiato = 2, cappuccino = 3, latte = 4, milk = 5, water = 6
    };
    
public:
    
    
    * makeCoffee(const string& type, Cup *cup) override{
        if (cup == nullptr) return nullptr;
        Coffee *coffee = nullptr;
        CoffeeType coffeeType = notype;
        if(type == "Espresso")
            coffeeType = espresso;
        else if(type == "Macchiato")
            coffeeType = macchiato;
        else if(type == "Cappuccino")
            coffeeType = cappuccino;
        else if(type == "Latte")
            coffeeType = latte;
        else if(type == "Milk")
            coffeeType = milk;
        else if(type == "Water")
            coffeeType = water;
        
        switch (coffeeType) {
            case espresso:
                coffee = new Coffee("Espresso", 20, 0);
                coffee->brew();
                break;
            case macchiato:
                coffee = new Coffee("Macchiato", 40, 20);
                coffee->brew();
                coffee->mix();
                break;
            case cappuccino:
                coffee = new Coffee("Cappuccino", 20, 40);
                coffee->brew();
                break;
            case latte:
                coffee = new Coffee("Latte", 30, 90);
                coffee->brew();
                coffee->mix();
                break;
            case milk:
                coffee = new Coffee("Milk", 0, 100);
                break;
            case water:
                coffee = new Coffee("Water", 0, 0);
                break;
            default:
                break;
        }
        if(coffee != nullptr) {
            coffee->pour_into(cup);
        }
        return coffee;
    }
    
};

#endif /* EasyMake_h */
