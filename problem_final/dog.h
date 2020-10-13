#pragma once
#include "animal.h"
#include <string>

class dog: public animal{
    public:
        using animal::animal;
        dog():animal(30,4){};
        dog(string);
        void outputvoice() const;
};