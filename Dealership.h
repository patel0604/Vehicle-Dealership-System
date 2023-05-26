#ifndef DEALERSHIP_H
#define DEALERSHIP_H
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include "Vehicle.h"
#include "Car.h"
#include "Van.h"
#include "Truck.h"
using namespace std;

// this class represents the dealership which contains an array of vehicles
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
        Dealership(string dealership_name, int capacity, double funds, int parking_length, int parking_width);

        //getters
        int get_capacity();
        int get_num_vehicles();
        string get_dealership_name();
        double get_funds();
        int get_parking_length();
        int get_parking_width();

        //setters
        void set_dealership_name(string dealership_name);

        //other functions:
        //add/subtract funds
        void change_funds(double funds_added);

        //add vehicle
        //pass the address to the vehicle being added as input
        bool add_vehicle(Vehicle* vehicle);

        //(new function for adding vehicles by reading a file)

        //remove vehicle
        //passes the number plate of the car being removed as an input
        //return a pointer to the removed vehicle
        //if the function doesn't remove a vehicle return nullptr
        Vehicle* remove_vehicle(string number_plate);



        //search vehicle of specific brand and model and display their position in the dealership
        void search_vehicle_brand(string brand, string model);


        //search vehicle of specific number plate and return their position in the dealership
        int search_vehicle_number_plate(string number_plate);

        //pass the position of the vehicle and return its cost
        double get_vehicle_cost(int vehicle_position);


        //display cars
        void display_cars();

        //display trucks
        void display_trucks();

        //display vans
        void display_vans();

        //function for writing a log of the dealership vehicles into a file
        void write(string file_name);

        //read the file and print each line to the terminal
        void read(string file_name);

        //constructor
        ~Dealership();
};

#endif