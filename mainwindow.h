#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMovie"
#include "test.h"
#include "person.h"
#include "machine.h"
#include "queue.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QMovie *clean = new QMovie(":/new/prefix1/cleanMachine.gif");//PRIMER GIF, MAQUINA DE LIMPIADO

    QMovie *fill1 = new QMovie(":/new/prefix1/toFill1.gif");//SEGUNDO GIF ARRIBA, BANDA
    QMovie *fill2 = new QMovie(":/new/prefix1/toFill2.gif");//SEGUNDO GIF ABAJO, BANDA

    QMovie *filled1 = new QMovie(":/new/prefix1/filled1.gif");//TERCER GIF ARRIBA, MAQUINA
    QMovie *filled2 = new QMovie(":/new/prefix1/filled2.gif");//TERCER GIF ABAJO, MAQUINA

    QMovie *cap = new QMovie(":/new/prefix1/capperMachine.gif");//CUARTO GIF, MAQUINA DE TAPADO

    doubleLinkedList *types;

    Test *test;

    Person *setter;
    Person *checker;

    Machine *cleaner;
    Machine *filler1;
    Machine *filler2;
    Machine *capper;

    Queue *queue1;
    Queue *queue2;
    Queue *queue3;
    Queue *queue4;
    Queue *queue5;
    Queue *queue6;

private slots:
    void start();
    void pause();
    void stop();
    void onBottleTaken(int);

private:
    Ui::MainWindow *ui;
signals:
    void status(int);
};

#endif // MAINWINDOW_H
