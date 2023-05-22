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
                bool loop = true;
                while (loop) {
                    cout << "enter 'car', 'truck' or 'van' for the type of vehicle you want to initialise" << endl;
                    string vehicle_type;
                    getline(cin, vehicle_type);
                    if (vehicle_type == "car" || vehicle_type == "truck" || vehicle_type == "van") {
                        //ask basic values
                        cout << "enter the brand: " << endl;
                        string brand;
                        getline(cin, brand);
                        cout << "enter the model: " << endl;
                        string model;
                        getline(cin, model);
                        cout << "enter the number plate: " << endl;
                        string number_plate;
                        getline(cin, number_plate);
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
                            cout << "vehicle type is car - debug message" << endl;
                            //initialise a new car with the given values
                            Car car(length, width, weight, cost, brand, model, number_plate);
                            cout << "new car initialised - debug message" << endl;
                            //change the pointer of the vehicles from nullptr to car
                            vehicles[vehicles_index]  = new Car;
                            //copy the contents of the object to a vehicle in the seller array
                            *vehicles[vehicles_index] = car;
                            vehicles[vehicles_index]->set_brand(car.get_brand());
                            vehicles[vehicles_index]->set_model(car.get_model());
                            vehicles[vehicles_index]->set_number_plate(car.get_number_plate());
                            cout << "car copied seller array - debug message" << endl;
                            //when the if statement ends, the object will delete itself
                            loop = false;
                        } else if (vehicle_type == "truck") {
                            cout << "vehicle type is truck - debug message" << endl;
                            cout << "enter the load volume in L: " << endl;
                            int load_volume;
                            cin >> load_volume;
                            cout << "enter the load capacity in kg: " << endl;
                            int load_capacity;
                            cin >> load_capacity;
                            //change the pointer of the vehicles from nullptr to truck
                            vehicles[vehicles_index]  = new Truck;
                            //initialise a new truck with the given values
                            Truck truck(length, width, weight, cost, brand, model, number_plate, load_volume, load_capacity);
                            //copy the contents of the object to a vehicle in the seller array
                            *vehicles[vehicles_index] = truck;
                            vehicles[vehicles_index]->set_brand(truck.get_brand());
                            vehicles[vehicles_index]->set_model(truck.get_model());
                            vehicles[vehicles_index]->set_number_plate(truck.get_number_plate());
                            vehicles[vehicles_index]->set_load_volume(truck.get_load_volume());
                            vehicles[vehicles_index]->set_load_capacity(truck.get_load_capacity());
                            cout << "truck copied seller array - debug message" << endl;
                            loop = false;
                        } else if (vehicle_type == "van") {
                            cout << "vehicle type is van - debug message" << endl;
                            //change the pointer of the vehicles from nullptr to van
                            vehicles[vehicles_index]  = new Van;
                            string van_type;
                            cout << "enter 'passenger' or 'transport' for the van type you want to initialise: " << endl;
                            getline(cin, van_type);
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
                                vehicles[vehicles_index]->set_brand(van.get_brand());
                                vehicles[vehicles_index]->set_model(van.get_model());
                                vehicles[vehicles_index]->set_number_plate(van.get_number_plate());
                                vehicles[vehicles_index]->set_load_volume(van.get_load_volume());
                                vehicles[vehicles_index]->set_load_capacity(van.get_load_capacity());
                                vehicles[vehicles_index]->set_van_type(van.get_van_type());
                                vehicles[vehicles_index]->set_passenger_limit(van.get_passenger_limit());
                                cout << "van copied seller array - debug message" << endl;
                                loop = false;
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
                                vehicles[vehicles_index]->set_brand(van.get_brand());
                                vehicles[vehicles_index]->set_model(van.get_model());
                                vehicles[vehicles_index]->set_number_plate(van.get_number_plate());
                                vehicles[vehicles_index]->set_load_volume(van.get_load_volume());
                                vehicles[vehicles_index]->set_load_capacity(van.get_load_capacity());
                                vehicles[vehicles_index]->set_van_type(van.get_van_type());
                                vehicles[vehicles_index]->set_passenger_limit(van.get_passenger_limit());
                                cout << "van copied seller array - debug message" << endl;
                                loop = false;
                            } else {
                                cout << "wrong van type entered, please try again" << endl;
                            }
                        }
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