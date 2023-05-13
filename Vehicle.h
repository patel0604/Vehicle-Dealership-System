#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    protected:
        // attributes
        int length;
        int width;
        double weight;
        double cost;
    public:
        //constructor
        Vehicle(int length, int width, double weight, double cost) {
            this->length = length;
            this->width = width;
            this->weight = weight;
            this->cost = cost;
        }
        //methods
        //getters and setters
        double get_cost(){
            return cost;
        }

        void set_cost(double cost){
            this->cost = cost;
        }

        double get_weight(){
            return weight;
        }

        int get_length(){
            return length;
        }

        int get_width(){
            return width;
        }

        ~Vehicle() {}
};

#endif