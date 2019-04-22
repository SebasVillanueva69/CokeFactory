#ifndef CLEANERTHREAD_H
#define CLEANERTHREAD_H
#include <QtCore>

class cleanerThread : public QThread
{
    Q_OBJECT
public:
    explicit cleanerThread(QThread *parent = 0);
    void run();
signals:

public slots:

};

#endif // CLEANERTHREAD_H
