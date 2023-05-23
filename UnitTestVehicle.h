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

            Car car1(30,150,1500, 15000,"tt","camry","KS390");
            Vehicle* vehicle2 = &car1;

            Car car2 (30,150,1500, -15000,"tt","camry","KS390");
            Vehicle* vehicle4 = &car2;

            Van van1(250,150,1500,15000,"toyota","tvan","SW390",1000,500,7);
            Vehicle* vehicle1 = &van1;

            Truck truck1; /*testing def. contructor*/
            Vehicle* vehicle3 = &truck1;

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

            if (vehicle1 -> get_brand() != "tt"){
                cout<<"test failed";
            }

            else{
                cout<<"test passed";
            }




        }
};