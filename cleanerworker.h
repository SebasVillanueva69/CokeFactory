#ifndef CLEANERWORKER_H
#define CLEANERWORKER_H

#include <QObject>
#include <QtCore>
#include "bottle.h"
#include "queue.h"

class cleanerWorker : public QThread
{
    Q_OBJECT
public:
    explicit cleanerWorker(QThread *parent = nullptr);
    void run();
    Queue *prevQ;
    Queue *nextQ1;
    Queue *nextQ2;
    Node *bottle;
    int speed;
    bool stop;
signals:

public slots:
};

#endif // CLEANERWORKER_H
