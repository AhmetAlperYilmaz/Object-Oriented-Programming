#include "myDynamicArray.h"
#include "myDynamicArray.cpp"
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "bird.h"

#include <iostream>
using namespace std;

int main(){
	dog d2("REX"); 
	const cat c2("Smokey"); 
	cout << d2.getname() << endl; 
	cout << c2.getname() << endl;	
	c2.outputvoice(); 
		
	bird b1("twitty"); 
	bird b2(b1); 
	bird b3;
	b3 = b1;

	return 0;
}
