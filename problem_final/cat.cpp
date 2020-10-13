#include "cat.h"
#include <iostream>
using namespace std;

cat::cat(string a):animal(20,4){
    this->name = a;
}

void cat::outputvoice() const{
    cout << "meow meow" << endl;
}