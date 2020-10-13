#pragma once
#include "animal.h"

class bird: public animal{
    public:
        using animal::animal;
        bird():animal(4,2){};
        bird(string);
        void outputvoice() const;
};
