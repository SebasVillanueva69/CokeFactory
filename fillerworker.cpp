#include "fillerworker.h"
#include <QtCore>
#include <QMutex>
#include <QWaitCondition>
#include <QThread>

fillerWorker::fillerWorker(QObject *parent) : QObject(parent)
{

}

void fillerWorker::doSetup(QThread &thread)
{
    connect(&thread,SIGNAL(started()),this,SLOT(doWork()));
}

void fillerWorker::doWork()
{
    while(stopped != true)
    {
        QMutex mutex;
        QWaitCondition pause;

        mutex.lock();
        Node *bottle = filler->band1->dequeue();
        if (filler->status == 1)
        {
            filler->startMachine(bottle->data);
        }
        else if (filler->status == 2) {
            pause.wait(&mutex);
        }
        else {
            break;
        }
        mutex.unlock();

        std::this_thread::sleep_for(std::chrono::seconds(filler->speed));
    }


}
