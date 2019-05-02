#include "queue.h"

Queue::Queue(int limit)
{
    this->limit = limit;
}

void Queue::changelimit(int newLimit)
{
    this->limit = newLimit;
}

Node* Queue::dequeue()
{
    Node* toReturn = first;
    first = first->next;
    return toReturn;
}

void Queue::enqueue(Node *newBottle)
{
    count++;
    if(first == nullptr){
        this->first = newBottle;
    }else{
        Node* temp = first;
        while(first->next != nullptr){
            temp = temp->next;
        }
        temp->next = newBottle;
    }
}

bool Queue::isFull()
{
    if(count == limit){
        return true;
    }
    return false;
}
