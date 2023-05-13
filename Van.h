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
        Van(int length, int width, double weight, double cost, string brand, string model, string number_plate, int load_capacity, int passenger_limit) : Truck(length, width, weight, cost, brand, model, number_plate, load_volume, load_capacity) {
            van_type = "passenger";
            this->passenger_limit = passenger_limit;
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