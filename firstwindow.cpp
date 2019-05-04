#include "firstwindow.h"
#include "mainwindow.h"
#include "ui_firstwindow.h"
#include "iostream"
#include "QStringListModel"

using namespace std;
firstWindow::firstWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::firstWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->verticalWidget);
    ui->verticalWidget->setFixedSize(500,270);
    this->adjustSize();

    connect(ui->start, SIGNAL (released()),this, SLOT (start()));
    connect(ui->add, SIGNAL (released()),this, SLOT (add()));

}
void firstWindow::start(){
    MainWindow *w = new MainWindow();
    w->showMaximized();
    this->hide();
}
void firstWindow::add(){
    QString type = ui->tipo->toPlainText() +" "+ ui->proba->toPlainText()+"%";
    ui->listWidget->addItem(type);
    ui->listWidget->update();
    ui->tipo->clear();
    ui->proba->clear();
}


firstWindow::~firstWindow()
{
    delete ui;
}
