#include <iostream>
#include <string>
#include "Seller.h"
#include "Customer.h"
#include "Van.h"
#include "Dealership.h"
#include "MakeVehicle.h"
using namespace std;

// constructor
Seller::Seller(string name, string licence_number, double wallet, int vehicle_amount):Customer(name, licence_number, wallet, vehicle_amount){}

// returns the index of the vehicle from the number plate
int Seller::get_vehicle_index(string number_plate){
    for (int i = 0; i < vehicle_amount; i++) {
        if (vehicles[i] != nullptr) {
            if (vehicles[i]->get_number_plate() == number_plate) {
                return i;
            }
        }
    }
    return -1;
}

// asks the user to initialise vehicles
void Seller::initialise_vehicles(){
    // loop through the seller array
    for (vehicles_index = 0; vehicles_index < vehicle_amount; vehicles_index++) {
        bool loop = true;
        while (loop) {
            // ask the vehicle type
            string vehicle_type;
            cout << "enter 'car', 'truck' or 'van' for the type of vehicle you want to initialise" << endl;
            cin >> vehicle_type;
            cin.ignore();
            if (vehicle_type == "car" || vehicle_type == "truck" || vehicle_type == "van") {
                // call the make initialise function inside makeVehicle class
                MakeVehicle makeVehicle;
                vehicles[vehicles_index] = makeVehicle.initialise_vehicle(vehicle_type);
                loop = false;
            } else {
                cout << "entered wrong vehicle type entered, please try again" << endl;
            }
        }
    }
}

// function to sell vehicle to dealership
bool Seller::vehicle_transaction(string number_plate, Dealership* dealership){
    // if there is at least one vehicle in the seller array
    if (vehicles_index > 0) {
        // get the array index
        int index = get_vehicle_index(number_plate);
        if (index != -1) {
            //get the cost of the vehicle
            double cost = vehicles[index]->get_cost();
            //if dealership has enough funds to
            if (dealership->get_funds() > cost) {
                //add the car to the dealership
                bool state = dealership->add_vehicle(vehicles[index]);
                //if the function works as intended
                if (state == true) {
                    //free the pointer
                    delete vehicles[index];
                    //create a placeholder default vehicle in its place to be deleted in the destructor
                    vehicles[index] = new Vehicle;
                    //subtract the cost of the vehicle from the dealership
                    dealership->change_funds(-cost);
                    //add the cost of the car to the seller
                    change_wallet(cost);
                    cout << "dealership funds: $" << dealership->get_funds() << endl;
                    cout << "seller funds: $" << get_wallet() << endl;
                    return true;
                } else {
                    cout << "the vehicle could not be added to the dealership, terminating function" << endl;
                }
            } else {
                cout << "there are not sufficient funds in the dealership for the transaction" << endl;
            }
        } else {
            cout << "vehicle with number plate not found in seller -> Aborting transaction" << endl;
        }
    } else {
        cout << "there are no vehicles in the seller array" << endl;
    }
    return false;
}

// seller destructor
Seller::~Seller() {
    for (int i = 0; i < vehicle_amount; i++) {
        delete vehicles[i];
    }
    delete[] vehicles;
}