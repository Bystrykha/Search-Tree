#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
    int n = 12;
    int mass[12] = {25, 4, 20, 15, 50, 78, 90, 1, 98, 17, 80, 85};

    Tree MyTree(mass, n);
    cout << "TreeTraversal: ";
    MyTree.TreeTraversal();
    cout << endl;
//    MyTree.AddNode(200);
//    cout << "AddNode(200): ";
//    MyTree.TreeTraversal();
//    cout << endl;
//    cout <<"SearchMax = " << MyTree.SearchMax() << endl;
//    MyTree.AddNode(0);
//    cout << "AddNode (0): ";
//    MyTree.TreeTraversal();
//    cout << endl;
//    cout <<"SearchMin = " << MyTree.SearchMin() << endl;
    MyTree.DeleteTree(25);
    cout << "DeleteTree(25): ";
    MyTree.TreeTraversal();
//    cout << endl;
//    cout <<"TreeSearch(25) = " << MyTree.TreeSearch(25) << endl;
//    cout <<"FatherFind result is: ";
//    cout << MyTree.FatherFind(1231254) << endl; /// такого узла в дереве нет
//    cout << "BalanceCheck = " <<  MyTree.BalanceCheck() << endl;
//    cout << "Height = " << MyTree.Height() << endl;
//    cout << "LayersTraversal: ";
//    MyTree.LayersTraversal();
//    cout << endl << "GOOOO:" << endl;
//    MyTree.PrintV();

    return 0;
}