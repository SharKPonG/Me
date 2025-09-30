#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};

bool contains(Node *head, int x){
    Node *curr = head;
    while (curr != nullptr){
        if (curr -> val == x) return true;
        curr = curr->next;
    }
    return false;
}
Node* findNode(Node *head, int x){
    Node *curr = head;
    while (curr != nullptr){
        if (curr->val == x) return curr;
        curr = curr->next;
    }
    return nullptr;
}

Node* pushFront(Node *head, int v){
    Node *newNode = new Node();
    newNode->val = v;
    newNode->next = head;
    return newNode;
}

Node* readLineReverse(){
    Node* head = nullptr;
    int x;
    while (cin >> x){
        if (x == 0) break;
        head = pushFront(head, x);
        }
    return head;
}
void appendTobundle(Node *&bundleHead,Node *&bundleTail, int v){
    Node* newNode = new Node();
    newNode->val =v;
    newNode->next = nullptr;

    if (bundleHead == nullptr){
        bundleHead = newNode;
        bundleTail = newNode;
    }else{
        bundleTail->next = newNode;
        bundleTail = newNode;
    }
}
pair<Node*, Node*> buildBundle(Node* lineFromSecond, Node *baseHead ){
    Node* bundleHead = nullptr;
    Node* bundleTail = nullptr;

    Node* curr = lineFromSecond;
    while (curr != nullptr){
        if (!contains(baseHead, curr->val)){
            appendTobundle(bundleHead, bundleTail, curr->val);
        }
        curr = curr->next;
    }
    return {bundleHead, bundleTail};
}

void spliceAfter(Node *anchorNode, Node* bHead, Node *bTail){
    if (!anchorNode || !bHead ) return;
    Node* after = anchorNode->next;
    anchorNode->next = bHead;
    bTail->next = after;
}


void printList(Node *head){
    bool first = true;
    for (Node* curr = head; curr != nullptr; curr = curr->next){
        if (!first) cout << ' ';
        cout << curr->val;
        first = false;
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;

    Node* base = readLineReverse();


    for (int i = 2; i <= n; ++i){
        Node* line = readLineReverse();
        if (!line) continue;

        int anchorVal = line->val;
        Node* anchorNode = findNode(base, anchorVal);
        if (!anchorNode) continue;

        auto bundle = buildBundle(line->next, base);
        Node* bHead = bundle.first;
        Node* bTail = bundle.second;
        if (bHead) spliceAfter(anchorNode, bHead, bTail);
    }

    printList(base);
    return 0;
}