#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"
using namespace std;


//def. constructor
Car::Car():Vehicle(){
    vehicle_type = "car";
    brand = "N/A";
    model = "N/A";
    number_plate = "N/A";
}

// constructor
Car::Car(int length, int width, double weight, double cost, string brand, string model, string number_plate) : Vehicle(length, width, weight, cost) {
    vehicle_type = "car";
    this->brand = brand;
    this->model = model;
    this->number_plate = number_plate;
}

//getters
string Car::get_brand() {return brand;}
string Car::get_model() {return model;}
string Car::get_number_plate() {return number_plate;}
        
//setters
void Car::set_number_plate(string number_plate) {
    this->number_plate = number_plate;
}

//virtual function
void Car::set_brand(string brand) {
    this->brand = brand;
}
//virtual function
void Car::set_model(string model) {
    this->model = model;
}


//destructor
Car::~Car() {}