#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"
using namespace std;

// this class represents a truck vehicle
//derived from car
class Truck : public Car {
    protected:
        //attributes
        int load_volume;
        int load_capacity;
    public:
        //defualt constructor
        Truck();
        //constructor
        Truck(int length, int width, double weight, double cost, string brand, string model, string number_plate, int load_volume, int load_capacity);

        //getters
        int get_load_volume();
        int get_load_capacity();

        //setters
        void set_load_volume(int load_volume);
        void set_load_capacity(int load_capacity);

        //destructor
        ~Truck();
};

#endif