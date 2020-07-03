#include "BalanceTree.h"

BalanceTree::BalanceTree(int *mass, int n) {
    root = nullptr;
    Node *node = new Node();
    node->key = mass[0];
    node->right_child = nullptr;
    node->left_child = nullptr;
    for(int i = 0; i < n; i++){
        bool h = true;
        root = Add_Balance(root, mass[i], h);
    }
}


Node* BalanceTree::Add_Balance(Node *p, int k, bool &h){
    cout << "p1" << endl;
    Node *s, *r;
    if(p==NULL){
        Node *p=new Node(k);
        return p;
    }
    if(k<=p->key){
        p->left_child=Add_Balance(p->left_child, k, h);
        if(h==false) return p;
        else{
            if(p->balance==1){
                p->balance=0;
                h=false;
                return p;
            }
            if(p->balance==0){
                p->balance=-1;
                return p;
            }
            if(p->balance==-1){
                p->balance=-2;
                s=p->left_child;
                if(s->balance==-1){
                    p->left_child=s->right_child;
                    s->right_child=p;
                    p->balance=0;
                    s->balance=0;
                    p=s;
                }
                else if(s->balance==1){
                    r=s->right_child;
                    s->right_child=r->left_child;
                    r->left_child=s;
                    p->left_child=r->right_child;
                    r->right_child=p;
                    if(r->balance==-1){
                        p->balance=1;
                        s->balance=0;
                    }
                    if(r->balance==1){
                        p->balance=0;
                        s->balance=-1;
                    }
                    if(r->balance==0) p->balance=s->balance=0;
                    r->balance=0;
                    p=r;
                }
                h=false;
                return p;
            }
        }
    }
    else{
        cout << "p2" << endl;
        p->right_child=Add_Balance(p->right_child, k, h);
        if(h==false) return p;
        else
        {
            if(p->balance==-1){
                p->balance=0;
                h=false;
                return p;
            }
            if(p->balance==0){
                p->balance=1;
                return p;
            }
            if(p->balance==1){
                p->balance=2;
                s=p->right_child;
                if(s->balance==1){
                    p->right_child=s->left_child;
                    s->left_child=p;
                    p->balance=0;
                    s->balance=0;
                    p=s;
                }
                else if(s->balance==-1){
                    r=s->left_child;
                    s->left_child=r->right_child;
                    r->right_child=s;
                    p->right_child=r->left_child;
                    r->left_child=p;
                    if(r->balance==1)
                    {
                        p->balance=-1;
                        s->balance=0;
                    }
                    if(r->balance==-1)
                    {
                        p->balance=0;
                        s->balance=1;
                    }
                    if(r->balance==0) p->balance=s->balance=0;
                    r->balance=0;
                    p=r;
                }
                h=false;
                return p;
            }
        }
    }
    return p;
}


