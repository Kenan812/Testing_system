#pragma once
#include "Test.h"

/*		Represents directory       */

class Subject : public Test
{
private:
	int totalNumberOfTests;  // Set in Category class

public:

	Subject();


	//=========================================================//


	int GetTotalNumberOfTests() const;


	//=========================================================//



	// Test is initialized inside method
	// Adds 1 to totalNumberOfTests
	// Automatically saves test 
	// Adds test to file
	void AddTest(string _path_to_directory); /* Need to test */


	// Deletes 1 Test
	// Name of the file asked from user in method
	// Subtracts 1 from totalNumberOfTests
	void DeleteTest(string _path_to_directory);  /* Need to test before using*/



	//=========================================================//
		
	





	void ShowAllTests(string _path);





	
	/* Possible addition */
	

	// Deletes all test in this subject
	// Sets totalNumberNumberOfTests to 0
	void DeleteAllTests(string _path_to_directory);




};
