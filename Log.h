#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <string>
#include <fstream>
#include "Dealership.h"
#include "Van.h"
using namespace std;

//reads a file and initialises vehicle objects
class Log {
    public:
        //initialises a vehicle from a file into a given pointer
        void write(string file_name, Dealership dealership);

        void read(string file_name);
};

#endif
<<<<<<< HEAD

                            /*if (vehicle->get_vehicle_type() == "car") {
                                dealership[i] = new Car;
                            } else if (vehicle->get_vehicle_type() == "truck") {
                                dealership[i] = new Truck;
                            } else if (vehicle->get_vehicle_type() == "Van") {
                                dealership[i] = new Van;
                            } else {
                                cout << "invalid vehicle type" << endl;
                                return false;
                            }*/
=======
>>>>>>> 9e933e4ae3391554cc25cb5894febfd9256ca36c
