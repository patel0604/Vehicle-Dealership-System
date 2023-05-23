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
        Seller(string name, string licence_number, double wallet, int vehicle_amount) : Customer(name, licence_number, wallet, vehicle_amount) {}

        //return the index of the vehicle from its number plate
        int get_vehicle_index(string number_plate) {
            //cout << "attempting to get index from number plate - debug message" << endl;
            for (int i = 0; i < vehicle_amount; i++) {
                if (vehicles[i] != nullptr) {
                    if (vehicles[i]->get_number_plate() == number_plate) {
                        return i;
                    }
                }
            }
            return -1;
        }

        //function for initialising the vehicles in the array to be sold
        void initialise_vehicles() {
            //if there is enough space in the array the for loop commences
            for (vehicles_index = 0; vehicles_index < vehicle_amount; vehicles_index++) {
                cout << "new loop started - debug message" << endl;
                bool loop = true;
                while (loop) {
                    string vehicle_type;
                    cout << "enter 'car', 'truck' or 'van' for the type of vehicle you want to initialise" << endl;
                    cin >> vehicle_type;
                    cin.ignore();
                    if (vehicle_type == "car" || vehicle_type == "truck" || vehicle_type == "van") {
                        MakeVehicle makeVehicle;
                        vehicles[vehicles_index] = makeVehicle.initialise_vehicle(vehicle_type);
                        loop = false;
                    } else {
                        cout << "entered wrong vehicle type entered, please try again" << endl;
                    }
                }
            }
        }

        //remove a vehicle from the vector and add it to the dealership using its pointer
        bool vehicle_transaction(string number_plate, Dealership* dealership) {
            //check if there are any vehicles in the array
            if (vehicles_index > 0) {
                cout << "there are seller vehicles to be sold - debug message" << endl;
                int index = get_vehicle_index(number_plate);
                if (index != -1) {
                    cout << "found index from number plate - debug message" << endl;
                    //get the cost of the vehicle
                    double cost = vehicles[index]->get_cost();
                    //if dealership has enough funds to
                    if (dealership->get_funds() > cost) {
                        cout << "dealership has sufficient funds for transaction" << endl;
                        //add the car to the dealership
                        bool state = dealership->add_vehicle(vehicles[index]);
                        //if the function works as intended
                        if (state == true) {
                            //free the pointer
                            delete vehicles[index];
                            cout << "seller vehicle pointer deleted - debug message" << endl;
                            //create a placeholder default vehicle in its place to be deleted in the destructor
                            vehicles[index] = new Vehicle;
                            cout << "pointer set to default vehicle" << endl;
                            //subtract the cost of the vehicle from the dealership
                            dealership->change_funds(-cost);
                            cout << "funds subtracted from dealership" << endl;
                            //add the cost of the car to the seller
                            change_wallet(cost);
                            cout << "funds added to seller" << endl;
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

        //maybe add a function for selling all vehicles in the seller array
        //this can be used to automate the selling process

        ~Seller() {
            for (int i = 0; i < vehicle_amount; i++) {
                delete vehicles[i];
            }
            delete[] vehicles;
            cout << "seller destructor called - debug message" << endl;
        }
};

#endif