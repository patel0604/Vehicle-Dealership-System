#ifndef SELLER_H
#define SELLER_H
#include <iostream>
#include <string>
#include "Customer.h"
#include "Van.h"
#include "Dealership.h"
#include "MakeVehicle.h"

using namespace std;

//inherited from abstract class customer
class Seller : public Customer {
    private:
        //no new attributes
    public:
        //seller constructor
        Seller(string name, string licence_number, double wallet, int vehicle_amount);

        //return the index of the vehicle from its number plate
        int get_vehicle_index(string number_plate);

        //function for initialising the vehicles in the array to be sold
        void initialise_vehicles();

        //remove a vehicle from the vector and add it to the dealership using its pointer
        bool vehicle_transaction(string number_plate, Dealership* dealership);
        //maybe add a function for selling all vehicles in the seller array
        //this can be used to automate the selling process

        ~Seller();
};

#endif