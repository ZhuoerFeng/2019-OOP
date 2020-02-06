#include <algorithm>
#include <iostream>
#include <vector>

#include <cassert>
#include <cmath>

using namespace std;

#include "Cup.h"
#include "Coffee.h"
#include "EasyMake.h"
#include "CoffeeFactory.h"



int main() {
    
    //freopen("output.out", "w", stdout);
    EasyMake makeCoffeeStrategy;
    CoffeeFactory *coffeeFactory = new CoffeeFactory(&makeCoffeeStrategy);
    coffeeFactory->makeCup("red");
    coffeeFactory->makeCup("white");
    coffeeFactory->makeCup("golden");
    coffeeFactory->makeCup("titanium");
    coffeeFactory->makeCup("cat pretending to be a");
    
    coffeeFactory->makeCoffee("Espresso");
    coffeeFactory->makeCoffee("Macchiato");
    coffeeFactory->makeCoffee("Cappuccino");
    coffeeFactory->makeCoffee("Latte");
    coffeeFactory->makeCoffee("Milk");
    coffeeFactory->makeCoffee("Water");
    
    cout << "Ordered " << coffeeFactory->orderedCoffeeNum() << " cups of coffee." << endl;
    
    coffeeFactory->clearCoffees();
    coffeeFactory->makeCoffee("Water");
    coffeeFactory->makeCoffee("Milk");
    coffeeFactory->makeCoffee("Latte");
    coffeeFactory->makeCoffee("Cappuccino");
    coffeeFactory->makeCoffee("Macchiato");
    coffeeFactory->makeCoffee("Espresso");
    
    cout << "Ordered " << coffeeFactory->orderedCoffeeNum() << " cups of coffee." << endl;
    
    coffeeFactory->drinkAllCoffees();
    coffeeFactory->washAllCups();
    delete coffeeFactory;
    return 0;
}
