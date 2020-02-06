#include "day.h"

Day::Day(int m, int d, const std::string& w) : month(m), day(d), week(w) {

}

Day::~Day() {
    
}

int Day::get_size() {
    return p.size();
}

bool Day::insert(Plan& t) {
    if (t.get_month() == this->month && t.get_day() == this->day) {
        p.push_back(t);
        return true;
    } else return false;
}  

void Day::print() {
    std::cout << this->month << "/" << this->day <<  " " << this->week << " ";
    if (!get_size()) {
        std::cout << "Today is Free\n";
    } else {  
        std::cout << "Today's Plan:\n";
        for (int i = 0; i < get_size(); ++i) {
            std::cout << p[i].get_act() << "\n";
        }
    }
    print_extra_info();
}

void Day::print_extra_info() {

}