#include <iostream>
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

int main(int argc, char const *argv[])
{

    return 0;
}
