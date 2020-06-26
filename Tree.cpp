#include "Tree.h"
#include <queue>

Tree::Tree() {      /// конструктор без аргументов
    root = nullptr;
}

Tree::Tree(int *mass, int n) {  /// конструктор, принимает массив элементов, из которых строится дерево и их кол-во
    root = nullptr;
    Node *node = new Node();
    node->key = mass[0];
    node->right_child = nullptr;
    node->left_child = nullptr;
    root = node;
    for(int i = 0; i < n; i++) root->AddNode(mass[i]);
}


Tree::Tree(Tree &tree) {      /// конструктор копирования
    root = new Node(*tree.root);
}

Tree::~Tree() {     /// диструктор
    delete root;
}

void Tree::AddNode(int value) {     /// добавление узла в дерево
    if(root == nullptr) {
        root = new Node();
        root->key = value;
    }
    else{
        root->AddNode(value);
    }
}

Tree &Tree::operator=(const Tree &tree) {   ///
    if (tree.root == nullptr) {
        root = nullptr;
    } else {
        root = new Node(*tree.root);
    }
}

int Tree::SearchMax() {     /// нахождение узла с максимальным значением ключа
    if(root == nullptr) {
        return NULL;
    }
    return root->SearchMax();
}

int Tree::SearchMin() {     /// поиск узла с минимальным значением узла
    if(root == nullptr) {
        return NULL;
    }
    return root->SearchMin();
}

Node* Tree::DeleteTree(int value) {
    if(root->key == value){     /// если удаляем корень всего дерева
        if(root->right_child != nullptr && root->left_child != nullptr){    ///если есть правое и левое поддеревья, на место корня ставим наименьший элемент правого поддерева
            Node *father, *sun;
            father = root;
            sun = father->right_child;
            while(sun->left_child != nullptr){      /// поиск наибольшего узла поддерева
                father = sun;
                sun = sun->left_child;
            }
            if(father != root) {        /// если левое поддерево состоит более, чем из одного узла
                father->left_child = sun->right_child;
                sun->left_child = root->left_child;
                sun->right_child = root->right_child;
                root->left_child = nullptr;         /// отчистка памяти
                root->right_child = nullptr;
                delete(root);
                root = sun;
            }
            if(father == root){     /// если правое поддерево состоит из одного узла
                sun->left_child = root->left_child;    /// без этого условия получалость, что новый корень содержал ссылку на самого себя в left_child
                sun->right_child = nullptr;
                root->left_child = nullptr;         /// отчистка памяти
                root->right_child = nullptr;
                delete(root);
                root = sun;
            }
        }
        else if(root->right_child == nullptr && root->left_child != nullptr){    /// если нет правого поддерева, то просто обозначаем за корень правый узел
            Node *sun;
            sun = root->left_child;
            root->left_child = nullptr;         /// отчистка памяти
            delete(root);
            root = sun;
        }
        else if(root->left_child == nullptr && root->right_child != nullptr){    /// аналогично верхнему
            Node *sun;
            sun = root->right_child;
            root->right_child = nullptr;         /// отчистка памяти
            delete(root);
            root = sun;
        }
        else if(root->right_child == nullptr && root->left_child == nullptr){/// если у корня нет потомков, просто удаляем его
            root = nullptr;
        }
        return root;
    }
    else return root->DeleteNode(value);    /// если удаляемый узел не является корнем всего дерева
}

void Tree::TreeTraversal() {        /// обход дерева КЛП
    if (root != nullptr) {
        root -> TreeTraversal();
    }
}

Node* Tree::TreeSearch(int key) {       /// поиск узла по ключу
    if(root == nullptr) return nullptr;
    else{
        return root -> NodeSearch(key);
    }
}

Node *Tree::FatherFind(int value) {     /// поиск отца по ключу узла
    if(root->key == value) return nullptr;
    else return root->FatherFind(value);
}

bool Tree::BalanceCheck() {     /// проверка на сбалансированность
    root->BalanceCheck();
}

int Tree::Height() {        /// определение высоты дерева
    return root -> Height();
}

void Tree::LayersTraversal() {      /// обход дерева по слоям
    Node past;      /// создал очредь, заношу туда корень, потом потомков
    queue <Node*> layers;
    layers.push(root);
    while (!layers.empty()){
        if(layers.front()->left_child != nullptr) layers.push(layers.front()->left_child);
        if(layers.front()->right_child != nullptr) layers.push(layers.front()->right_child);
        cout << layers.front()->key << " ";
        layers.pop();
    }
}

void Tree::PrintV(Node *p, int l) {
    if (p == nullptr) return;
    PrintV(p->right_child, l + 3);
    for(int k = 0; k < l; k++) cout << " ";
    cout.width(2);
    cout << p->key << endl;
    PrintV(p->left_child, l + 3);
}

void Tree::PrintV() {
    PrintV(root, 0);
}
