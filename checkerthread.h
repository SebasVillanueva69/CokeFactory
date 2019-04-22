#ifndef CHECKERTHREAD_H
#define CHECKERTHREAD_H
#include <QtCore>

class checkerThread : public QThread
{
public:
    explicit checkerThread(QThread *parent = 0);
    void run();

signals:

public slots:

};

#endif // CHECKERTHREAD_H
