#include <iostream>
#include <string>
#include <limits>
#include "Vehicle.h"
#include "Van.h"
#include "Car.h"
#include "Truck.h"
#include "Dealership.h"
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
    std::string user_choice1;

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

        if(user_choice1 != "1" && user_choice1 != "2" && user_choice1 != "3" && user_choice1 != "4"){
            cout<< "Invalid Option. Please choose again!"<<endl;
        }
    }

    while (user_choice1 != "1" && user_choice1 != "2" && user_choice1 != "3" && user_choice1 != "4");
    

    if (user_choice1 == "1")
    {
        cout << "Navigating to dealership menu.....\n" << endl;
        dealershipMenu();
        // need to access the dealership and the vehicles through here
    } 
    else if (user_choice1 == "2")
    {
        cout << "Navigating to buyer menu....." << endl;
        buyerMenu();
        // also need to access the dealership and vehciles through here
    } 
    else if (user_choice1 == "3")
    {
        cout <<"Navigating to seller menu....." << endl; 
        sellerMenu();
    } 
    
    else if (user_choice1 == "4")
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
    cout << "          1. New Buyer  \n";
    cout << "          2. Check old buyer  \n";
    cout << "          3. Go back to main menu  \n";
    cout << "          4. Close Program  \n";
    cout << "          Please select one of the options above   \n";

    do
    {
        cout << "Enter the number corresponding to which action you want to do:" << endl;
        cin >> user_choice2;

        if(user_choice2 != "1" && user_choice2 != "2" && user_choice2 != "3" && user_choice2 != "4"){
            cout<< "Invalid Option. Please choose again!"<<endl;
        }
    }

    while (user_choice2 != "1" && user_choice2 != "2" && user_choice2 != "3" && user_choice2 != "4");
    

    if (user_choice2 == "1")
    {
        cout << "Navigating to dealership menu.....\n" << endl;
        dealershipMenu();
        // need to access the dealership and the vehicles through here
    } 
    else if (user_choice2 == "2")
    {
        cout << "Navigating to buyer menu....." << endl;
        buyerMenu();
        // also need to access the dealership and vehciles through here
    } 
    
    else if (user_choice2 == "3")
    {
        cout << "Returning to the main menu." << endl;
        mainMenu();
    }     

    else if (user_choice2 == "4")
    {
        cout << "Closing the program"<<endl;
        exit(0);
    }
}

void UI::sellerMenu() {

    std::string user_choice3;

    cout << "*****************************************************\n";
    cout << "               Seller Menu             \n";
    cout << "*****************************************************\n";
    cout << "          1. Sell a vehicle  \n";
    cout << "          2. Go back to main menu  \n";
    cout << "          3. Exit the program  \n";
    cout << "          Please select one of the options above   ";

    do
    {
        cout << "Enter the number corresponding to which action you want to do:" << endl;
        cin >> user_choice3;

        if(user_choice3 != "1" && user_choice3 != "2" && user_choice3 != "3" && user_choice3 != "4"){
            cout<< "Invalid Option. Please choose again!"<<endl;
        }
    }

    while (user_choice3 != "1" && user_choice3 != "2" && user_choice3 != "3" && user_choice3 != "4");
    

    if (user_choice3 == "1")
    {
        cout << "......." << endl;
        
        // need to access the dealership and the vehicles through here
    } 
    else if (user_choice3 == "2")
    {
        cout << "Returning to main menu" << endl;
        mainMenu();

        // also need to access the dealership and vehciles through here
    } 
    
    else if (user_choice3 == "3")
    {
        cout << "Closing the program." << endl;
        exit(0);
    }     
    
}
    
void UI::dealershipMenu() {

    std::string user_choice4;

    cout << "*****************************************************\n";
    cout << "               Dealership Menu             \n";
    cout << "*****************************************************\n";
    cout << "          1. Check Vehicles  \n";
    cout << "          2. Check funds  \n";
    cout << "          3. Deposit Funds  \n";
    cout << "          4. Back to main menu  \n";
    cout << "          Please select one of the options above   ";

    do
    {
        cout << "Enter the number corresponding to which action you want to do:" << endl;
        cin >> user_choice4;

        if(user_choice4 != "1" && user_choice4 != "2" && user_choice4 != "3" && user_choice4 != "4"){
            cout<< "Invalid Option. Please choose again!"<<endl;
        }
    }

    while (user_choice4 != "1" && user_choice4 != "2" && user_choice4 != "3" && user_choice4 != "4");
    

    if (user_choice4 == "1")
    {
        cout << "......." << endl;
        
        // need to access the dealership and the vehicles through here
    } 
    else if (user_choice4 == "2")
    {
        cout << "......." << endl;
        // also need to access the dealership and vehciles through here
    } 
    
    else if (user_choice4 == "3")
    {
        cout << "Closing the program." << endl;
        exit(0);
    }

    else if (user_choice4 == "4")
    {
        cout << "Returning to main menu" << endl;
        mainMenu();
    }
    
}

int main(){
    Dealership dealership1;

    

    UI ui;
    ui.runProgram();

    return 0;
}
