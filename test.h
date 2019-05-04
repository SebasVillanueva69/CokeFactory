#ifndef TEST_H
#define TEST_H
#include <QObject>
#include <QtCore>
#include "queue.h"

class Test : public QThread
{
    Q_OBJECT
public:
    explicit Test(int m, QObject *parent = nullptr);
    void run();
    int time;
    Queue *lista;
    bool stop;
signals:
    void bottleTaken(int);
public slots:

};

#endif // TEST_H
