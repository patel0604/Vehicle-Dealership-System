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

        //function for initialising the vehicles in the array to be sold
        void initialise_vehicles() {
            //if there is enough space in the array the for loop commences
            for (vehicles_index; vehicles_index < vehicle_amount; vehicles_index++) {
                cout << "enter 'car', 'truck' or 'van' for the type of vehicle you want to initialise" << endl;
                string vehicle_type;
                cin >> vehicle_type;
                //ask basic values
                cout << "enter the brand: " << endl;
                string brand;
                cin >> brand;
                cout << "enter the model: " << endl;
                string model;
                cin >> model;
                cout << "enter the number plate: " << endl;
                string number_plate;
                cin >> number_plate;
                cout << "enter the length in cm: " << endl;
                int length;
                cin >> length;
                cout << "enter the width in cm: " << endl;
                int width;
                cin >> width;
                cout << "enter the weight in kg: " << endl;
                double weight;
                cin >> weight;
                cout << "enter the cost in $: " << endl;
                double cost;
                cin >> cost;

                if (vehicle_type == "car") {
                    //initialise a new car with the given values
                    Car car(length, width, weight, cost, brand, model, number_plate);
                    //copy the contents of the object to a vehicle in the seller array
                    *vehicles[vehicles_index] = car;
                    //when the if statement ends, the object will delete itself
                } else if (vehicle_type == "truck") {
                    cout << "enter the load volume in L: " << endl;
                    int load_volume;
                    cin >> load_volume;
                    cout << "enter the load capacity in kg: " << endl;
                    int load_capacity;
                    cin >> load_capacity;
                    //initialise a new truck with the given values
                    Truck truck(length, width, weight, cost, brand, model, number_plate, load_volume, load_capacity);
                    //copy the contents of the object to a vehicle in the seller array
                    *vehicles[vehicles_index] = truck;
                } else if (vehicle_type == "van") {
                    string van_type;
                    cout << "enter 'passenger' or 'transport' for the van type you want to initialise: " << endl;
                    cin >> van_type;
                    if (van_type == "passenger") {
                        int load_volume = 0;
                        cout << "enter the load capacity of passengers in kg: " << endl;
                        int load_capacity;
                        cin >> load_capacity;
                        cout << "enter the number of passenger limit: " << endl;
                        int passenger_limit;
                        cin >> passenger_limit;
                        //initialise a new van with the given values
                        Van van(length, width, weight, cost, brand, model, number_plate, load_volume, load_capacity, passenger_limit);
                        //copy the contents of the object to a vehicle in the seller array
                        *vehicles[vehicles_index] = van;
                    } else if (van_type == "transport") {
                        cout << "enter the load volume in L: " << endl;
                        int load_volume;
                        cin >> load_volume;
                        cout << "enter the load capacity of cargo in kg: " << endl;
                        int load_capacity;
                        cin >> load_capacity;
                        int passenger_limit = 0;
                        //initialise a new van with the given values
                        Van van(length, width, weight, cost, brand, model, number_plate, load_volume, load_capacity, passenger_limit);
                        //copy the contents of the object to a vehicle in the seller array
                        *vehicles[vehicles_index] = van;
                    } else {
                        cout << "wrong van type entered" << endl;
                    }
                } else {
                    cout << "entered wrong vehicle type entered" << endl;
                }  
            }
        }

        //remove a vehicle from the vector and add it to the dealership
        void vehicle_transaction(Vehicle* vehicle) { //also add a cost conditional
            //check if there are any vehicles in the array
            if (vehicles_index > 0) {
                cout << "there are seller vehicles to be sold" << endl;
                
            }
        }

        ~Seller() {
            for (int i = 0; i < vehicle_amount; i++) {
                delete[] vehicles[i];
            }
            delete[] vehicles;
        }
};

#endif