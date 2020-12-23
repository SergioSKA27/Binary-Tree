#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

template <class type>
class Node
{
private:
    type Data;

public:
    Node<type> *left;
    Node<type> *rigth;

    Node(type Data);
    Node();
    Node<type> &changedata(type data);
    type getdata();
    void showdata();
    Node<type> &operator=(const Node<type> &node);
    ~Node();
};

template <class type>
Node<type>::Node(type Data)
{
    this->Data = Data;
    this->left = NULL;
    this->rigth = NULL;
}

template <class type>
Node<type>::Node()
{
    this->left = NULL;
    this->rigth = NULL;
}

template <class type>
Node<type> &Node<type>::changedata(type newdata)
{
    Data = newdata;
    return *this;
}

template <class type>
type Node<type>::getdata()
{
    return this->Data;
}

template <class type>
void Node<type>::showdata()
{
    std::cout << this->Data << std::endl;
}

template <class type>
Node<type> &Node<type>::operator=(const Node<type> &node2)
{
    this->Data = node2.Data;
    this->left = node2.left;
    this->rigth = node2.rigth;
    return *this;
}

template <class type>
Node<type>::~Node()
{
}

template <class Type>
class Binary_tree
{
private:
    Node<Type> Root; //raiz del arbol
    Node<Type> *nodes;
    int nods;
    int levels;
    int leafs;
    bool emptystate;
    std::vector<Type> inorder;

public:
    //Costructores
    Binary_tree(Type Data);
    Binary_tree();
    //Insertar nodos(raiz e hijos)
    Binary_tree<Type> &setroot(type Data);                 //Cambiar el dato en la raiz.
    Binary_tree<Type> &insertleft(Nodea<Type>, type Data); //Insertar hijo izq.
    Binary_tree<Type> &insertrigth(Node<Type>, type Data); //Insertar hijo derecho.
    //Verificar si el arbol es(vacio, completo o lleno)
    bool empty();    //Verificar si el arbol esta vacio
    bool full();     //Verificar si esta lleno
    bool complete(); //Verificar si esta completo
    //Datos del arbol
    int countnodes();  //retorna el numero de nodos del arbol
    int countlevels(); //retorna el numero de niveles de el arbol
    int countleafs();  //retorna el numero de hojas del arbol

    //Funciones de impresion
    void printtree();                       //Imprimir el arbol completo
    void print_subtree(Node<Type> Subtree); // seleccionar un nodo e imprimir su arbol de decendientes

    ~Binary_tree();
};

template <class Type>
Binary_tree<Type>::Binary_tree(Type Data)
{
    this->Root.changedata(Data);
    this->nodes = NULL;
    this->leafs = 0;
    this->levels = 1;
    this->nods = 1;
}
template <class Type>
Binary_tree<Type>::Binary_tree()
{
    this->nodes = NULL;
    this->leafs = 0;
    this->levels = 0;
    this->nods = 0;
}
template <class Type>
Binary_tree<Type>::Binary_tree(Type Data)
{
}
template <class Type>
Binary_tree<Type>::Binary_tree(Type Data)
{
}
template <class Type>
Binary_tree<Type>::Binary_tree(Type Data)
{
}
template <class Type>
Binary_tree<Type>::Binary_tree(Type Data)
{
}
template <class Type>
Binary_tree<Type>::Binary_tree(Type Data)
{
}
template <class Type>
Binary_tree<Type>::Binary_tree(Type Data)
{
}
template <class Type>
Binary_tree<Type>::Binary_tree(Type Data)
{
}
Binary_tree::~Binary_tree()
{
}

int main(int argc, char const *argv[])
{

    return 0;
}
