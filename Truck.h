#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"
using namespace std;

//derived from car
class Truck : public Car {
    protected:
        //attributes
        int load_volume;
        int load_capacity;
    public:
        //defualt constructor
        Truck():Car(){
            vehicle_type = "truck";
            load_volume = 0;
            load_capacity = 0;
        }
        //constructor
        Truck(int length, int width, double weight, double cost, string brand, string model, string number_plate, int load_volume, int load_capacity) : Car(length, width, weight, cost, brand, model, number_plate) {
            vehicle_type = "truck";
            this->load_volume = load_volume;
            this->load_capacity = load_capacity;
        }

        //getters
        int get_load_volume() {return load_volume;}
        int get_load_capacity() {return load_capacity;}

        //destructor
        ~Truck() {}
};

#endif