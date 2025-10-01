#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node{
    string name;
    int size;
    vector<Node*> children;
    
    Node(string n, int s ): name(n), size(s){}
};

int computeSize(Node* node){
    if (node == nullptr) return 0;
    if (node->children.empty()) return node->size;

    int total = node->size;
    for (Node * child : node->children){
        total += computeSize(child);
    }

    node->size = total;
    return total;
}

void printPreOrder(Node* node, int depth = 0){
    if (!node) return;
    cout << string(depth * 2, ' ') << node->name << " (" << node->size << "K)" << endl;
    for (Node* child : node->children){
        printPreOrder(child, depth + 1);
    }
}

void printPostOrder(Node* node, int depth = 0){
    if (!node) return;
    for (Node* child : node->children) printPostOrder(child, depth+1);
    cout << string(depth*2, ' ') << node->name << " (" << node->size << "K)\n";
}

int main(){
    Node* root      = new Node("/user/rt/courses", 1);
    // left
    Node* cs016     = new Node("cs016", 2);
    Node* grades016 = new Node("grades", 8);
    Node* homeworks = new Node("homeworks", 1);
    Node* programs = new Node("programs", 1);
    
    homeworks->children.push_back(new Node("Hw1", 3));
    homeworks->children.push_back(new Node("Hw2", 2));
    homeworks->children.push_back(new Node("Hw3", 4));

    programs->children.push_back(new Node("pr1", 57));
    programs->children.push_back(new Node("pr2", 97));
    programs->children.push_back(new Node("pr3", 74));

    cs016->children.push_back(grades016);
    cs016->children.push_back(programs);
    cs016->children.push_back(homeworks);

    root->children.push_back(cs016);

    // Right
    Node* cs252 = new Node("cs252", 1);
    Node* project = new Node("projects", 3);
    Node* papers = new Node("papers", 1);
    Node* demos = new Node("demos", 1);

    papers->children.push_back(new Node("buylow", 26));
    papers->children.push_back(new Node("sellhigh", 55));

    demos->children.push_back(new Node("market", 47866));

    cs252->children.push_back(new Node("grades", 3));
    cs252->children.push_back(project);
    cs252->children.push_back(papers);
    cs252->children.push_back(demos);

    root->children.push_back(cs252);





    computeSize(root);
    printPreOrder(root);
    printPostOrder(root);
}
