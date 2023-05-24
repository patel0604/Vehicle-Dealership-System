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
        Vehicle();

        //constructor
        Vehicle(int length, int width, double weight, double cost);
        
        //getters
        string get_vehicle_type();

        double get_cost();

        double get_weight();

        int get_length();

        int get_width();

        //setters
        void set_cost(double cost);

        
        //virtual functions
        //car
        virtual string get_brand();
        virtual string get_model();
        virtual string get_number_plate();
        virtual void set_number_plate(string number_plate);
        virtual void set_brand(string brand);
        virtual void set_model(string model);


        //truck
        virtual int get_load_volume();
        virtual int get_load_capacity();
        virtual void set_load_volume(int load_volume);
        virtual void set_load_capacity(int load_capacity);

        //van
        virtual string get_van_type();
        virtual int get_passenger_limit();
        virtual void set_van_type(string van_type);
        virtual void set_passenger_limit(int passenger_limit);

        //destructor
        virtual ~Vehicle();
};

#endif