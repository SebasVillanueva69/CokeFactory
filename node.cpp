#include "node.h"
#include "iostream"

Node::Node(Bottle* data)
{
    this->data = data;
    std::cout<<data->type<<endl;
}
