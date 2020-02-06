#pragma once
#include <iostream>
#include <cstring>

class Plate {
	std::string _id;
	class Pizza *pizza;

public:
	Plate(const std::string &id) : _id(id), pizza(nullptr) {}
	
	bool contains_pizza() const {
		return this->pizza != nullptr;
	}

	void hold_pizza(Pizza *pizza) {
		this->pizza = pizza;
	}
	
	const std::string &id() const {
		return _id;
	}

	~Plate() {
		std::cout << "Sold " << _id << " plate." << std::endl;
	}
};
