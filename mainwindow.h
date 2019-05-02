#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMovie"


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

private slots:
    void start();
    void pause();
    void stop();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
