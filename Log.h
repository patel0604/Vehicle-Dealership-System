#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <string>
#include <fstream>
#include "Dealership.h"
#include "Van.h"
using namespace std;

//reads a file and initialises vehicle objects
class Log {
    public:
        //initialises a vehicle from a file into a given pointer
        void write(string file_name, Dealership dealership);

        void read(string file_name);
};

#endif
