#include <iostream>
#include <stack>
using namespace std;


/* array -> [0[1[2[3]4]5]
top = 2
arr[top] = 2    
*/
#define MAX_SIZE 100

class Stack{
private:
    int top;
    int arr[MAX_SIZE];
public:
    Stack() {top = -1;}

    void push(int x ){
        if(top >= (MAX_SIZE -1)){
            cout << "Stack OverFlow" << endl;
        }else{
            arr[++top] = x;
            cout << x << "pushed into stack" << endl;
        }
    }

    int pop(){
        if (top < 0){
            cout << "Stack UnderFlow" << endl;
            return 0;
        }else{
            int x = arr[top--];
            return x;
        }
    }

    int peek(){
        if (top < 0){
            cout << "Stack is Empty" << endl;
            return 0;
        }else{
            int x = arr[top];
            return x;
        }
    }
};


int main(){
    Stack s;

    s.push(10);
    s.push(20);

    cout << "Top Element is " << s.peek() << endl;
    cout << "Poped from stack" << s.pop() << endl;
    cout << "Element after pop" << s.peek() << endl;
}