#include <bits/stdc++.h>
using namespace std;

class iterator {
    int _data;

    public:
        iterator operator++();
        iterator operator++(int);
};

iterator iterator::operator++() {
    _data++;
    return *this;
}

iterator iterator::operator++(int i) {
    _data++;
    return xxx[_data - 1];
}

int main() {   
    i ++;
    ++ i;
    


    return 0;
}