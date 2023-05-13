#ifndef BUYER_H
#define BUYER_H
#include <iostream>
#include <string>
#include "Customer.h"
#include "Van.h"
using namespace std;

class Buyer : public Customer {
    private:

    public:
        Buyer(string name, string licence_number, double wallet, int num_vehicles) : Customer(name, licence_number, wallet, num_vehicles) {}

        void buy_vehicle() {
            //add a vehicle from the dealership to the vector
        }

        ~Buyer() {}
};

#endif