#include "capperworker.h"
#include <QMutex>
#include <QWaitCondition>
#include <QtCore>
CapperWorker::CapperWorker(QObject *parent) : QObject(parent)
{

}

void CapperWorker::doSetup(QThread &thread)
{
    connect(&thread,SIGNAL(started()),this,SLOT(doWork()));
}

void CapperWorker::doWork()
{
    while (stopped != true)
    {
        QMutex mutex;
        QWaitCondition pause;
        mutex.lock();

        Node *botella = capper->band1->dequeue();

        if (capper->status == 1)
        {
            capper->startMachine(botella->data);
        }
        else if (capper->status == 2)
        {
            pause.wait(&mutex);
        }
        else {
            break
        }
        mutex.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(capper->speed));
    }
}
