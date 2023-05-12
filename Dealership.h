#ifndef DEALERSHIP_H
#define DEALERSHIP_H
#include <string>
#include <iostream>
using namespace std;

class Dealership {
    private:
        const int capacity;
        int num_vehicles;
        string dealership_name;
        double funds;
        int parking_length;
        int parking_width;
        // pointer to a pointer of a vector of vehicles
    public:
        //constructor for dealership
        Dealership(string dealership_name, int capacity, double funds, int parking_length, int parking_width){
            this->dealership_name = dealership_name;
            this->capacity = capacity;
            this->funds = funds;
            this->parking_length = parking_length;
            this->parking_width = parking_width;
            num_vehicles = 0;
            // initialise the pointer to pointer
        }

        //all get functions
        int get_capacity() {return capacity;}
        int get_num_vehicles() {return num_vehicles;}
        string get_dealership_name() {return dealership_name;}
        double get_funds() {return funds;}
        int get_parking_length() {return parking_length;}
        int get_parking_width() {return parking_width;}

        //all set functions
        string set_dealership_name(dealership_name) {this->dealership_name = dealership_name;}

        //other functions
        //add/subtract funds
        void change_funds(double funds_added) {funds += funds_added;}
        //add vehicle
        void add_vehicle(Vehicle vehicle) {}
        //remove vehicle
        void remove_vehicle(Vehicle vehicle) {}
        //search vehicle
        void search_vehicle(string make, string model) {}
        //display cars
        void display_cars() {}
        //display trucks
        void display_trucks() {}
        //display vans
        void display_vans() {}
};

#endif