#include "testthread.h"
#include <iostream>

TestThread::TestThread(QThread *parent) : QThread(parent)
{

}

void TestThread::run()
{
    Node *e = lista->dequeue();

    while(e != nullptr)
    {
        cout << e->data->type << endl;
        e = lista->dequeue();

    }
}
