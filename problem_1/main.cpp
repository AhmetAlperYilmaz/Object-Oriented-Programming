#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

/*	Ahmet Alper Yılmaz
*/

void Drink::drinkinsert(string thedrink, Drink * drinklist){ // inserting drink to the drinklist
      Drink *iter = drinklist;
      if(drinklist->drink == " "){ // if it will be the first drink in the list
            drinklist->drink = thedrink;
            drinklist->amount++;
      }
      else{ // adding the drink and changing amount of it
            while(true){
                if(iter->drink == thedrink){
                    iter->amount++;
                    break;
                }
                else if(iter->next == NULL){
                    iter->next = new Drink;
                    iter->next->drink = thedrink;
                    iter->next->amount = 1;
                    break;
                }
            iter = iter->next;
            }   
      } 
}

void Drink::drinkcheck(int drinkchoice, Drink * drinklist){ // checking the choice and passing drinkinsert
    if(drinkchoice == 1){
        string thedrink = "cola";
        drinkinsert(thedrink,drinklist);
    }
    else if(drinkchoice == 2){
        string thedrink = "soda";
        drinkinsert(thedrink,drinklist);
    }
    else if(drinkchoice == 3){
        string thedrink = "ice tea";
        drinkinsert(thedrink,drinklist);
    }
    else if(drinkchoice == 4){
        string thedrink = "fruit juice";
        drinkinsert(thedrink,drinklist);
    }
}

void Drink::printdrinklist(Drink * drinklist){ // printing drinks with an iterator
        Drink * iter = drinklist;
        while(iter != NULL){
            cout << iter->amount << " ";
            cout << iter->drink << ", ";
            iter = iter->next;
        }
        cout << endl;
        cout << "------------" << endl;    
}

string Drink::getdrinkname(){
	return this->drink;
}

int Drink::getamount(){
	return this->amount;
}

Drink * Drink::getnext(){
	return this->next;
}

void Pizza::pizzainsert(int amount, Pizza * pizzalist){ // inserting pizzas with an iterator
	Pizza * iter = pizzalist;
	int i=1;
	for(i=1;i<amount;i++){
		Pizza * aPizza = new Pizza(*pizzalist);
		iter->next = aPizza;
		iter = iter->next;
	}
}	

void Pizza::printpizzalist(Pizza * pizzalist){ // printing pizzas and its ingredients with an iterator
		Pizza * iter = pizzalist;
		while(iter != NULL){
			int i=0;
			cout << iter->name << "(";
			for(i=0;i<6;i++){
				if(iter->ingredients[i] != " "){ // if it is blank, do not print it (removed in copy constructor)
					cout << iter->ingredients[i] << ", ";
				}
			}
			cout << ")" << endl;
			cout << "size: " << iter->size << ", ";
			cout << "crust: " << iter->crust_type << endl;
			cout << endl;
			iter = iter->next;
		}
}

string Pizza::getsize(){
	return this->size;
}

Pizza * Pizza::getnext(){
	return this->next;
}

double Order::getPrice(){ // adding specific prices according to selected pizza sizes and drink types
	double total = 0.0;
	Pizza * iterpizza = this->pizza;
	while(iterpizza != NULL){ // iterating in pizzalist
		if(iterpizza->getsize() == "small"){
			total += 15;
		}
		else if(iterpizza->getsize() == "medium"){
			total += 20;
		}
		else if(iterpizza->getsize() == "big"){
			total += 25;
		}
		iterpizza = iterpizza->getnext();
	}
	Drink * iterdrink = this->drink;
	while (iterdrink != NULL){ // iterating in drinklist
		if(iterdrink->getdrinkname() == "cola"){
			total += (iterdrink->getamount() * 4);
		}
		else if(iterdrink->getdrinkname() == "soda"){
			total += (iterdrink->getamount() * 2);
		}
		else if(iterdrink->getdrinkname() == "ice tea"){
			total += (iterdrink->getamount() * 3);
		}
		else if(iterdrink->getdrinkname() == "fruit juice"){
			total += (iterdrink->getamount() * 3.5);
		}
		iterdrink = iterdrink->getnext();
	}
	return total;
}

