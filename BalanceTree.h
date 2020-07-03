//#include "Node.h"
#include "Tree.h"

using namespace std;

class BalanceTree: public Tree{

public:
    BalanceTree(int *mass, int n);
    Node* Add_Balance(Node *p, int k, bool &h);
};

