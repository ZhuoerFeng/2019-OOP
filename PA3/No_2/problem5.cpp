#include "Test.h"

const Test& F(Test a){   
    Test& b = a;
    return std::move(b);
}

int main(){
    Test a;
    Test A = F(a);
    return 0;
}