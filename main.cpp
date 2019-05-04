#include "mainwindow.h"
#include "firstwindow.h"
#include <QApplication>
#include "test.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //firstWindow w;
    //w.showMaximized();

    MainWindow w;
    w.showMaximized();


    return a.exec();
}
