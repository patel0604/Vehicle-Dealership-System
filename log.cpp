#include <iostream>
#include <string>
#include <fstream>
#include "Dealership.h"
#include "Van.h"
#include "Log.h"
using namespace std;

void Log::write(string file_name, Dealership dealership) {

            //initialises a vehicle from a file into a given pointer
            ofstream write_dealership(file_name); //open the dealership file
            if (write_dealership.is_open()) { //check if the file was opened
                write_dealership << "19/05/2023" << endl;
                write_dealership << "vehicle number 1 is car" << endl;
                
                write_dealership.close(); //close the file
                cout << "written successfully" << endl;
                
            } else {
                cout << "failed to open the file" << endl;
            }


            void Log::read(string file_name) {
            ifstream read_dealership(file_name);
            if (read_dealership.is_open()) {
                string line;
                while (getline(read_dealership, line)) {
                    cout << line << endl; //print each line to the terminal
                }
                read_dealership.close(); //close the file
            } else {
                cout << "failed to open the file" << endl;
            }
        }
        }