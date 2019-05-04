#include "queue.h"
#include "iostream"
#include "string"

Queue::Queue(int limit)
{
    this->limit = limit;
    this->count = 0;
}

void Queue::changelimit(int newLimit)
{
    this->limit = newLimit;
}

Node* Queue::dequeue()
{
    Node* toReturn = first;
    first = first->next;
    count--;
    return toReturn;
}

void Queue::enqueue(Node *newBottle)
{
    if(count != limit){

        count++;
        if(first == nullptr){
            first = newBottle;
            std::cout<<"firstNode"<<endl;
        }else{
            std::cout<<"NotfirstNode"<<endl;
            Node* temp = first;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newBottle;
        }
        std::cout<<"Botellas: ";
        std::cout<<count<<endl;
    }

}
bool Queue::isEmpty(){
    return !first;
}
bool Queue::isFull()
{
    if(count == limit){
        return true;
    }
    return false;
}