void Order::printOrder(){ // printing the selected Order with subfunctions
	cout << "Name: " << this->customer << endl;
	cout << endl;
	if(this->pizza != NULL){
		this->pizza->printpizzalist(this->pizza);
	}
	if(this->drink == NULL){
		cout << endl;
		cout << "------------" << endl;
	}
	else{
		this->drink->printdrinklist(this->drink);		
	}
}

string Order::getcustomer(){
	return this->customer;
}

Order * Order::getnext(){
	return this->next;
}

void Order::setnext(Order * order){
	this->next = order;
}

void Order::setnext_to_next(){
	this->next = this->next->next;
}

void Order::setnext_to_null(){
	this->next = NULL;
}

void OrderList::orderinsert(Order * order){ // inserting orders
	if(this->head == NULL){ // checking if orderlist has no orders
		this->head = order;
		this->n++;
	}
	else{ // inserting order to appropriate place
		Order * iter = this->head;
		while(iter->getnext() != NULL){
			iter = iter->getnext();
		}
		iter->setnext(order);
		iter = iter->getnext();
		iter->setnext_to_null();
		this->n++;
	}	
}

void OrderList::takeOrder(){
	int choice;
	string sizechoice;
	string crustchoice;
	int amount;
	cout << "Pizza Menu" << endl; // asking the details
	cout << "1. Chicken Pizza (mozarella, chicken, mushroom, corn, onion, tomato)" << endl;
	cout << "2. Broccoli Pizza (mozarella, broccoli, pepperoni, olive, corn, onion)" << endl;
	cout << "3. Sausage Pizza (mozarella, sausage, tomato, olive, mushroom, corn)" << endl;
	cout << "0. Back to main menu" << endl;
	cin >> choice;
	if(choice == 0){
		return;
	}
	else if(choice > 3 && choice < 0 ){
		cout << "You have entered an invalid value, please enter a valid value!" << endl;
		return;
	}
	cout << "Select size: small(15 TL), medium (20 TL), big (25 TL)" << endl;
	cin >> sizechoice;
	cout << "Select crust type: thin, normal, thick" << endl;
	cin >> crustchoice;
	cout << "Enter the amount:";
	cin >> amount;
	cout << endl;
	Pizza * pizzalist;
	Pizza * OrderingPizza = new Pizza(sizechoice,crustchoice,choice); // creating pizzalist
	if(amount == 1){
		pizzalist = OrderingPizza; 
	}
	else if(amount > 1){
		pizzalist = OrderingPizza;
		pizzalist->pizzainsert(amount,pizzalist);
	}
	cout << "Please choose a drink:" << endl;
	cout << "0. no drink" << endl;
	cout << "1. cola 4 TL" << endl;
	cout << "2. soda 2 TL" << endl;
	cout << "3. ice tea 3 TL" << endl;
	cout << "4. fruit juice 3.5 TL" << endl;
	cout << "Press -1 for save your order" << endl;
	int drinkchoice;
	Drink * drinklist = new Drink; // creating drinklist
	while(true){
		cin >> drinkchoice;
		if(drinkchoice == 0){
			break;
		}
		else if(drinkchoice == -1){
			break;
		}
		else if(drinkchoice > 0 && drinkchoice < 5){
			drinklist->drinkcheck(drinkchoice, drinklist);
		}
	}
	Order * YourOrder; // definition of the adding order
	string nameholder;
	if(drinkchoice == 0){
		cout << "Please enter your name:" << endl;
		cin >> nameholder;
		cout << endl;
		YourOrder = new Order(nameholder,pizzalist); // order is filled with customer name, pizzalist
		this->orderinsert(YourOrder);
		cout << "Your order is saved, it will be delivered when it is ready..."<< endl;
		cout << "------------"<<endl;
		YourOrder->printOrder();
	}
	else{
		cout << "Please enter your name:" << endl;
		cin >> nameholder;
		cout << endl;
		YourOrder = new Order(nameholder,pizzalist,drinklist); // order is filled with customer name, pizzalist, drinklist
		this->orderinsert(YourOrder);
		cout << "Your order is saved, it will be delivered when it is ready..."<< endl;
		cout << "------------"<<endl;
		YourOrder->printOrder();
	}
}

