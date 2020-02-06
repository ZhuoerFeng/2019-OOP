# 架构说明

Coffee和Cup采取工厂模式结合策略模式编写，Coffee为接口AbstractCoffee的派生类。CoffeeFactory为生产对象的工厂，工厂与生产方法解耦，在构造工厂时传入生产方法。生产方法的接口为MakeCoffee,对题中此种Coffee的生产方法为EasyMake，实现MakeCoffee的方法。此种架构能够非常方便地新增咖啡种类，只要新的咖啡类实现了AbstractCoffee接口并且提供实现了MakeCoffee接口的生产咖啡方法，则可以构建生产此种咖啡的工厂。



## UML图

![UML图](./uml3s.png)

## main函数

```c++
int main() {
	EasyMake makeCoffeeStrategy;//生产一大类Coffee的方法
    
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
    
    delete coffeeFactory;//工厂销毁时会销毁内部的cups和coffees 
    
    return 0;
    
}
```

