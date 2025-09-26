#include <iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;
};

class Stack{
private:
    Node *top;

public: 
    Stack() {top = nullptr;}

    int pop(){
        if (top == nullptr){
            cout << "Stack Overflow\n";
            return 0;
        }
        Node *temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    bool isEmpty(){return top == nullptr;}

    int peek(){
        if (!isEmpty()){
            return top->data;
        }else{
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }
};




