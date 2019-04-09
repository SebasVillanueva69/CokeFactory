#ifndef STRUCTS_H
#define STRUCTS_H
#include<stdlib.h>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

struct Bottle
{
    string type; //PITUFA(250ml), 1/2LITROS(500ml), 2LITROS(2000ml)

    bool isClean = false; //Pasa por limpia botellas
    bool isEmpty = true; //Llenan
    bool isCap = false; //Se tapan
    bool isCheck = false; //Se inspeccionan
    bool isReady = false; //Se encajan

    Bottle(string type) {
        this->type = type;
    }
};

struct Person
{
    string type; //Carga o inspeccionan
    int status = 0; //0 = OFF, 1 = ON, 2 = PAUSE
    int speed;
    //INSPECTOR: PORCENTAJE DE BOTELLAS QUE SERAN RECHAZADAS.
    //vector<int> rejectPercentage = {5,20,10}; //0 = pitufas, 1 = 1/2litro, 2 = 2litros
    //CARGADOR: PORCENTAJE DE BOTELLAS QUE CARGARA.
    //vector<int> quantityPercentage = {50,25,25}; //0 = pitufas, 1 = 1/2litro, 2 = 2litros
    Person(string type, int speed) {
        this->type = type;
        this->speed = speed;
    }
    void changeSpeed(int newSpeed){
        this->speed = newSpeed;
    }
    void changeStatus(int newStatus){
        this->status = newStatus;
    }
    Bottle* startWork(Bottle* bottle){
        this->status = 1;
        if(this->type == "inspector"){ //FALTA LO DE LA PROBABILIDAD DE DESECHAR
            bottle->isCheck = true;
        }
        for (int i=this->speed; i>0; --i) {
            this_thread::sleep_for (std::chrono::seconds(1));
            //Actualizar segundos que se muestran.
        }
        return bottle;
    }
};

struct Machine
{
    string type;//clean, fill, cap,
    std::vector<int> counters = {0,0,0}; //0 = pitufas, 1 = 1/2litro, 2 = 2litros
    int speed;
    int status = 0; //0 = OFF, 1 = ON, 2 = PAUSE
    Machine(string type, int speed) {
        this->speed = speed;
        this->type = type;
    }
    void changeSpeed(int newSpeed){
        this->speed = newSpeed;
    }
    void changeStatus(int newStatus){
        this->status = newStatus;
    }
    Bottle* startMachine(Bottle* bottle){
        this->status = 1;
        if(type == "clean"){
            bottle->isClean = true;
        }else if(type == "fill"){
            bottle->isEmpty = false;
        }else {
            bottle->isCap = true;
        }
        for (int i=this->speed; i>0; --i) {
            this_thread::sleep_for (std::chrono::seconds(1));
            //Actualizar segundos que se muestran.
        }
        return bottle;
    }
};

struct Trucks
{
    string type;
    std::vector<int> capacity = {0,0,0}; //0 = pitufas, 1 = 1/2litro, 2 = 2litros
    Trucks(string type) {
        this->type = type;
        if(type == "pickup"){
            capacity.at(0) = 200;
            capacity.at(1) = 50;
            capacity.at(2) = 100;
        }else if(type == "camion"){
            capacity.at(0) = 300;
            capacity.at(1) = 100;
            capacity.at(2) = 150;
        }else{ //Si es un furgon
            capacity.at(0) = 300;
            capacity.at(1) = 150;
            capacity.at(2) = 200;
        }
    }
};

//--------------BIG DATA STRUCTS

struct Node
{
    Bottle *data = nullptr;
    Node *next = nullptr;
    Node(Bottle* data) {
        this->data = data;
    }
};

struct Queue
{
    int count;
    int limit;
    Node* first = nullptr;
    Queue(int limit) {
        this->limit = limit;
    }
    void changelimit(int newLimit){
        this->limit = newLimit;
    }
    Node* dequeue(){
        Node* toReturn = first;
        first->next = first;
        return toReturn;
    }
    void enqueue(Node* newBottle){
        count++;
        if(first == nullptr){
            this->first = newBottle;
        }else{
            Node* temp = first;
            while(first->next != nullptr){
                temp = temp->next;
            }
            temp->next = newBottle;
        }
    }
    bool isFull(){
        if(count == limit){
            return true;
        }return false;
    }

};

#endif // STRUCTS_H
