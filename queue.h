#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

struct Queue
{
public:
    Queue(int limit);
    int count;
    int limit;
    Node* first = nullptr;

    void changelimit(int newLimit);
    Node* dequeue();
    void enqueue(Node* newBottle);
    bool isFull();
    bool isEmpty();

};

#endif // QUEUE_H
