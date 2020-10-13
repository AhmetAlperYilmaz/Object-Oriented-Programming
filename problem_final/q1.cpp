#include "myDynamicArray.h"
#include "myDynamicArray.cpp"

#include <iostream>

using namespace std;

int main(){
	myDynamicArray<int> mya;
	
	int a = 5;
	mya.add(a);
	cout << "array size=" << mya.getsize() << " array capacity=" << mya.getcapacity() << endl;
	
	cout << mya.remove() << endl;
	cout << "array size=" << mya.getsize() << " array capacity=" << mya.getcapacity() << endl;
		
	for (int i = 0; i < 65; i++)
		mya.add(i);	
	cout << "array size=" << mya.getsize() << " array capacity=" << mya.getcapacity() << endl;
	
	for (int i = 65; i > 19; i--)
		mya.remove();
	cout << "array size=" << mya.getsize() << " array capacity=" << mya.getcapacity() << endl;
	

	myDynamicArray<int> mya2;
	for (int i = 65; i < 85; i++)
		mya2.add(i);
	cout << "array size=" << mya2.getsize() << " array capacity=" << mya2.getcapacity() << endl;
	
	return 0;
}

