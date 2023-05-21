#include <iostream>
#include <string>
#include <limits>
//#include "Dealership.h"
#include "Vehicle.h"
#include "Van.h"
#include "Car.h"
#include "Truck.h"
using namespace std;

class UI{
    private:
        void mainMenu();
        void checkDealership();
        void checkVehicles();

    public:
        void runProgram();

};

// this is the first function called in the main
void UI::runProgram(){
    mainMenu();
}

void UI::mainMenu(){
    //note that this is a string
    std::string user_choice1;

    cout << "*****************************************************\n";
    cout << "               Dealership Main menu                 \n";
    cout << "*****************************************************\n";

    cout << "            Welcome to the Dealership!        " << endl;
    cout << "1. Adding (buying) a car to the dealership." << endl;
    cout << "2. Removing (selling) a car from the dealership." << endl;
    cout << "3. Check dealership"<<endl;
    cout << "4. Close the program." << endl;
    cout << " "<<endl;
    cout << "Enter the number corresponding to which action you want to do." << endl;
    cin >> user_choice1;
    cout << endl; // leave this here for a gap between menu and next section

    //stage 1.1
    //Checking for the correct input type
    //user must input a number shown

    while(user_choice1 != "1" &&
                user_choice1 != "2" &&
                user_choice1 != "3" &&
                user_choice1 != "4"){
        cout << "Please enter a number shown in the main menu." << endl;
        cin >> user_choice1;
    }

    //stage 1.2

    if (user_choice1 == "1"){
        cout << "You selected: Adding (buying) a car to the dealership." << endl;
    } else if (user_choice1 == "2"){
        cout << "You selected: Removing (selling) a car from the dealership." << endl;
    } else if (user_choice1 == "3"){
        cout <<"Checking the dealership." << endl; 
        checkDealership();
    } else if (user_choice1 == "4"){
        cout << "Closing the program." << endl;
    } 
    
    

}
    
void UI::checkDealership() {

    std::string user_choice2;

    cout << "*****************************************************\n";
    cout << "               Dealership inventory menu             \n";
    cout << "*****************************************************\n";
    cout << "          1. Check Vehicles  \n";
    cout << "          2. Check funds  \n";
    cout << "          3. Deposit Funds  \n";
    cout << "          4. Back to main menu  \n";
    cout << "          Please select one of the options above   ";

    //checking for correct input
    while(user_choice2 != "1" &&
                user_choice2 != "2" &&
                user_choice2 != "3" &&
                user_choice2 != "4"){
        cout << "Please enter a number shown in the Dealership Inventory menu above." << endl;
        cin >> user_choice2;
    }

    if (user_choice2 == "1"){
        cout << "You selected: Check vehicles." << endl;
        checkVehicles();
    } else if (user_choice2 == "2"){
        cout << "You selected: Check funds." << endl;
    } else if (user_choice2 == "3"){
        cout <<"You selected: Deposit funds." << endl; 
    } else if (user_choice2 == "4"){
        cout << "Returning to main menu." << endl;
        mainMenu();
    } 
    
}


void UI::checkVehicles(){

    std::string user_choice3;
    cout << "*****************************************************\n";
    cout << "                Vehicles menu             \n";
    cout << "*****************************************************\n";
    cout << "          1. List all vehicles  \n";
    cout << "          2. Edit vehicle details  \n";
    cout << "          3. Back to main menu  \n";
    cout << "          Please select one of the options above   ";

    //checking for correct input
    while(  user_choice3 != "1" &&
            user_choice3 != "2" &&
            user_choice3 != "3"){
        cout << "Please enter a number shown in the Vehicles menu above." << endl;
        cin >> user_choice3;
    }

    //user's options
    if (user_choice3 == "1"){
        cout << "You selected: List all vehicles." << endl;
    } else if (user_choice3 == "2"){
        cout << "You selected: Edit Vehicle details." << endl;
    } else if (user_choice3 == "3"){
        cout << "Returning to main menu." << endl;
        mainMenu();
    } 
    
}


int main(){
    UI ui;
    ui.runProgram();

    return 0;
}
