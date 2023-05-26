#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Dealership.h"
using namespace std;

//default constructor
Vehicle::Vehicle(){
    vehicle_type = "N/A";
    length = 0;
    width = 0;
    weight = 0;
    cost = 0;
}

// constructor
Vehicle::Vehicle(int length, int width, double weight, double cost) {
    if (length > 0 && width > 0 && weight> 0 && cost >= 0){
        this->length = length;
        this->width = width;
        this->weight = weight;
        this->cost = cost;
        vehicle_type = "N/A";
    }
    else{
        
        cout << "invalid inputs values for constructor"<<endl;
    }
}

//getters
string Vehicle::get_vehicle_type(){return vehicle_type;}

double Vehicle::get_cost(){return cost;}

double Vehicle::get_weight(){return weight;}

int Vehicle::get_length(){return length;}

int Vehicle::get_width(){return width;}

//setters
void Vehicle::set_cost(double cost){
    this->cost = cost;
}

//virtual functions
//car
string Vehicle::get_brand() {return "N/A";}
string Vehicle::get_model() {return "N/A";}
string Vehicle::get_number_plate() {return "N/A";}
void Vehicle::set_number_plate(string number_plate) {}
void Vehicle::set_brand(string brand) {}
void Vehicle::set_model(string model) {}

//virtual functions
//truck
int Vehicle::get_load_volume() {return 0;}
int Vehicle::get_load_capacity() {return 0;}
void Vehicle::set_load_volume(int load_volume) {}
void Vehicle::set_load_capacity(int load_capacity) {}

//virtual functions
//van
string Vehicle::get_van_type() {return "N/A";}
int Vehicle::get_passenger_limit() {return 0;}
void Vehicle::set_van_type(string van_type) {}
void Vehicle::set_passenger_limit(int passenger_limit) {}

// virtual destructor
Vehicle::~Vehicle() {}