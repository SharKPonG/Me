#include <iostream>
using namespace std;

typedef struct Node{
    int val;
    Node *next;
}Node;


Node* createList(vector<int> &values){
    Node* head = nullptr;
    Node* tail = nullptr;

    vector<Node*> vectorPtr;

    for(int value : values){
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }

        vectorPtr.push_back(newNode);
    }

    return head;
}

void printList(Node* head){
    Node *p = head;
    while (p != nullptr){
        cout << p->val << " ";
        p = p->next;
    }
}

int main(){
    vector<int> valuesArr;
    int num;
    while(cin.peek() != '\n' && cin >> num){
        valuesArr.push_back(num);
    }

    Node *head = createList(valuesArr);
    printList(head);
}