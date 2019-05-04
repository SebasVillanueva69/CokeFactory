#include "mainwindow.h"
#include "firstwindow.h"
#include <QApplication>
#include "test.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //MainWindow w;
    //w.show();

    firstWindow w;
    w.show();


    return a.exec();
}
