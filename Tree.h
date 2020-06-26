#include <iostream>
#include "Node.h"

using namespace std;

class Tree{
    Node *root;
    static void PrintV(Node *p, int l);

public:
    Tree();
    Tree(int *mass, int n);
    Tree(Tree &Tree);
    ~Tree();
    void AddNode(int key);
    Tree &operator = (const Tree &Tree);
    int SearchMax();
    int SearchMin();
    Node* DeleteTree(int value);
    void TreeTraversal();
    Node* TreeSearch(int key);
    Node* FatherFind(int value);
    bool BalanceCheck();
    int Height();
    void LayersTraversal();
    void PrintV();
};