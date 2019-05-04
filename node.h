#ifndef NODE_H
#define NODE_H
#include "bottle.h"

struct Node
{
public:
    Node(Bottle* data);
    Bottle *data = nullptr;
    Node *next = nullptr;
};

#endif // NODE_H
