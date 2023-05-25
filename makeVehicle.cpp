#include <iostream>
#include <string>
#include "MakeVehicle.h"
#include "Van.h"
using namespace std;


Vehicle* MakeVehicle::initialise_vehicle(string vehicle_type) {  
    //ask basic values
    cout << "enter the brand: " << endl;
    string brand;
    getline(cin, brand);
    cout << "enter the model: " << endl;
    string model;
    getline(cin, model);
    cout << "enter the number plate: " << endl;
    string number_plate;
    getline(cin, number_plate);
    cout << "enter the length in cm: " << endl;
    int length;
    cin >> length;
    cout << "enter the width in cm: " << endl;
    int width;
    cin >> width;
    cout << "enter the weight in kg: " << endl;
    double weight;
    cin >> weight;
    cout << "enter the cost in $: " << endl;
    double cost;
    cin >> cost;

    if (vehicle_type == "car") {
        cout << "vehicle type is car - debug message" << endl;
        //initialise a new car with the given values
        Car* car = new Car(length, width, weight, cost, brand, model, number_plate);
        cout << "new car initialised - debug message" << endl;
        //return the address
        return car;
    } else if (vehicle_type == "truck") {
        cout << "vehicle type is truck - debug message" << endl;
        cout << "enter the load volume in L: " << endl;
        int load_volume;
        cin >> load_volume;
        cout << "enter the load capacity in kg: " << endl;
        int load_capacity;
        cin >> load_capacity;
        //initialise a new truck with the given values
        Truck* truck = new Truck(length, width, weight, cost, brand, model, number_plate, load_volume, load_capacity);
        //return the address
        return truck;
    } else if (vehicle_type == "van") {
        cout << "vehicle type is van - debug message" << endl;
        while (true) {
            string van_type;
            cout << "enter 'passenger' or 'transport' for the van type you want to initialise: " << endl;
            cin >> van_type;
            cin.ignore();
            if (van_type == "passenger") {
                int load_volume = 0;
                cout << "enter the load capacity of passengers in kg: " << endl;
                int load_capacity;
                cin >> load_capacity;
                cout << "enter the number of passenger limit: " << endl;
                int passenger_limit;
                cin >> passenger_limit;
                //initialise a new van with the given values
                Van* van = new Van(length, width, weight, cost, brand, model, number_plate, load_volume, load_capacity, passenger_limit);
                //return the address
                return van;
            } else if (van_type == "transport") {
                cout << "enter the load volume in L: " << endl;
                int load_volume;
                cin >> load_volume;
                cout << "enter the load capacity of cargo in kg: " << endl;
                int load_capacity;
                cin >> load_capacity;
                int passenger_limit = 0;
                //initialise a new van with the given values
                Van* van = new Van(length, width, weight, cost, brand, model, number_plate, load_volume, load_capacity, passenger_limit);
                //return the address
                return van;
            } else {
                cout << "wrong van type entered, please try again" << endl;
            }
        }
    }
return nullptr;
}