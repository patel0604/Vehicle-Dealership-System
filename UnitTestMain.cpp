#include "UnitTestVehicle.h"
#include "UnitTestDealership.h"
#include "UnitTestCustomer.h"
#include <iostream>
using namespace std;

int main(){
    //UnitTest unittest1;
    //unittest1.RunTests();
    UnitTestDealership utd1;
    utd1.RunTests();
    //UnitTestCustomer utc1;
    //utc1.RunTests();
    return 0;
}