#include "myDynamicArray.h"
#include "myDynamicArray.cpp"
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "bird.h"

#include <iostream>
using namespace std;


int main(){
	myDynamicArray<animal*> myanimals;
	
	dog d1;
	cat c1;

	cout << d1 << endl;
	cout << c1 << endl;

	myanimals.add(&d1);
	myanimals.add(&c1);
	myanimals.print();

	return 0;
}

