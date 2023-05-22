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
            Buyer buyer1("John Doe", "JREO92", 55000, 3);
            Seller seller1("Judas White", "RTN9E20", 10000, 4);

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
            cout << "buyer wallet is: " << buyer1.get_wallet() << endl;
            cout << "dealership funds are: " << dealership.get_funds() << endl;

            //initialise seller vehicles
            seller1.initialise_vehicles();

            //display seller vehicles
            seller1.display_vehicles();

            //buy all 3 vehicles from the seller
            for (int i = 0; i < 4; i++) {
                cout << "enter the number plate of the vehicle you want to buy from the seller:" << endl;
                string number_plate;
                cin >> number_plate;
                if (seller1.vehicle_transaction(number_plate, &dealership)) {
                    cout << "the function ran successfully" << endl;
                } else {
                    cout << "the function did not run successfully" << endl;
                }
            }

            //display vehicles in dealership
            dealership.display_cars();
            dealership.display_trucks();
            dealership.display_vans();

            //display dealership and seller funds
            cout << "dealership funds are: " << dealership.get_funds() << endl;
            cout << "seller wallet is: " << seller1.get_wallet() << endl;

            //display seller vehicles
            seller1.display_vehicles();
        }
};

#endif