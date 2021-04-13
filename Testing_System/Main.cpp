#include <iostream>
#include "TestSystem.h"
#include "MakeChoice.h"

using namespace std;

int main()
{
	/*

	Admin options:
		- Manage categories
			- Add categories
			- Add subjects
			- Add tests
		
		- Manage Guests
			- Add guest
			- Delete guest
			- Modify guest info
			- See all guests in system

		- See statistics
			- By categories
			- By users
			- ...

	*/


	/*

	Guest options:
		- Take a new test

		- See previoues results

	*/

	/*
		Way to access tests: Categories (created when program first launced)->
										-> category (added by admin during the work of program) ->
										-> subject (added by admin during the work of program) ->
										-> test (added by admin during the work of program)

	*/


	/*  

		To restart the program delete: admin.txt, guests.txt, Categories 

	*/




	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);


	TestSystem test_system;
	while (true)
	{
		if (test_system.SignInSystem()) break;
	}

	test_system.Use();


	cout << endl;
	return 0;
}
