#ifndef PERSON_H
#define PERSON_H
#include "string"
#include "queue.h"
#include "QtCore"
#include "doublelinkedlist.h"

class Person : public QThread
{
    Q_OBJECT
public:
    explicit Person(string type,int speed, QObject *parent = nullptr);
    string type; //Carga o inspeccionan
    int status = 0; //0 = OFF, 1 = ON, 2 = PAUSE
    int speed;
    Queue* bandNext;
    Queue* bandPrev;
    doubleLinkedList *typeList;
    void changeSpeed(int newSpeed);
    void run();
    void setBandNext(Queue* band);
    void setBandPrev(Queue* band);
    void setList(doubleLinkedList *types);
signals:
public slots:
    void changeStatus(int);
};

#endif // PERSON_H
