#include "plan.h"

Plan::Plan(int m, int d, const std::string& c) : month(m), day(d), act(c) {

}

int Plan::get_month() {
    return this->month;
}

int Plan::get_day() {
    return this->day;
}

std::string Plan::get_act() {
    return this->act;
}