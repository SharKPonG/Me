#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node *next;
}Node;


typedef struct Linked_list{
    int length;
    Node* head;
}NumList;

Node *newNode(){
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    p->next = nullptr;
    return p;
}

void initList(NumList *n){
    n->head = nullptr;
    n->length = 0;
}

int appendHeadList(NumList *s, Node *p){
    if (s->head == nullptr){
        s->head = p;
    }else{
        p->next = s->head;
        s->head = p;
    }
    s->length++;
    return 1;
}


int deleteNode(NumList *s){
    if (s->head == nullptr){
        return 0;
    }
    Node *temp = s->head;
    s->head = s->head->next;
    free(temp);
    s->length--;
    return 1;
}


void printNumList(NumList L){
    Node *pCurr = L.head;
    
    while(pCurr != nullptr){
        cout << "Num: " << pCurr->data << endl;
        pCurr = pCurr->next; 
    }
}

int main(){
    NumList NL;
    Node *N;
    initList(&NL);
    for (int i = 0; i < 3; i++){
        N = newNode();
        N->data = i;
        appendHeadList(&NL, N);
    }

    printNumList(NL);
    return 0;
}


// ผลลัพธ์การพิมพ์ตัวเลขจะเป็นอย่างไร = 2 1 0l