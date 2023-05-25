#ifndef UI_H
#define UI_H
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstddef>
#include "Van.h"
#include "Dealership.h"
#include "Buyer.h"
#include "Seller.h"
#include "MakeVehicle.h"
using namespace std;


class UI{
    private:
        Dealership* dealership = nullptr;
        vector<Buyer*> buyers;
        vector<Seller*> sellers;
        void mainMenu();
        void dealershipMenu();
        void buyerMenu();
        void sellerMenu();
        void checkVehicles();
        void buyerFunctions(size_t buyer_index);
        void sellerFunctions(size_t seller_index);

    public:
        UI(Dealership* dealership) {this->dealership = dealership;}
        void runProgram();
        // vector<Buyer*> get_buyers() {return buyers;}
        // vector<Seller*> get_sellers() {return sellers;}
        ~UI() {
            // Delete individual pointers for buyers
            for (Buyer* ptr : buyers) {
                delete ptr;
            }

            // Clear the buyers vector
            buyers.clear();
            cout << "cleared sellers vector - debug message" << endl;
            //Delete individual pointers for sellers
            for (Seller* ptr : sellers) {
                delete ptr;
            }

            // Clear the buyers vector
            sellers.clear();
            cout << "cleared buyers vector - debug message" << endl;
        }

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
    cout << "            3. Seller menu" << endl;
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
    } else if (user_choice1 == "2"){
        buyerMenu();
    } else if (user_choice1 == "3"){
        sellerMenu();
    } else if (user_choice1 == "4"){
        cout << "Closing the program." << endl;
    } 
}

void UI::buyerMenu() {

    std::string user_choice2;

    cout << "*****************************************************\n";
    cout << "               Buyers Menu             \n";
    cout << "*****************************************************\n";
    cout << "          1. New Buyer  \n";
    cout << "          2. Select buyer  \n";
    cout << "          3. Go back to main menu  \n";
    cout << "          Please select one of the options above: \n";

    do
    {
        cout << "Enter the number corresponding to which action you want to do:" << endl;
        cin >> user_choice2;

        if(user_choice2 != "1" && user_choice2 != "2" && user_choice2 != "3"){
            cout<< "Invalid Option. Please choose again!"<<endl;
        }
    }

    while (user_choice2 != "1" && user_choice2 != "2" && user_choice2 != "3");
    

    if (user_choice2 == "1") {
        //ask user for values to initialise buyer
        cout << "Enter the name of the buyer" << endl;
        string name;
        cin.ignore();
        getline(cin, name);
        cout << "Enter the buyer's licence number" << endl;
        string licence_number;
        getline(cin, licence_number);
        cout << "Enter the buyer's funds" << endl;
        double wallet;
        cin >> wallet;
        cout << "Enter the amount of vehicles the buyer wants to buy" << endl;
        int vehicle_amount;
        cin >> vehicle_amount;
        Buyer* buyer = new Buyer(name, licence_number, wallet, vehicle_amount);
        //add the pointer to the end of the buyers vector
        buyers.push_back(buyer);
        buyerMenu();
    } else if (user_choice2 == "2") {
        //display all buyers
        for (size_t i = 0; i < buyers.size(); i++) {
            //print buyer info
            cout << "Buyer " << i+1 << ":" << endl;
            cout << buyers[i]->get_name() << ", " << buyers[i]->get_licence_number();
            cout << ", funds: " << buyers[i]->get_wallet() << ", number of vehicles: ";
            cout << buyers[i]->get_num_vehicles() << endl;
            //print buyer vehicles
            buyers[i]->display_vehicles();
        }
        //ask the user to select a buyer
        int num = 0;
        while (num < 1 || num > static_cast<int>(buyers.size())) {
            cout << "Enter the correct buyer number you want to select from the above list: " << endl;
            cin >> num;
        }
        //subtract 1 to get index
        num--;
        //convert to vector index
        size_t index = num;
        //pass the index to the buyer functions menu
        buyerFunctions(index);
    } else if (user_choice2 == "3") {
        cout << "Returning to the main menu." << endl;
        mainMenu();
    }
}

