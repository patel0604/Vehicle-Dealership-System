program: main.cpp
	g++ main.cpp dealership.cpp vehicle.cpp van.cpp truck.cpp seller.cpp makeVehicle.cpp customer.cpp car.cpp buyer.cpp -o main_test
	./main_test


unit_test_program: UnitTestMain.cpp
	g++ UnitTestMain.cpp -o unit_test_program_run
	./unit_test_program_run