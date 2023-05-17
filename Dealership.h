#ifndef DEALERSHIP_H
#define DEALERSHIP_H
#include <string>
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Dealership {
    private:
        int capacity;
        int num_vehicles;
        string dealership_name;
        double funds;
        int parking_length;
        int parking_width;
        //making a pointer to a pointer of class vehicle
        Vehicle** dealership;
    public:
        //constructor for dealership
        Dealership(string dealership_name, int capacity, double funds, int parking_length, int parking_width){
            this->dealership_name = dealership_name;
            this->capacity = capacity;
            this->funds = funds;
            this->parking_length = parking_length;
            this->parking_width = parking_width;
            num_vehicles = 0;
            //making an array of size capacity for all vehicles in the dealership
            dealership = new Vehicle*[capacity];
            //initialising an empty array of vehicles
            //the index of the array represents the parking spaces in the dealership
            for (int i = 0; i < capacity; i++) {
                dealership[i] = nullptr;
            }
        }

        //getters
        int get_capacity() {return capacity;}
        int get_num_vehicles() {return num_vehicles;}
        string get_dealership_name() {return dealership_name;}
        double get_funds() {return funds;}
        int get_parking_length() {return parking_length;}
        int get_parking_width() {return parking_width;}

        //setters
        string set_dealership_name(string dealership_name) {
            this->dealership_name = dealership_name;
        }

        //other functions:
        //add/subtract funds
        void change_funds(double funds_added) {funds += funds_added;}

        //add vehicle
        //pass the address to the vehicle being added as input
        bool add_vehicle(Vehicle* vehicle) {
            //if there is space in the dealership and the vehicle meets the spatial limitations
            if (num_vehicles < capacity) {
                cout << "there is space is the dealership - debug message" << endl;
                if (vehicle->get_length() <= parking_length && vehicle->get_width() <= parking_width) {
                    cout << "the vehicle meets the spatial limitatios of the dealership - debug message" << endl;
                    //search through the dealership
                    for (int i = 0; i < capacity; i++) {
                        //when free space (empty pointer) is found
                        if (dealership[i] == nullptr) {
                            //add the contents of the passed vehicle to the vehicle in the dealership
                            *dealership[i] = *vehicle;
                            //free the pointer of the passed vehicle
                            delete vehicle;
                            cout << "passed vehicle pointer deleted - debug message" << endl;
                            //increase the number of vehicles in dealership
                            num_vehicles++;
                            cout << "Vehicle added to the dealership " << "at parking space: " << i+1 << endl;
                            return true;
                        }
                    }
                    cout << "error: vehicle not added to the dealership despite there being space" << endl;
                } else {
                    cout << "vehicle does not meet the spatial limitations" << endl;
                }
            } else {
                cout << "dealership is full" << endl;
            }
            cout << "function failed aborting - debug message" << endl;
            return false;
        }

        //(new function for adding vehicles by reading a file)

        //remove vehicle
        //passes the number plate of the car being removed as an input
        //return a pointer to the removed vehicle
        //if the function doesn't remove a vehicle return nullptr
        Vehicle* remove_vehicle(string number_plate) {
            //if there is at least one vehicle in dealership
            if (num_vehicles > 0) {
                cout << "there is at least 1 vehicle in the dealership - debug message" << endl;
                //search through the dealership
                for (int i = 0; i > capacity; i++) {
                    //if the number plate of the vehicle matches the number plate passed in the function
                    if (dealership[i]->get_number_plate() == number_plate) {
                        //create a copy object vehicle (with default constructor)
                        Vehicle* copy = nullptr;
                        //copy the contents of the vehicle to the copy object
                        *copy = *dealership[i];
                        //make the vehicle pointer in the dealership the nullptr
                        dealership[i] = nullptr;
                        cout << "vehicle " << i+1 << " removed from the dealership" << endl;
                        //number of vehicles in the dealership decreases by 1;
                        num_vehicles--;
                        //return the pointer of the copied vehicle
                        return copy;
                    }
                }
                //if the vehicle with the number plate cannot be found
                cout << "The vehicle with this number plate was not found in the dealership" << endl;
                return nullptr;
            }
            //if there are no vehicle in the dealership
            cout << "there are no vehicles in the dealership" << endl;
            return nullptr;
        }

        //search vehicle of specific brand and model and display their position in the dealership
        void search_vehicle_brand(string brand, string model) {
            for (int i = 0; i < capacity; i++) {
                if (dealership[i]->get_brand() == brand && dealership[i]->get_model() == model) {
                    cout << brand << " " << model << " at parking space: " << i+1 << endl;
                }
            }
        }

        //search vehicle of specific number plate and return their position in the dealership
        int search_vehicle_number_plate(string number_plate) {
            for (int i = 0; i < capacity; i++) {
                if (dealership[i]->get_number_plate() == number_plate) {
                    //return the index of the vehicle in the dealership array
                    return i;
                }
            }
            cout << "error vehicle number plate not found" << endl;
            return -1;
        }

        //pass the position of the vehicle and return its cost
        double get_vehicle_cost(int vehicle_position) {
            //retrieve the cost of the vehicle
            double vehicle_cost = dealership[vehicle_position]->get_cost();
            //return the cost
            return vehicle_cost;
        }

        //(new function for printing out the full list of all vehicles onto a file and open it on screen)
        //(all other display functions can be coded the same way)

        //display cars
        void display_cars() {
            for (int i = 0; i < capacity; i++) {
                //display all attributes for each car on one line
                if (dealership[i]->get_vehicle_type() == "car") {
                    cout << dealership[i]->get_brand() << " " << dealership[i]->get_model() << ", licence plate: " << dealership[i]->get_number_plate();
                    cout << ", dimensions: " << dealership[i]->get_length() << " x " << dealership[i]->get_width() << "cm, weight: " << dealership[i]->get_weight();
                    cout << "kg, cost: $" << dealership[i]->get_cost() << endl;
                }
            }
        }

        //display trucks
        void display_trucks() {
            for (int i = 0; i < capacity; i++) {
                //display all attributes for each truck on one line
                if (dealership[i]->get_vehicle_type() == "truck") {
                    cout << dealership[i]->get_brand() << " " << dealership[i]->get_model() << ", number plate: " << dealership[i]->get_number_plate();
                    cout << ", dimensions: " << dealership[i]->get_length() << " x " << dealership[i]->get_width() << "cm , weight: " << dealership[i]->get_weight();
                    cout << "kg, cost: $" << dealership[i]->get_cost() << ", load volume: " << dealership[i]->get_load_volume();
                    cout << "litres, load capacity: " << dealership[i]->get_load_capacity() << "kg" << endl;
                }
            }
        }

        //display vans
        void display_vans() {
            for (int i = 0; i < capacity; i++) {
                //display all attributes for each van on one line
                if (dealership[i]->get_vehicle_type() == "van") {
                    if (dealership[i]->get_van_type() == "passenger") {
                        //if the van is of type passenger
                        cout << dealership[i]->get_brand() << " " << dealership[i]->get_model() << ", number plate: " << dealership[i]->get_number_plate();
                        cout << ", van type: passenger, dimensions: " << dealership[i]->get_length() << " x " << dealership[i]->get_width() << "cm , weight: " << dealership[i]->get_weight();
                        cout << "kg, cost: $" << dealership[i]->get_cost() << ", load capacity: " << dealership[i]->get_load_capacity();
                        cout << "kg, passenger limit: " << dealership[i]->get_passenger_limit() << endl;
                    } else if (dealership[i]->get_van_type() == "transport") {
                        //if the van is of type transport
                        cout << dealership[i]->get_brand() << " " << dealership[i]->get_model() << ", number plate: " << dealership[i]->get_number_plate();
                        cout << ", van type: transport, dimensions: " << dealership[i]->get_length() << " x " << dealership[i]->get_width() << "cm , weight: " << dealership[i]->get_weight();
                        cout << "kg, cost: $" << dealership[i]->get_cost() << ", load volume: " << dealership[i]->get_load_volume();
                        cout << "litres, load capacity: " << dealership[i]->get_load_capacity() << "kg" << endl;
                    } else {
                        cout << "error: neither type passenger or transport - debug message" << endl;
                    }
                }
            }
        }

        ~Dealership() {
            for (int i = 0; i > capacity; i++) {
                delete[] dealership[i];
            }
            delete[] dealership;
        }
};

#endif