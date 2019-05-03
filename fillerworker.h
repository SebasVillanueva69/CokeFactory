#ifndef FILLERWORKER_H
#define FILLERWORKER_H

#include <QObject>
#include <QtCore>
#include "node.h"
#include "queue.h"
class FillerWorker : public QThread
{
    Q_OBJECT
public:
    explicit FillerWorker(QThread *parent = nullptr);
    void run();
    Node *bottle;
    Queue *prevQ;
    Queue *prevQ2;
    Queue *nextQ;
    Queue *nextQ2;
    int speed;
    bool stop;
signals:

public slots:
};

#endif // FILLERWORKER_H
