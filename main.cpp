#include <iostream>
#include <string>
#include <limits>
#include "Dealership.h"
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

void UI::mainMenu(){
    int user_choice1;

    cout << "*****************************************************\n";
    cout << "               Dealership Main menu                 \n";
    cout << "*****************************************************\n";

    cout << "            Welcome to the Dealership!        " << endl;
    cout << "1. Adding (buying) a car to the dealership." << endl;
    cout << "2. Removing (selling) a car from the dealership." << endl;
    cout << "3. Check dealership"<<endl;
    cout << "0. Close the program." << endl;
    cout << " "<<endl;
    cout << "Enter the number corresponding to which action you want to do." << endl;
    cin >> user_choice1;
    cout << endl; // leave this here for a gap between menu and next section

    //stage 1
    //Entering the correct input type
    //user must input a number shown

    switch (user_choice1){
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
            checkDealership();
            break;
        }
        case 0:
        {
            exit(0);
        }

        default:
        {
            cout<<"Please choose from one of the options"<<endl;
        }

    }

}
    
void UI::checkDealership() {

    int user_choice2;

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

        case 2:
        {
            cout<<"test"<<endl;
            break;

        }
        case 3:
        {
            cout<<"test"<<endl; 
            break;           
        }

        case 4:
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

void UI::runProgram(){
    mainMenu();
}

int main(){
    UI ui;
    ui.runProgram();

    return 0;
}
