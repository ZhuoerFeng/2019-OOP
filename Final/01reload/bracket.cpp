#include <iostream>
using namespace std;

class Test {
public:
    int operator() (int a, int b) {
        cout << "operator() called. " << a << ' ' << b << endl;
        return a + b;
    }
};
int main() {
    Test sum;
    int s = sum(3, 4); /// sum􀀇􀀍􀀋􀀂􀀆􀀍􀀊􀀁􀀃􀀅􀀉􀀎􀀈􀀄􀀌􀀏􀀅􀀉􀀇􀀍􀀐
    cout << "a + b = " << s << endl;
    int t = sum.operator()(5, 6);
    return 0;
}