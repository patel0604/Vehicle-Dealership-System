#ifndef MAKEVEHICLE_H
#define MAKEVEHICLE_H
#include <iostream>
#include <string>
#include "Van.h"
using namespace std;

class MakeVehicle {
    public:
        Vehicle* initialise_vehicle(string vehicle_type);

};



#endif