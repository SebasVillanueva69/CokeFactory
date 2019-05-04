#include "test.h"
#include <iostream>
#include <QMutex>

Test::Test(QObject *parent) : QThread(parent)
{

}

void Test::run()
{
    QMutex mutex;
    mutex.lock();

    if (stop) break;
    mutex.unlock();

    emit bottleTaken(i);



    this->sleep(1000);

}