void UI::buyerFunctions(size_t buyer_index) {

    std::string user_choice5;

    cout << "*****************************************************\n";
    cout << "               Buyer Functions             \n";
    cout << "*****************************************************\n";
    cout << "          1. Display current buyer  \n";
    cout << "          2. Sell vehicle to buyer  \n";
    cout << "          3. Delete buyer  \n";
    cout << "          4. Go back to buyers menu  \n";
    cout << "          Please select one of the options above: \n";

    do
    {
        cout << "Enter the number corresponding to which action you want to do:" << endl;
        cin >> user_choice5;

        if(user_choice5 != "1" && user_choice5 != "2" && user_choice5 != "3" && user_choice5 != "4"){
            cout<< "Invalid Option. Please choose again!"<<endl;
        }
    }

    while (user_choice5 != "1" && user_choice5 != "2" && user_choice5 != "3" && user_choice5 != "4");
    

    if (user_choice5 == "1") {
        //display current buyer
        //print buyer info
        cout << "Buyer " << buyer_index+1 << ":" << endl;
        cout << buyers[buyer_index]->get_name() << ", " << buyers[buyer_index]->get_licence_number();
        cout << ", funds: " << buyers[buyer_index]->get_wallet() << ", number of vehicles: ";
        cout << buyers[buyer_index]->get_num_vehicles() << endl;
        //print buyer vehicles
        buyers[buyer_index]->display_vehicles();
        buyerFunctions(buyer_index);
    } else if (user_choice5 == "2") {
        //display all vehicles in the dealership
        dealership->display_cars();
        dealership->display_trucks();
        dealership->display_vans();
        //ask the user to enter the number plate of the vehicle they want to sell
        string number_plate;
        int check = -1;
        while (check == -1) {
            cout << "Enter the number plate of the vehicle in the dealership you want to sell, enter 'stop' to cancel:" << endl;
            cin.ignore();
            getline(cin, number_plate);
            if (number_plate == "stop") {
                break;
            }
            check = dealership->search_vehicle_number_plate(number_plate);
        }
        //sell the vehicle to the buyer
        buyers[buyer_index]->vehicle_transaction(number_plate, dealership);
        buyerFunctions(buyer_index);
    } else if (user_choice5 == "3") {
        cout << "are you sure you want to delete the current buyer? Enter 'yes' or 'no'" << endl;
        string confirmation;
        cin >> confirmation;
        if (confirmation != "yes") {
            buyerFunctions(buyer_index);
        }
        //delete the element of vector at current index
        delete buyers[buyer_index];
        buyers.erase(buyers.begin() + buyer_index);
        cout << "Buyer successfully deleted" << endl;
        buyerMenu();
    } else if (user_choice5 == "4") {
        cout << "Returning to the buyers menu." << endl;
        buyerMenu();
    }
}

