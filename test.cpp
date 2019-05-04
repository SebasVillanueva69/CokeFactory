#include "test.h"
#include <iostream>
#include <QMutex>

Test::Test(int m , QObject *parent) : QThread(parent)
{
    this->time = m;
}

void Test::run()
{
    for (int i = time; i < 100;i++)
    {
        QMutex mutex;
        //mutex.lock();

        //if (stop) break;
        //mutex.unlock();

        emit bottleTaken(i);
         this->sleep(1);

    }


}