void OrderList::listOrders(){
	Order * iter = this->head;
	if(iter == NULL){ // if orderlist is empty
		cout << "empty" << endl;
		return;
	}
	int i=0;
	for(i=0;i < this->n ;i++){ // printing all orders with iterator using printOrder
		cout << i+1 << endl;
		cout << "------------" << endl;
		iter->printOrder();
		iter = iter->getnext();
	}
}

void OrderList::deliverOrders(){
	if(this->head == NULL){ // if orderlist is empty
		this->listOrders();
		return;
	}
	string customername;
	this->listOrders();
	Order * iter;
	bool isithead = false;
	bool control = true;
	while(control){ // asking for customer name
		iter = this->head;
		cout << "Please write the customer name in order to deliver his/her order: ";
		cin >> customername;
		if(iter->getcustomer() == customername){ // if it is first
			cout << "Following order is delivering..." << endl;
			cout << "------------" << endl;
			iter->printOrder();
			isithead = true;
			control = false;
		}
		else{ // iterating and finding it or could not finding
			while(iter != NULL){
				if(iter->getnext() == NULL){
					cout << "Wrong name. Please try again." << endl;
					return;
				}
				else if(iter->getnext()->getcustomer() == customername){
					cout << "Following order is delivering..." << endl;
					cout << "------------" << endl;
					iter->getnext()->printOrder();
					control = false;
					break;
				}
				iter = iter->getnext();
			}
		}	
	}
	double price; // getting the total price
	if(isithead){	
		price = iter->getPrice();
	}
	else if(!isithead){
		price = iter->getnext()->getPrice();
	}
	char yes_or_no;
	cout << "Total price: " << price << endl;
	while(true){ // promotion discount
		cout << "Do you have a promotion code? (y/n)" << endl;
		cin >> yes_or_no;
		if(yes_or_no == 'y'){
			string promotioncode;
			cout << "Please enter your promotion code: ";
			cin.ignore();
			getline(cin,promotioncode);
			if(promotioncode == "I am a student"){
				price *= 0.9;
				cout << "Discounted price: " << price << endl;
				break;
			}
			else{
				cout << "Promotion code is not accepted." << endl;
			}
		}
		else if(yes_or_no == 'n'){
			break;
		}
		else{
			cout << "You have entered an invalid input, please enter a valid input!" << endl;
		}
	} // deleting the selected order from orderlist because we delivered it
	if(isithead){
		if(iter->getnext() != NULL){
			this->head = iter->getnext();
			Order * temp = iter;
			delete temp;
			this->n--;
		}
		else{
			Order * temp = iter;
			delete temp;
			this->head = NULL;
			this->n--;
		}
	}
	else if(iter->getnext()->getnext() != NULL){
		Order * temp = iter->getnext();
		iter->setnext_to_next();
		delete temp;
		this->n--;
	}
	else if(iter->getnext()->getnext() == NULL){
		Order * temp = iter->getnext();
		delete temp;
		iter->setnext_to_null();
		this->n--;
	}
	cout << "The order is delivered succesfully!" << endl;
	cout << endl;	
}

int main(){
	OrderList * OL = new OrderList;
	int choice;
	while(true){ // user interface
		cout << "Welcome to Unicorn Pizza!" << endl;
		cout << "1. Add an order" << endl;
		cout << "2. List orders" << endl;
		cout << "3. Deliver order" << endl;
		cout << "4. Exit" << endl;
		cout << "Choose what to do: ";
		cin >> choice;
		if(choice == 1){
			OL->takeOrder();
		}
		else if(choice == 2){
			OL->listOrders();
		}
		else if(choice == 3){
			OL->deliverOrders();
		}
		else if(choice == 4){
			break;
		}
		else{
			cout << "You have entered an invalid value, please enter a valid value!" << endl;
		}
	}
	delete OL;
	return 0;
}
