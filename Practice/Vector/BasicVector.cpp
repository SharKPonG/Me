#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> number;

    number.push_back(10);
    number.push_back(20);


    number.pop_back();

    for (int i = 0; i < number.size(); i++){
        cout << number[i] << " " << endl;

    }
}