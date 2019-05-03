#include "mainwindow.h"
#include "firstwindow.h"
#include <QApplication>
#include "testthread.h"

int main(int argc, char *argv[])
{

    //firstWindow w;
    //w.showMaximized();
    Queue *lista = new Queue(10);
    Bottle *b = new Bottle("pene");
    Node *n = new Node(b);

    lista->enqueue(n);
    TestThread test;
    test.start();

    return 0;
}
