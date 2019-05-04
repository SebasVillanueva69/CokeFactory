#ifndef CLEANERTHREAD_H
#define CLEANERTHREAD_H

#include <QObject>
#include <QtCore>
#include "queue.h"

class CleanerThread : public QThread
{
    Q_OBJECT
public:
    explicit CleanerThread(QObject *parent = nullptr);
    void run();
    Queue *prevQ;
    Queue *nextQ;
    Queue *nextQ2;
    Node *bottle;
signals:
    void bottleCleaned();
public slots:
    void onBottleCleaned();
};

#endif // CLEANERTHREAD_H
