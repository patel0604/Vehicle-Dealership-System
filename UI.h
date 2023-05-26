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
        void main_menu();
        void dealership_menu();
        void buyer_menu();
        void seller_menu();
        void buyer_functions(size_t buyer_index);
        void seller_functions(size_t seller_index);

    public:
        UI(Dealership* dealership) {this->dealership = dealership;}
        void runProgram();
        // UI destructor, frees buyer and seller vectors
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

#endif