#ifndef VAN_H
#define VAN_H
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
using namespace std;

// this class represents a van vehicle
// derived from truck
class Van : public Truck {
    private:
        //attributes
        string van_type;
        int passenger_limit;
    public:
        //constructor
        //if statements used inside the constructor to create multiple constructor cases regarding the 2 types of vans
        Van(int length, int width, double weight, double cost, string brand, string model, string number_plate, int load_volume, int load_capacity, int passenger_limit);
        //default constructor
        Van();

        //getters
        string get_van_type();
        int get_passenger_limit();

        //setters
        void set_van_type(string van_type);
        void set_passenger_limit(int passenger_limit);

        //destructor
        ~Van();
};

#endif