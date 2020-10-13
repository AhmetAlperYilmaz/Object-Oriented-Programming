#include "bird.h"

bird::bird(string a):animal(4,2){
    this->name = a;
}

void bird::outputvoice() const{
    cout << "twit twit" << endl;
}