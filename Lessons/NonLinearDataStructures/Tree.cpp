#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

// inOrder left root right;
void traverseTree(Node *root){
    traverseTree(root->left);
    cout << root->data;
    traverseTree(root->right);
}
// PostOrder left->right->root;

void PostOrder(Node *root){
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data;

}



// PreOrder root->left->right;
void PreOrder(Node *root){
    cout << root->data;
    PreOrder(root->left);
    PreOrder(root->right);
}