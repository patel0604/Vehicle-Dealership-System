#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"
using namespace std;

class Car : public Vehicle {
    protected:
        string brand;
        string model;
        string number_plate;
    public:
        Car():Vehicle(){
            brand = "N/A";
            model = "N/A";
            number_plate = "N/A";
        }
        Car(int length, int width, double weight, double cost, string brand, string model, string number_plate) : Vehicle(length, width, weight, cost) {
            this->brand = brand;
            this->model = model;
            this->number_plate = number_plate;
        }

        string get_brand() {return brand;}
        string get_model() {return model;}
        string get_number_plate() {return number_plate;}
        
        void set_number_plate(string number_plate) {
            this->number_plate = number_plate;
        }

        ~Car() {}
};

#endif