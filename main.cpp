#include <iostream>
#include <string>
#include "UI.h"
using namespace std;



int main(){
    cout << endl;
    cout << "Welcome to the dealership program!!!" << endl;
    cout << "The program allows you to manage your dealership using your personal inputs." << endl;
    cout << "You can buy or sell cars, trucks and vans." << endl;
    cout << "You can set and check crucial information about your dealership." << endl;
    // leave a space between here and the main menu
    cout << endl;

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
    // ws is used to skip any leading whitespace characters. It also ignores the newline characters from previous inputs. 
    getline(cin>>ws, dealership_name);
    cout << "Enter the vehicle capacity of the dealership:" << endl;
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