#include "machine.h"
#include "stdlib.h"
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
#include "cstdlib"
#include "ctime"

Machine::Machine(string type, int speed,QObject *parent) : QThread(parent)
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
void Machine::setBandNext(Queue* band){
        if(this->band1n != nullptr){
            this->band2n = band;
        }else{
            this->band1n = band;
        }
    }
void Machine:: setBandPrev(Queue* band){
        if(this->band1p != nullptr){
            this->band2p = band;
        }else{
            this->band1p = band;
        }
    }
void Machine:: run()
{
    while(status == 1 || status == 2){
        if(status == 2){
            continue;
        }
        Bottle *bottle;
        //cout<<"Emieza maquina"<<endl;
        this->status = 1;
        if(type == "cleaner"){
            while(band1p->isEmpty()){
                this->status = 2;
            }
            this->status = 1;
            bottle = band1p->dequeue()->data;
            //cout<<"se limpio"<<endl;
            srand(time(NULL));
            int band = rand() % 2;
            if(band == 1){
                //cout<<"banda1"<<endl;
                while(band1n->isFull()){
                    this->status = 2;
                }
                this->status = 1;
                Node *node = new Node(bottle);
                band1n->enqueue(node);
            }else{
                //cout<<"banda2"<<endl;
                while(band2n->isFull()){
                    this->status = 2;
                }
                this->status = 1;
                Node *node = new Node(bottle);
                band2n->enqueue(node);
            }
        }else if(type == "filler"){
            while(band1p->isEmpty()){
                this->status = 2;
            }
            this->status = 1;
            bottle = band1p->dequeue()->data;
            Node *node = new Node(bottle);
            while(band2n->isFull()){
                this->status = 2;
            }
            this->status = 1;
            band1n->enqueue(node);
        }else {
            srand(time(NULL));
            int band = rand() % 2;
            if(band == 1){
                while(band1p->isEmpty()){
                    this->status = 2;
                }
                this->status = 1;
                bottle = band1p->dequeue()->data;
            }else{
                while(band2p->isEmpty()){
                    this->status = 2;
                }
                this->status = 1;
                bottle = band2p->dequeue()->data;
            }
            Node *node = new Node(bottle);
            while(band1n->isFull()){
                this->status = 2;
            }
            this->status = 1;
            band1n->enqueue(node);
            cout<<"se tapo"<<endl;
            bottle->isCap = true;
        }
        for (int i=this->speed; i>0; --i) {
            this_thread::sleep_for (std::chrono::seconds(1));
            cout<<i<<endl;
            //Actualizar segundos que se muestran.
        }
    }
};
