#include <iostream>
using namespace std;

template <typename T0> class Student {
    T0 power;
public:
    template <typename T1> void set(T1 const& n);
    template <typename T2> T2 get();
};

template <typename T0> template <typename T1>
void Student<T0>::set(T1 const& n) {
    power = T0(n);
}

template <typename T0> template <typename T2>
T2 Student<T0>::get() {
    return T2(power);
}

int main() {
    Student<int> you;
    you.set<double>(66.4);
    cout << you.get<char>() << endl;

    return 0;
}