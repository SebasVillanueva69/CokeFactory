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
Bottle* doubleLinkedList::search(int p){
    NodeList* temp = first;
    int c = 0;
    while(temp){
        c = c + temp->per;
        if(p <= c){
            return new Bottle(temp->type);
        }
        if(temp->next == first){
            return nullptr;
        }
        temp = temp->next;
    }
    return nullptr;
}
bool doubleLinkedList::check(){
    NodeList* temp = first;
    int total = 0;
    while(temp->next != first){
        total = total + temp->per;
    }
    if(total != 100){
        return false;
    }
    else {
        return true;
    }
}

