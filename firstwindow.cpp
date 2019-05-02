#include "firstwindow.h"
#include "mainwindow.h"
#include "ui_firstwindow.h"

firstWindow::firstWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::firstWindow)
{
    ui->setupUi(this);

    connect(ui->start, SIGNAL (released()),this, SLOT (start()));
}
void firstWindow::start(){
    MainWindow *w = new MainWindow();
    w->showMaximized();
    this->hide();
}

firstWindow::~firstWindow()
{
    delete ui;
}