void UI::sellerMenu() {

    std::string user_choice3;

    cout << "*****************************************************\n";
    cout << "               Sellers Menu             \n";
    cout << "*****************************************************\n";
    cout << "          1. New seller  \n";
    cout << "          2. Select seller  \n";
    cout << "          3. Go back to main menu  \n";
    cout << "          Please select one of the options above: ";

    do
    {
        cout << "Enter the number corresponding to which action you want to do:" << endl;
        cin >> user_choice3;

        if(user_choice3 != "1" && user_choice3 != "2" && user_choice3 != "3"){
            cout<< "Invalid Option. Please choose again!"<<endl;
        }
    }

    while (user_choice3 != "1" && user_choice3 != "2" && user_choice3 != "3");
    

    if (user_choice3 == "1") {
        //ask user for values to initialise seller
        cout << "Enter the name of the seller" << endl;
        string name;
        cin.ignore();
        getline(cin, name);
        cout << "Enter the seller's licence number" << endl;
        string licence_number;
        getline(cin, licence_number);
        cout << "Enter the seller's funds" << endl;
        double wallet;
        cin >> wallet;
        cout << "Enter the amount of vehicles the seller wants to sell" << endl;
        int vehicle_amount;
        cin >> vehicle_amount;
        Seller* seller = new Seller(name, licence_number, wallet, vehicle_amount);
        //initialise all vehicles in seller
        cout << "Initialise all seller vehicles:" << endl;
        seller->initialise_vehicles();
        //add the pointer to the end of the sellers vector
        sellers.push_back(seller);
        sellerMenu();
    } else if (user_choice3 == "2") {
        //display all buyers
        for (size_t i = 0; i < sellers.size(); i++) {
            //print buyer info
            cout << "Seller " << i+1 << ":" << endl;
            cout << sellers[i]->get_name() << ", " << sellers[i]->get_licence_number();
            cout << ", funds: " << sellers[i]->get_wallet() << ", number of vehicles: ";
            cout << sellers[i]->get_num_vehicles() << endl;
            //print buyer vehicles
            sellers[i]->display_vehicles();
        }
        //ask the user to select a buyer
        int num = 0;
        while (num < 1 || num > static_cast<int>(sellers.size())) {
            cout << "Enter the correct sellers number you want to select from the above list: " << endl;
            cin >> num;
        }
        //subtract 1 to get index
        num--;
        //convert to vector index
        size_t index = num;
        //pass the index to the seller functions menu
        sellerFunctions(index);
    } else if (user_choice3 == "3") {
        cout << "Returning to main menu" << endl;
        mainMenu();
    }     
    
}

void UI::sellerFunctions(size_t seller_index) {

    std::string user_choice6;

    cout << "*****************************************************\n";
    cout << "               Seller Functions             \n";
    cout << "*****************************************************\n";
    cout << "          1. Display current seller  \n";
    cout << "          2. Buy vehicle from seller  \n";
    cout << "          3. Delete seller  \n";
    cout << "          4. Go back to seller menu  \n";
    cout << "          Please select one of the options above: \n";

    do
    {
        cout << "Enter the number corresponding to which action you want to do:" << endl;
        cin >> user_choice6;

        if(user_choice6 != "1" && user_choice6 != "2" && user_choice6 != "3" && user_choice6 != "4"){
            cout<< "Invalid Option. Please choose again!"<<endl;
        }
    }

    while (user_choice6 != "1" && user_choice6 != "2" && user_choice6 != "3" && user_choice6 != "4");
    

    if (user_choice6 == "1") {
        //display current seller
        //print seller info
        cout << "Seller " << seller_index+1 << ":" << endl;
        cout << sellers[seller_index]->get_name() << ", " << sellers[seller_index]->get_licence_number();
        cout << ", funds: " << sellers[seller_index]->get_wallet() << ", number of vehicles: ";
        cout << sellers[seller_index]->get_num_vehicles() << endl;
        //print seller vehicles
        sellers[seller_index]->display_vehicles();
        sellerFunctions(seller_index);
    } else if (user_choice6 == "2") {
        //display all vehicles in the seller
        sellers[seller_index]->display_vehicles();
        //ask the user to enter the number plate of the vehicle they want to sell
        string number_plate;
        int check = -1;
        while (check == -1) {
            cout << "Enter the number plate of the vehicle in the dealership you want to sell, enter 'stop' to cancel:" << endl;
            cin.ignore();
            getline(cin, number_plate);
            if (number_plate == "stop") {
                break;
            }
            check = sellers[seller_index]->get_vehicle_index(number_plate);
        }
        //buy the vehicle from the seller
        sellers[seller_index]->vehicle_transaction(number_plate, dealership);
        sellerFunctions(seller_index);
    } else if (user_choice6 == "3") {
        cout << "are you sure you want to delete the current seller? Enter 'yes' or 'no'" << endl;
        string confirmation;
        cin >> confirmation;
        if (confirmation != "yes") {
            sellerFunctions(seller_index);
        }
        //delete the element of vector at current index
        delete sellers[seller_index];
        sellers.erase(sellers.begin() + seller_index);
        cout << "Seller successfully deleted" << endl;
        sellerMenu();
    } else if (user_choice6 == "4") {
        cout << "Returning to the sellers menu." << endl;
        sellerMenu();
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
    cout << "          Please select one of the options above: \n";

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

#endif