#include <iostream>
using namespace std;


void reverseArray(int* x){
    for (int i = 4; i >= 0; i--){
        cout << " " << *x--;
    }
}

int main(){
    int num[5] = {10, 20, 30, 40, 50};
    int *nArrayPtr = &num[4];
    reverseArray(nArrayPtr);
}