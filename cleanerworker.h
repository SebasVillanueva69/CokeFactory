#ifndef CLEANERWORKER_H
#define CLEANERWORKER_H
#include "structs.h"
#include <QObject>
#include <QtCore>

class cleanerWorker : public QObject
{
    Q_OBJECT
public:
    explicit cleanerWorker(QObject *parent = nullptr);
    void doSetup(QThread &thread);
    Node *botella;
    Queue *prevQ;
    Queue *nextQ;
    Queue *nextQ2;
    bool stopped = false;
signals:

public slots:
    void doWork();
};

#endif // CLEANERWORKER_H
