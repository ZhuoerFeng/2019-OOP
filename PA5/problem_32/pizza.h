#pragma once
#include <cstring>
#include <iostream>
#include "plate.h"

class Pizza {
protected:
	std::string name;
	int ketchup, cheese;
	bool cooked;
	bool cutted;
	Plate *plate;

public: 
	Pizza(const std::string &name, int ketchup, int cheese)
			: name(name), ketchup(ketchup), cheese(cheese), cooked(false), cutted(false), plate(nullptr) {}
	
	virtual void cook() {
		this->cooked = true;
	}

	virtual void cut() {
		this->cutted = true;
	}

	virtual void put_on(Plate *plate) {
		this->plate = plate;
		plate->hold_pizza(this);
	}

	virtual void eat() {
		std::cout << "Eating " << this->name << " (";
		float total = (this->ketchup + this->cheese) / 100.0f;
		if (total == 0.0f) total = 1.0f;
		std::cout << static_cast<int>(round(this->ketchup / total)) << "% ketchup";
		std::cout << " and ";
		std::cout << static_cast<int>(round(this->cheese / total)) << "% cheese";
		if (this->cooked || this->cutted) {
			std::cout << " that is";
            if (this->cooked) std::cout << " cooked";
            if (this->cooked && this->cutted) std::cout << " and";
            if (this->cutted) std::cout << " cutted";
		}
	    std::cout << ") from " << this->plate->id() << " plate.";
        std::cout << std::endl;
	}

	virtual ~Pizza() {
		this->plate->hold_pizza(nullptr);
		std::cout << "Washed " << this->plate->id() << " plate." << std::endl;
	}
};

class Seafood_Pizza : public Pizza {
	Seafood_Pizza() : Pizza("Seafood Pizza", 30, 90) {}
};

class Beef_Pizza : public Pizza {
	Beef_Pizza() : Pizza("Beef Pizza", 20, 40) {}
};

class Fruit_Pizza : public Pizza {
	Fruit_Pizza() : Pizza("Fruit Pizza", 0, 0) {}
};

class Sausage_Pizza : public Pizza {
	Sausage_Pizza() : Pizza("Sausage Pizza", 40, 20) {}
};

class Tomato_Pizza : public Pizza {
	Tomato_Pizza() : Pizza("Tomato Pizza", 20, 0) {}
};

class Cheese_Pizza : public Pizza {
	Cheese_Pizza() : Pizza("Cheese Pizza", 0, 20) {}
};

