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
        void dealershipMenu();
        void buyerMenu();
        void sellerMenu();
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
    int user_choice1;

    cout << "*****************************************************\n";
    cout << "               Dealership Main menu                 \n";
    cout << "*****************************************************\n";
    cout << " "<<endl;
    cout << "            Welcome to the Dealership!        " << endl;
    cout << " "<<endl;
    cout << "            1. Check Dealership menu" << endl;
    cout << "            2. Check Buyer menu " << endl;
    cout << "            3. Check Seller menu"<<endl;
    cout << "            4. Close the program." << endl;
    cout << " "<<endl;
    
    do
    {
        cout << "Enter the number corresponding to which action you want to do:" << endl;
        cin >> user_choice1;

        if(user_choice1 != 1 && user_choice1 != 2 && user_choice1 != 3 && user_choice1 != 4){
            cout<< "Invalid Option. Please choose again!"<<endl;
        }
    }

    while (user_choice1 <= 0 || user_choice1 >= 5);
    

    if (user_choice1 == 1)
    {
        cout << "Navigating to dealership menu.....\n" << endl;
        dealershipMenu();
        // need to access the dealership and the vehicles through here
    } 
    else if (user_choice1 == 2)
    {
        cout << "Navigating to buyer menu....." << endl;
        buyerMenu();
        // also need to access the dealership and vehciles through here
    } 
    else if (user_choice1 == 3)
    {
        cout <<"Navigating to seller menu....." << endl; 
        sellerMenu();
    } 
    
    else if (user_choice1 == 4)
    {
        cout << "Closing the program." << endl;
        exit(0);
    }     
}

void UI::buyerMenu() {

    std::string user_choice2;

    cout << "*****************************************************\n";
    cout << "               Buyer Menu             \n";
    cout << "*****************************************************\n";
    cout << "          1. Buy vehicle  \n";
    cout << "          2. Go back to main menu  \n";
    cout << "          Please select one of the options above   ";

    cin>>user_choice2;

    if (user_choice2 == "1"){
        cout << "You selected: Buy vehicle" << endl;

    } else if (user_choice2 == "2"){
        cout << "Returning to main menu." << endl;
        mainMenu();
    } 
    
}

void UI::sellerMenu() {

    std::string user_choice2;

    cout << "*****************************************************\n";
    cout << "               Seller Menu             \n";
    cout << "*****************************************************\n";
    cout << "          1. Sell a vehicle  \n";
    cout << "          2. Go back to main menu  \n";
    cout << "          Please select one of the options above   ";

    cin>>user_choice2;

    if (user_choice2 == "1"){
        cout << "You selected: Sell vehicle " << endl;

    } else if (user_choice2 == "2"){
        cout << "Returning to main menu." << endl;
        mainMenu();
    } 
    
}
    
void UI::dealershipMenu() {

    std::string user_choice2;

    cout << "*****************************************************\n";
    cout << "               Dealership Menu             \n";
    cout << "*****************************************************\n";
    cout << "          1. Check Vehicles  \n";
    cout << "          2. Check funds  \n";
    cout << "          3. Deposit Funds  \n";
    cout << "          4. Back to main menu  \n";
    cout << "          Please select one of the options above   ";

    cin>>user_choice2;

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
