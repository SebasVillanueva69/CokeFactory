#include "doublelinkedlist.h"

doubleLinkedList::doubleLinkedList()
{
    first = nullptr;
}

void doubleLinkedList::insert(string type, int per)
{
    NodeList *nodo = new NodeList(type, per);
    if(first == nullptr){
        first = nodo;
        first->prev = first;
        first->next = first;
    }else{
        first->prev->next = nodo;
        nodo->prev = first->prev;
        nodo->next = first;
        first->prev = nodo;
    }
}
