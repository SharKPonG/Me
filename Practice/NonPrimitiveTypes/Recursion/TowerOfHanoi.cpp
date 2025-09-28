#include <iostream>
using namespace std;


void towerOfHanoi(int n, char fr, char tr, char ar){
    
    if (n == 0) return ;
    towerOfHanoi(n-1, fr, ar, tr);
    cout << "Move Disk " << n << "From " << fr << "To " << tr << endl;
    towerOfHanoi(n-1, ar, tr, fr);
}

int main(){
    int N = 3;
    towerOfHanoi(N,'A', 'C', 'B');
    return 0;
}