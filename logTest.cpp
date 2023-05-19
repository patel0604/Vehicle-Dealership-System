#include <iostream>
#include <string>
#include <fstream>
#include "Log.h"
#include "Van.h"
using namespace std;

int main() {
    
    Log test;
    test.write("dealership_log.txt");
    test.read("dealership_log.txt");
    return 0;
}