#ifndef CAPPERTHREAD_H
#define CAPPERTHREAD_H
#include <QtCore>

class capperThread : public QThread
{
public:
    explicit capperThread(QThread *parent = 0);
    void run();

signals:

public slots:

};

#endif // CAPPERTHREAD_H
