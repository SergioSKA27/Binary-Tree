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

    //Inserta un la data en un nodo especifico
    void insert_node(Node<T> *node, T data);

public:
    BinaryTree();
    void insert(T data); //inserta un elemento al arbol

    void print_tree();
    T minimo();
    T max();
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
