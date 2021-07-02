#include <bits/stdc++.h>

/*Esta implementacion sigue unicamente los principios basicos para elaborar un arbol
    binario, esto quiere decir que las alturas de dichos pueden variar de acuerdo a 
    como dichos elementos sean introduciodos, por lo que no se garantiza una altura 
    constante(vease AVL o RedBlack tree).
*/

template <class type>
class Node
{
public:
    type Data;
    Node<type> *father;
    Node<type> *rigth;
    Node<type> *left;

    short visited;

    Node(type Data);

    friend std::ostream &operator<<(std::ostream &o, const Node<type> &N)
    {
        o << N.Data;
        return o;
    }
    ~Node();
};

template <class type>
Node<type>::Node(type Data)
{
    this->Data = Data;
    this->father = nullptr;
    this->rigth = nullptr;
    this->left = nullptr;
    this->visited = 1;
}

template <class type>
Node<type>::~Node()
{
}

template <class T>
class BinaryTree
{
private:
    Node<T> *nodes; //variable para crear los nodos del arbol
    Node<T> *root;  //nodo raiz
    size_t _size;

    void insert_node(Node<T> *node, T data); //Inserta un la data en un nodo especifico

    void in_ord(Node<T> *node, std::vector<T> &v);   //realiza el recorrido in order sobre algun nodo y guarda los datos en un vector
    void pre_ord(Node<T> *node, std::vector<T> &v);  //realiza el recorrido pre order sobre algun nodo y guarda los datos en un vector
    void post_ord(Node<T> *node, std::vector<T> &v); //realiza el recorrido post order sobre algun nodo y guarda los datos en un vector

    T _min(Node<T> *node); // retorna el minimo elemento de un sub arbol
    T _max(Node<T> *node); //retorna el maximo elemento de un sub arbol

    void del(Node<T> *node); //elimina un nodo y todo su arbol de descendientes

public:
    BinaryTree();
    BinaryTree(std::vector<T> &v); //inicializa el arbol con los elementos de un vector

    void insert(T data); //inserta un elemento al arbol

    T minimo(); //retorna el elemento minimo
    T max();    //retorna el elemento maximo

    void clear(); //elimina todos los elementos del arbol

    std::vector<T> in_order();   //retorna un vector con el recorrido in order
    std::vector<T> pre_order();  //retorna un vector con el recorrido in order
    std::vector<T> post_order(); //retorna un vector con el recorrido in order

    void print_tree();

    Node<T> *begin(); //retorna un puntero a la raiz de arbol
    Node<T> *end();   //retorna un puntero nulo

    ~BinaryTree();
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    this->root = nullptr;
    this->nodes = nullptr;
    this->_size = 0;
}

template <class T>
BinaryTree<T>::BinaryTree(std::vector<T> &v)
{
    this->root = nullptr;
    this->nodes = nullptr;
    this->_size = 0;

    for (auto i : v)
    {
        this->insert(i);
    }
}

template <class T>
void BinaryTree<T>::insert(T data)
{
    if (this->root == nullptr)
    {
        this->nodes = new Node<T>(data);
        this->root = this->nodes;
    }
    else
    {
        this->insert_node(this->root, data);
    }

    this->_size += 1;
}

template <class T>
void BinaryTree<T>::insert_node(Node<T> *node, T data)
{
    if (data < node->Data)
    {
        if (node->left == nullptr)
        {
            this->nodes = new Node<T>(data);
            node->left = this->nodes;
            this->nodes->father = node;
        }
        else
        {
            this->insert_node(node->left, data);
        }
    }
    else
    {
        if (node->rigth == nullptr)
        {
            this->nodes = new Node<T>(data);
            node->rigth = this->nodes;
            this->nodes->father = node;
        }
        else
        {
            this->insert_node(node->rigth, data);
        }
    }
}

template <class T>
T BinaryTree<T>::minimo()
{
    Node<T> *itr;
    T min;
    if (this->root == nullptr)
        throw std::out_of_range("Tree is empty!");
    itr = this->root;
    while (itr)
    {
        min = itr->Data;
        itr = itr->left;
    }
    return min;
}

