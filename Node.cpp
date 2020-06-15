#include "Node.h"

Node::Node() {  ///конструктор без аргументов
    key = NULL;
    right_child = nullptr;
    left_child = nullptr;
}

Node::
Node(int *mass, int n) {    /// конструктор, принимает массив элементов, из которых строится дерево и их кол-во
    key = mass[0];
    right_child = nullptr;
    left_child = nullptr;
    for (int i = 1; i < n; i++) {
        this->AddNode(mass[i]);
        }
    }



void Node::AddNode(int value) {     /// добавление узла в дерево
    if (value < this->key) {    /// если ключ добавляемого узла больше чем ключ текущего
        if (this->left_child == nullptr){   /// добавляем узел
            Node *node = new Node();
            node->key = value;
            node->right_child = nullptr;
            node->left_child = nullptr;
            this->left_child = node;
        }
        else if (this->left_child != nullptr){  ///ищем отца для добавляемого узла
            this->left_child->AddNode(value);
        }
    }
    else if (value > this->key) {   /// то же самое, только ключ узла меньше текущего
        if (this->right_child == nullptr) {
            Node *node = new Node();
            node->key = value;
            node->right_child = nullptr;
            node->left_child = nullptr;
            this->right_child = node;
        }
        else if (this->right_child != nullptr) {
            this->right_child->AddNode(value);
        }
    }
}

Node::Node(Node &node) {        /// конструктор копирования
        this->key = node.key;
        if(node.left_child != nullptr) this->left_child = new Node(*node.left_child);
        else this->left_child = nullptr;
        if(node.right_child != nullptr) this->right_child = new class Node(*node.right_child);
        else this->right_child = nullptr;
    }

Node::~Node() {     /// диструктор
    delete(this->left_child);
    delete(this->right_child);
}


Node &Node::operator=(const Node &Node) {   ///
    this->key = Node.key;
    if(Node.left_child != nullptr) this->left_child = new class Node(*Node.left_child);
    else this->left_child = nullptr;
    if(Node.right_child != nullptr) this->right_child = new class Node(*Node.right_child);
    else this->right_child = nullptr;
    return *this;
}

int Node::SearchMax() {     /// нахождение узла с максимальным значением ключа
    Node Max;
    Max = *this;
    while(Max.right_child != nullptr)Max = *(Max.right_child); /// идем максимально вправо
    int a = Max.key;
    return a;
}

Node *Node::NodeSearch(int value) {     /// поиск узла по ключу
    cout << "p1" << endl;
    Node* node;
    node = this;
    if(value > node->key && node->right_child != nullptr) { /// если колч искомого узла больше текущего и нам есть где искать
        node = node->right_child;
        return node->NodeSearch(value);
    }
    else if(value < node->key && node->left_child != nullptr) { /// то же самое, только ключ искомого меньше текущего
        node = node->left_child;
        return node->NodeSearch(value);
    }
    else if(value == node->key) {   /// нашли
        return node;
    } else {    /// не нашли и искать негде
        cout << "non" << endl;
        return nullptr;
    }
}

int Node::SearchMin() {     /// поиск узла с минимальным значением узла
    Node Min;
    Min = *this;
    while(Min.left_child != nullptr) Min = *(Min.left_child); /// идем максимально влево
    int a = Min.key;
    return a;
}

void Node::TreeTraversal() {       /// обход дерева КЛП
    cout << key << " ";
    if (left_child != nullptr) {
        left_child->TreeTraversal();
    }
    if (right_child != nullptr) {
        right_child->TreeTraversal();
    }
}

Node *Node::FatherFind(int value) {     /// нахожение отца узла
    Node *father;
    Node *son;
    son = this;
    while(son->key != value) {  /// ищем узел по ключу, записывая в father его предка
        father = son;
        if(son->key > value)son = son->left_child;
        if(son->key < value)son = son->right_child;
        if(son->key == value) return father;
    }
}

bool Node::BalanceCheck() {     /// проверка на сбалансированность
    int long_left = 0;  /// проверяем сбалансированность узла через определение высот его левого и правого поддеревьев
    int long_right = 0;
    if(this->left_child != nullptr) long_left = this->left_child->Height();
    if(this->right_child != nullptr) long_right = this->right_child->Height();
    bool is_this_balanced = true;
    if(abs(long_left - long_right) > 1) is_this_balanced = false;
    bool is_left_balanced = true, is_right_balanced = true;
    if(this->left_child != nullptr) is_left_balanced = this->left_child->BalanceCheck();
    if(this->right_child != nullptr) is_right_balanced = this->right_child->BalanceCheck();
    return is_left_balanced && is_this_balanced && is_right_balanced;
}

int Node::Height() {        /// определение высоты дерева
    int h_l = 0, h_r = 0;   /// просто идем, пока не упремся в самый дальний лист
    if(this->left_child != nullptr) h_l = this->left_child->Height();
    if(this->right_child != nullptr) h_r = this->right_child->Height();
    if(h_l > h_r) return h_l + 1;
    return h_r + 1;
}

Node *Node::DeleteNode(int value) {     /// удаление узла дерева
    if(value > this->key){
        if(value == this->right_child->key) this->Delete_var_1();       /// метод для удаления узла справа от его отца
        else this->right_child->DeleteNode(value);
        return this;
    }
    else if(value < this->key) {
        if (value == this->left_child->key) this->Delete_var_2(); /// метод для удаления узла слева от его отца
        else this->left_child->DeleteNode(value);
        return this;
    }
    return nullptr;
}

Node *Node::Delete_var_1() {    ///правый потомок узла - удаляемый узел
    Node *del_node = this->right_child, *sun = nullptr, *father = nullptr;
    if (del_node->left_child != nullptr) {  /// если поддерево состоит не только из удаляемого узла
        sun = del_node->left_child; /// находим максимальный элемент в левом поддереве и ставим его на место удаляемого узля
        while (sun->right_child != nullptr) {
            father = sun;
            sun = sun->right_child;
        }
        if(father != nullptr) { ///см. RootDelete, работают аналогично
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
    else {  /// если у удаляемого узла нет девого поддерева
        this->right_child = nullptr;
    }
    return this;
}

Node *Node::Delete_var_2() {    /// аналогичео Delete_var_1()
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
