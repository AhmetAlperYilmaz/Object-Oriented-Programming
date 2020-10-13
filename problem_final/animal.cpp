#include "animal.h"
#include "myDynamicArray.cpp"
#include <iostream>

using namespace std;

animal::animal(string a, int length, int count){
    this->name = a;
    this->legLength = length;
    this->legCount = count;
    int i = 0;
    leg * ptr = legs.get_head();
    for(i=0;i<count;i++){
        leg * temp = new leg(length);
        ptr[i] = *temp;
    }
}

animal::animal(int length, int count){
    this->legLength = length;
    this->legCount = count;
    int i = 0;
    leg * ptr = legs.get_head();
    for(i=0;i<count;i++){
        leg * temp = new leg(length);
        ptr[i] = *temp;
    }
}

animal::animal(animal& dt){
    this->name = dt.getname();
    this->legLength = dt.legLength;
    this->legCount = dt.legCount;
    this->legs = dt.legs;
    int i = 0;
    leg * ptr = this->legs.get_head();
    leg * ptr2 = dt.legs.get_head();
    for(i=0;i<this->legCount;i++){
        ptr[i] = ptr2[i];
    }
}

ostream& operator<<(ostream& os, const animal& dt)
{
    dt.outputvoice();    
    cout << dt.name;
    return os;
}

void animal::operator=(const animal& dt)
{
    this->name = dt.getname();
    this->legLength = dt.legLength;
    this->legCount = dt.legCount;
    this->legs = dt.legs;
    int i = 0;
    leg * ptr = this->legs.get_head();
    leg * ptr2 = dt.legs.get_head();
    for(i=0;i<this->legCount;i++){
        ptr[i] = ptr2[i];
    }
}