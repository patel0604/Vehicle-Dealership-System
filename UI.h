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

// this class represents the UI for the program and loops functions together until the program ends
class UI{
    private:
        // initialise an empty dealership pointer
        Dealership* dealership = nullptr;
        // initialise a vector of buyer pointers
        vector<Buyer*> buyers;
        // initialise a vector of seller pointers
        vector<Seller*> sellers;
        // other private menu functions
        void mainMenu();
        void dealershipMenu();
        void buyerMenu();
        void sellerMenu();
        void checkVehicles();
        void buyerFunctions(size_t buyer_index);
        void sellerFunctions(size_t seller_index);

    public:
        // constructor
        UI(Dealership* dealership);

        // public function for starting the program
        void runProgram();

        // UI destructor
        ~UI();

};

#endif