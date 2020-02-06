#include "Test.h"

const Test& F(const Test& a){
    cout << "fuck2" << endl;
    Test b = a;
    cout << "fuck3" << endl;
    return std::move(b);
}

int main() {
    cout << "fuck0" << endl;
    Test a;
    cout << "fuck1" << endl;
    const Test &A = F(std::move(a));
    cout << "fuck4" << endl;
    return 0;
}