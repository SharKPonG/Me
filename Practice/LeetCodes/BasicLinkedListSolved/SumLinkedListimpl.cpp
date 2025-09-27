#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;



typedef struct Node{
    int data;
    Node* next;
}Node;

int componentNode(Node* head, vector<int> &nums){
    unordered_set<int> s(nums.begin(), nums.end());
    int count_compo = 0;
    Node* p = head;

    while (p != nullptr){
        if (s.count(p->data) && (p->next == nullptr || !s.count(p->next->data))){
            count_compo++;
        }
        p = p->next;
    }
    return count_compo;
}


Node* createList(vector<int> &values){
    Node* head = nullptr;
    Node* tail = nullptr;

    vector<Node*> valuesPtr;

    for (int value : values){
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr){
            head = newNode;
            tail = newNode; 
        }else{
            tail->next = newNode;
            tail = newNode; 
        }
        valuesPtr.push_back(newNode);
    }
    return  head;
}



int main(){

    vector<int> values;
    int num;
    while (cin.peek() != '\n' && cin >> num){
        values.push_back(num);
    }
    Node* head = createList(values);
    int answer = componentNode(head, values);

    cout << head << endl;
    

}