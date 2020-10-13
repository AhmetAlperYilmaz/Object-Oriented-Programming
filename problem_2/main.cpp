#include <iostream>

/* Ahmet Alper Yılmaz 150180037 
   g++ main.cpp -o main */

// Classes
class Person{
    private:
        std::string name;
        std::string surname;
    public:
        Person();
        Person(std::string,std::string);
        void setName(std::string & Name){this->name = Name;}
        void setSurname(std::string & Surname){this->surname = Surname;}
        std::string getName(){return this->name;}
        std::string getSurname(){return this->surname;}
        ~Person();
};

class Owner:public Person{
    private:    
        double ownership;
    public:
        Owner();
        Owner(std::string,std::string);
        void setownership(int owners){ownership = 100.0 / owners;}
        double getownership(){return this->ownership;}
        ~Owner();
};

class Courier:public Person{
    private:
        std::string vehicle_type;
        int vehicle_capacity;
        Courier * next;
    public:
        Courier(std::string,std::string,std::string);
        Courier * getnext(){return this->next;}
        void setnextnull(){this->next = NULL;}
        void setnext(Courier *c,Courier &obj){c->next = &obj;}
        void setnext(Courier *c,Courier *c2){c->next = c2->next;}
        std::string getvehicle_type(){return vehicle_type;}
        bool operator==(Courier);
        ~Courier();
};

class Business{
    private:
        std::string name;
        std::string address;
        Owner* owner_array;
        Courier* courier_array;
        int number_of_owners;
    public:
		Business(std::string,std::string,Owner*,int);
        void hire_courier(Courier);
        void fire_courier(Courier);
        void list_couriers();
        void list_owners();
        int calculate_shipment_capacity();
        void operator()();
        Courier operator[](int);
        ~Business();
};

//Person
Person::Person(){
    this->name = " ";
    this->surname = " ";
}

Person::~Person(){
    //delete name;
    //delete surname;
}

//Owner
Owner::Owner(){
    this->ownership = 0.0;
}

Owner::Owner(std::string name,std::string surname){
    setName(name);
    setSurname(surname);
    this->ownership = 0.0;
}

Owner::~Owner(){
    //delete ownership;
}

//Courier
Courier::Courier(std::string name,std::string surname,std::string vehicle_type){
    if(vehicle_type == "car" || vehicle_type == "bicycle" || vehicle_type == "motorcycle"){
        setName(name);
        setSurname(surname);
        this->next = NULL;
        this->vehicle_type = vehicle_type;
    }
    else{
        std::cout << "Invalid vehicle type!! Constructor failed!!" << std::endl; 
    }
}

bool Courier::operator==(Courier courier){
    if(this->getName() == courier.getName() && this->getSurname() == courier.getSurname() && this->getvehicle_type() == courier.getvehicle_type()){
        return true;        
    }
    else{
        return false;
    }
}

Courier::~Courier(){
    //delete vehicle_type;
    //delete vehicle_capacity;
    //delete next;
}

//Business
Business::Business(std::string name, std::string address, Owner* array, int owners){
    this->name = name;
    this->address = address;
    owner_array = array;
    courier_array = NULL;
    number_of_owners = owners;
    int i = 0;
    for(i=0;i<owners;i++){
        owner_array[i].setownership(owners);
    }
}

void Business::hire_courier(Courier courier){
    if(courier_array == NULL){
        courier_array = &courier;
        courier_array->setnextnull();
    }
    else{
        Courier * iter = courier_array;
        while(iter->getnext() != NULL){
            iter = iter->getnext();
        }
        iter->setnext(iter,courier);
    }
}

void Business::fire_courier(Courier courier){
    Courier * iter = courier_array;
    if((*iter) == courier){
        courier_array = courier_array->getnext();
        //delete iter;
        return;        
    }
    while(iter->getnext() != NULL){
        if((*iter->getnext()) == courier){
            Courier * temp = &courier;
            iter->setnext(iter,temp);
            //delete temp;
            return;
        }
        iter = iter->getnext();
        if(iter->getnext() == NULL){
            std::cout << "There is no courier like that!" << std::endl;
            return;
        }
    }
}

void Business::list_couriers(){
    Courier * iter = courier_array;
    while(iter != NULL){
        std::cout << iter->getName() << " ";
        std::cout << iter->getSurname() << " ";
        std::cout << iter->getvehicle_type() << std::endl;
        iter = iter->getnext();
    }
}

void Business::list_owners(){
    Owner * iter = owner_array;
    int i;
    for(i=0;i<this->number_of_owners;i++){
        std::cout << owner_array[i].getName() << " ";
        std::cout << owner_array[i].getSurname() << " ";
        std::cout << owner_array[i].getownership() << std::endl;
    }
}

int Business::calculate_shipment_capacity(){
    int total = 0;
    Courier * iter = courier_array;
    while(iter != NULL){
        std::string vehicletype = iter->getvehicle_type();
        if(vehicletype == "car")
        {
            total += 200;
        }
        else if(vehicletype == "bicycle"){
            total += 10;
        }
        else if(vehicletype == "motorcycle"){
            total += 35;
        }
        iter = iter->getnext();        
    }
    return total;
}

void Business::operator()(){
    std::cout << this->name << " ";
    std::cout << this->address << std::endl;
    list_owners();
    list_couriers();
}

Courier Business::operator[](int target){
    int counter = 0;
    Courier * iter = courier_array;
    if(target < 0){
        std::cout << "Invalid index value!!" << std::endl;
        return *courier_array;
    }
    else{
        while(iter != NULL){
            if(counter == target){
                return *iter;
            }
            iter = iter->getnext();
            counter++;
            if(iter == NULL){
                std::cout << "Could not find the index value!!" << std::endl;
                return *courier_array;
            }
        }
        return *courier_array;
    }
}

Business::~Business(){
    //delete name;
    //delete address;
    delete[] owner_array;
    Courier * iter = this->courier_array;
    while(iter != NULL){
        Courier * temp = iter->getnext();
        //delete iter;
        iter = temp;
    }
    //delete number_of_owners;
}

int main(){
    // Create owners of the business
    //Constructor parameters: name, surname
    Owner o1 = Owner("Owner_name1", "surname1");
    Owner o2 = Owner("Owner_name2", "surname2");
    Owner* owner_arr = new Owner[2];
    owner_arr[0] = o1;
    owner_arr[1] = o2;    

    //Crete the business itself
    //Constructor parameters: name, address, owner_array, number_of_owners
    Business atlas = Business("Atlas", "Maslak Istanbul/Turkey", owner_arr, 2);
    
    // Print owner info to screen: name, surname, ownership
    atlas.list_owners();

    // Add new employees
    // Constructor parameters: name, surname, vehicle_type
    Courier c1 = Courier("Courier", "surname1", "car");
    Courier c2 = Courier("Courier", "surname2", "motorcycle");
    Courier c3 = Courier("Courier", "surname3", "motorcycle");    

    atlas.hire_courier(c1);
    atlas.hire_courier(c2);
    atlas.hire_courier(c3);

    // Print business info to screen
    // Name, address, owners, couriers
    atlas();

    // Get courier with index 1 and remove it from the list/array
    Courier cour = atlas[1];
    atlas.fire_courier(cour);
    
    // Print remaining couriers
    atlas.list_couriers();
    
    // Print current maximum shipment capacity
    std::cout << atlas.calculate_shipment_capacity() << std::endl;
    return 0;
}