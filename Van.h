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
        //passenger
        Van(int length, int width, double weight, double cost, string brand, string model, string number_plate, int load_capacity, int passenger_limit) {
            this->length = length;
            this->width = width;
            this->cost = cost;
            this->brand = brand;
            this->model = model;
            this->number_plate = number_plate;
            this->load_capacity = load_capacity;
            this->passenger_limit = passenger_limit;
            van_type = "passenger";
            load_volume = 0;
        }

        //transport
        Van(int length, int width, double weight, double cost, string brand, string model, string number_plate, int load_volume, int load_capacity) : Truck(length, width, weight, cost, brand, model, number_plate, load_volume, load_capacity) {
            van_type = "transport";
            passenger_limit = 0;
        }

        string get_van_type() {return van_type;}
        int get_passenger_limit() {return passenger_limit;}
};

#endif