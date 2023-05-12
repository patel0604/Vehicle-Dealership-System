#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>

class Vehicle{
    private:
        // attributes
        int length;
        int width;
        double weight;
        double cost;
    public:
        //methods
        //getters and setters
        double get_cost(){
            return cost;
        }

        set_cost(double cost){
            this->cost = cost;
        }

        double get_weight(){
            return weight;
        }

        /*Splitting length and width
        into two separate get functions*/

        int get_length(){
            return length;
        }

        int get_width(){
            return width;
        }

        /*splitting length and width into
        two separate set functions*/

        set_length(int length){
            this->length = length;
        }

        set_width(int length){
            this->length = length;
        }
};

#endif