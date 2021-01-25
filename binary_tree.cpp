#include <iostream>
#include <cmath>
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
protected:
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
bool is_operator(char op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}

class SintaxTree : public Binary_tree<std::string>
{
private:
    char Type;               //tipo de expresion(sufijo o prefijo)
    std::string expr;        //expresion
    std::string infijo_expr; //expresion infijo de la expresion

    int value;

    std::string infijo_to_sufijo(std::string expr);  //convierte una expresion infijo a sufijo
    std::string infijo_to_prefijo(std::string expr); //convierte una expresion infijo a prefijo

    bool is_operator(char op);          //Determina si un caracter es operador
    inline bool is_parentheses(char c); //determina si un operador es parentesis
    int precedence(char c);             //precedencia de los operadores
    int association_order(char c);      //Orden de asociacion

    int EvalOp(int valA, char op, int valB);

public:
    SintaxTree(char type, std::string expr); //recibe el tipo de expresion(sufijo o prefijo) y la expresion en infijo
    SintaxTree(std::string expr_infijo);     //recibe una expresion infijo y la transforma a sufijo
    SintaxTree();                            //Constructor vacio

    SintaxTree &set_expresion(std::string new_expr);  //Cambia la expresion por una infijo la transoforma al tipo de formato del arbol(infijo o sufijo)
    SintaxTree &_set_expresion(std::string new_expr); //Cambia la expresion en el arbol por otra en el mismo formato

    void print_expresion();
    void print_infijo();

    int solve();

    ~SintaxTree();
};

SintaxTree::SintaxTree(char type, std::string expr)
{ //recibe el tipo de expresion(infijo o prefijo) y la expresion en dicho formato
    this->Type = type;
    this->value = 0;

    if (type == 's' || type == 'S')
    {
        this->emptystate = false;
        this->nods = expr.size();
        this->expr = this->infijo_to_sufijo(expr);
        std::stack<Node<std::string> *> S;

        for (int i = 0; i < this->expr.size(); i++)
        {
            std::string actual(1, this->expr[i]);

            this->nodes = new Node<std::string>(actual);

            if (this->is_operator(this->expr[i]))
            {
                Node<std::string> *der = S.top();
                S.pop();
                Node<std::string> *izq = S.top();
                S.pop();

                this->nodes->left = izq;
                this->nodes->rigth = der;
                izq->father = this->nodes;
                der->father = this->nodes;
            }

            S.push(this->nodes);
        }
        this->Root = S.top();
    }
    else if (type == 'P' || type == 'p')
    {
        this->emptystate = false;
        this->nods = expr.size();
        this->expr = this->infijo_to_prefijo(expr);
        std::stack<Node<std::string> *> S;

        for (int i = this->expr.size() - 1; i >= 0; i--)
        {
            std::string actual(1, this->expr[i]);

            this->nodes = new Node<std::string>(actual);

            if (this->is_operator(this->expr[i]))
            {
                Node<std::string> *der = S.top();
                S.pop();
                Node<std::string> *izq = S.top();
                S.pop();

                this->nodes->rigth = der;
                this->nodes->left = izq;
                der->father = this->nodes;
                izq->father = this->nodes;
            }

            S.push(this->nodes);
        }

        this->Root = this->nodes;
    }
    else
    {
        throw std::invalid_argument("Invalid type(Valid types are S or P\n");
    }

    this->infijo_expr = expr;
}

SintaxTree::SintaxTree(std::string expr_infijo)
{ //Recibe una expresion infijo, la convierte a sufijo y crea el arbol
    this->value = 0;
    this->expr = this->infijo_to_sufijo(expr_infijo);
    this->nods = this->expr.size();
    this->emptystate = false;
    this->Type = 'S';

    std::stack<Node<std::string> *> S;

    for (int i = 0; i < this->expr.size(); i++)
    {
        std::string actual(1, this->expr[i]);

        this->nodes = new Node<std::string>(actual);

        if (this->is_operator(this->expr[i]))
        {
            Node<std::string> *der = S.top();
            S.pop();
            Node<std::string> *izq = S.top();
            S.pop();

            this->nodes->left = izq;
            this->nodes->rigth = der;
            izq->father = this->nodes;
            der->father = this->nodes;
        }

        S.push(this->nodes);
    }
    this->Root = S.top();

    this->infijo_expr = expr;
}

SintaxTree::SintaxTree()
{
    this->nodes = NULL;
    this->Root = NULL;
    this->nods = 0;
    this->emptystate = true;
    this->value = 0;
}

