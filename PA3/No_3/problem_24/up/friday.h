#pragma once

#include "day.h"

class Friday : public Day {
private:
    void print_extra_info() override;
    
public: 
    using Day::Day;
};
