#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap coca("C:/Users/Sebas Villanueva/Documents/TEC SEMESTRE 3/Estructuras/ProyectoCoca/Coca Cola Logo.jpg");
    ui->label->setPixmap(coca);
}

MainWindow::~MainWindow()
{
    delete ui;
}
