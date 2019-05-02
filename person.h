#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "queue.h"
using namespace std;

struct Person
{
public:
    Person(string type, int speed);
    string type; //Carga o inspeccionan
    int status = 0; //0 = OFF, 1 = ON, 2 = PAUSE
    int speed;
    Queue* band;

    void changeSpeed(int newSpeed);
    void changeStatus(int newStatus);
    void startWork(Bottle* bottle);
    void setBand(Queue* band)
};

#endif // PERSON_H
