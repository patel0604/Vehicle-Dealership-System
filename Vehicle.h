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
        Vehicle(){
            length = 0;
            width = 0;
            weight = 0;
            cost = 0;
        }
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

        //virtual functions
        //car
        virtual string get_brand() {return "N/A";}
        virtual string get_model() {return "N/A";}
        virtual string get_number_plate() {return "N/A";}
        virtual void set_number_plate(string number_plate) {}

        //truck
        virtual int get_load_volume() {return 0;}
        virtual int get_load_capacity() {return 0;}

        //van
        virtual string get_van_type() {return "";}
        virtual int get_passenger_limit() {return 0;}

        virtual ~Vehicle() {}
};

#endif