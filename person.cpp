#include "person.h"
#include "stdlib.h"
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
#include "cstdlib"
#include "ctime"

Person::Person(string type, int speed)
{
    this->type = type;
    this->speed = speed;
}

void Person::changeSpeed(int newSpeed)
{
    this->speed = newSpeed;
}

void Person::changeStatus(int newStatus)
{
    this->status = newStatus;
}

void Person::startWork(Bottle *bottle)
{
    cout<<"Empieza trabajo"<<endl;
    this->status = 1;
    cout<<this->type;
    if(type == "inspector"){ //FALTA LO DE LA PROBABILIDAD DE DESECHAR
        bottle->isCheck = true;
        cout<<"checkeada!"<<endl;
    }
    for (int i=this->speed; i>0; --i) {
        this_thread::sleep_for (chrono::seconds(1));
        cout<<i<<endl;
        //Actualizar segundos que se muestran.
    }
    while(band->isFull()){
        continue;
    }
    Node *node = new Node(bottle);
    band->enqueue(node);
    //return bottle;
    cout<<"termino trabajo"<<endl;
}

void Person::setBand(Queue *band)
{
    this->band = band;
}
