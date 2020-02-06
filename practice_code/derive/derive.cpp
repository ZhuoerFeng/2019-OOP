#include <cstdio>
using namespace std;

class Base {
    private:
        int data;

    public:
        Base() : data(0) { printf("Base Construct -default. data = %d\n", data); }
        Base(int x) : data(x) { printf("Base Construct -int. data = %d\n", data); }
        void base_func() { printf("in Base::base_func()....\n"); }

};

class Derive : public Base {
    private:
        int num;
    
    public:
        Derive() = default;
        using Base::Base;

};

class Derive1 : public Base {};

class Derive2 : private Base {

    public:
        void derive_func() { 
            printf("in Derive2::derive_func(), calling....\n"); 
            base_func();
        }
};

class Derive3 : private Base{

    public:
        using Base::base_func;
};



int main() {
    printf("in main()...\n");

    Derive1 obj1;
    printf("calling obj1::base_func()...\n");
    obj1.base_func();

    Derive2 obj2;
    printf("calling obj2::derive_func()...\n");
    obj2.derive_func();

    Derive3 obj3;
    printf("calling obj3::base_func()...\n");
    obj3.base_func();

    // Derive me(10);
    return 0;
}