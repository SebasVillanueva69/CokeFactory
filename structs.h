#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdlib.h>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "iostream"
#include "cstdlib"
#include "ctime"

using namespace std;

//--------------BIG DATA STRUCTS
struct Node
{
    Bottle *data = nullptr;
    Node *next = nullptr;
    Node *prev = nullptr;
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
        first = first->next;
        cout<<"salio de la cola"<<endl;
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
        cout<<"entro a la cola"<<endl;
    }

    bool isFull(){
        if(count == limit){
            cout<<"esta lleno"<<endl;
            return true;
        }
        cout<<"no esta lleno"<<endl;
        return false;
    }

};

struct doubleLinkedList
{
    Node *first;
    doubleLinkedList()
    {
        first = nullptr;
    }

    void insertAtHead(Node bottle)
    {
        if (first == nullptr)
        {
            first = new Node(bottle);
            first->prev = first;
            first->next = first;
        }
        else
        {
            Node *n = new Node(bottle);
            n->next = first;
            n->prev = first->prev;
            n->prev->next = n;
            first->prev = n;
        }
    }
};
struct Person
{
    string type; //Carga o inspeccionan
    int status = 0; //0 = OFF, 1 = ON, 2 = PAUSE
    int speed;
    Queue* band;
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
    void startWork(Bottle* bottle){
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
    void setBand(Queue* band){
        this->band = band;
    }
};

struct Machine
{
    string type;//clean, fill, cap,
    Queue* band1 = nullptr;
    Queue* band2 = nullptr;
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
    int startMachine(Bottle* bottle){
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
    }
    void setBand(Queue* band){
        if(this->band1 != nullptr){
            this->band2 = band;
        }else{
            this->band1 = band;
        }
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

struct Factory
{
    //CREA MAQUINAS BANDAS Y PERSONAS
    Machine* cleaner = new Machine("clean",3);
    Machine* filler1 = new Machine("fill",4);
    Machine* filler2 = new Machine("fill",4);
    Machine* capper = new Machine("cap",1);

    Queue* band1 = new Queue(100);
    Queue* bandP2 = new Queue(50);
    Queue* bandP3 = new Queue(80);
    Queue* band4 = new Queue(10);
    Queue* band5 = new Queue(120);

    Person* setter = new Person("colocador",5);
    Person* checker = new Person("inspector",10);
    Factory() {
        //ARMA LA MAQUINARIA
        setter->setBand(band1);

        cleaner->setBand(bandP2);
        cleaner->setBand(bandP3);

        filler1->setBand(band4);
        filler2->setBand(band4);

        capper->setBand(band5);
    }
    void run(){
        //PROCESO
        Bottle* botella = new Bottle("PITUFA");

        if(setter->status == 0){//SI EL COLOCADOR ESTA APAGADO
            showMessage("No podemos empezar proceso, el colocador esta apagado.");
        }else{//SI EL COLOCADOR ESTA ENCENDIDO
            showMessage("Proceso iniciado.");
            setter->startWork(botella); //agarra la botella y la pone en la banda 1
            if(cleaner->status == 0){//SI LA MAQUINA DE LIMPIEZA ESTA APAGADA
                showMessage("No podemos seguir con el proceso, la maquina que limpia esta apagada.");
            }else{//SI LA MAQUINA DE LIMPIEZA ESTA ENCENDIDA
                int band = cleaner->startMachine(setter->band->dequeue()->data); //saca la botella de la banda y la mete en la maquina de lavado, y retorna en que banda metio la botella
                if(band == 1){//Si lo metio en la banda 1
                    if(filler1->status == 0){//SI LA MAQUINA DE LLENADO 1 ESTA APAGADA
                        showMessage("No podemos seguir con el proceso, la maquina de llenado 1 esta apagada.");
                    }else{//SI LA MAQUINA DE LLENADO 1 ESTA ENCENDIDA
                        filler1->startMachine(cleaner->band1->dequeue()->data); //saca la botella de la banda 1 y la mete a la maquina de llenado 1
                    }
                }else {//Si la metio en la banda 2
                    if(filler2->status == 0){//SI LA MAQUINA DE LLENADO 2 ESTA APAGADA
                        showMessage("No podemos seguir con el proceso, la maquina de llenado 2 esta apagada.");
                    }else{//SI LA MAQUINA DE LLENADO 2 ESTA ENCENDIDA
                        filler2->startMachine(cleaner->band2->dequeue()->data); //saca la botella de la banda 2 y la mete a la maquina de llenado 2
                    }
                }//En este momento la botella se encuentra en la banda 4
                if(capper->status == 0){//SI LA MAQUINA DE TAPADO ESTA APAGADA
                    showMessage("No podemos seguir con el proceso, la maquina de tapado esta apagada.");
                }else{//SI LA MAQUINA DE TAPADO ESTA ENCEDIDA
                    capper->startMachine(band4->dequeue()->data);//saca la botella de la banda 4, y se la da a la persona que inspecciona
                    if(checker->status == 0){
                        showMessage("No podemos seguir con el proceso, no hay inspector.");
                    }else{
                        checker->startWork(capper->band1->dequeue()->data);
                    }
                }
            }
        }


    }
    void showMessage(string msg){}
};

#endif


