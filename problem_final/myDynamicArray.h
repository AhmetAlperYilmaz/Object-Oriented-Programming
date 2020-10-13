#pragma once
#include <iostream>

template <class Type>
class myDynamicArray{
    private: 
        int capacity;
        int size;
        Type * array;
    public:
        myDynamicArray(){
            std::cout << "new array of capacity=5 has been created" << std::endl;
            capacity = 5;
            size = 0;
            array = new Type[5];
        }
        ~myDynamicArray(){
            delete[] array;
            std::cout << "a dynamic array has been destroyed" << std::endl; 
        }
        int getcapacity(){return this->capacity;}; 
        int getsize(){return this->size;};
        Type* get_head() const{return this->array;};
        void add(Type);
        Type remove();
        void print();
};