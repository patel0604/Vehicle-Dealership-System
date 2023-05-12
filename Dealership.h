#ifndef DEALERSHIP_H
#define DEALERSHIP_H
#include <string>
#include <iostream>
using namespace std;

class Dealership {
    private:
        int capacity;
        int num_vehicles;
        string dealership_name;
        double funds;
        int parking_length;
        int parking_width;
        // pointer to a pointer of a vector of vehicles
    public:
        Dealership(string dealership_name, int capacity, double funds, int parking_length, int parking_width){
            this->dealership_name = dealership_name;
            this->capacity = capacity;
            this->funds = funds;
            this->parking_length = parking_length;
            this->parking_width = parking_width;
            num_vehicles = 0;
            // initialise the pointer to pointer
        }
};

#endif