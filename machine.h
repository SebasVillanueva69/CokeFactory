#ifndef MACHINE_H
#define MACHINE_H
#include <string>
#include "bottle.h"
#include "queue.h"
using namespace std;

struct Machine
{
public:
    Machine(string type, int speed);
    void changeSpeed(int speed);
    void changeStatus(int status);
    int startMachine(Bottle *bottle);
    void setBand(Queue* band);
    string type;//clean, fill, cap,
    Queue* band1 = nullptr;
    Queue* band2 = nullptr;
    int speed;
    int status = 0; //0 = OFF, 1 = ON, 2 = PAUSE

};

#endif // MACHINE_H
