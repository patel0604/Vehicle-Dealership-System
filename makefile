main: main.cpp
	g++ main.cpp -o main_test
	./main_test


unit_test_program: UnitTestMain.cpp
	g++ UnitTestMain.cpp -o unit_test_program_run
	./unit_test_program_run