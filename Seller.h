#ifndef SELLER_H
#define SELLER_H
#include <iostream>
#include <string>
#include "Customer.h"
#include "Van.h"
using namespace std;

class Seller : public Customer {
    private:

    public:
        Seller(string name, string licence_number, double wallet, int num_vehicles) : Customer(name, licence_number, wallet, num_vehicles) {}

        Vehicle initialise_vehicle() {
            //initialise a vehicle and add it to the vector
        }

        void vehicle_transaction() {
            //remove a vehicle from the vector and add it to the dealership
        }

        ~Seller() {}
};

#endif