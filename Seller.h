#ifndef SELLER_H
#define SELLER_H
#include <iostream>
#include <string>
#include "Customer.h"
#include "Van.h"
#include "Dealership.h"
using namespace std;

//inherited from abstract class customer
class Seller : public Customer {
    private:
        //no new attributes
    public:
        //seller constructor
        Seller(string name, string licence_number, double wallet, int vehicle_amount) : Customer(name, licence_number, wallet, vehicle_amount) {}

        Vehicle initialise_vehicle() {
            for (int i = 0; i < vehicle_amount; i++) {
                cout << "what type of vehicle would you like to initialise?" << endl;
                string vehicle_type;
                cin >> vehicle_type;
                swith (vehicle_type) {
                    case "car":
                        cout << "enter the brand: " << endl;
                        string brand;
                        cin >> brand;
                        cout << "enter the model: " << endl;
                        string model;
                        cin >> model;
                        cout << "enter the licence plate: " << endl;
                        string licence_plate;
                        
                        break;
                    case "truck":
                        //if truck
                        break;
                    case "van":
                        //if van
                        break;
                    default:
                        cout << "entered wrong vehicle type, function aborted" << endl;
                        cout << "the vehicle type must either be 'car', 'truck, or 'van'" << endl;
                }
            }
        }

        void vehicle_transaction() { //also add a cost conditional
            //remove a vehicle from the vector and add it to the dealership
        }

        ~Seller() {
            for (int i = 0; i < vehicle_amount; i++) {
                delete[] vehicles[i];
            }
            delete[] vehicles;
        }
};

#endif