#include "Subject.h"

#pragma region Constructer


Subject::Subject()
{
	totalNumberOfTests = 0;
}


#pragma endregion


#pragma region Getters and Setters


int Subject::GetTotalNumberOfTests() const
{
	return totalNumberOfTests;
}


#pragma endregion


#pragma region Add Test


// Adds 1 test to allTests map
// Test is initialized inside method
// Adds 1 to totalNumberOfTests
// Adds test to file
void Subject::AddTest(string _path_to_directory)
{
	Test t;

	t.FillTest();

    t.SaveTestToFile(_path_to_directory);
}



#pragma endregion

