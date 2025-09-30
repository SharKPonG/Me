#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;


void insertNode(Node *curr){
    Node *temp;
    
    temp = (Node*)malloc(sizeof(Node));

    temp = curr->next;
    curr->next = temp->next;
    free(temp);
}


int main(){
    Node *number;
    number->data = 10;
    number->next = nullptr;
    insertNode(number);
}