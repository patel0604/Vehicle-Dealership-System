#include <iostream>
#include <string>
#include <limits>
#include "Vehicle.h"
#include "Van.h"
#include "Car.h"
#include "Truck.h"
#include "Dealership.h"
#include "MakeVehicle.h"
using namespace std;

class UI{
    private:
        Dealership* dealership = nullptr;
        void mainMenu();
        void dealershipMenu();
        void buyerMenu();
        void sellerMenu();
        void checkVehicles();

    public:
        UI(Dealership* dealership) {this->dealership = dealership;}
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
    cout << "            1. Dealership menu" << endl;
    cout << "            2. Buyer menu " << endl;
    cout << "            3. Seller menu"<<endl;
    cout << "            4. Close the program." << endl;
    cout << " "<<endl;
    
    while(user_choice1 != "1" &&
                user_choice1 != "2" &&
                user_choice1 != "3" &&
                user_choice1 != "4"){
        cout << "Please enter a number shown in the main menu." << endl;
        cin >> user_choice1;
    }

    while (user_choice1 != "1" && user_choice1 != "2" && user_choice1 != "3" && user_choice1 != "4");
    

    if (user_choice1 == "1"){
        dealershipMenu();
        //cout << "You selected: Adding (buying) a vehicle to the dealership." << endl;
        // need to access the dealership and the vehicles through here
    } else if (user_choice1 == "2"){
        cout << "You selected: Removing (selling) a vehicle from the dealership." << endl;
        // also need to access the dealership and vehciles through here
    } else if (user_choice1 == "3"){
        cout <<"Checking the dealership." << endl; 
        dealershipMenu();
    } else if (user_choice1 == "4"){
        cout << "Closing the program." << endl;
    } 
}

void UI::buyerMenu() {

    std::string user_choice2;

    cout << "*****************************************************\n";
    cout << "               Buyer Menu             \n";
    cout << "*****************************************************\n";
    cout << "          1. New Buyer  \n";
    cout << "          2. All buyers  \n";
    cout << "          3. Go back to main menu  \n";
    cout << "          4. Close Program  \n";
    cout << "          Please select one of the options above: \n";

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
    cout << "          1. Add a seller  \n";
    cout << "          2. All sellers  \n";
    cout << "          3. Go back to main menu  \n";
    cout << "          Please select one of the options above: ";

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
        cout << "Listing all sellers" << endl;
        

        // also need to access the dealership and vehciles through here
    } 
    
    else if (user_choice3 == "3")
    {
        cout << "Going back to main menu" << endl;
        mainMenu();
    }     
    
}
    
void UI::dealershipMenu() {

    std::string user_choice4;

    cout << "*****************************************************\n";
    cout << "               Dealership Menu             \n";
    cout << "*****************************************************\n";
    cout << "          1. Display vehicles list  \n";
    cout << "          2. Add a vehicle  \n";
    cout << "          3. Edit funds  \n";
    cout << "          4. Dealership information  \n";
    cout << "          5. Log dealership status in a file  \n";
    cout << "          6. Back to main menu  \n";
    cout << "          Please select one of the options above: ";

    do {
        cout << "Enter the number corresponding to which action you want to do:" << endl;
        cin >> user_choice4;

        if(user_choice4 != "1" && user_choice4 != "2" && user_choice4 != "3" && user_choice4 != "4" && user_choice4 != "5" && user_choice4 != "6"){
            cout<< "Invalid Option. Please choose again!"<<endl;
        }
    }

    while (user_choice4 != "1" && user_choice4 != "2" && user_choice4 != "3" && user_choice4 != "4" && user_choice4 != "5" && user_choice4 != "6");
    

    if (user_choice4 == "1") {
        dealership->display_cars();
        dealership->display_trucks();
        dealership->display_vans();
        dealershipMenu();
        // need to access the dealership and the vehicles through here
    } else if (user_choice4 == "2") {
        bool loop = true;
        while (loop) {
            string vehicle_type;
            cout << "enter 'car', 'truck' or 'van' for the type of vehicle you want to initialise" << endl;
            cin >> vehicle_type;
            cin.ignore();
            if (vehicle_type == "car" || vehicle_type == "truck" || vehicle_type == "van") {
                MakeVehicle makeVehicle;
                dealership->add_vehicle(makeVehicle.initialise_vehicle(vehicle_type));
                loop = false;
            } else {
                cout << "entered wrong vehicle type entered, please try again" << endl;
            }
        }
        dealershipMenu();
        // also need to access the dealership and vehciles through here
    } else if (user_choice4 == "3") {
        cout << "Enter a number for the amount of funds you want to deposit (+) or withdraw (-)" << endl;
        double funds;
        cin >> funds;
        dealership->change_funds(funds);
        dealershipMenu();
    } else if (user_choice4 == "4") {
        cout << "dealership name: " << dealership->get_dealership_name() << ", vehicle capacity: " << dealership->get_capacity();
        cout << ", funds: $" << dealership->get_funds() << ", parking dimentions: " << dealership->get_parking_length() << " x ";
        cout << dealership->get_parking_width() << "cm" << endl;
        dealershipMenu();
    } else if (user_choice4 == "5") {
        cout << "Logging current dealership status, enter the name of the log file:" << endl;
        string file_name;
        cin.ignore();
        getline(cin, file_name);
        cout << "check" << endl;
        // Check if the file name ends with ".txt"
        if (file_name.length() < 4 || file_name.substr(file_name.length() - 4) != ".txt") {
            file_name += ".txt"; // Append ".txt" extension
        }
        dealership->write(file_name);
        cout << "Displaying log file" << endl;
        dealership->read(file_name);
        dealershipMenu();
    } else if (user_choice4 == "6") {mainMenu();}
    
}

int main(){
    cout << "*****************************************************\n";
    cout << "               Start Menu             \n";
    cout << "*****************************************************\n";
    cout << "          1. Make a dealership  \n";
    cout << "          2. Exit the program  \n";
    cout << "          Please select one of the options above: ";
    int selection;
    cin >> selection;
    //if user inputs anything other than 1 then terminate the program
    if (selection != 1) {
        exit(0);
    }
    //ask the user for dealership values and create a dealership
    cout << "Enter the name of the dealership:" << endl;
    string dealership_name;
    // getline(cin, dealership_name);
    // cin.ignore();
    cin >> dealership_name;
    cout << "Enter the vehicle capcity of the dealership:" << endl;
    int capacity;
    cin >> capacity;
    cout << "Enter the funds of the dealership:" << endl;
    double funds;
    cin >> funds;
    cout << "Enter the length of the dealership parking spots in cm:" << endl;
    int parking_length;
    cin >> parking_length;
    cout << "Enter the width of the dealership parking spots in cm:" << endl;
    int parking_width;
    cin >> parking_width;
    cout << "Creating dealership..." << endl;
    //make a dealership pointer to be passed to functions
    Dealership* dealership = new Dealership(dealership_name, capacity, funds, parking_length, parking_width);
    UI ui(dealership);
    ui.runProgram();


    delete dealership;
    return 0;
}
