#ifndef VAN_H
#define VAN_H
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
using namespace std;

class Van : public Truck {
    private:
        string van_type;
        int passenger_limit;
    public:
        Van(int length, int width, double weight, double cost, string brand, string model, string number_plate, int load_volume, int load_capacity, int passenger_limit) {
            if (load_volume == 0 && passenger_limit != 0) {
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
                van_type = "passenger"; 
                cout << "initialised passenger van" << endl;
            } else if(passenger_limit == 0 && load_volume != 0) {
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
                van_type = "transport";
                cout << "initialised transport van" << endl;
            } else {
                cout << "wrong constructor input please try again" << endl;
                van_type = "N/A";
            }
        }

        string get_van_type() {return van_type;}
        int get_passenger_limit() {return passenger_limit;}

        ~Van() {}
};

#endif