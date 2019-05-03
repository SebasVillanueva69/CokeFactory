#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <QObject>
#include <QThread>
#include "queue.h"

class TestThread : public QThread
{
    Q_OBJECT
public:
    explicit TestThread(QThread *parent = nullptr);
    void run();
    Queue *lista;

signals:

public slots:
};

#endif // TESTTHREAD_H
