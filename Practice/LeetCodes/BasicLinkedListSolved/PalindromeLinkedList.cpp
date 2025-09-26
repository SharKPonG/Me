#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;



Node* reverse(Node *head){
    if (head == nullptr) return nullptr;

    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node *head){
    if (head == nullptr || head->next == nullptr) return true;

    Node* slow = head;
    Node* fast = head;
    
    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* checkHalf = reverse(slow);

    Node* p1 = head;
    Node* p2 = checkHalf;

    while(p2 != nullptr){
        if (p1->data != p2->data) return false;

        p1 = p1->next;
        p2 = p2->next;
    }
    return false;
}

Node* createList(const vector<int> values){
    Node *head = nullptr;
    Node *tail = nullptr;

    vector<int> valPtrs;
    for (int value : values){
        Node *newNode = new Node{value, nullptr};
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
int main(){

    vector<int> values;
    int num;
    while(cin.peek() != '\n' && cin >> num ){
        values.push_back(num);
    }

    Node *head = createList(values);
    cout << (isPalindrome(head) ? "true" : "false" )<< endl;

}