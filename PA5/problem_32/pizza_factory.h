#pragma once
#include <vector>
#include <cstring>
#include "pizza.h"
#include "plate.h"

class PizzaFactory {
    std::vector<Plate* > plates;
    std::vector<Pizza* > ordered_pizzas;

    Plate* find_empty_plate() {
        Plate *empty_plate = nullptr;
        for (Plate *plate : plates)
            if (!plate->contains_pizza()) {
                empty_plate = plate;
                break;
            }
        return empty_plate;
    }

public:
    void del(Pizza* pizza) {
        auto iter = std::find(ordered_pizzas.begin(), ordered_pizzas.end(), pizza);
        if (iter != ordered_pizzas.end()) {
            ordered_pizzas.erase(iter);
            delete pizza;
        }
    }

    void make_new_plate(const std::string& plateName) {
        Plate* plate = new Plate(plateName);
        plates.push_back(plate);
    }
     
    Pizza* make_pizza(const std::string& pizzaName) {
        Pizza* pizza = nullptr;
        if (pizzaName ==  "Seafood Pizza") {
            pizza = new Pizza("Seafood Pizza", 30, 90);
            pizza->cook();
            pizza->cut();
        } else if (pizzaName ==  "Beef Pizza") {
            pizza = new Pizza("Beef Pizza", 20, 40);
            pizza->cook();
        } else if (pizzaName == "Fruit Pizza") {
            pizza = new Pizza("Fruit Pizza", 0, 0);
            pizza->cook();
        } else if (pizzaName == "Sausage Pizza") {
            pizza = new Pizza("Sausage Pizza", 40, 20);
            pizza->cook();
            pizza->cut();
        } else if (pizzaName == "Tomato Pizza") {
            pizza = new Pizza("Tomato Pizza", 20, 0);
            pizza->cook();
        } else if (pizzaName == "Cheese Pizza") {
            pizza = new Pizza("Cheese Pizza", 0, 20);
            pizza->cook();
	        pizza->cut();
        }   
              
        Plate* plate = find_empty_plate();
        if (plate == nullptr) return nullptr;
        pizza->put_on(plate);
        ordered_pizzas.push_back(pizza);
        return pizza;
    }
    
    ~PizzaFactory() {
        for (auto pizza : ordered_pizzas) 
            delete pizza;

        for (auto plate : plates)
            delete plate;
    }
};

