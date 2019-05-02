#include "mainwindow.h"
#include "firstwindow.h"
#include <QApplication>
#include "structs.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    firstWindow w;
    w.showMaximized();

    return a.exec();
}
