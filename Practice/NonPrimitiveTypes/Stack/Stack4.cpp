#include <iostream>
using namespace std;


#define MAX_STACK_SIZE 100

typedef struct Stack{
    int item[MAX_STACK_SIZE];
    int top;
}Stack;

void initStack(Stack *s){
    s->top = -1;
}

bool pushStack(Stack *s, int x){
    if (s->top >= MAX_STACK_SIZE - 1){
        return false;
    }else{
        s->top++;
        s->item[s->top] = x;
        return true;
    }
}

bool popStack(Stack *s, int *x){
    if (s->top < 0){
        return false;
    }else{
        *x = s->item[s->top];
        s->top--;
        return true;
    }
}

void printStack(Stack s){
    int i;
    cout << "Stack: ";
    for(i = 0; i < s.top; i++){
        cout << s.item[i] << " ";
    }
}

int main(){
    Stack s;
    int choice;
    int cont = true;
    int x;

    initStack(&s);
    while(cont == true){
        cout << "Please select [1:push 2:pop 3:print 0:exit]" << endl;
        cin >> choice;
        switch(choice){
        case 1:
            cout << "Please enter a number to be pushed: ";
            cin >> x;
            if (!pushStack(&s,x)) cout << "ERROR pushing into the stack\n";
            break;
        case 2:
            if (popStack(&s,&x)) cout << "The number " << x << " is popped off\n";
        else
            cout << "ERROR popping from the stack\n";
            break;
        case 3:
            printStack(s);
            break;
        case 0:
            cont = false;
            break;
        }
    }
}