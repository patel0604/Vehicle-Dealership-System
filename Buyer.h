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
        Buyer(string name, string licence_number, double wallet, int vehicle_amount) : Customer(name, licence_number, wallet, vehicle_amount) {}

        //buying vehicles from the dealership if the buyer has enough funds
        void vehicle_transaction(string number_plate, Dealership dealership) {
            if (vehicles_index < vehicle_amount) {
                cout << "there is space in buyer array - debug message" << endl;
                //return the position of the vehicle with the same number plate
                int vehicle_position = dealership.search_vehicle_number_plate(number_plate);
                //return the cost of the vehicle
                double vehicle_cost = dealership.get_vehicle_cost(vehicle_position);
                //if the buyer has enough money to pay for the vehicle
                if (wallet > vehicle_cost) {
                    cout << "the buyer has enough funds for transaction - debug message" << endl;
                    //search through the dealership
                    vehicles[vehicles_index] = dealership.remove_vehicle(number_plate);
                    cout << "vehicle added to buyer" << endl;
                    //vehicles_index increases by 1
                    vehicles_index++;
                    //the cost of the vehicle is subtracted from the buyer
                    change_wallet(-vehicle_cost);
                    cout << "funds subtracted from the buyer - debug message" << endl;
                    //the value of the vehicle is added to the dealership's funds
                    dealership.change_funds(vehicle_cost);
                    cout << "funds added to the dealership - debug message" << endl;
                } else {
                    cout << "buyer does not have enough funds for transaction -> aborting transaction" << endl;
                }
            } else {
                cout << "buyer does not have enough space for a new vehicle" << endl;
            }
        }

        ~Buyer() {
            for (int i = 0; i < vehicle_amount; i++) {
                delete[] vehicles[i];
            }
            delete[] vehicles;
        }
};

#endif