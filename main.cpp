#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Van.h"
using namespace std;

int main() {
    Van van1(250,150,1500,15000,"toyota","tvan","SW390",1000,500,7);
    Vehicle* vehicle1 = &van1;
    cout << vehicle1->get_model() << endl;
    return 0;
}