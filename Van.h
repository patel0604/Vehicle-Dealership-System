#ifndef VAN_H
#define VAN_H
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
using namespace std;

//derived from truck
class Van : public Truck {
    private:
        //attributes
        string van_type;
        int passenger_limit;
    public:
        //constructor
        //if statements used inside the constructor to create multiple constructor cases regarding the 2 types of vans
        Van(int length, int width, double weight, double cost, string brand, string model, string number_plate, int load_volume, int load_capacity, int passenger_limit) {
            if (length > 0 && width > 0 && weight > 0 && cost >= 0 && brand != "" && model != "" && load_capacity > 0) {
                if (load_volume == 0 && passenger_limit != 0) {
                    vehicle_type = "van";
                    van_type = "passenger"; 
                    this->length = length;
                    this->width = width;
                    this->weight = weight;
                    this->cost = cost;
                    this->brand = brand;
                    this->model = model;
                    this->number_plate = number_plate;
                    this->load_volume = 0;
                    this->load_capacity = load_capacity;
                    this->passenger_limit = passenger_limit;
                    cout << "initialised passenger van" << endl;
                } else if(passenger_limit == 0 && load_volume != 0) {
                    vehicle_type = "van";
                    van_type = "transport";
                    this->length = length;
                    this->width = width;
                    this->weight = weight;
                    this->cost = cost;
                    this->brand = brand;
                    this->model = model;
                    this->number_plate = number_plate;
                    this->load_volume = load_volume;
                    this->load_capacity = load_capacity;
                    this->passenger_limit = 0;
                    cout << "initialised transport van" << endl;
                } else {
                    cout << "wrong inputs for van type" << endl;
                    van_type = "N/A";
                }
            } else {
                cout << "invalid input values for constructor" << endl;
            }
        }
        //default constructor
        Van() : Truck() {
            passenger_limit = 0;
        }

        //getters
        string get_van_type() {return van_type;}
        int get_passenger_limit() {return passenger_limit;}

        //setters
        void set_van_type(string van_type) {
            this->van_type = van_type;
        }
        void set_passenger_limit(int passenger_limit) {
            this->passenger_limit = passenger_limit;
        }

        //destructor
        ~Van() {}
};

#endif