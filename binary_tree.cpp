#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
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
    Node<Type> *Root;  //Raiz del arbol
    Node<Type> *nodes; //Variable para crear los nodos
    int nods;          //Numero de nodos del arbol
    int levels;        //Niveles del arbol
    int leafs;         //Hojas del arbol
    bool emptystate;   //Ver si el arbol esta vacio

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
    void in_order(Node<Type> *nde, std::vector<Type> &list);   //recibe un nodo y un vector retorna el recorrido in order en el vector seleccionado
    void pre_order(Node<Type> *nde, std::vector<Type> &list);  //recibe un nodo y un vector retorna el recorrido pre order en el vector seleccionado
    void post_order(Node<Type> *nde, std::vector<Type> &list); //recibe un nodo y un vector retorna el recorrido post order en el vector seleccionado

    //Verificar si el arbol es(vacio, completo o lleno)
    bool empty();    //Verificar si el arbol esta vacio
    bool full();     //Verificar si esta lleno
    bool complete(); //Verificar si esta completo

    //Datos del arbol
    int countnodes();                //retorna el numero de nodos del arbol
    int countlevels();               //retorna el numero de niveles de el arbol
    int countleafs(Node<Type> *nde); //retorna el numero de hojas del arbol o sub-arbol
    int countleafs();                //retorna el numero de hojas del arbol o sub-arbol

    //Funciones de impresion
    void showroot();
    void printtree();                        //Imprimir el arbol completo
    void print_subtree(Node<Type> *Subtree); // seleccionar un nodo e imprimir su arbol de decendientes

    //Funciones de borrado
    void prune(Node<Type> *nde); //Elimina el nodo y todo su arbol de descendientes

    ~Binary_tree();
};
//Iniciar el arbol con un nodo raiz
template <class Type>
Binary_tree<Type>::Binary_tree(Type Data)
{
    this->Root = new Node<Type>(Data);
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
    this->Root = NULL;
    this->nodes = NULL;
    this->leafs = 0;
    this->levels = 0;
    this->nods = 0;
    this->emptystate = true;
}

template <class Type>
Binary_tree<Type> &Binary_tree<Type>::setroot(Type Data)
{
    if (this->Root == NULL)
        this->Root = new Node<Type>(Data);
    Root->changedata(Data);
    emptystate = false;
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
    this->Root->left = this->nodes;
    this->nodes->father = this->Root;
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
    this->Root->rigth = this->nodes;
    this->nodes->father = this->Root;
    this->nods += 1;

    return this->nodes;
}

template <class Type>
Node<Type> *Binary_tree<Type>::root()
{
    return this->Root;
}

template <class Type>
void Binary_tree<Type>::in_order(Node<Type> *nde, std::vector<Type> &list)
{
    if (this->emptystate)
        throw std::invalid_argument("Tree is empty");

    if (nde == NULL)
        return;
    else
    {
        this->in_order(nde->left, list);
        list.push_back(nde->getdata());
        this->in_order(nde->rigth, list);
    }
}

template <class Type>
void Binary_tree<Type>::post_order(Node<Type> *nde, std::vector<Type> &list)
{
    if (this->emptystate)
        throw std::invalid_argument("Tree is empty");

    if (nde == NULL)
        return;
    else
    {
        this->in_order(nde->left, list);
        this->in_order(nde->rigth, list);
        list.push_back(nde->getdata());
    }
}

template <class Type>
void Binary_tree<Type>::pre_order(Node<Type> *nde, std::vector<Type> &list)
{
    if (this->emptystate)
        throw std::invalid_argument("Tree is empty");

    if (nde == NULL)
        return;
    else
    {
        list.push_back(nde->getdata());
        this->in_order(nde->left, list);
        this->in_order(nde->rigth, list);
    }
}

template <class Type>
bool Binary_tree<Type>::empty()
{
    return this->emptystate;
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
*/

template <class Type>
int Binary_tree<Type>::countleafs(Node<Type> *nde)
{
    if (nde == NULL)
    {
        return 0;
    }
    else
    {
        int A = this->countleafs(nde->left);
        int B = this->countleafs(nde->rigth);

        if (A == 0 && B == 0)
        {
            this->leafs += 1;
        }
        return this->leafs;
    }
}

template <class Type>
int Binary_tree<Type>::countleafs()
{
    return this->countleafs(this->Root);
}

template <class Type>
void Binary_tree<Type>::showroot()
{
    std::cout << this->Root->getdata() << std::endl;
}

template <class Type>
void Binary_tree<Type>::prune(Node<Type> *nde)
{
    Node<Type> *tmp = NULL;
    if (nde == NULL)
        return;
    else
    {
        tmp = nde;
        prune(nde->left);
        prune(nde->rigth);
        delete tmp;
    }
}

template <class Type>
Binary_tree<Type>::~Binary_tree()
{
    this->prune(this->Root);
}

template <class t>
void printvector(std::vector<t> &v)
{

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << "  ";
    }
    std::cout << std::endl;
}

