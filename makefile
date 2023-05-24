main: main.cpp
	g++ -Werror -std=c++11 main.cpp Dealership.cpp -o main_test
	./main_test


unit_test_program: UnitTestMain.cpp
	g++ UnitTestMain.cpp -o unit_test_program_run
	./unit_test_program_run