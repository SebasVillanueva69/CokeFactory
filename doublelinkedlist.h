#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "nodelist.h"
#include <string>

using namespace std;
struct doubleLinkedList
{
public:
    doubleLinkedList();
    NodeList *first;

    void insert(string type, int per);
};

#endif // DOUBLELINKEDLIST_H
