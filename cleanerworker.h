#ifndef CLEANERWORKER_H
#define CLEANERWORKER_H
#include "structs.h"
#include <QObject>
#include <QtCore>

class cleanerWorker : public QThread
{
    Q_OBJECT
public:
    explicit cleanerWorker(QThread *parent = nullptr);
    void run();
    Node *botella;
    Queue *prevQ;
    Queue *nextQ;
    Queue *nextQ2;
    bool stopped = false;
    int speed;
signals:

public slots:

};

#endif // CLEANERWORKER_H
