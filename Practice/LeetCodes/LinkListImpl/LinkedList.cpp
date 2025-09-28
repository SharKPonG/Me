#include <iostream>
using namespace std;


struct Node{
    int val;
    Node* next;
};


bool isEmpty(Node* head){
    if (head != nullptr) return true;
}
char menu(){
    char choice;

    cout << "MENU\n";

    cout << "1.Add an item.\n";
    cout << "2.Remove an item.\n";
    cout << "3.Show the List.\n";
    cout << "4.Exit.\n";
    
    cin >> choice;

    return choice;


}
void insertAsFirstElement(Node* &head, Node* &last, int number){
    Node *temp = new Node();
    temp->val = number;
    temp->next = nullptr;
    head = temp;
    last = temp;


}
void insert(Node* &head,Node* &last, int number){
    if(isEmpty(head)){
        insertAsFirstElement(head, last, number);
    }else{
        Node *temp = new Node;
        temp->val = number;
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}
void remove(Node* &head,Node* &last){
    
    if(isEmpty(head)){
        cout << "This is Empty\n"; 
    }else if(head == last){
        delete head;
        head = nullptr;
        last = nullptr;
    }else{
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
void showList(Node* current){
    if (isEmpty(current)){
        cout << "This List is empty\n";
    }else{
        cout << "This List contains: \n";
        while(current != nullptr){
            cout << current->val << endl;
            current = current->next;
        }
    }

}


int main(){


    Node* head = nullptr;
    Node* last = nullptr;

    char choice;
    int n;

    do{
        choice = menu();
        switch(choice)
        {
        case '1':
            cout << "Please Enter a number" << endl;
            cin >> n;
            insert(head, last, n);
            break;
        case '2': remove(head,last);
            break;
        case '3': showList(head);
            break;
        default:
            cout << "Exit\n";
            break;
        }
    }while(choice != '4');
    return 0;

}