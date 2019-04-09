#include "mainwindow.h"
#include <QApplication>
#include "structs.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Machine* cleaner = new Machine("clean",3);
    Machine* filler1 = new Machine("fill",4);
    Machine* filler2 = new Machine("fill",4);
    Machine* capper = new Machine("cap",1);

    Queue* band1 = new Queue(100);
    Queue* bandP2 = new Queue(50);
    Queue* bandP3 = new Queue(80);
    Queue* band4 = new Queue(10);
    Queue* band5 = new Queue(120);

    Person* setter = new Person("colocador",5);
    Person* checker = new Person("inspector",10);

    Bottle* botella = new Bottle("PITUFA");
    Bottle* Sbottle = setter->startWork(botella);
    if(!band1->isFull()){
        Node* node = new Node(Sbottle);
        band1->enqueue(node);
    }
    Bottle* Cbottle = cleaner->startMachine(band1->dequeue()->data);
    if(!bandP2->isFull()){
        Node* node = new Node(Cbottle);
        bandP2->enqueue(node);
    }
    Bottle* Fbottle = filler1->startMachine(bandP2->dequeue()->data);
    if(!band4->isFull()){
        Node* node = new Node(Fbottle);
        band4->enqueue(node);
    }
    Bottle* CaBottle = capper->startMachine(band4->dequeue()->data);
    if(!band5->isFull()){
        Node* node = new Node(CaBottle);
        band5->enqueue(node);
    }
    checker->startWork(band5->dequeue()->data);



    return a.exec();
}
