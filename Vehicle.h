#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    protected:
        // attributes
        string vehicle_type;
        int length;
        int width;
        double weight;
        double cost;
    public:
        //default constructor
        Vehicle(){
            vehicle_type = "N/A";
            length = 0;
            width = 0;
            weight = 0;
            cost = 0;
        }
        //constructor
        Vehicle(int length, int width, double weight, double cost) {
            if (length > 0 && width > 0 && weight> 0 && cost >= 0){
                this->length = length;
                this->width = width;
                this->weight = weight;
                this->cost = cost;
                vehicle_type = "N/A";
            }
            else{
                cout << "invalid inputs values for constructor" << endl;
            }
        }
        
        //getters
        string get_vehicle_type(){return vehicle_type;}

        double get_cost(){return cost;}

        double get_weight(){return weight;}

        int get_length(){return length;}

        int get_width(){return width;}

        //setters
        void set_cost(double cost){
            this->cost = cost;
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
        virtual string get_van_type() {return "N/A";}
        virtual int get_passenger_limit() {return 0;}

        //destructor
        virtual ~Vehicle() {}
};

#endif