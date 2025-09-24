#include <iostream>
using namespace std;

// void printFunction(int a){
//     cout << "Number of a: " << a << endl;
// }


int main(){

    int num = 10;
    int* nPtr1 = &num; // -> address 
    int* nPtr2 = nPtr1; // -> address n

    num = 20;
    
    cout << num << endl; // -> 20
    cout << *nPtr1 << endl; // -> 20
    cout << *nPtr2 << endl; // -> 20

    

    // // Function With Pointer
    // void (*functionPtr)(int) = printFunction;
    // functionPtr(4); // typeCasting ได้




    // Array With Pointer
    // int nArr[5] = {1, 2, 3, 4, 5};
    // int* nArrPtr = &nArr[1];
    // // สามารถไล่ Array ได้เช่น &nArr[0] + 2 = 3 

    // Pointer
    // int n = 10;
    // int* nPtr = &n;

    // cout << &n << endl; // address ของ n ที่เก็บ 10
    // cout << *nPtr << endl; // pointer -> value ของ n ซึ่ง = 10
}