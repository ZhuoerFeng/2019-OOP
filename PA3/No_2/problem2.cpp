#include "Test.h"

Test&& F(Test &a){
    Test b = a;
    return std::move(b);
}
int main(){
    Test tmp;
    Test A = F(tmp);
    return 0;
}