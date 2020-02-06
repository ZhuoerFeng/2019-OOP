#include "Test.h"

Test F(const Test& a){
    cout << "fuck1" << endl;
    Test b = std::move(a); 
    cout << "fuck2" << endl;
    return b;
}
int main(){
    cout << "fuck0" << endl;
    Test A = F(1);
    cout << "fuck3" << endl;
    return 0;
}