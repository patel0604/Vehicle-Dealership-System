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
        Car():Vehicle(){
            vehicle_type = "car";
            brand = "N/A";
            model = "N/A";
            number_plate = "N/A";
        }
        //constructor
        Car(int length, int width, double weight, double cost, string brand, string model, string number_plate) : Vehicle(length, width, weight, cost) {
            vehicle_type = "car";
            this->brand = brand;
            this->model = model;
            this->number_plate = number_plate;
        }

        //getters
        string get_brand() {return brand;}
        string get_model() {return model;}
        string get_number_plate() {return number_plate;}
        
        //setters
        void set_number_plate(string number_plate) {
            this->number_plate = number_plate;
        }
        virtual void set_brand(string brand) {
            this->brand = brand;
        }
        virtual void set_model(string model) {
            this->model = model;
        }

        //destructor
        ~Car() {}
};

#endif