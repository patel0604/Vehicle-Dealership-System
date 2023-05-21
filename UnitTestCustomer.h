#ifndef UNITTESTCUSTOMER_H
#define UNITTESTCUSTOMER_H
#include <iostream>
#include "Vehicle.h"
#include "Van.h"
#include "Dealership.h"
#include "Buyer.h"
#include "Seller.h"
#include <string>
#include <iostream>
using namespace std;

class UnitTestCustomer {
    public:
        void RunTests(){
            testDealership();
        }
    
    private:
        void testDealership() {
            //initialise objects
            Dealership dealership("Auto shop", 3, 50000, 300, 200);
            Vehicle* car1 = new Car(250, 150, 1200, 10000, "Ford", "Mondeo", "GR389B");
            Vehicle* truck1 = new Truck(300, 200, 2000, 25000, "Volvo", "VNL 860", "UNR389", 1000, 500);
            Vehicle* van1 = new Van(270, 175, 1400, 15000, "Mercedes-Benz", "Sprinter", "KLE38X2", 0, 400, 7);
            Buyer buyer1("John Doe", "JREO92", 40500, 3);

            //initialising all vehicles
            dealership.add_vehicle(car1);
            dealership.add_vehicle(truck1);
            dealership.add_vehicle(van1);

            //test buyer vehicle transaction
            //sell the truck
            if (buyer1.vehicle_transaction("UNR389", &dealership)) {
                cout << "the function ran successfully" << endl;
            } else {
                cout << "the function did not run successfully" << endl;
            }

            //sell the van
            if (buyer1.vehicle_transaction("KLE38X2", &dealership)) {
                cout << "the function ran successfully" << endl;
            } else {
                cout << "the function did not run successfully" << endl;
            }

            //sell the car
            if (buyer1.vehicle_transaction("GR389B", &dealership)) {
                cout << "the function ran successfully" << endl;
            } else {
                cout << "the function did not run successfully" << endl;
            }

            //show the list of vehicles
            buyer1.display_vehicles();

        }
};

#endif