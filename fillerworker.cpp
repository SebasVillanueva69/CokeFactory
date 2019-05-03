#include "fillerworker.h"
#include <QMutex>

FillerWorker::FillerWorker(QThread *parent) : QThread(parent)
{

}

void FillerWorker::run()
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
                bottle = prevQ->dequeue();
                bottle->data->isEmpty = false;

                if (nextQ->isFull() != true)
                {
                    nextQ->enqueue(bottle);
                }
            }
            else {
                break;
            }
        }
        else {
            if (prevQ2->dequeue() != nullptr)
            {
                bottle = prevQ2->dequeue();
                bottle->data->isEmpty = false;

                if (nextQ2->isFull() != true)
                {
                    nextQ2->enqueue(bottle);
                }
            }
            else {
                break;
            }
        }

        mutex.unlock();

        for (int i=this->speed; i>0; --i) {
            this_thread::sleep_for (std::chrono::seconds(1));
        }
    }
}
