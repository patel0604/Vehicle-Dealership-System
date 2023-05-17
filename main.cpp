#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Van.h"
#include "Car.h"
#include "Truck.h"
using namespace std;

int main() {

    /* Van testing*/
    Van van1(250,150,1500,15000,"toyota","tvan","SW390",1000,500,7);
    Vehicle* vehicle1 = &van1;
    cout << vehicle1->get_model() << endl;

    Car car1(-30,150,1500, -15000,"toyota","camry","KS390");
    Vehicle* vehicle2 = &car1;
    cout << vehicle2->get_cost() << endl;
    
    /*Truck testing*/
    Truck truck1; /*testing def. contructor*/
    Vehicle* vehicle3 = &truck1;
    cout << vehicle3 -> get_length() << endl;
    cout << vehicle3 -> get_load_capacity() << endl;

    Truck truck2(700, 300, 5000, 80000, "Scania", "L-Series", "S123ABC", 30000, 12345); /*testing std. contructor*/
    Vehicle* vehicle4 = &truck2;
    cout << vehicle4 -> get_brand() << endl;

    /*Vehicle testing*/
    Vehicle vehicle_a; /*tesing def. constructor*/
    cout << vehicle_a.get_brand() << endl;

    //Vehicle vehicle_b(1,2,3,4,5); /*testing for incorrect amount of arguments for the contructor*/



    return 0;
}