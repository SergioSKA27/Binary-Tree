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
    Node(type Data);
    Node<type> &changedata(type data);
    type getdata();
    void showdata();
    Node<type> &operator=(const Node<type> &node);
    ~Node();
};

Node::Node(/* args */)
{
}

Node::~Node()
{
}