template <class T>
T BinaryTree<T>::_min(Node<T> *node)
{
    Node<T> *itr;
    T min;
    if (this->root == nullptr)
        throw std::out_of_range("Tree is empty!");
    itr = node;
    while (itr)
    {
        min = itr->Data;
        itr = itr->left;
    }
    return min;
}

template <class T>
T BinaryTree<T>::max()
{
    Node<T> *itr;
    T m;
    if (this->root == nullptr)
        throw std::out_of_range("Tree is empty!");
    itr = this->root;
    while (itr)
    {
        m = itr->Data;
        itr = itr->rigth;
    }
    return m;
}

template <class T>
T BinaryTree<T>::_max(Node<T> *node)
{
    Node<T> *itr;
    T m;
    if (this->root == nullptr)
        throw std::out_of_range("Tree is empty!");
    itr = node;
    while (itr)
    {
        m = itr->Data;
        itr = itr->rigth;
    }
    return m;
}

template <class T>
void BinaryTree<T>::pre_ord(Node<T> *node, std::vector<T> &v)
{
    if (node == nullptr)
        return;

    v.push_back(node->Data);
    pre_ord(node->left);
    pre_ord(node->rigth);
}

template <class T>
void BinaryTree<T>::in_ord(Node<T> *node, std::vector<T> &v)
{
    if (node == nullptr)
        return;

    pre_ord(node->left);
    v.push_back(node->Data);
    pre_ord(node->rigth);
}

template <class T>
void BinaryTree<T>::post_ord(Node<T> *node, std::vector<T> &v)
{
    if (node == nullptr)
        return;

    pre_ord(node->left);
    pre_ord(node->rigth);
    v.push_back(node->Data);
}

template <class T>
std::vector<T> BinaryTree<T>::pre_order()
{
    if (this->root == nullptr)
        throw std::out_of_range("Tree is empty!");
    std::vector<T> pre;
    this->pre_ord(this->root, pre);
    return pre;
}

template <class T>
std::vector<T> BinaryTree<T>::in_order()
{
    if (this->root == nullptr)
        throw std::out_of_range("Tree is empty!");
    std::vector<T> in;
    this->in_ord(this->root, in);
    return in;
}

template <class T>
std::vector<T> BinaryTree<T>::post_order()
{
    if (this->root == nullptr)
        throw std::out_of_range("Tree is empty!");
    std::vector<T> post;
    this->post_ord(this->root, post);
    return post;
}

template <class T>
void BinaryTree<T>::print_tree()
{
    int ady = 1, sz = this->_size;
    bool p_tab = true;
    Node<T> *itr = this->root;
    std::queue<Node<T> *> Q;

    itr->visited = 2;
    Q.push(itr);

    while (!Q.empty())
    {
        Node<T> *current = Q.front();
        Q.pop();

        if (ady != 0)
        {
            ady--;
        }
        if (p_tab)
        {
            for (size_t i = 0; i < sz; i++)
            {
                std::cout << "\t";
            }
        }
        p_tab = false;

        if (current->left != nullptr && current->left->visited == 1)
        {
            Q.push(current->left);
            current->left->visited = 2;
        }

        if (current->rigth != nullptr && current->rigth->visited == 1)
        {
            Q.push(current->rigth);
            current->rigth->visited = 2;
        }

        current->visited = 3;
        std::cout << current->Data << " \t\t";
        if (ady == 0)
        {
            std::cout << std::endl;
            ady = Q.size();
            sz -= 1;
            p_tab = true;
        }
    }
}

template <class T>
Node<T> *BinaryTree<T>::begin()
{
    return this->root;
}

template <class T>
Node<T> *BinaryTree<T>::end()
{
    return nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
}

int main(int argc, char const *argv[])
{

    BinaryTree<int> A;

    A.insert(10);
    //A.print_tree();

    A.insert(9);
    A.insert(12);
    A.insert(15);
    A.insert(25);
    A.insert(45);
    A.insert(4);
    A.insert(1);
    A.insert(100);

    std::cout << A.max() << std::endl;
    //A.print_tree();

    return 0;
}
