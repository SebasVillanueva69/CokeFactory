#include "mainwindow.h"
#include "firstwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    //firstWindow w;
    w.show();

    return a.exec();
}
