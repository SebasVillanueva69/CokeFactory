#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMovie"
#include "QLabel"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->play, SIGNAL (released()),this, SLOT (start()));
    connect(ui->pause, SIGNAL (released()),this, SLOT (pause()));
    connect(ui->stop, SIGNAL (released()),this, SLOT (stop()));

    ui->allMachine->setPixmap(QPixmap(":/new/prefix1/allMachine.png"));
    ui->setter->setPixmap(QPixmap(":/new/prefix1/setter.png"));//ESTABLECE IMAGEN DEL SETTER

    ui->cleaner->setMovie(clean);//ESTABLECE AL PRIMER LABEL EL PRIMER GIF

    ui->fill1->setMovie(fill1);//ESTABLECE AL SEGUNDO LABEL ARRIBA, EL SEGUNDO GIF ARRIBA
    ui->fill2->setMovie(fill2);//ESTABLECE AL SEGUNDO LABEL ABAJO, EL SEGUNDO GIFF ABAJO

    ui->filled1->setMovie(filled1);//ESTABLECE AL TERCER LABEL ARRIBA, EL TERCER GIF ARRIBA
    ui->filled2->setMovie(filled2);//ESTABLECE AL TERCER LABEL ABAJO, EL TERCER GIF ABAJO

    ui->capper->setMovie(cap);//ESTABLECE AL CUARTO LABEL, EL CUARTO GIF

    ui->checker->setPixmap(QPixmap(":/new/prefix1/checker.png"));//ESTABLECE IMAGEN DEL CHECKER

    ui->name1->hide();
    ui->name2a->hide();
    ui->name2b->hide();
    ui->name3->hide();
    ui->setter->hide();
    ui->checker->hide();
    //COLORES DE LOS BOTTONES
    ui->pause->setStyleSheet("background-color: none");
    ui->stop->setStyleSheet("background-color: none");
    ui->play->setStyleSheet("background-color: none");

}
void MainWindow::start(){
    //APAGA COLORES DE BOTONES SI ESTA ENCEDIDOS
     ui->pause->setStyleSheet("background-color: none");
     ui->stop->setStyleSheet("background-color: none");
     ui->play->setStyleSheet("background-color: green");
     ui->allMachine->hide();
     //MUESTRA LOS NOMBRES
     ui->name1->show();
     ui->name2a->show();
     ui->name2b->show();
     ui->name3->show();
     ui->setter->show();
     ui->checker->show();
     //Empieza todos los gifs
     clean->start();
     fill1->start();
     fill2->start();
     filled1->start();
     filled2->start();
     cap->start();
}
void MainWindow::pause(){
    //APAGA COLORES DE BOTONES SI ESTA ENCEDIDOS
     ui->stop->setStyleSheet("background-color: none");
     ui->play->setStyleSheet("background-color: none");
     ui->pause->setStyleSheet("background-color: orange");
     //PAUSA TODOS LOS GIFS
     clean->setPaused(true);
     clean->setPaused(true);
     fill1->setPaused(true);
     fill2->setPaused(true);
     filled1->setPaused(true);
     filled2->setPaused(true);
     cap->setPaused(true);
}
void MainWindow::stop(){
    //APAGA COLORES DE BOTONES SI ESTA ENCEDIDOS
     ui->play->setStyleSheet("background-color: none");
     ui->pause->setStyleSheet("background-color: none");
     ui->stop->setStyleSheet("background-color: red");
     //PARA TODOS LOS GIFS
     clean->stop();
     clean->stop();
     fill1->stop();
     fill2->stop();
     filled1->stop();
     filled2->stop();
     cap->stop();
}
MainWindow::~MainWindow()
{
    delete ui;
}
