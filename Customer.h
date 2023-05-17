#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include "Van.h"
using namespace std;

//abstract class
class Customer {
    protected:
        string name;
        string licence_number;
        double wallet;
        int vehicle_amount;
        //making a pointer to a pointer of class vehicle 
        Vehicle** vehicles;
    public:
        //constructor for customer
        Customer(string name, string licence_number, double wallet, int vehicle_amount) : name(name), licence_number(licence_number), wallet(wallet), vehicle_amount(vehicle_amount) {
            //making an array of size num_vehicles for all vehicles the customer wants to buy/sell
            vehicles = new Vehicle*[vehicle_amount];
            //initialising an empty array of vehicles
            for (int i = 0; i < vehicle_amount; i++) {
                vehicles[i] = nullptr;
            }

        }

        // getters
        string get_name() {return name;}
        string get_licence_number() {return licence_number;}
        double get_wallet() {return wallet;}
        int get_num_vehicles() {return vehicle_amount;}

        //setters
        void set_name(string name) {this->name = name;}
        void set_licence_number(string licence_number) {this->licence_number = licence_number;}
        void change_wallet(double added_wallet) {wallet += added_wallet;}

        //abstract function for buying/selling vehicles
        virtual void vehicle_transaction() = 0;

        ~Customer() {
            for (int i = 0; i < vehicle_amount; i++) {
                delete[] vehicles[i];
            }
            delete[] vehicles;
        }
};

#endif