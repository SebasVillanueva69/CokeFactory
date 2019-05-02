#ifndef FILLERWORKER_H
#define FILLERWORKER_H
#include "structs.h"
#include <QObject>

class fillerWorker : public QObject
{
    Q_OBJECT
public:
    explicit fillerWorker(QObject *parent = nullptr);
    void doSetup(QThread &thread);
    Queue *prevQ;
    Queue *nextQ;
    Node *bottle;
    bool stopped;
signals:

public slots:
    void doWork();
};

#endif // FILLERWORKER_H
