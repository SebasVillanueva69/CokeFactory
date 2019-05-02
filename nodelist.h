#ifndef NODELIST_H
#define NODELIST_H
#include <string>
using namespace std;
struct NodeList
{
public:
    NodeList(string type, int per);
    string type;
    int per;
     NodeList *next = nullptr;
     NodeList *prev = nullptr;

};

#endif // NODELIST_H
