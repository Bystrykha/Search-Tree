#include "Tree.h"
#include <queue>

Tree::Tree() {
    root = nullptr;
}

Tree::Tree(int *mass, int n) {
    root = nullptr;
    Node *node = new Node();
    node->key = mass[0];
    node->right_child = nullptr;
    node->left_child = nullptr;
    root = node;
    for(int i = 0; i < n; i++) root->AddNode(mass[i]);
}


Tree::Tree(Tree &tree) {
    root = new Node(*tree.root);
}

Tree::~Tree() {
    delete root;
}

void Tree::AddNode(int value) {
    if(root == nullptr) {
        root = new Node();
        root->key = value;
    }
    else{
        root->AddNode(value);
    }
}

Tree &Tree::operator=(const Tree &tree) {
    if (tree.root == nullptr) {
        root = nullptr;
    } else {
        root = new Node(*tree.root);
    }
}

int Tree::SearchMax() {
    if(root == nullptr) {
        return NULL;
    }
    return root->SearchMax();
}

int Tree::SearchMin() {
    if(root == nullptr) {
        return NULL;
    }
    return root->SearchMin();
}

Node* Tree::DeleteTree(int value) {
    if(root->key == value){
        if(root->right_child != nullptr && root->left_child != nullptr){
            Node *father, *sun;
            father = root;
            sun = father->right_child;
            while(sun->left_child != nullptr){
                father = sun;
                sun = sun->left_child;
            }
            if(father != root) {
                father->left_child = sun->right_child;
                sun->left_child = root->left_child;
                sun->right_child = root->right_child;
                root = sun;
                root->TreeTraversal();
            }
            if(father == root){
                sun->left_child = root->left_child;
                sun->right_child = nullptr;
                root = sun;
            }
        }
        if(root->right_child == nullptr && root->left_child != nullptr)root = root->left_child;
        if(root->left_child == nullptr && root->right_child != nullptr)root = root->right_child;
        if(root->right_child == nullptr && root->left_child == nullptr)root = nullptr;
        return root;
    }
    else return root->DeleteNode(value);
}

void Tree::TreeTraversal() {
    if (root != nullptr) {
        root -> TreeTraversal();
    }
}

Node* Tree::TreeSearch(int key) {
    if(root == nullptr) return nullptr;
    else{
        return root -> NodeSearch(key);
    }
}

Node *Tree::FatherFind(int value) {
    if(root->key == value) return nullptr;
    else return root->FatherFind(value);
}

bool Tree::BalanceCheck() {
    root->BalanceCheck();
}

int Tree::Height() {
    return root -> Height();
}

void Tree::LayersTraversal() {
    Node past;
    queue <Node*> layers;
    layers.push(root);
    while (!layers.empty()){
        if(layers.front()->left_child != nullptr) layers.push(layers.front()->left_child);
        if(layers.front()->right_child != nullptr) layers.push(layers.front()->right_child);
        cout << layers.front()->key << " ";
        layers.pop();
    }
}
