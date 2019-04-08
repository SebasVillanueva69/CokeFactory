#ifndef STRUCTS_H
#define STRUCTS_H
#include<stdlib.h>
#include <string>
#include <vector>
using namespace std;

struct Bottle
{
    string type; //PITUFA(250ml), 1/2LITROS(500ml), 2LITROS(2000ml)

    bool isClean; //Pasa por limpia botellas
    bool isEmpty; //Llenan
    bool isCap; //Se tapan
    bool isCheck; //Se inspeccionan
    bool isReady; //Se encajan

    Bottle(string type) {
        this->type = type;
    }
};

struct Person
{
    string type; //Carga o inspeccionan
    int status = 0; //0 = OFF, 1 = ON, 2 = PAUSE
    int speed;
    vector<int> rejectPercentage = {5,20,10}; //0 = pitufas, 1 = 1/2litro, 2 = 2litros
    vector<int> quantityPercentage = {50,25,25}; //0 = pitufas, 1 = 1/2litro, 2 = 2litros
    Person(int speed) {
        this->speed = speed;
    }
    void changeSpeed(int newSpeed){
        this->speed = newSpeed;
    }
    void changeStatus(int newStatus){
        this->status = newStatus;
    }
};

struct Machine
{
    string type;
    std::vector<int> counters = {0,0,0}; //0 = pitufas, 1 = 1/2litro, 2 = 2litros
    int speed;
    int status = 0; //0 = OFF, 1 = ON, 2 = PAUSE
    Machine(int speed, string type) {
        this->speed = speed;
        this->type = type;
    }
    void changeSpeed(int newSpeed){
        this->speed = newSpeed;
    }
    void changeStatus(int newStatus){
        this->status = newStatus;
    }
};

struct trucks
{
    string type;
    std::vector<int> capacity = {0,0,0}; //0 = pitufas, 1 = 1/2litro, 2 = 2litros
    trucks(string type) {
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

#endif // STRUCTS_H
