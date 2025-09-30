#include <iostream>
using namespace std;




typedef struct Node{
    int data;
    Node* next;
}Node;

Node* createList(const vector<int> values){
    Node* head = nullptr;
    Node* tail = nullptr;
    vector<int> nPtrs;
    for (int i : values){
        Node* newNode = new Node{i, nullptr};
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
Node* reverseLinkList(Node *head){
    if (head == nullptr) return nullptr;

    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while (curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node *head){
    Node *p = head;
    while (p != nullptr){
        cout << p->data << " ";
        p = p->next;
    }
}
int main(){

    vector<int> values;
    int num;
    while(cin.peek() != '\n' && cin >> num){
        values.push_back(num);
    }
    Node *head = createList(values);
    head = reverseLinkList(head);
    printList(head);
}