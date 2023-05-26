#include <iostream>
#include "Vehicle.h"
#include "Van.h"
#include "Car.h"
#include "Truck.h"
#include <string>
using namespace std;


class UnitTest {
    public:
        void RunTests(){
            testVehicle();
        }
    
    private:
        void testVehicle(){

            //initialise a car
            Car car1(30,150,1500, 15000,"tt","camry","KS390");
            Vehicle* vehicle2 = &car1;

            //initialise a car
            Car car2 (30,150,1500, -15000,"tt","camry","KS390");
            Vehicle* vehicle4 = &car2;

            //initialise a van
            Van van1(250,150,1500,15000,"toyota","tvan","SW390",1000,500,7);
            Vehicle* vehicle1 = &van1;

            //initialise a truck
            Truck truck1(550,350,2500,25000,"toyota","tvan","SW390", 23450, 12345);
            Vehicle* vehicle3 = &truck1;

            //testing negative input. should return a error message.
            Truck truck2(550,350,2500,25000,"toyota","tvan","SW390", -23450, 12345);
            Vehicle* vehicle4 = &truck2;

            //initialise a truck
            Truck truck3; /*testing def. contructor*/
            Vehicle* vehicle5 = &truck3;

            //Testing the get cost function
            if (vehicle2-> get_cost() != 15000){
                cout<<"test failed"<< endl;
            }

            else {
                cout<< "Test passed"<< endl;
            }

            //testing negative inputs
            if (vehicle4 -> get_cost() < 0) {
                cout<< "invalid inputs values for constructor" << endl;
            }

            //Testing get model function
            if (vehicle1 -> get_model() != "tvan"){
                cout<<"test passed"<<endl;
            }
            else{
                cout<<"test failed"<<endl;
            }

            //testing the get brand function
            if (vehicle1 -> get_brand() != "tt"){
                cout<<"test failed";
            }

            else{
                cout<<"test passed";
            }

            //testing van type function through load volume
            if (vehicle1 -> get_van_type() != "transport"){
                cout<<"test failed"<<endl;
            }
            else{
                cout<<"test failed"<<endl;
            }

            //testing load volume getter
            if (vehicle3 -> get_load_volume() != 23450){
                cout<<"test failed"<<endl;
            }
            else{
                cout<<"test passed"<<endl;
            }
        }
};