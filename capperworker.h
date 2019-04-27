#ifndef CAPPERWORKER_H
#define CAPPERWORKER_H

#include <QObject>
#include "structs.h"

class CapperWorker : public QObject
{
    Q_OBJECT
public:
    explicit CapperWorker(QObject *parent = nullptr);
    void doSetup(QThread &thread);
    bool stopped = false;
    Machine *capper;
signals:

public slots:
    void doWork();
};

#endif // CAPPERWORKER_H
