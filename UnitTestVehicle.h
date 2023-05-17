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

            //Testing the get cost function
            if (vehicle2-> get_cost() != 15000){
                cout<<"test failed"<< endl;
            }

            else {
                cout<< "Test passed"<< endl;
            }
        }
};