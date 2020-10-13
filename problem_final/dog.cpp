#include "dog.h"
#include <iostream>
using namespace std;

dog::dog(string a):animal(30,4){
    this->name = a;
}

void dog::outputvoice() const{
    cout << "bark bark" << endl;
}