SintaxTree &SintaxTree::set_expresion(std::string new_expr)
{
    if (!this->emptystate)
        this->prune(this->root()); //limpiamos el arbol
    if (Type == 's' || Type == 'S')
    {
        this->emptystate = false;
        this->nods = expr.size();
        this->expr = this->infijo_to_sufijo(new_expr);
        std::stack<Node<std::string> *> S;

        for (int i = 0; i < this->expr.size(); i++)
        {
            std::string actual(1, this->expr[i]);

            this->nodes = new Node<std::string>(actual);

            if (this->is_operator(this->expr[i]))
            {
                Node<std::string> *der = S.top();
                S.pop();
                Node<std::string> *izq = S.top();
                S.pop();

                this->nodes->left = izq;
                this->nodes->rigth = der;
                izq->father = this->nodes;
                der->father = this->nodes;
            }

            S.push(this->nodes);
        }
        this->Root = S.top();
    }
    else
    {
        this->emptystate = false;
        this->nods = expr.size();
        this->expr = this->infijo_to_prefijo(new_expr);
        std::stack<Node<std::string> *> S;

        for (int i = this->expr.size() - 1; i >= 0; i--)
        {
            std::string actual(1, this->expr[i]);

            this->nodes = new Node<std::string>(actual);

            if (this->is_operator(this->expr[i]))
            {
                Node<std::string> *der = S.top();
                S.pop();
                Node<std::string> *izq = S.top();
                S.pop();

                this->nodes->rigth = der;
                this->nodes->left = izq;
                der->father = this->nodes;
                izq->father = this->nodes;
            }

            S.push(this->nodes);
        }

        this->Root = this->nodes;
    }
    this->infijo_expr = expr;

    return *this;
}

SintaxTree &SintaxTree::_set_expresion(std::string new_expr)
{
    if (!this->emptystate)
        this->prune(this->root()); //limpiamos el arbol
    if (Type == 's' || Type == 'S')
    {
        this->expr = new_expr;
        this->emptystate = false;
        this->nods = expr.size();

        std::stack<Node<std::string> *> S;

        for (int i = 0; i < this->expr.size(); i++)
        {
            std::string actual(1, this->expr[i]);

            this->nodes = new Node<std::string>(actual);

            if (this->is_operator(this->expr[i]))
            {
                Node<std::string> *der = S.top();
                S.pop();
                Node<std::string> *izq = S.top();
                S.pop();

                this->nodes->left = izq;
                this->nodes->rigth = der;
                izq->father = this->nodes;
                der->father = this->nodes;
            }

            S.push(this->nodes);
        }
        this->Root = S.top();
    }
    else
    {
        this->expr = new_expr;
        this->emptystate = false;
        this->nods = expr.size();

        std::stack<Node<std::string> *> S;

        for (int i = this->expr.size() - 1; i >= 0; i--)
        {
            std::string actual(1, this->expr[i]);

            this->nodes = new Node<std::string>(actual);

            if (this->is_operator(this->expr[i]))
            {
                Node<std::string> *der = S.top();
                S.pop();
                Node<std::string> *izq = S.top();
                S.pop();

                this->nodes->rigth = der;
                this->nodes->left = izq;
                der->father = this->nodes;
                izq->father = this->nodes;
            }

            S.push(this->nodes);
        }

        this->Root = this->nodes;
    }
    this->infijo_expr = expr;

    return *this;
}

bool SintaxTree::is_operator(char op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}

inline bool SintaxTree::is_parentheses(char c)
{
    return (c == '(' || c == ')');
}

int SintaxTree::precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 0;

    case '*':
    case '/':
        return 1;

    case '^':
        return 2;

    default:
        return -1;
    }
}

int SintaxTree::association_order(char c)
{
    switch (c)
    {
    case '^':
        return -1;
    case '*':
    case '/':
    case '-':
    case '+':
        return 1;

    default:
        return 0;
    }
}

std::string SintaxTree::infijo_to_sufijo(std::string expr)
{
    std::string result = "";
    std::stack<char> Pl;

    for (int i = 0; i < expr.size(); i++)
    {
        if (this->is_operator(expr[i]))
        {
            //Si es operador se compara contra la pila
            while (!Pl.empty() && this->precedence(Pl.top()) > this->precedence(expr[i]))
            { //Si el top es de mayor precedencia que el operador actual lo escribimos
                result = result + Pl.top();
                Pl.pop();
            }

            if (Pl.empty() || this->precedence(Pl.top()) < this->precedence(expr[i]) || this->is_parentheses(Pl.top()))
            { //si la pila esta vacia o el operador en turno de es de menor precedencia que el top de la pila
                Pl.push(expr[i]);
            }
            else
            { //El operador en turno y el top de la pila tienen la misma precedencia

                if (this->association_order(expr[i]) > 0) //izquierda a derecha
                {
                    result = result + Pl.top();
                    Pl.pop();
                    Pl.push(expr[i]);
                }
                else
                {
                    Pl.push(expr[i]);
                }
            }
        }
        else
        {
            if (this->is_parentheses(expr[i]))
            { //Si es parentesis revisamos si abre o cierra
                if (expr[i] == '(')
                {
                    Pl.push(expr[i]); //si es un parentesis que abre lo ponemos en la pila
                }
                else
                { //si el parentesis cierra sacamos los operadores de la pila hasta encontrar el que abre
                    while (Pl.top() != '(' && !Pl.empty())
                    {
                        result = result + Pl.top();
                        Pl.pop();
                    }
                    Pl.pop(); //eliminamos el parentesis que abre
                }
            }
            else
            {
                //Si es operando lo escribimos directamente
                result = result + expr[i];
            }
        }
    }

    while (!Pl.empty())
    {
        result = result + Pl.top();
        Pl.pop();
    }

    return result;
}

