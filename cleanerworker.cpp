#include "cleanerworker.h"
#include <QMutex>
#include <QWaitCondition>
#include <QThread>
#include <QDebug>
#include "cstdlib"

cleanerWorker::cleanerWorker(QThread *parent) : QThread(parent)
{
}

void cleanerWorker::run()
{
    while(this->stopped != true)
    {
        QMutex mutex;
        mutex.lock();

        botella = prevQ->dequeue();

        botella->data->isClean = true;
        int banda = rand() %2;

        if (banda == 0)
        {
            if (nextQ->isFull())
            {

            }
            else {
                nextQ->enqueue(botella);
            }
        }
        else{
            if (nextQ2->isFull())
            {

            }
            else {
                nextQ2->enqueue(botella);
            }
        }

        mutex.unlock();

    }
}
