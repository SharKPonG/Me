#include <iostream>
#include <queue>
using namespace std;


queue<int> calls;

int ping(int t){
    calls.push(t);

    while(!calls.empty() && calls.front() < t - 3000){
        calls.pop();
    }
    return calls.size();
}


int main(){

    cout << ping(1) << endl;
    cout << ping(100) << endl;
    cout << ping(3001) << endl;
    cout << ping(3002) << endl;
}