#pragma once
#include <iostream>
#include <string>
#include "myDynamicArray.h"

#include "leg.h"

using namespace std;


class animal{
    protected:
        string name;
        int legLength;
        int legCount;
        myDynamicArray<leg> legs;
    public:
        animal(){};
        animal(string a){this->name = a;};
        animal(string a, int length, int count);
        animal(int length, int count);
        animal(animal&);
        string getname() const {return this->name;};
        virtual void outputvoice() const = 0;
        friend ostream& operator<<(ostream& os, const animal& dt);
        void operator=(const animal& dt);
        myDynamicArray<leg> get_legs(){return legs;};
};
