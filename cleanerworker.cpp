#include "cleanerworker.h"
#include <QMutex>
#include <QWaitCondition>
#include <QThread>
#include <QDebug>
cleanerWorker::cleanerWorker(QObject *parent) : QObject(parent)
{

}

void cleanerWorker::doSetup(QThread &thread)
{
    connect(&thread,SIGNAL(started()), this, SLOT(doWork()));
}

void cleanerWorker::doWork()
{
    while (this->stopped == false)
    {
        QMutex mutex;
        QWaitCondition pause;

        mutex.lock();
        botella = prevQ->dequeue();
        qDebug("Se ha sacado de la banda");
        botella->data->isClean = true;

        if (nextQ->isFull() && nextQ2)
        {
            pause.wait(&mutex);
        }
        else {
            nextQ->enqueue(botella);
            qDebug("Se ha metido con exito");
        }
        mutex.unlock();
    }
}
