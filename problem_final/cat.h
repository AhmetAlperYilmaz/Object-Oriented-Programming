#pragma once
#include "animal.h"
#include <string>

class cat: public animal{
    public:
        using animal::animal;
        cat():animal(20,4){};
        cat(string);
        void outputvoice() const;
};