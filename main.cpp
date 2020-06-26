#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
    int n = 15;
    int mass[15] = {25, 4, 20, 15, 50, 78, 90, 30, 35, 1, 98, 17, 80, 37, 85};

    Tree MyTree(mass, n);
    cout << "TreeTraversal: ";
    MyTree.TreeTraversal();
    cout << endl;
    MyTree.AddNode(200);
    cout << "AddNode(200): ";
    MyTree.TreeTraversal();
    cout << endl;
    cout <<"SearchMax = " << MyTree.SearchMax() << endl;
    MyTree.AddNode(0);
    cout << "AddNode (0): ";
    MyTree.TreeTraversal();
    cout << endl;
    cout <<"SearchMin = " << MyTree.SearchMin() << endl;
    MyTree.DeleteTree(200);
    cout << "DeleteTree(25): ";
    MyTree.TreeTraversal();
    cout << endl;
    cout <<"TreeSearch(25) = " << MyTree.TreeSearch(25) << endl;
    cout << "FatherFind(4) (father is 25) = " << MyTree.FatherFind(4) << endl;
    cout << "BalanceCheck = " <<  MyTree.BalanceCheck() << endl;
    cout << "Height = " << MyTree.Height() << endl;
    cout << "LayersTraversal: ";
    MyTree.LayersTraversal();
    cout << endl << "GOOOO:" << endl;
    MyTree.PrintV();

    return 0;
}