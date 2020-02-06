#include <iostream>
using namespace std;

class A {
    
public:
    A() { printf("Constructing A...\n"); }
    A(A& ) {printf("Copying A...\n"); } 

};

int main() {
    printf("In main...\n");
    printf("First run...\n");
    A a;
    printf("Second run...\n");
    A b = a;
    printf("Third run...\n");
    A& c = b;
    // printf("Forth run...\n");
    // A d[4];
    return 0;
}