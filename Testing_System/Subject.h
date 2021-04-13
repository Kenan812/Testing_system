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



	//=========================================================//
		

};
