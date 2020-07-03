#include <iostream>
using namespace std;

class Node{

public:
    friend class  Tree;
    Node(int k=0);  //Конструктор по умолчанию
    Node(int *mass, int n);
    Node(Node &node);
    ~Node();
    void AddNode(int key);
    Node &operator = (const Node &Node);
    int SearchMax();
    int SearchMin();
    Node* DeleteNode(int value);
    void TreeTraversal();
    Node* NodeSearch(int key);
    Node* FatherFind(int value);
    bool BalanceCheck();
    int Height();
    Node* Delete_var_1();
    Node* Delete_var_2();
    Node* Add_Balance(int value);


    int balance = 0;
    int key;
    Node *left_child;
    Node *right_child;
    bool h;
};