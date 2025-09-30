#include <iostream>
using namespace std;

// pass by reference
void increment(int* x){
    cout << "Number after Pointer :" << x << endl;
    *x += 15; // num += 20;
}

int main(){
    int num = 20;
    increment(&num);
    cout << "Addresss : " << &num << endl;
    cout << num << endl;
}