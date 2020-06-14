#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
    int n = 15, a;
    //cin >> n;
    int mass[15] = {25, 4, 20, 15, 50, 78, 90, 30, 35, 1, 98, 17, 80, 37, 85};


//    for(int i = 0; i < n; i++) {
//        cin >> a;
//        mass = [25, 4 20 15 50 78 90 30 35 1 98 17 80 37 85];
//    }
    Tree MyTree(mass, n);
    MyTree.TreeTraversal();
    cout << endl;
//    MyTree.AddNode(200);
//    MyTree.TreeTraversal();
//    cout << endl;
//    cout <<"SearchMax = " << MyTree.SearchMax() << endl;
//    MyTree.AddNode(0);
//    MyTree.TreeTraversal();
//    cout << endl;
//    cout <<"SearchMin = " << MyTree.SearchMin() << endl;
//    MyTree.DeleteTree(89);
//    MyTree.TreeTraversal();
//    cout << endl;
//    cout <<"NodeSearch() = " << MyTree.TreeSearch(25) << endl;
//    MyTree.TreeSearch(800);
//    cout << "FatherFind(35) = " << MyTree.FatherFind(4) << endl;
//    cout << "BalanceCheck = " <<  MyTree.BalanceCheck() << endl;
//    cout << "Height = " << MyTree.Height() << endl;
    MyTree.LayersTraversal();
    return 0;
}

//15

//25 4 20 15 50 78 90 30 35 1 98 17 80 37 85 /15

//63 28 54 70 52 98 17 3 21 75 68 82 69 9 191 /15

