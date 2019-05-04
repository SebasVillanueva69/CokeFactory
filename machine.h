#ifndef MACHE_H
#define MACHINE_H
#include <QObject>
#include <string>
#include <QtCore>
#include "bottle.h"
#include "queue.h"

class Machine : public QThread
{
     Q_OBJECT
public:
    explicit Machine(string type, int speed,QObject *parent = nullptr);
    void changeSpeed(int speed);
    void changeStatus(int status);
    void run();
    void setBandNext(Queue* band);
    void setBandPrev(Queue* band);
    string type;//clean, fill, cap,
    Queue* band1n = nullptr;
    Queue* band2n = nullptr;
    Queue* band1p = nullptr;
    Queue* band2p = nullptr;
    int speed;
    int status = 0; //0 = OFF, 1 = ON, 2 = PAUSE
signals:
public slots:

};

#endif // MACHINE_H
