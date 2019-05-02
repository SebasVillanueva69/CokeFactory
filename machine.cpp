#include "machine.h"
#include "stdlib.h"
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
#include "cstdlib"
#include "ctime"

Machine::Machine(string type, int speed)
{
    this->speed = speed;
    this->type = type;
}

void Machine::changeSpeed(int newSpeed){
    this->speed = newSpeed;
}

void Machine::changeStatus(int status)
{
    this->status = status;
}

int Machine:: startMachine(Bottle* bottle)
{
    cout<<"Emieza maquina"<<endl;
    this->status = 1;
    if(type == "clean"){
        bottle->isClean = true;
        cout<<"se limpio"<<endl;
    }else if(type == "fill"){
        cout<<"se lleno"<<endl;
        bottle->isEmpty = false;
    }else {
        cout<<"se tapo"<<endl;
        bottle->isCap = true;
    }
    for (int i=this->speed; i>0; --i) {
        this_thread::sleep_for (std::chrono::seconds(1));
        cout<<i<<endl;
        //Actualizar segundos que se muestran.
    }
    if(this->type == "clean"){
        srand(time(NULL));
        int band = rand() % 2;
        cout<<"num ran: ";
        cout<<band<<endl;
        if(band == 1){
            cout<<"banda1"<<endl;
            while(band1->isFull()){
                this->status = 2;
            }
            this->status = 1;
            Node *node = new Node(bottle);
            band1->enqueue(node);
            return 1;
        }else{
            cout<<"banda2"<<endl;
            while(band2->isFull()){
                this->status = 2;
            }
            Node *node = new Node(bottle);
            band2->enqueue(node);
            return 2;
        }
    }else{
        while(band1->isFull()){
            this->status = 2;
        }
        Node *node = new Node(bottle);
        band1->enqueue(node);
        return 1;
    }

void Machine:: setBand(Queue* band){
        if(this->band1 != nullptr){
            this->band2 = band;
        }else{
            this->band1 = band;
        }
    }

}
