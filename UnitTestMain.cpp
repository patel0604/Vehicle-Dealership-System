#include "UnitTestVehicle.h"
#include "UnitTestDealership.h"
#include "UnitTestCustomer.h"
#include <iostream>
using namespace std;

// this file is the main file for all unit testing
int main(){
    // vehicle unit testing
    UnitTest unittest1;
    unittest1.RunTests();
    // dealership unit testing
    UnitTestDealership utd1;
    utd1.RunTests();
    // buyer and seller unit testing
    UnitTestCustomer utc1;
    utc1.RunTests();
    return 0;
}