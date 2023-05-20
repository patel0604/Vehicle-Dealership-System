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

            //search for a vehicle by brand and model and display its position
            dealership.search_vehicle_brand("Ford", "Mondeo");

            //search for a vehicle by number plate and return its array index
            int position = dealership.search_vehicle_number_plate("KLE38X2");
            cout << "Mercedes-Benz Sprinter is stored in array index: " << position << endl;

            //save and print a log of the vehicles in the dealership
            dealership.write("dealership_log.txt");
            dealership.read("dealership_log.txt");

            //removing vehicles
            Vehicle** vehicles = new Vehicle*[3];
            for (int i = 0; i < 3; i++) {
                vehicles[i] = nullptr;
            }
            vehicles[0] = dealership.remove_vehicle("KLE38X2");
            cout << vehicles[0]->get_vehicle_type() << ", " << vehicles[0]->get_van_type() << ", " << vehicles[0]->get_load_volume() << ", " << vehicles[0]->get_passenger_limit() << endl;
            vehicles[2] = dealership.remove_vehicle("GR389B");
            cout << vehicles[2]->get_model() << ", " << vehicles[2]->get_number_plate() << endl;
            vehicles[1] = dealership.remove_vehicle("UNR389");
            cout << vehicles[1]->get_load_volume() << ", " << vehicles[1]->get_load_capacity() << endl;
            

            for (int i = 0; i < 3; i++) {
                delete vehicles[i];
            }
            delete[] vehicles;
        }
};