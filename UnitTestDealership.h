#include <iostream>
#include "Vehicle.h"
#include "Van.h"
#include "Dealership.h"
#include <string>
using namespace std;


class UnitTestDealership {
    public:
        void RunTests(){
            testDealership();
        }
    
    private:
        void testDealership() {

            Dealership dealership("Auto shop", 3, 50000, 300, 200);
            Vehicle* car1 = new Car(250, 150, 1200, 10000, "Ford", "Mondeo", "GR389B");
            Vehicle* truck1 = new Truck(300, 200, 2000, 25000, "Volvo", "VNL 860", "UNR389", 1000, 500);
            Vehicle* van1 = new Van(270, 175, 1400, 15000, "Mercedes-Benz", "Sprinter", "KLE38X2", 0, 400, 7);

            //Testing the add vehicle function on a car
            if (dealership.add_vehicle(car1)) {
                dealership.display_cars();
                cout << "function ran successfully" << endl;
            } else {
                cout << "function did not run successfully" << endl;
            }

            //Testing the add vehicle function on a truck
            if (dealership.add_vehicle(truck1)) {
                dealership.display_trucks();
                cout << "function ran successfully" << endl;
            } else {
                cout << "function did not run successfully" << endl;
            }
            
            //Testing the add vehicle function on a van
            if (dealership.add_vehicle(van1)) {
                dealership.display_vans();
                cout << "function ran successfully" << endl;
            } else {
                cout << "function did not run successfully" << endl;
            }

            //save and print a log of the vehicles in the dealership
            dealership.write("dealership_log.txt");
            dealership.read("dealership_log.txt");
            
        }
};