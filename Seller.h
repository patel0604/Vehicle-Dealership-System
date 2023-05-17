#ifndef SELLER_H
#define SELLER_H
#include <iostream>
#include <string>
#include "Customer.h"
#include "Van.h"
#include "Dealership.h"
using namespace std;

//inherited from abstract class customer
class Seller : public Customer {
    private:
        //no new attributes
    public:
        Seller(string name, string licence_number, double wallet, int vehicle_amount) : Customer(name, licence_number, wallet, vehicle_amount) {}

        Vehicle initialise_vehicle() {
            //initialise a vehicle and add it to the vector
        }

        void vehicle_transaction() {
            //remove a vehicle from the vector and add it to the dealership
        }

        ~Seller() {
            for (int i = 0; i < vehicle_amount; i++) {
                delete[] vehicles[i];
            }
            delete[] vehicles;
        }
};

#endif