//funciones para crear arboles de expresiones
bool is_operator(std::string op)
{
    return (op == "+" || op == "-" || op == "*" || op == "/" || op == "^");
}

void insert_hijos(Binary_tree<std::string> &tree, Node<std::string> *node, std::stack<std::string> &Stack)
{
    if (Stack.empty()) //si la pila esta vacia retornamos
        return;

    if (is_operator(Stack.top()) && tree.empty()) //si el arbol esta vacio colocamos el top como raiz
    {
        tree.setroot(Stack.top());
        Stack.pop();
        Node<std::string> *r = tree.root(); //puntero a la raiz

        insert_hijos(tree, r, Stack); //insertamos los hijos a la derecha de la raiz

        if (is_operator(Stack.top()))
        { //insertamos los hijos a la izquierda de la raiz
            Node<std::string> *izq = tree.insertleft(r, Stack.top());
            Stack.pop();
            insert_hijos(tree, izq, Stack);
            return;
        }
        else
        {
            tree.insertleft(Stack.top());
            Stack.pop();
            return;
        }
    }

    if (is_operator(Stack.top()))
    {
        Node<std::string> *aux = tree.insertrigth(node, Stack.top());
        Stack.pop();
        insert_hijos(tree, aux, Stack);

        if (is_operator(Stack.top()))
        {
            Node<std::string> *aux2 = tree.insertleft(node, Stack.top());
            Stack.pop();
            insert_hijos(tree, aux2, Stack);
            return;
        }
        else
        {
            tree.insertleft(node, Stack.top());
            Stack.pop();
            return;
        }
    }
    else
    {
        tree.insertrigth(node, Stack.top());
        Stack.pop();
        return;
    }
}

/*void insert_hijos(Node<std::string> *node, std::stack<Node<std::string> *> &Stack)
{ //inserta los hijos de un nodo tomando un stack de nodos y insertando los hijos de manera recursiva
    if (Stack.empty())
        return;
    if (is_operator(Stack.top()->getdata()))
    {
        node->rigth = Stack.top();
        Stack.pop();
        insert_hijos(node->rigth, Stack);

        if (is_operator(Stack.top()->getdata()))
        {
            node->left = Stack.top();
            Stack.pop();
            insert_hijos(node->left, Stack);
        }
        else
        {
            node->left = Stack.top();
            Stack.pop();
        }
    }
    else
    {
        node->rigth = Stack.top();
        Stack.pop();

        if (is_operator(Stack.top()->getdata()))
        {
            node->left = Stack.top();
            Stack.pop();
            insert_hijos(node->left, Stack);
        }
        else
        {
            node->left = Stack.top();
            Stack.pop();
        }
    }
}
*/
void sufijo_arbol(std::string exp)
{
    std::stack<std::string> Str;
    Binary_tree<std::string> arbol;
    std::vector<std::string> V;

    for (int i = 0; i < exp.size(); i++)
    {
        std::string actual(1, exp[i]);

        Str.push(actual);
    }

    insert_hijos(arbol, NULL, Str);

    arbol.pre_order(arbol.root(), V);

    printvector<std::string>(V);
}

int main(int argc, char const *argv[])
{
    std::string s = "72ˆ653+*+9-";

    sufijo_arbol(s);

    /*Binary_tree<int> BIN(10);
    std::vector<int> InO;
    BIN.setroot(1);
    BIN.showroot();
    BIN.insertleft(BIN.insertleft(2), 4);
    BIN.insertrigth(BIN.root()->left, 5);
    BIN.insertrigth(BIN.insertrigth(BIN.insertrigth(3), 6), 9);
    BIN.insertleft(BIN.insertleft(BIN.root()->rigth->rigth, 8), 11);

    BIN.post_order(BIN.root(), InO);
    printvector(InO);
    std::cout << BIN.countleafs() << std::endl;*/

    return 0;
}
