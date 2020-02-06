// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1,2,3,4,5} ;
    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(3);
    // vec.push_back(4);
    // vec.push_back(5);
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << "[" << *it << "]\t";
    }
    std::cout << std::endl;

    return 0;
}