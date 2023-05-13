#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
using namespace std;

class Customer {
    protected:
        string name;
        string licence_number;
        double wallet;
        int num_vehicles;
        //pointer to pointer of an array of class vehicles
    public:
        Customer(string name, string licence_number, double wallet, int num_vehicles) : name(name), licence_number(licence_number), wallet(wallet), num_vehicles(num_vehicles) {
            //initialising the vector
        }

        string get_name() {return name;}
        string get_licence_number() {return licence_number;}
        double get_wallet() {return wallet;}
        int get_num_vehicles() {return num_vehicles;}

        void set_name(string name) {this->name = name;}
        void set_licence_number(string licence_number) {this->licence_number = licence_number;}
        void change_wallet(double added_wallet) {wallet += added_wallet;}

        ~Customer() {}
};

#endif