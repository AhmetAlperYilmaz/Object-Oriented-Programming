#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <string>

using namespace std;
// Classes, constructors, destructors and function declarations

class Drink{ // addition class to make a linked list of drinks
	private:
		string drink; // name of the drink
		int amount; // how many of them?
		Drink * next; // Drink to Drink next pointer
	public:
		Drink(); // default constructor
		~Drink(); // destructor
		void drinkinsert(string, Drink *); // inserting a drink to the drinklist
        void drinkcheck(int, Drink *); // checking the number of choice for example 1.cola, 2.soda etc.
        void printdrinklist(Drink *); // printing the linked drinklist, subfunction in printOrder
		string getdrinkname(); // getter methods
		int getamount();
		Drink * getnext();			
};

class Pizza{
	private:	
		string name; // name of the pizza
		string size; // small normal big
		string * ingredients;
		string crust_type; // thin normal thick
		Pizza * next; // Pizza to Pizza next pointer
	public:		
		Pizza(); // default constructor
		Pizza(string size, string crust_type, int pizza_type); // constructor with 3 parameters 
		Pizza(Pizza &); // copy constructor
		~Pizza(); // destructor
		void pizzainsert(int, Pizza *); // inserting a pizza to the pizzalist
		void printpizzalist(Pizza *); // printing the linked pizzalist, subfunction in printOrder
		string getsize(); // getter methods
		Pizza * getnext();
};

class Order{
	private:	
		string customer; // name of the customer
		Pizza * pizza; // for pointing the first pizza of the pizzalist
		Drink * drink; // for pointing the first drink of the drinklist
		Order * next; // Order to Order next pointer
	public: // there is no default constructor, we do not need it
		Order(string customer, Pizza * pizza, Drink * drink); //  constructor with 3 parameters 
		Order(string customer, Pizza * pizza); // constructor with 2 parameters
		~Order(); // destructor
		double getPrice(); // gets the price of the order
		void printOrder(); // printing the selected order
		string getcustomer(); // getter and setter methods
		Order * getnext();
		void setnext(Order *);
		void setnext_to_next();
		void setnext_to_null();
};

class OrderList{
	private:
		int n; // total number of orders
		Order * head; // orders head pointer
	public:
		OrderList(); // default constructor
		~OrderList(); // destructor
		void orderinsert(Order *); // inserting the selected order to the orderlist, subfunction of takeOrder 
		void takeOrder(); // adding an order to the orderlist
		void listOrders(); // listing all orders and printing them with printOrder
		void deliverOrders(); // delivering selected order
};

Drink::Drink(){
	this->drink = " ";
	this->amount = 0;
	this->next = NULL;
}

Drink::~Drink(){
	delete next;
}

Pizza::Pizza(){
	this->name = " ";
	this->size = "medium";
	this->crust_type = "normal";
	this->ingredients = new string[6];
	this->ingredients[0] = "mozarella";
	this->next = NULL;  
}

Pizza::Pizza(string size, string crust_type, int pizza_type){ // checking pizza type and adding details
		if(pizza_type == 1){
			this->name = "Chicken Pizza";
			this->ingredients = new string[6];
			this->ingredients[0] = "mozarella";
			this->ingredients[1] = "chicken";
			this->ingredients[2] = "mushroom";
			this->ingredients[3] = "corn";
			this->ingredients[4] = "onion";
			this->ingredients[5] = "tomato";
			this->crust_type = crust_type;
			this->size = size;
			this->next = NULL; 
		}
		else if(pizza_type == 2){
			this->name = "Broccoli Pizza";
			this->ingredients = new string[6];
			this->ingredients[0] = "mozarella";
			this->ingredients[1] = "broccoli";
			this->ingredients[2] = "pepperoni";
			this->ingredients[3] = "olive";
			this->ingredients[4] = "corn";
			this->ingredients[5] = "onion";
			this->crust_type = crust_type;
			this->size = size;
			this->next = NULL; 
		}
		else if(pizza_type == 3){
			this->name = "Sausage Pizza";
			this->ingredients = new string[6];
			this->ingredients[0] = "mozarella";
			this->ingredients[1] = "sausage";
			this->ingredients[2] = "tomato";
			this->ingredients[3] = "olive";
			this->ingredients[4] = "mushroom";
			this->ingredients[5] = "corn";
			this->crust_type = crust_type;
			this->size = size;
			this->next = NULL; 
		}		
}

Pizza::Pizza(Pizza &p){ 
	this->name = p.name; // copying dataset
	this->ingredients = new string[6];
	this->ingredients[0] = p.ingredients[0];
	this->ingredients[1] = p.ingredients[1];
	this->ingredients[2] = p.ingredients[2];
	this->ingredients[3] = p.ingredients[3];
	this->ingredients[4] = p.ingredients[4];
	this->ingredients[5] = p.ingredients[5];
	this->crust_type = p.crust_type;
	this->size = p.size;
	this->next = NULL; // asking the removing ingredients
	cout << "Please enter the number of the ingredient you want to remove from pizza." << endl;
	int i = 0;
	for(i=0;i<6;i++){
		cout << i+1 << ". " << this->ingredients[i] << endl; 
	}
	cout << "Press 0 to save it." << endl;
	int choice;
	while(true){
		cin >> choice;
		if((choice > 0) && (choice < 7)){
			this->ingredients[choice-1] = " "; // changing removed ingredient with blank
		}
		else if(choice == 0){
			break;
		}
		else{
			cout << "You have entered an invalid value, please enter a valid value!" << endl;
		}
	}		
}

Pizza::~Pizza(){
	delete[] ingredients;
	delete next;
}

Order::Order(string customer, Pizza * pizza, Drink * drink){
	this->customer = customer;
	this->pizza = pizza;
	this->drink = drink;
	this->next = NULL;
} 

Order::Order(string customer, Pizza * pizza){
	this->customer = customer;
	this->pizza = pizza;
	this->drink = NULL;
	this->next = NULL;
}

Order::~Order(){
	delete pizza;
	delete drink;
}

OrderList::OrderList(){
	this->n = 0;
	this->head = NULL;
}

OrderList::~OrderList(){
	delete head;
}
#endif

