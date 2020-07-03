#include <iostream>
//#include "Tree.h"
#include "BalanceTree.h"

using namespace std;

int main() {
    int n = 13;
    int mass[13] = {25, 4, 20, 15, 50, 78, 60, 90, 1, 98, 17, 80, 85};
    Tree tree_ex(mass, n);
    tree_ex.PrintV();
    cout << endl << "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ" << endl;
    BalanceTree tree(mass, n);
    tree.PrintV();
    return 0;
}

