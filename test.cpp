#include "test.h"
#include <iostream>
#include <QMutex>

Test::Test(QObject *parent) : QThread(parent)
{

}

void Test::run()
{
    for (int i = 0; i < 100000;i++)
    {
        QMutex mutex;
        mutex.lock();

        if (stop) break;
        mutex.unlock();

        emit bottleTaken(i);

    }

    this->sleep(1000);

}
