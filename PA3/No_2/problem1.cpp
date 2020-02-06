#include "Test.h"

Test F(Test &&a){
	cout << "fuck1" << endl;
    Test b = a;
	cout << "fuck2" << endl;
    return b;
}
int main(){
	cout << "fuck0" << endl;
    Test A = F(1);
	cout << "fuck3" << endl;
    return 0;
}