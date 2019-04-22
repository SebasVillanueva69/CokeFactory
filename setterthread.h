#ifndef SETTERTHREAD_H
#define SETTERTHREAD_H
#include <QtCore>

class setterThread : public QThread
{
    Q_OBJECT
public:
    explicit setterThread(QObject *parent = 0);
    void run();

signals:

public slots:

};

#endif // SETTERTHREAD_H
