#ifndef BUYER_H
#define BUYER_H
#include <iostream>
#include <string>
#include "Customer.h"
#include "Van.h"
#include "Dealership.h"
using namespace std;

//inherited from abstract class customer
class Buyer : public Customer {
    private:
        //no attributes
    public:
        //buyer constructor
        Buyer(string name, string licence_number, double wallet, int vehicle_amount);

        //buying vehicles from the dealership if the buyer has enough funds
        bool vehicle_transaction(string number_plate, Dealership* dealership);

        ~Buyer();
};

#endif