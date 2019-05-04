#include "person.h"
#include "stdlib.h"
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
#include "cstdlib"
#include "ctime"

Person::Person(string type, int speed, QObject *parent) : QThread(parent)
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
void Person::setList(doubleLinkedList *types)
{
    this->typeList = types;
}
void Person::run()
{
    while(status == 1 || status == 2){
        std::cout<<status<<endl;
        if(status == 2){
            continue;
        }else if(status == 0){
            break;
        }
        Bottle *bottle;
        if(type == "setter"){
            srand(time(NULL));
            int prob = rand() % 100 + 1;
            bottle = this->typeList->search(prob);
        }else{
            while(bandPrev->isEmpty()){
                this->changeStatus(2);
            }
            bottle = this->bandPrev->dequeue()->data;
            bottle->isCheck = true;
            cout<<"checkeada!"<<endl;
        }
        //cout<<"Empieza trabajo"<<endl;
        //cout<<this->type;
        for (int i=this->speed; i>0; --i) {
            this_thread::sleep_for (chrono::seconds(1));
            //cout<<i<<endl;
            //Actualizar segundos que se muestran.
        }
        while(bandNext->isFull()){
            this->status = 2;
            std::cout<<status<<endl;

        }
        this->status = 1;
        Node *node = new Node(bottle);
        bandNext->enqueue(node);
        //return bottle;
        //cout<<"termino trabajo"<<endl;
    }
}
void Person::setBandNext(Queue *band)
{
    this->bandNext = band;
}
void Person::setBandPrev(Queue *band)
{
    this->bandPrev = band;
}
