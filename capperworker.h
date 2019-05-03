#ifndef CAPPERWORKER_H
#define CAPPERWORKER_H

#include <QObject>
#include <QtCore>
#include "node.h"
#include "queue.h"

class CapperWorker : public QThread
{
    Q_OBJECT
public:
    explicit CapperWorker(QThread *parent = nullptr);
    void run();
    Node *bottle;
    Queue *prevQ;
    Queue *prevQ2;
    Queue *nextQ;
    int speed;
    bool stop;
signals:

public slots:
};

#endif // CAPPERWORKER_H
