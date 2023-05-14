#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"
using namespace std;

class Truck : public Car {
    protected:
        int load_volume;
        int load_capacity;
    public:
        Truck():Car(){
            load_volume = 0;
            load_capacity = 0;
        }
        Truck(int length, int width, double weight, double cost, string brand, string model, string number_plate, int load_volume, int load_capacity) : Car(length, width, weight, cost, brand, model, number_plate) {
            this->load_volume = load_volume;
            this->load_capacity = load_capacity;
        }

        int get_load_volume() {return load_volume;}
        int get_load_capacity() {return load_capacity;}

        ~Truck() {}
};

#endif