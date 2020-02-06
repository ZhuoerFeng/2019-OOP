#pragma once

#include "plan.h"
#include <string>
#include <iostream>
#include <vector>

class Day {
private:
    int month;
    int day;
    std::string week;
    std::vector<Plan> p;

public:
    Day(int m, int d, const std::string& w);
    ~Day();
    int get_size();
    bool insert(Plan& t);
    void print();
    virtual void print_extra_info();
};

