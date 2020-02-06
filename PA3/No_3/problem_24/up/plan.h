#pragma once

#include <string>

class Plan {
private:
    int month;
    int day;
    std::string act;

public:
    Plan(int m, int d, const std::string& c);
    int get_month();
    int get_day();
    std::string get_act();
};