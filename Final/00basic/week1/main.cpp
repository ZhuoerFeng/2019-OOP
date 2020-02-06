#include <iostream>
#include <cstdlib> // atoi()
#include “func.h” // ADD()

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " op1 op2" << std::endl;
        return 1;
    }
    int a, b;
    a = atoi(argv[1]); b = atoi(argv[2]);
    std::cout << ADD(a, b) << std::endl;
    return 0;
}