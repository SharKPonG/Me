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

// Circular LinkedList

#include <string>
class Song{
public:
    string title;
    Song *next;
    Song *prev;

    Song(string title){
        this->title = title;
        this->next = nullptr;
        this->prev = nullptr;
    }
};


class Playlist{
private:
    Song *head;
    Song *tail;

public: 
    Playlist() : head(nullptr), tail(nullptr){}

    void addSong(string title){
        Song *newSong = new Song(title);
        if (!head){
            head = newSong;
            tail = newSong;
        }else{
            tail->next = newSong; // เพลงถัดไป ชี้ newSong
            newSong->prev = tail;
            tail = newSong;
        }
    }

    bool removeSong(const string& title) {
        Song *temp = head;

        while (temp != nullptr) {
            if (temp->title == title) {
                // กรณีเป็นหัว
                if (temp == head) {
                    head = temp->next;                 // ขยับหัวไปขวา
                    if (head != nullptr) head->prev = nullptr;
                    if (temp == tail) tail = nullptr;  // เคสโหนดเดียว: head==tail==temp
                }
                // กรณีเป็นท้าย
                else if (temp == tail) {
                    tail = temp->prev;                 // ขยับท้ายไปซ้าย
                    if (tail != nullptr) tail->next = nullptr;
                }
                // กรณีกลาง
                else {
                    temp->prev->next = temp->next;  
                    temp->next->prev = temp->prev; 
                }

                delete temp;                           // ปิดหน่วยความจำ
                return true;                           // ลบ “ตัวแรกที่เจอ”
            }
            temp = temp->next;                         // เดินต่อเมื่อยังไม่เจอ
        }

        return false;                                   // ไล่ครบแล้วไม่เจอ
    }
};

int main(){
    Playlist mySongs;

    mySongs.addSong("BabyShark1");
    
    mySongs.addSong("BabyShark2");
    mySongs.addSong("BabyShark3");
    mySongs.addSong("BabyShark4");

    mySongs.removeSong("BabyShark2");
}