#include <iostream>
using namespace std;


// LinkedList
// linear data structures

// grade[] = {a, b, c, d} 
// LinkedList -> grade[] to nodes
// [ A[ .-]-> link 
// linked always -> null (last data)


// // sigly LinkedList
// class Node{
// public:
//     int data;
//     Node* next;

//     Node(int data){
//         this->data = data;
//         this->next = nullptr; // ชี้ Last data เสมอ
//     }
// };

// void printList(Node *n){
//     while (n != nullptr){ // ถ้า Node ไม่ว่าง ให้ชี้ ตัวถัดไป จนกว่าจะ nullptr
//         cout << n->data << " ";
//         n = n->next;
//     }
// }

// int main(){
//     Node *head = new Node(1);
//     Node *second = new Node(2);
//     Node *third = new Node(3);

//     head->next = second;
//     second->next = third;

//     printList(head); // 1, 2, 3

//     return 0;
// }


// Doubly LinkedList
// <-[-.[data].-]-> ไปได้ทั้งสองทาง เก็บได้ทั้งสองเส้นทาง


// class Node{
// public:
//     int data;
//     Node* prev;
//     Node* next;

//     Node(int data){
//         this->data = data;
//         this->prev = nullptr;
//         this->next = nullptr;
//     }
// };

// void printList(Node *node){
//     while (node != nullptr){
//         cout << node->data << " ";
//         node = node->next;
//     }


// }

// void printBackList(Node *node){
//     while (node != nullptr){ // ถ้า Node ไม่ว่าง ให้ชี้ตัวก่อนหน้า
//         cout << node->data << " ";
//         node = node->prev;
//     }

// }

// int main(){
//     Node *head = new Node(1);
//     Node *second = new Node(2);
//     Node *third = new Node(3);

//     head->next = second;
//     second->prev = head;
//     second->next = third;
//     third->prev = second;

//     printList(head);
//     printBackList(third); // 3, 2, 1
// }

// // Circular LinkedList

// #include <string>
// using std::string;
// class Song{
// public:
//     string title;
//     Song *next;
//     Song *prev;

//     Song(string title){
//         this->title = title;
//         this->next = nullptr;
//         this->prev = nullptr;
//     }
// };


// class Playlist{
// private:
//     Song *head;
//     Song *tail;

// public: 
//     Playlist() : head(nullptr), tail(nullptr){}

//     void addSong(string title){
//         Song *newSong = new Song(title);
//         if (!head){
//             head = newSong;
//             tail = newSong;
//         }else{
//             tail->next = newSong; // เพลงถัดไป ชี้ newSong
//             newSong->prev = tail;
//             tail = newSong;
//         }
//     }

//     bool removeSong(const string& title) {
//         Song *temp = head;

//         while (temp != nullptr) {
//             if (temp->title == title) {
//                 if(temp->prev) temp->prev->next = temp->next;
//                 if(temp->next) temp->next->prev = temp->prev;
//                 if(temp == head) head = temp->next;
//                 if(temp == tail) tail = temp->prev;
//             delete temp;
//             return true;
//             }
//         temp = temp->next;
//         }
//     return false;
//     }
// };


// int main(){
//     Playlist mySongs;

//     mySongs.addSong("BabyShark1");
    
//     mySongs.addSong("BabyShark2");
//     mySongs.addSong("BabyShark3");
//     mySongs.addSong("BabyShark4");

//     mySongs.removeSong("BabyShark2");
// }



typedef struct Node{
    int data;
    Node* next;
}Node;


void LinkedListTraversal(Node *ptr){
    while (ptr != nullptr){
        cout << ptr << " " << endl;
        ptr = ptr->next; 
    }
}

int main(){
    Node* head;
    Node* second;
    Node* third;

    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));


    head->data = 10;
    head->next = second;
    
    second->data = 14;
    second->next = third;


    third->data = 16;
    third->next = nullptr;

    LinkedListTraversal(head);
    
}