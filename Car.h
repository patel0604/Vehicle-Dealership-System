#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"
using namespace std;

//derived from vehicle
class Car : public Vehicle {
    protected:
        //attributes
        string brand;
        string model;
        string number_plate;
    public:
        //default constructor
        Car();
        //constructor
        Car(int length, int width, double weight, double cost, string brand, string model, string number_plate);
        //getters
        string get_brand();
        string get_model();
        string get_number_plate();
        
        //setters
        void set_number_plate(string number_plate);
        virtual void set_brand(string brand);
        virtual void set_model(string model);

        //destructor
        ~Car();
};

#endif