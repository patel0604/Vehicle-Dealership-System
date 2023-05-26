#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include "Van.h"
#include "Dealership.h"
using namespace std;

// this class represents a customer which is the abstract parent of buyer and seller
// abstract class
class Customer {
    protected:
        string name;
        string licence_number;
        double wallet;
        // number of vehicles the customer wants to buy/sell
        int vehicle_amount;
        // used as the index for the vehicles array, starts at 0
        int vehicles_index;
        // making a pointer to a pointer of class vehicle 
        Vehicle** vehicles;
    public:
        // constructor for customer
        Customer(string name, string licence_number, double wallet, int vehicle_amount);

        // getters
        string get_name();
        string get_licence_number();
        double get_wallet();
        int get_num_vehicles();

        // setters
        void set_name(string name);
        void set_licence_number(string licence_number);
        void change_wallet(double added_wallet);

        // abstract function for buying/selling vehicles
        virtual bool vehicle_transaction(string number_plate, Dealership* dealership) = 0;

        // display all customer vehicles
        void display_vehicles();

        // destructor
        ~Customer();
};

#endif