std::string SintaxTree::infijo_to_prefijo(std::string expr)
{
    std::string result = "";
    std::stack<char> Pl;

    for (int i = expr.size() - 1; i >= 0; i--)
    {
        if (this->is_operator(expr[i]))
        {
            //Si es operador se compara contra la pila
            while (!Pl.empty() && this->precedence(Pl.top()) > this->precedence(expr[i]))
            { //Si el top es de mayor precedencia que el operador actual lo escribimos
                result = Pl.top() + result;
                Pl.pop();
            }

            if (Pl.empty() || this->precedence(Pl.top()) < this->precedence(expr[i]) || this->is_parentheses(Pl.top()))
            { //si la pila esta vacia o el operador en turno de es de menor precedencia que el top de la pila
                Pl.push(expr[i]);
            }
            else
            { //El operador en turno y el top de la pila tienen la misma precedencia

                if (this->association_order(expr[i]) < 0) //derecha a izquierda
                {
                    result = Pl.top() + result;
                    Pl.pop();
                    Pl.push(expr[i]);
                }
                else
                {
                    Pl.push(expr[i]);
                }
            }
        }
        else
        {
            if (this->is_parentheses(expr[i]))
            { //Si es parentesis revisamos si abre o cierra
                if (expr[i] == ')')
                {
                    Pl.push(expr[i]); //si es un parentesis que abre lo ponemos en la pila
                }
                else
                { //si el parentesis cierra sacamos los operadores de la pila hasta encontrar el que abre
                    while (Pl.top() != ')' && !Pl.empty())
                    {
                        result = Pl.top() + result;
                        Pl.pop();
                    }
                    Pl.pop(); //eliminamos el parentesis que abre
                }
            }
            else
            {
                //Si es operando lo escribimos directamente
                result = expr[i] + result;
            }
        }
    }

    while (!Pl.empty())
    {
        result = Pl.top() + result;
        Pl.pop();
    }

    return result;
}

void SintaxTree::print_expresion()
{
    if (this->emptystate)
        throw std::invalid_argument("Tree is empty\n");

    std::cout << this->expr << std::endl;
}

void SintaxTree::print_infijo()
{

    std::vector<std::string> V;

    if (this->emptystate)
        throw std::invalid_argument("Tree is empty\n");

    std::cout << this->infijo_expr << std::endl;
}

int SintaxTree::EvalOp(int valA, char op, int valB)
{
    if (op == '^')
    {
        return std::pow(valA, valB);
    }
    else if (op == '*')
    {
        return valA * valB;
    }
    if (op == '/')
    {
        return valA / valB;
    }
    if (op == '+')
    {
        return valA + valB;
    }
    if (op == '-')
    {
        return valA - valB;
    }

    return 0;
}

int SintaxTree::solve()
{
    if (this->emptystate)
        throw std::invalid_argument("Empty Tree\n");

    std::stack<std::string> pl;
    if (Type == 's' || Type == 'S')
    {
        for (int i = 0; i < this->expr.size(); i++)
        {
            std::string act(1, this->expr[i]);

            if (this->is_operator(this->expr[i]))
            {
                int A = std::stoi(pl.top());
                pl.pop();
                int B = std::stoi(pl.top());
                pl.pop();

                std::string C = std::to_string(this->EvalOp(B, this->expr[i], A));
                pl.push(C);
            }
            else
            {
                pl.push(act);
            }
        }
    }
    else
    {

        for (int i = this->expr.size() - 1; i >= 0; i--)
        {
            std::string act(1, this->expr[i]);

            if (this->is_operator(this->expr[i]))
            {
                int A = std::stoi(pl.top());
                pl.pop();
                int B = std::stoi(pl.top());
                pl.pop();

                std::string C = std::to_string(this->EvalOp(A, this->expr[i], B));
                pl.push(C);
            }
            else
            {
                pl.push(act);
            }
        }
    }

    return std::stoi(pl.top());
}

SintaxTree::~SintaxTree()
{
}

int main(int argc, char const *argv[])
{
    std::string expr = "7^2+6*(5+3)-9";
    SintaxTree A('s', expr); //arbol sufijo
    SintaxTree B('p', expr); //arbol prefijo
    std::vector<std::string> InO, inO2;

    std::cout << A.solve() << "\n";

    A.print_expresion();
    A.in_order(A.root(), InO);
    printvector(InO);

    std::cout << B.solve() << "\n";
    B.print_expresion();
    B.in_order(B.root(), inO2);
    printvector(inO2);

    return 0;
}
