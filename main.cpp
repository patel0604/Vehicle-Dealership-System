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
    std::string user_choice1;

    cout << "Welcome to the Dealership!" << endl;
    cout << "1. Adding (buying) a car to the dealership." << endl;
    cout << "2. Removing (selling) a car from the dealership." << endl;

    cout << "0. Close the program." << endl;
    cout << "Enter the number corresponding to which action you want to do." << endl;
    cin >> user_choice1;
    cout << endl; // leave this here for a gap between menu and next section
    
    //stage 1
    //Entering the correct input type
    //user must input a number shown

    // if user enters a number not shown 
    while (user_choice1 != "1"
        && user_choice1 != "2"

        && user_choice1 != "0"){

        cout << "Please enter a number shown in the menu." << endl;
        cin >> user_choice1;
    }

    //stage 2
    //going down the path of the correct function
    //cannot use a switch statement as they are only for int types

    std::string user_choice2;

    if (user_choice1 == "1"){
        cout << "You selected 1. Adding (buying) a car to the dealership." << endl;
        cout << << endl;
    }

    if (user_choice1 == "2"){
        cout << "You selected 2. Removing (selling) a car from the dealership." << endl;
    }

    if (user_choice1 == "0"){
        cout << "You selected 0. Closing the program." << endl;
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