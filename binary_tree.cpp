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
    Node<type> *father;
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
    this->father = NULL;
    this->left = NULL;
    this->rigth = NULL;
}

template <class type>
Node<type>::Node()
{
    this->father = NULL;
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
    Node<Type> Root;           //Raiz del arbol
    Node<Type> *nodes;         //Variable para crear los nodos
    int nods;                  //Numero de nodos del arbol
    int levels;                //Niveles del arbol
    int leafs;                 //Hojas del arbol
    bool emptystate;           //Ver si el arbol esta vacio
    std::vector<Type> inorder; //Vector para recorrido in order

public:
    //Costructores
    Binary_tree(Type Data);
    Binary_tree();

    //Insertar nodos(raiz e hijos)
    Binary_tree<Type> &setroot(Type Data);                  //Cambiar el dato en la raiz.
    Node<Type> *insertleft(Node<Type> *Father, Type Data);  //Insertar hijo izq. y retorna un puntero al nodo insertado.
    Node<Type> *insertrigth(Node<Type> *Father, Type Data); //Insertar hijo derecho y retorna un puntero al nodo insertado.
    Node<Type> *insertleft(Type Data);                      //Insertar hijo izq. en la raiz y retorna un puntero al nodo insertado.
    Node<Type> *insertrigth(Type Data);                     //Insertar hijo derecho en la raiz y retorna un puntero al nodo insertado.

    //Metodos de acceso
    Node<Type> *root();
    std::vector<Type> in_order();
    std::vector<Type> pre_order();
    std::vector<Type> post_order();

    //Verificar si el arbol es(vacio, completo o lleno)
    bool empty();    //Verificar si el arbol esta vacio
    bool full();     //Verificar si esta lleno
    bool complete(); //Verificar si esta completo

    //Datos del arbol
    int countnodes();  //retorna el numero de nodos del arbol
    int countlevels(); //retorna el numero de niveles de el arbol
    int countleafs();  //retorna el numero de hojas del arbol

    //Funciones de impresion
    void showroot();
    void printtree();                        //Imprimir el arbol completo
    void print_subtree(Node<Type> *Subtree); // seleccionar un nodo e imprimir su arbol de decendientes

    ~Binary_tree();
};
//Iniciar el arbol con un nodo raiz
template <class Type>
Binary_tree<Type>::Binary_tree(Type Data)
{
    this->Root.changedata(Data);
    this->nodes = NULL;
    this->leafs = 0;
    this->levels = 1;
    this->nods = 1;
    this->emptystate = false;
}
//Constructor vacio
template <class Type>
Binary_tree<Type>::Binary_tree()
{
    this->nodes = NULL;
    this->leafs = 0;
    this->levels = 0;
    this->nods = 0;
    this->emptystate = true;
}

template <class Type>
Binary_tree<Type> &Binary_tree<Type>::setroot(Type Data)
{
    Root.changedata(Data);
    emptystate = false;
    nods = 0;
    return *this;
}

template <class Type>
Node<Type> *Binary_tree<Type>::insertleft(Node<Type> *Father, Type Data)
{
    if (this->emptystate)
        throw std::bad_alloc(); //si el el arbol no tine raiz

    this->nodes = new Node<Type>();
    this->nodes->changedata(Data);
    Father->left = this->nodes;
    this->nodes->father = Father;
    this->nods += 1;

    return this->nodes;
}

template <class Type>
Node<Type> *Binary_tree<Type>::insertrigth(Node<Type> *Father, Type Data)
{
    if (this->emptystate)
        throw std::bad_alloc(); //si el el arbol no tine raiz

    this->nodes = new Node<Type>();
    this->nodes->changedata(Data);
    Father->rigth = this->nodes;
    this->nodes->father = Father;
    this->nods += 1;

    return this->nodes;
}

template <class Type>
Node<Type> *Binary_tree<Type>::insertleft(Type Data)
{
    if (this->emptystate)
        throw std::bad_alloc(); //si el el arbol no tine raiz

    this->nodes = new Node<Type>();
    this->nodes->changedata(Data);
    this->Root.left = this->nodes;
    this->nodes->father = &this->Root;
    this->nods += 1;

    return this->nodes;
}

template <class Type>
Node<Type> *Binary_tree<Type>::insertrigth(Type Data)
{
    if (this->emptystate)
        throw std::bad_alloc(); //si el el arbol no tine raiz

    this->nodes = new Node<Type>();
    this->nodes->changedata(Data);
    this->Root.rigth = this->nodes;
    this->nodes->father = &this->Root;
    this->nods += 1;

    return this->nodes;
}

template <class Type>
Node<Type> *Binary_tree<Type>::root()
{
    return &this->Root;
}

/*
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
}*/
template <class Type>
void Binary_tree<Type>::showroot()
{
    std::cout << this->Root.getdata() << std::endl;
}

template <class Type>
Binary_tree<Type>::~Binary_tree()
{
}

int main(int argc, char const *argv[])
{
    Binary_tree<int> BIN(10);
    Node<int> *N;
    BIN.setroot(100);
    BIN.showroot();
    BIN.insertleft(BIN.root(), 10);
    BIN.insertrigth(BIN.root(), 1);
    BIN.root()->left->showdata();

    return 0;
}
