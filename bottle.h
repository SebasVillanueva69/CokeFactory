#ifndef BOTTLE_H
#define BOTTLE_H
#include <string>

using namespace std;

struct Bottle
{
public:
    Bottle(string type);
    string type; //PITUFA(250ml), 1/2LITROS(500ml), 2LITROS(2000ml)

    bool isClean = false; //Pasa por limpia botellas
    bool isEmpty = true; //Llenan
    bool isCap = false; //Se tapan
    bool isCheck = false; //Se inspeccionan
    bool isReady = false; //Se encajan

};

#endif // BOTTLE_H
