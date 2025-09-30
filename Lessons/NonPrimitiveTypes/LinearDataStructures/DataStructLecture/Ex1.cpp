#include <iostream>
using namespace std;

typedef struct Node{
    int num;
    Node* next;
}Node;


int main(){
    Node* first = NULL;
    Node* mid  = NULL;
    Node* last = NULL;

    first = (Node*)malloc(sizeof(Node));
    last = (Node*)malloc(sizeof(Node));
    mid = (Node*)malloc(sizeof(Node));

    first->num = 1;
    first->next = mid;

    mid->num = 3;
    mid->next = last;

    last->num = 5;
    last->next = NULL;
    
    cout << first->num << " " << last->num << " " <<mid->num << endl;

    free(first);
    free(last);
    free(mid);
    return 0;
}