#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

#include "plate.h"
#include "pizza.h"
#include "pizza_factory.h"

using namespace std;

int main() {
    PizzaFactory pizzafactory;
    pizzafactory.make_new_plate("red");  
    pizzafactory.make_new_plate("white");
    pizzafactory.make_new_plate("golden");
    pizzafactory.make_new_plate("titanium");
    pizzafactory.make_new_plate("yellow");

    vector<Pizza* > ordered_pizzas;

	ordered_pizzas.push_back(pizzafactory.make_pizza("Seafood Pizza"));
	ordered_pizzas.push_back(pizzafactory.make_pizza("Beef Pizza"));
	ordered_pizzas.push_back(pizzafactory.make_pizza("Fruit Pizza"));
	ordered_pizzas.push_back(pizzafactory.make_pizza("Sausage Pizza"));
	ordered_pizzas.push_back(pizzafactory.make_pizza("Tomato Pizza"));
	ordered_pizzas.push_back(pizzafactory.make_pizza("Cheese Pizza"));

	int count = 0;
	for (Pizza *pizza : ordered_pizzas)
		if (pizza != nullptr) ++count;
	cout << "Ordered " << count << " plates of pizza." << endl;
	for (Pizza *pizza : ordered_pizzas)
		if (pizza != nullptr) {
			pizza->eat();
			pizzafactory.del(pizza);
		}

	ordered_pizzas.clear();
	ordered_pizzas.push_back(pizzafactory.make_pizza("Cheese Pizza"));
	ordered_pizzas.push_back(pizzafactory.make_pizza("Tomato Pizza"));
	ordered_pizzas.push_back(pizzafactory.make_pizza("Sausage Pizza"));
	ordered_pizzas.push_back(pizzafactory.make_pizza("Fruit Pizza"));
	ordered_pizzas.push_back(pizzafactory.make_pizza("Beef Pizza"));
	ordered_pizzas.push_back(pizzafactory.make_pizza("Seafood Pizza"));
	
	count = 0;
	for (Pizza *pizza : ordered_pizzas)
		if (pizza != nullptr) ++count;
	cout << "Ordered " << count << " plates of pizza." << endl;
	for (Pizza *pizza : ordered_pizzas)
		if (pizza != nullptr) 
			pizza->eat();

	return 0;
}