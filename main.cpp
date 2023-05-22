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
    cout << "1. Adding (buying) a vehicle to the dealership." << endl;
    cout << "2. Removing (selling) a vehicle from the dealership." << endl;
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

        case 2:
        {
            cout<<"test"<<endl;
            break;
        }

    if (user_choice1 == "1"){
        cout << "You selected: Adding (buying) a vehicle to the dealership." << endl;
        // need to access the dealership and the vehicles through here
    } else if (user_choice1 == "2"){
        cout << "You selected: Removing (selling) a vehicle from the dealership." << endl;
        // also need to access the dealership and vehciles through here
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

    cin>>user_choice2;
    switch (user_choice2){
        case 1:
        {
            cout<<"test"<<endl;
            break;
        }

    if (user_choice2 == "1"){
        cout << "You selected: View/Edit vehicles." << endl;
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

    int user_choice3;
    cout << "*****************************************************\n";
    cout << "                Vehicle's menu             \n";
    cout << "*****************************************************\n";
    cout << "          1. List all vehicles  \n";
    cout << "          2. Edit vehicle details  \n";
    cout << "          3. Back to main menu  \n";
    cout << "          Please select one of the options above   ";

    cin>>user_choice3;
    switch (user_choice3){
        case 1:
        {
            cout<<"test"<<endl;
            break;
        }

        case 2:
        {
            cout<<"test"<<endl;
            break;
        }
        case 3:
        {
            mainMenu();
            break;
        }

        default:
        {
            cout<<"Please choose from one of the options"<<endl;
        }

    }
}


int main(){
    UI ui;
    ui.runProgram();

    return 0;
}
