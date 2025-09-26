#include <iostream>
using namespace std;

typedef struct Node{
    int num;
    struct Node *next;
}Node;


Node *newNode(){
    Node *p;
    p = (Node*)malloc(sizeof(Node));

    p->next = nullptr;
    return p;
}

int main(){
    Node* first = newNode();
    Node* last = newNode();
    first->num = 1;
    first->next = last;
    last->num = 5;
    last->next = nullptr;

    return 0;
}