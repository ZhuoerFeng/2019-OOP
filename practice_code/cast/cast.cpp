#include <iostream>
using namespace std;

class Base {
    int i;
    
};

class Derive : public Base {
    int j;
};

void getsize(Base& p) {
    printf("getsize: %d\n", sizeof(p));
}


int main() {
    Base b;
    printf("%d\n", sizeof(b));
    Derive d;
    printf("%d\n", sizeof(d));
    getsize(d);
    return 0;
}