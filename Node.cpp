#include "Node.h"

Node::Node() {
    key = NULL;
    right_child = nullptr;
    left_child = nullptr;
}

Node::
Node(int *mass, int n) {
    key = mass[0];
    right_child = nullptr;
    left_child = nullptr;
    for (int i = 1; i < n; i++) {
        this->AddNode(mass[i]);
        }
    }



void Node::AddNode(int value) {
//    cout << "1 - ";
//    this->TreeTraversal();
//    cout << endl;
//    cout << "this key = " << this->key << endl;
//    cout << value << endl;
//    cout << this;
    if (value < this->key) {
//        cout << "2 - ";
//        this->TreeTraversal();
//        cout << endl;
        if (this->left_child == nullptr){
            Node *node = new Node();
            node->key = value;
            node->right_child = nullptr;
            node->left_child = nullptr;
//            cout << "a2" << endl;
            this->left_child = node;
        }
        else if (this->left_child != nullptr){
//            cout << "b2" << endl;
            this->left_child->AddNode(value);
        }
    }
    else if (value > this->key) {
//        cout << "3 - ";
//        this->TreeTraversal();
//       cout << endl;
        if (this->right_child == nullptr) {
            Node *node = new Node();
            node->key = value;
            node->right_child = nullptr;
            node->left_child = nullptr;
//            cout << "a3" << endl;
            this->right_child = node;
        }
        else if (this->right_child != nullptr) {
//            cout <<"b3" << endl;
//            cout << "3(else) - ";
//            this->TreeTraversal();
//            cout << endl;
            this->right_child->AddNode(value);
        }
    }
}

Node::Node(Node &node) {
        this->key = node.key;
        if(node.left_child != nullptr) this->left_child = new Node(*node.left_child);
        else this->left_child = nullptr;
        if(node.right_child != nullptr) this->right_child = new class Node(*node.right_child);
        else this->right_child = nullptr;
    }

Node::~Node() {
    delete(this->left_child);
    delete(this->right_child);
}


Node &Node::operator=(const Node &Node) {
    this->key = Node.key;
    if(Node.left_child != nullptr) this->left_child = new class Node(*Node.left_child);
    else this->left_child = nullptr;
    if(Node.right_child != nullptr) this->right_child = new class Node(*Node.right_child);
    else this->right_child = nullptr;
    return *this;
}

int Node::SearchMax() {
    Node Max;
    Max = *this;
    while(Max.right_child != nullptr)Max = *(Max.right_child);
    int a = Max.key;
    return a;
}

Node *Node::NodeSearch(int value) {
    cout << "p1" << endl;
    Node* node;
    node = this;
    if(value > node->key && node->right_child != nullptr) {
        node = node->right_child;
        return node->NodeSearch(value);
    }
    else if(value < node->key && node->left_child != nullptr) {
        node = node->left_child;
        return node->NodeSearch(value);
    }
    else if(value == node->key) {
        return node;
    } else {
        cout << "non" << endl;
        return nullptr;
    }
}

int Node::SearchMin() {
    Node Min;
    Min = *this;
    while(Min.left_child != nullptr) Min = *(Min.left_child);
    int a = Min.key;
    return a;
}

void Node::TreeTraversal() {
    cout << key << " ";
    if (left_child != nullptr) {
   //     cout << "go left to " << left_child->key << endl;
        left_child->TreeTraversal();
    }
    if (right_child != nullptr) {
   //    cout << "gp right to " << right_child->key  << endl;
        right_child->TreeTraversal();
    }
  //  cout << "end" << endl;
}

Node *Node::FatherFind(int value) {
    Node *father;
    Node *son;
    son = this;
    while(son->key != value) {
        father = son;
        if(son->key > value)son = son->left_child;
        if(son->key < value)son = son->right_child;
        if(son->key == value) return father;
    }
}

bool Node::BalanceCheck() {
    int long_left = 0;
    int long_right = 0;
    if(this->left_child != nullptr) long_left = this->left_child->Height();
    if(this->right_child != nullptr) long_right = this->right_child->Height();
    bool is_this_balanced = true;
    if(abs(long_left - long_right) > 1) is_this_balanced = false;
    //cout << is_this_balanced << " " << this->key << " " << abs(long_left - long_right) << endl;
    bool is_left_balanced = true, is_right_balanced = true;
    if(this->left_child != nullptr) is_left_balanced = this->left_child->BalanceCheck();
    if(this->right_child != nullptr) is_right_balanced = this->right_child->BalanceCheck();
    return is_left_balanced && is_this_balanced && is_right_balanced;
}

int Node::Height() {
    int h_l = 0, h_r = 0;
    if(this->left_child != nullptr) h_l = this->left_child->Height();
    if(this->right_child != nullptr) h_r = this->right_child->Height();
    if(h_l > h_r) return h_l + 1;
    return h_r + 1;
}

Node *Node::DeleteNode(int value) {
    if(value > this->key){
        if(value == this->right_child->key){
            this->Delete_var_1();
        }
        else this->right_child->DeleteNode(value);
        return this;
    }
    else if(value < this->key) {
        if (value == this->left_child->key) this->Delete_var_2();
        else this->left_child->DeleteNode(value);
        return this;
    }
    return nullptr;
}

Node *Node::Delete_var_1() {
    Node *del_node = this->right_child, *sun = nullptr, *father = nullptr;
    if (del_node->left_child != nullptr) {
        sun = del_node->left_child;
        while (sun->right_child != nullptr) {
            father = sun;
            sun = sun->right_child;
        }
        if(father != nullptr) {
            father->right_child = sun->left_child;
            sun->right_child = del_node->right_child;
            sun->left_child = del_node->left_child;
            this->right_child = sun;
        }
        else {
            sun->right_child = del_node->right_child;
            this->left_child = sun;
        }
    }
    else if (del_node->right_child != nullptr) {
        this->right_child = del_node->right_child;
    }
    else {
        this->right_child = nullptr;
    }
    return this;
}

Node *Node::Delete_var_2() {
    Node *del_node = this->left_child, *sun = nullptr, *father = nullptr;
    if (del_node->left_child != nullptr) {
        sun = del_node->left_child;
        while (sun->right_child != nullptr) {
            father = sun;
            sun = sun->right_child;
        }
        if(father != nullptr) {
            father->right_child = sun->left_child;
            sun->right_child = del_node->right_child;
            sun->left_child = del_node->left_child;
            this->left_child = sun;
        }
        else {
            sun->right_child = del_node->right_child;
            this->left_child = sun;
        }
    }
    else if (del_node->right_child != nullptr) {
        this->left_child = del_node->right_child;
    }
    else this->left_child = nullptr;
    return this;
}
