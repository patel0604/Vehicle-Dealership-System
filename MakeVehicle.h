#ifndef MAKEVEHICLE_H
#define MAKEVEHICLE_H
#include <iostream>
#include <string>
#include "Van.h"
using namespace std;

// this class has a specific function which asks the user to initialise a single vehicle
// this function is called inside other header functions
class MakeVehicle {
    public:
        Vehicle* initialise_vehicle(string vehicle_type);

        // destructor
        ~MakeVehicle() {}
};

#endif