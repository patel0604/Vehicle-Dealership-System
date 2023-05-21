#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include "Van.h"
#include "Dealership.h"
using namespace std;

//abstract class
class Customer {
    protected:
        string name;
        string licence_number;
        double wallet;
        //number of vehicles the customer wants to buy/sell
        int vehicle_amount;
        //used as the index for the vehicles array, starts at 0
        int vehicles_index;
        //making a pointer to a pointer of class vehicle 
        Vehicle** vehicles;
    public:
        //constructor for customer
        Customer(string name, string licence_number, double wallet, int vehicle_amount) : name(name), licence_number(licence_number), wallet(wallet), vehicle_amount(vehicle_amount) {
            vehicles_index = 0;
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
        virtual bool vehicle_transaction(string number_plate, Dealership* dealership) = 0;

        //display all customer vehicles
        void display_vehicles() {
            cout << "list of vehicles:" << endl;
            for (int i = 0; i < vehicles_index; i++) {
                if (vehicles[i] != nullptr) {
                    //if car
                    if (vehicles[i]->get_vehicle_type() == "car") {
                        cout << vehicles[i]->get_brand() << " " << vehicles[i]->get_model() << ", licence plate: " << vehicles[i]->get_number_plate();
                        cout << ", dimensions: " << vehicles[i]->get_length() << " x " << vehicles[i]->get_width() << "cm, weight: " << vehicles[i]->get_weight();
                        cout << "kg, cost: $" << vehicles[i]->get_cost() << endl;
                    }
                    //if truck
                    if (vehicles[i]->get_vehicle_type() == "truck") {
                        cout << vehicles[i]->get_brand() << " " << vehicles[i]->get_model() << ", number plate: " << vehicles[i]->get_number_plate();
                        cout << ", dimensions: " << vehicles[i]->get_length() << " x " << vehicles[i]->get_width() << "cm, weight: " << vehicles[i]->get_weight();
                        cout << "kg, cost: $" << vehicles[i]->get_cost() << ", load volume: " << vehicles[i]->get_load_volume();
                        cout << "litres, load capacity: " << vehicles[i]->get_load_capacity() << "kg" << endl;
                    }
                    //if van
                    if (vehicles[i]->get_vehicle_type() == "van") {
                        if (vehicles[i]->get_van_type() == "passenger") {
                            //if the van is of type passenger
                            cout << vehicles[i]->get_brand() << " " << vehicles[i]->get_model() << ", number plate: " << vehicles[i]->get_number_plate();
                            cout << ", van type: passenger, dimensions: " << vehicles[i]->get_length() << " x " << vehicles[i]->get_width() << "cm, weight: " << vehicles[i]->get_weight();
                            cout << "kg, cost: $" << vehicles[i]->get_cost() << ", load capacity: " << vehicles[i]->get_load_capacity();
                            cout << "kg, passenger limit: " << vehicles[i]->get_passenger_limit() << endl;
                        } else if (vehicles[i]->get_van_type() == "transport") {
                            //if the van is of type transport
                            cout << vehicles[i]->get_brand() << " " << vehicles[i]->get_model() << ", number plate: " << vehicles[i]->get_number_plate();
                            cout << ", van type: transport, dimensions: " << vehicles[i]->get_length() << " x " << vehicles[i]->get_width() << "cm, weight: " << vehicles[i]->get_weight();
                            cout << "kg, cost: $" << vehicles[i]->get_cost() << ", load volume: " << vehicles[i]->get_load_volume();
                            cout << "litres, load capacity: " << vehicles[i]->get_load_capacity() << "kg" << endl;
                        } else {
                            cout << "error: neither type passenger or transport - debug message" << endl;
                        }
                    }
                }
            }
        }

        ~Customer() {}
};

#endif