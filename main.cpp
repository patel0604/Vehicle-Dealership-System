#include <iostream>
#include <string>
#include <limits>
#include "Vehicle.h"
#include "Van.h"
#include "Car.h"
#include "Truck.h"
using namespace std;

int main() {

    // Now writing code for main menu (user interface)
    int user_selection1;

    cout << "Welcome to the dealership!" << endl;
    cout << "1. Adding (buying) a car to the dealership." << endl;
    cout << "Enter the number corresponding to which action you want to do." << endl;
    cin >> user_selection1;
    /*
    switch (user_selection1)
    {
        case 1:
            cout << "You selected 1. \n
            Adding a car to the dealership" << endl;
            break;

        default:
            cout << "Please select a number shown above" << endl;
            break;
    }

    */

    if (user_selection1 == 1){
        // run code for adding a car to the dealership
    }

    while (user_selection1 != int){
    // if user enters a number not shown 
        cout << "Please enter a number shown." << endl;
        cin >> user_selection1;

    }
    

    /*

    // Van testing
    Van van1(250,150,1500,15000,"toyota","tvan","SW390",1000,500,7);
    Vehicle* vehicle1 = &van1;
    cout << vehicle1->get_model() << endl;

    Car car1(30,150,1500, -15000,"","camry","KS390");
    Vehicle* vehicle2 = &car1;
    cout << vehicle2->get_cost() << endl;
    
    //Truck testing
    Truck truck1; //testing def. contructor
    Vehicle* vehicle3 = &truck1;
    cout << vehicle3 -> get_length() << endl;
    cout << vehicle3 -> get_load_capacity() << endl;

    Truck truck2(700, 300, 5000, 80000, " ", "L-Series", "S123ABC", 30000, 12345); //testing std. contructor
    Vehicle* vehicle4 = &truck2;
    cout << vehicle4 -> get_brand() << endl;

    //Vehicle testing
    Vehicle vehicle_a; //tesing def. constructor
    cout << vehicle_a.get_brand() << endl;

    Vehicle vehicle_b(1,2,3,4); //testing for incorrect amount of arguments for the contructor

    */





    

    return 0;
}