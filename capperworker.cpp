#include "capperworker.h"
#include <QMutex>

CapperWorker::CapperWorker(QThread *parent) : QThread(parent)
{

}

void CapperWorker::run()
{
    while(this->stop != true)
    {
        int band = rand() % 2;

        QMutex mutex;
        mutex.lock();

        if (band == 0)
        {
            if (prevQ->dequeue() != nullptr)
            {

            }
        }



        mutex.unlock();
    }
}
