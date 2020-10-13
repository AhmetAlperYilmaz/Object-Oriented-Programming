#include "myDynamicArray.h"

using namespace std;

template <class Type>
void myDynamicArray<Type>::add(Type element){
    if(size == capacity){
        Type * temp = new Type[2*capacity];
        int i = 0;
        for(i=0;i<capacity;i++){
            temp[i] = array[i];
        }
        capacity = 2 * capacity;
        cout << "array resized " << capacity << endl;
        delete[] array;
        array = temp;
        array[size] = element;
        size++; 
    }
    else{
        array[size] = element;
        size++;
    }
}
template <class Type>
Type myDynamicArray<Type>::remove(){
    if(!size){
        cout << "empty array" << endl;
        return array[0];
    }
    else if(size == capacity/2){
        Type * temp = new Type[capacity/2];
        Type temptype = array[size-1];
        int i = 0;
        capacity = capacity / 2;
        cout << "array resized " << capacity << endl;
        for(i=0;i<capacity;i++){
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
        size--;
        return temptype;          
    }
    else if(capacity == 5 && size < 3){
        Type * temp = new Type[capacity/2];
        Type temptype = array[size-1];
        capacity = capacity / 2;
        cout << "array resized " << capacity << endl;
        delete[] array;
        array = temp;
        size--;
        return temptype;
    }
    Type * temparray = new Type[capacity];
    Type temp = array[size-1];
    int i = 0;
    for(i=0;i<size-1;i++){
            temparray[i] = array[i];
    }
    delete[] array;
    array = temparray;
    size--;
    return temp;
}
template <class Type> // Q2
void myDynamicArray<Type>::print(){
    int i = 0;
    for(i=0; i<size; i++){
        cout << (*array[i]) << endl;
    }
}