#include <iostream>
using namespace std;

class T {
    public:
        T() {
            cout << "Ooi Takaharu daii suki!!\n";
        }
        ~T() {
            cout << "Ganba suruyo!\n";
        }
};

int main() {
    T *pT = new T[3];
    delete[] pT;
}