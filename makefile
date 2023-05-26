program: main.cpp
	g++ -Werror -std=c++11 main.cpp dealership.cpp vehicle.cpp van.cpp truck.cpp seller.cpp makeVehicle.cpp customer.cpp car.cpp buyer.cpp UI.cpp -o program
	./program

unit_test_program: UnitTestMain.cpp
	g++ -Werror -std=c++11 UnitTestMain.cpp dealership.cpp vehicle.cpp van.cpp truck.cpp seller.cpp makeVehicle.cpp customer.cpp car.cpp buyer.cpp -o unit_test_program_run
	./unit_test_program_run