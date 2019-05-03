#include "cleanerworker.h"
#include <QMutex>

cleanerWorker::cleanerWorker(QThread *parent) : QThread(parent)
{

}

void cleanerWorker::run()
{
    while(this->stop != true)
    {
        QMutex mutex;
        mutex.lock();

        bottle = prevQ->dequeue();
        bottle->data->isClean = true;

        int band = rand() % 2;

        if (band == 0)
        {
            if (nextQ1->isFull() != true)
            {
                nextQ1->enqueue(bottle);
            }
        }
        else {
            if (nextQ2->isFull() != true)
            {
                nextQ2->enqueue(bottle);
            }
        }
        mutex.unlock();

        for (int i=this->speed; i>0; --i) {
            this_thread::sleep_for (std::chrono::seconds(1));
        }

    }

}
