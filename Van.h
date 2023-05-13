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
        Van(int length, int width, double weight, double cost, string brand, string model, string number_plate, int load_capacity, int passenger_limit) : Truck(length, width, weight, cost, brand, model, number_plate, load_capacity) {
            this->
        }
};

#endif