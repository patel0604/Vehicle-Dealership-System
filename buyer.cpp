#include <iostream>
#include <string>
#include "Customer.h"
#include "Van.h"
#include "Dealership.h"
#include "Buyer.h"
using namespace std;

// buyer constructor
Buyer::Buyer(string name, string licence_number, double wallet, int vehicle_amount) : Customer(name, licence_number, wallet, vehicle_amount){}

// function for removing a vehicle from dealership and adding it to buyer array
bool Buyer::vehicle_transaction(string number_plate, Dealership* dealership){
    // if there is space in the buyer array
    if (vehicles_index < vehicle_amount) {
        //return the position of the vehicle with the same number plate
        int vehicle_position = dealership->search_vehicle_number_plate(number_plate);
        // if the vehicle position is valid
        if (vehicle_position != -1) {
            //return the cost of the vehicle
            double vehicle_cost = dealership->get_vehicle_cost(vehicle_position);
            //if the buyer has enough money to pay for the vehicle
            if (wallet > vehicle_cost) {
                //returns the address of the vehicle removed from the dealership
                //The pointer in the buyer array now points to this new address
                vehicles[vehicles_index] = dealership->remove_vehicle(number_plate);
                //vehicles_index increases by 1
                vehicles_index++;
                //the cost of the vehicle is subtracted from the buyer
                change_wallet(-vehicle_cost);
                //the value of the vehicle is added to the dealership's funds
                dealership->change_funds(vehicle_cost);
                cout << "dealership funds: $" << dealership->get_funds() << endl;
                cout << "buyer funds: $" << get_wallet() << endl;
                return true;
            } else {
                cout << "buyer does not have enough funds for transaction -> aborting transaction" << endl;
            }
        } else {
            cout << "number plate could not be found in the dealership -> aborting transaction" << endl;
        }
    } else {
        cout << "buyer does not have enough space for a new vehicle -> aborting transaction" << endl;
    }
    return false;
}

// buyer destructor
Buyer :: ~Buyer(){
    for (int i = 0; i < vehicle_amount; i++) {
        delete vehicles[i];
    }
    delete[] vehicles;
}