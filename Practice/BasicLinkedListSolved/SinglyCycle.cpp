#include <iostream>
#include <vector>
using namespace std;


typedef struct Node{
    int val;
    Node* next;
}Node;


bool LinkedListCycle(Node *head){
    if (head == nullptr){
        return false;
    }
    Node *s = head;
    Node *p = head;

    while (s != nullptr && s->next != nullptr){
       s = s->next;
       p = p->next->next; 

       if (s == p){
        return true;
       }
    }
    return false;       
}
Node* createLinkedList(const vector<int> &values, int pos){
    Node *head = nullptr;
    Node *tail = nullptr;
    vector<Node*> nodePtrs;

    for (int value : values){
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        nodePtrs.push_back(newNode);
    }
    if (pos >= 0) {
        tail->next = nodePtrs[pos];
    } 
    return head;
}

int main(){
    vector<int> values;
    int num;

    while (cin.peek() != '\n' && cin >> num) {
        values.push_back(num);
    }


    int pos;
    cin >> pos;

    Node* head = createLinkedList(values, pos);
    cout << (LinkedListCycle(head) ? "true" : "false") << endl;
    return 0;
}