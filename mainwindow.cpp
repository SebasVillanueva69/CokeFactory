#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QPixmap coca();
    ui->label->setPixmap(QPixmap(":/new/prefix1/Coca Cola Logo.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
