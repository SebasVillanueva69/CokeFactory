#ifndef FILLERTHREAD_H
#define FILLERTHREAD_H
#include <QtCore>

class fillerThread : public QThread
{
    Q_OBJECT
public:
    explicit fillerThread(QThread *parent = 0);
    void run();

signals:

public slots:

};

#endif // FILLERTHREAD_H
